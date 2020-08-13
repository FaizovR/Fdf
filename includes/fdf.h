/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 14:19:13 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define SHIFT 10
# define SHIFT_Z 1
# define ZOOM 10
# define WINDOW_SIZE_S_X 2000
# define WINDOW_SIZE_S_Y 1000
# define WINDOW_SIZE_F_X 2560
# define WINDOW_SIZE_F_Y 1400
# define ANGLE_ISO 0.523599
# define COLOR_RED 0xe80c0c
# define COLOR_WHITE 0xffffff
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			shift_z;
	int			is_isometric;
	int			is_fullscreen;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

float			max(float a, float b);
float			mod(float i);
int				get_width_fd(char *file_name, t_fdf *data);
int				get_height_fd(char *file_name);
void			read_file(char *file_name, t_fdf *p_fdf);
void			isometric(float *x, float *y, int z);
void			draw_line(t_point p1, t_point p2, t_fdf *data);
void			draw(t_fdf *data);
void			ft_error(t_fdf *data, char *str);
int				deal_key(int key, t_fdf *data);
void			change_window(t_fdf *data);
void			shift(int key, t_fdf *data);
void			shift_z(int key, t_fdf *data);
void			zoom(int key, t_fdf *data);
void			new_window(t_fdf *data);
void			change_window(t_fdf *data);
void			exit_success(t_fdf *data);
#endif
