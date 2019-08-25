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

uint8_t		*ft_append_byte(uint8_t *chunk, int ret, int bytes, uint64_t bit_len)
{
	int i;

	i = ret;

	while(i < bytes)
	{
		chunk[i] = 0;
		i++;
	}
	bit_len = 0;
	return 0;
}

void	print_list(t_list **list)
{
	t_list *tmp;
	static int i =0;
	tmp = *list;
	printf("######session %d########\n",i);
	while(tmp)
	{
		printf("chunk is |%s|\n", tmp->content);
		// printf("memory address NEXT |%p|\n", &tmp->next);
		tmp = tmp->next;
	}
	i++;
	printf("^^^^^EXIT CHECK^^^^^^^\n");
}

t_list	*set_new_node(uint8_t *chunk, int bytes)
{
	t_list *new;

	if((new = (t_list *)malloc(sizeof(t_list))) == NULL)
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
	// printf("$$$$set new memory address |%p|\n", &new_chunk);
	// printf("$$$$check next memory address |%p|\n", &new_chunk->next);
	if(*list == NULL)
		*list = new_chunk;
	else
		ft_lstaddend(list, new_chunk);
	// free(new_chunk);
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
			if(ft_append_byte(tmp, bytes, bit_len))
			{
				//set chunk to current tmp and c
			}
			// printf("!!!!!last buff for chunk is |%s|\n", buff);
			//append then check if it the last 8 bytes are 0s or not
			//if not set another 64 byte chunk with the bit length of the message
			//in the last 8 bytes
		}
		add_new_chunk(list, tmp, bytes);
	}
	return (chunk);
}
