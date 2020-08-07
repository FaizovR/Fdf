#include "fdf.h"
#include <stdio.h>

int deal_key(int key, t_fdf *data) {
	printf("%d", key);

	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
int main(int argc, char **argv) {
	t_fdf *data;
	if (argc == 1) {
		return 0;
	}
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->zoom = 20;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	draw(data);
//	draw_line(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
