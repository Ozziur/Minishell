/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:24:51 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:24:51 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}
