// File Line: 265
// RVA: 0xAAB390
unsigned __int64 __fastcall CAkMatrixAwareCtx::GetAbsoluteTimeOffset(CAkMatrixAwareCtx *this)
{
  unsigned __int64 m_iLocalTime; // rbx
  CAkMatrixAwareCtx *m_pParentCtx; // rcx

  m_iLocalTime = this->m_iLocalTime;
  m_pParentCtx = (CAkMatrixAwareCtx *)this->m_pParentCtx;
  if ( m_pParentCtx )
    return m_iLocalTime + CAkMatrixAwareCtx::GetAbsoluteTimeOffset(m_pParentCtx);
  else
    return m_iLocalTime;
}

