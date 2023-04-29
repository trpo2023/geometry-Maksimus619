TARGET = ./bin/MyProject
CC = gcc

CFLAGS = -Wall -Werror 
PATH_INCLUDE = -Isrc/libgeometry

PREF_SRCMAIN = ./src/geometry/
PREF_OBJMAIN = ./obj/src/geometry/

PREF_SRC = ./src/libgeometry/
PREF_OBJ = ./obj/src/libgeometry/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

SRCMAIN = $(wildcard $(PREF_SRCMAIN)*.c)
OBJMAIN = $(patsubst $(PREF_SRCMAIN)%.c, $(PREF_OBJMAIN)%.o, $(SRCMAIN))

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	$(CC) -c $(CFLAGS) $(PATH_INCLUDE) -o $@ $<

$(PREF_OBJMAIN)%.o : $(PREF_SRCMAIN)%.c
	        $(CC) -c $(CFLAGS) $(PATH_INCLUDE) -o $@ $<

$(TARGET) : $(OBJMAIN) $(OBJ) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJMAIN) $(OBJ)

clean :
	rm $(TARGET) $(PREF_OBJ)*.o $(PREF_OBJMAIN)*.o
