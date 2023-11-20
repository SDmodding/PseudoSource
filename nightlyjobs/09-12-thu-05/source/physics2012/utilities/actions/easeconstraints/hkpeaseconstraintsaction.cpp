// File Line: 43
// RVA: 0xE10A00
void __fastcall hkpEaseConstraintsAction::hkpEaseConstraintsAction(hkpEaseConstraintsAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, unsigned __int64 userData)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v3; // rsi
  hkpEaseConstraintsAction *v4; // r14
  hkpConstraintUtils::CollectConstraintsFilter collectionFilter; // [rsp+30h] [rbp+8h]

  v3 = entities;
  v4 = this;
  hkpArrayAction::hkpArrayAction((hkpArrayAction *)&this->vfptr, entities, userData);
  v4->m_duration = -1.0;
  v4->vfptr = (hkBaseObjectVtbl *)&hkpEaseConstraintsAction::`vftable';
  v4->m_timePassed = 0.0;
  v4->m_originalConstraints.m_data = 0i64;
  v4->m_originalConstraints.m_size = 0;
  v4->m_originalConstraints.m_capacityAndFlags = 2147483648;
  v4->m_originalLimits.m_data = 0i64;
  v4->m_originalLimits.m_size = 0;
  v4->m_originalLimits.m_capacityAndFlags = 2147483648;
  collectionFilter.vfptr = (hkpConstraintUtils::CollectConstraintsFilterVtbl *)&hkpEaseConstraintsAction::CollectSupportedConstraints::`vftable';
  hkpConstraintUtils::collectConstraints(v3, &v4->m_originalConstraints, &collectionFilter);
  hkpEaseConstraintsAction::_saveLimits(&v4->m_originalLimits, &v4->m_originalConstraints);
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
  float v2; // xmm1_4
  hkpEaseConstraintsAction *v3; // rbx
  float v4; // xmm3_4
  float v5; // xmm6_4
  float v6; // xmm3_4
  float v7; // xmm6_4
  int v8; // edi
  int v9; // esi
  __int64 v10; // r14
  int v11; // eax

  v2 = this->m_duration;
  v3 = this;
  if ( v2 > 0.0 )
  {
    v4 = stepInfo->m_deltaTime.m_storage;
    v5 = v4;
    v6 = v4 + this->m_timePassed;
    v7 = v5 / (float)(v2 - this->m_timePassed);
    this->m_timePassed = v6;
    if ( v6 < v2 )
    {
      v8 = 0;
      v9 = 0;
      if ( this->m_originalConstraints.m_size > 0 )
      {
        v10 = 0i64;
        do
        {
          v11 = hkpEaseConstraintsAction::_partiallyRestoreConstraint(
                  v3->m_originalConstraints.m_data[v10],
                  &v3->m_originalLimits.m_data[v8],
                  v7);
          ++v9;
          ++v10;
          v8 += v11;
        }
        while ( v9 < v3->m_originalConstraints.m_size );
      }
    }
    else
    {
      hkpEaseConstraintsAction::restoreConstraints(this, 0.0);
      hkpWorld::removeAction((*v3->m_entities.m_data)->m_world, (hkpAction *)&v3->vfptr);
    }
  }
  else if ( v2 == 0.0 )
  {
    hkpWorld::removeAction(this->m_world, (hkpAction *)&this->vfptr);
  }
}

// File Line: 157
// RVA: 0xE10BF0
hkpAction *__fastcall hkpEaseConstraintsAction::clone(hkpEaseConstraintsAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkErrStream v4; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  hkErrStream::hkErrStream(&v4, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v4.vfptr, "This action does not support cloning().");
  if ( (unsigned int)hkError::messageError(
                       26655473,
                       &buf,
                       "Actions\\EaseConstraints\\hkpEaseConstraintsAction.cpp",
                       158) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v4.vfptr);
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
void __fastcall hkpEaseConstraintsAction::_saveLimits(hkArray<float,hkContainerHeapAllocator> *dst, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *src)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v2; // r15
  hkArray<float,hkContainerHeapAllocator> *v3; // rbx
  int v4; // esi
  __int64 v5; // r14
  hkpConstraintData *v6; // rdi
  int v7; // eax
  __int64 v8; // rbp
  int v9; // er9
  int v10; // eax
  int v11; // eax
  float *v12; // rcx
  __int64 v13; // rbp
  int v14; // er9
  int v15; // eax
  int v16; // eax
  float *v17; // rcx
  hkResult result; // [rsp+68h] [rbp+10h]
  hkResult v19; // [rsp+70h] [rbp+18h]

  v2 = src;
  v3 = dst;
  v4 = 0;
  if ( src->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v2->m_data[v5]->m_data;
      v7 = ((__int64 (__fastcall *)(hkpConstraintData *))v6->vfptr[1].__first_virtual_table_function__)(v6);
      if ( v7 == 2 )
      {
        v13 = v3->m_size;
        v14 = v13 + 2;
        v15 = v3->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v15 >= (signed int)v13 + 2 )
        {
          v19.m_enum = 0;
        }
        else
        {
          v16 = 2 * v15;
          if ( v14 < v16 )
            v14 = v16;
          hkArrayUtil::_reserve(&v19, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v14, 4);
        }
        v3->m_size += 2;
        v17 = v3->m_data;
        v17[v13] = *(float *)&v6[10].m_userData;
        v17[v13 + 1] = *(float *)(&v6[10].m_referenceCount + 1);
      }
      else if ( v7 == 7 )
      {
        v8 = v3->m_size;
        v9 = v8 + 5;
        v10 = v3->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v10 >= (signed int)v8 + 5 )
        {
          result.m_enum = 0;
        }
        else
        {
          v11 = 2 * v10;
          if ( v9 < v11 )
            v9 = v11;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v9, 4);
        }
        v3->m_size += 5;
        v12 = v3->m_data;
        v12[v8] = *(float *)(&v6[14].m_referenceCount + 1);
        v12[v8 + 1] = *((float *)&v6[15].m_userData + 1);
        v12[v8 + 2] = *(float *)&v6[15].m_userData;
        v12[v8 + 3] = *((float *)&v6[13].vfptr + 1);
        v12[v8 + 4] = *(float *)&v6[13].vfptr;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v2->m_size );
  }
}

// File Line: 207
// RVA: 0xE10DE0
void __fastcall hkpEaseConstraintsAction::_restoreLimits(hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *dst, hkArray<float,hkContainerHeapAllocator> *src)
{
  int v2; // ebx
  hkArray<float,hkContainerHeapAllocator> *v3; // r15
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v4; // rbp
  int v5; // esi
  __int64 v6; // r14
  hkpConstraintData *v7; // rdi
  int v8; // eax
  __int64 v9; // rcx
  int v10; // ebx
  int v11; // ebx
  __int64 v12; // rcx

  v2 = 0;
  v3 = src;
  v4 = dst;
  v5 = 0;
  if ( dst->m_size > 0 )
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = v4->m_data[v6]->m_data;
      v8 = ((__int64 (__fastcall *)(hkpConstraintData *))v7->vfptr[1].__first_virtual_table_function__)(v7);
      if ( v8 == 2 )
        break;
      if ( v8 == 7 )
      {
        v9 = v2;
        v10 = v2 + 1;
        *(float *)(&v7[14].m_referenceCount + 1) = v3->m_data[v9];
        *(float *)&v9 = v3->m_data[v10++];
        HIDWORD(v7[15].m_userData) = v9;
        *(float *)&v9 = v3->m_data[v10++];
        LODWORD(v7[15].m_userData) = v9;
        *(float *)&v9 = v3->m_data[v10];
        v11 = v10 + 1;
        HIDWORD(v7[13].vfptr) = v9;
        *(float *)&v7[13].vfptr = v3->m_data[v11];
LABEL_7:
        v2 = v11 + 1;
      }
      ++v5;
      ++v6;
      if ( v5 >= v4->m_size )
        return;
    }
    v12 = v2;
    v11 = v2 + 1;
    *(float *)&v7[10].m_userData = v3->m_data[v12];
    *(float *)(&v7[10].m_referenceCount + 1) = v3->m_data[v11];
    goto LABEL_7;
  }
}

// File Line: 252
// RVA: 0xE10EE0
void __fastcall hkpEaseConstraintsAction::_loosenConstraints(hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  hkResult result; // [rsp+30h] [rbp+8h]

  v1 = constraints;
  v2 = constraints->m_size - 1;
  for ( i = v2; i >= 0; --i )
    hkpConstraintDataUtils::loosenConstraintLimits(
      &result,
      v1->m_data[i]->m_data,
      &v1->m_data[i]->m_entities[0]->m_motion.m_motionState.m_transform,
      &v1->m_data[i]->m_entities[1]->m_motion.m_motionState.m_transform);
}

// File Line: 281
// RVA: 0xE10F50
signed __int64 __fastcall hkpEaseConstraintsAction::_partiallyRestoreConstraint(hkpConstraintInstance *runtimeConstraint, float *originalLimitsPtr, float restorationWeight)
{
  float *v3; // rbx
  float *v4; // rdi
  int v5; // eax
  signed __int64 result; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  hkErrStream v15; // [rsp+20h] [rbp-238h]
  char buf; // [rsp+40h] [rbp-218h]

  v3 = (float *)runtimeConstraint->m_data;
  v4 = originalLimitsPtr;
  v5 = (*(__int64 (__fastcall **)(hkpConstraintData *))(*(_QWORD *)v3 + 24i64))(runtimeConstraint->m_data);
  if ( v5 == 2 )
  {
    result = 2i64;
    v14 = v3[63];
    v3[64] = (float)((float)(*v4 - v3[64]) * restorationWeight) + v3[64];
    v3[63] = (float)((float)(v4[1] - v14) * restorationWeight) + v14;
  }
  else if ( v5 == 7 )
  {
    result = 5i64;
    v7 = v3[95];
    v3[87] = (float)((float)(*v4 - v3[87]) * restorationWeight) + v3[87];
    v8 = (float)((float)(v4[1] - v7) * restorationWeight) + v7;
    v9 = v3[94];
    v3[95] = v8;
    v10 = (float)((float)(v4[2] - v9) * restorationWeight) + v9;
    v11 = v3[79];
    v3[94] = v10;
    v12 = (float)((float)(v4[3] - v11) * restorationWeight) + v11;
    v13 = v3[78];
    v3[79] = v12;
    v3[78] = (float)((float)(v4[4] - v13) * restorationWeight) + v13;
  }
  else
  {
    hkErrStream::hkErrStream(&v15, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v15.vfptr, "hkpEaseConstraintsAction does not handle this type of constraint.");
    if ( (unsigned int)hkError::messageError(
                         778157838,
                         &buf,
                         "Actions\\EaseConstraints\\hkpEaseConstraintsAction.cpp",
                         334) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v15.vfptr);
    result = 0i64;
  }
  return result;
}

