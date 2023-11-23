// File Line: 25
// RVA: 0xCEC810
float __fastcall hkpCompressedSampledHeightFieldShape::getHeightAtImpl(
        hkpCompressedSampledHeightFieldShape *this,
        int x,
        int z)
{
  return (float)((float)this->m_storage.m_data[x + z * (__int64)this->m_xRes] * this->m_scale) + this->m_offset;
}

