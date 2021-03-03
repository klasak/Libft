/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:28:49 by klasak        #+#    #+#                 */
/*   Updated: 2020/12/09 10:14:35 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	const char	*line;

	if (!s)
		return ;
	line = (char*)'\n';
	write(fd, s, ft_strlen(s));
	write(fd, &line, 1);
}
