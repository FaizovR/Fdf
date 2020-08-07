
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
	void 		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void	read_file(char *file_name, t_fdf *p_fdf);

#endif
