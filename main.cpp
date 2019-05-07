#include "window.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>


const int kMajorGLVersion = 4;
const int kMinorGLVersion = 3;

Window window("Postawy OpenGL", 800, 600);

void Resize (int new_width, int new_height){
    window.Resize(new_width, new_height);
    
}

void Render(){
    window.Render();
}
GLfloat x=0.0f,  y= 0.0f,  radius= 0.8f;
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	int PI=3.14;
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}


void KeyPressed(unsigned char key, int x_coord, int y_coord){
    window.KeyPressed(key, x_coord, y_coord);
    
}
 

int main(int argc, char* argv[]){
    window.Initialize(argc, argv, kMajorGLVersion, kMinorGLVersion);

    glutReshapeFunc(Resize);
    glutDisplayFunc(Render);
    glutKeyboardFunc(KeyPressed);
   
    drawHollowCircle( x,  y,  radius);
glBegin(GL_POINTS);
 for(int i=0;i<1000;++i)
  {
  glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);
  }
 glEnd();
    glutMainLoop();

    exit(EXIT_SUCCESS);
}

