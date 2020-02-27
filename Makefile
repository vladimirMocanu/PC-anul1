CC=gcc
TARGET=telefon
CFLAG = -Wall
EX=telefon.c


build: $(TARGET)

$(TARGET): $(EX)
	$(CC) $(CFLAG) $(EX) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f *.o $(TARGET) *~

valgrind:
	valgrind --tool=memcheck --leak-check=full ./$(TARGET)


