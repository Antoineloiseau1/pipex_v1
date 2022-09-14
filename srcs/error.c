/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:49:47 by antoine           #+#    #+#             */
/*   Updated: 2022/09/14 11:04:30 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(void)
{
	ft_putstr_fd("pipex: usage: infile \"cmd1\" \"cmd2\" outfile""\n", 2);
	exit(EXIT_FAILURE);
}

void	error(int errnum, char *arg)
{
	perror(arg);
	exit(errnum);
}