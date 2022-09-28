NAME				:= philo

HEADER_PATH			:= ./includes
HEADER_FILES		:= philo.h internals.h

SOURCE_DIRS			:= . utils init error destroy time simulation
SOURCE_PATH			:= $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= main.c
SOURCE_FILES		+= init_data.c init_forks.c init_philos.c
SOURCE_FILES		+= ft_atoi.c ft_isdigit.c ft_is_valid_number_str.c
SOURCE_FILES		+= destroy.c
SOURCE_FILES		+= get_time_in_ms.c get_elapsed_time.c mssleep.c
SOURCE_FILES		+= simulation.c routine.c mutex.c actions.c eat.c

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -g3 -Wall -Wextra -Werror
IFLAGS				:= -I $(HEADER_PATH)
LDFLAGS				:= -pthread
REMOVE				:= rm -rf
VALGRIND			:= valgrind
VGFLAGS				:= --leak-check=full --show-leak-kinds=all
ARGV				:= 2 800 200 200 3

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

run:				all
					./$(NAME) $(ARGV)

vg:					all
					$(VALGRIND) $(VGFLAGS) ./$(NAME) $(ARGV)

test:
					bash test.sh

.PHONY:				all clean fclean re run vg
