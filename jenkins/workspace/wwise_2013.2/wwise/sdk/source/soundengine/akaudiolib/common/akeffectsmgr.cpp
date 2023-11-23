// File Line: 40
// RVA: 0x15BDF50
__int64 dynamic_initializer_for__CAkEffectsMgr::m_RegisteredFXList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkEffectsMgr::m_RegisteredFXList__);
}

// File Line: 41
// RVA: 0x15BDF40
__int64 dynamic_initializer_for__CAkEffectsMgr::m_RegisteredCodecList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkEffectsMgr::m_RegisteredCodecList__);
}

// File Line: 44
// RVA: 0x15BDF60
__int64 dynamic_initializer_for__CAkEffectsMgr::m_RegisteredFeedbackBus__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkEffectsMgr::m_RegisteredFeedbackBus__);
}

// File Line: 61
// RVA: 0xA4C890
__int64 __fastcall CAkEffectsMgr::Term()
{
  if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems )
  {
    CAkEffectsMgr::m_RegisteredFXList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, CAkEffectsMgr::m_RegisteredFXList.m_pItems);
    CAkEffectsMgr::m_RegisteredFXList.m_pItems = 0i64;
    CAkEffectsMgr::m_RegisteredFXList.m_ulReserved = 0;
  }
  if ( CAkEffectsMgr::m_RegisteredCodecList.m_pItems )
  {
    CAkEffectsMgr::m_RegisteredCodecList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, CAkEffectsMgr::m_RegisteredCodecList.m_pItems);
    CAkEffectsMgr::m_RegisteredCodecList.m_pItems = 0i64;
    CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved = 0;
  }
  if ( CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems )
  {
    CAkEffectsMgr::m_RegisteredFeedbackBus.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems);
    CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems = 0i64;
    CAkEffectsMgr::m_RegisteredFeedbackBus.m_ulReserved = 0;
  }
  return 1i64;
}

// File Line: 87
// RVA: 0xA4C6A0
__int64 __fastcall CAkEffectsMgr::RegisterPlugin(
        AkPluginType in_eType,
        unsigned int in_ulCompanyID,
        unsigned int in_ulPluginID,
        AK::IAkPlugin *(__fastcall *in_pCreateFunc)(AK::IAkPluginMemAlloc *),
        AK::IAkPluginParam *(__fastcall *in_pCreateParamFunc)(AK::IAkPluginMemAlloc *))
{
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *m_pItems; // r14
  unsigned int m_uLength; // r8d
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v9; // rax
  unsigned __int64 v10; // r13
  unsigned __int32 v11; // esi
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v12; // rcx
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *i; // rax
  __int64 v15; // rbx
  CAkEffectsMgr::EffectTypeRecord *p_item; // rdi
  __int64 v17; // rbp
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v21; // rax

  m_pItems = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  m_uLength = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
  v9 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v10 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
  v11 = (in_eType & 0xF) + 16 * (in_ulCompanyID + (in_ulPluginID << 12));
  v12 = &CAkEffectsMgr::m_RegisteredFXList.m_pItems[CAkEffectsMgr::m_RegisteredFXList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems != v12 )
  {
    do
    {
      if ( v9->key == v11 )
        break;
      ++v9;
    }
    while ( v9 != v12 );
  }
  if ( v9 != v12 && v9 != (MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *)-8i64 )
    return 2i64;
  if ( in_pCreateFunc && in_pCreateParamFunc )
  {
    for ( i = CAkEffectsMgr::m_RegisteredFXList.m_pItems; i != v12; ++i )
    {
      if ( i->key == v11 )
        break;
    }
    v15 = 0i64;
    if ( i == v12 )
    {
      p_item = 0i64;
    }
    else
    {
      p_item = &i->item;
      if ( i != (MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *)-8i64 )
      {
        p_item->pCreateFunc = in_pCreateFunc;
        i->item.pCreateParamFunc = in_pCreateParamFunc;
        return 2 - (unsigned int)(p_item != 0i64);
      }
    }
    LODWORD(v17) = CAkEffectsMgr::m_RegisteredFXList.m_ulReserved;
    if ( CAkEffectsMgr::m_RegisteredFXList.m_uLength >= (unsigned __int64)CAkEffectsMgr::m_RegisteredFXList.m_ulReserved )
    {
      v17 = CAkEffectsMgr::m_RegisteredFXList.m_ulReserved + 2;
      m_pItems = (MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *)AK::MemoryMgr::Malloc(
                                                                               g_DefaultPoolId,
                                                                               24 * v17);
      if ( !m_pItems )
        return 2 - (unsigned int)(p_item != 0i64);
      v18 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
      m_uLength = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
      v19 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
      if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems )
      {
        if ( CAkEffectsMgr::m_RegisteredFXList.m_uLength )
        {
          do
          {
            v20 = *(_QWORD *)&v18[v15++].key;
            *(_QWORD *)&m_pItems[v15 - 1].key = v20;
            m_pItems[v15 - 1].item.pCreateFunc = v18[v15 - 1].item.pCreateFunc;
            m_pItems[v15 - 1].item.pCreateParamFunc = v18[v15 - 1].item.pCreateParamFunc;
            v18 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
            --v19;
          }
          while ( v19 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        m_uLength = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
      }
      CAkEffectsMgr::m_RegisteredFXList.m_pItems = m_pItems;
      CAkEffectsMgr::m_RegisteredFXList.m_ulReserved = v17;
    }
    if ( v10 < (unsigned int)v17 )
    {
      CAkEffectsMgr::m_RegisteredFXList.m_uLength = m_uLength + 1;
      v21 = &m_pItems[m_uLength];
      if ( v21 )
      {
        p_item = &v21->item;
        v21->key = v11;
        v21->item.pCreateFunc = in_pCreateFunc;
        v21->item.pCreateParamFunc = in_pCreateParamFunc;
      }
    }
    return 2 - (unsigned int)(p_item != 0i64);
  }
  return 31i64;
}

// File Line: 122
// RVA: 0xA4C400
__int64 __fastcall CAkEffectsMgr::RegisterCodec(
        unsigned int in_ulCompanyID,
        unsigned int in_ulPluginID,
        IAkSoftwareCodec *(__fastcall *in_pFileCreateFunc)(void *),
        IAkSoftwareCodec *(__fastcall *in_pBankCreateFunc)(void *))
{
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *m_pItems; // r14
  unsigned int m_uLength; // r8d
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v8; // rax
  unsigned __int64 v9; // r13
  int v10; // esi
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v11; // rcx
  int v12; // esi
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *i; // rax
  __int64 v15; // rbx
  CAkEffectsMgr::CodecTypeRecord *p_item; // rdi
  __int64 v17; // rbp
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v21; // rax

  m_pItems = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
  m_uLength = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
  v8 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
  v9 = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
  v10 = in_ulCompanyID + (in_ulPluginID << 12);
  v11 = &CAkEffectsMgr::m_RegisteredCodecList.m_pItems[CAkEffectsMgr::m_RegisteredCodecList.m_uLength];
  v12 = 16 * v10 + 1;
  if ( CAkEffectsMgr::m_RegisteredCodecList.m_pItems != v11 )
  {
    do
    {
      if ( v8->key == v12 )
        break;
      ++v8;
    }
    while ( v8 != v11 );
  }
  if ( v8 != v11 && v8 != (MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *)-8i64 )
    return 2i64;
  if ( in_pFileCreateFunc && in_pBankCreateFunc )
  {
    for ( i = CAkEffectsMgr::m_RegisteredCodecList.m_pItems; i != v11; ++i )
    {
      if ( i->key == v12 )
        break;
    }
    v15 = 0i64;
    if ( i == v11 )
    {
      p_item = 0i64;
    }
    else
    {
      p_item = &i->item;
      if ( i != (MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *)-8i64 )
      {
        p_item->pFileCreateFunc = in_pFileCreateFunc;
        i->item.pBankCreateFunc = in_pBankCreateFunc;
        return 2 - (unsigned int)(p_item != 0i64);
      }
    }
    LODWORD(v17) = CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved;
    if ( CAkEffectsMgr::m_RegisteredCodecList.m_uLength >= (unsigned __int64)CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved )
    {
      v17 = CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved + 2;
      m_pItems = (MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *)AK::MemoryMgr::Malloc(
                                                                              g_DefaultPoolId,
                                                                              24 * v17);
      if ( !m_pItems )
        return 2 - (unsigned int)(p_item != 0i64);
      v18 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
      m_uLength = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
      v19 = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
      if ( CAkEffectsMgr::m_RegisteredCodecList.m_pItems )
      {
        if ( CAkEffectsMgr::m_RegisteredCodecList.m_uLength )
        {
          do
          {
            v20 = *(_QWORD *)&v18[v15++].key;
            *(_QWORD *)&m_pItems[v15 - 1].key = v20;
            m_pItems[v15 - 1].item.pFileCreateFunc = v18[v15 - 1].item.pFileCreateFunc;
            m_pItems[v15 - 1].item.pBankCreateFunc = v18[v15 - 1].item.pBankCreateFunc;
            v18 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
            --v19;
          }
          while ( v19 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        m_uLength = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
      }
      CAkEffectsMgr::m_RegisteredCodecList.m_pItems = m_pItems;
      CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved = v17;
    }
    if ( v9 < (unsigned int)v17 )
    {
      CAkEffectsMgr::m_RegisteredCodecList.m_uLength = m_uLength + 1;
      v21 = &m_pItems[m_uLength];
      if ( v21 )
      {
        p_item = &v21->item;
        v21->key = v12;
        v21->item.pFileCreateFunc = in_pFileCreateFunc;
        v21->item.pBankCreateFunc = in_pBankCreateFunc;
      }
    }
    return 2 - (unsigned int)(p_item != 0i64);
  }
  return 31i64;
}

// File Line: 155
// RVA: 0xA4C1F0
__int64 __fastcall CAkEffectsMgr::Alloc(
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_EffectTypeID,
        AK::IAkPlugin **out_pEffect)
{
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *m_pItems; // rax
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v5; // r9
  CAkEffectsMgr::EffectTypeRecord *p_item; // rax
  AK::IAkPlugin *v7; // rax

  *out_pEffect = 0i64;
  m_pItems = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v5 = &CAkEffectsMgr::m_RegisteredFXList.m_pItems[CAkEffectsMgr::m_RegisteredFXList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems == v5 )
    return 2i64;
  do
  {
    if ( m_pItems->key == in_EffectTypeID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 )
    return 2i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 2i64;
  v7 = p_item->pCreateFunc(in_pAllocator);
  *out_pEffect = v7;
  return 2 - (unsigned int)(v7 != 0i64);
}

// File Line: 184
// RVA: 0xA4C380
__int64 __fastcall CAkEffectsMgr::AllocParams(
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_EffectTypeID,
        AK::IAkPluginParam **out_pEffectParam)
{
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *m_pItems; // rax
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v5; // r9
  CAkEffectsMgr::EffectTypeRecord *p_item; // rax
  AK::IAkPluginParam *(__fastcall *pCreateParamFunc)(AK::IAkPluginMemAlloc *); // rdx
  AK::IAkPluginParam *v9; // rax

  *out_pEffectParam = 0i64;
  m_pItems = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v5 = &CAkEffectsMgr::m_RegisteredFXList.m_pItems[CAkEffectsMgr::m_RegisteredFXList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems == v5 )
    return 2i64;
  do
  {
    if ( m_pItems->key == in_EffectTypeID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 )
    return 2i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 2i64;
  pCreateParamFunc = p_item->pCreateParamFunc;
  if ( !pCreateParamFunc )
    return 1i64;
  v9 = pCreateParamFunc(in_pAllocator);
  *out_pEffectParam = v9;
  return 2 - (unsigned int)(v9 != 0i64);
}

// File Line: 217
// RVA: 0xA4C260
IAkSoftwareCodec *__fastcall CAkEffectsMgr::AllocCodec(
        CAkPBI *in_pCtx,
        unsigned int in_uSrcType,
        unsigned int in_CodecID)
{
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *m_pItems; // rax
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v4; // r9
  CAkEffectsMgr::CodecTypeRecord *p_item; // rax

  m_pItems = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
  v4 = &CAkEffectsMgr::m_RegisteredCodecList.m_pItems[CAkEffectsMgr::m_RegisteredCodecList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredCodecList.m_pItems == v4 )
    return 0i64;
  do
  {
    if ( m_pItems->key == in_CodecID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v4 );
  if ( m_pItems == v4 )
    return 0i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 0i64;
  if ( in_uSrcType == 1 )
    return p_item->pFileCreateFunc(in_pCtx);
  return p_item->pBankCreateFunc(in_pCtx);
}

// File Line: 247
// RVA: 0xA4C5E0
__int64 __fastcall CAkEffectsMgr::RegisterFeedbackBus(
        unsigned int in_iCompanyID,
        unsigned int in_iBusPluginID,
        CAkContainerBaseInfo *in_pCreateMixNodeFunc)
{
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *m_pItems; // rax
  int v5; // ebx
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v6; // rdx
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v7; // rcx
  int i; // ebx
  AK::IAkPlugin *(__fastcall **p_item)(AK::IAkPluginMemAlloc *); // rax
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v11; // rax

  m_pItems = CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems;
  v5 = in_iCompanyID + (in_iBusPluginID << 12);
  v6 = &CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems[CAkEffectsMgr::m_RegisteredFeedbackBus.m_uLength];
  v7 = CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems;
  for ( i = 16 * v5 + 4; v7 != v6; ++v7 )
  {
    if ( v7->key == i )
      break;
  }
  if ( v7 != v6 && v7 != (MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *)-8i64 )
    return 2i64;
  if ( CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems == v6 )
    goto LABEL_13;
  do
  {
    if ( m_pItems->key == i )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v6 );
  if ( m_pItems == v6 || (p_item = &m_pItems->item) == 0i64 )
  {
LABEL_13:
    v11 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&CAkEffectsMgr::m_RegisteredFeedbackBus);
    if ( v11 )
    {
      LODWORD(v11->key) = i;
      v11->item = in_pCreateMixNodeFunc;
    }
    return 1i64;
  }
  else
  {
    *p_item = (AK::IAkPlugin *(__fastcall *)(AK::IAkPluginMemAlloc *))in_pCreateMixNodeFunc;
    return 1i64;
  }
}

// File Line: 265
// RVA: 0xA4C2B0
__int64 __fastcall CAkEffectsMgr::AllocFeedbackBus(
        unsigned int in_iCompanyID,
        unsigned int in_iPluginID,
        AkPlatformInitSettings *io_pPDSettings,
        unsigned __int8 in_iPlayer,
        AK::IAkPlugin **out_pMixNode,
        void *in_pDevice)
{
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *m_pItems; // rax
  int v8; // edx
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v10; // rcx
  __int64 v11; // rdx
  __int64 (__fastcall **p_item)(AkFXMemAlloc *, __int64); // rax
  IAkMotionMixBus *v13; // rax
  __int64 result; // rax

  m_pItems = CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems;
  v8 = in_iCompanyID + (in_iPluginID << 12);
  v10 = &CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems[CAkEffectsMgr::m_RegisteredFeedbackBus.m_uLength];
  v11 = (unsigned int)(16 * v8 + 4);
  if ( CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems != v10 )
  {
    do
    {
      if ( m_pItems->key == (_DWORD)v11 )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v10 );
  }
  if ( m_pItems != v10 )
  {
    p_item = (__int64 (__fastcall **)(AkFXMemAlloc *, __int64))&m_pItems->item;
    if ( p_item )
    {
      v13 = (IAkMotionMixBus *)(*p_item)(&AkFXMemAlloc::m_instanceLower, v11);
      *out_pMixNode = v13;
      if ( v13 )
      {
        result = ((__int64 (__fastcall *)(IAkMotionMixBus *, AkFXMemAlloc *, AkPlatformInitSettings *, _QWORD, void *))v13->vfptr[1].__vecDelDtor)(
                   v13,
                   &AkFXMemAlloc::m_instanceLower,
                   io_pPDSettings,
                   in_iPlayer,
                   in_pDevice);
        if ( (_DWORD)result == 1 )
          return result;
        (*out_pMixNode)->vfptr->Term(*out_pMixNode, &AkFXMemAlloc::m_instanceLower);
        *out_pMixNode = 0i64;
      }
    }
  }
  return 2i64;
}

