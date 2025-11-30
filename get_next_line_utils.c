/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeizi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:37:57 by afeizi            #+#    #+#             */
/*   Updated: 2025/11/27 13:39:34 by afeizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c )
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*remp(char *s1, char *s2, int *i, int *j)
{
	char	*res;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[*i])
		{
			res[*i] = s1[*i];
			*i = *i + 1;
		}
	}
	if (s2)
	{
		while (s2[*j])
		{
			res[*i + *j] = s2[*j];
			*j = *j + 1;
		}
	}
	res[*i + *j] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = remp(s1, s2, &i, &j);
	return (result);
}
