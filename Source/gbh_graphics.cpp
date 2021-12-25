#include "gbh_graphics.hpp"
#include <stdio.h>

struct STexture;
struct Vert;
struct SLight;
struct SImage;

typedef int(__cdecl *T_gbh_InitDLL)(SVideo*);
typedef int(__cdecl *T_gbh_Init)(int);
typedef int(__cdecl *T_gbh_CloseDLL)();
typedef float(__cdecl *T_gbh_SetWindow)(float left, float top, float right, float bottom);
typedef int*(__cdecl *T_gbh_GetGlobals)(void);
typedef int(__cdecl *T_gbh_DrawTile)(unsigned int flags, STexture* pTexture, Vert* pData, int diffuseColour);
typedef int(__cdecl *T_gbh_DrawTilePart)(unsigned int flags, STexture* pTexture, Vert* pData, int diffuseColour);
typedef int(__cdecl *T_gbh_DrawQuad)(int flags, STexture* pTexture, Vert* pVerts, int baseColour);
typedef int(__cdecl *T_gbh_DrawQuadClipped)(int a1, int a2, int a3, int a4, int a5);
typedef int(__cdecl *T_gbh_DrawFlatRect)(int a1, int a2);
typedef int(__cdecl *T_gbh_DrawTriangle)(int triFlags, STexture* pTexture, Vert* pVerts, int diffuseColour);
typedef int(__cdecl *T_gbh_PrintBitmap)(int a1, int a2);
typedef int(__cdecl *T_gbh_SetColourDepth)(void);
typedef int(__cdecl *T_gbh_Plot)(int a1, int a2, int a3, int a4);
typedef int(__cdecl *T_gbh_ConvertColour)(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3);
typedef int(__cdecl *T_gbh_RegisterTexture)(__int16 width, __int16 height, BYTE* pData, int a4, char a5);
typedef int(__cdecl *T_gbh_SetCamera)(float a1, float a2, float a3, float a4);
typedef int(__cdecl *T_gbh_ResetLights)();
typedef int(__cdecl *T_gbh_AddLight)(SLight* pLight);
typedef int(__cdecl *T_gbh_SetAmbient)(float a1);
typedef int(__cdecl *T_gbh_GetUsedCache)(int a1);
typedef int(__cdecl *T_gbh_FreeTexture)(STexture* pTexture);
typedef int(__cdecl *T_gbh_RegisterPalette)(int palId, BYTE *pData);
typedef int(__cdecl *T_gbh_FreePalette)(int a1);
typedef int(__cdecl *T_gbh_AssignPalette)(STexture* pTexture, int palId);
typedef int(__cdecl *T_gbh_LockTexture)(STexture *);
typedef int(__cdecl *T_gbh_UnlockTexture)(STexture *);
typedef int(__cdecl *T_gbh_BeginScene)();
typedef double(__cdecl *T_gbh_EndScene)();
typedef int(__cdecl *T_gbh_BeginLevel)();
typedef int(__cdecl *T_gbh_EndLevel)();
typedef int(__cdecl *T_MakeScreenTable)(int result, int a2, unsigned int a3);
typedef int(__cdecl *T_ConvertColourBank)(int a1);
typedef int(__cdecl *T_SetShadeTableA)(int a1, int a2, int a3, int a4, int a5);
typedef int(__cdecl *T_gbh_InitImageTable)(int tableSize);
typedef int(__cdecl *T_gbh_FreeImageTable)();
typedef int(__cdecl *T_gbh_LoadImage)(SImage* pImage);
typedef char(__cdecl *T_gbh_BlitImage)(int imageIndex, int srcLeft, int srcTop, int srcRight, int srcBottom, int dstX, int dstY);
typedef int(__cdecl *T_gbh_BlitBuffer)(int a1, int a2, int a3, int a4, int a5, int a6);

T_gbh_InitDLL gbh_InitDLL;
T_gbh_Init gbh_Init;
T_gbh_CloseDLL gbh_CloseDLL;
T_gbh_SetWindow gbh_SetWindow;
T_gbh_GetGlobals gbh_GetGlobals;
T_gbh_DrawTile gbh_DrawTile;
T_gbh_DrawTilePart gbh_DrawTilePart;
T_gbh_DrawQuad gbh_DrawQuad;
T_gbh_DrawQuadClipped gbh_DrawQuadClipped;
T_gbh_DrawFlatRect gbh_DrawFlatRect;
T_gbh_DrawTriangle gbh_DrawTriangle;
T_gbh_PrintBitmap gbh_PrintBitmap;
T_gbh_SetColourDepth gbh_SetColourDepth;
T_gbh_Plot gbh_Plot;
T_gbh_ConvertColour gbh_ConvertColour;
T_gbh_RegisterTexture gbh_RegisterTexture;
T_gbh_SetCamera gbh_SetCamera;
T_gbh_ResetLights gbh_ResetLights;
T_gbh_AddLight gbh_AddLight;
T_gbh_SetAmbient gbh_SetAmbient;
T_gbh_GetUsedCache gbh_GetUsedCache;
T_gbh_FreeTexture gbh_FreeTexture;
T_gbh_RegisterPalette gbh_RegisterPalette;
T_gbh_FreePalette gbh_FreePalette;
T_gbh_AssignPalette gbh_AssignPalette;
T_gbh_LockTexture gbh_LockTexture;
T_gbh_UnlockTexture gbh_UnlockTexture;
T_gbh_BeginScene gbh_BeginScene;
T_gbh_EndScene gbh_EndScene;
T_gbh_BeginLevel gbh_BeginLevel;
T_gbh_EndLevel gbh_EndLevel;
T_MakeScreenTable MakeScreenTable;
T_ConvertColourBank ConvertColourBank;
T_SetShadeTableA SetShadeTableA;
T_gbh_InitImageTable gbh_InitImageTable;
T_gbh_FreeImageTable gbh_FreeImageTable;
T_gbh_LoadImage gbh_LoadImage;
T_gbh_BlitImage gbh_BlitImage;
T_gbh_BlitBuffer gbh_BlitBuffer;

HMODULE gGbhDllHandle_7085D8;
FARPROC DrawLine;
int gGBH_GraphicsLoaded_7085E0;
int* gpGBH_Globals_7085E4;


#define load_gbh_func(varName, varType, funcName)\
    varName = (varType)GetProcAddress(gGbhDllHandle_7085D8, funcName);\
    if (!varName)\
    {\
        sprintf(Text, "Can't Find Function Called %s", funcName);\
        MessageBoxA(0, Text, "Error Patching DLL Function", MB_OK);\
        FreeLibrary(gGbhDllHandle_7085D8);\
        return -1;\
    }


int __stdcall GBH_GraphicsLoadDll_5EA680(const char* lpLibFileName)
{
    CHAR Text[120];

    if (!lpLibFileName)
    {
        return 0;
    }

    gGbhDllHandle_7085D8 = LoadLibraryA(lpLibFileName);
    if (!gGbhDllHandle_7085D8)
    {
        sprintf(Text, "Error can't load DLL file: %s", lpLibFileName);
        MessageBoxA(0, Text, "Error Loading DLL.", MB_OK);
        return -1;
    }

    load_gbh_func(gbh_InitDLL, T_gbh_InitDLL, "gbh_InitDLL");
    load_gbh_func(gbh_CloseDLL, T_gbh_CloseDLL, "gbh_CloseDLL");
    load_gbh_func(gbh_Init, T_gbh_Init, "gbh_Init");
    load_gbh_func(gbh_DrawTile, T_gbh_DrawTile, "gbh_DrawTile");
    load_gbh_func(gbh_DrawTilePart, T_gbh_DrawTilePart, "gbh_DrawTilePart");
    load_gbh_func(gbh_DrawQuad, T_gbh_DrawQuad, "gbh_DrawQuad");
    load_gbh_func(gbh_DrawQuadClipped, T_gbh_DrawQuadClipped, "gbh_DrawQuadClipped");
    load_gbh_func(gbh_DrawTriangle, T_gbh_DrawTriangle, "gbh_DrawTriangle");
    load_gbh_func(gbh_Plot, T_gbh_Plot, "gbh_Plot");
    load_gbh_func(gbh_SetWindow, T_gbh_SetWindow, "gbh_SetWindow");
    load_gbh_func(gbh_PrintBitmap, T_gbh_PrintBitmap, "gbh_PrintBitmap");
    load_gbh_func(gbh_SetColourDepth, T_gbh_SetColourDepth, "gbh_SetColourDepth");
    load_gbh_func(gbh_GetGlobals, T_gbh_GetGlobals, "gbh_GetGlobals");
    load_gbh_func(gbh_ConvertColour, T_gbh_ConvertColour, "gbh_ConvertColour");
    load_gbh_func(gbh_RegisterTexture, T_gbh_RegisterTexture, "gbh_RegisterTexture");
    load_gbh_func(gbh_BeginScene, T_gbh_BeginScene, "gbh_BeginScene");
    load_gbh_func(gbh_EndScene, T_gbh_EndScene, "gbh_EndScene");
    load_gbh_func(gbh_BeginLevel, T_gbh_BeginLevel, "gbh_BeginLevel");
    load_gbh_func(gbh_EndLevel, T_gbh_EndLevel, "gbh_EndLevel");
    load_gbh_func(ConvertColourBank, T_ConvertColourBank, "ConvertColourBank");
    load_gbh_func(DrawLine, FARPROC, "DrawLine");
    load_gbh_func(MakeScreenTable, T_MakeScreenTable, "MakeScreenTable");
    load_gbh_func(SetShadeTableA, T_SetShadeTableA, "SetShadeTableA");
    load_gbh_func(gbh_UnlockTexture, T_gbh_UnlockTexture, "gbh_UnlockTexture");
    load_gbh_func(gbh_RegisterPalette, T_gbh_RegisterPalette, "gbh_RegisterPalette");
    load_gbh_func(gbh_FreePalette, T_gbh_FreePalette, "gbh_FreePalette");
    load_gbh_func(gbh_FreeTexture, T_gbh_FreeTexture, "gbh_FreeTexture");
    load_gbh_func(gbh_AssignPalette, T_gbh_AssignPalette, "gbh_AssignPalette");
    load_gbh_func(gbh_LockTexture, T_gbh_LockTexture, "gbh_LockTexture");
    load_gbh_func(gbh_GetUsedCache, T_gbh_GetUsedCache, "gbh_GetUsedCache");
    load_gbh_func(gbh_SetCamera, T_gbh_SetCamera, "gbh_SetCamera");
    load_gbh_func(gbh_ResetLights, T_gbh_ResetLights, "gbh_ResetLights");
    load_gbh_func(gbh_AddLight, T_gbh_AddLight, "gbh_AddLight");
    load_gbh_func(gbh_SetAmbient, T_gbh_SetAmbient, "gbh_SetAmbient");
    load_gbh_func(gbh_InitImageTable, T_gbh_InitImageTable, "gbh_InitImageTable");
    load_gbh_func(gbh_FreeImageTable, T_gbh_FreeImageTable, "gbh_FreeImageTable");
    load_gbh_func(gbh_LoadImage, T_gbh_LoadImage, "gbh_LoadImage");
    load_gbh_func(gbh_BlitImage, T_gbh_BlitImage, "gbh_BlitImage");
    load_gbh_func(gbh_BlitBuffer, T_gbh_BlitBuffer, "gbh_BlitBuffer");
    load_gbh_func(gbh_DrawFlatRect, T_gbh_DrawFlatRect, "gbh_DrawFlatRect");

    return 0;
}

int __stdcall GBH_GraphicsLoad_5EB680(const char* lpLibFileName, SVideo* pVidSys)
{
    int Dll_5EA680 = GBH_GraphicsLoadDll_5EA680(lpLibFileName);
    if (Dll_5EA680)
    {
        return Dll_5EA680;
    }

    gbh_InitDLL(pVidSys);
    gpGBH_Globals_7085E4 = gbh_GetGlobals();
    
    gGBH_GraphicsLoaded_7085E0 = 1;

    return 0;
}