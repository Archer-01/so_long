/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:33:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/15 22:51:36 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "libft.h"
# include "ft_errors.h"
# include "ft_types.h"
# include "ft_destroy.h"
# include <fcntl.h>

void	*ft_allocate(size_t count, size_t size);
int		ft_open(const char *path);
int		ft_exit(t_game *data);
void	ft_swap(char *a, char *b);
void	ft_clear_matrix(char ***matrix);

#endif