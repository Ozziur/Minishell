/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:52:33 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/07 18:38:00 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_status
{
	ERROR,
	OK
}	t_status;

typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;

#endif