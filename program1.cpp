#include <GL/glut.h>
 
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);   /* fill the window with the clear colour */
    glFlush();                      /* send the picture to the screen now    */
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          /* start GLUT              */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    /* one buffer, RGB colour  */
    glutInitWindowSize(640, 480);                   /* width x height (pixels) */
    glutInitWindowPosition(100, 100);               /* where on the desktop    */
    glutCreateWindow("My First OpenGL Window");     /* make the window         */
 
    glClearColor(0.0f, 0.2f, 0.4f, 1.0f);           /* dark blue background    */
 
    glutDisplayFunc(display);                       /* register the callback   */
    glutMainLoop();                                 /* start the event loop    */
    return 0;
}
