/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:46:38 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/15 18:10:51 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	int		fd[2];

	if (argc != 5)
		ft_exit();
	paths = get_paths(envp);
	pipe(fd);
	cmd1(paths, envp, argv, fd);
	close(fd[1]);
	cmd2(paths, envp, argv, fd);
	close(fd[0]);
	free_paths(paths);
	return (0);
}
