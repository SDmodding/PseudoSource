// File Line: 114
// RVA: 0x146F980
__int64 UFG::DataStreamer::_dynamic_initializer_for__gStallRecordNames__()
{
  `eh vector constructor iterator'(
    UFG::DataStreamer::gStallRecordNames,
    0x28ui64,
    5,
    (void (__fastcall *)(void *))UFG::qString::qString);
  return atexit(UFG::DataStreamer::_dynamic_atexit_destructor_for__gStallRecordNames__);
}

// File Line: 117
// RVA: 0x22CE70
void __fastcall UFG::DataStreamer::ResetLoopConditionDetection(UFG::DataStreamer *this)
{
  qword_142370784 = 1i64;
  qword_142370798 = 2i64;
  qword_1423707AC = 3i64;
  dword_1423707C0 = 4;
  qword_142370764 = 0i64;
  UFG::DataStreamer::gStallRecord[0].lastFrame = 0;
  qword_14237076C = 0i64;
  qword_142370778 = 0i64;
  dword_142370774 = 0;
  dword_142370780 = 0;
  qword_14237078C = 0i64;
  dword_142370794 = 0;
  qword_1423707A0 = 0i64;
  dword_1423707A8 = 0;
  qword_1423707B4 = 0i64;
  dword_1423707BC = 0;
}

// File Line: 135
// RVA: 0x2271F0
void __fastcall UFG::DataStreamer::Handle::~Handle(UFG::DataStreamer::Handle *this)
{
  UFG::DataStreamer::Handle *v1; // rbx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v2; // rdx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v3; // rax

  v1 = this;
  UFG::DataStreamer::ReleaseStream(this);
  v2 = v1->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
}

// File Line: 195
// RVA: 0x226E70
void __fastcall UFG::DataStreamer::StreamInfo::StreamInfo(UFG::DataStreamer::StreamInfo *this, unsigned int uid)
{
  UFG::DataStreamer::StreamInfo *v2; // rbx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v3; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v4; // rax
  UFG::qList<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  v3 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v4 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->mStateCurrent = 1;
  *(_QWORD *)&this->mDataType = 0i64;
  *((_WORD *)this + 40) &= 0xFE08u;
  this->mDeactivationTicks = 0;
  *(_QWORD *)&this->mFileSizePerm.load_offset = 0i64;
  *(_QWORD *)&this->mFileSizePerm.compressed_extra = 0i64;
  this->mhBufferPerm = -1i64;
  this->mhFilePerm = 0i64;
  *(_QWORD *)&this->mFileSizeTemp.load_offset = 0i64;
  *(_QWORD *)&this->mFileSizeTemp.compressed_extra = 0i64;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&this->mhBufferTemp);
  v2->mhFileTemp = 0i64;
  UFG::qString::qString(&v2->mFileName);
  v2->mTagSymbolUID = -1;
  v5 = &v2->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  *(_QWORD *)&v2->mFlagsAND = 0i64;
  v2->mDataLoadedTo = 0;
}

// File Line: 244
// RVA: 0x229820
unsigned __int64 __fastcall UFG::DataStreamer::GetDiskPosSortKey(const char *filename)
{
  const char *v1; // rbx
  unsigned __int64 result; // rax
  UFG::BIGFileIndex::Entry *_entry; // [rsp+38h] [rbp+10h]
  UFG::BIGFileIndex *_bigFile; // [rsp+40h] [rbp+18h]

  v1 = filename;
  _bigFile = 0i64;
  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) )
    result = _bigFile->mSortKey + (4 * (unsigned __int64)_entry->offset_div_4 >> 11);
  else
    result = UFG::qStringHash64(v1, 0xFFFFFFFFFFFFFFFFui64) & 0x8000000000000000ui64;
  return result;
}

// File Line: 284
// RVA: 0x22CB70
void __fastcall UFG::DataStreamer::StreamInfo::RecacheHandleInfo(UFG::DataStreamer::StreamInfo *this)
{
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v1; // r9
  UFG::qList<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle,1,0> *v2; // r10
  signed int v3; // er8
  UFG::DataStreamer::StreamInfo *v4; // rdx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v5; // rax
  unsigned int v6; // ecx
  signed int v7; // ecx

  v1 = this->mHandles.mNode.mNext;
  v2 = &this->mHandles;
  v3 = 1;
  v4 = this;
  this->mStateTarget = 1;
  v5 = v1;
  if ( v1 != (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&this->mHandles )
  {
    do
    {
      v6 = LOWORD(v5[2].mNext);
      if ( v5 == v1 )
      {
        v4->mFlagsAND = v6;
        v4->mFlagsOR = LOWORD(v5[2].mNext);
      }
      else
      {
        v4->mFlagsAND &= v6;
        v4->mFlagsAND |= LOWORD(v5[2].mNext);
      }
      v7 = WORD2(v5[2].mNext);
      if ( v7 > v3 )
      {
        v3 = WORD2(v5[2].mNext);
        v4->mStateTarget = v7;
      }
      v5 = v5->mNext;
    }
    while ( v5 != (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)v2 );
  }
}

// File Line: 312
// RVA: 0x146FB90
__int64 UFG::DataStreamer::_dynamic_initializer_for__mStreamInfo__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::DataStreamer::mStreamInfo.mTree);
  return atexit(UFG::DataStreamer::_dynamic_atexit_destructor_for__mStreamInfo__);
}

// File Line: 347
// RVA: 0x146FB70
__int64 UFG::DataStreamer::_dynamic_initializer_for__mPriorityList__()
{
  return atexit(UFG::DataStreamer::_dynamic_atexit_destructor_for__mPriorityList__);
}

// File Line: 348
// RVA: 0x146FB50
__int64 UFG::DataStreamer::_dynamic_initializer_for__mOrderList__()
{
  return atexit(UFG::DataStreamer::_dynamic_atexit_destructor_for__mOrderList__);
}

// File Line: 479
// RVA: 0x22A460
void __fastcall UFG::DataStreamer::Initialize(UFG::DataStreamer *this)
{
  UFG::DataStreamer::mFileOperationCount = 0;
  UFG::StreamResourceLoader::ResetResourceTimings(this);
  UFG::BandwidthHistory::smCurrentBandwidthTick = 0;
  UFG::qMemSet(UFG::BandwidthHistory::smTickHistoryRaw, 0, 0xE4Cu);
  UFG::qMemSet(UFG::BandwidthHistory::smTickHistoryAveraged, 0, 0xE4Cu);
  UFG::qMemSet(UFG::DataStreamer::mStateCountThis, 0, 0x20u);
  UFG::qMemSet(UFG::DataStreamer::mStateCountPrev, 0, 0x20u);
  qword_142370764 = 0i64;
  UFG::DataStreamer::gStallRecord[0].lastFrame = 0;
  qword_14237076C = 0i64;
  qword_142370778 = 0i64;
  dword_142370774 = 0;
  dword_142370780 = 0;
  qword_142370784 = 1i64;
  qword_14237078C = 0i64;
  dword_142370794 = 0;
  qword_142370798 = 2i64;
  qword_1423707A0 = 0i64;
  dword_1423707A8 = 0;
  qword_1423707AC = 3i64;
  qword_1423707B4 = 0i64;
  dword_1423707BC = 0;
  dword_1423707C0 = 4;
}

// File Line: 573
// RVA: 0x22A550
char __fastcall UFG::DataStreamer::IsBusy(UFG::StreamingMemory::DATA_TYPE *dataTypes, unsigned int numDataTypes)
{
  unsigned int v2; // ebx
  UFG::StreamingMemory::DATA_TYPE *v3; // rdi
  UFG::qBaseTreeRB *v5; // r9
  unsigned int v6; // edx
  UFG::StreamingMemory::DATA_TYPE *v7; // rcx

  v2 = numDataTypes;
  v3 = dataTypes;
  if ( dataTypes )
  {
    v5 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
    if ( v5 )
    {
      while ( 1 )
      {
        v6 = 0;
        if ( v2 )
        {
          v7 = v3;
          while ( LODWORD(v5[1].mRoot.mParent) != *v7 )
          {
            ++v6;
            ++v7;
            if ( v6 >= v2 )
              goto LABEL_11;
          }
          if ( (unsigned int)(v5->mCount - 2) <= 1 )
            return 1;
        }
LABEL_11:
        v5 = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &v5->mRoot);
        if ( !v5 )
          return 0;
      }
    }
  }
  else if ( *(_QWORD *)&UFG::DataStreamer::mStateCountThis[2] > 0ui64 )
  {
    return 1;
  }
  return 0;
}

// File Line: 613
// RVA: 0x22A5F0
char __fastcall UFG::DataStreamer::IsInLoopCondition(UFG::StreamingMemory::DATA_TYPE *dataTypes, unsigned int numDataTypes)
{
  unsigned int v2; // er10
  _DWORD *v3; // r9
  unsigned int v4; // er8
  UFG::StreamingMemory::DATA_TYPE *v5; // rax

  v2 = 0;
  v3 = (_DWORD *)((char *)&qword_142370764 + 4);
  while ( 1 )
  {
    v4 = 0;
    if ( numDataTypes )
      break;
LABEL_6:
    if ( numDataTypes == 0 )
      goto LABEL_7;
LABEL_9:
    ++v2;
    v3 += 5;
    if ( v2 >= 5 )
      return 0;
  }
  v5 = dataTypes;
  while ( v3[1] != *v5 )
  {
    ++v4;
    ++v5;
    if ( v4 >= numDataTypes )
      goto LABEL_6;
  }
LABEL_7:
  if ( *v3 <= 0x64u || UFG::Metrics::msFrameCount - *(v3 - 2) >= 0x1E )
    goto LABEL_9;
  return 1;
}

// File Line: 642
// RVA: 0x22A670
char __fastcall UFG::DataStreamer::IsStalled(UFG::StreamingMemory::DATA_TYPE *dataTypes, unsigned int numDataTypes)
{
  unsigned int v2; // er9
  UFG::StreamingMemory::DATA_TYPE *v3; // r11
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v5; // rdx
  char v6; // r10
  unsigned int v7; // ecx
  UFG::StreamingMemory::DATA_TYPE *v8; // rax
  int v9; // eax

  v2 = numDataTypes;
  v3 = dataTypes;
  if ( dataTypes )
  {
    v5 = UFG::DataStreamer::mOrderList.mNode.mNext - 2;
    v6 = 0;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)&UFG::DataStreamer::mOrderList.mNode.mNext[-2] == &UFG::DataStreamer::mOrderList - 2 )
      return v6;
    while ( 1 )
    {
      v7 = 0;
      if ( v2 )
      {
        v8 = v3;
        while ( LODWORD(v5[4].mNext) != *v8 )
        {
          ++v7;
          ++v8;
          if ( v7 >= v2 )
            goto LABEL_18;
        }
        v9 = (int)v5[4].mPrev;
        if ( v9 == 3 )
          return 0;
        if ( v9 == 2 )
        {
          if ( *((float *)&v5[4].mNext + 1) < 1.0 )
            return 0;
          v6 = 1;
        }
      }
LABEL_18:
      v5 = v5[2].mNext - 2;
      if ( v5 == (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)(&UFG::DataStreamer::mOrderList
                                                                                            - 2) )
        return v6;
    }
  }
  return UFG::DataStreamer::mStateCountThis[2]
      && !UFG::DataStreamer::mStateCountThis[3]
      && !UFG::DataStreamer::mStateCountPrev[3]
      && UFG::DataStreamer::mStateCountThis[2] <= UFG::DataStreamer::mStateCountPrev[2];
}

// File Line: 700
// RVA: 0x228120
void __fastcall UFG::DataStreamer::BeginTagging(UFG::StreamingMemory::DATA_TYPE *dataTypes, unsigned int numDataTypes)
{
  UFG::StreamingMemory::DATA_TYPE *v2; // rdi
  unsigned int v3; // ebx
  UFG::qBaseTreeRB *i; // r8
  unsigned int v5; // ecx
  UFG::StreamingMemory::DATA_TYPE *v6; // rax

  v2 = dataTypes;
  v3 = numDataTypes;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &i->mRoot) )
  {
    v5 = 0;
    if ( v3 )
    {
      v6 = v2;
      while ( LODWORD(i[1].mRoot.mParent) != *v6 )
      {
        ++v5;
        ++v6;
        if ( v5 >= v3 )
          goto LABEL_10;
      }
      if ( (unsigned int)(i->mCount - 2) > 1 )
        LOWORD(i[1].mRoot.mChild[0]) &= 0xFF7Fu;
      else
        LOWORD(i[1].mRoot.mChild[0]) |= 0x80u;
    }
LABEL_10:
    ;
  }
  UFG::DataStreamer::mbTagging = 1;
}

// File Line: 740
// RVA: 0x2281C0
void __fastcall UFG::DataStreamer::BeginTagging(UFG::DataStreamer *this)
{
  UFG::qBaseTreeRB *i; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &i->mRoot) )
  {
    if ( (unsigned int)(i->mCount - 2) > 1 )
      LOWORD(i[1].mRoot.mChild[0]) &= 0xFF7Fu;
    else
      LOWORD(i[1].mRoot.mChild[0]) |= 0x80u;
  }
  UFG::DataStreamer::mbTagging = 1;
}

// File Line: 767
// RVA: 0x228D20
void __fastcall UFG::DataStreamer::EndTagging(UFG::DataStreamer *this)
{
  UFG::qBaseTreeRB *i; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &i->mRoot) )
  {
    LOWORD(i[1].mRoot.mChild[0]) &= 0xFF7Fu;
  }
  UFG::DataStreamer::mbTagging = 0;
}

// File Line: 781
// RVA: 0x22A790
char __fastcall UFG::DataStreamer::IsTaggedStalled()
{
  float v0; // xmm6_4
  UFG::qBaseTreeRB *v1; // rax
  char result; // al

  v0 = FLOAT_3_4028235e38;
  v1 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
  if ( !v1 )
    goto LABEL_15;
  do
  {
    if ( SLOBYTE(v1[1].mRoot.mChild[0]) < 0 )
    {
      if ( v1->mCount == 2 )
      {
        if ( v0 >= *((float *)&v1[1].mRoot.mParent + 1) )
          v0 = *((float *)&v1[1].mRoot.mParent + 1);
      }
      else if ( v1->mCount == 3 )
      {
        return 0;
      }
    }
    v1 = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &v1->mRoot);
  }
  while ( v1 );
  if ( v0 < 3.4028235e38 && v0 > 1.0 )
    result = 1;
  else
LABEL_15:
    result = 0;
  return result;
}

// File Line: 814
// RVA: 0x22A740
bool __fastcall UFG::DataStreamer::IsTaggedBusy()
{
  UFG::qBaseTreeRB *i; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &i->mRoot) )
  {
    if ( SLOBYTE(i[1].mRoot.mChild[0]) < 0 && (i->mCount == 2 || i->mCount == 3) )
    {
      LOBYTE(i) = 1;
      return (char)i;
    }
  }
  return (char)i;
}

// File Line: 931
// RVA: 0x227EB0
UFG::DataStreamer::StreamInfo *__fastcall UFG::DataStreamer::AllocateStreamInfo(const char *fileName, unsigned int streamUID)
{
  unsigned int v2; // ebx
  const char *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::DataStreamer::StreamInfo *v5; // rax
  UFG::DataStreamer::StreamInfo *v6; // rbx

  v2 = streamUID;
  v3 = fileName;
  v4 = UFG::qMalloc(0x108ui64, "AllocateStreamInfo", 0x800ui64);
  if ( v4 )
  {
    UFG::DataStreamer::StreamInfo::StreamInfo((UFG::DataStreamer::StreamInfo *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qString::Set(&v6->mFileName, v3);
  v6->mStateCurrent = 1;
  v6->mDiskPosSortKey = -1i64;
  *((_WORD *)v6 + 40) &= 0xFF7Fu;
  *(_QWORD *)&v6->mFileSizePerm.load_offset = 0i64;
  *(_QWORD *)&v6->mFileSizePerm.compressed_extra = 0i64;
  *(_QWORD *)&v6->mFileSizeTemp.load_offset = 0i64;
  *(_QWORD *)&v6->mFileSizeTemp.compressed_extra = 0i64;
  UFG::qBaseTreeRB::Add(&UFG::DataStreamer::mStreamInfo.mTree, &v6->mNode);
  return v6;
}

// File Line: 978
// RVA: 0x22C360
char __fastcall UFG::DataStreamer::QueueStream(UFG::DataStreamer::Handle *handle, const char *filename, unsigned int mem_tag_qsymbol_uid, UFG::StreamingMemory::DATA_TYPE data_type, UFG::DataStreamer::PRIORITY priority, unsigned int flags, void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *), void *callbackParam)
{
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v8; // rax
  UFG::StreamingMemory::DATA_TYPE v9; // er14
  unsigned int v10; // er15
  const char *v11; // rbp
  UFG::DataStreamer::Handle *v12; // rbx
  UFG::DataStreamer::StreamInfo *v13; // rcx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v14; // rdx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v15; // rax
  unsigned int v16; // eax
  unsigned int v17; // esi
  UFG::DataStreamer::StreamInfo *v18; // rdi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v19; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v20; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v21; // rdx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v22; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v23; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v24; // rcx
  void (__fastcall *v25)(UFG::DataStreamer::Handle *, void *); // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v26; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v27; // rcx

  v8 = handle->mPrev;
  v9 = data_type;
  v10 = mem_tag_qsymbol_uid;
  v11 = filename;
  v12 = handle;
  if ( (UFG::DataStreamer::Handle *)handle->mPrev != handle || (UFG::DataStreamer::Handle *)handle->mNext != handle )
  {
    v13 = (UFG::DataStreamer::StreamInfo *)handle->mImpl;
    if ( v13 )
    {
      if ( v8 != (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)v12
        || (UFG::DataStreamer::Handle *)v12->mNext != v12 )
      {
        if ( v12 == UFG::DataStreamer::gCurrentStreamHandle )
          UFG::DataStreamer::gCurrentStreamHandle = (UFG::DataStreamer::Handle *)UFG::DataStreamer::gCurrentStreamHandle->mPrev;
        v14 = v12->mPrev;
        v15 = v12->mNext;
        v14->mNext = v15;
        v15->mPrev = v14;
        v12->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v12->mPrev;
        v12->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v12->mPrev;
        v12->_mTargetState.mValue = 1;
        UFG::DataStreamer::StreamInfo::RecacheHandleInfo(v13);
        v12->mImpl = 0i64;
        v12->mCallback = 0i64;
        v12->mCallbackParam = 0i64;
      }
    }
  }
  v16 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v11);
  v17 = v16;
  if ( v16 )
    v18 = (UFG::DataStreamer::StreamInfo *)UFG::qBaseTreeRB::Get(&UFG::DataStreamer::mStreamInfo.mTree, v16);
  else
    v18 = 0i64;
  if ( v18 )
  {
    v19 = v18->mPrev;
    v20 = v18->mNext;
    v21 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&v18->mPrev;
    v19->mNext = v20;
    v20->mPrev = v19;
    v21->mPrev = v21;
    v21->mNext = v21;
  }
  else
  {
    v18 = UFG::DataStreamer::AllocateStreamInfo(v11, v17);
  }
  if ( !v18 )
    return 0;
  *((_WORD *)v18 + 40) &= 0xFFEFu;
  *((_WORD *)v18 + 40) |= 16 * ((flags >> 4) & 1);
  if ( v18->mDiskPosSortKey == -1i64 )
    v18->mDiskPosSortKey = UFG::DataStreamer::GetDiskPosSortKey(v11);
  v12->mFlags = flags;
  v12->mImpl = v18;
  v12->mCallback = callback;
  v12->mCallbackParam = callbackParam;
  v12->mPriority.mValue = priority;
  v18->mDataType = v9;
  v22 = v18->mHandles.mNode.mPrev;
  v22->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v12->mPrev;
  v12->mPrev = v22;
  v12->mNext = &v18->mHandles.mNode;
  v18->mHandles.mNode.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v12->mPrev;
  v18->mTagSymbolUID = v10;
  v23 = UFG::DataStreamer::mOrderList.mNode.mPrev;
  v24 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&v18->mPrev;
  UFG::DataStreamer::mOrderList.mNode.mPrev->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&v18->mPrev;
  v24->mPrev = v23;
  v24->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&UFG::DataStreamer::mOrderList;
  UFG::DataStreamer::mOrderList.mNode.mPrev = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&v18->mPrev;
  if ( v18->mStateCurrent == 6 )
  {
    v25 = v12->mCallback;
    if ( v25 )
      v25(v12, v12->mCallbackParam);
  }
  v12->_mTargetState.mValue = 6;
  if ( v18->mStateCurrent == 1 )
  {
    v18->mStateCurrent = 2;
    v18->mTimeInState = 0.0;
    v26 = UFG::DataStreamer::mPriorityList.mNode.mPrev;
    v27 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v18->mPrev;
    UFG::DataStreamer::mPriorityList.mNode.mPrev->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v18->mPrev;
    v27->mPrev = v26;
    v27->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&UFG::DataStreamer::mPriorityList;
    UFG::DataStreamer::mPriorityList.mNode.mPrev = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v18->mPrev;
  }
  UFG::DataStreamer::StreamInfo::RecacheHandleInfo(v18);
  return 1;
}

// File Line: 1085
// RVA: 0x22C580
char __fastcall UFG::DataStreamer::QueueStream(UFG::DataStreamer::Handle *handle, const char *filename, UFG::StreamingMemory::DATA_TYPE data_type, UFG::DataStreamer::PRIORITY priority, unsigned int flags, void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *), void *callbackParam)
{
  return UFG::DataStreamer::QueueStream(
           handle,
           filename,
           0xFFFFFFFF,
           data_type,
           priority,
           flags,
           callback,
           callbackParam);
}

// File Line: 1100
// RVA: 0x22CBE0
char __fastcall UFG::DataStreamer::ReleaseStream(UFG::DataStreamer::Handle *handle)
{
  UFG::DataStreamer::Handle *v1; // rbx
  UFG::DataStreamer::StreamInfo *v2; // rcx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v3; // rax
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v4; // rdx
  char result; // al

  v1 = handle;
  v2 = (UFG::DataStreamer::StreamInfo *)handle->mImpl;
  if ( !v2 || (UFG::DataStreamer::Handle *)v1->mPrev == v1 && (UFG::DataStreamer::Handle *)v1->mNext == v1 )
    return 0;
  if ( v1 == UFG::DataStreamer::gCurrentStreamHandle )
    UFG::DataStreamer::gCurrentStreamHandle = (UFG::DataStreamer::Handle *)UFG::DataStreamer::gCurrentStreamHandle->mPrev;
  v3 = v1->mNext;
  v4 = v1->mPrev;
  v4->mNext = v3;
  v3->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
  v1->_mTargetState.mValue = 1;
  UFG::DataStreamer::StreamInfo::RecacheHandleInfo(v2);
  result = 1;
  v1->mImpl = 0i64;
  v1->mCallback = 0i64;
  v1->mCallbackParam = 0i64;
  return result;
}

// File Line: 1143
// RVA: 0x22EFB0
void __fastcall UFG::DataStreamer::fnDataStreamCallback(UFG::qFileOp *file_op, void *callback_param)
{
  UFG::DataStreamer::OnFileCompletionCallback(file_op, callback_param);
}

// File Line: 1148
// RVA: 0x229290
void __fastcall UFG::DataStreamer::FireStreamLoadCallback(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::Handle *v1; // rax
  UFG::DataStreamer::Handle *v2; // rbx
  void (__fastcall *v3)(UFG::DataStreamer::Handle *, void *); // r8

  v1 = (UFG::DataStreamer::Handle *)streamInfo->mHandles.mNode.mNext;
  v2 = (UFG::DataStreamer::Handle *)&streamInfo->mHandles;
  UFG::DataStreamer::gCurrentStreamHandle = v1;
  if ( v1 != (UFG::DataStreamer::Handle *)&streamInfo->mHandles )
  {
    do
    {
      v3 = v1->mCallback;
      if ( v3 )
      {
        v3(v1, v1->mCallbackParam);
        v1 = UFG::DataStreamer::gCurrentStreamHandle;
      }
      v1 = (UFG::DataStreamer::Handle *)v1->mNext;
      UFG::DataStreamer::gCurrentStreamHandle = v1;
    }
    while ( v1 != v2 );
  }
  UFG::DataStreamer::gCurrentStreamHandle = 0i64;
}

// File Line: 1162
// RVA: 0x22AEA0
void __fastcall UFG::DataStreamer::LoadStreamResources(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::StreamInfo *v1; // rdi
  unsigned int v2; // er8
  char v3; // cl
  unsigned int v4; // er9
  unsigned int v5; // er10
  unsigned int v6; // er11
  unsigned int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // rdx
  UFG::qBaseTreeRB *v12; // rax
  char *v13; // r12
  __int64 v14; // r13
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int *v17; // rbx
  char *v18; // r14
  unsigned __int64 (*v19)[2]; // rsi
  __int64 v20; // r8
  unsigned int v21; // ecx
  unsigned __int64 (*v22)[2]; // rax
  __int64 v23; // rbp
  unsigned int v24; // edx
  UFG::qBaseTreeRB *v25; // rax
  __int64 v26; // rcx
  unsigned int v27; // eax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v28; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v29; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v30; // rax
  __int64 v31; // rsi
  unsigned int v32; // edx
  UFG::qBaseTreeRB *v33; // rax
  unsigned __int64 v34; // rdx
  UFG::qBaseTreeRB *v35; // rax
  UFG::qString v36; // [rsp+28h] [rbp-50h]

  v1 = streamInfo;
  v2 = UFG::Metrics::msFrameCount;
  v3 = 0;
  if ( (_DWORD)qword_142370764 == v1->mNode.mUID )
  {
    ++HIDWORD(qword_142370764);
    v4 = UFG::Metrics::msFrameCount;
    UFG::DataStreamer::gStallRecord[0].lastFrame = UFG::Metrics::msFrameCount;
    v3 = 1;
  }
  else
  {
    v4 = UFG::DataStreamer::gStallRecord[0].lastFrame;
  }
  if ( (_DWORD)qword_142370778 == v1->mNode.mUID )
  {
    ++HIDWORD(qword_142370778);
    v5 = UFG::Metrics::msFrameCount;
    dword_142370774 = UFG::Metrics::msFrameCount;
    v3 = 1;
  }
  else
  {
    v5 = dword_142370774;
  }
  if ( (_DWORD)qword_14237078C == v1->mNode.mUID )
  {
    ++HIDWORD(qword_14237078C);
    v6 = UFG::Metrics::msFrameCount;
    HIDWORD(qword_142370784) = UFG::Metrics::msFrameCount;
    v3 = 1;
  }
  else
  {
    v6 = HIDWORD(qword_142370784);
  }
  if ( (_DWORD)qword_1423707A0 == v1->mNode.mUID )
  {
    ++HIDWORD(qword_1423707A0);
    v7 = UFG::Metrics::msFrameCount;
    HIDWORD(qword_142370798) = UFG::Metrics::msFrameCount;
    v3 = 1;
  }
  else
  {
    v7 = HIDWORD(qword_142370798);
  }
  if ( (_DWORD)qword_1423707B4 == v1->mNode.mUID )
  {
    ++HIDWORD(qword_1423707B4);
    HIDWORD(qword_1423707AC) = UFG::Metrics::msFrameCount;
    goto LABEL_28;
  }
  if ( !v3 )
  {
    v8 = -1;
    v9 = -1;
    if ( v4 < 0xFFFFFFFF )
    {
      v8 = v4;
      v9 = 0;
    }
    if ( v5 < v8 )
    {
      v8 = v5;
      v9 = 1;
    }
    if ( v6 < v8 )
    {
      v8 = v6;
      v9 = 2;
    }
    if ( v7 < v8 )
    {
      v8 = v7;
      v9 = 3;
    }
    if ( HIDWORD(qword_1423707AC) >= v8 )
    {
      if ( v9 == -1 )
        goto LABEL_28;
    }
    else
    {
      v9 = 4;
    }
    v10 = 5i64 * v9;
    *((_DWORD *)&qword_142370764 + v10) = v1->mNode.mUID;
    UFG::DataStreamer::gStallRecord[v10 / 5].lastFrame = v2;
    *((_DWORD *)&qword_142370764 + v10 + 1) = 1;
    *((_DWORD *)&qword_14237076C + v10) = v1->mDataType;
  }
LABEL_28:
  if ( v1->mFlagsOR & 0x20 )
  {
    v1->mDataLoadedTo = v1->mFileSizePerm.uncompressed_size;
  }
  else
  {
    if ( *((_BYTE *)v1 + 80) & 0x10 )
    {
      UFG::qResourceInventory::SetHotSwapMode(1);
      Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
    }
    v11 = v1->mhBufferPerm;
    if ( (_DWORD)v11 )
      v12 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v11);
    else
      v12 = 0i64;
    v13 = (char *)v12[1].mRoot.mParent;
    v14 = v1->mFileSizePerm.uncompressed_size;
    if ( v1->mhBufferTemp.mData )
    {
      UFG::qString::qString(&v36, &v1->mFileName);
      v15 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v36.mData);
      UFG::qString::ReplaceString(&v36, "perm.bin", "temp.bin", 1);
      v16 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v36.mData);
      UFG::qChunkFileSystem::AddExternalResourceFileReference(v16, &v1->mhBufferTemp, v1);
      UFG::qChunkFileSystem::AddExternalResourceFileReference(v15, v13, (unsigned int)v14, 0i64);
      *((_WORD *)v1 + 40) |= 0x100u;
      UFG::qString::~qString(&v36);
    }
    ++foo_dfsdgs;
    v17 = (unsigned int *)v13;
    if ( v1->mDataType == 4 )
    {
      v18 = &v13[v14];
      if ( v13 < &v13[v14] )
      {
        v19 = sTypeToChunkUIDLookup[7];
        while ( 1 )
        {
          v20 = *v17;
          if ( (_DWORD)v20 )
            break;
LABEL_50:
          v17 = (unsigned int *)((char *)v17 + ((v17[1] + 3) & 0xFFFFFFFC) + 16);
          if ( v17 >= (unsigned int *)v18 )
            goto LABEL_57;
        }
        v21 = 0;
        v22 = sTypeToChunkUIDLookup[7];
        while ( (*v22)[0] != v20 )
        {
          ++v21;
          ++v22;
          if ( v21 >= 3 )
          {
            if ( (_DWORD)v20 )
            {
              v23 = v17[3];
              if ( !(_S2_9 & 1) )
              {
                _S2_9 |= 1u;
                qword_1423A8CE0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
              }
              v24 = *(unsigned int *)((char *)v17 + v23 + 64);
              if ( v24 )
              {
                v25 = UFG::qBaseTreeRB::Get(qword_1423A8CE0, v24);
                if ( v25 )
                {
                  if ( v25 != (UFG::qBaseTreeRB *)8 )
                    (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)&v25[-1].mCount + 72i64))(
                      &v25[-1].mCount,
                      (signed __int64)v17 + v23 + 16);
                }
              }
            }
            goto LABEL_50;
          }
        }
        if ( v17 < (unsigned int *)v18 )
        {
          v26 = *v17;
          if ( (_DWORD)v26 )
          {
            v27 = 0;
            do
            {
              if ( (*v19)[0] == v26 )
                break;
              ++v27;
              ++v19;
            }
            while ( v27 < 3 );
          }
        }
      }
LABEL_57:
      v1->mDataLoadedTo += (_DWORD)v17 - (_DWORD)v13;
      if ( v1->mDataLoadedTo != (_DWORD)v14 )
      {
        if ( v1->mStateCurrent == 2 )
        {
          v28 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v1->mPrev;
          v29 = v1->mPrev;
          v30 = v1->mNext;
          v29->mNext = v30;
          v30->mPrev = v29;
          v28->mPrev = v28;
          v28->mNext = v28;
        }
        v1->mStateCurrent = 4;
        v1->mTimeInState = 0.0;
      }
    }
    else
    {
      if ( v13 < &v13[v14] )
      {
        do
        {
          if ( *v17 )
          {
            v31 = v17[3];
            if ( !(_S2_9 & 1) )
            {
              _S2_9 |= 1u;
              qword_1423A8CE0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
            }
            v32 = *(unsigned int *)((char *)v17 + v31 + 64);
            if ( v32 )
            {
              v33 = UFG::qBaseTreeRB::Get(qword_1423A8CE0, v32);
              if ( v33 )
              {
                if ( v33 != (UFG::qBaseTreeRB *)8 )
                  (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)&v33[-1].mCount + 72i64))(
                    &v33[-1].mCount,
                    (signed __int64)v17 + v31 + 16);
              }
            }
          }
          v17 = (unsigned int *)((char *)v17 + ((v17[1] + 3) & 0xFFFFFFFC) + 16);
        }
        while ( v17 < (unsigned int *)&v13[v14] );
      }
      v1->mDataLoadedTo += (_DWORD)v17 - (_DWORD)v13;
    }
  }
  v34 = v1->mhBufferPerm;
  if ( (_DWORD)v34 )
  {
    v35 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v34);
    if ( v35 )
      LOWORD(v35->mNULL.mChild[1]) |= 0x100u;
  }
  if ( !(v1->mFlagsOR & 0x20) && *((_BYTE *)v1 + 80) & 0x10 )
    UFG::qResourceInventory::SetHotSwapMode(0);
  if ( v1->mStateCurrent != 4 )
    *((_WORD *)v1 + 40) |= 2u;
}m >> 32) & 0x1F]->mBlockLookup.mTree, v34);
    if ( v35 )
  

// File Line: 1300
// RVA: 0x229110
void __fastcall UFG::DataStreamer::FinishLoadingResources(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::StreamInfo *v1; // rdi
  unsigned __int64 v2; // rdx
  UFG::qBaseTreeRB *v3; // rcx
  __int64 v4; // r14
  __int64 v5; // rbp
  _DWORD *v6; // r14
  _DWORD *v7; // rbx
  unsigned __int64 v8; // rbp
  __int64 v9; // rsi
  unsigned int v10; // edx
  UFG::qBaseTreeRB *v11; // rax
  unsigned __int64 v12; // rdx
  UFG::qBaseTreeRB *v13; // rax

  v1 = streamInfo;
  if ( *((_BYTE *)streamInfo + 80) & 0x10 )
  {
    UFG::qResourceInventory::SetHotSwapMode(1);
    Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
  }
  if ( !(v1->mFlagsOR & 0x20) )
  {
    v2 = v1->mhBufferPerm;
    if ( (_DWORD)v2 )
      v3 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v2);
    else
      v3 = 0i64;
    v4 = v1->mDataLoadedTo;
    v5 = (unsigned int)(v1->mFileSizePerm.uncompressed_size - v4);
    v6 = (_DWORD *)((char *)v3[1].mRoot.mParent + v4);
    ++foo_dfsdgs;
    v7 = v6;
    v8 = (unsigned __int64)v6 + v5;
    if ( (unsigned __int64)v6 < v8 )
    {
      do
      {
        if ( *v7 )
        {
          v9 = (unsigned int)v7[3];
          if ( !(_S2_9 & 1) )
          {
            _S2_9 |= 1u;
            qword_1423A8CE0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
          }
          v10 = *(_DWORD *)((char *)v7 + v9 + 64);
          if ( v10 )
          {
            v11 = UFG::qBaseTreeRB::Get(qword_1423A8CE0, v10);
            if ( v11 )
            {
              if ( v11 != (UFG::qBaseTreeRB *)8 )
                (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)&v11[-1].mCount + 72i64))(
                  &v11[-1].mCount,
                  (signed __int64)v7 + v9 + 16);
            }
          }
        }
        v7 = (_DWORD *)((char *)v7 + ((v7[1] + 3) & 0xFFFFFFFC) + 16);
      }
      while ( (unsigned __int64)v7 < v8 );
    }
    v1->mDataLoadedTo += (_DWORD)v7 - (_DWORD)v6;
  }
  v12 = v1->mhBufferPerm;
  if ( (_DWORD)v12 )
  {
    v13 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v12);
    if ( v13 )
      LOWORD(v13->mNULL.mChild[1]) |= 0x100u;
  }
  if ( *((_BYTE *)v1 + 80) & 0x10 )
    UFG::qResourceInventory::SetHotSwapMode(0);
  *((_WORD *)v1 + 40) |= 2u;
}

// File Line: 1474
// RVA: 0x22ED00
char __fastcall UFG::DataStreamer::UnloadStreamResources(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::StreamInfo *v1; // rsi
  unsigned __int64 v2; // rdx
  UFG::StreamPool *v3; // rbx
  UFG::qBaseTreeRB *v4; // rax
  char result; // al
  unsigned __int64 v6; // rdx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseNodeRB *v8; // rdi
  __int64 v9; // rbp
  UFG::qBaseNodeRB *i; // rbp
  __int64 v11; // rbx
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  unsigned __int64 v14; // rdx
  UFG::qBaseTreeRB *v15; // rax
  char *v16; // rdi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned __int64 v20; // rdx
  UFG::qBaseTreeRB *v21; // rax
  UFG::qString v22; // [rsp+28h] [rbp-40h]

  v1 = streamInfo;
  v2 = streamInfo->mhBufferPerm;
  v3 = UFG::gStreamPools[(streamInfo->mhBufferPerm >> 32) & 0x1F];
  if ( v3->mDefragState.meState )
  {
    v4 = (_DWORD)v2 ? UFG::qBaseTreeRB::Get(&v3->mBlockLookup.mTree, v2) : 0i64;
    if ( v4 == (UFG::qBaseTreeRB *)v3->mDefragState.mMovingBlock )
      return 0;
  }
  v6 = v1->mhBufferPerm;
  if ( (_DWORD)v6 )
    v7 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v6);
  else
    v7 = 0i64;
  v8 = v7[1].mRoot.mParent;
  if ( !(v1->mFlagsOR & 0x20) )
  {
    v9 = v1->mFileSizePerm.uncompressed_size;
    UFG::qResourceWarehouse::Instance();
    for ( i = (UFG::qBaseNodeRB *)((char *)v8 + v9);
          v8 < i;
          v8 = (UFG::qBaseNodeRB *)((char *)v8 + ((HIDWORD(v8->mParent) + 3) & 0xFFFFFFFC) + 16) )
    {
      if ( LODWORD(v8->mParent) )
      {
        v11 = HIDWORD(v8->mChild[0]);
        if ( !(_S3_7 & 1) )
        {
          _S3_7 |= 1u;
          qword_1423A8CF0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
        }
        v12 = *(_DWORD *)((char *)&v8[2].mParent + v11);
        if ( v12 )
        {
          v13 = UFG::qBaseTreeRB::Get(qword_1423A8CF0, v12);
          if ( v13 )
          {
            if ( v13 != (UFG::qBaseTreeRB *)8 )
              (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)&v13[-1].mCount + 80i64))(
                &v13[-1].mCount,
                (signed __int64)&v8->mChild[1] + v11);
          }
        }
      }
    }
  }
  if ( *((_BYTE *)v1 + 81) & 1 )
  {
    v14 = v1->mhBufferPerm;
    if ( (_DWORD)v14 )
      v15 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v14);
    else
      v15 = 0i64;
    v16 = (char *)v15[1].mRoot.mParent;
    v17 = v1->mFileSizePerm.uncompressed_size;
    UFG::qString::qString(&v22, &v1->mFileName);
    v18 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v22.mData);
    UFG::qChunkFileSystem::RemoveExternalResourceFileReference(v18, v16, v17);
    if ( v1->mhBufferTemp.mData )
    {
      UFG::qString::ReplaceString(&v22, "perm.bin", "temp.bin", 1);
      v19 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v22.mData);
      UFG::qChunkFileSystem::RemoveExternalResourceFileReference(v19, &v1->mhBufferTemp);
      if ( v1->mhBufferTemp.mData )
        UFG::qVRAMemoryPools::Free(&v1->mhBufferTemp, 0);
    }
    UFG::qString::~qString(&v22);
  }
  v20 = v1->mhBufferPerm;
  if ( (_DWORD)v20 )
  {
    v21 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v1->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v20);
    if ( v21 )
      LOWORD(v21->mNULL.mChild[1]) &= 0xFEFFu;
  }
  result = 1;
  *((_WORD *)v1 + 40) &= 0xFFFDu;
  v1->mDataLoadedTo = 0;
  return result;
}

// File Line: 1537
// RVA: 0x22BAE0
void __fastcall UFG::DataStreamer::OnStreamLoadComplete(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::StreamInfo *v1; // rbx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v2; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v3; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v4; // r8

  v1 = streamInfo;
  UFG::DataStreamer::LoadStreamResources(streamInfo);
  if ( v1->mStateCurrent != 4 )
  {
    UFG::DataStreamer::FireStreamLoadCallback(v1);
    if ( v1->mStateCurrent == 2 )
    {
      v2 = v1->mPrev;
      v3 = v1->mNext;
      v4 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v1->mPrev;
      v2->mNext = v3;
      v3->mPrev = v2;
      v4->mPrev = v4;
      v4->mNext = v4;
    }
    v1->mStateCurrent = 6;
    v1->mTimeInState = 0.0;
  }
  --UFG::DataStreamer::mFileOperationCount;
  UFG::DataStreamer::mLoadedBytes += v1->mFileSizePerm.compressed_extra + v1->mFileSizePerm.uncompressed_size;
  UFG::DataStreamer::mLoadedBytes += v1->mFileSizeTemp.compressed_extra + v1->mFileSizeTemp.uncompressed_size;
}

// File Line: 1564
// RVA: 0x22B7A0
void __fastcall UFG::DataStreamer::OnFileCompletionCallback(UFG::qFileOp *file_op, void *callback_param)
{
  UFG::DataStreamer::StreamInfo *v2; // rbx
  UFG::qFileOp *v3; // rdi
  char *v4; // rsi
  char *v5; // rbp
  char *v6; // rax
  char *v7; // rax
  char *v8; // rax
  void *v9; // rcx
  unsigned __int64 v10; // rdx
  UFG::qBaseTreeRB *v11; // rax

  v2 = (UFG::DataStreamer::StreamInfo *)callback_param;
  v3 = file_op;
  if ( (unsigned int)Scaleform::Render::FileImageSource::GetUse(file_op) != 3
    && (unsigned int)Scaleform::Render::FileImageSource::GetUse(v3) != 4 )
  {
    return;
  }
  v4 = 0i64;
  v5 = 0i64;
  if ( v3 )
  {
    if ( (v6 = (char *)v2->mFileSizePerm.uncompressed_size, (_DWORD)v6) && v2->mhFilePerm
      || (v6 = (char *)v2->mFileSizeTemp.uncompressed_size, (_DWORD)v6) )
    {
      v4 = v6;
    }
  }
  if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v3) == 6
    || (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v3) == 2 )
  {
    v7 = (char *)UFG::qFileOp::GetReadEntireFileSize(v3);
  }
  else
  {
    if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v3) != 9 )
      goto LABEL_14;
    v7 = UFG::qFileOp::GetReadEntireFileBuffer(v3);
  }
  v5 = v7;
LABEL_14:
  if ( v5 == v4 )
  {
    v9 = v2->mhFilePerm;
    if ( v9 )
    {
      UFG::StreamFileWrapper::Close(v9);
      v2->mhFilePerm = 0i64;
    }
    if ( !(*((_BYTE *)v2 + 80) & 4) )
      UFG::StreamPool_Unlock(v2->mhBufferPerm);
    if ( !(v2->mFlagsOR & 2) )
    {
      v10 = v2->mhBufferPerm;
      if ( (_DWORD)v10 )
      {
        v11 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(v2->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v10);
        if ( v11 )
          LOWORD(v11->mNULL.mChild[1]) |= 0x20u;
      }
    }
    if ( v2->mFileSizeTemp.uncompressed_size )
    {
      UFG::StreamFileWrapper::Close(v2->mhFileTemp);
      v2->mhFileTemp = 0i64;
      UFG::qVRAMemoryHandle::Unlock(&v2->mhBufferTemp);
    }
    UFG::DataStreamer::OnStreamLoadComplete(v2);
  }
  else
  {
    v8 = UFG::qFileOp::GetFilename(v3);
    UFG::qPrintf("file_op 0x%08x Read %d64 of %d64 expected bytes for stream 0x%08x from '%s'\n", v3, v5, v4, v2, v8);
  }
}

// File Line: 1684
// RVA: 0x22BE00
signed __int64 __fastcall UFG::DataStreamer::OpenFiles(UFG::DataStreamer::StreamInfo *streamInfo, unsigned int *CPURAMRestoredSizeBytes, unsigned int *VRAMRestoredSizeBytes)
{
  unsigned int *v3; // r12
  unsigned int *v4; // r15
  UFG::DataStreamer::StreamInfo *v5; // rbx
  unsigned int v6; // er13
  char *v7; // rdi
  char v8; // r14
  unsigned int v9; // eax
  __int64 v10; // rsi
  unsigned int v11; // edi
  UFG::allocator::free_link *v12; // rsi
  UFG::allocator::free_link *v13; // rbp
  unsigned int v14; // er15
  unsigned int v15; // er12
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rcx
  unsigned int v18; // eax
  int v19; // ecx
  UFG::allocator::free_link *v20; // rax
  unsigned int *v21; // rcx
  unsigned int v22; // eax
  unsigned int v23; // er14
  unsigned int v25; // er14
  char v26; // cl
  unsigned int v27; // [rsp+70h] [rbp-198h]
  unsigned int v28; // [rsp+74h] [rbp-194h]
  unsigned int v29; // [rsp+78h] [rbp-190h]
  unsigned int v30; // [rsp+80h] [rbp-188h]
  UFG::qVRAMemoryHandle handle; // [rsp+90h] [rbp-178h]
  __int64 v32; // [rsp+B0h] [rbp-158h]
  char v33[8]; // [rsp+B8h] [rbp-150h]
  char dest; // [rsp+C0h] [rbp-148h]
  unsigned int error_flags; // [rsp+210h] [rbp+8h]
  unsigned int *v36; // [rsp+218h] [rbp+10h]
  unsigned int *v37; // [rsp+220h] [rbp+18h]
  unsigned __int64 phMainRAM; // [rsp+228h] [rbp+20h]

  v37 = VRAMRestoredSizeBytes;
  v36 = CPURAMRestoredSizeBytes;
  v32 = -2i64;
  v3 = VRAMRestoredSizeBytes;
  v4 = CPURAMRestoredSizeBytes;
  v5 = streamInfo;
  v6 = streamInfo->mFlagsOR;
  v7 = streamInfo->mFileName.mData;
  v8 = 0;
  v9 = UFG::qStringLength(streamInfo->mFileName.mData);
  v10 = v9;
  if ( v9 > 8 && !(unsigned int)UFG::qStringCompareInsensitive(&v7[v9 - 8], "perm.bin", -1) )
  {
    UFG::qStringCopy(&dest, 256, v7, v10 - 8);
    UFG::qStringCopy(&v33[v10], 0x7FFFFFFF, "temp.bin", -1);
    v8 = 1;
  }
  v11 = 0;
  v12 = 0i64;
  v13 = 0i64;
  if ( *((_BYTE *)v5 + 80) & 1 )
    goto LABEL_21;
  error_flags = 0;
  v29 = 0;
  v14 = 0;
  v15 = 0;
  v16 = UFG::StreamFileWrapper::Open(v5->mFileName.mData, QACCESS_READ, 1, 0i64, 0i64);
  v12 = v16;
  if ( !v16 )
    return 1i64;
  if ( v16[4].mNext )
  {
    v17 = v16[5].mNext;
    v28 = (unsigned int)v17[1].mNext;
    v30 = HIDWORD(v17[1].mNext);
    LODWORD(phMainRAM) = v17[2].mNext;
    v18 = HIDWORD(v17[2].mNext);
    v19 = phMainRAM;
  }
  else
  {
    v18 = UFG::qGetFileSize((UFG::qFile *)v16[7].mNext);
    v30 = v18;
    v28 = 0;
    v19 = 0;
    LODWORD(phMainRAM) = 0;
  }
  v27 = v18;
  if ( v18 + v19 )
  {
    if ( v8 )
    {
      v20 = UFG::StreamFileWrapper::Open(&dest, QACCESS_READ, 0, 0i64, 0i64);
      v13 = v20;
      if ( v20 )
      {
        if ( v20[4].mNext )
        {
          v21 = (unsigned int *)v20[5].mNext;
          error_flags = v21[2];
          v22 = v21[3];
          v14 = v21[4];
          v15 = v21[5];
          v23 = error_flags;
        }
        else
        {
          v22 = UFG::qGetFileSize((UFG::qFile *)v20[7].mNext);
          v23 = 0;
          v15 = v22;
        }
        v29 = v22;
        if ( !(v15 + v14) )
        {
          UFG::StreamFileWrapper::Close(v13);
          v13 = 0i64;
        }
        goto LABEL_19;
      }
    }
  }
  else
  {
    UFG::StreamFileWrapper::Close(v12);
    v12 = 0i64;
  }
  v23 = error_flags;
LABEL_19:
  v5->mFileSizePerm.load_offset = v28;
  v5->mFileSizePerm.compressed_size = v30;
  v5->mFileSizePerm.compressed_extra = phMainRAM;
  v5->mFileSizePerm.uncompressed_size = v27;
  v5->mFileSizeTemp.load_offset = v23;
  v5->mFileSizeTemp.compressed_size = v29;
  v5->mFileSizeTemp.compressed_extra = v14;
  v5->mFileSizeTemp.uncompressed_size = v15;
  *((_WORD *)v5 + 40) |= 1u;
  v4 = v36;
  v3 = v37;
LABEL_21:
  v25 = 0;
  if ( !(v6 & 1) )
    v25 = 64;
  if ( !(v6 & 2) )
    v25 |= 32u;
  if ( _bittest((const signed int *)&v6, 8u) )
    v25 |= 0x200u;
  *((_WORD *)v5 + 40) &= 0xFF9Bu;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&handle);
  phMainRAM = -1i64;
  error_flags = 0;
  if ( UFG::StreamingMemory::Allocate(
         v5->mDataType,
         v25,
         v5->mFileSizePerm.compressed_extra + v5->mFileSizePerm.uncompressed_size,
         v5->mFileSizePerm.uncompressed_size,
         v5->mFileSizeTemp.compressed_extra + v5->mFileSizeTemp.uncompressed_size,
         &phMainRAM,
         &handle,
         v5->mFileName.mData,
         0i64,
         v4,
         v3,
         0i64,
         0i64,
         &error_flags) )
  {
    *((_WORD *)v5 + 40) ^= (*((_WORD *)v5 + 40) ^ 4 * (*v4 > 0)) & 4;
    if ( *v4 )
    {
      if ( v12 )
        UFG::StreamFileWrapper::Close(v12);
      v5->mhBufferPerm = phMainRAM;
      *((_WORD *)v5 + 40) &= 0xFFFEu;
      *((_WORD *)v5 + 40) |= 8u;
    }
    else
    {
      if ( !v12 )
        v12 = UFG::StreamFileWrapper::Open(v5->mFileName.mData, QACCESS_READ, 1, 0i64, 0i64);
      v5->mhFilePerm = v12;
      v5->mhBufferPerm = phMainRAM;
    }
    if ( v5->mFileSizeTemp.uncompressed_size )
    {
      if ( !v13 )
        v13 = UFG::StreamFileWrapper::Open(&dest, QACCESS_READ, 1, 0i64, 0i64);
      v5->mhFileTemp = v13;
      UFG::qVRAMemoryHandle::operator=(&v5->mhBufferTemp, &handle);
    }
  }
  else
  {
    v26 = error_flags;
    if ( error_flags & 1 )
      *((_WORD *)v5 + 40) |= 0x20u;
    if ( v26 & 2 )
      *((_WORD *)v5 + 40) |= 0x40u;
    if ( v12 )
      UFG::StreamFileWrapper::Close(v12);
    if ( v13 )
      UFG::StreamFileWrapper::Close(v13);
    v11 = 2;
  }
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&handle);
  return v11;
}

// File Line: 1937
// RVA: 0x227F70
char __fastcall UFG::DataStreamer::BeginLoading(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::StreamInfo *callbackParam; // rbx
  unsigned int v2; // edi
  char v3; // di
  void (__fastcall *callback)(UFG::qFileOp *, void *); // rcx
  unsigned __int64 v5; // rdx
  UFG::qBaseTreeRB *v6; // rax
  unsigned __int64 v7; // rdx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v9; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v10; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v11; // rdx
  bool v12; // zf

  callbackParam = streamInfo;
  v2 = streamInfo->mFlagsOR >> 6;
  streamInfo->mDataLoadedTo = 0;
  v3 = v2 & 1;
  if ( streamInfo->mFileSizeTemp.uncompressed_size )
  {
    UFG::qVRAMemoryHandle::Lock(&streamInfo->mhBufferTemp);
    callback = (void (__fastcall *)(UFG::qFileOp *, void *))_;
    if ( *((_BYTE *)callbackParam + 80) & 4 )
      callback = UFG::DataStreamer::fnDataStreamCallback;
    UFG::StreamFileWrapper::Read(
      callbackParam->mhFileTemp,
      (UFG::StreamFileWrapper::QUEUE_CLASS)(3 - (v3 != 0)),
      callbackParam->mhBufferTemp.mData,
      &callbackParam->mFileSizeTemp,
      0i64,
      0,
      callback,
      callbackParam,
      0);
  }
  if ( !(*((_BYTE *)callbackParam + 80) & 4) )
  {
    v5 = callbackParam->mhBufferPerm;
    if ( (_DWORD)v5 )
    {
      v6 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[BYTE4(v5) & 0x1F]->mBlockLookup.mTree, v5);
      if ( v6 )
        LOWORD(v6->mNULL.mChild[1]) |= 0x80u;
    }
    v7 = callbackParam->mhBufferPerm;
    if ( (_DWORD)v7 )
      v8 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[(callbackParam->mhBufferPerm >> 32) & 0x1F]->mBlockLookup.mTree, v7);
    else
      v8 = 0i64;
    UFG::StreamFileWrapper::Read(
      callbackParam->mhFilePerm,
      (UFG::StreamFileWrapper::QUEUE_CLASS)(3 - (v3 != 0)),
      v8[1].mRoot.mParent,
      &callbackParam->mFileSizePerm,
      0i64,
      0,
      UFG::DataStreamer::fnDataStreamCallback,
      callbackParam,
      0);
  }
  if ( callbackParam->mStateCurrent == 2 )
  {
    v9 = callbackParam->mPrev;
    v10 = callbackParam->mNext;
    v11 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&callbackParam->mPrev;
    v9->mNext = v10;
    v10->mPrev = v9;
    v11->mPrev = v11;
    v11->mNext = v11;
  }
  v12 = (*((_BYTE *)callbackParam + 80) & 4) == 0;
  callbackParam->mTimeInState = 0.0;
  callbackParam->mStateCurrent = 3;
  if ( !v12 && !callbackParam->mFileSizeTemp.uncompressed_size )
    UFG::DataStreamer::fnDataStreamCallback(0i64, callbackParam);
  return 1;
}

// File Line: 2001
// RVA: 0x22EFC0
bool __fastcall UFG::DataStreamer::fnPrioritySort(UFG::DataStreamer::StreamInfo *a, UFG::DataStreamer::StreamInfo *b)
{
  signed int v2; // er8
  signed int v3; // ecx

  v2 = 0x2000;
  if ( (UFG::qList<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle,1,0> *)a->mHandles.mNode.mNext == &a->mHandles )
    v3 = 0x2000;
  else
    v3 = WORD1(a->mHandles.mNode.mNext[2].mNext);
  if ( (UFG::qList<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle,1,0> *)b->mHandles.mNode.mNext != &b->mHandles )
    v2 = WORD1(b->mHandles.mNode.mNext[2].mNext);
  return v3 >= v2;
}

// File Line: 2035
// RVA: 0x22D270
void __fastcall UFG::DataStreamer::Service(float dT)
{
  unsigned int v1; // eax
  UFG::qResourceFileInventory *v2; // rdi
  __int64 v3; // rsi
  UFG::qResourceInventoryVtbl *v4; // rbx
  unsigned int v5; // eax
  UFG::StreamPool **v6; // rbx
  signed __int64 v7; // rdi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v8; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *v9; // r14
  signed __int64 v10; // rdi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v11; // rdx
  UFG::qBaseTreeRB *v12; // rax
  unsigned __int64 v13; // rdx
  UFG::StreamPool *v14; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v15; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v16; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v17; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v18; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v19; // rsi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v20; // rdi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v21; // r11
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v22; // r10
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v23; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v24; // r9
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v25; // rax
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v26; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v27; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v28; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v29; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v30; // rax
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v31; // r11
  signed __int64 v32; // r10
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v33; // r9
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v34; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v35; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v36; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v37; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v38; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v39; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v40; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v41; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v42; // rsi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v43; // rdi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v44; // r11
  signed int v45; // edx
  signed int v46; // ecx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v47; // r10
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v48; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v49; // r9
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v50; // rax
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v51; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v52; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v53; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v54; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v55; // rax
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v56; // r11
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v57; // r10
  signed int v58; // edx
  signed int v59; // ecx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v60; // r9
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v61; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v62; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v63; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v64; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v65; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v66; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v67; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v68; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v69; // rdi
  int v70; // eax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v71; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v72; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v73; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v74; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v75; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v76; // rax
  char v77; // bp
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v78; // rbx
  signed __int64 v79; // rsi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v80; // rdx
  UFG::qBaseTreeRB *v81; // rax
  unsigned __int64 v82; // rdx
  UFG::StreamPool *v83; // rcx
  UFG::DataStreamer::Handle *v84; // rax
  void (__fastcall *v85)(UFG::DataStreamer::Handle *, void *); // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v86; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v87; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v88; // rax
  _QWORD *v89; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v90; // rax
  int v91; // ecx
  int v92; // ecx
  int v93; // ecx
  int v94; // ecx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v95; // rdx
  UFG::qBaseTreeRB *v96; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v97; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v98; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v99; // rax
  UFG::DataStreamer::Handle *v100; // rax
  void (__fastcall *v101)(UFG::DataStreamer::Handle *, void *); // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v102; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v103; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v104; // rax
  unsigned __int64 v105; // rdx
  UFG::StreamPool *v106; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v107; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v108; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v109; // rax
  UFG::qString v110; // [rsp+28h] [rbp-390h]
  void *user_datas; // [rsp+50h] [rbp-368h]
  unsigned int CPURAMRestoredSizeBytes; // [rsp+3C8h] [rbp+10h]
  unsigned int VRAMRestoredSizeBytes; // [rsp+3D0h] [rbp+18h]

  if ( UFG::DataStreamer::gAllowStreaming )
  {
    v1 = UFG::qChunkFileSystem::GetZeroRefResourceFileUserData(&user_datas, 0x64u);
    if ( v1 )
    {
      v2 = (UFG::qResourceFileInventory *)&user_datas;
      v3 = v1;
      do
      {
        v4 = v2->vfptr;
        if ( BYTE1(v2->vfptr->Remove) & 1 && LODWORD(v4->IsEmpty) == 6 && v4[1].InitHandle )
        {
          UFG::qString::qString(&v110, (UFG::qString *)&v4[1].OnDetachHandle);
          UFG::qString::ReplaceString(&v110, "perm.bin", "temp.bin", 1);
          v5 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v110.mData);
          UFG::qChunkFileSystem::RemoveExternalResourceFileReference(v5, (UFG::qVRAMemoryHandle *)&v4->Validate);
          if ( v4[1].InitHandle )
            UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&v4->Validate, 0);
          UFG::qString::~qString(&v110);
        }
        v2 = (UFG::qResourceFileInventory *)((char *)v2 + 8);
        --v3;
      }
      while ( v3 );
    }
    v6 = UFG::gStreamPools;
    v7 = 32i64;
    do
    {
      if ( *v6 )
        UFG::DefragState::Service(&(*v6)->mDefragState);
      ++v6;
      --v7;
    }
    while ( v7 );
    UFG::qMemCopy(UFG::DataStreamer::mStateCountPrev, UFG::DataStreamer::mStateCountThis, 0x20u);
    UFG::qMemSet(UFG::DataStreamer::mStateCountThis, 0, 0x20u);
    v8 = UFG::DataStreamer::mOrderList.mNode.mNext - 2;
    v9 = &UFG::DataStreamer::mOrderList - 2;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)&UFG::DataStreamer::mOrderList.mNode.mNext[-2] != &UFG::DataStreamer::mOrderList - 2 )
    {
      do
      {
        v10 = (signed __int64)&v8[2].mNext[-2];
        if ( HIDWORD(v8[4].mPrev) == 1 && LODWORD(v8[4].mPrev) == 7 && ++WORD1(v8[5].mPrev) >= 2u )
        {
          v11 = v8[6].mNext;
          if ( (_DWORD)v11 )
          {
            v12 = UFG::qBaseTreeRB::Get(
                    &UFG::gStreamPools[((_QWORD)v8[6].mNext >> 32) & 0x1F]->mBlockLookup.mTree,
                    (unsigned int)v11);
            if ( v12 )
              LOWORD(v12->mNULL.mChild[1]) &= 0xFF7Fu;
          }
          v13 = (unsigned __int64)v8[6].mNext;
          if ( v13 != -1i64 )
          {
            v14 = UFG::gStreamPools[BYTE4(v13) & 0x1F];
            if ( v14 )
              UFG::StreamPool::Free(v14, v13);
            v8[6].mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)-1i64;
          }
          if ( v8[9].mNext )
          {
            UFG::qVRAMemoryHandle::Unlock((UFG::qVRAMemoryHandle *)&v8[8].mNext);
            if ( v8[9].mNext )
              UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&v8[8].mNext, 0);
          }
          if ( LODWORD(v8[4].mPrev) == 2 )
          {
            v15 = v8 + 3;
            v16 = v8[3].mPrev;
            v17 = v8[3].mNext;
            v16->mNext = v17;
            v17->mPrev = v16;
            v15->mPrev = v15;
            v15->mNext = v15;
          }
          LODWORD(v8[4].mPrev) = 1;
          HIDWORD(v8[4].mNext) = 0;
        }
        v8 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)v10;
      }
      while ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)v10 != v9 );
    }
    if ( UFG::DataStreamer::mDiskPosSortMode )
    {
      if ( UFG::DataStreamer::mDiskPosSortMode == 1 )
      {
        v41 = UFG::DataStreamer::mPriorityList.mNode.mNext - 3;
        v42 = &UFG::DataStreamer::mPriorityList - 3;
        do
        {
          v43 = 0i64;
          while ( v41 != (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)v42 )
          {
            v44 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v41[3].mNext[-3];
            if ( v44 == v42 )
              break;
            v45 = v41[14].mNext == &v41[14] ? 0x2000 : WORD1(v41[14].mNext[2].mNext);
            v46 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v44[14].mNode.mNext == &v44[14] ? 0x2000 : WORD1(v44[14].mNode.mNext[2].mNext);
            if ( v45 > v46 || v45 >= v46 && v41[16].mPrev <= v44[16].mNode.mPrev )
            {
              v41 = v41[3].mNext - 3;
            }
            else
            {
              v47 = v41 + 3;
              v48 = v41[3].mPrev;
              v49 = v44[3].mNode.mNext;
              v50 = v41[3].mNext;
              v48->mNext = v50;
              v50->mPrev = v48;
              v47->mPrev = v47;
              v47->mNext = v47;
              v51 = v44 + 3;
              v52 = v44[3].mNode.mPrev;
              v53 = v44[3].mNode.mNext;
              v52->mNext = v53;
              v53->mPrev = v52;
              v51->mNode.mPrev = &v51->mNode;
              v51->mNode.mNext = &v51->mNode;
              v54 = v48->mNext;
              v48->mNext = &v44[3].mNode;
              v51->mNode.mPrev = v48;
              v51->mNode.mNext = v54;
              v54->mPrev = &v44[3].mNode;
              v55 = v49->mPrev;
              v55->mNext = v41 + 3;
              v47->mPrev = v55;
              v47->mNext = v49;
              v49->mPrev = v41 + 3;
              v43 = v44;
            }
          }
          v41 = 0i64;
          if ( !v43 || v43 == v42 )
            break;
          do
          {
            v56 = v43 + 3;
            v57 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v43[3].mNode.mPrev[-3];
            if ( v57 == v42 )
              break;
            v58 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v57[14].mNode.mNext == &v57[14] ? 0x2000 : WORD1(v57[14].mNode.mNext[2].mNext);
            v59 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v43[14].mNode.mNext == &v43[14] ? 0x2000 : WORD1(v43[14].mNode.mNext[2].mNext);
            if ( v58 > v59 || v58 >= v59 && v57[16].mNode.mPrev <= v43[16].mNode.mPrev )
            {
              v43 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v43[3].mNode.mPrev[-3];
            }
            else
            {
              v60 = v43[3].mNode.mPrev;
              v61 = v43[3].mNode.mPrev->mPrev;
              v62 = v43[3].mNode.mNext;
              v63 = v57[3].mNode.mNext;
              v61->mNext = v63;
              v63->mPrev = v61;
              v60->mPrev = v60;
              v60->mNext = v60;
              v64 = v56->mNode.mPrev;
              v65 = v43[3].mNode.mNext;
              v64->mNext = v65;
              v65->mPrev = v64;
              v56->mNode.mPrev = &v56->mNode;
              v43[3].mNode.mNext = &v43[3].mNode;
              v66 = v61->mNext;
              v61->mNext = &v56->mNode;
              v56->mNode.mPrev = v61;
              v43[3].mNode.mNext = v66;
              v66->mPrev = &v56->mNode;
              v67 = v62->mPrev;
              v67->mNext = &v57[3].mNode;
              v60->mPrev = v67;
              v60->mNext = v62;
              v62->mPrev = &v57[3].mNode;
              v41 = &v57->mNode;
            }
          }
          while ( v43 != v42 );
        }
        while ( v41 );
      }
      else if ( UFG::DataStreamer::mDiskPosSortMode == 2 )
      {
        v18 = UFG::DataStreamer::mPriorityList.mNode.mNext - 3;
        v19 = &UFG::DataStreamer::mPriorityList - 3;
        do
        {
          v20 = 0i64;
          while ( v18 != (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)v19 )
          {
            v21 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v18[3].mNext[-3];
            if ( v21 == v19 )
              break;
            if ( v18[16].mPrev <= v21[16].mNode.mPrev )
            {
              v18 = v18[3].mNext - 3;
            }
            else
            {
              v22 = v18 + 3;
              v23 = v18[3].mPrev;
              v24 = v21[3].mNode.mNext;
              v25 = v18[3].mNext;
              v23->mNext = v25;
              v25->mPrev = v23;
              v22->mPrev = v22;
              v22->mNext = v22;
              v26 = v21 + 3;
              v27 = v21[3].mNode.mPrev;
              v28 = v21[3].mNode.mNext;
              v27->mNext = v28;
              v28->mPrev = v27;
              v26->mNode.mPrev = &v26->mNode;
              v26->mNode.mNext = &v26->mNode;
              v29 = v23->mNext;
              v23->mNext = &v21[3].mNode;
              v26->mNode.mPrev = v23;
              v26->mNode.mNext = v29;
              v29->mPrev = &v21[3].mNode;
              v30 = v24->mPrev;
              v30->mNext = v18 + 3;
              v22->mPrev = v30;
              v22->mNext = v24;
              v24->mPrev = v18 + 3;
              v20 = v21;
            }
          }
          v18 = 0i64;
          if ( !v20 || v20 == v19 )
            break;
          do
          {
            v31 = v20 + 3;
            v32 = (signed __int64)&v20[3].mNode.mPrev[-3];
            if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v32 == v19 )
              break;
            if ( (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)*(_QWORD *)(v32 + 256) <= v20[16].mNode.mPrev )
            {
              v20 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v20[3].mNode.mPrev[-3];
            }
            else
            {
              v33 = v20[3].mNode.mPrev;
              v34 = v20[3].mNode.mPrev->mPrev;
              v35 = v20[3].mNode.mNext;
              v36 = *(UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> **)(v32 + 56);
              v34->mNext = v36;
              v36->mPrev = v34;
              v33->mPrev = v33;
              v33->mNext = v33;
              v37 = v31->mNode.mPrev;
              v38 = v20[3].mNode.mNext;
              v37->mNext = v38;
              v38->mPrev = v37;
              v31->mNode.mPrev = &v31->mNode;
              v20[3].mNode.mNext = &v20[3].mNode;
              v39 = v34->mNext;
              v34->mNext = &v31->mNode;
              v31->mNode.mPrev = v34;
              v20[3].mNode.mNext = v39;
              v39->mPrev = &v31->mNode;
              v40 = v35->mPrev;
              v40->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)(v32 + 48);
              v33->mPrev = v40;
              v33->mNext = v35;
              v35->mPrev = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)(v32 + 48);
              v18 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)v32;
            }
          }
          while ( v20 != v19 );
        }
        while ( v18 );
      }
    }
    else
    {
      UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0>::MergeSort(
        &UFG::DataStreamer::mPriorityList,
        UFG::DataStreamer::fnPrioritySort);
    }
    v68 = UFG::DataStreamer::mPriorityList.mNode.mNext - 3;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&UFG::DataStreamer::mPriorityList.mNode.mNext[-3] != &UFG::DataStreamer::mPriorityList - 3 )
    {
      while ( 1 )
      {
        v69 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v68[3].mNext[-3];
        if ( HIDWORD(v68[4].mPrev) == 1 )
          break;
        if ( HIDWORD(v68[4].mPrev) == 6 && UFG::DataStreamer::mFileOperationCount < 4 )
        {
          CPURAMRestoredSizeBytes = 0;
          v70 = UFG::DataStreamer::OpenFiles(
                  (UFG::DataStreamer::StreamInfo *)v68,
                  &CPURAMRestoredSizeBytes,
                  &VRAMRestoredSizeBytes);
          if ( !v70 )
          {
            if ( CPURAMRestoredSizeBytes <= 0 || HIDWORD(v68[8].mPrev) )
            {
              ++UFG::DataStreamer::mFileOperationCount;
              UFG::DataStreamer::BeginLoading((UFG::DataStreamer::StreamInfo *)v68);
            }
            else
            {
              ++UFG::DataStreamer::mFileOperationCount;
              UFG::DataStreamer::OnStreamLoadComplete((UFG::DataStreamer::StreamInfo *)v68);
            }
            goto LABEL_102;
          }
          if ( v70 == 1 )
          {
            if ( LODWORD(v68[4].mPrev) == 2 )
            {
              v71 = v68 + 3;
              v72 = v68[3].mPrev;
              v73 = v68[3].mNext;
              v72->mNext = v73;
              v73->mPrev = v72;
              v71->mPrev = v71;
              v71->mNext = v71;
            }
            LODWORD(v68[4].mPrev) = 0;
LABEL_101:
            HIDWORD(v68[4].mNext) = 0;
            goto LABEL_102;
          }
        }
LABEL_102:
        v68 = &v69->mNode;
        if ( v69 == &UFG::DataStreamer::mPriorityList - 3 )
          goto LABEL_103;
      }
      if ( LODWORD(v68[4].mPrev) == 2 )
      {
        v74 = v68 + 3;
        v75 = v68[3].mPrev;
        v76 = v68[3].mNext;
        v75->mNext = v76;
        v76->mPrev = v75;
        v74->mPrev = v74;
        v74->mNext = v74;
      }
      LODWORD(v68[4].mPrev) = 1;
      goto LABEL_101;
    }
LABEL_103:
    v77 = 0;
    v78 = UFG::DataStreamer::mOrderList.mNode.mNext - 2;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)&UFG::DataStreamer::mOrderList.mNode.mNext[-2] != v9 )
    {
      while ( 1 )
      {
        v79 = (signed __int64)&v78[2].mNext[-2];
        if ( HIDWORD(v78[4].mPrev) != 1 )
          break;
        v91 = (int)v78[4].mPrev;
        if ( !v91 )
        {
          if ( v78[9].mNext )
            UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&v78[8].mNext, 0);
          v105 = (unsigned __int64)v78[6].mNext;
          if ( v105 != -1i64 )
          {
            v106 = UFG::gStreamPools[BYTE4(v105) & 0x1F];
            if ( v106 )
              UFG::StreamPool::Free(v106, v105);
            v78[6].mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)-1i64;
          }
          goto LABEL_161;
        }
        v92 = v91 - 1;
        if ( v92 )
        {
          v93 = v92 - 3;
          if ( v93 )
          {
            v94 = v93 - 1;
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                if ( !((HIDWORD(v78[15].mPrev) >> 7) & 1) )
                  goto LABEL_139;
                if ( !v77 || UFG::DataStreamer::gDisableSpreadedUnloadTick )
                {
                  v77 = 1;
LABEL_139:
                  if ( UFG::DataStreamer::UnloadStreamResources((UFG::DataStreamer::StreamInfo *)v78) )
                  {
                    WORD1(v78[5].mPrev) = 0;
                    v95 = v78[6].mNext;
                    if ( (_DWORD)v95 )
                    {
                      v96 = UFG::qBaseTreeRB::Get(
                              &UFG::gStreamPools[((_QWORD)v78[6].mNext >> 32) & 0x1F]->mBlockLookup.mTree,
                              (unsigned int)v95);
                      if ( v96 )
                        LOWORD(v96->mNULL.mChild[1]) |= 0x80u;
                    }
                    if ( v78[9].mNext )
                      UFG::qVRAMemoryHandle::Lock((UFG::qVRAMemoryHandle *)&v78[8].mNext);
                    if ( LODWORD(v78[4].mPrev) == 2 )
                    {
                      v97 = v78 + 3;
                      v98 = v78[3].mPrev;
                      v99 = v78[3].mNext;
                      v98->mNext = v99;
                      v99->mPrev = v98;
                      v97->mPrev = v97;
                      v97->mNext = v97;
                    }
                    LODWORD(v78[4].mPrev) = 7;
LABEL_164:
                    HIDWORD(v78[4].mNext) = 0;
                  }
                }
              }
LABEL_165:
              ++UFG::DataStreamer::mStateCountThis[SLODWORD(v78[4].mPrev)];
              *((float *)&v78[4].mNext + 1) = dT + *((float *)&v78[4].mNext + 1);
              goto LABEL_166;
            }
            UFG::DataStreamer::FinishLoadingResources((UFG::DataStreamer::StreamInfo *)v78);
            v100 = (UFG::DataStreamer::Handle *)v78[14].mNext;
            for ( UFG::DataStreamer::gCurrentStreamHandle = v100;
                  v100 != (UFG::DataStreamer::Handle *)&v78[14];
                  UFG::DataStreamer::gCurrentStreamHandle = v100 )
            {
              v101 = v100->mCallback;
              if ( v101 )
              {
                v101(v100, v100->mCallbackParam);
                v100 = UFG::DataStreamer::gCurrentStreamHandle;
              }
              v100 = (UFG::DataStreamer::Handle *)v100->mNext;
            }
LABEL_125:
            UFG::DataStreamer::gCurrentStreamHandle = 0i64;
            if ( LODWORD(v78[4].mPrev) == 2 )
            {
              v86 = v78 + 3;
              v87 = v78[3].mPrev;
              v88 = v78[3].mNext;
              v87->mNext = v88;
              v88->mPrev = v87;
              v86->mPrev = v86;
              v86->mNext = v86;
            }
            LODWORD(v78[4].mPrev) = 6;
            goto LABEL_164;
          }
LABEL_128:
          LODWORD(v78[4].mPrev) = 5;
          goto LABEL_164;
        }
        if ( v78[14].mNext != &v78[14] )
          goto LABEL_165;
        v102 = v78 + 2;
        v103 = v78[2].mPrev;
        v104 = v78[2].mNext;
        v103->mNext = v104;
        v104->mPrev = v103;
        v102->mPrev = v102;
        v102->mNext = v102;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::DataStreamer::mStreamInfo,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v78);
        UFG::DataStreamer::StreamInfo::~StreamInfo((UFG::DataStreamer::StreamInfo *)v78);
        operator delete[](v78);
LABEL_166:
        v78 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)v79;
        if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)v79 == v9 )
          goto LABEL_167;
      }
      if ( HIDWORD(v78[4].mPrev) != 6 )
        goto LABEL_165;
      switch ( LODWORD(v78[4].mPrev) )
      {
        case 1:
          LODWORD(v78[4].mPrev) = 2;
          HIDWORD(v78[4].mNext) = 0;
          v89 = &v78[3].mPrev;
          v90 = UFG::DataStreamer::mPriorityList.mNode.mPrev;
          UFG::DataStreamer::mPriorityList.mNode.mPrev->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v78[3];
          *v89 = v90;
          v89[1] = &UFG::DataStreamer::mPriorityList;
          UFG::DataStreamer::mPriorityList.mNode.mPrev = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v78[3];
          goto LABEL_165;
        case 4:
          goto LABEL_128;
        case 5:
          UFG::DataStreamer::FinishLoadingResources((UFG::DataStreamer::StreamInfo *)v78);
          v84 = (UFG::DataStreamer::Handle *)v78[14].mNext;
          for ( UFG::DataStreamer::gCurrentStreamHandle = v84;
                v84 != (UFG::DataStreamer::Handle *)&v78[14];
                UFG::DataStreamer::gCurrentStreamHandle = v84 )
          {
            v85 = v84->mCallback;
            if ( v85 )
            {
              v85(v84, v84->mCallbackParam);
              v84 = UFG::DataStreamer::gCurrentStreamHandle;
            }
            v84 = (UFG::DataStreamer::Handle *)v84->mNext;
          }
          goto LABEL_125;
      }
      if ( LODWORD(v78[4].mPrev) != 7 )
        goto LABEL_165;
      if ( ++WORD1(v78[5].mPrev) < 2u )
        goto LABEL_165;
      v80 = v78[6].mNext;
      if ( (_DWORD)v80 )
      {
        v81 = UFG::qBaseTreeRB::Get(
                &UFG::gStreamPools[((_QWORD)v78[6].mNext >> 32) & 0x1F]->mBlockLookup.mTree,
                (unsigned int)v80);
        if ( v81 )
          LOWORD(v81->mNULL.mChild[1]) &= 0xFF7Fu;
      }
      v82 = (unsigned __int64)v78[6].mNext;
      if ( v82 != -1i64 )
      {
        v83 = UFG::gStreamPools[BYTE4(v82) & 0x1F];
        if ( v83 )
          UFG::StreamPool::Free(v83, v82);
        v78[6].mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)-1i64;
      }
      if ( v78[9].mNext )
      {
        UFG::qVRAMemoryHandle::Unlock((UFG::qVRAMemoryHandle *)&v78[8].mNext);
        if ( v78[9].mNext )
          UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&v78[8].mNext, 0);
      }
LABEL_161:
      if ( LODWORD(v78[4].mPrev) == 2 )
      {
        v107 = v78 + 3;
        v108 = v78[3].mPrev;
        v109 = v78[3].mNext;
        v108->mNext = v109;
        v109->mPrev = v108;
        v107->mPrev = v107;
        v107->mNext = v107;
      }
      LODWORD(v78[4].mPrev) = 1;
      goto LABEL_164;
    }
LABEL_167:
    UFG::StreamFileWrapper::Service(dT);
    if ( UFG::DataStreamer::gDisableSpreadedUnloadTick > 0 )
      --UFG::DataStreamer::gDisableSpreadedUnloadTick;
  }
}::qVRAMemoryHandle *)&v78[8].mNex

// File Line: 2410
// RVA: 0x229CD0
signed __int64 __fastcall UFG::DataStreamer::GetStreamState(UFG::DataStreamer::Handle *handle)
{
  unsigned int *v1; // rax
  signed __int64 result; // rax

  v1 = (unsigned int *)handle->mImpl;
  if ( v1 )
    result = v1[16];
  else
    result = 1i64;
  return result;
}

// File Line: 2436
// RVA: 0x229660
char __fastcall UFG::DataStreamer::GetBufferFromUID(unsigned int uid, void **buffer_ptr, unsigned int *buffer_size)
{
  unsigned int *v3; // rdi
  void **v4; // rsi
  UFG::DataStreamer::StreamInfo *v5; // rax
  UFG::DataStreamer::StreamInfo *v6; // rbx
  unsigned __int64 v7; // rax

  v3 = buffer_size;
  v4 = buffer_ptr;
  if ( !uid )
    return 0;
  v5 = (UFG::DataStreamer::StreamInfo *)UFG::qBaseTreeRB::Get(&UFG::DataStreamer::mStreamInfo.mTree, uid);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = v5->mhBufferPerm;
  if ( (_DWORD)v7 )
    *v4 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[BYTE4(v7) & 31]->mBlockLookup.mTree, v7)[1].mRoot.mParent;
  else
    *v4 = (void *)MEMORY[0x48];
  *v3 = v6->mFileSizePerm.uncompressed_size;
  return 1;
}

// File Line: 2696
// RVA: 0x229CB0
__int64 __fastcall UFG::DataStreamer::GetReadBytes(UFG::DataStreamer::Handle *handle)
{
  _DWORD *v1; // rdx
  __int64 result; // rax

  v1 = handle->mImpl;
  if ( v1 )
    result = (unsigned int)(v1[23] + v1[24] + v1[32] + v1[33]);
  else
    result = 0i64;
  return result;
}

// File Line: 2706
// RVA: 0x229C50
__int64 __fastcall UFG::DataStreamer::GetQueuedBytes()
{
  unsigned int v0; // ebx
  UFG::qBaseTreeRB *i; // rax

  v0 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &i->mRoot) )
  {
    if ( (unsigned int)(i->mCount - 2) <= 1 )
      v0 += HIDWORD(i[1].mRoot.mChild[1]) + i[1].mRoot.mUID + i[1].mNULL.mUID + *(&i[1].mNULL.mUID + 1);
  }
  return v0;
}

// File Line: 2720
// RVA: 0x229C40
__int64 __fastcall UFG::DataStreamer::GetLoadedBytes()
{
  return UFG::DataStreamer::mLoadedBytes;
}

// File Line: 2725
// RVA: 0x22CE60
void __fastcall UFG::DataStreamer::ResetLoadedBytes(UFG::DataStreamer *this)
{
  UFG::DataStreamer::mLoadedBytes = 0;
}

// File Line: 2730
// RVA: 0x228B60
void __fastcall UFG::DataStreamer::DisableSpreadedUnload(UFG::DataStreamer *this)
{
  UFG::DataStreamer::gDisableSpreadedUnloadTick = 15;
}

