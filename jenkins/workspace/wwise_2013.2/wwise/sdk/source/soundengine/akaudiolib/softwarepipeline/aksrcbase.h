// File Line: 76
// RVA: 0xA98F00
signed __int64 __fastcall CAkSrcBaseEx::OnLoopComplete(CAkSrcBaseEx *this, bool in_bEndOfFile)
{
  unsigned __int16 v2; // ax
  signed __int64 result; // rax

  v2 = this->m_uLoopCnt;
  if ( v2 > 1u )
    this->m_uLoopCnt = v2 - 1;
  result = 45i64;
  if ( in_bEndOfFile )
    result = 17i64;
  return result;
}

