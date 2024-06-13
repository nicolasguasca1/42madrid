/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+   :*/
/*                                                    +:+ +:+         +:+     */
/*   By: nguasca <nguasca@student.42madrid.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:07:37 by nguasca           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:37 by nguasca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	print_error(char *message)
{
	while (*message)
		write(2, message++, 1);
	write(2, "\n", 1);
}

int	reading_file(int fd)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (write(1, buffer, bytes_read) != bytes_read)
		{
			print_error("Cannot write to stdout.");
			close(fd);
			return (1);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		print_error("Cannot read file.");
		close(fd);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
	{
		print_error("File name missing.");
		return (1);
	}
	else if (argc > 2)
	{
		print_error("Too many arguments.");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Cannot read file.");
		return (1);
	}
	if (reading_file(fd) == 1)
		return (1);
	close(fd);
	return (0);
}
