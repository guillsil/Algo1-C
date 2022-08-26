EJECUTABLE=ejercicio
FLAGS=-Wall -Werror -std=c99 -Wconversion
CONFIG=config
ARCHIVO=trabajando_con_archivos_2.c

compile:
	gcc ${ARCHIVO} -o ${EJECUTABLE} 

compile-all:
	gcc ${ARCHIVO} -o ${EJECUTABLE} ${FLAGS} && ./${EJECUTABLE} ${CONFIG}

run:
	./${EJECUTABLE} ${CONFIG}

clean:
	rm -f ${EJECUTABLE}

all: clean compile run