CC=gcc
CFLAGS=-I.
DEPS = audioread.h ligne_csv.h stft.h outils_maths.h
OBJ = audioread.c ligne_csv.c stft.c outils_maths.c main_test_encodage_ecriture_2.c

%.o: %.c $(DEPS)
	$(CC) -x -o $@ $< $(CFLAGS)

ecriture_csv: audioread.o ligne_csv.o stft.o outils_maths.o main_test_encodage_ecriture_2.o
	$(CC) -o $@ $^ $(CFLAGS)
