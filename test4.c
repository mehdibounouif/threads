/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:40:44 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/05 12:51:00 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef	struct s_list
{
	int	value;
	pthread_mutex_t	lock;
	int	i;
}	t_list;

int	m = 0;

void*	routine(void *args)
{
	t_list	*list = (t_list*)args;
//	int	i = 0;
	pthread_mutex_lock(&list->lock);
	while (list->i < 100000)
	{
		(list)->value++;
		list->i++;
	}
	pthread_mutex_unlock(&list->lock);
	return (NULL);
}

void	*routine2(void *args)
{
	t_list	*list = (t_list*)args;
	int	i = 0;
	pthread_mutex_lock(&list->lock);
	while (i++ < 100000)
		m++;
	pthread_mutex_unlock(&list->lock);
	return (NULL);
}

int	main()
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
		return (5);
	list->value = 0;
	list->i = 0;
	pthread_t t1;
	pthread_t t2;

	pthread_mutex_init(&list->lock, NULL);

	if (pthread_create(&t1, NULL, routine, list))
		return (1);
	if (pthread_create(&t2, NULL, routine, list))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);

	printf("%d\n", list->value);
	printf("%d\n", m);

	pthread_mutex_destroy(&list->lock);
	free(list);
}
