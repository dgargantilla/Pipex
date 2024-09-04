/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:58:33 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/03 09:22:45 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*path;

	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			path = ft_strdup(*env + 5);
			break;
		}	
		env++;
	}
	return (ft_split(path, ':'));
}

