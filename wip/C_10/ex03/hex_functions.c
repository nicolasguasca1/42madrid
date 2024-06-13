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

#include <unistd.h>

#define BUFFER_SIZE 16

void	print_offset_recursive(int offset, char *ptr)
{
	char	hex[9];
	static	const	char	*hex_chars;
	char	*ptr;
	int	i;

	ptr = hex;
	hex_chars = "0123456789abcdef";
	i = 28;
	while (i >= 0)
	{
		*ptr++ = hex_chars[(offset >> i) & 0xF];
		i -= 4;
	}
	*ptr = ' ';
	write(STDOUT_FILENO, hex, 9);
}

void	print_hex_recursive(const unsigned char *buf, int len, char *ptr)
{
	static	const	char	*hex_chars;

	char hex[49];
	char *ptr_hex;

	ptr_hex = hex;
	hex_chars = "0123456789abcdef";
	if (len > 0) {
		print_hex_recursive(buf + 1, len - 1, ptr);
		*ptr++ = hex_chars[*buf >> 4];
		*ptr++ = hex_chars[*buf & 0xF];
		*ptr++ = ' ';
	} else {
		*ptr++ = ' ';
		*ptr++ = ' ';
		*ptr++ = ' ';
	}

	if (len == 8) *ptr++ = ' ';
}

void	print_ascii_recursive(const unsigned char *buf, int len, char *ptr)
{
	if (len > 0)
	{
		print_ascii_recursive(buf + 1, len - 1, ptr);
		*ptr++ = (*buf >= 32 && *buf <= 126) ? *buf : '.';
	}
	else
	{
		*ptr++ = '|';
		*ptr++ = '\n';
	}
}

void	print_hex_ascii_line(const unsigned char *buf, int len, int offset)
{
	char	offset_hex[9];
	char	*ptr_offset;
	char	hex[49];
	char	*ptr_hex;

	ptr_hex = hex;
	ptr_offset = offset_hex;
	print_offset_recursive(offset, ptr_offset);
	ptr_offset += 8;
	*ptr_offset = ' ';
	write(STDOUT_FILENO, offset_hex, 9);
	print_hex_recursive(buf, len, ptr_hex);
	*ptr_hex = '|';
	write(STDOUT_FILENO, hex, 49);
	char ascii[17];
	char *ptr_ascii = ascii;
	print_ascii_recursive(buf, len, ptr_ascii);
	write(STDOUT_FILENO, ascii, 17);
}
