#include "../cub3d.h"

void    images_to_xpm(t_mlx *wind)
{
    int height;
    int width;

    wind->north_img = wind->parsing.north_path;
    wind->south_img = wind->parsing.south_path;
    wind->west_img  = wind->parsing.west_path;
    wind->east_img  = wind->parsing.east_path;

    // printf("We -> %s\n", wind->west_img);
    // printf("No -> %s\n", wind->north_img);
    // printf("So -> %s\n", wind->south_img);
    // printf("Ea -> %s\n", wind->east_img);

    
    wind->north_xpm = mlx_xpm_file_to_image(wind->mlx, wind->north_img ,&width, &height);
    wind->south_xpm = mlx_xpm_file_to_image(wind->mlx, wind->south_img ,&width, &height);
    wind->west_xpm  = mlx_xpm_file_to_image(wind->mlx, wind->west_img ,&width, &height);
    wind->east_xpm  = mlx_xpm_file_to_image(wind->mlx, wind->east_img ,&width, &height);

    wind->my_mlx.addr_n = mlx_get_data_addr(wind->north_xpm, &wind->my_mlx.bpp_n, &wind->my_mlx.line_len_n, &wind->my_mlx.endian_n);
    wind->my_mlx.addr_s = mlx_get_data_addr(wind->south_xpm, &wind->my_mlx.bpp_s, &wind->my_mlx.line_len_s, &wind->my_mlx.endian_s);
    wind->my_mlx.addr_w = mlx_get_data_addr(wind->west_xpm, &wind->my_mlx.bpp_w, &wind->my_mlx.line_len_w, &wind->my_mlx.endian_w);
    wind->my_mlx.addr_e = mlx_get_data_addr(wind->east_xpm, &wind->my_mlx.bpp_e, &wind->my_mlx.line_len_e, &wind->my_mlx.endian_e);
}
