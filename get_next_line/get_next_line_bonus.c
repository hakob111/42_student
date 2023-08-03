
#include "get_next_line_bonus.h"

char	*joinandfree(char *str, char *buffer)
{
	char	*result;

	result = NULL;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
	}
	result = ft_strjoin(str, buffer);
	if (!result)
		return (0);
	free(str);
	return (result);
}

char	*longline(char *str)
{
	int		index;
	int		ind2;
	char	*result;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str || str[index] == '\0' || str[index + 1] == '\0')
	{
		free(str);
		return (0);
	}
	ind2 = index + 1;
	result = malloc(1 + (ft_strlen(str) - ind2) * sizeof(char));
	if (!result)
		return (0);
	index = 0;
	while (str[ind2 + index])
	{
		result[index] = str[index + ind2];
		index++;
	}
	result[index] = '\0';
	free(str);
	return (result);
}

char	*getn(char *string)
{
	int		index;
	char	*valid_line;

	index = 0;
	if (!string || !string[index])
		return (0);
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	valid_line = (char *)malloc((index + 1) * sizeof(char));
	if (!valid_line)
		return (0);
	index = 0;
	while (string[index] && string[index] != '\n')
	{
		valid_line[index] = string[index];
		index++;
	}
	if (string[index] == '\n')
		valid_line[index++] = '\n';
	valid_line[index] = '\0';
	return (valid_line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	int			fd_read;
	static char	*start_str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
	{
		if (start_str[fd])
			free(start_str[fd]);
		return (0);
	}
	fd_read = 1;
	tmp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (0);
	while (!(ft_strchr(start_str[fd], '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (0);
		}
		tmp[fd_read] = '\0';
		start_str[fd] = joinandfree(start_str[fd], tmp);
	}
	free(tmp);
	tmp = getn(start_str[fd]);
	start_str[fd] = longline(start_str[fd]);
	return (tmp);
}

/*
int main (void)
{
	int fd;
	char	*good;
	char	*next;

	fd = open("41_no_nl", O_RDONLY);
	good = get_next_line(fd);
	next = get_next_line(fd);
	printf("%s", good);
	printf("%s", next);
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%u\n", fb);
	//printf("%i", BUFFER_SIZE);
	free(good);
	free(next);
	return (0);
}
*/