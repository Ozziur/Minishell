/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:14:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/07 14:55:51 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINDING_UTILS_H
# define BINDING_UTILS_H

# include "../env.h"

void		*ft_malloc(size_t size);
void		free_env(t_bindings *head);
t_bindings	*get_new_binding(char *var_name, char *var_val, t_bool concat);
void		copy_env(char **envp);
char		*binding_get_value(t_bindings *head, char *name);
t_bool		binding_exist(t_bindings *head, t_bindings *binding);
size_t		bindings_len(t_bindings *head);
t_bindings	*binding_over_write(t_bindings *head, t_bindings *binding);

#endif
