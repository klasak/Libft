/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/12 15:27:16 by klasak        #+#    #+#                 */
/*   Updated: 2020/11/08 17:51:45 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_d;
	size_t	c;
	size_t	l_s;
	size_t	i;

	l_d = ft_strlen(dst);
	c = l_d;
	l_s = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && size - 1 > l_d + i)
		{
			dst[c] = src[i];
			i++;
			c++;
		}
		dst[c] = '\0';
	}
	if (l_d >= size)
		l_d = size;
	return (l_d + l_s);
}
