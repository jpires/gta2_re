#pragma once

#include "types.hpp"
#include <vector>

class GlobalRef;

class GlobalsRegistry
{
  public:
    void Add(GlobalRef* pRef);

  public:
    std::vector<GlobalRef*> mGlobals;
};

// Export as plain C function with no name mangling so that
// the HookLoader can easily find and special case it.
extern "C"
{
    __declspec(dllexport) GlobalsRegistry* __cdecl GetGlobalsRegistry();
}

typedef GlobalsRegistry*(__cdecl* TGetGlobalsRegistry)();

class GlobalRef
{
  public:
    GlobalRef(void* pVar, u32 addr);
    const void* mVar;
    const u32 mOgAddr;
};

#define GLOBAL(var, addr) const GlobalRef gRef_##var(&var, addr);