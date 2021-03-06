/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:44:45 by lchaineu          #+#    #+#             */
/*   Updated: 2020/10/09 14:44:47 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_start(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] && is_in_set(s1[i], set) == 1)
		i++;
	return (i);
}

static int	get_end(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1);
	i--;
	while (i && is_in_set(s1[i], set) == 1)
		i--;
	return ((int)i);
}

static char	*trimcpy(char const *s1, char *trim, int start, int end)
{
	int i;

	i = 0;
	while (start <= end)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end == 0)
	{
		if (!(trim = malloc(sizeof(char))))
			return (NULL);
		trimcpy(s1, trim, start, end);
		return (trim);
	}
	if (!(trim = (char *)malloc(sizeof(char) * ((end - start) + 2))))
		return (NULL);
	trimcpy(s1, trim, start, end);
	return (trim);
}
