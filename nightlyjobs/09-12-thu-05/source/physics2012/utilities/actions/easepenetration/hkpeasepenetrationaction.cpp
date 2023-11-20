// File Line: 17
// RVA: 0xE106E0
void __fastcall hkpEasePenetrationAction::hkpEasePenetrationAction(hkpEasePenetrationAction *this, hkpEntity *entity, float duration)
{
  hkpEntity *v3; // rbx
  hkpEasePenetrationAction *v4; // rdi

  v3 = entity;
  v4 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, entity, 0i64);
  v4->m_duration = duration;
  v4->vfptr = (hkBaseObjectVtbl *)&hkpEasePenetrationAction::`vftable;
  v4->m_timePassed = 0.0;
  v4->m_originalAllowedPenetrationDepth = v3->m_collidable.m_allowedPenetrationDepth;
  *(_QWORD *)&v4->m_initialAllowedPenetrationDepthMultiplier = 1086324736i64;
  v4->m_reducePenetrationDistance = 1;
  v4->m_initialContactDepthMultiplier = 0.2;
}

// File Line: 31
// RVA: 0xE10750
void __fastcall hkpEasePenetrationAction::~hkpEasePenetrationAction(hkpEasePenetrationAction *this)
{
  hkpEntity *v1; // rdx

  v1 = this->m_entity;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEasePenetrationAction::`vftable;
  if ( v1 )
    v1->m_collidable.m_allowedPenetrationDepth = this->m_originalAllowedPenetrationDepth;
  hkpUnaryAction::~hkpUnaryAction((hkpUnaryAction *)&this->vfptr);
}

// File Line: 40
// RVA: 0xE10780
void __usercall hkpEasePenetrationAction::applyAction(hkpEasePenetrationAction *this@<rcx>, hkStepInfo *stepInfo@<rdx>, __m128 a3@<xmm7>)
{
  float v3; // xmm1_4
  hkStepInfo *v4; // r13
  hkpEasePenetrationAction *v5; // rbp
  float v6; // xmm0_4
  hkpEntity *v7; // r12
  __int64 v8; // rdi
  int v9; // er14
  __m128 v10; // xmm7
  __int64 v11; // r15
  hkpContactMgr *v12; // rsi
  hkBaseObjectVtbl *v13; // rax
  int v14; // ebx
  __int64 v15; // rax
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  float v18; // xmm0_4
  bool v19; // cf
  char *v20; // [rsp+20h] [rbp-58h]
  int v21; // [rsp+28h] [rbp-50h]
  int v22; // [rsp+2Ch] [rbp-4Ch]

  v3 = this->m_originalAllowedPenetrationDepth;
  v4 = stepInfo;
  v5 = this;
  v6 = (float)(v3 * this->m_initialAllowedPenetrationDepthMultiplier) + this->m_initialAdditionalAllowedPenetrationDepth;
  this->m_entity->m_collidable.m_allowedPenetrationDepth = (float)((float)((float)(v3 - v6) * this->m_timePassed)
                                                                 / this->m_duration)
                                                         + v6;
  if ( this->m_reducePenetrationDistance )
  {
    v7 = this->m_entity;
    v8 = 0i64;
    v9 = 0;
    a3.m128_f32[0] = (float)((float)((float)(1.0 - this->m_initialContactDepthMultiplier) * this->m_timePassed)
                           / this->m_duration)
                   + this->m_initialContactDepthMultiplier;
    v10 = _mm_shuffle_ps(a3, a3, 0);
    if ( v7->m_collidable.m_collisionEntries.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        v12 = v7->m_collidable.m_collisionEntries.m_data[v11].m_agentEntry->m_contactMgr;
        if ( !((unsigned int (__fastcall *)(hkpContactMgr *))v12->vfptr[6].__first_virtual_table_function__)(v12) )
        {
          v13 = v12->vfptr;
          v20 = 0i64;
          v21 = 0;
          v22 = 2147483648;
          v13[6].__vecDelDtor((hkBaseObject *)&v12->vfptr, (unsigned int)&v20);
          v14 = v8;
          if ( v21 > 0 )
          {
            do
            {
              v15 = ((__int64 (__fastcall *)(hkpContactMgr *, _QWORD))v12->vfptr[5].__first_virtual_table_function__)(
                      v12,
                      *(unsigned __int16 *)&v20[v8]);
              v16 = *(__m128 *)(v15 + 16);
              v17 = _mm_shuffle_ps(v16, v16, 255);
              if ( v17.m128_f32[0] < 0.0 )
                *(__m128 *)(v15 + 16) = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, _mm_mul_ps(v10, v17)), 196);
              ++v14;
              v8 += 2i64;
            }
            while ( v14 < v21 );
            v8 = 0i64;
          }
          v21 = v8;
          if ( v22 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v20,
              2 * (v22 & 0x3FFFFFFF));
          v20 = 0i64;
          v22 = 2147483648;
        }
        ++v9;
        ++v11;
      }
      while ( v9 < v7->m_collidable.m_collisionEntries.m_size );
    }
  }
  v18 = v4->m_deltaTime.m_storage + v5->m_timePassed;
  v19 = v18 < v5->m_duration;
  v5->m_timePassed = v18;
  if ( !v19 )
  {
    v5->m_entity->m_collidable.m_allowedPenetrationDepth = v5->m_originalAllowedPenetrationDepth;
    hkpWorld::removeAction(v5->m_entity->m_world, (hkpAction *)&v5->vfptr);
  }
}

// File Line: 88
// RVA: 0xE10990
hkpAction *__fastcall hkpEasePenetrationAction::clone(hkpEasePenetrationAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  return 0i64;
}

