/*
 * QuaternionsTest.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: gech
 */

#include <iostream>

#include <gtest/gtest.h>

#include <rm/quaternions/QuaternionEigen.hpp>

namespace quat = rm::quaternions::eigen_implementation;


template <typename QuaternionImplementation>
struct QuaternionsTest : public ::testing::Test  {
  typedef typename QuaternionImplementation::Scalar Scalar;
  typedef Eigen::Matrix<Scalar, 3, 1> Vector3;

  QuaternionImplementation identity = QuaternionImplementation(quat::Quaternion<Scalar>(Eigen::Quaterniond(1, 0, 0, 0).cast<Scalar>()));
  QuaternionImplementation halfX =    QuaternionImplementation(quat::Quaternion<Scalar>(Eigen::Quaterniond(0, 1, 0, 0).cast<Scalar>()));
  QuaternionImplementation halfY =    QuaternionImplementation(quat::Quaternion<Scalar>(Eigen::Quaterniond(0, 0, 1, 0).cast<Scalar>()));
  QuaternionImplementation halfZ =    QuaternionImplementation(quat::Quaternion<Scalar>(Eigen::Quaterniond(0, 0, 0, 1).cast<Scalar>()));
  QuaternionImplementation generic =  QuaternionImplementation(quat::Quaternion<Scalar>(Eigen::Quaterniond(1, 2, 3, 4).cast<Scalar>()));
  QuaternionImplementation genericInverse =  QuaternionImplementation(quat::Quaternion<Scalar>(Eigen::Quaterniond(1, -2, -3, -4).cast<Scalar>()));

  QuaternionsTest() : X(Vector3::UnitX()), Y(Vector3::UnitY()), Z(Vector3::UnitZ()) {}
  Vector3 X, Y, Z;
};



typedef ::testing::Types<
quat::QuaternionD,
quat::QuaternionF
> Types;

TYPED_TEST_CASE(QuaternionsTest, Types);

TYPED_TEST (QuaternionsTest, testQuatenionMultiplication ) {

	auto q1 = this->generic;
	auto q2 = q1.inverse();

//	std::cout << q1.toImplementation.x() << std::endl;
//	ASSERT_EQ(q2.toImplementatio	n.x() ==this->genericInverse.toImplementation.x(),"inverse");

}




TEST (RotationsTest, testQuaternionVarious ) {

  quat::UnitQuaternion<double> uquat1(1,2,3,4);
  quat::UnitQuaternion<double> uquat2(uquat1);
  quat::UnitQuaternion<double> uquat3;
  uquat3 = uquat1;
  std::cout << uquat1 << std::endl;
  std::cout << uquat2 << std::endl;
  std::cout << uquat3 << std::endl;
  std::cout << uquat1.conjugate() << std::endl;
  std::cout << uquat1.inverse() << std::endl;
  std::cout << uquat1*uquat2 << std::endl;
  std::cout << (uquat1==uquat2) << std::endl;
  std::cout << std::endl;


  quat::Quaternion<double> quat1(1,2,3,4);
  quat::Quaternion<double> quat2(quat1);
  quat::Quaternion<double> quat3;
  quat3 = quat1;
  std::cout << quat1 << std::endl;
  std::cout << quat2 << std::endl;
  std::cout << quat3 << std::endl;
  std::cout << quat1.conjugate() << std::endl;
  std::cout << quat1.inverse() << std::endl;
  std::cout << quat1*quat2 << std::endl;
  std::cout << (quat1==quat2) << std::endl;
  std::cout << std::endl;


  std::cout << uquat1*quat2 << std::endl;
  std::cout << (uquat1==quat2) << std::endl;
  std::cout << std::endl;



}
