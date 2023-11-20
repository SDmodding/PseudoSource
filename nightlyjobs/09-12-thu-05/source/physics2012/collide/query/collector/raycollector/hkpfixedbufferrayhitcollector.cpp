// File Line: 18
// RVA: 0xD40DB0
void hkpFixedBufferRayHitCollector::registerDefaultAddRayHitFunction(void)
{
  g_FixedBufferRayHitCollectorAddRayHitCallbackFunc = hkpFixedBufferRayHitCollector::addRayHitImplementation;
}

// File Line: 24
// RVA: 0xD40DD0
void __fastcall hkpFixedBufferRayHitCollector::addRayHitImplementation(hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfo, hkpFixedBufferRayHitCollector *collector)
{
  int v3; // eax
  hkpShapeRayCastCollectorOutput *v4; // r11
  hkpCdBody *v5; // r10
  hkpWorldRayCastOutput *v6; // r9
  signed __int64 v7; // rcx
  __int64 v8; // rdx
  hkpCollidable *v9; // rax
  hkpCdBody *v10; // rax
  hkpCollidable *i; // rcx
  hkpCdBody *v12; // rax
  int j; // ecx
  int v14; // eax
  __int64 v15; // rcx
  signed __int64 v16; // rdx

  v3 = collector->m_numOutputs.m_storage;
  v4 = hitInfo;
  v5 = cdBody;
  if ( v3 < collector->m_capacity.m_storage )
  {
    v6 = collector->m_nextFreeOutput.m_storage;
    collector->m_numOutputs.m_storage = v3 + 1;
    collector->m_nextFreeOutput.m_storage = v6 + 1;
LABEL_9:
    v6->m_hitFraction = v4->m_hitFraction;
    v6->m_normal = v4->m_normal;
    v6->m_extraInfo = v4->m_extraInfo;
    v9 = collector->m_collidableOnPpu.m_storage;
    if ( v9 )
    {
      v6->m_rootCollidable = v9;
    }
    else
    {
      v10 = v5->m_parent;
      for ( i = (hkpCollidable *)v5; v10; v10 = v10->m_parent )
        i = (hkpCollidable *)v10;
      v6->m_rootCollidable = i;
    }
    v12 = v5->m_parent;
    for ( j = 0; v12; ++j )
      v12 = v12->m_parent;
    v6->m_shapeKeys[j] = -1;
    v14 = j - 1;
    v15 = j - 1;
    if ( v14 >= 0 )
    {
      v16 = (signed __int64)v6 + 4 * (v14 + 8i64);
      do
      {
        --v15;
        v16 -= 4i64;
        *(_DWORD *)(v16 + 4) = v5->m_shapeKey;
        v5 = v5->m_parent;
      }
      while ( v15 >= 0 );
    }
    return;
  }
  v6 = collector->m_rayCastOutputBase.m_storage;
  v7 = (signed __int64)&v6[1];
  if ( v3 > 1 )
  {
    v8 = (unsigned int)(v3 - 1);
    do
    {
      if ( v6->m_hitFraction < *(float *)(v7 + 16) )
        v6 = (hkpWorldRayCastOutput *)v7;
      v7 += 96i64;
      --v8;
    }
    while ( v8 );
  }
  if ( v6->m_hitFraction > v4->m_hitFraction )
    goto LABEL_9;
}

