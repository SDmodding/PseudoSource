// File Line: 76
// RVA: 0xA98F00
__int64 __fastcall CAkSrcBaseEx::OnLoopComplete(CAkSrcBaseEx *this, bool in_bEndOfFile)
{
  unsigned __int16 m_uLoopCnt; // ax
  __int64 result; // rax

  m_uLoopCnt = this->m_uLoopCnt;
  if ( m_uLoopCnt > 1u )
    this->m_uLoopCnt = m_uLoopCnt - 1;
  result = 45i64;
  if ( in_bEndOfFile )
    return 17i64;
  return result;
}

