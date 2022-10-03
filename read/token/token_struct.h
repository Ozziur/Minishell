/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:24:15 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 13:50:39 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_STRUCT_H
# define TOKEN_STRUCT_H

# include "../../types.h"

typedef enum e_op_code
{
	e_READ_INPUT,
	e_NEXT_TOKEN,
	e_CLEAN
}	t_op_code;

typedef enum e_token_id
{
	e_CMD_NAME,
	e_CMD_ARG,
	e_IN_FILE_TRUNC,
	e_HERE_DOC,
	e_OUT_FILE_TRUNC,
	e_OUT_FILE_APPEND,
	e_OPERATOR,
	e_ENV_VAR_DECL,
	e_ENV_VAR_UNSET,
	e_PARENTHESIS,
	e_NONE
}	t_token_id;

typedef struct s_token
{
	t_token_id		token_id;
	void			*token_val;
	void			(*to_string)(struct s_token *token);
	struct s_token	*next;
}	t_token;

#endif
