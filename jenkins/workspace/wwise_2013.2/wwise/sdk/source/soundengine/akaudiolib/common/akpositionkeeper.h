// File Line: 128
// RVA: 0xA6B130
__int64 __fastcall AkPositionKeeper::SetPosition(
        AkPositionKeeper *this,
        AkSoundPosition *in_Positions,
        unsigned __int16 in_NumPos)
{
  AkSoundPosition *v6; // rax

  if ( in_NumPos == this->m_uNumPos )
    goto LABEL_7;
  if ( this->m_aPos )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_aPos);
    this->m_aPos = 0i64;
    this->m_uNumPos = 0;
  }
  if ( !in_NumPos )
    goto LABEL_7;
  v6 = (AkSoundPosition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24i64 * in_NumPos);
  this->m_aPos = v6;
  if ( v6 )
  {
    this->m_uNumPos = in_NumPos;
LABEL_7:
    memmove(this->m_aPos, in_Positions, 24i64 * this->m_uNumPos);
    return 1i64;
  }
  return 52i64;
}

