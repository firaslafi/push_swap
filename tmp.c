void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->index <= i)
		{
			pa(&stack_a, &stack_b);
			rb(&stack_b);
			i++;
		}
		else if (stack_a->head->index <= i + range)
		{
			pb(&stack_a, &stack_b);
			i++;
		}
		else
			ra(&stack_a);
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->index != length - 1)
				rb(&stack_b);
			pa(&stack_a, &stack_b);
			length--;
		}
		else
		{
			while (stack_b->head->index != length - 1)
				rrb(&stack_b);
			pa(&stack_a, &stack_b);
			length--;
		}
	}
}