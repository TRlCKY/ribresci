#include "../H_Files/codexion.h"

void	add_back(t_heap *heap, t_coder *coder)
{
	heap->coders[heap->size] = *coder;
	heap->size++;
	if (strcmp(heap->scheduler, "edf") == 0)
		sort_heap(heap);
}

void	pop_front(t_heap *heap)
{
	int	i;

	i = 0;
	if (heap->size == 0)
		return ;
	while (i < heap->size - 1)
	{
		heap->coders[i] = heap->coders[i + 1];
		i++;
	}
	heap->size--;
}

void	sort_heap(t_heap *heap)
{
	int		i;
	int		e;
	t_coder	coder0;

	e = 0;
	while (e < heap->size)
	{
		i = 0;
		while (i < heap->size - 1)
		{
			if (heap->coders[i].last_compile_start + heap->coders[i].burnout > heap->coders[i + 1].last_compile_start + heap->coders[i + 1].burnout)
			{
				coder0 = heap->coders[i];
				heap->coders[i] = heap->coders[i + 1];
				heap->coders[i + 1] = coder0;
			}
			i++;
		}
		e++;
	}
}

t_coder	*get_next(t_heap *heap)
{
	if (heap->size == 0)
		return (NULL);
	else
		return(&heap->coders[0]);
}