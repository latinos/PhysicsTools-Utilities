#include <cppunit/extensions/HelperMacros.h>
#include "PhysicsTools/Utilities/interface/Gaussian.h"
#include "PhysicsTools/Utilities/interface/Exponential.h"
#include "PhysicsTools/Utilities/interface/Product.h"
#include "PhysicsTools/Utilities/interface/Sum.h"
#include "PhysicsTools/Utilities/interface/Ratio.h"
#include "PhysicsTools/Utilities/interface/Difference.h"
#include "PhysicsTools/Utilities/interface/Minus.h"
#include <cmath>

class testFunctions : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(testFunctions);
  CPPUNIT_TEST(checkAll);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() {}
  void tearDown() {}
  void checkAll(); 
};

CPPUNIT_TEST_SUITE_REGISTRATION(testFunctions);

void testFunctions::checkAll() {
  using namespace function;
  Gaussian g1(0, 1);
  Gaussian g2(1, 1);
  const double epsilon = 1.e-6;
  Sum<Gaussian, Gaussian> g1plus2 = g1 + g2;
  Product<Gaussian, Gaussian> g1times2 = g1 * g2; 
  Difference<Gaussian, Gaussian> g1minus2 = g1 - g2;
  Ratio<Gaussian, Gaussian> g1over2 = g1 / g2; 
  Minus<Gaussian> gm1 = - g1;
  double x = 0.5;
  CPPUNIT_ASSERT(fabs(g1plus2(x) - (g1(x) + g2(x))) < epsilon);
  CPPUNIT_ASSERT(fabs(g1times2(x) - (g1(x) * g2(x))) < epsilon);
  CPPUNIT_ASSERT(fabs(g1minus2(x) - (g1(x) - g2(x))) < epsilon);
  CPPUNIT_ASSERT(fabs(g1over2(x) - (g1(x) / g2(x))) < epsilon);
  CPPUNIT_ASSERT(fabs(gm1(x) - (-g1(x)) < epsilon));
}
