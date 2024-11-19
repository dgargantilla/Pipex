/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:47:31 by dgargant          #+#    #+#             */
/*   Updated: 2024/11/19 11:28:06 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc_one(int *pipe_fd, char **argv, char **envp)
{
	char	**paths;
	char	**splited_argv;
	char	*real_path;
	int		fd;

	paths = get_path(envp);
	splited_argv = ft_split(argv[2], ' ');
	real_path = set_comand_path(paths, splited_argv[0]);
	ft_free_array(paths);
	close(pipe_fd[FD_RD]);
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		close(pipe_fd[FD_WR]);
		perror(RED"Error: Open error"RESET);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipe_fd[FD_WR], STDOUT_FILENO);
	close(pipe_fd[FD_WR]);
	execute_path(splited_argv, real_path, envp);
}

void	child_proc_two(int *pipe_fd, char **argv, char **envp)
{
	char	**paths;
	char	**splited_argv;
	char	*real_path;
	int		fd;

	paths = get_path(envp);
	splited_argv = ft_split(argv[3], ' ');
	real_path = set_comand_path(paths, splited_argv[0]);
	ft_free_array(paths);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		close(pipe_fd[FD_RD]);
		perror(RED"Error: Open error"RESET);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pipe_fd[FD_RD], STDIN_FILENO);
	close(pipe_fd[FD_RD]);
	execute_path(splited_argv, real_path, envp);
}

void	parent_proc(char **argv, int *pipe_fd, char **envp, int status)
{
	pid_t	pid_one;
	pid_t	pid_two;

	pid_one = fork();
	if (pid_one == -1)
		exit(-1);
	else if (pid_one == 0)
		child_proc_one(pipe_fd, argv, envp);
	else if (pid_one > 0)
	{
		pid_two = fork();
		close(pipe_fd[FD_WR]);
		if (pid_two == -1)
			exit(-1);
		else if (pid_two == 0)
			child_proc_two(pipe_fd, argv, envp);
		else if (pid_two > 0)
		{
			close(pipe_fd[FD_RD]);
			waitpid(pid_one, &status, 0);
			waitpid(pid_two, &status, 0);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		status;

	status = 0;
	if (argc != 5)
		perror(RED"Error: The number of arguments is invalid"RESET);
	else if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			exit(-1);
		parent_proc(argv, pipe_fd, envp, status);
	}
	return (status);
}
