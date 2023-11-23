// File Line: 17
// RVA: 0xE106E0
void __fastcall hkpEasePenetrationAction::hkpEasePenetrationAction(
        hkpEasePenetrationAction *this,
        hkpEntity *entity,
        float duration)
{
  hkpUnaryAction::hkpUnaryAction(this, entity, 0i64);
  this->m_duration = duration;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEasePenetrationAction::`vftable;
  this->m_timePassed = 0.0;
  this->m_originalAllowedPenetrationDepth = entity->m_collidable.m_allowedPenetrationDepth;
  *(_QWORD *)&this->m_initialAllowedPenetrationDepthMultiplier = 1086324736i64;
  this->m_reducePenetrationDistance = 1;
  this->m_initialContactDepthMultiplier = 0.2;
}

// File Line: 31
// RVA: 0xE10750
void __fastcall hkpEasePenetrationAction::~hkpEasePenetrationAction(hkpEasePenetrationAction *this)
{
  hkpEntity *m_entity; // rdx

  m_entity = this->m_entity;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEasePenetrationAction::`vftable;
  if ( m_entity )
    m_entity->m_collidable.m_allowedPenetrationDepth = this->m_originalAllowedPenetrationDepth;
  hkpUnaryAction::~hkpUnaryAction(this);
}

// File Line: 40
// RVA: 0xE10780
void __fastcall hkpEasePenetrationAction::applyAction(hkpEasePenetrationAction *this, hkStepInfo *stepInfo)
{
  __m128 v2; // xmm7
  float m_originalAllowedPenetrationDepth; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  hkpEntity *m_entity; // r12
  __int64 v9; // rdi
  int v10; // r14d
  __m128 v11; // xmm7
  __int64 v12; // r15
  hkpContactMgr *m_contactMgr; // rsi
  hkBaseObjectVtbl *vfptr; // rax
  int v15; // ebx
  __int64 v16; // rax
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  float v19; // xmm0_4
  bool v20; // cf
  char *v21; // [rsp+20h] [rbp-58h] BYREF
  int v22; // [rsp+28h] [rbp-50h]
  int v23; // [rsp+2Ch] [rbp-4Ch]
  __m128 v24; // [rsp+30h] [rbp-48h]

  m_originalAllowedPenetrationDepth = this->m_originalAllowedPenetrationDepth;
  v6 = (float)(m_originalAllowedPenetrationDepth * this->m_initialAllowedPenetrationDepthMultiplier)
     + this->m_initialAdditionalAllowedPenetrationDepth;
  this->m_entity->m_collidable.m_allowedPenetrationDepth = (float)((float)((float)(m_originalAllowedPenetrationDepth - v6)
                                                                         * this->m_timePassed)
                                                                 / this->m_duration)
                                                         + v6;
  if ( this->m_reducePenetrationDistance )
  {
    v7 = 1.0 - this->m_initialContactDepthMultiplier;
    m_entity = this->m_entity;
    v24 = v2;
    v9 = 0i64;
    v10 = 0;
    v2.m128_f32[0] = (float)((float)(v7 * this->m_timePassed) / this->m_duration)
                   + this->m_initialContactDepthMultiplier;
    v11 = _mm_shuffle_ps(v2, v2, 0);
    if ( m_entity->m_collidable.m_collisionEntries.m_size > 0 )
    {
      v12 = 0i64;
      do
      {
        m_contactMgr = m_entity->m_collidable.m_collisionEntries.m_data[v12].m_agentEntry->m_contactMgr;
        if ( !((unsigned int (__fastcall *)(hkpContactMgr *))m_contactMgr->vfptr[6].__first_virtual_table_function__)(m_contactMgr) )
        {
          vfptr = m_contactMgr->vfptr;
          v21 = 0i64;
          v22 = 0;
          v23 = 0x80000000;
          vfptr[6].__vecDelDtor(m_contactMgr, (unsigned int)&v21);
          v15 = 0;
          if ( v22 > 0 )
          {
            do
            {
              v16 = ((__int64 (__fastcall *)(hkpContactMgr *, _QWORD))m_contactMgr->vfptr[5].__first_virtual_table_function__)(
                      m_contactMgr,
                      *(unsigned __int16 *)&v21[v9]);
              v17 = *(__m128 *)(v16 + 16);
              v18 = _mm_shuffle_ps(v17, v17, 255);
              if ( v18.m128_f32[0] < 0.0 )
                *(__m128 *)(v16 + 16) = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, _mm_mul_ps(v11, v18)), 196);
              ++v15;
              v9 += 2i64;
            }
            while ( v15 < v22 );
            v9 = 0i64;
          }
          v22 = 0;
          if ( v23 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v21,
              2 * (v23 & 0x3FFFFFFF));
          v21 = 0i64;
          v23 = 0x80000000;
        }
        ++v10;
        ++v12;
      }
      while ( v10 < m_entity->m_collidable.m_collisionEntries.m_size );
    }
  }
  v19 = stepInfo->m_deltaTime.m_storage + this->m_timePassed;
  v20 = v19 < this->m_duration;
  this->m_timePassed = v19;
  if ( !v20 )
  {
    this->m_entity->m_collidable.m_allowedPenetrationDepth = this->m_originalAllowedPenetrationDepth;
    hkpWorld::removeAction(this->m_entity->m_world, this);
  }
}

// File Line: 88
// RVA: 0xE10990
hkpAction *__fastcall hkpEasePenetrationAction::clone(
        hkpEasePenetrationAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  return 0i64;
}

