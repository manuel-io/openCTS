NAME    := openCTS
VERSION := 0.0.1
CC      := g++ -c
LD      := g++
CFLAGS  := -Wall -g
LDFLAGS := -lSDL2 -lSDL2_image -lSDL2_ttf

OBJS    := menu/menu.o \
           menu/credits.o \
           play/play.o \
					 play/menu.o \
					 editor/editor.o \
					 editor/menu.o \
					 editor/items.o \
					 form/button.o \
           game/main.o \
           game/state.o \
					 game/game.o \
					 game/texture.o \
					 game/obj.o \
					 game/map.o \
					 game/submenu.o \
					 game/tabmenu.o

.PHONY: clean install uninstall

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $@ $+ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.so
	rm -f game/*.o
	rm -f gamemenu/*.o
	rm -f play/*.o
	rm -f editor/*.o
	rm -f form/*.o
	rm -f $(NAME)
