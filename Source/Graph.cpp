//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <gl\gl.h>
#include <gl\glu.h>
#include "Graph.h"
#include "Levers.cpp"

#define LevDiam 10
#define BalDiam 30
#define JointLeng (BalDiam+LevDiam)
#define CentDiam 30

//---------------------------------------------------------------------------

int GLCreate(HWND handle)
{
 hdc=GetDC(handle);
 PIXELFORMATDESCRIPTOR pfd = {
    	        sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                24,
                0,0,0,0,0,0,
                0,0,
                0,0,0,0,0,
                32,
                0,
                0,
                PFD_MAIN_PLANE,
                0,
                0,0,
 };
 int PixelFormat=ChoosePixelFormat(hdc,&pfd);
 SetPixelFormat(hdc,PixelFormat,&pfd);
 hrc=wglCreateContext(hdc);
 if(hrc==NULL)
  return -1;
 if(!wglMakeCurrent(hdc,hrc))
  return -1;
 glShadeModel( GL_SMOOTH );
 GLfloat amb_light[] = { 6.0, 0.0, 0.1, 1 };
 GLfloat diffuse[] = { 6.6, 0, 0.6, 1 };
 GLfloat specular[] = { 0.7, 0.0, 0.3, 1 };
 glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );
 glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
 glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
 glEnable( GL_LIGHT0 );
 glClearColor(0.0,0.0,0.0,0.0);
 glEnable(GL_COLOR_MATERIAL);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 glEnable(GL_SCISSOR_TEST);
 float p[4]={10,10,10,0};
 glLightfv(GL_LIGHT0,GL_POSITION,p);
 GLMainObj=gluNewQuadric();
 gluQuadricDrawStyle(GLMainObj,GLU_FILL);
 glRotatef(90,0,1,0);
 return 0;
}
//---------------------------------------------------------------------------

void GLTerminate(void)
{
 gluDeleteQuadric(GLMainObj);
 wglMakeCurrent(NULL, NULL);
 wglDeleteContext(hrc);
}
//---------------------------------------------------------------------------
void GLResize(int width,int height)
{
 Height=height;
 Width=width;
 glViewport(0,0,width,height);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-(width/2),width/2, -(height/2),height/2,-(height/2),height/2);
 glMatrixMode(GL_MODELVIEW);
 glScissor(0,0,Width,Height);
}
//---------------------------------------------------------------------------

void GLClear(void)
{
 glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}
//---------------------------------------------------------------------------

void GLCreateObjects(Levers *Lever)
{
 //  Draw lever
 glColor3f(0.7,0.5,1);
 glRotatef(Lever->LevAngle,1,0,0);
 gluCylinder(GLMainObj,LevDiam,LevDiam,Lever->LevLength,10,10);
 glRotatef(-Lever->LevAngle,1,0,0);

 //  Draw lever plug
 glTranslatef(0,-Lever->LevEnd.y,Lever->LevEnd.x);
 gluSphere(GLMainObj,LevDiam,20,20);
 glTranslatef(0,Lever->LevEnd.y,-Lever->LevEnd.x);

 //  Draw shoulder joint
 glTranslatef(0,-Lever->LevEnd.y,Lever->LevEnd.x);
 glRotatef(-90,0,1,0);
 gluCylinder(GLMainObj,LevDiam,0,JointLeng,10,10);
 glRotatef(90,0,1,0);
 glTranslatef(0,Lever->LevEnd.y,-Lever->LevEnd.x);

 //  Draw shoulder
 glColor3f(0.5,0.2,0.5);
 glTranslatef(-JointLeng,-Lever->ShBegin.y,Lever->ShBegin.x);
 glRotatef(Lever->ShAngle,1,0,0);
 gluCylinder(GLMainObj,LevDiam,LevDiam,Lever->ShLength,10,10);
 glRotatef(-Lever->ShAngle,1,0,0);
 glTranslatef(JointLeng,Lever->ShBegin.y,-Lever->ShBegin.x);

 //  Draw shoulder plugs
 glTranslatef(-JointLeng,-Lever->ShBegin.y,Lever->ShBegin.x);
 gluSphere(GLMainObj,LevDiam,20,20);
 glTranslatef(JointLeng,Lever->ShBegin.y,-Lever->ShBegin.x);

 glTranslatef(-JointLeng,-Lever->ShEnd.y,Lever->ShEnd.x);
 gluSphere(GLMainObj,LevDiam,20,20);
 glTranslatef(JointLeng,Lever->ShEnd.y,-Lever->ShEnd.x);

 //  Draw balance
 glColor3f(0,0.5,1);
 glTranslatef(-JointLeng,-Lever->BalCenter.y,Lever->BalCenter.x);
 gluSphere(GLMainObj,BalDiam,20,20);
 glTranslatef(JointLeng,Lever->BalCenter.y,-Lever->BalCenter.x);

 //  Draw central sphere
 glColor3f(1,1,0.5);
 gluSphere(GLMainObj,CentDiam,20,10);
}
//---------------------------------------------------------------------------

void GLPaint(void)
{
 SwapBuffers(hdc);              //  Show all
}
//---------------------------------------------------------------------------

void GLRotate(int Deg)
{
 glRotatef(Deg,0,1,0);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
