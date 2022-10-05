NAME				:= philo_bonus

HEADER_PATH			:= ./includes_bonus
HEADER_FILES		:= philo_bonus.h internals_bonus.h

SOURCE_DIRS			:= . utils_bonus init_bonus error_bonus destroy_bonus time_bonus simulation_bonus
SOURCE_PATH			:= $(addprefix ./sources_bonus/, $(SOURCE_DIRS))
SOURCE_FILES		:= main_bonus.c
SOURCE_FILES		+= init_data_bonus.c init_philos_bonus.c
SOURCE_FILES		+= ft_atoi_bonus.c ft_isdigit_bonus.c ft_is_valid_number_str_bonus.c
SOURCE_FILES		+= ft_strcmp_bonus.c destroy_bonus.c
SOURCE_FILES		+= get_time_in_ms_bonus.c get_elapsed_time_bonus.c
SOURCE_FILES		+= simulation_bonus.c eat_bonus.c sleep_bonus.c think_bonus.c die_bonus.c
SOURCE_FILES		+= thread_utils_bonus.c

OBJECT_PATH			:= ./objects_bonus
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
IFLAGS				:= -I $(HEADER_PATH)
LDFLAGS				:= -pthread
REMOVE				:= rm -rf
VALGRIND			:= valgrind
VGFLAGS				:= --leak-check=full --show-leak-kinds=all
ARGV				:= 5 800 200 200 7

vpath				%.c $(SOURCE_PATH)
vpath				%.h $(HEADER_PATH)

ifdef DEBUG
	CFLAGS += -g3
endif

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

.PHONY:				all clean fclean re run vg
