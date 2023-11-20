// File Line: 124
// RVA: 0xD433D0
signed __int64 __fastcall hkpAgentNnTrack::getSectorSize(hkpAgentNnTrack *this, int sectorIndex)
{
  signed __int64 result; // rax

  if ( sectorIndex + 1 == this->m_sectors.m_size )
    result = this->m_bytesUsedInLastSector;
  else
    result = 960i64;
  return result;
}

