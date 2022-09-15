/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:05:48 by antoine           #+#    #+#             */
/*   Updated: 2022/09/15 18:09:41 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1(char **paths, char *envp[], char *argv[], int fd[])
{
	int		file1;
	int		pid;
	char	*path;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(argv[1]);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		path = check_path(paths, argv[2]);
		if (path == NULL)
			exit(1);
		execve(path, ft_split(argv[2], ' '), envp);
	}
	else
		waitpid(pid, NULL, 0);
}

void	cmd2(char **paths, char *envp[], char *argv[], int fd[])
{
	int		file2;
	int		pid;
	char	*path;

	file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (file2 == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		path = check_path(paths, argv[3]);
		if (path == NULL)
			exit(1);
		execve(path, ft_split(argv[3], ' '), envp);
	}
	else
		waitpid(pid, NULL, 0);
}
