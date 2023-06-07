#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
int inctree = 0;
double a = 0, b = 0, a2 = -90;
int i, j, spaceCount = 0;
int tortoiselegs[] = {-2, 6, 22, 30};
int ssTortoisey = 220;
int ssTortoisex = 50;
int ssHarex = 800;
int ssHarey = 150;
int tCount;
void display();
void display2();
void display3();
void movement();
void delay(float);
void roadAndTrees();
void roadAndTrees2();
void hareScene();
void tortoiseraces();
void Tortoise();
unsigned int bg1, bg2;
void init()
{
    glClearColor(0.1, 0.8, 0.1, 1.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 1000, 0, 500);
}

void display_string(int x, int y, char *string, int font)
{
    int len, i;
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        if (font == 1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
        if (font == 2)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        if (font == 3)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
        if (font == 4)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string[i]);
    }
}

void NormalKey(GLubyte key, GLint x, GLint y)
{
    int m;
    switch (key)
    {
    case 27:
        printf("Escape pressed. exit.\n");
        exit(0);
        break;

    case ' ':
        delay(0.3);
        spaceCount++;
        if (spaceCount == 1)
        {
            tCount = 0;
            display2();
        }
        if (spaceCount == 2)
        {
            display();
        }
        if (spaceCount == 3)
        {
            display3();
        }

        break;
    case 'f':
    case 'F':
        glutFullScreen();
        spaceCount = 0;
        tCount = 0;
        break;
    case 's':
    case 'S':
        if (spaceCount == 1)
        {
            tCount++;
            switch (tCount)
            {
            case 1:
                display_string(580, 360, "I am the fastest animal in the whole wide world.", 1);
                break;
            case 2:
                display_string(80, 330, "All Lies!!!", 1);
                display_string(80, 310, "Stop Boasting, If you are not careful then you will meet your", 1);
                display_string(80, 290, "end.", 1);
                break;
            case 3:
                display_string(580, 280, "I will prove to you all that I’m the fastest animal", 1);
                display_string(580, 260, "in the whole World.", 1);
                break;
            case 4:
                display_string(80, 240, "OK! I'll race you then...", 1);
                break;
            case 5:
                display_string(580, 210, "* Laughs Heavily *", 1);
                break;
            case 6:
                display_string(80, 180, "You just Wait and See...", 1);
                break;
            case 7:
                display_string(300, 90, "PRESS SPACE BAR TO PROCEED TO THE RACE", 1);
                break;
            }
            glFlush();
        }
        break;
    case 'o':
    case 'O':
        for (m = 0; m < 25; m++)
        {
            movement();
            delay(0.05);
        }
        hareScene();
        delay(1);
        delay(1);
        display_string(330, 320, "He is somewhere far away so", 1);
        display_string(330, 300, "I can sleep for a while", 1);
        glFlush();
        delay(1);
        delay(1);
        hareScene();
        delay(1);
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(4);
        glBegin(GL_POINTS);
        glVertex2i(278, 273);
        glEnd();
        glFlush();
        delay(1);
        display_string(310, 310, "Z", 1);
        display_string(300, 290, "Z", 1);
        glFlush();
        delay(1);
        display_string(300, 180, "(Tortoise continues to run slowly and steadily.)", 1);
        glFlush();
        delay(1);
        delay(1);
        for (m = 0; m < 28; m++)
        {
            tortoiseraces();
            delay(0.05);
            glutSwapBuffers();
        }

        delay(1);
        display_string(750, 230, "I Win!!!", 1);
        glFlush();
        delay(1);
        display_string(300, 200, "(The Hare was over confident", 1);
        display_string(300, 180, "and- that lead to his failure ) ", 1);
        glFlush();
        break;
    }
}
void tortoiseraces()
{
    hareScene();
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2i(278, 273);
    glEnd();
    display_string(310, 310, "Z", 1);
    display_string(300, 290, "Z", 1);
    glFlush();
    glPushMatrix();
    glTranslated(a2, 0, 0);
    Tortoise();
    //Hare();
    glPopMatrix();
    a2 += 30;
    glFlush();
}
void roadAndTrees2()
{
    //Road
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 150);
    glVertex2i(1000, 150);
    glVertex2i(1000, 350);
    glVertex2i(0, 350);
    glEnd();

    //Top Trees
    for (i = 0; i < 14; i++)
    {
        glColor3f(1.0, 0.4, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(30 + inctree, 400);
        glVertex2i(40 + inctree, 400);
        glVertex2i(40 + inctree, 420);
        glVertex2i(30 + inctree, 420);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;

    for (i = 0; i < 14; i++)
    {
        glColor3f(0.0, 0.4, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(20 + inctree, 420);
        glVertex2f(55 + inctree, 420);
        glVertex2f(35 + inctree, 470);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;

    //Bottom Trees
    for (i = 0; i < 14; i++)
    {
        glColor3f(1.0, 0.4, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(30 + inctree, 30);
        glVertex2i(40 + inctree, 30);
        glVertex2i(40 + inctree, 50);
        glVertex2i(30 + inctree, 50);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;

    for (i = 0; i < 14; i++)
    {
        glColor3f(0.0, 0.4, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(20 + inctree, 50);
        glVertex2f(55 + inctree, 50);
        glVertex2f(35 + inctree, 100);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;
}

void roadAndTrees()
{
    //Road
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 150);
    glVertex2i(1000, 150);
    glVertex2i(1000, 350);
    glVertex2i(0, 350);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(100, 150);
    glVertex2i(100, 350);
    glEnd();
    //Top Trees
    for (i = 0; i < 14; i++)
    {
        glColor3f(1.0, 0.4, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(30 + inctree, 400);
        glVertex2i(40 + inctree, 400);
        glVertex2i(40 + inctree, 420);
        glVertex2i(30 + inctree, 420);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;

    for (i = 0; i < 14; i++)
    {
        glColor3f(0.0, 0.4, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(20 + inctree, 420);
        glVertex2f(55 + inctree, 420);
        glVertex2f(35 + inctree, 470);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;

    //Bottom Trees
    for (i = 0; i < 14; i++)
    {
        glColor3f(1.0, 0.4, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(30 + inctree, 30);
        glVertex2i(40 + inctree, 30);
        glVertex2i(40 + inctree, 50);
        glVertex2i(30 + inctree, 50);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;

    for (i = 0; i < 14; i++)
    {
        glColor3f(0.0, 0.4, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(20 + inctree, 50);
        glVertex2f(55 + inctree, 50);
        glVertex2f(35 + inctree, 100);
        glEnd();
        inctree = inctree + 70;
    }
    inctree = 0;
}
void Tortoise()
{

    float x, y;
    float t;
    //Tortoise
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 50 + 22 * cos(t);
        y = 180 + 22 * sin(t);
        glVertex2f(50, 180);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 0.5, 0.0); //This covers the bottom half of the circle.
    glBegin(GL_POLYGON);
    glVertex2i(28, 180);
    glVertex2i(72, 180);
    glVertex2i(72, 158);
    glVertex2i(28, 158);
    glEnd();

    //Tortoise Face
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 82 + 7 * cos(t);
        y = 184 + 7 * sin(t);
        glVertex2f(72, 182);
        glVertex2f(x, y);
    }
    glEnd();

    //Tortoise Legs
    for (i = 0; i < 4; i++)
    {
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON);
        glVertex2i(32 + tortoiselegs[i], 170);
        glVertex2i(38 + tortoiselegs[i], 170);
        glVertex2i(37 + tortoiselegs[i], 180);
        glVertex2i(33 + tortoiselegs[i], 180);
        glEnd();
    }
}
void Tortoise2()
{

    float x, y;
    float t;
    //Tortoise
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = (50 + ssTortoisex) + 22 * cos(t);
        y = (180 + ssTortoisey) + 22 * sin(t);
        glVertex2f(50 + ssTortoisex, 180 + ssTortoisey);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 0.5, 0.0); //This covers the bottom half of the circle.
    glBegin(GL_POLYGON);
    glVertex2i(28 + ssTortoisex, 180 + ssTortoisey);
    glVertex2i(72 + ssTortoisex, 180 + ssTortoisey);
    glVertex2i(72 + ssTortoisex, 158 + ssTortoisey);
    glVertex2i(28 + ssTortoisex, 158 + ssTortoisey);
    glEnd();

    //Tortoise Face
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = (82 + ssTortoisex) + 7 * cos(t);
        y = (184 + ssTortoisey) + 7 * sin(t);
        glVertex2f(72 + ssTortoisex, 182 + ssTortoisey);
        glVertex2f(x, y);
    }
    glEnd();

    //Tortoise Legs
    for (i = 0; i < 4; i++)
    {
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON);
        glVertex2i(32 + tortoiselegs[i] + ssTortoisex, 170 + ssTortoisey);
        glVertex2i(38 + tortoiselegs[i] + ssTortoisex, 170 + ssTortoisey);
        glVertex2i(37 + tortoiselegs[i] + ssTortoisex, 180 + ssTortoisey);
        glVertex2i(33 + tortoiselegs[i] + ssTortoisex, 180 + ssTortoisey);
        glEnd();
    }
}
void Hare()
{

    float x, y;
    float t;

    //Rabbit
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 210 + 40);
    glVertex2i(60, 210 + 40);
    glVertex2i(70, 220 + 40);
    glVertex2i(70, 230 + 40);
    glVertex2i(60, 240 + 40);
    glVertex2i(50, 240 + 40);
    glVertex2i(40, 230 + 40);
    glVertex2i(40, 220 + 40);
    glEnd();

    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 78 + 9 * cos(t);
        y = 273 + 9 * sin(t);
        glVertex2f(70, 260);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2i(78, 273);
    glEnd();

    //Rabbit Ears
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 74 + 4 * cos(t);
        y = 295 + 4 * sin(t);
        glVertex2f(70, 270);
        glVertex2f(x, y);
    }
    glEnd();
}
void Hare2()
{

    float x, y;
    float t;

    //Rabbit Body
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(50 + ssHarex, 210 + 40 + ssHarey);
    glVertex2i(60 + ssHarex, 210 + 40 + ssHarey);
    glVertex2i(70 + ssHarex, 220 + 40 + ssHarey);
    glVertex2i(70 + ssHarex, 230 + 40 + ssHarey);
    glVertex2i(60 + ssHarex, 240 + 40 + ssHarey);
    glVertex2i(50 + ssHarex, 240 + 40 + ssHarey);
    glVertex2i(40 + ssHarex, 230 + 40 + ssHarey);
    glVertex2i(40 + ssHarex, 220 + 40 + ssHarey);
    glEnd();

    //Rabbit Face
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = (78 + ssHarex) + 9 * cos(t);
        y = (273 + ssHarey) + 9 * sin(t);
        glVertex2f(70 + ssHarex, 260 + ssHarey);
        glVertex2f(x, y);
    }
    glEnd();

    //Rabbit Eye
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2i(78 + ssHarex, 273 + ssHarey);
    glEnd();

    //Rabbit Ears
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = (74 + ssHarex) + 4 * cos(t);
        y = (295 + ssHarey) + 4 * sin(t);
        glVertex2f(70 + ssHarex, 270 + ssHarey);
        glVertex2f(x, y);
    }
    glEnd();
}

void delay(float secs)
{
    float end = clock() / CLOCKS_PER_SEC + secs;
    while ((clock() / CLOCKS_PER_SEC) < end)
        ;
}
void display()
{
    //This is the Race Scene
    glClearColor(0.1, 0.8, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    display_string(500, 110, "Press O to race", 1);
    //init();
    roadAndTrees();
    //glPushMatrix();
    //glTranslated(a,0,0);
    Tortoise();
    Hare();
    //glPopMatrix();
    //a+=10;
    glFlush();
}

void movement()
{
    //This is the Race Scene
    glClearColor(0.1, 0.8, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //init();

    roadAndTrees();
    glPushMatrix();
    glTranslated(a, 0, 0);
    //Tortoise();
    Hare();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b, 0, 0);
    Tortoise();
    //Hare();
    glPopMatrix();
    b += 15;
    a += 50;
    glFlush();
}

void hareScene()
{
    glClearColor(0.1, 0.8, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //init();
    roadAndTrees2();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(700, 150);
    glVertex2i(700, 350);
    glEnd();
    glPushMatrix();
    glTranslated(200, 0, 0);
    //Tortoise();
    Hare();
    glPopMatrix();
    //a+=10;
    glFlush();
}

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glTexCoord2f(0, 0);
    glVertex2f(0, 500);
    glTexCoord2f(0, 1);
    glVertex2f(1000, 500);
    glTexCoord2f(1, 1);
    glVertex2f(1000, 0);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void display2()
{
    //This is the Second Screen (Conversation)
    glClearColor(1.0, 0.5, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    display_string(300, 100, "Press S to converse", 1);
    Hare2();
    Tortoise2();
    glFlush();
}

void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg2);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glTexCoord2f(0, 0);
    glVertex2f(0, 500);
    glTexCoord2f(0, 1);
    glVertex2f(1000, 500);
    glTexCoord2f(1, 1);
    glVertex2f(1000, 0);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
void menu(int value)
{
    switch (value)
    {
    case 0:
        exit(0);
        break;
    case 1:
        glutDisplayFunc(display1);
        glutKeyboardFunc(NormalKey);
        spaceCount = 0;
        glutPostRedisplay();
    }
}

void loadBackground(void)
{
    glGenTextures(1, &bg1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("S1BG.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}
void loadMoral(void)
{
    glGenTextures(1, &bg2);
    glBindTexture(GL_TEXTURE_2D, bg2);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("Moral.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load moral" << std::endl;
    }
    stbi_image_free(data);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("Hare and Tortoise");
    glutPositionWindow(50, 50);
    init();
    loadBackground();
    loadMoral();
    glutDisplayFunc(display1);
    glutKeyboardFunc(NormalKey);
    glutCreateMenu(menu);
    glutAddMenuEntry("Exit", 0);
    glutAddMenuEntry("Reset", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
