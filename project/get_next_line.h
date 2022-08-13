/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:19:37 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/13 16:40:33 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// # define BUFFER_SIZE 50
typedef	struct Data {
	char	*buf;
	char	*temp;
	char	*pending;

	int		r;
} data ;
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup( char *s);
char	*ft_strchr( char *s, int c);
char	*ft_strjoin(char  *s1, char  *s2);
char	*get_the_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
#endif
