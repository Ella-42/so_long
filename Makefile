# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:49:34 by lpeeters          #+#    #+#              #
#    Updated: 2023/06/05 15:52:58 by lpeeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = so_long

#compiler
CC = gcc -g

#remove
RM = rm -rf

#flags
CFLAGS = -Wall -Wextra -Werror

#find sources
SRCS = ${shell find . -name "*.c" -not -path "*lib*"}

#header file
HEADER = ${shell find . -name "*.h" -not -path "*lib*"}

#find other makefiles
MKFL = ${shell find . -mindepth 2 -name "Makefile" -o -name "makefile"}

#find library files
LIBS = ${shell find . -name "*.a"}

#fetch makefile directory
MKFL_DIRS = ${dir ${MKFL}}

#fetch library directory
LIB_DIRS = ${dir ${LIBS}}

#fetch library filename
LIB_PNAMES = ${notdir ${LIBS}} #cut off the path
LIB_LNAMES = ${LIB_PNAMES:lib%.a=%} #cut off the library files' "lib" prefix
LIB_NAMES = ${LIB_LNAMES:.a=} #cut off the library files' ".a" suffix

#compilation flags, their directories and names for any library
LIB_ALL = ${foreach libdir,${LIB_DIRS},-L ${libdir}} \
	  ${foreach libname,${LIB_NAMES},-l ${libname}}

#make other projects that were found
MKFL_ALL = ${foreach mkfldir,${MKFL_DIRS}, make -C ${mkfldir}}

#make
all: MK ${NAME}

#make project into program
${NAME}:${SRCS} ${HEADER}
	${CC} ${CFLAGS} ${SRCS} ${HEADER} ${LIB_ALL} -o ${NAME}
	chmod +x ${NAME}

#make library
MK:
	${MKFL_ALL}

#clean object files and directories
clean:
	${foreach mkfldir,${MKFL_DIRS}, make -C ${mkfldir} fclean}

#clean everything that was made
fclean: clean
	${RM} ${NAME}

#remake
re: fclean all

#targets
.PHONY: all clean fclean re MK
