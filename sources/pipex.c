/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:47:31 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/03 12:31:49 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//void	child_proces()
//{
//	
//}


int	main(int argc, char **argv, char **envp)
{
	// int	fd[2];
	// pid_t pid;
	int i = 0;
	if (argc == 1)
	{
		printf("%s\n \n", argv[0]);
	}
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}