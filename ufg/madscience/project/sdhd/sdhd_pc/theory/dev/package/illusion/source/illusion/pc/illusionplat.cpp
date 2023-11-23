// File Line: 61
// RVA: 0x15AA610
__int64 Illusion::_dynamic_initializer_for__gEnginePlat__()
{
  Illusion::EnginePlat::EnginePlat(&Illusion::gEnginePlat);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gEnginePlat__);
}

// File Line: 92
// RVA: 0xA22E20
double __fastcall Illusion::IEnginePlat::WaitUntilGPUDone(Illusion::IEnginePlat *this)
{
  unsigned __int64 Ticks; // rbp
  void *CurrentThreadID; // rbx
  unsigned __int64 MainThreadID; // rax
  __int64 v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // rsi
  unsigned __int64 v7; // rax
  double result; // xmm0_8
  __int64 v9; // [rsp+58h] [rbp+10h] BYREF
  __int64 v10; // [rsp+60h] [rbp+18h] BYREF

  Ticks = UFG::qGetTicks();
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  CurrentThreadID = UFG::qGetCurrentThreadID();
  MainThreadID = UFG::qGetMainThreadID();
  v4 = tls_index;
  if ( CurrentThreadID == (void *)MainThreadID
    && (v5 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64),
        (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v5 + 896i64))(v5) == 1) )
  {
    Illusion::RenderThreadManager::AddCommand(&Illusion::gRenderThreadManager, RTCMD_WAIT_FOR_GPU, 0i64, 0i64, 0i64);
    UFG::qEvent::Wait(&stru_1424527E8);
  }
  else
  {
    v9 = 0i64;
    v10 = 0i64;
    if ( ((int (__fastcall *)(ID3D11Device *, __int64 *, __int64 *))UFG::gD3D11Device->vfptr->OMSetRenderTargets)(
           UFG::gD3D11Device,
           &v10,
           &v9) >= 0 )
    {
      v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + v4);
      (*(void (__fastcall **)(_QWORD, __int64))(**(_QWORD **)(v6 + 104) + 224i64))(*(_QWORD *)(v6 + 104), v9);
      while ( (*(unsigned int (__fastcall **)(_QWORD, __int64, _QWORD, _QWORD, _DWORD))(**(_QWORD **)(v6 + 104) + 232i64))(
                *(_QWORD *)(v6 + 104),
                v9,
                0i64,
                0i64,
                0) == 1 )
        UFG::qSleep(0);
    }
    if ( v9 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  }
  v7 = UFG::qGetTicks();
  *(float *)&result = UFG::qGetTickTime(Ticks, v7);
  return result;
}

// File Line: 131
// RVA: 0xA1BCE0
__int64 __fastcall Illusion::IEnginePlat::IsValidDrawCall(
        Illusion::IEnginePlat *this,
        Illusion::rMesh *rmesh,
        Illusion::rMaterial *rmaterial,
        Illusion::Buffer *forced_index_buffer,
        Illusion::Buffer *instance_buffer)
{
  unsigned __int8 v7; // cl
  unsigned int mTypeUID; // ebx
  int v9; // eax
  unsigned int v10; // ebx
  int v11; // eax
  UFG::qResourceData **p_mData; // rdi
  __int64 v13; // rsi
  UFG::qResourceData *v14; // rax
  unsigned int v15; // ebx
  int v16; // eax

  v7 = 1;
  if ( instance_buffer && !instance_buffer[1].mResourceHandles.UFG::qResourceData::mNode.mNext )
  {
    mTypeUID = instance_buffer[1].mTypeUID;
    v9 = UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
    if ( v9 > 4095 )
      v9 = 4095;
    v7 = 0;
    Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v9] = mTypeUID;
  }
  if ( rmesh )
  {
    if ( (forced_index_buffer || (forced_index_buffer = (Illusion::Buffer *)rmesh->mIndexBufferHandle.mData) != 0i64)
      && !forced_index_buffer[1].mResourceHandles.UFG::qResourceData::mNode.mNext )
    {
      v10 = forced_index_buffer[1].mTypeUID;
      v11 = UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
      if ( v11 > 4095 )
        v11 = 4095;
      v7 = 0;
      Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v11] = v10;
    }
    p_mData = &rmesh->mVertexBufferHandles[0].mData;
    v13 = 4i64;
    do
    {
      v14 = *p_mData;
      if ( *p_mData && !v14[2].mNode.mChild[0] )
      {
        v15 = (unsigned int)v14[2].mNode.mChild[1];
        v16 = UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
        if ( v16 > 4095 )
          v16 = 4095;
        v7 = 0;
        Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v16] = v15;
      }
      p_mData += 4;
      --v13;
    }
    while ( v13 );
  }
  return v7;
}

// File Line: 176
// RVA: 0xA1B8E0
__int64 __fastcall Illusion::IEnginePlat::IsValidDrawCall(Illusion::IEnginePlat *this, Illusion::Material *material)
{
  unsigned __int8 v2; // r8
  unsigned int mNumParams; // eax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **p_mNext; // rdi
  __int64 v5; // rsi
  __int64 v6; // rax
  __int64 v7; // rdx
  unsigned int v8; // ebx
  int v9; // eax

  v2 = 1;
  if ( material )
  {
    mNumParams = material->mNumParams;
    if ( mNumParams )
    {
      p_mNext = &material[1].mResourceHandles.UFG::qResourceData::mNode.mNext;
      v5 = mNumParams;
      do
      {
        if ( *((_DWORD *)p_mNext - 10) )
        {
          if ( *((_DWORD *)p_mNext + 2) == -1958479169 )
          {
            v6 = (__int64)*(p_mNext - 1);
            if ( v6 )
            {
              if ( (unsigned int)(*(_DWORD *)p_mNext - 1) <= 0xFFFFFFFD
                && (*(_DWORD *)p_mNext == *(_DWORD *)(v6 + 24) || !*(_QWORD *)(v6 + 296)) )
              {
                v7 = *(_QWORD *)(v6 + 296);
                if ( !v7 || *(_DWORD *)(v7 + 24) != *(_DWORD *)(v6 + 304) )
                {
                  v8 = *(_DWORD *)(v6 + 304);
                  v9 = UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
                  if ( v9 > 4095 )
                    v9 = 4095;
                  v2 = 0;
                  Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[v9] = v8;
                }
              }
            }
          }
        }
        p_mNext += 7;
        --v5;
      }
      while ( v5 );
    }
  }
  return v2;
}

// File Line: 231
// RVA: 0xA1B9D0
char __fastcall Illusion::IEnginePlat::IsValidDrawCall(
        Illusion::IEnginePlat *this,
        Illusion::Mesh *mesh,
        Illusion::Material *material,
        Illusion::Buffer *forced_index_buffer,
        Illusion::Buffer *instance_buffer)
{
  int v5; // r10d
  Illusion::Buffer *mData; // rbp
  __int64 mOffset; // rax
  _BYTE *v10; // rax
  unsigned __int64 v11; // r15
  __int64 v12; // rsi
  char v13; // r13
  __int64 mUID; // rax
  unsigned int v15; // ecx
  unsigned __int64 v16; // r8
  unsigned int v17; // eax
  unsigned __int64 v18; // r15
  __int64 v19; // rcx
  char v20; // r8
  unsigned int mTypeUID; // ebx
  int v22; // eax
  unsigned int v23; // ebx
  int v24; // eax
  UFG::qResourceData **p_mData; // rdi
  __int64 v26; // rbp
  UFG::qResourceData *v27; // rax
  unsigned int v28; // ebx
  int v29; // eax
  char v30; // r12
  unsigned int mNumParams; // eax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **p_mNext; // rdi
  __int64 v33; // rbp
  __int64 v34; // rcx
  __int64 v36; // rdx
  unsigned int v37; // ebx
  int v38; // eax
  unsigned __int64 v39; // [rsp+60h] [rbp+18h]

  v5 = 0;
  mData = forced_index_buffer;
  if ( material
    && ((mOffset = material->mMaterialUser.mOffset) == 0
      ? (v10 = 0i64)
      : (v10 = (char *)&material->mMaterialUser + mOffset),
        (*v10 & 0x20) != 0) )
  {
    v11 = v39;
    LODWORD(v12) = v39;
    v13 = 0;
LABEL_25:
    v20 = 1;
    if ( instance_buffer && !instance_buffer[1].mResourceHandles.UFG::qResourceData::mNode.mNext )
    {
      mTypeUID = instance_buffer[1].mTypeUID;
      v22 = UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
      if ( v22 > 4095 )
        v22 = 4095;
      v20 = 0;
      Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v22] = mTypeUID;
    }
    if ( mesh )
    {
      if ( (mData || (mData = (Illusion::Buffer *)mesh->mIndexBufferHandle.mData) != 0i64)
        && !mData[1].mResourceHandles.UFG::qResourceData::mNode.mNext )
      {
        v23 = mData[1].mTypeUID;
        v24 = UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
        if ( v24 > 4095 )
          v24 = 4095;
        v20 = 0;
        Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v24] = v23;
      }
      p_mData = &mesh->mVertexBufferHandles[0].mData;
      v26 = 4i64;
      do
      {
        v27 = *p_mData;
        if ( *p_mData && !v27[2].mNode.mChild[0] )
        {
          v28 = (unsigned int)v27[2].mNode.mChild[1];
          v29 = UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
          if ( v29 > 4095 )
            v29 = 4095;
          v20 = 0;
          Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v29] = v28;
        }
        p_mData += 4;
        --v26;
      }
      while ( v26 );
    }
    v30 = 0;
    if ( material )
    {
      mNumParams = material->mNumParams;
      if ( mNumParams )
      {
        p_mNext = &material[1].mResourceHandles.UFG::qResourceData::mNode.mNext;
        v33 = mNumParams;
        do
        {
          if ( *((_DWORD *)p_mNext - 10) )
          {
            if ( *((_DWORD *)p_mNext + 2) == -1958479169 )
            {
              v34 = (__int64)*(p_mNext - 1);
              if ( v34 )
              {
                if ( (unsigned int)(*(_DWORD *)p_mNext - 1) <= 0xFFFFFFFD )
                {
                  if ( *(_DWORD *)p_mNext == *(_DWORD *)(v34 + 24) || !*(_QWORD *)(v34 + 296) )
                  {
                    v36 = *(_QWORD *)(v34 + 296);
                    if ( !v36 || *(_DWORD *)(v36 + 24) != *(_DWORD *)(v34 + 304) )
                    {
                      v37 = *(_DWORD *)(v34 + 304);
                      v38 = UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
                      if ( v38 > 4095 )
                        v38 = 4095;
                      v20 = 0;
                      Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[v38] = v37;
                    }
                  }
                  else
                  {
                    v30 = 1;
                  }
                }
              }
            }
          }
          p_mNext += 7;
          --v33;
        }
        while ( v33 );
      }
    }
    if ( v13 && !v30 && v20 == 1 && (_DWORD)v12 != -1 )
      qword_14245AF48[(unsigned int)v12] = v11;
    return v20;
  }
  else
  {
    v13 = 1;
    if ( forced_index_buffer )
    {
      mUID = forced_index_buffer->mNode.mUID;
    }
    else if ( mesh )
    {
      mUID = mesh->mIndexBufferHandle.mNameUID;
    }
    else
    {
      mUID = 0i64;
    }
    if ( instance_buffer )
      v15 = instance_buffer->mNode.mUID;
    else
      v15 = 0;
    v16 = mUID | ((unsigned __int64)v15 << 32);
    if ( material )
      v17 = material->mNode.mUID;
    else
      v17 = 0;
    v18 = v17;
    if ( mesh )
      v18 = (mesh->mVertexBufferHandles[1].mNameUID | ((unsigned __int64)mesh->mVertexBufferHandles[0].mNameUID << 32)) ^ (mesh->mVertexBufferHandles[3].mNameUID | ((unsigned __int64)mesh->mVertexBufferHandles[2].mNameUID << 32)) ^ v17;
    v11 = v16 ^ v18;
    while ( 1 )
    {
      v12 = (v11 >> v5) & 0x7FFF;
      v19 = qword_14245AF48[v12];
      if ( v19 == v11 )
        return 1;
      if ( !v19 )
        goto LABEL_25;
      if ( (unsigned int)++v5 >= 0x31 )
      {
        LODWORD(v12) = -1;
        goto LABEL_25;
      }
    }
  }
}

// File Line: 358
// RVA: 0xA1B860
char __fastcall Illusion::IEnginePlat::IsAnInvalidTextureResourceHandle(
        Illusion::IEnginePlat *this,
        UFG::qGenericResourceHandle *handle)
{
  Illusion::TexturePlat *mData; // rdx
  unsigned int v3; // ebx
  int v4; // eax

  if ( handle->mTypeUID != 0x8B43FABF )
    return 0;
  mData = (Illusion::TexturePlat *)handle->mData;
  if ( (!mData || *(_QWORD *)&mData[1].mPadding[16])
    && *(_DWORD *)(*(_QWORD *)&mData[1].mPadding[16] + 24i64) == *(_DWORD *)&mData[1].mPadding[24] )
  {
    return 0;
  }
  v3 = *(_DWORD *)&mData[1].mPadding[24];
  v4 = UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
  if ( v4 > 4095 )
    v4 = 4095;
  Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[v4] = v3;
  return 1;
}

// File Line: 384
// RVA: 0xA15910
void __fastcall Illusion::EnginePlat::EnginePlat(Illusion::EnginePlat *this)
{
  unsigned __int64 v2; // rax

  this->mMaxGpuFramesInFlight = 1;
  this->mDevice = 0i64;
  this->mContext = 0i64;
  UFG::qMutex::qMutex(&this->mDeferredContextsMutex, &customCaption);
  this->mDeferredContexts.mCapacity = 16;
  this->mDeferredContexts.mpMemoryPool = 0i64;
  v2 = 128i64;
  if ( !is_mul_ok(0x10ui64, 8ui64) )
    v2 = -1i64;
  this->mDeferredContexts.mData = (ID3D11DeviceContext **)UFG::qMalloc(v2, "qCircularArray::mData", 0i64);
  *(_QWORD *)&this->mDeferredContexts.mHeadIndex = -1i64;
  UFG::qMemSet(&this->mIsValidDrawCache, 0, 0x40000u);
}

// File Line: 394
// RVA: 0xA21E20
void __fastcall Illusion::EnginePlat::SetContext(Illusion::EnginePlat *this, ID3D11DeviceContext *context)
{
  _QWORD *v2; // rax
  int v4; // eax
  __int64 v5; // rdi
  ID3D11Device *mDevice; // rcx
  ID3D11DeviceContext *v7; // r9
  unsigned int mHeadIndex; // edx
  int v9; // ecx
  unsigned int mTailIndex; // ecx
  int mCapacity; // r8d
  ID3D11DeviceContext *v12; // [rsp+30h] [rbp+8h] BYREF

  v2 = NtCurrentTeb()->Reserved1[11];
  this->mContext = context;
  *(_QWORD *)(v2[tls_index] + 104i64) = context;
  v4 = UFG::qTaskManager::GetMaxWorkers(&UFG::gTaskManager) + 1;
  if ( v4 > 0 )
  {
    v5 = (unsigned int)v4;
    do
    {
      mDevice = this->mDevice;
      v12 = 0i64;
      ((void (__fastcall *)(ID3D11Device *, _QWORD, ID3D11DeviceContext **))mDevice->vfptr->SOSetTargets)(
        mDevice,
        0i64,
        &v12);
      v7 = v12;
      if ( v12 )
      {
        mHeadIndex = this->mDeferredContexts.mHeadIndex;
        if ( mHeadIndex == -1 )
        {
          v9 = 0;
        }
        else
        {
          mTailIndex = this->mDeferredContexts.mTailIndex;
          v9 = mHeadIndex <= mTailIndex
             ? mTailIndex - mHeadIndex + 1
             : this->mDeferredContexts.mCapacity - mHeadIndex + mTailIndex + 1;
        }
        mCapacity = this->mDeferredContexts.mCapacity;
        if ( v9 < mCapacity )
        {
          if ( v9 )
            this->mDeferredContexts.mTailIndex = (this->mDeferredContexts.mTailIndex + 1) % mCapacity;
          else
            *(_QWORD *)&this->mDeferredContexts.mHeadIndex = 0i64;
          this->mDeferredContexts.mData[this->mDeferredContexts.mTailIndex] = v7;
        }
      }
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 436
// RVA: 0xA177A0
ID3D11DeviceContext *__fastcall Illusion::EnginePlat::AllocDeferredContextBlocking(Illusion::EnginePlat *this)
{
  _RTL_CRITICAL_SECTION *p_mDeferredContextsMutex; // rbx
  __int64 mHeadIndex; // rdx
  unsigned int mTailIndex; // r8d
  int v5; // eax
  int v6; // r9d
  ID3D11DeviceContext **v7; // rsi
  int v8; // r8d
  ID3D11DeviceContext *v9; // rsi

  p_mDeferredContextsMutex = (_RTL_CRITICAL_SECTION *)&this->mDeferredContextsMutex;
  while ( 1 )
  {
    UFG::qMutex::Lock(p_mDeferredContextsMutex);
    mHeadIndex = this->mDeferredContexts.mHeadIndex;
    if ( (_DWORD)mHeadIndex == -1
      || ((mTailIndex = this->mDeferredContexts.mTailIndex,
           v5 = mTailIndex - mHeadIndex,
           (unsigned int)mHeadIndex <= mTailIndex)
        ? (v6 = v5 + 1)
        : (v6 = v5 + this->mDeferredContexts.mCapacity + 1),
          !v6) )
    {
      UFG::qMutex::Unlock(p_mDeferredContextsMutex);
      goto LABEL_16;
    }
    v7 = 0i64;
    v8 = (unsigned int)mHeadIndex <= mTailIndex ? v5 + 1 : v5 + this->mDeferredContexts.mCapacity + 1;
    if ( v8 > 0 )
    {
      v7 = &this->mDeferredContexts.mData[mHeadIndex];
      this->mDeferredContexts.mHeadIndex = (unsigned int)(mHeadIndex + 1) % this->mDeferredContexts.mCapacity;
      if ( v8 == 1 )
        *(_QWORD *)&this->mDeferredContexts.mHeadIndex = -1i64;
    }
    v9 = *v7;
    UFG::qMutex::Unlock(p_mDeferredContextsMutex);
    if ( v9 )
      return v9;
LABEL_16:
    UFG::qSleep(0);
  }
}

// File Line: 450
// RVA: 0xA20F30
void __fastcall Illusion::EnginePlat::ReleaseDeferredContext(Illusion::EnginePlat *this, ID3D11DeviceContext *defcon)
{
  _RTL_CRITICAL_SECTION *p_mDeferredContextsMutex; // rbx
  unsigned int mHeadIndex; // r8d
  int v6; // ecx
  unsigned int mTailIndex; // ecx
  int mCapacity; // r8d

  p_mDeferredContextsMutex = (_RTL_CRITICAL_SECTION *)&this->mDeferredContextsMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mDeferredContextsMutex);
  mHeadIndex = this->mDeferredContexts.mHeadIndex;
  if ( mHeadIndex == -1 )
  {
    v6 = 0;
  }
  else
  {
    mTailIndex = this->mDeferredContexts.mTailIndex;
    if ( mHeadIndex <= mTailIndex )
      v6 = mTailIndex - mHeadIndex + 1;
    else
      v6 = this->mDeferredContexts.mCapacity - mHeadIndex + mTailIndex + 1;
  }
  mCapacity = this->mDeferredContexts.mCapacity;
  if ( v6 < mCapacity )
  {
    if ( v6 )
      this->mDeferredContexts.mTailIndex = (this->mDeferredContexts.mTailIndex + 1) % mCapacity;
    else
      *(_QWORD *)&this->mDeferredContexts.mHeadIndex = 0i64;
    this->mDeferredContexts.mData[this->mDeferredContexts.mTailIndex] = defcon;
  }
  UFG::qMutex::Unlock(p_mDeferredContextsMutex);
}

// File Line: 482
// RVA: 0xA15780
void __fastcall Illusion::AsyncCommandBuilderTask(
        int workerId,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param_stream,
        void *pad1,
        void *pad2)
{
  ID3D11DeviceContext *v6; // rbx

  v6 = Illusion::EnginePlat::AllocDeferredContextBlocking(&Illusion::gEnginePlat);
  *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64) = v6;
  (**(void (__fastcall ***)(_QWORD, ID3D11DeviceContext *))*param_stream)(*param_stream, v6);
  v6->vfptr[38].QueryInterface(v6, 0i64, (void **)(*param_stream + 32i64));
  Illusion::EnginePlat::ReleaseDeferredContext(&Illusion::gEnginePlat, v6);
}

// File Line: 496
// RVA: 0x15AA780
__int64 Illusion::_dynamic_initializer_for__gTaskFunctionDecl_AsyncCommandBuilderTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Illusion::gTaskFunctionDecl_AsyncCommandBuilderTask,
    &Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gTaskFunctionDecl_AsyncCommandBuilderTask__);
}

// File Line: 499
// RVA: 0xA17880
void __fastcall Illusion::AsyncCommandBuilder::BeginAsyncCommandBuilding(Illusion::AsyncCommandBuilder *this)
{
  char *v2; // rdi
  char *v3; // rax
  UFG::qTask *v4; // rdx
  _QWORD *v5; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r8
  char *mAddress; // r9
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax

  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x18u, 0x10u);
  *(_QWORD *)v2 = this;
  v3 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v4 = (UFG::qTask *)v3;
  if ( v3 )
  {
    *(_QWORD *)v3 = v3;
    *((_QWORD *)v3 + 1) = v3;
    v5 = v3 + 16;
    *v5 = v5;
    v5[1] = v5;
    mSpuElf = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mSpuElf;
    mTaskFunctionSPU = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mTaskFunctionSPU;
    mTaskFunctionPPU = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mTaskFunctionPPU;
    mTaskFunctionOffload = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mTaskFunctionOffload;
    if ( !Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mCurrentSPUEnabled )
    {
      mSpuElf = 0i64;
      mTaskFunctionSPU = 0i64;
      mTaskFunctionOffload = 0i64;
    }
    v4->mTaskGroup = 0i64;
    v4->mFlags = 2;
    v4->mSyncVars.i64 = 0i64;
    v4->mSyncVars.v.mDependents = 0i64;
    v4->mFunctionDeclData = &Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask;
    if ( mSpuElf )
      mAddress = mSpuElf->mAddress;
    else
      mAddress = 0i64;
    v4->mSPUElfAddress = mAddress;
    v4->mSPUFunction = mTaskFunctionSPU;
    v4->mPPUFunction = mTaskFunctionPPU;
    v4->mParam0 = v2;
    v4->mParam1 = 0i64;
    v4->mParam2 = 0i64;
    v4->mParam3 = 0i64;
    if ( mTaskFunctionOffload )
    {
      v4->mFlags = 130;
      v4->mOffloadThread = 0;
    }
  }
  mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
  mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  mPrev->mNext = v4;
  v4->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
  v4->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
  mSingleFrameTasks->mNode.mPrev = v4;
  this->mTask = v4;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v4);
}

// File Line: 513
// RVA: 0xA1A930
void __fastcall Illusion::AsyncCommandBuilder::FinalizeAsyncCommandBuilding(Illusion::AsyncCommandBuilder *this)
{
  UFG::qTask *mTask; // rdx
  __int64 v3; // rdi
  _QWORD *v4; // rdi
  void *mCommandList; // rdx
  void *v6; // rcx

  mTask = this->mTask;
  if ( mTask )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, mTask);
    v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
    this->mTask = 0i64;
    v4 = (_QWORD *)(v3 + 104);
    if ( (*(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)*v4 + 896i64))(*v4) == 1 )
    {
      Illusion::RenderThreadManager::AddCommand(
        &Illusion::gRenderThreadManager,
        RTCMD_EXECUTE_DEFERRED_COMMANDS,
        (UFG::allocator::free_link *)&this->mCommandList,
        0i64,
        0i64);
    }
    else
    {
      mCommandList = this->mCommandList;
      if ( mCommandList )
        (*(void (__fastcall **)(_QWORD, void *, _QWORD))(*(_QWORD *)*v4 + 464i64))(*v4, mCommandList, 0i64);
      v6 = this->mCommandList;
      if ( v6 )
      {
        (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 16i64))(v6);
        this->mCommandList = 0i64;
      }
    }
    this->vfptr->PostSyncCommandList(this);
  }
}

// File Line: 554
// RVA: 0xA15800
void __fastcall Illusion::AsyncD3DCreationTask(
        int workerId,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param_stream,
        void *pad1,
        void *pad2)
{
  (**(void (__fastcall ***)(_QWORD, UFG::qMemoryStreamer *))*param_stream)(*param_stream, memory_streamer);
}

// File Line: 561
// RVA: 0x15AA7B0
__int64 Illusion::_dynamic_initializer_for__gTaskFunctionDecl_AsyncD3DCreationTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Illusion::gTaskFunctionDecl_AsyncD3DCreationTask,
    &Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gTaskFunctionDecl_AsyncD3DCreationTask__);
}

// File Line: 564
// RVA: 0xA179B0
void __fastcall Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(Illusion::AsyncD3DCreationTask *this)
{
  char *v2; // rdi
  char *v3; // rax
  UFG::qTask *v4; // rdx
  _QWORD *v5; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r8
  char *mAddress; // r9
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax

  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x18u, 0x10u);
  *(_QWORD *)v2 = this;
  v3 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v4 = (UFG::qTask *)v3;
  if ( v3 )
  {
    *(_QWORD *)v3 = v3;
    *((_QWORD *)v3 + 1) = v3;
    v5 = v3 + 16;
    *v5 = v5;
    v5[1] = v5;
    mSpuElf = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mSpuElf;
    mTaskFunctionSPU = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mTaskFunctionSPU;
    mTaskFunctionPPU = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mTaskFunctionPPU;
    mTaskFunctionOffload = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mTaskFunctionOffload;
    if ( !Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mCurrentSPUEnabled )
    {
      mSpuElf = 0i64;
      mTaskFunctionSPU = 0i64;
      mTaskFunctionOffload = 0i64;
    }
    v4->mTaskGroup = 0i64;
    v4->mFlags = 2;
    v4->mSyncVars.i64 = 0i64;
    v4->mSyncVars.v.mDependents = 0i64;
    v4->mFunctionDeclData = &Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask;
    if ( mSpuElf )
      mAddress = mSpuElf->mAddress;
    else
      mAddress = 0i64;
    v4->mSPUElfAddress = mAddress;
    v4->mSPUFunction = mTaskFunctionSPU;
    v4->mPPUFunction = mTaskFunctionPPU;
    v4->mParam0 = v2;
    v4->mParam1 = 0i64;
    v4->mParam2 = 0i64;
    v4->mParam3 = 0i64;
    if ( mTaskFunctionOffload )
    {
      v4->mFlags = 130;
      v4->mOffloadThread = 0;
    }
  }
  mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
  mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  mPrev->mNext = v4;
  v4->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
  v4->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
  mSingleFrameTasks->mNode.mPrev = v4;
  this->mTask = v4;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v4);
}

// File Line: 577
// RVA: 0xA1A9F0
void __fastcall Illusion::AsyncD3DCreationTask::FinalizeAsyncCreationTask(Illusion::AsyncD3DCreationTask *this)
{
  UFG::qTask *mTask; // rdx
  Illusion::AsyncD3DCreationTaskVtbl *vfptr; // rax

  mTask = this->mTask;
  if ( mTask )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, mTask);
    vfptr = this->vfptr;
    this->mTask = 0i64;
    vfptr->PostSyncCreationTask(this);
  }
}

// File Line: 602
// RVA: 0xA1C4D0
void __fastcall Illusion::FrameWriteMemoryPlat::Lock(Illusion::FrameWriteMemoryPlat *this, unsigned int frame_index)
{
  __int64 v3; // rax
  ID3D11Buffer *v5; // rdx
  void *v6; // rax
  __int64 v7[3]; // [rsp+30h] [rbp-18h] BYREF

  v7[1] = 0i64;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  v7[0] = 0i64;
  v5 = this->mBuffer[frame_index];
  this->mCurrLockedBuffer = v5;
  (*(void (__fastcall **)(_QWORD, ID3D11Buffer *, _QWORD, __int64, _DWORD, __int64 *))(**(_QWORD **)(v3 + 104) + 112i64))(
    *(_QWORD *)(v3 + 104),
    v5,
    0i64,
    4i64,
    0,
    v7);
  v6 = (void *)v7[0];
  this->mFrameMemoryBufferIndex = frame_index;
  this->mLockData = v6;
}

// File Line: 638
// RVA: 0xA22A10
void __fastcall Illusion::FrameWriteMemoryPlat::Unlock(Illusion::FrameWriteMemoryPlat *this)
{
  ID3D11Buffer *mCurrLockedBuffer; // rdx
  __int64 v3; // rcx

  mCurrLockedBuffer = this->mCurrLockedBuffer;
  v3 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
  (*(void (__fastcall **)(__int64, ID3D11Buffer *, _QWORD))(*(_QWORD *)v3 + 120i64))(v3, mCurrLockedBuffer, 0i64);
  this->mLockData = 0i64;
  this->mCurrLockedBuffer = 0i64;
}

