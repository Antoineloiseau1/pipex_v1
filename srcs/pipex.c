/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:46:38 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/08 14:43:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	char	**paths = get_paths(envp);
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	int file2 = open(argv[4], O_CREAT | O_WRONLY, 0777);

	if (file1 == -1)
	{
		free(paths);
		return (1);
	}

	int	fd[2];
	pipe(fd);
	int pid1 = fork();
	if (pid1 == 0)
	{
		//child process (first program)
		close(fd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(check_path(paths, argv[2]), argv, envp);
	}
	int	pid2 = fork();
	if (pid2 == 0)
	{
	//  	// child process of second program
		dup2(fd[0], fd[1]);
		dup2(file2, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(check_path(paths, argv[3]), argv, envp);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	free(paths);
	close(file1);
	close(file2);
	return (0);
}