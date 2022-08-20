/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:50:42 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/21 05:20:07 by ssaehoei         ###   ########.fr       */
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
char	*ft_dup_with_mode_n(char *s,char mode ,int *len)
{
	size_t	i;
	char	*buf;

	if (!s)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,mode) + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < ft_strlen_with_mode(s,mode))
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	*len = i;

	return (buf);

}
char	*ft_dup_with_mode_null( char *s,char mode ,int *len)
{
	int		i;
	char	*buf;

	if (!s)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,mode) + 1));
	if (!buf)
		return (NULL);

	i = 0;
	while (*(s + i) != '\0')
	{
		*(buf + i) = *(s + i);
		i++;
	}
	*(buf + i) = '\0';
	*len = i;
	return (buf);

}
//							remian, char,    &len
char	*ft_dup_with_mode( char *s,char mode ,int *len)
{
	int		i;
	char	*buf;

	buf = NULL;
	if (!s)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,mode) + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(buf + i) = *(s + i);

		if((*(buf + i) == '\n') && (mode == '\n'))
			break;
		i++;
	}
	*(buf + i) = '\0';
	*len = i;
	if(s)
	{
		free(s);
		s = NULL;
	}

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
	size_t	len_all;
	size_t	i;
	size_t	j;
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
	// while (*(s1 + i)!= '\0')
	while (i < ft_strlen(s1))
	{
		*(new_str + i) = *(s1+i);
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		*(new_str + i) = *(s2 + j);
		j++;
		i++;
	}
	*(new_str + i) = '\0';
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


// tempppppp

// char	*ft_strdup( char *s)
// {
// 	char	*buf;
// 	int		i;
// 	if(!s)
// 		return(NULL);
// 	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,TILL_NULL) + 1));
// 	i = 0;
// 	if (!buf)
// 		return (NULL);
// 	while (*(s + i) != '\0')
// 	{
// 		*(buf + i) = *(s + i);
// 		i++;
// 	}
// 	*(buf + i) = '\0';
// 	return (buf);
// }