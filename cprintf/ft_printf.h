/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:46:17 by lbespin           #+#    #+#             */
/*   Updated: 2021/06/01 18:32:21 by lbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define ZEROPAD 1
# define LEFT 2
# define SIGN 4

typedef struct s_flags
{
	char	*fmt;
	va_list	arg;
	int		res;
	int		flags;
	int		width;
	int		precision;
	int		err;
	int		fd;
	char	ch;
}	t_flag;

int		ft_printf(const char *fmt, ...);
void	ft_parser(t_flag *params);
void	ft_print_p(t_flag *params);
void	ft_print_c(t_flag *params);
void	ft_print_s(t_flag *params);
void	ft_print_d(t_flag *params);
void	ft_print_u(t_flag *params);
int		ft_print_x(t_flag *params);
int		ft_processing(t_flag *params);
void	ft_init_params(t_flag *params);
void	ft_print(t_flag *params);

#endif
