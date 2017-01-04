
#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define WIDTH   600
#define HEIGHT  600


void handleKey(unsigned char key, int x, int y){
  switch(key){
    case 'q':		// q - quit
    case 'Q':
    case 27:		// esc - quit
      exit(0);
    default:		// not a valid key -- just ignore it
      return;
  }
}

void drawSquare(){
  // Set the drawing color
  glColor3f(0, 1, 1);
  // Draw the square in clockwise order; order matters here.
  glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(50, 250);
    glVertex2i(250, 250);
    glVertex2i(250, 50);
  glEnd();
}

void drawTriangle(){
  glColor3f(0,0,1);
  glBegin(GL_POLYGON);
    glVertex2i(25,250);
    glVertex2i(150,350);
    glVertex2i(275,250);
  glEnd();
}

void drawRectangle(){
  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
    glVertex2i(130,50);
    glVertex2i(130,100);
    glVertex2i(170,100);
    glVertex2i(170,50);
  glEnd();
}

void drawGrass(){
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
     glVertex2i(0,0);
     glVertex2i(0,50);
     glVertex2i(800,50);
     glVertex2i(800,0);
  glEnd();
}


void drawWindow1(){
  glColor3f(1,1,0);
  glBegin(GL_POLYGON);
    glVertex2i(70,150);
    glVertex2i(70,190);
    glVertex2i(100,190);
    glVertex2i(100,150);
  glEnd();
}

void drawWindow2(){
  glColor3f(1,1,0);
  glBegin(GL_POLYGON);
    glVertex2i(200,150);
    glVertex2i(200,190);
    glVertex2i(230,190);
    glVertex2i(230,150);
  glEnd();
}

void display() {
  // clear window to background color
  glClear(GL_COLOR_BUFFER_BIT); 
  drawSquare();
  drawTriangle();
  drawRectangle();
  drawGrass();
  drawWindow1();
  drawWindow2();
  glFlush();
}

/* Create the graphics window, giving width, height, and title text
 * Register a callback: display
 */
void initialize(int argc, char* argv[]) {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("A Simple Square");
  gluOrtho2D(0, WIDTH, 0, HEIGHT);
  glClearColor(0, 0, 0, 0);
  glutDisplayFunc(display);
  glutKeyboardFunc(handleKey);	
}

int main(int argc, char* argv[]){
  glutInit(&argc, argv);
  initialize(argc, argv);
  display();
  glutMainLoop();
  return 0;
}
