// File Line: 61
// RVA: 0xA450A0
__int64 __fastcall CAkLEngine::CreateLEnginePools()
{
  unsigned int uLEngineDefaultPoolSize; // edx
  int Pool; // eax

  if ( g_LEngineDefaultPoolId != -1 )
    return 1i64;
  uLEngineDefaultPoolSize = 0x1000000;
  if ( g_PDSettings.uLEngineDefaultPoolSize > 0x40 )
    uLEngineDefaultPoolSize = g_PDSettings.uLEngineDefaultPoolSize;
  Pool = AK::MemoryMgr::CreatePool(0i64, uLEngineDefaultPoolSize, 0x40u, 1u, 0x10u);
  g_LEngineDefaultPoolId = Pool;
  if ( Pool != -1 )
  {
    AkFXMemAlloc::m_instanceLower.m_poolId = Pool;
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
  unsigned __int16 epi16; // ax

  if ( io_pPDSettings )
  {
    v1 = *(_OWORD *)&io_pPDSettings->hWnd;
    *(_OWORD *)&g_PDSettings.hWnd = *(_OWORD *)&io_pPDSettings->hWnd;
    *(_OWORD *)&g_PDSettings.threadLEngine.uStackSize = *(_OWORD *)&io_pPDSettings->threadLEngine.uStackSize;
    *(_OWORD *)&g_PDSettings.threadMonitor.nPriority = *(_OWORD *)&io_pPDSettings->threadMonitor.nPriority;
    epi16 = _mm_extract_epi16(*(__m128i *)&io_pPDSettings->fLEngineDefaultPoolRatioThreshold, 2);
    *(_OWORD *)&g_PDSettings.fLEngineDefaultPoolRatioThreshold = *(_OWORD *)&io_pPDSettings->fLEngineDefaultPoolRatioThreshold;
    g_PDSettings.pXAudio2 = io_pPDSettings->pXAudio2;
    if ( epi16 < 2u )
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
  int v3; // ebx

  (*(void (__fastcall **)(CAkVPLSrcCbxNodeBase *, __int64))in_pCbx->vfptr->gap8)(in_pCbx, in_bNotify);
  v3 = g_LEngineDefaultPoolId;
  in_pCbx->vfptr->__vecDelDtor(in_pCbx, 0i64);
  AK::MemoryMgr::Free(v3, in_pCbx);
}

// File Line: 175
// RVA: 0xA45150
void __fastcall MergeLastAndCurrentValues(
        AkAuxSendValueEx *in_pNewValues,
        AkMergedEnvironmentValue *io_paMergedValues,
        bool in_bFirstBufferConsumed,
        char *out_uNumSends)
{
  unsigned int v7; // r15d
  unsigned int i; // r14d
  __int64 v9; // rbx
  float fControlValue; // xmm0_4
  __int64 v11; // rdi
  AkAuxType eAuxType; // eax
  void *v13; // rdx
  int v14; // ecx
  MapStruct<unsigned __int64,AkVPL *> *m_pItems; // rax
  unsigned int v16; // r14d
  __int64 v17; // rdx
  __int64 v18; // rcx
  unsigned int auxBusID; // eax
  float v20; // xmm0_4
  AkAuxType v21; // eax
  unsigned int *v22; // rbx
  __int64 v23; // r12
  unsigned int v24; // r8d
  unsigned int v25; // eax
  char *v26; // rcx
  unsigned int *p_auxBusID; // rdx
  AkMergedEnvironmentValue *v28; // rdi
  AkAuxType v29; // eax
  MapStruct<unsigned __int64,AkVPL *> *v30; // rdx
  int v31; // ecx
  unsigned int v32; // eax
  __int64 v33; // rbx
  int v34; // edi
  char *v35; // rbx
  void *v36; // rdx
  __int64 v37; // r15
  MapStruct<unsigned __int64,AkVPL *> *v38; // rdx
  int v39; // ecx
  char v40[32]; // [rsp+20h] [rbp-B8h] BYREF
  void *in_pvMemAddress; // [rsp+40h] [rbp-98h]
  __int64 v42[26]; // [rsp+48h] [rbp-90h] BYREF
  char v43; // [rsp+118h] [rbp+40h] BYREF
  char *vars0; // [rsp+160h] [rbp+88h]
  CAkVPLSrcCbxNodeBase *retaddr; // [rsp+168h] [rbp+90h]

  v7 = 0;
  in_pvMemAddress = 0i64;
  v42[0] = 0i64;
  memset(&v42[2], 0, 24);
  v42[6] = 0i64;
  v42[7] = 0i64;
  v42[10] = 0i64;
  v42[11] = 0i64;
  v42[14] = 0i64;
  v42[15] = 0i64;
  v42[18] = 0i64;
  v42[19] = 0i64;
  v42[22] = 0i64;
  v42[23] = 0i64;
  for ( i = 0; i < (unsigned __int8)*out_uNumSends; ++i )
  {
    v9 = i;
    fControlValue = io_paMergedValues[v9].fControlValue;
    if ( fControlValue > 0.0 )
    {
      v11 = 4i64 * v7;
      *(_DWORD *)&v40[v11 * 8 + 16] = io_paMergedValues[v9].auxBusID;
      eAuxType = io_paMergedValues[v9].eAuxType;
      *(float *)&v40[v11 * 8 + 20] = fControlValue;
      *(_DWORD *)&v40[v11 * 8 + 24] = eAuxType;
      v13 = (void *)v42[v11 - 1];
      if ( v13 )
      {
        v14 = g_DefaultPoolId;
        v42[4 * v7] = 0i64;
        AK::MemoryMgr::Free(v14, v13);
        out_uNumSends = vars0;
        v42[4 * v7 - 1] = 0i64;
      }
      m_pItems = io_paMergedValues[v9].PerDeviceAuxBusses.m_pItems;
      ++v7;
      io_paMergedValues[v9].PerDeviceAuxBusses.m_pItems = 0i64;
      v42[v11 - 1] = (__int64)m_pItems;
      LODWORD(v42[v11]) = io_paMergedValues[v9].PerDeviceAuxBusses.m_uLength;
      LODWORD(m_pItems) = io_paMergedValues[v9].PerDeviceAuxBusses.m_ulReserved;
      *(_QWORD *)&io_paMergedValues[v9].PerDeviceAuxBusses.m_uLength = 0i64;
      HIDWORD(v42[v11]) = (_DWORD)m_pItems;
    }
  }
  v16 = 0;
  do
  {
    v17 = v16;
    v18 = v16;
    auxBusID = in_pNewValues[v18].auxBusID;
    if ( !auxBusID )
      break;
    v20 = in_pNewValues[v18].fControlValue;
    io_paMergedValues[v18].auxBusID = auxBusID;
    io_paMergedValues[v18].fControlValue = v20;
    if ( in_bFirstBufferConsumed )
      v20 = 0.0;
    v21 = in_pNewValues[v18].eAuxType;
    ++v16;
    io_paMergedValues[v18].fLastControlValue = v20;
    io_paMergedValues[v18].eAuxType = v21;
    io_paMergedValues[v18].PerDeviceAuxBusses.m_uLength = 0;
    v40[v17] = 0;
  }
  while ( v16 < 8 );
  if ( v7 )
  {
    v22 = (unsigned int *)v42 + 1;
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
        v28 = &io_paMergedValues[v16];
        LODWORD(v28->fLastControlValue) = *(v22 - 6);
        v29 = *(v22 - 5);
        v28->auxBusID = v24;
        v28->eAuxType = v29;
        v28->fControlValue = 0.0;
        v30 = v28->PerDeviceAuxBusses.m_pItems;
        if ( v30 )
        {
          v31 = g_DefaultPoolId;
          v28->PerDeviceAuxBusses.m_uLength = 0;
          AK::MemoryMgr::Free(v31, v30);
          v28->PerDeviceAuxBusses.m_pItems = 0i64;
          v28->PerDeviceAuxBusses.m_ulReserved = 0;
        }
        ++v16;
LABEL_23:
        v28->PerDeviceAuxBusses.m_pItems = *(MapStruct<unsigned __int64,AkVPL *> **)(v22 - 3);
        v28->PerDeviceAuxBusses.m_uLength = *(v22 - 1);
        v32 = *v22;
        *(_QWORD *)(v22 - 1) = 0i64;
        v28->PerDeviceAuxBusses.m_ulReserved = v32;
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
    p_auxBusID = &io_paMergedValues->auxBusID;
    while ( *p_auxBusID != v24 || *v26 )
    {
      ++v25;
      p_auxBusID += 8;
      ++v26;
      if ( v25 >= v16 )
        goto LABEL_19;
    }
    v37 = v25;
    v28 = &io_paMergedValues[v25];
    LODWORD(v28->fLastControlValue) = *(v22 - 6);
    v38 = v28->PerDeviceAuxBusses.m_pItems;
    if ( v38 )
    {
      v39 = g_DefaultPoolId;
      v28->PerDeviceAuxBusses.m_uLength = 0;
      AK::MemoryMgr::Free(v39, v38);
      v28->PerDeviceAuxBusses.m_pItems = 0i64;
      v28->PerDeviceAuxBusses.m_ulReserved = 0;
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
      CAkLEngine::EnsureAuxBusExist(retaddr, io_paMergedValues++);
      --v33;
    }
    while ( v33 );
  }
  v34 = 7;
  v35 = &v43;
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
void __fastcall CAkLEngine::SetPanningRule(unsigned int in_iOutputID, int in_eDeviceType, AkPanningRule in_panningRule)
{
  __int64 v3; // rax
  unsigned __int64 v4; // r9
  unsigned __int64 *i; // rcx
  AkDevice *v6; // rax

  v3 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v4 = in_eDeviceType | ((unsigned __int64)in_iOutputID << 32);
    for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i != v4; i += 10 )
    {
      v3 = (unsigned int)(v3 + 1);
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

