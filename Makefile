#comandos

SCANNER := lex
SCANNER_PARAMS := lexico.l
PARSER := yacc
PARSER_PARAMS := -d sintatico.y

all: compile translate test

test: 
	g++ -o teste teste.cpp
	./teste
	

compile:
		$(SCANNER) $(SCANNER_PARAMS)
		$(PARSER) $(PARSER_PARAMS)
		g++ -o glf y.tab.c -ll

run: 	glf
		clear
		compile

debug:	PARSER_PARAMS += -Wcounterexamples
debug: 	all

translate: glf
		./glf < exemplo.hahaha
		

clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm glf