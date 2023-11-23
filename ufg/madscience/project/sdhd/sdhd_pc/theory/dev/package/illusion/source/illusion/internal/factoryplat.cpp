// File Line: 116
// RVA: 0xA1CC00
UFG::qMemoryPool *__fastcall Illusion::Factory::NewBuffer(
        const char *name,
        unsigned int name_uid,
        unsigned int byte_size,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *alloc_name,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v10; // rdi
  const char *v11; // rbx
  __int64 mNumMemStructures; // rcx
  char *v13; // rdx
  __int64 v14; // rcx
  char *v15; // rdx
  UFG::qMemoryPool *v16; // r8
  __int64 v17; // rcx
  char *v18; // rdx
  char *v19; // r8
  UFG::qMemoryPool *v20; // r8
  __int64 v21; // rcx
  char *v22; // rdx
  UFG::qMemoryPool *v23; // r9
  signed int v24; // r8d
  __int64 v25; // rcx
  char *v26; // rdx
  char *v27; // r9
  UFG::qMemoryPool *v28; // rsi
  UFG::qMemoryPool *v29; // rbx
  UFG::qMemoryPool *v30; // rbx
  unsigned __int64 v32; // [rsp+20h] [rbp-30h] BYREF
  unsigned __int64 v33; // [rsp+28h] [rbp-28h] BYREF
  __int64 v34[4]; // [rsp+30h] [rbp-20h] BYREF
  UFG::qMemoryPool *mCurrSize; // [rsp+98h] [rbp+48h] BYREF

  v34[1] = -2i64;
  v10 = &Illusion::gMemImageSchema;
  if ( schema )
    v10 = schema;
  v11 = "Buffer";
  if ( alloc_name )
    v11 = (const char *)alloc_name;
  Illusion::MemImageSchema::Init(v10);
  mNumMemStructures = v10->mNumMemStructures;
  v13 = (char *)v10 + 48 * mNumMemStructures;
  v10->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v13 + 2) = v11;
  *((_QWORD *)v13 + 3) = v10->mCurrSize;
  *((_DWORD *)v13 + 8) = 144;
  *((_QWORD *)v13 + 5) = 0i64;
  *((_QWORD *)v13 + 7) = 0i64;
  *((_QWORD *)v13 + 6) = 0i64;
  alloc_name = (UFG::qMemoryPool *)v10->mCurrSize;
  *((_QWORD *)v13 + 5) = &alloc_name;
  v10->mCurrSize += 144i64;
  v14 = v10->mNumMemStructures;
  v15 = (char *)v10 + 48 * v14;
  v10->mNumMemStructures = v14 + 1;
  *((_QWORD *)v15 + 2) = "Illusion.BufferPlat";
  *((_QWORD *)v15 + 3) = v10->mCurrSize;
  *((_DWORD *)v15 + 8) = 128;
  *((_QWORD *)v15 + 5) = 0i64;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  mCurrSize = (UFG::qMemoryPool *)v10->mCurrSize;
  *((_QWORD *)v15 + 5) = &mCurrSize;
  v10->mCurrSize += 128i64;
  v16 = alloc_name;
  v17 = v10->mNumMemStructures;
  v18 = (char *)v10 + 48 * v17;
  v10->mNumMemStructures = v17 + 1;
  *((_QWORD *)v18 + 2) = "Illusion.BufferUser";
  *((_QWORD *)v18 + 3) = v10->mCurrSize;
  *((_DWORD *)v18 + 8) = 16;
  *((_QWORD *)v18 + 5) = 0i64;
  *((_QWORD *)v18 + 7) = 0i64;
  *((_QWORD *)v18 + 6) = 0i64;
  v32 = v10->mCurrSize;
  *((_QWORD *)v18 + 5) = &v32;
  v19 = &v16->mDataBuffer[72];
  if ( v19 )
  {
    *((_QWORD *)v18 + 7) = v19;
    *((_QWORD *)v18 + 6) = v10->mCurrSize - (_QWORD)v19;
  }
  v10->mCurrSize += 16i64;
  v20 = mCurrSize;
  v21 = v10->mNumMemStructures;
  v22 = (char *)v10 + 48 * v21;
  v10->mNumMemStructures = v21 + 1;
  *((_QWORD *)v22 + 2) = "Illusion.BufferUserPlat";
  *((_QWORD *)v22 + 3) = v10->mCurrSize;
  *((_DWORD *)v22 + 8) = 16;
  *((_QWORD *)v22 + 5) = 0i64;
  *((_QWORD *)v22 + 7) = 0i64;
  *((_QWORD *)v22 + 6) = 0i64;
  v33 = v10->mCurrSize;
  *((_QWORD *)v22 + 5) = &v33;
  if ( v20 )
  {
    *((_QWORD *)v22 + 7) = v20;
    *((_QWORD *)v22 + 6) = v10->mCurrSize - (_QWORD)v20;
  }
  v10->mCurrSize += 16i64;
  v23 = alloc_name;
  v24 = (byte_size + 15) & 0xFFFFFFF0;
  v25 = v10->mNumMemStructures;
  v26 = (char *)v10 + 48 * v25;
  v10->mNumMemStructures = v25 + 1;
  *((_QWORD *)v26 + 2) = "Illusion.BufferData";
  *((_QWORD *)v26 + 3) = v10->mCurrSize;
  *((_DWORD *)v26 + 8) = v24;
  *((_QWORD *)v26 + 5) = 0i64;
  *((_QWORD *)v26 + 7) = 0i64;
  *((_QWORD *)v26 + 6) = 0i64;
  v34[0] = v10->mCurrSize;
  *((_QWORD *)v26 + 5) = v34;
  v27 = &v23->mDataBuffer[56];
  if ( v27 )
  {
    *((_QWORD *)v26 + 7) = v27;
    *((_QWORD *)v26 + 6) = v10->mCurrSize - (_QWORD)v27;
  }
  v10->mCurrSize += v24;
  v28 = memory_pool;
  Illusion::MemImageSchema::Allocate(v10, memory_pool, allocation_params);
  v29 = alloc_name;
  memory_pool = alloc_name;
  if ( alloc_name )
  {
    UFG::qResourceData::qResourceData((UFG::qResourceData *)alloc_name, 0x92CDEC8F, name_uid, name);
    *(_DWORD *)&v29->mDataBuffer[52] = byte_size;
    *(_QWORD *)&v29->mDataBuffer[88] = 0i64;
    *(_QWORD *)&v29->mDataBuffer[80] = 0i64;
    *(_WORD *)&v29->mDataBuffer[50] = 0;
    *(_QWORD *)&v29->mDataBuffer[96] = 0i64;
  }
  v30 = mCurrSize;
  memory_pool = mCurrSize;
  if ( mCurrSize )
  {
    mCurrSize->mNext = 0i64;
    *(_QWORD *)&v30->mInitializedUID = 0i64;
    v34[2] = (__int64)&v30->mAutoAllocatedBuffer;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v30->mAutoAllocatedBuffer);
    UFG::qMemSet(&v30->mDataBuffer[16], 0, 0x48u);
    *(_DWORD *)&v30->mDataBuffer[8] = 0;
  }
  alloc_name->mDataBuffer[49] = 1;
  *(_QWORD *)&alloc_name->mDataBuffer[88] = v28;
  return alloc_name;
}

// File Line: 151
// RVA: 0xA1CA70
Illusion::Buffer *__fastcall Illusion::Factory::NewBuffer(
        const char *name,
        unsigned int name_uid,
        unsigned int byte_size,
        Illusion::MemImageSchema *schema,
        const char *alloc_name,
        UFG::qLinearAllocator *linear_allocator,
        unsigned __int64 allocation_params)
{
  unsigned int v10; // ebx
  unsigned int v11; // eax
  char *v12; // rdi
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rcx

  v10 = (byte_size + 15) & 0xFFFFFFF0;
  v11 = (unsigned int)allocation_params >> 8;
  if ( (unsigned int)allocation_params >> 8 < 0x10 )
    v11 = 16;
  v12 = UFG::qLinearAllocator::Malloc(linear_allocator, (v10 + 319) & 0xFFFFFFF0, v11);
  UFG::qMemSet(v12, 0, v10 + 304);
  if ( v12 == (char *)-272i64 )
    v13 = 0i64;
  else
    v13 = 160i64;
  *((_QWORD *)v12 + 14) = v13;
  if ( v12 == (char *)-288i64 )
    v14 = 0i64;
  else
    v14 = 144i64;
  *((_QWORD *)v12 + 18) = v14;
  if ( v12 == (char *)-304i64 )
    v15 = 0i64;
  else
    v15 = 208i64;
  *((_QWORD *)v12 + 12) = v15;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)v12, 0x92CDEC8F, name_uid, name);
  *((_DWORD *)v12 + 23) = byte_size;
  *((_QWORD *)v12 + 16) = 0i64;
  *((_QWORD *)v12 + 15) = 0i64;
  *((_WORD *)v12 + 45) = 0;
  *((_QWORD *)v12 + 17) = 0i64;
  *((_QWORD *)v12 + 19) = 0i64;
  *((_QWORD *)v12 + 20) = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v12 + 168));
  UFG::qMemSet(v12 + 200, 0, 0x48u);
  *((_DWORD *)v12 + 48) = 0;
  v12[89] = 1;
  return (Illusion::Buffer *)v12;
}

// File Line: 191
// RVA: 0xA19960
void __fastcall Illusion::Factory::Delete(Illusion::Buffer *buffer, bool wait)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qMemoryPool *mMemoryPool; // rcx

  if ( buffer )
  {
    if ( wait )
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
    Illusion::BufferPlat::~BufferPlat((Illusion::BufferPlat *)&buffer[1]);
    UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&buffer->mResourceHandles);
    mPrev = buffer->mResourceHandles.UFG::qResourceData::mNode.mPrev;
    mNext = buffer->mResourceHandles.UFG::qResourceData::mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    buffer->mResourceHandles.UFG::qResourceData::mNode.mPrev = &buffer->mResourceHandles.UFG::qResourceData::mNode;
    buffer->mResourceHandles.UFG::qResourceData::mNode.mNext = &buffer->mResourceHandles.UFG::qResourceData::mNode;
    mMemoryPool = buffer->mMemoryPool;
    if ( mMemoryPool )
      UFG::qMemoryPool::Free(mMemoryPool, (char *)buffer);
    else
      operator delete[](buffer);
  }
}

// File Line: 243
// RVA: 0xA1CF40
UFG::qResourceData *__fastcall Illusion::Factory::NewModel(
        const char *name,
        unsigned int name_uid,
        unsigned int num_meshes,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  unsigned __int64 v6; // rdi
  unsigned int v7; // r12d
  Illusion::MemImageSchema *v9; // rbx
  __int64 mNumMemStructures; // r9
  char *v11; // rcx
  __int64 v12; // rcx
  char *v13; // rdx
  __int64 v14; // r8
  __int64 v15; // rcx
  char *v16; // rdx
  UFG::qResourceData *v17; // r8
  __int64 v18; // rcx
  char *v19; // rdx
  unsigned int *p_mUID; // r8
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // r15
  unsigned int v25; // r9d
  _QWORD *p_mNext; // r8
  __int64 v27; // rcx
  char *v28; // rdx
  UFG::qBaseNodeRB **mChild; // r10
  UFG::allocator::free_link *v30; // r9
  unsigned __int64 v31; // r10
  UFG::allocator::free_link *mNext; // r8
  __int64 v33; // rcx
  char *v34; // rdx
  __int64 v35; // rcx
  char *v36; // rdx
  UFG::qMemoryPool *v37; // r14
  UFG::qResourceData *v38; // rbx
  __int64 v39; // rdi
  UFG::qBaseNodeRB *v40; // rcx
  char *v41; // rax
  char *v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rbx
  __int64 v46; // [rsp+30h] [rbp-30h] BYREF
  UFG::qMemoryPool *v47; // [rsp+38h] [rbp-28h] BYREF
  __int64 v48[2]; // [rsp+40h] [rbp-20h] BYREF
  char *p_mResourceHandles; // [rsp+50h] [rbp-10h]
  __int64 v50; // [rsp+58h] [rbp-8h]
  UFG::qResourceData *mCurrSize; // [rsp+B8h] [rbp+58h] BYREF

  v48[1] = -2i64;
  v6 = num_meshes;
  v7 = name_uid;
  v9 = &Illusion::gMemImageSchema;
  if ( schema )
    v9 = schema;
  Illusion::MemImageSchema::Init(v9);
  mNumMemStructures = v9->mNumMemStructures;
  v11 = (char *)v9 + 48 * mNumMemStructures;
  v9->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v11 + 2) = "Illusion.Model";
  *((_QWORD *)v11 + 3) = v9->mCurrSize;
  *((_DWORD *)v11 + 8) = 304;
  *((_QWORD *)v11 + 5) = 0i64;
  *((_QWORD *)v11 + 7) = 0i64;
  *((_QWORD *)v11 + 6) = 0i64;
  mCurrSize = (UFG::qResourceData *)v9->mCurrSize;
  *((_QWORD *)v11 + 5) = &mCurrSize;
  v9->mCurrSize += 304i64;
  v12 = v9->mNumMemStructures;
  v13 = (char *)v9 + 48 * v12;
  v9->mNumMemStructures = v12 + 1;
  *((_QWORD *)v13 + 2) = "Illusion.ModelPlat";
  *((_QWORD *)v13 + 3) = v9->mCurrSize;
  *((_DWORD *)v13 + 8) = 16;
  *((_QWORD *)v13 + 5) = 0i64;
  *((_QWORD *)v13 + 7) = 0i64;
  *((_QWORD *)v13 + 6) = 0i64;
  v46 = v9->mCurrSize;
  *((_QWORD *)v13 + 5) = &v46;
  v9->mCurrSize += 16i64;
  v14 = v46;
  v15 = v9->mNumMemStructures;
  v16 = (char *)v9 + 48 * v15;
  v9->mNumMemStructures = v15 + 1;
  *((_QWORD *)v16 + 2) = "Illusion.ModelUserPlat";
  *((_QWORD *)v16 + 3) = v9->mCurrSize;
  *((_DWORD *)v16 + 8) = 16;
  *((_QWORD *)v16 + 5) = 0i64;
  *((_QWORD *)v16 + 7) = 0i64;
  *((_QWORD *)v16 + 6) = 0i64;
  v47 = (UFG::qMemoryPool *)v9->mCurrSize;
  *((_QWORD *)v16 + 5) = &v47;
  if ( v14 )
  {
    *((_QWORD *)v16 + 7) = v14;
    *((_QWORD *)v16 + 6) = v9->mCurrSize - v14;
  }
  v9->mCurrSize += 16i64;
  v17 = mCurrSize;
  v18 = v9->mNumMemStructures;
  v19 = (char *)v9 + 48 * v18;
  v9->mNumMemStructures = v18 + 1;
  *((_QWORD *)v19 + 2) = "Illusion.ModelUser";
  *((_QWORD *)v19 + 3) = v9->mCurrSize;
  *((_DWORD *)v19 + 8) = 16;
  *((_QWORD *)v19 + 5) = 0i64;
  *((_QWORD *)v19 + 7) = 0i64;
  *((_QWORD *)v19 + 6) = 0i64;
  v48[0] = v9->mCurrSize;
  *((_QWORD *)v19 + 5) = v48;
  p_mUID = &v17[2].mNode.mUID;
  if ( p_mUID )
  {
    *((_QWORD *)v19 + 7) = p_mUID;
    *((_QWORD *)v19 + 6) = v9->mCurrSize - (_QWORD)p_mUID;
  }
  v9->mCurrSize += 16i64;
  v21 = v6;
  v22 = 8 * v6;
  if ( !is_mul_ok(v6, 8ui64) )
    v22 = -1i64;
  v23 = UFG::qMalloc(v22, "MeshOffsetPtr", 0i64);
  v24 = v23;
  v25 = 0;
  if ( (_DWORD)v6 )
  {
    p_mNext = &v23->mNext;
    do
    {
      v27 = v9->mNumMemStructures;
      v9->mNumMemStructures = v27 + 1;
      v28 = (char *)v9 + 48 * v27;
      if ( v25 )
      {
        *((_QWORD *)v28 + 2) = "UFG::qOffset<Mesh*>";
        *((_QWORD *)v28 + 3) = v9->mCurrSize;
        *((_DWORD *)v28 + 8) = 8;
        *((_QWORD *)v28 + 5) = 0i64;
        *((_QWORD *)v28 + 7) = 0i64;
        *((_QWORD *)v28 + 6) = 0i64;
        if ( p_mNext )
        {
          *p_mNext = v9->mCurrSize;
          *((_QWORD *)v28 + 5) = p_mNext;
        }
      }
      else
      {
        mChild = mCurrSize[2].mNode.mChild;
        *((_QWORD *)v28 + 2) = "UFG::qOffset<Mesh*>";
        *((_QWORD *)v28 + 3) = v9->mCurrSize;
        *((_DWORD *)v28 + 8) = 8;
        *((_QWORD *)v28 + 5) = 0i64;
        *((_QWORD *)v28 + 7) = 0i64;
        *((_QWORD *)v28 + 6) = 0i64;
        if ( p_mNext )
        {
          *p_mNext = v9->mCurrSize;
          *((_QWORD *)v28 + 5) = p_mNext;
        }
        if ( mChild )
        {
          *((_QWORD *)v28 + 7) = mChild;
          *((_QWORD *)v28 + 6) = v9->mCurrSize - (_QWORD)mChild;
        }
      }
      v9->mCurrSize += 8i64;
      ++v25;
      ++p_mNext;
    }
    while ( v25 < (unsigned int)v6 );
  }
  Illusion::MemImageSchema::Align16(v9);
  if ( (_DWORD)v6 )
  {
    v30 = v24;
    v31 = v6;
    do
    {
      mNext = v30->mNext;
      v33 = v9->mNumMemStructures;
      v34 = (char *)v9 + 48 * v33;
      v9->mNumMemStructures = v33 + 1;
      *((_QWORD *)v34 + 2) = "Illusion.Mesh";
      *((_QWORD *)v34 + 3) = v9->mCurrSize;
      *((_DWORD *)v34 + 8) = 256;
      *((_QWORD *)v34 + 5) = 0i64;
      *((_QWORD *)v34 + 7) = 0i64;
      *((_QWORD *)v34 + 6) = 0i64;
      if ( mNext )
      {
        *((_QWORD *)v34 + 7) = mNext;
        *((_QWORD *)v34 + 6) = v9->mCurrSize - (_QWORD)mNext;
      }
      v9->mCurrSize += 256i64;
      v35 = v9->mNumMemStructures;
      v36 = (char *)v9 + 48 * v35;
      v9->mNumMemStructures = v35 + 1;
      *((_QWORD *)v36 + 2) = "Illusion.MeshPlat";
      *((_QWORD *)v36 + 3) = v9->mCurrSize;
      *((_DWORD *)v36 + 8) = 16;
      *((_QWORD *)v36 + 5) = 0i64;
      *((_QWORD *)v36 + 7) = 0i64;
      *((_QWORD *)v36 + 6) = 0i64;
      v9->mCurrSize += 16i64;
      ++v30;
      --v31;
    }
    while ( v31 );
    v7 = name_uid;
  }
  v37 = memory_pool;
  Illusion::MemImageSchema::Allocate(v9, memory_pool, allocation_params);
  v38 = mCurrSize;
  memory_pool = (UFG::qMemoryPool *)mCurrSize;
  if ( mCurrSize )
  {
    UFG::qResourceData::qResourceData(mCurrSize, 0xA2ADCD77, v7, name);
    p_mResourceHandles = (char *)&v38[1].mResourceHandles;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[1].mResourceHandles);
    p_mResourceHandles = &v38[1].mDebugName[12];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[1].mDebugName[12]);
    p_mResourceHandles = &v38[2].mDebugName[4];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[2].mDebugName[4]);
    p_mResourceHandles = (char *)&v38[3];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[3]);
    *(_QWORD *)&v38[2].mTypeUID = 0i64;
    v38[2].mResourceHandles.mNode.mPrev = 0i64;
    *(&v38[1].mNode.mUID + 1) = 0;
    LODWORD(v38[2].mResourceHandles.mNode.mNext) = 0;
  }
  memory_pool = v47;
  *(_QWORD *)&mCurrSize[2].mTypeUID = v37;
  LODWORD(mCurrSize[2].mNode.mChild[1]) = v6;
  HIDWORD(mCurrSize[1].mNode.mChild[0]) = 0;
  if ( (_DWORD)v6 )
  {
    v39 = 0i64;
    do
    {
      v40 = mCurrSize[2].mNode.mChild[0];
      if ( v40 )
        v41 = (char *)mCurrSize[2].mNode.mChild + (_QWORD)v40;
      else
        v41 = 0i64;
      v42 = &v41[v39];
      v43 = *(_QWORD *)&v41[v39];
      v44 = (__int64)&v42[v43];
      if ( !v43 )
        v44 = 0i64;
      memory_pool = (UFG::qMemoryPool *)v44;
      p_mResourceHandles = (char *)v44;
      if ( v44 )
      {
        v50 = v44;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)v44);
        v50 = v44 + 32;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v44 + 32));
        v50 = v44 + 64;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v44 + 64));
        `eh vector constructor iterator(
          (void *)(v44 + 96),
          0x20ui64,
          4,
          (void (__fastcall *)(void *))Illusion::BufferHandle::BufferHandle);
      }
      v39 += 8i64;
      --v21;
    }
    while ( v21 );
  }
  operator delete[](v24);
  return mCurrSize;
}

// File Line: 311
// RVA: 0xA19A00
void __fastcall Illusion::Factory::Delete(Illusion::Model *model, bool wait)
{
  UFG::qMemoryPool *mMemoryPool; // rcx

  if ( model )
  {
    if ( wait )
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
    Illusion::Model::~Model(model);
    mMemoryPool = model->mMemoryPool;
    if ( mMemoryPool )
      UFG::qMemoryPool::Free(mMemoryPool, (char *)model);
    else
      operator delete[](model);
  }
}

// File Line: 356
// RVA: 0xA1D620
UFG::qResourceData *__fastcall Illusion::Factory::NewShader(
        const char *name,
        unsigned int name_uid,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v8; // rbx
  __int64 mNumMemStructures; // r8
  char *v10; // rdx
  __int64 v11; // rcx
  char *v12; // rdx
  UFG::qResourceData *v13; // r8
  __int64 v14; // rcx
  char *v15; // rdx
  UFG::qBaseNodeRB **v16; // r8
  char *v17; // r8
  __int64 v18; // rcx
  char *v19; // rdx
  char *v20; // r8
  _QWORD *v21; // rcx
  void *dest; // [rsp+20h] [rbp-38h] BYREF
  Illusion::ShaderUser *v24; // [rsp+28h] [rbp-30h] BYREF
  __int64 v25[2]; // [rsp+30h] [rbp-28h] BYREF
  void *v26; // [rsp+40h] [rbp-18h]
  Illusion::ShaderUser *v27; // [rsp+48h] [rbp-10h]
  UFG::qResourceData *mCurrSize; // [rsp+70h] [rbp+18h] BYREF

  v25[1] = -2i64;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  mNumMemStructures = v8->mNumMemStructures;
  v10 = (char *)v8 + 48 * mNumMemStructures;
  v8->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v10 + 2) = "Illusion.Shader";
  *((_QWORD *)v10 + 3) = v8->mCurrSize;
  *((_DWORD *)v10 + 8) = 1168;
  *((_QWORD *)v10 + 5) = 0i64;
  *((_QWORD *)v10 + 7) = 0i64;
  *((_QWORD *)v10 + 6) = 0i64;
  mCurrSize = (UFG::qResourceData *)v8->mCurrSize;
  *((_QWORD *)v10 + 5) = &mCurrSize;
  v8->mCurrSize += 1168i64;
  v11 = v8->mNumMemStructures;
  v12 = (char *)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *((_QWORD *)v12 + 2) = "Illusion.ShaderPlat";
  *((_QWORD *)v12 + 3) = v8->mCurrSize;
  *((_DWORD *)v12 + 8) = 80;
  *((_QWORD *)v12 + 5) = 0i64;
  *((_QWORD *)v12 + 7) = 0i64;
  *((_QWORD *)v12 + 6) = 0i64;
  dest = (void *)v8->mCurrSize;
  *((_QWORD *)v12 + 5) = &dest;
  v8->mCurrSize += 80i64;
  v13 = mCurrSize;
  v14 = v8->mNumMemStructures;
  v15 = (char *)v8 + 48 * v14;
  v8->mNumMemStructures = v14 + 1;
  *((_QWORD *)v15 + 2) = "Illusion.ShaderUser";
  *((_QWORD *)v15 + 3) = v8->mCurrSize;
  *((_DWORD *)v15 + 8) = 208;
  *((_QWORD *)v15 + 5) = 0i64;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  v24 = (Illusion::ShaderUser *)v8->mCurrSize;
  *((_QWORD *)v15 + 5) = &v24;
  v16 = &v13[1].mNode.mChild[1];
  if ( v16 )
  {
    *((_QWORD *)v15 + 7) = v16;
    *((_QWORD *)v15 + 6) = v8->mCurrSize - (_QWORD)v16;
  }
  v8->mCurrSize += 208i64;
  v17 = (char *)dest;
  v18 = v8->mNumMemStructures;
  v19 = (char *)v8 + 48 * v18;
  v8->mNumMemStructures = v18 + 1;
  *((_QWORD *)v19 + 2) = "Illusion.ShaderUserPlat";
  *((_QWORD *)v19 + 3) = v8->mCurrSize;
  *((_DWORD *)v19 + 8) = 16;
  *((_QWORD *)v19 + 5) = 0i64;
  *((_QWORD *)v19 + 7) = 0i64;
  *((_QWORD *)v19 + 6) = 0i64;
  v25[0] = v8->mCurrSize;
  *((_QWORD *)v19 + 5) = v25;
  v20 = v17 + 48;
  if ( v20 )
  {
    *((_QWORD *)v19 + 7) = v20;
    *((_QWORD *)v19 + 6) = v8->mCurrSize - (_QWORD)v20;
  }
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, memory_pool, allocation_params);
  v26 = mCurrSize;
  if ( mCurrSize )
    UFG::qResourceData::qResourceData(mCurrSize, 0x8B5561A1, name_uid, name);
  v21 = dest;
  v26 = dest;
  if ( dest )
  {
    v27 = (Illusion::ShaderUser *)((char *)dest + 56);
    *((_QWORD *)dest + 7) = (char *)dest + 56;
    v21[8] = v21 + 7;
    UFG::qMemSet(v21, 0, 0x30u);
  }
  v27 = v24;
  if ( v24 )
    Illusion::ShaderUser::ShaderUser(v24);
  return mCurrSize;
}

// File Line: 383
// RVA: 0xA19A50
void __fastcall Illusion::Factory::Delete(Illusion::Shader *shader)
{
  char *v2; // rbx
  __int64 v3; // rcx
  _QWORD *v4; // rax
  __int64 mOffset; // rax
  Illusion::ShaderUser *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  if ( shader )
  {
    v2 = &shader[1].mDebugName[12];
    UFG::qList<Illusion::ShaderParam,Illusion::ShaderParam,1,0>::DeleteNodes((UFG::qList<Illusion::ShaderParam,Illusion::ShaderParam,1,0> *)&shader[1].mDebugName[12]);
    v3 = *(_QWORD *)v2;
    v4 = (_QWORD *)*((_QWORD *)v2 + 1);
    *(_QWORD *)(v3 + 8) = v4;
    *v4 = v3;
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
    mOffset = shader->mShaderUser.mOffset;
    if ( mOffset )
      v6 = (Illusion::ShaderUser *)((char *)&shader->mShaderUser + mOffset);
    else
      v6 = 0i64;
    Illusion::ShaderUser::~ShaderUser(v6);
    UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&shader->mResourceHandles);
    mPrev = shader->mResourceHandles.UFG::qResourceData::mNode.mPrev;
    mNext = shader->mResourceHandles.UFG::qResourceData::mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    shader->mResourceHandles.UFG::qResourceData::mNode.mPrev = &shader->mResourceHandles.UFG::qResourceData::mNode;
    shader->mResourceHandles.UFG::qResourceData::mNode.mNext = &shader->mResourceHandles.UFG::qResourceData::mNode;
    operator delete[](shader);
  }
}

// File Line: 407
// RVA: 0xA1D8A0
UFG::qResourceData *__fastcall Illusion::Factory::NewTexture(
        const char *name,
        unsigned int name_uid,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v8; // rbx
  __int64 mNumMemStructures; // r8
  char *v10; // rdx
  __int64 v11; // rcx
  char *v12; // rdx
  UFG::qResourceData *v13; // r8
  __int64 v14; // rcx
  char *v15; // rdx
  unsigned int *p_mUID; // r8
  Illusion::TexturePlat *v17; // r8
  __int64 v18; // rcx
  char *v19; // rdx
  UFG::qResourceData *v20; // rbx
  UFG::qResourceHandle *v21; // rbx
  Illusion::TexturePlat *v23; // [rsp+20h] [rbp-38h] BYREF
  UFG::qResourceHandle *v24; // [rsp+28h] [rbp-30h] BYREF
  __int64 v25[2]; // [rsp+30h] [rbp-28h] BYREF
  UFG::qResourceHandle *v26; // [rsp+40h] [rbp-18h]
  char *v27; // [rsp+48h] [rbp-10h]
  UFG::qResourceData *mCurrSize; // [rsp+70h] [rbp+18h] BYREF

  v25[1] = -2i64;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  mNumMemStructures = v8->mNumMemStructures;
  v10 = (char *)v8 + 48 * mNumMemStructures;
  v8->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v10 + 2) = "Illusion.Texture";
  *((_QWORD *)v10 + 3) = v8->mCurrSize;
  *((_DWORD *)v10 + 8) = 208;
  *((_QWORD *)v10 + 5) = 0i64;
  *((_QWORD *)v10 + 7) = 0i64;
  *((_QWORD *)v10 + 6) = 0i64;
  mCurrSize = (UFG::qResourceData *)v8->mCurrSize;
  *((_QWORD *)v10 + 5) = &mCurrSize;
  v8->mCurrSize += 208i64;
  v11 = v8->mNumMemStructures;
  v12 = (char *)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *((_QWORD *)v12 + 2) = "Illusion.TexturePlat";
  *((_QWORD *)v12 + 3) = v8->mCurrSize;
  *((_DWORD *)v12 + 8) = 176;
  *((_QWORD *)v12 + 5) = 0i64;
  *((_QWORD *)v12 + 7) = 0i64;
  *((_QWORD *)v12 + 6) = 0i64;
  v23 = (Illusion::TexturePlat *)v8->mCurrSize;
  *((_QWORD *)v12 + 5) = &v23;
  v8->mCurrSize += 176i64;
  v13 = mCurrSize;
  v14 = v8->mNumMemStructures;
  v15 = (char *)v8 + 48 * v14;
  v8->mNumMemStructures = v14 + 1;
  *((_QWORD *)v15 + 2) = "Illusion.TextureUser";
  *((_QWORD *)v15 + 3) = v8->mCurrSize;
  *((_DWORD *)v15 + 8) = 64;
  *((_QWORD *)v15 + 5) = 0i64;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  v24 = (UFG::qResourceHandle *)v8->mCurrSize;
  *((_QWORD *)v15 + 5) = &v24;
  p_mUID = &v13[1].mNode.mUID;
  if ( p_mUID )
  {
    *((_QWORD *)v15 + 7) = p_mUID;
    *((_QWORD *)v15 + 6) = v8->mCurrSize - (_QWORD)p_mUID;
  }
  v8->mCurrSize += 64i64;
  v17 = v23;
  v18 = v8->mNumMemStructures;
  v19 = (char *)v8 + 48 * v18;
  v8->mNumMemStructures = v18 + 1;
  *((_QWORD *)v19 + 2) = "Illusion.TextureUserPlat";
  *((_QWORD *)v19 + 3) = v8->mCurrSize;
  *((_DWORD *)v19 + 8) = 16;
  *((_QWORD *)v19 + 5) = 0i64;
  *((_QWORD *)v19 + 7) = 0i64;
  *((_QWORD *)v19 + 6) = 0i64;
  v25[0] = v8->mCurrSize;
  *((_QWORD *)v19 + 5) = v25;
  if ( v17 )
  {
    *((_QWORD *)v19 + 7) = v17;
    *((_QWORD *)v19 + 6) = v8->mCurrSize - (_QWORD)v17;
  }
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, memory_pool, allocation_params);
  v20 = mCurrSize;
  v26 = (UFG::qResourceHandle *)mCurrSize;
  if ( mCurrSize )
  {
    UFG::qResourceData::qResourceData(mCurrSize, 0x8B43FABF, name_uid, name);
    v27 = &v20[1].mDebugName[12];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v20[1].mDebugName[12]);
  }
  v27 = (char *)v23;
  if ( v23 )
    Illusion::TexturePlat::TexturePlat(v23);
  v21 = v24;
  v27 = (char *)v24;
  if ( v24 )
  {
    v26 = v24;
    UFG::qResourceHandle::qResourceHandle(v24);
    v26 = v21 + 1;
    UFG::qResourceHandle::qResourceHandle(v21 + 1);
  }
  return mCurrSize;
}

// File Line: 435
// RVA: 0xA19B00
void __fastcall Illusion::Factory::Delete(Illusion::Texture *texture, bool wait)
{
  __int64 mOffset; // rax
  Illusion::eRenderPass::PassData *v4; // rcx

  if ( texture )
  {
    if ( wait )
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
    mOffset = texture->mTextureUser.mOffset;
    if ( mOffset )
      v4 = (Illusion::eRenderPass::PassData *)((char *)&texture->mTextureUser + mOffset);
    else
      v4 = 0i64;
    Illusion::TextureUser::~TextureUser(v4);
    Illusion::TexturePlat::~TexturePlat((Illusion::TexturePlat *)texture[1].mNode.mChild);
    Illusion::Texture::~Texture(texture);
    operator delete[](texture);
  }
}

// File Line: 478
// RVA: 0xA1DB40
Illusion::VertexDecl *__fastcall Illusion::Factory::NewVertexDecl(
        hkMemoryResourceContainer *descriptor,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  const char *UsedSpace; // r12
  unsigned int LayerCount; // r13d
  int TotalElements; // r15d
  Illusion::MemImageSchema *v9; // rdi
  unsigned int v10; // r14d
  __int64 mNumMemStructures; // rcx
  char *v12; // rdx
  int v13; // ebx
  __int64 v14; // rcx
  char *v15; // rdx
  UFG::qResourceData *v16; // r8
  __int64 v17; // rcx
  char *v18; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // r8
  __int64 v20; // r8
  __int64 v21; // rcx
  char *v22; // rdx
  __int64 v23; // r8
  UFG::qResourceData *v24; // r9
  signed int v25; // r8d
  __int64 v26; // rcx
  char *v27; // rdx
  UFG::qResourceData *v28; // r9
  UFG::qResourceData *v29; // rdi
  UFG::qBaseNodeRB *mParent; // rcx
  char *v31; // rcx
  __int64 v32; // rdi
  int StreamSize; // eax
  unsigned __int64 v35; // [rsp+20h] [rbp-38h] BYREF
  UFG::qResourceData *v36; // [rsp+28h] [rbp-30h] BYREF
  unsigned __int64 v37; // [rsp+30h] [rbp-28h] BYREF
  void *source; // [rsp+38h] [rbp-20h]
  __int64 v39; // [rsp+40h] [rbp-18h]
  UFG::qResourceData *v40; // [rsp+48h] [rbp-10h]
  UFG::qResourceData *mCurrSize; // [rsp+A0h] [rbp+48h] BYREF
  __int64 v42; // [rsp+A8h] [rbp+50h] BYREF
  UFG::qMemoryPool *memory_poola; // [rsp+B0h] [rbp+58h]
  unsigned __int64 allocation_paramsa; // [rsp+B8h] [rbp+60h]

  allocation_paramsa = allocation_params;
  memory_poola = memory_pool;
  v39 = -2i64;
  UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(descriptor);
  LayerCount = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)descriptor);
  source = Illusion::VertexStreamDescriptor::GetElement((Illusion::VertexStreamDescriptor *)descriptor, 0, -1);
  TotalElements = Illusion::VertexStreamDescriptor::GetTotalElements((Illusion::VertexStreamDescriptor *)descriptor);
  v9 = &Illusion::gMemImageSchema;
  if ( schema )
    v9 = schema;
  Illusion::MemImageSchema::Init(v9);
  v10 = 36 * TotalElements;
  mNumMemStructures = v9->mNumMemStructures;
  v12 = (char *)v9 + 48 * mNumMemStructures;
  v9->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v12 + 2) = "Illusion.VertexDecl";
  *((_QWORD *)v12 + 3) = v9->mCurrSize;
  *((_DWORD *)v12 + 8) = 128;
  v13 = 0;
  *((_QWORD *)v12 + 5) = 0i64;
  *((_QWORD *)v12 + 7) = 0i64;
  *((_QWORD *)v12 + 6) = 0i64;
  mCurrSize = (UFG::qResourceData *)v9->mCurrSize;
  *((_QWORD *)v12 + 5) = &mCurrSize;
  v9->mCurrSize += 128i64;
  v14 = v9->mNumMemStructures;
  v15 = (char *)v9 + 48 * v14;
  v9->mNumMemStructures = v14 + 1;
  *((_QWORD *)v15 + 2) = "Illusion.VertexDeclPlat";
  *((_QWORD *)v15 + 3) = v9->mCurrSize;
  *((_DWORD *)v15 + 8) = 32;
  *((_QWORD *)v15 + 5) = 0i64;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  v42 = v9->mCurrSize;
  *((_QWORD *)v15 + 5) = &v42;
  v9->mCurrSize += 32i64;
  v16 = mCurrSize;
  v17 = v9->mNumMemStructures;
  v18 = (char *)v9 + 48 * v17;
  v9->mNumMemStructures = v17 + 1;
  *((_QWORD *)v18 + 2) = "Illusion.VertexDeclUser";
  *((_QWORD *)v18 + 3) = v9->mCurrSize;
  *((_DWORD *)v18 + 8) = 16;
  *((_QWORD *)v18 + 5) = 0i64;
  *((_QWORD *)v18 + 7) = 0i64;
  *((_QWORD *)v18 + 6) = 0i64;
  v35 = v9->mCurrSize;
  *((_QWORD *)v18 + 5) = &v35;
  p_mResourceHandles = &v16[1].mResourceHandles;
  if ( p_mResourceHandles )
  {
    *((_QWORD *)v18 + 7) = p_mResourceHandles;
    *((_QWORD *)v18 + 6) = v9->mCurrSize - (_QWORD)p_mResourceHandles;
  }
  v9->mCurrSize += 16i64;
  v20 = v42;
  v21 = v9->mNumMemStructures;
  v22 = (char *)v9 + 48 * v21;
  v9->mNumMemStructures = v21 + 1;
  *((_QWORD *)v22 + 2) = "Illusion.VertexDeclUserPlat";
  *((_QWORD *)v22 + 3) = v9->mCurrSize;
  *((_DWORD *)v22 + 8) = 16;
  *((_QWORD *)v22 + 5) = 0i64;
  *((_QWORD *)v22 + 7) = 0i64;
  *((_QWORD *)v22 + 6) = 0i64;
  v36 = (UFG::qResourceData *)v9->mCurrSize;
  *((_QWORD *)v22 + 5) = &v36;
  v23 = v20 + 16;
  if ( v23 )
  {
    *((_QWORD *)v22 + 7) = v23;
    *((_QWORD *)v22 + 6) = v9->mCurrSize - v23;
  }
  v9->mCurrSize += 16i64;
  v24 = mCurrSize;
  v25 = (v10 + 15) & 0xFFFFFFF0;
  v26 = v9->mNumMemStructures;
  v27 = (char *)v9 + 48 * v26;
  v9->mNumMemStructures = v26 + 1;
  *((_QWORD *)v27 + 2) = "Illusion.VertexDeclData";
  *((_QWORD *)v27 + 3) = v9->mCurrSize;
  *((_DWORD *)v27 + 8) = v25;
  *((_QWORD *)v27 + 5) = 0i64;
  *((_QWORD *)v27 + 7) = 0i64;
  *((_QWORD *)v27 + 6) = 0i64;
  v37 = v9->mCurrSize;
  *((_QWORD *)v27 + 5) = &v37;
  v28 = v24 + 1;
  if ( v28 )
  {
    *((_QWORD *)v27 + 7) = v28;
    *((_QWORD *)v27 + 6) = v9->mCurrSize - (_QWORD)v28;
  }
  v9->mCurrSize += v25;
  Illusion::MemImageSchema::Allocate(v9, memory_poola, allocation_paramsa);
  v29 = mCurrSize;
  v40 = mCurrSize;
  if ( mCurrSize )
  {
    UFG::qResourceData::qResourceData(mCurrSize, 0x3E5FDA3Eu, LayerCount, UsedSpace);
    LODWORD(v29[1].mNode.mChild[0]) = TotalElements;
  }
  v40 = v36;
  mParent = mCurrSize[1].mNode.mParent;
  if ( mParent )
    v31 = (char *)&mParent[2].mChild[2] + (_QWORD)mCurrSize;
  else
    v31 = 0i64;
  UFG::qMemCopy(v31, source, v10);
  *(&mCurrSize[1].mNode.mUID + 1) = HIDWORD(descriptor[10].vfptr);
  v32 = 100i64;
  do
  {
    StreamSize = Illusion::VertexStreamDescriptor::GetStreamSize((Illusion::VertexStreamDescriptor *)descriptor, v13);
    *(_DWORD *)((char *)&mCurrSize->mNode.mParent + v32) = StreamSize;
    ++v13;
    v32 += 4i64;
  }
  while ( v13 < 4 );
  return (Illusion::VertexDecl *)mCurrSize;
}

// File Line: 541
// RVA: 0xA1C900
UFG::qResourceData *__fastcall Illusion::Factory::NewAlphaState(
        const char *name,
        unsigned int name_uid,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v8; // rbx
  __int64 mNumMemStructures; // r8
  char *v10; // rdx
  __int64 v11; // rcx
  char *v12; // rdx
  UFG::qResourceData *v13; // rbx
  __int64 v15[7]; // [rsp+20h] [rbp-38h] BYREF
  UFG::qResourceData *mCurrSize; // [rsp+70h] [rbp+18h] BYREF

  v15[1] = -2i64;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  mNumMemStructures = v8->mNumMemStructures;
  v10 = (char *)v8 + 48 * mNumMemStructures;
  v8->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v10 + 2) = "Illusion.AlphaState";
  *((_QWORD *)v10 + 3) = v8->mCurrSize;
  *((_DWORD *)v10 + 8) = 112;
  *((_QWORD *)v10 + 5) = 0i64;
  *((_QWORD *)v10 + 7) = 0i64;
  *((_QWORD *)v10 + 6) = 0i64;
  mCurrSize = (UFG::qResourceData *)v8->mCurrSize;
  *((_QWORD *)v10 + 5) = &mCurrSize;
  v8->mCurrSize += 112i64;
  v11 = v8->mNumMemStructures;
  v12 = (char *)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *((_QWORD *)v12 + 2) = "Illusion.AlphaStatePlat";
  *((_QWORD *)v12 + 3) = v8->mCurrSize;
  *((_DWORD *)v12 + 8) = 16;
  *((_QWORD *)v12 + 5) = 0i64;
  *((_QWORD *)v12 + 7) = 0i64;
  *((_QWORD *)v12 + 6) = 0i64;
  v15[0] = v8->mCurrSize;
  *((_QWORD *)v12 + 5) = v15;
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, memory_pool, allocation_params);
  v13 = mCurrSize;
  v15[2] = (__int64)mCurrSize;
  if ( mCurrSize )
  {
    UFG::qResourceData::qResourceData(mCurrSize, 0x12C800F2u, name_uid, name);
    LODWORD(v13[1].mNode.mParent) = 256;
    HIDWORD(v13[1].mNode.mParent) = 121634816;
    LOWORD(v13[1].mNode.mChild[0]) = 256;
    *(_DWORD *)((char *)v13[1].mNode.mChild + 2) = -61696;
    HIWORD(v13[1].mNode.mChild[0]) = 0;
  }
  return mCurrSize;
}

// File Line: 577
// RVA: 0xA1D4A0
UFG::qResourceData *__fastcall Illusion::Factory::NewRasterState(
        const char *name,
        unsigned int name_uid,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v8; // rbx
  __int64 mNumMemStructures; // r8
  char *v10; // rdx
  __int64 v11; // rcx
  char *v12; // rdx
  UFG::qResourceData *v13; // rbx
  __int64 v15[5]; // [rsp+20h] [rbp-28h] BYREF
  UFG::qResourceData *mCurrSize; // [rsp+60h] [rbp+18h] BYREF

  v15[1] = -2i64;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  mNumMemStructures = v8->mNumMemStructures;
  v10 = (char *)v8 + 48 * mNumMemStructures;
  v8->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v10 + 2) = "Illusion.RasterState";
  *((_QWORD *)v10 + 3) = v8->mCurrSize;
  *((_DWORD *)v10 + 8) = 128;
  *((_QWORD *)v10 + 5) = 0i64;
  *((_QWORD *)v10 + 7) = 0i64;
  *((_QWORD *)v10 + 6) = 0i64;
  mCurrSize = (UFG::qResourceData *)v8->mCurrSize;
  *((_QWORD *)v10 + 5) = &mCurrSize;
  v8->mCurrSize += 128i64;
  v11 = v8->mNumMemStructures;
  v12 = (char *)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *((_QWORD *)v12 + 2) = "Illusion.RasterStatePlat";
  *((_QWORD *)v12 + 3) = v8->mCurrSize;
  *((_DWORD *)v12 + 8) = 16;
  *((_QWORD *)v12 + 5) = 0i64;
  *((_QWORD *)v12 + 7) = 0i64;
  *((_QWORD *)v12 + 6) = 0i64;
  v15[0] = v8->mCurrSize;
  *((_QWORD *)v12 + 5) = v15;
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, memory_pool, allocation_params);
  v13 = mCurrSize;
  v15[2] = (__int64)mCurrSize;
  if ( mCurrSize )
  {
    UFG::qResourceData::qResourceData(mCurrSize, 0x3BC715E0u, name_uid, name);
    LODWORD(v13[1].mNode.mParent) = 196865;
    HIDWORD(v13[1].mNode.mParent) = 257;
    LODWORD(v13[1].mNode.mChild[0]) = 256;
    WORD2(v13[1].mNode.mChild[0]) = 0;
    *(_DWORD *)((char *)v13[1].mNode.mChild + 7) = 0;
    BYTE6(v13[1].mNode.mChild[0]) = 7;
    *(_DWORD *)((char *)&v13[1].mNode.mChild[1] + 3) = 458752;
    *(_DWORD *)((char *)&v13[1].mNode.mChild[1] + 7) = 16711680;
  }
  return mCurrSize;
}

