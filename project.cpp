#include <GL/glut.h>
#include <bits/stdc++.h>
float ship_x = 0,ship_y = 0;
float boat_x = 0,boat_y = 0;
float fish_x,fish_y = 0;
float sun_x = 0,sun_y = 0;
float night = 0;
int ship_flag = 0,fish_flag = 0,boat_flag = 0,sun_flag = 0;
class Point 
{
    public:
        float x, y, z;
        Point(float a, float b, float c) {
            x = a;
            y = b;
            z = c;
        }
};
class Circle 
{
    public:
        Point *center;
        float radius;
        Circle(Point *p, float r)
        {
            center = p;
            radius = r;
        }
        void drawCircle() 
        {
            glBegin(GL_POLYGON);
            glColor3f(1.0,0.5,0.0);
            for (float angle = 0; angle < 2 * M_PI; angle = angle + 0.01)
            {
                glVertex2f(radius * cos(angle) + center -> x, radius * sin(angle) + center -> y);
            }
            glEnd();
        }
};
void background(float color)
{
    glBegin(GL_POLYGON);
    glColor3f(0.2+color,0.6+color,0.8+color);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glVertex2f(1000,800);
    glVertex2f(0,800);
    glEnd();
}
void sun(int x,int y)
{
	Point *center = new Point(900+x,700+y,0);
    Circle *circle = new Circle(center,40);
    circle->drawCircle();
}
void water()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(0,0);
    glVertex2f(1000,0);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
}
void boat(int x,int y)
{
    glBegin(GL_POLYGON);
    //glColor3f(0.5,0.35,0.05);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(750+x,180+y);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(900+x,190+y);
    glColor3f(0.5,0.35,0.05);
    glVertex2f(910+x,230+y);
    glColor3f(0.5,0.35,0.05);
    glVertex2f(720+x,250+y);
    glEnd();
}
void ship(int x,int y)
{
    //Base of the ship
    glBegin(GL_POLYGON);
    glColor3f(0.29f,0.07f,0.43f);
    glVertex2f(30+x,240+y);
    glColor3f(0.29f,0.07f,0.43f);
    glVertex2f(30+x,220+y);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(80+x,140+y);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(440+x,85+y);
    glColor3f(0.29f,0.07f,0.43f);
    glVertex2f(585+x,200+y);
    glColor3f(0.29f,0.07f,0.43f);
    glVertex2f(600+x,220+y);
    glEnd();    
    //Storey 1
    glColor3f(0.70,0.0,0.0);
    glBegin(GL_POLYGON);    
    glVertex2f(70+x,240+y);
    glVertex2f(70+x,260+y);
    glVertex2f(478+x,262+y);
    glVertex2f(478+x,222+y);
    glVertex2f(70+x,238+y);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.50,0.0,0.0);
    glVertex2f(478+x,262+y);
    glVertex2f(478+x,222+y);
    glVertex2f(514+x,220+y);
    glVertex2f(514+x,254+y);
    glEnd();
    //Storey 2
    glColor3f(0.30,0.30,0.30);
    glBegin(GL_POLYGON);
    glVertex2f(102+x,282+y);
    glVertex2f(102+x,260+y);
    glVertex2f(442+x,262+y);
    glVertex2f(442+x,282+y);
    glEnd();
    //Mast
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(180+x,260+y);
    glVertex2f(180+x,290+y);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(360+x,260+y);
    glVertex2f(360+x,300+y);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(140+x,285+y);
    glVertex2f(420+x,280+y);
    glVertex2f(430+x,500+y);
    glVertex2f(142+x,490+y);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(142+x,490+y);
    glVertex2f(430+x,500+y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(286+x,495+y);
    glVertex2f(290+x,600+y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(256+x,530+y);
    glVertex2f(316+x,530+y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(266+x,570+y);
    glVertex2f(306+x,570+y);
    glEnd();
}
void fish(int x,int y)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(100+x,85+y);
    glVertex2f(100+x,115+y);
    glVertex2f(140+x,100+y);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(140+x,100+y);
    glVertex2f(190+x,120+y);
    glVertex2f(240+x,100+y);
    glVertex2f(190+x,80+y);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(190+x,100+y);
    glVertex2f(220+x,100+y);
    glVertex2f(160+x,150+y);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(190+x,100+y);
    glVertex2f(220+x,100+y);
    glVertex2f(160+x,50+y);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    for(int i=218;i<=222;i++)
    {
        for(int j=99;j<=101;j++)
        {
            glVertex2f(i+x,j+y);
        }
    }
    glEnd();
}
void fishes(int x,int y)
{
    fish(x,y);
    fish(x+120,y-50);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    if(ship_flag==0)
    {
	   ship_x += 0.15;
    }
    if(boat_flag==0)
    {
        boat_x -= 0.1;
    }
    if(fish_flag==0)
    {
        fish_x += 0.1;
    }
    if(sun_flag==0)
    {
        sun_y  -= 0.17;
        night -= 0.00025;
    }
    background(night);
    sun(sun_x,sun_y);
    water();
    boat(boat_x,boat_y);
	ship(ship_x,ship_y);
	fishes(fish_x,fish_y);
	glutPostRedisplay();
	glFlush();
	glutSwapBuffers();
}
void init()
{
	glClearColor(0.2,0.6,0.8,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1000,0,800);	
}
void keyboard(unsigned char key,int x, int y)
{
    if(key==97)
    {
        if(ship_flag)
        {
            ship_flag = 0;
        }
        else
        {
            ship_flag = 1;
        }
    }
    if(key==115)
    {
        if(boat_flag)
        {
            boat_flag = 0;
        } 
        else
        {
            boat_flag = 1;
        }
    }
    if(key==100)
    {
        if(fish_flag)
        {
            fish_flag = 0;
        }
        else
        {
            fish_flag = 1;
        }
    }
    if(key==102)
    {
        if(sun_flag)
        {
            sun_flag = 0;
            boat_flag = 0;
            ship_flag = 0;
            fish_flag = 0;
        }
        else
        {
            fish_flag = 1;
            boat_flag = 1;
            sun_flag = 1;
            ship_flag = 1;
        }
    }
}
int main(int argc,char	**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Ship Scenery");
	glutSwapBuffers();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glEnable(GL_SMOOTH);
	init();
	glutMainLoop();	
    return 0;
}