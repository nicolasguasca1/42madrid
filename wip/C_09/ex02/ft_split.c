/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguasca <nguasca@student.42madrid.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:07:37 by nguasca           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:37 by nguasca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			count++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	return (count);
}

char	**allocate_memory(int word_count)
{
	char	**result;

	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

char	*extract_word(char *str, char *charset, int *length)
{
	int	len;
	char	*start;
	char	*word;
	int	i;

	len = 0;
	start = str;
	while (*str && !is_separator(*str, charset))
	{
		len++;
		str++;
	}
	*length = len;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_count;
	int		word_len;
	char	**result;

	word_count = count_words(str, charset);
	result = allocate_memory(word_count);
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			result[i] = extract_word(str, charset, &word_len);
			if (!result[i])
				return (NULL);
			str += word_len;
			i++;
		}
	}
	result[i] = 0;
	return (result);
}
