/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:54:29 by alabreui          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/21 15:45:40 by asambron         ###   ########.fr       */
=======
/*   Updated: 2019/07/21 16:08:28 by alabreui         ###   ########.fr       */
>>>>>>> 287d161b4da9d10fbe0b544ed66009c532f8466f
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
char			**ft_split(char *str, char sep);
t_dict_entry	*read_dict(char *dict_name);

#endif
