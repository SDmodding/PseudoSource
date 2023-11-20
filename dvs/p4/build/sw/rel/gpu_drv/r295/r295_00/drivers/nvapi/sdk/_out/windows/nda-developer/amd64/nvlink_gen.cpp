// File Line: 117
// RVA: 0xE9ACB0
__int64 __fastcall NvAPI_Initialize()
{
  HINSTANCE__ *hMod; // [rsp+20h] [rbp-18h]
  unsigned int v2; // [rsp+28h] [rbp-10h]

  v2 = GetGpuHandle(&hMod);
  if ( v2 == -14 )
    v2 = 0;
  return v2;
}

// File Line: 129
// RVA: 0xE9ACE0
void __fastcall updateModulePrivateData(HINSTANCE__ *hMod, _NVAPI_MODULE_ID moduleId)
{
  char *v2; // ST08_8

  v2 = (char *)hMod + *((signed int *)hMod + 15) + 4;
  g_module_privateData[moduleId].checksum = *(_DWORD *)((char *)hMod + *((signed int *)hMod + 15) + 88);
  g_module_privateData[moduleId].TimeDateStamp = *((_DWORD *)v2 + 1);
}

// File Line: 141
// RVA: 0xE9AD60
char __fastcall NeedtoRefreshFunctionPointer(HINSTANCE__ *hMod, _NVAPI_MODULE_ID moduleId)
{
  __int64 v2; // rcx
  char *v4; // [rsp+8h] [rbp-20h]
  HINSTANCE__ *v5; // [rsp+30h] [rbp+8h]

  v5 = hMod;
  v4 = (char *)hMod + *((signed int *)hMod + 15) + 4;
  v2 = *((signed int *)hMod + 15);
  if ( *(_DWORD *)((char *)v5 + v2 + 88) )
  {
    if ( *(_DWORD *)((char *)v5 + v2 + 88) != g_module_privateData[moduleId].checksum )
    {
      g_module_privateData[moduleId].checksum = *(_DWORD *)((char *)v5 + v2 + 88);
      g_module_privateData[moduleId].TimeDateStamp = *((_DWORD *)v4 + 1);
      return 1;
    }
  }
  else if ( *((_DWORD *)v4 + 1) != g_module_privateData[moduleId].TimeDateStamp )
  {
    g_module_privateData[moduleId].checksum = *(_DWORD *)((char *)v5 + v2 + 88);
    g_module_privateData[moduleId].TimeDateStamp = *((_DWORD *)v4 + 1);
    return 1;
  }
  return 0;
}

// File Line: 171
// RVA: 0xE9AE60
signed __int64 __fastcall Module_InitializeHelper(HINSTANCE__ *hMod, _NVAPI_MODULE_ID moduleId)
{
  unsigned int (*v3)(void); // [rsp+20h] [rbp-18h]

  if ( moduleId )
  {
    if ( moduleId == 1 )
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
    v3 = (unsigned int (*)(void))g_nvapi_lpNvAPI_gpuQueryInterface(0x150E828u);
    if ( !v3 )
    {
      g_nvapi_lpNvAPI_gpuQueryInterface = 0i64;
      return 0xFFFFFFFFi64;
    }
    if ( v3() )
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
  signed __int64 result; // rax
  int v2; // [rsp+20h] [rbp-18h]
  unsigned int v3; // [rsp+24h] [rbp-14h]
  unsigned int v4; // [rsp+24h] [rbp-14h]
  HINSTANCE__ **v5; // [rsp+40h] [rbp+8h]

  v5 = hMod;
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
  *v5 = GetModuleHandleA("nvapi64.dll");
  if ( *v5 )
  {
    if ( NeedtoRefreshFunctionPointer(*v5, 0) )
    {
      v4 = Module_InitializeHelper(*v5, 0);
      if ( v4 )
      {
        --g_module_numApiInUse[0];
        FreeLibrary(*v5);
        result = v4;
      }
      else
      {
        g_nvapi_gpuHModule = *v5;
        updateModulePrivateData(*v5, 0);
        result = 4294967282i64;
      }
    }
    else
    {
      result = 0i64;
    }
  }
  else
  {
    *v5 = LoadLibraryA("nvapi64.dll");
    if ( *v5 )
    {
      v3 = Module_InitializeHelper(*v5, 0);
      if ( v3 )
      {
        --g_module_numApiInUse[0];
        FreeLibrary(*v5);
        result = v3;
      }
      else
      {
        g_nvapi_gpuHModule = *v5;
        updateModulePrivateData(*v5, 0);
        result = 4294967282i64;
      }
    }
    else
    {
      --g_module_numApiInUse[0];
      bAttempted = 1;
      result = 4294967294i64;
    }
  }
  return result;
}

// File Line: 272
// RVA: 0xE9B170
signed __int64 __fastcall GetPepHandle(HINSTANCE__ **hMod)
{
  signed __int64 result; // rax
  unsigned int v2; // [rsp+20h] [rbp-18h]
  unsigned int v3; // [rsp+20h] [rbp-18h]
  HINSTANCE__ **v4; // [rsp+40h] [rbp+8h]

  v4 = hMod;
  while ( byte_1424BF561 )
    Sleep(0x64u);
  ++dword_1424BF58C;
  *v4 = GetModuleHandleA("nvpowerapi.dll");
  if ( *v4 )
  {
    if ( NeedtoRefreshFunctionPointer(*v4, NVAPI_MODULE_PEP) )
    {
      v3 = Module_InitializeHelper(*v4, NVAPI_MODULE_PEP);
      if ( v3 )
      {
        --dword_1424BF58C;
        result = v3;
      }
      else
      {
        g_nvapi_pepHModule = *v4;
        updateModulePrivateData(*v4, NVAPI_MODULE_PEP);
        result = 4294967282i64;
      }
    }
    else
    {
      result = 0i64;
    }
  }
  else
  {
    *v4 = LoadLibraryA("nvpowerapi.dll");
    if ( *v4 )
    {
      v2 = Module_InitializeHelper(*v4, NVAPI_MODULE_PEP);
      if ( v2 )
      {
        --dword_1424BF58C;
        result = v2;
      }
      else
      {
        g_nvapi_pepHModule = *v4;
        updateModulePrivateData(*v4, NVAPI_MODULE_PEP);
        result = 4294967282i64;
      }
    }
    else
    {
      --dword_1424BF58C;
      result = 4294967294i64;
    }
  }
  return result;
}

// File Line: 318
// RVA: 0xE9B2E0
signed __int64 __fastcall NvAPI_Unload()
{
  signed __int64 result; // rax
  unsigned int (*v1)(void); // [rsp+20h] [rbp-18h]

  g_nvapi_moduleUnloadPending[0] = 1;
  if ( g_nvapi_gpuHModule && g_nvapi_lpNvAPI_gpuQueryInterface )
  {
    if ( g_module_numApiInUse[0] )
    {
      g_nvapi_moduleUnloadPending[0] = 0;
      result = 0xFFFFFFFFi64;
    }
    else
    {
      v1 = (unsigned int (*)(void))g_nvapi_lpNvAPI_gpuQueryInterface(0xD22BDD7E);
      if ( v1 )
      {
        if ( v1() )
        {
          g_nvapi_moduleUnloadPending[0] = 0;
          result = 0xFFFFFFFFi64;
        }
        else
        {
          g_nvapi_lpNvAPI_gpuQueryInterface = 0i64;
          FreeLibrary(g_nvapi_gpuHModule);
          g_nvapi_gpuHModule = 0i64;
          g_nvapi_callStart = 0i64;
          g_nvapi_callReturn = 0i64;
          g_nvapi_moduleUnloadPending[0] = 0;
          result = 0i64;
        }
      }
      else
      {
        g_nvapi_moduleUnloadPending[0] = 0;
        result = 4294967293i64;
      }
    }
  }
  else
  {
    g_nvapi_moduleUnloadPending[0] = 0;
    result = 4294967292i64;
  }
  return result;
}

// File Line: 362
// RVA: 0xE9B3C0
signed __int64 __fastcall NvAPI_Power_Unload()
{
  signed __int64 result; // rax

  byte_1424BF561 = 1;
  if ( g_nvapi_pepHModule && g_nvapi_lpNvAPI_pepQueryInterface )
  {
    if ( dword_1424BF58C )
    {
      byte_1424BF561 = 0;
      result = 0xFFFFFFFFi64;
    }
    else
    {
      g_nvapi_lpNvAPI_pepQueryInterface = 0i64;
      FreeLibrary(g_nvapi_pepHModule);
      g_nvapi_pepHModule = 0i64;
      byte_1424BF561 = 0;
      result = 0i64;
    }
  }
  else
  {
    byte_1424BF561 = 0;
    result = 4294967292i64;
  }
  return result;
}

// File Line: 877
// RVA: 0xE9B450
signed __int64 __fastcall NvAPI_GetErrorMessage(_NvAPI_Status nr, char *szDesc)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  _NvAPI_Status v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szDesc;
  v8 = nr;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp = 0i64;
  if ( !fp && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6C2D048Cu);
  if ( !fp )
    return 4294967293i64;
  v3 = fp;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6C2D048Cu, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6C2D048Cu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 902
// RVA: 0xE9B580
signed __int64 __fastcall NvAPI_GetInterfaceVersionString(char *szDesc)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  char *v7; // [rsp+50h] [rbp+8h]

  v7 = szDesc;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_0 = 0i64;
  if ( !fp_0 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_0 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1053FA5u);
  if ( !fp_0 )
    return 4294967293i64;
  v2 = fp_0;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1053FA5u, &v4);
  v5 = ((unsigned int (__fastcall *)(char *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1053FA5u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 927
// RVA: 0xE9B6A0
signed __int64 __fastcall NvAPI_GetDisplayDriverVersion(NvDisplayHandle__ *hNvDisplay, NV_DISPLAY_DRIVER_VERSION *pVersion)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_DISPLAY_DRIVER_VERSION *v9; // [rsp+58h] [rbp+10h]

  v9 = pVersion;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_1 = 0i64;
  if ( !fp_1 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_1 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF951A4D1);
  if ( !fp_1 )
    return 4294967293i64;
  v3 = fp_1;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF951A4D1, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_DRIVER_VERSION *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF951A4D1, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 952
// RVA: 0xE9B7D0
signed __int64 __fastcall NvAPI_SYS_GetDriverAndBranchVersion(unsigned int *pDriverVersion, char *szBuildBranchString)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szBuildBranchString;
  v8 = pDriverVersion;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_2 = 0i64;
  if ( !fp_2 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_2 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2926AAADu);
  if ( !fp_2 )
    return 4294967293i64;
  v3 = fp_2;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2926AAADu, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2926AAADu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 977
// RVA: 0xE9B900
signed __int64 __fastcall NvAPI_EnumNvidiaDisplayHandle(unsigned int thisEnum, NvDisplayHandle__ **pNvDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  NvDisplayHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pNvDispHandle;
  v8 = thisEnum;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_3 = 0i64;
  if ( !fp_3 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_3 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9ABDD40D);
  if ( !fp_3 )
    return 4294967293i64;
  v3 = fp_3;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9ABDD40D, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, NvDisplayHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9ABDD40D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1002
// RVA: 0xE9BA30
signed __int64 __fastcall NvAPI_EnumNvidiaUnAttachedDisplayHandle(unsigned int thisEnum, NvUnAttachedDisplayHandle__ **pNvUnAttachedDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  NvUnAttachedDisplayHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pNvUnAttachedDispHandle;
  v8 = thisEnum;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_4 = 0i64;
  if ( !fp_4 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_4 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x20DE9260u);
  if ( !fp_4 )
    return 4294967293i64;
  v3 = fp_4;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x20DE9260u, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, NvUnAttachedDisplayHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x20DE9260u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1027
// RVA: 0xE9BB60
signed __int64 __fastcall NvAPI_EnumPhysicalGPUs(NvPhysicalGpuHandle__ **nvGPUHandle, unsigned int *pGpuCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ **v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pGpuCount;
  v8 = nvGPUHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_5 = 0i64;
  if ( !fp_5 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_5 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE5AC921F);
  if ( !fp_5 )
    return 4294967293i64;
  v3 = fp_5;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE5AC921F, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ **, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE5AC921F, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1052
// RVA: 0xE9BC90
signed __int64 __fastcall NvAPI_EnumLogicalGPUs(NvLogicalGpuHandle__ **nvGPUHandle, unsigned int *pGpuCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvLogicalGpuHandle__ **v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pGpuCount;
  v8 = nvGPUHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_6 = 0i64;
  if ( !fp_6 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_6 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x48B3EA59u);
  if ( !fp_6 )
    return 4294967293i64;
  v3 = fp_6;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x48B3EA59u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvLogicalGpuHandle__ **, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x48B3EA59u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1077
// RVA: 0xE9BDC0
signed __int64 __fastcall NvAPI_GetPhysicalGPUsFromDisplay(NvDisplayHandle__ *hNvDisp, NvPhysicalGpuHandle__ **nvGPUHandle, unsigned int *pGpuCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvPhysicalGpuHandle__ **v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pGpuCount;
  v10 = nvGPUHandle;
  v9 = hNvDisp;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_7 = 0i64;
  if ( !fp_7 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_7 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x34EF9506u);
  if ( !fp_7 )
    return 4294967293i64;
  v4 = fp_7;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x34EF9506u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NvPhysicalGpuHandle__ **, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x34EF9506u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1102
// RVA: 0xE9BF00
signed __int64 __fastcall NvAPI_GetPhysicalGPUFromUnAttachedDisplay(NvUnAttachedDisplayHandle__ *hNvUnAttachedDisp, NvPhysicalGpuHandle__ **pPhysicalGpu)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvUnAttachedDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvPhysicalGpuHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pPhysicalGpu;
  v8 = hNvUnAttachedDisp;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_8 = 0i64;
  if ( !fp_8 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_8 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5018ED61u);
  if ( !fp_8 )
    return 4294967293i64;
  v3 = fp_8;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5018ED61u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvUnAttachedDisplayHandle__ *, NvPhysicalGpuHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5018ED61u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1127
// RVA: 0xE9C030
signed __int64 __fastcall NvAPI_CreateDisplayFromUnAttachedDisplay(NvUnAttachedDisplayHandle__ *hNvUnAttachedDisp, NvDisplayHandle__ **pNvDisplay)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvUnAttachedDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvDisplayHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pNvDisplay;
  v8 = hNvUnAttachedDisp;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_9 = 0i64;
  if ( !fp_9 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_9 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63F9799Eu);
  if ( !fp_9 )
    return 4294967293i64;
  v3 = fp_9;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63F9799Eu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvUnAttachedDisplayHandle__ *, NvDisplayHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63F9799Eu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1152
// RVA: 0xE9C160
signed __int64 __fastcall NvAPI_GetLogicalGPUFromDisplay(NvDisplayHandle__ *hNvDisp, NvLogicalGpuHandle__ **pLogicalGPU)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvLogicalGpuHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pLogicalGPU;
  v8 = hNvDisp;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_10 = 0i64;
  if ( !fp_10 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_10 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEE1370CF);
  if ( !fp_10 )
    return 4294967293i64;
  v3 = fp_10;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEE1370CF, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NvLogicalGpuHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEE1370CF, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1177
// RVA: 0xE9C290
signed __int64 __fastcall NvAPI_GetLogicalGPUFromPhysicalGPU(NvPhysicalGpuHandle__ *hPhysicalGPU, NvLogicalGpuHandle__ **pLogicalGPU)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvLogicalGpuHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pLogicalGPU;
  v8 = hPhysicalGPU;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_11 = 0i64;
  if ( !fp_11 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_11 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xADD604D1);
  if ( !fp_11 )
    return 4294967293i64;
  v3 = fp_11;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xADD604D1, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NvLogicalGpuHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xADD604D1, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1202
// RVA: 0xE9C3C0
signed __int64 __fastcall NvAPI_GetPhysicalGPUsFromLogicalGPU(NvLogicalGpuHandle__ *hLogicalGPU, NvPhysicalGpuHandle__ **hPhysicalGPU, unsigned int *pGpuCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvLogicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvPhysicalGpuHandle__ **v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pGpuCount;
  v10 = hPhysicalGPU;
  v9 = hLogicalGPU;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_12 = 0i64;
  if ( !fp_12 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_12 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAEA3FA32);
  if ( !fp_12 )
    return 4294967293i64;
  v4 = fp_12;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAEA3FA32, &v6);
  v7 = ((unsigned int (__fastcall *)(NvLogicalGpuHandle__ *, NvPhysicalGpuHandle__ **, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAEA3FA32, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1227
// RVA: 0xE9C500
signed __int64 __fastcall NvAPI_GetAssociatedNvidiaDisplayHandle(const char *szDisplayName, NvDisplayHandle__ **pNvDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  const char *v8; // [rsp+50h] [rbp+8h]
  NvDisplayHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pNvDispHandle;
  v8 = szDisplayName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_13 = 0i64;
  if ( !fp_13 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_13 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x35C29134u);
  if ( !fp_13 )
    return 4294967293i64;
  v3 = fp_13;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x35C29134u, &v5);
  v6 = ((unsigned int (__fastcall *)(const char *, NvDisplayHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x35C29134u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1252
// RVA: 0xE9C630
signed __int64 __fastcall NvAPI_DISP_GetAssociatedUnAttachedNvidiaDisplayHandle(const char *szDisplayName, NvUnAttachedDisplayHandle__ **pNvUnAttachedDispHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  const char *v8; // [rsp+50h] [rbp+8h]
  NvUnAttachedDisplayHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pNvUnAttachedDispHandle;
  v8 = szDisplayName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_14 = 0i64;
  if ( !fp_14 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_14 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA70503B2);
  if ( !fp_14 )
    return 4294967293i64;
  v3 = fp_14;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA70503B2, &v5);
  v6 = ((unsigned int (__fastcall *)(const char *, NvUnAttachedDisplayHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA70503B2, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1277
// RVA: 0xE9C760
signed __int64 __fastcall NvAPI_GetAssociatedNvidiaDisplayName(NvDisplayHandle__ *NvDispHandle, char *szDisplayName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szDisplayName;
  v8 = NvDispHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_15 = 0i64;
  if ( !fp_15 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_15 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22A78B05u);
  if ( !fp_15 )
    return 4294967293i64;
  v3 = fp_15;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22A78B05u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22A78B05u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1302
// RVA: 0xE9C890
signed __int64 __fastcall NvAPI_GetUnAttachedAssociatedDisplayName(NvUnAttachedDisplayHandle__ *hNvUnAttachedDisp, char *szDisplayName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvUnAttachedDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szDisplayName;
  v8 = hNvUnAttachedDisp;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_16 = 0i64;
  if ( !fp_16 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_16 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4888D790u);
  if ( !fp_16 )
    return 4294967293i64;
  v3 = fp_16;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4888D790u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvUnAttachedDisplayHandle__ *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4888D790u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1327
// RVA: 0xE9C9C0
signed __int64 __fastcall NvAPI_EnableHWCursor(NvDisplayHandle__ *hNvDisplay)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hNvDisplay;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_17 = 0i64;
  if ( !fp_17 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_17 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2863148Du);
  if ( !fp_17 )
    return 4294967293i64;
  v2 = fp_17;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2863148Du, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2863148Du, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 1352
// RVA: 0xE9CAE0
signed __int64 __fastcall NvAPI_DisableHWCursor(NvDisplayHandle__ *hNvDisplay)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hNvDisplay;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_18 = 0i64;
  if ( !fp_18 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_18 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAB163097);
  if ( !fp_18 )
    return 4294967293i64;
  v2 = fp_18;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAB163097, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAB163097, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 1377
// RVA: 0xE9CC00
signed __int64 __fastcall NvAPI_GetVBlankCounter(NvDisplayHandle__ *hNvDisplay, unsigned int *pCounter)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCounter;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_19 = 0i64;
  if ( !fp_19 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_19 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x67B5DB55u);
  if ( !fp_19 )
    return 4294967293i64;
  v3 = fp_19;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x67B5DB55u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x67B5DB55u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1402
// RVA: 0xE9CD30
signed __int64 __fastcall NvAPI_SetRefreshRateOverride(NvDisplayHandle__ *hNvDisplay, unsigned int outputsMask, float refreshRate, unsigned int bSetDeferred)
{
  __int64 v4; // r8
  __int64 (__fastcall *v6)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+38h] [rbp-10h]
  int v10; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v11; // [rsp+50h] [rbp+8h]
  unsigned int v12; // [rsp+58h] [rbp+10h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = bSetDeferred;
  v12 = outputsMask;
  v11 = hNvDisplay;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_20 = 0i64;
  if ( !fp_20 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_20 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3092AC32u);
  if ( !fp_20 )
    return 4294967293i64;
  v6 = fp_20;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3092AC32u, &v8);
  v9 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, __int64, _QWORD))v6)(v11, v12, v4, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3092AC32u, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 1427
// RVA: 0xE9CE70
signed __int64 __fastcall NvAPI_GetAssociatedDisplayOutputId(NvDisplayHandle__ *hNvDisplay, unsigned int *pOutputId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputId;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_21 = 0i64;
  if ( !fp_21 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_21 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD995937E);
  if ( !fp_21 )
    return 4294967293i64;
  v3 = fp_21;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD995937E, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD995937E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1452
// RVA: 0xE9CFA0
signed __int64 __fastcall NvAPI_GetDisplayPortInfo(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_PORT_INFO *pInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_PORT_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_22 = 0i64;
  if ( !fp_22 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_22 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC64FF367);
  if ( !fp_22 )
    return 4294967293i64;
  v4 = fp_22;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC64FF367, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_PORT_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC64FF367, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1477
// RVA: 0xE9D0D0
signed __int64 __fastcall NvAPI_SetDisplayPort(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_PORT_CONFIG *pCfg)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_PORT_CONFIG *v11; // [rsp+60h] [rbp+18h]

  v11 = pCfg;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_23 = 0i64;
  if ( !fp_23 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_23 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA13E65A);
  if ( !fp_23 )
    return 4294967293i64;
  v4 = fp_23;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA13E65A, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_PORT_CONFIG *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA13E65A, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1502
// RVA: 0xE9D200
signed __int64 __fastcall NvAPI_GetHDMISupportInfo(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_HDMI_SUPPORT_INFO *pInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_HDMI_SUPPORT_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_24 = 0i64;
  if ( !fp_24 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_24 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6AE16EC3u);
  if ( !fp_24 )
    return 4294967293i64;
  v4 = fp_24;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6AE16EC3u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_HDMI_SUPPORT_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6AE16EC3u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1527
// RVA: 0xE9D330
signed __int64 __fastcall NvAPI_DISP_EnumHDMIStereoModes(NV_HDMI_STEREO_MODES_LIST_V1 *pHDMIStereoModes)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_HDMI_STEREO_MODES_LIST_V1 *v7; // [rsp+50h] [rbp+8h]

  v7 = pHDMIStereoModes;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_25 = 0i64;
  if ( !fp_25 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_25 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2CCF5D6);
  if ( !fp_25 )
    return 4294967293i64;
  v2 = fp_25;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2CCF5D6, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_HDMI_STEREO_MODES_LIST_V1 *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2CCF5D6, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 1552
// RVA: 0xE9D450
signed __int64 __fastcall NvAPI_GetInfoFrame(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, _NV_INFOFRAME_TYPE type, NV_INFOFRAME *pInfoFrame)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  _NV_INFOFRAME_TYPE v12; // [rsp+60h] [rbp+18h]
  NV_INFOFRAME *v13; // [rsp+68h] [rbp+20h]

  v13 = pInfoFrame;
  v12 = type;
  v11 = outputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_26 = 0i64;
  if ( !fp_26 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_26 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9734F1Du);
  if ( !fp_26 )
    return 4294967293i64;
  v5 = fp_26;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9734F1Du, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_INFOFRAME *))v5)(
         v10,
         v11,
         (unsigned int)v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9734F1Du, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 1577
// RVA: 0xE9D590
signed __int64 __fastcall NvAPI_SetInfoFrame(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, _NV_INFOFRAME_TYPE type, NV_INFOFRAME *pInfoFrame)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  _NV_INFOFRAME_TYPE v12; // [rsp+60h] [rbp+18h]
  NV_INFOFRAME *v13; // [rsp+68h] [rbp+20h]

  v13 = pInfoFrame;
  v12 = type;
  v11 = outputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_27 = 0i64;
  if ( !fp_27 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_27 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x69C6F365u);
  if ( !fp_27 )
    return 4294967293i64;
  v5 = fp_27;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x69C6F365u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_INFOFRAME *))v5)(
         v10,
         v11,
         (unsigned int)v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x69C6F365u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 1602
// RVA: 0xE9D6D0
signed __int64 __fastcall NvAPI_SetInfoFrameState(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, _NV_INFOFRAME_TYPE type, _NV_INFOFRAME_STATE *pState)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  _NV_INFOFRAME_TYPE v12; // [rsp+60h] [rbp+18h]
  _NV_INFOFRAME_STATE *v13; // [rsp+68h] [rbp+20h]

  v13 = pState;
  v12 = type;
  v11 = outputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_28 = 0i64;
  if ( !fp_28 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_28 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x67EFD887u);
  if ( !fp_28 )
    return 4294967293i64;
  v5 = fp_28;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x67EFD887u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, _NV_INFOFRAME_STATE *))v5)(
         v10,
         v11,
         (unsigned int)v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x67EFD887u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 1627
// RVA: 0xE9D810
signed __int64 __fastcall NvAPI_GetInfoFrameState(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, _NV_INFOFRAME_TYPE type, _NV_INFOFRAME_STATE *pState)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  _NV_INFOFRAME_TYPE v12; // [rsp+60h] [rbp+18h]
  _NV_INFOFRAME_STATE *v13; // [rsp+68h] [rbp+20h]

  v13 = pState;
  v12 = type;
  v11 = outputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_29 = 0i64;
  if ( !fp_29 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_29 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x41511594u);
  if ( !fp_29 )
    return 4294967293i64;
  v5 = fp_29;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x41511594u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, _NV_INFOFRAME_STATE *))v5)(
         v10,
         v11,
         (unsigned int)v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x41511594u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 1652
// RVA: 0xE9D950
signed __int64 __fastcall NvAPI_Disp_InfoFrameControl(unsigned int displayId, NV_INFOFRAME_DATA *pInfoframeData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  NV_INFOFRAME_DATA *v9; // [rsp+58h] [rbp+10h]

  v9 = pInfoframeData;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_30 = 0i64;
  if ( !fp_30 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_30 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6067AF3Fu);
  if ( !fp_30 )
    return 4294967293i64;
  v3 = fp_30;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6067AF3Fu, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, NV_INFOFRAME_DATA *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6067AF3Fu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1677
// RVA: 0xE9DA80
signed __int64 __fastcall NvAPI_Disp_ColorControl(unsigned int displayId, NV_COLOR_DATA *pColorData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  NV_COLOR_DATA *v9; // [rsp+58h] [rbp+10h]

  v9 = pColorData;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_31 = 0i64;
  if ( !fp_31 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_31 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x92F9D80D);
  if ( !fp_31 )
    return 4294967293i64;
  v3 = fp_31;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x92F9D80D, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, NV_COLOR_DATA *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x92F9D80D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1702
// RVA: 0xE9DBB0
signed __int64 __fastcall NvAPI_DISP_GetVirtualModeData(unsigned int displayId, NV_VIRTUALMODE_DATA *virtualModeData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  NV_VIRTUALMODE_DATA *v9; // [rsp+58h] [rbp+10h]

  v9 = virtualModeData;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_32 = 0i64;
  if ( !fp_32 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_32 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3230D69Au);
  if ( !fp_32 )
    return 4294967293i64;
  v3 = fp_32;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3230D69Au, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, NV_VIRTUALMODE_DATA *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3230D69Au, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1727
// RVA: 0xE9DCE0
signed __int64 __fastcall NvAPI_DISP_OverrideDisplayModeList(unsigned int displayId, unsigned int modeCount, _NV_DISPLAY_MODE_INFO *modeList, unsigned int enableOutput)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  _NV_DISPLAY_MODE_INFO *v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = enableOutput;
  v12 = modeList;
  v11 = modeCount;
  v10 = displayId;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_33 = 0i64;
  if ( !fp_33 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_33 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x291BFF2u);
  if ( !fp_33 )
    return 4294967293i64;
  v5 = fp_33;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x291BFF2u, &v7);
  v8 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _NV_DISPLAY_MODE_INFO *, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x291BFF2u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 1752
// RVA: 0xE9DE20
signed __int64 __fastcall NvAPI_GetDisplayDriverMemoryInfo(NvDisplayHandle__ *hNvDisplay, NV_DISPLAY_DRIVER_MEMORY_INFO_V2 *pMemoryInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_DISPLAY_DRIVER_MEMORY_INFO_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pMemoryInfo;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_34 = 0i64;
  if ( !fp_34 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_34 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x774AA982u);
  if ( !fp_34 )
    return 4294967293i64;
  v3 = fp_34;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x774AA982u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_DRIVER_MEMORY_INFO_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x774AA982u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1777
// RVA: 0xE9DF50
signed __int64 __fastcall NvAPI_GetDriverMemoryInfo(NvDisplayHandle__ *hNvDisplay, NV_DRIVER_MEMORY_INFO *pMemoryInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_DRIVER_MEMORY_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pMemoryInfo;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_35 = 0i64;
  if ( !fp_35 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_35 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2DC95125u);
  if ( !fp_35 )
    return 4294967293i64;
  v3 = fp_35;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2DC95125u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DRIVER_MEMORY_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2DC95125u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 1802
// RVA: 0xE9E080
signed __int64 __fastcall NvAPI_GetDVCInfo(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_DVC_INFO *pDVCInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_DVC_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pDVCInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_36 = 0i64;
  if ( !fp_36 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_36 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4085DE45u);
  if ( !fp_36 )
    return 4294967293i64;
  v4 = fp_36;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4085DE45u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_DVC_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4085DE45u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1827
// RVA: 0xE9E1B0
signed __int64 __fastcall NvAPI_SetDVCLevel(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int level)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = level;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_37 = 0i64;
  if ( !fp_37 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_37 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x172409B4u);
  if ( !fp_37 )
    return 4294967293i64;
  v4 = fp_37;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x172409B4u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x172409B4u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1852
// RVA: 0xE9E2E0
signed __int64 __fastcall NvAPI_GetDVCInfoEx(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_DVC_INFO_EX *pDVCInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_DVC_INFO_EX *v11; // [rsp+60h] [rbp+18h]

  v11 = pDVCInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_38 = 0i64;
  if ( !fp_38 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_38 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE45002Du);
  if ( !fp_38 )
    return 4294967293i64;
  v4 = fp_38;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE45002Du, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_DVC_INFO_EX *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE45002Du, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1877
// RVA: 0xE9E410
signed __int64 __fastcall NvAPI_SetDVCLevelEx(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_DVC_INFO_EX *pDVCInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_DVC_INFO_EX *v11; // [rsp+60h] [rbp+18h]

  v11 = pDVCInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_39 = 0i64;
  if ( !fp_39 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_39 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4A82C2B1u);
  if ( !fp_39 )
    return 4294967293i64;
  v4 = fp_39;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4A82C2B1u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_DVC_INFO_EX *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4A82C2B1u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1902
// RVA: 0xE9E540
signed __int64 __fastcall NvAPI_GetHUEInfo(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_HUE_INFO *pHUEInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_HUE_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pHUEInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_40 = 0i64;
  if ( !fp_40 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_40 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x95B64341);
  if ( !fp_40 )
    return 4294967293i64;
  v4 = fp_40;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x95B64341, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_HUE_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x95B64341, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1927
// RVA: 0xE9E670
signed __int64 __fastcall NvAPI_SetHUEAngle(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int hueAngle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = hueAngle;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_41 = 0i64;
  if ( !fp_41 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_41 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5A0F22C);
  if ( !fp_41 )
    return 4294967293i64;
  v4 = fp_41;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5A0F22C, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5A0F22C, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1952
// RVA: 0xE9E7A0
signed __int64 __fastcall NvAPI_GetImageSharpeningInfo(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_IMAGE_SHARPENING_INFO *pImageSharpeningInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_IMAGE_SHARPENING_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pImageSharpeningInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_42 = 0i64;
  if ( !fp_42 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_42 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9FB063DF);
  if ( !fp_42 )
    return 4294967293i64;
  v4 = fp_42;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9FB063DF, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_IMAGE_SHARPENING_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9FB063DF, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 1977
// RVA: 0xE9E8D0
signed __int64 __fastcall NvAPI_SetImageSharpeningLevel(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int level)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = level;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_43 = 0i64;
  if ( !fp_43 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_43 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3FC9A59Cu);
  if ( !fp_43 )
    return 4294967293i64;
  v4 = fp_43;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3FC9A59Cu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3FC9A59Cu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2002
// RVA: 0xE9EA00
signed __int64 __fastcall NvAPI_D3D_GetCurrentSLIState(IUnknown *pDevice, NV_GET_CURRENT_SLI_STATE *pSliState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v8; // [rsp+50h] [rbp+8h]
  NV_GET_CURRENT_SLI_STATE *v9; // [rsp+58h] [rbp+10h]

  v9 = pSliState;
  v8 = pDevice;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_44 = 0i64;
  if ( !fp_44 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_44 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4B708B54u);
  if ( !fp_44 )
    return 4294967293i64;
  v3 = fp_44;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4B708B54u, &v5);
  v6 = ((unsigned int (__fastcall *)(IUnknown *, NV_GET_CURRENT_SLI_STATE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4B708B54u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2027
// RVA: 0xE9EB30
signed __int64 __fastcall NvAPI_D3D9_RegisterResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pResource;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_45 = 0i64;
  if ( !fp_45 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_45 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA064BDFC);
  if ( !fp_45 )
    return 4294967293i64;
  v2 = fp_45;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA064BDFC, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA064BDFC, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2052
// RVA: 0xE9EC50
signed __int64 __fastcall NvAPI_D3D9_UnregisterResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pResource;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_46 = 0i64;
  if ( !fp_46 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_46 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBB2B17AA);
  if ( !fp_46 )
    return 4294967293i64;
  v2 = fp_46;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBB2B17AA, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBB2B17AA, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2077
// RVA: 0xE9ED70
signed __int64 __fastcall NvAPI_D3D9_AliasSurfaceAsTexture(unsigned int *pDev, unsigned int *pSurface, unsigned int **ppTexture, unsigned int dwFlag)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int **v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = dwFlag;
  v12 = ppTexture;
  v11 = pSurface;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_47 = 0i64;
  if ( !fp_47 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_47 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE5CEAE41);
  if ( !fp_47 )
    return 4294967293i64;
  v5 = fp_47;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE5CEAE41, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int **, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE5CEAE41, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 2102
// RVA: 0xE9EEB0
signed __int64 __fastcall NvAPI_D3D9_StretchRectEx(unsigned int *pDevice, unsigned int *pSourceResource, tagRECT *pSourceRect, unsigned int *pDestResource, tagRECT *pDestRect, unsigned int Filter)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v12; // [rsp+60h] [rbp+8h]
  unsigned int *v13; // [rsp+68h] [rbp+10h]
  tagRECT *v14; // [rsp+70h] [rbp+18h]
  unsigned int *v15; // [rsp+78h] [rbp+20h]

  v15 = pDestResource;
  v14 = pSourceRect;
  v13 = pSourceResource;
  v12 = pDevice;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_48 = 0i64;
  if ( !fp_48 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_48 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22DE03AAu);
  if ( !fp_48 )
    return 4294967293i64;
  v7 = fp_48;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22DE03AAu, &v9);
  v10 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, tagRECT *, unsigned int *, tagRECT *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pDestRect,
          Filter);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22DE03AAu, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 2127
// RVA: 0xE9F010
signed __int64 __fastcall NvAPI_D3D9_ClearRT(unsigned int *pDevice, unsigned int dwNumRects, tagRECT *pRects, float r)
{
  __int64 (__fastcall *v5)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h]
  unsigned __int64 v7; // [rsp+50h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+58h] [rbp-10h]
  int v9; // [rsp+5Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+70h] [rbp+8h]
  unsigned int v11; // [rsp+78h] [rbp+10h]
  tagRECT *v12; // [rsp+80h] [rbp+18h]

  v12 = pRects;
  v11 = dwNumRects;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_49 = 0i64;
  if ( !fp_49 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_49 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x332D3942u);
  if ( !fp_49 )
    return 4294967293i64;
  v5 = fp_49;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x332D3942u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, tagRECT *))v5)(v10, v11, v12);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x332D3942u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 2152
// RVA: 0xE9F180
signed __int64 __fastcall NvAPI_D3D_CreateQuery(IUnknown *pDeviceOrContext, _NVAPI_D3D_QUERY_TYPE type, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v9; // [rsp+50h] [rbp+8h]
  _NVAPI_D3D_QUERY_TYPE v10; // [rsp+58h] [rbp+10h]
  NVDX_ObjectHandle__ **v11; // [rsp+60h] [rbp+18h]

  v11 = pHandle;
  v10 = type;
  v9 = pDeviceOrContext;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_50 = 0i64;
  if ( !fp_50 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_50 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5D19BCA4u);
  if ( !fp_50 )
    return 4294967293i64;
  v4 = fp_50;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5D19BCA4u, &v6);
  v7 = ((unsigned int (__fastcall *)(IUnknown *, _QWORD, NVDX_ObjectHandle__ **))v4)(v9, (unsigned int)v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5D19BCA4u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2177
// RVA: 0xE9F2B0
signed __int64 __fastcall NvAPI_D3D_DestroyQuery(NVDX_ObjectHandle__ *queryHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NVDX_ObjectHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = queryHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_51 = 0i64;
  if ( !fp_51 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_51 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC8FF7258);
  if ( !fp_51 )
    return 4294967293i64;
  v2 = fp_51;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC8FF7258, &v4);
  v5 = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC8FF7258, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2202
// RVA: 0xE9F3D0
signed __int64 __fastcall NvAPI_D3D_Query_Begin(NVDX_ObjectHandle__ *queryHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NVDX_ObjectHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = queryHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_52 = 0i64;
  if ( !fp_52 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_52 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE5A9AAE0);
  if ( !fp_52 )
    return 4294967293i64;
  v2 = fp_52;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE5A9AAE0, &v4);
  v5 = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE5A9AAE0, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2227
// RVA: 0xE9F4F0
signed __int64 __fastcall NvAPI_D3D_Query_End(NVDX_ObjectHandle__ *queryHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NVDX_ObjectHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = queryHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_53 = 0i64;
  if ( !fp_53 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_53 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2AC084FAu);
  if ( !fp_53 )
    return 4294967293i64;
  v2 = fp_53;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2AC084FAu, &v4);
  v5 = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2AC084FAu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2252
// RVA: 0xE9F610
signed __int64 __fastcall NvAPI_D3D_Query_GetData(NVDX_ObjectHandle__ *queryHandle, void *pData, unsigned int dwSize, unsigned int dwGetDataFlags)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NVDX_ObjectHandle__ *v10; // [rsp+50h] [rbp+8h]
  void *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = dwGetDataFlags;
  v12 = dwSize;
  v11 = pData;
  v10 = queryHandle;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_54 = 0i64;
  if ( !fp_54 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_54 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF8B53C69);
  if ( !fp_54 )
    return 4294967293i64;
  v5 = fp_54;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF8B53C69, &v7);
  v8 = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *, void *, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF8B53C69, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 2277
// RVA: 0xE9F750
signed __int64 __fastcall NvAPI_D3D_Query_GetDataSize(NVDX_ObjectHandle__ *queryHandle, unsigned int *pDwSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NVDX_ObjectHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pDwSize;
  v8 = queryHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_55 = 0i64;
  if ( !fp_55 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_55 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF2A54796);
  if ( !fp_55 )
    return 4294967293i64;
  v3 = fp_55;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF2A54796, &v5);
  v6 = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF2A54796, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2302
// RVA: 0xE9F880
signed __int64 __fastcall NvAPI_D3D_Query_GetType(NVDX_ObjectHandle__ *queryHandle, _NVAPI_D3D_QUERY_TYPE *pType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NVDX_ObjectHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_D3D_QUERY_TYPE *v9; // [rsp+58h] [rbp+10h]

  v9 = pType;
  v8 = queryHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_56 = 0i64;
  if ( !fp_56 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_56 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4ACEEAF7u);
  if ( !fp_56 )
    return 4294967293i64;
  v3 = fp_56;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4ACEEAF7u, &v5);
  v6 = ((unsigned int (__fastcall *)(NVDX_ObjectHandle__ *, _NVAPI_D3D_QUERY_TYPE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4ACEEAF7u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2327
// RVA: 0xE9F9B0
signed __int64 __fastcall NvAPI_D3D_RegisterApp(IUnknown *pDev, unsigned int userAppId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = userAppId;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_57 = 0i64;
  if ( !fp_57 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_57 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD44D3C4E);
  if ( !fp_57 )
    return 4294967293i64;
  v3 = fp_57;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD44D3C4E, &v5);
  v6 = ((unsigned int (__fastcall *)(IUnknown *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD44D3C4E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2352
// RVA: 0xE9FAE0
signed __int64 __fastcall NvAPI_D3D9_CreatePathContextNV(unsigned int *pDevice, unsigned int *context)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = context;
  v8 = pDevice;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_58 = 0i64;
  if ( !fp_58 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_58 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA342F682);
  if ( !fp_58 )
    return 4294967293i64;
  v3 = fp_58;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA342F682, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA342F682, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2377
// RVA: 0xE9FC10
signed __int64 __fastcall NvAPI_D3D9_DestroyPathContextNV(unsigned int context)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int v7; // [rsp+50h] [rbp+8h]

  v7 = context;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_59 = 0i64;
  if ( !fp_59 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_59 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x667C2929u);
  if ( !fp_59 )
    return 4294967293i64;
  v2 = fp_59;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x667C2929u, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x667C2929u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2402
// RVA: 0xE9FD30
signed __int64 __fastcall NvAPI_D3D9_CreatePathNV(unsigned int context, _NV_PATH_DATATYPE datatype, unsigned int numCommands, const char *commands, unsigned int *path)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int v11; // [rsp+60h] [rbp+8h]
  _NV_PATH_DATATYPE v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  const char *v14; // [rsp+78h] [rbp+20h]

  v14 = commands;
  v13 = numCommands;
  v12 = datatype;
  v11 = context;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_60 = 0i64;
  if ( !fp_60 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_60 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x71329DF3u);
  if ( !fp_60 )
    return 4294967293i64;
  v6 = fp_60;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x71329DF3u, &v8);
  v9 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD, const char *, unsigned int *))v6)(
         v11,
         (unsigned int)v12,
         v13,
         v14,
         path);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x71329DF3u, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 2427
// RVA: 0xE9FE80
signed __int64 __fastcall NvAPI_D3D9_DeletePathNV(unsigned int path)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int v7; // [rsp+50h] [rbp+8h]

  v7 = path;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_61 = 0i64;
  if ( !fp_61 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_61 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x73E0019Au);
  if ( !fp_61 )
    return 4294967293i64;
  v2 = fp_61;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x73E0019Au, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x73E0019Au, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 2452
// RVA: 0xE9FFA0
signed __int64 __fastcall NvAPI_D3D9_PathVerticesNV(unsigned int path, const void *vertices)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  const void *v9; // [rsp+58h] [rbp+10h]

  v9 = vertices;
  v8 = path;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_62 = 0i64;
  if ( !fp_62 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_62 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC23DF926);
  if ( !fp_62 )
    return 4294967293i64;
  v3 = fp_62;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC23DF926, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, const void *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC23DF926, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2477
// RVA: 0xEA00D0
signed __int64 __fastcall NvAPI_D3D9_PathParameterfNV(unsigned int path, _NV_PATH_PARAMTYPE paramType, float param)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  _NV_PATH_PARAMTYPE v10; // [rsp+58h] [rbp+10h]

  v10 = paramType;
  v9 = path;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_63 = 0i64;
  if ( !fp_63 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_63 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF7FF00C1);
  if ( !fp_63 )
    return 4294967293i64;
  v4 = fp_63;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF7FF00C1, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, _QWORD))v4)(v9, (unsigned int)v10);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF7FF00C1, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2502
// RVA: 0xEA0200
signed __int64 __fastcall NvAPI_D3D9_PathParameteriNV(unsigned int path, _NV_PATH_PARAMTYPE paramType, int param)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  _NV_PATH_PARAMTYPE v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = param;
  v10 = paramType;
  v9 = path;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_64 = 0i64;
  if ( !fp_64 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_64 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFC31236C);
  if ( !fp_64 )
    return 4294967293i64;
  v4 = fp_64;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFC31236C, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD))v4)(v9, (unsigned int)v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFC31236C, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2527
// RVA: 0xEA0330
signed __int64 __fastcall NvAPI_D3D9_PathMatrixNV(unsigned int context, _NV_PATH_TARGETTYPE paramType, const float *value)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  _NV_PATH_TARGETTYPE v10; // [rsp+58h] [rbp+10h]
  const float *v11; // [rsp+60h] [rbp+18h]

  v11 = value;
  v10 = paramType;
  v9 = context;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_65 = 0i64;
  if ( !fp_65 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_65 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2F6C499);
  if ( !fp_65 )
    return 4294967293i64;
  v4 = fp_65;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2F6C499, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, const float *))v4)(v9, (unsigned int)v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2F6C499, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2552
// RVA: 0xEA0460
signed __int64 __fastcall NvAPI_D3D9_PathDepthNV(unsigned int context, float value)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]

  v8 = context;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_66 = 0i64;
  if ( !fp_66 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_66 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFCB16330);
  if ( !fp_66 )
    return 4294967293i64;
  v3 = fp_66;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFCB16330, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD))v3)(v8);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFCB16330, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2577
// RVA: 0xEA0590
signed __int64 __fastcall NvAPI_D3D9_PathClearDepthNV(unsigned int context, float value)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]

  v8 = context;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_67 = 0i64;
  if ( !fp_67 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_67 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x157E45C4u);
  if ( !fp_67 )
    return 4294967293i64;
  v3 = fp_67;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x157E45C4u, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD))v3)(v8);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x157E45C4u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2602
// RVA: 0xEA06C0
signed __int64 __fastcall NvAPI_D3D9_PathEnableDepthTestNV(unsigned int context, bool enable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  bool v9; // [rsp+58h] [rbp+10h]

  v9 = enable;
  v8 = context;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_68 = 0i64;
  if ( !fp_68 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_68 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE99BA7F3);
  if ( !fp_68 )
    return 4294967293i64;
  v3 = fp_68;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE99BA7F3, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, bool))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE99BA7F3, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2627
// RVA: 0xEA07F0
signed __int64 __fastcall NvAPI_D3D9_PathEnableColorWriteNV(unsigned int context, bool enable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  bool v9; // [rsp+58h] [rbp+10h]

  v9 = enable;
  v8 = context;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_69 = 0i64;
  if ( !fp_69 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_69 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3E2804A2u);
  if ( !fp_69 )
    return 4294967293i64;
  v3 = fp_69;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3E2804A2u, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, bool))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3E2804A2u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2652
// RVA: 0xEA0920
signed __int64 __fastcall NvAPI_D3D9_DrawPathNV(unsigned int path, _NV_PATH_MODE mode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_PATH_MODE v9; // [rsp+58h] [rbp+10h]

  v9 = mode;
  v8 = path;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_70 = 0i64;
  if ( !fp_70 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_70 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x13199B3Du);
  if ( !fp_70 )
    return 4294967293i64;
  v3 = fp_70;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x13199B3Du, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _QWORD))v3)(v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x13199B3Du, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2677
// RVA: 0xEA0A50
signed __int64 __fastcall NvAPI_D3D9_GetSurfaceHandle(unsigned int *pSurface, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pSurface;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_71 = 0i64;
  if ( !fp_71 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_71 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF2DD3F2u);
  if ( !fp_71 )
    return 4294967293i64;
  v3 = fp_71;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF2DD3F2u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF2DD3F2u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2702
// RVA: 0xEA0B80
signed __int64 __fastcall NvAPI_D3D9_GetOverlaySurfaceHandles(unsigned int *pDev, _NV_OVLY_SURFS_INFO *pInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NV_OVLY_SURFS_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pInfo;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_72 = 0i64;
  if ( !fp_72 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_72 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6800F5FCu);
  if ( !fp_72 )
    return 4294967293i64;
  v3 = fp_72;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6800F5FCu, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NV_OVLY_SURFS_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6800F5FCu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2727
// RVA: 0xEA0CB0
signed __int64 __fastcall NvAPI_D3D9_GetTextureHandle(unsigned int *pTexture, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pTexture;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_73 = 0i64;
  if ( !fp_73 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_73 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC7985ED5);
  if ( !fp_73 )
    return 4294967293i64;
  v3 = fp_73;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC7985ED5, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC7985ED5, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2752
// RVA: 0xEA0DE0
signed __int64 __fastcall NvAPI_D3D9_GpuSyncGetHandleSize(unsigned int *pDev, unsigned int *pInitHandleSize, unsigned int *pMapHandleSize)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pMapHandleSize;
  v10 = pInitHandleSize;
  v9 = pDev;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_74 = 0i64;
  if ( !fp_74 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_74 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x80C9FD3B);
  if ( !fp_74 )
    return 4294967293i64;
  v4 = fp_74;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x80C9FD3B, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x80C9FD3B, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2777
// RVA: 0xEA0F20
signed __int64 __fastcall NvAPI_D3D9_GpuSyncInit(unsigned int *pDev, void *syncInitData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  void *v9; // [rsp+58h] [rbp+10h]

  v9 = syncInitData;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_75 = 0i64;
  if ( !fp_75 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_75 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6D6FDAD4u);
  if ( !fp_75 )
    return 4294967293i64;
  v3 = fp_75;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6D6FDAD4u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6D6FDAD4u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2802
// RVA: 0xEA1050
signed __int64 __fastcall NvAPI_D3D9_GpuSyncEnd(unsigned int *pDev, void *syncData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  void *v9; // [rsp+58h] [rbp+10h]

  v9 = syncData;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_76 = 0i64;
  if ( !fp_76 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_76 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x754033F0u);
  if ( !fp_76 )
    return 4294967293i64;
  v3 = fp_76;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x754033F0u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x754033F0u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2827
// RVA: 0xEA1180
signed __int64 __fastcall NvAPI_D3D9_GpuSyncMapTexBuffer(unsigned int *pDev, unsigned int *pTexture, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  void *v11; // [rsp+60h] [rbp+18h]

  v11 = syncData;
  v10 = pTexture;
  v9 = pDev;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_77 = 0i64;
  if ( !fp_77 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_77 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDE4A28A);
  if ( !fp_77 )
    return 4294967293i64;
  v4 = fp_77;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDE4A28A, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDE4A28A, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2852
// RVA: 0xEA12C0
signed __int64 __fastcall NvAPI_D3D9_GpuSyncMapSurfaceBuffer(unsigned int *pDev, unsigned int *pSurface, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  void *v11; // [rsp+60h] [rbp+18h]

  v11 = syncData;
  v10 = pSurface;
  v9 = pDev;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_78 = 0i64;
  if ( !fp_78 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_78 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2AB714ABu);
  if ( !fp_78 )
    return 4294967293i64;
  v4 = fp_78;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2AB714ABu, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2AB714ABu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2877
// RVA: 0xEA1400
signed __int64 __fastcall NvAPI_D3D9_GpuSyncMapVertexBuffer(unsigned int *pDev, unsigned int *pVertexBuffer, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  void *v11; // [rsp+60h] [rbp+18h]

  v11 = syncData;
  v10 = pVertexBuffer;
  v9 = pDev;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_79 = 0i64;
  if ( !fp_79 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_79 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDBC803EC);
  if ( !fp_79 )
    return 4294967293i64;
  v4 = fp_79;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDBC803EC, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDBC803EC, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2902
// RVA: 0xEA1540
signed __int64 __fastcall NvAPI_D3D9_GpuSyncMapIndexBuffer(unsigned int *pDev, unsigned int *pIndexBuffer, void *syncData)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  void *v11; // [rsp+60h] [rbp+18h]

  v11 = syncData;
  v10 = pIndexBuffer;
  v9 = pDev;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_80 = 0i64;
  if ( !fp_80 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_80 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x12EE68F2u);
  if ( !fp_80 )
    return 4294967293i64;
  v4 = fp_80;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x12EE68F2u, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, void *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x12EE68F2u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 2927
// RVA: 0xEA1680
signed __int64 __fastcall NvAPI_D3D9_SetPitchSurfaceCreation(unsigned int *pDev, unsigned int Signature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = Signature;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_81 = 0i64;
  if ( !fp_81 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_81 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x18CDF365u);
  if ( !fp_81 )
    return 4294967293i64;
  v3 = fp_81;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x18CDF365u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x18CDF365u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2952
// RVA: 0xEA17B0
signed __int64 __fastcall NvAPI_D3D9_GpuSyncAcquire(unsigned int *pDev, void *syncData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  void *v9; // [rsp+58h] [rbp+10h]

  v9 = syncData;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_82 = 0i64;
  if ( !fp_82 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_82 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD00B8317);
  if ( !fp_82 )
    return 4294967293i64;
  v3 = fp_82;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD00B8317, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD00B8317, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 2977
// RVA: 0xEA18E0
signed __int64 __fastcall NvAPI_D3D9_GpuSyncRelease(unsigned int *pDev, void *syncData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  void *v9; // [rsp+58h] [rbp+10h]

  v9 = syncData;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_83 = 0i64;
  if ( !fp_83 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_83 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3D7A86BBu);
  if ( !fp_83 )
    return 4294967293i64;
  v3 = fp_83;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3D7A86BBu, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, void *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3D7A86BBu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3002
// RVA: 0xEA1A10
signed __int64 __fastcall NvAPI_D3D9_GetCurrentRenderTargetHandle(unsigned int *pDev, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_84 = 0i64;
  if ( !fp_84 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_84 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22CAD61u);
  if ( !fp_84 )
    return 4294967293i64;
  v3 = fp_84;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22CAD61u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22CAD61u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3027
// RVA: 0xEA1B40
signed __int64 __fastcall NvAPI_D3D9_GetCurrentZBufferHandle(unsigned int *pDev, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_85 = 0i64;
  if ( !fp_85 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_85 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB380F218);
  if ( !fp_85 )
    return 4294967293i64;
  v3 = fp_85;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB380F218, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB380F218, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3052
// RVA: 0xEA1C70
signed __int64 __fastcall NvAPI_D3D9_GetIndexBufferHandle(unsigned int *pIndexBuffer, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pIndexBuffer;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_86 = 0i64;
  if ( !fp_86 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_86 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFC5A155B);
  if ( !fp_86 )
    return 4294967293i64;
  v3 = fp_86;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFC5A155B, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFC5A155B, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3077
// RVA: 0xEA1DA0
signed __int64 __fastcall NvAPI_D3D9_GetVertexBufferHandle(unsigned int *pVertexBuffer, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pVertexBuffer;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_87 = 0i64;
  if ( !fp_87 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_87 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x72B19155u);
  if ( !fp_87 )
    return 4294967293i64;
  v3 = fp_87;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x72B19155u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x72B19155u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3102
// RVA: 0xEA1ED0
signed __int64 __fastcall NvAPI_D3D9_CreateTexture(unsigned int *pDev, unsigned int Width, unsigned int Height, unsigned int Level, unsigned int Flags, unsigned int Format, unsigned int **ppTexture, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v9)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h]
  unsigned __int64 v11; // [rsp+50h] [rbp-18h]
  _NvAPI_Status v12; // [rsp+58h] [rbp-10h]
  int v13; // [rsp+5Ch] [rbp-Ch]
  unsigned int *v14; // [rsp+70h] [rbp+8h]
  unsigned int v15; // [rsp+78h] [rbp+10h]
  unsigned int v16; // [rsp+80h] [rbp+18h]
  unsigned int v17; // [rsp+88h] [rbp+20h]

  v17 = Level;
  v16 = Height;
  v15 = Width;
  v14 = pDev;
  hMod = 0i64;
  v13 = 0;
  v12 = (unsigned int)GetGpuHandle(&hMod);
  if ( v12 && v12 != -14 )
    return v12;
  if ( v12 == -14 )
    fp_88 = 0i64;
  if ( !fp_88 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_88 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD5E13573);
  if ( !fp_88 )
    return 4294967293i64;
  v9 = fp_88;
  v11 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD5E13573, &v11);
  v12 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD, unsigned int, unsigned int, unsigned int **, NVDX_ObjectHandle__ **))v9)(
          v14,
          v15,
          v16,
          v17,
          Flags,
          Format,
          ppTexture,
          pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD5E13573, v11, v12);
  --g_module_numApiInUse[v13];
  return v12;
}

// File Line: 3127
// RVA: 0xEA2040
signed __int64 __fastcall NvAPI_D3D9_AliasPrimaryAsTexture(unsigned int *pDev, unsigned int dwIndex, unsigned int **ppTexture, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int **v12; // [rsp+60h] [rbp+18h]
  NVDX_ObjectHandle__ **v13; // [rsp+68h] [rbp+20h]

  v13 = pHandle;
  v12 = ppTexture;
  v11 = dwIndex;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_89 = 0i64;
  if ( !fp_89 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_89 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x13C7112Eu);
  if ( !fp_89 )
    return 4294967293i64;
  v5 = fp_89;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x13C7112Eu, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, unsigned int **, NVDX_ObjectHandle__ **))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x13C7112Eu, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 3152
// RVA: 0xEA2180
signed __int64 __fastcall NvAPI_D3D9_PresentSurfaceToDesktop(unsigned int *pDev, NVDX_ObjectHandle__ *surfaceHandle, unsigned int dwFlipFlags, unsigned int dwExcludeDevices)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = dwExcludeDevices;
  v12 = dwFlipFlags;
  v11 = surfaceHandle;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_90 = 0i64;
  if ( !fp_90 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_90 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF7029C5u);
  if ( !fp_90 )
    return 4294967293i64;
  v5 = fp_90;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF7029C5u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF7029C5u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 3177
// RVA: 0xEA22C0
signed __int64 __fastcall NvAPI_D3D9_CreateVideoBegin(unsigned int *pDev)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pDev;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_91 = 0i64;
  if ( !fp_91 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_91 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x84C9D553);
  if ( !fp_91 )
    return 4294967293i64;
  v2 = fp_91;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x84C9D553, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x84C9D553, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 3202
// RVA: 0xEA23E0
signed __int64 __fastcall NvAPI_D3D9_CreateVideoEnd(unsigned int *pDev)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pDev;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_92 = 0i64;
  if ( !fp_92 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_92 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB476BF61);
  if ( !fp_92 )
    return 4294967293i64;
  v2 = fp_92;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB476BF61, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB476BF61, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 3227
// RVA: 0xEA2500
signed __int64 __fastcall NvAPI_D3D9_CreateVideo(unsigned int *pDev, NV_DX_CREATE_VIDEO_PARAMS2 *pCVParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NV_DX_CREATE_VIDEO_PARAMS2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pCVParams;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_93 = 0i64;
  if ( !fp_93 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_93 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x89FFD9A3);
  if ( !fp_93 )
    return 4294967293i64;
  v3 = fp_93;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x89FFD9A3, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NV_DX_CREATE_VIDEO_PARAMS2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x89FFD9A3, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3252
// RVA: 0xEA2630
signed __int64 __fastcall NvAPI_D3D9_FreeVideo(unsigned int *pDev)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pDev;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_94 = 0i64;
  if ( !fp_94 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_94 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3111BED1u);
  if ( !fp_94 )
    return 4294967293i64;
  v2 = fp_94;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3111BED1u, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3111BED1u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 3277
// RVA: 0xEA2750
signed __int64 __fastcall NvAPI_D3D9_PresentVideo(unsigned int *pDev, NV_DX_PRESENT_VIDEO_PARAMS1 *pPVParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NV_DX_PRESENT_VIDEO_PARAMS1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pPVParams;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_95 = 0i64;
  if ( !fp_95 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_95 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5CF7F862u);
  if ( !fp_95 )
    return 4294967293i64;
  v3 = fp_95;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5CF7F862u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NV_DX_PRESENT_VIDEO_PARAMS1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5CF7F862u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3302
// RVA: 0xEA2880
signed __int64 __fastcall NvAPI_D3D9_VideoSetStereoInfo(unsigned int *pDev, _NV_DX_VIDEO_STEREO_INFO *pStereoInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NV_DX_VIDEO_STEREO_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pStereoInfo;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_96 = 0i64;
  if ( !fp_96 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_96 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB852F4DB);
  if ( !fp_96 )
    return 4294967293i64;
  v3 = fp_96;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB852F4DB, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NV_DX_VIDEO_STEREO_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB852F4DB, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3327
// RVA: 0xEA29B0
signed __int64 __fastcall NvAPI_D3D9_SetGamutData(unsigned int *pDev, unsigned int outputId, _NV_GAMUT_FORMAT format, _NV_GAMUT_METADATA *pGamutData)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  _NV_GAMUT_FORMAT v12; // [rsp+60h] [rbp+18h]
  _NV_GAMUT_METADATA *v13; // [rsp+68h] [rbp+20h]

  v13 = pGamutData;
  v12 = format;
  v11 = outputId;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_97 = 0i64;
  if ( !fp_97 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_97 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2BBDA32Eu);
  if ( !fp_97 )
    return 4294967293i64;
  v5 = fp_97;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2BBDA32Eu, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _NV_GAMUT_METADATA *))v5)(
         v10,
         v11,
         (unsigned int)v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2BBDA32Eu, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 3352
// RVA: 0xEA2AF0
signed __int64 __fastcall NvAPI_D3D9_SetSurfaceCreationLayout(unsigned int *pDev, _NVAPI_SURFACE_LAYOUT_STRUCT *pSurfaceLayout)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_SURFACE_LAYOUT_STRUCT *v9; // [rsp+58h] [rbp+10h]

  v9 = pSurfaceLayout;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_98 = 0i64;
  if ( !fp_98 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_98 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5609B86Au);
  if ( !fp_98 )
    return 4294967293i64;
  v3 = fp_98;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5609B86Au, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_SURFACE_LAYOUT_STRUCT *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5609B86Au, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3377
// RVA: 0xEA2C20
signed __int64 __fastcall NvAPI_D3D9_GetVideoCapabilities(unsigned int *pDev, _NV_DX_VIDEO_CAPS *pVideoCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NV_DX_VIDEO_CAPS *v9; // [rsp+58h] [rbp+10h]

  v9 = pVideoCaps;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_99 = 0i64;
  if ( !fp_99 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_99 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3D596B93u);
  if ( !fp_99 )
    return 4294967293i64;
  v3 = fp_99;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3D596B93u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NV_DX_VIDEO_CAPS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3D596B93u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3402
// RVA: 0xEA2D50
signed __int64 __fastcall NvAPI_D3D9_QueryVideoInfo(unsigned int *pDev, _NVAPI_DX_QUERY_VIDEO_INFO *pQueryInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_DX_QUERY_VIDEO_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pQueryInfo;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_100 = 0i64;
  if ( !fp_100 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_100 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1E6634B3u);
  if ( !fp_100 )
    return 4294967293i64;
  v3 = fp_100;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1E6634B3u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_DX_QUERY_VIDEO_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1E6634B3u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3427
// RVA: 0xEA2E80
signed __int64 __fastcall NvAPI_D3D9_AliasPrimaryFromDevice(unsigned int *pDevTo, unsigned int *pDevFrom, unsigned int dwIndex, unsigned int **ppSurf, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v11; // [rsp+60h] [rbp+8h]
  unsigned int *v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  unsigned int **v14; // [rsp+78h] [rbp+20h]

  v14 = ppSurf;
  v13 = dwIndex;
  v12 = pDevFrom;
  v11 = pDevTo;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_101 = 0i64;
  if ( !fp_101 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_101 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7C20C5BEu);
  if ( !fp_101 )
    return 4294967293i64;
  v6 = fp_101;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7C20C5BEu, &v8);
  v9 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, _QWORD, unsigned int **, NVDX_ObjectHandle__ **))v6)(
         v11,
         v12,
         v13,
         v14,
         pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7C20C5BEu, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 3452
// RVA: 0xEA2FD0
signed __int64 __fastcall NvAPI_D3D9_SetResourceHint(unsigned int *pDev, NVDX_ObjectHandle__ *obj, _NVAPI_SETRESOURCEHINT_CATEGORY dwHintCategory, unsigned int dwHintName, unsigned int *pdwHintValue)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v11; // [rsp+60h] [rbp+8h]
  NVDX_ObjectHandle__ *v12; // [rsp+68h] [rbp+10h]
  _NVAPI_SETRESOURCEHINT_CATEGORY v13; // [rsp+70h] [rbp+18h]
  unsigned int v14; // [rsp+78h] [rbp+20h]

  v14 = dwHintName;
  v13 = dwHintCategory;
  v12 = obj;
  v11 = pDev;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_102 = 0i64;
  if ( !fp_102 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_102 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x905F5C27);
  if ( !fp_102 )
    return 4294967293i64;
  v6 = fp_102;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x905F5C27, &v8);
  v9 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, _QWORD, _QWORD, unsigned int *))v6)(
         v11,
         v12,
         (unsigned int)v13,
         v14,
         pdwHintValue);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x905F5C27, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 3477
// RVA: 0xEA3120
signed __int64 __fastcall NvAPI_D3D9_Lock(unsigned int *pDev, NVDX_ObjectHandle__ *obj, unsigned int dwLockFlags, void **ppAddress, unsigned int *pPitch)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v11; // [rsp+60h] [rbp+8h]
  NVDX_ObjectHandle__ *v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  void **v14; // [rsp+78h] [rbp+20h]

  v14 = ppAddress;
  v13 = dwLockFlags;
  v12 = obj;
  v11 = pDev;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_103 = 0i64;
  if ( !fp_103 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_103 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6317345Cu);
  if ( !fp_103 )
    return 4294967293i64;
  v6 = fp_103;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6317345Cu, &v8);
  v9 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, _QWORD, void **, unsigned int *))v6)(
         v11,
         v12,
         v13,
         v14,
         pPitch);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6317345Cu, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 3502
// RVA: 0xEA3270
signed __int64 __fastcall NvAPI_D3D9_Unlock(unsigned int *pDev, NVDX_ObjectHandle__ *obj)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVDX_ObjectHandle__ *v9; // [rsp+58h] [rbp+10h]

  v9 = obj;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_104 = 0i64;
  if ( !fp_104 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_104 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC182027E);
  if ( !fp_104 )
    return 4294967293i64;
  v3 = fp_104;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC182027E, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC182027E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3527
// RVA: 0xEA33A0
signed __int64 __fastcall NvAPI_D3D9_GetVideoState(unsigned int *pDev, _NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_GET_VIDEO_STATE_COMPONENT *v9; // [rsp+58h] [rbp+10h]

  v9 = pGetVidStateComp;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_105 = 0i64;
  if ( !fp_105 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_105 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA4527BF8);
  if ( !fp_105 )
    return 4294967293i64;
  v3 = fp_105;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA4527BF8, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_GET_VIDEO_STATE_COMPONENT *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA4527BF8, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3552
// RVA: 0xEA34D0
signed __int64 __fastcall NvAPI_D3D9_SetVideoState(unsigned int *pDev, _NVAPI_SET_VIDEO_STATE_COMPONENT *pSetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_SET_VIDEO_STATE_COMPONENT *v9; // [rsp+58h] [rbp+10h]

  v9 = pSetVidStateComp;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_106 = 0i64;
  if ( !fp_106 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_106 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBD4BC56F);
  if ( !fp_106 )
    return 4294967293i64;
  v3 = fp_106;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBD4BC56F, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_SET_VIDEO_STATE_COMPONENT *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBD4BC56F, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3577
// RVA: 0xEA3600
signed __int64 __fastcall NvAPI_D3D9_EnumVideoFeatures(unsigned int *pDev, _NVAPI_DX_VIDEO_FEATURE_DETAILS *pVideoFeatureDetails)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_DX_VIDEO_FEATURE_DETAILS *v9; // [rsp+58h] [rbp+10h]

  v9 = pVideoFeatureDetails;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_107 = 0i64;
  if ( !fp_107 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_107 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1DB7C52Cu);
  if ( !fp_107 )
    return 4294967293i64;
  v3 = fp_107;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1DB7C52Cu, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_DX_VIDEO_FEATURE_DETAILS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1DB7C52Cu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3602
// RVA: 0xEA3730
signed __int64 __fastcall NvAPI_D3D9_GetSLIInfo(unsigned int *pDev, NV_SLI_INFO *pSliInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NV_SLI_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pSliInfo;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_108 = 0i64;
  if ( !fp_108 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_108 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x694BFF4Du);
  if ( !fp_108 )
    return 4294967293i64;
  v3 = fp_108;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x694BFF4Du, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NV_SLI_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x694BFF4Du, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3627
// RVA: 0xEA3860
signed __int64 __fastcall NvAPI_D3D9_SetSLIMode(unsigned int *pDev, _NV_SLI_MODE SliMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NV_SLI_MODE v9; // [rsp+58h] [rbp+10h]

  v9 = SliMode;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_109 = 0i64;
  if ( !fp_109 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_109 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBFDC062C);
  if ( !fp_109 )
    return 4294967293i64;
  v3 = fp_109;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBFDC062C, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v3)(v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBFDC062C, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3652
// RVA: 0xEA3990
signed __int64 __fastcall NvAPI_D3D9_QueryAAOverrideMode(unsigned int *pDev, unsigned int *pRenderingSampleCount, unsigned int *pBufferSampleCount, unsigned int *pAAMode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  unsigned int *v13; // [rsp+68h] [rbp+20h]

  v13 = pAAMode;
  v12 = pBufferSampleCount;
  v11 = pRenderingSampleCount;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_110 = 0i64;
  if ( !fp_110 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_110 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDDF5643C);
  if ( !fp_110 )
    return 4294967293i64;
  v5 = fp_110;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDDF5643C, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, unsigned int *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDDF5643C, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 3677
// RVA: 0xEA3AD0
signed __int64 __fastcall NvAPI_D3D9_VideoSurfaceEncryptionControl(unsigned int *pDev, NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *pVidSurfEncrCtrlParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *v9; // [rsp+58h] [rbp+10h]

  v9 = pVidSurfEncrCtrlParams;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_111 = 0i64;
  if ( !fp_111 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_111 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9D2509EF);
  if ( !fp_111 )
    return 4294967293i64;
  v3 = fp_111;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9D2509EF, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVAPI_VIDSURF_ENCRYPT_CTRL_PARAMS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9D2509EF, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3702
// RVA: 0xEA3C00
signed __int64 __fastcall NvAPI_D3D9_DMA(unsigned int *pDev, _NVAPI_D3D9_DMA_PARAMS *pVideoDMAParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_D3D9_DMA_PARAMS *v9; // [rsp+58h] [rbp+10h]

  v9 = pVideoDMAParams;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_112 = 0i64;
  if ( !fp_112 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_112 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x962B8AF6);
  if ( !fp_112 )
    return 4294967293i64;
  v3 = fp_112;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x962B8AF6, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_D3D9_DMA_PARAMS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x962B8AF6, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3727
// RVA: 0xEA3D30
signed __int64 __fastcall NvAPI_D3D9_EnableStereo(unsigned int *pDev, _NVAPI_D3D9_ENABLE_STEREO_PARAMS *pEnableStereoParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_D3D9_ENABLE_STEREO_PARAMS *v9; // [rsp+58h] [rbp+10h]

  v9 = pEnableStereoParams;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_113 = 0i64;
  if ( !fp_113 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_113 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x492A6954u);
  if ( !fp_113 )
    return 4294967293i64;
  v3 = fp_113;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x492A6954u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_D3D9_ENABLE_STEREO_PARAMS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x492A6954u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3752
// RVA: 0xEA3E60
signed __int64 __fastcall NvAPI_D3D9_StretchRect(unsigned int *pDev, NVDX_ObjectHandle__ *hSrcObj, tagRECT *pSourceRect, NVDX_ObjectHandle__ *hDstObj, tagRECT *pDestRect, unsigned int Filter)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v12; // [rsp+60h] [rbp+8h]
  NVDX_ObjectHandle__ *v13; // [rsp+68h] [rbp+10h]
  tagRECT *v14; // [rsp+70h] [rbp+18h]
  NVDX_ObjectHandle__ *v15; // [rsp+78h] [rbp+20h]

  v15 = hDstObj;
  v14 = pSourceRect;
  v13 = hSrcObj;
  v12 = pDev;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_114 = 0i64;
  if ( !fp_114 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_114 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAEAECD41);
  if ( !fp_114 )
    return 4294967293i64;
  v7 = fp_114;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAEAECD41, &v9);
  v10 = ((unsigned int (__fastcall *)(unsigned int *, NVDX_ObjectHandle__ *, tagRECT *, NVDX_ObjectHandle__ *, tagRECT *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pDestRect,
          Filter);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAEAECD41, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 3777
// RVA: 0xEA3FC0
signed __int64 __fastcall NvAPI_D3D9_CreateRenderTarget(unsigned int *pDev, unsigned int Width, unsigned int Height, unsigned int Format, unsigned int MultiSample, unsigned int MultisampleQuality, int Lockable, unsigned int **ppSurface, NVDX_ObjectHandle__ **pHandle)
{
  __int64 (__fastcall *v10)(); // [rsp+50h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+58h] [rbp-20h]
  unsigned __int64 v12; // [rsp+60h] [rbp-18h]
  _NvAPI_Status v13; // [rsp+68h] [rbp-10h]
  int v14; // [rsp+6Ch] [rbp-Ch]
  unsigned int *v15; // [rsp+80h] [rbp+8h]
  unsigned int v16; // [rsp+88h] [rbp+10h]
  unsigned int v17; // [rsp+90h] [rbp+18h]
  unsigned int v18; // [rsp+98h] [rbp+20h]

  v18 = Format;
  v17 = Height;
  v16 = Width;
  v15 = pDev;
  hMod = 0i64;
  v14 = 0;
  v13 = (unsigned int)GetGpuHandle(&hMod);
  if ( v13 && v13 != -14 )
    return v13;
  if ( v13 == -14 )
    fp_115 = 0i64;
  if ( !fp_115 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_115 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB3827C8u);
  if ( !fp_115 )
    return 4294967293i64;
  v10 = fp_115;
  v12 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB3827C8u, &v12);
  v13 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD, unsigned int, unsigned int, int, unsigned int **, NVDX_ObjectHandle__ **))v10)(
          v15,
          v16,
          v17,
          v18,
          MultiSample,
          MultisampleQuality,
          Lockable,
          ppSurface,
          pHandle);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB3827C8u, v12, v13);
  --g_module_numApiInUse[v14];
  return v13;
}

// File Line: 3802
// RVA: 0xEA4150
signed __int64 __fastcall NvAPI_D3D9_NVFBC_GetStatus(void *pNvFBCStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = pNvFBCStatus;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_116 = 0i64;
  if ( !fp_116 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_116 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBD3EB475);
  if ( !fp_116 )
    return 4294967293i64;
  v2 = fp_116;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBD3EB475, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBD3EB475, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 3827
// RVA: 0xEA4270
signed __int64 __fastcall NvAPI_D3D9_IFR_SetUpTargetBufferToSys(unsigned int *pDev, NVFBC_BUFFER_FORMAT eFormat, unsigned int dwNBuffers, char **ppBuffer)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  NVFBC_BUFFER_FORMAT v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  char **v13; // [rsp+68h] [rbp+20h]

  v13 = ppBuffer;
  v12 = dwNBuffers;
  v11 = eFormat;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_117 = 0i64;
  if ( !fp_117 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_117 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x55255D05u);
  if ( !fp_117 )
    return 4294967293i64;
  v5 = fp_117;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x55255D05u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, char **))v5)(v10, (unsigned int)v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x55255D05u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 3852
// RVA: 0xEA43B0
signed __int64 __fastcall NvAPI_D3D9_GPUBasedCPUSleep(unsigned int *pDev, unsigned __int64 qwMicroSeconds)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  unsigned __int64 v9; // [rsp+58h] [rbp+10h]

  v9 = qwMicroSeconds;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_118 = 0i64;
  if ( !fp_118 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_118 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD504DDA7);
  if ( !fp_118 )
    return 4294967293i64;
  v3 = fp_118;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD504DDA7, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, unsigned __int64))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD504DDA7, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 3877
// RVA: 0xEA44E0
signed __int64 __fastcall NvAPI_D3D9_IFR_TransferRenderTarget(unsigned int *pDev, void **pEvent, unsigned int dwBufferIndex, unsigned int dwTargetWidth, unsigned int dwTargetHeight)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v11; // [rsp+60h] [rbp+8h]
  void **v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  unsigned int v14; // [rsp+78h] [rbp+20h]

  v14 = dwTargetWidth;
  v13 = dwBufferIndex;
  v12 = pEvent;
  v11 = pDev;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_119 = 0i64;
  if ( !fp_119 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_119 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAB7C2DCu);
  if ( !fp_119 )
    return 4294967293i64;
  v6 = fp_119;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAB7C2DCu, &v8);
  v9 = ((unsigned int (__fastcall *)(unsigned int *, void **, _QWORD, _QWORD, unsigned int))v6)(
         v11,
         v12,
         v13,
         v14,
         dwTargetHeight);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAB7C2DCu, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 3902
// RVA: 0xEA4630
signed __int64 __fastcall NvAPI_D3D9_IFR_SetUpTargetBufferToNV12BLVideoSurface(unsigned int *pDev, unsigned int dwNBuffers, void **aHandles, unsigned int dwTargetWidth, unsigned int dwTargetHeight)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v11; // [rsp+60h] [rbp+8h]
  unsigned int v12; // [rsp+68h] [rbp+10h]
  void **v13; // [rsp+70h] [rbp+18h]
  unsigned int v14; // [rsp+78h] [rbp+20h]

  v14 = dwTargetWidth;
  v13 = aHandles;
  v12 = dwNBuffers;
  v11 = pDev;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_120 = 0i64;
  if ( !fp_120 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_120 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCFC92C15);
  if ( !fp_120 )
    return 4294967293i64;
  v6 = fp_120;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCFC92C15, &v8);
  v9 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, void **, _QWORD, unsigned int))v6)(
         v11,
         v12,
         v13,
         v14,
         dwTargetHeight);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCFC92C15, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 3927
// RVA: 0xEA4780
signed __int64 __fastcall NvAPI_D3D9_IFR_TransferRenderTargetToNV12BLVideoSurface(unsigned int *pDev, unsigned int dwBufferIndex, unsigned int dwTargetWidth, unsigned int dwTargetHeight)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = dwTargetHeight;
  v12 = dwTargetWidth;
  v11 = dwBufferIndex;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_121 = 0i64;
  if ( !fp_121 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_121 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5FE72F64u);
  if ( !fp_121 )
    return 4294967293i64;
  v5 = fp_121;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5FE72F64u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5FE72F64u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 3952
// RVA: 0xEA48C0
signed __int64 __fastcall NvAPI_D3D10_AliasPrimaryAsTexture(unsigned int *pDev, unsigned int headIndex, unsigned int **ppTexture)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int **v11; // [rsp+60h] [rbp+18h]

  v11 = ppTexture;
  v10 = headIndex;
  v9 = pDev;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_122 = 0i64;
  if ( !fp_122 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_122 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8AAC133D);
  if ( !fp_122 )
    return 4294967293i64;
  v4 = fp_122;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8AAC133D, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, unsigned int **))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8AAC133D, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 3977
// RVA: 0xEA49F0
signed __int64 __fastcall NvAPI_D3D10_SetPrimaryFlipChainCallbacks(unsigned int *pDev, NVAPI_FLIP_CHAIN_CALLBACK_PARAMS *pCallbackParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NVAPI_FLIP_CHAIN_CALLBACK_PARAMS *v9; // [rsp+58h] [rbp+10h]

  v9 = pCallbackParams;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_123 = 0i64;
  if ( !fp_123 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_123 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x73EB9329u);
  if ( !fp_123 )
    return 4294967293i64;
  v3 = fp_123;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x73EB9329u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NVAPI_FLIP_CHAIN_CALLBACK_PARAMS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x73EB9329u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4002
// RVA: 0xEA4B20
signed __int64 __fastcall NvAPI_D3D10_ProcessCallbacks(unsigned int *pDev, unsigned int dwMilliseconds)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = dwMilliseconds;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_124 = 0i64;
  if ( !fp_124 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_124 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE9C2019);
  if ( !fp_124 )
    return 4294967293i64;
  v3 = fp_124;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE9C2019, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE9C2019, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4027
// RVA: 0xEA4C50
signed __int64 __fastcall NvAPI_D3D10_GetRenderedCursorAsBitmap(unsigned int *pDev, _NVAPI_RENDERED_CURSOR_BITMAP_DATA *pRenderedCursorBitmapData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_RENDERED_CURSOR_BITMAP_DATA *v9; // [rsp+58h] [rbp+10h]

  v9 = pRenderedCursorBitmapData;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_125 = 0i64;
  if ( !fp_125 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_125 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCAC3CE5D);
  if ( !fp_125 )
    return 4294967293i64;
  v3 = fp_125;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCAC3CE5D, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NVAPI_RENDERED_CURSOR_BITMAP_DATA *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCAC3CE5D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4052
// RVA: 0xEA4D80
signed __int64 __fastcall NvAPI_D3D10_BeginShareResource(unsigned int *pResource, void **pHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  void **v9; // [rsp+58h] [rbp+10h]

  v9 = pHandle;
  v8 = pResource;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_126 = 0i64;
  if ( !fp_126 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_126 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x35233210u);
  if ( !fp_126 )
    return 4294967293i64;
  v3 = fp_126;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x35233210u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, void **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x35233210u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4077
// RVA: 0xEA4EB0
signed __int64 __fastcall NvAPI_D3D10_BeginShareResourceEx(unsigned int *pResource, unsigned int flags, void **pHandle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  void **v11; // [rsp+60h] [rbp+18h]

  v11 = pHandle;
  v10 = flags;
  v9 = pResource;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_127 = 0i64;
  if ( !fp_127 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_127 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEF303A9D);
  if ( !fp_127 )
    return 4294967293i64;
  v4 = fp_127;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEF303A9D, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, void **))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEF303A9D, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4102
// RVA: 0xEA4FE0
signed __int64 __fastcall NvAPI_D3D10_EndShareResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pResource;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_128 = 0i64;
  if ( !fp_128 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_128 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE9C5853u);
  if ( !fp_128 )
    return 4294967293i64;
  v2 = fp_128;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE9C5853u, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE9C5853u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 4127
// RVA: 0xEA5100
signed __int64 __fastcall NvAPI_D3D10_SetDepthBoundsTest(unsigned int *pDev, unsigned int bEnable, float fMinDepth, float fMaxDepth)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]

  v11 = bEnable;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_129 = 0i64;
  if ( !fp_129 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_129 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4EADF5D2u);
  if ( !fp_129 )
    return 4294967293i64;
  v5 = fp_129;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4EADF5D2u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v5)(v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4EADF5D2u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 4152
// RVA: 0xEA5240
signed __int64 __fastcall NvAPI_D3D10_CreateDevice(unsigned int *pAdapter, unsigned int DriverType, HINSTANCE__ *Software, unsigned int Flags, unsigned int HardwareLevel, unsigned int SDKVersion, unsigned int **ppDevice, NVAPI_DEVICE_FEATURE_LEVEL *pLevel)
{
  __int64 (__fastcall *v9)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h]
  unsigned __int64 v11; // [rsp+50h] [rbp-18h]
  _NvAPI_Status v12; // [rsp+58h] [rbp-10h]
  int v13; // [rsp+5Ch] [rbp-Ch]
  unsigned int *v14; // [rsp+70h] [rbp+8h]
  unsigned int v15; // [rsp+78h] [rbp+10h]
  HINSTANCE__ *v16; // [rsp+80h] [rbp+18h]
  unsigned int v17; // [rsp+88h] [rbp+20h]

  v17 = Flags;
  v16 = Software;
  v15 = DriverType;
  v14 = pAdapter;
  hMod = 0i64;
  v13 = 0;
  v12 = (unsigned int)GetGpuHandle(&hMod);
  if ( v12 && v12 != -14 )
    return v12;
  if ( v12 == -14 )
    fp_130 = 0i64;
  if ( !fp_130 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_130 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2DE11D61u);
  if ( !fp_130 )
    return 4294967293i64;
  v9 = fp_130;
  v11 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2DE11D61u, &v11);
  v12 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, unsigned int, unsigned int, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *))v9)(
          v14,
          v15,
          v16,
          v17,
          HardwareLevel,
          SDKVersion,
          ppDevice,
          pLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2DE11D61u, v11, v12);
  --g_module_numApiInUse[v13];
  return v12;
}

// File Line: 4177
// RVA: 0xEA53B0
signed __int64 __fastcall NvAPI_D3D10_CreateDeviceAndSwapChain(unsigned int *pAdapter, unsigned int DriverType, HINSTANCE__ *Software, unsigned int Flags, unsigned int HardwareLevel, unsigned int SDKVersion, unsigned int *pSwapChainDesc, unsigned int **ppSwapChain, unsigned int **ppDevice, NVAPI_DEVICE_FEATURE_LEVEL *pLevel)
{
  __int64 (__fastcall *v11)(); // [rsp+50h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+58h] [rbp-20h]
  unsigned __int64 v13; // [rsp+60h] [rbp-18h]
  _NvAPI_Status v14; // [rsp+68h] [rbp-10h]
  int v15; // [rsp+6Ch] [rbp-Ch]
  unsigned int *v16; // [rsp+80h] [rbp+8h]
  unsigned int v17; // [rsp+88h] [rbp+10h]
  HINSTANCE__ *v18; // [rsp+90h] [rbp+18h]
  unsigned int v19; // [rsp+98h] [rbp+20h]

  v19 = Flags;
  v18 = Software;
  v17 = DriverType;
  v16 = pAdapter;
  hMod = 0i64;
  v15 = 0;
  v14 = (unsigned int)GetGpuHandle(&hMod);
  if ( v14 && v14 != -14 )
    return v14;
  if ( v14 == -14 )
    fp_131 = 0i64;
  if ( !fp_131 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_131 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5B803DAFu);
  if ( !fp_131 )
    return 4294967293i64;
  v11 = fp_131;
  v13 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5B803DAFu, &v13);
  v14 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, unsigned int, unsigned int, unsigned int *, unsigned int **, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *))v11)(
          v16,
          v17,
          v18,
          v19,
          HardwareLevel,
          SDKVersion,
          pSwapChainDesc,
          ppSwapChain,
          ppDevice,
          pLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5B803DAFu, v13, v14);
  --g_module_numApiInUse[v15];
  return v14;
}

// File Line: 4202
// RVA: 0xEA5540
signed __int64 __fastcall NvAPI_D3D11_CreateDevice(unsigned int *pAdapter, unsigned int DriverType, HINSTANCE__ *Software, unsigned int Flags, const unsigned int *pFeatureLevels, unsigned int FeatureLevels, unsigned int SDKVersion, unsigned int **ppDevice, unsigned int *pFeatureLevel, unsigned int **ppImmediateContext, NVAPI_DEVICE_FEATURE_LEVEL *pSupportedLevel)
{
  __int64 (__fastcall *v12)(); // [rsp+60h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+68h] [rbp-20h]
  unsigned __int64 v14; // [rsp+70h] [rbp-18h]
  _NvAPI_Status v15; // [rsp+78h] [rbp-10h]
  int v16; // [rsp+7Ch] [rbp-Ch]
  unsigned int *v17; // [rsp+90h] [rbp+8h]
  unsigned int v18; // [rsp+98h] [rbp+10h]
  HINSTANCE__ *v19; // [rsp+A0h] [rbp+18h]
  unsigned int v20; // [rsp+A8h] [rbp+20h]

  v20 = Flags;
  v19 = Software;
  v18 = DriverType;
  v17 = pAdapter;
  hMod = 0i64;
  v16 = 0;
  v15 = (unsigned int)GetGpuHandle(&hMod);
  if ( v15 && v15 != -14 )
    return v15;
  if ( v15 == -14 )
    fp_132 = 0i64;
  if ( !fp_132 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_132 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6A16D3A0u);
  if ( !fp_132 )
    return 4294967293i64;
  v12 = fp_132;
  v14 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6A16D3A0u, &v14);
  v15 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, const unsigned int *, unsigned int, unsigned int, unsigned int **, unsigned int *, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *))v12)(
          v17,
          v18,
          v19,
          v20,
          pFeatureLevels,
          FeatureLevels,
          SDKVersion,
          ppDevice,
          pFeatureLevel,
          ppImmediateContext,
          pSupportedLevel);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6A16D3A0u, v14, v15);
  --g_module_numApiInUse[v16];
  return v15;
}

// File Line: 4227
// RVA: 0xEA56F0
signed __int64 __fastcall NvAPI_D3D11_CreateDeviceAndSwapChain(unsigned int *pAdapter, unsigned int DriverType, HINSTANCE__ *Software, unsigned int Flags, const unsigned int *pFeatureLevels, unsigned int FeatureLevels, unsigned int SDKVersion, const unsigned int *pSwapChainDesc, unsigned int **ppSwapChain, unsigned int **ppDevice, unsigned int *pFeatureLevel, unsigned int **ppImmediateContext, NVAPI_DEVICE_FEATURE_LEVEL *pSupportedLevel)
{
  __int64 (__fastcall *v14)(); // [rsp+70h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+78h] [rbp-20h]
  unsigned __int64 v16; // [rsp+80h] [rbp-18h]
  _NvAPI_Status v17; // [rsp+88h] [rbp-10h]
  int v18; // [rsp+8Ch] [rbp-Ch]
  unsigned int *v19; // [rsp+A0h] [rbp+8h]
  unsigned int v20; // [rsp+A8h] [rbp+10h]
  HINSTANCE__ *v21; // [rsp+B0h] [rbp+18h]
  unsigned int v22; // [rsp+B8h] [rbp+20h]

  v22 = Flags;
  v21 = Software;
  v20 = DriverType;
  v19 = pAdapter;
  hMod = 0i64;
  v18 = 0;
  v17 = (unsigned int)GetGpuHandle(&hMod);
  if ( v17 && v17 != -14 )
    return v17;
  if ( v17 == -14 )
    fp_133 = 0i64;
  if ( !fp_133 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_133 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBB939EE5);
  if ( !fp_133 )
    return 4294967293i64;
  v14 = fp_133;
  v16 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBB939EE5, &v16);
  v17 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, HINSTANCE__ *, _QWORD, const unsigned int *, unsigned int, unsigned int, const unsigned int *, unsigned int **, unsigned int **, unsigned int *, unsigned int **, NVAPI_DEVICE_FEATURE_LEVEL *))v14)(
          v19,
          v20,
          v21,
          v22,
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
    g_nvapi_callReturn(0xBB939EE5, v16, v17);
  --g_module_numApiInUse[v18];
  return v17;
}

// File Line: 4252
// RVA: 0xEA58E0
signed __int64 __fastcall NvAPI_D3D11_BeginShareResource(unsigned int *pResource, unsigned int flags, void **pHandle)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  void **v11; // [rsp+60h] [rbp+18h]

  v11 = pHandle;
  v10 = flags;
  v9 = pResource;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_134 = 0i64;
  if ( !fp_134 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_134 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x121BDC6u);
  if ( !fp_134 )
    return 4294967293i64;
  v4 = fp_134;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x121BDC6u, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, void **))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x121BDC6u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4277
// RVA: 0xEA5A10
signed __int64 __fastcall NvAPI_D3D11_EndShareResource(unsigned int *pResource)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pResource;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_135 = 0i64;
  if ( !fp_135 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_135 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8FFB8E26);
  if ( !fp_135 )
    return 4294967293i64;
  v2 = fp_135;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8FFB8E26, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8FFB8E26, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 4302
// RVA: 0xEA5B30
signed __int64 __fastcall NvAPI_D3D11_SetDepthBoundsTest(unsigned int *pDev, unsigned int bEnable, float fMinDepth, float fMaxDepth)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]

  v11 = bEnable;
  v10 = pDev;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_136 = 0i64;
  if ( !fp_136 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_136 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7AAF7A04u);
  if ( !fp_136 )
    return 4294967293i64;
  v5 = fp_136;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7AAF7A04u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD))v5)(v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7AAF7A04u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 4327
// RVA: 0xEA5C70
signed __int64 __fastcall NvAPI_GPU_GetShaderPipeCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_137 = 0i64;
  if ( !fp_137 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_137 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63E2F56Fu);
  if ( !fp_137 )
    return 4294967293i64;
  v3 = fp_137;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63E2F56Fu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63E2F56Fu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4352
// RVA: 0xEA5DA0
signed __int64 __fastcall NvAPI_GPU_GetShaderSubPipeCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_138 = 0i64;
  if ( !fp_138 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_138 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBE17923u);
  if ( !fp_138 )
    return 4294967293i64;
  v3 = fp_138;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBE17923u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBE17923u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4377
// RVA: 0xEA5ED0
signed __int64 __fastcall NvAPI_GPU_GetPartitionCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_139 = 0i64;
  if ( !fp_139 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_139 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x86F05D7A);
  if ( !fp_139 )
    return 4294967293i64;
  v3 = fp_139;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x86F05D7A, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x86F05D7A, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4402
// RVA: 0xEA6000
signed __int64 __fastcall NvAPI_GPU_GetMemPartitionMask(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_140 = 0i64;
  if ( !fp_140 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_140 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x329D77CDu);
  if ( !fp_140 )
    return 4294967293i64;
  v3 = fp_140;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x329D77CDu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x329D77CDu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4427
// RVA: 0xEA6130
signed __int64 __fastcall NvAPI_GPU_GetTPCMask(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_141 = 0i64;
  if ( !fp_141 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_141 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4A35DF54u);
  if ( !fp_141 )
    return 4294967293i64;
  v3 = fp_141;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4A35DF54u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4A35DF54u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4452
// RVA: 0xEA6260
signed __int64 __fastcall NvAPI_GPU_GetSMMask(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int tpcId, unsigned int *pMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pMask;
  v10 = tpcId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_142 = 0i64;
  if ( !fp_142 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_142 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEB7AF173);
  if ( !fp_142 )
    return 4294967293i64;
  v4 = fp_142;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEB7AF173, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEB7AF173, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4477
// RVA: 0xEA6390
signed __int64 __fastcall NvAPI_GPU_GetTotalTPCCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_143 = 0i64;
  if ( !fp_143 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_143 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4E2F76A8u);
  if ( !fp_143 )
    return 4294967293i64;
  v3 = fp_143;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4E2F76A8u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4E2F76A8u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4502
// RVA: 0xEA64C0
signed __int64 __fastcall NvAPI_GPU_GetTotalSMCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_144 = 0i64;
  if ( !fp_144 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_144 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE5FBCFE);
  if ( !fp_144 )
    return 4294967293i64;
  v3 = fp_144;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE5FBCFE, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE5FBCFE, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4527
// RVA: 0xEA65F0
signed __int64 __fastcall NvAPI_GPU_GetTotalSPCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_145 = 0i64;
  if ( !fp_145 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_145 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB6D62591);
  if ( !fp_145 )
    return 4294967293i64;
  v3 = fp_145;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB6D62591, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB6D62591, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4552
// RVA: 0xEA6720
signed __int64 __fastcall NvAPI_GPU_GetGpuCoreCount(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCount;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_146 = 0i64;
  if ( !fp_146 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_146 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC7026A87);
  if ( !fp_146 )
    return 4294967293i64;
  v3 = fp_146;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC7026A87, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC7026A87, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4577
// RVA: 0xEA6850
signed __int64 __fastcall NvAPI_GPU_GetAllOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_147 = 0i64;
  if ( !fp_147 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_147 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7D554F8Eu);
  if ( !fp_147 )
    return 4294967293i64;
  v3 = fp_147;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7D554F8Eu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7D554F8Eu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4602
// RVA: 0xEA6980
signed __int64 __fastcall NvAPI_GPU_GetConnectedOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_148 = 0i64;
  if ( !fp_148 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_148 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1730BFC9u);
  if ( !fp_148 )
    return 4294967293i64;
  v3 = fp_148;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1730BFC9u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1730BFC9u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4627
// RVA: 0xEA6AB0
signed __int64 __fastcall NvAPI_GPU_GetConnectedSLIOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_149 = 0i64;
  if ( !fp_149 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_149 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x680DE09u);
  if ( !fp_149 )
    return 4294967293i64;
  v3 = fp_149;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x680DE09u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x680DE09u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4652
// RVA: 0xEA6BE0
signed __int64 __fastcall NvAPI_GPU_GetConnectedDisplayIds(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_DISPLAYIDS *pDisplayIds, unsigned int *pDisplayIdCount, unsigned int flags)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  _NV_GPU_DISPLAYIDS *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = flags;
  v12 = pDisplayIdCount;
  v11 = pDisplayIds;
  v10 = hPhysicalGpu;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_150 = 0i64;
  if ( !fp_150 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_150 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x78DBA2u);
  if ( !fp_150 )
    return 4294967293i64;
  v5 = fp_150;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x78DBA2u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_DISPLAYIDS *, unsigned int *, _QWORD))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x78DBA2u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 4677
// RVA: 0xEA6D20
signed __int64 __fastcall NvAPI_GPU_GetAllDisplayIds(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_DISPLAYIDS *pDisplayIds, unsigned int *pDisplayIdCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  _NV_GPU_DISPLAYIDS *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pDisplayIdCount;
  v10 = pDisplayIds;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_151 = 0i64;
  if ( !fp_151 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_151 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x785210A2u);
  if ( !fp_151 )
    return 4294967293i64;
  v4 = fp_151;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x785210A2u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_DISPLAYIDS *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x785210A2u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4702
// RVA: 0xEA6E60
signed __int64 __fastcall NvAPI_GPU_GetConnectedOutputsWithLidState(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_152 = 0i64;
  if ( !fp_152 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_152 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCF8CAF39);
  if ( !fp_152 )
    return 4294967293i64;
  v3 = fp_152;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCF8CAF39, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCF8CAF39, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4727
// RVA: 0xEA6F90
signed __int64 __fastcall NvAPI_GPU_GetConnectedSLIOutputsWithLidState(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_153 = 0i64;
  if ( !fp_153 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_153 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x96043CC7);
  if ( !fp_153 )
    return 4294967293i64;
  v3 = fp_153;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x96043CC7, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x96043CC7, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4752
// RVA: 0xEA70C0
signed __int64 __fastcall NvAPI_GPU_GetSystemType(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_SYSTEM_TYPE *pSystemType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_SYSTEM_TYPE *v9; // [rsp+58h] [rbp+10h]

  v9 = pSystemType;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_154 = 0i64;
  if ( !fp_154 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_154 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBAAABFCC);
  if ( !fp_154 )
    return 4294967293i64;
  v3 = fp_154;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBAAABFCC, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_SYSTEM_TYPE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBAAABFCC, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4777
// RVA: 0xEA71F0
signed __int64 __fastcall NvAPI_GPU_GetActiveOutputs(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pOutputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pOutputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_155 = 0i64;
  if ( !fp_155 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_155 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE3E89B6F);
  if ( !fp_155 )
    return 4294967293i64;
  v3 = fp_155;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE3E89B6F, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE3E89B6F, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4802
// RVA: 0xEA7320
signed __int64 __fastcall NvAPI_GPU_GetEDID(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int displayOutputId, NV_EDID_V3 *pEDID)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_EDID_V3 *v11; // [rsp+60h] [rbp+18h]

  v11 = pEDID;
  v10 = displayOutputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_156 = 0i64;
  if ( !fp_156 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_156 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x37D32E69u);
  if ( !fp_156 )
    return 4294967293i64;
  v4 = fp_156;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x37D32E69u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_EDID_V3 *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x37D32E69u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4827
// RVA: 0xEA7450
signed __int64 __fastcall NvAPI_GPU_SetEDID(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int displayOutputId, NV_EDID_V3 *pEDID)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_EDID_V3 *v11; // [rsp+60h] [rbp+18h]

  v11 = pEDID;
  v10 = displayOutputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_157 = 0i64;
  if ( !fp_157 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_157 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE83D6456);
  if ( !fp_157 )
    return 4294967293i64;
  v4 = fp_157;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE83D6456, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_EDID_V3 *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE83D6456, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4852
// RVA: 0xEA7580
signed __int64 __fastcall NvAPI_GPU_GetOutputType(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, _NV_GPU_OUTPUT_TYPE *pOutputType)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  _NV_GPU_OUTPUT_TYPE *v11; // [rsp+60h] [rbp+18h]

  v11 = pOutputType;
  v10 = outputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_158 = 0i64;
  if ( !fp_158 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_158 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x40A505E4u);
  if ( !fp_158 )
    return 4294967293i64;
  v4 = fp_158;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x40A505E4u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _NV_GPU_OUTPUT_TYPE *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x40A505E4u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4877
// RVA: 0xEA76B0
signed __int64 __fastcall NvAPI_GPU_GetDeviceDisplayMode(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int displayId, NV_GPU_DISPLAY_MODE *pDeviceDisplayMode)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_DISPLAY_MODE *v11; // [rsp+60h] [rbp+18h]

  v11 = pDeviceDisplayMode;
  v10 = displayId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_159 = 0i64;
  if ( !fp_159 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_159 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2277E3A);
  if ( !fp_159 )
    return 4294967293i64;
  v4 = fp_159;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2277E3A, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_DISPLAY_MODE *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2277E3A, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4902
// RVA: 0xEA77E0
signed __int64 __fastcall NvAPI_GPU_GetFlatPanelInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, NV_GPU_FLAT_PANEL_INFO *pFlatPanelInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_FLAT_PANEL_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pFlatPanelInfo;
  v10 = outputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_160 = 0i64;
  if ( !fp_160 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_160 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x36CFF969u);
  if ( !fp_160 )
    return 4294967293i64;
  v4 = fp_160;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x36CFF969u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_FLAT_PANEL_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x36CFF969u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4927
// RVA: 0xEA7910
signed __int64 __fastcall NvAPI_GPU_ValidateOutputCombination(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputsMask)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = outputsMask;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_161 = 0i64;
  if ( !fp_161 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_161 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x34C9C2D4u);
  if ( !fp_161 )
    return 4294967293i64;
  v3 = fp_161;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x34C9C2D4u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x34C9C2D4u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 4952
// RVA: 0xEA7A40
signed __int64 __fastcall NvAPI_GPU_GetConnectorInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, NV_GPU_CONNECTOR_INFO *pConnectorInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_CONNECTOR_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pConnectorInfo;
  v10 = outputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_162 = 0i64;
  if ( !fp_162 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_162 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4ECA2C10u);
  if ( !fp_162 )
    return 4294967293i64;
  v4 = fp_162;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4ECA2C10u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_CONNECTOR_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4ECA2C10u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 4977
// RVA: 0xEA7B70
signed __int64 __fastcall NvAPI_GPU_GetFullName(NvPhysicalGpuHandle__ *hPhysicalGpu, char *szName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szName;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_163 = 0i64;
  if ( !fp_163 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_163 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCEEE8E9F);
  if ( !fp_163 )
    return 4294967293i64;
  v3 = fp_163;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCEEE8E9F, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCEEE8E9F, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5002
// RVA: 0xEA7CA0
signed __int64 __fastcall NvAPI_GPU_GetPCIIdentifiers(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pDeviceId, unsigned int *pSubSystemId, unsigned int *pRevisionId, unsigned int *pExtDeviceId)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v11; // [rsp+60h] [rbp+8h]
  unsigned int *v12; // [rsp+68h] [rbp+10h]
  unsigned int *v13; // [rsp+70h] [rbp+18h]
  unsigned int *v14; // [rsp+78h] [rbp+20h]

  v14 = pRevisionId;
  v13 = pSubSystemId;
  v12 = pDeviceId;
  v11 = hPhysicalGpu;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_164 = 0i64;
  if ( !fp_164 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_164 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2DDFB66Eu);
  if ( !fp_164 )
    return 4294967293i64;
  v6 = fp_164;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2DDFB66Eu, &v8);
  v9 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, unsigned int *, unsigned int *, unsigned int *))v6)(
         v11,
         v12,
         v13,
         v14,
         pExtDeviceId);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2DDFB66Eu, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 5027
// RVA: 0xEA7DF0
signed __int64 __fastcall NvAPI_GPU_GetGPUType(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_TYPE *pGpuType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_GPU_TYPE *v9; // [rsp+58h] [rbp+10h]

  v9 = pGpuType;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_165 = 0i64;
  if ( !fp_165 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_165 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC33BAEB1);
  if ( !fp_165 )
    return 4294967293i64;
  v3 = fp_165;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC33BAEB1, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_TYPE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC33BAEB1, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5052
// RVA: 0xEA7F20
signed __int64 __fastcall NvAPI_GPU_GetBusType(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_BUS_TYPE *pBusType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_GPU_BUS_TYPE *v9; // [rsp+58h] [rbp+10h]

  v9 = pBusType;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_166 = 0i64;
  if ( !fp_166 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_166 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1BB18724u);
  if ( !fp_166 )
    return 4294967293i64;
  v3 = fp_166;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1BB18724u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_BUS_TYPE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1BB18724u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5077
// RVA: 0xEA8050
signed __int64 __fastcall NvAPI_GPU_GetBusId(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBusId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pBusId;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_167 = 0i64;
  if ( !fp_167 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_167 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1BE0B8E5u);
  if ( !fp_167 )
    return 4294967293i64;
  v3 = fp_167;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1BE0B8E5u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1BE0B8E5u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5102
// RVA: 0xEA8180
signed __int64 __fastcall NvAPI_GPU_GetBusSlotId(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBusSlotId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pBusSlotId;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_168 = 0i64;
  if ( !fp_168 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_168 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2A0A350Fu);
  if ( !fp_168 )
    return 4294967293i64;
  v3 = fp_168;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2A0A350Fu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2A0A350Fu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5127
// RVA: 0xEA82B0
signed __int64 __fastcall NvAPI_GPU_GetIRQ(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pIRQ)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pIRQ;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_169 = 0i64;
  if ( !fp_169 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_169 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE4715417);
  if ( !fp_169 )
    return 4294967293i64;
  v3 = fp_169;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE4715417, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE4715417, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5152
// RVA: 0xEA83E0
signed __int64 __fastcall NvAPI_GPU_GetVbiosRevision(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBiosRevision)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pBiosRevision;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_170 = 0i64;
  if ( !fp_170 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_170 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xACC3DA0A);
  if ( !fp_170 )
    return 4294967293i64;
  v3 = fp_170;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xACC3DA0A, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xACC3DA0A, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5177
// RVA: 0xEA8510
signed __int64 __fastcall NvAPI_GPU_GetVbiosOEMRevision(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBiosRevision)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pBiosRevision;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_171 = 0i64;
  if ( !fp_171 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_171 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2D43FB31u);
  if ( !fp_171 )
    return 4294967293i64;
  v3 = fp_171;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2D43FB31u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2D43FB31u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5202
// RVA: 0xEA8640
signed __int64 __fastcall NvAPI_GPU_GetVbiosVersionString(NvPhysicalGpuHandle__ *hPhysicalGpu, char *szBiosRevision)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szBiosRevision;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_172 = 0i64;
  if ( !fp_172 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_172 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA561FD7D);
  if ( !fp_172 )
    return 4294967293i64;
  v3 = fp_172;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA561FD7D, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA561FD7D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5227
// RVA: 0xEA8770
signed __int64 __fastcall NvAPI_GPU_GetAGPAperture(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pSize;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_173 = 0i64;
  if ( !fp_173 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_173 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6E042794u);
  if ( !fp_173 )
    return 4294967293i64;
  v3 = fp_173;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6E042794u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6E042794u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5252
// RVA: 0xEA88A0
signed __int64 __fastcall NvAPI_GPU_GetCurrentAGPRate(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pRate)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pRate;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_174 = 0i64;
  if ( !fp_174 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_174 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC74925A0);
  if ( !fp_174 )
    return 4294967293i64;
  v3 = fp_174;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC74925A0, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC74925A0, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5277
// RVA: 0xEA89D0
signed __int64 __fastcall NvAPI_GPU_GetCurrentPCIEDownstreamWidth(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pWidth)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pWidth;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_175 = 0i64;
  if ( !fp_175 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_175 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD048C3B1);
  if ( !fp_175 )
    return 4294967293i64;
  v3 = fp_175;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD048C3B1, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD048C3B1, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5302
// RVA: 0xEA8B00
signed __int64 __fastcall NvAPI_GPU_GetPhysicalFrameBufferSize(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pSize;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_176 = 0i64;
  if ( !fp_176 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_176 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x46FBEB03u);
  if ( !fp_176 )
    return 4294967293i64;
  v3 = fp_176;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x46FBEB03u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x46FBEB03u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5327
// RVA: 0xEA8C30
signed __int64 __fastcall NvAPI_GPU_GetVirtualFrameBufferSize(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pSize)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pSize;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_177 = 0i64;
  if ( !fp_177 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_177 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5A04B644u);
  if ( !fp_177 )
    return 4294967293i64;
  v3 = fp_177;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5A04B644u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5A04B644u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5352
// RVA: 0xEA8D60
signed __int64 __fastcall NvAPI_GPU_GetQuadroStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_178 = 0i64;
  if ( !fp_178 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_178 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE332FA47);
  if ( !fp_178 )
    return 4294967293i64;
  v3 = fp_178;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE332FA47, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE332FA47, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5377
// RVA: 0xEA8E90
signed __int64 __fastcall NvAPI_GPU_GetBoardInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_BOARD_INFO *pBoardInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_BOARD_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pBoardInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_179 = 0i64;
  if ( !fp_179 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_179 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22D54523u);
  if ( !fp_179 )
    return 4294967293i64;
  v3 = fp_179;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22D54523u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_BOARD_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22D54523u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5402
// RVA: 0xEA8FC0
signed __int64 __fastcall NvAPI_GPU_GetRamType(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_RAM_TYPE *pRamType)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_RAM_TYPE *v9; // [rsp+58h] [rbp+10h]

  v9 = pRamType;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_180 = 0i64;
  if ( !fp_180 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_180 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x57F7CAACu);
  if ( !fp_180 )
    return 4294967293i64;
  v3 = fp_180;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x57F7CAACu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_RAM_TYPE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x57F7CAACu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5427
// RVA: 0xEA90F0
signed __int64 __fastcall NvAPI_GPU_GetFBWidthAndLocation(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pBusWidth, _NV_GPU_FB_LOCATION *pFBLocation)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  _NV_GPU_FB_LOCATION *v11; // [rsp+60h] [rbp+18h]

  v11 = pFBLocation;
  v10 = pBusWidth;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_181 = 0i64;
  if ( !fp_181 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_181 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x11104158u);
  if ( !fp_181 )
    return 4294967293i64;
  v4 = fp_181;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x11104158u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, _NV_GPU_FB_LOCATION *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x11104158u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5452
// RVA: 0xEA9230
signed __int64 __fastcall NvAPI_GPU_GetAllClockFrequencies(NvPhysicalGpuHandle__ *hPhysicalGPU, NV_GPU_CLOCK_FREQUENCIES_V2 *pClkFreqs)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_CLOCK_FREQUENCIES_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pClkFreqs;
  v8 = hPhysicalGPU;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_182 = 0i64;
  if ( !fp_182 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_182 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDCB616C3);
  if ( !fp_182 )
    return 4294967293i64;
  v3 = fp_182;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDCB616C3, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLOCK_FREQUENCIES_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDCB616C3, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5477
// RVA: 0xEA9360
signed __int64 __fastcall NvAPI_GPU_GetPerfClocks(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int level, NV_GPU_PERF_CLOCK_TABLE *pPerfClkTable)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_PERF_CLOCK_TABLE *v11; // [rsp+60h] [rbp+18h]

  v11 = pPerfClkTable;
  v10 = level;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_183 = 0i64;
  if ( !fp_183 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_183 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1EA54A3Bu);
  if ( !fp_183 )
    return 4294967293i64;
  v4 = fp_183;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1EA54A3Bu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_PERF_CLOCK_TABLE *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1EA54A3Bu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5502
// RVA: 0xEA9490
signed __int64 __fastcall NvAPI_GPU_SetPerfClocks(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int level, NV_GPU_PERF_CLOCK_TABLE *pPerfClkTable)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_PERF_CLOCK_TABLE *v11; // [rsp+60h] [rbp+18h]

  v11 = pPerfClkTable;
  v10 = level;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_184 = 0i64;
  if ( !fp_184 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_184 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7BCF4ACu);
  if ( !fp_184 )
    return 4294967293i64;
  v4 = fp_184;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7BCF4ACu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_PERF_CLOCK_TABLE *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7BCF4ACu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5527
// RVA: 0xEA95C0
signed __int64 __fastcall NvAPI_GPU_GetCoolerSettings(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int coolerIndex, NV_GPU_GETCOOLER_SETTINGS_V3 *pCoolerInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_GETCOOLER_SETTINGS_V3 *v11; // [rsp+60h] [rbp+18h]

  v11 = pCoolerInfo;
  v10 = coolerIndex;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_185 = 0i64;
  if ( !fp_185 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_185 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA141340);
  if ( !fp_185 )
    return 4294967293i64;
  v4 = fp_185;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA141340, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_GETCOOLER_SETTINGS_V3 *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA141340, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5552
// RVA: 0xEA96F0
signed __int64 __fastcall NvAPI_GPU_SetCoolerLevels(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int coolerIndex, NV_GPU_SETCOOLER_LEVEL_V2 *pCoolerLevels)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_SETCOOLER_LEVEL_V2 *v11; // [rsp+60h] [rbp+18h]

  v11 = pCoolerLevels;
  v10 = coolerIndex;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_186 = 0i64;
  if ( !fp_186 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_186 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x891FA0AE);
  if ( !fp_186 )
    return 4294967293i64;
  v4 = fp_186;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x891FA0AE, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_SETCOOLER_LEVEL_V2 *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x891FA0AE, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5577
// RVA: 0xEA9820
signed __int64 __fastcall NvAPI_GPU_RestoreCoolerSettings(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCoolerIndex, unsigned int coolerCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = coolerCount;
  v10 = pCoolerIndex;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_187 = 0i64;
  if ( !fp_187 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_187 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8F6ED0FB);
  if ( !fp_187 )
    return 4294967293i64;
  v4 = fp_187;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8F6ED0FB, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8F6ED0FB, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5602
// RVA: 0xEA9960
signed __int64 __fastcall NvAPI_GPU_GetCoolerPolicyTable(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int coolerIndex, NV_GPU_COOLER_POLICY_TABLE *pCoolerTable, unsigned int *count)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  NV_GPU_COOLER_POLICY_TABLE *v12; // [rsp+60h] [rbp+18h]
  unsigned int *v13; // [rsp+68h] [rbp+20h]

  v13 = count;
  v12 = pCoolerTable;
  v11 = coolerIndex;
  v10 = hPhysicalGpu;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_188 = 0i64;
  if ( !fp_188 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_188 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x518A32Cu);
  if ( !fp_188 )
    return 4294967293i64;
  v5 = fp_188;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x518A32Cu, &v7);
  v8 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_COOLER_POLICY_TABLE *, unsigned int *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x518A32Cu, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 5627
// RVA: 0xEA9AA0
signed __int64 __fastcall NvAPI_GPU_SetCoolerPolicyTable(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int coolerIndex, NV_GPU_COOLER_POLICY_TABLE *pCoolerTable, unsigned int count)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  NV_GPU_COOLER_POLICY_TABLE *v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = count;
  v12 = pCoolerTable;
  v11 = coolerIndex;
  v10 = hPhysicalGpu;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_189 = 0i64;
  if ( !fp_189 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_189 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x987947CD);
  if ( !fp_189 )
    return 4294967293i64;
  v5 = fp_189;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x987947CD, &v7);
  v8 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_COOLER_POLICY_TABLE *, _QWORD))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x987947CD, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 5652
// RVA: 0xEA9BE0
signed __int64 __fastcall NvAPI_GPU_RestoreCoolerPolicyTable(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCoolerIndex, unsigned int coolerCount, NV_COOLER_POLICY policy)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  NV_COOLER_POLICY v13; // [rsp+68h] [rbp+20h]

  v13 = policy;
  v12 = coolerCount;
  v11 = pCoolerIndex;
  v10 = hPhysicalGpu;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_190 = 0i64;
  if ( !fp_190 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_190 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD8C4FE63);
  if ( !fp_190 )
    return 4294967293i64;
  v5 = fp_190;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD8C4FE63, &v7);
  v8 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *, _QWORD, _QWORD))v5)(
         v10,
         v11,
         v12,
         (unsigned int)v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD8C4FE63, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 5677
// RVA: 0xEA9D20
signed __int64 __fastcall NvAPI_GPU_GetPstatesInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_PSTATES_INFO_V2 *pPerfPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_PERF_PSTATES_INFO_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pPerfPstatesInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_191 = 0i64;
  if ( !fp_191 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_191 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBA94C56E);
  if ( !fp_191 )
    return 4294967293i64;
  v3 = fp_191;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBA94C56E, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES_INFO_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBA94C56E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5702
// RVA: 0xEA9E50
signed __int64 __fastcall NvAPI_GPU_GetPstatesInfoEx(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_PSTATES_INFO_V2 *pPerfPstatesInfo, unsigned int inputFlags)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_GPU_PERF_PSTATES_INFO_V2 *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = inputFlags;
  v10 = pPerfPstatesInfo;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_192 = 0i64;
  if ( !fp_192 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_192 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x843C0256);
  if ( !fp_192 )
    return 4294967293i64;
  v4 = fp_192;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x843C0256, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES_INFO_V2 *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x843C0256, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5727
// RVA: 0xEA9F90
signed __int64 __fastcall NvAPI_GPU_SetPstatesInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_PSTATES_INFO_V2 *pPerfPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_PERF_PSTATES_INFO_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pPerfPstatesInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_193 = 0i64;
  if ( !fp_193 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_193 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDF27911);
  if ( !fp_193 )
    return 4294967293i64;
  v3 = fp_193;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDF27911, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES_INFO_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDF27911, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5752
// RVA: 0xEAA0C0
signed __int64 __fastcall NvAPI_GPU_GetPstates20(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_PSTATES20_INFO_V1 *pPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_PERF_PSTATES20_INFO_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pPstatesInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_194 = 0i64;
  if ( !fp_194 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_194 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6FF81213u);
  if ( !fp_194 )
    return 4294967293i64;
  v3 = fp_194;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6FF81213u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES20_INFO_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6FF81213u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5777
// RVA: 0xEAA1F0
signed __int64 __fastcall NvAPI_GPU_SetPstates20(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_PSTATES20_INFO_V1 *pPstatesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_PERF_PSTATES20_INFO_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pPstatesInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_195 = 0i64;
  if ( !fp_195 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_195 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF4DAE6Bu);
  if ( !fp_195 )
    return 4294967293i64;
  v3 = fp_195;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF4DAE6Bu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_PSTATES20_INFO_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF4DAE6Bu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5802
// RVA: 0xEAA320
signed __int64 __fastcall NvAPI_GPU_GetCurrentPstate(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_GPU_PERF_PSTATE_ID *pCurrentPstate)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_GPU_PERF_PSTATE_ID *v9; // [rsp+58h] [rbp+10h]

  v9 = pCurrentPstate;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_196 = 0i64;
  if ( !fp_196 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_196 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x927DA4F6);
  if ( !fp_196 )
    return 4294967293i64;
  v3 = fp_196;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x927DA4F6, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _NV_GPU_PERF_PSTATE_ID *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x927DA4F6, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5827
// RVA: 0xEAA450
signed __int64 __fastcall NvAPI_GPU_GetPstateClientLimits(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_PERF_PSTATE_CLIENT_LIMIT_ID limitId, _NV_GPU_PERF_PSTATE_ID *PstateLimit)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  _NV_PERF_PSTATE_CLIENT_LIMIT_ID v10; // [rsp+58h] [rbp+10h]
  _NV_GPU_PERF_PSTATE_ID *v11; // [rsp+60h] [rbp+18h]

  v11 = PstateLimit;
  v10 = limitId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_197 = 0i64;
  if ( !fp_197 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_197 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x88C82104);
  if ( !fp_197 )
    return 4294967293i64;
  v4 = fp_197;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x88C82104, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _NV_GPU_PERF_PSTATE_ID *))v4)(
         v9,
         (unsigned int)v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x88C82104, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5852
// RVA: 0xEAA580
signed __int64 __fastcall NvAPI_GPU_SetPstateClientLimits(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_PERF_PSTATE_CLIENT_LIMIT_ID limitId, _NV_GPU_PERF_PSTATE_ID PstateLimit)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  _NV_PERF_PSTATE_CLIENT_LIMIT_ID v10; // [rsp+58h] [rbp+10h]
  _NV_GPU_PERF_PSTATE_ID v11; // [rsp+60h] [rbp+18h]

  v11 = PstateLimit;
  v10 = limitId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_198 = 0i64;
  if ( !fp_198 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_198 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFDFC7D49);
  if ( !fp_198 )
    return 4294967293i64;
  v4 = fp_198;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFDFC7D49, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(
         v9,
         (unsigned int)v10,
         (unsigned int)v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFDFC7D49, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 5877
// RVA: 0xEAA6B0
signed __int64 __fastcall NvAPI_GPU_EnableOverclockedPstates(NvPhysicalGpuHandle__ *hPhysicalGpu, char bEnable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned __int8 v9; // [rsp+58h] [rbp+10h]

  v9 = bEnable;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_199 = 0i64;
  if ( !fp_199 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_199 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB23B70EE);
  if ( !fp_199 )
    return 4294967293i64;
  v3 = fp_199;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB23B70EE, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB23B70EE, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5902
// RVA: 0xEAA7E0
signed __int64 __fastcall NvAPI_GPU_EnableDynamicPstates(NvPhysicalGpuHandle__ *hPhysicalGpu, char bEnable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned __int8 v9; // [rsp+58h] [rbp+10h]

  v9 = bEnable;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_200 = 0i64;
  if ( !fp_200 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_200 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA579A0F);
  if ( !fp_200 )
    return 4294967293i64;
  v3 = fp_200;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA579A0F, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA579A0F, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5927
// RVA: 0xEAA910
signed __int64 __fastcall NvAPI_GPU_GetDynamicPstatesInfoEx(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_DYNAMIC_PSTATES_INFO_EX *pDynamicPstatesInfoEx)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_DYNAMIC_PSTATES_INFO_EX *v9; // [rsp+58h] [rbp+10h]

  v9 = pDynamicPstatesInfoEx;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_201 = 0i64;
  if ( !fp_201 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_201 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x60DED2EDu);
  if ( !fp_201 )
    return 4294967293i64;
  v3 = fp_201;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x60DED2EDu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_DYNAMIC_PSTATES_INFO_EX *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x60DED2EDu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5952
// RVA: 0xEAAA40
signed __int64 __fastcall NvAPI_GPU_GetVoltages(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_PERF_VOLTAGES *pPerfVoltages)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_PERF_VOLTAGES *v9; // [rsp+58h] [rbp+10h]

  v9 = pPerfVoltages;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_202 = 0i64;
  if ( !fp_202 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_202 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7D656244u);
  if ( !fp_202 )
    return 4294967293i64;
  v3 = fp_202;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7D656244u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_PERF_VOLTAGES *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7D656244u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 5977
// RVA: 0xEAAB70
signed __int64 __fastcall NvAPI_GPU_GetThermalSettings(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int sensorIndex, NV_GPU_THERMAL_SETTINGS_V2 *pThermalSettings)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GPU_THERMAL_SETTINGS_V2 *v11; // [rsp+60h] [rbp+18h]

  v11 = pThermalSettings;
  v10 = sensorIndex;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_203 = 0i64;
  if ( !fp_203 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_203 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE3640A56);
  if ( !fp_203 )
    return 4294967293i64;
  v4 = fp_203;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE3640A56, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GPU_THERMAL_SETTINGS_V2 *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE3640A56, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6002
// RVA: 0xEAACA0
signed __int64 __fastcall NvAPI_GPU_SetDitherControl(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, _NVAPI_DITHER_TYPE type, _NVAPI_DITHER_BITS bits, _NVAPI_DITHER_MODE mode)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v11; // [rsp+60h] [rbp+8h]
  unsigned int v12; // [rsp+68h] [rbp+10h]
  _NVAPI_DITHER_TYPE v13; // [rsp+70h] [rbp+18h]
  _NVAPI_DITHER_BITS v14; // [rsp+78h] [rbp+20h]

  v14 = bits;
  v13 = type;
  v12 = outputId;
  v11 = hPhysicalGpu;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_204 = 0i64;
  if ( !fp_204 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_204 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDF0DFCDD);
  if ( !fp_204 )
    return 4294967293i64;
  v6 = fp_204;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDF0DFCDD, &v8);
  v9 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD, _QWORD, _NVAPI_DITHER_MODE))v6)(
         v11,
         v12,
         (unsigned int)v13,
         (unsigned int)v14,
         mode);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDF0DFCDD, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 6027
// RVA: 0xEAADF0
signed __int64 __fastcall NvAPI_GPU_GetDitherControl(unsigned int displayId, _NV_GPU_DITHER_CONTROL_V1 *pDitherData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_GPU_DITHER_CONTROL_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pDitherData;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_205 = 0i64;
  if ( !fp_205 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_205 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x932AC8FB);
  if ( !fp_205 )
    return 4294967293i64;
  v3 = fp_205;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x932AC8FB, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _NV_GPU_DITHER_CONTROL_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x932AC8FB, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6052
// RVA: 0xEAAF20
signed __int64 __fastcall NvAPI_GPU_GetColorSpaceConversion(unsigned int displayId, _NV_GPU_COLORSPACE_CONVERSION_V1 *pColorData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_GPU_COLORSPACE_CONVERSION_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pColorData;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_206 = 0i64;
  if ( !fp_206 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_206 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8159E87A);
  if ( !fp_206 )
    return 4294967293i64;
  v3 = fp_206;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8159E87A, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _NV_GPU_COLORSPACE_CONVERSION_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8159E87A, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6077
// RVA: 0xEAB050
signed __int64 __fastcall NvAPI_GPU_SetColorSpaceConversion(unsigned int displayId, _NV_GPU_COLORSPACE_CONVERSION_V1 *pColorData)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_GPU_COLORSPACE_CONVERSION_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pColorData;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_207 = 0i64;
  if ( !fp_207 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_207 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFCABD23A);
  if ( !fp_207 )
    return 4294967293i64;
  v3 = fp_207;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFCABD23A, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _NV_GPU_COLORSPACE_CONVERSION_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFCABD23A, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6102
// RVA: 0xEAB180
signed __int64 __fastcall NvAPI_GetTVOutputInfo(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_DISPLAY_TV_OUTPUT_INFO *pTVOutInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_TV_OUTPUT_INFO *v11; // [rsp+60h] [rbp+18h]

  v11 = pTVOutInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_208 = 0i64;
  if ( !fp_208 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_208 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x30C805D5u);
  if ( !fp_208 )
    return 4294967293i64;
  v4 = fp_208;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x30C805D5u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_DISPLAY_TV_OUTPUT_INFO *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x30C805D5u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6127
// RVA: 0xEAB2B0
signed __int64 __fastcall NvAPI_GetTVEncoderControls(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_TV_ENCODER_CONTROLS *pTvEncoderInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_TV_ENCODER_CONTROLS *v11; // [rsp+60h] [rbp+18h]

  v11 = pTvEncoderInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_209 = 0i64;
  if ( !fp_209 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_209 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5757474Au);
  if ( !fp_209 )
    return 4294967293i64;
  v4 = fp_209;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5757474Au, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_TV_ENCODER_CONTROLS *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5757474Au, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6152
// RVA: 0xEAB3E0
signed __int64 __fastcall NvAPI_SetTVEncoderControls(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_TV_ENCODER_CONTROLS *pTvEncoderInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_TV_ENCODER_CONTROLS *v11; // [rsp+60h] [rbp+18h]

  v11 = pTvEncoderInfo;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_210 = 0i64;
  if ( !fp_210 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_210 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCA36A3AB);
  if ( !fp_210 )
    return 4294967293i64;
  v4 = fp_210;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCA36A3AB, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_TV_ENCODER_CONTROLS *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCA36A3AB, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6177
// RVA: 0xEAB510
signed __int64 __fastcall NvAPI_GetTVOutputBorderColor(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_TV_BORDER_COLOR *pBorderColor)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_TV_BORDER_COLOR *v11; // [rsp+60h] [rbp+18h]

  v11 = pBorderColor;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_211 = 0i64;
  if ( !fp_211 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_211 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6DFD1C8Cu);
  if ( !fp_211 )
    return 4294967293i64;
  v4 = fp_211;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6DFD1C8Cu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_TV_BORDER_COLOR *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6DFD1C8Cu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6202
// RVA: 0xEAB640
signed __int64 __fastcall NvAPI_SetTVOutputBorderColor(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, NV_TV_BORDER_COLOR borderColor)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_TV_BORDER_COLOR v11; // [rsp+60h] [rbp+18h]

  v11 = borderColor;
  v10 = outputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_212 = 0i64;
  if ( !fp_212 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_212 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAED02700);
  if ( !fp_212 )
    return 4294967293i64;
  v4 = fp_212;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAED02700, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, (unsigned int)v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAED02700, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6227
// RVA: 0xEAB770
signed __int64 __fastcall NvAPI_GetDisplayPosition(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int *pXOffset, unsigned int *pYOffset)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  unsigned int *v13; // [rsp+68h] [rbp+20h]

  v13 = pYOffset;
  v12 = pXOffset;
  v11 = outputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_213 = 0i64;
  if ( !fp_213 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_213 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6BB1EE5Du);
  if ( !fp_213 )
    return 4294967293i64;
  v5 = fp_213;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6BB1EE5Du, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, unsigned int *, unsigned int *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6BB1EE5Du, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 6252
// RVA: 0xEAB8B0
signed __int64 __fastcall NvAPI_SetDisplayPosition(NvDisplayHandle__ *hNvDisplay, unsigned int outputId, unsigned int xOffset, unsigned int yOffset)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = yOffset;
  v12 = xOffset;
  v11 = outputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_214 = 0i64;
  if ( !fp_214 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_214 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x57D9060Fu);
  if ( !fp_214 )
    return 4294967293i64;
  v5 = fp_214;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x57D9060Fu, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x57D9060Fu, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 6277
// RVA: 0xEAB9F0
signed __int64 __fastcall NvAPI_GetValidGpuTopologies(NV_GPU_TOPOLOGIES *pTopology, unsigned int *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_GPU_TOPOLOGIES *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pStatus;
  v8 = pTopology;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_215 = 0i64;
  if ( !fp_215 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_215 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5DFAB48Au);
  if ( !fp_215 )
    return 4294967293i64;
  v3 = fp_215;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5DFAB48Au, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5DFAB48Au, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6302
// RVA: 0xEABB20
signed __int64 __fastcall NvAPI_GetInvalidGpuTopologies(NV_GPU_TOPOLOGIES *pTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_GPU_TOPOLOGIES *v7; // [rsp+50h] [rbp+8h]

  v7 = pTopology;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_216 = 0i64;
  if ( !fp_216 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_216 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x15658BE6u);
  if ( !fp_216 )
    return 4294967293i64;
  v2 = fp_216;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x15658BE6u, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x15658BE6u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 6327
// RVA: 0xEABC40
signed __int64 __fastcall NvAPI_SetGpuTopologies(NV_GPU_TOPOLOGIES *pTopology, unsigned int flags)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_GPU_TOPOLOGIES *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = flags;
  v8 = pTopology;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_217 = 0i64;
  if ( !fp_217 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_217 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x25201F3Du);
  if ( !fp_217 )
    return 4294967293i64;
  v3 = fp_217;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x25201F3Du, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x25201F3Du, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6352
// RVA: 0xEABD70
signed __int64 __fastcall NvAPI_GPU_GetPerGpuTopologyStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_218 = 0i64;
  if ( !fp_218 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_218 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA81F8992);
  if ( !fp_218 )
    return 4294967293i64;
  v3 = fp_218;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA81F8992, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA81F8992, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6377
// RVA: 0xEABEA0
signed __int64 __fastcall NvAPI_SYS_GetChipSetTopologyStatus(unsigned int *pStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pStatus;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_219 = 0i64;
  if ( !fp_219 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_219 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8A50F126);
  if ( !fp_219 )
    return 4294967293i64;
  v2 = fp_219;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8A50F126, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8A50F126, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 6402
// RVA: 0xEABFC0
signed __int64 __fastcall NvAPI_GPU_Get_DisplayPort_DongleInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_NVAPI_GET_DP_DONGLE_INFO *pDongleInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_NVAPI_GET_DP_DONGLE_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pDongleInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_220 = 0i64;
  if ( !fp_220 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_220 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x76A70E8Du);
  if ( !fp_220 )
    return 4294967293i64;
  v3 = fp_220;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x76A70E8Du, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_NVAPI_GET_DP_DONGLE_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x76A70E8Du, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6427
// RVA: 0xEAC0F0
signed __int64 __fastcall NvAPI_I2CRead(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_I2C_INFO_V2 *pI2cInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_I2C_INFO_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pI2cInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_221 = 0i64;
  if ( !fp_221 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_221 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2FDE12C5u);
  if ( !fp_221 )
    return 4294967293i64;
  v3 = fp_221;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2FDE12C5u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2FDE12C5u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6452
// RVA: 0xEAC220
signed __int64 __fastcall NvAPI_I2CWrite(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_I2C_INFO_V2 *pI2cInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_I2C_INFO_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pI2cInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_222 = 0i64;
  if ( !fp_222 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_222 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE812EB07);
  if ( !fp_222 )
    return 4294967293i64;
  v3 = fp_222;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE812EB07, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE812EB07, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6477
// RVA: 0xEAC350
signed __int64 __fastcall NvAPI_I2CWriteEx(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_I2C_INFO_V2 *pI2cInfo, NV_I2C_INFO_EX *pI2cInfoEx)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_I2C_INFO_V2 *v10; // [rsp+58h] [rbp+10h]
  NV_I2C_INFO_EX *v11; // [rsp+60h] [rbp+18h]

  v11 = pI2cInfoEx;
  v10 = pI2cInfo;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_223 = 0i64;
  if ( !fp_223 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_223 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x283AC65Au);
  if ( !fp_223 )
    return 4294967293i64;
  v4 = fp_223;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x283AC65Au, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *, NV_I2C_INFO_EX *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x283AC65Au, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6502
// RVA: 0xEAC490
signed __int64 __fastcall NvAPI_I2CReadEx(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_I2C_INFO_V2 *pI2cInfo, NV_I2C_INFO_EX *pI2cInfoEx)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_I2C_INFO_V2 *v10; // [rsp+58h] [rbp+10h]
  NV_I2C_INFO_EX *v11; // [rsp+60h] [rbp+18h]

  v11 = pI2cInfoEx;
  v10 = pI2cInfo;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_224 = 0i64;
  if ( !fp_224 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_224 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4D7B0709u);
  if ( !fp_224 )
    return 4294967293i64;
  v4 = fp_224;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4D7B0709u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_I2C_INFO_V2 *, NV_I2C_INFO_EX *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4D7B0709u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6527
// RVA: 0xEAC5D0
signed __int64 __fastcall NvAPI_GPU_GetPowerMizerInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_PWR_SOURCE_INFO powerSourceInfo, _NV_SELECT_INFO select, _NV_LEVEL_INFO *pLevelInfo)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  _NV_PWR_SOURCE_INFO v11; // [rsp+58h] [rbp+10h]
  _NV_SELECT_INFO v12; // [rsp+60h] [rbp+18h]
  _NV_LEVEL_INFO *v13; // [rsp+68h] [rbp+20h]

  v13 = pLevelInfo;
  v12 = select;
  v11 = powerSourceInfo;
  v10 = hPhysicalGpu;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_225 = 0i64;
  if ( !fp_225 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_225 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x76BFA16Bu);
  if ( !fp_225 )
    return 4294967293i64;
  v5 = fp_225;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x76BFA16Bu, &v7);
  v8 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD, _NV_LEVEL_INFO *))v5)(
         v10,
         (unsigned int)v11,
         (unsigned int)v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x76BFA16Bu, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 6552
// RVA: 0xEAC710
signed __int64 __fastcall NvAPI_GPU_SetPowerMizerInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, _NV_PWR_SOURCE_INFO powerSourceInfo, _NV_SELECT_INFO select, _NV_LEVEL_INFO levelInfo)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  _NV_PWR_SOURCE_INFO v11; // [rsp+58h] [rbp+10h]
  _NV_SELECT_INFO v12; // [rsp+60h] [rbp+18h]
  _NV_LEVEL_INFO v13; // [rsp+68h] [rbp+20h]

  v13 = levelInfo;
  v12 = select;
  v11 = powerSourceInfo;
  v10 = hPhysicalGpu;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_226 = 0i64;
  if ( !fp_226 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_226 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x50016C78u);
  if ( !fp_226 )
    return 4294967293i64;
  v5 = fp_226;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x50016C78u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD, _QWORD))v5)(
         v10,
         (unsigned int)v11,
         (unsigned int)v12,
         (unsigned int)v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x50016C78u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 6577
// RVA: 0xEAC850
signed __int64 __fastcall NvAPI_GPU_GetVoltageDomainsStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_VOLTAGE_DOMAINS_STATUS_V1 *pVoltageDomainsStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_VOLTAGE_DOMAINS_STATUS_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pVoltageDomainsStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_227 = 0i64;
  if ( !fp_227 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_227 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC16C7E2C);
  if ( !fp_227 )
    return 4294967293i64;
  v3 = fp_227;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC16C7E2C, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_VOLTAGE_DOMAINS_STATUS_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC16C7E2C, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6602
// RVA: 0xEAC980
signed __int64 __fastcall NvAPI_GPU_ClientPowerTopologyGetInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_CLIENT_POWER_TOPOLOGY_INFO_V1 *pClientPowerTopologyInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_CLIENT_POWER_TOPOLOGY_INFO_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pClientPowerTopologyInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_228 = 0i64;
  if ( !fp_228 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_228 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA4DFD3F2);
  if ( !fp_228 )
    return 4294967293i64;
  v3 = fp_228;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA4DFD3F2, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_TOPOLOGY_INFO_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA4DFD3F2, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6627
// RVA: 0xEACAB0
signed __int64 __fastcall NvAPI_GPU_ClientPowerTopologyGetStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_CLIENT_POWER_TOPOLOGY_STATUS_V1 *pClientPowerTopologyStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_CLIENT_POWER_TOPOLOGY_STATUS_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pClientPowerTopologyStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_229 = 0i64;
  if ( !fp_229 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_229 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEDCF624E);
  if ( !fp_229 )
    return 4294967293i64;
  v3 = fp_229;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEDCF624E, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_TOPOLOGY_STATUS_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEDCF624E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6652
// RVA: 0xEACBE0
signed __int64 __fastcall NvAPI_GPU_ClientPowerPoliciesGetInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_CLIENT_POWER_POLICIES_INFO_V1 *pClientPowerPoliciesInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_CLIENT_POWER_POLICIES_INFO_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pClientPowerPoliciesInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_230 = 0i64;
  if ( !fp_230 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_230 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x34206D86u);
  if ( !fp_230 )
    return 4294967293i64;
  v3 = fp_230;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x34206D86u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_POLICIES_INFO_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x34206D86u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6677
// RVA: 0xEACD10
signed __int64 __fastcall NvAPI_GPU_ClientPowerPoliciesGetStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *pClientPowerPoliciesStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pClientPowerPoliciesStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_231 = 0i64;
  if ( !fp_231 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_231 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x70916171u);
  if ( !fp_231 )
    return 4294967293i64;
  v3 = fp_231;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x70916171u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x70916171u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6702
// RVA: 0xEACE40
signed __int64 __fastcall NvAPI_GPU_ClientPowerPoliciesSetStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *pClientPowerPoliciesStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pClientPowerPoliciesStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_232 = 0i64;
  if ( !fp_232 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_232 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAD95F5ED);
  if ( !fp_232 )
    return 4294967293i64;
  v3 = fp_232;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAD95F5ED, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_CLIENT_POWER_POLICIES_STATUS_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAD95F5ED, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 6727
// RVA: 0xEACF70
signed __int64 __fastcall NvAPI_GPU_WorkstationFeatureSetup(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int featureEnableMask, unsigned int featureDisableMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = featureDisableMask;
  v10 = featureEnableMask;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_233 = 0i64;
  if ( !fp_233 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_233 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6C1F3FE4u);
  if ( !fp_233 )
    return 4294967293i64;
  v4 = fp_233;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6C1F3FE4u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6C1F3FE4u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6752
// RVA: 0xEAD0A0
signed __int64 __fastcall NvAPI_SYS_GetChipSetInfo(NV_CHIPSET_INFO_v4 *pChipSetInfo)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_CHIPSET_INFO_v4 *v7; // [rsp+50h] [rbp+8h]

  v7 = pChipSetInfo;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_234 = 0i64;
  if ( !fp_234 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_234 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x53DABBCAu);
  if ( !fp_234 )
    return 4294967293i64;
  v2 = fp_234;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x53DABBCAu, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_CHIPSET_INFO_v4 *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x53DABBCAu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 6777
// RVA: 0xEAD1C0
signed __int64 __fastcall NvAPI_SYS_GetLidAndDockInfo(NV_LID_DOCK_PARAMS *pLidAndDock)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_LID_DOCK_PARAMS *v7; // [rsp+50h] [rbp+8h]

  v7 = pLidAndDock;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_235 = 0i64;
  if ( !fp_235 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_235 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDA14D8A);
  if ( !fp_235 )
    return 4294967293i64;
  v2 = fp_235;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDA14D8A, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_LID_DOCK_PARAMS *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDA14D8A, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 6802
// RVA: 0xEAD2E0
signed __int64 __fastcall NvAPI_OGL_ExpertModeSet(unsigned int expertDetailLevel, unsigned int expertReportMask, unsigned int expertOutputMask, void (__fastcall *expertCallback)(unsigned int, unsigned int, unsigned int, int, const char *))
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  void (__fastcall *v13)(unsigned int, unsigned int, unsigned int, int, const char *); // [rsp+68h] [rbp+20h]

  v13 = expertCallback;
  v12 = expertOutputMask;
  v11 = expertReportMask;
  v10 = expertDetailLevel;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_236 = 0i64;
  if ( !fp_236 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_236 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3805EF7Au);
  if ( !fp_236 )
    return 4294967293i64;
  v5 = fp_236;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3805EF7Au, &v7);
  v8 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD, void (__fastcall *)(unsigned int, unsigned int, unsigned int, int, const char *)))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3805EF7Au, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 6827
// RVA: 0xEAD420
signed __int64 __fastcall NvAPI_OGL_ExpertModeGet(unsigned int *pExpertDetailLevel, unsigned int *pExpertReportMask, unsigned int *pExpertOutputMask, void (__fastcall **pExpertCallback)(unsigned int, unsigned int, unsigned int, int, const char *))
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  void (__fastcall **v13)(unsigned int, unsigned int, unsigned int, int, const char *); // [rsp+68h] [rbp+20h]

  v13 = pExpertCallback;
  v12 = pExpertOutputMask;
  v11 = pExpertReportMask;
  v10 = pExpertDetailLevel;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_237 = 0i64;
  if ( !fp_237 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_237 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x22ED9516u);
  if ( !fp_237 )
    return 4294967293i64;
  v5 = fp_237;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x22ED9516u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, void (__fastcall **)(unsigned int, unsigned int, unsigned int, int, const char *)))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x22ED9516u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 6852
// RVA: 0xEAD560
signed __int64 __fastcall NvAPI_OGL_ExpertModeDefaultsSet(unsigned int expertDetailLevel, unsigned int expertReportMask, unsigned int expertOutputMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = expertOutputMask;
  v10 = expertReportMask;
  v9 = expertDetailLevel;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_238 = 0i64;
  if ( !fp_238 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_238 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB47A657E);
  if ( !fp_238 )
    return 4294967293i64;
  v4 = fp_238;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB47A657E, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB47A657E, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6877
// RVA: 0xEAD690
signed __int64 __fastcall NvAPI_OGL_ExpertModeDefaultsGet(unsigned int *pExpertDetailLevel, unsigned int *pExpertReportMask, unsigned int *pExpertOutputMask)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pExpertOutputMask;
  v10 = pExpertReportMask;
  v9 = pExpertDetailLevel;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_239 = 0i64;
  if ( !fp_239 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_239 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE921F12);
  if ( !fp_239 )
    return 4294967293i64;
  v4 = fp_239;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE921F12, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE921F12, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6902
// RVA: 0xEAD7D0
signed __int64 __fastcall NvAPI_SetDisplaySettings(NvDisplayHandle__ *hNvDisplay, NV_DISP_PATH_V2 *paths, unsigned int pathCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_DISP_PATH_V2 *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = pathCount;
  v10 = paths;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_240 = 0i64;
  if ( !fp_240 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_240 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE04F3D86);
  if ( !fp_240 )
    return 4294967293i64;
  v4 = fp_240;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE04F3D86, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISP_PATH_V2 *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE04F3D86, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6927
// RVA: 0xEAD910
signed __int64 __fastcall NvAPI_GetDisplaySettings(NvDisplayHandle__ *hNvDisplay, NV_DISP_PATH_V2 *pPaths, unsigned int *pPathCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_DISP_PATH_V2 *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pPathCount;
  v10 = pPaths;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_241 = 0i64;
  if ( !fp_241 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_241 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDC27D5D4);
  if ( !fp_241 )
    return 4294967293i64;
  v4 = fp_241;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDC27D5D4, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISP_PATH_V2 *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDC27D5D4, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 6952
// RVA: 0xEADA50
signed __int64 __fastcall NvAPI_GetTiming(NvDisplayHandle__ *hNvDisplay, unsigned int width, unsigned int height, float rr, NV_TIMING_FLAG *flag)
{
  __int64 (__fastcall *v6)(); // [rsp+40h] [rbp-48h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-40h]
  unsigned __int64 v8; // [rsp+50h] [rbp-38h]
  _NvAPI_Status v9; // [rsp+58h] [rbp-30h]
  int v10; // [rsp+5Ch] [rbp-2Ch]
  char v11; // [rsp+60h] [rbp-28h]
  NvDisplayHandle__ *v12; // [rsp+90h] [rbp+8h]
  unsigned int v13; // [rsp+98h] [rbp+10h]
  unsigned int v14; // [rsp+A0h] [rbp+18h]

  v14 = height;
  v13 = width;
  v12 = hNvDisplay;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_242 = 0i64;
  if ( !fp_242 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_242 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAFC4833E);
  if ( !fp_242 )
    return 4294967293i64;
  v6 = fp_242;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAFC4833E, &v8);
  qmemcpy(&v11, flag, 0xCui64);
  v9 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v6)(v12, v13, v14);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAFC4833E, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 6977
// RVA: 0xEADBE0
signed __int64 __fastcall NvAPI_DISP_GetMonitorCapabilities(unsigned int displayId, _NV_MONITOR_CAPABILITIES *pMonitorCapabilities)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_MONITOR_CAPABILITIES *v9; // [rsp+58h] [rbp+10h]

  v9 = pMonitorCapabilities;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_243 = 0i64;
  if ( !fp_243 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_243 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3B05C7E1u);
  if ( !fp_243 )
    return 4294967293i64;
  v3 = fp_243;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3B05C7E1u, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _NV_MONITOR_CAPABILITIES *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3B05C7E1u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7002
// RVA: 0xEADD10
signed __int64 __fastcall NvAPI_EnumCustomDisplay(NvDisplayHandle__ *hNvDisplay, unsigned int index, unsigned int outputId, NV_CUSTOM_DISPLAY *pC)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  NV_CUSTOM_DISPLAY *v13; // [rsp+68h] [rbp+20h]

  v13 = pC;
  v12 = outputId;
  v11 = index;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_244 = 0i64;
  if ( !fp_244 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_244 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x42892957u);
  if ( !fp_244 )
    return 4294967293i64;
  v5 = fp_244;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x42892957u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_CUSTOM_DISPLAY *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x42892957u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 7027
// RVA: 0xEADE50
signed __int64 __fastcall NvAPI_TryCustomDisplay(NvDisplayHandle__ *hNvDisplay, unsigned int *pDispOutputId, NV_CUSTOM_DISPLAY *pCustDisp, unsigned int count, unsigned int hwModeSetOnly)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  NvDisplayHandle__ *v11; // [rsp+60h] [rbp+8h]
  unsigned int *v12; // [rsp+68h] [rbp+10h]
  NV_CUSTOM_DISPLAY *v13; // [rsp+70h] [rbp+18h]
  unsigned int v14; // [rsp+78h] [rbp+20h]

  v14 = count;
  v13 = pCustDisp;
  v12 = pDispOutputId;
  v11 = hNvDisplay;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_245 = 0i64;
  if ( !fp_245 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_245 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBF6C1762);
  if ( !fp_245 )
    return 4294967293i64;
  v6 = fp_245;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBF6C1762, &v8);
  v9 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *, NV_CUSTOM_DISPLAY *, _QWORD, unsigned int))v6)(
         v11,
         v12,
         v13,
         v14,
         hwModeSetOnly);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBF6C1762, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 7052
// RVA: 0xEADFA0
signed __int64 __fastcall NvAPI_RevertCustomDisplayTrial(NvDisplayHandle__ *hNvDisplay)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hNvDisplay;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_246 = 0i64;
  if ( !fp_246 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_246 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x854BA405);
  if ( !fp_246 )
    return 4294967293i64;
  v2 = fp_246;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x854BA405, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x854BA405, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 7077
// RVA: 0xEAE0C0
signed __int64 __fastcall NvAPI_DeleteCustomDisplay(NvDisplayHandle__ *hNvDisplay, unsigned int displayOutputId, unsigned int index)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = index;
  v10 = displayOutputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_247 = 0i64;
  if ( !fp_247 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_247 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE7CB998D);
  if ( !fp_247 )
    return 4294967293i64;
  v4 = fp_247;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE7CB998D, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE7CB998D, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7102
// RVA: 0xEAE1F0
signed __int64 __fastcall NvAPI_SaveCustomDisplay(NvDisplayHandle__ *hNvDisplay, unsigned int isThisOutputIdOnly, unsigned int isThisMonitorIdOnly)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = isThisMonitorIdOnly;
  v10 = isThisOutputIdOnly;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_248 = 0i64;
  if ( !fp_248 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_248 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA9062C78);
  if ( !fp_248 )
    return 4294967293i64;
  v4 = fp_248;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA9062C78, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA9062C78, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7127
// RVA: 0xEAE320
signed __int64 __fastcall NvAPI_QueryUnderscanCap(NvDisplayHandle__ *hNvDisplay, unsigned int displayOutputId, NV_UNDERSCAN_CAP *cap)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_UNDERSCAN_CAP *v11; // [rsp+60h] [rbp+18h]

  v11 = cap;
  v10 = displayOutputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_249 = 0i64;
  if ( !fp_249 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_249 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x61D7B624u);
  if ( !fp_249 )
    return 4294967293i64;
  v4 = fp_249;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x61D7B624u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_UNDERSCAN_CAP *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x61D7B624u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7152
// RVA: 0xEAE450
signed __int64 __fastcall NvAPI_EnumUnderscanConfig(NvDisplayHandle__ *hNvDisplay, unsigned int displayOutputId, unsigned int index, NV_UNDERSCAN_CONFIG *config)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  NV_UNDERSCAN_CONFIG *v13; // [rsp+68h] [rbp+20h]

  v13 = config;
  v12 = index;
  v11 = displayOutputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_250 = 0i64;
  if ( !fp_250 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_250 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4144111Au);
  if ( !fp_250 )
    return 4294967293i64;
  v5 = fp_250;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4144111Au, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD, NV_UNDERSCAN_CONFIG *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4144111Au, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 7177
// RVA: 0xEAE590
signed __int64 __fastcall NvAPI_DeleteUnderscanConfig(NvDisplayHandle__ *hNvDisplay, unsigned int displayOutputId, unsigned int index)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = index;
  v10 = displayOutputId;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_251 = 0i64;
  if ( !fp_251 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_251 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF98854C8);
  if ( !fp_251 )
    return 4294967293i64;
  v4 = fp_251;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF98854C8, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF98854C8, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7202
// RVA: 0xEAE6C0
signed __int64 __fastcall NvAPI_SetUnderscanConfig(NvDisplayHandle__ *hNvDisplay, unsigned int displayOutputId, NV_UNDERSCAN_CONFIG *config, unsigned int setDeferred)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  NV_UNDERSCAN_CONFIG *v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = setDeferred;
  v12 = config;
  v11 = displayOutputId;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_252 = 0i64;
  if ( !fp_252 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_252 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3EFADA1Du);
  if ( !fp_252 )
    return 4294967293i64;
  v5 = fp_252;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3EFADA1Du, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD, NV_UNDERSCAN_CONFIG *, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3EFADA1Du, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 7227
// RVA: 0xEAE800
signed __int64 __fastcall NvAPI_GetDisplayFeatureConfig(NvDisplayHandle__ *hNvDisplay, _NV_DISPLAY_FEATURE *pFeature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_DISPLAY_FEATURE *v9; // [rsp+58h] [rbp+10h]

  v9 = pFeature;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_253 = 0i64;
  if ( !fp_253 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_253 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8E985CCD);
  if ( !fp_253 )
    return 4294967293i64;
  v3 = fp_253;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8E985CCD, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_DISPLAY_FEATURE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8E985CCD, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7252
// RVA: 0xEAE930
signed __int64 __fastcall NvAPI_SetDisplayFeatureConfig(NvDisplayHandle__ *hNvDisplay, _NV_DISPLAY_FEATURE feature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_DISPLAY_FEATURE v9; // [rsp+58h] [rbp+10h]

  v9 = feature;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_254 = 0i64;
  if ( !fp_254 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_254 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF36A668D);
  if ( !fp_254 )
    return 4294967293i64;
  v3 = fp_254;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF36A668D, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD))v3)(v8, *(unsigned int *)&v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF36A668D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7277
// RVA: 0xEAEA60
signed __int64 __fastcall NvAPI_GetDisplayFeatureConfigDefaults(NvDisplayHandle__ *hNvDisplay, _NV_DISPLAY_FEATURE *pFeature)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_DISPLAY_FEATURE *v9; // [rsp+58h] [rbp+10h]

  v9 = pFeature;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_255 = 0i64;
  if ( !fp_255 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_255 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5F4D01u);
  if ( !fp_255 )
    return 4294967293i64;
  v3 = fp_255;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5F4D01u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_DISPLAY_FEATURE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5F4D01u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7302
// RVA: 0xEAEB90
signed __int64 __fastcall NvAPI_SetView(NvDisplayHandle__ *hNvDisplay, NV_VIEW_TARGET_INFO *pTargetInfo, _NV_TARGET_VIEW_MODE targetView)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_VIEW_TARGET_INFO *v10; // [rsp+58h] [rbp+10h]
  _NV_TARGET_VIEW_MODE v11; // [rsp+60h] [rbp+18h]

  v11 = targetView;
  v10 = pTargetInfo;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_256 = 0i64;
  if ( !fp_256 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_256 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x957D7B6u);
  if ( !fp_256 )
    return 4294967293i64;
  v4 = fp_256;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x957D7B6u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_VIEW_TARGET_INFO *, _QWORD))v4)(v9, v10, (unsigned int)v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x957D7B6u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7327
// RVA: 0xEAECD0
signed __int64 __fastcall NvAPI_GetView(NvDisplayHandle__ *hNvDisplay, NV_VIEW_TARGET_INFO *pTargets, unsigned int *pTargetMaskCount, _NV_TARGET_VIEW_MODE *pTargetView)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  NV_VIEW_TARGET_INFO *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  _NV_TARGET_VIEW_MODE *v13; // [rsp+68h] [rbp+20h]

  v13 = pTargetView;
  v12 = pTargetMaskCount;
  v11 = pTargets;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_257 = 0i64;
  if ( !fp_257 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_257 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD6B99D89);
  if ( !fp_257 )
    return 4294967293i64;
  v5 = fp_257;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD6B99D89, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_VIEW_TARGET_INFO *, unsigned int *, _NV_TARGET_VIEW_MODE *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD6B99D89, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 7352
// RVA: 0xEAEE10
signed __int64 __fastcall NvAPI_SetViewEx(NvDisplayHandle__ *hNvDisplay, NV_DISPLAY_PATH_INFO *pPathInfo, _NV_TARGET_VIEW_MODE displayView)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_DISPLAY_PATH_INFO *v10; // [rsp+58h] [rbp+10h]
  _NV_TARGET_VIEW_MODE v11; // [rsp+60h] [rbp+18h]

  v11 = displayView;
  v10 = pPathInfo;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_258 = 0i64;
  if ( !fp_258 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_258 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6B89E68u);
  if ( !fp_258 )
    return 4294967293i64;
  v4 = fp_258;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6B89E68u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_PATH_INFO *, _QWORD))v4)(
         v9,
         v10,
         (unsigned int)v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6B89E68u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7377
// RVA: 0xEAEF50
signed __int64 __fastcall NvAPI_GetViewEx(NvDisplayHandle__ *hNvDisplay, NV_DISPLAY_PATH_INFO *pPathInfo, unsigned int *pPathCount, _NV_TARGET_VIEW_MODE *pTargetViewMode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v10; // [rsp+50h] [rbp+8h]
  NV_DISPLAY_PATH_INFO *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  _NV_TARGET_VIEW_MODE *v13; // [rsp+68h] [rbp+20h]

  v13 = pTargetViewMode;
  v12 = pPathCount;
  v11 = pPathInfo;
  v10 = hNvDisplay;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_259 = 0i64;
  if ( !fp_259 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_259 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDBBC0AF4);
  if ( !fp_259 )
    return 4294967293i64;
  v5 = fp_259;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDBBC0AF4, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_DISPLAY_PATH_INFO *, unsigned int *, _NV_TARGET_VIEW_MODE *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDBBC0AF4, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 7402
// RVA: 0xEAF090
signed __int64 __fastcall NvAPI_GetSupportedViews(NvDisplayHandle__ *hNvDisplay, _NV_TARGET_VIEW_MODE *pTargetViews, unsigned int *pViewCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  _NV_TARGET_VIEW_MODE *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pViewCount;
  v10 = pTargetViews;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_260 = 0i64;
  if ( !fp_260 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_260 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x66FB7FC0u);
  if ( !fp_260 )
    return 4294967293i64;
  v4 = fp_260;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x66FB7FC0u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_TARGET_VIEW_MODE *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x66FB7FC0u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7427
// RVA: 0xEAF1D0
signed __int64 __fastcall NvAPI_GetHDCPLinkParameters(NvDisplayHandle__ *hNvDisplay, NV_HDCP_INFO *pNvHdcpInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_HDCP_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pNvHdcpInfo;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_261 = 0i64;
  if ( !fp_261 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_261 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB3BB0772);
  if ( !fp_261 )
    return 4294967293i64;
  v3 = fp_261;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB3BB0772, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, NV_HDCP_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB3BB0772, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7452
// RVA: 0xEAF300
signed __int64 __fastcall NvAPI_Disp_DpAuxChannelControl(NvDisplayHandle__ *hNvDisplay, _NV_DPCD_PARAMS *pDpcdParams, unsigned int reserved)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v9; // [rsp+50h] [rbp+8h]
  _NV_DPCD_PARAMS *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = reserved;
  v10 = pDpcdParams;
  v9 = hNvDisplay;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_262 = 0i64;
  if ( !fp_262 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_262 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8EB56969);
  if ( !fp_262 )
    return 4294967293i64;
  v4 = fp_262;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8EB56969, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_DPCD_PARAMS *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8EB56969, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7477
// RVA: 0xEAF440
signed __int64 __fastcall NvAPI_SetHybridMode(_NV_HYBRID_MODE mode)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_HYBRID_MODE v7; // [rsp+50h] [rbp+8h]

  v7 = mode;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_263 = 0i64;
  if ( !fp_263 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_263 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFB22D656);
  if ( !fp_263 )
    return 4294967293i64;
  v2 = fp_263;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFB22D656, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)((unsigned int)v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFB22D656, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 7502
// RVA: 0xEAF560
signed __int64 __fastcall NvAPI_GetHybridMode(_NV_HYBRID_MODE *pMode)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_HYBRID_MODE *v7; // [rsp+50h] [rbp+8h]

  v7 = pMode;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_264 = 0i64;
  if ( !fp_264 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_264 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE23B68C1);
  if ( !fp_264 )
    return 4294967293i64;
  v2 = fp_264;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE23B68C1, &v4);
  v5 = ((unsigned int (__fastcall *)(_NV_HYBRID_MODE *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE23B68C1, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 7527
// RVA: 0xEAF680
signed __int64 __fastcall NvAPI_Coproc_GetCoprocStatus(unsigned int *pCoprocStatus, NV_COPROC_STATE *pCoprocState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  NV_COPROC_STATE *v9; // [rsp+58h] [rbp+10h]

  v9 = pCoprocState;
  v8 = pCoprocStatus;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_265 = 0i64;
  if ( !fp_265 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_265 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1EFC3957u);
  if ( !fp_265 )
    return 4294967293i64;
  v3 = fp_265;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1EFC3957u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, NV_COPROC_STATE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1EFC3957u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7552
// RVA: 0xEAF7B0
signed __int64 __fastcall NvAPI_Coproc_SetCoprocInfoFlagsEx(NV_COPROC_FLAGS_EX *coprocInfoExFlags)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_COPROC_FLAGS_EX *v7; // [rsp+50h] [rbp+8h]

  v7 = coprocInfoExFlags;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_266 = 0i64;
  if ( !fp_266 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_266 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF4C863AC);
  if ( !fp_266 )
    return 4294967293i64;
  v2 = fp_266;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF4C863AC, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_COPROC_FLAGS_EX *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF4C863AC, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 7577
// RVA: 0xEAF8D0
signed __int64 __fastcall NvAPI_Coproc_GetCoprocInfoFlagsEx(NV_COPROC_FLAGS_EX *coprocInfoExFlags)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_COPROC_FLAGS_EX *v7; // [rsp+50h] [rbp+8h]

  v7 = coprocInfoExFlags;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_267 = 0i64;
  if ( !fp_267 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_267 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x69A9874Du);
  if ( !fp_267 )
    return 4294967293i64;
  v2 = fp_267;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x69A9874Du, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_COPROC_FLAGS_EX *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x69A9874Du, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 7602
// RVA: 0xEAF9F0
signed __int64 __fastcall NvAPI_Coproc_NotifyCoprocPowerState(unsigned int IsSafetoPowerOff, unsigned __int64 SequenceNumber, unsigned int *pStatus)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  unsigned __int64 v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pStatus;
  v10 = SequenceNumber;
  v9 = IsSafetoPowerOff;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_268 = 0i64;
  if ( !fp_268 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_268 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCADCB956);
  if ( !fp_268 )
    return 4294967293i64;
  v4 = fp_268;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCADCB956, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, unsigned __int64, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCADCB956, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 7627
// RVA: 0xEAFB20
signed __int64 __fastcall NvAPI_Coproc_GetApplicationCoprocInfo(NV_COPROC_APP_INFO *pCoprocAppInfo)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_COPROC_APP_INFO *v7; // [rsp+50h] [rbp+8h]

  v7 = pCoprocAppInfo;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_269 = 0i64;
  if ( !fp_269 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_269 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x79232685u);
  if ( !fp_269 )
    return 4294967293i64;
  v2 = fp_269;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x79232685u, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_COPROC_APP_INFO *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x79232685u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 7652
// RVA: 0xEAFC40
signed __int64 __fastcall NvAPI_GetVideoState(NvDisplayHandle__ *hNvDisplay, _NVAPI_GET_VIDEO_STATE_COMPONENT *pGetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_GET_VIDEO_STATE_COMPONENT *v9; // [rsp+58h] [rbp+10h]

  v9 = pGetVidStateComp;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_270 = 0i64;
  if ( !fp_270 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_270 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1C5659CDu);
  if ( !fp_270 )
    return 4294967293i64;
  v3 = fp_270;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1C5659CDu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NVAPI_GET_VIDEO_STATE_COMPONENT *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1C5659CDu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7677
// RVA: 0xEAFD70
signed __int64 __fastcall NvAPI_SetVideoState(NvDisplayHandle__ *hNvDisplay, _NVAPI_SET_VIDEO_STATE_COMPONENT *pSetVidStateComp)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_SET_VIDEO_STATE_COMPONENT *v9; // [rsp+58h] [rbp+10h]

  v9 = pSetVidStateComp;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_271 = 0i64;
  if ( !fp_271 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_271 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x54FE75Au);
  if ( !fp_271 )
    return 4294967293i64;
  v3 = fp_271;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x54FE75Au, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NVAPI_SET_VIDEO_STATE_COMPONENT *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x54FE75Au, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7702
// RVA: 0xEAFEA0
signed __int64 __fastcall NvAPI_SetFrameRateNotify(NvDisplayHandle__ *hNvDisplay, _NVAPI_FRAME_RATE_NOTIFY_INFO *pFRNotifyInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_FRAME_RATE_NOTIFY_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pFRNotifyInfo;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_272 = 0i64;
  if ( !fp_272 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_272 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x18919887u);
  if ( !fp_272 )
    return 4294967293i64;
  v3 = fp_272;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x18919887u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NVAPI_FRAME_RATE_NOTIFY_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x18919887u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7727
// RVA: 0xEAFFD0
signed __int64 __fastcall NvAPI_SetPVExtName(NvDisplayHandle__ *hNvDisplay, const char *szDllName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  const char *v9; // [rsp+58h] [rbp+10h]

  v9 = szDllName;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_273 = 0i64;
  if ( !fp_273 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_273 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4FEEB498u);
  if ( !fp_273 )
    return 4294967293i64;
  v3 = fp_273;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4FEEB498u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, const char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4FEEB498u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7752
// RVA: 0xEB0100
signed __int64 __fastcall NvAPI_GetPVExtName(NvDisplayHandle__ *hNvDisplay, char *szDllName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = szDllName;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_274 = 0i64;
  if ( !fp_274 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_274 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2F5B08E0u);
  if ( !fp_274 )
    return 4294967293i64;
  v3 = fp_274;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2F5B08E0u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2F5B08E0u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7777
// RVA: 0xEB0230
signed __int64 __fastcall NvAPI_SetPVExtProfile(NvDisplayHandle__ *hNvDisplay, unsigned int dwProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = dwProfile;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_275 = 0i64;
  if ( !fp_275 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_275 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8354A8F4);
  if ( !fp_275 )
    return 4294967293i64;
  v3 = fp_275;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8354A8F4, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8354A8F4, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7802
// RVA: 0xEB0360
signed __int64 __fastcall NvAPI_GetPVExtProfile(NvDisplayHandle__ *hNvDisplay, unsigned int *pProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pProfile;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_276 = 0i64;
  if ( !fp_276 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_276 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1B1B9A16u);
  if ( !fp_276 )
    return 4294967293i64;
  v3 = fp_276;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1B1B9A16u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1B1B9A16u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7827
// RVA: 0xEB0490
signed __int64 __fastcall NvAPI_VideoSetStereoInfo(NvDisplayHandle__ *hNvDisplay, _NV_VIDEO_STEREO_INFO *pStereoInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_VIDEO_STEREO_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pStereoInfo;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_277 = 0i64;
  if ( !fp_277 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_277 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x97063269);
  if ( !fp_277 )
    return 4294967293i64;
  v3 = fp_277;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x97063269, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_VIDEO_STEREO_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x97063269, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7852
// RVA: 0xEB05C0
signed __int64 __fastcall NvAPI_VideoGetStereoInfo(NvDisplayHandle__ *hNvDisplay, _NV_VIDEO_STEREO_INFO *pStereoInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDisplayHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NV_VIDEO_STEREO_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pStereoInfo;
  v8 = hNvDisplay;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_278 = 0i64;
  if ( !fp_278 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_278 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8E1F8CFE);
  if ( !fp_278 )
    return 4294967293i64;
  v3 = fp_278;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8E1F8CFE, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDisplayHandle__ *, _NV_VIDEO_STEREO_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8E1F8CFE, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7877
// RVA: 0xEB06F0
signed __int64 __fastcall NvAPI_Mosaic_GetSupportedTopoInfo(NV_MOSAIC_SUPPORTED_TOPO_INFO *pSupportedTopoInfo, NV_MOSAIC_TOPO_TYPE type)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_SUPPORTED_TOPO_INFO *v8; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_TOPO_TYPE v9; // [rsp+58h] [rbp+10h]

  v9 = type;
  v8 = pSupportedTopoInfo;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_279 = 0i64;
  if ( !fp_279 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_279 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFDB63C81);
  if ( !fp_279 )
    return 4294967293i64;
  v3 = fp_279;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFDB63C81, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_MOSAIC_SUPPORTED_TOPO_INFO *, _QWORD))v3)(v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFDB63C81, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7902
// RVA: 0xEB0820
signed __int64 __fastcall NvAPI_Mosaic_GetTopoGroup(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_TOPO_GROUP *pTopoGroup)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_TOPO_BRIEF *v8; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_TOPO_GROUP *v9; // [rsp+58h] [rbp+10h]

  v9 = pTopoGroup;
  v8 = pTopoBrief;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_280 = 0i64;
  if ( !fp_280 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_280 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCB89381D);
  if ( !fp_280 )
    return 4294967293i64;
  v3 = fp_280;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCB89381D, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_TOPO_GROUP *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCB89381D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 7927
// RVA: 0xEB0950
signed __int64 __fastcall NvAPI_Mosaic_GetOverlapLimits(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting, int *pMinOverlapX, int *pMaxOverlapX, int *pMinOverlapY, int *pMaxOverlapY)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  NV_MOSAIC_TOPO_BRIEF *v12; // [rsp+60h] [rbp+8h]
  NV_MOSAIC_DISPLAY_SETTING *v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pMaxOverlapX;
  v14 = pMinOverlapX;
  v13 = pDisplaySetting;
  v12 = pTopoBrief;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_281 = 0i64;
  if ( !fp_281 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_281 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x989685F0);
  if ( !fp_281 )
    return 4294967293i64;
  v7 = fp_281;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x989685F0, &v9);
  v10 = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_DISPLAY_SETTING *, int *, int *, int *, int *))v7)(
          v12,
          v13,
          v14,
          v15,
          pMinOverlapY,
          pMaxOverlapY);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x989685F0, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 7952
// RVA: 0xEB0AB0
signed __int64 __fastcall NvAPI_Mosaic_SetCurrentTopo(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting, int overlapX, int overlapY, unsigned int enable)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  NV_MOSAIC_TOPO_BRIEF *v11; // [rsp+60h] [rbp+8h]
  NV_MOSAIC_DISPLAY_SETTING *v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  unsigned int v14; // [rsp+78h] [rbp+20h]

  v14 = overlapY;
  v13 = overlapX;
  v12 = pDisplaySetting;
  v11 = pTopoBrief;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_282 = 0i64;
  if ( !fp_282 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_282 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9B542831);
  if ( !fp_282 )
    return 4294967293i64;
  v6 = fp_282;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9B542831, &v8);
  v9 = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_DISPLAY_SETTING *, _QWORD, _QWORD, unsigned int))v6)(
         v11,
         v12,
         v13,
         v14,
         enable);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9B542831, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 7977
// RVA: 0xEB0C00
signed __int64 __fastcall NvAPI_Mosaic_GetCurrentTopo(NV_MOSAIC_TOPO_BRIEF *pTopoBrief, NV_MOSAIC_DISPLAY_SETTING *pDisplaySetting, int *pOverlapX, int *pOverlapY)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_TOPO_BRIEF *v10; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_DISPLAY_SETTING *v11; // [rsp+58h] [rbp+10h]
  int *v12; // [rsp+60h] [rbp+18h]
  int *v13; // [rsp+68h] [rbp+20h]

  v13 = pOverlapY;
  v12 = pOverlapX;
  v11 = pDisplaySetting;
  v10 = pTopoBrief;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_283 = 0i64;
  if ( !fp_283 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_283 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEC32944E);
  if ( !fp_283 )
    return 4294967293i64;
  v5 = fp_283;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEC32944E, &v7);
  v8 = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPO_BRIEF *, NV_MOSAIC_DISPLAY_SETTING *, int *, int *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEC32944E, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 8002
// RVA: 0xEB0D40
signed __int64 __fastcall NvAPI_Mosaic_EnableCurrentTopo(unsigned int enable)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int v7; // [rsp+50h] [rbp+8h]

  v7 = enable;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_284 = 0i64;
  if ( !fp_284 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_284 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F1AA66Cu);
  if ( !fp_284 )
    return 4294967293i64;
  v2 = fp_284;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F1AA66Cu, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F1AA66Cu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8027
// RVA: 0xEB0E60
signed __int64 __fastcall NvAPI_Mosaic_SetGridTopology(NV_MOSAIC_GRID_TOPO *pGridTopology, unsigned int enable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_GRID_TOPO *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = enable;
  v8 = pGridTopology;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_285 = 0i64;
  if ( !fp_285 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_285 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3F113C77u);
  if ( !fp_285 )
    return 4294967293i64;
  v3 = fp_285;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3F113C77u, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3F113C77u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8052
// RVA: 0xEB0F90
signed __int64 __fastcall NvAPI_Mosaic_GetMosaicCapabilities(NV_GPU_TOPOLOGIES *pSliTopology, NV_MOSAIC_CAPS_V2 *pCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_GPU_TOPOLOGIES *v8; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_CAPS_V2 *v9; // [rsp+58h] [rbp+10h]

  v9 = pCaps;
  v8 = pSliTopology;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_286 = 0i64;
  if ( !fp_286 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_286 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA97071E);
  if ( !fp_286 )
    return 4294967293i64;
  v3 = fp_286;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA97071E, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, NV_MOSAIC_CAPS_V2 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA97071E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8077
// RVA: 0xEB10C0
signed __int64 __fastcall NvAPI_Mosaic_GetDisplayCapabilities(NV_MOSAIC_DISPLAY_CAPS_V2 *pDisplayCaps)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_DISPLAY_CAPS_V2 *v7; // [rsp+50h] [rbp+8h]

  v7 = pDisplayCaps;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_287 = 0i64;
  if ( !fp_287 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_287 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD58026B9);
  if ( !fp_287 )
    return 4294967293i64;
  v2 = fp_287;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD58026B9, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_MOSAIC_DISPLAY_CAPS_V2 *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD58026B9, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8102
// RVA: 0xEB11E0
signed __int64 __fastcall NvAPI_Mosaic_EnumGridTopologies(unsigned int index, unsigned int flags, NV_MOSAIC_GRID_TOPO *pGridTopology, char *bEnabled)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  NV_MOSAIC_GRID_TOPO *v12; // [rsp+60h] [rbp+18h]
  char *v13; // [rsp+68h] [rbp+20h]

  v13 = bEnabled;
  v12 = pGridTopology;
  v11 = flags;
  v10 = index;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_288 = 0i64;
  if ( !fp_288 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_288 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA3C55220);
  if ( !fp_288 )
    return 4294967293i64;
  v5 = fp_288;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA3C55220, &v7);
  v8 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, NV_MOSAIC_GRID_TOPO *, char *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA3C55220, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 8127
// RVA: 0xEB1320
signed __int64 __fastcall NvAPI_Mosaic_GetDisplayViewportsByResolution(unsigned int displayId, unsigned int srcWidth, unsigned int srcHeight, _NV_RECT *viewports, char *bezelCorrected)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  unsigned int v11; // [rsp+60h] [rbp+8h]
  unsigned int v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  _NV_RECT *v14; // [rsp+78h] [rbp+20h]

  v14 = viewports;
  v13 = srcHeight;
  v12 = srcWidth;
  v11 = displayId;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_289 = 0i64;
  if ( !fp_289 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_289 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDC6DC8D3);
  if ( !fp_289 )
    return 4294967293i64;
  v6 = fp_289;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDC6DC8D3, &v8);
  v9 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, _QWORD, _NV_RECT *, char *))v6)(v11, v12, v13, v14, bezelCorrected);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDC6DC8D3, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 8152
// RVA: 0xEB1470
signed __int64 __fastcall NvAPI_Mosaic_GetMosaicViewports(NV_MOSAIC_GRID_TOPO *pGridTopology, unsigned int baseWidth, unsigned int baseHeight, char bezelCorrected, unsigned int *totalWidth, unsigned int *totalHeight, _NV_RECT *viewports)
{
  __int64 (__fastcall *v8)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h]
  unsigned __int64 v10; // [rsp+50h] [rbp-18h]
  _NvAPI_Status v11; // [rsp+58h] [rbp-10h]
  int v12; // [rsp+5Ch] [rbp-Ch]
  NV_MOSAIC_GRID_TOPO *v13; // [rsp+70h] [rbp+8h]
  unsigned int v14; // [rsp+78h] [rbp+10h]
  unsigned int v15; // [rsp+80h] [rbp+18h]
  unsigned __int8 v16; // [rsp+88h] [rbp+20h]

  v16 = bezelCorrected;
  v15 = baseHeight;
  v14 = baseWidth;
  v13 = pGridTopology;
  hMod = 0i64;
  v12 = 0;
  v11 = (unsigned int)GetGpuHandle(&hMod);
  if ( v11 && v11 != -14 )
    return v11;
  if ( v11 == -14 )
    fp_290 = 0i64;
  if ( !fp_290 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_290 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7EBA036u);
  if ( !fp_290 )
    return 4294967293i64;
  v8 = fp_290;
  v10 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7EBA036u, &v10);
  v11 = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD, _QWORD, _QWORD, unsigned int *, unsigned int *, _NV_RECT *))v8)(
          v13,
          v14,
          v15,
          v16,
          totalWidth,
          totalHeight,
          viewports);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7EBA036u, v10, v11);
  --g_module_numApiInUse[v12];
  return v11;
}

// File Line: 8177
// RVA: 0xEB15E0
signed __int64 __fastcall NvAPI_Mosaic_SetDisplayGrids(NV_MOSAIC_GRID_TOPO *pGridTopologies, unsigned int gridCount, unsigned int setTopoFlags)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_GRID_TOPO *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = setTopoFlags;
  v10 = gridCount;
  v9 = pGridTopologies;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_291 = 0i64;
  if ( !fp_291 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_291 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4D959A89u);
  if ( !fp_291 )
    return 4294967293i64;
  v4 = fp_291;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4D959A89u, &v6);
  v7 = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4D959A89u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 8202
// RVA: 0xEB1710
signed __int64 __fastcall NvAPI_Mosaic_ValidateDisplayGridsWithSLI(NV_GPU_TOPOLOGIES *pGpuTopologies, NV_MOSAIC_GRID_TOPO *pGridTopologies, NV_MOSAIC_DISPLAY_TOPO_STATUS *pTopoStatus, unsigned int gridCount)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NV_GPU_TOPOLOGIES *v10; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_GRID_TOPO *v11; // [rsp+58h] [rbp+10h]
  NV_MOSAIC_DISPLAY_TOPO_STATUS *v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = gridCount;
  v12 = pTopoStatus;
  v11 = pGridTopologies;
  v10 = pGpuTopologies;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_292 = 0i64;
  if ( !fp_292 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_292 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1ECFD263u);
  if ( !fp_292 )
    return 4294967293i64;
  v5 = fp_292;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1ECFD263u, &v7);
  v8 = ((unsigned int (__fastcall *)(NV_GPU_TOPOLOGIES *, NV_MOSAIC_GRID_TOPO *, NV_MOSAIC_DISPLAY_TOPO_STATUS *, _QWORD))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1ECFD263u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 8227
// RVA: 0xEB1850
signed __int64 __fastcall NvAPI_Mosaic_ValidateDisplayGrids(unsigned int setTopoFlags, NV_MOSAIC_GRID_TOPO *pGridTopologies, NV_MOSAIC_DISPLAY_TOPO_STATUS *pTopoStatus, unsigned int gridCount)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int v10; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_GRID_TOPO *v11; // [rsp+58h] [rbp+10h]
  NV_MOSAIC_DISPLAY_TOPO_STATUS *v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = gridCount;
  v12 = pTopoStatus;
  v11 = pGridTopologies;
  v10 = setTopoFlags;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_293 = 0i64;
  if ( !fp_293 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_293 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCF43903D);
  if ( !fp_293 )
    return 4294967293i64;
  v5 = fp_293;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCF43903D, &v7);
  v8 = ((unsigned int (__fastcall *)(_QWORD, NV_MOSAIC_GRID_TOPO *, NV_MOSAIC_DISPLAY_TOPO_STATUS *, _QWORD))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCF43903D, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 8252
// RVA: 0xEB1990
signed __int64 __fastcall NvAPI_Mosaic_EnumDisplayModes(NV_MOSAIC_GRID_TOPO *pGridTopology, NV_MOSAIC_DISPLAY_SETTING *pDisplaySettings, unsigned int *pDisplayCount)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_GRID_TOPO *v9; // [rsp+50h] [rbp+8h]
  NV_MOSAIC_DISPLAY_SETTING *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pDisplayCount;
  v10 = pDisplaySettings;
  v9 = pGridTopology;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_294 = 0i64;
  if ( !fp_294 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_294 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x78DB97D7u);
  if ( !fp_294 )
    return 4294967293i64;
  v4 = fp_294;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x78DB97D7u, &v6);
  v7 = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, NV_MOSAIC_DISPLAY_SETTING *, unsigned int *))v4)(
         v9,
         v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x78DB97D7u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 8277
// RVA: 0xEB1AD0
signed __int64 __fastcall NvAPI_Mosaic_ChooseGpuTopologies(NV_MOSAIC_GRID_TOPO *pGridTopologies, unsigned int gridCount, unsigned int setTopoFlags, NV_GPU_TOPOLOGIES *pGpuTopologies)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_GRID_TOPO *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  NV_GPU_TOPOLOGIES *v13; // [rsp+68h] [rbp+20h]

  v13 = pGpuTopologies;
  v12 = setTopoFlags;
  v11 = gridCount;
  v10 = pGridTopologies;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_295 = 0i64;
  if ( !fp_295 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_295 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB033B140);
  if ( !fp_295 )
    return 4294967293i64;
  v5 = fp_295;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB033B140, &v7);
  v8 = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, _QWORD, _QWORD, NV_GPU_TOPOLOGIES *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB033B140, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 8302
// RVA: 0xEB1C10
signed __int64 __fastcall NvAPI_Mosaic_EnumDisplayGrids(NV_MOSAIC_GRID_TOPO *pGridTopologies, unsigned int *pGridCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_GRID_TOPO *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pGridCount;
  v8 = pGridTopologies;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_296 = 0i64;
  if ( !fp_296 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_296 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDF2887AF);
  if ( !fp_296 )
    return 4294967293i64;
  v3 = fp_296;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDF2887AF, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_MOSAIC_GRID_TOPO *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDF2887AF, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8327
// RVA: 0xEB1D40
signed __int64 __fastcall NvAPI_GetSupportedMosaicTopologies(NV_MOSAIC_SUPPORTED_TOPOLOGIES *pMosaicTopos)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_SUPPORTED_TOPOLOGIES *v7; // [rsp+50h] [rbp+8h]

  v7 = pMosaicTopos;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_297 = 0i64;
  if ( !fp_297 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_297 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x410B5C25u);
  if ( !fp_297 )
    return 4294967293i64;
  v2 = fp_297;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x410B5C25u, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_MOSAIC_SUPPORTED_TOPOLOGIES *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x410B5C25u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8352
// RVA: 0xEB1E60
signed __int64 __fastcall NvAPI_GetCurrentMosaicTopology(NV_MOSAIC_TOPOLOGY *pMosaicTopo, unsigned int *pEnabled)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_TOPOLOGY *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pEnabled;
  v8 = pMosaicTopo;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_298 = 0i64;
  if ( !fp_298 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_298 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF60852BD);
  if ( !fp_298 )
    return 4294967293i64;
  v3 = fp_298;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF60852BD, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPOLOGY *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF60852BD, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8377
// RVA: 0xEB1F90
signed __int64 __fastcall NvAPI_SetCurrentMosaicTopology(NV_MOSAIC_TOPOLOGY *pMosaicTopo)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_MOSAIC_TOPOLOGY *v7; // [rsp+50h] [rbp+8h]

  v7 = pMosaicTopo;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_299 = 0i64;
  if ( !fp_299 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_299 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD54B8989);
  if ( !fp_299 )
    return 4294967293i64;
  v2 = fp_299;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD54B8989, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_MOSAIC_TOPOLOGY *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD54B8989, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8402
// RVA: 0xEB20B0
signed __int64 __fastcall NvAPI_EnableCurrentMosaicTopology(unsigned int enable)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int v7; // [rsp+50h] [rbp+8h]

  v7 = enable;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_300 = 0i64;
  if ( !fp_300 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_300 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x74073CC9u);
  if ( !fp_300 )
    return 4294967293i64;
  v2 = fp_300;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x74073CC9u, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x74073CC9u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8427
// RVA: 0xEB21D0
signed __int64 __fastcall NvAPI_QueryNonMigratableApps(NV_3D_APP_INFO_V2 *apps, unsigned int *total)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_3D_APP_INFO_V2 *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = total;
  v8 = apps;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_301 = 0i64;
  if ( !fp_301 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_301 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBB9EF1C3);
  if ( !fp_301 )
    return 4294967293i64;
  v3 = fp_301;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBB9EF1C3, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_3D_APP_INFO_V2 *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBB9EF1C3, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8452
// RVA: 0xEB2300
signed __int64 __fastcall NvAPI_GPU_QueryActiveApps(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_3D_APP_INFO_V2 *apps, unsigned int *total)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  NV_3D_APP_INFO_V2 *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = total;
  v10 = apps;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_302 = 0i64;
  if ( !fp_302 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_302 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x65B1C5F5u);
  if ( !fp_302 )
    return 4294967293i64;
  v4 = fp_302;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x65B1C5F5u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_3D_APP_INFO_V2 *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x65B1C5F5u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 8477
// RVA: 0xEB2440
signed __int64 __fastcall NvAPI_Hybrid_QueryUnblockedNonMigratableApps(NV_HYBRID_APP_INFO *apps, unsigned int *total)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_HYBRID_APP_INFO *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = total;
  v8 = apps;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_303 = 0i64;
  if ( !fp_303 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_303 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F35BCB5u);
  if ( !fp_303 )
    return 4294967293i64;
  v3 = fp_303;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F35BCB5u, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_HYBRID_APP_INFO *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F35BCB5u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8502
// RVA: 0xEB2570
signed __int64 __fastcall NvAPI_Hybrid_QueryBlockedMigratableApps(NV_HYBRID_APP_INFO *apps, unsigned int *total)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_HYBRID_APP_INFO *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = total;
  v8 = apps;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_304 = 0i64;
  if ( !fp_304 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_304 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF4C2F8CC);
  if ( !fp_304 )
    return 4294967293i64;
  v3 = fp_304;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF4C2F8CC, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_HYBRID_APP_INFO *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF4C2F8CC, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8527
// RVA: 0xEB26A0
signed __int64 __fastcall NvAPI_Hybrid_SetAppMigrationState(NV_HYBRID_APP_INFO *app, unsigned int flag)
{
  __int64 (__fastcall *v3)(); // [rsp+28h] [rbp-250h]
  HINSTANCE__ *hMod; // [rsp+30h] [rbp-248h]
  unsigned __int64 v5; // [rsp+38h] [rbp-240h]
  _NvAPI_Status v6; // [rsp+40h] [rbp-238h]
  int v7; // [rsp+44h] [rbp-234h]
  char v8; // [rsp+50h] [rbp-228h]
  NV_HYBRID_APP_INFO *v9; // [rsp+280h] [rbp+8h]
  unsigned int v10; // [rsp+288h] [rbp+10h]

  v10 = flag;
  v9 = app;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_305 = 0i64;
  if ( !fp_305 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_305 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA0B9A59);
  if ( !fp_305 )
    return 4294967293i64;
  v3 = fp_305;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA0B9A59, &v5);
  qmemcpy(&v8, v9, 0x204ui64);
  v6 = ((unsigned int (__fastcall *)(char *, _QWORD))v3)(&v8, v10);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA0B9A59, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8552
// RVA: 0xEB27F0
signed __int64 __fastcall NvAPI_Hybrid_IsAppMigrationStateChangeable(NV_HYBRID_APP_INFO *app, unsigned int *allowed)
{
  __int64 (__fastcall *v3)(); // [rsp+28h] [rbp-250h]
  HINSTANCE__ *hMod; // [rsp+30h] [rbp-248h]
  unsigned __int64 v5; // [rsp+38h] [rbp-240h]
  _NvAPI_Status v6; // [rsp+40h] [rbp-238h]
  int v7; // [rsp+44h] [rbp-234h]
  char v8; // [rsp+50h] [rbp-228h]
  NV_HYBRID_APP_INFO *v9; // [rsp+280h] [rbp+8h]
  unsigned int *v10; // [rsp+288h] [rbp+10h]

  v10 = allowed;
  v9 = app;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_306 = 0i64;
  if ( !fp_306 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_306 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x584CB0B6u);
  if ( !fp_306 )
    return 4294967293i64;
  v3 = fp_306;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x584CB0B6u, &v5);
  qmemcpy(&v8, v9, 0x204ui64);
  v6 = ((unsigned int (__fastcall *)(char *, unsigned int *))v3)(&v8, v10);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x584CB0B6u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8577
// RVA: 0xEB2940
signed __int64 __fastcall NvAPI_GPU_GPIOQueryLegalPins(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_GPIO_LEGAL_PINS *pgpioLegalPins)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_GPIO_LEGAL_PINS *v9; // [rsp+58h] [rbp+10h]

  v9 = pgpioLegalPins;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_307 = 0i64;
  if ( !fp_307 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_307 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFAB69565);
  if ( !fp_307 )
    return 4294967293i64;
  v3 = fp_307;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFAB69565, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GPIO_LEGAL_PINS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFAB69565, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8602
// RVA: 0xEB2A70
signed __int64 __fastcall NvAPI_GPU_GPIOReadFromPin(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_GPIO_PIN_DATA *pgpioReadPin)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_GPIO_PIN_DATA *v9; // [rsp+58h] [rbp+10h]

  v9 = pgpioReadPin;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_308 = 0i64;
  if ( !fp_308 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_308 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5E10439);
  if ( !fp_308 )
    return 4294967293i64;
  v3 = fp_308;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5E10439, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GPIO_PIN_DATA *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5E10439, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8627
// RVA: 0xEB2BA0
signed __int64 __fastcall NvAPI_GPU_GPIOWriteToPin(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_GPIO_PIN_DATA *pgpioWritePin)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_GPIO_PIN_DATA *v9; // [rsp+58h] [rbp+10h]

  v9 = pgpioWritePin;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_309 = 0i64;
  if ( !fp_309 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_309 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF3B11E68);
  if ( !fp_309 )
    return 4294967293i64;
  v3 = fp_309;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF3B11E68, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GPIO_PIN_DATA *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF3B11E68, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8652
// RVA: 0xEB2CD0
signed __int64 __fastcall NvAPI_GPU_GetHDCPSupportStatus(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_GET_HDCP_SUPPORT_STATUS *pGetHDCPSupportStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_GET_HDCP_SUPPORT_STATUS *v9; // [rsp+58h] [rbp+10h]

  v9 = pGetHDCPSupportStatus;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_310 = 0i64;
  if ( !fp_310 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_310 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF089EEF5);
  if ( !fp_310 )
    return 4294967293i64;
  v3 = fp_310;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF089EEF5, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_GET_HDCP_SUPPORT_STATUS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF089EEF5, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8677
// RVA: 0xEB2E00
signed __int64 __fastcall NvAPI_SetTopologyFocusDisplayAndView(NvLogicalGpuHandle__ *hLogicalGPU, unsigned int focusDisplayOutputId, NV_DISPLAY_PATH_INFO *pPathInfo, _NV_TARGET_VIEW_MODE displayView)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvLogicalGpuHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  NV_DISPLAY_PATH_INFO *v12; // [rsp+60h] [rbp+18h]
  _NV_TARGET_VIEW_MODE v13; // [rsp+68h] [rbp+20h]

  v13 = displayView;
  v12 = pPathInfo;
  v11 = focusDisplayOutputId;
  v10 = hLogicalGPU;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_311 = 0i64;
  if ( !fp_311 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_311 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA8064F9u);
  if ( !fp_311 )
    return 4294967293i64;
  v5 = fp_311;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA8064F9u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvLogicalGpuHandle__ *, _QWORD, NV_DISPLAY_PATH_INFO *, _QWORD))v5)(
         v10,
         v11,
         v12,
         (unsigned int)v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA8064F9u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 8702
// RVA: 0xEB2F40
signed __int64 __fastcall NvAPI_Stereo_CreateConfigurationProfileRegistryKey(_NV_StereoRegistryProfileType registryProfileType)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_StereoRegistryProfileType v7; // [rsp+50h] [rbp+8h]

  v7 = registryProfileType;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_312 = 0i64;
  if ( !fp_312 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_312 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBE7692EC);
  if ( !fp_312 )
    return 4294967293i64;
  v2 = fp_312;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBE7692EC, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)((unsigned int)v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBE7692EC, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8727
// RVA: 0xEB3060
signed __int64 __fastcall NvAPI_Stereo_DeleteConfigurationProfileRegistryKey(_NV_StereoRegistryProfileType registryProfileType)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_StereoRegistryProfileType v7; // [rsp+50h] [rbp+8h]

  v7 = registryProfileType;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_313 = 0i64;
  if ( !fp_313 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_313 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF117B834);
  if ( !fp_313 )
    return 4294967293i64;
  v2 = fp_313;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF117B834, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)((unsigned int)v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF117B834, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8752
// RVA: 0xEB3180
signed __int64 __fastcall NvAPI_Stereo_SetConfigurationProfileValue(_NV_StereoRegistryProfileType registryProfileType, _NV_StereoRegistryID valueRegistryID, void *pValue)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  _NV_StereoRegistryProfileType v9; // [rsp+50h] [rbp+8h]
  _NV_StereoRegistryID v10; // [rsp+58h] [rbp+10h]
  void *v11; // [rsp+60h] [rbp+18h]

  v11 = pValue;
  v10 = valueRegistryID;
  v9 = registryProfileType;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_314 = 0i64;
  if ( !fp_314 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_314 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x24409F48u);
  if ( !fp_314 )
    return 4294967293i64;
  v4 = fp_314;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x24409F48u, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, _QWORD, void *))v4)((unsigned int)v9, (unsigned int)v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x24409F48u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 8777
// RVA: 0xEB32B0
signed __int64 __fastcall NvAPI_Stereo_DeleteConfigurationProfileValue(_NV_StereoRegistryProfileType registryProfileType, _NV_StereoRegistryID valueRegistryID)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  _NV_StereoRegistryProfileType v8; // [rsp+50h] [rbp+8h]
  _NV_StereoRegistryID v9; // [rsp+58h] [rbp+10h]

  v9 = valueRegistryID;
  v8 = registryProfileType;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_315 = 0i64;
  if ( !fp_315 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_315 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x49BCEECFu);
  if ( !fp_315 )
    return 4294967293i64;
  v3 = fp_315;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x49BCEECFu, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _QWORD))v3)((unsigned int)v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x49BCEECFu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8802
// RVA: 0xEB33E0
signed __int64 __fastcall NvAPI_Stereo_Enable()
{
  unsigned int (*v1)(void); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v3; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v4; // [rsp+38h] [rbp-10h]
  int v5; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v5 = 0;
  v4 = (unsigned int)GetGpuHandle(&hMod);
  if ( v4 && v4 != -14 )
    return v4;
  if ( v4 == -14 )
    fp_316 = 0i64;
  if ( !fp_316 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_316 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x239C4545u);
  if ( !fp_316 )
    return 4294967293i64;
  v1 = (unsigned int (*)(void))fp_316;
  v3 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x239C4545u, &v3);
  v4 = v1();
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x239C4545u, v3, v4);
  --g_module_numApiInUse[v5];
  return v4;
}

// File Line: 8827
// RVA: 0xEB3500
signed __int64 __fastcall NvAPI_Stereo_Disable()
{
  unsigned int (*v1)(void); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v3; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v4; // [rsp+38h] [rbp-10h]
  int v5; // [rsp+3Ch] [rbp-Ch]

  hMod = 0i64;
  v5 = 0;
  v4 = (unsigned int)GetGpuHandle(&hMod);
  if ( v4 && v4 != -14 )
    return v4;
  if ( v4 == -14 )
    fp_317 = 0i64;
  if ( !fp_317 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_317 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2EC50C2Bu);
  if ( !fp_317 )
    return 4294967293i64;
  v1 = (unsigned int (*)(void))fp_317;
  v3 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2EC50C2Bu, &v3);
  v4 = v1();
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2EC50C2Bu, v3, v4);
  --g_module_numApiInUse[v5];
  return v4;
}

// File Line: 8852
// RVA: 0xEB3620
signed __int64 __fastcall NvAPI_Stereo_IsEnabled(char *pIsStereoEnabled)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  char *v7; // [rsp+50h] [rbp+8h]

  v7 = pIsStereoEnabled;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_318 = 0i64;
  if ( !fp_318 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_318 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x348FF8E1u);
  if ( !fp_318 )
    return 4294967293i64;
  v2 = fp_318;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x348FF8E1u, &v4);
  v5 = ((unsigned int (__fastcall *)(char *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x348FF8E1u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8877
// RVA: 0xEB3740
signed __int64 __fastcall NvAPI_Stereo_GetStereoCaps(_NVAPI_STEREO_CAPS *pCaps)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NVAPI_STEREO_CAPS *v7; // [rsp+50h] [rbp+8h]

  v7 = pCaps;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_319 = 0i64;
  if ( !fp_319 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_319 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDFC063B7);
  if ( !fp_319 )
    return 4294967293i64;
  v2 = fp_319;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDFC063B7, &v4);
  v5 = ((unsigned int (__fastcall *)(_NVAPI_STEREO_CAPS *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDFC063B7, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8902
// RVA: 0xEB3860
signed __int64 __fastcall NvAPI_Stereo_GetStereoSupport(NvMonitorHandle__ *hMonitor, _NVAPI_STEREO_CAPS *pCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvMonitorHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_STEREO_CAPS *v9; // [rsp+58h] [rbp+10h]

  v9 = pCaps;
  v8 = hMonitor;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_320 = 0i64;
  if ( !fp_320 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_320 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x296C434Du);
  if ( !fp_320 )
    return 4294967293i64;
  v3 = fp_320;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x296C434Du, &v5);
  v6 = ((unsigned int (__fastcall *)(NvMonitorHandle__ *, _NVAPI_STEREO_CAPS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x296C434Du, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8927
// RVA: 0xEB3990
signed __int64 __fastcall NvAPI_Stereo_CreateHandleFromIUnknown(IUnknown *pDevice, void **pStereoHandle)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v8; // [rsp+50h] [rbp+8h]
  void **v9; // [rsp+58h] [rbp+10h]

  v9 = pStereoHandle;
  v8 = pDevice;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_321 = 0i64;
  if ( !fp_321 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_321 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAC7E37F4);
  if ( !fp_321 )
    return 4294967293i64;
  v3 = fp_321;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAC7E37F4, &v5);
  v6 = ((unsigned int (__fastcall *)(IUnknown *, void **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAC7E37F4, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 8952
// RVA: 0xEB3AC0
signed __int64 __fastcall NvAPI_Stereo_DestroyHandle(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_322 = 0i64;
  if ( !fp_322 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_322 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3A153134u);
  if ( !fp_322 )
    return 4294967293i64;
  v2 = fp_322;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3A153134u, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3A153134u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 8977
// RVA: 0xEB3BE0
signed __int64 __fastcall NvAPI_Stereo_Activate(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_323 = 0i64;
  if ( !fp_323 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_323 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF6A1AD68);
  if ( !fp_323 )
    return 4294967293i64;
  v2 = fp_323;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF6A1AD68, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF6A1AD68, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9002
// RVA: 0xEB3D00
signed __int64 __fastcall NvAPI_Stereo_Deactivate(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_324 = 0i64;
  if ( !fp_324 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_324 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2D68DE96u);
  if ( !fp_324 )
    return 4294967293i64;
  v2 = fp_324;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2D68DE96u, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2D68DE96u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9027
// RVA: 0xEB3E20
signed __int64 __fastcall NvAPI_Stereo_IsActivated(void *stereoHandle, char *pIsStereoOn)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = pIsStereoOn;
  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_325 = 0i64;
  if ( !fp_325 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_325 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1FB0BC30u);
  if ( !fp_325 )
    return 4294967293i64;
  v3 = fp_325;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1FB0BC30u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1FB0BC30u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9052
// RVA: 0xEB3F50
signed __int64 __fastcall NvAPI_Stereo_GetSeparation(void *stereoHandle, float *pSeparationPercentage)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  float *v9; // [rsp+58h] [rbp+10h]

  v9 = pSeparationPercentage;
  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_326 = 0i64;
  if ( !fp_326 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_326 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x451F2134u);
  if ( !fp_326 )
    return 4294967293i64;
  v3 = fp_326;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x451F2134u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, float *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x451F2134u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9077
// RVA: 0xEB4080
signed __int64 __fastcall NvAPI_Stereo_SetSeparation(void *stereoHandle, float newSeparationPercentage)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]

  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_327 = 0i64;
  if ( !fp_327 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_327 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5C069FA3u);
  if ( !fp_327 )
    return 4294967293i64;
  v3 = fp_327;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5C069FA3u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *))v3)(v8);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5C069FA3u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9102
// RVA: 0xEB41B0
signed __int64 __fastcall NvAPI_Stereo_DecreaseSeparation(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_328 = 0i64;
  if ( !fp_328 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_328 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA044458);
  if ( !fp_328 )
    return 4294967293i64;
  v2 = fp_328;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA044458, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA044458, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9127
// RVA: 0xEB42D0
signed __int64 __fastcall NvAPI_Stereo_IncreaseSeparation(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_329 = 0i64;
  if ( !fp_329 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_329 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC9A8ECEC);
  if ( !fp_329 )
    return 4294967293i64;
  v2 = fp_329;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC9A8ECEC, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC9A8ECEC, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9152
// RVA: 0xEB43F0
signed __int64 __fastcall NvAPI_Stereo_GetConvergence(void *stereoHandle, float *pConvergence)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  float *v9; // [rsp+58h] [rbp+10h]

  v9 = pConvergence;
  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_330 = 0i64;
  if ( !fp_330 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_330 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4AB00934u);
  if ( !fp_330 )
    return 4294967293i64;
  v3 = fp_330;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4AB00934u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, float *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4AB00934u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9177
// RVA: 0xEB4520
signed __int64 __fastcall NvAPI_Stereo_SetConvergence(void *stereoHandle, float newConvergence)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]

  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_331 = 0i64;
  if ( !fp_331 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_331 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3DD6B54Bu);
  if ( !fp_331 )
    return 4294967293i64;
  v3 = fp_331;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3DD6B54Bu, &v5);
  v6 = ((unsigned int (__fastcall *)(void *))v3)(v8);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3DD6B54Bu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9202
// RVA: 0xEB4650
signed __int64 __fastcall NvAPI_Stereo_DecreaseConvergence(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_332 = 0i64;
  if ( !fp_332 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_332 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4C87E317u);
  if ( !fp_332 )
    return 4294967293i64;
  v2 = fp_332;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4C87E317u, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4C87E317u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9227
// RVA: 0xEB4770
signed __int64 __fastcall NvAPI_Stereo_IncreaseConvergence(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_333 = 0i64;
  if ( !fp_333 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_333 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA17DAABE);
  if ( !fp_333 )
    return 4294967293i64;
  v2 = fp_333;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA17DAABE, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA17DAABE, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9252
// RVA: 0xEB4890
signed __int64 __fastcall NvAPI_Stereo_GetFrustumAdjustMode(void *stereoHandle, _NV_FrustumAdjustMode *pFrustumAdjustMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  _NV_FrustumAdjustMode *v9; // [rsp+58h] [rbp+10h]

  v9 = pFrustumAdjustMode;
  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_334 = 0i64;
  if ( !fp_334 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_334 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE6839B43);
  if ( !fp_334 )
    return 4294967293i64;
  v3 = fp_334;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE6839B43, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _NV_FrustumAdjustMode *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE6839B43, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9277
// RVA: 0xEB49C0
signed __int64 __fastcall NvAPI_Stereo_SetFrustumAdjustMode(void *stereoHandle, _NV_FrustumAdjustMode newFrustumAdjustModeValue)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  _NV_FrustumAdjustMode v9; // [rsp+58h] [rbp+10h]

  v9 = newFrustumAdjustModeValue;
  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_335 = 0i64;
  if ( !fp_335 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_335 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7BE27FA2u);
  if ( !fp_335 )
    return 4294967293i64;
  v3 = fp_335;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7BE27FA2u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7BE27FA2u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9302
// RVA: 0xEB4AF0
signed __int64 __fastcall NvAPI_Stereo_CaptureJpegImage(void *stereoHandle, unsigned int quality)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = quality;
  v8 = stereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_336 = 0i64;
  if ( !fp_336 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_336 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x932CB140);
  if ( !fp_336 )
    return 4294967293i64;
  v3 = fp_336;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x932CB140, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x932CB140, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9327
// RVA: 0xEB4C20
signed __int64 __fastcall NvAPI_Stereo_CapturePngImage(void *stereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = stereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_337 = 0i64;
  if ( !fp_337 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_337 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8B7E99B5);
  if ( !fp_337 )
    return 4294967293i64;
  v2 = fp_337;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8B7E99B5, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8B7E99B5, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9352
// RVA: 0xEB4D40
signed __int64 __fastcall NvAPI_Stereo_ReverseStereoBlitControl(void *hStereoHandle, char TurnOn)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  unsigned __int8 v9; // [rsp+58h] [rbp+10h]

  v9 = TurnOn;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_338 = 0i64;
  if ( !fp_338 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_338 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3CD58F89u);
  if ( !fp_338 )
    return 4294967293i64;
  v3 = fp_338;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3CD58F89u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3CD58F89u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9377
// RVA: 0xEB4E70
signed __int64 __fastcall NvAPI_Stereo_SetNotificationMessage(void *hStereoHandle, unsigned __int64 hWnd, unsigned __int64 messageID)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  void *v9; // [rsp+50h] [rbp+8h]
  unsigned __int64 v10; // [rsp+58h] [rbp+10h]
  unsigned __int64 v11; // [rsp+60h] [rbp+18h]

  v11 = messageID;
  v10 = hWnd;
  v9 = hStereoHandle;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_339 = 0i64;
  if ( !fp_339 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_339 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6B9B409Eu);
  if ( !fp_339 )
    return 4294967293i64;
  v4 = fp_339;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6B9B409Eu, &v6);
  v7 = ((unsigned int (__fastcall *)(void *, unsigned __int64, unsigned __int64))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6B9B409Eu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 9402
// RVA: 0xEB4FB0
signed __int64 __fastcall NvAPI_Stereo_SetActiveEye(void *hStereoHandle, _NV_StereoActiveEye StereoEye)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  _NV_StereoActiveEye v9; // [rsp+58h] [rbp+10h]

  v9 = StereoEye;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_340 = 0i64;
  if ( !fp_340 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_340 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x96EEA9F8);
  if ( !fp_340 )
    return 4294967293i64;
  v3 = fp_340;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x96EEA9F8, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x96EEA9F8, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9427
// RVA: 0xEB50E0
signed __int64 __fastcall NvAPI_Stereo_SetDriverMode(_NV_StereoDriverMode mode)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_StereoDriverMode v7; // [rsp+50h] [rbp+8h]

  v7 = mode;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_341 = 0i64;
  if ( !fp_341 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_341 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5E8F0BECu);
  if ( !fp_341 )
    return 4294967293i64;
  v2 = fp_341;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5E8F0BECu, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)((unsigned int)v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5E8F0BECu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9452
// RVA: 0xEB5200
signed __int64 __fastcall NvAPI_Stereo_GetEyeSeparation(void *hStereoHandle, float *pSeparation)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  float *v9; // [rsp+58h] [rbp+10h]

  v9 = pSeparation;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_342 = 0i64;
  if ( !fp_342 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_342 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCE653127);
  if ( !fp_342 )
    return 4294967293i64;
  v3 = fp_342;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCE653127, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, float *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCE653127, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9477
// RVA: 0xEB5330
signed __int64 __fastcall NvAPI_Stereo_IsWindowedModeSupported(char *bSupported)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  char *v7; // [rsp+50h] [rbp+8h]

  v7 = bSupported;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_343 = 0i64;
  if ( !fp_343 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_343 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x40C8ED5Eu);
  if ( !fp_343 )
    return 4294967293i64;
  v2 = fp_343;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x40C8ED5Eu, &v4);
  v5 = ((unsigned int (__fastcall *)(char *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x40C8ED5Eu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9502
// RVA: 0xEB5450
signed __int64 __fastcall NvAPI_Stereo_AppHandShake(void *hStereoHandle, _NVAPI_STEREO_HANDSHAKE_PARAMS *pStereoHandshakeParams)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_STEREO_HANDSHAKE_PARAMS *v9; // [rsp+58h] [rbp+10h]

  v9 = pStereoHandshakeParams;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_344 = 0i64;
  if ( !fp_344 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_344 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8C610BDA);
  if ( !fp_344 )
    return 4294967293i64;
  v3 = fp_344;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8C610BDA, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _NVAPI_STEREO_HANDSHAKE_PARAMS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8C610BDA, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9527
// RVA: 0xEB5580
signed __int64 __fastcall NvAPI_Stereo_HandShake_Trigger_Activation(void *hStereoHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  void *v7; // [rsp+50h] [rbp+8h]

  v7 = hStereoHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_345 = 0i64;
  if ( !fp_345 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_345 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB30CD1A7);
  if ( !fp_345 )
    return 4294967293i64;
  v2 = fp_345;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB30CD1A7, &v4);
  v5 = ((unsigned int (__fastcall *)(void *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB30CD1A7, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 9552
// RVA: 0xEB56A0
signed __int64 __fastcall NvAPI_Stereo_HandShake_Message_Control(void *hStereoHandle, char TurnOn)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  unsigned __int8 v9; // [rsp+58h] [rbp+10h]

  v9 = TurnOn;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_346 = 0i64;
  if ( !fp_346 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_346 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x315E0EF0u);
  if ( !fp_346 )
    return 4294967293i64;
  v3 = fp_346;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x315E0EF0u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x315E0EF0u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9577
// RVA: 0xEB57D0
signed __int64 __fastcall NvAPI_Stereo_SetSurfaceCreationMode(void *hStereoHandle, _NVAPI_STEREO_SURFACECREATEMODE creationMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_STEREO_SURFACECREATEMODE v9; // [rsp+58h] [rbp+10h]

  v9 = creationMode;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_347 = 0i64;
  if ( !fp_347 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_347 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF5DCFCBA);
  if ( !fp_347 )
    return 4294967293i64;
  v3 = fp_347;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF5DCFCBA, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, (unsigned int)v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF5DCFCBA, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9602
// RVA: 0xEB5900
signed __int64 __fastcall NvAPI_Stereo_GetSurfaceCreationMode(void *hStereoHandle, _NVAPI_STEREO_SURFACECREATEMODE *pCreationMode)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  _NVAPI_STEREO_SURFACECREATEMODE *v9; // [rsp+58h] [rbp+10h]

  v9 = pCreationMode;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_348 = 0i64;
  if ( !fp_348 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_348 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x36F1C736u);
  if ( !fp_348 )
    return 4294967293i64;
  v3 = fp_348;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x36F1C736u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _NVAPI_STEREO_SURFACECREATEMODE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x36F1C736u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9627
// RVA: 0xEB5A30
signed __int64 __fastcall NvAPI_Stereo_Debug_WasLastDrawStereoized(void *hStereoHandle, char *pWasStereoized)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  char *v9; // [rsp+58h] [rbp+10h]

  v9 = pWasStereoized;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_349 = 0i64;
  if ( !fp_349 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_349 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xED4416C5);
  if ( !fp_349 )
    return 4294967293i64;
  v3 = fp_349;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xED4416C5, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, char *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xED4416C5, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9652
// RVA: 0xEB5B60
signed __int64 __fastcall NvAPI_Stereo_ForceToScreenDepth(void *hStereoHandle, char bForceToScreenDepth)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  void *v8; // [rsp+50h] [rbp+8h]
  unsigned __int8 v9; // [rsp+58h] [rbp+10h]

  v9 = bForceToScreenDepth;
  v8 = hStereoHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_350 = 0i64;
  if ( !fp_350 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_350 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2D495758u);
  if ( !fp_350 )
    return 4294967293i64;
  v3 = fp_350;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2D495758u, &v5);
  v6 = ((unsigned int (__fastcall *)(void *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2D495758u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 9677
// RVA: 0xEB5C90
signed __int64 __fastcall NvAPI_Stereo_SetVertexShaderConstantF(void *hStereoHandle, unsigned int StartRegister, float *pConstantDataMono, float *pConstantDataLeft, float *pConstantDataRight, unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  float *v14; // [rsp+70h] [rbp+18h]
  float *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_351 = 0i64;
  if ( !fp_351 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_351 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x416C07B3u);
  if ( !fp_351 )
    return 4294967293i64;
  v7 = fp_351;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x416C07B3u, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4fCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x416C07B3u, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9702
// RVA: 0xEB5DF0
signed __int64 __fastcall NvAPI_Stereo_SetVertexShaderConstantB(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_352 = 0i64;
  if ( !fp_352 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_352 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5268716Fu);
  if ( !fp_352 )
    return 4294967293i64;
  v7 = fp_352;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5268716Fu, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          BoolCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5268716Fu, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9727
// RVA: 0xEB5F50
signed __int64 __fastcall NvAPI_Stereo_SetVertexShaderConstantI(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_353 = 0i64;
  if ( !fp_353 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_353 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7923BA0Eu);
  if ( !fp_353 )
    return 4294967293i64;
  v7 = fp_353;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7923BA0Eu, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4iCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7923BA0Eu, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9752
// RVA: 0xEB60B0
signed __int64 __fastcall NvAPI_Stereo_GetVertexShaderConstantF(void *hStereoHandle, unsigned int StartRegister, float *pConstantDataMono, float *pConstantDataLeft, float *pConstantDataRight, unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  float *v14; // [rsp+70h] [rbp+18h]
  float *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_354 = 0i64;
  if ( !fp_354 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_354 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x622FDC87u);
  if ( !fp_354 )
    return 4294967293i64;
  v7 = fp_354;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x622FDC87u, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4fCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x622FDC87u, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9777
// RVA: 0xEB6210
signed __int64 __fastcall NvAPI_Stereo_GetVertexShaderConstantB(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_355 = 0i64;
  if ( !fp_355 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_355 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x712BAA5Bu);
  if ( !fp_355 )
    return 4294967293i64;
  v7 = fp_355;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x712BAA5Bu, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          BoolCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x712BAA5Bu, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9802
// RVA: 0xEB6370
signed __int64 __fastcall NvAPI_Stereo_GetVertexShaderConstantI(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_356 = 0i64;
  if ( !fp_356 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_356 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5A60613Au);
  if ( !fp_356 )
    return 4294967293i64;
  v7 = fp_356;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5A60613Au, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4iCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5A60613Au, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9827
// RVA: 0xEB64D0
signed __int64 __fastcall NvAPI_Stereo_SetPixelShaderConstantF(void *hStereoHandle, unsigned int StartRegister, float *pConstantDataMono, float *pConstantDataLeft, float *pConstantDataRight, unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  float *v14; // [rsp+70h] [rbp+18h]
  float *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_357 = 0i64;
  if ( !fp_357 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_357 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA9657F32);
  if ( !fp_357 )
    return 4294967293i64;
  v7 = fp_357;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA9657F32, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4fCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA9657F32, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9852
// RVA: 0xEB6630
signed __int64 __fastcall NvAPI_Stereo_SetPixelShaderConstantB(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_358 = 0i64;
  if ( !fp_358 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_358 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBA6109EE);
  if ( !fp_358 )
    return 4294967293i64;
  v7 = fp_358;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBA6109EE, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          BoolCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBA6109EE, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9877
// RVA: 0xEB6790
signed __int64 __fastcall NvAPI_Stereo_SetPixelShaderConstantI(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_359 = 0i64;
  if ( !fp_359 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_359 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x912AC28F);
  if ( !fp_359 )
    return 4294967293i64;
  v7 = fp_359;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x912AC28F, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4iCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x912AC28F, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9902
// RVA: 0xEB68F0
signed __int64 __fastcall NvAPI_Stereo_GetPixelShaderConstantF(void *hStereoHandle, unsigned int StartRegister, float *pConstantDataMono, float *pConstantDataLeft, float *pConstantDataRight, unsigned int Vector4fCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  float *v14; // [rsp+70h] [rbp+18h]
  float *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_360 = 0i64;
  if ( !fp_360 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_360 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD4974572);
  if ( !fp_360 )
    return 4294967293i64;
  v7 = fp_360;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD4974572, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, float *, float *, float *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4fCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD4974572, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9927
// RVA: 0xEB6A50
signed __int64 __fastcall NvAPI_Stereo_GetPixelShaderConstantB(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int BoolCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_361 = 0i64;
  if ( !fp_361 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_361 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC79333AE);
  if ( !fp_361 )
    return 4294967293i64;
  v7 = fp_361;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC79333AE, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          BoolCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC79333AE, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9952
// RVA: 0xEB6BB0
signed __int64 __fastcall NvAPI_Stereo_GetPixelShaderConstantI(void *hStereoHandle, unsigned int StartRegister, int *pConstantDataMono, int *pConstantDataLeft, int *pConstantDataRight, unsigned int Vector4iCount)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  void *v12; // [rsp+60h] [rbp+8h]
  unsigned int v13; // [rsp+68h] [rbp+10h]
  int *v14; // [rsp+70h] [rbp+18h]
  int *v15; // [rsp+78h] [rbp+20h]

  v15 = pConstantDataLeft;
  v14 = pConstantDataMono;
  v13 = StartRegister;
  v12 = hStereoHandle;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_362 = 0i64;
  if ( !fp_362 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_362 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xECD8F8CF);
  if ( !fp_362 )
    return 4294967293i64;
  v7 = fp_362;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xECD8F8CF, &v9);
  v10 = ((unsigned int (__fastcall *)(void *, _QWORD, int *, int *, int *, unsigned int))v7)(
          v12,
          v13,
          v14,
          v15,
          pConstantDataRight,
          Vector4iCount);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xECD8F8CF, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 9977
// RVA: 0xEB6D10
signed __int64 __fastcall NvAPI_Stereo_SetDefaultProfile(const char *szProfileName)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  const char *v7; // [rsp+50h] [rbp+8h]

  v7 = szProfileName;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_363 = 0i64;
  if ( !fp_363 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_363 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x44F0ECD1u);
  if ( !fp_363 )
    return 4294967293i64;
  v2 = fp_363;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x44F0ECD1u, &v4);
  v5 = ((unsigned int (__fastcall *)(const char *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x44F0ECD1u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10002
// RVA: 0xEB6E30
signed __int64 __fastcall NvAPI_Stereo_GetDefaultProfile(unsigned int cbSizeIn, char *szProfileName, unsigned int *pcbSizeOut)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  char *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pcbSizeOut;
  v10 = szProfileName;
  v9 = cbSizeIn;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_364 = 0i64;
  if ( !fp_364 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_364 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x624E21C2u);
  if ( !fp_364 )
    return 4294967293i64;
  v4 = fp_364;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x624E21C2u, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, char *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x624E21C2u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 10027
// RVA: 0xEB6F60
signed __int64 __fastcall NvAPI_VIO_GetCapabilities(NvVioHandle__ *hVioHandle, _NVVIOCAPS *pAdapterCaps)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOCAPS *v9; // [rsp+58h] [rbp+10h]

  v9 = pAdapterCaps;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_365 = 0i64;
  if ( !fp_365 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_365 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1DC91303u);
  if ( !fp_365 )
    return 4294967293i64;
  v3 = fp_365;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1DC91303u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCAPS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1DC91303u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10052
// RVA: 0xEB7090
signed __int64 __fastcall NvAPI_VIO_Open(NvVioHandle__ *hVioHandle, unsigned int vioClass, _NVVIOOWNERTYPE ownerType)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  _NVVIOOWNERTYPE v11; // [rsp+60h] [rbp+18h]

  v11 = ownerType;
  v10 = vioClass;
  v9 = hVioHandle;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_366 = 0i64;
  if ( !fp_366 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_366 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x44EE4841u);
  if ( !fp_366 )
    return 4294967293i64;
  v4 = fp_366;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x44EE4841u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _QWORD))v4)(v9, v10, (unsigned int)v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x44EE4841u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 10077
// RVA: 0xEB71C0
signed __int64 __fastcall NvAPI_VIO_Close(NvVioHandle__ *hVioHandle, unsigned int bRelease)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = bRelease;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_367 = 0i64;
  if ( !fp_367 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_367 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD01BD237);
  if ( !fp_367 )
    return 4294967293i64;
  v3 = fp_367;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD01BD237, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD01BD237, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10102
// RVA: 0xEB72F0
signed __int64 __fastcall NvAPI_VIO_Status(NvVioHandle__ *hVioHandle, _NVVIOSTATUS *pStatus)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOSTATUS *v9; // [rsp+58h] [rbp+10h]

  v9 = pStatus;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_368 = 0i64;
  if ( !fp_368 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_368 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE6CE4F1u);
  if ( !fp_368 )
    return 4294967293i64;
  v3 = fp_368;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE6CE4F1u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOSTATUS *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE6CE4F1u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10127
// RVA: 0xEB7420
signed __int64 __fastcall NvAPI_VIO_SyncFormatDetect(NvVioHandle__ *hVioHandle, unsigned int *pWait)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pWait;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_369 = 0i64;
  if ( !fp_369 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_369 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x118D48A3u);
  if ( !fp_369 )
    return 4294967293i64;
  v3 = fp_369;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x118D48A3u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x118D48A3u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10152
// RVA: 0xEB7550
signed __int64 __fastcall NvAPI_VIO_GetConfig(NvVioHandle__ *hVioHandle, _NVVIOCONFIG_V3 *pConfig)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOCONFIG_V3 *v9; // [rsp+58h] [rbp+10h]

  v9 = pConfig;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_370 = 0i64;
  if ( !fp_370 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_370 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD34A789B);
  if ( !fp_370 )
    return 4294967293i64;
  v3 = fp_370;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD34A789B, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCONFIG_V3 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD34A789B, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10177
// RVA: 0xEB7680
signed __int64 __fastcall NvAPI_VIO_SetConfig(NvVioHandle__ *hVioHandle, _NVVIOCONFIG_V3 *pConfig)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOCONFIG_V3 *v9; // [rsp+58h] [rbp+10h]

  v9 = pConfig;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_371 = 0i64;
  if ( !fp_371 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_371 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE4EEC07u);
  if ( !fp_371 )
    return 4294967293i64;
  v3 = fp_371;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE4EEC07u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCONFIG_V3 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE4EEC07u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10202
// RVA: 0xEB77B0
signed __int64 __fastcall NvAPI_VIO_SetCSC(NvVioHandle__ *hVioHandle, _NVVIOCOLORCONVERSION *pCSC)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOCOLORCONVERSION *v9; // [rsp+58h] [rbp+10h]

  v9 = pCSC;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_372 = 0i64;
  if ( !fp_372 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_372 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA1EC8D74);
  if ( !fp_372 )
    return 4294967293i64;
  v3 = fp_372;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA1EC8D74, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCOLORCONVERSION *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA1EC8D74, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10227
// RVA: 0xEB78E0
signed __int64 __fastcall NvAPI_VIO_GetCSC(NvVioHandle__ *hVioHandle, _NVVIOCOLORCONVERSION *pCSC)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOCOLORCONVERSION *v9; // [rsp+58h] [rbp+10h]

  v9 = pCSC;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_373 = 0i64;
  if ( !fp_373 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_373 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7B0D72A3u);
  if ( !fp_373 )
    return 4294967293i64;
  v3 = fp_373;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7B0D72A3u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOCOLORCONVERSION *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7B0D72A3u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10252
// RVA: 0xEB7A10
signed __int64 __fastcall NvAPI_VIO_SetGamma(NvVioHandle__ *hVioHandle, _NVVIOGAMMACORRECTION *pGamma)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOGAMMACORRECTION *v9; // [rsp+58h] [rbp+10h]

  v9 = pGamma;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_374 = 0i64;
  if ( !fp_374 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_374 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x964BF452);
  if ( !fp_374 )
    return 4294967293i64;
  v3 = fp_374;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x964BF452, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOGAMMACORRECTION *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x964BF452, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10277
// RVA: 0xEB7B40
signed __int64 __fastcall NvAPI_VIO_GetGamma(NvVioHandle__ *hVioHandle, _NVVIOGAMMACORRECTION *pGamma)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOGAMMACORRECTION *v9; // [rsp+58h] [rbp+10h]

  v9 = pGamma;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_375 = 0i64;
  if ( !fp_375 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_375 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x51D53D06u);
  if ( !fp_375 )
    return 4294967293i64;
  v3 = fp_375;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x51D53D06u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOGAMMACORRECTION *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x51D53D06u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10302
// RVA: 0xEB7C70
signed __int64 __fastcall NvAPI_VIO_SetSyncDelay(NvVioHandle__ *hVioHandle, _NVVIOSYNCDELAY *pSyncDelay)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOSYNCDELAY *v9; // [rsp+58h] [rbp+10h]

  v9 = pSyncDelay;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_376 = 0i64;
  if ( !fp_376 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_376 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2697A8D1u);
  if ( !fp_376 )
    return 4294967293i64;
  v3 = fp_376;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2697A8D1u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOSYNCDELAY *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2697A8D1u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10327
// RVA: 0xEB7DA0
signed __int64 __fastcall NvAPI_VIO_GetSyncDelay(NvVioHandle__ *hVioHandle, _NVVIOSYNCDELAY *pSyncDelay)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOSYNCDELAY *v9; // [rsp+58h] [rbp+10h]

  v9 = pSyncDelay;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_377 = 0i64;
  if ( !fp_377 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_377 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x462214A9u);
  if ( !fp_377 )
    return 4294967293i64;
  v3 = fp_377;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x462214A9u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOSYNCDELAY *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x462214A9u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10352
// RVA: 0xEB7ED0
signed __int64 __fastcall NvAPI_VIO_GetPCIInfo(NvVioHandle__ *hVioHandle, _NVVIOPCIINFO *pVioPCIInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v8; // [rsp+50h] [rbp+8h]
  _NVVIOPCIINFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pVioPCIInfo;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_378 = 0i64;
  if ( !fp_378 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_378 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB981D935);
  if ( !fp_378 )
    return 4294967293i64;
  v3 = fp_378;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB981D935, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _NVVIOPCIINFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB981D935, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10377
// RVA: 0xEB8000
signed __int64 __fastcall NvAPI_VIO_IsRunning(NvVioHandle__ *hVioHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hVioHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_379 = 0i64;
  if ( !fp_379 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_379 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x96BD040E);
  if ( !fp_379 )
    return 4294967293i64;
  v2 = fp_379;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x96BD040E, &v4);
  v5 = ((unsigned int (__fastcall *)(NvVioHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x96BD040E, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10402
// RVA: 0xEB8120
signed __int64 __fastcall NvAPI_VIO_Start(NvVioHandle__ *hVioHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hVioHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_380 = 0i64;
  if ( !fp_380 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_380 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCDE8E1A3);
  if ( !fp_380 )
    return 4294967293i64;
  v2 = fp_380;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCDE8E1A3, &v4);
  v5 = ((unsigned int (__fastcall *)(NvVioHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCDE8E1A3, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10427
// RVA: 0xEB8240
signed __int64 __fastcall NvAPI_VIO_Stop(NvVioHandle__ *hVioHandle)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hVioHandle;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_381 = 0i64;
  if ( !fp_381 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_381 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6BA2A5D6u);
  if ( !fp_381 )
    return 4294967293i64;
  v2 = fp_381;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6BA2A5D6u, &v4);
  v5 = ((unsigned int (__fastcall *)(NvVioHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6BA2A5D6u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10452
// RVA: 0xEB8360
signed __int64 __fastcall NvAPI_VIO_IsFrameLockModeCompatible(NvVioHandle__ *hVioHandle, unsigned int srcEnumIndex, unsigned int destEnumIndex, unsigned int *pbCompatible)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned int v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int *v13; // [rsp+68h] [rbp+20h]

  v13 = pbCompatible;
  v12 = destEnumIndex;
  v11 = srcEnumIndex;
  v10 = hVioHandle;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_382 = 0i64;
  if ( !fp_382 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_382 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7BF0A94Du);
  if ( !fp_382 )
    return 4294967293i64;
  v5 = fp_382;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7BF0A94Du, &v7);
  v8 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _QWORD, unsigned int *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7BF0A94Du, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 10477
// RVA: 0xEB84A0
signed __int64 __fastcall NvAPI_VIO_EnumDevices(NvVioHandle__ **hVioHandle, unsigned int *vioDeviceCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ **v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = vioDeviceCount;
  v8 = hVioHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_383 = 0i64;
  if ( !fp_383 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_383 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFD7C5557);
  if ( !fp_383 )
    return 4294967293i64;
  v3 = fp_383;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFD7C5557, &v5);
  v6 = ((unsigned int (__fastcall *)(NvVioHandle__ **, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFD7C5557, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10502
// RVA: 0xEB85D0
signed __int64 __fastcall NvAPI_VIO_QueryTopology(_NV_VIO_TOPOLOGY *pNvVIOTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_VIO_TOPOLOGY *v7; // [rsp+50h] [rbp+8h]

  v7 = pNvVIOTopology;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_384 = 0i64;
  if ( !fp_384 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_384 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x869534E2);
  if ( !fp_384 )
    return 4294967293i64;
  v2 = fp_384;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x869534E2, &v4);
  v5 = ((unsigned int (__fastcall *)(_NV_VIO_TOPOLOGY *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x869534E2, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10527
// RVA: 0xEB86F0
signed __int64 __fastcall NvAPI_VIO_EnumSignalFormats(NvVioHandle__ *hVioHandle, unsigned int enumIndex, _NVVIOSIGNALFORMATDETAIL *pSignalFormatDetail)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  _NVVIOSIGNALFORMATDETAIL *v11; // [rsp+60h] [rbp+18h]

  v11 = pSignalFormatDetail;
  v10 = enumIndex;
  v9 = hVioHandle;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_385 = 0i64;
  if ( !fp_385 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_385 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEAD72FE4);
  if ( !fp_385 )
    return 4294967293i64;
  v4 = fp_385;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEAD72FE4, &v6);
  v7 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _NVVIOSIGNALFORMATDETAIL *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEAD72FE4, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 10552
// RVA: 0xEB8820
signed __int64 __fastcall NvAPI_VIO_EnumDataFormats(NvVioHandle__ *hVioHandle, unsigned int enumIndex, _NVVIODATAFORMATDETAIL *pDataFormatDetail)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvVioHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  _NVVIODATAFORMATDETAIL *v11; // [rsp+60h] [rbp+18h]

  v11 = pDataFormatDetail;
  v10 = enumIndex;
  v9 = hVioHandle;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_386 = 0i64;
  if ( !fp_386 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_386 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x221FA8E8u);
  if ( !fp_386 )
    return 4294967293i64;
  v4 = fp_386;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x221FA8E8u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvVioHandle__ *, _QWORD, _NVVIODATAFORMATDETAIL *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x221FA8E8u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 10577
// RVA: 0xEB8950
signed __int64 __fastcall NvAPI_GPU_GetTachReading(NvPhysicalGpuHandle__ *hPhysicalGPU, unsigned int *pValue)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pValue;
  v8 = hPhysicalGPU;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_387 = 0i64;
  if ( !fp_387 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_387 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F608315u);
  if ( !fp_387 )
    return 4294967293i64;
  v3 = fp_387;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F608315u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F608315u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10602
// RVA: 0xEB8A80
signed __int64 __fastcall NvAPI_3D_GetProperty(char *szProfileName, NV_3D_SETTING *p3dSetting)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  char *v8; // [rsp+50h] [rbp+8h]
  NV_3D_SETTING *v9; // [rsp+58h] [rbp+10h]

  v9 = p3dSetting;
  v8 = szProfileName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_388 = 0i64;
  if ( !fp_388 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_388 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8061A4B1);
  if ( !fp_388 )
    return 4294967293i64;
  v3 = fp_388;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8061A4B1, &v5);
  v6 = ((unsigned int (__fastcall *)(char *, NV_3D_SETTING *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8061A4B1, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10627
// RVA: 0xEB8BB0
signed __int64 __fastcall NvAPI_3D_SetProperty(char *szProfileName, NV_3D_SETTING *p3dSetting)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  char *v8; // [rsp+50h] [rbp+8h]
  NV_3D_SETTING *v9; // [rsp+58h] [rbp+10h]

  v9 = p3dSetting;
  v8 = szProfileName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_389 = 0i64;
  if ( !fp_389 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_389 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC9175E8D);
  if ( !fp_389 )
    return 4294967293i64;
  v3 = fp_389;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC9175E8D, &v5);
  v6 = ((unsigned int (__fastcall *)(char *, NV_3D_SETTING *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC9175E8D, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10652
// RVA: 0xEB8CE0
signed __int64 __fastcall NvAPI_3D_GetPropertyRange(char *szProfileName, NV_3D_SETTING_RANGE *p3dsettingRange)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  char *v8; // [rsp+50h] [rbp+8h]
  NV_3D_SETTING_RANGE *v9; // [rsp+58h] [rbp+10h]

  v9 = p3dsettingRange;
  v8 = szProfileName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_390 = 0i64;
  if ( !fp_390 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_390 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB85DE27C);
  if ( !fp_390 )
    return 4294967293i64;
  v3 = fp_390;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB85DE27C, &v5);
  v6 = ((unsigned int (__fastcall *)(char *, NV_3D_SETTING_RANGE *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB85DE27C, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10677
// RVA: 0xEB8E10
signed __int64 __fastcall NvAPI_GPS_GetPowerSteeringStatus(NV_GPS_PS_STATUS *pPowerSteeringStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_GPS_PS_STATUS *v7; // [rsp+50h] [rbp+8h]

  v7 = pPowerSteeringStatus;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_391 = 0i64;
  if ( !fp_391 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_391 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x540EE82Eu);
  if ( !fp_391 )
    return 4294967293i64;
  v2 = fp_391;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x540EE82Eu, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_GPS_PS_STATUS *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x540EE82Eu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10702
// RVA: 0xEB8F30
signed __int64 __fastcall NvAPI_GPS_SetPowerSteeringStatus(NV_GPS_PS_STATUS PowerSteeringStatus)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_GPS_PS_STATUS v7; // [rsp+50h] [rbp+8h]

  v7 = PowerSteeringStatus;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_392 = 0i64;
  if ( !fp_392 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_392 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9723D3A2);
  if ( !fp_392 )
    return 4294967293i64;
  v2 = fp_392;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9723D3A2, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)((unsigned int)v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9723D3A2, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10727
// RVA: 0xEB9050
signed __int64 __fastcall NvAPI_GPS_SetVPStateCap(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int newCap)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int v9; // [rsp+58h] [rbp+10h]

  v9 = newCap;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_393 = 0i64;
  if ( !fp_393 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_393 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x68888EB4u);
  if ( !fp_393 )
    return 4294967293i64;
  v3 = fp_393;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x68888EB4u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x68888EB4u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10752
// RVA: 0xEB9180
signed __int64 __fastcall NvAPI_GPS_GetVPStateCap(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pCurCap)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pCurCap;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_394 = 0i64;
  if ( !fp_394 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_394 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x71913023u);
  if ( !fp_394 )
    return 4294967293i64;
  v3 = fp_394;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x71913023u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x71913023u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10777
// RVA: 0xEB92B0
signed __int64 __fastcall NvAPI_GPS_GetThermalLimit(_NV_GPS_GET_THERMAL_LIMIT_PARM *pParams)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_GPS_GET_THERMAL_LIMIT_PARM *v7; // [rsp+50h] [rbp+8h]

  v7 = pParams;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_395 = 0i64;
  if ( !fp_395 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_395 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x583113EDu);
  if ( !fp_395 )
    return 4294967293i64;
  v2 = fp_395;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x583113EDu, &v4);
  v5 = ((unsigned int (__fastcall *)(_NV_GPS_GET_THERMAL_LIMIT_PARM *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x583113EDu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10802
// RVA: 0xEB93D0
signed __int64 __fastcall NvAPI_GPS_SetThermalLimit(_NV_GPS_SET_THERMAL_LIMIT_PARM *pParams)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_GPS_SET_THERMAL_LIMIT_PARM *v7; // [rsp+50h] [rbp+8h]

  v7 = pParams;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_396 = 0i64;
  if ( !fp_396 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_396 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC07E210F);
  if ( !fp_396 )
    return 4294967293i64;
  v2 = fp_396;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC07E210F, &v4);
  v5 = ((unsigned int (__fastcall *)(_NV_GPS_SET_THERMAL_LIMIT_PARM *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC07E210F, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10827
// RVA: 0xEB94F0
signed __int64 __fastcall NvAPI_GPS_GetPerfSensors(_NV_GPS_GET_PERF_SENSOR_COUNTERS_PARAM_V1 *pParams)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NV_GPS_GET_PERF_SENSOR_COUNTERS_PARAM_V1 *v7; // [rsp+50h] [rbp+8h]

  v7 = pParams;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_397 = 0i64;
  if ( !fp_397 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_397 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x271C1109u);
  if ( !fp_397 )
    return 4294967293i64;
  v2 = fp_397;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x271C1109u, &v4);
  v5 = ((unsigned int (__fastcall *)(_NV_GPS_GET_PERF_SENSOR_COUNTERS_PARAM_V1 *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x271C1109u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10852
// RVA: 0xEB9610
signed __int64 __fastcall NvAPI_SYS_GetDisplayIdFromGpuAndOutputId(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, unsigned int *displayId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = displayId;
  v10 = outputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_398 = 0i64;
  if ( !fp_398 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_398 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x8F2BAB4u);
  if ( !fp_398 )
    return 4294967293i64;
  v4 = fp_398;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x8F2BAB4u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x8F2BAB4u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 10877
// RVA: 0xEB9740
signed __int64 __fastcall NvAPI_SYS_GetGpuAndOutputIdFromDisplayId(unsigned int displayId, NvPhysicalGpuHandle__ **hPhysicalGpu, unsigned int *outputId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  NvPhysicalGpuHandle__ **v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = outputId;
  v10 = hPhysicalGpu;
  v9 = displayId;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_399 = 0i64;
  if ( !fp_399 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_399 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x112BA1A5u);
  if ( !fp_399 )
    return 4294967293i64;
  v4 = fp_399;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x112BA1A5u, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, NvPhysicalGpuHandle__ **, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x112BA1A5u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 10902
// RVA: 0xEB9870
signed __int64 __fastcall NvAPI_DISP_GetDisplayIdByDisplayName(const char *displayName, unsigned int *displayId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  const char *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = displayId;
  v8 = displayName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_400 = 0i64;
  if ( !fp_400 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_400 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE457190);
  if ( !fp_400 )
    return 4294967293i64;
  v3 = fp_400;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE457190, &v5);
  v6 = ((unsigned int (__fastcall *)(const char *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE457190, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10927
// RVA: 0xEB99A0
signed __int64 __fastcall NvAPI_DISP_GetGDIPrimaryDisplayId(unsigned int *displayId)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = displayId;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_401 = 0i64;
  if ( !fp_401 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_401 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1E9D8A31u);
  if ( !fp_401 )
    return 4294967293i64;
  v2 = fp_401;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1E9D8A31u, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1E9D8A31u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 10952
// RVA: 0xEB9AC0
signed __int64 __fastcall NvAPI_DISP_GetDisplayConfig(unsigned int *pathInfoCount, _NV_DISPLAYCONFIG_PATH_INFO *pathInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  _NV_DISPLAYCONFIG_PATH_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pathInfo;
  v8 = pathInfoCount;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_402 = 0i64;
  if ( !fp_402 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_402 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x11ABCCF8u);
  if ( !fp_402 )
    return 4294967293i64;
  v3 = fp_402;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x11ABCCF8u, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, _NV_DISPLAYCONFIG_PATH_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x11ABCCF8u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 10977
// RVA: 0xEB9BF0
signed __int64 __fastcall NvAPI_DISP_SetDisplayConfig(unsigned int pathInfoCount, _NV_DISPLAYCONFIG_PATH_INFO *pathInfo, unsigned int flags)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  _NV_DISPLAYCONFIG_PATH_INFO *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = flags;
  v10 = pathInfo;
  v9 = pathInfoCount;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_403 = 0i64;
  if ( !fp_403 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_403 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5D8CF8DEu);
  if ( !fp_403 )
    return 4294967293i64;
  v4 = fp_403;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5D8CF8DEu, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, _NV_DISPLAYCONFIG_PATH_INFO *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5D8CF8DEu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11002
// RVA: 0xEB9D20
signed __int64 __fastcall NvAPI_GPU_GetPixelClockRange(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, NV_GET_PCLK *pTimings)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_GET_PCLK *v11; // [rsp+60h] [rbp+18h]

  v11 = pTimings;
  v10 = outputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_404 = 0i64;
  if ( !fp_404 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_404 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x66AF10B7u);
  if ( !fp_404 )
    return 4294967293i64;
  v4 = fp_404;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x66AF10B7u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_GET_PCLK *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x66AF10B7u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11027
// RVA: 0xEB9E50
signed __int64 __fastcall NvAPI_GPU_SetPixelClockRange(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int outputId, NV_SET_PCLK *pTimings)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NV_SET_PCLK *v11; // [rsp+60h] [rbp+18h]

  v11 = pTimings;
  v10 = outputId;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_405 = 0i64;
  if ( !fp_405 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_405 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5AC7F8E5u);
  if ( !fp_405 )
    return 4294967293i64;
  v4 = fp_405;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5AC7F8E5u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, NV_SET_PCLK *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5AC7F8E5u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11052
// RVA: 0xEB9F80
signed __int64 __fastcall NvAPI_GPU_GetECCStatusInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_ECC_STATUS_INFO *pECCStatusInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_ECC_STATUS_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pECCStatusInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_406 = 0i64;
  if ( !fp_406 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_406 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCA1DDAF3);
  if ( !fp_406 )
    return 4294967293i64;
  v3 = fp_406;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCA1DDAF3, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_ECC_STATUS_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCA1DDAF3, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11077
// RVA: 0xEBA0B0
signed __int64 __fastcall NvAPI_GPU_GetECCErrorInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_ECC_ERROR_INFO *pECCErrorInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_ECC_ERROR_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pECCErrorInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_407 = 0i64;
  if ( !fp_407 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_407 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC71F85A6);
  if ( !fp_407 )
    return 4294967293i64;
  v3 = fp_407;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC71F85A6, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_ECC_ERROR_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC71F85A6, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11102
// RVA: 0xEBA1E0
signed __int64 __fastcall NvAPI_GPU_ResetECCErrorInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, char bResetCurrent, char bResetAggregate)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned __int8 v10; // [rsp+58h] [rbp+10h]
  unsigned __int8 v11; // [rsp+60h] [rbp+18h]

  v11 = bResetAggregate;
  v10 = bResetCurrent;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_408 = 0i64;
  if ( !fp_408 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_408 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC02EEC20);
  if ( !fp_408 )
    return 4294967293i64;
  v4 = fp_408;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC02EEC20, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC02EEC20, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11127
// RVA: 0xEBA320
signed __int64 __fastcall NvAPI_GPU_GetECCConfigurationInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, NV_GPU_ECC_CONFIGURATION_INFO *pECCConfigurationInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_GPU_ECC_CONFIGURATION_INFO *v9; // [rsp+58h] [rbp+10h]

  v9 = pECCConfigurationInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_409 = 0i64;
  if ( !fp_409 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_409 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x77A796F3u);
  if ( !fp_409 )
    return 4294967293i64;
  v3 = fp_409;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x77A796F3u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_GPU_ECC_CONFIGURATION_INFO *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x77A796F3u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11152
// RVA: 0xEBA450
signed __int64 __fastcall NvAPI_GPU_SetECCConfiguration(NvPhysicalGpuHandle__ *hPhysicalGpu, char bEnable, char bEnableImmediately)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned __int8 v10; // [rsp+58h] [rbp+10h]
  unsigned __int8 v11; // [rsp+60h] [rbp+18h]

  v11 = bEnableImmediately;
  v10 = bEnable;
  v9 = hPhysicalGpu;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_410 = 0i64;
  if ( !fp_410 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_410 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1CF639D9u);
  if ( !fp_410 )
    return 4294967293i64;
  v4 = fp_410;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1CF639D9u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1CF639D9u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11177
// RVA: 0xEBA590
signed __int64 __fastcall NvAPI_D3D1x_CreateSwapChain(void *hStereoHandle, unsigned int *pDesc, unsigned int **ppSwapChain, _NV_StereoSwapChainMode mode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  void *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int **v12; // [rsp+60h] [rbp+18h]
  _NV_StereoSwapChainMode v13; // [rsp+68h] [rbp+20h]

  v13 = mode;
  v12 = ppSwapChain;
  v11 = pDesc;
  v10 = hStereoHandle;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_411 = 0i64;
  if ( !fp_411 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_411 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1BC21B66u);
  if ( !fp_411 )
    return 4294967293i64;
  v5 = fp_411;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1BC21B66u, &v7);
  v8 = ((unsigned int (__fastcall *)(void *, unsigned int *, unsigned int **, _QWORD))v5)(
         v10,
         v11,
         v12,
         (unsigned int)v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1BC21B66u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11202
// RVA: 0xEBA6D0
signed __int64 __fastcall NvAPI_D3D9_CreateSwapChain(void *hStereoHandle, unsigned int *pPresentationParameters, unsigned int **ppSwapChain, _NV_StereoSwapChainMode mode)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  void *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int **v12; // [rsp+60h] [rbp+18h]
  _NV_StereoSwapChainMode v13; // [rsp+68h] [rbp+20h]

  v13 = mode;
  v12 = ppSwapChain;
  v11 = pPresentationParameters;
  v10 = hStereoHandle;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_412 = 0i64;
  if ( !fp_412 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_412 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1A131E09u);
  if ( !fp_412 )
    return 4294967293i64;
  v5 = fp_412;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1A131E09u, &v7);
  v8 = ((unsigned int (__fastcall *)(void *, unsigned int *, unsigned int **, _QWORD))v5)(
         v10,
         v11,
         v12,
         (unsigned int)v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1A131E09u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11227
// RVA: 0xEBA810
signed __int64 __fastcall NvAPI_D3D_SetFPSIndicatorState(IUnknown *pDev, char doEnable)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v8; // [rsp+50h] [rbp+8h]
  unsigned __int8 v9; // [rsp+58h] [rbp+10h]

  v9 = doEnable;
  v8 = pDev;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_413 = 0i64;
  if ( !fp_413 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_413 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA776E8DB);
  if ( !fp_413 )
    return 4294967293i64;
  v3 = fp_413;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA776E8DB, &v5);
  v6 = ((unsigned int (__fastcall *)(IUnknown *, _QWORD))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA776E8DB, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11252
// RVA: 0xEBA940
signed __int64 __fastcall NvAPI_D3D9_Present(unsigned int *pDevice, unsigned int *pSwapChain, tagRECT *pSourceRect, tagRECT *pDestRect, HWND__ *hDestWindowOverride, _RGNDATA *pDirtyRegion)
{
  __int64 (__fastcall *v7)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v9; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v10; // [rsp+48h] [rbp-10h]
  int v11; // [rsp+4Ch] [rbp-Ch]
  unsigned int *v12; // [rsp+60h] [rbp+8h]
  unsigned int *v13; // [rsp+68h] [rbp+10h]
  tagRECT *v14; // [rsp+70h] [rbp+18h]
  tagRECT *v15; // [rsp+78h] [rbp+20h]

  v15 = pDestRect;
  v14 = pSourceRect;
  v13 = pSwapChain;
  v12 = pDevice;
  hMod = 0i64;
  v11 = 0;
  v10 = (unsigned int)GetGpuHandle(&hMod);
  if ( v10 && v10 != -14 )
    return v10;
  if ( v10 == -14 )
    fp_414 = 0i64;
  if ( !fp_414 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_414 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5650BEBu);
  if ( !fp_414 )
    return 4294967293i64;
  v7 = fp_414;
  v9 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5650BEBu, &v9);
  v10 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, tagRECT *, tagRECT *, HWND__ *, _RGNDATA *))v7)(
          v12,
          v13,
          v14,
          v15,
          hDestWindowOverride,
          pDirtyRegion);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5650BEBu, v9, v10);
  --g_module_numApiInUse[v11];
  return v10;
}

// File Line: 11277
// RVA: 0xEBAAA0
signed __int64 __fastcall NvAPI_D3D9_QueryFrameCount(unsigned int *pDevice, unsigned int *pFrameCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pFrameCount;
  v8 = pDevice;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_415 = 0i64;
  if ( !fp_415 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_415 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9083E53A);
  if ( !fp_415 )
    return 4294967293i64;
  v3 = fp_415;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9083E53A, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9083E53A, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11302
// RVA: 0xEBABD0
signed __int64 __fastcall NvAPI_D3D9_ResetFrameCount(unsigned int *pDevice)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = pDevice;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_416 = 0i64;
  if ( !fp_416 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_416 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA6A0675);
  if ( !fp_416 )
    return 4294967293i64;
  v2 = fp_416;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA6A0675, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA6A0675, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11327
// RVA: 0xEBACF0
signed __int64 __fastcall NvAPI_D3D9_QueryMaxSwapGroup(unsigned int *pDevice, unsigned int *pMaxGroups, unsigned int *pMaxBarriers)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pMaxBarriers;
  v10 = pMaxGroups;
  v9 = pDevice;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_417 = 0i64;
  if ( !fp_417 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_417 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5995410Du);
  if ( !fp_417 )
    return 4294967293i64;
  v4 = fp_417;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5995410Du, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5995410Du, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11352
// RVA: 0xEBAE30
signed __int64 __fastcall NvAPI_D3D9_QuerySwapGroup(unsigned int *pDevice, unsigned int *pSwapChain, unsigned int *pSwapGroup, unsigned int *pSwapBarrier)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  unsigned int *v13; // [rsp+68h] [rbp+20h]

  v13 = pSwapBarrier;
  v12 = pSwapGroup;
  v11 = pSwapChain;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_418 = 0i64;
  if ( !fp_418 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_418 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEBA4D232);
  if ( !fp_418 )
    return 4294967293i64;
  v5 = fp_418;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEBA4D232, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, unsigned int *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEBA4D232, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11377
// RVA: 0xEBAF70
signed __int64 __fastcall NvAPI_D3D9_JoinSwapGroup(unsigned int *pDevice, unsigned int *pSwapChain, unsigned int group, int blocking)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = blocking;
  v12 = group;
  v11 = pSwapChain;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_419 = 0i64;
  if ( !fp_419 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_419 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7D44BB54u);
  if ( !fp_419 )
    return 4294967293i64;
  v5 = fp_419;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7D44BB54u, &v7);
  v8 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7D44BB54u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11402
// RVA: 0xEBB0B0
signed __int64 __fastcall NvAPI_D3D9_BindSwapBarrier(unsigned int *pDevice, unsigned int group, unsigned int barrier)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = barrier;
  v10 = group;
  v9 = pDevice;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_420 = 0i64;
  if ( !fp_420 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_420 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9C39C246);
  if ( !fp_420 )
    return 4294967293i64;
  v4 = fp_420;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9C39C246, &v6);
  v7 = ((unsigned int (__fastcall *)(unsigned int *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9C39C246, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11427
// RVA: 0xEBB1E0
signed __int64 __fastcall NvAPI_D3D1x_Present(IUnknown *pDevice, unsigned int *pSwapChain, unsigned int SyncInterval, unsigned int Flags)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = Flags;
  v12 = SyncInterval;
  v11 = pSwapChain;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_421 = 0i64;
  if ( !fp_421 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_421 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x3B845A1u);
  if ( !fp_421 )
    return 4294967293i64;
  v5 = fp_421;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x3B845A1u, &v7);
  v8 = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x3B845A1u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11452
// RVA: 0xEBB320
signed __int64 __fastcall NvAPI_D3D1x_QueryFrameCount(IUnknown *pDevice, unsigned int *pFrameCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pFrameCount;
  v8 = pDevice;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_422 = 0i64;
  if ( !fp_422 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_422 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9152E055);
  if ( !fp_422 )
    return 4294967293i64;
  v3 = fp_422;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9152E055, &v5);
  v6 = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9152E055, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11477
// RVA: 0xEBB450
signed __int64 __fastcall NvAPI_D3D1x_ResetFrameCount(IUnknown *pDevice)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v7; // [rsp+50h] [rbp+8h]

  v7 = pDevice;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_423 = 0i64;
  if ( !fp_423 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_423 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFBBB031A);
  if ( !fp_423 )
    return 4294967293i64;
  v2 = fp_423;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFBBB031A, &v4);
  v5 = ((unsigned int (__fastcall *)(IUnknown *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFBBB031A, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11502
// RVA: 0xEBB570
signed __int64 __fastcall NvAPI_D3D1x_QueryMaxSwapGroup(IUnknown *pDevice, unsigned int *pMaxGroups, unsigned int *pMaxBarriers)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  unsigned int *v11; // [rsp+60h] [rbp+18h]

  v11 = pMaxBarriers;
  v10 = pMaxGroups;
  v9 = pDevice;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_424 = 0i64;
  if ( !fp_424 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_424 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9BB9D68F);
  if ( !fp_424 )
    return 4294967293i64;
  v4 = fp_424;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9BB9D68F, &v6);
  v7 = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, unsigned int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9BB9D68F, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11527
// RVA: 0xEBB6B0
signed __int64 __fastcall NvAPI_D3D1x_QuerySwapGroup(IUnknown *pDevice, unsigned int *pSwapChain, unsigned int *pSwapGroup, unsigned int *pSwapBarrier)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int *v12; // [rsp+60h] [rbp+18h]
  unsigned int *v13; // [rsp+68h] [rbp+20h]

  v13 = pSwapBarrier;
  v12 = pSwapGroup;
  v11 = pSwapChain;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_425 = 0i64;
  if ( !fp_425 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_425 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x407F67AAu);
  if ( !fp_425 )
    return 4294967293i64;
  v5 = fp_425;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x407F67AAu, &v7);
  v8 = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, unsigned int *, unsigned int *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x407F67AAu, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11552
// RVA: 0xEBB7F0
signed __int64 __fastcall NvAPI_D3D1x_JoinSwapGroup(IUnknown *pDevice, unsigned int *pSwapChain, unsigned int group, int blocking)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v10; // [rsp+50h] [rbp+8h]
  unsigned int *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  unsigned int v13; // [rsp+68h] [rbp+20h]

  v13 = blocking;
  v12 = group;
  v11 = pSwapChain;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_426 = 0i64;
  if ( !fp_426 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_426 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x14610CD7u);
  if ( !fp_426 )
    return 4294967293i64;
  v5 = fp_426;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x14610CD7u, &v7);
  v8 = ((unsigned int (__fastcall *)(IUnknown *, unsigned int *, _QWORD, _QWORD))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x14610CD7u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 11577
// RVA: 0xEBB930
signed __int64 __fastcall NvAPI_D3D1x_BindSwapBarrier(IUnknown *pDevice, unsigned int group, unsigned int barrier)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = barrier;
  v10 = group;
  v9 = pDevice;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_427 = 0i64;
  if ( !fp_427 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_427 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9DE8C729);
  if ( !fp_427 )
    return 4294967293i64;
  v4 = fp_427;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9DE8C729, &v6);
  v7 = ((unsigned int (__fastcall *)(IUnknown *, _QWORD, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9DE8C729, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11602
// RVA: 0xEBBA60
signed __int64 __fastcall NvAPI_SYS_VenturaGetState(_NVAPI_VENTURA_STATE *state)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NVAPI_VENTURA_STATE *v7; // [rsp+50h] [rbp+8h]

  v7 = state;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_428 = 0i64;
  if ( !fp_428 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_428 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCB7C208D);
  if ( !fp_428 )
    return 4294967293i64;
  v2 = fp_428;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCB7C208D, &v4);
  v5 = ((unsigned int (__fastcall *)(_NVAPI_VENTURA_STATE *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCB7C208D, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11627
// RVA: 0xEBBB80
signed __int64 __fastcall NvAPI_SYS_VenturaSetState(_NVAPI_VENTURA_STATE state)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  _NVAPI_VENTURA_STATE v7; // [rsp+50h] [rbp+8h]

  v7 = state;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_429 = 0i64;
  if ( !fp_429 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_429 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCE2E9D9u);
  if ( !fp_429 )
    return 4294967293i64;
  v2 = fp_429;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCE2E9D9u, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)((unsigned int)v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCE2E9D9u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11652
// RVA: 0xEBBCA0
signed __int64 __fastcall NvAPI_SYS_VenturaGetCoolingBudget(unsigned int *budget)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v7; // [rsp+50h] [rbp+8h]

  v7 = budget;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_430 = 0i64;
  if ( !fp_430 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_430 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC9D86E33);
  if ( !fp_430 )
    return 4294967293i64;
  v2 = fp_430;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC9D86E33, &v4);
  v5 = ((unsigned int (__fastcall *)(unsigned int *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC9D86E33, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11677
// RVA: 0xEBBDC0
signed __int64 __fastcall NvAPI_SYS_VenturaSetCoolingBudget(unsigned int budget)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  unsigned int v7; // [rsp+50h] [rbp+8h]

  v7 = budget;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_431 = 0i64;
  if ( !fp_431 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_431 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x85FF5A15);
  if ( !fp_431 )
    return 4294967293i64;
  v2 = fp_431;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x85FF5A15, &v4);
  v5 = ((unsigned int (__fastcall *)(_QWORD))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x85FF5A15, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11702
// RVA: 0xEBBEE0
signed __int64 __fastcall NvAPI_SYS_VenturaGetPowerReading(_NVAPI_VENTURA_DEVICE device, unsigned int *power)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  _NVAPI_VENTURA_DEVICE v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = power;
  v8 = device;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_432 = 0i64;
  if ( !fp_432 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_432 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63685979u);
  if ( !fp_432 )
    return 4294967293i64;
  v3 = fp_432;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63685979u, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, unsigned int *))v3)((unsigned int)v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63685979u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11727
// RVA: 0xEBC010
signed __int64 __fastcall NvAPI_DISP_GetDisplayBlankingState(unsigned int displayId, _NV_DISPLAY_BLANKING_INFO_V1 *pDisplayBlankingState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_DISPLAY_BLANKING_INFO_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pDisplayBlankingState;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_433 = 0i64;
  if ( !fp_433 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_433 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x63E5D8DBu);
  if ( !fp_433 )
    return 4294967293i64;
  v3 = fp_433;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x63E5D8DBu, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _NV_DISPLAY_BLANKING_INFO_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x63E5D8DBu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11752
// RVA: 0xEBC140
signed __int64 __fastcall NvAPI_DISP_SetDisplayBlankingState(unsigned int displayId, _NV_DISPLAY_BLANKING_INFO_V1 *pDisplayBlankingState)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  _NV_DISPLAY_BLANKING_INFO_V1 *v9; // [rsp+58h] [rbp+10h]

  v9 = pDisplayBlankingState;
  v8 = displayId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_434 = 0i64;
  if ( !fp_434 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_434 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1E17E29Bu);
  if ( !fp_434 )
    return 4294967293i64;
  v3 = fp_434;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1E17E29Bu, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, _NV_DISPLAY_BLANKING_INFO_V1 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1E17E29Bu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11777
// RVA: 0xEBC270
signed __int64 __fastcall NvAPI_DRS_CreateSession(NvDRSSessionHandle__ **phSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ **v7; // [rsp+50h] [rbp+8h]

  v7 = phSession;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_435 = 0i64;
  if ( !fp_435 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_435 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x694D52Eu);
  if ( !fp_435 )
    return 4294967293i64;
  v2 = fp_435;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x694D52Eu, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ **))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x694D52Eu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11802
// RVA: 0xEBC390
signed __int64 __fastcall NvAPI_DRS_DestroySession(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hSession;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_436 = 0i64;
  if ( !fp_436 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_436 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDAD9CFF8);
  if ( !fp_436 )
    return 4294967293i64;
  v2 = fp_436;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDAD9CFF8, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDAD9CFF8, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11827
// RVA: 0xEBC4B0
signed __int64 __fastcall NvAPI_DRS_LoadSettings(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hSession;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_437 = 0i64;
  if ( !fp_437 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_437 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x375DBD6Bu);
  if ( !fp_437 )
    return 4294967293i64;
  v2 = fp_437;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x375DBD6Bu, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x375DBD6Bu, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11852
// RVA: 0xEBC5D0
signed __int64 __fastcall NvAPI_DRS_SaveSettings(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hSession;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_438 = 0i64;
  if ( !fp_438 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_438 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFCBC7E14);
  if ( !fp_438 )
    return 4294967293i64;
  v2 = fp_438;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFCBC7E14, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFCBC7E14, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 11877
// RVA: 0xEBC6F0
signed __int64 __fastcall NvAPI_DRS_LoadSettingsFromFile(NvDRSSessionHandle__ *hSession, unsigned __int16 *fileName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned __int16 *v9; // [rsp+58h] [rbp+10h]

  v9 = fileName;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_439 = 0i64;
  if ( !fp_439 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_439 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD3EDE889);
  if ( !fp_439 )
    return 4294967293i64;
  v3 = fp_439;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD3EDE889, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD3EDE889, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11902
// RVA: 0xEBC820
signed __int64 __fastcall NvAPI_DRS_SaveSettingsToFile(NvDRSSessionHandle__ *hSession, unsigned __int16 *fileName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned __int16 *v9; // [rsp+58h] [rbp+10h]

  v9 = fileName;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_440 = 0i64;
  if ( !fp_440 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_440 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2BE25DF8u);
  if ( !fp_440 )
    return 4294967293i64;
  v3 = fp_440;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2BE25DF8u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2BE25DF8u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11927
// RVA: 0xEBC950
signed __int64 __fastcall NvAPI_DRS_CreateProfile(NvDRSSessionHandle__ *hSession, _NVDRS_PROFILE *pProfileInfo, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  _NVDRS_PROFILE *v10; // [rsp+58h] [rbp+10h]
  NvDRSProfileHandle__ **v11; // [rsp+60h] [rbp+18h]

  v11 = phProfile;
  v10 = pProfileInfo;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_441 = 0i64;
  if ( !fp_441 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_441 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCC176068);
  if ( !fp_441 )
    return 4294967293i64;
  v4 = fp_441;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCC176068, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, _NVDRS_PROFILE *, NvDRSProfileHandle__ **))v4)(
         v9,
         v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCC176068, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 11952
// RVA: 0xEBCA90
signed __int64 __fastcall NvAPI_DRS_DeleteProfile(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v9; // [rsp+58h] [rbp+10h]

  v9 = hProfile;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_442 = 0i64;
  if ( !fp_442 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_442 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x17093206u);
  if ( !fp_442 )
    return 4294967293i64;
  v3 = fp_442;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x17093206u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x17093206u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 11977
// RVA: 0xEBCBC0
signed __int64 __fastcall NvAPI_DRS_SetCurrentGlobalProfile(NvDRSSessionHandle__ *hSession, unsigned __int16 *wszGlobalProfileName)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned __int16 *v9; // [rsp+58h] [rbp+10h]

  v9 = wszGlobalProfileName;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_443 = 0i64;
  if ( !fp_443 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_443 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1C89C5DFu);
  if ( !fp_443 )
    return 4294967293i64;
  v3 = fp_443;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1C89C5DFu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1C89C5DFu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12002
// RVA: 0xEBCCF0
signed __int64 __fastcall NvAPI_DRS_GetCurrentGlobalProfile(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = phProfile;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_444 = 0i64;
  if ( !fp_444 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_444 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x617BFF9Fu);
  if ( !fp_444 )
    return 4294967293i64;
  v3 = fp_444;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x617BFF9Fu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x617BFF9Fu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12027
// RVA: 0xEBCE20
signed __int64 __fastcall NvAPI_DRS_GetProfileInfo(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, _NVDRS_PROFILE *pProfileInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  _NVDRS_PROFILE *v11; // [rsp+60h] [rbp+18h]

  v11 = pProfileInfo;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_445 = 0i64;
  if ( !fp_445 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_445 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x61CD6FD6u);
  if ( !fp_445 )
    return 4294967293i64;
  v4 = fp_445;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x61CD6FD6u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_PROFILE *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x61CD6FD6u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12052
// RVA: 0xEBCF60
signed __int64 __fastcall NvAPI_DRS_SetProfileInfo(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, _NVDRS_PROFILE *pProfileInfo)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  _NVDRS_PROFILE *v11; // [rsp+60h] [rbp+18h]

  v11 = pProfileInfo;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_446 = 0i64;
  if ( !fp_446 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_446 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x16ABD3A9u);
  if ( !fp_446 )
    return 4294967293i64;
  v4 = fp_446;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x16ABD3A9u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_PROFILE *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x16ABD3A9u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12077
// RVA: 0xEBD0A0
signed __int64 __fastcall NvAPI_DRS_FindProfileByName(NvDRSSessionHandle__ *hSession, unsigned __int16 *profileName, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned __int16 *v10; // [rsp+58h] [rbp+10h]
  NvDRSProfileHandle__ **v11; // [rsp+60h] [rbp+18h]

  v11 = phProfile;
  v10 = profileName;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_447 = 0i64;
  if ( !fp_447 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_447 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7E4A9A0Bu);
  if ( !fp_447 )
    return 4294967293i64;
  v4 = fp_447;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7E4A9A0Bu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *, NvDRSProfileHandle__ **))v4)(
         v9,
         v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7E4A9A0Bu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12102
// RVA: 0xEBD1E0
signed __int64 __fastcall NvAPI_DRS_EnumProfiles(NvDRSSessionHandle__ *hSession, unsigned int index, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  unsigned int v10; // [rsp+58h] [rbp+10h]
  NvDRSProfileHandle__ **v11; // [rsp+60h] [rbp+18h]

  v11 = phProfile;
  v10 = index;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_448 = 0i64;
  if ( !fp_448 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_448 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBC371EE0);
  if ( !fp_448 )
    return 4294967293i64;
  v4 = fp_448;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBC371EE0, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, _QWORD, NvDRSProfileHandle__ **))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBC371EE0, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12127
// RVA: 0xEBD310
signed __int64 __fastcall NvAPI_DRS_GetNumProfiles(NvDRSSessionHandle__ *hSession, unsigned int *numProfiles)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = numProfiles;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_449 = 0i64;
  if ( !fp_449 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_449 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x1DAE4FBCu);
  if ( !fp_449 )
    return 4294967293i64;
  v3 = fp_449;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x1DAE4FBCu, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x1DAE4FBCu, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12152
// RVA: 0xEBD440
signed __int64 __fastcall NvAPI_DRS_CreateApplication(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  _NVDRS_APPLICATION_V2 *v11; // [rsp+60h] [rbp+18h]

  v11 = pApplication;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_450 = 0i64;
  if ( !fp_450 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_450 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x4347A9DEu);
  if ( !fp_450 )
    return 4294967293i64;
  v4 = fp_450;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x4347A9DEu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_APPLICATION_V2 *))v4)(
         v9,
         v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x4347A9DEu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12177
// RVA: 0xEBD580
signed __int64 __fastcall NvAPI_DRS_DeleteApplicationEx(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, _NVDRS_APPLICATION_V2 *pApp)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  _NVDRS_APPLICATION_V2 *v11; // [rsp+60h] [rbp+18h]

  v11 = pApp;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_451 = 0i64;
  if ( !fp_451 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_451 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xC5EA85A1);
  if ( !fp_451 )
    return 4294967293i64;
  v4 = fp_451;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xC5EA85A1, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_APPLICATION_V2 *))v4)(
         v9,
         v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xC5EA85A1, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12202
// RVA: 0xEBD6C0
signed __int64 __fastcall NvAPI_DRS_DeleteApplication(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned __int16 *appName)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  unsigned __int16 *v11; // [rsp+60h] [rbp+18h]

  v11 = appName;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_452 = 0i64;
  if ( !fp_452 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_452 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2C694BC6u);
  if ( !fp_452 )
    return 4294967293i64;
  v4 = fp_452;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2C694BC6u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, unsigned __int16 *))v4)(
         v9,
         v10,
         v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2C694BC6u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12227
// RVA: 0xEBD800
signed __int64 __fastcall NvAPI_DRS_GetApplicationInfo(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned __int16 *appName, _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v10; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v11; // [rsp+58h] [rbp+10h]
  unsigned __int16 *v12; // [rsp+60h] [rbp+18h]
  _NVDRS_APPLICATION_V2 *v13; // [rsp+68h] [rbp+20h]

  v13 = pApplication;
  v12 = appName;
  v11 = hProfile;
  v10 = hSession;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_453 = 0i64;
  if ( !fp_453 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_453 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xED1F8C69);
  if ( !fp_453 )
    return 4294967293i64;
  v5 = fp_453;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xED1F8C69, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, unsigned __int16 *, _NVDRS_APPLICATION_V2 *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xED1F8C69, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 12252
// RVA: 0xEBD940
signed __int64 __fastcall NvAPI_DRS_EnumApplications(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned int startIndex, unsigned int *appCount, _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v11; // [rsp+60h] [rbp+8h]
  NvDRSProfileHandle__ *v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  unsigned int *v14; // [rsp+78h] [rbp+20h]

  v14 = appCount;
  v13 = startIndex;
  v12 = hProfile;
  v11 = hSession;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_454 = 0i64;
  if ( !fp_454 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_454 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7FA2173Au);
  if ( !fp_454 )
    return 4294967293i64;
  v6 = fp_454;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7FA2173Au, &v8);
  v9 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD, unsigned int *, _NVDRS_APPLICATION_V2 *))v6)(
         v11,
         v12,
         v13,
         v14,
         pApplication);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7FA2173Au, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 12277
// RVA: 0xEBDA90
signed __int64 __fastcall NvAPI_DRS_FindApplicationByName(NvDRSSessionHandle__ *hSession, unsigned __int16 *appName, NvDRSProfileHandle__ **phProfile, _NVDRS_APPLICATION_V2 *pApplication)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v10; // [rsp+50h] [rbp+8h]
  unsigned __int16 *v11; // [rsp+58h] [rbp+10h]
  NvDRSProfileHandle__ **v12; // [rsp+60h] [rbp+18h]
  _NVDRS_APPLICATION_V2 *v13; // [rsp+68h] [rbp+20h]

  v13 = pApplication;
  v12 = phProfile;
  v11 = appName;
  v10 = hSession;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_455 = 0i64;
  if ( !fp_455 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_455 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xEEE566B2);
  if ( !fp_455 )
    return 4294967293i64;
  v5 = fp_455;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xEEE566B2, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, unsigned __int16 *, NvDRSProfileHandle__ **, _NVDRS_APPLICATION_V2 *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xEEE566B2, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 12302
// RVA: 0xEBDBD0
signed __int64 __fastcall NvAPI_DRS_SetSetting(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, _NVDRS_SETTING *pSetting)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  _NVDRS_SETTING *v11; // [rsp+60h] [rbp+18h]

  v11 = pSetting;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_456 = 0i64;
  if ( !fp_456 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_456 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x577DD202u);
  if ( !fp_456 )
    return 4294967293i64;
  v4 = fp_456;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x577DD202u, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _NVDRS_SETTING *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x577DD202u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12327
// RVA: 0xEBDD10
signed __int64 __fastcall NvAPI_DRS_GetSetting(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned int settingId, _NVDRS_SETTING *pSetting)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v10; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  _NVDRS_SETTING *v13; // [rsp+68h] [rbp+20h]

  v13 = pSetting;
  v12 = settingId;
  v11 = hProfile;
  v10 = hSession;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_457 = 0i64;
  if ( !fp_457 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_457 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x73BF8338u);
  if ( !fp_457 )
    return 4294967293i64;
  v5 = fp_457;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x73BF8338u, &v7);
  v8 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD, _NVDRS_SETTING *))v5)(
         v10,
         v11,
         v12,
         v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x73BF8338u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 12352
// RVA: 0xEBDE50
signed __int64 __fastcall NvAPI_DRS_EnumSettings(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned int startIndex, unsigned int *settingsCount, _NVDRS_SETTING *pSetting)
{
  __int64 (__fastcall *v6)(); // [rsp+30h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+38h] [rbp-20h]
  unsigned __int64 v8; // [rsp+40h] [rbp-18h]
  _NvAPI_Status v9; // [rsp+48h] [rbp-10h]
  int v10; // [rsp+4Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v11; // [rsp+60h] [rbp+8h]
  NvDRSProfileHandle__ *v12; // [rsp+68h] [rbp+10h]
  unsigned int v13; // [rsp+70h] [rbp+18h]
  unsigned int *v14; // [rsp+78h] [rbp+20h]

  v14 = settingsCount;
  v13 = startIndex;
  v12 = hProfile;
  v11 = hSession;
  hMod = 0i64;
  v10 = 0;
  v9 = (unsigned int)GetGpuHandle(&hMod);
  if ( v9 && v9 != -14 )
    return v9;
  if ( v9 == -14 )
    fp_458 = 0i64;
  if ( !fp_458 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_458 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xAE3039DA);
  if ( !fp_458 )
    return 4294967293i64;
  v6 = fp_458;
  v8 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xAE3039DA, &v8);
  v9 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD, unsigned int *, _NVDRS_SETTING *))v6)(
         v11,
         v12,
         v13,
         v14,
         pSetting);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xAE3039DA, v8, v9);
  --g_module_numApiInUse[v10];
  return v9;
}

// File Line: 12377
// RVA: 0xEBDFA0
signed __int64 __fastcall NvAPI_DRS_EnumAvailableSettingIds(unsigned int *pSettingIds, unsigned int *pMaxCount)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pMaxCount;
  v8 = pSettingIds;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_459 = 0i64;
  if ( !fp_459 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_459 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xF020614A);
  if ( !fp_459 )
    return 4294967293i64;
  v3 = fp_459;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xF020614A, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned int *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xF020614A, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12402
// RVA: 0xEBE0D0
signed __int64 __fastcall NvAPI_DRS_EnumAvailableSettingValues(unsigned int settingId, unsigned int *pMaxNumValues, _NVDRS_SETTING_VALUES *pSettingValues)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  unsigned int *v10; // [rsp+58h] [rbp+10h]
  _NVDRS_SETTING_VALUES *v11; // [rsp+60h] [rbp+18h]

  v11 = pSettingValues;
  v10 = pMaxNumValues;
  v9 = settingId;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_460 = 0i64;
  if ( !fp_460 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_460 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x2EC39F90u);
  if ( !fp_460 )
    return 4294967293i64;
  v4 = fp_460;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x2EC39F90u, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, unsigned int *, _NVDRS_SETTING_VALUES *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x2EC39F90u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12427
// RVA: 0xEBE200
signed __int64 __fastcall NvAPI_DRS_GetSettingIdFromName(unsigned __int16 *settingName, unsigned int *pSettingId)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned __int16 *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pSettingId;
  v8 = settingName;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_461 = 0i64;
  if ( !fp_461 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_461 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xCB7309CD);
  if ( !fp_461 )
    return 4294967293i64;
  v3 = fp_461;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xCB7309CD, &v5);
  v6 = ((unsigned int (__fastcall *)(unsigned __int16 *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xCB7309CD, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12452
// RVA: 0xEBE330
signed __int64 __fastcall NvAPI_DRS_GetSettingNameFromId(unsigned int settingId, unsigned __int16 (*pSettingName)[2048])
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  unsigned int v8; // [rsp+50h] [rbp+8h]
  unsigned __int16 (*v9)[2048]; // [rsp+58h] [rbp+10h]

  v9 = pSettingName;
  v8 = settingId;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_462 = 0i64;
  if ( !fp_462 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_462 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD61CBE6E);
  if ( !fp_462 )
    return 4294967293i64;
  v3 = fp_462;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD61CBE6E, &v5);
  v6 = ((unsigned int (__fastcall *)(_QWORD, unsigned __int16 (*)[2048]))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD61CBE6E, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12477
// RVA: 0xEBE460
signed __int64 __fastcall NvAPI_DRS_DeleteProfileSetting(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned int settingId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = settingId;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_463 = 0i64;
  if ( !fp_463 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_463 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE4A26362);
  if ( !fp_463 )
    return 4294967293i64;
  v4 = fp_463;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE4A26362, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE4A26362, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12502
// RVA: 0xEBE5A0
signed __int64 __fastcall NvAPI_DRS_RestoreAllDefaults(NvDRSSessionHandle__ *hSession)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hSession;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_464 = 0i64;
  if ( !fp_464 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_464 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5927B094u);
  if ( !fp_464 )
    return 4294967293i64;
  v2 = fp_464;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5927B094u, &v4);
  v5 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5927B094u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 12527
// RVA: 0xEBE6C0
signed __int64 __fastcall NvAPI_DRS_RestoreProfileDefault(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v9; // [rsp+58h] [rbp+10h]

  v9 = hProfile;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_465 = 0i64;
  if ( !fp_465 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_465 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xFA5F6134);
  if ( !fp_465 )
    return 4294967293i64;
  v3 = fp_465;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xFA5F6134, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xFA5F6134, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12552
// RVA: 0xEBE7F0
signed __int64 __fastcall NvAPI_DRS_RestoreProfileDefaultSetting(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ *hProfile, unsigned int settingId)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v9; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ *v10; // [rsp+58h] [rbp+10h]
  unsigned int v11; // [rsp+60h] [rbp+18h]

  v11 = settingId;
  v10 = hProfile;
  v9 = hSession;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_466 = 0i64;
  if ( !fp_466 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_466 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x53F0381Eu);
  if ( !fp_466 )
    return 4294967293i64;
  v4 = fp_466;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x53F0381Eu, &v6);
  v7 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ *, _QWORD))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x53F0381Eu, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12577
// RVA: 0xEBE930
signed __int64 __fastcall NvAPI_DRS_GetBaseProfile(NvDRSSessionHandle__ *hSession, NvDRSProfileHandle__ **phProfile)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvDRSSessionHandle__ *v8; // [rsp+50h] [rbp+8h]
  NvDRSProfileHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = phProfile;
  v8 = hSession;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_467 = 0i64;
  if ( !fp_467 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_467 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDA8466A0);
  if ( !fp_467 )
    return 4294967293i64;
  v3 = fp_467;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDA8466A0, &v5);
  v6 = ((unsigned int (__fastcall *)(NvDRSSessionHandle__ *, NvDRSProfileHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDA8466A0, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12602
// RVA: 0xEBEA60
signed __int64 __fastcall NvAPI_Event_RegisterCallback(NV_EVENT_REGISTER_CALLBACK *eventCallback, NvEventHandle__ **phClient)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_EVENT_REGISTER_CALLBACK *v8; // [rsp+50h] [rbp+8h]
  NvEventHandle__ **v9; // [rsp+58h] [rbp+10h]

  v9 = phClient;
  v8 = eventCallback;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_468 = 0i64;
  if ( !fp_468 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_468 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xE6DBEA69);
  if ( !fp_468 )
    return 4294967293i64;
  v3 = fp_468;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xE6DBEA69, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_EVENT_REGISTER_CALLBACK *, NvEventHandle__ **))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xE6DBEA69, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12627
// RVA: 0xEBEB90
signed __int64 __fastcall NvAPI_Event_UnregisterCallback(NvEventHandle__ *hClient)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NvEventHandle__ *v7; // [rsp+50h] [rbp+8h]

  v7 = hClient;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_469 = 0i64;
  if ( !fp_469 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_469 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xDE1F9B45);
  if ( !fp_469 )
    return 4294967293i64;
  v2 = fp_469;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xDE1F9B45, &v4);
  v5 = ((unsigned int (__fastcall *)(NvEventHandle__ *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xDE1F9B45, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 12652
// RVA: 0xEBECB0
signed __int64 __fastcall NvAPI_GPU_GetCurrentThermalLevel(NvPhysicalGpuHandle__ *nvGPUHandle, NV_EVENT_LEVEL *pThermalLevel)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_EVENT_LEVEL *v9; // [rsp+58h] [rbp+10h]

  v9 = pThermalLevel;
  v8 = nvGPUHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_470 = 0i64;
  if ( !fp_470 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_470 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xD2488B79);
  if ( !fp_470 )
    return 4294967293i64;
  v3 = fp_470;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xD2488B79, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_EVENT_LEVEL *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xD2488B79, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12677
// RVA: 0xEBEDE0
signed __int64 __fastcall NvAPI_GPU_GetCurrentFanSpeedLevel(NvPhysicalGpuHandle__ *nvGPUHandle, NV_EVENT_LEVEL *pFanSpeedLevel)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  NV_EVENT_LEVEL *v9; // [rsp+58h] [rbp+10h]

  v9 = pFanSpeedLevel;
  v8 = nvGPUHandle;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_471 = 0i64;
  if ( !fp_471 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_471 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xBD71F0C9);
  if ( !fp_471 )
    return 4294967293i64;
  v3 = fp_471;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xBD71F0C9, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, NV_EVENT_LEVEL *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xBD71F0C9, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12702
// RVA: 0xEBEF10
signed __int64 __fastcall NvAPI_GPU_SetScanoutIntensity(unsigned int displayId, NV_SCANOUT_INTENSITY_DATA *scanoutIntensityData, int *pbSticky)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  NV_SCANOUT_INTENSITY_DATA *v10; // [rsp+58h] [rbp+10h]
  int *v11; // [rsp+60h] [rbp+18h]

  v11 = pbSticky;
  v10 = scanoutIntensityData;
  v9 = displayId;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_472 = 0i64;
  if ( !fp_472 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_472 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xA57457A4);
  if ( !fp_472 )
    return 4294967293i64;
  v4 = fp_472;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xA57457A4, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, NV_SCANOUT_INTENSITY_DATA *, int *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xA57457A4, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12727
// RVA: 0xEBF040
signed __int64 __fastcall NvAPI_GPU_SetScanoutWarping(unsigned int displayId, NV_SCANOUT_WARPING_DATA *scanoutWarpingData, int *piMaxNumVertices, int *pbSticky)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  unsigned int v10; // [rsp+50h] [rbp+8h]
  NV_SCANOUT_WARPING_DATA *v11; // [rsp+58h] [rbp+10h]
  int *v12; // [rsp+60h] [rbp+18h]
  int *v13; // [rsp+68h] [rbp+20h]

  v13 = pbSticky;
  v12 = piMaxNumVertices;
  v11 = scanoutWarpingData;
  v10 = displayId;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_473 = 0i64;
  if ( !fp_473 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_473 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0xB34BAB4F);
  if ( !fp_473 )
    return 4294967293i64;
  v5 = fp_473;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0xB34BAB4F, &v7);
  v8 = ((unsigned int (__fastcall *)(_QWORD, NV_SCANOUT_WARPING_DATA *, int *, int *))v5)(v10, v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0xB34BAB4F, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 12752
// RVA: 0xEBF180
signed __int64 __fastcall NvAPI_GPU_GetScanoutConfiguration(unsigned int displayId, NvSBox *desktopRect, NvSBox *scanoutRect)
{
  __int64 (__fastcall *v4)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v6; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v7; // [rsp+38h] [rbp-10h]
  int v8; // [rsp+3Ch] [rbp-Ch]
  unsigned int v9; // [rsp+50h] [rbp+8h]
  NvSBox *v10; // [rsp+58h] [rbp+10h]
  NvSBox *v11; // [rsp+60h] [rbp+18h]

  v11 = scanoutRect;
  v10 = desktopRect;
  v9 = displayId;
  hMod = 0i64;
  v8 = 0;
  v7 = (unsigned int)GetGpuHandle(&hMod);
  if ( v7 && v7 != -14 )
    return v7;
  if ( v7 == -14 )
    fp_474 = 0i64;
  if ( !fp_474 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_474 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x6A9F5B63u);
  if ( !fp_474 )
    return 4294967293i64;
  v4 = fp_474;
  v6 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x6A9F5B63u, &v6);
  v7 = ((unsigned int (__fastcall *)(_QWORD, NvSBox *, NvSBox *))v4)(v9, v10, v11);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x6A9F5B63u, v6, v7);
  --g_module_numApiInUse[v8];
  return v7;
}

// File Line: 12777
// RVA: 0xEBF2B0
signed __int64 __fastcall NvAPI_DISP_SetHCloneTopology(NV_HCLONE_TOPOLOGY_V1 *pHCloneTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_HCLONE_TOPOLOGY_V1 *v7; // [rsp+50h] [rbp+8h]

  v7 = pHCloneTopology;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_475 = 0i64;
  if ( !fp_475 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_475 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x61041C24u);
  if ( !fp_475 )
    return 4294967293i64;
  v2 = fp_475;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x61041C24u, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_HCLONE_TOPOLOGY_V1 *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x61041C24u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 12802
// RVA: 0xEBF3D0
signed __int64 __fastcall NvAPI_DISP_GetHCloneTopology(NV_HCLONE_TOPOLOGY_V1 *pHCloneTopology)
{
  __int64 (__fastcall *v2)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v4; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v5; // [rsp+38h] [rbp-10h]
  int v6; // [rsp+3Ch] [rbp-Ch]
  NV_HCLONE_TOPOLOGY_V1 *v7; // [rsp+50h] [rbp+8h]

  v7 = pHCloneTopology;
  hMod = 0i64;
  v6 = 0;
  v5 = (unsigned int)GetGpuHandle(&hMod);
  if ( v5 && v5 != -14 )
    return v5;
  if ( v5 == -14 )
    fp_476 = 0i64;
  if ( !fp_476 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_476 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x47BAD137u);
  if ( !fp_476 )
    return 4294967293i64;
  v2 = fp_476;
  v4 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x47BAD137u, &v4);
  v5 = ((unsigned int (__fastcall *)(NV_HCLONE_TOPOLOGY_V1 *))v2)(v7);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x47BAD137u, v4, v5);
  --g_module_numApiInUse[v6];
  return v5;
}

// File Line: 12827
// RVA: 0xEBF4F0
signed __int64 __fastcall NvAPI_DISP_ValidateHCloneTopology(NV_HCLONE_TOPOLOGY_V1 *pHCloneTopology, unsigned int *pValid)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NV_HCLONE_TOPOLOGY_V1 *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pValid;
  v8 = pHCloneTopology;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_477 = 0i64;
  if ( !fp_477 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_477 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x5F4C2664u);
  if ( !fp_477 )
    return 4294967293i64;
  v3 = fp_477;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x5F4C2664u, &v5);
  v6 = ((unsigned int (__fastcall *)(NV_HCLONE_TOPOLOGY_V1 *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x5F4C2664u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12852
// RVA: 0xEBF620
signed __int64 __fastcall NvAPI_GPU_GetPerfDecreaseInfo(NvPhysicalGpuHandle__ *hPhysicalGpu, unsigned int *pPerfDecrInfo)
{
  __int64 (__fastcall *v3)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v5; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v6; // [rsp+38h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-Ch]
  NvPhysicalGpuHandle__ *v8; // [rsp+50h] [rbp+8h]
  unsigned int *v9; // [rsp+58h] [rbp+10h]

  v9 = pPerfDecrInfo;
  v8 = hPhysicalGpu;
  hMod = 0i64;
  v7 = 0;
  v6 = (unsigned int)GetGpuHandle(&hMod);
  if ( v6 && v6 != -14 )
    return v6;
  if ( v6 == -14 )
    fp_478 = 0i64;
  if ( !fp_478 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_478 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x7F7F4600u);
  if ( !fp_478 )
    return 4294967293i64;
  v3 = fp_478;
  v5 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x7F7F4600u, &v5);
  v6 = ((unsigned int (__fastcall *)(NvPhysicalGpuHandle__ *, unsigned int *))v3)(v8, v9);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x7F7F4600u, v5, v6);
  --g_module_numApiInUse[v7];
  return v6;
}

// File Line: 12877
// RVA: 0xEBF750
signed __int64 __fastcall NvAPI_D3D1x_IFR_SetUpTargetBufferToSys(IUnknown *pDevice, NVFBC_BUFFER_FORMAT eFormat, unsigned int dwNBuffers, void **ppBuffers)
{
  __int64 (__fastcall *v5)(); // [rsp+20h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]
  _NvAPI_Status v8; // [rsp+38h] [rbp-10h]
  int v9; // [rsp+3Ch] [rbp-Ch]
  IUnknown *v10; // [rsp+50h] [rbp+8h]
  NVFBC_BUFFER_FORMAT v11; // [rsp+58h] [rbp+10h]
  unsigned int v12; // [rsp+60h] [rbp+18h]
  void **v13; // [rsp+68h] [rbp+20h]

  v13 = ppBuffers;
  v12 = dwNBuffers;
  v11 = eFormat;
  v10 = pDevice;
  hMod = 0i64;
  v9 = 0;
  v8 = (unsigned int)GetGpuHandle(&hMod);
  if ( v8 && v8 != -14 )
    return v8;
  if ( v8 == -14 )
    fp_479 = 0i64;
  if ( !fp_479 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_479 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x473F7828u);
  if ( !fp_479 )
    return 4294967293i64;
  v5 = fp_479;
  v7 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x473F7828u, &v7);
  v8 = ((unsigned int (__fastcall *)(IUnknown *, _QWORD, _QWORD, void **))v5)(v10, (unsigned int)v11, v12, v13);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x473F7828u, v7, v8);
  --g_module_numApiInUse[v9];
  return v8;
}

// File Line: 12902
// RVA: 0xEBF890
signed __int64 __fastcall NvAPI_D3D1x_IFR_TransferRenderTarget(IUnknown *pDevice, void **pEvent, unsigned int dwBufferIndex, unsigned int dwTargetWidth, unsigned int dwTargetHeight, unsigned int dwRenderTargetIndex, unsigned int dwRenderTargetArraySlice)
{
  __int64 (__fastcall *v8)(); // [rsp+40h] [rbp-28h]
  HINSTANCE__ *hMod; // [rsp+48h] [rbp-20h]
  unsigned __int64 v10; // [rsp+50h] [rbp-18h]
  _NvAPI_Status v11; // [rsp+58h] [rbp-10h]
  int v12; // [rsp+5Ch] [rbp-Ch]
  IUnknown *v13; // [rsp+70h] [rbp+8h]
  void **v14; // [rsp+78h] [rbp+10h]
  unsigned int v15; // [rsp+80h] [rbp+18h]
  unsigned int v16; // [rsp+88h] [rbp+20h]

  v16 = dwTargetWidth;
  v15 = dwBufferIndex;
  v14 = pEvent;
  v13 = pDevice;
  hMod = 0i64;
  v12 = 0;
  v11 = (unsigned int)GetGpuHandle(&hMod);
  if ( v11 && v11 != -14 )
    return v11;
  if ( v11 == -14 )
    fp_480 = 0i64;
  if ( !fp_480 && hMod && g_nvapi_lpNvAPI_gpuQueryInterface )
    fp_480 = (__int64 (__fastcall *)())g_nvapi_lpNvAPI_gpuQueryInterface(0x9FBAE4EB);
  if ( !fp_480 )
    return 4294967293i64;
  v8 = fp_480;
  v10 = 0i64;
  if ( g_nvapi_callStart )
    g_nvapi_callStart(0x9FBAE4EB, &v10);
  v11 = ((unsigned int (__fastcall *)(IUnknown *, void **, _QWORD, _QWORD, unsigned int, unsigned int, unsigned int))v8)(
          v13,
          v14,
          v15,
          v16,
          dwTargetHeight,
          dwRenderTargetIndex,
          dwRenderTargetArraySlice);
  if ( g_nvapi_callReturn )
    g_nvapi_callReturn(0x9FBAE4EB, v10, v11);
  --g_module_numApiInUse[v12];
  return v11;
}

