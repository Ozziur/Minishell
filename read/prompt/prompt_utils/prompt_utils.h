/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:10:18 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 18:03:37 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_UTILS_H
# define PROMPT_UTILS_H

// * standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>

// * libraries
# include "../../../global.h"

char	*my_readline(char *prompt);

#endif