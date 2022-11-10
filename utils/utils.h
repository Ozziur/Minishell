/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:43:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/25 18:24:36 by ccantale         ###   ########.fr       */
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

//*sub
# include "easy_pf/ft_printf.h"

//*shell_utils
size_t	bash_next_string_len(char *str, size_t offset);
size_t	skip_consecutive_chars(char *string, size_t offset,
			char to_skip, int direction);
t_bool	command_is_empty(char *command);

//* error
void	set_error(t_status *status);

//* is something
t_bool	ft_isspace(char c);
t_bool	ft_is_quote(char c);
t_bool	char_is_alpha(char c);
t_bool	bash_control_character(char c);
t_bool	char_is_digit(char c);

//* str_utils
char	*ft_strcpy(char *buf, char *src, int copy_len);
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *pre, char *post, t_bool free_pre, t_bool free_post);
size_t	skip_past_char(char *str, size_t offset,
			char to_skip, int direction);
char	**ft_split(char const *string, char delimiter);
int		ft_atoi(char *str);
char	*ft_itoa(int nbr);
char	*find_substr(char *str, char *substr);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_str_replace(char **str, char *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char *str, char delimiter);

//split_utils in str_utils
void	*ft_split_clear(char **split);

//* memory_utils
void	*ft_malloc(size_t size);
void	ft_free(void *ptr);

#endif
