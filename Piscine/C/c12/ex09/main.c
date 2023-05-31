/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:04:54 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/05/31 09:53:51 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_mult_by3(void *data)
{
	*(int *)data *= 3;
}

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;		

	return (elem);
}

void    ft_print_list(t_list *list)
{
	t_list	*current = list;
	
    while (current != NULL)
    {
		printf("%p/", current);
        printf("%i -> ", *(int*)current->data);
        printf("%p\n", current->next);
        current = current->next;
    }
}

int    main(void)
{
    t_list	*linked_list = malloc(sizeof(t_list));
    int    	n1 = 1;
	int		n2 = 2;
	int		n3 = 3;
	int		n4 = 4;
	int		n5 = 5;

	linked_list = ft_create_elem(&n1);
	linked_list->next = ft_create_elem(&n2);
	linked_list->next->next = ft_create_elem(&n3);
	linked_list->next->next->next = ft_create_elem(&n4);
	linked_list->next->next->next->next = ft_create_elem(&n5);
		
	printf("Original list:\n");
	ft_print_list(linked_list);

	ft_list_foreach(linked_list, &ft_mult_by3);
	
	printf("Reversed list:\n");
	ft_print_list(linked_list);
	
	free(linked_list);
}