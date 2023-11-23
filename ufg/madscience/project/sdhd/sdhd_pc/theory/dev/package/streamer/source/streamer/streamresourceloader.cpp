// File Line: 93
// RVA: 0x22CEF0
void __fastcall UFG::StreamResourceLoader::ResetResourceTimings(UFG::StreamResourceLoader *this)
{
  __int64 v1; // rcx
  unsigned __int64 *v2; // rax
  __int64 v3; // rdx
  __int64 v4; // rdx
  unsigned __int64 *v5; // rax
  __int64 v6; // rdx
  unsigned __int64 *v7; // rax
  __int64 v8; // rdx
  unsigned __int64 *v9; // rax
  __int64 v10; // rdx
  unsigned __int64 *v11; // rax
  __int64 v12; // rdx
  unsigned __int64 *v13; // rax
  __int64 v14; // rdx
  unsigned __int64 *v15; // rax
  __int64 v16; // rdx
  unsigned __int64 *v17; // rax
  __int64 v18; // rdx
  unsigned __int64 *v19; // rax
  __int64 v20; // rdx
  unsigned __int64 *v21; // rax
  __int64 v22; // rdx
  unsigned __int64 *v23; // rax
  unsigned __int64 *v24; // rax
  __int64 v25; // rcx
  __int64 v26; // rdx
  __int64 v27; // rax

  v1 = 2i64;
  v2 = UFG::StreamResourceLoader::mPostDFLoadTotalTicksPerType;
  UFG::StreamResourceLoader::mWorstLoad.thisTicksTotal = 0i64;
  UFG::StreamResourceLoader::mWorstUnload.thisTicksTotal = 0i64;
  *(_QWORD *)UFG::StreamResourceLoader::mWorstUnload.thisCountPerType = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[2] = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[4] = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[6] = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[8] = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[10] = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[12] = 0i64;
  *(_QWORD *)&UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[14] = 0i64;
  UFG::StreamResourceLoader::mWorstUnload.thisCountPerType[16] = 0;
  v3 = 2i64;
  do
  {
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    v2 += 8;
    *(v2 - 5) = 0i64;
    *(v2 - 4) = 0i64;
    *(v2 - 3) = 0i64;
    *(v2 - 2) = 0i64;
    *(v2 - 1) = 0i64;
    --v3;
  }
  while ( v3 );
  *v2 = 0i64;
  v4 = 2i64;
  v5 = UFG::StreamResourceLoader::mPostDFLoadMaxUIDPerType;
  do
  {
    *v5 = 0i64;
    v5[1] = 0i64;
    v5[2] = 0i64;
    v5 += 8;
    *(v5 - 5) = 0i64;
    *(v5 - 4) = 0i64;
    *(v5 - 3) = 0i64;
    *(v5 - 2) = 0i64;
    *(v5 - 1) = 0i64;
    --v4;
  }
  while ( v4 );
  *v5 = 0i64;
  v6 = 2i64;
  v7 = UFG::StreamResourceLoader::mPostDFLoadMaxTicksPerType;
  do
  {
    *v7 = 0i64;
    v7[1] = 0i64;
    v7[2] = 0i64;
    v7 += 8;
    *(v7 - 5) = 0i64;
    *(v7 - 4) = 0i64;
    *(v7 - 3) = 0i64;
    *(v7 - 2) = 0i64;
    *(v7 - 1) = 0i64;
    --v6;
  }
  while ( v6 );
  *v7 = 0i64;
  v8 = 2i64;
  v9 = UFG::StreamResourceLoader::mPreDFUnloadTotalTicksPerType;
  do
  {
    *v9 = 0i64;
    v9[1] = 0i64;
    v9[2] = 0i64;
    v9 += 8;
    *(v9 - 5) = 0i64;
    *(v9 - 4) = 0i64;
    *(v9 - 3) = 0i64;
    *(v9 - 2) = 0i64;
    *(v9 - 1) = 0i64;
    --v8;
  }
  while ( v8 );
  *v9 = 0i64;
  v10 = 2i64;
  v11 = UFG::StreamResourceLoader::mPreDFUnloadMaxUIDPerType;
  do
  {
    *v11 = 0i64;
    v11[1] = 0i64;
    v11[2] = 0i64;
    v11 += 8;
    *(v11 - 5) = 0i64;
    *(v11 - 4) = 0i64;
    *(v11 - 3) = 0i64;
    *(v11 - 2) = 0i64;
    *(v11 - 1) = 0i64;
    --v10;
  }
  while ( v10 );
  *v11 = 0i64;
  v12 = 2i64;
  v13 = UFG::StreamResourceLoader::mPreDFUnloadMaxTicksPerType;
  do
  {
    *v13 = 0i64;
    v13[1] = 0i64;
    v13[2] = 0i64;
    v13 += 8;
    *(v13 - 5) = 0i64;
    *(v13 - 4) = 0i64;
    *(v13 - 3) = 0i64;
    *(v13 - 2) = 0i64;
    *(v13 - 1) = 0i64;
    --v12;
  }
  while ( v12 );
  *v13 = 0i64;
  v14 = 2i64;
  v15 = UFG::StreamResourceLoader::mUnloadTotalTicksPerType;
  do
  {
    *v15 = 0i64;
    v15[1] = 0i64;
    v15[2] = 0i64;
    v15 += 8;
    *(v15 - 5) = 0i64;
    *(v15 - 4) = 0i64;
    *(v15 - 3) = 0i64;
    *(v15 - 2) = 0i64;
    *(v15 - 1) = 0i64;
    --v14;
  }
  while ( v14 );
  *v15 = 0i64;
  v16 = 2i64;
  v17 = UFG::StreamResourceLoader::mUnloadMaxUIDPerType;
  do
  {
    *v17 = 0i64;
    v17[1] = 0i64;
    v17[2] = 0i64;
    v17 += 8;
    *(v17 - 5) = 0i64;
    *(v17 - 4) = 0i64;
    *(v17 - 3) = 0i64;
    *(v17 - 2) = 0i64;
    *(v17 - 1) = 0i64;
    --v16;
  }
  while ( v16 );
  *v17 = 0i64;
  v18 = 2i64;
  v19 = UFG::StreamResourceLoader::mUnloadMaxTicksPerType;
  do
  {
    *v19 = 0i64;
    v19[1] = 0i64;
    v19[2] = 0i64;
    v19 += 8;
    *(v19 - 5) = 0i64;
    *(v19 - 4) = 0i64;
    *(v19 - 3) = 0i64;
    *(v19 - 2) = 0i64;
    *(v19 - 1) = 0i64;
    --v18;
  }
  while ( v18 );
  *v19 = 0i64;
  v20 = 2i64;
  v21 = UFG::StreamResourceLoader::mLoadTotalTicksPerType;
  do
  {
    *v21 = 0i64;
    v21[1] = 0i64;
    v21[2] = 0i64;
    v21 += 8;
    *(v21 - 5) = 0i64;
    *(v21 - 4) = 0i64;
    *(v21 - 3) = 0i64;
    *(v21 - 2) = 0i64;
    *(v21 - 1) = 0i64;
    --v20;
  }
  while ( v20 );
  *v21 = 0i64;
  v22 = 2i64;
  v23 = UFG::StreamResourceLoader::mLoadMaxUIDPerType;
  do
  {
    *v23 = 0i64;
    v23[1] = 0i64;
    v23[2] = 0i64;
    v23 += 8;
    *(v23 - 5) = 0i64;
    *(v23 - 4) = 0i64;
    *(v23 - 3) = 0i64;
    *(v23 - 2) = 0i64;
    *(v23 - 1) = 0i64;
    --v22;
  }
  while ( v22 );
  *v23 = 0i64;
  v24 = UFG::StreamResourceLoader::mLoadMaxTicksPerType;
  do
  {
    *v24 = 0i64;
    v24[1] = 0i64;
    v24[2] = 0i64;
    v24 += 8;
    *(v24 - 5) = 0i64;
    *(v24 - 4) = 0i64;
    *(v24 - 3) = 0i64;
    *(v24 - 2) = 0i64;
    *(v24 - 1) = 0i64;
    --v1;
  }
  while ( v1 );
  *v24 = 0i64;
  v25 = 0i64;
  v26 = 17i64;
  v27 = 0i64;
  do
  {
    UFG::StreamResourceLoader::mWorstLoad.thisCountPerType[v25] = 0;
    UFG::StreamResourceLoader::mWorstLoad.thisTicksPerType[v27++] = 0i64;
    ++v25;
    --v26;
  }
  while ( v26 );
}

// File Line: 275
// RVA: 0x146FDC0
__int64 UFG::StreamResourceLoader::_dynamic_initializer_for__smResourceTimings__()
{
  return atexit((int (__fastcall *)())UFG::StreamResourceLoader::_dynamic_atexit_destructor_for__smResourceTimings__);
}

// File Line: 280
// RVA: 0x22A8C0
__int64 __fastcall UFG::StreamResourceLoader::Load(
        unsigned int *buffer,
        __int64 num_bytes,
        const char *debug_identifier,
        UFG::StreamerMetrics::DATA_TYPE end_data_type,
        bool (__fastcall *fnFilter)(UFG::qChunk *))
{
  __int64 v5; // r15
  int v6; // r13d
  unsigned int *v7; // rbx
  unsigned int *v8; // rbp
  __int64 v9; // rdi
  UFG::qBaseTreeRB *v10; // rax
  unsigned int v11; // esi
  __int64 v12; // r9
  unsigned __int64 (*v13)[2]; // rcx
  __int64 v14; // rdi
  UFG::qBaseTreeRB *v15; // rax
  __int64 v16; // rax
  unsigned __int64 (*v17)[2]; // rcx

  v5 = end_data_type;
  v6 = (int)buffer;
  ++foo_dfsdgs;
  v7 = buffer;
  v8 = (unsigned int *)((char *)buffer + (unsigned int)num_bytes);
  if ( end_data_type == DATA_UNKNOWN )
  {
    if ( buffer < v8 )
    {
      do
      {
        if ( *v7
          && (!fnFilter
           || ((unsigned __int8 (__fastcall *)(unsigned int *, __int64, const char *))fnFilter)(
                v7,
                num_bytes,
                debug_identifier)) )
        {
          v9 = v7[3];
          if ( (_S2_9 & 1) == 0 )
          {
            _S2_9 |= 1u;
            qword_1423A8CE0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
          }
          num_bytes = *(unsigned int *)((char *)v7 + v9 + 0x40);
          if ( (_DWORD)num_bytes )
          {
            v10 = UFG::qBaseTreeRB::Get(qword_1423A8CE0, num_bytes);
            if ( v10 )
            {
              if ( v10 != (UFG::qBaseTreeRB *)8 )
                (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)&v10[-1].mCount + 72i64))(
                  &v10[-1].mCount,
                  (__int64)v7 + v9 + 16);
            }
          }
        }
        v7 = (unsigned int *)((char *)v7 + ((v7[1] + 3) & 0xFFFFFFFC) + 16);
      }
      while ( v7 < v8 );
    }
    return (unsigned int)((_DWORD)v7 - v6);
  }
  if ( buffer >= v8 )
    return (unsigned int)((_DWORD)v7 - v6);
  v11 = 0;
  while ( 1 )
  {
    v12 = *v7;
    if ( (int)v5 >= DATA_TERRAIN )
    {
LABEL_21:
      if ( (_DWORD)v12
        && (!fnFilter
         || ((unsigned __int8 (__fastcall *)(unsigned int *, __int64, const char *))fnFilter)(
              v7,
              num_bytes,
              debug_identifier)) )
      {
        v14 = v7[3];
        if ( (_S2_9 & 1) == 0 )
        {
          _S2_9 |= 1u;
          qword_1423A8CE0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
        }
        num_bytes = *(unsigned int *)((char *)v7 + v14 + 64);
        if ( (_DWORD)num_bytes )
        {
          v15 = UFG::qBaseTreeRB::Get(qword_1423A8CE0, num_bytes);
          if ( v15 )
          {
            if ( v15 != (UFG::qBaseTreeRB *)8 )
              (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)&v15[-1].mCount + 72i64))(
                &v15[-1].mCount,
                (__int64)v7 + v14 + 16);
          }
        }
      }
      goto LABEL_30;
    }
    if ( (_DWORD)v12 )
      break;
LABEL_30:
    v7 = (unsigned int *)((char *)v7 + ((v7[1] + 3) & 0xFFFFFFFC) + 16);
    if ( v7 >= v8 )
      return (unsigned int)((_DWORD)v7 - v6);
  }
  LODWORD(num_bytes) = 0;
  v13 = sTypeToChunkUIDLookup[v5];
  while ( (*v13)[0] != v12 )
  {
    num_bytes = (unsigned int)(num_bytes + 1);
    ++v13;
    if ( (unsigned int)num_bytes >= 3 )
      goto LABEL_21;
  }
  if ( v7 < v8 )
  {
    v16 = *v7;
    if ( (_DWORD)v16 )
    {
      v17 = sTypeToChunkUIDLookup[v5];
      do
      {
        if ( (*v17)[0] == v16 )
          break;
        ++v11;
        ++v17;
      }
      while ( v11 < 3 );
    }
  }
  return (unsigned int)((_DWORD)v7 - v6);
}

// File Line: 527
// RVA: 0x22BB60
void __fastcall UFG::StreamResourceLoader::OnVRAMMove(char *buffer, unsigned int num_bytes)
{
  __int64 v2; // rdi
  char *i; // rdi

  v2 = num_bytes;
  UFG::qResourceWarehouse::Instance();
  for ( i = &buffer[v2]; buffer < i; buffer += ((*((_DWORD *)buffer + 1) + 3) & 0xFFFFFFFC) + 16 )
  {
    if ( *(_DWORD *)buffer == -843079536 )
      HandleDamageTrack::ResolveReferences((Illusion::Texture *)&buffer[*((unsigned int *)buffer + 3) + 16]);
  }
}

// File Line: 554
// RVA: 0x22C2D0
void __fastcall UFG::StreamResourceLoader::PreMove(char *buffer, unsigned int num_bytes)
{
  _DWORD *v2; // rbx
  char *v3; // rdi
  UFG::qResourceWarehouse *i; // rsi
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax

  v2 = buffer;
  v3 = &buffer[num_bytes];
  for ( i = UFG::qResourceWarehouse::Instance();
        v2 < (_DWORD *)v3;
        v2 = (_DWORD *)((char *)v2 + ((v2[1] + 3) & 0xFFFFFFFC) + 16) )
  {
    if ( *v2 )
    {
      v5 = *(_DWORD *)((char *)v2 + (unsigned int)v2[3] + 64);
      if ( v5 )
      {
        v6 = UFG::qBaseTreeRB::Get(&i->mInventoryTree.mTree, v5);
        if ( v6 )
        {
          if ( v6 != (UFG::qBaseTreeRB *)8 )
            (*(void (__fastcall **)(int *, _DWORD *))(*(_QWORD *)&v6[-1].mCount + 120i64))(&v6[-1].mCount, v2);
        }
      }
    }
  }
}

// File Line: 579
// RVA: 0x22C240
void __fastcall UFG::StreamResourceLoader::PostMove(char *buffer, unsigned int num_bytes)
{
  _DWORD *v2; // rbx
  char *v3; // rdi
  UFG::qResourceWarehouse *i; // rsi
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax

  v2 = buffer;
  v3 = &buffer[num_bytes];
  for ( i = UFG::qResourceWarehouse::Instance();
        v2 < (_DWORD *)v3;
        v2 = (_DWORD *)((char *)v2 + ((v2[1] + 3) & 0xFFFFFFFC) + 16) )
  {
    if ( *v2 )
    {
      v5 = *(_DWORD *)((char *)v2 + (unsigned int)v2[3] + 64);
      if ( v5 )
      {
        v6 = UFG::qBaseTreeRB::Get(&i->mInventoryTree.mTree, v5);
        if ( v6 )
        {
          if ( v6 != (UFG::qBaseTreeRB *)8 )
            (*(void (__fastcall **)(int *, _DWORD *))(*(_QWORD *)&v6[-1].mCount + 128i64))(&v6[-1].mCount, v2);
        }
      }
    }
  }
}

// File Line: 812
// RVA: 0x226DF0
void __fastcall UFG::StreamResourceLoader::LoadedFile::LoadedFile(
        UFG::StreamResourceLoader::LoadedFile *this,
        const char *filename)
{
  unsigned int v4; // eax

  v4 = UFG::qStringHash32(filename, 0xFFFFFFFF);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v4;
  this->meState = STATE_LOAD_QUEUED;
  UFG::qString::qString(&this->mFilename, filename);
  this->mData = 0i64;
  this->mAllocFlags = 0;
  this->mpPool = 0i64;
  this->mfnChunkFilter = 0i64;
}

// File Line: 832
// RVA: 0x146FD50
__int64 UFG::StreamResourceLoader::_dynamic_initializer_for__smLoadedFiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::StreamResourceLoader::smLoadedFiles.mTree);
  return atexit((int (__fastcall *)())UFG::StreamResourceLoader::_dynamic_atexit_destructor_for__smLoadedFiles__);
}

// File Line: 835
// RVA: 0x22EB60
void __fastcall UFG::StreamResourceLoader::UnloadInternal(UFG::StreamResourceLoader::LoadedFile *loaded_file)
{
  char *mData; // rdi
  __int64 mDataSize; // rbp
  char *i; // rbp
  __int64 v5; // rbx
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qMemoryPool *mpPool; // rcx
  char *v9; // rdx

  mData = (char *)loaded_file->mData;
  if ( mData )
  {
    mDataSize = loaded_file->mDataSize;
    UFG::qResourceWarehouse::Instance();
    for ( i = &mData[mDataSize]; mData < i; mData += ((*((_DWORD *)mData + 1) + 3) & 0xFFFFFFFC) + 0x10 )
    {
      if ( *(_DWORD *)mData )
      {
        v5 = *((unsigned int *)mData + 3);
        if ( (_S3_7 & 1) == 0 )
        {
          _S3_7 |= 1u;
          qword_1423A8CF0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
        }
        v6 = *(_DWORD *)&mData[v5 + 0x40];
        if ( v6 )
        {
          v7 = UFG::qBaseTreeRB::Get(qword_1423A8CF0, v6);
          if ( v7 )
          {
            if ( v7 != (UFG::qBaseTreeRB *)8 )
              (*(void (__fastcall **)(int *, char *))(*(_QWORD *)&v7[-1].mCount + 0x50i64))(
                &v7[-1].mCount,
                &mData[v5 + 16]);
          }
        }
      }
    }
    mpPool = loaded_file->mpPool;
    v9 = (char *)loaded_file->mData;
    if ( v9 )
    {
      if ( !mpPool )
        mpPool = UFG::gMainMemoryPool;
      UFG::qMemoryPool::Free(mpPool, v9);
    }
    loaded_file->mData = 0i64;
    loaded_file->mDataSize = 0;
  }
}

// File Line: 855
// RVA: 0x22ACF0
__int64 __fastcall UFG::StreamResourceLoader::LoadInternal(UFG::StreamResourceLoader::LoadedFile *loaded_file)
{
  char v2; // si
  char *dbg_tag; // rcx
  unsigned int mAllocFlags; // r9d
  UFG::qMemoryPool *mpPool; // r8
  unsigned int v6; // edi
  UFG::BIGFileIndex *v7; // rax
  unsigned int *v8; // r10
  unsigned int v9; // ecx
  char *mData; // r8
  bool (__fastcall *mfnChunkFilter)(UFG::qChunk *); // rax
  __int64 loaded_size; // [rsp+40h] [rbp+8h] BYREF

  v2 = 0;
  UFG::StreamResourceLoader::UnloadInternal(loaded_file);
  dbg_tag = loaded_file->mFilename.mData;
  mAllocFlags = loaded_file->mAllocFlags;
  mpPool = loaded_file->mpPool;
  v6 = 0;
  loaded_size = 0i64;
  v7 = UFG::StreamFileWrapper::ReadEntireFile(dbg_tag, &loaded_size, mpPool, mAllocFlags, dbg_tag);
  v8 = (unsigned int *)v7;
  if ( v7 )
  {
    v9 = loaded_size;
    mData = loaded_file->mFilename.mData;
    loaded_file->mData = v7;
    mfnChunkFilter = loaded_file->mfnChunkFilter;
    loaded_file->mDataSize = v9;
    UFG::StreamResourceLoader::Load(v8, v9, mData, DATA_UNKNOWN, mfnChunkFilter);
    loaded_file->meState = STATE_EMPTY;
    v2 = 1;
  }
  else
  {
    UFG::qPrintf(
      "WARNING: StreamResourceLoader::Load() failed, file_name[%s] since is doesnt exist or has a fileSize of zero\n",
      loaded_file->mFilename.mData);
  }
  LOBYTE(v6) = v2 != 0;
  return v6;
}

// File Line: 883
// RVA: 0x22E9E0
void __fastcall UFG::StreamResourceLoader::StreamResourceLoaderFileCallback(
        const char *filename,
        unsigned int *data,
        unsigned int fileSize,
        UFG::qBaseNodeRB *param)
{
  bool (__fastcall *fnFilter)(UFG::qChunk *); // rax
  const char *v7; // r8
  __int64 v9; // rdx
  UFG::qBaseNodeRB *v10; // rax

  fnFilter = *(bool (__fastcall **)(UFG::qChunk *))&param[3].mUID;
  LODWORD(param[3].mChild[0]) = fileSize;
  v7 = (const char *)param[2].mChild[1];
  param[3].mParent = (UFG::qBaseNodeRB *)data;
  UFG::StreamResourceLoader::Load(data, fileSize, v7, DATA_UNKNOWN, fnFilter);
  UFG::qBaseTreeRB::Add(&UFG::StreamResourceLoader::smLoadedFiles.mTree, param);
  v10 = param[1].mChild[0];
  LODWORD(param[1].mParent) = 1;
  if ( v10 )
  {
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(const char *, __int64, UFG::qBaseNodeRB *))v10)(filename, v9, param[1].mChild[1]);
  }
}

// File Line: 917
// RVA: 0x22ADA0
char __fastcall UFG::StreamResourceLoader::LoadResourceFile(
        const char *filename,
        UFG::qMemoryPool *pool,
        unsigned int alloc_flags,
        bool (__fastcall *filter)(UFG::qChunk *),
        void (__fastcall *callback)(const char *, bool, void *),
        void *callbackParam)
{
  UFG::allocator::free_link *v10; // rax
  UFG::StreamResourceLoader::LoadedFile *v11; // rax
  UFG::StreamResourceLoader::LoadedFile *v12; // rbx

  v10 = UFG::qMalloc(0x80ui64, "StreamResourceLoader::LoadedFile", 0i64);
  if ( v10 )
  {
    UFG::StreamResourceLoader::LoadedFile::LoadedFile((UFG::StreamResourceLoader::LoadedFile *)v10, filename);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v12->mpPool = pool;
  v12->mAllocFlags = alloc_flags;
  v12->mfnChunkFilter = filter;
  v12->mfnCallback = callback;
  v12->mCallbackParam = callbackParam;
  if ( callback )
  {
    UFG::StreamFileWrapper::ReadEntireFileAsync(
      v12->mFilename.mData,
      STREAM_DATA_HIGH_PRIORITY,
      UFG::StreamResourceLoader::StreamResourceLoaderFileCallback,
      v12,
      pool,
      alloc_flags,
      v12->mFilename.mData);
    return 1;
  }
  else if ( (unsigned int)UFG::StreamResourceLoader::LoadInternal(v12) )
  {
    UFG::qBaseTreeRB::Add(&UFG::StreamResourceLoader::smLoadedFiles.mTree, &v12->mNode);
    return 1;
  }
  else
  {
    UFG::qString::~qString(&v12->mFilename);
    operator delete[](v12);
    return 0;
  }
}

// File Line: 958
// RVA: 0x22EC60
char __fastcall UFG::StreamResourceLoader::UnloadResourceFile(const char *filename)
{
  UFG::StreamResourceLoader::LoadedFile *Head; // rbx

  Head = (UFG::StreamResourceLoader::LoadedFile *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::StreamResourceLoader::smLoadedFiles);
  if ( !Head )
    return 0;
  while ( (unsigned int)UFG::qStringCompareInsensitive(Head->mFilename.mData, filename, -1) )
  {
    Head = (UFG::StreamResourceLoader::LoadedFile *)UFG::qBaseTreeRB::GetNext(
                                                      &UFG::StreamResourceLoader::smLoadedFiles.mTree,
                                                      &Head->mNode);
    if ( !Head )
      return 0;
  }
  UFG::StreamResourceLoader::UnloadInternal(Head);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::StreamResourceLoader::smLoadedFiles,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head);
  UFG::qString::~qString(&Head->mFilename);
  operator delete[](Head);
  return 1;
}

