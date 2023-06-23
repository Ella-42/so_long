# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:49:34 by lpeeters          #+#    #+#              #
#    Updated: 2023/06/21 10:29:02 by lpeeters         ###   ########.fr        #
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

#minilibx flags
MLXFLAGS = -L /usr/lib -l Xext -l X11 -l m -l z

#redirect output to /dev/null to silence it
OUT = > /dev/null 2> /dev/null

#find sources
SRCS = ${shell find . -name "*.c" -not -path "*lib*" -a -not -path "*mlx*"}

#header file
HEADER = ${shell find . -name "*.h" -not -path "*lib*" -a -not -path "*mlx*"}

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
MKFL_ALL = ${foreach mkfldir,${MKFL_DIRS}, make -C ${mkfldir} ${OUT} ;}

#make
all: MK ${NAME}

#make project into program
${NAME}:${SRCS} ${HEADER}
	@${CC} ${CFLAGS} ${SRCS} ${HEADER} ${LIB_ALL} ${MLXFLAGS} -o ${NAME}
	@chmod +x ${NAME}

#make library
MK:
	@${MKFL_ALL}

#clean object files and directories
clean:
	@${foreach mkfldir,${MKFL_DIRS}, make -C ${mkfldir} fclean ${OUT} ;}

#clean everything that was made
fclean: clean
	@${RM} ${NAME}

#remake
re: fclean all

#targets
.PHONY: all clean fclean re MK
