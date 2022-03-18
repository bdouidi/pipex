/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:20:05 by idouidi           #+#    #+#             */
/*   Updated: 2021/10/08 12:28:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	***split_each_cmd_btwn_pipe(char *s1, char *s2)
{
	char	***tab;

	tab = malloc(sizeof(char **) * (2 + 1));
	if (tab == NULL)
		return (NULL);
	tab[0] = ft_split(s1, " ");
	tab[1] = ft_split(s2, " ");
	tab[2] = NULL;
	return (tab);
}

void	free_list(t_data *d)
{
	t_env	*tmp;

	tmp = NULL;
	while (d->head)
	{
		tmp = d->head;
		ft_leak(d->head->name);
		ft_leak(d->head->value);
		d->head = d->head->next;
		free(tmp);
	}
}

void	clean_memory(t_data *d)
{
	d->pipe = ft_leak_3(d->pipe);
	close(d->fd_stdout);
	close (d->fd_stdin);
	free_list(d);
}
