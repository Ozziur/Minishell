/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:45:07 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/07 11:10:52 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	ft_atoi(char *str)
{
	int	i;
	long long result;

	result = 0;
	i = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	if (result > 2147483647 || result < -2147483648)
	{
		printf("\nATOI_ERROR!\n");
		exit(1);
	}
	return ((int)result);
}

char	*ft_itoa(int nbr)
{
	char	digit[2];

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
		return (ft_strjoin("-", ft_itoa(-nbr), e_false, e_true));
	digit[0] = (nbr % 10) + '0';
	digit[1] = 0;
	if (nbr < 10)
	   return (ft_strdup(digit));
	return (ft_strjoin(ft_itoa(nbr / 10), digit, e_true, e_false));
}	
