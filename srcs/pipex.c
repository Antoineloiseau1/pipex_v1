/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:46:38 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/15 15:04:06 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	char	*path[2];
	int		fd[2];

	if (argc != 5)
		ft_exit();
	paths = get_paths(envp);
	if (paths == NULL)
		error("command not found\n");
	path[0] = check_path(paths, argv[2]);
	path[1] = check_path(paths, argv[3]);
	pipe(fd);
	if (path[0])
		cmd1(path[0], envp, argv, fd);
	close(fd[1]);
	cmd2(path[1], envp, argv, fd);
	close(fd[0]);
	free_paths(paths);
	return (0);
}
