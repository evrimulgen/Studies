########################################
# définitions
########################################

# executables à générer

BIN=client serveur clientOnemsg

# liste des fichiers sources 
SRCS0=client.c
SRCS1=serveur.c
SRCS2=clientOnemsg.c
default: $(BIN)

########################################
# regles pour générer les executables
########################################

%.o: %.c
	gcc -Wall -Iinclude -c $< -o $@

client: $(SRCS0:%.c=%.o)
	gcc -o $@ $+

serveur: $(SRCS1:%.c=%.o)
	gcc -o $@ $+

clientOnemsg : $(SRCS2:%.c=%.o)
	gcc -o $@ $+
clean:
	rm -f $(BIN) *.o *~
	
