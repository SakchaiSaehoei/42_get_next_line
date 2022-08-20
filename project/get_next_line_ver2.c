/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:24:58 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/17 17:24:58 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_join_free(char *s1, char *s2, int *remain_len)
char	*ft_join_free(char *s1, char *s2, int *remain_len,char mode)
{
	char	*temp;

	// temp = ft_strjoin_mod(s1, s2,remain_len);
	*remain_len = *remain_len;
	temp = ft_strjoin_with_mode(s1, s2,mode);
	free(s1);
	s1 = NULL;
	// free(s2);
	return (temp);
}

// int		ft_read(fd, read_buff, read_byte)
// {
// 	// int		read_byte;

// 	// read_byte = read(fd, read_buff,BUFFER_SIZE);
// 	if(read_byte == -1){
// 		free(read_buff);
// 		return(0);
// 	}
// }

// void	ft_detect_n(char **remain, char **buff)
// {

// }

char	*get_next_line(int fd)
{
	char	*read_buff;
	int		read_byte;
	static	t_data *remain_data = NULL;
	char	*buff;//for return whole line
	char	*temp;

	buff = 0;
	// printf("here\n");

	/*initial remain data*/
	// printf("Welcome to get the line\n");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}

	if (remain_data == NULL)//initual reamin data
	{
		remain_data = (t_data *)malloc(sizeof(t_data));
		// if(remain_data)
		// 	printf("malloc struct remain data \n");
		remain_data->remain =  NULL;
		remain_data->current_remain_len = 0;// len - 1 = last index
		remain_data->detect_n = false;
		remain_data->va_after_n = false;
		// printf("initualed \n");
		// printf("remain_data->remain = %s\n",remain_data->remain);
		// printf("remain_data->current_remain_len = %d\n",remain_data->current_remain_len);
		// printf("remain_data->detect_n = %d\n",remain_data->detect_n);
		// printf("remain_data->detect_n = %d\n",remain_data->va_after_n);

	}
	/*start procces of reaidn */
	// read_buff = (char*)malloc(sizeof(char)* BUFFER_SIZE + 1);
	// ft_calloc(BUFFER_SIZE + 1,sizeof(char))
	read_buff = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
		if(!read_buff)
			return NULL;
	read_byte = 1;
	while(read_byte > 0)// in this loop we nned to update reamin_data.reamin and when '\n' is found strdup to
	{
		read_buff = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
		if(!read_buff)
			return NULL;
		read_byte = read(fd, read_buff,BUFFER_SIZE);
		if(read_byte == -1){
			free(remain_data);
			free(read_buff);
			return(NULL);
		}
		read_buff[read_byte] = '\0';
		temp = ft_strchr_mod(read_buff,'\n',&remain_data->detect_n,&remain_data->va_after_n);
		if(remain_data->detect_n)
		{
			if (remain_data->va_after_n)
			{
				// remain_data->remain = ft_strjoin(remain_data->remain,read_buff);
				buff = ft_join_free(remain_data->remain,read_buff,&remain_data->current_remain_len,TILL_N);//remain_data->remain is freed inside the function
				remain_data->remain = ft_strdup(temp);// after remaindata->remain is freed in ft_strjoin free we malloc in dup to assgin remain value after '\n' in read_buff
				remain_data->detect_n = false;
				// free(read_buff);

				break;
			}
			else//va_after_n = false; no need to use remain anymore
			{
				buff = ft_join_free(remain_data->remain,read_buff,&remain_data->current_remain_len,TILL_N);//remain_data->remain is freed inside the function
				// free(remain_data->remain);
				remain_data->detect_n = false;
				free(remain_data);
				remain_data = NULL;
				// free(read_buff);
				// read_buff = NULL;

				break;
			}
		}
		else
		{
			remain_data->remain = ft_join_free(remain_data->remain, read_buff,&remain_data->current_remain_len,TILL_NULL);
			// free(read_buff);
		}
	}
	free(read_buff);
	return(buff);
}
