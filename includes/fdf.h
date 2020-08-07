
#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct 	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	void 		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void	read_file(char *file_name, t_fdf *p_fdf);
void	draw_line(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
#endif
