/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:23:31 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/29 17:50:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*quote(char *str, t_bool free)
{
	return (ft_strjoin(ft_strjoin("\"", str, e_false, free),
				"\"", e_true, e_false));
}

char	*single_quote(char *str, t_bool free)
{
	return (ft_strjoin(ft_strjoin("\'", str, e_false, free),
				"\'", e_true, e_false));
}
