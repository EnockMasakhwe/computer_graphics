#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_POINTS 200
int px[MAX_POINTS], py[MAX_POINTS];   /* points the user has clicked   */
int count = 0;                        /* how many points stored so far */
int winW = 640, winH = 480;           /* current window size           */
 
void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);      /* yellow                         */
    glPointSize(8.0f);
    glBegin(GL_POINTS);               /* a dot at every clicked point   */
        for (i = 0; i < count; i++) glVertex2i(px[i], py[i]);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);      /* join the dots in order         */
    glBegin(GL_LINE_STRIP);
        for (i = 0; i < count; i++) glVertex2i(px[i], py[i]);
    glEnd();
    glFlush();
}
 
/* Called when the window is opened or resized */
void reshape(int w, int h)
{
    winW = w; winH = h;
    glViewport(0, 0, w, h);           /* use the whole window           */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);       /* 1 unit = 1 pixel               */
}
 
/* Called when a mouse button is pressed or released */
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && count < MAX_POINTS) {
        px[count] = x;
        py[count] = winH - y;         /* GLUT counts y from the TOP     */
        printf("Point %d at (%d, %d)\n", count + 1, px[count], py[count]);
        count++;
        glutPostRedisplay();          /* ask GLUT to call display() again */
    }
}
 
/* Called when an ordinary key is pressed */
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'c': count = 0; break;                                   /* clear      */
    case 'r': glClearColor(0.5f, 0.0f, 0.0f, 1.0f); break;        /* dark red   */
    case 'g': glClearColor(0.0f, 0.4f, 0.0f, 1.0f); break;        /* dark green */
    case 'b': glClearColor(0.0f, 0.0f, 0.4f, 1.0f); break;        /* dark blue  */
    case 'q': case 27: exit(0);                                   /* q or Esc   */
    }
    glutPostRedisplay();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winW, winH);
    glutCreateWindow("Click to Draw");
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);    /* almost black */
 
    glutDisplayFunc(display);                /* register all four callbacks */
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
 
    glutMainLoop();                          /* hand control to the event loop */
    return 0;
}
