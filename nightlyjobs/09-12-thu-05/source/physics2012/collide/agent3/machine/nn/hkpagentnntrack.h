// File Line: 124
// RVA: 0xD433D0
__int64 __fastcall hkpAgentNnTrack::getSectorSize(hkpAgentNnTrack *this, int sectorIndex)
{
  if ( sectorIndex + 1 == this->m_sectors.m_size )
    return this->m_bytesUsedInLastSector;
  else
    return 960i64;
}

