/**
 * @file axis_controller.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#include <axis_controller.h>

#include <GL/glu.h>
#include <GL/glut.h>


AxisController::AxisController(bool showAxis){
  this->X = 0.0f;
  this->Y = 0.0f;
  this->Z = 0.0f;

  this->rotX = 0.0f;
  this->rotY = 0.0f;
  this->rotZ = 0.0f;

  this->rotLx = 0.0f;
  this->rotLy = 0.0f;
  this->rotLz = 0.0f;

  this->showAxis = showAxis;
}


AxisController::~AxisController(void){

}



