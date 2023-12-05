#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>

// Define your menu action functions here
void menu();
void mainMenu(GLint option);
void ObjSubMenu(GLint objectOption);
void MCSTransMenu(GLint transOption);
void WCSTransMenu(GLint transOption);
void VCSTransMenu(GLint transOption);
void reset();
void light();
void MCSTransform(GLint);
void WCSTransform(GLint);
void VCSTransform(GLint);
void cullMenu(GLint option);
void lightMenu(GLint option);
void lightTransform(GLint);
void shadeMenu(GLint option);
void animateMenu(GLint option);
void curveSurfaceMenu(GLint option);
void move();

#endif // MENU_HPP_
