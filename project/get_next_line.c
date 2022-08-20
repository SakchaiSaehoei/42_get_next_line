/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:50:16 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/21 05:18:28 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// char	*ft_free(char *original,char *temp,char m_dj, char mode)//with mode
char	*ft_free(char *original,char *temp,char m_dj)//with out mode
{
	char	*buffer;
	int		dummy;

	dummy = 0;
	// printf("M_DJ = %c\n",m_dj);
	// printf("original === %s\ntemp===%s\n",original,temp);
	if (m_dj == DUP)
	{
		// temp >> original + index
		// printf("I call From FREEEEEEE\n");
		buffer = ft_dup_with_mode_null(temp,TILL_NULL,&dummy);
		// buffer = ft_strdup(temp);
		// printf("bufferrr =====  |%s|\n",buffer);
		// free(original);
	}
	else if (m_dj == JOIN)
	{
		buffer =  ft_strjoin(original, temp);
		// printf("buffer 's len = %zu\n",ft_strlen(buffer));
		// free(original);
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

// char	*ft_read(int fd , char *s)
// {
// 	char	*read_buff;
// 	int		read_byte;

// 	// printf("ft_read \n ");

// 	if(!s)
// 		s = ft_calloc(1,1);
// 	read_buff = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
// 	if(!read_buff)
// 		return NULL;
// 	read_byte = 1;
// 	while(read_byte > 0)
// 	{
// 		read_byte = read(fd, read_buff,BUFFER_SIZE);
// 		read_buff[read_byte] = '\0';
// 		printf("read_byte === %d\n",read_byte);
// 		// printf("read buff ==== %s\n",read_buff);
// 		s = ft_strjoin(s,read_buff);
// 		if(read_byte <= 0)
// 			break;
// 		// s = ft_free(s,read_buff,JOIN);
// 		// s = ft_free(s,read_buff,JOIN);
// 		if (ft_strchr(read_buff,'\n'))
// 			break;
// 	}
// 	free(read_buff);
// 	printf("S before reutrn == |%s|\n",s);
// 	return(s);
// }

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
	read_byte = read(fd, read_buff,BUFFER_SIZE);
	// printf("read buff = |%s|\n",read_buff);
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
	// printf("S before reutrn == |%s|\n",s);
	return(s);
}

char	*ft_get_line(char *remain,int *len)
{
	char	*re_buff;
	if (ft_strchr(remain,'\n'))
	{
	// printf("remain = |%s|\n",remain);
		re_buff = ft_dup_with_mode_n(remain,TILL_N ,len);
	}
	else
	{
		// printf("I call From GETTTTTTT\n");
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
	// printf("BUFFER = %s\n",buffer);
	// printf("========= %c\n",*buffer);
	if(*buffer != '\0')
	{
		// temp = ft_free(buffer,remain,DUP);
		// printf("current buffer = %c\n",*buffer);
		temp = ft_free(remain,buffer,DUP);
		buffer= NULL;
		// buffer =  ft_dup_with_mode(original,TILL_NULL,&dummy);

	}
	else
	{
		// printf("there in no value after\n");
		free(remain);
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
		// if (re_buff)
		// printf("HELLO from re_buff[0]\n");
		// printf("remain is |%s| \n rebuff is |%s|\n",remain,re_buff);
		if (remain){
			free(remain);
			remain = NULL;}
		// printf("Hello after remian\n");
		if (re_buff)
			free(re_buff);
		return(NULL);
	}
	// printf("current_remain_len = %d\n",current_remain_len);
	if (current_remain_len != -1)
	{

		// printf("reamin in get line === %s\n",remain);
		// printf("there is next value\n");
		remain = ft_next(remain,current_remain_len); // to keep the next value
	}
	else
	{
		// printf("there in no value after\n");
		// remain[0] = '\0';
		if (remain)
			free(remain);
		remain = NULL;
		// return(NULL);
	}
	return(re_buff);
}
