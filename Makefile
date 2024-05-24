SRCS =  main.c\
		$(addprefix parsing/,pars.c\
							recup_text.c\
							recup_colors.c\
							recup_col2.c\
							recup_map.c\
							check_map.c\
							pars_utils.c)\
		$(addprefix utils/, parsing_utils.c\
							parsing_utils2.c)\
					


OBJS = $(SRCS:.c=.o)
NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -O3 -g3 #-fsanitize=leak
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
RM = rm -rf
LIBFT = ./libft

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

YEL = \033[38;5;220m
ORANGE = \033[38;5;216m
BLEU =  \033[38;5;27m 
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
RED1 = \033[38;5;196m
GREEN1 =\033[38;5;46m
GREEN = \033[38;5;85m

FICH_COUNT = 0
NBR_TOT_FICHIER = 9
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}



${MAIN_PATH}%.o:%.c 
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -Lmlx_linux -lmlx_Linux -L$(MINILIBX_DIR) -Imlx_linux -lXext -lX11 -lm -lz -c -I . $< -o ${<:.c=.o}
	@echo ""
	@echo " ${GRAS}${RED1}-> COMPILATION EN COURS${RESET}${GRAS}${YEL}[CUBE_3D]${RESET}"
	@printf " ${RED1}${GRAS}[${YEL}%-23.${BAR}s${RED1}] [%d/%d (%d%%)]${RESET}" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER}
	@echo "${UP}${UP}${UP}"

all : ${NAME}


${NAME}: ${OBJS}
	@${MAKE} --silent -C ${LIBFT}/
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT}/libft.a -o ${NAME} ${FLAGSMLX}
	@echo "\n\n\n ${GRAS}${RED1}CUBE_3D EST COMPILÉ 👏${RESET}\n"
	
clean:

	@${MAKE} --silent clean -C ${LIBFT}
	@${RM}  ${OBJS} 
	@echo "${GREEN1}${GRAS}\tNETTOYAGE 🛁${RESET}"
	@echo "${BLEU}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean: clean
	@${RM} ${NAME} ${LIBFT}/libft.a
	@echo "${BLEU}${ITALIQUE} -libft.a est supprimé${RESET}"
	@echo "${BLEU}${ITALIQUE} -${NAME} est supprimê${RESET}"

re: fclean all

.PHONY: all clean fclean re
