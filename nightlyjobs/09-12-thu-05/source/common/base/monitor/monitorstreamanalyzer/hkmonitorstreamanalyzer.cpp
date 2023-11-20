// File Line: 23
// RVA: 0xC756E0
void __fastcall hkMonitorStreamStringMap::hkMonitorStreamStringMap(hkMonitorStreamStringMap *this)
{
  this->m_map.m_capacityAndFlags = 2147483648;
  this->m_map.m_data = 0i64;
  this->m_map.m_size = 0;
}

// File Line: 27
// RVA: 0xC75700
void __fastcall hkMonitorStreamStringMap::hkMonitorStreamStringMap(hkMonitorStreamStringMap *this, hkFinishLoadedObjectFlag f)
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
void __fastcall hkMonitorStreamStringMap::StringMap::StringMap(hkMonitorStreamStringMap::StringMap *this, hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_string, f);
}

// File Line: 43
// RVA: 0xC77870
void __fastcall hkMonitorStreamAnalyzer::Node::Node(hkMonitorStreamAnalyzer::Node *this, hkMonitorStreamAnalyzer::Node *parent, const char *name, hkMonitorStreamAnalyzer::Node::NodeType type)
{
  hkMonitorStreamAnalyzer::Node *v4; // rbx
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *v5; // rdi
  signed __int64 v6; // rax

  this->m_children.m_capacityAndFlags = 2147483648;
  v4 = this;
  this->m_children.m_data = 0i64;
  this->m_children.m_size = 0;
  this->m_parent = parent;
  this->m_name = name;
  this->m_userFlags = 0;
  this->m_type.m_storage = type;
  if ( parent )
  {
    v5 = &parent->m_children;
    if ( parent->m_children.m_size == (parent->m_children.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &parent->m_children, 8);
    v5->m_data[v5->m_size++] = v4;
  }
  v6 = 0i64;
  do
  {
    v4->m_value[v6] = 0.0;
    v4->m_count[v6++] = 0;
  }
  while ( v6 < 12 );
  v4->m_absoluteStartTime = 0.0;
}

// File Line: 56
// RVA: 0xC779E0
void __fastcall hkMonitorStreamAnalyzer::Node::~Node(hkMonitorStreamAnalyzer::Node *this)
{
  __int64 v1; // rsi
  hkMonitorStreamAnalyzer::Node *v2; // rbx
  int v3; // edi
  hkMonitorStreamAnalyzer::Node **v4; // rax
  __int64 v5; // rbp
  _QWORD **v6; // rax
  int v7; // er8

  v1 = 0i64;
  v2 = this;
  v3 = 0;
  if ( this->m_children.m_size > 0 )
  {
    do
    {
      v4 = v2->m_children.m_data;
      v5 = *(__int64 *)((char *)v4 + v1);
      if ( v5 )
      {
        hkMonitorStreamAnalyzer::Node::~Node(*(hkMonitorStreamAnalyzer::Node **)((char *)v4 + v1));
        v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v6[11] + 16i64))(v6[11], v5, 144i64);
      }
      ++v3;
      v1 += 8i64;
    }
    while ( v3 < v2->m_children.m_size );
    LODWORD(v1) = 0;
  }
  v7 = v2->m_children.m_capacityAndFlags;
  v2->m_children.m_size = v1;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_children.m_data,
      8 * v7);
  v2->m_children.m_capacityAndFlags = 2147483648;
  v2->m_children.m_data = 0i64;
}

// File Line: 65
// RVA: 0xC764C0
char *__fastcall hkMonitorStreamAnalyzer::getStreamBegin(hkMonitorStreamAnalyzer *this)
{
  char *result; // rax

  if ( this->m_data.m_size )
    result = this->m_data.m_data;
  else
    result = 0i64;
  return result;
}

// File Line: 84
// RVA: 0xC760A0
void __fastcall hkMonitorStreamAnalyzer::hkMonitorStreamAnalyzer(hkMonitorStreamAnalyzer *this, int memorySize, int numThreads, int numSpus)
{
  int v4; // esi
  int v5; // edi
  int v6; // eax
  hkMonitorStreamAnalyzer *v7; // rbx
  int v8; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  this->m_frameInfos.m_capacityAndFlags = 2147483648;
  this->m_frameInfos.m_data = 0i64;
  this->m_frameInfos.m_size = 0;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 2147483648;
  v4 = numThreads;
  hkMonitorStreamAnalyzer::g_lastFrameTime = FLOAT_16666_6;
  v5 = numSpus;
  v6 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = this;
  if ( v6 < memorySize )
  {
    v8 = 2 * v6;
    if ( memorySize < v8 )
      memorySize = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr,
      &this->m_data,
      memorySize,
      1);
  }
  v7->m_nodeIdForFrameOverview = "Physics 2012";
  hkMonitorStreamAnalyzer::resetNumThreads(v7, v4, v5);
}

// File Line: 93
// RVA: 0xC762A0
void __fastcall hkMonitorStreamAnalyzer::resetNumThreads(hkMonitorStreamAnalyzer *this, int numThreads, int numSpus)
{
  int v3; // er15
  int v4; // eax
  int v5; // er12
  int v6; // er13
  hkMonitorStreamAnalyzer *v7; // r14
  int v8; // eax
  int v9; // er9
  int v10; // eax
  __int64 v11; // rbp
  signed __int64 v12; // rsi
  int v13; // ebx
  hkStringPtr *v14; // rdi
  int v15; // eax
  signed __int64 v16; // rax
  int v17; // ecx
  signed __int64 v18; // rdx
  __int64 v19; // rax
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v20; // rdx
  hkResult result; // [rsp+68h] [rbp+10h]

  v3 = numSpus + numThreads;
  v4 = this->m_frameInfos.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = numSpus;
  v6 = numThreads;
  v7 = this;
  if ( v4 < numSpus + numThreads )
  {
    v8 = 2 * v4;
    v9 = numSpus + numThreads;
    if ( v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v9, 16);
  }
  v10 = v7->m_frameInfos.m_size - v3 - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = (signed __int64)&v7->m_frameInfos.m_data[v3 + v10];
    do
    {
      v13 = *(_DWORD *)(v12 + 8) - 1;
      if ( v13 >= 0 )
      {
        v14 = (hkStringPtr *)(*(_QWORD *)v12 + 40i64 * v13);
        do
        {
          hkStringPtr::~hkStringPtr(v14);
          v14 -= 5;
          --v13;
        }
        while ( v13 >= 0 );
      }
      v15 = *(_DWORD *)(v12 + 12);
      *(_DWORD *)(v12 + 8) = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)v12,
          40 * (v15 & 0x3FFFFFFF));
      *(_QWORD *)v12 = 0i64;
      *(_DWORD *)(v12 + 12) = 2147483648;
      v12 -= 16i64;
      --v11;
    }
    while ( v11 >= 0 );
  }
  v16 = v7->m_frameInfos.m_size;
  v17 = v3 - v16;
  v18 = v16;
  v19 = v3 - (signed int)v16;
  v20 = &v7->m_frameInfos.m_data[v18];
  if ( v17 > 0 )
  {
    do
    {
      if ( v20 )
      {
        v20->m_data = 0i64;
        v20->m_size = 0;
        v20->m_capacityAndFlags = 2147483648;
      }
      ++v20;
      --v19;
    }
    while ( v19 );
  }
  v7->m_frameInfos.m_size = v3;
  v7->m_numSpus = v5;
  v7->m_numThreads = v6;
  hkMonitorStreamAnalyzer::reset(v7);
}

// File Line: 102
// RVA: 0xC76410
void __fastcall hkMonitorStreamAnalyzer::reset(hkMonitorStreamAnalyzer *this)
{
  hkMonitorStreamAnalyzer *v1; // rbp
  int v2; // esi
  __int64 v3; // r14
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v4; // r15
  int v5; // ebx
  hkStringPtr *v6; // rdi

  v1 = this;
  this->m_data.m_size = 0;
  v2 = 0;
  if ( this->m_frameInfos.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->m_frameInfos.m_data;
      v5 = v1->m_frameInfos.m_data[v3].m_size - 1;
      if ( v5 >= 0 )
      {
        v6 = &v1->m_frameInfos.m_data[v3].m_data[v5].m_heading;
        do
        {
          hkStringPtr::~hkStringPtr(v6);
          v6 -= 5;
          --v5;
        }
        while ( v5 >= 0 );
      }
      v4[v3].m_size = 0;
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_frameInfos.m_size );
  }
}

// File Line: 122
// RVA: 0xC75770
void __fastcall hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo(hkMonitorStreamFrameInfo *this)
{
  hkMonitorStreamFrameInfo *v1; // rbx

  v1 = this;
  hkStringPtr::hkStringPtr(&this->m_heading, "Unknown Heading");
  *(_QWORD *)&v1->m_indexOfTimer1 = 1i64;
  v1->m_indexOfTimer0 = 0;
  *(_QWORD *)&v1->m_frameStreamStart = 0i64;
  v1->m_timerFactor0 = 1.0;
  *(_QWORD *)&v1->m_timerFactor1 = 1065353216i64;
}

// File Line: 187
// RVA: 0xC78A40
hkMonitorStreamAnalyzer::applyStringMap

// File Line: 321
// RVA: 0xC78940
hkMonitorStreamAnalyzer::extractStringMap

// File Line: 392
// RVA: 0xC76150
hkBool *__fastcall hkMonitorStreamAnalyzer::captureFrameDetails(hkMonitorStreamAnalyzer *this, hkBool *result, const char *monitorStreamBegin, const char *monitorStreamEnd, hkMonitorStreamFrameInfo *info)
{
  const char *v5; // r12
  int v6; // ebp
  hkBool *v7; // r14
  hkMonitorStreamAnalyzer *v8; // rsi
  hkBool *v9; // rax
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v10; // rdi
  hkMonitorStreamFrameInfo *v11; // rcx
  __int64 v12; // rdx
  signed __int64 v13; // rbx
  int v14; // eax
  __int64 v15; // rcx
  int v16; // eax
  char *v17; // rcx

  v5 = monitorStreamBegin;
  v6 = (_DWORD)monitorStreamEnd - (_DWORD)monitorStreamBegin;
  v7 = result;
  v8 = this;
  if ( (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) - this->m_data.m_size >= (signed int)monitorStreamEnd
                                                                             - (signed int)monitorStreamBegin )
  {
    v10 = &this->m_frameInfos.m_data[info->m_threadId];
    if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 40);
    v11 = &v10->m_data[v10->m_size];
    if ( v11 )
      hkMonitorStreamFrameInfo::hkMonitorStreamFrameInfo(v11);
    v12 = v10->m_size;
    v13 = (signed __int64)&v10->m_data[v12];
    v10->m_size = v12 + 1;
    hkStringPtr::operator=((hkStringPtr *)v13, &info->m_heading);
    *(_DWORD *)(v13 + 8) = info->m_indexOfTimer0;
    *(_DWORD *)(v13 + 12) = info->m_indexOfTimer1;
    *(_DWORD *)(v13 + 16) = info->m_absoluteTimeCounter.m_storage;
    *(float *)(v13 + 20) = info->m_timerFactor0;
    *(float *)(v13 + 24) = info->m_timerFactor1;
    *(_DWORD *)(v13 + 28) = info->m_threadId;
    *(_DWORD *)(v13 + 32) = info->m_frameStreamStart;
    *(_DWORD *)(v13 + 36) = info->m_frameStreamEnd;
    v14 = v8->m_data.m_size;
    *(_DWORD *)(v13 + 32) = v14;
    *(_DWORD *)(v13 + 36) = v6 + v14;
    v15 = v8->m_data.m_size;
    v16 = v15 + v6;
    v17 = &v8->m_data.m_data[v15];
    v8->m_data.m_size = v16;
    hkString::memCpy(v17, v5, v6);
    v7->m_bool = 1;
    v9 = v7;
  }
  else
  {
    result->m_bool = 0;
    v9 = result;
  }
  return v9;
}

// File Line: 424
// RVA: 0xC7A0E0
hkMonitorStreamAnalyzer::Node *__fastcall createNewNode(hkMonitorStreamAnalyzer::Node *parent, const char *name, hkMonitorStreamAnalyzer::Node::NodeType type, bool wantNodeReuse)
{
  __int64 v4; // r14
  hkMonitorStreamAnalyzer::Node::NodeType v5; // er15
  const char *v6; // rbp
  hkMonitorStreamAnalyzer::Node *v7; // rsi
  int v8; // ebx
  __int64 v9; // rdi
  hkMonitorStreamAnalyzer::Node *v10; // rax
  _QWORD **v12; // rax
  hkMonitorStreamAnalyzer::Node *v13; // rax
  __int64 v14; // rax

  v4 = 0i64;
  v5 = type;
  v6 = name;
  v7 = parent;
  if ( wantNodeReuse )
  {
    v8 = 0;
    if ( parent )
    {
      v9 = 0i64;
      while ( v6 && v8 < v7->m_children.m_size )
      {
        v10 = v7->m_children.m_data[v9];
        if ( v10->m_name && !(unsigned int)hkString::strCmp(v10->m_name, v6) )
          return v7->m_children.m_data[v8];
        ++v8;
        ++v9;
      }
    }
  }
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                           v12[11],
                                           144i64);
  if ( v13 )
  {
    hkMonitorStreamAnalyzer::Node::Node(v13, v7, v6, v5);
    v4 = v14;
  }
  return (hkMonitorStreamAnalyzer::Node *)v4;
}

// File Line: 444
// RVA: 0xC77920
void __fastcall hkMonitorStreamAnalyzer::Node::setTimers(hkMonitorStreamAnalyzer::Node *this, hkMonitorStreamFrameInfo *frameInfo, hkMonitorStream::TimerCommand *start, hkMonitorStream::TimerCommand *end)
{
  __int64 v4; // r10
  hkMonitorStream::TimerCommand *v5; // r11
  unsigned int v6; // eax
  unsigned int v7; // er9
  int v8; // eax
  float v9; // xmm0_4
  __int64 v10; // r9
  unsigned int v11; // eax
  signed int v12; // eax
  float v13; // xmm0_4
  unsigned int v14; // eax
  float v15; // xmm1_4
  signed int v16; // eax

  v4 = frameInfo->m_indexOfTimer0;
  v5 = end;
  if ( (unsigned int)v4 <= 0xB )
  {
    v6 = end->m_time0;
    v7 = start->m_time0;
    if ( v6 >= v7 )
      v8 = v6 - v7;
    else
      v8 = v6 - v7 - 1;
    v9 = (float)v8 * frameInfo->m_timerFactor0;
    ++this->m_count[v4];
    this->m_value[v4] = v9 + this->m_value[v4];
  }
  v10 = frameInfo->m_indexOfTimer1;
  if ( (unsigned int)v10 <= 0xB )
  {
    v11 = v5->m_time1;
    if ( v5->m_time0 >= start->m_time0 )
      v12 = v11 - start->m_time1;
    else
      v12 = v11 - start->m_time1 - 1;
    v13 = (float)v12 * frameInfo->m_timerFactor1;
    ++this->m_count[v10];
    this->m_value[v10] = v13 + this->m_value[v10];
  }
  v14 = frameInfo->m_absoluteTimeCounter.m_storage;
  if ( v14 )
  {
    if ( v14 != 1 )
      return;
    v15 = frameInfo->m_timerFactor1;
    v16 = start->m_time1;
  }
  else
  {
    v15 = frameInfo->m_timerFactor0;
    v16 = start->m_time0;
  }
  this->m_absoluteStartTime = v15 * (double)v16;
}

// File Line: 498
// RVA: 0xC7A1B0
char __fastcall findChildWithHint(hkMonitorStreamAnalyzer::Node *mainNode, const char *childName, int *childId)
{
  int *v3; // r14
  const char *v4; // rbp
  hkMonitorStreamAnalyzer::Node *v5; // rsi
  int v7; // ebx
  __int64 v8; // rdi

  v3 = childId;
  v4 = childName;
  v5 = mainNode;
  if ( mainNode->m_children.m_size > *childId
    && !(unsigned int)hkString::strCmp(mainNode->m_children.m_data[*childId]->m_name, childName) )
  {
    return 1;
  }
  v7 = 0;
  if ( v5->m_children.m_size <= 0 )
    return 0;
  v8 = 0i64;
  while ( (unsigned int)hkString::strCmp(v5->m_children.m_data[v8]->m_name, v4) )
  {
    ++v7;
    ++v8;
    if ( v7 >= v5->m_children.m_size )
      return 0;
  }
  *v3 = v7;
  return 1;
}

// File Line: 516
// RVA: 0xC7A270
void __fastcall reduceMainTree(hkMonitorStreamAnalyzer::Node *node, int destTimerId, float smoothingFactor)
{
  __int64 v3; // rbp
  int v4; // ebx
  hkMonitorStreamAnalyzer::Node *v5; // rsi
  __int64 v6; // rdi

  v3 = destTimerId;
  v4 = 0;
  node->m_count[v3] = 0;
  v5 = node;
  node->m_value[v3] = smoothingFactor * node->m_value[destTimerId];
  if ( node->m_children.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      reduceMainTree(v5->m_children.m_data[v6], v3, smoothingFactor);
      ++v4;
      ++v6;
    }
    while ( v4 < v5->m_children.m_size );
  }
}

// File Line: 527
// RVA: 0xC7A2F0
void __fastcall mergeSubTree(hkMonitorStreamAnalyzer::Node *mainTree, hkMonitorStreamAnalyzer::Node *subTree, int destTimerId, int sourceTimerId, float smoothingFactor)
{
  hkMonitorStreamAnalyzer::Node *v5; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkMonitorStreamAnalyzer::Node *v8; // rbp
  char v9; // al
  int v10; // ebx
  _QWORD **v11; // rax
  hkMonitorStreamAnalyzer::Node *v12; // rax
  hkMonitorStreamAnalyzer::Node *v13; // rax
  hkMonitorStreamAnalyzer::Node *v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rax
  int v17; // ecx
  int childId; // [rsp+30h] [rbp-68h]
  __int64 v19; // [rsp+38h] [rbp-60h]
  __int64 v20; // [rsp+40h] [rbp-58h]
  hkMonitorStreamAnalyzer::Node *parent; // [rsp+A0h] [rbp+8h]
  hkMonitorStreamAnalyzer::Node *v22; // [rsp+A8h] [rbp+10h]
  int destTimerIda; // [rsp+B0h] [rbp+18h]
  int sourceTimerIda; // [rsp+B8h] [rbp+20h]

  sourceTimerIda = sourceTimerId;
  v22 = subTree;
  parent = mainTree;
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
      v9 = findChildWithHint(v5, v8->m_name, &childId);
      v10 = childId;
      if ( v9 )
      {
        v14 = parent->m_children.m_data[childId];
      }
      else
      {
        v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v12 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                                 v11[11],
                                                 144i64);
        if ( v12 )
        {
          hkMonitorStreamAnalyzer::Node::Node(
            v12,
            parent,
            v8->m_name,
            (hkMonitorStreamAnalyzer::Node::NodeType)v8->m_type.m_storage);
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
      mergeSubTree(v14, v8, destTimerIda, sourceTimerIda, smoothingFactor);
      subTree = v22;
      v17 = v22->m_children.m_size;
      if ( v10 < v17 - 1 )
        childId = v10 + 1;
      v5 = parent;
      ++v6;
      ++v7;
    }
    while ( v6 < v17 );
  }
}

// File Line: 564
// RVA: 0xC774B0
void __fastcall hkMonitorStreamAnalyzer::mergeTreesForCombinedThreadSummary(hkMonitorStreamAnalyzer::Node *mainTree, hkMonitorStreamAnalyzer::Node *subTree, int destTimerId, int sourceTimerId, float smoothingFactor)
{
  hkMonitorStreamAnalyzer::Node *v5; // rax
  int v6; // er8
  int v7; // er9
  hkMonitorStreamAnalyzer::Node *v8; // r10

  reduceMainTree(mainTree, destTimerId, smoothingFactor);
  mergeSubTree(v8, v5, v6, v7, smoothingFactor);
}

// File Line: 571
// RVA: 0xC774E0
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::navigateMonitors(hkMonitorStreamAnalyzer::CursorKeys *keys, hkMonitorStreamAnalyzer::Node *activeNodeIn)
{
  hkMonitorStreamAnalyzer::Node *v2; // r9
  hkMonitorStreamAnalyzer::CursorKeys *v3; // rsi
  hkMonitorStreamAnalyzer::Node *v5; // rcx
  hkMonitorStreamAnalyzer::Node **v6; // r11
  hkMonitorStreamAnalyzer::Node *v7; // rax
  __int64 v8; // r10
  int v9; // er8
  __int64 v10; // rdx
  hkMonitorStreamAnalyzer::Node **v11; // rcx
  int i; // ecx
  hkMonitorStreamAnalyzer::Node *v13; // r10
  hkMonitorStreamAnalyzer::Node *v14; // r11
  int v15; // er8
  __int64 v16; // rdx
  __int64 v17; // rdi
  hkMonitorStreamAnalyzer::Node **v18; // rcx
  unsigned int v19; // eax
  hkMonitorStreamAnalyzer::Node *v20; // rax

  v2 = activeNodeIn;
  v3 = keys;
  if ( !activeNodeIn )
    return 0i64;
  if ( keys->m_upPressed.m_bool )
  {
    v5 = activeNodeIn->m_parent;
    v6 = v5->m_children.m_data;
    v7 = *v6;
    if ( *v6 == activeNodeIn )
    {
      if ( v5->m_parent )
        v2 = activeNodeIn->m_parent;
    }
    else
    {
      v8 = v5->m_children.m_size;
      v9 = 0;
      v10 = 0i64;
      if ( v8 > 0 )
      {
        v11 = v5->m_children.m_data;
        while ( *v11 != v2 )
        {
          ++v10;
          ++v9;
          ++v11;
          if ( v10 >= v8 )
            goto LABEL_11;
        }
        v7 = v6[v9 - 1];
      }
LABEL_11:
      for ( i = v7->m_children.m_size; i > 0; i = v7->m_children.m_size )
      {
        if ( !(v7->m_userFlags & 1) )
          break;
        v7 = v7->m_children.m_data[i - 1];
      }
      v2 = v7;
    }
  }
  if ( v3->m_downPressed.m_bool )
  {
    v13 = v2;
    if ( v2->m_children.m_size > 0 && v2->m_userFlags & 1 )
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
        if ( (signed int)v17 > 0 )
          break;
LABEL_26:
        if ( !v14->m_parent )
          goto LABEL_29;
        v13 = v13->m_parent;
      }
      v18 = v14->m_children.m_data;
      while ( *v18 != v13 || v15 >= (signed int)v17 - 1 )
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
  if ( v3->m_leftPressed.m_bool )
  {
    v19 = v2->m_userFlags;
    if ( v19 & 1 )
    {
      v2->m_userFlags = v19 & 0xFFFFFFFE;
    }
    else
    {
      v20 = v2->m_parent;
      if ( v20->m_parent )
      {
        v20->m_userFlags &= 0xFFFFFFFE;
        v2 = v20;
      }
    }
  }
  if ( v3->m_rightPressed.m_bool )
  {
    if ( !(v2->m_userFlags & 1) )
      v2->m_userFlags |= 1u;
    v2->m_userFlags |= 1u;
  }
  return v2;
}

// File Line: 682
// RVA: 0xC77AA0
__int64 __fastcall hkMonitorStreamAnalyzer::findMaxTimerNameIndent(hkMonitorStreamAnalyzer::Node *node, int recursionDepth, int spacing, bool displayPartialTree)
{
  hkMonitorStreamAnalyzer::Node *v4; // rdi
  int v5; // ebp
  int v6; // eax
  int v7; // edx
  bool v8; // cl
  int v9; // ebx
  int v10; // esi
  int v11; // er10
  __int64 v12; // rbp
  int v13; // eax
  int v15; // [rsp+48h] [rbp+10h]
  int spacinga; // [rsp+50h] [rbp+18h]
  bool v17; // [rsp+58h] [rbp+20h]

  v17 = displayPartialTree;
  spacinga = spacing;
  v4 = node;
  v5 = recursionDepth;
  v6 = hkString::strLen(node->m_name);
  v7 = spacinga;
  v8 = v17;
  v9 = v6 + spacinga * v5 + 8;
  if ( !v17 || v4->m_userFlags & 1 )
  {
    v10 = 0;
    if ( v4->m_children.m_size > 0 )
    {
      v11 = v5 + 1;
      v12 = 0i64;
      v15 = v11;
      do
      {
        v13 = hkMonitorStreamAnalyzer::findMaxTimerNameIndent(v4->m_children.m_data[v12], v11, v7, v8);
        v8 = v17;
        v7 = spacinga;
        v11 = v15;
        ++v12;
        if ( v13 > v9 )
          v9 = v13;
        ++v10;
      }
      while ( v10 < v4->m_children.m_size );
    }
  }
  return (unsigned int)v9;
}

// File Line: 701
// RVA: 0xC77B50
void __fastcall hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec(hkOstream *os, hkMonitorStreamAnalyzer::Node *node, int recursionDepth, int numThreads, int numSpus, hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *options)
{
  hkMonitorStreamAnalyzer::Node *v6; // rbp
  int v7; // ebx
  int v8; // ecx
  int v9; // er8
  hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *v10; // rsi
  int v11; // edi
  char v12; // dl
  int v13; // eax
  __int64 v14; // rbx
  char v15; // dl
  __int64 v16; // rbx
  int v17; // edx
  int v18; // er8
  signed __int64 v19; // r10
  unsigned int *v20; // rax
  unsigned __int64 v21; // rcx
  unsigned int v22; // er9
  __int64 v23; // rax
  const char *v24; // r8
  int v25; // edx
  __int64 v26; // rdi
  int v27; // eax
  int v28; // ecx
  __int64 v29; // rbx
  __int64 v30; // r9
  __m128d v31; // xmm2
  int v32; // ebx
  int v33; // eax
  __int64 v34; // rdi
  __int64 v35; // [rsp+30h] [rbp-48h]
  char *s; // [rsp+38h] [rbp-40h]
  int v37; // [rsp+40h] [rbp-38h]
  int v38; // [rsp+44h] [rbp-34h]
  hkOstream v39; // [rsp+48h] [rbp-30h]
  hkOstream *osa; // [rsp+80h] [rbp+8h]
  int v41; // [rsp+90h] [rbp+18h]
  int v42; // [rsp+90h] [rbp+18h]
  int numThreadsa; // [rsp+98h] [rbp+20h]
  int optionsa; // [rsp+A8h] [rbp+30h]

  numThreadsa = numThreads;
  v41 = recursionDepth;
  osa = os;
  v6 = node;
  s = 0i64;
  v7 = recursionDepth;
  v37 = 0;
  v38 = 2147483648;
  hkOstream::hkOstream(&v39, (hkArray<char,hkContainerHeapAllocator> *)&s);
  v8 = numThreadsa;
  v9 = numSpus;
  v10 = options;
  v11 = numThreadsa + numSpus;
  if ( v7 )
  {
    if ( options->m_displayPartialTree )
    {
      if ( options->m_activeNode == v6 )
        v12 = options->m_rightArrowChar;
      else
        v12 = 32;
      hkOstream::operator<<(&v39, v12);
    }
    v13 = (v7 - 1) * options->m_tabSpacingForTimerNames;
    if ( v13 > 0 )
    {
      v14 = (unsigned int)v13;
      do
      {
        hkOstream::operator<<(&v39, 32);
        --v14;
      }
      while ( v14 );
    }
    if ( options->m_displayPartialTree )
    {
      if ( v6->m_children.m_size <= 0 )
      {
        v15 = 32;
      }
      else if ( v6->m_userFlags & 1 )
      {
        v15 = options->m_downArrowChar;
      }
      else
      {
        v15 = options->m_rightArrowChar;
      }
      hkOstream::operator<<(&v39, v15);
    }
    v16 = v11;
    v17 = 0;
    v18 = 0;
    v19 = 0i64;
    v35 = v11;
    if ( v11 >= 2i64 )
    {
      v20 = &v6->m_count[1];
      v21 = ((unsigned __int64)(v11 - 2i64) >> 1) + 1;
      v19 = 2 * v21;
      do
      {
        v17 += *(v20 - 1);
        v18 += *v20;
        v20 += 2;
        --v21;
      }
      while ( v21 );
    }
    if ( v19 < v11 )
      v22 = v6->m_count[v19];
    LODWORD(v23) = v17 + v18;
    if ( options->m_showUnaccountedForTimes )
    {
      if ( !v6->m_type.m_storage )
      {
        v23 = v6->m_children.m_size;
        if ( v23 > 0 )
        {
          do
            --v23;
          while ( v23 );
        }
      }
    }
    v24 = v6->m_name;
    hkOstream::printf(&v39, "%s (%i) ", v23);
    v25 = 0;
    v26 = 0i64;
    for ( optionsa = 0; v26 < v16; ++optionsa )
    {
      if ( v10->m_useTabsNotSpacesForColumns )
      {
        v27 = (unsigned __int64)hkOstream::operator<<(&v39, 9);
      }
      else
      {
        v27 = v25 * v10->m_timerColumnWidth;
        v28 = v10->m_indentationToFirstTimerValue + v27 + (v41 - 1) * v10->m_tabSpacingForTimerValues - v37;
        if ( v28 > 0 )
        {
          v29 = (unsigned int)v28;
          do
          {
            v27 = (unsigned __int64)hkOstream::operator<<(&v39, 32);
            --v29;
          }
          while ( v29 );
          v16 = v35;
        }
      }
      v30 = v6->m_count[v26];
      v31 = _mm_cvtps_pd((__m128)LODWORD(v6->m_value[v26]));
      hkOstream::printf(&v39, "%-6.3f (%i)", v27);
      v25 = optionsa + 1;
      ++v26;
    }
    hkOstream::operator<<(osa, s);
    hkOstream::operator<<(osa, 10);
    v8 = numThreadsa;
    v9 = numSpus;
  }
  if ( !v10->m_displayPartialTree || v6->m_userFlags & 1 )
  {
    v32 = 0;
    if ( v6->m_children.m_size > 0 )
    {
      v33 = v41 + 1;
      v34 = 0i64;
      v42 = v41 + 1;
      do
      {
        hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec(osa, v6->m_children.m_data[v34], v33, v8, v9, v10);
        v33 = v42;
        v8 = numThreadsa;
        v9 = numSpus;
        ++v32;
        ++v34;
      }
      while ( v32 < v6->m_children.m_size );
    }
  }
  hkOstream::~hkOstream(&v39);
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      s,
      v38 & 0x3FFFFFFF);
}

// File Line: 814
// RVA: 0xC76D40
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::makeStatisticsTreeForSingleFrame(const char *frameStart, const char *frameEnd, hkMonitorStreamFrameInfo *frameInfo, const char *rootNodeName, hkBool reuseNodesIfPossible)
{
  char *v5; // rdi
  const char *v6; // rbx
  hkMonitorStreamFrameInfo *v7; // r13
  const char *v8; // r15
  _QWORD **v9; // rax
  hkMonitorStreamAnalyzer::Node *v10; // rax
  hkMonitorStreamAnalyzer::Node *v11; // rax
  hkMonitorStreamAnalyzer::Node *v12; // r14
  hkMonitorStreamAnalyzer::Node *v13; // r12
  char *v14; // rsi
  char *v15; // rcx
  char *v16; // rcx
  hkMonitorStream::TimerCommand *v17; // rbx
  int v18; // ebx
  int v19; // er9
  char *v20; // rcx
  char *v21; // rcx
  char *v23; // rcx
  char *v24; // rcx
  hkMonitorStreamAnalyzer::Node *v25; // rax
  int v26; // edx
  __int64 v27; // rsi
  __int64 v28; // rbx
  hkMonitorStreamAnalyzer::Node *v29; // r14
  char *v30; // rax
  int v31; // ecx
  char *v32; // rax
  char *v33; // rbx
  hkMonitorStream::TimerCommand *v34; // r8
  hkMonitorStreamAnalyzer::Node *v35; // r14
  int v36; // ecx
  int v37; // ebx
  int v38; // er9
  int v39; // ebx
  int v40; // er9
  hkMonitorStreamAnalyzer::Node *v41; // rax
  float v42; // xmm0_4
  hkResult v43; // [rsp+30h] [rbp-D0h]
  char *array; // [rsp+40h] [rbp-C0h]
  int v45; // [rsp+48h] [rbp-B8h]
  int v46; // [rsp+4Ch] [rbp-B4h]
  char v47; // [rsp+50h] [rbp-B0h]
  char *v48; // [rsp+150h] [rbp+50h]
  int v49; // [rsp+158h] [rbp+58h]
  int v50; // [rsp+15Ch] [rbp+5Ch]
  char v51; // [rsp+160h] [rbp+60h]
  char *v52; // [rsp+260h] [rbp+160h]
  hkResult result; // [rsp+2B0h] [rbp+1B0h]
  hkResult v54; // [rsp+2B8h] [rbp+1B8h]

  v5 = (char *)frameStart;
  v6 = rootNodeName;
  v7 = frameInfo;
  v8 = frameEnd;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(
                                           v9[11],
                                           144i64);
  if ( v10 )
  {
    hkMonitorStreamAnalyzer::Node::Node(v10, 0i64, v6, NODE_TYPE_DIRECTORY);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = v12;
  v45 = 0;
  array = &v47;
  v46 = -2147483632;
  v49 = 0;
  v50 = -2147483632;
  v48 = &v51;
  if ( v5 < v8 )
  {
    while ( 1 )
    {
      v14 = *(char **)v5;
      if ( *(_QWORD *)v5 >= 0x14ui64 )
        break;
      v5 += 4;
$LN21_61:
      if ( v5 >= v8 )
        goto LABEL_36;
    }
    switch ( *v14 )
    {
      case 69:
        if ( !v45 )
          break;
        v17 = (hkMonitorStream::TimerCommand *)&array[16 * (v45 - 1)];
        if ( v14[2] )
        {
          if ( (unsigned int)hkString::strCmp(v17->m_commandAndMonitor + 2, v14 + 2) )
            break;
        }
        hkMonitorStreamAnalyzer::Node::setTimers(v12, v7, v17, (hkMonitorStream::TimerCommand *)v5);
        v12 = v12->m_parent;
        --v45;
        v18 = v49 - 1;
        if ( (v50 & 0x3FFFFFFF) >= v49 - 1 )
        {
          result.m_enum = 0;
          --v49;
          v5 += 16;
        }
        else
        {
          v19 = v49 - 1;
          if ( v18 < 2 * (v50 & 0x3FFFFFFF) )
            v19 = 2 * (v50 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, v19, 16);
          v49 = v18;
          v5 += 16;
        }
        goto $LN21_61;
      case 70:
        goto $LN21_61;
      case 76:
        if ( v45 == (v46 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v23 = &array[16 * v45];
        if ( v23 )
        {
          *(_QWORD *)v23 = *(_QWORD *)v5;
          *((_QWORD *)v23 + 1) = *((_QWORD *)v5 + 1);
        }
        ++v45;
        if ( v49 == (v50 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, 16);
        v24 = &v48[16 * v49];
        if ( v24 )
        {
          *(_QWORD *)v24 = *(_QWORD *)v5;
          *((_QWORD *)v24 + 1) = *((_QWORD *)v5 + 1);
        }
        ++v49;
        v25 = createNewNode(v12, v14 + 2, 0, reuseNodesIfPossible.m_bool != 0);
        v26 = v45;
        v27 = *((_QWORD *)v5 + 1);
        v28 = *((_QWORD *)v5 + 2);
        v52 = *(char **)v5;
        v29 = v25;
        if ( v45 == (v46 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v26 = v45;
        }
        v30 = &array[16 * v26];
        if ( v30 )
        {
          *(_QWORD *)v30 = v28;
          *((_QWORD *)v30 + 1) = v27;
          v26 = v45;
        }
        v31 = v49;
        v45 = v26 + 1;
        if ( v49 == (v50 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, 16);
          v31 = v49;
        }
        v32 = &v48[16 * v31];
        if ( v32 )
        {
          *(_QWORD *)v32 = v28;
          *((_QWORD *)v32 + 1) = v27;
          v31 = v49;
        }
        v49 = v31 + 1;
        v12 = createNewNode(v29, (const char *)(v28 + 2), 0, reuseNodesIfPossible.m_bool != 0);
        goto $LN3_162;
      case 77:
        v41 = createNewNode(v12, v14 + 2, NODE_TYPE_SINGLE, reuseNodesIfPossible.m_bool != 0);
        v42 = *((float *)v5 + 2);
        ++v41->m_count[0];
        v5 += 16;
        v41->m_value[0] = v42 + v41->m_value[0];
        goto $LN21_61;
      case 78:
        goto $LN4_174;
      case 79:
        if ( v45 == (v46 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v20 = &array[16 * v45];
        if ( v20 )
        {
          *(_QWORD *)v20 = *(_QWORD *)v5;
          *((_QWORD *)v20 + 1) = *((_QWORD *)v5 + 1);
        }
        ++v45;
        v12 = createNewNode(v12, *((const char **)v5 + 2), 0, reuseNodesIfPossible.m_bool != 0);
        if ( v49 == (v50 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, 16);
        v21 = &v48[16 * v49];
        if ( v21 )
        {
          *(_QWORD *)v21 = *(_QWORD *)v5;
          *((_QWORD *)v21 + 1) = *((_QWORD *)v5 + 1);
        }
        ++v49;
        goto $LN3_162;
      case 80:
        v5 += 8;
        v12 = createNewNode(v12, v14 + 2, NODE_TYPE_DIRECTORY, reuseNodesIfPossible.m_bool != 0);
        goto $LN21_61;
      case 83:
        if ( !v45 )
          break;
        v33 = &array[16 * (v45 - 1)];
        hkMonitorStreamAnalyzer::Node::setTimers(
          v12,
          v7,
          (hkMonitorStream::TimerCommand *)&array[16 * (v45 - 1)],
          (hkMonitorStream::TimerCommand *)v5);
        v5 += 16;
        v12 = createNewNode(v12->m_parent, v14 + 2, 0, reuseNodesIfPossible.m_bool != 0);
        *(_QWORD *)v33 = *((_QWORD *)v5 - 2);
        *((_QWORD *)v33 + 1) = *((_QWORD *)v5 - 1);
        goto $LN21_61;
      case 84:
        v12 = createNewNode(v12, v14 + 2, 0, reuseNodesIfPossible.m_bool != 0);
        if ( v45 == (v46 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v15 = &array[16 * v45];
        if ( v15 )
        {
          *(_QWORD *)v15 = *(_QWORD *)v5;
          *((_QWORD *)v15 + 1) = *((_QWORD *)v5 + 1);
        }
        ++v45;
        if ( v49 == (v50 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, 16);
        v16 = &v48[16 * v49];
        if ( v16 )
        {
          *(_QWORD *)v16 = *(_QWORD *)v5;
          *((_QWORD *)v16 + 1) = *((_QWORD *)v5 + 1);
        }
        ++v49;
        v5 += 16;
        goto $LN21_61;
      case 108:
        if ( v45 <= 1 )
          break;
        v34 = (hkMonitorStream::TimerCommand *)&array[16 * (v45 - 1)];
        if ( *v34->m_commandAndMonitor != 83 )
          break;
        hkMonitorStreamAnalyzer::Node::setTimers(v12, v7, v34, (hkMonitorStream::TimerCommand *)v5);
        v35 = v12->m_parent;
        v36 = v45 - 1;
        v37 = v49 - 1;
        --v45;
        if ( (v50 & 0x3FFFFFFF) >= v49 - 1 )
        {
          v54.m_enum = 0;
        }
        else
        {
          v38 = v49 - 1;
          if ( v37 < 2 * (v50 & 0x3FFFFFFF) )
            v38 = 2 * (v50 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v54, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, v38, 16);
          v36 = v45;
        }
        v49 = v37;
        hkMonitorStreamAnalyzer::Node::setTimers(
          v35,
          v7,
          (hkMonitorStream::TimerCommand *)&array[16 * (v36 - 1)],
          (hkMonitorStream::TimerCommand *)v5);
        v12 = v35->m_parent;
        --v45;
        v39 = v49 - 1;
        if ( (v50 & 0x3FFFFFFF) >= v49 - 1 )
        {
          v43.m_enum = 0;
          --v49;
          v5 += 16;
        }
        else
        {
          v40 = v49 - 1;
          if ( v39 < 2 * (v50 & 0x3FFFFFFF) )
            v40 = 2 * (v50 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v43, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, v40, 16);
          v49 = v39;
          v5 += 16;
        }
        goto $LN21_61;
      case 109:
$LN3_162:
        v5 += 24;
        goto $LN21_61;
      case 112:
        v12 = v12->m_parent;
        if ( !v12 )
          break;
$LN4_174:
        v5 += 8;
        goto $LN21_61;
      default:
        break;
    }
  }
LABEL_36:
  v49 = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v48,
      16 * v50);
  v48 = 0i64;
  v50 = 2147483648;
  v45 = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v46);
  return v13;
}

// File Line: 1021
// RVA: 0xC77E50
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::makeStatisticsTreeForMultipleFrames(hkMonitorStreamAnalyzer *this, int threadId, hkBool reuseNodesIfPossible)
{
  hkMonitorStreamAnalyzer *v3; // r15
  signed __int64 v4; // rbx
  _QWORD **v5; // rax
  hkMonitorStreamAnalyzer::Node *v6; // rax
  int v7; // edi
  _DWORD *v8; // rax
  _DWORD *v9; // rbp
  signed __int64 v10; // rsi
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // er9
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v15; // rcx
  __int64 v16; // r13
  __int64 v17; // r12
  __int64 v18; // rbx
  hkMonitorStreamAnalyzer::Node *v19; // rax
  hkResult result; // [rsp+78h] [rbp+10h]
  char v22; // [rsp+80h] [rbp+18h]

  v22 = reuseNodesIfPossible.m_bool;
  v3 = this;
  v4 = threadId;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                          v5[11],
                                          144i64);
  v7 = 0;
  if ( v6 )
  {
    hkMonitorStreamAnalyzer::Node::Node(v6, 0i64, "/", NODE_TYPE_DIRECTORY);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v4;
  v11 = v3->m_frameInfos.m_data[v4].m_size;
  v12 = v9[27] & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v11;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 24, v14, 8);
  }
  v9[26] = v11;
  v15 = &v3->m_frameInfos.m_data[v10];
  if ( v15->m_size > 0 )
  {
    v16 = 0i64;
    v17 = 0i64;
    do
    {
      v18 = *((_QWORD *)v9 + 12);
      v19 = hkMonitorStreamAnalyzer::makeStatisticsTreeForSingleFrame(
              &v3->m_data.m_data[v15->m_data[v16].m_frameStreamStart],
              &v3->m_data.m_data[v15->m_data[v16].m_frameStreamEnd],
              &v15->m_data[v16],
              (const char *)((_QWORD)v15->m_data[v16].m_heading.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
              (hkBool)v22);
      ++v7;
      ++v16;
      *(_QWORD *)(v18 + v17) = v19;
      v17 += 8i64;
      v15 = &v3->m_frameInfos.m_data[v10];
    }
    while ( v7 < v15->m_size );
  }
  return (hkMonitorStreamAnalyzer::Node *)v9;
}

// File Line: 1049
// RVA: 0xC77660
void __fastcall hkMonitorStreamAnalyzer::showCombinedThreadSummaryForSingleFrame(hkMonitorStreamAnalyzer::Node *node, int numThreads, int numSpus, hkOstream *os, hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *options)
{
  hkOstream *v5; // r15
  int v6; // er14
  signed int v7; // ebp
  hkMonitorStreamAnalyzer::Node *v8; // r12
  int v9; // eax
  int v10; // eax
  signed int i; // esi
  int v12; // eax
  __int64 v13; // rbx
  int j; // esi
  int v15; // eax
  __int64 v16; // rbx
  int v17; // eax
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+30h] [rbp-48h]
  hkOstream v19; // [rsp+40h] [rbp-38h]

  v5 = os;
  v6 = numSpus;
  v7 = numThreads;
  v8 = node;
  v9 = hkMonitorStreamAnalyzer::findMaxTimerNameIndent(
         node,
         0,
         options->m_tabSpacingForTimerNames,
         options->m_displayPartialTree);
  buf.m_data = 0i64;
  buf.m_size = 0;
  options->m_indentationToFirstTimerValue = v9;
  buf.m_capacityAndFlags = 2147483648;
  hkOstream::hkOstream(&v19, &buf);
  hkOstream::printf(&v19, "Timer Name", v10);
  if ( v7 > 1 || v6 > 0 )
  {
    for ( i = 0; i < v7; ++i )
    {
      if ( options->m_useTabsNotSpacesForColumns )
      {
        v12 = (unsigned __int64)hkOstream::operator<<(&v19, 9);
      }
      else
      {
        v12 = options->m_indentationToFirstTimerValue + i * options->m_timerColumnWidth - buf.m_size;
        if ( v12 > 0 )
        {
          v13 = (unsigned int)v12;
          do
          {
            v12 = (unsigned __int64)hkOstream::operator<<(&v19, 32);
            --v13;
          }
          while ( v13 );
        }
      }
      hkOstream::printf(&v19, "Thread %d", v12);
    }
    for ( j = 0; j < v6; ++j )
    {
      if ( options->m_useTabsNotSpacesForColumns )
      {
        v15 = (unsigned __int64)hkOstream::operator<<(&v19, 9);
      }
      else
      {
        v15 = options->m_indentationToFirstTimerValue + options->m_timerColumnWidth * (j + v7) - buf.m_size;
        if ( v15 > 0 )
        {
          v16 = (unsigned int)v15;
          do
          {
            v15 = (unsigned __int64)hkOstream::operator<<(&v19, 32);
            --v16;
          }
          while ( v16 );
        }
      }
      hkOstream::printf(&v19, "Spu %d", v15);
    }
  }
  v17 = (unsigned __int64)hkOstream::operator<<(v5, buf.m_data);
  hkOstream::printf(v5, "\n\n", v17);
  hkMonitorStreamAnalyzer::showCombinedThreadSummaryRec(v5, v8, 0, v7, v6, options);
  hkOstream::~hkOstream(&v19);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 1095
// RVA: 0xC7A490
void __fastcall hkMakeSum(hkMonitorStreamAnalyzer::Node *sum, hkMonitorStreamAnalyzer::Node *node)
{
  float *v2; // r8
  signed __int64 v3; // rdx
  signed __int64 v4; // rcx
  float v5; // xmm0_4

  v2 = (float *)sum->m_count;
  v3 = (char *)node - (char *)sum;
  v4 = 2i64;
  do
  {
    v5 = *(float *)((char *)v2 + v3 - 48);
    v2 += 6;
    *(v2 - 18) = v5 + *(v2 - 18);
    *((_DWORD *)v2 - 6) += *(_DWORD *)((char *)v2 + v3 - 24);
    *(v2 - 17) = *(float *)((char *)v2 + v3 - 68) + *(v2 - 17);
    *((_DWORD *)v2 - 5) += *(_DWORD *)((char *)v2 + v3 - 20);
    *(v2 - 16) = *(float *)((char *)v2 + v3 - 64) + *(v2 - 16);
    *((_DWORD *)v2 - 4) += *(_DWORD *)((char *)v2 + v3 - 16);
    *(v2 - 15) = *(float *)((char *)v2 + v3 - 60) + *(v2 - 15);
    *((_DWORD *)v2 - 3) += *(_DWORD *)((char *)v2 + v3 - 12);
    *(v2 - 14) = *(float *)((char *)v2 + v3 - 56) + *(v2 - 14);
    *((_DWORD *)v2 - 2) += *(_DWORD *)((char *)v2 + v3 - 8);
    *(v2 - 13) = *(float *)((char *)v2 + v3 - 52) + *(v2 - 13);
    *((_DWORD *)v2 - 1) += *(_DWORD *)((char *)v2 + v3 - 4);
    --v4;
  }
  while ( v4 );
}

// File Line: 1133
// RVA: 0xC7BED0
void __fastcall hkMonitorStreamAnalyzerPrintByTypeInfo::hkMonitorStreamAnalyzerPrintByTypeInfo(hkMonitorStreamAnalyzerPrintByTypeInfo *this)
{
  hkMonitorStreamAnalyzerPrintByTypeInfo *v1; // rbx

  v1 = this;
  hkMonitorStreamAnalyzer::Node::Node(&this->m_this, 0i64, 0i64, 0);
  v1->m_parents.m_data = 0i64;
  v1->m_parents.m_size = 0;
  v1->m_parents.m_capacityAndFlags = 2147483648;
  v1->m_children.m_data = 0i64;
  v1->m_children.m_size = 0;
  v1->m_children.m_capacityAndFlags = 2147483648;
}

// File Line: 1142
// RVA: 0xC7C280
bool __fastcall hkCompareInfosBySize(hkMonitorStreamAnalyzerPrintByTypeInfo *a, hkMonitorStreamAnalyzerPrintByTypeInfo *b)
{
  return a->m_this.m_value[1] < b->m_this.m_value[1];
}

// File Line: 1147
// RVA: 0xC7AA70
void __fastcall hkBuildSizePerName(hkMonitorStreamAnalyzer::Node *node, hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *mapOut)
{
  const char *v2; // rdi
  hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *v3; // rbp
  hkMonitorStreamAnalyzer::Node *v4; // rsi
  unsigned __int64 v5; // rbx
  _QWORD **v6; // rax
  hkMonitorStreamAnalyzerPrintByTypeInfo *v7; // rax
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  char *v10; // rdx
  signed __int64 v11; // r8
  float v12; // xmm0_4
  signed __int64 v13; // rcx
  hkMonitorStreamAnalyzer::Node *v14; // rdi
  signed int *v15; // rax
  const char *v16; // rcx
  signed __int64 v17; // rbp
  int v18; // esi
  __int64 v19; // rbx
  signed __int64 v20; // rdi
  signed int *v21; // rbx
  __int64 v22; // rsi
  int v23; // er9
  int v24; // eax
  int v25; // eax
  signed __int64 v26; // rcx
  hkMonitorStreamAnalyzer::Node *v27; // rcx
  signed __int64 v28; // rax
  signed __int64 v29; // rcx
  char *v30; // rdi
  signed __int64 v31; // rdx
  float v32; // xmm0_4
  hkMonitorStreamAnalyzer::Node *v33; // rcx
  char *v34; // rcx
  __int64 v35; // rax
  int v36; // ebp
  __int64 v37; // rdi
  signed __int64 v38; // rsi
  signed int *v39; // rbx
  __int64 v40; // rdi
  int v41; // er9
  int v42; // eax
  int v43; // eax
  signed __int64 v44; // rcx
  hkMonitorStreamAnalyzer::Node *v45; // rcx
  signed __int64 v46; // rcx
  char *v47; // rdx
  float v48; // xmm0_4
  unsigned __int64 v49; // [rsp+30h] [rbp-58h]
  char *name; // [rsp+38h] [rbp-50h]
  __int64 v51; // [rsp+40h] [rbp-48h]
  signed __int64 v52; // [rsp+48h] [rbp-40h]
  hkMonitorStreamAnalyzer::Node *v53; // [rsp+50h] [rbp-38h]
  hkMonitorStreamAnalyzer::Node *v54; // [rsp+90h] [rbp+8h]
  char *v55; // [rsp+98h] [rbp+10h]
  __int64 v56; // [rsp+A0h] [rbp+18h]
  hkResult result; // [rsp+A8h] [rbp+20h]

  v55 = (char *)mapOut;
  v54 = node;
  v2 = node->m_name;
  v3 = mapOut;
  v4 = node;
  v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)mapOut,
         (unsigned __int64)node->m_name,
         0i64);
  v49 = v5;
  if ( !v5 )
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkMonitorStreamAnalyzerPrintByTypeInfo *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[12] + 8i64))(
                                                     v6[12],
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
    *(_QWORD *)(v5 + 128) = v2;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v3->m_map, (unsigned __int64)v2, v5);
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
      v15 = (signed int *)v49;
      v16 = v14->m_name;
      v17 = 0i64;
      name = (char *)v14->m_name;
      v18 = *(_DWORD *)(v49 + 168) - 1;
      v19 = v18;
      if ( v18 >= 0 )
      {
        v20 = 144i64 * v18;
        do
        {
          v17 = v20 + *((_QWORD *)v15 + 20);
          if ( !(unsigned int)hkString::strCmp(v16, *(const char **)(v17 + 128)) )
            break;
          v15 = (signed int *)v49;
          v16 = name;
          --v18;
          v20 -= 144i64;
          --v19;
        }
        while ( v19 >= 0 );
        v14 = v53;
        v15 = (signed int *)v49;
      }
      if ( v18 < 0 )
      {
        v21 = v15 + 40;
        v22 = v15[42];
        v23 = v22 + 1;
        v24 = v15[43] & 0x3FFFFFFF;
        if ( v24 >= (signed int)v22 + 1 )
        {
          result.m_enum = 0;
        }
        else
        {
          v25 = 2 * v24;
          if ( v23 < v25 )
            v23 = v25;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, v21, v23, 144);
        }
        v26 = *(_QWORD *)v21 + 144i64 * v21[2];
        if ( v26 )
        {
          *(_QWORD *)(v26 + 96) = 0i64;
          *(_DWORD *)(v26 + 104) = 0;
          *(_DWORD *)(v26 + 108) = 2147483648;
        }
        ++v21[2];
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
    while ( (signed int)v56 < v54->m_children.m_size );
    v5 = v49;
  }
  v33 = v4->m_parent;
  if ( v33 )
  {
    v34 = (char *)v33->m_name;
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
      v39 = (signed int *)(v5 + 144);
      v40 = v39[2];
      v41 = v40 + 1;
      v42 = v39[3] & 0x3FFFFFFF;
      if ( v42 >= (signed int)v40 + 1 )
      {
        LODWORD(v54) = 0;
      }
      else
      {
        v43 = 2 * v42;
        if ( v41 < v43 )
          v41 = v43;
        hkArrayUtil::_reserve(
          (hkResult *)&v54,
          (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr,
          v39,
          v41,
          144);
      }
      v44 = *(_QWORD *)v39 + 144i64 * v39[2];
      if ( v44 )
      {
        *(_QWORD *)(v44 + 96) = 0i64;
        *(_DWORD *)(v44 + 104) = 0;
        *(_DWORD *)(v44 + 108) = 2147483648;
      }
      ++v39[2];
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
  signed __int64 v3; // rbx
  hkMonitorStreamAnalyzer::Node *v4; // rdi
  hkOstream *v5; // rsi
  signed __int64 v6; // r10
  unsigned int v7; // eax
  unsigned int *v8; // r9
  const char *v9; // r9
  int v10; // eax
  int v11; // eax
  __m128d v12; // xmm2
  __int64 v13; // [rsp+20h] [rbp-118h]
  char buf; // [rsp+30h] [rbp-108h]

  v3 = 0i64;
  v4 = node;
  v5 = outstream;
  v6 = 12i64;
  v7 = 0;
  v8 = node->m_count;
  do
  {
    if ( *v8 && *v8 > v7 )
      v7 = *v8;
    ++v8;
    --v6;
  }
  while ( v6 );
  v9 = node->m_name;
  if ( maxMem <= 0.0 )
  {
    LODWORD(v13) = v7;
    v10 = hkString::snprintf(&buf, 200, "%s (%i)", v9, v13);
  }
  else
  {
    LODWORD(v13) = v7;
    v10 = hkString::snprintf(&buf, 200, "%s (%i) %4.1f%%", v9, v13, (float)((float)(node->m_value[1] * 100.0) / maxMem));
  }
  hkOstream::printf(v5, "%-34s%s", v10);
  do
  {
    if ( v4->m_count[v3] )
    {
      v12 = _mm_cvtps_pd((__m128)LODWORD(v4->m_value[v3]));
      hkOstream::printf(v5, "% 12.3f: ", v11);
    }
    ++v3;
  }
  while ( v3 < 12 );
  hkOstream::printf(v5, "\n", v11);
}

// File Line: 1252
// RVA: 0xC7B0B0
void __fastcall printStatisticsByType(hkOstream *outstream, hkMonitorStreamAnalyzer::Node *rootNode, float maxImportance)
{
  hkOstream *v3; // rdi
  hkMonitorStreamAnalyzer::Node *v4; // rbx
  int v5; // er9
  Dummy *v6; // rbx
  unsigned __int64 v7; // rax
  float v8; // xmm8_4
  int v9; // eax
  int v10; // eax
  int v11; // eax
  __int64 i; // r14
  hkMonitorStreamAnalyzerPrintByTypeInfo *v13; // rbx
  int v14; // eax
  int v15; // eax
  int j; // esi
  int v17; // eax
  int k; // esi
  _QWORD **v19; // rax
  hkpEntity **array; // [rsp+28h] [rbp-19h]
  int v21; // [rsp+30h] [rbp-11h]
  int v22; // [rsp+34h] [rbp-Dh]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v23; // [rsp+38h] [rbp-9h]
  hkResult result; // [rsp+C0h] [rbp+7Fh]

  v3 = outstream;
  v4 = rootNode;
  array = 0i64;
  v21 = 0;
  v22 = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v23,
    0);
  hkBuildSizePerName(v4, (hkStringMap<hkMonitorStreamAnalyzerPrintByTypeInfo *,hkContainerHeapAllocator> *)&v23);
  v5 = v23.m_numElems;
  if ( v23.m_numElems > 0 )
  {
    if ( v23.m_numElems < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v5, 8);
  }
  v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v23);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v23,
    (hkBool *)&result,
    v6);
  while ( LOBYTE(result.m_enum) )
  {
    v7 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v23,
           v6);
    array[v21++] = (hkpEntity *)v7;
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v23,
           v6);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v23,
      (hkBool *)&result,
      v6);
  }
  if ( v21 > 1 )
    hkAlgorithm::quickSortRecursive<hkMonitorStreamAnalyzerPrintByTypeInfo *,bool (*)(hkMonitorStreamAnalyzerPrintByTypeInfo const *,hkMonitorStreamAnalyzerPrintByTypeInfo const *)>(
      array,
      0,
      v21 - 1,
      (bool (__fastcall *)(hkpEntity *, hkpEntity *))hkCompareInfosBySize);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v23);
  v8 = *((float *)&array[v21 - 1]->vfptr + 1);
  hkOstream::printf(v3, "\n\n", (int)array);
  hkOstream::printf(v3, "************************************\n", v9);
  hkOstream::printf(v3, "********** Per Type Times    *******\n", v10);
  hkOstream::printf(v3, "************************************\n", v11);
  for ( i = v21 - 1; i >= 0; --i )
  {
    v13 = (hkMonitorStreamAnalyzerPrintByTypeInfo *)array[i];
    if ( (float)(v8 * maxImportance) < v13->m_this.m_value[1] )
    {
      hkOstream::printf(v3, "\n", (int)array);
      hkOstream::printf(v3, "************************************\n\n", v14);
      for ( j = 0; j < v13->m_parents.m_size; ++j )
      {
        hkOstream::printf(v3, "\t\t", v15);
        printSingleNodeValues(v3, 0.0, &v13->m_parents.m_data[j]);
      }
      printSingleNodeValues(v3, v8, &v13->m_this);
      for ( k = 0; k < v13->m_children.m_size; ++k )
      {
        hkOstream::printf(v3, "\t\t", v17);
        printSingleNodeValues(v3, 0.0, &v13->m_children.m_data[k]);
      }
    }
    hkMonitorStreamAnalyzerPrintByTypeInfo::~hkMonitorStreamAnalyzerPrintByTypeInfo(v13);
    v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzerPrintByTypeInfo *, signed __int64))(*v19[12] + 16i64))(
      v19[12],
      v13,
      176i64);
  }
  v21 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v22);
}

// File Line: 1308
// RVA: 0xC77F90
void __fastcall hkMonitorStreamAnalyzer::writeStatisticsDetails(hkOstream *outstream, hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodes, int numThreads, int numSpus, int reportLevel, const char *nodeIdForFrameOverview, bool showMultithreadedSummary)
{
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v7; // rsi
  hkOstream *v8; // rbx
  float v9; // xmm7_4
  hkMonitorStreamAnalyzer::Node *v10; // r12
  int v11; // er14
  float v12; // xmm6_4
  __int64 v13; // rdi
  const char *v14; // r14
  hkMonitorStreamAnalyzer::Node *v15; // rax
  char v16; // r15
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // er13
  __int64 v27; // rcx
  hkMonitorStreamAnalyzer::Node **v28; // rax
  hkMonitorStreamAnalyzer::Node *v29; // rdi
  float v30; // xmm6_4
  hkMonitorStreamAnalyzer::Node *i; // rax
  const char *v32; // r15
  int v33; // eax
  int v34; // er9
  int *v35; // r8
  signed int v36; // ecx
  int v37; // ecx
  int *v38; // rdi
  __int64 v39; // rdx
  int v40; // er9
  int v41; // ecx
  _BYTE *v42; // r8
  void *v43; // rdi
  void *v44; // rdi
  int v45; // eax
  int v46; // edx
  int v47; // er12
  hkMonitorStreamAnalyzer::Node **v48; // rax
  __int64 v49; // r13
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // edi
  LPVOID v54; // rax
  hkLifoAllocator *v55; // rcx
  hkMonitorStreamAnalyzer::Node **v56; // rax
  int v57; // edx
  char *v58; // r8
  int v59; // er15
  unsigned int v60; // edi
  int v61; // edi
  int v62; // er9
  int v63; // er14
  __int64 v64; // rdi
  _QWORD **v65; // rax
  hkMonitorStreamAnalyzer::Node *v66; // rax
  hkMonitorStreamAnalyzer::Node *v67; // rax
  hkMonitorStreamAnalyzer::Node *v68; // rcx
  hkMonitorStreamAnalyzer::Node *v69; // rdx
  int v70; // edi
  signed __int64 v71; // r14
  int v72; // er15
  __int64 v73; // r14
  hkMonitorStreamAnalyzer::Node *v74; // rdi
  _QWORD **v75; // rax
  int v76; // eax
  char *v77; // r14
  signed int v78; // edi
  hkLifoAllocator *v79; // rax
  int v80; // er8
  int v81; // er12
  __int64 v82; // r13
  int v83; // edi
  __int64 v84; // r14
  hkMonitorStreamAnalyzer::Node *v85; // r15
  int v86; // eax
  int v87; // eax
  int v88; // eax
  int v89; // eax
  hkMonitorStreamAnalyzer::Node **v90; // rax
  const char *v91; // r8
  int v92; // er14
  __int64 v93; // r13
  int v94; // edi
  __int64 v95; // r12
  hkMonitorStreamAnalyzer::Node *v96; // r15
  int v97; // eax
  int v98; // eax
  const char *v99; // rdx
  int v100; // eax
  hkMonitorStreamAnalyzer::Node **v101; // rax
  const char *v102; // r8
  hkMonitorStreamAnalyzer::Node **array; // [rsp+30h] [rbp-D0h]
  int v104; // [rsp+38h] [rbp-C8h]
  int v105; // [rsp+3Ch] [rbp-C4h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v107; // [rsp+48h] [rbp-B8h]
  __int64 v108; // [rsp+50h] [rbp-B0h]
  int dst; // [rsp+58h] [rbp-A8h]
  int v110; // [rsp+5Ch] [rbp-A4h]
  int v111; // [rsp+60h] [rbp-A0h]
  int v112; // [rsp+64h] [rbp-9Ch]
  char v113; // [rsp+68h] [rbp-98h]
  __int64 v114; // [rsp+70h] [rbp-90h]
  int v115; // [rsp+78h] [rbp-88h]
  char v116; // [rsp+80h] [rbp-80h]
  hkMonitorStreamAnalyzer::Node sum; // [rsp+90h] [rbp-70h]
  void *retaddr; // [rsp+1A8h] [rbp+A8h]
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *result; // [rsp+1B8h] [rbp+B8h]
  int numThreadsa; // [rsp+1C0h] [rbp+C0h]
  int numSpusa; // [rsp+1C8h] [rbp+C8h]

  numSpusa = numSpus;
  numThreadsa = numThreads;
  result = nodes;
  v7 = nodes;
  v8 = outstream;
  hkOstream::printf(outstream, "Havok version: %s\n", (unsigned __int64)&retaddr);
  v9 = 0.0;
  v10 = *v7->m_data;
  hkMonitorStreamAnalyzer::Node::Node(&sum, 0i64, "Sum", NODE_TYPE_DIRECTORY);
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
  v15 = hkFindChildByName(&sum, nodeIdForFrameOverview, (hkBool)1);
  if ( !v15 )
    goto LABEL_102;
  do
  {
    v9 = v9 + (float)(v12 * v15->m_value[0]);
    v15 = hkFindNextChildByName(&sum, v14, v15);
  }
  while ( v15 );
  if ( v9 <= 0.0 )
LABEL_102:
    v9 = FLOAT_1000_0;
  v16 = reportLevel;
  if ( reportLevel & 1 )
  {
    hkOstream::printf(v8, "\n\n", (int)v15);
    hkOstream::printf(v8, "*********************************\n", v17);
    hkOstream::printf(v8, "********** Total Times    *******\n", v18);
    hkOstream::printf(v8, "*********************************\n", v19);
    hkOstream::printf(v8, "Timers are added together\n", v20);
    hkWriteRec(v8, &sum, 0, v12);
  }
  hkMonitorStreamAnalyzer::Node::~Node(&sum);
  if ( v16 & 2 )
  {
    hkOstream::printf(v8, "\n\n", v21);
    hkOstream::printf(v8, "*********************************\n", v22);
    hkOstream::printf(v8, "********** Per Frame Time *******\n", v23);
    hkOstream::printf(v8, "*********************************\n", v24);
    hkOstream::printf(v8, "Ascii Art all frames overview\n", v25);
    hkString::memSet(&dst, 32, 40);
    v26 = 0;
    v116 = 0;
    if ( v10->m_children.m_size > 0 )
    {
      v27 = 0i64;
      v108 = 0i64;
      do
      {
        v28 = v10->m_children.m_data;
        v29 = *(hkMonitorStreamAnalyzer::Node **)((char *)v28 + v27);
        if ( v29->m_children.m_size )
        {
          v30 = 0.0;
          for ( i = hkFindChildByName(*(hkMonitorStreamAnalyzer::Node **)((char *)v28 + v27), v14, (hkBool)1);
                i;
                i = hkFindNextChildByName(v29, v14, i) )
          {
            v32 = i->m_name;
            v30 = v30 + i->m_value[0];
          }
          v33 = (signed int)(float)((float)(v30 * 20.0) / v9);
          if ( v33 >= 0 )
          {
            if ( v33 >= 40 )
              v33 = 39;
          }
          else
          {
            v33 = 0;
          }
          v34 = 0;
          v35 = &dst;
          if ( v33 > 4 )
          {
            v36 = 4;
            do
            {
              v36 += 4;
              *(_BYTE *)v35 = 9;
              v35 = (int *)((char *)v35 + 1);
              v34 += 4;
            }
            while ( v36 < v33 );
          }
          v37 = v34;
          if ( v34 < v33 )
          {
            v38 = v35;
            v39 = (unsigned int)(v33 - v34);
            v33 = 32;
            v35 = (int *)((char *)v35 + v39);
            memset(v38, 32, (unsigned int)v39);
            v37 = v39 + v34;
          }
          v40 = v34 + 4;
          v41 = v37 + 1;
          *(_BYTE *)v35 = 35;
          v42 = (char *)v35 + 1;
          if ( v41 < v40 )
          {
            v43 = v42;
            v33 = 32;
            v42 += (unsigned int)(v40 - v41);
            memset(v43, 32, (unsigned int)(v40 - v41));
          }
          if ( v40 < 40 )
          {
            v44 = v42;
            v33 = 9;
            v42 += ((unsigned int)(39 - v40) >> 2) + 1;
            memset(v44, 9, ((unsigned int)(39 - v40) >> 2) + 1);
          }
          *v42 = 0;
          hkOstream::printf(v8, (const char *)&dst, v33);
          hkOstream::printf(v8, "%i %-12s %f\n", v45, v30);
          v27 = v108;
        }
        v27 += 8i64;
        ++v26;
        v108 = v27;
      }
      while ( v26 < v10->m_children.m_size );
      v7 = result;
      v16 = reportLevel;
    }
  }
  if ( v16 & 4 )
  {
    v46 = v7->m_size;
    if ( v46 != 1 && showMultithreadedSummary )
    {
      v47 = 0;
      if ( (*v7->m_data)->m_children.m_size > 0 )
      {
        LODWORD(v48) = v16 & 8;
        v49 = 0i64;
        LODWORD(v108) = v16 & 8;
        do
        {
          hkOstream::printf(v8, "\n", (int)v48);
          hkOstream::printf(v8, "****************************************\n", v50);
          hkOstream::printf(v8, "****** Summary Frame:%i ******\n", v51);
          hkOstream::printf(v8, "****************************************\n", v52);
          v53 = v7->m_size;
          array = 0i64;
          v104 = 0;
          v105 = 2147483648;
          v107 = v53;
          if ( v53 )
          {
            v54 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v55 = (hkLifoAllocator *)v54;
            v56 = (hkMonitorStreamAnalyzer::Node **)*((_QWORD *)v54 + 3);
            v57 = (8 * v53 + 127) & 0xFFFFFF80;
            v58 = (char *)v56 + v57;
            if ( v57 > v55->m_slabSize || v58 > v55->m_end )
              v56 = (hkMonitorStreamAnalyzer::Node **)hkLifoAllocator::allocateFromNewSlab(v55, v57);
            else
              v55->m_cur = v58;
          }
          else
          {
            v56 = 0i64;
          }
          v59 = v7->m_size;
          v60 = v53 | 0x80000000;
          array = v56;
          v105 = v60;
          v61 = v60 & 0x3FFFFFFF;
          p = v56;
          if ( v61 >= v59 )
          {
            LODWORD(result) = 0;
          }
          else
          {
            v62 = v59;
            if ( v59 < 2 * v61 )
              v62 = 2 * v61;
            hkArrayUtil::_reserve(
              (hkResult *)&result,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &array,
              v62,
              8);
            v56 = array;
          }
          v63 = 0;
          v104 = v59;
          if ( v7->m_size > 0 )
          {
            v64 = 0i64;
            do
            {
              v65 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v66 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v65[11] + 8i64))(
                                                       v65[11],
                                                       144i64);
              if ( v66 )
              {
                hkMonitorStreamAnalyzer::Node::Node(v66, 0i64, &customWorldMapCaption, NODE_TYPE_DIRECTORY);
                v68 = v67;
              }
              else
              {
                v68 = 0i64;
              }
              array[v64] = v68;
              v69 = v7->m_data[v64];
              if ( v69->m_children.m_size > v47 )
                hkMakeSumRecursive(v68, v69->m_children.m_data[v49]);
              ++v63;
              ++v64;
            }
            while ( v63 < v7->m_size );
            v59 = v104;
            v56 = array;
          }
          v70 = 1;
          dst = 0;
          v114 = 0i64;
          v115 = 24382;
          v111 = 4;
          v112 = 2;
          v110 = 16;
          v113 = 0;
          if ( v59 > 1 )
          {
            v71 = 1i64;
            do
            {
              hkMonitorStreamAnalyzer::mergeTreesForCombinedThreadSummary(*v56, v56[v71], v70, 0, 0.0);
              v56 = array;
              ++v70;
              ++v71;
            }
            while ( v70 < v104 );
          }
          hkMonitorStreamAnalyzer::showCombinedThreadSummaryForSingleFrame(
            *v56,
            numThreadsa,
            numSpusa,
            v8,
            (hkMonitorStreamAnalyzer::CombinedThreadSummaryOptions *)&dst);
          if ( (_DWORD)v108 )
            printStatisticsByType(v8, *array, 0.0099999998);
          v72 = 0;
          if ( v7->m_size > 0 )
          {
            v73 = 0i64;
            do
            {
              v74 = array[v73];
              if ( v74 )
              {
                hkMonitorStreamAnalyzer::Node::~Node(array[v73]);
                v75 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzer::Node *, signed __int64))(*v75[11] + 16i64))(
                  v75[11],
                  v74,
                  144i64);
              }
              ++v72;
              ++v73;
            }
            while ( v72 < v7->m_size );
          }
          v76 = v104;
          v77 = (char *)p;
          if ( p == array )
            v76 = 0;
          v104 = v76;
          v78 = (8 * v107 + 127) & 0xFFFFFF80;
          v79 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v80 = (v78 + 15) & 0xFFFFFFF0;
          if ( v78 > v79->m_slabSize || &v77[v80] != v79->m_cur || v79->m_firstNonLifoEnd == v77 )
            hkLifoAllocator::slowBlockFree(v79, v77, v80);
          else
            v79->m_cur = v77;
          v104 = 0;
          if ( v105 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array,
              8 * v105);
          v48 = v7->m_data;
          ++v47;
          ++v49;
        }
        while ( v47 < (*v7->m_data)->m_children.m_size );
      }
    }
    else
    {
      v81 = 0;
      if ( (*v7->m_data)->m_children.m_size > 0 )
      {
        v82 = 0i64;
        do
        {
          v83 = 0;
          if ( v46 > 0 )
          {
            v84 = 0i64;
            do
            {
              v85 = v7->m_data[v84];
              if ( v81 < v85->m_children.m_size )
              {
                hkMonitorStreamAnalyzer::Node::Node(&sum, 0i64, "Sum", NODE_TYPE_DIRECTORY);
                hkMakeSumRecursive(&sum, v85->m_children.m_data[v82]);
                hkOstream::printf(v8, "\n", v86);
                hkOstream::printf(v8, "****************************************\n", v87);
                hkOstream::printf(v8, "****** Summary Frame:%i Thread:%i ******\n", v88);
                hkOstream::printf(v8, "****************************************\n", v89);
                v90 = v85->m_children.m_data;
                v91 = v90[v82]->m_name;
                hkOstream::printf(v8, "%s\n", (int)v90);
                hkWriteRec(v8, &sum, 0, 1.0);
                if ( reportLevel & 8 )
                  printStatisticsByType(v8, &sum, 0.0099999998);
                hkMonitorStreamAnalyzer::Node::~Node(&sum);
              }
              v46 = v7->m_size;
              ++v83;
              ++v84;
            }
            while ( v83 < v46 );
          }
          ++v81;
          ++v82;
        }
        while ( v81 < (*v7->m_data)->m_children.m_size );
      }
    }
  }
  if ( reportLevel & 0x10 )
  {
    v92 = 0;
    if ( (*v7->m_data)->m_children.m_size > 0 )
    {
      v93 = 0i64;
      do
      {
        v94 = 0;
        if ( v7->m_size > 0 )
        {
          v95 = 0i64;
          reportLevel = -numThreadsa;
          do
          {
            v96 = v7->m_data[v95];
            if ( v92 < v96->m_children.m_size )
            {
              hkOstream::printf(v8, "\n\n", (int)v7->m_data);
              hkOstream::printf(v8, "***************************************\n", v97);
              if ( v94 >= numThreadsa )
                v99 = "***** Details Frame-%i Spu:%i ******\n";
              else
                v99 = "***** Details Frame-%i Thread:%i ******\n";
              hkOstream::printf(v8, v99, v98);
              hkOstream::printf(v8, "***************************************\n", v100);
              v101 = v96->m_children.m_data;
              v102 = v101[v93]->m_name;
              hkOstream::printf(v8, "%s\n", (int)v101);
              hkWriteRec(v8, v96->m_children.m_data[v93], 0, 1.0);
            }
            ++v94;
            ++v95;
          }
          while ( v94 < v7->m_size );
        }
        ++v92;
        ++v93;
      }
      while ( v92 < (*v7->m_data)->m_children.m_size );
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
  hkOstream *v7; // rsi
  __int64 v8; // rbx
  unsigned int v9; // edi
  signed __int64 v10; // rdx
  unsigned int *v11; // rcx
  const char *v12; // r9
  int v13; // eax
  int v14; // eax
  signed __int64 v15; // rbx
  signed __int64 v16; // rax
  signed int v17; // ecx
  int v18; // eax
  float v19; // xmm2_4
  const char *v20; // rdx
  int v21; // eax
  __int64 v22; // rbx
  __int64 v23; // [rsp+20h] [rbp-148h]
  __int64 v24; // [rsp+20h] [rbp-148h]
  char buf; // [rsp+40h] [rbp-128h]
  hkMonitorStreamAnalyzer::Node *v26; // [rsp+178h] [rbp+10h]
  int v27; // [rsp+180h] [rbp+18h]
  int v28; // [rsp+180h] [rbp+18h]

  v27 = RecDepth;
  v26 = node;
  v4 = 0;
  v5 = node;
  v6 = RecDepth;
  v7 = outstream;
  if ( RecDepth )
  {
    if ( RecDepth > 1 )
    {
      v8 = (unsigned int)(RecDepth - 1);
      do
      {
        hkOstream::printf(v7, "\t", v6);
        --v8;
      }
      while ( v8 );
    }
    v9 = 0;
    v10 = 12i64;
    v11 = v26->m_count;
    do
    {
      if ( *v11 )
      {
        ++v4;
        if ( *v11 > v9 )
          v9 = *v11;
      }
      ++v11;
      --v10;
    }
    while ( v10 );
    LODWORD(v23) = v9;
    hkString::snprintf(&buf, 200, "%s(%i)", v26->m_name, v23);
    v12 = v26->m_name;
    if ( v9 > 1 )
    {
      if ( factor == 1.0 )
      {
        LODWORD(v24) = v9;
        v13 = hkString::snprintf(&buf, 200, "%s (%i)", v12, v24);
      }
      else
      {
        v13 = hkString::snprintf(&buf, 200, "%s (%4.1f)", v12, (float)((float)(signed int)v9 * factor));
      }
    }
    else
    {
      v13 = hkString::snprintf(&buf, 200, "%s", v12);
    }
    hkOstream::printf(v7, "%-32s", v13);
    v15 = 3i64;
    do
    {
      hkOstream::printf(v7, "\t", v14);
      --v15;
    }
    while ( v15 );
    if ( v4 <= 0 )
    {
      hkOstream::printf(v7, "% 12.3f\n", v14);
    }
    else
    {
      v16 = (signed __int64)v26->m_count;
      do
      {
        v17 = *(_DWORD *)(v16 + 4 * v15);
        if ( v17 )
        {
          v18 = (signed int)v26;
          if ( v17 < v9 )
          {
            v18 = v9;
            v19 = (float)(factor * v26->m_value[v15]) * (float)((float)(signed int)v9 / (float)v17);
          }
          v20 = "% 12.3f: ";
          if ( !--v4 )
            v20 = "% 12.3f\n";
          hkOstream::printf(v7, v20, v18);
          v16 = (signed __int64)v26->m_count;
        }
        ++v15;
      }
      while ( v15 < 12 );
    }
    v6 = v27;
    v5 = v26;
    v4 = 0;
  }
  if ( v5->m_children.m_size > 0 )
  {
    v21 = v6 + 1;
    v22 = 0i64;
    v28 = v21;
    do
    {
      hkWriteRec(v7, v5->m_children.m_data[v22], v21, factor);
      v21 = v28;
      ++v4;
      ++v22;
    }
    while ( v4 < v5->m_children.m_size );
  }
}

// File Line: 1629
// RVA: 0xC7A920
hkMonitorStreamAnalyzer::Node *__fastcall hkFindChildByName(hkMonitorStreamAnalyzer::Node *node, const char *childName, hkBool searchAnyChild)
{
  int v3; // ebx
  const char *v4; // rbp
  hkMonitorStreamAnalyzer::Node *v5; // rdi
  __int64 v6; // rsi
  hkMonitorStreamAnalyzer::Node *result; // rax
  char v8; // [rsp+40h] [rbp+18h]

  v8 = searchAnyChild.m_bool;
  v3 = 0;
  v4 = childName;
  v5 = node;
  if ( node->m_children.m_size <= 0 )
  {
LABEL_6:
    if ( searchAnyChild.m_bool && v5->m_children.m_size > 0 )
      result = *v5->m_children.m_data;
    else
      result = 0i64;
  }
  else
  {
    v6 = 0i64;
    while ( (unsigned int)hkString::strCmp(v4, v5->m_children.m_data[v6]->m_name) )
    {
      ++v3;
      ++v6;
      if ( v3 >= v5->m_children.m_size )
      {
        searchAnyChild.m_bool = v8;
        goto LABEL_6;
      }
    }
    result = v5->m_children.m_data[v3];
  }
  return result;
}

// File Line: 1647
// RVA: 0xC7A9C0
hkMonitorStreamAnalyzer::Node *__fastcall hkFindNextChildByName(hkMonitorStreamAnalyzer::Node *node, const char *childName, hkMonitorStreamAnalyzer::Node *oldChild)
{
  __int64 v3; // r10
  int v4; // ebx
  const char *v5; // rbp
  hkMonitorStreamAnalyzer::Node *v6; // rsi
  __int64 v7; // r9
  hkMonitorStreamAnalyzer::Node **v8; // rax
  int v9; // ebx
  signed __int64 v10; // rdi

  v3 = node->m_children.m_size;
  v4 = 0;
  v5 = childName;
  v6 = node;
  v7 = 0i64;
  if ( (signed int)v3 > 0 )
  {
    v8 = node->m_children.m_data;
    do
    {
      if ( *v8 == oldChild )
        break;
      ++v7;
      ++v4;
      ++v8;
    }
    while ( v7 < v3 );
  }
  v9 = v4 + 1;
  if ( v9 >= (signed int)v3 )
    return 0i64;
  v10 = v9;
  while ( (unsigned int)hkString::strCmp(v5, v6->m_children.m_data[v10]->m_name) )
  {
    ++v9;
    ++v10;
    if ( v9 >= v6->m_children.m_size )
      return 0i64;
  }
  return v6->m_children.m_data[v9];
}

// File Line: 1673
// RVA: 0xC7A790
void __fastcall hkMakeSumRecursive(hkMonitorStreamAnalyzer::Node *sum, hkMonitorStreamAnalyzer::Node *tree)
{
  int v2; // edi
  hkMonitorStreamAnalyzer::Node *v3; // rbp
  __int64 v4; // rsi
  hkMonitorStreamAnalyzer::Node *v5; // rbx
  hkMonitorStreamAnalyzer::Node *v6; // r9
  _QWORD **v7; // rax
  hkMonitorStreamAnalyzer::Node *v8; // rax
  hkMonitorStreamAnalyzer::Node *v9; // rax
  signed __int64 v10; // rcx
  signed __int64 v11; // rdx
  signed __int64 v12; // r8
  float v13; // xmm0_4
  hkMonitorStreamAnalyzer::Node *parent; // [rsp+30h] [rbp+8h]

  parent = sum;
  v2 = 0;
  v3 = tree;
  if ( tree->m_children.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v3->m_children.m_data[v4];
      v6 = hkFindChildByName(sum, v5->m_name, 0);
      if ( !v6 )
      {
        v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v8 = (hkMonitorStreamAnalyzer::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                                v7[11],
                                                144i64);
        if ( v8 )
        {
          hkMonitorStreamAnalyzer::Node::Node(
            v8,
            parent,
            v5->m_name,
            (hkMonitorStreamAnalyzer::Node::NodeType)v5->m_type.m_storage);
          v6 = v9;
        }
        else
        {
          v6 = 0i64;
        }
      }
      v10 = (signed __int64)v6->m_count;
      v11 = 2i64;
      v12 = (char *)v5 - (char *)v6;
      do
      {
        v13 = *(float *)(v12 + v10 - 48);
        v10 += 24i64;
        *(float *)(v10 - 72) = v13 + *(float *)(v10 - 72);
        *(_DWORD *)(v10 - 24) += *(_DWORD *)(v12 + v10 - 24);
        *(float *)(v10 - 68) = *(float *)(v12 + v10 - 68) + *(float *)(v10 - 68);
        *(_DWORD *)(v10 - 20) += *(_DWORD *)(v12 + v10 - 20);
        *(float *)(v10 - 64) = *(float *)(v12 + v10 - 64) + *(float *)(v10 - 64);
        *(_DWORD *)(v10 - 16) += *(_DWORD *)(v12 + v10 - 16);
        *(float *)(v10 - 60) = *(float *)(v12 + v10 - 60) + *(float *)(v10 - 60);
        *(_DWORD *)(v10 - 12) += *(_DWORD *)(v12 + v10 - 12);
        *(float *)(v10 - 56) = *(float *)(v12 + v10 - 56) + *(float *)(v10 - 56);
        *(_DWORD *)(v10 - 8) += *(_DWORD *)(v12 + v10 - 8);
        *(float *)(v10 - 52) = *(float *)(v12 + v10 - 52) + *(float *)(v10 - 52);
        *(_DWORD *)(v10 - 4) += *(_DWORD *)(v12 + v10 - 4);
        --v11;
      }
      while ( v11 );
      hkMakeSumRecursive(v6, v5);
      sum = parent;
      ++v2;
      ++v4;
    }
    while ( v2 < v3->m_children.m_size );
  }
}

// File Line: 1689
// RVA: 0xC764E0
void __fastcall hkMonitorStreamAnalyzer::writeStatistics(hkMonitorStreamAnalyzer *this, hkOstream *outStream, int reportLevel)
{
  int v3; // ebx
  hkOstream *v4; // r14
  int v5; // ebp
  hkMonitorStreamAnalyzer *v6; // rdi
  hkMonitorStreamAnalyzer::Node *v7; // rax
  int v8; // edx
  hkMonitorStreamAnalyzer::Node *v9; // rsi
  int v10; // ecx
  int v11; // edi
  __int64 v12; // rbx
  __int64 v13; // rsi
  _QWORD **v14; // rax
  _QWORD *array; // [rsp+40h] [rbp-18h]
  int v16; // [rsp+48h] [rbp-10h]
  int i; // [rsp+4Ch] [rbp-Ch]

  v3 = 0;
  v4 = outStream;
  v5 = reportLevel;
  v6 = this;
  array = 0i64;
  v16 = 0;
  for ( i = 2147483648; v3 < v6->m_frameInfos.m_size; ++v16 )
  {
    v7 = hkMonitorStreamAnalyzer::makeStatisticsTreeForMultipleFrames(v6, v3, 0);
    v8 = v16;
    v9 = v7;
    if ( v16 == (i & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
      v8 = v16;
    }
    ++v3;
    array[v8] = v9;
  }
  hkMonitorStreamAnalyzer::writeStatisticsDetails(
    v4,
    (hkArrayBase<hkMonitorStreamAnalyzer::Node *> *)&array,
    v6->m_numThreads,
    v6->m_numSpus,
    v5,
    v6->m_nodeIdForFrameOverview,
    1);
  v10 = v16;
  v11 = 0;
  if ( v16 > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = array[v12];
      if ( v13 )
      {
        hkMonitorStreamAnalyzer::Node::~Node((hkMonitorStreamAnalyzer::Node *)array[v12]);
        v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v14[11] + 16i64))(v14[11], v13, 144i64);
        v10 = v16;
      }
      ++v11;
      ++v12;
    }
    while ( v11 < v10 );
  }
  v16 = 0;
  if ( i >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * i);
}

// File Line: 1746
// RVA: 0xC76650
void __fastcall hkMonitorStreamAnalyzer::writeRawStatistics(hkMonitorStreamAnalyzer *this, hkOstream *os)
{
  hkOstream *v2; // rsi
  hkMonitorStreamAnalyzer *v3; // rdi
  int v4; // ecx
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v5; // rax
  __int64 v6; // r9
  __int64 v7; // r8
  hkResultEnum v8; // eax
  __int64 v9; // r12
  hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator> *v10; // r13
  int v11; // er15
  __int64 v12; // r14
  hkMonitorStreamFrameInfo *v13; // rbx
  unsigned __int64 v14; // r8
  char *v15; // rax
  __int64 v16; // rdi
  unsigned __int64 v17; // rbx
  char *v18; // rdi
  int v19; // er9
  int v20; // edx
  int v21; // eax
  const char *v22; // rdx
  int v23; // ecx
  int v24; // ecx
  signed __int64 v25; // r9
  char *v26; // r9
  __int64 v27; // ST28_8
  __int64 v28; // ST20_8
  int v29; // ecx
  int v30; // ecx
  int v31; // edx
  __int64 v32; // rcx
  signed __int64 v33; // r9
  signed __int64 v34; // r9
  __int64 sizeElem; // [rsp+20h] [rbp-60h]
  __int64 sizeElema; // [rsp+20h] [rbp-60h]
  __int64 v37; // [rsp+28h] [rbp-58h]
  __int64 v38[2]; // [rsp+30h] [rbp-50h]
  _BYTE *array; // [rsp+40h] [rbp-40h]
  int v40; // [rsp+48h] [rbp-38h]
  int v41; // [rsp+4Ch] [rbp-34h]
  hkMonitorStreamAnalyzer *v42; // [rsp+90h] [rbp+10h]
  hkResult result; // [rsp+A0h] [rbp+20h]
  hkResult v44; // [rsp+A8h] [rbp+28h]

  v42 = this;
  v2 = os;
  v3 = this;
  array = 0i64;
  v40 = 0;
  v41 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, 64, 1);
  v4 = v40;
  if ( v40 == (v41 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, 1);
    v4 = v40;
  }
  array[v4] = 0;
  v5 = v3->m_frameInfos.m_data;
  ++v40;
  v6 = (unsigned int)v3->m_numSpus;
  v7 = (unsigned int)v3->m_numThreads;
  LODWORD(sizeElem) = v5->m_size;
  hkOstream::printf(v2, "StatisticsDumpInfo(num_threads=%i, num_spus=%i, num_frames=%i)\n", (int)v5, sizeElem);
  v8 = 0;
  result.m_enum = 0;
  if ( v3->m_frameInfos.m_size > 0 )
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = v3->m_frameInfos.m_data;
      v11 = 0;
      if ( v3->m_frameInfos.m_data[v9].m_size > 0 )
        break;
LABEL_36:
      ++v8;
      ++v9;
      result.m_enum = v8;
      if ( v8 >= v3->m_frameInfos.m_size )
        goto LABEL_37;
    }
    v12 = 0i64;
    while ( 1 )
    {
      v13 = v10[v9].m_data;
      LODWORD(v37) = v13[v12].m_absoluteTimeCounter.m_storage;
      v14 = (_QWORD)v13[v12].m_heading.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
      LODWORD(sizeElema) = v13[v12].m_threadId;
      hkOstream::printf(
        v2,
        "FrameInfo(heading=%s, frame=%i, thread_id=%i, time_counter=%i)\n",
        v13[v12].m_threadId,
        sizeElema,
        v37);
      v15 = v3->m_data.m_data;
      v16 = v13[v12].m_frameStreamStart;
      v17 = (unsigned __int64)&v15[v13[v12].m_frameStreamEnd];
      v18 = &v15[v16];
      if ( (v41 & 0x3FFFFFFF) >= 1 )
      {
        v44.m_enum = 0;
      }
      else
      {
        v19 = 1;
        if ( 2 * (v41 & 0x3FFFFFFF) > 1 )
          v19 = 2 * (v41 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v44, (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, v19, 1);
      }
      v40 = 1;
      *array = 0;
      if ( (unsigned __int64)v18 < v17 )
        break;
LABEL_34:
      v3 = v42;
      ++v11;
      ++v12;
      if ( v11 >= v10[v9].m_size )
      {
        v8 = result.m_enum;
        goto LABEL_36;
      }
    }
    v20 = v40;
    while ( 2 )
    {
      v21 = **(char **)v18;
      switch ( v21 )
      {
        case 69:
          v40 = v20 - 2;
          array[v20 - 3] = 0;
          LODWORD(v37) = *((_DWORD *)v18 + 3);
          v25 = *(_QWORD *)v18 + 2i64;
          LODWORD(sizeElema) = *((_DWORD *)v18 + 2);
          hkOstream::printf(v2, "%sTimerEnd(%s,%u,%u)\n", *((_DWORD *)v18 + 2), sizeElema, v37);
          v18 += 16;
          goto LABEL_32;
        case 70:
        case 79:
        case 80:
        case 112:
          goto $LN14_97;
        case 76:
          LODWORD(v37) = *((_DWORD *)v18 + 3);
          LODWORD(sizeElema) = *((_DWORD *)v18 + 2);
          hkOstream::printf(v2, "%sTimerBegin(%s, %u, %u)\n", *((_DWORD *)v18 + 2), sizeElema, v37);
          v26 = (char *)*((_QWORD *)v18 + 2);
          LODWORD(v27) = *((_DWORD *)v18 + 3);
          LODWORD(v28) = *((_DWORD *)v18 + 2);
          hkOstream::printf(v2, "%sTimerSplit(%s, %u, %u)\n", *((_DWORD *)v18 + 2), v28, v27);
          array[v40 - 1] = 32;
          v29 = v40;
          if ( v40 == (v41 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, 1);
            v29 = v40;
          }
          array[v29] = 32;
          v30 = v40 + 1;
          v40 = v30;
          if ( v30 == (v41 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, 1);
            v30 = v40;
          }
          array[v30] = 0;
          v20 = v40 + 1;
          v18 += 24;
          ++v40;
          goto $LN14_97;
        case 77:
          hkOstream::printf(v2, "%sAddValue(%s,%f)\n", v21, *((float *)v18 + 2));
          v18 += 16;
          goto LABEL_32;
        case 78:
          v18 += 8;
          goto $LN14_97;
        case 83:
          v31 = v20 - 2;
          v40 = v31;
          v32 = v31;
          v22 = "%sTimerSplit(%s, %u, %u)\n";
          array[v32 - 1] = 0;
          v33 = *(_QWORD *)v18 + 2i64;
          goto LABEL_16;
        case 84:
          v22 = "%sTimerBegin(%s,%u,%u)\n";
LABEL_16:
          LODWORD(v37) = *((_DWORD *)v18 + 3);
          LODWORD(sizeElema) = *((_DWORD *)v18 + 2);
          hkOstream::printf(v2, v22, *((_DWORD *)v18 + 2), sizeElema, v37);
          array[v40 - 1] = 32;
          v23 = v40;
          if ( v40 == (v41 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, 1);
            v23 = v40;
          }
          array[v23] = 32;
          v24 = v40 + 1;
          v40 = v24;
          if ( v24 == (v41 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr, &array, 1);
            v24 = v40;
          }
          array[v24] = 0;
          v20 = v40 + 1;
          v18 += 16;
          ++v40;
          goto $LN14_97;
        case 108:
          v40 = v20 - 2;
          array[v20 - 3] = 0;
          LODWORD(v37) = *((_DWORD *)v18 + 3);
          v34 = *(_QWORD *)v18 + 2i64;
          LODWORD(sizeElema) = *((_DWORD *)v18 + 2);
          hkOstream::printf(v2, "%sTimerEnd(%s, %u, %u)\n", *((_DWORD *)v18 + 2), sizeElema, v37);
          v18 += 16;
          goto LABEL_32;
        case 109:
          *((_DWORD *)v18 + 4);
          LODWORD(v38[0]) = *((_DWORD *)v18 + 4) & 0x7FFFFFFF;
          hkOstream::printf(
            v2,
            "%s%s%s(ptr=0x%p, nbytes=%i)\n",
            *((_QWORD *)v18 + 1),
            *(_QWORD *)v18 + 1i64,
            *((_QWORD *)v18 + 1),
            v38[0]);
          v18 += 24;
LABEL_32:
          v20 = v40;
$LN14_97:
          if ( (unsigned __int64)v18 >= v17 )
            goto LABEL_34;
          continue;
        default:
          goto LABEL_37;
      }
    }
  }
LABEL_37:
  v40 = 0;
  if ( v41 >= 0 )
    hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
      array,
      v41 & 0x3FFFFFFF);
}

// File Line: 1878
// RVA: 0xC7C1B0
hkMonitorStreamAnalyzer::Node *__fastcall findChildNode(hkMonitorStreamAnalyzer::Node *currentNode, long double sampleTime, int absoluteTimeIndex)
{
  int v3; // er9
  __int64 v4; // rdi
  __int64 v5; // rsi
  hkMonitorStreamAnalyzer::Node *v6; // rbx
  int v7; // er10
  hkMonitorStreamAnalyzer::Node **v8; // r11
  hkMonitorStreamAnalyzer::Node *v9; // rcx
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  __int64 v12; // rcx

  v3 = currentNode->m_children.m_size;
  v4 = 0i64;
  v5 = absoluteTimeIndex;
  v6 = currentNode;
  v7 = 0;
  if ( v3 > 2 )
  {
    v8 = currentNode->m_children.m_data;
    do
    {
      v9 = v8[(v3 + v7) >> 1];
      if ( v9->m_type.m_storage == 2 )
        break;
      if ( sampleTime >= v9->m_absoluteStartTime )
        v7 = (v3 + v7) >> 1;
      else
        v3 = (v3 + v7) >> 1;
    }
    while ( v3 - v7 > 2 );
  }
  v10 = v7;
  if ( v7 >= (signed __int64)v3 )
    return 0i64;
  v11 = (signed __int64)&v6->m_children.m_data[v7];
  while ( 1 )
  {
    v12 = *(_QWORD *)v11;
    if ( *(_DWORD *)(*(_QWORD *)v11 + 140i64) != 2 && sampleTime <= *(float *)(v12 + 4 * v5) + *(double *)(v12 + 112) )
      break;
    ++v10;
    v11 += 8i64;
    if ( v10 >= v3 )
      return 0i64;
  }
  if ( sampleTime >= *(double *)(v12 + 112) )
    v4 = *(_QWORD *)v11;
  return (hkMonitorStreamAnalyzer::Node *)v4;
}

// File Line: 1926
// RVA: 0xC7B3C0
hkMonitorStreamAnalyzer::Node *__fastcall getNodeAtSample(hkMonitorStreamAnalyzer::Node *currentNode, hkMonitorStreamAnalyzer::Node *lastHit, long double sampleTime, int absoluteTimeIndex)
{
  int v4; // edi
  hkMonitorStreamAnalyzer::Node *v5; // rbx
  hkMonitorStreamAnalyzer::Node *v6; // rax

  v4 = absoluteTimeIndex;
  v5 = currentNode;
  if ( lastHit && lastHit->m_value[absoluteTimeIndex] + lastHit->m_absoluteStartTime >= sampleTime )
    v5 = lastHit;
  if ( v5 )
  {
    while ( 1 )
    {
      v6 = findChildNode(v5, sampleTime, v4);
      if ( !v6 )
        break;
      v5 = v6;
    }
  }
  return v5;
}

// File Line: 1958
// RVA: 0xC7B440
void __fastcall outputStatsForFrame(hkMonitorStreamAnalyzer::Node *root, float startTime, float timeInc, int maxFrames, hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *timerNodesAtTicks, int absoluteTimeIndex)
{
  hkMonitorStreamAnalyzer::Node **v6; // r8
  hkMonitorStreamAnalyzer::Node *v7; // rbp
  hkMonitorStreamAnalyzer::Node *v8; // rdi
  int v9; // er14
  float v10; // xmm9_4
  hkMonitorStreamAnalyzer::Node *v11; // r15
  int v12; // edx
  hkMonitorStreamAnalyzer::Node **v13; // rax
  hkMonitorStreamAnalyzer::Node *v14; // rsi
  int v15; // eax
  __int64 v16; // rcx
  hkMonitorStreamAnalyzer::Node **v17; // rax
  double v18; // xmm6_8
  double v19; // xmm7_8
  double v20; // xmm1_8
  long double v21; // xmm7_8
  double v22; // xmm7_8

  v6 = root->m_children.m_data;
  v7 = 0i64;
  v8 = *v6;
  v9 = maxFrames;
  v10 = startTime;
  v11 = root;
  v12 = 0;
  if ( *v6 )
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
  v14 = v6[root->m_children.m_size - 1];
  v15 = root->m_children.m_size - 1;
  v16 = v15;
  if ( v14 )
  {
    v17 = &v6[v15];
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
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              timerNodesAtTicks,
              8);
          timerNodesAtTicks->m_data[timerNodesAtTicks->m_size++] = 0i64;
          --v9;
        }
        while ( v9 );
      }
      v20 = v8->m_absoluteStartTime;
      v21 = v14->m_value[absoluteTimeIndex] + v14->m_absoluteStartTime;
      v11->m_absoluteStartTime = v20;
      v22 = v21 - v10;
      for ( v11->m_value[absoluteTimeIndex] = v10 + v22 - v20 + 1.0; v9; --v9 )
      {
        if ( v22 <= v18 )
          break;
        v7 = getNodeAtSample(v11, v7, v10 + v18, absoluteTimeIndex);
        if ( v7 )
        {
          if ( timerNodesAtTicks->m_size == (timerNodesAtTicks->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              timerNodesAtTicks,
              8);
          timerNodesAtTicks->m_data[timerNodesAtTicks->m_size++] = v7;
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
  hkMonitorStreamColorTable *v1; // rbx

  v1 = this;
  hkMonitorStreamColorTable::addColor(this, "Physics 2012", hkColor::GREY25);
  hkMonitorStreamColorTable::addColor(v1, "NarrowPhase", hkColor::CORNFLOWERBLUE);
  hkMonitorStreamColorTable::addColor(v1, "Broadphase", hkColor::BLUE);
  hkMonitorStreamColorTable::addColor(v1, "3AxisSweep", hkColor::MIDNIGHTBLUE);
  hkMonitorStreamColorTable::addColor(v1, "WaitForExport", hkColor::DARKSLATEBLUE);
  hkMonitorStreamColorTable::addColor(v1, "SplitIsle", hkColor::BROWN);
  hkMonitorStreamColorTable::addColor(v1, "PostCollide", hkColor::BEIGE);
  hkMonitorStreamColorTable::addColor(v1, "Maintenance", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "InterIsland", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "PendingOps", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "ConstraintCallbacks", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "SingleObj", hkColor::TAN);
  hkMonitorStreamColorTable::addColor(v1, "TOIs", hkColor::GOLD);
  hkMonitorStreamColorTable::addColor(v1, "PostSimCB", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(v1, "Integrate", hkColor::GREEN);
  hkMonitorStreamColorTable::addColor(v1, "Actions", hkColor::SPRINGGREEN);
  hkMonitorStreamColorTable::addColor(v1, "SetupJobs", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "BuildJacTask", hkColor::SEAGREEN);
  hkMonitorStreamColorTable::addColor(v1, "BuildAccumulators", hkColor::OLIVE);
  hkMonitorStreamColorTable::addColor(v1, "BuildJacobians", hkColor::FORESTGREEN);
  hkMonitorStreamColorTable::addColor(v1, "Solver", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "Solve", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "IntegrateMotions", hkColor::LIGHTGREEN);
  hkMonitorStreamColorTable::addColor(v1, "SolverExport", hkColor::DARKSEAGREEN);
  hkMonitorStreamColorTable::addColor(v1, "GetNextJob", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "GetNextTask", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "FinishJob", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "FinishTask", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "FinishJobAndGetNext", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "FinishTaskAndGetNext", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "WaitForSignal", hkColor::MAROON);
  hkMonitorStreamColorTable::addColor(v1, "WaitForTasks", hkColor::MAROON);
  hkMonitorStreamColorTable::addColor(v1, "LockQueue", hkColor::RED);
  hkMonitorStreamColorTable::addColor(v1, "CriticalLock", hkColor::CRIMSON);
  hkMonitorStreamColorTable::addColor(v1, "hkSpuMoppRaycastQuery", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "VehicleManager", hkColor::PALEGOLDENROD);
  hkMonitorStreamColorTable::addColor(v1, "Vehicle", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(v1, "VehicleJob", hkColor::DARKKHAKI);
  hkMonitorStreamColorTable::addColor(v1, "ApplyVehicleForces", hkColor::KHAKI);
  hkMonitorStreamColorTable::addColor(v1, "Physics", 0xFFFFB300);
  hkMonitorStreamColorTable::addColor(v1, "PreCollide", hkColor::BEIGE);
  hkMonitorStreamColorTable::addColor(v1, "DispatchCommands", hkColor::GOLD);
  hkMonitorStreamColorTable::addColor(v1, "PostCollideEvent", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(v1, "BroadPhaseTask", hkColor::BLUE);
  hkMonitorStreamColorTable::addColor(v1, "NarrowPhaseTask", hkColor::CORNFLOWERBLUE);
  hkMonitorStreamColorTable::addColor(v1, "GatherConstraintsTask", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "ConstraintSetupTask", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "PreSolve", hkColor::OLIVE);
  hkMonitorStreamColorTable::addColor(v1, "SolverTask", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "SolveConstraints", hkColor::LIGHTGREEN);
  hkMonitorStreamColorTable::addColor(v1, "SubIntegrate", hkColor::LIMEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "UpdateBodies", hkColor::DARKSEAGREEN);
  hkMonitorStreamColorTable::addColor(v1, "PostSolve", hkColor::OLIVE);
  hkMonitorStreamColorTable::addColor(v1, "PostSimulateEvent", hkColor::WHEAT);
  hkMonitorStreamColorTable::addColor(v1, "WaitForMainThread", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "WaitForWorkerThreads", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "WaitForOtherTasks", hkColor::DARKRED);
  hkMonitorStreamColorTable::addColor(v1, "ReleaseSemaphore", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "ReleaseSemaphore_1", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "ReleaseSemaphore_2", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "ReleaseSemaphore_3", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "ReleaseSemaphore_4", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "ReleaseSemaphore_5+", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "hkaQuantizedSampleAndCombineJob", hkColor::ORCHID);
  hkMonitorStreamColorTable::addColor(v1, "SampleAndBlend", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "hkaCpuSampleAnimationJob", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "hkaCpuSampleAndCombineJob", hkColor::PALEGREEN);
  hkMonitorStreamColorTable::addColor(v1, "SpuAnim", hkColor::LIGHTBLUE);
  hkMonitorStreamColorTable::addColor(v1, "Cloth", hkColor::MEDIUMPURPLE);
  hkMonitorStreamColorTable::addColor(v1, "Simulate", hkColor::LIGHTGREEN);
  hkMonitorStreamColorTable::addColor(v1, "Accumulate Actions", hkColor::SPRINGGREEN);
  hkMonitorStreamColorTable::addColor(v1, "Collide", hkColor::DARKGREEN);
  hkMonitorStreamColorTable::addColor(v1, "Collide And Solve", hkColor::DARKGREEN);
  hkMonitorStreamColorTable::addColor(v1, "Input Conversion", hkColor::PINK);
  hkMonitorStreamColorTable::addColor(v1, "Output Conversion", hkColor::PINK);
  hkMonitorStreamColorTable::addColor(v1, "Mesh Mesh Deform", hkColor::LIGHTBLUE);
  hkMonitorStreamColorTable::addColor(v1, "Mesh Bone Deform", hkColor::LIGHTBLUE);
  hkMonitorStreamColorTable::addColor(v1, "Skin", hkColor::BLUE);
  hkMonitorStreamColorTable::addColor(v1, "Gather All Vertices", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "Gather Some Vertices", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "Copy Vertices", hkColor::YELLOW);
  hkMonitorStreamColorTable::addColor(v1, "Recalculate Some Normals", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Recalculate All Normals", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Update Some Vertex Frames (N)", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Update Some Vertex Frames (T)", hkColor::DARKORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Update Some Vertex Frames (TB)", hkColor::DARKORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Update All Vertex Frames (N)", hkColor::ORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Update All Vertex Frames (T)", hkColor::DARKORANGE);
  hkMonitorStreamColorTable::addColor(v1, "Update All Vertex Frames (TB)", hkColor::DARKORANGE);
}

// File Line: 2149
// RVA: 0xC757C0
__int64 __fastcall hkMonitorStreamColorTable::findColor(hkMonitorStreamColorTable *this, const char *color)
{
  int v2; // ebx
  const char *v3; // rbp
  hkMonitorStreamColorTable *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = color;
  v4 = this;
  if ( this->m_colorPairs.m_size <= 0 )
    return v4->m_defaultColor;
  v5 = 0i64;
  while ( (unsigned int)hkString::strCasecmp(
                          (const char *)((_QWORD)v4->m_colorPairs.m_data[v5].m_colorName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          v3) )
  {
    ++v2;
    ++v5;
    if ( v2 >= v4->m_colorPairs.m_size )
      return v4->m_defaultColor;
  }
  return v4->m_colorPairs.m_data[v2].m_color;
}

// File Line: 2161
// RVA: 0xC75850
void __fastcall hkMonitorStreamColorTable::addColor(hkMonitorStreamColorTable *this, const char *name, unsigned int color)
{
  hkMonitorStreamColorTable *v3; // rbx
  unsigned int v4; // edi
  int v5; // eax
  signed __int64 v6; // rdi
  signed __int64 v7; // rbx
  hkStringPtr strRef; // [rsp+20h] [rbp-18h]
  unsigned int v9; // [rsp+28h] [rbp-10h]

  v3 = this;
  v4 = color;
  hkStringPtr::hkStringPtr(&strRef, name);
  v5 = v3->m_colorPairs.m_capacityAndFlags;
  v9 = v4;
  v6 = (signed __int64)&v3->m_colorPairs;
  if ( v3->m_colorPairs.m_size == (v5 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_colorPairs, 16);
  v7 = *(_QWORD *)v6 + 16i64 * v3->m_colorPairs.m_size;
  if ( v7 )
  {
    hkStringPtr::hkStringPtr((hkStringPtr *)v7, &strRef);
    *(_DWORD *)(v7 + 8) = v9;
  }
  ++*(_DWORD *)(v6 + 8);
  hkStringPtr::~hkStringPtr(&strRef);
}

// File Line: 2183
// RVA: 0xC7B670
char __fastcall saveToTGA(int *data, hkOstream *s, int width, int height)
{
  hkOstream *v4; // rbp
  int v5; // esi
  int *v6; // rdi
  int v7; // ebx
  char dst; // [rsp+20h] [rbp-28h]
  char v10; // [rsp+22h] [rbp-26h]
  __int16 v11; // [rsp+2Ch] [rbp-1Ch]
  __int16 v12; // [rsp+2Eh] [rbp-1Ah]
  char v13; // [rsp+30h] [rbp-18h]

  v4 = s;
  v5 = width;
  v6 = data;
  v7 = height;
  hkString::memSet(&dst, 0, 18);
  v10 = 2;
  v12 = v7;
  v11 = v5;
  v13 = 32;
  hkOstream::write(v4, &dst, 18i64);
  hkOstream::write(v4, (const char *)v6, (unsigned int)(4 * v7 * v5));
  return 1;
}

// File Line: 2327
// RVA: 0xC7B700
void __fastcall drawDigit(int nr, int currentY, int outputPixelWidth, int *texture)
{
  __int64 v4; // r10
  unsigned int *v5; // r11
  signed int v6; // ecx

  v4 = 0i64;
  v5 = numbers[nr];
  v6 = 0;
  do
  {
    if ( (v5[6] << v6) & 0xF0000000 )
      texture[v4] = -16777216;
    if ( (v5[5] << v6) & 0xF0000000 )
      texture[v4 + outputPixelWidth] = -16777216;
    if ( (v5[4] << v6) & 0xF0000000 )
      texture[v4 + 2i64 * outputPixelWidth] = -16777216;
    if ( (v5[3] << v6) & 0xF0000000 )
      texture[v4 + 2i64 * outputPixelWidth + outputPixelWidth] = -16777216;
    if ( (v5[2] << v6) & 0xF0000000 )
      texture[v4 + 4i64 * outputPixelWidth] = -16777216;
    if ( (v5[1] << v6) & 0xF0000000 )
      texture[v4 + 4i64 * outputPixelWidth + outputPixelWidth] = -16777216;
    if ( (*v5 << v6) & 0xF0000000 )
      texture[v4 + 6i64 * outputPixelWidth] = -16777216;
    v6 += 4;
    ++v4;
  }
  while ( v6 < 32 );
}

// File Line: 2342
// RVA: 0xC7B800
void __fastcall drawNumber(int nr, int currentY, int outputPixelWidth, int *texture)
{
  int *v4; // rsi
  int v5; // ebp
  int v6; // er14
  int v7; // edi
  signed int v8; // ebx

  v4 = texture;
  v5 = currentY;
  v6 = nr;
  v7 = 0;
  v8 = 1000;
  do
  {
    drawDigit(v6 / v8 % 10, v5, outputPixelWidth, &v4[v7]);
    v7 += 7;
    v8 /= 10;
  }
  while ( v8 >= 1 );
}

// File Line: 2358
// RVA: 0xC7B8A0
hkMonitorStreamAnalyzer::Node *__fastcall getNodeSampledAtTick(hkMonitorStreamFrameInfo *info, int frameIndex, int tick, hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodes, int maxX, float frameTime, float absoluteFrameStartTimes)
{
  int v7; // esi
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v8; // r14
  __int64 v9; // rbp
  __int64 v10; // r15
  hkMonitorStreamFrameInfo *v11; // rdi
  float v12; // xmm6_4
  hkMonitorStreamAnalyzer::Node **v13; // rdx
  hkMonitorStreamAnalyzer::Node *v14; // rbx
  int absoluteTimeIndex; // eax
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> timerNodesAtTicks; // [rsp+30h] [rbp-38h]

  v7 = maxX;
  v8 = nodes;
  v9 = tick;
  v10 = frameIndex;
  v11 = info;
  timerNodesAtTicks.m_data = 0i64;
  timerNodesAtTicks.m_size = 0;
  timerNodesAtTicks.m_capacityAndFlags = 2147483648;
  v12 = frameTime / (float)maxX;
  if ( maxX > 0 )
    hkArrayUtil::_reserve(
      (hkResult *)&maxX,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &timerNodesAtTicks,
      maxX,
      8);
  v13 = v8->m_data;
  v14 = 0i64;
  if ( v8->m_data[v10]->m_children.m_size > 0 )
  {
    timerNodesAtTicks.m_size = 0;
    absoluteTimeIndex = v11->m_absoluteTimeCounter.m_storage ? v11->m_indexOfTimer1 : v11->m_indexOfTimer0;
    outputStatsForFrame(v13[v10], absoluteFrameStartTimes, v12, v7, &timerNodesAtTicks, absoluteTimeIndex);
    if ( (signed int)v9 < timerNodesAtTicks.m_size )
      v14 = timerNodesAtTicks.m_data[v9];
  }
  timerNodesAtTicks.m_size = 0;
  if ( timerNodesAtTicks.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      timerNodesAtTicks.m_data,
      8 * timerNodesAtTicks.m_capacityAndFlags);
  return v14;
}

// File Line: 2398
// RVA: 0xC7B9D0
void __usercall drawStatistics(hkMonitorStreamFrameInfo *info@<rcx>, int frameIndex@<edx>, hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodes@<r8>, int *texture@<r9>, __int64 a5@<rbx>, int height, hkMonitorStreamColorTable *colorTable, __int64 pixelWidth, int maxX, float frameTime, float absoluteFrameStartTimes, hkPointerMap<char const *,unsigned int,hkContainerHeapAllocator> *unknownColorMap)
{
  int *v12; // r12
  hkMonitorStreamAnalyzer::Node *v13; // rsi
  hkMonitorStreamFrameInfo *v14; // rdi
  float v15; // xmm6_4
  int v16; // eax
  __int64 v17; // r10
  unsigned __int64 v18; // r13
  __int64 v19; // rsi
  __int64 v20; // rdi
  __int64 v21; // r9
  __int64 v22; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v23; // rbx
  __int64 v24; // r14
  int v25; // ecx
  const char *v26; // r12
  int v27; // ebx
  __int64 v28; // rsi
  __int64 v29; // rdi
  int *v30; // rax
  __int64 v31; // rdx
  __int64 v32; // [rsp+10h] [rbp-71h]
  unsigned __int64 out; // [rsp+18h] [rbp-69h]
  int sizeElem[2]; // [rsp+20h] [rbp-61h]
  int absoluteTimeIndex[2]; // [rsp+28h] [rbp-59h]
  __int64 v36; // [rsp+30h] [rbp-51h]
  __int64 v37; // [rsp+38h] [rbp-49h]
  __int64 array; // [rsp+40h] [rbp-41h]
  int v39; // [rsp+48h] [rbp-39h]
  int v40; // [rsp+4Ch] [rbp-35h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v41; // [rsp+50h] [rbp-31h]
  hkResult result; // [rsp+B8h] [rbp+37h]
  hkResult vars0; // [rsp+C0h] [rbp+3Fh]
  int *retaddr; // [rsp+C8h] [rbp+47h]
  __int64 v45; // [rsp+D0h] [rbp+4Fh]
  __int64 v46; // [rsp+D8h] [rbp+57h]
  int v47; // [rsp+E0h] [rbp+5Fh]
  int *v48; // [rsp+E8h] [rbp+67h]

  v48 = texture;
  v12 = texture;
  v13 = nodes->m_data[frameIndex];
  v14 = info;
  if ( !v13->m_children.m_size )
    return;
  v45 = a5;
  v41.m_hashMod = -1;
  v40 = 2147483648;
  v41.m_elem = 0i64;
  v41.m_numElems = 0;
  v15 = *(float *)&height / (float)(signed int)texture;
  array = 0i64;
  v39 = 0;
  if ( (signed int)texture > 0 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      (int)texture,
      8);
  if ( v14->m_absoluteTimeCounter.m_storage )
    v16 = v14->m_indexOfTimer1;
  else
    v16 = v14->m_indexOfTimer0;
  outputStatsForFrame(
    v13,
    *(float *)&colorTable,
    v15,
    (int)v48,
    (hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *)&array,
    v16);
  v17 = v39;
  LODWORD(v18) = hkColor::WHITE;
  v19 = (signed int)a5;
  v20 = 0i64;
  v21 = 0i64;
  v22 = (signed int)v48;
  v37 = (signed int)v48;
  v36 = v39;
  if ( v39 <= 0i64 )
    goto LABEL_32;
  v23 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)pixelWidth;
  do
  {
    if ( v21 >= v22 )
      break;
    v24 = *(_QWORD *)(array + 8 * v21);
    if ( !v24 || *(_DWORD *)(v24 + 140) )
      goto LABEL_31;
    if ( v24 == v20 )
    {
      v25 = v18;
      goto LABEL_28;
    }
    LODWORD(v18) = hkColor::WHITE;
    *(_QWORD *)absoluteTimeIndex = *(_QWORD *)(array + 8 * v21);
    while ( 1 )
    {
      v26 = *(const char **)(v24 + 128);
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
             &v41,
             &result,
             *(_QWORD *)(v24 + 128),
             (unsigned __int64 *)sizeElem)->m_enum == HK_SUCCESS )
      {
        LODWORD(v18) = sizeElem[0];
        goto LABEL_27;
      }
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
             v23,
             &vars0,
             (unsigned __int64)v26,
             &out)->m_enum )
        break;
      LODWORD(v18) = out;
LABEL_23:
      v24 = *(_QWORD *)(v24 + 120);
      if ( !v24 )
        goto LABEL_27;
    }
    v27 = 0;
    v28 = 0i64;
    if ( *(_DWORD *)(v46 + 24) <= 0 )
    {
LABEL_22:
      v23 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)pixelWidth;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)pixelWidth,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v26,
        (unsigned int)v18);
      goto LABEL_23;
    }
    v29 = 0i64;
    while ( (unsigned int)hkString::strCasecmp(
                            (const char *)(*(_QWORD *)(v29 + *(_QWORD *)(v46 + 16)) & 0xFFFFFFFFFFFFFFFEui64),
                            v26) )
    {
      ++v27;
      ++v28;
      v29 += 16i64;
      if ( v27 >= *(_DWORD *)(v46 + 24) )
        goto LABEL_22;
    }
    v18 = *(unsigned int *)(*(_QWORD *)(v46 + 16) + 16 * v28 + 8);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v41,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)v26,
      v18);
LABEL_27:
    v23 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)pixelWidth;
    v21 = v32;
    v12 = retaddr;
    v20 = *(_QWORD *)absoluteTimeIndex;
    v19 = (signed int)v45;
    v17 = v36;
    v25 = v18 & 0xFF000000 | ((unsigned int)v18 >> 1) & 0x7F7F7F;
LABEL_28:
    if ( v19 > 0 )
    {
      v30 = v12;
      v31 = v19;
      do
      {
        *v30 = v25;
        v30 += v47;
        --v31;
      }
      while ( v31 );
    }
LABEL_31:
    v22 = v37;
    ++v21;
    ++v12;
    retaddr = v12;
  }
  while ( v21 < v17 );
LABEL_32:
  v39 = 0;
  if ( v40 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(8 * v40),
      v21);
  array = 0i64;
  v40 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v41,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v41);
}

// File Line: 2501
// RVA: 0xC7BCE0
float __fastcall _hkMin(float result, float b)
{
  if ( result >= b )
    result = b;
  return result;
}

// File Line: 2506
// RVA: 0xC7BCF0
float __fastcall _hkMax(float result, float b)
{
  if ( result <= b )
    result = b;
  return result;
}

// File Line: 2511
// RVA: 0xC7BD00
long double __fastcall _hkMinD(long double result, long double b)
{
  if ( result >= b )
    result = b;
  return result;
}

// File Line: 2516
// RVA: 0xC7BD20
long double __fastcall _hkMaxD(long double result, long double b)
{
  if ( result <= b )
    result = b;
  return result;
}

// File Line: 2521
// RVA: 0xC77F80
void __fastcall hkMonitorStreamAnalyzer::checkAllThreadsCapturedSameNumFrames(hkMonitorStreamAnalyzer *this)
{
  ;
}

// File Line: 2533
// RVA: 0xC76BC0
__int64 __fastcall hkMonitorStreamAnalyzer::ThreadDrawInput::computePerThreadHeightToFit(int textureHeight, int numFrames, int numThreads, int frameGap, int threadGap)
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
  return (v2 | (v2 >> 16)) + 1;
}

// File Line: 2552
// RVA: 0xC7BD70
void __fastcall rebase(hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *rootNodes, long double hdt, long double dt)
{
  int v3; // esi
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *v4; // rdi
  __int64 v5; // rbx
  hkMonitorStreamAnalyzer::Node *v6; // rdx
  double v7; // xmm0_8

  v3 = 0;
  v4 = rootNodes;
  if ( rootNodes->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_data[v5];
      if ( v6->m_type.m_storage != 2 )
      {
        v7 = v6->m_absoluteStartTime;
        if ( v7 < hdt )
          v6->m_absoluteStartTime = v7 + dt;
      }
      rebase(&v4->m_data[v5]->m_children, hdt, dt);
      ++v3;
      ++v5;
    }
    while ( v3 < v4->m_size );
  }
}

// File Line: 2565
// RVA: 0xC7BE10
char __fastcall needsRebase(hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *rootNodes, long double halfRange, long double *maxSoFar)
{
  int v3; // edi
  long double *v4; // rsi
  long double v5; // xmm6_8
  hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *v6; // rbp
  __int64 v7; // rbx
  hkMonitorStreamAnalyzer::Node *v8; // rdx
  double v9; // xmm1_8
  double v10; // xmm0_8

  v3 = 0;
  v4 = maxSoFar;
  v5 = halfRange;
  v6 = rootNodes;
  if ( rootNodes->m_size <= 0 )
    return 0;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = v6->m_data[v7];
    if ( v8->m_type.m_storage == 2 )
      goto LABEL_9;
    v9 = v8->m_absoluteStartTime;
    if ( v9 < v5 && *v4 - v9 > v5 )
      return 1;
    v10 = *v4;
    if ( *v4 <= v9 )
      v10 = v8->m_absoluteStartTime;
    *v4 = v10;
LABEL_9:
    if ( needsRebase(&v6->m_data[v7]->m_children, v5, v4) )
      return 1;
    ++v3;
    ++v7;
    if ( v3 >= v6->m_size )
      return 0;
  }
}

// File Line: 2591
// RVA: 0xC79450
void __fastcall hkMonitorStreamAnalyzer::getTimerLimits(hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList, hkMonitorStreamAnalyzer::ThreadDrawInput *input, hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos, float *maxFrameTime, hkArray<float,hkContainerHeapAllocator> *startTimes)
{
  int v5; // ebx
  int v6; // edi
  int v7; // er11
  int v8; // esi
  int v9; // eax
  float *v10; // r15
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v11; // r9
  hkMonitorStreamAnalyzer::ThreadDrawInput *v12; // r8
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v13; // r10
  int v14; // er13
  hkArray<float,hkContainerHeapAllocator> *v15; // r14
  int v16; // eax
  int v17; // eax
  int v18; // er9
  __int64 v19; // rdx
  float *v20; // rdi
  __int64 v21; // rcx
  signed __int64 v22; // rax
  signed __int64 v23; // rbp
  __int64 v24; // r12
  __int64 v25; // rdx
  hkMonitorStreamFrameInfo *v26; // rcx
  int v27; // ebx
  int v28; // eax
  int v29; // esi
  float v30; // xmm0_4
  signed __int64 v31; // rdi
  double v32; // xmm3_8
  signed __int64 v33; // r9
  __int64 v34; // r9
  _QWORD *v35; // r10
  long double v36; // xmm4_8
  signed __int64 v37; // rdi
  int v38; // eax
  double *v39; // r13
  hkResultEnum v40; // ecx
  double *v41; // r8
  signed __int64 v42; // r10
  int v43; // edi
  __int64 v44; // r9
  __int64 v45; // rdx
  __int64 v46; // rcx
  double v47; // xmm0_8
  signed __int64 v48; // rdx
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
  float v65; // xmm0_4
  float v66; // xmm0_4
  unsigned int v67; // ecx
  float v68; // xmm1_4
  float v69; // xmm0_4
  int v70; // [rsp+30h] [rbp-A8h]
  hkResult result; // [rsp+34h] [rbp-A4h]
  int v72; // [rsp+38h] [rbp-A0h]
  int v73; // [rsp+3Ch] [rbp-9Ch]
  int v74; // [rsp+40h] [rbp-98h]
  int v75; // [rsp+44h] [rbp-94h]
  double *v76; // [rsp+48h] [rbp-90h]
  __int64 v77; // [rsp+50h] [rbp-88h]
  long double maxSoFar; // [rsp+58h] [rbp-80h]
  __int64 v79; // [rsp+60h] [rbp-78h]
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v80; // [rsp+E0h] [rbp+8h]
  hkMonitorStreamAnalyzer::ThreadDrawInput *v81; // [rsp+E8h] [rbp+10h]
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v82; // [rsp+F0h] [rbp+18h]

  v82 = frameInfos;
  v81 = input;
  v80 = nodeList;
  v5 = input->m_numFrames;
  v6 = input->m_frameStart;
  v7 = nodeList->m_size;
  v8 = input->m_frameStart + v5;
  v9 = (*nodeList->m_data)->m_children.m_size;
  v10 = maxFrameTime;
  v11 = frameInfos;
  v12 = input;
  v13 = nodeList;
  v75 = nodeList->m_size;
  v74 = v8;
  v14 = v5;
  v70 = v5;
  if ( v8 > v9 )
  {
    v8 = v9;
    v74 = v9;
    v14 = v9 - v6;
    v70 = v9 - v6;
  }
  if ( v14 > 0 )
  {
    v15 = startTimes;
    v16 = startTimes->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v16 < v5 )
    {
      v17 = 2 * v16;
      v18 = v5;
      if ( v5 < v17 )
        v18 = v17;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, startTimes, v18, 4);
      v12 = v81;
      v13 = v80;
      v7 = v75;
      v11 = v82;
    }
    v19 = startTimes->m_size;
    v20 = &startTimes->m_data[v19];
    v21 = v5 - (signed int)v19;
    if ( v5 - (signed int)v19 > 0 )
    {
      while ( v21 )
      {
        *v20 = 0.0;
        ++v20;
        --v21;
      }
    }
    startTimes->m_size = v5;
    *v10 = 0.0;
    v22 = v12->m_frameStart;
    v23 = v7;
    v79 = v8;
    v72 = v22;
    v24 = v22;
    if ( v22 < v8 )
    {
      v25 = 40 * v22;
      v77 = 40 * v22;
      do
      {
        v26 = v11->m_data->m_data;
        v27 = v22 - v12->m_frameStart;
        v28 = *(unsigned int *)((char *)&v26->m_absoluteTimeCounter.m_storage + v25);
        if ( v28 )
          v29 = *(int *)((char *)&v26->m_indexOfTimer1 + v25);
        else
          v29 = *(int *)((char *)&v26->m_indexOfTimer0 + v25);
        if ( v28 )
          v30 = *(float *)((char *)&v26->m_timerFactor1 + v25);
        else
          v30 = *(float *)((char *)&v26->m_timerFactor0 + v25);
        v31 = 0i64;
        maxSoFar = 0.0;
        v32 = v30 * 4294967295.0 * 0.5;
        if ( v23 > 0 )
        {
          v33 = (signed __int64)v13->m_data;
          while ( !needsRebase(
                     (hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v33 + 96i64) + 8 * v24)
                                                                                         + 96i64),
                     v32,
                     &maxSoFar) )
          {
            ++v31;
            v33 = v34 + 8;
            if ( v31 >= v23 )
              goto LABEL_26;
          }
          v37 = 0i64;
          do
            rebase(
              (hkArray<hkMonitorStreamAnalyzer::Node *,hkContainerHeapAllocator> *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*v35 + 8 * v37++) + 96i64)
                                                                                              + 8 * v24)
                                                                                  + 96i64),
              v32,
              v36);
          while ( v37 < v23 );
        }
LABEL_26:
        v38 = v7;
        if ( v7 )
        {
          v73 = 8 * v7;
          v39 = (double *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            &v73);
          v38 = v73 / 8;
        }
        else
        {
          v39 = 0i64;
        }
        v40 = 2147483648;
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
            v44 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)((char *)v41 + (unsigned __int64)v80->m_data - (char *)v39) + 96i64)
                            + 8 * v24);
            if ( *(_DWORD *)(v44 + 104) > 0 )
            {
              v45 = 0i64;
              do
              {
                v46 = *(_QWORD *)(v45 + *(_QWORD *)(v44 + 96));
                if ( *(_DWORD *)(v46 + 140) != 2 )
                {
                  v47 = *(double *)(v46 + 112);
                  if ( v47 >= *v41 )
                    v47 = *v41;
                  *v41 = v47;
                }
                ++v43;
                v45 += 8i64;
              }
              while ( v43 < *(_DWORD *)(v44 + 104) );
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
            v58 = v80->m_data[v56]->m_children.m_data[v24];
            if ( v58->m_children.m_size > 0 )
            {
              v59 = 0i64;
              do
              {
                v60 = v58->m_children.m_data[v59];
                if ( v60->m_type.m_storage != 2 )
                {
                  v61 = v60->m_value[v29] + v60->m_absoluteStartTime - v15->m_data[v27];
                  if ( v61 <= *v10 )
                    v61 = *v10;
                  *v10 = v61;
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
        if ( (signed int)result.m_enum >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v39,
            8 * result.m_enum);
        v12 = v81;
        v13 = v80;
        v7 = v75;
        v11 = v82;
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
    v65 = v12->m_limitFrameTime;
    if ( v65 <= 0.0 )
    {
      if ( v14 == 1 )
      {
        v66 = hkMonitorStreamAnalyzer::g_lastFrameTime * 0.25;
        v67 = ((((((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 4) | ((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 8) | ((((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 4) | ((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001);
        if ( (float)(hkMonitorStreamAnalyzer::g_lastFrameTime * 0.25) >= (float)((float)((float)(signed int)((v67 | (v67 >> 16)) + 1)
                                                                                       * 1000.0)
                                                                               - hkMonitorStreamAnalyzer::g_lastFrameTime) )
          v66 = (float)((float)(signed int)((v67 | ((((((((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 4) | ((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 8) | ((((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 4) | ((((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 2) | ((unsigned int)(signed int)(float)(*v10 * 0.001) >> 1) | (signed int)(float)(*v10 * 0.001)) >> 16))
                                          + 1)
                      * 1000.0)
              - hkMonitorStreamAnalyzer::g_lastFrameTime;
        v68 = FLOAT_16666_0;
        v69 = (float)(v66 * 0.050000001) + hkMonitorStreamAnalyzer::g_lastFrameTime;
        *v10 = v69;
        if ( v69 >= 16666.0 )
          v68 = v69;
        *v10 = v68;
        hkMonitorStreamAnalyzer::g_lastFrameTime = v68;
      }
    }
    else
    {
      *v10 = v65;
    }
  }
}

// File Line: 2718
// RVA: 0xC78D10
void __fastcall hkMonitorStreamAnalyzer::writeStatisticsDetailsToTexture(hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList, hkMonitorStreamAnalyzer::ThreadDrawInput *input, hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos, int **texture, int *height, hkMonitorStreamAnalyzer::SampleInfo *sampleInfo)
{
  __int64 v6; // r15
  void **v7; // rsi
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v8; // rbx
  hkMonitorStreamAnalyzer::ThreadDrawInput *v9; // rdi
  int v10; // er8
  signed int v11; // er14
  int v12; // er12
  int v13; // eax
  int v14; // ebp
  int v15; // ebx
  hkMemoryAllocator **v16; // rax
  float frameTime; // xmm6_4
  __int64 v18; // rax
  signed __int64 v19; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v20; // rbx
  int v21; // er11
  __int64 v22; // r13
  __int64 v23; // r12
  __int64 v24; // rbx
  __int64 v25; // r15
  __int64 v26; // r9
  float v27; // xmm1_4
  signed int v28; // er15
  int v29; // er10
  int v30; // eax
  __int64 i; // rdx
  __int64 v32; // rcx
  signed int v33; // er10
  int v34; // er14
  __int64 v35; // r8
  __int64 j; // rdx
  __int64 v37; // rcx
  int v38; // edx
  signed __int64 v39; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v40; // rax
  int v41; // eax
  int v42; // edx
  signed __int64 v43; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v44; // rax
  int maxX; // [rsp+60h] [rbp-98h]
  int v46; // [rsp+64h] [rbp-94h]
  float maxFrameTime[2]; // [rsp+68h] [rbp-90h]
  hkPointerMap<char const *,unsigned int,hkContainerHeapAllocator> unknownColorMap; // [rsp+70h] [rbp-88h]
  int v49; // [rsp+80h] [rbp-78h]
  __int64 v50; // [rsp+88h] [rbp-70h]
  int v51; // [rsp+90h] [rbp-68h]
  float *startTimes; // [rsp+98h] [rbp-60h]
  int v53; // [rsp+A0h] [rbp-58h]
  int v54; // [rsp+A4h] [rbp-54h]
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v55; // [rsp+100h] [rbp+8h]
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v56; // [rsp+110h] [rbp+18h]

  v56 = frameInfos;
  v55 = nodeList;
  v6 = nodeList->m_size;
  v7 = (void **)texture;
  v8 = frameInfos;
  v9 = input;
  if ( (signed int)v6 >= 1 )
  {
    maxFrameTime[0] = FLOAT_N1_0;
    startTimes = 0i64;
    v53 = 0;
    v54 = 2147483648;
    hkMonitorStreamAnalyzer::getTimerLimits(
      nodeList,
      input,
      frameInfos,
      maxFrameTime,
      (hkArray<float,hkContainerHeapAllocator> *)&startTimes);
    v10 = v9->m_numFrames;
    v11 = 0;
    if ( v10 > v8->m_data->m_size - v9->m_frameStart )
      v10 = v8->m_data->m_size - v9->m_frameStart;
    v46 = v10;
    LODWORD(v50) = v9->m_frameStart + v10;
    v49 = v9->m_heightPerThread + v9->m_gapBetweenThreads;
    v12 = v10 * (v9->m_gapBetweenFrames + v6 * v49);
    if ( v10 > 1 )
      v11 = 32;
    v13 = v9->m_outputPixelWidth;
    v51 = v10 * (v9->m_gapBetweenFrames + v6 * v49);
    v14 = v12;
    v15 = v12 * (v13 + 1);
    maxX = v13 - v11;
    v16 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 *= 4;
    *v7 = (void *)hkMemoryRouter::easyAlloc(v16[11], v15);
    *height = v12;
    hkString::memSet(*v7, 0, v15);
    frameTime = maxFrameTime[0];
    if ( sampleInfo )
      sampleInfo->m_maxSampleTime = maxFrameTime[0];
    v18 = (signed int)v50;
    v19 = v46;
    v20 = 0i64;
    v21 = -1;
    unknownColorMap.m_map.m_numElems = 0;
    v22 = v9->m_frameStart;
    unknownColorMap.m_map.m_elem = 0i64;
    unknownColorMap.m_map.m_hashMod = -1;
    *(_QWORD *)maxFrameTime = v6;
    v23 = v22;
    v50 = v18;
    if ( v22 < v18 )
    {
      do
      {
        v14 -= v9->m_gapBetweenFrames;
        if ( v19 > 1 )
        {
          drawNumber(v22, v14, v9->m_outputPixelWidth, (int *)*v7 + v9->m_outputPixelWidth * (v14 - v49));
          v18 = v50;
        }
        v24 = 0i64;
        if ( v6 > 0 )
        {
          v25 = 0i64;
          do
          {
            v14 -= v49;
            drawStatistics(
              v56->m_data[v25].m_data,
              v22,
              (hkArrayBase<hkMonitorStreamAnalyzer::Node *> *)&v55->m_data[v24++]->m_children.m_data,
              (int *)*v7 + v11 + v14 * v9->m_outputPixelWidth,
              v9->m_heightPerThread,
              v9->m_colorTable,
              v9->m_outputPixelWidth,
              maxX,
              frameTime,
              startTimes[v23 - v9->m_frameStart],
              &unknownColorMap);
            ++v25;
          }
          while ( v24 < *(_QWORD *)maxFrameTime );
          v6 = *(_QWORD *)maxFrameTime;
          v18 = v50;
        }
        v19 = v46;
        ++v23;
        LODWORD(v22) = v22 + 1;
      }
      while ( v23 < v18 );
      v21 = unknownColorMap.m_map.m_hashMod;
      v20 = unknownColorMap.m_map.m_elem;
    }
    v26 = v51;
    v27 = (float)(1000 * maxX) * (float)(1.0 / frameTime);
    v28 = (signed int)(float)((float)((float)((signed int)v9->m_limitStartTime % 1000) * 0.001) * v27);
    if ( v27 > 5.0 )
    {
      v29 = 0;
      v30 = v11 - v28;
      if ( v11 - v28 < v9->m_outputPixelWidth )
      {
        do
        {
          if ( v30 >= 0 )
          {
            for ( i = 0i64; i < v26; *((_DWORD *)*v7 + v30 + v32) = -16776961 )
              v32 = i++ * v9->m_outputPixelWidth;
          }
          v30 = v11 + (signed int)(float)((float)++v29 * v27) - v28;
        }
        while ( v30 < v9->m_outputPixelWidth );
        v21 = unknownColorMap.m_map.m_hashMod;
        v20 = unknownColorMap.m_map.m_elem;
      }
    }
    v33 = (signed int)(float)((float)(16666 * maxX) * (float)(1.0 / frameTime));
    if ( v33 > 0 )
    {
      v34 = v11 - v28;
      v35 = v34;
      if ( v34 < v9->m_outputPixelWidth )
      {
        do
        {
          if ( v35 >= 0 )
          {
            for ( j = 0i64; j < v26; *((_DWORD *)*v7 + v37 + 1) = -16711936 )
            {
              *((_DWORD *)*v7 + v35 + j * v9->m_outputPixelWidth) = -16711936;
              v37 = v35 + j++ * v9->m_outputPixelWidth;
            }
          }
          v34 += v33;
          v35 += v33;
        }
        while ( v34 < v9->m_outputPixelWidth );
        v21 = unknownColorMap.m_map.m_hashMod;
        v20 = unknownColorMap.m_map.m_elem;
      }
    }
    if ( v9->m_warnAboutMissingTimers.m_bool )
    {
      v38 = 0;
      v39 = 0i64;
      if ( v21 >= 0 )
      {
        v40 = v20;
        do
        {
          if ( v40->key != -1i64 )
            break;
          ++v39;
          ++v38;
          ++v40;
        }
        while ( v39 <= v21 );
      }
      v41 = v38;
      if ( v38 <= v21 )
      {
        do
        {
          v42 = v41 + 1;
          v43 = v41 + 1;
          if ( v43 <= v21 )
          {
            v44 = &v20[v42];
            do
            {
              if ( v44->key != -1i64 )
                break;
              ++v43;
              ++v42;
              ++v44;
            }
            while ( v43 <= v21 );
          }
          v41 = v42;
        }
        while ( v42 <= v21 );
      }
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&unknownColorMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&unknownColorMap);
    v53 = 0;
    if ( v54 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        startTimes,
        4 * v54);
  }
}

// File Line: 2833
// RVA: 0xC79200
void __fastcall hkMonitorStreamAnalyzer::writeStatisticsDetailsToTga(hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList, hkMonitorStreamAnalyzer::ThreadDrawInput *input, hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos, hkOstream *outStream, hkMonitorStreamAnalyzer::SampleInfo *sampleInfo)
{
  hkOstream *v5; // rsi
  hkMonitorStreamAnalyzer::ThreadDrawInput *v6; // rdi
  hkMemoryAllocator **v7; // rax
  int height; // [rsp+30h] [rbp-18h]
  int *texture; // [rsp+38h] [rbp-10h]

  v5 = outStream;
  texture = 0i64;
  height = 0;
  v6 = input;
  hkMonitorStreamAnalyzer::writeStatisticsDetailsToTexture(nodeList, input, frameInfos, &texture, &height, sampleInfo);
  if ( texture )
  {
    saveToTGA(texture, v5, v6->m_outputPixelWidth, height);
    v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v7[11], texture);
  }
}

// File Line: 2847
// RVA: 0xC76BE0
void __fastcall hkMonitorStreamAnalyzer::drawThreadsToTga(hkMonitorStreamAnalyzer *this, hkMonitorStreamAnalyzer::ThreadDrawInput *input, hkOstream *outStream)
{
  __int64 v3; // rbx
  hkOstream *v4; // r15
  hkMonitorStreamAnalyzer::ThreadDrawInput *v5; // r12
  hkMonitorStreamAnalyzer *v6; // r14
  int v7; // er9
  int v8; // ebp
  __int64 v9; // rdi
  __int64 v10; // rsi
  hkMonitorStreamAnalyzer::Node **v11; // rbx
  hkMonitorStreamAnalyzer::Node *v12; // rax
  __int64 i; // rbx
  hkMonitorStreamAnalyzer::Node *v14; // rdi
  _QWORD **v15; // rax
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> nodeList; // [rsp+30h] [rbp-68h]
  __int64 v17; // [rsp+40h] [rbp-58h]
  __int64 v18; // [rsp+A0h] [rbp+8h]

  v3 = this->m_frameInfos.m_size;
  v4 = outStream;
  nodeList.m_data = (hkMonitorStreamAnalyzer::Node **)&v17;
  v5 = input;
  v6 = this;
  nodeList.m_size = 0;
  nodeList.m_capacityAndFlags = -2147483642;
  if ( (signed int)v3 > 6 )
  {
    v7 = v3;
    if ( (signed int)v3 < 12 )
      v7 = 12;
    hkArrayUtil::_reserve(
      (hkResult *)&v18,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &nodeList,
      v7,
      8);
  }
  v8 = 0;
  v9 = 0i64;
  nodeList.m_size = v3;
  v10 = v3;
  if ( (signed int)v3 > 0 )
  {
    do
    {
      v11 = &nodeList.m_data[v9];
      v12 = hkMonitorStreamAnalyzer::makeStatisticsTreeForMultipleFrames(v6, v8, 0);
      ++v9;
      ++v8;
      *v11 = v12;
    }
    while ( v9 < v10 );
  }
  hkMonitorStreamAnalyzer::writeStatisticsDetailsToTga(&nodeList, v5, &v6->m_frameInfos, v4, 0i64);
  for ( i = 0i64; i < v10; ++i )
  {
    v14 = nodeList.m_data[i];
    if ( v14 )
    {
      hkMonitorStreamAnalyzer::Node::~Node(nodeList.m_data[i]);
      v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkMonitorStreamAnalyzer::Node *, signed __int64))(*v15[11] + 16i64))(
        v15[11],
        v14,
        144i64);
    }
  }
  nodeList.m_size = 0;
  if ( nodeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      nodeList.m_data,
      8 * nodeList.m_capacityAndFlags);
}

// File Line: 2869
// RVA: 0xC79290
hkMonitorStreamAnalyzer::Node *__fastcall hkMonitorStreamAnalyzer::reverseLookupNodeAtTgaSample(int x, int y, hkArrayBase<hkMonitorStreamAnalyzer::Node *> *nodeList, hkMonitorStreamAnalyzer::ThreadDrawInput *input, hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *frameInfos)
{
  int v5; // eax
  hkMonitorStreamAnalyzer::ThreadDrawInput *v6; // r10
  int v7; // er9
  hkArrayBase<hkMonitorStreamAnalyzer::Node *> *v8; // r12
  int v9; // er15
  int v11; // ebp
  int v12; // er14
  int v13; // er14
  int v14; // er8
  int v15; // ecx
  int v16; // eax
  hkArray<hkArray<hkMonitorStreamFrameInfo,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v17; // rbx
  int v18; // eax
  __int64 v19; // rsi
  __int64 v20; // rdi
  hkMonitorStreamAnalyzer::Node *v21; // rbx
  hkArray<float,hkContainerHeapAllocator> startTimes; // [rsp+40h] [rbp-38h]
  float maxFrameTime; // [rsp+90h] [rbp+18h]

  v5 = nodeList->m_size;
  v6 = input;
  v7 = input->m_numFrames;
  v8 = nodeList;
  v9 = x;
  if ( v5 < 1 )
    return 0i64;
  v11 = 0;
  if ( v7 > 1 )
    v11 = 32;
  if ( x < v11 )
    return 0i64;
  v12 = v6->m_outputPixelWidth;
  if ( x >= v12 )
    return 0i64;
  v13 = v12 - v11;
  v14 = v6->m_heightPerThread + v6->m_gapBetweenThreads;
  v15 = v6->m_gapBetweenFrames + v5 * v14;
  v16 = v7 * (v6->m_gapBetweenFrames + v5 * v14);
  if ( y < 0 || y >= v16 )
    return 0i64;
  v17 = frameInfos;
  v18 = v16 - y - 1;
  maxFrameTime = FLOAT_N1_0;
  startTimes.m_data = 0i64;
  startTimes.m_size = 0;
  startTimes.m_capacityAndFlags = 2147483648;
  v19 = v18 / v15;
  v20 = v18 % v15 / v14;
  hkMonitorStreamAnalyzer::getTimerLimits(v8, v6, frameInfos, &maxFrameTime, &startTimes);
  v21 = getNodeSampledAtTick(
          v17->m_data[v20].m_data,
          v19,
          v9 - v11,
          (hkArrayBase<hkMonitorStreamAnalyzer::Node *> *)&v8->m_data[v20]->m_children.m_data,
          v13,
          maxFrameTime,
          startTimes.m_data[v19]);
  startTimes.m_size = 0;
  if ( startTimes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      startTimes.m_data,
      4 * startTimes.m_capacityAndFlags);
  return v21;
}

// File Line: 2928
// RVA: 0xC79B10
void __fastcall hkMonitorStreamAnalyzer::gatherRawStreamTimerValues(const char *frameStart, const char *frameEnd, hkMonitorStreamFrameInfo *frameInfo, const char **timerNames, int numTimers, float *valuesOut)
{
  const char **v6; // r15
  hkMonitorStreamFrameInfo *v7; // r12
  const char *v8; // rsi
  hkMonitorStream::TimerCommand *v9; // rdi
  char *v10; // rax
  int v11; // er9
  char *v12; // r13
  __int64 v13; // r8
  int v14; // eax
  signed __int64 v15; // rbp
  _DWORD *v16; // rcx
  __int64 v17; // rdx
  signed __int64 v18; // r14
  signed __int64 v19; // rsi
  const char *v20; // rbx
  hkMonitorStreamAnalyzer::Node *v21; // rax
  int v22; // eax
  const char *v23; // r15
  signed __int64 v24; // rbx
  __int64 v25; // rsi
  _DWORD *v26; // rbx
  hkMonitorStreamAnalyzer::Node *v27; // rsi
  __int64 v28; // r14
  hkMonitorStream::TimerCommand *v29; // r8
  signed __int64 v30; // rbx
  __int64 v31; // rsi
  __int64 v32; // r10
  float *v33; // r9
  float *v34; // rcx
  signed __int64 v35; // rdx
  unsigned __int64 v36; // r8
  int v37; // eax
  float *v38; // rcx
  float v39; // eax
  int v40; // ebx
  hkMonitorStreamAnalyzer::Node *v41; // rdi
  signed __int64 v42; // rbx
  hkMonitorStreamAnalyzer::Node *v43; // rsi
  __int64 v44; // r14
  _DWORD *v45; // rbx
  hkMonitorStreamAnalyzer::Node *v46; // rsi
  __int64 v47; // r14
  hkMonitorStream::TimerCommand *v48; // r8
  __int64 v49; // rsi
  signed __int64 v50; // rbx
  __int64 v51; // r14
  int v52; // [rsp+20h] [rbp-E8h]
  __int64 v53; // [rsp+28h] [rbp-E0h]
  int v54; // [rsp+30h] [rbp-D8h]
  hkMonitorStreamAnalyzer::Node v55; // [rsp+38h] [rbp-D0h]
  const char *v56; // [rsp+118h] [rbp+10h]
  hkMonitorStreamFrameInfo *v57; // [rsp+120h] [rbp+18h]

  v57 = frameInfo;
  v56 = frameEnd;
  v6 = timerNames;
  v7 = frameInfo;
  v8 = frameEnd;
  v9 = (hkMonitorStream::TimerCommand *)frameStart;
  if ( numTimers > 0 )
  {
    v52 = 168 * numTimers;
    v10 = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    &v52);
    v11 = numTimers;
    v12 = v10;
    v13 = numTimers;
    v53 = numTimers;
    v14 = 2147483648;
    if ( v52 / 168 )
      v14 = v52 / 168;
    v15 = 0i64;
    v54 = v14;
    if ( numTimers > 0 )
    {
      v16 = v12 + 108;
      v17 = numTimers;
      do
      {
        if ( v16 != (_DWORD *)108 )
        {
          *(_QWORD *)(v16 - 3) = 0i64;
          *(v16 - 1) = 0;
          *v16 = 2147483648;
        }
        v16 += 42;
        --v17;
      }
      while ( v17 );
    }
    v18 = 0i64;
    if ( numTimers > 0 )
    {
      v19 = (signed __int64)(v12 + 152);
      do
      {
        v20 = v6[v18];
        hkMonitorStreamAnalyzer::Node::Node(&v55, 0i64, v6[v18], 0);
        hkMonitorStreamAnalyzer::Node::operator=((hkMonitorStreamAnalyzer::Node *)(v19 - 152), v21);
        hkMonitorStreamAnalyzer::Node::~Node(&v55);
        v22 = hkString::strLen(v20);
        ++v18;
        *(_QWORD *)v19 = 0i64;
        *(_DWORD *)(v19 + 8) = 0;
        v19 += 168i64;
        *(_DWORD *)(v19 - 176) = v22 + 1;
      }
      while ( v18 < numTimers );
      v7 = v57;
      v13 = v53;
      v11 = numTimers;
      v8 = v56;
    }
    if ( v9 < (hkMonitorStream::TimerCommand *)v8 )
    {
      while ( 1 )
      {
        v23 = v9->m_commandAndMonitor;
        if ( v9->m_commandAndMonitor >= (const char *)0x14 )
          break;
        v9 = (hkMonitorStream::TimerCommand *)((char *)v9 + 4);
LABEL_46:
        v13 = v53;
        v11 = numTimers;
        if ( v9 >= (hkMonitorStream::TimerCommand *)v8 )
          goto LABEL_47;
      }
      switch ( *v23 )
      {
        case 69:
          if ( v11 <= 0 )
            goto LABEL_25;
          v26 = v12 + 160;
          v27 = (hkMonitorStreamAnalyzer::Node *)v12;
          v28 = (unsigned int)v11;
          do
          {
            v29 = (hkMonitorStream::TimerCommand *)*((_QWORD *)v26 - 1);
            if ( v29 )
            {
              if ( *v26 )
              {
                --*v26;
              }
              else
              {
                hkMonitorStreamAnalyzer::Node::setTimers(v27, v7, v29, v9);
                *((_QWORD *)v26 - 1) = 0i64;
              }
            }
            v27 = (hkMonitorStreamAnalyzer::Node *)((char *)v27 + 168);
            v26 += 42;
            --v28;
          }
          while ( v28 );
          v8 = v56;
          ++v9;
          goto LABEL_46;
        case 76:
          if ( v13 <= 0 )
            goto $LN6_186;
          v30 = (signed __int64)(v12 + 128);
          v31 = v13;
          break;
        case 77:
          if ( v13 <= 0 )
            goto LABEL_25;
          v49 = 0i64;
          v50 = (signed __int64)(v12 + 128);
          v51 = v13;
          do
          {
            if ( !hkString::memCmp(v23 + 2, *(const void **)v50, *(_DWORD *)(v50 + 16)) )
            {
              *(_DWORD *)(v50 + 12) = 2;
              *(_DWORD *)&v12[4 * (v49 + v7->m_indexOfTimer0)] = v9->m_time0;
              ++*(_DWORD *)&v12[4 * (v49 + v7->m_indexOfTimer0) + 48];
            }
            v50 += 168i64;
            v49 += 42i64;
            --v51;
          }
          while ( v51 );
          v8 = v56;
          ++v9;
          goto LABEL_46;
        case 78:
        case 80:
        case 112:
          v9 = (hkMonitorStream::TimerCommand *)((char *)v9 + 8);
          goto LABEL_46;
        case 79:
        case 109:
$LN6_186:
          v9 = (hkMonitorStream::TimerCommand *)((char *)v9 + 24);
          goto LABEL_46;
        case 83:
          if ( v11 <= 0 )
            goto LABEL_25;
          v42 = (signed __int64)(v12 + 152);
          v43 = (hkMonitorStreamAnalyzer::Node *)v12;
          v44 = (unsigned int)v11;
          do
          {
            if ( *(_QWORD *)v42 )
            {
              if ( !*(_DWORD *)(v42 + 8) )
              {
                hkMonitorStreamAnalyzer::Node::setTimers(v43, v7, *(hkMonitorStream::TimerCommand **)v42, v9);
                *(_QWORD *)v42 = 0i64;
              }
            }
            else if ( !hkString::memCmp(v23 + 2, *(const void **)(v42 - 24), *(_DWORD *)(v42 - 8)) )
            {
              *(_QWORD *)v42 = v9;
              *(_DWORD *)(v42 + 8) = 0;
            }
            v43 = (hkMonitorStreamAnalyzer::Node *)((char *)v43 + 168);
            v42 += 168i64;
            --v44;
          }
          while ( v44 );
          v8 = v56;
          ++v9;
          goto LABEL_46;
        case 84:
          if ( v13 > 0 )
          {
            v24 = (signed __int64)(v12 + 152);
            v25 = v13;
            do
            {
              if ( *(_QWORD *)v24 )
              {
                ++*(_DWORD *)(v24 + 8);
              }
              else if ( !hkString::memCmp(v23 + 2, *(const void **)(v24 - 24), *(_DWORD *)(v24 - 8)) )
              {
                *(_QWORD *)v24 = v9;
                *(_DWORD *)(v24 + 8) = 0;
              }
              v24 += 168i64;
              --v25;
            }
            while ( v25 );
            v8 = v56;
          }
          goto LABEL_25;
        case 108:
          if ( v11 <= 0 )
          {
LABEL_25:
            ++v9;
          }
          else
          {
            v45 = v12 + 160;
            v46 = (hkMonitorStreamAnalyzer::Node *)v12;
            v47 = (unsigned int)v11;
            do
            {
              v48 = (hkMonitorStream::TimerCommand *)*((_QWORD *)v45 - 1);
              if ( v48 )
              {
                if ( *v45 <= 1 )
                {
                  hkMonitorStreamAnalyzer::Node::setTimers(v46, v7, v48, v9);
                  *((_QWORD *)v45 - 1) = 0i64;
                }
                *v45 -= 2;
              }
              v46 = (hkMonitorStreamAnalyzer::Node *)((char *)v46 + 168);
              v45 += 42;
              --v47;
            }
            while ( v47 );
            v8 = v56;
            ++v9;
          }
          goto LABEL_46;
        default:
          goto LABEL_46;
      }
      while ( 1 )
      {
        if ( *(_QWORD *)(v30 + 24) )
        {
          *(_DWORD *)(v30 + 32) += 2;
        }
        else
        {
          if ( !hkString::memCmp(v23 + 2, *(const void **)v30, *(_DWORD *)(v30 + 16)) )
          {
            *(_DWORD *)(v30 + 32) = 1;
LABEL_42:
            *(_QWORD *)(v30 + 24) = v9;
            goto LABEL_43;
          }
          if ( !hkString::memCmp(v9[1].m_commandAndMonitor + 2, *(const void **)v30, *(_DWORD *)(v30 + 16)) )
          {
            *(_DWORD *)(v30 + 32) = 0;
            goto LABEL_42;
          }
        }
LABEL_43:
        v30 += 168i64;
        if ( !--v31 )
        {
          v8 = v56;
          goto $LN6_186;
        }
      }
    }
LABEL_47:
    v32 = v53;
    v33 = valuesOut;
    if ( v53 >= 4 )
    {
      v34 = valuesOut + 2;
      v35 = (signed __int64)(v12 + 336);
      v36 = ((unsigned __int64)(v53 - 4) >> 2) + 1;
      v15 = 4 * v36;
      do
      {
        v37 = *(_DWORD *)(v35 - 336);
        v34 += 4;
        v35 += 672i64;
        *((_DWORD *)v34 - 6) = v37;
        *(v34 - 5) = *(float *)(v35 - 840);
        *(v34 - 4) = *(float *)(v35 - 672);
        *(v34 - 3) = *(float *)(v35 - 504);
        --v36;
      }
      while ( v36 );
    }
    if ( v15 < v32 )
    {
      v38 = (float *)&v12[168 * v15];
      do
      {
        v39 = *v38;
        ++v15;
        v38 += 42;
        valuesOut[v15 - 1] = v39;
      }
      while ( v15 < v32 );
    }
    v40 = numTimers - 1;
    if ( numTimers - 1 >= 0 )
    {
      v41 = (hkMonitorStreamAnalyzer::Node *)&v12[168 * v40];
      do
      {
        hkMonitorStreamAnalyzer::Node::~Node(v41);
        v41 = (hkMonitorStreamAnalyzer::Node *)((char *)v41 - 168);
        --v40;
      }
      while ( v40 >= 0 );
    }
    if ( v54 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, float *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v12,
        168 * (v54 & 0x3FFFFFFFu),
        v33);
  }
}

