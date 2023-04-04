/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:22:53 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/07 00:24:42 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_list1;

	t_list1 = (t_list *)malloc(sizeof(t_list));
	if (!t_list1)
		return (t_list1 = NULL);
	t_list1->next = 0;
	t_list1->content = content;
	return (t_list1);
}
