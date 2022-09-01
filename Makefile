NAME				:= philo

HEADER_PATH			:= ./includes
HEADER_FILES		:= philo.h

SOURCE_PATH			:= ./sources
SOURCE_FILES		:= main.c

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -g3 -Wall -Wextra -Werror
IFLAGS				:= -I $(HEADER_PATH)
LDFLAGS				:= -pthread
REMOVE				:= rm -rf

vpath				%.c $(SOURCE_PATH)
vpath				%.h $(HEADER_PATH)

all:				$(NAME)

$(NAME):			$(OBJECT_FILES)
					$(CC) $(CFLAGS) -o $@ $(OBJECT_FILES) $(LDFLAGS)

$(OBJECT_PATH)/%.o:	%.c $(HEADER_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
					mkdir -p $@

clean:
					$(REMOVE) $(OBJECT_PATH)

fclean:				clean
					$(REMOVE) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
