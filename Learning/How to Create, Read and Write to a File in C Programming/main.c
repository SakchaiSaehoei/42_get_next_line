/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:15 by marvin            #+#    #+#             */
/*   Updated: 2022/07/23 14:05:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
// Steps for Processing a File
// 1. Declare a file pointer vairable
// 2. Open a file using fopen()
// 3. Process the file using fclose () funciton
// 4. close the file using fclose() funciotn


//https://www.youtube.com/watch?v=dP3N8g7h8gY
// fopen, fclose, getc ,putc ,getw

int main()
{
    int fd;
    char buf[20];
    fd = open("test1.txt", O_RDONLY); // get the fd from open
    printf("fd is %d \n",fd);
    if(fd == -1)
    {
        printf("Failed to open and read the file .\n");
        exit(1);
    }
    //        ssize_t read(int fd, void *buf, size_t count);
    //  After we get fd from open we use read funcion then we put fd to make selecte which file that we are going to read
    // and buffer use to stroge  value that we read and be cuase of it is char array so we need to null terminate 
    // and  we put size_t count in order to set how many bytes to read;
    read(fd, buf, 20);
    buf[13] = '\0';
    close(fd);
   

    printf("buf : %s \n", buf);
    
    return 0;

}