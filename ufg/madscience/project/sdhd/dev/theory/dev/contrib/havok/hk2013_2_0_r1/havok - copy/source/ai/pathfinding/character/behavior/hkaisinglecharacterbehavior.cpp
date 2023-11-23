// File Line: 17
// RVA: 0xBD55D0
void __fastcall hkaiSingleCharacterBehavior::hkaiSingleCharacterBehavior(
        hkaiSingleCharacterBehavior *this,
        hkaiCharacter *character,
        hkaiWorld *world)
{
  this->hkaiBehavior::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiBehavior::`vftable{for `hkReferencedObject};
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkaiBehavior::hkaiPathRequestInfoOwner::vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  if ( world )
    hkReferencedObject::addReference(world);
  this->m_world.m_pntr = world;
  this->hkaiBehavior::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkReferencedObject};
  this->hkaiBehavior::hkaiPathRequestInfoOwner::vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  if ( character )
    hkReferencedObject::addReference(character);
  this->m_character.m_pntr = character;
}

// File Line: 21
// RVA: 0xBD5660
void __fastcall hkaiSingleCharacterBehavior::~hkaiSingleCharacterBehavior(hkaiSingleCharacterBehavior *this)
{
  hkaiCharacter *m_pntr; // rcx
  hkaiWorld *v3; // rcx

  this->hkaiBehavior::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkReferencedObject};
  this->hkaiBehavior::hkaiPathRequestInfoOwner::vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  hkaiSingleCharacterBehavior::cancelRequestedPath(this);
  m_pntr = this->m_character.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_character.m_pntr = 0i64;
  this->hkaiBehavior::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiBehavior::`vftable{for `hkReferencedObject};
  this->hkaiBehavior::hkaiPathRequestInfoOwner::vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  v3 = this->m_world.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_world.m_pntr = 0i64;
  this->hkaiBehavior::hkaiPathRequestInfoOwner::vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiPathRequestInfoOwner::`vftable;
  this->hkaiBehavior::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 26
// RVA: 0xBD56F0
void __fastcall hkaiSingleCharacterBehavior::requestPathWithMultipleGoals(
        hkaiSingleCharacterBehavior *this,
        hkVector4f *goals,
        int numGoals,
        int priority)
{
  hkaiPathRequestInfoOwner *v8; // rdx
  hkaiNavMeshPathRequestInfo *v9; // rax
  int m_priority; // eax
  hkaiPathfindingUtil::FindPathInput *PathRequest; // rbx

  if ( this )
    v8 = &this->hkaiPathRequestInfoOwner;
  else
    v8 = 0i64;
  v9 = hkaiWorld::cancelRequestedNavMeshPath(this->m_world.m_pntr, v8);
  if ( v9 )
  {
    m_priority = v9->m_priority;
    if ( priority > m_priority )
      m_priority = priority;
    priority = m_priority;
  }
  PathRequest = hkaiCharacterUtil::generatePathRequest(this->m_world.m_pntr, this->m_character.m_pntr, goals, numGoals);
  hkaiWorld::requestPath(this->m_world.m_pntr, &this->hkaiPathRequestInfoOwner, PathRequest, priority);
  hkReferencedObject::removeReference(PathRequest);
}

// File Line: 41
// RVA: 0xBD5780
void __fastcall hkaiSingleCharacterBehavior::requestVolumePathWithMultipleGoals(
        hkaiSingleCharacterBehavior *this,
        hkVector4f *goals,
        int numGoals,
        int priority)
{
  hkaiPathRequestInfoOwner *v8; // rdx
  hkaiNavVolumePathRequestInfo *v9; // rax
  int m_priority; // eax
  hkaiVolumePathfindingUtil::FindPathInput *VolumePathRequest; // rbx

  if ( this )
    v8 = &this->hkaiPathRequestInfoOwner;
  else
    v8 = 0i64;
  v9 = hkaiWorld::cancelRequestedNavVolumePath(this->m_world.m_pntr, v8);
  if ( v9 )
  {
    m_priority = v9->m_priority;
    if ( priority > m_priority )
      m_priority = priority;
    priority = m_priority;
  }
  VolumePathRequest = hkaiCharacterUtil::generateVolumePathRequest(
                        this->m_world.m_pntr,
                        this->m_character.m_pntr,
                        goals,
                        numGoals);
  hkaiWorld::requestPath(this->m_world.m_pntr, &this->hkaiPathRequestInfoOwner, VolumePathRequest, priority);
  hkReferencedObject::removeReference(VolumePathRequest);
}

// File Line: 56
// RVA: 0xBD5830
hkaiCharacter *__fastcall hkaiSingleCharacterBehavior::getCharacter(hkaiSingleCharacterBehavior *this, int index)
{
  return this->m_character.m_pntr;
}

// File Line: 62
// RVA: 0xBD5840
void __fastcall hkaiSingleCharacterBehavior::cancelRequestedPath(hkaiSingleCharacterBehavior *this)
{
  hkaiWorld *m_pntr; // rcx

  m_pntr = this->m_world.m_pntr;
  if ( m_pntr )
  {
    hkaiWorld::cancelRequestedNavMeshPath(m_pntr, &this->hkaiPathRequestInfoOwner);
    hkaiWorld::cancelRequestedNavVolumePath(this->m_world.m_pntr, &this->hkaiPathRequestInfoOwner);
  }
}

// File Line: 71
// RVA: 0xBD5810
bool __fastcall hkaiSingleCharacterBehavior::isNearGoal(hkaiSingleCharacterBehavior *this)
{
  return (unsigned int)(this->m_character.m_pntr->m_state.m_storage - 2) <= 1;
}

