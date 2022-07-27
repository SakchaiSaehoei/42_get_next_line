/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:19:37 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/07/27 18:44:02 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// # define BUFFER_SIZE 50
typedef	struct Data {
	char	*buf;
	char	*temp;
	char	*pending;

	int		r;
} data ;
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);

#endif
