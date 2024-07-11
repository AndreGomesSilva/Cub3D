/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/11 18:53:23 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Wrong number of arguments\n"));
	printf("Init game\n");
	if (start_game(argv[1]) != E_OK)
		return (print_error("Could not start game\n"));
	printf("Finish game\n");
	printf("SERA???? game\n");
	return (E_OK);
}
