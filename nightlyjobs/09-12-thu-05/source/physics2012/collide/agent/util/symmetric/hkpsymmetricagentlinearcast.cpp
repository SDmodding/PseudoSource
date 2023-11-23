// File Line: 13
// RVA: 0xD31780
void __fastcall hkpSymmetricAgentFlipCollector::addCdPoint(hkpSymmetricAgentFlipCollector *this, hkpCdPoint *point)
{
  hkpCdPointCollector *m_collector; // rcx
  __m128 v4; // xmm3
  __m128 v5; // xmm3
  __m128 v6; // [rsp+20h] [rbp-48h] BYREF
  __m128 v7; // [rsp+30h] [rbp-38h]
  __m128 v8; // [rsp+40h] [rbp-28h]
  hkpCdBody *m_cdBodyB; // [rsp+50h] [rbp-18h]
  hkpCdBody *m_cdBodyA; // [rsp+58h] [rbp-10h]

  m_collector = this->m_collector;
  v4 = _mm_mul_ps(
         _mm_shuffle_ps(point->m_contact.m_separatingNormal.m_quad, point->m_contact.m_separatingNormal.m_quad, 255),
         point->m_contact.m_separatingNormal.m_quad);
  m_cdBodyB = point->m_cdBodyB;
  v5 = _mm_add_ps(v4, point->m_contact.m_position.m_quad);
  m_cdBodyA = point->m_cdBodyA;
  v6 = v5;
  v7 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
         point->m_contact.m_separatingNormal.m_quad);
  v8 = v7;
  m_collector->vfptr->addCdPoint(m_collector, (hkpCdPoint *)&v6);
  this->m_earlyOutDistance = this->m_collector->m_earlyOutDistance;
}

// File Line: 23
// RVA: 0xD31800
void __fastcall hkpSymmetricAgentFlipCastCollector::addCdPoint(
        hkpSymmetricAgentFlipCastCollector *this,
        hkpCdPoint *point)
{
  hkVector4f v2; // xmm2
  __m128 v4; // xmm3
  hkpCdPointCollector *m_collector; // rcx
  hkpCdBody *m_cdBodyA; // rax
  __m128 v7; // xmm3
  __m128 v8; // [rsp+20h] [rbp-48h] BYREF
  __m128 v9; // [rsp+30h] [rbp-38h]
  __m128 v10; // [rsp+40h] [rbp-28h]
  hkpCdBody *m_cdBodyB; // [rsp+50h] [rbp-18h]
  hkpCdBody *v12; // [rsp+58h] [rbp-10h]

  v2.m_quad = (__m128)point->m_contact.m_separatingNormal;
  v4 = _mm_mul_ps(_mm_shuffle_ps(v2.m_quad, v2.m_quad, 255), this->m_path.m_quad);
  m_collector = this->m_collector;
  m_cdBodyB = point->m_cdBodyB;
  m_cdBodyA = point->m_cdBodyA;
  v7 = _mm_add_ps(v4, point->m_contact.m_position.m_quad);
  v9 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v2.m_quad);
  v12 = m_cdBodyA;
  v10 = v9;
  v8 = v7;
  m_collector->vfptr->addCdPoint(m_collector, (hkpCdPoint *)&v8);
  this->m_earlyOutDistance = this->m_collector->m_earlyOutDistance;
}

// File Line: 39
// RVA: 0xD31880
void __fastcall hkpSymmetricAgentFlipBodyCollector::addCdBodyPair(
        hkpSymmetricAgentFlipBodyCollector *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB)
{
  this->m_collector->vfptr->addCdBodyPair(this->m_collector, bodyB, bodyA);
  this->m_earlyOut.m_bool = this->m_collector->m_earlyOut.m_bool;
}

