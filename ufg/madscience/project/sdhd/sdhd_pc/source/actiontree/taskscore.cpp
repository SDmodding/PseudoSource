// File Line: 41
// RVA: 0x26BB60
void __fastcall PrintTask::Begin(PrintTask *this, ActionContext *context)
{
  ITrack *v2; // rax

  v2 = this->m_Track;
  this->mContext = context;
  JUMPOUT(BYTE4(v2[1].mResourceOwner), 0, PrintTask::DoPrinting);
}

// File Line: 50
// RVA: 0x273740
char __fastcall PrintTask::Update(PrintTask *this, float timeDelta)
{
  if ( !BYTE4(this->m_Track[1].mResourceOwner) )
    PrintTask::DoPrinting(this);
  return 1;
}

// File Line: 59
// RVA: 0x26D940
void __fastcall PrintTask::DoPrinting(PrintTask *this)
{
  ITrack *v1; // r8
  int v2; // edx
  int v3; // edx
  ActionContext *v4; // rax
  UFG::TransformNodeComponent *v5; // rcx
  unsigned __int64 v6; // rax
  const char *v7; // rcx

  v1 = this->m_Track;
  v2 = (int)v1[1].mResourceOwner;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v4 = this->mContext;
        if ( v4 )
        {
          v5 = (UFG::TransformNodeComponent *)v4->mSimObject.m_pPointer;
          if ( v5 )
            v5 = (UFG::TransformNodeComponent *)v5->mChildren.mNode.mNext;
          if ( v5 )
          {
            v6 = (_QWORD)v1[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
            UFG::DrawDebugText(v5, &UFG::qColour::White, "%s", v6);
          }
        }
      }
    }
    else
    {
      if ( (_QWORD)v1[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
        v7 = (char *)&v1[1] + ((_QWORD)v1[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
      else
        v7 = BinString::sEmptyString;
      UFG::DrawDebugText(0, 0, &UFG::qColour::White, "%s", v7);
    }
  }
  else if ( (_QWORD)v1[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
  {
    UFG::qPrintf("%s\n", (char *)&v1[1] + ((_QWORD)v1[1].vfptr & 0xFFFFFFFFFFFFFFFEui64));
  }
  else
  {
    UFG::qPrintf("%s\n", BinString::sEmptyString);
  }
}

// File Line: 137
// RVA: 0x26BA20
void __fastcall OpportunityTask::Begin(OpportunityTask *this, ActionContext *context)
{
  OpportunityTask *v2; // rbx
  ITrack *v3; // rcx
  Expression::IMemberMapVtbl *v4; // rax
  ActionContext *v5; // rsi
  signed __int64 v6; // rdx
  signed __int64 v7; // rax
  __int64 v8; // r8
  UFG::SimObject *v9; // rcx
  ActionNode *v10; // rdi
  __int64 v11; // rbp
  ActionNodeRoot *v12; // rax
  __int64 v13; // r8
  ActionNodeRoot *v14; // rdi
  UFG::ActionTreeComponentBase *v15; // rcx
  ActionNodeRoot *v16; // rax

  this->mContext = context;
  v2 = this;
  v3 = this->m_Track;
  v4 = v3[1].vfptr;
  v5 = context;
  v6 = 0i64;
  if ( v4 )
    v7 = (signed __int64)&v4->ResolveReferences + (_QWORD)v3;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)(v7 + 72);
  if ( v8 )
    v6 = v8 + v7 + 72;
  v2->mTrackNodeBranch = (ActionNode *)v6;
  v2->mTrackTruthDuration = *(float *)&v3[1].mMasterRate.text.mOffset;
  v2->mTrackTimeLatch = *(float *)&v3[1].mBreakPoint;
  v2->mTrackEvaluationFrequency = SHIWORD(v3[1].m_TrackClassNameUID);
  v2->mTrackConditionGroup = (ConditionGroup *)((__int64 (*)(void))v3->vfptr[2].__vecDelDtor)();
  v9 = v2->mContext->mSimObject.m_pPointer;
  if ( v9 )
    v2->mNameUID = v9->mNode.mUID;
  v10 = v2->mTrackNodeBranch;
  if ( v10
    || !(OpportunityTrack::GetActionPath((OpportunityTrack *)v2->m_Track)->mPath.mCount & 0x7FFFFFFF)
    && (v10 = v2->mContext->m_OpeningBranch) != 0i64 )
  {
    v11 = ((__int64 (*)(void))v5->m_OpeningBranch->vfptr[1].GetResourceOwner)();
    v12 = (ActionNodeRoot *)v10->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v10->vfptr);
    v13 = v12->mActionTreeType.mValue;
    v14 = v12;
    if ( (v5->mActionTreeComponentBase[v13] || v5->mActionTreeComponentBase[1]) && (ActionNodeRoot *)v11 != v12 )
    {
      v15 = v5->mActionTreeComponentBase[v13];
      if ( !v15 )
        v15 = v5->mActionTreeComponentBase[1];
      if ( UFG::ActionTreeComponentBase::AllocateFor(v15, v12) )
      {
        v16 = (ActionNodeRoot *)v14->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v14->vfptr);
        ActionNodeRoot::Init(v16, v2->mContext);
      }
    }
  }
}

// File Line: 196
// RVA: 0x2735C0
char __fastcall OpportunityTask::Update(OpportunityTask *this, float timeDelta)
{
  OpportunityTask *v2; // rbx
  unsigned int v3; // ecx
  ActionNode *v5; // rdi
  float v6; // xmm6_4
  ConditionGroup *v7; // rcx
  __int64 v8; // rax
  float v9; // xmm8_4
  float v10; // xmm0_4
  bool v11; // cl
  bool v12; // al

  v2 = this;
  if ( !this->mLatchedNode )
  {
    v3 = this->mTrackEvaluationFrequency;
    if ( v3 > 1 )
    {
      if ( (UFG::Metrics::msInstance.mSimFrameCount + v2->mNameUID) % v3 )
        return 1;
    }
  }
  v5 = v2->mTrackNodeBranch;
  if ( !v5 )
  {
    if ( OpportunityTrack::GetActionPath((OpportunityTrack *)v2->m_Track)->mPath.mCount & 0x7FFFFFFF )
      return 0;
    v5 = v2->mContext->m_OpeningBranch;
    if ( !v5 )
      return 0;
  }
  v6 = v2->mTrackTruthDuration;
  if ( !v2->mLatchedNode || v6 > 0.0 )
  {
    v7 = v2->mTrackConditionGroup;
    v2->mLatchedNode = 0i64;
    if ( !v7
      || (unsigned __int8)v7->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v7->vfptr, (const char *)v2->mContext) )
    {
      v8 = ((__int64 (__fastcall *)(ActionNode *, ActionContext *))v5->vfptr[2].GetClassNameUID)(v5, v2->mContext);
      if ( v8 )
      {
        if ( BYTE1(v2->m_Track[1].m_TrackClassNameUID) )
        {
          v2->mLatchedNode = (ActionNodePlayable *)v8;
        }
        else if ( v2->mContext->mActionController->m_currentNode != (ActionNodePlayable *)v8 )
        {
          v2->mLatchedNode = (ActionNodePlayable *)v8;
        }
      }
    }
  }
  if ( v2->mLatchedNode )
  {
    v9 = timeDelta + v2->mTruthDuration;
    v10 = v2->mTrackTimeLatch;
    v2->mTruthDuration = v9;
    v11 = v10 >= 0.0 && v10 <= v2->mContext->mActionController->m_ActionNodePlayTime;
    v12 = v6 <= 0.0 || v9 >= v6;
    if ( v11 && v12 )
      return 0;
    if ( v6 > 0.0 )
      v2->mLatchedNode = 0i64;
  }
  else
  {
    v2->mTruthDuration = 0.0;
  }
  return 1;
}

// File Line: 321
// RVA: 0x26DA30
void __fastcall OpportunityTask::End(OpportunityTask *this)
{
  ActionNodePlayable *v1; // rdx
  ActionContext *v2; // r8
  int v3; // ecx
  ActionController *v4; // rax

  v1 = this->mLatchedNode;
  if ( v1 )
  {
    v2 = this->mContext;
    if ( v2 )
    {
      v3 = SLOBYTE(this->m_Track[1].m_TrackClassNameUID);
      v4 = v2->mActionController;
      if ( v3 > v4->m_SequencePriority )
      {
        v4->m_SequencePriority = v3;
        v4->m_SequenceNode = v1;
      }
      v4->mOverRideNode = 1;
    }
  }
}

// File Line: 345
// RVA: 0x26DA70
void __fastcall SequenceTask::End(SequenceTask *this)
{
  ActionContext *v1; // rbx
  ITrack *v2; // rax
  Expression::IMemberMapVtbl *v3; // rcx
  signed __int64 v4; // rax
  Expression::IMemberMap *(__fastcall *v5)(Expression::IMemberMap *); // rax
  signed __int64 v6; // rdi
  ActionController *v7; // rbx
  ActionContext *v8; // rcx
  __int64 v9; // rax

  v1 = this->mContext;
  if ( v1 )
  {
    v2 = this->m_Track;
    v3 = v2[1].vfptr;
    v4 = (signed __int64)&v2[1];
    if ( v3 )
      v3 = (Expression::IMemberMapVtbl *)((char *)v3 + v4);
    v5 = v3->GetResourceOwner;
    if ( v5 )
      v6 = (signed __int64)&v3->GetResourceOwner + (_QWORD)v5;
    else
      v6 = 0i64;
    v7 = v1->mActionController;
    if ( v6 && v7->m_SequencePriority < 0 )
    {
      v8 = v7->m_Context;
      if ( v8 )
        ActionContext::UpdateSignalsAndConditions(v8);
      v9 = (*(__int64 (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v6 + 200i64))(v6, v7->m_Context);
      if ( v9 )
      {
        if ( v7->m_SequencePriority < 0 )
        {
          v7->m_SequencePriority = 0;
          v7->m_SequenceNode = (ActionNodePlayable *)v9;
        }
      }
    }
  }
}

// File Line: 375
// RVA: 0x269FB0
void __fastcall SpawnTask::~SpawnTask(SpawnTask *this)
{
  SpawnTask *v1; // rdi
  ActionController *v2; // rbx
  ActionContext *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<SpawnTask,SpawnTask> *v8; // rdx
  UFG::qNode<SpawnTask,SpawnTask> *v9; // rcx
  UFG::qNode<SpawnTask,SpawnTask> *v10; // rax
  UFG::qNode<ITask,ITask> *v11; // rdx
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&SpawnTask::`vftable';
  v2 = &this->m_ActionController;
  v2->vfptr = (Expression::IMemberMapVtbl *)&ActionController::`vftable';
  ActionController::nodeCleanup(&this->m_ActionController);
  v2->m_SequenceNode = 0i64;
  v2->m_previousNode = 0i64;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&v2->m_FinishUpdateTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&v2->m_SequencedTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&v2->m_RunningTasks);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  v3 = &v1->m_ActionContext;
  if ( v1->m_ActionContext.mSimObject.m_pPointer )
  {
    v4 = v3->mSimObject.mPrev;
    v5 = v1->m_ActionContext.mSimObject.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mSimObject.mPrev;
    v1->m_ActionContext.mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_ActionContext.mSimObject.mPrev;
  }
  v1->m_ActionContext.mSimObject.m_pPointer = 0i64;
  v6 = v3->mSimObject.mPrev;
  v7 = v1->m_ActionContext.mSimObject.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mSimObject.mPrev;
  v1->m_ActionContext.mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_ActionContext.mSimObject.mPrev;
  v8 = (UFG::qNode<SpawnTask,SpawnTask> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v11 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v12 = v1->mPrev;
  v13 = v1->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v11->mPrev = v11;
  v11->mNext = v11;
}

// File Line: 402
// RVA: 0x26BB80
void __fastcall SpawnTask::Begin(SpawnTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  SpawnTask *v3; // rdi
  ActionContext *v4; // rsi
  signed __int64 v5; // rbp
  ITrack *v6; // rax
  signed __int64 v7; // rbx
  char *v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // rdx
  __int64 v11; // rax
  ActionNode *v12; // rcx
  ActionNodeRoot *v13; // r15
  ActionNodeRoot *v14; // rax
  ActionNodeRoot *v15; // rsi
  __int64 v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  ITrack *v18; // rdx
  bool v19; // al
  Expression::IMemberMapVtbl *v20; // rax
  signed __int64 v21; // rax
  __int64 v22; // rcx
  signed __int64 v23; // r8
  __int64 v24; // rcx
  signed __int64 v25; // rax
  __int64 v26; // rcx
  signed __int64 v27; // rax
  char v28; // al
  Expression::IMemberMapVtbl *v29; // rax
  __int64 v30; // rax
  signed __int64 v31; // rdx
  __int64 v32; // rax
  signed __int64 v33; // rax
  __int64 v34; // rcx
  signed __int64 v35; // rax
  signed __int64 v36; // r14
  signed __int64 v37; // rbx
  float v38; // xmm0_4
  signed __int64 v39; // rsi
  __int64 v40; // rcx
  _QWORD *v41; // rax
  _QWORD *v42; // rdx
  __int64 v43; // rax
  __int64 v44; // rdi
  __int64 v45; // rax
  signed __int64 v46; // rcx
  float v47; // xmm0_4
  __int64 v48; // rcx
  __int64 v49; // rax
  _QWORD *v50; // rcx
  __int64 v51; // [rsp+30h] [rbp-48h]
  __int16 v52; // [rsp+44h] [rbp-34h]

  this->m_CallingActionContext = context;
  v2 = &this->m_ActionContext;
  v3 = this;
  v4 = context;
  this->m_ActionController.m_BankTracksEnabled = context->mActionController->m_BankTracksEnabled != 0;
  this->m_ActionController.m_OnEnterExitCallbacksEnabled = context->mActionController->m_OnEnterExitCallbacksEnabled != 0;
  ActionContext::operator=(&this->m_ActionContext, context);
  v5 = (signed __int64)&v3->m_ActionController;
  v6 = v3->m_Track + 1;
  v3->m_ActionController.m_Context = v2;
  v3->m_ActionContext.mActionController = &v3->m_ActionController;
  v3->m_ActionContext.mParentContext = v4;
  v7 = 0i64;
  if ( v6->vfptr )
    v8 = (char *)v6->vfptr + (unsigned __int64)v6;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 9);
  if ( v9 )
    v10 = (signed __int64)&v8[v9 + 72];
  else
    v10 = 0i64;
  v3->m_ActionContext.m_OpeningBranch = (ActionNode *)v10;
  v11 = ((__int64 (*)(void))v4->m_OpeningBranch->vfptr[1].GetResourceOwner)();
  v12 = v3->m_ActionContext.m_OpeningBranch;
  v13 = (ActionNodeRoot *)v11;
  if ( v12 )
  {
    v14 = (ActionNodeRoot *)((__int64 (*)(void))v12->vfptr[1].GetResourceOwner)();
    v15 = v14;
    if ( v14 )
    {
      v16 = v14->mActionTreeType.mValue;
      if ( (v2->mActionTreeComponentBase[v16] || v2->mActionTreeComponentBase[1]) && v13 != v14 )
      {
        v17 = v2->mActionTreeComponentBase[v16];
        if ( !v17 )
          v17 = v2->mActionTreeComponentBase[1];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v17, v14) )
          ActionNodeRoot::Init(v15, v2);
      }
    }
  }
  v18 = v3->m_Track;
  v19 = LOBYTE(v18[1].mResourceOwner) != 0;
  v3->m_ActionController.mKeepAlive = v19;
  v3->m_isKeepAlive = v19;
  v20 = v18[1].vfptr;
  if ( v20 )
    v21 = (signed __int64)&v20->ResolveReferences + (_QWORD)v18;
  else
    v21 = 0i64;
  v22 = *(_QWORD *)(v21 + 72);
  if ( v22 && (v23 = v21 + v22 + 72) != 0 && (v24 = *(_QWORD *)(v21 + 16)) != 0 && (v25 = v24 + v21 + 16) != 0 )
  {
    while ( v25 != v23 )
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = v25 + 16;
      if ( v26 )
      {
        v25 = v26 + v27;
        if ( v25 )
          continue;
      }
      goto LABEL_26;
    }
    v28 = 1;
  }
  else
  {
LABEL_26:
    v28 = 0;
  }
  v3->m_isParent = v28;
  if ( v3->m_ActionContext.m_OpeningBranch )
  {
    v3->m_ActionContext.m_ActionTreeType.mValue = SBYTE1(v18[1].mResourceOwner);
    v29 = v18[1].vfptr;
    if ( v29 )
      v7 = (signed __int64)&v18[1] + (_QWORD)v29;
    v30 = *(_QWORD *)(v7 + 72);
    if ( v30 && (v31 = v7 + v30 + 72) != 0 && (v32 = *(_QWORD *)(v7 + 16)) != 0 && (v33 = v7 + v32 + 16) != 0 )
    {
      while ( v33 != v31 )
      {
        v34 = *(_QWORD *)(v33 + 16);
        v35 = v33 + 16;
        if ( v34 )
        {
          v33 = v34 + v35;
          if ( v33 )
            continue;
        }
        goto LABEL_37;
      }
    }
    else
    {
LABEL_37:
      ActionController::Play(&v3->m_ActionController, v3->m_ActionController.m_Context->m_OpeningBranch, 0);
      v36 = (signed __int64)&v3->m_ActionController.m_RunningSpawnTasksTmp[1];
      v37 = (signed __int64)&v3->m_ActionController.m_SequencedTasks.mNode.mNext[-1].mNext;
      if ( (unsigned __int64 *)v37 != &v3->m_ActionController.m_RunningSpawnTasksTmp[1] )
      {
        do
        {
          v38 = *(float *)(v37 + 32);
          v39 = *(_QWORD *)(v37 + 16) - 8i64;
          if ( v38 >= 0.0 && v38 <= *(float *)(v5 + 32) )
          {
            v40 = *(_QWORD *)(v37 + 8);
            v41 = *(_QWORD **)(v37 + 16);
            v42 = (_QWORD *)(v37 + 8);
            *(_QWORD *)(v40 + 8) = v41;
            *v41 = v40;
            *v42 = v42;
            v42[1] = v42;
            v43 = *(_QWORD *)(v5 + 64);
            *(_QWORD *)(v43 + 8) = v37 + 8;
            *v42 = v43;
            v42[1] = v5 + 64;
            *(_QWORD *)(v5 + 64) = v37 + 8;
            v44 = *(_QWORD *)(v37 + 24);
            if ( *(_BYTE *)(v44 + 22) )
            {
              v45 = *(_QWORD *)(v44 + 32);
              if ( v45
                && (v46 = v44 + v45 + 32) != 0
                && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v46 + 24i64))(
                      v46,
                      &v51,
                      UEL::gCurrentParameters,
                      0i64,
                      UEL::gCurrentStringBuilder),
                    v52) )
              {
                if ( v52 == 4 )
                  v47 = *(float *)&v51;
                else
                  v47 = (float)(signed int)v51;
              }
              else
              {
                v47 = *(float *)(v44 + 40);
              }
              *(float *)(v5 + 112) = v47;
            }
            (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v37 + 8i64))(v37, *(_QWORD *)(v5 + 24));
            v48 = *(_QWORD *)(v37 + 24);
            if ( v48 )
            {
              if ( *(_DWORD *)(v48 + 16) == SpawnTrack::sClassNameUID )
              {
                v49 = *(_QWORD *)(v5 + 80);
                v50 = (_QWORD *)(v37 + 40);
                *(_QWORD *)(v49 + 8) = v37 + 40;
                *v50 = v49;
                v50[1] = v5 + 80;
                *(_QWORD *)(v5 + 80) = v37 + 40;
              }
            }
          }
          v37 = v39;
        }
        while ( v39 != v36 );
      }
    }
  }
}

// File Line: 483
// RVA: 0x273760
bool __fastcall SpawnTask::Update(SpawnTask *this, float timeDelta)
{
  ActionNode *v2; // rax
  SpawnTask *v3; // rdi
  bool result; // al
  bool v5; // bl

  v2 = this->m_ActionContext.m_OpeningBranch;
  v3 = this;
  if ( !v2 || this->m_isParent || !v2 )
    return 0;
  v5 = this->m_isKeepAlive != 0;
  ActionController::Update(&this->m_ActionController, timeDelta);
  if ( v5 )
    result = 1;
  else
    result = v3->m_ActionController.m_currentNode != 0i64;
  return result;
}

// File Line: 540
// RVA: 0x26DB10
void __fastcall SpawnTask::End(SpawnTask *this)
{
  ActionController *v1; // rbx

  v1 = &this->m_ActionController;
  ActionController::nodeCleanup(&this->m_ActionController);
  v1->m_SequenceNode = 0i64;
  v1->m_previousNode = 0i64;
}

