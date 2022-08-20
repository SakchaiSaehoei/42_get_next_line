/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:51:30 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/21 05:47:49 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# define TILL_NULL '\0'
# define TILL_N '\n'
# define DUP 'd'
# define JOIN 'j'
#
//utils
void	*ft_calloc(size_t nmemb, size_t size);//*
char	*ft_strchr( char *s, int c);//*
char	*ft_strjoin(char *s1, char *s2);
char	*ft_dup_with_mode( char *s,char mode, int *len);//*
char	*ft_dup_with_mode_n( char *s,char mode, int *len);//*
char	*ft_dup_with_mode_null( char *s,char mode, int *len);//*
char	*ft_strdup( char *s);
size_t	ft_strlen_with_mode(char *s,char mode);
size_t	ft_strlen(char *s);

//get_next_line
// char	*get_the_line(int fd);//for new version *
char	*ft_read(int fd, char *s);//*
// char	*ft_free(char *original, char *temp,char m_dj, char mode); //with mode
char	*ft_free(char *original, char *temp,char m_dj);//with out mode
char	*get_next_line(int fd);//*
char	*ft_get_line(char *remain,int *len);

# endif

