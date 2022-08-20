/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:17:30 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/19 00:24:10 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_the_line(int fd) // i want to keep reaminng string in here
{
	char	*completed_line;
	char	*read_buff;
	static char *remain;
	int	found_n;
	int	read_byte;

	// printf("+++++++++++++++++ remain intual value: %s\n",remain);
	// printf("++++++++++++++++++len of intual remain %lu\n",ft_strlen(remain));
	found_n = 0;
	read_buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if(!read_buff)
			return NULL;
	completed_line = ft_calloc(OPEN_MAX + 1,sizeof(char)); // use OPEN_MAX for?
	read_byte = 1;
	// printf("Before while loop\n");
	while (read_byte > 0 )// && still readable //!found_n  ||
	{
		read_byte = read(fd, read_buff, BUFFER_SIZE); // now I can use string in read_buff to to do stuff
		if (read_byte == -1) {
			free (read_buff);
			return (NULL);
		}
		read_buff[read_byte] = '\0'; // read will not null terminate the return string
		// printf("read_buff :  %s\n",read_buff);
		if (ft_strchr(read_buff, '\n'))
			found_n == 1;
		// printf("FOUND STATUS %d\n",found_n);
		// printf("remain before dup : %s\n",remain);
		completed_line = ft_strdup(remain);
		// printf("COMPLETE LINE  BEFORE STRJOIN ::::::::  %s\n",completed_line);
		completed_line = ft_strjoin(completed_line, read_buff);//concat read_buff after completed line
		// printf("CURRENT VALUE AFTER JOIN      ::::::::  %s \n",completed_line);
		if (found_n)
		{
			remain = ft_strchr(read_buff, '\n');
			remain++;
			// printf("CURRENT VALUE when \\n IS FOUNDED %c \n",*remain);
			remain = ft_strdup(remain);
			// printf("AFTER DUPPPPP %s\n",remain);
			free (read_buff);
			break;
		}
		else if(!found_n)
		{
			remain = ft_strdup(completed_line);
			// free(completed_line);
			// printf("AFTER DUPPPPP %s\n",remain);
		}
		// printf("---------------------------------\n");
		// printf("REMAINING VALUE OF EACHHHHHHHH LOOP %s\n",remain);
		// printf("---------------------------------\n");
		// printf("---------------------------------\n");
		// printf("---------------------------------\n");
	}
	free(completed_line);
	return(completed_line);
}


// char	*get_the_line_2(int fd) // i want to keep reaminng string in here
// {
// 	char	*completed_line;
// 	char	*read_buff;
// 	static char *remain;
// 	int	found_n;
// 	int	read_byte;
// 	// char	*temp;

// 	found_n = 0;
// 	read_buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
// 		if(!read_buff)
// 			return NULL;
// 	read_buff[BUFFER_SIZE] = '\0';
// 	completed_line = ft_calloc(OPEN_MAX + 1,sizeof(char)); // use OPEN_MAX for?
// 	read_byte = 1;
// 	while (read_byte > 0 )// && still readable //!found_n  ||
// 	{
// 		read_byte = read(fd, read_buff, BUFFER_SIZE); // now I can use string in read_buff to to do stuff
// 		// if (read_byte == -1) {
// 		// 	free (read_buff);
// 		// 	return (NULL);
// 		// }
// 		// read_buff[read_byte] = '\0';


// 		if (ft_strchr(read_buff, '\n'))
// 		{
// 			remain = ft_strchr(read_buff, '\n');
// 			remain++;
// 			remain = ft_strdup(remain);
// 			completed_line = ft_strjoin(completed_line, read_buff);//concat read_buff after completed line

// 			// free (read_buff);
// 			break;
// 		}
// 		else
// 		{
// 			remain = ft_strdup(completed_line);
// 			ft_memset(completed_line, '\0', OPEN_MAX * sizeof(char));
// 		}


// 		completed_line = ft_strdup(remain);
// 		completed_line = ft_strjoin(completed_line, read_buff);//concat read_buff after completed line
// 		// if (found_n)
// 		// {
// 		// 	remain = ft_strchr(read_buff, '\n');
// 		// 	remain++;
// 		// 	remain = ft_strdup(remain);
// 		// 	free (read_buff);
// 		// 	break;
// 		// }
// 		// else if(!found_n)
// 		// {
// 		// 	remain = ft_strdup(completed_line);
// 		// 	// free(completed_line);
// 		// }
// 	}
// 	// free(completed_line);
// 	return(completed_line);
// }

char	*get_next_line(int fd)
{
	// char	*buffer; // i am t===
	char	*res_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// res_line = NULL;
	// char	*remain;
	// printf("welcome to get next line \n");
	// first buffer will need to store the string that is terminated by '\n'
	res_line = get_the_line(fd); // frist try to write to get the frist line.
	return (res_line);
}

