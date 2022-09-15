/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:49:47 by antoine           #+#    #+#             */
/*   Updated: 2022/09/15 14:31:30 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(void)
{
	ft_putstr_fd("pipex: usage: infile \"cmd1\" \"cmd2\" outfile""\n", 2);
	exit(EXIT_FAILURE);
}

void	error(char *arg)
{
	ft_putstr_fd("pipex: ", 2);
	perror(arg);
	exit(errno);
}
