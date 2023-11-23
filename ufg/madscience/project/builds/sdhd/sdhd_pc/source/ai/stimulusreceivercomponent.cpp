// File Line: 36
// RVA: 0x14AEC90
__int64 dynamic_initializer_for__UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList__);
}

// File Line: 37
// RVA: 0x3633F0
const char *__fastcall UFG::StimulusReceiverComponent::GetTypeName(UFG::StimulusReceiverComponent *this)
{
  return "StimulusReceiverComponent";
}

// File Line: 42
// RVA: 0x332330
void __fastcall UFG::StimulusReceiverComponent::StimulusReceiverComponent(
        UFG::StimulusReceiverComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *mPrev; // rax
  int v4; // eax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent>;
  this->mNext = &this->UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusReceiverComponent::`vftable;
  this->m_pRegisteredStimulusCookie = 0i64;
  this->m_StimulusRegistered.mBits[0] = 0i64;
  this->m_StimulusRegistered.mBits[1] = 0i64;
  this->m_OnPerceivedNotifyList.mNode.mPrev = &this->m_OnPerceivedNotifyList.mNode;
  this->m_OnPerceivedNotifyList.mNode.mNext = &this->m_OnPerceivedNotifyList.mNode;
  mPrev = UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mPrev;
  UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *)&UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList;
  UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::StimulusReceiverComponent::_StimulusReceiverComponentTypeUID,
    "StimulusReceiverComponent");
  this->m_DebugDraw = 0;
  *(_WORD *)&this->m_NumStimuliRegistered = 0;
  this->m_StimulusRegistered.mBits[0] = 0i64;
  this->m_StimulusRegistered.mBits[1] = 0i64;
  UFG::qMemSet(this->m_pReceivedStimulusInfo, 0, 0x3A0u);
  this->m_LastTimePerceivedAnyStimulus = -99999.0;
  v4 = once_9;
  if ( !once_9 )
    v4 = 1;
  once_9 = v4;
}

// File Line: 64
// RVA: 0x33B430
void __fastcall UFG::StimulusReceiverComponent::~StimulusReceiverComponent(UFG::StimulusReceiverComponent *this)
{
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v2; // rdi
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *mPrev; // rcx
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *mNext; // rax
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v5; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v6; // rax
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v7; // rcx
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusReceiverComponent::`vftable;
  if ( this == UFG::StimulusReceiverComponent::s_StimulusReceiverComponentpCurrentIterator )
    UFG::StimulusReceiverComponent::s_StimulusReceiverComponentpCurrentIterator = (UFG::StimulusReceiverComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::StimulusReceiverComponent::UnrequestAllStimuli(this);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_OnPerceivedNotifyList);
  v5 = this->m_OnPerceivedNotifyList.mNode.mPrev;
  v6 = this->m_OnPerceivedNotifyList.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_OnPerceivedNotifyList.mNode.mPrev = &this->m_OnPerceivedNotifyList.mNode;
  this->m_OnPerceivedNotifyList.mNode.mNext = &this->m_OnPerceivedNotifyList.mNode;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 72
// RVA: 0x37F270
UFG::qPropertySet *__fastcall UFG::StimulusReceiverComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *result; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v11; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  if ( required )
    goto LABEL_5;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  result = UFG::qPropertySet::GetParentFromName(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentStimulusReceiver,
             DEPTH_RECURSE);
  if ( result )
  {
LABEL_5:
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x428ui64, "StimulusReceiverComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::StimulusReceiverComponent::StimulusReceiverComponent(
        (UFG::StimulusReceiverComponent *)v6,
        pSceneObj->m_NameUID);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v11 = 11;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v12, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, v8, v11);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    return (UFG::qPropertySet *)v8;
  }
  return result;
}

// File Line: 90
// RVA: 0x3794B0
void __fastcall UFG::StimulusReceiverComponent::OnAttach(UFG::StimulusReceiverComponent *this, UFG::SimObject *object)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v3; // [rsp+30h] [rbp-18h] BYREF

  v3.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::StimulusReceiverComponent::HandleStimulus;
  v3.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->m_pRegisteredStimulusCookie = (struct UFG::EventHandlerCookieTag *)UFG::EventDispatcher::Register(
                                                                             &UFG::EventDispatcher::mInstance,
                                                                             &v3,
                                                                             UFG::g_StimulusEventHash,
                                                                             0i64,
                                                                             0);
}

// File Line: 105
// RVA: 0x37B2D0
void __fastcall UFG::StimulusReceiverComponent::OnDetach(UFG::StimulusReceiverComponent *this)
{
  struct UFG::EventHandlerCookieTag *m_pRegisteredStimulusCookie; // rdx

  UFG::StimulusReceiverComponent::UnrequestAllStimuli(this);
  UFG::StimulusReceiverComponent::DeregisterCallbacks(this);
  m_pRegisteredStimulusCookie = this->m_pRegisteredStimulusCookie;
  if ( m_pRegisteredStimulusCookie )
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      m_pRegisteredStimulusCookie,
      UFG::g_StimulusEventHash);
}

// File Line: 132
// RVA: 0x38AF90
void __fastcall UFG::StimulusReceiverComponent::UnrequestAllStimuli(UFG::StimulusReceiverComponent *this)
{
  __int64 v1; // rbx
  __int64 v3; // r15
  __int64 v4; // r14
  UFG::ReceivedStimulusInfo **m_pReceivedStimulusInfo; // rsi
  UFG::ReceivedStimulusInfo *v6; // rbp

  v1 = 1i64;
  v3 = 116i64;
  v4 = 0i64;
  m_pReceivedStimulusInfo = this->m_pReceivedStimulusInfo;
  do
  {
    if ( (v1 & this->m_StimulusRegistered.mBits[v4 >> 6]) != 0 )
    {
      this->m_StimulusRegistered.mBits[v4 >> 6] &= ~v1;
      --this->m_NumStimuliRegistered;
    }
    v6 = *m_pReceivedStimulusInfo;
    if ( *m_pReceivedStimulusInfo )
    {
      UFG::ReceivedStimulusInfo::~ReceivedStimulusInfo(*m_pReceivedStimulusInfo);
      operator delete[](v6);
      *m_pReceivedStimulusInfo = 0i64;
      --this->m_NumStimuliAllocated;
    }
    v1 = __ROL8__(v1, 1);
    ++v4;
    ++m_pReceivedStimulusInfo;
    --v3;
  }
  while ( v3 );
}

// File Line: 140
// RVA: 0x382610
void __fastcall UFG::StimulusReceiverComponent::RequestToReceiveStimulus(
        UFG::StimulusReceiverComponent *this,
        int stimulus_type)
{
  __int64 v2; // rax
  char v3; // dl
  char v4; // cl

  v2 = (__int64)stimulus_type >> 6;
  if ( ((1i64 << (stimulus_type & 0x3F)) & this->m_StimulusRegistered.mBits[v2]) == 0 )
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
void __fastcall UFG::StimulusReceiverComponent::RegisterNotifyCallback(
        UFG::StimulusReceiverComponent *this,
        UFG::StimulusNotifyCallback *callback)
{
  __int64 m_type; // r9
  char v5; // dl
  char v6; // cl
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *mPrev; // rax

  m_type = callback->m_type;
  if ( (_DWORD)m_type && ((1i64 << (m_type & 0x3F)) & this->m_StimulusRegistered.mBits[m_type >> 6]) == 0 )
  {
    this->m_StimulusRegistered.mBits[m_type >> 6] |= 1i64 << (m_type & 0x3F);
    v5 = ++this->m_NumStimuliRegistered;
    v6 = UFG::StimulusReceiverComponent::s_MaxStimuliRegistered;
    if ( UFG::StimulusReceiverComponent::s_MaxStimuliRegistered <= v5 )
      v6 = v5;
    UFG::StimulusReceiverComponent::s_MaxStimuliRegistered = v6;
  }
  mPrev = this->m_OnPerceivedNotifyList.mNode.mPrev;
  mPrev->mNext = &callback->UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>;
  callback->mPrev = mPrev;
  callback->mNext = &this->m_OnPerceivedNotifyList.mNode;
  this->m_OnPerceivedNotifyList.mNode.mPrev = &callback->UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>;
}

// File Line: 200
// RVA: 0x352150
void __fastcall UFG::StimulusReceiverComponent::DeregisterCallbacks(UFG::StimulusReceiverComponent *this)
{
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v1; // rsi
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *mNext; // rdx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *mPrev; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v5; // rax
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> **p_mNext; // rdi

  v1 = (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)&this->m_pReceivedStimulusInfo[115];
  if ( (UFG::ReceivedStimulusInfo **)&this->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext != &this->m_pReceivedStimulusInfo[115] )
  {
    do
    {
      mNext = this->m_OnPerceivedNotifyList.mNode.mNext;
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      p_mNext = &mNext[-1].mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      ((void (__fastcall *)(UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *, UFG::StimulusReceiverComponent *, _QWORD, UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> **))p_mNext[5])(
        mNext[1].mNext,
        this,
        0i64,
        p_mNext);
      ((void (__fastcall *)(UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> **, __int64))(*p_mNext)->mPrev)(
        p_mNext,
        1i64);
    }
    while ( (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)((char *)this->m_OnPerceivedNotifyList.mNode.mNext
                                                                                  - 8) != v1 );
  }
}

// File Line: 241
// RVA: 0x364CB0
void __fastcall UFG::StimulusReceiverComponent::HandleStimulus(
        UFG::StimulusReceiverComponent *this,
        UFG::Stimulus *this_event)
{
  if ( this->m_StimulusRegistered.mBits[0] | this->m_StimulusRegistered.mBits[1] | this_event->m_StimulusMask.mBits[0] | this_event->m_StimulusMask.mBits[1]
    && (!this_event->m_IsTargeted || this_event->m_pStimulusTarget.m_pPointer == this->m_pSimObject) )
  {
    UFG::StimulusReceiverComponent::SetLastTimeReceived(this, this_event);
    if ( UFG::StimulusReceiverComponent::CheckIfPerceived(this, this_event) )
      UFG::StimulusReceiverComponent::SetLastTimePerceived(this, this_event);
  }
}

// File Line: 441
// RVA: 0x387010
void __fastcall UFG::StimulusReceiverComponent::SetLastTimePerceived(
        UFG::StimulusReceiverComponent *this,
        UFG::Stimulus *stimulus)
{
  __int64 m_Type; // rbx
  UFG::ReceivedStimulusInfo *v5; // rdx
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pProducer; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::StimulusReceiverComponent *p_mNext; // rbx
  UFG::StimulusReceiverComponent *v12; // rdi
  unsigned int m_TypeUID; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  m_Type = stimulus->m_Description.m_Type;
  UFG::StimulusReceiverComponent::MaybeCreateReceivedStimulusInfo(this, stimulus->m_Description.m_Type);
  v5 = this->m_pReceivedStimulusInfo[m_Type];
  if ( v5 )
  {
    m_pPointer = stimulus->m_pStimulusProducer.m_pPointer;
    p_m_pProducer = &v5->m_LastTimePerceived.m_pProducer;
    *(float *)&p_m_pProducer[-1].m_pPointer = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( p_m_pProducer->m_pPointer )
    {
      mPrev = p_m_pProducer->mPrev;
      mNext = p_m_pProducer->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pProducer->mPrev = p_m_pProducer;
      p_m_pProducer->mNext = p_m_pProducer;
    }
    p_m_pProducer->m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v10 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v10->mNext = p_m_pProducer;
      p_m_pProducer->mPrev = v10;
      p_m_pProducer->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pProducer;
    }
    this->m_LastTimePerceivedAnyStimulus = this->m_pReceivedStimulusInfo[m_Type]->m_LastTimePerceived.m_Time;
    if ( (UFG::ReceivedStimulusInfo **)&this->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext != &this->m_pReceivedStimulusInfo[115] )
    {
      p_mNext = (UFG::StimulusReceiverComponent *)&this->m_OnPerceivedNotifyList.mNode.mNext[-1].mNext;
      do
      {
        v12 = p_mNext;
        m_TypeUID = p_mNext->m_TypeUID;
        p_mNext = (UFG::StimulusReceiverComponent *)&p_mNext->m_SafePointerList.mNode.mNext[-1].mNext;
        if ( !m_TypeUID || m_TypeUID == stimulus->m_Description.m_Type )
        {
          if ( ((unsigned __int64 (__fastcall *)(_QWORD, UFG::StimulusReceiverComponent *, UFG::Stimulus *, UFG::StimulusReceiverComponent *))v12->m_pSimObject)(
                 *(_QWORD *)&v12->m_Flags,
                 this,
                 stimulus,
                 v12) )
          {
            v14 = v12->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
            v15 = v12->m_SafePointerList.mNode.mNext;
            v14->mNext = v15;
            v15->mPrev = v14;
            v12->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &v12->m_SafePointerList.mNode;
            v12->m_SafePointerList.mNode.mNext = &v12->m_SafePointerList.mNode;
            if ( v12 )
              v12->vfptr->__vecDelDtor(v12, 1u);
          }
        }
      }
      while ( p_mNext != (UFG::StimulusReceiverComponent *)&this->m_pReceivedStimulusInfo[115] );
    }
  }
}

// File Line: 492
// RVA: 0x374CE0
void __fastcall UFG::StimulusReceiverComponent::MaybeCreateReceivedStimulusInfo(
        UFG::StimulusReceiverComponent *this,
        int stimulus_type)
{
  __int64 v3; // rdi
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::ReceivedStimulusInfo *v6; // rcx
  UFG::allocator::free_link *v7; // rax
  char m_NumStimuliAllocated; // cl

  v3 = stimulus_type;
  v4 = this->m_StimulusRegistered.mBits[(__int64)stimulus_type >> 6];
  if ( _bittest64((const __int64 *)&v4, stimulus_type & 0x3F) && !this->m_pReceivedStimulusInfo[stimulus_type] )
  {
    v5 = UFG::qMalloc(0x40ui64, "ReceivedStimulusInfo", 0i64);
    v6 = (UFG::ReceivedStimulusInfo *)v5;
    if ( v5 )
    {
      v7 = v5 + 1;
      v7->mNext = v7;
      v7[1].mNext = v7;
      v7[2].mNext = 0i64;
      v6->m_LastTimePerceived.m_pProducer.mPrev = &v6->m_LastTimePerceived.m_pProducer;
      v6->m_LastTimePerceived.m_pProducer.mNext = &v6->m_LastTimePerceived.m_pProducer;
      v6->m_LastTimePerceived.m_pProducer.m_pPointer = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    this->m_pReceivedStimulusInfo[v3] = v6;
    UFG::ReceivedStimulusInfo::Clear(v6);
    ++this->m_NumStimuliAllocated;
    m_NumStimuliAllocated = UFG::StimulusReceiverComponent::s_MaxStimuliAllocated;
    if ( UFG::StimulusReceiverComponent::s_MaxStimuliAllocated <= this->m_NumStimuliAllocated )
      m_NumStimuliAllocated = this->m_NumStimuliAllocated;
    UFG::StimulusReceiverComponent::s_MaxStimuliAllocated = m_NumStimuliAllocated;
  }
}

// File Line: 512
// RVA: 0x387160
void __fastcall UFG::StimulusReceiverComponent::SetLastTimeReceived(
        UFG::StimulusReceiverComponent *this,
        UFG::Stimulus *stimulus)
{
  __int64 m_Type; // rbx
  UFG::ReceivedStimulusInfo *v5; // rdx
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pProducer; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  m_Type = stimulus->m_Description.m_Type;
  UFG::StimulusReceiverComponent::MaybeCreateReceivedStimulusInfo(this, stimulus->m_Description.m_Type);
  v5 = this->m_pReceivedStimulusInfo[m_Type];
  if ( v5 )
  {
    m_pPointer = stimulus->m_pStimulusProducer.m_pPointer;
    p_m_pProducer = &v5->m_LastTimeReceived.m_pProducer;
    *(float *)&p_m_pProducer[-1].m_pPointer = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( p_m_pProducer->m_pPointer )
    {
      mPrev = p_m_pProducer->mPrev;
      mNext = p_m_pProducer->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pProducer->mPrev = p_m_pProducer;
      p_m_pProducer->mNext = p_m_pProducer;
    }
    p_m_pProducer->m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v10 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v10->mNext = p_m_pProducer;
      p_m_pProducer->mPrev = v10;
      p_m_pProducer->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pProducer;
    }
  }
}

// File Line: 526
// RVA: 0x34DB30
bool __fastcall UFG::StimulusReceiverComponent::CheckIfPerceived(
        UFG::StimulusReceiverComponent *this,
        UFG::Stimulus *stimulus)
{
  __int64 m_Type; // rbp
  UFG::TransformNodeComponent *m_pSimObject; // rdi
  UFG::ReceivedStimulusInfo *v6; // rdx
  float v7; // xmm0_4
  UFG::SimObject *m_pPointer; // rdx
  float y; // xmm1_4
  UFG::StimulusEmitterComponent *v10; // rcx
  __m128 y_low; // xmm6
  float v12; // xmm7_4
  __m128 v13; // xmm0
  UFG::qVector3 position; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-38h] BYREF

  m_Type = stimulus->m_Description.m_Type;
  if ( !this->m_pReceivedStimulusInfo[m_Type] )
    return 0;
  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( !UFG::StimulusReceiverComponent::CanPerceive(stimulus, m_pSimObject) )
    return 0;
  v6 = this->m_pReceivedStimulusInfo[m_Type];
  v7 = stimulus->m_Description.m_MinTimeBetweenUpdates * 2.0;
  if ( v7 <= 0.5 )
    v7 = FLOAT_0_5;
  if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - v6->m_LastTimePerceived.m_Time) > v7 )
    return 1;
  m_pPointer = v6->m_LastTimePerceived.m_pProducer.m_pPointer;
  if ( stimulus->m_pStimulusProducer.m_pPointer == m_pPointer )
    return 1;
  UFG::GetPosition(&result, m_pPointer);
  if ( stimulus->m_StimulusProducerInfoValid )
  {
    y = stimulus->m_StimulusProducerPosition.y;
    position.x = stimulus->m_StimulusProducerPosition.x;
    position.y = y;
  }
  else
  {
    v10 = (UFG::StimulusEmitterComponent *)stimulus->m_pStimulusProducerStimulusEmitterComponent.m_pPointer;
    if ( !v10 || !UFG::StimulusEmitterComponent::GetStimulusProducerPosition(v10, &position) )
      return 0;
  }
  if ( !m_pSimObject )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  y_low = (__m128)LODWORD(position.y);
  v12 = position.x - m_pSimObject->mWorldTransform.v3.x;
  y_low.m128_f32[0] = position.y - m_pSimObject->mWorldTransform.v3.y;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  v13 = (__m128)LODWORD(result.y);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v12 * v12);
  v13.m128_f32[0] = (float)((float)(result.y - m_pSimObject->mWorldTransform.v3.y)
                          * (float)(result.y - m_pSimObject->mWorldTransform.v3.y))
                  + (float)((float)(result.x - m_pSimObject->mWorldTransform.v3.x)
                          * (float)(result.x - m_pSimObject->mWorldTransform.v3.x));
  return (float)(_mm_sqrt_ps(v13).m128_f32[0] - 0.5) > _mm_sqrt_ps(y_low).m128_f32[0];
}

// File Line: 596
// RVA: 0x34C200
char __fastcall UFG::StimulusReceiverComponent::CanPerceive(
        UFG::Stimulus *stimulus,
        UFG::TransformNodeComponent *receiver_transform_node_component)
{
  UFG::SimObjectGame *m_pPointer; // rsi
  char v3; // r13
  UFG::SimObject *m_pSimObject; // r15
  bool m_StimulusProducerInfoValid; // bp
  bool m_IsTargeted; // r12
  float x; // xmm14_4
  __m128 y_low; // xmm15
  float z; // xmm11_4
  float v12; // xmm7_4
  __m128 v13; // xmm6
  float v14; // xmm12_4
  float v15; // xmm9_4
  __m128 v16; // xmm8
  float v17; // xmm10_4
  UFG::InventoryItemComponent *v18; // rcx
  UFG::SimObject *OwnerSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObject *v21; // rax
  float m_MinPerceptionRadiusMetres; // xmm2_4
  float v23; // xmm0_4
  __m128 v24; // xmm0
  bool v25; // bp
  __m128 v26; // xmm0
  float v27; // xmm11_4
  __m128 v28; // xmm5
  float v29; // xmm4_4
  float v30; // xmm12_4
  __m128 v31; // xmm3
  float y; // xmm13_4
  __m128 x_low; // xmm2
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  __int16 m_Flags; // cx
  UFG::AimingBaseComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float m_EmitterVerticalAngleCosine; // xmm13_4
  __m128 v42; // xmm5
  float v43; // xmm9_4
  __m128 v44; // xmm3
  __m128 z_low; // xmm8
  __m128 v46; // xmm2
  float v47; // xmm3_4
  float v48; // xmm5_4
  float v49; // xmm10_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  bool v52; // al
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  float v55; // xmm3_4
  float v56; // xmm8_4
  float v57; // xmm9_4
  float v58; // xmm3_4
  float v59; // xmm6_4
  float v60; // xmm4_4
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  float v63; // xmm1_4
  float v64; // xmm4_4
  float v65; // xmm5_4
  float v66; // xmm1_4
  float v67; // xmm6_4
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+20h] [rbp-F8h] BYREF
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+30h] [rbp-E8h] BYREF
  float v71; // [rsp+120h] [rbp+8h]
  float v72; // [rsp+120h] [rbp+8h]
  float v73; // [rsp+128h] [rbp+10h]
  float m_PerceptionAngleCosine; // [rsp+130h] [rbp+18h]

  m_pPointer = (UFG::SimObjectGame *)stimulus->m_pStimulusProducer.m_pPointer;
  v3 = 0;
  if ( receiver_transform_node_component )
    m_pSimObject = receiver_transform_node_component->m_pSimObject;
  else
    m_pSimObject = 0i64;
  m_StimulusProducerInfoValid = stimulus->m_StimulusProducerInfoValid;
  m_IsTargeted = stimulus->m_IsTargeted;
  if ( m_StimulusProducerInfoValid )
  {
    x = stimulus->m_StimulusProducerPosition.x;
    y_low = (__m128)LODWORD(stimulus->m_StimulusProducerPosition.y);
    z = stimulus->m_StimulusProducerPosition.z;
  }
  else
  {
    z = vWeaponProjectileDirection.z;
    y_low = (__m128)LODWORD(vWeaponProjectileDirection.y);
    x = vWeaponProjectileDirection.x;
  }
  if ( m_StimulusProducerInfoValid )
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
  if ( m_StimulusProducerInfoValid )
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
    OwnerSimObject = UFG::InventoryItemComponent::GetOwnerSimObject(v18);
    m_pTransformNodeComponent = 0i64;
    if ( OwnerSimObject )
      m_pTransformNodeComponent = OwnerSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v15 = m_pTransformNodeComponent->mWorldTransform.v0.x;
      v16 = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
      v17 = m_pTransformNodeComponent->mWorldTransform.v0.z;
    }
  }
  if ( (!m_IsTargeted || (v21 = stimulus->m_pStimulusTarget.m_pPointer) != 0i64 && v21 == m_pSimObject)
    && m_StimulusProducerInfoValid
    && m_pPointer
    && receiver_transform_node_component
    && (m_pPointer != m_pSimObject || m_IsTargeted) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(receiver_transform_node_component);
    m_MinPerceptionRadiusMetres = stimulus->m_Description.m_MinPerceptionRadiusMetres;
    m_PerceptionAngleCosine = stimulus->m_Description.m_PerceptionAngleCosine;
    v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
    v23 = _mm_sqrt_ps(v13).m128_f32[0] * stimulus->m_Description.m_PerceptionRadiusSeconds;
    if ( m_MinPerceptionRadiusMetres <= v23 )
      m_MinPerceptionRadiusMetres = v23;
    v24 = y_low;
    v24.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - receiver_transform_node_component->mWorldTransform.v3.y)
                            * (float)(y_low.m128_f32[0] - receiver_transform_node_component->mWorldTransform.v3.y))
                    + (float)((float)(x - receiver_transform_node_component->mWorldTransform.v3.x)
                            * (float)(x - receiver_transform_node_component->mWorldTransform.v3.x));
    v25 = 0;
    if ( m_MinPerceptionRadiusMetres <= _mm_sqrt_ps(v24).m128_f32[0] )
      return v3;
    UFG::TransformNodeComponent::UpdateWorldTransform(receiver_transform_node_component);
    v26 = y_low;
    v27 = z - receiver_transform_node_component->mWorldTransform.v3.z;
    v28 = (__m128)LODWORD(receiver_transform_node_component->mWorldTransform.v3.y);
    v29 = receiver_transform_node_component->mWorldTransform.v3.x;
    v30 = FLOAT_0_001;
    v26.m128_f32[0] = y_low.m128_f32[0] - v28.m128_f32[0];
    v31 = v26;
    v71 = y_low.m128_f32[0] - v28.m128_f32[0];
    v31.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)((float)(x - v29) * (float)(x - v29)))
                    + (float)(v27 * v27);
    if ( v31.m128_f32[0] <= 0.001
      || (y = receiver_transform_node_component->mWorldTransform.v0.y,
          x_low = (__m128)LODWORD(receiver_transform_node_component->mWorldTransform.v0.x),
          x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y))
                            + (float)(receiver_transform_node_component->mWorldTransform.v0.z
                                    * receiver_transform_node_component->mWorldTransform.v0.z),
          x_low.m128_f32[0] <= 0.001) )
    {
      if ( !m_IsTargeted || m_pPointer != m_pSimObject )
        return v3;
    }
    else
    {
      if ( v31.m128_f32[0] == 0.0 )
        v34 = 0.0;
      else
        v34 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
      v35 = v71 * v34;
      v36 = (float)(x - v29) * v34;
      v72 = v71 * v34;
      v73 = v27 * v34;
      if ( x_low.m128_f32[0] == 0.0 )
      {
        v37 = 0.0;
      }
      else
      {
        v37 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        v35 = v72;
      }
      v30 = FLOAT_0_001;
      if ( (float)((float)((float)((float)(y * v37) * v35)
                         + (float)((float)(receiver_transform_node_component->mWorldTransform.v0.x * v37) * v36))
                 + (float)((float)(receiver_transform_node_component->mWorldTransform.v0.z * v37) * v73)) <= m_PerceptionAngleCosine )
        return v3;
    }
    if ( stimulus->m_Description.m_UseAimDirection )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::AimingBaseComponent *)m_pPointer->m_Components.p[47].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
        m_pComponent = (UFG::AimingBaseComponent *)ComponentOfTypeHK;
      }
      if ( !m_pComponent )
        return v3;
      m_EmitterVerticalAngleCosine = stimulus->m_Description.m_EmitterVerticalAngleCosine;
      UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(m_pComponent, &vWeaponProjectileSpawnPosition);
      UFG::AimingBaseComponent::GetWeaponProjectileDirection(m_pComponent, &vWeaponProjectileDirection);
      v42 = (__m128)LODWORD(receiver_transform_node_component->mWorldTransform.v3.x);
      z_low = (__m128)LODWORD(receiver_transform_node_component->mWorldTransform.v3.z);
      v42.m128_f32[0] = v42.m128_f32[0] - vWeaponProjectileSpawnPosition.x;
      v43 = receiver_transform_node_component->mWorldTransform.v3.y - vWeaponProjectileSpawnPosition.y;
      v44 = v42;
      v44.m128_f32[0] = (float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v43 * v43);
      z_low.m128_f32[0] = (float)(z_low.m128_f32[0] + 1.0) - vWeaponProjectileSpawnPosition.z;
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
          v47 = 1.0 / _mm_sqrt_ps(v44).m128_f32[0];
        v48 = v42.m128_f32[0] * v47;
        v49 = v43 * v47;
        v50 = v47 * 0.0;
        if ( v46.m128_f32[0] == 0.0 )
          v51 = 0.0;
        else
          v51 = 1.0 / _mm_sqrt_ps(v46).m128_f32[0];
        v52 = (float)((float)((float)((float)(vWeaponProjectileDirection.y * v51) * v49)
                            + (float)((float)(vWeaponProjectileDirection.x * v51) * v48))
                    + (float)((float)(v51 * 0.0) * v50)) > m_EmitterVerticalAngleCosine;
      }
      v53 = z_low;
      v53.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v43 * v43);
      if ( v53.m128_f32[0] > v30 )
      {
        v54 = (__m128)LODWORD(vWeaponProjectileDirection.z);
        v54.m128_f32[0] = (float)(v54.m128_f32[0] * v54.m128_f32[0])
                        + (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y);
        if ( v54.m128_f32[0] > v30 )
        {
          if ( v53.m128_f32[0] == 0.0 )
            v55 = 0.0;
          else
            v55 = 1.0 / _mm_sqrt_ps(v53).m128_f32[0];
          v56 = z_low.m128_f32[0] * v55;
          v57 = v43 * v55;
          v58 = v55 * 0.0;
          if ( v54.m128_f32[0] == 0.0 )
            v59 = 0.0;
          else
            v59 = 1.0 / _mm_sqrt_ps(v54).m128_f32[0];
          v25 = (float)((float)((float)((float)(vWeaponProjectileDirection.y * v59) * v57)
                              + (float)((float)(vWeaponProjectileDirection.z * v59) * v56))
                      + (float)((float)(v59 * 0.0) * v58)) > m_EmitterVerticalAngleCosine;
        }
      }
    }
    else
    {
      v60 = v29 - x;
      v28.m128_f32[0] = v28.m128_f32[0] - y_low.m128_f32[0];
      v61 = v28;
      v61.m128_f32[0] = (float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v60 * v60);
      if ( v61.m128_f32[0] <= v30
        || (v62 = v16,
            v62.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15))
                            + (float)(v17 * v17),
            v62.m128_f32[0] <= v30) )
      {
        v52 = 1;
      }
      else
      {
        if ( v61.m128_f32[0] == 0.0 )
          v63 = 0.0;
        else
          v63 = 1.0 / _mm_sqrt_ps(v61).m128_f32[0];
        v64 = v60 * v63;
        v65 = v28.m128_f32[0] * v63;
        v66 = v63 * 0.0;
        if ( v62.m128_f32[0] == 0.0 )
          v67 = 0.0;
        else
          v67 = 1.0 / _mm_sqrt_ps(v62).m128_f32[0];
        v52 = (float)((float)((float)((float)(v16.m128_f32[0] * v67) * v65) + (float)((float)(v15 * v67) * v64))
                    + (float)((float)(v17 * v67) * v66)) > stimulus->m_Description.m_EmitterHorizontalAngleCosine;
      }
      v25 = COERCE_FLOAT(LODWORD(v27) & _xmm) < 2.0;
    }
    if ( v52 && v25 )
      return 1;
    return v3;
  }
  return 0;
}

