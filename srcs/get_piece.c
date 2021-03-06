/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_piece.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 19:06:09 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:11:54 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void		ft_split(t_fillstr *vl)
{
	int i;

	i = 0;
	vl->token = ft_strnsplit(vl->otoken, vl->tokenw);
	while (i < vl->tokenl)
	{
		i++;
	}
	free(vl->otoken);
}

static void		ft_get_str(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;

	vl->otoken = (char *)malloc(sizeof(char) * (vl->tokenw * vl->tokenl) + 1);
	ft_bzero(vl->otoken, (vl->tokenw * vl->tokenl) + 1);
	i = vl->tokenl;
	while (i)
	{
		get_next_line(0, &tempvalue);
		vl->otoken = ft_strcat(vl->otoken, tempvalue);
		free(tempvalue);
		i--;
	}
}

static void		ft_get_len_wid(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;

	i = 6;
	get_next_line(0, &tempvalue);
	while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
	{
		vl->tokenl = vl->tokenl * 10 + tempvalue[i] - '0';
		i++;
	}
	i++;
	while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
	{
		vl->tokenw = vl->tokenw * 10 + tempvalue[i] - '0';
		i++;
	}
	free(tempvalue);
}

void			ft_getpiece(t_fillstr *vl)
{
	ft_get_len_wid(vl);
	ft_get_str(vl);
	ft_split(vl);
	ft_check_offset_l(vl);
	ft_check_offset_w(vl);
}
