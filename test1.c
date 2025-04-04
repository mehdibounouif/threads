/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:45:11 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/04 21:42:40 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void*	routine()
{
	printf("value after increment\n");
	sleep(3);
	printf("Ending of threads\n");
	return (NULL);
}

int	main(int c, char **v)
{
	pthread_t	t1;
	pthread_t	t2;

	if ((pthread_create(&t1,  NULL, routine, NULL) != 0))
	{
		perror("pthread_create 1 failed");
		return (1);
	}

	if ((pthread_create(&t2, NULL, &routine, NULL) != 0))
	{
		perror("ptherad_create 2 failed");
		return (1);
	}
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
