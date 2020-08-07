#include "fdf.h"



int main() {
	t_fdf *data;

	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(data);
	return (0);
}
