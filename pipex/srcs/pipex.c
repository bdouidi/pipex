/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:49:40 by idouidi           #+#    #+#             */
/*   Updated: 2021/10/07 16:33:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex(char **s, t_data *d, char **envp)
{
	d->fd_stdin = 0;
	d->fd_stdout = 1;
	redirection(s[0], s[3], d);
	exec_pipex(s, d, envp);
}
