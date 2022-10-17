/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:43:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 14:51:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../colors.h"

//* std libs
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

//* user defined types
# include "../types.h"

//*shell_utils
size_t	bash_next_string_len(char *str, size_t offset);
size_t	skip_consecutive_chars(char *string, size_t offset,
			char to_skip, int direction);
t_bool	command_is_empty(char *command);

//* error
void set_error(t_status *status);

//* is something
t_bool	ft_isspace(char c);
t_bool	ft_is_quote(char c);
t_bool	bash_control_character(char c);

//* str_utils
char	*ft_strcpy(char *buf, char *src, int copy_len);
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *pre, char *post, t_bool free_pre, t_bool free_post);
size_t	skip_past_char(char *str, size_t offset,
			char to_skip, int direction);
char	**ft_split(char const *string, char delimiter);

//* memory_utils
void	*ft_malloc(size_t size);
void	ft_free(void *ptr);

#endif
