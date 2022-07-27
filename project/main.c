/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:33:52 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/27 18:40:01 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
    char *buf;
    int r;
    fd = open("test1.txt", O_RDONLY); // get the fd from open
    // printf("fd is %d \n",fd);
	buf = get_next_line(fd);
	printf("Current line value %s \n",buf);
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
	return 0;
}
