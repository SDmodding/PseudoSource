// File Line: 116
// RVA: 0xA1CC00
Illusion::Buffer *__fastcall Illusion::Factory::NewBuffer(const char *name, unsigned int name_uid, unsigned int byte_size, Illusion::MemImageSchema *schema, const char *alloc_name, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  unsigned int v7; // er14
  unsigned int v8; // er15
  const char *v9; // r12
  Illusion::MemImageSchema *v10; // rdi
  const char *v11; // rbx
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  const char *v16; // r8
  __int64 v17; // rcx
  signed __int64 v18; // rdx
  signed __int64 v19; // r8
  UFG::qMemoryPool *v20; // r8
  __int64 v21; // rcx
  signed __int64 v22; // rdx
  const char *v23; // r9
  signed int v24; // er8
  __int64 v25; // rcx
  signed __int64 v26; // rdx
  signed __int64 v27; // r9
  UFG::qMemoryPool *v28; // rsi
  const char *v29; // rbx
  UFG::qMemoryPool *v30; // rbx
  unsigned __int64 v32; // [rsp+20h] [rbp-30h]
  unsigned __int64 v33; // [rsp+28h] [rbp-28h]
  unsigned __int64 v34; // [rsp+30h] [rbp-20h]
  __int64 v35; // [rsp+38h] [rbp-18h]
  void **v36; // [rsp+40h] [rbp-10h]
  UFG::qMemoryPool *v37; // [rsp+98h] [rbp+48h]

  v35 = -2i64;
  v7 = byte_size;
  v8 = name_uid;
  v9 = name;
  v10 = &Illusion::gMemImageSchema;
  if ( schema )
    v10 = schema;
  v11 = "Buffer";
  if ( alloc_name )
    v11 = alloc_name;
  Illusion::MemImageSchema::Init(v10);
  v12 = v10->mNumMemStructures;
  v13 = (signed __int64)v10 + 48 * v12;
  v10->mNumMemStructures = v12 + 1;
  *(_QWORD *)(v13 + 16) = v11;
  *(_QWORD *)(v13 + 24) = v10->mCurrSize;
  *(_DWORD *)(v13 + 32) = 144;
  *(_QWORD *)(v13 + 40) = 0i64;
  *(_QWORD *)(v13 + 56) = 0i64;
  *(_QWORD *)(v13 + 48) = 0i64;
  alloc_name = (const char *)v10->mCurrSize;
  *(_QWORD *)(v13 + 40) = &alloc_name;
  v10->mCurrSize += 144i64;
  v14 = v10->mNumMemStructures;
  v15 = (signed __int64)v10 + 48 * v14;
  v10->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "Illusion.BufferPlat";
  *(_QWORD *)(v15 + 24) = v10->mCurrSize;
  *(_DWORD *)(v15 + 32) = 128;
  *(_QWORD *)(v15 + 40) = 0i64;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  v37 = (UFG::qMemoryPool *)v10->mCurrSize;
  *(_QWORD *)(v15 + 40) = &v37;
  v10->mCurrSize += 128i64;
  v16 = alloc_name;
  v17 = v10->mNumMemStructures;
  v18 = (signed __int64)v10 + 48 * v17;
  v10->mNumMemStructures = v17 + 1;
  *(_QWORD *)(v18 + 16) = "Illusion.BufferUser";
  *(_QWORD *)(v18 + 24) = v10->mCurrSize;
  *(_DWORD *)(v18 + 32) = 16;
  *(_QWORD *)(v18 + 40) = 0i64;
  *(_QWORD *)(v18 + 56) = 0i64;
  *(_QWORD *)(v18 + 48) = 0i64;
  v32 = v10->mCurrSize;
  *(_QWORD *)(v18 + 40) = &v32;
  v19 = (signed __int64)(v16 + 112);
  if ( v19 )
  {
    *(_QWORD *)(v18 + 56) = v19;
    *(_QWORD *)(v18 + 48) = v10->mCurrSize - v19;
  }
  v10->mCurrSize += 16i64;
  v20 = v37;
  v21 = v10->mNumMemStructures;
  v22 = (signed __int64)v10 + 48 * v21;
  v10->mNumMemStructures = v21 + 1;
  *(_QWORD *)(v22 + 16) = "Illusion.BufferUserPlat";
  *(_QWORD *)(v22 + 24) = v10->mCurrSize;
  *(_DWORD *)(v22 + 32) = 16;
  *(_QWORD *)(v22 + 40) = 0i64;
  *(_QWORD *)(v22 + 56) = 0i64;
  *(_QWORD *)(v22 + 48) = 0i64;
  v33 = v10->mCurrSize;
  *(_QWORD *)(v22 + 40) = &v33;
  if ( v20 )
  {
    *(_QWORD *)(v22 + 56) = v20;
    *(_QWORD *)(v22 + 48) = v10->mCurrSize - (_QWORD)v20;
  }
  v10->mCurrSize += 16i64;
  v23 = alloc_name;
  v24 = (v7 + 15) & 0xFFFFFFF0;
  v25 = v10->mNumMemStructures;
  v26 = (signed __int64)v10 + 48 * v25;
  v10->mNumMemStructures = v25 + 1;
  *(_QWORD *)(v26 + 16) = "Illusion.BufferData";
  *(_QWORD *)(v26 + 24) = v10->mCurrSize;
  *(_DWORD *)(v26 + 32) = v24;
  *(_QWORD *)(v26 + 40) = 0i64;
  *(_QWORD *)(v26 + 56) = 0i64;
  *(_QWORD *)(v26 + 48) = 0i64;
  v34 = v10->mCurrSize;
  *(_QWORD *)(v26 + 40) = &v34;
  v27 = (signed __int64)(v23 + 96);
  if ( v27 )
  {
    *(_QWORD *)(v26 + 56) = v27;
    *(_QWORD *)(v26 + 48) = v10->mCurrSize - v27;
  }
  v10->mCurrSize += v24;
  v28 = memory_pool;
  Illusion::MemImageSchema::Allocate(v10, memory_pool, allocation_params);
  v29 = alloc_name;
  memory_pool = (UFG::qMemoryPool *)alloc_name;
  if ( alloc_name )
  {
    UFG::qResourceData::qResourceData((UFG::qResourceData *)alloc_name, 0x92CDEC8F, v8, v9);
    *((_DWORD *)v29 + 23) = v7;
    *((_QWORD *)v29 + 16) = 0i64;
    *((_QWORD *)v29 + 15) = 0i64;
    *((_WORD *)v29 + 45) = 0;
    *((_QWORD *)v29 + 17) = 0i64;
  }
  v30 = v37;
  memory_pool = v37;
  if ( v37 )
  {
    v37->mNext = 0i64;
    *(_QWORD *)&v30->mInitializedUID = 0i64;
    v36 = &v30->mAutoAllocatedBuffer;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v30->mAutoAllocatedBuffer);
    UFG::qMemSet(&v30->mDataBuffer[16], 0, 0x48u);
    *(_DWORD *)&v30->mDataBuffer[8] = 0;
  }
  *((_BYTE *)alloc_name + 89) = 1;
  *((_QWORD *)alloc_name + 16) = v28;
  return (Illusion::Buffer *)alloc_name;
}

// File Line: 151
// RVA: 0xA1CA70
Illusion::Buffer *__fastcall Illusion::Factory::NewBuffer(const char *name, unsigned int name_uid, unsigned int byte_size, Illusion::MemImageSchema *schema, const char *alloc_name, UFG::qLinearAllocator *linear_allocator, unsigned __int64 allocation_params)
{
  unsigned int v7; // er14
  unsigned int v8; // er15
  const char *v9; // r12
  unsigned int v10; // ebx
  signed int v11; // eax
  char *v12; // rdi
  signed __int64 v13; // rax
  signed __int64 v14; // rax
  signed __int64 v15; // rcx

  v7 = byte_size;
  v8 = name_uid;
  v9 = name;
  v10 = (byte_size + 15) & 0xFFFFFFF0;
  v11 = (unsigned int)allocation_params >> 8;
  if ( (signed int)((unsigned int)allocation_params >> 8) < 16 )
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
  UFG::qResourceData::qResourceData((UFG::qResourceData *)v12, 0x92CDEC8F, v8, v9);
  *((_DWORD *)v12 + 23) = v7;
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
  Illusion::Buffer *v2; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qMemoryPool *v5; // rcx

  if ( buffer )
  {
    v2 = buffer;
    if ( wait )
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
    Illusion::BufferPlat::~BufferPlat((Illusion::BufferPlat *)&v2[1]);
    UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
    v3 = v2->mResourceHandles.mNode.mPrev;
    v4 = v2->mResourceHandles.mNode.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mResourceHandles.mNode.mPrev = &v2->mResourceHandles.mNode;
    v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
    v5 = v2->mMemoryPool;
    if ( v5 )
      UFG::qMemoryPool::Free(v5, v2);
    else
      operator delete[](v2);
  }
}

// File Line: 243
// RVA: 0xA1CF40
UFG::qResourceData *__fastcall Illusion::Factory::NewModel(const char *name, unsigned int name_uid, unsigned int num_meshes, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  unsigned __int64 v6; // rdi
  unsigned int v7; // er12
  const char *v8; // r13
  Illusion::MemImageSchema *v9; // rbx
  __int64 v10; // r9
  signed __int64 v11; // rcx
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  __int64 v14; // r8
  __int64 v15; // rcx
  signed __int64 v16; // rdx
  UFG::qResourceData *v17; // r8
  __int64 v18; // rcx
  signed __int64 v19; // rdx
  signed __int64 v20; // r8
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // r15
  unsigned int v25; // er9
  _QWORD *v26; // r8
  __int64 v27; // rcx
  signed __int64 v28; // rdx
  UFG::qBaseNodeRB **v29; // r10
  UFG::allocator::free_link *v30; // r9
  unsigned __int64 v31; // r10
  UFG::allocator::free_link *v32; // r8
  __int64 v33; // rcx
  signed __int64 v34; // rdx
  __int64 v35; // rcx
  signed __int64 v36; // rdx
  UFG::qMemoryPool *v37; // r14
  UFG::qResourceData *v38; // rbx
  __int64 v39; // rdi
  UFG::qBaseNodeRB *v40; // rcx
  char *v41; // rax
  char *v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rbx
  __int64 v46; // [rsp+30h] [rbp-30h]
  UFG::qMemoryPool *v47; // [rsp+38h] [rbp-28h]
  unsigned __int64 v48; // [rsp+40h] [rbp-20h]
  __int64 v49; // [rsp+48h] [rbp-18h]
  char *v50; // [rsp+50h] [rbp-10h]
  __int64 v51; // [rsp+58h] [rbp-8h]
  unsigned int v52; // [rsp+A8h] [rbp+48h]
  UFG::qResourceData *v53; // [rsp+B8h] [rbp+58h]

  v52 = name_uid;
  v49 = -2i64;
  v6 = num_meshes;
  v7 = name_uid;
  v8 = name;
  v9 = &Illusion::gMemImageSchema;
  if ( schema )
    v9 = schema;
  Illusion::MemImageSchema::Init(v9);
  v10 = v9->mNumMemStructures;
  v11 = (signed __int64)v9 + 48 * v10;
  v9->mNumMemStructures = v10 + 1;
  *(_QWORD *)(v11 + 16) = "Illusion.Model";
  *(_QWORD *)(v11 + 24) = v9->mCurrSize;
  *(_DWORD *)(v11 + 32) = 304;
  *(_QWORD *)(v11 + 40) = 0i64;
  *(_QWORD *)(v11 + 56) = 0i64;
  *(_QWORD *)(v11 + 48) = 0i64;
  v53 = (UFG::qResourceData *)v9->mCurrSize;
  *(_QWORD *)(v11 + 40) = &v53;
  v9->mCurrSize += 304i64;
  v12 = v9->mNumMemStructures;
  v13 = (signed __int64)v9 + 48 * v12;
  v9->mNumMemStructures = v12 + 1;
  *(_QWORD *)(v13 + 16) = "Illusion.ModelPlat";
  *(_QWORD *)(v13 + 24) = v9->mCurrSize;
  *(_DWORD *)(v13 + 32) = 16;
  *(_QWORD *)(v13 + 40) = 0i64;
  *(_QWORD *)(v13 + 56) = 0i64;
  *(_QWORD *)(v13 + 48) = 0i64;
  v46 = v9->mCurrSize;
  *(_QWORD *)(v13 + 40) = &v46;
  v9->mCurrSize += 16i64;
  v14 = v46;
  v15 = v9->mNumMemStructures;
  v16 = (signed __int64)v9 + 48 * v15;
  v9->mNumMemStructures = v15 + 1;
  *(_QWORD *)(v16 + 16) = "Illusion.ModelUserPlat";
  *(_QWORD *)(v16 + 24) = v9->mCurrSize;
  *(_DWORD *)(v16 + 32) = 16;
  *(_QWORD *)(v16 + 40) = 0i64;
  *(_QWORD *)(v16 + 56) = 0i64;
  *(_QWORD *)(v16 + 48) = 0i64;
  v47 = (UFG::qMemoryPool *)v9->mCurrSize;
  *(_QWORD *)(v16 + 40) = &v47;
  if ( v14 )
  {
    *(_QWORD *)(v16 + 56) = v14;
    *(_QWORD *)(v16 + 48) = v9->mCurrSize - v14;
  }
  v9->mCurrSize += 16i64;
  v17 = v53;
  v18 = v9->mNumMemStructures;
  v19 = (signed __int64)v9 + 48 * v18;
  v9->mNumMemStructures = v18 + 1;
  *(_QWORD *)(v19 + 16) = "Illusion.ModelUser";
  *(_QWORD *)(v19 + 24) = v9->mCurrSize;
  *(_DWORD *)(v19 + 32) = 16;
  *(_QWORD *)(v19 + 40) = 0i64;
  *(_QWORD *)(v19 + 56) = 0i64;
  *(_QWORD *)(v19 + 48) = 0i64;
  v48 = v9->mCurrSize;
  *(_QWORD *)(v19 + 40) = &v48;
  v20 = (signed __int64)&v17[2].mNode.mUID;
  if ( v20 )
  {
    *(_QWORD *)(v19 + 56) = v20;
    *(_QWORD *)(v19 + 48) = v9->mCurrSize - v20;
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
    v26 = &v23->mNext;
    do
    {
      v27 = v9->mNumMemStructures;
      v9->mNumMemStructures = v27 + 1;
      v28 = (signed __int64)v9 + 48 * v27;
      if ( v25 )
      {
        *(_QWORD *)(v28 + 16) = "UFG::qOffset<Mesh*>";
        *(_QWORD *)(v28 + 24) = v9->mCurrSize;
        *(_DWORD *)(v28 + 32) = 8;
        *(_QWORD *)(v28 + 40) = 0i64;
        *(_QWORD *)(v28 + 56) = 0i64;
        *(_QWORD *)(v28 + 48) = 0i64;
        if ( v26 )
        {
          *v26 = v9->mCurrSize;
          *(_QWORD *)(v28 + 40) = v26;
        }
      }
      else
      {
        v29 = v53[2].mNode.mChild;
        *(_QWORD *)(v28 + 16) = "UFG::qOffset<Mesh*>";
        *(_QWORD *)(v28 + 24) = v9->mCurrSize;
        *(_DWORD *)(v28 + 32) = 8;
        *(_QWORD *)(v28 + 40) = 0i64;
        *(_QWORD *)(v28 + 56) = 0i64;
        *(_QWORD *)(v28 + 48) = 0i64;
        if ( v26 )
        {
          *v26 = v9->mCurrSize;
          *(_QWORD *)(v28 + 40) = v26;
        }
        if ( v29 )
        {
          *(_QWORD *)(v28 + 56) = v29;
          *(_QWORD *)(v28 + 48) = v9->mCurrSize - (_QWORD)v29;
        }
      }
      v9->mCurrSize += 8i64;
      ++v25;
      ++v26;
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
      v32 = v30->mNext;
      v33 = v9->mNumMemStructures;
      v34 = (signed __int64)v9 + 48 * v33;
      v9->mNumMemStructures = v33 + 1;
      *(_QWORD *)(v34 + 16) = "Illusion.Mesh";
      *(_QWORD *)(v34 + 24) = v9->mCurrSize;
      *(_DWORD *)(v34 + 32) = 256;
      *(_QWORD *)(v34 + 40) = 0i64;
      *(_QWORD *)(v34 + 56) = 0i64;
      *(_QWORD *)(v34 + 48) = 0i64;
      if ( v32 )
      {
        *(_QWORD *)(v34 + 56) = v32;
        *(_QWORD *)(v34 + 48) = v9->mCurrSize - (_QWORD)v32;
      }
      v9->mCurrSize += 256i64;
      v35 = v9->mNumMemStructures;
      v36 = (signed __int64)v9 + 48 * v35;
      v9->mNumMemStructures = v35 + 1;
      *(_QWORD *)(v36 + 16) = "Illusion.MeshPlat";
      *(_QWORD *)(v36 + 24) = v9->mCurrSize;
      *(_DWORD *)(v36 + 32) = 16;
      *(_QWORD *)(v36 + 40) = 0i64;
      *(_QWORD *)(v36 + 56) = 0i64;
      *(_QWORD *)(v36 + 48) = 0i64;
      v9->mCurrSize += 16i64;
      ++v30;
      --v31;
    }
    while ( v31 );
    v7 = v52;
  }
  v37 = memory_pool;
  Illusion::MemImageSchema::Allocate(v9, memory_pool, allocation_params);
  v38 = v53;
  memory_pool = (UFG::qMemoryPool *)v53;
  if ( v53 )
  {
    UFG::qResourceData::qResourceData(v53, 0xA2ADCD77, v7, v8);
    v50 = (char *)&v38[1].mResourceHandles;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[1].mResourceHandles);
    v50 = &v38[1].mDebugName[12];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[1].mDebugName[12]);
    v50 = &v38[2].mDebugName[4];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[2].mDebugName[4]);
    v50 = (char *)&v38[3];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v38[3]);
    *(_QWORD *)&v38[2].mTypeUID = 0i64;
    v38[2].mResourceHandles.mNode.mPrev = 0i64;
    *(&v38[1].mNode.mUID + 1) = 0;
    LODWORD(v38[2].mResourceHandles.mNode.mNext) = 0;
  }
  memory_pool = v47;
  *(_QWORD *)&v53[2].mTypeUID = v37;
  LODWORD(v53[2].mNode.mChild[1]) = v6;
  HIDWORD(v53[1].mNode.mChild[0]) = 0;
  if ( (_DWORD)v6 )
  {
    v39 = 0i64;
    do
    {
      v40 = v53[2].mNode.mChild[0];
      if ( v40 )
        v41 = (char *)v53[2].mNode.mChild + (_QWORD)v40;
      else
        v41 = 0i64;
      v42 = &v41[v39];
      v43 = *(_QWORD *)&v41[v39];
      v44 = (__int64)&v42[v43];
      if ( !v43 )
        v44 = 0i64;
      memory_pool = (UFG::qMemoryPool *)v44;
      v50 = (char *)v44;
      if ( v44 )
      {
        v51 = v44;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)v44);
        v51 = v44 + 32;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v44 + 32));
        v51 = v44 + 64;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v44 + 64));
        `eh vector constructor iterator'(
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
  return v53;
}

// File Line: 311
// RVA: 0xA19A00
void __fastcall Illusion::Factory::Delete(Illusion::Model *model, bool wait)
{
  Illusion::Model *v2; // rbx
  UFG::qMemoryPool *v3; // rcx

  if ( model )
  {
    v2 = model;
    if ( wait )
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
    Illusion::Model::~Model(v2);
    v3 = v2->mMemoryPool;
    if ( v3 )
      UFG::qMemoryPool::Free(v3, v2);
    else
      operator delete[](v2);
  }
}

// File Line: 356
// RVA: 0xA1D620
UFG::qResourceData *__fastcall Illusion::Factory::NewShader(const char *name, unsigned int name_uid, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v5; // rbp
  unsigned int v6; // edi
  const char *v7; // rsi
  Illusion::MemImageSchema *v8; // rbx
  __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  UFG::qResourceData *v13; // r8
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // r8
  char *v17; // r8
  __int64 v18; // rcx
  signed __int64 v19; // rdx
  signed __int64 v20; // r8
  void *v21; // rcx
  Illusion::ShaderUser *v22; // rax
  void *dest; // [rsp+20h] [rbp-38h]
  Illusion::ShaderUser *v25; // [rsp+28h] [rbp-30h]
  unsigned __int64 v26; // [rsp+30h] [rbp-28h]
  __int64 v27; // [rsp+38h] [rbp-20h]
  void *v28; // [rsp+40h] [rbp-18h]
  Illusion::ShaderUser *v29; // [rsp+48h] [rbp-10h]
  UFG::qResourceData *v30; // [rsp+70h] [rbp+18h]

  v27 = -2i64;
  v5 = memory_pool;
  v6 = name_uid;
  v7 = name;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  v9 = v8->mNumMemStructures;
  v10 = (signed __int64)v8 + 48 * v9;
  v8->mNumMemStructures = v9 + 1;
  *(_QWORD *)(v10 + 16) = "Illusion.Shader";
  *(_QWORD *)(v10 + 24) = v8->mCurrSize;
  *(_DWORD *)(v10 + 32) = 1168;
  *(_QWORD *)(v10 + 40) = 0i64;
  *(_QWORD *)(v10 + 56) = 0i64;
  *(_QWORD *)(v10 + 48) = 0i64;
  v30 = (UFG::qResourceData *)v8->mCurrSize;
  *(_QWORD *)(v10 + 40) = &v30;
  v8->mCurrSize += 1168i64;
  v11 = v8->mNumMemStructures;
  v12 = (signed __int64)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *(_QWORD *)(v12 + 16) = "Illusion.ShaderPlat";
  *(_QWORD *)(v12 + 24) = v8->mCurrSize;
  *(_DWORD *)(v12 + 32) = 80;
  *(_QWORD *)(v12 + 40) = 0i64;
  *(_QWORD *)(v12 + 56) = 0i64;
  *(_QWORD *)(v12 + 48) = 0i64;
  dest = (void *)v8->mCurrSize;
  *(_QWORD *)(v12 + 40) = &dest;
  v8->mCurrSize += 80i64;
  v13 = v30;
  v14 = v8->mNumMemStructures;
  v15 = (signed __int64)v8 + 48 * v14;
  v8->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "Illusion.ShaderUser";
  *(_QWORD *)(v15 + 24) = v8->mCurrSize;
  *(_DWORD *)(v15 + 32) = 208;
  *(_QWORD *)(v15 + 40) = 0i64;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  v25 = (Illusion::ShaderUser *)v8->mCurrSize;
  *(_QWORD *)(v15 + 40) = &v25;
  v16 = (signed __int64)&v13[1].mNode.mChild[1];
  if ( v16 )
  {
    *(_QWORD *)(v15 + 56) = v16;
    *(_QWORD *)(v15 + 48) = v8->mCurrSize - v16;
  }
  v8->mCurrSize += 208i64;
  v17 = (char *)dest;
  v18 = v8->mNumMemStructures;
  v19 = (signed __int64)v8 + 48 * v18;
  v8->mNumMemStructures = v18 + 1;
  *(_QWORD *)(v19 + 16) = "Illusion.ShaderUserPlat";
  *(_QWORD *)(v19 + 24) = v8->mCurrSize;
  *(_DWORD *)(v19 + 32) = 16;
  *(_QWORD *)(v19 + 40) = 0i64;
  *(_QWORD *)(v19 + 56) = 0i64;
  *(_QWORD *)(v19 + 48) = 0i64;
  v26 = v8->mCurrSize;
  *(_QWORD *)(v19 + 40) = &v26;
  v20 = (signed __int64)(v17 + 48);
  if ( v20 )
  {
    *(_QWORD *)(v19 + 56) = v20;
    *(_QWORD *)(v19 + 48) = v8->mCurrSize - v20;
  }
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, v5, allocation_params);
  v28 = v30;
  if ( v30 )
    UFG::qResourceData::qResourceData(v30, 0x8B5561A1, v6, v7);
  v21 = dest;
  v28 = dest;
  if ( dest )
  {
    v22 = (Illusion::ShaderUser *)((char *)dest + 56);
    v29 = v22;
    v22->mOverride_OutputDepth.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v22->mOverride_OutputDepth.mPrev;
    v22->mOverride_OutputDepth.mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v22->mOverride_OutputDepth.mPrev;
    UFG::qMemSet(v21, 0, 0x30u);
  }
  v29 = v25;
  if ( v25 )
    Illusion::ShaderUser::ShaderUser(v25);
  return v30;
}

// File Line: 383
// RVA: 0xA19A50
void __fastcall Illusion::Factory::Delete(Illusion::Shader *shader)
{
  Illusion::Shader *v1; // rdi
  char *v2; // rbx
  __int64 v3; // rcx
  _QWORD *v4; // rax
  __int64 v5; // rax
  Illusion::ShaderUser *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax

  if ( shader )
  {
    v1 = shader;
    v2 = &shader[1].mDebugName[12];
    UFG::qList<Illusion::ShaderParam,Illusion::ShaderParam,1,0>::DeleteNodes((UFG::qList<Illusion::ShaderParam,Illusion::ShaderParam,1,0> *)&shader[1].mDebugName[12]);
    v3 = *(_QWORD *)v2;
    v4 = (_QWORD *)*((_QWORD *)v2 + 1);
    *(_QWORD *)(v3 + 8) = v4;
    *v4 = v3;
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
    v5 = v1->mShaderUser.mOffset;
    if ( v5 )
      v6 = (Illusion::ShaderUser *)((char *)&v1->mShaderUser + v5);
    else
      v6 = 0i64;
    Illusion::ShaderUser::~ShaderUser(v6);
    UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
    v7 = v1->mResourceHandles.mNode.mPrev;
    v8 = v1->mResourceHandles.mNode.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v1->mResourceHandles.mNode.mPrev = &v1->mResourceHandles.mNode;
    v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
    operator delete[](v1);
  }
}

// File Line: 407
// RVA: 0xA1D8A0
UFG::qResourceData *__fastcall Illusion::Factory::NewTexture(const char *name, unsigned int name_uid, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v5; // rdi
  unsigned int v6; // esi
  const char *v7; // rbp
  Illusion::MemImageSchema *v8; // rbx
  __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  UFG::qResourceData *v13; // r8
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // r8
  Illusion::TexturePlat *v17; // r8
  __int64 v18; // rcx
  signed __int64 v19; // rdx
  UFG::qResourceData *v20; // rbx
  UFG::qResourceHandle *v21; // rbx
  Illusion::TexturePlat *v23; // [rsp+20h] [rbp-38h]
  UFG::qResourceHandle *v24; // [rsp+28h] [rbp-30h]
  unsigned __int64 v25; // [rsp+30h] [rbp-28h]
  __int64 v26; // [rsp+38h] [rbp-20h]
  UFG::qResourceHandle *v27; // [rsp+40h] [rbp-18h]
  char *v28; // [rsp+48h] [rbp-10h]
  UFG::qResourceData *v29; // [rsp+70h] [rbp+18h]

  v26 = -2i64;
  v5 = memory_pool;
  v6 = name_uid;
  v7 = name;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  v9 = v8->mNumMemStructures;
  v10 = (signed __int64)v8 + 48 * v9;
  v8->mNumMemStructures = v9 + 1;
  *(_QWORD *)(v10 + 16) = "Illusion.Texture";
  *(_QWORD *)(v10 + 24) = v8->mCurrSize;
  *(_DWORD *)(v10 + 32) = 208;
  *(_QWORD *)(v10 + 40) = 0i64;
  *(_QWORD *)(v10 + 56) = 0i64;
  *(_QWORD *)(v10 + 48) = 0i64;
  v29 = (UFG::qResourceData *)v8->mCurrSize;
  *(_QWORD *)(v10 + 40) = &v29;
  v8->mCurrSize += 208i64;
  v11 = v8->mNumMemStructures;
  v12 = (signed __int64)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *(_QWORD *)(v12 + 16) = "Illusion.TexturePlat";
  *(_QWORD *)(v12 + 24) = v8->mCurrSize;
  *(_DWORD *)(v12 + 32) = 176;
  *(_QWORD *)(v12 + 40) = 0i64;
  *(_QWORD *)(v12 + 56) = 0i64;
  *(_QWORD *)(v12 + 48) = 0i64;
  v23 = (Illusion::TexturePlat *)v8->mCurrSize;
  *(_QWORD *)(v12 + 40) = &v23;
  v8->mCurrSize += 176i64;
  v13 = v29;
  v14 = v8->mNumMemStructures;
  v15 = (signed __int64)v8 + 48 * v14;
  v8->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "Illusion.TextureUser";
  *(_QWORD *)(v15 + 24) = v8->mCurrSize;
  *(_DWORD *)(v15 + 32) = 64;
  *(_QWORD *)(v15 + 40) = 0i64;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  v24 = (UFG::qResourceHandle *)v8->mCurrSize;
  *(_QWORD *)(v15 + 40) = &v24;
  v16 = (signed __int64)&v13[1].mNode.mUID;
  if ( v16 )
  {
    *(_QWORD *)(v15 + 56) = v16;
    *(_QWORD *)(v15 + 48) = v8->mCurrSize - v16;
  }
  v8->mCurrSize += 64i64;
  v17 = v23;
  v18 = v8->mNumMemStructures;
  v19 = (signed __int64)v8 + 48 * v18;
  v8->mNumMemStructures = v18 + 1;
  *(_QWORD *)(v19 + 16) = "Illusion.TextureUserPlat";
  *(_QWORD *)(v19 + 24) = v8->mCurrSize;
  *(_DWORD *)(v19 + 32) = 16;
  *(_QWORD *)(v19 + 40) = 0i64;
  *(_QWORD *)(v19 + 56) = 0i64;
  *(_QWORD *)(v19 + 48) = 0i64;
  v25 = v8->mCurrSize;
  *(_QWORD *)(v19 + 40) = &v25;
  if ( v17 )
  {
    *(_QWORD *)(v19 + 56) = v17;
    *(_QWORD *)(v19 + 48) = v8->mCurrSize - (_QWORD)v17;
  }
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, v5, allocation_params);
  v20 = v29;
  v27 = (UFG::qResourceHandle *)v29;
  if ( v29 )
  {
    UFG::qResourceData::qResourceData(v29, 0x8B43FABF, v6, v7);
    v28 = &v20[1].mDebugName[12];
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v20[1].mDebugName[12]);
  }
  v28 = (char *)v23;
  if ( v23 )
    Illusion::TexturePlat::TexturePlat(v23);
  v21 = v24;
  v28 = (char *)v24;
  if ( v24 )
  {
    v27 = v24;
    UFG::qResourceHandle::qResourceHandle(v24);
    v27 = v21 + 1;
    UFG::qResourceHandle::qResourceHandle(v21 + 1);
  }
  return v29;
}

// File Line: 435
// RVA: 0xA19B00
void __fastcall Illusion::Factory::Delete(Illusion::Texture *texture, bool wait)
{
  Illusion::Texture *v2; // rbx
  __int64 v3; // rax
  Illusion::eRenderPass::PassData *v4; // rcx

  if ( texture )
  {
    v2 = texture;
    if ( wait )
      Illusion::Engine::WaitUntilSafeToDelete(&Illusion::gEngine);
    v3 = v2->mTextureUser.mOffset;
    if ( v3 )
      v4 = (Illusion::eRenderPass::PassData *)((char *)&v2->mTextureUser + v3);
    else
      v4 = 0i64;
    Illusion::TextureUser::~TextureUser(v4);
    Illusion::TexturePlat::~TexturePlat((Illusion::TexturePlat *)v2[1].mNode.mChild);
    Illusion::Texture::~Texture(v2);
    operator delete[](v2);
  }
}

// File Line: 478
// RVA: 0xA1DB40
UFG::qResourceData *__fastcall Illusion::Factory::NewVertexDecl(Illusion::VertexStreamDescriptor *descriptor, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v4; // rbx
  Illusion::VertexStreamDescriptor *v5; // rsi
  const char *v6; // r12
  unsigned int v7; // er13
  int v8; // er15
  Illusion::MemImageSchema *v9; // rdi
  unsigned int v10; // er14
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  int v13; // ebx
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  UFG::qResourceData *v16; // r8
  __int64 v17; // rcx
  signed __int64 v18; // rdx
  signed __int64 v19; // r8
  __int64 v20; // r8
  __int64 v21; // rcx
  signed __int64 v22; // rdx
  signed __int64 v23; // r8
  UFG::qResourceData *v24; // r9
  signed int v25; // er8
  __int64 v26; // rcx
  signed __int64 v27; // rdx
  signed __int64 v28; // r9
  UFG::qResourceData *v29; // rdi
  UFG::qBaseNodeRB *v30; // rcx
  char *v31; // rcx
  signed __int64 v32; // rdi
  int v33; // eax
  unsigned __int64 v35; // [rsp+20h] [rbp-38h]
  UFG::qResourceData *v36; // [rsp+28h] [rbp-30h]
  unsigned __int64 v37; // [rsp+30h] [rbp-28h]
  void *source; // [rsp+38h] [rbp-20h]
  __int64 v39; // [rsp+40h] [rbp-18h]
  UFG::qResourceData *v40; // [rsp+48h] [rbp-10h]
  UFG::qResourceData *v41; // [rsp+A0h] [rbp+48h]
  __int64 v42; // [rsp+A8h] [rbp+50h]
  UFG::qMemoryPool *memory_poola; // [rsp+B0h] [rbp+58h]
  unsigned __int64 allocation_paramsa; // [rsp+B8h] [rbp+60h]

  allocation_paramsa = allocation_params;
  memory_poola = memory_pool;
  v39 = -2i64;
  v4 = schema;
  v5 = descriptor;
  v6 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)descriptor);
  v7 = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)v5);
  source = Illusion::VertexStreamDescriptor::GetElement(v5, 0, -1);
  v8 = Illusion::VertexStreamDescriptor::GetTotalElements(v5);
  v9 = &Illusion::gMemImageSchema;
  if ( v4 )
    v9 = v4;
  Illusion::MemImageSchema::Init(v9);
  v10 = 36 * v8;
  v11 = v9->mNumMemStructures;
  v12 = (signed __int64)v9 + 48 * v11;
  v9->mNumMemStructures = v11 + 1;
  *(_QWORD *)(v12 + 16) = "Illusion.VertexDecl";
  *(_QWORD *)(v12 + 24) = v9->mCurrSize;
  *(_DWORD *)(v12 + 32) = 128;
  v13 = 0;
  *(_QWORD *)(v12 + 40) = 0i64;
  *(_QWORD *)(v12 + 56) = 0i64;
  *(_QWORD *)(v12 + 48) = 0i64;
  v41 = (UFG::qResourceData *)v9->mCurrSize;
  *(_QWORD *)(v12 + 40) = &v41;
  v9->mCurrSize += 128i64;
  v14 = v9->mNumMemStructures;
  v15 = (signed __int64)v9 + 48 * v14;
  v9->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "Illusion.VertexDeclPlat";
  *(_QWORD *)(v15 + 24) = v9->mCurrSize;
  *(_DWORD *)(v15 + 32) = 32;
  *(_QWORD *)(v15 + 40) = 0i64;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  v42 = v9->mCurrSize;
  *(_QWORD *)(v15 + 40) = &v42;
  v9->mCurrSize += 32i64;
  v16 = v41;
  v17 = v9->mNumMemStructures;
  v18 = (signed __int64)v9 + 48 * v17;
  v9->mNumMemStructures = v17 + 1;
  *(_QWORD *)(v18 + 16) = "Illusion.VertexDeclUser";
  *(_QWORD *)(v18 + 24) = v9->mCurrSize;
  *(_DWORD *)(v18 + 32) = 16;
  *(_QWORD *)(v18 + 40) = 0i64;
  *(_QWORD *)(v18 + 56) = 0i64;
  *(_QWORD *)(v18 + 48) = 0i64;
  v35 = v9->mCurrSize;
  *(_QWORD *)(v18 + 40) = &v35;
  v19 = (signed __int64)&v16[1].mResourceHandles;
  if ( v19 )
  {
    *(_QWORD *)(v18 + 56) = v19;
    *(_QWORD *)(v18 + 48) = v9->mCurrSize - v19;
  }
  v9->mCurrSize += 16i64;
  v20 = v42;
  v21 = v9->mNumMemStructures;
  v22 = (signed __int64)v9 + 48 * v21;
  v9->mNumMemStructures = v21 + 1;
  *(_QWORD *)(v22 + 16) = "Illusion.VertexDeclUserPlat";
  *(_QWORD *)(v22 + 24) = v9->mCurrSize;
  *(_DWORD *)(v22 + 32) = 16;
  *(_QWORD *)(v22 + 40) = 0i64;
  *(_QWORD *)(v22 + 56) = 0i64;
  *(_QWORD *)(v22 + 48) = 0i64;
  v36 = (UFG::qResourceData *)v9->mCurrSize;
  *(_QWORD *)(v22 + 40) = &v36;
  v23 = v20 + 16;
  if ( v23 )
  {
    *(_QWORD *)(v22 + 56) = v23;
    *(_QWORD *)(v22 + 48) = v9->mCurrSize - v23;
  }
  v9->mCurrSize += 16i64;
  v24 = v41;
  v25 = (v10 + 15) & 0xFFFFFFF0;
  v26 = v9->mNumMemStructures;
  v27 = (signed __int64)v9 + 48 * v26;
  v9->mNumMemStructures = v26 + 1;
  *(_QWORD *)(v27 + 16) = "Illusion.VertexDeclData";
  *(_QWORD *)(v27 + 24) = v9->mCurrSize;
  *(_DWORD *)(v27 + 32) = v25;
  *(_QWORD *)(v27 + 40) = 0i64;
  *(_QWORD *)(v27 + 56) = 0i64;
  *(_QWORD *)(v27 + 48) = 0i64;
  v37 = v9->mCurrSize;
  *(_QWORD *)(v27 + 40) = &v37;
  v28 = (signed __int64)&v24[1];
  if ( v28 )
  {
    *(_QWORD *)(v27 + 56) = v28;
    *(_QWORD *)(v27 + 48) = v9->mCurrSize - v28;
  }
  v9->mCurrSize += v25;
  Illusion::MemImageSchema::Allocate(v9, memory_poola, allocation_paramsa);
  v29 = v41;
  v40 = v41;
  if ( v41 )
  {
    UFG::qResourceData::qResourceData(v41, 0x3E5FDA3Eu, v7, v6);
    LODWORD(v29[1].mNode.mChild[0]) = v8;
  }
  v40 = v36;
  v30 = v41[1].mNode.mParent;
  if ( v30 )
    v31 = (char *)&v30[2].mUID + (_QWORD)v41;
  else
    v31 = 0i64;
  UFG::qMemCopy(v31, source, v10);
  *(&v41[1].mNode.mUID + 1) = v5->mStreamRuntimeFlags;
  v32 = 100i64;
  do
  {
    v33 = Illusion::VertexStreamDescriptor::GetStreamSize(v5, v13);
    *(_DWORD *)((char *)&v41->mNode.mParent + v32) = v33;
    ++v13;
    v32 += 4i64;
  }
  while ( v13 < 4 );
  return v41;
}

// File Line: 541
// RVA: 0xA1C900
UFG::qResourceData *__fastcall Illusion::Factory::NewAlphaState(const char *name, unsigned int name_uid, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v5; // rdi
  unsigned int v6; // esi
  const char *v7; // rbp
  Illusion::MemImageSchema *v8; // rbx
  __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  UFG::qResourceData *v13; // rbx
  unsigned __int64 v15; // [rsp+20h] [rbp-38h]
  __int64 v16; // [rsp+28h] [rbp-30h]
  UFG::qResourceData *v17; // [rsp+30h] [rbp-28h]
  UFG::qResourceData *v18; // [rsp+70h] [rbp+18h]

  v16 = -2i64;
  v5 = memory_pool;
  v6 = name_uid;
  v7 = name;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  v9 = v8->mNumMemStructures;
  v10 = (signed __int64)v8 + 48 * v9;
  v8->mNumMemStructures = v9 + 1;
  *(_QWORD *)(v10 + 16) = "Illusion.AlphaState";
  *(_QWORD *)(v10 + 24) = v8->mCurrSize;
  *(_DWORD *)(v10 + 32) = 112;
  *(_QWORD *)(v10 + 40) = 0i64;
  *(_QWORD *)(v10 + 56) = 0i64;
  *(_QWORD *)(v10 + 48) = 0i64;
  v18 = (UFG::qResourceData *)v8->mCurrSize;
  *(_QWORD *)(v10 + 40) = &v18;
  v8->mCurrSize += 112i64;
  v11 = v8->mNumMemStructures;
  v12 = (signed __int64)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *(_QWORD *)(v12 + 16) = "Illusion.AlphaStatePlat";
  *(_QWORD *)(v12 + 24) = v8->mCurrSize;
  *(_DWORD *)(v12 + 32) = 16;
  *(_QWORD *)(v12 + 40) = 0i64;
  *(_QWORD *)(v12 + 56) = 0i64;
  *(_QWORD *)(v12 + 48) = 0i64;
  v15 = v8->mCurrSize;
  *(_QWORD *)(v12 + 40) = &v15;
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, v5, allocation_params);
  v13 = v18;
  v17 = v18;
  if ( v18 )
  {
    UFG::qResourceData::qResourceData(v18, 0x12C800F2u, v6, v7);
    LODWORD(v13[1].mNode.mParent) = 256;
    HIDWORD(v13[1].mNode.mParent) = 121634816;
    LOWORD(v13[1].mNode.mChild[0]) = 256;
    *(_DWORD *)((char *)v13[1].mNode.mChild + 2) = -61696;
    HIWORD(v13[1].mNode.mChild[0]) = 0;
  }
  return v18;
}

// File Line: 577
// RVA: 0xA1D4A0
UFG::qResourceData *__fastcall Illusion::Factory::NewRasterState(const char *name, unsigned int name_uid, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v5; // rdi
  unsigned int v6; // esi
  const char *v7; // rbp
  Illusion::MemImageSchema *v8; // rbx
  __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  UFG::qResourceData *v13; // rbx
  unsigned __int64 v15; // [rsp+20h] [rbp-28h]
  __int64 v16; // [rsp+28h] [rbp-20h]
  UFG::qResourceData *v17; // [rsp+30h] [rbp-18h]
  UFG::qResourceData *v18; // [rsp+60h] [rbp+18h]

  v16 = -2i64;
  v5 = memory_pool;
  v6 = name_uid;
  v7 = name;
  v8 = &Illusion::gMemImageSchema;
  if ( schema )
    v8 = schema;
  Illusion::MemImageSchema::Init(v8);
  v9 = v8->mNumMemStructures;
  v10 = (signed __int64)v8 + 48 * v9;
  v8->mNumMemStructures = v9 + 1;
  *(_QWORD *)(v10 + 16) = "Illusion.RasterState";
  *(_QWORD *)(v10 + 24) = v8->mCurrSize;
  *(_DWORD *)(v10 + 32) = 128;
  *(_QWORD *)(v10 + 40) = 0i64;
  *(_QWORD *)(v10 + 56) = 0i64;
  *(_QWORD *)(v10 + 48) = 0i64;
  v18 = (UFG::qResourceData *)v8->mCurrSize;
  *(_QWORD *)(v10 + 40) = &v18;
  v8->mCurrSize += 128i64;
  v11 = v8->mNumMemStructures;
  v12 = (signed __int64)v8 + 48 * v11;
  v8->mNumMemStructures = v11 + 1;
  *(_QWORD *)(v12 + 16) = "Illusion.RasterStatePlat";
  *(_QWORD *)(v12 + 24) = v8->mCurrSize;
  *(_DWORD *)(v12 + 32) = 16;
  *(_QWORD *)(v12 + 40) = 0i64;
  *(_QWORD *)(v12 + 56) = 0i64;
  *(_QWORD *)(v12 + 48) = 0i64;
  v15 = v8->mCurrSize;
  *(_QWORD *)(v12 + 40) = &v15;
  v8->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v8, v5, allocation_params);
  v13 = v18;
  v17 = v18;
  if ( v18 )
  {
    UFG::qResourceData::qResourceData(v18, 0x3BC715E0u, v6, v7);
    LODWORD(v13[1].mNode.mParent) = 196865;
    HIDWORD(v13[1].mNode.mParent) = 257;
    LODWORD(v13[1].mNode.mChild[0]) = 256;
    WORD2(v13[1].mNode.mChild[0]) = 0;
    *(_DWORD *)((char *)v13[1].mNode.mChild + 7) = 0;
    BYTE6(v13[1].mNode.mChild[0]) = 7;
    *(_DWORD *)((char *)&v13[1].mNode.mChild[1] + 3) = 458752;
    *(_DWORD *)((char *)&v13[1].mNode.mChild[1] + 7) = 16711680;
  }
  return v18;
}

