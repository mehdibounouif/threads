/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 07:42:18 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/19 14:46:33 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
	long	value;
	pthread_mutex_t	mutex;
}	t_list;

void	*routine(void *args)
{
	t_list	*list;
	long	i;

	list = (t_list *)args;
	i = 0;
	pthread_mutex_lock(&(list->mutex));
	while (i++ < 10000000000)
		list->value++;
	pthread_mutex_unlock(&(list->mutex));
	return (NULL);
}

// Example of mutex:
//
// void	*routine(void *args)
// {
//		int	i = 0;
//		int	lock = 0;
//		while (i < 1000000)
//		{
//			if (lock == 1)
//				wait until thread finished.
//			lock = 1;
//			i++;
//			lock = 0;
//		}
//		return (NULL);
// }

int	main()
{
	int	i;
	t_list	*list;
	pthread_t	th[4];

	i = 0;
	if (!(list = malloc(sizeof(t_list))))
		return (1);
	pthread_mutex_init(&(list->mutex), NULL);
	
	// pthread_create():
	// 1 - Allocates resources for a new thread of execution within the current process 
	// 2 - Create a new thread ID (stored in the pthread_t variable you provide)
	while (i < 2)
	{
		if (pthread_create(&th[i], NULL, routine, list))
		{
			printf("thread create failed!\n");
			return (2);
		}
		//printf("Thread %d is started with address %lu\n", i+1, th[i]);
		//if (pthread_join(th[i], NULL))
		//{
		//	printf("thread failed execution!\n");
		//	return (3);
		//}
		//printf("Thread %d is finished execution\n", i+1);
		i++;
	}
	// pthread_join():
	// 1 - blocks the calling thread until the specified thread terminates.
	// 2 - Retrieves the thread's return value (if any) and cleans up its resources.
	i = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], NULL))
		{
			printf("thread failed execution!\n");
			return (3);
		}
		printf("Thread %d is finished execution\n", i+1);
		i++;	
	}
//	pthread_mutex_destroy(&(list->mutex));
	printf("Value = %ld\n", list->value);
	return (0);

}
