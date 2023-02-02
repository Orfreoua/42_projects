#include "../../headers/libft.h"

int		find_index(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i++])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	if (fd == -1)
		return (NULL);
	if (find_index(rest, '\n') != -1)
	{
		temp = ft_substr(rest, find_index(rest, '\n'), ft_strlen(rest));
		line = ft_substr(rest, 0, find_index(rest, '\n'));
		free(rest);
		rest = temp;
		return (line);
	}
	else
	{
		ret = read(fd, buff, BUFFER_SIZE);
		while (ret > 0)
		{
			buff[ret] = '\0';
			rest = ft_strjoin(rest, buff, 1);
			if (find_index(rest, '\n') != -1)
				get_next_line(fd);
		}
	}
	if (ft_strlen(rest))
	{
		line = ft_substr(rest, 0, ft_strlen(rest));
		free(rest);
		rest = NULL;
	}
	return (line);
}


#include  <stdio.h>
int main()
{
	int fd = open("ft_substr.c", O_RDONLY);
	char *line;
	while (line = get_next_line(fd))
	{
		printf("%s\n", line);
		free(line);
	}
}