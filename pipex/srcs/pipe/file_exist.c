/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:12:04 by idouidi           #+#    #+#             */
/*   Updated: 2021/10/08 17:02:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*join_path_cmd(char *path, char *slash, char *cmd)
{
	char	*leak;
	char	*tmp;

	tmp = ft_strjoin(path, slash);
	leak = tmp;
	tmp = ft_strjoin(tmp, cmd);
	leak = ft_leak(leak);
	return (tmp);
}

int	set_return(char ***tab, int ret, t_data *d)
{
	*tab = ft_leak_2(*tab);
	if (ret == 127)
		ft_putstr_fd("pipex: command was not found\n", d->save_stdout);
	return (ret);
}

int	loop_check_if_file_exist(char **cmd, char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (tab[i])
	{
		tmp = join_path_cmd(tab[i], "/", *cmd);
		if (!access(tmp, F_OK))
		{
			*cmd = ft_leak(*cmd);
			*cmd = ft_strdup(tmp);
			tmp = ft_leak(tmp);
			return (0);
		}
		tmp = ft_leak(tmp);
		i += 1;
	}
	return (127);
}

char	*find_var(char *s, t_data *d)
{
	t_env	*tmp;

	tmp = d->head;
	while (tmp)
	{
		if (strcmp(s, tmp->name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	file_exist(char **s, t_data *d)
{
	char	**tab;
	int		ret;

	tab = NULL;
	ret = 127;
	if (s[0] && ft_strcmp("", s[0]) != 0)
	{
		if (s[0][0] == '/' || s[0][0] == '.')
			return ;
		tab = ft_split(find_var("PATH", d), ":");
		ret = loop_check_if_file_exist(&s[0], tab);
	}
	if (ret == 127)
	{
		write(2, "pipex: ", 7);
		write(2, s[0], ft_strlen(s[0]));
		write(2, ": command not found\n", 20);
	}
	tab = ft_leak_2(tab);
}
