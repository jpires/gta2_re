#include "Varrok_7F8.hpp"

STUB_FUNC(0x59b060)
u8 Varrok_7F8::sub_59B060(s32 a2)
{
    return 0;
}

STUB_FUNC(0x59b0b0)
char_type* Varrok_7F8::sub_59B0B0(u8 a2)
{
    return 0;
}

STUB_FUNC(0x59b0d0)
char_type Varrok_7F8::sub_59B0D0(u8 idx)
{
    return 0;
}

MATCH_FUNC(0x59b0f0)
Varrok_7F8::Varrok_7F8()
{
    for (s32 i=0; i < GTA2_COUNTOF(field_0); i++)
    {
        field_0[i].field_0 = 0;
        field_0[i].field_4 = 0;
    }
}

STUB_FUNC(0x59b110)
Varrok_7F8::~Varrok_7F8()
{
}
