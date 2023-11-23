// File Line: 105
// RVA: 0xA99580
__int64 __fastcall CAkSrcFileBase::OnLoopComplete(CAkSrcFileBase *this, bool in_bEndOfFile)
{
  unsigned __int16 m_uLoopCnt; // ax
  __int64 result; // rax

  if ( !in_bEndOfFile )
    --this->m_uStreamLoopCntAhead;
  m_uLoopCnt = this->m_uLoopCnt;
  if ( m_uLoopCnt > 1u )
    this->m_uLoopCnt = m_uLoopCnt - 1;
  result = 45i64;
  if ( in_bEndOfFile )
    return 17i64;
  return result;
}

