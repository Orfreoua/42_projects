#ifndef PIPEX_H
# define PIPEX_H

#ifndef BONUS
#define BONUS 0
#endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

# define TRUE		0
# define FALSE		1
# define STDIN		0
# define STDOUT		1
# define INFILE		0
# define OUTFILE	1
# define STDERR		2


void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(char *str, unsigned int n);
char	*path_join (char *path, char *bin);
int		find_index(char *str, char index);

#endif