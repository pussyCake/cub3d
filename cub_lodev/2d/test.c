#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	printf("start\n");
	//parse_cub(av[1], &cub);
	printf("h:%d\n", cub.win_h);
	printf("w:%d\n", cub.win_w);
	printf("h_max:%d\n", cub.h_max);
	printf("w_max:%d\n", cub.w_max);
	printf("%s\n", cub.no);
	printf("%s\n", cub.so);
	printf("%s\n", cub.we);
	printf("%s\n", cub.ea);
	printf("%s\n", cub.s);
	printf("%d\n", cub.f);
	printf("%d\n", cub.c);
	printf("stop\n");
	return (0);
}