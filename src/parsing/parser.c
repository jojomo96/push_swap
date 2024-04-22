/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:18:54 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 23:13:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_handle_error(char *message, char **split)
{
	ft_free_split(split);
	ft_error(message);
}

void	ft_replace_value_by_index(t_dlist *list, t_dlist *index_list)
{
	t_dlist_node	*node;
	int				*value;
	int				index;
	int				i;

	i = 0;
	node = list->head;
	while (node)
	{
		value = (int *)node->content;
		index = (int)ft_dlist_index_of(index_list, value, ft_int_cmp);
		*value = index;
		node = node->next;
		i++;
	}
}

void	process_split_strings(t_dlist *list, char **split)
{
	int				j;
	int				*value;
	t_dlist_node	*node;

	j = 0;
	while (split[j])
	{
		if (!ft_isnumber(split[j]))
			ft_handle_error("Invalid number format", split);
		value = malloc(sizeof(int));
		if (!value)
			ft_handle_error("Memory allocation failed for integer", split);
		*value = ft_atoi(split[j]);
		node = ft_dlist_new_node(value);
		if (!ft_dlist_append_unique(list, node, ft_int_cmp))
		{
			free(value);
			free(node);
			ft_handle_error("Duplicate value or append failed", split);
		}
		j++;
	}
}

void	ft_parse_input(t_dlist *list, char **argv)
{
	int		i;
	char	**split;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error("Memory allocation failed for split");
		if (!split[0])
			ft_handle_error("Empty string", split);
		process_split_strings(list, split);
		ft_free_split(split);
		i++;
	}
	ft_replace_value_by_index(list, ft_dlist_sort_copy(list, ft_int_cmp));
}
