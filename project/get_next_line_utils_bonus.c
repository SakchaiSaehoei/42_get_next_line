/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:50:42 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/21 05:47:59 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_with_mode(char *s,char mode)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while(*(s + count) != mode)
	{
		count++;
	}
	if (mode == '\n' && *(s + count) == '\n')
		count++;
	return (count);
}

char	*ft_dup_with_mode_n(char *s,char mode ,int *len)
{
	size_t	i;
	size_t	s_len;
	char	*buf;

	if (!s)
		return (NULL);
	s_len = ft_strlen_with_mode(s, mode);
	buf = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	*len = i;
	return (buf);

}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	unsigned char	*buff;
	size_t	i;
	size_t	masize;

	masize = nmemb * size;
	a = malloc(masize);
	i = -1;
	if (nmemb == i || size == i)
		return (NULL);
	if (a == NULL || size == 0)
		return (a);
	i++;
	buff = (unsigned char *)a;
	while (i < masize)
	{
		(*buff) = '\0';
		buff++;
		i++;
	}
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*new_str;

	if(!s1 || !s2)
		return(NULL);
	s1_len = ft_strlen_with_mode(s1,0);
	s2_len = ft_strlen_with_mode(s2,0);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	if (!new_str)
		return (NULL);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strchr( char *s, int c)// use to check if '\n' is exits/
{
	if (!s)
		return (NULL);
	while (*s != '\0' && (char)c != *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
