/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:50:16 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/21 05:48:07 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *original,char *temp,char m_dj)
{
	char	*buffer;
	int		dummy;

	dummy = 0;
	if (m_dj == DUP)
	{
		buffer = ft_dup_with_mode_n(temp,TILL_NULL,&dummy);
	}
	else if (m_dj == JOIN)
	{
		buffer =  ft_strjoin(original, temp);
	}
	else
	{
		buffer = NULL;
	}

	if(original)
	{
		free(original);
		original = NULL;
	}
	return(buffer);
}


char	*ft_read(int fd , char *s)
{
	char	*read_buff;
	int		read_byte;

	if(!s)
		s = ft_calloc(1,1);
	read_buff = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
	if(!read_buff)
		return NULL;
	read_byte = read(fd, read_buff,BUFFER_SIZE);
	read_buff[read_byte] = '\0';
	while(read_byte > 0)
	{
		s = ft_strjoin(s,read_buff);
		if(ft_strchr(s,'\n') || read_byte < BUFFER_SIZE)
			break;
		read_byte = read(fd, read_buff,BUFFER_SIZE);
		read_buff[read_byte] = '\0';
	}
	free(read_buff);
	return(s);
}

char	*ft_get_line(char *remain,int *len)
{
	char	*re_buff;
	if (ft_strchr(remain,'\n'))
	{
		re_buff = ft_dup_with_mode_n(remain,TILL_N ,len);
	}
	else
	{
		re_buff =ft_dup_with_mode_n(remain,TILL_NULL,len);
		*len = -1;
	}

	return(re_buff);
}

char	*ft_next(char *remain,int index)
{
	char	*buffer;
	int		dummy;
	char	*temp;

	dummy = 0;
	buffer = (remain + index);
	if(*buffer != '\0')
	{
		temp = ft_free(remain,buffer,DUP);
		buffer= NULL;
	}
	else
	{
		free(remain);
		temp = NULL;
	}

	return(temp);
}
char	*get_next_line(int fd)
{
	char	*re_buff;
	static	char	*remain[OPEN_MAX];
	int		current_remain_len;

	current_remain_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= OPEN_MAX)
		return (NULL);
	remain[fd] = ft_read(fd ,remain[fd]);
	re_buff = ft_get_line(remain[fd],&current_remain_len);
	if (re_buff[0] == '\0')
	{
		free(remain[fd]);
		remain[fd] = NULL;
		free(re_buff);
		return(NULL);
	}
	if (current_remain_len != -1)
		remain[fd] = ft_next(remain[fd], current_remain_len);
	else
	{
		if (remain[fd])
			free(remain[fd]);
		remain[fd] = NULL;
	}
	return(re_buff);
}
