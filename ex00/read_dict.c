/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:13:51 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/21 16:09:35 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "utils.h"

int				open_dict_data(char **dict_data, char *dict_name, int *dict_ref)
{
	int				size_read;
	int				nb_times_read;
	char			read_data[BUF_SIZE + 1];

	*dict_ref = open(dict_name, O_RDONLY);
	if (*dict_ref == -1)
		return (0);
	nb_times_read = 0;
	while ((size_read = read(*dict_ref, read_data, BUF_SIZE)))
		nb_times_read++;
	if (!(*dict_data =
				((char *)malloc(sizeof(char) *
					(BUF_SIZE * nb_times_read + 1)))))
		return (0);
	*dict_ref = open(dict_name, O_RDONLY);
	if (*dict_ref == -1)
		return (0);
	return (1);
}

void			get_dict_data(char *dict_full_data, int dict_ref)
{
	int		i;
	int		size_read;
	int		total_size_read;
	char	read_data[BUF_SIZE + 1];

	total_size_read = 0;
	while ((size_read = read(dict_ref, read_data, BUF_SIZE)))
	{
		i = 0;
		read_data[size_read] = '\0';
		while (i < size_read)
		{
			dict_full_data[total_size_read + i] = read_data[i];
			i++;
		}
		total_size_read += size_read;
	}
	dict_full_data[total_size_read] = '\0';
}

int				set_dict_entry_el(t_dict_entry *element, char **strs)
{
	int		start;
	int		length;
	int		j;
	char	*curr_str;

	element->nb = strs[0];
	start = 0;
	while (strs[1][start] == ' ' || strs[1][start] == '\t')
		start++;
	length = 0;
	while (strs[1][start + length])
		length++;
	if (!(curr_str =
				((char *)malloc(sizeof(char) * length + 1))))
		return (0);
	j = 0;
	while (j < length)
	{
		curr_str[j] = strs[1][start + j];
		j++;
	}
	curr_str[j] = '\0';
	element->str = curr_str;
	return (1);
}

int				format_dict_data(t_dict_entry **array, char **dict_array)
{
	int				i;
	int				length;
	char			**curr_strs;

	length = 0;
	while (dict_array[length] != 0)
		length++;
	if (!(*array =
				((t_dict_entry *)malloc(sizeof(t_dict_entry) * length + 1))))
		return (0);
	i = 0;
	while (i < length)
	{
		curr_strs = ft_split(dict_array[i], ':');
		if (!set_dict_entry_el(&(*array)[i], curr_strs))
			return (0);
		curr_strs = 0;
		i++;
	}
	array[i]->str = "";
	return (1);
}

t_dict_entry	*read_dict(char *dict_name)
{
	int				dict_ref;
	char			*dict_full_data;
	char			**dict_array_data;
	t_dict_entry	*array;

//	int	i;
	open_dict_data(&dict_full_data, dict_name, &dict_ref);
	if (dict_ref == -1)
		return (0);
	get_dict_data(dict_full_data, dict_ref);
	if (!(dict_array_data = ft_split(dict_full_data, '\n')))
		return (0);
	if (!format_dict_data(&array, dict_array_data))
		return (0);
//	i = 0;
//	while (array[i].str)
//	{
//		printf("%s : %s, ", array[i].nb, array[i].str);
//		i++;
//	}
	free(dict_full_data);
	dict_full_data = 0;
	free(dict_array_data);
	dict_array_data = 0;
	if (!close(dict_ref))
		return (0);
	return (array);
}
