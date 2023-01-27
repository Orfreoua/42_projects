#include "pipex.h"

int	load_files(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			/*write(STDERR, "pipex: ", 7);
			write(STDERR, filename, find_index(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);*/
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

 
char *get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && find_index(path, ':') > -1)
	{
		dir = ft_strndup(path, find_index(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		path += find_index(path, ':') + 1;
	}
	return (cmd);
}

/*
char **split_path(char *path)
{

}*/
/*
char *find_command(char **paths, char *command)
{
	while (*paths)
	{
		char *join = join(*paths, "/", command);
		if (access(join) == OK)
			return 	join;
	}
	return (NULL);
}
*/

char	**str_split (char *str, char sep)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == sep)
			count++;
	}
	tab = malloc(sizeof(char *) * (count + 2));
	tab[count + 1] = NULL;
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = ft_strndup(str, j);
		str = str + j + 1;
	}
	return (tab);
}


void	exec(char *cmd, char **env)
{
	char	*path;
	char	**args;

	args = str_split(cmd, ' ');
	if (find_index(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(cmd, env);
	execve(path, args, env);
	exit(127);
}

int	main(int argc, char **argv, char **env)
{
	int		fdin;
	int		fdout;
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		ft_putstr_fd("error wrong number of arguments\n", 2);
	else
	{
		fdin = load_files(argv[1], INFILE);
		fdout = load_files(argv[4], OUTFILE);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		pipe(pipefd);
		pid = fork();
		if (pid) // si parent.
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN);
			waitpid(pid, NULL, 0);
		}
		else
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT);
			if (!fdin)
				exit(1);
			else
				exec(argv[2], env);
			exec(argv[3], env);
		}
	}
	return (0);
}