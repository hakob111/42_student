/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:42:39 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/08 20:42:41 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*copy;

	copy = lst;
	if (!lst || !f)
		return ;
	while (copy != NULL)
	{
		f(copy->content);
		copy = copy->next;
	}
}
