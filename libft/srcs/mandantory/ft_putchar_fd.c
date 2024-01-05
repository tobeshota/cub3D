/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:39:15 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:39 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(int c, char**v)
// {
// 	// char c;
// 	int fd;
// 	close(0);
// 	free(123);
// 	fd = open("test.txt", O_RDWR);
// 	if (fd == -1)
// 		printf("The file doesn't exist.\n");

// 	write(fd, v[0], 10);
// 	return (0);
// }
