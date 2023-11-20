// File Line: 83
// RVA: 0x1488320
__int64 dynamic_initializer_for__gSpawnTask__()
{
  unk_142047568 = &unk_142047568;
  unk_142047570 = &unk_142047568;
  gSpawnTask.vfptr = (ITaskVtbl *)&SpawnTask::`vftable;
  unk_142047578 = 0i64;
  unk_142047580 = &unk_142047580;
  unk_142047588 = &unk_142047580;
  unk_142047590 = 0i64;
  unk_142047598 = 0i64;
  _mm_store_si128((__m128i *)&unk_1420475A0, (__m128i)0i64);
  unk_1420475B0 = 0;
  unk_1420475B8 = -1i64;
  unk_1420475C0 = 0;
  unk_142047628 = 0;
  UFG::qMemSet(&unk_14204762C, 0, 0x28u);
  UFG::qMemSet(&unk_1420475E8, 0, 0x40u);
  _mm_store_si128((__m128i *)&unk_1420475D0, (__m128i)0i64);
  unk_1420475E0 = 0i64;
  unk_142047658 = 0;
  ActionController::ActionController(&stru_142047660);
  return atexit(dynamic_atexit_destructor_for__gSpawnTask__);
}

// File Line: 101
// RVA: 0x26BEE0
__int64 __fastcall ActionController::BreakPointMessageHandler(ActionController *this, const char *baseMessage, const char *appendedMessage)
{
  const char *v3; // rsi
  const char *v4; // rbp
  ActionController *v5; // rdi
  ActionNodePlayable *v6; // rcx
  const char *v7; // rbx
  const char *v8; // rax
  ActionNode *v9; // rcx
  char *v10; // rcx
  const char *v11; // rax
  unsigned int v12; // ebx
  UFG::qString v14; // [rsp+38h] [rbp-60h]
  UFG::qString v15; // [rsp+60h] [rbp-38h]

  v3 = appendedMessage;
  v4 = baseMessage;
  v5 = this;
  v6 = this->m_currentNode;
  v7 = "NULL";
  if ( v6 )
    v8 = ActionNode::GetNameFullPathe_DBG((ActionNode *)&v6->vfptr);
  else
    v8 = "NULL";
  UFG::qString::qString(&v15, v8);
  v9 = (ActionNode *)&v5->m_SequenceNode->vfptr;
  if ( v9 )
    v7 = ActionNode::GetNameFullPathe_DBG(v9);
  UFG::qString::qString(&v14, v7);
  v10 = &customWorldMapCaption;
  if ( v3 )
    v10 = (char *)v3;
  v11 = "FALSE";
  if ( v5->mOverRideNode )
    v11 = "TRUE";
  v12 = ActionTreeDebugMessageHandler(
          "ACTIONCONTROLLER:%s\n"
          " \t\t\t\t\t\t\t\t\tCurrentNode:\n"
          "%s\n"
          " \t\t\t\t\t\t\t\t\tSequenceNode:\n"
          "%s\n"
          " \t\t\t\t\t\t\t\t\tOverRide:%s\n"
          " \t\t\t\t\t\t\t\t\t%s\n",
          v4,
          v15.mData,
          v14.mData,
          v11,
          v10,
          -2i64);
  UFG::qString::~qString(&v14);
  UFG::qString::~qString(&v15);
  return v12;
}

// File Line: 146
// RVA: 0x273CF0
void __fastcall ActionController::breakOnPlay(ActionController *this, ActionNode *node)
{
  ActionController *v2; // rbx
  char *v3; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = this;
  if ( ActionController::sBreakOnPlay
    && node
    && ActionNode::sEnableNodeBreakPoints
    && node->mBreakPoint
    && this->m_Context->mDebugBreak
    && ActionNode::sSoftBreakPoints )
  {
    v3 = ActionNode::GetNameFullPathe_DBG(node);
    UFG::qString::FormatEx(&result, "NewNode:\n%s", v3);
    ActionController::BreakPointMessageHandler(v2, "ActionController::breakOnPlay", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 158
// RVA: 0x273D80
void __fastcall ActionController::breakOnStart(ActionController *this, ActionNode *node)
{
  ActionController *v2; // rbx
  char *v3; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = this;
  if ( ActionController::sBreakOnStart
    && node
    && ActionNode::sEnableNodeBreakPoints
    && node->mBreakPoint
    && this->m_Context->mDebugBreak
    && ActionNode::sSoftBreakPoints )
  {
    v3 = ActionNode::GetNameFullPathe_DBG(node);
    UFG::qString::FormatEx(&result, "NewNode:\n%s", v3);
    ActionController::BreakPointMessageHandler(v2, "ActionController::breakOnStart", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 211
// RVA: 0x268850
void __fastcall ActionController::ActionController(ActionController *this)
{
  UFG::qList<ITask,ITask,0,0> *v1; // [rsp+28h] [rbp+10h]
  UFG::qList<ITask,ITask,0,0> *v2; // [rsp+28h] [rbp+10h]
  UFG::qList<IFinishUpdate,IFinishUpdate,0,0> *v3; // [rsp+28h] [rbp+10h]

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
  v1 = &this->m_RunningTasks;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  v2 = &this->m_SequencedTasks;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  this->mRunningMasterRate = 1.0;
  v3 = &this->m_FinishUpdateTasks;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
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
  ActionController *v1; // rbx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionController::`vftable;
  ActionController::nodeCleanup(this);
  v1->m_SequenceNode = 0i64;
  v1->m_previousNode = 0i64;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&v1->m_FinishUpdateTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&v1->m_SequencedTasks);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&v1->m_RunningTasks);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 309
// RVA: 0x270730
void __fastcall ActionController::Play(ActionController *this)
{
  ActionController::Play(this, this->m_Context->m_OpeningBranch, 0);
}

// File Line: 314
// RVA: 0x270140
void __fastcall ActionController::Play(ActionController *this, ActionNode *node, bool forcePlay)
{
  ActionContext *v3; // rax
  bool v4; // r14
  ActionNodePlayable *v5; // rdi
  ActionController *v6; // rbx
  ActionContext *v7; // rbp
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int64 v9; // rsi
  UFG::AICharacterControllerBaseComponent *v10; // rax
  __int64 v11; // rax
  ActionNodeRoot *v12; // rsi
  ActionContext *v13; // rdx
  ActionNode *v14; // rcx
  __int64 v15; // rax
  ActionContext *v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  UEL::ParametersBase *v18; // rsi
  UFG::SimObject *v19; // rcx
  unsigned __int16 v20; // dx
  UFG::SimComponent *v21; // rax
  ActionNodePlayable *v22; // rax
  int v23; // edx
  int v24; // ecx

  if ( node )
  {
    v3 = this->m_Context;
    v4 = forcePlay;
    v5 = (ActionNodePlayable *)node;
    v6 = this;
    if ( v3 )
    {
      v3->mProbabilitiesValid = 0;
      v7 = this->m_Context;
      v8 = (UFG::SimObjectCVBase *)v7->mSimObject.m_pPointer;
      v9 = 0i64;
      if ( v8 )
      {
        if ( (v8->m_Flags >> 14) & 1 )
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
          if ( v10 )
            v9 = v10->m_Intention.mSignals;
        }
      }
      v7->mSignals = v9;
    }
    v11 = (__int64)v5->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v5->vfptr);
    v12 = (ActionNodeRoot *)v11;
    if ( v11 )
    {
      v13 = v6->m_Context;
      if ( v13->mActionTreeComponentBase[*(char *)(v11 + 236)] || v13->mActionTreeComponentBase[1] )
      {
        v14 = v13->m_OpeningBranch;
        v15 = v14 ? ((__int64 (*)(void))v14->vfptr[1].GetResourceOwner)() : 0i64;
        if ( (ActionNodeRoot *)v15 != v12 )
        {
          v16 = v6->m_Context;
          v17 = v16->mActionTreeComponentBase[v12->mActionTreeType.mValue];
          if ( !v17 )
            v17 = v16->mActionTreeComponentBase[1];
          if ( UFG::ActionTreeComponentBase::AllocateFor(v17, v12) )
            ActionNodeRoot::Init(v12, v6->m_Context);
        }
      }
    }
    v18 = UEL::gCurrentParameters;
    v19 = v6->m_Context->mSimObject.m_pPointer;
    if ( v19
      && ((v20 = v19->m_Flags, !((v20 >> 14) & 1)) ? ((v20 & 0x8000u) == 0 ? (!((v20 >> 13) & 1) ? (!((v20 >> 12) & 1) ? (v21 = UFG::SimObject::GetComponentOfType(v19, UFG::UELComponent::_TypeUID)) : (v21 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v19, UFG::UELComponent::_TypeUID))) : (v21 = v19->m_Components.p->m_pComponent)) : (v21 = v19->m_Components.p->m_pComponent)) : (v21 = v19->m_Components.p->m_pComponent),
          v21) )
    {
      UEL::gCurrentParameters = (UEL::ParametersBase *)&v21[1].m_TypeUID;
    }
    else
    {
      UEL::gCurrentParameters = 0i64;
    }
    v22 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNodePlayable *, ActionContext *))v5->vfptr[2].GetClassNameUID)(
                                  v5,
                                  v6->m_Context);
    if ( !v22 && v4 )
    {
      if ( v5->vfptr->GetClassNameUID((Expression::IMemberMap *)&v5->vfptr) == TrackLibraryNode::sClassNameUID )
      {
        ActionController::PlayTracks(v6, v5, 1, 0.0);
        return;
      }
      v22 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNodePlayable *))v5->vfptr[2].GetResourcePath)(v5);
    }
    if ( v6->mUpdating )
    {
      v23 = v6->m_SequencePriority;
      v24 = v23 + 1;
      if ( v22 )
      {
        if ( v24 > v23 )
        {
          v6->m_SequencePriority = v24;
          v6->m_SequenceNode = v22;
        }
        v6->mOverRideNode = 1;
      }
    }
    else
    {
      ActionController::Play(v6, v22);
    }
    UEL::gCurrentParameters = v18;
  }
}

// File Line: 395
// RVA: 0x275880
void __fastcall ActionController::setPlayingNodeUID(ActionController *this, ActionNodePlayable *currentNode, bool addPlayingInfo)
{
  unsigned int v3; // edi
  ActionNodePlayable *v4; // rbx
  ActionController *v5; // rsi
  unsigned __int64 v6; // rbp
  __int64 v7; // rax
  signed __int64 v8; // r8
  __int64 v9; // rdx
  __int64 v10; // rax
  ActionContext *v11; // rcx
  char v12; // al

  v3 = 0;
  v4 = currentNode;
  v5 = this;
  v6 = 0i64;
  if ( addPlayingInfo )
  {
    v3 = this->m_NumPlayingNodes;
    v6 = this->m_PlayingMostUsedMask;
  }
  else
  {
    UFG::qMemSet(this->m_Context->mMostUsedPlayCount, 0, 0x40u);
  }
  while ( 1 )
  {
    v7 = v4->mParent.mOffset;
    if ( !v7 )
      break;
    v8 = (signed __int64)&v4->mParent + v7;
    if ( !v8 )
      break;
    if ( v3 < 0x20 )
    {
      v9 = v4->mMostUsedIndex;
      v10 = v3++;
      v5->m_PlayingNodeUID[v10].mUID = v4->mID.mUID;
      if ( (_DWORD)v9 != -1 )
      {
        v11 = v5->m_Context;
        for ( v6 |= 1i64 << v9; v11; v11 = v11->mParentContext )
        {
          v12 = v11->mMostUsedPlayCount[v9];
          if ( (unsigned __int8)v12 >= 0xFAu )
            break;
          v11->mMostUsedPlayCount[v9] = v12 + 1;
        }
      }
    }
    v4 = (ActionNodePlayable *)v8;
  }
  v5->m_PlayingMostUsedMask = v6;
  v5->m_NumPlayingNodes = v3;
}

// File Line: 449
// RVA: 0x270360
void __fastcall ActionController::Play(ActionController *this, ActionNodePlayable *node)
{
  ActionNodePlayable *v2; // rbx
  ActionController *v3; // rsi
  ActionContext *v4; // rax
  int v5; // ecx
  int v6; // eax
  __int64 v7; // rax
  ActionNodeRoot *v8; // rbx
  ActionContext *v9; // rdx
  ActionNode *v10; // rcx
  __int64 v11; // rax
  ActionContext *v12; // rdx
  UFG::ActionTreeComponentBase *v13; // rcx
  __int64 v14; // rax
  char *v15; // r9
  __int64 v16; // rbp
  __int64 v17; // rdi
  signed __int64 v18; // r14
  signed __int64 v19; // rcx
  __int64 v20; // rax
  ActionNodePlayable *v21; // rdx
  UFG::qNode<ITask,ITask> *v22; // rax
  UFG::qNode<ITask,ITask> *v23; // rcx
  ActionNodePlayable *v24; // rax
  __int64 v25; // rcx
  signed __int64 v26; // rax
  ActionNode *v27; // rbx
  __int64 v28; // rax
  __int64 v29; // rdi
  __int64 v30; // rbp
  signed __int64 v31; // r15
  UFG::qList<ITask,ITask,0,0> *v32; // r14
  signed __int64 v33; // rcx
  UFG::qNode<ITask,ITask> *v34; // rax
  UFG::qNode<ITask,ITask> *v35; // rcx
  __int64 v36; // rax
  signed __int64 v37; // rbx
  ActionNodePlayable *v38; // r8
  int v39; // er10
  ActionNode *v40; // r11
  signed __int64 v41; // rcx
  signed __int64 v42; // rdx
  __int64 v43; // rax
  signed __int64 v44; // rdx
  __int64 v45; // rax
  signed __int64 v46; // rcx
  bool v47; // zf
  __int64 v48; // rax
  signed __int64 v49; // r8
  __int64 v50; // rbp
  __int64 v51; // rdi
  ActionContext *v52; // r14
  __int64 *i; // rbx
  __int64 v54; // [rsp+18h] [rbp-120h]
  char v55; // [rsp+20h] [rbp-118h]

  v2 = node;
  v3 = this;
  ActionController::breakOnPlay(this, (ActionNode *)&node->vfptr);
  v4 = v3->m_Context;
  if ( v4 )
    v4->mProbabilitiesValid = 0;
  if ( v3->mUpdating )
  {
    v5 = v3->m_SequencePriority;
    v6 = v5 + 1;
    if ( v2 )
    {
      if ( v6 > v5 )
      {
        v3->m_SequencePriority = v6;
        v3->m_SequenceNode = v2;
      }
      v3->mOverRideNode = 1;
    }
  }
  else
  {
    ActionController::breakOnStart(v3, (ActionNode *)&v2->vfptr);
    ActionController::nodeCleanup(v3);
    v3->m_SequenceNode = 0i64;
    v3->m_currentNode = v2;
    if ( v2 )
    {
      v7 = (__int64)v2->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v2->vfptr);
      v8 = (ActionNodeRoot *)v7;
      if ( v7 )
      {
        v9 = v3->m_Context;
        if ( v9->mActionTreeComponentBase[*(char *)(v7 + 236)] || v9->mActionTreeComponentBase[1] )
        {
          v10 = v9->m_OpeningBranch;
          v11 = v10 ? ((__int64 (*)(void))v10->vfptr[1].GetResourceOwner)() : 0i64;
          if ( (ActionNodeRoot *)v11 != v8 )
          {
            v12 = v3->m_Context;
            v13 = v12->mActionTreeComponentBase[v8->mActionTreeType.mValue];
            if ( !v13 )
              v13 = v12->mActionTreeComponentBase[1];
            if ( UFG::ActionTreeComponentBase::AllocateFor(v13, v8) )
              ActionNodeRoot::Init(v8, v3->m_Context);
          }
        }
      }
      ActionController::setPlayingNodeUID(v3, v3->m_currentNode, 0);
      v14 = ((__int64 (*)(void))v3->m_currentNode->vfptr[3].GetClassNameUID)();
      v16 = v14;
      if ( v14 )
      {
        v17 = 0i64;
        v18 = *(_QWORD *)(v14 + 24) + v14 + 24;
        if ( *(_DWORD *)(v14 + 16) & 0x7FFFFFFF )
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
              ActionController::PlayTracks(v3, v21, 1, *(float *)(v19 + 48));
            }
            else
            {
              v22 = (UFG::qNode<ITask,ITask> *)(*(__int64 (__fastcall **)(signed __int64, const char *))(*(_QWORD *)v19 + 80i64))(
                                                 v19,
                                                 "ActionController::Play(): My tasks");
              v23 = v3->m_SequencedTasks.mNode.mPrev;
              v22 = (UFG::qNode<ITask,ITask> *)((char *)v22 + 8);
              v23->mNext = v22;
              v22->mPrev = v23;
              v22->mNext = &v3->m_SequencedTasks.mNode;
              v3->m_SequencedTasks.mNode.mPrev = v22;
            }
            v17 = (unsigned int)(v17 + 1);
          }
          while ( (unsigned int)v17 < (*(_DWORD *)(v16 + 16) & 0x7FFFFFFFu) );
        }
      }
      if ( v3->m_BankTracksEnabled )
      {
        v24 = v3->m_currentNode;
        v25 = v24->mParent.mOffset;
        v26 = (signed __int64)&v24->mParent;
        if ( v25 )
        {
          v27 = (ActionNode *)(v25 + v26);
          if ( v25 + v26 )
          {
            do
            {
              if ( v27->vfptr->GetClassNameUID((Expression::IMemberMap *)&v27->vfptr) == ActionNodeBank::sClassNameUID
                || v27->vfptr->GetClassNameUID((Expression::IMemberMap *)&v27->vfptr) == ActionNodeRoot::sClassNameUID )
              {
                v28 = v27->vfptr[3].GetClassNameUID((Expression::IMemberMap *)&v27->vfptr);
                v29 = v28;
                if ( v28 )
                {
                  v30 = 0i64;
                  v31 = v28 + *(_QWORD *)(v28 + 24) + 24i64;
                  if ( *(_DWORD *)(v28 + 16) & 0x7FFFFFFF )
                  {
                    v32 = &v3->m_SequencedTasks;
                    do
                    {
                      v33 = *(_QWORD *)(v31 + 8 * v30) + v31 + 8 * v30;
                      v34 = (UFG::qNode<ITask,ITask> *)(*(__int64 (__fastcall **)(signed __int64, const char *))(*(_QWORD *)v33 + 80i64))(
                                                         v33,
                                                         "ActionController::Play(): Parents tasks");
                      v35 = v32->mNode.mPrev;
                      v30 = (unsigned int)(v30 + 1);
                      v34 = (UFG::qNode<ITask,ITask> *)((char *)v34 + 8);
                      v35->mNext = v34;
                      v34->mPrev = v35;
                      v34->mNext = &v32->mNode;
                      v32->mNode.mPrev = v34;
                    }
                    while ( (unsigned int)v30 < (*(_DWORD *)(v29 + 16) & 0x7FFFFFFFu) );
                  }
                }
              }
              if ( v27 == v3->m_Context->m_OpeningBranch )
                break;
              v36 = v27->mParent.mOffset;
              v37 = (signed __int64)&v27->mParent;
              if ( !v36 )
                break;
              v27 = (ActionNode *)(v36 + v37);
            }
            while ( v27 );
          }
        }
      }
      if ( v3->m_OnEnterExitCallbacksEnabled )
      {
        v38 = v3->m_currentNode;
        v39 = 0;
        if ( v38 )
        {
          v15 = &v55;
          v40 = v3->m_Context->m_OpeningBranch;
          do
          {
            ++v39;
            *(_QWORD *)v15 = v38;
            v15 += 8;
            v41 = (signed __int64)v40;
            v42 = (signed __int64)v38;
            if ( v38 == (ActionNodePlayable *)v40 )
              break;
            while ( v41 )
            {
              if ( *(_DWORD *)(v42 + 40) != *(_DWORD *)(v41 + 40) )
                goto LABEL_58;
              v43 = *(_QWORD *)(v42 + 16);
              v44 = v42 + 16;
              if ( v43 )
                v42 = v43 + v44;
              else
                v42 = 0i64;
              v45 = *(_QWORD *)(v41 + 16);
              v46 = v41 + 16;
              if ( v45 )
                v41 = v45 + v46;
              else
                v41 = 0i64;
              if ( !v42 )
              {
                v47 = v41 == 0;
                goto LABEL_57;
              }
            }
            v47 = v42 == 0;
LABEL_57:
            if ( v47 )
              break;
LABEL_58:
            v48 = v38->mParent.mOffset;
            v49 = (signed __int64)&v38->mParent;
            if ( !v48 )
              break;
            v38 = (ActionNodePlayable *)(v48 + v49);
          }
          while ( v38 );
        }
        v50 = v39;
        while ( v50 > 0 )
        {
          v51 = *(&v54 + v50);
          v52 = v3->m_Context;
          --v50;
          for ( i = *(__int64 **)(v51 + 24); i; i = (__int64 *)*i )
          {
            if ( !*((_DWORD *)i + 6) )
              ((void (__fastcall *)(__int64, __int64, ActionContext *, char *))i[2])(i[1], v51, v52, v15);
          }
        }
      }
    }
  }
}

// File Line: 625
// RVA: 0x270740
void __fastcall ActionController::PlayTracks(ActionController *this, ActionNode *node, bool offsetTimeBeginAndEnd, float offsetTime)
{
  ActionContext *v4; // rbx
  bool v5; // bp
  ActionController *v6; // rsi
  ActionNode *v7; // r14
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int64 v9; // rdi
  UFG::AICharacterControllerBaseComponent *v10; // rax
  ActionNodePlayable *v11; // rax

  v4 = this->m_Context;
  v5 = offsetTimeBeginAndEnd;
  v6 = this;
  v7 = node;
  if ( v4 )
  {
    v8 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
    v9 = 0i64;
    if ( v8 )
    {
      if ( (v8->m_Flags >> 14) & 1 )
      {
        v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
        if ( v10 )
          v9 = v10->m_Intention.mSignals;
      }
    }
    v4->mSignals = v9;
  }
  v11 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))v7->vfptr[2].GetClassNameUID)(
                                v7,
                                v6->m_Context);
  if ( v11 )
    ActionController::PlayTracks(v6, v11, v5, offsetTime);
}

// File Line: 641
// RVA: 0x2707F0
void __fastcall ActionController::PlayTracks(ActionController *this, ActionNodePlayable *node, bool offsetTimeBeginAndEnd, float offsetTime)
{
  ActionController *v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rbp
  __int64 v7; // rdx
  signed __int64 v8; // rcx
  __int64 v9; // rsi
  signed __int64 v10; // rdi
  signed __int64 v11; // rcx
  signed __int64 v12; // rax
  bool v13; // dl
  signed __int64 v14; // rax
  bool v15; // dl
  __int64 v16; // rax
  ActionNodePlayable *v17; // rdx
  __int64 v18; // rax
  float v19; // xmm0_4
  float v20; // xmm0_4
  UFG::qNode<ITask,ITask> *v21; // rcx
  UFG::qNode<ITask,ITask> *v22; // rax
  signed __int64 v23; // [rsp+68h] [rbp+10h]
  bool v24; // [rsp+70h] [rbp+18h]

  if ( node )
  {
    v24 = offsetTimeBeginAndEnd;
    v4 = this;
    v5 = node->vfptr[3].GetClassNameUID((Expression::IMemberMap *)node);
    v6 = v5;
    if ( v5 )
    {
      v7 = *(_QWORD *)(v5 + 24);
      v8 = v7 + v5 + 24;
      v9 = 0i64;
      v23 = v7 + v5 + 24;
      if ( *(_DWORD *)(v5 + 16) & 0x7FFFFFFF )
      {
        v10 = (signed __int64)&v4->m_SequenceNode;
        do
        {
          v11 = *(_QWORD *)(v8 + 8 * v9) + v8 + 8 * v9;
          v12 = (signed __int64)&v4->m_RunningTasks.mNode.mNext[-1].mNext;
          v13 = v12 == v10;
          if ( v4->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v13 )
                break;
              if ( v11 == *(_QWORD *)(v12 + 24) )
                goto LABEL_26;
              v12 = *(_QWORD *)(v12 + 16) - 8i64;
              v13 = v12 == v10;
            }
            while ( v12 );
          }
          v14 = (signed __int64)&v4->m_SequencedTasks.mNode.mNext[-1].mNext;
          v15 = v14 == (_QWORD)v4 + 88;
          if ( v4->m_SequencedTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v15 )
                break;
              if ( v11 == *(_QWORD *)(v14 + 24) )
                goto LABEL_26;
              v14 = *(_QWORD *)(v14 + 16) - 8i64;
              v15 = v14 == (_QWORD)v4 + 88;
            }
            while ( v14 );
          }
          if ( *(_DWORD *)(v11 + 16) == ExecuteTrackLibraryTrack::sClassNameUID )
          {
            v16 = *(_QWORD *)(v11 + 56);
            if ( v16 )
              v16 += v11 + 56;
            v17 = *(ActionNodePlayable **)(v16 + 72);
            if ( v17 )
              v17 = (ActionNodePlayable *)((char *)v17 + v16 + 72);
            ActionController::PlayTracks(v4, v17, 1, *(float *)(v11 + 48));
          }
          else
          {
            v18 = (*(__int64 (__fastcall **)(signed __int64, const char *))(*(_QWORD *)v11 + 80i64))(
                    v11,
                    "ActionController::PlayTracks()");
            if ( v24 && offsetTime > 0.0 )
            {
              v19 = *(float *)(v18 + 32);
              if ( v19 >= 0.0 )
                *(float *)(v18 + 32) = v19 + offsetTime;
              v20 = *(float *)(v18 + 36);
              if ( v20 >= 0.0 )
                *(float *)(v18 + 36) = v20 + offsetTime;
            }
            v21 = (UFG::qNode<ITask,ITask> *)(v18 + 8);
            v22 = v4->m_SequencedTasks.mNode.mPrev;
            v22->mNext = v21;
            v21->mPrev = v22;
            v21->mNext = &v4->m_SequencedTasks.mNode;
            v4->m_SequencedTasks.mNode.mPrev = v21;
          }
LABEL_26:
          v8 = v23;
          v9 = (unsigned int)(v9 + 1);
        }
        while ( (unsigned int)v9 < (*(_DWORD *)(v6 + 16) & 0x7FFFFFFFu) );
      }
    }
  }
}

// File Line: 706
// RVA: 0x2709B0
void __fastcall ActionController::PlayTracks(ActionController *this, ITrack *track, bool offsetTimeBeginAndEnd, float offsetTime)
{
  ITrack *v4; // rbx
  ITrack **v5; // rax
  bool v6; // si
  ActionController *v7; // rdi
  bool v8; // dl
  unsigned __int64 *v9; // rdx
  ITrack **v10; // rax
  bool i; // cl
  Expression::IMemberMapVtbl *v12; // rax
  ActionNodePlayable *v13; // rdx
  signed __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  UFG::qNode<ITask,ITask> *v19; // rcx
  UFG::qNode<ITask,ITask> *v20; // rax

  if ( track )
  {
    v4 = track;
    v5 = (ITrack **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
    v6 = offsetTimeBeginAndEnd;
    v7 = this;
    v8 = v5 == (ITrack **)&this->m_SequenceNode;
    if ( this->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
    {
      do
      {
        if ( v8 )
          break;
        if ( v4 == v5[3] )
          return;
        v5 = (ITrack **)&v5[2][-1].mTimeBegin;
        v8 = v5 == (ITrack **)&this->m_SequenceNode;
      }
      while ( v5 );
    }
    v9 = &this->m_RunningSpawnTasksTmp[1];
    v10 = (ITrack **)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
    for ( i = v10 == (ITrack **)&this->m_RunningSpawnTasksTmp[1]; v10; i = v10 == (ITrack **)v9 )
    {
      if ( i )
        break;
      if ( v4 == v10[3] )
        return;
      v10 = (ITrack **)&v10[2][-1].mTimeBegin;
    }
    if ( v4->m_TrackClassNameUID == ExecuteTrackLibraryTrack::sClassNameUID )
    {
      v12 = v4[1].vfptr;
      v13 = 0i64;
      if ( v12 )
        v14 = (signed __int64)&v12->ResolveReferences + (_QWORD)v4;
      else
        v14 = 0i64;
      v15 = *(_QWORD *)(v14 + 72);
      if ( v15 )
        v13 = (ActionNodePlayable *)(v15 + v14 + 72);
      ActionController::PlayTracks(v7, v13, 1, v4->mTimeBegin);
    }
    v16 = (__int64)v4->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v4->vfptr, "ActionController::PlayTracks()");
    if ( v6 && offsetTime > 0.0 )
    {
      v17 = *(float *)(v16 + 32);
      if ( v17 >= 0.0 )
        *(float *)(v16 + 32) = v17 + offsetTime;
      v18 = *(float *)(v16 + 36);
      if ( v18 >= 0.0 )
        *(float *)(v16 + 36) = v18 + offsetTime;
    }
    v19 = (UFG::qNode<ITask,ITask> *)(v16 + 8);
    v20 = v7->m_SequencedTasks.mNode.mPrev;
    v20->mNext = v19;
    v19->mPrev = v20;
    v19->mNext = &v7->m_SequencedTasks.mNode;
    v7->m_SequencedTasks.mNode.mPrev = v19;
  }
}

// File Line: 756
// RVA: 0x270B10
void __fastcall ActionController::PlayTracks(ActionController *this, TrackGroup *group, bool offsetTimeBeginAndEnd, float offsetTime)
{
  __int64 v4; // rsi
  char *v5; // r14
  bool v6; // r15
  TrackGroup *v7; // rbp
  ActionController *v8; // rdi
  signed __int64 v9; // rbx
  signed __int64 v10; // rax
  bool v11; // cl
  signed __int64 v12; // rax
  bool v13; // cl
  __int64 v14; // rax
  __int64 v15; // rcx
  ActionNodePlayable *v16; // rdx
  __int64 v17; // rax
  float v18; // xmm0_4
  float v19; // xmm0_4
  UFG::qNode<ITask,ITask> *v20; // rcx
  UFG::qNode<ITask,ITask> *v21; // rax

  if ( group )
  {
    v4 = 0i64;
    v5 = (char *)&group->mTracks.mData + group->mTracks.mData.mOffset;
    v6 = offsetTimeBeginAndEnd;
    v7 = group;
    v8 = this;
    if ( group->mTracks.mCount & 0x7FFFFFFF )
    {
      do
      {
        v9 = (signed __int64)&v5[8 * v4 + *(_QWORD *)&v5[8 * v4]];
        if ( v9 )
        {
          v10 = (signed __int64)&v8->m_RunningTasks.mNode.mNext[-1].mNext;
          v11 = v10 == (_QWORD)v8 + 56;
          if ( v8->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v11 )
                break;
              if ( v9 == *(_QWORD *)(v10 + 24) )
                goto LABEL_26;
              v10 = *(_QWORD *)(v10 + 16) - 8i64;
              v11 = v10 == (_QWORD)v8 + 56;
            }
            while ( v10 );
          }
          v12 = (signed __int64)&v8->m_SequencedTasks.mNode.mNext[-1].mNext;
          v13 = v12 == (_QWORD)v8 + 88;
          if ( v8->m_SequencedTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
          {
            do
            {
              if ( v13 )
                break;
              if ( v9 == *(_QWORD *)(v12 + 24) )
                goto LABEL_26;
              v12 = *(_QWORD *)(v12 + 16) - 8i64;
              v13 = v12 == (_QWORD)v8 + 88;
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
            ActionController::PlayTracks(v8, v16, 1, *(float *)(v9 + 48));
          }
          v17 = (*(__int64 (__fastcall **)(signed __int64, const char *))(*(_QWORD *)v9 + 80i64))(
                  v9,
                  "ActionController::PlayTracks()");
          if ( v6 && offsetTime > 0.0 )
          {
            v18 = *(float *)(v17 + 32);
            if ( v18 >= 0.0 )
              *(float *)(v17 + 32) = v18 + offsetTime;
            v19 = *(float *)(v17 + 36);
            if ( v19 >= 0.0 )
              *(float *)(v17 + 36) = v19 + offsetTime;
          }
          v20 = (UFG::qNode<ITask,ITask> *)(v17 + 8);
          v21 = v8->m_SequencedTasks.mNode.mPrev;
          v21->mNext = v20;
          v20->mPrev = v21;
          v20->mNext = &v8->m_SequencedTasks.mNode;
          v8->m_SequencedTasks.mNode.mPrev = v20;
        }
LABEL_26:
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < (v7->mTracks.mCount & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 787
// RVA: 0x272290
void __fastcall ActionController::Sequence(ActionController *this, ActionNodePlayable *node, int priority, bool override)
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
  ActionController *v1; // rbx

  v1 = this;
  ActionController::nodeCleanup(this);
  v1->m_SequenceNode = 0i64;
  v1->m_previousNode = 0i64;
}

// File Line: 820
// RVA: 0x272E40
void __fastcall ActionController::Update(ActionController *this, float timeDelta)
{
  ActionController *v2; // rbx
  ActionNodePlayable *v3; // rax
  signed __int64 v4; // rdi
  float v5; // xmm0_4
  signed __int64 v6; // r14
  __int64 v7; // rcx
  _QWORD *v8; // rax
  UFG::qNode<ITask,ITask> **v9; // rdx
  UFG::qNode<ITask,ITask> *v10; // rax
  __int64 v11; // rsi
  __int64 v12; // rax
  signed __int64 v13; // rcx
  float v14; // xmm0_4
  __int64 v15; // rcx
  unsigned __int64 v16; // rax
  unsigned __int64 *v17; // rcx
  ActionContext *v18; // rdi
  signed __int64 v19; // r14
  UFG::SimObjectCVBase *v20; // rcx
  unsigned __int64 v21; // rsi
  UFG::AICharacterControllerBaseComponent *v22; // rax
  ActionNodePlayable **v23; // r12
  signed __int64 v24; // r8
  signed __int64 v25; // rdx
  signed __int64 v26; // rcx
  __int64 v27; // rdi
  __int64 v28; // rax
  signed __int64 v29; // rdi
  signed __int64 v30; // rcx
  float v31; // xmm0_4
  float v32; // xmm7_4
  signed __int64 v33; // r15
  signed __int64 v34; // rdi
  char v35; // r13
  float v36; // xmm0_4
  signed __int64 v37; // r15
  __int64 v38; // rcx
  _QWORD *v39; // rax
  UFG::qNode<ITask,ITask> **v40; // rdx
  UFG::qNode<ITask,ITask> *v41; // rax
  __int64 v42; // rsi
  __int64 v43; // rax
  signed __int64 v44; // rcx
  float v45; // xmm0_4
  __int64 v46; // rcx
  unsigned __int64 v47; // rax
  unsigned __int64 *v48; // rcx
  __int64 v49; // rax
  bool v50; // cf
  bool v51; // zf
  char v52; // al
  signed __int64 v53; // rdx
  signed __int64 v54; // rcx
  ActionNodePlayable *v55; // rax
  const char *v56; // r8
  bool v57; // di
  signed __int64 v58; // rdi
  float v59; // xmm0_4
  signed __int64 v60; // r14
  __int64 v61; // rcx
  _QWORD *v62; // rax
  UFG::qNode<ITask,ITask> **v63; // rdx
  UFG::qNode<ITask,ITask> *v64; // rax
  __int64 v65; // rsi
  __int64 v66; // rax
  signed __int64 v67; // rcx
  float v68; // xmm0_4
  __int64 v69; // rcx
  unsigned __int64 v70; // rax
  unsigned __int64 *v71; // rcx
  signed __int64 v72; // rdi
  float v73; // xmm0_4
  signed __int64 v74; // r14
  __int64 v75; // rcx
  _QWORD *v76; // rax
  UFG::qNode<ITask,ITask> **v77; // rdx
  UFG::qNode<ITask,ITask> *v78; // rax
  __int64 v79; // rsi
  __int64 v80; // rax
  signed __int64 v81; // rcx
  float v82; // xmm0_4
  __int64 v83; // rcx
  unsigned __int64 v84; // rax
  unsigned __int64 *v85; // rcx
  __int64 v86; // [rsp+30h] [rbp-9h]
  __int16 v87; // [rsp+44h] [rbp+Bh]

  v2 = this;
  if ( ActionController::sBreakOnUpdate )
  {
    v3 = this->m_currentNode;
    if ( v3 )
    {
      if ( ActionNode::sEnableNodeBreakPoints
        && v3->mBreakPoint
        && this->m_Context->mDebugBreak
        && ActionNode::sSoftBreakPoints )
      {
        ActionController::BreakPointMessageHandler(this, "ActionController::breakOnUpdate", 0i64);
      }
    }
  }
  if ( v2->m_currentNode || !v2->mKeepAlive )
  {
    v18 = v2->m_Context;
    v19 = 0i64;
    if ( v18 )
    {
      v20 = (UFG::SimObjectCVBase *)v18->mSimObject.m_pPointer;
      v21 = 0i64;
      if ( v20 )
      {
        if ( (v20->m_Flags >> 14) & 1 )
        {
          v22 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v20);
          if ( v22 )
            v21 = v22->m_Intention.mSignals;
        }
      }
      v18->mSignals = v21;
    }
    v23 = &v2->m_SequenceNode;
    v24 = 0i64;
    v25 = (signed __int64)&v2->m_RunningTasks.mNode.mNext[-1].mNext;
    if ( (ActionNodePlayable **)v25 != &v2->m_SequenceNode )
    {
      do
      {
        v26 = *(_QWORD *)(v25 + 16) - 8i64;
        if ( *(_BYTE *)(*(_QWORD *)(v25 + 24) + 22i64) )
          v24 = v25;
        v25 = *(_QWORD *)(v25 + 16) - 8i64;
      }
      while ( (ActionNodePlayable **)v26 != v23 );
      if ( v24 )
      {
        v27 = *(_QWORD *)(v24 + 24);
        v28 = *(_QWORD *)(v27 + 32);
        v29 = v27 + 24;
        if ( v28
          && (v30 = v29 + v28 + 8) != 0
          && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v30 + 24i64))(
                v30,
                &v86,
                UEL::gCurrentParameters,
                0i64,
                UEL::gCurrentStringBuilder),
              v87) )
        {
          if ( v87 == 4 )
            v31 = *(float *)&v86;
          else
            v31 = (float)(signed int)v86;
        }
        else
        {
          v31 = *(float *)(v29 + 16);
        }
        v2->mRunningMasterRate = v31;
      }
    }
    v32 = timeDelta * v2->mRunningMasterRate;
    v33 = (signed __int64)&v2->m_RunningSpawnTasksTmp[1];
    v34 = (signed __int64)&v2->m_SequencedTasks.mNode.mNext[-1].mNext;
    v35 = 0;
    v2->mUpdating = 1;
    v2->m_ActionNodePlayTime = v32 + v2->m_ActionNodePlayTime;
    if ( (unsigned __int64 *)v34 != &v2->m_RunningSpawnTasksTmp[1] )
    {
      do
      {
        v36 = *(float *)(v34 + 32);
        v37 = *(_QWORD *)(v34 + 16) - 8i64;
        if ( v36 < 0.0 || v36 > v2->m_ActionNodePlayTime )
        {
          v49 = *(_QWORD *)(v34 + 24);
          if ( !*(_BYTE *)(v49 + 22)
            || (v50 = *(float *)(v49 + 48) > 0.0, v51 = *(float *)(v49 + 48) == 0.0, v52 = 1, !v50 && !v51) )
          {
            v52 = 0;
          }
          v35 |= v52;
        }
        else
        {
          v38 = *(_QWORD *)(v34 + 8);
          v39 = *(_QWORD **)(v34 + 16);
          v40 = (UFG::qNode<ITask,ITask> **)(v34 + 8);
          *(_QWORD *)(v38 + 8) = v39;
          *v39 = v38;
          *v40 = (UFG::qNode<ITask,ITask> *)v40;
          v40[1] = (UFG::qNode<ITask,ITask> *)v40;
          v41 = v2->m_RunningTasks.mNode.mPrev;
          v41->mNext = (UFG::qNode<ITask,ITask> *)(v34 + 8);
          *v40 = v41;
          v40[1] = &v2->m_RunningTasks.mNode;
          v2->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v34 + 8);
          v42 = *(_QWORD *)(v34 + 24);
          if ( *(_BYTE *)(v42 + 22) )
          {
            v43 = *(_QWORD *)(v42 + 32);
            if ( v43
              && (v44 = v42 + v43 + 32) != 0
              && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v44 + 24i64))(
                    v44,
                    &v86,
                    UEL::gCurrentParameters,
                    0i64,
                    UEL::gCurrentStringBuilder),
                  v87) )
            {
              if ( v87 == 4 )
                v45 = *(float *)&v86;
              else
                v45 = (float)(signed int)v86;
            }
            else
            {
              v45 = *(float *)(v42 + 40);
            }
            v2->mRunningMasterRate = v45;
          }
          (*(void (__fastcall **)(signed __int64, ActionContext *, signed __int64))(*(_QWORD *)v34 + 8i64))(
            v34,
            v2->m_Context,
            v24);
          v46 = *(_QWORD *)(v34 + 24);
          if ( v46 && *(_DWORD *)(v46 + 16) == SpawnTrack::sClassNameUID )
          {
            v47 = v2->m_RunningSpawnTasksTmp[0];
            v48 = (unsigned __int64 *)(v34 + 40);
            *(_QWORD *)(v47 + 8) = v34 + 40;
            *v48 = v47;
            v48[1] = (unsigned __int64)v2->m_RunningSpawnTasksTmp;
            v2->m_RunningSpawnTasksTmp[0] = v34 + 40;
          }
        }
        v34 = v37;
      }
      while ( (unsigned __int64 *)v37 != &v2->m_RunningSpawnTasksTmp[1] );
      v33 = (signed __int64)&v2->m_RunningSpawnTasksTmp[1];
    }
    ActionController::updateTasks(v2, v32);
    v53 = (signed __int64)&v2->m_RunningTasks.mNode.mNext[-1].mNext;
    if ( (ActionNodePlayable **)v53 != v23 )
    {
      do
      {
        v54 = *(_QWORD *)(v53 + 16) - 8i64;
        if ( *(_BYTE *)(*(_QWORD *)(v53 + 24) + 22i64) )
          v19 = v53;
        v53 = *(_QWORD *)(v53 + 16) - 8i64;
      }
      while ( (ActionNodePlayable **)v54 != v23 );
    }
    v51 = v2->mOverRideNode == 0;
    v2->mUpdating = 0;
    if ( !v51 || !v19 && !v35 )
    {
      if ( ActionController::sBreakOnEnd )
      {
        v55 = v2->m_currentNode;
        if ( v55 )
        {
          if ( ActionNode::sEnableNodeBreakPoints
            && v55->mBreakPoint
            && v2->m_Context->mDebugBreak
            && ActionNode::sSoftBreakPoints )
          {
            v56 = "masterTracksRunning:FALSE";
            if ( v19 )
              v56 = "masterTracksRunning:TRUE";
            ActionController::BreakPointMessageHandler(v2, "ActionController::breakOnEnd", v56);
          }
        }
      }
      v57 = v2->mKeepAlive != 0;
      ActionController::nodeCleanup(v2);
      if ( *v23 )
      {
        ActionController::Play(v2, *v23);
        v58 = (signed __int64)&v2->m_SequencedTasks.mNode.mNext[-1].mNext;
        if ( v58 != v33 )
        {
          do
          {
            v59 = *(float *)(v58 + 32);
            v60 = *(_QWORD *)(v58 + 16) - 8i64;
            if ( v59 >= 0.0 && v59 <= v2->m_ActionNodePlayTime )
            {
              v61 = *(_QWORD *)(v58 + 8);
              v62 = *(_QWORD **)(v58 + 16);
              v63 = (UFG::qNode<ITask,ITask> **)(v58 + 8);
              *(_QWORD *)(v61 + 8) = v62;
              *v62 = v61;
              *v63 = (UFG::qNode<ITask,ITask> *)v63;
              v63[1] = (UFG::qNode<ITask,ITask> *)v63;
              v64 = v2->m_RunningTasks.mNode.mPrev;
              v64->mNext = (UFG::qNode<ITask,ITask> *)(v58 + 8);
              *v63 = v64;
              v63[1] = &v2->m_RunningTasks.mNode;
              v2->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v58 + 8);
              v65 = *(_QWORD *)(v58 + 24);
              if ( *(_BYTE *)(v65 + 22) )
              {
                v66 = *(_QWORD *)(v65 + 32);
                if ( v66
                  && (v67 = v65 + v66 + 32) != 0
                  && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v67 + 24i64))(
                        v67,
                        &v86,
                        UEL::gCurrentParameters,
                        0i64,
                        UEL::gCurrentStringBuilder),
                      v87) )
                {
                  if ( v87 == 4 )
                    v68 = *(float *)&v86;
                  else
                    v68 = (float)(signed int)v86;
                }
                else
                {
                  v68 = *(float *)(v65 + 40);
                }
                v2->mRunningMasterRate = v68;
              }
              (*(void (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v58 + 8i64))(v58, v2->m_Context);
              v69 = *(_QWORD *)(v58 + 24);
              if ( v69 && *(_DWORD *)(v69 + 16) == SpawnTrack::sClassNameUID )
              {
                v70 = v2->m_RunningSpawnTasksTmp[0];
                v71 = (unsigned __int64 *)(v58 + 40);
                *(_QWORD *)(v70 + 8) = v58 + 40;
                *v71 = v70;
                v71[1] = (unsigned __int64)v2->m_RunningSpawnTasksTmp;
                v2->m_RunningSpawnTasksTmp[0] = v58 + 40;
              }
            }
            v58 = v60;
          }
          while ( v60 != v33 );
        }
      }
      else if ( v57 )
      {
        ActionController::Play(v2, v2->m_Context->m_OpeningBranch, 0);
        v72 = (signed __int64)&v2->m_SequencedTasks.mNode.mNext[-1].mNext;
        if ( v72 != v33 )
        {
          do
          {
            v73 = *(float *)(v72 + 32);
            v74 = *(_QWORD *)(v72 + 16) - 8i64;
            if ( v73 >= 0.0 && v73 <= v2->m_ActionNodePlayTime )
            {
              v75 = *(_QWORD *)(v72 + 8);
              v76 = *(_QWORD **)(v72 + 16);
              v77 = (UFG::qNode<ITask,ITask> **)(v72 + 8);
              *(_QWORD *)(v75 + 8) = v76;
              *v76 = v75;
              *v77 = (UFG::qNode<ITask,ITask> *)v77;
              v77[1] = (UFG::qNode<ITask,ITask> *)v77;
              v78 = v2->m_RunningTasks.mNode.mPrev;
              v78->mNext = (UFG::qNode<ITask,ITask> *)(v72 + 8);
              *v77 = v78;
              v77[1] = &v2->m_RunningTasks.mNode;
              v2->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v72 + 8);
              v79 = *(_QWORD *)(v72 + 24);
              if ( *(_BYTE *)(v79 + 22) )
              {
                v80 = *(_QWORD *)(v79 + 32);
                if ( v80
                  && (v81 = v79 + v80 + 32) != 0
                  && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v81 + 24i64))(
                        v81,
                        &v86,
                        UEL::gCurrentParameters,
                        0i64,
                        UEL::gCurrentStringBuilder),
                      v87) )
                {
                  if ( v87 == 4 )
                    v82 = *(float *)&v86;
                  else
                    v82 = (float)(signed int)v86;
                }
                else
                {
                  v82 = *(float *)(v79 + 40);
                }
                v2->mRunningMasterRate = v82;
              }
              (*(void (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v72 + 8i64))(v72, v2->m_Context);
              v83 = *(_QWORD *)(v72 + 24);
              if ( v83 && *(_DWORD *)(v83 + 16) == SpawnTrack::sClassNameUID )
              {
                v84 = v2->m_RunningSpawnTasksTmp[0];
                v85 = (unsigned __int64 *)(v72 + 40);
                *(_QWORD *)(v84 + 8) = v72 + 40;
                *v85 = v84;
                v85[1] = (unsigned __int64)v2->m_RunningSpawnTasksTmp;
                v2->m_RunningSpawnTasksTmp[0] = v72 + 40;
              }
            }
            v72 = v74;
          }
          while ( v74 != v33 );
        }
      }
    }
  }
  else
  {
    ActionController::Play(v2, v2->m_Context->m_OpeningBranch, 0);
    v4 = (signed __int64)&v2->m_SequencedTasks.mNode.mNext[-1].mNext;
    if ( (unsigned __int64 *)v4 != &v2->m_RunningSpawnTasksTmp[1] )
    {
      do
      {
        v5 = *(float *)(v4 + 32);
        v6 = *(_QWORD *)(v4 + 16) - 8i64;
        if ( v5 >= 0.0 && v5 <= v2->m_ActionNodePlayTime )
        {
          v7 = *(_QWORD *)(v4 + 8);
          v8 = *(_QWORD **)(v4 + 16);
          v9 = (UFG::qNode<ITask,ITask> **)(v4 + 8);
          *(_QWORD *)(v7 + 8) = v8;
          *v8 = v7;
          *v9 = (UFG::qNode<ITask,ITask> *)v9;
          v9[1] = (UFG::qNode<ITask,ITask> *)v9;
          v10 = v2->m_RunningTasks.mNode.mPrev;
          v10->mNext = (UFG::qNode<ITask,ITask> *)(v4 + 8);
          *v9 = v10;
          v9[1] = &v2->m_RunningTasks.mNode;
          v2->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v4 + 8);
          v11 = *(_QWORD *)(v4 + 24);
          if ( *(_BYTE *)(v11 + 22) )
          {
            v12 = *(_QWORD *)(v11 + 32);
            if ( v12
              && (v13 = v11 + v12 + 32) != 0
              && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v13 + 24i64))(
                    v13,
                    &v86,
                    UEL::gCurrentParameters,
                    0i64,
                    UEL::gCurrentStringBuilder),
                  v87) )
            {
              if ( v87 == 4 )
                v14 = *(float *)&v86;
              else
                v14 = (float)(signed int)v86;
            }
            else
            {
              v14 = *(float *)(v11 + 40);
            }
            v2->mRunningMasterRate = v14;
          }
          (*(void (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v4 + 8i64))(v4, v2->m_Context);
          v15 = *(_QWORD *)(v4 + 24);
          if ( v15 )
          {
            if ( *(_DWORD *)(v15 + 16) == SpawnTrack::sClassNameUID )
            {
              v16 = v2->m_RunningSpawnTasksTmp[0];
              v17 = (unsigned __int64 *)(v4 + 40);
              *(_QWORD *)(v16 + 8) = v4 + 40;
              *v17 = v16;
              v17[1] = (unsigned __int64)v2->m_RunningSpawnTasksTmp;
              v2->m_RunningSpawnTasksTmp[0] = v4 + 40;
            }
          }
        }
        v4 = v6;
      }
      while ( (unsigned __int64 *)v6 != &v2->m_RunningSpawnTasksTmp[1] );
    }
  }
}ameUID )
            {
              v16 = v2->m_RunningSpawn

// File Line: 933
// RVA: 0x275E20
__int64 __fastcall ActionController::updateTasksTimeBegin(ActionController *this, float timeDelta, bool nodeEnd)
{
  char *v3; // r12
  unsigned __int8 v4; // r15
  ActionController *v5; // rbx
  bool v6; // r14
  ActionController *v7; // rsi
  float v8; // xmm0_4
  signed __int64 v9; // rbp
  Expression::IMemberMap *v10; // rcx
  ActionNodePlayable *v11; // rax
  Expression::IMemberMap **v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rax
  ActionContext *v14; // rdi
  ActionController *v15; // rax
  signed __int64 v16; // rcx
  float v17; // xmm0_4
  ActionContext *v18; // rcx
  unsigned __int64 v19; // rax
  char *v20; // rdx
  ActionContext *v21; // rax
  char v22; // al
  __int64 v24; // [rsp+30h] [rbp-58h]
  __int16 v25; // [rsp+44h] [rbp-44h]

  v3 = (char *)&this->m_RunningSpawnTasksTmp[1];
  v4 = 0;
  v5 = (ActionController *)&this->m_SequencedTasks.mNode.mNext[-1].mNext;
  v6 = nodeEnd;
  v7 = this;
  if ( v5 != (ActionController *)&this->m_RunningSpawnTasksTmp[1] )
  {
    do
    {
      v8 = v5->m_ActionNodePlayTime;
      v9 = (signed __int64)&v5->m_currentNode[-1].mChildren.mData;
      if ( v6 )
      {
        if ( v8 < 0.0 )
          goto LABEL_7;
      }
      else if ( v8 >= 0.0 && v8 <= v7->m_ActionNodePlayTime )
      {
LABEL_7:
        v10 = v5->mResourceOwner;
        v11 = v5->m_currentNode;
        v12 = &v5->mResourceOwner;
        v10->mResourceOwner = (Expression::IMemberMap *)&v11->vfptr;
        v11->vfptr = (Expression::IMemberMapVtbl *)v10;
        v13 = v7->m_RunningTasks.mNode.mPrev;
        v13->mNext = (UFG::qNode<ITask,ITask> *)&v5->mResourceOwner;
        *v12 = (Expression::IMemberMap *)v13;
        v12[1] = (Expression::IMemberMap *)&v7->m_RunningTasks;
        v14 = v5->m_Context;
        v7->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)&v5->mResourceOwner;
        if ( BYTE6(v14->mSimObject.m_pPointer) )
        {
          v15 = v14->mActionController;
          if ( v15
            && (v16 = (signed __int64)&v14->mActionController + (_QWORD)v15) != 0
            && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v16 + 24i64))(
                  v16,
                  &v24,
                  UEL::gCurrentParameters,
                  0i64,
                  UEL::gCurrentStringBuilder),
                v25) )
          {
            if ( v25 == 4 )
              v17 = *(float *)&v24;
            else
              v17 = (float)(signed int)v24;
          }
          else
          {
            v17 = *(float *)&v14->mParentContext;
          }
          v7->mRunningMasterRate = v17;
        }
        v5->vfptr->__vecDelDtor((Expression::IMemberMap *)&v5->vfptr, (unsigned int)v7->m_Context);
        v18 = v5->m_Context;
        if ( v18 && LODWORD(v18->mSimObject.m_pPointer) == SpawnTrack::sClassNameUID )
        {
          v19 = v7->m_RunningSpawnTasksTmp[0];
          v20 = &v5->m_OnEnterExitCallbacksEnabled;
          *(_QWORD *)(v19 + 8) = (char *)v5 + 40;
          v7->m_RunningSpawnTasksTmp[0] = (unsigned __int64)&v5->m_OnEnterExitCallbacksEnabled;
          *(_QWORD *)v20 = v19;
          *((_QWORD *)v20 + 1) = (char *)v7 + 80;
        }
        if ( v6 )
          v5->vfptr->CreateClone((Expression::IMemberMap *)&v5->vfptr);
        goto LABEL_26;
      }
      v21 = v5->m_Context;
      if ( BYTE6(v21->mSimObject.m_pPointer) )
      {
        if ( v6 )
        {
          if ( *(float *)&v21->mDebugBreak < 0.0 )
          {
LABEL_29:
            v22 = 1;
            goto LABEL_25;
          }
        }
        else if ( *(float *)&v21->mDebugBreak >= 0.0 )
        {
          goto LABEL_29;
        }
      }
      v22 = 0;
LABEL_25:
      v4 |= v22;
LABEL_26:
      v5 = (ActionController *)v9;
    }
    while ( (char *)v9 != v3 );
  }
  return v4;
}

// File Line: 1049
// RVA: 0x275D30
void __fastcall ActionController::updateTasks(ActionController *this, float timeDelta)
{
  ActionNodePlayable **v2; // rbp
  ActionController *v3; // rbx
  ActionController *v4; // rsi
  float v5; // xmm6_4
  signed __int64 v6; // rdi
  Expression::IMemberMap *v7; // rdx
  ActionNodePlayable *v8; // rax
  Expression::IMemberMap **v9; // r8
  signed __int64 v10; // rcx
  signed __int64 v11; // rbx

  v2 = &this->m_SequenceNode;
  v3 = (ActionController *)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  v4 = this;
  if ( v3 != (ActionController *)&this->m_SequenceNode )
  {
    do
    {
      v5 = *(float *)&v3->mUpdating;
      v6 = (signed __int64)&v3->m_currentNode[-1].mChildren.mData;
      if ( !(unsigned __int8)v3->vfptr->CreateClone((Expression::IMemberMap *)&v3->vfptr)
        || v5 >= 0.0 && v5 <= v4->m_ActionNodePlayTime )
      {
        ((void (__fastcall *)(ActionController *))v3->vfptr->Serialize)(v3);
        v7 = v3->mResourceOwner;
        v8 = v3->m_currentNode;
        v9 = &v3->mResourceOwner;
        v7->mResourceOwner = (Expression::IMemberMap *)&v8->vfptr;
        v8->vfptr = (Expression::IMemberMapVtbl *)v7;
        *v9 = (Expression::IMemberMap *)v9;
        v9[1] = (Expression::IMemberMap *)v9;
        v3->vfptr->FindWithOldPath((Expression::IMemberMap *)&v3->vfptr, (const char *)1);
      }
      v3 = (ActionController *)v6;
    }
    while ( (ActionNodePlayable **)v6 != v2 );
  }
  v10 = (signed __int64)&v4->m_FinishUpdateTasks.mNode.mNext[-1].mNext;
  if ( (ActionController *)v10 != (ActionController *)&v4->mRunningMasterRate )
  {
    do
    {
      v11 = *(_QWORD *)(v10 + 16) - 8i64;
      (**(void (***)(void))v10)();
      v10 = v11;
    }
    while ( (ActionController *)v11 != (ActionController *)&v4->mRunningMasterRate );
  }
}

// File Line: 1138
// RVA: 0x273E10
void __fastcall ActionController::clearSequencedTasks(ActionController *this)
{
  char *v1; // rdi
  ActionController *v2; // rbx
  signed __int64 v3; // rcx
  UFG::qNode<ITask,ITask> *v4; // r8
  UFG::qNode<ITask,ITask> *v5; // rdx
  UFG::qNode<ITask,ITask> *v6; // rax

  v1 = (char *)&this->m_RunningSpawnTasksTmp[1];
  v2 = this;
  if ( (unsigned __int64 *)&this->m_SequencedTasks.mNode.mNext[-1].mNext != &this->m_RunningSpawnTasksTmp[1] )
  {
    do
    {
      v3 = (signed __int64)&v2->m_SequencedTasks.mNode.mNext[-1].mNext;
      v4 = v2->m_SequencedTasks.mNode.mNext;
      v5 = v2->m_SequencedTasks.mNode.mNext->mPrev;
      v6 = *(UFG::qNode<ITask,ITask> **)(v3 + 16);
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = v4;
      v4->mNext = v4;
      (**(void (__fastcall ***)(signed __int64, signed __int64))v3)(v3, 1i64);
    }
    while ( (char *)&v2->m_SequencedTasks.mNode.mNext[-1].mNext != v1 );
  }
}

// File Line: 1148
// RVA: 0x273C70
void __fastcall ActionController::allTasksTimeEnd(ActionController *this)
{
  ActionNodePlayable **v1; // rsi
  ActionController *v2; // rdi
  UFG::qNode<ITask,ITask> *v3; // rbx
  UFG::qNode<ITask,ITask> *v4; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax

  v1 = &this->m_SequenceNode;
  v2 = this;
  if ( (ActionNodePlayable **)&this->m_RunningTasks.mNode.mNext[-1].mNext != &this->m_SequenceNode )
  {
    do
    {
      v3 = v2->m_RunningTasks.mNode.mNext;
      ((void (__fastcall *)(UFG::qNode<ITask,ITask> **))v3[-1].mNext[1].mNext)(&v3[-1].mNext);
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, signed __int64))v3[-1].mNext->mPrev)(&v3[-1].mNext, 1i64);
    }
    while ( (ActionNodePlayable **)&v2->m_RunningTasks.mNode.mNext[-1].mNext != v1 );
  }
}

// File Line: 1188
// RVA: 0x2755C0
void __fastcall ActionController::nodeCleanup(ActionController *this)
{
  ActionNodePlayable *v1; // rdi
  ActionController *v2; // rsi
  ConditionCallback *v3; // rbx
  ActionContext *i; // rbp
  ActionNodePlayable *v5; // rdx
  ActionNodePlayable *v6; // rcx
  __int64 v7; // rax
  signed __int64 v8; // rdx
  __int64 v9; // rax
  signed __int64 v10; // rcx
  bool v11; // zf
  __int64 v12; // rax
  signed __int64 v13; // rdi
  signed __int64 v14; // rbx
  signed __int64 v15; // rbp
  __int64 v16; // rcx
  _QWORD *v17; // rax
  UFG::qNode<ITask,ITask> **v18; // rdx
  UFG::qNode<ITask,ITask> *v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rax
  signed __int64 v22; // rcx
  float v23; // xmm0_4
  __int64 v24; // rcx
  unsigned __int64 v25; // rax
  unsigned __int64 *v26; // rdx
  signed __int64 v27; // rax
  __int64 v28; // rcx
  signed __int64 v29; // rdx
  __int64 v30; // rcx
  ActionContext *j; // rax
  __int64 v32; // [rsp+30h] [rbp-48h]
  __int16 v33; // [rsp+44h] [rbp-34h]

  v1 = this->m_currentNode;
  v2 = this;
  this->mUpdating = 1;
  if ( v1 )
    this->m_previousNode = v1;
  if ( this->m_OnEnterExitCallbacksEnabled && v1 )
  {
    do
    {
      v3 = v1->mFirstCallback;
      for ( i = v2->m_Context; v3; v3 = v3->mNextCallback )
      {
        if ( v3->mType == 1 )
          ((void (__fastcall *)(fastdelegate::detail::GenericClass *, ActionNodePlayable *, ActionContext *))v3->m_CallbackDelegate.m_Closure.m_pFunction)(
            v3->m_CallbackDelegate.m_Closure.m_pthis,
            v1,
            i);
      }
      v5 = v1;
      v6 = (ActionNodePlayable *)v2->m_Context->m_OpeningBranch;
      if ( v1 == v6 )
        break;
      while ( v6 )
      {
        if ( v5->mID.mUID != v6->mID.mUID )
          goto LABEL_22;
        v7 = v5->mParent.mOffset;
        v8 = (signed __int64)&v5->mParent;
        if ( v7 )
          v5 = (ActionNodePlayable *)(v7 + v8);
        else
          v5 = 0i64;
        v9 = v6->mParent.mOffset;
        v10 = (signed __int64)&v6->mParent;
        if ( v9 )
          v6 = (ActionNodePlayable *)(v9 + v10);
        else
          v6 = 0i64;
        if ( !v5 )
        {
          v11 = v6 == 0i64;
          goto LABEL_21;
        }
      }
      v11 = v5 == 0i64;
LABEL_21:
      if ( v11 )
        break;
LABEL_22:
      v12 = v1->mParent.mOffset;
      v13 = (signed __int64)&v1->mParent;
      if ( !v12 )
        break;
      v1 = (ActionNodePlayable *)(v12 + v13);
    }
    while ( v1 );
  }
  v14 = (signed __int64)&v2->m_SequencedTasks.mNode.mNext[-1].mNext;
  if ( (unsigned __int64 *)v14 != &v2->m_RunningSpawnTasksTmp[1] )
  {
    do
    {
      v15 = *(_QWORD *)(v14 + 16) - 8i64;
      if ( *(float *)(v14 + 32) < 0.0 )
      {
        v16 = *(_QWORD *)(v14 + 8);
        v17 = *(_QWORD **)(v14 + 16);
        v18 = (UFG::qNode<ITask,ITask> **)(v14 + 8);
        *(_QWORD *)(v16 + 8) = v17;
        *v17 = v16;
        *v18 = (UFG::qNode<ITask,ITask> *)v18;
        v18[1] = (UFG::qNode<ITask,ITask> *)v18;
        v19 = v2->m_RunningTasks.mNode.mPrev;
        v19->mNext = (UFG::qNode<ITask,ITask> *)(v14 + 8);
        *v18 = v19;
        v18[1] = &v2->m_RunningTasks.mNode;
        v2->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v14 + 8);
        v20 = *(_QWORD *)(v14 + 24);
        if ( *(_BYTE *)(v20 + 22) )
        {
          v21 = *(_QWORD *)(v20 + 32);
          if ( v21
            && (v22 = v21 + v20 + 32) != 0
            && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v22 + 24i64))(
                  v22,
                  &v32,
                  UEL::gCurrentParameters,
                  0i64,
                  UEL::gCurrentStringBuilder),
                v33) )
          {
            if ( v33 == 4 )
              v23 = *(float *)&v32;
            else
              v23 = (float)(signed int)v32;
          }
          else
          {
            v23 = *(float *)(v20 + 40);
          }
          v2->mRunningMasterRate = v23;
        }
        (*(void (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v14 + 8i64))(v14, v2->m_Context);
        v24 = *(_QWORD *)(v14 + 24);
        if ( v24 && *(_DWORD *)(v24 + 16) == SpawnTrack::sClassNameUID )
        {
          v25 = v2->m_RunningSpawnTasksTmp[0];
          v26 = (unsigned __int64 *)(v14 + 40);
          *(_QWORD *)(v25 + 8) = v14 + 40;
          *v26 = v25;
          v26[1] = (unsigned __int64)v2->m_RunningSpawnTasksTmp;
          v2->m_RunningSpawnTasksTmp[0] = v14 + 40;
        }
        (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v14 + 16i64))(v14);
      }
      v14 = v15;
    }
    while ( (unsigned __int64 *)v15 != &v2->m_RunningSpawnTasksTmp[1] );
  }
  ActionController::allTasksTimeEnd(v2);
  ActionController::clearSequencedTasks(v2);
  v27 = (signed __int64)v2->m_currentNode;
  if ( v27 )
  {
    while ( 1 )
    {
      v28 = *(_QWORD *)(v27 + 16);
      if ( !v28 )
        break;
      v29 = v28 + v27 + 16;
      if ( !v29 )
        break;
      v30 = *(unsigned int *)(v27 + 32);
      if ( (_DWORD)v30 != -1 )
      {
        for ( j = v2->m_Context; j; j = j->mParentContext )
          --j->mMostUsedPlayCount[v30];
      }
      v27 = v29;
    }
  }
  v2->m_currentNode = 0i64;
  v2->m_NumPlayingNodes = 0;
  v2->m_PlayingMostUsedMask = 0i64;
  v2->mOverRideNode = 0;
  v2->m_ActionNodePlayTime = 0.0;
  v2->mUpdating = 0;
  v2->m_SequencePriority = -1;
}

// File Line: 1269
// RVA: 0x26F310
char __fastcall ActionController::IsPlaying(ActionController *this, ActionNode *node)
{
  ActionNodePlayable *v2; // rax
  __int64 v3; // rcx

  v2 = this->m_currentNode;
  if ( v2 )
  {
    while ( 1 )
    {
      v3 = v2->mParent.mOffset;
      if ( !v3 || !(UFG::qOffset64<ActionNode *> *)((char *)&v2->mParent + v3) )
        break;
      if ( node == (ActionNode *)v2 )
        return 1;
      v2 = (ActionNodePlayable *)((char *)v2 + v3 + 16);
    }
  }
  return 0;
}

// File Line: 1297
// RVA: 0x1488310
__int64 dynamic_initializer_for__gPlayEntries__()
{
  return atexit(dynamic_atexit_destructor_for__gPlayEntries__);
}

// File Line: 1368
// RVA: 0x26F170
unsigned __int8 __fastcall ActionController::IsPlaying(ActionController *this, ActionID *node_id, unsigned int mostUsedIndex, const bool recurseOnSpawns)
{
  unsigned int v4; // ebx
  ActionController *v5; // r10
  unsigned __int8 result; // al
  unsigned __int64 v7; // rax
  unsigned int v8; // edx
  unsigned int v9; // ecx
  ActionID *v10; // rax
  signed __int64 v11; // r11
  signed __int64 v12; // rdx
  unsigned int v13; // esi
  unsigned int v14; // edi
  signed __int64 v15; // r9
  signed __int64 v16; // r10
  signed __int64 v17; // rcx
  signed __int64 v18; // r8
  __int64 v19; // rax
  __int64 v20; // rax
  unsigned int v21; // er8
  unsigned int v22; // ecx
  _DWORD *v23; // rax
  __m128i v24[32]; // [rsp+0h] [rbp-208h]

  v4 = node_id->mUID;
  v5 = this;
  if ( mostUsedIndex == -1 )
  {
    v8 = this->m_NumPlayingNodes;
    v9 = 0;
    if ( v8 )
    {
      v10 = v5->m_PlayingNodeUID;
      while ( v10->mUID != v4 )
      {
        ++v9;
        ++v10;
        if ( v9 >= v8 )
          goto LABEL_9;
      }
      result = 1;
    }
    else
    {
LABEL_9:
      if ( recurseOnSpawns
        && (v11 = (signed __int64)&v5->m_OnEnterExitCallbacksEnabled,
            v12 = v5->m_RunningSpawnTasksTmp[1] - 40,
            (char *)v12 != &v5->m_OnEnterExitCallbacksEnabled) )
      {
        v13 = 1;
        _mm_store_si128(v24, (__m128i)0i64);
        if ( v12 )
        {
          v14 = 0;
          while ( 1 )
          {
            v15 = v12 + 288;
            v16 = v12 + 328;
            v17 = *(_QWORD *)(v12 + 376) - 40i64;
            if ( v17 == v12 + 328 )
            {
              v12 = *(_QWORD *)(v12 + 48) - 40i64;
              if ( v12 == v11 )
              {
                --v13;
                v20 = v14--;
                v12 = v24[v20].m128i_i64[0];
                v11 = v24[v20].m128i_i64[1];
              }
            }
            else
            {
              v18 = *(_QWORD *)(v12 + 48) - 40i64;
              if ( v18 != v11 )
              {
                v19 = v13++;
                v19 *= 16i64;
                ++v14;
                *(__int64 *)((char *)v24[0].m128i_i64 + v19) = v18;
                *(__int64 *)((char *)&v24[0].m128i_i64[1] + v19) = v11;
              }
              v12 = v17;
              v11 = v16;
            }
            v21 = *(_DWORD *)(v15 + 144);
            v22 = 0;
            if ( v21 )
              break;
LABEL_24:
            if ( !v12 )
              return 0;
          }
          v23 = (_DWORD *)(v15 + 148);
          while ( *v23 != v4 )
          {
            ++v22;
            ++v23;
            if ( v22 >= v21 )
              goto LABEL_24;
          }
          result = 1;
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
    }
  }
  else if ( recurseOnSpawns )
  {
    result = this->m_Context->mMostUsedPlayCount[mostUsedIndex] != 0;
  }
  else
  {
    v7 = this->m_PlayingMostUsedMask;
    result = _bittest64((const signed __int64 *)&v7, mostUsedIndex);
  }
  return result;
}

// File Line: 1615
// RVA: 0x26F400
char __fastcall ActionController::IsPlayingFullPath(ActionController *this, ActionNode *testNode, const bool recurseOnSpawns)
{
  ActionNodePlayable *v3; // rax
  ActionController *v4; // r10
  unsigned int v5; // ebp
  unsigned int v6; // edi
  signed __int64 v7; // r14
  unsigned int v8; // esi
  __int64 v9; // rcx
  signed __int64 v11; // rbx
  signed __int64 v12; // r9
  signed __int64 v13; // r10
  signed __int64 v14; // r11
  signed __int64 v15; // rcx
  signed __int64 v16; // r8
  __int64 v17; // rax
  __int64 v18; // rax
  ActionNode *v19; // rax
  __int64 v20; // rcx
  __int128 v21[32]; // [rsp+0h] [rbp-208h]

  v3 = this->m_currentNode;
  v4 = this;
  if ( testNode )
    v5 = testNode->mMostUsedIndex;
  else
    v5 = -1;
  v6 = 0;
  v7 = 0i64;
  v8 = 1;
  if ( v5 == -1 || (v7 = 1i64 << v5, (1i64 << v5) & this->m_PlayingMostUsedMask) )
  {
    if ( v3 )
    {
      while ( 1 )
      {
        v9 = v3->mParent.mOffset;
        if ( !v9 || !(UFG::qOffset64<ActionNode *> *)((char *)&v3->mParent + v9) )
          break;
        if ( (unsigned int)testNode >= (unsigned int)v3 )
        {
          if ( testNode == (ActionNode *)v3 )
            return 1;
          if ( (unsigned int)testNode > (unsigned int)v3 )
            break;
        }
        v3 = (ActionNodePlayable *)((char *)v3 + v9 + 16);
      }
    }
  }
  if ( !recurseOnSpawns )
    return 0;
  v11 = (signed __int64)&v4->m_OnEnterExitCallbacksEnabled;
  v12 = v4->m_RunningSpawnTasksTmp[1] - 40;
  if ( (char *)v12 != &v4->m_OnEnterExitCallbacksEnabled )
  {
    _mm_store_si128((__m128i *)v21, (__m128i)0i64);
    while ( v12 )
    {
      v13 = v12 + 288;
      v14 = v12 + 328;
      v15 = *(_QWORD *)(v12 + 376) - 40i64;
      if ( v15 == v12 + 328 )
      {
        v12 = *(_QWORD *)(v12 + 48) - 40i64;
        if ( v12 == v11 )
        {
          --v8;
          v18 = v6--;
          v12 = *(_QWORD *)&v21[v18];
          v11 = *((_QWORD *)&v21[v18] + 1);
        }
      }
      else
      {
        v16 = *(_QWORD *)(v12 + 48) - 40i64;
        if ( v16 != v11 )
        {
          v17 = v8++;
          v17 *= 16i64;
          ++v6;
          *(_QWORD *)((char *)v21 + v17) = v16;
          *(_QWORD *)((char *)v21 + v17 + 8) = v11;
        }
        v12 = v15;
        v11 = v14;
      }
      if ( v5 == -1 || v7 & *(_QWORD *)(v13 + 136) )
      {
        v19 = *(ActionNode **)(v13 + 16);
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
bool __fastcall ActionController::IsPlayingFullPath(ActionController *this, ActionPath *animPath, const bool recurseOnSpawns)
{
  ActionController *v3; // r15
  ActionNode *v4; // rcx
  unsigned int v5; // ebx
  bool v6; // bp
  ActionPath *v7; // r14
  unsigned int v8; // edi
  signed __int64 v9; // rsi
  __int64 v10; // rax
  signed __int64 v11; // rdx
  int v13; // [rsp+48h] [rbp+10h]

  v3 = this;
  v4 = 0i64;
  v5 = animPath->mPath.mCount & 0x7FFFFFFF;
  v6 = recurseOnSpawns;
  v7 = animPath;
  if ( v5 > 1 )
  {
    v4 = ActionNode::smRoot;
    v8 = 1;
    if ( v5 > 1 )
    {
      v9 = 4i64;
      do
      {
        if ( !v4 )
          break;
        v10 = v7->mPath.mData.mOffset;
        v11 = (signed __int64)(v10 ? (UFG::qOffset64<ActionID *> *)((char *)&v7->mPath.mData + v10) : 0i64);
        v13 = *(_DWORD *)(v9 + v11);
        ++v8;
        v9 += 4i64;
        v4 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v4->vfptr[1].CreateClone)(
                             v4,
                             &v13,
                             0i64);
      }
      while ( v8 < v5 );
    }
  }
  return ActionController::IsPlayingFullPath(v3, v4, v6);
}

// File Line: 1796
// RVA: 0x26F130
UFG::qNode<ITask,ITask> **__fastcall ActionController::IsPlaying(ActionController *this, ITrack *track)
{
  ActionNodePlayable **v2; // r9
  UFG::qNode<ITask,ITask> **v3; // r8
  bool i; // zf
  ITrack *v5; // rcx
  signed __int64 v6; // rax

  v2 = &this->m_SequenceNode;
  v3 = &this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = v3 == (UFG::qNode<ITask,ITask> **)&this->m_SequenceNode; !i; i = v6 == (_QWORD)v2 )
  {
    v5 = (ITrack *)v3[3];
    v6 = (signed __int64)&v3[2][-1].mNext;
    if ( v5 && track == v5 )
      return v3;
    v3 = &v3[2][-1].mNext;
  }
  return 0i64;
}

// File Line: 1813
// RVA: 0x273AB0
char __fastcall ActionController::WasPlaying(ActionController *this, ActionID *animID, const bool recurseOnSpawns)
{
  bool v3; // si
  ActionID *v4; // rbp
  ActionController *v5; // rdi
  ActionNodePlayable *v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rax
  char result; // al
  unsigned __int64 v10; // rcx
  signed __int64 v11; // rdi
  signed __int64 v12; // rcx
  signed __int64 v13; // rbx

  v3 = recurseOnSpawns;
  v4 = animID;
  v5 = this;
  if ( this->m_ActionNodePlayTime == 0.0 && (v6 = this->m_previousNode) != 0i64 )
  {
    while ( v6->mID.mUID != animID->mUID )
    {
      v7 = v6->mParent.mOffset;
      v8 = (signed __int64)&v6->mParent;
      if ( v7 )
      {
        v6 = (ActionNodePlayable *)(v7 + v8);
        if ( v6 )
          continue;
      }
      goto LABEL_6;
    }
    result = 1;
  }
  else
  {
LABEL_6:
    if ( recurseOnSpawns )
    {
      v10 = v5->m_RunningSpawnTasksTmp[1];
      v11 = (signed __int64)&v5->m_OnEnterExitCallbacksEnabled;
      v12 = v10 - 40;
      if ( v12 == v11 )
      {
LABEL_12:
        result = 0;
      }
      else
      {
        while ( 1 )
        {
          v13 = *(_QWORD *)(v12 + 48) - 40i64;
          if ( ActionController::WasPlaying((ActionController *)(v12 + 288), v4, v3) )
            break;
          v12 = v13;
          if ( v13 == v11 )
            goto LABEL_12;
        }
        result = 1;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 1857
// RVA: 0x273B90
char __fastcall ActionController::WasPlayingFullPath(ActionController *this, ActionNode *testNode)
{
  ActionNodePlayable *v2; // rax
  __int64 v3; // rcx

  if ( this->m_ActionNodePlayTime == 0.0 )
  {
    v2 = this->m_previousNode;
    if ( v2 )
    {
      while ( 1 )
      {
        v3 = v2->mParent.mOffset;
        if ( !v3 || !(UFG::qOffset64<ActionNode *> *)((char *)&v2->mParent + v3) )
          break;
        if ( (unsigned int)testNode >= (unsigned int)v2 )
        {
          if ( testNode == (ActionNode *)v2 )
            return 1;
          if ( (unsigned int)testNode > (unsigned int)v2 )
            return 0;
        }
        v2 = (ActionNodePlayable *)((char *)v2 + v3 + 16);
      }
    }
  }
  return 0;
}

// File Line: 2079
// RVA: 0x26E5B0
void __fastcall ActionController::GetDebugString(ActionController *this, UFG::qStringBuilder *debugStringBuilder, const bool bShowAllTracks, ActionController *pControllerToHighlight, ITrack *pTrackToHighlight)
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
void __fastcall ActionController::writeDebugDisplayToString(ActionController *this, UFG::qStringBuilder *debugStringBuilder, const bool bShowAllTracks, ActionController *pControllerToHighlight, ITrack *pTrackToHighlight, const int indentSpaces, ITask *pParentTask)
{
  bool v7; // bl
  UFG::qStringBuilder *v8; // rdi
  ActionController *v9; // rsi
  ActionNode *v10; // rcx
  int v11; // ebp
  float v12; // xmm6_4
  char *v13; // rax
  unsigned int v14; // ebx
  const char *v15; // rdx
  signed __int64 v16; // rbx
  __int64 v17; // rdi
  bool v18; // bp
  bool v19; // si
  UFG::qStringBuilder *v20; // rdi
  int v21; // [rsp+40h] [rbp-88h]
  ActionPath pathToPopulate; // [rsp+50h] [rbp-78h]
  UFG::qString v23; // [rsp+60h] [rbp-68h]
  bool v24; // [rsp+D0h] [rbp+8h]
  signed __int64 i; // [rsp+D0h] [rbp+8h]
  UFG::qStringBuilder *debugStringBuildera; // [rsp+D8h] [rbp+10h]
  bool v27; // [rsp+E0h] [rbp+18h]
  ActionController *pControllerToHighlighta; // [rsp+E8h] [rbp+20h]

  pControllerToHighlighta = pControllerToHighlight;
  v27 = bShowAllTracks;
  debugStringBuildera = debugStringBuilder;
  v7 = bShowAllTracks;
  v8 = debugStringBuilder;
  v9 = this;
  v24 = this == pControllerToHighlight;
  v21 = 0;
  if ( this == pControllerToHighlight )
  {
    UFG::qString::qString(&v23, "=>");
    UFG::qStringBuilder::Add(v8, v23.mData, -1);
    v21 = v23.mLength;
    UFG::qString::~qString(&v23);
  }
  pathToPopulate.mPath.mCount = 0;
  pathToPopulate.mPath.mData.mOffset = 0i64;
  if ( pParentTask
    && InvokeBehaviourTrack::sClassNameUID == ((unsigned int (*)(void))pParentTask->m_Track->vfptr->GetClassNameUID)() )
  {
    v11 = indentSpaces;
  }
  else
  {
    v10 = (ActionNode *)&v9->m_currentNode->vfptr;
    if ( !v10 )
    {
      UFG::qStringBuilder::Format(
        v8,
        "%*s%s:%0.3f@%0.3f\n",
        (unsigned int)indentSpaces,
        &customWorldMapCaption,
        "NULL",
        v9->m_ActionNodePlayTime,
        v9->mRunningMasterRate);
      goto LABEL_30;
    }
    ActionNode::GetNameFullPath(v10, &pathToPopulate);
    v11 = indentSpaces;
    v12 = v9->mRunningMasterRate;
    v13 = ActionPath::GetString_DBG(&pathToPopulate);
    v14 = indentSpaces - v21;
    if ( indentSpaces - v21 < 0 )
      v14 = 0;
    UFG::qStringBuilder::Format(
      v8,
      "%*s%s:%0.3f@%0.3f",
      v14,
      &customWorldMapCaption,
      v13,
      v9->m_ActionNodePlayTime,
      v12);
    v7 = v27;
  }
  v15 = " <=\n";
  if ( !v24 )
    v15 = "\n";
  UFG::qStringBuilder::Add(v8, v15, -1);
  if ( v7 )
    indentSpaces = sSpacesPerTrackIndent + v11;
  v16 = (signed __int64)&v9->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = (signed __int64)&v9->m_SequenceNode; v16 != i; v16 = *(_QWORD *)(v16 + 16) - 8i64 )
  {
    v17 = *(_QWORD *)(v16 + 24);
    v18 = InvokeBehaviourTrack::sClassNameUID == (*(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)v17 + 40i64))(*(_QWORD *)(v16 + 24));
    v19 = SpawnTrack::sClassNameUID == (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v17 + 40i64))(v17) || v18;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 40i64))(v17);
    if ( v19 || v27 )
    {
      if ( v18 || v17 != (_QWORD)pTrackToHighlight )
      {
        v20 = debugStringBuildera;
      }
      else
      {
        UFG::qString::qString(&v23, "=>");
        v20 = debugStringBuildera;
        UFG::qStringBuilder::Add(debugStringBuildera, v23.mData, -1);
        UFG::qString::~qString(&v23);
      }
      if ( v19 )
        ActionController::writeDebugDisplayToString(
          (ActionController *)(v16 + 288),
          v20,
          v27,
          pControllerToHighlighta,
          pTrackToHighlight,
          indentSpaces + sSpacesPerIndent,
          (ITask *)v16);
    }
  }
LABEL_30:
  if ( pathToPopulate.mPath.mCount >= 0 && pathToPopulate.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
      operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
  }
}ata.mOffset) )
      operator delete[]((

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
  return atexit(dynamic_atexit_destructor_for__gActionControllerFactory__);
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
  ActionNodePlayable **v1; // r10
  __int64 result; // rax
  UFG::qNode<ITask,ITask> **v3; // rdx
  bool i; // cl
  UFG::qNode<ITask,ITask> *v5; // rcx

  v1 = &this->m_SequenceNode;
  result = 0i64;
  v3 = &this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = v3 == (UFG::qNode<ITask,ITask> **)&this->m_SequenceNode; v3; i = v3 == (UFG::qNode<ITask,ITask> **)v1 )
  {
    if ( i )
      break;
    v5 = v3[3];
    if ( gReflectAllActionTreeTasks || v5 && SpawnTrack::sClassNameUID == LODWORD(v5[1].mPrev) )
      result = (unsigned int)(result + 1);
    v3 = &v3[2][-1].mNext;
  }
  return result;
}

// File Line: 2371
// RVA: 0x26E100
UFG::qNode<ITask,ITask> *__fastcall ActionController::GetChild2(ActionController *this, int priority)
{
  ActionNodePlayable **v2; // r11
  int v3; // er8
  UFG::qNode<ITask,ITask> **v4; // rax
  bool i; // cl
  UFG::qNode<ITask,ITask> *v6; // rcx

  v2 = &this->m_SequenceNode;
  v3 = 0;
  v4 = &this->m_RunningTasks.mNode.mNext[-1].mNext;
  for ( i = v4 == (UFG::qNode<ITask,ITask> **)&this->m_SequenceNode; v4; i = v4 == (UFG::qNode<ITask,ITask> **)v2 )
  {
    if ( i )
      return 0i64;
    v6 = v4[3];
    if ( gReflectAllActionTreeTasks )
    {
      if ( priority == v3 && v6 )
      {
        if ( SpawnTrack::sClassNameUID == LODWORD(v6[1].mPrev) )
          return (UFG::qNode<ITask,ITask> *)(v4 + 36);
        return v4[3];
      }
    }
    else
    {
      if ( !v6 || SpawnTrack::sClassNameUID != LODWORD(v6[1].mPrev) )
        goto LABEL_12;
      if ( priority == v3 )
        return (UFG::qNode<ITask,ITask> *)(v4 + 36);
    }
    ++v3;
LABEL_12:
    v4 = &v4[2][-1].mNext;
  }
  return 0i64;
}

