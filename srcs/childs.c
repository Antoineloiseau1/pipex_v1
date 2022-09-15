/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:05:48 by antoine           #+#    #+#             */
/*   Updated: 2022/09/14 11:24:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1(char **paths, char *envp[], char *argv[], int fd[])
{
	int file1;
	int pid;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		free(paths);
		error(2, argv[1]);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(check_path(paths, argv[2]), ft_split(argv[2], ' '), envp);
	}
	else
		waitpid(pid, NULL, 0);	
}

void	cmd2(char **paths, char *envp[], char *argv[], int fd[], int argc)
{
	int file2;
	int	pid;

	file2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (file2 == -1)
	{
		free(paths);
		error(2, argv[4]);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		execve(check_path(paths, argv[3]), ft_split(argv[3], ' '), envp);
	}
	else
		waitpid(pid, NULL, 0);
}
