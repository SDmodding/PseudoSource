// File Line: 17
// RVA: 0xBD55D0
void __fastcall hkaiSingleCharacterBehavior::hkaiSingleCharacterBehavior(hkaiSingleCharacterBehavior *this, hkaiCharacter *character, hkaiWorld *world)
{
  hkaiWorld *v3; // rsi
  hkaiCharacter *v4; // rdi
  hkaiSingleCharacterBehavior *v5; // rbx

  v3 = world;
  v4 = character;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiBehavior::`vftable{for `hkReferencedObject};
  v5 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  if ( world )
    hkReferencedObject::addReference((hkReferencedObject *)&world->vfptr);
  v5->m_world.m_pntr = v3;
  v5->vfptr = (hkBaseObjectVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkReferencedObject};
  v5->vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v5->m_character.m_pntr = v4;
}

// File Line: 21
// RVA: 0xBD5660
void __fastcall hkaiSingleCharacterBehavior::~hkaiSingleCharacterBehavior(hkaiSingleCharacterBehavior *this)
{
  hkaiSingleCharacterBehavior *v1; // rbx
  hkReferencedObject *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkReferencedObject};
  this->vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiSingleCharacterBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  hkaiSingleCharacterBehavior::cancelRequestedPath(this);
  v2 = (hkReferencedObject *)&v1->m_character.m_pntr->vfptr;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1->m_character.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkaiBehavior::`vftable{for `hkReferencedObject};
  v1->vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiBehavior::`vftable{for `hkaiPathRequestInfoOwner};
  v3 = (hkReferencedObject *)&v1->m_world.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_world.m_pntr = 0i64;
  v1->vfptr = (hkaiPathRequestInfoOwnerVtbl *)&hkaiPathRequestInfoOwner::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 26
// RVA: 0xBD56F0
void __fastcall hkaiSingleCharacterBehavior::requestPathWithMultipleGoals(hkaiSingleCharacterBehavior *this, hkVector4f *goals, int numGoals, int priority)
{
  int v4; // esi
  int v5; // ebx
  hkVector4f *v6; // rbp
  hkaiSingleCharacterBehavior *v7; // rdi
  hkaiPathRequestInfoOwner *v8; // rdx
  hkaiNavMeshPathRequestInfo *v9; // rax
  int v10; // eax
  hkaiPathfindingUtil::FindPathInput *v11; // rbx

  v4 = priority;
  v5 = numGoals;
  v6 = goals;
  v7 = this;
  if ( this )
    v8 = (hkaiPathRequestInfoOwner *)&this->vfptr;
  else
    v8 = 0i64;
  v9 = hkaiWorld::cancelRequestedNavMeshPath(this->m_world.m_pntr, v8);
  if ( v9 )
  {
    v10 = v9->m_priority;
    if ( v4 > v10 )
      v10 = v4;
    v4 = v10;
  }
  v11 = hkaiCharacterUtil::generatePathRequest(v7->m_world.m_pntr, v7->m_character.m_pntr, v6, v5);
  hkaiWorld::requestPath(v7->m_world.m_pntr, (hkaiPathRequestInfoOwner *)&v7->vfptr, v11, v4);
  hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
}

// File Line: 41
// RVA: 0xBD5780
void __fastcall hkaiSingleCharacterBehavior::requestVolumePathWithMultipleGoals(hkaiSingleCharacterBehavior *this, hkVector4f *goals, int numGoals, int priority)
{
  int v4; // esi
  int v5; // ebx
  hkVector4f *v6; // rbp
  hkaiSingleCharacterBehavior *v7; // rdi
  hkaiPathRequestInfoOwner *v8; // rdx
  hkaiNavVolumePathRequestInfo *v9; // rax
  int v10; // eax
  hkaiVolumePathfindingUtil::FindPathInput *v11; // rbx

  v4 = priority;
  v5 = numGoals;
  v6 = goals;
  v7 = this;
  if ( this )
    v8 = (hkaiPathRequestInfoOwner *)&this->vfptr;
  else
    v8 = 0i64;
  v9 = hkaiWorld::cancelRequestedNavVolumePath(this->m_world.m_pntr, v8);
  if ( v9 )
  {
    v10 = v9->m_priority;
    if ( v4 > v10 )
      v10 = v4;
    v4 = v10;
  }
  v11 = hkaiCharacterUtil::generateVolumePathRequest(v7->m_world.m_pntr, v7->m_character.m_pntr, v6, v5);
  hkaiWorld::requestPath(v7->m_world.m_pntr, (hkaiPathRequestInfoOwner *)&v7->vfptr, v11, v4);
  hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
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
  hkaiSingleCharacterBehavior *v1; // rdi
  hkaiWorld *v2; // rcx

  v1 = this;
  v2 = this->m_world.m_pntr;
  if ( v2 )
  {
    hkaiWorld::cancelRequestedNavMeshPath(v2, (hkaiPathRequestInfoOwner *)&v1->vfptr);
    hkaiWorld::cancelRequestedNavVolumePath(v1->m_world.m_pntr, (hkaiPathRequestInfoOwner *)&v1->vfptr);
  }
}

// File Line: 71
// RVA: 0xBD5810
bool __fastcall hkaiSingleCharacterBehavior::isNearGoal(hkaiSingleCharacterBehavior *this)
{
  return (unsigned int)(this->m_character.m_pntr->m_state.m_storage - 2) <= 1;
}

