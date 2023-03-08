/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:16:34 by agallet           #+#    #+#             */
/*   Updated: 2023/02/27 15:34:42 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlench(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str && *str && *str != c)
	{
		i++;
		str++;
	}
	if (*str == '\n')
		i++;
	return (i);
}

char	*ft_clear(char **str)
{
	int	i;

	i = 0;
	if (str && *str)
	{
		while (*str && (*str)[i])
			(*str)[i++] = '\0';
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

int	right_side(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && *str && *str != '\n')
		str++;
	if (*str && *str == '\n')
		str++;
	while (str && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup1(char *s1)
{
	char	*_str;
	int		i;

	i = 0;
	_str = NULL;
	while (s1 && *s1 != '\n')
		s1++;
	if (s1 && *s1 == '\n')
		s1++;
	_str = malloc(sizeof(char) * (ft_strlench(s1, '\0') + 1));
	if (!_str)
		return (NULL);
	while (s1 && s1[i])
	{
		_str[i] = s1[i];
		i++;
	}
	_str[i] = '\0';
	return (_str);
}
