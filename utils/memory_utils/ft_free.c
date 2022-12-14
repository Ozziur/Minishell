/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:25:00 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:25:00 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}
