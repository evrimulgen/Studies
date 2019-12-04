########################################
# définitions
########################################

# executables à générer

BIN=emetteur recepteur

# liste des fichiers sources 
SRCS0=emetteur.c
SRCS1=recepteur.c

default: $(BIN)

########################################
# regles pour générer les executables
########################################

%.o: %.c
	gcc -Wall -Iinclude -c $< -o $@

emetteur: $(SRCS0:%.c=%.o)
	gcc -o $@ $+

recepteur: $(SRCS1:%.c=%.o)
	gcc -o $@ $+

clean:
	rm -f $(BIN) *.o *~
	
