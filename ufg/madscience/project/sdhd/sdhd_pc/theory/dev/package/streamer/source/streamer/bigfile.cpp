// File Line: 15
// RVA: 0x146F7C0
__int64 dynamic_initializer_for__UFG::BigFileSystem::m_BigFileNamePrefix__()
{
  UFG::qString::qString(&UFG::BigFileSystem::m_BigFileNamePrefix);
  return atexit(dynamic_atexit_destructor_for__UFG::BigFileSystem::m_BigFileNamePrefix__);
}

// File Line: 31
// RVA: 0x146F8C0
__int64 UFG::_dynamic_initializer_for__gBIGFileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gBIGFileInventory.vfptr,
    "BIGFileInventory",
    0x2AE784F9u,
    0x2C5C40A8u,
    0,
    0);
  UFG::gBIGFileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::BIGFileInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gBIGFileInventory__);
}

// File Line: 39
// RVA: 0x227360
void __fastcall UFG::BIGFileInventory::Add(UFG::BIGFileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::BIGFileInventory *v3; // rdi
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  UFG::qString *v6; // rax
  UFG::qFile *v7; // rax
  UFG::qString result; // [rsp+30h] [rbp-98h]
  __int64 v9; // [rsp+58h] [rbp-70h]
  UFG::qString v10; // [rsp+60h] [rbp-68h]
  UFG::qString v11; // [rsp+88h] [rbp-40h]

  v9 = -2i64;
  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qString::qString(&v10, (const char *)&v2[1].mResourceHandles.mNode.mNext + 4);
  UFG::operator+(&result, v4, ".big");
  UFG::qString::~qString(&v10);
  UFG::qString::qString(&v10, &result);
  v6 = UFG::BigFileSystem::BigFilePrepend(&v11, v5);
  UFG::qString::Set(&result, v6->mData, v6->mLength, 0i64, 0);
  UFG::qString::~qString(&v11);
  WORD1(v2[1].mResourceHandles.mNode.mPrev) = UFG::gBigFileNextMountIndex++;
  v7 = UFG::qOpen(result.mData, QACCESS_READ, 1);
  *(_QWORD *)&v2[1].mNode.mUID = v7;
  if ( v7 )
  {
    LOWORD(v2[1].mResourceHandles.mNode.mPrev) = 1;
    v2[1].mNode.mParent = (UFG::qBaseNodeRB *)UFG::qGetDiskPosSortKey(v7);
  }
  else
  {
    LOWORD(v2[1].mResourceHandles.mNode.mPrev) = 0;
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  UFG::qString::~qString(&result);
}

// File Line: 66
// RVA: 0x22CC60
void __fastcall UFG::BIGFileInventory::Remove(UFG::BIGFileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::BIGFileInventory *v2; // rdi
  UFG::qFile *v3; // rcx
  UFG::qResourceData *v4; // rbx

  v2 = this;
  v3 = *(UFG::qFile **)&resource_data[1].mNode.mUID;
  v4 = resource_data;
  if ( v3 )
  {
    UFG::qClose(v3);
    *(_QWORD *)&v4[1].mNode.mUID = 0i64;
  }
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v2->vfptr, v4);
}

// File Line: 132
// RVA: 0x146F920
__int64 UFG::_dynamic_initializer_for__gBIGFileNameLookupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gBIGFileNameLookupInventory.vfptr,
    "BIGFileNameLookupInventory",
    0x21EFAF30u,
    0x164013D5u,
    0,
    0);
  UFG::gBIGFileNameLookupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::BIGFileNameLookupInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gBIGFileNameLookupInventory__);
}

// File Line: 185
// RVA: 0x228230
UFG::qString *__fastcall UFG::BigFileSystem::BigFilePrepend(UFG::qString *result, UFG::qString *fileName)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // rdi
  __int64 v5; // [rsp+20h] [rbp-18h]

  v2 = fileName;
  v3 = result;
  UFG::qString::qString(result);
  LODWORD(v5) = 1;
  UFG::qString::Format(v3, "%s%s", UFG::BigFileSystem::m_BigFileNamePrefix.mData, v2->mData, v5, -2i64);
  UFG::qString::~qString(v2);
  return v3;
}

// File Line: 197
// RVA: 0x229BC0
UFG::qResourceData *__fastcall UFG::BigFileSystem::GetIndexFromFilename(const char *index_filename)
{
  UFG::qResourceData *v1; // rbx
  UFG::qString *v2; // rax
  int v3; // edx
  unsigned int v4; // eax
  UFG::qResourceData *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v8; // [rsp+50h] [rbp-38h]

  v1 = 0i64;
  UFG::qString::qString(&v8, index_filename);
  UFG::qString::GetFilenameWithoutExtension(v2, &result);
  UFG::qString::~qString(&v8);
  v4 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    v4 = UFG::qStringHash32(result.mData, result.mStringHash32 | v3);
    result.mStringHash32 = v4;
  }
  v5 = UFG::qResourceInventory::Get((UFG::qResourceInventory *)&UFG::gBIGFileInventory.vfptr, v4);
  if ( v5 )
    v1 = v5;
  UFG::qString::~qString(&result);
  return v1;
}

// File Line: 209
// RVA: 0x22AAD0
char __fastcall UFG::BigFileSystem::LoadBigFileIndex(const char *index_filename, bool load_debug_names)
{
  bool v2; // di
  const char *v3; // rbx
  UFG::qResourceData *v4; // rax
  char v5; // al
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString text; // [rsp+30h] [rbp-88h]
  __int64 v11; // [rsp+58h] [rbp-60h]
  UFG::qString v12; // [rsp+60h] [rbp-58h]
  UFG::qString result; // [rsp+88h] [rbp-30h]

  v11 = -2i64;
  v2 = load_debug_names;
  v3 = index_filename;
  v4 = UFG::BigFileSystem::GetIndexFromFilename(index_filename);
  if ( v4 )
  {
    LOWORD(v4[1].mResourceHandles.mNode.mPrev) = 1;
    v5 = 1;
  }
  else
  {
    UFG::qString::qString(&text);
    UFG::qString::Set(&text, v3);
    UFG::qString::qString(&v12, &text);
    v7 = UFG::BigFileSystem::BigFilePrepend(&result, v6);
    UFG::qString::Set(&text, v7->mData, v7->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    UFG::qChunkFileSystem::Load(text.mData, 0i64, 0i64, 0i64, 0);
    if ( UFG::gLoadAllDebugNames || v2 )
    {
      UFG::qString::qString(&v12, v3);
      v9 = UFG::qString::GetFilenameWithoutExtension(v8, &result);
      UFG::BigFileSystem::LoadDebugNames(v9->mData);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v12);
    }
    UFG::qString::~qString(&text);
    v5 = 1;
  }
  return v5;
}

// File Line: 242
// RVA: 0x228CA0
void __fastcall UFG::EmptyFileCallback(UFG::qFileOp *file_op, void *callback_param)
{
  UFG::qFileOp *v2; // rsi
  const char *v3; // rdi
  const char *v4; // rbx
  char *v5; // rax

  v2 = file_op;
  v3 = UFG::qFileOp::GetStatusName(file_op);
  v4 = UFG::qFileOp::GetTypeName(v2);
  v5 = UFG::qFileOp::GetFilename(v2);
  UFG::qPrintf("Got empty callback for qFileOp * 0x%08x %s %s - %s\n", v2, v5, v4, v3);
}

// File Line: 247
// RVA: 0x22CCA0
void __fastcall UFG::BigFileSystem::ReopenBigFile(const char *filename)
{
  const char *v1; // rsi
  UFG::qBaseTreeRB *i; // rbx
  UFG::qString *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  UFG::qFile *v6; // rax
  UFG::qString result; // [rsp+30h] [rbp-B8h]
  __int64 v8; // [rsp+58h] [rbp-90h]
  UFG::qString v9; // [rsp+60h] [rbp-88h]
  UFG::qString v10; // [rsp+88h] [rbp-60h]
  UFG::qString v11; // [rsp+B0h] [rbp-38h]

  v8 = -2i64;
  v1 = filename;
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
      if ( !(unsigned int)UFG::qStringCompareInsensitive(result.mData, v1, -1) )
      {
        UFG::qPrintf("Closing bigfile %s qFile* at 0x%08x\n", &i[1].mNULL.mUID + 1, i[1].mNULL.mChild[0]);
        UFG::qCloseAsync((UFG::qFile *)i[1].mNULL.mChild[0], UFG::EmptyFileCallback, 0i64, QPRIORITY_NORMAL);
        i[1].mNULL.mChild[0] = 0i64;
        UFG::qString::qString(&v10, &result);
        v5 = UFG::BigFileSystem::BigFilePrepend(&v11, v4);
        UFG::qString::Set(&result, v5->mData, v5->mLength, 0i64, 0);
        UFG::qString::~qString(&v11);
        v6 = UFG::qOpenAsync(result.mData, QACCESS_READ, 0, UFG::EmptyFileCallback, 0i64, QPRIORITY_NORMAL);
        i[1].mNULL.mChild[0] = (UFG::qBaseNodeRB *)v6;
        UFG::qPrintf("Reopenned bigfile %s qFile* at 0x%08x\n", &i[1].mNULL.mUID + 1, v6);
      }
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 303
// RVA: 0x22AC10
void __fastcall UFG::BigFileSystem::LoadDebugNames(const char *system_name)
{
  const char *v1; // rbx
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString text; // [rsp+30h] [rbp-B8h]
  __int64 v5; // [rsp+58h] [rbp-90h]
  UFG::qString result; // [rsp+60h] [rbp-88h]
  UFG::qString v7; // [rsp+88h] [rbp-60h]
  UFG::qString v8; // [rsp+B0h] [rbp-38h]

  v5 = -2i64;
  v1 = system_name;
  UFG::qString::qString(&text);
  UFG::qString::Set(&text, v1);
  UFG::qString::qString(&v7, &text);
  v3 = UFG::BigFileSystem::BigFilePrepend(&v8, v2);
  UFG::qString::Set(&text, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&v8);
  UFG::operator+(&result, &text, "_namelookup.bin");
  UFG::qChunkFileSystem::Load(result.mData, 0i64, 0i64, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&text);
}

// File Line: 314
// RVA: 0x22EA60
bool __fastcall UFG::BigFileSystem::UnloadBigFileIndex(const char *index_filename)
{
  const char *v1; // rbx
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString text; // [rsp+30h] [rbp-B8h]
  __int64 v7; // [rsp+58h] [rbp-90h]
  UFG::qString result; // [rsp+60h] [rbp-88h]
  UFG::qString v9; // [rsp+88h] [rbp-60h]
  UFG::qString v10; // [rsp+B0h] [rbp-38h]

  v7 = -2i64;
  v1 = index_filename;
  UFG::qString::qString(&text);
  UFG::qString::Set(&text, v1);
  UFG::qString::qString(&v10, &text);
  v3 = UFG::BigFileSystem::BigFilePrepend(&result, v2);
  UFG::qString::Set(&text, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::qChunkFileSystem::Unload(text.mData);
  v4 = UFG::qString::GetFilePathWithoutExtension(&text, &result);
  UFG::operator+(&v9, v4, "_namelookup.bin");
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
  __int16 v2; // bx
  UFG::qResourceData *v3; // rax

  v2 = state;
  v3 = UFG::BigFileSystem::GetIndexFromFilename(index_filename);
  if ( v3 )
  {
    LOWORD(v3[1].mResourceHandles.mNode.mPrev) = v2;
    LOBYTE(v3) = 1;
  }
  return (char)v3;
}

// File Line: 338
// RVA: 0x229B10
const char *__fastcall UFG::BigFileSystem::GetFilenameDBG(unsigned int filename_uid)
{
  unsigned int v1; // ebx
  UFG::qBaseNodeRB *v2; // r11
  signed __int64 v3; // rdi
  int v4; // er9
  int v5; // er8
  UFG::qBaseNodeRB *v6; // r10
  int v7; // eax
  signed __int64 v8; // rdx
  signed __int64 v9; // rcx
  __int64 v11; // rax

  v1 = filename_uid;
  v2 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142374AF0);
  if ( !v2 )
    return 0i64;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = 0;
    v5 = v2[2].mUID - 1;
    if ( v5 >= 0 )
      break;
LABEL_13:
    v2 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142374AF0, v2);
    if ( !v2 )
      return 0i64;
  }
  v6 = v2[3].mParent;
  while ( 1 )
  {
    v7 = (v5 + v4) / 2;
    v8 = (signed __int64)(v6 ? (UFG::qBaseNodeRB *)((char *)&v2[3] + (_QWORD)v6) : 0i64);
    v9 = v8 + 16i64 * v7;
    if ( v1 <= *(_DWORD *)v9 )
      break;
    v4 = v7 + 1;
LABEL_12:
    if ( v4 > v5 )
      goto LABEL_13;
  }
  if ( v1 < *(_DWORD *)v9 )
  {
    v5 = v7 - 1;
    goto LABEL_12;
  }
  v11 = *(_QWORD *)(v9 + 8);
  if ( v11 )
    v3 = v9 + v11 + 8;
  return (const char *)v3;
}

// File Line: 352
// RVA: 0x229890
char __fastcall UFG::BigFileSystem::GetFileInfoFromBigFile(const char *filename, UFG::BIGFileIndex **_bigFile, UFG::BIGFileIndex::Entry **_entry)
{
  UFG::BIGFileIndex::Entry **v3; // r14
  UFG::BIGFileIndex **v4; // r15
  const char *i; // rbx
  char v6; // dl
  char *v7; // rcx
  signed __int64 v8; // rbx
  bool v9; // zf
  char v10; // al
  signed int v11; // ebp
  unsigned int v12; // esi
  UFG::qBaseTreeRB *j; // rdi
  int v14; // er10
  int v15; // ecx
  UFG::qBaseNodeRB *v16; // rbx
  int v17; // eax
  __int64 v18; // r8
  signed __int64 v19; // r9
  unsigned int v20; // eax
  signed __int64 v21; // r11
  int v22; // er10
  int v23; // er8
  UFG::qBaseNodeRB *v24; // rbx
  int v25; // eax
  __int64 v26; // rdx
  signed __int64 v27; // r9
  char result; // al
  unsigned int v29; // eax
  char dest; // [rsp+20h] [rbp-118h]

  v3 = _entry;
  v4 = _bigFile;
  for ( i = filename; (unsigned __int8)(*i - 46) <= 1u || *i == 92; ++i )
    ;
  UFG::qStringCopy(&dest, 0x7FFFFFFF, i, -1);
  v6 = *i;
  v7 = &dest;
  if ( *i )
  {
    v8 = i - &dest;
    do
    {
      v9 = v6 == 47;
      v10 = v6;
      v6 = v7[v8 + 1];
      if ( v9 )
        v10 = 92;
      *(++v7 - 1) = v10;
    }
    while ( v6 );
  }
  *v7 = 0;
  v11 = 4;
  v12 = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
  do
  {
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142377400);
          j;
          j = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142377400, &j->mRoot) )
    {
      if ( LOWORD(j[1].mNULL.mChild[1]) == v11 )
      {
        v14 = 0;
        v15 = j[1].mRoot.mUID - 1;
        if ( v15 >= 0 )
        {
          v16 = j[1].mNULL.mParent;
          do
          {
            v17 = (v15 + v14) / 2;
            v18 = v17;
            if ( v16 )
              v19 = (signed __int64)&j[1].mNULL + (_QWORD)v16;
            else
              v19 = 0i64;
            v20 = *(_DWORD *)(v19 + 24i64 * v17);
            v21 = v19 + 24 * v18;
            if ( v12 <= v20 )
            {
              if ( v12 >= v20 )
              {
LABEL_31:
                *v4 = (UFG::BIGFileIndex *)j;
                result = 1;
                *v3 = (UFG::BIGFileIndex::Entry *)v21;
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
  for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142377400);
        j;
        j = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142377400, &j->mRoot) )
  {
    if ( LOWORD(j[1].mNULL.mChild[1]) == 1 )
    {
      v22 = 0;
      v23 = j[1].mRoot.mUID - 1;
      if ( v23 >= 0 )
      {
        v24 = j[1].mNULL.mParent;
        do
        {
          v25 = (v23 + v22) / 2;
          v26 = v25;
          if ( v24 )
            v27 = (signed __int64)&j[1].mNULL + (_QWORD)v24;
          else
            v27 = 0i64;
          v29 = *(_DWORD *)(v27 + 24i64 * v25);
          v21 = v27 + 24 * v26;
          if ( v12 <= v29 )
          {
            if ( v12 >= v29 )
              goto LABEL_31;
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

