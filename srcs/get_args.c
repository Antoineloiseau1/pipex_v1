/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:34:15 by antoine           #+#    #+#             */
/*   Updated: 2022/09/08 14:40:34 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

char	**get_args(char *argv)
{
	char **args;
	int	i;

	i = 0;
	while(argv[i])
	{
		args[i] = ft_split(argv, ' ');
		i++;
	}
	return (args);
}