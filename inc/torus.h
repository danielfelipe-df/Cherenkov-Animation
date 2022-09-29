/**
 * @file torus.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#ifndef TORUS_H
#define TORUS_H


#include <vector>


/**
 * @brief
 *
 * @class Torus
 */
class Torus{

 public:
  /// Inner radius
  std::vector<double> innerRadius;
  /// Outer radius
  std::vector<double> outerRadius;

  /// Translate screen on x axis
  std::vector<double> X;
  /// Translate screen on y axis
  std::vector<double> Y;
  /// Translate screen on z axis
  std::vector<double> Z;

  /// Rotate screen on x axis
  std::vector<double> rotX;
  /// Rotate screen on y axis
  std::vector<double> rotY;
  /// Rotate screen on z axis
  std::vector<double> rotZ;

  /// True draws torus, if not draws spheres
  bool isTorus;


  /* Contructor and destructor */
  /**
   * @brief
   */
  Torus(bool isTorus=true, size_t numberTorus=1, double initInnerRadius=5e-3, double initOuterRadius=0.0, double initX=-1.0, double initY=0.0, double initZ=0.0, double initRotX=0.0, double initRotY=90, double initRotZ=0.0);


  /**
   * @brief
   */
  ~Torus();


  /* Methods */
  /**
   * @brief
   */
  void move(size_t i);
};


#endif /* TORUS_H */
