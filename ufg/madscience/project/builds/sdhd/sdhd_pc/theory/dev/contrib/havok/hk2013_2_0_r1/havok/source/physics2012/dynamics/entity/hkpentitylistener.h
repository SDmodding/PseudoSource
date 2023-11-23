// File Line: 20
// RVA: 0x9DCD0
void __fastcall hkpEntityListener::~hkpEntityListener(hkpEntityListener *this)
{
  this->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
}

// File Line: 30
// RVA: 0xB7EA0
void __fastcall hkpEntityListener::entityShapeSetCallback(hkpEntityListener *this, hkpEntity *entity)
{
  if ( entity->m_world )
  {
    ((void (__fastcall *)(hkpEntityListener *))this->vfptr->entityRemovedCallback)(this);
    this->vfptr->entityAddedCallback(this, entity);
  }
}

