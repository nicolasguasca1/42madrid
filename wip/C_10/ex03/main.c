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

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include "hex_functions.h"

#define BUFFER_SIZE 16

void ft_hexdump_rec(int fd, unsigned char *buf, int offset) {
	ssize_t bytes_read = read(fd, buf, BUFFER_SIZE);

	if (bytes_read <= 0) {
		close(fd);
		return;
	}

	print_hex_ascii_line(buf, bytes_read, offset);
	ft_hexdump_rec(fd, buf, offset + bytes_read);
}

void ft_hexdump(char *filename) {
	int fd;
	unsigned char buf[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		char errmsg[256];
		strncpy(errmsg, "Error opening file ", 20);
		strncat(errmsg, filename, 235);
		perror(errmsg);
		return;
	}

	ft_hexdump_rec(fd, buf, 0);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		char usage[64];
		strncpy(usage, "Usage: ", 7);
		strncat(usage, basename(argv[0]), 56);
		perror(argc < 2);
		return 1;
	}

	ft_hexdump(argv[1]);
	return 0;
}
