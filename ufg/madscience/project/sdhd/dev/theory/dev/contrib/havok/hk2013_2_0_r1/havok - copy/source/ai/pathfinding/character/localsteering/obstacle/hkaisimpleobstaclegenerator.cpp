// File Line: 14
// RVA: 0xBE3640
void __fastcall hkaiSimpleObstacleGenerator::hkaiSimpleObstacleGenerator(hkaiSimpleObstacleGenerator *this)
{
  hkaiSimpleObstacleGenerator *v1; // rbx

  v1 = this;
  hkaiObstacleGenerator::hkaiObstacleGenerator((hkaiObstacleGenerator *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkaiSimpleObstacleGenerator::`vftable;
  v1->m_localAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v1->m_localAabb.m_max.m_quad = _mm_xor_ps(
                                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                   v1->m_localAabb.m_min.m_quad);
}

// File Line: 19
// RVA: 0xBE36A0
void __fastcall hkaiSimpleObstacleGenerator::getAabb(hkaiSimpleObstacleGenerator *this, hkAabb *aabbOut)
{
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h]

  extraRadius.m_real = 0i64;
  hkAabbUtil::calcAabb(&this->m_transform, &this->m_localAabb, &extraRadius, aabbOut);
}

// File Line: 25
// RVA: 0xBE36E0
void __fastcall hkaiSimpleObstacleGenerator::calcAabb(hkaiSimpleObstacleGenerator *this)
{
  hkaiObstacleGenerator::calcLocalAabb((hkaiObstacleGenerator *)&this->vfptr, &this->m_localAabb);
}

// File Line: 30
// RVA: 0xBE36D0
void __fastcall hkaiSimpleObstacleGenerator::recalcCachedData(hkaiSimpleObstacleGenerator *this)
{
  hkaiSimpleObstacleGenerator::calcAabb(this);
}

// File Line: 35
// RVA: 0xBE3700
void __fastcall hkaiSimpleObstacleGenerator::_checkLocalAabb(hkaiSimpleObstacleGenerator *this)
{
  ;
}

