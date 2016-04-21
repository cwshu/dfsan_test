all: var

var: var.c
	clang -fsanitize=dataflow -fsanitize-blacklist=dfsan_abilist.txt var.c -o var

clean:
	rm -f var
