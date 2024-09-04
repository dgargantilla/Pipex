/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:37:52 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/03 12:18:36 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int n)
{
	unsigned int	res;
	int				result;

	result = 0;
	res = n % 10;
	if (n > 9)
		result += ft_putunbr(n / 10);
	res += 48;
	result += write(1, &res, 1);
	return (result);
}
