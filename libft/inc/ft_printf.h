/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:59:09 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 14:59:39 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_flags
{
	int	min_field_width;
	int	precision;
	int	args;
	int	sign;
	int	minus_flag;
	int	zero_flag;
	int	sharp_flag;
	int	space_flag;
	int	plus_flag;
}		t_flags;

int		ft_printf(const char *format, ...);
void	ft_abs_address(long *n);
long	ft_abs_value(long n);
int		strlen_upto_per(const char *str);
void	reassign_flags_precision(t_flags *flags);
int		is_flag(int c);
int		is_min_field_width(int c);
int		is_precision(const char *c);
int		is_conversion(char c);
int		is_number_conversion(char c);
void	get_int_flag(long *lnb, t_flags *flags);
void	get_unsigned_flag(unsigned int *unb, t_flags *flags);
void	get_hexnum_lowercase_flag(unsigned int *unb, t_flags *flags);
void	get_hexnum_uppercase_flag(unsigned int *unb, t_flags *flags);
void	get_space_len_in_str(t_flags *flags);
void	get_space_len_in_int(t_flags *flags, long lnb);
void	get_args_output_len(t_flags *flags);
void	get_zero_len(t_flags *flags);
void	get_sign(int n, t_flags *flags);
void	get_nbrlen_base(unsigned long long ullnb, char *base, t_flags *flags);
void	put_char(char c, t_flags *flags, int *written_len);
void	put_str(char *str, t_flags *flags, int *written_len);
void	put_ptr(void *ptr, t_flags *flags, int *written_len);
void	put_percent(int *written_len, t_flags *flags);
void	put_int(int n, t_flags *flags, int *written_len);
void	ft_putlnb_fd(long lnb, int fd);
void	put_unsinged(unsigned int unb, t_flags *flags, int *written_len);
void	put_hexnum_lowercase(unsigned int unb, t_flags *flags,
			int *written_len);
void	put_hexnum_uppercase(unsigned int unb, t_flags *flags,
			int *written_len);
ssize_t	put(int fd, const void *buf, size_t count);
int		put_space(int num);
void	put_zero(int num);
int		put_sign(t_flags *flags);
void	ft_putnbr_base(unsigned long long nb, char *base);
void	printf_str(const char **format, int *written_len);
void	proc_conversion(const char **format, va_list args, t_flags *flags,
			int *written_len);
void	proc_flag(const char **format, t_flags *flags);
void	proc_min_field_width(const char **format, va_list args, t_flags *flags);
void	proc_precision(const char **format, va_list args, t_flags *flags);
void	proc_output_conversions(const char **format, va_list args,
			t_flags *flags, int *written_len);
#endif
