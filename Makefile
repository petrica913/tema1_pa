# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: servere p2 p3 p4

# Nu compilați aici, nici măcar ca dependențe de reguli.
run-p1:
	./servere
run-p2:
	./p2
run-p3:
	./compresie
run-p4:
	./p4

# Schimbați numele surselor (și, eventual, ale executabilelor - peste tot).
servere: servere.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: p2.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: compresie.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: p4.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f servere p2 compresie p4
