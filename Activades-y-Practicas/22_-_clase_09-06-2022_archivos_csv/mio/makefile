EJECUTABLE=ejercicio
FLAGS=-Wall -Werror -std=c99 -Wconversion
CONFIG=config
ANIMALES=animales.csv
ARCHIVO=trabajando_con_csv_1.c

compile:
	gcc ${ARCHIVO} -o ${EJECUTABLE} 

compile-all:
	gcc ${ARCHIVO} -o ${EJECUTABLE} ${FLAGS} && ./${EJECUTABLE} ${CONFIG}

run:
	./${EJECUTABLE} ${ANIMALES} ${CONFIG}

clean:
	rm -f ${EJECUTABLE}

all: clean compile run