/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/25 15:06:28 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: %s <map>\n", argv[0]);
    return (E_FAIL);
  }
	printf("Init game\n");
	if (!start_game(argv[1]))
		return (E_FAIL);
	printf("Finish game\n");
	return (E_OK);
}