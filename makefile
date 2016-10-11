listtest: runner.c
	gcc runner.c -o listtest

run: listtest
	./listtest
