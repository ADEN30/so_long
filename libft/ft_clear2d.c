/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:15:33 by agallet           #+#    #+#             */
/*   Updated: 2023/04/25 12:44:45 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clear2d(char **str)
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
