/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:58:30 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:01:18 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	new;

// 	head = malloc(sizeof(t_list));
// 	if (head == NULL)
// 		return (0);
// 	head->content = "head_content";
// 	head->next = NULL;
// 	new.content = "new_content";
// 	new.next = NULL;
// 	printf("before: %s\n", head->content);
// 	ft_lstadd_front(&head, &new);
// 	printf("afeter: %s\n", head->content);
// 	return (0);
// }
