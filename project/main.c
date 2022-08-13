/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:33:52 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/13 16:36:30 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
    char *buf;
    int r;
	size_t open_max = OPEN_MAX;

	// printf("Open max : %d",OPEN_MAX);
    fd = open("test2.txt", O_RDONLY); // get the fd from open
    // printf("fd is %d \n",fd);
	r = 1;
	while (r < 6)
	{
		buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	if (ft_strchr(buf,'\n'))
		printf("there is  a \\n at the end of the buff\n");
	printf("RETURN THE %d LINE ::::::::%s|",r,buf);
		r++;
	}
	// buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	// if (ft_strchr(buf,'\n'))
	// 	printf("there is  a \\n at the end of the buff\n");
	// printf("RETURN THE 1ST LINE ::::::::  %s| \n =======================\n=======================\n=======================\n",buf);
	// buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	// if (ft_strchr(buf,'\n'))
	// 	printf("there is \\n at the end of the buff\n");
	// printf("RETURN THE 2RD LINE ::::::::  %s \n=======================\n=======================\n=======================\n",buf);
	// buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	// if (ft_strchr(buf,'\n'))
	// 	printf("there is \\n at the end of the buff\n");
	// printf("RETURN THE 3RD LINE ::::::::  %s \n=======================\n=======================\n=======================\n",buf);
	// buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	// buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	// printf("RETURN THE 5TH LINE ::::::::  %s \n=======================\n=======================\n=======================\n",buf);


	// if (buf == NULL)
	// 	printf("buff is NUll");
	// else
	// {
	// 	printf("%s",buf);
	// }
	// buf = get_next_line(fd);// expected return is a new line the terminated by '\n'
	// printf("===second call=== %s",buf);
	// printf("===third call=== %s",buf);



	// buf = get_next_line(fd);
	// printf("%s \n",buf);
	// buf = get_next_line(fd);
	// printf("%s \n",buf);
	// buf = get_next_line(fd);
	// printf("%s \n",buf);
	// buf = get_next_line(fd);
	// printf("%s \n",buf);
	// buf = get_next_line(fd);
	// printf("%s \n",buf);
	// buf = get_next_line(fd);
	// printf("%s \n",buf);
	// ft_calloc(5, sizeof(char));
	return 0;
}
