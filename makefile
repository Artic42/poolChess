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

#default make file, makes the full application

$(Binaries)/PoolChess.app: $(Sources)/poolChess.c $(Sources)/poolChess.h $(Binaries)/Data.o $(Binaries)/Screen.o
	@$(CC) $(CFLAGSR) $(IPATH) $(Sources)/poolChess.c $(Binaries)/Data.o $(Binaries)/Screen.o -o $(Binaries)/PoolChess.app

$(Binaries)/PoolChessDebug.app: $(Sources)/poolChess.c $(Sources)/poolChess.h $(Binaries)/Data_D.o $(Binaries)/Screen_D.o
	@$(CC) $(CFLAGSD) $(IPATH) $(Sources)/poolChess.c $(Binaries)/Data_D.o $(Binaries)/Screen_D.o -o $(Binaries)/PoolChessDebug.app

#Subordinate objects of the application Heimdallr for Debug

$(Binaries)/Data_D.o: $(Sources)/dtInitialize.c $(Sources)/dtInitialize.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/dtInitialize.c -o $(Binaries)/Data_D.o

$(Binaries)/Screen_D.o: $(Sources)/scInitialDraw.c $(Sources)/scInitialDraw.h $(Sources)/scColors.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/scInitialDraw.c -o $(Binaries)/Screen_D.o

#Subordinate objects of the application Heimdallr for realease 

$(Binaries)/Data.o: $(Sources)/dtInitialize.c $(Sources)/dtInitialize.h
	@$(CC) $(OFLAGSR) $(IPATH) $(Sources)/dtInitialize.c -o $(Binaries)/Data.o

$(Binaries)/Screen.o: $(Sources)/scInitialDraw.c $(Sources)/scInitialDraw.h $(Sources)/scColors.h
	@$(CC) $(OFLAGSR) $(IPATH) $(Sources)/scInitialDraw.c -o $(Binaries)/Screen.o

#Abreviated command

Data: $(Binaries)/Data.o
Screen: $(Binaries)/Screen_D.o


#Run the program

Run: $(Binaries)/PoolChess.app
	@$(Binaries)/PoolChess.app

Debug: $(Binaries)/PoolChessDebug.app

clean: 
	@rm -f $(Binaries)/*.o
	@rm -f $(Binaries)/*.app