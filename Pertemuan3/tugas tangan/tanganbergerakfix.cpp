#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0;
static int elbow = 0;
static int finger1 = 0; 
static int finger2 = 0; 
static int finger3 = 0;
static int finger4 = 0; 
static int thumb   = 0; 
static int rotateY = 0; 

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef((GLfloat)rotateY, 0.0, 1.0, 0.0);

    glColor3f(0.0, 0.5, 1.0);

    // SHOULDER 
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    // ELBOW
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    // TELAPAK + JARI
    glPushMatrix();

        // TELAPAK 
        glTranslatef(1.5, 0.0, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef(0.8, 0.5, 0.3);
            glutWireCube(1.0);
        glPopMatrix();

        // TELUNJUK
        glPushMatrix();
            glTranslatef(0.4, -0.2, 0.0);
            glRotatef(finger1, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.25, 0.0, 0.0);
                glScalef(0.5, 0.1, 0.2);
                glutWireCube(1.0);
            glPopMatrix();

            glTranslatef(0.5, 0.0, 0.0);
            glRotatef(finger1 * 0.7, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.2, 0.0, 0.0);
                glScalef(0.4, 0.09, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // TENGAH 
        glPushMatrix();
            glTranslatef(0.4, 0.0, 0.0);
            glRotatef(finger2, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.3, 0.0, 0.0);
                glScalef(0.6, 0.1, 0.2);
                glutWireCube(1.0);
            glPopMatrix();

            glTranslatef(0.6, 0.0, 0.0);
            glRotatef(finger2 * 0.7, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.25, 0.0, 0.0);
                glScalef(0.5, 0.09, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // MANIS
        glPushMatrix();
            glTranslatef(0.4, 0.2, 0.0);
            glRotatef(finger3, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.25, 0.0, 0.0);
                glScalef(0.5, 0.1, 0.2);
                glutWireCube(1.0);
            glPopMatrix();

            glTranslatef(0.5, 0.0, 0.0);
            glRotatef(finger3 * 0.7, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.2, 0.0, 0.0);
                glScalef(0.4, 0.09, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // KELINGKING 
        glPushMatrix();
            glTranslatef(0.4, 0.35, 0.0);
            glRotatef(finger4, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.2, 0.0, 0.0);
                glScalef(0.4, 0.1, 0.2);
                glutWireCube(1.0);
            glPopMatrix();

            glTranslatef(0.4, 0.0, 0.0);
            glRotatef(finger4 * 0.7, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.15, 0.0, 0.0);
                glScalef(0.3, 0.08, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // JEMPOL 
        glPushMatrix();
            glTranslatef(0.2, -0.35, 0.2);
            glRotatef(thumb, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.2, 0.0, 0.0);
                glScalef(0.4, 0.2, 0.3);
                glutWireCube(1.0);
            glPopMatrix();

            glTranslatef(0.4, 0.0, 0.0);
            glRotatef(thumb * 0.6, 0, 1, 0);

            glPushMatrix();
                glTranslatef(0.15, 0.0, 0.0);
                glScalef(0.3, 0.18, 0.3);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glPopMatrix(); 

    glutSwapBuffers(); 
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': 
			shoulder = (shoulder + 5) % 360; 
			break;
        case 'S': 
			shoulder = (shoulder - 5) % 360; 
			break;

        case 'e': 
			elbow = (elbow + 5) % 360; 
			break;
        case 'E': 
			elbow = (elbow - 5) % 360; 
			break;

        case 'a': 
			rotateY -= 5; 
			break;
        case 'd': 
			rotateY += 5; 
			break;

        case 'w': 
			finger1 += 5; 
			break;
        case 'W': 
			finger1 -= 5; break;

        case 'r': 
			finger2 += 5; 
			break;
        case 'R': 
			finger2 -= 5; 
			break;

        case 'q': 
			finger3 += 5; 
			break;
        case 'Q': 
			finger3 -= 5; 
			break;

        case 'z': 
			finger4 += 5; 
			break;
        case 'Z': 
			finger4 -= 5; 
			break;

        case 'x': 
			thumb += 5; 
			break;
        case 'X': 
			thumb -= 5; 
			break;

        case 27: exit(0);
    }

    if(finger1 > 90) finger1 = 90;
    if(finger1 < 0)  finger1 = 0;

    if(finger2 > 90) finger2 = 90;
    if(finger2 < 0)  finger2 = 0;

    if(finger3 > 90) finger3 = 90;
    if(finger3 < 0)  finger3 = 0;

    if(finger4 > 90) finger4 = 90;
    if(finger4 < 0)  finger4 = 0;

    if(thumb > 60) thumb = 60;
    if(thumb < 0)  thumb = 0;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm Punya jari");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
