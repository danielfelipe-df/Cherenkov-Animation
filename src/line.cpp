/**
 * @file line.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#include <line.h>

#include <GL/gl.h>


Line::Line(size_t numberLines, double initLength, double initX, double initY, double initZ, double initRotX, double initRotY, double initRotZ){
  this->length.resize(numberLines);

  this->X.resize(numberLines);
  this->Y.resize(numberLines);
  this->Z.resize(numberLines);

  this->rotX.resize(numberLines);
  this->rotY.resize(numberLines);
  this->rotZ.resize(numberLines);

  for(size_t i=0; i!=numberLines; i++){
    this->length[i] = initLength;

    this->X[i] = initX;
    this->Y[i] = initY;
    this->Z[i] = initZ;

    this->rotX[i] = initRotX;
    this->rotY[i] = initRotY;
    this->rotZ[i] = initRotZ;
  }
}


Line::~Line(){
  this->length.clear();

  this->X.clear();
  this->Y.clear();
  this->Z.clear();

  this->rotX.clear();
  this->rotY.clear();
  this->rotZ.clear();
}


void Line::move(void){
  // Line
  glPushMatrix();
  glTranslated(this->X[0], this->Y[0], this->Z[0]);
  glRotatef(this->rotX[0], 1.0, 0.0, 0.0); // Rotate on x
  glRotatef(this->rotY[0], 0.0, 1.0, 0.0); // Rotate on y
  glRotatef(this->rotZ[0], 0.0, 0.0, 1.0); // Rotate on z

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3d(this->length[0], 0.0, 0.0);
  glVertex3d(0.0, 0.0, 0.0);
  glEnd();

  glPopMatrix();
}
