SRC_FILES = get_next_line.c get_next_line_utils.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES = get_next_line.h

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))
HDR_FILES = get_next_line_bonus.h

BUILD_DIR = .

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

.SECONDEXPANSION:
$(NAME): $$(SRC_FILES) $(HDR_FILES)
	$(CC) $(CFLAGS) -o $@ $^

bonus: SRC_FILES += $(SRC_BONUS)
bonus: HDR_FILES += $(HDR_BONUS)
bonus: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean reclean:
	rm -rf $(OBJ_FILES) $(OBJ_BONUS) 

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

rebonus: fclean bonus reclean

info:
	$(info $(SRC_FILES))
	$(info $(SRC_BONUS))

.PHONY: all fclean reclean re bonus rebonus info
