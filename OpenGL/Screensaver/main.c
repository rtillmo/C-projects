#include <stdlib.h>
#include <stdio.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
# include <math.h> 
#endif
#include "utility.h"

#define WIDTH   640
#define HEIGHT  480
#define MIN_SPEED 1.0
#define MAX_SPEED 3.0
#define SQUARES 5
#define DELAY 25

// Structs ********************

typedef struct {
  float x;
  float y;
  int width;
} Square;

typedef struct {
  Square square1;
  Square square2;
  float xspeed;
  float yspeed;
} Ship;

Ship ship[10];

//Functions ********************

void drawSquare(){
  int i;
  for( i = 0; i < 10; ++i){
  glColor3f(0.5, 0, 1);
  glBegin(GL_POLYGON);
    glVertex2i(ship[i].square1.x, ship[i].square1.y);
    glVertex2i(ship[i].square1.x+ ship[i].square1.width, ship[i].square1.y);
    glVertex2i(ship[i].square1.x, ship[i].square1.y+ship[i].square1.width);
  glEnd();
}
}
void drawSquare2(){
  int i;
  for( i = 0; i < 10; ++i){
  glColor3f(1, 0.5, 0);
   glBegin(GL_POLYGON);
    glVertex2i(ship[i].square2.x,ship[i].square2.y);
    glVertex2i(ship[i].square2.x+ship[i].square2.width, ship[i].square2.y);
    glVertex2i(ship[i].square2.x+ship[i].square2.width, ship[i].square2.y+ship[i].square2.width);
    glVertex2i(ship[i].square2.x, ship[i].square2.y+ship[i].square2.width);
  glEnd();
}
}
void initBoth() {
  int i;
  for( i = 0; i < 10; ++i){
  ship[i].square1.x = rand() % WIDTH;
  ship[i].square1.width = 30;

  ship[i].square2.x = ship[i].square1.x+7;
  ship[i].square2.y = ship[i].square1.y+7;
  ship[i].square2.width = 15;

  ship[i].xspeed = getRandFloat(MIN_SPEED, MAX_SPEED) * ( rand()%2?1:-1 );
  ship[i].yspeed = getRandFloat(MIN_SPEED, MAX_SPEED) * ( rand()%2?1:-1 );
}
}
void updateBoth() {
  int i;
  for( i = 0; i < 10; ++i){
  if ( ship[i].square1.x+ship[i].square1.width >= WIDTH ) {
    ship[i].xspeed = -1*abs(ship[i].xspeed);
    glClearColor( 0, 0, 0, 0); 
  }
  if ( ship[i].square1.x < 0 ) {
    ship[i].xspeed = abs(ship[i].xspeed);;
    glClearColor(0,0,0,0);
     }

  if (ship[i].square1.y+ship[i].square1.width >=HEIGHT){
      ship[i].yspeed = -1*abs(ship[i].yspeed);;
      glClearColor (0,0,0.7,0);
  }

  if ( ship[i].square1.y < 0 ) {
    ship[i].yspeed = abs(ship[i].xspeed);;
    glClearColor (1,0,0,0);
    }
  ship[i].square1.x+=ship[i].xspeed;
  ship[i].square1.y+=ship[i].yspeed;
  ship[i].square2.x+=ship[i].xspeed;
  ship[i].square2.y+=ship[i].yspeed;
}
}

void updateAnimation(int extra) {
  static int time = 0;
  static int oldtime = 0;
  int delay;
  updateBoth();
  glutPostRedisplay();

  time = glutGet(GLUT_ELAPSED_TIME);
  delay = DELAY - (time - oldtime);
  oldtime = time;
  if (delay < 0) delay = 0;
  glutTimerFunc(delay, updateAnimation, 0);
} 

void handleKey(unsigned char key, int x, int y){
  switch(key){
    case 'q': case 'Q': case 27: exit(0);
    default: return; 
  }
}

void displayFunction() {
  glClear(GL_COLOR_BUFFER_BIT); 
  drawSquare();
  drawSquare2();
  glutSwapBuffers();
}

void initGlut(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(200,0);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Clemson Ships");
  gluOrtho2D(0, WIDTH, 0, HEIGHT);
  glClearColor(0, 0, 0, 0);
  glutDisplayFunc(displayFunction);	
  glutKeyboardFunc(handleKey);	
  glutTimerFunc(0, updateAnimation, 0);
}

// Main ********************

int main(int argc, char* argv[]){
  initGlut(argc, argv);
  initBoth();
  glutMainLoop();
  return 0;
}

