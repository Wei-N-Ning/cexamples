//
// Created by wein on 22/08/18.
//

#include <assert.h>

void RunTinyTests();

void test_set_float_using_IEEE()
{
    float a;
    *( unsigned int* )( &a ) = 0x3f800000;
    assert( 1 == a );
}

void test_this()
{
    ;
}

void test_that()
{
    ;
}

int main( int argc, char** argv )
{
    RunTinyTests();
    return 0;
}
