#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*do_something(void *arg);

int	n = 0;
pthread_mutex_t	mutex;

int main(void)
{
	pthread_t		t1;
	pthread_t		t2;
	pthread_t		t3;

	pthread_mutex_init(&mutex, NULL);

	if (pthread_create(&t1, NULL, &do_something, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &do_something, NULL) != 0)
		return (1);
	if (pthread_create(&t3, NULL, &do_something, NULL) != 0)
		return (1);

	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	if (pthread_join(t3, NULL) != 0)
		return (1);
	printf("i: %d", n);
	pthread_mutex_destroy(&mutex);
    return (0);
}

void	*do_something(void *arg)
{
	int	i;

	i = 0;
	(void)arg;
	while (i < 100000)
	{
		pthread_mutex_lock(&mutex);
		n++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}
