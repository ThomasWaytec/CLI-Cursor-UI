all: project_file.exe

project_file.exe: src/Tic-Tac-Toe.c src/controls.c src/interface.c
	gcc src/Tic-Tac-Toe.c src/controls.c src/interface.c -o project_file.exe

clean:
	rm project_file.exe