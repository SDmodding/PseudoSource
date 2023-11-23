// File Line: 117
// RVA: 0xE9ACB0
__int64 __fastcall NvAPI_Initialize()
{
  HINSTANCE__ *hMod; // [rsp+20h] [rbp-18h] BYREF
  unsigned int GpuHandle; // [rsp+28h] [rbp-10h]

  GpuHandle = GetGpuHandle(&hMod);
  if ( GpuHandle == -14 )
    return 0;
  return GpuHandle;
}

// File Line: 129
// RVA: 0xE9ACE0
void __fastcall updateModulePrivateData(HINSTANCE__ *hMod, _NVAPI_MODULE_ID moduleId)
{
  char *v2; // [rsp+8h] [rbp-20h]

  v2 = (char *)hMod + *((int *)hMod + 15) + 4;
  g_module_privateData[moduleId].checksum = *(_DWORD *)((char *)hMod + *((int *)hMod + 15) + 88);
  g_module_privateData[moduleId].TimeDateStamp = *((_DWORD *)v2 + 1);
}

// File Line: 141
// RVA: 0xE9AD60
char __fastcall NeedtoRefreshFunctionPointer(HINSTANCE__ *hMod, _NVAPI_MODULE_ID moduleId)
{
  __int64 v2; // rcx
  char *v4; // [rsp+8h] [rbp-20h]

  v4 = (char *)hMod + *((int *)hMod + 15) + 4;
  v2 = *((int *)hMod + 15);
  if ( *(_DWORD *)((char *)hMod + v2 + 88) )
  {
    if ( *(_DWORD *)((char *)hMod + v2 + 88) != g_module_privateData[moduleId].checksum )
    {
      g_module_privateData[moduleId].checksum = *(_DWORD *)((char *)hMod + v2 + 88);
      g_module_privateData[moduleId].TimeDateStamp = *((_DWORD *)v4 + 1);
      return 1;
    }
  }
  else if ( *((_DWORD *)v4 + 1) != g_module_privateData[moduleId].TimeDateStamp )
  {
    g_module_privateData[moduleId].checksum = *(_DWORD *)((char *)hMod + v2 + 88);
    g_module_privateData[moduleId].TimeDateStamp = *((_DWORD *)v4 + 1);
    return 1;
  }
  return 0;
}

// File Line: 171
// RVA: 0xE9AE60
__int64 __fastcall Module_InitializeHelper(HMODULE hMod, _NVAPI_MODULE_ID moduleId)
{
  __int64 v3; // rcx
  unsigned int (__fastcall *Interface)(__int64); // [rsp+20h] [rbp-18h]

  if ( moduleId )
  {
    if ( moduleId == NVAPI_MODULE_PEP )
    {
      g_nvapi_lpNvAPI_pepQueryInterface = (void *(__fastcall *)(unsigned int))GetProcAddress(
                                                                                hMod,
                                                                                "nvapi_pepQueryInterface");
      if ( !g_nvapi_lpNvAPI_pepQueryInterface )
      {
        FreeLibrary(g_nvapi_pepHModule);
        return 0xFFFFFFFFi64;
      }
    }
  }
  else
  {
    g_nvapi_lpNvAPI_gpuQueryInterface = (void *(__fastcall *)(unsigned int))GetProcAddress(hMod, "nvapi_QueryInterface");
    if ( !g_nvapi_lpNvAPI_gpuQueryInterface )
      return 0xFFFFFFFFi64;
    Interface = (unsigned int (__fastcall *)(__int64))g_nvapi_lpNvAPI_gpuQueryInterface(0x150E828u);
    if ( !Interface )
    {
      g_nvapi_lpNvAPI_gpuQueryInterface = 0i64;
      return 0xFFFFFFFFi64;
    }
    if ( Interface(v3) )
    {
      g_nvapi_lpNvAPI_gpuQueryInterface = 0i64;
      return 0xFFFFFFFFi64;
    }
    g_nvapi_callStart = (void (__fastcall *)(unsigned int, unsigned __int64 *))g_nvapi_lpNvAPI_gpuQueryInterface(0x33C7358Cu);
    g_nvapi_callReturn = (void (__fastcall *)(unsigned int, unsigned __int64, _NvAPI_Status))g_nvapi_lpNvAPI_gpuQueryInterface(0x593E8644u);
    if ( g_nvapi_callStart && !g_nvapi_callReturn || g_nvapi_callStart && !g_nvapi_callReturn )
    {
      g_nvapi_callStart = 0i64;
      g_nvapi_callReturn = 0i64;
    }
  }
  return 0i64;
}

// File Line: 215
// RVA: 0xE9AFB0
signed __int64 __fastcall GetGpuHandle(HINSTANCE__ **hMod)
{
  int v2; // [rsp+20h] [rbp-18h]
  unsigned int v3; // [rsp+24h] [rbp-14h]

  if ( bAttempted )
    return 4294967294i64;
  v2 = 0;
  while ( g_nvapi_moduleUnloadPending[0] )
  {
    Sleep(0x64u);
    if ( (unsigned int)++v2 >= 0xA )
      return 0xFFFFFFFFi64;
  }
  ++g_module_numApiInUse[0];
  *hMod = GetModuleHandleA("nvapi64.dll");
  if ( !*hMod )
  {
    *hMod = LoadLibraryA("nvapi64.dll");
    if ( !*hMod )
    {
      --g_module_numApiInUse[0];
      bAttempted = 1;
      return 4294967294i64;
    }
    v3 = Module_InitializeHelper(*hMod, NVAPI_MODULE_GPU);
    if ( v3 )
      goto LABEL_12;
LABEL_16:
    g_nvapi_gpuHModule = *hMod;
    updateModulePrivateData(*hMod, NVAPI_MODULE_GPU);
    return 4294967282i64;
  }
  if ( NeedtoRefreshFunctionPointer(*hMod, NVAPI_MODULE_GPU) )
  {
    v3 = Module_InitializeHelper(*hMod, NVAPI_MODULE_GPU);
    if ( v3 )
    {
LABEL_12:
      --g_module_numApiInUse[0];
      FreeLibrary(*hMod);
      return v3;
    }
    goto LABEL_16;
  }
  return 0i64;
}

// File Line: 272
// RVA: 0xE9B170
__int64 __fastcall GetPepHandle(HINSTANCE__ **hMod)
{
  unsigned int v2; // [rsp+20h] [rbp-18h]
  unsigned int v3; // [rsp+20h] [rbp-18h]

  while ( byte_1424BF561 )
    Sleep(0x64u);
  ++dword_1424BF58C;
  *hMod = GetModuleHandleA("nvpowerapi.dll");
  if ( !*hMod )
  {
    *hMod = LoadLibraryA("nvpowerapi.dll");
    if ( !*hMod )
    {
      --dword_1424BF58C;
      return 4294967294i64;
    }
    v2 = Module_InitializeHelper(*hMod, NVAPI_MODULE_PEP);
    if ( v2 )
    {
      --dword_1424BF58C;
      return v2;
    }
    goto LABEL_8;
  }
  if ( !NeedtoRefreshFunctionPointer(*hMod, NVAPI_MODULE_PEP) )
    return 0i64;
  v3 = Module_InitializeHelper(*hMod, NVAPI_MODULE_PEP);
  if ( !v3 )
  {
LABEL_8:
    g_nvapi_pepHModule = *hMod;
    updateModulePrivateData(*hMod, NVAPI_MODULE_PEP);
    return 4294967282i64;
  }
  --dword_1424BF58C;
  return v3;
}

// File Line: 318
// RVA: 0xE9B2E0
__int64 __fastcall NvAPI_Unload()
{
  __int64 v1; // rcx
  unsigned int (__fastcall *Interface)(__int64); // [rsp+20h] [rbp-18h]

  g_nvapi_moduleUnloadPending[0] = 1;
  if ( g_nvapi_gpuHModule && g_nvapi_lpNvAPI_gpuQueryInterface )
  {
    if ( g_module_numApiInUse[0] )
    {
      g_nvapi_moduleUnloadPending[0] = 0;
      return 0xFFFFFFFFi64;
    }
    else
    {
      Interface = (unsigned int (__fastcall *)(__int64))g_nvapi_lpNvAPI_gpuQueryInterface(0xD22BDD7E);
      if ( Interface )
      {
        if ( Interface(v1) )
        {
          g_nvapi_moduleUnloadPending[0] = 0;
          return 0xFFFFFFFFi64;
        }
        else
        {
          g_nvapi_lpNvAPI_gpuQueryInterface = 0i64;
          FreeLibrary(g_nvapi_gpuHModule);
          g_nvapi_gpuHModule = 0i64;
          g_nvapi_callStart = 0i64;
          g_nvapi_callReturn = 0i64;
          g_nvapi_moduleUnloadPending[0] = 0;
          return 0i64;
        }
      }
      else
      {
        g_nvapi_moduleUnloadPending[0] = 0;
        return 4294967293i64;
      }
    }
  }
  else
  {
    g_nvapi_moduleUnloadPending[0] = 0;
    return 4294967292i64;
  }
}

// File Line: 362
// RVA: 0xE9B3C0
__int64 __fastcall NvAPI_Power_Unload()
{
  byte_1424BF561 = 1;
  if ( g_nvapi_pepHModule && g_nvapi_lpNvAPI_pepQueryInterface )
  {
    if ( dword_1424BF58C )
    {
      byte_1424BF561 = 0;
      return 0xFFFFFFFFi64;
    }
    else
    {
      g_nvapi_lpNvAPI_pepQueryInterface = 0i64;
      FreeLibrary(g_nvapi_pepHModule);
      g_nvapi_pepHModule = 0i64;
      byte_1424BF561 = 0;
      return 0i64;
    }
  }
  else
  {
    byte_1424BF561 = 0;
    return 4294967292i64;
  }
}

// File Line: 877
// RVA: 0xE9B450
__int64 __fastcall NvAPI_GetErrorMessage(unsigned int nr, char *szDesc)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp = 0i64;
  if ( !fp && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6C2D048Cu);
  if ( !fp )
    return 4294967293i64;
  v3 = fp;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6C2D048Cu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, char *))v3)(nr, szDesc);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6C2D048Cu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 902
// RVA: 0xE9B580
__int64 __fastcall NvAPI_GetInterfaceVersionString(char *szDesc)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_0 = 0i64;
  if ( !fp_0 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_0 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1053FA5u);
  if ( !fp_0 )
    return 4294967293i64;
  v2 = fp_0;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1053FA5u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(char *))v2)(szDesc);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1053FA5u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 927
// RVA: 0xE9B6A0
__int64 __fastcall NvAPI_GetDisplayDriverVersion(NvDisplayHandle__ *hNvDisplay, NV_DISPLAY_DRIVER_VERSION *pVersion)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_1 = 0i64;
  if ( !fp_1 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_1 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF951A4D1);
  if ( !fp_1 )
    return 4294967293i64;
  v3 = fp_1;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF951A4D1, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_DRIVER_VERSION *))v3)(hNvDisplay, pVersion);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF951A4D1, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 952
// RVA: 0xE9B7D0
__int64 __fastcall NvAPI_SYS_GetDriverAndBranchVersion(unsigned int *pDriverVersion, char *szBuildBranchString)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_2 = 0i64;
  if ( !fp_2 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_2 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2926AAADu);
  if ( !fp_2 )
    return 4294967293i64;
  v3 = fp_2;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2926AAADu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, char *))v3)(pDriverVersion, szBuildBranchString);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2926AAADu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 977
// RVA: 0xE9B900
__int64 __fastcall NvAPI_EnumNvidiaDisplayHandle(unsigned int thisEnum, NvDisplayHandle__ **pNvDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_3 = 0i64;
  if ( !fp_3 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_3 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9ABDD40D);
  if ( !fp_3 )
    return 4294967293i64;
  v3 = fp_3;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9ABDD40D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NvDisplayHandle__ **))v3)(thisEnum, pNvDispHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9ABDD40D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1002
// RVA: 0xE9BA30
__int64 __fastcall NvAPI_EnumNvidiaUnAttachedDisplayHandle(
        unsigned int thisEnum,
        NvUnAttachedDisplayHandle__ **pNvUnAttachedDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_4 = 0i64;
  if ( !fp_4 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_4 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x20DE9260u);
  if ( !fp_4 )
    return 4294967293i64;
  v3 = fp_4;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x20DE9260u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NvUnAttachedDisplayHandle__ **))v3)(
                thisEnum,
                pNvUnAttachedDispHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x20DE9260u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1027
// RVA: 0xE9BB60
__int64 __fastcall NvAPI_EnumPhysicalGPUs(NvPhysicalGpuHandle__ **nvGPUHandle, unsigned int *pGpuCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_5 = 0i64;
  if ( !fp_5 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_5 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE5AC921F);
  if ( !fp_5 )
    return 4294967293i64;
  v3 = fp_5;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE5AC921F, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ **, unsigned int *))v3)(nvGPUHandle, pGpuCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE5AC921F, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1052
// RVA: 0xE9BC90
__int64 __fastcall NvAPI_EnumLogicalGPUs(NvLogicalGpuHandle__ **nvGPUHandle, unsigned int *pGpuCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_6 = 0i64;
  if ( !fp_6 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_6 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x48B3EA59u);
  if ( !fp_6 )
    return 4294967293i64;
  v3 = fp_6;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x48B3EA59u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvLogicalGpuHandle__ **, unsigned int *))v3)(nvGPUHandle, pGpuCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x48B3EA59u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1077
// RVA: 0xE9BDC0
__int64 __fastcall NvAPI_GetPhysicalGPUsFromDisplay(
        NvDisplayHandle__ *hNvDisp,
        NvPhysicalGpuHandle__ **nvGPUHandle,
        unsigned int *pGpuCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_7 = 0i64;
  if ( !fp_7 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_7 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x34EF9506u);
  if ( !fp_7 )
    return 4294967293i64;
  v4 = fp_7;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x34EF9506u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NvPhysicalGpuHandle__ **, unsigned int *))v4)(
                hNvDisp,
                nvGPUHandle,
                pGpuCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x34EF9506u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1102
// RVA: 0xE9BF00
__int64 __fastcall NvAPI_GetPhysicalGPUFromUnAttachedDisplay(
        NvUnAttachedDisplayHandle__ *hNvUnAttachedDisp,
        NvPhysicalGpuHandle__ **pPhysicalGpu)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_8 = 0i64;
  if ( !fp_8 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_8 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5018ED61u);
  if ( !fp_8 )
    return 4294967293i64;
  v3 = fp_8;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5018ED61u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvUnAttachedDisplayHandle__ *, NvPhysicalGpuHandle__ **))v3)(
                hNvUnAttachedDisp,
                pPhysicalGpu);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5018ED61u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1127
// RVA: 0xE9C030
__int64 __fastcall NvAPI_CreateDisplayFromUnAttachedDisplay(
        NvUnAttachedDisplayHandle__ *hNvUnAttachedDisp,
        NvDisplayHandle__ **pNvDisplay)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_9 = 0i64;
  if ( !fp_9 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_9 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63F9799Eu);
  if ( !fp_9 )
    return 4294967293i64;
  v3 = fp_9;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63F9799Eu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvUnAttachedDisplayHandle__ *, NvDisplayHandle__ **))v3)(
                hNvUnAttachedDisp,
                pNvDisplay);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63F9799Eu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1152
// RVA: 0xE9C160
__int64 __fastcall NvAPI_GetLogicalGPUFromDisplay(NvDisplayHandle__ *hNvDisp, NvLogicalGpuHandle__ **pLogicalGPU)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_10 = 0i64;
  if ( !fp_10 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_10 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEE1370CF);
  if ( !fp_10 )
    return 4294967293i64;
  v3 = fp_10;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEE1370CF, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NvLogicalGpuHandle__ **))v3)(hNvDisp, pLogicalGPU);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEE1370CF, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1177
// RVA: 0xE9C290
__int64 __fastcall NvAPI_GetLogicalGPUFromPhysicalGPU(
        NvPhysicalGpuHandle__ *hPhysicalGPU,
        NvLogicalGpuHandle__ **pLogicalGPU)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_11 = 0i64;
  if ( !fp_11 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_11 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xADD604D1);
  if ( !fp_11 )
    return 4294967293i64;
  v3 = fp_11;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xADD604D1, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NvLogicalGpuHandle__ **))v3)(
                hPhysicalGPU,
                pLogicalGPU);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xADD604D1, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1202
// RVA: 0xE9C3C0
__int64 __fastcall NvAPI_GetPhysicalGPUsFromLogicalGPU(
        NvLogicalGpuHandle__ *hLogicalGPU,
        NvPhysicalGpuHandle__ **hPhysicalGPU,
        unsigned int *pGpuCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_12 = 0i64;
  if ( !fp_12 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_12 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAEA3FA32);
  if ( !fp_12 )
    return 4294967293i64;
  v4 = fp_12;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAEA3FA32, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvLogicalGpuHandle__ *, NvPhysicalGpuHandle__ **, unsigned int *))v4)(
                hLogicalGPU,
                hPhysicalGPU,
                pGpuCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAEA3FA32, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1227
// RVA: 0xE9C500
__int64 __fastcall NvAPI_GetAssociatedNvidiaDisplayHandle(const char *szDisplayName, NvDisplayHandle__ **pNvDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_13 = 0i64;
  if ( !fp_13 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_13 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x35C29134u);
  if ( !fp_13 )
    return 4294967293i64;
  v3 = fp_13;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x35C29134u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(const char *, NvDisplayHandle__ **))v3)(szDisplayName, pNvDispHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x35C29134u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1252
// RVA: 0xE9C630
__int64 __fastcall NvAPI_DISP_GetAssociatedUnAttachedNvidiaDisplayHandle(
        const char *szDisplayName,
        NvUnAttachedDisplayHandle__ **pNvUnAttachedDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_14 = 0i64;
  if ( !fp_14 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_14 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA70503B2);
  if ( !fp_14 )
    return 4294967293i64;
  v3 = fp_14;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA70503B2, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(const char *, NvUnAttachedDisplayHandle__ **))v3)(
                szDisplayName,
                pNvUnAttachedDispHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA70503B2, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1277
// RVA: 0xE9C760
__int64 __fastcall NvAPI_GetAssociatedNvidiaDisplayName(NvDisplayHandle__ *NvDispHandle, char *szDisplayName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_15 = 0i64;
  if ( !fp_15 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_15 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22A78B05u);
  if ( !fp_15 )
    return 4294967293i64;
  v3 = fp_15;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22A78B05u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, char *))v3)(NvDispHandle, szDisplayName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22A78B05u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1302
// RVA: 0xE9C890
__int64 __fastcall NvAPI_GetUnAttachedAssociatedDisplayName(
        NvUnAttachedDisplayHandle__ *hNvUnAttachedDisp,
        char *szDisplayName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_16 = 0i64;
  if ( !fp_16 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_16 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4888D790u);
  if ( !fp_16 )
    return 4294967293i64;
  v3 = fp_16;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4888D790u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvUnAttachedDisplayHandle__ *, char *))v3)(hNvUnAttachedDisp, szDisplayName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4888D790u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1327
// RVA: 0xE9C9C0
__int64 __fastcall NvAPI_EnableHWCursor(NvDisplayHandle__ *hNvDisplay)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_17 = 0i64;
  if ( !fp_17 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_17 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2863148Du);
  if ( !fp_17 )
    return 4294967293i64;
  v2 = fp_17;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2863148Du, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *))v2)(hNvDisplay);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2863148Du, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 1352
// RVA: 0xE9CAE0
__int64 __fastcall NvAPI_DisableHWCursor(NvDisplayHandle__ *hNvDisplay)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_18 = 0i64;
  if ( !fp_18 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_18 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAB163097);
  if ( !fp_18 )
    return 4294967293i64;
  v2 = fp_18;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAB163097, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *))v2)(hNvDisplay);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAB163097, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 1377
// RVA: 0xE9CC00
__int64 __fastcall NvAPI_GetVBlankCounter(NvDisplayHandle__ *hNvDisplay, unsigned int *pCounter)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_19 = 0i64;
  if ( !fp_19 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_19 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x67B5DB55u);
  if ( !fp_19 )
    return 4294967293i64;
  v3 = fp_19;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x67B5DB55u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *))v3)(hNvDisplay, pCounter);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x67B5DB55u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1402
// RVA: 0xE9CD30
__int64 __fastcall NvAPI_SetRefreshRateOverride(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputsMask,
        float refreshRate,
        unsigned int bSetDeferred)
{
  __int64 v4; // r8
  __int64 (__fastcall *v6)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v10; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_20 = 0i64;
  if ( !fp_20 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_20 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3092AC32u);
  if ( !fp_20 )
    return 4294967293i64;
  v6 = fp_20;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3092AC32u, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, __int64, _QWORD, __int64 (__fastcall *)()))v6)(
                hNvDisplay,
                outputsMask,
                v4,
                bSetDeferred,
                v6);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3092AC32u, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 1427
// RVA: 0xE9CE70
__int64 __fastcall NvAPI_GetAssociatedDisplayOutputId(NvDisplayHandle__ *hNvDisplay, unsigned int *pOutputId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_21 = 0i64;
  if ( !fp_21 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_21 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD995937E);
  if ( !fp_21 )
    return 4294967293i64;
  v3 = fp_21;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD995937E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *))v3)(hNvDisplay, pOutputId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD995937E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1452
// RVA: 0xE9CFA0
__int64 __fastcall NvAPI_GetDisplayPortInfo(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_PORT_INFO *pInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_22 = 0i64;
  if ( !fp_22 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_22 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC64FF367);
  if ( !fp_22 )
    return 4294967293i64;
  v4 = fp_22;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC64FF367, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_PORT_INFO *))v4)(
                hNvDisplay,
                outputId,
                pInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC64FF367, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1477
// RVA: 0xE9D0D0
__int64 __fastcall NvAPI_SetDisplayPort(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_PORT_CONFIG *pCfg)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_23 = 0i64;
  if ( !fp_23 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_23 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA13E65A);
  if ( !fp_23 )
    return 4294967293i64;
  v4 = fp_23;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA13E65A, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_PORT_CONFIG *))v4)(
                hNvDisplay,
                outputId,
                pCfg);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA13E65A, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1502
// RVA: 0xE9D200
__int64 __fastcall NvAPI_GetHDMISupportInfo(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_HDMI_SUPPORT_INFO *pInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_24 = 0i64;
  if ( !fp_24 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_24 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6AE16EC3u);
  if ( !fp_24 )
    return 4294967293i64;
  v4 = fp_24;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6AE16EC3u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_HDMI_SUPPORT_INFO *))v4)(
                hNvDisplay,
                outputId,
                pInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6AE16EC3u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1527
// RVA: 0xE9D330
__int64 __fastcall NvAPI_DISP_EnumHDMIStereoModes(NV_HDMI_STEREO_MODES_LIST_V1 *pHDMIStereoModes)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_25 = 0i64;
  if ( !fp_25 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_25 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2CCF5D6);
  if ( !fp_25 )
    return 4294967293i64;
  v2 = fp_25;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2CCF5D6, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_HDMI_STEREO_MODES_LIST_V1 *))v2)(pHDMIStereoModes);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2CCF5D6, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 1552
// RVA: 0xE9D450
__int64 __fastcall NvAPI_GetInfoFrame(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int type,
        NV_INFOFRAME *pInfoFrame)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_26 = 0i64;
  if ( !fp_26 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_26 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9734F1Du);
  if ( !fp_26 )
    return 4294967293i64;
  v5 = fp_26;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9734F1Du, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_INFOFRAME *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                outputId,
                type,
                pInfoFrame,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9734F1Du, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 1577
// RVA: 0xE9D590
__int64 __fastcall NvAPI_SetInfoFrame(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int type,
        NV_INFOFRAME *pInfoFrame)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_27 = 0i64;
  if ( !fp_27 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_27 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x69C6F365u);
  if ( !fp_27 )
    return 4294967293i64;
  v5 = fp_27;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x69C6F365u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_INFOFRAME *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                outputId,
                type,
                pInfoFrame,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x69C6F365u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 1602
// RVA: 0xE9D6D0
__int64 __fastcall NvAPI_SetInfoFrameState(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int type,
        _NV_INFOFRAME_STATE *pState)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_28 = 0i64;
  if ( !fp_28 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_28 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x67EFD887u);
  if ( !fp_28 )
    return 4294967293i64;
  v5 = fp_28;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x67EFD887u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, _NV_INFOFRAME_STATE *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                outputId,
                type,
                pState,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x67EFD887u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 1627
// RVA: 0xE9D810
__int64 __fastcall NvAPI_GetInfoFrameState(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int type,
        _NV_INFOFRAME_STATE *pState)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_29 = 0i64;
  if ( !fp_29 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_29 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x41511594u);
  if ( !fp_29 )
    return 4294967293i64;
  v5 = fp_29;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x41511594u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, _NV_INFOFRAME_STATE *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                outputId,
                type,
                pState,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x41511594u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 1652
// RVA: 0xE9D950
__int64 __fastcall NvAPI_Disp_InfoFrameControl(unsigned int displayId, NV_INFOFRAME_DATA *pInfoframeData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_30 = 0i64;
  if ( !fp_30 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_30 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6067AF3Fu);
  if ( !fp_30 )
    return 4294967293i64;
  v3 = fp_30;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6067AF3Fu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NV_INFOFRAME_DATA *))v3)(displayId, pInfoframeData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6067AF3Fu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1677
// RVA: 0xE9DA80
__int64 __fastcall NvAPI_Disp_ColorControl(unsigned int displayId, NV_COLOR_DATA *pColorData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_31 = 0i64;
  if ( !fp_31 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_31 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x92F9D80D);
  if ( !fp_31 )
    return 4294967293i64;
  v3 = fp_31;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x92F9D80D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NV_COLOR_DATA *))v3)(displayId, pColorData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x92F9D80D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1702
// RVA: 0xE9DBB0
__int64 __fastcall NvAPI_DISP_GetVirtualModeData(unsigned int displayId, NV_VIRTUALMODE_DATA *virtualModeData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_32 = 0i64;
  if ( !fp_32 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_32 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3230D69Au);
  if ( !fp_32 )
    return 4294967293i64;
  v3 = fp_32;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3230D69Au, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NV_VIRTUALMODE_DATA *))v3)(displayId, virtualModeData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3230D69Au, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1727
// RVA: 0xE9DCE0
__int64 __fastcall NvAPI_DISP_OverrideDisplayModeList(
        unsigned int displayId,
        unsigned int modeCount,
        _NV_DISPLAY_MODE_INFO *modeList,
        unsigned int enableOutput)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_33 = 0i64;
  if ( !fp_33 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_33 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x291BFF2u);
  if ( !fp_33 )
    return 4294967293i64;
  v5 = fp_33;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x291BFF2u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _NV_DISPLAY_MODE_INFO *, _QWORD, __int64 (__fastcall *)()))v5)(
                displayId,
                modeCount,
                modeList,
                enableOutput,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x291BFF2u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 1752
// RVA: 0xE9DE20
__int64 __fastcall NvAPI_GetDisplayDriverMemoryInfo(
        NvDisplayHandle__ *hNvDisplay,
        NV_DISPLAY_DRIVER_MEMORY_INFO_V2 *pMemoryInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_34 = 0i64;
  if ( !fp_34 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_34 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x774AA982u);
  if ( !fp_34 )
    return 4294967293i64;
  v3 = fp_34;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x774AA982u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_DRIVER_MEMORY_INFO_V2 *))v3)(
                hNvDisplay,
                pMemoryInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x774AA982u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1777
// RVA: 0xE9DF50
__int64 __fastcall NvAPI_GetDriverMemoryInfo(NvDisplayHandle__ *hNvDisplay, NV_DRIVER_MEMORY_INFO *pMemoryInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_35 = 0i64;
  if ( !fp_35 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_35 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2DC95125u);
  if ( !fp_35 )
    return 4294967293i64;
  v3 = fp_35;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2DC95125u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DRIVER_MEMORY_INFO *))v3)(hNvDisplay, pMemoryInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2DC95125u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 1802
// RVA: 0xE9E080
__int64 __fastcall NvAPI_GetDVCInfo(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_DVC_INFO *pDVCInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_36 = 0i64;
  if ( !fp_36 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_36 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4085DE45u);
  if ( !fp_36 )
    return 4294967293i64;
  v4 = fp_36;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4085DE45u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_DVC_INFO *))v4)(
                hNvDisplay,
                outputId,
                pDVCInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4085DE45u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1827
// RVA: 0xE9E1B0
__int64 __fastcall NvAPI_SetDVCLevel(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int level)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_37 = 0i64;
  if ( !fp_37 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_37 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x172409B4u);
  if ( !fp_37 )
    return 4294967293i64;
  v4 = fp_37;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x172409B4u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(hNvDisplay, outputId, level);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x172409B4u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1852
// RVA: 0xE9E2E0
__int64 __fastcall NvAPI_GetDVCInfoEx(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_DVC_INFO_EX *pDVCInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_38 = 0i64;
  if ( !fp_38 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_38 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE45002Du);
  if ( !fp_38 )
    return 4294967293i64;
  v4 = fp_38;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE45002Du, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_DVC_INFO_EX *))v4)(
                hNvDisplay,
                outputId,
                pDVCInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE45002Du, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1877
// RVA: 0xE9E410
__int64 __fastcall NvAPI_SetDVCLevelEx(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_DVC_INFO_EX *pDVCInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_39 = 0i64;
  if ( !fp_39 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_39 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4A82C2B1u);
  if ( !fp_39 )
    return 4294967293i64;
  v4 = fp_39;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4A82C2B1u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_DVC_INFO_EX *))v4)(
                hNvDisplay,
                outputId,
                pDVCInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4A82C2B1u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1902
// RVA: 0xE9E540
__int64 __fastcall NvAPI_GetHUEInfo(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_HUE_INFO *pHUEInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_40 = 0i64;
  if ( !fp_40 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_40 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x95B64341);
  if ( !fp_40 )
    return 4294967293i64;
  v4 = fp_40;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x95B64341, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_HUE_INFO *))v4)(
                hNvDisplay,
                outputId,
                pHUEInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x95B64341, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1927
// RVA: 0xE9E670
__int64 __fastcall NvAPI_SetHUEAngle(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int hueAngle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_41 = 0i64;
  if ( !fp_41 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_41 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5A0F22C);
  if ( !fp_41 )
    return 4294967293i64;
  v4 = fp_41;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5A0F22C, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(hNvDisplay, outputId, hueAngle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5A0F22C, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1952
// RVA: 0xE9E7A0
__int64 __fastcall NvAPI_GetImageSharpeningInfo(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_IMAGE_SHARPENING_INFO *pImageSharpeningInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_42 = 0i64;
  if ( !fp_42 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_42 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9FB063DF);
  if ( !fp_42 )
    return 4294967293i64;
  v4 = fp_42;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9FB063DF, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_IMAGE_SHARPENING_INFO *))v4)(
                hNvDisplay,
                outputId,
                pImageSharpeningInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9FB063DF, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 1977
// RVA: 0xE9E8D0
__int64 __fastcall NvAPI_SetImageSharpeningLevel(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int level)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_43 = 0i64;
  if ( !fp_43 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_43 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3FC9A59Cu);
  if ( !fp_43 )
    return 4294967293i64;
  v4 = fp_43;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3FC9A59Cu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(hNvDisplay, outputId, level);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3FC9A59Cu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2002
// RVA: 0xE9EA00
__int64 __fastcall NvAPI_D3D_GetCurrentSLIState(IUnknown *pDevice, NV_GET_CURRENT_SLI_STATE *pSliState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_44 = 0i64;
  if ( !fp_44 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_44 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4B708B54u);
  if ( !fp_44 )
    return 4294967293i64;
  v3 = fp_44;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4B708B54u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, NV_GET_CURRENT_SLI_STATE *))v3)(pDevice, pSliState);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4B708B54u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2027
// RVA: 0xE9EB30
__int64 __fastcall NvAPI_D3D9_RegisterResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_45 = 0i64;
  if ( !fp_45 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_45 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA064BDFC);
  if ( !fp_45 )
    return 4294967293i64;
  v2 = fp_45;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA064BDFC, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pResource);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA064BDFC, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2052
// RVA: 0xE9EC50
__int64 __fastcall NvAPI_D3D9_UnregisterResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_46 = 0i64;
  if ( !fp_46 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_46 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBB2B17AA);
  if ( !fp_46 )
    return 4294967293i64;
  v2 = fp_46;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBB2B17AA, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pResource);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBB2B17AA, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2077
// RVA: 0xE9ED70
__int64 __fastcall NvAPI_D3D9_AliasSurfaceAsTexture(
        unsigned int *pDev,
        unsigned int *pSurface,
        unsigned int **ppTexture,
        unsigned int dwFlag)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_47 = 0i64;
  if ( !fp_47 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_47 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE5CEAE41);
  if ( !fp_47 )
    return 4294967293i64;
  v5 = fp_47;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE5CEAE41, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int **, _QWORD, __int64 (__fastcall *)()))v5)(
                pDev,
                pSurface,
                ppTexture,
                dwFlag,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE5CEAE41, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 2102
// RVA: 0xE9EEB0
__int64 __fastcall NvAPI_D3D9_StretchRectEx(
        unsigned int *pDevice,
        unsigned int *pSourceResource,
        tagRECT *pSourceRect,
        unsigned int *pDestResource,
        tagRECT *pDestRect,
        unsigned int Filter)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_48 = 0i64;
  if ( !fp_48 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_48 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22DE03AAu);
  if ( !fp_48 )
    return 4294967293i64;
  v7 = fp_48;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22DE03AAu, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, tagRECT *, unsigned int *, tagRECT *, unsigned int, __int64 (__fastcall *)()))v7)(
                pDevice,
                pSourceResource,
                pSourceRect,
                pDestResource,
                pDestRect,
                Filter,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22DE03AAu, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 2127
// RVA: 0xE9F010
__int64 __fastcall NvAPI_D3D9_ClearRT(unsigned int *pDevice, unsigned int dwNumRects, tagRECT *pRects, float r)
{
  __int64 (__fastcall *v5)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+50h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+58h] [rbp-10h]
  int v9; // [rsp+5Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_49 = 0i64;
  if ( !fp_49 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_49 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x332D3942u);
  if ( !fp_49 )
    return 4294967293i64;
  v5 = fp_49;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x332D3942u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, tagRECT *))v5)(pDevice, dwNumRects, pRects);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x332D3942u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 2152
// RVA: 0xE9F180
__int64 __fastcall NvAPI_D3D_CreateQuery(IUnknown *pDeviceOrContext, unsigned int type, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_50 = 0i64;
  if ( !fp_50 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_50 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5D19BCA4u);
  if ( !fp_50 )
    return 4294967293i64;
  v4 = fp_50;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5D19BCA4u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, _QWORD, NVDX_ObjectHandle__ **))v4)(
                pDeviceOrContext,
                type,
                pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5D19BCA4u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2177
// RVA: 0xE9F2B0
__int64 __fastcall NvAPI_D3D_DestroyQuery(NVDX_ObjectHandle__ *queryHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_51 = 0i64;
  if ( !fp_51 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_51 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC8FF7258);
  if ( !fp_51 )
    return 4294967293i64;
  v2 = fp_51;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC8FF7258, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *))v2)(queryHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC8FF7258, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2202
// RVA: 0xE9F3D0
__int64 __fastcall NvAPI_D3D_Query_Begin(NVDX_ObjectHandle__ *queryHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_52 = 0i64;
  if ( !fp_52 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_52 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE5A9AAE0);
  if ( !fp_52 )
    return 4294967293i64;
  v2 = fp_52;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE5A9AAE0, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *))v2)(queryHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE5A9AAE0, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2227
// RVA: 0xE9F4F0
__int64 __fastcall NvAPI_D3D_Query_End(NVDX_ObjectHandle__ *queryHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_53 = 0i64;
  if ( !fp_53 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_53 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2AC084FAu);
  if ( !fp_53 )
    return 4294967293i64;
  v2 = fp_53;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2AC084FAu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *))v2)(queryHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2AC084FAu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2252
// RVA: 0xE9F610
__int64 __fastcall NvAPI_D3D_Query_GetData(
        NVDX_ObjectHandle__ *queryHandle,
        void *pData,
        unsigned int dwSize,
        unsigned int dwGetDataFlags)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_54 = 0i64;
  if ( !fp_54 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_54 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF8B53C69);
  if ( !fp_54 )
    return 4294967293i64;
  v5 = fp_54;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF8B53C69, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *, void *, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                queryHandle,
                pData,
                dwSize,
                dwGetDataFlags,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF8B53C69, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 2277
// RVA: 0xE9F750
__int64 __fastcall NvAPI_D3D_Query_GetDataSize(NVDX_ObjectHandle__ *queryHandle, unsigned int *pDwSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_55 = 0i64;
  if ( !fp_55 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_55 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF2A54796);
  if ( !fp_55 )
    return 4294967293i64;
  v3 = fp_55;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF2A54796, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *, unsigned int *))v3)(queryHandle, pDwSize);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF2A54796, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2302
// RVA: 0xE9F880
__int64 __fastcall NvAPI_D3D_Query_GetType(NVDX_ObjectHandle__ *queryHandle, _NVAPI_D3D_QUERY_TYPE *pType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_56 = 0i64;
  if ( !fp_56 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_56 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4ACEEAF7u);
  if ( !fp_56 )
    return 4294967293i64;
  v3 = fp_56;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4ACEEAF7u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *, _NVAPI_D3D_QUERY_TYPE *))v3)(queryHandle, pType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4ACEEAF7u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2327
// RVA: 0xE9F9B0
__int64 __fastcall NvAPI_D3D_RegisterApp(IUnknown *pDev, unsigned int userAppId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_57 = 0i64;
  if ( !fp_57 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_57 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD44D3C4E);
  if ( !fp_57 )
    return 4294967293i64;
  v3 = fp_57;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD44D3C4E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, _QWORD))v3)(pDev, userAppId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD44D3C4E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2352
// RVA: 0xE9FAE0
__int64 __fastcall NvAPI_D3D9_CreatePathContextNV(unsigned int *pDevice, unsigned int *context)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_58 = 0i64;
  if ( !fp_58 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_58 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA342F682);
  if ( !fp_58 )
    return 4294967293i64;
  v3 = fp_58;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA342F682, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *))v3)(pDevice, context);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA342F682, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2377
// RVA: 0xE9FC10
__int64 __fastcall NvAPI_D3D9_DestroyPathContextNV(unsigned int context)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_59 = 0i64;
  if ( !fp_59 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_59 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x667C2929u);
  if ( !fp_59 )
    return 4294967293i64;
  v2 = fp_59;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x667C2929u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(context);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x667C2929u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2402
// RVA: 0xE9FD30
__int64 __fastcall NvAPI_D3D9_CreatePathNV(
        unsigned int context,
        unsigned int datatype,
        unsigned int numCommands,
        const char *commands,
        unsigned int *path)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_60 = 0i64;
  if ( !fp_60 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_60 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x71329DF3u);
  if ( !fp_60 )
    return 4294967293i64;
  v6 = fp_60;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x71329DF3u, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD, const char *, unsigned int *))v6)(
                context,
                datatype,
                numCommands,
                commands,
                path);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x71329DF3u, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 2427
// RVA: 0xE9FE80
__int64 __fastcall NvAPI_D3D9_DeletePathNV(unsigned int path)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_61 = 0i64;
  if ( !fp_61 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_61 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x73E0019Au);
  if ( !fp_61 )
    return 4294967293i64;
  v2 = fp_61;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x73E0019Au, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(path);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x73E0019Au, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 2452
// RVA: 0xE9FFA0
__int64 __fastcall NvAPI_D3D9_PathVerticesNV(unsigned int path, const void *vertices)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_62 = 0i64;
  if ( !fp_62 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_62 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC23DF926);
  if ( !fp_62 )
    return 4294967293i64;
  v3 = fp_62;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC23DF926, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, const void *))v3)(path, vertices);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC23DF926, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2477
// RVA: 0xEA00D0
__int64 __fastcall NvAPI_D3D9_PathParameterfNV(unsigned int path, unsigned int paramType, float param)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_63 = 0i64;
  if ( !fp_63 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_63 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF7FF00C1);
  if ( !fp_63 )
    return 4294967293i64;
  v4 = fp_63;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF7FF00C1, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD))v4)(path, paramType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF7FF00C1, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2502
// RVA: 0xEA0200
__int64 __fastcall NvAPI_D3D9_PathParameteriNV(unsigned int path, unsigned int paramType, unsigned int param)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_64 = 0i64;
  if ( !fp_64 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_64 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFC31236C);
  if ( !fp_64 )
    return 4294967293i64;
  v4 = fp_64;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFC31236C, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD))v4)(path, paramType, param);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFC31236C, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2527
// RVA: 0xEA0330
__int64 __fastcall NvAPI_D3D9_PathMatrixNV(unsigned int context, unsigned int paramType, const float *value)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_65 = 0i64;
  if ( !fp_65 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_65 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2F6C499);
  if ( !fp_65 )
    return 4294967293i64;
  v4 = fp_65;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2F6C499, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, const float *))v4)(context, paramType, value);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2F6C499, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2552
// RVA: 0xEA0460
__int64 __fastcall NvAPI_D3D9_PathDepthNV(unsigned int context, float value)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_66 = 0i64;
  if ( !fp_66 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_66 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFCB16330);
  if ( !fp_66 )
    return 4294967293i64;
  v3 = fp_66;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFCB16330, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v3)(context);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFCB16330, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2577
// RVA: 0xEA0590
__int64 __fastcall NvAPI_D3D9_PathClearDepthNV(unsigned int context, float value)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_67 = 0i64;
  if ( !fp_67 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_67 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x157E45C4u);
  if ( !fp_67 )
    return 4294967293i64;
  v3 = fp_67;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x157E45C4u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v3)(context);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x157E45C4u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2602
// RVA: 0xEA06C0
__int64 __fastcall NvAPI_D3D9_PathEnableDepthTestNV(unsigned int context, bool enable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_68 = 0i64;
  if ( !fp_68 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_68 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE99BA7F3);
  if ( !fp_68 )
    return 4294967293i64;
  v3 = fp_68;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE99BA7F3, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, bool))v3)(context, enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE99BA7F3, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2627
// RVA: 0xEA07F0
__int64 __fastcall NvAPI_D3D9_PathEnableColorWriteNV(unsigned int context, bool enable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_69 = 0i64;
  if ( !fp_69 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_69 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3E2804A2u);
  if ( !fp_69 )
    return 4294967293i64;
  v3 = fp_69;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3E2804A2u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, bool))v3)(context, enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3E2804A2u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2652
// RVA: 0xEA0920
__int64 __fastcall NvAPI_D3D9_DrawPathNV(unsigned int path, unsigned int mode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_70 = 0i64;
  if ( !fp_70 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_70 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x13199B3Du);
  if ( !fp_70 )
    return 4294967293i64;
  v3 = fp_70;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x13199B3Du, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD))v3)(path, mode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x13199B3Du, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2677
// RVA: 0xEA0A50
__int64 __fastcall NvAPI_D3D9_GetSurfaceHandle(unsigned int *pSurface, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_71 = 0i64;
  if ( !fp_71 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_71 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF2DD3F2u);
  if ( !fp_71 )
    return 4294967293i64;
  v3 = fp_71;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF2DD3F2u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(pSurface, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF2DD3F2u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2702
// RVA: 0xEA0B80
__int64 __fastcall NvAPI_D3D9_GetOverlaySurfaceHandles(unsigned int *pDev, _NV_OVLY_SURFS_INFO *pInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_72 = 0i64;
  if ( !fp_72 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_72 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6800F5FCu);
  if ( !fp_72 )
    return 4294967293i64;
  v3 = fp_72;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6800F5FCu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NV_OVLY_SURFS_INFO *))v3)(pDev, pInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6800F5FCu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2727
// RVA: 0xEA0CB0
__int64 __fastcall NvAPI_D3D9_GetTextureHandle(unsigned int *pTexture, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_73 = 0i64;
  if ( !fp_73 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_73 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC7985ED5);
  if ( !fp_73 )
    return 4294967293i64;
  v3 = fp_73;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC7985ED5, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(pTexture, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC7985ED5, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2752
// RVA: 0xEA0DE0
__int64 __fastcall NvAPI_D3D9_GpuSyncGetHandleSize(
        unsigned int *pDev,
        unsigned int *pInitHandleSize,
        unsigned int *pMapHandleSize)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_74 = 0i64;
  if ( !fp_74 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_74 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x80C9FD3B);
  if ( !fp_74 )
    return 4294967293i64;
  v4 = fp_74;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x80C9FD3B, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *))v4)(
                pDev,
                pInitHandleSize,
                pMapHandleSize);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x80C9FD3B, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2777
// RVA: 0xEA0F20
__int64 __fastcall NvAPI_D3D9_GpuSyncInit(unsigned int *pDev, void *syncInitData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_75 = 0i64;
  if ( !fp_75 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_75 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6D6FDAD4u);
  if ( !fp_75 )
    return 4294967293i64;
  v3 = fp_75;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6D6FDAD4u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(pDev, syncInitData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6D6FDAD4u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2802
// RVA: 0xEA1050
__int64 __fastcall NvAPI_D3D9_GpuSyncEnd(unsigned int *pDev, void *syncData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_76 = 0i64;
  if ( !fp_76 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_76 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x754033F0u);
  if ( !fp_76 )
    return 4294967293i64;
  v3 = fp_76;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x754033F0u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(pDev, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x754033F0u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2827
// RVA: 0xEA1180
__int64 __fastcall NvAPI_D3D9_GpuSyncMapTexBuffer(unsigned int *pDev, unsigned int *pTexture, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_77 = 0i64;
  if ( !fp_77 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_77 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDE4A28A);
  if ( !fp_77 )
    return 4294967293i64;
  v4 = fp_77;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDE4A28A, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(pDev, pTexture, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDE4A28A, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2852
// RVA: 0xEA12C0
__int64 __fastcall NvAPI_D3D9_GpuSyncMapSurfaceBuffer(unsigned int *pDev, unsigned int *pSurface, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_78 = 0i64;
  if ( !fp_78 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_78 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2AB714ABu);
  if ( !fp_78 )
    return 4294967293i64;
  v4 = fp_78;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2AB714ABu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(pDev, pSurface, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2AB714ABu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2877
// RVA: 0xEA1400
__int64 __fastcall NvAPI_D3D9_GpuSyncMapVertexBuffer(unsigned int *pDev, unsigned int *pVertexBuffer, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_79 = 0i64;
  if ( !fp_79 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_79 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDBC803EC);
  if ( !fp_79 )
    return 4294967293i64;
  v4 = fp_79;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDBC803EC, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(pDev, pVertexBuffer, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDBC803EC, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2902
// RVA: 0xEA1540
__int64 __fastcall NvAPI_D3D9_GpuSyncMapIndexBuffer(unsigned int *pDev, unsigned int *pIndexBuffer, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_80 = 0i64;
  if ( !fp_80 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_80 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x12EE68F2u);
  if ( !fp_80 )
    return 4294967293i64;
  v4 = fp_80;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x12EE68F2u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(pDev, pIndexBuffer, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x12EE68F2u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 2927
// RVA: 0xEA1680
__int64 __fastcall NvAPI_D3D9_SetPitchSurfaceCreation(unsigned int *pDev, unsigned int Signature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_81 = 0i64;
  if ( !fp_81 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_81 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x18CDF365u);
  if ( !fp_81 )
    return 4294967293i64;
  v3 = fp_81;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x18CDF365u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v3)(pDev, Signature);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x18CDF365u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2952
// RVA: 0xEA17B0
__int64 __fastcall NvAPI_D3D9_GpuSyncAcquire(unsigned int *pDev, void *syncData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_82 = 0i64;
  if ( !fp_82 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_82 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD00B8317);
  if ( !fp_82 )
    return 4294967293i64;
  v3 = fp_82;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD00B8317, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(pDev, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD00B8317, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 2977
// RVA: 0xEA18E0
__int64 __fastcall NvAPI_D3D9_GpuSyncRelease(unsigned int *pDev, void *syncData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_83 = 0i64;
  if ( !fp_83 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_83 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3D7A86BBu);
  if ( !fp_83 )
    return 4294967293i64;
  v3 = fp_83;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3D7A86BBu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(pDev, syncData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3D7A86BBu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3002
// RVA: 0xEA1A10
__int64 __fastcall NvAPI_D3D9_GetCurrentRenderTargetHandle(unsigned int *pDev, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_84 = 0i64;
  if ( !fp_84 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_84 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22CAD61u);
  if ( !fp_84 )
    return 4294967293i64;
  v3 = fp_84;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22CAD61u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(pDev, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22CAD61u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3027
// RVA: 0xEA1B40
__int64 __fastcall NvAPI_D3D9_GetCurrentZBufferHandle(unsigned int *pDev, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_85 = 0i64;
  if ( !fp_85 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_85 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB380F218);
  if ( !fp_85 )
    return 4294967293i64;
  v3 = fp_85;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB380F218, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(pDev, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB380F218, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3052
// RVA: 0xEA1C70
__int64 __fastcall NvAPI_D3D9_GetIndexBufferHandle(unsigned int *pIndexBuffer, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_86 = 0i64;
  if ( !fp_86 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_86 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFC5A155B);
  if ( !fp_86 )
    return 4294967293i64;
  v3 = fp_86;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFC5A155B, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(pIndexBuffer, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFC5A155B, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3077
// RVA: 0xEA1DA0
__int64 __fastcall NvAPI_D3D9_GetVertexBufferHandle(unsigned int *pVertexBuffer, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_87 = 0i64;
  if ( !fp_87 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_87 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x72B19155u);
  if ( !fp_87 )
    return 4294967293i64;
  v3 = fp_87;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x72B19155u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(pVertexBuffer, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x72B19155u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3102
// RVA: 0xEA1ED0
__int64 __fastcall NvAPI_D3D9_CreateTexture(
        unsigned int *pDev,
        unsigned int Width,
        unsigned int Height,
        unsigned int Level,
        unsigned int Flags,
        unsigned int Format,
        unsigned int **ppTexture,
        NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v9)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h] BYREF
  unsigned __int64 v11; // [rsp+50h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+58h] [rbp-10h]
  int v13; // [rsp+5Ch] [rbp-Ch]

  hMod = 0i64;
  v13 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_88 = 0i64;
  if ( !fp_88 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_88 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD5E13573);
  if ( !fp_88 )
    return 4294967293i64;
  v9 = fp_88;
  v11 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD5E13573, &v11);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD, unsigned int, unsigned int, unsigned int **, NVDX_ObjectHandle__ **, __int64 (__fastcall *)()))v9)(
                pDev,
                Width,
                Height,
                Level,
                Flags,
                Format,
                ppTexture,
                pHandle,
                v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD5E13573, v11, GpuHandle);
  --g_module_numApiInUse[v13];
  return (unsigned int)GpuHandle;
}

// File Line: 3127
// RVA: 0xEA2040
__int64 __fastcall NvAPI_D3D9_AliasPrimaryAsTexture(
        unsigned int *pDev,
        unsigned int dwIndex,
        unsigned int **ppTexture,
        NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_89 = 0i64;
  if ( !fp_89 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_89 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x13C7112Eu);
  if ( !fp_89 )
    return 4294967293i64;
  v5 = fp_89;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x13C7112Eu, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, unsigned int **, NVDX_ObjectHandle__ **, __int64 (__fastcall *)()))v5)(
                pDev,
                dwIndex,
                ppTexture,
                pHandle,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x13C7112Eu, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 3152
// RVA: 0xEA2180
__int64 __fastcall NvAPI_D3D9_PresentSurfaceToDesktop(
        unsigned int *pDev,
        NVDX_ObjectHandle__ *surfaceHandle,
        unsigned int dwFlipFlags,
        unsigned int dwExcludeDevices)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_90 = 0i64;
  if ( !fp_90 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_90 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF7029C5u);
  if ( !fp_90 )
    return 4294967293i64;
  v5 = fp_90;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF7029C5u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                pDev,
                surfaceHandle,
                dwFlipFlags,
                dwExcludeDevices,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF7029C5u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 3177
// RVA: 0xEA22C0
__int64 __fastcall NvAPI_D3D9_CreateVideoBegin(unsigned int *pDev)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_91 = 0i64;
  if ( !fp_91 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_91 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x84C9D553);
  if ( !fp_91 )
    return 4294967293i64;
  v2 = fp_91;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x84C9D553, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pDev);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x84C9D553, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 3202
// RVA: 0xEA23E0
__int64 __fastcall NvAPI_D3D9_CreateVideoEnd(unsigned int *pDev)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_92 = 0i64;
  if ( !fp_92 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_92 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB476BF61);
  if ( !fp_92 )
    return 4294967293i64;
  v2 = fp_92;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB476BF61, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pDev);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB476BF61, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 3227
// RVA: 0xEA2500
__int64 __fastcall NvAPI_D3D9_CreateVideo(unsigned int *pDev, NV_DX_CREATE_VIDEO_PARAMS2 *pCVParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_93 = 0i64;
  if ( !fp_93 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_93 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x89FFD9A3);
  if ( !fp_93 )
    return 4294967293i64;
  v3 = fp_93;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x89FFD9A3, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NV_DX_CREATE_VIDEO_PARAMS2 *))v3)(pDev, pCVParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x89FFD9A3, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3252
// RVA: 0xEA2630
__int64 __fastcall NvAPI_D3D9_FreeVideo(unsigned int *pDev)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_94 = 0i64;
  if ( !fp_94 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_94 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3111BED1u);
  if ( !fp_94 )
    return 4294967293i64;
  v2 = fp_94;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3111BED1u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pDev);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3111BED1u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 3277
// RVA: 0xEA2750
__int64 __fastcall NvAPI_D3D9_PresentVideo(unsigned int *pDev, NV_DX_PRESENT_VIDEO_PARAMS1 *pPVParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_95 = 0i64;
  if ( !fp_95 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_95 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5CF7F862u);
  if ( !fp_95 )
    return 4294967293i64;
  v3 = fp_95;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5CF7F862u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NV_DX_PRESENT_VIDEO_PARAMS1 *))v3)(pDev, pPVParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5CF7F862u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3302
// RVA: 0xEA2880
__int64 __fastcall NvAPI_D3D9_VideoSetStereoInfo(unsigned int *pDev, _NV_DX_VIDEO_STEREO_INFO *pStereoInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_96 = 0i64;
  if ( !fp_96 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_96 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB852F4DB);
  if ( !fp_96 )
    return 4294967293i64;
  v3 = fp_96;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB852F4DB, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NV_DX_VIDEO_STEREO_INFO *))v3)(pDev, pStereoInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB852F4DB, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3327
// RVA: 0xEA29B0
__int64 __fastcall NvAPI_D3D9_SetGamutData(
        unsigned int *pDev,
        unsigned int outputId,
        unsigned int format,
        _NV_GAMUT_METADATA *pGamutData)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_97 = 0i64;
  if ( !fp_97 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_97 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2BBDA32Eu);
  if ( !fp_97 )
    return 4294967293i64;
  v5 = fp_97;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2BBDA32Eu, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _NV_GAMUT_METADATA *, __int64 (__fastcall *)()))v5)(
                pDev,
                outputId,
                format,
                pGamutData,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2BBDA32Eu, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 3352
// RVA: 0xEA2AF0
__int64 __fastcall NvAPI_D3D9_SetSurfaceCreationLayout(
        unsigned int *pDev,
        _NVAPI_SURFACE_LAYOUT_STRUCT *pSurfaceLayout)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_98 = 0i64;
  if ( !fp_98 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_98 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5609B86Au);
  if ( !fp_98 )
    return 4294967293i64;
  v3 = fp_98;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5609B86Au, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_SURFACE_LAYOUT_STRUCT *))v3)(pDev, pSurfaceLayout);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5609B86Au, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3377
// RVA: 0xEA2C20
__int64 __fastcall NvAPI_D3D9_GetVideoCapabilities(unsigned int *pDev, _NV_DX_VIDEO_CAPS *pVideoCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_99 = 0i64;
  if ( !fp_99 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_99 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3D596B93u);
  if ( !fp_99 )
    return 4294967293i64;
  v3 = fp_99;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3D596B93u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NV_DX_VIDEO_CAPS *))v3)(pDev, pVideoCaps);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3D596B93u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3402
// RVA: 0xEA2D50
__int64 __fastcall NvAPI_D3D9_QueryVideoInfo(unsigned int *pDev, _NVAPI_DX_QUERY_VIDEO_INFO *pQueryInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_100 = 0i64;
  if ( !fp_100 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_100 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1E6634B3u);
  if ( !fp_100 )
    return 4294967293i64;
  v3 = fp_100;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1E6634B3u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_DX_QUERY_VIDEO_INFO *))v3)(pDev, pQueryInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1E6634B3u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3427
// RVA: 0xEA2E80
__int64 __fastcall NvAPI_D3D9_AliasPrimaryFromDevice(
        unsigned int *pDevTo,
        unsigned int *pDevFrom,
        unsigned int dwIndex,
        unsigned int **ppSurf,
        NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_101 = 0i64;
  if ( !fp_101 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_101 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7C20C5BEu);
  if ( !fp_101 )
    return 4294967293i64;
  v6 = fp_101;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7C20C5BEu, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, _QWORD, unsigned int **, NVDX_ObjectHandle__ **))v6)(
                pDevTo,
                pDevFrom,
                dwIndex,
                ppSurf,
                pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7C20C5BEu, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 3452
// RVA: 0xEA2FD0
__int64 __fastcall NvAPI_D3D9_SetResourceHint(
        unsigned int *pDev,
        NVDX_ObjectHandle__ *obj,
        unsigned int dwHintCategory,
        unsigned int dwHintName,
        unsigned int *pdwHintValue)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_102 = 0i64;
  if ( !fp_102 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_102 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x905F5C27);
  if ( !fp_102 )
    return 4294967293i64;
  v6 = fp_102;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x905F5C27, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, _QWORD, _QWORD, unsigned int *))v6)(
                pDev,
                obj,
                dwHintCategory,
                dwHintName,
                pdwHintValue);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x905F5C27, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 3477
// RVA: 0xEA3120
__int64 __fastcall NvAPI_D3D9_Lock(
        unsigned int *pDev,
        NVDX_ObjectHandle__ *obj,
        unsigned int dwLockFlags,
        void **ppAddress,
        unsigned int *pPitch)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_103 = 0i64;
  if ( !fp_103 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_103 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6317345Cu);
  if ( !fp_103 )
    return 4294967293i64;
  v6 = fp_103;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6317345Cu, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, _QWORD, void **, unsigned int *))v6)(
                pDev,
                obj,
                dwLockFlags,
                ppAddress,
                pPitch);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6317345Cu, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 3502
// RVA: 0xEA3270
__int64 __fastcall NvAPI_D3D9_Unlock(unsigned int *pDev, NVDX_ObjectHandle__ *obj)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_104 = 0i64;
  if ( !fp_104 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_104 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC182027E);
  if ( !fp_104 )
    return 4294967293i64;
  v3 = fp_104;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC182027E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *))v3)(pDev, obj);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC182027E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3527
// RVA: 0xEA33A0
__int64 __fastcall NvAPI_D3D9_GetVideoState(unsigned int *pDev, _NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_105 = 0i64;
  if ( !fp_105 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_105 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA4527BF8);
  if ( !fp_105 )
    return 4294967293i64;
  v3 = fp_105;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA4527BF8, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_GET_VIDEO_STATE_COMPONENT *))v3)(
                pDev,
                pGetVidStateComp);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA4527BF8, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3552
// RVA: 0xEA34D0
__int64 __fastcall NvAPI_D3D9_SetVideoState(unsigned int *pDev, _NVAPI_SET_VIDEO_STATE_COMPONENT *pSetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_106 = 0i64;
  if ( !fp_106 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_106 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBD4BC56F);
  if ( !fp_106 )
    return 4294967293i64;
  v3 = fp_106;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBD4BC56F, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_SET_VIDEO_STATE_COMPONENT *))v3)(
                pDev,
                pSetVidStateComp);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBD4BC56F, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3577
// RVA: 0xEA3600
__int64 __fastcall NvAPI_D3D9_EnumVideoFeatures(
        unsigned int *pDev,
        _NVAPI_DX_VIDEO_FEATURE_DETAILS *pVideoFeatureDetails)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_107 = 0i64;
  if ( !fp_107 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_107 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1DB7C52Cu);
  if ( !fp_107 )
    return 4294967293i64;
  v3 = fp_107;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1DB7C52Cu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_DX_VIDEO_FEATURE_DETAILS *))v3)(
                pDev,
                pVideoFeatureDetails);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1DB7C52Cu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3602
// RVA: 0xEA3730
__int64 __fastcall NvAPI_D3D9_GetSLIInfo(unsigned int *pDev, NV_SLI_INFO *pSliInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_108 = 0i64;
  if ( !fp_108 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_108 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x694BFF4Du);
  if ( !fp_108 )
    return 4294967293i64;
  v3 = fp_108;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x694BFF4Du, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NV_SLI_INFO *))v3)(pDev, pSliInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x694BFF4Du, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3627
// RVA: 0xEA3860
__int64 __fastcall NvAPI_D3D9_SetSLIMode(unsigned int *pDev, unsigned int SliMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_109 = 0i64;
  if ( !fp_109 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_109 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBFDC062C);
  if ( !fp_109 )
    return 4294967293i64;
  v3 = fp_109;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBFDC062C, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v3)(pDev, SliMode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBFDC062C, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3652
// RVA: 0xEA3990
__int64 __fastcall NvAPI_D3D9_QueryAAOverrideMode(
        unsigned int *pDev,
        unsigned int *pRenderingSampleCount,
        unsigned int *pBufferSampleCount,
        unsigned int *pAAMode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_110 = 0i64;
  if ( !fp_110 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_110 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDDF5643C);
  if ( !fp_110 )
    return 4294967293i64;
  v5 = fp_110;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDDF5643C, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, unsigned int *, __int64 (__fastcall *)()))v5)(
                pDev,
                pRenderingSampleCount,
                pBufferSampleCount,
                pAAMode,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDDF5643C, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 3677
// RVA: 0xEA3AD0
__int64 __fastcall NvAPI_D3D9_VideoSurfaceEncryptionControl(
        unsigned int *pDev,
        NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *pVidSurfEncrCtrlParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_111 = 0i64;
  if ( !fp_111 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_111 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9D2509EF);
  if ( !fp_111 )
    return 4294967293i64;
  v3 = fp_111;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9D2509EF, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *))v3)(
                pDev,
                pVidSurfEncrCtrlParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9D2509EF, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3702
// RVA: 0xEA3C00
__int64 __fastcall NvAPI_D3D9_DMA(unsigned int *pDev, _NVAPI_D3D9_DMA_PARAMS *pVideoDMAParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_112 = 0i64;
  if ( !fp_112 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_112 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x962B8AF6);
  if ( !fp_112 )
    return 4294967293i64;
  v3 = fp_112;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x962B8AF6, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_D3D9_DMA_PARAMS *))v3)(pDev, pVideoDMAParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x962B8AF6, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3727
// RVA: 0xEA3D30
__int64 __fastcall NvAPI_D3D9_EnableStereo(unsigned int *pDev, _NVAPI_D3D9_ENABLE_STEREO_PARAMS *pEnableStereoParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_113 = 0i64;
  if ( !fp_113 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_113 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x492A6954u);
  if ( !fp_113 )
    return 4294967293i64;
  v3 = fp_113;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x492A6954u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_D3D9_ENABLE_STEREO_PARAMS *))v3)(
                pDev,
                pEnableStereoParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x492A6954u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3752
// RVA: 0xEA3E60
__int64 __fastcall NvAPI_D3D9_StretchRect(
        unsigned int *pDev,
        NVDX_ObjectHandle__ *hSrcObj,
        tagRECT *pSourceRect,
        NVDX_ObjectHandle__ *hDstObj,
        tagRECT *pDestRect,
        unsigned int Filter)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_114 = 0i64;
  if ( !fp_114 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_114 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAEAECD41);
  if ( !fp_114 )
    return 4294967293i64;
  v7 = fp_114;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAEAECD41, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, tagRECT *, NVDX_ObjectHandle__ *, tagRECT *, unsigned int, __int64 (__fastcall *)()))v7)(
                pDev,
                hSrcObj,
                pSourceRect,
                hDstObj,
                pDestRect,
                Filter,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAEAECD41, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 3777
// RVA: 0xEA3FC0
__int64 __fastcall NvAPI_D3D9_CreateRenderTarget(
        unsigned int *pDev,
        unsigned int Width,
        unsigned int Height,
        unsigned int Format,
        unsigned int MultiSample,
        unsigned int MultisampleQuality,
        int Lockable,
        unsigned int **ppSurface,
        NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v10)(); // [rsp+50h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+58h] [rbp-20h] BYREF
  unsigned __int64 v12; // [rsp+60h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+68h] [rbp-10h]
  int v14; // [rsp+6Ch] [rbp-Ch]

  hMod = 0i64;
  v14 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_115 = 0i64;
  if ( !fp_115 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_115 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB3827C8u);
  if ( !fp_115 )
    return 4294967293i64;
  v10 = fp_115;
  v12 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB3827C8u, &v12);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD, unsigned int, unsigned int, int, unsigned int **, NVDX_ObjectHandle__ **))v10)(
                pDev,
                Width,
                Height,
                Format,
                MultiSample,
                MultisampleQuality,
                Lockable,
                ppSurface,
                pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB3827C8u, v12, GpuHandle);
  --g_module_numApiInUse[v14];
  return (unsigned int)GpuHandle;
}

// File Line: 3802
// RVA: 0xEA4150
__int64 __fastcall NvAPI_D3D9_NVFBC_GetStatus(void *pNvFBCStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_116 = 0i64;
  if ( !fp_116 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_116 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBD3EB475);
  if ( !fp_116 )
    return 4294967293i64;
  v2 = fp_116;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBD3EB475, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(pNvFBCStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBD3EB475, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 3827
// RVA: 0xEA4270
__int64 __fastcall NvAPI_D3D9_IFR_SetUpTargetBufferToSys(
        unsigned int *pDev,
        unsigned int eFormat,
        unsigned int dwNBuffers,
        char **ppBuffer)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_117 = 0i64;
  if ( !fp_117 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_117 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x55255D05u);
  if ( !fp_117 )
    return 4294967293i64;
  v5 = fp_117;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x55255D05u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, char **, __int64 (__fastcall *)()))v5)(
                pDev,
                eFormat,
                dwNBuffers,
                ppBuffer,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x55255D05u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 3852
// RVA: 0xEA43B0
__int64 __fastcall NvAPI_D3D9_GPUBasedCPUSleep(unsigned int *pDev, unsigned __int64 qwMicroSeconds)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_118 = 0i64;
  if ( !fp_118 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_118 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD504DDA7);
  if ( !fp_118 )
    return 4294967293i64;
  v3 = fp_118;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD504DDA7, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned __int64))v3)(pDev, qwMicroSeconds);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD504DDA7, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 3877
// RVA: 0xEA44E0
__int64 __fastcall NvAPI_D3D9_IFR_TransferRenderTarget(
        unsigned int *pDev,
        void **pEvent,
        unsigned int dwBufferIndex,
        unsigned int dwTargetWidth,
        unsigned int dwTargetHeight)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_119 = 0i64;
  if ( !fp_119 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_119 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAB7C2DCu);
  if ( !fp_119 )
    return 4294967293i64;
  v6 = fp_119;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAB7C2DCu, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, void **, _QWORD, _QWORD, unsigned int))v6)(
                pDev,
                pEvent,
                dwBufferIndex,
                dwTargetWidth,
                dwTargetHeight);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAB7C2DCu, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 3902
// RVA: 0xEA4630
__int64 __fastcall NvAPI_D3D9_IFR_SetUpTargetBufferToNV12BLVideoSurface(
        unsigned int *pDev,
        unsigned int dwNBuffers,
        void **aHandles,
        unsigned int dwTargetWidth,
        unsigned int dwTargetHeight)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_120 = 0i64;
  if ( !fp_120 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_120 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCFC92C15);
  if ( !fp_120 )
    return 4294967293i64;
  v6 = fp_120;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCFC92C15, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, void **, _QWORD, unsigned int))v6)(
                pDev,
                dwNBuffers,
                aHandles,
                dwTargetWidth,
                dwTargetHeight);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCFC92C15, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 3927
// RVA: 0xEA4780
__int64 __fastcall NvAPI_D3D9_IFR_TransferRenderTargetToNV12BLVideoSurface(
        unsigned int *pDev,
        unsigned int dwBufferIndex,
        unsigned int dwTargetWidth,
        unsigned int dwTargetHeight)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_121 = 0i64;
  if ( !fp_121 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_121 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5FE72F64u);
  if ( !fp_121 )
    return 4294967293i64;
  v5 = fp_121;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5FE72F64u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                pDev,
                dwBufferIndex,
                dwTargetWidth,
                dwTargetHeight,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5FE72F64u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 3952
// RVA: 0xEA48C0
__int64 __fastcall NvAPI_D3D10_AliasPrimaryAsTexture(
        unsigned int *pDev,
        unsigned int headIndex,
        unsigned int **ppTexture)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_122 = 0i64;
  if ( !fp_122 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_122 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8AAC133D);
  if ( !fp_122 )
    return 4294967293i64;
  v4 = fp_122;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8AAC133D, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, unsigned int **))v4)(pDev, headIndex, ppTexture);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8AAC133D, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 3977
// RVA: 0xEA49F0
__int64 __fastcall NvAPI_D3D10_SetPrimaryFlipChainCallbacks(
        unsigned int *pDev,
        NVAPI_FLIP_CHAIN_CALLBACK_PARAMS *pCallbackParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_123 = 0i64;
  if ( !fp_123 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_123 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x73EB9329u);
  if ( !fp_123 )
    return 4294967293i64;
  v3 = fp_123;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x73EB9329u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NVAPI_FLIP_CHAIN_CALLBACK_PARAMS *))v3)(
                pDev,
                pCallbackParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x73EB9329u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4002
// RVA: 0xEA4B20
__int64 __fastcall NvAPI_D3D10_ProcessCallbacks(unsigned int *pDev, unsigned int dwMilliseconds)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_124 = 0i64;
  if ( !fp_124 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_124 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE9C2019);
  if ( !fp_124 )
    return 4294967293i64;
  v3 = fp_124;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE9C2019, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v3)(pDev, dwMilliseconds);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE9C2019, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4027
// RVA: 0xEA4C50
__int64 __fastcall NvAPI_D3D10_GetRenderedCursorAsBitmap(
        unsigned int *pDev,
        _NVAPI_RENDERED_CURSOR_BITMAP_DATA *pRenderedCursorBitmapData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_125 = 0i64;
  if ( !fp_125 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_125 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCAC3CE5D);
  if ( !fp_125 )
    return 4294967293i64;
  v3 = fp_125;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCAC3CE5D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_RENDERED_CURSOR_BITMAP_DATA *))v3)(
                pDev,
                pRenderedCursorBitmapData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCAC3CE5D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4052
// RVA: 0xEA4D80
__int64 __fastcall NvAPI_D3D10_BeginShareResource(unsigned int *pResource, void **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_126 = 0i64;
  if ( !fp_126 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_126 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x35233210u);
  if ( !fp_126 )
    return 4294967293i64;
  v3 = fp_126;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x35233210u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, void **))v3)(pResource, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x35233210u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4077
// RVA: 0xEA4EB0
__int64 __fastcall NvAPI_D3D10_BeginShareResourceEx(unsigned int *pResource, unsigned int flags, void **pHandle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_127 = 0i64;
  if ( !fp_127 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_127 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEF303A9D);
  if ( !fp_127 )
    return 4294967293i64;
  v4 = fp_127;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEF303A9D, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, void **))v4)(pResource, flags, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEF303A9D, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4102
// RVA: 0xEA4FE0
__int64 __fastcall NvAPI_D3D10_EndShareResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_128 = 0i64;
  if ( !fp_128 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_128 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE9C5853u);
  if ( !fp_128 )
    return 4294967293i64;
  v2 = fp_128;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE9C5853u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pResource);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE9C5853u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 4127
// RVA: 0xEA5100
__int64 __fastcall NvAPI_D3D10_SetDepthBoundsTest(
        unsigned int *pDev,
        unsigned int bEnable,
        float fMinDepth,
        float fMaxDepth)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_129 = 0i64;
  if ( !fp_129 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_129 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4EADF5D2u);
  if ( !fp_129 )
    return 4294967293i64;
  v5 = fp_129;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4EADF5D2u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v5)(pDev, bEnable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4EADF5D2u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 4152
// RVA: 0xEA5240
__int64 __fastcall NvAPI_D3D10_CreateDevice(
        unsigned int *pAdapter,
        unsigned int DriverType,
        HINSTANCE__ *Software,
        unsigned int Flags,
        unsigned int HardwareLevel,
        unsigned int SDKVersion,
        unsigned int **ppDevice,
        NVAPI_DEVICE_FEATURE_LEVEL *pLevel)
{
  __int64 (__fastcall *v9)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h] BYREF
  unsigned __int64 v11; // [rsp+50h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+58h] [rbp-10h]
  int v13; // [rsp+5Ch] [rbp-Ch]

  hMod = 0i64;
  v13 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_130 = 0i64;
  if ( !fp_130 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_130 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2DE11D61u);
  if ( !fp_130 )
    return 4294967293i64;
  v9 = fp_130;
  v11 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2DE11D61u, &v11);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, unsigned int, unsigned int, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *, __int64 (__fastcall *)()))v9)(
                pAdapter,
                DriverType,
                Software,
                Flags,
                HardwareLevel,
                SDKVersion,
                ppDevice,
                pLevel,
                v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2DE11D61u, v11, GpuHandle);
  --g_module_numApiInUse[v13];
  return (unsigned int)GpuHandle;
}

// File Line: 4177
// RVA: 0xEA53B0
__int64 __fastcall NvAPI_D3D10_CreateDeviceAndSwapChain(
        unsigned int *pAdapter,
        unsigned int DriverType,
        HINSTANCE__ *Software,
        unsigned int Flags,
        unsigned int HardwareLevel,
        unsigned int SDKVersion,
        unsigned int *pSwapChainDesc,
        unsigned int **ppSwapChain,
        unsigned int **ppDevice,
        NVAPI_DEVICE_FEATURE_LEVEL *pLevel)
{
  __int64 (__fastcall *v11)(); // [rsp+50h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+58h] [rbp-20h] BYREF
  unsigned __int64 v13; // [rsp+60h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+68h] [rbp-10h]
  int v15; // [rsp+6Ch] [rbp-Ch]

  hMod = 0i64;
  v15 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_131 = 0i64;
  if ( !fp_131 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_131 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5B803DAFu);
  if ( !fp_131 )
    return 4294967293i64;
  v11 = fp_131;
  v13 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5B803DAFu, &v13);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, unsigned int, unsigned int, unsigned int *, unsigned int **, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *, __int64 (__fastcall *)()))v11)(
                pAdapter,
                DriverType,
                Software,
                Flags,
                HardwareLevel,
                SDKVersion,
                pSwapChainDesc,
                ppSwapChain,
                ppDevice,
                pLevel,
                v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5B803DAFu, v13, GpuHandle);
  --g_module_numApiInUse[v15];
  return (unsigned int)GpuHandle;
}

// File Line: 4202
// RVA: 0xEA5540
__int64 __fastcall NvAPI_D3D11_CreateDevice(
        unsigned int *pAdapter,
        unsigned int DriverType,
        HINSTANCE__ *Software,
        unsigned int Flags,
        const unsigned int *pFeatureLevels,
        unsigned int FeatureLevels,
        unsigned int SDKVersion,
        unsigned int **ppDevice,
        unsigned int *pFeatureLevel,
        unsigned int **ppImmediateContext,
        NVAPI_DEVICE_FEATURE_LEVEL *pSupportedLevel)
{
  __int64 (__fastcall *v12)(); // [rsp+60h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+68h] [rbp-20h] BYREF
  unsigned __int64 v14; // [rsp+70h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+78h] [rbp-10h]
  int v16; // [rsp+7Ch] [rbp-Ch]

  hMod = 0i64;
  v16 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_132 = 0i64;
  if ( !fp_132 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_132 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6A16D3A0u);
  if ( !fp_132 )
    return 4294967293i64;
  v12 = fp_132;
  v14 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6A16D3A0u, &v14);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, const unsigned int *, unsigned int, unsigned int, unsigned int **, unsigned int *, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *))v12)(
                pAdapter,
                DriverType,
                Software,
                Flags,
                pFeatureLevels,
                FeatureLevels,
                SDKVersion,
                ppDevice,
                pFeatureLevel,
                ppImmediateContext,
                pSupportedLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6A16D3A0u, v14, GpuHandle);
  --g_module_numApiInUse[v16];
  return (unsigned int)GpuHandle;
}

// File Line: 4227
// RVA: 0xEA56F0
__int64 __fastcall NvAPI_D3D11_CreateDeviceAndSwapChain(
        unsigned int *pAdapter,
        unsigned int DriverType,
        HINSTANCE__ *Software,
        unsigned int Flags,
        const unsigned int *pFeatureLevels,
        unsigned int FeatureLevels,
        unsigned int SDKVersion,
        const unsigned int *pSwapChainDesc,
        unsigned int **ppSwapChain,
        unsigned int **ppDevice,
        unsigned int *pFeatureLevel,
        unsigned int **ppImmediateContext,
        NVAPI_DEVICE_FEATURE_LEVEL *pSupportedLevel)
{
  __int64 (__fastcall *v14)(); // [rsp+70h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+78h] [rbp-20h] BYREF
  unsigned __int64 v16; // [rsp+80h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+88h] [rbp-10h]
  int v18; // [rsp+8Ch] [rbp-Ch]

  hMod = 0i64;
  v18 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_133 = 0i64;
  if ( !fp_133 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_133 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBB939EE5);
  if ( !fp_133 )
    return 4294967293i64;
  v14 = fp_133;
  v16 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBB939EE5, &v16);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, const unsigned int *, unsigned int, unsigned int, const unsigned int *, unsigned int **, unsigned int **, unsigned int *, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *))v14)(
                pAdapter,
                DriverType,
                Software,
                Flags,
                pFeatureLevels,
                FeatureLevels,
                SDKVersion,
                pSwapChainDesc,
                ppSwapChain,
                ppDevice,
                pFeatureLevel,
                ppImmediateContext,
                pSupportedLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBB939EE5, v16, GpuHandle);
  --g_module_numApiInUse[v18];
  return (unsigned int)GpuHandle;
}

// File Line: 4252
// RVA: 0xEA58E0
__int64 __fastcall NvAPI_D3D11_BeginShareResource(unsigned int *pResource, unsigned int flags, void **pHandle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_134 = 0i64;
  if ( !fp_134 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_134 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x121BDC6u);
  if ( !fp_134 )
    return 4294967293i64;
  v4 = fp_134;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x121BDC6u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, void **))v4)(pResource, flags, pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x121BDC6u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4277
// RVA: 0xEA5A10
__int64 __fastcall NvAPI_D3D11_EndShareResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_135 = 0i64;
  if ( !fp_135 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_135 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8FFB8E26);
  if ( !fp_135 )
    return 4294967293i64;
  v2 = fp_135;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8FFB8E26, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pResource);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8FFB8E26, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 4302
// RVA: 0xEA5B30
__int64 __fastcall NvAPI_D3D11_SetDepthBoundsTest(
        unsigned int *pDev,
        unsigned int bEnable,
        float fMinDepth,
        float fMaxDepth)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_136 = 0i64;
  if ( !fp_136 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_136 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7AAF7A04u);
  if ( !fp_136 )
    return 4294967293i64;
  v5 = fp_136;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7AAF7A04u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v5)(pDev, bEnable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7AAF7A04u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 4327
// RVA: 0xEA5C70
__int64 __fastcall NvAPI_GPU_GetShaderPipeCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_137 = 0i64;
  if ( !fp_137 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_137 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63E2F56Fu);
  if ( !fp_137 )
    return 4294967293i64;
  v3 = fp_137;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63E2F56Fu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63E2F56Fu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4352
// RVA: 0xEA5DA0
__int64 __fastcall NvAPI_GPU_GetShaderSubPipeCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_138 = 0i64;
  if ( !fp_138 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_138 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBE17923u);
  if ( !fp_138 )
    return 4294967293i64;
  v3 = fp_138;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBE17923u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBE17923u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4377
// RVA: 0xEA5ED0
__int64 __fastcall NvAPI_GPU_GetPartitionCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_139 = 0i64;
  if ( !fp_139 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_139 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x86F05D7A);
  if ( !fp_139 )
    return 4294967293i64;
  v3 = fp_139;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x86F05D7A, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x86F05D7A, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4402
// RVA: 0xEA6000
__int64 __fastcall NvAPI_GPU_GetMemPartitionMask(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_140 = 0i64;
  if ( !fp_140 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_140 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x329D77CDu);
  if ( !fp_140 )
    return 4294967293i64;
  v3 = fp_140;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x329D77CDu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x329D77CDu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4427
// RVA: 0xEA6130
__int64 __fastcall NvAPI_GPU_GetTPCMask(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_141 = 0i64;
  if ( !fp_141 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_141 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4A35DF54u);
  if ( !fp_141 )
    return 4294967293i64;
  v3 = fp_141;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4A35DF54u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4A35DF54u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4452
// RVA: 0xEA6260
__int64 __fastcall NvAPI_GPU_GetSMMask(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int tpcId, unsigned int *pMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_142 = 0i64;
  if ( !fp_142 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_142 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEB7AF173);
  if ( !fp_142 )
    return 4294967293i64;
  v4 = fp_142;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEB7AF173, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, unsigned int *))v4)(
                hPhysicalGpu,
                tpcId,
                pMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEB7AF173, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4477
// RVA: 0xEA6390
__int64 __fastcall NvAPI_GPU_GetTotalTPCCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_143 = 0i64;
  if ( !fp_143 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_143 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4E2F76A8u);
  if ( !fp_143 )
    return 4294967293i64;
  v3 = fp_143;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4E2F76A8u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4E2F76A8u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4502
// RVA: 0xEA64C0
__int64 __fastcall NvAPI_GPU_GetTotalSMCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_144 = 0i64;
  if ( !fp_144 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_144 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE5FBCFE);
  if ( !fp_144 )
    return 4294967293i64;
  v3 = fp_144;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE5FBCFE, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE5FBCFE, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4527
// RVA: 0xEA65F0
__int64 __fastcall NvAPI_GPU_GetTotalSPCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_145 = 0i64;
  if ( !fp_145 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_145 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB6D62591);
  if ( !fp_145 )
    return 4294967293i64;
  v3 = fp_145;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB6D62591, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB6D62591, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4552
// RVA: 0xEA6720
__int64 __fastcall NvAPI_GPU_GetGpuCoreCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_146 = 0i64;
  if ( !fp_146 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_146 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC7026A87);
  if ( !fp_146 )
    return 4294967293i64;
  v3 = fp_146;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC7026A87, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC7026A87, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4577
// RVA: 0xEA6850
__int64 __fastcall NvAPI_GPU_GetAllOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_147 = 0i64;
  if ( !fp_147 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_147 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7D554F8Eu);
  if ( !fp_147 )
    return 4294967293i64;
  v3 = fp_147;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7D554F8Eu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pOutputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7D554F8Eu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4602
// RVA: 0xEA6980
__int64 __fastcall NvAPI_GPU_GetConnectedOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_148 = 0i64;
  if ( !fp_148 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_148 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1730BFC9u);
  if ( !fp_148 )
    return 4294967293i64;
  v3 = fp_148;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1730BFC9u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pOutputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1730BFC9u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4627
// RVA: 0xEA6AB0
__int64 __fastcall NvAPI_GPU_GetConnectedSLIOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_149 = 0i64;
  if ( !fp_149 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_149 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x680DE09u);
  if ( !fp_149 )
    return 4294967293i64;
  v3 = fp_149;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x680DE09u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pOutputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x680DE09u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4652
// RVA: 0xEA6BE0
__int64 __fastcall NvAPI_GPU_GetConnectedDisplayIds(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        _NV_GPU_DISPLAYIDS *pDisplayIds,
        unsigned int *pDisplayIdCount,
        unsigned int flags)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_150 = 0i64;
  if ( !fp_150 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_150 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x78DBA2u);
  if ( !fp_150 )
    return 4294967293i64;
  v5 = fp_150;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x78DBA2u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_DISPLAYIDS *, unsigned int *, _QWORD, __int64 (__fastcall *)()))v5)(
                hPhysicalGpu,
                pDisplayIds,
                pDisplayIdCount,
                flags,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x78DBA2u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 4677
// RVA: 0xEA6D20
__int64 __fastcall NvAPI_GPU_GetAllDisplayIds(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        _NV_GPU_DISPLAYIDS *pDisplayIds,
        unsigned int *pDisplayIdCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_151 = 0i64;
  if ( !fp_151 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_151 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x785210A2u);
  if ( !fp_151 )
    return 4294967293i64;
  v4 = fp_151;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x785210A2u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_DISPLAYIDS *, unsigned int *))v4)(
                hPhysicalGpu,
                pDisplayIds,
                pDisplayIdCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x785210A2u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4702
// RVA: 0xEA6E60
__int64 __fastcall NvAPI_GPU_GetConnectedOutputsWithLidState(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_152 = 0i64;
  if ( !fp_152 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_152 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCF8CAF39);
  if ( !fp_152 )
    return 4294967293i64;
  v3 = fp_152;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCF8CAF39, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pOutputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCF8CAF39, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4727
// RVA: 0xEA6F90
__int64 __fastcall NvAPI_GPU_GetConnectedSLIOutputsWithLidState(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_153 = 0i64;
  if ( !fp_153 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_153 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x96043CC7);
  if ( !fp_153 )
    return 4294967293i64;
  v3 = fp_153;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x96043CC7, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pOutputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x96043CC7, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4752
// RVA: 0xEA70C0
__int64 __fastcall NvAPI_GPU_GetSystemType(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_SYSTEM_TYPE *pSystemType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_154 = 0i64;
  if ( !fp_154 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_154 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBAAABFCC);
  if ( !fp_154 )
    return 4294967293i64;
  v3 = fp_154;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBAAABFCC, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_SYSTEM_TYPE *))v3)(hPhysicalGpu, pSystemType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBAAABFCC, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4777
// RVA: 0xEA71F0
__int64 __fastcall NvAPI_GPU_GetActiveOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_155 = 0i64;
  if ( !fp_155 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_155 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE3E89B6F);
  if ( !fp_155 )
    return 4294967293i64;
  v3 = fp_155;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE3E89B6F, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pOutputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE3E89B6F, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4802
// RVA: 0xEA7320
__int64 __fastcall NvAPI_GPU_GetEDID(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int displayOutputId,
        NV_EDID_V3 *pEDID)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_156 = 0i64;
  if ( !fp_156 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_156 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x37D32E69u);
  if ( !fp_156 )
    return 4294967293i64;
  v4 = fp_156;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x37D32E69u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_EDID_V3 *))v4)(
                hPhysicalGpu,
                displayOutputId,
                pEDID);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x37D32E69u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4827
// RVA: 0xEA7450
__int64 __fastcall NvAPI_GPU_SetEDID(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int displayOutputId,
        NV_EDID_V3 *pEDID)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_157 = 0i64;
  if ( !fp_157 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_157 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE83D6456);
  if ( !fp_157 )
    return 4294967293i64;
  v4 = fp_157;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE83D6456, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_EDID_V3 *))v4)(
                hPhysicalGpu,
                displayOutputId,
                pEDID);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE83D6456, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4852
// RVA: 0xEA7580
__int64 __fastcall NvAPI_GPU_GetOutputType(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        _NV_GPU_OUTPUT_TYPE *pOutputType)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_158 = 0i64;
  if ( !fp_158 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_158 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x40A505E4u);
  if ( !fp_158 )
    return 4294967293i64;
  v4 = fp_158;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x40A505E4u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _NV_GPU_OUTPUT_TYPE *))v4)(
                hPhysicalGpu,
                outputId,
                pOutputType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x40A505E4u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4877
// RVA: 0xEA76B0
__int64 __fastcall NvAPI_GPU_GetDeviceDisplayMode(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int displayId,
        NV_GPU_DISPLAY_MODE *pDeviceDisplayMode)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_159 = 0i64;
  if ( !fp_159 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_159 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2277E3A);
  if ( !fp_159 )
    return 4294967293i64;
  v4 = fp_159;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2277E3A, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_DISPLAY_MODE *))v4)(
                hPhysicalGpu,
                displayId,
                pDeviceDisplayMode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2277E3A, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4902
// RVA: 0xEA77E0
__int64 __fastcall NvAPI_GPU_GetFlatPanelInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        NV_GPU_FLAT_PANEL_INFO *pFlatPanelInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_160 = 0i64;
  if ( !fp_160 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_160 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x36CFF969u);
  if ( !fp_160 )
    return 4294967293i64;
  v4 = fp_160;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x36CFF969u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_FLAT_PANEL_INFO *))v4)(
                hPhysicalGpu,
                outputId,
                pFlatPanelInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x36CFF969u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4927
// RVA: 0xEA7910
__int64 __fastcall NvAPI_GPU_ValidateOutputCombination(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_161 = 0i64;
  if ( !fp_161 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_161 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x34C9C2D4u);
  if ( !fp_161 )
    return 4294967293i64;
  v3 = fp_161;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x34C9C2D4u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(hPhysicalGpu, outputsMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x34C9C2D4u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 4952
// RVA: 0xEA7A40
__int64 __fastcall NvAPI_GPU_GetConnectorInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        NV_GPU_CONNECTOR_INFO *pConnectorInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_162 = 0i64;
  if ( !fp_162 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_162 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4ECA2C10u);
  if ( !fp_162 )
    return 4294967293i64;
  v4 = fp_162;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4ECA2C10u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_CONNECTOR_INFO *))v4)(
                hPhysicalGpu,
                outputId,
                pConnectorInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4ECA2C10u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 4977
// RVA: 0xEA7B70
__int64 __fastcall NvAPI_GPU_GetFullName(NvPhysicalGpuHandle__ *hPhysicalGpu, char *szName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_163 = 0i64;
  if ( !fp_163 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_163 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCEEE8E9F);
  if ( !fp_163 )
    return 4294967293i64;
  v3 = fp_163;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCEEE8E9F, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, char *))v3)(hPhysicalGpu, szName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCEEE8E9F, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5002
// RVA: 0xEA7CA0
__int64 __fastcall NvAPI_GPU_GetPCIIdentifiers(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int *pDeviceId,
        unsigned int *pSubSystemId,
        unsigned int *pRevisionId,
        unsigned int *pExtDeviceId)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_164 = 0i64;
  if ( !fp_164 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_164 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2DDFB66Eu);
  if ( !fp_164 )
    return 4294967293i64;
  v6 = fp_164;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2DDFB66Eu, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, unsigned int *, unsigned int *, unsigned int *))v6)(
                hPhysicalGpu,
                pDeviceId,
                pSubSystemId,
                pRevisionId,
                pExtDeviceId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2DDFB66Eu, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 5027
// RVA: 0xEA7DF0
__int64 __fastcall NvAPI_GPU_GetGPUType(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_TYPE *pGpuType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_165 = 0i64;
  if ( !fp_165 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_165 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC33BAEB1);
  if ( !fp_165 )
    return 4294967293i64;
  v3 = fp_165;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC33BAEB1, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_TYPE *))v3)(hPhysicalGpu, pGpuType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC33BAEB1, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5052
// RVA: 0xEA7F20
__int64 __fastcall NvAPI_GPU_GetBusType(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_BUS_TYPE *pBusType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_166 = 0i64;
  if ( !fp_166 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_166 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1BB18724u);
  if ( !fp_166 )
    return 4294967293i64;
  v3 = fp_166;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1BB18724u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_BUS_TYPE *))v3)(hPhysicalGpu, pBusType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1BB18724u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5077
// RVA: 0xEA8050
__int64 __fastcall NvAPI_GPU_GetBusId(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBusId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_167 = 0i64;
  if ( !fp_167 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_167 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1BE0B8E5u);
  if ( !fp_167 )
    return 4294967293i64;
  v3 = fp_167;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1BE0B8E5u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pBusId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1BE0B8E5u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5102
// RVA: 0xEA8180
__int64 __fastcall NvAPI_GPU_GetBusSlotId(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBusSlotId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_168 = 0i64;
  if ( !fp_168 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_168 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2A0A350Fu);
  if ( !fp_168 )
    return 4294967293i64;
  v3 = fp_168;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2A0A350Fu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pBusSlotId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2A0A350Fu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5127
// RVA: 0xEA82B0
__int64 __fastcall NvAPI_GPU_GetIRQ(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pIRQ)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_169 = 0i64;
  if ( !fp_169 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_169 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE4715417);
  if ( !fp_169 )
    return 4294967293i64;
  v3 = fp_169;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE4715417, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pIRQ);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE4715417, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5152
// RVA: 0xEA83E0
__int64 __fastcall NvAPI_GPU_GetVbiosRevision(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBiosRevision)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_170 = 0i64;
  if ( !fp_170 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_170 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xACC3DA0A);
  if ( !fp_170 )
    return 4294967293i64;
  v3 = fp_170;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xACC3DA0A, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pBiosRevision);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xACC3DA0A, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5177
// RVA: 0xEA8510
__int64 __fastcall NvAPI_GPU_GetVbiosOEMRevision(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBiosRevision)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_171 = 0i64;
  if ( !fp_171 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_171 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2D43FB31u);
  if ( !fp_171 )
    return 4294967293i64;
  v3 = fp_171;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2D43FB31u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pBiosRevision);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2D43FB31u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5202
// RVA: 0xEA8640
__int64 __fastcall NvAPI_GPU_GetVbiosVersionString(NvPhysicalGpuHandle__ *hPhysicalGpu, char *szBiosRevision)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_172 = 0i64;
  if ( !fp_172 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_172 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA561FD7D);
  if ( !fp_172 )
    return 4294967293i64;
  v3 = fp_172;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA561FD7D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, char *))v3)(hPhysicalGpu, szBiosRevision);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA561FD7D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5227
// RVA: 0xEA8770
__int64 __fastcall NvAPI_GPU_GetAGPAperture(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_173 = 0i64;
  if ( !fp_173 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_173 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6E042794u);
  if ( !fp_173 )
    return 4294967293i64;
  v3 = fp_173;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6E042794u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pSize);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6E042794u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5252
// RVA: 0xEA88A0
__int64 __fastcall NvAPI_GPU_GetCurrentAGPRate(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pRate)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_174 = 0i64;
  if ( !fp_174 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_174 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC74925A0);
  if ( !fp_174 )
    return 4294967293i64;
  v3 = fp_174;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC74925A0, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pRate);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC74925A0, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5277
// RVA: 0xEA89D0
__int64 __fastcall NvAPI_GPU_GetCurrentPCIEDownstreamWidth(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pWidth)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_175 = 0i64;
  if ( !fp_175 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_175 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD048C3B1);
  if ( !fp_175 )
    return 4294967293i64;
  v3 = fp_175;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD048C3B1, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pWidth);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD048C3B1, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5302
// RVA: 0xEA8B00
__int64 __fastcall NvAPI_GPU_GetPhysicalFrameBufferSize(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_176 = 0i64;
  if ( !fp_176 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_176 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x46FBEB03u);
  if ( !fp_176 )
    return 4294967293i64;
  v3 = fp_176;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x46FBEB03u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pSize);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x46FBEB03u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5327
// RVA: 0xEA8C30
__int64 __fastcall NvAPI_GPU_GetVirtualFrameBufferSize(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_177 = 0i64;
  if ( !fp_177 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_177 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5A04B644u);
  if ( !fp_177 )
    return 4294967293i64;
  v3 = fp_177;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5A04B644u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pSize);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5A04B644u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5352
// RVA: 0xEA8D60
__int64 __fastcall NvAPI_GPU_GetQuadroStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_178 = 0i64;
  if ( !fp_178 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_178 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE332FA47);
  if ( !fp_178 )
    return 4294967293i64;
  v3 = fp_178;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE332FA47, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE332FA47, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5377
// RVA: 0xEA8E90
__int64 __fastcall NvAPI_GPU_GetBoardInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_BOARD_INFO *pBoardInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_179 = 0i64;
  if ( !fp_179 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_179 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22D54523u);
  if ( !fp_179 )
    return 4294967293i64;
  v3 = fp_179;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22D54523u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_BOARD_INFO *))v3)(hPhysicalGpu, pBoardInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22D54523u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5402
// RVA: 0xEA8FC0
__int64 __fastcall NvAPI_GPU_GetRamType(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_RAM_TYPE *pRamType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_180 = 0i64;
  if ( !fp_180 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_180 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x57F7CAACu);
  if ( !fp_180 )
    return 4294967293i64;
  v3 = fp_180;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x57F7CAACu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_RAM_TYPE *))v3)(hPhysicalGpu, pRamType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x57F7CAACu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5427
// RVA: 0xEA90F0
__int64 __fastcall NvAPI_GPU_GetFBWidthAndLocation(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int *pBusWidth,
        _NV_GPU_FB_LOCATION *pFBLocation)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_181 = 0i64;
  if ( !fp_181 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_181 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x11104158u);
  if ( !fp_181 )
    return 4294967293i64;
  v4 = fp_181;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x11104158u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, _NV_GPU_FB_LOCATION *))v4)(
                hPhysicalGpu,
                pBusWidth,
                pFBLocation);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x11104158u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5452
// RVA: 0xEA9230
__int64 __fastcall NvAPI_GPU_GetAllClockFrequencies(
        NvPhysicalGpuHandle__ *hPhysicalGPU,
        NV_GPU_CLOCK_FREQUENCIES_V2 *pClkFreqs)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_182 = 0i64;
  if ( !fp_182 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_182 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDCB616C3);
  if ( !fp_182 )
    return 4294967293i64;
  v3 = fp_182;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDCB616C3, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLOCK_FREQUENCIES_V2 *))v3)(
                hPhysicalGPU,
                pClkFreqs);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDCB616C3, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5477
// RVA: 0xEA9360
__int64 __fastcall NvAPI_GPU_GetPerfClocks(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int level,
        NV_GPU_PERF_CLOCK_TABLE *pPerfClkTable)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_183 = 0i64;
  if ( !fp_183 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_183 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1EA54A3Bu);
  if ( !fp_183 )
    return 4294967293i64;
  v4 = fp_183;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1EA54A3Bu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_PERF_CLOCK_TABLE *))v4)(
                hPhysicalGpu,
                level,
                pPerfClkTable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1EA54A3Bu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5502
// RVA: 0xEA9490
__int64 __fastcall NvAPI_GPU_SetPerfClocks(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int level,
        NV_GPU_PERF_CLOCK_TABLE *pPerfClkTable)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_184 = 0i64;
  if ( !fp_184 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_184 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7BCF4ACu);
  if ( !fp_184 )
    return 4294967293i64;
  v4 = fp_184;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7BCF4ACu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_PERF_CLOCK_TABLE *))v4)(
                hPhysicalGpu,
                level,
                pPerfClkTable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7BCF4ACu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5527
// RVA: 0xEA95C0
__int64 __fastcall NvAPI_GPU_GetCoolerSettings(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int coolerIndex,
        NV_GPU_GETCOOLER_SETTINGS_V3 *pCoolerInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_185 = 0i64;
  if ( !fp_185 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_185 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA141340);
  if ( !fp_185 )
    return 4294967293i64;
  v4 = fp_185;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA141340, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_GETCOOLER_SETTINGS_V3 *))v4)(
                hPhysicalGpu,
                coolerIndex,
                pCoolerInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA141340, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5552
// RVA: 0xEA96F0
__int64 __fastcall NvAPI_GPU_SetCoolerLevels(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int coolerIndex,
        NV_GPU_SETCOOLER_LEVEL_V2 *pCoolerLevels)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_186 = 0i64;
  if ( !fp_186 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_186 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x891FA0AE);
  if ( !fp_186 )
    return 4294967293i64;
  v4 = fp_186;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x891FA0AE, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_SETCOOLER_LEVEL_V2 *))v4)(
                hPhysicalGpu,
                coolerIndex,
                pCoolerLevels);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x891FA0AE, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5577
// RVA: 0xEA9820
__int64 __fastcall NvAPI_GPU_RestoreCoolerSettings(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int *pCoolerIndex,
        unsigned int coolerCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_187 = 0i64;
  if ( !fp_187 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_187 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8F6ED0FB);
  if ( !fp_187 )
    return 4294967293i64;
  v4 = fp_187;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8F6ED0FB, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, _QWORD))v4)(
                hPhysicalGpu,
                pCoolerIndex,
                coolerCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8F6ED0FB, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5602
// RVA: 0xEA9960
__int64 __fastcall NvAPI_GPU_GetCoolerPolicyTable(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int coolerIndex,
        NV_GPU_COOLER_POLICY_TABLE *pCoolerTable,
        unsigned int *count)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_188 = 0i64;
  if ( !fp_188 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_188 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x518A32Cu);
  if ( !fp_188 )
    return 4294967293i64;
  v5 = fp_188;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x518A32Cu, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_COOLER_POLICY_TABLE *, unsigned int *, __int64 (__fastcall *)()))v5)(
                hPhysicalGpu,
                coolerIndex,
                pCoolerTable,
                count,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x518A32Cu, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 5627
// RVA: 0xEA9AA0
__int64 __fastcall NvAPI_GPU_SetCoolerPolicyTable(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int coolerIndex,
        NV_GPU_COOLER_POLICY_TABLE *pCoolerTable,
        unsigned int count)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_189 = 0i64;
  if ( !fp_189 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_189 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x987947CD);
  if ( !fp_189 )
    return 4294967293i64;
  v5 = fp_189;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x987947CD, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_COOLER_POLICY_TABLE *, _QWORD, __int64 (__fastcall *)()))v5)(
                hPhysicalGpu,
                coolerIndex,
                pCoolerTable,
                count,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x987947CD, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 5652
// RVA: 0xEA9BE0
__int64 __fastcall NvAPI_GPU_RestoreCoolerPolicyTable(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int *pCoolerIndex,
        unsigned int coolerCount,
        unsigned int policy)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_190 = 0i64;
  if ( !fp_190 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_190 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD8C4FE63);
  if ( !fp_190 )
    return 4294967293i64;
  v5 = fp_190;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD8C4FE63, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                hPhysicalGpu,
                pCoolerIndex,
                coolerCount,
                policy,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD8C4FE63, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 5677
// RVA: 0xEA9D20
__int64 __fastcall NvAPI_GPU_GetPstatesInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_PERF_PSTATES_INFO_V2 *pPerfPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_191 = 0i64;
  if ( !fp_191 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_191 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBA94C56E);
  if ( !fp_191 )
    return 4294967293i64;
  v3 = fp_191;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBA94C56E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES_INFO_V2 *))v3)(
                hPhysicalGpu,
                pPerfPstatesInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBA94C56E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5702
// RVA: 0xEA9E50
__int64 __fastcall NvAPI_GPU_GetPstatesInfoEx(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_PERF_PSTATES_INFO_V2 *pPerfPstatesInfo,
        unsigned int inputFlags)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_192 = 0i64;
  if ( !fp_192 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_192 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x843C0256);
  if ( !fp_192 )
    return 4294967293i64;
  v4 = fp_192;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x843C0256, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES_INFO_V2 *, _QWORD))v4)(
                hPhysicalGpu,
                pPerfPstatesInfo,
                inputFlags);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x843C0256, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5727
// RVA: 0xEA9F90
__int64 __fastcall NvAPI_GPU_SetPstatesInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_PERF_PSTATES_INFO_V2 *pPerfPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_193 = 0i64;
  if ( !fp_193 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_193 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDF27911);
  if ( !fp_193 )
    return 4294967293i64;
  v3 = fp_193;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDF27911, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES_INFO_V2 *))v3)(
                hPhysicalGpu,
                pPerfPstatesInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDF27911, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5752
// RVA: 0xEAA0C0
__int64 __fastcall NvAPI_GPU_GetPstates20(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_PERF_PSTATES20_INFO_V1 *pPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_194 = 0i64;
  if ( !fp_194 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_194 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6FF81213u);
  if ( !fp_194 )
    return 4294967293i64;
  v3 = fp_194;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6FF81213u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES20_INFO_V1 *))v3)(
                hPhysicalGpu,
                pPstatesInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6FF81213u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5777
// RVA: 0xEAA1F0
__int64 __fastcall NvAPI_GPU_SetPstates20(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_PERF_PSTATES20_INFO_V1 *pPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_195 = 0i64;
  if ( !fp_195 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_195 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF4DAE6Bu);
  if ( !fp_195 )
    return 4294967293i64;
  v3 = fp_195;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF4DAE6Bu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES20_INFO_V1 *))v3)(
                hPhysicalGpu,
                pPstatesInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF4DAE6Bu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5802
// RVA: 0xEAA320
__int64 __fastcall NvAPI_GPU_GetCurrentPstate(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        _NV_GPU_PERF_PSTATE_ID *pCurrentPstate)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_196 = 0i64;
  if ( !fp_196 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_196 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x927DA4F6);
  if ( !fp_196 )
    return 4294967293i64;
  v3 = fp_196;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x927DA4F6, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_PERF_PSTATE_ID *))v3)(
                hPhysicalGpu,
                pCurrentPstate);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x927DA4F6, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5827
// RVA: 0xEAA450
__int64 __fastcall NvAPI_GPU_GetPstateClientLimits(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int limitId,
        _NV_GPU_PERF_PSTATE_ID *PstateLimit)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_197 = 0i64;
  if ( !fp_197 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_197 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x88C82104);
  if ( !fp_197 )
    return 4294967293i64;
  v4 = fp_197;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x88C82104, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _NV_GPU_PERF_PSTATE_ID *))v4)(
                hPhysicalGpu,
                limitId,
                PstateLimit);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x88C82104, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5852
// RVA: 0xEAA580
__int64 __fastcall NvAPI_GPU_SetPstateClientLimits(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int limitId,
        unsigned int PstateLimit)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_198 = 0i64;
  if ( !fp_198 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_198 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFDFC7D49);
  if ( !fp_198 )
    return 4294967293i64;
  v4 = fp_198;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFDFC7D49, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(
                hPhysicalGpu,
                limitId,
                PstateLimit);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFDFC7D49, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 5877
// RVA: 0xEAA6B0
__int64 __fastcall NvAPI_GPU_EnableOverclockedPstates(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned __int8 bEnable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_199 = 0i64;
  if ( !fp_199 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_199 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB23B70EE);
  if ( !fp_199 )
    return 4294967293i64;
  v3 = fp_199;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB23B70EE, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(hPhysicalGpu, bEnable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB23B70EE, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5902
// RVA: 0xEAA7E0
__int64 __fastcall NvAPI_GPU_EnableDynamicPstates(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned __int8 bEnable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_200 = 0i64;
  if ( !fp_200 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_200 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA579A0F);
  if ( !fp_200 )
    return 4294967293i64;
  v3 = fp_200;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA579A0F, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(hPhysicalGpu, bEnable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA579A0F, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5927
// RVA: 0xEAA910
__int64 __fastcall NvAPI_GPU_GetDynamicPstatesInfoEx(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_DYNAMIC_PSTATES_INFO_EX *pDynamicPstatesInfoEx)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_201 = 0i64;
  if ( !fp_201 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_201 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x60DED2EDu);
  if ( !fp_201 )
    return 4294967293i64;
  v3 = fp_201;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x60DED2EDu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_DYNAMIC_PSTATES_INFO_EX *))v3)(
                hPhysicalGpu,
                pDynamicPstatesInfoEx);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x60DED2EDu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5952
// RVA: 0xEAAA40
__int64 __fastcall NvAPI_GPU_GetVoltages(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_VOLTAGES *pPerfVoltages)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_202 = 0i64;
  if ( !fp_202 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_202 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7D656244u);
  if ( !fp_202 )
    return 4294967293i64;
  v3 = fp_202;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7D656244u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_VOLTAGES *))v3)(
                hPhysicalGpu,
                pPerfVoltages);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7D656244u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 5977
// RVA: 0xEAAB70
__int64 __fastcall NvAPI_GPU_GetThermalSettings(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int sensorIndex,
        NV_GPU_THERMAL_SETTINGS_V2 *pThermalSettings)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_203 = 0i64;
  if ( !fp_203 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_203 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE3640A56);
  if ( !fp_203 )
    return 4294967293i64;
  v4 = fp_203;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE3640A56, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_THERMAL_SETTINGS_V2 *))v4)(
                hPhysicalGpu,
                sensorIndex,
                pThermalSettings);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE3640A56, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6002
// RVA: 0xEAACA0
__int64 __fastcall NvAPI_GPU_SetDitherControl(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        unsigned int type,
        unsigned int bits,
        _NVAPI_DITHER_MODE mode)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_204 = 0i64;
  if ( !fp_204 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_204 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDF0DFCDD);
  if ( !fp_204 )
    return 4294967293i64;
  v6 = fp_204;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDF0DFCDD, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD, _QWORD, _NVAPI_DITHER_MODE))v6)(
                hPhysicalGpu,
                outputId,
                type,
                bits,
                mode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDF0DFCDD, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 6027
// RVA: 0xEAADF0
__int64 __fastcall NvAPI_GPU_GetDitherControl(unsigned int displayId, _NV_GPU_DITHER_CONTROL_V1 *pDitherData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_205 = 0i64;
  if ( !fp_205 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_205 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x932AC8FB);
  if ( !fp_205 )
    return 4294967293i64;
  v3 = fp_205;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x932AC8FB, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_GPU_DITHER_CONTROL_V1 *))v3)(displayId, pDitherData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x932AC8FB, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6052
// RVA: 0xEAAF20
__int64 __fastcall NvAPI_GPU_GetColorSpaceConversion(
        unsigned int displayId,
        _NV_GPU_COLORSPACE_CONVERSION_V1 *pColorData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_206 = 0i64;
  if ( !fp_206 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_206 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8159E87A);
  if ( !fp_206 )
    return 4294967293i64;
  v3 = fp_206;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8159E87A, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_GPU_COLORSPACE_CONVERSION_V1 *))v3)(displayId, pColorData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8159E87A, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6077
// RVA: 0xEAB050
__int64 __fastcall NvAPI_GPU_SetColorSpaceConversion(
        unsigned int displayId,
        _NV_GPU_COLORSPACE_CONVERSION_V1 *pColorData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_207 = 0i64;
  if ( !fp_207 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_207 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFCABD23A);
  if ( !fp_207 )
    return 4294967293i64;
  v3 = fp_207;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFCABD23A, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_GPU_COLORSPACE_CONVERSION_V1 *))v3)(displayId, pColorData);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFCABD23A, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6102
// RVA: 0xEAB180
__int64 __fastcall NvAPI_GetTVOutputInfo(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_DISPLAY_TV_OUTPUT_INFO *pTVOutInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_208 = 0i64;
  if ( !fp_208 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_208 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x30C805D5u);
  if ( !fp_208 )
    return 4294967293i64;
  v4 = fp_208;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x30C805D5u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_TV_OUTPUT_INFO *))v4)(
                hNvDisplay,
                outputId,
                pTVOutInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x30C805D5u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6127
// RVA: 0xEAB2B0
__int64 __fastcall NvAPI_GetTVEncoderControls(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_TV_ENCODER_CONTROLS *pTvEncoderInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_209 = 0i64;
  if ( !fp_209 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_209 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5757474Au);
  if ( !fp_209 )
    return 4294967293i64;
  v4 = fp_209;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5757474Au, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_TV_ENCODER_CONTROLS *))v4)(
                hNvDisplay,
                outputId,
                pTvEncoderInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5757474Au, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6152
// RVA: 0xEAB3E0
__int64 __fastcall NvAPI_SetTVEncoderControls(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_TV_ENCODER_CONTROLS *pTvEncoderInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_210 = 0i64;
  if ( !fp_210 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_210 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCA36A3AB);
  if ( !fp_210 )
    return 4294967293i64;
  v4 = fp_210;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCA36A3AB, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_TV_ENCODER_CONTROLS *))v4)(
                hNvDisplay,
                outputId,
                pTvEncoderInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCA36A3AB, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6177
// RVA: 0xEAB510
__int64 __fastcall NvAPI_GetTVOutputBorderColor(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        NV_TV_BORDER_COLOR *pBorderColor)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_211 = 0i64;
  if ( !fp_211 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_211 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6DFD1C8Cu);
  if ( !fp_211 )
    return 4294967293i64;
  v4 = fp_211;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6DFD1C8Cu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_TV_BORDER_COLOR *))v4)(
                hNvDisplay,
                outputId,
                pBorderColor);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6DFD1C8Cu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6202
// RVA: 0xEAB640
__int64 __fastcall NvAPI_SetTVOutputBorderColor(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int borderColor)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_212 = 0i64;
  if ( !fp_212 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_212 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAED02700);
  if ( !fp_212 )
    return 4294967293i64;
  v4 = fp_212;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAED02700, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(hNvDisplay, outputId, borderColor);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAED02700, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6227
// RVA: 0xEAB770
__int64 __fastcall NvAPI_GetDisplayPosition(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int *pXOffset,
        unsigned int *pYOffset)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_213 = 0i64;
  if ( !fp_213 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_213 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6BB1EE5Du);
  if ( !fp_213 )
    return 4294967293i64;
  v5 = fp_213;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6BB1EE5Du, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, unsigned int *, unsigned int *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                outputId,
                pXOffset,
                pYOffset,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6BB1EE5Du, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 6252
// RVA: 0xEAB8B0
__int64 __fastcall NvAPI_SetDisplayPosition(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int outputId,
        unsigned int xOffset,
        unsigned int yOffset)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_214 = 0i64;
  if ( !fp_214 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_214 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x57D9060Fu);
  if ( !fp_214 )
    return 4294967293i64;
  v5 = fp_214;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x57D9060Fu, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                outputId,
                xOffset,
                yOffset,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x57D9060Fu, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 6277
// RVA: 0xEAB9F0
__int64 __fastcall NvAPI_GetValidGpuTopologies(NV_GPU_TOPOLOGIES *pTopology, unsigned int *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_215 = 0i64;
  if ( !fp_215 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_215 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5DFAB48Au);
  if ( !fp_215 )
    return 4294967293i64;
  v3 = fp_215;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5DFAB48Au, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, unsigned int *))v3)(pTopology, pStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5DFAB48Au, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6302
// RVA: 0xEABB20
__int64 __fastcall NvAPI_GetInvalidGpuTopologies(NV_GPU_TOPOLOGIES *pTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_216 = 0i64;
  if ( !fp_216 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_216 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x15658BE6u);
  if ( !fp_216 )
    return 4294967293i64;
  v2 = fp_216;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x15658BE6u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *))v2)(pTopology);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x15658BE6u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 6327
// RVA: 0xEABC40
__int64 __fastcall NvAPI_SetGpuTopologies(NV_GPU_TOPOLOGIES *pTopology, unsigned int flags)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_217 = 0i64;
  if ( !fp_217 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_217 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x25201F3Du);
  if ( !fp_217 )
    return 4294967293i64;
  v3 = fp_217;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x25201F3Du, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, _QWORD))v3)(pTopology, flags);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x25201F3Du, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6352
// RVA: 0xEABD70
__int64 __fastcall NvAPI_GPU_GetPerGpuTopologyStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_218 = 0i64;
  if ( !fp_218 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_218 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA81F8992);
  if ( !fp_218 )
    return 4294967293i64;
  v3 = fp_218;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA81F8992, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA81F8992, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6377
// RVA: 0xEABEA0
__int64 __fastcall NvAPI_SYS_GetChipSetTopologyStatus(unsigned int *pStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_219 = 0i64;
  if ( !fp_219 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_219 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8A50F126);
  if ( !fp_219 )
    return 4294967293i64;
  v2 = fp_219;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8A50F126, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8A50F126, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 6402
// RVA: 0xEABFC0
__int64 __fastcall NvAPI_GPU_Get_DisplayPort_DongleInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_NVAPI_GET_DP_DONGLE_INFO *pDongleInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_220 = 0i64;
  if ( !fp_220 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_220 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x76A70E8Du);
  if ( !fp_220 )
    return 4294967293i64;
  v3 = fp_220;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x76A70E8Du, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_NVAPI_GET_DP_DONGLE_INFO *))v3)(
                hPhysicalGpu,
                pDongleInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x76A70E8Du, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6427
// RVA: 0xEAC0F0
__int64 __fastcall NvAPI_I2CRead(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_I2C_INFO_V2 *pI2cInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_221 = 0i64;
  if ( !fp_221 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_221 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2FDE12C5u);
  if ( !fp_221 )
    return 4294967293i64;
  v3 = fp_221;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2FDE12C5u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *))v3)(hPhysicalGpu, pI2cInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2FDE12C5u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6452
// RVA: 0xEAC220
__int64 __fastcall NvAPI_I2CWrite(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_I2C_INFO_V2 *pI2cInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_222 = 0i64;
  if ( !fp_222 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_222 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE812EB07);
  if ( !fp_222 )
    return 4294967293i64;
  v3 = fp_222;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE812EB07, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *))v3)(hPhysicalGpu, pI2cInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE812EB07, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6477
// RVA: 0xEAC350
__int64 __fastcall NvAPI_I2CWriteEx(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_I2C_INFO_V2 *pI2cInfo,
        NV_I2C_INFO_EX *pI2cInfoEx)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_223 = 0i64;
  if ( !fp_223 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_223 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x283AC65Au);
  if ( !fp_223 )
    return 4294967293i64;
  v4 = fp_223;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x283AC65Au, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *, NV_I2C_INFO_EX *))v4)(
                hPhysicalGpu,
                pI2cInfo,
                pI2cInfoEx);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x283AC65Au, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6502
// RVA: 0xEAC490
__int64 __fastcall NvAPI_I2CReadEx(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_I2C_INFO_V2 *pI2cInfo,
        NV_I2C_INFO_EX *pI2cInfoEx)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_224 = 0i64;
  if ( !fp_224 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_224 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4D7B0709u);
  if ( !fp_224 )
    return 4294967293i64;
  v4 = fp_224;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4D7B0709u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *, NV_I2C_INFO_EX *))v4)(
                hPhysicalGpu,
                pI2cInfo,
                pI2cInfoEx);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4D7B0709u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6527
// RVA: 0xEAC5D0
__int64 __fastcall NvAPI_GPU_GetPowerMizerInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int powerSourceInfo,
        unsigned int select,
        _NV_LEVEL_INFO *pLevelInfo)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_225 = 0i64;
  if ( !fp_225 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_225 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x76BFA16Bu);
  if ( !fp_225 )
    return 4294967293i64;
  v5 = fp_225;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x76BFA16Bu, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD, _NV_LEVEL_INFO *, __int64 (__fastcall *)()))v5)(
                hPhysicalGpu,
                powerSourceInfo,
                select,
                pLevelInfo,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x76BFA16Bu, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 6552
// RVA: 0xEAC710
__int64 __fastcall NvAPI_GPU_SetPowerMizerInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int powerSourceInfo,
        unsigned int select,
        unsigned int levelInfo)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_226 = 0i64;
  if ( !fp_226 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_226 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x50016C78u);
  if ( !fp_226 )
    return 4294967293i64;
  v5 = fp_226;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x50016C78u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                hPhysicalGpu,
                powerSourceInfo,
                select,
                levelInfo,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x50016C78u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 6577
// RVA: 0xEAC850
__int64 __fastcall NvAPI_GPU_GetVoltageDomainsStatus(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_VOLTAGE_DOMAINS_STATUS_V1 *pVoltageDomainsStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_227 = 0i64;
  if ( !fp_227 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_227 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC16C7E2C);
  if ( !fp_227 )
    return 4294967293i64;
  v3 = fp_227;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC16C7E2C, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_VOLTAGE_DOMAINS_STATUS_V1 *))v3)(
                hPhysicalGpu,
                pVoltageDomainsStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC16C7E2C, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6602
// RVA: 0xEAC980
__int64 __fastcall NvAPI_GPU_ClientPowerTopologyGetInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_CLIENT_POWER_TOPOLOGY_INFO_V1 *pClientPowerTopologyInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_228 = 0i64;
  if ( !fp_228 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_228 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA4DFD3F2);
  if ( !fp_228 )
    return 4294967293i64;
  v3 = fp_228;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA4DFD3F2, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_TOPOLOGY_INFO_V1 *))v3)(
                hPhysicalGpu,
                pClientPowerTopologyInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA4DFD3F2, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6627
// RVA: 0xEACAB0
__int64 __fastcall NvAPI_GPU_ClientPowerTopologyGetStatus(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_CLIENT_POWER_TOPOLOGY_STATUS_V1 *pClientPowerTopologyStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_229 = 0i64;
  if ( !fp_229 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_229 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEDCF624E);
  if ( !fp_229 )
    return 4294967293i64;
  v3 = fp_229;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEDCF624E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_TOPOLOGY_STATUS_V1 *))v3)(
                hPhysicalGpu,
                pClientPowerTopologyStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEDCF624E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6652
// RVA: 0xEACBE0
__int64 __fastcall NvAPI_GPU_ClientPowerPoliciesGetInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_CLIENT_POWER_POLICIES_INFO_V1 *pClientPowerPoliciesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_230 = 0i64;
  if ( !fp_230 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_230 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x34206D86u);
  if ( !fp_230 )
    return 4294967293i64;
  v3 = fp_230;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x34206D86u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_POLICIES_INFO_V1 *))v3)(
                hPhysicalGpu,
                pClientPowerPoliciesInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x34206D86u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6677
// RVA: 0xEACD10
__int64 __fastcall NvAPI_GPU_ClientPowerPoliciesGetStatus(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *pClientPowerPoliciesStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_231 = 0i64;
  if ( !fp_231 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_231 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x70916171u);
  if ( !fp_231 )
    return 4294967293i64;
  v3 = fp_231;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x70916171u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *))v3)(
                hPhysicalGpu,
                pClientPowerPoliciesStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x70916171u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6702
// RVA: 0xEACE40
__int64 __fastcall NvAPI_GPU_ClientPowerPoliciesSetStatus(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *pClientPowerPoliciesStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_232 = 0i64;
  if ( !fp_232 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_232 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAD95F5ED);
  if ( !fp_232 )
    return 4294967293i64;
  v3 = fp_232;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAD95F5ED, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *))v3)(
                hPhysicalGpu,
                pClientPowerPoliciesStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAD95F5ED, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 6727
// RVA: 0xEACF70
__int64 __fastcall NvAPI_GPU_WorkstationFeatureSetup(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int featureEnableMask,
        unsigned int featureDisableMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_233 = 0i64;
  if ( !fp_233 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_233 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6C1F3FE4u);
  if ( !fp_233 )
    return 4294967293i64;
  v4 = fp_233;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6C1F3FE4u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(
                hPhysicalGpu,
                featureEnableMask,
                featureDisableMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6C1F3FE4u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6752
// RVA: 0xEAD0A0
__int64 __fastcall NvAPI_SYS_GetChipSetInfo(NV_CHIPSET_INFO_v4 *pChipSetInfo)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_234 = 0i64;
  if ( !fp_234 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_234 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x53DABBCAu);
  if ( !fp_234 )
    return 4294967293i64;
  v2 = fp_234;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x53DABBCAu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_CHIPSET_INFO_v4 *))v2)(pChipSetInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x53DABBCAu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 6777
// RVA: 0xEAD1C0
__int64 __fastcall NvAPI_SYS_GetLidAndDockInfo(NV_LID_DOCK_PARAMS *pLidAndDock)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_235 = 0i64;
  if ( !fp_235 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_235 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDA14D8A);
  if ( !fp_235 )
    return 4294967293i64;
  v2 = fp_235;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDA14D8A, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_LID_DOCK_PARAMS *))v2)(pLidAndDock);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDA14D8A, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 6802
// RVA: 0xEAD2E0
__int64 __fastcall NvAPI_OGL_ExpertModeSet(
        unsigned int expertDetailLevel,
        unsigned int expertReportMask,
        unsigned int expertOutputMask,
        void (__fastcall *expertCallback)(unsigned int, unsigned int, unsigned int, int, const char *))
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_236 = 0i64;
  if ( !fp_236 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_236 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3805EF7Au);
  if ( !fp_236 )
    return 4294967293i64;
  v5 = fp_236;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3805EF7Au, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                expertDetailLevel,
                expertReportMask,
                expertOutputMask,
                expertCallback,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3805EF7Au, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 6827
// RVA: 0xEAD420
__int64 __fastcall NvAPI_OGL_ExpertModeGet(
        unsigned int *pExpertDetailLevel,
        unsigned int *pExpertReportMask,
        unsigned int *pExpertOutputMask,
        void (__fastcall **pExpertCallback)(unsigned int, unsigned int, unsigned int, int, const char *))
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_237 = 0i64;
  if ( !fp_237 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_237 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22ED9516u);
  if ( !fp_237 )
    return 4294967293i64;
  v5 = fp_237;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22ED9516u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, _QWORD, __int64 (__fastcall *)()))v5)(
                pExpertDetailLevel,
                pExpertReportMask,
                pExpertOutputMask,
                pExpertCallback,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22ED9516u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 6852
// RVA: 0xEAD560
__int64 __fastcall NvAPI_OGL_ExpertModeDefaultsSet(
        unsigned int expertDetailLevel,
        unsigned int expertReportMask,
        unsigned int expertOutputMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_238 = 0i64;
  if ( !fp_238 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_238 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB47A657E);
  if ( !fp_238 )
    return 4294967293i64;
  v4 = fp_238;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB47A657E, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD))v4)(
                expertDetailLevel,
                expertReportMask,
                expertOutputMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB47A657E, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6877
// RVA: 0xEAD690
__int64 __fastcall NvAPI_OGL_ExpertModeDefaultsGet(
        unsigned int *pExpertDetailLevel,
        unsigned int *pExpertReportMask,
        unsigned int *pExpertOutputMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_239 = 0i64;
  if ( !fp_239 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_239 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE921F12);
  if ( !fp_239 )
    return 4294967293i64;
  v4 = fp_239;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE921F12, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *))v4)(
                pExpertDetailLevel,
                pExpertReportMask,
                pExpertOutputMask);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE921F12, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6902
// RVA: 0xEAD7D0
__int64 __fastcall NvAPI_SetDisplaySettings(
        NvDisplayHandle__ *hNvDisplay,
        NV_DISP_PATH_V2 *paths,
        unsigned int pathCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_240 = 0i64;
  if ( !fp_240 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_240 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE04F3D86);
  if ( !fp_240 )
    return 4294967293i64;
  v4 = fp_240;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE04F3D86, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISP_PATH_V2 *, _QWORD))v4)(
                hNvDisplay,
                paths,
                pathCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE04F3D86, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6927
// RVA: 0xEAD910
__int64 __fastcall NvAPI_GetDisplaySettings(
        NvDisplayHandle__ *hNvDisplay,
        NV_DISP_PATH_V2 *pPaths,
        unsigned int *pPathCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_241 = 0i64;
  if ( !fp_241 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_241 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDC27D5D4);
  if ( !fp_241 )
    return 4294967293i64;
  v4 = fp_241;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDC27D5D4, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISP_PATH_V2 *, unsigned int *))v4)(
                hNvDisplay,
                pPaths,
                pPathCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDC27D5D4, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 6952
// RVA: 0xEADA50
__int64 __fastcall NvAPI_GetTiming(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int width,
        unsigned int height,
        float rr,
        NV_TIMING_FLAG *flag)
{
  __int64 (__fastcall *v6)(); // [rsp+40h] [rbp-48h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-40h] BYREF
  unsigned __int64 v8; // [rsp+50h] [rbp-38h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+58h] [rbp-30h]
  int v10; // [rsp+5Ch] [rbp-2Ch]
  char v11[12]; // [rsp+60h] [rbp-28h] BYREF

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_242 = 0i64;
  if ( !fp_242 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_242 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAFC4833E);
  if ( !fp_242 )
    return 4294967293i64;
  v6 = fp_242;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAFC4833E, &v8);
  qmemcpy(v11, flag, sizeof(v11));
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v6)(hNvDisplay, width, height);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAFC4833E, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 6977
// RVA: 0xEADBE0
__int64 __fastcall NvAPI_DISP_GetMonitorCapabilities(
        unsigned int displayId,
        _NV_MONITOR_CAPABILITIES *pMonitorCapabilities)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_243 = 0i64;
  if ( !fp_243 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_243 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3B05C7E1u);
  if ( !fp_243 )
    return 4294967293i64;
  v3 = fp_243;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3B05C7E1u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_MONITOR_CAPABILITIES *))v3)(displayId, pMonitorCapabilities);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3B05C7E1u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7002
// RVA: 0xEADD10
__int64 __fastcall NvAPI_EnumCustomDisplay(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int index,
        unsigned int outputId,
        NV_CUSTOM_DISPLAY *pC)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_244 = 0i64;
  if ( !fp_244 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_244 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x42892957u);
  if ( !fp_244 )
    return 4294967293i64;
  v5 = fp_244;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x42892957u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_CUSTOM_DISPLAY *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                index,
                outputId,
                pC,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x42892957u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 7027
// RVA: 0xEADE50
__int64 __fastcall NvAPI_TryCustomDisplay(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int *pDispOutputId,
        NV_CUSTOM_DISPLAY *pCustDisp,
        unsigned int count,
        unsigned int hwModeSetOnly)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_245 = 0i64;
  if ( !fp_245 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_245 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBF6C1762);
  if ( !fp_245 )
    return 4294967293i64;
  v6 = fp_245;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBF6C1762, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *, NV_CUSTOM_DISPLAY *, _QWORD, unsigned int))v6)(
                hNvDisplay,
                pDispOutputId,
                pCustDisp,
                count,
                hwModeSetOnly);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBF6C1762, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 7052
// RVA: 0xEADFA0
__int64 __fastcall NvAPI_RevertCustomDisplayTrial(NvDisplayHandle__ *hNvDisplay)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_246 = 0i64;
  if ( !fp_246 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_246 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x854BA405);
  if ( !fp_246 )
    return 4294967293i64;
  v2 = fp_246;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x854BA405, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *))v2)(hNvDisplay);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x854BA405, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 7077
// RVA: 0xEAE0C0
__int64 __fastcall NvAPI_DeleteCustomDisplay(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int displayOutputId,
        unsigned int index)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_247 = 0i64;
  if ( !fp_247 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_247 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE7CB998D);
  if ( !fp_247 )
    return 4294967293i64;
  v4 = fp_247;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE7CB998D, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(hNvDisplay, displayOutputId, index);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE7CB998D, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7102
// RVA: 0xEAE1F0
__int64 __fastcall NvAPI_SaveCustomDisplay(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int isThisOutputIdOnly,
        unsigned int isThisMonitorIdOnly)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_248 = 0i64;
  if ( !fp_248 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_248 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA9062C78);
  if ( !fp_248 )
    return 4294967293i64;
  v4 = fp_248;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA9062C78, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(
                hNvDisplay,
                isThisOutputIdOnly,
                isThisMonitorIdOnly);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA9062C78, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7127
// RVA: 0xEAE320
__int64 __fastcall NvAPI_QueryUnderscanCap(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int displayOutputId,
        NV_UNDERSCAN_CAP *cap)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_249 = 0i64;
  if ( !fp_249 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_249 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x61D7B624u);
  if ( !fp_249 )
    return 4294967293i64;
  v4 = fp_249;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x61D7B624u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_UNDERSCAN_CAP *))v4)(
                hNvDisplay,
                displayOutputId,
                cap);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x61D7B624u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7152
// RVA: 0xEAE450
__int64 __fastcall NvAPI_EnumUnderscanConfig(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int displayOutputId,
        unsigned int index,
        NV_UNDERSCAN_CONFIG *config)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_250 = 0i64;
  if ( !fp_250 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_250 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4144111Au);
  if ( !fp_250 )
    return 4294967293i64;
  v5 = fp_250;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4144111Au, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_UNDERSCAN_CONFIG *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                displayOutputId,
                index,
                config,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4144111Au, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 7177
// RVA: 0xEAE590
__int64 __fastcall NvAPI_DeleteUnderscanConfig(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int displayOutputId,
        unsigned int index)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_251 = 0i64;
  if ( !fp_251 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_251 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF98854C8);
  if ( !fp_251 )
    return 4294967293i64;
  v4 = fp_251;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF98854C8, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(hNvDisplay, displayOutputId, index);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF98854C8, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7202
// RVA: 0xEAE6C0
__int64 __fastcall NvAPI_SetUnderscanConfig(
        NvDisplayHandle__ *hNvDisplay,
        unsigned int displayOutputId,
        NV_UNDERSCAN_CONFIG *config,
        unsigned int setDeferred)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_252 = 0i64;
  if ( !fp_252 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_252 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3EFADA1Du);
  if ( !fp_252 )
    return 4294967293i64;
  v5 = fp_252;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3EFADA1Du, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_UNDERSCAN_CONFIG *, _QWORD, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                displayOutputId,
                config,
                setDeferred,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3EFADA1Du, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 7227
// RVA: 0xEAE800
__int64 __fastcall NvAPI_GetDisplayFeatureConfig(NvDisplayHandle__ *hNvDisplay, _NV_DISPLAY_FEATURE *pFeature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_253 = 0i64;
  if ( !fp_253 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_253 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8E985CCD);
  if ( !fp_253 )
    return 4294967293i64;
  v3 = fp_253;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8E985CCD, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_DISPLAY_FEATURE *))v3)(hNvDisplay, pFeature);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8E985CCD, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7252
// RVA: 0xEAE930
__int64 __fastcall NvAPI_SetDisplayFeatureConfig(NvDisplayHandle__ *hNvDisplay, _NV_DISPLAY_FEATURE feature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_254 = 0i64;
  if ( !fp_254 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_254 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF36A668D);
  if ( !fp_254 )
    return 4294967293i64;
  v3 = fp_254;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF36A668D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD))v3)(hNvDisplay, *(unsigned int *)&feature);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF36A668D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7277
// RVA: 0xEAEA60
__int64 __fastcall NvAPI_GetDisplayFeatureConfigDefaults(NvDisplayHandle__ *hNvDisplay, _NV_DISPLAY_FEATURE *pFeature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_255 = 0i64;
  if ( !fp_255 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_255 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5F4D01u);
  if ( !fp_255 )
    return 4294967293i64;
  v3 = fp_255;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5F4D01u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_DISPLAY_FEATURE *))v3)(hNvDisplay, pFeature);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5F4D01u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7302
// RVA: 0xEAEB90
__int64 __fastcall NvAPI_SetView(
        NvDisplayHandle__ *hNvDisplay,
        NV_VIEW_TARGET_INFO *pTargetInfo,
        unsigned int targetView)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_256 = 0i64;
  if ( !fp_256 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_256 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x957D7B6u);
  if ( !fp_256 )
    return 4294967293i64;
  v4 = fp_256;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x957D7B6u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_VIEW_TARGET_INFO *, _QWORD))v4)(
                hNvDisplay,
                pTargetInfo,
                targetView);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x957D7B6u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7327
// RVA: 0xEAECD0
__int64 __fastcall NvAPI_GetView(
        NvDisplayHandle__ *hNvDisplay,
        NV_VIEW_TARGET_INFO *pTargets,
        unsigned int *pTargetMaskCount,
        _NV_TARGET_VIEW_MODE *pTargetView)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_257 = 0i64;
  if ( !fp_257 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_257 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD6B99D89);
  if ( !fp_257 )
    return 4294967293i64;
  v5 = fp_257;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD6B99D89, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_VIEW_TARGET_INFO *, unsigned int *, _NV_TARGET_VIEW_MODE *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                pTargets,
                pTargetMaskCount,
                pTargetView,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD6B99D89, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 7352
// RVA: 0xEAEE10
__int64 __fastcall NvAPI_SetViewEx(
        NvDisplayHandle__ *hNvDisplay,
        NV_DISPLAY_PATH_INFO *pPathInfo,
        unsigned int displayView)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_258 = 0i64;
  if ( !fp_258 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_258 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6B89E68u);
  if ( !fp_258 )
    return 4294967293i64;
  v4 = fp_258;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6B89E68u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_PATH_INFO *, _QWORD))v4)(
                hNvDisplay,
                pPathInfo,
                displayView);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6B89E68u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7377
// RVA: 0xEAEF50
__int64 __fastcall NvAPI_GetViewEx(
        NvDisplayHandle__ *hNvDisplay,
        NV_DISPLAY_PATH_INFO *pPathInfo,
        unsigned int *pPathCount,
        _NV_TARGET_VIEW_MODE *pTargetViewMode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_259 = 0i64;
  if ( !fp_259 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_259 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDBBC0AF4);
  if ( !fp_259 )
    return 4294967293i64;
  v5 = fp_259;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDBBC0AF4, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_PATH_INFO *, unsigned int *, _NV_TARGET_VIEW_MODE *, __int64 (__fastcall *)()))v5)(
                hNvDisplay,
                pPathInfo,
                pPathCount,
                pTargetViewMode,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDBBC0AF4, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 7402
// RVA: 0xEAF090
__int64 __fastcall NvAPI_GetSupportedViews(
        NvDisplayHandle__ *hNvDisplay,
        _NV_TARGET_VIEW_MODE *pTargetViews,
        unsigned int *pViewCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_260 = 0i64;
  if ( !fp_260 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_260 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x66FB7FC0u);
  if ( !fp_260 )
    return 4294967293i64;
  v4 = fp_260;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x66FB7FC0u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_TARGET_VIEW_MODE *, unsigned int *))v4)(
                hNvDisplay,
                pTargetViews,
                pViewCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x66FB7FC0u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7427
// RVA: 0xEAF1D0
__int64 __fastcall NvAPI_GetHDCPLinkParameters(NvDisplayHandle__ *hNvDisplay, NV_HDCP_INFO *pNvHdcpInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_261 = 0i64;
  if ( !fp_261 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_261 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB3BB0772);
  if ( !fp_261 )
    return 4294967293i64;
  v3 = fp_261;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB3BB0772, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_HDCP_INFO *))v3)(hNvDisplay, pNvHdcpInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB3BB0772, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7452
// RVA: 0xEAF300
__int64 __fastcall NvAPI_Disp_DpAuxChannelControl(
        NvDisplayHandle__ *hNvDisplay,
        _NV_DPCD_PARAMS *pDpcdParams,
        unsigned int reserved)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_262 = 0i64;
  if ( !fp_262 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_262 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8EB56969);
  if ( !fp_262 )
    return 4294967293i64;
  v4 = fp_262;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8EB56969, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_DPCD_PARAMS *, _QWORD))v4)(
                hNvDisplay,
                pDpcdParams,
                reserved);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8EB56969, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7477
// RVA: 0xEAF440
__int64 __fastcall NvAPI_SetHybridMode(unsigned int mode)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_263 = 0i64;
  if ( !fp_263 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_263 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFB22D656);
  if ( !fp_263 )
    return 4294967293i64;
  v2 = fp_263;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFB22D656, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(mode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFB22D656, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 7502
// RVA: 0xEAF560
__int64 __fastcall NvAPI_GetHybridMode(_NV_HYBRID_MODE *pMode)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_264 = 0i64;
  if ( !fp_264 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_264 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE23B68C1);
  if ( !fp_264 )
    return 4294967293i64;
  v2 = fp_264;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE23B68C1, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NV_HYBRID_MODE *))v2)(pMode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE23B68C1, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 7527
// RVA: 0xEAF680
__int64 __fastcall NvAPI_Coproc_GetCoprocStatus(unsigned int *pCoprocStatus, NV_COPROC_STATE *pCoprocState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_265 = 0i64;
  if ( !fp_265 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_265 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1EFC3957u);
  if ( !fp_265 )
    return 4294967293i64;
  v3 = fp_265;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1EFC3957u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, NV_COPROC_STATE *))v3)(pCoprocStatus, pCoprocState);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1EFC3957u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7552
// RVA: 0xEAF7B0
__int64 __fastcall NvAPI_Coproc_SetCoprocInfoFlagsEx(NV_COPROC_FLAGS_EX *coprocInfoExFlags)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_266 = 0i64;
  if ( !fp_266 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_266 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF4C863AC);
  if ( !fp_266 )
    return 4294967293i64;
  v2 = fp_266;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF4C863AC, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_COPROC_FLAGS_EX *))v2)(coprocInfoExFlags);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF4C863AC, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 7577
// RVA: 0xEAF8D0
__int64 __fastcall NvAPI_Coproc_GetCoprocInfoFlagsEx(NV_COPROC_FLAGS_EX *coprocInfoExFlags)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_267 = 0i64;
  if ( !fp_267 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_267 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x69A9874Du);
  if ( !fp_267 )
    return 4294967293i64;
  v2 = fp_267;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x69A9874Du, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_COPROC_FLAGS_EX *))v2)(coprocInfoExFlags);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x69A9874Du, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 7602
// RVA: 0xEAF9F0
__int64 __fastcall NvAPI_Coproc_NotifyCoprocPowerState(
        unsigned int IsSafetoPowerOff,
        unsigned __int64 SequenceNumber,
        unsigned int *pStatus)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_268 = 0i64;
  if ( !fp_268 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_268 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCADCB956);
  if ( !fp_268 )
    return 4294967293i64;
  v4 = fp_268;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCADCB956, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, unsigned __int64, unsigned int *))v4)(
                IsSafetoPowerOff,
                SequenceNumber,
                pStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCADCB956, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 7627
// RVA: 0xEAFB20
__int64 __fastcall NvAPI_Coproc_GetApplicationCoprocInfo(NV_COPROC_APP_INFO *pCoprocAppInfo)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_269 = 0i64;
  if ( !fp_269 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_269 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x79232685u);
  if ( !fp_269 )
    return 4294967293i64;
  v2 = fp_269;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x79232685u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_COPROC_APP_INFO *))v2)(pCoprocAppInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x79232685u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 7652
// RVA: 0xEAFC40
__int64 __fastcall NvAPI_GetVideoState(
        NvDisplayHandle__ *hNvDisplay,
        _NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_270 = 0i64;
  if ( !fp_270 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_270 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1C5659CDu);
  if ( !fp_270 )
    return 4294967293i64;
  v3 = fp_270;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1C5659CDu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NVAPI_GET_VIDEO_STATE_COMPONENT *))v3)(
                hNvDisplay,
                pGetVidStateComp);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1C5659CDu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7677
// RVA: 0xEAFD70
__int64 __fastcall NvAPI_SetVideoState(
        NvDisplayHandle__ *hNvDisplay,
        _NVAPI_SET_VIDEO_STATE_COMPONENT *pSetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_271 = 0i64;
  if ( !fp_271 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_271 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x54FE75Au);
  if ( !fp_271 )
    return 4294967293i64;
  v3 = fp_271;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x54FE75Au, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NVAPI_SET_VIDEO_STATE_COMPONENT *))v3)(
                hNvDisplay,
                pSetVidStateComp);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x54FE75Au, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7702
// RVA: 0xEAFEA0
__int64 __fastcall NvAPI_SetFrameRateNotify(
        NvDisplayHandle__ *hNvDisplay,
        _NVAPI_FRAME_RATE_NOTIFY_INFO *pFRNotifyInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_272 = 0i64;
  if ( !fp_272 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_272 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x18919887u);
  if ( !fp_272 )
    return 4294967293i64;
  v3 = fp_272;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x18919887u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NVAPI_FRAME_RATE_NOTIFY_INFO *))v3)(
                hNvDisplay,
                pFRNotifyInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x18919887u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7727
// RVA: 0xEAFFD0
__int64 __fastcall NvAPI_SetPVExtName(NvDisplayHandle__ *hNvDisplay, const char *szDllName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_273 = 0i64;
  if ( !fp_273 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_273 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4FEEB498u);
  if ( !fp_273 )
    return 4294967293i64;
  v3 = fp_273;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4FEEB498u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, const char *))v3)(hNvDisplay, szDllName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4FEEB498u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7752
// RVA: 0xEB0100
__int64 __fastcall NvAPI_GetPVExtName(NvDisplayHandle__ *hNvDisplay, char *szDllName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_274 = 0i64;
  if ( !fp_274 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_274 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2F5B08E0u);
  if ( !fp_274 )
    return 4294967293i64;
  v3 = fp_274;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2F5B08E0u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, char *))v3)(hNvDisplay, szDllName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2F5B08E0u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7777
// RVA: 0xEB0230
__int64 __fastcall NvAPI_SetPVExtProfile(NvDisplayHandle__ *hNvDisplay, unsigned int dwProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_275 = 0i64;
  if ( !fp_275 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_275 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8354A8F4);
  if ( !fp_275 )
    return 4294967293i64;
  v3 = fp_275;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8354A8F4, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD))v3)(hNvDisplay, dwProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8354A8F4, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7802
// RVA: 0xEB0360
__int64 __fastcall NvAPI_GetPVExtProfile(NvDisplayHandle__ *hNvDisplay, unsigned int *pProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_276 = 0i64;
  if ( !fp_276 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_276 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1B1B9A16u);
  if ( !fp_276 )
    return 4294967293i64;
  v3 = fp_276;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1B1B9A16u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *))v3)(hNvDisplay, pProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1B1B9A16u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7827
// RVA: 0xEB0490
__int64 __fastcall NvAPI_VideoSetStereoInfo(NvDisplayHandle__ *hNvDisplay, _NV_VIDEO_STEREO_INFO *pStereoInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_277 = 0i64;
  if ( !fp_277 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_277 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x97063269);
  if ( !fp_277 )
    return 4294967293i64;
  v3 = fp_277;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x97063269, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_VIDEO_STEREO_INFO *))v3)(hNvDisplay, pStereoInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x97063269, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7852
// RVA: 0xEB05C0
__int64 __fastcall NvAPI_VideoGetStereoInfo(NvDisplayHandle__ *hNvDisplay, _NV_VIDEO_STEREO_INFO *pStereoInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_278 = 0i64;
  if ( !fp_278 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_278 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8E1F8CFE);
  if ( !fp_278 )
    return 4294967293i64;
  v3 = fp_278;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8E1F8CFE, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_VIDEO_STEREO_INFO *))v3)(hNvDisplay, pStereoInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8E1F8CFE, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7877
// RVA: 0xEB06F0
__int64 __fastcall NvAPI_Mosaic_GetSupportedTopoInfo(
        NV_MOSAIC_SUPPORTED_TOPO_INFO *pSupportedTopoInfo,
        unsigned int type)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_279 = 0i64;
  if ( !fp_279 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_279 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFDB63C81);
  if ( !fp_279 )
    return 4294967293i64;
  v3 = fp_279;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFDB63C81, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_SUPPORTED_TOPO_INFO *, _QWORD))v3)(pSupportedTopoInfo, type);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFDB63C81, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7902
// RVA: 0xEB0820
__int64 __fastcall NvAPI_Mosaic_GetTopoGroup(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_TOPO_GROUP *pTopoGroup)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_280 = 0i64;
  if ( !fp_280 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_280 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCB89381D);
  if ( !fp_280 )
    return 4294967293i64;
  v3 = fp_280;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCB89381D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_TOPO_GROUP *))v3)(pTopoBrief, pTopoGroup);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCB89381D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 7927
// RVA: 0xEB0950
__int64 __fastcall NvAPI_Mosaic_GetOverlapLimits(
        NV_MOSAIC_TOPO_BRIEF *pTopoBrief,
        NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting,
        int *pMinOverlapX,
        int *pMaxOverlapX,
        int *pMinOverlapY,
        int *pMaxOverlapY)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_281 = 0i64;
  if ( !fp_281 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_281 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x989685F0);
  if ( !fp_281 )
    return 4294967293i64;
  v7 = fp_281;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x989685F0, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_DISPLAY_SETTING *, int *, int *, int *, int *, __int64 (__fastcall *)()))v7)(
                pTopoBrief,
                pDisplaySetting,
                pMinOverlapX,
                pMaxOverlapX,
                pMinOverlapY,
                pMaxOverlapY,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x989685F0, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 7952
// RVA: 0xEB0AB0
__int64 __fastcall NvAPI_Mosaic_SetCurrentTopo(
        NV_MOSAIC_TOPO_BRIEF *pTopoBrief,
        NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting,
        unsigned int overlapX,
        unsigned int overlapY,
        unsigned int enable)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_282 = 0i64;
  if ( !fp_282 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_282 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9B542831);
  if ( !fp_282 )
    return 4294967293i64;
  v6 = fp_282;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9B542831, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_DISPLAY_SETTING *, _QWORD, _QWORD, unsigned int))v6)(
                pTopoBrief,
                pDisplaySetting,
                overlapX,
                overlapY,
                enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9B542831, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 7977
// RVA: 0xEB0C00
__int64 __fastcall NvAPI_Mosaic_GetCurrentTopo(
        NV_MOSAIC_TOPO_BRIEF *pTopoBrief,
        NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting,
        int *pOverlapX,
        int *pOverlapY)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_283 = 0i64;
  if ( !fp_283 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_283 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEC32944E);
  if ( !fp_283 )
    return 4294967293i64;
  v5 = fp_283;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEC32944E, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_DISPLAY_SETTING *, int *, int *, __int64 (__fastcall *)()))v5)(
                pTopoBrief,
                pDisplaySetting,
                pOverlapX,
                pOverlapY,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEC32944E, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 8002
// RVA: 0xEB0D40
__int64 __fastcall NvAPI_Mosaic_EnableCurrentTopo(unsigned int enable)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_284 = 0i64;
  if ( !fp_284 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_284 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F1AA66Cu);
  if ( !fp_284 )
    return 4294967293i64;
  v2 = fp_284;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F1AA66Cu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F1AA66Cu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8027
// RVA: 0xEB0E60
__int64 __fastcall NvAPI_Mosaic_SetGridTopology(NV_MOSAIC_GRID_TOPO *pGridTopology, unsigned int enable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_285 = 0i64;
  if ( !fp_285 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_285 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3F113C77u);
  if ( !fp_285 )
    return 4294967293i64;
  v3 = fp_285;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3F113C77u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD))v3)(pGridTopology, enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3F113C77u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8052
// RVA: 0xEB0F90
__int64 __fastcall NvAPI_Mosaic_GetMosaicCapabilities(NV_GPU_TOPOLOGIES *pSliTopology, NV_MOSAIC_CAPS_V2 *pCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_286 = 0i64;
  if ( !fp_286 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_286 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA97071E);
  if ( !fp_286 )
    return 4294967293i64;
  v3 = fp_286;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA97071E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, NV_MOSAIC_CAPS_V2 *))v3)(pSliTopology, pCaps);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA97071E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8077
// RVA: 0xEB10C0
__int64 __fastcall NvAPI_Mosaic_GetDisplayCapabilities(NV_MOSAIC_DISPLAY_CAPS_V2 *pDisplayCaps)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_287 = 0i64;
  if ( !fp_287 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_287 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD58026B9);
  if ( !fp_287 )
    return 4294967293i64;
  v2 = fp_287;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD58026B9, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_DISPLAY_CAPS_V2 *))v2)(pDisplayCaps);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD58026B9, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8102
// RVA: 0xEB11E0
__int64 __fastcall NvAPI_Mosaic_EnumGridTopologies(
        unsigned int index,
        unsigned int flags,
        NV_MOSAIC_GRID_TOPO *pGridTopology,
        char *bEnabled)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_288 = 0i64;
  if ( !fp_288 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_288 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA3C55220);
  if ( !fp_288 )
    return 4294967293i64;
  v5 = fp_288;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA3C55220, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, NV_MOSAIC_GRID_TOPO *, char *, __int64 (__fastcall *)()))v5)(
                index,
                flags,
                pGridTopology,
                bEnabled,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA3C55220, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 8127
// RVA: 0xEB1320
__int64 __fastcall NvAPI_Mosaic_GetDisplayViewportsByResolution(
        unsigned int displayId,
        unsigned int srcWidth,
        unsigned int srcHeight,
        _NV_RECT *viewports,
        char *bezelCorrected)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_289 = 0i64;
  if ( !fp_289 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_289 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDC6DC8D3);
  if ( !fp_289 )
    return 4294967293i64;
  v6 = fp_289;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDC6DC8D3, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD, _NV_RECT *, char *))v6)(
                displayId,
                srcWidth,
                srcHeight,
                viewports,
                bezelCorrected);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDC6DC8D3, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 8152
// RVA: 0xEB1470
__int64 __fastcall NvAPI_Mosaic_GetMosaicViewports(
        NV_MOSAIC_GRID_TOPO *pGridTopology,
        unsigned int baseWidth,
        unsigned int baseHeight,
        unsigned __int8 bezelCorrected,
        unsigned int *totalWidth,
        unsigned int *totalHeight,
        _NV_RECT *viewports)
{
  __int64 (__fastcall *v8)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h] BYREF
  unsigned __int64 v10; // [rsp+50h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+58h] [rbp-10h]
  int v12; // [rsp+5Ch] [rbp-Ch]

  hMod = 0i64;
  v12 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_290 = 0i64;
  if ( !fp_290 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_290 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7EBA036u);
  if ( !fp_290 )
    return 4294967293i64;
  v8 = fp_290;
  v10 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7EBA036u, &v10);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD, _QWORD, _QWORD, unsigned int *, unsigned int *, _NV_RECT *))v8)(
                pGridTopology,
                baseWidth,
                baseHeight,
                bezelCorrected,
                totalWidth,
                totalHeight,
                viewports);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7EBA036u, v10, GpuHandle);
  --g_module_numApiInUse[v12];
  return (unsigned int)GpuHandle;
}

// File Line: 8177
// RVA: 0xEB15E0
__int64 __fastcall NvAPI_Mosaic_SetDisplayGrids(
        NV_MOSAIC_GRID_TOPO *pGridTopologies,
        unsigned int gridCount,
        unsigned int setTopoFlags)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_291 = 0i64;
  if ( !fp_291 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_291 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4D959A89u);
  if ( !fp_291 )
    return 4294967293i64;
  v4 = fp_291;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4D959A89u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD, _QWORD))v4)(
                pGridTopologies,
                gridCount,
                setTopoFlags);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4D959A89u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 8202
// RVA: 0xEB1710
__int64 __fastcall NvAPI_Mosaic_ValidateDisplayGridsWithSLI(
        NV_GPU_TOPOLOGIES *pGpuTopologies,
        NV_MOSAIC_GRID_TOPO *pGridTopologies,
        NV_MOSAIC_DISPLAY_TOPO_STATUS *pTopoStatus,
        unsigned int gridCount)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_292 = 0i64;
  if ( !fp_292 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_292 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1ECFD263u);
  if ( !fp_292 )
    return 4294967293i64;
  v5 = fp_292;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1ECFD263u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, NV_MOSAIC_GRID_TOPO *, NV_MOSAIC_DISPLAY_TOPO_STATUS *, _QWORD, __int64 (__fastcall *)()))v5)(
                pGpuTopologies,
                pGridTopologies,
                pTopoStatus,
                gridCount,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1ECFD263u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 8227
// RVA: 0xEB1850
__int64 __fastcall NvAPI_Mosaic_ValidateDisplayGrids(
        unsigned int setTopoFlags,
        NV_MOSAIC_GRID_TOPO *pGridTopologies,
        NV_MOSAIC_DISPLAY_TOPO_STATUS *pTopoStatus,
        unsigned int gridCount)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_293 = 0i64;
  if ( !fp_293 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_293 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCF43903D);
  if ( !fp_293 )
    return 4294967293i64;
  v5 = fp_293;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCF43903D, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NV_MOSAIC_GRID_TOPO *, NV_MOSAIC_DISPLAY_TOPO_STATUS *, _QWORD, __int64 (__fastcall *)()))v5)(
                setTopoFlags,
                pGridTopologies,
                pTopoStatus,
                gridCount,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCF43903D, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 8252
// RVA: 0xEB1990
__int64 __fastcall NvAPI_Mosaic_EnumDisplayModes(
        NV_MOSAIC_GRID_TOPO *pGridTopology,
        NV_MOSAIC_DISPLAY_SETTING *pDisplaySettings,
        unsigned int *pDisplayCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_294 = 0i64;
  if ( !fp_294 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_294 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x78DB97D7u);
  if ( !fp_294 )
    return 4294967293i64;
  v4 = fp_294;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x78DB97D7u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, NV_MOSAIC_DISPLAY_SETTING *, unsigned int *))v4)(
                pGridTopology,
                pDisplaySettings,
                pDisplayCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x78DB97D7u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 8277
// RVA: 0xEB1AD0
__int64 __fastcall NvAPI_Mosaic_ChooseGpuTopologies(
        NV_MOSAIC_GRID_TOPO *pGridTopologies,
        unsigned int gridCount,
        unsigned int setTopoFlags,
        NV_GPU_TOPOLOGIES *pGpuTopologies)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_295 = 0i64;
  if ( !fp_295 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_295 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB033B140);
  if ( !fp_295 )
    return 4294967293i64;
  v5 = fp_295;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB033B140, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD, _QWORD, NV_GPU_TOPOLOGIES *, __int64 (__fastcall *)()))v5)(
                pGridTopologies,
                gridCount,
                setTopoFlags,
                pGpuTopologies,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB033B140, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 8302
// RVA: 0xEB1C10
__int64 __fastcall NvAPI_Mosaic_EnumDisplayGrids(NV_MOSAIC_GRID_TOPO *pGridTopologies, unsigned int *pGridCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_296 = 0i64;
  if ( !fp_296 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_296 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDF2887AF);
  if ( !fp_296 )
    return 4294967293i64;
  v3 = fp_296;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDF2887AF, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, unsigned int *))v3)(pGridTopologies, pGridCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDF2887AF, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8327
// RVA: 0xEB1D40
__int64 __fastcall NvAPI_GetSupportedMosaicTopologies(NV_MOSAIC_SUPPORTED_TOPOLOGIES *pMosaicTopos)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_297 = 0i64;
  if ( !fp_297 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_297 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x410B5C25u);
  if ( !fp_297 )
    return 4294967293i64;
  v2 = fp_297;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x410B5C25u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_SUPPORTED_TOPOLOGIES *))v2)(pMosaicTopos);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x410B5C25u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8352
// RVA: 0xEB1E60
__int64 __fastcall NvAPI_GetCurrentMosaicTopology(NV_MOSAIC_TOPOLOGY *pMosaicTopo, unsigned int *pEnabled)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_298 = 0i64;
  if ( !fp_298 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_298 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF60852BD);
  if ( !fp_298 )
    return 4294967293i64;
  v3 = fp_298;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF60852BD, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPOLOGY *, unsigned int *))v3)(pMosaicTopo, pEnabled);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF60852BD, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8377
// RVA: 0xEB1F90
__int64 __fastcall NvAPI_SetCurrentMosaicTopology(NV_MOSAIC_TOPOLOGY *pMosaicTopo)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_299 = 0i64;
  if ( !fp_299 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_299 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD54B8989);
  if ( !fp_299 )
    return 4294967293i64;
  v2 = fp_299;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD54B8989, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPOLOGY *))v2)(pMosaicTopo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD54B8989, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8402
// RVA: 0xEB20B0
__int64 __fastcall NvAPI_EnableCurrentMosaicTopology(unsigned int enable)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_300 = 0i64;
  if ( !fp_300 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_300 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x74073CC9u);
  if ( !fp_300 )
    return 4294967293i64;
  v2 = fp_300;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x74073CC9u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x74073CC9u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8427
// RVA: 0xEB21D0
__int64 __fastcall NvAPI_QueryNonMigratableApps(NV_3D_APP_INFO_V2 *apps, unsigned int *total)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_301 = 0i64;
  if ( !fp_301 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_301 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBB9EF1C3);
  if ( !fp_301 )
    return 4294967293i64;
  v3 = fp_301;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBB9EF1C3, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_3D_APP_INFO_V2 *, unsigned int *))v3)(apps, total);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBB9EF1C3, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8452
// RVA: 0xEB2300
__int64 __fastcall NvAPI_GPU_QueryActiveApps(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_3D_APP_INFO_V2 *apps,
        unsigned int *total)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_302 = 0i64;
  if ( !fp_302 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_302 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x65B1C5F5u);
  if ( !fp_302 )
    return 4294967293i64;
  v4 = fp_302;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x65B1C5F5u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_3D_APP_INFO_V2 *, unsigned int *))v4)(
                hPhysicalGpu,
                apps,
                total);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x65B1C5F5u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 8477
// RVA: 0xEB2440
__int64 __fastcall NvAPI_Hybrid_QueryUnblockedNonMigratableApps(NV_HYBRID_APP_INFO *apps, unsigned int *total)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_303 = 0i64;
  if ( !fp_303 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_303 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F35BCB5u);
  if ( !fp_303 )
    return 4294967293i64;
  v3 = fp_303;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F35BCB5u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_HYBRID_APP_INFO *, unsigned int *))v3)(apps, total);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F35BCB5u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8502
// RVA: 0xEB2570
__int64 __fastcall NvAPI_Hybrid_QueryBlockedMigratableApps(NV_HYBRID_APP_INFO *apps, unsigned int *total)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_304 = 0i64;
  if ( !fp_304 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_304 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF4C2F8CC);
  if ( !fp_304 )
    return 4294967293i64;
  v3 = fp_304;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF4C2F8CC, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_HYBRID_APP_INFO *, unsigned int *))v3)(apps, total);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF4C2F8CC, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8527
// RVA: 0xEB26A0
__int64 __fastcall NvAPI_Hybrid_SetAppMigrationState(NV_HYBRID_APP_INFO *app, unsigned int flag)
{
  __int64 (__fastcall *v3)(); // [rsp+28h] [rbp-250h]
  HINSTANCE__ *hMod; // [rsp+30h] [rbp-248h] BYREF
  unsigned __int64 v5; // [rsp+38h] [rbp-240h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+40h] [rbp-238h]
  int v7; // [rsp+44h] [rbp-234h]
  char v8[552]; // [rsp+50h] [rbp-228h] BYREF

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_305 = 0i64;
  if ( !fp_305 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_305 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA0B9A59);
  if ( !fp_305 )
    return 4294967293i64;
  v3 = fp_305;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA0B9A59, &v5);
  qmemcpy(v8, app, 0x204ui64);
  GpuHandle = ((unsigned int (__fastcall *)(char *, _QWORD))v3)(v8, flag);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA0B9A59, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8552
// RVA: 0xEB27F0
__int64 __fastcall NvAPI_Hybrid_IsAppMigrationStateChangeable(NV_HYBRID_APP_INFO *app, unsigned int *allowed)
{
  __int64 (__fastcall *v3)(); // [rsp+28h] [rbp-250h]
  HINSTANCE__ *hMod; // [rsp+30h] [rbp-248h] BYREF
  unsigned __int64 v5; // [rsp+38h] [rbp-240h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+40h] [rbp-238h]
  int v7; // [rsp+44h] [rbp-234h]
  char v8[552]; // [rsp+50h] [rbp-228h] BYREF

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_306 = 0i64;
  if ( !fp_306 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_306 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x584CB0B6u);
  if ( !fp_306 )
    return 4294967293i64;
  v3 = fp_306;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x584CB0B6u, &v5);
  qmemcpy(v8, app, 0x204ui64);
  GpuHandle = ((unsigned int (__fastcall *)(char *, unsigned int *))v3)(v8, allowed);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x584CB0B6u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8577
// RVA: 0xEB2940
__int64 __fastcall NvAPI_GPU_GPIOQueryLegalPins(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_GPIO_LEGAL_PINS *pgpioLegalPins)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_307 = 0i64;
  if ( !fp_307 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_307 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFAB69565);
  if ( !fp_307 )
    return 4294967293i64;
  v3 = fp_307;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFAB69565, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GPIO_LEGAL_PINS *))v3)(
                hPhysicalGpu,
                pgpioLegalPins);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFAB69565, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8602
// RVA: 0xEB2A70
__int64 __fastcall NvAPI_GPU_GPIOReadFromPin(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_GPIO_PIN_DATA *pgpioReadPin)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_308 = 0i64;
  if ( !fp_308 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_308 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5E10439);
  if ( !fp_308 )
    return 4294967293i64;
  v3 = fp_308;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5E10439, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GPIO_PIN_DATA *))v3)(
                hPhysicalGpu,
                pgpioReadPin);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5E10439, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8627
// RVA: 0xEB2BA0
__int64 __fastcall NvAPI_GPU_GPIOWriteToPin(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_GPIO_PIN_DATA *pgpioWritePin)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_309 = 0i64;
  if ( !fp_309 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_309 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF3B11E68);
  if ( !fp_309 )
    return 4294967293i64;
  v3 = fp_309;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF3B11E68, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GPIO_PIN_DATA *))v3)(
                hPhysicalGpu,
                pgpioWritePin);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF3B11E68, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8652
// RVA: 0xEB2CD0
__int64 __fastcall NvAPI_GPU_GetHDCPSupportStatus(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_GET_HDCP_SUPPORT_STATUS *pGetHDCPSupportStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_310 = 0i64;
  if ( !fp_310 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_310 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF089EEF5);
  if ( !fp_310 )
    return 4294967293i64;
  v3 = fp_310;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF089EEF5, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GET_HDCP_SUPPORT_STATUS *))v3)(
                hPhysicalGpu,
                pGetHDCPSupportStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF089EEF5, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8677
// RVA: 0xEB2E00
__int64 __fastcall NvAPI_SetTopologyFocusDisplayAndView(
        NvLogicalGpuHandle__ *hLogicalGPU,
        unsigned int focusDisplayOutputId,
        NV_DISPLAY_PATH_INFO *pPathInfo,
        unsigned int displayView)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_311 = 0i64;
  if ( !fp_311 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_311 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA8064F9u);
  if ( !fp_311 )
    return 4294967293i64;
  v5 = fp_311;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA8064F9u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvLogicalGpuHandle__ *, _QWORD, NV_DISPLAY_PATH_INFO *, _QWORD, __int64 (__fastcall *)()))v5)(
                hLogicalGPU,
                focusDisplayOutputId,
                pPathInfo,
                displayView,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA8064F9u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 8702
// RVA: 0xEB2F40
__int64 __fastcall NvAPI_Stereo_CreateConfigurationProfileRegistryKey(unsigned int registryProfileType)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_312 = 0i64;
  if ( !fp_312 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_312 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBE7692EC);
  if ( !fp_312 )
    return 4294967293i64;
  v2 = fp_312;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBE7692EC, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(registryProfileType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBE7692EC, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8727
// RVA: 0xEB3060
__int64 __fastcall NvAPI_Stereo_DeleteConfigurationProfileRegistryKey(unsigned int registryProfileType)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_313 = 0i64;
  if ( !fp_313 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_313 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF117B834);
  if ( !fp_313 )
    return 4294967293i64;
  v2 = fp_313;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF117B834, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(registryProfileType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF117B834, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8752
// RVA: 0xEB3180
__int64 __fastcall NvAPI_Stereo_SetConfigurationProfileValue(
        unsigned int registryProfileType,
        unsigned int valueRegistryID,
        void *pValue)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_314 = 0i64;
  if ( !fp_314 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_314 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x24409F48u);
  if ( !fp_314 )
    return 4294967293i64;
  v4 = fp_314;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x24409F48u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD, void *))v4)(registryProfileType, valueRegistryID, pValue);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x24409F48u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 8777
// RVA: 0xEB32B0
__int64 __fastcall NvAPI_Stereo_DeleteConfigurationProfileValue(
        unsigned int registryProfileType,
        unsigned int valueRegistryID)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_315 = 0i64;
  if ( !fp_315 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_315 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x49BCEECFu);
  if ( !fp_315 )
    return 4294967293i64;
  v3 = fp_315;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x49BCEECFu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _QWORD))v3)(registryProfileType, valueRegistryID);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x49BCEECFu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8802
// RVA: 0xEB33E0
__int64 __fastcall NvAPI_Stereo_Enable()
{
  __int64 v0; // rcx
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_316 = 0i64;
  if ( !fp_316 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_316 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x239C4545u);
  if ( !fp_316 )
    return 4294967293i64;
  v2 = fp_316;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x239C4545u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(__int64))v2)(v0);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x239C4545u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8827
// RVA: 0xEB3500
__int64 __fastcall NvAPI_Stereo_Disable()
{
  __int64 v0; // rcx
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_317 = 0i64;
  if ( !fp_317 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_317 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2EC50C2Bu);
  if ( !fp_317 )
    return 4294967293i64;
  v2 = fp_317;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2EC50C2Bu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(__int64))v2)(v0);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2EC50C2Bu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8852
// RVA: 0xEB3620
__int64 __fastcall NvAPI_Stereo_IsEnabled(char *pIsStereoEnabled)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_318 = 0i64;
  if ( !fp_318 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_318 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x348FF8E1u);
  if ( !fp_318 )
    return 4294967293i64;
  v2 = fp_318;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x348FF8E1u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(char *))v2)(pIsStereoEnabled);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x348FF8E1u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8877
// RVA: 0xEB3740
__int64 __fastcall NvAPI_Stereo_GetStereoCaps(_NVAPI_STEREO_CAPS *pCaps)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_319 = 0i64;
  if ( !fp_319 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_319 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDFC063B7);
  if ( !fp_319 )
    return 4294967293i64;
  v2 = fp_319;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDFC063B7, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NVAPI_STEREO_CAPS *))v2)(pCaps);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDFC063B7, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8902
// RVA: 0xEB3860
__int64 __fastcall NvAPI_Stereo_GetStereoSupport(NvMonitorHandle__ *hMonitor, _NVAPI_STEREO_CAPS *pCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_320 = 0i64;
  if ( !fp_320 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_320 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x296C434Du);
  if ( !fp_320 )
    return 4294967293i64;
  v3 = fp_320;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x296C434Du, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvMonitorHandle__ *, _NVAPI_STEREO_CAPS *))v3)(hMonitor, pCaps);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x296C434Du, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8927
// RVA: 0xEB3990
__int64 __fastcall NvAPI_Stereo_CreateHandleFromIUnknown(IUnknown *pDevice, void **pStereoHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_321 = 0i64;
  if ( !fp_321 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_321 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAC7E37F4);
  if ( !fp_321 )
    return 4294967293i64;
  v3 = fp_321;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAC7E37F4, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, void **))v3)(pDevice, pStereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAC7E37F4, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 8952
// RVA: 0xEB3AC0
__int64 __fastcall NvAPI_Stereo_DestroyHandle(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_322 = 0i64;
  if ( !fp_322 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_322 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3A153134u);
  if ( !fp_322 )
    return 4294967293i64;
  v2 = fp_322;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3A153134u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3A153134u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 8977
// RVA: 0xEB3BE0
__int64 __fastcall NvAPI_Stereo_Activate(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_323 = 0i64;
  if ( !fp_323 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_323 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF6A1AD68);
  if ( !fp_323 )
    return 4294967293i64;
  v2 = fp_323;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF6A1AD68, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF6A1AD68, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9002
// RVA: 0xEB3D00
__int64 __fastcall NvAPI_Stereo_Deactivate(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_324 = 0i64;
  if ( !fp_324 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_324 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2D68DE96u);
  if ( !fp_324 )
    return 4294967293i64;
  v2 = fp_324;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2D68DE96u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2D68DE96u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9027
// RVA: 0xEB3E20
__int64 __fastcall NvAPI_Stereo_IsActivated(void *stereoHandle, char *pIsStereoOn)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_325 = 0i64;
  if ( !fp_325 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_325 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1FB0BC30u);
  if ( !fp_325 )
    return 4294967293i64;
  v3 = fp_325;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1FB0BC30u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, char *))v3)(stereoHandle, pIsStereoOn);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1FB0BC30u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9052
// RVA: 0xEB3F50
__int64 __fastcall NvAPI_Stereo_GetSeparation(void *stereoHandle, float *pSeparationPercentage)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_326 = 0i64;
  if ( !fp_326 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_326 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x451F2134u);
  if ( !fp_326 )
    return 4294967293i64;
  v3 = fp_326;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x451F2134u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, float *))v3)(stereoHandle, pSeparationPercentage);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x451F2134u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9077
// RVA: 0xEB4080
__int64 __fastcall NvAPI_Stereo_SetSeparation(void *stereoHandle, float newSeparationPercentage)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_327 = 0i64;
  if ( !fp_327 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_327 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5C069FA3u);
  if ( !fp_327 )
    return 4294967293i64;
  v3 = fp_327;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5C069FA3u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v3)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5C069FA3u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9102
// RVA: 0xEB41B0
__int64 __fastcall NvAPI_Stereo_DecreaseSeparation(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_328 = 0i64;
  if ( !fp_328 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_328 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA044458);
  if ( !fp_328 )
    return 4294967293i64;
  v2 = fp_328;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA044458, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA044458, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9127
// RVA: 0xEB42D0
__int64 __fastcall NvAPI_Stereo_IncreaseSeparation(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_329 = 0i64;
  if ( !fp_329 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_329 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC9A8ECEC);
  if ( !fp_329 )
    return 4294967293i64;
  v2 = fp_329;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC9A8ECEC, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC9A8ECEC, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9152
// RVA: 0xEB43F0
__int64 __fastcall NvAPI_Stereo_GetConvergence(void *stereoHandle, float *pConvergence)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_330 = 0i64;
  if ( !fp_330 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_330 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4AB00934u);
  if ( !fp_330 )
    return 4294967293i64;
  v3 = fp_330;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4AB00934u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, float *))v3)(stereoHandle, pConvergence);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4AB00934u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9177
// RVA: 0xEB4520
__int64 __fastcall NvAPI_Stereo_SetConvergence(void *stereoHandle, float newConvergence)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_331 = 0i64;
  if ( !fp_331 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_331 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3DD6B54Bu);
  if ( !fp_331 )
    return 4294967293i64;
  v3 = fp_331;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3DD6B54Bu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v3)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3DD6B54Bu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9202
// RVA: 0xEB4650
__int64 __fastcall NvAPI_Stereo_DecreaseConvergence(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_332 = 0i64;
  if ( !fp_332 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_332 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4C87E317u);
  if ( !fp_332 )
    return 4294967293i64;
  v2 = fp_332;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4C87E317u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4C87E317u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9227
// RVA: 0xEB4770
__int64 __fastcall NvAPI_Stereo_IncreaseConvergence(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_333 = 0i64;
  if ( !fp_333 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_333 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA17DAABE);
  if ( !fp_333 )
    return 4294967293i64;
  v2 = fp_333;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA17DAABE, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA17DAABE, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9252
// RVA: 0xEB4890
__int64 __fastcall NvAPI_Stereo_GetFrustumAdjustMode(void *stereoHandle, _NV_FrustumAdjustMode *pFrustumAdjustMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_334 = 0i64;
  if ( !fp_334 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_334 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE6839B43);
  if ( !fp_334 )
    return 4294967293i64;
  v3 = fp_334;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE6839B43, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _NV_FrustumAdjustMode *))v3)(stereoHandle, pFrustumAdjustMode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE6839B43, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9277
// RVA: 0xEB49C0
__int64 __fastcall NvAPI_Stereo_SetFrustumAdjustMode(void *stereoHandle, unsigned int newFrustumAdjustModeValue)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_335 = 0i64;
  if ( !fp_335 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_335 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7BE27FA2u);
  if ( !fp_335 )
    return 4294967293i64;
  v3 = fp_335;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7BE27FA2u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(stereoHandle, newFrustumAdjustModeValue);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7BE27FA2u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9302
// RVA: 0xEB4AF0
__int64 __fastcall NvAPI_Stereo_CaptureJpegImage(void *stereoHandle, unsigned int quality)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_336 = 0i64;
  if ( !fp_336 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_336 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x932CB140);
  if ( !fp_336 )
    return 4294967293i64;
  v3 = fp_336;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x932CB140, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(stereoHandle, quality);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x932CB140, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9327
// RVA: 0xEB4C20
__int64 __fastcall NvAPI_Stereo_CapturePngImage(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_337 = 0i64;
  if ( !fp_337 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_337 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8B7E99B5);
  if ( !fp_337 )
    return 4294967293i64;
  v2 = fp_337;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8B7E99B5, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(stereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8B7E99B5, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9352
// RVA: 0xEB4D40
__int64 __fastcall NvAPI_Stereo_ReverseStereoBlitControl(void *hStereoHandle, unsigned __int8 TurnOn)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_338 = 0i64;
  if ( !fp_338 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_338 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3CD58F89u);
  if ( !fp_338 )
    return 4294967293i64;
  v3 = fp_338;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3CD58F89u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(hStereoHandle, TurnOn);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3CD58F89u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9377
// RVA: 0xEB4E70
__int64 __fastcall NvAPI_Stereo_SetNotificationMessage(
        void *hStereoHandle,
        unsigned __int64 hWnd,
        unsigned __int64 messageID)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_339 = 0i64;
  if ( !fp_339 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_339 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6B9B409Eu);
  if ( !fp_339 )
    return 4294967293i64;
  v4 = fp_339;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6B9B409Eu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(void *, unsigned __int64, unsigned __int64))v4)(
                hStereoHandle,
                hWnd,
                messageID);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6B9B409Eu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 9402
// RVA: 0xEB4FB0
__int64 __fastcall NvAPI_Stereo_SetActiveEye(void *hStereoHandle, unsigned int StereoEye)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_340 = 0i64;
  if ( !fp_340 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_340 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x96EEA9F8);
  if ( !fp_340 )
    return 4294967293i64;
  v3 = fp_340;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x96EEA9F8, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(hStereoHandle, StereoEye);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x96EEA9F8, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9427
// RVA: 0xEB50E0
__int64 __fastcall NvAPI_Stereo_SetDriverMode(unsigned int mode)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_341 = 0i64;
  if ( !fp_341 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_341 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5E8F0BECu);
  if ( !fp_341 )
    return 4294967293i64;
  v2 = fp_341;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5E8F0BECu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(mode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5E8F0BECu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9452
// RVA: 0xEB5200
__int64 __fastcall NvAPI_Stereo_GetEyeSeparation(void *hStereoHandle, float *pSeparation)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_342 = 0i64;
  if ( !fp_342 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_342 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCE653127);
  if ( !fp_342 )
    return 4294967293i64;
  v3 = fp_342;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCE653127, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, float *))v3)(hStereoHandle, pSeparation);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCE653127, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9477
// RVA: 0xEB5330
__int64 __fastcall NvAPI_Stereo_IsWindowedModeSupported(char *bSupported)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_343 = 0i64;
  if ( !fp_343 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_343 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x40C8ED5Eu);
  if ( !fp_343 )
    return 4294967293i64;
  v2 = fp_343;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x40C8ED5Eu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(char *))v2)(bSupported);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x40C8ED5Eu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9502
// RVA: 0xEB5450
__int64 __fastcall NvAPI_Stereo_AppHandShake(
        void *hStereoHandle,
        _NVAPI_STEREO_HANDSHAKE_PARAMS *pStereoHandshakeParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_344 = 0i64;
  if ( !fp_344 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_344 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8C610BDA);
  if ( !fp_344 )
    return 4294967293i64;
  v3 = fp_344;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8C610BDA, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _NVAPI_STEREO_HANDSHAKE_PARAMS *))v3)(
                hStereoHandle,
                pStereoHandshakeParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8C610BDA, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9527
// RVA: 0xEB5580
__int64 __fastcall NvAPI_Stereo_HandShake_Trigger_Activation(void *hStereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_345 = 0i64;
  if ( !fp_345 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_345 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB30CD1A7);
  if ( !fp_345 )
    return 4294967293i64;
  v2 = fp_345;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB30CD1A7, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(void *))v2)(hStereoHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB30CD1A7, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 9552
// RVA: 0xEB56A0
__int64 __fastcall NvAPI_Stereo_HandShake_Message_Control(void *hStereoHandle, unsigned __int8 TurnOn)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_346 = 0i64;
  if ( !fp_346 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_346 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x315E0EF0u);
  if ( !fp_346 )
    return 4294967293i64;
  v3 = fp_346;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x315E0EF0u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(hStereoHandle, TurnOn);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x315E0EF0u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9577
// RVA: 0xEB57D0
__int64 __fastcall NvAPI_Stereo_SetSurfaceCreationMode(void *hStereoHandle, unsigned int creationMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_347 = 0i64;
  if ( !fp_347 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_347 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5DCFCBA);
  if ( !fp_347 )
    return 4294967293i64;
  v3 = fp_347;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5DCFCBA, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(hStereoHandle, creationMode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5DCFCBA, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9602
// RVA: 0xEB5900
__int64 __fastcall NvAPI_Stereo_GetSurfaceCreationMode(
        void *hStereoHandle,
        _NVAPI_STEREO_SURFACECREATEMODE *pCreationMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_348 = 0i64;
  if ( !fp_348 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_348 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x36F1C736u);
  if ( !fp_348 )
    return 4294967293i64;
  v3 = fp_348;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x36F1C736u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _NVAPI_STEREO_SURFACECREATEMODE *))v3)(hStereoHandle, pCreationMode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x36F1C736u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9627
// RVA: 0xEB5A30
__int64 __fastcall NvAPI_Stereo_Debug_WasLastDrawStereoized(void *hStereoHandle, char *pWasStereoized)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_349 = 0i64;
  if ( !fp_349 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_349 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xED4416C5);
  if ( !fp_349 )
    return 4294967293i64;
  v3 = fp_349;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xED4416C5, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, char *))v3)(hStereoHandle, pWasStereoized);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xED4416C5, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9652
// RVA: 0xEB5B60
__int64 __fastcall NvAPI_Stereo_ForceToScreenDepth(void *hStereoHandle, unsigned __int8 bForceToScreenDepth)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_350 = 0i64;
  if ( !fp_350 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_350 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2D495758u);
  if ( !fp_350 )
    return 4294967293i64;
  v3 = fp_350;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2D495758u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(hStereoHandle, bForceToScreenDepth);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2D495758u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 9677
// RVA: 0xEB5C90
__int64 __fastcall NvAPI_Stereo_SetVertexShaderConstantF(
        void *hStereoHandle,
        unsigned int StartRegister,
        float *pConstantDataMono,
        float *pConstantDataLeft,
        float *pConstantDataRight,
        unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_351 = 0i64;
  if ( !fp_351 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_351 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x416C07B3u);
  if ( !fp_351 )
    return 4294967293i64;
  v7 = fp_351;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x416C07B3u, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4fCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x416C07B3u, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9702
// RVA: 0xEB5DF0
__int64 __fastcall NvAPI_Stereo_SetVertexShaderConstantB(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_352 = 0i64;
  if ( !fp_352 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_352 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5268716Fu);
  if ( !fp_352 )
    return 4294967293i64;
  v7 = fp_352;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5268716Fu, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                BoolCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5268716Fu, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9727
// RVA: 0xEB5F50
__int64 __fastcall NvAPI_Stereo_SetVertexShaderConstantI(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_353 = 0i64;
  if ( !fp_353 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_353 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7923BA0Eu);
  if ( !fp_353 )
    return 4294967293i64;
  v7 = fp_353;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7923BA0Eu, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4iCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7923BA0Eu, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9752
// RVA: 0xEB60B0
__int64 __fastcall NvAPI_Stereo_GetVertexShaderConstantF(
        void *hStereoHandle,
        unsigned int StartRegister,
        float *pConstantDataMono,
        float *pConstantDataLeft,
        float *pConstantDataRight,
        unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_354 = 0i64;
  if ( !fp_354 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_354 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x622FDC87u);
  if ( !fp_354 )
    return 4294967293i64;
  v7 = fp_354;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x622FDC87u, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4fCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x622FDC87u, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9777
// RVA: 0xEB6210
__int64 __fastcall NvAPI_Stereo_GetVertexShaderConstantB(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_355 = 0i64;
  if ( !fp_355 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_355 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x712BAA5Bu);
  if ( !fp_355 )
    return 4294967293i64;
  v7 = fp_355;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x712BAA5Bu, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                BoolCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x712BAA5Bu, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9802
// RVA: 0xEB6370
__int64 __fastcall NvAPI_Stereo_GetVertexShaderConstantI(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_356 = 0i64;
  if ( !fp_356 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_356 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5A60613Au);
  if ( !fp_356 )
    return 4294967293i64;
  v7 = fp_356;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5A60613Au, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4iCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5A60613Au, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9827
// RVA: 0xEB64D0
__int64 __fastcall NvAPI_Stereo_SetPixelShaderConstantF(
        void *hStereoHandle,
        unsigned int StartRegister,
        float *pConstantDataMono,
        float *pConstantDataLeft,
        float *pConstantDataRight,
        unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_357 = 0i64;
  if ( !fp_357 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_357 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA9657F32);
  if ( !fp_357 )
    return 4294967293i64;
  v7 = fp_357;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA9657F32, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4fCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA9657F32, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9852
// RVA: 0xEB6630
__int64 __fastcall NvAPI_Stereo_SetPixelShaderConstantB(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_358 = 0i64;
  if ( !fp_358 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_358 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBA6109EE);
  if ( !fp_358 )
    return 4294967293i64;
  v7 = fp_358;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBA6109EE, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                BoolCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBA6109EE, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9877
// RVA: 0xEB6790
__int64 __fastcall NvAPI_Stereo_SetPixelShaderConstantI(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_359 = 0i64;
  if ( !fp_359 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_359 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x912AC28F);
  if ( !fp_359 )
    return 4294967293i64;
  v7 = fp_359;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x912AC28F, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4iCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x912AC28F, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9902
// RVA: 0xEB68F0
__int64 __fastcall NvAPI_Stereo_GetPixelShaderConstantF(
        void *hStereoHandle,
        unsigned int StartRegister,
        float *pConstantDataMono,
        float *pConstantDataLeft,
        float *pConstantDataRight,
        unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_360 = 0i64;
  if ( !fp_360 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_360 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD4974572);
  if ( !fp_360 )
    return 4294967293i64;
  v7 = fp_360;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD4974572, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4fCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD4974572, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9927
// RVA: 0xEB6A50
__int64 __fastcall NvAPI_Stereo_GetPixelShaderConstantB(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_361 = 0i64;
  if ( !fp_361 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_361 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC79333AE);
  if ( !fp_361 )
    return 4294967293i64;
  v7 = fp_361;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC79333AE, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                BoolCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC79333AE, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9952
// RVA: 0xEB6BB0
__int64 __fastcall NvAPI_Stereo_GetPixelShaderConstantI(
        void *hStereoHandle,
        unsigned int StartRegister,
        int *pConstantDataMono,
        int *pConstantDataLeft,
        int *pConstantDataRight,
        unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_362 = 0i64;
  if ( !fp_362 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_362 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xECD8F8CF);
  if ( !fp_362 )
    return 4294967293i64;
  v7 = fp_362;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xECD8F8CF, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int, __int64 (__fastcall *)()))v7)(
                hStereoHandle,
                StartRegister,
                pConstantDataMono,
                pConstantDataLeft,
                pConstantDataRight,
                Vector4iCount,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xECD8F8CF, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 9977
// RVA: 0xEB6D10
__int64 __fastcall NvAPI_Stereo_SetDefaultProfile(const char *szProfileName)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_363 = 0i64;
  if ( !fp_363 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_363 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x44F0ECD1u);
  if ( !fp_363 )
    return 4294967293i64;
  v2 = fp_363;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x44F0ECD1u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(const char *))v2)(szProfileName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x44F0ECD1u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10002
// RVA: 0xEB6E30
__int64 __fastcall NvAPI_Stereo_GetDefaultProfile(unsigned int cbSizeIn, char *szProfileName, unsigned int *pcbSizeOut)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_364 = 0i64;
  if ( !fp_364 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_364 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x624E21C2u);
  if ( !fp_364 )
    return 4294967293i64;
  v4 = fp_364;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x624E21C2u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, char *, unsigned int *))v4)(cbSizeIn, szProfileName, pcbSizeOut);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x624E21C2u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 10027
// RVA: 0xEB6F60
__int64 __fastcall NvAPI_VIO_GetCapabilities(NvVioHandle__ *hVioHandle, _NVVIOCAPS *pAdapterCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_365 = 0i64;
  if ( !fp_365 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_365 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1DC91303u);
  if ( !fp_365 )
    return 4294967293i64;
  v3 = fp_365;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1DC91303u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCAPS *))v3)(hVioHandle, pAdapterCaps);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1DC91303u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10052
// RVA: 0xEB7090
__int64 __fastcall NvAPI_VIO_Open(NvVioHandle__ *hVioHandle, unsigned int vioClass, unsigned int ownerType)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_366 = 0i64;
  if ( !fp_366 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_366 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x44EE4841u);
  if ( !fp_366 )
    return 4294967293i64;
  v4 = fp_366;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x44EE4841u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _QWORD))v4)(hVioHandle, vioClass, ownerType);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x44EE4841u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 10077
// RVA: 0xEB71C0
__int64 __fastcall NvAPI_VIO_Close(NvVioHandle__ *hVioHandle, unsigned int bRelease)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_367 = 0i64;
  if ( !fp_367 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_367 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD01BD237);
  if ( !fp_367 )
    return 4294967293i64;
  v3 = fp_367;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD01BD237, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD))v3)(hVioHandle, bRelease);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD01BD237, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10102
// RVA: 0xEB72F0
__int64 __fastcall NvAPI_VIO_Status(NvVioHandle__ *hVioHandle, _NVVIOSTATUS *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_368 = 0i64;
  if ( !fp_368 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_368 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE6CE4F1u);
  if ( !fp_368 )
    return 4294967293i64;
  v3 = fp_368;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE6CE4F1u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOSTATUS *))v3)(hVioHandle, pStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE6CE4F1u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10127
// RVA: 0xEB7420
__int64 __fastcall NvAPI_VIO_SyncFormatDetect(NvVioHandle__ *hVioHandle, unsigned int *pWait)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_369 = 0i64;
  if ( !fp_369 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_369 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x118D48A3u);
  if ( !fp_369 )
    return 4294967293i64;
  v3 = fp_369;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x118D48A3u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, unsigned int *))v3)(hVioHandle, pWait);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x118D48A3u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10152
// RVA: 0xEB7550
__int64 __fastcall NvAPI_VIO_GetConfig(NvVioHandle__ *hVioHandle, _NVVIOCONFIG_V3 *pConfig)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_370 = 0i64;
  if ( !fp_370 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_370 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD34A789B);
  if ( !fp_370 )
    return 4294967293i64;
  v3 = fp_370;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD34A789B, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCONFIG_V3 *))v3)(hVioHandle, pConfig);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD34A789B, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10177
// RVA: 0xEB7680
__int64 __fastcall NvAPI_VIO_SetConfig(NvVioHandle__ *hVioHandle, _NVVIOCONFIG_V3 *pConfig)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_371 = 0i64;
  if ( !fp_371 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_371 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE4EEC07u);
  if ( !fp_371 )
    return 4294967293i64;
  v3 = fp_371;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE4EEC07u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCONFIG_V3 *))v3)(hVioHandle, pConfig);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE4EEC07u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10202
// RVA: 0xEB77B0
__int64 __fastcall NvAPI_VIO_SetCSC(NvVioHandle__ *hVioHandle, _NVVIOCOLORCONVERSION *pCSC)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_372 = 0i64;
  if ( !fp_372 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_372 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA1EC8D74);
  if ( !fp_372 )
    return 4294967293i64;
  v3 = fp_372;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA1EC8D74, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCOLORCONVERSION *))v3)(hVioHandle, pCSC);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA1EC8D74, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10227
// RVA: 0xEB78E0
__int64 __fastcall NvAPI_VIO_GetCSC(NvVioHandle__ *hVioHandle, _NVVIOCOLORCONVERSION *pCSC)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_373 = 0i64;
  if ( !fp_373 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_373 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7B0D72A3u);
  if ( !fp_373 )
    return 4294967293i64;
  v3 = fp_373;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7B0D72A3u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCOLORCONVERSION *))v3)(hVioHandle, pCSC);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7B0D72A3u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10252
// RVA: 0xEB7A10
__int64 __fastcall NvAPI_VIO_SetGamma(NvVioHandle__ *hVioHandle, _NVVIOGAMMACORRECTION *pGamma)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_374 = 0i64;
  if ( !fp_374 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_374 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x964BF452);
  if ( !fp_374 )
    return 4294967293i64;
  v3 = fp_374;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x964BF452, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOGAMMACORRECTION *))v3)(hVioHandle, pGamma);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x964BF452, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10277
// RVA: 0xEB7B40
__int64 __fastcall NvAPI_VIO_GetGamma(NvVioHandle__ *hVioHandle, _NVVIOGAMMACORRECTION *pGamma)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_375 = 0i64;
  if ( !fp_375 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_375 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x51D53D06u);
  if ( !fp_375 )
    return 4294967293i64;
  v3 = fp_375;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x51D53D06u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOGAMMACORRECTION *))v3)(hVioHandle, pGamma);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x51D53D06u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10302
// RVA: 0xEB7C70
__int64 __fastcall NvAPI_VIO_SetSyncDelay(NvVioHandle__ *hVioHandle, _NVVIOSYNCDELAY *pSyncDelay)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_376 = 0i64;
  if ( !fp_376 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_376 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2697A8D1u);
  if ( !fp_376 )
    return 4294967293i64;
  v3 = fp_376;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2697A8D1u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOSYNCDELAY *))v3)(hVioHandle, pSyncDelay);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2697A8D1u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10327
// RVA: 0xEB7DA0
__int64 __fastcall NvAPI_VIO_GetSyncDelay(NvVioHandle__ *hVioHandle, _NVVIOSYNCDELAY *pSyncDelay)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_377 = 0i64;
  if ( !fp_377 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_377 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x462214A9u);
  if ( !fp_377 )
    return 4294967293i64;
  v3 = fp_377;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x462214A9u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOSYNCDELAY *))v3)(hVioHandle, pSyncDelay);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x462214A9u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10352
// RVA: 0xEB7ED0
__int64 __fastcall NvAPI_VIO_GetPCIInfo(NvVioHandle__ *hVioHandle, _NVVIOPCIINFO *pVioPCIInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_378 = 0i64;
  if ( !fp_378 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_378 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB981D935);
  if ( !fp_378 )
    return 4294967293i64;
  v3 = fp_378;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB981D935, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOPCIINFO *))v3)(hVioHandle, pVioPCIInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB981D935, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10377
// RVA: 0xEB8000
__int64 __fastcall NvAPI_VIO_IsRunning(NvVioHandle__ *hVioHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_379 = 0i64;
  if ( !fp_379 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_379 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x96BD040E);
  if ( !fp_379 )
    return 4294967293i64;
  v2 = fp_379;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x96BD040E, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *))v2)(hVioHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x96BD040E, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10402
// RVA: 0xEB8120
__int64 __fastcall NvAPI_VIO_Start(NvVioHandle__ *hVioHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_380 = 0i64;
  if ( !fp_380 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_380 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDE8E1A3);
  if ( !fp_380 )
    return 4294967293i64;
  v2 = fp_380;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDE8E1A3, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *))v2)(hVioHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDE8E1A3, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10427
// RVA: 0xEB8240
__int64 __fastcall NvAPI_VIO_Stop(NvVioHandle__ *hVioHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_381 = 0i64;
  if ( !fp_381 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_381 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6BA2A5D6u);
  if ( !fp_381 )
    return 4294967293i64;
  v2 = fp_381;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6BA2A5D6u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *))v2)(hVioHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6BA2A5D6u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10452
// RVA: 0xEB8360
__int64 __fastcall NvAPI_VIO_IsFrameLockModeCompatible(
        NvVioHandle__ *hVioHandle,
        unsigned int srcEnumIndex,
        unsigned int destEnumIndex,
        unsigned int *pbCompatible)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_382 = 0i64;
  if ( !fp_382 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_382 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7BF0A94Du);
  if ( !fp_382 )
    return 4294967293i64;
  v5 = fp_382;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7BF0A94Du, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _QWORD, unsigned int *, __int64 (__fastcall *)()))v5)(
                hVioHandle,
                srcEnumIndex,
                destEnumIndex,
                pbCompatible,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7BF0A94Du, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 10477
// RVA: 0xEB84A0
__int64 __fastcall NvAPI_VIO_EnumDevices(NvVioHandle__ **hVioHandle, unsigned int *vioDeviceCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_383 = 0i64;
  if ( !fp_383 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_383 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFD7C5557);
  if ( !fp_383 )
    return 4294967293i64;
  v3 = fp_383;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFD7C5557, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ **, unsigned int *))v3)(hVioHandle, vioDeviceCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFD7C5557, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10502
// RVA: 0xEB85D0
__int64 __fastcall NvAPI_VIO_QueryTopology(_NV_VIO_TOPOLOGY *pNvVIOTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_384 = 0i64;
  if ( !fp_384 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_384 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x869534E2);
  if ( !fp_384 )
    return 4294967293i64;
  v2 = fp_384;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x869534E2, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NV_VIO_TOPOLOGY *))v2)(pNvVIOTopology);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x869534E2, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10527
// RVA: 0xEB86F0
__int64 __fastcall NvAPI_VIO_EnumSignalFormats(
        NvVioHandle__ *hVioHandle,
        unsigned int enumIndex,
        _NVVIOSIGNALFORMATDETAIL *pSignalFormatDetail)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_385 = 0i64;
  if ( !fp_385 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_385 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEAD72FE4);
  if ( !fp_385 )
    return 4294967293i64;
  v4 = fp_385;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEAD72FE4, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _NVVIOSIGNALFORMATDETAIL *))v4)(
                hVioHandle,
                enumIndex,
                pSignalFormatDetail);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEAD72FE4, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 10552
// RVA: 0xEB8820
__int64 __fastcall NvAPI_VIO_EnumDataFormats(
        NvVioHandle__ *hVioHandle,
        unsigned int enumIndex,
        _NVVIODATAFORMATDETAIL *pDataFormatDetail)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_386 = 0i64;
  if ( !fp_386 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_386 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x221FA8E8u);
  if ( !fp_386 )
    return 4294967293i64;
  v4 = fp_386;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x221FA8E8u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _NVVIODATAFORMATDETAIL *))v4)(
                hVioHandle,
                enumIndex,
                pDataFormatDetail);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x221FA8E8u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 10577
// RVA: 0xEB8950
__int64 __fastcall NvAPI_GPU_GetTachReading(NvPhysicalGpuHandle__ *hPhysicalGPU, unsigned int *pValue)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_387 = 0i64;
  if ( !fp_387 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_387 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F608315u);
  if ( !fp_387 )
    return 4294967293i64;
  v3 = fp_387;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F608315u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGPU, pValue);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F608315u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10602
// RVA: 0xEB8A80
__int64 __fastcall NvAPI_3D_GetProperty(char *szProfileName, NV_3D_SETTING *p3dSetting)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_388 = 0i64;
  if ( !fp_388 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_388 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8061A4B1);
  if ( !fp_388 )
    return 4294967293i64;
  v3 = fp_388;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8061A4B1, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(char *, NV_3D_SETTING *))v3)(szProfileName, p3dSetting);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8061A4B1, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10627
// RVA: 0xEB8BB0
__int64 __fastcall NvAPI_3D_SetProperty(char *szProfileName, NV_3D_SETTING *p3dSetting)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_389 = 0i64;
  if ( !fp_389 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_389 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC9175E8D);
  if ( !fp_389 )
    return 4294967293i64;
  v3 = fp_389;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC9175E8D, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(char *, NV_3D_SETTING *))v3)(szProfileName, p3dSetting);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC9175E8D, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10652
// RVA: 0xEB8CE0
__int64 __fastcall NvAPI_3D_GetPropertyRange(char *szProfileName, NV_3D_SETTING_RANGE *p3dsettingRange)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_390 = 0i64;
  if ( !fp_390 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_390 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB85DE27C);
  if ( !fp_390 )
    return 4294967293i64;
  v3 = fp_390;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB85DE27C, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(char *, NV_3D_SETTING_RANGE *))v3)(szProfileName, p3dsettingRange);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB85DE27C, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10677
// RVA: 0xEB8E10
__int64 __fastcall NvAPI_GPS_GetPowerSteeringStatus(NV_GPS_PS_STATUS *pPowerSteeringStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_391 = 0i64;
  if ( !fp_391 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_391 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x540EE82Eu);
  if ( !fp_391 )
    return 4294967293i64;
  v2 = fp_391;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x540EE82Eu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_GPS_PS_STATUS *))v2)(pPowerSteeringStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x540EE82Eu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10702
// RVA: 0xEB8F30
__int64 __fastcall NvAPI_GPS_SetPowerSteeringStatus(unsigned int PowerSteeringStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_392 = 0i64;
  if ( !fp_392 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_392 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9723D3A2);
  if ( !fp_392 )
    return 4294967293i64;
  v2 = fp_392;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9723D3A2, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(PowerSteeringStatus);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9723D3A2, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10727
// RVA: 0xEB9050
__int64 __fastcall NvAPI_GPS_SetVPStateCap(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int newCap)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_393 = 0i64;
  if ( !fp_393 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_393 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x68888EB4u);
  if ( !fp_393 )
    return 4294967293i64;
  v3 = fp_393;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x68888EB4u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(hPhysicalGpu, newCap);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x68888EB4u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10752
// RVA: 0xEB9180
__int64 __fastcall NvAPI_GPS_GetVPStateCap(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCurCap)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_394 = 0i64;
  if ( !fp_394 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_394 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x71913023u);
  if ( !fp_394 )
    return 4294967293i64;
  v3 = fp_394;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x71913023u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pCurCap);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x71913023u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10777
// RVA: 0xEB92B0
__int64 __fastcall NvAPI_GPS_GetThermalLimit(_NV_GPS_GET_THERMAL_LIMIT_PARM *pParams)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_395 = 0i64;
  if ( !fp_395 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_395 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x583113EDu);
  if ( !fp_395 )
    return 4294967293i64;
  v2 = fp_395;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x583113EDu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NV_GPS_GET_THERMAL_LIMIT_PARM *))v2)(pParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x583113EDu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10802
// RVA: 0xEB93D0
__int64 __fastcall NvAPI_GPS_SetThermalLimit(_NV_GPS_SET_THERMAL_LIMIT_PARM *pParams)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_396 = 0i64;
  if ( !fp_396 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_396 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC07E210F);
  if ( !fp_396 )
    return 4294967293i64;
  v2 = fp_396;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC07E210F, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NV_GPS_SET_THERMAL_LIMIT_PARM *))v2)(pParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC07E210F, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10827
// RVA: 0xEB94F0
__int64 __fastcall NvAPI_GPS_GetPerfSensors(_NV_GPS_GET_PERF_SENSOR_COUNTERS_PARAM_V1 *pParams)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_397 = 0i64;
  if ( !fp_397 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_397 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x271C1109u);
  if ( !fp_397 )
    return 4294967293i64;
  v2 = fp_397;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x271C1109u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NV_GPS_GET_PERF_SENSOR_COUNTERS_PARAM_V1 *))v2)(pParams);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x271C1109u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10852
// RVA: 0xEB9610
__int64 __fastcall NvAPI_SYS_GetDisplayIdFromGpuAndOutputId(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        unsigned int *displayId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_398 = 0i64;
  if ( !fp_398 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_398 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8F2BAB4u);
  if ( !fp_398 )
    return 4294967293i64;
  v4 = fp_398;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8F2BAB4u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, unsigned int *))v4)(
                hPhysicalGpu,
                outputId,
                displayId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8F2BAB4u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 10877
// RVA: 0xEB9740
__int64 __fastcall NvAPI_SYS_GetGpuAndOutputIdFromDisplayId(
        unsigned int displayId,
        NvPhysicalGpuHandle__ **hPhysicalGpu,
        unsigned int *outputId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_399 = 0i64;
  if ( !fp_399 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_399 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x112BA1A5u);
  if ( !fp_399 )
    return 4294967293i64;
  v4 = fp_399;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x112BA1A5u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NvPhysicalGpuHandle__ **, unsigned int *))v4)(
                displayId,
                hPhysicalGpu,
                outputId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x112BA1A5u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 10902
// RVA: 0xEB9870
__int64 __fastcall NvAPI_DISP_GetDisplayIdByDisplayName(const char *displayName, unsigned int *displayId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_400 = 0i64;
  if ( !fp_400 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_400 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE457190);
  if ( !fp_400 )
    return 4294967293i64;
  v3 = fp_400;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE457190, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(const char *, unsigned int *))v3)(displayName, displayId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE457190, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10927
// RVA: 0xEB99A0
__int64 __fastcall NvAPI_DISP_GetGDIPrimaryDisplayId(unsigned int *displayId)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_401 = 0i64;
  if ( !fp_401 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_401 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1E9D8A31u);
  if ( !fp_401 )
    return 4294967293i64;
  v2 = fp_401;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1E9D8A31u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(displayId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1E9D8A31u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 10952
// RVA: 0xEB9AC0
__int64 __fastcall NvAPI_DISP_GetDisplayConfig(unsigned int *pathInfoCount, _NV_DISPLAYCONFIG_PATH_INFO *pathInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_402 = 0i64;
  if ( !fp_402 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_402 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x11ABCCF8u);
  if ( !fp_402 )
    return 4294967293i64;
  v3 = fp_402;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x11ABCCF8u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _NV_DISPLAYCONFIG_PATH_INFO *))v3)(pathInfoCount, pathInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x11ABCCF8u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 10977
// RVA: 0xEB9BF0
__int64 __fastcall NvAPI_DISP_SetDisplayConfig(
        unsigned int pathInfoCount,
        _NV_DISPLAYCONFIG_PATH_INFO *pathInfo,
        unsigned int flags)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_403 = 0i64;
  if ( !fp_403 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_403 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5D8CF8DEu);
  if ( !fp_403 )
    return 4294967293i64;
  v4 = fp_403;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5D8CF8DEu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_DISPLAYCONFIG_PATH_INFO *, _QWORD))v4)(
                pathInfoCount,
                pathInfo,
                flags);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5D8CF8DEu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11002
// RVA: 0xEB9D20
__int64 __fastcall NvAPI_GPU_GetPixelClockRange(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        NV_GET_PCLK *pTimings)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_404 = 0i64;
  if ( !fp_404 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_404 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x66AF10B7u);
  if ( !fp_404 )
    return 4294967293i64;
  v4 = fp_404;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x66AF10B7u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GET_PCLK *))v4)(
                hPhysicalGpu,
                outputId,
                pTimings);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x66AF10B7u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11027
// RVA: 0xEB9E50
__int64 __fastcall NvAPI_GPU_SetPixelClockRange(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned int outputId,
        NV_SET_PCLK *pTimings)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_405 = 0i64;
  if ( !fp_405 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_405 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5AC7F8E5u);
  if ( !fp_405 )
    return 4294967293i64;
  v4 = fp_405;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5AC7F8E5u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_SET_PCLK *))v4)(
                hPhysicalGpu,
                outputId,
                pTimings);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5AC7F8E5u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11052
// RVA: 0xEB9F80
__int64 __fastcall NvAPI_GPU_GetECCStatusInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_ECC_STATUS_INFO *pECCStatusInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_406 = 0i64;
  if ( !fp_406 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_406 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCA1DDAF3);
  if ( !fp_406 )
    return 4294967293i64;
  v3 = fp_406;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCA1DDAF3, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_ECC_STATUS_INFO *))v3)(
                hPhysicalGpu,
                pECCStatusInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCA1DDAF3, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11077
// RVA: 0xEBA0B0
__int64 __fastcall NvAPI_GPU_GetECCErrorInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_ECC_ERROR_INFO *pECCErrorInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_407 = 0i64;
  if ( !fp_407 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_407 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC71F85A6);
  if ( !fp_407 )
    return 4294967293i64;
  v3 = fp_407;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC71F85A6, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_ECC_ERROR_INFO *))v3)(
                hPhysicalGpu,
                pECCErrorInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC71F85A6, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11102
// RVA: 0xEBA1E0
__int64 __fastcall NvAPI_GPU_ResetECCErrorInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned __int8 bResetCurrent,
        unsigned __int8 bResetAggregate)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_408 = 0i64;
  if ( !fp_408 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_408 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC02EEC20);
  if ( !fp_408 )
    return 4294967293i64;
  v4 = fp_408;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC02EEC20, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(
                hPhysicalGpu,
                bResetCurrent,
                bResetAggregate);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC02EEC20, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11127
// RVA: 0xEBA320
__int64 __fastcall NvAPI_GPU_GetECCConfigurationInfo(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        NV_GPU_ECC_CONFIGURATION_INFO *pECCConfigurationInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_409 = 0i64;
  if ( !fp_409 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_409 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x77A796F3u);
  if ( !fp_409 )
    return 4294967293i64;
  v3 = fp_409;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x77A796F3u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_ECC_CONFIGURATION_INFO *))v3)(
                hPhysicalGpu,
                pECCConfigurationInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x77A796F3u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11152
// RVA: 0xEBA450
__int64 __fastcall NvAPI_GPU_SetECCConfiguration(
        NvPhysicalGpuHandle__ *hPhysicalGpu,
        unsigned __int8 bEnable,
        unsigned __int8 bEnableImmediately)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_410 = 0i64;
  if ( !fp_410 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_410 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1CF639D9u);
  if ( !fp_410 )
    return 4294967293i64;
  v4 = fp_410;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1CF639D9u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(
                hPhysicalGpu,
                bEnable,
                bEnableImmediately);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1CF639D9u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11177
// RVA: 0xEBA590
__int64 __fastcall NvAPI_D3D1x_CreateSwapChain(
        void *hStereoHandle,
        unsigned int *pDesc,
        unsigned int **ppSwapChain,
        unsigned int mode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_411 = 0i64;
  if ( !fp_411 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_411 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1BC21B66u);
  if ( !fp_411 )
    return 4294967293i64;
  v5 = fp_411;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1BC21B66u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(void *, unsigned int *, unsigned int **, _QWORD, __int64 (__fastcall *)()))v5)(
                hStereoHandle,
                pDesc,
                ppSwapChain,
                mode,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1BC21B66u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11202
// RVA: 0xEBA6D0
__int64 __fastcall NvAPI_D3D9_CreateSwapChain(
        void *hStereoHandle,
        unsigned int *pPresentationParameters,
        unsigned int **ppSwapChain,
        unsigned int mode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_412 = 0i64;
  if ( !fp_412 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_412 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1A131E09u);
  if ( !fp_412 )
    return 4294967293i64;
  v5 = fp_412;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1A131E09u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(void *, unsigned int *, unsigned int **, _QWORD, __int64 (__fastcall *)()))v5)(
                hStereoHandle,
                pPresentationParameters,
                ppSwapChain,
                mode,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1A131E09u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11227
// RVA: 0xEBA810
__int64 __fastcall NvAPI_D3D_SetFPSIndicatorState(IUnknown *pDev, unsigned __int8 doEnable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_413 = 0i64;
  if ( !fp_413 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_413 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA776E8DB);
  if ( !fp_413 )
    return 4294967293i64;
  v3 = fp_413;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA776E8DB, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, _QWORD))v3)(pDev, doEnable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA776E8DB, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11252
// RVA: 0xEBA940
signed __int64 __fastcall NvAPI_D3D9_Present(
        unsigned int *pDevice,
        unsigned int *pSwapChain,
        tagRECT *pSourceRect,
        tagRECT *pDestRect,
        HWND__ *hDestWindowOverride,
        _RGNDATA *pDirtyRegion)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v11 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_414 = 0i64;
  if ( !fp_414 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_414 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5650BEBu);
  if ( !fp_414 )
    return 4294967293i64;
  v7 = fp_414;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5650BEBu, &v9);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, tagRECT *, tagRECT *, HWND__ *, _RGNDATA *, __int64 (__fastcall *)()))v7)(
                pDevice,
                pSwapChain,
                pSourceRect,
                pDestRect,
                hDestWindowOverride,
                pDirtyRegion,
                v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5650BEBu, v9, GpuHandle);
  --g_module_numApiInUse[v11];
  return (unsigned int)GpuHandle;
}

// File Line: 11277
// RVA: 0xEBAAA0
__int64 __fastcall NvAPI_D3D9_QueryFrameCount(unsigned int *pDevice, unsigned int *pFrameCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_415 = 0i64;
  if ( !fp_415 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_415 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9083E53A);
  if ( !fp_415 )
    return 4294967293i64;
  v3 = fp_415;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9083E53A, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *))v3)(pDevice, pFrameCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9083E53A, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11302
// RVA: 0xEBABD0
__int64 __fastcall NvAPI_D3D9_ResetFrameCount(unsigned int *pDevice)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_416 = 0i64;
  if ( !fp_416 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_416 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA6A0675);
  if ( !fp_416 )
    return 4294967293i64;
  v2 = fp_416;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA6A0675, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(pDevice);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA6A0675, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11327
// RVA: 0xEBACF0
__int64 __fastcall NvAPI_D3D9_QueryMaxSwapGroup(
        unsigned int *pDevice,
        unsigned int *pMaxGroups,
        unsigned int *pMaxBarriers)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_417 = 0i64;
  if ( !fp_417 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_417 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5995410Du);
  if ( !fp_417 )
    return 4294967293i64;
  v4 = fp_417;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5995410Du, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *))v4)(
                pDevice,
                pMaxGroups,
                pMaxBarriers);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5995410Du, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11352
// RVA: 0xEBAE30
__int64 __fastcall NvAPI_D3D9_QuerySwapGroup(
        unsigned int *pDevice,
        unsigned int *pSwapChain,
        unsigned int *pSwapGroup,
        unsigned int *pSwapBarrier)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_418 = 0i64;
  if ( !fp_418 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_418 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEBA4D232);
  if ( !fp_418 )
    return 4294967293i64;
  v5 = fp_418;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEBA4D232, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, unsigned int *, __int64 (__fastcall *)()))v5)(
                pDevice,
                pSwapChain,
                pSwapGroup,
                pSwapBarrier,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEBA4D232, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11377
// RVA: 0xEBAF70
__int64 __fastcall NvAPI_D3D9_JoinSwapGroup(
        unsigned int *pDevice,
        unsigned int *pSwapChain,
        unsigned int group,
        unsigned int blocking)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_419 = 0i64;
  if ( !fp_419 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_419 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7D44BB54u);
  if ( !fp_419 )
    return 4294967293i64;
  v5 = fp_419;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7D44BB54u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                pDevice,
                pSwapChain,
                group,
                blocking,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7D44BB54u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11402
// RVA: 0xEBB0B0
__int64 __fastcall NvAPI_D3D9_BindSwapBarrier(unsigned int *pDevice, unsigned int group, unsigned int barrier)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_420 = 0i64;
  if ( !fp_420 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_420 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9C39C246);
  if ( !fp_420 )
    return 4294967293i64;
  v4 = fp_420;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9C39C246, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD))v4)(pDevice, group, barrier);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9C39C246, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11427
// RVA: 0xEBB1E0
signed __int64 __fastcall NvAPI_D3D1x_Present(
        IUnknown *pDevice,
        unsigned int *pSwapChain,
        unsigned int SyncInterval,
        unsigned int Flags)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_421 = 0i64;
  if ( !fp_421 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_421 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3B845A1u);
  if ( !fp_421 )
    return 4294967293i64;
  v5 = fp_421;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3B845A1u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                pDevice,
                pSwapChain,
                SyncInterval,
                Flags,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3B845A1u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11452
// RVA: 0xEBB320
__int64 __fastcall NvAPI_D3D1x_QueryFrameCount(IUnknown *pDevice, unsigned int *pFrameCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_422 = 0i64;
  if ( !fp_422 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_422 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9152E055);
  if ( !fp_422 )
    return 4294967293i64;
  v3 = fp_422;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9152E055, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *))v3)(pDevice, pFrameCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9152E055, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11477
// RVA: 0xEBB450
__int64 __fastcall NvAPI_D3D1x_ResetFrameCount(IUnknown *pDevice)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_423 = 0i64;
  if ( !fp_423 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_423 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFBBB031A);
  if ( !fp_423 )
    return 4294967293i64;
  v2 = fp_423;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFBBB031A, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *))v2)(pDevice);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFBBB031A, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11502
// RVA: 0xEBB570
__int64 __fastcall NvAPI_D3D1x_QueryMaxSwapGroup(
        IUnknown *pDevice,
        unsigned int *pMaxGroups,
        unsigned int *pMaxBarriers)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_424 = 0i64;
  if ( !fp_424 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_424 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9BB9D68F);
  if ( !fp_424 )
    return 4294967293i64;
  v4 = fp_424;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9BB9D68F, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, unsigned int *))v4)(
                pDevice,
                pMaxGroups,
                pMaxBarriers);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9BB9D68F, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11527
// RVA: 0xEBB6B0
__int64 __fastcall NvAPI_D3D1x_QuerySwapGroup(
        IUnknown *pDevice,
        unsigned int *pSwapChain,
        unsigned int *pSwapGroup,
        unsigned int *pSwapBarrier)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_425 = 0i64;
  if ( !fp_425 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_425 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x407F67AAu);
  if ( !fp_425 )
    return 4294967293i64;
  v5 = fp_425;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x407F67AAu, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, unsigned int *, unsigned int *, __int64 (__fastcall *)()))v5)(
                pDevice,
                pSwapChain,
                pSwapGroup,
                pSwapBarrier,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x407F67AAu, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11552
// RVA: 0xEBB7F0
__int64 __fastcall NvAPI_D3D1x_JoinSwapGroup(
        IUnknown *pDevice,
        unsigned int *pSwapChain,
        unsigned int group,
        unsigned int blocking)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_426 = 0i64;
  if ( !fp_426 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_426 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x14610CD7u);
  if ( !fp_426 )
    return 4294967293i64;
  v5 = fp_426;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x14610CD7u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, _QWORD, _QWORD, __int64 (__fastcall *)()))v5)(
                pDevice,
                pSwapChain,
                group,
                blocking,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x14610CD7u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 11577
// RVA: 0xEBB930
__int64 __fastcall NvAPI_D3D1x_BindSwapBarrier(IUnknown *pDevice, unsigned int group, unsigned int barrier)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_427 = 0i64;
  if ( !fp_427 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_427 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9DE8C729);
  if ( !fp_427 )
    return 4294967293i64;
  v4 = fp_427;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9DE8C729, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, _QWORD, _QWORD))v4)(pDevice, group, barrier);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9DE8C729, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11602
// RVA: 0xEBBA60
__int64 __fastcall NvAPI_SYS_VenturaGetState(_NVAPI_VENTURA_STATE *state)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_428 = 0i64;
  if ( !fp_428 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_428 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCB7C208D);
  if ( !fp_428 )
    return 4294967293i64;
  v2 = fp_428;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCB7C208D, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_NVAPI_VENTURA_STATE *))v2)(state);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCB7C208D, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11627
// RVA: 0xEBBB80
__int64 __fastcall NvAPI_SYS_VenturaSetState(unsigned int state)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_429 = 0i64;
  if ( !fp_429 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_429 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCE2E9D9u);
  if ( !fp_429 )
    return 4294967293i64;
  v2 = fp_429;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCE2E9D9u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(state);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCE2E9D9u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11652
// RVA: 0xEBBCA0
__int64 __fastcall NvAPI_SYS_VenturaGetCoolingBudget(unsigned int *budget)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_430 = 0i64;
  if ( !fp_430 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_430 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC9D86E33);
  if ( !fp_430 )
    return 4294967293i64;
  v2 = fp_430;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC9D86E33, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *))v2)(budget);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC9D86E33, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11677
// RVA: 0xEBBDC0
__int64 __fastcall NvAPI_SYS_VenturaSetCoolingBudget(unsigned int budget)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_431 = 0i64;
  if ( !fp_431 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_431 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x85FF5A15);
  if ( !fp_431 )
    return 4294967293i64;
  v2 = fp_431;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x85FF5A15, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD))v2)(budget);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x85FF5A15, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11702
// RVA: 0xEBBEE0
__int64 __fastcall NvAPI_SYS_VenturaGetPowerReading(unsigned int device, unsigned int *power)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_432 = 0i64;
  if ( !fp_432 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_432 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63685979u);
  if ( !fp_432 )
    return 4294967293i64;
  v3 = fp_432;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63685979u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, unsigned int *))v3)(device, power);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63685979u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11727
// RVA: 0xEBC010
__int64 __fastcall NvAPI_DISP_GetDisplayBlankingState(
        unsigned int displayId,
        _NV_DISPLAY_BLANKING_INFO_V1 *pDisplayBlankingState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_433 = 0i64;
  if ( !fp_433 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_433 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63E5D8DBu);
  if ( !fp_433 )
    return 4294967293i64;
  v3 = fp_433;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63E5D8DBu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_DISPLAY_BLANKING_INFO_V1 *))v3)(
                displayId,
                pDisplayBlankingState);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63E5D8DBu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11752
// RVA: 0xEBC140
__int64 __fastcall NvAPI_DISP_SetDisplayBlankingState(
        unsigned int displayId,
        _NV_DISPLAY_BLANKING_INFO_V1 *pDisplayBlankingState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_434 = 0i64;
  if ( !fp_434 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_434 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1E17E29Bu);
  if ( !fp_434 )
    return 4294967293i64;
  v3 = fp_434;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1E17E29Bu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, _NV_DISPLAY_BLANKING_INFO_V1 *))v3)(
                displayId,
                pDisplayBlankingState);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1E17E29Bu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11777
// RVA: 0xEBC270
__int64 __fastcall NvAPI_DRS_CreateSession(NvDRSSessionHandle__ **phSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_435 = 0i64;
  if ( !fp_435 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_435 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x694D52Eu);
  if ( !fp_435 )
    return 4294967293i64;
  v2 = fp_435;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x694D52Eu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ **))v2)(phSession);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x694D52Eu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11802
// RVA: 0xEBC390
__int64 __fastcall NvAPI_DRS_DestroySession(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_436 = 0i64;
  if ( !fp_436 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_436 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDAD9CFF8);
  if ( !fp_436 )
    return 4294967293i64;
  v2 = fp_436;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDAD9CFF8, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(hSession);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDAD9CFF8, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11827
// RVA: 0xEBC4B0
__int64 __fastcall NvAPI_DRS_LoadSettings(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_437 = 0i64;
  if ( !fp_437 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_437 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x375DBD6Bu);
  if ( !fp_437 )
    return 4294967293i64;
  v2 = fp_437;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x375DBD6Bu, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(hSession);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x375DBD6Bu, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11852
// RVA: 0xEBC5D0
__int64 __fastcall NvAPI_DRS_SaveSettings(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_438 = 0i64;
  if ( !fp_438 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_438 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFCBC7E14);
  if ( !fp_438 )
    return 4294967293i64;
  v2 = fp_438;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFCBC7E14, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(hSession);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFCBC7E14, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 11877
// RVA: 0xEBC6F0
__int64 __fastcall NvAPI_DRS_LoadSettingsFromFile(NvDRSSessionHandle__ *hSession, unsigned __int16 *fileName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_439 = 0i64;
  if ( !fp_439 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_439 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD3EDE889);
  if ( !fp_439 )
    return 4294967293i64;
  v3 = fp_439;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD3EDE889, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *))v3)(hSession, fileName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD3EDE889, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11902
// RVA: 0xEBC820
__int64 __fastcall NvAPI_DRS_SaveSettingsToFile(NvDRSSessionHandle__ *hSession, unsigned __int16 *fileName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_440 = 0i64;
  if ( !fp_440 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_440 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2BE25DF8u);
  if ( !fp_440 )
    return 4294967293i64;
  v3 = fp_440;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2BE25DF8u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *))v3)(hSession, fileName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2BE25DF8u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11927
// RVA: 0xEBC950
__int64 __fastcall NvAPI_DRS_CreateProfile(
        NvDRSSessionHandle__ *hSession,
        _NVDRS_PROFILE *pProfileInfo,
        NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_441 = 0i64;
  if ( !fp_441 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_441 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCC176068);
  if ( !fp_441 )
    return 4294967293i64;
  v4 = fp_441;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCC176068, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, _NVDRS_PROFILE *, NvDRSProfileHandle__ **))v4)(
                hSession,
                pProfileInfo,
                phProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCC176068, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 11952
// RVA: 0xEBCA90
__int64 __fastcall NvAPI_DRS_DeleteProfile(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_442 = 0i64;
  if ( !fp_442 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_442 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x17093206u);
  if ( !fp_442 )
    return 4294967293i64;
  v3 = fp_442;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x17093206u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *))v3)(hSession, hProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x17093206u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 11977
// RVA: 0xEBCBC0
__int64 __fastcall NvAPI_DRS_SetCurrentGlobalProfile(
        NvDRSSessionHandle__ *hSession,
        unsigned __int16 *wszGlobalProfileName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_443 = 0i64;
  if ( !fp_443 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_443 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1C89C5DFu);
  if ( !fp_443 )
    return 4294967293i64;
  v3 = fp_443;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1C89C5DFu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *))v3)(
                hSession,
                wszGlobalProfileName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1C89C5DFu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12002
// RVA: 0xEBCCF0
__int64 __fastcall NvAPI_DRS_GetCurrentGlobalProfile(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_444 = 0i64;
  if ( !fp_444 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_444 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x617BFF9Fu);
  if ( !fp_444 )
    return 4294967293i64;
  v3 = fp_444;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x617BFF9Fu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ **))v3)(hSession, phProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x617BFF9Fu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12027
// RVA: 0xEBCE20
__int64 __fastcall NvAPI_DRS_GetProfileInfo(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        _NVDRS_PROFILE *pProfileInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_445 = 0i64;
  if ( !fp_445 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_445 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x61CD6FD6u);
  if ( !fp_445 )
    return 4294967293i64;
  v4 = fp_445;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x61CD6FD6u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_PROFILE *))v4)(
                hSession,
                hProfile,
                pProfileInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x61CD6FD6u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12052
// RVA: 0xEBCF60
__int64 __fastcall NvAPI_DRS_SetProfileInfo(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        _NVDRS_PROFILE *pProfileInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_446 = 0i64;
  if ( !fp_446 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_446 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x16ABD3A9u);
  if ( !fp_446 )
    return 4294967293i64;
  v4 = fp_446;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x16ABD3A9u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_PROFILE *))v4)(
                hSession,
                hProfile,
                pProfileInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x16ABD3A9u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12077
// RVA: 0xEBD0A0
__int64 __fastcall NvAPI_DRS_FindProfileByName(
        NvDRSSessionHandle__ *hSession,
        unsigned __int16 *profileName,
        NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_447 = 0i64;
  if ( !fp_447 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_447 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7E4A9A0Bu);
  if ( !fp_447 )
    return 4294967293i64;
  v4 = fp_447;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7E4A9A0Bu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *, NvDRSProfileHandle__ **))v4)(
                hSession,
                profileName,
                phProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7E4A9A0Bu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12102
// RVA: 0xEBD1E0
__int64 __fastcall NvAPI_DRS_EnumProfiles(
        NvDRSSessionHandle__ *hSession,
        unsigned int index,
        NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_448 = 0i64;
  if ( !fp_448 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_448 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBC371EE0);
  if ( !fp_448 )
    return 4294967293i64;
  v4 = fp_448;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBC371EE0, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, _QWORD, NvDRSProfileHandle__ **))v4)(
                hSession,
                index,
                phProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBC371EE0, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12127
// RVA: 0xEBD310
__int64 __fastcall NvAPI_DRS_GetNumProfiles(NvDRSSessionHandle__ *hSession, unsigned int *numProfiles)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_449 = 0i64;
  if ( !fp_449 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_449 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1DAE4FBCu);
  if ( !fp_449 )
    return 4294967293i64;
  v3 = fp_449;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1DAE4FBCu, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned int *))v3)(hSession, numProfiles);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1DAE4FBCu, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12152
// RVA: 0xEBD440
__int64 __fastcall NvAPI_DRS_CreateApplication(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_450 = 0i64;
  if ( !fp_450 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_450 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4347A9DEu);
  if ( !fp_450 )
    return 4294967293i64;
  v4 = fp_450;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4347A9DEu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_APPLICATION_V2 *))v4)(
                hSession,
                hProfile,
                pApplication);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4347A9DEu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12177
// RVA: 0xEBD580
__int64 __fastcall NvAPI_DRS_DeleteApplicationEx(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        _NVDRS_APPLICATION_V2 *pApp)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_451 = 0i64;
  if ( !fp_451 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_451 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC5EA85A1);
  if ( !fp_451 )
    return 4294967293i64;
  v4 = fp_451;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC5EA85A1, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_APPLICATION_V2 *))v4)(
                hSession,
                hProfile,
                pApp);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC5EA85A1, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12202
// RVA: 0xEBD6C0
__int64 __fastcall NvAPI_DRS_DeleteApplication(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned __int16 *appName)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_452 = 0i64;
  if ( !fp_452 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_452 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2C694BC6u);
  if ( !fp_452 )
    return 4294967293i64;
  v4 = fp_452;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2C694BC6u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, unsigned __int16 *))v4)(
                hSession,
                hProfile,
                appName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2C694BC6u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12227
// RVA: 0xEBD800
__int64 __fastcall NvAPI_DRS_GetApplicationInfo(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned __int16 *appName,
        _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_453 = 0i64;
  if ( !fp_453 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_453 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xED1F8C69);
  if ( !fp_453 )
    return 4294967293i64;
  v5 = fp_453;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xED1F8C69, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, unsigned __int16 *, _NVDRS_APPLICATION_V2 *, __int64 (__fastcall *)()))v5)(
                hSession,
                hProfile,
                appName,
                pApplication,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xED1F8C69, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 12252
// RVA: 0xEBD940
__int64 __fastcall NvAPI_DRS_EnumApplications(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned int startIndex,
        unsigned int *appCount,
        _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_454 = 0i64;
  if ( !fp_454 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_454 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7FA2173Au);
  if ( !fp_454 )
    return 4294967293i64;
  v6 = fp_454;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7FA2173Au, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD, unsigned int *, _NVDRS_APPLICATION_V2 *))v6)(
                hSession,
                hProfile,
                startIndex,
                appCount,
                pApplication);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7FA2173Au, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 12277
// RVA: 0xEBDA90
__int64 __fastcall NvAPI_DRS_FindApplicationByName(
        NvDRSSessionHandle__ *hSession,
        unsigned __int16 *appName,
        NvDRSProfileHandle__ **phProfile,
        _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_455 = 0i64;
  if ( !fp_455 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_455 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEEE566B2);
  if ( !fp_455 )
    return 4294967293i64;
  v5 = fp_455;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEEE566B2, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *, NvDRSProfileHandle__ **, _NVDRS_APPLICATION_V2 *, __int64 (__fastcall *)()))v5)(
                hSession,
                appName,
                phProfile,
                pApplication,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEEE566B2, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 12302
// RVA: 0xEBDBD0
__int64 __fastcall NvAPI_DRS_SetSetting(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        _NVDRS_SETTING *pSetting)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_456 = 0i64;
  if ( !fp_456 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_456 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x577DD202u);
  if ( !fp_456 )
    return 4294967293i64;
  v4 = fp_456;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x577DD202u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_SETTING *))v4)(
                hSession,
                hProfile,
                pSetting);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x577DD202u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12327
// RVA: 0xEBDD10
__int64 __fastcall NvAPI_DRS_GetSetting(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned int settingId,
        _NVDRS_SETTING *pSetting)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_457 = 0i64;
  if ( !fp_457 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_457 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x73BF8338u);
  if ( !fp_457 )
    return 4294967293i64;
  v5 = fp_457;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x73BF8338u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD, _NVDRS_SETTING *, __int64 (__fastcall *)()))v5)(
                hSession,
                hProfile,
                settingId,
                pSetting,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x73BF8338u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 12352
// RVA: 0xEBDE50
__int64 __fastcall NvAPI_DRS_EnumSettings(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned int startIndex,
        unsigned int *settingsCount,
        _NVDRS_SETTING *pSetting)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]

  hMod = 0i64;
  v10 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_458 = 0i64;
  if ( !fp_458 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_458 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE3039DA);
  if ( !fp_458 )
    return 4294967293i64;
  v6 = fp_458;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE3039DA, &v8);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD, unsigned int *, _NVDRS_SETTING *))v6)(
                hSession,
                hProfile,
                startIndex,
                settingsCount,
                pSetting);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE3039DA, v8, GpuHandle);
  --g_module_numApiInUse[v10];
  return (unsigned int)GpuHandle;
}

// File Line: 12377
// RVA: 0xEBDFA0
__int64 __fastcall NvAPI_DRS_EnumAvailableSettingIds(unsigned int *pSettingIds, unsigned int *pMaxCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_459 = 0i64;
  if ( !fp_459 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_459 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF020614A);
  if ( !fp_459 )
    return 4294967293i64;
  v3 = fp_459;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF020614A, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *))v3)(pSettingIds, pMaxCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF020614A, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12402
// RVA: 0xEBE0D0
__int64 __fastcall NvAPI_DRS_EnumAvailableSettingValues(
        unsigned int settingId,
        unsigned int *pMaxNumValues,
        _NVDRS_SETTING_VALUES *pSettingValues)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_460 = 0i64;
  if ( !fp_460 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_460 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2EC39F90u);
  if ( !fp_460 )
    return 4294967293i64;
  v4 = fp_460;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2EC39F90u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, unsigned int *, _NVDRS_SETTING_VALUES *))v4)(
                settingId,
                pMaxNumValues,
                pSettingValues);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2EC39F90u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12427
// RVA: 0xEBE200
__int64 __fastcall NvAPI_DRS_GetSettingIdFromName(unsigned __int16 *settingName, unsigned int *pSettingId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_461 = 0i64;
  if ( !fp_461 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_461 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCB7309CD);
  if ( !fp_461 )
    return 4294967293i64;
  v3 = fp_461;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCB7309CD, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(unsigned __int16 *, unsigned int *))v3)(settingName, pSettingId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCB7309CD, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12452
// RVA: 0xEBE330
__int64 __fastcall NvAPI_DRS_GetSettingNameFromId(unsigned int settingId, unsigned __int16 (*pSettingName)[2048])
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_462 = 0i64;
  if ( !fp_462 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_462 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD61CBE6E);
  if ( !fp_462 )
    return 4294967293i64;
  v3 = fp_462;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD61CBE6E, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, unsigned __int16 (*)[2048]))v3)(settingId, pSettingName);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD61CBE6E, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12477
// RVA: 0xEBE460
__int64 __fastcall NvAPI_DRS_DeleteProfileSetting(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned int settingId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_463 = 0i64;
  if ( !fp_463 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_463 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE4A26362);
  if ( !fp_463 )
    return 4294967293i64;
  v4 = fp_463;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE4A26362, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD))v4)(
                hSession,
                hProfile,
                settingId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE4A26362, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12502
// RVA: 0xEBE5A0
__int64 __fastcall NvAPI_DRS_RestoreAllDefaults(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_464 = 0i64;
  if ( !fp_464 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_464 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5927B094u);
  if ( !fp_464 )
    return 4294967293i64;
  v2 = fp_464;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5927B094u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(hSession);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5927B094u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 12527
// RVA: 0xEBE6C0
__int64 __fastcall NvAPI_DRS_RestoreProfileDefault(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_465 = 0i64;
  if ( !fp_465 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_465 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA5F6134);
  if ( !fp_465 )
    return 4294967293i64;
  v3 = fp_465;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA5F6134, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *))v3)(hSession, hProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA5F6134, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12552
// RVA: 0xEBE7F0
__int64 __fastcall NvAPI_DRS_RestoreProfileDefaultSetting(
        NvDRSSessionHandle__ *hSession,
        NvDRSProfileHandle__ *hProfile,
        unsigned int settingId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_466 = 0i64;
  if ( !fp_466 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_466 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x53F0381Eu);
  if ( !fp_466 )
    return 4294967293i64;
  v4 = fp_466;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x53F0381Eu, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD))v4)(
                hSession,
                hProfile,
                settingId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x53F0381Eu, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12577
// RVA: 0xEBE930
__int64 __fastcall NvAPI_DRS_GetBaseProfile(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_467 = 0i64;
  if ( !fp_467 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_467 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA8466A0);
  if ( !fp_467 )
    return 4294967293i64;
  v3 = fp_467;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA8466A0, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ **))v3)(hSession, phProfile);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA8466A0, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12602
// RVA: 0xEBEA60
__int64 __fastcall NvAPI_Event_RegisterCallback(NV_EVENT_REGISTER_CALLBACK *eventCallback, NvEventHandle__ **phClient)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_468 = 0i64;
  if ( !fp_468 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_468 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE6DBEA69);
  if ( !fp_468 )
    return 4294967293i64;
  v3 = fp_468;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE6DBEA69, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_EVENT_REGISTER_CALLBACK *, NvEventHandle__ **))v3)(
                eventCallback,
                phClient);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE6DBEA69, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12627
// RVA: 0xEBEB90
__int64 __fastcall NvAPI_Event_UnregisterCallback(NvEventHandle__ *hClient)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_469 = 0i64;
  if ( !fp_469 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_469 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDE1F9B45);
  if ( !fp_469 )
    return 4294967293i64;
  v2 = fp_469;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDE1F9B45, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NvEventHandle__ *))v2)(hClient);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDE1F9B45, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 12652
// RVA: 0xEBECB0
__int64 __fastcall NvAPI_GPU_GetCurrentThermalLevel(NvPhysicalGpuHandle__ *nvGPUHandle, NV_EVENT_LEVEL *pThermalLevel)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_470 = 0i64;
  if ( !fp_470 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_470 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2488B79);
  if ( !fp_470 )
    return 4294967293i64;
  v3 = fp_470;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2488B79, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_EVENT_LEVEL *))v3)(nvGPUHandle, pThermalLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2488B79, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12677
// RVA: 0xEBEDE0
signed __int64 __fastcall NvAPI_GPU_GetCurrentFanSpeedLevel(
        NvPhysicalGpuHandle__ *nvGPUHandle,
        NV_EVENT_LEVEL *pFanSpeedLevel)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_471 = 0i64;
  if ( !fp_471 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_471 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBD71F0C9);
  if ( !fp_471 )
    return 4294967293i64;
  v3 = fp_471;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBD71F0C9, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_EVENT_LEVEL *))v3)(nvGPUHandle, pFanSpeedLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBD71F0C9, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12702
// RVA: 0xEBEF10
__int64 __fastcall NvAPI_GPU_SetScanoutIntensity(
        unsigned int displayId,
        NV_SCANOUT_INTENSITY_DATA *scanoutIntensityData,
        int *pbSticky)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_472 = 0i64;
  if ( !fp_472 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_472 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA57457A4);
  if ( !fp_472 )
    return 4294967293i64;
  v4 = fp_472;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA57457A4, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NV_SCANOUT_INTENSITY_DATA *, int *))v4)(
                displayId,
                scanoutIntensityData,
                pbSticky);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA57457A4, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12727
// RVA: 0xEBF040
__int64 __fastcall NvAPI_GPU_SetScanoutWarping(
        unsigned int displayId,
        NV_SCANOUT_WARPING_DATA *scanoutWarpingData,
        int *piMaxNumVertices,
        int *pbSticky)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_473 = 0i64;
  if ( !fp_473 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_473 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB34BAB4F);
  if ( !fp_473 )
    return 4294967293i64;
  v5 = fp_473;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB34BAB4F, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NV_SCANOUT_WARPING_DATA *, int *, int *, __int64 (__fastcall *)()))v5)(
                displayId,
                scanoutWarpingData,
                piMaxNumVertices,
                pbSticky,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB34BAB4F, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 12752
// RVA: 0xEBF180
__int64 __fastcall NvAPI_GPU_GetScanoutConfiguration(unsigned int displayId, NvSBox *desktopRect, NvSBox *scanoutRect)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v8 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_474 = 0i64;
  if ( !fp_474 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_474 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6A9F5B63u);
  if ( !fp_474 )
    return 4294967293i64;
  v4 = fp_474;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6A9F5B63u, &v6);
  GpuHandle = ((unsigned int (__fastcall *)(_QWORD, NvSBox *, NvSBox *))v4)(displayId, desktopRect, scanoutRect);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6A9F5B63u, v6, GpuHandle);
  --g_module_numApiInUse[v8];
  return (unsigned int)GpuHandle;
}

// File Line: 12777
// RVA: 0xEBF2B0
__int64 __fastcall NvAPI_DISP_SetHCloneTopology(NV_HCLONE_TOPOLOGY_V1 *pHCloneTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_475 = 0i64;
  if ( !fp_475 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_475 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x61041C24u);
  if ( !fp_475 )
    return 4294967293i64;
  v2 = fp_475;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x61041C24u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_HCLONE_TOPOLOGY_V1 *))v2)(pHCloneTopology);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x61041C24u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 12802
// RVA: 0xEBF3D0
__int64 __fastcall NvAPI_DISP_GetHCloneTopology(NV_HCLONE_TOPOLOGY_V1 *pHCloneTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v4; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v6 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_476 = 0i64;
  if ( !fp_476 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_476 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x47BAD137u);
  if ( !fp_476 )
    return 4294967293i64;
  v2 = fp_476;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x47BAD137u, &v4);
  GpuHandle = ((unsigned int (__fastcall *)(NV_HCLONE_TOPOLOGY_V1 *))v2)(pHCloneTopology);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x47BAD137u, v4, GpuHandle);
  --g_module_numApiInUse[v6];
  return (unsigned int)GpuHandle;
}

// File Line: 12827
// RVA: 0xEBF4F0
__int64 __fastcall NvAPI_DISP_ValidateHCloneTopology(NV_HCLONE_TOPOLOGY_V1 *pHCloneTopology, unsigned int *pValid)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_477 = 0i64;
  if ( !fp_477 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_477 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F4C2664u);
  if ( !fp_477 )
    return 4294967293i64;
  v3 = fp_477;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F4C2664u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NV_HCLONE_TOPOLOGY_V1 *, unsigned int *))v3)(pHCloneTopology, pValid);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F4C2664u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12852
// RVA: 0xEBF620
__int64 __fastcall NvAPI_GPU_GetPerfDecreaseInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pPerfDecrInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v5; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v7 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_478 = 0i64;
  if ( !fp_478 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_478 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7F7F4600u);
  if ( !fp_478 )
    return 4294967293i64;
  v3 = fp_478;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7F7F4600u, &v5);
  GpuHandle = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(hPhysicalGpu, pPerfDecrInfo);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7F7F4600u, v5, GpuHandle);
  --g_module_numApiInUse[v7];
  return (unsigned int)GpuHandle;
}

// File Line: 12877
// RVA: 0xEBF750
__int64 __fastcall NvAPI_D3D1x_IFR_SetUpTargetBufferToSys(
        IUnknown *pDevice,
        unsigned int eFormat,
        unsigned int dwNBuffers,
        void **ppBuffers)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v9 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_479 = 0i64;
  if ( !fp_479 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_479 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x473F7828u);
  if ( !fp_479 )
    return 4294967293i64;
  v5 = fp_479;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x473F7828u, &v7);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, _QWORD, _QWORD, void **, __int64 (__fastcall *)()))v5)(
                pDevice,
                eFormat,
                dwNBuffers,
                ppBuffers,
                v5);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x473F7828u, v7, GpuHandle);
  --g_module_numApiInUse[v9];
  return (unsigned int)GpuHandle;
}

// File Line: 12902
// RVA: 0xEBF890
__int64 __fastcall NvAPI_D3D1x_IFR_TransferRenderTarget(
        IUnknown *pDevice,
        void **pEvent,
        unsigned int dwBufferIndex,
        unsigned int dwTargetWidth,
        unsigned int dwTargetHeight,
        unsigned int dwRenderTargetIndex,
        unsigned int dwRenderTargetArraySlice)
{
  __int64 (__fastcall *v8)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h] BYREF
  unsigned __int64 v10; // [rsp+50h] [rbp-18h] BYREF
  _NvAPI_Status GpuHandle; // [rsp+58h] [rbp-10h]
  int v12; // [rsp+5Ch] [rbp-Ch]

  hMod = 0i64;
  v12 = 0;
  GpuHandle = (unsigned int)GetGpuHandle(&hMod);
  if ( GpuHandle && GpuHandle != NVAPI_INVALID_POINTER )
    return (unsigned int)GpuHandle;
  if ( GpuHandle == NVAPI_INVALID_POINTER )
    fp_480 = 0i64;
  if ( !fp_480 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_480 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9FBAE4EB);
  if ( !fp_480 )
    return 4294967293i64;
  v8 = fp_480;
  v10 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9FBAE4EB, &v10);
  GpuHandle = ((unsigned int (__fastcall *)(IUnknown *, void **, _QWORD, _QWORD, unsigned int, unsigned int, unsigned int))v8)(
                pDevice,
                pEvent,
                dwBufferIndex,
                dwTargetWidth,
                dwTargetHeight,
                dwRenderTargetIndex,
                dwRenderTargetArraySlice);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9FBAE4EB, v10, GpuHandle);
  --g_module_numApiInUse[v12];
  return (unsigned int)GpuHandle;
}

