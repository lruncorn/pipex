#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**path;
	char	**args1;
	char	**args2;
	char	*cmd1;
	char	*cmd2;
	char	*arg1;
	char	*arg2;
}				t_data;

void	get_data(t_data *data, char **argv, char **envp);
void	end_programm(const char *message, int ret);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif