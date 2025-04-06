#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	sum;
int	list_size;	
int	*list;

void	*routine()
{
	int	i = 0;
	while (i < list_size)
		sum += list[i++];
	return (NULL);
}

int	main(int	c, char **v)
{
	pthread_t	t;
	int	i = 0;
	if (c <= 1)
	{
		fprintf(stderr, "Invalid argument\n");
		return (1);
	}
	while (list_size < c)
		list_size++;
	list_size--;
	if (!(list = malloc(sizeof(int) * list_size)))
		return (2);
	while (i < list_size)
	{
		list[i] = atoi(v[i+1]);
		i++;
	}	
	if(pthread_create(&t, NULL, routine, NULL))
	{
		fprintf(stderr, "pthread_create failed!\n");
		return (1);
	}
	pthread_join(t, NULL);
	printf("Sum of numbers = %d", sum);
	/*
	i = 0;
	while (i < list_size)
	{
		printf("%d ", list[i++]);
		printf("\n");
	}
	*/
}

