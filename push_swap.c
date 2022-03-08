#include "push_swap.h"

t_stack	*translate(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = createt_stack();
	while (i < argc)
	{
		if (argv[i][0] == '0' && argv[i][1] == '\0')
			push_back(a, 0);
		else if (ft_atoi(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			deletet_stack(&a);
			exit(4);
		}
		else
			push_back(a, ft_atoi(argv[i]));
		i++;
	}
	return (a);
}

void	duplicates(t_stack **st)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*st)->size - 1)
	{
		j = i + 1;
		while (j < (*st)->size)
		{
			if (get_nvalue(*st, i) == get_nvalue(*st, j))
			{
				write (1, "Error\n", 6);
				deletet_stack(st);
				exit(2);
			}
			j++;
		}
		i++;
	}
}

void	extra_main1(t_stack **st, int argc)
{
	if (is_sorted(*st))
	{
		deletet_stack(st);
		exit (0);
	}
	if (argc == 3)
	{
		if ((*st)->head->value > (*st)->tail->value)
			write(1, "sa\n", 3);
		deletet_stack(st);
		exit (0);
	}
}

void	extra_main2(t_stack **st, t_stack **b)
{
	int		min_price;

	parse_stack(*st, *b);
	triple_sort(*st);
	while ((*b)->size > 0)
	{
		find_your_place(*st, *b);
		min_price = evaluation(*st, *b);
		sorting(*st, *b, min_price);
	}
	last_step(*st);
	deletet_stack(st);
	deletet_stack(b);
}

int	main(int argc, char**argv)
{
	t_stack	*st;
	t_stack	*b;

	if (argc < 2)
		return (0);
	else
	{
		if (parse_argv(argc, argv))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		st = translate(argc, argv);
		duplicates(&st);
		if (argc == 2)
		{
			deletet_stack(&st);
			return (0);
		}
		extra_main1(&st, argc);
		b = createt_stack();
		extra_main2(&st, &b);
	}
}
