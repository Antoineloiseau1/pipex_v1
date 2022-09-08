/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:29:17 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/08 13:16:29 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	**get_paths(char **envp)
{
	char	*env_path;
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		tmp = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (tmp)
			env_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	paths = ft_split(env_path, ':');
	free(env_path);
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}
