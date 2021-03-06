/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_wall.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 09:56:25 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 17:42:02 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		calc_and_go_wall_c(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int temp;

	temp = d;
	ft_init_offset(vl, &ti, &td);
	if (ft_check_ceiling(vl, vlc))
		return (0);
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*')
			{
				if ((i - vl->offsetl) == 0)
					if (ft_return_coor(vl, i, d))
						return (1);
			}
			td++;
		}
		td = vl->offsetw;
		d = temp;
		ti++;
	}
	return (0);
}

int		calc_and_go_wall_b(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int temp;

	temp = d;
	ft_init_offset(vl, &ti, &td);
	if (ft_check_bottom(vl, vlc))
		return (0);
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*')
			{
				if ((i + ti - vl->offsetl) == vl->fldl)
					if (ft_return_coor(vl, i, d))
						return (1);
			}
			td++;
		}
		td = vl->offsetw;
		d = temp;
		ti++;
	}
	return (0);
}

int		calc_and_go_wall_r(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int temp;

	temp = d;
	ft_init_offset(vl, &ti, &td);
	if (ft_check_rightwall(vl, vlc))
		return (0);
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*')
			{
				if ((d + td - vl->offsetw) == (vl->fldw - 1))
					if (ft_return_coor(vl, i, d))
						return (1);
			}
			td++;
		}
		td = vl->offsetw;
		d = temp;
		ti++;
	}
	return (0);
}

int		calc_and_go_wall_l(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int temp;

	temp = d;
	ft_init_offset(vl, &ti, &td);
	if (ft_check_leftwall(vl, vlc))
		return (0);
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*')
			{
				if (d == 0)
					if (ft_return_coor(vl, i, d))
						return (1);
			}
			td++;
		}
		td = vl->offsetw;
		d = temp;
		ti++;
	}
	return (0);
}

int		calc_and_go_wall(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ret;

	ret = 0;
	ret += calc_and_go_wall_r(vl, vlc, i, d);
	ret += calc_and_go_wall_l(vl, vlc, i, d);
	ret += calc_and_go_wall_c(vl, vlc, i, d);
	ret += calc_and_go_wall_b(vl, vlc, i, d);
	return (ret);
}
