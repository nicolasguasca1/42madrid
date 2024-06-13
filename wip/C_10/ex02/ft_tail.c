/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguasca <nguasca@student.42madrid.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:07:37 by nguasca           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:37 by nguasca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	print_error(const char *msg)
{
	char	error_msg[1024];
	size_t	len;
	ssize_t	bytes_written;

	len = strlen(msg);
	strncpy(error_msg, msg, len);
	strncpy(error_msg + len, ": ", 2);
	strncpy(error_msg + len + 2, strerror(errno), 256);
	len += 2 + strlen(strerror(errno));
	strncpy(error_msg + len, "\n", 1);
	bytes_written = write(STDERR_FILENO, error_msg, len + 1);
	if (bytes_written == -1)
		return ;
	exit(EXIT_FAILURE);
}

off_t	get_file_size(int fd, size_t count, size_t *start_pos)
{
	off_t	size;

	size = lseek(fd, 0, SEEK_END);
	if (size == -1)
	{
		print_error("Error seeking file");
	}
	if ((off_t)size > (off_t)count)
	{
		*start_pos = (size_t)(size - (off_t)count);
	}
	else
	{
		*start_pos = 0;
	}
	if (lseek(fd, (off_t) * start_pos, SEEK_SET) == -1)
		print_error("Error seeking file");
	return (size);
}

void	read_and_write(int fd, size_t count)
{
	char	*buffer;
	size_t	total_written;
	ssize_t	bytes_read;
	ssize_t	bytes_written;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		print_error("Malloc failed");
	total_written = 0;
	while (total_written < count)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			print_error("Error reading file");
		if (bytes_read == 0)
			break ;
		bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
		if (bytes_written == -1)
			print_error("Error writing to stdout");
		total_written += bytes_written;
	}
	free(buffer);
}

void	tail_file(const char *filename, long long_count)
{
	int		fd;
	size_t	read_start;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Error opening file");
	get_file_size(fd, long_count, &read_start);
	read_and_write(fd, long_count);
	close(fd);
}

int	main(int argc, char *argv[])
{
	long		long_count;
	const char	*filename;

	if (argc != 4 || strcmp(argv[1], "-c") != 0)
	{
		write(STDERR_FILENO, "Usage: ft_tail -c <number> <file>\n", 37);
		exit(EXIT_FAILURE);
	}
	long_count = atol(argv[2]);
	filename = argv[3];
	tail_file(filename, long_count);
	return (EXIT_SUCCESS);
}
