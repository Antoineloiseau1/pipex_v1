/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:29:17 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/15 18:11:23 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_for_path(char **envp)
{
	char	*env_path;
	int		i;
	char	*tmp;

	env_path = NULL;
	i = 0;
	while (envp[i])
	{	
		tmp = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (tmp)
			return (env_path = ft_substr(envp[i], 5, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

char	**get_paths(char **envp)
{
	char	*env_path;
	char	**paths;
	char	*tmp;
	int		i;

	env_path = search_for_path(envp);
	if (env_path == NULL)
		error("path not found");
	paths = ft_split(env_path, ':');
	free(env_path);
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
	return (paths);
}
