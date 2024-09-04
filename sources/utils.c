/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:04:44 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/03 12:27:52 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	print_error(char *error)
{
		ft_printf("Error: %s", error);
		exit(-1);
}