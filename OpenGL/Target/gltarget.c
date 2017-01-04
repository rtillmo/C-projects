/*
   Sample OpenGL Program to Draw a Target

   DPA 4010            Donald H. House         1/18/2016

   To compile on linux:
    gcc -o gltarget gltarget.c -lglut -lGL -lGLU
 
   To compile on Macintosh:
    gcc -o gltarget gltarget.c -framework Foundation -framework GLUT -framework OpenGL
*/

#include <stdio.h>	/* definitions for standard I/O routines */
#include <stdlib.h>
#include <math.h>   /* definitions for math library */

#ifdef __APPLE__
/* this preprocessor statement avoids warnings about using OpenGL 2.0 standard */
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define WINWIDTH	    600	/* window dimensions */
#define WINHEIGHT     600

#define DRAWWIDTH     12.0
#define DRAWHEIGHT    12.0
#define RADIUS        5.0
#define DEG2RAD       (3.14159 / 180)

/*
   Routine to draw a filled in circle of specified radius
   with center at (0, 0)
*/
void drawCircle(float r){
  float x, y;
  int theta;
  
  glBegin(GL_POLYGON);
    for(theta = 0; theta < 360; theta += 5){
      x = r * cos(theta * DEG2RAD);
      y = r * sin(theta * DEG2RAD);
      glVertex2f(x, y);
    }
  glEnd();
}

/*
   Callback to update the display: clear the screen and draw a square
*/
void drawTarget(){

  /* clear the window to the background color */
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw 5 concentric circles: Black, White, Blue, Red, Yellow */
  glColor3f(0.0, 0.0, 0.0);
  drawCircle(RADIUS);
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(4 * RADIUS / 5);
  glColor3f(0.0, 0.0, 1.0);
  drawCircle(3 * RADIUS / 5);
  glColor3f(1.0, 0.0, 0.0);
  drawCircle(2 * RADIUS / 5);
  glColor3f(1.0, 1.0, 0.0);
  drawCircle(RADIUS / 5);
  
  /* make sure that all graphics go to screen */
  glFlush();
}

/*
  Callback to handle key presses on the keyboard: quit when q key pressed
*/
void handleKey(unsigned char key, int x, int y){
  switch(key){
    case 'q':
    case 'Q':
      exit(0);
  }
}

void handleReshape(int neww, int newh){
  /* use the full window for the viewport */
  glViewport(0, 0, neww, newh);
  
  /* lower left of window is (0, 0), upper right is (WIDTH, HEIGHT) */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-DRAWWIDTH / 2, DRAWWIDTH / 2, -DRAWHEIGHT / 2, DRAWHEIGHT / 2);
}

/*
   Main program to draw the squre and wait for quit
*/
int main(int argc, char* argv[]){

  /* start up the glut utilities */
  glutInit(&argc, argv);
  
  /* use single buffering and RGBA colors */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  /* create the graphics window, giving width, height, and title text */
  glutInitWindowSize(WINWIDTH, WINHEIGHT);
  glutCreateWindow("A 5 Ringed Target");

  /* the callback routine to draw graphics used by glutMainLoop() */
  glutDisplayFunc(drawTarget);
  
  /* the callback routine to respond to the keyboard used by glutMainLoop() */
  glutKeyboardFunc(handleKey);
  
  /* window reshape callback */
  glutReshapeFunc(handleReshape);

  /* specify window clear (background) color to be white */
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glutMainLoop();
  return 0;
}
