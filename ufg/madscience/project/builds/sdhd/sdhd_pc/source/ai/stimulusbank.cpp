// File Line: 34
// RVA: 0x14AE6E0
__int64 dynamic_initializer_for__StimulusBank::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("StimulusBank", 0xFFFFFFFF);
  StimulusBank::sClassNameUID = result;
  return result;
}

// File Line: 50
// RVA: 0x332050
void __fastcall StimulusBank::StimulusBank(StimulusBank *this)
{
  StimulusBank *v1; // rbx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v2; // rax

  v1 = this;
  ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)&this->vfptr);
  v2 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeBank::`vftable';
  v1->m_Level = 0;
  v1->mSignalMask = -1i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&StimulusBank::`vftable';
  *(_QWORD *)&v1->m_NumChildren = 0i64;
  v1->m_pStimulusType = 0i64;
  v1->m_pNumRecords = 0i64;
  v1->m_pStimulusRecordBlock = 0i64;
  v1->m_ppFirstStimulusRecord = 0i64;
  v1->m_pNeedToCallMatchOnChild = 0i64;
  v1->m_pNeedToCallMatchOnChildInitialValues = 0i64;
  v1->m_MaxSecondsSincePerceivedForAnyStimulus = -999999.0;
}

// File Line: 61
// RVA: 0x33B2C0
void __fastcall StimulusBank::~StimulusBank(StimulusBank *this)
{
  StimulusBank *v1; // rbx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v2; // rdx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v3; // rcx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&StimulusBank::`vftable';
  StimulusBank::CleanUp(this);
  v2 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  ActionNodeImplementation::~ActionNodeImplementation((ActionNodeImplementation *)&v1->vfptr);
}

// File Line: 84
// RVA: 0x350DB0
StimulusBank *__fastcall StimulusBank::CreateClone(StimulusBank *this)
{
  StimulusBank *v1; // rdi
  char *v2; // rax
  StimulusBank *v3; // rax
  StimulusBank *v4; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB8ui64, "StimulusBank::CreateClone", 0i64, 1u);
  if ( v2 )
  {
    StimulusBank::StimulusBank((StimulusBank *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  StimulusBank::CleanUp(v4);
  ActionNodeBank::CopyFrom((ActionNodeBank *)&v4->vfptr, (ActionNodeBank *)&v1->vfptr);
  return v4;
}

// File Line: 146
// RVA: 0x34E770
void __fastcall StimulusBank::CleanUp(StimulusBank *this)
{
  StimulusBank *v1; // rbx

  v1 = this;
  operator delete[](this->m_pStimulusType);
  operator delete[](v1->m_pNumRecords);
  operator delete[](v1->m_pStimulusRecordBlock);
  operator delete[](v1->m_ppFirstStimulusRecord);
  operator delete[](v1->m_pNeedToCallMatchOnChild);
  operator delete[](v1->m_pNeedToCallMatchOnChildInitialValues);
  v1->m_MaxSecondsSincePerceivedForAnyStimulus = -999999.0;
  *(_QWORD *)&v1->m_NumChildren = 0i64;
  v1->m_pStimulusType = 0i64;
  v1->m_pNumRecords = 0i64;
  v1->m_pStimulusRecordBlock = 0i64;
  v1->m_ppFirstStimulusRecord = 0i64;
  v1->m_pNeedToCallMatchOnChild = 0i64;
  v1->m_pNeedToCallMatchOnChildInitialValues = 0i64;
}

// File Line: 158
// RVA: 0x350900
__int64 __fastcall StimulusBank::CountNumStimulusTypesInConditionGroup(StimulusBank *this, ConditionGroup *condition_group, int *num_entries)
{
  __int64 v3; // rax
  unsigned __int8 v4; // si
  char *v5; // rcx
  __int64 v6; // rdi
  int *v7; // rbp
  unsigned __int8 *v8; // rbx
  StimulusBank *v10; // [rsp+40h] [rbp+8h]
  ConditionGroup *v11; // [rsp+48h] [rbp+10h]
  char *v12; // [rsp+58h] [rbp+20h]

  v11 = condition_group;
  v10 = this;
  v3 = condition_group->mConditions.mData.mOffset;
  v4 = 0;
  v5 = (char *)&condition_group->mConditions.mData + v3;
  v6 = 0i64;
  v12 = (char *)&condition_group->mConditions.mData + v3;
  v7 = num_entries;
  if ( condition_group->mConditions.mCount & 0x7FFFFFFF )
  {
    do
    {
      v8 = (unsigned __int8 *)&v5[8 * v6 + *(_QWORD *)&v5[8 * v6]];
      if ( (*(unsigned int (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v8 + 40i64))(v8) == ReceivedStimulusCondition::sClassNameUID )
      {
        v4 = 1;
        ++v7[v8[48]];
      }
      else if ( (*(unsigned int (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v8 + 40i64))(v8) == ConditionGroup::sClassNameUID
             && StimulusBank::CountNumStimulusTypesInConditionGroup(v10, (ConditionGroup *)v8, v7) )
      {
        v4 = 1;
      }
      v6 = (unsigned int)(v6 + 1);
      v5 = v12;
    }
    while ( (unsigned int)v6 < (v11->mConditions.mCount & 0x7FFFFFFFu) );
  }
  return v4;
}

// File Line: 194
// RVA: 0x340C50
void __fastcall StimulusBank::AddRecordsForAllReceivedStimulusConditions(StimulusBank *this, ConditionGroup *condition_group, int child_index, int *record_index)
{
  StimulusBank *v4; // rdi
  __int64 v5; // rsi
  int *v6; // rbp
  char *v7; // rcx
  signed __int64 v8; // rbx
  int v9; // edx
  __int64 v10; // r9
  int v11; // ecx
  __int64 v12; // r8
  UFG::eStimulusType *v13; // rax
  __int64 v14; // rdx
  StimulusRecord *v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm0_4
  char *v18; // [rsp+20h] [rbp-28h]
  ConditionGroup *v19; // [rsp+58h] [rbp+10h]
  int child_indexa; // [rsp+60h] [rbp+18h]

  child_indexa = child_index;
  v19 = condition_group;
  v4 = this;
  v5 = 0i64;
  v6 = record_index;
  v7 = (char *)&condition_group->mConditions.mData + condition_group->mConditions.mData.mOffset;
  v18 = (char *)&condition_group->mConditions.mData + condition_group->mConditions.mData.mOffset;
  if ( condition_group->mConditions.mCount & 0x7FFFFFFF )
  {
    do
    {
      v8 = (signed __int64)&v7[8 * v5 + *(_QWORD *)&v7[8 * v5]];
      if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v8 + 40i64))(v8) == ReceivedStimulusCondition::sClassNameUID )
      {
        v9 = v4->m_NumStimulusTypes;
        v10 = *(unsigned __int8 *)(v8 + 48);
        v11 = 0;
        v12 = 0i64;
        if ( v9 > 0 )
        {
          v13 = v4->m_pStimulusType;
          while ( (_DWORD)v10 != *v13 )
          {
            ++v11;
            ++v12;
            ++v13;
            if ( v11 >= v9 )
              goto LABEL_14;
          }
          if ( v12 >= 0 )
          {
            v14 = v6[v10];
            v15 = v4->m_ppFirstStimulusRecord[v12];
            v15[v14].m_ChildIndex = child_indexa;
            v16 = *(float *)(v8 + 60);
            v15[v14].m_MaxSecondsSincePerceived = v16;
            v17 = v4->m_MaxSecondsSincePerceivedForAnyStimulus;
            if ( v17 <= v16 )
              v17 = v16;
            v4->m_MaxSecondsSincePerceivedForAnyStimulus = v17;
            ++v6[v10];
          }
        }
      }
      else if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v8 + 40i64))(v8) == ConditionGroup::sClassNameUID )
      {
        StimulusBank::AddRecordsForAllReceivedStimulusConditions(v4, (ConditionGroup *)v8, child_indexa, v6);
      }
LABEL_14:
      v7 = v18;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < (v19->mConditions.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 246
// RVA: 0x383930
void __fastcall StimulusBank::ResolveReferences(StimulusBank *this)
{
  StimulusBank *v1; // rbx
  __int64 v2; // r15
  int v3; // ecx
  UFG::allocator::free_link *v4; // rax
  unsigned __int64 v5; // rcx
  UFG::allocator::free_link *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // esi
  unsigned int v9; // edi
  __int64 v10; // r14
  signed __int64 v11; // r12
  ConditionGroup *v12; // rax
  int v13; // er8
  int v14; // ebp
  char *v15; // rax
  signed __int64 v16; // rdx
  unsigned __int64 v17; // rdi
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  StimulusRecord *v23; // r11
  signed int v24; // er9
  __int64 v25; // rdi
  __int64 v26; // r10
  char *v27; // rdx
  __int64 v28; // rdi
  signed __int64 v29; // r14
  ConditionGroup *v30; // rax
  char dest; // [rsp+20h] [rbp-3B8h]
  int record_index; // [rsp+1F0h] [rbp-1E8h]

  v1 = this;
  StimulusBank::CleanUp(this);
  UFG::qMemSet(&dest, 0, 0x1D0u);
  v2 = ((__int64 (__fastcall *)(StimulusBank *))v1->vfptr[1].GetResourcePath)(v1);
  v3 = *(_DWORD *)v2 & 0x7FFFFFFF;
  v1->m_NumChildren = v3;
  v4 = UFG::qMalloc(v3, "StimulusBank", 0i64);
  v5 = v1->m_NumChildren;
  v1->m_pNeedToCallMatchOnChild = (char *)v4;
  v6 = UFG::qMalloc(v5, "StimulusBank", 0i64);
  v7 = v1->m_NumChildren;
  v1->m_pNeedToCallMatchOnChildInitialValues = (char *)v6;
  UFG::qMemSet(v6, 0, v7);
  v8 = 0;
  v9 = 0;
  v10 = 0i64;
  v11 = v2 + *(_QWORD *)(v2 + 8) + 8i64;
  if ( *(_DWORD *)v2 & 0x7FFFFFFF )
  {
    do
    {
      v12 = (ConditionGroup *)(*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v11 + 8i64 * v9) + v11 + 8i64 * v9) + 272i64))();
      if ( !v12 || !(unsigned __int8)StimulusBank::CountNumStimulusTypesInConditionGroup(v1, v12, (int *)&dest) )
        v1->m_pNeedToCallMatchOnChildInitialValues[v10] = 1;
      ++v9;
      ++v10;
    }
    while ( v9 < (*(_DWORD *)v2 & 0x7FFFFFFFu) );
  }
  v13 = 0;
  v14 = 0;
  v15 = &dest;
  v16 = 116i64;
  do
  {
    if ( *(_DWORD *)v15 > 0 )
    {
      v14 += *(_DWORD *)v15;
      ++v13;
    }
    v15 += 4;
    --v16;
  }
  while ( v16 );
  v17 = v13;
  v1->m_NumStimulusTypes = v13;
  v18 = 4i64 * v13;
  if ( !is_mul_ok(v13, 4ui64) )
    v18 = -1i64;
  v1->m_pStimulusType = (UFG::eStimulusType *)UFG::qMalloc(v18, "StimulusBank", 0i64);
  v19 = 4 * v17;
  if ( !is_mul_ok(v17, 4ui64) )
    v19 = -1i64;
  v1->m_pNumRecords = (int *)UFG::qMalloc(v19, "StimulusBank", 0i64);
  v20 = 8i64 * v14;
  if ( !is_mul_ok(v14, 8ui64) )
    v20 = -1i64;
  v1->m_pStimulusRecordBlock = (StimulusRecord *)UFG::qMalloc(v20, "StimulusBank", 0i64);
  v21 = 8 * v17;
  if ( !is_mul_ok(v17, 8ui64) )
    v21 = -1i64;
  v22 = UFG::qMalloc(v21, "StimulusBank", 0i64);
  v23 = v1->m_pStimulusRecordBlock;
  v24 = 0;
  v25 = 0i64;
  v26 = 0i64;
  v27 = &dest;
  v1->m_ppFirstStimulusRecord = (StimulusRecord **)v22;
  do
  {
    if ( *(_DWORD *)v27 > 0 )
    {
      ++v26;
      ++v25;
      v1->m_pStimulusType[v26 - 1] = v24;
      v1->m_pNumRecords[v26 - 1] = *(_DWORD *)v27;
      v1->m_ppFirstStimulusRecord[v25 - 1] = v23;
      v23 += *(signed int *)v27;
    }
    ++v24;
    v27 += 4;
  }
  while ( v24 < 116 );
  UFG::qMemSet(&record_index, 0, 0x1D0u);
  v28 = ((__int64 (__fastcall *)(StimulusBank *))v1->vfptr[1].GetResourcePath)(v1);
  v29 = v28 + *(_QWORD *)(v28 + 8) + 8i64;
  if ( *(_DWORD *)v28 & 0x7FFFFFFF )
  {
    do
    {
      v30 = (ConditionGroup *)(*(__int64 (**)(void))(*(_QWORD *)(v29 + 8i64 * v8 + *(_QWORD *)(v29 + 8i64 * v8)) + 272i64))();
      if ( v30 )
        StimulusBank::AddRecordsForAllReceivedStimulusConditions(v1, v30, v8, &record_index);
      ++v8;
    }
    while ( v8 < (*(_DWORD *)v28 & 0x7FFFFFFFu) );
  }
  ActionNodeBank::ResolveReferences((ActionNodeBank *)&v1->vfptr);
}

// File Line: 379
// RVA: 0x372780
ActionNodePlayable *__fastcall StimulusBank::Match(StimulusBank *this, ActionContext *context)
{
  StimulusBank *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rdi
  UFG::SimComponent *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  float v10; // xmm2_4
  __int64 v11; // r13
  int v12; // er10
  __int64 v13; // r11
  __int64 v14; // rax
  float *v15; // rax
  float v16; // xmm1_4
  float *v17; // rdx
  __int64 v18; // rbp
  ActionNode *v19; // r15
  StimulusBank *v20; // rcx
  ActionNode *v21; // rdx
  __int64 v22; // rax
  signed __int64 v23; // rcx
  unsigned int v24; // esi
  __int64 v25; // rdi
  __int64 v26; // r14
  signed __int64 v27; // r12
  signed __int64 v28; // rcx
  ActionContext *v30; // [rsp+58h] [rbp+10h]

  v30 = context;
  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0i64;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[11].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StimulusReceiverComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StimulusReceiverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::StimulusReceiverComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[11].m_pComponent;
  }
  if ( !v6 )
    return 0i64;
  UFG::qMemCopy(v2->m_pNeedToCallMatchOnChild, v2->m_pNeedToCallMatchOnChildInitialValues, v2->m_NumChildren);
  v10 = UFG::Metrics::msInstance.mSimTime_Temp;
  v11 = 0i64;
  if ( UFG::Metrics::msInstance.mSimTime_Temp <= (float)(*(float *)(&v6[16].m_SimObjIndex + 1)
                                                       + v2->m_MaxSecondsSincePerceivedForAnyStimulus) )
  {
    v12 = 0;
    if ( v2->m_NumStimulusTypes > 0 )
    {
      v9 = 0i64;
      v13 = 0i64;
      do
      {
        v14 = *((_QWORD *)&v6[1].m_BoundComponentHandles.mNode.mPrev + (signed int)v2->m_pStimulusType[v9]);
        if ( v14 && (v15 = (float *)(v14 + 32)) != 0i64 )
          v16 = *v15;
        else
          v16 = FLOAT_N99999_0;
        v8 = 0i64;
        v17 = (float *)v2->m_ppFirstStimulusRecord[v13];
        if ( v2->m_pNumRecords[v9] > 0 )
        {
          do
          {
            if ( v10 <= (float)(v16 + v17[1]) )
              v2->m_pNeedToCallMatchOnChild[*(signed int *)v17] = 1;
            v8 = (unsigned int)(v8 + 1);
            v17 += 2;
          }
          while ( (signed int)v8 < v2->m_pNumRecords[v9] );
        }
        ++v12;
        ++v13;
        ++v9;
      }
      while ( v12 < v2->m_NumStimulusTypes );
    }
  }
  LODWORD(v18) = -1;
  v19 = 0i64;
  v20 = (StimulusBank *)v4->mActionController->m_currentNode;
  if ( v20 )
  {
    v21 = 0i64;
    while ( v20 != v2 )
    {
      v22 = v20->mParent.mOffset;
      v21 = (ActionNode *)&v20->vfptr;
      v23 = (signed __int64)&v20->mParent;
      if ( v22 )
      {
        v20 = (StimulusBank *)(v22 + v23);
        if ( v20 )
          continue;
      }
      goto LABEL_33;
    }
    if ( v21 )
    {
      v19 = v21;
      LODWORD(v18) = BinPtrArray<ActionNode,0,0>::Find(&v2->mChildren, v21);
    }
  }
LABEL_33:
  v24 = 0;
  v25 = 0i64;
  v26 = ((__int64 (__fastcall *)(StimulusBank *, Expression::IMemberMapVtbl *, __int64, __int64))v2->vfptr[1].GetResourcePath)(
          v2,
          v2->vfptr,
          v8,
          v9 * 4);
  v18 = (signed int)v18;
  v27 = v26 + *(_QWORD *)(v26 + 8) + 8i64;
  if ( *(_DWORD *)v26 & 0x7FFFFFFF )
  {
    do
    {
      v28 = v27 + 8i64 * v24 + *(_QWORD *)(v27 + 8i64 * v24);
      if ( (v18 == -1 || v25 < v18) && v2->m_pNeedToCallMatchOnChild[v25] || (ActionNode *)v28 == v19 )
      {
        v11 = (*(__int64 (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v28 + 200i64))(v28, v30);
        if ( v11 )
          break;
      }
      ++v24;
      ++v25;
    }
    while ( v24 < (*(_DWORD *)v26 & 0x7FFFFFFFu) );
  }
  return (ActionNodePlayable *)v11;
}

