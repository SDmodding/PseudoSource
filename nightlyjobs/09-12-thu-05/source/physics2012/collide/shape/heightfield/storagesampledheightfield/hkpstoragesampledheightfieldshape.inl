// File Line: 15
// RVA: 0xCECAE0
float __fastcall hkpStorageSampledHeightFieldShape::getHeightAtImpl(
        hkpStorageSampledHeightFieldShape *this,
        int x,
        int z)
{
  return this->m_storage.m_data[x + z * (__int64)this->m_xRes];
}

// File Line: 29
// RVA: 0xCECB00
hkBool *__fastcall hkpStorageSampledHeightFieldShape::getTriangleFlipImpl(
        hkpStorageSampledHeightFieldShape *this,
        hkBool *result)
{
  result->m_bool = (char)this->m_triangleFlip;
  return result;
}

