# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 16:48:53 by jarumuga          #+#    #+#              #
#    Updated: 2024/07/30 22:27:59 by jarumuga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	$(SRCS_DIR)/ft_atoi.c \
		$(SRCS_DIR)/ft_bzero.c \
		$(SRCS_DIR)/ft_calloc.c \
		$(SRCS_DIR)/ft_isalnum.c \
		$(SRCS_DIR)/ft_isalpha.c \
		$(SRCS_DIR)/ft_isascii.c \
		$(SRCS_DIR)/ft_isdigit.c \
		$(SRCS_DIR)/ft_isprint.c \
		$(SRCS_DIR)/ft_itoa.c \
		$(SRCS_DIR)/ft_memchr.c \
		$(SRCS_DIR)/ft_memcmp.c \
		$(SRCS_DIR)/ft_memcpy.c \
		$(SRCS_DIR)/ft_memmove.c \
		$(SRCS_DIR)/ft_memset.c \
		$(SRCS_DIR)/ft_putchar_fd.c \
		$(SRCS_DIR)/ft_putendl_fd.c \
		$(SRCS_DIR)/ft_putnbr_fd.c \
		$(SRCS_DIR)/ft_putstr_fd.c \
		$(SRCS_DIR)/ft_split.c \
		$(SRCS_DIR)/ft_strchr.c \
		$(SRCS_DIR)/ft_strdup.c \
		$(SRCS_DIR)/ft_striteri.c \
		$(SRCS_DIR)/ft_strjoin.c \
		$(SRCS_DIR)/ft_strlcat.c \
		$(SRCS_DIR)/ft_strlcpy.c \
		$(SRCS_DIR)/ft_strlen.c \
		$(SRCS_DIR)/ft_strmapi.c \
		$(SRCS_DIR)/ft_strncmp.c \
		$(SRCS_DIR)/ft_strnstr.c \
		$(SRCS_DIR)/ft_strrchr.c \
		$(SRCS_DIR)/ft_strtrim.c \
		$(SRCS_DIR)/ft_substr.c \
		$(SRCS_DIR)/ft_tolower.c \
		$(SRCS_DIR)/ft_toupper.c \
		$(SRCS_DIR)/ft_lstnew.c \
		$(SRCS_DIR)/ft_lstadd_front.c \
		$(SRCS_DIR)/ft_lstsize.c \
		$(SRCS_DIR)/ft_lstlast.c \
		$(SRCS_DIR)/ft_lstadd_back.c \
		$(SRCS_DIR)/ft_lstdelone.c \
		$(SRCS_DIR)/ft_lstclear.c \
		$(SRCS_DIR)/ft_lstiter.c \
		$(SRCS_DIR)/ft_lstmap.c \
		$(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/ft_print_char.c \
		$(SRCS_DIR)/ft_print_str.c $(SRCS_DIR)/ft_print_int.c \
		$(SRCS_DIR)/ft_print_int_unsigned.c $(SRCS_DIR)/ft_print_ptr.c \
		$(SRCS_DIR)/ft_print_hex.c
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

