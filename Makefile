all: compile run

compile:
	g++ -O3 wrapper.cpp -o wrapper.exe

run: compile
	./wrapper.exe

clean:
	rm -f wrapper.exe wrapper Assignment_02/driver/*_exec Assignment_02/driver/*.exe Assignment_02/outputs/*_out.txt
.PHONY: all compile run clean