// File Line: 13
// RVA: 0xD31780
void __fastcall hkpSymmetricAgentFlipCollector::addCdPoint(hkpSymmetricAgentFlipCollector *this, hkpCdPoint *point)
{
  hkpSymmetricAgentFlipCollector *v2; // rbx
  hkpCdPointCollector *v3; // rcx
  __m128 v4; // xmm3
  __m128 v5; // xmm3
  __m128 v6; // [rsp+20h] [rbp-48h]
  __m128 v7; // [rsp+30h] [rbp-38h]
  __m128 v8; // [rsp+40h] [rbp-28h]
  hkpCdBody *v9; // [rsp+50h] [rbp-18h]
  hkpCdBody *v10; // [rsp+58h] [rbp-10h]

  v2 = this;
  v3 = this->m_collector;
  v4 = _mm_mul_ps(
         _mm_shuffle_ps(point->m_contact.m_separatingNormal.m_quad, point->m_contact.m_separatingNormal.m_quad, 255),
         point->m_contact.m_separatingNormal.m_quad);
  v9 = point->m_cdBodyB;
  v5 = _mm_add_ps(v4, point->m_contact.m_position.m_quad);
  v10 = point->m_cdBodyA;
  v6 = v5;
  v7 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
         point->m_contact.m_separatingNormal.m_quad);
  v8 = v7;
  v3->vfptr->addCdPoint(v3, (hkpCdPoint *)&v6);
  v2->m_earlyOutDistance = v2->m_collector->m_earlyOutDistance;
}

// File Line: 23
// RVA: 0xD31800
void __fastcall hkpSymmetricAgentFlipCastCollector::addCdPoint(hkpSymmetricAgentFlipCastCollector *this, hkpCdPoint *point)
{
  hkVector4f v2; // xmm2
  hkpSymmetricAgentFlipCastCollector *v3; // rbx
  __m128 v4; // xmm3
  hkpCdPointCollector *v5; // rcx
  hkpCdBody *v6; // rax
  __m128 v7; // xmm3
  __m128 v8; // [rsp+20h] [rbp-48h]
  __m128 v9; // [rsp+30h] [rbp-38h]
  __m128 v10; // [rsp+40h] [rbp-28h]
  hkpCdBody *v11; // [rsp+50h] [rbp-18h]
  hkpCdBody *v12; // [rsp+58h] [rbp-10h]

  v2.m_quad = (__m128)point->m_contact.m_separatingNormal;
  v3 = this;
  v4 = _mm_mul_ps(_mm_shuffle_ps(v2.m_quad, v2.m_quad, 255), this->m_path.m_quad);
  v5 = this->m_collector;
  v11 = point->m_cdBodyB;
  v6 = point->m_cdBodyA;
  v7 = _mm_add_ps(v4, point->m_contact.m_position.m_quad);
  v9 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v2.m_quad);
  v12 = v6;
  v10 = v9;
  v8 = v7;
  v5->vfptr->addCdPoint(v5, (hkpCdPoint *)&v8);
  v3->m_earlyOutDistance = v3->m_collector->m_earlyOutDistance;
}

// File Line: 39
// RVA: 0xD31880
void __fastcall hkpSymmetricAgentFlipBodyCollector::addCdBodyPair(hkpSymmetricAgentFlipBodyCollector *this, hkpCdBody *bodyA, hkpCdBody *bodyB)
{
  hkpSymmetricAgentFlipBodyCollector *v3; // rbx

  v3 = this;
  this->m_collector->vfptr->addCdBodyPair(this->m_collector, bodyB, bodyA);
  v3->m_earlyOut.m_bool = v3->m_collector->m_earlyOut.m_bool;
}

