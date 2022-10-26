/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:14:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/26 16:49:26 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINDING_UTILS_H
# define BINDING_UTILS_H

# include "../env.h"

void		*ft_malloc(size_t size);
void		free_env(t_bindings *head);
t_bindings	*get_new_binding(char *var_name, char *var_val, t_bool concat);
void		copy_env(char **envp);

#endif
