#include "../includes/so_long.h"
#include <stdlib.h>

static void	parse_file(t_base *base, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		destroy_base(base, "map_init(): ft_strjoin()", errno);
	}
}

static void	read_file(t_base *base, char **file, char buf[], int fd)
{
	int				ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(*file);
			close(fd);
			destroy_base(base, "map_init(): read()", errno);
		}
		else
		{
			buf[ret] = 0;
			parse_file(base, file, buf, fd);
		}
	}
}

static char	*init_file(t_base *base, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		destroy_base(base, "map_init(): ft_calloc()", errno);
	}
	return (file);
}

void	init_map(t_base *base, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		destroy_base(base, filename, errno);
	file = init_file(base, fd);
	read_file(base, &file, buf, fd);
	close(fd);
	read_map(base, file);
	free(file);
}
