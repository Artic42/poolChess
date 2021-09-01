#Constant definitions

CC = gcc
CFLAGSR = -Wall -lncurses
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFLAGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -ISource

#Path to diferent modules

Binaries = bin
Sources = Source
Headers = Source/Header

OBJECTS = $(Binaries)/DataInit.o $(Binaries)/DataRead.o $(Binaries)/InitialDraw.o $(Binaries)/PieceDraw.o
OBJECTS_D = $(Binaries)/DataInit_D.o $(Binaries)/DataRead_D.o $(Binaries)/InitialDraw_D.o $(Binaries)/PieceDraw_D.o
#default make file, makes the full application

$(Binaries)/PoolChess.app: $(Sources)/poolChess.c $(Sources)/poolChess.h $(OBJECTS)
	@$(CC) $(CFLAGSR) $(IPATH) $(Sources)/poolChess.c $(OBJECTS) -o $(Binaries)/PoolChess.app

$(Binaries)/PoolChessDebug.app: $(Sources)/poolChess.c $(Sources)/poolChess.h $(OBJECTS_D)
	@$(CC) $(CFLAGSD) $(IPATH) $(Sources)/poolChess.c $(OBJECTS_D) -o $(Binaries)/PoolChessDebug.app

#Subordinate objects of the application Heimdallr for Debug

$(Binaries)/DataInit_D.o: $(Sources)/dtInitialize.c $(Sources)/dtInitialize.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/dtInitialize.c -o $(Binaries)/DataInit_D.o

$(Binaries)/DataRead_D.o: $(Sources)/dtRead.c $(Sources)/dtRead.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/dtRead.c -o $(Binaries)/DataRead_D.o

$(Binaries)/InitialDraw_D.o: $(Sources)/scInitialDraw.c $(Sources)/scInitialDraw.h $(Sources)/scColors.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/scInitialDraw.c -o $(Binaries)/InitialDraw_D.o

$(Binaries)/PieceDraw_D.o: $(Sources)/scPieceDraw.c $(Sources)/scPieceDraw.h $(Sources)/scColors.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/scPieceDraw.c -o $(Binaries)/PieceDraw_D.o

#Subordinate objects of the application Heimdallr for realease 

$(Binaries)/DataInit.o: $(Sources)/dtInitialize.c $(Sources)/dtInitialize.h
	@$(CC) $(OFLAGSR) $(IPATH) $(Sources)/dtInitialize.c -o $(Binaries)/DataInit.o

$(Binaries)/DataRead.o: $(Sources)/dtRead.c $(Sources)/dtRead.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/dtRead.c -o $(Binaries)/DataRead.o

$(Binaries)/InitialDraw.o: $(Sources)/scInitialDraw.c $(Sources)/scInitialDraw.h $(Sources)/scColors.h
	@$(CC) $(OFLAGSR) $(IPATH) $(Sources)/scInitialDraw.c -o $(Binaries)/InitialDraw.o

$(Binaries)/PieceDraw.o: $(Sources)/scPieceDraw.c $(Sources)/scPieceDraw.h $(Sources)/scColors.h $(Sources)/scInitialDraw.h $(Sources)/dtRead.h
	@$(CC) $(OFLAGSR) $(IPATH) $(Sources)/scPieceDraw.c -o $(Binaries)/PieceDraw.o

#Abreviated command

DataInit: $(Binaries)/DataInit.o
DataRead: $(Binaries)/DataRead.o
InitialDraw: $(Binaries)/InitialDraw.o
PieceDraw: $(Binaries)/PieceDraw.o


#Run the program

Run: $(Binaries)/PoolChess.app
	@$(Binaries)/PoolChess.app

Debug: $(Binaries)/PoolChessDebug.app

clean: 
	@rm -f $(Binaries)/*.o
	@rm -f $(Binaries)/*.app