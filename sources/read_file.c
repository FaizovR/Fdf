#include "fdf.h"


int get_height(char *file_name);


int get_width(char *file_name);

void fill_matrix(int *z_line, char *line);

void read_file(char *file_name, t_fdf *data)
{
	int fd;
	char *line;
	int i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

//	TODO add Malloc error handler
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
//	TODO add Malloc error handler
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
//	TODO check this
	data->z_matrix[i] = NULL;
}

void fill_matrix(int *z_line, char *line) {
	char	**nums;
	int		i;
//	TODO add Malloc error handler
	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int get_width(char *file_name) {
	int width;
	int fd;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_word_cnt(line, ' ');
	free(line);
	close(fd);

	return (width);
}

int get_height(char *file_name) {
	char	*line;
	int		fd;
	int 	height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);

	return (height);
}
