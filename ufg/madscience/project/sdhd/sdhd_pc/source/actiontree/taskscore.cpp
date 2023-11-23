// File Line: 41
// RVA: 0x26BB60
void __fastcall PrintTask::Begin(PrintTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax

  m_Track = this->m_Track;
  this->mContext = context;
  if ( BYTE4(m_Track[1].mResourceOwner) )
    PrintTask::DoPrinting(this);
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
  ITrack *m_Track; // r8
  int mResourceOwner; // edx
  int v3; // edx
  ActionContext *mContext; // rax
  UFG::TransformNodeComponent *m_pPointer; // rcx
  unsigned __int64 v6; // rax
  const char *v7; // rcx

  m_Track = this->m_Track;
  mResourceOwner = (int)m_Track[1].mResourceOwner;
  if ( mResourceOwner )
  {
    v3 = mResourceOwner - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        mContext = this->mContext;
        if ( mContext )
        {
          m_pPointer = (UFG::TransformNodeComponent *)mContext->mSimObject.m_pPointer;
          if ( m_pPointer )
            m_pPointer = (UFG::TransformNodeComponent *)m_pPointer->mChildren.mNode.mNext;
          if ( m_pPointer )
          {
            v6 = (unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
            UFG::DrawDebugText(m_pPointer, &UFG::qColour::White, "%s", v6);
          }
        }
      }
    }
    else
    {
      if ( ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        v7 = (char *)&m_Track[1] + ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
      else
        v7 = BinString::sEmptyString;
      UFG::DrawDebugText(0, 0, &UFG::qColour::White, "%s", v7);
    }
  }
  else if ( ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    UFG::qPrintf("%s\n", (const char *)&m_Track[1] + ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64));
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
  ITrack *m_Track; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  ActionNode *v6; // rdx
  char *v7; // rax
  __int64 v8; // r8
  UFG::SimObject *m_pPointer; // rcx
  ActionNode *mTrackNodeBranch; // rdi
  Expression::IMemberMap *v11; // rbp
  ActionNodeRoot *v12; // rax
  __int64 mValue; // r8
  ActionNodeRoot *v14; // rdi
  UFG::ActionTreeComponentBase *v15; // rcx
  ActionNodeRoot *v16; // rax

  this->mContext = context;
  m_Track = this->m_Track;
  vfptr = m_Track[1].vfptr;
  v6 = 0i64;
  if ( vfptr )
    v7 = (char *)&vfptr->ResolveReferences + (_QWORD)m_Track;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 9);
  if ( v8 )
    v6 = (ActionNode *)&v7[v8 + 72];
  this->mTrackNodeBranch = v6;
  this->mTrackTruthDuration = *(float *)&m_Track[1].mMasterRate.text.mOffset;
  this->mTrackTimeLatch = *(float *)&m_Track[1].mBreakPoint;
  this->mTrackEvaluationFrequency = SHIWORD(m_Track[1].m_TrackClassNameUID);
  this->mTrackConditionGroup = (ConditionGroup *)((__int64 (__fastcall *)(ITrack *))m_Track->vfptr[2].__vecDelDtor)(m_Track);
  m_pPointer = this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
    this->mNameUID = m_pPointer->mNode.mUID;
  mTrackNodeBranch = this->mTrackNodeBranch;
  if ( mTrackNodeBranch
    || (OpportunityTrack::GetActionPath((OpportunityTrack *)this->m_Track)->mPath.mCount & 0x7FFFFFFF) == 0
    && (mTrackNodeBranch = this->mContext->m_OpeningBranch) != 0i64 )
  {
    v11 = context->m_OpeningBranch->vfptr[1].GetResourceOwner(context->m_OpeningBranch);
    v12 = (ActionNodeRoot *)mTrackNodeBranch->vfptr[1].GetResourceOwner(mTrackNodeBranch);
    mValue = v12->mActionTreeType.mValue;
    v14 = v12;
    if ( (context->mActionTreeComponentBase[mValue] || context->mActionTreeComponentBase[1]) && v11 != v12 )
    {
      v15 = context->mActionTreeComponentBase[mValue];
      if ( !v15 )
        v15 = context->mActionTreeComponentBase[1];
      if ( UFG::ActionTreeComponentBase::AllocateFor(v15, v12) )
      {
        v16 = (ActionNodeRoot *)v14->vfptr[1].GetResourceOwner(v14);
        ActionNodeRoot::Init(v16, this->mContext);
      }
    }
  }
}

// File Line: 196
// RVA: 0x2735C0
char __fastcall OpportunityTask::Update(OpportunityTask *this, float timeDelta)
{
  unsigned int mTrackEvaluationFrequency; // ecx
  ActionNode *mTrackNodeBranch; // rdi
  float mTrackTruthDuration; // xmm6_4
  ConditionGroup *mTrackConditionGroup; // rcx
  ActionNodePlayable *v8; // rax
  float v9; // xmm8_4
  float mTrackTimeLatch; // xmm0_4
  bool v11; // cl
  bool v12; // al

  if ( !this->mLatchedNode )
  {
    mTrackEvaluationFrequency = this->mTrackEvaluationFrequency;
    if ( mTrackEvaluationFrequency > 1 )
    {
      if ( (UFG::Metrics::msInstance.mSimFrameCount + this->mNameUID) % mTrackEvaluationFrequency )
        return 1;
    }
  }
  mTrackNodeBranch = this->mTrackNodeBranch;
  if ( !mTrackNodeBranch )
  {
    if ( (OpportunityTrack::GetActionPath((OpportunityTrack *)this->m_Track)->mPath.mCount & 0x7FFFFFFF) != 0 )
      return 0;
    mTrackNodeBranch = this->mContext->m_OpeningBranch;
    if ( !mTrackNodeBranch )
      return 0;
  }
  mTrackTruthDuration = this->mTrackTruthDuration;
  if ( !this->mLatchedNode || mTrackTruthDuration > 0.0 )
  {
    mTrackConditionGroup = this->mTrackConditionGroup;
    this->mLatchedNode = 0i64;
    if ( !mTrackConditionGroup
      || mTrackConditionGroup->vfptr[1].FindWithOldPath(mTrackConditionGroup, (const char *)this->mContext) )
    {
      v8 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))mTrackNodeBranch->vfptr[2].GetClassNameUID)(
                                   mTrackNodeBranch,
                                   this->mContext);
      if ( v8 )
      {
        if ( BYTE1(this->m_Track[1].m_TrackClassNameUID) )
        {
          this->mLatchedNode = v8;
        }
        else if ( this->mContext->mActionController->m_currentNode != v8 )
        {
          this->mLatchedNode = v8;
        }
      }
    }
  }
  if ( this->mLatchedNode )
  {
    v9 = timeDelta + this->mTruthDuration;
    mTrackTimeLatch = this->mTrackTimeLatch;
    this->mTruthDuration = v9;
    v11 = mTrackTimeLatch >= 0.0 && mTrackTimeLatch <= this->mContext->mActionController->m_ActionNodePlayTime;
    v12 = mTrackTruthDuration <= 0.0 || v9 >= mTrackTruthDuration;
    if ( v11 && v12 )
      return 0;
    if ( mTrackTruthDuration > 0.0 )
      this->mLatchedNode = 0i64;
  }
  else
  {
    this->mTruthDuration = 0.0;
  }
  return 1;
}

// File Line: 321
// RVA: 0x26DA30
void __fastcall OpportunityTask::End(OpportunityTask *this)
{
  ActionNodePlayable *mLatchedNode; // rdx
  ActionContext *mContext; // r8
  int m_TrackClassNameUID_low; // ecx
  ActionController *mActionController; // rax

  mLatchedNode = this->mLatchedNode;
  if ( mLatchedNode )
  {
    mContext = this->mContext;
    if ( mContext )
    {
      m_TrackClassNameUID_low = SLOBYTE(this->m_Track[1].m_TrackClassNameUID);
      mActionController = mContext->mActionController;
      if ( m_TrackClassNameUID_low > mActionController->m_SequencePriority )
      {
        mActionController->m_SequencePriority = m_TrackClassNameUID_low;
        mActionController->m_SequenceNode = mLatchedNode;
      }
      mActionController->mOverRideNode = 1;
    }
  }
}

// File Line: 345
// RVA: 0x26DA70
void __fastcall SequenceTask::End(SequenceTask *this)
{
  ActionContext *mContext; // rbx
  ITrack *m_Track; // rax
  Expression::IMemberMapVtbl *vfptr; // rcx
  ITrack *v4; // rax
  Expression::IMemberMap *(__fastcall *GetResourceOwner)(Expression::IMemberMap *); // rax
  char *v6; // rdi
  ActionController *mActionController; // rbx
  ActionContext *m_Context; // rcx
  __int64 v9; // rax

  mContext = this->mContext;
  if ( mContext )
  {
    m_Track = this->m_Track;
    vfptr = m_Track[1].vfptr;
    v4 = m_Track + 1;
    if ( vfptr )
      vfptr = (Expression::IMemberMapVtbl *)((char *)vfptr + (_QWORD)v4);
    GetResourceOwner = vfptr->GetResourceOwner;
    if ( GetResourceOwner )
      v6 = (char *)&vfptr->GetResourceOwner + (_QWORD)GetResourceOwner;
    else
      v6 = 0i64;
    mActionController = mContext->mActionController;
    if ( v6 && mActionController->m_SequencePriority < 0 )
    {
      m_Context = mActionController->m_Context;
      if ( m_Context )
        ActionContext::UpdateSignalsAndConditions(m_Context);
      v9 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v6 + 200i64))(
             v6,
             mActionController->m_Context);
      if ( v9 )
      {
        if ( mActionController->m_SequencePriority < 0 )
        {
          mActionController->m_SequencePriority = 0;
          mActionController->m_SequenceNode = (ActionNodePlayable *)v9;
        }
      }
    }
  }
}

// File Line: 375
// RVA: 0x269FB0
void __fastcall SpawnTask::~SpawnTask(SpawnTask *this)
{
  ActionController *p_m_ActionController; // rbx
  ActionContext *p_m_ActionContext; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<SpawnTask,SpawnTask> *v8; // rcx
  UFG::qNode<SpawnTask,SpawnTask> *v9; // rax
  UFG::qNode<ITask,ITask> *v10; // rcx
  UFG::qNode<ITask,ITask> *v11; // rax

  this->vfptr = (ITaskVtbl *)&SpawnTask::`vftable;
  p_m_ActionController = &this->m_ActionController;
  this->m_ActionController.vfptr = (Expression::IMemberMapVtbl *)&ActionController::`vftable;
  ActionController::nodeCleanup(&this->m_ActionController);
  p_m_ActionController->m_SequenceNode = 0i64;
  p_m_ActionController->m_previousNode = 0i64;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&p_m_ActionController->m_FinishUpdateTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&p_m_ActionController->m_SequencedTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&p_m_ActionController->m_RunningTasks);
  p_m_ActionController->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  p_m_ActionContext = &this->m_ActionContext;
  if ( this->m_ActionContext.mSimObject.m_pPointer )
  {
    mPrev = p_m_ActionContext->mSimObject.mPrev;
    mNext = this->m_ActionContext.mSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_ActionContext->mSimObject.mPrev = &p_m_ActionContext->mSimObject;
    this->m_ActionContext.mSimObject.mNext = &this->m_ActionContext.mSimObject;
  }
  this->m_ActionContext.mSimObject.m_pPointer = 0i64;
  v6 = p_m_ActionContext->mSimObject.mPrev;
  v7 = this->m_ActionContext.mSimObject.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_ActionContext->mSimObject.mPrev = &p_m_ActionContext->mSimObject;
  this->m_ActionContext.mSimObject.mNext = &this->m_ActionContext.mSimObject;
  v8 = this->UFG::qNode<SpawnTask,SpawnTask>::mPrev;
  v9 = this->UFG::qNode<SpawnTask,SpawnTask>::mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->UFG::qNode<SpawnTask,SpawnTask>::mPrev = &this->UFG::qNode<SpawnTask,SpawnTask>;
  this->UFG::qNode<SpawnTask,SpawnTask>::mNext = &this->UFG::qNode<SpawnTask,SpawnTask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v10 = this->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev;
  v11 = this->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 402
// RVA: 0x26BB80
void __fastcall SpawnTask::Begin(SpawnTask *this, ActionContext *context)
{
  ActionContext *p_m_ActionContext; // r14
  ActionController *p_m_ActionController; // rbp
  ITrack *v6; // rax
  char *v7; // rbx
  char *v8; // rax
  __int64 v9; // rcx
  ActionNode *v10; // rdx
  Expression::IMemberMap *v11; // rax
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v13; // r15
  ActionNodeRoot *v14; // rax
  ActionNodeRoot *v15; // rsi
  __int64 mValue; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  ITrack *m_Track; // rdx
  bool v19; // al
  Expression::IMemberMapVtbl *vfptr; // rax
  char *v21; // rax
  __int64 v22; // rcx
  char *v23; // r8
  __int64 v24; // rcx
  char *v25; // rax
  __int64 v26; // rcx
  char *v27; // rax
  char v28; // al
  Expression::IMemberMapVtbl *v29; // rax
  __int64 v30; // rax
  char *v31; // rdx
  __int64 v32; // rax
  char *v33; // rax
  __int64 v34; // rcx
  char *v35; // rax
  unsigned __int64 *v36; // r14
  SpawnTask *p_mNext; // rbx
  float m_TimeBegin; // xmm0_4
  __int64 v39; // rsi
  UFG::qNode<ITask,ITask> *mPrev; // rcx
  UFG::qNode<ITask,ITask> *mNext; // rax
  UFG::qNode<ITask,ITask> *v42; // rax
  ITrack *v43; // rdi
  __int64 mOffset; // rax
  char *v45; // rcx
  float value; // xmm0_4
  ITrack *v47; // rcx
  UFG::qNode<SpawnTask,SpawnTask> *v48; // rax
  __int64 v49; // [rsp+30h] [rbp-48h] BYREF
  __int16 v50; // [rsp+44h] [rbp-34h]

  this->m_CallingActionContext = context;
  p_m_ActionContext = &this->m_ActionContext;
  this->m_ActionController.m_BankTracksEnabled = context->mActionController->m_BankTracksEnabled != 0;
  this->m_ActionController.m_OnEnterExitCallbacksEnabled = context->mActionController->m_OnEnterExitCallbacksEnabled != 0;
  ActionContext::operator=(&this->m_ActionContext, context);
  p_m_ActionController = &this->m_ActionController;
  v6 = this->m_Track + 1;
  this->m_ActionController.m_Context = p_m_ActionContext;
  this->m_ActionContext.mActionController = &this->m_ActionController;
  this->m_ActionContext.mParentContext = context;
  v7 = 0i64;
  if ( v6->vfptr )
    v8 = (char *)v6->vfptr + (unsigned __int64)v6;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 9);
  if ( v9 )
    v10 = (ActionNode *)&v8[v9 + 72];
  else
    v10 = 0i64;
  this->m_ActionContext.m_OpeningBranch = v10;
  v11 = context->m_OpeningBranch->vfptr[1].GetResourceOwner(context->m_OpeningBranch);
  m_OpeningBranch = this->m_ActionContext.m_OpeningBranch;
  v13 = (ActionNodeRoot *)v11;
  if ( m_OpeningBranch )
  {
    v14 = (ActionNodeRoot *)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch);
    v15 = v14;
    if ( v14 )
    {
      mValue = v14->mActionTreeType.mValue;
      if ( (p_m_ActionContext->mActionTreeComponentBase[mValue] || p_m_ActionContext->mActionTreeComponentBase[1])
        && v13 != v14 )
      {
        v17 = p_m_ActionContext->mActionTreeComponentBase[mValue];
        if ( !v17 )
          v17 = p_m_ActionContext->mActionTreeComponentBase[1];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v17, v14) )
          ActionNodeRoot::Init(v15, p_m_ActionContext);
      }
    }
  }
  m_Track = this->m_Track;
  v19 = LOBYTE(m_Track[1].mResourceOwner) != 0;
  this->m_ActionController.mKeepAlive = v19;
  this->m_isKeepAlive = v19;
  vfptr = m_Track[1].vfptr;
  if ( vfptr )
    v21 = (char *)&vfptr->ResolveReferences + (_QWORD)m_Track;
  else
    v21 = 0i64;
  v22 = *((_QWORD *)v21 + 9);
  if ( v22 && (v23 = &v21[v22 + 72]) != 0i64 && (v24 = *((_QWORD *)v21 + 2)) != 0 && (v25 = &v21[v24 + 16]) != 0i64 )
  {
    while ( v25 != v23 )
    {
      v26 = *((_QWORD *)v25 + 2);
      v27 = v25 + 16;
      if ( v26 )
      {
        v25 = &v27[v26];
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
  this->m_isParent = v28;
  if ( this->m_ActionContext.m_OpeningBranch )
  {
    this->m_ActionContext.m_ActionTreeType.mValue = SBYTE1(m_Track[1].mResourceOwner);
    v29 = m_Track[1].vfptr;
    if ( v29 )
      v7 = (char *)&m_Track[1] + (_QWORD)v29;
    v30 = *((_QWORD *)v7 + 9);
    if ( v30 && (v31 = &v7[v30 + 72]) != 0i64 && (v32 = *((_QWORD *)v7 + 2)) != 0 && (v33 = &v7[v32 + 16]) != 0i64 )
    {
      while ( v33 != v31 )
      {
        v34 = *((_QWORD *)v33 + 2);
        v35 = v33 + 16;
        if ( v34 )
        {
          v33 = &v35[v34];
          if ( v33 )
            continue;
        }
        goto LABEL_37;
      }
    }
    else
    {
LABEL_37:
      ActionController::Play(&this->m_ActionController, this->m_ActionController.m_Context->m_OpeningBranch, 0);
      v36 = &this->m_ActionController.m_RunningSpawnTasksTmp[1];
      p_mNext = (SpawnTask *)&this->m_ActionController.m_SequencedTasks.mNode.mNext[-1].mNext;
      if ( p_mNext != (SpawnTask *)&this->m_ActionController.m_RunningSpawnTasksTmp[1] )
      {
        do
        {
          m_TimeBegin = p_mNext->m_TimeBegin;
          v39 = (__int64)&p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext[-1].mNext;
          if ( m_TimeBegin >= 0.0 && m_TimeBegin <= p_m_ActionController->m_ActionNodePlayTime )
          {
            mPrev = p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev;
            mNext = p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &p_mNext->UFG::qNode<ITask,ITask>;
            p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &p_mNext->UFG::qNode<ITask,ITask>;
            v42 = p_m_ActionController->m_RunningTasks.mNode.mPrev;
            v42->mNext = &p_mNext->UFG::qNode<ITask,ITask>;
            p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = v42;
            p_mNext->Task<SpawnTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &p_m_ActionController->m_RunningTasks.mNode;
            p_m_ActionController->m_RunningTasks.mNode.mPrev = &p_mNext->UFG::qNode<ITask,ITask>;
            v43 = p_mNext->m_Track;
            if ( v43->mMaster )
            {
              mOffset = v43->mMasterRate.expression.mOffset;
              if ( mOffset
                && (v45 = (char *)&v43->mMasterRate.expression + mOffset) != 0i64
                && ((*(void (__fastcall **)(char *, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v45 + 24i64))(
                      v45,
                      &v49,
                      UEL::gCurrentParameters,
                      0i64,
                      UEL::gCurrentStringBuilder),
                    v50) )
              {
                if ( v50 == 4 )
                  value = *(float *)&v49;
                else
                  value = (float)(int)v49;
              }
              else
              {
                value = v43->mMasterRate.value;
              }
              p_m_ActionController->mRunningMasterRate = value;
            }
            p_mNext->vfptr->Begin(p_mNext, p_m_ActionController->m_Context);
            v47 = p_mNext->m_Track;
            if ( v47 )
            {
              if ( v47->m_TrackClassNameUID == SpawnTrack::sClassNameUID )
              {
                v48 = (UFG::qNode<SpawnTask,SpawnTask> *)p_m_ActionController->m_RunningSpawnTasksTmp[0];
                v48->mNext = &p_mNext->UFG::qNode<SpawnTask,SpawnTask>;
                p_mNext->UFG::qNode<SpawnTask,SpawnTask>::mPrev = v48;
                p_mNext->UFG::qNode<SpawnTask,SpawnTask>::mNext = (UFG::qNode<SpawnTask,SpawnTask> *)p_m_ActionController->m_RunningSpawnTasksTmp;
                p_m_ActionController->m_RunningSpawnTasksTmp[0] = (unsigned __int64)&p_mNext->UFG::qNode<SpawnTask,SpawnTask>;
              }
            }
          }
          p_mNext = (SpawnTask *)v39;
        }
        while ( (unsigned __int64 *)v39 != v36 );
      }
    }
  }
}39;
        }
        while ( (unsigned __int64 *)v39 != v36 );
      }
    }
  }
}

// File Line: 483
// RVA: 0x273760
bool __fastcall SpawnTask::Update(SpawnTask *this, float timeDelta)
{
  bool v4; // bl

  if ( !this->m_ActionContext.m_OpeningBranch || this->m_isParent )
    return 0;
  v4 = this->m_isKeepAlive != 0;
  ActionController::Update(&this->m_ActionController, timeDelta);
  return v4 || this->m_ActionController.m_currentNode != 0i64;
}

// File Line: 540
// RVA: 0x26DB10
void __fastcall SpawnTask::End(SpawnTask *this)
{
  ActionController *p_m_ActionController; // rbx

  p_m_ActionController = &this->m_ActionController;
  ActionController::nodeCleanup(&this->m_ActionController);
  p_m_ActionController->m_SequenceNode = 0i64;
  p_m_ActionController->m_previousNode = 0i64;
}

