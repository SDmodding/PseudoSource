// File Line: 28
// RVA: 0xCF36E0
void __fastcall hkpFixedBufferCdPointCollector::sortHits(hkpFixedBufferCdPointCollector *this)
{
  int m_storage; // r8d

  m_storage = this->m_numPoints.m_storage;
  if ( m_storage > 1 )
    hkAlgorithm::quickSortRecursive<hkpRootCdPoint,hkAlgorithm::less<hkpRootCdPoint>>(
      this->m_pointsArrayBase.m_storage,
      0,
      m_storage - 1,
      0);
}

// File Line: 34
// RVA: 0xCF3710
void hkpFixedBufferCdPointCollector::registerDefaultAddCdPointFunction(void)
{
  g_FixedBufferCdPointCollectorAddCdPointCallbackFunc = hkpFixedBufferCdPointCollector::addCdPointImplementation;
}

// File Line: 39
// RVA: 0xCF3730
void __fastcall hkpFixedBufferCdPointCollector::registerCustomAddCdPointFunction(
        void (__fastcall *func)(hkpCdPoint *, hkpFixedBufferCdPointCollector *))
{
  g_FixedBufferCdPointCollectorAddCdPointCallbackFunc = func;
}

// File Line: 44
// RVA: 0xCF3840
void __fastcall setHit(hkpRootCdPoint *insertAt, hkpCdPoint *event)
{
  hkpCollidable *m_cdBodyA; // r8
  hkpCollidable *i; // rax
  hkpCollidable *m_cdBodyB; // rcx
  hkpCollidable *j; // rax

  insertAt->m_contact.m_position = event->m_contact.m_position;
  insertAt->m_contact.m_separatingNormal = event->m_contact.m_separatingNormal;
  m_cdBodyA = (hkpCollidable *)event->m_cdBodyA;
  for ( i = (hkpCollidable *)m_cdBodyA->m_parent; i; i = (hkpCollidable *)i->m_parent )
    m_cdBodyA = i;
  insertAt->m_rootCollidableA = m_cdBodyA;
  m_cdBodyB = (hkpCollidable *)event->m_cdBodyB;
  for ( j = (hkpCollidable *)m_cdBodyB->m_parent; j; j = (hkpCollidable *)j->m_parent )
    m_cdBodyB = j;
  insertAt->m_rootCollidableB = m_cdBodyB;
  insertAt->m_shapeKeyA = event->m_cdBodyA->m_shapeKey;
  insertAt->m_shapeKeyB = event->m_cdBodyB->m_shapeKey;
}

// File Line: 58
// RVA: 0xCF3740
void __fastcall hkpFixedBufferCdPointCollector::addCdPointImplementation(
        hkpCdPoint *event,
        hkpFixedBufferCdPointCollector *collector)
{
  hkpFixedBufferCdPointCollector *v2; // r11
  int m_storage; // edx
  __int64 v5; // rax
  __int64 v6; // r11
  __int64 v7; // r10
  hkpRootCdPoint *v8; // rax
  hkpRootCdPoint *v9; // r10
  __m128 *p_m_quad; // rcx
  unsigned __int64 v11; // r10
  __m128 *v12; // rdx

  v2 = collector;
  m_storage = collector->m_capacity.m_storage;
  if ( m_storage )
  {
    v5 = v2->m_numPoints.m_storage;
    if ( (int)v5 >= m_storage )
    {
      v7 = v5 << 6;
      v8 = v2->m_pointsArrayBase.m_storage;
      v9 = (hkpRootCdPoint *)((char *)v8 + v7);
      p_m_quad = &v8[1].m_contact.m_position.m_quad;
      if ( &v8[1] < v9 )
      {
        do
        {
          if ( _mm_shuffle_ps(p_m_quad[1], p_m_quad[1], 255).m128_f32[0] > _mm_shuffle_ps(
                                                                             v8->m_contact.m_separatingNormal.m_quad,
                                                                             v8->m_contact.m_separatingNormal.m_quad,
                                                                             255).m128_f32[0] )
            v8 = (hkpRootCdPoint *)p_m_quad;
          p_m_quad += 4;
        }
        while ( p_m_quad < (__m128 *)v9 );
      }
      if ( _mm_shuffle_ps(event->m_contact.m_separatingNormal.m_quad, event->m_contact.m_separatingNormal.m_quad, 255).m128_f32[0] < _mm_shuffle_ps(v8->m_contact.m_separatingNormal.m_quad, v8->m_contact.m_separatingNormal.m_quad, 255).m128_f32[0] )
      {
        setHit(v8, event);
        v8 = v2->m_pointsArrayBase.m_storage;
        v12 = &v8[1].m_contact.m_position.m_quad;
        if ( (unsigned __int64)&v8[1] < v11 )
        {
          do
          {
            if ( _mm_shuffle_ps(v12[1], v12[1], 255).m128_f32[0] > _mm_shuffle_ps(
                                                                     v8->m_contact.m_separatingNormal.m_quad,
                                                                     v8->m_contact.m_separatingNormal.m_quad,
                                                                     255).m128_f32[0] )
              v8 = (hkpRootCdPoint *)v12;
            v12 += 4;
          }
          while ( (unsigned __int64)v12 < v11 );
        }
      }
      LODWORD(v2->m_earlyOutDistance) = v8->m_contact.m_separatingNormal.m_quad.m128_i32[3];
    }
    else
    {
      setHit(&v2->m_pointsArrayBase.m_storage[v5], event);
      ++*(_DWORD *)(v6 + 28);
    }
  }
}

