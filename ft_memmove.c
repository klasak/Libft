/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/12 15:27:16 by klasak        #+#    #+#                 */
/*   Updated: 2020/11/30 14:06:48 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destt;
	const char	*srcc;

	destt = dest;
	srcc = src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = n - 1;
		while (n > 0)
		{
			destt[i] = srcc[i];
			i--;
			n--;
		}
	}
	else
		dest = ft_memcpy(destt, srcc, n);
	return (dest);
}
