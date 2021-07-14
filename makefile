obj = main.o

%.o: %.cpp
	g++ -c $< -o $@

all: $(obj)
	g++ $^ -o app -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -rf *.o
	rm -rf app