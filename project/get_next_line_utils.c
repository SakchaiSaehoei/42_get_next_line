/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:41:24 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/13 16:07:04 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while(*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	*ft_strchr( char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && (char)c != *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
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
	size_t	len_all;
	size_t	i;
	char	*new_str;

	len_all = ft_strlen(s1) + ft_strlen(s2);
	new_str = ((char *)malloc((sizeof(char) * len_all) + 1));
	i = 0;
	if (!new_str)
		return (NULL);
	if (s1)
	{
		while (*s1 != '\0')
		{
			*(new_str + i) = *s1;
			s1++;
			i++;
		}
	}
	while (*s2 != '\0')
	{
		*(new_str + i) = *s2;
		if(*(new_str + i )== '\n')
		{
			i++;
			*(new_str + i) = '\0';
			break;
		}
		// printf("CURRENT *s2 is %c \n",*s2);
		s2++;
		i++;
	}
	*(new_str + i) = '\0';
	// printf("RETURN OF STRJOIN  ===== %s\n",new_str);
	return (new_str);
}

char	*ft_strdup( char *s)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (!s || !buf)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(buf + i) = *(s + i);
		i++;
	}
	*(buf + i) = '\0';
	return (buf);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			b;
	unsigned char	*buff;

	buff = (unsigned char *)s;
	b = 0;
	while (b < n && *buff != '\0')
	{
		(*buff) = (c);
		buff++;
		b++;
	}
	return (s);
}
