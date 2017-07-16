SRC=bigint.o test.o
#
#
test:$(SRC)
	@echo "start"
	g++ -o test bigint.o test.o -g 
	@echo "end"
test.o:Test.cpp
	g++ -o test.o -c Test.cpp -g
bigint.o:bigint.cpp
	g++ -o bigint.o -c bigint.cpp
.PHONY:clean
clean:
	rm test bigint.o
