// File Line: 74
// RVA: 0xE22A20
void __fastcall hkpSerializedAgentNnEntry::hkpSerializedAgentNnEntry(hkpSerializedAgentNnEntry *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_bodyAId = -1i64;
  this->m_bodyBId = -1i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSerializedAgentNnEntry::`vftable';
  this->m_bodyA = 0i64;
  this->m_bodyB = 0i64;
  this->m_useEntityIds.m_bool = 0;
  this->m_atom.m_type.m_storage = 29;
  *(_DWORD *)&this->m_atom.m_info.m_flags = 196608;
  this->m_atom.m_info.m_contactRadius = 0.0;
  *(_DWORD *)&this->m_atom.m_info.m_internalData1.m_value = 0;
  this->m_atom.m_info.m_rhsRolling[1].m_value = 0;
  this->m_atom.m_info.m_rollingFrictionMultiplier.m_value = 0;
  *(_QWORD *)this->m_atom.m_info.m_data = 0i64;
  *(_QWORD *)&this->m_atom.m_info.m_data[2] = 0i64;
  this->m_propertiesStream.m_data = 0i64;
  this->m_propertiesStream.m_size = 0;
  this->m_propertiesStream.m_capacityAndFlags = 2147483648;
  this->m_contactPoints.m_data = 0i64;
  this->m_contactPoints.m_size = 0;
  this->m_contactPoints.m_capacityAndFlags = 2147483648;
  this->m_cpIdMgr.m_data = 0i64;
  this->m_cpIdMgr.m_size = 0;
  this->m_cpIdMgr.m_capacityAndFlags = 2147483648;
  this->m_trackInfo.m_sectors.m_data = 0i64;
  this->m_trackInfo.m_sectors.m_size = 0;
  this->m_trackInfo.m_sectors.m_capacityAndFlags = 2147483648;
  this->m_trackInfo.m_subTracks.m_data = 0i64;
  this->m_trackInfo.m_subTracks.m_size = 0;
  this->m_trackInfo.m_subTracks.m_capacityAndFlags = 2147483648;
  *(_DWORD *)this->m_endianCheckBuffer = 259;
  this->m_version = 1;
}

