NAME = keyboard
SRC = *.cpp -g
FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	g++ -g $(SRC) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean name