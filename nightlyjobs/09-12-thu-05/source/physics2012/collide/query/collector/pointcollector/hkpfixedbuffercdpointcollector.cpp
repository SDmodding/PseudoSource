// File Line: 28
// RVA: 0xCF36E0
void __fastcall hkpFixedBufferCdPointCollector::sortHits(hkpFixedBufferCdPointCollector *this)
{
  int v1; // er8

  v1 = this->m_numPoints.m_storage;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkpRootCdPoint,hkAlgorithm::less<hkpRootCdPoint>>(
      this->m_pointsArrayBase.m_storage,
      0,
      v1 - 1,
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
void __fastcall hkpFixedBufferCdPointCollector::registerCustomAddCdPointFunction(void (__fastcall *func)(hkpCdPoint *, hkpFixedBufferCdPointCollector *))
{
  g_FixedBufferCdPointCollectorAddCdPointCallbackFunc = func;
}

// File Line: 44
// RVA: 0xCF3840
void __fastcall setHit(hkpRootCdPoint *insertAt, hkpCdPoint *event)
{
  hkpRootCdPoint *v2; // r9
  hkpCollidable *v3; // r8
  hkpCollidable *i; // rax
  hkpCdBody *v5; // rcx
  hkpCdBody *j; // rax

  v2 = insertAt;
  insertAt->m_contact.m_position = event->m_contact.m_position;
  insertAt->m_contact.m_separatingNormal = event->m_contact.m_separatingNormal;
  v3 = (hkpCollidable *)event->m_cdBodyA;
  for ( i = (hkpCollidable *)v3->m_parent; i; i = (hkpCollidable *)i->m_parent )
    v3 = i;
  insertAt->m_rootCollidableA = v3;
  v5 = event->m_cdBodyB;
  for ( j = v5->m_parent; j; j = j->m_parent )
    v5 = j;
  v2->m_rootCollidableB = (hkpCollidable *)v5;
  v2->m_shapeKeyA = event->m_cdBodyA->m_shapeKey;
  v2->m_shapeKeyB = event->m_cdBodyB->m_shapeKey;
}

// File Line: 58
// RVA: 0xCF3740
void __fastcall hkpFixedBufferCdPointCollector::addCdPointImplementation(hkpCdPoint *event, hkpFixedBufferCdPointCollector *collector)
{
  hkpFixedBufferCdPointCollector *v2; // r11
  int v3; // edx
  hkpCdPoint *v4; // r8
  __int64 v5; // rax
  __int64 v6; // r11
  hkpRootCdPoint *v7; // rcx
  __int64 v8; // r10
  hkpRootCdPoint *v9; // rax
  unsigned __int64 v10; // r10
  __m128 *i; // rcx
  unsigned __int64 v12; // r10
  hkpRootCdPoint *v13; // rdx
  __m128 *j; // rdx

  v2 = collector;
  v3 = collector->m_capacity.m_storage;
  v4 = event;
  if ( v3 )
  {
    v5 = v2->m_numPoints.m_storage;
    if ( (signed int)v5 >= v3 )
    {
      v7 = v2->m_pointsArrayBase.m_storage;
      v8 = v5 << 6;
      v9 = v7;
      v10 = (unsigned __int64)v7 + v8;
      for ( i = &v7[1].m_contact.m_position.m_quad; (unsigned __int64)i < v10; i += 4 )
      {
        if ( COERCE_FLOAT(_mm_shuffle_ps(i[1], i[1], 255)) > COERCE_FLOAT(
                                                               _mm_shuffle_ps(
                                                                 v9->m_contact.m_separatingNormal.m_quad,
                                                                 v9->m_contact.m_separatingNormal.m_quad,
                                                                 255)) )
          v9 = (hkpRootCdPoint *)i;
      }
      if ( COERCE_FLOAT(_mm_shuffle_ps(v4->m_contact.m_separatingNormal.m_quad, v4->m_contact.m_separatingNormal.m_quad, 255)) < COERCE_FLOAT(_mm_shuffle_ps(v9->m_contact.m_separatingNormal.m_quad, v9->m_contact.m_separatingNormal.m_quad, 255)) )
      {
        setHit(v9, v4);
        v13 = v2->m_pointsArrayBase.m_storage;
        v9 = v13;
        for ( j = &v13[1].m_contact.m_position.m_quad; (unsigned __int64)j < v12; j += 4 )
        {
          if ( COERCE_FLOAT(_mm_shuffle_ps(j[1], j[1], 255)) > COERCE_FLOAT(
                                                                 _mm_shuffle_ps(
                                                                   v9->m_contact.m_separatingNormal.m_quad,
                                                                   v9->m_contact.m_separatingNormal.m_quad,
                                                                   255)) )
            v9 = (hkpRootCdPoint *)j;
        }
      }
      v2->m_earlyOutDistance = v9->m_contact.m_separatingNormal.m_quad.m128_f32[3];
    }
    else
    {
      setHit(&v2->m_pointsArrayBase.m_storage[v5], event);
      ++*(_DWORD *)(v6 + 28);
    }
  }
}

