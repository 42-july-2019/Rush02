/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:13:51 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/20 17:00:59 by alabreui         ###   ########.fr       */
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
	printf("%d\n", *dict_ref);
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
	printf("%d\n", *dict_ref);
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

t_dict_entry	*read_dict(char *dict_name)
{
	int				dict_ref;
	char			*dict_full_data;
	char			**dict_array_data;
	t_dict_entry	*array;

	array = 0;
	open_dict_data(&dict_full_data, dict_name, &dict_ref);
	if (dict_ref == -1)
		return (0);
	get_dict_data(dict_full_data, dict_ref);
	printf("%s\n", dict_full_data);
	dict_array_data = ft_split(dict_full_data, '\n');
	while (*dict_array_data)
	{
		printf("%s, ", *dict_array_data);
		dict_array_data++;
	}
	if (!close(dict_ref))
		return (0);
	return (array);
}
