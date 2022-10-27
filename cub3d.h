/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:50 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/19 16:37:21 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
// # include "./get_next_line/get_next_line.h"

# include "./map_parssing/includ/map_parssing.h"

# define TRUE 1

# define RED	0XFF0000
# define WHITE	0XFFFFFF
# define BLACK	0X000000
# define PURPLE	0X800080
# define BLUE	0X0000FF
# define GREEN	0X00FF00

# define WALL_DIM 64.0
# define HALF_WALL 32.0

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_parsing
{
	// Put your stuffs down here


}	t_parsing;


typedef struct s_my_mlx
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		bpp_n;
	int		line_len_n;
	int		endian_n;

	int		bpp_s;
	int		line_len_s;
	int		endian_s;

	int		bpp_w;
	int		line_len_w;
	int		endian_w;

	int		bpp_e;
	int		line_len_e;
	int		endian_e;

	char	*addr_n;
	char	*addr_s;
	char	*addr_w;
	char	*addr_e;
}	t_my_mlx;

typedef struct s_window
{
	void		*mlx;
	void		*window;
	char		**map;
	char		*north_img;
	char		*south_img;
	char		*east_img;
	char		*west_img;
	char		*north_xpm;
	char		*south_xpm;
	char		*east_xpm;
	char		*west_xpm;
	double		field_of_view;
	double		x_player;
	double		y_player;
	double		x_endRay;
	double		y_endRay;
	double		distance;
	double		corrected_distance;
	int			ceilling;
	int			floor;

	double		dir_x;
	double		dir_y;

	
	t_data_par	parsing;
	t_my_mlx	my_mlx;
}	t_mlx;

void	images_to_xpm(t_mlx *wind);
char	*get_next_line(int fd);
/*
	Getting the player position in the map [y,x]
*/
void	get_player_position(t_mlx *wind);
/*
	Used to move the player forward by increasing his current position by 1px
*/
void	move_forward(t_mlx *wind);
/*
	Used to move the player backward by decreasing his current position by 1px
*/
void	move_backword(t_mlx *wind);
/*
	Used to move the player by -90 degree in ordre to move him left 
*/
void	move_left(t_mlx *wind);
/*
	Used to move the player by -90 degree in ordre to move him right
*/
void	move_right(t_mlx *wind);
/*
	An infinite cast ray using x->cos() y->sin() until hitting the Wall
*/
void	cast_rays(t_mlx *wind, double angle, int i);
/*
	Whenever a ray hits the wall set which interface he see's based on his position [y,x]
	and the wall intersection[y,x]
*/
char	set_directions(double w_y, double w_x, t_mlx *wind);
/*
	Starting from the player position we draw line using cast_rays()
*/
void	projecting_rays(t_mlx *wind);
/*
	When we mesured the distance we start rendring our world
*/
void	casting_3d(double distance, int i, t_mlx *mlx, char dir);
/*
	Whenever the user hit a key provide him wwith the move he requires
*/
int		get_keys(int press, t_mlx	*wind);
int		destroy_window(t_mlx *wind);
void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color);

#endif