/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:00:17 by idouidi           #+#    #+#             */
/*   Updated: 2021/10/07 13:28:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	redirection(char *s1, char *s2, t_data *d)
{	
	d->fd_stdin = open(s1, O_RDONLY);
	d->fd_stdout = open(s2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (d->fd_stdin < 0)
		printf("pipex: %s: No such file or directory\n", s1);
	if (d->fd_stdout < 0)
		printf("pipex: %s: No such file or directory\n", s2);
	if (d->fd_stdout >= 3)
		dup2(d->fd_stdout, 1);
	if (d->fd_stdin >= 3)
		dup2(d->fd_stdin, 0);
}
