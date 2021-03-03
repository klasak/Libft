/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/12 15:27:16 by klasak        #+#    #+#                 */
/*   Updated: 2020/11/29 20:17:41 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*destt;
	char	*srcc;

	i = 0;
	destt = (char*)(dest);
	srcc = (char*)(src);
	while (i < n)
	{
		destt[i] = srcc[i];
		if (destt[i] == (char)c)
			return (destt + i + 1);
		i++;
	}
	return (NULL);
}
