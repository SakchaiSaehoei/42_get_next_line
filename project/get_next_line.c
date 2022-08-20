/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:50:16 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/20 18:05:00 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_dup_free(char *original,char *temp)//what is sub is null?
// {
// 	char	*buffer;

// 	buffer = ft_strdup(temp);
// 	free(original);
// 	return(buffer);
// }

// char	*ft_free(char *original, char *temp)
// {
// 	char	*buffer;

// 	buffer = ft_strjoin(original, temp);
// 	// free(original);
// 	return (buffer);
// }

// char	*ft_free(char *original,char *temp,char m_dj, char mode)//with mode
char	*ft_free(char *original,char *temp,char m_dj)//with out mode
{
	char	*buffer;
	int		dummy;

	dummy = 0;
	if (m_dj == DUP)
	{
		buffer = ft_dup_with_mode(temp,TILL_NULL,&dummy);
		free(original);
	}
	else if (m_dj == JOIN)
	{
		buffer =  ft_strjoin(original, temp);
		free(original);
	}
	else
	{
		buffer = NULL;
	}

	// m_dj = 'a';
	// printf("buffer == |%s|",buffer);
	return(buffer);
}

char	*ft_read(int fd , char *s)
{
	char	*read_buff;
	int		read_byte;

	// printf("ft_read \n ");

	if(!s)
		s = ft_calloc(1,1);
	read_buff = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
	if(!read_buff)
		return NULL;
	read_byte = 1;
	while(read_byte > 0)
	{
		read_byte = read(fd, read_buff,BUFFER_SIZE);
		read_buff[read_byte] = '\0';
		// printf("read_byte === %d\n",read_byte);
		if(read_byte <= 0)
			break;
		s = ft_free(s,read_buff,JOIN);
		if (ft_strchr(read_buff,'\n'))
			break;
	}
	free(read_buff);
	// printf("s = %s\n",s);
	return(s);
}
char	*ft_get_line(char *remain,int *len)
{
	char	*re_buff;

	// printf("ft_get_line \n ");

	if (ft_strchr(remain,'\n'))
	{
		re_buff = ft_dup_with_mode(remain,TILL_N ,len);
	}
	else
	{
		re_buff =ft_dup_with_mode(remain,TILL_NULL,len);
		*len = -1;
	}
	// printf("re_buff  == %s\n",re_buff);

	return(re_buff);
}
char	*ft_next(char *remain,int index)
{
	char	*buffer;
	int		dummy;
	char	*temp;

	dummy = 0;
	buffer = (remain + index);
	// printf("BUFFER = %s\n",buffer);
	if(*buffer != '\0')
	{
		// temp = ft_free(buffer,remain,DUP);
		temp = ft_free(remain,buffer,DUP);
		// buffer =  ft_dup_with_mode(original,TILL_NULL,&dummy);

	}
	else
	{
		// printf("there in no value after\n");
		temp = NULL;
	}

	return(temp);
}
char	*get_next_line(int fd)
{
	char	*re_buff;// buffer for return

	static	char	*remain;
	int		current_remain_len;

	current_remain_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remain = ft_read(fd ,remain);
	// printf("remian after read = %s\n",remain);
	re_buff = ft_get_line(remain,&current_remain_len);
	// printf("re_buff after ft_get_line  == %s\n",re_buff);
	if (re_buff[0] == '\0')
	{
		// printf("re_buff[0] == '0)\n");
		return(NULL);
	}
	if (current_remain_len != -1)
	{

		// printf("there is next value\n");
		remain = ft_next(remain,current_remain_len); // to keep the next value
	}
	else
	{
		// printf("there in no value after\n");
		remain[0] = '\0';
		free(remain);
		remain = NULL;
		// return(NULL);
	}
	return(re_buff);
}
