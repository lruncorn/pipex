#include "pipex.h"

void	check_file(char *file)
{
	if (access(file, 0) != 0)
		end_programm("Error: no such file or directory\n", 1);
}

void	first_command(int *fd, char **argv, char **envp, t_data *data)
{
	int	file;

	close(fd[0]);
	dup2(fd[1], 1);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		end_programm("Cannot read the file\n", 1);
	dup2(file, 0);
	if (execve(data->args1[0], data->args1, envp) == -1)
		end_programm("Error: execve\n", 1);
}

void	second_command(int *fd, char **argv, char **envp, t_data *data)
{
	int	file;

	close(fd[1]);
	dup2(fd[0], 0);
	file = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (file < 0)
		end_programm("Error: can't open or create file\n", 1);
	dup2(file, STDOUT_FILENO);
	close(file);
	if (execve(data->args2[0], data->args2, envp) == -1)
		end_programm("Error: execve\n", 1);
}

void	check_argc(int argc, char **argv)
{
	if (argc != 5)
		end_programm("Error: wrong argument number\n", 1);
	check_file(argv[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		fd[2];
	pid_t	pid;
	pid_t	pid1;

	check_argc(argc, argv);
	if (pipe(fd) == -1)
		end_programm("Error: pipe fail\n", 1);
	get_data(&data, argv, envp);
	pid = fork();
	if (pid == -1)
		end_programm("Error: fork fail\n", 1);
	if (pid == 0)
		first_command(fd, argv, envp, &data);
	pid1 = fork();
	if (pid1 < 0)
		end_programm("Error: fork fail\n", 1);
	if (pid1 == 0)
		second_command(fd, argv, envp, &data);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid1, NULL, 0);
	exit (0);
}
