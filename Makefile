# Makefile
#
# make [all] : compile le programme
# make clean : supprime les *.o et *~
# make mrproper : supprime les *.o, *~ et les programmes

##### Variables #####
CXX=g++
LD=g++
CPPFLAGS=-Wall -Wextra
LDFLAGS=-s

BIN=bin/
OBJ=obj/
SRC=src/
INC=inc/

##### Cibles generales #####
all: $(BIN)gitwar

##### Programme #####
$(BIN)gitwar: $(OBJ)main.o $(OBJ)Player.o $(OBJ)Object.o
	@echo [LD] $@
	@$(LD) $^ -o $@ $(LDFLAGS)

##### Regles generiques #####
$(OBJ)%.o: $(SRC)%.cpp Makefile
	@echo [CC] $@
	@$(CXX) -c $< -o $@ $(CPPFLAGS) -I$(INC)

##### Dependances specifiques #####
$(SRC)main.o:$(INC)Player.h $(INC)Object.h
$(SRC)Player.o:$(INC)Player.h $(INC)Object.h
$(SRC)Object.o:$(INC)Object.h


##### Utilitaires #####
.PNOHY: clean mrproper

clean:
	@echo "[RM] Suppression des sauvegardes"
	@find . -name \*~ -exec rm -f {} \;
	@echo "[RM] Suppression des *.o"
	@rm -f $(OBJ)*.o

mrproper: clean
	@echo "[RM] Suppression des programmes"
	@rm -f $(BIN)*
