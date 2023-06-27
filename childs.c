/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otitebah <otitebah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:43:02 by otitebah          #+#    #+#             */
/*   Updated: 2023/02/17 20:22:03 by otitebah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(int fd[2], char **av, char **env)
{
	char	*get_cm;
	char	**spl;
	int		fd1;

	fd1 = open(av[1], O_RDONLY);
	if (access(av[1], R_OK) == -1)
	{
		perror(av[1]);
		exit(0);
	}
	close(fd[0]);
	dup2(fd1, 0);
	dup2(fd[1], 1);
	spl = ft_split(av[2], ' ');
	execve(av[2], spl, env);
	get_cm = get_cmd(env, spl[0]);
	execve(get_cm, spl, env);
	close(fd1);
}

void	child_process2(int fd[2], char **av, char **env)
{
	char	*get_cm;
	char	**spl;
	int		fd1;

	fd1 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC );
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(fd1, 1);
	spl = ft_split(av[3], ' ');
	execve(av[3], spl, env);
	get_cm = get_cmd(env, spl[0]);
	execve(get_cm, spl, env);
	close(fd1);
}
