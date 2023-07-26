# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:49:34 by lpeeters          #+#    #+#              #
#    Updated: 2023/07/26 21:26:43 by lpeeters         ###   ########.fr        #
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
MKFL = ${shell find . -mindepth 2 \( -name "Makefile" -o -name "makefile" \) -not -path "*test*"}

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

#valgrind with flags
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s ./so_long

#automatically test the maps for memory leaks
val: all
	reset ; \
	echo "\n==========ALGORITHM TEST EASY==========\n" ; ${VALGRIND} maps/algorithm_test_easy.ber ; \
	echo "\n==========ALGORITHM TEST MEDIUM==========\n" ; ${VALGRIND} maps/algorithm_test_medium.ber ; \
	echo "\n==========ALGORITHM TEST HARD==========\n" ; ${VALGRIND} maps/algorithm_test_hard.ber ; \
	echo "\n==========ALGORITHM TEST ADVANCED==========\n" ; ${VALGRIND} maps/algorithm_test_advanced.ber ; \
	echo "\n==========SMALL==========\n" ; ${VALGRIND} maps/small.ber ; \
	echo "\n==========MAYHEM==========\n" ; ${VALGRIND} maps/mayhem.ber ; \
	echo "\n==========BIG==========\n" ; ${VALGRIND} maps/big.ber ; \
	echo "\n==========INVALID SMALL==========\n" ; ${VALGRIND} maps/invalid_small.ber ; \
	echo "\n==========INVALID BIG==========\n" ; ${VALGRIND} maps/invalid_big.ber ; \
	echo "\n==========INVALID EMPTY==========\n" ; ${VALGRIND} maps/invalid_empty.ber ; \
	echo "\n==========INVALID MISSING ITEMS==========\n" ; ${VALGRIND} maps/invalid_missing_items.ber ; \
	echo "\n==========INVALID TOO MANY ITEMS==========\n" ; ${VALGRIND} maps/invalid_too_many_items.ber ; \
	echo "\n==========INVALID CHARACTERS==========\n" ; ${VALGRIND} maps/invalid_chars.ber ; \
	echo "\n==========INVALID UNINCLOSED==========\n" ; ${VALGRIND} maps/invalid_uninclosed.ber ; \
	echo "\n==========INVALID RECTANGLE==========\n" ; ${VALGRIND} maps/invalid_rectangle.ber ; \
	echo "\n==========INVALID EXTENSION NONE==========\n" ; ${VALGRIND} maps/invalid_extension_none ; \
	echo "\n==========INVALID EXTENSION DOT==========\n" ; ${VALGRIND} maps/invalid_extension_dot. ; \
	echo "\n==========INVALID EXTENSION DOUBLE DOTS==========\n" ; ${VALGRIND} maps/invalid_extension.double.dots ; \
	echo "\n==========INVALID EXTENSION FILETYPE==========\n" ; ${VALGRIND} maps/invalid_extension_filetype.txt

#automatically test the maps
test: all
	reset ; \
	echo "\n==========ALGORITHM TEST EASY==========\n" ; ./so_long maps/algorithm_test_easy.ber ; \
	echo "\n==========ALGORITHM TEST MEDIUM==========\n" ; ./so_long maps/algorithm_test_medium.ber ; \
	echo "\n==========ALGORITHM TEST HARD==========\n" ; ./so_long maps/algorithm_test_hard.ber ; \
	echo "\n==========ALGORITHM TEST ADVANCED==========\n" ; ./so_long maps/algorithm_test_advanced.ber ; \
	echo "\n==========SMALL==========\n" ; ./so_long maps/small.ber ; \
	echo "\n==========MAYHEM==========\n" ; ./so_long maps/mayhem.ber ; \
	echo "\n==========BIG==========\n" ; ./so_long maps/big.ber ; \
	echo "\n==========INVALID SMALL==========\n" ; ./so_long maps/invalid_small.ber ; \
	echo "\n==========INVALID BIG==========\n" ; ./so_long maps/invalid_big.ber ; \
	echo "\n==========INVALID EMPTY==========\n" ; ./so_long maps/invalid_empty.ber ; \
	echo "\n==========INVALID MISSING ITEMS==========\n" ; ./so_long maps/invalid_missing_items.ber ; \
	echo "\n==========INVALID TOO MANY ITEMS==========\n" ; ./so_long maps/invalid_too_many_items.ber ; \
	echo "\n==========INVALID CHARACTERS==========\n" ; ./so_long maps/invalid_chars.ber ; \
	echo "\n==========INVALID UNINCLOSED==========\n" ; ./so_long maps/invalid_uninclosed.ber ; \
	echo "\n==========INVALID RECTANGLE==========\n" ; ./so_long maps/invalid_rectangle.ber ; \
	echo "\n==========INVALID EXTENSION NONE==========\n" ; ./so_long maps/invalid_extension_none ; \
	echo "\n==========INVALID EXTENSION DOT==========\n" ; ./so_long maps/invalid_extension_dot. ; \
	echo "\n==========INVALID EXTENSION DOUBLE DOTS==========\n" ; ./so_long maps/invalid_extension.double.dots ; \
	echo "\n==========INVALID EXTENSION FILETYPE==========\n" ; ./so_long maps/invalid_extension_filetype.txt

#targets
.PHONY: all clean fclean re MK val test
