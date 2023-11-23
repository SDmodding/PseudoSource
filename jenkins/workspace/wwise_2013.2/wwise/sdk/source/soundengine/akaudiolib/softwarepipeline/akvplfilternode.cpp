// File Line: 34
// RVA: 0xA92010
void __fastcall CAkVPLFilterNode::GetBuffer(CAkVPLFilterNode *this, AkVPLState *io_state)
{
  if ( this->m_bLast )
  {
    io_state->result = AK_NoMoreData;
    ((void (__fastcall *)(CAkVPLFilterNode *))this->vfptr[1].VirtualOff)(this);
  }
}

// File Line: 45
// RVA: 0xA91F20
void __fastcall CAkVPLFilterNode::ConsumeBuffer(CAkVPLFilterNode *this, AK::IAkPluginMemAlloc *io_state)
{
  unsigned int vfptr; // ecx
  __int64 i; // rdx
  char *v6; // rax

  if ( this->m_bBypassed || (*((_BYTE *)this->m_pCtx + 375) & 1) != 0 )
  {
    if ( !this->m_LastBypassed )
      this->m_pEffect->vfptr->Reset(this->m_pEffect);
    this->m_LastBypassed = 1;
  }
  else
  {
    this->m_LastBypassed = 0;
    if ( LODWORD(io_state[7].vfptr) == 17 )
      this->m_bLast = 1;
    if ( io_state->vfptr )
      goto LABEL_10;
    vfptr = (unsigned int)io_state[1].vfptr;
    for ( i = 0i64; vfptr; vfptr &= vfptr - 1 )
      i = (unsigned int)(i + 1);
    v6 = (char *)AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, 4 * LOWORD(io_state[2].vfptr) * i, 0x10u);
    this->m_pAllocatedBuffer = v6;
    if ( v6 )
    {
      io_state->vfptr = (AK::IAkPluginMemAllocVtbl *)v6;
      WORD1(io_state[2].vfptr) = 0;
LABEL_10:
      HIDWORD(io_state[1].vfptr) = io_state[7].vfptr;
      this->m_pEffect->vfptr[1].Term(this->m_pEffect, io_state);
      LODWORD(io_state[7].vfptr) = HIDWORD(io_state[1].vfptr);
      return;
    }
    LODWORD(io_state[7].vfptr) = 2;
  }
}

// File Line: 121
// RVA: 0xA920B0
void __fastcall CAkVPLFilterNode::ReleaseBuffer(CAkVPLFilterNode *this)
{
  char *m_pAllocatedBuffer; // rdx
  CAkVPLNode *m_pInput; // rcx

  m_pAllocatedBuffer = this->m_pAllocatedBuffer;
  if ( m_pAllocatedBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pAllocatedBuffer);
    this->m_pAllocatedBuffer = 0i64;
  }
  else
  {
    m_pInput = this->m_pInput;
    if ( m_pInput )
      m_pInput->vfptr->ReleaseBuffer(m_pInput);
  }
}

// File Line: 135
// RVA: 0xA92150
__int64 __fastcall CAkVPLFilterNode::Seek(CAkVPLFilterNode *this)
{
  CAkVPLNode *m_pInput; // rcx

  this->m_pEffect->vfptr->Reset(this->m_pEffect);
  m_pInput = this->m_pInput;
  this->m_bLast = 0;
  return ((__int64 (__fastcall *)(CAkVPLNode *))m_pInput->vfptr->Seek)(m_pInput);
}

// File Line: 145
// RVA: 0xA921F0
void __fastcall CAkVPLFilterNode::VirtualOn(CAkVPLFilterNode *this, AkVirtualQueueBehavior eBehavior)
{
  if ( eBehavior != AkVirtualQueueBehavior_Resume )
    this->m_pEffect->vfptr->Reset(this->m_pEffect);
  CAkVPLFilterNodeBase::VirtualOn(this, eBehavior);
}

// File Line: 158
// RVA: 0xA92030
__int64 __fastcall CAkVPLFilterNode::Init(
        CAkVPLFilterNode *this,
        AK::IAkInPlaceEffectPlugin *in_pPlugin,
        AkFXDesc *in_fxDesc,
        unsigned int in_uFXIndex,
        CAkPBI *in_pCtx,
        AkAudioFormat *in_format)
{
  int v7; // eax
  __int64 result; // rax

  v7 = *((_DWORD *)in_format + 1);
  this->m_pEffect = in_pPlugin;
  this->m_pAllocatedBuffer = 0i64;
  this->m_uChannelMask = v7 & 0x3FFFF;
  result = CAkVPLFilterNodeBase::Init(this, in_pPlugin, in_fxDesc, in_uFXIndex, in_pCtx);
  if ( (_DWORD)result == 1 )
  {
    result = ((__int64 (__fastcall *)(AK::IAkInPlaceEffectPlugin *, AkFXMemAlloc *, CAkInsertFXContext *, AK::IAkPluginParam *, AkAudioFormat *, AkAudioFormat *))this->m_pEffect->vfptr[1].__vecDelDtor)(
               this->m_pEffect,
               &AkFXMemAlloc::m_instanceLower,
               this->m_pInsertFXContext,
               this->m_pParam,
               in_format,
               in_format);
    if ( (_DWORD)result == 1 )
      return ((__int64 (__fastcall *)(AK::IAkInPlaceEffectPlugin *))this->m_pEffect->vfptr->Reset)(this->m_pEffect);
  }
  return result;
}

// File Line: 202
// RVA: 0xA92180
void __fastcall CAkVPLFilterNode::Term(CAkVPLFilterNode *this)
{
  this->vfptr[1].ReleaseBuffer(this);
  CAkVPLFilterNodeBase::Term(this);
}

// File Line: 208
// RVA: 0xA92100
void __fastcall CAkVPLFilterNode::ReleaseMemory(CAkVPLFilterNode *this)
{
  AK::IAkInPlaceEffectPlugin *m_pEffect; // rcx
  char *m_pAllocatedBuffer; // rdx

  m_pEffect = this->m_pEffect;
  if ( m_pEffect )
  {
    m_pEffect->vfptr->Term(m_pEffect, &AkFXMemAlloc::m_instanceLower);
    this->m_pEffect = 0i64;
  }
  m_pAllocatedBuffer = this->m_pAllocatedBuffer;
  if ( m_pAllocatedBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pAllocatedBuffer);
    this->m_pAllocatedBuffer = 0i64;
  }
}

// File Line: 222
// RVA: 0xA921A0
__int64 __fastcall CAkVPLFilterNode::TimeSkip(CAkVPLFilterNode *this, unsigned int *io_uFrames)
{
  AK::IAkInPlaceEffectPlugin *m_pEffect; // rcx

  if ( this->m_bLast )
    return 17i64;
  m_pEffect = this->m_pEffect;
  if ( m_pEffect )
    ((void (__fastcall *)(AK::IAkInPlaceEffectPlugin *, _QWORD))m_pEffect->vfptr[1].Reset)(m_pEffect, *io_uFrames);
  return ((__int64 (__fastcall *)(CAkVPLNode *, unsigned int *))this->m_pInput->CAkVPLFilterNodeBase::CAkVPLNode::vfptr->TimeSkip)(
           this->m_pInput,
           io_uFrames);
}

