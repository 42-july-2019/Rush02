/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:52:03 by exam              #+#    #+#             */
/*   Updated: 2019/07/20 16:51:31 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		get_nb_words(char *str)
{
	int result;

	result = 0;
	while (*str)
	{
		if (!is_separator(*str))
			result++;
		while (*str && !is_separator(*str))
			str++;
		while (*str && is_separator(*str))
			str++;
	}
	return (result);
}

int		add_str_to_array(char **array, char *str, int nb_word, int length)
{
	int		i;

	if (length != 0)
	{
		if (!(array[nb_word - 1] =
					((char *)malloc(sizeof(char) * length + 1))))
			return (0);
		array[nb_word - 1][length] = '\0';
	}
	i = 0;
	while (i < length)
	{
		array[nb_word - 1][i] = str[i];
		i++;
	}
	return (1);
}

int		write_str(char **array, char *str)
{
	int nb_word;
	int length;

	nb_word = 0;
	while (*str)
	{
		length = 0;
		if (!is_separator(*str))
		{
			nb_word++;
		}
		while (str[length] && !is_separator(str[length]))
			length++;
		if (!add_str_to_array(array, str, nb_word, length))
			return (0);
		str = str + length;
		while (*str && is_separator(*str))
			str++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	int		nb_words;
	char	**array;

	nb_words = get_nb_words(str);
	if (!(array = (char **)malloc(sizeof(char *) * nb_words + 1)))
		return (0);
	array[nb_words] = 0;
	if (!write_str(array, str))
		return (0);
	return (array);
}
