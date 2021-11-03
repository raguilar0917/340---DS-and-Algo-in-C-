CFLAGS = -std=c++11
CC = g++
listtest: aClient.o PrecondViolatedExcept.o
	$(CC) $(CFLAGS) -o listtest aClient.o PrecondViolatedExcept.o
aClient.o: aClient.cpp
	$(CC) $(CFLAGS) -c aClient.cpp
PrecondViolatedExcept.o: PrecondViolatedExcept.cpp
	$(CC) $(CFLAGS) -c PrecondViolatedExcept.cpp
clean:
	rm -f core *.o
