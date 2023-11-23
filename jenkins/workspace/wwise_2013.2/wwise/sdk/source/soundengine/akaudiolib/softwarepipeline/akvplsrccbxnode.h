// File Line: 94
// RVA: 0xA45130
CAkPBI *__fastcall CAkVPLSrcCbxNodeBase::GetContext(CAkVPLSrcCbxNodeBase *this)
{
  CAkPBI *result; // rax

  result = (CAkPBI *)this->m_pSources[0];
  if ( result )
    return result->pNextItem;
  return result;
}

// File Line: 159
// RVA: 0xA50CD0
void __fastcall CAkVPLSrcCbxNodeBase::CleanupAuxBusses(CAkVPLSrcCbxNodeBase *this)
{
  unsigned int i; // ebx
  char *v3; // rdi
  void *v4; // rdx

  for ( i = 0; i < (unsigned __int8)this->m_uNumSends; ++i )
  {
    v3 = (char *)this + 32 * i;
    v4 = (void *)*((_QWORD *)v3 + 14);
    if ( v4 )
    {
      *((_DWORD *)v3 + 30) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      *((_QWORD *)v3 + 14) = 0i64;
      *((_DWORD *)v3 + 31) = 0;
    }
  }
}

// File Line: 179
// RVA: 0xA50790
void __fastcall CAkVPLSrcCbxNodeBase::AddOutputBus(
        CAkVPLSrcCbxNodeBase *this,
        AkVPL *in_pVPL,
        unsigned __int64 in_uDeviceID,
        bool bCrossDeviceSend)
{
  AkDeviceInfo *v8; // rax
  AkDeviceInfo *v9; // rax
  AkDeviceInfo *v10; // rdx
  AkDeviceInfo *m_pFirst; // rax
  AkDevice *v12; // rbx
  __int64 v13; // rax
  unsigned __int64 *p_uDeviceID; // rcx
  unsigned int OutputConfig; // eax

  *((_BYTE *)this + 76) |= 0x40u;
  v8 = (AkDeviceInfo *)AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, 0x270ui64, 0x10u);
  if ( v8 )
  {
    AkDeviceInfo::AkDeviceInfo(v8, in_pVPL, in_uDeviceID, bCrossDeviceSend);
    v10 = v9;
    if ( v9 )
    {
      m_pFirst = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
      v12 = 0i64;
      if ( m_pFirst )
      {
        v10->pNextLightItem = m_pFirst;
        this->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v10;
      }
      else
      {
        this->m_OutputDevices.m_listDeviceVolumes.m_pFirst = v10;
        v10->pNextLightItem = 0i64;
      }
      ++this->m_OutputDevices.m_uNumDevices;
      v13 = 0i64;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *p_uDeviceID != in_uDeviceID )
        {
          v13 = (unsigned int)(v13 + 1);
          p_uDeviceID += 10;
          if ( (unsigned int)v13 >= CAkOutputMgr::m_Devices.m_uLength )
            goto LABEL_12;
        }
        v12 = &CAkOutputMgr::m_Devices.m_pItems[v13];
      }
LABEL_12:
      OutputConfig = AkDeviceInfo::GetOutputConfig(v10);
      if ( AkDevice::EnsurePanCacheExists(v12, OutputConfig) != AK_Success )
        CAkVPLSrcCbxNodeBase::RemoveOutputBus(this, in_pVPL);
    }
  }
}

// File Line: 195
// RVA: 0xA52980
void __fastcall CAkVPLSrcCbxNodeBase::RemoveOutputBus(CAkVPLSrcCbxNodeBase *this, AkVPL *in_pVPL)
{
  AkDeviceInfo *m_pFirst; // rax
  AkDeviceInfo *v3; // r8
  AkDeviceInfo *v5; // rbx
  bool v6; // zf
  AkDeviceInfo *pNextLightItem; // rax
  int v8; // edi

  *((_BYTE *)this + 76) |= 0x40u;
  m_pFirst = this->m_OutputDevices.m_listDeviceVolumes.m_pFirst;
  v3 = 0i64;
  v5 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v5->pMixBus != in_pVPL )
    {
      v3 = v5;
      v5 = v5->pNextLightItem;
      if ( !v5 )
        return;
    }
    v6 = v5 == m_pFirst;
    pNextLightItem = v5->pNextLightItem;
    if ( v6 )
      this->m_OutputDevices.m_listDeviceVolumes.m_pFirst = pNextLightItem;
    else
      v3->pNextLightItem = pNextLightItem;
    v8 = g_LEngineDefaultPoolId;
    ((void (__fastcall *)(AkDeviceInfo *, _QWORD, AkDeviceInfo *))v5->vfptr->__vecDelDtor)(v5, 0i64, v3);
    AK::MemoryMgr::Free(v8, v5);
    --this->m_OutputDevices.m_uNumDevices;
  }
}

// File Line: 338
// RVA: 0xA667D0
void __fastcall CAkVPLSrcCbxNode::GetAnalyzedEnvelope(CAkVPLSrcCbxNode *this)
{
  this->m_pSources[0]->vfptr[2].TimeSkip(
    this->m_pSources[0],
    (unsigned int *)this->m_cbxRec.m_Pitch.m_BufferIn.uValidFrames);
}

