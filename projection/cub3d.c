/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/27 18:28:36 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* TODO:
// {
			Poms
// 	[✅] Fixing 3D Rendring Strips
// 	[✅] Fixing seeing between 2 walls
// 	[✅] Fixing fisheye effect
// 	[✅] Fixing keys

// 	[✅] Adding colors to wall
// 	[❌] Fixing colors between walls
// 	[❌] Adding textures

			Oussama
// 	[✅] Handling More than 2 comma in rgb
// 	[✅] Handling newlines inside the map
// 	[✅] Convert RGB color to hexadecimal
// 	[✅] Don't forget to exit if an error happend
// 	[✅] Leaks
erro color 
oerder of fiaileds
*/
// dupbicated objects
// newlines after map


int	main(int ac, char **av)
{
	// av = 0;
	t_mlx	wind;
	t_data_par *parsing;

	parsing = malloc(sizeof(t_data_par));
	ft_parsing(ac, av, parsing);
	wind.parsing = parsing;

	if (ac == 2)
	{
		wind.map = parsing->maze;
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, WIN_W, WIN_H, "Cub3D");
		images_to_xpm(&wind);
		get_player_position(&wind);
		projecting_rays(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
