/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:50:08 by jarumuga          #+#    #+#             */
/*   Updated: 2024/08/09 10:58:40 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// if not 4 argc (+ 1 for ./pipex), error message then exit
// otherwise call pipex
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Correct syntax : ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (EXIT_FAILURE);
	}
	pipex(argv, envp);
	return (0);
}
