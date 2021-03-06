/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:44 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/09 22:57:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnew(char **str)
{
	(*str) = (char *)malloc(sizeof(char) * 1);
	if (*str == NULL)
	{
		free((*str));
		(*str) = NULL;
		return (-1);
	}
	(*str)[0] = 0;
	return (1);
}
