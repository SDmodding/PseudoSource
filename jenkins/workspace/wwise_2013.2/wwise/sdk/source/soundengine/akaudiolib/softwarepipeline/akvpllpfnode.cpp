// File Line: 24
// RVA: 0xA84120
void __fastcall CAkVPLLPFNode::ConsumeBuffer(CAkVPLLPFNode *this, AkVPLState *io_state)
{
  if ( io_state->pData )
    CAkSrcLpFilter::Execute(&this->m_LPF, io_state);
}

// File Line: 48
// RVA: 0xA84140
void __fastcall CAkVPLLPFNode::ReleaseBuffer(CAkVPLLPFNode *this)
{
  CAkVPLNode *m_pInput; // rcx

  m_pInput = this->m_pInput;
  if ( m_pInput )
    m_pInput->vfptr->ReleaseBuffer(m_pInput);
}

// File Line: 54
// RVA: 0xA84160
__int64 __fastcall CAkVPLLPFNode::TimeSkip(CAkVPLLPFNode *this, unsigned int *io_uFrames)
{
  return ((__int64 (__fastcall *)(CAkVPLNode *, unsigned int *))this->m_pInput->CAkVPLNode::vfptr->TimeSkip)(
           this->m_pInput,
           io_uFrames);
}

// File Line: 63
// RVA: 0xA84170
void __fastcall CAkVPLLPFNode::VirtualOn(CAkVPLLPFNode *this, unsigned int eBehavior)
{
  CAkVPLNode *m_pInput; // rcx

  CAkSrcLpFilter::ResetRamp(&this->m_LPF);
  m_pInput = this->m_pInput;
  if ( m_pInput )
    m_pInput->vfptr->VirtualOn(m_pInput, (AkVirtualQueueBehavior)eBehavior);
}

