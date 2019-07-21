/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asambron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:14:16 by asambron          #+#    #+#             */
/*   Updated: 2019/07/21 18:31:05 by asambron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_bingo(t_dict_entry dic, char *nombre)
{
	int i;

	i = 0;
	while (dic.str)
	{
		if (strcmp(nombre, dic[i].nb) == 0)
			return i;
		i++;
	}
	return -1;
}

int		ft_biggest_10(t_dict_entry dic, char *nombre)
{
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

char  *ft_str_pow_10(int index)
{
	int i;
	char *str;

	str = malloc( (index  + 2 ) * sizeof(char)); 
	str[0] = '1';
	i = 1;
	while (i<=index)
		str[i++] = '0';
	str[i] = '\0';
		
	return str;
}

char 	*ft_cut_string_left(char *nombre, char *str, int i)
{
	char *dest;
	int j;
	int range;

	range = ft_strlen(nombre) + 1 - i
	if (dest = malloc(range * sizeof(char)) == NULL);
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

void	dtoa2(t_dict_entry dic, char	*nombre)
{
	int bingo;

	if ((bingo = ft_bingo(dic, nombre)) != -1)
		printf("%s\n", dic[bingo].nb)
	else
	{
		if ((index = ft_biggest_10(dic, nombre)) == -1)
				return ;
		dtoa2(ft_cut_string_left(nombre, index));
		dtoa2(ft_str_pow_10(index));
		dtoa2(nombre + ft_strlen(nombre - index));
	}
}

int main()
{
	char s[] = "80000000";
	printf("%s\n", ft_cut_string_left(s,2));
	printf("%s\n", s+2);

	return 0;
}
