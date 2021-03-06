
#include "cub.h"

void	ft_check_format(t_cub *cub, char *str)
{
	char	*s;

	s = ft_strchr(str + 1, '.');
	if (!s || ft_strncmp(s, ".xpm", 5) != 0)
		ft_notify_error("MUST BE '.xpm' texture", cub);
}

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	while (str[i] != '.')
	{
		if (ft_isascii(str[i]) && str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_prefix(t_cub *cub)
{
	if (ft_check_space(cub->param.n) == 0)
		ft_notify_error_param("FAIL PARAM: ", cub, "NO");
	if (ft_check_space(cub->param.s) == 0)
		ft_notify_error_param("FAIL PARAM: ", cub, "SO");
	if (ft_check_space(cub->param.w) == 0)
		ft_notify_error_param("FAIL PARAM: ", cub, "WE");
	if (ft_check_space(cub->param.e) == 0)
		ft_notify_error_param("FAIL PARAM: ", cub, "EA");
	if (ft_check_space(cub->param.sp) == 0)
		ft_notify_error_param("FAIL PARAM: ", cub, "S");
}

void	ft_free_structure(char *str)
{
	free(str);
	str = NULL;
}

void	ft_check_path(t_cub *cub)
{
	ft_check_prefix(cub);
	cub->param.no = ft_strtrim(ft_strchr(cub->param.n, '.'), " ");
	if (!(cub->param.no))
		ft_notify_error_param("FAIL malloc in : ", cub, "NO");
	ft_free_structure(cub->param.n);
	cub->param.so = ft_strtrim(ft_strchr(cub->param.s, '.'), " ");
	if (!(cub->param.so))
		ft_notify_error_param("FAIL malloc in : ", cub, "SO");
	ft_free_structure(cub->param.s);
	cub->param.we = ft_strtrim(ft_strchr(cub->param.w, '.'), " ");
	if (!(cub->param.we))
		ft_notify_error_param("FAIL malloc in : ", cub, "WE");
	ft_free_structure(cub->param.w);
	cub->param.ea = ft_strtrim(ft_strchr(cub->param.e, '.'), " ");
	if (!(cub->param.ea))
		ft_notify_error_param("FAIL malloc in : ", cub, "EA");
	ft_free_structure(cub->param.e);
	cub->param.spr = ft_strtrim(ft_strchr(cub->param.sp, '.'), " ");
	if (!(cub->param.spr))
		ft_notify_error_param("FAIL malloc in : ", cub, "S");
	ft_free_structure(cub->param.sp);
}
