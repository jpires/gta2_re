#include "distracted_einstein_0xC.hpp"
#include <windows.h>

// match
void distracted_einstein_0xC::sub_5BEBF0()
{
    field_8 += timeGetTime() - field_4;
}

// match 0x5BEC10
distracted_einstein_0xC::distracted_einstein_0xC()
{
    this->field_0 = 0;
    this->field_8 = 0;
    this->field_4 = 0;
}

// match 0x5BEC20
distracted_einstein_0xC::~distracted_einstein_0xC()
{

}
