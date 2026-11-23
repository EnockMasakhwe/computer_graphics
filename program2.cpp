#include <GL/glut.h>
#include <math.h>
 
/* Called once at start-up: settings that never change */
void init(void)
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);   /* sky blue background          */
    glMatrixMode(GL_PROJECTION);               /* we are setting up the camera */
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);        /* x: 0..640, y: 0..480         */
}
 
/* Called whenever the window needs to be drawn */
void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
 
    /* 1. Ground: a green rectangle (polygon with 4 vertices) */
    glColor3f(0.20f, 0.80f, 0.20f);
    glBegin(GL_POLYGON);
        glVertex2i(0, 0);   glVertex2i(640, 0);
        glVertex2i(640, 100); glVertex2i(0, 100);
    glEnd();
 
    /* 2. Walls of the house */
    glColor3f(0.96f, 0.87f, 0.70f);
    glBegin(GL_POLYGON);
        glVertex2i(200, 100); glVertex2i(420, 100);
        glVertex2i(420, 260); glVertex2i(200, 260);
    glEnd();
 
    /* 3. Roof: one triangle */
    glColor3f(0.60f, 0.25f, 0.15f);
    glBegin(GL_TRIANGLES);
        glVertex2i(180, 260); glVertex2i(440, 260); glVertex2i(310, 360);
    glEnd();
 
    /* 4. Door and window */
    /*Door*/
    glColor3f(0.45f, 0.30f, 0.15f);
    glBegin(GL_POLYGON);
        glVertex2i(285, 100); glVertex2i(335, 100);
        glVertex2i(335, 190); glVertex2i(285, 190);
    glEnd();
    /*Left window*/
    glColor3f(0.85f, 0.95f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2i(220, 180); glVertex2i(265, 180);
        glVertex2i(265, 225); glVertex2i(220, 225);
    glEnd();
    /*Right window*/
    glColor3f(0.85f, 0.95f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2i(355, 180); glVertex2i(400, 180);
        glVertex2i(400, 225); glVertex2i(355, 225);
    glEnd();
 
    /* 5. Frames: a closed outline using GL_LINE_LOOP */
    /*Left window frame*/
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2i(220, 180); glVertex2i(265, 180);
        glVertex2i(265, 225); glVertex2i(220, 225);
    glEnd();
    /*Right window frame*/
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2i(355, 180); glVertex2i(400, 180);
        glVertex2i(400, 225); glVertex2i(355, 225);
    glEnd();
    /*Door frame*/
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2i(285, 100); glVertex2i(335, 100);
        glVertex2i(335, 190); glVertex2i(285, 190);
    glEnd();
 
    /* 6. Fence: separate line segments using GL_LINES (2 vertices per line) */
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        for (i = 450; i <= 620; i += 20) {
            glVertex2i(i, 100); glVertex2i(i, 150);     /* upright posts */
        }
        glVertex2i(445, 130); glVertex2i(625, 130);     /* rail          */
    glEnd();
 
    /* 7. Sun: a circle approximated by a 40-sided polygon (Lesson 5!) */
    glColor3f(1.0f, 0.85f, 0.10f);
    glBegin(GL_POLYGON);
        for (i = 0; i < 40; i++) {
            float a = 2.0f * 3.14159f * i / 40;
            glVertex2f(540.0f + 40.0f * cosf(a), 400.0f + 40.0f * sinf(a));
        }
    glEnd();
 
    /* 8. Flowers: big points using GL_POINTS */
    glPointSize(9.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.2f, 0.4f);  glVertex2i(60, 60);  glVertex2i(110, 40);
        glColor3f(1.0f, 1.0f, 0.2f);  glVertex2i(150, 70); glVertex2i(500, 50);
        glColor3f(0.8f, 0.3f, 1.0f);  glVertex2i(560, 30); glVertex2i(600, 70);
    glEnd();
 
    glFlush();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A Simple House Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
