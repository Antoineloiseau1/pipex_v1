/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:09:07 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/09 17:49:42 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*check_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	int		is_access;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], ft_strcut(cmd, ' '));
		is_access = access(cmd_path, X_OK | F_OK);
		if (is_access == 0)
			return (cmd_path);
		i++;
	}
	free(cmd_path);
	free(paths);
	exit(5);
}
