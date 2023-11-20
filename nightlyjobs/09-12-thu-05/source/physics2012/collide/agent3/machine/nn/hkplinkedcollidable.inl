// File Line: 11
// RVA: 0xD555F0
void __fastcall hkpLinkedCollidable::hkpLinkedCollidable(hkpLinkedCollidable *this, hkpShape *shape, hkMotionState *ms, int type)
{
  hkpTypedBroadPhaseHandle *v4; // rbx
  hkpLinkedCollidable *v5; // rdi

  v4 = &this->m_broadPhaseHandle;
  this->m_shape = shape;
  this->m_motion = ms;
  this->m_shapeKey = -1;
  v5 = this;
  this->m_parent = 0i64;
  this->m_ownerOffset = 0;
  v4->m_id = 0;
  v4->m_type = type;
  v4->m_collisionFilterInfo = 0;
  *(_WORD *)&v4->m_ownerOffset = -129;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&this->m_boundingVolumeData);
  v5->m_allowedPenetrationDepth = -1.0;
  v4->m_ownerOffset = (_BYTE)v5 - (_BYTE)v4;
  v5->m_shapeSizeOnSpu = 0;
  v5->m_forceCollideOntoPpu = 8;
  v5->m_collisionEntries.m_data = 0i64;
  v5->m_collisionEntries.m_size = 0;
  v5->m_collisionEntries.m_capacityAndFlags = 2147483648;
}

