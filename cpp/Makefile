ALL_CC=$(basename $(wildcard *.cc))

all: $(addprefix run_,$(ALL_CC))

run_%:
	@echo Rule: $@
	@mkdir -p out/
	g++ -pthread -std=c++17 $*.cc -o out/$*.o -I ../eigen-3.4.0
	@echo "./out/$*.o"
	@echo "================="
	@./out/$*.o



clean:
	rm -rf out/
