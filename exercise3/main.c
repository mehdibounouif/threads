/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:47:44 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/06 16:51:06 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef	struct	s_list
{
	int	sum;
	int	*list;
	int	list_size;
}	t_list;

void	*routine(void *args)
{
	t_list	*data;
	int	i;

	data = (t_list*)args;
	i = 0;
	while (i < data->list_size)
	{
		data->sum += data->list[i];
		i++;
	}
	return ((void*)(long)data->sum);
}

int	main(int c, char **v)
{
	pthread_t	t;
	int	i;
	void	*result;
	t_list	*list;

	i = 0;
	if (!(list = malloc(sizeof(t_list))))
		return (1);
	list->list_size = c - 1;
	if (!(list->list = malloc(sizeof(int) * list->list_size)))
	{
		free(list);
		return (1);
	}
	while(i < list->list_size)
	{
		list->list[i] = atoi(v[i+1]);
		i++;
	}
	if (pthread_create(&t, NULL, &routine, list))
	{
		fprintf(stderr, "pthread_create() failed!\n");
		free(list);
		return (2);
	}
	if (pthread_join(t, &result))
	{
		fprintf(stderr, "pthread_join() failed!\n");
		free(list);
		return (3);
	}
	printf("Result = %ld", (long)result);
	return (0);
}
