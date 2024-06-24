#!/bin/sh
for i in {0..100};
	do cc -Wall -Wextra -Werror -g -I. -o get_next_line main.c get_next_line.c get_next_line_utils.c get_next_line_bonus.h -D BUFFER_SIZE=$i \
	&& ./get_next_line testfile.txt;
done
