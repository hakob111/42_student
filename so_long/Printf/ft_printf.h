/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:18:29 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/19 17:18:31 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printhex(unsigned int n, int charnum);
int	ft_printint(int n);
int	ft_printpointer(unsigned long long c);
int	ft_printstring(char *str);
int	ft_printunsig(unsigned int n);
int	ft_printf(const char *str, ...);

#endif
