/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 11:34:31 by klasak        #+#    #+#                 */
/*   Updated: 2020/11/27 11:20:14 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative_putnbr(int nb, int fd)
{
	int nnb;

	ft_putchar_fd('-', fd);
	nnb = (-1) * nb;
	nb = nnb;
	return (nb);
}

static int	ft_count(int nb)
{
	int number;
	int i;

	i = 0;
	number = nb;
	while (number / 10 > 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

static void	ft_print(int nb, int i, int fd)
{
	int j;
	int div;

	while (i >= 0)
	{
		j = 1;
		div = 1;
		while (j <= i)
		{
			div = div * 10;
			j++;
		}
		ft_putchar_fd((nb / div) % 10 + '0', fd);
		div = div / 10;
		i--;
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	int i;

	if (nb >= 0)
	{
		i = ft_count(nb);
		ft_print(nb, i, fd);
	}
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(fd, "-2147483648", 11);
		}
		else
		{
			nb = ft_negative_putnbr(nb, fd);
			i = ft_count(nb);
			ft_print(nb, i, fd);
		}
	}
}
