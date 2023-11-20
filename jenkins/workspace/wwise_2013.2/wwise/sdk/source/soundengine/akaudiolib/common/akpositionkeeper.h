// File Line: 128
// RVA: 0xA6B130
signed __int64 __fastcall AkPositionKeeper::SetPosition(AkPositionKeeper *this, AkSoundPosition *in_Positions, unsigned __int16 in_NumPos)
{
  unsigned __int16 v3; // di
  AkSoundPosition *v4; // rsi
  AkPositionKeeper *v5; // rbx
  AkSoundPosition *v6; // rax

  v3 = in_NumPos;
  v4 = in_Positions;
  v5 = this;
  if ( in_NumPos == this->m_uNumPos )
    goto LABEL_7;
  if ( this->m_aPos )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_aPos);
    v5->m_aPos = 0i64;
    v5->m_uNumPos = 0;
  }
  if ( !v3 )
    goto LABEL_7;
  v6 = (AkSoundPosition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24i64 * v3);
  v5->m_aPos = v6;
  if ( v6 )
  {
    v5->m_uNumPos = v3;
LABEL_7:
    memmove(v5->m_aPos, v4, 24i64 * v5->m_uNumPos);
    return 1i64;
  }
  return 52i64;
}

