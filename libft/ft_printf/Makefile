# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 19:52:48 by toshota           #+#    #+#              #
#    Updated: 2023/10/21 12:54:59 by toshota          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -rf
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
INC_DIR		=	../inc/
SRCS		=	srcs/ft_abs_address.c srcs/ft_abs_value.c srcs/ft_printf.c \
				srcs/ft_putlnb_fd.c srcs/ft_putnbr_base.c srcs/get_args_output_len.c \
				srcs/get_hexnum_lowercase_flag.c srcs/get_hexnum_uppercase_flag.c \
				srcs/get_int_flag.c srcs/get_nbrlen_base.c srcs/get_sign.c \
				srcs/get_space_len_in_int.c srcs/get_space_len_in_str.c \
				srcs/get_unsigned_flag.c srcs/get_zero_len.c srcs/is_conversion.c \
				srcs/is_flag.c srcs/is_min_field_width.c srcs/is_number_conversion.c \
				srcs/is_precision.c srcs/printf_str.c srcs/proc_conversion.c srcs/proc_flag.c \
				srcs/proc_min_field_width.c srcs/proc_output_conversions.c \
				srcs/proc_precision.c srcs/put.c srcs/put_char.c srcs/put_hexnum_lowercase.c \
				srcs/put_hexnum_uppercase.c srcs/put_int.c srcs/put_percent.c srcs/put_ptr.c \
				srcs/put_sign.c srcs/put_space.c srcs/put_str.c srcs/put_unsinged.c \
				srcs/put_zero.c srcs/reassign_flags_precision.c srcs/strlen_upto_per.c
OBJS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))



all:		$(NAME)

$(NAME):	$(OBJS)
	@ $(AR) $(NAME) $(OBJS)

bonus:		all

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@ $(RM) $(OBJS_DIR)

fclean:		clean
	@ $(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
