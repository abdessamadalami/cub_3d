/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:33:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/26 22:21:27 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"

void error_line()
{
	system("leaks cub3d");
	printf(" error line [<>!<>] \n");
	exit(1);
}

void error_map()
{
	system("leaks cub3d");
	printf(" error map [<>!<>] \n");
	exit(1);
}
void error_player()
{
	system("leaks cub3d");
	printf(" error player [<>!<>] \n");
	exit(1);
}

void error_color()
{
	system("leaks cub3d");
	printf(" error color [<>!<>] \n");
	exit(1);
}