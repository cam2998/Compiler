SHELL=/bin/bash

#==========================
# include lex and yacc libraries
# enable debugging and use gnu11 standard
#==========================
LOADLIBES = -ll -ly
YFLAGS = -d
CFLAGS = -g  -std=gnu11

#==========================
# Make rule syntax
# target: dependencies
# 	rule to build target from dependencies
#
# - no rule necessary if make already knows (i.e. .o from .c)
# - sometimes no dependencies (e.g. clean target)

#==========================
# Symbol Table Project
SymTab.o: SymTab.c SymTab.h
SymTabDriver.o: SymTabDriver.c SymTab.h
SymTabDriver: SymTabDriver.o SymTab.o

symtest: SymTabDriver
		make -s symtest-0
		make -s symtest-1
		make -s symtest-2

symtest-0: SymTabDriver
		echo "Test 0"
		./SymTabDriver SymData-0.in > out
		cat out
		if diff out SymData-0.out; then \
			echo -e "\n\nSUCCESS\n\n" ;\
		else \
			echo -e "\n\nFAILED\n\n" ;\
		fi
		rm out

symtest-1: SymTabDriver
		echo "Test 1"
		./SymTabDriver SymData-1.in > out
		cat out
		if diff out SymData-1.out; then \
			echo -e "\n\nSUCCESS\n\n" ;\
		else \
			echo -e "\n\nFAILED\n\n" ;\
		fi
		rm out

symtest-2: SymTabDriver
		echo "Test 2"
		./SymTabDriver SymData-2.in > out
		cat out
		if diff out SymData-2.out; then \
			echo -e "\n\nSUCCESS\n\n" ;\
		else \
			echo -e "\n\nFAILED\n\n" ;\
		fi
		rm out

symgrind: SymTabDriver
	valgrind --leak-check=full ./SymTabDriver SymData-2.in


#===========================
# IOMngr Project
IOMngr.o: IOMngr.c IOMngr.h
IOMngrDriver.o: IOMngrDriver.c IOMngr.h
IOMngrDriver: IOMngrDriver.o IOMngr.o

iotest:	IOMngrDriver
		make -s iotest1
		make -s iotest2

iotest1: IOMngrDriver
	./IOMngrDriver IOMngrSource IOMngrListing

iotest2: IOMngrDriver
	./IOMngrDriver IOMngrSource


#===========================
# Scanner Project
ScannerDriver.o: ScannerDriver.c Scanner.h SymTab.h ScanTokens.h
ScannerDriver: 	ScannerDriver.o Scanner.o SymTab.o IOMngr.o

scantest: 	ScannerDriver
	./ScannerDriver

scanextest: 	ScanExample
	./ScanExample


#===========================
# Recursive Descent Project
RDSupport.o:	RDSupport.c RDSupport.h
RecDescent.o: 	RecDescent.c Scanner.h RDTokens.h
RecDescent: 	RecDescent.o RDGrammar.o RDScanner.o RDSupport.o IOMngr.o

rdtest: 	rdtest1 rdtest2 rdtest3 rdtest4 rdtest5

rdtest1: 	RecDescent
	./RecDescent RDSrc-1
	./RecDescent -l RDSrc-1
rdtest2: 	RecDescent
	./RecDescent RDSrc-2
	./RecDescent -l RDSrc-2
rdtest3: 	RecDescent
	./RecDescent RDSrc-3
	./RecDescent -l RDSrc-3
rdtest4: 	RecDescent
	./RecDescent RDSrc-4
	./RecDescent -l RDSrc-4
rdtest5: 	RecDescent
	./RecDescent RDSrc-5
	./RecDescent -l RDSrc-5


#===========================
# Parser Stage 1 & 2
ParserScanner.o: ParserScanner.l IOMngr.h ParserGrammar.o
ParserGrammar.o: ParserGrammar.y y.tab.h
Parse.o: Parse.c Grammar.h Scanner.h IOMngr.h
Parse: Parse.o ParserGrammar.o ParserScanner.o IOMngr.o

partest:	parse1 parse2

parse1:	Parse
	./Parse ParSrc-1
parse2:	Parse
	./Parse ParSrc-2

#===========================
# Semantics
CGTest.o:     CGTest.c YCodeGen.h
CGTest:       CGTest.o YCodeGen.o

YCodeGen.o:	YCodeGen.c YCodeGen.h

YScanner.o: 	YScanner.l IOMngr.h YSemantics.h YGrammar.o
YGrammar.o:		YGrammar.y y.tab.h
YSemantics.o: 	YSemantics.c YSemantics.h
Y.o: 		Y.c Grammar.h YScanner.l IOMngr.h
Y:		Y.o SymTab.o IOMngr.o YScanner.o YGrammar.o YSemantics.o YCodeGen.o

ytest:	y1test y2test y3test y4test y5test

y1test:	Y
	./Y y1

y2test: Y
	./Y y2
	spim -noexception -file y2.asm < y2.in

y3test: Y
	./Y y3
	spim -noexception -file y3.asm < y3.in

y4test: Y
	./Y y4
	spim -noexception -file y4.asm < y4.in

y5test: Y yfactors.src
	./Y yfactors
	spim -noexception -file yfactors.asm < yfactors.in

sem2test:	 feature1 feature2 feature3 feature4 feature5 feature6 feature7 feature8 feature9 feature10 feature11

feature1:    Y
	 echo "Testing increment and decrement"
	 rm -f yIncDec.lst yIncDec.asm
	 ./Y -l yIncDec
	 cat yIncDec.lst
	 cat yIncDec.asm
	 spim -noexception -file yIncDec.asm < yIncDec.in

feature2:    Y
		echo "Testing boolean operators"
		rm -f ymybool.lst ymybool.asm
	 	./Y -l ymybool
	 	cat ymybool.lst
	 	cat ymybool.asm
	 	spim -noexception -file ymybool.asm

feature3:    Y
	echo "Testing basic for loop"
	rm -f yfor.lst yfor.asm
	./Y -l yfor
	cat yfor.lst
	cat yfor.asm
	spim -noexception -file yfor.asm

feature4:    Y
	echo "Testing for with multiple fields in each part operators"
	rm -f yfor++.lst yfor++.asm
	./Y -l yfor++
	cat yfor++.lst
	cat yfor++.asm
	spim -noexception -file yfor++.asm

feature5:	Y
	echo "Testing for loop/break"
	rm -f ymyloop.lst ymyloop.asm
	./Y -l ymyloop
	cat ymyloop.lst
	cat ymyloop.asm
	spim -noexception -file ymyloop.asm


feature6:	Y
	echo "Testing the loop/break for nesting "
	rm -f ymyloop++.lst ymyloop++.asm
	./Y -l ymyloop++
	cat ymyloop++.lst
	cat ymyloop++.asm
	spim -noexception -file ymyloop++.asm

feature7:	Y
	echo "Testing for constants"
	rm -f ycnst.lst ycnst.asm
	./Y -l ycnst
	cat ycnst.lst
	cat ycnst.asm
	spim -noexception -file ycnst.asm

feature8:	Y
	echo "Testing for switch (if theres a default it has to be at top to work)"
	rm -f ycase.lst ycase.asm
	./Y -l ycase
	cat ycase.lst
	cat ycase.asm
	spim -noexception -file ycase.asm


feature9:	Y
	echo "Testing for locals"
	rm -f ylocal.lst ylocal.asm
	./Y -l ylocal
	cat ylocal.lst
	cat ylocal.asm
	spim -noexception -file ylocal.asm


feature10:	Y
	echo "Testing arrays"
	rm -f yarr.lst yarr.asm
	./Y -l yarr
	cat yarr.lst
	cat yarr.asm
	spim -noexception -file yarr.asm

feature11:	Y
	echo "Testing functions"
	rm -f yfunction.lst yfunction.asm
	./Y -l yfunction
	cat yfunction.lst
	cat yfunction.asm
	spim -noexception -file yfunction.asm



# Other
clean:
	rm -f *.o SymTabDriver IOMngrDriver ScannerDriver RecDescent Parse Y
