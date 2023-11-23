// File Line: 23
// RVA: 0xC756E0
void __fastcall hkMonitorStreamStringMap::hkMonitorStreamStringMap(hkMonitorStreamStringMap *this)
{
  this->m_map.m_capacityAndFlags = 0x80000000;
  this->m_map.m_data = 0i64;
  this->m_map.m_size = 0;
}

// File Line: 27
// RVA: 0xC75700
void __fastcall hkMonitorStreamStringMap::hkMonitorStreamStringMap(
        hkMonitorStreamStringMap *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 31
// RVA: 0xC75710
void __fastcall hkMonitorStreamStringMap::StringMap::StringMap(hkMonitorStreamStringMap::StringMap *this)
{
  hkStringPtr::hkStringPtr(&this->m_string);
}

// File Line: 35
// RVA: 0xC75740
void __fastcall hkMonitorStreamStringMap::StringMap::StringMap(
        hkMonitorStreamStringMap::StringMap *this,
        hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_string, f);
}

// File Line: 43
// RVA: 0xC77870
void __fastcall hkMonitorStreamAnalyzer::Node::Node(
        hkMonitorStreamAnalyzer::Node *this,
        hkMonitorStreamAnalyzer::Node *parent,
        const char *name,
        unsigned int type)
{
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *p_m_children; // rdi
  __int64 i; // rax

  this->m_children.m_capacityAndFlags = 0x80000000;
  this->m_children.m_data = 0i64;
  this->m_children.m_size = 0;
  this->m_parent = parent;
  this->m_name = name;
  this->m_userFlags = 0;
  this->m_type.m_storage = type;
  if ( parent )
  {
    p_m_children = &parent->m_children;
    if ( parent->m_children.m_size == (parent->m_children.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&parent->m_children.m_data, 8);
    p_m_children->m_data[p_m_children->m_size++] = this;
  }
  for ( i = 0i64; i < 12; ++i )
  {
    this->m_value[i] = 0.0;
    this->m_count[i] = 0;
  }
  this->m_absoluteStartTime = 0.0;
}

// File Line: 56
// RVA: 0xC779E0
void __fastcall hkMonitorStreamAnalyzer::Node::~Node(hkMonitorStreamAnalyzer::Node *this)
{
  __int64 v1; // rsi
  int i; // edi
  hkMonitorStreamAnalyzer::Node **m_data; // rax
  hkMonitorStreamAnalyzer::Node *v5; // rbp
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  v1 = 0i64;
  for ( i = 0; i < this->m_children.m_size; ++v1 )
  {
    m_data = this->m_children.m_data;
    v5 = m_data[v1];
    if ( v5 )
    {
      hkMonitorStreamAnalyzer::Node::~Node(m_data[v1]);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzer::Node *, __int64))(*Value[11] + 16i64))(
        Value[11],
        v5,
        144i64);
    }
    ++i;
  }
  m_capacityAndFlags = this->m_children.m_capacityAndFlags;
  this->m_children.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_children.m_data,
      8 * m_capacityAndFlags);
  this->m_children.m_capacityAndFlags = 0x80000000;
  this->m_children.m_data = 0i64;
}

// File Line: 65
// RVA: 0xC764C0
char *__fastcall hkMonitorStreamAnalyzer::getStreamBegin(hkMonitorStreamAnalyzer *this)
{
  if ( this->m_data.m_size )
    return this->m_data.m_data;
  else
    return 0i64;
}

// File Line: 84
// RVA: 0xC760A0
void __fastcall hkMonitorStreamAnalyzer::hkMonitorStreamAnalyzer(
        hkMonitorStreamAnalyzer *this,
        int memorySize,
        int numThreads,
        int numSpus)
{
  int v6; // eax
  int v8; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_frameInfos.m_capacityAndFlags = 0x80000000;
  this->m_frameInfos.m_data = 0i64;
  this->m_frameInfos.m_size = 0;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  hkMonitorStreamAnalyzer::g_lastFrameTime = FLOAT_16666_6;
  v6 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < memorySize )
  {
    v8 = 2 * v6;
    if ( memorySize < v8 )
      memorySize = v8;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerDebugAllocator::s_alloc,
      (const void **)&this->m_data.m_data,
      memorySize,
      1);
  }
  this->m_nodeIdForFrameOverview = "Physics 2012";
  hkMonitorStreamAnalyzer::resetNumThreads(this, numThreads, numSpus);
}

// File Line: 93
// RVA: 0xC762A0
void __fastcall hkMonitorStreamAnalyzer::resetNumThreads(hkMonitorStreamAnalyzer *this, int numThreads, int numSpus)
{
  int v3; // r15d
  int v4; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // eax
  __int64 v11; // rbp
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v12; // rsi
  int v13; // ebx
  hkStringPtr *p_m_heading; // rdi
  int m_capacityAndFlags; // eax
  __int64 m_size; // rdx
  int v17; // ecx
  __int64 v18; // rax
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v19; // rdx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  v3 = numSpus + numThreads;
  v4 = this->m_frameInfos.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < numSpus + numThreads )
  {
    v8 = 2 * v4;
    v9 = numSpus + numThreads;
    if ( v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_frameInfos.m_data,
      v9,
      16);
  }
  v10 = this->m_frameInfos.m_size - v3 - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = &this->m_frameInfos.m_data[v3 + v10];
    do
    {
      v13 = v12->m_size - 1;
      if ( v13 >= 0 )
      {
        p_m_heading = &v12->m_data[v13].m_heading;
        do
        {
          hkStringPtr::~hkStringPtr(p_m_heading);
          p_m_heading -= 5;
          --v13;
        }
        while ( v13 >= 0 );
      }
      m_capacityAndFlags = v12->m_capacityAndFlags;
      v12->m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v12->m_data,
          40 * (m_capacityAndFlags & 0x3FFFFFFF));
      v12->m_data = 0i64;
      v12->m_capacityAndFlags = 0x80000000;
      --v12;
      --v11;
    }
    while ( v11 >= 0 );
  }
  m_size = this->m_frameInfos.m_size;
  v17 = v3 - m_size;
  v18 = v3 - (int)m_size;
  v19 = &this->m_frameInfos.m_data[m_size];
  if ( v17 > 0 )
  {
    do
    {
      if ( v19 )
      {
        v19->m_data = 0i64;
        v19->m_size = 0;
        v19->m_capacityAndFlags = 0x80000000;
      }
      ++v19;
      --v18;
    }
    while ( v18 );
  }
  this->m_frameInfos.m_size = v3;
  this->m_numSpus = numSpus;
  this->m_numThreads = numThreads;
  hkMonitorStreamAnalyzer::reset(this);
}

// File Line: 102
// RVA: 0xC76410
void __fastcall hkMonitorStreamAnalyzer::reset(hkMonitorStreamAnalyzer *this)
{
  int v2; // esi
  __int64 v3; // r14
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *m_data; // r15
  int v5; // ebx
  hkMonitorStreamFrameInfo *v6; // rdi

  this->m_data.m_size = 0;
  v2 = 0;
  if ( this->m_frameInfos.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = this->m_frameInfos.m_data;
      v5 = this->m_frameInfos.m_data[v3].m_size - 1;
      if ( v5 >= 0 )
      {
        v6 = &this->m_frameInfos.m_data[v3].m_data[v5];
        do
        {
          hkStringPtr::~hkStringPtr(&v6->m_heading);
          --v6;
          --v5;
        }
        while ( v5 >= 0 );
      }
      m_data[v3].m_size = 0;
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_frameInfos.m_size );
  }
}

// File Line: 122
// RVA: 0xC75770
void __fastcall hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo(hkMonitorStreamFrameInfo *this)
{
  hkStringPtr::hkStringPtr(&this->m_heading, "Unknown Heading");
  *(_QWORD *)&this->m_indexOfTimer1 = 1i64;
  this->m_indexOfTimer0 = 0;
  *(_QWORD *)&this->m_frameStreamStart = 0i64;
  this->m_timerFactor0 = 1.0;
  *(_QWORD *)&this->m_timerFactor1 = 1065353216i64;
}

// File Line: 187
// RVA: 0xC78A40
hkMonitorStreamAnalyzer::applyStringMap

// File Line: 321
// RVA: 0xC78940
void __fastcall hkMonitorStreamAnalyzer::extractStringMap(
        char *frameStart,
        const char *frameEnd,
        hkPointerMap<void const *,char const *,hkContainerHeapAllocator> *map)
{
  unsigned __int64 *v5; // rbx

  if ( frameStart < frameEnd )
  {
    v5 = (unsigned __int64 *)frameStart;
    do
    {
      if ( *v5 >= 0x14 )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &map->m_map,
          &hkContainerHeapAllocator::s_alloc,
          *v5,
          *v5);
        switch ( *(_BYTE *)*v5 )
        {
          case E:
            v5 += 2;
            continue;
          case F:
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &map->m_map,
              &hkContainerHeapAllocator::s_alloc,
              v5[2],
              v5[2]);
            v5 += 3;
            continue;
          case G:
            ++v5;
            continue;
          case I:
            JUMPOUT(0x143030300i64);
          case J:
            JUMPOUT(0x141030303i64);
          case K:
            JUMPOUT(0x142010200i64);
          case L:
            JUMPOUT(0x140000303i64);
          case M:
          case N:
          case O:
          case P:
          case Q:
            JUMPOUT(0x143030303i64);
          case R:
            JUMPOUT(0x140030303i64);
          case S:
            JUMPOUT(0x142030303i64);
          case T:
          case U:
          case V:
            JUMPOUT(0x20CCCCCCCi64);
          case W:
            JUMPOUT(0x14FCA3B48i64);
          case X:
            JUMPOUT(0x140027083i64);
          case Y:
            JUMPOUT(0x18C884400i64);
          case Z:
            JUMPOUT(0x193552024i64);
          case [:
            JUMPOUT(0x188564157i64);
          case \\:
            JUMPOUT(0x1C348EC8Bi64);
          case ]:
            JUMPOUT(0x1C94C68ECi64);
          case ^:
            JUMPOUT(0x18D60247Ci64);
          case _:
            JUMPOUT(0x1CB48F08Bi64);
          case `:
            JUMPOUT(0x17D8D4CFAi64);
          case a:
            JUMPOUT(0x23F387594i64);
          case b:
            JUMPOUT(0x164B48948i64);
          case c:
            JUMPOUT(0x1400000A0i64);
          case d:
            JUMPOUT(0x1C0D98B48i64);
          case e:
            JUMPOUT(0x1B500407Di64);
          case f:
            JUMPOUT(0x17B83480Fi64);
          case g:
            JUMPOUT(0x188397314i64);
          case h:
            JUMPOUT(0x22904C383i64);
          case i:
            JUMPOUT(0x14000020Ei64);
          case j:
            JUMPOUT(0x2088B038Bi64);
          case k:
            JUMPOUT(0x2012B4588i64);
          case l:
            JUMPOUT(0x18D8818E9i64);
          case m:
            JUMPOUT(0x201C88B28i64);
          case n:
            JUMPOUT(0x18D8810E9i64);
          case o:
            JUMPOUT(0x201C88B29i64);
          case p:
            JUMPOUT(0x18D8808E9i64);
          default:
            return;
        }
      }
      v5 = (unsigned __int64 *)((char *)v5 + 4);
    }
    while ( v5 < (unsigned __int64 *)frameEnd );
  }
}

// File Line: 392
// RVA: 0xC76150
hkBool *__fastcall hkMonitorStreamAnalyzer::captureFrameDetails(
        hkMonitorStreamAnalyzer *this,
        hkBool *result,
        const char *monitorStreamBegin,
        const char *monitorStreamEnd,
        hkMonitorStreamFrameInfo *info)
{
  unsigned int v6; // ebp
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v10; // rdi
  hkMonitorStreamFrameInfo *v11; // rcx
  __int64 m_size; // rdx
  __int64 v13; // rbx
  int v14; // eax
  __int64 v15; // rcx
  int v16; // eax
  char *v17; // rcx

  v6 = (_DWORD)monitorStreamEnd - (_DWORD)monitorStreamBegin;
  if ( (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) - this->m_data.m_size >= (int)monitorStreamEnd
                                                                             - (int)monitorStreamBegin )
  {
    v10 = &this->m_frameInfos.m_data[info->m_threadId];
    if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v10->m_data, 40);
    v11 = &v10->m_data[v10->m_size];
    if ( v11 )
      hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo(v11);
    m_size = v10->m_size;
    v13 = (__int64)&v10->m_data[m_size];
    v10->m_size = m_size + 1;
    hkStringPtr::operator=((hkStringPtr *)v13, &info->m_heading);
    *(_DWORD *)(v13 + 8) = info->m_indexOfTimer0;
    *(_DWORD *)(v13 + 12) = info->m_indexOfTimer1;
    *(_DWORD *)(v13 + 16) = info->m_absoluteTimeCounter.m_storage;
    *(float *)(v13 + 20) = info->m_timerFactor0;
    *(float *)(v13 + 24) = info->m_timerFactor1;
    *(_DWORD *)(v13 + 28) = info->m_threadId;
    *(_DWORD *)(v13 + 32) = info->m_frameStreamStart;
    *(_DWORD *)(v13 + 36) = info->m_frameStreamEnd;
    v14 = this->m_data.m_size;
    *(_DWORD *)(v13 + 32) = v14;
    *(_DWORD *)(v13 + 36) = v6 + v14;
    v15 = this->m_data.m_size;
    v16 = v15 + v6;
    v17 = &this->m_data.m_data[v15];
    this->m_data.m_size = v16;
    hkString::memCpy(v17, monitorStreamBegin, v6);
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 424
// RVA: 0xC7A0E0
hkMonitorStreamAnalyzer::Node *__fastcall createNewNode(
        hkMonitorStreamAnalyzer::Node *parent,
        const char *name,
        unsigned int type,
        bool wantNodeReuse)
{
  __int64 v4; // r14
  int v8; // ebx
  __int64 v9; // rdi
  hkMonitorStreamAnalyzer::Node *v10; // rax
  _QWORD **Value; // rax
  hkMonitorStreamAnalyzer::Node *v13; // rax
  __int64 v14; // rax

  v4 = 0i64;
  if ( wantNodeReuse )
  {
    v8 = 0;
    if ( parent )
    {
      v9 = 0i64;
      while ( name && v8 < parent->m_children.m_size )
      {
        v10 = parent->m_children.m_data[v9];
        if ( v10->m_name && !(unsigned int)hkString::strCmp(v10->m_name, name) )
          return parent->m_children.m_data[v8];
        ++v8;
        ++v9;
      }
    }
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           144i64);
  if ( v13 )
  {
    hkMonitorStreamAnalyzer::Node::Node(v13, parent, name, type);
    return (hkMonitorStreamAnalyzer::Node *)v14;
  }
  return (hkMonitorStreamAnalyzer::Node *)v4;
}

// File Line: 444
// RVA: 0xC77920
void __fastcall hkMonitorStreamAnalyzer::Node::setTimers(
        hkMonitorStreamAnalyzer::Node *this,
        hkMonitorStreamFrameInfo *frameInfo,
        hkMonitorStream::TimerCommand *start,
        hkMonitorStream::TimerCommand *end)
{
  __int64 m_indexOfTimer0; // r10
  unsigned int m_time0; // eax
  unsigned int v7; // r9d
  int v8; // eax
  float v9; // xmm0_4
  __int64 m_indexOfTimer1; // r9
  unsigned int m_time1; // eax
  signed int v12; // eax
  float v13; // xmm0_4
  unsigned int m_storage; // eax
  float m_timerFactor1; // xmm1_4
  signed int v16; // eax

  m_indexOfTimer0 = frameInfo->m_indexOfTimer0;
  if ( (unsigned int)m_indexOfTimer0 <= 0xB )
  {
    m_time0 = end->m_time0;
    v7 = start->m_time0;
    if ( m_time0 >= v7 )
      v8 = m_time0 - v7;
    else
      v8 = m_time0 - v7 - 1;
    v9 = (float)v8 * frameInfo->m_timerFactor0;
    ++this->m_count[m_indexOfTimer0];
    this->m_value[m_indexOfTimer0] = v9 + this->m_value[m_indexOfTimer0];
  }
  m_indexOfTimer1 = frameInfo->m_indexOfTimer1;
  if ( (unsigned int)m_indexOfTimer1 <= 0xB )
  {
    m_time1 = end->m_time1;
    if ( end->m_time0 >= start->m_time0 )
      v12 = m_time1 - start->m_time1;
    else
      v12 = m_time1 - start->m_time1 - 1;
    v13 = (float)v12 * frameInfo->m_timerFactor1;
    ++this->m_count[m_indexOfTimer1];
    this->m_value[m_indexOfTimer1] = v13 + this->m_value[m_indexOfTimer1];
  }
  m_storage = frameInfo->m_absoluteTimeCounter.m_storage;
  if ( m_storage )
  {
    if ( m_storage != 1 )
      return;
    m_timerFactor1 = frameInfo->m_timerFactor1;
    v16 = start->m_time1;
  }
  else
  {
    m_timerFactor1 = frameInfo->m_timerFactor0;
    v16 = start->m_time0;
  }
  this->m_absoluteStartTime = m_timerFactor1 * (double)v16;
}

// File Line: 498
// RVA: 0xC7A1B0
char __fastcall findChildWithHint(hkMonitorStreamAnalyzer::Node *mainNode, const char *childName, int *childId)
{
  int v7; // ebx
  __int64 i; // rdi

  if ( mainNode->m_children.m_size > *childId
    && !(unsigned int)hkString::strCmp(mainNode->m_children.m_data[*childId]->m_name, childName) )
  {
    return 1;
  }
  v7 = 0;
  if ( mainNode->m_children.m_size <= 0 )
    return 0;
  for ( i = 0i64; (unsigned int)hkString::strCmp(mainNode->m_children.m_data[i]->m_name, childName); ++i )
  {
    if ( ++v7 >= mainNode->m_children.m_size )
      return 0;
  }
  *childId = v7;
  return 1;
}

// File Line: 516
// RVA: 0xC7A270
void __fastcall reduceMainTree(hkMonitorStreamAnalyzer::Node *node, int destTimerId, float smoothingFactor)
{
  int v4; // ebx
  __int64 v6; // rdi

  v4 = 0;
  node->m_count[destTimerId] = 0;
  node->m_value[destTimerId] = smoothingFactor * node->m_value[destTimerId];
  if ( node->m_children.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      reduceMainTree(node->m_children.m_data[v6], destTimerId, smoothingFactor);
      ++v4;
      ++v6;
    }
    while ( v4 < node->m_children.m_size );
  }
}

// File Line: 527
// RVA: 0xC7A2F0
void __fastcall mergeSubTree(
        hkMonitorStreamAnalyzer::Node *mainTree,
        hkMonitorStreamAnalyzer::Node *subTree,
        int destTimerId,
        int sourceTimerId,
        float smoothingFactor)
{
  hkMonitorStreamAnalyzer::Node *v5; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkMonitorStreamAnalyzer::Node *v8; // rbp
  char ChildWithHint; // al
  int v10; // ebx
  _QWORD **Value; // rax
  hkMonitorStreamAnalyzer::Node *v12; // rax
  hkMonitorStreamAnalyzer::Node *v13; // rax
  hkMonitorStreamAnalyzer::Node *v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rax
  int m_size; // ecx
  int childId; // [rsp+30h] [rbp-68h] BYREF
  __int64 v19; // [rsp+38h] [rbp-60h]
  __int64 v20; // [rsp+40h] [rbp-58h]
  hkMonitorStreamAnalyzer::Node *v22; // [rsp+A8h] [rbp+10h]
  int destTimerIda; // [rsp+B0h] [rbp+18h]

  v22 = subTree;
  v5 = mainTree;
  if ( destTimerId >= 12 )
    destTimerId = 11;
  v6 = 0;
  childId = 0;
  destTimerIda = destTimerId;
  v20 = destTimerId;
  if ( subTree->m_children.m_size > 0 )
  {
    v7 = 0i64;
    v19 = sourceTimerId;
    do
    {
      v8 = subTree->m_children.m_data[v7];
      ChildWithHint = findChildWithHint(v5, v8->m_name, &childId);
      v10 = childId;
      if ( ChildWithHint )
      {
        v14 = mainTree->m_children.m_data[childId];
      }
      else
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v12 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                 Value[11],
                                                 144i64);
        if ( v12 )
        {
          hkMonitorStreamAnalyzer::Node::Node(v12, mainTree, v8->m_name, v8->m_type.m_storage);
          v14 = v13;
        }
        else
        {
          v14 = 0i64;
        }
      }
      v15 = v20;
      v16 = v19;
      v14->m_value[v20] = (float)((float)(1.0 - smoothingFactor) * v8->m_value[v19]) + v14->m_value[v20];
      v14->m_count[v15] = v8->m_count[v16];
      mergeSubTree(v14, v8, destTimerIda, sourceTimerId, smoothingFactor);
      subTree = v22;
      m_size = v22->m_children.m_size;
      if ( v10 < m_size - 1 )
        childId = v10 + 1;
      v5 = mainTree;
      ++v6;
      ++v7;
    }
    while ( v6 < m_size );
  }
}

// File Line: 564
// RVA: 0xC774B0
void __fastcall hkMonitorStreamAnalyzer::mergeTreesForCombinedThreadSummary(
        hkMonitorStreamAnalyzer::Node *mainTree,
        hkMonitorStreamAnalyzer::Node *subTree,
        int destTimerId,
        int sourceTimerId,
        float smoothingFactor)
{
  hkMonitorStreamAnalyzer::Node *v5; // rax
  int v6; // r8d
  int v7; // r9d
  hkMonitorStreamAnalyzer::Node *v8; // r10

  reduceMainTree(mainTree, destTimerId, smoothingFactor);
  mergeSubTree(v8, v5, v6, v7, smoothingFactor);
}

// File Line: 571
// RVA: 0xC774E0
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::navigateMonitors(
        hkMonitorStreamAnalyzer::CursorKeys *keys,
        hkMonitorStreamAnalyzer::Node *activeNodeIn)
{
  hkMonitorStreamAnalyzer::Node *v2; // r9
  hkMonitorStreamAnalyzer::Node *m_parent; // rcx
  hkMonitorStreamAnalyzer::Node **m_data; // r11
  hkMonitorStreamAnalyzer::Node *v7; // rax
  __int64 m_size; // r10
  int v9; // r8d
  __int64 v10; // rdx
  hkMonitorStreamAnalyzer::Node **v11; // rcx
  int i; // ecx
  hkMonitorStreamAnalyzer::Node *v13; // r10
  hkMonitorStreamAnalyzer::Node *v14; // r11
  int v15; // r8d
  __int64 v16; // rdx
  __int64 v17; // rdi
  hkMonitorStreamAnalyzer::Node **v18; // rcx
  unsigned int m_userFlags; // eax
  hkMonitorStreamAnalyzer::Node *v20; // rax

  v2 = activeNodeIn;
  if ( !activeNodeIn )
    return 0i64;
  if ( keys->m_upPressed.m_bool )
  {
    m_parent = activeNodeIn->m_parent;
    m_data = m_parent->m_children.m_data;
    v7 = *m_data;
    if ( *m_data == activeNodeIn )
    {
      if ( m_parent->m_parent )
        v2 = activeNodeIn->m_parent;
    }
    else
    {
      m_size = m_parent->m_children.m_size;
      v9 = 0;
      v10 = 0i64;
      if ( m_size > 0 )
      {
        v11 = m_parent->m_children.m_data;
        while ( *v11 != v2 )
        {
          ++v10;
          ++v9;
          ++v11;
          if ( v10 >= m_size )
            goto LABEL_11;
        }
        v7 = m_data[v9 - 1];
      }
LABEL_11:
      for ( i = v7->m_children.m_size; i > 0; i = v7->m_children.m_size )
      {
        if ( (v7->m_userFlags & 1) == 0 )
          break;
        v7 = v7->m_children.m_data[i - 1];
      }
      v2 = v7;
    }
  }
  if ( keys->m_downPressed.m_bool )
  {
    v13 = v2;
    if ( v2->m_children.m_size > 0 && (v2->m_userFlags & 1) != 0 )
    {
      v2 = *v2->m_children.m_data;
    }
    else
    {
      while ( 1 )
      {
        v14 = v13->m_parent;
        v15 = 0;
        v16 = 0i64;
        v17 = v14->m_children.m_size;
        if ( (int)v17 > 0 )
          break;
LABEL_26:
        if ( !v14->m_parent )
          goto LABEL_29;
        v13 = v13->m_parent;
      }
      v18 = v14->m_children.m_data;
      while ( *v18 != v13 || v15 >= (int)v17 - 1 )
      {
        ++v16;
        ++v15;
        ++v18;
        if ( v16 >= v17 )
          goto LABEL_26;
      }
      v2 = v14->m_children.m_data[v16 + 1];
    }
  }
LABEL_29:
  if ( keys->m_leftPressed.m_bool )
  {
    m_userFlags = v2->m_userFlags;
    if ( (m_userFlags & 1) != 0 )
    {
      v2->m_userFlags = m_userFlags & 0xFFFFFFFE;
    }
    else
    {
      v20 = v2->m_parent;
      if ( v20->m_parent )
      {
        v20->m_userFlags &= ~1u;
        v2 = v20;
      }
    }
  }
  if ( keys->m_rightPressed.m_bool )
  {
    if ( (v2->m_userFlags & 1) == 0 )
      v2->m_userFlags |= 1u;
    v2->m_userFlags |= 1u;
  }
  return v2;
}

// File Line: 682
// RVA: 0xC77AA0
__int64 __fastcall hkMonitorStreamAnalyzer::findMaxTimerNameIndent(
        hkMonitorStreamAnalyzer::Node *node,
        int recursionDepth,
        int spacing,
        bool displayPartialTree)
{
  int v6; // eax
  int v7; // edx
  bool v8; // cl
  int v9; // ebx
  int v10; // esi
  int v11; // r10d
  __int64 v12; // rbp
  int MaxTimerNameIndent; // eax
  int v15; // [rsp+48h] [rbp+10h]

  v6 = hkString::strLen(node->m_name);
  v7 = spacing;
  v8 = displayPartialTree;
  v9 = v6 + spacing * recursionDepth + 8;
  if ( !displayPartialTree || (node->m_userFlags & 1) != 0 )
  {
    v10 = 0;
    if ( node->m_children.m_size > 0 )
    {
      v11 = recursionDepth + 1;
      v12 = 0i64;
      v15 = v11;
      do
      {
        MaxTimerNameIndent = hkMonitorStreamAnalyzer::findMaxTimerNameIndent(node->m_children.m_data[v12], v11, v7, v8);
        v8 = displayPartialTree;
        v7 = spacing;
        v11 = v15;
        ++v12;
        if ( MaxTimerNameIndent > v9 )
          v9 = MaxTimerNameIndent;
        ++v10;
      }
      while ( v10 < node->m_children.m_size );
    }
  }
  return (unsigned int)v9;
}

// File Line: 701
// RVA: 0xC77B50
void __fastcall hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec(
        hkOstream *os,
        hkMonitorStreamAnalyzer::Node *node,
        int recursionDepth,
        int numThreads,
        int numSpus,
        hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *options)
{
  int v8; // ecx
  int v9; // r8d
  int v11; // edi
  char m_rightArrowChar; // dl
  int v13; // eax
  __int64 v14; // rbx
  char m_downArrowChar; // dl
  __int64 v16; // rbx
  int v17; // edx
  int v18; // r8d
  unsigned int v19; // r9d
  __int64 v20; // r10
  unsigned int *v21; // rax
  unsigned __int64 v22; // rcx
  __int64 v23; // r9
  __int64 m_size; // rax
  int v25; // edx
  __int64 v26; // rdi
  int v27; // ecx
  __int64 v28; // rbx
  int v29; // ebx
  int v30; // eax
  __int64 v31; // rdi
  __int64 v32; // [rsp+30h] [rbp-48h]
  hkArray<char,hkContainerHeapAllocator> s; // [rsp+38h] [rbp-40h] BYREF
  hkOstream v34; // [rsp+48h] [rbp-30h] BYREF
  int v37; // [rsp+90h] [rbp+18h]
  int optionsa; // [rsp+A8h] [rbp+30h]

  s.m_data = 0i64;
  s.m_size = 0;
  s.m_capacityAndFlags = 0x80000000;
  hkOstream::hkOstream(&v34, &s);
  v8 = numThreads;
  v9 = numSpus;
  v11 = numThreads + numSpus;
  if ( recursionDepth )
  {
    if ( options->m_displayPartialTree )
    {
      if ( options->m_activeNode == node )
        m_rightArrowChar = options->m_rightArrowChar;
      else
        m_rightArrowChar = 32;
      hkOstream::operator<<(&v34, m_rightArrowChar);
    }
    v13 = (recursionDepth - 1) * options->m_tabSpacingForTimerNames;
    if ( v13 > 0 )
    {
      v14 = (unsigned int)v13;
      do
      {
        hkOstream::operator<<(&v34, 32);
        --v14;
      }
      while ( v14 );
    }
    if ( options->m_displayPartialTree )
    {
      if ( node->m_children.m_size <= 0 )
      {
        m_downArrowChar = 32;
      }
      else if ( (node->m_userFlags & 1) != 0 )
      {
        m_downArrowChar = options->m_downArrowChar;
      }
      else
      {
        m_downArrowChar = options->m_rightArrowChar;
      }
      hkOstream::operator<<(&v34, m_downArrowChar);
    }
    v16 = v11;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v20 = 0i64;
    v32 = v11;
    if ( v11 >= 2i64 )
    {
      v21 = &node->m_count[1];
      v22 = ((unsigned __int64)(v11 - 2i64) >> 1) + 1;
      v20 = 2 * v22;
      do
      {
        v17 += *(v21 - 1);
        v18 += *v21;
        v21 += 2;
        --v22;
      }
      while ( v22 );
    }
    if ( v20 < v11 )
      v19 = node->m_count[v20];
    v23 = v17 + v18 + v19;
    if ( options->m_showUnaccountedForTimes && !node->m_type.m_storage )
    {
      m_size = node->m_children.m_size;
      if ( m_size > 0 )
      {
        do
          --m_size;
        while ( m_size );
      }
    }
    hkOstream::printf(&v34, "%s (%i) ", node->m_name, v23);
    v25 = 0;
    v26 = 0i64;
    for ( optionsa = 0; v26 < v16; ++optionsa )
    {
      if ( options->m_useTabsNotSpacesForColumns )
      {
        hkOstream::operator<<(&v34, 9);
      }
      else
      {
        v27 = options->m_indentationToFirstTimerValue
            + v25 * options->m_timerColumnWidth
            + (recursionDepth - 1) * options->m_tabSpacingForTimerValues
            - s.m_size;
        if ( v27 > 0 )
        {
          v28 = (unsigned int)v27;
          do
          {
            hkOstream::operator<<(&v34, 32);
            --v28;
          }
          while ( v28 );
          v16 = v32;
        }
      }
      hkOstream::printf(&v34, "%-6.3f (%i)", node->m_value[v26], node->m_count[v26]);
      v25 = optionsa + 1;
      ++v26;
    }
    hkOstream::operator<<(os, s.m_data);
    hkOstream::operator<<(os, 10);
    v8 = numThreads;
    v9 = numSpus;
  }
  if ( !options->m_displayPartialTree || (node->m_userFlags & 1) != 0 )
  {
    v29 = 0;
    if ( node->m_children.m_size > 0 )
    {
      v30 = recursionDepth + 1;
      v31 = 0i64;
      v37 = recursionDepth + 1;
      do
      {
        hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec(os, node->m_children.m_data[v31], v30, v8, v9, options);
        v30 = v37;
        v8 = numThreads;
        v9 = numSpus;
        ++v29;
        ++v31;
      }
      while ( v29 < node->m_children.m_size );
    }
  }
  hkOstream::~hkOstream(&v34);
  s.m_size = 0;
  if ( s.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      s.m_data,
      s.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 814
// RVA: 0xC76D40
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::makeStatisticsTreeForSingleFrame(
        hkMonitorStream::TimerCommand *frameStart,
        hkMonitorStream::TimerCommand *frameEnd,
        hkMonitorStreamFrameInfo *frameInfo,
        const char *rootNodeName,
        hkBool reuseNodesIfPossible)
{
  _QWORD **Value; // rax
  hkMonitorStreamAnalyzer::Node *v10; // rax
  hkMonitorStreamAnalyzer::Node *v11; // rax
  hkMonitorStreamAnalyzer::Node *v12; // r14
  hkMonitorStreamAnalyzer::Node *v13; // r12
  const char *m_commandAndMonitor; // rsi
  hkMonitorStream::TimerCommand *v15; // rcx
  const char **v16; // rcx
  hkMonitorStream::TimerCommand *v17; // rbx
  int v18; // ebx
  int v19; // r9d
  hkResult *p_result; // rcx
  hkMonitorStream::TimerCommand *v21; // rcx
  const char **v22; // rcx
  hkMonitorStream::TimerCommand *v24; // rcx
  const char **v25; // rcx
  hkMonitorStreamAnalyzer::Node *NewNode; // rax
  int v27; // edx
  __int64 v28; // rsi
  const char *v29; // rbx
  hkMonitorStreamAnalyzer::Node *v30; // r14
  hkMonitorStream::TimerCommand *v31; // rax
  int v32; // ecx
  char *v33; // rax
  hkMonitorStream::TimerCommand *v34; // rbx
  hkMonitorStream::TimerCommand *v35; // r8
  hkMonitorStreamAnalyzer::Node *m_parent; // r14
  int v37; // ecx
  int v38; // ebx
  int v39; // r9d
  hkMonitorStreamAnalyzer::Node *v40; // rax
  float v41; // xmm0_4
  hkResult v42; // [rsp+30h] [rbp-D0h] BYREF
  hkMonitorStream::TimerCommand *array; // [rsp+40h] [rbp-C0h] BYREF
  int v44; // [rsp+48h] [rbp-B8h]
  int v45; // [rsp+4Ch] [rbp-B4h]
  char v46; // [rsp+50h] [rbp-B0h] BYREF
  char *v47; // [rsp+150h] [rbp+50h] BYREF
  int v48; // [rsp+158h] [rbp+58h]
  int v49; // [rsp+15Ch] [rbp+5Ch]
  char v50; // [rsp+160h] [rbp+60h] BYREF
  const char *v51; // [rsp+260h] [rbp+160h]
  hkResult result; // [rsp+2B0h] [rbp+1B0h] BYREF
  hkResult v53; // [rsp+2B8h] [rbp+1B8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           144i64);
  if ( v10 )
  {
    hkMonitorStreamAnalyzer::Node::Node(v10, 0i64, rootNodeName, NODE_TYPE_DIRECTORY);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = v12;
  v44 = 0;
  array = (hkMonitorStream::TimerCommand *)&v46;
  v45 = -2147483632;
  v48 = 0;
  v49 = -2147483632;
  v47 = &v50;
  while ( frameStart < frameEnd )
  {
    m_commandAndMonitor = frameStart->m_commandAndMonitor;
    if ( frameStart->m_commandAndMonitor >= (const char *)0x14 )
    {
      switch ( *m_commandAndMonitor )
      {
        case E:
          if ( !v44 )
            goto LABEL_36;
          v17 = &array[v44 - 1];
          if ( m_commandAndMonitor[2] )
          {
            if ( (unsigned int)hkString::strCmp(v17->m_commandAndMonitor + 2, m_commandAndMonitor + 2) )
              goto LABEL_36;
          }
          hkMonitorStreamAnalyzer::Node::setTimers(v12, frameInfo, v17, frameStart);
          v12 = v12->m_parent;
          --v44;
          v18 = v48 - 1;
          if ( (v49 & 0x3FFFFFFF) >= v48 - 1 )
          {
            result.m_enum = HK_SUCCESS;
            --v48;
            ++frameStart;
            break;
          }
          v19 = v48 - 1;
          p_result = &result;
          if ( v18 < 2 * (v49 & 0x3FFFFFFF) )
            v19 = 2 * (v49 & 0x3FFFFFFF);
          goto LABEL_23;
        case F:
          break;
        case L:
          if ( v44 == (v45 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v24 = &array[v44];
          if ( v24 )
          {
            v24->m_commandAndMonitor = frameStart->m_commandAndMonitor;
            *(_QWORD *)&v24->m_time0 = *(_QWORD *)&frameStart->m_time0;
          }
          ++v44;
          if ( v48 == (v49 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v47, 16);
          v25 = (const char **)&v47[16 * v48];
          if ( v25 )
          {
            *v25 = frameStart->m_commandAndMonitor;
            v25[1] = *(const char **)&frameStart->m_time0;
          }
          ++v48;
          NewNode = createNewNode(v12, m_commandAndMonitor + 2, NODE_TYPE_TIMER, reuseNodesIfPossible.m_bool != 0);
          v27 = v44;
          v28 = *(_QWORD *)&frameStart->m_time0;
          v29 = frameStart[1].m_commandAndMonitor;
          v51 = frameStart->m_commandAndMonitor;
          v30 = NewNode;
          if ( v44 == (v45 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v27 = v44;
          }
          v31 = &array[v27];
          if ( v31 )
          {
            v31->m_commandAndMonitor = v29;
            *(_QWORD *)&v31->m_time0 = v28;
            v27 = v44;
          }
          v32 = v48;
          v44 = v27 + 1;
          if ( v48 == (v49 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v47, 16);
            v32 = v48;
          }
          v33 = &v47[16 * v32];
          if ( v33 )
          {
            *(_QWORD *)v33 = v29;
            *((_QWORD *)v33 + 1) = v28;
            v32 = v48;
          }
          v48 = v32 + 1;
          v12 = createNewNode(v30, v29 + 2, NODE_TYPE_TIMER, reuseNodesIfPossible.m_bool != 0);
          goto $LN3_162;
        case M:
          v40 = createNewNode(v12, m_commandAndMonitor + 2, NODE_TYPE_SINGLE, reuseNodesIfPossible.m_bool != 0);
          v41 = *(float *)&frameStart->m_time0;
          ++v40->m_count[0];
          ++frameStart;
          v40->m_value[0] = v41 + v40->m_value[0];
          break;
        case N:
          goto $LN4_174;
        case O:
          if ( v44 == (v45 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v21 = &array[v44];
          if ( v21 )
          {
            v21->m_commandAndMonitor = frameStart->m_commandAndMonitor;
            *(_QWORD *)&v21->m_time0 = *(_QWORD *)&frameStart->m_time0;
          }
          ++v44;
          v12 = createNewNode(v12, frameStart[1].m_commandAndMonitor, NODE_TYPE_TIMER, reuseNodesIfPossible.m_bool != 0);
          if ( v48 == (v49 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v47, 16);
          v22 = (const char **)&v47[16 * v48];
          if ( v22 )
          {
            *v22 = frameStart->m_commandAndMonitor;
            v22[1] = *(const char **)&frameStart->m_time0;
          }
          ++v48;
          goto $LN3_162;
        case P:
          frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 8);
          v12 = createNewNode(v12, m_commandAndMonitor + 2, NODE_TYPE_DIRECTORY, reuseNodesIfPossible.m_bool != 0);
          break;
        case S:
          if ( !v44 )
            goto LABEL_36;
          v34 = &array[v44 - 1];
          hkMonitorStreamAnalyzer::Node::setTimers(v12, frameInfo, v34, frameStart++);
          v12 = createNewNode(v12->m_parent, m_commandAndMonitor + 2, NODE_TYPE_TIMER, reuseNodesIfPossible.m_bool != 0);
          v34->m_commandAndMonitor = frameStart[-1].m_commandAndMonitor;
          *(_QWORD *)&v34->m_time0 = *(_QWORD *)&frameStart[-1].m_time0;
          break;
        case T:
          v12 = createNewNode(v12, m_commandAndMonitor + 2, NODE_TYPE_TIMER, reuseNodesIfPossible.m_bool != 0);
          if ( v44 == (v45 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v15 = &array[v44];
          if ( v15 )
          {
            v15->m_commandAndMonitor = frameStart->m_commandAndMonitor;
            *(_QWORD *)&v15->m_time0 = *(_QWORD *)&frameStart->m_time0;
          }
          ++v44;
          if ( v48 == (v49 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v47, 16);
          v16 = (const char **)&v47[16 * v48];
          if ( v16 )
          {
            *v16 = frameStart->m_commandAndMonitor;
            v16[1] = *(const char **)&frameStart->m_time0;
          }
          ++v48;
          ++frameStart;
          break;
        case l:
          if ( v44 <= 1 )
            goto LABEL_36;
          v35 = &array[v44 - 1];
          if ( *v35->m_commandAndMonitor != 83 )
            goto LABEL_36;
          hkMonitorStreamAnalyzer::Node::setTimers(v12, frameInfo, v35, frameStart);
          m_parent = v12->m_parent;
          v37 = v44 - 1;
          v38 = v48 - 1;
          --v44;
          if ( (v49 & 0x3FFFFFFF) >= v48 - 1 )
          {
            v53.m_enum = HK_SUCCESS;
          }
          else
          {
            v39 = v48 - 1;
            if ( v38 < 2 * (v49 & 0x3FFFFFFF) )
              v39 = 2 * (v49 & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&v53, &hkContainerHeapAllocator::s_alloc, (const void **)&v47, v39, 16);
            v37 = v44;
          }
          v48 = v38;
          hkMonitorStreamAnalyzer::Node::setTimers(m_parent, frameInfo, &array[v37 - 1], frameStart);
          v12 = m_parent->m_parent;
          --v44;
          v18 = v48 - 1;
          if ( (v49 & 0x3FFFFFFF) >= v48 - 1 )
          {
            v42.m_enum = HK_SUCCESS;
            --v48;
            ++frameStart;
          }
          else
          {
            v19 = v48 - 1;
            p_result = &v42;
            if ( v18 < 2 * (v49 & 0x3FFFFFFF) )
              v19 = 2 * (v49 & 0x3FFFFFFF);
LABEL_23:
            hkArrayUtil::_reserve(p_result, &hkContainerHeapAllocator::s_alloc, (const void **)&v47, v19, 16);
            v48 = v18;
            ++frameStart;
          }
          break;
        case m:
$LN3_162:
          frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 24);
          break;
        case p:
          v12 = v12->m_parent;
          if ( !v12 )
            goto LABEL_36;
$LN4_174:
          frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 8);
          break;
        default:
          goto LABEL_36;
      }
    }
    else
    {
      frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 4);
    }
  }
LABEL_36:
  v48 = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v47, 16 * v49);
  v47 = 0i64;
  v49 = 0x80000000;
  v44 = 0;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v45);
  return v13;
}

// File Line: 1021
// RVA: 0xC77E50
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::makeStatisticsTreeForMultipleFrames(
        hkMonitorStreamAnalyzer *this,
        int threadId,
        hkBool reuseNodesIfPossible)
{
  __int64 v4; // rbx
  _QWORD **Value; // rax
  hkMonitorStreamAnalyzer::Node *v6; // rax
  int v7; // edi
  __int64 v8; // rax
  __int64 v9; // rbp
  __int64 v10; // rsi
  int m_size; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v15; // rcx
  __int64 v16; // r13
  __int64 v17; // r12
  __int64 v18; // rbx
  hkMonitorStreamAnalyzer::Node *StatisticsTreeForSingleFrame; // rax
  hkResult result; // [rsp+78h] [rbp+10h] BYREF
  hkBool v22; // [rsp+80h] [rbp+18h]

  v22.m_bool = reuseNodesIfPossible.m_bool;
  v4 = threadId;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          144i64);
  v7 = 0;
  if ( v6 )
  {
    hkMonitorStreamAnalyzer::Node::Node(v6, 0i64, "/", 1u);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v4;
  m_size = this->m_frameInfos.m_data[v4].m_size;
  v12 = *(_DWORD *)(v9 + 108) & 0x3FFFFFFF;
  if ( v12 < m_size )
  {
    v13 = 2 * v12;
    v14 = m_size;
    if ( m_size < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v9 + 96), v14, 8);
  }
  *(_DWORD *)(v9 + 104) = m_size;
  v15 = &this->m_frameInfos.m_data[v10];
  if ( v15->m_size > 0 )
  {
    v16 = 0i64;
    v17 = 0i64;
    do
    {
      v18 = *(_QWORD *)(v9 + 96);
      StatisticsTreeForSingleFrame = hkMonitorStreamAnalyzer::makeStatisticsTreeForSingleFrame(
                                       (hkMonitorStream::TimerCommand *)&this->m_data.m_data[v15->m_data[v16].m_frameStreamStart],
                                       (hkMonitorStream::TimerCommand *)&this->m_data.m_data[v15->m_data[v16].m_frameStreamEnd],
                                       &v15->m_data[v16],
                                       (const char *)((unsigned __int64)v15->m_data[v16].m_heading.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                                       v22);
      ++v7;
      ++v16;
      *(_QWORD *)(v18 + v17) = StatisticsTreeForSingleFrame;
      v17 += 8i64;
      v15 = &this->m_frameInfos.m_data[v10];
    }
    while ( v7 < v15->m_size );
  }
  return (hkMonitorStreamAnalyzer::Node *)v9;
}

// File Line: 1049
// RVA: 0xC77660
void __fastcall hkMonitorStreamAnalyzer::showCombinedThreadSummaryForSingleFrame(
        hkMonitorStreamAnalyzer::Node *node,
        int numThreads,
        int numSpus,
        hkOstream *os,
        hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *options)
{
  int MaxTimerNameIndent; // eax
  int i; // esi
  int v11; // eax
  __int64 v12; // rbx
  int j; // esi
  int v14; // eax
  __int64 v15; // rbx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+30h] [rbp-48h] BYREF
  hkOstream v17; // [rsp+40h] [rbp-38h] BYREF

  MaxTimerNameIndent = hkMonitorStreamAnalyzer::findMaxTimerNameIndent(
                         node,
                         0,
                         options->m_tabSpacingForTimerNames,
                         options->m_displayPartialTree);
  buf.m_data = 0i64;
  buf.m_size = 0;
  options->m_indentationToFirstTimerValue = MaxTimerNameIndent;
  buf.m_capacityAndFlags = 0x80000000;
  hkOstream::hkOstream(&v17, &buf);
  hkOstream::printf(&v17, "Timer Name");
  if ( numThreads > 1 || numSpus > 0 )
  {
    for ( i = 0; i < numThreads; ++i )
    {
      if ( options->m_useTabsNotSpacesForColumns )
      {
        hkOstream::operator<<(&v17, 9);
      }
      else
      {
        v11 = options->m_indentationToFirstTimerValue + i * options->m_timerColumnWidth - buf.m_size;
        if ( v11 > 0 )
        {
          v12 = (unsigned int)v11;
          do
          {
            hkOstream::operator<<(&v17, 32);
            --v12;
          }
          while ( v12 );
        }
      }
      hkOstream::printf(&v17, "Thread %d", (unsigned int)i);
    }
    for ( j = 0; j < numSpus; ++j )
    {
      if ( options->m_useTabsNotSpacesForColumns )
      {
        hkOstream::operator<<(&v17, 9);
      }
      else
      {
        v14 = options->m_indentationToFirstTimerValue + options->m_timerColumnWidth * (j + numThreads) - buf.m_size;
        if ( v14 > 0 )
        {
          v15 = (unsigned int)v14;
          do
          {
            hkOstream::operator<<(&v17, 32);
            --v15;
          }
          while ( v15 );
        }
      }
      hkOstream::printf(&v17, "Spu %d", (unsigned int)j);
    }
  }
  hkOstream::operator<<(os, buf.m_data);
  hkOstream::printf(os, "\n\n");
  hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec(os, node, 0, numThreads, numSpus, options);
  hkOstream::~hkOstream(&v17);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 1095
// RVA: 0xC7A490
void __fastcall hkMakeSum(hkMonitorStreamAnalyzer::Node *sum, hkMonitorStreamAnalyzer::Node *node)
{
  unsigned int *m_count; // r8
  signed __int64 v3; // rdx
  __int64 v4; // rcx
  float v5; // xmm0_4

  m_count = sum->m_count;
  v3 = (char *)node - (char *)sum;
  v4 = 2i64;
  do
  {
    v5 = *(float *)((char *)m_count + v3 - 48);
    m_count += 6;
    *((float *)m_count - 18) = v5 + *((float *)m_count - 18);
    *(m_count - 6) += *(unsigned int *)((char *)m_count + v3 - 24);
    *((float *)m_count - 17) = *(float *)((char *)m_count + v3 - 68) + *((float *)m_count - 17);
    *(m_count - 5) += *(unsigned int *)((char *)m_count + v3 - 20);
    *((float *)m_count - 16) = *(float *)((char *)m_count + v3 - 64) + *((float *)m_count - 16);
    *(m_count - 4) += *(unsigned int *)((char *)m_count + v3 - 16);
    *((float *)m_count - 15) = *(float *)((char *)m_count + v3 - 60) + *((float *)m_count - 15);
    *(m_count - 3) += *(unsigned int *)((char *)m_count + v3 - 12);
    *((float *)m_count - 14) = *(float *)((char *)m_count + v3 - 56) + *((float *)m_count - 14);
    *(m_count - 2) += *(unsigned int *)((char *)m_count + v3 - 8);
    *((float *)m_count - 13) = *(float *)((char *)m_count + v3 - 52) + *((float *)m_count - 13);
    *(m_count - 1) += *(unsigned int *)((char *)m_count + v3 - 4);
    --v4;
  }
  while ( v4 );
}

// File Line: 1133
// RVA: 0xC7BED0
void __fastcall hkMonitorStreamAnalyzerPrintByTypeInfo::hkMonitorStreamAnalyzerPrintByTypeInfo(
        hkMonitorStreamAnalyzerPrintByTypeInfo *this)
{
  hkMonitorStreamAnalyzer::Node::Node(&this->m_this, 0i64, 0i64, 0);
  this->m_parents.m_data = 0i64;
  this->m_parents.m_size = 0;
  this->m_parents.m_capacityAndFlags = 0x80000000;
  this->m_children.m_data = 0i64;
  this->m_children.m_size = 0;
  this->m_children.m_capacityAndFlags = 0x80000000;
}

// File Line: 1142
// RVA: 0xC7C280
bool __fastcall hkCompareInfosBySize(
        hkMonitorStreamAnalyzerPrintByTypeInfo *a,
        hkMonitorStreamAnalyzerPrintByTypeInfo *b)
{
  return a->m_this.m_value[1] < b->m_this.m_value[1];
}

// File Line: 1147
// RVA: 0xC7AA70
void __fastcall hkBuildSizePerName(
        hkMonitorStreamAnalyzer::Node *node,
        hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *mapOut)
{
  const char *m_name; // rdi
  hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *v3; // rbp
  hkMonitorStreamAnalyzer::Node *v4; // rsi
  unsigned __int64 v5; // rbx
  _QWORD **Value; // rax
  hkMonitorStreamAnalyzerPrintByTypeInfo *v7; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  char *v10; // rdx
  __int64 v11; // r8
  float v12; // xmm0_4
  __int64 v13; // rcx
  hkMonitorStreamAnalyzer::Node *v14; // rdi
  unsigned __int64 v15; // rax
  const char *v16; // rcx
  __int64 v17; // rbp
  int v18; // esi
  __int64 v19; // rbx
  __int64 v20; // rdi
  unsigned __int64 v21; // rbx
  __int64 v22; // rsi
  int v23; // r9d
  int v24; // eax
  int v25; // eax
  __int64 v26; // rcx
  hkMonitorStreamAnalyzer::Node *v27; // rcx
  __int64 v28; // rax
  __int64 v29; // rcx
  char *v30; // rdi
  __int64 v31; // rdx
  float v32; // xmm0_4
  hkMonitorStreamAnalyzer::Node *m_parent; // rcx
  char *v34; // rcx
  __int64 v35; // rax
  int v36; // ebp
  __int64 v37; // rdi
  __int64 v38; // rsi
  unsigned __int64 v39; // rbx
  __int64 v40; // rdi
  int v41; // r9d
  int v42; // eax
  int v43; // eax
  __int64 v44; // rcx
  hkMonitorStreamAnalyzer::Node *v45; // rcx
  __int64 v46; // rcx
  char *v47; // rdx
  float v48; // xmm0_4
  unsigned __int64 v49; // [rsp+30h] [rbp-58h]
  char *name; // [rsp+38h] [rbp-50h]
  __int64 v51; // [rsp+40h] [rbp-48h]
  __int64 v52; // [rsp+48h] [rbp-40h]
  hkMonitorStreamAnalyzer::Node *v53; // [rsp+50h] [rbp-38h]
  hkMonitorStreamAnalyzer::Node *v54; // [rsp+90h] [rbp+8h] BYREF
  char *v55; // [rsp+98h] [rbp+10h]
  __int64 v56; // [rsp+A0h] [rbp+18h]
  hkResult result; // [rsp+A8h] [rbp+20h] BYREF

  v55 = (char *)mapOut;
  v54 = node;
  m_name = node->m_name;
  v3 = mapOut;
  v4 = node;
  v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)mapOut,
         m_name,
         0i64);
  v49 = v5;
  if ( !v5 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkMonitorStreamAnalyzerPrintByTypeInfo *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[12] + 8i64))(
                                                     Value[12],
                                                     176i64);
    if ( v7 )
    {
      hkMonitorStreamAnalyzerPrintByTypeInfo::hkMonitorStreamAnalyzerPrintByTypeInfo(v7);
      v5 = v8;
    }
    else
    {
      v5 = 0i64;
    }
    v49 = v5;
    *(_QWORD *)(v5 + 128) = m_name;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v3->m_map, m_name, v5);
  }
  v9 = v5 + 48;
  v10 = (char *)v4 - v5;
  v52 = 2i64;
  v11 = 2i64;
  do
  {
    v12 = *(float *)&v10[v9 - 48];
    v9 += 24i64;
    *(float *)(v9 - 72) = v12 + *(float *)(v9 - 72);
    *(_DWORD *)(v9 - 24) += *(_DWORD *)&v10[v9 - 24];
    *(float *)(v9 - 68) = *(float *)&v10[v9 - 68] + *(float *)(v9 - 68);
    *(_DWORD *)(v9 - 20) += *(_DWORD *)&v10[v9 - 20];
    *(float *)(v9 - 64) = *(float *)&v10[v9 - 64] + *(float *)(v9 - 64);
    *(_DWORD *)(v9 - 16) += *(_DWORD *)&v10[v9 - 16];
    *(float *)(v9 - 60) = *(float *)&v10[v9 - 60] + *(float *)(v9 - 60);
    *(_DWORD *)(v9 - 12) += *(_DWORD *)&v10[v9 - 12];
    *(float *)(v9 - 56) = *(float *)&v10[v9 - 56] + *(float *)(v9 - 56);
    *(_DWORD *)(v9 - 8) += *(_DWORD *)&v10[v9 - 8];
    *(float *)(v9 - 52) = *(float *)&v10[v9 - 52] + *(float *)(v9 - 52);
    *(_DWORD *)(v9 - 4) += *(_DWORD *)&v10[v9 - 4];
    --v11;
  }
  while ( v11 );
  LODWORD(v56) = 0;
  if ( v4->m_children.m_size > 0 )
  {
    v13 = 0i64;
    v51 = 0i64;
    do
    {
      v14 = *(hkMonitorStreamAnalyzer::Node **)((char *)v4->m_children.m_data + v13);
      v53 = v14;
      hkBuildSizePerName(v14, v3);
      v15 = v49;
      v16 = v14->m_name;
      v17 = 0i64;
      name = (char *)v16;
      v18 = *(_DWORD *)(v49 + 168) - 1;
      v19 = v18;
      if ( v18 >= 0 )
      {
        v20 = 144i64 * v18;
        do
        {
          v17 = v20 + *(_QWORD *)(v15 + 160);
          if ( !(unsigned int)hkString::strCmp(v16, *(const char **)(v17 + 128)) )
            break;
          v15 = v49;
          v16 = name;
          --v18;
          v20 -= 144i64;
          --v19;
        }
        while ( v19 >= 0 );
        v14 = v53;
        v15 = v49;
      }
      if ( v18 < 0 )
      {
        v21 = v15 + 160;
        v22 = *(int *)(v15 + 168);
        v23 = v22 + 1;
        v24 = *(_DWORD *)(v15 + 172) & 0x3FFFFFFF;
        if ( v24 >= (int)v22 + 1 )
        {
          result.m_enum = HK_SUCCESS;
        }
        else
        {
          v25 = 2 * v24;
          if ( v23 < v25 )
            v23 = v25;
          hkArrayUtil::_reserve(&result, &hkContainerDebugAllocator::s_alloc, (const void **)v21, v23, 144);
        }
        v26 = *(_QWORD *)v21 + 144i64 * *(int *)(v21 + 8);
        if ( v26 )
        {
          *(_QWORD *)(v26 + 96) = 0i64;
          *(_DWORD *)(v26 + 104) = 0;
          *(_DWORD *)(v26 + 108) = 0x80000000;
        }
        ++*(_DWORD *)(v21 + 8);
        v27 = (hkMonitorStreamAnalyzer::Node *)(*(_QWORD *)v21 + 144 * v22);
        if ( v27 )
        {
          hkMonitorStreamAnalyzer::Node::Node(v27, 0i64, name, 0);
          v17 = v28;
        }
        else
        {
          v17 = 0i64;
        }
      }
      v29 = v17 + 48;
      v30 = (char *)v14 - v17;
      v31 = 2i64;
      do
      {
        v32 = *(float *)&v30[v29 - 48];
        v29 += 24i64;
        *(float *)(v29 - 72) = v32 + *(float *)(v29 - 72);
        *(_DWORD *)(v29 - 24) += *(_DWORD *)&v30[v29 - 24];
        *(float *)(v29 - 68) = *(float *)&v30[v29 - 68] + *(float *)(v29 - 68);
        *(_DWORD *)(v29 - 20) += *(_DWORD *)&v30[v29 - 20];
        *(float *)(v29 - 64) = *(float *)&v30[v29 - 64] + *(float *)(v29 - 64);
        *(_DWORD *)(v29 - 16) += *(_DWORD *)&v30[v29 - 16];
        *(float *)(v29 - 60) = *(float *)&v30[v29 - 60] + *(float *)(v29 - 60);
        *(_DWORD *)(v29 - 12) += *(_DWORD *)&v30[v29 - 12];
        *(float *)(v29 - 56) = *(float *)&v30[v29 - 56] + *(float *)(v29 - 56);
        *(_DWORD *)(v29 - 8) += *(_DWORD *)&v30[v29 - 8];
        *(float *)(v29 - 52) = *(float *)&v30[v29 - 52] + *(float *)(v29 - 52);
        *(_DWORD *)(v29 - 4) += *(_DWORD *)&v30[v29 - 4];
        --v31;
      }
      while ( v31 );
      v4 = v54;
      v3 = (hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *)v55;
      v13 = v51 + 8;
      LODWORD(v56) = v56 + 1;
      v51 += 8i64;
    }
    while ( (int)v56 < v54->m_children.m_size );
    v5 = v49;
  }
  m_parent = v4->m_parent;
  if ( m_parent )
  {
    v34 = (char *)m_parent->m_name;
    v35 = 0i64;
    v36 = *(_DWORD *)(v5 + 152) - 1;
    v55 = v34;
    v37 = v36;
    if ( v36 >= 0 )
    {
      v38 = 144i64 * v36;
      do
      {
        v56 = v38 + *(_QWORD *)(v5 + 144);
        if ( !(unsigned int)hkString::strCmp(v34, *(const char **)(v56 + 128)) )
          break;
        v34 = v55;
        --v36;
        v38 -= 144i64;
        --v37;
      }
      while ( v37 >= 0 );
      v35 = v56;
      v4 = v54;
    }
    if ( v36 < 0 )
    {
      v39 = v5 + 144;
      v40 = *(int *)(v39 + 8);
      v41 = v40 + 1;
      v42 = *(_DWORD *)(v39 + 12) & 0x3FFFFFFF;
      if ( v42 >= (int)v40 + 1 )
      {
        LODWORD(v54) = 0;
      }
      else
      {
        v43 = 2 * v42;
        if ( v41 < v43 )
          v41 = v43;
        hkArrayUtil::_reserve((hkResult *)&v54, &hkContainerDebugAllocator::s_alloc, (const void **)v39, v41, 144);
      }
      v44 = *(_QWORD *)v39 + 144i64 * *(int *)(v39 + 8);
      if ( v44 )
      {
        *(_QWORD *)(v44 + 96) = 0i64;
        *(_DWORD *)(v44 + 104) = 0;
        *(_DWORD *)(v44 + 108) = 0x80000000;
      }
      ++*(_DWORD *)(v39 + 8);
      v45 = (hkMonitorStreamAnalyzer::Node *)(*(_QWORD *)v39 + 144 * v40);
      if ( v45 )
        hkMonitorStreamAnalyzer::Node::Node(v45, 0i64, v55, 0);
      else
        v35 = 0i64;
    }
    v46 = v35 + 48;
    v47 = (char *)v4->m_parent - v35;
    do
    {
      v48 = *(float *)&v47[v46 - 48];
      v46 += 24i64;
      *(float *)(v46 - 72) = v48 + *(float *)(v46 - 72);
      *(_DWORD *)(v46 - 24) += *(_DWORD *)&v47[v46 - 24];
      *(float *)(v46 - 68) = *(float *)&v47[v46 - 68] + *(float *)(v46 - 68);
      *(_DWORD *)(v46 - 20) += *(_DWORD *)&v47[v46 - 20];
      *(float *)(v46 - 64) = *(float *)&v47[v46 - 64] + *(float *)(v46 - 64);
      *(_DWORD *)(v46 - 16) += *(_DWORD *)&v47[v46 - 16];
      *(float *)(v46 - 60) = *(float *)&v47[v46 - 60] + *(float *)(v46 - 60);
      *(_DWORD *)(v46 - 12) += *(_DWORD *)&v47[v46 - 12];
      *(float *)(v46 - 56) = *(float *)&v47[v46 - 56] + *(float *)(v46 - 56);
      *(_DWORD *)(v46 - 8) += *(_DWORD *)&v47[v46 - 8];
      *(float *)(v46 - 52) = *(float *)&v47[v46 - 52] + *(float *)(v46 - 52);
      *(_DWORD *)(v46 - 4) += *(_DWORD *)&v47[v46 - 4];
      --v52;
    }
    while ( v52 );
  }
}

// File Line: 1207
// RVA: 0xC7AFA0
void __fastcall printSingleNodeValues(hkOstream *outstream, float maxMem, hkMonitorStreamAnalyzer::Node *node)
{
  __int64 v3; // rbx
  __int64 v6; // r10
  unsigned int v7; // eax
  unsigned int *m_count; // r9
  const char *m_name; // r9
  char buf[256]; // [rsp+30h] [rbp-108h] BYREF

  v3 = 0i64;
  v6 = 12i64;
  v7 = 0;
  m_count = node->m_count;
  do
  {
    if ( *m_count && *m_count > v7 )
      v7 = *m_count;
    ++m_count;
    --v6;
  }
  while ( v6 );
  m_name = node->m_name;
  if ( maxMem <= 0.0 )
    hkString::snprintf(buf, 200, "%s (%i)", m_name, v7);
  else
    hkString::snprintf(buf, 200, "%s (%i) %4.1f%%", m_name, v7, (float)((float)(node->m_value[1] * 100.0) / maxMem));
  hkOstream::printf(outstream, "%-34s%s", buf, "\t\t\t");
  do
  {
    if ( node->m_count[v3] )
      hkOstream::printf(outstream, "% 12.3f: ", node->m_value[v3]);
    ++v3;
  }
  while ( v3 < 12 );
  hkOstream::printf(outstream, "\n");
}

// File Line: 1252
// RVA: 0xC7B0B0
void __fastcall printStatisticsByType(
        hkOstream *outstream,
        hkMonitorStreamAnalyzer::Node *rootNode,
        float maxImportance)
{
  Dummy *Iterator; // rbx
  unsigned __int64 Value; // rax
  float v7; // xmm8_4
  __int64 i; // r14
  hkMonitorStreamAnalyzerPrintByTypeInfo *v9; // rbx
  int j; // esi
  int k; // esi
  _QWORD **v12; // rax
  hkpEntity **array; // [rsp+28h] [rbp-19h] BYREF
  int v14; // [rsp+30h] [rbp-11h]
  int v15; // [rsp+34h] [rbp-Dh]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v16; // [rsp+38h] [rbp-9h] BYREF
  hkResult result; // [rsp+C0h] [rbp+7Fh] BYREF

  array = 0i64;
  v14 = 0;
  v15 = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v16,
    0);
  hkBuildSizePerName(rootNode, (hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *)&v16);
  if ( v16.m_numElems > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, v16.m_numElems, 8);
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v16);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v16,
    (hkBool *)&result,
    Iterator);
  while ( LOBYTE(result.m_enum) )
  {
    Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v16,
              Iterator);
    array[v14++] = (hkpEntity *)Value;
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v16,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v16,
      (hkBool *)&result,
      Iterator);
  }
  if ( v14 > 1 )
    hkAlgorithm::quickSortRecursive<hkMonitorStreamAnalyzerPrintByTypeInfo *,bool (*)(hkMonitorStreamAnalyzerPrintByTypeInfo const *,hkMonitorStreamAnalyzerPrintByTypeInfo const *)>(
      array,
      0,
      v14 - 1,
      (bool (__fastcall *)(hkpEntity *, hkpEntity *))hkCompareInfosBySize);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v16);
  v7 = *((float *)&array[v14 - 1]->vfptr + 1);
  hkOstream::printf(outstream, "\n\n");
  hkOstream::printf(outstream, "************************************\n");
  hkOstream::printf(outstream, "********** Per Type Times    *******\n");
  hkOstream::printf(outstream, "************************************\n");
  for ( i = v14 - 1; i >= 0; --i )
  {
    v9 = (hkMonitorStreamAnalyzerPrintByTypeInfo *)array[i];
    if ( (float)(v7 * maxImportance) < v9->m_this.m_value[1] )
    {
      hkOstream::printf(outstream, "\n");
      hkOstream::printf(outstream, "************************************\n\n");
      for ( j = 0; j < v9->m_parents.m_size; ++j )
      {
        hkOstream::printf(outstream, "\t\t");
        printSingleNodeValues(outstream, 0.0, &v9->m_parents.m_data[j]);
      }
      printSingleNodeValues(outstream, v7, &v9->m_this);
      for ( k = 0; k < v9->m_children.m_size; ++k )
      {
        hkOstream::printf(outstream, "\t\t");
        printSingleNodeValues(outstream, 0.0, &v9->m_children.m_data[k]);
      }
    }
    hkMonitorStreamAnalyzerPrintByTypeInfo::~hkMonitorStreamAnalyzerPrintByTypeInfo(v9);
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzerPrintByTypeInfo *, __int64))(*v12[12] + 16i64))(
      v12[12],
      v9,
      176i64);
  }
  v14 = 0;
  if ( v15 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v15);
}

// File Line: 1308
// RVA: 0xC77F90
void __fastcall hkMonitorStreamAnalyzer::writeStatisticsDetails(
        hkOstream *outstream,
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodes,
        int numThreads,
        int numSpus,
        int reportLevel,
        const char *nodeIdForFrameOverview,
        bool showMultithreadedSummary)
{
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v7; // rsi
  float v9; // xmm7_4
  hkMonitorStreamAnalyzer::Node *v10; // r12
  int v11; // r14d
  float v12; // xmm6_4
  __int64 v13; // rdi
  const char *v14; // r14
  hkMonitorStreamAnalyzer::Node *ChildByName; // rax
  char v16; // r15
  int v17; // r13d
  __int64 v18; // rcx
  hkMonitorStreamAnalyzer::Node **m_data; // rax
  hkMonitorStreamAnalyzer::Node *v20; // rdi
  float v21; // xmm6_4
  const char *m_name; // r15
  hkMonitorStreamAnalyzer::Node *i; // rax
  int v24; // eax
  int v25; // r9d
  hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *p_dst; // r8
  int v27; // ecx
  int v28; // ecx
  hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *v29; // rdi
  __int64 v30; // rdx
  int v31; // r9d
  int v32; // ecx
  _BYTE *v33; // r8
  void *v34; // rdi
  void *v35; // rdi
  int m_size; // edx
  int v37; // r12d
  __int64 v38; // r13
  int v39; // edi
  hkLifoAllocator *Value; // rcx
  hkMonitorStreamAnalyzer::Node **m_cur; // rax
  int v42; // edx
  char *v43; // r8
  int v44; // r15d
  int v45; // edi
  int v46; // r9d
  int v47; // r14d
  __int64 v48; // rdi
  _QWORD **v49; // rax
  hkMonitorStreamAnalyzer::Node *v50; // rax
  hkMonitorStreamAnalyzer::Node *v51; // rax
  hkMonitorStreamAnalyzer::Node *v52; // rcx
  hkMonitorStreamAnalyzer::Node *v53; // rdx
  int v54; // edi
  __int64 v55; // r14
  int v56; // r15d
  __int64 v57; // r14
  hkMonitorStreamAnalyzer::Node *v58; // rdi
  _QWORD **v59; // rax
  int v60; // eax
  char *v61; // r14
  signed int v62; // edi
  hkLifoAllocator *v63; // rax
  int v64; // r8d
  int v65; // r12d
  __int64 v66; // r13
  int v67; // edi
  __int64 v68; // r14
  hkMonitorStreamAnalyzer::Node *v69; // r15
  int v70; // r14d
  __int64 v71; // r13
  int v72; // edi
  __int64 v73; // r12
  hkMonitorStreamAnalyzer::Node *v74; // r15
  hkMonitorStreamAnalyzer::Node **array; // [rsp+30h] [rbp-D0h] BYREF
  int v76; // [rsp+38h] [rbp-C8h]
  int v77; // [rsp+3Ch] [rbp-C4h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v79; // [rsp+48h] [rbp-B8h]
  __int64 v80; // [rsp+50h] [rbp-B0h]
  hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions dst; // [rsp+58h] [rbp-A8h] BYREF
  char v82; // [rsp+80h] [rbp-80h]
  hkMonitorStreamAnalyzer::Node sum; // [rsp+90h] [rbp-70h] BYREF
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *result; // [rsp+1B8h] [rbp+B8h] BYREF
  int numThreadsa; // [rsp+1C0h] [rbp+C0h]
  int numSpusa; // [rsp+1C8h] [rbp+C8h]

  numSpusa = numSpus;
  numThreadsa = numThreads;
  result = nodes;
  v7 = nodes;
  hkOstream::printf(outstream, "Havok version: %s\n", "hk_2013.2.0-r1");
  v9 = 0.0;
  v10 = *v7->m_data;
  hkMonitorStreamAnalyzer::Node::Node(&sum, 0i64, "Sum", 1u);
  v11 = 0;
  v12 = 1.0 / (float)v10->m_children.m_size;
  if ( v10->m_children.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      hkMakeSumRecursive(&sum, v10->m_children.m_data[v13]);
      ++v11;
      ++v13;
    }
    while ( v11 < v10->m_children.m_size );
  }
  v14 = nodeIdForFrameOverview;
  ChildByName = hkFindChildByName(&sum, nodeIdForFrameOverview, (hkBool)1);
  if ( !ChildByName )
    goto LABEL_7;
  do
  {
    v9 = v9 + (float)(v12 * ChildByName->m_value[0]);
    ChildByName = hkFindNextChildByName(&sum, v14, ChildByName);
  }
  while ( ChildByName );
  if ( v9 <= 0.0 )
LABEL_7:
    v9 = FLOAT_1000_0;
  v16 = reportLevel;
  if ( (reportLevel & 1) != 0 )
  {
    hkOstream::printf(outstream, "\n\n");
    hkOstream::printf(outstream, "*********************************\n");
    hkOstream::printf(outstream, "********** Total Times    *******\n");
    hkOstream::printf(outstream, "*********************************\n");
    hkOstream::printf(outstream, "Timers are added together\n");
    hkWriteRec(outstream, &sum, 0, v12);
  }
  hkMonitorStreamAnalyzer::Node::~Node(&sum);
  if ( (v16 & 2) != 0 )
  {
    hkOstream::printf(outstream, "\n\n");
    hkOstream::printf(outstream, "*********************************\n");
    hkOstream::printf(outstream, "********** Per Frame Time *******\n");
    hkOstream::printf(outstream, "*********************************\n");
    hkOstream::printf(outstream, "Ascii Art all frames overview\n");
    hkString::memSet(&dst, 32, 0x28u);
    v17 = 0;
    v82 = 0;
    if ( v10->m_children.m_size > 0 )
    {
      v18 = 0i64;
      v80 = 0i64;
      do
      {
        m_data = v10->m_children.m_data;
        v20 = *(hkMonitorStreamAnalyzer::Node **)((char *)m_data + v18);
        if ( v20->m_children.m_size )
        {
          v21 = 0.0;
          m_name = "Unknown";
          for ( i = hkFindChildByName(*(hkMonitorStreamAnalyzer::Node **)((char *)m_data + v18), v14, (hkBool)1);
                i;
                i = hkFindNextChildByName(v20, v14, i) )
          {
            m_name = i->m_name;
            v21 = v21 + i->m_value[0];
          }
          v24 = (int)(float)((float)(v21 * 20.0) / v9);
          if ( v24 >= 0 )
          {
            if ( v24 >= 40 )
              v24 = 39;
          }
          else
          {
            v24 = 0;
          }
          v25 = 0;
          p_dst = &dst;
          if ( v24 > 4 )
          {
            v27 = 4;
            do
            {
              v27 += 4;
              LOBYTE(p_dst->m_indentationToFirstTimerValue) = 9;
              p_dst = (hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *)((char *)p_dst + 1);
              v25 += 4;
            }
            while ( v27 < v24 );
          }
          v28 = v25;
          if ( v25 < v24 )
          {
            v29 = p_dst;
            v30 = (unsigned int)(v24 - v25);
            p_dst = (hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *)((char *)p_dst + v30);
            memset(v29, 32, (unsigned int)v30);
            v28 = v24;
          }
          v31 = v25 + 4;
          v32 = v28 + 1;
          LOBYTE(p_dst->m_indentationToFirstTimerValue) = 35;
          v33 = (char *)&p_dst->m_indentationToFirstTimerValue + 1;
          if ( v32 < v31 )
          {
            v34 = v33;
            v33 += (unsigned int)(v31 - v32);
            memset(v34, 32, (unsigned int)(v31 - v32));
          }
          if ( v31 < 40 )
          {
            v35 = v33;
            v33 += ((unsigned int)(39 - v31) >> 2) + 1;
            memset(v35, 9, ((unsigned int)(39 - v31) >> 2) + 1);
          }
          *v33 = 0;
          hkOstream::printf(outstream, (const char *)&dst);
          hkOstream::printf(outstream, "%i %-12s %f\n", (unsigned int)v17, m_name, v21);
          v18 = v80;
        }
        v18 += 8i64;
        ++v17;
        v80 = v18;
      }
      while ( v17 < v10->m_children.m_size );
      v7 = result;
      v16 = reportLevel;
    }
  }
  if ( (v16 & 4) != 0 )
  {
    m_size = v7->m_size;
    if ( m_size == 1 || !showMultithreadedSummary )
    {
      v65 = 0;
      if ( (*v7->m_data)->m_children.m_size > 0 )
      {
        v66 = 0i64;
        do
        {
          v67 = 0;
          if ( m_size > 0 )
          {
            v68 = 0i64;
            do
            {
              v69 = v7->m_data[v68];
              if ( v65 < v69->m_children.m_size )
              {
                hkMonitorStreamAnalyzer::Node::Node(&sum, 0i64, "Sum", 1u);
                hkMakeSumRecursive(&sum, v69->m_children.m_data[v66]);
                hkOstream::printf(outstream, "\n");
                hkOstream::printf(outstream, "****************************************\n");
                hkOstream::printf(
                  outstream,
                  "****** Summary Frame:%i Thread:%i ******\n",
                  (unsigned int)v65,
                  (unsigned int)v67);
                hkOstream::printf(outstream, "****************************************\n");
                hkOstream::printf(outstream, "%s\n", v69->m_children.m_data[v66]->m_name);
                hkWriteRec(outstream, &sum, 0, 1.0);
                if ( (reportLevel & 8) != 0 )
                  printStatisticsByType(outstream, &sum, 0.0099999998);
                hkMonitorStreamAnalyzer::Node::~Node(&sum);
              }
              m_size = v7->m_size;
              ++v67;
              ++v68;
            }
            while ( v67 < m_size );
          }
          ++v65;
          ++v66;
        }
        while ( v65 < (*v7->m_data)->m_children.m_size );
      }
    }
    else
    {
      v37 = 0;
      if ( (*v7->m_data)->m_children.m_size > 0 )
      {
        v38 = 0i64;
        LODWORD(v80) = v16 & 8;
        do
        {
          hkOstream::printf(outstream, "\n");
          hkOstream::printf(outstream, "****************************************\n");
          hkOstream::printf(outstream, "****** Summary Frame:%i ******\n", (unsigned int)v37);
          hkOstream::printf(outstream, "****************************************\n");
          v39 = v7->m_size;
          array = 0i64;
          v76 = 0;
          v77 = 0x80000000;
          v79 = v39;
          if ( v39 )
          {
            Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            m_cur = (hkMonitorStreamAnalyzer::Node **)Value->m_cur;
            v42 = (8 * v39 + 127) & 0xFFFFFF80;
            v43 = (char *)m_cur + v42;
            if ( v42 > Value->m_slabSize || v43 > Value->m_end )
              m_cur = (hkMonitorStreamAnalyzer::Node **)hkLifoAllocator::allocateFromNewSlab(Value, v42);
            else
              Value->m_cur = v43;
          }
          else
          {
            m_cur = 0i64;
          }
          v44 = v7->m_size;
          array = m_cur;
          v77 = v39 | 0x80000000;
          v45 = v39 & 0x3FFFFFFF;
          p = m_cur;
          if ( v45 >= v44 )
          {
            LODWORD(result) = 0;
          }
          else
          {
            v46 = v44;
            if ( v44 < 2 * v45 )
              v46 = 2 * v45;
            hkArrayUtil::_reserve(
              (hkResult *)&result,
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&array,
              v46,
              8);
            m_cur = array;
          }
          v47 = 0;
          v76 = v44;
          if ( v7->m_size > 0 )
          {
            v48 = 0i64;
            do
            {
              v49 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v50 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v49[11] + 8i64))(
                                                       v49[11],
                                                       144i64);
              if ( v50 )
              {
                hkMonitorStreamAnalyzer::Node::Node(v50, 0i64, &customCaption, 1u);
                v52 = v51;
              }
              else
              {
                v52 = 0i64;
              }
              array[v48] = v52;
              v53 = v7->m_data[v48];
              if ( v53->m_children.m_size > v37 )
                hkMakeSumRecursive(v52, v53->m_children.m_data[v38]);
              ++v47;
              ++v48;
            }
            while ( v47 < v7->m_size );
            v44 = v76;
            m_cur = array;
          }
          v54 = 1;
          dst.m_indentationToFirstTimerValue = 0;
          dst.m_activeNode = 0i64;
          *(_DWORD *)&dst.m_rightArrowChar = 24382;
          dst.m_tabSpacingForTimerNames = 4;
          dst.m_tabSpacingForTimerValues = 2;
          dst.m_timerColumnWidth = 16;
          dst.m_displayPartialTree = 0;
          if ( v44 > 1 )
          {
            v55 = 1i64;
            do
            {
              hkMonitorStreamAnalyzer::mergeTreesForCombinedThreadSummary(*m_cur, m_cur[v55], v54, 0, 0.0);
              m_cur = array;
              ++v54;
              ++v55;
            }
            while ( v54 < v76 );
          }
          hkMonitorStreamAnalyzer::showCombinedThreadSummaryForSingleFrame(
            *m_cur,
            numThreadsa,
            numSpusa,
            outstream,
            &dst);
          if ( (_DWORD)v80 )
            printStatisticsByType(outstream, *array, 0.0099999998);
          v56 = 0;
          if ( v7->m_size > 0 )
          {
            v57 = 0i64;
            do
            {
              v58 = array[v57];
              if ( v58 )
              {
                hkMonitorStreamAnalyzer::Node::~Node(array[v57]);
                v59 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzer::Node *, __int64))(*v59[11] + 16i64))(
                  v59[11],
                  v58,
                  144i64);
              }
              ++v56;
              ++v57;
            }
            while ( v56 < v7->m_size );
          }
          v60 = v76;
          v61 = (char *)p;
          if ( p == array )
            v60 = 0;
          v76 = v60;
          v62 = (8 * v79 + 127) & 0xFFFFFF80;
          v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v64 = (v62 + 15) & 0xFFFFFFF0;
          if ( v62 > v63->m_slabSize || &v61[v64] != v63->m_cur || v63->m_firstNonLifoEnd == v61 )
            hkLifoAllocator::slowBlockFree(v63, v61, v64);
          else
            v63->m_cur = v61;
          v76 = 0;
          if ( v77 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v77);
          ++v37;
          ++v38;
        }
        while ( v37 < (*v7->m_data)->m_children.m_size );
      }
    }
  }
  if ( (reportLevel & 0x10) != 0 )
  {
    v70 = 0;
    if ( (*v7->m_data)->m_children.m_size > 0 )
    {
      v71 = 0i64;
      do
      {
        v72 = 0;
        if ( v7->m_size > 0 )
        {
          v73 = 0i64;
          reportLevel = -numThreadsa;
          do
          {
            v74 = v7->m_data[v73];
            if ( v70 < v74->m_children.m_size )
            {
              hkOstream::printf(outstream, "\n\n");
              hkOstream::printf(outstream, "***************************************\n");
              if ( v72 >= numThreadsa )
                hkOstream::printf(
                  outstream,
                  "***** Details Frame-%i Spu:%i ******\n",
                  (unsigned int)v70,
                  (unsigned int)(v72 + reportLevel));
              else
                hkOstream::printf(
                  outstream,
                  "***** Details Frame-%i Thread:%i ******\n",
                  (unsigned int)v70,
                  (unsigned int)v72);
              hkOstream::printf(outstream, "***************************************\n");
              hkOstream::printf(outstream, "%s\n", v74->m_children.m_data[v71]->m_name);
              hkWriteRec(outstream, v74->m_children.m_data[v71], 0, 1.0);
            }
            ++v72;
            ++v73;
          }
          while ( v72 < v7->m_size );
        }
        ++v70;
        ++v71;
      }
      while ( v70 < (*v7->m_data)->m_children.m_size );
    }
  }
}

// File Line: 1531
// RVA: 0xC7A560
void __fastcall hkWriteRec(hkOstream *outstream, hkMonitorStreamAnalyzer::Node *node, int RecDepth, float factor)
{
  int v4; // ebp
  hkMonitorStreamAnalyzer::Node *v5; // rdi
  int v6; // eax
  __int64 v8; // rbx
  unsigned int v9; // edi
  __int64 v10; // rdx
  unsigned int *m_count; // rcx
  const char *m_name; // r9
  __int64 v13; // rbx
  unsigned int *v14; // rax
  int v15; // ecx
  float v16; // xmm2_4
  const char *v17; // rdx
  int v18; // eax
  __int64 v19; // rbx
  __int64 v20; // [rsp+20h] [rbp-148h]
  char buf[256]; // [rsp+40h] [rbp-128h] BYREF
  int v24; // [rsp+180h] [rbp+18h]

  v4 = 0;
  v5 = node;
  v6 = RecDepth;
  if ( RecDepth )
  {
    if ( RecDepth > 1 )
    {
      v8 = (unsigned int)(RecDepth - 1);
      do
      {
        hkOstream::printf(outstream, "\t");
        --v8;
      }
      while ( v8 );
    }
    v9 = 0;
    v10 = 12i64;
    m_count = node->m_count;
    do
    {
      if ( *m_count )
      {
        ++v4;
        if ( *m_count > v9 )
          v9 = *m_count;
      }
      ++m_count;
      --v10;
    }
    while ( v10 );
    hkString::snprintf(buf, 200, "%s(%i)", node->m_name, v9);
    m_name = node->m_name;
    if ( v9 > 1 )
    {
      if ( factor == 1.0 )
      {
        LODWORD(v20) = v9;
        hkString::snprintf(buf, 200, "%s (%i)", m_name, v20);
      }
      else
      {
        hkString::snprintf(buf, 200, "%s (%4.1f)", m_name, (float)((float)(int)v9 * factor));
      }
    }
    else
    {
      hkString::snprintf(buf, 200, "%s", m_name);
    }
    hkOstream::printf(outstream, "%-32s", buf);
    v13 = 3i64;
    do
    {
      hkOstream::printf(outstream, "\t");
      --v13;
    }
    while ( v13 );
    if ( v4 <= 0 )
    {
      hkOstream::printf(outstream, "% 12.3f\n", 0.0);
    }
    else
    {
      v14 = node->m_count;
      do
      {
        v15 = v14[v13];
        if ( v15 )
        {
          v16 = factor * node->m_value[v13];
          if ( v15 < v9 )
            v16 = v16 * (float)((float)(int)v9 / (float)v15);
          v17 = "% 12.3f: ";
          if ( !--v4 )
            v17 = "% 12.3f\n";
          hkOstream::printf(outstream, v17, v16);
          v14 = node->m_count;
        }
        ++v13;
      }
      while ( v13 < 12 );
    }
    v6 = RecDepth;
    v5 = node;
    v4 = 0;
  }
  if ( v5->m_children.m_size > 0 )
  {
    v18 = v6 + 1;
    v19 = 0i64;
    v24 = v18;
    do
    {
      hkWriteRec(outstream, v5->m_children.m_data[v19], v18, factor);
      v18 = v24;
      ++v4;
      ++v19;
    }
    while ( v4 < v5->m_children.m_size );
  }
}

// File Line: 1629
// RVA: 0xC7A920
hkMonitorStreamAnalyzer::Node *__fastcall hkFindChildByName(
        hkMonitorStreamAnalyzer::Node *node,
        const char *childName,
        hkBool searchAnyChild)
{
  int v3; // ebx
  __int64 v6; // rsi
  char m_bool; // [rsp+40h] [rbp+18h]

  m_bool = searchAnyChild.m_bool;
  v3 = 0;
  if ( node->m_children.m_size <= 0 )
  {
LABEL_6:
    if ( searchAnyChild.m_bool && node->m_children.m_size > 0 )
      return *node->m_children.m_data;
    else
      return 0i64;
  }
  else
  {
    v6 = 0i64;
    while ( (unsigned int)hkString::strCmp(childName, node->m_children.m_data[v6]->m_name) )
    {
      ++v3;
      ++v6;
      if ( v3 >= node->m_children.m_size )
      {
        searchAnyChild.m_bool = m_bool;
        goto LABEL_6;
      }
    }
    return node->m_children.m_data[v3];
  }
}

// File Line: 1647
// RVA: 0xC7A9C0
hkMonitorStreamAnalyzer::Node *__fastcall hkFindNextChildByName(
        hkMonitorStreamAnalyzer::Node *node,
        const char *childName,
        hkMonitorStreamAnalyzer::Node *oldChild)
{
  __int64 m_size; // r10
  int v4; // ebx
  __int64 v7; // r9
  hkMonitorStreamAnalyzer::Node **m_data; // rax
  int v9; // ebx
  __int64 i; // rdi

  m_size = node->m_children.m_size;
  v4 = 0;
  v7 = 0i64;
  if ( (int)m_size > 0 )
  {
    m_data = node->m_children.m_data;
    do
    {
      if ( *m_data == oldChild )
        break;
      ++v7;
      ++v4;
      ++m_data;
    }
    while ( v7 < m_size );
  }
  v9 = v4 + 1;
  if ( v9 >= (int)m_size )
    return 0i64;
  for ( i = v9; (unsigned int)hkString::strCmp(childName, node->m_children.m_data[i]->m_name); ++i )
  {
    if ( ++v9 >= node->m_children.m_size )
      return 0i64;
  }
  return node->m_children.m_data[v9];
}

// File Line: 1673
// RVA: 0xC7A790
void __fastcall hkMakeSumRecursive(hkMonitorStreamAnalyzer::Node *sum, hkMonitorStreamAnalyzer::Node *tree)
{
  int v2; // edi
  __int64 v4; // rsi
  hkMonitorStreamAnalyzer::Node *v5; // rbx
  hkMonitorStreamAnalyzer::Node *ChildByName; // r9
  _QWORD **Value; // rax
  hkMonitorStreamAnalyzer::Node *v8; // rax
  hkMonitorStreamAnalyzer::Node *v9; // rax
  unsigned int *m_count; // rcx
  __int64 v11; // rdx
  signed __int64 v12; // r8
  float v13; // xmm0_4
  hkMonitorStreamAnalyzer::Node *parent; // [rsp+30h] [rbp+8h]

  parent = sum;
  v2 = 0;
  if ( tree->m_children.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = tree->m_children.m_data[v4];
      ChildByName = hkFindChildByName(sum, v5->m_name, 0);
      if ( !ChildByName )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v8 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                Value[11],
                                                144i64);
        if ( v8 )
        {
          hkMonitorStreamAnalyzer::Node::Node(v8, parent, v5->m_name, v5->m_type.m_storage);
          ChildByName = v9;
        }
        else
        {
          ChildByName = 0i64;
        }
      }
      m_count = ChildByName->m_count;
      v11 = 2i64;
      v12 = (char *)v5 - (char *)ChildByName;
      do
      {
        v13 = *(float *)((char *)m_count + v12 - 48);
        m_count += 6;
        *((float *)m_count - 18) = v13 + *((float *)m_count - 18);
        *(m_count - 6) += *(unsigned int *)((char *)m_count + v12 - 24);
        *((float *)m_count - 17) = *(float *)((char *)m_count + v12 - 68) + *((float *)m_count - 17);
        *(m_count - 5) += *(unsigned int *)((char *)m_count + v12 - 20);
        *((float *)m_count - 16) = *(float *)((char *)m_count + v12 - 64) + *((float *)m_count - 16);
        *(m_count - 4) += *(unsigned int *)((char *)m_count + v12 - 16);
        *((float *)m_count - 15) = *(float *)((char *)m_count + v12 - 60) + *((float *)m_count - 15);
        *(m_count - 3) += *(unsigned int *)((char *)m_count + v12 - 12);
        *((float *)m_count - 14) = *(float *)((char *)m_count + v12 - 56) + *((float *)m_count - 14);
        *(m_count - 2) += *(unsigned int *)((char *)m_count + v12 - 8);
        *((float *)m_count - 13) = *(float *)((char *)m_count + v12 - 52) + *((float *)m_count - 13);
        *(m_count - 1) += *(unsigned int *)((char *)m_count + v12 - 4);
        --v11;
      }
      while ( v11 );
      hkMakeSumRecursive(ChildByName, v5);
      sum = parent;
      ++v2;
      ++v4;
    }
    while ( v2 < tree->m_children.m_size );
  }
}

// File Line: 1689
// RVA: 0xC764E0
void __fastcall hkMonitorStreamAnalyzer::writeStatistics(
        hkMonitorStreamAnalyzer *this,
        hkOstream *outStream,
        int reportLevel)
{
  int v3; // ebx
  hkMonitorStreamAnalyzer::Node *StatisticsTreeForMultipleFrames; // rax
  int m_size; // edx
  hkMonitorStreamAnalyzer::Node *v9; // rsi
  int v10; // ecx
  int v11; // edi
  __int64 v12; // rbx
  hkMonitorStreamAnalyzer::Node *v13; // rsi
  _QWORD **Value; // rax
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> array; // [rsp+40h] [rbp-18h] BYREF

  v3 = 0;
  array.m_data = 0i64;
  array.m_size = 0;
  for ( array.m_capacityAndFlags = 0x80000000; v3 < this->m_frameInfos.m_size; ++array.m_size )
  {
    StatisticsTreeForMultipleFrames = hkMonitorStreamAnalyzer::makeStatisticsTreeForMultipleFrames(this, v3, 0);
    m_size = array.m_size;
    v9 = StatisticsTreeForMultipleFrames;
    if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 8);
      m_size = array.m_size;
    }
    ++v3;
    array.m_data[m_size] = v9;
  }
  hkMonitorStreamAnalyzer::writeStatisticsDetails(
    outStream,
    &array,
    this->m_numThreads,
    this->m_numSpus,
    reportLevel,
    this->m_nodeIdForFrameOverview,
    1);
  v10 = array.m_size;
  v11 = 0;
  if ( array.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = array.m_data[v12];
      if ( v13 )
      {
        hkMonitorStreamAnalyzer::Node::~Node(array.m_data[v12]);
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzer::Node *, __int64))(*Value[11] + 16i64))(
          Value[11],
          v13,
          144i64);
        v10 = array.m_size;
      }
      ++v11;
      ++v12;
    }
    while ( v11 < v10 );
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
}

// File Line: 1746
// RVA: 0xC76650
void __fastcall hkMonitorStreamAnalyzer::writeRawStatistics(hkMonitorStreamAnalyzer *this, hkOstream *os)
{
  hkMonitorStreamAnalyzer *v3; // rdi
  int v4; // ecx
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *m_data; // rax
  hkResultEnum m_enum; // eax
  __int64 v7; // r12
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v8; // r13
  int v9; // r15d
  __int64 v10; // r14
  hkMonitorStreamFrameInfo *v11; // rbx
  char *v12; // rax
  __int64 m_frameStreamStart; // rdi
  char *v14; // rbx
  char *v15; // rdi
  int v16; // edx
  __int64 v17; // r8
  __int64 v18; // r9
  const char *v19; // rdx
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  __int64 v24; // rcx
  const char *v25; // r9
  __int64 sizeElem; // [rsp+20h] [rbp-60h]
  __int64 sizeElema; // [rsp+20h] [rbp-60h]
  __int64 sizeElemb; // [rsp+20h] [rbp-60h]
  __int64 v29; // [rsp+28h] [rbp-58h]
  __int64 v30; // [rsp+28h] [rbp-58h]
  __int64 v31; // [rsp+30h] [rbp-50h]
  _BYTE *array; // [rsp+40h] [rbp-40h] BYREF
  int v33; // [rsp+48h] [rbp-38h]
  int v34; // [rsp+4Ch] [rbp-34h]
  hkResult result; // [rsp+A0h] [rbp+20h] BYREF
  hkResult v37; // [rsp+A8h] [rbp+28h] BYREF

  v3 = this;
  array = 0i64;
  v33 = 0;
  v34 = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerDebugAllocator::s_alloc, (const void **)&array, 64, 1);
  v4 = v33;
  if ( v33 == (v34 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerDebugAllocator::s_alloc, (const void **)&array, 1);
    v4 = v33;
  }
  array[v4] = 0;
  m_data = v3->m_frameInfos.m_data;
  ++v33;
  LODWORD(sizeElem) = m_data->m_size;
  hkOstream::printf(
    os,
    "StatisticsDumpInfo(num_threads=%i, num_spus=%i, num_frames=%i)\n",
    (unsigned int)v3->m_numThreads,
    (unsigned int)v3->m_numSpus,
    sizeElem);
  m_enum = HK_SUCCESS;
  result.m_enum = HK_SUCCESS;
  if ( v3->m_frameInfos.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v3->m_frameInfos.m_data;
      v9 = 0;
      if ( v3->m_frameInfos.m_data[v7].m_size > 0 )
      {
        v10 = 0i64;
        do
        {
          v11 = v8[v7].m_data;
          LODWORD(v29) = v11[v10].m_absoluteTimeCounter.m_storage;
          LODWORD(sizeElema) = v11[v10].m_threadId;
          hkOstream::printf(
            os,
            "FrameInfo(heading=%s, frame=%i, thread_id=%i, time_counter=%i)\n",
            (const char *)((unsigned __int64)v11[v10].m_heading.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (unsigned int)v9,
            sizeElema,
            v29);
          v12 = v3->m_data.m_data;
          m_frameStreamStart = v11[v10].m_frameStreamStart;
          v14 = &v12[v11[v10].m_frameStreamEnd];
          v15 = &v12[m_frameStreamStart];
          if ( (v34 & 0x3FFFFFFF) != 0 )
            v37.m_enum = HK_SUCCESS;
          else
            hkArrayUtil::_reserve(&v37, &hkContainerDebugAllocator::s_alloc, (const void **)&array, 1, 1);
          v33 = 1;
          *array = 0;
          if ( v15 < v14 )
          {
            v16 = v33;
            while ( 2 )
            {
              v17 = *(_QWORD *)v15;
              switch ( **(_BYTE **)v15 )
              {
                case E:
                  v33 = v16 - 2;
                  array[v16 - 3] = 0;
                  LODWORD(v29) = *((_DWORD *)v15 + 3);
                  LODWORD(sizeElema) = *((_DWORD *)v15 + 2);
                  hkOstream::printf(
                    os,
                    "%sTimerEnd(%s,%u,%u)\n",
                    array,
                    (const char *)(*(_QWORD *)v15 + 2i64),
                    sizeElema,
                    v29);
                  v15 += 16;
                  goto LABEL_32;
                case F:
                case O:
                case P:
                case p:
                  goto $LN14_97;
                case L:
                  LODWORD(v29) = *((_DWORD *)v15 + 3);
                  LODWORD(sizeElema) = *((_DWORD *)v15 + 2);
                  hkOstream::printf(os, "%sTimerBegin(%s, %u, %u)\n", array, (const char *)(v17 + 2), sizeElema, v29);
                  LODWORD(v30) = *((_DWORD *)v15 + 3);
                  LODWORD(sizeElemb) = *((_DWORD *)v15 + 2);
                  hkOstream::printf(
                    os,
                    "%sTimerSplit(%s, %u, %u)\n",
                    array,
                    (const char *)(*((_QWORD *)v15 + 2) + 2i64),
                    sizeElemb,
                    v30);
                  array[v33 - 1] = 32;
                  v22 = v33;
                  if ( v33 == (v34 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerDebugAllocator::s_alloc, (const void **)&array, 1);
                    v22 = v33;
                  }
                  array[v22] = 32;
                  v23 = v33 + 1;
                  v33 = v23;
                  if ( v23 == (v34 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerDebugAllocator::s_alloc, (const void **)&array, 1);
                    v23 = v33;
                  }
                  array[v23] = 0;
                  v16 = v33 + 1;
                  v15 += 24;
                  ++v33;
                  goto $LN14_97;
                case M:
                  hkOstream::printf(os, "%sAddValue(%s,%f)\n", array, (const char *)(v17 + 1), *((float *)v15 + 2));
                  v15 += 16;
                  goto LABEL_32;
                case N:
                  v15 += 8;
                  goto $LN14_97;
                case S:
                  v33 = v16 - 2;
                  v24 = v16 - 2;
                  v19 = "%sTimerSplit(%s, %u, %u)\n";
                  array[v24 - 1] = 0;
                  v18 = *(_QWORD *)v15 + 2i64;
                  goto LABEL_14;
                case T:
                  v18 = v17 + 2;
                  v19 = "%sTimerBegin(%s,%u,%u)\n";
LABEL_14:
                  LODWORD(v29) = *((_DWORD *)v15 + 3);
                  LODWORD(sizeElema) = *((_DWORD *)v15 + 2);
                  hkOstream::printf(os, v19, array, v18, sizeElema, v29);
                  array[v33 - 1] = 32;
                  v20 = v33;
                  if ( v33 == (v34 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerDebugAllocator::s_alloc, (const void **)&array, 1);
                    v20 = v33;
                  }
                  array[v20] = 32;
                  v21 = v33 + 1;
                  v33 = v21;
                  if ( v21 == (v34 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerDebugAllocator::s_alloc, (const void **)&array, 1);
                    v21 = v33;
                  }
                  array[v21] = 0;
                  v16 = v33 + 1;
                  v15 += 16;
                  ++v33;
                  goto $LN14_97;
                case l:
                  v33 = v16 - 2;
                  array[v16 - 3] = 0;
                  LODWORD(v29) = *((_DWORD *)v15 + 3);
                  LODWORD(sizeElema) = *((_DWORD *)v15 + 2);
                  hkOstream::printf(
                    os,
                    "%sTimerEnd(%s, %u, %u)\n",
                    array,
                    (const char *)(*(_QWORD *)v15 + 2i64),
                    sizeElema,
                    v29);
                  v15 += 16;
                  goto LABEL_32;
                case m:
                  v25 = "Alloc";
                  if ( *((int *)v15 + 4) < 0 )
                    v25 = "Free";
                  LODWORD(v31) = *((_DWORD *)v15 + 4) & 0x7FFFFFFF;
                  hkOstream::printf(
                    os,
                    "%s%s%s(ptr=0x%p, nbytes=%i)\n",
                    array,
                    v25,
                    (const char *)(v17 + 1),
                    *((const void **)v15 + 1),
                    v31);
                  v15 += 24;
LABEL_32:
                  v16 = v33;
$LN14_97:
                  if ( v15 >= v14 )
                    break;
                  continue;
                default:
                  goto LABEL_37;
              }
              break;
            }
          }
          v3 = this;
          ++v9;
          ++v10;
        }
        while ( v9 < v8[v7].m_size );
        m_enum = result.m_enum;
      }
      ++m_enum;
      ++v7;
      result.m_enum = m_enum;
    }
    while ( m_enum < v3->m_frameInfos.m_size );
  }
LABEL_37:
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerDebugAllocator::s_alloc.vfptr->bufFree(&hkContainerDebugAllocator::s_alloc, array, v34 & 0x3FFFFFFF);
}

// File Line: 1878
// RVA: 0xC7C1B0
hkMonitorStreamAnalyzer::Node *__fastcall findChildNode(
        hkMonitorStreamAnalyzer::Node *currentNode,
        double sampleTime,
        int absoluteTimeIndex)
{
  int m_size; // r9d
  __int64 v4; // rdi
  __int64 v5; // rsi
  int v7; // r10d
  hkMonitorStreamAnalyzer::Node **m_data; // r11
  hkMonitorStreamAnalyzer::Node *v9; // rcx
  __int64 v10; // rdx
  hkMonitorStreamAnalyzer::Node **i; // r8
  hkMonitorStreamAnalyzer::Node *v12; // rcx

  m_size = currentNode->m_children.m_size;
  v4 = 0i64;
  v5 = absoluteTimeIndex;
  v7 = 0;
  if ( m_size > 2 )
  {
    m_data = currentNode->m_children.m_data;
    do
    {
      v9 = m_data[(m_size + v7) >> 1];
      if ( v9->m_type.m_storage == 2 )
        break;
      if ( sampleTime >= v9->m_absoluteStartTime )
        v7 = (m_size + v7) >> 1;
      else
        m_size = (m_size + v7) >> 1;
    }
    while ( m_size - v7 > 2 );
  }
  v10 = v7;
  if ( v7 >= (__int64)m_size )
    return 0i64;
  for ( i = &currentNode->m_children.m_data[v7]; ; ++i )
  {
    v12 = *i;
    if ( (*i)->m_type.m_storage != 2 && sampleTime <= v12->m_value[v5] + v12->m_absoluteStartTime )
      break;
    if ( ++v10 >= m_size )
      return 0i64;
  }
  if ( sampleTime >= v12->m_absoluteStartTime )
    return *i;
  return (hkMonitorStreamAnalyzer::Node *)v4;
}

// File Line: 1926
// RVA: 0xC7B3C0
hkMonitorStreamAnalyzer::Node *__fastcall getNodeAtSample(
        hkMonitorStreamAnalyzer::Node *currentNode,
        hkMonitorStreamAnalyzer::Node *lastHit,
        long double sampleTime,
        int absoluteTimeIndex)
{
  hkMonitorStreamAnalyzer::Node *ChildNode; // rax

  if ( lastHit && lastHit->m_value[absoluteTimeIndex] + lastHit->m_absoluteStartTime >= sampleTime )
    currentNode = lastHit;
  if ( currentNode )
  {
    while ( 1 )
    {
      ChildNode = findChildNode(currentNode, sampleTime, absoluteTimeIndex);
      if ( !ChildNode )
        break;
      currentNode = ChildNode;
    }
  }
  return currentNode;
}

// File Line: 1958
// RVA: 0xC7B440
void __fastcall outputStatsForFrame(
        hkMonitorStreamAnalyzer::Node *root,
        float startTime,
        float timeInc,
        int maxFrames,
        hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *timerNodesAtTicks,
        int absoluteTimeIndex)
{
  hkMonitorStreamAnalyzer::Node **m_data; // r8
  hkMonitorStreamAnalyzer::Node *NodeAtSample; // rbp
  hkMonitorStreamAnalyzer::Node *v8; // rdi
  int v9; // r14d
  int v12; // edx
  hkMonitorStreamAnalyzer::Node **v13; // rax
  hkMonitorStreamAnalyzer::Node *v14; // rsi
  int v15; // eax
  __int64 v16; // rcx
  hkMonitorStreamAnalyzer::Node **v17; // rax
  double v18; // xmm6_8
  double v19; // xmm7_8
  double m_absoluteStartTime; // xmm1_8
  long double v21; // xmm7_8
  double v22; // xmm7_8

  m_data = root->m_children.m_data;
  NodeAtSample = 0i64;
  v8 = *m_data;
  v9 = maxFrames;
  v12 = 0;
  if ( *m_data )
  {
    v13 = root->m_children.m_data;
    while ( v8->m_type.m_storage == 2 )
    {
      ++v12;
      ++v13;
      if ( v12 >= root->m_children.m_size )
      {
        v8 = 0i64;
        break;
      }
      v8 = *v13;
      if ( !*v13 )
        break;
    }
  }
  v14 = m_data[root->m_children.m_size - 1];
  v15 = root->m_children.m_size - 1;
  v16 = v15;
  if ( v14 )
  {
    v17 = &m_data[v15];
    while ( v14->m_type.m_storage == 2 )
    {
      --v17;
      if ( --v16 >= 0 )
      {
        v14 = *v17;
        if ( *v17 )
          continue;
      }
      return;
    }
    if ( v8 )
    {
      v18 = 0.0;
      v19 = v8->m_absoluteStartTime - startTime;
      if ( maxFrames )
      {
        do
        {
          if ( v19 <= v18 )
            break;
          v18 = v18 + timeInc;
          if ( timerNodesAtTicks->m_size == (timerNodesAtTicks->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&timerNodesAtTicks->m_data, 8);
          timerNodesAtTicks->m_data[timerNodesAtTicks->m_size++] = 0i64;
          --v9;
        }
        while ( v9 );
      }
      m_absoluteStartTime = v8->m_absoluteStartTime;
      v21 = v14->m_value[absoluteTimeIndex] + v14->m_absoluteStartTime;
      root->m_absoluteStartTime = m_absoluteStartTime;
      v22 = v21 - startTime;
      for ( root->m_value[absoluteTimeIndex] = startTime + v22 - m_absoluteStartTime + 1.0; v9; --v9 )
      {
        if ( v22 <= v18 )
          break;
        NodeAtSample = getNodeAtSample(root, NodeAtSample, startTime + v18, absoluteTimeIndex);
        if ( NodeAtSample )
        {
          if ( timerNodesAtTicks->m_size == (timerNodesAtTicks->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&timerNodesAtTicks->m_data, 8);
          timerNodesAtTicks->m_data[timerNodesAtTicks->m_size++] = NodeAtSample;
        }
        v18 = v18 + timeInc;
      }
    }
  }
}

// File Line: 2018
// RVA: 0xC758E0
void __fastcall hkMonitorStreamColorTable::setupDefaultColorTable(hkMonitorStreamColorTable *this)
{
  hkMonitorStreamColorTable::addColor(this, "Physics 2012", hkColor::GREY25);
  hkMonitorStreamColorTable::addColor(this, "NarrowPhase", hkColor::CORNFLOWERBLUE);
  hkMonitorStreamColorTable::addColor(this, "Broadphase", hkColor::BLUE);
  hkMonitorStreamColorTable::addColor(this, "3AxisSweep", hkColor::MIDNIGHTBLUE);
  hkMonitorStreamColorTable::addColor(this, "WaitForExport", hkColor::DARKSLATEBLUE);
  hkMonitorStreamColorTable::addColor(this, "SplitIsle", hkColor::BROWN);
  hkMonitorStreamColorTable::addColor(this, "PostCollide", hkColor::BEIGE);
  hkMonitorStreamColorTable::addColor(this, "Maintenance", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "InterIsland", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "PendingOps", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "ConstraintCallbacks", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "SingleObj", hkColor::TAN);
  hkMonitorStreamColorTable::addColor(this, "TOIs", hkColor::GOLD);
  hkMonitorStreamColorTable::addColor(this, "PostSimCB", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(this, "Integrate", hkColor::GREEN);
  hkMonitorStreamColorTable::addColor(this, "Actions", hkColor::SPRINGGREEN);
  hkMonitorStreamColorTable::addColor(this, "SetupJobs", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(this, "BuildJacTask", hkColor::SEAGREEN);
  hkMonitorStreamColorTable::addColor(this, "BuildAccumulators", hkColor::OLIVE);
  hkMonitorStreamColorTable::addColor(this, "BuildJacobians", hkColor::FORESTGREEN);
  hkMonitorStreamColorTable::addColor(this, "Solver", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(this, "Solve", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(this, "IntegrateMotions", hkColor::LIGHTGREEN);
  hkMonitorStreamColorTable::addColor(this, "SolverExport", hkColor::DARKSEAGREEN);
  hkMonitorStreamColorTable::addColor(this, "GetNextJob", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "GetNextTask", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "FinishJob", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "FinishTask", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "FinishJobAndGetNext", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "FinishTaskAndGetNext", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "WaitForSignal", hkColor::MAROON);
  hkMonitorStreamColorTable::addColor(this, "WaitForTasks", hkColor::MAROON);
  hkMonitorStreamColorTable::addColor(this, "LockQueue", hkColor::RED);
  hkMonitorStreamColorTable::addColor(this, "CriticalLock", hkColor::CRIMSON);
  hkMonitorStreamColorTable::addColor(this, "hkSpuMoppRaycastQuery", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "VehicleManager", hkColor::PALEGOLDENROD);
  hkMonitorStreamColorTable::addColor(this, "Vehicle", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(this, "VehicleJob", hkColor::DARKKHAKI);
  hkMonitorStreamColorTable::addColor(this, "ApplyVehicleForces", hkColor::KHAKI);
  hkMonitorStreamColorTable::addColor(this, "Physics", 0xFFFFB300);
  hkMonitorStreamColorTable::addColor(this, "PreCollide", hkColor::BEIGE);
  hkMonitorStreamColorTable::addColor(this, "DispatchCommands", hkColor::GOLD);
  hkMonitorStreamColorTable::addColor(this, "PostCollideEvent", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(this, "BroadPhaseTask", hkColor::BLUE);
  hkMonitorStreamColorTable::addColor(this, "NarrowPhaseTask", hkColor::CORNFLOWERBLUE);
  hkMonitorStreamColorTable::addColor(this, "GatherConstraintsTask", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(this, "ConstraintSetupTask", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(this, "PreSolve", hkColor::OLIVE);
  hkMonitorStreamColorTable::addColor(this, "SolverTask", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(this, "SolveConstraints", hkColor::LIGHTGREEN);
  hkMonitorStreamColorTable::addColor(this, "SubIntegrate", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(this, "UpdateBodies", hkColor::DARKSEAGREEN);
  hkMonitorStreamColorTable::addColor(this, "PostSolve", hkColor::OLIVE);
  hkMonitorStreamColorTable::addColor(this, "PostSimulateEvent", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(this, "WaitForMainThread", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "WaitForWorkerThreads", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "WaitForOtherTasks", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(this, "ReleaseSemaphore", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "ReleaseSemaphore_1", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "ReleaseSemaphore_2", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "ReleaseSemaphore_3", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "ReleaseSemaphore_4", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "ReleaseSemaphore_5+", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "hkaQuantizedSampleAndCombineJob", hkColor::ORCHID);
  hkMonitorStreamColorTable::addColor(this, "SampleAndBlend", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "hkaCpuSampleAnimationJob", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "hkaCpuSampleAndCombineJob", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(this, "SpuAnim", hkColor::LIGHTBLUE);
  hkMonitorStreamColorTable::addColor(this, "Cloth", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(this, "Simulate", hkColor::LIGHTGREEN);
  hkMonitorStreamColorTable::addColor(this, "Accumulate Actions", hkColor::SPRINGGREEN);
  hkMonitorStreamColorTable::addColor(this, "Collide", hkColor::DARKGREEN);
  hkMonitorStreamColorTable::addColor(this, "Collide And Solve", hkColor::DARKGREEN);
  hkMonitorStreamColorTable::addColor(this, "Input Conversion", hkColor::PINK);
  hkMonitorStreamColorTable::addColor(this, "Output Conversion", hkColor::PINK);
  hkMonitorStreamColorTable::addColor(this, "Mesh Mesh Deform", hkColor::LIGHTBLUE);
  hkMonitorStreamColorTable::addColor(this, "Mesh Bone Deform", hkColor::LIGHTBLUE);
  hkMonitorStreamColorTable::addColor(this, "Skin", hkColor::BLUE);
  hkMonitorStreamColorTable::addColor(this, "Gather All Vertices", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "Gather Some Vertices", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "Copy Vertices", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(this, "Recalculate Some Normals", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(this, "Recalculate All Normals", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(this, "Update Some Vertex Frames (N)", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(this, "Update Some Vertex Frames (T)", hkColor::DARKORANGE);
  hkMonitorStreamColorTable::addColor(this, "Update Some Vertex Frames (TB)", hkColor::DARKORANGE);
  hkMonitorStreamColorTable::addColor(this, "Update All Vertex Frames (N)", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(this, "Update All Vertex Frames (T)", hkColor::DARKORANGE);
  hkMonitorStreamColorTable::addColor(this, "Update All Vertex Frames (TB)", hkColor::DARKORANGE);
}

// File Line: 2149
// RVA: 0xC757C0
__int64 __fastcall hkMonitorStreamColorTable::findColor(hkMonitorStreamColorTable *this, const char *color)
{
  int v2; // ebx
  __int64 i; // rdi

  v2 = 0;
  if ( this->m_colorPairs.m_size <= 0 )
    return this->m_defaultColor;
  for ( i = 0i64;
        (unsigned int)hkString::strCasecmp(
                        (const char *)((unsigned __int64)this->m_colorPairs.m_data[i].m_colorName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                        color);
        ++i )
  {
    if ( ++v2 >= this->m_colorPairs.m_size )
      return this->m_defaultColor;
  }
  return this->m_colorPairs.m_data[v2].m_color;
}

// File Line: 2161
// RVA: 0xC75850
void __fastcall hkMonitorStreamColorTable::addColor(
        hkMonitorStreamColorTable *this,
        const char *name,
        unsigned int color)
{
  int m_capacityAndFlags; // eax
  hkArray<hkMonitorStreamColorTable::ColorPair,hkContainerHeapAllocator> *p_m_colorPairs; // rdi
  __int64 v7; // rbx
  hkStringPtr strRef; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v9; // [rsp+28h] [rbp-10h]

  hkStringPtr::hkStringPtr(&strRef, name);
  m_capacityAndFlags = this->m_colorPairs.m_capacityAndFlags;
  v9 = color;
  p_m_colorPairs = &this->m_colorPairs;
  if ( this->m_colorPairs.m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_colorPairs.m_data, 16);
  v7 = (__int64)&p_m_colorPairs->m_data[this->m_colorPairs.m_size];
  if ( v7 )
  {
    hkStringPtr::hkStringPtr((hkStringPtr *)v7, &strRef);
    *(_DWORD *)(v7 + 8) = v9;
  }
  ++p_m_colorPairs->m_size;
  hkStringPtr::~hkStringPtr(&strRef);
}

// File Line: 2183
// RVA: 0xC7B670
char __fastcall saveToTGA(const char *data, hkOstream *s, int width, int height)
{
  char dst[12]; // [rsp+20h] [rbp-28h] BYREF
  __int16 v10; // [rsp+2Ch] [rbp-1Ch]
  __int16 v11; // [rsp+2Eh] [rbp-1Ah]
  char v12; // [rsp+30h] [rbp-18h]

  hkString::memSet(dst, 0, 0x12u);
  dst[2] = 2;
  v11 = height;
  v10 = width;
  v12 = 32;
  hkOstream::write(s, dst, 18i64);
  hkOstream::write(s, data, (unsigned int)(4 * height * width));
  return 1;
}

// File Line: 2327
// RVA: 0xC7B700
void __fastcall drawDigit(int nr, int currentY, int outputPixelWidth, int *texture)
{
  __int64 v4; // r10
  unsigned int *v5; // r11
  int i; // ecx

  v4 = 0i64;
  v5 = numbers[nr];
  for ( i = 0; i < 32; i += 4 )
  {
    if ( ((v5[6] << i) & 0xF0000000) != 0 )
      texture[v4] = -16777216;
    if ( ((v5[5] << i) & 0xF0000000) != 0 )
      texture[v4 + outputPixelWidth] = -16777216;
    if ( ((v5[4] << i) & 0xF0000000) != 0 )
      texture[2 * outputPixelWidth + v4] = -16777216;
    if ( ((v5[3] << i) & 0xF0000000) != 0 )
      texture[2 * outputPixelWidth + v4 + outputPixelWidth] = -16777216;
    if ( ((v5[2] << i) & 0xF0000000) != 0 )
      texture[4 * outputPixelWidth + v4] = -16777216;
    if ( ((v5[1] << i) & 0xF0000000) != 0 )
      texture[4 * outputPixelWidth + v4 + outputPixelWidth] = -16777216;
    if ( ((*v5 << i) & 0xF0000000) != 0 )
      texture[6 * outputPixelWidth + v4] = -16777216;
    ++v4;
  }
}

// File Line: 2342
// RVA: 0xC7B800
void __fastcall drawNumber(int nr, int currentY, int outputPixelWidth, int *texture)
{
  int v7; // edi
  int i; // ebx

  v7 = 0;
  for ( i = 1000; i >= 1; i /= 10 )
  {
    drawDigit(nr / i % 10, currentY, outputPixelWidth, &texture[v7]);
    v7 += 7;
  }
}

// File Line: 2358
// RVA: 0xC7B8A0
hkMonitorStreamAnalyzer::Node *__fastcall getNodeSampledAtTick(
        hkMonitorStreamFrameInfo *info,
        int frameIndex,
        int tick,
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodes,
        int maxX,
        float frameTime,
        float absoluteFrameStartTimes)
{
  int v7; // esi
  __int64 v9; // rbp
  __int64 v10; // r15
  float v12; // xmm6_4
  hkMonitorStreamAnalyzer::Node **m_data; // rdx
  hkMonitorStreamAnalyzer::Node *v14; // rbx
  int absoluteTimeIndex; // eax
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> timerNodesAtTicks; // [rsp+30h] [rbp-38h] BYREF

  v7 = maxX;
  v9 = tick;
  v10 = frameIndex;
  timerNodesAtTicks.m_data = 0i64;
  timerNodesAtTicks.m_size = 0;
  timerNodesAtTicks.m_capacityAndFlags = 0x80000000;
  v12 = frameTime / (float)maxX;
  if ( maxX > 0 )
    hkArrayUtil::_reserve(
      (hkResult *)&maxX,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&timerNodesAtTicks.m_data,
      maxX,
      8);
  m_data = nodes->m_data;
  v14 = 0i64;
  if ( nodes->m_data[v10]->m_children.m_size > 0 )
  {
    timerNodesAtTicks.m_size = 0;
    absoluteTimeIndex = info->m_absoluteTimeCounter.m_storage ? info->m_indexOfTimer1 : info->m_indexOfTimer0;
    outputStatsForFrame(m_data[v10], absoluteFrameStartTimes, v12, v7, &timerNodesAtTicks, absoluteTimeIndex);
    if ( (int)v9 < timerNodesAtTicks.m_size )
      v14 = timerNodesAtTicks.m_data[v9];
  }
  timerNodesAtTicks.m_size = 0;
  if ( timerNodesAtTicks.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      timerNodesAtTicks.m_data,
      8 * timerNodesAtTicks.m_capacityAndFlags);
  return v14;
}

// File Line: 2398
// RVA: 0xC7B9D0
void __fastcall drawStatistics(
        hkMonitorStreamFrameInfo *info,
        int frameIndex,
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodes,
        int *texture,
        int height,
        hkMonitorStreamColorTable *colorTable,
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *pixelWidth,
        int maxX,
        float frameTime,
        float absoluteFrameStartTimes,
        hkPointerMap<char const *,unsigned int,hkContainerHeapAllocator> *unknownColorMap)
{
  int v11; // ebx
  int *v12; // r12
  hkMonitorStreamAnalyzer::Node *v13; // rsi
  float v15; // xmm6_4
  int m_indexOfTimer1; // eax
  __int64 m_size; // r10
  unsigned int v18; // r13d
  __int64 v19; // rsi
  hkMonitorStreamAnalyzer::Node *v20; // rdi
  __int64 v21; // r9
  __int64 v22; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v23; // rbx
  hkMonitorStreamAnalyzer::Node *v24; // r14
  unsigned int v25; // ecx
  const char *m_name; // r12
  int v27; // ebx
  __int64 v28; // rsi
  __int64 v29; // rdi
  _DWORD *v30; // rax
  __int64 v31; // rdx
  __int64 v32; // [rsp+10h] [rbp-71h]
  unsigned __int64 out; // [rsp+18h] [rbp-69h] BYREF
  int sizeElem[2]; // [rsp+20h] [rbp-61h] BYREF
  int absoluteTimeIndex[2]; // [rsp+28h] [rbp-59h]
  __int64 v36; // [rsp+30h] [rbp-51h]
  __int64 v37; // [rsp+38h] [rbp-49h]
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> array; // [rsp+40h] [rbp-41h] BYREF
  AMD_HD3D v39; // [rsp+50h] [rbp-31h] BYREF
  hkResult result; // [rsp+B8h] [rbp+37h] BYREF
  hkResult vars0; // [rsp+C0h] [rbp+3Fh] BYREF
  int *retaddr; // [rsp+C8h] [rbp+47h]
  int v43; // [rsp+D0h] [rbp+4Fh]
  __int64 v44; // [rsp+D8h] [rbp+57h]
  int v45; // [rsp+E0h] [rbp+5Fh]
  int v46; // [rsp+E8h] [rbp+67h]

  v46 = (int)texture;
  v12 = texture;
  v13 = nodes->m_data[frameIndex];
  if ( !v13->m_children.m_size )
    return;
  v43 = v11;
  v39.mHeight = -1;
  array.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&v39.mEnableStereo = 0i64;
  v39.mWidth = 0;
  v15 = *(float *)&height / (float)(int)texture;
  array.m_data = 0i64;
  array.m_size = 0;
  if ( (int)texture > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, (int)texture, 8);
  if ( info->m_absoluteTimeCounter.m_storage )
    m_indexOfTimer1 = info->m_indexOfTimer1;
  else
    m_indexOfTimer1 = info->m_indexOfTimer0;
  outputStatsForFrame(v13, *(float *)&colorTable, v15, v46, &array, m_indexOfTimer1);
  m_size = array.m_size;
  v18 = hkColor::WHITE;
  v19 = v11;
  v20 = 0i64;
  v21 = 0i64;
  v22 = v46;
  v37 = v46;
  v36 = array.m_size;
  if ( array.m_size <= 0 )
    goto LABEL_32;
  v23 = pixelWidth;
  do
  {
    if ( v21 >= v22 )
      break;
    v24 = array.m_data[v21];
    if ( !v24 || v24->m_type.m_storage )
      goto LABEL_31;
    if ( v24 == v20 )
    {
      v25 = v18;
      goto LABEL_28;
    }
    v18 = hkColor::WHITE;
    *(_QWORD *)absoluteTimeIndex = array.m_data[v21];
    while ( 1 )
    {
      m_name = v24->m_name;
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v39,
             &result,
             (unsigned __int64)m_name,
             (unsigned __int64 *)sizeElem)->m_enum == HK_SUCCESS )
      {
        v18 = sizeElem[0];
        goto LABEL_27;
      }
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
             v23,
             &vars0,
             (unsigned __int64)m_name,
             &out)->m_enum )
        break;
      v18 = out;
LABEL_23:
      v24 = v24->m_parent;
      if ( !v24 )
        goto LABEL_27;
    }
    v27 = 0;
    v28 = 0i64;
    if ( *(int *)(v44 + 24) <= 0 )
    {
LABEL_22:
      v23 = pixelWidth;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        pixelWidth,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)m_name,
        v18);
      goto LABEL_23;
    }
    v29 = 0i64;
    while ( (unsigned int)hkString::strCasecmp(
                            (const char *)(*(_QWORD *)(v29 + *(_QWORD *)(v44 + 16)) & 0xFFFFFFFFFFFFFFFEui64),
                            m_name) )
    {
      ++v27;
      ++v28;
      v29 += 16i64;
      if ( v27 >= *(_DWORD *)(v44 + 24) )
        goto LABEL_22;
    }
    v18 = *(_DWORD *)(*(_QWORD *)(v44 + 16) + 16 * v28 + 8);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v39,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)m_name,
      v18);
LABEL_27:
    v23 = pixelWidth;
    v21 = v32;
    v12 = retaddr;
    v20 = *(hkMonitorStreamAnalyzer::Node **)absoluteTimeIndex;
    v19 = v43;
    m_size = v36;
    v25 = v18 & 0xFF000000 | (v18 >> 1) & 0x7F7F7F;
LABEL_28:
    if ( v19 > 0 )
    {
      v30 = v12;
      v31 = v19;
      do
      {
        *v30 = v25;
        v30 += v45;
        --v31;
      }
      while ( v31 );
    }
LABEL_31:
    v22 = v37;
    ++v21;
    retaddr = ++v12;
  }
  while ( v21 < m_size );
LABEL_32:
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkMonitorStreamAnalyzer::Node **, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      (unsigned int)(8 * array.m_capacityAndFlags),
      v21);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v39,
    &hkContainerHeapAllocator::s_alloc);
  _(&v39);
}

// File Line: 2501
// RVA: 0xC7BCE0
float __fastcall _hkMin(float a, float b)
{
  if ( a >= b )
    return b;
  return a;
}

// File Line: 2506
// RVA: 0xC7BCF0
float __fastcall _hkMax(float a, float b)
{
  if ( a <= b )
    return b;
  return a;
}

// File Line: 2511
// RVA: 0xC7BD00
long double __fastcall _hkMinD(long double a, long double b)
{
  if ( a >= b )
    return b;
  return a;
}

// File Line: 2516
// RVA: 0xC7BD20
long double __fastcall _hkMaxD(long double a, long double b)
{
  if ( a <= b )
    return b;
  return a;
}

// File Line: 2521
// RVA: 0xC77F80
void __fastcall hkMonitorStreamAnalyzer::checkAllThreadsCapturedSameNumFrames(hkMonitorStreamAnalyzer *this)
{
  ;
}

// File Line: 2533
// RVA: 0xC76BC0
__int64 __fastcall hkMonitorStreamAnalyzer::ThreadDrawInput::computePerThreadHeightToFit(
        int textureHeight,
        int numFrames,
        int numThreads,
        int frameGap,
        int threadGap)
{
  return (unsigned int)((textureHeight / numFrames - frameGap) / numThreads - threadGap);
}

// File Line: 2540
// RVA: 0xC7BD40
__int64 __fastcall hkRoundUpPow2(unsigned int n)
{
  unsigned int v1; // ecx
  unsigned int v2; // ecx

  v1 = ((((n - 1) >> 1) | (n - 1)) >> 2) | ((n - 1) >> 1) | (n - 1);
  v2 = (((v1 >> 4) | v1) >> 8) | (v1 >> 4) | v1;
  return (v2 | HIWORD(v2)) + 1;
}

// File Line: 2552
// RVA: 0xC7BD70
void __fastcall rebase(
        hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *rootNodes,
        double hdt,
        long double dt)
{
  int v3; // esi
  __int64 v5; // rbx
  hkMonitorStreamAnalyzer::Node *v6; // rdx
  double m_absoluteStartTime; // xmm0_8

  v3 = 0;
  if ( rootNodes->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = rootNodes->m_data[v5];
      if ( v6->m_type.m_storage != 2 )
      {
        m_absoluteStartTime = v6->m_absoluteStartTime;
        if ( m_absoluteStartTime < hdt )
          v6->m_absoluteStartTime = m_absoluteStartTime + dt;
      }
      rebase(&rootNodes->m_data[v5]->m_children, hdt, dt);
      ++v3;
      ++v5;
    }
    while ( v3 < rootNodes->m_size );
  }
}

// File Line: 2565
// RVA: 0xC7BE10
char __fastcall needsRebase(
        hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *rootNodes,
        double halfRange,
        long double *maxSoFar)
{
  int v3; // edi
  __int64 i; // rbx
  hkMonitorStreamAnalyzer::Node *v8; // rdx
  double m_absoluteStartTime; // xmm1_8
  long double v10; // xmm0_8

  v3 = 0;
  if ( rootNodes->m_size <= 0 )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    v8 = rootNodes->m_data[i];
    if ( v8->m_type.m_storage == 2 )
      goto LABEL_9;
    m_absoluteStartTime = v8->m_absoluteStartTime;
    if ( m_absoluteStartTime < halfRange && *maxSoFar - m_absoluteStartTime > halfRange )
      break;
    v10 = *maxSoFar;
    if ( *maxSoFar <= m_absoluteStartTime )
      v10 = v8->m_absoluteStartTime;
    *maxSoFar = v10;
LABEL_9:
    if ( needsRebase(&rootNodes->m_data[i]->m_children, halfRange, maxSoFar) )
      return 1;
    if ( ++v3 >= rootNodes->m_size )
      return 0;
  }
  return 1;
}

// File Line: 2591
// RVA: 0xC79450
void __fastcall hkMonitorStreamAnalyzer::getTimerLimits(
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList,
        hkMonitorStreamAnalyzer::ThreadDrawInput *input,
        hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos,
        float *maxFrameTime,
        hkArray<float,hkContainerHeapAllocator> *startTimes)
{
  int m_numFrames; // ebx
  int m_frameStart; // edi
  int m_size; // r11d
  int v8; // esi
  int v9; // eax
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v11; // r9
  hkMonitorStreamAnalyzer::ThreadDrawInput *v12; // r8
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v13; // r10
  int v14; // r13d
  hkArray<float,hkContainerHeapAllocator> *v15; // r14
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  __int64 v19; // rdx
  float *v20; // rdi
  __int64 v21; // rcx
  __int64 v22; // rax
  signed __int64 v23; // rbp
  __int64 v24; // r12
  __int64 v25; // rdx
  hkMonitorStreamFrameInfo *m_data; // rcx
  int v27; // ebx
  int v28; // eax
  int v29; // esi
  float v30; // xmm0_4
  signed __int64 v31; // rdi
  double v32; // xmm3_8
  hkMonitorStreamAnalyzer::Node **v33; // r9
  __int64 v34; // r9
  _QWORD *v35; // r10
  long double v36; // xmm4_8
  signed __int64 i; // rdi
  int v38; // eax
  double *v39; // r13
  hkResultEnum v40; // ecx
  double *v41; // r8
  signed __int64 v42; // r10
  int v43; // edi
  hkMonitorStreamAnalyzer::Node *v44; // r9
  __int64 v45; // rdx
  hkMonitorStreamAnalyzer::Node *v46; // rcx
  double m_absoluteStartTime; // xmm0_8
  __int64 v48; // rdx
  double *v49; // rax
  unsigned __int64 v50; // rdi
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  signed __int64 v56; // r10
  int v57; // edi
  hkMonitorStreamAnalyzer::Node *v58; // r8
  __int64 v59; // rdx
  hkMonitorStreamAnalyzer::Node *v60; // rcx
  float v61; // xmm2_4
  int v62; // edx
  int v63; // eax
  int v64; // eax
  float m_limitFrameTime; // xmm0_4
  float v66; // xmm0_4
  unsigned int v67; // ecx
  float v68; // xmm1_4
  float v69; // xmm0_4
  int v70; // [rsp+30h] [rbp-A8h]
  hkResult result; // [rsp+34h] [rbp-A4h] BYREF
  int v72; // [rsp+38h] [rbp-A0h]
  int v73; // [rsp+3Ch] [rbp-9Ch] BYREF
  int v74; // [rsp+40h] [rbp-98h]
  int v75; // [rsp+44h] [rbp-94h]
  double *v76; // [rsp+48h] [rbp-90h]
  __int64 v77; // [rsp+50h] [rbp-88h]
  long double maxSoFar; // [rsp+58h] [rbp-80h] BYREF
  __int64 v79; // [rsp+60h] [rbp-78h]

  m_numFrames = input->m_numFrames;
  m_frameStart = input->m_frameStart;
  m_size = nodeList->m_size;
  v8 = input->m_frameStart + m_numFrames;
  v9 = (*nodeList->m_data)->m_children.m_size;
  v11 = frameInfos;
  v12 = input;
  v13 = nodeList;
  v75 = m_size;
  v74 = v8;
  v14 = m_numFrames;
  v70 = m_numFrames;
  if ( v8 > v9 )
  {
    v8 = v9;
    v74 = v9;
    v14 = v9 - m_frameStart;
    v70 = v9 - m_frameStart;
  }
  if ( v14 > 0 )
  {
    v15 = startTimes;
    v16 = startTimes->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v16 < m_numFrames )
    {
      v17 = 2 * v16;
      v18 = m_numFrames;
      if ( m_numFrames < v17 )
        v18 = v17;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&startTimes->m_data, v18, 4);
      v12 = input;
      v13 = nodeList;
      m_size = v75;
      v11 = frameInfos;
    }
    v19 = startTimes->m_size;
    v20 = &startTimes->m_data[v19];
    v21 = m_numFrames - (int)v19;
    if ( m_numFrames - (int)v19 > 0 )
    {
      while ( v21 )
      {
        *v20++ = 0.0;
        --v21;
      }
    }
    startTimes->m_size = m_numFrames;
    *maxFrameTime = 0.0;
    v22 = v12->m_frameStart;
    v23 = m_size;
    v79 = v8;
    v72 = v22;
    v24 = v22;
    if ( v22 < v8 )
    {
      v25 = 40 * v22;
      v77 = 40 * v22;
      do
      {
        m_data = v11->m_data->m_data;
        v27 = v22 - v12->m_frameStart;
        v28 = *(unsigned int *)((char *)&m_data->m_absoluteTimeCounter.m_storage + v25);
        if ( v28 )
          v29 = *(int *)((char *)&m_data->m_indexOfTimer1 + v25);
        else
          v29 = *(int *)((char *)&m_data->m_indexOfTimer0 + v25);
        if ( v28 )
          v30 = *(float *)((char *)&m_data->m_timerFactor1 + v25);
        else
          v30 = *(float *)((char *)&m_data->m_timerFactor0 + v25);
        v31 = 0i64;
        maxSoFar = 0.0;
        v32 = v30 * 4294967295.0 * 0.5;
        if ( v23 > 0 )
        {
          v33 = v13->m_data;
          while ( !needsRebase(&(*v33)->m_children.m_data[v24]->m_children, v32, &maxSoFar) )
          {
            ++v31;
            v33 = (hkMonitorStreamAnalyzer::Node **)(v34 + 8);
            if ( v31 >= v23 )
              goto LABEL_26;
          }
          for ( i = 0i64; i < v23; ++i )
            rebase(
              (hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*v35 + 8 * i) + 96i64)
                                                                                              + 8 * v24)
                                                                                  + 96i64),
              v32,
              v36);
        }
LABEL_26:
        v38 = m_size;
        if ( m_size )
        {
          v73 = 8 * m_size;
          v39 = (double *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v73);
          v38 = v73 / 8;
        }
        else
        {
          v39 = 0i64;
        }
        v40 = 0x80000000;
        v76 = v39;
        if ( v38 )
          v40 = v38;
        result.m_enum = v40;
        if ( v23 > 0 )
        {
          v41 = v39;
          memset64(v39, 0x47EFFFFDC0000000ui64, v23);
          v42 = v23;
          do
          {
            v43 = 0;
            v44 = *(hkMonitorStreamAnalyzer::Node **)(*(_QWORD *)(*(_QWORD *)((char *)v41
                                                                            + (unsigned __int64)nodeList->m_data
                                                                            - (char *)v39)
                                                                + 96i64)
                                                    + 8 * v24);
            if ( v44->m_children.m_size > 0 )
            {
              v45 = 0i64;
              do
              {
                v46 = v44->m_children.m_data[v45];
                if ( v46->m_type.m_storage != 2 )
                {
                  m_absoluteStartTime = v46->m_absoluteStartTime;
                  if ( m_absoluteStartTime >= *v41 )
                    m_absoluteStartTime = *v41;
                  *v41 = m_absoluteStartTime;
                }
                ++v43;
                ++v45;
              }
              while ( v43 < v44->m_children.m_size );
            }
            ++v41;
            --v42;
          }
          while ( v42 );
          v15 = startTimes;
        }
        v48 = 0i64;
        v15->m_data[v27] = 3.40282e38;
        if ( v23 >= 4 )
        {
          v49 = v39 + 2;
          v50 = ((unsigned __int64)(v23 - 4) >> 2) + 1;
          v48 = 4 * v50;
          do
          {
            v51 = *(v49 - 2);
            if ( v51 >= v15->m_data[v27] )
              v51 = v15->m_data[v27];
            v15->m_data[v27] = v51;
            v52 = *(v49 - 1);
            if ( v52 >= v15->m_data[v27] )
              v52 = v15->m_data[v27];
            v15->m_data[v27] = v52;
            v53 = *v49;
            if ( v53 >= v15->m_data[v27] )
              v53 = v15->m_data[v27];
            v15->m_data[v27] = v53;
            v54 = v49[1];
            if ( v54 >= v15->m_data[v27] )
              v54 = v15->m_data[v27];
            v49 += 4;
            v15->m_data[v27] = v54;
            --v50;
          }
          while ( v50 );
        }
        for ( ; v48 < v23; v15->m_data[v27] = v55 )
        {
          v55 = v39[v48];
          if ( v55 >= v15->m_data[v27] )
            v55 = v15->m_data[v27];
          ++v48;
        }
        v56 = 0i64;
        if ( v23 > 0 )
        {
          do
          {
            v57 = 0;
            v58 = nodeList->m_data[v56]->m_children.m_data[v24];
            if ( v58->m_children.m_size > 0 )
            {
              v59 = 0i64;
              do
              {
                v60 = v58->m_children.m_data[v59];
                if ( v60->m_type.m_storage != 2 )
                {
                  v61 = v60->m_value[v29] + v60->m_absoluteStartTime - v15->m_data[v27];
                  if ( v61 <= *maxFrameTime )
                    v61 = *maxFrameTime;
                  *maxFrameTime = v61;
                }
                ++v57;
                ++v59;
              }
              while ( v57 < v58->m_children.m_size );
            }
            ++v56;
          }
          while ( v56 < v23 );
          v39 = v76;
        }
        if ( result.m_enum >= HK_SUCCESS )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v39, 8 * result.m_enum);
        v12 = input;
        v13 = nodeList;
        m_size = v75;
        v11 = frameInfos;
        LODWORD(v22) = v72 + 1;
        v25 = v77 + 40;
        ++v24;
        ++v72;
        v77 += 40i64;
      }
      while ( v24 < v79 );
      v8 = v74;
      v14 = v70;
    }
    if ( v12->m_limitStartTime > 0.0 )
    {
      v62 = v12->m_frameStart;
      if ( v12->m_frameStart < v8 )
      {
        if ( v8 - v62 >= 4 )
        {
          do
          {
            v15->m_data[v62 - v12->m_frameStart] = v12->m_limitStartTime + v15->m_data[v62 - v12->m_frameStart];
            v15->m_data[v62 - v12->m_frameStart + 1] = v12->m_limitStartTime + v15->m_data[v62 - v12->m_frameStart + 1];
            v15->m_data[v62 - v12->m_frameStart + 2] = v12->m_limitStartTime + v15->m_data[v62 - v12->m_frameStart + 2];
            v63 = v62;
            v62 += 4;
            v15->m_data[v63 - v12->m_frameStart + 3] = v12->m_limitStartTime + v15->m_data[v63 - v12->m_frameStart + 3];
          }
          while ( v62 < v8 - 3 );
        }
        for ( ;
              v62 < v8;
              v15->m_data[v64 - v12->m_frameStart] = v12->m_limitStartTime + v15->m_data[v64 - v12->m_frameStart] )
        {
          v64 = v62++;
        }
      }
    }
    m_limitFrameTime = v12->m_limitFrameTime;
    if ( m_limitFrameTime <= 0.0 )
    {
      if ( v14 == 1 )
      {
        v66 = hkMonitorStreamAnalyzer::g_lastFrameTime * 0.25;
        v67 = ((((((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 4) | ((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 8) | ((((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 4) | ((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001);
        if ( (float)(hkMonitorStreamAnalyzer::g_lastFrameTime * 0.25) >= (float)((float)((float)(int)((v67 | HIWORD(v67)) + 1)
                                                                                       * 1000.0)
                                                                               - hkMonitorStreamAnalyzer::g_lastFrameTime) )
          v66 = (float)((float)(int)((v67 | ((((((((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 4) | ((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 8) | ((((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 4) | ((((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 2) | ((unsigned int)(int)(float)(*maxFrameTime * 0.001) >> 1) | (int)(float)(*maxFrameTime * 0.001)) >> 16))
                                   + 1)
                      * 1000.0)
              - hkMonitorStreamAnalyzer::g_lastFrameTime;
        v68 = FLOAT_16666_0;
        v69 = (float)(v66 * 0.050000001) + hkMonitorStreamAnalyzer::g_lastFrameTime;
        *maxFrameTime = v69;
        if ( v69 >= 16666.0 )
          v68 = v69;
        *maxFrameTime = v68;
        hkMonitorStreamAnalyzer::g_lastFrameTime = v68;
      }
    }
    else
    {
      *maxFrameTime = m_limitFrameTime;
    }
  }
}

// File Line: 2718
// RVA: 0xC78D10
void __fastcall hkMonitorStreamAnalyzer::writeStatisticsDetailsToTexture(
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList,
        hkMonitorStreamAnalyzer::ThreadDrawInput *input,
        hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos,
        int **texture,
        int *height,
        hkMonitorStreamAnalyzer::SampleInfo *sampleInfo)
{
  __int64 m_size; // r15
  int m_numFrames; // r8d
  int v11; // r14d
  int v12; // r12d
  int m_outputPixelWidth; // eax
  int v14; // ebp
  int v15; // ebx
  hkMemoryAllocator **Value; // rax
  float frameTime; // xmm6_4
  IAmdDxExt *mExtension_low; // rax
  __int64 v19; // rcx
  _QWORD *v20; // rbx
  signed int mHeight; // r11d
  __int64 m_frameStart; // r13
  __int64 v23; // r12
  __int64 v24; // rbx
  __int64 v25; // r15
  __int64 v26; // r9
  float v27; // xmm1_4
  int v28; // r15d
  int v29; // r10d
  int v30; // eax
  __int64 i; // rdx
  __int64 v32; // rcx
  int v33; // r10d
  int v34; // r14d
  __int64 v35; // r8
  __int64 j; // rdx
  __int64 v37; // rcx
  signed int v38; // edx
  __int64 v39; // rcx
  _QWORD *v40; // rax
  signed int v41; // eax
  signed int v42; // edx
  __int64 v43; // rcx
  _QWORD *v44; // rax
  int maxX; // [rsp+60h] [rbp-98h]
  int v46; // [rsp+64h] [rbp-94h]
  float maxFrameTime[2]; // [rsp+68h] [rbp-90h] BYREF
  AMD_HD3D unknownColorMap; // [rsp+70h] [rbp-88h] BYREF
  int v49; // [rsp+90h] [rbp-68h]
  hkArray<float,hkContainerHeapAllocator> startTimes; // [rsp+98h] [rbp-60h] BYREF

  m_size = nodeList->m_size;
  if ( (int)m_size >= 1 )
  {
    maxFrameTime[0] = FLOAT_N1_0;
    startTimes.m_data = 0i64;
    startTimes.m_size = 0;
    startTimes.m_capacityAndFlags = 0x80000000;
    hkMonitorStreamAnalyzer::getTimerLimits(nodeList, input, frameInfos, maxFrameTime, &startTimes);
    m_numFrames = input->m_numFrames;
    v11 = 0;
    if ( m_numFrames > frameInfos->m_data->m_size - input->m_frameStart )
      m_numFrames = frameInfos->m_data->m_size - input->m_frameStart;
    v46 = m_numFrames;
    LODWORD(unknownColorMap.mExtension) = input->m_frameStart + m_numFrames;
    LODWORD(unknownColorMap.mStereo) = input->m_heightPerThread + input->m_gapBetweenThreads;
    v12 = m_numFrames * (input->m_gapBetweenFrames + m_size * LODWORD(unknownColorMap.mStereo));
    if ( m_numFrames > 1 )
      v11 = 32;
    m_outputPixelWidth = input->m_outputPixelWidth;
    v49 = m_numFrames * (input->m_gapBetweenFrames + m_size * LODWORD(unknownColorMap.mStereo));
    v14 = v12;
    v15 = v12 * (m_outputPixelWidth + 1);
    maxX = m_outputPixelWidth - v11;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 *= 4;
    *texture = (int *)hkMemoryRouter::easyAlloc(Value[11], v15);
    *height = v12;
    hkString::memSet(*texture, 0, v15);
    frameTime = maxFrameTime[0];
    if ( sampleInfo )
      sampleInfo->m_maxSampleTime = maxFrameTime[0];
    mExtension_low = (IAmdDxExt *)SLODWORD(unknownColorMap.mExtension);
    v19 = v46;
    v20 = 0i64;
    mHeight = -1;
    unknownColorMap.mWidth = 0;
    m_frameStart = input->m_frameStart;
    *(_QWORD *)&unknownColorMap.mEnableStereo = 0i64;
    unknownColorMap.mHeight = -1;
    *(_QWORD *)maxFrameTime = m_size;
    v23 = m_frameStart;
    unknownColorMap.mExtension = mExtension_low;
    if ( m_frameStart < (__int64)mExtension_low )
    {
      do
      {
        v14 -= input->m_gapBetweenFrames;
        if ( v19 > 1 )
        {
          drawNumber(
            m_frameStart,
            v14,
            input->m_outputPixelWidth,
            &(*texture)[input->m_outputPixelWidth * (v14 - LODWORD(unknownColorMap.mStereo))]);
          mExtension_low = unknownColorMap.mExtension;
        }
        v24 = 0i64;
        if ( m_size > 0 )
        {
          v25 = 0i64;
          do
          {
            v14 -= LODWORD(unknownColorMap.mStereo);
            drawStatistics(
              frameInfos->m_data[v25++].m_data,
              m_frameStart,
              &nodeList->m_data[v24++]->m_children,
              &(*texture)[v11 + v14 * input->m_outputPixelWidth],
              input->m_heightPerThread,
              input->m_colorTable,
              input->m_outputPixelWidth,
              maxX,
              frameTime,
              startTimes.m_data[v23 - input->m_frameStart],
              (hkPointerMap<char const *,unsigned int,hkContainerHeapAllocator> *)&unknownColorMap);
          }
          while ( v24 < *(__int64 *)maxFrameTime );
          m_size = *(_QWORD *)maxFrameTime;
          mExtension_low = unknownColorMap.mExtension;
        }
        v19 = v46;
        ++v23;
        LODWORD(m_frameStart) = m_frameStart + 1;
      }
      while ( v23 < (__int64)mExtension_low );
      mHeight = unknownColorMap.mHeight;
      v20 = *(_QWORD **)&unknownColorMap.mEnableStereo;
    }
    v26 = v49;
    v27 = (float)(1000 * maxX) * (float)(1.0 / frameTime);
    v28 = (int)(float)((float)((float)((int)input->m_limitStartTime % 1000) * 0.001) * v27);
    if ( v27 > 5.0 )
    {
      v29 = 0;
      v30 = v11 - v28;
      if ( v11 - v28 < input->m_outputPixelWidth )
      {
        do
        {
          if ( v30 >= 0 )
          {
            for ( i = 0i64; i < v26; (*texture)[v30 + v32] = -16776961 )
            {
              v32 = i * input->m_outputPixelWidth;
              ++i;
            }
          }
          v30 = v11 + (int)(float)((float)++v29 * v27) - v28;
        }
        while ( v30 < input->m_outputPixelWidth );
        mHeight = unknownColorMap.mHeight;
        v20 = *(_QWORD **)&unknownColorMap.mEnableStereo;
      }
    }
    v33 = (int)(float)((float)(16666 * maxX) * (float)(1.0 / frameTime));
    if ( v33 > 0 )
    {
      v34 = v11 - v28;
      v35 = v34;
      if ( v34 < input->m_outputPixelWidth )
      {
        do
        {
          if ( v35 >= 0 )
          {
            for ( j = 0i64; j < v26; (*texture)[v37 + 1] = -16711936 )
            {
              (*texture)[v35 + j * input->m_outputPixelWidth] = -16711936;
              v37 = v35 + j * input->m_outputPixelWidth;
              ++j;
            }
          }
          v34 += v33;
          v35 += v33;
        }
        while ( v34 < input->m_outputPixelWidth );
        mHeight = unknownColorMap.mHeight;
        v20 = *(_QWORD **)&unknownColorMap.mEnableStereo;
      }
    }
    if ( input->m_warnAboutMissingTimers.m_bool )
    {
      v38 = 0;
      v39 = 0i64;
      if ( mHeight >= 0 )
      {
        v40 = v20;
        do
        {
          if ( *v40 != -1i64 )
            break;
          ++v39;
          ++v38;
          v40 += 2;
        }
        while ( v39 <= mHeight );
      }
      v41 = v38;
      if ( v38 <= mHeight )
      {
        do
        {
          v42 = v41 + 1;
          v43 = v41 + 1;
          if ( v43 <= mHeight )
          {
            v44 = &v20[2 * v42];
            do
            {
              if ( *v44 != -1i64 )
                break;
              ++v43;
              ++v42;
              v44 += 2;
            }
            while ( v43 <= mHeight );
          }
          v41 = v42;
        }
        while ( v42 <= mHeight );
      }
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&unknownColorMap,
      &hkContainerHeapAllocator::s_alloc);
    _(&unknownColorMap);
    startTimes.m_size = 0;
    if ( startTimes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        startTimes.m_data,
        4 * startTimes.m_capacityAndFlags);
  }
}

// File Line: 2833
// RVA: 0xC79200
void __fastcall hkMonitorStreamAnalyzer::writeStatisticsDetailsToTga(
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList,
        hkMonitorStreamAnalyzer::ThreadDrawInput *input,
        hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos,
        hkOstream *outStream,
        hkMonitorStreamAnalyzer::SampleInfo *sampleInfo)
{
  hkMemoryAllocator **Value; // rax
  int height; // [rsp+30h] [rbp-18h] BYREF
  int *texture; // [rsp+38h] [rbp-10h] BYREF

  texture = 0i64;
  height = 0;
  hkMonitorStreamAnalyzer::writeStatisticsDetailsToTexture(nodeList, input, frameInfos, &texture, &height, sampleInfo);
  if ( texture )
  {
    saveToTGA(texture, outStream, input->m_outputPixelWidth, height);
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(Value[11], texture);
  }
}

// File Line: 2847
// RVA: 0xC76BE0
void __fastcall hkMonitorStreamAnalyzer::drawThreadsToTga(
        hkMonitorStreamAnalyzer *this,
        hkMonitorStreamAnalyzer::ThreadDrawInput *input,
        hkOstream *outStream)
{
  __int64 m_size; // rbx
  int v7; // r9d
  int v8; // ebp
  __int64 v9; // rdi
  __int64 v10; // rsi
  hkMonitorStreamAnalyzer::Node **v11; // rbx
  hkMonitorStreamAnalyzer::Node *StatisticsTreeForMultipleFrames; // rax
  __int64 i; // rbx
  hkMonitorStreamAnalyzer::Node *v14; // rdi
  _QWORD **Value; // rax
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> nodeList; // [rsp+30h] [rbp-68h] BYREF
  __int64 v17; // [rsp+40h] [rbp-58h] BYREF
  hkResult v18; // [rsp+A0h] [rbp+8h] BYREF

  m_size = this->m_frameInfos.m_size;
  nodeList.m_data = (hkMonitorStreamAnalyzer::Node **)&v17;
  nodeList.m_size = 0;
  nodeList.m_capacityAndFlags = -2147483642;
  if ( (int)m_size > 6 )
  {
    v7 = m_size;
    if ( (int)m_size < 12 )
      v7 = 12;
    hkArrayUtil::_reserve(&v18, &hkContainerHeapAllocator::s_alloc, (const void **)&nodeList.m_data, v7, 8);
  }
  v8 = 0;
  v9 = 0i64;
  nodeList.m_size = m_size;
  v10 = m_size;
  if ( (int)m_size > 0 )
  {
    do
    {
      v11 = &nodeList.m_data[v9];
      StatisticsTreeForMultipleFrames = hkMonitorStreamAnalyzer::makeStatisticsTreeForMultipleFrames(this, v8, 0);
      ++v9;
      ++v8;
      *v11 = StatisticsTreeForMultipleFrames;
    }
    while ( v9 < v10 );
  }
  hkMonitorStreamAnalyzer::writeStatisticsDetailsToTga(&nodeList, input, &this->m_frameInfos, outStream, 0i64);
  for ( i = 0i64; i < v10; ++i )
  {
    v14 = nodeList.m_data[i];
    if ( v14 )
    {
      hkMonitorStreamAnalyzer::Node::~Node(nodeList.m_data[i]);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzer::Node *, __int64))(*Value[11] + 16i64))(
        Value[11],
        v14,
        144i64);
    }
  }
  nodeList.m_size = 0;
  if ( nodeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      nodeList.m_data,
      8 * nodeList.m_capacityAndFlags);
}

// File Line: 2869
// RVA: 0xC79290
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::reverseLookupNodeAtTgaSample(
        int x,
        int y,
        hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList,
        hkMonitorStreamAnalyzer::ThreadDrawInput *input,
        hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos)
{
  int m_size; // eax
  int m_numFrames; // r9d
  int v11; // ebp
  int m_outputPixelWidth; // r14d
  int v13; // r14d
  int v14; // r8d
  int v15; // ecx
  int v16; // eax
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v17; // rbx
  int v18; // eax
  __int64 v19; // rsi
  __int64 v20; // rdi
  hkMonitorStreamAnalyzer::Node *NodeSampledAtTick; // rbx
  hkArray<float,hkContainerHeapAllocator> startTimes; // [rsp+40h] [rbp-38h] BYREF
  float maxFrameTime; // [rsp+90h] [rbp+18h] BYREF

  m_size = nodeList->m_size;
  m_numFrames = input->m_numFrames;
  if ( m_size < 1 )
    return 0i64;
  v11 = 0;
  if ( m_numFrames > 1 )
    v11 = 32;
  if ( x < v11 )
    return 0i64;
  m_outputPixelWidth = input->m_outputPixelWidth;
  if ( x >= m_outputPixelWidth )
    return 0i64;
  v13 = m_outputPixelWidth - v11;
  v14 = input->m_heightPerThread + input->m_gapBetweenThreads;
  v15 = input->m_gapBetweenFrames + m_size * v14;
  v16 = m_numFrames * v15;
  if ( y < 0 || y >= v16 )
    return 0i64;
  v17 = frameInfos;
  v18 = v16 - y - 1;
  maxFrameTime = FLOAT_N1_0;
  startTimes.m_data = 0i64;
  startTimes.m_size = 0;
  startTimes.m_capacityAndFlags = 0x80000000;
  v19 = v18 / v15;
  v20 = v18 % v15 / v14;
  hkMonitorStreamAnalyzer::getTimerLimits(nodeList, input, frameInfos, &maxFrameTime, &startTimes);
  NodeSampledAtTick = getNodeSampledAtTick(
                        v17->m_data[v20].m_data,
                        v19,
                        x - v11,
                        &nodeList->m_data[v20]->m_children,
                        v13,
                        maxFrameTime,
                        startTimes.m_data[v19]);
  startTimes.m_size = 0;
  if ( startTimes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      startTimes.m_data,
      4 * startTimes.m_capacityAndFlags);
  return NodeSampledAtTick;
}

// File Line: 2928
// RVA: 0xC79B10
void __fastcall hkMonitorStreamAnalyzer::gatherRawStreamTimerValues(
        hkMonitorStream::TimerCommand *frameStart,
        hkMonitorStream::TimerCommand *frameEnd,
        hkMonitorStreamFrameInfo *frameInfo,
        const char **timerNames,
        int numTimers,
        float *valuesOut)
{
  char *v8; // r13
  int v9; // eax
  __int64 v10; // rbp
  _DWORD *v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // r14
  char *v14; // rsi
  const char *v15; // rbx
  hkMonitorStreamAnalyzer::Node *v16; // rax
  int v17; // eax
  __int64 v18; // r8
  unsigned int v19; // r9d
  const char *v20; // rsi
  const char *m_commandAndMonitor; // r15
  char *v22; // rbx
  __int64 v23; // rsi
  _DWORD *v24; // rbx
  hkMonitorStreamAnalyzer::Node *v25; // rsi
  __int64 v26; // r14
  hkMonitorStream::TimerCommand *v27; // r8
  char *v28; // rbx
  __int64 v29; // rsi
  __int64 v30; // r10
  float *v31; // r9
  float *v32; // rcx
  char *v33; // rdx
  unsigned __int64 v34; // r8
  int v35; // eax
  float *v36; // rcx
  float v37; // eax
  int v38; // ebx
  hkMonitorStreamAnalyzer::Node *v39; // rdi
  char *v40; // rbx
  hkMonitorStreamAnalyzer::Node *v41; // rsi
  __int64 v42; // r14
  int *v43; // rbx
  hkMonitorStreamAnalyzer::Node *v44; // rsi
  __int64 v45; // r14
  hkMonitorStream::TimerCommand *v46; // r8
  __int64 v47; // rsi
  char *v48; // rbx
  __int64 v49; // r14
  int v50; // [rsp+20h] [rbp-E8h] BYREF
  __int64 v51; // [rsp+28h] [rbp-E0h]
  int v52; // [rsp+30h] [rbp-D8h]
  hkMonitorStreamAnalyzer::Node v53; // [rsp+38h] [rbp-D0h] BYREF

  if ( numTimers > 0 )
  {
    v50 = 168 * numTimers;
    v8 = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v50);
    v51 = numTimers;
    v9 = 0x80000000;
    if ( v50 / 168 )
      v9 = v50 / 168;
    v10 = 0i64;
    v52 = v9;
    v11 = v8 + 108;
    v12 = numTimers;
    do
    {
      if ( v11 != (_DWORD *)108 )
      {
        *(_QWORD *)(v11 - 3) = 0i64;
        *(v11 - 1) = 0;
        *v11 = 0x80000000;
      }
      v11 += 42;
      --v12;
    }
    while ( v12 );
    v13 = 0i64;
    v14 = v8 + 152;
    do
    {
      v15 = timerNames[v13];
      hkMonitorStreamAnalyzer::Node::Node(&v53, 0i64, v15, 0);
      hkMonitorStreamAnalyzer::Node::operator=((hkMonitorStreamAnalyzer::Node *)(v14 - 152), v16);
      hkMonitorStreamAnalyzer::Node::~Node(&v53);
      v17 = hkString::strLen(v15);
      ++v13;
      *(_QWORD *)v14 = 0i64;
      *((_DWORD *)v14 + 2) = 0;
      v14 += 168;
      *((_DWORD *)v14 - 44) = v17 + 1;
    }
    while ( v13 < numTimers );
    v18 = v51;
    v19 = numTimers;
    v20 = (const char *)frameEnd;
    if ( frameStart < frameEnd )
    {
      while ( 1 )
      {
        m_commandAndMonitor = frameStart->m_commandAndMonitor;
        if ( frameStart->m_commandAndMonitor >= (const char *)0x14 )
          break;
        frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 4);
LABEL_42:
        v18 = v51;
        v19 = numTimers;
        if ( frameStart >= (hkMonitorStream::TimerCommand *)v20 )
          goto LABEL_43;
      }
      switch ( *m_commandAndMonitor )
      {
        case E:
          v24 = v8 + 160;
          v25 = (hkMonitorStreamAnalyzer::Node *)v8;
          v26 = v19;
          do
          {
            v27 = (hkMonitorStream::TimerCommand *)*((_QWORD *)v24 - 1);
            if ( v27 )
            {
              if ( *v24 )
              {
                --*v24;
              }
              else
              {
                hkMonitorStreamAnalyzer::Node::setTimers(v25, frameInfo, v27, frameStart);
                *((_QWORD *)v24 - 1) = 0i64;
              }
            }
            v25 = (hkMonitorStreamAnalyzer::Node *)((char *)v25 + 168);
            v24 += 42;
            --v26;
          }
          while ( v26 );
          v20 = (const char *)frameEnd;
          ++frameStart;
          goto LABEL_42;
        case L:
          if ( v18 <= 0 )
            goto $LN6_186;
          v28 = v8 + 128;
          v29 = v18;
          break;
        case M:
          if ( v18 <= 0 )
            goto LABEL_22;
          v47 = 0i64;
          v48 = v8 + 128;
          v49 = v18;
          do
          {
            if ( !hkString::memCmp(m_commandAndMonitor + 2, *(const void **)v48, *((_DWORD *)v48 + 4)) )
            {
              *((_DWORD *)v48 + 3) = 2;
              *(_DWORD *)&v8[4 * v47 + 4 * frameInfo->m_indexOfTimer0] = frameStart->m_time0;
              ++*(_DWORD *)&v8[4 * v47 + 48 + 4 * frameInfo->m_indexOfTimer0];
            }
            v48 += 168;
            v47 += 42i64;
            --v49;
          }
          while ( v49 );
          v20 = (const char *)frameEnd;
          ++frameStart;
          goto LABEL_42;
        case N:
        case P:
        case p:
          frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 8);
          goto LABEL_42;
        case O:
        case m:
$LN6_186:
          frameStart = (hkMonitorStream::TimerCommand *)((char *)frameStart + 24);
          goto LABEL_42;
        case S:
          v40 = v8 + 152;
          v41 = (hkMonitorStreamAnalyzer::Node *)v8;
          v42 = v19;
          do
          {
            if ( *(_QWORD *)v40 )
            {
              if ( !*((_DWORD *)v40 + 2) )
              {
                hkMonitorStreamAnalyzer::Node::setTimers(
                  v41,
                  frameInfo,
                  *(hkMonitorStream::TimerCommand **)v40,
                  frameStart);
                *(_QWORD *)v40 = 0i64;
              }
            }
            else if ( !hkString::memCmp(m_commandAndMonitor + 2, *((const void **)v40 - 3), *((_DWORD *)v40 - 2)) )
            {
              *(_QWORD *)v40 = frameStart;
              *((_DWORD *)v40 + 2) = 0;
            }
            v41 = (hkMonitorStreamAnalyzer::Node *)((char *)v41 + 168);
            v40 += 168;
            --v42;
          }
          while ( v42 );
          v20 = (const char *)frameEnd;
          ++frameStart;
          goto LABEL_42;
        case T:
          if ( v18 > 0 )
          {
            v22 = v8 + 152;
            v23 = v18;
            do
            {
              if ( *(_QWORD *)v22 )
              {
                ++*((_DWORD *)v22 + 2);
              }
              else if ( !hkString::memCmp(m_commandAndMonitor + 2, *((const void **)v22 - 3), *((_DWORD *)v22 - 2)) )
              {
                *(_QWORD *)v22 = frameStart;
                *((_DWORD *)v22 + 2) = 0;
              }
              v22 += 168;
              --v23;
            }
            while ( v23 );
            v20 = (const char *)frameEnd;
          }
LABEL_22:
          ++frameStart;
          goto LABEL_42;
        case l:
          v43 = (int *)(v8 + 160);
          v44 = (hkMonitorStreamAnalyzer::Node *)v8;
          v45 = v19;
          do
          {
            v46 = (hkMonitorStream::TimerCommand *)*((_QWORD *)v43 - 1);
            if ( v46 )
            {
              if ( *v43 <= 1 )
              {
                hkMonitorStreamAnalyzer::Node::setTimers(v44, frameInfo, v46, frameStart);
                *((_QWORD *)v43 - 1) = 0i64;
              }
              *v43 -= 2;
            }
            v44 = (hkMonitorStreamAnalyzer::Node *)((char *)v44 + 168);
            v43 += 42;
            --v45;
          }
          while ( v45 );
          v20 = (const char *)frameEnd;
          ++frameStart;
          goto LABEL_42;
        default:
          goto LABEL_42;
      }
      while ( 1 )
      {
        if ( *((_QWORD *)v28 + 3) )
        {
          *((_DWORD *)v28 + 8) += 2;
        }
        else
        {
          if ( !hkString::memCmp(m_commandAndMonitor + 2, *(const void **)v28, *((_DWORD *)v28 + 4)) )
          {
            *((_DWORD *)v28 + 8) = 1;
LABEL_38:
            *((_QWORD *)v28 + 3) = frameStart;
            goto LABEL_39;
          }
          if ( !hkString::memCmp(frameStart[1].m_commandAndMonitor + 2, *(const void **)v28, *((_DWORD *)v28 + 4)) )
          {
            *((_DWORD *)v28 + 8) = 0;
            goto LABEL_38;
          }
        }
LABEL_39:
        v28 += 168;
        if ( !--v29 )
        {
          v20 = (const char *)frameEnd;
          goto $LN6_186;
        }
      }
    }
LABEL_43:
    v30 = v51;
    v31 = valuesOut;
    if ( v51 >= 4 )
    {
      v32 = valuesOut + 2;
      v33 = v8 + 336;
      v34 = ((unsigned __int64)(v51 - 4) >> 2) + 1;
      v10 = 4 * v34;
      do
      {
        v35 = *((_DWORD *)v33 - 84);
        v32 += 4;
        v33 += 672;
        *((_DWORD *)v32 - 6) = v35;
        *(v32 - 5) = *((float *)v33 - 210);
        *(v32 - 4) = *((float *)v33 - 168);
        *(v32 - 3) = *((float *)v33 - 126);
        --v34;
      }
      while ( v34 );
    }
    if ( v10 < v30 )
    {
      v36 = (float *)&v8[168 * v10];
      do
      {
        v37 = *v36;
        ++v10;
        v36 += 42;
        valuesOut[v10 - 1] = v37;
      }
      while ( v10 < v30 );
    }
    v38 = numTimers - 1;
    if ( numTimers - 1 >= 0 )
    {
      v39 = (hkMonitorStreamAnalyzer::Node *)&v8[168 * v38];
      do
      {
        hkMonitorStreamAnalyzer::Node::~Node(v39);
        v39 = (hkMonitorStreamAnalyzer::Node *)((char *)v39 - 168);
        --v38;
      }
      while ( v38 >= 0 );
    }
    if ( v52 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, float *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v8,
        168 * (v52 & 0x3FFFFFFFu),
        v31);
  }
}

