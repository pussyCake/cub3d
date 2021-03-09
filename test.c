// #include "libft.h"
// #include "cub.h"
// #include "get_next_line.h"

// char	**make_map(t_list **head, int size)
// {
// 	char	**map;
// 	int		i;
// 	t_list	*tmp;

// 	map = ft_calloc(size + 1, sizeof(char*));
// 	i = -1;
// 	tmp = *head;
// 	while (tmp)
// 	{
// 		map[++i] = tmp->content;
// 		tmp = tmp->next;
// 	}
// 	i = -1;
// 	while (map[++i])
// 		ft_putlist(map[i]);
// 	return (map);
// }

// void	parse_map(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	t_list	*head;
	
// 	line = NULL;
// 	head = NULL;
// 	fd = open(argv[1], O_RDONLY);
// 	while (get_next_line(fd, &line))
// 		ft_lstadd_back(&head, ft_lstnew(line));
// 	ft_lstadd_back(&head, ft_lstnew(line));
// 	make_map(&head, ft_lstsize(head));
// }

// int main(int argc, char **argv)
// {
// 	parse_map(argc, argv);
// 	return (0);
// }