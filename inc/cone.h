/**
 * @file cone.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#ifndef CONE_H
#define CONE_H


#include <vector>


/**
 * @brief
 *
 * @class Cone
 */
class Cone{

 public:
  /// Radius
  std::vector<double> radius;
  /// Height
  std::vector<double> height;

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


  /* Contructor and destructor */
  /**
   * @brief
   */
  Cone(size_t numberCones=1, double initRadius=2e-2, double initHeight=6e-2, double initX=-1.0, double initY=0.0, double initZ=0.0, double initRotX=0-0, double initRotY=90, double initRotZ=0.0);


  /**
   * @brief
   */
  ~Cone();


  /* Methods */
  /**
   * @brief
   */
  void move(void);
};


#endif /* CONE_H */
