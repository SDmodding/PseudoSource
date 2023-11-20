// File Line: 20
// RVA: 0x9DCD0
void __fastcall hkpEntityListener::~hkpEntityListener(hkpEntityListener *this)
{
  this->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable';
}

// File Line: 30
// RVA: 0xB7EA0
void __fastcall hkpEntityListener::entityShapeSetCallback(hkpEntityListener *this, hkpEntity *entity)
{
  hkpEntity *v2; // rbx
  hkpEntityListener *v3; // rdi

  v2 = entity;
  v3 = this;
  if ( entity->m_world )
  {
    ((void (*)(void))this->vfptr->entityRemovedCallback)();
    v3->vfptr->entityAddedCallback(v3, v2);
  }
}

