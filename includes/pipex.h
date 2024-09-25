/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:45:22 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/25 10:59:50 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

# define FD_RD 0
# define FD_WR 1

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

int	main(int argc, char **argv, char **envp);

char	**get_path(char **env);

void	print_error(char *error);

char *set_comand_path(char **splited_path, char *comand);

void	execute_path(char **splited_arg, char *real_path, char **envp);

void	child_proc_one(int *pipe_fd, char **argv, char **envp);

void	child_proc_two(int *pipe_fd, char **argv, char **envp);

void	parent_proc(char **argv,int *pipe_fd ,char **envp, int status);

#endif