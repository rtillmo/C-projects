CC		= gcc
C		= c

CFLAGS		= -g

ifeq ("$(shell uname)", "Darwin")
  LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lm
else
  ifeq ("$(shell uname)", "Linux")
    LDFLAGS     = -L /usr/lib64/ -lglut -lGL -lGLU -lm
  endif
endif

PROJECT		= main
EXEC		= run

${PROJECT}:	${PROJECT}.o
	${CC} ${CFLAGS} -o ${EXEC} ${PROJECT}.o ${LDFLAGS}

${PROJECT}.o:	${PROJECT}.${C}
	${CC} ${CFLAGS} -c ${PROJECT}.${C}

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf ${EXEC}
