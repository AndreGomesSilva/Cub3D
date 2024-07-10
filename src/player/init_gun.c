/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:55:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/10 12:07:00 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_gun_textures(mlx_texture_t **gun_texture)
{
	gun_texture[0]
		= mlx_load_png("./assets/textures/gun_textures/shotgun1.png");
	gun_texture[1]
		= mlx_load_png("./assets/textures/gun_textures/shotgun2.png");
	gun_texture[2]
		= mlx_load_png("./assets/textures/gun_textures/shotgun3.png");
	gun_texture[3]
		= mlx_load_png("./assets/textures/gun_textures/shotgun4.png");
	gun_texture[4]
		= mlx_load_png("./assets/textures/gun_textures/shotgun5.png");
	if (!gun_texture[0] || !gun_texture[0] || !gun_texture[0]
		||!gun_texture[0] ||!gun_texture[0])
		return (print_error("Could not load gun textures\n"));
	return (E_OK);
}
