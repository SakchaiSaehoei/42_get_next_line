/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:17:30 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/27 18:48:42 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// char 	*buf;
	// char	*temp;
	// char	*pendig;
	// int r;
	static char	*remaining;
	data	d;
	int	i = 0;
	int	j;
	d.buf =(char*)malloc(sizeof(char) * BUFFER_SIZE); /// to overwirte the value inside buf every time when this function is called
	// *(d.buf + BUFFER_SIZE) = '\0';
	d.r = read(fd, d.buf, BUFFER_SIZE);
	d.temp = (char*)malloc(sizeof(char) * d.r);
	*(d.temp + d.r) = '\0';
	*(d.buf + d.r) = '\0';
	while (d.buf[i] != '\n')
	{
		d.temp[i] = d.buf[i];
		i++;
	}
	d.temp[i++] = '\n';
	d.temp[i++] = 0 ;

	j = 0;
	printf(" i = %d and d.r = %d \n",i,d.r);
	printf("d.r - i + 1 = %d\n",(d.r - i + 1));
	if (i < d.r)
	{
		remaining = (char*)malloc(sizeof(char) * (d.r - i + 1));
		while (d.buf[i] != 0)
		{
			remaining[j++] = d.buf[i++];
		}
	}


	printf("Remaining value is %s\n",remaining);

	return d.temp;
}
