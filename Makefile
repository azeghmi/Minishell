# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 18:38:58 by azeghmi           #+#    #+#              #
#    Updated: 2019/10/12 15:40:32 by azeghmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		=	minishell

#######   DIRECTORIES   #######
HDR			=	include
SRCDIR		=	srcs
OBJDIR		=	obj

DIRS := $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(shell find $(SRCDIR) -type d))

##########   FLAGS   ##########
CFLAGS		=	-Wall						\
				-Wextra						\
				-Werror						\
				-msse4
				-g3					\
				-fsanitize=address

INCFLAG		=	-I $(HDR)

#########   SOURCES   #########
SRCS		=	$(shell find $(SRCDIR) -type f -name "*.c")

OBJS		=	$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

DEPENDS		=	${OBJS:.o=.d}

#########   COLORS   ##########
STD			=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

##########   RULES   ##########
all			: $(NAME)

$(NAME)		: $(OBJS)
	@printf "$(YELLOW)%-45s$(STD)" "Building executable $@ ..."
	@$(CC) $(CFLAGS) $(INCFLAG) $(OBJS) -o $@
	@echo "$(GREEN)DONE$(STD)"

-include $(DEPENDS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(DIRS)
	@printf "%-45s" " > Compiling $* ..."
	@$(CC) $(CFLAGS) -MMD $(INCFLAG) -c $< -o $@
	@echo '✓'

clean		:
	@/bin/rm -rf $(OBJDIR)

fclean		: clean
	@/bin/rm -rf $(NAME)

re			: fclean all

.PHONY		: all $(LIBFT) clean fclean re
