// File Line: 36
// RVA: 0x14AEC90
__int64 dynamic_initializer_for__UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList__);
}

// File Line: 37
// RVA: 0x3633F0
const char *__fastcall UFG::StimulusReceiverComponent::GetTypeName(UFG::StimulusReceiverComponent *this)
{
  return "StimulusReceiverComponent";
}

// File Line: 42
// RVA: 0x332330
void __fastcall UFG::StimulusReceiverComponent::StimulusReceiverComponent(UFG::StimulusReceiverComponent *this, unsigned int name_uid)
{
  UFG::StimulusReceiverComponent *v2; // rbx
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v3; // rdx
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v4; // rax
  signed int v5; // eax
  UFG::qList<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback,1,0> *v6; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusReceiverComponent::`vftable';
  v2->m_pRegisteredStimulusCookie = 0i64;
  v2->m_StimulusRegistered.mBits[0] = 0i64;
  v2->m_StimulusRegistered.mBits[1] = 0i64;
  v6 = &v2->m_OnPerceivedNotifyList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v4 = UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mPrev;
  UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *)&UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList;
  UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mPrev = (UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::StimulusReceiverComponent::_StimulusReceiverComponentTypeUID,
    "StimulusReceiverComponent");
  v2->m_DebugDraw = 0;
  *(_WORD *)&v2->m_NumStimuliRegistered = 0;
  v2->m_StimulusRegistered.mBits[0] = 0i64;
  v2->m_StimulusRegistered.mBits[1] = 0i64;
  UFG::qMemSet(v2->m_pReceivedStimulusInfo, 0, 0x3A0u);
  v2->m_LastTimePerceivedAnyStimulus = -99999.0;
  v5 = once_9;
  if ( !once_9 )
    v5 = 1;
  once_9 = v5;
}

// File Line: 64
// RVA: 0x33B430
void __fastcall UFG::StimulusReceiverComponent::~StimulusReceiverComponent(UFG::StimulusReceiverComponent *this)
{
  UFG::StimulusReceiverComponent *v1; // rsi
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v2; // rdi
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v3; // rcx
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v4; // rax
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v5; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v6; // rax
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v7; // rcx
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusReceiverComponent::`vftable';
  if ( this == UFG::StimulusReceiverComponent::s_StimulusReceiverComponentpCurrentIterator )
    UFG::StimulusReceiverComponent::s_StimulusReceiverComponentpCurrentIterator = (UFG::StimulusReceiverComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::StimulusReceiverComponent::UnrequestAllStimuli(v1);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_OnPerceivedNotifyList);
  v5 = v1->m_OnPerceivedNotifyList.mNode.mPrev;
  v6 = v1->m_OnPerceivedNotifyList.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_OnPerceivedNotifyList.mNode.mPrev = &v1->m_OnPerceivedNotifyList.mNode;
  v1->m_OnPerceivedNotifyList.mNode.mNext = &v1->m_OnPerceivedNotifyList.mNode;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 72
// RVA: 0x37F270
UFG::qPropertySet *__fastcall UFG::StimulusReceiverComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *result; // rax
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::StimulusReceiverComponent *v7; // rax
  UFG::StimulusReceiverComponent *v8; // rdi
  UFG::SimObject *v9; // rdx
  unsigned __int16 v10; // cx
  unsigned int v11; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  if ( required )
    goto LABEL_15;
  v3 = pSceneObj->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  result = UFG::qPropertySet::GetParentFromName(
             v3,
             (UFG::qSymbol *)&SimSymX_propset_componentStimulusReceiver.mUID,
             DEPTH_RECURSE);
  if ( result )
  {
LABEL_15:
    v5 = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(v5, 0x428ui64, "StimulusReceiverComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::StimulusReceiverComponent::StimulusReceiverComponent((UFG::StimulusReceiverComponent *)v6, v2->m_NameUID);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = v2->m_pSimObject;
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 || (v10 & 0x8000u) != 0 )
      v11 = 11;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v12, v9, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, (UFG::SimComponent *)&v8->vfptr, v11);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    result = (UFG::qPropertySet *)v8;
  }
  return result;
}

// File Line: 90
// RVA: 0x3794B0
void __fastcall UFG::StimulusReceiverComponent::OnAttach(UFG::StimulusReceiverComponent *this, UFG::SimObject *object)
{
  UFG::StimulusReceiverComponent *v2; // rbx
  hkSeekableStreamReader *v3; // [rsp+30h] [rbp-18h]
  void (__fastcall *v4)(UFG::StimulusReceiverComponent *, UFG::Event *); // [rsp+38h] [rbp-10h]

  v2 = this;
  v4 = UFG::StimulusReceiverComponent::HandleStimulus;
  v3 = Assembly::GetRCX(this);
  v2->m_pRegisteredStimulusCookie = (struct UFG::EventHandlerCookieTag *)UFG::EventDispatcher::Register(
                                                                           &UFG::EventDispatcher::mInstance,
                                                                           (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
                                                                           UFG::g_StimulusEventHash,
                                                                           0i64,
                                                                           0);
}

// File Line: 105
// RVA: 0x37B2D0
void __fastcall UFG::StimulusReceiverComponent::OnDetach(UFG::StimulusReceiverComponent *this)
{
  UFG::StimulusReceiverComponent *v1; // rbx
  struct UFG::EventHandlerCookieTag *v2; // rdx

  v1 = this;
  UFG::StimulusReceiverComponent::UnrequestAllStimuli(this);
  UFG::StimulusReceiverComponent::DeregisterCallbacks(v1);
  v2 = v1->m_pRegisteredStimulusCookie;
  if ( v2 )
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v2, UFG::g_StimulusEventHash);
}

// File Line: 132
// RVA: 0x38AF90
void __fastcall UFG::StimulusReceiverComponent::UnrequestAllStimuli(UFG::StimulusReceiverComponent *this)
{
  signed __int64 v1; // rbx
  UFG::StimulusReceiverComponent *v2; // rdi
  signed __int64 v3; // r15
  __int64 v4; // r14
  UFG::ReceivedStimulusInfo **v5; // rsi
  UFG::ReceivedStimulusInfo *v6; // rbp

  v1 = 1i64;
  v2 = this;
  v3 = 116i64;
  v4 = 0i64;
  v5 = this->m_pReceivedStimulusInfo;
  do
  {
    if ( v1 & v2->m_StimulusRegistered.mBits[v4 >> 6] )
    {
      v2->m_StimulusRegistered.mBits[v4 >> 6] &= ~v1;
      --v2->m_NumStimuliRegistered;
    }
    v6 = *v5;
    if ( *v5 )
    {
      UFG::ReceivedStimulusInfo::~ReceivedStimulusInfo(*v5);
      operator delete[](v6);
      *v5 = 0i64;
      --v2->m_NumStimuliAllocated;
    }
    v1 = __ROL8__(v1, 1);
    ++v4;
    ++v5;
    --v3;
  }
  while ( v3 );
}

// File Line: 140
// RVA: 0x382610
void __fastcall UFG::StimulusReceiverComponent::RequestToReceiveStimulus(UFG::StimulusReceiverComponent *this, UFG::eStimulusType stimulus_type)
{
  signed __int64 v2; // rax
  char v3; // dl
  char v4; // cl

  v2 = (signed __int64)(signed int)stimulus_type >> 6;
  if ( !((1i64 << (stimulus_type & 0x3F)) & this->m_StimulusRegistered.mBits[v2]) )
  {
    this->m_StimulusRegistered.mBits[v2] |= 1i64 << (stimulus_type & 0x3F);
    v3 = ++this->m_NumStimuliRegistered;
    v4 = UFG::StimulusReceiverComponent::s_MaxStimuliRegistered;
    if ( UFG::StimulusReceiverComponent::s_MaxStimuliRegistered <= v3 )
      v4 = v3;
    UFG::StimulusReceiverComponent::s_MaxStimuliRegistered = v4;
  }
}

// File Line: 171
// RVA: 0x380B10
void __fastcall UFG::StimulusReceiverComponent::RegisterNotifyCallback(UFG::StimulusReceiverComponent *this, UFG::StimulusNotifyCallback *callback)
{
  __int64 v2; // r9
  UFG::StimulusNotifyCallback *v3; // r10
  UFG::StimulusReceiverComponent *v4; // r8
  char v5; // dl
  char v6; // cl
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v7; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v8; // rax

  v2 = callback->m_type;
  v3 = callback;
  v4 = this;
  if ( (_DWORD)v2 && !((1i64 << (v2 & 0x3F)) & this->m_StimulusRegistered.mBits[v2 >> 6]) )
  {
    this->m_StimulusRegistered.mBits[v2 >> 6] |= 1i64 << (v2 & 0x3F);
    v5 = ++this->m_NumStimuliRegistered;
    v6 = UFG::StimulusReceiverComponent::s_MaxStimuliRegistered;
    if ( UFG::StimulusReceiverComponent::s_MaxStimuliRegistered <= v5 )
      v6 = v5;
    UFG::StimulusReceiverComponent::s_MaxStimuliRegistered = v6;
  }
  v7 = (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)&v3->mPrev;
  v8 = v4->m_OnPerceivedNotifyList.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)&v3->mPrev;
  v7->mPrev = v8;
  v7->mNext = &v4->m_OnPerceivedNotifyList.mNode;
  v4->m_OnPerceivedNotifyList.mNode.mPrev = (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)&v3->mPrev;
}

// File Line: 200
// RVA: 0x352150
void __fastcall UFG::StimulusReceiverComponent::DeregisterCallbacks(UFG::StimulusReceiverComponent *this)
{
  char *v1; // rsi
  UFG::StimulusReceiverComponent *v2; // rbx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v3; // rdx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v4; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v5; // rax
  signed __int64 v6; // rdi

  v1 = (char *)&this->m_pReceivedStimulusInfo[115];
  v2 = this;
  if ( (UFG::ReceivedStimulusInfo **)&this->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext != &this->m_pReceivedStimulusInfo[115] )
  {
    do
    {
      v3 = v2->m_OnPerceivedNotifyList.mNode.mNext;
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v6 = (signed __int64)&v3[-1].mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      (*(void (__fastcall **)(UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *, UFG::StimulusReceiverComponent *, _QWORD, signed __int64))(v6 + 40))(
        v3[1].mNext,
        v2,
        0i64,
        v6);
      (**(void (__fastcall ***)(signed __int64, signed __int64))v6)(v6, 1i64);
    }
    while ( (char *)&v2->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext != v1 );
  }
}

// File Line: 241
// RVA: 0x364CB0
void __fastcall UFG::StimulusReceiverComponent::HandleStimulus(UFG::StimulusReceiverComponent *this, UFG::Event *this_event)
{
  UFG::Stimulus *v2; // rbx
  UFG::StimulusReceiverComponent *v3; // rdi

  v2 = (UFG::Stimulus *)this_event;
  v3 = this;
  if ( this->m_StimulusRegistered.mBits[0] | this->m_StimulusRegistered.mBits[1] | (_QWORD)this_event[3].mPrev | (_QWORD)this_event[3].mNext
    && (!LOBYTE(this_event[6].mUserData0)
     || this_event[7].mPrev == (UFG::qNode<UFG::Event,UFG::Event> *)this->m_pSimObject) )
  {
    UFG::StimulusReceiverComponent::SetLastTimeReceived(this, (UFG::Stimulus *)this_event);
    if ( UFG::StimulusReceiverComponent::CheckIfPerceived(v3, v2) )
      UFG::StimulusReceiverComponent::SetLastTimePerceived(v3, v2);
  }
}

// File Line: 441
// RVA: 0x387010
void __fastcall UFG::StimulusReceiverComponent::SetLastTimePerceived(UFG::StimulusReceiverComponent *this, UFG::Stimulus *stimulus)
{
  __int64 v2; // rbx
  UFG::Stimulus *v3; // rbp
  UFG::StimulusReceiverComponent *v4; // rsi
  UFG::ReceivedStimulusInfo *v5; // rdx
  UFG::SimObject *v6; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  signed __int64 v11; // rbx
  signed __int64 v12; // rdi
  int v13; // eax
  __int64 v14; // rcx
  _QWORD *v15; // rax
  _QWORD *v16; // rdx

  v2 = stimulus->m_Description.m_Type;
  v3 = stimulus;
  v4 = this;
  UFG::StimulusReceiverComponent::MaybeCreateReceivedStimulusInfo(this, stimulus->m_Description.m_Type);
  v5 = v4->m_pReceivedStimulusInfo[v2];
  if ( v5 )
  {
    v6 = v3->m_pStimulusProducer.m_pPointer;
    v7 = &v5->m_LastTimePerceived.m_pProducer;
    *(float *)&v7[-1].m_pPointer = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v7->m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v7->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v7->m_pPointer = v6;
    if ( v6 )
    {
      v10 = v6->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v7->mNext = &v6->m_SafePointerList.mNode;
      v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v4->m_LastTimePerceivedAnyStimulus = v4->m_pReceivedStimulusInfo[v2]->m_LastTimePerceived.m_Time;
    if ( (UFG::ReceivedStimulusInfo **)&v4->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext != &v4->m_pReceivedStimulusInfo[115] )
    {
      v11 = (signed __int64)&v4->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext;
      do
      {
        v12 = v11;
        v13 = *(_DWORD *)(v11 + 24);
        v11 = *(_QWORD *)(v11 + 16) - 8i64;
        if ( !v13 || v13 == v3->m_Description.m_Type )
        {
          if ( (*(unsigned __int8 (__fastcall **)(_QWORD, UFG::StimulusReceiverComponent *, UFG::Stimulus *, signed __int64))(v12 + 40))(
                 *(_QWORD *)(v12 + 32),
                 v4,
                 v3,
                 v12) )
          {
            v14 = *(_QWORD *)(v12 + 8);
            v15 = *(_QWORD **)(v12 + 16);
            v16 = (_QWORD *)(v12 + 8);
            *(_QWORD *)(v14 + 8) = v15;
            *v15 = v14;
            *v16 = v16;
            v16[1] = v16;
            if ( v12 )
              (**(void (__fastcall ***)(signed __int64, signed __int64))v12)(v12, 1i64);
          }
        }
      }
      while ( (UFG::ReceivedStimulusInfo **)v11 != &v4->m_pReceivedStimulusInfo[115] );
    }
  }
}

// File Line: 492
// RVA: 0x374CE0
void __fastcall UFG::StimulusReceiverComponent::MaybeCreateReceivedStimulusInfo(UFG::StimulusReceiverComponent *this, UFG::eStimulusType stimulus_type)
{
  UFG::StimulusReceiverComponent *v2; // rbx
  __int64 v3; // rdi
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::ReceivedStimulusInfo *v6; // rcx
  UFG::allocator::free_link *v7; // rax
  char v8; // cl
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // [rsp+58h] [rbp+20h]

  v2 = this;
  v3 = stimulus_type;
  v4 = this->m_StimulusRegistered.mBits[(signed __int64)(signed int)stimulus_type >> 6];
  if ( _bittest64((const signed __int64 *)&v4, stimulus_type & 0x3F) && !this->m_pReceivedStimulusInfo[stimulus_type] )
  {
    v5 = UFG::qMalloc(0x40ui64, "ReceivedStimulusInfo", 0i64);
    v6 = (UFG::ReceivedStimulusInfo *)v5;
    if ( v5 )
    {
      v7 = v5 + 1;
      v7->mNext = v7;
      v7[1].mNext = v7;
      v7[2].mNext = 0i64;
      v9 = &v6->m_LastTimePerceived.m_pProducer;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v6->m_LastTimePerceived.m_pProducer.m_pPointer = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    v2->m_pReceivedStimulusInfo[v3] = v6;
    UFG::ReceivedStimulusInfo::Clear(v6);
    ++v2->m_NumStimuliAllocated;
    v8 = UFG::StimulusReceiverComponent::s_MaxStimuliAllocated;
    if ( UFG::StimulusReceiverComponent::s_MaxStimuliAllocated <= v2->m_NumStimuliAllocated )
      v8 = v2->m_NumStimuliAllocated;
    UFG::StimulusReceiverComponent::s_MaxStimuliAllocated = v8;
  }
}

// File Line: 512
// RVA: 0x387160
void __fastcall UFG::StimulusReceiverComponent::SetLastTimeReceived(UFG::StimulusReceiverComponent *this, UFG::Stimulus *stimulus)
{
  __int64 v2; // rbx
  UFG::Stimulus *v3; // rsi
  UFG::StimulusReceiverComponent *v4; // rdi
  UFG::ReceivedStimulusInfo *v5; // rdx
  UFG::SimObject *v6; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = stimulus->m_Description.m_Type;
  v3 = stimulus;
  v4 = this;
  UFG::StimulusReceiverComponent::MaybeCreateReceivedStimulusInfo(this, stimulus->m_Description.m_Type);
  v5 = v4->m_pReceivedStimulusInfo[v2];
  if ( v5 )
  {
    v6 = v3->m_pStimulusProducer.m_pPointer;
    v7 = &v5->m_LastTimeReceived.m_pProducer;
    *(float *)&v7[-1].m_pPointer = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v7->m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v7->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v7->m_pPointer = v6;
    if ( v6 )
    {
      v10 = v6->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v7->mNext = &v6->m_SafePointerList.mNode;
      v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
}

// File Line: 526
// RVA: 0x34DB30
char __fastcall UFG::StimulusReceiverComponent::CheckIfPerceived(UFG::StimulusReceiverComponent *this, UFG::Stimulus *stimulus)
{
  __int64 v2; // rbp
  UFG::Stimulus *v3; // rbx
  UFG::StimulusReceiverComponent *v4; // rsi
  UFG::TransformNodeComponent *v5; // rdi
  UFG::ReceivedStimulusInfo *v6; // rdx
  float v7; // xmm0_4
  UFG::SimObject *v8; // rdx
  float v9; // xmm1_4
  UFG::StimulusEmitterComponent *v10; // rcx
  __m128 v11; // xmm6
  float v12; // xmm7_4
  __m128 v13; // xmm0
  UFG::qVector3 position; // [rsp+20h] [rbp-48h]
  UFG::qVector3 result; // [rsp+30h] [rbp-38h]

  v2 = stimulus->m_Description.m_Type;
  v3 = stimulus;
  v4 = this;
  if ( !this->m_pReceivedStimulusInfo[v2] )
    return 0;
  v5 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( v5 )
    v5 = (UFG::TransformNodeComponent *)v5->mChildren.mNode.mNext;
  if ( !UFG::StimulusReceiverComponent::CanPerceive(stimulus, v5) )
    return 0;
  v6 = v4->m_pReceivedStimulusInfo[v2];
  v7 = v3->m_Description.m_MinTimeBetweenUpdates * 2.0;
  if ( v7 <= 0.5 )
    v7 = FLOAT_0_5;
  if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - v6->m_LastTimePerceived.m_Time) > v7 )
    return 1;
  v8 = v6->m_LastTimePerceived.m_pProducer.m_pPointer;
  if ( v3->m_pStimulusProducer.m_pPointer == v8 )
    return 1;
  UFG::GetPosition(&result, v8);
  if ( v3->m_StimulusProducerInfoValid )
  {
    v9 = v3->m_StimulusProducerPosition.y;
    position.x = v3->m_StimulusProducerPosition.x;
    position.y = v9;
  }
  else
  {
    v10 = (UFG::StimulusEmitterComponent *)v3->m_pStimulusProducerStimulusEmitterComponent.m_pPointer;
    if ( !v10 || !UFG::StimulusEmitterComponent::GetStimulusProducerPosition(v10, &position) )
      return 0;
  }
  if ( v5 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v11 = (__m128)LODWORD(position.y);
    v12 = position.x - v5->mWorldTransform.v3.x;
    v11.m128_f32[0] = position.y - v5->mWorldTransform.v3.y;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v13 = (__m128)LODWORD(result.y);
    v11.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v12 * v12);
    v13.m128_f32[0] = (float)((float)(result.y - v5->mWorldTransform.v3.y) * (float)(result.y - v5->mWorldTransform.v3.y))
                    + (float)((float)(result.x - v5->mWorldTransform.v3.x) * (float)(result.x - v5->mWorldTransform.v3.x));
    if ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.5) > COERCE_FLOAT(_mm_sqrt_ps(v11)) )
      return 1;
  }
  return 0;
}

// File Line: 596
// RVA: 0x34C200
char __fastcall UFG::StimulusReceiverComponent::CanPerceive(UFG::Stimulus *stimulus, UFG::TransformNodeComponent *receiver_transform_node_component)
{
  UFG::SimObjectGame *v2; // rsi
  char v3; // r13
  UFG::TransformNodeComponent *v4; // r14
  UFG::Stimulus *v5; // rbx
  UFG::SimObject *v6; // r15
  bool v7; // bp
  bool v8; // r12
  float v9; // xmm14_4
  __m128 v10; // xmm15
  float v11; // xmm11_4
  float v12; // xmm7_4
  __m128 v13; // xmm6
  float v14; // xmm12_4
  float v15; // xmm9_4
  __m128 v16; // xmm8
  float v17; // xmm10_4
  UFG::InventoryItemComponent *v18; // rcx
  UFG::SimObject *v19; // rax
  UFG::TransformNodeComponent *v20; // rdi
  UFG::SimObject *v21; // rax
  float v22; // xmm2_4
  float v23; // xmm0_4
  __m128 v24; // xmm0
  bool v25; // bp
  __m128 v26; // xmm0
  float v27; // xmm11_4
  __m128 v28; // xmm5
  float v29; // xmm4_4
  float v30; // xmm12_4
  __m128 v31; // xmm3
  float v32; // xmm13_4
  __m128 v33; // xmm2
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  unsigned __int16 v38; // cx
  UFG::AimingBaseComponent *v39; // rdi
  UFG::SimComponent *v40; // rax
  float v41; // xmm13_4
  __m128 v42; // xmm5
  float v43; // xmm9_4
  __m128 v44; // xmm3
  __m128 v45; // xmm8
  __m128 v46; // xmm2
  float v47; // xmm3_4
  float v48; // xmm5_4
  float v49; // xmm10_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  bool v52; // al
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm4
  float v56; // xmm3_4
  float v57; // xmm8_4
  float v58; // xmm9_4
  float v59; // xmm3_4
  float v60; // xmm6_4
  float v61; // xmm4_4
  __m128 v62; // xmm3
  __m128 v63; // xmm2
  float v64; // xmm1_4
  float v65; // xmm4_4
  float v66; // xmm5_4
  float v67; // xmm1_4
  float v68; // xmm6_4
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+20h] [rbp-F8h]
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+30h] [rbp-E8h]
  float v72; // [rsp+120h] [rbp+8h]
  float v73; // [rsp+120h] [rbp+8h]
  float v74; // [rsp+128h] [rbp+10h]
  float v75; // [rsp+130h] [rbp+18h]

  v2 = (UFG::SimObjectGame *)stimulus->m_pStimulusProducer.m_pPointer;
  v3 = 0;
  v4 = receiver_transform_node_component;
  v5 = stimulus;
  if ( receiver_transform_node_component )
    v6 = receiver_transform_node_component->m_pSimObject;
  else
    v6 = 0i64;
  v7 = stimulus->m_StimulusProducerInfoValid;
  v8 = stimulus->m_IsTargeted;
  if ( v7 )
  {
    v9 = stimulus->m_StimulusProducerPosition.x;
    v10 = (__m128)LODWORD(stimulus->m_StimulusProducerPosition.y);
    v11 = stimulus->m_StimulusProducerPosition.z;
  }
  else
  {
    v11 = vWeaponProjectileDirection.z;
    v10 = (__m128)LODWORD(vWeaponProjectileDirection.y);
    v9 = vWeaponProjectileDirection.x;
  }
  if ( v7 )
  {
    v12 = stimulus->m_StimulusProducerVelocity.x;
    v13 = (__m128)LODWORD(stimulus->m_StimulusProducerVelocity.y);
    v14 = stimulus->m_StimulusProducerVelocity.z;
  }
  else
  {
    v14 = vWeaponProjectileDirection.z;
    v13 = (__m128)LODWORD(vWeaponProjectileDirection.y);
    v12 = vWeaponProjectileDirection.x;
  }
  if ( v7 )
  {
    v15 = stimulus->m_StimulusProducerFacing.x;
    v16 = (__m128)LODWORD(stimulus->m_StimulusProducerFacing.y);
    v17 = stimulus->m_StimulusProducerFacing.z;
  }
  else
  {
    v17 = vWeaponProjectileDirection.z;
    v16 = (__m128)LODWORD(vWeaponProjectileDirection.y);
    v15 = vWeaponProjectileDirection.x;
  }
  v18 = (UFG::InventoryItemComponent *)stimulus->m_pStimulusProducerInventoryItemComponent.m_pPointer;
  if ( v18 )
  {
    v19 = UFG::InventoryItemComponent::GetOwnerSimObject(v18);
    v20 = 0i64;
    if ( v19 )
      v20 = v19->m_pTransformNodeComponent;
    if ( v20 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v20);
      v9 = v20->mWorldTransform.v3.x;
      v10 = (__m128)LODWORD(v20->mWorldTransform.v3.y);
      v11 = v20->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(v20);
      v15 = v20->mWorldTransform.v0.x;
      v16 = (__m128)LODWORD(v20->mWorldTransform.v0.y);
      v17 = v20->mWorldTransform.v0.z;
    }
  }
  if ( !v8 || (v21 = v5->m_pStimulusTarget.m_pPointer) != 0i64 && v21 == v6 )
  {
    if ( v7 && v2 && v4 && (v2 != (UFG::SimObjectGame *)v6 || v8) )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v22 = v5->m_Description.m_MinPerceptionRadiusMetres;
      v75 = v5->m_Description.m_PerceptionAngleCosine;
      v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
      v23 = COERCE_FLOAT(_mm_sqrt_ps(v13)) * v5->m_Description.m_PerceptionRadiusSeconds;
      if ( v22 <= v23 )
        v22 = v23;
      v24 = v10;
      v24.m128_f32[0] = (float)((float)(v10.m128_f32[0] - v4->mWorldTransform.v3.y)
                              * (float)(v10.m128_f32[0] - v4->mWorldTransform.v3.y))
                      + (float)((float)(v9 - v4->mWorldTransform.v3.x) * (float)(v9 - v4->mWorldTransform.v3.x));
      v25 = 0;
      if ( v22 <= COERCE_FLOAT(_mm_sqrt_ps(v24)) )
        return v3;
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v26 = v10;
      v27 = v11 - v4->mWorldTransform.v3.z;
      v28 = (__m128)LODWORD(v4->mWorldTransform.v3.y);
      v29 = v4->mWorldTransform.v3.x;
      v30 = FLOAT_0_001;
      v26.m128_f32[0] = v10.m128_f32[0] - v28.m128_f32[0];
      v31 = v26;
      v72 = v10.m128_f32[0] - v28.m128_f32[0];
      v31.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0])
                              + (float)((float)(v9 - v29) * (float)(v9 - v29)))
                      + (float)(v27 * v27);
      if ( v31.m128_f32[0] <= 0.001
        || (v32 = v4->mWorldTransform.v0.y,
            v33 = (__m128)LODWORD(v4->mWorldTransform.v0.x),
            v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32))
                            + (float)(v4->mWorldTransform.v0.z * v4->mWorldTransform.v0.z),
            v33.m128_f32[0] <= 0.001) )
      {
        if ( !v8 || v2 != (UFG::SimObjectGame *)v6 )
          return v3;
      }
      else
      {
        if ( v31.m128_f32[0] == 0.0 )
          v34 = 0.0;
        else
          v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
        v35 = v72 * v34;
        v36 = (float)(v9 - v29) * v34;
        v73 = v72 * v34;
        v74 = v27 * v34;
        if ( v33.m128_f32[0] == 0.0 )
        {
          v37 = 0.0;
        }
        else
        {
          v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
          v35 = v73;
        }
        v30 = FLOAT_0_001;
        if ( (float)((float)((float)((float)(v32 * v37) * v35) + (float)((float)(v4->mWorldTransform.v0.x * v37) * v36))
                   + (float)((float)(v4->mWorldTransform.v0.z * v37) * v74)) <= v75 )
          return v3;
      }
      if ( v5->m_Description.m_UseAimDirection )
      {
        v38 = v2->m_Flags;
        if ( (v38 >> 14) & 1 )
        {
          v39 = (UFG::AimingBaseComponent *)v2->m_Components.p[47].m_pComponent;
        }
        else
        {
          if ( (v38 & 0x8000u) == 0 )
          {
            if ( (v38 >> 13) & 1 )
            {
              v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
            }
            else if ( (v38 >> 12) & 1 )
            {
              v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
            }
            else
            {
              v40 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AimingBaseComponent::_TypeUID);
            }
          }
          else
          {
            v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
          }
          v39 = (UFG::AimingBaseComponent *)v40;
        }
        if ( !v39 )
          return v3;
        v41 = v5->m_Description.m_EmitterVerticalAngleCosine;
        UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(v39, &vWeaponProjectileSpawnPosition);
        UFG::AimingBaseComponent::GetWeaponProjectileDirection(v39, &vWeaponProjectileDirection);
        v42 = (__m128)LODWORD(v4->mWorldTransform.v3.x);
        v45 = (__m128)LODWORD(v4->mWorldTransform.v3.z);
        v42.m128_f32[0] = v42.m128_f32[0] - vWeaponProjectileSpawnPosition.x;
        v43 = v4->mWorldTransform.v3.y - vWeaponProjectileSpawnPosition.y;
        v44 = v42;
        v44.m128_f32[0] = (float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v43 * v43);
        v45.m128_f32[0] = (float)(v45.m128_f32[0] + 1.0) - vWeaponProjectileSpawnPosition.z;
        if ( v44.m128_f32[0] <= v30
          || (v46 = (__m128)LODWORD(vWeaponProjectileDirection.y),
              v46.m128_f32[0] = (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y)
                              + (float)(vWeaponProjectileDirection.x * vWeaponProjectileDirection.x),
              v46.m128_f32[0] <= v30) )
        {
          v52 = 1;
        }
        else
        {
          if ( v44.m128_f32[0] == 0.0 )
            v47 = 0.0;
          else
            v47 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
          v48 = v42.m128_f32[0] * v47;
          v49 = v43 * v47;
          v50 = v47 * 0.0;
          if ( v46.m128_f32[0] == 0.0 )
            v51 = 0.0;
          else
            v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v46));
          v52 = (float)((float)((float)((float)(vWeaponProjectileDirection.y * v51) * v49)
                              + (float)((float)(vWeaponProjectileDirection.x * v51) * v48))
                      + (float)((float)(v51 * 0.0) * v50)) > v41;
        }
        v53 = v45;
        v53.m128_f32[0] = (float)(v45.m128_f32[0] * v45.m128_f32[0]) + (float)(v43 * v43);
        if ( v53.m128_f32[0] > v30 )
        {
          v54 = (__m128)LODWORD(vWeaponProjectileDirection.z);
          v55 = v54;
          v55.m128_f32[0] = (float)(v54.m128_f32[0] * v54.m128_f32[0])
                          + (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y);
          if ( v55.m128_f32[0] > v30 )
          {
            if ( v53.m128_f32[0] == 0.0 )
              v56 = 0.0;
            else
              v56 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v53));
            v57 = v45.m128_f32[0] * v56;
            v58 = v43 * v56;
            v59 = v56 * 0.0;
            if ( v55.m128_f32[0] == 0.0 )
              v60 = 0.0;
            else
              v60 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v55));
            v25 = (float)((float)((float)((float)(vWeaponProjectileDirection.y * v60) * v58)
                                + (float)((float)(vWeaponProjectileDirection.z * v60) * v57))
                        + (float)((float)(v60 * 0.0) * v59)) > v41;
          }
        }
      }
      else
      {
        v61 = v29 - v9;
        v28.m128_f32[0] = v28.m128_f32[0] - v10.m128_f32[0];
        v62 = v28;
        v62.m128_f32[0] = (float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v61 * v61);
        if ( v62.m128_f32[0] <= v30
          || (v63 = v16,
              v63.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15))
                              + (float)(v17 * v17),
              v63.m128_f32[0] <= v30) )
        {
          v52 = 1;
        }
        else
        {
          if ( v62.m128_f32[0] == 0.0 )
            v64 = 0.0;
          else
            v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v62));
          v65 = v61 * v64;
          v66 = v28.m128_f32[0] * v64;
          v67 = v64 * 0.0;
          if ( v63.m128_f32[0] == 0.0 )
            v68 = 0.0;
          else
            v68 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v63));
          v52 = (float)((float)((float)((float)(v16.m128_f32[0] * v68) * v66) + (float)((float)(v15 * v68) * v65))
                      + (float)((float)(v17 * v68) * v67)) > v5->m_Description.m_EmitterHorizontalAngleCosine;
        }
        v25 = COERCE_FLOAT(LODWORD(v27) & _xmm) < 2.0;
      }
      if ( v52 && v25 )
        v3 = 1;
      return v3;
    }
  }
  return 0;
}128_f32[0] * v68) * v66) + (float)((float)(v15 * v68) * v65))
                      + (float)((float)(v17 * v68) * v67)) > v5->m_Description.m_EmitterHorizontalAngleCosine;
        }
        v25 = COERCE_FLOAT(LODWORD(v27) & _xmm) < 2.0;
      }
      if ( v52 && v25 )

