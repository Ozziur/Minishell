/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:13:21 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/22 16:29:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

// * user defined types //
# include "../types.h"
# include "env_types.h"
# include "../colors.h"

// * user defined modules //
# include "../utils/ft_utils.h"
# include "env_utils/env_utils.h"

void	*env_handler(t_env_handl_opcode opcode, void *argument);

#endif
