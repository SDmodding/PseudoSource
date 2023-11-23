// File Line: 114
// RVA: 0x146F980
__int64 UFG::DataStreamer::_dynamic_initializer_for__gStallRecordNames__()
{
  `eh vector constructor iterator(
    (char *)UFG::DataStreamer::gStallRecordNames,
    0x28ui64,
    5,
    (void (__fastcall *)(void *))UFG::qString::qString);
  return atexit((int (__fastcall *)())UFG::DataStreamer::_dynamic_atexit_destructor_for__gStallRecordNames__);
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
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mPrev; // rdx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mNext; // rax

  UFG::DataStreamer::ReleaseStream(this);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 195
// RVA: 0x226E70
void __fastcall UFG::DataStreamer::StreamInfo::StreamInfo(UFG::DataStreamer::StreamInfo *this, unsigned int uid)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mPrev = &this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>;
  this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mNext = &this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>;
  this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev = &this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
  this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext = &this->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
  this->mStateCurrent = STATE_EMPTY;
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
  this->mhFileTemp = 0i64;
  UFG::qString::qString(&this->mFileName);
  this->mTagSymbolUID = -1;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  *(_QWORD *)&this->mFlagsAND = 0i64;
  this->mDataLoadedTo = 0;
}

// File Line: 244
// RVA: 0x229820
unsigned __int64 __fastcall UFG::DataStreamer::GetDiskPosSortKey(const char *filename)
{
  UFG::BIGFileIndex::Entry *_entry; // [rsp+38h] [rbp+10h] BYREF
  UFG::BIGFileIndex *_bigFile; // [rsp+40h] [rbp+18h] BYREF

  _bigFile = 0i64;
  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) )
    return _bigFile->mSortKey + ((4 * (unsigned __int64)_entry->offset_div_4) >> 11);
  else
    return UFG::qStringHash64(filename, 0xFFFFFFFFFFFFFFFFui64) & 0x8000000000000000ui64;
}

// File Line: 284
// RVA: 0x22CB70
void __fastcall UFG::DataStreamer::StreamInfo::RecacheHandleInfo(UFG::DataStreamer::StreamInfo *this)
{
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mNext; // r9
  UFG::qList<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle,1,0> *p_mHandles; // r10
  int v3; // r8d
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *i; // rax
  unsigned int mNext_low; // ecx
  UFG::DataStreamer::STREAM_STATE v7; // ecx

  mNext = this->mHandles.mNode.mNext;
  p_mHandles = &this->mHandles;
  v3 = 1;
  this->mStateTarget = STATE_EMPTY;
  for ( i = mNext; i != (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)p_mHandles; i = i->mNext )
  {
    mNext_low = LOWORD(i[2].mNext);
    if ( i == mNext )
    {
      this->mFlagsAND = mNext_low;
      this->mFlagsOR = LOWORD(i[2].mNext);
    }
    else
    {
      this->mFlagsAND &= mNext_low;
      this->mFlagsAND |= LOWORD(i[2].mNext);
    }
    v7 = WORD2(i[2].mNext);
    if ( v7 > v3 )
    {
      v3 = WORD2(i[2].mNext);
      this->mStateTarget = v7;
    }
  }
}

// File Line: 312
// RVA: 0x146FB90
__int64 UFG::DataStreamer::_dynamic_initializer_for__mStreamInfo__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::DataStreamer::mStreamInfo.mTree);
  return atexit((int (__fastcall *)())UFG::DataStreamer::_dynamic_atexit_destructor_for__mStreamInfo__);
}

// File Line: 347
// RVA: 0x146FB70
__int64 UFG::DataStreamer::_dynamic_initializer_for__mPriorityList__()
{
  return atexit((int (__fastcall *)())UFG::DataStreamer::_dynamic_atexit_destructor_for__mPriorityList__);
}

// File Line: 348
// RVA: 0x146FB50
__int64 UFG::DataStreamer::_dynamic_initializer_for__mOrderList__()
{
  return atexit((int (__fastcall *)())UFG::DataStreamer::_dynamic_atexit_destructor_for__mOrderList__);
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
  UFG::qBaseTreeRB *Head; // r9
  unsigned int v6; // edx
  UFG::StreamingMemory::DATA_TYPE *v7; // rcx

  if ( dataTypes )
  {
    Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
    if ( Head )
    {
      while ( 1 )
      {
        v6 = 0;
        if ( numDataTypes )
        {
          v7 = dataTypes;
          while ( LODWORD(Head[1].mRoot.mParent) != *v7 )
          {
            ++v6;
            ++v7;
            if ( v6 >= numDataTypes )
              goto LABEL_12;
          }
          if ( (unsigned int)(Head->mCount - 2) <= 1 )
            return 1;
        }
LABEL_12:
        Head = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &Head->mRoot);
        if ( !Head )
          return 0;
      }
    }
  }
  else if ( UFG::DataStreamer::mStateCountThis[2] || UFG::DataStreamer::mStateCountThis[3] )
  {
    return 1;
  }
  return 0;
}

// File Line: 613
// RVA: 0x22A5F0
char __fastcall UFG::DataStreamer::IsInLoopCondition(
        UFG::StreamingMemory::DATA_TYPE *dataTypes,
        unsigned int numDataTypes)
{
  int v2; // r10d
  _DWORD *i; // r9
  unsigned int v4; // r8d
  UFG::StreamingMemory::DATA_TYPE *v5; // rax

  v2 = 0;
  for ( i = (_DWORD *)&qword_142370764 + 1; ; i += 5 )
  {
    v4 = 0;
    if ( numDataTypes )
      break;
LABEL_6:
    if ( !numDataTypes )
      goto LABEL_7;
LABEL_9:
    if ( (unsigned int)++v2 >= 5 )
      return 0;
  }
  v5 = dataTypes;
  while ( i[1] != *v5 )
  {
    ++v4;
    ++v5;
    if ( v4 >= numDataTypes )
      goto LABEL_6;
  }
LABEL_7:
  if ( *i <= 0x64u || UFG::Metrics::msFrameCount - *(i - 2) >= 0x1E )
    goto LABEL_9;
  return 1;
}

// File Line: 642
// RVA: 0x22A670
char __fastcall UFG::DataStreamer::IsStalled(UFG::StreamingMemory::DATA_TYPE *dataTypes, unsigned int numDataTypes)
{
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v5; // rdx
  char v6; // r10
  unsigned int v7; // ecx
  UFG::StreamingMemory::DATA_TYPE *v8; // rax
  int mPrev; // eax

  if ( dataTypes )
  {
    v5 = UFG::DataStreamer::mOrderList.mNode.mNext - 2;
    v6 = 0;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)&UFG::DataStreamer::mOrderList.mNode.mNext[-2] == &UFG::DataStreamer::mOrderList - 2 )
      return v6;
    while ( 1 )
    {
      v7 = 0;
      if ( numDataTypes )
      {
        v8 = dataTypes;
        while ( LODWORD(v5[4].mNext) != *v8 )
        {
          ++v7;
          ++v8;
          if ( v7 >= numDataTypes )
            goto LABEL_18;
        }
        mPrev = (int)v5[4].mPrev;
        if ( mPrev == 3 )
          return 0;
        if ( mPrev == 2 )
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
  UFG::qBaseTreeRB *i; // r8
  unsigned int v5; // ecx
  UFG::StreamingMemory::DATA_TYPE *v6; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &i->mRoot) )
  {
    v5 = 0;
    if ( numDataTypes )
    {
      v6 = dataTypes;
      while ( LODWORD(i[1].mRoot.mParent) != *v6 )
      {
        ++v5;
        ++v6;
        if ( v5 >= numDataTypes )
          goto LABEL_10;
      }
      if ( (unsigned int)(i->mCount - 2) > 1 )
        LOWORD(i[1].mRoot.mChild[0]) &= ~0x80u;
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
      LOWORD(i[1].mRoot.mChild[0]) &= ~0x80u;
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
    LOWORD(i[1].mRoot.mChild[0]) &= ~0x80u;
  }
  UFG::DataStreamer::mbTagging = 0;
}

// File Line: 781
// RVA: 0x22A790
bool __fastcall UFG::DataStreamer::IsTaggedStalled()
{
  float v0; // xmm6_4
  UFG::qBaseTreeRB *Head; // rax

  v0 = FLOAT_3_4028235e38;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::DataStreamer::mStreamInfo);
  if ( !Head )
    return 0;
  do
  {
    if ( SLOBYTE(Head[1].mRoot.mChild[0]) < 0 )
    {
      if ( Head->mCount == 2 )
      {
        if ( v0 >= *((float *)&Head[1].mRoot.mParent + 1) )
          v0 = *((float *)&Head[1].mRoot.mParent + 1);
      }
      else if ( Head->mCount == 3 )
      {
        return 0;
      }
    }
    Head = UFG::qBaseTreeRB::GetNext(&UFG::DataStreamer::mStreamInfo.mTree, &Head->mRoot);
  }
  while ( Head );
  return v0 < 3.4028235e38 && v0 > 1.0;
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
UFG::DataStreamer::StreamInfo *__fastcall UFG::DataStreamer::AllocateStreamInfo(
        const char *fileName,
        unsigned int streamUID)
{
  UFG::allocator::free_link *v4; // rax
  UFG::DataStreamer::StreamInfo *v5; // rax
  UFG::DataStreamer::StreamInfo *v6; // rbx

  v4 = UFG::qMalloc(0x108ui64, "AllocateStreamInfo", 0x800ui64);
  if ( v4 )
  {
    UFG::DataStreamer::StreamInfo::StreamInfo((UFG::DataStreamer::StreamInfo *)v4, streamUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qString::Set(&v6->mFileName, fileName);
  v6->mStateCurrent = STATE_EMPTY;
  v6->mDiskPosSortKey = -1i64;
  *((_WORD *)v6 + 40) &= ~0x80u;
  *(_QWORD *)&v6->mFileSizePerm.load_offset = 0i64;
  *(_QWORD *)&v6->mFileSizePerm.compressed_extra = 0i64;
  *(_QWORD *)&v6->mFileSizeTemp.load_offset = 0i64;
  *(_QWORD *)&v6->mFileSizeTemp.compressed_extra = 0i64;
  UFG::qBaseTreeRB::Add(&UFG::DataStreamer::mStreamInfo.mTree, &v6->mNode);
  return v6;
}

// File Line: 978
// RVA: 0x22C360
char __fastcall UFG::DataStreamer::QueueStream(
        UFG::DataStreamer::Handle *handle,
        const char *filename,
        unsigned int mem_tag_qsymbol_uid,
        UFG::StreamingMemory::DATA_TYPE data_type,
        UFG::DataStreamer::PRIORITY priority,
        unsigned int flags,
        void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *),
        void *callbackParam)
{
  UFG::DataStreamer::Handle *mPrev; // rax
  UFG::DataStreamer::StreamInfo *mImpl; // rcx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v14; // rdx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mNext; // rax
  unsigned int ResourceFileUID; // eax
  unsigned int v17; // esi
  UFG::DataStreamer::StreamInfo *StreamInfo; // rdi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v19; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v20; // rax
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v21; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v22; // rax
  void (__fastcall *mCallback)(UFG::DataStreamer::Handle *, void *); // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v24; // rax

  mPrev = (UFG::DataStreamer::Handle *)handle->mPrev;
  if ( handle->mPrev != handle || handle->mNext != handle )
  {
    mImpl = (UFG::DataStreamer::StreamInfo *)handle->mImpl;
    if ( mImpl )
    {
      if ( mPrev != handle || handle->mNext != handle )
      {
        if ( handle == UFG::DataStreamer::gCurrentStreamHandle )
          UFG::DataStreamer::gCurrentStreamHandle = (UFG::DataStreamer::Handle *)UFG::DataStreamer::gCurrentStreamHandle->mPrev;
        v14 = handle->mPrev;
        mNext = handle->mNext;
        v14->mNext = mNext;
        mNext->mPrev = v14;
        handle->mPrev = handle;
        handle->mNext = handle;
        handle->_mTargetState.mValue = 1;
        UFG::DataStreamer::StreamInfo::RecacheHandleInfo(mImpl);
        handle->mImpl = 0i64;
        handle->mCallback = 0i64;
        handle->mCallbackParam = 0i64;
      }
    }
  }
  ResourceFileUID = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, filename);
  v17 = ResourceFileUID;
  if ( ResourceFileUID )
    StreamInfo = (UFG::DataStreamer::StreamInfo *)UFG::qBaseTreeRB::Get(
                                                    &UFG::DataStreamer::mStreamInfo.mTree,
                                                    ResourceFileUID);
  else
    StreamInfo = 0i64;
  if ( StreamInfo )
  {
    v19 = StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mPrev;
    v20 = StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mPrev = &StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>;
    StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mNext = &StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>;
  }
  else
  {
    StreamInfo = UFG::DataStreamer::AllocateStreamInfo(filename, v17);
  }
  if ( !StreamInfo )
    return 0;
  *((_WORD *)StreamInfo + 40) &= ~0x10u;
  *((_WORD *)StreamInfo + 40) |= 16 * ((flags >> 4) & 1);
  if ( StreamInfo->mDiskPosSortKey == -1i64 )
    StreamInfo->mDiskPosSortKey = UFG::DataStreamer::GetDiskPosSortKey(filename);
  handle->mFlags = flags;
  handle->mImpl = StreamInfo;
  handle->mCallback = callback;
  handle->mCallbackParam = callbackParam;
  handle->mPriority.mValue = priority;
  StreamInfo->mDataType = data_type;
  v21 = StreamInfo->mHandles.mNode.mPrev;
  v21->mNext = handle;
  handle->mPrev = v21;
  handle->mNext = &StreamInfo->mHandles.mNode;
  StreamInfo->mHandles.mNode.mPrev = handle;
  StreamInfo->mTagSymbolUID = mem_tag_qsymbol_uid;
  v22 = UFG::DataStreamer::mOrderList.mNode.mPrev;
  UFG::DataStreamer::mOrderList.mNode.mPrev->mNext = &StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>;
  StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mPrev = v22;
  StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>::mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&UFG::DataStreamer::mOrderList;
  UFG::DataStreamer::mOrderList.mNode.mPrev = &StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder>;
  if ( StreamInfo->mStateCurrent == STATE_ACTIVE )
  {
    mCallback = handle->mCallback;
    if ( mCallback )
      mCallback(handle, handle->mCallbackParam);
  }
  handle->_mTargetState.mValue = 6;
  if ( StreamInfo->mStateCurrent == STATE_EMPTY )
  {
    StreamInfo->mStateCurrent = STATE_LOAD_QUEUED;
    StreamInfo->mTimeInState = 0.0;
    v24 = UFG::DataStreamer::mPriorityList.mNode.mPrev;
    UFG::DataStreamer::mPriorityList.mNode.mPrev->mNext = &StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
    StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev = v24;
    StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&UFG::DataStreamer::mPriorityList;
    UFG::DataStreamer::mPriorityList.mNode.mPrev = &StreamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
  }
  UFG::DataStreamer::StreamInfo::RecacheHandleInfo(StreamInfo);
  return 1;
}

// File Line: 1085
// RVA: 0x22C580
char __fastcall UFG::DataStreamer::QueueStream(
        UFG::DataStreamer::Handle *handle,
        const char *filename,
        UFG::StreamingMemory::DATA_TYPE data_type,
        UFG::DataStreamer::PRIORITY priority,
        unsigned int flags,
        void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *),
        void *callbackParam)
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
  UFG::DataStreamer::StreamInfo *mImpl; // rcx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mNext; // rax
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mPrev; // rdx
  char result; // al

  mImpl = (UFG::DataStreamer::StreamInfo *)handle->mImpl;
  if ( !mImpl || handle->mPrev == handle && handle->mNext == handle )
    return 0;
  if ( handle == UFG::DataStreamer::gCurrentStreamHandle )
    UFG::DataStreamer::gCurrentStreamHandle = (UFG::DataStreamer::Handle *)UFG::DataStreamer::gCurrentStreamHandle->mPrev;
  mNext = handle->mNext;
  mPrev = handle->mPrev;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  handle->mPrev = handle;
  handle->mNext = handle;
  handle->_mTargetState.mValue = 1;
  UFG::DataStreamer::StreamInfo::RecacheHandleInfo(mImpl);
  result = 1;
  handle->mImpl = 0i64;
  handle->mCallback = 0i64;
  handle->mCallbackParam = 0i64;
  return result;
}

// File Line: 1143
// RVA: 0x22EFB0
// attributes: thunk
void __fastcall UFG::DataStreamer::fnDataStreamCallback(UFG::qFileOp *file_op, unsigned int *callback_param)
{
  UFG::DataStreamer::OnFileCompletionCallback(file_op, callback_param);
}

// File Line: 1148
// RVA: 0x229290
void __fastcall UFG::DataStreamer::FireStreamLoadCallback(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::DataStreamer::Handle *mNext; // rax
  UFG::qList<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle,1,0> *p_mHandles; // rbx
  void (__fastcall *mCallback)(UFG::DataStreamer::Handle *, void *); // r8

  mNext = (UFG::DataStreamer::Handle *)streamInfo->mHandles.mNode.mNext;
  p_mHandles = &streamInfo->mHandles;
  for ( UFG::DataStreamer::gCurrentStreamHandle = mNext;
        mNext != (UFG::DataStreamer::Handle *)p_mHandles;
        UFG::DataStreamer::gCurrentStreamHandle = mNext )
  {
    mCallback = mNext->mCallback;
    if ( mCallback )
    {
      mCallback(mNext, mNext->mCallbackParam);
      mNext = UFG::DataStreamer::gCurrentStreamHandle;
    }
    mNext = (UFG::DataStreamer::Handle *)mNext->mNext;
  }
  UFG::DataStreamer::gCurrentStreamHandle = 0i64;
}

// File Line: 1162
// RVA: 0x22AEA0
void __fastcall UFG::DataStreamer::LoadStreamResources(UFG::DataStreamer::StreamInfo *streamInfo)
{
  unsigned int v2; // r8d
  char v3; // cl
  unsigned int lastFrame; // r9d
  unsigned int v5; // r10d
  unsigned int v6; // r11d
  unsigned int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned __int64 v10; // rdx
  unsigned __int64 mhBufferPerm; // rdx
  UFG::qBaseTreeRB *v12; // rax
  char *mParent; // r12
  __int64 uncompressed_size; // r13
  unsigned int ResourceFileUID; // ebx
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
  unsigned int i; // eax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *mPrev; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *mNext; // rax
  __int64 v30; // rsi
  unsigned int v31; // edx
  UFG::qBaseTreeRB *v32; // rax
  unsigned __int64 v33; // rdx
  UFG::qBaseTreeRB *v34; // rax
  UFG::qString v35; // [rsp+28h] [rbp-50h] BYREF

  v2 = UFG::Metrics::msFrameCount;
  v3 = 0;
  if ( (_DWORD)qword_142370764 == streamInfo->mNode.mUID )
  {
    ++HIDWORD(qword_142370764);
    lastFrame = UFG::Metrics::msFrameCount;
    UFG::DataStreamer::gStallRecord[0].lastFrame = UFG::Metrics::msFrameCount;
    v3 = 1;
  }
  else
  {
    lastFrame = UFG::DataStreamer::gStallRecord[0].lastFrame;
  }
  if ( (_DWORD)qword_142370778 == streamInfo->mNode.mUID )
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
  if ( (_DWORD)qword_14237078C == streamInfo->mNode.mUID )
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
  if ( (_DWORD)qword_1423707A0 == streamInfo->mNode.mUID )
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
  if ( (_DWORD)qword_1423707B4 == streamInfo->mNode.mUID )
  {
    ++HIDWORD(qword_1423707B4);
    HIDWORD(qword_1423707AC) = UFG::Metrics::msFrameCount;
    goto LABEL_28;
  }
  if ( !v3 )
  {
    v8 = -1;
    v9 = -1;
    if ( lastFrame != -1 )
    {
      v8 = lastFrame;
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
    *((_DWORD *)&qword_142370764 + v10) = streamInfo->mNode.mUID;
    UFG::DataStreamer::gStallRecord[v10 / 5].lastFrame = v2;
    *((_DWORD *)&qword_142370764 + v10 + 1) = 1;
    *((_DWORD *)&qword_14237076C + v10) = streamInfo->mDataType;
  }
LABEL_28:
  if ( (streamInfo->mFlagsOR & 0x20) != 0 )
  {
    streamInfo->mDataLoadedTo = streamInfo->mFileSizePerm.uncompressed_size;
  }
  else
  {
    if ( (*((_BYTE *)streamInfo + 80) & 0x10) != 0 )
    {
      UFG::qResourceInventory::SetHotSwapMode(1);
      Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
    }
    mhBufferPerm = streamInfo->mhBufferPerm;
    if ( (_DWORD)mhBufferPerm )
      v12 = UFG::qBaseTreeRB::Get(
              &UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree,
              mhBufferPerm);
    else
      v12 = 0i64;
    mParent = (char *)v12[1].mRoot.mParent;
    uncompressed_size = streamInfo->mFileSizePerm.uncompressed_size;
    if ( streamInfo->mhBufferTemp.mData )
    {
      UFG::qString::qString(&v35, &streamInfo->mFileName);
      ResourceFileUID = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v35.mData);
      UFG::qString::ReplaceString(&v35, "perm.bin", "temp.bin", 1);
      v16 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v35.mData);
      UFG::qChunkFileSystem::AddExternalResourceFileReference(v16, &streamInfo->mhBufferTemp, streamInfo);
      UFG::qChunkFileSystem::AddExternalResourceFileReference(
        ResourceFileUID,
        mParent,
        (unsigned int)uncompressed_size,
        0i64);
      *((_WORD *)streamInfo + 40) |= 0x100u;
      UFG::qString::~qString(&v35);
    }
    ++foo_dfsdgs;
    v17 = (unsigned int *)mParent;
    if ( streamInfo->mDataType == DATA_SECTION_STD )
    {
      v18 = &mParent[uncompressed_size];
      if ( mParent < &mParent[uncompressed_size] )
      {
        v19 = sTypeToChunkUIDLookup[7];
        while ( 1 )
        {
          v20 = *v17;
          if ( (_DWORD)v20 )
            break;
LABEL_49:
          v17 = (unsigned int *)((char *)v17 + ((v17[1] + 3) & 0xFFFFFFFC) + 16);
          if ( v17 >= (unsigned int *)v18 )
            goto LABEL_56;
        }
        v21 = 0;
        v22 = sTypeToChunkUIDLookup[7];
        while ( (*v22)[0] != v20 )
        {
          ++v21;
          ++v22;
          if ( v21 >= 3 )
          {
            v23 = v17[3];
            if ( (_S2_9 & 1) == 0 )
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
                  (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)&v25[-1].mCount + 72i64))(
                    &v25[-1].mCount,
                    (__int64)v17 + v23 + 16);
              }
            }
            goto LABEL_49;
          }
        }
        if ( v17 < (unsigned int *)v18 )
        {
          v26 = *v17;
          if ( (_DWORD)v26 )
          {
            for ( i = 0; i < 3; ++i )
            {
              if ( (*v19)[0] == v26 )
                break;
              ++v19;
            }
          }
        }
      }
LABEL_56:
      streamInfo->mDataLoadedTo += (_DWORD)v17 - (_DWORD)mParent;
      if ( streamInfo->mDataLoadedTo != (_DWORD)uncompressed_size )
      {
        if ( streamInfo->mStateCurrent == STATE_LOAD_QUEUED )
        {
          mPrev = streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev;
          mNext = streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev = &streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
          streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext = &streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
        }
        streamInfo->mStateCurrent = STATE_FIXUP_DELAY;
        streamInfo->mTimeInState = 0.0;
      }
    }
    else
    {
      if ( mParent < &mParent[uncompressed_size] )
      {
        do
        {
          if ( *v17 )
          {
            v30 = v17[3];
            if ( (_S2_9 & 1) == 0 )
            {
              _S2_9 |= 1u;
              qword_1423A8CE0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
            }
            v31 = *(unsigned int *)((char *)v17 + v30 + 64);
            if ( v31 )
            {
              v32 = UFG::qBaseTreeRB::Get(qword_1423A8CE0, v31);
              if ( v32 )
              {
                if ( v32 != (UFG::qBaseTreeRB *)8 )
                  (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)&v32[-1].mCount + 72i64))(
                    &v32[-1].mCount,
                    (__int64)v17 + v30 + 16);
              }
            }
          }
          v17 = (unsigned int *)((char *)v17 + ((v17[1] + 3) & 0xFFFFFFFC) + 16);
        }
        while ( v17 < (unsigned int *)&mParent[uncompressed_size] );
      }
      streamInfo->mDataLoadedTo += (_DWORD)v17 - (_DWORD)mParent;
    }
  }
  v33 = streamInfo->mhBufferPerm;
  if ( (_DWORD)v33 )
  {
    v34 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree, v33);
    if ( v34 )
      LOWORD(v34->mNULL.mChild[1]) |= 0x100u;
  }
  if ( (streamInfo->mFlagsOR & 0x20) == 0 && (*((_BYTE *)streamInfo + 80) & 0x10) != 0 )
    UFG::qResourceInventory::SetHotSwapMode(0);
  if ( streamInfo->mStateCurrent != STATE_FIXUP_DELAY )
    *((_WORD *)streamInfo + 40) |= 2u;
}

// File Line: 1300
// RVA: 0x229110
void __fastcall UFG::DataStreamer::FinishLoadingResources(UFG::DataStreamer::StreamInfo *streamInfo)
{
  unsigned __int64 mhBufferPerm; // rdx
  UFG::qBaseTreeRB *v3; // rcx
  __int64 mDataLoadedTo; // r14
  __int64 v5; // rbp
  _DWORD *v6; // r14
  _DWORD *v7; // rbx
  unsigned __int64 v8; // rbp
  __int64 v9; // rsi
  unsigned int v10; // edx
  UFG::qBaseTreeRB *v11; // rax
  unsigned __int64 v12; // rdx
  UFG::qBaseTreeRB *v13; // rax

  if ( (*((_BYTE *)streamInfo + 80) & 0x10) != 0 )
  {
    UFG::qResourceInventory::SetHotSwapMode(1);
    Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
  }
  if ( (streamInfo->mFlagsOR & 0x20) == 0 )
  {
    mhBufferPerm = streamInfo->mhBufferPerm;
    if ( (_DWORD)mhBufferPerm )
      v3 = UFG::qBaseTreeRB::Get(
             &UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree,
             mhBufferPerm);
    else
      v3 = 0i64;
    mDataLoadedTo = streamInfo->mDataLoadedTo;
    v5 = (unsigned int)(streamInfo->mFileSizePerm.uncompressed_size - mDataLoadedTo);
    v6 = (_DWORD *)((char *)v3[1].mRoot.mParent + mDataLoadedTo);
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
          if ( (_S2_9 & 1) == 0 )
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
                (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)&v11[-1].mCount + 72i64))(
                  &v11[-1].mCount,
                  (__int64)v7 + v9 + 16);
            }
          }
        }
        v7 = (_DWORD *)((char *)v7 + ((v7[1] + 3) & 0xFFFFFFFC) + 16);
      }
      while ( (unsigned __int64)v7 < v8 );
    }
    streamInfo->mDataLoadedTo += (_DWORD)v7 - (_DWORD)v6;
  }
  v12 = streamInfo->mhBufferPerm;
  if ( (_DWORD)v12 )
  {
    v13 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree, v12);
    if ( v13 )
      LOWORD(v13->mNULL.mChild[1]) |= 0x100u;
  }
  if ( (*((_BYTE *)streamInfo + 80) & 0x10) != 0 )
    UFG::qResourceInventory::SetHotSwapMode(0);
  *((_WORD *)streamInfo + 40) |= 2u;
}

// File Line: 1474
// RVA: 0x22ED00
char __fastcall UFG::DataStreamer::UnloadStreamResources(UFG::DataStreamer::StreamInfo *streamInfo)
{
  unsigned __int64 mhBufferPerm; // rdx
  UFG::StreamPool *v3; // rbx
  UFG::qBaseTreeRB *v4; // rax
  char result; // al
  unsigned __int64 v6; // rdx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseNodeRB *mParent; // rdi
  __int64 uncompressed_size; // rbp
  UFG::qBaseNodeRB *i; // rbp
  __int64 v11; // rbx
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  unsigned __int64 v14; // rdx
  UFG::qBaseTreeRB *v15; // rax
  char *v16; // rdi
  unsigned int v17; // ebx
  unsigned int ResourceFileUID; // eax
  unsigned int v19; // eax
  unsigned __int64 v20; // rdx
  UFG::qBaseTreeRB *v21; // rax
  UFG::qString v22; // [rsp+28h] [rbp-40h] BYREF

  mhBufferPerm = streamInfo->mhBufferPerm;
  v3 = UFG::gStreamPools[BYTE4(mhBufferPerm) & 0x1F];
  if ( v3->mDefragState.meState )
  {
    v4 = (_DWORD)mhBufferPerm ? UFG::qBaseTreeRB::Get(&v3->mBlockLookup.mTree, mhBufferPerm) : 0i64;
    if ( v4 == (UFG::qBaseTreeRB *)v3->mDefragState.mMovingBlock )
      return 0;
  }
  v6 = streamInfo->mhBufferPerm;
  if ( (_DWORD)v6 )
    v7 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree, v6);
  else
    v7 = 0i64;
  mParent = v7[1].mRoot.mParent;
  if ( (streamInfo->mFlagsOR & 0x20) == 0 )
  {
    uncompressed_size = streamInfo->mFileSizePerm.uncompressed_size;
    UFG::qResourceWarehouse::Instance();
    for ( i = (UFG::qBaseNodeRB *)((char *)mParent + uncompressed_size);
          mParent < i;
          mParent = (UFG::qBaseNodeRB *)((char *)mParent + ((HIDWORD(mParent->mParent) + 3) & 0xFFFFFFFC) + 16) )
    {
      if ( LODWORD(mParent->mParent) )
      {
        v11 = HIDWORD(mParent->mChild[0]);
        if ( (_S3_7 & 1) == 0 )
        {
          _S3_7 |= 1u;
          qword_1423A8CF0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
        }
        v12 = *(_DWORD *)((char *)&mParent[2].mParent + v11);
        if ( v12 )
        {
          v13 = UFG::qBaseTreeRB::Get(qword_1423A8CF0, v12);
          if ( v13 )
          {
            if ( v13 != (UFG::qBaseTreeRB *)8 )
              (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)&v13[-1].mCount + 80i64))(
                &v13[-1].mCount,
                (__int64)&mParent->mChild[1] + v11);
          }
        }
      }
    }
  }
  if ( (*((_BYTE *)streamInfo + 81) & 1) != 0 )
  {
    v14 = streamInfo->mhBufferPerm;
    if ( (_DWORD)v14 )
      v15 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree, v14);
    else
      v15 = 0i64;
    v16 = (char *)v15[1].mRoot.mParent;
    v17 = streamInfo->mFileSizePerm.uncompressed_size;
    UFG::qString::qString(&v22, &streamInfo->mFileName);
    ResourceFileUID = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v22.mData);
    UFG::qChunkFileSystem::RemoveExternalResourceFileReference(ResourceFileUID, v16, v17);
    if ( streamInfo->mhBufferTemp.mData )
    {
      UFG::qString::ReplaceString(&v22, "perm.bin", "temp.bin", 1);
      v19 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v22.mData);
      UFG::qChunkFileSystem::RemoveExternalResourceFileReference(v19, &streamInfo->mhBufferTemp);
      if ( streamInfo->mhBufferTemp.mData )
        UFG::qVRAMemoryPools::Free(&streamInfo->mhBufferTemp, 0);
    }
    UFG::qString::~qString(&v22);
  }
  v20 = streamInfo->mhBufferPerm;
  if ( (_DWORD)v20 )
  {
    v21 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree, v20);
    if ( v21 )
      LOWORD(v21->mNULL.mChild[1]) &= ~0x100u;
  }
  result = 1;
  *((_WORD *)streamInfo + 40) &= ~2u;
  streamInfo->mDataLoadedTo = 0;
  return result;
}

// File Line: 1537
// RVA: 0x22BAE0
void __fastcall UFG::DataStreamer::OnStreamLoadComplete(UFG::DataStreamer::StreamInfo *streamInfo)
{
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *mPrev; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *mNext; // rax

  UFG::DataStreamer::LoadStreamResources(streamInfo);
  if ( streamInfo->mStateCurrent != STATE_FIXUP_DELAY )
  {
    UFG::DataStreamer::FireStreamLoadCallback(streamInfo);
    if ( streamInfo->mStateCurrent == STATE_LOAD_QUEUED )
    {
      mPrev = streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev;
      mNext = streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev = &streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
      streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext = &streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
    }
    streamInfo->mStateCurrent = STATE_ACTIVE;
    streamInfo->mTimeInState = 0.0;
  }
  --UFG::DataStreamer::mFileOperationCount;
  UFG::DataStreamer::mLoadedBytes += streamInfo->mFileSizePerm.compressed_extra
                                   + streamInfo->mFileSizePerm.uncompressed_size;
  UFG::DataStreamer::mLoadedBytes += streamInfo->mFileSizeTemp.compressed_extra
                                   + streamInfo->mFileSizeTemp.uncompressed_size;
}

// File Line: 1564
// RVA: 0x22B7A0
void __fastcall UFG::DataStreamer::OnFileCompletionCallback(UFG::qFileOp *file_op, unsigned int *callback_param)
{
  char *v4; // rsi
  char *v5; // rbp
  char *v6; // rax
  char *EntireFileSize; // rax
  char *Filename; // rax
  UFG::qFile **v9; // rcx
  __int64 v10; // rdx
  UFG::qBaseTreeRB *v11; // rax

  if ( (unsigned int)Scaleform::Render::FileImageSource::GetUse(file_op) != STATUS_WAIT_3
    && (unsigned int)Scaleform::Render::FileImageSource::GetUse(file_op) != 4 )
  {
    return;
  }
  v4 = 0i64;
  v5 = 0i64;
  if ( file_op )
  {
    if ( (v6 = (char *)callback_param[24], (_DWORD)v6) && *((_QWORD *)callback_param + 14)
      || (v6 = (char *)callback_param[33], (_DWORD)v6) )
    {
      v4 = v6;
    }
  }
  if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)file_op) == 6
    || (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)file_op) == 2 )
  {
    EntireFileSize = (char *)UFG::qFileOp::GetReadEntireFileSize(file_op);
  }
  else
  {
    if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)file_op) != 9 )
      goto LABEL_14;
    EntireFileSize = UFG::qFileOp::GetReadEntireFileBuffer(file_op);
  }
  v5 = EntireFileSize;
LABEL_14:
  if ( v5 == v4 )
  {
    v9 = (UFG::qFile **)*((_QWORD *)callback_param + 14);
    if ( v9 )
    {
      UFG::StreamFileWrapper::Close(v9);
      *((_QWORD *)callback_param + 14) = 0i64;
    }
    if ( (callback_param[20] & 4) == 0 )
      UFG::StreamPool_Unlock(*((_QWORD *)callback_param + 13));
    if ( (callback_param[61] & 2) == 0 )
    {
      v10 = *((_QWORD *)callback_param + 13);
      if ( (_DWORD)v10 )
      {
        v11 = UFG::qBaseTreeRB::Get(
                &UFG::gStreamPools[HIDWORD(*((_QWORD *)callback_param + 13)) & 0x1F]->mBlockLookup.mTree,
                v10);
        if ( v11 )
          LOWORD(v11->mNULL.mChild[1]) |= 0x20u;
      }
    }
    if ( callback_param[33] )
    {
      UFG::StreamFileWrapper::Close(*((UFG::qFile ***)callback_param + 21));
      *((_QWORD *)callback_param + 21) = 0i64;
      UFG::qVRAMemoryHandle::Unlock((UFG::qVRAMemoryHandle *)(callback_param + 34));
    }
    UFG::DataStreamer::OnStreamLoadComplete((UFG::DataStreamer::StreamInfo *)callback_param);
  }
  else
  {
    Filename = UFG::qFileOp::GetFilename(file_op);
    UFG::qPrintf(
      "file_op 0x%08x Read %d64 of %d64 expected bytes for stream 0x%08x from %s\n",
      file_op,
      v5,
      v4,
      callback_param,
      Filename);
  }
}

// File Line: 1684
// RVA: 0x22BE00
signed __int64 __fastcall UFG::DataStreamer::OpenFiles(
        UFG::DataStreamer::StreamInfo *streamInfo,
        unsigned int *CPURAMRestoredSizeBytes,
        unsigned int *VRAMRestoredSizeBytes)
{
  unsigned int *v3; // r12
  unsigned int *v4; // r15
  unsigned int mFlagsOR; // r13d
  char *mData; // rdi
  char v8; // r14
  unsigned int v9; // eax
  __int64 v10; // rsi
  unsigned int v11; // edi
  UFG::qFile **v12; // rsi
  UFG::qFile **v13; // rbp
  unsigned int v14; // r15d
  unsigned int v15; // r12d
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *mNext; // rcx
  unsigned int FileSize; // eax
  int v19; // ecx
  UFG::allocator::free_link *v20; // rax
  unsigned int *v21; // rcx
  unsigned int v22; // eax
  unsigned int v23; // r14d
  __int16 v25; // r14
  char v26; // cl
  unsigned int v27; // [rsp+70h] [rbp-198h]
  unsigned int v28; // [rsp+74h] [rbp-194h]
  unsigned int v29; // [rsp+78h] [rbp-190h]
  unsigned int mNext_high; // [rsp+80h] [rbp-188h]
  UFG::qVRAMemoryHandle handle; // [rsp+90h] [rbp-178h] BYREF
  __int64 v32; // [rsp+B0h] [rbp-158h]
  char v33[8]; // [rsp+B8h] [rbp-150h] BYREF
  char dest[328]; // [rsp+C0h] [rbp-148h] BYREF
  unsigned int error_flags; // [rsp+210h] [rbp+8h] BYREF
  unsigned int *v36; // [rsp+218h] [rbp+10h]
  unsigned int *v37; // [rsp+220h] [rbp+18h]
  unsigned __int64 phMainRAM; // [rsp+228h] [rbp+20h] BYREF

  v37 = VRAMRestoredSizeBytes;
  v36 = CPURAMRestoredSizeBytes;
  v32 = -2i64;
  v3 = VRAMRestoredSizeBytes;
  v4 = CPURAMRestoredSizeBytes;
  mFlagsOR = streamInfo->mFlagsOR;
  mData = streamInfo->mFileName.mData;
  v8 = 0;
  v9 = UFG::qStringLength(mData);
  v10 = v9;
  if ( v9 > 8 && !(unsigned int)UFG::qStringCompareInsensitive(&mData[v9 - 8], "perm.bin", -1) )
  {
    UFG::qStringCopy(dest, 256, mData, v10 - 8);
    UFG::qStringCopy(&v33[v10], 0x7FFFFFFF, "temp.bin", -1);
    v8 = 1;
  }
  v11 = 0;
  v12 = 0i64;
  v13 = 0i64;
  if ( (*((_BYTE *)streamInfo + 80) & 1) != 0 )
    goto LABEL_21;
  error_flags = 0;
  v29 = 0;
  v14 = 0;
  v15 = 0;
  v16 = UFG::StreamFileWrapper::Open(streamInfo->mFileName.mData, QACCESS_READ, 1, 0i64, 0i64);
  v12 = (UFG::qFile **)v16;
  if ( !v16 )
    return 1i64;
  if ( v16[4].mNext )
  {
    mNext = v16[5].mNext;
    v28 = (unsigned int)mNext[1].mNext;
    mNext_high = HIDWORD(mNext[1].mNext);
    LODWORD(phMainRAM) = mNext[2].mNext;
    FileSize = HIDWORD(mNext[2].mNext);
    v19 = phMainRAM;
  }
  else
  {
    FileSize = UFG::qGetFileSize((UFG::qFile *)v16[7].mNext);
    mNext_high = FileSize;
    v28 = 0;
    v19 = 0;
    LODWORD(phMainRAM) = 0;
  }
  v27 = FileSize;
  if ( FileSize + v19 )
  {
    if ( v8 )
    {
      v20 = UFG::StreamFileWrapper::Open(dest, QACCESS_READ, 0, 0i64, 0i64);
      v13 = (UFG::qFile **)v20;
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
  streamInfo->mFileSizePerm.load_offset = v28;
  streamInfo->mFileSizePerm.compressed_size = mNext_high;
  streamInfo->mFileSizePerm.compressed_extra = phMainRAM;
  streamInfo->mFileSizePerm.uncompressed_size = v27;
  streamInfo->mFileSizeTemp.load_offset = v23;
  streamInfo->mFileSizeTemp.compressed_size = v29;
  streamInfo->mFileSizeTemp.compressed_extra = v14;
  streamInfo->mFileSizeTemp.uncompressed_size = v15;
  *((_WORD *)streamInfo + 40) |= 1u;
  v4 = v36;
  v3 = v37;
LABEL_21:
  v25 = 0;
  if ( (mFlagsOR & 1) == 0 )
    v25 = 64;
  if ( (mFlagsOR & 2) == 0 )
    v25 |= 32u;
  if ( (mFlagsOR & 0x100) != 0 )
    v25 |= 0x200u;
  *((_WORD *)streamInfo + 40) &= 0xFF9Bu;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&handle);
  phMainRAM = -1i64;
  error_flags = 0;
  if ( UFG::StreamingMemory::Allocate(
         streamInfo->mDataType,
         v25,
         streamInfo->mFileSizePerm.compressed_extra + streamInfo->mFileSizePerm.uncompressed_size,
         streamInfo->mFileSizePerm.uncompressed_size,
         streamInfo->mFileSizeTemp.compressed_extra + streamInfo->mFileSizeTemp.uncompressed_size,
         &phMainRAM,
         &handle,
         streamInfo->mFileName.mData,
         0i64,
         v4,
         v3,
         0i64,
         0i64,
         &error_flags) )
  {
    *((_WORD *)streamInfo + 40) ^= (*((_WORD *)streamInfo + 40) ^ (4 * (*v4 != 0))) & 4;
    if ( *v4 )
    {
      if ( v12 )
        UFG::StreamFileWrapper::Close(v12);
      streamInfo->mhBufferPerm = phMainRAM;
      *((_WORD *)streamInfo + 40) &= ~1u;
      *((_WORD *)streamInfo + 40) |= 8u;
    }
    else
    {
      if ( !v12 )
        v12 = (UFG::qFile **)UFG::StreamFileWrapper::Open(streamInfo->mFileName.mData, QACCESS_READ, 1, 0i64, 0i64);
      streamInfo->mhFilePerm = v12;
      streamInfo->mhBufferPerm = phMainRAM;
    }
    if ( streamInfo->mFileSizeTemp.uncompressed_size )
    {
      if ( !v13 )
        v13 = (UFG::qFile **)UFG::StreamFileWrapper::Open(dest, QACCESS_READ, 1, 0i64, 0i64);
      streamInfo->mhFileTemp = v13;
      UFG::qVRAMemoryHandle::operator=(&streamInfo->mhBufferTemp, &handle);
    }
  }
  else
  {
    v26 = error_flags;
    if ( (error_flags & 1) != 0 )
      *((_WORD *)streamInfo + 40) |= 0x20u;
    if ( (v26 & 2) != 0 )
      *((_WORD *)streamInfo + 40) |= 0x40u;
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
  unsigned int v2; // edi
  char v3; // di
  void (__fastcall *callback)(UFG::qFileOp *, void *); // rcx
  unsigned __int64 mhBufferPerm; // rdx
  UFG::qBaseTreeRB *v6; // rax
  unsigned __int64 v7; // rdx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *mPrev; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *mNext; // rax
  bool v11; // zf

  v2 = streamInfo->mFlagsOR >> 6;
  streamInfo->mDataLoadedTo = 0;
  v3 = v2 & 1;
  if ( streamInfo->mFileSizeTemp.uncompressed_size )
  {
    UFG::qVRAMemoryHandle::Lock(&streamInfo->mhBufferTemp);
    callback = (void (__fastcall *)(UFG::qFileOp *, void *))_;
    if ( (*((_BYTE *)streamInfo + 80) & 4) != 0 )
      callback = UFG::DataStreamer::fnDataStreamCallback;
    UFG::StreamFileWrapper::Read(
      streamInfo->mhFileTemp,
      (UFG::StreamFileWrapper::QUEUE_CLASS)(3 - (v3 != 0)),
      streamInfo->mhBufferTemp.mData,
      &streamInfo->mFileSizeTemp,
      0i64,
      QSEEK_SET,
      callback,
      streamInfo,
      0);
  }
  if ( (*((_BYTE *)streamInfo + 80) & 4) == 0 )
  {
    mhBufferPerm = streamInfo->mhBufferPerm;
    if ( (_DWORD)mhBufferPerm )
    {
      v6 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[BYTE4(mhBufferPerm) & 0x1F]->mBlockLookup.mTree, mhBufferPerm);
      if ( v6 )
        LOWORD(v6->mNULL.mChild[1]) |= 0x80u;
    }
    v7 = streamInfo->mhBufferPerm;
    if ( (_DWORD)v7 )
      v8 = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[HIDWORD(streamInfo->mhBufferPerm) & 0x1F]->mBlockLookup.mTree, v7);
    else
      v8 = 0i64;
    UFG::StreamFileWrapper::Read(
      streamInfo->mhFilePerm,
      (UFG::StreamFileWrapper::QUEUE_CLASS)(3 - (v3 != 0)),
      v8[1].mRoot.mParent,
      &streamInfo->mFileSizePerm,
      0i64,
      QSEEK_SET,
      UFG::DataStreamer::fnDataStreamCallback,
      streamInfo,
      0);
  }
  if ( streamInfo->mStateCurrent == STATE_LOAD_QUEUED )
  {
    mPrev = streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev;
    mNext = streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mPrev = &streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
    streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>::mNext = &streamInfo->UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority>;
  }
  v11 = (*((_BYTE *)streamInfo + 80) & 4) == 0;
  streamInfo->mTimeInState = 0.0;
  streamInfo->mStateCurrent = STATE_LOADING;
  if ( !v11 && !streamInfo->mFileSizeTemp.uncompressed_size )
    UFG::DataStreamer::fnDataStreamCallback(0i64, streamInfo);
  return 1;
}

// File Line: 2001
// RVA: 0x22EFC0
bool __fastcall UFG::DataStreamer::fnPrioritySort(UFG::DataStreamer::StreamInfo *a, UFG::DataStreamer::StreamInfo *b)
{
  int v2; // r8d
  int v3; // ecx

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
  unsigned int ZeroRefResourceFileUserData; // eax
  UFG::qResourceFileInventory *v2; // rdi
  __int64 v3; // rsi
  UFG::qResourceInventoryVtbl *vfptr; // rbx
  unsigned int ResourceFileUID; // eax
  UFG::StreamPool **v6; // rbx
  __int64 v7; // rdi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v8; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *v9; // r14
  __int64 v10; // rdi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *mNext; // rdx
  UFG::qBaseTreeRB *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  UFG::StreamPool *v14; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *mPrev; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v16; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v17; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v18; // rsi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v19; // rdi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v20; // r11
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v21; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v22; // r9
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v23; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v24; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v25; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v26; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v27; // rax
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v28; // r11
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v29; // r10
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v30; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v31; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v32; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v33; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v34; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v35; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v36; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *p_mNode; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v38; // rsi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v39; // rdi
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v40; // r11
  int v41; // edx
  int v42; // ecx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v43; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v44; // r9
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v45; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v46; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v47; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v48; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v49; // rax
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v50; // r11
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v51; // r10
  int v52; // edx
  int v53; // ecx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v54; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v55; // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v56; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v57; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v58; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v59; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v60; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v61; // rbx
  UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *v62; // rdi
  int v63; // eax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v64; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v65; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v66; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v67; // rax
  char v68; // bp
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v69; // rbx
  __int64 v70; // rsi
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v71; // rdx
  UFG::qBaseTreeRB *v72; // rax
  UFG::allocator::free_link *v73; // rdx
  UFG::StreamPool *v74; // rcx
  UFG::DataStreamer::Handle *v75; // rax
  void (__fastcall *v76)(UFG::DataStreamer::Handle *, void *); // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v77; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v78; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *v79; // rax
  int v80; // ecx
  int v81; // ecx
  int v82; // ecx
  int v83; // ecx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v84; // rdx
  UFG::qBaseTreeRB *v85; // rax
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v86; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v87; // rax
  UFG::DataStreamer::Handle *v88; // rax
  void (__fastcall *mCallback)(UFG::DataStreamer::Handle *, void *); // r8
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v90; // rdx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v91; // rax
  UFG::allocator::free_link *v92; // rdx
  UFG::StreamPool *v93; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v94; // rcx
  UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *v95; // rax
  UFG::qString v96; // [rsp+28h] [rbp-390h] BYREF
  void *user_datas[100]; // [rsp+50h] [rbp-368h] BYREF
  unsigned int CPURAMRestoredSizeBytes; // [rsp+3C8h] [rbp+10h] BYREF
  unsigned int VRAMRestoredSizeBytes; // [rsp+3D0h] [rbp+18h] BYREF

  if ( UFG::DataStreamer::gAllowStreaming )
  {
    ZeroRefResourceFileUserData = UFG::qChunkFileSystem::GetZeroRefResourceFileUserData(user_datas, 0x64u);
    if ( ZeroRefResourceFileUserData )
    {
      v2 = (UFG::qResourceFileInventory *)user_datas;
      v3 = ZeroRefResourceFileUserData;
      do
      {
        vfptr = v2->vfptr;
        if ( (BYTE1(v2->vfptr->Remove) & 1) != 0 && LODWORD(vfptr->IsEmpty) == 6 && vfptr[1].InitHandle )
        {
          UFG::qString::qString(&v96, (UFG::qString *)&vfptr[1].OnDetachHandle);
          UFG::qString::ReplaceString(&v96, "perm.bin", "temp.bin", 1);
          ResourceFileUID = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, v96.mData);
          UFG::qChunkFileSystem::RemoveExternalResourceFileReference(
            ResourceFileUID,
            (UFG::qVRAMemoryHandle *)&vfptr->Validate);
          if ( vfptr[1].InitHandle )
            UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&vfptr->Validate, 0);
          UFG::qString::~qString(&v96);
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
        v10 = (__int64)&v8[2].mNext[-2];
        if ( HIDWORD(v8[4].mPrev) == 1 && LODWORD(v8[4].mPrev) == 7 && ++WORD1(v8[5].mPrev) >= 2u )
        {
          mNext = v8[6].mNext;
          if ( (_DWORD)mNext )
          {
            v12 = UFG::qBaseTreeRB::Get(
                    &UFG::gStreamPools[((unsigned __int64)v8[6].mNext >> 32) & 0x1F]->mBlockLookup.mTree,
                    (unsigned int)mNext);
            if ( v12 )
              LOWORD(v12->mNULL.mChild[1]) &= ~0x80u;
          }
          v13 = (UFG::allocator::free_link *)v8[6].mNext;
          if ( v13 != (UFG::allocator::free_link *)-1i64 )
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
            mPrev = v8[3].mPrev;
            v16 = v8[3].mNext;
            mPrev->mNext = v16;
            v16->mPrev = mPrev;
            v8[3].mPrev = v8 + 3;
            v8[3].mNext = v8 + 3;
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
      if ( UFG::DataStreamer::mDiskPosSortMode == SORT_BY_PRIORITY_THEN_DISK_POSITION )
      {
        p_mNode = UFG::DataStreamer::mPriorityList.mNode.mNext - 3;
        v38 = &UFG::DataStreamer::mPriorityList - 3;
        do
        {
          v39 = 0i64;
          while ( p_mNode != (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)v38 )
          {
            v40 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&p_mNode[3].mNext[-3];
            if ( v40 == v38 )
              break;
            v41 = p_mNode[14].mNext == &p_mNode[14] ? 0x2000 : WORD1(p_mNode[14].mNext[2].mNext);
            v42 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v40[14].mNode.mNext == &v40[14]
                ? 0x2000
                : WORD1(v40[14].mNode.mNext[2].mNext);
            if ( v41 > v42 || v41 >= v42 && p_mNode[16].mPrev <= v40[16].mNode.mPrev )
            {
              p_mNode = p_mNode[3].mNext - 3;
            }
            else
            {
              v43 = p_mNode[3].mPrev;
              v44 = v40[3].mNode.mNext;
              v45 = p_mNode[3].mNext;
              v43->mNext = v45;
              v45->mPrev = v43;
              p_mNode[3].mPrev = p_mNode + 3;
              p_mNode[3].mNext = p_mNode + 3;
              v46 = v40[3].mNode.mPrev;
              v47 = v40[3].mNode.mNext;
              v46->mNext = v47;
              v47->mPrev = v46;
              v40[3].mNode.mPrev = &v40[3].mNode;
              v40[3].mNode.mNext = &v40[3].mNode;
              v48 = v43->mNext;
              v43->mNext = &v40[3].mNode;
              v40[3].mNode.mPrev = v43;
              v40[3].mNode.mNext = v48;
              v48->mPrev = &v40[3].mNode;
              v49 = v44->mPrev;
              v49->mNext = p_mNode + 3;
              p_mNode[3].mPrev = v49;
              p_mNode[3].mNext = v44;
              v44->mPrev = p_mNode + 3;
              v39 = v40;
            }
          }
          p_mNode = 0i64;
          if ( !v39 || v39 == v38 )
            break;
          do
          {
            v50 = v39 + 3;
            v51 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v39[3].mNode.mPrev[-3];
            if ( v51 == v38 )
              break;
            v52 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v51[14].mNode.mNext == &v51[14]
                ? 0x2000
                : WORD1(v51[14].mNode.mNext[2].mNext);
            v53 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)v39[14].mNode.mNext == &v39[14]
                ? 0x2000
                : WORD1(v39[14].mNode.mNext[2].mNext);
            if ( v52 > v53 || v52 >= v53 && v51[16].mNode.mPrev <= v39[16].mNode.mPrev )
            {
              v39 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v39[3].mNode.mPrev[-3];
            }
            else
            {
              v54 = v39[3].mNode.mPrev->mPrev;
              v55 = v39[3].mNode.mNext;
              v56 = v51[3].mNode.mNext;
              v54->mNext = v56;
              v56->mPrev = v54;
              v51[3].mNode.mPrev = &v51[3].mNode;
              v51[3].mNode.mNext = &v51[3].mNode;
              v57 = v50->mNode.mPrev;
              v58 = v39[3].mNode.mNext;
              v57->mNext = v58;
              v58->mPrev = v57;
              v50->mNode.mPrev = &v50->mNode;
              v39[3].mNode.mNext = &v39[3].mNode;
              v59 = v54->mNext;
              v54->mNext = &v50->mNode;
              v50->mNode.mPrev = v54;
              v39[3].mNode.mNext = v59;
              v59->mPrev = &v50->mNode;
              v60 = v55->mPrev;
              v60->mNext = &v51[3].mNode;
              v51[3].mNode.mPrev = v60;
              v51[3].mNode.mNext = v55;
              v55->mPrev = &v51[3].mNode;
              p_mNode = &v51->mNode;
            }
          }
          while ( v39 != v38 );
        }
        while ( p_mNode );
      }
      else if ( UFG::DataStreamer::mDiskPosSortMode == SORT_BY_DISK_POSITION )
      {
        v17 = UFG::DataStreamer::mPriorityList.mNode.mNext - 3;
        v18 = &UFG::DataStreamer::mPriorityList - 3;
        do
        {
          v19 = 0i64;
          while ( v17 != (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)v18 )
          {
            v20 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v17[3].mNext[-3];
            if ( v20 == v18 )
              break;
            if ( v17[16].mPrev <= v20[16].mNode.mPrev )
            {
              v17 = v17[3].mNext - 3;
            }
            else
            {
              v21 = v17[3].mPrev;
              v22 = v20[3].mNode.mNext;
              v23 = v17[3].mNext;
              v21->mNext = v23;
              v23->mPrev = v21;
              v17[3].mPrev = v17 + 3;
              v17[3].mNext = v17 + 3;
              v24 = v20[3].mNode.mPrev;
              v25 = v20[3].mNode.mNext;
              v24->mNext = v25;
              v25->mPrev = v24;
              v20[3].mNode.mPrev = &v20[3].mNode;
              v20[3].mNode.mNext = &v20[3].mNode;
              v26 = v21->mNext;
              v21->mNext = &v20[3].mNode;
              v20[3].mNode.mPrev = v21;
              v20[3].mNode.mNext = v26;
              v26->mPrev = &v20[3].mNode;
              v27 = v22->mPrev;
              v27->mNext = v17 + 3;
              v17[3].mPrev = v27;
              v17[3].mNext = v22;
              v22->mPrev = v17 + 3;
              v19 = v20;
            }
          }
          v17 = 0i64;
          if ( !v19 || v19 == v18 )
            break;
          do
          {
            v28 = v19 + 3;
            v29 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v19[3].mNode.mPrev[-3];
            if ( v29 == v18 )
              break;
            if ( v29[16].mNode.mPrev <= v19[16].mNode.mPrev )
            {
              v19 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v19[3].mNode.mPrev[-3];
            }
            else
            {
              v30 = v19[3].mNode.mPrev->mPrev;
              v31 = v19[3].mNode.mNext;
              v32 = v29[3].mNode.mNext;
              v30->mNext = v32;
              v32->mPrev = v30;
              v29[3].mNode.mPrev = &v29[3].mNode;
              v29[3].mNode.mNext = &v29[3].mNode;
              v33 = v28->mNode.mPrev;
              v34 = v19[3].mNode.mNext;
              v33->mNext = v34;
              v34->mPrev = v33;
              v28->mNode.mPrev = &v28->mNode;
              v19[3].mNode.mNext = &v19[3].mNode;
              v35 = v30->mNext;
              v30->mNext = &v28->mNode;
              v28->mNode.mPrev = v30;
              v19[3].mNode.mNext = v35;
              v35->mPrev = &v28->mNode;
              v36 = v31->mPrev;
              v36->mNext = &v29[3].mNode;
              v29[3].mNode.mPrev = v36;
              v29[3].mNode.mNext = v31;
              v31->mPrev = &v29[3].mNode;
              v17 = &v29->mNode;
            }
          }
          while ( v19 != v18 );
        }
        while ( v17 );
      }
    }
    else
    {
      UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0>::MergeSort(
        &UFG::DataStreamer::mPriorityList,
        UFG::DataStreamer::fnPrioritySort);
    }
    v61 = UFG::DataStreamer::mPriorityList.mNode.mNext - 3;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&UFG::DataStreamer::mPriorityList.mNode.mNext[-3] != &UFG::DataStreamer::mPriorityList - 3 )
    {
      while ( 1 )
      {
        v62 = (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority,1,0> *)&v61[3].mNext[-3];
        if ( HIDWORD(v61[4].mPrev) == 1 )
          break;
        if ( HIDWORD(v61[4].mPrev) == 6 && UFG::DataStreamer::mFileOperationCount < 4 )
        {
          CPURAMRestoredSizeBytes = 0;
          v63 = UFG::DataStreamer::OpenFiles(
                  (UFG::DataStreamer::StreamInfo *)v61,
                  &CPURAMRestoredSizeBytes,
                  &VRAMRestoredSizeBytes);
          if ( !v63 )
          {
            if ( CPURAMRestoredSizeBytes && !HIDWORD(v61[8].mPrev) )
            {
              ++UFG::DataStreamer::mFileOperationCount;
              UFG::DataStreamer::OnStreamLoadComplete((UFG::DataStreamer::StreamInfo *)v61);
            }
            else
            {
              ++UFG::DataStreamer::mFileOperationCount;
              UFG::DataStreamer::BeginLoading((UFG::DataStreamer::StreamInfo *)v61);
            }
            goto LABEL_102;
          }
          if ( v63 == 1 )
          {
            if ( LODWORD(v61[4].mPrev) == 2 )
            {
              v64 = v61[3].mPrev;
              v65 = v61[3].mNext;
              v64->mNext = v65;
              v65->mPrev = v64;
              v61[3].mPrev = v61 + 3;
              v61[3].mNext = v61 + 3;
            }
            LODWORD(v61[4].mPrev) = 0;
LABEL_101:
            HIDWORD(v61[4].mNext) = 0;
          }
        }
LABEL_102:
        v61 = &v62->mNode;
        if ( v62 == &UFG::DataStreamer::mPriorityList - 3 )
          goto LABEL_103;
      }
      if ( LODWORD(v61[4].mPrev) == 2 )
      {
        v66 = v61[3].mPrev;
        v67 = v61[3].mNext;
        v66->mNext = v67;
        v67->mPrev = v66;
        v61[3].mPrev = v61 + 3;
        v61[3].mNext = v61 + 3;
      }
      LODWORD(v61[4].mPrev) = 1;
      goto LABEL_101;
    }
LABEL_103:
    v68 = 0;
    v69 = UFG::DataStreamer::mOrderList.mNode.mNext - 2;
    if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)&UFG::DataStreamer::mOrderList.mNode.mNext[-2] != v9 )
    {
      while ( 1 )
      {
        v70 = (__int64)&v69[2].mNext[-2];
        if ( HIDWORD(v69[4].mPrev) != 1 )
          break;
        v80 = (int)v69[4].mPrev;
        if ( !v80 )
        {
          if ( v69[9].mNext )
            UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&v69[8].mNext, 0);
          v92 = (UFG::allocator::free_link *)v69[6].mNext;
          if ( v92 != (UFG::allocator::free_link *)-1i64 )
          {
            v93 = UFG::gStreamPools[BYTE4(v92) & 0x1F];
            if ( v93 )
              UFG::StreamPool::Free(v93, v92);
            v69[6].mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)-1i64;
          }
          goto LABEL_161;
        }
        v81 = v80 - 1;
        if ( v81 )
        {
          v82 = v81 - 3;
          if ( v82 )
          {
            v83 = v82 - 1;
            if ( v83 )
            {
              if ( v83 == 1 )
              {
                if ( (HIDWORD(v69[15].mPrev) & 0x80) == 0 )
                  goto LABEL_139;
                if ( !v68 || UFG::DataStreamer::gDisableSpreadedUnloadTick )
                {
                  v68 = 1;
LABEL_139:
                  if ( UFG::DataStreamer::UnloadStreamResources((UFG::DataStreamer::StreamInfo *)v69) )
                  {
                    WORD1(v69[5].mPrev) = 0;
                    v84 = v69[6].mNext;
                    if ( (_DWORD)v84 )
                    {
                      v85 = UFG::qBaseTreeRB::Get(
                              &UFG::gStreamPools[((unsigned __int64)v69[6].mNext >> 32) & 0x1F]->mBlockLookup.mTree,
                              (unsigned int)v84);
                      if ( v85 )
                        LOWORD(v85->mNULL.mChild[1]) |= 0x80u;
                    }
                    if ( v69[9].mNext )
                      UFG::qVRAMemoryHandle::Lock((UFG::qVRAMemoryHandle *)&v69[8].mNext);
                    if ( LODWORD(v69[4].mPrev) == 2 )
                    {
                      v86 = v69[3].mPrev;
                      v87 = v69[3].mNext;
                      v86->mNext = v87;
                      v87->mPrev = v86;
                      v69[3].mPrev = v69 + 3;
                      v69[3].mNext = v69 + 3;
                    }
                    LODWORD(v69[4].mPrev) = 7;
LABEL_164:
                    HIDWORD(v69[4].mNext) = 0;
                  }
                }
              }
LABEL_165:
              ++UFG::DataStreamer::mStateCountThis[SLODWORD(v69[4].mPrev)];
              *((float *)&v69[4].mNext + 1) = dT + *((float *)&v69[4].mNext + 1);
              goto LABEL_166;
            }
            UFG::DataStreamer::FinishLoadingResources((UFG::DataStreamer::StreamInfo *)v69);
            v88 = (UFG::DataStreamer::Handle *)v69[14].mNext;
            for ( UFG::DataStreamer::gCurrentStreamHandle = v88;
                  v88 != (UFG::DataStreamer::Handle *)&v69[14];
                  UFG::DataStreamer::gCurrentStreamHandle = v88 )
            {
              mCallback = v88->mCallback;
              if ( mCallback )
              {
                mCallback(v88, v88->mCallbackParam);
                v88 = UFG::DataStreamer::gCurrentStreamHandle;
              }
              v88 = (UFG::DataStreamer::Handle *)v88->mNext;
            }
LABEL_125:
            UFG::DataStreamer::gCurrentStreamHandle = 0i64;
            if ( LODWORD(v69[4].mPrev) == 2 )
            {
              v77 = v69[3].mPrev;
              v78 = v69[3].mNext;
              v77->mNext = v78;
              v78->mPrev = v77;
              v69[3].mPrev = v69 + 3;
              v69[3].mNext = v69 + 3;
            }
            LODWORD(v69[4].mPrev) = 6;
            goto LABEL_164;
          }
LABEL_128:
          LODWORD(v69[4].mPrev) = 5;
          goto LABEL_164;
        }
        if ( v69[14].mNext != &v69[14] )
          goto LABEL_165;
        v90 = v69[2].mPrev;
        v91 = v69[2].mNext;
        v90->mNext = v91;
        v91->mPrev = v90;
        v69[2].mPrev = v69 + 2;
        v69[2].mNext = v69 + 2;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::DataStreamer::mStreamInfo,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v69);
        UFG::DataStreamer::StreamInfo::~StreamInfo((UFG::DataStreamer::StreamInfo *)v69);
        operator delete[](v69);
LABEL_166:
        v69 = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)v70;
        if ( (UFG::qList<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder,1,0> *)v70 == v9 )
          goto LABEL_167;
      }
      if ( HIDWORD(v69[4].mPrev) != 6 )
        goto LABEL_165;
      switch ( LODWORD(v69[4].mPrev) )
      {
        case 1:
          LODWORD(v69[4].mPrev) = 2;
          HIDWORD(v69[4].mNext) = 0;
          v79 = UFG::DataStreamer::mPriorityList.mNode.mPrev;
          UFG::DataStreamer::mPriorityList.mNode.mPrev->mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v69[3];
          v69[3].mPrev = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)v79;
          v69[3].mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)&UFG::DataStreamer::mPriorityList;
          UFG::DataStreamer::mPriorityList.mNode.mPrev = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::Priority> *)&v69[3];
          goto LABEL_165;
        case 4:
          goto LABEL_128;
        case 5:
          UFG::DataStreamer::FinishLoadingResources((UFG::DataStreamer::StreamInfo *)v69);
          v75 = (UFG::DataStreamer::Handle *)v69[14].mNext;
          for ( UFG::DataStreamer::gCurrentStreamHandle = v75;
                v75 != (UFG::DataStreamer::Handle *)&v69[14];
                UFG::DataStreamer::gCurrentStreamHandle = v75 )
          {
            v76 = v75->mCallback;
            if ( v76 )
            {
              v76(v75, v75->mCallbackParam);
              v75 = UFG::DataStreamer::gCurrentStreamHandle;
            }
            v75 = (UFG::DataStreamer::Handle *)v75->mNext;
          }
          goto LABEL_125;
      }
      if ( LODWORD(v69[4].mPrev) != 7 )
        goto LABEL_165;
      if ( ++WORD1(v69[5].mPrev) < 2u )
        goto LABEL_165;
      v71 = v69[6].mNext;
      if ( (_DWORD)v71 )
      {
        v72 = UFG::qBaseTreeRB::Get(
                &UFG::gStreamPools[((unsigned __int64)v69[6].mNext >> 32) & 0x1F]->mBlockLookup.mTree,
                (unsigned int)v71);
        if ( v72 )
          LOWORD(v72->mNULL.mChild[1]) &= ~0x80u;
      }
      v73 = (UFG::allocator::free_link *)v69[6].mNext;
      if ( v73 != (UFG::allocator::free_link *)-1i64 )
      {
        v74 = UFG::gStreamPools[BYTE4(v73) & 0x1F];
        if ( v74 )
          UFG::StreamPool::Free(v74, v73);
        v69[6].mNext = (UFG::qNode<UFG::DataStreamer::StreamInfo,UFG::DataStreamer::StreamOrder> *)-1i64;
      }
      if ( v69[9].mNext )
      {
        UFG::qVRAMemoryHandle::Unlock((UFG::qVRAMemoryHandle *)&v69[8].mNext);
        if ( v69[9].mNext )
          UFG::qVRAMemoryPools::Free((UFG::qVRAMemoryHandle *)&v69[8].mNext, 0);
      }
LABEL_161:
      if ( LODWORD(v69[4].mPrev) == 2 )
      {
        v94 = v69[3].mPrev;
        v95 = v69[3].mNext;
        v94->mNext = v95;
        v95->mPrev = v94;
        v69[3].mPrev = v69 + 3;
        v69[3].mNext = v69 + 3;
      }
      LODWORD(v69[4].mPrev) = 1;
      goto LABEL_164;
    }
LABEL_167:
    UFG::StreamFileWrapper::Service(dT);
    if ( UFG::DataStreamer::gDisableSpreadedUnloadTick > 0 )
      --UFG::DataStreamer::gDisableSpreadedUnloadTick;
  }
}bleSpreadedUnloadTick > 0 )
      --UFG::DataStreamer::gDisableSpreadedUnloadTick;
  }
}

// File Line: 2410
// RVA: 0x229CD0
signed __int64 __fastcall UFG::DataStreamer::GetStreamState(UFG::DataStreamer::Handle *handle)
{
  unsigned int *mImpl; // rax

  mImpl = (unsigned int *)handle->mImpl;
  if ( mImpl )
    return mImpl[16];
  else
    return 1i64;
}

// File Line: 2436
// RVA: 0x229660
char __fastcall UFG::DataStreamer::GetBufferFromUID(
        unsigned int uid,
        UFG::qBaseNodeRB **buffer_ptr,
        unsigned int *buffer_size)
{
  UFG::DataStreamer::StreamInfo *v5; // rax
  UFG::DataStreamer::StreamInfo *v6; // rbx
  unsigned __int64 mhBufferPerm; // rax

  if ( !uid )
    return 0;
  v5 = (UFG::DataStreamer::StreamInfo *)UFG::qBaseTreeRB::Get(&UFG::DataStreamer::mStreamInfo.mTree, uid);
  v6 = v5;
  if ( !v5 )
    return 0;
  mhBufferPerm = v5->mhBufferPerm;
  if ( (_DWORD)mhBufferPerm )
    *buffer_ptr = UFG::qBaseTreeRB::Get(&UFG::gStreamPools[BYTE4(mhBufferPerm) & 31]->mBlockLookup.mTree, mhBufferPerm)[1].mRoot.mParent;
  else
    *buffer_ptr = (UFG::qBaseNodeRB *)MEMORY[0x48];
  *buffer_size = v6->mFileSizePerm.uncompressed_size;
  return 1;
}

// File Line: 2696
// RVA: 0x229CB0
__int64 __fastcall UFG::DataStreamer::GetReadBytes(UFG::DataStreamer::Handle *handle)
{
  _DWORD *mImpl; // rdx

  mImpl = handle->mImpl;
  if ( mImpl )
    return (unsigned int)(mImpl[23] + mImpl[24] + mImpl[32] + mImpl[33]);
  else
    return 0i64;
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

