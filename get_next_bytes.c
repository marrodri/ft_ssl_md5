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

uint8_t		*ft_append_byte(uint8_t *chunk)
{
	return 0;
}

void	add_new_chunk(t_list **list, uint8_t *chunk, int bytes)
{
	t_list *new_chunk;
	new_chunk = (t_list *)malloc(sizeof(t_list));
	new_chunk->content = chunk;
	new_chunk->content_size = bytes;
	printf("chunk is |%s|\n", new_chunk->content);
	printf("bytes are|%d|\n", new_chunk->content_size);
	printf("setting new chunk\n");
	if(*list == NULL)
	{
		printf("list is null, adding first node\n");
		*list = new_chunk;
	}
	else
	{
		printf("!!!!!!!!!!!!!!!!!adding next node\n");
		ft_lstaddend(list, new_chunk);
	}
	printf("EXITING NEW_CHUNKS SET\n");
}

int		ft_set_bytes(const int fd, int bytes, t_list **list)
{
	uint32_t ret; //32bit as 4byte
	uint8_t buff[bytes]; //8bit as 1 byte
	uint32_t byte_len; //int
	uint64_t bit_len; //unsigned long long
	int chunk;

	bit_len = 0;
	chunk = 0;
	byte_len = 0;
	while((ret = read(fd, buff, bytes)) > 0)
	{
		byte_len = byte_len + ret;
		if(ret == bytes)
		{
			chunk++;
		}
		if(ret < bytes && ret != 0)
		{
			chunk++;
			bit_len = byte_len * 8;
			printf("ret is less than %d bytes appending!!!\n", bytes);
			printf("byte len is|%d|, bit len is|%llu|\n", byte_len, bit_len);
			// ret--;
			ret+=5;
			while(ret < bytes)
			{
				buff[ret] = '\0';
				ret++;
			}
			printf("!!!!!last buff for chunk is |%s|\n", buff);
			//append then check if it the last 8 bytes are 0s or not
			//if not set another 64 byte chunk with the bit length of the message
			//in the last 8 bytes
		}
		add_new_chunk(list, buff, bytes);
	}
	return (chunk);
}
