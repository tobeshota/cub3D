/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:47:11 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:32 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*ptr;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (NULL);
	ptr = result;
	while (lst->next != NULL)
	{
		lst = lst->next;
		ptr->next = ft_lstnew(f(lst->content));
		if (ptr->next == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ptr = ptr->next;
	}
	return (result);
}
