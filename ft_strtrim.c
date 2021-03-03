/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:55:56 by klasak        #+#    #+#                 */
/*   Updated: 2020/11/25 17:44:18 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char_in_set(char s, char const *set)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t start;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_end(char const *s1, char const *set, size_t start)
{
	size_t end;

	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*pp;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set, start);
	pp = (char*)malloc(sizeof(char) * (end - start + 1));
	if (!pp)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		pp[i] = s1[start + i];
		i++;
	}
	pp[i] = '\0';
	return (pp);
}
