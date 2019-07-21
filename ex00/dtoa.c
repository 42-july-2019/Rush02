/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asambron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:55:46 by asambron          #+#    #+#             */
/*   Updated: 2019/07/21 14:25:58 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_digit_to_a(t_dict_entry *dic, int clef, int *erreur)
{
	int ft_search(t_dict_entry *dic, int clef, int *erreur);
	int i;

	i = ft_search(dic, clef, erreur);
	if (i == -1)
		return ("\0");
	return (dic[i].str);
}

int		ft_pow_10(int taille)
{
	int n;
	int i;

	n = 1;
	i = 0;
	while (i < taille)
	{
		n *= 10;
		i++;
	}
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while ((dest[i++] = src[j++]) != '\0')
		;
	return (dest);
}

int		ft_search(t_dict_entry *dic, int clef, int *erreur)
{
	int i;

	i = 0;
	while (i < 50)
	{
		if (clef == dic[i].nb)
			return (i);
		i++;
	}
	*erreur = 1;
	return (-1);
}

char	*ft_itoa(char *chaine, t_dict_entry *dic, char *nombre)
{
	int t_n;
	int i;
	int erreur[1];

	erreur[0] = 0;
	t_n = ft_strlen(nombre);
	i = 0;
	while (i < t_n)
	{
		ft_strcat(chaine, ft_digit_to_a(dic, ft_pow_10(t_n - 1 - i) * (nombre[i] - '0'), erreur));
		if (erreur[0] == 1)
			return ("\0");
		ft_strcat(chaine, " ");
		i++;
	}
	return (chaine);
}
