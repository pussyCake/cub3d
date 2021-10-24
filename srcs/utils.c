
#include "cub.h"

t_img	*ft_create_text(t_cub *cub, char *add)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!(texture))
		return (NULL);
	texture->img = mlx_xpm_file_to_image(cub->mlx, add, &texture->width,
			&texture->height);
	if (!(texture->img))
		return (NULL);
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->line_length, &texture->endian);
	if (!(texture->addr))
		return (NULL);
	return (texture);
}

t_img	*ft_new_image(t_cub *cub)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!(img))
		ft_notify_error("img fail", cub);
	img->img = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (!(img->img))
		ft_notify_error("img fail", cub);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	if (!(img->addr))
		ft_notify_error("img fail", cub);
	img->width = cub->win_w;
	img->height = cub->win_h;
	return (img);
}

void	ft_check(t_cub *cub)
{
	ft_check_number_param(cub);
	ft_check_path(cub);
	ft_check_format(cub, cub->param.no);
	ft_check_format(cub, cub->param.so);
	ft_check_format(cub, cub->param.we);
	ft_check_format(cub, cub->param.ea);
	ft_check_format(cub, cub->param.spr);
}
