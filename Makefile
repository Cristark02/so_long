NAME			:=	So_Long

LIBMLX			:= libs/MLX42

LIBFT			:= libs/Libft+

HEADERS			:=	-I ${LIBMLX}/include/MLX42 -I ./include

LIBS			:=	${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

CC				:=	gcc

RM				=	rm -f

CFLAGS			:=	-Wall -Wextra -Werror -Wunreachable-code -Ofast

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

shell := /bin/zsh

ifdef DEBUG
	CC += -g
	MAKE += DEBUG=1
endif

ifdef LEAKS
	CC += -fsanitize=address 
	MAKE += LEAKS=1
endif

SRC				:=	src/main.c			\
					src/init.c			\
					src/file_check.c	\
					src/read_map.c		\
					src/map_check.c		\

OBJ				:=	${SRC:.c=.o}

%.o: %.c
	@echo "$(BLUE)$(BOLD)Compilando:$(MAGENTA)  ┈┈┈┈┈┈➤ $(RED)$(BOLD) $(notdir $<)$(RESET)" 
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

all:			libft libmlx ${NAME}
	@echo "$(GREEN)$(BOLD)\n◤◢◣◥◤◢◣◥ Juego Compilado ◤◢◣◥◤◢◣◥$(RESET)" | lolcat -a

libft:			
				@echo "$(YELLOW)$(BOLD)Compilando Libft$(MAGENTA)+$(RESET)"
				@${MAKE} -C ${LIBFT} | lolcat -t


libmlx:
				@echo "$(YELLOW)$(BOLD)\nCompilando Libreria MLX42$(RESET)"
				@${MAKE} -C ${LIBMLX} | lolcat -t
				@echo "$(GREEN)$(BOLD)\nLibrerias Terminada\n\n$(RESET)"
				@echo "$(YELLOW)$(BOLD)Compilando Juego$(RESET)"

${NAME}:		${OBJ}
				@${CC} ${OBJ} ${LIBS} -lglfw -L "/Users/mmita/.brew/opt/glfw/lib/" ${HEADERS} -o ${NAME}

clean:
				@${RM} ${OBJ}
				@echo "$(RED)$(BOLD)Limpiando ...\n$(RESET)"
				@${MAKE} -C ${LIBMLX} clean
				@${MAKE} -C ${LIBFT} clean

fclean:			clean
				@${MAKE} -C ${LIBMLX} fclean
				@${MAKE} -C ${LIBFT} fclean
				@echo "$(RED)$(BOLD)\nTodo Limpio\n$(RESET)"
				@${RM} ${NAME}

re:				fclean all

.PHONY:			${NAME} re clean fclean all libmlx libft leaks
