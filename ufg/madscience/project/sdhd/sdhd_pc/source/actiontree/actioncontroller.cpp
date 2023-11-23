// File Line: 83
// RVA: 0x1488320
__int64 dynamic_initializer_for__gSpawnTask__()
{
  qword_142047568 = &qword_142047568;
  unk_142047570 = &qword_142047568;
  gSpawnTask.vfptr = (ITaskVtbl *)&SpawnTask::`vftable;
  unk_142047578 = 0i64;
  qword_142047580 = &qword_142047580;
  unk_142047588 = &qword_142047580;
  unk_142047590 = 0i64;
  unk_142047598 = 0i64;
  unk_1420475A0 = 0i64;
  unk_1420475B0 = 0;
  unk_1420475B8 = -1i64;
  unk_1420475C0 = 0;
  unk_142047628 = 0;
  UFG::qMemSet(&unk_14204762C, 0, 0x28u);
  UFG::qMemSet(&unk_1420475E8, 0, 0x40u);
  unk_1420475D0 = 0i64;
  unk_1420475E0 = 0i64;
  unk_142047658 = 0;
  ActionController::ActionController(&stru_142047660);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gSpawnTask__);
}

// File Line: 101
// RVA: 0x26BEE0
__int64 __fastcall ActionController::BreakPointMessageHandler(
        ActionController *this,
        const char *baseMessage,
        const char *appendedMessage)
{
  ActionNodePlayable *m_currentNode; // rcx
  const char *v7; // rbx
  const char *NameFullPathe_DBG; // rax
  ActionNodePlayable *m_SequenceNode; // rcx
  const char *v10; // rcx
  const char *v11; // rax
  unsigned int v12; // ebx
  UFG::qString v14; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v15; // [rsp+60h] [rbp-38h] BYREF

  m_currentNode = this->m_currentNode;
  v7 = "NULL";
  if ( m_currentNode )
    NameFullPathe_DBG = ActionNode::GetNameFullPathe_DBG(m_currentNode);
  else
    NameFullPathe_DBG = "NULL";
  UFG::qString::qString(&v15, NameFullPathe_DBG);
  m_SequenceNode = this->m_SequenceNode;
  if ( m_SequenceNode )
    v7 = ActionNode::GetNameFullPathe_DBG(m_SequenceNode);
  UFG::qString::qString(&v14, v7);
  v10 = &customCaption;
  if ( appendedMessage )
    v10 = appendedMessage;
  v11 = "FALSE";
  if ( this->mOverRideNode )
    v11 = "TRUE";
  v12 = ActionTreeDebugMessageHandler(
          "ACTIONCONTROLLER:%s\n"
          " \t\t\t\t\t\t\t\t\tCurrentNode:\n"
          "%s\n"
          " \t\t\t\t\t\t\t\t\tSequenceNode:\n"
          "%s\n"
          " \t\t\t\t\t\t\t\t\tOverRide:%s\n"
          " \t\t\t\t\t\t\t\t\t%s\n",
          baseMessage,
          v15.mData,
          v14.mData,
          v11,
          v10);
  UFG::qString::~qString(&v14);
  UFG::qString::~qString(&v15);
  return v12;
}

// File Line: 146
// RVA: 0x273CF0
void __fastcall ActionController::breakOnPlay(ActionController *this, ActionNode *node)
{
  char *NameFullPathe_DBG; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( ActionController::sBreakOnPlay
    && node
    && ActionNode::sEnableNodeBreakPoints
    && node->mBreakPoint
    && this->m_Context->mDebugBreak
    && ActionNode::sSoftBreakPoints )
  {
    NameFullPathe_DBG = ActionNode::GetNameFullPathe_DBG(node);
    UFG::qString::FormatEx(&result, "NewNode:\n%s", NameFullPathe_DBG);
    ActionController::BreakPointMessageHandler(this, "ActionController::breakOnPlay", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 158
// RVA: 0x273D80
void __fastcall ActionController::breakOnStart(ActionController *this, ActionNode *node)
{
  char *NameFullPathe_DBG; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( ActionController::sBreakOnStart
    && node
    && ActionNode::sEnableNodeBreakPoints
    && node->mBreakPoint
    && this->m_Context->mDebugBreak
    && ActionNode::sSoftBreakPoints )
  {
    NameFullPathe_DBG = ActionNode::GetNameFullPathe_DBG(node);
    UFG::qString::FormatEx(&result, "NewNode:\n%s", NameFullPathe_DBG);
    ActionController::BreakPointMessageHandler(this, "ActionController::breakOnStart", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 211
// RVA: 0x268850
void __fastcall ActionController::ActionController(ActionController *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionController::`vftable;
  this->m_currentNode = 0i64;
  this->m_Context = 0i64;
  this->m_ActionNodePlayTime = 0.0;
  *(_DWORD *)&this->mUpdating = 256;
  this->m_OnEnterExitCallbacksEnabled = 0;
  this->m_previousNode = 0i64;
  this->m_SequenceNode = 0i64;
  this->m_RunningTasks.mNode.mPrev = &this->m_RunningTasks.mNode;
  this->m_RunningTasks.mNode.mNext = &this->m_RunningTasks.mNode;
  this->m_SequencedTasks.mNode.mPrev = &this->m_SequencedTasks.mNode;
  this->m_SequencedTasks.mNode.mNext = &this->m_SequencedTasks.mNode;
  this->mRunningMasterRate = 1.0;
  this->m_FinishUpdateTasks.mNode.mPrev = &this->m_FinishUpdateTasks.mNode;
  this->m_FinishUpdateTasks.mNode.mNext = &this->m_FinishUpdateTasks.mNode;
  this->m_PlayingMostUsedMask = 0i64;
  this->m_NumPlayingNodes = 0;
  this->m_SequencePriority = -1;
  if ( this != (ActionController *)-80i64 )
  {
    this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)this->m_RunningSpawnTasksTmp;
    this->m_RunningSpawnTasksTmp[1] = (unsigned __int64)this->m_RunningSpawnTasksTmp;
  }
}

// File Line: 216
// RVA: 0x269730
void __fastcall ActionController::~ActionController(ActionController *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionController::`vftable;
  ActionController::nodeCleanup(this);
  this->m_SequenceNode = 0i64;
  this->m_previousNode = 0i64;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&this->m_FinishUpdateTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&this->m_SequencedTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&this->m_RunningTasks);
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 309
// RVA: 0x270730
void __fastcall ActionController::Play(ActionController *this)
{
  ActionController::Play(this, (ActionNodePlayable *)this->m_Context->m_OpeningBranch, 0);
}

// File Line: 314
// RVA: 0x270140
void __fastcall ActionController::Play(ActionController *this, ActionNodePlayable *node, bool forcePlay)
{
  ActionContext *m_Context; // rax
  ActionContext *v7; // rbp
  UFG::SimObjectCVBase *m_pPointer; // rcx
  unsigned __int64 mSignals; // rsi
  UFG::AICharacterControllerBaseComponent *v10; // rax
  Expression::IMemberMap *v11; // rax
  ActionNodeRoot *v12; // rsi
  ActionContext *v13; // rdx
  ActionNode *m_OpeningBranch; // rcx
  __int64 v15; // rax
  ActionContext *v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  UEL::ParametersBase *v18; // rsi
  UFG::SimObjectGame *v19; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  ActionNodePlayable *v22; // rax
  int m_SequencePriority; // edx
  int v24; // ecx

  if ( node )
  {
    m_Context = this->m_Context;
    if ( m_Context )
    {
      m_Context->mProbabilitiesValid = 0;
      v7 = this->m_Context;
      m_pPointer = (UFG::SimObjectCVBase *)v7->mSimObject.m_pPointer;
      mSignals = 0i64;
      if ( m_pPointer )
      {
        if ( (m_pPointer->m_Flags & 0x4000) != 0 )
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
          if ( v10 )
            mSignals = v10->m_Intention.mSignals;
        }
      }
      v7->mSignals = mSignals;
    }
    v11 = node->vfptr[1].GetResourceOwner(node);
    v12 = (ActionNodeRoot *)v11;
    if ( v11 )
    {
      v13 = this->m_Context;
      if ( v13->mActionTreeComponentBase[SBYTE4(v11[14].mResourceOwner)] || v13->mActionTreeComponentBase[1] )
      {
        m_OpeningBranch = v13->m_OpeningBranch;
        v15 = m_OpeningBranch ? (__int64)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch) : 0i64;
        if ( (ActionNodeRoot *)v15 != v12 )
        {
          v16 = this->m_Context;
          v17 = v16->mActionTreeComponentBase[v12->mActionTreeType.mValue];
          if ( !v17 )
            v17 = v16->mActionTreeComponentBase[1];
          if ( UFG::ActionTreeComponentBase::AllocateFor(v17, v12) )
            ActionNodeRoot::Init(v12, this->m_Context);
        }
      }
    }
    v18 = UEL::gCurrentParameters;
    v19 = (UFG::SimObjectGame *)this->m_Context->mSimObject.m_pPointer;
    if ( v19
      && ((m_Flags = v19->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v19, UFG::UELComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::UELComponent::_TypeUID)))
          : (ComponentOfType = v19->m_Components.p->m_pComponent))
         : (ComponentOfType = v19->m_Components.p->m_pComponent))
        : (ComponentOfType = v19->m_Components.p->m_pComponent),
          ComponentOfType) )
    {
      UEL::gCurrentParameters = (UEL::ParametersBase *)&ComponentOfType[1].m_TypeUID;
    }
    else
    {
      UEL::gCurrentParameters = 0i64;
    }
    v22 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNodePlayable *, ActionContext *))node->vfptr[2].GetClassNameUID)(
                                  node,
                                  this->m_Context);
    if ( !v22 && forcePlay )
    {
      if ( node->vfptr->GetClassNameUID(node) == TrackLibraryNode::sClassNameUID )
      {
        ActionController::PlayTracks(this, node, 1, 0.0);
        return;
      }
      v22 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNodePlayable *))node->vfptr[2].GetResourcePath)(node);
    }
    if ( this->mUpdating )
    {
      m_SequencePriority = this->m_SequencePriority;
      v24 = m_SequencePriority + 1;
      if ( v22 )
      {
        if ( v24 > m_SequencePriority )
        {
          this->m_SequencePriority = v24;
          this->m_SequenceNode = v22;
        }
        this->mOverRideNode = 1;
      }
    }
    else
    {
      ActionController::Play(this, v22);
    }
    UEL::gCurrentParameters = v18;
  }
}

// File Line: 395
// RVA: 0x275880
void __fastcall ActionController::setPlayingNodeUID(
        ActionController *this,
        ActionNodePlayable *currentNode,
        bool addPlayingInfo)
{
  unsigned int m_NumPlayingNodes; // edi
  unsigned __int64 m_PlayingMostUsedMask; // rbp
  __int64 mOffset; // rax
  ActionNodePlayable *v8; // r8
  __int64 mMostUsedIndex; // rdx
  __int64 v10; // rax
  ActionContext *m_Context; // rcx
  char v12; // al

  m_NumPlayingNodes = 0;
  m_PlayingMostUsedMask = 0i64;
  if ( addPlayingInfo )
  {
    m_NumPlayingNodes = this->m_NumPlayingNodes;
    m_PlayingMostUsedMask = this->m_PlayingMostUsedMask;
  }
  else
  {
    UFG::qMemSet(this->m_Context->mMostUsedPlayCount, 0, 0x40u);
  }
  while ( 1 )
  {
    mOffset = currentNode->mParent.mOffset;
    if ( !mOffset )
      break;
    v8 = (ActionNodePlayable *)((char *)&currentNode->mParent + mOffset);
    if ( !v8 )
      break;
    if ( m_NumPlayingNodes < 0x20 )
    {
      mMostUsedIndex = currentNode->mMostUsedIndex;
      v10 = m_NumPlayingNodes++;
      this->m_PlayingNodeUID[v10].mUID = currentNode->mID.mUID;
      if ( (_DWORD)mMostUsedIndex != -1 )
      {
        m_Context = this->m_Context;
        for ( m_PlayingMostUsedMask |= 1i64 << mMostUsedIndex; m_Context; m_Context = m_Context->mParentContext )
        {
          v12 = m_Context->mMostUsedPlayCount[mMostUsedIndex];
          if ( (unsigned __int8)v12 >= 0xFAu )
            break;
          m_Context->mMostUsedPlayCount[mMostUsedIndex] = v12 + 1;
        }
      }
    }
    currentNode = v8;
  }
  this->m_PlayingMostUsedMask = m_PlayingMostUsedMask;
  this->m_NumPlayingNodes = m_NumPlayingNodes;
}

// File Line: 449
// RVA: 0x270360
void __fastcall ActionController::Play(ActionController *this, ActionNodePlayable *node)
{
  ActionContext *m_Context; // rax
  int m_SequencePriority; // ecx
  int v6; // eax
  Expression::IMemberMap *v7; // rax
  ActionNodeRoot *v8; // rbx
  ActionContext *v9; // rdx
  ActionNode *m_OpeningBranch; // rcx
  __int64 v11; // rax
  ActionContext *v12; // rdx
  UFG::ActionTreeComponentBase *v13; // rcx
  __int64 v14; // rax
  char *v15; // r9
  __int64 v16; // rbp
  __int64 v17; // rdi
  __int64 v18; // r14
  __int64 v19; // rcx
  __int64 v20; // rax
  ActionNodePlayable *v21; // rdx
  UFG::qNode<ITask,ITask> *v22; // rax
  UFG::qNode<ITask,ITask> *mPrev; // rcx
  ActionNodePlayable *m_currentNode; // rax
  __int64 mOffset; // rcx
  UFG::qOffset64<ActionNode *> *p_mParent; // rax
  ActionNode *i; // rbx
  __int64 v28; // rax
  __int64 v29; // rdi
  __int64 v30; // rbp
  __int64 v31; // r15
  UFG::qList<ITask,ITask,0,0> *p_m_SequencedTasks; // r14
  __int64 v33; // rcx
  UFG::qNode<ITask,ITask> *v34; // rax
  UFG::qNode<ITask,ITask> *v35; // rcx
  __int64 v36; // rax
  UFG::qOffset64<ActionNode *> *v37; // rbx
  ActionNodePlayable *v38; // r8
  int v39; // r10d
  ActionNode *v40; // r11
  ActionNode *v41; // rcx
  ActionNodePlayable *v42; // rdx
  __int64 v43; // rax
  UFG::qOffset64<ActionNode *> *v44; // rdx
  __int64 v45; // rax
  UFG::qOffset64<ActionNode *> *v46; // rcx
  bool v47; // zf
  __int64 v48; // rax
  UFG::qOffset64<ActionNode *> *v49; // r8
  __int64 j; // rbp
  __int64 v51; // rdi
  ActionContext *v52; // r14
  __int64 *k; // rbx
  __int64 v54; // [rsp+18h] [rbp-120h]
  char v55; // [rsp+20h] [rbp-118h] BYREF

  ActionController::breakOnPlay(this, node);
  m_Context = this->m_Context;
  if ( m_Context )
    m_Context->mProbabilitiesValid = 0;
  if ( this->mUpdating )
  {
    m_SequencePriority = this->m_SequencePriority;
    v6 = m_SequencePriority + 1;
    if ( node )
    {
      if ( v6 > m_SequencePriority )
      {
        this->m_SequencePriority = v6;
        this->m_SequenceNode = node;
      }
      this->mOverRideNode = 1;
    }
  }
  else
  {
    ActionController::breakOnStart(this, node);
    ActionController::nodeCleanup(this);
    this->m_SequenceNode = 0i64;
    this->m_currentNode = node;
    if ( node )
    {
      v7 = node->vfptr[1].GetResourceOwner(node);
      v8 = (ActionNodeRoot *)v7;
      if ( v7 )
      {
        v9 = this->m_Context;
        if ( v9->mActionTreeComponentBase[SBYTE4(v7[14].mResourceOwner)] || v9->mActionTreeComponentBase[1] )
        {
          m_OpeningBranch = v9->m_OpeningBranch;
          v11 = m_OpeningBranch ? (__int64)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch) : 0i64;
          if ( (ActionNodeRoot *)v11 != v8 )
          {
            v12 = this->m_Context;
            v13 = v12->mActionTreeComponentBase[v8->mActionTreeType.mValue];
            if ( !v13 )
              v13 = v12->mActionTreeComponentBase[1];
            if ( UFG::ActionTreeComponentBase::AllocateFor(v13, v8) )
              ActionNodeRoot::Init(v8, this->m_Context);
          }
        }
      }
      ActionController::setPlayingNodeUID(this, this->m_currentNode, 0);
      v14 = ((__int64 (__fastcall *)(ActionNodePlayable *))this->m_currentNode->vfptr[3].GetClassNameUID)(this->m_currentNode);
      v16 = v14;
      if ( v14 )
      {
        v17 = 0i64;
        v18 = *(_QWORD *)(v14 + 24) + v14 + 24;
        if ( (*(_DWORD *)(v14 + 16) & 0x7FFFFFFF) != 0 )
        {
          do
          {
            v19 = *(_QWORD *)(v18 + 8 * v17) + v18 + 8 * v17;
            if ( *(_DWORD *)(v19 + 16) == ExecuteTrackLibraryTrack::sClassNameUID )
            {
              v20 = *(_QWORD *)(v19 + 0x38);
              if ( v20 )
                v20 += v19 + 56;
              v21 = *(ActionNodePlayable **)(v20 + 0x48);
              if ( v21 )
                v21 = (ActionNodePlayable *)((char *)v21 + v20 + 72);
              ActionController::PlayTracks(this, v21, 1, *(float *)(v19 + 48));
            }
            else
            {
              v22 = (UFG::qNode<ITask,ITask> *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v19 + 80i64))(
                                                 v19,
                                                 "ActionController::Play(): My tasks");
              mPrev = this->m_SequencedTasks.mNode.mPrev;
              v22 = (UFG::qNode<ITask,ITask> *)((char *)v22 + 8);
              mPrev->mNext = v22;
              v22->mPrev = mPrev;
              v22->mNext = &this->m_SequencedTasks.mNode;
              this->m_SequencedTasks.mNode.mPrev = v22;
            }
            v17 = (unsigned int)(v17 + 1);
          }
          while ( (unsigned int)v17 < (*(_DWORD *)(v16 + 16) & 0x7FFFFFFFu) );
        }
      }
      if ( this->m_BankTracksEnabled )
      {
        m_currentNode = this->m_currentNode;
        mOffset = m_currentNode->mParent.mOffset;
        p_mParent = &m_currentNode->mParent;
        if ( mOffset )
        {
          for ( i = (ActionNode *)((char *)p_mParent + mOffset); i; i = (ActionNode *)((char *)v37 + v36) )
          {
            if ( i->vfptr->GetClassNameUID(i) == ActionNodeBank::sClassNameUID
              || i->vfptr->GetClassNameUID(i) == ActionNodeRoot::sClassNameUID )
            {
              v28 = ((__int64 (__fastcall *)(ActionNode *))i->vfptr[3].GetClassNameUID)(i);
              v29 = v28;
              if ( v28 )
              {
                v30 = 0i64;
                v31 = v28 + *(_QWORD *)(v28 + 24) + 24i64;
                if ( (*(_DWORD *)(v28 + 16) & 0x7FFFFFFF) != 0 )
                {
                  p_m_SequencedTasks = &this->m_SequencedTasks;
                  do
                  {
                    v33 = *(_QWORD *)(v31 + 8 * v30) + v31 + 8 * v30;
                    v34 = (UFG::qNode<ITask,ITask> *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v33 + 80i64))(
                                                       v33,
                                                       "ActionController::Play(): Parents tasks");
                    v35 = p_m_SequencedTasks->mNode.mPrev;
                    v30 = (unsigned int)(v30 + 1);
                    v34 = (UFG::qNode<ITask,ITask> *)((char *)v34 + 8);
                    v35->mNext = v34;
                    v34->mPrev = v35;
                    v34->mNext = &p_m_SequencedTasks->mNode;
                    p_m_SequencedTasks->mNode.mPrev = v34;
                  }
                  while ( (unsigned int)v30 < (*(_DWORD *)(v29 + 16) & 0x7FFFFFFFu) );
                }
              }
            }
            if ( i == this->m_Context->m_OpeningBranch )
              break;
            v36 = i->mParent.mOffset;
            v37 = &i->mParent;
            if ( !v36 )
              break;
          }
        }
      }
      if ( this->m_OnEnterExitCallbacksEnabled )
      {
        v38 = this->m_currentNode;
        v39 = 0;
        if ( v38 )
        {
          v15 = &v55;
          v40 = this->m_Context->m_OpeningBranch;
          do
          {
            ++v39;
            *(_QWORD *)v15 = v38;
            v15 += 8;
            v41 = v40;
            v42 = v38;
            if ( v38 == v40 )
              break;
            while ( v41 )
            {
              if ( v42->mID.mUID != v41->mID.mUID )
                goto LABEL_58;
              v43 = v42->mParent.mOffset;
              v44 = &v42->mParent;
              if ( v43 )
                v42 = (ActionNodePlayable *)((char *)v44 + v43);
              else
                v42 = 0i64;
              v45 = v41->mParent.mOffset;
              v46 = &v41->mParent;
              if ( v45 )
                v41 = (ActionNode *)((char *)v46 + v45);
              else
                v41 = 0i64;
              if ( !v42 )
              {
                v47 = v41 == 0i64;
                goto LABEL_57;
              }
            }
            v47 = v42 == 0i64;
LABEL_57:
            if ( v47 )
              break;
LABEL_58:
            v48 = v38->mParent.mOffset;
            v49 = &v38->mParent;
            if ( !v48 )
              break;
            v38 = (ActionNodePlayable *)((char *)v49 + v48);
          }
          while ( v38 );
        }
        for ( j = v39; j > 0; --j )
        {
          v51 = *(&v54 + j);
          v52 = this->m_Context;
          for ( k = *(__int64 **)(v51 + 24); k; k = (__int64 *)*k )
          {
            if ( !*((_DWORD *)k + 6) )
              ((void (__fastcall *)(__int64, __int64, ActionContext *, char *))k[2])(k[1], v51, v52, v15);
          }
        }
      }
    }
  }
}

// File Line: 625
// RVA: 0x270740
void __fastcall ActionController::PlayTracks(
        ActionController *this,
        ActionNode *node,
        bool offsetTimeBeginAndEnd,
        float offsetTime)
{
  ActionContext *m_Context; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  unsigned __int64 mSignals; // rdi
  UFG::AICharacterControllerBaseComponent *v10; // rax
  ActionNodePlayable *v11; // rax

  m_Context = this->m_Context;
  if ( m_Context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)m_Context->mSimObject.m_pPointer;
    mSignals = 0i64;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
        if ( v10 )
          mSignals = v10->m_Intention.mSignals;
      }
    }
    m_Context->mSignals = mSignals;
  }
  v11 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))node->vfptr[2].GetClassNameUID)(
                                node,
                                this->m_Context);
  if ( v11 )
    ActionController::PlayTracks(this, v11, offsetTimeBeginAndEnd, offsetTime);
}

// File Line: 641
// RVA: 0x2707F0
void __fastcall ActionController::PlayTracks(
        ActionController *this,
        ActionNodePlayable *node,
        bool offsetTimeBeginAndEnd,
        float offsetTime)
{
  __int64 v5; // rax
  __int64 v6; // rbp
  __int64 v7; // rcx
  __int64 v8; // rsi
  ActionNodePlayable **p_m_SequenceNode; // rdi
  __int64 v10; // rcx
  UFG::qNode<ITask,ITask> **p_mNext; // rax
  bool v12; // dl
  unsigned __int64 *v13; // rax
  bool v14; // dl
  __int64 v15; // rax
  ActionNodePlayable *v16; // rdx
  __int64 v17; // rax
  float v18; // xmm0_4
  float v19; // xmm0_4
  UFG::qNode<ITask,ITask> *v20; // rcx
  UFG::qNode<ITask,ITask> *mPrev; // rax
  __int64 v22; // [rsp+68h] [rbp+10h]

  if ( node )
  {
    v5 = ((__int64 (__fastcall *)(ActionNodePlayable *))node->vfptr[3].GetClassNameUID)(node);
    v6 = v5;
    if ( v5 )
    {
      v7 = *(_QWORD *)(v5 + 24) + v5 + 24;
      v8 = 0i64;
      v22 = v7;
      if ( (*(_DWORD *)(v5 + 16) & 0x7FFFFFFF) != 0 )
      {
        p_m_SequenceNode = &this->m_SequenceNode;
        do
        {
          v10 = *(_QWORD *)(v7 + 8 * v8) + v7 + 8 * v8;
          p_mNext = &this->m_RunningTasks.mNode.mNext[-1].mNext;
          v12 = p_mNext == (UFG::qNode<ITask,ITask> **)p_m_SequenceNode;
          if ( this->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v12 )
                break;
              if ( (UFG::qNode<ITask,ITask> *)v10 == p_mNext[3] )
                goto LABEL_26;
              p_mNext = &p_mNext[2][-1].mNext;
              v12 = p_mNext == (UFG::qNode<ITask,ITask> **)p_m_SequenceNode;
            }
            while ( p_mNext );
          }
          v13 = (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
          v14 = v13 == &this->m_RunningSpawnTasksTmp[1];
          if ( this->m_SequencedTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v14 )
                break;
              if ( v10 == v13[3] )
                goto LABEL_26;
              v13 = (unsigned __int64 *)(v13[2] - 8);
              v14 = v13 == &this->m_RunningSpawnTasksTmp[1];
            }
            while ( v13 );
          }
          if ( *(_DWORD *)(v10 + 16) == ExecuteTrackLibraryTrack::sClassNameUID )
          {
            v15 = *(_QWORD *)(v10 + 56);
            if ( v15 )
              v15 += v10 + 56;
            v16 = *(ActionNodePlayable **)(v15 + 72);
            if ( v16 )
              v16 = (ActionNodePlayable *)((char *)v16 + v15 + 72);
            ActionController::PlayTracks(this, v16, 1, *(float *)(v10 + 48));
          }
          else
          {
            v17 = (*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v10 + 80i64))(
                    v10,
                    "ActionController::PlayTracks()");
            if ( offsetTimeBeginAndEnd && offsetTime > 0.0 )
            {
              v18 = *(float *)(v17 + 32);
              if ( v18 >= 0.0 )
                *(float *)(v17 + 32) = v18 + offsetTime;
              v19 = *(float *)(v17 + 36);
              if ( v19 >= 0.0 )
                *(float *)(v17 + 36) = v19 + offsetTime;
            }
            v20 = (UFG::qNode<ITask,ITask> *)(v17 + 8);
            mPrev = this->m_SequencedTasks.mNode.mPrev;
            mPrev->mNext = v20;
            v20->mPrev = mPrev;
            v20->mNext = &this->m_SequencedTasks.mNode;
            this->m_SequencedTasks.mNode.mPrev = v20;
          }
LABEL_26:
          v7 = v22;
          v8 = (unsigned int)(v8 + 1);
        }
        while ( (unsigned int)v8 < (*(_DWORD *)(v6 + 16) & 0x7FFFFFFFu) );
      }
    }
  }
}

// File Line: 706
// RVA: 0x2709B0
void __fastcall ActionController::PlayTracks(
        ActionController *this,
        ITrack *track,
        bool offsetTimeBeginAndEnd,
        float offsetTime)
{
  ActionNodePlayable **p_mNext; // rax
  bool v8; // dl
  unsigned __int64 *v9; // rdx
  unsigned __int64 *v10; // rax
  bool i; // cl
  Expression::IMemberMapVtbl *vfptr; // rax
  ActionNodePlayable *v13; // rdx
  char *v14; // rax
  __int64 v15; // rcx
  Expression::IMemberMap *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  UFG::qNode<ITask,ITask> *p_mResourceOwner; // rcx
  UFG::qNode<ITask,ITask> *mPrev; // rax

  if ( track )
  {
    p_mNext = (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
    v8 = p_mNext == &this->m_SequenceNode;
    if ( this->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
    {
      do
      {
        if ( v8 )
          break;
        if ( track == (ITrack *)p_mNext[3] )
          return;
        p_mNext = (ActionNodePlayable **)&p_mNext[2][-1].mChildren.mData;
        v8 = p_mNext == &this->m_SequenceNode;
      }
      while ( p_mNext );
    }
    v9 = &this->m_RunningSpawnTasksTmp[1];
    v10 = (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
    for ( i = v10 == &this->m_RunningSpawnTasksTmp[1]; v10; i = v10 == v9 )
    {
      if ( i )
        break;
      if ( track == (ITrack *)v10[3] )
        return;
      v10 = (unsigned __int64 *)(v10[2] - 8);
    }
    if ( track->m_TrackClassNameUID == ExecuteTrackLibraryTrack::sClassNameUID )
    {
      vfptr = track[1].vfptr;
      v13 = 0i64;
      if ( vfptr )
        v14 = (char *)&vfptr->ResolveReferences + (_QWORD)track;
      else
        v14 = 0i64;
      v15 = *((_QWORD *)v14 + 9);
      if ( v15 )
        v13 = (ActionNodePlayable *)&v14[v15 + 72];
      ActionController::PlayTracks(this, v13, 1, track->mTimeBegin);
    }
    v16 = track->vfptr[1].FindWithOldPath(track, "ActionController::PlayTracks()");
    if ( offsetTimeBeginAndEnd && offsetTime > 0.0 )
    {
      v17 = *(float *)&v16[2].vfptr;
      if ( v17 >= 0.0 )
        *(float *)&v16[2].vfptr = v17 + offsetTime;
      v18 = *((float *)&v16[2].vfptr + 1);
      if ( v18 >= 0.0 )
        *((float *)&v16[2].vfptr + 1) = v18 + offsetTime;
    }
    p_mResourceOwner = (UFG::qNode<ITask,ITask> *)&v16->mResourceOwner;
    mPrev = this->m_SequencedTasks.mNode.mPrev;
    mPrev->mNext = p_mResourceOwner;
    p_mResourceOwner->mPrev = mPrev;
    p_mResourceOwner->mNext = &this->m_SequencedTasks.mNode;
    this->m_SequencedTasks.mNode.mPrev = p_mResourceOwner;
  }
}

// File Line: 756
// RVA: 0x270B10
void __fastcall ActionController::PlayTracks(
        ActionController *this,
        TrackGroup *group,
        bool offsetTimeBeginAndEnd,
        float offsetTime)
{
  __int64 v4; // rsi
  char *v5; // r14
  __int64 v9; // rbx
  ActionNodePlayable **p_mNext; // rax
  bool v11; // cl
  unsigned __int64 *v12; // rax
  bool v13; // cl
  __int64 v14; // rax
  __int64 v15; // rcx
  ActionNodePlayable *v16; // rdx
  __int64 v17; // rax
  float v18; // xmm0_4
  float v19; // xmm0_4
  UFG::qNode<ITask,ITask> *v20; // rcx
  UFG::qNode<ITask,ITask> *mPrev; // rax

  if ( group )
  {
    v4 = 0i64;
    v5 = (char *)&group->mTracks.mData + group->mTracks.mData.mOffset;
    if ( (group->mTracks.mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v9 = (__int64)&v5[8 * v4 + *(_QWORD *)&v5[8 * v4]];
        if ( v9 )
        {
          p_mNext = (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
          v11 = p_mNext == &this->m_SequenceNode;
          if ( this->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v11 )
                break;
              if ( (ActionNodePlayable *)v9 == p_mNext[3] )
                goto LABEL_26;
              p_mNext = (ActionNodePlayable **)&p_mNext[2][-1].mChildren.mData;
              v11 = p_mNext == &this->m_SequenceNode;
            }
            while ( p_mNext );
          }
          v12 = (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
          v13 = v12 == &this->m_RunningSpawnTasksTmp[1];
          if ( this->m_SequencedTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v13 )
                break;
              if ( v9 == v12[3] )
                goto LABEL_26;
              v12 = (unsigned __int64 *)(v12[2] - 8);
              v13 = v12 == &this->m_RunningSpawnTasksTmp[1];
            }
            while ( v12 );
          }
          if ( *(_DWORD *)(v9 + 16) == ExecuteTrackLibraryTrack::sClassNameUID )
          {
            v14 = *(_QWORD *)(v9 + 56);
            if ( v14 )
              v14 += v9 + 56;
            v15 = *(_QWORD *)(v14 + 72);
            if ( v15 )
              v16 = (ActionNodePlayable *)(v15 + v14 + 72);
            else
              v16 = 0i64;
            ActionController::PlayTracks(this, v16, 1, *(float *)(v9 + 48));
          }
          v17 = (*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v9 + 80i64))(
                  v9,
                  "ActionController::PlayTracks()");
          if ( offsetTimeBeginAndEnd && offsetTime > 0.0 )
          {
            v18 = *(float *)(v17 + 32);
            if ( v18 >= 0.0 )
              *(float *)(v17 + 32) = v18 + offsetTime;
            v19 = *(float *)(v17 + 36);
            if ( v19 >= 0.0 )
              *(float *)(v17 + 36) = v19 + offsetTime;
          }
          v20 = (UFG::qNode<ITask,ITask> *)(v17 + 8);
          mPrev = this->m_SequencedTasks.mNode.mPrev;
          mPrev->mNext = v20;
          v20->mPrev = mPrev;
          v20->mNext = &this->m_SequencedTasks.mNode;
          this->m_SequencedTasks.mNode.mPrev = v20;
        }
LABEL_26:
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < (group->mTracks.mCount & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 787
// RVA: 0x272290
void __fastcall ActionController::Sequence(
        ActionController *this,
        ActionNodePlayable *node,
        int priority,
        bool override)
{
  if ( node )
  {
    if ( priority > this->m_SequencePriority )
    {
      this->m_SequencePriority = priority;
      this->m_SequenceNode = node;
    }
    if ( override )
      this->mOverRideNode = 1;
  }
}

// File Line: 807
// RVA: 0x272A80
void __fastcall ActionController::Stop(ActionController *this)
{
  ActionController::nodeCleanup(this);
  this->m_SequenceNode = 0i64;
  this->m_previousNode = 0i64;
}

// File Line: 820
// RVA: 0x272E40
void __fastcall ActionController::Update(ActionController *this, float timeDelta)
{
  ActionNodePlayable *m_currentNode; // rax
  ActionController *v4; // rdi
  float v5; // xmm0_4
  ActionController *v6; // r14
  Expression::IMemberMap *v7; // rcx
  ActionNodePlayable *v8; // rax
  UFG::qNode<ITask,ITask> *v9; // rax
  ActionContext *v10; // rsi
  ActionController *v11; // rax
  char *v12; // rcx
  float v13; // xmm0_4
  ActionContext *v14; // rcx
  unsigned __int64 v15; // rax
  ActionContext *m_Context; // rdi
  UFG::qNode<ITask,ITask> **v17; // r14
  UFG::SimObjectCVBase *m_pPointer; // rcx
  unsigned __int64 mSignals; // rsi
  UFG::AICharacterControllerBaseComponent *v20; // rax
  ActionNodePlayable **p_m_SequenceNode; // r12
  ActionController *v22; // r8
  ActionController *p_mNext; // rdx
  __int64 p_mData; // rcx
  ActionContext *v25; // rdi
  ActionController *mActionController; // rax
  ActionNode **p_m_OpeningBranch; // rdi
  __int64 v28; // rcx
  float v29; // xmm0_4
  float v30; // xmm7_4
  unsigned __int64 *v31; // r15
  ActionController *v32; // rdi
  char v33; // r13
  float m_ActionNodePlayTime; // xmm0_4
  ActionController *v35; // r15
  Expression::IMemberMap *mResourceOwner; // rcx
  ActionNodePlayable *v37; // rax
  UFG::qNode<ITask,ITask> *mPrev; // rax
  ActionContext *v39; // rsi
  ActionController *v40; // rax
  char *v41; // rcx
  float v42; // xmm0_4
  ActionContext *v43; // rcx
  unsigned __int64 v44; // rax
  ActionContext *v45; // rax
  bool v46; // cc
  char v47; // al
  UFG::qNode<ITask,ITask> **v48; // rdx
  __int64 v49; // rcx
  bool v50; // zf
  ActionNodePlayable *v51; // rax
  const char *v52; // r8
  bool v53; // di
  unsigned __int64 *v54; // rdi
  float v55; // xmm0_4
  __int64 v56; // r14
  unsigned __int64 v57; // rcx
  unsigned __int64 *v58; // rax
  UFG::qNode<ITask,ITask> *v59; // rax
  unsigned __int64 v60; // rsi
  __int64 v61; // rax
  unsigned __int64 v62; // rcx
  float v63; // xmm0_4
  unsigned __int64 v64; // rcx
  unsigned __int64 v65; // rax
  unsigned __int64 *v66; // rdi
  float v67; // xmm0_4
  __int64 v68; // r14
  unsigned __int64 v69; // rcx
  unsigned __int64 *v70; // rax
  UFG::qNode<ITask,ITask> *v71; // rax
  unsigned __int64 v72; // rsi
  __int64 v73; // rax
  unsigned __int64 v74; // rcx
  float v75; // xmm0_4
  unsigned __int64 v76; // rcx
  unsigned __int64 v77; // rax
  __int64 v78[2]; // [rsp+30h] [rbp-9h] BYREF
  __int16 v79; // [rsp+44h] [rbp+Bh]

  if ( ActionController::sBreakOnUpdate )
  {
    m_currentNode = this->m_currentNode;
    if ( m_currentNode )
    {
      if ( ActionNode::sEnableNodeBreakPoints
        && m_currentNode->mBreakPoint
        && this->m_Context->mDebugBreak
        && ActionNode::sSoftBreakPoints )
      {
        ActionController::BreakPointMessageHandler(this, "ActionController::breakOnUpdate", 0i64);
      }
    }
  }
  if ( this->m_currentNode || !this->mKeepAlive )
  {
    m_Context = this->m_Context;
    v17 = 0i64;
    if ( m_Context )
    {
      m_pPointer = (UFG::SimObjectCVBase *)m_Context->mSimObject.m_pPointer;
      mSignals = 0i64;
      if ( m_pPointer )
      {
        if ( (m_pPointer->m_Flags & 0x4000) != 0 )
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
          if ( v20 )
            mSignals = v20->m_Intention.mSignals;
        }
      }
      m_Context->mSignals = mSignals;
    }
    p_m_SequenceNode = &this->m_SequenceNode;
    v22 = 0i64;
    p_mNext = (ActionController *)&this->m_RunningTasks.mNode.mNext[-1].mNext;
    if ( p_mNext != (ActionController *)&this->m_SequenceNode )
    {
      do
      {
        p_mData = (__int64)&p_mNext->m_currentNode[-1].mChildren.mData;
        if ( BYTE6(p_mNext->m_Context->mSimObject.m_pPointer) )
          v22 = p_mNext;
        p_mNext = (ActionController *)&p_mNext->m_currentNode[-1].mChildren.mData;
      }
      while ( (ActionNodePlayable **)p_mData != p_m_SequenceNode );
      if ( v22 )
      {
        v25 = v22->m_Context;
        mActionController = v25->mActionController;
        p_m_OpeningBranch = &v25->m_OpeningBranch;
        if ( mActionController
          && (v28 = (__int64)&mActionController->mResourceOwner + (_QWORD)p_m_OpeningBranch) != 0
          && ((*(void (__fastcall **)(__int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v28 + 24i64))(
                v28,
                v78,
                UEL::gCurrentParameters,
                0i64,
                UEL::gCurrentStringBuilder),
              v79) )
        {
          if ( v79 == 4 )
            v29 = *(float *)v78;
          else
            v29 = (float)SLODWORD(v78[0]);
        }
        else
        {
          v29 = *((float *)p_m_OpeningBranch + 4);
        }
        this->mRunningMasterRate = v29;
      }
    }
    v30 = timeDelta * this->mRunningMasterRate;
    v31 = &this->m_RunningSpawnTasksTmp[1];
    v32 = (ActionController *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
    v33 = 0;
    this->mUpdating = 1;
    this->m_ActionNodePlayTime = v30 + this->m_ActionNodePlayTime;
    if ( v32 != (ActionController *)&this->m_RunningSpawnTasksTmp[1] )
    {
      do
      {
        m_ActionNodePlayTime = v32->m_ActionNodePlayTime;
        v35 = (ActionController *)&v32->m_currentNode[-1].mChildren.mData;
        if ( m_ActionNodePlayTime < 0.0 || m_ActionNodePlayTime > this->m_ActionNodePlayTime )
        {
          v45 = v32->m_Context;
          if ( !BYTE6(v45->mSimObject.m_pPointer) || (v46 = *(float *)&v45->mDebugBreak >= 0.0, v47 = 1, !v46) )
            v47 = 0;
          v33 |= v47;
        }
        else
        {
          mResourceOwner = v32->mResourceOwner;
          v37 = v32->m_currentNode;
          mResourceOwner->mResourceOwner = v37;
          v37->vfptr = (Expression::IMemberMapVtbl *)mResourceOwner;
          v32->mResourceOwner = (Expression::IMemberMap *)&v32->mResourceOwner;
          v32->m_currentNode = (ActionNodePlayable *)&v32->mResourceOwner;
          mPrev = this->m_RunningTasks.mNode.mPrev;
          mPrev->mNext = (UFG::qNode<ITask,ITask> *)&v32->mResourceOwner;
          v32->mResourceOwner = (Expression::IMemberMap *)mPrev;
          v32->m_currentNode = (ActionNodePlayable *)&this->m_RunningTasks;
          this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)&v32->mResourceOwner;
          v39 = v32->m_Context;
          if ( BYTE6(v39->mSimObject.m_pPointer) )
          {
            v40 = v39->mActionController;
            if ( v40
              && (v41 = (char *)&v40->m_ActionNodePlayTime + (_QWORD)v39) != 0i64
              && ((*(void (__fastcall **)(char *, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v41 + 24i64))(
                    v41,
                    v78,
                    UEL::gCurrentParameters,
                    0i64,
                    UEL::gCurrentStringBuilder),
                  v79) )
            {
              if ( v79 == 4 )
                v42 = *(float *)v78;
              else
                v42 = (float)SLODWORD(v78[0]);
            }
            else
            {
              v42 = *(float *)&v39->mParentContext;
            }
            this->mRunningMasterRate = v42;
          }
          ((void (__fastcall *)(ActionController *, ActionContext *, ActionController *))v32->vfptr->__vecDelDtor)(
            v32,
            this->m_Context,
            v22);
          v43 = v32->m_Context;
          if ( v43 && LODWORD(v43->mSimObject.m_pPointer) == SpawnTrack::sClassNameUID )
          {
            v44 = this->m_RunningSpawnTasksTmp[0];
            *(_QWORD *)(v44 + 8) = &v32->m_OnEnterExitCallbacksEnabled;
            *(_QWORD *)&v32->m_OnEnterExitCallbacksEnabled = v44;
            v32->m_previousNode = (ActionNodePlayable *)this->m_RunningSpawnTasksTmp;
            this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)&v32->m_OnEnterExitCallbacksEnabled;
          }
        }
        v32 = v35;
      }
      while ( v35 != (ActionController *)&this->m_RunningSpawnTasksTmp[1] );
      v31 = &this->m_RunningSpawnTasksTmp[1];
    }
    ActionController::updateTasks(this, v30);
    v48 = &this->m_RunningTasks.mNode.mNext[-1].mNext;
    if ( v48 != (UFG::qNode<ITask,ITask> **)p_m_SequenceNode )
    {
      do
      {
        v49 = (__int64)&v48[2][-1].mNext;
        if ( BYTE6(v48[3][1].mPrev) )
          v17 = v48;
        v48 = &v48[2][-1].mNext;
      }
      while ( (ActionNodePlayable **)v49 != p_m_SequenceNode );
    }
    v50 = this->mOverRideNode == 0;
    this->mUpdating = 0;
    if ( !v50 || !v17 && !v33 )
    {
      if ( ActionController::sBreakOnEnd )
      {
        v51 = this->m_currentNode;
        if ( v51 )
        {
          if ( ActionNode::sEnableNodeBreakPoints
            && v51->mBreakPoint
            && this->m_Context->mDebugBreak
            && ActionNode::sSoftBreakPoints )
          {
            v52 = "masterTracksRunning:FALSE";
            if ( v17 )
              v52 = "masterTracksRunning:TRUE";
            ActionController::BreakPointMessageHandler(this, "ActionController::breakOnEnd", v52);
          }
        }
      }
      v53 = this->mKeepAlive != 0;
      ActionController::nodeCleanup(this);
      if ( *p_m_SequenceNode )
      {
        ActionController::Play(this, *p_m_SequenceNode);
        v54 = (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
        if ( v54 != v31 )
        {
          do
          {
            v55 = *((float *)v54 + 8);
            v56 = v54[2] - 8;
            if ( v55 >= 0.0 && v55 <= this->m_ActionNodePlayTime )
            {
              v57 = v54[1];
              v58 = (unsigned __int64 *)v54[2];
              *(_QWORD *)(v57 + 8) = v58;
              *v58 = v57;
              v54[1] = (unsigned __int64)(v54 + 1);
              v54[2] = (unsigned __int64)(v54 + 1);
              v59 = this->m_RunningTasks.mNode.mPrev;
              v59->mNext = (UFG::qNode<ITask,ITask> *)(v54 + 1);
              v54[1] = (unsigned __int64)v59;
              v54[2] = (unsigned __int64)&this->m_RunningTasks;
              this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v54 + 1);
              v60 = v54[3];
              if ( *(_BYTE *)(v60 + 22) )
              {
                v61 = *(_QWORD *)(v60 + 32);
                if ( v61
                  && (v62 = v60 + v61 + 32) != 0
                  && ((*(void (__fastcall **)(unsigned __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v62 + 24i64))(
                        v62,
                        v78,
                        UEL::gCurrentParameters,
                        0i64,
                        UEL::gCurrentStringBuilder),
                      v79) )
                {
                  if ( v79 == 4 )
                    v63 = *(float *)v78;
                  else
                    v63 = (float)SLODWORD(v78[0]);
                }
                else
                {
                  v63 = *(float *)(v60 + 40);
                }
                this->mRunningMasterRate = v63;
              }
              (*(void (__fastcall **)(unsigned __int64 *, ActionContext *))(*v54 + 8))(v54, this->m_Context);
              v64 = v54[3];
              if ( v64 && *(_DWORD *)(v64 + 16) == SpawnTrack::sClassNameUID )
              {
                v65 = this->m_RunningSpawnTasksTmp[0];
                *(_QWORD *)(v65 + 8) = v54 + 5;
                v54[5] = v65;
                v54[6] = (unsigned __int64)this->m_RunningSpawnTasksTmp;
                this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)(v54 + 5);
              }
            }
            v54 = (unsigned __int64 *)v56;
          }
          while ( (unsigned __int64 *)v56 != v31 );
        }
      }
      else if ( v53 )
      {
        ActionController::Play(this, (ActionNodePlayable *)this->m_Context->m_OpeningBranch, 0);
        v66 = (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
        if ( v66 != v31 )
        {
          do
          {
            v67 = *((float *)v66 + 8);
            v68 = v66[2] - 8;
            if ( v67 >= 0.0 && v67 <= this->m_ActionNodePlayTime )
            {
              v69 = v66[1];
              v70 = (unsigned __int64 *)v66[2];
              *(_QWORD *)(v69 + 8) = v70;
              *v70 = v69;
              v66[1] = (unsigned __int64)(v66 + 1);
              v66[2] = (unsigned __int64)(v66 + 1);
              v71 = this->m_RunningTasks.mNode.mPrev;
              v71->mNext = (UFG::qNode<ITask,ITask> *)(v66 + 1);
              v66[1] = (unsigned __int64)v71;
              v66[2] = (unsigned __int64)&this->m_RunningTasks;
              this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v66 + 1);
              v72 = v66[3];
              if ( *(_BYTE *)(v72 + 22) )
              {
                v73 = *(_QWORD *)(v72 + 32);
                if ( v73
                  && (v74 = v72 + v73 + 32) != 0
                  && ((*(void (__fastcall **)(unsigned __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v74 + 24i64))(
                        v74,
                        v78,
                        UEL::gCurrentParameters,
                        0i64,
                        UEL::gCurrentStringBuilder),
                      v79) )
                {
                  if ( v79 == 4 )
                    v75 = *(float *)v78;
                  else
                    v75 = (float)SLODWORD(v78[0]);
                }
                else
                {
                  v75 = *(float *)(v72 + 40);
                }
                this->mRunningMasterRate = v75;
              }
              (*(void (__fastcall **)(unsigned __int64 *, ActionContext *))(*v66 + 8))(v66, this->m_Context);
              v76 = v66[3];
              if ( v76 && *(_DWORD *)(v76 + 16) == SpawnTrack::sClassNameUID )
              {
                v77 = this->m_RunningSpawnTasksTmp[0];
                *(_QWORD *)(v77 + 8) = v66 + 5;
                v66[5] = v77;
                v66[6] = (unsigned __int64)this->m_RunningSpawnTasksTmp;
                this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)(v66 + 5);
              }
            }
            v66 = (unsigned __int64 *)v68;
          }
          while ( (unsigned __int64 *)v68 != v31 );
        }
      }
    }
  }
  else
  {
    ActionController::Play(this, (ActionNodePlayable *)this->m_Context->m_OpeningBranch, 0);
    v4 = (ActionController *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
    if ( v4 != (ActionController *)&this->m_RunningSpawnTasksTmp[1] )
    {
      do
      {
        v5 = v4->m_ActionNodePlayTime;
        v6 = (ActionController *)&v4->m_currentNode[-1].mChildren.mData;
        if ( v5 >= 0.0 && v5 <= this->m_ActionNodePlayTime )
        {
          v7 = v4->mResourceOwner;
          v8 = v4->m_currentNode;
          v7->mResourceOwner = v8;
          v8->vfptr = (Expression::IMemberMapVtbl *)v7;
          v4->mResourceOwner = (Expression::IMemberMap *)&v4->mResourceOwner;
          v4->m_currentNode = (ActionNodePlayable *)&v4->mResourceOwner;
          v9 = this->m_RunningTasks.mNode.mPrev;
          v9->mNext = (UFG::qNode<ITask,ITask> *)&v4->mResourceOwner;
          v4->mResourceOwner = (Expression::IMemberMap *)v9;
          v4->m_currentNode = (ActionNodePlayable *)&this->m_RunningTasks;
          this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)&v4->mResourceOwner;
          v10 = v4->m_Context;
          if ( BYTE6(v10->mSimObject.m_pPointer) )
          {
            v11 = v10->mActionController;
            if ( v11
              && (v12 = (char *)&v11->m_ActionNodePlayTime + (_QWORD)v10) != 0i64
              && ((*(void (__fastcall **)(char *, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v12 + 24i64))(
                    v12,
                    v78,
                    UEL::gCurrentParameters,
                    0i64,
                    UEL::gCurrentStringBuilder),
                  v79) )
            {
              if ( v79 == 4 )
                v13 = *(float *)v78;
              else
                v13 = (float)SLODWORD(v78[0]);
            }
            else
            {
              v13 = *(float *)&v10->mParentContext;
            }
            this->mRunningMasterRate = v13;
          }
          v4->vfptr->__vecDelDtor(v4, (unsigned int)this->m_Context);
          v14 = v4->m_Context;
          if ( v14 )
          {
            if ( LODWORD(v14->mSimObject.m_pPointer) == SpawnTrack::sClassNameUID )
            {
              v15 = this->m_RunningSpawnTasksTmp[0];
              *(_QWORD *)(v15 + 8) = &v4->m_OnEnterExitCallbacksEnabled;
              *(_QWORD *)&v4->m_OnEnterExitCallbacksEnabled = v15;
              v4->m_previousNode = (ActionNodePlayable *)this->m_RunningSpawnTasksTmp;
              this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)&v4->m_OnEnterExitCallbacksEnabled;
            }
          }
        }
        v4 = v6;
      }
      while ( v6 != (ActionController *)&this->m_RunningSpawnTasksTmp[1] );
    }
  }
}

// File Line: 933
// RVA: 0x275E20
__int64 __fastcall ActionController::updateTasksTimeBegin(ActionController *this, float timeDelta, bool nodeEnd)
{
  unsigned __int64 *v3; // r12
  unsigned __int8 v4; // r15
  ActionController *p_mNext; // rbx
  float m_ActionNodePlayTime; // xmm0_4
  __int64 p_mData; // rbp
  Expression::IMemberMap *mResourceOwner; // rcx
  ActionNodePlayable *m_currentNode; // rax
  UFG::qNode<ITask,ITask> *mPrev; // rax
  ActionContext *m_Context; // rdi
  ActionController *mActionController; // rax
  char *v15; // rcx
  float v16; // xmm0_4
  ActionContext *v17; // rcx
  unsigned __int64 v18; // rax
  ActionContext *v19; // rax
  char v20; // al
  __int64 v22; // [rsp+30h] [rbp-58h] BYREF
  __int16 v23; // [rsp+44h] [rbp-44h]

  v3 = &this->m_RunningSpawnTasksTmp[1];
  v4 = 0;
  p_mNext = (ActionController *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
  if ( p_mNext != (ActionController *)&this->m_RunningSpawnTasksTmp[1] )
  {
    do
    {
      m_ActionNodePlayTime = p_mNext->m_ActionNodePlayTime;
      p_mData = (__int64)&p_mNext->m_currentNode[-1].mChildren.mData;
      if ( nodeEnd )
      {
        if ( m_ActionNodePlayTime < 0.0 )
          goto LABEL_7;
      }
      else if ( m_ActionNodePlayTime >= 0.0 && m_ActionNodePlayTime <= this->m_ActionNodePlayTime )
      {
LABEL_7:
        mResourceOwner = p_mNext->mResourceOwner;
        m_currentNode = p_mNext->m_currentNode;
        mResourceOwner->mResourceOwner = m_currentNode;
        m_currentNode->vfptr = (Expression::IMemberMapVtbl *)mResourceOwner;
        mPrev = this->m_RunningTasks.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<ITask,ITask> *)&p_mNext->mResourceOwner;
        p_mNext->mResourceOwner = (Expression::IMemberMap *)mPrev;
        p_mNext->m_currentNode = (ActionNodePlayable *)&this->m_RunningTasks;
        m_Context = p_mNext->m_Context;
        this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)&p_mNext->mResourceOwner;
        if ( BYTE6(m_Context->mSimObject.m_pPointer) )
        {
          mActionController = m_Context->mActionController;
          if ( mActionController
            && (v15 = (char *)&m_Context->mActionController + (_QWORD)mActionController) != 0i64
            && ((*(void (__fastcall **)(char *, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v15 + 24i64))(
                  v15,
                  &v22,
                  UEL::gCurrentParameters,
                  0i64,
                  UEL::gCurrentStringBuilder),
                v23) )
          {
            if ( v23 == 4 )
              v16 = *(float *)&v22;
            else
              v16 = (float)(int)v22;
          }
          else
          {
            v16 = *(float *)&m_Context->mParentContext;
          }
          this->mRunningMasterRate = v16;
        }
        p_mNext->vfptr->__vecDelDtor(p_mNext, (unsigned int)this->m_Context);
        v17 = p_mNext->m_Context;
        if ( v17 && LODWORD(v17->mSimObject.m_pPointer) == SpawnTrack::sClassNameUID )
        {
          v18 = this->m_RunningSpawnTasksTmp[0];
          *(_QWORD *)(v18 + 8) = &p_mNext->m_OnEnterExitCallbacksEnabled;
          this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)&p_mNext->m_OnEnterExitCallbacksEnabled;
          *(_QWORD *)&p_mNext->m_OnEnterExitCallbacksEnabled = v18;
          p_mNext->m_previousNode = (ActionNodePlayable *)this->m_RunningSpawnTasksTmp;
        }
        if ( nodeEnd )
          p_mNext->vfptr->CreateClone(p_mNext);
        goto LABEL_26;
      }
      v19 = p_mNext->m_Context;
      if ( BYTE6(v19->mSimObject.m_pPointer) )
      {
        if ( nodeEnd )
        {
          if ( *(float *)&v19->mDebugBreak < 0.0 )
          {
LABEL_29:
            v20 = 1;
            goto LABEL_25;
          }
        }
        else if ( *(float *)&v19->mDebugBreak >= 0.0 )
        {
          goto LABEL_29;
        }
      }
      v20 = 0;
LABEL_25:
      v4 |= v20;
LABEL_26:
      p_mNext = (ActionController *)p_mData;
    }
    while ( (unsigned __int64 *)p_mData != v3 );
  }
  return v4;
}xt = (ActionController *)p_mData;
    }
    while

// File Line: 1049
// RVA: 0x275D30
void __fastcall ActionController::updateTasks(ActionController *this, float timeDelta)
{
  ActionNodePlayable **p_m_SequenceNode; // rbp
  ActionController *p_mNext; // rbx
  float v5; // xmm6_4
  __int64 p_mData; // rdi
  Expression::IMemberMap *mResourceOwner; // rdx
  ActionNodePlayable *m_currentNode; // rax
  ActionController *v9; // rcx
  ActionController *v10; // rbx

  p_m_SequenceNode = &this->m_SequenceNode;
  p_mNext = (ActionController *)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  if ( p_mNext != (ActionController *)&this->m_SequenceNode )
  {
    do
    {
      v5 = *(float *)&p_mNext->mUpdating;
      p_mData = (__int64)&p_mNext->m_currentNode[-1].mChildren.mData;
      if ( !p_mNext->vfptr->CreateClone(p_mNext) || v5 >= 0.0 && v5 <= this->m_ActionNodePlayTime )
      {
        ((void (__fastcall *)(ActionController *))p_mNext->vfptr->Serialize)(p_mNext);
        mResourceOwner = p_mNext->mResourceOwner;
        m_currentNode = p_mNext->m_currentNode;
        mResourceOwner->mResourceOwner = m_currentNode;
        m_currentNode->vfptr = (Expression::IMemberMapVtbl *)mResourceOwner;
        p_mNext->mResourceOwner = (Expression::IMemberMap *)&p_mNext->mResourceOwner;
        p_mNext->m_currentNode = (ActionNodePlayable *)&p_mNext->mResourceOwner;
        p_mNext->vfptr->FindWithOldPath(p_mNext, (const char *)1);
      }
      p_mNext = (ActionController *)p_mData;
    }
    while ( (ActionNodePlayable **)p_mData != p_m_SequenceNode );
  }
  v9 = (ActionController *)&this->m_FinishUpdateTasks.mNode.mNext[-1].mNext;
  if ( v9 != (ActionController *)&this->mRunningMasterRate )
  {
    do
    {
      v10 = (ActionController *)&v9->m_currentNode[-1].mChildren.mData;
      ((void (__fastcall *)(ActionController *))v9->vfptr->FindWithOldPath)(v9);
      v9 = v10;
    }
    while ( v10 != (ActionController *)&this->mRunningMasterRate );
  }
}

// File Line: 1138
// RVA: 0x273E10
void __fastcall ActionController::clearSequencedTasks(ActionController *this)
{
  UFG::qNode<ITask,ITask> *v1; // rdi
  UFG::qNode<ITask,ITask> **p_mNext; // rcx
  UFG::qNode<ITask,ITask> *mPrev; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->m_RunningSpawnTasksTmp[1];
  if ( (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext != &this->m_RunningSpawnTasksTmp[1] )
  {
    do
    {
      p_mNext = &this->m_SequencedTasks.mNode.mNext[-1].mNext;
      mPrev = this->m_SequencedTasks.mNode.mNext->mPrev;
      v5 = p_mNext[2];
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      p_mNext[1] = (UFG::qNode<ITask,ITask> *)(p_mNext + 1);
      p_mNext[2] = (UFG::qNode<ITask,ITask> *)(p_mNext + 1);
      ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, __int64))(*p_mNext)->mPrev)(p_mNext, 1i64);
    }
    while ( (UFG::qNode<ITask,ITask> *)((char *)this->m_SequencedTasks.mNode.mNext - 8) != v1 );
  }
}

// File Line: 1148
// RVA: 0x273C70
void __fastcall ActionController::allTasksTimeEnd(ActionController *this)
{
  ActionNodePlayable **p_m_SequenceNode; // rsi
  UFG::qNode<ITask,ITask> *mNext; // rbx
  UFG::qNode<ITask,ITask> *mPrev; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax

  p_m_SequenceNode = &this->m_SequenceNode;
  while ( (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext != p_m_SequenceNode )
  {
    mNext = this->m_RunningTasks.mNode.mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **))mNext[-1].mNext[1].mNext)(&mNext[-1].mNext);
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, __int64))mNext[-1].mNext->mPrev)(&mNext[-1].mNext, 1i64);
  }
}

// File Line: 1188
// RVA: 0x2755C0
void __fastcall ActionController::nodeCleanup(ActionController *this)
{
  ActionNodePlayable *m_currentNode; // rdi
  ConditionCallback *mFirstCallback; // rbx
  ActionContext *i; // rbp
  ActionNodePlayable *v5; // rdx
  ActionNode *m_OpeningBranch; // rcx
  __int64 mOffset; // rax
  UFG::qOffset64<ActionNode *> *p_mParent; // rdx
  __int64 v9; // rax
  UFG::qOffset64<ActionNode *> *v10; // rcx
  bool v11; // zf
  __int64 v12; // rax
  UFG::qOffset64<ActionNode *> *v13; // rdi
  ActionController *p_mNext; // rbx
  ActionController *p_mData; // rbp
  Expression::IMemberMap *mResourceOwner; // rcx
  ActionNodePlayable *v17; // rax
  UFG::qNode<ITask,ITask> *mPrev; // rax
  ActionContext *m_Context; // rdi
  ActionController *mActionController; // rax
  char *v21; // rcx
  float v22; // xmm0_4
  ActionContext *v23; // rcx
  unsigned __int64 v24; // rax
  ActionNodePlayable *v25; // rax
  __int64 v26; // rcx
  ActionNodePlayable *v27; // rdx
  __int64 mMostUsedIndex; // rcx
  ActionContext *j; // rax
  __int64 v30; // [rsp+30h] [rbp-48h] BYREF
  __int16 v31; // [rsp+44h] [rbp-34h]

  m_currentNode = this->m_currentNode;
  this->mUpdating = 1;
  if ( m_currentNode )
    this->m_previousNode = m_currentNode;
  if ( this->m_OnEnterExitCallbacksEnabled && m_currentNode )
  {
    do
    {
      mFirstCallback = m_currentNode->mFirstCallback;
      for ( i = this->m_Context; mFirstCallback; mFirstCallback = mFirstCallback->mNextCallback )
      {
        if ( mFirstCallback->mType == ON_EXIT )
          ((void (__fastcall *)(fastdelegate::detail::GenericClass *, ActionNodePlayable *, ActionContext *))mFirstCallback->m_CallbackDelegate.m_Closure.m_pFunction)(
            mFirstCallback->m_CallbackDelegate.m_Closure.m_pthis,
            m_currentNode,
            i);
      }
      v5 = m_currentNode;
      m_OpeningBranch = this->m_Context->m_OpeningBranch;
      if ( m_currentNode == m_OpeningBranch )
        break;
      while ( m_OpeningBranch )
      {
        if ( v5->mID.mUID != m_OpeningBranch->mID.mUID )
          goto LABEL_22;
        mOffset = v5->mParent.mOffset;
        p_mParent = &v5->mParent;
        if ( mOffset )
          v5 = (ActionNodePlayable *)((char *)p_mParent + mOffset);
        else
          v5 = 0i64;
        v9 = m_OpeningBranch->mParent.mOffset;
        v10 = &m_OpeningBranch->mParent;
        if ( v9 )
          m_OpeningBranch = (ActionNode *)((char *)v10 + v9);
        else
          m_OpeningBranch = 0i64;
        if ( !v5 )
        {
          v11 = m_OpeningBranch == 0i64;
          goto LABEL_21;
        }
      }
      v11 = v5 == 0i64;
LABEL_21:
      if ( v11 )
        break;
LABEL_22:
      v12 = m_currentNode->mParent.mOffset;
      v13 = &m_currentNode->mParent;
      if ( !v12 )
        break;
      m_currentNode = (ActionNodePlayable *)((char *)v13 + v12);
    }
    while ( m_currentNode );
  }
  p_mNext = (ActionController *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
  if ( p_mNext != (ActionController *)&this->m_RunningSpawnTasksTmp[1] )
  {
    do
    {
      p_mData = (ActionController *)&p_mNext->m_currentNode[-1].mChildren.mData;
      if ( p_mNext->m_ActionNodePlayTime < 0.0 )
      {
        mResourceOwner = p_mNext->mResourceOwner;
        v17 = p_mNext->m_currentNode;
        mResourceOwner->mResourceOwner = v17;
        v17->vfptr = (Expression::IMemberMapVtbl *)mResourceOwner;
        p_mNext->mResourceOwner = (Expression::IMemberMap *)&p_mNext->mResourceOwner;
        p_mNext->m_currentNode = (ActionNodePlayable *)&p_mNext->mResourceOwner;
        mPrev = this->m_RunningTasks.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<ITask,ITask> *)&p_mNext->mResourceOwner;
        p_mNext->mResourceOwner = (Expression::IMemberMap *)mPrev;
        p_mNext->m_currentNode = (ActionNodePlayable *)&this->m_RunningTasks;
        this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)&p_mNext->mResourceOwner;
        m_Context = p_mNext->m_Context;
        if ( BYTE6(m_Context->mSimObject.m_pPointer) )
        {
          mActionController = m_Context->mActionController;
          if ( mActionController
            && (v21 = (char *)&m_Context->mActionController + (_QWORD)mActionController) != 0i64
            && ((*(void (__fastcall **)(char *, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v21 + 24i64))(
                  v21,
                  &v30,
                  UEL::gCurrentParameters,
                  0i64,
                  UEL::gCurrentStringBuilder),
                v31) )
          {
            if ( v31 == 4 )
              v22 = *(float *)&v30;
            else
              v22 = (float)(int)v30;
          }
          else
          {
            v22 = *(float *)&m_Context->mParentContext;
          }
          this->mRunningMasterRate = v22;
        }
        p_mNext->vfptr->__vecDelDtor(p_mNext, (unsigned int)this->m_Context);
        v23 = p_mNext->m_Context;
        if ( v23 && LODWORD(v23->mSimObject.m_pPointer) == SpawnTrack::sClassNameUID )
        {
          v24 = this->m_RunningSpawnTasksTmp[0];
          *(_QWORD *)(v24 + 8) = &p_mNext->m_OnEnterExitCallbacksEnabled;
          *(_QWORD *)&p_mNext->m_OnEnterExitCallbacksEnabled = v24;
          p_mNext->m_previousNode = (ActionNodePlayable *)this->m_RunningSpawnTasksTmp;
          this->m_RunningSpawnTasksTmp[0] = (unsigned __int64)&p_mNext->m_OnEnterExitCallbacksEnabled;
        }
        p_mNext->vfptr->CreateClone(p_mNext);
      }
      p_mNext = p_mData;
    }
    while ( p_mData != (ActionController *)&this->m_RunningSpawnTasksTmp[1] );
  }
  ActionController::allTasksTimeEnd(this);
  ActionController::clearSequencedTasks(this);
  v25 = this->m_currentNode;
  if ( v25 )
  {
    while ( 1 )
    {
      v26 = v25->mParent.mOffset;
      if ( !v26 )
        break;
      v27 = (ActionNodePlayable *)((char *)&v25->mParent + v26);
      if ( !v27 )
        break;
      mMostUsedIndex = v25->mMostUsedIndex;
      if ( (_DWORD)mMostUsedIndex != -1 )
      {
        for ( j = this->m_Context; j; j = j->mParentContext )
          --j->mMostUsedPlayCount[mMostUsedIndex];
      }
      v25 = v27;
    }
  }
  this->m_currentNode = 0i64;
  this->m_NumPlayingNodes = 0;
  this->m_PlayingMostUsedMask = 0i64;
  this->mOverRideNode = 0;
  this->m_ActionNodePlayTime = 0.0;
  this->mUpdating = 0;
  this->m_SequencePriority = -1;
}

// File Line: 1269
// RVA: 0x26F310
char __fastcall ActionController::IsPlaying(ActionController *this, ActionNodePlayable *node)
{
  ActionNodePlayable *m_currentNode; // rax
  __int64 mOffset; // rcx

  m_currentNode = this->m_currentNode;
  if ( m_currentNode )
  {
    while ( 1 )
    {
      mOffset = m_currentNode->mParent.mOffset;
      if ( !mOffset || !(UFG::qOffset64<ActionNode *> *)((char *)&m_currentNode->mParent + mOffset) )
        break;
      if ( node == m_currentNode )
        return 1;
      m_currentNode = (ActionNodePlayable *)((char *)m_currentNode + mOffset + 16);
    }
  }
  return 0;
}

// File Line: 1297
// RVA: 0x1488310
__int64 dynamic_initializer_for__gPlayEntries__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPlayEntries__);
}

// File Line: 1368
// RVA: 0x26F170
unsigned __int8 __fastcall ActionController::IsPlaying(
        ActionController *this,
        ActionID *node_id,
        unsigned int mostUsedIndex,
        const bool recurseOnSpawns)
{
  unsigned int mUID; // ebx
  unsigned __int64 m_PlayingMostUsedMask; // rax
  unsigned int m_NumPlayingNodes; // edx
  unsigned int v9; // ecx
  ActionID *m_PlayingNodeUID; // rax
  char *p_m_OnEnterExitCallbacksEnabled; // r11
  ActionController *p_mPad2; // rdx
  unsigned int v13; // esi
  unsigned int v14; // edi
  Expression::IMemberMap **p_mResourceOwner; // r9
  char *p_m_previousNode; // r10
  __int64 p_mNext; // rcx
  __int64 v18; // r8
  __int64 v19; // rax
  __int64 v20; // rax
  unsigned int v21; // r8d
  unsigned int v22; // ecx
  _DWORD *v23; // rax
  __m128i v24[32]; // [rsp+0h] [rbp-208h]

  mUID = node_id->mUID;
  if ( mostUsedIndex == -1 )
  {
    m_NumPlayingNodes = this->m_NumPlayingNodes;
    v9 = 0;
    if ( m_NumPlayingNodes )
    {
      m_PlayingNodeUID = this->m_PlayingNodeUID;
      while ( m_PlayingNodeUID->mUID != mUID )
      {
        ++v9;
        ++m_PlayingNodeUID;
        if ( v9 >= m_NumPlayingNodes )
          goto LABEL_9;
      }
      return 1;
    }
    else
    {
LABEL_9:
      if ( !recurseOnSpawns )
        return 0;
      p_m_OnEnterExitCallbacksEnabled = &this->m_OnEnterExitCallbacksEnabled;
      p_mPad2 = (ActionController *)(this->m_RunningSpawnTasksTmp[1] - 40);
      if ( p_mPad2 == (ActionController *)&this->m_OnEnterExitCallbacksEnabled )
      {
        return 0;
      }
      else
      {
        v13 = 1;
        v24[0] = 0i64;
        if ( p_mPad2 )
        {
          v14 = 0;
          while ( 1 )
          {
            p_mResourceOwner = &p_mPad2[1].mResourceOwner;
            p_m_previousNode = (char *)&p_mPad2[1].m_previousNode;
            p_mNext = (__int64)&p_mPad2[1].m_SequencedTasks.mNode.mPrev[-3].mNext;
            if ( (ActionNodePlayable **)p_mNext == &p_mPad2[1].m_previousNode )
            {
              p_mPad2 = (ActionController *)&p_mPad2->m_previousNode[-1].mPad2;
              if ( p_mPad2 == (ActionController *)p_m_OnEnterExitCallbacksEnabled )
              {
                --v13;
                v20 = v14--;
                p_mPad2 = (ActionController *)v24[v20].m128i_i64[0];
                p_m_OnEnterExitCallbacksEnabled = (char *)v24[v20].m128i_i64[1];
              }
            }
            else
            {
              v18 = (__int64)&p_mPad2->m_previousNode[-1].mPad2;
              if ( (char *)v18 != p_m_OnEnterExitCallbacksEnabled )
              {
                v19 = v13++;
                v19 *= 16i64;
                ++v14;
                *(__int64 *)((char *)v24[0].m128i_i64 + v19) = v18;
                *(__int64 *)((char *)&v24[0].m128i_i64[1] + v19) = (__int64)p_m_OnEnterExitCallbacksEnabled;
              }
              p_mPad2 = (ActionController *)p_mNext;
              p_m_OnEnterExitCallbacksEnabled = p_m_previousNode;
            }
            v21 = *((_DWORD *)p_mResourceOwner + 36);
            v22 = 0;
            if ( v21 )
              break;
LABEL_24:
            if ( !p_mPad2 )
              return 0;
          }
          v23 = (_DWORD *)p_mResourceOwner + 37;
          while ( *v23 != mUID )
          {
            ++v22;
            ++v23;
            if ( v22 >= v21 )
              goto LABEL_24;
          }
          return 1;
        }
        else
        {
          return 0;
        }
      }
    }
  }
  else if ( recurseOnSpawns )
  {
    return this->m_Context->mMostUsedPlayCount[mostUsedIndex] != 0;
  }
  else
  {
    m_PlayingMostUsedMask = this->m_PlayingMostUsedMask;
    return _bittest64((const __int64 *)&m_PlayingMostUsedMask, mostUsedIndex);
  }
}

// File Line: 1615
// RVA: 0x26F400
char __fastcall ActionController::IsPlayingFullPath(
        ActionController *this,
        ActionNodePlayable *testNode,
        const bool recurseOnSpawns)
{
  ActionNodePlayable *m_currentNode; // rax
  unsigned int mMostUsedIndex; // ebp
  unsigned int v6; // edi
  __int64 v7; // r14
  unsigned int v8; // esi
  __int64 mOffset; // rcx
  char *p_m_OnEnterExitCallbacksEnabled; // rbx
  ActionController *p_mPad2; // r9
  Expression::IMemberMap **p_mResourceOwner; // r10
  char *p_m_previousNode; // r11
  __int64 p_mNext; // rcx
  __int64 v16; // r8
  __int64 v17; // rax
  __int64 v18; // rax
  ActionNode *v19; // rax
  __int64 v20; // rcx
  __int128 v21[32]; // [rsp+0h] [rbp-208h]

  m_currentNode = this->m_currentNode;
  if ( testNode )
    mMostUsedIndex = testNode->mMostUsedIndex;
  else
    mMostUsedIndex = -1;
  v6 = 0;
  v7 = 0i64;
  v8 = 1;
  if ( mMostUsedIndex == -1
    || (v7 = 1i64 << mMostUsedIndex, ((1i64 << mMostUsedIndex) & this->m_PlayingMostUsedMask) != 0) )
  {
    if ( m_currentNode )
    {
      while ( 1 )
      {
        mOffset = m_currentNode->mParent.mOffset;
        if ( !mOffset || !(UFG::qOffset64<ActionNode *> *)((char *)&m_currentNode->mParent + mOffset) )
          break;
        if ( (unsigned int)testNode >= (unsigned int)m_currentNode )
        {
          if ( testNode == m_currentNode )
            return 1;
          if ( (unsigned int)testNode > (unsigned int)m_currentNode )
            break;
        }
        m_currentNode = (ActionNodePlayable *)((char *)m_currentNode + mOffset + 16);
      }
    }
  }
  if ( !recurseOnSpawns )
    return 0;
  p_m_OnEnterExitCallbacksEnabled = &this->m_OnEnterExitCallbacksEnabled;
  p_mPad2 = (ActionController *)(this->m_RunningSpawnTasksTmp[1] - 40);
  if ( p_mPad2 != (ActionController *)&this->m_OnEnterExitCallbacksEnabled )
  {
    v21[0] = 0i64;
    while ( p_mPad2 )
    {
      p_mResourceOwner = &p_mPad2[1].mResourceOwner;
      p_m_previousNode = (char *)&p_mPad2[1].m_previousNode;
      p_mNext = (__int64)&p_mPad2[1].m_SequencedTasks.mNode.mPrev[-3].mNext;
      if ( (ActionNodePlayable **)p_mNext == &p_mPad2[1].m_previousNode )
      {
        p_mPad2 = (ActionController *)&p_mPad2->m_previousNode[-1].mPad2;
        if ( p_mPad2 == (ActionController *)p_m_OnEnterExitCallbacksEnabled )
        {
          --v8;
          v18 = v6--;
          p_mPad2 = *(ActionController **)&v21[v18];
          p_m_OnEnterExitCallbacksEnabled = (char *)*((_QWORD *)&v21[v18] + 1);
        }
      }
      else
      {
        v16 = (__int64)&p_mPad2->m_previousNode[-1].mPad2;
        if ( (char *)v16 != p_m_OnEnterExitCallbacksEnabled )
        {
          v17 = v8++;
          v17 *= 16i64;
          ++v6;
          *(_QWORD *)((char *)v21 + v17) = v16;
          *(_QWORD *)((char *)v21 + v17 + 8) = p_m_OnEnterExitCallbacksEnabled;
        }
        p_mPad2 = (ActionController *)p_mNext;
        p_m_OnEnterExitCallbacksEnabled = p_m_previousNode;
      }
      if ( mMostUsedIndex == -1 || (v7 & (unsigned __int64)p_mResourceOwner[17]) != 0 )
      {
        v19 = (ActionNode *)p_mResourceOwner[2];
        if ( v19 )
        {
          while ( 1 )
          {
            v20 = v19->mParent.mOffset;
            if ( !v20 || !(UFG::qOffset64<ActionNode *> *)((char *)&v19->mParent + v20) )
              break;
            if ( (unsigned int)testNode >= (unsigned int)v19 )
            {
              if ( testNode == v19 )
                return 1;
              if ( (unsigned int)testNode > (unsigned int)v19 )
                break;
            }
            v19 = (ActionNode *)((char *)v19 + v20 + 16);
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 1790
// RVA: 0x26F350
bool __fastcall ActionController::IsPlayingFullPath(ActionController *this, ActionPath *animPath, bool recurseOnSpawns)
{
  ActionNode *v4; // rcx
  unsigned int v5; // ebx
  unsigned int v8; // edi
  __int64 v9; // rsi
  __int64 mOffset; // rax
  char *v11; // rdx
  int v13; // [rsp+48h] [rbp+10h] BYREF

  v4 = 0i64;
  v5 = animPath->mPath.mCount & 0x7FFFFFFF;
  if ( v5 > 1 )
  {
    v4 = ActionNode::smRoot;
    v8 = 1;
    v9 = 4i64;
    do
    {
      if ( !v4 )
        break;
      mOffset = animPath->mPath.mData.mOffset;
      v11 = mOffset ? (char *)&animPath->mPath.mData + mOffset : 0i64;
      v13 = *(_DWORD *)&v11[v9];
      ++v8;
      v9 += 4i64;
      v4 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v4->vfptr[1].CreateClone)(v4, &v13, 0i64);
    }
    while ( v8 < v5 );
  }
  return ActionController::IsPlayingFullPath(this, v4, recurseOnSpawns);
}

// File Line: 1796
// RVA: 0x26F130
ActionNodePlayable **__fastcall ActionController::IsPlaying(ActionController *this, ITrack *track)
{
  ActionNodePlayable **p_m_SequenceNode; // r9
  ActionNodePlayable **p_mNext; // r8
  bool i; // zf
  ITrack *v5; // rcx
  __int64 p_mData; // rax

  p_m_SequenceNode = &this->m_SequenceNode;
  p_mNext = (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = p_mNext == &this->m_SequenceNode; !i; i = p_mData == (_QWORD)p_m_SequenceNode )
  {
    v5 = (ITrack *)p_mNext[3];
    p_mData = (__int64)&p_mNext[2][-1].mChildren.mData;
    if ( v5 && track == v5 )
      return p_mNext;
    p_mNext = (ActionNodePlayable **)&p_mNext[2][-1].mChildren.mData;
  }
  return 0i64;
}

// File Line: 1813
// RVA: 0x273AB0
char __fastcall ActionController::WasPlaying(ActionController *this, ActionID *animID, bool recurseOnSpawns)
{
  ActionNodePlayable *m_previousNode; // rax
  __int64 mOffset; // rcx
  UFG::qOffset64<ActionNode *> *p_mParent; // rax
  unsigned __int64 v10; // rcx
  char *p_m_OnEnterExitCallbacksEnabled; // rdi
  __int64 v12; // rcx
  __int64 v13; // rbx

  if ( this->m_ActionNodePlayTime == 0.0 && (m_previousNode = this->m_previousNode) != 0i64 )
  {
    while ( m_previousNode->mID.mUID != animID->mUID )
    {
      mOffset = m_previousNode->mParent.mOffset;
      p_mParent = &m_previousNode->mParent;
      if ( mOffset )
      {
        m_previousNode = (ActionNodePlayable *)((char *)p_mParent + mOffset);
        if ( m_previousNode )
          continue;
      }
      goto LABEL_6;
    }
    return 1;
  }
  else
  {
LABEL_6:
    if ( recurseOnSpawns )
    {
      v10 = this->m_RunningSpawnTasksTmp[1];
      p_m_OnEnterExitCallbacksEnabled = &this->m_OnEnterExitCallbacksEnabled;
      v12 = v10 - 40;
      if ( (char *)v12 == p_m_OnEnterExitCallbacksEnabled )
      {
        return 0;
      }
      else
      {
        while ( 1 )
        {
          v13 = *(_QWORD *)(v12 + 48) - 40i64;
          if ( ActionController::WasPlaying((ActionController *)(v12 + 288), animID, recurseOnSpawns) )
            break;
          v12 = v13;
          if ( (char *)v13 == p_m_OnEnterExitCallbacksEnabled )
            return 0;
        }
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 1857
// RVA: 0x273B90
char __fastcall ActionController::WasPlayingFullPath(ActionController *this, ActionNodePlayable *testNode)
{
  ActionNodePlayable *m_previousNode; // rax
  __int64 mOffset; // rcx

  if ( this->m_ActionNodePlayTime == 0.0 )
  {
    m_previousNode = this->m_previousNode;
    if ( m_previousNode )
    {
      while ( 1 )
      {
        mOffset = m_previousNode->mParent.mOffset;
        if ( !mOffset || !(UFG::qOffset64<ActionNode *> *)((char *)&m_previousNode->mParent + mOffset) )
          break;
        if ( (unsigned int)testNode >= (unsigned int)m_previousNode )
        {
          if ( testNode == m_previousNode )
            return 1;
          if ( (unsigned int)testNode > (unsigned int)m_previousNode )
            return 0;
        }
        m_previousNode = (ActionNodePlayable *)((char *)m_previousNode + mOffset + 16);
      }
    }
  }
  return 0;
}

// File Line: 2079
// RVA: 0x26E5B0
void __fastcall ActionController::GetDebugString(
        ActionController *this,
        UFG::qStringBuilder *debugStringBuilder,
        const bool bShowAllTracks,
        ActionController *pControllerToHighlight,
        ITrack *pTrackToHighlight)
{
  bool v5; // r8

  v5 = bShowAllTracks || gReflectAllActionTreeTasks;
  ActionController::writeDebugDisplayToString(
    this,
    debugStringBuilder,
    v5,
    pControllerToHighlight,
    pTrackToHighlight,
    0,
    0i64);
}

// File Line: 2120
// RVA: 0x275FF0
void __fastcall ActionController::writeDebugDisplayToString(
        ActionController *this,
        UFG::qStringBuilder *debugStringBuilder,
        bool bShowAllTracks,
        ActionController *pControllerToHighlight,
        ITrack *pTrackToHighlight,
        unsigned int indentSpaces,
        ITask *pParentTask)
{
  bool v7; // bl
  ActionNodePlayable *m_currentNode; // rcx
  unsigned int v11; // ebp
  float mRunningMasterRate; // xmm6_4
  char *String_DBG; // rax
  unsigned int v14; // ebx
  const char *v15; // rdx
  UFG::qNode<ITask,ITask> **p_mNext; // rbx
  ITrack *v17; // rdi
  bool v18; // bp
  bool v19; // si
  UFG::qStringBuilder *v20; // rdi
  int mLength; // [rsp+40h] [rbp-88h]
  ActionPath pathToPopulate; // [rsp+50h] [rbp-78h] BYREF
  UFG::qString v23; // [rsp+60h] [rbp-68h] BYREF
  bool v24; // [rsp+D0h] [rbp+8h]
  ActionNodePlayable **i; // [rsp+D0h] [rbp+8h]

  v7 = bShowAllTracks;
  v24 = this == pControllerToHighlight;
  mLength = 0;
  if ( this == pControllerToHighlight )
  {
    UFG::qString::qString(&v23, "=>");
    UFG::qStringBuilder::Add(debugStringBuilder, v23.mData, -1);
    mLength = v23.mLength;
    UFG::qString::~qString(&v23);
  }
  pathToPopulate.mPath.mCount = 0;
  pathToPopulate.mPath.mData.mOffset = 0i64;
  if ( pParentTask
    && InvokeBehaviourTrack::sClassNameUID == pParentTask->m_Track->vfptr->GetClassNameUID(pParentTask->m_Track) )
  {
    v11 = indentSpaces;
  }
  else
  {
    m_currentNode = this->m_currentNode;
    if ( !m_currentNode )
    {
      UFG::qStringBuilder::Format(
        debugStringBuilder,
        "%*s%s:%0.3f@%0.3f\n",
        indentSpaces,
        &customCaption,
        "NULL",
        this->m_ActionNodePlayTime,
        this->mRunningMasterRate);
      goto LABEL_30;
    }
    ActionNode::GetNameFullPath(m_currentNode, &pathToPopulate);
    v11 = indentSpaces;
    mRunningMasterRate = this->mRunningMasterRate;
    String_DBG = ActionPath::GetString_DBG(&pathToPopulate);
    v14 = indentSpaces - mLength;
    if ( (int)(indentSpaces - mLength) < 0 )
      v14 = 0;
    UFG::qStringBuilder::Format(
      debugStringBuilder,
      "%*s%s:%0.3f@%0.3f",
      v14,
      &customCaption,
      String_DBG,
      this->m_ActionNodePlayTime,
      mRunningMasterRate);
    v7 = bShowAllTracks;
  }
  v15 = " <=\n";
  if ( !v24 )
    v15 = "\n";
  UFG::qStringBuilder::Add(debugStringBuilder, v15, -1);
  if ( v7 )
    indentSpaces = sSpacesPerTrackIndent + v11;
  p_mNext = &this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = &this->m_SequenceNode; p_mNext != (UFG::qNode<ITask,ITask> **)i; p_mNext = &p_mNext[2][-1].mNext )
  {
    v17 = (ITrack *)p_mNext[3];
    v18 = InvokeBehaviourTrack::sClassNameUID == v17->vfptr->GetClassNameUID(v17);
    v19 = SpawnTrack::sClassNameUID == v17->vfptr->GetClassNameUID(v17) || v18;
    v17->vfptr->GetClassNameUID(v17);
    if ( v19 || bShowAllTracks )
    {
      if ( v18 || v17 != pTrackToHighlight )
      {
        v20 = debugStringBuilder;
      }
      else
      {
        UFG::qString::qString(&v23, "=>");
        v20 = debugStringBuilder;
        UFG::qStringBuilder::Add(debugStringBuilder, v23.mData, -1);
        UFG::qString::~qString(&v23);
      }
      if ( v19 )
        ActionController::writeDebugDisplayToString(
          (ActionController *)(p_mNext + 36),
          v20,
          bShowAllTracks,
          pControllerToHighlight,
          pTrackToHighlight,
          indentSpaces + sSpacesPerIndent,
          (ITask *)p_mNext);
    }
  }
LABEL_30:
  if ( pathToPopulate.mPath.mCount >= 0 && pathToPopulate.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
      operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
  }
}

// File Line: 2261
// RVA: 0x148A440
const char *dynamic_initializer_for__sActionControllerFactoryList__()
{
  const char *result; // rax

  result = ActionController::sClassName;
  sActionControllerFactoryList[0].mClassName = ActionController::sClassName;
  return result;
}

// File Line: 2267
// RVA: 0x1483CD0
__int64 dynamic_initializer_for__gActionControllerFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gActionControllerFactory,
    sActionControllerFactoryList,
    sActionControllerFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gActionControllerFactory__);
}

// File Line: 2271
// RVA: 0x1480410
__int64 dynamic_initializer_for__ActionController::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionController", 0xFFFFFFFF);
  ActionController::sClassNameUID = result;
  return result;
}

// File Line: 2326
// RVA: 0x26EBA0
ActionPath *__fastcall ActionController::GetPlayingFullPath(ActionController *this, ActionPath *result)
{
  result->mPath.mCount = 0;
  result->mPath.mData.mOffset = 0i64;
  return result;
}

// File Line: 2344
// RVA: 0x26E1E0
__int64 __fastcall ActionController::GetChildCount(ActionController *this)
{
  ActionNodePlayable **p_m_SequenceNode; // r10
  __int64 result; // rax
  ActionNodePlayable **p_mNext; // rdx
  bool i; // cl
  ActionNodePlayable *v5; // rcx

  p_m_SequenceNode = &this->m_SequenceNode;
  result = 0i64;
  p_mNext = (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = p_mNext == &this->m_SequenceNode; p_mNext; i = p_mNext == p_m_SequenceNode )
  {
    if ( i )
      break;
    v5 = p_mNext[3];
    if ( gReflectAllActionTreeTasks || v5 && SpawnTrack::sClassNameUID == LODWORD(v5->mParent.mOffset) )
      result = (unsigned int)(result + 1);
    p_mNext = (ActionNodePlayable **)&p_mNext[2][-1].mChildren.mData;
  }
  return result;
}

// File Line: 2371
// RVA: 0x26E100
ActionNodePlayable **__fastcall ActionController::GetChild2(ActionController *this, int priority)
{
  ActionNodePlayable **p_m_SequenceNode; // r11
  int v3; // r8d
  ActionNodePlayable **p_mNext; // rax
  bool i; // cl
  ActionNodePlayable *v6; // rcx

  p_m_SequenceNode = &this->m_SequenceNode;
  v3 = 0;
  p_mNext = (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = p_mNext == &this->m_SequenceNode; p_mNext; i = p_mNext == p_m_SequenceNode )
  {
    if ( i )
      return 0i64;
    v6 = p_mNext[3];
    if ( gReflectAllActionTreeTasks )
    {
      if ( priority == v3 && v6 )
      {
        if ( SpawnTrack::sClassNameUID == LODWORD(v6->mParent.mOffset) )
          return p_mNext + 36;
        return (ActionNodePlayable **)p_mNext[3];
      }
    }
    else
    {
      if ( !v6 || SpawnTrack::sClassNameUID != LODWORD(v6->mParent.mOffset) )
        goto LABEL_12;
      if ( priority == v3 )
        return p_mNext + 36;
    }
    ++v3;
LABEL_12:
    p_mNext = (ActionNodePlayable **)&p_mNext[2][-1].mChildren.mData;
  }
  return 0i64;
}

