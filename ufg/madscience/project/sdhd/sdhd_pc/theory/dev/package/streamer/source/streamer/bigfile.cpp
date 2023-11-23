// File Line: 15
// RVA: 0x146F7C0
__int64 dynamic_initializer_for__UFG::BigFileSystem::m_BigFileNamePrefix__()
{
  UFG::qString::qString(&UFG::BigFileSystem::m_BigFileNamePrefix);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BigFileSystem::m_BigFileNamePrefix__);
}

// File Line: 31
// RVA: 0x146F8C0
__int64 UFG::_dynamic_initializer_for__gBIGFileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gBIGFileInventory,
    "BIGFileInventory",
    0x2AE784F9u,
    0x2C5C40A8u,
    0,
    0);
  UFG::gBIGFileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::BIGFileInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gBIGFileInventory__);
}

// File Line: 39
// RVA: 0x227360
void __fastcall UFG::BIGFileInventory::Add(UFG::BIGFileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  UFG::qString *v6; // rax
  UFG::qFile *v7; // rax
  UFG::qString result; // [rsp+30h] [rbp-98h] BYREF
  __int64 v9; // [rsp+58h] [rbp-70h]
  UFG::qString v10; // [rsp+60h] [rbp-68h] BYREF
  UFG::qString v11; // [rsp+88h] [rbp-40h] BYREF

  v9 = -2i64;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qString::qString(&v10, (const char *)&resource_data[1].mResourceHandles.mNode.mNext + 4);
  UFG::operator+(&result, v4, ".big");
  UFG::qString::~qString(&v10);
  UFG::qString::qString(&v10, &result);
  v6 = UFG::BigFileSystem::BigFilePrepend(&v11, v5);
  UFG::qString::Set(&result, v6->mData, v6->mLength, 0i64, 0);
  UFG::qString::~qString(&v11);
  WORD1(resource_data[1].mResourceHandles.mNode.mPrev) = UFG::gBigFileNextMountIndex++;
  v7 = UFG::qOpen(result.mData, QACCESS_READ, 1);
  *(_QWORD *)&resource_data[1].mNode.mUID = v7;
  if ( v7 )
  {
    LOWORD(resource_data[1].mResourceHandles.mNode.mPrev) = 1;
    resource_data[1].mNode.mParent = (UFG::qBaseNodeRB *)UFG::qGetDiskPosSortKey(v7);
  }
  else
  {
    LOWORD(resource_data[1].mResourceHandles.mNode.mPrev) = 0;
  }
  UFG::qResourceInventory::Add(this, resource_data);
  UFG::qString::~qString(&result);
}

// File Line: 66
// RVA: 0x22CC60
void __fastcall UFG::BIGFileInventory::Remove(UFG::BIGFileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qFile *v3; // rcx

  v3 = *(UFG::qFile **)&resource_data[1].mNode.mUID;
  if ( v3 )
  {
    UFG::qClose(v3);
    *(_QWORD *)&resource_data[1].mNode.mUID = 0i64;
  }
  UFG::qResourceInventory::Remove(this, resource_data);
}

// File Line: 132
// RVA: 0x146F920
__int64 UFG::_dynamic_initializer_for__gBIGFileNameLookupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gBIGFileNameLookupInventory,
    "BIGFileNameLookupInventory",
    0x21EFAF30u,
    0x164013D5u,
    0,
    0);
  UFG::gBIGFileNameLookupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::BIGFileNameLookupInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gBIGFileNameLookupInventory__);
}

// File Line: 185
// RVA: 0x228230
UFG::qString *__fastcall UFG::BigFileSystem::BigFilePrepend(UFG::qString *result, UFG::qString *fileName)
{
  UFG::qString::qString(result);
  UFG::qString::Format(result, "%s%s", UFG::BigFileSystem::m_BigFileNamePrefix.mData, fileName->mData);
  UFG::qString::~qString(fileName);
  return result;
}

// File Line: 197
// RVA: 0x229BC0
UFG::BIGFileIndex *__fastcall UFG::BigFileSystem::GetIndexFromFilename(const char *index_filename)
{
  UFG::qResourceData *v1; // rbx
  UFG::qString *v2; // rax
  unsigned int mStringHash32; // eax
  UFG::qResourceData *v4; // rax
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v7; // [rsp+50h] [rbp-38h] BYREF

  v1 = 0i64;
  UFG::qString::qString(&v7, index_filename);
  UFG::qString::GetFilenameWithoutExtension(v2, &result);
  UFG::qString::~qString(&v7);
  mStringHash32 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
    result.mStringHash32 = mStringHash32;
  }
  v4 = UFG::qResourceInventory::Get(&UFG::gBIGFileInventory, mStringHash32);
  if ( v4 )
    v1 = v4;
  UFG::qString::~qString(&result);
  return (UFG::BIGFileIndex *)v1;
}

// File Line: 209
// RVA: 0x22AAD0
char __fastcall UFG::BigFileSystem::LoadBigFileIndex(const char *index_filename, bool load_debug_names)
{
  UFG::BIGFileIndex *IndexFromFilename; // rax
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *FilenameWithoutExtension; // rax
  UFG::qString text; // [rsp+30h] [rbp-88h] BYREF
  __int64 v11; // [rsp+58h] [rbp-60h]
  UFG::qString v12; // [rsp+60h] [rbp-58h] BYREF
  UFG::qString result; // [rsp+88h] [rbp-30h] BYREF

  v11 = -2i64;
  IndexFromFilename = UFG::BigFileSystem::GetIndexFromFilename(index_filename);
  if ( IndexFromFilename )
  {
    IndexFromFilename->mState = 1;
    return 1;
  }
  else
  {
    UFG::qString::qString(&text);
    UFG::qString::Set(&text, index_filename);
    UFG::qString::qString(&v12, &text);
    v7 = UFG::BigFileSystem::BigFilePrepend(&result, v6);
    UFG::qString::Set(&text, v7->mData, v7->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    UFG::qChunkFileSystem::Load(text.mData, 0i64, 0i64, 0i64, ResourceFileContentType_Standard);
    if ( UFG::gLoadAllDebugNames || load_debug_names )
    {
      UFG::qString::qString(&v12, index_filename);
      FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(v8, &result);
      UFG::BigFileSystem::LoadDebugNames(FilenameWithoutExtension->mData);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v12);
    }
    UFG::qString::~qString(&text);
    return 1;
  }
}

// File Line: 242
// RVA: 0x228CA0
void __fastcall UFG::EmptyFileCallback(UFG::qFileOp *file_op, void *callback_param)
{
  const char *StatusName; // rdi
  const char *TypeName; // rbx
  char *Filename; // rax

  StatusName = UFG::qFileOp::GetStatusName(file_op);
  TypeName = UFG::qFileOp::GetTypeName(file_op);
  Filename = UFG::qFileOp::GetFilename(file_op);
  UFG::qPrintf("Got empty callback for qFileOp * 0x%08x %s %s - %s\n", file_op, Filename, TypeName, StatusName);
}

// File Line: 247
// RVA: 0x22CCA0
void __fastcall UFG::BigFileSystem::ReopenBigFile(const char *filename)
{
  UFG::qBaseTreeRB *i; // rbx
  UFG::qString *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  UFG::qFile *v6; // rax
  UFG::qString result; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v8; // [rsp+58h] [rbp-90h]
  UFG::qString v9; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString v10; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v11; // [rsp+B0h] [rbp-38h] BYREF

  v8 = -2i64;
  UFG::qPrintf("schedule reopen of file %s\n", filename);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142377400);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142377400, &i->mRoot) )
  {
    if ( i[1].mNULL.mChild[0] )
    {
      UFG::qString::qString(&v9, (const char *)&i[1].mNULL.mUID + 4);
      UFG::operator+(&result, v3, ".big");
      UFG::qString::~qString(&v9);
      if ( !(unsigned int)UFG::qStringCompareInsensitive(result.mData, filename, -1) )
      {
        UFG::qPrintf(
          "Closing bigfile %s qFile* at 0x%08x\n",
          (const char *)&i[1].mNULL.mUID + 4,
          i[1].mNULL.mChild[0]);
        UFG::qCloseAsync((UFG::qFile *)i[1].mNULL.mChild[0], UFG::EmptyFileCallback, 0i64, QPRIORITY_NORMAL);
        i[1].mNULL.mChild[0] = 0i64;
        UFG::qString::qString(&v10, &result);
        v5 = UFG::BigFileSystem::BigFilePrepend(&v11, v4);
        UFG::qString::Set(&result, v5->mData, v5->mLength, 0i64, 0);
        UFG::qString::~qString(&v11);
        v6 = UFG::qOpenAsync(result.mData, QACCESS_READ, 0, UFG::EmptyFileCallback, 0i64, QPRIORITY_NORMAL);
        i[1].mNULL.mChild[0] = (UFG::qBaseNodeRB *)v6;
        UFG::qPrintf("Reopenned bigfile %s qFile* at 0x%08x\n", (const char *)&i[1].mNULL.mUID + 4, v6);
      }
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 303
// RVA: 0x22AC10
void __fastcall UFG::BigFileSystem::LoadDebugNames(const char *system_name)
{
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString text; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v5; // [rsp+58h] [rbp-90h]
  UFG::qString result; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString v7; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v8; // [rsp+B0h] [rbp-38h] BYREF

  v5 = -2i64;
  UFG::qString::qString(&text);
  UFG::qString::Set(&text, system_name);
  UFG::qString::qString(&v7, &text);
  v3 = UFG::BigFileSystem::BigFilePrepend(&v8, v2);
  UFG::qString::Set(&text, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&v8);
  UFG::operator+(&result, &text, "_namelookup.bin");
  UFG::qChunkFileSystem::Load(result.mData, 0i64, 0i64, 0i64, ResourceFileContentType_Standard);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&text);
}

// File Line: 314
// RVA: 0x22EA60
bool __fastcall UFG::BigFileSystem::UnloadBigFileIndex(const char *index_filename)
{
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString *FilePathWithoutExtension; // rax
  UFG::qString text; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v7; // [rsp+58h] [rbp-90h]
  UFG::qString result; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString v9; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v10; // [rsp+B0h] [rbp-38h] BYREF

  v7 = -2i64;
  UFG::qString::qString(&text);
  UFG::qString::Set(&text, index_filename);
  UFG::qString::qString(&v10, &text);
  v3 = UFG::BigFileSystem::BigFilePrepend(&result, v2);
  UFG::qString::Set(&text, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qChunkFileSystem::Unload(text.mData);
  FilePathWithoutExtension = UFG::qString::GetFilePathWithoutExtension(&text, &result);
  UFG::operator+(&v9, FilePathWithoutExtension, "_namelookup.bin");
  UFG::qString::~qString(&result);
  UFG::qChunkFileSystem::Unload(v9.mData);
  UFG::qString::~qString(&v9);
  UFG::qString::~qString(&text);
  return 0;
}

// File Line: 327
// RVA: 0x22E2A0
bool __fastcall UFG::BigFileSystem::SetBigFileState(const char *index_filename, UFG::BIGFileIndex::State state)
{
  unsigned __int16 v2; // bx
  UFG::BIGFileIndex *IndexFromFilename; // rax

  v2 = state;
  IndexFromFilename = UFG::BigFileSystem::GetIndexFromFilename(index_filename);
  if ( IndexFromFilename )
  {
    IndexFromFilename->mState = v2;
    LOBYTE(IndexFromFilename) = 1;
  }
  return (char)IndexFromFilename;
}

// File Line: 338
// RVA: 0x229B10
const char *__fastcall UFG::BigFileSystem::GetFilenameDBG(unsigned int filename_uid)
{
  UFG::qBaseNodeRB *Head; // r11
  __int64 v3; // rdi
  int v4; // r9d
  int v5; // r8d
  UFG::qBaseNodeRB *mParent; // r10
  int v7; // eax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v11; // rax

  Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142374AF0);
  if ( !Head )
    return 0i64;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = 0;
    v5 = Head[2].mUID - 1;
    if ( v5 >= 0 )
      break;
LABEL_13:
    Head = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142374AF0, Head);
    if ( !Head )
      return 0i64;
  }
  mParent = Head[3].mParent;
  while ( 1 )
  {
    v7 = (v5 + v4) / 2;
    v8 = mParent ? (__int64)&Head[3] + (_QWORD)mParent : 0i64;
    v9 = v8 + 16i64 * v7;
    if ( filename_uid <= *(_DWORD *)v9 )
      break;
    v4 = v7 + 1;
LABEL_12:
    if ( v4 > v5 )
      goto LABEL_13;
  }
  if ( filename_uid < *(_DWORD *)v9 )
  {
    v5 = v7 - 1;
    goto LABEL_12;
  }
  v11 = *(_QWORD *)(v9 + 8);
  if ( v11 )
    return (const char *)(v9 + v11 + 8);
  return (const char *)v3;
}

// File Line: 352
// RVA: 0x229890
char __fastcall UFG::BigFileSystem::GetFileInfoFromBigFile(
        char *filename,
        UFG::BIGFileIndex **_bigFile,
        UFG::BIGFileIndex::Entry **_entry)
{
  char v6; // dl
  char *v7; // rcx
  signed __int64 v8; // rbx
  bool v9; // zf
  char v10; // al
  int v11; // ebp
  unsigned int v12; // esi
  UFG::BIGFileIndex *i; // rdi
  int v14; // r10d
  int v15; // ecx
  __int64 mOffset; // rbx
  int v17; // eax
  __int64 v18; // r8
  char *v19; // r9
  unsigned int v20; // eax
  UFG::BIGFileIndex::Entry *v21; // r11
  int v22; // r10d
  int v23; // r8d
  __int64 v24; // rbx
  int v25; // eax
  __int64 v26; // rdx
  char *v27; // r9
  char result; // al
  unsigned int v29; // eax
  char dest[256]; // [rsp+20h] [rbp-118h] BYREF

  while ( (unsigned __int8)(*filename - 46) <= 1u || *filename == 92 )
    ++filename;
  UFG::qStringCopy(dest, 0x7FFFFFFF, filename, -1);
  v6 = *filename;
  v7 = dest;
  if ( *filename )
  {
    v8 = filename - dest;
    do
    {
      v9 = v6 == 47;
      v10 = v6;
      v6 = v7[v8 + 1];
      if ( v9 )
        v10 = 92;
      *v7++ = v10;
    }
    while ( v6 );
  }
  *v7 = 0;
  v11 = 4;
  v12 = UFG::qStringHashUpper32(dest, -1);
  do
  {
    for ( i = (UFG::BIGFileIndex *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142377400);
          i;
          i = (UFG::BIGFileIndex *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142377400, &i->mNode) )
    {
      if ( i->mState == v11 )
      {
        v14 = 0;
        v15 = i->mEntryCount - 1;
        if ( v15 >= 0 )
        {
          mOffset = i->mEntries.mOffset;
          do
          {
            v17 = (v15 + v14) / 2;
            v18 = v17;
            if ( mOffset )
              v19 = (char *)&i->mEntries + mOffset;
            else
              v19 = 0i64;
            v20 = *(_DWORD *)&v19[24 * v17];
            v21 = (UFG::BIGFileIndex::Entry *)&v19[24 * v18];
            if ( v12 <= v20 )
            {
              if ( v12 >= v20 )
              {
LABEL_30:
                *_bigFile = i;
                result = 1;
                *_entry = v21;
                return result;
              }
              v15 = v18 - 1;
            }
            else
            {
              v14 = v18 + 1;
            }
          }
          while ( v14 <= v15 );
        }
      }
    }
    --v11;
  }
  while ( v11 > 1 );
  for ( i = (UFG::BIGFileIndex *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142377400);
        i;
        i = (UFG::BIGFileIndex *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142377400, &i->mNode) )
  {
    if ( i->mState == 1 )
    {
      v22 = 0;
      v23 = i->mEntryCount - 1;
      if ( v23 >= 0 )
      {
        v24 = i->mEntries.mOffset;
        do
        {
          v25 = (v23 + v22) / 2;
          v26 = v25;
          if ( v24 )
            v27 = (char *)&i->mEntries + v24;
          else
            v27 = 0i64;
          v29 = *(_DWORD *)&v27[24 * v25];
          v21 = (UFG::BIGFileIndex::Entry *)&v27[24 * v26];
          if ( v12 <= v29 )
          {
            if ( v12 >= v29 )
              goto LABEL_30;
            v23 = v26 - 1;
          }
          else
          {
            v22 = v26 + 1;
          }
        }
        while ( v22 <= v23 );
      }
    }
  }
  return 0;
}

