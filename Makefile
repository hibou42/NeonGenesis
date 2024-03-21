#***** Name *****#

NAME			= NeonGenesis

#***** Sources / Objs *****#

SRC				=	main.cpp \
					srcs/Weapon.cpp \
					srcs/Resource.cpp \
					srcs/Player.cpp 
					#srcs/Farm.cpp \
					#srcs/Forge.cpp \
					#srcs/House.cpp

OBJ_DIR			= obj
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

#***** SFML *****#
#Windows by default
SFML_LIB		=	./sfml/Windows.SFML-2.6.1
SFML_FLAG		=	-L${SFML_LIB}/lib -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(shell uname), Linux)
SFML_LIB		=	./sfml/Linux.SFML-2.6.1
SFML_FLAG		=	-L${SFML_LIB}/lib -lsfml-graphics -lsfml-window -lsfml-system
endif

#***** Couleurs *****#

GREEN		=	\033[1;32m
BG_GREEN	=	\033[42m
BLUE		=	\033[0;94m
RED			=	\033[1;31m
GREY		=	\033[0;37m
ENDCOLOR	=	\033[0m

#***** Textes *****#

START_TXT		=	echo "$(GREEN)Compilation of $(NAME) just started$(ENDCOLOR)"
TEST_TXT		=	echo "$(GREY)Running some test$(ENDCOLOR)\n"
END_COMP_TXT	=	echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=	echo "$(RED)Deleting objects$(ENDCOLOR)"
FCLEAN_TXT		=	echo "$(RED)Deleting program$(ENDCOLOR)"
END_TXT			=	echo "$(GREEN)Cleaning succes$(ENDCOLOR)"
BS_N_TXT		=	echo "\n"

#***** Message compilation *****#

TOTAL_FILES		=	$(words $(SRC))
COMPILED_FILE	=	0
MESSAGE			=	"Compilation en cours : $(COMPILED_FILES)/$(TOTAL_FILES) ($(shell expr $(COMPILED_FILES) \* 100 / $(TOTAL_FILES))%)"

#***** Flags *****#

CXX				=	c++
CXXFLAGS		=	-Wall -g -I$(SFML_LIB)/include
#CXXFLAGS		+=	-Wextra -Werror -std=c++11 -g
RM				=	rm -f


#***** Compilation *****#

all : logo start $(NAME)

logo :
		@tput setaf 2; cat ascii_art/hibou; tput setaf default
		@$(BS_N_TXT)

start:
		@tput setaf 2; cat ascii_art/logo; tput setaf default
		@$(BS_N_TXT)
		@$(START_TXT)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
		@mkdir -p $(dir $@)
		@$(CXX) $(CXXFLAGS) -c $< -o $@
		$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
		@printf "$(GREEN)%s$(ENDCOLOR)" $(MESSAGE)
		@printf "\r"

$(NAME) :	${OBJS}
		@$(BS_N_TXT)
		@${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${SFML_FLAG} -Wl,-rpath,$(SFML_LIB)/lib
		@$(END_COMP_TXT)
		@tput setaf 2; cat ascii_art/small_hibou1; tput setaf default

#***** Clean *****#

clean:
		@$(CLEAN_TXT)
		@${RM} ${OBJS}
		@$(RM) -r $(OBJ_DIR)
		@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean:		clean
		@$(FCLEAN_TXT)
		@${RM} ${NAME}
		@$(END_TXT)

re:		fclean all

.PHONY:	all clean fclean 