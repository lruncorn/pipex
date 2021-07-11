#include "pipex.h"

void	end_programm(const char *message, int ret)
{
	write(1, message, ft_strlen(message));
	exit(ret);
}
