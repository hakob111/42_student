/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:29:25 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/07 18:29:27 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*copy;
	int		len;

	len = 0;
	copy = lst;
	if (!copy)
		return (0);
	while (copy != NULL)
	{
		len++;
		copy = copy->next;
	}
	return (len);
}

/*
int main() {
  char *cony = "hello";
  t_list  *elem = (t_list *)malloc(sizeof(t_list));
  t_list  *elem1 = (t_list *)malloc(sizeof(t_list));
  t_list  *elem2= (t_list *)malloc(sizeof(t_list));
  t_list  *elem3= (t_list *)malloc(sizeof(t_list));
  (*elem).next = elem1;
  (*elem1).next = elem2;
  (*elem2).next = elem3;
  (*elem3).next = NULL;
  
  elem->content = cony;
  elem1->content = cony;
  elem3->content = cony;
  elem2->content = cony;
  
  printf("%d", ft_lstsize(elem1));
  

  return 0;
}
*/