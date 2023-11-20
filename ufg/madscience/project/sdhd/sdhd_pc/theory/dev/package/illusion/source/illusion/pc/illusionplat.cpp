// File Line: 61
// RVA: 0x15AA610
__int64 Illusion::_dynamic_initializer_for__gEnginePlat__()
{
  Illusion::EnginePlat::EnginePlat(&Illusion::gEnginePlat);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gEnginePlat__);
}

// File Line: 92
// RVA: 0xA22E20
void __fastcall Illusion::IEnginePlat::WaitUntilGPUDone(Illusion::IEnginePlat *this)
{
  unsigned __int64 v1; // rbp
  void *v2; // rbx
  unsigned __int64 v3; // rax
  __int64 v4; // rdi
  __int64 v5; // rsi
  unsigned __int64 v6; // rax
  void *data1; // [rsp+20h] [rbp-28h]
  __int64 v8; // [rsp+58h] [rbp+10h]
  __int64 v9; // [rsp+60h] [rbp+18h]

  v1 = UFG::qGetTicks();
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  v2 = UFG::qGetCurrentThreadID();
  v3 = UFG::qGetMainThreadID();
  v4 = tls_index;
  if ( v2 != (void *)v3
    || (*(unsigned int (**)(void))(**(_QWORD **)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64)
                                 + 896i64))() != 1 )
  {
    v9 = 0i64;
    v8 = 0i64;
    LODWORD(v9) = 0;
    if ( ((signed int (__fastcall *)(ID3D11Device *, __int64 *, __int64 *))UFG::gD3D11Device->vfptr->OMSetRenderTargets)(
           UFG::gD3D11Device,
           &v9,
           &v8) >= 0 )
    {
      v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + v4);
      (*(void (__fastcall **)(_QWORD, __int64))(**(_QWORD **)(v5 + 104) + 224i64))(*(_QWORD *)(v5 + 104), v8);
      if ( (*(unsigned int (__fastcall **)(_QWORD, __int64, _QWORD, _QWORD, _DWORD))(**(_QWORD **)(v5 + 104) + 232i64))(
             *(_QWORD *)(v5 + 104),
             v8,
             0i64,
             0i64,
             0) == 1 )
      {
        do
        {
          UFG::qSleep(0);
          LODWORD(data1) = 0;
        }
        while ( (*(unsigned int (__fastcall **)(_QWORD, __int64, _QWORD, _QWORD, void *))(**(_QWORD **)(v5 + 104)
                                                                                        + 232i64))(
                  *(_QWORD *)(v5 + 104),
                  v8,
                  0i64,
                  0i64,
                  data1) == 1 );
      }
    }
    if ( v8 )
      (*(void (**)(void))(*(_QWORD *)v8 + 16i64))();
  }
  else
  {
    Illusion::RenderThreadManager::AddCommand(&Illusion::gRenderThreadManager, RTCMD_WAIT_FOR_GPU, 0i64, 0i64, 0i64);
    UFG::qEvent::Wait(&stru_1424527E8);
  }
  v6 = UFG::qGetTicks();
  UFG::qGetTickTime(v1, v6);
}

// File Line: 131
// RVA: 0xA1BCE0
__int64 __fastcall Illusion::IEnginePlat::IsValidDrawCall(Illusion::IEnginePlat *this, Illusion::rMesh *rmesh, Illusion::rMaterial *rmaterial, Illusion::Buffer *forced_index_buffer, Illusion::Buffer *instance_buffer)
{
  Illusion::Buffer *v5; // rdi
  Illusion::rMesh *v6; // rsi
  unsigned __int8 v7; // cl
  unsigned int v8; // ebx
  signed int v9; // eax
  unsigned int v10; // ebx
  signed int v11; // eax
  UFG::qResourceData **v12; // rdi
  signed __int64 v13; // rsi
  UFG::qResourceData *v14; // rax
  unsigned int v15; // ebx
  signed int v16; // eax

  v5 = forced_index_buffer;
  v6 = rmesh;
  v7 = 1;
  if ( instance_buffer && !instance_buffer[1].mResourceHandles.mNode.mNext )
  {
    v8 = instance_buffer[1].mTypeUID;
    v9 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
    if ( v9 > 4095 )
      v9 = 4095;
    v7 = 0;
    Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v9] = v8;
  }
  if ( v6 )
  {
    if ( v5 || (v5 = (Illusion::Buffer *)v6->mIndexBufferHandle.mData) != 0i64 )
    {
      if ( !v5[1].mResourceHandles.mNode.mNext )
      {
        v10 = v5[1].mTypeUID;
        v11 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
        if ( v11 > 4095 )
          v11 = 4095;
        v7 = 0;
        Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v11] = v10;
      }
    }
    v12 = &v6->mVertexBufferHandles[0].mData;
    v13 = 4i64;
    do
    {
      v14 = *v12;
      if ( *v12 && !v14[2].mNode.mChild[0] )
      {
        v15 = (unsigned int)v14[2].mNode.mChild[1];
        v16 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
        if ( v16 > 4095 )
          v16 = 4095;
        v7 = 0;
        Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v16] = v15;
      }
      v12 += 4;
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
  unsigned int v3; // eax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **v4; // rdi
  __int64 v5; // rsi
  __int64 v6; // rax
  __int64 v7; // rdx
  unsigned int v8; // ebx
  signed int v9; // eax

  v2 = 1;
  if ( material )
  {
    v3 = material->mNumParams;
    if ( v3 )
    {
      v4 = &material[1].mResourceHandles.mNode.mNext;
      v5 = v3;
      do
      {
        if ( *((_DWORD *)v4 - 10) )
        {
          if ( *((_DWORD *)v4 + 2) == -1958479169 )
          {
            v6 = (__int64)*(v4 - 1);
            if ( v6 )
            {
              if ( (unsigned int)(*(_DWORD *)v4 - 1) <= 0xFFFFFFFD
                && (*(_DWORD *)v4 == *(_DWORD *)(v6 + 24) || !*(_QWORD *)(v6 + 296)) )
              {
                v7 = *(_QWORD *)(v6 + 296);
                if ( !v7 || *(_DWORD *)(v7 + 24) != *(_DWORD *)(v6 + 304) )
                {
                  v8 = *(_DWORD *)(v6 + 304);
                  v9 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
                  if ( v9 > 4095 )
                    v9 = 4095;
                  v2 = 0;
                  Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[v9] = v8;
                }
              }
            }
          }
        }
        v4 += 7;
        --v5;
      }
      while ( v5 );
    }
  }
  return v2;
}

// File Line: 231
// RVA: 0xA1B9D0
char __fastcall Illusion::IEnginePlat::IsValidDrawCall(Illusion::IEnginePlat *this, Illusion::Mesh *mesh, Illusion::Material *material, Illusion::Buffer *forced_index_buffer, Illusion::Buffer *instance_buffer)
{
  int v5; // er10
  Illusion::Buffer *v6; // rbp
  Illusion::Mesh *v7; // rdi
  Illusion::Material *v8; // r14
  __int64 v9; // rax
  _BYTE *v10; // rax
  unsigned __int64 v11; // r15
  signed __int64 v12; // rsi
  char v13; // r13
  __int64 v14; // rax
  unsigned int v15; // ecx
  unsigned __int64 v16; // r8
  unsigned int v17; // eax
  unsigned __int64 v18; // r15
  __int64 v19; // rcx
  char v20; // r8
  unsigned int v21; // ebx
  signed int v22; // eax
  unsigned int v23; // ebx
  signed int v24; // eax
  UFG::qResourceData **v25; // rdi
  signed __int64 v26; // rbp
  UFG::qResourceData *v27; // rax
  unsigned int v28; // ebx
  signed int v29; // eax
  char v30; // r12
  unsigned int v31; // eax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **v32; // rdi
  __int64 v33; // rbp
  __int64 v34; // rcx
  char result; // al
  __int64 v36; // rdx
  unsigned int v37; // ebx
  signed int v38; // eax
  unsigned __int64 v39; // [rsp+60h] [rbp+18h]

  v5 = 0;
  v6 = forced_index_buffer;
  v7 = mesh;
  v8 = material;
  if ( material
    && ((v9 = material->mMaterialUser.mOffset) == 0 ? (v10 = 0i64) : (v10 = (char *)&material->mMaterialUser + v9),
        *v10 & 0x20) )
  {
    v11 = v39;
    LODWORD(v12) = v39;
    v13 = 0;
LABEL_25:
    v20 = 1;
    if ( instance_buffer && !instance_buffer[1].mResourceHandles.mNode.mNext )
    {
      v21 = instance_buffer[1].mTypeUID;
      v22 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
      if ( v22 > 4095 )
        v22 = 4095;
      v20 = 0;
      Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v22] = v21;
    }
    if ( v7 )
    {
      if ( v6 || (v6 = (Illusion::Buffer *)v7->mIndexBufferHandle.mData) != 0i64 )
      {
        if ( !v6[1].mResourceHandles.mNode.mNext )
        {
          v23 = v6[1].mTypeUID;
          v24 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
          if ( v24 > 4095 )
            v24 = 4095;
          v20 = 0;
          Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v24] = v23;
        }
      }
      v25 = &v7->mVertexBufferHandles[0].mData;
      v26 = 4i64;
      do
      {
        v27 = *v25;
        if ( *v25 && !v27[2].mNode.mChild[0] )
        {
          v28 = (unsigned int)v27[2].mNode.mChild[1];
          v29 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gNumHighPriorityUIDs) - 1;
          if ( v29 > 4095 )
            v29 = 4095;
          v20 = 0;
          Illusion::gBufferD3DResourceInventory.mHighPriorityUIDs[v29] = v28;
        }
        v25 += 4;
        --v26;
      }
      while ( v26 );
    }
    v30 = 0;
    if ( v8 )
    {
      v31 = v8->mNumParams;
      if ( v31 )
      {
        v32 = &v8[1].mResourceHandles.mNode.mNext;
        v33 = v31;
        do
        {
          if ( *((_DWORD *)v32 - 10) )
          {
            if ( *((_DWORD *)v32 + 2) == -1958479169 )
            {
              v34 = (__int64)*(v32 - 1);
              if ( v34 )
              {
                if ( (unsigned int)(*(_DWORD *)v32 - 1) <= 0xFFFFFFFD )
                {
                  if ( *(_DWORD *)v32 != *(_DWORD *)(v34 + 24) && *(_QWORD *)(v34 + 296) )
                  {
                    v30 = 1;
                  }
                  else
                  {
                    v36 = *(_QWORD *)(v34 + 296);
                    if ( !v36 || *(_DWORD *)(v36 + 24) != *(_DWORD *)(v34 + 304) )
                    {
                      v37 = *(_DWORD *)(v34 + 304);
                      v38 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
                      if ( v38 > 4095 )
                        v38 = 4095;
                      v20 = 0;
                      Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[v38] = v37;
                    }
                  }
                }
              }
            }
          }
          v32 += 7;
          --v33;
        }
        while ( v33 );
      }
    }
    if ( v13 && !v30 && v20 == 1 && (_DWORD)v12 != -1 )
      qword_14245AF48[(unsigned int)v12] = v11;
    result = v20;
  }
  else
  {
    v13 = 1;
    if ( forced_index_buffer )
    {
      v14 = forced_index_buffer->mNode.mUID;
    }
    else if ( mesh )
    {
      v14 = mesh->mIndexBufferHandle.mNameUID;
    }
    else
    {
      v14 = 0i64;
    }
    if ( instance_buffer )
      v15 = instance_buffer->mNode.mUID;
    else
      v15 = 0;
    v16 = v14 | ((unsigned __int64)v15 << 32);
    if ( v8 )
      v17 = v8->mNode.mUID;
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
        break;
      if ( !v19 )
        goto LABEL_25;
      if ( (unsigned int)++v5 >= 0x31 )
      {
        LODWORD(v12) = -1;
        goto LABEL_25;
      }
    }
    result = 1;
  }
  return result;
}

// File Line: 358
// RVA: 0xA1B860
char __fastcall Illusion::IEnginePlat::IsAnInvalidTextureResourceHandle(Illusion::IEnginePlat *this, UFG::qGenericResourceHandle *handle)
{
  Illusion::TexturePlat *v2; // rdx
  unsigned int v3; // ebx
  signed int v4; // eax

  if ( handle->mTypeUID != 0x8B43FABF )
    return 0;
  v2 = (Illusion::TexturePlat *)handle->mData;
  if ( (!v2 || *(_QWORD *)&v2[1].mPadding[16])
    && *(_DWORD *)(*(_QWORD *)&v2[1].mPadding[16] + 24i64) == *(_DWORD *)&v2[1].mPadding[24] )
  {
    return 0;
  }
  v3 = *(_DWORD *)&v2[1].mPadding[24];
  v4 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
  if ( v4 > 4095 )
    v4 = 4095;
  Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[v4] = v3;
  return 1;
}

// File Line: 384
// RVA: 0xA15910
void __fastcall Illusion::EnginePlat::EnginePlat(Illusion::EnginePlat *this)
{
  Illusion::EnginePlat *v1; // rbx
  unsigned __int64 v2; // rax

  v1 = this;
  this->mMaxGpuFramesInFlight = 1;
  this->mDevice = 0i64;
  this->mContext = 0i64;
  UFG::qMutex::qMutex(&this->mDeferredContextsMutex, &customWorldMapCaption);
  v1->mDeferredContexts.mCapacity = 16;
  v1->mDeferredContexts.mpMemoryPool = 0i64;
  v2 = 128i64;
  if ( !is_mul_ok(0x10ui64, 8ui64) )
    v2 = -1i64;
  v1->mDeferredContexts.mData = (ID3D11DeviceContext **)UFG::qMalloc(v2, "qCircularArray::mData", 0i64);
  *(_QWORD *)&v1->mDeferredContexts.mHeadIndex = -1i64;
  UFG::qMemSet(&v1->mIsValidDrawCache, 0, 0x40000u);
}

// File Line: 394
// RVA: 0xA21E20
void __fastcall Illusion::EnginePlat::SetContext(Illusion::EnginePlat *this, ID3D11DeviceContext *context)
{
  _QWORD *v2; // rax
  Illusion::EnginePlat *v3; // rbx
  int v4; // eax
  __int64 v5; // rdi
  ID3D11Device *v6; // rcx
  __int64 v7; // r9
  unsigned int v8; // edx
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // er8
  __int64 v12; // [rsp+30h] [rbp+8h]

  v2 = NtCurrentTeb()->Reserved1[11];
  this->mContext = context;
  v3 = this;
  *(_QWORD *)(v2[tls_index] + 104i64) = context;
  v4 = UFG::qTaskManager::GetMaxWorkers(&UFG::gTaskManager) + 1;
  if ( v4 > 0 )
  {
    v5 = (unsigned int)v4;
    do
    {
      v6 = v3->mDevice;
      v12 = 0i64;
      ((void (__fastcall *)(ID3D11Device *, _QWORD, __int64 *))v6->vfptr->SOSetTargets)(v6, 0i64, &v12);
      v7 = v12;
      if ( v12 )
      {
        v8 = v3->mDeferredContexts.mHeadIndex;
        if ( v8 == -1 )
        {
          v9 = 0;
        }
        else
        {
          v10 = v3->mDeferredContexts.mTailIndex;
          v9 = v8 <= v10 ? v10 - v8 + 1 : v3->mDeferredContexts.mCapacity - v8 + v10 + 1;
        }
        v11 = v3->mDeferredContexts.mCapacity;
        if ( v9 < v11 )
        {
          if ( v9 )
            v3->mDeferredContexts.mTailIndex = (v3->mDeferredContexts.mTailIndex + 1) % v11;
          else
            *(_QWORD *)&v3->mDeferredContexts.mHeadIndex = 0i64;
          v3->mDeferredContexts.mData[v3->mDeferredContexts.mTailIndex] = (ID3D11DeviceContext *)v7;
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
  Illusion::EnginePlat *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  __int64 v3; // rdx
  unsigned int v4; // er8
  int v5; // eax
  int v6; // er9
  ID3D11DeviceContext **v7; // rsi
  int v8; // er8
  ID3D11DeviceContext *v9; // rsi

  v1 = this;
  v2 = (_RTL_CRITICAL_SECTION *)&this->mDeferredContextsMutex;
  while ( 1 )
  {
    UFG::qMutex::Lock(v2);
    v3 = v1->mDeferredContexts.mHeadIndex;
    if ( (_DWORD)v3 == -1
      || ((v4 = v1->mDeferredContexts.mTailIndex, v5 = v1->mDeferredContexts.mTailIndex - v3, (unsigned int)v3 <= v4) ? (v6 = v5 + 1) : (v6 = v5 + v1->mDeferredContexts.mCapacity + 1),
          !v6) )
    {
      UFG::qMutex::Unlock(v2);
      goto LABEL_16;
    }
    v7 = 0i64;
    v8 = (unsigned int)v3 <= v4 ? v5 + 1 : v5 + v1->mDeferredContexts.mCapacity + 1;
    if ( v8 > 0 )
    {
      v7 = &v1->mDeferredContexts.mData[v3];
      v1->mDeferredContexts.mHeadIndex = (unsigned int)(v3 + 1) % v1->mDeferredContexts.mCapacity;
      if ( v8 == 1 )
        *(_QWORD *)&v1->mDeferredContexts.mHeadIndex = -1i64;
    }
    v9 = *v7;
    UFG::qMutex::Unlock(v2);
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
  ID3D11DeviceContext *v2; // rsi
  Illusion::EnginePlat *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  unsigned int v5; // er8
  int v6; // ecx
  unsigned int v7; // ecx
  int v8; // er8

  v2 = defcon;
  v3 = this;
  v4 = (_RTL_CRITICAL_SECTION *)&this->mDeferredContextsMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mDeferredContextsMutex);
  v5 = v3->mDeferredContexts.mHeadIndex;
  if ( v5 == -1 )
  {
    v6 = 0;
  }
  else
  {
    v7 = v3->mDeferredContexts.mTailIndex;
    if ( v5 <= v7 )
      v6 = v7 - v5 + 1;
    else
      v6 = v3->mDeferredContexts.mCapacity - v5 + v7 + 1;
  }
  v8 = v3->mDeferredContexts.mCapacity;
  if ( v6 < v8 )
  {
    if ( v6 )
      v3->mDeferredContexts.mTailIndex = (v3->mDeferredContexts.mTailIndex + 1) % v8;
    else
      *(_QWORD *)&v3->mDeferredContexts.mHeadIndex = 0i64;
    v3->mDeferredContexts.mData[v3->mDeferredContexts.mTailIndex] = v2;
  }
  UFG::qMutex::Unlock(v4);
}

// File Line: 482
// RVA: 0xA15780
void __fastcall Illusion::AsyncCommandBuilderTask(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad1, void *pad2)
{
  _QWORD *v5; // rdi
  ID3D11DeviceContext *v6; // rbx

  v5 = param_stream;
  v6 = Illusion::EnginePlat::AllocDeferredContextBlocking(&Illusion::gEnginePlat);
  *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64) = v6;
  (**(void (__fastcall ***)(_QWORD, ID3D11DeviceContext *))*v5)(*v5, v6);
  v6->vfptr[38].QueryInterface((IUnknown *)&v6->vfptr, 0i64, (void **)(*v5 + 32i64));
  Illusion::EnginePlat::ReleaseDeferredContext(&Illusion::gEnginePlat, v6);
}

// File Line: 496
// RVA: 0x15AA780
__int64 Illusion::_dynamic_initializer_for__gTaskFunctionDecl_AsyncCommandBuilderTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Illusion::gTaskFunctionDecl_AsyncCommandBuilderTask,
    &Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gTaskFunctionDecl_AsyncCommandBuilderTask__);
}

// File Line: 499
// RVA: 0xA17880
void __fastcall Illusion::AsyncCommandBuilder::BeginAsyncCommandBuilding(Illusion::AsyncCommandBuilder *this)
{
  Illusion::AsyncCommandBuilder *v1; // rbx
  char *v2; // rax
  char *v3; // rdi
  char *v4; // rax
  UFG::qTask *v5; // rdx
  _QWORD *v6; // rax
  UFG::qSpuElf *v7; // rax
  void (__fastcall *v8)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *v9)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v10)(void *, void *, void *, void *); // r8
  char *v11; // r9
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v12; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v13; // rax

  v1 = this;
  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x18u, 0x10u);
  v3 = v2;
  *(_QWORD *)v2 = v1;
  v4 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v5 = (UFG::qTask *)v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    v6 = v4 + 16;
    *v6 = v6;
    v6[1] = v6;
    v7 = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mSpuElf;
    v8 = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mTaskFunctionSPU;
    v9 = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mTaskFunctionPPU;
    v10 = Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mTaskFunctionOffload;
    if ( !Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask.mCurrentSPUEnabled )
    {
      v7 = 0i64;
      v8 = 0i64;
      v10 = 0i64;
    }
    v5->mTaskGroup = 0i64;
    v5->mFlags = 2;
    v5->mSyncVars.i64 = 0i64;
    v5->mSyncVars.v.mDependents = 0i64;
    v5->mFunctionDeclData = &Illusion::gTaskFunctionDeclData_AsyncCommandBuilderTask;
    if ( v7 )
      v11 = v7->mAddress;
    else
      v11 = 0i64;
    v5->mSPUElfAddress = v11;
    v5->mSPUFunction = v8;
    v5->mPPUFunction = v9;
    v5->mParam0 = v3;
    v5->mParam1 = 0i64;
    v5->mParam2 = 0i64;
    v5->mParam3 = 0i64;
    if ( v10 )
    {
      v5->mFlags = 130;
      v5->mOffloadThread = 0;
    }
  }
  v12 = UFG::gTaskManager.mSingleFrameTasks;
  v13 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v13->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v5->mPrev;
  v5->mPrev = v13;
  v5->mNext = &v12->mNode;
  v12->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v5->mPrev;
  v1->mTask = v5;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v5);
}

// File Line: 513
// RVA: 0xA1A930
void __fastcall Illusion::AsyncCommandBuilder::FinalizeAsyncCommandBuilding(Illusion::AsyncCommandBuilder *this)
{
  UFG::qTask *v1; // rdx
  Illusion::AsyncCommandBuilder *v2; // rbx
  __int64 v3; // rdi
  _QWORD *v4; // rdi
  void *v5; // rdx
  void *v6; // rcx

  v1 = this->mTask;
  v2 = this;
  if ( v1 )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v1);
    v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
    v2->mTask = 0i64;
    v4 = (_QWORD *)(v3 + 104);
    if ( (*(unsigned int (**)(void))(*(_QWORD *)*v4 + 896i64))() == 1 )
    {
      Illusion::RenderThreadManager::AddCommand(
        &Illusion::gRenderThreadManager,
        RTCMD_EXECUTE_DEFERRED_COMMANDS,
        &v2->mCommandList,
        0i64,
        0i64);
    }
    else
    {
      v5 = v2->mCommandList;
      if ( v5 )
        (*(void (__fastcall **)(_QWORD, void *, _QWORD))(*(_QWORD *)*v4 + 464i64))(*v4, v5, 0i64);
      v6 = v2->mCommandList;
      if ( v6 )
      {
        (*(void (**)(void))(*(_QWORD *)v6 + 16i64))();
        v2->mCommandList = 0i64;
      }
    }
    v2->vfptr->PostSyncCommandList(v2);
  }
}

// File Line: 554
// RVA: 0xA15800
void __fastcall Illusion::AsyncD3DCreationTask(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad1, void *pad2)
{
  (***(void (__fastcall ****)(_QWORD, UFG::qMemoryStreamer *, void *, void *))param_stream)(
    *(_QWORD *)param_stream,
    memory_streamer,
    param_stream,
    pad1);
}

// File Line: 561
// RVA: 0x15AA7B0
__int64 Illusion::_dynamic_initializer_for__gTaskFunctionDecl_AsyncD3DCreationTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Illusion::gTaskFunctionDecl_AsyncD3DCreationTask,
    &Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gTaskFunctionDecl_AsyncD3DCreationTask__);
}

// File Line: 564
// RVA: 0xA179B0
void __fastcall Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(Illusion::AsyncD3DCreationTask *this)
{
  Illusion::AsyncD3DCreationTask *v1; // rbx
  char *v2; // rax
  char *v3; // rdi
  char *v4; // rax
  UFG::qTask *v5; // rdx
  _QWORD *v6; // rax
  UFG::qSpuElf *v7; // rax
  void (__fastcall *v8)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *v9)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v10)(void *, void *, void *, void *); // r8
  char *v11; // r9
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v12; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v13; // rax

  v1 = this;
  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x18u, 0x10u);
  v3 = v2;
  *(_QWORD *)v2 = v1;
  v4 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v5 = (UFG::qTask *)v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    v6 = v4 + 16;
    *v6 = v6;
    v6[1] = v6;
    v7 = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mSpuElf;
    v8 = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mTaskFunctionSPU;
    v9 = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mTaskFunctionPPU;
    v10 = Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mTaskFunctionOffload;
    if ( !Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask.mCurrentSPUEnabled )
    {
      v7 = 0i64;
      v8 = 0i64;
      v10 = 0i64;
    }
    v5->mTaskGroup = 0i64;
    v5->mFlags = 2;
    v5->mSyncVars.i64 = 0i64;
    v5->mSyncVars.v.mDependents = 0i64;
    v5->mFunctionDeclData = &Illusion::gTaskFunctionDeclData_AsyncD3DCreationTask;
    if ( v7 )
      v11 = v7->mAddress;
    else
      v11 = 0i64;
    v5->mSPUElfAddress = v11;
    v5->mSPUFunction = v8;
    v5->mPPUFunction = v9;
    v5->mParam0 = v3;
    v5->mParam1 = 0i64;
    v5->mParam2 = 0i64;
    v5->mParam3 = 0i64;
    if ( v10 )
    {
      v5->mFlags = 130;
      v5->mOffloadThread = 0;
    }
  }
  v12 = UFG::gTaskManager.mSingleFrameTasks;
  v13 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v13->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v5->mPrev;
  v5->mPrev = v13;
  v5->mNext = &v12->mNode;
  v12->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v5->mPrev;
  v1->mTask = v5;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v5);
}

// File Line: 577
// RVA: 0xA1A9F0
void __fastcall Illusion::AsyncD3DCreationTask::FinalizeAsyncCreationTask(Illusion::AsyncD3DCreationTask *this)
{
  UFG::qTask *v1; // rdx
  Illusion::AsyncD3DCreationTask *v2; // rbx
  Illusion::AsyncD3DCreationTaskVtbl *v3; // rax

  v1 = this->mTask;
  v2 = this;
  if ( v1 )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v1);
    v3 = v2->vfptr;
    v2->mTask = 0i64;
    v3->PostSyncCreationTask(v2);
  }
}

// File Line: 602
// RVA: 0xA1C4D0
void __fastcall Illusion::FrameWriteMemoryPlat::Lock(Illusion::FrameWriteMemoryPlat *this, unsigned int frame_index)
{
  Illusion::FrameWriteMemoryPlat *v2; // rbx
  __int64 v3; // rax
  unsigned int v4; // edi
  int v5; // ST20_4
  ID3D11Buffer *v6; // rdx
  void *v7; // rax
  __int128 v8; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  v8 = 0ui64;
  v4 = frame_index;
  v5 = 0;
  v6 = this->mBuffer[frame_index];
  this->mCurrLockedBuffer = v6;
  (*(void (__fastcall **)(_QWORD, ID3D11Buffer *, _QWORD, signed __int64, int, __int128 *))(**(_QWORD **)(v3 + 104)
                                                                                          + 112i64))(
    *(_QWORD *)(v3 + 104),
    v6,
    0i64,
    4i64,
    v5,
    &v8);
  v7 = (void *)v8;
  v2->mFrameMemoryBufferIndex = v4;
  v2->mLockData = v7;
}

// File Line: 638
// RVA: 0xA22A10
void __fastcall Illusion::FrameWriteMemoryPlat::Unlock(Illusion::FrameWriteMemoryPlat *this)
{
  Illusion::FrameWriteMemoryPlat *v1; // rbx
  ID3D11Buffer *v2; // rdx
  __int64 v3; // rcx

  v1 = this;
  v2 = this->mCurrLockedBuffer;
  v3 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
  (*(void (__fastcall **)(__int64, ID3D11Buffer *, _QWORD))(*(_QWORD *)v3 + 120i64))(v3, v2, 0i64);
  v1->mLockData = 0i64;
  v1->mCurrLockedBuffer = 0i64;
}

