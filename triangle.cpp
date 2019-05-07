#include "triangle.h"

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>

void Triangle::Initialize(){
    const GLfloat kVertices[] = {
		/* 0.0f,  0.0f, 0.0f, 1.0f,
        -0.4f, 0.2f, 0.0f, 1.0f,
        
        
         0.0f, 0.8f, 0.0f, 1.0f,*/
        0.0f,0.0f,0.0f,0.1f,//1
        0.0f,0.8f,0.0f, 1.0f,//2
        0.3f,0.2f,0.0f, 1.0f,//3
        0.8f,0.2f,0.0f, 1.0f,//4
        0.45f,-0.2f,0.0f, 1.0f,//5
        0.8f,-0.8f,0.0f, 1.0f,//6
        0.0f,-0.3f,0.0f, 1.0f,//7
        
        -0.8f,-0.8f,0.0f, 1.0f,//8
        -0.45f,-0.2f,0.0f, 1.0f,//9
        -0.8f,0.2f,0.0f, 1.0f,//10
        -0.3f,0.2f,0.0f, 1.0f,//11
         0.0f,0.8f,0.0f, 1.0f,//12
        
        
         
    };

    const GLfloat kColors[] = {
        0.07f, 0.57f, 0.4f, 1.0f,
         0.07f, 0.57f, 0.4f, 1.0f,
         0.07f, 0.57f, 0.4f, 1.0f,
        
         0.07f, 0.57f, 0.4f, 1.0f,
         0.07f, 0.57f, 0.4f, 1.0f,
      0.07f, 0.57f, 0.4f, 1.0f,
      
      0.07f, 0.57f, 0.4f, 1.0f,
      0.07f, 0.57f, 0.4f, 1.0f,
      0.07f, 0.57f, 0.4f, 1.0f,
      
      0.07f, 0.57f, 0.4f, 1.0f,
      0.07f, 0.57f, 0.4f, 1.0f,
      0.07f, 0.57f, 0.4f, 1.0f,
    };


    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kVertices), kVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &color_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kColors), kColors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

Triangle::~Triangle(){
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteBuffers(1, &color_buffer_);
    glDeleteBuffers(1, &vertex_buffer_);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao_);
}

void Triangle::Draw(const Program &program){

    glUseProgram(program);
    glBindVertexArray(vao_);

    glDrawArrays(GL_TRIANGLE_FAN, 0, 12);

    glBindVertexArray(0);
    glUseProgram(0);


}
