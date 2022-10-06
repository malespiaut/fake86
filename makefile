SRCFILES=src/fake86/*.c
BINPATH=/usr/bin
DATAPATH=/usr/share/fake86
CFLAGS=-O2 -DPATH_DATAFILES=\"$(DATAPATH)/\"
INCLUDE=-Isrc/fake86
LIBS=-lpthread
SDLFLAGS=`sdl-config --cflags --libs`

all: fake86-src imagegen-src

fake86-src:
	$(CC) $(SRCFILES) -o bin/fake86 $(CFLAGS) $(INCLUDE) $(LIBS) $(SDLFLAGS)
	chmod a+x bin/fake86

imagegen-src:
	$(CC) src/imagegen/imagegen.c -o bin/imagegen $(CFLAGS)
	chmod a+x bin/imagegen

install:
	mkdir -p $(BINPATH)
	mkdir -p $(DATAPATH)
	chmod a-x data/*
	cp -p bin/fake86 $(BINPATH)
	cp -p bin/imagegen $(BINPATH)
	cp -p data/asciivga.dat $(DATAPATH)
	cp -p data/pcxtbios.bin $(DATAPATH)
	cp -p data/videorom.bin $(DATAPATH)
	cp -p data/rombasic.bin $(DATAPATH)

clean:
	rm -f src/fake86/*.o
	rm -f src/fake86/*~
	rm -f src/imagegen/*.o
	rm -f src/imagegen/*~
	rm -f bin/fake86
	rm -f bin/imagegen

uninstall:
	rm -f $(BINPATH)/fake86
	rm -f $(BINPATH)/imagegen
