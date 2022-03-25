/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:56:33 by fheidi            #+#    #+#             */
/*   Updated: 2021/12/04 19:34:46 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new_st;
	int		len;

	len = ft_strlen(s);
	new_st = (char *)malloc(sizeof(s[0]) * (len + 1));
	if (NULL == new_st)
		return (NULL);
	new_st[len] = '\0';
	while ((len - 1) >= 0)
	{
		new_st[len - 1] = s[len - 1];
		len--;
	}
	return (new_st);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_st;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_st = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (NULL == new_st)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_st[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_st[i++] = s2[j++];
	new_st[i] = '\0';
	return (new_st);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_st;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	new_st = (char *)malloc(nmemb * size);
	if (NULL == new_st)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		new_st[i] = 0;
		i++;
	}
	return (new_st);
}
