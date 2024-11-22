/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:30:28 by jarumuga          #+#    #+#             */
/*   Updated: 2024/08/09 11:00:08 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

// args : commands
// path : commande path
// infile : where i read
// outfile : where i write
// fd[0] for reading from the pipe ; fd[1] for writing the pipe
typedef struct s_context
{
	char	**args;
	char	*path;
	int		infile;
	int		outfile;
	int		fd[2];
}	t_context;

void	error_exit(const char *message, t_context *context);
void	free_args(char **args);
char	*find_path_variable(char **envp);
char	*check_absolut_path(const char *command, t_context *context);
char	*search_path_directories(const char *path_var, \
const char *command, t_context *context);
void	execute_command(const char *argv, char **envp, t_context *context);
void	pipex(char **argv, char **envp);

#endif
