/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:54:40 by marvin            #+#    #+#             */
/*   Updated: 2023/12/31 11:54:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		pid1;
	int		pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	child1(t_pipex pipex, char *argv[], char *envp[]);
void	child2(t_pipex pipex, char *argv[], char *envp[]);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
void	msg_error(char *error);
int		msg(char *error);

#endif