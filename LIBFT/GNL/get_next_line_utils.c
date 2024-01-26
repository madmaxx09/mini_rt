/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:44 by mdor              #+#    #+#             */
/*   Updated: 2024/01/26 10:39:28 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_g(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*a;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_g((char *)s1);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	*protect(char *fdp, char *sonpote)
{
	if (fdp)
		free(fdp);
	if (sonpote)
		free(sonpote);
	return (NULL);
}
