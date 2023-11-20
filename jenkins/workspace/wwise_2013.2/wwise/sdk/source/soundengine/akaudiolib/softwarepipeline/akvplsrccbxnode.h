// File Line: 94
// RVA: 0xA45130
CAkPBI *__fastcall CAkVPLSrcCbxNodeBase::GetContext(CAkVPLSrcCbxNodeBase *this)
{
  CAkPBI *result; // rax

  result = (CAkPBI *)this->m_pSources[0];
  if ( result )
    result = result->pNextItem;
  return result;
}

// File Line: 159
// RVA: 0xA50CD0
void __fastcall CAkVPLSrcCbxNodeBase::CleanupAuxBusses(CAkVPLSrcCbxNodeBase *this)
{
  CAkVPLSrcCbxNodeBase *v1; // rsi
  unsigned int v2; // ebx
  signed __int64 v3; // rdi
  void *v4; // rdx

  v1 = this;
  v2 = 0;
  if ( this->m_uNumSends )
  {
    do
    {
      v3 = (signed __int64)v1 + 32 * v2;
      v4 = *(void **)(v3 + 112);
      if ( v4 )
      {
        *(_DWORD *)(v3 + 120) = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v4);
        *(_QWORD *)(v3 + 112) = 0i64;
        *(_DWORD *)(v3 + 124) = 0;
      }
      ++v2;
    }
    while ( v2 < (unsigned __int8)v1->m_uNumSends );
  }
}

// File Line: 179
// RVA: 0xA50790
void __fastcall CAkVPLSrcCbxNodeBase::AddOutputBus(CAkVPLSrcCbxNodeBase *this, AkVPL *in_pVPL, unsigned __int64 in_uDeviceID, bool bCrossDeviceSend)
{
  CAkVPLSrcCbxNodeBase *v4; // rdi
  unsigned __int64 v5; // rsi
  AkVPL *v6; // rbp
  bool v7; // bl
  AkDeviceInfo *v8; // rax
  AkDeviceInfo *v9; // rax
  AkDeviceInfo *v10; // rdx
  AkDeviceInfo *v11; // rax
  AkDevice *v12; // rbx
  __int64 v13; // rax
  unsigned __int64 *v14; // rcx
  unsigned int v15; // eax

  *((_BYTE *)this + 76) |= 0x40u;
  v4 = this;
  v5 = in_uDeviceID;
  v6 = in_pVPL;
  v7 = bCrossDeviceSend;
  v8 = (AkDeviceInfo *)AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, 0x270ui64, 0x10u);
  if ( v8 )
  {
    AkDeviceInfo::AkDeviceInfo(v8, v6, v5, v7);
    v10 = v9;
    if ( v9 )
    {
      v11 = v4->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
      v12 = 0i64;
      if ( v11 )
      {
        v10->pNextLightItem = v11;
        v4->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v10;
      }
      else
      {
        v4->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v10;
        v10->pNextLightItem = 0i64;
      }
      ++v4->m_OutputDevices.m_uNumDevices;
      v13 = 0i64;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        v14 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *v14 != v5 )
        {
          v13 = (unsigned int)(v13 + 1);
          v14 += 10;
          if ( (unsigned int)v13 >= CAkOutputMgr::m_Devices.m_uLength )
            goto LABEL_12;
        }
        v12 = &CAkOutputMgr::m_Devices.m_pItems[v13];
      }
LABEL_12:
      v15 = AkDeviceInfo::GetOutputConfig(v10);
      if ( AkDevice::EnsurePanCacheExists(v12, v15) != 1 )
        CAkVPLSrcCbxNodeBase::RemoveOutputBus(v4, v6);
    }
  }
}

// File Line: 195
// RVA: 0xA52980
void __fastcall CAkVPLSrcCbxNodeBase::RemoveOutputBus(CAkVPLSrcCbxNodeBase *this, AkVPL *in_pVPL)
{
  AkDeviceInfo *v2; // rax
  AkDeviceInfo *v3; // r8
  CAkVPLSrcCbxNodeBase *v4; // rsi
  AkDeviceInfo *v5; // rbx
  bool v6; // zf
  AkDeviceInfo *v7; // rax
  int v8; // edi

  *((_BYTE *)this + 76) |= 0x40u;
  v2 = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
  v3 = 0i64;
  v4 = this;
  v5 = v2;
  if ( v2 )
  {
    while ( v5->pMixBus != in_pVPL )
    {
      v3 = v5;
      v5 = v5->pNextLightItem;
      if ( !v5 )
        return;
    }
    v6 = v5 == v2;
    v7 = v5->pNextLightItem;
    if ( v6 )
      this->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v7;
    else
      v3->pNextLightItem = v7;
    v8 = g_LEngineDefaultPoolId;
    ((void (__fastcall *)(AkDeviceInfo *, _QWORD, AkDeviceInfo *))v5->vfptr->__vecDelDtor)(v5, 0i64, v3);
    AK::MemoryMgr::Free(v8, v5);
    --v4->m_OutputDevices.m_uNumDevices;
  }
}

// File Line: 338
// RVA: 0xA667D0
void __fastcall CAkVPLSrcCbxNode::GetAnalyzedEnvelope(CAkVPLSrcCbxNode *this)
{
  this->m_pSources[0]->vfptr[2].TimeSkip(
    (CAkVPLNode *)this->m_pSources[0],
    (unsigned int *)this->m_cbxRec.m_Pitch.m_BufferIn.uValidFrames);
}

