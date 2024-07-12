/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:55:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/12 15:49:59 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	load_gun_textures(mlx_texture_t **gun_texture)
{
	gun_texture[0]
		= mlx_load_png("./assets/textures/gun_textures/shotgun1-2.png");
	gun_texture[1]
		= mlx_load_png("./assets/textures/gun_textures/shotgun2-2.png");
	gun_texture[2]
		= mlx_load_png("./assets/textures/gun_textures/shotgun3-2.png");
	gun_texture[3]
		= mlx_load_png("./assets/textures/gun_textures/shotgun4-2.png");
	gun_texture[4]
		= mlx_load_png("./assets/textures/gun_textures/shotgun5-2.png");
	if (!gun_texture[0] || !gun_texture[0] || !gun_texture[0]
		||!gun_texture[0] ||!gun_texture[0])
		return (print_error("Could not load gun textures\n"));
	return (E_OK);
}

static int	init_gun_img(t_game *game, mlx_texture_t **gun_texture)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		game->gun_img[i] = mlx_texture_to_image(game->win->mlx, gun_texture[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (game->gun_img[i] == NULL)
			return (print_error("Could not transform texture into img\n"));
		i++;
	}
	return (E_OK);
}

int	create_gun(t_game *game)
{
	if (load_gun_textures(game->gun_texture) != E_OK)
		return (E_FAIL);
	if (init_gun_img(game, game->gun_texture) != E_OK)
		return (E_FAIL);
	return (E_OK);
}

void	first_render_gun(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(game->win->mlx, game->gun_img[i],
			WIN_WIDTH / 2 - 100, WIN_HEIGHT - 360);
		if (i != 0)
			game->gun_img[i]->enabled = false;
		i++;
	}
}

void	shoot(t_game *game, long long *i, long long *click_frame)
{
	if (*i == 5)
	{
		game->gun_img[1]->enabled = false;
		game->gun_img[2]->enabled = true;
	}
	if (*i == 10)
	{
		game->gun_img[2]->enabled = false;
		game->gun_img[3]->enabled = true;
	}
	if (*i == 15)
	{
		game->gun_img[3]->enabled = false;
		game->gun_img[4]->enabled = true;
	}
	if (*i == 20)
	{
		game->gun_img[4]->enabled = false;
		game->gun_img[0]->enabled = true;
		*i = -1;
		*click_frame = -1;
	}
}
