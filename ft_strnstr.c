/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/12 15:27:16 by klasak        #+#    #+#                 */
/*   Updated: 2020/12/05 09:31:21 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t c;
	size_t i;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < n)
	{
		c = 0;
		while (str[i + c] == to_find[c] && to_find[c] != '\0' && i + c < n)
			c++;
		if (to_find[c] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
