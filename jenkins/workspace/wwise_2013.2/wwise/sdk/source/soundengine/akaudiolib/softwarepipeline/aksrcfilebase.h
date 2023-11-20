// File Line: 105
// RVA: 0xA99580
signed __int64 __fastcall CAkSrcFileBase::OnLoopComplete(CAkSrcFileBase *this, bool in_bEndOfFile)
{
  unsigned __int16 v2; // ax
  signed __int64 result; // rax

  if ( !in_bEndOfFile )
    --this->m_uStreamLoopCntAhead;
  v2 = this->m_uLoopCnt;
  if ( v2 > 1u )
    this->m_uLoopCnt = v2 - 1;
  result = 45i64;
  if ( in_bEndOfFile )
    result = 17i64;
  return result;
}

