all: project_file.exe

project_file.exe: Tic-Tac-Toe.c tiny-regex-c/re.h tiny-regex-c/re.c
	gcc Tic-Tac-Toe.c tiny-regex-c/re.h tiny-regex-c/re.c -o project_file.exe

clean:
	rm project_file.exe