// File Line: 34
// RVA: 0xA92010
void __fastcall CAkVPLFilterNode::GetBuffer(CAkVPLFilterNode *this, AkVPLState *io_state)
{
  if ( this->m_bLast )
  {
    io_state->result = 17;
    ((void (*)(void))this->vfptr[1].VirtualOff)();
  }
}

// File Line: 45
// RVA: 0xA91F20
void __fastcall CAkVPLFilterNode::ConsumeBuffer(CAkVPLFilterNode *this, AkVPLState *io_state)
{
  AkVPLState *v2; // rbx
  CAkVPLFilterNode *v3; // rdi
  unsigned int v4; // ecx
  __int64 i; // rdx
  char *v6; // rax

  v2 = io_state;
  v3 = this;
  if ( this->m_bBypassed || *((_BYTE *)this->m_pCtx + 375) & 1 )
  {
    if ( !this->m_LastBypassed )
      ((void (*)(void))this->m_pEffect->vfptr->Reset)();
    v3->m_LastBypassed = 1;
  }
  else
  {
    this->m_LastBypassed = 0;
    if ( io_state->result == 17 )
      this->m_bLast = 1;
    if ( io_state->pData )
      goto LABEL_10;
    v4 = io_state->uChannelMask;
    for ( i = 0i64; v4; v4 &= v4 - 1 )
      i = (unsigned int)(i + 1);
    v6 = (char *)AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, 4 * v2->uMaxFrames * i, 0x10u);
    v3->m_pAllocatedBuffer = v6;
    if ( v6 )
    {
      v2->pData = v6;
      v2->uValidFrames = 0;
LABEL_10:
      v2->eState = v2->result;
      v3->m_pEffect->vfptr[1].Term((AK::IAkPlugin *)&v3->m_pEffect->vfptr, (AK::IAkPluginMemAlloc *)v2);
      v2->result = v2->eState;
      return;
    }
    v2->result = 2;
  }
}

// File Line: 121
// RVA: 0xA920B0
void __fastcall CAkVPLFilterNode::ReleaseBuffer(CAkVPLFilterNode *this)
{
  char *v1; // rdx
  CAkVPLFilterNode *v2; // rbx
  CAkVPLNode *v3; // rcx

  v1 = this->m_pAllocatedBuffer;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_pAllocatedBuffer = 0i64;
  }
  else
  {
    v3 = this->m_pInput;
    if ( v3 )
      ((void (*)(void))v3->vfptr->ReleaseBuffer)();
  }
}

// File Line: 135
// RVA: 0xA92150
__int64 __fastcall CAkVPLFilterNode::Seek(CAkVPLFilterNode *this)
{
  CAkVPLFilterNode *v1; // rbx
  CAkVPLNode *v2; // rcx

  v1 = this;
  ((void (*)(void))this->m_pEffect->vfptr->Reset)();
  v2 = v1->m_pInput;
  v1->m_bLast = 0;
  return ((__int64 (*)(void))v2->vfptr->Seek)();
}

// File Line: 145
// RVA: 0xA921F0
void __fastcall CAkVPLFilterNode::VirtualOn(CAkVPLFilterNode *this, AkVirtualQueueBehavior eBehavior)
{
  AkVirtualQueueBehavior v2; // ebx
  CAkVPLFilterNode *v3; // rdi

  v2 = eBehavior;
  v3 = this;
  if ( eBehavior != 2 )
    ((void (*)(void))this->m_pEffect->vfptr->Reset)();
  CAkVPLFilterNodeBase::VirtualOn((CAkVPLFilterNodeBase *)&v3->vfptr, v2);
}

// File Line: 158
// RVA: 0xA92030
signed __int64 __fastcall CAkVPLFilterNode::Init(CAkVPLFilterNode *this, AK::IAkPlugin *in_pPlugin, AkFXDesc *in_fxDesc, unsigned int in_uFXIndex, CAkPBI *in_pCtx, AkAudioFormat *in_format)
{
  CAkVPLFilterNode *v6; // rbx
  int v7; // eax
  signed __int64 result; // rax

  v6 = this;
  v7 = *((_DWORD *)in_format + 1);
  this->m_pEffect = (AK::IAkInPlaceEffectPlugin *)in_pPlugin;
  this->m_pAllocatedBuffer = 0i64;
  this->m_uChannelMask = v7 & 0x3FFFF;
  result = CAkVPLFilterNodeBase::Init((CAkVPLFilterNodeBase *)&this->vfptr, in_pPlugin, in_fxDesc, in_uFXIndex, in_pCtx);
  if ( (_DWORD)result == 1 )
  {
    result = ((__int64 (__fastcall *)(AK::IAkInPlaceEffectPlugin *, AkFXMemAlloc *, CAkInsertFXContext *, AK::IAkPluginParam *, AkAudioFormat *, AkAudioFormat *))v6->m_pEffect->vfptr[1].__vecDelDtor)(
               v6->m_pEffect,
               &AkFXMemAlloc::m_instanceLower,
               v6->m_pInsertFXContext,
               v6->m_pParam,
               in_format,
               in_format);
    if ( (_DWORD)result == 1 )
      result = ((__int64 (*)(void))v6->m_pEffect->vfptr->Reset)();
  }
  return result;
}

// File Line: 202
// RVA: 0xA92180
void __fastcall CAkVPLFilterNode::Term(CAkVPLFilterNode *this)
{
  CAkVPLFilterNode *v1; // rbx

  v1 = this;
  ((void (*)(void))this->vfptr[1].ReleaseBuffer)();
  CAkVPLFilterNodeBase::Term((CAkVPLFilterNodeBase *)&v1->vfptr);
}

// File Line: 208
// RVA: 0xA92100
void __fastcall CAkVPLFilterNode::ReleaseMemory(CAkVPLFilterNode *this)
{
  CAkVPLFilterNode *v1; // rbx
  AK::IAkInPlaceEffectPlugin *v2; // rcx
  char *v3; // rdx

  v1 = this;
  v2 = this->m_pEffect;
  if ( v2 )
  {
    v2->vfptr->Term((AK::IAkPlugin *)&v2->vfptr, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr);
    v1->m_pEffect = 0i64;
  }
  v3 = v1->m_pAllocatedBuffer;
  if ( v3 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
    v1->m_pAllocatedBuffer = 0i64;
  }
}

// File Line: 222
// RVA: 0xA921A0
__int64 __fastcall CAkVPLFilterNode::TimeSkip(CAkVPLFilterNode *this, unsigned int *io_uFrames)
{
  unsigned int *v2; // rdi
  CAkVPLFilterNode *v3; // rbx
  AK::IAkInPlaceEffectPlugin *v5; // rcx

  v2 = io_uFrames;
  v3 = this;
  if ( this->m_bLast )
    return 17i64;
  v5 = this->m_pEffect;
  if ( v5 )
    ((void (__fastcall *)(AK::IAkInPlaceEffectPlugin *, _QWORD))v5->vfptr[1].Reset)(v5, *io_uFrames);
  return v3->m_pInput->vfptr->TimeSkip(v3->m_pInput, v2);
}

