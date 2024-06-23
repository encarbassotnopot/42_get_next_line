SRC_FILES = get_next_line.c get_next_line_utils.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES = get_next_line.h

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))
HDR_FILES = get_next_line_bonus.h

SRC_TEST = $(wildcard $(TEST_DIR)/*.c)
OBJ_TEST = $(patsubst %.c,%.o,$(SRC_TEST))
TEST_DIR = tests

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

all: $(NAME) Makefile

.SECONDEXPANSION:
$(NAME): main.c $$(SRC_FILES) $(HDR_FILES)
	$(CC) $(CFLAGS) -o $@ $^

bonus: SRC_FILES += $(SRC_BONUS)
bonus: HDR_FILES += $(HDR_BONUS)
bonus: all

test: CFLAGS += -fsanitize=address
test: all tests.o Makefile

tests.o: $(OBJ_TEST) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean reclean:
	rm -rf $(OBJ_FILES) $(OBJ_BONUS) 

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

rebonus: fclean bonus reclean

info:
	$(info $(SRC_FILES))
	$(info $(SRC_BONUS))

.PHONY: all fclean reclean re bonus rebonus info test
