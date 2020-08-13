/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 12:41:53 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error(data, "file does not exist\n");
	if (get_next_line(fd, &line) == -1)
		ft_error(data, "Invalid file\n");
	free(line);
	close(fd);
}

int		ft_is_str_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	fill_matrix(int *z_line, char *line, t_fdf *data)
{
	char	**nums;
	int		i;
	int		j;

	if (!(nums = ft_strsplit(line, ' ')))
	{
		ft_putstr("Reading error\n");
		free(line);
		free(z_line);
		exit(0);
	}
	i = 0;
	j = 0;
	while (nums[i])
	{
		if (!ft_is_str_digit(nums[i]))
			ft_error(data, "Incorrect map\n");
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	check_file(file_name, data);
	data->height = get_height_fd(file_name);
	data->width = get_width_fd(file_name, data);
	if (!(data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1))))
		ft_error(data, "Reading error\n");
	i = 0;
	while (i < data->height)
		if (!(data->z_matrix[i++] =
				(int*)ft_memalloc(sizeof(int) * (data->width + 1))))
			ft_error(data, "Reading error\n");
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line, data);
		ft_bzero(line, sizeof(line));
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
