/**
 * @file torus.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#include <torus.h>

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>


Torus::Torus(bool isTorus, size_t numberTorus, double initInnerRadius, double initOuterRadius, double initX, double initY, double initZ, double initRotX, double initRotY, double initRotZ){
  this->isTorus = isTorus;

  this->innerRadius.resize(numberTorus);
  this->outerRadius.resize(numberTorus);

  this->X.resize(numberTorus);
  this->Y.resize(numberTorus);
  this->Z.resize(numberTorus);

  this->rotX.resize(numberTorus);
  this->rotY.resize(numberTorus);
  this->rotZ.resize(numberTorus);

  for(size_t i=0; i!=numberTorus; i++){
    this->innerRadius[i] = initInnerRadius;
    this->outerRadius[i] = initOuterRadius;

    this->X[i] = initX;
    this->Y[i] = initY;
    this->Z[i] = initZ;

    this->rotX[i] = initRotX;
    this->rotY[i] = initRotY;
    this->rotZ[i] = initRotZ;
  }
}


Torus::~Torus(){
  this->innerRadius.clear();
  this->outerRadius.clear();

  this->X.clear();
  this->Y.clear();
  this->Z.clear();

  this->rotX.clear();
  this->rotY.clear();
  this->rotZ.clear();
}


void Torus::move(size_t i){
  //Torus
  glPushMatrix();
  glTranslated(this->X[i], this->Y[i], this->Z[i]);
  glRotatef(this->rotX[i], 1.0, 0.0, 0.0); // Rotate on x
  glRotatef(this->rotY[i], 0.0, 1.0, 0.0); // Rotate on y
  glRotatef(this->rotZ[i], 0.0, 0.0, 1.0); // Rotate on z

  glColor3f(0.0f, 0.0f, 1.0f);
  if(this->isTorus)
    glutSolidTorus(this->innerRadius[i], this->outerRadius[i], 20, 20);
  else
    glutWireSphere(this->outerRadius[i], 20, 20);

  glPopMatrix();
}
