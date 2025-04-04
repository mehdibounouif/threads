/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:14:19 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/04 22:22:38 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int c, char **v)
{
	int	pid;
	int	x = 0;
	pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		sleep(1);
		x++;
	}

	if (pid > 0)
	{
		sleep(5);
	}
	printf("value of x = %d pid = %d\n", x, getpid());

	return (0);
}
