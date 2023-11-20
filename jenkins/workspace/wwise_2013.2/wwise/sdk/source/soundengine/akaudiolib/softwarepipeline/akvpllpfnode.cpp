// File Line: 24
// RVA: 0xA84120
void __fastcall CAkVPLLPFNode::ConsumeBuffer(CAkVPLLPFNode *this, AkVPLState *io_state)
{
  if ( io_state->pData )
    CAkSrcLpFilter::Execute(&this->m_LPF, (AkAudioBuffer *)&io_state->pData);
}

// File Line: 48
// RVA: 0xA84140
void __fastcall CAkVPLLPFNode::ReleaseBuffer(CAkVPLLPFNode *this)
{
  CAkVPLNode *v1; // rcx

  v1 = this->m_pInput;
  if ( v1 )
    ((void (*)(void))v1->vfptr->ReleaseBuffer)();
}

// File Line: 54
// RVA: 0xA84160
__int64 __fastcall CAkVPLLPFNode::TimeSkip(CAkVPLLPFNode *this, unsigned int *io_uFrames)
{
  return this->m_pInput->vfptr->TimeSkip(this->m_pInput, io_uFrames);
}

// File Line: 63
// RVA: 0xA84170
void __fastcall CAkVPLLPFNode::VirtualOn(CAkVPLLPFNode *this, AkVirtualQueueBehavior eBehavior)
{
  CAkVPLLPFNode *v2; // rbx
  AkVirtualQueueBehavior v3; // edi
  CAkVPLNode *v4; // rcx

  v2 = this;
  v3 = eBehavior;
  CAkSrcLpFilter::ResetRamp(&this->m_LPF);
  v4 = v2->m_pInput;
  if ( v4 )
    v4->vfptr->VirtualOn(v4, v3);
}

