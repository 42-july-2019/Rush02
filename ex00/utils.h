/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:54:29 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/21 22:24:47 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BUF_SIZE 36

typedef struct	s_dict_entry
{
	char	*nb;
	char	*str;
}				t_dict_entry;

int				ft_atoi(const char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char *str, char sep);
t_dict_entry	*read_dict(char *dict_name);

#endif
