/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:46:38 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/13 19:18:58 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	int 	file1; 
	int 	file2;
	int		fd[2];
	char 	**args;
	int		pid1;
	int		pid2;
	
	if (argc != 5)
		return (1);
	

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		error(2, argv[1]);
	file2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (file2 == -1)
		error(2, argv[4]);
	paths  = get_paths(envp);
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		args = ft_split(argv[2], ' ');
		close(fd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(check_path(paths, argv[2]), args, envp);
	}
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	pid2 = fork();
	if (pid2 == 0)
	{
 		args = ft_split(argv[3], ' ');
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		execve(check_path(paths, argv[3]), args, envp);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	close(fd[0]);
	free(paths);
	close(file1);
	close(file2);
	return (0);
}