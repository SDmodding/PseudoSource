// File Line: 18
// RVA: 0xD40DB0
void hkpFixedBufferRayHitCollector::registerDefaultAddRayHitFunction(void)
{
  g_FixedBufferRayHitCollectorAddRayHitCallbackFunc = hkpFixedBufferRayHitCollector::addRayHitImplementation;
}

// File Line: 24
// RVA: 0xD40DD0
void __fastcall hkpFixedBufferRayHitCollector::addRayHitImplementation(
        hkpCdBody *cdBody,
        hkpShapeRayCastCollectorOutput *hitInfo,
        hkpFixedBufferRayHitCollector *collector)
{
  int m_storage; // eax
  hkpWorldRayCastOutput *v6; // r9
  hkpWorldRayCastOutput *v7; // rcx
  __int64 v8; // rdx
  hkpCollidable *v9; // rax
  hkpCdBody *m_parent; // rax
  hkpCdBody *i; // rcx
  hkpCdBody *v12; // rax
  int j; // ecx
  int v14; // eax
  __int64 v15; // rcx
  unsigned int *v16; // rdx

  m_storage = collector->m_numOutputs.m_storage;
  if ( m_storage < collector->m_capacity.m_storage )
  {
    v6 = collector->m_nextFreeOutput.m_storage;
    collector->m_numOutputs.m_storage = m_storage + 1;
    collector->m_nextFreeOutput.m_storage = v6 + 1;
LABEL_9:
    v6->m_hitFraction = hitInfo->m_hitFraction;
    v6->m_normal = hitInfo->m_normal;
    v6->m_extraInfo = hitInfo->m_extraInfo;
    v9 = collector->m_collidableOnPpu.m_storage;
    if ( v9 )
    {
      v6->m_rootCollidable = v9;
    }
    else
    {
      m_parent = cdBody->m_parent;
      for ( i = cdBody; m_parent; m_parent = m_parent->m_parent )
        i = m_parent;
      v6->m_rootCollidable = (hkpCollidable *)i;
    }
    v12 = cdBody->m_parent;
    for ( j = 0; v12; ++j )
      v12 = v12->m_parent;
    v6->m_shapeKeys[j] = -1;
    v14 = j - 1;
    v15 = j - 1;
    if ( v14 >= 0 )
    {
      v16 = &v6->m_shapeKeys[v14];
      do
      {
        --v15;
        --v16;
        v16[1] = cdBody->m_shapeKey;
        cdBody = cdBody->m_parent;
      }
      while ( v15 >= 0 );
    }
    return;
  }
  v6 = collector->m_rayCastOutputBase.m_storage;
  v7 = v6 + 1;
  if ( m_storage > 1 )
  {
    v8 = (unsigned int)(m_storage - 1);
    do
    {
      if ( v6->m_hitFraction < v7->m_hitFraction )
        v6 = v7;
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  if ( v6->m_hitFraction > hitInfo->m_hitFraction )
    goto LABEL_9;
}

