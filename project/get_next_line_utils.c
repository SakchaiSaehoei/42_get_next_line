/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:50:42 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/21 00:10:22 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
////temp
size_t	ft_strlen(char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while(*(s + count)!= '\0')
	{
		// s++;
		count++;
	}
	return (count);
}

size_t	ft_strlen_with_mode(char *s,char mode)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while(*(s + count) != mode)
	{
		// s++;
		count++;
	}
	if (mode == '\n' && *(s + count) == '\n')
		count++;
	return (count);
}
//							remian, char,    &len
char	*ft_dup_with_mode( char *s,char mode ,int *len)
{
	char	*buf;
	int		i;

	printf("%s\t|%c|\n",s,mode);
	if (!s)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,mode) + 1));
	if (!buf)
		return (NULL);
	printf("strlen wit mode = %zu\n",ft_strlen_with_mode(s,mode));
	i = 0;
	while (*(s + i) != '\0')
	{
		*(buf + i) = *(s + i);
		printf("====== %p = %c\t%p = %c =======\n", &buf[i], buf[i], &s[i], s[i]);
		if((*(buf + i) == '\n') && mode == '\n')
		{
			i++;
			break;
		}
		i++;
	}

	*(buf + i) = '\0';
	*len = i;

	// printf("len of buf %zu\n",ft_strlen(buf));
	printf("address of = %p\n",&s[0]);
	if(s)
	{
		free(s);
		s = NULL;
	}
	return (buf);
}

void	*ft_calloc(size_t nmemb, size_t size)// not sure if it is really nesserslay or not
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

	if(!s1 || !s2)
		return(NULL);
	// printf("f1 == |%s| \n f2 == |%s| \n",s1,s2);
	len_all = ft_strlen(s1) + ft_strlen(s2);
	// printf("len all = %zu\n",len_all);
	new_str = (char *)malloc(sizeof(char) * (len_all + 1));
	i = 0;
	if (!new_str)
		return (NULL);
	while (*(s1 + i)!= '\0')
	{
			*(new_str + i) = *(s1+i);
			i++;
	}
	while (*s2 != '\0')
	{
		*(new_str + i) = *s2;
		s2++;
		i++;
	}
	*(new_str + i) = '\0';
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


// tempppppp

char	*ft_strdup( char *s)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
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
