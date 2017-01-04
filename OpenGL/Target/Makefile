CC		= gcc
CFLAGS	= -g -Wall
C		= c

ifeq ("$(shell uname)", "Darwin")
    LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lm
else
  ifeq ("$(shell uname)", "Linux")
    LDFLAGS     = -lglut -lGL -lGLU -lm
  endif
endif

OFILES		=
HFILES		=
PROJECT		= gltarget

${PROJECT}:	${PROJECT}.o ${OFILES}
	${CC} ${CFLAGS} -o ${PROJECT} ${PROJECT}.o ${OFILES} ${LDFLAGS}

${PROJECT}.o: ${PROJECT}.${C} ${HFILES}
	${CC} ${CFLAGS} -c ${PROJECT}.${C}

clean:
	rm -f *.o *~ ${PROJECT}
