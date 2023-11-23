// File Line: 14
// RVA: 0xE2C3D0
void __fastcall hkpRejectChassisListener::~hkpRejectChassisListener(hkpRejectChassisListener *this)
{
  this->hkpPhantomOverlapListener::vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpPhantomOverlapListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 24
// RVA: 0xE2C3F0
void __fastcall hkpRejectChassisListener::collidableAddedCallback(
        hkpRejectChassisListener *this,
        hkpCollidableAddedEvent *event)
{
  hkpCollidable *m_collidable; // rax

  m_collidable = event->m_collidable;
  if ( m_collidable == *(hkpCollidable **)&this->m_memSizeAndFlags || m_collidable->m_broadPhaseHandle.m_type != 1 )
    event->m_collidableAccept = HK_COLLIDABLE_REJECT;
}

// File Line: 33
// RVA: 0xE2C410
void __fastcall hkpRejectChassisListener::collidableRemovedCallback(
        hkpRejectChassisListener *this,
        hkpCollidableRemovedEvent *event)
{
  ;
}

