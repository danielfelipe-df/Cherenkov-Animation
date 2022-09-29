/**
 * @file line.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 28/09/2022
 *
 * @brief
 */


#ifndef LINE_H
#define LINE_H


#include <vector>


/**
 * @brief
 *
 * @class Line
 */
class Line{

 public:
  /// Length
  std::vector<double> length;

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
  Line(size_t numberLines=1, double initLength=-10.0, double initX=-1.0, double initY=0.0, double initZ=0.0, double initRotX=90, double initRotY=0.0, double initRotZ=0.0);


  /**
   * @brief
   */
  ~Line();


  /* Methods */
  /**
   * @brief
   */
  void move(void);
};


#endif /* LINE_H */
