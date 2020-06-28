aloop: main.o
	cc -framework SDL2 -o aloop main.o

main.o: ../main.c
	cc -c -Wall ../main.c

.PHONY: clean
clean:
	rm -f aloop main.o

.PHONY: install
install: aloop
	sudo mkdir -p /usr/local/bin
	sudo install aloop /usr/local/bin

.PHONY: uninstall
uninstall:
	-killall aloop
	sudo rm -f /usr/local/bin/aloop
	-sudo rmdir /usr/local/bin
