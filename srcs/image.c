#include "so_long.h"

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	
	/* mlx function that creates and image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
