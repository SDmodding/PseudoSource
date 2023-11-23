// File Line: 36
// RVA: 0x33BD40
UFG::PlayerCoverComponent::CoverObjectPosition *__fastcall UFG::PlayerCoverComponent::CoverObjectPosition::operator=(
        UFG::PlayerCoverComponent::CoverObjectPosition *this,
        UFG::PlayerCoverComponent::CoverObjectPosition *other)
{
  UFG::CoverObjectBase *m_pCoverObject; // rdi
  UFG::CoverObjectBase *v4; // rcx
  bool v6; // zf
  UFG::CoverPosition *m_pCoverPosition; // rcx
  UFG::CoverPosition *v8; // rdi
  UFG::PlayerCoverComponent::CoverObjectPosition *result; // rax

  m_pCoverObject = other->m_pCoverObject;
  v4 = this->m_pCoverObject;
  if ( v4 )
  {
    v6 = v4->m_iRefCount-- == 1;
    if ( v6 )
      v4->vfptr->__vecDelDtor(v4, 1u);
    this->m_pCoverObject = 0i64;
  }
  if ( m_pCoverObject )
  {
    this->m_pCoverObject = m_pCoverObject;
    ++m_pCoverObject->m_iRefCount;
  }
  m_pCoverPosition = this->m_pCoverPosition;
  v8 = other->m_pCoverPosition;
  if ( m_pCoverPosition )
  {
    v6 = m_pCoverPosition->m_iRefCount-- == 1;
    if ( v6 )
      m_pCoverPosition->vfptr->__vecDelDtor(m_pCoverPosition, 1u);
    this->m_pCoverPosition = 0i64;
  }
  result = this;
  if ( v8 )
  {
    this->m_pCoverPosition = v8;
    ++v8->m_iRefCount;
  }
  return result;
}

// File Line: 52
// RVA: 0x331960
void __fastcall UFG::PlayerCoverComponent::ScoredObject::ScoredObject(UFG::PlayerCoverComponent::ScoredObject *this)
{
  this->m_pCoverObject = 0i64;
  this->m_fScore = -1.0;
}

// File Line: 115
// RVA: 0x33F5F0
UFG::ComponentIDDesc *__fastcall UFG::PlayerCoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::PlayerCoverComponent::_DescInit )
  {
    v0 = UFG::AICoverComponent::AccessComponentDesc();
    ++UFG::AICoverComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AICoverComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::PlayerCoverComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::PlayerCoverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::PlayerCoverComponent::_TypeIDesc.mChildren = 0;
    UFG::PlayerCoverComponent::_DescInit = 1;
    UFG::PlayerCoverComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::PlayerCoverComponent::_PlayerCoverComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::PlayerCoverComponent::_TypeIDesc;
}

