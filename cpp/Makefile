ALL_CC=$(basename $(wildcard *.cc))

all: $(addprefix run_,$(ALL_CC))

run_%:
	@echo Rule: $@
	@mkdir -p out/
	g++ -std=c++14 -O2 $*.cc -o out/$*.o
	@echo "./out/$*.o"
	@echo "================="
	@./out/$*.o



clean:
	rm -rf out/
