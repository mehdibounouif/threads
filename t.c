/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:03:00 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/06 10:22:12 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the rece condition
// the problem is uncall pthread_join() to block the calling thread until the specified thread terminated

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 16

void *thread(void *thread_id) {
    int id = *((int *) thread_id);
    printf("Hello from thread %d\n", id + 1);
    return NULL;
}

int main() {
	int	i;
    pthread_t threads[NUM_THREADS];

	i = 0;
    while (i < NUM_THREADS) {
        if (pthread_create(&threads[i], NULL, thread, &i))
        {
            fprintf(stderr, "pthread_create failed!\n");
            return EXIT_FAILURE;
        }
		if (pthread_join(threads[i], NULL))
		{
            fprintf(stderr, " pthread_join failed!\n");
            return EXIT_FAILURE;
		}
		i++;
    }
    return EXIT_SUCCESS;
}
