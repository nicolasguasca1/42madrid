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

#ifndef HEX_FUNCTIONS_H
#define HEX_FUNCTIONS_H

void print_offset(int offset);
void print_hex(const unsigned char *buf, int len);
void print_ascii(const unsigned char *buf, int len);
void print_hex_ascii_line(const unsigned char *buf, int len, int offset);

#endif // HEX_FUNCTIONS_H
