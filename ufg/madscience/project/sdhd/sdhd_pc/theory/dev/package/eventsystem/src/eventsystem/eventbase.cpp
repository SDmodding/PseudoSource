// File Line: 20
// RVA: 0x146A8B0
__int64 dynamic_initializer_for__UFG::EventDispatcher::mInstance__()
{
  UFG::EventDispatcher::EventDispatcher(&UFG::EventDispatcher::mInstance);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::EventDispatcher::mInstance__);
}

// File Line: 24
// RVA: 0x1B5C80
void __fastcall UFG::ChannelObj::ChannelObj(UFG::ChannelObj *this, const char *name, const char *desc)
{
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mNext; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mName = name;
  this->mDescription = desc;
  this->mUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  if ( (_S1_23 & 1) == 0 )
  {
    _S1_23 |= 1u;
    localList.mNode.mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    atexit(UFG::EventDispatcher::StaticLinkUp_::_2_::_dynamic_atexit_destructor_for__localList__);
  }
  mNext = localList.mNode.mNext;
  localList.mNode.mNext = this;
  this->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
  this->mNext = mNext;
  mNext->mPrev = this;
}

// File Line: 33
// RVA: 0x1B5BF0
void __fastcall UFG::ChannelObj::ChannelObj(
        UFG::ChannelObj *this,
        unsigned int uid,
        const char *name,
        const char *desc)
{
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mNext; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mName = name;
  this->mDescription = desc;
  this->mUID = uid;
  if ( (_S1_23 & 1) == 0 )
  {
    _S1_23 |= 1u;
    localList.mNode.mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    atexit(UFG::EventDispatcher::StaticLinkUp_::_2_::_dynamic_atexit_destructor_for__localList__);
  }
  mNext = localList.mNode.mNext;
  localList.mNode.mNext = this;
  this->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
  this->mNext = mNext;
  mNext->mPrev = this;
}

// File Line: 148
// RVA: 0x1B5F90
UFG::allocator::free_link *__fastcall UFG::EventChannel::AddHandler(
        UFG::EventChannel *this,
        fastdelegate::FastDelegate1<UFG::Event *,void> *eh,
        unsigned int dependencyID)
{
  UFG::allocator::free_link *v6; // r9
  void (__fastcall *m_pFunction)(fastdelegate::detail::GenericClass *); // rax
  fastdelegate::detail::GenericClass *m_pthis; // rdx
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *mPrev; // rcx

  v6 = UFG::qMalloc(0x30ui64, "eventsys.HandlerNode", 0i64);
  if ( v6 )
  {
    m_pFunction = eh->m_Closure.m_pFunction;
    m_pthis = eh->m_Closure.m_pthis;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v6[3].mNext = (UFG::allocator::free_link *)m_pFunction;
    v6[2].mNext = (UFG::allocator::free_link *)m_pthis;
    LODWORD(v6[4].mNext) = dependencyID;
    *(UFG::allocator::free_link **)((char *)&v6[4].mNext + 4) = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  mPrev = this->m_HandlerList.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)v6;
  v6->mNext = (UFG::allocator::free_link *)mPrev;
  v6[1].mNext = (UFG::allocator::free_link *)&this->m_HandlerList;
  this->m_HandlerList.mNode.mPrev = (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)v6;
  return v6;
}

// File Line: 160
// RVA: 0x1B6690
__int64 __fastcall UFG::EventChannel::RemoveHandler(
        UFG::EventChannel *this,
        fastdelegate::FastDelegate1<UFG::Event *,void> *handler)
{
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *mNext; // rcx
  UFG::qList<UFG::HandlerNode,UFG::HandlerNode,1,0> *p_m_HandlerList; // rax
  UFG::EventDispatcher *v5; // rdx
  __int64 v6; // r8
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *mPrev; // rdx
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v8; // rax
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v9; // rdx
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v10; // rax

  mNext = this->m_HandlerList.mNode.mNext;
  p_m_HandlerList = &this->m_HandlerList;
  while ( 1 )
  {
    if ( mNext == (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)p_m_HandlerList )
      return 1i64;
    if ( mNext[1].mPrev == (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)handler->m_Closure.m_pthis
      && mNext[1].mNext == (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)handler->m_Closure.m_pFunction )
    {
      break;
    }
    mNext = mNext->mNext;
  }
  if ( !mNext )
    return 1i64;
  v5 = &UFG::EventDispatcher::mInstance;
  v6 = 16i64;
  do
  {
    if ( v5->mCachedNextNode[0] == mNext )
      v5->mCachedNextNode[0] = (UFG::HandlerNode *)v5->mCachedNextNode[0]->mNext;
    v5 = (UFG::EventDispatcher *)((char *)v5 + 8);
    --v6;
  }
  while ( v6 );
  mPrev = mNext->mPrev;
  v8 = mNext->mNext;
  mPrev->mNext = v8;
  v8->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  v9 = mNext->mPrev;
  v10 = mNext->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  operator delete[](mNext);
  return 0i64;
}

// File Line: 177
// RVA: 0x1B6610
__int64 __fastcall UFG::EventChannel::RemoveHandler(UFG::EventChannel *this, struct UFG::EventHandlerCookieTag *cookie)
{
  UFG::EventDispatcher *v2; // rax
  __int64 v3; // r8
  __int64 v4; // rcx
  _QWORD *v5; // rax
  __int64 v6; // rcx
  _QWORD *v7; // rax

  v2 = &UFG::EventDispatcher::mInstance;
  v3 = 16i64;
  do
  {
    if ( (struct UFG::EventHandlerCookieTag *)v2->mCachedNextNode[0] == cookie )
      v2->mCachedNextNode[0] = (UFG::HandlerNode *)v2->mCachedNextNode[0]->mNext;
    v2 = (UFG::EventDispatcher *)((char *)v2 + 8);
    --v3;
  }
  while ( v3 );
  v4 = *(_QWORD *)cookie;
  v5 = (_QWORD *)*((_QWORD *)cookie + 1);
  *(_QWORD *)(v4 + 8) = v5;
  *v5 = v4;
  *(_QWORD *)cookie = cookie;
  *((_QWORD *)cookie + 1) = cookie;
  v6 = *(_QWORD *)cookie;
  v7 = (_QWORD *)*((_QWORD *)cookie + 1);
  *(_QWORD *)(v6 + 8) = v7;
  *v7 = v6;
  *(_QWORD *)cookie = cookie;
  *((_QWORD *)cookie + 1) = cookie;
  operator delete[](cookie);
  return 0i64;
}

// File Line: 240
// RVA: 0x1B6590
void __fastcall UFG::EventDispatcher::QueueEvent(UFG::EventDispatcher *this, UFG::Event *event)
{
  UFG::qList<UFG::Event,UFG::Event,1,0> *v2; // r8
  UFG::qNode<UFG::Event,UFG::Event> *mPrev; // rax

  v2 = &this->QueuedEventList[this->mListIndex];
  mPrev = v2->mNode.mPrev;
  mPrev->mNext = &event->UFG::qNode<UFG::Event,UFG::Event>;
  event->mPrev = mPrev;
  event->mNext = &v2->mNode;
  v2->mNode.mPrev = &event->UFG::qNode<UFG::Event,UFG::Event>;
}

// File Line: 249
// RVA: 0x1B6380
void __fastcall UFG::EventDispatcher::DispatchAllQueuedEvents(UFG::EventDispatcher *this)
{
  __int64 mListIndex; // rbp
  int *v3; // rsi
  UFG::Event *p_mNext; // rdx
  __int64 v5; // rbx
  UFG::qList<UFG::Event,UFG::Event,1,0> *v6; // r8
  UFG::qNode<UFG::Event,UFG::Event> *i; // rax
  UFG::qNode<UFG::Event,UFG::Event> *mNext; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *mPrev; // rdx

  mListIndex = this->mListIndex;
  this->mListIndex = mListIndex ^ 1;
  v3 = &this->mListIndex + 4 * mListIndex;
  p_mNext = (UFG::Event *)&this->QueuedEventList[mListIndex].mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::Event *)v3 )
  {
    do
    {
      v5 = (__int64)&p_mNext->mNext[-1].mNext;
      UFG::EventDispatcher::DispatchEvent(this, p_mNext);
      p_mNext = (UFG::Event *)v5;
    }
    while ( (int *)v5 != v3 );
  }
  v6 = &this->QueuedEventList[mListIndex];
  for ( i = v6->mNode.mNext; &i[-1].mNext != &v6[-1].mNode.mNext; i = v6->mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
}

// File Line: 280
// RVA: 0x1B6460
void __fastcall UFG::EventDispatcher::DispatchEvent(UFG::EventDispatcher *this, UFG::Event *evt)
{
  unsigned int v2; // eax
  unsigned int m_EventUID; // edx
  UFG::EventDispatcher *v6; // r8
  unsigned int v7; // r12d
  UFG::qBaseTreeRB *v8; // rax
  UFG::HandlerNode *v9; // rdi
  unsigned int *p_mUID; // rbp
  UFG::HandlerNode **v11; // rsi
  unsigned int *mNext; // rax
  bool v13; // bl

  v2 = 0;
  m_EventUID = evt->m_EventUID;
  v6 = this;
  v7 = 16;
  while ( v6->mCachedNextNode[0] )
  {
    ++v2;
    v6 = (UFG::EventDispatcher *)((char *)v6 + 8);
    if ( v2 >= 0x10 )
      goto LABEL_6;
  }
  v7 = v2;
LABEL_6:
  if ( m_EventUID )
  {
    v8 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, m_EventUID);
    if ( v8 )
    {
      v9 = *(UFG::HandlerNode **)&v8->mCount;
      p_mUID = &v8->mNULL.mUID;
      if ( v9 != (UFG::HandlerNode *)&v8->mNULL.mUID )
      {
        v11 = &this->mCachedNextNode[v7];
        do
        {
          mNext = (unsigned int *)v9->mNext;
          *v11 = (UFG::HandlerNode *)mNext;
          v13 = mNext != p_mUID;
          ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::Event *))v9->HandlerFunction.m_Closure.m_pFunction)(
            v9->HandlerFunction.m_Closure.m_pthis,
            evt);
          v9 = *v11;
        }
        while ( v13 );
      }
    }
  }
  this->mCachedNextNode[v7] = 0i64;
  ((void (__fastcall *)(UFG::Event *, __int64, UFG::EventDispatcher *))evt->vfptr->__vecDelDtor)(evt, 1i64, v6);
}

// File Line: 333
// RVA: 0x1B5D20
void __fastcall UFG::EventDispatcher::EventDispatcher(UFG::EventDispatcher *this)
{
  Render::Skinning *p_m_ChannelTree; // rdi

  p_m_ChannelTree = (Render::Skinning *)&this->m_ChannelTree;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_ChannelTree.mTree);
  `eh vector constructor iterator(
    this->QueuedEventList,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  this->mSortedChannelList.mNode.mPrev = &this->mSortedChannelList.mNode;
  this->mSortedChannelList.mNode.mNext = &this->mSortedChannelList.mNode;
  UFG::qBaseTreeRB::~qBaseTreeRB(p_m_ChannelTree);
  this->mListIndex = 0;
  memset(this, 0, 0x80ui64);
}

// File Line: 344
// RVA: 0x1B5DF0
void __fastcall UFG::EventDispatcher::~EventDispatcher(UFG::EventDispatcher *this)
{
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mNext; // rbx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *p_mSortedChannelList; // rsi
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v4; // rcx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> **p_mNext; // r8
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mPrev; // rdx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v7; // rdx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v8; // rax
  UFG::EventDispatcher *i; // rax
  UFG::HandlerNode **v10; // rdx
  UFG::HandlerNode *v11; // rcx
  UFG::HandlerNode *v12; // rax
  UFG::EventDispatcher *j; // rax
  UFG::HandlerNode **v14; // rdx
  UFG::HandlerNode *v15; // rcx
  UFG::HandlerNode *v16; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v17; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v18; // rax

  mNext = this->mSortedChannelList.mNode.mNext;
  p_mSortedChannelList = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mSortedChannelList;
  if ( mNext != (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&this->mSortedChannelList )
  {
    do
    {
      v4 = mNext;
      p_mNext = &mNext->mNext;
      mNext = mNext->mNext;
      if ( LOBYTE(v4[2].mNext[3].mPrev) == 1 )
      {
        mPrev = v4->mPrev;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v4->mPrev = v4;
        *p_mNext = v4;
        v7 = v4->mPrev;
        v8 = *p_mNext;
        v7->mNext = *p_mNext;
        v8->mPrev = v7;
        v4->mPrev = v4;
        *p_mNext = v4;
        operator delete[](v4);
      }
    }
    while ( mNext != (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)p_mSortedChannelList );
  }
  for ( i = (UFG::EventDispatcher *)&this->QueuedEventList[0].mNode.mNext[-1].mNext;
        i != (UFG::EventDispatcher *)&this->mListIndex;
        i = (UFG::EventDispatcher *)&this->QueuedEventList[0].mNode.mNext[-1].mNext )
  {
    v10 = &i->mCachedNextNode[1];
    v11 = i->mCachedNextNode[1];
    v12 = i->mCachedNextNode[2];
    v11->mNext = v12;
    v12->mPrev = v11;
    *v10 = (UFG::HandlerNode *)v10;
    v10[1] = (UFG::HandlerNode *)v10;
    if ( v10 != (UFG::HandlerNode **)8 )
      ((void (__fastcall *)(UFG::HandlerNode **, __int64))(*(v10 - 1))->mPrev)(v10 - 1, 1i64);
  }
  for ( j = (UFG::EventDispatcher *)&this->QueuedEventList[1].mNode.mNext[-1].mNext;
        j != (UFG::EventDispatcher *)&this->QueuedEventList[0].mNode.mNext;
        j = (UFG::EventDispatcher *)&this->QueuedEventList[1].mNode.mNext[-1].mNext )
  {
    v14 = &j->mCachedNextNode[1];
    v15 = j->mCachedNextNode[1];
    v16 = j->mCachedNextNode[2];
    v15->mNext = v16;
    v16->mPrev = v15;
    *v14 = (UFG::HandlerNode *)v14;
    v14[1] = (UFG::HandlerNode *)v14;
    if ( v14 != (UFG::HandlerNode **)8 )
      ((void (__fastcall *)(UFG::HandlerNode **, __int64))(*(v14 - 1))->mPrev)(v14 - 1, 1i64);
  }
  UFG::qTreeRB<UFG::EventChannel,UFG::EventChannel,1>::DeleteAll(&this->m_ChannelTree);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes(p_mSortedChannelList);
  v17 = p_mSortedChannelList->mNode.mPrev;
  v18 = p_mSortedChannelList->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mSortedChannelList->mNode.mPrev = &p_mSortedChannelList->mNode;
  p_mSortedChannelList->mNode.mNext = &p_mSortedChannelList->mNode;
  `eh vector destructor iterator(
    this->QueuedEventList,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0>::~qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0>);
  UFG::qTreeRB<UFG::EventChannel,UFG::EventChannel,1>::DeleteAll(&this->m_ChannelTree);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->m_ChannelTree);
}

// File Line: 457
// RVA: 0x1B6230
__int64 __fastcall UFG::EventDispatcher::DeleteDynamicChannel(
        UFG::EventDispatcher *this,
        unsigned int uid,
        UFG::qBaseTreeRB *channel)
{
  UFG::qBaseTreeRB *v3; // rdi
  UFG::qBaseNodeRB *v5; // rcx
  UFG::qBaseNodeRB *mParent; // rdx
  UFG::qBaseNodeRB *v7; // rax
  UFG::qBaseNodeRB *v8; // rdx
  UFG::qBaseNodeRB *v9; // rax
  __int64 v10; // rdx
  _QWORD *v11; // rcx

  v3 = channel;
  if ( !channel && uid )
    v3 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, uid);
  if ( !v3 )
    return 1i64;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v3->mNULL.mUID);
  v5 = v3->mNULL.mChild[0];
  mParent = v5->mParent;
  v7 = v5->mChild[0];
  mParent->mChild[0] = v7;
  v7->mParent = mParent;
  v5->mParent = v5;
  v5->mChild[0] = v5;
  v8 = v5->mParent;
  v9 = v5->mChild[0];
  v8->mChild[0] = v9;
  v9->mParent = v8;
  v5->mParent = v5;
  v5->mChild[0] = v5;
  operator delete[](v5);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->m_ChannelTree,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v3->mNULL.mUID);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v3->mNULL.mUID);
  v10 = *(_QWORD *)&v3->mNULL.mUID;
  v11 = *(_QWORD **)&v3->mCount;
  *(_QWORD *)(v10 + 8) = v11;
  *v11 = v10;
  *(_QWORD *)&v3->mNULL.mUID = &v3->mNULL.mUID;
  *(_QWORD *)&v3->mCount = &v3->mNULL.mUID;
  operator delete[](v3);
  return 0i64;
}

// File Line: 495
// RVA: 0x1B6030
UFG::qBaseTreeRB *__fastcall UFG::EventDispatcher::CreateChannel(
        UFG::EventDispatcher *this,
        unsigned int uid,
        UFG::allocator::free_link *co,
        bool dynamic_flag)
{
  UFG::qBaseTreeRB *result; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qBaseNodeRB *v10; // rbx

  if ( uid )
    result = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, uid);
  else
    result = 0i64;
  if ( !result )
  {
    v9 = UFG::qMalloc(0x48ui64, "eventsys.EventChannel", 0i64);
    v10 = (UFG::qBaseNodeRB *)v9;
    if ( v9 )
    {
      v9->mNext = 0i64;
      v9[1].mNext = 0i64;
      v9[2].mNext = 0i64;
      LODWORD(v9[3].mNext) = uid;
      LODWORD(v9[4].mNext) = uid;
      v9[5].mNext = co;
      LOBYTE(v9[6].mNext) = dynamic_flag;
      v9[7].mNext = v9 + 7;
      v9[8].mNext = v9 + 7;
    }
    else
    {
      v10 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->m_ChannelTree.mTree, v10);
    return (UFG::qBaseTreeRB *)v10;
  }
  return result;
}

// File Line: 530
// RVA: 0x1B65C0
UFG::allocator::free_link *__fastcall UFG::EventDispatcher::Register(
        UFG::EventDispatcher *this,
        fastdelegate::FastDelegate1<UFG::Event *,void> *handler,
        unsigned int uid,
        const char *name,
        unsigned int depID)
{
  UFG::qBaseTreeRB *v6; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v8; // [rsp+20h] [rbp-18h] BYREF

  if ( !uid )
    return 0i64;
  v6 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, uid);
  if ( !v6 )
    return 0i64;
  v8 = *handler;
  return UFG::EventChannel::AddHandler((UFG::EventChannel *)v6, &v8, depID);
}

// File Line: 578
// RVA: 0x1B6890
signed __int64 __fastcall UFG::EventDispatcher::UnRegister(
        UFG::EventDispatcher *this,
        fastdelegate::FastDelegate1<UFG::Event *,void> *handler,
        unsigned int channel_id)
{
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  void (__fastcall *m_pFunction)(fastdelegate::detail::GenericClass *); // r8
  unsigned int v8; // esi
  fastdelegate::FastDelegate1<UFG::Event *,void> v10; // [rsp+20h] [rbp-18h] BYREF

  if ( !channel_id )
    return 1i64;
  v5 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, channel_id);
  v6 = v5;
  if ( !v5 )
    return 1i64;
  m_pFunction = handler->m_Closure.m_pFunction;
  v10.m_Closure.m_pthis = handler->m_Closure.m_pthis;
  v10.m_Closure.m_pFunction = m_pFunction;
  v8 = UFG::EventChannel::RemoveHandler((UFG::EventChannel *)v5, &v10);
  if ( LOBYTE(v6->mNULL.mChild[1]) )
  {
    if ( *(UFG::qBaseTreeRB **)&v6->mCount == (UFG::qBaseTreeRB *)&v6->mNULL.mUID )
      UFG::EventDispatcher::DeleteDynamicChannel(this, (unsigned int)v6->mNULL.mParent, 0i64);
  }
  return v8;
}

// File Line: 604
// RVA: 0x1B6810
signed __int64 __fastcall UFG::EventDispatcher::UnRegister(
        UFG::EventDispatcher *this,
        struct UFG::EventHandlerCookieTag *cookie,
        unsigned int channel_id)
{
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  unsigned int v7; // edi

  if ( !channel_id )
    return 1i64;
  v5 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, channel_id);
  v6 = v5;
  if ( !v5 )
    return 1i64;
  v7 = UFG::EventChannel::RemoveHandler((UFG::EventChannel *)v5, cookie);
  if ( LOBYTE(v6->mNULL.mChild[1]) )
  {
    if ( *(UFG::qBaseTreeRB **)&v6->mCount == (UFG::qBaseTreeRB *)&v6->mNULL.mUID )
      UFG::EventDispatcher::DeleteDynamicChannel(this, (unsigned int)v6->mNULL.mParent, 0i64);
  }
  return v7;
}

// File Line: 630
// RVA: 0x1B6740
void __fastcall UFG::EventDispatcher::StaticLinkUp(UFG::ChannelObj *chanToAdd, int addToList)
{
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mNext; // rax
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mPrev; // rdx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v6; // rcx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v7; // rcx

  if ( (_S1_23 & 1) == 0 )
  {
    _S1_23 |= 1u;
    localList.mNode.mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    atexit(UFG::EventDispatcher::StaticLinkUp_::_2_::_dynamic_atexit_destructor_for__localList__);
  }
  mNext = localList.mNode.mNext;
  if ( addToList )
  {
    localList.mNode.mNext = chanToAdd;
    chanToAdd->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    chanToAdd->mNext = mNext;
    mNext->mPrev = chanToAdd;
  }
  else
  {
    for ( ;
          (UFG::qList<UFG::ChannelObj,UFG::ChannelObj,1,0> *)localList.mNode.mNext != &localList;
          mNext = localList.mNode.mNext )
    {
      mPrev = mNext->mPrev;
      v6 = mNext->mNext;
      mPrev->mNext = v6;
      v6->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v7 = UFG::EventDispatcher::mInstance.mSortedChannelList.mNode.mNext;
      UFG::EventDispatcher::mInstance.mSortedChannelList.mNode.mNext = mNext;
      mNext->mPrev = &UFG::EventDispatcher::mInstance.mSortedChannelList.mNode;
      mNext->mNext = v7;
      v7->mPrev = mNext;
    }
  }
}

// File Line: 649
// RVA: 0x1B6530
void __fastcall UFG::EventDispatcher::Initialize(UFG::EventDispatcher *this)
{
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *mNext; // rbx
  UFG::qList<UFG::ChannelObj,UFG::ChannelObj,1,0> *i; // rdi

  UFG::EventDispatcher::StaticLinkUp(0i64, 0);
  mNext = this->mSortedChannelList.mNode.mNext;
  for ( i = &this->mSortedChannelList; mNext != (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)i; mNext = mNext->mNext )
    mNext[2].mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)UFG::EventDispatcher::CreateChannel(
                                                                      &UFG::EventDispatcher::mInstance,
                                                                      (unsigned int)mNext[1].mNext,
                                                                      (UFG::allocator::free_link *)mNext,
                                                                      0);
}

