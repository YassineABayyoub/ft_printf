NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c ft_putchar.c ft_putnbr.c ft_puthex.c ft_putptr.c
OBJS		= $(SRCS:.c=.o)

BONUS_DIR	= bonus
BONUS_SRCS	= $(BONUS_DIR)/ft_printf_bonus.c \
			  $(BONUS_DIR)/check_format_bonus.c \
			  $(BONUS_DIR)/parse_functions_bonus.c \
			  $(BONUS_DIR)/ft_numutils_bonus.c \
			  $(BONUS_DIR)/ft_putnumber_bonus.c \
			  $(BONUS_DIR)/ft_putnbr_bonus.c \
			  $(BONUS_DIR)/ft_putptr_bonus.c \
			  $(BONUS_DIR)/ft_putstr_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): .mandatory

.mandatory: $(OBJS)
	@rm -f $(NAME) .bonus
	ar rcs $(NAME) $(OBJS)
	@touch .mandatory

bonus: .bonus

.bonus: $(BONUS_OBJS)
	@rm -f $(NAME) .mandatory
	ar rcs $(NAME) $(BONUS_OBJS)
	@touch .bonus

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/ft_printf_bonus.h
	$(CC) $(CFLAGS) -I$(BONUS_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) .bonus .mandatory

re: fclean all

.PHONY: all bonus clean fclean re
