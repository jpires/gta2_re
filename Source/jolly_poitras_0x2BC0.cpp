#include "Function.hpp"
#include "jolly_poitras_0x2BC0.hpp"
#include "error.hpp"
#include "file.hpp"
#include <io.h>

jolly_poitras_0x2BC0* gJolly_poitras_0x2BC0_6FEAC0;

wchar_t word_67DC8C[50];

STUB_FUNC(0x56B6E0)
jolly_poitras_0x2BC0::jolly_poitras_0x2BC0()
{
    // todo
    int* tmp = field_1878;
    int* pIter1 = this->field_1884;
    struc_221* pIter2 = this->field_1800;

    s32 i;
    for (i = 0; i < 3; i++)
    {
      //  ++pIter1;
        memset(pIter2, 0, sizeof(struc_221));
        *pIter1 = 0;
        pIter1++;

        *tmp = 0;
        tmp++;

//        *(pIter1 - 4) = 0;
  //      *(pIter1 - 1) = 0;
        ++pIter2;
    }

    for (i = 0; i < 8; i++)
    {
        if (PlySlotDatExists_56B940(i))
        {
            sub_56B990(i);
        }
        else
        {
            sub_56BA60(i);
        }
    }

    if (HiScoreHscExists_56BCA0())
    {
        sub_56BE50();
    }
    else
    {
        sub_56C1D0();
        sub_56BF20();
    }

    sub_56BD20();
}

STUB_FUNC(0x56B810)
jolly_poitras_0x2BC0::~jolly_poitras_0x2BC0()
{

}

MATCH_FUNC(0x56C2C0)
void jolly_poitras_0x2BC0::create_56C2C0()
{
    if (!gJolly_poitras_0x2BC0_6FEAC0)
    {
        gJolly_poitras_0x2BC0_6FEAC0 = new jolly_poitras_0x2BC0();
        if (!gJolly_poitras_0x2BC0_6FEAC0)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\plydat.cpp", 1269);
        }
    }
}

MATCH_FUNC(0x56C340)
void jolly_poitras_0x2BC0::destroy_56C340()
{
    if (gJolly_poitras_0x2BC0_6FEAC0)
    {
        delete gJolly_poitras_0x2BC0_6FEAC0;
        gJolly_poitras_0x2BC0_6FEAC0 = 0;
    }
}

STUB_FUNC(0x56BB10)
void jolly_poitras_0x2BC0::sub_56BB10(angry_lewin_0x85C *a2)
{
    // todo
}

STUB_FUNC(0x56C010)
void jolly_poitras_0x2BC0::sub_56C010()
{
    // todo
}

MATCH_FUNC(0x56B8A0)
void jolly_poitras_0x2BC0::GetPlySlotDatName_56B8A0(u16 a1, char_type *a2)
{
    char_type Buffer[8];
    _itoa(a1, Buffer, 10);
    strcpy(a2, "player\\plyslot");
    strcat(a2, Buffer);
    strcat(a2, ".dat");
}

MATCH_FUNC(0x56B940)
char_type jolly_poitras_0x2BC0::PlySlotDatExists_56B940(s32 a1)
{
    char_type FileName[356];
    GetPlySlotDatName_56B8A0(a1, FileName);

    _finddata_t findData;
    long hFind = _findfirst(FileName, &findData);
    if (hFind == -1)
    {
        return 0;
    }
    _findclose(hFind);
    return 1;
}

MATCH_FUNC(0x56BCF0)
void jolly_poitras_0x2BC0::GetHiScoreHscFileName_56BCF0(char_type *pName)
{
    strcpy(pName, "player\\hiscores.hsc");
}

MATCH_FUNC(0x56BCA0)
char_type jolly_poitras_0x2BC0::HiScoreHscExists_56BCA0()
{
    char_type FileName[356];
    GetHiScoreHscFileName_56BCF0(FileName);

    _finddata_t findData;
    long hFind = _findfirst(FileName, &findData);
    if (hFind == -1)
    {
        return 0;
    }
    _findclose(hFind);
    return 1;
}

/*
 char_type FileName[356];

    u16 idx = (u16)slotIdx;

    wchar_t* pStr = field_26A0[idx].field_90_str;
    GetPlySlotDatName_56B8A0(idx, FileName);
    File::Global_Open_4A7060(FileName);



    s32 i = 9;
    do
    {
        s32 readLen = 2;
        File::Global_Read_4A71C0(pStr, &readLen);
        pStr++;
        i--;
    } while (i);


    s32 j;
    s32 k;
    for (k = 0; k < 3; k++)
    {
        for (j = 0; j < 4; j++)
        {
            s32 len_read = 1;
            File::Global_Read_4A71C0(&field_26A0[idx].field_0[k][j].field_0, &len_read);

            len_read = 4;
            File::Global_Read_4A71C0(&field_26A0[idx].field_0[k][j].field_4, &len_read);

            len_read = 4;
            File::Global_Read_4A71C0(&field_26A0[idx].field_0[k][j].field_8, &len_read);
        }
    }
    File::Global_Close_4A70C0();
*/

STUB_FUNC(0x56B990)
void jolly_poitras_0x2BC0::sub_56B990(s32 slotIdx)
{

    char_type FileName[356];
    u16 idx = (u16)slotIdx;
  
    wchar_t  * pStr = field_26A0[idx].field_90_str; // todo: This instruction is too early lea     esi, [ebx+2730h]
    GetPlySlotDatName_56B8A0(idx, FileName);
    File::Global_Open_4A7060(FileName);


    s32 i = 9;
    do
    {
        u32 readLen = 2;
        File::Global_Read_4A71C0(pStr, &readLen);
        pStr++;
        i--;
    } while (i);


    s32 j;
    s32 k;
    for (k = 0; k < 3; k++)
    {
        for (j = 0; j < 4; j++)
        {
            u32 len_read = 1;
            File::Global_Read_4A71C0(&field_26A0[idx].field_0[k][j].field_0, &len_read);

            len_read = 4;
            File::Global_Read_4A71C0(&field_26A0[idx].field_0[k][j].field_4, &len_read);

            len_read = 4;
            File::Global_Read_4A71C0(&field_26A0[idx].field_0[k][j].field_8, &len_read);
        }
    }
    File::Global_Close_4A70C0();
}

STUB_FUNC(0x56BA60)
void jolly_poitras_0x2BC0::sub_56BA60(s16 a2)
{
    // todo
}

/*
s32 len;
    s32 k3Counter;
    s32 k4Counter;

    char_type FileName[256];
    GetHiScoreHscFileName_56BCF0(FileName);
    File::Global_Open_4A7060(FileName);

    len = 240;
    File::Global_Read_4A71C0(&field_23D0.field_0, &len);


    for (k3Counter = 0; k3Counter < 3; k3Counter++)
    {
        for (k4Counter = 0; k4Counter < 4; k4Counter++)
        {
            len = 240;
            File::Global_Read_4A71C0(&field_1890[k3Counter][k4Counter].field_0, &len);
        }

        len = 40;
        File::Global_Read_4A71C0(&field_1800[k3Counter], &len); // 3 40 byte objs

        len = 4;
        File::Global_Read_4A71C0(&field_1878[k3Counter], &len);

        len = 4;
        File::Global_Read_4A71C0(&field_1884[k3Counter], &len);
    }

    File::Global_Close_4A70C0();
*/

// wrong stack slots
STUB_FUNC(0x56BE50)
void jolly_poitras_0x2BC0::sub_56BE50()
{
    char_type FileName[256];
    GetHiScoreHscFileName_56BCF0(FileName);
    File::Global_Open_4A7060(FileName);

    u32 len = 240;
    File::Global_Read_4A71C0(&field_23D0.field_0, &len);

    for (s32 k3Counter = 0; k3Counter < 3; k3Counter++)
    {
        for (s32 k4Counter = 0; k4Counter < 4; k4Counter++)
        {
            len = 240;
            File::Global_Read_4A71C0(&field_1890[k3Counter][k4Counter].field_0, &len);
        }

        len = 40;
        File::Global_Read_4A71C0(&field_1800[k3Counter], &len); // 3 40 byte objs

        len = 4;
        File::Global_Read_4A71C0(&field_1878[k3Counter], &len);

        len = 4;
        File::Global_Read_4A71C0(&field_1884[k3Counter], &len);
    }

    File::Global_Close_4A70C0();
}

STUB_FUNC(0x56C1D0)
void jolly_poitras_0x2BC0::sub_56C1D0()
{
    // todo
}

STUB_FUNC(0x56BF20)
void jolly_poitras_0x2BC0::sub_56BF20()
{
    // todo
}

MATCH_FUNC(0x56BD20)
void jolly_poitras_0x2BC0::sub_56BD20()
{
    wcsncpy(this->field_24C0.field_0[0].field_0_str, L"ALAN", 9u);
    this->field_24C0.field_0[0].field_14_score = 1000000;
    wcsncpy(this->field_24C0.field_0[1].field_0_str, L"BRIAN", 9u);
    this->field_24C0.field_0[1].field_14_score = 500000;
    wcsncpy(this->field_24C0.field_0[2].field_0_str, L"COLIN", 9u);
    this->field_24C0.field_0[2].field_14_score = 400000;
    wcsncpy(this->field_24C0.field_0[3].field_0_str, L"DAVE", 9u);
    this->field_24C0.field_0[3].field_14_score = 300000;
    wcsncpy(this->field_24C0.field_0[4].field_0_str, L"ERIC", 9u);
    this->field_24C0.field_0[4].field_14_score = 250000;
    wcsncpy(this->field_24C0.field_0[5].field_0_str, L"FRANK", 9u);
    this->field_24C0.field_0[5].field_14_score = 200000;
    wcsncpy(this->field_24C0.field_0[6].field_0_str, L"GRAEME", 9u);
    this->field_24C0.field_0[6].field_14_score = 100000;
    wcsncpy(this->field_24C0.field_0[7].field_0_str, L"HECTOR", 9u);
    this->field_24C0.field_0[7].field_14_score = 50000;
    wcsncpy(this->field_24C0.field_0[8].field_0_str, L"IMOGEN", 9u);
    this->field_24C0.field_0[8].field_14_score = 25000;
    wcsncpy(this->field_24C0.field_0[9].field_0_str, L"JACKSON", 9u);
    this->field_24C0.field_0[9].field_14_score = 10000;
}

STUB_FUNC(0x56BBD0)
void jolly_poitras_0x2BC0::sub_56BBD0(u8 a2, u8 a3)
{
    // todo
}

STUB_FUNC(0x56B500)
agitated_keldysh_0xF0::agitated_keldysh_0xF0()
{
    Init_56B520();
}

STUB_FUNC(0x56B510)
agitated_keldysh_0xF0::~agitated_keldysh_0xF0()
{

}

MATCH_FUNC(0x56B520)
void agitated_keldysh_0xF0::Init_56B520()
{
    for (s32 i=0; i<10; i++)
    {
        wcscpy(field_0[i].field_0_str, word_67DC8C);
        field_0[i].field_14_score = 0;
    }
}

STUB_FUNC(0x56B550)
char_type agitated_keldysh_0xF0::sub_56B550(const wchar_t *pFindStr, s32 findScore)
{
    u16 startIdx = 10;
    for (s16 i = 9; i != -1; --i)
    {
        if (findScore > field_0[i].field_14_score)
        {
            startIdx = i;
        }

        if (findScore == field_0[i].field_14_score &&
            wcscmp(pFindStr, field_0[i].field_0_str) == 0)
        {
            return 0;
        }
    }

    if (startIdx != 10)
    {

        if (startIdx < 9u)
        {
            // ??????
            small_string* pIter = &field_0[8];// .field_14_score;
          //  int* pIter = &field_0[9 - 1].field_14_score;

            s32 remainderCount = 9 - startIdx;
            do
            {
                wcsncpy((pIter+1)->field_0_str, (pIter)->field_0_str, 9u);
                (pIter+1)->field_14_score = (pIter)->field_14_score;

                pIter--;

                --remainderCount;
            } while (remainderCount);
            //newScore = findScore;
        }

        wcsncpy(field_0[startIdx].field_0_str, pFindStr, 9u);
        field_0[startIdx].field_14_score = findScore;

        return 1;
    }
    return 0;
}

STUB_FUNC(0x56B610)
dreamy_clarke_0xA4::dreamy_clarke_0xA4()
{
    sub_56B630();
}

STUB_FUNC(0x56B620)
dreamy_clarke_0xA4::~dreamy_clarke_0xA4()
{

}

STUB_FUNC(0x56B630)
void dreamy_clarke_0xA4::sub_56B630()
{
    // todo
}
