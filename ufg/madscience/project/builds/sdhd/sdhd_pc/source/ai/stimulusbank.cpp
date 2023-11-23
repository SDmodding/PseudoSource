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
  ActionNodeImplementation::ActionNodeImplementation(this);
  this->mPrev = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  this->mNext = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeBank::`vftable;
  this->m_Level = 0;
  this->mSignalMask = -1i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&StimulusBank::`vftable;
  *(_QWORD *)&this->m_NumChildren = 0i64;
  this->m_pStimulusType = 0i64;
  this->m_pNumRecords = 0i64;
  this->m_pStimulusRecordBlock = 0i64;
  this->m_ppFirstStimulusRecord = 0i64;
  this->m_pNeedToCallMatchOnChild = 0i64;
  this->m_pNeedToCallMatchOnChildInitialValues = 0i64;
  this->m_MaxSecondsSincePerceivedForAnyStimulus = -999999.0;
}

// File Line: 61
// RVA: 0x33B2C0
void __fastcall StimulusBank::~StimulusBank(StimulusBank *this)
{
  UFG::qNode<ActionNodeBank,ActionNodeBank> *mPrev; // rcx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&StimulusBank::`vftable;
  StimulusBank::CleanUp(this);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  this->mNext = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  ActionNodeImplementation::~ActionNodeImplementation(this);
}

// File Line: 84
// RVA: 0x350DB0
StimulusBank *__fastcall StimulusBank::CreateClone(StimulusBank *this)
{
  char *v2; // rax
  StimulusBank *v3; // rax
  StimulusBank *v4; // rbx

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
  ActionNodeBank::CopyFrom(v4, this);
  return v4;
}

// File Line: 146
// RVA: 0x34E770
void __fastcall StimulusBank::CleanUp(StimulusBank *this)
{
  operator delete[](this->m_pStimulusType);
  operator delete[](this->m_pNumRecords);
  operator delete[](this->m_pStimulusRecordBlock);
  operator delete[](this->m_ppFirstStimulusRecord);
  operator delete[](this->m_pNeedToCallMatchOnChild);
  operator delete[](this->m_pNeedToCallMatchOnChildInitialValues);
  this->m_MaxSecondsSincePerceivedForAnyStimulus = -999999.0;
  *(_QWORD *)&this->m_NumChildren = 0i64;
  this->m_pStimulusType = 0i64;
  this->m_pNumRecords = 0i64;
  this->m_pStimulusRecordBlock = 0i64;
  this->m_ppFirstStimulusRecord = 0i64;
  this->m_pNeedToCallMatchOnChild = 0i64;
  this->m_pNeedToCallMatchOnChildInitialValues = 0i64;
}

// File Line: 158
// RVA: 0x350900
__int64 __fastcall StimulusBank::CountNumStimulusTypesInConditionGroup(
        StimulusBank *this,
        ConditionGroup *condition_group,
        int *num_entries)
{
  unsigned __int8 v3; // si
  char *v4; // rcx
  __int64 v5; // rdi
  unsigned __int8 *v7; // rbx
  char *v11; // [rsp+58h] [rbp+20h]

  v3 = 0;
  v4 = (char *)&condition_group->mConditions.mData + condition_group->mConditions.mData.mOffset;
  v5 = 0i64;
  v11 = v4;
  if ( (condition_group->mConditions.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v7 = (unsigned __int8 *)&v4[8 * v5 + *(_QWORD *)&v4[8 * v5]];
      if ( (*(unsigned int (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v7 + 40i64))(v7) == ReceivedStimulusCondition::sClassNameUID )
      {
        v3 = 1;
        ++num_entries[v7[48]];
      }
      else if ( (*(unsigned int (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v7 + 40i64))(v7) == ConditionGroup::sClassNameUID
             && StimulusBank::CountNumStimulusTypesInConditionGroup(this, (ConditionGroup *)v7, num_entries) )
      {
        v3 = 1;
      }
      v5 = (unsigned int)(v5 + 1);
      v4 = v11;
    }
    while ( (unsigned int)v5 < (condition_group->mConditions.mCount & 0x7FFFFFFFu) );
  }
  return v3;
}

// File Line: 194
// RVA: 0x340C50
void __fastcall StimulusBank::AddRecordsForAllReceivedStimulusConditions(
        StimulusBank *this,
        ConditionGroup *condition_group,
        int child_index,
        int *record_index)
{
  __int64 v5; // rsi
  char *v7; // rcx
  __int64 v8; // rbx
  int m_NumStimulusTypes; // edx
  __int64 v10; // r9
  int v11; // ecx
  __int64 v12; // r8
  UFG::eStimulusType *m_pStimulusType; // rax
  __int64 v14; // rdx
  StimulusRecord *v15; // rcx
  float v16; // xmm1_4
  float m_MaxSecondsSincePerceivedForAnyStimulus; // xmm0_4
  char *v18; // [rsp+20h] [rbp-28h]

  v5 = 0i64;
  v7 = (char *)&condition_group->mConditions.mData + condition_group->mConditions.mData.mOffset;
  v18 = v7;
  if ( (condition_group->mConditions.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v8 = (__int64)&v7[8 * v5 + *(_QWORD *)&v7[8 * v5]];
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8) == ReceivedStimulusCondition::sClassNameUID )
      {
        m_NumStimulusTypes = this->m_NumStimulusTypes;
        v10 = *(unsigned __int8 *)(v8 + 48);
        v11 = 0;
        v12 = 0i64;
        if ( m_NumStimulusTypes > 0 )
        {
          m_pStimulusType = this->m_pStimulusType;
          while ( (_DWORD)v10 != *m_pStimulusType )
          {
            ++v11;
            ++v12;
            ++m_pStimulusType;
            if ( v11 >= m_NumStimulusTypes )
              goto LABEL_14;
          }
          if ( v12 >= 0 )
          {
            v14 = record_index[v10];
            v15 = this->m_ppFirstStimulusRecord[v12];
            v15[v14].m_ChildIndex = child_index;
            v16 = *(float *)(v8 + 60);
            v15[v14].m_MaxSecondsSincePerceived = v16;
            m_MaxSecondsSincePerceivedForAnyStimulus = this->m_MaxSecondsSincePerceivedForAnyStimulus;
            if ( m_MaxSecondsSincePerceivedForAnyStimulus <= v16 )
              m_MaxSecondsSincePerceivedForAnyStimulus = v16;
            this->m_MaxSecondsSincePerceivedForAnyStimulus = m_MaxSecondsSincePerceivedForAnyStimulus;
            ++record_index[v10];
          }
        }
      }
      else if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8) == ConditionGroup::sClassNameUID )
      {
        StimulusBank::AddRecordsForAllReceivedStimulusConditions(this, (ConditionGroup *)v8, child_index, record_index);
      }
LABEL_14:
      v7 = v18;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < (condition_group->mConditions.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 246
// RVA: 0x383930
void __fastcall StimulusBank::ResolveReferences(StimulusBank *this)
{
  __int64 v2; // r15
  int v3; // ecx
  char *v4; // rax
  unsigned __int64 m_NumChildren; // rcx
  char *v6; // rax
  int v7; // r8d
  unsigned int v8; // esi
  unsigned int v9; // edi
  __int64 v10; // r14
  __int64 v11; // r12
  __int64 v12; // rcx
  ConditionGroup *v13; // rax
  int v14; // r8d
  int v15; // ebp
  int *v16; // rax
  __int64 v17; // rdx
  unsigned __int64 v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rax
  StimulusRecord **v23; // rax
  StimulusRecord *m_pStimulusRecordBlock; // r11
  int v25; // r9d
  __int64 v26; // rdi
  __int64 v27; // r10
  int *v28; // rdx
  __int64 v29; // rdi
  __int64 v30; // r14
  __int64 v31; // rcx
  ConditionGroup *v32; // rax
  int dest[116]; // [rsp+20h] [rbp-3B8h] BYREF
  int record_index[116]; // [rsp+1F0h] [rbp-1E8h] BYREF

  StimulusBank::CleanUp(this);
  UFG::qMemSet(dest, 0, 0x1D0u);
  v2 = ((__int64 (__fastcall *)(StimulusBank *))this->vfptr[1].GetResourcePath)(this);
  v3 = *(_DWORD *)v2 & 0x7FFFFFFF;
  this->m_NumChildren = v3;
  v4 = (char *)UFG::qMalloc(v3, "StimulusBank", 0i64);
  m_NumChildren = this->m_NumChildren;
  this->m_pNeedToCallMatchOnChild = v4;
  v6 = (char *)UFG::qMalloc(m_NumChildren, "StimulusBank", 0i64);
  v7 = this->m_NumChildren;
  this->m_pNeedToCallMatchOnChildInitialValues = v6;
  UFG::qMemSet(v6, 0, v7);
  v8 = 0;
  v9 = 0;
  v10 = 0i64;
  v11 = v2 + *(_QWORD *)(v2 + 8) + 8i64;
  if ( (*(_DWORD *)v2 & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v12 = *(_QWORD *)(v11 + 8i64 * v9) + v11 + 8i64 * v9;
      v13 = (ConditionGroup *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 272i64))(v12);
      if ( !v13 || !(unsigned __int8)StimulusBank::CountNumStimulusTypesInConditionGroup(this, v13, dest) )
        this->m_pNeedToCallMatchOnChildInitialValues[v10] = 1;
      ++v9;
      ++v10;
    }
    while ( v9 < (*(_DWORD *)v2 & 0x7FFFFFFFu) );
  }
  v14 = 0;
  v15 = 0;
  v16 = dest;
  v17 = 116i64;
  do
  {
    if ( *v16 > 0 )
    {
      v15 += *v16;
      ++v14;
    }
    ++v16;
    --v17;
  }
  while ( v17 );
  v18 = v14;
  this->m_NumStimulusTypes = v14;
  v19 = 4i64 * v14;
  if ( !is_mul_ok(v14, 4ui64) )
    v19 = -1i64;
  this->m_pStimulusType = (UFG::eStimulusType *)UFG::qMalloc(v19, "StimulusBank", 0i64);
  v20 = 4 * v18;
  if ( !is_mul_ok(v18, 4ui64) )
    v20 = -1i64;
  this->m_pNumRecords = (int *)UFG::qMalloc(v20, "StimulusBank", 0i64);
  v21 = 8i64 * v15;
  if ( !is_mul_ok(v15, 8ui64) )
    v21 = -1i64;
  this->m_pStimulusRecordBlock = (StimulusRecord *)UFG::qMalloc(v21, "StimulusBank", 0i64);
  v22 = 8 * v18;
  if ( !is_mul_ok(v18, 8ui64) )
    v22 = -1i64;
  v23 = (StimulusRecord **)UFG::qMalloc(v22, "StimulusBank", 0i64);
  m_pStimulusRecordBlock = this->m_pStimulusRecordBlock;
  v25 = 0;
  v26 = 0i64;
  v27 = 0i64;
  v28 = dest;
  this->m_ppFirstStimulusRecord = v23;
  do
  {
    if ( *v28 > 0 )
    {
      ++v27;
      ++v26;
      this->m_pStimulusType[v27 - 1] = v25;
      this->m_pNumRecords[v27 - 1] = *v28;
      this->m_ppFirstStimulusRecord[v26 - 1] = m_pStimulusRecordBlock;
      m_pStimulusRecordBlock += *v28;
    }
    ++v25;
    ++v28;
  }
  while ( v25 < 116 );
  UFG::qMemSet(record_index, 0, 0x1D0u);
  v29 = ((__int64 (__fastcall *)(StimulusBank *))this->vfptr[1].GetResourcePath)(this);
  v30 = v29 + *(_QWORD *)(v29 + 8) + 8i64;
  if ( (*(_DWORD *)v29 & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v31 = v30 + 8i64 * v8 + *(_QWORD *)(v30 + 8i64 * v8);
      v32 = (ConditionGroup *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v31 + 272i64))(v31);
      if ( v32 )
        StimulusBank::AddRecordsForAllReceivedStimulusConditions(this, v32, v8, record_index);
      ++v8;
    }
    while ( v8 < (*(_DWORD *)v29 & 0x7FFFFFFFu) );
  }
  ActionNodeBank::ResolveReferences(this);
}

// File Line: 379
// RVA: 0x372780
ActionNodePlayable *__fastcall StimulusBank::Match(StimulusBank *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  float mSimTime_Temp; // xmm2_4
  __int64 v11; // r13
  int v12; // r10d
  __int64 v13; // r11
  __int64 v14; // rax
  float *v15; // rax
  float v16; // xmm1_4
  StimulusRecord *i; // rdx
  int v18; // ebp
  ActionNode *v19; // r15
  StimulusBank *m_currentNode; // rcx
  ActionNode *v21; // rdx
  __int64 mOffset; // rax
  UFG::qOffset64<ActionNode *> *p_mParent; // rcx
  unsigned int v24; // esi
  __int64 v25; // rdi
  __int64 v26; // r14
  __int64 v27; // r12
  __int64 v28; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0i64;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::StimulusReceiverComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StimulusReceiverComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
  }
  if ( !m_pComponent )
    return 0i64;
  UFG::qMemCopy(this->m_pNeedToCallMatchOnChild, this->m_pNeedToCallMatchOnChildInitialValues, this->m_NumChildren);
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v11 = 0i64;
  if ( UFG::Metrics::msInstance.mSimTime_Temp <= (float)(*(float *)(&m_pComponent[16].m_SimObjIndex + 1)
                                                       + this->m_MaxSecondsSincePerceivedForAnyStimulus) )
  {
    v12 = 0;
    if ( this->m_NumStimulusTypes > 0 )
    {
      v9 = 0i64;
      v13 = 0i64;
      do
      {
        v14 = *((_QWORD *)&m_pComponent[1].m_BoundComponentHandles.mNode.mPrev + (int)this->m_pStimulusType[v9]);
        if ( v14 && (v15 = (float *)(v14 + 32)) != 0i64 )
          v16 = *v15;
        else
          v16 = FLOAT_N99999_0;
        v8 = 0i64;
        for ( i = this->m_ppFirstStimulusRecord[v13]; (int)v8 < this->m_pNumRecords[v9]; ++i )
        {
          if ( mSimTime_Temp <= (float)(v16 + i->m_MaxSecondsSincePerceived) )
            this->m_pNeedToCallMatchOnChild[i->m_ChildIndex] = 1;
          v8 = (unsigned int)(v8 + 1);
        }
        ++v12;
        ++v13;
        ++v9;
      }
      while ( v12 < this->m_NumStimulusTypes );
    }
  }
  v18 = -1;
  v19 = 0i64;
  m_currentNode = (StimulusBank *)context->mActionController->m_currentNode;
  if ( m_currentNode )
  {
    v21 = 0i64;
    while ( m_currentNode != this )
    {
      mOffset = m_currentNode->mParent.mOffset;
      v21 = m_currentNode;
      p_mParent = &m_currentNode->mParent;
      if ( mOffset )
      {
        m_currentNode = (StimulusBank *)((char *)p_mParent + mOffset);
        if ( m_currentNode )
          continue;
      }
      goto LABEL_32;
    }
    if ( v21 )
    {
      v19 = v21;
      v18 = BinPtrArray<ActionNode,0,0>::Find(&this->mChildren, v21);
    }
  }
LABEL_32:
  v24 = 0;
  v25 = 0i64;
  v26 = ((__int64 (__fastcall *)(StimulusBank *, Expression::IMemberMapVtbl *, __int64, __int64))this->vfptr[1].GetResourcePath)(
          this,
          this->vfptr,
          v8,
          v9 * 4);
  v27 = v26 + *(_QWORD *)(v26 + 8) + 8i64;
  if ( (*(_DWORD *)v26 & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v28 = v27 + 8i64 * v24 + *(_QWORD *)(v27 + 8i64 * v24);
      if ( (v18 == -1i64 || v25 < v18) && this->m_pNeedToCallMatchOnChild[v25] || (ActionNode *)v28 == v19 )
      {
        v11 = (*(__int64 (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v28 + 200i64))(v28, context);
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
      ++v24;
      ++v25;
    }
    while ( v24 < (

