#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_stack_node *a;
	t_stack_node *b;
	a = stack->a_top;
	b = stack->b_top;
	printf("stack a\tstack b\n");
	for(int i = 1; i < stack->total + 1; i++)
	{
		if (i < stack->cnt_a)
		{
			printf("%d", a->idx);
			a = a->next;
		}
		if (i < stack->cnt_b)
		{
			printf("\t%d", b->idx);
			b = b->next;
		}
		printf("\n");
	}
}

void cmd_test(t_stack *stack, t_archive **archive)
{
	(void)archive;
	static int	i;
	char		*cmd;
	// print_stack(stack);

	// t_stack_node *pop_node = pop(stack, A);
	// t_stack_node *push_node = push(stack, B, pop_node);
	// (void) pop_node;
	// (void) push_node;
	// (void) archive;
	// print_stack(stack);

	
	pb(stack, archive);
	print_stack(stack);
	pb(stack, archive);
	
	while(i < 8)
	{
		sleep(1);
		switch (i)
		{
		case SA:
			cmd = "SA";
			break;
		case SB:
			cmd = "SB";
			break;
		case RA:
			cmd = "RA";
			break;
		case RB:
			cmd = "RB";
			break;
		case RRA:
			cmd = "RRA";
			break;
		case RRB:
			cmd = "RRB";
			break;
		case PA:
			cmd = "PA";
			break;
		case PB:
			cmd = "PB";
			break;
		}
		printf("\n%d.===========%s============\n", i, cmd);
		ra(stack, archive);
		print_stack(stack);

		printf("\narchive\n");
		print_archive(*archive);
		printf("\n");
		i++;
	}

}
