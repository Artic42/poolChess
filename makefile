#Constant definitions

CC = gcc
CFLAGSR = -Wall
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFLAGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -ISource

#Path to diferent modules

Binaries = bin
Sources = Source
Headers = Source/Header

#default make file, makes the full application

$(Binaries)/PoolChess.app: $(Sources)/poolChess.c $(Sources)/poolChess.h $(Binaries)/Data.o
	@$(CC) $(CFLAGSR) $(IPATH) $(Sources)/poolChess.c $(Binaries)/Data.o -o $(Binaries)/PoolChess.app

$(Binaries)/PoolChessDebug.app: $(Sources)/poolChess.c $(Sources)/poolChess.h $(Binaries)/Data_D.o
	@$(CC) $(CFLAGSD) $(IPATH) $(Sources)/poolChess.c $(Binaries)/Data_D.o -o $(Binaries)/PoolChessDebug.app

#Subordinate objects of the application Heimdallr for Debug

$(Binaries)/Data_D.o: $(Sources)/initializeData.c $(Sources)/initializeData.h
	@$(CC) $(OFLAGSD) $(IPATH) $(Sources)/initializeData.c -o $(Binaries)/Data_D.o


#Subordinate objects of the application Heimdallr for realease 

$(Binaries)/Data.o: $(Sources)/initializeData.c $(Sources)/initializeData.h
	@$(CC) $(OFLAGSR) $(IPATH) $(Sources)/initializeData.c -o $(Binaries)/Data.o

#Abreviated command

Data: $(Binaries)/Data.o


#Run the program

Run: $(Binaries)/PoolChess.app
	@$(Binaries)/PoolChess.app

Debug: $(Binaries)/PoolChessDebug.app

clean: 
	@rm -f $(Binaries)/*.o
	@rm -f $(Binaries)/*.app