/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:37:05 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/08 19:37:07 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;
	t_list	*to_free;

	if (!del || lst == NULL || *lst == NULL)
		return ;
	copy = *lst;
	while (copy != NULL)
	{
		to_free = copy->next;
		ft_lstdelone(copy, del);
		copy = to_free;
	}
	*lst = NULL;
}
