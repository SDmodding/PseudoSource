// File Line: 36
// RVA: 0x33BD40
UFG::PlayerCoverComponent::CoverObjectPosition *__fastcall UFG::PlayerCoverComponent::CoverObjectPosition::operator=(UFG::PlayerCoverComponent::CoverObjectPosition *this, UFG::PlayerCoverComponent::CoverObjectPosition *other)
{
  UFG::CoverObjectBase *v2; // rdi
  UFG::PlayerCoverComponent::CoverObjectPosition *v3; // rbx
  UFG::CoverObjectBase *v4; // rcx
  UFG::PlayerCoverComponent::CoverObjectPosition *v5; // rsi
  bool v6; // zf
  UFG::CoverPosition *v7; // rcx
  UFG::CoverPosition *v8; // rdi
  UFG::PlayerCoverComponent::CoverObjectPosition *result; // rax

  v2 = other->m_pCoverObject;
  v3 = this;
  v4 = this->m_pCoverObject;
  v5 = other;
  if ( v4 )
  {
    v6 = v4->m_iRefCount-- == 1;
    if ( v6 )
      v4->vfptr->__vecDelDtor(v4, 1u);
    v3->m_pCoverObject = 0i64;
  }
  if ( v2 )
  {
    v3->m_pCoverObject = v2;
    ++v2->m_iRefCount;
  }
  v7 = v3->m_pCoverPosition;
  v8 = v5->m_pCoverPosition;
  if ( v7 )
  {
    v6 = v7->m_iRefCount-- == 1;
    if ( v6 )
      v7->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v7->vfptr, 1u);
    v3->m_pCoverPosition = 0i64;
  }
  result = v3;
  if ( v8 )
  {
    v3->m_pCoverPosition = v8;
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
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::PlayerCoverComponent::_DescInit )
  {
    v0 = UFG::AICoverComponent::AccessComponentDesc();
    ++UFG::AICoverComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AICoverComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::PlayerCoverComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::PlayerCoverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::PlayerCoverComponent::_TypeIDesc.mChildren = 0;
    UFG::PlayerCoverComponent::_DescInit = 1;
    UFG::PlayerCoverComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::PlayerCoverComponent::_PlayerCoverComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::PlayerCoverComponent::_TypeIDesc;
}

