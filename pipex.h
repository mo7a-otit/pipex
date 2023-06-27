/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otitebah <otitebah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:20:34 by otitebah          #+#    #+#             */
/*   Updated: 2023/02/17 15:43:19 by otitebah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
void	child_process1(int fd[2], char **av, char **env);
void	child_process2(int fd[2], char **av, char **env);
char	*get_cmd(char **path, char *cmd);
char    *ft_join_free(char *s1, char *s2);

#endif