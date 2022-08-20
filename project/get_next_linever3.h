/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linever3.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:19:37 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/08/20 11:15:37 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# define TILL_NULL '\0'
# define TILL_N '\n'
# define DUP 'd'
# define JOIN 'j'


/*USE OF STRUCT
1. remain for contain string until '\n' is found
2. current_remain_last_value_index will indecate index of last value befor NULL for concat uses
3. current_remain_len store the length of remaining value
*/
typedef struct s_data {
	char	*remain;
	// int		current_remain_last_value_index;// how to initual?
	int		current_remain_len;
	// bool	initual;
	int		detect_n;
	int		va_after_n;
	// char	*r_buf_pointer;
} t_data ;

char	*get_next_line(int fd);
size_t	ft_strlen_with_mode(char *s,char mode);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup( char *s);
char	*ft_strchr( char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_with_mode(char  *s1, char  *s2,char mode);
// char	*get_the_line(int fd); for fist version
char	*get_the_line(int fd);//for new version
void	*ft_memset(void *s, int c, size_t n);
char	*ft_dup_with_mode( char *s,char mode, int *len);
// char	*ft_join_free(char *s1, char *s2, int *remain_len,char mode); for version 2
char	*ft_join_free(char *til_eof, char *read_buff, int *remain_len,char mode);
char	*ft_strjoin_mod(char *s1, char *s2,int *remain_len);
char	*ft_strchr_mod( char *s, int c,int *detct_n,int *v_after_n);
size_t	ft_strlen_with_mode(char *s,char mode);
char	*ft_dup_free(char *original, char *temp);
char	*ft_read(int fd, char *s);
// char	*get_the_line_2(int fd);
# endif
