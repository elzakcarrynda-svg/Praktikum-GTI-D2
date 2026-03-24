#include <GL/glut.h>

void Robot(void){
    glClear(GL_COLOR_BUFFER_BIT);

    // Warna ungu 
    glColor3f(0.6f, 0.2f, 0.8f);
    // Kepala
    glRectf(-0.1, 0.6, 0.1, 0.4);
    // Tangan kiri
    glRectf(-0.35, 0.35, -0.15, 0.1);
    glRectf(0.15, 0.35, 0.35, 0.1);

    // Telinga 
    glRectf(-0.08, 0.8, -0.02, 0.6);
    glRectf(0.02, 0.8, 0.08, 0.6);

    // Warna pink 
    glColor3f(1.0f, 0.4f, 0.7f);
    // Badan
    glRectf(-0.15, 0.4, 0.15, 0.0);
    // Kaki 
    glRectf(-0.12, 0.0, -0.02, -0.4);
    glRectf(0.02, 0.0, 0.12, -0.4);


    // Warna kuning 
    glColor3f(1.0f, 1.0f, 0.0f);
    // Mata 
    glRectf(-0.07, 0.55, -0.03, 0.50);
    glRectf(0.03, 0.55, 0.07, 0.50);
    // Mulut
    glRectf(-0.04, 0.47, 0.04, 0.43);

    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("JAX DIGITAL CIRCUS");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(Robot);
    glutMainLoop();

    return 0;
}
