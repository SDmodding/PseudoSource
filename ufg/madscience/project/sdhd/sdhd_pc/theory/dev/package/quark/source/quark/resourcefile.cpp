// File Line: 45
// RVA: 0x1467C30
__int64 UFG::_dynamic_initializer_for__gChunkFileBuildersMutex__()
{
  UFG::qMutex::qMutex(&UFG::gChunkFileBuildersMutex, &customCaption);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gChunkFileBuildersMutex__);
}

// File Line: 46
// RVA: 0x1467C10
__int64 UFG::_dynamic_initializer_for__gChunkFileBuilders__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gChunkFileBuilders__);
}

// File Line: 198
// RVA: 0x18C990
void __fastcall UFG::qValidateChunkFileBuilders(UFG *this)
{
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *i; // rbx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::gChunkFileBuildersMutex);
  for ( i = UFG::gChunkFileBuilders.mNode.mNext;
        i != (UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *)&UFG::gChunkFileBuilders;
        i = i->mNext )
  {
    UFG::qPrintf("ERROR:  filename=%s\n", (const char *)i[5].mPrev);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::gChunkFileBuildersMutex);
}

// File Line: 268
// RVA: 0x1634A0
void __fastcall UFG::qChunkFileBuilder::~qChunkFileBuilder(UFG::qChunkFileBuilder *this)
{
  void *mWriteBufferPtr; // rdx
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *mPrev; // rcx
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *mNext; // rax
  UFG::qNode<UFG::tChunkPosition,UFG::tChunkPosition> *v5; // rcx
  UFG::qNode<UFG::tChunkPosition,UFG::tChunkPosition> *v6; // rax
  UFG::qNode<UFG::tCheckSize,UFG::tCheckSize> *v7; // rcx
  UFG::qNode<UFG::tCheckSize,UFG::tCheckSize> *v8; // rax
  UFG::qNode<UFG::tChunk,UFG::tChunk> *v9; // rcx
  UFG::qNode<UFG::tChunk,UFG::tChunk> *v10; // rax
  UFG::qString *p_mCompressionFilename; // rbx
  char *mData; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *p_mLogIndent; // rbx
  char *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qString *p_mLogFilename; // rbx
  char *v20; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rax
  UFG::qString *p_mPipelineIndexFilename; // rbx
  char *v24; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  UFG::qString *p_mIndexFilename; // rbx
  char *v28; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rax
  UFG::qString *p_mBinFilename; // rbx
  char *v32; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  UFG::qString *p_mPlatformName; // rbx
  char *v36; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rax
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *v39; // rcx
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *v40; // rax

  mWriteBufferPtr = this->mWriteBufferPtr;
  if ( mWriteBufferPtr )
  {
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mWriteBufferPtr);
    this->mWriteBufferPtr = 0i64;
    this->mWriteBufferSizeBytes = 0i64;
    this->mWriteBufferEOFPos = 0i64;
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes(&this->mOrderedChunks);
  v5 = this->mOrderedChunks.mNode.mPrev;
  v6 = this->mOrderedChunks.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mOrderedChunks.mNode.mPrev = &this->mOrderedChunks.mNode;
  this->mOrderedChunks.mNode.mNext = &this->mOrderedChunks.mNode;
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll(&this->mTreePatchPoints);
  this->mTreePatchPoints.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mTreePatchPoints.mTree.mNULL | (__int64)this->mTreePatchPoints.mTree.mRoot.mParent & 1);
  this->mTreePatchPoints.mTree.mRoot.mChild[0] = &this->mTreePatchPoints.mTree.mNULL;
  this->mTreePatchPoints.mTree.mRoot.mChild[1] = &this->mTreePatchPoints.mTree.mNULL;
  this->mTreePatchPoints.mTree.mCount = 0;
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll((UFG::qTreeRB<UFG::tPatchPoint,UFG::tPatchPoint,1> *)&this->mTreeFileIndex);
  this->mTreeFileIndex.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mTreeFileIndex.mTree.mNULL | (__int64)this->mTreeFileIndex.mTree.mRoot.mParent & 1);
  this->mTreeFileIndex.mTree.mRoot.mChild[0] = &this->mTreeFileIndex.mTree.mNULL;
  this->mTreeFileIndex.mTree.mRoot.mChild[1] = &this->mTreeFileIndex.mTree.mNULL;
  this->mTreeFileIndex.mTree.mCount = 0;
  UFG::qTreeRB64<UFG::tMarker,UFG::tMarker,1>::DeleteAll(&this->mTreeForbiddenMarkers);
  this->mTreeForbiddenMarkers.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mTreeForbiddenMarkers.mTree.mNULL | (__int64)this->mTreeForbiddenMarkers.mTree.mRoot.mParent & 1);
  this->mTreeForbiddenMarkers.mTree.mRoot.mChild[0] = &this->mTreeForbiddenMarkers.mTree.mNULL;
  this->mTreeForbiddenMarkers.mTree.mRoot.mChild[1] = &this->mTreeForbiddenMarkers.mTree.mNULL;
  this->mTreeForbiddenMarkers.mTree.mCount = 0;
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll((UFG::qTreeRB<UFG::tPatchPoint,UFG::tPatchPoint,1> *)&this->mTreeOffset);
  this->mTreeOffset.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mTreeOffset.mTree.mNULL | (__int64)this->mTreeOffset.mTree.mRoot.mParent & 1);
  this->mTreeOffset.mTree.mRoot.mChild[0] = &this->mTreeOffset.mTree.mNULL;
  this->mTreeOffset.mTree.mRoot.mChild[1] = &this->mTreeOffset.mTree.mNULL;
  this->mTreeOffset.mTree.mCount = 0;
  UFG::qTreeRB64<UFG::tMarker,UFG::tMarker,1>::DeleteAll(&this->mTreeMarker);
  this->mTreeMarker.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mTreeMarker.mTree.mNULL | (__int64)this->mTreeMarker.mTree.mRoot.mParent & 1);
  this->mTreeMarker.mTree.mRoot.mChild[0] = &this->mTreeMarker.mTree.mNULL;
  this->mTreeMarker.mTree.mRoot.mChild[1] = &this->mTreeMarker.mTree.mNULL;
  this->mTreeMarker.mTree.mCount = 0;
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes((UFG::qList<UFG::tChunkPosition,UFG::tChunkPosition,1,0> *)&this->mCheckSizes);
  v7 = this->mCheckSizes.mNode.mPrev;
  v8 = this->mCheckSizes.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mCheckSizes.mNode.mPrev = &this->mCheckSizes.mNode;
  this->mCheckSizes.mNode.mNext = &this->mCheckSizes.mNode;
  UFG::qList<UFG::tChunk,UFG::tChunk,1,0>::DeleteNodes(&this->mChunks);
  v9 = this->mChunks.mNode.mPrev;
  v10 = this->mChunks.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mChunks.mNode.mPrev = &this->mChunks.mNode;
  this->mChunks.mNode.mNext = &this->mChunks.mNode;
  p_mCompressionFilename = &this->mCompressionFilename;
  mData = this->mCompressionFilename.mData;
  if ( mData != UFG::qString::sEmptyString && mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mData);
  this->mCompressionFilename.mMagic = 0;
  v13 = p_mCompressionFilename->mPrev;
  v14 = this->mCompressionFilename.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mCompressionFilename->mPrev = p_mCompressionFilename;
  this->mCompressionFilename.mNext = &this->mCompressionFilename;
  p_mLogIndent = &this->mLogIndent;
  v16 = this->mLogIndent.mData;
  if ( v16 != UFG::qString::sEmptyString && v16 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v16);
  this->mLogIndent.mMagic = 0;
  v17 = p_mLogIndent->mPrev;
  v18 = this->mLogIndent.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mLogIndent->mPrev = p_mLogIndent;
  this->mLogIndent.mNext = &this->mLogIndent;
  p_mLogFilename = &this->mLogFilename;
  v20 = this->mLogFilename.mData;
  if ( v20 != UFG::qString::sEmptyString && v20 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v20);
  this->mLogFilename.mMagic = 0;
  v21 = p_mLogFilename->mPrev;
  v22 = this->mLogFilename.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_mLogFilename->mPrev = p_mLogFilename;
  this->mLogFilename.mNext = &this->mLogFilename;
  p_mPipelineIndexFilename = &this->mPipelineIndexFilename;
  v24 = this->mPipelineIndexFilename.mData;
  if ( v24 != UFG::qString::sEmptyString && v24 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v24);
  this->mPipelineIndexFilename.mMagic = 0;
  v25 = p_mPipelineIndexFilename->mPrev;
  v26 = this->mPipelineIndexFilename.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_mPipelineIndexFilename->mPrev = p_mPipelineIndexFilename;
  this->mPipelineIndexFilename.mNext = &this->mPipelineIndexFilename;
  p_mIndexFilename = &this->mIndexFilename;
  v28 = this->mIndexFilename.mData;
  if ( v28 != UFG::qString::sEmptyString && v28 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v28);
  this->mIndexFilename.mMagic = 0;
  v29 = p_mIndexFilename->mPrev;
  v30 = this->mIndexFilename.mNext;
  v29->mNext = v30;
  v30->mPrev = v29;
  p_mIndexFilename->mPrev = p_mIndexFilename;
  this->mIndexFilename.mNext = &this->mIndexFilename;
  p_mBinFilename = &this->mBinFilename;
  v32 = this->mBinFilename.mData;
  if ( v32 != UFG::qString::sEmptyString && v32 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v32);
  this->mBinFilename.mMagic = 0;
  v33 = p_mBinFilename->mPrev;
  v34 = this->mBinFilename.mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  p_mBinFilename->mPrev = p_mBinFilename;
  this->mBinFilename.mNext = &this->mBinFilename;
  p_mPlatformName = &this->mPlatformName;
  v36 = this->mPlatformName.mData;
  if ( v36 != UFG::qString::sEmptyString && v36 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v36);
  this->mPlatformName.mMagic = 0;
  v37 = p_mPlatformName->mPrev;
  v38 = this->mPlatformName.mNext;
  v37->mNext = v38;
  v38->mPrev = v37;
  p_mPlatformName->mPrev = p_mPlatformName;
  this->mPlatformName.mNext = &this->mPlatformName;
  v39 = this->mPrev;
  v40 = this->mNext;
  v39->mNext = v40;
  v40->mPrev = v39;
  this->mPrev = this;
  this->mNext = this;
}

