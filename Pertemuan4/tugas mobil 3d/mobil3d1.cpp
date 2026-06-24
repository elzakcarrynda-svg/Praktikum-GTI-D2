#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 2.5f, z = 20.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;

const GLfloat light_ambient[]   = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[]  = { 5.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[]     = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]     = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]    = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[]  = { 100.0f };

void DrawPanel(float w2, float h2)
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-w2, -h2, 0.0f);
        glVertex3f( w2, -h2, 0.0f);
        glVertex3f( w2,  h2, 0.0f);
        glVertex3f(-w2,  h2, 0.0f);
    glEnd();
}

void DrawBox(float cx, float cy, float cz, float sw, float sh, float sd)
{
    float hw = sw / 2.0f;
    float hh = sh / 2.0f;
    float hd = sd / 2.0f;

    glPushMatrix();
    glTranslatef(cx, cy, cz);

    // Depan
    glPushMatrix();
    glTranslatef(0, 0, hd);
    DrawPanel(hw, hh);
    glPopMatrix();

    // Belakang
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, hd);
    DrawPanel(hw, hh);
    glPopMatrix();

    // Atas
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, 0, hh);
    DrawPanel(hw, hd);
    glPopMatrix();

    // Bawah
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, hh);
    DrawPanel(hw, hd);
    glPopMatrix();

    // Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glTranslatef(0, 0, hw);
    DrawPanel(hd, hh);
    glPopMatrix();

    // Kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, hw);
    DrawPanel(hd, hh);
    glPopMatrix();

    glPopMatrix();
}



void DrawWheel(float cx, float cy, float cz)
{
    glPushMatrix();
    glTranslatef(cx, cy, cz);
    // Torus sudah berbentuk roda (lingkaran) menghadap sumbu Z by default
    glutSolidTorus(0.25, 0.6, 12, 20);
    glPopMatrix();
}

void Mobil()
{
    // Bodi bawah
    glColor3f(0.2f, 0.4f, 0.8f);
    DrawBox(0, 0.8f, 0,   6.0f, 1.2f, 2.8f);

    // Kabin/atap
    glColor3f(0.3f, 0.5f, 0.9f);
    DrawBox(0, 2.1f, 0,   4.0f, 0.8f, 2.6f);

    // Kap mesin
    glColor3f(0.2f, 0.4f, 0.8f);
    DrawBox(3.5f, 1.3f, 0,   1.5f, 0.5f, 2.8f);

    // Bagasi belakang
    DrawBox(-3.5f, 1.3f, 0,  1.5f, 0.5f, 2.8f);

    // Bemper depan
    glColor3f(0.15f, 0.15f, 0.15f);
    DrawBox(4.4f, 0.5f, 0,   0.3f, 0.6f, 2.8f);

    // Bemper belakang
    DrawBox(-4.4f, 0.5f, 0,  0.3f, 0.6f, 2.8f);

    // 4 Roda
    glColor3f(0.1f, 0.1f, 0.1f);
    DrawWheel( 2.5f, 0.7f,  2.0f);
    DrawWheel( 2.5f, 0.7f, -2.0f);
    DrawWheel(-2.5f, 0.7f,  2.0f);
    DrawWheel(-2.5f, 0.7f, -2.0f);

    // Lampu depan
    glColor3f(1.0f, 1.0f, 0.3f);
    DrawBox(4.3f, 1.1f,  1.0f,  0.2f, 0.3f, 0.6f);
    DrawBox(4.3f, 1.1f, -1.0f,  0.2f, 0.3f, 0.6f);

    // Lampu belakang
    glColor3f(0.9f, 0.1f, 0.1f);
    DrawBox(-4.3f, 1.1f,  1.0f,  0.2f, 0.3f, 0.6f);
    DrawBox(-4.3f, 1.1f, -1.0f,  0.2f, 0.3f, 0.6f);
}

void Grid()
{
    double i;
    const float Z_MIN = -20, Z_MAX = 20;
    const float X_MIN = -20, X_MAX = 20;
    const float gap = 2.0;

    glDisable(GL_LIGHTING);
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

void Reshape(int w1, int h1)
{
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void orientMe(float ang)
{
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i)
{
    x = x + i * lx * 0.1f;
    z = z + i * lz * 0.1f;
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void display()
{
    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Grid();
    Mobil();
    glutSwapBuffers();
    glFlush();

    if (deltaMove || deltaAngle)
        glutPostRedisplay();
}

void pressKey(int key, int x2, int y2)
{
    switch (key) {
        case GLUT_KEY_LEFT:  deltaAngle = -0.01f; break;
        case GLUT_KEY_RIGHT: deltaAngle =  0.01f; break;
        case GLUT_KEY_UP:    deltaMove  =  1;     break;
        case GLUT_KEY_DOWN:  deltaMove  = -1;     break;
    }
    glutPostRedisplay();
}

void releaseKey(int key, int x2, int y2)
{
    switch (key) {
        case GLUT_KEY_LEFT:  if (deltaAngle < 0.0f) deltaAngle = 0.0f; break;
        case GLUT_KEY_RIGHT: if (deltaAngle > 0.0f) deltaAngle = 0.0f; break;
        case GLUT_KEY_UP:    if (deltaMove  > 0)    deltaMove  = 0;    break;
        case GLUT_KEY_DOWN:  if (deltaMove  < 0)    deltaMove  = 0;    break;
    }
    glutPostRedisplay();
}

void lighting()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,   light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,   light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR,  light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION,  light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void)
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D - Depth & Lighting");

    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);

    lighting();
    init();

    glutMainLoop();
    return 0;
}