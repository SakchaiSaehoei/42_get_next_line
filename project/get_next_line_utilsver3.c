/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilsver3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:41:24 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/20 10:26:44 by ssaehoei         ###   ########.fr       */
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

size_t	ft_strlen_with_mode(char *s,char mode)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while(*s != mode)
	{
		s++;
		count++;
	}
	if (mode == '\n' && *s == '\n')
		count++;
	return (count);
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
/*expected behavior of ft_str_mod
1. return when '\n' is deteced
2. if ther *(s + 1) have value return *(s+1); to use for str join  to remain afterwards
3.	else return *(s);
*/
char	*ft_strchr_mod( char *s, int c,int *detct_n,int *v_after_n)// use to check if '\n' is exits/
{
	if (!s)
		return (NULL);
	while (*s != '\0' && (char)c != *s)
		s++;
	// printf("curren s in strchr %s\n",s+1);
	if (*s == (char)c){
		*detct_n = 1;
		if(*(s + 1) != '\0')
		{
			*v_after_n = 1;
			// printf("There value after n ");
			s++;
		}
		// else if (*(s + 1) == '\0')
		// {
		// 	*v_after_n = 0;
		// 	printf("There value after n ");

		// }
		return ((char *)s);
	}
	return (0);
}
// void	*ft_check_n(char *s, int *decte_n , int *v_after_n)
// {
// 	if (!s)
// 		return (NULL);
// 	while (*s != '\0' && *s != '\n')
// 		s++;
// 	if (*s == '\n'
// 	{
// 		*detct_n = 1;
// 		if(*(s + 1) != '\0')
// 		{
// 			*v_after_n = 1;
// 			s++;
// 		}
// 		else if (*(s + 1) == '\0')
// 		{
// 			*v_after_n = 0;
// 		}
// 		return ((char *)s);
// 	}
// 	return (0);
// }
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
/*expected behavior of ft_str_mod
1. return joined string
2. if ther *(s + 1) have value return *(s+1); to use for str join  to remain afterwards
3.	else return *(s);
*/
char	*ft_strjoin_mod(char *s1, char *s2,int *remain_len)
{
	size_t	len_all;
	size_t	i;
	char	*new_str;

	len_all = *remain_len + ft_strlen(s2);
	*remain_len = len_all;
	new_str = ((char *)malloc((sizeof(char) * len_all) + 1));
	i = 0;
	if (!new_str)
		return (NULL);
	if (s1)
	{
		while (*s1 != '\0')
		{
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
	return (new_str);
}

//                            free       readbuff
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_all;
	size_t	i;
	char	*new_str;

	len_all = ft_strlen(s1) + ft_strlen(s2);
	new_str = ((char *)malloc(sizeof(char) * (len_all + 1)));
	i = 0;
	if (!new_str || !s1 || !s2)
		return (NULL);
	while (*(s1 + i)!= '\0')
	{
			*(new_str + i) = *(s1+i);
			i++;
	}
	free(s1);
	while (*s2 != '\0')
	{
		*(new_str + i) = *s2;
		s2++;
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}
/*USE OF FT_STRDUP SCENARIO
	when '\n' is found in read_buff by using ft_strchr(read_buff)
	1.ft_strlcat() to concat the remain by read_buff
	2.ft_strdup remain to completed_line for return;
	3.set curren_remain_len to 0;
*/
char	*ft_strdup( char *s)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,TILL_NULL) + 1));
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

char	*ft_dup_with_mode( char *s,char mode ,int *len)
{
	char	*buf;
	int		i;

	if (!s)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen_with_mode(s,mode) + 1));
	i = 0;
	if (!buf)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(buf + i) = *(s + i);
		if((*(buf + i) == '\n') && mode == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	*(buf + i) = '\0';
	*len = i;
	if(s)
		free(s);
	s = NULL;
	return (buf);
}

void	*ft_memset(void *s, int c, size_t n)//not use yet
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
/*USE OF FT_STRLCAT SCENARIO
	when '\n' is found in read_buff by using ft_strchr(read_buff)
	1.ft_strlcat() to concat the remain by read_buff
	2.ft_strdup remain to completed_line for return;
	3.set remain[0] = NULL;
*/

