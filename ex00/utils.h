/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:54:29 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/20 14:05:12 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BUF_SIZE 36

typedef struct	s_dict_entry
{
	int		nb;
	char	*str;
}				t_dict_entry;

t_dict_entry	*read_dict(char *dict_name);

#endif
