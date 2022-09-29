/**
 * @file code.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 27/09/2022
 * @brief
 */


#include <axis_controller.h>
#include <cone.h>
#include <line.h>
#include <torus.h>

#include <iostream>
#include <GL/glu.h>
#include <GL/glut.h>


AxisController axis(false);
Cone cone;
Line lines;
Torus torus(false);

int localTime = 0;
int wavesFrequency = 150;

double particleVelocity = 5e-4;
double velocitiesQuotient = 0.99;
double lightVelocity = particleVelocity/velocitiesQuotient;
double refractionIndex = 5.0;

unsigned int wavesDraws = 50;


/**
 * @brief
 * @param
 * @param
 * @param
 * @param
 */
void mouse(int button, int state, int x, int y);


/**
 * @brief
 * @param
 * @param
 * @param
 */
void specialKey(int key, int x, int y);


/**
 * @brief
 * @param
 * @param
 * @param
 */
void keyboard(unsigned char key, int x, int y);


/**
 * @brief
 */
void display(void);


/**
 * @brief
 */
void init(void);


/**
 * @brief
 */
void animationDisplay(void);


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1200, 300);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("Cherenkov Animation");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard); // set window's key callback
  glutSpecialFunc(specialKey);

  glutMainLoop();

  return 0;
}


void init(void){
  /* select clearing (background) color
  glClearColor(0.0, 0.0, 0.0, 0.0);
  */
  /*initialize viewing values */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //glOrtho(1200/120.0, 0.0, 0.0, 300/120.0, -1.0, 1.0);

  // Cone
  glColor3f(0.5f, 0.5f, 0.0f);
  glutSolidCone(cone.radius[0], cone.height[0], 100, 100);
  glEnd();

  // Line
  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3d(lines.length[0], 0.0, 0.0);
  glVertex3d(0.0, 0.0, 0.0);
  glEnd();

  // Torus
  glColor3f(0.0f, 0.0f, 1.0f);
  glutSolidTorus(torus.innerRadius[0], torus.outerRadius[0], 100, 100);
}


void animationDisplay(void){
  cone.X[0] += particleVelocity;
  cone.Y[0] = 0.0;
  cone.Z[0] = 0.0;

  lines.X[0] += particleVelocity;
  lines.Y[0] = 0.0;
  lines.Z[0] = 0.0;

  for(size_t i=0; i!=torus.outerRadius.size(); i++)
    torus.outerRadius[i] += lightVelocity/refractionIndex;

  localTime++;

  glutPostRedisplay();
}


void mouse(int button, int state, int x, int y){
  switch(button){
  case GLUT_LEFT_BUTTON:
    if(state == GLUT_DOWN)
      glutIdleFunc(animationDisplay);
    break;
  case GLUT_MIDDLE_BUTTON:
    if (state == GLUT_DOWN)
      glutIdleFunc(NULL);
    break;
  default:
    break;
  }
}


// called on special key pressed
void specialKey(int key, int x, int y){

  // The keys below are using the gluLookAt() function for navigation
  // Check which key is pressed

  switch(key){
  case GLUT_KEY_LEFT : // Rotate on x axis
    axis.X -= 0.1f;
    break;
  case GLUT_KEY_RIGHT : // Rotate on x axis (opposite)
    axis.X += 0.1f;
    break;
  case GLUT_KEY_UP : // Rotate on y axis
    axis.Y += 0.1f;
    break;
  case GLUT_KEY_DOWN : // Rotate on y axis (opposite)
    axis.Y -= 0.1f;
    break;
  case GLUT_KEY_PAGE_UP: // Rotate on z axis
    axis.Z -= 0.1f;
    break;
  case GLUT_KEY_PAGE_DOWN:// Rotate on z axis (opposite)
    axis.Z += 0.1f;
    break;
  }

  glutPostRedisplay(); // Redraw the scene
}


// This function is used for the navigation keys
void keyboard(unsigned char key, int x, int y){
  switch(key){   // x,X,y,Y,z,Z uses the glRotatef() function
  case 'x': // Rotates screen on x axis
    axis.rotX -= 0.5f;
    break;
  case 'X': // Opposite way
    axis.rotX += 0.5f;
    break;
  case 'y': // Rotates screen on y axis
    axis.rotY -= 0.5f;
    break;
  case 'Y': // Opposite way
    axis.rotY += 0.5f;
    break;
  case 'z': // Rotates screen on z axis
    axis.rotZ -= 0.5f;
    break;
  case 'Z': // Opposite way
    axis.rotZ += 0.5f;
    break;
    // j,J,k,K,l,L uses the gluLookAt function for navigation
  case 'j':
    axis.rotLx -= 0.2f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0 + axis.rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 'J':
    axis.rotLx += 0.2f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0 + axis.rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 'k':
    axis.rotLy -= 0.2f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0 + axis.rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 'K':
    axis.rotLy += 0.2f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0 + axis.rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 'l': 	// It has a special case when the rotLZ becomes
		// less than -15 the screen is viewed from the opposite side
    // therefore this if statement below does not allow rotLz be less than -15
    if(axis.rotLz + 14 >= 0)
      axis.rotLz -= 0.2f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0 + axis.rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 'L':
    axis.rotLz += 0.2f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0 + axis.rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 'b': // Rotates on x axis by -90 degree
    axis.rotX -= 90.0f;
    break;
  case 'B': // Rotates on y axis by 90 degree
    axis.rotX += 90.0f;
    break;
  case 'n': // Rotates on y axis by -90 degree
    axis.rotY -= 90.0f;
    break;
  case 'N': // Rotates on y axis by 90 degree
    axis.rotY += 90.0f;
    break;
  case 'm': // Rotates on z axis by -90 degree
    axis.rotZ -= 90.0f;
    break;
  case 'M': // Rotates on z axis by 90 degree
    axis.rotZ += 90.0f;
    break;
  case 'o': // Default, resets the translations vies from starting view
  case 'O':
    axis.X = 0.0f;
    axis.Y = 0.0f;
    axis.Z = 0.0f;
    axis.rotX = 0.0f;
    axis.rotY = 0.0f;
    axis.rotZ = 0.0f;
    axis.rotLx = 0.0f;
    axis.rotLy = 0.0f;
    axis.rotLz = 0.0f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(axis.rotLx, axis.rotLy, 15.0f + axis.rotLz, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    break;
  }

  glutPostRedisplay(); // Redraw the scene
}


void display(void){
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  glTranslated(axis.X, axis.Y, axis.Z);
  glRotatef(axis.rotX, 1.0, 0.0, 0.0); // Rotate on x
  glRotatef(axis.rotY, 0.0, 1.0, 0.0); // Rotate on y
  glRotatef(axis.rotZ, 0.0, 0.0, 1.0); // Rotate on z

  if(axis.showAxis){

    // Draw the positive side of the lines x,y,z
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); // Green for x axis
    glVertex3f(0,0,0);
    glVertex3f(10,0,0);
    glColor3f(1.0,0.0,0.0); // Red for y axis
    glVertex3f(0,0,0);
    glVertex3f(0,10,0);
    glColor3f(0.0,0.0,1.0); // Blue for z axis
    glVertex3f(0,0,0);
    glVertex3f(0,0,10);
    glEnd();

    // Dotted lines for the negative sides of x,y,z
    glEnable(GL_LINE_STIPPLE); 	// Enable line stipple to use a
				// dotted pattern for the lines
    glLineStipple(1, 0x0101); 	// Dotted stipple pattern for the lines
    glBegin(GL_LINES);
    glColor3f (0.0, 1.0, 0.0); 	// Green for x axis
    glVertex3f(-10,0,0);
    glVertex3f(0,0,0);
    glColor3f(1.0,0.0,0.0); 	// Red for y axis
    glVertex3f(0,0,0);
    glVertex3f(0,-10,0);
    glColor3f(0.0,0.0,1.0); 	// Blue for z axis
    glVertex3f(0,0,0);
    glVertex3f(0,0,-10);
    glEnd();
    glDisable(GL_LINE_STIPPLE); 	// Disable the line stipple
  }

  lines.move();

  cone.move();

  if(localTime%wavesFrequency == 0 and localTime != 0){
    torus.X.push_back(cone.X[0] + cone.height[0]);
    torus.Y.push_back(0.0);
    torus.Z.push_back(0.0);

    torus.rotX.push_back(0.0);
    torus.rotY.push_back(90);
    torus.rotZ.push_back(0.0);

    torus.innerRadius.push_back(5e-3);
    torus.outerRadius.push_back(0);
  }

  size_t initial = (torus.X.size() < wavesDraws) ? 0 : torus.X.size()-wavesDraws;
  for(size_t i=initial; i!=torus.X.size(); i++)
    torus.move(i);

  glPopMatrix(); 		// Don't forget to pop the Matrix
  glutSwapBuffers();
}
