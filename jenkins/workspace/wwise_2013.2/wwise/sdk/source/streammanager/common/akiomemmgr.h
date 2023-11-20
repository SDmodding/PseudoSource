// File Line: 94
// RVA: 0xAA8BE0
void __fastcall AK::StreamMgr::AkMemBlocksDictionnary::Move(AK::StreamMgr::AkMemBlocksDictionnary *this, unsigned int in_uIndexSource, unsigned int in_uIndexDestination)
{
  unsigned int v3; // er9
  __int64 v4; // r8
  __int64 v5; // r10
  AK::StreamMgr::AkMemBlocksDictionnary *v6; // r11
  unsigned __int16 v7; // bx
  unsigned int v8; // er8
  signed __int64 v9; // r10
  __int64 v10; // rcx
  unsigned __int16 v11; // ax

  v3 = in_uIndexDestination;
  LODWORD(v4) = in_uIndexSource;
  v5 = in_uIndexSource;
  v6 = this;
  v7 = this->m_pItems[v5];
  if ( in_uIndexSource < v3 )
  {
    --v3;
    v8 = in_uIndexSource + 1;
    if ( in_uIndexSource + 1 <= v3 )
    {
      v9 = v8;
      do
      {
        v10 = v8++ - 1;
        v11 = v6->m_pItems[v9];
        ++v9;
        v6->m_pItems[v10] = v11;
      }
      while ( v8 <= v3 );
    }
    goto LABEL_8;
  }
  if ( in_uIndexSource <= v3 )
  {
LABEL_8:
    v6->m_pItems[v3] = v7;
    return;
  }
  do
  {
    v4 = (unsigned int)(v4 - 1);
    --v5;
    this->m_pItems[v5 + 1] = this->m_pItems[v4];
  }
  while ( (unsigned int)v4 > v3 );
  this->m_pItems[v3] = v7;
}

