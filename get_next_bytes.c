/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:30 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/22 16:21:33 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"
#include <stdio.h>

void	print_list(t_list **list)
{
	t_list *tmp;
	static int i = 0;
	tmp = *list;
	printf("######session %d########\n",i);
	while(tmp)
	{
		printf("chunk is |%s|\n", tmp->content);
		tmp = tmp->next;
	}
	i++;
	printf("^^^^^EXIT CHECK^^^^^^^\n");
}

int check_last8bytes(uint8_t *chunk, int bytes)
{
	int i;
	int dif;

	dif = bytes - 8; // 64-8 = 56
	i = bytes - 1; //63
	while (i >= dif)
	{
		if (chunk[i] != 0x00)
			return 0;
		i--;
	}
	return 1;
}


uint8_t		*ft_append_bytes(uint8_t *chunk, int ret, int bytes, uint8_t bit_len)
{
	int i;
	int dif;
	i = ret + 1;
	dif = bytes - 8;
	chunk[ret] = (chunk[ret] << 8) | 0x80;
		while (i < bytes)
		{
			chunk[i] = (chunk[i] << 8) | 0x00;
			i++;
		}
	if (check_last8bytes(chunk, bytes))
	{
		i--;
		while (i >= dif)
		{
			chunk[i] = (chunk[i] << 8) | bit_len;
			i--;
		}
	}
	else
	{
		printf("    (((((((the last 8 bytes are not 0, SETTING A NEW NODE))))))))\n");
	}
	return (chunk);
}

t_list	*set_new_node(uint8_t *chunk, int bytes)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return NULL;
	if (chunk)
	{
		new->content = chunk;
		new->content_size = bytes;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return new;
}

void	add_new_chunk(t_list **list, uint8_t *chunk, int bytes)
{
	t_list *new_chunk;

	new_chunk = set_new_node(chunk, bytes);
	if (*list == NULL)
		*list = new_chunk;
	else
		ft_lstaddend(list, new_chunk);
	print_list(list);
}

int		ft_set_bytes(const int fd, uint32_t bytes, t_list **list)
{
	uint32_t ret; //32bit as 4byte
	uint8_t buff[bytes]; //8bit as 1 byte
	uint32_t byte_len; //int
	uint64_t bit_len; //unsigned long long
	int chunk;
	uint8_t *tmp;

	bit_len = 0;
	chunk = 0;
	byte_len = 0;
	while((ret = read(fd, buff, bytes)) > 0)
	{
		printf("ret is %d\n", ret);
		printf("buff is |%s|\n", buff);
		tmp = ft_memalloc(bytes);
		tmp = ft_memcpy(tmp, buff, bytes);
		byte_len = byte_len + ret;
		if (ret == bytes)
		{
			chunk++;
		}
		if (ret < bytes)
		{
			chunk++;
			bit_len = byte_len * 8;
			printf("ret is less than %d bytes appending!!!\n", bytes);
			// tmp = ft_append_bytes(tmp, ret, bytes, bit_len);

			//append then check if it the last 8 bytes are 0s or not
			if(!check_last8bytes(tmp, bytes))
			{
				printf("    (((((((the last 8 bytes are not 0, SETTING A NEW NODE))))))))\n");
				// add_new_chunk(list, tmp, bytes);
			}
			else
			{
				tmp = ft_append_bytes(tmp, ret, bytes, bit_len);
			}
			//if not set another 64 byte chunk with the bit length of the message
		}
		add_new_chunk(list, tmp, bytes);
	}
	return (chunk);
}
