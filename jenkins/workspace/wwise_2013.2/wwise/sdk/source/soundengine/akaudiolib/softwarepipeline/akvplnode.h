// File Line: 45
// RVA: 0xA67FE0
void __fastcall CAkVPLNode::VirtualOn(CAkVPLNode *this, __int64 eBehavior)
{
  CAkVPLNode *m_pInput; // rcx

  m_pInput = this->m_pInput;
  if ( m_pInput )
    m_pInput->vfptr->VirtualOn(m_pInput, (AkVirtualQueueBehavior)eBehavior);
}

// File Line: 46
// RVA: 0xA67FC0
__int64 __fastcall CAkVPLNode::VirtualOff(CAkVPLNode *this, __int64 eBehavior, __int64 in_bUseSourceOffset)
{
  CAkVPLNode *m_pInput; // rcx

  m_pInput = this->m_pInput;
  if ( m_pInput )
    return ((__int64 (__fastcall *)(CAkVPLNode *, __int64, __int64))m_pInput->vfptr->VirtualOff)(
             m_pInput,
             eBehavior,
             in_bUseSourceOffset);
  else
    return 1i64;
}

// File Line: 47
// RVA: 0xA672B0
__int64 __fastcall CAkVPLNode::Seek(CAkVPLNode *this)
{
  CAkVPLNode *m_pInput; // rcx

  m_pInput = this->m_pInput;
  if ( m_pInput )
    return ((__int64 (__fastcall *)(CAkVPLNode *))m_pInput->vfptr->Seek)(m_pInput);
  else
    return 2i64;
}

// File Line: 48
// RVA: 0xA668C0
float __fastcall CAkVPLNode::GetPitch(CAkVPLNode *this)
{
  CAkVPLNode *m_pInput; // rcx
  float result; // xmm0_4

  m_pInput = this->m_pInput;
  if ( !m_pInput )
    return *(float *)&FLOAT_1_0;
  m_pInput->vfptr->GetPitch(m_pInput);
  return result;
}

