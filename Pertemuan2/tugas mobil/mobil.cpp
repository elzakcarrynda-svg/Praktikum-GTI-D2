#include <GL/glut.h>
#include <cmath>

float sudut = 0;
float posisiX = 0;
float awanX = -60;

// LINGKARAN 
void lingkaran(float r){
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++){
        float rad = i * 3.1416 / 180;
        glVertex2f(r * cos(rad), r * sin(rad));
    }
    glEnd();
}

// MOBIL 
void mobilF1(){
    glColor3f(0.8,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-30,-3);
        glVertex2f(25,-3);
        glVertex2f(35,2);
        glVertex2f(-25,2);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(35,2);
        glVertex2f(45,0);
        glVertex2f(35,-3);
    glEnd();

    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
        glVertex2f(-5,2);
        glVertex2f(5,2);
        glVertex2f(3,8);
        glVertex2f(-3,8);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-30,0);
        glVertex2f(-35,0);
        glVertex2f(-35,10);
        glVertex2f(-30,10);
    glEnd();

    // roda depan
    glPushMatrix();
        glTranslatef(20,-6,0);
        glRotatef(sudut,0,0,1); 
        glColor3f(0,0,0);
        lingkaran(5);
    glPopMatrix();

    // roda belakang
    glPushMatrix();
        glTranslatef(-20,-6,0);
        glRotatef(sudut,0,0,1);
        glColor3f(0,0,0);
        lingkaran(5);
    glPopMatrix();
}

// JALAN 
void jalan(){
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(-100,-20);
        glVertex2f(100,-20);
        glVertex2f(100,10);
        glVertex2f(-100,10);
    glEnd();

    glColor3f(1,1,1);
    for(int i=-100;i<100;i+=25){
        glBegin(GL_POLYGON);
            glVertex2f(i,-5);
            glVertex2f(i+12,-5);
            glVertex2f(i+12,-2);
            glVertex2f(i,-2);
        glEnd();
    }
}

// LAMPU LALU LINTAS
void lampu(){
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(80,0);
        glVertex2f(85,0);
        glVertex2f(85,40);
        glVertex2f(80,40);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(75,40);
        glVertex2f(90,40);
        glVertex2f(90,70);
        glVertex2f(75,70);
    glEnd();

    glColor3f(1,0,0);
    glPushMatrix();
        glTranslatef(82,62,0);
        lingkaran(3);
    glPopMatrix();

    glColor3f(1,1,0);
    glPushMatrix();
        glTranslatef(82,55,0);
        lingkaran(3);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
        glTranslatef(82,48,0);
        lingkaran(3);
    glPopMatrix();
}

// PENONTON 
void gambarPenonton(float startX, float endX, float baseY){
    for(float x = startX; x <= endX; x += 5){
        float y = baseY;

        glPushMatrix();
            glTranslatef(x, y, 0);
            glColor3f(0,0,0);
            lingkaran(1.5);
        glPopMatrix();
    }
}

// STAND
void stand(){

    // kiri
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
        glVertex2f(-100,20);
        glVertex2f(-60,20);
        glVertex2f(-60,70);
        glVertex2f(-100,70);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-95,40);
        glVertex2f(-65,40);
        glVertex2f(-65,55);
        glVertex2f(-95,55);
    glEnd();

    glColor3f(1,1,1);
    glRasterPos2f(-95,47);
    const char* t1 = "SEMANGAT!!";
    for(int i=0;t1[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t1[i]);

    gambarPenonton(-98,-62,72);

    // tengah
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
        glVertex2f(-20,20);
        glVertex2f(20,20);
        glVertex2f(20,70);
        glVertex2f(-20,70);
    glEnd();

    gambarPenonton(-18,18,72);

    // kanan
    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
        glVertex2f(60,20);
        glVertex2f(100,20);
        glVertex2f(100,70);
        glVertex2f(60,70);
    glEnd();

    gambarPenonton(62,98,72);
}

// AWAN
void awan(){
    glColor3f(1,1,1);

    glPushMatrix();
        glTranslatef(awanX,75,0);
        lingkaran(5);
        glTranslatef(8,2,0);
        lingkaran(6);
        glTranslatef(-16,0,0);
        lingkaran(5);
    glPopMatrix();
}

// DISPLAY
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // tanah
    glColor3f(0.6,0.3,0.1);
    glBegin(GL_POLYGON);
        glVertex2f(-100,-100);
        glVertex2f(100,-100);
        glVertex2f(100,-20);
        glVertex2f(-100,-20);
    glEnd();

    jalan();
    stand();
    lampu();
    awan();

    glPushMatrix();
        glTranslatef(posisiX,5,0);
        mobilF1();
    glPopMatrix();

    glutSwapBuffers();
}

// INIT
void init(){
    glClearColor(0.5,0.8,1.0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

// MAIN
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Mobil F1");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
