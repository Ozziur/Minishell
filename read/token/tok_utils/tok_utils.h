/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:01:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 16:06:25 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_UTILS_H
# define TOK_UTILS_H

# include <unistd.h>
# include "../../../colors.h"
# include "../../../utils/utils.h"
# include "../token_struct.h"
# include "../../../types.h"
// # include "../../../global.h"
// # include "../../../env/env_utils/env_utils.h"

//tok_mem_utils
void	tok_add_back(t_token **token_list, t_token *token);


#endif