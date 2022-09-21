/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:43:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/21 16:43:19 by mruizzo          ###   ########.fr       */
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


//str_utils
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *pre, char *post, t_bool free_pre, t_bool free_post);

#endif