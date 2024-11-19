#pragma once

#include "Function.hpp"
#include <windows.h>

class Network_20324
{
public:
    EXPORT u16 sub_519960(u8* a1, u16* a2);
    EXPORT static char_type sub_5199B0(u16* a1, char_type* a2);
    EXPORT char_type* GetString_519A00(const char_type* Key);
    EXPORT static void GetString_519A50(wchar_t* Dest, char_type* Source, size_t MaxCount);
    EXPORT Network_20324* ctor_519A90();
    EXPORT Network_20324* vdtor_519B80(Network_20324* lpMem, char_type flags);
    EXPORT void dtor_519BA0();
    EXPORT s32 sub_519BD0(Network_20324* dwInitParam, HINSTANCE hInstance);
    EXPORT INT_PTR DialogFunc(HWND hDlg, UINT message, WPARAM wParam, Network_20324* lParam);
    EXPORT s32 cb_sub_519D30(Network_20324* a1, s32 a2);
    EXPORT void SetDlgHwnd_519E10(HWND a2);
    EXPORT HWND sub_519E20();
    EXPORT LRESULT cb_sub_519E30(Network_20324* a1, wchar_t* Source, s32 a3);
    EXPORT void OnPaint_519FD0(s32 a1);
    EXPORT void OnWmCommand_519FE0(HWND hDlg, s32 a2, s32 a3, s32 a4);
    EXPORT LRESULT OnTimer_51A9D0(HWND hWnd, s32 a2);
    EXPORT char_type sub_51AA90(HWND hWndParent);
    EXPORT s32 sub_51ABF0(s32 a2);
    EXPORT s32 OnInitDialog_51AC60(HWND hWnd, s32 a2, Network_20324* thisPtr);
    EXPORT s32 sub_51ACC0();
    EXPORT LRESULT cb_sub_51ACD0(Network_20324* a1, wchar_t* Source);
    EXPORT s32 cb_sub_51ADE0(Network_20324* a1);
    EXPORT void sub_51AE20(s32 nIDDlgItem);
    EXPORT s32 cb_sub_51AE50(s32 a1, wchar_t* Source);
    EXPORT s32 sub_51AFA0();
    EXPORT LRESULT cb_sub_51B2F0(Network_20324* a1, wchar_t* Source);
    EXPORT s32 sub_51B4F0(s32 a2, const char_type* a3);
    EXPORT void SetPlayerNameText_51B7C0();
    EXPORT void cb_sub_51B7E0(s32 a1, const char_type** a2);
    EXPORT void sub_51B810(const char_type* a2);
    EXPORT s32 sub_51B9C0(s32 a2, char_type* Data);
    EXPORT void sub_51BBC0();
    EXPORT s32 sub_51BBD0();
    EXPORT void sub_51BBE0();
    EXPORT void sub_51BBF0();
    EXPORT static void cb_sub_51BC00(Network_20324* pThis);
    EXPORT void sub_51BC70(s32 a2);
    EXPORT s32 sub_51BC80();
    EXPORT void sub_51BC90();
    EXPORT void sub_51BD40(const wchar_t* pPlayerNameW, const char* pPlayerNameA);
    EXPORT LRESULT sub_51BDD0(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    EXPORT s32 sub_51BEB0(s32 nIDDlgItem, s32 a3);
    EXPORT void sub_51BFA0();
    EXPORT s32 OnWmHScroll_51C630(HWND hWnd, HWND a2, s32 a3, s32 a4);
    EXPORT void sub_51C7F0(s32* a2);
    EXPORT u32 sub_51C830();
    EXPORT char_type* sub_51CA10();
    EXPORT char_type* sub_51CA50();
    EXPORT char_type* sub_51CA90();
    EXPORT s32 sub_51CAD0(const char_type* a1, const char_type* a2);
    EXPORT s32 sub_51CB30(s32 a1, HWND hDlg);
    EXPORT s32 sub_51CBC0();
    EXPORT LRESULT sub_51CCB0(s32 a1, HWND hDlg);
    EXPORT s32 sub_51CD30(s32 a1, HWND hDlg);
    EXPORT s32 sub_51CDC0(s32 a2, s32 a3, HWND hDlg);
    EXPORT s32 sub_51CFC0(const char_type* lParam, HWND hDlg);
    EXPORT s32 sub_51D0C0(s32 a1, s32 a2, HWND hDlg);
    EXPORT s32 sub_51D2F0(s32 a1, HWND hDlg);
    EXPORT s32 sub_51D3B0(s32 a1, HWND hDlg);

    s32 field_0_vTable;
    char_type field_4[100][1304];
    s32 field_1FD64_f4_idx_count;
    s32 field_1FD68;
    s32 field_1FD6C;
    s32 field_1FD70;
    s32 field_1FD74;
    wchar_t field_1FD78_player_name_2[260];
    char_type field_1FF80_player_name[4];
    s32 field_1FF84;
    s32 field_1FF88;
    s32 field_1FF8C;
    s32 field_1FF90;
    s32 field_1FF94;
    s32 field_1FF98;
    s32 field_1FF9C;
    s32 field_1FFA0;
    s32 field_1FFA4;
    s32 field_1FFA8;
    s32 field_1FFAC;
    s32 field_1FFB0;
    s32 field_1FFB4;
    s32 field_1FFB8;
    s32 field_1FFBC;
    s32 field_1FFC0;
    s32 field_1FFC4;
    s32 field_1FFC8;
    s32 field_1FFCC;
    s32 field_1FFD0;
    s32 field_1FFD4;
    s32 field_1FFD8;
    s32 field_1FFDC;
    s32 field_1FFE0;
    s32 field_1FFE4;
    s32 field_1FFE8;
    s32 field_1FFEC;
    s32 field_1FFF0;
    s32 field_1FFF4;
    s32 field_1FFF8;
    s32 field_1FFFC;
    s32 field_20000;
    s32 field_20004;
    s32 field_20008;
    s32 field_2000C;
    s32 field_20010;
    s32 field_20014;
    s32 field_20018;
    s32 field_2001C;
    s32 field_20020;
    s32 field_20024;
    s32 field_20028;
    s32 field_2002C;
    s32 field_20030;
    s32 field_20034;
    s32 field_20038;
    s32 field_2003C;
    s32 field_20040;
    s32 field_20044;
    s32 field_20048;
    s32 field_2004C;
    s32 field_20050;
    s32 field_20054;
    s32 field_20058;
    s32 field_2005C;
    s32 field_20060;
    s32 field_20064;
    s32 field_20068;
    s32 field_2006C;
    s32 field_20070;
    s32 field_20074;
    s32 field_20078;
    s32 field_2007C;
    s32 field_20080;
    s32 field_20084;
    char_type field_20088_map_index[260];
    s32 field_2018C_f4_idx;
    s32 field_20190_game_speed;
    s32 field_20194_f_limit;
    s32 field_20198_game_type;
    s32 field_2019C;
    s32 field_201A0_police;
    s32 field_201A4_game_time_limiot;
    s32 field_201A8;
    s32 field_201AC;
    s32 field_201B0;
    s32 field_201B4;
    s32 field_201B8;
    s32 field_201BC;
    s32 field_201C0;
    s32 field_201C4;
    s32 field_201C8;
    s32 field_201CC;
    s32 field_201D0;
    s32 field_201D4;
    s32 field_201D8;
    s32 field_201DC;
    s32 field_201E0;
    s32 field_201E4;
    s32 field_201E8;
    s32 field_201EC;
    s32 field_201F0;
    s32 field_201F4;
    s32 field_201F8;
    s32 field_201FC;
    s32 field_20200;
    s32 field_20204;
    s32 field_20208;
    s32 field_2020C;
    s32 field_20210;
    s32 field_20214;
    s32 field_20218;
    s32 field_2021C;
    s32 field_20220;
    s32 field_20224;
    s32 field_20228;
    s32 field_2022C;
    s32 field_20230;
    s32 field_20234;
    s32 field_20238;
    s32 field_2023C;
    s32 field_20240;
    s32 field_20244;
    s32 field_20248;
    s32 field_2024C;
    s32 field_20250;
    s32 field_20254;
    s32 field_20258;
    s32 field_2025C;
    s32 field_20260;
    s32 field_20264;
    s32 field_20268;
    s32 field_2026C;
    s32 field_20270;
    s32 field_20274;
    s32 field_20278;
    s32 field_2027C;
    s32 field_20280;
    s32 field_20284;
    s32 field_20288;
    s32 field_2028C;
    s32 field_20290;
    s32 field_20294;
    s32 field_20298;
    s32 field_2029C;
    s32 field_202A0;
    s32 field_202A4;
    s32 field_202A8;
    s32 field_202AC;
    s32 field_202B0;
    s32 field_202B4;
    s32 field_202B8;
    s32 field_202BC;
    s32 field_202C0;
    s32 field_202C4;
    s32 field_202C8;
    s32 field_202CC;
    s32 field_202D0;
    s32 field_202D4;
    s32 field_202D8;
    s32 field_202DC;
    s32 field_202E0;
    s32 field_202E4;
    s32 field_202E8;
    s32 field_202EC;
    s32 field_202F0;
    s32 field_202F4;
    s32 field_202F8;
    s32 field_202FC;
    s32 field_20300;
    s32 field_20304;
    s32 field_20308;
    s32 field_2030C;
    s32 field_20310;
    s32 field_20314;
    s16 field_20318;
    s16 field_2031A;
    HWND field_2031C_dlg_hwnd;
    HINSTANCE field_20320_hInstance;
};
