//sazzad ul alam shawon (19-39385-1) AIUB
//sazzadulalambd
//sazzadulalamshawon@gmail.com
//https://www.facebook.com/sazzadulalamshawonbd
//https://www.facebook.com/ProgrammingwithSUAS
//https://youtu.be/JgbkEQfEqCQ

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

# define PI 3.14159265358979323846

using namespace std;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * PI;

float vehicleSpeed = .003f;

bool night = false;
bool on = false;
bool cover = false;
bool vehicleStop = false;
bool rain = false;
bool waveUp = true;
bool handup= false;

float _crashB2 = 0.0f;
float _crashB1 = 0.0f;

float _rain1x = 0.0;
float _rain2x = 0.0;
float _rain3x = 0.0;
float _rain4x = 0.0;
float _rain5x = 0.0;
float _rain6x = 0.0;
float _rain7x = 0.0;
float _rain8x = 0.0;
float _rain9x = 0.0;
float _rain10x = 0.0;
float _rain11x = 0.0;

float _rain1y = 0.0;
float _rain2y = 0.0;
float _rain3y = 0.0;
float _rain4y = 0.0;
float _rain5y = 0.0;
float _rain6y = 0.0;
float _rain7y = 0.0;
float _rain8y = 0.0;
float _rain9y = 0.0;
float _rain10y = 0.0;
float _rain11y = 0.0;
float _rain12y = 0.0;
float _rain13y = 0.0;
float _rain14y = 0.0;
float _rain15y = 0.0;

int i = 0;

float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;
float _run4 = 0.0;
float _run5 = 0.0;  ///green car
float _run6 = 0.0;
float _run7 = 0.0;  ///red bus
float _run8 = 0.0;
float _run9 = 0.0;
float _run10 = 0.0;
float _run11 = 0.0;

float c1 = 0.00;
float c2 = 0.00;
float c3 = 0.00;
float c4 = 0.00;
float c5 = 0.00;
float c6 = 0.00;
float c7 = 0.00;
float c8 = 0.00;
float c9 = 0.00;
float c10 = 0.00;
float c11 = 0.00;
float c12 = 0.00;
float c13 = 0.00;
float c14 = 0.00;
float c15 = 0.00;
float c16 = 0.00;
float c17 = 0.00;

void resetRain()
{
    _rain1y = 0.0;
    _rain2y = 0.0;
    _rain3y = 0.0;
    _rain4y = 0.0;
    _rain5y = 0.0;
    _rain6y = 0.0;
    _rain7y = 0.0;
    _rain8y = 0.0;
    _rain9y = 0.0;
    _rain10y = 0.0;

    i = 0;
}

void clearColor(float r, float g, float b,float bb)
{
    glClearColor(r,g,b,bb);
}

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display()
{
    clearColor(0.0f, 0.7f, 0.4f, 1.0f);
    if(night)
    {
        clearColor(0.07, 0.30, 0.15, 1);
    }


    glClear(GL_COLOR_BUFFER_BIT);



//sky...............................................................................................................

    glBegin(GL_QUADS);

    glColor3f(0.4f,0.69f,1.0f);
    if(rain && !night)
    {
        glColor3f(0.18, 0.36, 0.56);
    }
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    if(night)
    {
        glColor3f(0.2, 0.2, 0.40);
        glVertex2f(-1.0f, 0.5f);
        glVertex2f(-1.0f, 1.0f);
        glColor3f(0.0, 0.01, 0.02);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, 0.5f);

    }
    glEnd();



    // sun
    if(!night)
    {
        GLfloat xs1=0.2f;
        GLfloat ys1=0.85f;
        GLfloat radiuss1 =0.05f;
        glColor3f(0.95f,0.95f,0.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xs1, ys1);
        //GLfloat twicePi = 2.0f * PI;
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( xs1 + (radiuss1 * cos(i *  twicePi / triangleAmount)),
                        ys1 + (radiuss1 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
    }


    // moon
    if(night)
    {
        GLfloat xsm1=0.78f;
        GLfloat ysm1=0.9f;
        GLfloat radiussm1 =0.05f;
        glColor3f(1.0f,1.0f,1.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xsm1, ysm1);
        //GLfloat twicePi = 2.0f * PI;
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( xsm1 + (radiussm1 * cos(i *  twicePi / triangleAmount)),
                        ysm1 + (radiussm1 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();



        GLfloat xsm2=0.8f;
        GLfloat ysm2=0.9f;
        glColor3f(0.0, 0.01, 0.02);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xsm2, ysm2);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( xsm2 + (radiussm1 * cos(i *  twicePi / triangleAmount)),
                        ysm2 + (radiussm1 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

    }

    // star
    if(night && !rain)
    {
        glBegin(GL_POINTS);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.9f, 0.9f);

        glVertex2f(-0.7f, 0.9f);

        glVertex2f(-0.5f, 0.9f);

        glVertex2f(-0.3f, 0.9f);

        glVertex2f(-0.1f, 0.9f);

        glVertex2f(0.1f, 0.9f);

        glVertex2f(0.3f, 0.9f);

        glVertex2f(0.5f, 0.9f);

        glVertex2f(0.7f, 0.9f);

        glVertex2f(0.9f, 0.9f);

        glVertex2f(-0.98f, 0.93f);

        glVertex2f(-0.88f, 0.94f);

        glVertex2f(-0.68f, 0.91f);

        glVertex2f(-0.55f, 0.92f);

        glVertex2f(-0.45f, 0.93f);

        glVertex2f(-0.25f, 0.94f);

        glVertex2f(0.0f, 0.9f);

        glVertex2f(0.13f, 0.91f);

        glVertex2f(0.25f, 0.92f);

        glVertex2f(0.37f, 0.93f);

        glVertex2f(0.49f, 0.92f);

        glVertex2f(-0.8f, 0.85f);

        glVertex2f(-0.6f, 0.85f);

        glVertex2f(-0.4f, 0.85f);

        glVertex2f(-0.2f, 0.85f);

        glVertex2f(0.0f, 0.85f);

        glVertex2f(0.2f, 0.85f);

        glVertex2f(0.4f, 0.85f);

        glVertex2f(0.6f, 0.85f);

        glVertex2f(0.8f, 0.85f);

        glVertex2f(1.0f, 0.85f);

        glEnd();
    }


//......................................................................................................................
//hill3

    glPushMatrix();
    glTranslatef(0.3f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.2f,0.0f);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, 0.65f);


    glVertex2f(-1.0f, 0.65f);
    glVertex2f(-0.97f, 0.68f);

    glVertex2f(-0.97f, 0.68f);
    glVertex2f(-0.95f, 0.66f);

    glVertex2f(-0.95f, 0.66f);
    glVertex2f(-0.9f, 0.77f);

    glVertex2f(-0.9f, 0.77f);
    glVertex2f(-0.87f, 0.73f);

    glVertex2f(-0.87f, 0.73f);
    glVertex2f(-0.84f, 0.66f);

    glVertex2f(-0.84f, 0.66f);
    glVertex2f(-0.8f, 0.7f);

    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.78f, 0.68f);

    glVertex2f(-0.78f, 0.68f);
    glVertex2f(-0.73f, 0.73f);

    glVertex2f(-0.73f, 0.73f);
    glVertex2f(-0.68f, 0.64f);

    glVertex2f(-0.68f, 0.64f);
    glVertex2f(-0.65f, 0.67f);

    glVertex2f(-0.65f, 0.67f);
    glVertex2f(-0.58f, 0.58f);

    glVertex2f(-0.58f, 0.58f);
    glVertex2f(-0.55f, 0.6f);

    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.5f, 0.5f);



    glEnd();


    glPopMatrix();

//hill01
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.4f,0.0f);
    if(night)
    {
        glColor3f(0.09, 0.20, 0.09);
    }
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, 0.65f);


    glVertex2f(-1.0f, 0.65f);
    glVertex2f(-0.97f, 0.68f);

    glVertex2f(-0.97f, 0.68f);
    glVertex2f(-0.95f, 0.66f);

    glVertex2f(-0.95f, 0.66f);
    glVertex2f(-0.9f, 0.75f);

    glVertex2f(-0.9f, 0.75f);
    glVertex2f(-0.87f, 0.73f);

    glVertex2f(-0.87f, 0.73f);
    glVertex2f(-0.84f, 0.66f);

    glVertex2f(-0.84f, 0.66f);
    glVertex2f(-0.8f, 0.7f);

    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.78f, 0.68f);

    glVertex2f(-0.78f, 0.68f);
    glVertex2f(-0.73f, 0.73f);

    glVertex2f(-0.73f, 0.73f);
    glVertex2f(-0.68f, 0.64f);

    glVertex2f(-0.68f, 0.64f);
    glVertex2f(-0.65f, 0.67f);

    glVertex2f(-0.65f, 0.67f);
    glVertex2f(-0.58f, 0.58f);

    glVertex2f(-0.58f, 0.58f);
    glVertex2f(-0.55f, 0.6f);

    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.5f, 0.5f);



    glEnd();


    //hill5

    glPushMatrix();
    glTranslatef(0.8f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.2f,0.0f);
    if(night)
    {
        glColor3f(0.08, 0.19, 0.08);
    }


    glVertex2f(-0.65f, 0.5f);
    glVertex2f(-0.63f, 0.55f);

    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.61f, 0.53f);

    glVertex2f(-0.61f, 0.53f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.52f, 0.63f);

    glVertex2f(-0.52f, 0.63f);
    glVertex2f(-0.5f, 0.68f);

    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-0.47f, 0.66f);

    glVertex2f(-0.47f, 0.66f);
    glVertex2f(-0.44f, 0.73f);

    glVertex2f(-0.44f, 0.73f);
    glVertex2f(-0.4f, 0.7f);

    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.35f, 0.62f);

    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.3f, 0.66f);

    glVertex2f(-0.3f, 0.66f);
    glVertex2f(-0.28f, 0.63f);

    glVertex2f(-0.28f, 0.63f);
    glVertex2f(-0.24f, 0.69f);

    glVertex2f(-0.24f, 0.69f);
    glVertex2f(-0.18f, 0.58f);

    glVertex2f(-0.18f, 0.58f);
    glVertex2f(-0.15f, 0.6f);

    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.11f, 0.55f);

    glVertex2f(-0.11f, 0.55f);
    glVertex2f(-0.1f, 0.5f);

    glEnd();

    glPopMatrix();

    //hill4

    glPushMatrix();
    glTranslatef(0.78f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.3f,0.0f);
    if(night)
    {
        glColor3f(0.12, 0.28, 0.12);
    }
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, 0.65f);


    glVertex2f(-1.0f, 0.65f);
    glVertex2f(-0.97f, 0.68f);

    glVertex2f(-0.97f, 0.68f);
    glVertex2f(-0.95f, 0.66f);

    glVertex2f(-0.95f, 0.66f);
    glVertex2f(-0.9f, 0.75f);

    glVertex2f(-0.9f, 0.75f);
    glVertex2f(-0.87f, 0.73f);

    glVertex2f(-0.87f, 0.73f);
    glVertex2f(-0.84f, 0.66f);

    glVertex2f(-0.84f, 0.66f);
    glVertex2f(-0.8f, 0.7f);

    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.78f, 0.68f);

    glVertex2f(-0.78f, 0.68f);
    glVertex2f(-0.73f, 0.73f);

    glVertex2f(-0.73f, 0.73f);
    glVertex2f(-0.68f, 0.64f);

    glVertex2f(-0.68f, 0.64f);
    glVertex2f(-0.65f, 0.67f);

    glVertex2f(-0.65f, 0.67f);
    glVertex2f(-0.58f, 0.58f);

    glVertex2f(-0.58f, 0.58f);
    glVertex2f(-0.55f, 0.6f);

    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.5f, 0.5f);



    glEnd();


    glPopMatrix();

//hill6

    glPushMatrix();
    glTranslatef(1.3f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.3f,0.0f);
    if(night)
    {
        glColor3f(0.00, 0.20, 0.00);
    }

    glVertex2f(-0.65f, 0.5f);
    glVertex2f(-0.63f, 0.55f);

    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.61f, 0.53f);

    glVertex2f(-0.61f, 0.53f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.52f, 0.63f);

    glVertex2f(-0.52f, 0.63f);
    glVertex2f(-0.5f, 0.68f);

    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-0.47f, 0.66f);

    glVertex2f(-0.47f, 0.66f);
    glVertex2f(-0.44f, 0.73f);

    glVertex2f(-0.44f, 0.73f);
    glVertex2f(-0.4f, 0.7f);

    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.35f, 0.62f);

    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.3f, 0.66f);

    glVertex2f(-0.3f, 0.66f);
    glVertex2f(-0.28f, 0.63f);

    glVertex2f(-0.28f, 0.63f);
    glVertex2f(-0.24f, 0.69f);

    glVertex2f(-0.24f, 0.69f);
    glVertex2f(-0.18f, 0.58f);

    glVertex2f(-0.18f, 0.58f);
    glVertex2f(-0.15f, 0.6f);

    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.11f, 0.55f);

    glVertex2f(-0.11f, 0.55f);
    glVertex2f(-0.1f, 0.5f);

    glEnd();

    glPopMatrix();


//hill2
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.5f,0.0f);
    if(night)
    {
        glColor3f(0.13, 0.31, 0.13);
    }

    glVertex2f(-0.65f, 0.5f);
    glVertex2f(-0.63f, 0.55f);

    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.61f, 0.53f);

    glVertex2f(-0.61f, 0.53f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.52f, 0.63f);

    glVertex2f(-0.52f, 0.63f);
    glVertex2f(-0.5f, 0.68f);

    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-0.47f, 0.66f);

    glVertex2f(-0.47f, 0.66f);
    glVertex2f(-0.44f, 0.73f);

    glVertex2f(-0.44f, 0.73f);
    glVertex2f(-0.4f, 0.7f);

    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.35f, 0.62f);

    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.3f, 0.66f);

    glVertex2f(-0.3f, 0.66f);
    glVertex2f(-0.28f, 0.63f);

    glVertex2f(-0.28f, 0.63f);
    glVertex2f(-0.24f, 0.69f);

    glVertex2f(-0.24f, 0.69f);
    glVertex2f(-0.18f, 0.58f);

    glVertex2f(-0.18f, 0.58f);
    glVertex2f(-0.15f, 0.6f);

    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.11f, 0.55f);

    glVertex2f(-0.11f, 0.55f);
    glVertex2f(-0.1f, 0.5f);

    glEnd();

//cloud1........................................................................
    glPushMatrix();
    glTranslatef(_run1,0,0);

    glPushMatrix();
    glTranslatef(0.05f, 0.14f, 0.0f);
    glScalef(.7,.8,0);

    GLfloat xm1=-0.8f;
    GLfloat ym1=0.9f;
    GLfloat radiusm1 =0.08f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xm1, ym1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xm1 + (radiusm1 * cos(i *  twicePi / triangleAmount)),
                    ym1 + (radiusm1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xm2=-0.72f;
    GLfloat ym2=0.9f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xm2, ym2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xm2 + (radiusm1 * cos(i *  twicePi / triangleAmount)),
                    ym2 + (radiusm1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xm3=-0.77f;
    GLfloat ym3=0.82f;
    GLfloat radiusm2 =0.05f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xm3, ym3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xm3 + (radiusm2 * cos(i *  twicePi / triangleAmount)),
                    ym3 + (radiusm2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xm4=-0.85f;
    GLfloat ym4=0.82f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xm4, ym4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xm4 + (radiusm2 * cos(i *  twicePi / triangleAmount)),
                    ym4 + (radiusm2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xm5=-0.69f;
    GLfloat ym5=0.82f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xm5, ym5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xm5 + (radiusm2 * cos(i *  twicePi / triangleAmount)),
                    ym5 + (radiusm2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();
    glPopMatrix();

    glPopMatrix();


    //cloud2....................................................................
    glPushMatrix();
    glTranslatef(_run2,0,0);

    glPushMatrix();
    glTranslatef(0.3f, 0.4f, 0.0f);
    glScalef(.6,.6,0);

    GLfloat xcl1=0.8f;
    GLfloat ycl1=0.83f;
    GLfloat radiusm3 =0.08f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xcl1, ycl1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xcl1 + (radiusm1 * cos(i *  twicePi / triangleAmount)),
                    ycl1 + (radiusm1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xcl2=0.84f;
    GLfloat ycl2=0.76f;
    GLfloat radiusm4 =0.08f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xcl2, ycl2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xcl2 + (radiusm4 * cos(i *  twicePi / triangleAmount)),
                    ycl2 + (radiusm4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xcl3=0.725f;
    GLfloat ycl3=0.79f;
    GLfloat radiusm5 =0.092f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xcl3, ycl3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xcl3 + (radiusm5 * cos(i *  twicePi / triangleAmount)),
                    ycl3 + (radiusm5* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xcl4=0.72f;
    GLfloat ycl4=0.88f;
    GLfloat radiusm6 =0.06f;
    glColor3f(0.95f,0.95f,0.95);
    if(night)
    {
        glColor3f(0.5f,0.5f,0.5);
    }
    if(rain && !night)
    {
        glColor3f(0.43, 0.63, 0.85);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xcl4, ycl4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xcl4 + (radiusm6* cos(i *  twicePi / triangleAmount)),
                    ycl4 + (radiusm6* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPopMatrix();

    // rail line....................................................................................................

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);

    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.01f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.03f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.06f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.07f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.09f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.11f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.12f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.13f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.14f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.17f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.18f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.19f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.21f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.22f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.23f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.25f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.26f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.27f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.28f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.29f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.3f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.31f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.32f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.33f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.34f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.36f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.37f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.38f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.39f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.41f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.42f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.43f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.44f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.45f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.46f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.47f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.49f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.51f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.52f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.53f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.54f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.55f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.56f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.57f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.58f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.59f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.61f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.62f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.63f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.64f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.65f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.66f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.67f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.68f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.69f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.71f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.72f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.73f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.74f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.75f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.76f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.77f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.78f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.79f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.81f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.82f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.83f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.84f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.85f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.86f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.87f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.89f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.91f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.92f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.93f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.94f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.95f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.96f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.97f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.98f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.99f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    //again

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.01f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.03f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.06f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.07f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.09f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.11f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.12f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.13f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.14f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.16f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.17f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.18f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.19f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.21f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.22f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.23f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.25f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.26f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.27f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.28f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.29f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.3f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.31f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.32f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.33f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.34f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.36f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.37f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.38f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.39f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.41f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.42f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.43f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.44f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.45f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.46f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.47f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.49f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.51f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.52f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.53f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.54f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.55f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.56f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.57f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.58f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.59f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.61f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.62f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.63f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.64f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.65f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.66f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.67f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.68f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.69f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.71f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.72f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.73f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.74f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.75f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.76f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.77f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.78f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.79f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.81f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.82f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.83f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.84f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.85f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.86f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.87f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.89f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.91f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.92f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.93f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.94f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.95f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.96f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.97f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.98f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.99f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-0.995f, 0.45f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0f, 0.467f);
    glVertex2f(1.0f,0.467f);
    glVertex2f(1.0f,0.46f);
    glVertex2f(-1.0f,0.46f);

    glVertex2f(-1.0f, 0.485f);
    glVertex2f(1.0f,0.485f);
    glVertex2f(1.0f, 0.49f);
    glVertex2f(-1.0f, 0.49f);

    glEnd();


    // rail line end /////////////////////////////////////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<??????????

    //rail start/////////////////////.......................



    glPushMatrix();
    glTranslatef(_run3,0,0);

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f);
    glVertex2f(0.02f,0.51f);
    glVertex2f(0.105f,0.51f);
    glVertex2f(0.105f,0.46f);
    glVertex2f(0.0f,0.46f);

    glColor3f(0.0f,0.3f,0.6f);
    glVertex2f(0.02f,0.505f);
    glVertex2f(0.1f,0.505f);
    glVertex2f(0.1f,0.5f);
    glVertex2f(0.02f,0.5f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.02f,0.476f);
    glVertex2f(0.1f,0.476f);
    glVertex2f(0.1f,0.465f);
    glVertex2f(0.02f,0.465f);

    glColor3f(0.0f,0.3f,0.6f);
    glVertex2f(0.025f,0.471f);
    glVertex2f(0.1f,0.471f);
    glVertex2f(0.1f,0.465f);
    glVertex2f(0.021f,0.465f);
//..
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.012f,0.495f);
    glVertex2f(0.019f,0.495f);
    glVertex2f(0.019f,0.48f);
    glVertex2f(0.007f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.022f,0.495f);
    glVertex2f(0.03f,0.495f);
    glVertex2f(0.03f,0.48f);
    glVertex2f(0.022f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.032f,0.495f);
    glVertex2f(0.04f,0.495f);
    glVertex2f(0.04f,0.48f);
    glVertex2f(0.032f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.042f,0.495f);
    glVertex2f(0.05f,0.495f);
    glVertex2f(0.05f,0.48f);
    glVertex2f(0.042f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.052f,0.495f);
    glVertex2f(0.06f,0.495f);
    glVertex2f(0.06f,0.48f);
    glVertex2f(0.052f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.062f,0.495f);
    glVertex2f(0.07f,0.495f);
    glVertex2f(0.07f,0.48f);
    glVertex2f(0.062f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.072f,0.495f);
    glVertex2f(0.08f,0.495f);
    glVertex2f(0.08f,0.48f);
    glVertex2f(0.072f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.082f,0.495f);
    glVertex2f(0.09f,0.495f);
    glVertex2f(0.09f,0.48f);
    glVertex2f(0.082f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.092f,0.495f);
    glVertex2f(0.099f,0.495f);
    glVertex2f(0.099f,0.48f);
    glVertex2f(0.092f,0.48f);

    glEnd();




    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f);
    glVertex2f(0.205f,0.51f);
    glVertex2f(0.102f,0.51f);
    glVertex2f(0.102f,0.46f);
    glVertex2f(0.205f,0.46f);

    glColor3f(0.0f,0.3f,0.6f);
    glVertex2f(0.199f,0.505f);
    glVertex2f(0.102f,0.505f);
    glVertex2f(0.102f,0.5f);
    glVertex2f(0.199f,0.5f);


    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.11f,0.465f);
    glVertex2f(0.105f,0.465f);
    glVertex2f(0.105f,0.5f);
    glVertex2f(0.11f,0.5f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.199f,0.476f);
    glVertex2f(0.105f,0.476f);
    glVertex2f(0.105f,0.465f);
    glVertex2f(0.199f,0.465f);

    glColor3f(0.0f,0.3f,0.6f);
    glVertex2f(0.11f,0.471f);
    glVertex2f(0.199f,0.471f);
    glVertex2f(0.199f,0.465f);
    glVertex2f(0.107f,0.465f);

//windus
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.12f,0.495f);
    glVertex2f(0.112f,0.495f);
    glVertex2f(0.112f,0.48f);
    glVertex2f(0.12f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.13f,0.495f);
    glVertex2f(0.122f,0.495f);
    glVertex2f(0.122f,0.48f);
    glVertex2f(0.13f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.14f,0.495f);
    glVertex2f(0.132f,0.495f);
    glVertex2f(0.132f,0.48f);
    glVertex2f(0.14f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.15f,0.495f);
    glVertex2f(0.142f,0.495f);
    glVertex2f(0.142f,0.48f);
    glVertex2f(0.15f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.16f,0.495f);
    glVertex2f(0.152f,0.495f);
    glVertex2f(0.152f,0.48f);
    glVertex2f(0.16f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.17f,0.495f);
    glVertex2f(0.162f,0.495f);
    glVertex2f(0.162f,0.48f);
    glVertex2f(0.17f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.18f,0.495f);
    glVertex2f(0.172f,0.495f);
    glVertex2f(0.172f,0.48f);
    glVertex2f(0.18f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.19f,0.495f);
    glVertex2f(0.182f,0.495f);
    glVertex2f(0.182f,0.48f);
    glVertex2f(0.19f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.1985f,0.495f);
    glVertex2f(0.192f,0.495f);
    glVertex2f(0.192f,0.48f);
    glVertex2f(0.1985f,0.48f);


    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f);
    glVertex2f(0.305f,0.51f);
    glVertex2f(0.202f,0.51f);
    glVertex2f(0.202f,0.46f);
    glVertex2f(0.305f,0.46f);

    glColor3f(0.0f,0.3f,0.6f);
    glVertex2f(0.3f,0.505f);
    glVertex2f(0.202f,0.505f);
    glVertex2f(0.202f,0.5f);
    glVertex2f(0.3f,0.5f);


    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.21f,0.465f);
    glVertex2f(0.205f,0.465f);
    glVertex2f(0.205f,0.5f);
    glVertex2f(0.21f,0.5f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.3f,0.476f);
    glVertex2f(0.205f,0.476f);
    glVertex2f(0.205f,0.465f);
    glVertex2f(0.3f,0.465f);

    glColor3f(0.0f,0.3f,0.6f);
    glVertex2f(0.21f,0.471f);
    glVertex2f(0.3f,0.471f);
    glVertex2f(0.3f,0.465f);
    glVertex2f(0.207f,0.465f);

    //..
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.22f,0.495f);
    glVertex2f(0.212f,0.495f);
    glVertex2f(0.212f,0.48f);
    glVertex2f(0.22f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.23f,0.495f);
    glVertex2f(0.222f,0.495f);
    glVertex2f(0.222f,0.48f);
    glVertex2f(0.23f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.24f,0.495f);
    glVertex2f(0.232f,0.495f);
    glVertex2f(0.232f,0.48f);
    glVertex2f(0.24f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.25f,0.495f);
    glVertex2f(0.242f,0.495f);
    glVertex2f(0.242f,0.48f);
    glVertex2f(0.25f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.26f,0.495f);
    glVertex2f(0.252f,0.495f);
    glVertex2f(0.252f,0.48f);
    glVertex2f(0.26f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.27f,0.495f);
    glVertex2f(0.262f,0.495f);
    glVertex2f(0.262f,0.48f);
    glVertex2f(0.27f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.28f,0.495f);
    glVertex2f(0.272f,0.495f);
    glVertex2f(0.272f,0.48f);
    glVertex2f(0.28f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.29f,0.495f);
    glVertex2f(0.282f,0.495f);
    glVertex2f(0.282f,0.48f);
    glVertex2f(0.29f,0.48f);

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.3f,0.495f);
    glVertex2f(0.292f,0.495f);
    glVertex2f(0.292f,0.48f);
    glVertex2f(0.3f,0.48f);

    glEnd();

    glPopMatrix();

    //rail end /////////////////////.......................


    //forest<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//////////////tree 01 copy.01..................

    glPushMatrix();
    glTranslatef(1.f, .2f, 0.0f);
    glScalef(.5,.5,0);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xf1=-0.645f;
    GLfloat yf1=0.3f;
    GLfloat radiusf1 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf1, yf1);
    GLfloat twice1Pi = 1.0f * PI;
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf1 + (radiusf1 * cos(i *  twice1Pi / triangleAmount)),
                    yf1 + (radiusf1 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xf2=-0.645f;
    GLfloat yf2=0.33f;
    GLfloat radiusf2 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf2, yf2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf2 + (radiusf2 * cos(i *  twice1Pi / triangleAmount)),
                    yf2 + (radiusf2 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xf3=-0.645f;
    GLfloat yf3=0.36f;
    GLfloat radiusf3 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf3, yf3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf3 + (radiusf3 * cos(i *  twice1Pi / triangleAmount)),
                    yf3 + (radiusf3 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();

    glPopMatrix();


    //////////////tree 01 copy.02..................

    glPushMatrix();
    glTranslatef(1.01f, .15f, 0.0f);
    glScalef(.5,.5,0);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xf4=-0.645f;
    GLfloat yf4=0.3f;
    GLfloat radiusf4 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf4, yf4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf4 + (radiusf4 * cos(i *  twice1Pi / triangleAmount)),
                    yf4 + (radiusf4 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xf5=-0.645f;
    GLfloat yf5=0.33f;
    GLfloat radiusf5 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf5, yf5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf5 + (radiusf5 * cos(i *  twice1Pi / triangleAmount)),
                    yf5 + (radiusf5 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xf6=-0.645f;
    GLfloat yf6=0.36f;
    GLfloat radiusf6 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf6, yf6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf6 + (radiusf6 * cos(i *  twice1Pi / triangleAmount)),
                    yf6 + (radiusf6 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();

    glPopMatrix();



    //////////////tree 01 copy.03..................

    glPushMatrix();
    glTranslatef(.95f, .35f, 0.0f);
    glScalef(.3,.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xf7=-0.645f;
    GLfloat yf7=0.3f;
    GLfloat radiusf7 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf7, yf7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf7 + (radiusf7 * cos(i *  twice1Pi / triangleAmount)),
                    yf7 + (radiusf7 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xf8=-0.645f;
    GLfloat yf8=0.33f;
    GLfloat radiusf8 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf8, yf8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf8 + (radiusf8 * cos(i *  twice1Pi / triangleAmount)),
                    yf8 + (radiusf8 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xf9=-0.645f;
    GLfloat yf9=0.36f;
    GLfloat radiusf9 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf9, yf9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf9 + (radiusf9 * cos(i *  twice1Pi / triangleAmount)),
                    yf9 + (radiusf9 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();

    glPopMatrix();



    //////////////tree 01 copy.04..................

    glPushMatrix();
    glTranslatef(1.12f, .35f, 0.0f);
    glScalef(.3,.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xf10=-0.645f;
    GLfloat yf10=0.3f;
    GLfloat radiusf10 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf10, yf10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf10 + (radiusf10* cos(i *  twice1Pi / triangleAmount)),
                    yf10 + (radiusf10 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xf11=-0.645f;
    GLfloat yf11=0.33f;
    GLfloat radiusf11 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf11, yf11);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf11 + (radiusf11 * cos(i *  twice1Pi / triangleAmount)),
                    yf11 + (radiusf11 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xf12=-0.645f;
    GLfloat yf12=0.36f;
    GLfloat radiusf12 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf12, yf12);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf12 + (radiusf12 * cos(i *  twice1Pi / triangleAmount)),
                    yf12 + (radiusf12 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();

    glPopMatrix();



    //////////////tree 01 copy.05..................

    glPushMatrix();
    glTranslatef(1.16f, .35f, 0.0f);
    glScalef(.3,.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xf13=-0.645f;
    GLfloat yf13=0.3f;
    GLfloat radiusf13 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf13, yf13);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf13 + (radiusf13* cos(i *  twice1Pi / triangleAmount)),
                    yf13 + (radiusf13 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xf14=-0.645f;
    GLfloat yf14=0.33f;
    GLfloat radiusf14 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf14, yf14);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf14 + (radiusf14 * cos(i *  twice1Pi / triangleAmount)),
                    yf14 + (radiusf14 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xf15=-0.645f;
    GLfloat yf15=0.36f;
    GLfloat radiusf15 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xf15, yf15);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xf15 + (radiusf15 * cos(i *  twice1Pi / triangleAmount)),
                    yf15 + (radiusf15 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();

    glPopMatrix();






    // house01......................................................................................................



    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);

    glVertex2f(-0.86f, 0.48f);
    glVertex2f(-0.88f, 0.48f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.86f, 0.3f);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.855f, 0.48f);
    glVertex2f(-0.885f, 0.48f);
    glVertex2f(-0.885f, 0.495f);
    glVertex2f(-0.855f, 0.495f);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.9f, 0.2f);
    glVertex2f(-0.9f, 0.4f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.7f, 0.2f);


    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.69f, 0.39f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, 0.52f);
    glVertex2f(-0.68f, 0.4f);

    glVertex2f(-0.91f, 0.39f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, 0.52f);
    glVertex2f(-0.92f, 0.4f);
    glEnd();

//windos...................................................................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.808f, 0.43f);
    glVertex2f(-0.792f, 0.43f);
    glVertex2f(-0.792f, 0.46f);
    glVertex2f(-0.808f, 0.46f);

    glColor3f(0.6f,0.8f,1.0f);

    glVertex2f(-0.805f, 0.435f);
    glVertex2f(-0.795f, 0.435f);
    glVertex2f(-0.795f, 0.455f);
    glVertex2f(-0.805f, 0.455f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.82f, 0.32f);
    glVertex2f(-0.82f, 0.38f);
    glVertex2f(-0.78f, 0.38f);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.775f, 0.39f);
    glVertex2f(-0.825f, 0.39f);
    glVertex2f(-0.825f, 0.38f);
    glVertex2f(-0.775f, 0.38f);


    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }

    glVertex2f(-0.785f, 0.325f);
    glVertex2f(-0.795f, 0.325f);
    glVertex2f(-0.795f, 0.345f);
    glVertex2f(-0.785f, 0.345f);

    glVertex2f(-0.785f, 0.35f);
    glVertex2f(-0.795f, 0.35f);
    glVertex2f(-0.795f, 0.37f);
    glVertex2f(-0.785f, 0.37f);

    glVertex2f(-0.815f, 0.325f);
    glVertex2f(-0.805f, 0.325f);
    glVertex2f(-0.805f, 0.345f);
    glVertex2f(-0.815f, 0.345f);

    glVertex2f(-0.815f, 0.35f);
    glVertex2f(-0.805f, 0.35f);
    glVertex2f(-0.805f, 0.37f);
    glVertex2f(-0.815f, 0.37f);


    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.80f, 0.32f);
    glVertex2f(-0.80f, 0.38f);
    glEnd();


    //copy windos.............................................................

    glPushMatrix();
    glTranslatef(-0.06f, 0.0f, 0.0f);

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.82f, 0.32f);
    glVertex2f(-0.82f, 0.38f);
    glVertex2f(-0.78f, 0.38f);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.775f, 0.39f);
    glVertex2f(-0.825f, 0.39f);
    glVertex2f(-0.825f, 0.38f);
    glVertex2f(-0.775f, 0.38f);


    glColor3f(0.6f,0.8f,1.0f);

    glVertex2f(-0.785f, 0.325f);
    glVertex2f(-0.795f, 0.325f);
    glVertex2f(-0.795f, 0.345f);
    glVertex2f(-0.785f, 0.345f);

    glVertex2f(-0.785f, 0.35f);
    glVertex2f(-0.795f, 0.35f);
    glVertex2f(-0.795f, 0.37f);
    glVertex2f(-0.785f, 0.37f);

    glVertex2f(-0.815f, 0.325f);
    glVertex2f(-0.805f, 0.325f);
    glVertex2f(-0.805f, 0.345f);
    glVertex2f(-0.815f, 0.345f);

    glVertex2f(-0.815f, 0.35f);
    glVertex2f(-0.805f, 0.35f);
    glVertex2f(-0.805f, 0.37f);
    glVertex2f(-0.815f, 0.37f);


    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.80f, 0.32f);
    glVertex2f(-0.80f, 0.38f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.06f, 0.0f, 0.0f);

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.82f, 0.32f);
    glVertex2f(-0.82f, 0.38f);
    glVertex2f(-0.78f, 0.38f);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.775f, 0.39f);
    glVertex2f(-0.825f, 0.39f);
    glVertex2f(-0.825f, 0.38f);
    glVertex2f(-0.775f, 0.38f);


    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }

    glVertex2f(-0.785f, 0.325f);
    glVertex2f(-0.795f, 0.325f);
    glVertex2f(-0.795f, 0.345f);
    glVertex2f(-0.785f, 0.345f);

    glVertex2f(-0.785f, 0.35f);
    glVertex2f(-0.795f, 0.35f);
    glVertex2f(-0.795f, 0.37f);
    glVertex2f(-0.785f, 0.37f);

    glVertex2f(-0.815f, 0.325f);
    glVertex2f(-0.805f, 0.325f);
    glVertex2f(-0.805f, 0.345f);
    glVertex2f(-0.815f, 0.345f);

    glVertex2f(-0.815f, 0.35f);
    glVertex2f(-0.805f, 0.35f);
    glVertex2f(-0.805f, 0.37f);
    glVertex2f(-0.815f, 0.37f);


    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.80f, 0.32f);
    glVertex2f(-0.80f, 0.38f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.1f, 0.0f);

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.82f, 0.32f);
    glVertex2f(-0.82f, 0.38f);
    glVertex2f(-0.78f, 0.38f);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.775f, 0.39f);
    glVertex2f(-0.825f, 0.39f);
    glVertex2f(-0.825f, 0.38f);
    glVertex2f(-0.775f, 0.38f);


    glColor3f(0.6f,0.8f,1.0f);

    glVertex2f(-0.785f, 0.325f);
    glVertex2f(-0.795f, 0.325f);
    glVertex2f(-0.795f, 0.345f);
    glVertex2f(-0.785f, 0.345f);

    glVertex2f(-0.785f, 0.35f);
    glVertex2f(-0.795f, 0.35f);
    glVertex2f(-0.795f, 0.37f);
    glVertex2f(-0.785f, 0.37f);

    glVertex2f(-0.815f, 0.325f);
    glVertex2f(-0.805f, 0.325f);
    glVertex2f(-0.805f, 0.345f);
    glVertex2f(-0.815f, 0.345f);

    glVertex2f(-0.815f, 0.35f);
    glVertex2f(-0.805f, 0.35f);
    glVertex2f(-0.805f, 0.37f);
    glVertex2f(-0.815f, 0.37f);


    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.80f, 0.32f);
    glVertex2f(-0.80f, 0.38f);
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.06f, -0.1f, 0.0f);

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.78f, 0.32f);
    glVertex2f(-0.82f, 0.32f);
    glVertex2f(-0.82f, 0.38f);
    glVertex2f(-0.78f, 0.38f);

    glColor3f(0.2f,0.0f,0.0f);

    glVertex2f(-0.775f, 0.39f);
    glVertex2f(-0.825f, 0.39f);
    glVertex2f(-0.825f, 0.38f);
    glVertex2f(-0.775f, 0.38f);


    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }

    glVertex2f(-0.785f, 0.325f);
    glVertex2f(-0.795f, 0.325f);
    glVertex2f(-0.795f, 0.345f);
    glVertex2f(-0.785f, 0.345f);

    glVertex2f(-0.785f, 0.35f);
    glVertex2f(-0.795f, 0.35f);
    glVertex2f(-0.795f, 0.37f);
    glVertex2f(-0.785f, 0.37f);

    glVertex2f(-0.815f, 0.325f);
    glVertex2f(-0.805f, 0.325f);
    glVertex2f(-0.805f, 0.345f);
    glVertex2f(-0.815f, 0.345f);

    glVertex2f(-0.815f, 0.35f);
    glVertex2f(-0.805f, 0.35f);
    glVertex2f(-0.805f, 0.37f);
    glVertex2f(-0.815f, 0.37f);


    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.80f, 0.32f);
    glVertex2f(-0.80f, 0.38f);
    glEnd();

    glPopMatrix();


//door

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glVertex2f(-0.72f, 0.28f);
    glVertex2f(-0.76f, 0.28f);


    glColor3f(0.6f,0.8f,1.0f);

    glVertex2f(-0.755f, 0.21f);
    glVertex2f(-0.742f, 0.21f);
    glVertex2f(-0.742f, 0.27f);
    glVertex2f(-0.755f, 0.27f);

    glVertex2f(-0.738f, 0.21f);
    glVertex2f(-0.725f, 0.21f);
    glVertex2f(-0.725f, 0.27f);
    glVertex2f(-0.738f, 0.27f);


    glEnd();

    glBegin(GL_QUADS);


    glColor3f(0.8f,0.8f,0.8f);

    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glVertex2f(-0.72f, 0.19f);
    glVertex2f(-0.76f, 0.19f);

    glVertex2f(-0.755f, 0.17f);
    glVertex2f(-0.725f, 0.17f);
    glVertex2f(-0.725f, 0.19f);
    glVertex2f(-0.755f, 0.19f);
    glEnd();


    // tree2 copy.........................................//


    glPushMatrix();
    glTranslatef(0.06f, -0.01f, 0.0f);
    float _run3 = 0.0;
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.96f, 0.2f);
    glVertex2f(-0.96f, 0.3f);
    glVertex2f(-0.95f, 0.3f);
    glVertex2f(-0.95f, 0.2f);
    glEnd();

    GLfloat xt10=-0.955f;
    GLfloat yt10=0.3f;
    GLfloat radiust10 =0.03f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt10, yt10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt10 + (radiust10* cos(i *  twicePi / triangleAmount)),
                    yt10 + (radiust10 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt11=-0.955f;
    GLfloat yt11=0.33f;
    GLfloat radiust11 =0.025f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt11, yt11);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt11 + (radiust11 * cos(i *  twicePi / triangleAmount)),
                    yt11 + (radiust11 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt12=-0.955f;
    GLfloat yt12=0.35f;
    GLfloat radiust12 =0.02f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt12, yt12);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt12 + (radiust12 * cos(i *  twicePi / triangleAmount)),
                    yt12 + (radiust12 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();



    glBegin(GL_QUADS);


    glColor3f(0.6f,0.28f,0.0f);

    glVertex2f(-0.93f, 0.23f);
    glVertex2f(-0.77f, 0.23f);
    glVertex2f(-0.77f, 0.19f);
    glVertex2f(-0.93f, 0.19f);

    glVertex2f(-0.71f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glVertex2f(-0.67f, 0.19f);
    glVertex2f(-0.71f, 0.19f);


    glColor3f(0.8f,0.4f,0.0f);

    glVertex2f(-0.76f, 0.24f);
    glVertex2f(-0.77f, 0.24f);
    glVertex2f(-0.77f, 0.19f);
    glVertex2f(-0.76f, 0.19f);

    glVertex2f(-0.71f, 0.24f);
    glVertex2f(-0.72f, 0.24f);
    glVertex2f(-0.72f, 0.19f);
    glVertex2f(-0.71f, 0.19f);


    glEnd();



//house 2.............................................................................................................

    glBegin(GL_QUADS);
    glColor3f(0.05, 0.30, 0.50);
    glVertex2f(-0.47f, 0.6f);
    glVertex2f(-0.47f, 0.2f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.6f, 0.6f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.00, 0.18, 0.34);
    glVertex2f(-0.47f, 0.47f);
    glVertex2f(-0.4f, 0.35f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.47f, 0.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.04, 0.31, 0.52);
    glVertex2f(-.472,.47);
    glVertex2f(-.39,.34);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.05, 0.20, 0.34);
    glVertex2f(-.61,.60);
    glVertex2f(-.46,.60);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.53f, 0.56f);
    glVertex2f(-0.53f, 0.5f);
    glVertex2f(-0.57f, 0.5f);
    glVertex2f(-0.57f, 0.56f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.00, 0.20, 0.35);
    glVertex2f(-.521,.57);
    glVertex2f(-.579,.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.5f, 0.56f);
    glVertex2f(-0.5f, 0.52f);
    glVertex2f(-0.485f, 0.52f);
    glVertex2f(-0.485f, 0.56f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.497f, 0.557f);
    glVertex2f(-0.497f, 0.523f);
    glVertex2f(-0.487f, 0.523);
    glVertex2f(-0.487f, 0.557f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    glVertex2f(-0.532f, 0.557f);
    glVertex2f(-0.532f, 0.503f);
    glVertex2f(-0.549f, 0.503);
    glVertex2f(-0.549f, 0.557f);

    glVertex2f(-0.552f, 0.557f);
    glVertex2f(-0.552f, 0.503f);
    glVertex2f(-0.568f, 0.503);
    glVertex2f(-0.568f, 0.557f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-0.52f, 0.51f);
    glVertex2f(-0.52f, 0.475f);
    glVertex2f(-0.58f, 0.475);
    glVertex2f(-0.58f, 0.51f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.53f, 0.3f);
    glVertex2f(-0.53f, 0.24f);
    glVertex2f(-0.57f, 0.24f);
    glVertex2f(-0.57f, 0.3f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.00, 0.20, 0.35);
    glVertex2f(-.521,.31);
    glVertex2f(-.579,.31);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.5f, 0.3f);
    glVertex2f(-0.5f, 0.26f);
    glVertex2f(-0.485f, 0.26f);
    glVertex2f(-0.485f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.497f, 0.297f);
    glVertex2f(-0.497f, 0.263f);
    glVertex2f(-0.487f, 0.263);
    glVertex2f(-0.487f, 0.297f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    glVertex2f(-0.532f, 0.297f);
    glVertex2f(-0.532f, 0.243f);
    glVertex2f(-0.549f, 0.243);
    glVertex2f(-0.549f, 0.297f);

    glVertex2f(-0.552f, 0.297f);
    glVertex2f(-0.552f, 0.243f);
    glVertex2f(-0.568f, 0.243);
    glVertex2f(-0.568f, 0.297f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-0.52f, 0.25f);
    glVertex2f(-0.52f, 0.215f);
    glVertex2f(-0.58f, 0.215);
    glVertex2f(-0.58f, 0.25f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.53f, 0.43f);
    glVertex2f(-0.53f, 0.37f);
    glVertex2f(-0.57f, 0.37f);
    glVertex2f(-0.57f, 0.43f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.00, 0.20, 0.35);
    glVertex2f(-.521,.44);
    glVertex2f(-.579,.44);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.5f, 0.43f);
    glVertex2f(-0.5f, 0.39f);
    glVertex2f(-0.485f, 0.39f);
    glVertex2f(-0.485f, 0.43f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    glVertex2f(-0.497f, 0.427f);
    glVertex2f(-0.497f, 0.393f);
    glVertex2f(-0.487f, 0.393);
    glVertex2f(-0.487f, 0.427f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.532f, 0.427f);
    glVertex2f(-0.532f, 0.373f);
    glVertex2f(-0.549f, 0.373);
    glVertex2f(-0.549f, 0.427f);

    glVertex2f(-0.552f, 0.427f);
    glVertex2f(-0.552f, 0.373f);
    glVertex2f(-0.568f, 0.373);
    glVertex2f(-0.568f, 0.427f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-0.52f, 0.38f);
    glVertex2f(-0.52f, 0.345f);
    glVertex2f(-0.58f, 0.345);
    glVertex2f(-0.58f, 0.38f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.428f, 0.37f);
    glVertex2f(-0.428f, 0.32f);
    glVertex2f(-0.453f, 0.32f);
    glVertex2f(-0.453f, 0.37f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.38, 0.68, 0.78);
    glVertex2f(-0.431f, 0.365f);
    glVertex2f(-0.431f, 0.323f);
    glVertex2f(-0.450f, 0.323);
    glVertex2f(-0.450f, 0.365f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.95, 0.98, 0.98);
    glVertex2f(-0.425f, 0.3);
    glVertex2f(-0.425f, 0.2f);
    glVertex2f(-0.455f, 0.2);
    glVertex2f(-0.455f, 0.3);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-.435,.215);
    glVertex2f(-.435,.245);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-.445,.215);
    glVertex2f(-.445,.245);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-.435,.255);
    glVertex2f(-.435,.285);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.62, 0.67, 0.73);
    glVertex2f(-.445,.255);
    glVertex2f(-.445,.285);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.80);
    glVertex2f(-.421,.2);
    glVertex2f(-.458,.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.80, 0.80, 0.80);
    glVertex2f(-0.425f, 0.2f);
    glVertex2f(-0.425f, 0.15f);
    glVertex2f(-0.455f, 0.15);
    glVertex2f(-0.455f, 0.2f);
    glEnd();


    // car 01.....................................................................


    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.34f, 0.295f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.39f, 0.295f);

    glVertex2f(-0.325f, 0.17f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.405f, 0.17f);

    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.34f, 0.28f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.37f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.342f, 0.277f);
    glVertex2f(-0.335f, 0.255f);
    glVertex2f(-0.375f, 0.255f);
    glVertex2f(-0.367f, 0.277f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.0f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.328f, 0.234f);
    glVertex2f(-0.328f, 0.216f);
    glVertex2f(-0.339f, 0.216f);
    glVertex2f(-0.339f, 0.234f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.372f, 0.234f);
    glVertex2f(-0.372f, 0.216f);
    glVertex2f(-0.382f, 0.216f);
    glVertex2f(-0.382f, 0.234f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.369f, 0.22f);
    glVertex2f(-0.369f, 0.215f);
    glVertex2f(-0.341f, 0.215f);
    glVertex2f(-0.341f, 0.22f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.369f, 0.225f);
    glVertex2f(-0.369f, 0.23f);
    glVertex2f(-0.341f, 0.23f);
    glVertex2f(-0.341f, 0.225f);


    glEnd();




    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.375f, 0.195f);
    glVertex2f(-0.375f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.195f);

    glVertex2f(-0.325f, 0.195f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.335f, 0.21f);
    glVertex2f(-0.335f, 0.195f);
    glEnd();

    glPopMatrix();

//house03..............................royal////////////////////////////////////////////////////////////////////////

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.4f,0.2f);
    glVertex2f(-0.3f, 0.45f);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.0f, 0.19f);
    glVertex2f(-0.3f, 0.19f);

    glColor3f(0.4f,0.0f,0.0f);

    glVertex2f(-0.0065f, 0.45f);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.0f, 0.19f);
    glVertex2f(-0.0065f, 0.19f);

    glColor3f(0.4f,0.0f,0.0f);
    glVertex2f(-0.3f, 0.45f);
    glVertex2f(-0.295f, 0.45f);
    glVertex2f(-0.295f, 0.19f);
    glVertex2f(-0.3f, 0.19f);



    glEnd();



    glPushMatrix();
    glTranslatef(0.0f, 0.08f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.4f, 0.0f);
    glVertex2f(-0.02f, 0.37f);
    glVertex2f(0.0f, 0.33f);
    glVertex2f(-0.3f, 0.33f);
    glVertex2f(-0.28f, 0.37f);

    glColor3f(1.0f, 0.4f, 0.2f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.33f);
    glVertex2f(-0.29f, 0.33f);
    glVertex2f(-0.29f, 0.22f);


    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(-0.01f, 0.325f);
    glVertex2f(-0.01f, 0.33f);
    glVertex2f(-0.29f, 0.33f);
    glVertex2f(-0.29f, 0.325f);


    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.227f);
    glVertex2f(-0.29f, 0.227f);
    glVertex2f(-0.29f, 0.22f);



    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.4f, 0.0f);
    glVertex2f(-0.12f, 0.4f);
    glVertex2f(-0.09f, 0.35f);
    glVertex2f(-0.21f, 0.35f);
    glVertex2f(-0.18f, 0.4f);

    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.2f, 0.35f);
    glVertex2f(-0.2f, 0.2f);


    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(-0.1f, 0.345f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.2f, 0.35f);
    glVertex2f(-0.2f, 0.345f);

    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1f, 0.215f);
    glVertex2f(-0.2f, 0.215f);
    glVertex2f(-0.2f, 0.2f);


    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.17f, 0.282f);
    glVertex2f(-0.17f, 0.215f);
    glVertex2f(-0.13f, 0.215f);
    glVertex2f(-0.13f, 0.282f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.151f, 0.277f);
    glVertex2f(-0.151f, 0.215f);
    glVertex2f(-0.165f, 0.215f);
    glVertex2f(-0.165f, 0.277f);

    glVertex2f(-0.135f, 0.277f);
    glVertex2f(-0.135f, 0.215f);
    glVertex2f(-0.149f, 0.215f);
    glVertex2f(-0.149f, 0.277f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(-0.111f, 0.345f);
    glVertex2f(-0.15f, 0.42f);
    glVertex2f(-0.189f, 0.345f);

    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(-0.117f, 0.345f);
    glVertex2f(-0.15f, 0.41f);
    glVertex2f(-0.184f, 0.345f);

    glEnd();

    glColor3f(0.0,0.0,1.0);
    renderBitmapString(-0.168f, 0.35f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Royal");


// windus.......................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.022f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.044f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.066f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();




    //
    glPushMatrix();
    glTranslatef(0.0f, -0.046f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.022f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.044f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.066f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();


    //////////////////////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(0.189f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.022f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.044f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.066f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.283f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();




    //
    glPushMatrix();
    glTranslatef(0.0f, -0.046f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.022f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.044f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.285f, 0.283f);
    glVertex2f(-0.285f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.066f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.283f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
////////////////////////////////////////////////////////

////////////......................//////////////

    glPushMatrix();
    glTranslatef(0.094f, 0.01f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.283f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.022f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.283f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.044f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.283f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.066f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.283f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.283f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();


////////////....................../////////////

///////////////////....................////////////////////////.....................///////////////
    glPushMatrix();
    glTranslatef(0.094f, -0.037f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.26f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.26f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslatef(0.007f, -0.036f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.036f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.047f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.047f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    //..

    glPushMatrix();
    glTranslatef(0.066f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.286f, 0.26f);
    glVertex2f(-0.286f, 0.32f);
    glVertex2f(-0.27f, 0.32f);
    glVertex2f(-0.27f, 0.26f);

    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.007f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.012f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.024f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslatef(0.007f, -0.036f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.036f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.007f, -0.047f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.047f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.8f,1.0f);
    glVertex2f(-0.284f, 0.309f);
    glVertex2f(-0.284f, 0.317f);
    glVertex2f(-0.278f, 0.317f);
    glVertex2f(-0.278f, 0.309f);
    glEnd();
    glPopMatrix();
    //..
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.0f,0.0f);

    glVertex2f(-0.3f, 0.23f);
    glVertex2f(-0.17f, 0.23f);
    glVertex2f(-0.17f, 0.19f);
    glVertex2f(-0.3f, 0.19f);

    glVertex2f(0.0f, 0.23f);
    glVertex2f(-0.13f, 0.23f);
    glVertex2f(-0.13f, 0.19f);
    glVertex2f(0.0f, 0.19f);


    glColor3f(0.4f,0.0f,0.0f);

    glVertex2f(-0.18f, 0.24f);
    glVertex2f(-0.17f, 0.24f);
    glVertex2f(-0.17f, 0.19f);
    glVertex2f(-0.18f, 0.19f);

    glVertex2f(-0.12f, 0.24f);
    glVertex2f(-0.13f, 0.24f);
    glVertex2f(-0.13f, 0.19f);
    glVertex2f(-0.12f, 0.19f);


    glColor3f(0.8f,0.8f,0.8f);
    glVertex2f(-0.13f, 0.17f);
    glVertex2f(-0.17f, 0.17f);
    glVertex2f(-0.17f, 0.19f);
    glVertex2f(-0.13f, 0.19f);


    glEnd();

/////////////////////////.......................//////////end_royal///////////////...........................//////////////


////////////////////////////////////////////// marmad/////////////////////////////////////////////////////////////

    glPushMatrix();
    // glTranslatef(-0.03f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.89f, 0.8f);
    glVertex2f(0.04f, 0.31f);
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.36f, 0.3f);
    glVertex2f(0.36f, 0.31f);

    glColor3f(1.0f, 0.69f, 0.4f);
    glVertex2f(0.04f, 0.29f);
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.36f, 0.3f);
    glVertex2f(0.36f, 0.29f);

    glColor3f(0.69f, 0.4f, 1.0f);
    glVertex2f(0.05f, 0.29f);
    glVertex2f(0.05f, 0.19f);
    glVertex2f(0.35f, 0.19f);
    glVertex2f(0.35f, 0.29f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.055f, 0.285f);
    glVertex2f(0.055f, 0.195f);
    glVertex2f(0.105f, 0.195f);
    glVertex2f(0.105f, 0.285f);

    glColor3f(0.6f, 0.8f, 1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.06f, 0.28f);
    glVertex2f(0.06f, 0.2f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.1f, 0.28f);


    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.295f, 0.285f);
    glVertex2f(0.295f, 0.195f);
    glVertex2f(0.345f, 0.195f);
    glVertex2f(0.345f, 0.285f);

    glColor3f(0.6f, 0.8f, 1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.3f, 0.28f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.34f, 0.2f);
    glVertex2f(0.34f, 0.28f);


    glEnd();



    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.89f, 0.8f);
    glVertex2f(0.1f, 0.385f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.3f, 0.385f);

    glColor3f(1.0f, 0.69f, 0.4f);
    glVertex2f(0.1f, 0.385f);
    glVertex2f(0.1f, 0.37f);
    glVertex2f(0.3f, 0.37f);
    glVertex2f(0.3f, 0.385f);

    glColor3f(0.69f, 0.4f, 1.0f);
    glVertex2f(0.11f, 0.37f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.29f, 0.19f);
    glVertex2f(0.29f, 0.37f);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.11f, 0.278f);
    glVertex2f(0.11f, 0.29f);
    glVertex2f(0.29f, 0.29f);
    glVertex2f(0.29f, 0.278f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.11f, 0.282f);
    glVertex2f(0.11f, 0.286f);
    glVertex2f(0.29f, 0.286f);
    glVertex2f(0.29f, 0.282f);


    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.12f, 0.36f);
    glVertex2f(0.12f, 0.3f);
    glVertex2f(0.28f, 0.3f);
    glVertex2f(0.28f, 0.36f);

    glColor3f(0.6f, 0.8f, 1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.125f, 0.355f);
    glVertex2f(0.125f, 0.305f);
    glVertex2f(0.275f, 0.305f);
    glVertex2f(0.275f, 0.355f);


    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.12f, 0.278f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.112f, 0.19f);
    glVertex2f(0.112f, 0.278f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.288f, 0.278f);
    glVertex2f(0.288f, 0.19f);
    glVertex2f(0.28f, 0.19f);
    glVertex2f(0.28f, 0.278f);


    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.04f, 0.15f);
    glVertex2f(0.05f, 0.19f);
    glVertex2f(0.35f, 0.19f);
    glVertex2f(0.36f, 0.15f);


    glEnd();


// car1 copy




    glPushMatrix();
    glTranslatef(0.5f, 0.055f, 0.0f);
    glScalef(.7,.7,0);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.34f, 0.28f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.37f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.342f, 0.277f);
    glVertex2f(-0.335f, 0.255f);
    glVertex2f(-0.375f, 0.255f);
    glVertex2f(-0.367f, 0.277f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.328f, 0.234f);
    glVertex2f(-0.328f, 0.216f);
    glVertex2f(-0.339f, 0.216f);
    glVertex2f(-0.339f, 0.234f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.372f, 0.234f);
    glVertex2f(-0.372f, 0.216f);
    glVertex2f(-0.382f, 0.216f);
    glVertex2f(-0.382f, 0.234f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.369f, 0.22f);
    glVertex2f(-0.369f, 0.215f);
    glVertex2f(-0.341f, 0.215f);
    glVertex2f(-0.341f, 0.22f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.369f, 0.225f);
    glVertex2f(-0.369f, 0.23f);
    glVertex2f(-0.341f, 0.23f);
    glVertex2f(-0.341f, 0.225f);


    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.375f, 0.195f);
    glVertex2f(-0.375f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.195f);

    glVertex2f(-0.325f, 0.195f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.335f, 0.21f);
    glVertex2f(-0.335f, 0.195f);
    glEnd();

    glLoadIdentity();

    glPopMatrix();

    //again car1 copy

    glPushMatrix();
    glTranslatef(0.445f, 0.055f, 0.0f);
    glScalef(.7,.7,0);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.29f, 0.6f);
    glVertex2f(-0.34f, 0.28f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.37f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.342f, 0.277f);
    glVertex2f(-0.335f, 0.255f);
    glVertex2f(-0.375f, 0.255f);
    glVertex2f(-0.367f, 0.277f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.2f, 0.4f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.29f, 0.6f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.328f, 0.234f);
    glVertex2f(-0.328f, 0.216f);
    glVertex2f(-0.339f, 0.216f);
    glVertex2f(-0.339f, 0.234f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.372f, 0.234f);
    glVertex2f(-0.372f, 0.216f);
    glVertex2f(-0.382f, 0.216f);
    glVertex2f(-0.382f, 0.234f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.369f, 0.22f);
    glVertex2f(-0.369f, 0.215f);
    glVertex2f(-0.341f, 0.215f);
    glVertex2f(-0.341f, 0.22f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.369f, 0.225f);
    glVertex2f(-0.369f, 0.23f);
    glVertex2f(-0.341f, 0.23f);
    glVertex2f(-0.341f, 0.225f);


    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.375f, 0.195f);
    glVertex2f(-0.375f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.195f);

    glVertex2f(-0.325f, 0.195f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.335f, 0.21f);
    glVertex2f(-0.335f, 0.195f);
    glEnd();

    glLoadIdentity();

    glPopMatrix();

    //again car1 copy

    glPushMatrix();
    glTranslatef(0.395f, 0.055f, 0.0f);
    glScalef(.7,.7,0);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.34f, 0.28f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.37f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.342f, 0.277f);
    glVertex2f(-0.335f, 0.255f);
    glVertex2f(-0.375f, 0.255f);
    glVertex2f(-0.367f, 0.277f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.33f, 0.25f);
    glVertex2f(-0.38f, 0.25f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.325f, 0.24f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.24f);
    glEnd();
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.328f, 0.234f);
    glVertex2f(-0.328f, 0.216f);
    glVertex2f(-0.339f, 0.216f);
    glVertex2f(-0.339f, 0.234f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.372f, 0.234f);
    glVertex2f(-0.372f, 0.216f);
    glVertex2f(-0.382f, 0.216f);
    glVertex2f(-0.382f, 0.234f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.369f, 0.22f);
    glVertex2f(-0.369f, 0.215f);
    glVertex2f(-0.341f, 0.215f);
    glVertex2f(-0.341f, 0.22f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.369f, 0.225f);
    glVertex2f(-0.369f, 0.23f);
    glVertex2f(-0.341f, 0.23f);
    glVertex2f(-0.341f, 0.225f);


    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.375f, 0.195f);
    glVertex2f(-0.375f, 0.21f);
    glVertex2f(-0.385f, 0.21f);
    glVertex2f(-0.385f, 0.195f);

    glVertex2f(-0.325f, 0.195f);
    glVertex2f(-0.325f, 0.21f);
    glVertex2f(-0.335f, 0.21f);
    glVertex2f(-0.335f, 0.195f);
    glEnd();

    glLoadIdentity();

    glPopMatrix();

    glPopMatrix();


//hospital<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    glPushMatrix();
    glTranslatef(0.25f, 0.04f, 0.0f);
    glScalef(0.55f,0.85f,0.0f);


    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(0.7f, 0.6f);
    glVertex2f(0.7f, 0.17f);
    glVertex2f(0.48f, 0.17f);
    glVertex2f(0.48f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(0.48f, 0.6f);
    glVertex2f(0.48f, 0.52f);
    glVertex2f(0.465f, 0.52f);
    glVertex2f(0.465f, 0.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.23, 0.71, 0.78);
    glVertex2f(0.45f, 0.6f);
    glVertex2f(0.715f, 0.6f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.45, 0.79, 0.89);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.58f, 0.52f);
    glVertex2f(0.58f, 0.18f);
    glVertex2f(0.7f, 0.18f);
    glVertex2f(0.7f, 0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45, 0.79, 0.89);
    glVertex2f(0.535f, 0.52f);
    glVertex2f(0.535f, 0.18f);
    glVertex2f(0.48f, 0.18f);
    glVertex2f(0.48f, 0.52f);
    glEnd();

    glLineWidth(2.4);
    glBegin(GL_LINES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(0.62f, 0.52f);
    glVertex2f(0.62f, 0.18f);

    glVertex2f(0.66f, 0.52f);
    glVertex2f(0.66f, 0.18f);

    glVertex2f(0.58f, 0.248f);
    glVertex2f(0.7f, 0.248);

    glVertex2f(0.58f, 0.316f);
    glVertex2f(0.7f, 0.316);

    glVertex2f(0.58f, 0.384f);
    glVertex2f(0.7f, 0.384);

    glVertex2f(0.58f, 0.452f);
    glVertex2f(0.7f, 0.452);
    glEnd();

    glLineWidth(2.4);
    glBegin(GL_LINES);
    glColor3f(0.17, 0.53, 0.55);
    glVertex2f(0.535f, 0.248f);
    glVertex2f(0.48f, 0.248);

    glVertex2f(0.535f, 0.316f);
    glVertex2f(0.48f, 0.316);

    glVertex2f(0.535f, 0.384f);
    glVertex2f(0.48f, 0.384);

    glVertex2f(0.535f, 0.452f);
    glVertex2f(0.48f, 0.452);

    glVertex2f(0.535f, 0.452f);
    glVertex2f(0.48f, 0.452);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.28, 0.68, 0.81);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.67f, 0.255f);
    glVertex2f(0.67f, 0.17f);
    glVertex2f(0.61f, 0.17f);
    glVertex2f(0.61f, 0.255f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.17, 0.53, 0.55);
    glVertex2f(.64,.17);
    glVertex2f(.64,.25);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.73, 0.89, 0.87);
    glVertex2f(0.67f, 0.255f);
    glVertex2f(0.67f, 0.17);

    glVertex2f(0.61f, 0.255f);
    glVertex2f(0.61f, 0.17);
    glEnd();


    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.17, 0.53, 0.55);
    glVertex2f(0.6f, 0.255f);
    glVertex2f(0.68f, 0.255);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.93, 0.95, 0.96);
    glVertex2f(0.7f, 0.29f);
    glVertex2f(0.79f, 0.29);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.93, 0.95, 0.96);
    glVertex2f(0.775f, 0.29f);
    glVertex2f(0.775f, 0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.93, 0.95, 0.96);
    glVertex2f(0.48f, 0.4f);
    glVertex2f(0.48f, 0.17f);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.33f, 0.4f);
    glEnd();

    glLineWidth(12);
    glBegin(GL_LINES);
    glColor3f(0.25, 0.70, 0.77);
    glVertex2f(0.315f, 0.41f);
    glVertex2f(0.48f, 0.41);
    glEnd();

    glPushMatrix();
    glTranslatef(0,-.02,0);
    glPushMatrix();
    glTranslatef(.025,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.319f, 0.381f);
    glVertex2f(0.371f, 0.381f);
    glVertex2f(0.371f, 0.317f);
    glVertex2f(0.319f, 0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.43, 0.77, 0.87);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.32f, 0.38f);
    glVertex2f(0.37f, 0.38f);
    glVertex2f(0.37f, 0.32f);
    glVertex2f(0.32f, 0.32);
    glEnd();

    glLineWidth(1.2);
    glBegin(GL_LINES);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.345f, 0.38f);
    glVertex2f(0.345f, 0.32);
    glVertex2f(0.32f, 0.35f);
    glVertex2f(0.37f, 0.35);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.085,0,0);

    glPushMatrix();
    glTranslatef(.01,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.319f, 0.381f);
    glVertex2f(0.371f, 0.381f);
    glVertex2f(0.371f, 0.317f);
    glVertex2f(0.319f, 0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.43, 0.77, 0.87);
    glVertex2f(0.32f, 0.38f);
    glVertex2f(0.37f, 0.38f);
    glVertex2f(0.37f, 0.32f);
    glVertex2f(0.32f, 0.32);
    glEnd();

    glLineWidth(1.2);
    glBegin(GL_LINES);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.345f, 0.38f);
    glVertex2f(0.345f, 0.32);
    glVertex2f(0.32f, 0.35f);
    glVertex2f(0.37f, 0.35);
    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(.085,-.1,0);

    glPushMatrix();
    glTranslatef(.01,0,0);

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.319f, 0.383f);
    glVertex2f(0.371f, 0.383f);
    glVertex2f(0.371f, 0.317f);
    glVertex2f(0.319f, 0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.43, 0.77, 0.87);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.32f, 0.38f);
    glVertex2f(0.37f, 0.38f);
    glVertex2f(0.37f, 0.32f);
    glVertex2f(0.32f, 0.32);
    glEnd();

    glLineWidth(1.2);
    glBegin(GL_LINES);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.345f, 0.38f);
    glVertex2f(0.345f, 0.32);
    glVertex2f(0.32f, 0.35f);
    glVertex2f(0.37f, 0.35);
    glEnd();
    glLoadIdentity();
    glPopMatrix();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(.0,-.1,0);

    glPushMatrix();
    glTranslatef(.025,0,0);

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.319f, 0.383f);
    glVertex2f(0.371f, 0.383f);
    glVertex2f(0.371f, 0.317f);
    glVertex2f(0.319f, 0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.43, 0.77, 0.87);
    glVertex2f(0.32f, 0.38f);
    glVertex2f(0.37f, 0.38f);
    glVertex2f(0.37f, 0.32f);
    glVertex2f(0.32f, 0.32);
    glEnd();

    glLineWidth(1.2);
    glBegin(GL_LINES);
    glColor3f(0.14, 0.47, 0.54);
    glVertex2f(0.345f, 0.38f);
    glVertex2f(0.345f, 0.32);
    glVertex2f(0.32f, 0.35f);
    glVertex2f(0.37f, 0.35);
    glEnd();

    glLoadIdentity();
    glPopMatrix();

    glLoadIdentity();
    glPopMatrix();

    glPopMatrix();
    glLoadIdentity();


    glLoadIdentity();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.575f, 0.15f);
    glVertex2f(0.575f, 0.19f);
    glVertex2f(0.685f, 0.19f);
    glVertex2f(0.685f, 0.15f);
    glEnd();






//////////////////////////............................house5_start.......................//////////////////////////////


//////////////tree 01 copy...................

    glPushMatrix();
    glTranslatef(1.61f, -0.03f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xt1=-0.645f;
    GLfloat yt1=0.3f;
    GLfloat radiust1 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt1, yt1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt1 + (radiust1 * cos(i *  twice1Pi / triangleAmount)),
                    yt1 + (radiust1 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xt2=-0.645f;
    GLfloat yt2=0.33f;
    GLfloat radiust2 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt2, yt2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt2 + (radiust2 * cos(i *  twice1Pi / triangleAmount)),
                    yt2 + (radiust2 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt3=-0.645f;
    GLfloat yt3=0.36f;
    GLfloat radiust3 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt3, yt3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt3 + (radiust3 * cos(i *  twice1Pi / triangleAmount)),
                    yt3 + (radiust3 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.5f, 0.00f, 0.0f);
    glScalef(0.65f,0.95f,0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.65, 0.56, 0.51);
    glVertex2f(0.7f, 0.3f);
    glVertex2f(0.7f, 0.2f);
    glVertex2f(0.55f, 0.2f);
    glVertex2f(0.55f, 0.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.72, 0.66, 0.62);
    glVertex2f(0.55f, 0.3f);
    glVertex2f(0.55f, 0.2f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.45f, 0.3f);
    glEnd();

    ///1st roof
    glBegin(GL_QUADS);
    glColor3f(0.44, 0.38, 0.39);
    glVertex2f(0.65f, 0.37f);
    glVertex2f(0.71f, 0.305f);
    glVertex2f(0.34f, 0.305f);
    glVertex2f(0.4f, 0.37f);
    glEnd();

    ///1st floor
    glBegin(GL_QUADS);
    glColor3f(0.64, 0.57, 0.51);
    glVertex2f(0.62f, 0.45f);
    glVertex2f(0.62f, 0.37f);
    glVertex2f(0.43f, 0.37f);
    glVertex2f(0.43f, 0.45f);
    glEnd();

    ///2nd roof
    glBegin(GL_QUADS);
    glColor3f(0.44, 0.38, 0.39);
    glVertex2f(0.59f, 0.51f);
    glVertex2f(0.63f, 0.451f);
    glVertex2f(0.42f, 0.451f);
    glVertex2f(0.46f, 0.51f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(0.56f, 0.3f);
    glVertex2f(0.44f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.72, 0.66, 0.62);
    glVertex2f(0.5f, 0.385f);
    glVertex2f(0.55f, 0.3f);
    glVertex2f(0.45f, 0.3);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.65, 0.56, 0.51);
    glVertex2f(0.45f, 0.3f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.41f, 0.2f);
    glVertex2f(0.41f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.33, 0.27, 0.28);
    glVertex2f(0.45f, 0.27f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.43f, 0.2f);
    glVertex2f(0.43f, 0.27f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.85, 0.84);
    glVertex2f(.34f,.3f);
    glVertex2f(.71f,.3f);

    glVertex2f(.35f,.3f);
    glVertex2f(.35f,.2f);

    glVertex2f(.45f,.3f);
    glVertex2f(.45f,.2f);

    glVertex2f(.55f,.3f);
    glVertex2f(.55f,.2f);


    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.85, 0.84);
    glVertex2f(.42f,.45f);
    glVertex2f(.63f,.45f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(0.565f, 0.52f);
    glVertex2f(0.6f, 0.45f);
    glVertex2f(0.6f, 0.37f);
    glVertex2f(0.53f, 0.37f);
    glVertex2f(0.53f, 0.45f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.72, 0.66, 0.62);
    glVertex2f(0.565f, 0.51f);
    glVertex2f(0.595f, 0.445f);
    glVertex2f(0.595f, 0.37f);
    glVertex2f(0.535f, 0.37f);
    glVertex2f(0.535f, 0.445f);
    glEnd();

    ///window 2
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(0.58f, 0.44f);
    glVertex2f(0.58f, 0.39f);
    glVertex2f(0.548f, 0.39f);
    glVertex2f(0.548f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66, 0.71, 0.80);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(0.577f, 0.435f);
    glVertex2f(0.577f, 0.395f);
    glVertex2f(0.551f, 0.395f);
    glVertex2f(0.551f, 0.435f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.85, 0.84);
    glVertex2f(.564f,.435f);
    glVertex2f(.564f,.395f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.80, 0.80, 0.80);
    glVertex2f(0.68f, 0.28f);
    glVertex2f(0.68f, 0.2f);
    glVertex2f(0.58f, 0.2f);
    glVertex2f(0.58f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(0.53f, 0.27f);
    glVertex2f(0.53f, 0.22f);
    glVertex2f(0.47f, 0.22f);
    glVertex2f(0.47f, 0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66, 0.71, 0.80);
    glVertex2f(0.527f, 0.268f);
    glVertex2f(0.527f, 0.222f);
    glVertex2f(0.5015f, 0.222f);
    glVertex2f(0.5015f, 0.268f);

    glVertex2f(0.473f, 0.268f);
    glVertex2f(0.473f, 0.222f);
    glVertex2f(0.4985f, 0.222f);
    glVertex2f(0.4985f, 0.268f);
    glEnd();

    ///gDore line
    glLineWidth(.7);
    glBegin(GL_LINES);
    glColor3f(0.70, 0.70, 0.70);

    glVertex2f(.678f,.28f);
    glVertex2f(.58f,.28f);

    glVertex2f(.678f,.26f);
    glVertex2f(.58f,.26f);

    glVertex2f(.678f,.24f);
    glVertex2f(.58f,.24f);

    glVertex2f(.678f,.22f);
    glVertex2f(.58f,.22f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.80, 0.80, 0.80);
    glVertex2f(0.685f, 0.2f);
    glVertex2f(0.685f, 0.15f);
    glVertex2f(0.575f, 0.15f);
    glVertex2f(0.575f, 0.2f);

    glVertex2f(0.46f, 0.2f);
    glVertex2f(0.46f, 0.15f);
    glVertex2f(0.34f, 0.15f);
    glVertex2f(0.34f, 0.2f);
    glEnd();

    glLoadIdentity();
    glPopMatrix();
    ////////////////////////////////////////house5_end/////////////////////////////////////////////////////



// tree01 ............................................................................................................

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.64f, 0.2f);
    glVertex2f(-0.64f, 0.3f);
    glVertex2f(-0.65f, 0.3f);
    glVertex2f(-0.65f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPushMatrix();
    glTranslatef(-0.01f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();




    glPushMatrix();
    glTranslatef(0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.645f, 0.25f);
    glVertex2f(-0.64f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.655f, 0.26f);
    glVertex2f(-0.658f, 0.2f);


    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.645f, 0.2f);
    glVertex2f(-0.635f, 0.26f);
    glVertex2f(-0.638f, 0.2f);


    glEnd();


    glPopMatrix();





    GLfloat xt01=-0.645f;
    GLfloat yt01=0.3f;
    GLfloat radiust01 =0.039f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt01, yt01);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt01 + (radiust01 * cos(i *  twice1Pi / triangleAmount)),
                    yt01 + (radiust01 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();


    GLfloat xt02=-0.645f;
    GLfloat yt02=0.33f;
    GLfloat radiust02 =0.034f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt02, yt02);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt02 + (radiust02 * cos(i *  twice1Pi / triangleAmount)),
                    yt02 + (radiust02 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt03=-0.645f;
    GLfloat yt03=0.36f;
    GLfloat radiust03 =0.029f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt03, yt03);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt03 + (radiust03 * cos(i *  twice1Pi / triangleAmount)),
                    yt03 + (radiust03 * sin(i * twice1Pi / triangleAmount)) );
    }
    glEnd();

//tree02...............................................................................................................

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.96f, 0.2f);
    glVertex2f(-0.96f, 0.3f);
    glVertex2f(-0.95f, 0.3f);
    glVertex2f(-0.95f, 0.2f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.02f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.03f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.04f, 0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.04f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.02f, 0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();





    GLfloat xt4=-0.955f;
    GLfloat yt4=0.3f;
    GLfloat radiust4 =0.03f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt4, yt4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt4 + (radiust4 * cos(i *  twicePi / triangleAmount)),
                    yt4 + (radiust4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt5=-0.955f;
    GLfloat yt5=0.33f;
    GLfloat radiust5 =0.025f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt5, yt5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt5 + (radiust5 * cos(i *  twicePi / triangleAmount)),
                    yt5 + (radiust5 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt6=-0.955f;
    GLfloat yt6=0.35f;
    GLfloat radiust6 =0.02f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt6, yt6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt6 + (radiust6 * cos(i *  twicePi / triangleAmount)),
                    yt6 + (radiust6 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


// tree02 copy...........................................
    glPushMatrix();
    glTranslatef(-0.02f, 0.02f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(-0.96f, 0.2f);
    glVertex2f(-0.96f, 0.3f);
    glVertex2f(-0.95f, 0.3f);
    glVertex2f(-0.95f, 0.2f);
    glEnd();

    GLfloat xt7=-0.955f;
    GLfloat yt7=0.3f;
    GLfloat radiust7 =0.03f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt7, yt7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt7 + (radiust7 * cos(i *  twicePi / triangleAmount)),
                    yt7 + (radiust7 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt8=-0.955f;
    GLfloat yt8=0.33f;
    GLfloat radiust8 =0.025f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt8, yt8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt8 + (radiust8 * cos(i *  twicePi / triangleAmount)),
                    yt8 + (radiust8 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat xt9=-0.955f;
    GLfloat yt9=0.35f;
    GLfloat radiust9 =0.02f;
    glColor3f(0.0f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xt9, yt9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xt9 + (radiust9 * cos(i *  twicePi / triangleAmount)),
                    yt9 + (radiust9 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.04f, -0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.02f, -0.02f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.05f, -0.01f, 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.945f, 0.25f);
    glVertex2f(-0.938f, 0.2f);

    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.955f, 0.26f);
    glVertex2f(-0.958f, 0.2f);

    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.945f, 0.2f);
    glVertex2f(-0.935f, 0.26f);
    glVertex2f(-0.938f, 0.2f);
    glEnd();
    glPopMatrix();



    //wake way................................................................................
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.8f,0.8f);
    glVertex2f(-1.0f, -0.17f);
    glVertex2f(1.0f, -0.17f);
    glVertex2f(1.0f, -0.12f);
    glVertex2f(-1.0f, -0.12f);


    glColor3f(0.8f,0.8f,0.8f);
    glVertex2f(-1.0f, 0.17f);
    glVertex2f(1.0f, 0.17f);
    glVertex2f(1.0f, 0.12f);
    glVertex2f(-1.0f, 0.12f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.12f);
    glVertex2f(-1.0f, -0.12f);


    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(1.0f, 0.12f);
    glVertex2f(-1.0f, 0.12f);

    glEnd();

//lamp
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);


    glEnd();

    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }

    //..

    glPushMatrix();
    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(0.4f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);
        glEnd();
    }
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslatef(0.6f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(0.8f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);
        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);
        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(1.2f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslatef(1.4f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslatef(1.6f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(1.8f,0.0f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.85f, 0.12f);
        glEnd();
    }
    glPopMatrix();



// police

    GLfloat xp=0.4f;
    GLfloat yp=0.195f;
    GLfloat radiusp =0.007f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xp, yp); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xp + (radiusp * cos(i *  twicePi / triangleAmount)),
                    yp+ (radiusp * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f,0.8f,0.0f);
    glVertex2f(0.394f, 0.185f);
    glVertex2f(0.407f, 0.185f);
    glVertex2f(0.407f, 0.155f);
    glVertex2f(0.394f, 0.155f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.396f, 0.185f);
    glVertex2f(0.399f, 0.185f);
    glVertex2f(0.399f, 0.155f);
    glVertex2f(0.396f, 0.155f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.405f, 0.185f);
    glVertex2f(0.402f, 0.185f);
    glVertex2f(0.402f, 0.155f);
    glVertex2f(0.405f, 0.155f);

    glEnd();

    glBegin(GL_QUADS);
//right hand
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.411f, 0.185f);
    glVertex2f(0.407f, 0.185f);
    glVertex2f(0.407f, 0.145f);
    glVertex2f(0.411f, 0.145f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.411f, 0.155f);
    glVertex2f(0.407f, 0.155f);
    glVertex2f(0.407f, 0.145f);
    glVertex2f(0.411f, 0.145f);
//left hand
    if(!handup)
    {
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.394f, 0.185f);
        glVertex2f(0.39f, 0.185f);
        glVertex2f(0.39f, 0.145f);
        glVertex2f(0.394f, 0.145f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(0.394f, 0.155f);
        glVertex2f(0.39f, 0.155f);
        glVertex2f(0.39f, 0.145f);
        glVertex2f(0.394f, 0.145f);
    }

    //left hand up
    if(handup)
    {
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.394f, 0.175f);
        glVertex2f(0.39f, 0.175f);
        glVertex2f(0.39f, 0.215f);
        glVertex2f(0.394f, 0.215f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(0.394f, 0.205f);
        glVertex2f(0.39f, 0.205f);
        glVertex2f(0.39f, 0.215f);
        glVertex2f(0.394f, 0.215f);


    }
// left lag

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.406f, 0.12f);
    glVertex2f(0.401f, 0.12f);
    glVertex2f(0.401f, 0.155f);
    glVertex2f(0.406f, 0.155f);

// right lag

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.395f, 0.12f);
    glVertex2f(0.4f, 0.12f);
    glVertex2f(0.4f, 0.155f);
    glVertex2f(0.395f, 0.155f);

    //table
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.415f, 0.12f);
    glVertex2f(0.47f, 0.12f);
    glVertex2f(0.46f, 0.158f);
    glVertex2f(0.42f, 0.158f);

    glColor3f(0.9f,0.9f,0.0f);
    glVertex2f(0.414f, 0.12f);
    glVertex2f(0.455f, 0.12f);
    glVertex2f(0.46f, 0.158f);
    glVertex2f(0.42f, 0.158f);



    glEnd();








//road................................................................................................................
    glBegin(GL_QUADS);



    glColor3f(0.2f,0.2f,0.2f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(-1.0f, 0.1f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.2f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.2f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f,0.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.01f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.05f,-0.01f);
    glVertex2f(-0.05f,-0.01f);
    glEnd();
    glPopMatrix();



    // bus01<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>


    glPushMatrix();
    glTranslatef(_run4,0,0);
    GLfloat xb1=-0.455f;
    GLfloat yb1=0.095f;
    GLfloat radiusb1 =.01f;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb1, yb1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb1 + (radiusb1 * cos(i *  twicePi / triangleAmount)),
                    yb1 + (radiusb1 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    if(night)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(-0.445f, 0.097f);
        glVertex2f(-0.455f, 0.095f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(-0.435f, 0.06f);
        glVertex2f(-0.39f, 0.06f);

        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex2f(-.45,.188);
    glVertex2f(-.45,.06);
    glColor3f(0.98, 0.88, 0.02);
    glVertex2f(-.6,.06);
    glVertex2f(-.6,.188);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(-.45,.077);
    glVertex2f(-.45,.069);
    glVertex2f(-.46,.069);
    glVertex2f(-.46,.077);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.455f,.17f);
    glVertex2f(-.455f,.12f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.59f,.12f);
    glVertex2f(-.47f,.12f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.59f,.1f);
    glVertex2f(-.47f,.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();

    glPushMatrix();
    glTranslatef(-.022,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.044,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.066,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.088,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.11,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();



    GLfloat xb2=-0.49f;
    GLfloat yb2=0.06f;
    GLfloat radiusb2 =.02f;
    glColor3f(0.10, 0.10, 0.10);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb2, yb2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb2 + (radiusb2 * cos(i *  twicePi / triangleAmount)),
                    yb2 + (radiusb2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb3=-.49f;
    GLfloat yb3=0.06f;
    GLfloat radiusb3 =.014f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb3, yb3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb3 + (radiusb3 * cos(i *  twicePi / triangleAmount)),
                    yb3 + (radiusb3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb4=-.57f;
    GLfloat yb4=0.06f;
    glColor3f(0.10, 0.10, 0.10 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb4, yb4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb4 + (radiusb2 * cos(i *  twicePi / triangleAmount)),
                    yb4 + (radiusb2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb5=-.57f;
    GLfloat yb5=0.06f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb5, yb5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb5 + (radiusb3 * cos(i *  twicePi / triangleAmount)),
                    yb5 + (radiusb3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

    //CAR4 body<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    glPushMatrix();
    glTranslatef(_run5,0,0);
    glPushMatrix();
    glTranslatef(0.5f,0.1f,0.0f);
    glRotatef(180,0,1,0),
              glBegin(GL_QUADS);
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(0.42f, 0.0175f);
    glVertex2f(0.42f, -0.02f);
    glVertex2f(0.32f, -0.02f);
    glVertex2f(0.33f, 0.0175f);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(0.42f, -0.02f);
    glVertex2f(0.42f, -0.067f);
    glVertex2f(0.3f, -0.067f);
    glVertex2f(0.3f, -0.02f);

    glEnd();



//Light....................................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.038f,0.27f);



    glVertex2f(0.306f, -0.02f);
    glVertex2f(0.309f, -0.032f);

    glVertex2f(0.3f, -0.032f);
    glVertex2f(0.3f, -0.02f);




    glEnd();

    if(night)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(0.3f, -0.025f);
        glVertex2f(0.3f, -0.032f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(0.28f, -0.067f);
        glVertex2f(0.25f, -0.067f);

        glEnd();
    }

//back light.............................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.38f,0.27f);

    glVertex2f(0.42f, -0.04f);
    glVertex2f(0.413f, -0.04);
    glVertex2f(0.413f, -0.054f);
    glVertex2f(0.42f, -0.054f);


    glEnd();
//  //BACK SIDE WHELL.......................................................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.42f, -0.018f);
    glVertex2f(0.425f, -0.018f);
    glVertex2f(0.425f, -0.05f);
    glVertex2f(0.42f, -0.053f);



    glEnd();


    //window1..............................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);


    glVertex2f(0.352f, 0.012f);
    glVertex2f(0.352f, -0.02f);
    glVertex2f(0.325f, -0.02f);
    glVertex2f(0.334f, 0.012f);
    glEnd();

    //window2..................
    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.354f, 0.012f);
    glVertex2f(0.354f, -0.02f);
    glVertex2f(0.374f, -0.02f);
    glVertex2f(0.374f, 0.012f);



    glEnd();


    //window3.................................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.41f, 0.012f);
    glVertex2f(0.41f, -0.02f);
    glVertex2f(0.376f, -0.02f);
    glVertex2f(0.376f, 0.012f);



    glEnd();
//
    //Door1..........................................


    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.352f, -0.023f);
    glVertex2f(0.352f, -0.027f);
    glVertex2f(0.344f, -0.027f);
    glVertex2f(0.344f, -0.023f);



    glEnd();

    //Door2..........................................................



    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.373f, -0.023f);
    glVertex2f(0.373f, -0.027f);
    glVertex2f(0.367f, -0.027f);
    glVertex2f(0.367f, -0.023f);



    glEnd();

    //wheel1...................................



    GLfloat xc=0.33f;
    GLfloat yc=-0.067f;
    GLfloat radiusc =0.015f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc + (radiusc * cos(i *  twicePi / triangleAmount)),
                    yc+ (radiusc * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc1=0.33f;
    GLfloat yc1=-0.067f;
    GLfloat radiusc3 =0.008f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc1, yc1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc1 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc1 + (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


//wheel2.................................


    GLfloat xc2=0.39f;
    GLfloat yc2=-0.067f;
    GLfloat radiusc4=0.015f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc2, yc2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc2 + (radiusc4 * cos(i *  twicePi / triangleAmount)),
                    yc2 + (radiusc4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xc3=0.39f;
    GLfloat yc3=-0.067f;
    GLfloat radiusc5=0.008f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc3, yc3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc3 + (radiusc5 * cos(i *  twicePi / triangleAmount)),
                    yc3 + (radiusc5 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glLoadIdentity();

    glPopMatrix();


    glPopMatrix();


    //CAR3 body<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    glPushMatrix();
    glTranslatef(_run6,0,0);
    glPushMatrix();
    glTranslatef(-0.45f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.4f, 0.0175f);
    glVertex2f(0.42f, -0.02f);
    glVertex2f(0.32f, -0.02f);
    glVertex2f(0.33f, 0.0175f);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.42f, -0.02f);
    glVertex2f(0.42f, -0.067f);
    glVertex2f(0.3f, -0.067f);
    glVertex2f(0.3f, -0.02f);

    glEnd();



//Light....................................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.038f,0.27f);



    glVertex2f(0.306f, -0.02f);
    glVertex2f(0.309f, -0.032f);

    glVertex2f(0.3f, -0.032f);
    glVertex2f(0.3f, -0.02f);


    glEnd();
    if(night)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(0.3f, -0.025f);
        glVertex2f(0.3f, -0.032f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(0.28f, -0.067f);
        glVertex2f(0.25f, -0.067f);

        glEnd();
    }
//back light.............................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.38f,0.27f);

    glVertex2f(0.42f, -0.04f);
    glVertex2f(0.413f, -0.04);
    glVertex2f(0.413f, -0.054f);
    glVertex2f(0.42f, -0.054f);


    glEnd();
//  //BACK SIDE WHELL.......................................................
//
//   glBegin(GL_QUADS);
//    glColor3f(0.8f,1.0f,1.0f);
//
//    glVertex2f(0.42f, -0.018f);
//    glVertex2f(0.425f, -0.018f);
//    glVertex2f(0.425f, -0.05f);
//    glVertex2f(0.42f, -0.053f);
//
//
//
//    glEnd();


    //window1..............................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);


    glVertex2f(0.352f, 0.012f);
    glVertex2f(0.352f, -0.02f);
    glVertex2f(0.325f, -0.02f);
    glVertex2f(0.334f, 0.012f);
    glEnd();

    //window2..................
    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.354f, 0.012f);
    glVertex2f(0.354f, -0.02f);
    glVertex2f(0.374f, -0.02f);
    glVertex2f(0.374f, 0.012f);



    glEnd();


    //window3.................................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.394f, 0.012f);
    glVertex2f(0.41f, -0.02f);
    glVertex2f(0.376f, -0.02f);
    glVertex2f(0.376f, 0.012f);



    glEnd();
//
    //Door1..........................................


    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.352f, -0.023f);
    glVertex2f(0.352f, -0.027f);
    glVertex2f(0.344f, -0.027f);
    glVertex2f(0.344f, -0.023f);



    glEnd();

    //Door2..........................................................



    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.373f, -0.023f);
    glVertex2f(0.373f, -0.027f);
    glVertex2f(0.367f, -0.027f);
    glVertex2f(0.367f, -0.023f);



    glEnd();

    //wheel1...................................



    GLfloat xc5=0.33f;
    GLfloat yc5=-0.067f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc5 + (radiusc * cos(i *  twicePi / triangleAmount)),
                    yc5+ (radiusc * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc6=0.33f;
    GLfloat yc6=-0.067f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc6, yc6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc6 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc6 + (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


//wheel2.................................


    GLfloat xc7=0.39f;
    GLfloat yc7=-0.067f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc7, yc7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc7 + (radiusc4 * cos(i *  twicePi / triangleAmount)),
                    yc7 + (radiusc4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xc8=0.39f;
    GLfloat yc8=-0.067f;
    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc8, yc8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc8 + (radiusc5 * cos(i *  twicePi / triangleAmount)),
                    yc8 + (radiusc5 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
    glPopMatrix();



//	// bus 02<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>

    glPushMatrix();

    glTranslatef(_run7,0,0);

    glPushMatrix();
    glTranslatef(0.09f,-0.125f, 0.0f);
    glRotatef(180,0,1,0);



    GLfloat xb6=-0.455f;
    GLfloat yb6=0.095f;
    GLfloat radiusb6 =.01f;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb6, yb6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb6 + (radiusb6 * cos(i *  twicePi / triangleAmount)),
                    yb6 + (radiusb6 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    if(night)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(-0.445f, 0.097f);
        glVertex2f(-0.455f, 0.095f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(-0.435f, 0.06f);
        glVertex2f(-0.39f, 0.06f);

        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.4, 0.0);
    glVertex2f(-.45,.188);
    glVertex2f(-.45,.06);
    glColor3f(1.0, 0.2, 0.2);
    glVertex2f(-.6,.06);
    glVertex2f(-.6,.188);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(-.45,.077);
    glVertex2f(-.45,.069);
    glVertex2f(-.46,.069);
    glVertex2f(-.46,.077);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.455f,.17f);
    glVertex2f(-.455f,.12f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.59f,.12f);
    glVertex2f(-.47f,.12f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.59f,.1f);
    glVertex2f(-.47f,.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();

    glPushMatrix();
    glTranslatef(-.022,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.044,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.066,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.088,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.11,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.77, 0.78);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();



    GLfloat xb7=-0.49f;
    GLfloat yb7=0.06f;
    GLfloat radiusb7 =.02f;
    glColor3f(0.10, 0.10, 0.10);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb7, yb7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb7 + (radiusb7 * cos(i *  twicePi / triangleAmount)),
                    yb7 + (radiusb7 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb8=-.49f;
    GLfloat yb8=0.06f;
    GLfloat radiusb8 =.014f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb8, yb8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb8 + (radiusb8 * cos(i *  twicePi / triangleAmount)),
                    yb8 + (radiusb8 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb9=-.57f;
    GLfloat yb9=0.06f;
    GLfloat radiusb9 =.02f;
    glColor3f(0.10, 0.10, 0.10 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb9, yb9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb9 + (radiusb9 * cos(i *  twicePi / triangleAmount)),
                    yb9 + (radiusb9 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb10=-.57f;
    GLfloat yb10=0.06f;
    GLfloat radiusb10 =.014f;
    glColor3f(0.47, 0.46, 0.46);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb10, yb10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb10 + (radiusb10 * cos(i *  twicePi / triangleAmount)),
                    yb10 + (radiusb10* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glLoadIdentity();
    glPopMatrix();
    glPopMatrix();

// lamp part02<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//..

    glPushMatrix();
    glTranslatef(-0.1f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(0.1f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslatef(0.3f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslatef(0.5f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslatef(0.7f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(0.9f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


//..

    glPushMatrix();
    glTranslatef(1.1f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(1.3f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(1.5f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


    //..

    glPushMatrix();
    glTranslatef(1.7f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();



    //..

    glPushMatrix();
    glTranslatef(1.9f,-0.22f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    //bech.......................................................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.71f,0.43f);
    if(night)
    {
        glColor3f(0.8, 0.51, 0.23);
    }

    glVertex2f(-1.0f, -0.45f);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(1.0f, -0.17f);
    glVertex2f(-1.0f, -0.17f);
    glEnd();


    //Beach bench <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


    ///bench 1

    glPushMatrix();
    glTranslated(0.0f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();



    //..
    glPushMatrix();
    glTranslated(-0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslated(0.06f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

//..
    glPushMatrix();
    glTranslated(0.09f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.12f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();


    ////.////

    glPushMatrix();
    glTranslated(0.3f,0.0f,0.0f);

    glPushMatrix();
    glTranslated(0.0f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();



    //..
    glPushMatrix();
    glTranslated(-0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslated(0.06f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

//..
    glPushMatrix();
    glTranslated(0.09f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.12f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();
    glPopMatrix();



    ////.////

    glPushMatrix();
    glTranslated(-0.3f,0.0f,0.0f);

    glPushMatrix();
    glTranslated(0.0f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();



    //..
    glPushMatrix();
    glTranslated(-0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslated(0.06f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

//..
    glPushMatrix();
    glTranslated(0.09f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.12f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();
    glPopMatrix();


    ////.////

    glPushMatrix();
    glTranslated(-0.45f,0.0f,0.0f);

    glPushMatrix();
    glTranslated(0.0f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();



    //..
    glPushMatrix();
    glTranslated(-0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslated(0.06f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

//..
    glPushMatrix();
    glTranslated(0.09f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.12f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();
    glPopMatrix();


    ////.////

    glPushMatrix();
    glTranslated(0.45f,0.0f,0.0f);

    glPushMatrix();
    glTranslated(0.0f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();



    //..
    glPushMatrix();
    glTranslated(-0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslated(0.06f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

//..
    glPushMatrix();
    glTranslated(0.09f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.12f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();
    glPopMatrix();


////.////

    glPushMatrix();
    glTranslated(-0.85f,0.0f,0.0f);

    glPushMatrix();
    glTranslated(0.0f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();



    //..
    glPushMatrix();
    glTranslated(-0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.03f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..
    glPushMatrix();
    glTranslated(0.06f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

//..
    glPushMatrix();
    glTranslated(0.09f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();

    //..

    glPushMatrix();
    glTranslated(0.12f,0.01f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.33, 0.19, 0.19);

    glVertex2f(.112,-.238);
    glVertex2f(.105,-.245);

    glVertex2f(.112,-.28);
    glVertex2f(.105,-.29);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.80, 0.35, 0.01);
    glVertex2f(.13,-.23);
    glVertex2f(.13,-.3);
    glVertex2f(.11,-.3);
    glVertex2f(.11,-.23);
    glVertex2f(.115,-.22);
    glVertex2f(.135,-.22);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.83, 0.80);
    glVertex2f(.11,-.29);
    glVertex2f(.131,-.29);

    glVertex2f(.11,-.28);
    glVertex2f(.131,-.28);

    glVertex2f(.11,-.27);
    glVertex2f(.131,-.27);

    glVertex2f(.11,-.26);
    glVertex2f(.131,-.26);

    glVertex2f(.11,-.25);
    glVertex2f(.131,-.25);

    glVertex2f(.11,-.24);
    glVertex2f(.131,-.24);

    glVertex2f(.11,-.23);
    glVertex2f(.131,-.23);

    glEnd();
    glPopMatrix();
    glPopMatrix();



    // bus 02<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>
//
//    glPushMatrix();
////    if(crash){
////        glTranslatef(_run7,_crashB2,0);
////    }
////    else{
////       glTranslatef(_run7,0,0);
////    }
//
//    glTranslatef(_run7,_crashB2,0);
//
//    glPushMatrix();
//    glTranslatef(0.09f,-0.125f, 0.0f);
//    glRotatef(180,0,1,0);
//
//
//
//   GLfloat xb6=-0.455f; GLfloat yb6=0.095f; GLfloat radiusb6 =.01f;
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_TRIANGLE_FAN);
//		glVertex2f(xb6, yb6);
//		for(int i = 0; i <= triangleAmount;i++) {
//			glVertex2f( xb6 + (radiusb6 * cos(i *  twicePi / triangleAmount)),
//                        yb6 + (radiusb6 * sin(i * twicePi / triangleAmount)));
//		}
//	glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(0.0, 0.4, 0.0);
//    glVertex2f(-.45,.188);
//    glVertex2f(-.45,.06);
//    glColor3f(1.0, 0.2, 0.2);
//    glVertex2f(-.6,.06);
//    glVertex2f(-.6,.188);
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(0.00, 0.00, 0.00);
//    glVertex2f(-.45,.077);
//    glVertex2f(-.45,.069);
//    glVertex2f(-.46,.069);
//    glVertex2f(-.46,.077);
//    glEnd();
//
//    glLineWidth(6);
//    glBegin(GL_LINES);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.455f,.17f);
//    glVertex2f(-.455f,.12f);
//    glEnd();
//
//    glLineWidth(2);
//    glBegin(GL_LINES);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.59f,.12f);
//    glVertex2f(-.47f,.12f);
//    glEnd();
//
//    glLineWidth(2);
//    glBegin(GL_LINES);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.59f,.1f);
//    glVertex2f(-.47f,.1f);
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.465,.17);
//    glVertex2f(-.465,.14);
//    glVertex2f(-.48,.14);
//    glVertex2f(-.48,.17);
//    glEnd();
//
//    glPushMatrix();
//    glTranslatef(-.022,0,0);
//    glBegin(GL_QUADS);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.465,.17);
//    glVertex2f(-.465,.14);
//    glVertex2f(-.48,.14);
//    glVertex2f(-.48,.17);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-.044,0,0);
//    glBegin(GL_QUADS);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.465,.17);
//    glVertex2f(-.465,.14);
//    glVertex2f(-.48,.14);
//    glVertex2f(-.48,.17);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-.066,0,0);
//    glBegin(GL_QUADS);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.465,.17);
//    glVertex2f(-.465,.14);
//    glVertex2f(-.48,.14);
//    glVertex2f(-.48,.17);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-.088,0,0);
//    glBegin(GL_QUADS);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.465,.17);
//    glVertex2f(-.465,.14);
//    glVertex2f(-.48,.14);
//    glVertex2f(-.48,.17);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-.11,0,0);
//    glBegin(GL_QUADS);
//    glColor3f(0.76, 0.77, 0.78);
//    glVertex2f(-.465,.17);
//    glVertex2f(-.465,.14);
//    glVertex2f(-.48,.14);
//    glVertex2f(-.48,.17);
//    glEnd();
//    glPopMatrix();
//
//
//
//    GLfloat xb7=-0.49f;
//    GLfloat yb7=0.06f;
//    GLfloat radiusb7 =.02f;
//	glColor3f(0.10, 0.10, 0.10);
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(xb7, yb7);
//		for(int i = 0; i <= triangleAmount;i++) {
//			glVertex2f( xb7 + (radiusb7 * cos(i *  twicePi / triangleAmount)),
//                        yb7 + (radiusb7 * sin(i * twicePi / triangleAmount)) );
//		}
//	glEnd();
//
//
//	 GLfloat xb8=-.49f; GLfloat yb8=0.06f;GLfloat radiusb8 =.014f;
//	glColor3f(0.47, 0.46, 0.46 );
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(xb8, yb8);
//		for(int i = 0; i <= triangleAmount;i++) {
//			glVertex2f( xb8 + (radiusb8 * cos(i *  twicePi / triangleAmount)),
//                        yb8 + (radiusb8 * sin(i * twicePi / triangleAmount)) );
//		}
//	glEnd();
//
//
//
//	 GLfloat xb9=-.57f;  GLfloat yb9=0.06f;GLfloat radiusb9 =.02f;
//	glColor3f(0.10, 0.10, 0.10 );
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(xb9, yb9);
//		for(int i = 0; i <= triangleAmount;i++) {
//			glVertex2f( xb9 + (radiusb9 * cos(i *  twicePi / triangleAmount)),
//                        yb9 + (radiusb9 * sin(i * twicePi / triangleAmount)) );
//		}
//	glEnd();
//
//
//
//	 GLfloat xb10=-.57f;
//	  GLfloat yb10=0.06f;
//	  GLfloat radiusb10 =.014f;
//	glColor3f(0.47, 0.46, 0.46);
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(xb10, yb10);
//		for(int i = 0; i <= triangleAmount;i++) {
//			glVertex2f( xb10 + (radiusb10 * cos(i *  twicePi / triangleAmount)),
//                        yb10 + (radiusb10* sin(i * twicePi / triangleAmount)) );
//		}
//	glEnd();
//
//    glLoadIdentity();
//    glPopMatrix();
//    glPopMatrix();

    //sea............................................................................................

    glPushMatrix();
    glTranslatef(0,-.1,0);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }

    glVertex2f(-1.0f, -0.35f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    //c1..............................
    glPushMatrix();
    glTranslatef(0,c1,0);
    GLfloat xw1=-0.9f;
    GLfloat yw1=-0.61f;
    GLfloat radiusw1 =0.3f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw1, yw1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw1 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw1 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c2..............................
    glPushMatrix();
    glTranslatef(0,c2,0);
    GLfloat xw2=0.3f;
    GLfloat yw2=-0.61f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw2, yw2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw2 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw2 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();


    //c3..............................
    glPushMatrix();
    glTranslatef(0,c3,0);
    GLfloat xw3=0.2f;
    GLfloat yw3=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw3, yw3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw3 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw3 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c4..............................

    glPushMatrix();
    glTranslatef(0,c4,0);
    GLfloat xw4=0.1f;
    GLfloat yw4=-0.63f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw4, yw4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw4 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw4 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();


    //c5..............................
    glPushMatrix();
    glTranslatef(0,c5,0);
    GLfloat xw5=-0.2f;
    GLfloat yw5=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw5, yw5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw5 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw5 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c6..............................
    glPushMatrix();
    glTranslatef(0,c6,0);
    GLfloat xw6=-0.8f;
    GLfloat yw6=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw6, yw6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw6 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw6 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c7..............................
    glPushMatrix();
    glTranslatef(0,c7,0);
    GLfloat xw7=-0.7f;
    GLfloat yw7=-0.63f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw7, yw7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw7 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw7 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c8..............................
    glPushMatrix();
    glTranslatef(0,c8,0);
    GLfloat xw8=-0.6f;
    GLfloat yw8=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw8, yw8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw8 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw8 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c9..............................
    glPushMatrix();
    glTranslatef(0,c9,0);
    GLfloat xw9=-0.5f;
    GLfloat yw9=-0.61f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw9, yw9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw9 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw9 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c10..............................
    glPushMatrix();
    glTranslatef(0,c10,0);
    GLfloat xw10=-0.4f;
    GLfloat yw10=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw10, yw10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw10 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw10 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c11..............................
    glPushMatrix();
    glTranslatef(0,c11,0);
    GLfloat xw11=-0.05f;
    GLfloat yw11=-0.63f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw11, yw11);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw11 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw11 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c12..............................
    glPushMatrix();
    glTranslatef(0,c12,0);
    GLfloat xw12=0.4f;
    GLfloat yw12=-0.61f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw12, yw12);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw12 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw12 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c13..............................
    glPushMatrix();
    glTranslatef(0,c13,0);
    GLfloat xw13=0.5f;
    GLfloat yw13=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw13, yw13);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw13 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw13 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c14..............................
    glPushMatrix();
    glTranslatef(0,c14,0);
    GLfloat xw14=0.6f;
    GLfloat yw14=-0.63f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw14, yw14);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw14 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw14 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c15..............................
    glPushMatrix();
    glTranslatef(0,c15,0);
    GLfloat xw15=0.7f;
    GLfloat yw15=-0.61f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw15, yw15);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw15 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw15 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();


    //c16..............................
    glPushMatrix();
    glTranslatef(0,c16,0);
    GLfloat xw16=0.8f;
    GLfloat yw16=-0.62f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw16, yw16);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw16 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw16 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    //c17..............................
    glPushMatrix();
    glTranslatef(0,c17,0);
    GLfloat xw17=0.9f;
    GLfloat yw17=-0.63f;
    glColor3f(0.0f,0.29f,0.6f);
    if(night)
    {
        glColor3f(0.0f, 0.09f, 0.4f);
    }
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw17, yw17);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw17 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw17 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();



    // small.boat...................................................................................
    glPushMatrix();
    glTranslatef(0,-.1,0);
    if(!night && ! rain)
    {
        glPushMatrix();
        glTranslatef(_run8,0,0);

        glPushMatrix();
        glTranslatef(0.01f, -0.2f, 0.0f);
        glScalef(.5,.5,0);


        glBegin(GL_POLYGON);

        glColor3f(0.4f,0.0f,0.0f);

        glVertex2f(-0.75f, -0.47f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.75f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.44f);

        glVertex2f(-0.75f, -0.44f);
        glVertex2f(-0.8f, -0.4f);

        glVertex2f(-0.65f, -0.44f);
        glVertex2f(-0.75f, -0.44f);

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.0f,0.6f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.67f, -0.39f);
        glVertex2f(-0.65f, -0.435f);
        glVertex2f(-0.7f, -0.435f);


        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.7f, -0.43f);
        glVertex2f(-0.75f, -0.418f);


        glEnd();
        glLoadIdentity();
        glPopMatrix();

        glPopMatrix();
    }
    glPopMatrix();

    //smallboat night
    if(night || rain)
    {
        glPushMatrix();
        glTranslatef(1.1,-.05,0);

        glPushMatrix();
        glTranslatef(0.01f, -0.2f, 0.0f);
        glScalef(.5,.5,0);


        glBegin(GL_POLYGON);

        glColor3f(0.4f,0.0f,0.0f);

        glVertex2f(-0.75f, -0.47f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.75f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.44f);

        glVertex2f(-0.75f, -0.44f);
        glVertex2f(-0.8f, -0.4f);

        glVertex2f(-0.65f, -0.44f);
        glVertex2f(-0.75f, -0.44f);

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.0f,0.6f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.67f, -0.39f);
        glVertex2f(-0.65f, -0.435f);
        glVertex2f(-0.7f, -0.435f);


        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.7f, -0.43f);
        glVertex2f(-0.75f, -0.418f);


        glEnd();
        glLoadIdentity();
        glPopMatrix();

        glPopMatrix();
    }

    //small boat copy...........................................................
    glPushMatrix();
    glTranslatef(0,-.1,0);
    if(!night && !rain)
    {
        glPushMatrix();
        glTranslatef(_run9,0,0);

        glPushMatrix();
        glTranslatef(0.09f,-0.3f, 0.0f);
        glRotatef(180,0,1,0);

        glScalef(.5,.5,0);


        glBegin(GL_POLYGON);

        glColor3f(0.2f,0.1f,0.0f);

        glVertex2f(-0.75f, -0.47f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.75f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.44f);

        glVertex2f(-0.75f, -0.44f);
        glVertex2f(-0.8f, -0.4f);

        glVertex2f(-0.65f, -0.44f);
        glVertex2f(-0.75f, -0.44f);

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.9f,0.5f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.67f, -0.39f);
        glVertex2f(-0.65f, -0.435f);
        glVertex2f(-0.7f, -0.435f);


        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.7f, -0.43f);
        glVertex2f(-0.75f, -0.418f);

        glEnd();
        glLoadIdentity();
        glPopMatrix();

        glPopMatrix();

    }
    glPopMatrix();
///night
    if(night || rain)
    {
        glPushMatrix();
        glTranslatef(.17,.05,0);

        glPushMatrix();
        glTranslatef(0.09f,-0.3f, 0.0f);
        glRotatef(180,0,1,0);

        glScalef(.5,.5,0);


        glBegin(GL_POLYGON);

        glColor3f(0.2f,0.1f,0.0f);

        glVertex2f(-0.75f, -0.47f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.47f);

        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.75f, -0.47f);

        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.44f);

        glVertex2f(-0.75f, -0.44f);
        glVertex2f(-0.8f, -0.4f);

        glVertex2f(-0.65f, -0.44f);
        glVertex2f(-0.75f, -0.44f);

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.9f,0.5f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.67f, -0.39f);
        glVertex2f(-0.65f, -0.435f);
        glVertex2f(-0.7f, -0.435f);


        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,0.0f);

        glVertex2f(-0.72f, -0.39f);
        glVertex2f(-0.7f, -0.43f);
        glVertex2f(-0.75f, -0.418f);

        glEnd();
        glLoadIdentity();
        glPopMatrix();

        glPopMatrix();

    }
    //big_boat...............................................................................................

    glPushMatrix();
    glTranslatef(_run10,0,0);

    glPushMatrix();
    glTranslatef(0.01f,-0.3f, 0.0f);
    glScalef(.7f,0.6f,0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.29f,0.0f);

    glVertex2f(0.1f, -0.8f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.2f, -0.9f);

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.6f, -0.8f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.5f, -0.9f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.18f, -0.88f);
    glVertex2f(0.2f, -0.9f);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.42f, -0.88f);

    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(0.15f, -0.75f);
    glVertex2f(0.45f, -0.75f);
    glVertex2f(0.45f, -0.8f);
    glVertex2f(0.15f, -0.8f);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f, -0.75f);
    glVertex2f(0.45f, -0.75f);
    glVertex2f(0.45f, -0.8f);
    glVertex2f(0.55f, -0.8f);

    glColor3f(0.8f,0.6f,1.0f);
    glVertex2f(0.15f, -0.75f);
    glVertex2f(0.45f, -0.75f);
    glVertex2f(0.4f, -0.7f);
    glVertex2f(0.15f, -0.7f);

    glColor3f(0.6f,0.6f,1.0f);
    glVertex2f(0.55f, -0.75f);
    glVertex2f(0.45f, -0.75f);
    glVertex2f(0.4f, -0.7f);
    glVertex2f(0.5f, -0.7f);
    glEnd();
    /**.................................... big boat-Pillar .......................................**/
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.65f);
    glVertex2f(0.21f, -0.65f);
    glVertex2f(0.21f, -0.7f);
    glVertex2f(0.18f, -0.7f);
    glEnd();

    glColor3f(0.6f,0.29f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.65f);
    glVertex2f(0.21f, -0.65f);
    glVertex2f(0.21f, -0.63f);
    glVertex2f(0.18f, -0.63f);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.28f, -0.65f);
    glVertex2f(0.31f, -0.65f);
    glVertex2f(0.31f, -0.7f);
    glVertex2f(0.28f, -0.7f);
    glEnd();

    glColor3f(0.6f,0.29f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.28f, -0.65f);
    glVertex2f(0.31f, -0.65f);
    glVertex2f(0.31f, -0.63f);
    glVertex2f(0.28f, -0.63f);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.38f, -0.65f);
    glVertex2f(0.41f, -0.65f);
    glVertex2f(0.41f, -0.7f);
    glVertex2f(0.38f, -0.7f);
    glEnd();

    glColor3f(0.6f,0.29f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.38f, -0.65f);
    glVertex2f(0.41f, -0.65f);
    glVertex2f(0.41f, -0.63f);
    glVertex2f(0.38f, -0.63f);
    glEnd();


    /**.................................... big boat-design .......................................**/

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25f, 0.0f, 0.0f);
    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();

    glPopMatrix();

    glColor3f(0.6f,0.8f,1.0f);
    if (night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(0.46f, -0.79f);
    glVertex2f(0.54f, -0.79f);
    glVertex2f(0.54f, -0.76f);
    glVertex2f(0.46f, -0.76f);
    glEnd();


    GLfloat xboat1=0.175f;
    GLfloat yboat1=-0.84f;
    GLfloat radiusb =.015f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat1, yboat1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat1 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat1 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();




    glPushMatrix();
    glTranslatef(0.045f, 0.0f, 0.0f);
    GLfloat xboat2=0.18f;
    GLfloat yboat2=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat2, yboat2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat2 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat2 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.095f, 0.0f, 0.0f);
    GLfloat xboat3=0.18f;
    GLfloat yboat3=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat3, yboat3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat3 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat3 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.145f, 0.0f, 0.0f);
    GLfloat xboat4=0.18f;
    GLfloat yboat4=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat4, yboat4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat4 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat4 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.195f, 0.0f, 0.0f);
    GLfloat xboat5=0.18f;
    GLfloat yboat5=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat5, yboat5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat5 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat5 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.245f, 0.0f, 0.0f);
    GLfloat xboat6=0.18f;
    GLfloat yboat6=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat6, yboat6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat6 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat6 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
    glLoadIdentity();

    glPopMatrix();

    glPopMatrix();


    //rains <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    if(rain)
    {
        glPushMatrix();
        glTranslatef(_rain1x,_rain1y,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();

        //rain 2 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain2x,_rain2y,0);

        glPushMatrix();
        glTranslatef(-.02,-.2,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 3 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain3x,_rain3y,0);

        glPushMatrix();
        glTranslatef(-.0,-.4,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 4 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain4x,_rain4y,0);

        glPushMatrix();
        glTranslatef(-.03,-.6,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 5 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain5x,_rain5y,0);

        glPushMatrix();
        glTranslatef(-.03,-.8,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 6 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain6x,_rain6y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 7 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain7x,_rain7y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.2,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 8 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain8x,_rain8y,0);

        glPushMatrix();
        glTranslatef(-.0,-1.4,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 9 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain9x,_rain9y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.6,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 10 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain10x,_rain10y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.8,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();
    }

    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.52f, 0.5f, 0.0f, GLUT_BITMAP_9_BY_15, "Hospital");

    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.811f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Inani");


    glColor3f(0.6,0.0,0.0);
    renderBitmapString(-0.85f, 0.4f, 0.0f, GLUT_BITMAP_HELVETICA_10, "La Bella Resort");

    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.59f, 0.61f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Neeshorgo Hotel");

    glColor3f(0.0,0.2,0.0);
    renderBitmapString(0.11f, 0.375f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Mermaid Cafe Marine Drive");







    ////ENDS Here
  if(!cover){
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.36, 0.0);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.18, 0.36, 0.56);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    glColor3f(1.0,1.0,1.0);

     renderBitmapString(-0.3f, 0.85f, 0.0f, GLUT_BITMAP_HELVETICA_18, " 01054 - COMPUTER GRAPHICS [M]");


    glPushMatrix();
    //glTranslatef(_run11,0,0);
    renderBitmapString(-0.24f, 0.75f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MARINE DRIVE COX BAZAR");
    glLoadIdentity();
    glPopMatrix();


    renderBitmapString(-0.28f, 0.65f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted by Group[1] Code hunter");
    renderBitmapString(-0.4f, 0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID                                 Name                                         Contribution ");
    renderBitmapString(-0.4f, 0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-39385-1                Sazzdul alam Shawon                     25% ");
    renderBitmapString(-0.4f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "18-38939-3                Md. Rifat Hossain                            25% ");
    renderBitmapString(-0.4f, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-39371-1                Jannatul Ferdus                               19% ");
    renderBitmapString(-0.4f, 0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-39500-1                Abdullah al Mahmud                        16% ");
    renderBitmapString(-0.4f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-41686-3                Jamil Ahammed                                15% ");

    renderBitmapString(-0.11f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted to");
    renderBitmapString(-0.18f, -0.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MAHFUJUR RAHAMAN");
    renderBitmapString(-0.22f, -0.65f, 0.0f, GLUT_BITMAP_HELVETICA_12, "FACULTY OF SCIENCE & TECHNOLOGY");
    renderBitmapString(-0.2f, -0.7f, 0.0f, GLUT_BITMAP_HELVETICA_10, "American International University-Bangladesh");
  }
//vertex01
//    glLineWidth(1);
//
//    glBegin(GL_LINES);            // Each set of 4 vertices form a quad
//    glColor3f(0.0f, 1.0f, 0.0f); // green
//
//    glVertex2f(0.0f, 0.0f);    // x, y
//    glVertex2f(1.0f, 0.0f);    // x, y
//
//    glVertex2f(0.0f, 0.0f);    // x, y
//    glVertex2f(0.0f, 1.0f);    // x, y
//
//    glVertex2f(0.0f, 0.0f);    // x, y
//    glVertex2f(-1.0f, 0.0f);    // x, y
//
//    glVertex2f(0.0f, 0.0f);    // x, y
//    glVertex2f(0.0f, -1.0f);
//    glEnd();
//
//    glBegin(GL_LINES);
//    glColor3f(0.0f,0.0f,0.0f);
//
//    glVertex2f(-1.0f, 0.1f);    // x, y
//    glVertex2f(1.0f, 0.1f);
//    glVertex2f(-1.0f, 0.2f);    // x, y
//    glVertex2f(1.0f, 0.2f);
//    glVertex2f(-1.0f, 0.3f);    // x, y
//    glVertex2f(1.0f, 0.3f);
//    glVertex2f(-1.0f, 0.4f);    // x, y
//    glVertex2f(1.0f, 0.4f);
//    glVertex2f(-1.0f, 0.5f);    // x, y
//    glVertex2f(1.0f, 0.5f);
//    glVertex2f(-1.0f, 0.6f);    // x, y
//    glVertex2f(1.0f, 0.6f);
//    glVertex2f(-1.0f, 0.7f);    // x, y
//    glVertex2f(1.0f, 0.7f);
//    glVertex2f(-1.0f, 0.8f);    // x, y
//    glVertex2f(1.0f, 0.8f);
//    glVertex2f(-1.0f, 0.9f);    // x, y
//    glVertex2f(1.0f, 0.9f);
//
//    glVertex2f(-1.0f, -0.1f);    // x, y
//    glVertex2f(1.0f, -0.1f);
//    glVertex2f(-1.0f, -0.2f);    // x, y
//    glVertex2f(1.0f, -0.2f);
//    glVertex2f(-1.0f, -0.3f);    // x, y
//    glVertex2f(1.0f, -0.3f);
//    glVertex2f(-1.0f, -0.4f);    // x, y
//    glVertex2f(1.0f, -0.4f);
//    glVertex2f(-1.0f, -0.5f);    // x, y
//    glVertex2f(1.0f, -0.5f);
//    glVertex2f(-1.0f, -0.6f);    // x, y
//    glVertex2f(1.0f, -0.6f);
//    glVertex2f(-1.0f, -0.7f);    // x, y
//    glVertex2f(1.0f, -0.7f);
//    glVertex2f(-1.0f, -0.8f);    // x, y
//    glVertex2f(1.0f, -0.8f);
//    glVertex2f(-1.0f, -0.9f);    // x, y
//    glVertex2f(1.0f, -0.9f);
//
//    glVertex2f(0.1f, 1.0f);    // x, y
//    glVertex2f(0.1f, -1.0f);
//    glVertex2f(0.2f, 1.0f);    // x, y
//    glVertex2f(0.2f, -1.0f);
//    glVertex2f(0.3f, 1.0f);    // x, y
//    glVertex2f(0.3f, -1.0f);
//    glVertex2f(0.4f, 1.0f);    // x, y
//    glVertex2f(0.4f, -1.0f);
//    glVertex2f(0.5f, 1.0f);    // x, y
//    glVertex2f(0.5f, -1.0f);
//    glVertex2f(0.6f, 1.0f);    // x, y
//    glVertex2f(0.6f, -1.0f);
//    glVertex2f(0.7f, 1.0f);    // x, y
//    glVertex2f(0.7f, -1.0f);
//    glVertex2f(0.8f, 1.0f);    // x, y
//    glVertex2f(0.8f, -1.0f);
//    glVertex2f(0.9f, 1.0f);    // x, y
//    glVertex2f(0.9f, -1.0f);
//
//    glVertex2f(-0.1f, 1.0f);    // x, y
//    glVertex2f(-0.1f, -1.0f);
//    glVertex2f(-0.2f, 1.0f);    // x, y
//    glVertex2f(-0.2f, -1.0f);
//    glVertex2f(-0.3f, 1.0f);    // x, y
//    glVertex2f(-0.3f, -1.0f);
//    glVertex2f(-0.4f, 1.0f);    // x, y
//    glVertex2f(-0.4f, -1.0f);
//    glVertex2f(-0.5f, 1.0f);    // x, y
//    glVertex2f(-0.5f, -1.0f);
//    glVertex2f(-0.6f, 1.0f);    // x, y
//    glVertex2f(-0.6f, -1.0f);
//    glVertex2f(-0.7f, 1.0f);    // x, y
//    glVertex2f(-0.7f, -1.0f);
//    glVertex2f(-0.8f, 1.0f);    // x, y
//    glVertex2f(-0.8f, -1.0f);
//    glVertex2f(-0.9f, 1.0f);    // x, y
//    glVertex2f(-0.9f, -1.0f);
//    glEnd();




    glFlush();  // Render now
}


void update(int value)
{
    if(!cover)
    {
        _run11 += .003f;

        if (_run11 > 1.25)
    {
        _run11 = -1;
    }

    }


    if(on)
    {
        if(!vehicleStop)
        {
            _run7 -= vehicleSpeed;
            if(!handup)
            {
                _run4 += vehicleSpeed;
            }
            _run5 += (vehicleSpeed+.001);
            _run6 -= (vehicleSpeed+.001);
            _run3 -= (vehicleSpeed+.002);
        }
        _run1 += .0003f;
        _run2 -= .0002f;
        _run10 += .0009f;

        if(rain)
        {
            _rain1y -= .05;
            _rain2y -= .05;
            _rain3y -= .05;
            _rain4y -= .05;
            _rain5y -= .05;
            _rain6y -= .05;
            _rain7y -= .05;
            _rain8y -= .05;
            _rain9y -= .05;
            _rain10y -= .05;
            i += 1;
            _rain1x -= .0055;
            _rain2x -= .0055;
            _rain3x -= .0055;
            _rain4x -= .0055;
            _rain5x -= .0055;
            _rain6x -= .0055;
            _rain7x -= .0055;
            _rain8x -= .0055;
            _rain9x -= .0055;
            _rain10x -= .0055;
        }

        if(waveUp)
        {
            c1 += .00042;
            c2 += .00042;
            c3 += .00042;
            c4 += .00042;
            c5 += .00042;
            c6 += .00042;
            c7 += .00042;
            c8 += .00042;
            c9 += .00042;
            c10 += .00042;
            c11 += .00042;
            c12 += .00042;
            c13 += .00042;
            c14 += .00042;
            c15 += .00042;
            c16 += .00042;
            c17 += .00042;
        }
        else
        {
            c1 -= .00032;
            c2 -= .00032;
            c3 -= .00032;
            c4 -= .00032;
            c5 -= .00032;
            c6 -= .00032;
            c7 -= .00032;
            c8 -= .00032;
            c9 -= .00032;
            c10 -= .00032;
            c11 -= .00032;
            c12 -= .00032;
            c13 -= .00032;
            c14 -= .00032;
            c15 -= .00032;
            c16 -= .00032;
            c17 -= .00032;
        }


        if(!night && !rain)
        {
            _run8 -= .0005f;
            _run9 += .0005f;
            //_run10 += .0009f;
        }
    }

    if (_run7 < -1.7)
    {
        _run7 = .5;//float _rain2y = 0.0;
    }
    if (_run5 > 1)
    {
        _run5 = -1.2;
    }
    if (_run6 < -1)
    {
        _run6 = 1.2;
    }
    if (_run4 > 1.7)
    {
        _run4 = -.6;
    }
    if (_run3 < -1.7)
    {
        _run3 = 1.3;
    }
    if (_run1 > 1.7)
    {
        _run1= -.6;
    }
    if (_run2 < -1.9)
    {
        _run2= .35;
    }
    if (_run8 < -.8)
    {
        _run8= 1.5;
    }
    if (_run9 > .8)
    {
        _run9= -1.5;
    }
    if (_run10 > .9)
    {
        _run10= -1.5;
    }
    if(_rain1y < -1.9)
    {
        _rain1y = .1;
        _rain1x = 0;
    }
    if(_rain2y < -1.7)
    {
        _rain2y = .3;
        _rain2x = 0;
    }
    if(_rain3y < -1.5)
    {
        _rain3y = .5;
        _rain3x = 0;
    }
    if(_rain4y < -1.3)
    {
        _rain4y = .7;
        _rain4x = 0;
    }
    if(_rain5y < -1.1)
    {
        _rain5y = 0.9;
        _rain5x = 0;
    }
    if(_rain6y < -.9)
    {
        _rain6y = 1.1;
        _rain6x = 0;
    }
    if(_rain7y < -.7)
    {
        _rain7y = 1.3;
        _rain7x = 0;
    }
    if(_rain8y < -.5)
    {
        _rain8y = 1.5;
        _rain8x = 0;
    }
    if(_rain9y < -.3)
    {
        _rain9y = 1.7;
        _rain9x = 0;
    }
    if(_rain10y < -.1)
    {
        _rain10y = 1.9;
        _rain10x = 0;
    }

    if(i == 120)
    {
        resetRain();
    }

    if (c1 >= .08)
    {
        waveUp = false;
    }
    if (c1 < 0.0)
    {
        waveUp = true;
    }
    if (c2 >= .08)
    {
        waveUp = false;
    }
    if (c2 < 0.0)
    {
        waveUp = true;
    }
    if (c3 >= .08)
    {
        waveUp = false;
    }
    if (c3 < 0.0)
    {
        waveUp = true;
    }
    if (c4 >= .08)
    {
        waveUp = false;
    }
    if (c4 < 0.0)
    {
        waveUp = true;
    }
    if (c5 >= .08)
    {
        waveUp = false;
    }
    if (c5 < 0.0)
    {
        waveUp = true;
    }

    if (c6 >= .08)
    {
        waveUp = false;
    }
    if (c6 < 0.0)
    {
        waveUp = true;
    }
    if (c7 >= .08)
    {
        waveUp = false;
    }
    if (c7 < 0.0)
    {
        waveUp = true;
    }
    if (c8 >= .08)
    {
        waveUp = false;
    }
    if (c8 < 0.0)
    {
        waveUp = true;
    }
    if (c9 >= .08)
    {
        waveUp = false;
    }
    if (c9 < 0.0)
    {
        waveUp = true;
    }
    if (c10 >= .08)
    {
        waveUp = false;
    }
    if (c10 < 0.0)
    {
        waveUp = true;
    }

    if (c11 >= .08)
    {
        waveUp = false;
    }
    if (c11 < 0.0)
    {
        waveUp = true;
    }
    if (c12 >= .08)
    {
        waveUp = false;
    }
    if (c12 < 0.0)
    {
        waveUp = true;
    }
    if (c13 >= .08)
    {
        waveUp = false;
    }
    if (c13 < 0.0)
    {
        waveUp = true;
    }
    if (c14 >= .08)
    {
        waveUp = false;
    }
    if (c14 < 0.0)
    {
        waveUp = true;
    }
    if (c15 >= .08)
    {
        waveUp = false;
    }
    if (c15 < 0.0)
    {
        waveUp = true;
    }
    if (c16 >= .08)
    {
        waveUp = false;
    }
    if (c16 < 0.0)
    {
        waveUp = true;
    }
    if (c17 >= .08)
    {
        waveUp = false;
    }
    if (c17 < 0.0)
    {
        waveUp = true;
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed
    glutTimerFunc(25, update, 0);
}

void SpecialInput(int key, int x, int y)
{

    switch(key)
    {
    case GLUT_KEY_UP:
        if(vehicleSpeed >= 0)
        {
            vehicleStop = false;
        }
        vehicleSpeed = vehicleSpeed + 0.001;
        break;

    case GLUT_KEY_DOWN:
        //if(vehicleSpeed >= 0){
        if(vehicleSpeed > 0)
        {
            vehicleSpeed = vehicleSpeed - 0.001;
        }
        if(vehicleSpeed <= 0)
        {
            vehicleStop = true;
        }
        break;
    }
    glutPostRedisplay();
}

void Input(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'n':
        night = true;

        sndPlaySound("H:\\AIUB\\9th sem\\01054 - COMPUTER GRAPHICS [M]\\CGPROJECT\\music\\night.wav",SND_ASYNC);

        break;
    case 'd':
        night = false;
        sndPlaySound("H:\\AIUB\\9th sem\\01054 - COMPUTER GRAPHICS [M]\\CGPROJECT\\music\\day.wav",SND_ASYNC);
        break;

    case '0':
        on= false;
        break;

    case '1':
        on = true;
        break;

        case 's':
                if(cover)
        {
            cover = false;
        }
        else
        {
            cover = true;
        }
        break;

    case '+':
        glutFullScreen();
        break;

    case '-':
        glutReshapeWindow(1024,576);
        glutInitWindowPosition(50,40);
        break;

    case 'x':
        //glutHideWindow();
        exit(0);
        break;

    case 'r':
        rain = true;
        sndPlaySound("H:\\AIUB\\9th sem\\01054 - COMPUTER GRAPHICS [M]\\CGPROJECT\\music\\rain.wav",SND_ASYNC);
        break;

    case 'e':

        rain = false;
        break;

    case 'h':
        if(handup)
        {
            handup = false;
        }
        else
        {
            handup = true;
        }
        break;

    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    cout << "Press s : For Start" << endl << endl;
    cout << "Press 1 : For Animation ON " << endl << endl;
    cout << "Press 0 : For Animation OFF " << endl << endl;
    cout << "Press h : For hands up and down " << endl << endl;
    cout << "Press n : For Night " << endl << endl;
    cout << "Press d : For Day " << endl << endl;
    cout << "Press r : For Rain start " << endl << endl;
    cout << "Press e : For Rain stop " << endl << endl;
    cout << "Press UP arrow : For Speed up " << endl << endl;
    cout << "Press Down Arrow : For Speed Down " << endl << endl;
    cout << "Press + : For Full Screen " << endl << endl;
    cout << "Press - : For Restore Screen " << endl << endl;
    cout << "Press x : For Hide Screen " << endl << endl;

    glutInitWindowSize(1024,576);
    glutInit(&argc, argv);
    glutCreateWindow("MARINE DRIVE COX BAZAR");
    glutInitWindowPosition(50,40);
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(Input);
    glutTimerFunc(25,update,0);

    glutMainLoop();

    return 0;
}
