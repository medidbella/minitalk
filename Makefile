COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

srv = server
clt = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
libft = libft/libft.a


all: $(srv) $(clt)
	@echo "$(COLOUR_GREEN)THE SERVER AND CLIENT PROGRAMS ARE READY$(COLOUR_END)"
$(srv): server.c $(libft)
	$(CC) $(CFLAGS) $(libft) server.c -o $(srv)

$(clt): client.c $(libft)
	$(CC) $(CFLAGS) $(libft) client.c -o $(clt)




clean:
	@rm -f $(srv) $(clt)
	@echo "$(COLOUR_RED)THE PROGRAMS ARE DELETED$(COLOUR_END)"

fclean: clean

re: fclean all
