//
// Created by wein on 5/1/18.
//

#include <assert.h>
#include <math.h>

void RunTinyTests();

void assertAlmostEqual(double lhs, double rhs, double threshold) {
    assert(fabs(lhs - rhs) < threshold);
}

void test_extractFractionAndDecimal() {
    double sut = 3.1415926;
    double compI = .0;
    double compF = .0;
    compF = modf(sut, &compI);
    assertAlmostEqual(compI, 3, 1e-17);
    assertAlmostEqual(compF, 0.1415926, 1e-16);  //1e-17 will fail
}

void test_midwayRounding() {
    assertAlmostEqual(floor(0.999999999123123 + 0.5), 1, 1e-16);
    assertAlmostEqual(floor(0.000000000123241 + 0.5), 0, 1e-16);
}

void test_fixedPointRounding() {
    double precision = pow(10, 3);  // fixed 3 decimal points
    assertAlmostEqual(round(0.9999999999123123123 * precision) / precision, 1, 1e-16);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
