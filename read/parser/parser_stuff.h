/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stuff.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:34:31 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/07 18:35:07 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STUFF_H
# define PARSER_STUFF_H

# include "parser_struct.h"

t_tree_node	*parse(void);
void		free_tree(t_tree_node **root_ref);

#endif
