/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:10 by jarumuga          #+#    #+#             */
/*   Updated: 2024/08/09 11:02:27 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// handle errors and perform cleanup before exit
// message write on stderr
// -1 is an invalid or uninit fd value
void	error_exit(const char *message, t_context *context)
{
	if (context)
	{
		if (context->args)
			free_args(context->args);
		if (context->path)
			free(context->path);
		if (context->infile != -1)
			close(context->infile);
		if (context->outfile != -1)
			close(context->outfile);
		if (context->fd[0] != -1)
			close(context->fd[0]);
		if (context->fd[1] != -1)
			close(context->fd[1]);
	}
	perror(message);
	exit(EXIT_FAILURE);
}

// function free for malloc (split)
void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
