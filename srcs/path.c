/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:35:32 by jarumuga          #+#    #+#             */
/*   Updated: 2024/08/09 11:54:41 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// look for the path var
// use strncmp to return the match PATCH
	// return the path by skiping "PATH="
char	*find_path_variable(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

// duplicate the path
// calculate the len
// cpy my path and return it
char	*duplicate_path(const char *path_var, t_context *context)
{
	size_t	path_var_len;
	char	*path;

	path_var_len = ft_strlen(path_var);
	path = (char *)malloc(path_var_len + 1);
	if (!path)
		error_exit("error malloc duplicate_path", context);
	ft_strlcpy(path, path_var, path_var_len + 1);
	return (path);
}

// construct the path
// cat directory path + command name
// calculate the len of dir and command
// calculate the len for the full path + 2 (one for / and one '\0')
// check for overflow
// cpy the dir path in full_path
// cat / then the command
static char	*construct_full_path(const char *directory, \
const char *command, t_context *context)
{
	char	*full_path;
	size_t	dir_len;
	size_t	cmd_len;
	size_t	full_path_size;

	dir_len = ft_strlen(directory);
	cmd_len = ft_strlen(command);
	full_path_size = dir_len + cmd_len + 2;
	if (dir_len + cmd_len + 2 > full_path_size)
		error_exit("error path too long construct_full_path", context);
	full_path = (char *)malloc(full_path_size);
	if (!full_path)
		error_exit("error malloc construct_full_path", context);
	ft_strlcpy(full_path, directory, full_path_size);
	ft_strlcat(full_path, "/", full_path_size);
	ft_strlcat(full_path, command, full_path_size);
	return (full_path);
}

// check if absolut path
// look for '/'
	// check if it's executable with access, if ok return it
char	*check_absolut_path(const char *command, t_context *context)
{
	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (ft_strdup(command));
		else
			error_exit("error command not found check_absolut_path", context);
	}
	return (NULL);
}

// look through the directories to find the full path
// token point to the curr dir being checked
// next token point to the next dir
// assign a duplicathe in 'path' because we are going to null terminated
// : separate dir in PATH, if it find it, replace : by \0
// build the full path : dir + command
// check with access if the path is correct
char	*search_path_directories(const char *path_var, \
const char *command, t_context *context)
{
	char	*path;
	char	*token;
	char	*next_token;
	char	*full_path;

	path = duplicate_path(path_var, context);
	if (!path)
		error_exit("malloc search_path_directories", context);
	token = path;
	next_token = NULL;
	full_path = NULL;
	while (token)
	{
		next_token = ft_strchr(token, ':');
		if (next_token)
			*next_token++ = '\0';
		full_path = construct_full_path(token, command, context);
		if (access(full_path, X_OK) == 0)
			return (free(path), full_path);
		free(full_path);
		token = next_token;
	}
	return (free(path), NULL);
}
