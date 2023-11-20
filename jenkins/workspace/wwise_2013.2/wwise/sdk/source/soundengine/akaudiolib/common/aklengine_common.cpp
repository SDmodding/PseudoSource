// File Line: 61
// RVA: 0xA450A0
signed __int64 __fastcall CAkLEngine::CreateLEnginePools()
{
  signed int v0; // edx
  int v1; // eax

  if ( g_LEngineDefaultPoolId != -1 )
    return 1i64;
  v0 = 0x1000000;
  if ( g_PDSettings.uLEngineDefaultPoolSize > 0x40 )
    v0 = g_PDSettings.uLEngineDefaultPoolSize;
  v1 = AK::MemoryMgr::CreatePool(0i64, v0, 0x40u, 1u, 0x10u);
  g_LEngineDefaultPoolId = v1;
  if ( v1 != -1 )
  {
    AkFXMemAlloc::m_instanceLower.m_poolId = v1;
    return 1i64;
  }
  return 52i64;
}

// File Line: 87
// RVA: 0xA45100
void CAkLEngine::DestroyLEnginePools(void)
{
  if ( AK::MemoryMgr::IsInitialized() && g_LEngineDefaultPoolId != -1 )
  {
    AK::MemoryMgr::DestroyPool(g_LEngineDefaultPoolId);
    g_LEngineDefaultPoolId = -1;
  }
}

// File Line: 108
// RVA: 0xA45000
void __fastcall CAkLEngine::ApplyGlobalSettings(AkPlatformInitSettings *io_pPDSettings)
{
  __int128 v1; // xmm3
  unsigned __int16 v2; // ax

  if ( io_pPDSettings )
  {
    v1 = *(_OWORD *)&io_pPDSettings->hWnd;
    *(_OWORD *)&g_PDSettings.hWnd = *(_OWORD *)&io_pPDSettings->hWnd;
    *(_OWORD *)&g_PDSettings.threadLEngine.uStackSize = *(_OWORD *)&io_pPDSettings->threadLEngine.uStackSize;
    *(_OWORD *)&g_PDSettings.threadMonitor.nPriority = *(_OWORD *)&io_pPDSettings->threadMonitor.nPriority;
    v2 = _mm_extract_epi16(*(__m128i *)&io_pPDSettings->fLEngineDefaultPoolRatioThreshold, 2);
    *(_OWORD *)&g_PDSettings.fLEngineDefaultPoolRatioThreshold = *(_OWORD *)&io_pPDSettings->fLEngineDefaultPoolRatioThreshold;
    g_PDSettings.pXAudio2 = io_pPDSettings->pXAudio2;
    if ( v2 < 2u )
      g_PDSettings.uNumRefillsInVoice = 4;
    *(_OWORD *)&io_pPDSettings->hWnd = v1;
    *(_OWORD *)&io_pPDSettings->threadLEngine.uStackSize = *(_OWORD *)&g_PDSettings.threadLEngine.uStackSize;
    *(_OWORD *)&io_pPDSettings->threadMonitor.nPriority = *(_OWORD *)&g_PDSettings.threadMonitor.nPriority;
    *(_OWORD *)&io_pPDSettings->fLEngineDefaultPoolRatioThreshold = *(_OWORD *)&g_PDSettings.fLEngineDefaultPoolRatioThreshold;
    io_pPDSettings->pXAudio2 = g_PDSettings.pXAudio2;
  }
  else
  {
    CAkLEngine::GetDefaultPlatformInitSettings(&g_PDSettings);
  }
}

// File Line: 136
// RVA: 0xA454A0
void __fastcall CAkLEngine::VPLDestroySource(CAkVPLSrcCbxNodeBase *in_pCbx, __int64 in_bNotify)
{
  CAkVPLSrcCbxNodeBase *v2; // rdi
  int v3; // ebx

  v2 = in_pCbx;
  (*(void (__fastcall **)(CAkVPLSrcCbxNodeBase *, __int64))in_pCbx->vfptr->gap8)(in_pCbx, in_bNotify);
  v3 = g_LEngineDefaultPoolId;
  v2->vfptr->__vecDelDtor(v2, 0);
  AK::MemoryMgr::Free(v3, v2);
}

// File Line: 175
// RVA: 0xA45150
void __fastcall MergeLastAndCurrentValues(AkAuxSendValueEx *in_pNewValues, AkMergedEnvironmentValue *io_paMergedValues, bool in_bFirstBufferConsumed, char *out_uNumSends)
{
  bool v4; // r13
  AkMergedEnvironmentValue *v5; // rsi
  AkAuxSendValueEx *v6; // r12
  unsigned int v7; // er15
  unsigned int v8; // er14
  signed __int64 v9; // rbx
  float v10; // xmm0_4
  unsigned __int64 v11; // rdi
  int v12; // eax
  void *v13; // rdx
  int v14; // ecx
  MapStruct<unsigned __int64,AkVPL *> *v15; // rax
  unsigned int v16; // er14
  __int64 v17; // rdx
  signed __int64 v18; // rcx
  unsigned int v19; // eax
  float v20; // xmm0_4
  AkAuxType v21; // eax
  int *v22; // rbx
  __int64 v23; // r12
  int v24; // er8
  unsigned int v25; // eax
  char *v26; // rcx
  unsigned int *v27; // rdx
  signed __int64 v28; // rdi
  int v29; // eax
  void *v30; // rdx
  int v31; // ecx
  int v32; // eax
  __int64 v33; // rbx
  signed int v34; // edi
  char *v35; // rbx
  void *v36; // rdx
  __int64 v37; // r15
  void *v38; // rdx
  int v39; // ecx
  char v40[16]; // [rsp+20h] [rbp-B8h]
  int v41; // [rsp+30h] [rbp-A8h]
  int v42; // [rsp+34h] [rbp-A4h]
  int v43[2]; // [rsp+38h] [rbp-A0h]
  void *in_pvMemAddress; // [rsp+40h] [rbp-98h]
  __int64 v45[2]; // [rsp+48h] [rbp-90h]
  __int64 v46; // [rsp+58h] [rbp-80h]
  __int64 v47; // [rsp+60h] [rbp-78h]
  __int64 v48; // [rsp+68h] [rbp-70h]
  __int64 v49; // [rsp+78h] [rbp-60h]
  __int64 v50; // [rsp+80h] [rbp-58h]
  __int64 v51; // [rsp+98h] [rbp-40h]
  __int64 v52; // [rsp+A0h] [rbp-38h]
  __int64 v53; // [rsp+B8h] [rbp-20h]
  __int64 v54; // [rsp+C0h] [rbp-18h]
  __int64 v55; // [rsp+D8h] [rbp+0h]
  __int64 v56; // [rsp+E0h] [rbp+8h]
  __int64 v57; // [rsp+F8h] [rbp+20h]
  __int64 v58; // [rsp+100h] [rbp+28h]
  char v59; // [rsp+118h] [rbp+40h]
  char *vars0; // [rsp+160h] [rbp+88h]
  CAkVPLSrcCbxNodeBase *retaddr; // [rsp+168h] [rbp+90h]

  v4 = in_bFirstBufferConsumed;
  v5 = io_paMergedValues;
  v6 = in_pNewValues;
  v7 = 0;
  in_pvMemAddress = 0i64;
  v45[0] = 0i64;
  v48 = 0i64;
  v46 = 0i64;
  v47 = 0i64;
  v49 = 0i64;
  v50 = 0i64;
  v51 = 0i64;
  v52 = 0i64;
  v53 = 0i64;
  v54 = 0i64;
  v55 = 0i64;
  v56 = 0i64;
  v57 = 0i64;
  v58 = 0i64;
  v8 = 0;
  if ( *out_uNumSends )
  {
    do
    {
      v9 = v8;
      v10 = v5[v9].fControlValue;
      if ( v10 > 0.0 )
      {
        v11 = 32i64 * v7;
        *(int *)((char *)&v41 + v11) = v5[v9].auxBusID;
        v12 = v5[v9].eAuxType;
        *(float *)((char *)&v42 + v11) = v10;
        v43[v11 / 4] = v12;
        v13 = *(&in_pvMemAddress + 4 * v7);
        if ( v13 )
        {
          v14 = g_DefaultPoolId;
          v45[v11 / 8] = 0i64;
          AK::MemoryMgr::Free(v14, v13);
          out_uNumSends = vars0;
          *(void **)((char *)&in_pvMemAddress + v11) = 0i64;
        }
        v15 = v5[v9].PerDeviceAuxBusses.m_pItems;
        ++v7;
        v5[v9].PerDeviceAuxBusses.m_pItems = 0i64;
        *(void **)((char *)&in_pvMemAddress + v11) = v15;
        LODWORD(v45[v11 / 8]) = v5[v9].PerDeviceAuxBusses.m_uLength;
        LODWORD(v15) = v5[v9].PerDeviceAuxBusses.m_ulReserved;
        *(_QWORD *)&v5[v9].PerDeviceAuxBusses.m_uLength = 0i64;
        HIDWORD(v45[v11 / 8]) = (_DWORD)v15;
      }
      ++v8;
    }
    while ( v8 < (unsigned __int8)*out_uNumSends );
  }
  v16 = 0;
  do
  {
    v17 = v16;
    v18 = v16;
    v19 = v6[v18].auxBusID;
    if ( !v19 )
      break;
    v20 = v6[v18].fControlValue;
    v5[v18].auxBusID = v19;
    v5[v18].fControlValue = v20;
    if ( v4 )
      v20 = 0.0;
    v21 = v6[v18].eAuxType;
    ++v16;
    v5[v18].fLastControlValue = v20;
    v5[v18].eAuxType = v21;
    v5[v18].PerDeviceAuxBusses.m_uLength = 0;
    v40[v17] = 0;
  }
  while ( v16 < 8 );
  if ( v7 )
  {
    v22 = (int *)((char *)v45 + 4);
    v23 = v7;
    while ( 1 )
    {
      v24 = *(v22 - 7);
      v25 = 0;
      if ( v16 )
        break;
LABEL_19:
      if ( v16 < 8 )
      {
        v28 = (signed __int64)&v5[v16];
        *(_DWORD *)(v28 + 4) = *(v22 - 6);
        v29 = *(v22 - 5);
        *(_DWORD *)(v28 + 8) = v24;
        *(_DWORD *)(v28 + 12) = v29;
        *(_DWORD *)v28 = 0;
        v30 = *(void **)(v28 + 16);
        if ( v30 )
        {
          v31 = g_DefaultPoolId;
          *(_DWORD *)(v28 + 24) = 0;
          AK::MemoryMgr::Free(v31, v30);
          *(_QWORD *)(v28 + 16) = 0i64;
          *(_DWORD *)(v28 + 28) = 0;
        }
        ++v16;
LABEL_23:
        *(_QWORD *)(v28 + 16) = *(_QWORD *)(v22 - 3);
        *(_DWORD *)(v28 + 24) = *(v22 - 1);
        v32 = *v22;
        *(_QWORD *)(v22 - 1) = 0i64;
        *(_DWORD *)(v28 + 28) = v32;
        *(_QWORD *)(v22 - 3) = 0i64;
      }
      v22 += 8;
      if ( !--v23 )
      {
        out_uNumSends = vars0;
        goto LABEL_26;
      }
    }
    v26 = v40;
    v27 = &v5->auxBusID;
    while ( *v27 != v24 || *v26 )
    {
      ++v25;
      v27 += 8;
      ++v26;
      if ( v25 >= v16 )
        goto LABEL_19;
    }
    v37 = v25;
    v28 = (signed __int64)&v5[v25];
    *(_DWORD *)(v28 + 4) = *(v22 - 6);
    v38 = *(void **)(v28 + 16);
    if ( v38 )
    {
      v39 = g_DefaultPoolId;
      *(_DWORD *)(v28 + 24) = 0;
      AK::MemoryMgr::Free(v39, v38);
      *(_QWORD *)(v28 + 16) = 0i64;
      *(_DWORD *)(v28 + 28) = 0;
    }
    v40[v37] = 1;
    goto LABEL_23;
  }
LABEL_26:
  *out_uNumSends = v16;
  if ( v16 )
  {
    v33 = v16;
    do
    {
      CAkLEngine::EnsureAuxBusExist(retaddr, v5);
      ++v5;
      --v33;
    }
    while ( v33 );
  }
  v34 = 7;
  v35 = &v59;
  do
  {
    v36 = (void *)*((_QWORD *)v35 - 4);
    v35 -= 32;
    if ( v36 )
    {
      *((_DWORD *)v35 + 2) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v36);
      *(_QWORD *)v35 = 0i64;
      *((_DWORD *)v35 + 3) = 0;
    }
    --v34;
  }
  while ( v34 >= 0 );
}

// File Line: 263
// RVA: 0xA45450
void __fastcall CAkLEngine::SetPanningRule(unsigned int in_iOutputID, AkSinkType in_eDeviceType, AkPanningRule in_panningRule)
{
  __int64 v3; // rax
  unsigned __int64 v4; // r9
  unsigned __int64 *v5; // rcx
  AkDevice *v6; // rax

  v3 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v4 = (signed int)in_eDeviceType | ((unsigned __int64)in_iOutputID << 32);
    v5 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *v5 != v4 )
    {
      v3 = (unsigned int)(v3 + 1);
      v5 += 10;
      if ( (unsigned int)v3 >= CAkOutputMgr::m_Devices.m_uLength )
        return;
    }
    v6 = &CAkOutputMgr::m_Devices.m_pItems[v3];
    if ( v6 )
    {
      v6->ePanningRule = in_panningRule;
      CAkListener::ResetListenerData();
    }
  }
}

// File Line: 274
// RVA: 0xA45140
void __fastcall CAkLEngine::GetDefaultOutputSettingsCommon(AkOutputSettings *out_settings)
{
  *out_settings = 0i64;
}

