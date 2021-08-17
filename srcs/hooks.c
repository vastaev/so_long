#include "so_long.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, void *param)
{
	t_long *program = (t_long *)param;

	// mlx function that clears the window
	mlx_clear_window(program->mlx, program->window.reference);

	// move in a direction based on the key
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == 53)
		ft_close();

	// mlx function that puts and image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update (t_long *program)
{
	// a static that saves how many frames have passed
	// static int	frame;

	// // add a frame and every x frames change the position by 1 pixel
	// // so it looks like its animated
	// frame++;
	// if (frame == ANIMATION_FRAMES)
	// 	program->sprite_position.y += 1;
	// // every x*2 frames go back that pixel to loop the animation
	// else if (frame >= ANIMATION_FRAMES * 2)
	// {
	// 	program->sprite_position.y -= 1;
	// 	frame = 0;
	// }
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	return (0);
}