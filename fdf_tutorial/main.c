
#include "fdf.h"

int     deal_key(int key, fdf *data)
{
	printf("%d", key);
	if (key == 126)
	{
		data->shift_y -=10;
	}
	if (key == 125)
	{
		data->shift_y +=10;
	}
	if (key == 123)
	{
		data->shift_x -=10;
	}
	if (key == 124)
	{
		data->shift_x +=10;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int main(int argc, char **argv) {

	fdf *data;
	int i;
	int j;
	int x;
	int y;

	i = 0;
	data =  (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			printf("%3d ", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
//	bresenham(10, 10, 600, 300, data);
	draw(data);
//	mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, #color);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
