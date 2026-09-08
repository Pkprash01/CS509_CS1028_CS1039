all: compile run

compile:
	mkdir -p Assignment_01/outputs Assignment_02/outputs Assignment_03/outputs Assignment_04/outputs
	g++ -O3 wrapper.cpp -o wrapper.exe

run: compile
	./wrapper.exe

clean:
	rm -f wrapper.exe wrapper
	rm -f Assignment_*/driver/*_exec
	rm -f Assignment_*/driver/*.exe

.PHONY: all compile run clean