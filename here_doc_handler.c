/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:38:21 by antabord          #+#    #+#             */
/*   Updated: 2025/10/30 18:13:11 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"

static char	*get_line(void)
{
	static char	buffer[2];
	char		*tmp;
	char		*old_tmp;
	int			bytes_read;

	tmp = NULL;
	bytes_read = 1;
	while (bytes_read != 0 && (!tmp || !ft_strchr(tmp, '\n')))
	{
		old_tmp = tmp;
		bytes_read = read(0, buffer, 1);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
			return (NULL);
		free(old_tmp);
	}
	if (!tmp || !*tmp)
		return (free(tmp), NULL);
    tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

int	heredoc_handler(char *limiter)
{
	char *str;
    int fd[2];

	str = NULL;
    if (pipe(fd) == -1)
    {
        perror("rip pipe");
        return 0;
    }
	while (1)
	{
		str = get_line();
		if (!str)
			return 0;
        if (!ft_strncmp(str, limiter, ft_strlen(limiter) + 1))
        {
            get_fd()->infile_fd = fd[0];
            return (free(str), close(fd[1]), 1);
        }
        write(fd[1], str, ft_strlen(str));
        write(fd[1], "\n", 1);
        free(str);
	}
    close(fd[1]);
    get_fd()->infile_fd = fd[0];
	return 0;
}
