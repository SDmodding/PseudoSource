// File Line: 21
// RVA: 0x15BAB0
AK::IAkPluginParam *__fastcall CreateGrainPlayerSourceParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 48ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkPluginParam::`vftable;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcGrainPlayerParams::`vftable;
  result[4].vfptr = 0i64;
  return result;
}

// File Line: 60
// RVA: 0x15BB10
void __fastcall CAkFxSrcGrainPlayerDataBlock::Destroy(CAkFxSrcGrainPlayerDataBlock *this)
{
  bool v1; // zf
  CAkFxSrcGrainPlayerDataBlock *v2; // rbx
  AK::IAkPluginMemAlloc *v3; // rcx

  v1 = this->m_refCount-- == 1;
  v2 = this;
  if ( v1 )
  {
    if ( this->m_pDataBlock )
    {
      ((void (*)(void))this->m_allocator->vfptr->Free)();
      v2->m_pDataBlock = 0i64;
      v2->m_blockSize = 0i64;
    }
    v3 = v2->m_allocator;
    v2->m_refCount = 0;
    v3->vfptr->Free(v3, v2);
  }
}

// File Line: 104
// RVA: 0x15BA20
AK::IAkPluginParam *__fastcall CAkFxSrcGrainPlayerParams::Clone(CAkFxSrcGrainPlayerParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFxSrcGrainPlayerParams *v2; // rbx
  AK::IAkPluginParam *result; // rax
  CAkFxSrcGrainPlayerDataBlock *v4; // rdx

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 48ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkPluginParam::`vftable;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcGrainPlayerParams::`vftable;
  v4 = v2->m_dataBlock;
  result[4].vfptr = (AK::IAkRTPCSubscriberVtbl *)v4;
  result[1].vfptr = *(AK::IAkRTPCSubscriberVtbl **)&v2->m_Params.fFrequency;
  result[2].vfptr = *(AK::IAkRTPCSubscriberVtbl **)&v2->m_Params.fDuration;
  result[3].vfptr = (AK::IAkRTPCSubscriberVtbl *)v2->m_Params.pData;
  result[5].vfptr = (AK::IAkRTPCSubscriberVtbl *)v2->m_allocator;
  ++v4->m_refCount;
  return result;
}

// File Line: 113
// RVA: 0x15BB60
__int64 __fastcall CAkFxSrcGrainPlayerParams::Init(CAkFxSrcGrainPlayerParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  size_t v4; // rsi
  const void *v5; // rbp
  AK::IAkPluginMemAlloc *v6; // r14
  CAkFxSrcGrainPlayerParams *v7; // rbx
  __int64 result; // rax
  CAkFxSrcGrainPlayerDataBlock *v9; // rcx
  __int64 v10; // rdi
  void *v11; // rax
  CAkFxSrcGrainPlayerDataBlock *v12; // rcx

  v4 = in_ulBlockSize;
  v5 = in_pParamsBlock;
  v6 = in_pAllocator;
  v7 = this;
  this->m_allocator = in_pAllocator;
  if ( in_ulBlockSize )
  {
    v9 = this->m_dataBlock;
    if ( v9 )
      CAkFxSrcGrainPlayerDataBlock::Destroy(v9);
    v10 = (__int64)v7->m_allocator->vfptr->Malloc(v7->m_allocator, 32ui64);
    if ( v10 )
    {
      *(_QWORD *)v10 = 0i64;
      *(_QWORD *)(v10 + 8) = 0i64;
      *(_DWORD *)(v10 + 16) = 0;
    }
    else
    {
      v10 = 0i64;
    }
    v7->m_dataBlock = (CAkFxSrcGrainPlayerDataBlock *)v10;
    *(_DWORD *)(v10 + 16) = 1;
    *(_QWORD *)(v10 + 24) = v6;
    v11 = v6->vfptr->Malloc(v6, v4);
    *(_QWORD *)v10 = v11;
    if ( v11 )
    {
      memmove(v11, v5, v4);
      *(_QWORD *)(v10 + 8) = v4;
    }
    v12 = v7->m_dataBlock;
    if ( v12->m_pDataBlock )
      result = ((__int64 (__fastcall *)(CAkFxSrcGrainPlayerParams *, void *, _QWORD))v7->vfptr[2].SetParam)(
                 v7,
                 v12->m_pDataBlock,
                 LODWORD(v12->m_blockSize));
    else
      result = 2i64;
  }
  else
  {
    this->m_Params.fFrequency = 440.0;
    this->m_Params.fGain = -12.0;
    this->m_Params.fDuration = 1.0;
    this->m_Params.uChannelMask = 4;
    result = 1i64;
  }
  return result;
}

// File Line: 147
// RVA: 0x15BDB0
signed __int64 __fastcall CAkFxSrcGrainPlayerParams::Term(CAkFxSrcGrainPlayerParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFxSrcGrainPlayerDataBlock *v2; // rbx
  AK::IAkPluginMemAlloc *v3; // rsi
  CAkFxSrcGrainPlayerParams *v4; // rdi
  bool v5; // zf
  AK::IAkPluginMemAlloc *v6; // rcx

  v2 = this->m_dataBlock;
  v3 = in_pAllocator;
  v4 = this;
  if ( v2 )
  {
    v5 = v2->m_refCount-- == 1;
    if ( v5 )
    {
      if ( v2->m_pDataBlock )
      {
        ((void (*)(void))v2->m_allocator->vfptr->Free)();
        v2->m_pDataBlock = 0i64;
        v2->m_blockSize = 0i64;
      }
      v6 = v2->m_allocator;
      v2->m_refCount = 0;
      v6->vfptr->Free(v6, v2);
    }
    v4->m_dataBlock = 0i64;
  }
  v4->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)&v4->vfptr, 0);
  v3->vfptr->Free(v3, v4);
  return 1i64;
}

// File Line: 162
// RVA: 0x15BD90
signed __int64 __fastcall CAkFxSrcGrainPlayerParams::SetParamsBlock(CAkFxSrcGrainPlayerParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  *(_QWORD *)&this->m_Params.fFrequency = *(_QWORD *)in_pParamsBlock;
  *(_QWORD *)&this->m_Params.fDuration = *((_QWORD *)in_pParamsBlock + 1);
  this->m_Params.pData = (char *)in_pParamsBlock + 16;
  return 1i64;
}

// File Line: 176
// RVA: 0x15BC60
signed __int64 __fastcall CAkFxSrcGrainPlayerParams::SetParam(CAkFxSrcGrainPlayerParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  size_t v4; // rbp
  const void *v5; // r14
  CAkFxSrcGrainPlayerParams *v6; // rbx
  CAkFxSrcGrainPlayerDataBlock *v7; // rcx
  __int64 v8; // rax
  CAkFxSrcGrainPlayerDataBlock *v9; // rsi
  AK::IAkPluginMemAlloc *v10; // rcx
  void *v11; // rax
  char *v12; // rax

  v4 = in_ulParamSize;
  v5 = in_pValue;
  v6 = this;
  if ( in_ParamID == 0x7FFF )
  {
    if ( (signed int)(in_ulParamSize - 4) <= 0 )
    {
      this->m_Params.pData = 0i64;
    }
    else
    {
      v7 = this->m_dataBlock;
      if ( v7 )
      {
        CAkFxSrcGrainPlayerDataBlock::Destroy(v7);
        v6->m_dataBlock = 0i64;
      }
      v8 = (__int64)v6->m_allocator->vfptr->Malloc(v6->m_allocator, 32ui64);
      v9 = (CAkFxSrcGrainPlayerDataBlock *)v8;
      if ( v8 )
      {
        *(_QWORD *)v8 = 0i64;
        *(_QWORD *)(v8 + 8) = 0i64;
        *(_DWORD *)(v8 + 16) = 0;
      }
      else
      {
        v9 = 0i64;
      }
      v6->m_dataBlock = v9;
      v10 = v6->m_allocator;
      v9->m_refCount = 1;
      v9->m_allocator = v10;
      v11 = v10->vfptr->Malloc(v10, v4);
      v9->m_pDataBlock = v11;
      if ( v11 )
      {
        memmove(v11, v5, v4);
        v9->m_blockSize = v4;
      }
      v12 = (char *)v6->m_dataBlock->m_pDataBlock;
      if ( !v12 )
        return 2i64;
      v6->m_Params.pData = v12 + 4;
    }
  }
  else if ( in_ParamID )
  {
    switch ( in_ParamID )
    {
      case 1:
        this->m_Params.fGain = *(float *)in_pValue;
        break;
      case 2:
        this->m_Params.fDuration = *(float *)in_pValue;
        break;
      case 3:
        this->m_Params.uChannelMask = *(_DWORD *)in_pValue;
        break;
      default:
        return 31i64;
    }
  }
  else
  {
    this->m_Params.fFrequency = *(float *)in_pValue;
  }
  return 1i64;
}

