// File Line: 7
// RVA: 0x14B390
void __fastcall UFG::OneShotHandle::Release(UFG::OneShotHandle *this)
{
  UFG::OneShot *m_pOneShot; // rdx

  m_pOneShot = this->m_pOneShot;
  if ( this->m_pOneShot && m_pOneShot->m_pOwnerHandle )
    m_pOneShot->m_pOwnerHandle = 0i64;
  this->m_pOneShot = 0i64;
}

// File Line: 12
// RVA: 0x147D50
bool __fastcall UFG::OneShotHandle::IsValid(UFG::OneShotHandle *this)
{
  return this->m_pOneShot != 0i64;
}

// File Line: 20
// RVA: 0x14CD20
void __fastcall UFG::OneShotHandle::StopAndRelease(UFG::OneShotHandle *this)
{
  UFG::OneShot *m_pOneShot; // rcx

  m_pOneShot = this->m_pOneShot;
  if ( m_pOneShot )
    UFG::OneShotPool::Free(m_pOneShot);
}

// File Line: 28
// RVA: 0x149D60
bool __fastcall UFG::OneShotHandle::OwnsOneShot(UFG::OneShotHandle *this, UFG::OneShot *pOneShot)
{
  return this->m_pOneShot == pOneShot;
}

