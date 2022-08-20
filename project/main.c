/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:33:52 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/20 23:12:23 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void test(char *data)
// {
//   char **s = data;
//   data = "helloYzxcvzxv";

// }

// void test2(int *last_index)
// {
//   *last_index = *last_index + 50;

// }
int	main(void)
{
	int fd;
    char *buf;
    int r;
	// char *array;
	// int	i;
	// t_data	*remain_data = NULL;



	// if (!remain_data)//initual reamin data
	// {
	// 	remain_data = (t_data *)malloc(sizeof(t_data));

	// 	remain_data->remain =  (char *)malloc(sizeof(char)* (5+1) );
	// 	remain_data->current_remain_len = 0;// len - 1 = last index
	// 	remain_data->detect_n = false;
	// }

	// printf("%lu",sizeof(t_data));
	// free(remain_data->remain);
	// remain_data->remain = NULL;
	// if(!remain_data->remain)
	// 	printf("!reamain %s\n",remain_data->remain);
	// else
	// 	printf("reamain still rech able%s\n",remain_data->remain);
	// printf("remain address %p\n",&remain_data->remain);
	// printf("remain_data address  %p\n",&remain_data);

	// printf("current remain len  %d\n",remain_data->current_remain_len);
	// printf("found N ? %d",remain_data->detect_n);
	// r = ft_strlen_with_mode(array,LEN_TILL_NULL);
	// size_t open_max = OPEN_MAX;
	// printf("len till null = %d",r);
	// printf("Open max : %d",OPEN_MAX);
    fd = open("./gnlTester/files/alternate_line_nl_with_nl", O_RDONLY); // get the fd from open
    // fd = open("test2.txt", O_RDONLY); // get the fd from open
    // printf("fd is %d \n",fd);
	// printf("fd === %d \n",fd);
	r = 1;
	buf = get_next_line(fd);
	while (buf)
	{
		// expected return is a new line the terminated by '\n'
		// if (ft_strchr(buf,'\n'))
		// 	printf("there is  a \\n at the end of the returned line %d\n",r);
		printf("RETURN THE %d LINE |%s|",r,buf);
		free(buf);
		buf = get_next_line(fd);
//		buf = NULL;
		r++;
	}
	printf("RETURN THE %d LINE |%s|",r,buf);
	free(buf);

	return 0;
}
