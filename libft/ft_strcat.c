/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:02:41 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/08 20:57:51 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		dst_i;
	int		src_i;

	src_i = 0;
	dst_i = 0;
	if (src[0] == '\0')
		return (dest);
	while (dest[dst_i] != '\0')
		dst_i++;
	while (src[src_i] != '\0')
	{
		dest[dst_i] = src[src_i];
		src_i++;
		dst_i++;
	}
	dest[dst_i] = '\0';
	return (dest);
}
