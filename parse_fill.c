/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:42:53 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/25 18:37:37 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit(char *str, t_stack *stacks)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	clear_list(stacks->a, free);
	clear_list(stacks->b, free);
	exit(1);
}

char	check_sep(char *st, t_stack *stacks)
{
	int		i;
	char	sep;

	i = 0;
	sep = '\0';
	while (st[i])
	{
		if (st[i] == ',' || st[i] == ';' || st[i] == ' ' || st[i] == '\f'
			|| st[i] == '\n' || st[i] == '\r' || st[i] == '\t' || st[i] == '\v')
		{
			if (sep != '\0' && sep != st[i])
				err_exit("Error", stacks);
			else
				sep = st[i];
		}
		else if (!(ft_isdigit(st[i]) || st[i] == '+' || st[i] == '-'))
			err_exit("Error", stacks);
		i++;
	}
	return (sep);
}

long	get_atoi(const char *s)
{
	int		i;
	int		neg;
	long	temp;

	i = 0;
	neg = 1;
	temp = 0;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			neg = -1;
	while (ft_isdigit(s[i]))
	{
		temp = temp * 10 + s[i] - 48;
		i++;
	}
	temp *= neg;
	return (temp);
}

void	intout_addnode(int *buff, long num, char **argv_i, t_stack *stacks)
{
	*buff = num;
	if (num > 2147483647 || num < -2147483648)
	{
		free(buff);
		free(argv_i);
		err_exit("Error", stacks);
	}
	node_add_back(stacks->a, buff);
}

int	parse_fill(char **argv, t_stack *stacks)
{
	int		*buff;
	int		i;
	int		j;
	char	**argv_i;
	long	num;

	i = 1;
	j = 0;
	while (argv[i])
	{
		argv_i = ft_split(argv[i], check_sep(argv[i], stacks));
		j = 0;
		while (argv_i[j])
		{
			num = get_atoi(argv_i[j++]);
			free(argv_i[j - 1]);
			buff = malloc(sizeof(int));
			if (NULL == buff)
				return (0);
			intout_addnode(buff, num, argv_i, stacks);
		}
		i++;
		free(argv_i);
	}
	return (1);
}
