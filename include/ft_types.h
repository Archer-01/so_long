/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:48:14 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/21 15:31:12 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_animation
{
	int		frame_count;
	int		duration;
	void	**frames;
}	t_animation;

typedef struct s_player_imgs
{
	t_animation	*idle_left;
	t_animation	*idle_right;
	t_animation	*idle_up;
	t_animation	*idle_down;
	t_animation	*left;
	t_animation	*right;
	t_animation	*up;
	t_animation	*down;
}	t_player_imgs;

typedef struct s_enemy
{
	int		i;
	int		j;
	char	type;
	int		curr_direction;
}	t_enemy;

typedef struct s_map
{
	t_mlx			*mlx;
	t_player_imgs	*player_imgs;
	void			*collectible;
	void			*empty;
	void			*enemy;
	void			*exit;
	void			*wall;
	int				width;
	int				height;
	int				collect_count;
	int				player_i;
	int				player_j;
	char			**map;
	int				p_collect;
	int				player_moves;
	int				enemy_count;
	t_enemy			*enemies;
	char			*player_direction;
}	t_game;

#endif