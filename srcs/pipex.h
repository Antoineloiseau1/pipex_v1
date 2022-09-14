/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:57 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/14 11:18:03 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>

// typedef struct 	s_data
// {
// 	char	**paths;
// 	int		files[2];
// 	int		fd[2];
// 	char	**args;
// 	int		pid[2];
// }				t_data;


char	**get_paths(char **envp);
char	*check_path(char **paths, char *cmd);
char	**get_args(char *cmd);
void	error(int errnum, char *arg);
void	cmd1(char **paths, char *envp[], char *argv[], int fd[]);
void	cmd2(char **paths, char *envp[], char *argv[], int fd[], int argc);
void	ft_exit(void);

#endif