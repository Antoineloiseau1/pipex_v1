/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:57 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/15 14:42:11 by anloisea         ###   ########.fr       */
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

char	**get_paths(char **envp);
char	*check_path(char **paths, char *cmd);
char	**get_args(char *cmd);
void	error(char *arg);
void	cmd1(char *path, char *envp[], char *argv[], int fd[]);
void	cmd2(char *path, char *envp[], char *argv[], int fd[]);
void	ft_exit(void);
void	free_paths(char **paths);
char	*search_for_path(char **envp);

#endif