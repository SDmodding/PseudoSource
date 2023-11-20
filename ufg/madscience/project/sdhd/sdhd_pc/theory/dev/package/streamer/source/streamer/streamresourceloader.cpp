// File Line: 93
// RVA: 0x22CEF0
void __fastcall UFG::StreamResourceLoader::ResetResourceTimings(UFG::StreamResourceLoader *this)
{
  signed __int64 v1; // rcx
  unsigned __int64 *v2; // rax
  signed __int64 v3; // rdx
  signed __int64 v4; // rdx
  unsigned __int64 *v5; // rax
  signed __int64 v6; // rdx
  unsigned __int64 *v7; // rax
  signed __int64 v8; // rdx
  unsigned __int64 *v9; // rax
  signed __int64 v10; // rdx
  unsigned __int64 *v11; // rax
  signed __int64 v12; // rdx
  unsigned __int64 *v13; // rax
  signed __int64 v14; // rdx
  unsigned __int64 *v15; // rax
  signed __int64 v16; // rdx
  unsigned __int64 *v17; // rax
  signed __int64 v18; // rdx
  unsigned __int64 *v19; // rax
  signed __int64 v20; // rdx
  unsigned __int64 *v21; // rax
  signed __int64 v22; // rdx
  unsigned __int64 *v23; // rax
  unsigned __int64 *v24; // rax
  __int64 v25; // rcx
  signed __int64 v26; // rdx
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
    UFG::StreamResourceLoader::mWorstLoad.thisTicksPerType[v27] = 0i64;
    ++v27;
    ++v25;
    --v26;
  }
  while ( v26 );
}

// File Line: 275
// RVA: 0x146FDC0
__int64 UFG::StreamResourceLoader::_dynamic_initializer_for__smResourceTimings__()
{
  return atexit(UFG::StreamResourceLoader::_dynamic_atexit_destructor_for__smResourceTimings__);
}

// File Line: 280
// RVA: 0x22A8C0
__int64 __fastcall UFG::StreamResourceLoader::Load(void *buffer, __int64 num_bytes, const char *debug_identifier, UFG::StreamerMetrics::DATA_TYPE end_data_type, bool (__fastcall *fnFilter)(UFG::qChunk *))
{
  __int64 v5; // r15
  int v6; // er13
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
  v6 = (signed int)buffer;
  ++foo_dfsdgs;
  v7 = (unsigned int *)buffer;
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
          if ( !(_S2_9 & 1) )
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
                (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)&v10[-1].mCount + 72i64))(
                  &v10[-1].mCount,
                  (signed __int64)v7 + v9 + 16);
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
    if ( (signed int)v5 >= DATA_TERRAIN )
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
        if ( !(_S2_9 & 1) )
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
              (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)&v15[-1].mCount + 72i64))(
                &v15[-1].mCount,
                (signed __int64)v7 + v14 + 16);
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
void __fastcall UFG::StreamResourceLoader::OnVRAMMove(void *buffer, unsigned int num_bytes)
{
  __int64 v2; // rdi
  char *v3; // rbx
  char *i; // rdi

  v2 = num_bytes;
  v3 = (char *)buffer;
  UFG::qResourceWarehouse::Instance();
  for ( i = &v3[v2]; v3 < i; v3 += ((*((_DWORD *)v3 + 1) + 3) & 0xFFFFFFFC) + 16 )
  {
    if ( *(_DWORD *)v3 == -843079536 )
      HandleDamageTrack::ResolveReferences((Illusion::Texture *)&v3[*((unsigned int *)v3 + 3) + 16]);
  }
}

// File Line: 554
// RVA: 0x22C2D0
void __fastcall UFG::StreamResourceLoader::PreMove(void *buffer, unsigned int num_bytes)
{
  char *v2; // rbx
  char *v3; // rdi
  UFG::qResourceWarehouse *i; // rsi
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax

  v2 = (char *)buffer;
  v3 = (char *)buffer + num_bytes;
  for ( i = UFG::qResourceWarehouse::Instance(); v2 < v3; v2 += ((*((_DWORD *)v2 + 1) + 3) & 0xFFFFFFFC) + 16 )
  {
    if ( *(_DWORD *)v2 )
    {
      v5 = *(_DWORD *)&v2[*((unsigned int *)v2 + 3) + 64];
      if ( v5 )
      {
        v6 = UFG::qBaseTreeRB::Get(&i->mInventoryTree.mTree, v5);
        if ( v6 )
        {
          if ( v6 != (UFG::qBaseTreeRB *)8 )
            (*(void (__fastcall **)(int *, char *))(*(_QWORD *)&v6[-1].mCount + 120i64))(&v6[-1].mCount, v2);
        }
      }
    }
  }
}

// File Line: 579
// RVA: 0x22C240
void __fastcall UFG::StreamResourceLoader::PostMove(void *buffer, unsigned int num_bytes)
{
  char *v2; // rbx
  char *v3; // rdi
  UFG::qResourceWarehouse *i; // rsi
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax

  v2 = (char *)buffer;
  v3 = (char *)buffer + num_bytes;
  for ( i = UFG::qResourceWarehouse::Instance(); v2 < v3; v2 += ((*((_DWORD *)v2 + 1) + 3) & 0xFFFFFFFC) + 16 )
  {
    if ( *(_DWORD *)v2 )
    {
      v5 = *(_DWORD *)&v2[*((unsigned int *)v2 + 3) + 64];
      if ( v5 )
      {
        v6 = UFG::qBaseTreeRB::Get(&i->mInventoryTree.mTree, v5);
        if ( v6 )
        {
          if ( v6 != (UFG::qBaseTreeRB *)8 )
            (*(void (__fastcall **)(int *, char *))(*(_QWORD *)&v6[-1].mCount + 128i64))(&v6[-1].mCount, v2);
        }
      }
    }
  }
}

// File Line: 812
// RVA: 0x226DF0
void __fastcall UFG::StreamResourceLoader::LoadedFile::LoadedFile(UFG::StreamResourceLoader::LoadedFile *this, const char *filename)
{
  const char *v2; // rbx
  UFG::StreamResourceLoader::LoadedFile *v3; // rdi
  unsigned int v4; // eax

  v2 = filename;
  v3 = this;
  v4 = UFG::qStringHash32(filename, 0xFFFFFFFF);
  v3->mNode.mParent = 0i64;
  v3->mNode.mChild[0] = 0i64;
  v3->mNode.mChild[1] = 0i64;
  v3->mNode.mUID = v4;
  v3->meState = 2;
  UFG::qString::qString(&v3->mFilename, v2);
  v3->mData = 0i64;
  v3->mAllocFlags = 0;
  v3->mpPool = 0i64;
  v3->mfnChunkFilter = 0i64;
}

// File Line: 832
// RVA: 0x146FD50
__int64 UFG::StreamResourceLoader::_dynamic_initializer_for__smLoadedFiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::StreamResourceLoader::smLoadedFiles.mTree);
  return atexit(UFG::StreamResourceLoader::_dynamic_atexit_destructor_for__smLoadedFiles__);
}

// File Line: 835
// RVA: 0x22EB60
void __fastcall UFG::StreamResourceLoader::UnloadInternal(UFG::StreamResourceLoader::LoadedFile *loaded_file)
{
  UFG::StreamResourceLoader::LoadedFile *v1; // rsi
  char *v2; // rdi
  __int64 v3; // rbp
  char *i; // rbp
  __int64 v5; // rbx
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qMemoryPool *v8; // rcx
  void *v9; // rdx

  v1 = loaded_file;
  v2 = (char *)loaded_file->mData;
  if ( v2 )
  {
    v3 = loaded_file->mDataSize;
    UFG::qResourceWarehouse::Instance();
    for ( i = &v2[v3]; v2 < i; v2 += ((*((_DWORD *)v2 + 1) + 3) & 0xFFFFFFFC) + 0x10 )
    {
      if ( *(_DWORD *)v2 )
      {
        v5 = *((unsigned int *)v2 + 3);
        if ( !(_S3_7 & 1) )
        {
          _S3_7 |= 1u;
          qword_1423A8CF0 = (UFG::qBaseTreeRB *)UFG::qResourceWarehouse::Instance();
        }
        v6 = *(_DWORD *)&v2[v5 + 0x40];
        if ( v6 )
        {
          v7 = UFG::qBaseTreeRB::Get(qword_1423A8CF0, v6);
          if ( v7 )
          {
            if ( v7 != (UFG::qBaseTreeRB *)8 )
              (*(void (__fastcall **)(int *, char *))(*(_QWORD *)&v7[-1].mCount + 0x50i64))(
                &v7[-1].mCount,
                &v2[v5 + 16]);
          }
        }
      }
    }
    v8 = v1->mpPool;
    v9 = v1->mData;
    if ( v9 )
    {
      if ( !v8 )
        v8 = UFG::gMainMemoryPool;
      UFG::qMemoryPool::Free(v8, v9);
    }
    v1->mData = 0i64;
    v1->mDataSize = 0;
  }
}

// File Line: 855
// RVA: 0x22ACF0
__int64 __fastcall UFG::StreamResourceLoader::LoadInternal(UFG::StreamResourceLoader::LoadedFile *loaded_file)
{
  UFG::StreamResourceLoader::LoadedFile *v1; // rbx
  char v2; // si
  const char *v3; // rcx
  unsigned int v4; // er9
  UFG::qMemoryPool *v5; // r8
  unsigned int v6; // edi
  char *dbg_tag; // ST20_8
  UFG::BIGFileIndex *v8; // rax
  UFG::BIGFileIndex *v9; // r10
  unsigned int v10; // ecx
  const char *v11; // r8
  bool (__fastcall *v12)(UFG::qChunk *); // rax
  __int64 loaded_size; // [rsp+40h] [rbp+8h]

  v1 = loaded_file;
  v2 = 0;
  UFG::StreamResourceLoader::UnloadInternal(loaded_file);
  v3 = v1->mFilename.mData;
  v4 = v1->mAllocFlags;
  v5 = v1->mpPool;
  v6 = 0;
  dbg_tag = v1->mFilename.mData;
  loaded_size = 0i64;
  v8 = UFG::StreamFileWrapper::ReadEntireFile(v3, &loaded_size, v5, v4, dbg_tag);
  v9 = v8;
  if ( v8 )
  {
    v10 = loaded_size;
    v11 = v1->mFilename.mData;
    v1->mData = v8;
    v12 = v1->mfnChunkFilter;
    v1->mDataSize = v10;
    UFG::StreamResourceLoader::Load(v9, v10, v11, 0, v12);
    v1->meState = 1;
    v2 = 1;
  }
  else
  {
    UFG::qPrintf(
      "WARNING: StreamResourceLoader::Load() failed, file_name[%s] since is doesn't exist or has a fileSize of zero\n",
      v1->mFilename.mData);
  }
  LOBYTE(v6) = v2 != 0;
  return v6;
}

// File Line: 883
// RVA: 0x22E9E0
void __fastcall UFG::StreamResourceLoader::StreamResourceLoaderFileCallback(const char *filename, void *data, int fileSize, void *param)
{
  bool (__fastcall *fnFilter)(UFG::qChunk *); // rax
  UFG::qBaseNodeRB *v5; // rbx
  unsigned int v6; // er10
  const char *v7; // r8
  const char *v8; // rdi
  __int64 v9; // rdx
  UFG::qBaseNodeRB *v10; // rax

  fnFilter = (bool (__fastcall *)(UFG::qChunk *))*((_QWORD *)param + 15);
  v5 = (UFG::qBaseNodeRB *)param;
  v6 = fileSize;
  *((_DWORD *)param + 26) = fileSize;
  v7 = (const char *)*((_QWORD *)param + 10);
  *((_QWORD *)param + 12) = data;
  v8 = filename;
  UFG::StreamResourceLoader::Load(data, v6, v7, 0, fnFilter);
  UFG::qBaseTreeRB::Add(&UFG::StreamResourceLoader::smLoadedFiles.mTree, v5);
  v10 = v5[1].mChild[0];
  LODWORD(v5[1].mParent) = 1;
  if ( v10 )
  {
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(const char *, __int64, UFG::qBaseNodeRB *))v10)(v8, v9, v5[1].mChild[1]);
  }
}

// File Line: 917
// RVA: 0x22ADA0
char __fastcall UFG::StreamResourceLoader::LoadResourceFile(const char *filename, UFG::qMemoryPool *pool, unsigned int alloc_flags, bool (__fastcall *filter)(UFG::qChunk *), void (__fastcall *callback)(const char *, bool, void *), void *callbackParam)
{
  bool (__fastcall *v6)(UFG::qChunk *); // rbp
  unsigned int v7; // edi
  UFG::qMemoryPool *memory_pool; // rsi
  const char *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::StreamResourceLoader::LoadedFile *v11; // rax
  UFG::StreamResourceLoader::LoadedFile *v12; // rbx
  char result; // al

  v6 = filter;
  v7 = alloc_flags;
  memory_pool = pool;
  v9 = filename;
  v10 = UFG::qMalloc(0x80ui64, "StreamResourceLoader::LoadedFile", 0i64);
  if ( v10 )
  {
    UFG::StreamResourceLoader::LoadedFile::LoadedFile((UFG::StreamResourceLoader::LoadedFile *)v10, v9);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v12->mpPool = memory_pool;
  v12->mAllocFlags = v7;
  v12->mfnChunkFilter = v6;
  v12->mfnCallback = callback;
  v12->mCallbackParam = callbackParam;
  if ( callback )
  {
    UFG::StreamFileWrapper::ReadEntireFileAsync(
      v12->mFilename.mData,
      STREAM_DATA_HIGH_PRIORITY,
      UFG::StreamResourceLoader::StreamResourceLoaderFileCallback,
      v12,
      memory_pool,
      v7,
      v12->mFilename.mData);
    result = 1;
  }
  else if ( (unsigned int)UFG::StreamResourceLoader::LoadInternal(v12) )
  {
    UFG::qBaseTreeRB::Add(&UFG::StreamResourceLoader::smLoadedFiles.mTree, &v12->mNode);
    result = 1;
  }
  else
  {
    UFG::qString::~qString(&v12->mFilename);
    operator delete[](v12);
    result = 0;
  }
  return result;
}

// File Line: 958
// RVA: 0x22EC60
char __fastcall UFG::StreamResourceLoader::UnloadResourceFile(const char *filename)
{
  const char *v1; // rdi
  UFG::StreamResourceLoader::LoadedFile *v2; // rbx

  v1 = filename;
  v2 = (UFG::StreamResourceLoader::LoadedFile *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::StreamResourceLoader::smLoadedFiles);
  if ( !v2 )
    return 0;
  while ( (unsigned int)UFG::qStringCompareInsensitive(v2->mFilename.mData, v1, -1) )
  {
    v2 = (UFG::StreamResourceLoader::LoadedFile *)UFG::qBaseTreeRB::GetNext(
                                                    &UFG::StreamResourceLoader::smLoadedFiles.mTree,
                                                    &v2->mNode);
    if ( !v2 )
      return 0;
  }
  UFG::StreamResourceLoader::UnloadInternal(v2);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::StreamResourceLoader::smLoadedFiles,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2);
  UFG::qString::~qString(&v2->mFilename);
  operator delete[](v2);
  return 1;
}

