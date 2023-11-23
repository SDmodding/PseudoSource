// File Line: 24
// RVA: 0xEE4C3C
OSuite::ZListBase *__fastcall OSuite::ZListBase::operator=(OSuite::ZListBase *this, OSuite::ZListBase *that)
{
  if ( this != that )
  {
    this->m_nSize = that->m_nSize;
    this->m_nTop = that->m_nTop;
  }
  return this;
}

// File Line: 54
// RVA: 0xEE4C2C
void __fastcall OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        OSuite::ZListBase::ZListIteratorBase *this,
        OSuite::ZListBase *pList)
{
  this->m_nIndex = 0i64;
  this->m_pListBase = pList;
}

// File Line: 78
// RVA: 0xEE4C68
bool __fastcall OSuite::ZListBase::ZListIteratorBase::AtEnd(OSuite::ZListBase::ZListIteratorBase *this)
{
  return this->m_nIndex >= this->m_pListBase->m_nTop;
}

// File Line: 84
// RVA: 0xEE4C58
bool __fastcall OSuite::ZListBase::ZListIteratorBase::operator bool(OSuite::ZListBase::ZListIteratorBase *this)
{
  return this->m_nIndex < this->m_pListBase->m_nTop;
}

// File Line: 90
// RVA: 0xEE4C78
void __fastcall OSuite::ZListBase::ZListIteratorBase::Next(OSuite::ZListBase::ZListIteratorBase *this)
{
  unsigned __int64 m_nIndex; // r8
  unsigned __int64 m_nTop; // rdx

  m_nIndex = this->m_nIndex;
  m_nTop = this->m_pListBase->m_nTop;
  this->m_nIndex = m_nIndex + 1;
  if ( m_nIndex == m_nTop )
    this->m_nIndex = 0i64;
}

// File Line: 108
// RVA: 0xEE4C98
void __fastcall OSuite::ZListBase::ZListIteratorBase::Remove(OSuite::ZListBase::ZListIteratorBase *this)
{
  this->m_pListBase->vfptr[1].__vecDelDtor(this->m_pListBase, this->m_nIndex);
}

