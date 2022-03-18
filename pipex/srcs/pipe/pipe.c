/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:08:35 by idouidi           #+#    #+#             */
/*   Updated: 2021/10/08 16:55:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	is_son(t_data *d, int i, int fd[2], char **envp)
{
	if ((d->fd_stdin < 0 && i == 0) || (d->fd_stdout < 0 && i == 1))
		exit (EXIT_FAILURE);
	if (i == 0 && d->fd_stdin >= 3)
		dup2(d->fdd, d->fd_stdin);
	else
		dup2(d->fdd, 0);
	if (i == 1)
		dup2(fd[1], d->fd_stdout);
	else
		dup2(fd[1], 1);
	close(fd[0]);
	file_exist(&d->pipe[i][0], d);
	execve(d->pipe[i][0], d->pipe[i], envp);
	exit (127);
}

void	is_father(t_data *d, int i, int fd[2])
{
	waitpid(d->pid, &(d->status), 0);
	close(fd[1]);
	if (WIFEXITED(d->status) != 0)
	{
		if (WEXITSTATUS(d->status) == 1)
			d->status = 1;
		else
			d->status = (WEXITSTATUS(d->status));
	}
	if (i != 0 && d->fd_stdin >= 3)
	{
		close(d->fd_stdin);
		d->fd_stdin = 0;
	}
	d->fdd = fd[0];
}

void	exec_pipex(char **s, t_data *d, char **envp)
{
	int		fd[2];
	int		i;

	i = 0;
	d->status = 0;
	d->pid = 0;
	d->fdd = 0;
	d->pipe = split_each_cmd_btwn_pipe(s[1], s[2]);
	while (d->pipe[i])
	{
		pipe(fd);
		d->pid = fork();
		if (d->pid < 0)
		{
			perror("fork error");
			clean_memory(d);
			exit(EXIT_FAILURE);
		}
		else if (d->pid == 0)
			is_son(d, i, fd, envp);
		else
			is_father(d, i, fd);
		i += 1;
	}
	clean_memory(d);
}
