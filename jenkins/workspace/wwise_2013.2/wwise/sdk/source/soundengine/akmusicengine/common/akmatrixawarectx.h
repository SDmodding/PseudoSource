// File Line: 265
// RVA: 0xAAB390
unsigned __int64 __fastcall CAkMatrixAwareCtx::GetAbsoluteTimeOffset(CAkMatrixAwareCtx *this)
{
  unsigned __int64 v1; // rbx
  CAkMatrixAwareCtx *v2; // rcx
  unsigned __int64 result; // rax

  v1 = this->m_iLocalTime;
  v2 = (CAkMatrixAwareCtx *)this->m_pParentCtx;
  if ( v2 )
    result = v1 + CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v2);
  else
    result = v1;
  return result;
}

