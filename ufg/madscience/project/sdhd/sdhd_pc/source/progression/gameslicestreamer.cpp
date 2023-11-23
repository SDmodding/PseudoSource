// File Line: 21
// RVA: 0x48AD00
void __fastcall UFG::GameSliceStreamer::GameSliceStreamer(UFG::GameSliceStreamer *this)
{
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v2; // rdi
  __int64 v3; // rax
  bool v4; // cf
  unsigned __int64 v5; // rax
  UFG::allocator::free_link *v6; // rax

  this->mStreamRequests.mNode.mPrev = &this->mStreamRequests.mNode;
  this->mStreamRequests.mNode.mNext = &this->mStreamRequests.mNode;
  v2 = 0i64;
  this->mStreamData.size = 0;
  this->mDeferScriptDeletionRequests.mCapacity = 128;
  this->mDeferScriptDeletionRequests.mpMemoryPool = 0i64;
  v3 = 3072i64;
  if ( !is_mul_ok(0x80ui64, 0x18ui64) )
    v3 = -1i64;
  v4 = __CFADD__(v3, 8i64);
  v5 = v3 + 8;
  if ( v4 )
    v5 = -1i64;
  v6 = UFG::qMalloc(v5, "qCircularArray::mData", 0i64);
  if ( v6 )
  {
    LODWORD(v6->mNext) = 128;
    v2 = (UFG::GameSliceStreamer::DeferScriptDeletionRequest *)&v6[1];
    `eh vector constructor iterator(
      &v6[1],
      0x18ui64,
      128,
      (void (__fastcall *)(void *))UFG::GameSliceStreamer::DeferScriptDeletionRequest::DeferScriptDeletionRequest);
  }
  this->mDeferScriptDeletionRequests.mData = v2;
  *(_QWORD *)&this->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
  UFG::GameSliceStreamer::mspInstance = this;
}

// File Line: 26
// RVA: 0x490530
void __fastcall UFG::GameSliceStreamer::~GameSliceStreamer(UFG::GameSliceStreamer *this)
{
  UFG::qMemoryPool *mpMemoryPool; // rcx
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *mData; // rcx
  UFG::SSGameSlice **p_m_pPointer; // rbx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mPrev; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mNext; // rax

  UFG::GameSliceStreamer::mspInstance = 0i64;
  mpMemoryPool = this->mDeferScriptDeletionRequests.mpMemoryPool;
  if ( mpMemoryPool )
  {
    UFG::qMemoryPool::Free(mpMemoryPool, (char *)this->mDeferScriptDeletionRequests.mData);
  }
  else
  {
    mData = this->mDeferScriptDeletionRequests.mData;
    if ( mData )
    {
      p_m_pPointer = &mData[-1].mScript.m_pPointer;
      `eh vector destructor iterator(
        mData,
        0x18ui64,
        (int)mData[-1].mScript.m_pPointer,
        (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
      operator delete[](p_m_pPointer);
    }
  }
  this->mStreamData.size = 0;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this);
  mPrev = this->mStreamRequests.mNode.mPrev;
  mNext = this->mStreamRequests.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mStreamRequests.mNode.mPrev = &this->mStreamRequests.mNode;
  this->mStreamRequests.mNode.mNext = &this->mStreamRequests.mNode;
}

// File Line: 31
// RVA: 0x4AB680
UFG::GameSliceStreamer *__fastcall UFG::GameSliceStreamer::Instance()
{
  return UFG::GameSliceStreamer::mspInstance;
}

// File Line: 36
// RVA: 0x497700
void __fastcall UFG::GameSliceStreamer::Clear(UFG::GameSliceStreamer *this)
{
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mNext; // rdi
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mPrev; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v4; // rax
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v5; // rdx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v6; // rax
  __int64 mHeadIndex; // rdx
  unsigned int mTailIndex; // r8d
  int v9; // ecx
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v11; // r9
  int v12; // r8d
  UFG::SSGameSlice *m_pPointer; // rcx
  __int64 size; // rsi
  UFG::GameSliceStreamer::StreamData *p; // rdi

  while ( (UFG::GameSliceStreamer *)this->mStreamRequests.mNode.mNext != this )
  {
    mNext = this->mStreamRequests.mNode.mNext;
    mPrev = mNext->mPrev;
    v4 = mNext->mNext;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::GameSliceStreamer::CancelStream(this, (UFG::GameSlice *)mNext[1].mPrev);
    v5 = mNext->mPrev;
    v6 = mNext->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
  }
  while ( 1 )
  {
    mHeadIndex = this->mDeferScriptDeletionRequests.mHeadIndex;
    if ( (_DWORD)mHeadIndex == -1 )
      break;
    mTailIndex = this->mDeferScriptDeletionRequests.mTailIndex;
    v9 = mTailIndex - mHeadIndex;
    if ( !((unsigned int)mHeadIndex <= mTailIndex ? v9 + 1 : v9 + this->mDeferScriptDeletionRequests.mCapacity + 1) )
      break;
    v11 = 0i64;
    if ( (unsigned int)mHeadIndex <= mTailIndex )
      v12 = v9 + 1;
    else
      v12 = v9 + this->mDeferScriptDeletionRequests.mCapacity + 1;
    if ( v12 > 0 )
    {
      v11 = &this->mDeferScriptDeletionRequests.mData[mHeadIndex];
      this->mDeferScriptDeletionRequests.mHeadIndex = (unsigned int)(mHeadIndex + 1)
                                                    % this->mDeferScriptDeletionRequests.mCapacity;
      if ( v12 == 1 )
        *(_QWORD *)&this->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
    }
    m_pPointer = v11->mScript.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->i_ref_count-- == 1 )
      {
        m_pPointer->i_ref_count = 0x80000000;
        m_pPointer->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr[1].get_scope_context(&m_pPointer->SSActor);
      }
    }
  }
  size = this->mStreamData.size;
  if ( this->mStreamData.size )
  {
    p = this->mStreamData.p;
    do
    {
      if ( (p->mpRoot->i_flags & 1) != 0 )
      {
        ((void (__fastcall *)(SSClass *))p->mpRoot->vfptr[1].find_common_type)(p->mpRoot);
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&p->mpRoot->ANamed);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_GameSliceStreamer,
          OUTPUT_LEVEL_DEBUG,
          "[GameSliceStreamer]: ########## Unloading game slice group: %s\n");
      }
      ++p;
      --size;
    }
    while ( size );
  }
  this->mStreamData.size = 0;
}

// File Line: 72
// RVA: 0x4B15B0
void __fastcall UFG::GameSliceStreamer::OnAsyncRead(
        const char *filename,
        char *data,
        int fileSize,
        UFG::qSymbolUC *pCallbackParam)
{
  __int64 v6; // rcx
  UFG::GameSliceStreamer::StreamData *p; // rax

  if ( fileSize && data )
  {
    UFG::qSymbol::as_cstr_dbg(pCallbackParam + 2);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: OnAsyncRead called for (%s) (%s)\n");
    v6 = 0i64;
    if ( UFG::GameSliceStreamer::mspInstance->mStreamData.size )
    {
      p = UFG::GameSliceStreamer::mspInstance->mStreamData.p;
      while ( (UFG::qSymbolUC *)p->mpRoot != pCallbackParam )
      {
        ++v6;
        ++p;
        if ( v6 >= UFG::GameSliceStreamer::mspInstance->mStreamData.size )
          goto LABEL_12;
      }
      if ( (pCallbackParam[3].mUID & 1) != 0 )
      {
        pCallbackParam[3].mUID &= ~8u;
        pCallbackParam[3].mUID |= 1u;
      }
      else if ( !p->mpBuffer )
      {
        p->mpBuffer = data;
        return;
      }
    }
LABEL_12:
    UFG::qFreeEntireFile(data, 0i64);
  }
}

// File Line: 94
// RVA: 0x4B66D0
void __fastcall UFG::GameSliceStreamer::RequestStream(
        UFG::GameSliceStreamer *this,
        UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *pGameSlice)
{
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mNext; // rax
  SSClass *v5; // rax
  UFG::allocator::free_link *demand_loaded_root; // rsi
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v8; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mPrev; // rax

  mNext = this->mStreamRequests.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
  {
LABEL_6:
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: RequestStream (%s) - Queuing!\n");
    v5 = SSBrain::get_class((const char *)pGameSlice[3].mPrev);
    demand_loaded_root = (UFG::allocator::free_link *)SSClass::get_demand_loaded_root(v5);
    v7 = UFG::qMalloc(0x20ui64, "GameSliceStreamer::StreamRequest", 0i64);
    v8 = (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)v7;
    if ( v7 )
    {
      v7->mNext = v7;
      v7[1].mNext = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v8[1].mPrev = pGameSlice;
    v8[1].mNext = (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)demand_loaded_root;
    mPrev = this->mStreamRequests.mNode.mPrev;
    mPrev->mNext = v8;
    v8->mPrev = mPrev;
    v8->mNext = &this->mStreamRequests.mNode;
    this->mStreamRequests.mNode.mPrev = v8;
    if ( demand_loaded_root )
      UFG::GameSliceStreamer::RequestStream(this, (UFG::GameSlice *)pGameSlice, demand_loaded_root);
  }
  else
  {
    while ( mNext[1].mPrev != pGameSlice )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
        goto LABEL_6;
    }
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: RequestStream (%s) - Request already present, ignored!\n");
  }
}

// File Line: 127
// RVA: 0x49A360
void __fastcall UFG::GameSliceStreamer::DeferScriptDelete(UFG::GameSliceStreamer *this, UFG::SSGameSlice *pScript)
{
  __int64 mHeadIndex; // rdx
  int v5; // ecx
  unsigned int mTailIndex; // ecx
  int mCapacity; // eax
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v8; // rcx
  unsigned int v9; // r8d
  int v10; // r8d
  UFG::SSGameSlice *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *mPrev; // rax
  unsigned int v14; // eax
  int v15; // ecx
  unsigned int v16; // ecx
  int v17; // r8d
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *v21; // rax
  __int64 *v22; // rcx
  _QWORD *p_mPrev; // rax
  __int64 *v24; // rcx
  _QWORD *v25; // rax
  __int64 *v26; // [rsp+28h] [rbp-18h] BYREF
  UFG::qList<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // [rsp+30h] [rbp-10h]
  UFG::SSGameSlice *v28; // [rsp+38h] [rbp-8h]

  mHeadIndex = this->mDeferScriptDeletionRequests.mHeadIndex;
  if ( (_DWORD)mHeadIndex == -1 )
  {
    v5 = 0;
  }
  else
  {
    mTailIndex = this->mDeferScriptDeletionRequests.mTailIndex;
    if ( (unsigned int)mHeadIndex <= mTailIndex )
      v5 = mTailIndex - mHeadIndex + 1;
    else
      v5 = this->mDeferScriptDeletionRequests.mCapacity - mHeadIndex + mTailIndex + 1;
  }
  mCapacity = this->mDeferScriptDeletionRequests.mCapacity;
  if ( v5 == mCapacity )
  {
    v8 = 0i64;
    if ( (_DWORD)mHeadIndex != -1 )
    {
      v9 = this->mDeferScriptDeletionRequests.mTailIndex;
      v10 = (unsigned int)mHeadIndex <= v9 ? v9 - mHeadIndex + 1 : mCapacity + v9 - (unsigned int)mHeadIndex + 1;
      if ( v10 > 0 )
      {
        v8 = &this->mDeferScriptDeletionRequests.mData[mHeadIndex];
        this->mDeferScriptDeletionRequests.mHeadIndex = (unsigned int)(mHeadIndex + 1)
                                                      % this->mDeferScriptDeletionRequests.mCapacity;
        if ( v10 == 1 )
          *(_QWORD *)&this->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
      }
    }
    m_pPointer = v8->mScript.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->i_ref_count-- == 1 )
      {
        m_pPointer->i_ref_count = 0x80000000;
        m_pPointer->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr[1].get_scope_context(&m_pPointer->SSActor);
      }
    }
  }
  v26 = (__int64 *)&v26;
  p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList,1,0> *)&v26;
  v28 = pScript;
  if ( pScript )
  {
    mPrev = pScript->m_SafePointerList.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v26;
    v26 = (__int64 *)mPrev;
    p_m_SafePointerList = &pScript->m_SafePointerList;
    pScript->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v26;
    pScript = v28;
  }
  v14 = this->mDeferScriptDeletionRequests.mHeadIndex;
  if ( v14 == -1 )
  {
    v15 = 0;
  }
  else
  {
    v16 = this->mDeferScriptDeletionRequests.mTailIndex;
    if ( v14 <= v16 )
      v15 = v16 - v14 + 1;
    else
      v15 = this->mDeferScriptDeletionRequests.mCapacity + 1 + v16 - v14;
  }
  v17 = this->mDeferScriptDeletionRequests.mCapacity;
  if ( v15 < v17 )
  {
    if ( v15 )
      this->mDeferScriptDeletionRequests.mTailIndex = (this->mDeferScriptDeletionRequests.mTailIndex + 1) % v17;
    else
      *(_QWORD *)&this->mDeferScriptDeletionRequests.mHeadIndex = 0i64;
    v18 = &this->mDeferScriptDeletionRequests.mData[this->mDeferScriptDeletionRequests.mTailIndex];
    if ( v18->mScript.m_pPointer )
    {
      v19 = v18->mScript.mPrev;
      mNext = v18->mScript.mNext;
      v19->mNext = mNext;
      mNext->mPrev = v19;
      v18->mScript.mPrev = &v18->mScript;
      v18->mScript.mNext = &v18->mScript;
    }
    v18->mScript.m_pPointer = pScript;
    if ( pScript )
    {
      v21 = pScript->m_SafePointerList.mNode.mPrev;
      v21->mNext = &v18->mScript;
      v18->mScript.mPrev = v21;
      v18->mScript.mNext = &pScript->m_SafePointerList.mNode;
      pScript->m_SafePointerList.mNode.mPrev = &v18->mScript;
    }
  }
  if ( v28 )
  {
    v22 = v26;
    p_mPrev = &p_m_SafePointerList->mNode.mPrev;
    v26[1] = (__int64)p_m_SafePointerList;
    *p_mPrev = v22;
    v26 = (__int64 *)&v26;
    p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList,1,0> *)&v26;
  }
  v24 = v26;
  v25 = &p_m_SafePointerList->mNode.mPrev;
  v26[1] = (__int64)p_m_SafePointerList;
  *v25 = v24;
}

// File Line: 145
// RVA: 0x4B6530
void __fastcall UFG::GameSliceStreamer::RequestStream(
        UFG::GameSliceStreamer *this,
        UFG::GameSlice *pGameSlice,
        UFG::allocator::free_link *pRoot)
{
  UFG::qFixedArray<UFG::GameSliceStreamer::StreamData,128> *p_mStreamData; // r14
  bool v5; // dl
  __int64 v7; // rax
  UFG::GameSliceStreamer::StreamData *p; // rsi
  __int64 size; // rcx
  char *v10; // rdx
  ANamed *v11; // rcx
  char *v12; // rax
  UFG::StreamFileWrapper::QUEUE_CLASS v13; // edx

  p_mStreamData = &this->mStreamData;
  v5 = pGameSlice->mStreamRequested != 0;
  pGameSlice->mStreamRequested = 1;
  v7 = 0i64;
  if ( this->mStreamData.size )
  {
    p = this->mStreamData.p;
    while ( (UFG::allocator::free_link *)p->mpRoot != pRoot )
    {
      ++v7;
      ++p;
      if ( v7 >= this->mStreamData.size )
        goto LABEL_5;
    }
    v11 = (ANamed *)&pRoot[1];
    if ( v5 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v11);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_GameSliceStreamer,
        OUTPUT_LEVEL_DEBUG,
        "[GameSliceStreamer]: RequestStream (%s)(%0x08d) - pRoot request by (%s) - already requested, ignored\n");
    }
    else
    {
      ++p->mUsageCount;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v11);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_GameSliceStreamer,
        OUTPUT_LEVEL_DEBUG,
        "[GameSliceStreamer]: RequestStream (%s)(%0x08d) - pRoot request by (%s) - now at (%d)\n");
    }
  }
  else
  {
LABEL_5:
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pRoot[1]);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: RequestStream (%s)(%0x08d) - New pRoot request\n");
    size = p_mStreamData->size;
    v10 = (char *)p_mStreamData + 24 * size;
    p_mStreamData->size = size + 1;
    *((_QWORD *)v10 + 1) = pRoot;
    *((_QWORD *)v10 + 2) = 0i64;
    v10[24] = 1;
    if ( (BYTE4(pRoot[1].mNext) & 1) != 0 )
    {
      HIDWORD(pRoot[1].mNext) &= ~8u;
      HIDWORD(pRoot[1].mNext) |= 1u;
    }
    else
    {
      v12 = a_cstr_format("Data\\Scripts\\Class[%x].skoo-bin", LODWORD(pRoot[1].mNext));
      v13 = STREAM_DATA_LOW_PRIORITY;
      if ( (unsigned int)(pGameSlice->mType - 10) <= 1 )
        v13 = STREAM_DATA_HIGH_PRIORITY;
      UFG::StreamFileWrapper::ReadEntireFileAsync(
        v12,
        v13,
        (UFG::allocator::free_link *)UFG::GameSliceStreamer::OnAsyncRead,
        pRoot,
        0i64,
        0,
        "StreamFileWrapper::ReadEntireFileAsync");
    }
  }
}

// File Line: 200
// RVA: 0x496A50
void __fastcall UFG::GameSliceStreamer::CancelStream(UFG::GameSliceStreamer *this, UFG::GameSlice *pGameSlice)
{
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mNext; // rbx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mPrev; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v6; // rax
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v7; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v8; // rax
  SSClass *v9; // rax
  SSClass *demand_loaded_root; // r10
  bool v11; // cl
  __int64 size; // r9
  char *p_mUsageCount; // rax

  mNext = this->mStreamRequests.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
  {
    while ( (UFG::GameSlice *)mNext[1].mPrev != pGameSlice )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
        goto LABEL_6;
    }
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: CancelStream (%s) - Request found, cancelling.\n");
    mPrev = mNext->mPrev;
    v6 = mNext->mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v7 = mNext->mPrev;
    v8 = mNext->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
  }
LABEL_6:
  v9 = SSBrain::get_class(pGameSlice->mScriptClassName.mText);
  demand_loaded_root = SSClass::get_demand_loaded_root(v9);
  if ( demand_loaded_root )
  {
    v11 = pGameSlice->mStreamRequested != 0;
    pGameSlice->mStreamRequested = 0;
    if ( v11 )
    {
      size = this->mStreamData.size;
      if ( this->mStreamData.size )
      {
        p_mUsageCount = &this->mStreamData.p[0].mUsageCount;
        do
        {
          if ( *((SSClass **)p_mUsageCount - 2) == demand_loaded_root && *p_mUsageCount > 0 )
            --*p_mUsageCount;
          p_mUsageCount += 24;
          --size;
        }
        while ( size );
      }
    }
  }
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_GameSliceStreamer,
    OUTPUT_LEVEL_DEBUG,
    "[GameSliceStreamer]: WARNING: CancelStream (%s) - Unable to find request!\n");
}

// File Line: 285
// RVA: 0x4C3FA0
void __fastcall UFG::GameSliceStreamer::Update(UFG::GameSliceStreamer *this)
{
  UFG::GameSliceStreamer *mNext; // rbx
  unsigned int v3; // ebp
  SSClass *mpRoot; // rcx
  __int64 v5; // rax
  UFG::GameSliceStreamer::StreamData *p; // rsi
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *mPrev; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v8; // rax
  __int64 v9; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v10; // rdx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v11; // rax
  __int64 mHeadIndex; // rdx
  unsigned int mTailIndex; // r8d
  int v14; // ecx
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v16; // r9
  int v17; // r8d
  UFG::SSGameSlice *m_pPointer; // rcx
  __int64 v20; // rax
  UFG::qFixedArray<UFG::GameSliceStreamer::StreamData,128> *p_mStreamData; // rbx
  __int64 size; // rcx
  UFG::GameSliceStreamer::StreamData *i; // rdi
  UFG::qSymbolUC *v24; // rcx
  const char *v25; // r8
  __int64 v26; // rdx
  __int64 v27; // rcx
  void *binary_pp; // [rsp+50h] [rbp+8h] BYREF

  mNext = (UFG::GameSliceStreamer *)this->mStreamRequests.mNode.mNext;
  v3 = 0;
  if ( mNext != this )
  {
    mpRoot = mNext->mStreamData.p[0].mpRoot;
    if ( !mpRoot || (mpRoot->i_flags & 1) != 0 )
    {
      mPrev = mNext->mStreamRequests.mNode.mPrev;
      v8 = mNext->mStreamRequests.mNode.mNext;
      mPrev->mNext = v8;
      v8->mPrev = mPrev;
      mNext->mStreamRequests.mNode.mPrev = &mNext->mStreamRequests.mNode;
      mNext->mStreamRequests.mNode.mNext = &mNext->mStreamRequests.mNode;
      v9 = *(_QWORD *)&mNext->mStreamData.size;
      if ( (unsigned int)(*(_DWORD *)(v9 + 264) - 1) <= 6 )
        UFG::GameSlice::StartScript((UFG::GameSlice *)v9);
      binary_pp = mNext;
      v10 = mNext->mStreamRequests.mNode.mPrev;
      v11 = mNext->mStreamRequests.mNode.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      mNext->mStreamRequests.mNode.mPrev = &mNext->mStreamRequests.mNode;
      mNext->mStreamRequests.mNode.mNext = &mNext->mStreamRequests.mNode;
      operator delete[](mNext);
    }
    else
    {
      v5 = 0i64;
      if ( this->mStreamData.size )
      {
        p = this->mStreamData.p;
        while ( p->mpRoot != mpRoot )
        {
          ++v5;
          ++p;
          if ( v5 >= this->mStreamData.size )
            goto LABEL_17;
        }
        if ( p->mpBuffer )
        {
          if ( (p->mpRoot->i_flags & 1) != 0 )
          {
            UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&p->mpRoot->ANamed);
            UFG::qPrintChannel::Print(
              &UFG::gPrintChannel_HK_GameSliceStreamer,
              OUTPUT_LEVEL_WARNING,
              "[GameSliceStreamer]: Binary alread loaded! (%s)(%x)\n");
          }
          else
          {
            binary_pp = p->mpBuffer;
            SSClass::from_binary_group((const void **)&binary_pp);
            SSClass::invoke_class_ctor_recurse(p->mpRoot);
          }
          UFG::qFreeEntireFile((char *)p->mpBuffer, 0i64);
          p->mpBuffer = 0i64;
        }
      }
    }
  }
  do
  {
LABEL_17:
    mHeadIndex = this->mDeferScriptDeletionRequests.mHeadIndex;
    if ( (_DWORD)mHeadIndex == -1 )
      break;
    mTailIndex = this->mDeferScriptDeletionRequests.mTailIndex;
    v14 = mTailIndex - mHeadIndex;
    if ( !((unsigned int)mHeadIndex <= mTailIndex ? v14 + 1 : v14 + this->mDeferScriptDeletionRequests.mCapacity + 1) )
      break;
    v16 = 0i64;
    if ( (unsigned int)mHeadIndex <= mTailIndex )
      v17 = v14 + 1;
    else
      v17 = v14 + this->mDeferScriptDeletionRequests.mCapacity + 1;
    if ( v17 > 0 )
    {
      v16 = &this->mDeferScriptDeletionRequests.mData[mHeadIndex];
      this->mDeferScriptDeletionRequests.mHeadIndex = (unsigned int)(mHeadIndex + 1)
                                                    % this->mDeferScriptDeletionRequests.mCapacity;
      if ( v17 == 1 )
        *(_QWORD *)&this->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
    }
    m_pPointer = v16->mScript.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->i_ref_count-- == 1 )
      {
        m_pPointer->i_ref_count = 0x80000000;
        m_pPointer->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr[1].get_scope_context(&m_pPointer->SSActor);
      }
    }
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( !qword_14240B6D0 )
      break;
  }
  while ( *(int *)(qword_14240B6D0 + 268) >= 6 );
  v20 = 0i64;
  p_mStreamData = &this->mStreamData;
  size = this->mStreamData.size;
  if ( this->mStreamData.size )
  {
    for ( i = this->mStreamData.p; i->mUsageCount; ++i )
    {
      ++v3;
      if ( ++v20 >= size )
        return;
    }
    v24 = (UFG::qSymbolUC *)i->mpRoot;
    if ( (i->mpRoot->i_flags & 1) != 0 )
    {
      (*(void (__fastcall **)(UFG::qSymbolUC *))(*(_QWORD *)&v24->mUID + 248i64))(v24);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i->mpRoot->ANamed);
      v25 = "[GameSliceStreamer]: ########## Unloading game slice group: %s\n";
    }
    else
    {
      UFG::qSymbol::as_cstr_dbg(v24 + 2);
      v25 = "[GameSliceStreamer]: ########## Unloading game slice group: %s.  No need to unload, not yet loaded\n";
    }
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_GameSliceStreamer, OUTPUT_LEVEL_DEBUG, v25);
    v26 = --p_mStreamData->size;
    v27 = v3;
    p_mStreamData->p[v27].mpRoot = p_mStreamData->p[p_mStreamData->size].mpRoot;
    p_mStreamData->p[v27].mpBuffer = p_mStreamData->p[v26].mpBuffer;
    *(_QWORD *)&p_mStreamData->p[v27].mUsageCount = *(_QWORD *)&p_mStreamData->p[v26].mUsageCount;
  }
}

