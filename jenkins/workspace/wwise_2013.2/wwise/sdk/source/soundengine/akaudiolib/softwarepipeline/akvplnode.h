// File Line: 45
// RVA: 0xA67FE0
void __fastcall CAkVPLNode::VirtualOn(CAkVPLNode *this, __int64 eBehavior)
{
  CAkVPLNode *v2; // rcx

  v2 = this->m_pInput;
  if ( v2 )
    v2->vfptr->VirtualOn(v2, (AkVirtualQueueBehavior)eBehavior);
}

// File Line: 46
// RVA: 0xA67FC0
__int64 __fastcall CAkVPLNode::VirtualOff(CAkVPLNode *this, __int64 eBehavior, __int64 in_bUseSourceOffset)
{
  CAkVPLNode *v3; // rcx
  __int64 result; // rax

  v3 = this->m_pInput;
  if ( v3 )
    result = v3->vfptr->VirtualOff(v3, (AkVirtualQueueBehavior)eBehavior, in_bUseSourceOffset);
  else
    result = 1i64;
  return result;
}

// File Line: 47
// RVA: 0xA672B0
__int64 __fastcall CAkVPLNode::Seek(CAkVPLNode *this)
{
  CAkVPLNode *v1; // rcx
  __int64 result; // rax

  v1 = this->m_pInput;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr->Seek)();
  else
    result = 2i64;
  return result;
}

// File Line: 48
// RVA: 0xA668C0
float __fastcall CAkVPLNode::GetPitch(CAkVPLNode *this)
{
  CAkVPLNode *v1; // rcx
  float result; // xmm0_4

  v1 = this->m_pInput;
  if ( !v1 )
    return *(float *)&FLOAT_1_0;
  ((void (*)(void))v1->vfptr->GetPitch)();
  return result;
}

