// File Line: 14
// RVA: 0xE2C3D0
void __fastcall hkpRejectChassisListener::~hkpRejectChassisListener(hkpRejectChassisListener *this)
{
  this->vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpPhantomOverlapListener::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 24
// RVA: 0xE2C3F0
void __fastcall hkpRejectChassisListener::collidableAddedCallback(hkpRejectChassisListener *this, hkpCollidableAddedEvent *event)
{
  hkpCollidable *v2; // rax

  v2 = event->m_collidable;
  if ( v2 == *(hkpCollidable **)&this->m_memSizeAndFlags || v2->m_broadPhaseHandle.m_type != 1 )
    event->m_collidableAccept = 1;
}

// File Line: 33
// RVA: 0xE2C410
void __fastcall hkpRejectChassisListener::collidableRemovedCallback(hkpRejectChassisListener *this, hkpCollidableRemovedEvent *event)
{
  ;
}

