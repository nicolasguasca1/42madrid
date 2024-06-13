/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguasca <nguasca@student.42madrid.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:07:37 by nguasca           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:37 by nguasca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUFFER_SIZE 4096

void	ft_cat(int fd)
{
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	ssize_t		bytes_written;	
	const char	*error_msg;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	error_msg = strerror(errno);
	while (bytes_read > 0)
	{
		bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
		if (bytes_written < 0)
		{
			write(STDERR_FILENO, error_msg, strlen(error_msg));
			return ;
		}
		bytes_read = 0;
	}
	if (bytes_read < 0)
	{
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return ;
	}
}

int	handle_arguments_and_open_file(int argc, char *argv[])
{
	const char	*program_name;
	const char	*usage_msg;
	char		*filename;
	int			fd;
	const char	*error_msg;

	program_name = basename(argv[0]);
	usage_msg = "Usage: %s <filename>\n";
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	error_msg = strerror(errno);
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, usage_msg, program_name);
		return (-1);
	}
	if (fd < 0)
	{
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (-1);
	}
	return (fd);
}

int	process_file(int fd)
{
	const char	*error_msg;

	ft_cat(fd);
	error_msg = strerror(errno);
	if (close(fd) < 0)
	{
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	result;

	fd = handle_arguments_and_open_file(argc, argv);
	if (fd < 0)
	{
		return (1);
	}
	result = process_file(fd);
	return (result);
}
