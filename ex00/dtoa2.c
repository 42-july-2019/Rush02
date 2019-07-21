/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asambron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:14:16 by asambron          #+#    #+#             */
/*   Updated: 2019/07/21 19:11:02 by asambron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_bingo(t_dict_entry *dic, char *nombre)
{
	int i;

	i = 0;
	while (dic->str)
	{
		if (strcmp(nombre, dic[i].nb) == 0)
			return i;
		i++;
	}
	return -1;
}
int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

int		ft_biggest_10(t_dict_entry *dic, char *nombre)
{
	char  *ft_str_pow_10(int ind);
	int i;

	while (nombre[i])
		i++;
	while (i > 0)
	{
		if (ft_bingo(dic, ft_str_pow_10(i)) != -1)
			return i;
	}
	return -1;
}

char  *ft_str_pow_10(int ind)
{
	int i;
	char *str;

	str = malloc( (ind  + 2 ) * sizeof(char)); 
	str[0] = '1';
	i = 1;
	while (i<=ind)
		str[i++] = '0';
	str[i] = '\0';
		
	return str;
}

char 	*ft_cut_string_left(char *nombre, int i)
{
	char *dest;
	int j;
	int range;

	range = ft_strlen(nombre) + 1 - i;
	if ((dest = malloc(range * sizeof(char))) == NULL)
		return 0;
	j = 0;
	while (j < i)
	{
	   dest[j] = nombre[j];
	   j++;
	}
	dest[j] = '\0';
	return dest;
}

void	dtoa2(t_dict_entry *dic, char	*nombre)
{
	int bingo;
	int ind;

	if ((bingo = ft_bingo(dic, nombre)) != -1)
		printf("%s\n", dic[bingo].nb);
	else
	{
		if ((ind = ft_biggest_10(dic, nombre)) == -1)
				return ;
		dtoa2(dic, ft_cut_string_left(nombre, ind));
		dtoa2(dic, ft_str_pow_10(ind));
		dtoa2(dic, nombre + ft_strlen(nombre) - ind);
	}
}

int main()
{
	char *s = ft_str_pow_10(6);
	//printf("%s\n", ft_cut_string_left(s,2));
	printf("%s\n", s);

	return 0;
}
