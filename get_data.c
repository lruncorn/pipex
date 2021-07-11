#include "pipex.h"

void	get_paths(t_data *data, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		end_programm("Error: PATH not found\n", 1);
	tmp = envp[i] + 5;
	data->path = ft_split(tmp, ':');
}

void	find_file2(t_data *data)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (data->path[i] != NULL)
	{
		tmp = ft_strjoin(data->path[i], "/");
		tmp2 = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(tmp2, data->args2[0]);
		if (access(tmp, 0) == 0)
		{
			data->cmd2 = ft_strdup(tmp);
			free(tmp);
			free(tmp2);
			break ;
		}
		free(tmp);
		free(tmp2);
		i++;
	}
	if (data->path[i] == NULL)
		end_programm("Error: file doesn't exist\n", 1);
}

void	find_file1(t_data *data)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (data->path[i] != NULL)
	{
		tmp = ft_strjoin(data->path[i], "/");
		tmp2 = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(tmp2, data->args1[0]);
		if (access(tmp, 0) == 0)
		{
			data->cmd1 = ft_strdup(tmp);
			free(tmp);
			free(tmp2);
			break ;
		}
		free(tmp);
		free(tmp2);
		i++;
	}
	if (data->path[i] == NULL)
		end_programm("Error: command file doesn't exist\n", 1);
}

void	get_args(t_data *data, char **argv)
{
	data->args1 = ft_split(argv[2], ' ');
	data->args2 = ft_split(argv[3], ' ');
}

void	get_data(t_data *data, char **argv, char **envp)
{
	char	*tmp;

	get_paths(data, envp);
	get_args(data, argv);
	find_file1(data);
	find_file2(data);
	tmp = data->args1[0];
	free(tmp);
	data->args1[0] = ft_strdup(data->cmd1);
	tmp = data->args2[0];
	free(tmp);
	data->args2[0] = ft_strdup(data->cmd2);
}
