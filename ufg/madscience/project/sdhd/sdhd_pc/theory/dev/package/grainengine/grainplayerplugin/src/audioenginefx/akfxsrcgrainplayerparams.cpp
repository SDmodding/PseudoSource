// File Line: 21
// RVA: 0x15BAB0
AK::IAkPluginParam *__fastcall CreateGrainPlayerSourceParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 48i64);
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
  AK::IAkPluginMemAlloc *m_allocator; // rcx

  if ( this->m_refCount-- == 1 )
  {
    if ( this->m_pDataBlock )
    {
      ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_allocator->vfptr->Free)(this->m_allocator);
      this->m_pDataBlock = 0i64;
      this->m_blockSize = 0i64;
    }
    m_allocator = this->m_allocator;
    this->m_refCount = 0;
    m_allocator->vfptr->Free(m_allocator, this);
  }
}

// File Line: 104
// RVA: 0x15BA20
AK::IAkPluginParam *__fastcall CAkFxSrcGrainPlayerParams::Clone(
        CAkFxSrcGrainPlayerParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax
  CAkFxSrcGrainPlayerDataBlock *m_dataBlock; // rdx

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 48i64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkPluginParam::`vftable;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcGrainPlayerParams::`vftable;
  m_dataBlock = this->m_dataBlock;
  result[4].vfptr = (AK::IAkRTPCSubscriberVtbl *)m_dataBlock;
  result[1].vfptr = *(AK::IAkRTPCSubscriberVtbl **)&this->m_Params.fFrequency;
  result[2].vfptr = *(AK::IAkRTPCSubscriberVtbl **)&this->m_Params.fDuration;
  result[3].vfptr = (AK::IAkRTPCSubscriberVtbl *)this->m_Params.pData;
  result[5].vfptr = (AK::IAkRTPCSubscriberVtbl *)this->m_allocator;
  ++m_dataBlock->m_refCount;
  return result;
}

// File Line: 113
// RVA: 0x15BB60
__int64 __fastcall CAkFxSrcGrainPlayerParams::Init(
        CAkFxSrcGrainPlayerParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  unsigned __int64 v4; // rsi
  CAkFxSrcGrainPlayerDataBlock *m_dataBlock; // rcx
  CAkFxSrcGrainPlayerDataBlock *v10; // rdi
  void *v11; // rax
  CAkFxSrcGrainPlayerDataBlock *v12; // rcx

  v4 = in_ulBlockSize;
  this->m_allocator = in_pAllocator;
  if ( in_ulBlockSize )
  {
    m_dataBlock = this->m_dataBlock;
    if ( m_dataBlock )
      CAkFxSrcGrainPlayerDataBlock::Destroy(m_dataBlock);
    v10 = (CAkFxSrcGrainPlayerDataBlock *)this->m_allocator->vfptr->Malloc(this->m_allocator, 32i64);
    if ( v10 )
    {
      v10->m_pDataBlock = 0i64;
      v10->m_blockSize = 0i64;
      v10->m_refCount = 0;
    }
    else
    {
      v10 = 0i64;
    }
    this->m_dataBlock = v10;
    v10->m_refCount = 1;
    v10->m_allocator = in_pAllocator;
    v11 = in_pAllocator->vfptr->Malloc(in_pAllocator, v4);
    v10->m_pDataBlock = v11;
    if ( v11 )
    {
      memmove(v11, in_pParamsBlock, v4);
      v10->m_blockSize = v4;
    }
    v12 = this->m_dataBlock;
    if ( v12->m_pDataBlock )
      return ((__int64 (__fastcall *)(CAkFxSrcGrainPlayerParams *, void *, _QWORD))this->vfptr[2].SetParam)(
               this,
               v12->m_pDataBlock,
               LODWORD(v12->m_blockSize));
    else
      return 2i64;
  }
  else
  {
    this->m_Params.fFrequency = 440.0;
    this->m_Params.fGain = -12.0;
    this->m_Params.fDuration = 1.0;
    this->m_Params.uChannelMask = 4;
    return 1i64;
  }
}

// File Line: 147
// RVA: 0x15BDB0
__int64 __fastcall CAkFxSrcGrainPlayerParams::Term(
        CAkFxSrcGrainPlayerParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFxSrcGrainPlayerDataBlock *m_dataBlock; // rbx
  AK::IAkPluginMemAlloc *m_allocator; // rcx

  m_dataBlock = this->m_dataBlock;
  if ( m_dataBlock )
  {
    if ( m_dataBlock->m_refCount-- == 1 )
    {
      if ( m_dataBlock->m_pDataBlock )
      {
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))m_dataBlock->m_allocator->vfptr->Free)(m_dataBlock->m_allocator);
        m_dataBlock->m_pDataBlock = 0i64;
        m_dataBlock->m_blockSize = 0i64;
      }
      m_allocator = m_dataBlock->m_allocator;
      m_dataBlock->m_refCount = 0;
      m_allocator->vfptr->Free(m_allocator, m_dataBlock);
    }
    this->m_dataBlock = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 162
// RVA: 0x15BD90
__int64 __fastcall CAkFxSrcGrainPlayerParams::SetParamsBlock(
        CAkFxSrcGrainPlayerParams *this,
        char *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  *(_QWORD *)&this->m_Params.fFrequency = *(_QWORD *)in_pParamsBlock;
  *(_QWORD *)&this->m_Params.fDuration = *((_QWORD *)in_pParamsBlock + 1);
  this->m_Params.pData = in_pParamsBlock + 16;
  return 1i64;
}

// File Line: 176
// RVA: 0x15BC60
__int64 __fastcall CAkFxSrcGrainPlayerParams::SetParam(
        CAkFxSrcGrainPlayerParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  size_t v4; // rbp
  CAkFxSrcGrainPlayerDataBlock *m_dataBlock; // rcx
  CAkFxSrcGrainPlayerDataBlock *v8; // rax
  CAkFxSrcGrainPlayerDataBlock *v9; // rsi
  AK::IAkPluginMemAlloc *m_allocator; // rcx
  void *v11; // rax
  char *m_pDataBlock; // rax

  v4 = in_ulParamSize;
  if ( in_ParamID == 0x7FFF )
  {
    if ( (int)(in_ulParamSize - 4) <= 0 )
    {
      this->m_Params.pData = 0i64;
    }
    else
    {
      m_dataBlock = this->m_dataBlock;
      if ( m_dataBlock )
      {
        CAkFxSrcGrainPlayerDataBlock::Destroy(m_dataBlock);
        this->m_dataBlock = 0i64;
      }
      v8 = (CAkFxSrcGrainPlayerDataBlock *)this->m_allocator->vfptr->Malloc(this->m_allocator, 32i64);
      v9 = v8;
      if ( v8 )
      {
        v8->m_pDataBlock = 0i64;
        v8->m_blockSize = 0i64;
        v8->m_refCount = 0;
      }
      else
      {
        v9 = 0i64;
      }
      this->m_dataBlock = v9;
      m_allocator = this->m_allocator;
      v9->m_refCount = 1;
      v9->m_allocator = m_allocator;
      v11 = m_allocator->vfptr->Malloc(m_allocator, v4);
      v9->m_pDataBlock = v11;
      if ( v11 )
      {
        memmove(v11, in_pValue, v4);
        v9->m_blockSize = v4;
      }
      m_pDataBlock = (char *)this->m_dataBlock->m_pDataBlock;
      if ( !m_pDataBlock )
        return 2i64;
      this->m_Params.pData = m_pDataBlock + 4;
    }
  }
  else if ( in_ParamID )
  {
    switch ( in_ParamID )
    {
      case 1:
        this->m_Params.fGain = *in_pValue;
        break;
      case 2:
        this->m_Params.fDuration = *in_pValue;
        break;
      case 3:
        this->m_Params.uChannelMask = *(unsigned int *)in_pValue;
        break;
      default:
        return 31i64;
    }
  }
  else
  {
    this->m_Params.fFrequency = *in_pValue;
  }
  return 1i64;
}

