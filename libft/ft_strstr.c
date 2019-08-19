/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:26:08 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/08 21:00:31 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int index;
	int temp;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		index = 0;
		if (str[i] == to_find[index])
		{
			temp = i;
			while (str[i] == to_find[index])
			{
				if (to_find[index + 1] == '\0')
					return (&str[temp]);
				index++;
				i++;
			}
			i = temp;
		}
		i++;
	}
	return (0);
}
