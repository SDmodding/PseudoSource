// File Line: 45
// RVA: 0x1467C30
__int64 UFG::_dynamic_initializer_for__gChunkFileBuildersMutex__()
{
  UFG::qMutex::qMutex(&UFG::gChunkFileBuildersMutex, &customWorldMapCaption);
  return atexit(UFG::_dynamic_atexit_destructor_for__gChunkFileBuildersMutex__);
}

// File Line: 46
// RVA: 0x1467C10
__int64 UFG::_dynamic_initializer_for__gChunkFileBuilders__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__gChunkFileBuilders__);
}

// File Line: 198
// RVA: 0x18C990
void __fastcall UFG::qValidateChunkFileBuilders(UFG *this)
{
  UFG::qList<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder,1,0> *i; // rbx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::gChunkFileBuildersMutex);
  for ( i = (UFG::qList<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder,1,0> *)UFG::gChunkFileBuilders.mNode.mNext;
        i != &UFG::gChunkFileBuilders;
        i = (UFG::qList<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder,1,0> *)i->mNode.mNext )
  {
    UFG::qPrintf("ERROR:  filename=%s\n", i[5].mNode.mPrev);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::gChunkFileBuildersMutex);
}

// File Line: 268
// RVA: 0x1634A0
void __fastcall UFG::qChunkFileBuilder::~qChunkFileBuilder(UFG::qChunkFileBuilder *this)
{
  UFG::qChunkFileBuilder *v1; // rdi
  void *v2; // rdx
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *v3; // rcx
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *v4; // rax
  UFG::qNode<UFG::tChunkPosition,UFG::tChunkPosition> *v5; // rcx
  UFG::qNode<UFG::tChunkPosition,UFG::tChunkPosition> *v6; // rax
  UFG::qNode<UFG::tCheckSize,UFG::tCheckSize> *v7; // rcx
  UFG::qNode<UFG::tCheckSize,UFG::tCheckSize> *v8; // rax
  UFG::qNode<UFG::tChunk,UFG::tChunk> *v9; // rcx
  UFG::qNode<UFG::tChunk,UFG::tChunk> *v10; // rax
  UFG::qString *v11; // rbx
  char *v12; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *v15; // rbx
  char *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qString *v19; // rbx
  char *v20; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rax
  UFG::qString *v23; // rbx
  char *v24; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  UFG::qString *v27; // rbx
  char *v28; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rax
  UFG::qString *v31; // rbx
  char *v32; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  UFG::qString *v35; // rbx
  char *v36; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rax
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *v39; // rcx
  UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *v40; // rax

  v1 = this;
  v2 = this->mWriteBufferPtr;
  if ( v2 )
  {
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
    v1->mWriteBufferPtr = 0i64;
    v1->mWriteBufferSizeBytes = 0i64;
    v1->mWriteBufferEOFPos = 0i64;
  }
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mPrev = (UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *)&v1->mPrev;
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes(&v1->mOrderedChunks);
  v5 = v1->mOrderedChunks.mNode.mPrev;
  v6 = v1->mOrderedChunks.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mOrderedChunks.mNode.mPrev = &v1->mOrderedChunks.mNode;
  v1->mOrderedChunks.mNode.mNext = &v1->mOrderedChunks.mNode;
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll(&v1->mTreePatchPoints);
  v1->mTreePatchPoints.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&v1->mTreePatchPoints.mTree.mNULL | (_QWORD)v1->mTreePatchPoints.mTree.mRoot.mParent & 1);
  v1->mTreePatchPoints.mTree.mRoot.mChild[0] = &v1->mTreePatchPoints.mTree.mNULL;
  v1->mTreePatchPoints.mTree.mRoot.mChild[1] = &v1->mTreePatchPoints.mTree.mNULL;
  v1->mTreePatchPoints.mTree.mCount = 0;
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll((UFG::qTreeRB<UFG::tPatchPoint,UFG::tPatchPoint,1> *)&v1->mTreeFileIndex);
  v1->mTreeFileIndex.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&v1->mTreeFileIndex.mTree.mNULL | (_QWORD)v1->mTreeFileIndex.mTree.mRoot.mParent & 1);
  v1->mTreeFileIndex.mTree.mRoot.mChild[0] = &v1->mTreeFileIndex.mTree.mNULL;
  v1->mTreeFileIndex.mTree.mRoot.mChild[1] = &v1->mTreeFileIndex.mTree.mNULL;
  v1->mTreeFileIndex.mTree.mCount = 0;
  UFG::qTreeRB64<UFG::tMarker,UFG::tMarker,1>::DeleteAll(&v1->mTreeForbiddenMarkers);
  v1->mTreeForbiddenMarkers.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v1->mTreeForbiddenMarkers.mTree.mNULL | (_QWORD)v1->mTreeForbiddenMarkers.mTree.mRoot.mParent & 1);
  v1->mTreeForbiddenMarkers.mTree.mRoot.mChild[0] = &v1->mTreeForbiddenMarkers.mTree.mNULL;
  v1->mTreeForbiddenMarkers.mTree.mRoot.mChild[1] = &v1->mTreeForbiddenMarkers.mTree.mNULL;
  v1->mTreeForbiddenMarkers.mTree.mCount = 0;
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll((UFG::qTreeRB<UFG::tPatchPoint,UFG::tPatchPoint,1> *)&v1->mTreeOffset);
  v1->mTreeOffset.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v1->mTreeOffset.mTree.mNULL | (_QWORD)v1->mTreeOffset.mTree.mRoot.mParent & 1);
  v1->mTreeOffset.mTree.mRoot.mChild[0] = &v1->mTreeOffset.mTree.mNULL;
  v1->mTreeOffset.mTree.mRoot.mChild[1] = &v1->mTreeOffset.mTree.mNULL;
  v1->mTreeOffset.mTree.mCount = 0;
  UFG::qTreeRB64<UFG::tMarker,UFG::tMarker,1>::DeleteAll(&v1->mTreeMarker);
  v1->mTreeMarker.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v1->mTreeMarker.mTree.mNULL | (_QWORD)v1->mTreeMarker.mTree.mRoot.mParent & 1);
  v1->mTreeMarker.mTree.mRoot.mChild[0] = &v1->mTreeMarker.mTree.mNULL;
  v1->mTreeMarker.mTree.mRoot.mChild[1] = &v1->mTreeMarker.mTree.mNULL;
  v1->mTreeMarker.mTree.mCount = 0;
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes((UFG::qList<UFG::tChunkPosition,UFG::tChunkPosition,1,0> *)&v1->mCheckSizes);
  v7 = v1->mCheckSizes.mNode.mPrev;
  v8 = v1->mCheckSizes.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mCheckSizes.mNode.mPrev = &v1->mCheckSizes.mNode;
  v1->mCheckSizes.mNode.mNext = &v1->mCheckSizes.mNode;
  UFG::qList<UFG::tChunk,UFG::tChunk,1,0>::DeleteNodes(&v1->mChunks);
  v9 = v1->mChunks.mNode.mPrev;
  v10 = v1->mChunks.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v1->mChunks.mNode.mPrev = &v1->mChunks.mNode;
  v1->mChunks.mNode.mNext = &v1->mChunks.mNode;
  v11 = &v1->mCompressionFilename;
  v12 = v1->mCompressionFilename.mData;
  if ( v12 != UFG::qString::sEmptyString && v12 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12);
  v1->mCompressionFilename.mMagic = 0;
  v13 = v11->mPrev;
  v14 = v1->mCompressionFilename.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v11->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v11->mPrev;
  v1->mCompressionFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mCompressionFilename.mPrev;
  v15 = &v1->mLogIndent;
  v16 = v1->mLogIndent.mData;
  if ( v16 != UFG::qString::sEmptyString && v16 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v16);
  v1->mLogIndent.mMagic = 0;
  v17 = v15->mPrev;
  v18 = v1->mLogIndent.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v15->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v15->mPrev;
  v1->mLogIndent.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mLogIndent.mPrev;
  v19 = &v1->mLogFilename;
  v20 = v1->mLogFilename.mData;
  if ( v20 != UFG::qString::sEmptyString && v20 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v20);
  v1->mLogFilename.mMagic = 0;
  v21 = v19->mPrev;
  v22 = v1->mLogFilename.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v19->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v19->mPrev;
  v1->mLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mLogFilename.mPrev;
  v23 = &v1->mPipelineIndexFilename;
  v24 = v1->mPipelineIndexFilename.mData;
  if ( v24 != UFG::qString::sEmptyString && v24 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v24);
  v1->mPipelineIndexFilename.mMagic = 0;
  v25 = v23->mPrev;
  v26 = v1->mPipelineIndexFilename.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v23->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v23->mPrev;
  v1->mPipelineIndexFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mPipelineIndexFilename.mPrev;
  v27 = &v1->mIndexFilename;
  v28 = v1->mIndexFilename.mData;
  if ( v28 != UFG::qString::sEmptyString && v28 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v28);
  v1->mIndexFilename.mMagic = 0;
  v29 = v27->mPrev;
  v30 = v1->mIndexFilename.mNext;
  v29->mNext = v30;
  v30->mPrev = v29;
  v27->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v27->mPrev;
  v1->mIndexFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mIndexFilename.mPrev;
  v31 = &v1->mBinFilename;
  v32 = v1->mBinFilename.mData;
  if ( v32 != UFG::qString::sEmptyString && v32 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v32);
  v1->mBinFilename.mMagic = 0;
  v33 = v31->mPrev;
  v34 = v1->mBinFilename.mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v31->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v31->mPrev;
  v1->mBinFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mBinFilename.mPrev;
  v35 = &v1->mPlatformName;
  v36 = v1->mPlatformName.mData;
  if ( v36 != UFG::qString::sEmptyString && v36 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v36);
  v1->mPlatformName.mMagic = 0;
  v37 = v35->mPrev;
  v38 = v1->mPlatformName.mNext;
  v37->mNext = v38;
  v38->mPrev = v37;
  v35->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v35->mPrev;
  v1->mPlatformName.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mPlatformName.mPrev;
  v39 = v1->mPrev;
  v40 = v1->mNext;
  v39->mNext = v40;
  v40->mPrev = v39;
  v1->mPrev = (UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qChunkFileBuilder,UFG::qChunkFileBuilder> *)&v1->mPrev;
}

