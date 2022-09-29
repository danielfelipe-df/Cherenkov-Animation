/**
 * @file cone.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#include <cone.h>

#include <GL/gl.h>
#include <GL/glut.h>


Cone::Cone(size_t numberCones, double initRadius, double initHeight, double initX, double initY, double initZ, double initRotX, double initRotY, double initRotZ){
  this->radius.resize(numberCones);
  this->height.resize(numberCones);

  for(size_t i=0; i!=numberCones; i++){
    this->radius[i] = initRadius;
    this->height[i] = initHeight;
  }

  this->X.resize(numberCones);
  this->Y.resize(numberCones);
  this->Z.resize(numberCones);

  for(size_t i=0; i!=numberCones; i++){
    this->X[i] = initX;
    this->Y[i] = initY;
    this->Z[i] = initZ;
  }


  this->rotX.resize(numberCones);
  this->rotY.resize(numberCones);
  this->rotZ.resize(numberCones);

  for(size_t i=0; i!=numberCones; i++){
    this->rotX[i] = initRotX;
    this->rotY[i] = initRotY;
    this->rotZ[i] = initRotZ;
  }
}


Cone::~Cone(){
  this->X.clear();
  this->Y.clear();
  this->Z.clear();

  this->rotX.clear();
  this->rotY.clear();
  this->rotZ.clear();

  this->radius.clear();
  this->height.clear();
}


void Cone::move(void){
  // Cone
  glPushMatrix();
  glTranslated(this->X[0], this->Y[0], this->Z[0]);
  glRotatef(this->rotX[0], 1.0, 0.0, 0.0); // Rotate on x
  glRotatef(this->rotY[0], 0.0, 1.0, 0.0); // Rotate on y
  glRotatef(this->rotZ[0], 0.0, 0.0, 1.0); // Rotate on z

  glColor3f(0.5f, 0.5f, 0.0f);
  glutSolidCone(this->radius[0], this->height[0], 100, 100);

  glPopMatrix();
}
