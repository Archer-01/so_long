/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:04:46 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/20 16:38:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HOOKS_H
# define FT_HOOKS_H

# include "ft_types.h"
# include "ft_utils.h"
# include "ft_move.h"
# include "ft_enemy.h"
# include <mlx.h>
# include "ft_animations.h"

# define ON_WIN_CLOSE 17
# define ON_KEY_PRESS 2
# define ON_KEY_RELEASE 3

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

void	ft_install_hooks(t_game *data);

#endif