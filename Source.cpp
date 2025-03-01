#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#include <cstdio>
#include <GL/gl.h>
#define PI 3.14159265358979323846

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.018f;
GLfloat position3 = 0.0f;
GLfloat speed3 = 0.08f;
GLfloat position13 = 0.0f;
GLfloat speed13 = 0.03f;
GLfloat position14 = 0.0f;
GLfloat speed14 = 0.04f;
GLfloat position15 = 0.0f;
GLfloat speed15 = 0.15f;

void update_white_car(int value)
{

    if (position2 < -1.20)
        position2 = .99f;

    position2 -= speed2;

    glutPostRedisplay();

    glutTimerFunc(100, update_white_car, 0);
}
void update_blue_car(int value)
{

    if (position3 < -1.50)
        position3 = 1.0f;

    position3 -= speed3;

    glutPostRedisplay();

    glutTimerFunc(100, update_blue_car, 0);
}
void update_purple_car(int value) // car3-4
{

    if (position13 > 1.50)
        position13 = -1.50f;

    position13 += speed13;

    glutPostRedisplay();

    glutTimerFunc(100, update_purple_car, 0);
}
void update_red_car(int value)
{

    if (position14 > 1.50)
        position14 = -1.50f;

    position14 += speed14;

    glutPostRedisplay();

    glutTimerFunc(100, update_red_car, 0);
}
void update_airplane(int value)
{

    if (position15 < -1.5)
        position15 = 2.0f;

    position15 -= speed15;

    glutPostRedisplay();

    glutTimerFunc(100, update_airplane, 0);
}

void create_circle(float radius, float x, float y, int triangleAmount)
{
    float twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); // center of circle
    for (int q = 0; q <= triangleAmount; q++)
    {
        glVertex2f(
            x + (radius * cos(q * twicePi / triangleAmount)),
            y + (radius * sin(q * twicePi / triangleAmount)));
    }
    glEnd();
}
void generate_trees()
{
    float radius, x, y, triangleAmount, twicePi;
    // roadside tree dark
    for (float i = 0.0; i <= 2.0; i = i + 0.1)
    {
        glColor3ub(51, 102, 0);
        radius = .075f;
        x = (-0.95 + i);
        y = -.44f;
        if (int(i * 10) % 2 == 0)
        {
            radius = .055f;
            y = -.43f;
        }
        twicePi = 2.0f * PI;
        create_circle(radius, x, y, 20);
    }
    // roadside tree light
    for (float i = 0.0; i <= 2.2; i = i + 0.1)
    {
        glColor3ub(72, 143, 10);
        x = (-1.0 + i);
        y = -.5f;
        radius = .052f;
        if (int(i * 10) % 2 == 0)
        {
            radius = .06f;
            y = -.48f;
        }
        create_circle(radius, x, y, 20);
    }
}
void generate_sky_stars()
{
    // sky
    glBegin(GL_QUADS);
    glColor3ub(4, 26, 64);
    glVertex2f(1.0, -0.4);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glVertex2f(-1.0, -0.4);
    glEnd();

    // stars
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f, 0.65f);
    glVertex2f(0.9f, 0.9f);
    glVertex2f(0.95f, 0.7f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(0.7f, 0.9f);
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.5f, 0.75f);
    glVertex2f(0.4f, 0.9f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(0.25f, 0.7f);
    glVertex2f(0.1f, 0.5f);
    glVertex2f(0.15f, 0.75f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(-0.7f, 0.9f);
    glVertex2f(-0.8f, 0.65f);
    glVertex2f(-0.4f, 0.8f);
    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.9f, 0.9f);
    glVertex2f(-0.95f, 0.6f);
    glVertex2f(-0.8f, 0.8f);
    glVertex2f(-0.7f, 0.9f);
    glVertex2f(-0.6f, 0.8f);
    glVertex2f(-0.5f, 0.45f);
    glVertex2f(-0.4f, 0.9f);
    glVertex2f(-0.3f, 0.7f);
    glVertex2f(-0.25f, 0.8f);
    glVertex2f(-0.25f, 0.7f);
    glVertex2f(-0.15f, 0.65f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.5f, 0.45f);
    glVertex2f(0.6f, 0.55f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, 0.65f);
    glVertex2f(-0.8f, 0.55f);
    glVertex2f(-0.4f, 0.8f);
    glEnd();

    // Moon
    glColor3f(1, 1, 1);
    float x = -.8f;
    float y = .8f;
    float radius = .07f;
    create_circle(radius, x, y, 20);
}

void display()
{

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // sky and stars
    generate_sky_stars();

    // plane
    glPushMatrix();
    glTranslatef(position15, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(183, 183, 183);
    glVertex2f(.6, .6);
    glVertex2f(.65, 0.65);
    glVertex2f(0.40, 0.63);
    glVertex2f(0.30, .6);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.45f, 0.62f);
    glVertex2f(0.5f, 0.62f);
    glVertex2f(0.55f, 0.62f);
    glEnd();
    glPopMatrix();

    // right blding 1
    glBegin(GL_QUADS);
    glColor3ub(163, 163, 194);
    glVertex2f(0.05, -0.50);
    glVertex2f(0.05, 0.15);
    glVertex2f(-0.05, 0.15);
    glVertex2f(-0.05, -0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 204);
    glVertex2f(0.17, -0.50);
    glVertex2f(0.17, 0.15);
    glVertex2f(0.05, 0.15);
    glVertex2f(0.05, -0.50);
    glEnd();

    // glass
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.12);
    glVertex2f(0.16, 0.13);
    glVertex2f(0.06, 0.13);
    glVertex2f(0.06, 0.12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.10);
    glVertex2f(0.16, 0.11);
    glVertex2f(0.06, 0.11);
    glVertex2f(0.06, 0.10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.08);
    glVertex2f(0.16, 0.09);
    glVertex2f(0.06, 0.09);
    glVertex2f(0.06, 0.08);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.06);
    glVertex2f(0.16, 0.07);
    glVertex2f(0.06, 0.07);
    glVertex2f(0.06, 0.06);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.04);
    glVertex2f(0.16, 0.05);
    glVertex2f(0.06, 0.05);
    glVertex2f(0.06, 0.04);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.02);
    glVertex2f(0.16, 0.03);
    glVertex2f(0.06, 0.03);
    glVertex2f(0.06, 0.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, 0.0);
    glVertex2f(0.16, 0.01);
    glVertex2f(0.06, 0.01);
    glVertex2f(0.06, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.02);
    glVertex2f(0.16, -0.01);
    glVertex2f(0.06, -0.01);
    glVertex2f(0.06, -0.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.04);
    glVertex2f(0.16, -0.03);
    glVertex2f(0.06, -0.03);
    glVertex2f(0.06, -0.04);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.06);
    glVertex2f(0.16, -0.05);
    glVertex2f(0.06, -0.05);
    glVertex2f(0.06, -0.06);
    glEnd(); //
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.08);
    glVertex2f(0.16, -0.07);
    glVertex2f(0.06, -0.07);
    glVertex2f(0.06, -0.08);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.10);
    glVertex2f(0.16, -0.09);
    glVertex2f(0.06, -0.09);
    glVertex2f(0.06, -0.10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.12);
    glVertex2f(0.16, -0.11);
    glVertex2f(0.06, -0.11);
    glVertex2f(0.06, -0.12);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.14);
    glVertex2f(0.16, -0.13);
    glVertex2f(0.06, -0.13);
    glVertex2f(0.06, -0.14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.16);
    glVertex2f(0.16, -0.15);
    glVertex2f(0.06, -0.15);
    glVertex2f(0.06, -0.16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.18);
    glVertex2f(0.16, -0.17);
    glVertex2f(0.06, -0.17);
    glVertex2f(0.06, -0.18);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.20);
    glVertex2f(0.16, -0.19);
    glVertex2f(0.06, -0.19);
    glVertex2f(0.06, -0.20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.22);
    glVertex2f(0.16, -0.21);
    glVertex2f(0.06, -0.21);
    glVertex2f(0.06, -0.22);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.24);
    glVertex2f(0.16, -0.23);
    glVertex2f(0.06, -0.23);
    glVertex2f(0.06, -0.24);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.26);
    glVertex2f(0.16, -0.25);
    glVertex2f(0.06, -0.25);
    glVertex2f(0.06, -0.26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.28);
    glVertex2f(0.16, -0.27);
    glVertex2f(0.06, -0.27);
    glVertex2f(0.06, -0.28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.30);
    glVertex2f(0.16, -0.29);
    glVertex2f(0.06, -0.29);
    glVertex2f(0.06, -0.30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.32);
    glVertex2f(0.16, -0.31);
    glVertex2f(0.06, -0.31);
    glVertex2f(0.06, -0.32);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.34);
    glVertex2f(0.16, -0.33);
    glVertex2f(0.06, -0.33);
    glVertex2f(0.06, -0.34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.36);
    glVertex2f(0.16, -0.35);
    glVertex2f(0.06, -0.35);
    glVertex2f(0.06, -0.36);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.06);
    glVertex2f(0.16, -0.05);
    glVertex2f(0.06, -0.05);
    glVertex2f(0.06, -0.06);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.16, -0.06);
    glVertex2f(0.16, -0.05);
    glVertex2f(0.06, -0.05);
    glVertex2f(0.06, -0.06);
    glEnd();

    // Right blding 2
    glBegin(GL_QUADS);
    glColor3ub(117, 163, 163);
    glVertex2f(0.25, -0.50);
    glVertex2f(0.25, 0.05);
    glVertex2f(0.17, 0.05);
    glVertex2f(0.17, -0.50);
    glEnd();

    // Right blding 3
    glBegin(GL_QUADS);
    glColor3ub(133, 173, 173);
    glVertex2f(0.37, -0.50);
    glVertex2f(0.37, 0.1);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.25, -0.50);
    glEnd();

    // GLASS
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.365, -0.50);
    glVertex2f(0.365, 0.085);
    glVertex2f(0.30, 0.085);
    glVertex2f(0.30, -0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.29, -0.50);
    glVertex2f(0.29, 0.085);
    glVertex2f(0.255, 0.085);
    glVertex2f(0.255, -0.50);
    glEnd();

    // Right blding 5
    glBegin(GL_QUADS);
    glColor3ub(117, 163, 163);
    glVertex2f(0.53, -0.50);
    glVertex2f(0.53, 0.3);
    glVertex2f(0.37, 0.3);
    glVertex2f(0.37, -0.50);
    glEnd();

    // glass
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.29);
    glVertex2f(0.525, 0.28);
    glVertex2f(0.42, 0.28);
    glVertex2f(0.42, 0.29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.27);
    glVertex2f(0.525, 0.26);
    glVertex2f(0.42, 0.26);
    glVertex2f(0.42, 0.27);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.25);
    glVertex2f(0.525, 0.24);
    glVertex2f(0.42, 0.24);
    glVertex2f(0.42, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.23);
    glVertex2f(0.525, 0.22);
    glVertex2f(0.42, 0.22);
    glVertex2f(0.42, 0.23);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.21);
    glVertex2f(0.525, 0.20);
    glVertex2f(0.42, 0.20);
    glVertex2f(0.42, 0.21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.18);
    glVertex2f(0.42, 0.18);
    glVertex2f(0.42, 0.19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.17);
    glVertex2f(0.525, 0.16);
    glVertex2f(0.42, 0.16);
    glVertex2f(0.42, 0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.15);
    glVertex2f(0.525, 0.14);
    glVertex2f(0.42, 0.14);
    glVertex2f(0.42, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.13);
    glVertex2f(0.525, 0.12);
    glVertex2f(0.42, 0.12);
    glVertex2f(0.42, 0.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.11);
    glVertex2f(0.525, 0.10);
    glVertex2f(0.42, 0.10);
    glVertex2f(0.42, 0.11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.09);
    glVertex2f(0.525, 0.08);
    glVertex2f(0.42, 0.08);
    glVertex2f(0.42, 0.09);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.07);
    glVertex2f(0.525, 0.06);
    glVertex2f(0.42, 0.06);
    glVertex2f(0.42, 0.07);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.05);
    glVertex2f(0.525, 0.04);
    glVertex2f(0.42, 0.04);
    glVertex2f(0.42, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.03);
    glVertex2f(0.525, 0.02);
    glVertex2f(0.42, 0.02);
    glVertex2f(0.42, 0.03);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, 0.01);
    glVertex2f(0.525, 0.00);
    glVertex2f(0.42, 0.00);
    glVertex2f(0.42, 0.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.01);
    glVertex2f(0.525, -0.02);
    glVertex2f(0.42, -0.02);
    glVertex2f(0.42, -0.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.03);
    glVertex2f(0.525, -0.04);
    glVertex2f(0.42, -0.04);
    glVertex2f(0.42, -0.03);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.05);
    glVertex2f(0.525, -0.06);
    glVertex2f(0.42, -0.06);
    glVertex2f(0.42, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.07);
    glVertex2f(0.525, -0.08);
    glVertex2f(0.42, -0.08);
    glVertex2f(0.42, -0.07);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.09);
    glVertex2f(0.525, -0.10);
    glVertex2f(0.42, -0.10);
    glVertex2f(0.42, -0.09);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.11);
    glVertex2f(0.525, -0.12);
    glVertex2f(0.42, -0.12);
    glVertex2f(0.42, -0.11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.13);
    glVertex2f(0.525, -0.14);
    glVertex2f(0.42, -0.14);
    glVertex2f(0.42, -0.13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.15);
    glVertex2f(0.525, -0.16);
    glVertex2f(0.42, -0.16);
    glVertex2f(0.42, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.17);
    glVertex2f(0.525, -0.18);
    glVertex2f(0.42, -0.18);
    glVertex2f(0.42, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.19);
    glVertex2f(0.525, -0.20);
    glVertex2f(0.42, -0.20);
    glVertex2f(0.42, -0.19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 26);
    glVertex2f(0.525, -0.21);
    glVertex2f(0.525, -0.22);
    glVertex2f(0.42, -0.22);
    glVertex2f(0.42, -0.21);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.23);
    glVertex2f(0.525, -0.24);
    glVertex2f(0.42, -0.24);
    glVertex2f(0.42, -0.23);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.25);
    glVertex2f(0.525, -0.26);
    glVertex2f(0.42, -0.26);
    glVertex2f(0.42, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.27);
    glVertex2f(0.525, -0.28);
    glVertex2f(0.42, -0.28);
    glVertex2f(0.42, -0.27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.29);
    glVertex2f(0.525, -0.30);
    glVertex2f(0.42, -0.30);
    glVertex2f(0.42, -0.29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.31);
    glVertex2f(0.525, -0.32);
    glVertex2f(0.42, -0.32);
    glVertex2f(0.42, -0.31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.33);
    glVertex2f(0.525, -0.34);
    glVertex2f(0.42, -0.34);
    glVertex2f(0.42, -0.33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.35);
    glVertex2f(0.525, -0.36);
    glVertex2f(0.42, -0.36);
    glVertex2f(0.42, -0.35);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.37);
    glVertex2f(0.525, -0.38);
    glVertex2f(0.42, -0.38);
    glVertex2f(0.42, -0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.39);
    glVertex2f(0.525, -0.40);
    glVertex2f(0.42, -0.40);
    glVertex2f(0.42, -0.39);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.41);
    glVertex2f(0.525, -0.42);
    glVertex2f(0.42, -0.42);
    glVertex2f(0.42, -0.41);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(0.525, -0.43);
    glVertex2f(0.525, -0.44);
    glVertex2f(0.42, -0.44);
    glVertex2f(0.42, -0.43);
    glEnd();

    // Right blding 4

    glBegin(GL_QUADS);
    glColor3ub(102, 153, 153);
    glVertex2f(0.5, -0.50);
    glVertex2f(0.5, -0.21);
    glVertex2f(0.3, -0.21);
    glVertex2f(0.3, -0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(117, 163, 163);
    glVertex2f(0.75, -0.50);
    glVertex2f(0.75, -0.21);
    glVertex2f(0.5, -0.21);
    glVertex2f(0.5, -0.50);
    glEnd();

    // glass

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.23);
    glVertex2f(0.74, -0.22);
    glVertex2f(0.51, -0.22);
    glVertex2f(0.51, -0.23);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.25);
    glVertex2f(0.74, -0.24);
    glVertex2f(0.51, -0.24);
    glVertex2f(0.51, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.27);
    glVertex2f(0.74, -0.26);
    glVertex2f(0.51, -0.26);
    glVertex2f(0.51, -0.27);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.29);
    glVertex2f(0.74, -0.28);
    glVertex2f(0.51, -0.28);
    glVertex2f(0.51, -0.29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.31);
    glVertex2f(0.74, -0.30);
    glVertex2f(0.51, -0.30);
    glVertex2f(0.51, -0.31);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.33);
    glVertex2f(0.74, -0.32);
    glVertex2f(0.51, -0.32);
    glVertex2f(0.51, -0.33);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.35);
    glVertex2f(0.74, -0.34);
    glVertex2f(0.51, -0.34);
    glVertex2f(0.51, -0.35);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.37);
    glVertex2f(0.74, -0.36);
    glVertex2f(0.51, -0.36);
    glVertex2f(0.51, -0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.39);
    glVertex2f(0.74, -0.38);
    glVertex2f(0.51, -0.38);
    glVertex2f(0.51, -0.39);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.41);
    glVertex2f(0.74, -0.40);
    glVertex2f(0.51, -0.40);
    glVertex2f(0.51, -0.41);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.43);
    glVertex2f(0.74, -0.42);
    glVertex2f(0.51, -0.42);
    glVertex2f(0.51, -0.43);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.45);
    glVertex2f(0.74, -0.44);
    glVertex2f(0.51, -0.44);
    glVertex2f(0.51, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.74, -0.47);
    glVertex2f(0.74, -0.46);
    glVertex2f(0.51, -0.46);
    glVertex2f(0.51, -0.47);
    glEnd();

    // Right blding 8
    glBegin(GL_QUADS);
    glColor3ub(133, 173, 173);
    glVertex2f(0.85, -0.50);
    glVertex2f(0.85, -0.25);
    glVertex2f(0.8, -0.25);
    glVertex2f(0.8, -0.50);
    glEnd();
    // Right blding 6
    glBegin(GL_QUADS);
    glColor3ub(102, 153, 153);
    glVertex2f(0.85, -0.50);
    glVertex2f(0.85, -0.27);
    glVertex2f(0.75, -0.27);
    glVertex2f(0.75, -0.50);
    glEnd();
    // glass
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.45);
    glVertex2f(0.84, -0.44);
    glVertex2f(0.76, -0.44);
    glVertex2f(0.76, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.43);
    glVertex2f(0.84, -0.42);
    glVertex2f(0.76, -0.42);
    glVertex2f(0.76, -0.43);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.41);
    glVertex2f(0.84, -0.40);
    glVertex2f(0.76, -0.40);
    glVertex2f(0.76, -0.41);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.39);
    glVertex2f(0.84, -0.38);
    glVertex2f(0.76, -0.38);
    glVertex2f(0.76, -0.39);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.37);
    glVertex2f(0.84, -0.36);
    glVertex2f(0.76, -0.36);
    glVertex2f(0.76, -0.37);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.34);
    glVertex2f(0.84, -0.35);
    glVertex2f(0.76, -0.35);
    glVertex2f(0.76, -0.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.32);
    glVertex2f(0.84, -0.33);
    glVertex2f(0.76, -0.33);
    glVertex2f(0.76, -0.32);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.30);
    glVertex2f(0.84, -0.31);
    glVertex2f(0.76, -0.31);
    glVertex2f(0.76, -0.30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(0.84, -0.28);
    glVertex2f(0.84, -0.29);
    glVertex2f(0.76, -0.29);
    glVertex2f(0.76, -0.28);
    glEnd();

    // Right blding 7

    glBegin(GL_QUADS);
    glColor3ub(92, 138, 138);
    glVertex2f(0.9, -0.50);
    glVertex2f(0.9, -0.105);
    glVertex2f(0.85, -0.105);
    glVertex2f(0.85, -0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 153, 153);
    glVertex2f(1., -0.50);
    glVertex2f(1.0, -0.105);
    glVertex2f(0.9, -0.105);
    glVertex2f(0.9, -0.50);
    glEnd();
    // glass
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.45);
    glVertex2f(.995, -0.44);
    glVertex2f(0.91, -0.44);
    glVertex2f(0.91, -0.45);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.43);
    glVertex2f(.995, -0.42);
    glVertex2f(0.91, -0.42);
    glVertex2f(0.91, -0.43);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.41);
    glVertex2f(.995, -0.40);
    glVertex2f(0.91, -0.40);
    glVertex2f(0.91, -0.41);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.39);
    glVertex2f(.995, -0.38);
    glVertex2f(0.91, -0.38);
    glVertex2f(0.91, -0.39);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.37);
    glVertex2f(.995, -0.36);
    glVertex2f(0.91, -0.36);
    glVertex2f(0.91, -0.37);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.35);
    glVertex2f(.995, -0.34);
    glVertex2f(0.91, -0.34);
    glVertex2f(0.91, -0.35);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.33);
    glVertex2f(.995, -0.32);
    glVertex2f(0.91, -0.32);
    glVertex2f(0.91, -0.33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.31);
    glVertex2f(.995, -0.30);
    glVertex2f(0.91, -0.30);
    glVertex2f(0.91, -0.31);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.29);
    glVertex2f(.995, -0.28);
    glVertex2f(0.91, -0.28);
    glVertex2f(0.91, -0.29);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.27);
    glVertex2f(.995, -0.26);
    glVertex2f(0.91, -0.26);
    glVertex2f(0.91, -0.27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.25);
    glVertex2f(.995, -0.24);
    glVertex2f(0.91, -0.24);
    glVertex2f(0.91, -0.25);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.23);
    glVertex2f(.995, -0.22);
    glVertex2f(0.91, -0.22);
    glVertex2f(0.91, -0.23);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.21);
    glVertex2f(.995, -0.20);
    glVertex2f(0.91, -0.20);
    glVertex2f(0.91, -0.21);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.19);
    glVertex2f(.995, -0.18);
    glVertex2f(0.91, -0.18);
    glVertex2f(0.91, -0.19);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.17);
    glVertex2f(.995, -0.16);
    glVertex2f(0.91, -0.16);
    glVertex2f(0.91, -0.17);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.15);
    glVertex2f(.995, -0.14);
    glVertex2f(0.91, -0.14);
    glVertex2f(0.91, -0.15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 51);
    glVertex2f(.995, -0.13);
    glVertex2f(.995, -0.12);
    glVertex2f(0.91, -0.12);
    glVertex2f(0.91, -0.13);
    glEnd();

    // LEFT SIDE BLDING 1  //************************
    glBegin(GL_QUADS);
    glColor3ub(204, 51, 0);
    glVertex2f(-.95, -0.4);
    glVertex2f(-.95, 0.17);
    glVertex2f(-1.0, 0.17);
    glVertex2f(-1.0, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 57, 0);
    glVertex2f(-.8, -0.4);
    glVertex2f(-.8, 0.17);
    glVertex2f(-.950, 0.17);
    glVertex2f(-.950, -0.4);
    glEnd();

    // glass#####
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 230);
    glVertex2f(-.81, -0.4);
    glVertex2f(-.81, 0.15);
    glVertex2f(-.945, 0.15);
    glVertex2f(-.945, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 230);
    glVertex2f(-.96, -0.4);
    glVertex2f(-.96, 0.15);
    glVertex2f(-.995, 0.15);
    glVertex2f(-.995, -0.4);
    glEnd();

    // LEFT SIDE BLDING 2

    glBegin(GL_QUADS);
    glColor3ub(102, 153, 153);
    glVertex2f(-.75, -0.4);
    glVertex2f(-.75, -0.13);
    glVertex2f(-0.8, -0.13);
    glVertex2f(-.8, -0.4);
    glEnd();
    // LEFT SIDE BLDING 3

    glBegin(GL_QUADS);
    glColor3ub(117, 163, 163);
    glVertex2f(-.65, -0.4);
    glVertex2f(-.65, -0.08);
    glVertex2f(-0.75, -0.08);
    glVertex2f(-.75, -0.4);
    glEnd();

    // LEFT SIDE BLDING 4

    // bldingside

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-.6, -0.4);
    glVertex2f(-.6, 0.31);
    glVertex2f(-0.65, 0.31);
    glVertex2f(-.65, -0.4);
    glEnd();
    // miror 1

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(-.59, -0.4);
    glVertex2f(-.59, 0.29);
    glVertex2f(-0.64, 0.29);
    glVertex2f(-.64, -0.4);
    glEnd();

    // blding

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(-.5, -0.4);
    glVertex2f(-.5, 0.31);
    glVertex2f(-0.6, 0.31);
    glVertex2f(-.6, -0.4);
    glEnd();

    // miror 2
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 255);
    glVertex2f(-.51, -0.4);
    glVertex2f(-.51, 0.29);
    glVertex2f(-0.59, 0.29);
    glVertex2f(-.59, -0.4);
    glEnd();

    // LEFT SIDE BLDING 5

    glBegin(GL_QUADS);
    glColor3ub(198, 140, 83);
    glVertex2f(-.45, -0.4);
    glVertex2f(-.45, 0.09);
    glVertex2f(-0.5, 0.09);
    glVertex2f(-0.5, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 153, 102);
    glVertex2f(-.4, -0.4);
    glVertex2f(-.4, 0.09);
    glVertex2f(-0.45, 0.09);
    glVertex2f(-0.45, -0.4);
    glEnd();

    // Glass
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.405, -0.4);
    glVertex2f(-.405, 0.08);
    glVertex2f(-0.447, 0.08);
    glVertex2f(-0.447, -0.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.457, -0.4);
    glVertex2f(-.457, 0.08);
    glVertex2f(-0.495, 0.08);
    glVertex2f(-0.495, -0.4);
    glEnd();

    // thamba

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(-.35, -0.4);
    glVertex2f(-.35, 0.35);
    glVertex2f(-0.4, 0.35);
    glVertex2f(-0.4, -0.4);
    glEnd();

    glPointSize(2.5);
    glBegin(GL_POINTS);
    glColor3ub(255, 26, 26);
    glVertex2f(0 - .35f, 0.15f);
    glVertex2f(-0.375f, 0.15f);
    glVertex2f(-0.4f, 0.15f);
    glVertex2f(-0.35f, 0.25f);
    glVertex2f(-0.375f, 0.25f);
    glVertex2f(-0.4f, 0.25f);

    glVertex2f(0 - .35f, 0.35f);
    glVertex2f(-0.375f, 0.35f);
    glVertex2f(-0.4f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(-.36, 0.35);
    glVertex2f(-.36, 0.37);
    glVertex2f(-0.39, 0.37);
    glVertex2f(-0.39, 0.35);
    glEnd();

    glBegin(GL_QUADS); // fst mota
    glColor3ub(89, 89, 89);
    glVertex2f(-.345, 0.37);
    glVertex2f(-.345, 0.45);
    glVertex2f(-0.405, 0.45);
    glVertex2f(-0.405, 0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(-.36, 0.45);
    glVertex2f(-.36, 0.47);
    glVertex2f(-0.39, 0.47);
    glVertex2f(-0.39, 0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(-.35, 0.47);
    glVertex2f(-.35, 0.48);
    glVertex2f(-0.40, 0.48);
    glVertex2f(-0.40, 0.47);
    glEnd();

    glBegin(GL_QUADS); // 2nd mota
    glColor3ub(89, 89, 89);
    glVertex2f(-.33, 0.48);
    glVertex2f(-.33, 0.54);
    glVertex2f(-0.42, 0.54);
    glVertex2f(-0.42, 0.48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(-.36, 0.54);
    glVertex2f(-.36, 0.56);
    glVertex2f(-0.39, 0.56);
    glVertex2f(-0.39, 0.54);
    glEnd();

    glBegin(GL_QUADS); // dandi
    glColor3ub(89, 89, 89);
    glVertex2f(-.38, 0.56);
    glVertex2f(-.38, 0.8);
    glVertex2f(-0.385, 0.8);
    glVertex2f(-0.385, 0.56);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(-.365, 0.56);
    glVertex2f(-.365, 0.8);
    glVertex2f(-0.37, 0.8);
    glVertex2f(-0.37, 0.56);
    glEnd();

    glBegin(GL_QUADS); // dandi matha
    glColor3ub(89, 89, 89);
    glVertex2f(-.365, 0.8);
    glVertex2f(-.365, 0.81);
    glVertex2f(-0.385, 0.81);
    glVertex2f(-0.385, 0.8);
    glEnd();

    // thamba dim

    // left blding 6

    glBegin(GL_QUADS);
    glColor3ub(204, 153, 102);
    glVertex2f(-.2, -0.4);
    glVertex2f(-.2, -0.09);
    glVertex2f(-0.3, -0.09);
    glVertex2f(-0.3, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(198, 140, 83);
    glVertex2f(-.3, -0.4);
    glVertex2f(-.3, -0.09);
    glVertex2f(-0.37, -0.09);
    glVertex2f(-0.37, -0.4);
    glEnd();
    // Glass
    glBegin(GL_QUADS);
    glColor3ub(214, 214, 194);
    glVertex2f(-.31, -0.4);
    glVertex2f(-.31, -0.10);
    glVertex2f(-0.365, -0.10);
    glVertex2f(-0.365, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.21, -0.4);
    glVertex2f(-.21, -0.10);
    glVertex2f(-0.29, -0.10);
    glVertex2f(-0.29, -0.4);
    glEnd();

    // left blding 7

    glBegin(GL_QUADS);
    glColor3ub(117, 163, 163);
    glVertex2f(-.1, -0.4);
    glVertex2f(-.1, -0.15);
    glVertex2f(-0.15, -0.15);
    glVertex2f(-0.15, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 153, 153);
    glVertex2f(-.15, -0.4);
    glVertex2f(-.15, -0.15);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.2, -0.4);
    glEnd();
    // Glass
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.16);
    glVertex2f(-.103, -0.17);
    glVertex2f(-0.145, -0.17);
    glVertex2f(-0.145, -0.16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.18);
    glVertex2f(-.103, -0.19);
    glVertex2f(-0.145, -0.19);
    glVertex2f(-0.145, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.20);
    glVertex2f(-.103, -0.21);
    glVertex2f(-0.145, -0.21);
    glVertex2f(-0.145, -0.20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.22);
    glVertex2f(-.103, -0.23);
    glVertex2f(-0.145, -0.23);
    glVertex2f(-0.145, -0.22);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.24);
    glVertex2f(-.103, -0.25);
    glVertex2f(-0.145, -0.25);
    glVertex2f(-0.145, -0.24);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.26);
    glVertex2f(-.103, -0.27);
    glVertex2f(-0.145, -0.27);
    glVertex2f(-0.145, -0.26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.28);
    glVertex2f(-.103, -0.29);
    glVertex2f(-0.145, -0.29);
    glVertex2f(-0.145, -0.28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.30);
    glVertex2f(-.103, -0.31);
    glVertex2f(-0.145, -0.31);
    glVertex2f(-0.145, -0.30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.32);
    glVertex2f(-.103, -0.33);
    glVertex2f(-0.145, -0.33);
    glVertex2f(-0.145, -0.32);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.34);
    glVertex2f(-.103, -0.35);
    glVertex2f(-0.145, -0.35);
    glVertex2f(-0.145, -0.34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.103, -0.36);
    glVertex2f(-.103, -0.37);
    glVertex2f(-0.145, -0.37);
    glVertex2f(-0.145, -0.36);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.16);
    glVertex2f(-.155, -0.17);
    glVertex2f(-0.195, -0.17);
    glVertex2f(-0.195, -0.16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.18);
    glVertex2f(-.155, -0.19);
    glVertex2f(-0.195, -0.19);
    glVertex2f(-0.195, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.20);
    glVertex2f(-.155, -0.21);
    glVertex2f(-0.195, -0.21);
    glVertex2f(-0.195, -0.20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.22);
    glVertex2f(-.155, -0.23);
    glVertex2f(-0.195, -0.23);
    glVertex2f(-0.195, -0.22);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.24);
    glVertex2f(-.155, -0.25);
    glVertex2f(-0.195, -0.25);
    glVertex2f(-0.195, -0.24);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.26);
    glVertex2f(-.155, -0.27);
    glVertex2f(-0.195, -0.27);
    glVertex2f(-0.195, -0.26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.28);
    glVertex2f(-.155, -0.29);
    glVertex2f(-0.195, -0.29);
    glVertex2f(-0.195, -0.28);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.30);
    glVertex2f(-.155, -0.31);
    glVertex2f(-0.195, -0.31);
    glVertex2f(-0.195, -0.30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.32);
    glVertex2f(-.155, -0.33);
    glVertex2f(-0.195, -0.33);
    glVertex2f(-0.195, -0.32);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.34);
    glVertex2f(-.155, -0.35);
    glVertex2f(-0.195, -0.35);
    glVertex2f(-0.195, -0.34);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(224, 224, 209);
    glVertex2f(-.155, -0.36);
    glVertex2f(-.155, -0.37);
    glVertex2f(-0.195, -0.37);
    glVertex2f(-0.195, -0.36);
    glEnd();

    // choto thamba

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-.14, -0.15);
    glVertex2f(-.14, 0.05);
    glVertex2f(-0.144, 0.05);
    glVertex2f(-0.144, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-.16, -0.15);
    glVertex2f(-.16, 0.05);
    glVertex2f(-0.164, 0.05);
    glVertex2f(-0.164, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-.14, -0.0);
    glVertex2f(-.14, 0.05);
    glVertex2f(-0.164, 0.05);
    glVertex2f(-0.164, -0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex2f(-.151, 0.05);
    glVertex2f(-.151, 0.09);
    glVertex2f(-0.153, 0.09);
    glVertex2f(-0.153, 0.05);
    glEnd();

    glBegin(GL_QUADS); // lite
    glColor3ub(255, 0, 0);
    glVertex2f(-.151, 0.09);
    glVertex2f(-.151, 0.095);
    glVertex2f(-0.153, 0.095);
    glVertex2f(-0.153, 0.09);
    glEnd();
    // left blding 8

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 204);
    glVertex2f(-.05, -0.5);
    glVertex2f(-.05, -0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, -0.5);
    glEnd();

    generate_trees();
    // grass

    glBegin(GL_QUADS);
    glColor3ub(102, 153, 0);
    glVertex2f(1.0, -0.53);
    glVertex2f(1.0, -0.50);
    glVertex2f(-1.0, -0.50);
    glVertex2f(-1.0, -0.53);
    glEnd();

    // road1

    glBegin(GL_QUADS);
    glColor3ub(115, 115, 115);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -0.53);
    glVertex2f(-1.0, -0.53);
    glVertex2f(-1.0, -0.6);
    glEnd();

    glBegin(GL_QUADS); // road line
    glColor3ub(230, 255, 255);
    glVertex2f(1.0, -0.54);
    glVertex2f(1.0, -0.5390);
    glVertex2f(-1.0, -0.5390);
    glVertex2f(-1.0, -0.54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.50, -0.565);
    glVertex2f(-0.50, -0.557);
    glVertex2f(-1.0, -0.557);
    glVertex2f(-1.0, -0.565);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.20, -0.565);
    glVertex2f(0.20, -0.557);
    glVertex2f(-0.30, -0.557);
    glVertex2f(-0.30, -0.565);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.40, -0.565);
    glVertex2f(0.40, -0.557);
    glVertex2f(0.90, -0.557);
    glVertex2f(0.90, -0.565);
    glEnd();

    // car
    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(.23, -0.58);
    glVertex2f(.23, -0.55);
    glVertex2f(.32, -0.55);
    glVertex2f(.32, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(.26, -0.55);
    glVertex2f(.26, -0.51);
    glVertex2f(.313, -0.51);
    glVertex2f(.313, -0.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.265, -0.55);
    glVertex2f(.265, -0.515);
    glVertex2f(.309, -0.515);
    glVertex2f(.309, -0.55);
    glEnd();

    glColor3ub(7, 8, 7);
    float x = .25f;
    float y = -.578f;
    float radius = .01f;
    create_circle(radius, x, y, 20);

    glColor3ub(7, 8, 7);
    x = .30f;
    y = -.578f;
    radius = .01f;
    create_circle(radius, x, y, 20);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(1.0, -0.595);
    glVertex2f(1.0, -0.590);
    glVertex2f(-1.0, -0.590);
    glVertex2f(-1.0, -0.595);
    glEnd();

    // grass 2

    glBegin(GL_QUADS);
    glColor3ub(102, 153, 0);
    glVertex2f(1.0, -0.61);
    glVertex2f(1.0, -0.6);
    glVertex2f(-1.0, -0.6);
    glVertex2f(-1.0, -0.61);
    glEnd();

    // road 2

    glBegin(GL_QUADS);
    glColor3ub(115, 115, 115);
    glVertex2f(1.0, -0.7);
    glVertex2f(1.0, -0.6195);
    glVertex2f(-1.0, -0.6195);
    glVertex2f(-1.0, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(1.0, -0.6295);
    glVertex2f(1.0, -0.625);
    glVertex2f(-1.0, -0.625);
    glVertex2f(-1.0, -0.6295);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(1.0, -0.695);
    glVertex2f(1.0, -0.69);
    glVertex2f(-1.0, -0.69);
    glVertex2f(-1.0, -0.695);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-.5, -0.66);
    glVertex2f(-.50, -0.67);
    glVertex2f(-1.0, -0.67);
    glVertex2f(-1.0, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(.2, -0.66);
    glVertex2f(.20, -0.67);
    glVertex2f(-.30, -0.67);
    glVertex2f(-.30, -0.66);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(.4, -0.66);
    glVertex2f(.40, -0.67);
    glVertex2f(.90, -0.67);
    glVertex2f(.90, -0.66);
    glEnd();

    // car3
    glPushMatrix();
    glTranslatef(position13, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(184, 0, 230);
    glVertex2f(-.23, -0.68);
    glVertex2f(-.23, -0.65);
    glVertex2f(-.32, -0.65);
    glVertex2f(-.32, -0.68);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(184, 0, 230);
    glVertex2f(-.26, -0.65);
    glVertex2f(-.26, -0.61);
    glVertex2f(-.313, -0.61);
    glVertex2f(-.313, -0.65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-.265, -0.65);
    glVertex2f(-.265, -0.615);
    glVertex2f(-.309, -0.615);
    glVertex2f(-.309, -0.65);
    glEnd();

    glColor3ub(7, 8, 7);
    x = -.25f;
    y = -.678f;
    radius = .01f;
    create_circle(radius, x, y, 20);
    x = -.30f;
    y = -.678f;
    radius = .01f;
    create_circle(radius, x, y, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(position14, 0.0f, 0.0f);
    // car4
    glBegin(GL_QUADS);
    glColor3ub(255, 77, 136);
    glVertex2f(.23, -0.68);
    glVertex2f(.23, -0.65);
    glVertex2f(.32, -0.65);
    glVertex2f(.32, -0.68);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 77, 136);
    glVertex2f(.29, -0.65);
    glVertex2f(.29, -0.61);
    glVertex2f(.24, -0.61);
    glVertex2f(.24, -0.65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(.285, -0.65);
    glVertex2f(.285, -0.615);
    glVertex2f(.245, -0.615);
    glVertex2f(.245, -0.65);
    glEnd();

    glColor3ub(7, 8, 7);
    x = .25f;
    y = -.678f;
    radius = .01f;
    create_circle(radius, x, y, 20);

    x = .30f;
    y = -.678f;
    radius = .01f;
    create_circle(radius, x, y, 20);
    glPopMatrix();

    // grass 3
    glBegin(GL_QUADS);
    glColor3ub(102, 153, 0);
    glVertex2f(1.0, -0.71);
    glVertex2f(1.0, -0.7);
    glVertex2f(-1.0, -0.7);
    glVertex2f(-1.0, -0.71);
    glEnd();

    // road 3
    glBegin(GL_QUADS);
    glColor3ub(115, 115, 115);
    glVertex2f(1.0, -0.8);
    glVertex2f(1.0, -0.7195);
    glVertex2f(-1.0, -0.7195);
    glVertex2f(-1.0, -0.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(1.0, -0.7295);
    glVertex2f(1.0, -0.725);
    glVertex2f(-1.0, -0.725);
    glVertex2f(-1.0, -0.7295);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(1.0, -0.795);
    glVertex2f(1.0, -0.79);
    glVertex2f(-1.0, -0.79);
    glVertex2f(-1.0, -0.795);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-.5, -0.76);
    glVertex2f(-.50, -0.77);
    glVertex2f(-1.0, -0.77);
    glVertex2f(-1.0, -0.76);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(.2, -0.76);
    glVertex2f(.20, -0.77);
    glVertex2f(-.30, -0.77);
    glVertex2f(-.30, -0.76);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(.4, -0.76);
    glVertex2f(.40, -0.77);
    glVertex2f(.90, -0.77);
    glVertex2f(.90, -0.76);
    glEnd();

    // car2
    glPushMatrix();
    glTranslatef(position3, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(.43, -0.78);
    glVertex2f(.43, -0.75);
    glVertex2f(.52, -0.75);
    glVertex2f(.52, -0.78);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(.46, -0.75);
    glVertex2f(.46, -0.71);
    glVertex2f(.513, -0.71);
    glVertex2f(.513, -0.75);
    glVertex2f(.465, -0.715);
    glVertex2f(.509, -0.715);
    glVertex2f(.509, -0.75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(.49, -0.71);
    glVertex2f(.49, -0.702);
    glVertex2f(.5, -0.702);
    glVertex2f(.5, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(.465, -0.75);
    glVertex2f(.465, -0.715);
    glVertex2f(.509, -0.715);
    glVertex2f(.509, -0.75);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(.49, -0.71);
    glVertex2f(.49, -0.702);
    glVertex2f(.5, -0.702);
    glVertex2f(.5, -0.71);
    glEnd();

    glColor3ub(7, 8, 7);
    x = .45f;
    y = -.778f;
    radius = .01f;
    create_circle(radius, x, y, 20);

    x = .50f;
    y = -.778f;
    radius = .01f;
    create_circle(radius, x, y, 20);
    glPopMatrix();

    // grass4
    glBegin(GL_QUADS);
    glColor3ub(102, 153, 0);
    glVertex2f(1.0, -0.8);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(-1.0, -0.8);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("City at Night");
    glutInitWindowSize(700, 700);
    glutDisplayFunc(display);
    glutTimerFunc(100, update_white_car, 0);
    glutTimerFunc(100, update_blue_car, 0);
    glutTimerFunc(100, update_purple_car, 0);
    glutTimerFunc(100, update_red_car, 0);
    glutTimerFunc(100, update_airplane, 0);
    glutMainLoop();
    return 0;
}
a