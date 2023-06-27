/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otitebah <otitebah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:49:09 by otitebah          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:50 by otitebah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path(char **env)
{
	while (ft_strncmp("PATH=", *env, 5))
			env++;
	return(ft_split((*env + 5), ':'));
}

void	ft_error(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2 , 2);
	exit (0);
}

char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, X_OK) != -1)
			return(free(tmp), free(command), command);
		free(tmp);
		free(command);
		i++;
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	int fd[2];
	int f1;
	int f2;

	if (ac != 5)
	{
		write (2, "Error: too many arguments!\n", 28);
		exit(0);
	}
	if (pipe(fd) == -1)
		perror("pipe");
	env = path(env);
	f1 = fork();
	if (f1 == 0)
	{
		child_process1(fd, av, env);
		ft_error("Command not found : ", av[2]);
	}
	f2 = fork();
	if (f2 == 0)
	{
		child_process2(fd, av, env);
		ft_error("Command not found : ", av[3]);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(f2, 0, 0);
	waitpid(f1, 0, 0);
}
