// File Line: 43
// RVA: 0xE10A00
void __fastcall hkpEaseConstraintsAction::hkpEaseConstraintsAction(
        hkpEaseConstraintsAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        unsigned __int64 userData)
{
  hkpConstraintUtils::CollectConstraintsFilter collectionFilter; // [rsp+30h] [rbp+8h] BYREF

  hkpArrayAction::hkpArrayAction(this, entities, userData);
  this->m_duration = -1.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEaseConstraintsAction::`vftable;
  this->m_timePassed = 0.0;
  this->m_originalConstraints.m_data = 0i64;
  this->m_originalConstraints.m_size = 0;
  this->m_originalConstraints.m_capacityAndFlags = 0x80000000;
  this->m_originalLimits.m_data = 0i64;
  this->m_originalLimits.m_size = 0;
  this->m_originalLimits.m_capacityAndFlags = 0x80000000;
  collectionFilter.vfptr = (hkpConstraintUtils::CollectConstraintsFilterVtbl *)&hkpEaseConstraintsAction::CollectSupportedConstraints::`vftable;
  hkpConstraintUtils::collectConstraints(entities, &this->m_originalConstraints, &collectionFilter);
  hkpEaseConstraintsAction::_saveLimits(&this->m_originalLimits, &this->m_originalConstraints);
}

// File Line: 57
// RVA: 0xE10AB0
void __fastcall hkpEaseConstraintsAction::loosenConstraints(hkpEaseConstraintsAction *this)
{
  this->m_duration = -1.0;
  this->m_timePassed = 0.0;
  hkpEaseConstraintsAction::_loosenConstraints(&this->m_originalConstraints);
}

// File Line: 76
// RVA: 0xE10AD0
void __fastcall hkpEaseConstraintsAction::restoreConstraints(hkpEaseConstraintsAction *this, float duration)
{
  this->m_duration = duration;
  this->m_timePassed = 0.0;
  if ( duration == 0.0 )
    hkpEaseConstraintsAction::_restoreLimits(&this->m_originalConstraints, &this->m_originalLimits);
}

// File Line: 100
// RVA: 0xE10B00
void __fastcall hkpEaseConstraintsAction::applyAction(hkpEaseConstraintsAction *this, hkStepInfo *stepInfo)
{
  float m_duration; // xmm1_4
  float m_storage; // xmm6_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  int v7; // edi
  int v8; // esi
  __int64 v9; // r14
  int v10; // eax

  m_duration = this->m_duration;
  if ( m_duration > 0.0 )
  {
    m_storage = stepInfo->m_deltaTime.m_storage;
    v5 = m_storage + this->m_timePassed;
    v6 = m_storage / (float)(m_duration - this->m_timePassed);
    this->m_timePassed = v5;
    if ( v5 < m_duration )
    {
      v7 = 0;
      v8 = 0;
      if ( this->m_originalConstraints.m_size > 0 )
      {
        v9 = 0i64;
        do
        {
          v10 = hkpEaseConstraintsAction::_partiallyRestoreConstraint(
                  this->m_originalConstraints.m_data[v9],
                  &this->m_originalLimits.m_data[v7],
                  v6);
          ++v8;
          ++v9;
          v7 += v10;
        }
        while ( v8 < this->m_originalConstraints.m_size );
      }
    }
    else
    {
      hkpEaseConstraintsAction::restoreConstraints(this, 0.0);
      hkpWorld::removeAction((*this->m_entities.m_data)->m_world, this);
    }
  }
  else if ( m_duration == 0.0 )
  {
    hkpWorld::removeAction(this->m_world, this);
  }
}

// File Line: 157
// RVA: 0xE10BF0
hkpAction *__fastcall hkpEaseConstraintsAction::clone(
        hkpEaseConstraintsAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkErrStream v4; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v4, buf, 512);
  hkOstream::operator<<(&v4, "This action does not support cloning().");
  if ( (unsigned int)hkError::messageError(
                       0x196BAF1u,
                       buf,
                       "Actions\\EaseConstraints\\hkpEaseConstraintsAction.cpp",
                       158) )
    __debugbreak();
  hkOstream::~hkOstream(&v4);
  return 0i64;
}

// File Line: 163
// RVA: 0xE10C60
float __fastcall hkpEaseConstraintsAction::getDuration(hkpEaseConstraintsAction *this)
{
  return this->m_duration;
}

// File Line: 171
// RVA: 0xE10C70
void __fastcall hkpEaseConstraintsAction::_saveLimits(
        hkArray<float,hkContainerHeapAllocator> *dst,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *src)
{
  int v4; // esi
  __int64 v5; // r14
  hkpConstraintData *m_data; // rdi
  int v7; // eax
  __int64 v8; // rbp
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  float *v12; // rcx
  __int64 m_size; // rbp
  int v14; // r9d
  int v15; // eax
  int v16; // eax
  float *v17; // rcx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF
  hkResult v19; // [rsp+70h] [rbp+18h] BYREF

  v4 = 0;
  if ( src->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_data = src->m_data[v5]->m_data;
      v7 = ((__int64 (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
      if ( v7 == 2 )
      {
        m_size = dst->m_size;
        v14 = m_size + 2;
        v15 = dst->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v15 >= (int)m_size + 2 )
        {
          v19.m_enum = HK_SUCCESS;
        }
        else
        {
          v16 = 2 * v15;
          if ( v14 < v16 )
            v14 = v16;
          hkArrayUtil::_reserve(&v19, &hkContainerHeapAllocator::s_alloc, (const void **)&dst->m_data, v14, 4);
        }
        dst->m_size += 2;
        v17 = dst->m_data;
        v17[m_size] = *(float *)&m_data[10].m_userData;
        v17[m_size + 1] = *(float *)(&m_data[10].m_referenceCount + 1);
      }
      else if ( v7 == 7 )
      {
        v8 = dst->m_size;
        v9 = v8 + 5;
        v10 = dst->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v10 >= (int)v8 + 5 )
        {
          result.m_enum = HK_SUCCESS;
        }
        else
        {
          v11 = 2 * v10;
          if ( v9 < v11 )
            v9 = v11;
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&dst->m_data, v9, 4);
        }
        dst->m_size += 5;
        v12 = dst->m_data;
        v12[v8] = *(float *)(&m_data[14].m_referenceCount + 1);
        v12[v8 + 1] = *((float *)&m_data[15].m_userData + 1);
        v12[v8 + 2] = *(float *)&m_data[15].m_userData;
        v12[v8 + 3] = *((float *)&m_data[13].vfptr + 1);
        v12[v8 + 4] = *(float *)&m_data[13].vfptr;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < src->m_size );
  }
}

// File Line: 207
// RVA: 0xE10DE0
void __fastcall hkpEaseConstraintsAction::_restoreLimits(
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *dst,
        hkArray<float,hkContainerHeapAllocator> *src)
{
  int v2; // ebx
  int v5; // esi
  __int64 i; // r14
  hkpConstraintData *m_data; // rdi
  int v8; // eax
  __int64 v9; // rcx
  int v10; // ebx
  int v11; // ebx
  __int64 v12; // rcx

  v2 = 0;
  v5 = 0;
  if ( dst->m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      m_data = dst->m_data[i]->m_data;
      v8 = ((__int64 (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
      if ( v8 == 2 )
        break;
      if ( v8 == 7 )
      {
        v9 = v2;
        v10 = v2 + 1;
        *(float *)(&m_data[14].m_referenceCount + 1) = src->m_data[v9];
        *(float *)&v9 = src->m_data[v10++];
        HIDWORD(m_data[15].m_userData) = v9;
        *(float *)&v9 = src->m_data[v10++];
        LODWORD(m_data[15].m_userData) = v9;
        *(float *)&v9 = src->m_data[v10];
        v11 = v10 + 1;
        HIDWORD(m_data[13].vfptr) = v9;
        *(float *)&m_data[13].vfptr = src->m_data[v11];
LABEL_7:
        v2 = v11 + 1;
      }
      if ( ++v5 >= dst->m_size )
        return;
    }
    v12 = v2;
    v11 = v2 + 1;
    *(float *)&m_data[10].m_userData = src->m_data[v12];
    *(float *)(&m_data[10].m_referenceCount + 1) = src->m_data[v11];
    goto LABEL_7;
  }
}

// File Line: 252
// RVA: 0xE10EE0
void __fastcall hkpEaseConstraintsAction::_loosenConstraints(
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints)
{
  int v2; // eax
  __int64 i; // rbx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  v2 = constraints->m_size - 1;
  for ( i = v2; i >= 0; --i )
    hkpConstraintDataUtils::loosenConstraintLimits(
      &result,
      constraints->m_data[i]->m_data,
      &constraints->m_data[i]->m_entities[0]->m_motion.m_motionState.m_transform,
      &constraints->m_data[i]->m_entities[1]->m_motion.m_motionState.m_transform);
}

// File Line: 281
// RVA: 0xE10F50
__int64 __fastcall hkpEaseConstraintsAction::_partiallyRestoreConstraint(
        hkpConstraintInstance *runtimeConstraint,
        float *originalLimitsPtr,
        float restorationWeight)
{
  float *m_data; // rbx
  int v5; // eax
  __int64 result; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  hkErrStream v15; // [rsp+20h] [rbp-238h] BYREF
  char buf[512]; // [rsp+40h] [rbp-218h] BYREF

  m_data = (float *)runtimeConstraint->m_data;
  v5 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)m_data + 24i64))(m_data);
  if ( v5 == 2 )
  {
    result = 2i64;
    v14 = m_data[63];
    m_data[64] = (float)((float)(*originalLimitsPtr - m_data[64]) * restorationWeight) + m_data[64];
    m_data[63] = (float)((float)(originalLimitsPtr[1] - v14) * restorationWeight) + v14;
  }
  else if ( v5 == 7 )
  {
    result = 5i64;
    v7 = m_data[95];
    m_data[87] = (float)((float)(*originalLimitsPtr - m_data[87]) * restorationWeight) + m_data[87];
    v8 = (float)((float)(originalLimitsPtr[1] - v7) * restorationWeight) + v7;
    v9 = m_data[94];
    m_data[95] = v8;
    v10 = (float)((float)(originalLimitsPtr[2] - v9) * restorationWeight) + v9;
    v11 = m_data[79];
    m_data[94] = v10;
    v12 = (float)((float)(originalLimitsPtr[3] - v11) * restorationWeight) + v11;
    v13 = m_data[78];
    m_data[79] = v12;
    m_data[78] = (float)((float)(originalLimitsPtr[4] - v13) * restorationWeight) + v13;
  }
  else
  {
    hkErrStream::hkErrStream(&v15, buf, 512);
    hkOstream::operator<<(&v15, "hkpEaseConstraintsAction does not handle this type of constraint.");
    if ( (unsigned int)hkError::messageError(
                         0x2E61BF0Eu,
                         buf,
                         "Actions\\EaseConstraints\\hkpEaseConstraintsAction.cpp",
                         334) )
      __debugbreak();
    hkOstream::~hkOstream(&v15);
    return 0i64;
  }
  return result;
}

