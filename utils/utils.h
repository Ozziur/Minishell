/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:43:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/07 18:16:37 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../colors.h"

//* std libs
# include <stdlib.h>
# include <stdio.h>

//* read, write, file handling ...
# include <unistd.h>
# include <fcntl.h>

//* user defined types
# include "../types.h"

//*shell_utils
size_t	bash_next_string_len(char *str, size_t offset);
size_t	skip_consecutive_chars(char *string, size_t offset,
			char to_skip, int direction);

//* is something
t_bool			ft_isspace(char c);

//str_utils
char	*ft_strcpy(char *buf, char *src, int copy_len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *pre, char *post, t_bool free_pre, t_bool free_post);

#endif
