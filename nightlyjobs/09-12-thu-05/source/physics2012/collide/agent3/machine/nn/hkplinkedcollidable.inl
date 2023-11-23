// File Line: 11
// RVA: 0xD555F0
void __fastcall hkpLinkedCollidable::hkpLinkedCollidable(
        hkpLinkedCollidable *this,
        hkpShape *shape,
        hkMotionState *ms,
        char type)
{
  hkpTypedBroadPhaseHandle *p_m_broadPhaseHandle; // rbx

  p_m_broadPhaseHandle = &this->m_broadPhaseHandle;
  this->m_shape = shape;
  this->m_motion = ms;
  this->m_shapeKey = -1;
  this->m_parent = 0i64;
  this->m_ownerOffset = 0;
  this->m_broadPhaseHandle.m_id = 0;
  this->m_broadPhaseHandle.m_type = type;
  this->m_broadPhaseHandle.m_collisionFilterInfo = 0;
  *(_WORD *)&this->m_broadPhaseHandle.m_ownerOffset = -129;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&this->m_boundingVolumeData);
  this->m_allowedPenetrationDepth = -1.0;
  p_m_broadPhaseHandle->m_ownerOffset = (_BYTE)this - (_BYTE)p_m_broadPhaseHandle;
  this->m_shapeSizeOnSpu = 0;
  this->m_forceCollideOntoPpu = 8;
  this->m_collisionEntries.m_data = 0i64;
  this->m_collisionEntries.m_size = 0;
  this->m_collisionEntries.m_capacityAndFlags = 0x80000000;
}

