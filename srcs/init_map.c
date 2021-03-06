#include "../includes/so_long.h"
#include <stdlib.h>
#include <fcntl.h>

void	parse_file(t_base *base, char buf[], int fd, char **file)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		destroy_base(base, "Malloc error");
	}
}

void	read_file(t_base *base, char buf[], int fd, char **file)
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
			destroy_base(base, "read error");
		}
		else
		{
			buf[ret] = 0;
			parse_file(base, buf, fd, file);
		}
	}
}

char	*init_file(t_base *base, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		destroy_base(base, "calloc error");
	}
	return (file);
}

void	init_map(t_base *base, char *path)
{
	char	*file;
	int		fd;
	char	buf[1024 + 1];

	fd = open(path, O_RDONLY);
	if (fd == -1)
		destroy_base(base, "Open failed");
	file = init_file(base, fd);
	read_file(base, buf, fd, &file);
	close(fd);
	read_map(base, file);
	free(file);
}
