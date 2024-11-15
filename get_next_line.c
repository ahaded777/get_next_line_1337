/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
    +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+
    +#+        */
/*                                                +#+#+#+#+#+
    +#+           */
/*   Created: 2024/11/12 13:34:09 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/12 18:37:17 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

static void	ft_lkmala_strjoin(char *res, char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		res[*len] = str[i];
		i++;
		(*len)++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	len = 0;
	ft_lkmala_strjoin(res, s1, &len);
	ft_lkmala_strjoin(res, s2, &len);
	res[len] = '\0';
	return (res);
}

static int	ft_lkmala_machakil_ti9niya(int bytes_read, char **saved)
{
	if (bytes_read < 0)
	{
		free(*saved);
		*saved = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchar(saved, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_lkmala_machakil_ti9niya(bytes_read, &saved) == 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(saved, buffer);
		if (!temp)
			return (free(saved), saved = NULL, NULL);
		free(saved);
		saved = temp;
	}
	if (!saved)
		return (NULL);
	return (ft_lkmala(&saved));
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);

// 	char *line;

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// }
