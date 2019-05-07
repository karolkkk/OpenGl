#ifndef WINDOW_H
#define WINDOW_H

#include <cstring>

#include "triangle.h"
#include "program.h"

class Window{
 public:
    Window(const char*, int, int);
    void Initialize(int argc, char* argv[], int major_gl_version, int minor_gl_version);
    void Resize(int new_width, int new_height);
    void Render(void);
    void KeyPressed(unsigned char key, int x_coord, int y_coord);
 private:
    int width_;
    int height_;
    char title_[256];
    Triangle triangle_;
    Program program_;

    void InitGlutOrDie(int argc, char* argv[], int major_gl_version, int minor_gl_version);
    void InitGlewOrDie();
    void InitModels();
    void InitPrograms();

};


#endif // WINDOW_H

