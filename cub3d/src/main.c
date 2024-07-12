/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 13:06:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Wrong number of arguments\n"));
	if (start_game(argv[1]) != E_OK)
	{
		printf("Could not start game\n");
		return (E_FAIL);
	}
	return (E_OK);
}
