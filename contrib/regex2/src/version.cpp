// Win32Project2.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "version.h"


#include <windows.h>
#include <shlwapi.h>
#ifdef __cplusplus
extern "C" {
#endif
    __declspec(dllexport) HRESULT DllGetVersion(DLLVERSIONINFO2 *pdvi);
#ifdef __cplusplus
}
#endif

HRESULT DllGetVersion(DLLVERSIONINFO2 *pdvi)
{
    if (!pdvi || (pdvi->info1.cbSize != sizeof(*pdvi)))
        return (E_INVALIDARG);
    pdvi->info1.dwMajorVersion = MAJOR_VERSION;
    pdvi->info1.dwMinorVersion = MINOR_VERSION;
    pdvi->info1.dwBuildNumber = BUILD_NUMBER;
    pdvi->info1.dwPlatformID = DLLVER_PLATFORM_WINDOWS;
    if (pdvi->info1.cbSize == sizeof(DLLVERSIONINFO2))
        pdvi->ullVersion = MAKEDLLVERULL(MAJOR_VERSION, MINOR_VERSION, BUILD_NUMBER, 0);
    return S_OK;
}