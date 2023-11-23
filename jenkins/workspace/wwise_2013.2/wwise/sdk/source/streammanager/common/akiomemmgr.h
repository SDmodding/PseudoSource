// File Line: 94
// RVA: 0xAA8BE0
void __fastcall AK::StreamMgr::AkMemBlocksDictionnary::Move(
        AK::StreamMgr::AkMemBlocksDictionnary *this,
        unsigned int in_uIndexSource,
        unsigned int in_uIndexDestination)
{
  __int64 v4; // r8
  __int64 v5; // r10
  unsigned __int16 v7; // bx
  unsigned int v8; // r8d
  __int64 v9; // r10
  __int64 v10; // rcx
  unsigned __int16 v11; // ax

  LODWORD(v4) = in_uIndexSource;
  v5 = in_uIndexSource;
  v7 = this->m_pItems[v5];
  if ( in_uIndexSource < in_uIndexDestination )
  {
    --in_uIndexDestination;
    v8 = in_uIndexSource + 1;
    if ( in_uIndexSource + 1 <= in_uIndexDestination )
    {
      v9 = v8;
      do
      {
        v10 = v8++ - 1;
        v11 = this->m_pItems[v9++];
        this->m_pItems[v10] = v11;
      }
      while ( v8 <= in_uIndexDestination );
    }
    goto LABEL_8;
  }
  if ( in_uIndexSource <= in_uIndexDestination )
  {
LABEL_8:
    this->m_pItems[in_uIndexDestination] = v7;
    return;
  }
  do
  {
    v4 = (unsigned int)(v4 - 1);
    this->m_pItems[v5--] = this->m_pItems[v4];
  }
  while ( (unsigned int)v4 > in_uIndexDestination );
  this->m_pItems[in_uIndexDestination] = v7;
}

