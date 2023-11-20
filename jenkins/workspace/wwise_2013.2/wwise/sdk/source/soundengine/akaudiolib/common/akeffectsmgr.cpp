// File Line: 40
// RVA: 0x15BDF50
__int64 dynamic_initializer_for__CAkEffectsMgr::m_RegisteredFXList__()
{
  return atexit(dynamic_atexit_destructor_for__CAkEffectsMgr::m_RegisteredFXList__);
}

// File Line: 41
// RVA: 0x15BDF40
__int64 dynamic_initializer_for__CAkEffectsMgr::m_RegisteredCodecList__()
{
  return atexit(dynamic_atexit_destructor_for__CAkEffectsMgr::m_RegisteredCodecList__);
}

// File Line: 44
// RVA: 0x15BDF60
__int64 dynamic_initializer_for__CAkEffectsMgr::m_RegisteredFeedbackBus__()
{
  return atexit(dynamic_atexit_destructor_for__CAkEffectsMgr::m_RegisteredFeedbackBus__);
}

// File Line: 61
// RVA: 0xA4C890
signed __int64 __fastcall CAkEffectsMgr::Term()
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
signed __int64 __fastcall CAkEffectsMgr::RegisterPlugin(AkPluginType in_eType, unsigned int in_ulCompanyID, unsigned int in_ulPluginID, AK::IAkPlugin *(__fastcall *in_pCreateFunc)(AK::IAkPluginMemAlloc *), AK::IAkPluginParam *(__fastcall *in_pCreateParamFunc)(AK::IAkPluginMemAlloc *))
{
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v5; // r14
  unsigned int v6; // esi
  unsigned int v7; // er8
  AK::IAkPlugin *(__fastcall *v8)(AK::IAkPluginMemAlloc *); // r12
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v9; // rax
  unsigned __int64 v10; // r13
  unsigned __int32 v11; // esi
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v12; // rcx
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *i; // rax
  __int64 v15; // rbx
  CAkEffectsMgr::EffectTypeRecord *v16; // rdi
  __int64 v17; // rbp
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v21; // rax

  v5 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v6 = in_ulPluginID;
  v7 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
  v8 = in_pCreateFunc;
  v9 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v10 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
  v11 = (in_eType & 0xF) + 16 * (in_ulCompanyID + (v6 << 12));
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
      v16 = 0i64;
    }
    else
    {
      v16 = &i->item;
      if ( i != (MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *)-8i64 )
      {
        v16->pCreateFunc = in_pCreateFunc;
        i->item.pCreateParamFunc = in_pCreateParamFunc;
        return 2 - (unsigned int)(v16 != 0i64);
      }
    }
    LODWORD(v17) = CAkEffectsMgr::m_RegisteredFXList.m_ulReserved;
    if ( CAkEffectsMgr::m_RegisteredFXList.m_uLength >= (unsigned __int64)CAkEffectsMgr::m_RegisteredFXList.m_ulReserved )
    {
      v17 = CAkEffectsMgr::m_RegisteredFXList.m_ulReserved + 2;
      v5 = (MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v17);
      if ( !v5 )
        return 2 - (unsigned int)(v16 != 0i64);
      v18 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
      v7 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
      v19 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
      if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems )
      {
        if ( CAkEffectsMgr::m_RegisteredFXList.m_uLength )
        {
          do
          {
            v20 = *(_QWORD *)&v18[v15].key;
            ++v15;
            *(_QWORD *)&v5[v15 - 1].key = v20;
            *((_QWORD *)&v5[v15] - 2) = *((_QWORD *)&v18[v15] - 2);
            *((_QWORD *)&v5[v15] - 1) = *((_QWORD *)&v18[v15] - 1);
            v18 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
            --v19;
          }
          while ( v19 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        v7 = CAkEffectsMgr::m_RegisteredFXList.m_uLength;
      }
      CAkEffectsMgr::m_RegisteredFXList.m_pItems = v5;
      CAkEffectsMgr::m_RegisteredFXList.m_ulReserved = v17;
    }
    if ( v10 < (unsigned int)v17 )
    {
      CAkEffectsMgr::m_RegisteredFXList.m_uLength = v7 + 1;
      v21 = &v5[v7];
      if ( v21 )
      {
        v16 = &v21->item;
        v21->key = v11;
        v16->pCreateFunc = v8;
        v16->pCreateParamFunc = in_pCreateParamFunc;
      }
    }
    return 2 - (unsigned int)(v16 != 0i64);
  }
  return 31i64;
}= in_pCreateParamFunc;
      }
    }
    return 2 - (unsigned int)(v16 != 0i64);
  }
  r

// File Line: 122
// RVA: 0xA4C400
signed __int64 __fastcall CAkEffectsMgr::RegisterCodec(unsigned int in_ulCompanyID, unsigned int in_ulPluginID, IAkSoftwareCodec *(__fastcall *in_pFileCreateFunc)(void *), IAkSoftwareCodec *(__fastcall *in_pBankCreateFunc)(void *))
{
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v4; // r14
  IAkSoftwareCodec *(__fastcall *v5)(void *); // r15
  unsigned int v6; // er8
  IAkSoftwareCodec *(__fastcall *v7)(void *); // r12
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v8; // rax
  unsigned __int64 v9; // r13
  unsigned int v10; // esi
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v11; // rcx
  int v12; // esi
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *i; // rax
  __int64 v15; // rbx
  CAkEffectsMgr::CodecTypeRecord *v16; // rdi
  __int64 v17; // rbp
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v21; // rax

  v4 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
  v5 = in_pFileCreateFunc;
  v6 = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
  v7 = in_pBankCreateFunc;
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
  if ( v5 && in_pBankCreateFunc )
  {
    for ( i = CAkEffectsMgr::m_RegisteredCodecList.m_pItems; i != v11; ++i )
    {
      if ( i->key == v12 )
        break;
    }
    v15 = 0i64;
    if ( i == v11 )
    {
      v16 = 0i64;
    }
    else
    {
      v16 = &i->item;
      if ( i != (MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *)-8i64 )
      {
        v16->pFileCreateFunc = v5;
        i->item.pBankCreateFunc = in_pBankCreateFunc;
        return 2 - (unsigned int)(v16 != 0i64);
      }
    }
    LODWORD(v17) = CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved;
    if ( CAkEffectsMgr::m_RegisteredCodecList.m_uLength >= (unsigned __int64)CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved )
    {
      v17 = CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved + 2;
      v4 = (MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v17);
      if ( !v4 )
        return 2 - (unsigned int)(v16 != 0i64);
      v18 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
      v6 = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
      v19 = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
      if ( CAkEffectsMgr::m_RegisteredCodecList.m_pItems )
      {
        if ( CAkEffectsMgr::m_RegisteredCodecList.m_uLength )
        {
          do
          {
            v20 = *(_QWORD *)&v18[v15].key;
            ++v15;
            *(_QWORD *)&v4[v15 - 1].key = v20;
            *((_QWORD *)&v4[v15] - 2) = *((_QWORD *)&v18[v15] - 2);
            *((_QWORD *)&v4[v15] - 1) = *((_QWORD *)&v18[v15] - 1);
            v18 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
            --v19;
          }
          while ( v19 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v18);
        v6 = CAkEffectsMgr::m_RegisteredCodecList.m_uLength;
      }
      CAkEffectsMgr::m_RegisteredCodecList.m_pItems = v4;
      CAkEffectsMgr::m_RegisteredCodecList.m_ulReserved = v17;
    }
    if ( v9 < (unsigned int)v17 )
    {
      CAkEffectsMgr::m_RegisteredCodecList.m_uLength = v6 + 1;
      v21 = &v4[v6];
      if ( v21 )
      {
        v16 = &v21->item;
        v21->key = v12;
        v16->pFileCreateFunc = v5;
        v16->pBankCreateFunc = v7;
      }
    }
    return 2 - (unsigned int)(v16 != 0i64);
  }
  return 31i64;
}6->pBankCreateFunc = v7;
      }
    }
    return 2 - (unsigned int)(v16 != 0i64);
 

// File Line: 155
// RVA: 0xA4C1F0
signed __int64 __fastcall CAkEffectsMgr::Alloc(AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_EffectTypeID, AK::IAkPlugin **out_pEffect)
{
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v3; // rax
  AK::IAkPlugin **v4; // rbx
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v5; // r9
  CAkEffectsMgr::EffectTypeRecord *v6; // rax
  __int64 v7; // rax

  *out_pEffect = 0i64;
  v3 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v4 = out_pEffect;
  v5 = &CAkEffectsMgr::m_RegisteredFXList.m_pItems[CAkEffectsMgr::m_RegisteredFXList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems == v5 )
    return 2i64;
  do
  {
    if ( v3->key == in_EffectTypeID )
      break;
    ++v3;
  }
  while ( v3 != v5 );
  if ( v3 == v5 )
    return 2i64;
  v6 = &v3->item;
  if ( !v6 )
    return 2i64;
  v7 = (__int64)v6->pCreateFunc(in_pAllocator);
  *v4 = (AK::IAkPlugin *)v7;
  return 2 - (unsigned int)(v7 != 0);
}

// File Line: 184
// RVA: 0xA4C380
signed __int64 __fastcall CAkEffectsMgr::AllocParams(AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_EffectTypeID, AK::IAkPluginParam **out_pEffectParam)
{
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v3; // rax
  AK::IAkPluginParam **v4; // rbx
  MapStruct<unsigned long,CAkEffectsMgr::EffectTypeRecord> *v5; // r9
  signed __int64 v6; // rax
  __int64 (__fastcall *v7)(AK::IAkPluginMemAlloc *); // rdx
  __int64 v9; // rax

  *out_pEffectParam = 0i64;
  v3 = CAkEffectsMgr::m_RegisteredFXList.m_pItems;
  v4 = out_pEffectParam;
  v5 = &CAkEffectsMgr::m_RegisteredFXList.m_pItems[CAkEffectsMgr::m_RegisteredFXList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredFXList.m_pItems == v5 )
    return 2i64;
  do
  {
    if ( v3->key == in_EffectTypeID )
      break;
    ++v3;
  }
  while ( v3 != v5 );
  if ( v3 == v5 )
    return 2i64;
  v6 = (signed __int64)&v3->item;
  if ( !v6 )
    return 2i64;
  v7 = *(__int64 (__fastcall **)(AK::IAkPluginMemAlloc *))(v6 + 8);
  if ( !v7 )
    return 1i64;
  v9 = v7(in_pAllocator);
  *v4 = (AK::IAkPluginParam *)v9;
  return 2 - (unsigned int)(v9 != 0);
}

// File Line: 217
// RVA: 0xA4C260
IAkSoftwareCodec *__fastcall CAkEffectsMgr::AllocCodec(CAkPBI *in_pCtx, unsigned int in_uSrcType, unsigned int in_CodecID)
{
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v3; // rax
  MapStruct<unsigned long,CAkEffectsMgr::CodecTypeRecord> *v4; // r9
  CAkEffectsMgr::CodecTypeRecord *v5; // rax

  v3 = CAkEffectsMgr::m_RegisteredCodecList.m_pItems;
  v4 = &CAkEffectsMgr::m_RegisteredCodecList.m_pItems[CAkEffectsMgr::m_RegisteredCodecList.m_uLength];
  if ( CAkEffectsMgr::m_RegisteredCodecList.m_pItems == v4 )
    return 0i64;
  do
  {
    if ( v3->key == in_CodecID )
      break;
    ++v3;
  }
  while ( v3 != v4 );
  if ( v3 == v4 )
    return 0i64;
  v5 = &v3->item;
  if ( !v5 )
    return 0i64;
  if ( in_uSrcType == 1 )
    return (IAkSoftwareCodec *)v5->pFileCreateFunc(in_pCtx);
  return (IAkSoftwareCodec *)v5->pBankCreateFunc(in_pCtx);
}

// File Line: 247
// RVA: 0xA4C5E0
signed __int64 __fastcall CAkEffectsMgr::RegisterFeedbackBus(unsigned int in_iCompanyID, unsigned int in_iBusPluginID, AK::IAkPlugin *(__fastcall *in_pCreateMixNodeFunc)(AK::IAkPluginMemAlloc *))
{
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v3; // rax
  AK::IAkPlugin *(__fastcall *v4)(AK::IAkPluginMemAlloc *); // rdi
  unsigned int v5; // ebx
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v6; // rdx
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v7; // rcx
  int i; // ebx
  signed __int64 result; // rax
  AK::IAkPlugin *(__fastcall **v10)(AK::IAkPluginMemAlloc *); // rax
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v11; // rax

  v3 = CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems;
  v4 = in_pCreateMixNodeFunc;
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
    goto LABEL_18;
  do
  {
    if ( v3->key == i )
      break;
    ++v3;
  }
  while ( v3 != v6 );
  if ( v3 != v6 && (v10 = &v3->item) != 0i64 )
  {
    *v10 = in_pCreateMixNodeFunc;
    result = 1i64;
  }
  else
  {
LABEL_18:
    v11 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&CAkEffectsMgr::m_RegisteredFeedbackBus);
    if ( v11 )
    {
      LODWORD(v11->key) = i;
      v11->item = (CAkContainerBaseInfo *)v4;
    }
    result = 1i64;
  }
  return result;
}

// File Line: 265
// RVA: 0xA4C2B0
__int64 __fastcall CAkEffectsMgr::AllocFeedbackBus(unsigned int in_iCompanyID, unsigned int in_iPluginID, AkPlatformInitSettings *io_pPDSettings, char in_iPlayer, IAkMotionMixBus **out_pMixNode, void *in_pDevice)
{
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v6; // rax
  unsigned __int8 v7; // di
  unsigned int v8; // edx
  AkPlatformInitSettings *v9; // rsi
  MapStruct<unsigned long,AK::IAkPlugin * (__cdecl*)(AK::IAkPluginMemAlloc *)> *v10; // rcx
  __int64 v11; // rdx
  __int64 (__fastcall **v12)(AkFXMemAlloc *, __int64); // rax
  IAkMotionMixBus *v13; // rax
  __int64 result; // rax

  v6 = CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems;
  v7 = in_iPlayer;
  v8 = in_iCompanyID + (in_iPluginID << 12);
  v9 = io_pPDSettings;
  v10 = &CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems[CAkEffectsMgr::m_RegisteredFeedbackBus.m_uLength];
  v11 = 16 * v8 + 4;
  if ( CAkEffectsMgr::m_RegisteredFeedbackBus.m_pItems != v10 )
  {
    do
    {
      if ( v6->key == (_DWORD)v11 )
        break;
      ++v6;
    }
    while ( v6 != v10 );
  }
  if ( v6 != v10 )
  {
    v12 = (__int64 (__fastcall **)(AkFXMemAlloc *, __int64))&v6->item;
    if ( v12 )
    {
      v13 = (IAkMotionMixBus *)(*v12)(&AkFXMemAlloc::m_instanceLower, v11);
      *out_pMixNode = v13;
      if ( v13 )
      {
        result = ((__int64 (__fastcall *)(IAkMotionMixBus *, AkFXMemAlloc *, AkPlatformInitSettings *, _QWORD, void *))v13->vfptr[1].__vecDelDtor)(
                   v13,
                   &AkFXMemAlloc::m_instanceLower,
                   v9,
                   v7,
                   in_pDevice);
        if ( (_DWORD)result == 1 )
          return result;
        (*out_pMixNode)->vfptr->Term(
          (AK::IAkPlugin *)*out_pMixNode,
          (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower);
        *out_pMixNode = 0i64;
      }
    }
  }
  return 2i64;
}

