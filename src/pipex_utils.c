#include "pipex.h"

int	pipex_cleanup(t_data *data, char **path)
{
	if (path)
		free_chartab(path);
	if (data[0].cmd)
		free_chartab(data[0].cmd);
	if (data[1].cmd)
		free_chartab(data[1].cmd);
	if (data[0].fd > 0)
		close(data[0].fd);
	if (data[1].fd > 0)
		close(data[1].fd);
	free(data);
	return (EXIT_FAILURE);
}

void	close_fd(t_data *data, t_pipe pipe)
{
	close(pipe.pipe[0]);
	close(pipe.pipe[1]);
	close(data[0].fd);
	close(data[1].fd);
}
