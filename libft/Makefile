# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:58:55 by lpeeters          #+#    #+#              #
#    Updated: 2023/05/18 22:05:02 by lpeeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name (library)
NAME = libft.a

#make into library file
LIBC = ar rcs

#compiler
CC = gcc -g

#remove
RM = rm -rf

#flags
CFLAGS = -Wall -Wextra -Werror

#source files
SRCS = libftprintf/ft_lstiter.c \
       libftprintf/ft_printf_unsigned_int.c \
       libftprintf/ft_atoi.c \
       libftprintf/ft_isprint.c \
       libftprintf/ft_printf_number_hex.c \
       libftprintf/ft_putstr_fd.c \
       libftprintf/ft_strlen.c \
       libftprintf/ft_tolower.c \
       libftprintf/ft_isdigit.c \
       libftprintf/ft_strdup.c \
       libftprintf/ft_strjoin.c \
       libftprintf/ft_strtrim.c \
       libftprintf/ft_printf_int_decimal.c \
       libftprintf/ft_printf_ptr.c \
       libftprintf/ft_isalnum.c \
       libftprintf/ft_split.c \
       libftprintf/ft_memcmp.c \
       libftprintf/ft_strrchr.c \
       libftprintf/ft_itoa.c \
       libftprintf/ft_lstadd_front.c \
       libftprintf/ft_lstmap.c \
       libftprintf/ft_memset.c \
       libftprintf/ft_lstnew.c \
       libftprintf/ft_lstdelone.c \
       libftprintf/ft_lstsize.c \
       libftprintf/ft_strmapi.c \
       libftprintf/ft_strlcat.c \
       libftprintf/ft_memmove.c \
       libftprintf/free_array.c \
       libftprintf/ft_strlcpy.c \
       libftprintf/ft_calloc.c \
       libftprintf/ft_strncmp.c \
       libftprintf/ft_bzero.c \
       libftprintf/ft_putchar_fd.c \
       libftprintf/ft_putnbr_fd.c \
       libftprintf/ft_memcpy.c \
       libftprintf/ft_strchr.c \
       libftprintf/ft_strnstr.c \
       libftprintf/ft_lstadd_back.c \
       libftprintf/ft_isascii.c \
       libftprintf/ft_isalpha.c \
       libftprintf/ft_printf.c \
       libftprintf/ft_memchr.c \
       libftprintf/ft_putendl_fd.c \
       libftprintf/ft_toupper.c \
       libftprintf/ft_lstclear.c \
       libftprintf/ft_substr.c \
       libftprintf/ft_striteri.c \
       libftprintf/ft_lstlast.c \

#object directory
OBJ_DIR = OBJS/

#convert c files into object files
OBJS = ${SRCS:%.c=${OBJ_DIR}%.o}

#header file
HEADER = libft.h

#make directories for object files
MK_DIR = mkdir -p ${@D}

#make object files
${OBJ_DIR}%.o: %.c
	@${MK_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

#make project into library file
${NAME}: ${OBJS} ${HEADER}
	@${MK_DIR}
	@${LIBC} ${NAME} ${OBJS} ${HEADER}

#make
all: ${NAME}

#clean object files and directories
clean:
	@${RM} ${OBJ_DIR}

#clean everything that was made
fclean: clean
	@${RM} ${NAME}

#remake
re: fclean all

#targets
.PHONY: all clean fclean re
