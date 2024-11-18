/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:58:33 by dgargant          #+#    #+#             */
/*   Updated: 2024/11/18 12:11:12 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*path;
	char	**splited;

	if (env == NULL)
		return (NULL);
	path = NULL;
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			path = ft_strdup(*env + 5);
			break ;
		}
		env++;
	}
	splited = ft_split(path, ':');
	free(path);
	return (splited);
}

char	*set_comand_path(char **splited_path, char *comand)
{
	int		i;
	char	*real_path;
	char	*aux_path;

	i = 0;
	if (splited_path == NULL && access(comand, 0) == 0)
		return (ft_strdup(comand));
	else if (splited_path != NULL)
	{
		while (splited_path[i])
		{
			aux_path = ft_strjoin(splited_path[i], "/");
			real_path = ft_strjoin(aux_path, comand);
			free(aux_path);
			aux_path = NULL;
			if (access(real_path, X_OK) == 0)
				return (real_path);
			free(real_path);
			real_path = NULL;
			i++;
		}
	}
	return (ft_strdup(comand));
}

void	execute_path(char **splited_arg, char *real_path, char **envp)
{
	if (real_path != NULL && access(real_path, X_OK) == 0)
	{
		execve(real_path, splited_arg, envp);
		perror(RED"Error: Failed execution"RESET);
		exit(127);
	}
	else
	{
		ft_free_array(splited_arg);
		free(real_path);
		perror(RED"zsh: comand not found"RESET);
		exit(127);
	}
}
