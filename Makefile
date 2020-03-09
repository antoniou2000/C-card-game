OBJS = cards.o GameBoard.o Player_deck.o Player_impl.o Player_interface.o main.o

PROGRAM = prog

$(PROGRAM): clean $(OBJS)
		g++ $(OBJS) -o $(PROGRAM)

clean:
		rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
		./$(PROGRAM)
