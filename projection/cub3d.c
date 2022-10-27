/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/26 11:22:08 by ael-oual         ###   ########.fr       */
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
void	parse_aguments(t_mlx	*wind)
{
	printf("We Path -> %s\n", wind->west_img);
    printf("No Path -> %s\n", wind->north_img);
    printf("So Path -> %s\n", wind->south_img);
    printf("Ea Path -> %s\n", wind->east_img);
    printf("C Color -> %s\n", wind->east_img);
    printf("E Color -> %s\n", wind->east_img);
	for (int i = 0; wind->map[i];i++)
	{
    	printf("Map -> %s\n", wind->map[i]);
	}
}

int	main(int ac, char **av)
{
	// av = 0;
	t_mlx	wind;
	t_data_par *parsing;

	parsing = malloc(sizeof(t_data_par));
	printf("omaut");
	printf(" %s " ,av[1]);
	ft_parsing(ac, av, parsing);
	print_data(parsing);
	system("leaks cub3d");
	
	exit(0);
	if (ac == 2)
	{
		wind.map = wind.parsing.maze;
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
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
