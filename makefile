dirInfo: dirInfo.c
	gcc dirInfo.c -o dirInfo

run: dirInfo
	./dirInfo

clean:
	-rm dirInfo
	-rm *~
