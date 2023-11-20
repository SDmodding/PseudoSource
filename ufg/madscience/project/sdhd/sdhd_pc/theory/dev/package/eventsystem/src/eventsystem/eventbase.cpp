// File Line: 20
// RVA: 0x146A8B0
__int64 dynamic_initializer_for__UFG::EventDispatcher::mInstance__()
{
  UFG::EventDispatcher::EventDispatcher(&UFG::EventDispatcher::mInstance);
  return atexit(dynamic_atexit_destructor_for__UFG::EventDispatcher::mInstance__);
}

// File Line: 24
// RVA: 0x1B5C80
void __fastcall UFG::ChannelObj::ChannelObj(UFG::ChannelObj *this, const char *name, const char *desc)
{
  UFG::ChannelObj *v3; // rbx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v4; // rax

  v3 = this;
  this->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&this->mPrev;
  this->mName = name;
  this->mDescription = desc;
  this->mUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  if ( !(_S1_23 & 1) )
  {
    _S1_23 |= 1u;
    localList.mNode.mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    atexit(UFG::EventDispatcher::StaticLinkUp_::_2_::_dynamic_atexit_destructor_for__localList__);
  }
  v4 = localList.mNode.mNext;
  localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&v3->mPrev;
  v3->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
  v3->mNext = v4;
  v4->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&v3->mPrev;
}

// File Line: 33
// RVA: 0x1B5BF0
void __fastcall UFG::ChannelObj::ChannelObj(UFG::ChannelObj *this, const unsigned int uid, const char *name, const char *desc)
{
  UFG::ChannelObj *v4; // rbx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v5; // rax

  v4 = this;
  this->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&this->mPrev;
  this->mName = name;
  this->mDescription = desc;
  this->mUID = uid;
  if ( !(_S1_23 & 1) )
  {
    _S1_23 |= 1u;
    localList.mNode.mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    atexit(UFG::EventDispatcher::StaticLinkUp_::_2_::_dynamic_atexit_destructor_for__localList__);
  }
  v5 = localList.mNode.mNext;
  localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&v4->mPrev;
  v4->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
  v4->mNext = v5;
  v5->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&v4->mPrev;
}

// File Line: 148
// RVA: 0x1B5F90
UFG::allocator::free_link *__fastcall UFG::EventChannel::AddHandler(UFG::EventChannel *this, fastdelegate::FastDelegate1<UFG::Event *,void> *eh, unsigned int dependencyID)
{
  unsigned int v3; // esi
  fastdelegate::FastDelegate1<UFG::Event *,void> *v4; // rdi
  UFG::EventChannel *v5; // rbx
  UFG::allocator::free_link *v6; // r9
  void (__fastcall *v7)(fastdelegate::detail::GenericClass *); // rax
  UFG::allocator::free_link *v8; // rdx
  UFG::allocator::free_link *v9; // rcx

  v3 = dependencyID;
  v4 = eh;
  v5 = this;
  v6 = UFG::qMalloc(0x30ui64, "eventsys.HandlerNode", 0i64);
  if ( v6 )
  {
    v7 = v4->m_Closure.m_pFunction;
    v8 = (UFG::allocator::free_link *)v4->m_Closure.m_pthis;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v6[3].mNext = (UFG::allocator::free_link *)v7;
    v6[2].mNext = v8;
    LODWORD(v6[4].mNext) = v3;
    *(UFG::allocator::free_link **)((char *)&v6[4].mNext + 4) = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::allocator::free_link *)v5->m_HandlerList.mNode.mPrev;
  v9[1].mNext = v6;
  v6->mNext = v9;
  v6[1].mNext = (UFG::allocator::free_link *)&v5->m_HandlerList;
  v5->m_HandlerList.mNode.mPrev = (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)v6;
  return v6;
}

// File Line: 160
// RVA: 0x1B6690
signed __int64 __fastcall UFG::EventChannel::RemoveHandler(UFG::EventChannel *this, fastdelegate::FastDelegate1<UFG::Event *,void> *handler)
{
  UFG::EventChannel *v2; // rax
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v3; // rcx
  signed __int64 v4; // rax
  UFG::EventDispatcher *v5; // rdx
  signed __int64 v6; // r8
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v7; // rdx
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v8; // rax
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v9; // rdx
  UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *v10; // rax

  v2 = this;
  v3 = this->m_HandlerList.mNode.mNext;
  v4 = (signed __int64)&v2->m_HandlerList;
  while ( 1 )
  {
    if ( v3 == (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)v4 )
      return 1i64;
    if ( *(_OWORD *)&v3[1] == *(_OWORD *)handler )
      break;
    v3 = v3->mNext;
  }
  if ( !v3 )
    return 1i64;
  v5 = &UFG::EventDispatcher::mInstance;
  v6 = 16i64;
  do
  {
    if ( (UFG::qNode<UFG::HandlerNode,UFG::HandlerNode> *)v5->mCachedNextNode[0] == v3 )
      v5->mCachedNextNode[0] = (UFG::HandlerNode *)v5->mCachedNextNode[0]->mNext;
    v5 = (UFG::EventDispatcher *)((char *)v5 + 8);
    --v6;
  }
  while ( v6 );
  v7 = v3->mPrev;
  v8 = v3->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v3->mPrev = v3;
  v3->mNext = v3;
  v9 = v3->mPrev;
  v10 = v3->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v3->mPrev = v3;
  v3->mNext = v3;
  operator delete[](v3);
  return 0i64;
}

// File Line: 177
// RVA: 0x1B6610
__int64 __fastcall UFG::EventChannel::RemoveHandler(UFG::EventChannel *this, struct UFG::EventHandlerCookieTag *cookie)
{
  UFG::EventDispatcher *v2; // rax
  signed __int64 v3; // r8
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
  operator delete[]((void *)cookie);
  return 0i64;
}

// File Line: 240
// RVA: 0x1B6590
void __fastcall UFG::EventDispatcher::QueueEvent(UFG::EventDispatcher *this, UFG::Event *event)
{
  UFG::HandlerNode **v2; // r8
  UFG::qNode<UFG::Event,UFG::Event> *v3; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v4; // rax

  v2 = &this->mCachedNextNode[2 * (this->mListIndex + 13i64)];
  v3 = (UFG::qNode<UFG::Event,UFG::Event> *)&event->mPrev;
  v4 = (UFG::qNode<UFG::Event,UFG::Event> *)*v2;
  v4->mNext = (UFG::qNode<UFG::Event,UFG::Event> *)&event->mPrev;
  v3->mPrev = v4;
  v3->mNext = (UFG::qNode<UFG::Event,UFG::Event> *)v2;
  *v2 = (UFG::HandlerNode *)&event->mPrev;
}

// File Line: 249
// RVA: 0x1B6380
void __fastcall UFG::EventDispatcher::DispatchAllQueuedEvents(UFG::EventDispatcher *this)
{
  __int64 v1; // rdx
  __int64 v2; // rbp
  UFG::EventDispatcher *v3; // rdi
  UFG::Event *v4; // rsi
  UFG::Event *v5; // rdx
  signed __int64 v6; // rbx
  signed __int64 v7; // r8
  __int64 *i; // rax
  _QWORD *v9; // rcx
  __int64 v10; // rdx

  v1 = this->mListIndex;
  v2 = v1;
  v3 = this;
  this->mListIndex = v1 ^ 1;
  v4 = (UFG::Event *)(&this->mListIndex + 4 * v1);
  v5 = (UFG::Event *)&this->QueuedEventList[v1].mNode.mNext[-1].mNext;
  if ( v5 != v4 )
  {
    do
    {
      v6 = (signed __int64)&v5->mNext[-1].mNext;
      UFG::EventDispatcher::DispatchEvent(v3, v5);
      v5 = (UFG::Event *)v6;
    }
    while ( (UFG::Event *)v6 != v4 );
  }
  v7 = (signed __int64)v3 + 16 * (v2 + 13);
  for ( i = *(__int64 **)(v7 + 8); i - 1 != (__int64 *)(v7 - 8); i = *(__int64 **)(v7 + 8) )
  {
    v9 = (_QWORD *)i[1];
    v10 = *i;
    *(_QWORD *)(v10 + 8) = v9;
    *v9 = v10;
    *i = (__int64)i;
    i[1] = (__int64)i;
  }
}

// File Line: 280
// RVA: 0x1B6460
void __fastcall UFG::EventDispatcher::DispatchEvent(UFG::EventDispatcher *this, UFG::Event *evt)
{
  unsigned int v2; // eax
  UFG::Event *v3; // r14
  unsigned int v4; // edx
  UFG::EventDispatcher *v5; // r15
  UFG::EventDispatcher *v6; // r8
  unsigned int v7; // er12
  UFG::qBaseTreeRB *v8; // rax
  UFG::HandlerNode *v9; // rdi
  signed __int64 v10; // rbp
  UFG::HandlerNode **v11; // rsi
  UFG::HandlerNode *v12; // rax
  bool v13; // bl

  v2 = 0;
  v3 = evt;
  v4 = evt->m_EventUID;
  v5 = this;
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
  if ( v4 )
  {
    v8 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, v4);
    if ( v8 )
    {
      v9 = *(UFG::HandlerNode **)&v8->mCount;
      v10 = (signed __int64)&v8->mNULL.mUID;
      if ( v9 != (UFG::HandlerNode *)&v8->mNULL.mUID )
      {
        v11 = &v5->mCachedNextNode[v7];
        do
        {
          v12 = (UFG::HandlerNode *)v9->mNext;
          *v11 = v12;
          v13 = v12 != (UFG::HandlerNode *)v10;
          ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::Event *))v9->HandlerFunction.m_Closure.m_pFunction)(
            v9->HandlerFunction.m_Closure.m_pthis,
            v3);
          v9 = *v11;
        }
        while ( v13 );
      }
    }
  }
  v5->mCachedNextNode[v7] = 0i64;
  ((void (__fastcall *)(UFG::Event *, signed __int64, UFG::EventDispatcher *))v3->vfptr->__vecDelDtor)(v3, 1i64, v6);
}

// File Line: 333
// RVA: 0x1B5D20
void __fastcall UFG::EventDispatcher::EventDispatcher(UFG::EventDispatcher *this)
{
  UFG::EventDispatcher *v1; // rbx
  Render::Skinning *v2; // rdi
  UFG::qList<UFG::ChannelObj,UFG::ChannelObj,1,0> *v3; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = (Render::Skinning *)&this->m_ChannelTree;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_ChannelTree.mTree);
  `eh vector constructor iterator(
    v1->QueuedEventList,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  v3 = &v1->mSortedChannelList;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  UFG::qBaseTreeRB::~qBaseTreeRB(v2);
  v1->mListIndex = 0;
  memset(v1, 0, 0x80ui64);
}

// File Line: 344
// RVA: 0x1B5DF0
void __fastcall UFG::EventDispatcher::~EventDispatcher(UFG::EventDispatcher *this)
{
  UFG::EventDispatcher *v1; // rdi
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v2; // rbx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v3; // rsi
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v4; // rcx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> **v5; // r8
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v6; // rdx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v7; // rdx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v8; // rax
  signed __int64 i; // rax
  _QWORD *v10; // rdx
  __int64 v11; // rcx
  _QWORD *v12; // rax
  signed __int64 j; // rax
  _QWORD *v14; // rdx
  __int64 v15; // rcx
  _QWORD *v16; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v17; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v18; // rax

  v1 = this;
  v2 = this->mSortedChannelList.mNode.mNext;
  v3 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mSortedChannelList;
  if ( v2 != (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&this->mSortedChannelList )
  {
    do
    {
      v4 = v2;
      v5 = &v2->mNext;
      v2 = v2->mNext;
      if ( LOBYTE(v4[2].mNext[3].mPrev) == 1 )
      {
        v6 = v4->mPrev;
        v6->mNext = v2;
        v2->mPrev = v6;
        v4->mPrev = v4;
        *v5 = v4;
        v7 = v4->mPrev;
        v8 = *v5;
        v7->mNext = *v5;
        v8->mPrev = v7;
        v4->mPrev = v4;
        *v5 = v4;
        operator delete[](v4);
      }
    }
    while ( v2 != (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)v3 );
  }
  for ( i = (signed __int64)&v1->QueuedEventList[0].mNode.mNext[-1].mNext;
        (int *)i != &v1->mListIndex;
        i = (signed __int64)&v1->QueuedEventList[0].mNode.mNext[-1].mNext )
  {
    v10 = (_QWORD *)(i + 8);
    v11 = *(_QWORD *)(i + 8);
    v12 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    *v10 = v10;
    v10[1] = v10;
    if ( v10 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v10 - 1))(v10 - 1, 1i64);
  }
  for ( j = (signed __int64)&v1->QueuedEventList[1].mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::Event,UFG::Event> **)j != &v1->QueuedEventList[0].mNode.mNext;
        j = (signed __int64)&v1->QueuedEventList[1].mNode.mNext[-1].mNext )
  {
    v14 = (_QWORD *)(j + 8);
    v15 = *(_QWORD *)(j + 8);
    v16 = *(_QWORD **)(j + 16);
    *(_QWORD *)(v15 + 8) = v16;
    *v16 = v15;
    *v14 = v14;
    v14[1] = v14;
    if ( v14 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v14 - 1))(v14 - 1, 1i64);
  }
  UFG::qTreeRB<UFG::EventChannel,UFG::EventChannel,1>::DeleteAll(&v1->m_ChannelTree);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes(v3);
  v17 = v3->mNode.mPrev;
  v18 = v3->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  `eh vector destructor iterator(
    v1->QueuedEventList,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0>::~qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0>);
  UFG::qTreeRB<UFG::EventChannel,UFG::EventChannel,1>::DeleteAll(&v1->m_ChannelTree);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->m_ChannelTree);
}

// File Line: 457
// RVA: 0x1B6230
signed __int64 __fastcall UFG::EventDispatcher::DeleteDynamicChannel(UFG::EventDispatcher *this, const unsigned int uid, UFG::EventChannel *channel)
{
  char *v3; // rdi
  UFG::EventDispatcher *v4; // rsi
  __int64 *v5; // rcx
  __int64 v6; // rdx
  _QWORD *v7; // rax
  __int64 v8; // rdx
  _QWORD *v9; // rax
  __int64 v10; // rdx
  _QWORD *v11; // rcx

  v3 = (char *)channel;
  v4 = this;
  if ( !channel && uid )
    v3 = (char *)UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, uid);
  if ( !v3 )
    return 1i64;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)(v3 + 56));
  v5 = (__int64 *)*((_QWORD *)v3 + 5);
  v6 = *v5;
  v7 = (_QWORD *)v5[1];
  *(_QWORD *)(v6 + 8) = v7;
  *v7 = v6;
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  v8 = *v5;
  v9 = (_QWORD *)v5[1];
  *(_QWORD *)(v8 + 8) = v9;
  *v9 = v8;
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  operator delete[](v5);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v4->m_ChannelTree,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)(v3 + 56));
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)(v3 + 56));
  v10 = *((_QWORD *)v3 + 7);
  v11 = (_QWORD *)*((_QWORD *)v3 + 8);
  *(_QWORD *)(v10 + 8) = v11;
  *v11 = v10;
  *((_QWORD *)v3 + 7) = v3 + 56;
  *((_QWORD *)v3 + 8) = v3 + 56;
  operator delete[](v3);
  return 0i64;
}

// File Line: 495
// RVA: 0x1B6030
UFG::qBaseTreeRB *__fastcall UFG::EventDispatcher::CreateChannel(UFG::EventDispatcher *this, const unsigned int uid, UFG::ChannelObj *co, bool dynamic_flag)
{
  bool v4; // bp
  UFG::ChannelObj *v5; // r14
  unsigned int v6; // edi
  UFG::EventDispatcher *v7; // rsi
  UFG::qBaseTreeRB *result; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::EventChannel *v10; // rbx
  UFG::allocator::free_link *v11; // ST30_8

  v4 = dynamic_flag;
  v5 = co;
  v6 = uid;
  v7 = this;
  if ( uid )
    result = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, uid);
  else
    result = 0i64;
  if ( !result )
  {
    v9 = UFG::qMalloc(0x48ui64, "eventsys.EventChannel", 0i64);
    v10 = (UFG::EventChannel *)v9;
    if ( v9 )
    {
      v9->mNext = 0i64;
      v9[1].mNext = 0i64;
      v9[2].mNext = 0i64;
      LODWORD(v9[3].mNext) = v6;
      LODWORD(v9[4].mNext) = v6;
      v9[5].mNext = (UFG::allocator::free_link *)v5;
      LOBYTE(v9[6].mNext) = v4;
      v11 = v9 + 7;
      v11->mNext = v11;
      v11[1].mNext = v11;
    }
    else
    {
      v10 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&v7->m_ChannelTree.mTree, &v10->mNode);
    result = (UFG::qBaseTreeRB *)v10;
  }
  return result;
}

// File Line: 530
// RVA: 0x1B65C0
UFG::allocator::free_link *__fastcall UFG::EventDispatcher::Register(UFG::EventDispatcher *this, fastdelegate::FastDelegate1<UFG::Event *,void> *handler, unsigned int uid, const char *name, unsigned int depID)
{
  __int64 *v5; // rbx
  UFG::qBaseTreeRB *v6; // rax
  __int64 v8; // [rsp+20h] [rbp-18h]
  __int64 v9; // [rsp+28h] [rbp-10h]

  v5 = (__int64 *)handler;
  if ( !uid )
    return 0i64;
  v6 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, uid);
  if ( !v6 )
    return 0i64;
  v9 = v5[1];
  v8 = *v5;
  return UFG::EventChannel::AddHandler(
           (UFG::EventChannel *)v6,
           (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v8,
           depID);
}

// File Line: 578
// RVA: 0x1B6890
signed __int64 __fastcall UFG::EventDispatcher::UnRegister(UFG::EventDispatcher *this, fastdelegate::FastDelegate1<UFG::Event *,void> *handler, unsigned int channel_id)
{
  __int64 *v3; // rsi
  UFG::EventDispatcher *v4; // rdi
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  __int64 v7; // r8
  unsigned int v8; // esi
  __int64 v10; // [rsp+20h] [rbp-18h]
  __int64 v11; // [rsp+28h] [rbp-10h]

  v3 = (__int64 *)handler;
  v4 = this;
  if ( !channel_id )
    return 1i64;
  v5 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, channel_id);
  v6 = v5;
  if ( !v5 )
    return 1i64;
  v7 = v3[1];
  v10 = *v3;
  v11 = v7;
  v8 = UFG::EventChannel::RemoveHandler((UFG::EventChannel *)v5, (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10);
  if ( LOBYTE(v6->mNULL.mChild[1]) )
  {
    if ( *(UFG::qBaseTreeRB **)&v6->mCount == (UFG::qBaseTreeRB *)&v6->mNULL.mUID )
      UFG::EventDispatcher::DeleteDynamicChannel(v4, (const unsigned int)v6->mNULL.mParent, 0i64);
  }
  return v8;
}

// File Line: 604
// RVA: 0x1B6810
signed __int64 __fastcall UFG::EventDispatcher::UnRegister(UFG::EventDispatcher *this, struct UFG::EventHandlerCookieTag *cookie, unsigned int channel_id)
{
  struct UFG::EventHandlerCookieTag *v3; // rdi
  UFG::EventDispatcher *v4; // rsi
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  unsigned int v7; // edi

  v3 = cookie;
  v4 = this;
  if ( !channel_id )
    return 1i64;
  v5 = UFG::qBaseTreeRB::Get(&this->m_ChannelTree.mTree, channel_id);
  v6 = v5;
  if ( !v5 )
    return 1i64;
  v7 = UFG::EventChannel::RemoveHandler((UFG::EventChannel *)v5, v3);
  if ( LOBYTE(v6->mNULL.mChild[1]) )
  {
    if ( *(UFG::qBaseTreeRB **)&v6->mCount == (UFG::qBaseTreeRB *)&v6->mNULL.mUID )
      UFG::EventDispatcher::DeleteDynamicChannel(v4, (const unsigned int)v6->mNULL.mParent, 0i64);
  }
  return v7;
}

// File Line: 630
// RVA: 0x1B6740
void __fastcall UFG::EventDispatcher::StaticLinkUp(UFG::ChannelObj *chanToAdd, int addToList)
{
  int v2; // edi
  UFG::ChannelObj *v3; // rbx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v4; // rax
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v5; // rdx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v6; // rcx
  UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *v7; // rcx

  v2 = addToList;
  v3 = chanToAdd;
  if ( !(_S1_23 & 1) )
  {
    _S1_23 |= 1u;
    localList.mNode.mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    atexit(UFG::EventDispatcher::StaticLinkUp_::_2_::_dynamic_atexit_destructor_for__localList__);
  }
  v4 = localList.mNode.mNext;
  if ( v2 )
  {
    localList.mNode.mNext = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&localList;
    v3->mNext = v4;
    v4->mPrev = (UFG::qNode<UFG::ChannelObj,UFG::ChannelObj> *)&v3->mPrev;
  }
  else
  {
    for ( ;
          (UFG::qList<UFG::ChannelObj,UFG::ChannelObj,1,0> *)localList.mNode.mNext != &localList;
          v4 = localList.mNode.mNext )
    {
      v5 = v4->mPrev;
      v6 = v4->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = v4;
      v4->mNext = v4;
      v7 = UFG::EventDispatcher::mInstance.mSortedChannelList.mNode.mNext;
      UFG::EventDispatcher::mInstance.mSortedChannelList.mNode.mNext = v4;
      v4->mPrev = &UFG::EventDispatcher::mInstance.mSortedChannelList.mNode;
      v4->mNext = v7;
      v7->mPrev = v4;
    }
  }
}

// File Line: 649
// RVA: 0x1B6530
void __fastcall UFG::EventDispatcher::Initialize(UFG::EventDispatcher *this)
{
  UFG::EventDispatcher *v1; // rdi
  UFG::ChannelObj *v2; // rbx
  signed __int64 i; // rdi

  v1 = this;
  UFG::EventDispatcher::StaticLinkUp(0i64, 0);
  v2 = (UFG::ChannelObj *)v1->mSortedChannelList.mNode.mNext;
  for ( i = (signed __int64)&v1->mSortedChannelList; v2 != (UFG::ChannelObj *)i; v2 = (UFG::ChannelObj *)v2->mNext )
    v2->mEventChannel = (UFG::EventChannel *)UFG::EventDispatcher::CreateChannel(
                                               &UFG::EventDispatcher::mInstance,
                                               v2->mUID,
                                               v2,
                                               0);
}

