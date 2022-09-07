/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:46:38 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/07 13:29:50 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	char	**paths = get_paths(envp);
	int		i;

	i = 0;
	while (paths[i])
	{
		if (check_path(paths, argv[1]) == 0)
			execve(ft_strjoin(paths[i], argv[1]), argv + 1, envp);
		i++;
	}
	return (0);
}