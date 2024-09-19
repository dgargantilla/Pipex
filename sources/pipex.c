/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:47:31 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/19 09:48:25 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//void	first_child_proces()
//{
//	
//}


int	main(int argc, char **argv, char **envp)
{
	// int	fd[2];
	// pid_t pid;
	//int i = 0;
	char **paths;
	char *real_path;
	char **splited_argv;

	if (argc != 2)
		print_error("The number of arguments is invalid");
	else if (!*envp)
		print_error("Environment variables not found");
	else
	{
		paths = get_path(envp);
		for(int i = 0; paths[i] != NULL ;i++)
			ft_printf("%s\n", paths[i]);
		ft_printf(GREEN"\n---------------------PATH---------------\n\n"RESET);
		splited_argv = ft_split(argv[1], ' ');
		real_path = set_comand_path(paths, splited_argv[0]);
		ft_printf("%s\n", real_path);
		execute_path(splited_argv, real_path, envp);
		ft_free_array(splited_argv);
		ft_free_array(paths);
		free(real_path);
	}
	return (0);
}
