/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:16:48 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/20 02:17:46 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_join_free(char *til_eof, char *read_buff, int *remain_len,char mode)
// {
// 	char	*temp;

// 	// temp = ft_strjoin_mod(s1, s2,remain_len);
// 	*remain_len = *remain_len;
// 	temp = ft_strjoin(til_eof,read_buff);
// 	// if(til_eof)
// 	// 	free(til_eof);
// 	free(read_buff);
// 	read_buff = NULL;
// 	return (temp);
// }

char	*ft_dup_free(char *original,char *temp)//what is sub is null?
{
	char	*buffer;

	buffer = ft_strdup(temp);
	free(original);
	return(buffer);
}

char	*ft_join_and_free(char *s1, char *s2)
{
	char	*temp;
	temp = ft_strjoin(s1,s2);
	// free(s1);
	return(temp);
}

char	*ft_read(int fd , char *s)
{
	char	*read_buff;
	int		read_byte;

	// printf("sss in READ = %s\n",s);
	read_buff = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
		if(!read_buff)
			return NULL;
	// read_buff[read_byte] = '\0';
	read_byte = 1;
	while(read_byte > 0)
	{
		// ft_strchr_mod(read_buff,'\n',detect_n,va_after_n);
		read_byte = read(fd, read_buff,BUFFER_SIZE);
		read_buff[read_byte] = '\0';
		// printf("read byte %d\n",read_byte);
		if(read_byte <= 0)
		{
			// free(read_buff);
			break;
		}
		// printf("%s\n",read_buff);
		s = ft_join_and_free(s,read_buff);
		// printf("SSS is %s\n",s);
		if (ft_strchr(read_buff,'\n'))
			break;
	}
	free(read_buff);
	read_buff = NULL;
	return(s);
}

// if (remain_data == NULL)//initual reamin data
// 	{
// 		remain_data = (t_data *)malloc(sizeof(t_data));
// 		remain_data->remain =  NULL;
// 		remain_data->current_remain_len = 0;// len - 1 = last index
// 		remain_data->detect_n = false;
// 		remain_data->va_after_n = false;
// 	}
char	*get_next_line(int fd)
{
	char	*re_buff;// buffer for return
	char	*temp;
	static	char	*remain;
	int		current_remain_len;

	current_remain_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remain = ft_read(fd ,remain);
	if (ft_strchr(remain,'\n'))
	{
		re_buff = ft_dup_with_mode(remain,TILL_N ,&current_remain_len);
		temp = remain + current_remain_len;
		if(*temp != '\0')
		{
			remain = ft_dup_free(remain,temp);
		}
		else
		{
			free(remain);
			remain = NULL;
		}
	}
	else
	{
		re_buff =ft_dup_with_mode(remain,TILL_NULL,&current_remain_len);
		free(remain);
		remain = NULL;
	}
	return(re_buff);
}
