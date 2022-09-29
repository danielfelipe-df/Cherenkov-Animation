/**
 * @file axis_controller.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#ifndef AXIS_CONTROLLER_H
#define AXIS_CONTROLLER_H


#include <GL/gl.h>


/**
 * @brief
 *
 * @class AxisController
 */
class AxisController{

public:
  /// Translate screen on x axis
  GLfloat X;
  /// Translate screen on y axis
  GLfloat Y;
  /// Translate screen on z axis
  GLfloat Z;

  /// Rotate screen on x axis
  GLfloat rotX;
  /// Rotate screen on y axis
  GLfloat rotY;
  /// Rotate screen on z axis
  GLfloat rotZ;

  /// Translate screen by using the glulookAt function (left or right)
  GLfloat rotLx;
  /// Translate screen by using the glulookAt function (up or down)
  GLfloat rotLy;
  /// Translate screen by using the glulookAt function (zoom in or out)
  GLfloat rotLz;

  /// Display axis
  bool showAxis;


 public:
  /* Contructor and destructor */
  /**
   * @brief
   */
  AxisController(bool showAxis);


  /**
   * @brief
   */
  ~AxisController();
};


#endif /* AXIS_CONTROLLER_H */
