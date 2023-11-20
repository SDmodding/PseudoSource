// File Line: 21
// RVA: 0x48AD00
void __fastcall UFG::GameSliceStreamer::GameSliceStreamer(UFG::GameSliceStreamer *this)
{
  UFG::GameSliceStreamer *v1; // rbx
  signed __int64 v2; // rdi
  signed __int64 v3; // rax
  unsigned __int8 v4; // cf
  unsigned __int64 v5; // rax
  UFG::allocator::free_link *v6; // rax

  v1 = this;
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
    v2 = (signed __int64)&v6[1];
    `eh vector constructor iterator(
      &v6[1],
      0x18ui64,
      128,
      (void (__fastcall *)(void *))UFG::GameSliceStreamer::DeferScriptDeletionRequest::DeferScriptDeletionRequest);
  }
  v1->mDeferScriptDeletionRequests.mData = (UFG::GameSliceStreamer::DeferScriptDeletionRequest *)v2;
  *(_QWORD *)&v1->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
  UFG::GameSliceStreamer::mspInstance = v1;
}

// File Line: 26
// RVA: 0x490530
void __fastcall UFG::GameSliceStreamer::~GameSliceStreamer(UFG::GameSliceStreamer *this)
{
  UFG::GameSliceStreamer *v1; // rdi
  UFG::qMemoryPool *v2; // rcx
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v3; // rcx
  UFG::SSGameSlice **v4; // rbx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v5; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v6; // rax

  v1 = this;
  UFG::GameSliceStreamer::mspInstance = 0i64;
  v2 = this->mDeferScriptDeletionRequests.mpMemoryPool;
  if ( v2 )
  {
    UFG::qMemoryPool::Free(v2, v1->mDeferScriptDeletionRequests.mData);
  }
  else
  {
    v3 = v1->mDeferScriptDeletionRequests.mData;
    if ( v3 )
    {
      v4 = &v3[-1].mScript.m_pPointer;
      `eh vector destructor iterator(
        v3,
        0x18ui64,
        (int)v3[-1].mScript.m_pPointer,
        (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
      operator delete[](v4);
    }
  }
  v1->mStreamData.size = 0;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v1);
  v5 = v1->mStreamRequests.mNode.mPrev;
  v6 = v1->mStreamRequests.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mStreamRequests.mNode.mPrev = &v1->mStreamRequests.mNode;
  v1->mStreamRequests.mNode.mNext = &v1->mStreamRequests.mNode;
}

// File Line: 31
// RVA: 0x4AB680
UFG::GameSliceStreamer *__fastcall UFG::GameSliceStreamer::Instance()
{
  return UFG::GameSliceStreamer::mspInstance;
}

// File Line: 36
// RVA: 0x497700
void __fastcall UFG::GameSliceStreamer::Clear(UFG::GameSliceStreamer *this, __int64 a2, __int64 a3, __int64 a4)
{
  UFG::GameSliceStreamer *v4; // rbx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v5; // rdi
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v6; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v7; // rax
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v8; // rdx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v9; // rax
  __int64 v10; // rdx
  unsigned int v11; // er8
  int v12; // ecx
  int v13; // er9
  signed __int64 v14; // r9
  int v15; // er8
  __int64 v16; // rcx
  bool v17; // zf
  __int64 v18; // rsi
  UFG::qSymbolUC **v19; // rdi

  v4 = this;
  while ( (UFG::GameSliceStreamer *)v4->mStreamRequests.mNode.mNext != v4 )
  {
    v5 = v4->mStreamRequests.mNode.mNext;
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = v5;
    v5->mNext = v5;
    UFG::GameSliceStreamer::CancelStream(v4, (UFG::GameSlice *)v5[1].mPrev, a3, a4);
    v8 = v5->mPrev;
    v9 = v5->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v5->mPrev = v5;
    v5->mNext = v5;
    operator delete[](v5);
  }
  while ( 1 )
  {
    v10 = v4->mDeferScriptDeletionRequests.mHeadIndex;
    if ( (_DWORD)v10 == -1 )
      break;
    v11 = v4->mDeferScriptDeletionRequests.mTailIndex;
    v12 = v4->mDeferScriptDeletionRequests.mTailIndex - v10;
    v13 = (unsigned int)v10 <= v11 ? v12 + 1 : v12 + v4->mDeferScriptDeletionRequests.mCapacity + 1;
    if ( !v13 )
      break;
    v14 = 0i64;
    if ( (unsigned int)v10 <= v11 )
      v15 = v12 + 1;
    else
      v15 = v12 + v4->mDeferScriptDeletionRequests.mCapacity + 1;
    if ( v15 > 0 )
    {
      v14 = (signed __int64)&v4->mDeferScriptDeletionRequests.mData[v10];
      v4->mDeferScriptDeletionRequests.mHeadIndex = (unsigned int)(v10 + 1) % v4->mDeferScriptDeletionRequests.mCapacity;
      if ( v15 == 1 )
        *(_QWORD *)&v4->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
    }
    v16 = *(_QWORD *)(v14 + 16);
    if ( v16 )
    {
      v17 = (*(_DWORD *)(v16 + 40))-- == 1;
      if ( v17 )
      {
        *(_DWORD *)(v16 + 40) = 2147483648;
        (*(void (__cdecl **)(__int64))(*(_QWORD *)(v16 + 24) + 112i64))(v16 + 24);
      }
    }
  }
  v18 = v4->mStreamData.size;
  if ( v18 > 0 )
  {
    v19 = (UFG::qSymbolUC **)v4->mStreamData.p;
    do
    {
      if ( (*v19)[3].mUID & 1 )
      {
        (*(void (__cdecl **)(UFG::qSymbolUC *))(*(_QWORD *)&(*v19)->mUID + 248i64))(*v19);
        UFG::qSymbol::as_cstr_dbg(*v19 + 2);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_GameSliceStreamer,
          OUTPUT_LEVEL_DEBUG,
          "[GameSliceStreamer]: ########## Unloading game slice group: %s\n");
      }
      v19 += 3;
      --v18;
    }
    while ( v18 );
  }
  v4->mStreamData.size = 0;
}

// File Line: 72
// RVA: 0x4B15B0
void __fastcall UFG::GameSliceStreamer::OnAsyncRead(const char *filename, void *data, int fileSize, void *pCallbackParam)
{
  SSClass *v4; // rbx
  void *v5; // rdi
  __int64 v6; // rcx
  __int64 v7; // rdx
  UFG::GameSliceStreamer::StreamData *v8; // rax

  if ( fileSize )
  {
    v4 = (SSClass *)pCallbackParam;
    v5 = data;
    if ( data )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)pCallbackParam + 2);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_GameSliceStreamer,
        OUTPUT_LEVEL_DEBUG,
        "[GameSliceStreamer]: OnAsyncRead called for (%s) (%s)\n");
      v6 = 0i64;
      v7 = UFG::GameSliceStreamer::mspInstance->mStreamData.size;
      if ( v7 > 0 )
      {
        v8 = UFG::GameSliceStreamer::mspInstance->mStreamData.p;
        while ( v8->mpRoot != v4 )
        {
          ++v6;
          ++v8;
          if ( v6 >= v7 )
            goto LABEL_12;
        }
        if ( v4->i_flags & 1 )
        {
          v4->i_flags &= 0xFFFFFFF7;
          v4->i_flags |= 1u;
        }
        else if ( !v8->mpBuffer )
        {
          v8->mpBuffer = v5;
          return;
        }
      }
LABEL_12:
      UFG::qFreeEntireFile(v5, 0i64);
    }
  }
}

// File Line: 94
// RVA: 0x4B66D0
void __fastcall UFG::GameSliceStreamer::RequestStream(UFG::GameSliceStreamer *this, UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v2; // rdi
  UFG::GameSliceStreamer *v3; // rbx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v4; // rax
  char *v5; // r9
  char *v6; // r9
  SSClass *v7; // rax
  SSClass *v8; // rsi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v11; // rax

  v2 = pGameSlice;
  v3 = this;
  v4 = this->mStreamRequests.mNode.mNext;
  if ( v4 == (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
  {
LABEL_6:
    v6 = pGameSlice->mName.mText;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: RequestStream (%s) - Queuing!\n");
    v7 = SSBrain::get_class(v2->mScriptClassName.mText);
    v8 = SSClass::get_demand_loaded_root(v7);
    v9 = UFG::qMalloc(0x20ui64, "GameSliceStreamer::StreamRequest", 0i64);
    v10 = v9;
    if ( v9 )
    {
      v9->mNext = v9;
      v9[1].mNext = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v10[2].mNext = (UFG::allocator::free_link *)v2;
    v10[3].mNext = (UFG::allocator::free_link *)v8;
    v11 = v3->mStreamRequests.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)v10;
    v10->mNext = (UFG::allocator::free_link *)v11;
    v10[1].mNext = (UFG::allocator::free_link *)v3;
    v3->mStreamRequests.mNode.mPrev = (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)v10;
    if ( v8 )
      UFG::GameSliceStreamer::RequestStream(v3, v2, v8);
  }
  else
  {
    while ( (UFG::GameSlice *)v4[1].mPrev != pGameSlice )
    {
      v4 = v4->mNext;
      if ( v4 == (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
        goto LABEL_6;
    }
    v5 = pGameSlice->mName.mText;
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
  UFG::SSGameSlice *v2; // rdi
  UFG::GameSliceStreamer *v3; // rbx
  __int64 v4; // rdx
  int v5; // ecx
  unsigned int v6; // ecx
  int v7; // eax
  signed __int64 v8; // rcx
  unsigned int v9; // er8
  int v10; // er8
  __int64 v11; // rcx
  bool v12; // zf
  __int64 *v15; // rax
  unsigned int v16; // eax
  int v17; // ecx
  unsigned int v18; // ecx
  int v19; // er8
  UFG::GameSliceStreamer::DeferScriptDeletionRequest *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *v23; // rax
  __int64 *v24; // rcx
  __int64 **v25; // rax
  __int64 *v26; // rcx
  __int64 **v27; // rax
  __int64 *v28; // [rsp+28h] [rbp-18h]
  __int64 **v29; // [rsp+30h] [rbp-10h]
  UFG::SSGameSlice *v30; // [rsp+38h] [rbp-8h]

  v2 = pScript;
  v3 = this;
  v4 = this->mDeferScriptDeletionRequests.mHeadIndex;
  if ( (_DWORD)v4 == -1 )
  {
    v5 = 0;
  }
  else
  {
    v6 = this->mDeferScriptDeletionRequests.mTailIndex;
    if ( (unsigned int)v4 <= v6 )
      v5 = v6 - v4 + 1;
    else
      v5 = v3->mDeferScriptDeletionRequests.mCapacity - v4 + v6 + 1;
  }
  v7 = v3->mDeferScriptDeletionRequests.mCapacity;
  if ( v5 == v7 )
  {
    v8 = 0i64;
    if ( (_DWORD)v4 != -1 )
    {
      v9 = v3->mDeferScriptDeletionRequests.mTailIndex;
      v10 = (unsigned int)v4 <= v9 ? v9 - v4 + 1 : v7 + v9 - (unsigned int)v4 + 1;
      if ( v10 > 0 )
      {
        v8 = (signed __int64)&v3->mDeferScriptDeletionRequests.mData[v4];
        v3->mDeferScriptDeletionRequests.mHeadIndex = (unsigned int)(v4 + 1)
                                                    % v3->mDeferScriptDeletionRequests.mCapacity;
        if ( v10 == 1 )
          *(_QWORD *)&v3->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
      }
    }
    v11 = *(_QWORD *)(v8 + 16);
    if ( v11 )
    {
      v12 = (*(_DWORD *)(v11 + 40))-- == 1;
      if ( v12 )
      {
        *(_DWORD *)(v11 + 40) = 2147483648;
        (*(void (__cdecl **)(__int64))(*(_QWORD *)(v11 + 24) + 112i64))(v11 + 24);
      }
    }
  }
  v28 = (__int64 *)&v28;
  v29 = &v28;
  v30 = 0i64;
  v30 = v2;
  if ( v2 )
  {
    v15 = (__int64 *)v2->m_SafePointerList.mNode.mPrev;
    v15[1] = (__int64)&v28;
    v28 = v15;
    v29 = (__int64 **)&v2->m_SafePointerList;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v28;
    v2 = v30;
  }
  v16 = v3->mDeferScriptDeletionRequests.mHeadIndex;
  if ( v16 == -1 )
  {
    v17 = 0;
  }
  else
  {
    v18 = v3->mDeferScriptDeletionRequests.mTailIndex;
    if ( v16 <= v18 )
      v17 = v18 - v16 + 1;
    else
      v17 = v3->mDeferScriptDeletionRequests.mCapacity + 1 + v18 - v16;
  }
  v19 = v3->mDeferScriptDeletionRequests.mCapacity;
  if ( v17 < v19 )
  {
    if ( v17 )
      v3->mDeferScriptDeletionRequests.mTailIndex = (v3->mDeferScriptDeletionRequests.mTailIndex + 1) % v19;
    else
      *(_QWORD *)&v3->mDeferScriptDeletionRequests.mHeadIndex = 0i64;
    v20 = &v3->mDeferScriptDeletionRequests.mData[v3->mDeferScriptDeletionRequests.mTailIndex];
    if ( v20->mScript.m_pPointer )
    {
      v21 = v20->mScript.mPrev;
      v22 = v20->mScript.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      v20->mScript.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v20->mScript.mPrev;
      v20->mScript.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v20->mScript.mPrev;
    }
    v20->mScript.m_pPointer = v2;
    if ( v2 )
    {
      v23 = v2->m_SafePointerList.mNode.mPrev;
      v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v20->mScript.mPrev;
      v20->mScript.mPrev = v23;
      v20->mScript.mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *)&v20->mScript.mPrev;
    }
  }
  if ( v30 )
  {
    v24 = v28;
    v25 = v29;
    v28[1] = (__int64)v29;
    *v25 = v24;
    v28 = (__int64 *)&v28;
    v29 = &v28;
  }
  v26 = v28;
  v27 = v29;
  v28[1] = (__int64)v29;
  *v27 = v26;
}

// File Line: 145
// RVA: 0x4B6530
void __fastcall UFG::GameSliceStreamer::RequestStream(UFG::GameSliceStreamer *this, UFG::GameSlice *pGameSlice, SSClass *pRoot)
{
  UFG::GameSlice *v3; // rdi
  UFG::qFixedArray<UFG::GameSliceStreamer::StreamData,128> *v4; // r14
  bool v5; // dl
  UFG::qSymbolUC *v6; // rbp
  __int64 v7; // r8
  __int64 v8; // rax
  UFG::GameSliceStreamer::StreamData *v9; // rsi
  __int64 v10; // rbx
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  UFG::qSymbolUC *v13; // rcx
  char *v14; // rdi
  UFG::qSymbolUC v15; // ebx
  int dbg_tag; // ST30_4
  char *v17; // rdi
  UFG::qSymbolUC v18; // ebx
  const char *v19; // rax
  UFG::StreamFileWrapper::QUEUE_CLASS v20; // edx

  v3 = pGameSlice;
  v4 = &this->mStreamData;
  v5 = pGameSlice->mStreamRequested != 0;
  v6 = (UFG::qSymbolUC *)pRoot;
  v3->mStreamRequested = 1;
  v7 = this->mStreamData.size;
  v8 = 0i64;
  if ( v7 <= 0 )
  {
LABEL_5:
    v10 = v6[2].mUID;
    UFG::qSymbol::as_cstr_dbg(v6 + 2);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: RequestStream (%s)(%0x08d) - New pRoot request\n");
    v11 = v4->size;
    v12 = (signed __int64)v4 + 24 * v11;
    v4->size = v11 + 1;
    *(_QWORD *)(v12 + 8) = v6;
    *(_QWORD *)(v12 + 16) = 0i64;
    *(_BYTE *)(v12 + 24) = 1;
    if ( v6[3].mUID & 1 )
    {
      v6[3].mUID &= 0xFFFFFFF7;
      v6[3].mUID |= 1u;
    }
    else
    {
      v19 = a_cstr_format("Data\\Scripts\\Class[%x].skoo-bin", v6[2].mUID);
      v20 = 3;
      if ( (unsigned int)(v3->mType - 10) <= 1 )
        v20 = 2;
      UFG::StreamFileWrapper::ReadEntireFileAsync(
        v19,
        v20,
        UFG::GameSliceStreamer::OnAsyncRead,
        v6,
        0i64,
        0,
        "StreamFileWrapper::ReadEntireFileAsync");
    }
  }
  else
  {
    v9 = this->mStreamData.p;
    while ( (UFG::qSymbolUC *)v9->mpRoot != v6 )
    {
      ++v8;
      ++v9;
      if ( v8 >= v7 )
        goto LABEL_5;
    }
    v13 = v6 + 2;
    if ( v5 )
    {
      v17 = v3->mName.mText;
      v18.mUID = v13->mUID;
      UFG::qSymbol::as_cstr_dbg(v13);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_GameSliceStreamer,
        OUTPUT_LEVEL_DEBUG,
        "[GameSliceStreamer]: RequestStream (%s)(%0x08d) - pRoot request by (%s) - already requested, ignored\n");
    }
    else
    {
      ++v9->mUsageCount;
      v14 = v3->mName.mText;
      v15.mUID = v13->mUID;
      UFG::qSymbol::as_cstr_dbg(v13);
      dbg_tag = v9->mUsageCount;
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_GameSliceStreamer,
        OUTPUT_LEVEL_DEBUG,
        "[GameSliceStreamer]: RequestStream (%s)(%0x08d) - pRoot request by (%s) - now at (%d)\n");
    }
  }
}

// File Line: 200
// RVA: 0x496A50
void __fastcall UFG::GameSliceStreamer::CancelStream(UFG::GameSliceStreamer *this, UFG::GameSlice *pGameSlice, __int64 a3, __int64 a4)
{
  UFG::GameSlice *v4; // rsi
  UFG::GameSliceStreamer *v5; // rdi
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v6; // rbx
  char *v7; // r9
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v8; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v9; // rax
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v10; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v11; // rax
  SSClass *v12; // rax
  SSClass *v13; // r10
  bool v14; // cl
  __int64 v15; // r9
  char *v16; // rax
  char *v17; // r9

  v4 = pGameSlice;
  v5 = this;
  v6 = this->mStreamRequests.mNode.mNext;
  if ( v6 != (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
  {
    while ( (UFG::GameSlice *)v6[1].mPrev != pGameSlice )
    {
      v6 = v6->mNext;
      if ( v6 == (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)this )
        goto LABEL_6;
    }
    v7 = pGameSlice->mName.mText;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_GameSliceStreamer,
      OUTPUT_LEVEL_DEBUG,
      "[GameSliceStreamer]: CancelStream (%s) - Request found, cancelling.\n");
    v8 = v6->mPrev;
    v9 = v6->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v6->mPrev = v6;
    v6->mNext = v6;
    v10 = v6->mPrev;
    v11 = v6->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v6->mPrev = v6;
    v6->mNext = v6;
    operator delete[](v6);
  }
LABEL_6:
  v12 = SSBrain::get_class(v4->mScriptClassName.mText);
  v13 = SSClass::get_demand_loaded_root(v12);
  if ( v13 )
  {
    v14 = v4->mStreamRequested != 0;
    v4->mStreamRequested = 0;
    if ( v14 )
    {
      v15 = v5->mStreamData.size;
      if ( v15 > 0 )
      {
        v16 = &v5->mStreamData.p[0].mUsageCount;
        do
        {
          if ( *((SSClass **)v16 - 2) == v13 && *v16 > 0 )
            --*v16;
          v16 += 24;
          --v15;
        }
        while ( v15 );
      }
    }
  }
  v17 = v4->mName.mText;
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_GameSliceStreamer,
    OUTPUT_LEVEL_DEBUG,
    "[GameSliceStreamer]: WARNING: CancelStream (%s) - Unable to find request!\n");
}

// File Line: 285
// RVA: 0x4C3FA0
void __fastcall UFG::GameSliceStreamer::Update(UFG::GameSliceStreamer *this)
{
  UFG::GameSliceStreamer *v1; // rdi
  UFG::GameSliceStreamer *v2; // rbx
  unsigned int v3; // ebp
  SSClass *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rdx
  signed __int64 v7; // rsi
  UFG::qSymbolUC *v8; // rcx
  UFG::qSymbolUC v9; // ebx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v10; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v11; // rax
  __int64 v12; // rcx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v13; // rdx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *v14; // rax
  __int64 v15; // rdx
  unsigned int v16; // er8
  int v17; // ecx
  int v18; // er9
  signed __int64 v19; // r9
  int v20; // er8
  __int64 v21; // rcx
  bool v22; // zf
  __int64 v23; // rax
  UFG::qFixedArray<UFG::GameSliceStreamer::StreamData,128> *v24; // rbx
  __int64 v25; // rcx
  signed __int64 v26; // rdi
  UFG::qSymbolUC *v27; // rcx
  const char *v28; // r8
  signed __int64 v29; // rdx
  signed __int64 v30; // rcx
  void *binary_pp; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = (UFG::GameSliceStreamer *)this->mStreamRequests.mNode.mNext;
  v3 = 0;
  if ( v2 != this )
  {
    v4 = v2->mStreamData.p[0].mpRoot;
    if ( !v4 || v4->i_flags & 1 )
    {
      v10 = v2->mStreamRequests.mNode.mPrev;
      v11 = v2->mStreamRequests.mNode.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v2->mStreamRequests.mNode.mPrev = &v2->mStreamRequests.mNode;
      v2->mStreamRequests.mNode.mNext = &v2->mStreamRequests.mNode;
      v12 = *(_QWORD *)&v2->mStreamData.size;
      if ( (unsigned int)(*(_DWORD *)(v12 + 264) - 1) <= 6 )
        UFG::GameSlice::StartScript((UFG::GameSlice *)v12);
      binary_pp = v2;
      v13 = v2->mStreamRequests.mNode.mPrev;
      v14 = v2->mStreamRequests.mNode.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v2->mStreamRequests.mNode.mPrev = &v2->mStreamRequests.mNode;
      v2->mStreamRequests.mNode.mNext = &v2->mStreamRequests.mNode;
      operator delete[](v2);
    }
    else
    {
      v5 = 0i64;
      v6 = v1->mStreamData.size;
      if ( v6 > 0 )
      {
        v7 = (signed __int64)v1->mStreamData.p;
        while ( *(SSClass **)v7 != v4 )
        {
          ++v5;
          v7 += 24i64;
          if ( v5 >= v6 )
            goto LABEL_17;
        }
        if ( *(_QWORD *)(v7 + 8) )
        {
          if ( *(_BYTE *)(*(_QWORD *)v7 + 12i64) & 1 )
          {
            v8 = (UFG::qSymbolUC *)(*(_QWORD *)v7 + 8i64);
            v9.mUID = v8->mUID;
            UFG::qSymbol::as_cstr_dbg(v8);
            UFG::qPrintChannel::Print(
              &UFG::gPrintChannel_HK_GameSliceStreamer,
              OUTPUT_LEVEL_WARNING,
              "[GameSliceStreamer]: Binary alread loaded! (%s)(%x)\n");
          }
          else
          {
            binary_pp = *(void **)(v7 + 8);
            SSClass::from_binary_group((const void **)&binary_pp);
            SSClass::invoke_class_ctor_recurse(*(SSClass **)v7);
          }
          UFG::qFreeEntireFile(*(void **)(v7 + 8), 0i64);
          *(_QWORD *)(v7 + 8) = 0i64;
        }
      }
    }
  }
  do
  {
LABEL_17:
    v15 = v1->mDeferScriptDeletionRequests.mHeadIndex;
    if ( (_DWORD)v15 == -1 )
      break;
    v16 = v1->mDeferScriptDeletionRequests.mTailIndex;
    v17 = v1->mDeferScriptDeletionRequests.mTailIndex - v15;
    v18 = (unsigned int)v15 <= v16 ? v17 + 1 : v17 + v1->mDeferScriptDeletionRequests.mCapacity + 1;
    if ( !v18 )
      break;
    v19 = 0i64;
    if ( (unsigned int)v15 <= v16 )
      v20 = v17 + 1;
    else
      v20 = v17 + v1->mDeferScriptDeletionRequests.mCapacity + 1;
    if ( v20 > 0 )
    {
      v19 = (signed __int64)&v1->mDeferScriptDeletionRequests.mData[v15];
      v1->mDeferScriptDeletionRequests.mHeadIndex = (unsigned int)(v15 + 1) % v1->mDeferScriptDeletionRequests.mCapacity;
      if ( v20 == 1 )
        *(_QWORD *)&v1->mDeferScriptDeletionRequests.mHeadIndex = -1i64;
    }
    v21 = *(_QWORD *)(v19 + 16);
    if ( v21 )
    {
      v22 = (*(_DWORD *)(v21 + 40))-- == 1;
      if ( v22 )
      {
        *(_DWORD *)(v21 + 40) = 2147483648;
        (*(void (__cdecl **)(__int64))(*(_QWORD *)(v21 + 24) + 112i64))(v21 + 24);
      }
    }
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( !unk_14240B6D0 )
      break;
  }
  while ( *(_DWORD *)(unk_14240B6D0 + 268i64) >= 6 );
  v23 = 0i64;
  v24 = &v1->mStreamData;
  v25 = v1->mStreamData.size;
  if ( v25 > 0 )
  {
    v26 = (signed __int64)v1->mStreamData.p;
    while ( *(_BYTE *)(v26 + 16) )
    {
      ++v3;
      ++v23;
      v26 += 24i64;
      if ( v23 >= v25 )
        return;
    }
    v27 = *(UFG::qSymbolUC **)v26;
    if ( *(_BYTE *)(*(_QWORD *)v26 + 12i64) & 1 )
    {
      (*(void (__cdecl **)(UFG::qSymbolUC *))(*(_QWORD *)&v27->mUID + 248i64))(v27);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(*(_QWORD *)v26 + 8i64));
      v28 = "[GameSliceStreamer]: ########## Unloading game slice group: %s\n";
    }
    else
    {
      UFG::qSymbol::as_cstr_dbg(v27 + 2);
      v28 = "[GameSliceStreamer]: ########## Unloading game slice group: %s.  No need to unload, not yet loaded\n";
    }
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_GameSliceStreamer, OUTPUT_LEVEL_DEBUG, v28);
    v29 = --v24->size;
    v30 = v3;
    v24->p[v30].mpRoot = v24->p[v24->size].mpRoot;
    v24->p[v30].mpBuffer = v24->p[v29].mpBuffer;
    *(_QWORD *)&v24->p[v30].mUsageCount = *(_QWORD *)&v24->p[v29].mUsageCount;
  }
}

