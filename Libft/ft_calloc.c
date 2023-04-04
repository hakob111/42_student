/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:56:41 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 18:56:47 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;
	size_t	size1;

	size1 = nitems * size;
	if (!nitems || !size)
		return (malloc(0));
	if (size1 / nitems < size || size1 / size < nitems)
		return (NULL);
	res = (void *)malloc (nitems * size);
	if (!res)
		return (0);
	ft_bzero(res, nitems * size);
	return ((void *)res);
}
