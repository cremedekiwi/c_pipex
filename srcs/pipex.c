/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:43:05 by jarumuga          #+#    #+#             */
/*   Updated: 2024/08/09 11:27:41 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// determine the full path of a command :
// 1. if already an absolute path (/), return it
// 2. assign the path_var then get the full path
// return the full path of my command
static char	*get_path(const char *command, char **envp, t_context *context)
{
	char	*path_var;
	char	*full_path;

	if (!command)
		return (NULL);
	full_path = check_absolut_path(command, context);
	if (full_path)
		return (full_path);
	path_var = find_path_variable(envp);
	if (!path_var)
		error_exit("error no path get_path", context);
	full_path = search_path_directories(path_var, command, context);
	if (!full_path)
		error_exit("error command not found get_path", context);
	return (full_path);
}

// execute my command
// split my command
// get my path (argv[0] is my command)
// execve execute my command, if there is an error it exit
void	execute_command(const char *argv, char **envp, t_context *context)
{
	context->args = ft_split(argv, ' ');
	if (!context->args)
		error_exit("error ft_split execute_command", context);
	context->path = get_path(context->args[0], envp, context);
	if (!context->path)
		error_exit("error command not found execute_command", context);
	if (execve(context->path, context->args, envp) == -1)
		error_exit("error execve execute_command", context);
	free(context->path);
	free(context->args);
	context->path = NULL;
	context->args = NULL;
}

// child_process
// open the file in read only mode
// duplicate the fd[1] (write end) to standard output
	// anything written by the child will be sent to the pipe
// duplicate infile to standard input
	// redirect standard input
// close then execute command
static void	child_process(char **argv, char **envp, t_context *context)
{
	context->infile = open(argv[1], O_RDONLY);
	if (context->infile == -1)
		error_exit("error open infile child_process", context);
	if (dup2(context->fd[1], STDOUT_FILENO) == -1)
		error_exit("error dup2 fd[1] child_process", context);
	if (dup2(context->infile, STDIN_FILENO) == -1)
		error_exit("error dup2 infile child_process", context);
	close(context->fd[0]);
	close(context->fd[1]);
	execute_command(argv[2], envp, context);
}

// parent_process
// open the file for writing (rw r r)
// duplicate the fd[0] (read end) to standard input
	// the input to the command come from the pipe
// duplicate outfile to standard output
	// redirect standard output
// close then execute command
static void	parent_process(char **argv, char **envp, t_context *context)
{
	context->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (context->outfile == -1)
		error_exit("error open outfile parent_process", context);
	if (dup2(context->fd[0], STDIN_FILENO) == -1)
		error_exit("error dup2 fd[0] parent_process", context);
	if (dup2(context->outfile, STDOUT_FILENO) == -1)
		error_exit("error dup2 outfile parent_process", context);
	close(context->fd[0]);
	close(context->fd[1]);
	execute_command(argv[3], envp, context);
}

// manage the execution of two process (child and a parent)
// so i can redirect the output of one command to be the input of another
// init all pointers to NULL, and fd to -1 (not open)
// create a pipe
// fork the first child (pid1)
// fork again, to create a second child (pid2)
// close
// wait that evry child process finished
void	pipex(char **argv, char **envp)
{
	int			status;
	pid_t		pid1;
	pid_t		pid2;
	t_context	context;

	context = (t_context){NULL, NULL, -1, -1, {-1, -1}};
	if (pipe(context.fd) == -1)
		error_exit("error pipe pipex", &context);
	pid1 = fork();
	if (pid1 == -1)
		error_exit("error fork pipex", &context);
	if (pid1 == 0)
		child_process(argv, envp, &context);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("error fork pipex", &context);
	if (pid2 == 0)
		parent_process(argv, envp, &context);
	close(context.fd[0]);
	close(context.fd[1]);
	while (wait(&status) > 0)
		;
}
