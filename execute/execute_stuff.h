/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_stuff.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:10:46 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/17 16:19:51 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_STUFF_H
# define EXECUTE_STUFF_H

# include "execute_struct.h"
#include "../read/parser/parser_struct.h"

void	execute(t_tree_node *parse_tree);

#endif