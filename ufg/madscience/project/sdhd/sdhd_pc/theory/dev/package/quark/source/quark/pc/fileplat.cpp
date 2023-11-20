// File Line: 64
// RVA: 0xA3A330
char __fastcall UFG::qRemoveEmptyDirectoriesRecurse(const char *directory_base)
{
  HANDLE v1; // rbx
  bool v2; // al
  UFG::qString *v3; // rax
  UFG::qString v5; // [rsp+28h] [rbp-1F0h]
  UFG::qString lhs; // [rsp+50h] [rbp-1C8h]
  UFG::qString result; // [rsp+78h] [rbp-1A0h]
  UFG::qString v8; // [rsp+A0h] [rbp-178h]
  _WIN32_FIND_DATAA FindFileData; // [rsp+D0h] [rbp-148h]

  UFG::qString::qString(&lhs, directory_base);
  UFG::operator+(&result, &lhs, "\\*");
  v1 = FindFirstFileA(result.mData, &FindFileData);
  if ( v1 != (HANDLE)-1i64 )
  {
    do
    {
      v2 = FindFileData.cFileName[0] != 46
        || FindFileData.cFileName[1]
        && (FindFileData.cFileName[1] != FindFileData.cFileName[0] || FindFileData.cFileName[2]);
      if ( (FindFileData.dwFileAttributes >> 4) & 1 && v2 )
      {
        v3 = UFG::operator+(&v8, &lhs, "\\");
        UFG::operator+(&v5, v3, FindFileData.cFileName);
        UFG::qString::~qString(&v8);
        if ( !RemoveDirectoryA(v5.mData) && GetLastError() == 145 )
        {
          UFG::qRemoveEmptyDirectoriesRecurse(v5.mData);
          RemoveDirectoryA(v5.mData);
        }
        UFG::qString::~qString(&v5);
      }
    }
    while ( FindNextFileA(v1, &FindFileData) );
    FindClose(v1);
  }
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&lhs);
  return 1;
}

// File Line: 187
// RVA: 0xA38CC0
void __fastcall UFG::PCFileDevice::Mount(UFG::PCFileDevice *this)
{
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v1; // rax
  UFG::qFileOpList *v2; // r8

  v1 = this->mFileOpLists.mNode.mPrev;
  v2 = &this->mFileOpList;
  v1->mNext = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)&this->mFileOpList.mPrev;
  v2->mNext = &this->mFileOpLists.mNode;
  v2->mPrev = v1;
  this->mFileOpLists.mNode.mPrev = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)&this->mFileOpList.mPrev;
  UFG::qFileIoThread::Start(&this->mIoThread, (UFG::qFileDevice *)&this->vfptr, &this->mFileOpList, 0, -1, -1);
}

// File Line: 194
// RVA: 0xA397D0
void __fastcall UFG::PCFileDevice::Unmount(UFG::PCFileDevice *this)
{
  UFG::PCFileDevice *v1; // rbx
  UFG::qFileDeviceVtbl *v2; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v3; // rax

  v1 = this;
  UFG::qFileIoThread::Stop(&this->mIoThread);
  v1 = (UFG::PCFileDevice *)((char *)v1 + 264);
  v2 = v1->vfptr;
  v3 = v1->mPrev;
  *(_QWORD *)v2->gap8 = v3;
  v3->mPrev = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)v2;
  v1->vfptr = (UFG::qFileDeviceVtbl *)v1;
  v1->mPrev = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)v1;
}

// File Line: 201
// RVA: 0xA39260
void __fastcall UFG::PCFileDevice::QueueFileOp(UFG::PCFileDevice *this, UFG::qFileOp *file_op, int priority)
{
  UFG::qFileOpList::Queue(&this->mFileOpList, file_op, priority);
}

// File Line: 212
// RVA: 0xA389E0
_ULARGE_INTEGER __fastcall UFG::PCFileDevice::GetFreeDiskSpace(UFG::PCFileDevice *this, const char *base_directory)
{
  _ULARGE_INTEGER v2; // rbx
  const char *v3; // rcx
  _ULARGE_INTEGER FreeBytesAvailableToCaller; // [rsp+38h] [rbp+10h]
  _ULARGE_INTEGER TotalNumberOfFreeBytes; // [rsp+40h] [rbp+18h]
  _ULARGE_INTEGER TotalNumberOfBytes; // [rsp+48h] [rbp+20h]

  v2.QuadPart = 0i64;
  v3 = "C:\\";
  if ( base_directory )
    v3 = base_directory;
  FreeBytesAvailableToCaller.QuadPart = 0i64;
  TotalNumberOfBytes.QuadPart = 0i64;
  TotalNumberOfFreeBytes.QuadPart = 0i64;
  if ( GetDiskFreeSpaceExA(v3, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes) )
    v2 = FreeBytesAvailableToCaller;
  return v2;
}

// File Line: 228
// RVA: 0xA383E0
__int64 __fastcall UFG::PCFileDevice::FindFilesAndDirs(UFG::PCFileDevice *this, UFG::qList<UFG::qString,UFG::qString,1,0> *files, const char *initial_directory, bool recursive, UFG::qList<UFG::qString,UFG::qString,1,0> *file_patterns, UFG::qList<UFG::qString,UFG::qString,1,0> *dir_patterns)
{
  bool v6; // di
  const char *v7; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v8; // r15
  UFG::qString *v9; // rax
  __int64 *v10; // rax
  __int64 *v11; // rcx
  __int64 *v12; // rax
  unsigned int v13; // er13
  UFG::qString *v14; // r12
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  HANDLE v17; // rax
  void *v18; // rbx
  UFG::qString *v19; // rax
  UFG::qString *v20; // rax
  UFG::qString *v21; // rbx
  __int64 *v22; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v23; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rsi
  int v25; // er14
  char *v26; // rbx
  char v27; // cl
  UFG::qString *v28; // rax
  UFG::qString *v29; // rax
  UFG::qString *v30; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v32; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rsi
  int v34; // er14
  char *v35; // rbx
  char v36; // cl
  UFG::qString *v37; // rax
  UFG::qString *v38; // rax
  UFG::qString *v39; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v40; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rax
  __int64 *v44; // rdx
  UFG::qString *v45; // rcx
  __int64 *v47; // [rsp+20h] [rbp-E0h]
  UFG::qString *v48; // [rsp+28h] [rbp-D8h]
  UFG::qString *v49; // [rsp+30h] [rbp-D0h]
  __int64 v50; // [rsp+38h] [rbp-C8h]
  UFG::qString v51; // [rsp+40h] [rbp-C0h]
  _WIN32_FIND_DATAA FindFileData; // [rsp+70h] [rbp-90h]
  HANDLE v53; // [rsp+1F8h] [rbp+F8h]
  bool v54; // [rsp+208h] [rbp+108h]

  v54 = recursive;
  v50 = -2i64;
  v6 = recursive;
  v7 = initial_directory;
  v8 = files;
  if ( !files || !initial_directory || !*initial_directory )
    return 0i64;
  v47 = (__int64 *)&v47;
  v48 = (UFG::qString *)&v47;
  v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v9 )
  {
    UFG::qString::qString(v9, v7);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v47;
  v47[1] = (__int64)v11;
  *v11 = (__int64)v12;
  v11[1] = (__int64)&v47;
  v47 = v11;
  v13 = 0;
  v14 = v48;
  if ( v48 == (UFG::qString *)&v47 )
    goto LABEL_53;
  do
  {
    v15 = v14->mPrev;
    v16 = v14->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v14->mPrev;
    v14->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v14->mPrev;
    UFG::qString::qString(&v51);
    UFG::qString::Format(&v51, "%s\\*", v14->mData);
    v17 = FindFirstFileA(v51.mData, &FindFileData);
    v18 = v17;
    v53 = v17;
    if ( v17 == (HANDLE)-1i64 )
    {
      UFG::qString::~qString(v14);
      operator delete[](v14);
      UFG::qString::~qString(&v51);
      break;
    }
    if ( !v17 )
      goto LABEL_50;
    do
    {
      if ( !(FindFileData.dwFileAttributes & 0x10) )
      {
        v32 = file_patterns;
        if ( !file_patterns )
          goto LABEL_48;
        v33 = file_patterns->mNode.mNext;
        do
        {
          if ( v33 == (UFG::qNode<UFG::qString,UFG::qString> *)v32 )
            break;
          v34 = UFG::qWildcardMatchInsensitive((const char *)v33[1].mNext, FindFileData.cFileName);
          if ( v34 )
          {
            v35 = v14->mData;
            if ( *v35 == 46 )
            {
              v36 = v35[1];
              if ( v36 == 92 || v36 == 47 )
                v35 += 2;
            }
            v37 = (UFG::qString *)UFG::qMalloc(0x28ui64, "files", 0i64);
            v49 = v37;
            if ( v37 )
            {
              UFG::qString::qString(v37);
              v39 = v38;
            }
            else
            {
              v39 = 0i64;
            }
            UFG::qString::Format(v39, "%s\\%s", v35, FindFileData.cFileName, v47);
            v40 = v8->mNode.mPrev;
            v40->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v39->mPrev;
            v39->mPrev = v40;
            v39->mNext = &v8->mNode;
            v8->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v39->mPrev;
            ++v13;
          }
          v33 = v33->mNext;
          v32 = file_patterns;
        }
        while ( !v34 );
        goto LABEL_47;
      }
      if ( FindFileData.cFileName[0] != 46
        || FindFileData.cFileName[1]
        && (FindFileData.cFileName[1] != FindFileData.cFileName[0] || FindFileData.cFileName[2]) )
      {
        if ( v6 )
        {
          v19 = (UFG::qString *)UFG::qMalloc(0x28ui64, "directories", 0i64);
          v49 = v19;
          if ( v19 )
          {
            UFG::qString::qString(v19);
            v21 = v20;
          }
          else
          {
            v21 = 0i64;
          }
          UFG::qString::Format(v21, "%s\\%s", v14->mData, FindFileData.cFileName, v47);
          v22 = v47;
          v47[1] = (__int64)v21;
          v21->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v22;
          v21->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v47;
          v47 = (__int64 *)v21;
          v18 = v53;
        }
        v23 = dir_patterns;
        if ( dir_patterns )
        {
          v24 = dir_patterns->mNode.mNext;
          do
          {
            if ( v24 == (UFG::qNode<UFG::qString,UFG::qString> *)v23 )
              break;
            v25 = UFG::qWildcardMatchInsensitive((const char *)v24[1].mNext, FindFileData.cFileName);
            if ( v25 )
            {
              v26 = v14->mData;
              if ( *v26 == 46 )
              {
                v27 = v26[1];
                if ( v27 == 92 || v27 == 47 )
                  v26 += 2;
              }
              v28 = (UFG::qString *)UFG::qMalloc(0x28ui64, "files", 0i64);
              v49 = v28;
              if ( v28 )
              {
                UFG::qString::qString(v28);
                v30 = v29;
              }
              else
              {
                v30 = 0i64;
              }
              UFG::qString::Format(v30, "%s\\%s", v26, FindFileData.cFileName, v47);
              v31 = v8->mNode.mPrev;
              v31->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v30->mPrev;
              v30->mPrev = v31;
              v30->mNext = &v8->mNode;
              v8->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v30->mPrev;
              ++v13;
            }
            v24 = v24->mNext;
            v23 = dir_patterns;
          }
          while ( !v25 );
LABEL_47:
          v18 = v53;
          goto LABEL_48;
        }
      }
LABEL_48:
      v6 = v54;
    }
    while ( FindNextFileA(v18, &FindFileData) );
    FindClose(v18);
LABEL_50:
    UFG::qString::~qString(v14);
    operator delete[](v14);
    UFG::qString::~qString(&v51);
    v14 = v48;
  }
  while ( v48 != (UFG::qString *)&v47 );
LABEL_53:
  for ( i = v48; v48 != (UFG::qString *)&v47; i = v48 )
  {
    v42 = i->mPrev;
    v43 = i->mNext;
    v42->mNext = v43;
    v43->mPrev = v42;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v44 = v47;
  v45 = v48;
  v47[1] = (__int64)v48;
  v45->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v44;
  v47 = (__int64 *)&v47;
  v48 = (UFG::qString *)&v47;
  return v13;
}

// File Line: 347
// RVA: 0xA37E60
char __fastcall UFG::PCFileDevice::DirectoryExists(UFG::PCFileDevice *this, const char *directory)
{
  HANDLE v2; // rax
  _WIN32_FIND_DATAA FindFileData; // [rsp+20h] [rbp-148h]

  if ( !directory || !*directory )
    return 1;
  v2 = FindFirstFileA(directory, &FindFileData);
  if ( v2 == (HANDLE)-1i64 )
    return 0;
  FindClose(v2);
  return (LOBYTE(FindFileData.dwFileAttributes) >> 4) & 1;
}

// File Line: 364
// RVA: 0xA37B10
char __fastcall UFG::PCFileDevice::CreateDirectoryA(UFG::PCFileDevice *this, const char *directory)
{
  UFG::qString *v2; // rax
  __int64 *v3; // rax
  __int64 *v4; // rcx
  __int64 *v5; // rax
  UFG::qString *v6; // rax
  UFG::qString *i; // rbx
  __int64 v8; // rbx
  char v9; // di
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  __int64 *v13; // rdx
  UFG::qString *v14; // rcx
  __int64 *v16; // [rsp+30h] [rbp-11h]
  UFG::qString *v17; // [rsp+38h] [rbp-9h]
  UFG::qString v18; // [rsp+40h] [rbp-1h]
  UFG::qString result; // [rsp+68h] [rbp+27h]

  if ( !directory || !*directory )
    return 1;
  v16 = (__int64 *)&v16;
  v17 = (UFG::qString *)&v16;
  UFG::qString::qString(&v18, directory);
  while ( v18.mLength )
  {
    v2 = (UFG::qString *)UFG::qMalloc(0x28ui64, "CreateDirectory::IntDirName", 0i64);
    if ( v2 )
    {
      UFG::qString::qString(v2, v18.mData);
      v4 = v3;
    }
    else
    {
      v4 = 0i64;
    }
    v5 = v16;
    v16[1] = (__int64)v4;
    *v4 = (__int64)v5;
    v4[1] = (__int64)&v16;
    v16 = v4;
    v6 = UFG::qString::GetFilePath(&v18, &result);
    UFG::qString::Set(&v18, v6->mData, v6->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
  }
  for ( i = v17; i != (UFG::qString *)&v16; i = (UFG::qString *)i->mNext )
  {
    if ( CreateDirectoryA(i->mData, 0i64) || GetLastError() == 183 )
    {
      if ( i != (UFG::qString *)&v16 )
      {
        v8 = (__int64)i->mPrev;
        if ( (__int64 **)v8 == &v16 )
        {
LABEL_18:
          v9 = 1;
          goto LABEL_20;
        }
        while ( CreateDirectoryA(*(LPCSTR *)(v8 + 24), 0i64) || GetLastError() == 183 )
        {
          v8 = *(_QWORD *)v8;
          if ( (__int64 **)v8 == &v16 )
            goto LABEL_18;
        }
      }
      break;
    }
  }
  v9 = 0;
LABEL_20:
  UFG::qString::~qString(&v18);
  for ( j = v17; v17 != (UFG::qString *)&v16; j = v17 )
  {
    v11 = j->mPrev;
    v12 = j->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v13 = v16;
  v14 = v17;
  v16[1] = (__int64)v17;
  v14->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v13;
  v16 = (__int64 *)&v16;
  v17 = (UFG::qString *)&v16;
  return v9;
}

// File Line: 416
// RVA: 0xA37CF0
bool __fastcall UFG::PCFileDevice::DeleteDirectory(UFG::PCFileDevice *this, const char *directory)
{
  const char *v2; // rdi
  UFG::qString *i; // rbx
  bool v4; // di
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  __int64 *v8; // rdx
  UFG::qString *v9; // rcx
  __int64 *v11; // [rsp+28h] [rbp-20h]
  UFG::qString *v12; // [rsp+30h] [rbp-18h]

  v2 = directory;
  if ( !directory || !*directory )
    return 0;
  v11 = (__int64 *)&v11;
  v12 = (UFG::qString *)&v11;
  if ( (unsigned int)UFG::qGetFiles((UFG::qList<UFG::qString,UFG::qString,1,0> *)&v11, directory, 1, pattern) )
  {
    for ( i = v12; i != (UFG::qString *)&v11; i = (UFG::qString *)i->mNext )
      UFG::qDeleteFile(i->mData);
  }
  UFG::qRemoveEmptyDirectoriesRecurse(v2);
  v4 = RemoveDirectoryA(v2) || GetLastError() == 2;
  for ( j = v12; v12 != (UFG::qString *)&v11; j = v12 )
  {
    v6 = j->mPrev;
    v7 = j->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v8 = v11;
  v9 = v12;
  v11[1] = (__int64)v12;
  v9->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v8;
  v11 = (__int64 *)&v11;
  v12 = (UFG::qString *)&v11;
  return v4;
}

// File Line: 451
// RVA: 0xA383A0
bool __fastcall UFG::PCFileDevice::FilenameExists(UFG::PCFileDevice *this, const char *filename)
{
  bool result; // al
  char FileInformation; // [rsp+20h] [rbp-38h]

  if ( filename && *filename )
    result = GetFileAttributesExA(filename, 0, &FileInformation) != 0;
  else
    result = 0;
  return result;
}

// File Line: 467
// RVA: 0xA38920
unsigned __int64 __fastcall UFG::PCFileDevice::GetFilenameSize(UFG::PCFileDevice *this, const char *filename)
{
  unsigned __int64 v2; // rbx
  char FileInformation; // [rsp+20h] [rbp-38h]
  unsigned int v5; // [rsp+3Ch] [rbp-1Ch]
  unsigned int v6; // [rsp+40h] [rbp-18h]

  if ( !filename || !*filename )
    return 0i64;
  v2 = 0i64;
  if ( GetFileAttributesExA(filename, 0, &FileInformation) )
    v2 = v6 | ((unsigned __int64)v5 << 32);
  return v2;
}

// File Line: 485
// RVA: 0xA38970
_FILETIME __fastcall UFG::PCFileDevice::GetFilenameTime(UFG::PCFileDevice *this, const char *filename)
{
  char FileInformation; // [rsp+20h] [rbp-38h]
  FILETIME FileTime; // [rsp+34h] [rbp-24h]
  _FILETIME LocalFileTime; // [rsp+68h] [rbp+10h]

  if ( !filename || !*filename )
    return 0i64;
  if ( GetFileAttributesExA(filename, 0, &FileInformation) && FileTimeToLocalFileTime(&FileTime, &LocalFileTime) )
    return LocalFileTime;
  return 0i64;
}

// File Line: 518
// RVA: 0xA39340
char __fastcall UFG::PCFileDevice::SetFilenameTime(UFG::PCFileDevice *this, const char *filename, unsigned __int64 modification_time)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rbx
  HANDLE v5; // rdi
  char v6; // bl
  FILETIME LocalFileTime; // [rsp+68h] [rbp+10h]
  _FILETIME FileTime; // [rsp+78h] [rbp+20h]

  v3 = modification_time;
  v4 = filename;
  if ( !filename || !*filename )
    return 0;
  v5 = CreateFileA(filename, 0x180u, 0, 0i64, 3u, 0, 0i64);
  if ( GetLastError() == 2 )
    v5 = CreateFileA(v4, 0x180u, 0, 0i64, 1u, 0, 0i64);
  LocalFileTime = (FILETIME)v3;
  LocalFileTimeToFileTime(&LocalFileTime, &FileTime);
  v6 = 1;
  if ( !SetFileTime(v5, 0i64, 0i64, &FileTime) )
    v6 = 0;
  CloseHandle(v5);
  return v6;
}

// File Line: 552
// RVA: 0xA388D0
bool __fastcall UFG::PCFileDevice::GetFilenameReadOnly(UFG::PCFileDevice *this, const char *filename)
{
  char v2; // bl
  char FileInformation; // [rsp+20h] [rbp-38h]

  if ( !filename || !*filename )
    return 0;
  v2 = 0;
  if ( GetFileAttributesExA(filename, 0, &FileInformation) )
    v2 = FileInformation & 1;
  return v2;
}

// File Line: 570
// RVA: 0xA392C0
char __fastcall UFG::PCFileDevice::SetFilenameReadOnly(UFG::PCFileDevice *this, const char *filename, bool make_read_only)
{
  bool v3; // di
  const char *v4; // rbx
  int FileInformation; // [rsp+20h] [rbp-38h]

  v3 = make_read_only;
  v4 = filename;
  if ( !filename || !*filename || !GetFileAttributesExA(filename, 0, &FileInformation) )
    return 0;
  if ( v3 )
    SetFileAttributesA(v4, FileInformation | 1);
  else
    SetFileAttributesA(v4, FileInformation & 0xFFFFFFFE);
  return 1;
}

// File Line: 593
// RVA: 0xA37E10
bool __fastcall UFG::PCFileDevice::DeleteFilename(UFG::PCFileDevice *this, const char *filename)
{
  BOOL v2; // eax
  bool v3; // bl

  if ( !filename || !*filename )
    return 0;
  v2 = DeleteFileA(filename);
  v3 = v2 != 0;
  if ( !v2 && GetLastError() == 2 )
    v3 = 1;
  return v3;
}

// File Line: 612
// RVA: 0xA39270
bool __fastcall UFG::PCFileDevice::RenameFilename(UFG::PCFileDevice *this, const char *src_filename, const char *dest_filename)
{
  bool result; // al

  if ( src_filename && *src_filename && dest_filename && *dest_filename )
    result = MoveFileA(src_filename, dest_filename) != 0;
  else
    result = 0;
  return result;
}

// File Line: 627
// RVA: 0xA38170
char __fastcall UFG::PCFileDevice::FileOpen(UFG::PCFileDevice *this, UFG::qFile *file, bool warn_if_fail)
{
  UFG::qFile *v3; // rbx
  DWORD dwCreationDisposition; // ecx
  DWORD v5; // edx
  UFG::qFileAccessType v6; // eax
  bool v7; // si
  bool v8; // zf
  DWORD dwFlagsAndAttributes; // eax
  HANDLE v10; // rax
  DWORD v11; // eax
  int DistanceToMoveHigh; // [rsp+58h] [rbp+10h]

  v3 = file;
  dwCreationDisposition = 0;
  v5 = 0;
  v6 = v3->mAccessType;
  v7 = warn_if_fail;
  if ( v6 == 3 )
  {
    v5 = -1073741824;
    dwCreationDisposition = 2;
    goto LABEL_12;
  }
  if ( v6 & 1 )
  {
    v5 = 2147483648;
LABEL_11:
    dwCreationDisposition = 3;
    goto LABEL_12;
  }
  if ( v6 & 2 )
  {
    v5 = 0x40000000;
    dwCreationDisposition = 2;
    goto LABEL_12;
  }
  if ( v6 & 4 )
  {
    v5 = 0x40000000;
    dwCreationDisposition = 4;
    goto LABEL_12;
  }
  if ( v6 & 8 )
  {
    v5 = 0x40000000;
    goto LABEL_11;
  }
LABEL_12:
  v8 = (v6 & 0x10) == 0;
  dwFlagsAndAttributes = 128;
  if ( !v8 )
    dwFlagsAndAttributes = 0x8000000;
  v10 = CreateFileA(v3->mFilename, v5, 1u, 0i64, dwCreationDisposition, dwFlagsAndAttributes, 0i64);
  v8 = (v3->mAccessType & 4) == 0;
  v3->mFileHandle = v10;
  if ( !v8 )
  {
    DistanceToMoveHigh = 0;
    SetFilePointer(v10, 0, &DistanceToMoveHigh, 2u);
  }
  if ( v3->mFileHandle != (void *)-1i64 )
    return 1;
  if ( v7 )
  {
    v11 = GetLastError();
    UFG::qPrintf("WARNING: File open error code 0x%08x : %s\n", v11, v3->mFilename);
  }
  v3->mFileHandle = 0i64;
  return 0;
}

// File Line: 694
// RVA: 0xA38110
char __fastcall UFG::PCFileDevice::FileClose(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *v2; // rcx
  UFG::qFile *v3; // rbx

  v2 = file->mFileHandle;
  v3 = file;
  if ( !v2 )
    return 0;
  CloseHandle(v2);
  v3->mFileHandle = 0i64;
  return 1;
}

// File Line: 707
// RVA: 0xA38840
__int64 __fastcall UFG::PCFileDevice::GetFilePosition(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *v2; // rcx
  DWORD v4; // eax
  int DistanceToMoveHigh; // [rsp+38h] [rbp+10h]

  v2 = file->mFileHandle;
  if ( !v2 )
    return -1i64;
  DistanceToMoveHigh = 0;
  v4 = SetFilePointer(v2, 0, &DistanceToMoveHigh, 1u);
  return ((signed __int64)DistanceToMoveHigh << 32) | v4;
}

// File Line: 718
// RVA: 0xA38890
unsigned __int64 __fastcall UFG::PCFileDevice::GetFileSize(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *v2; // rcx
  DWORD v4; // eax
  unsigned int FileSizeHigh; // [rsp+38h] [rbp+10h]

  v2 = file->mFileHandle;
  if ( !v2 )
    return -1i64;
  FileSizeHigh = 0;
  v4 = GetFileSize(v2, &FileSizeHigh);
  return ((unsigned __int64)FileSizeHigh << 32) | v4;
}

// File Line: 735
// RVA: 0xA38140
char __fastcall UFG::PCFileDevice::FileFlush(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *v2; // rcx

  v2 = file->mFileHandle;
  if ( v2 == (void *)-1i64 )
    return 0;
  FlushFileBuffers(v2);
  return 1;
}

// File Line: 745
// RVA: 0xA382D0
char __fastcall UFG::PCFileDevice::FileSeek(UFG::PCFileDevice *this, UFG::qFile *file, UFG::qFileSeekType type, __int64 offset)
{
  void *v4; // rcx
  int DistanceToMoveHigh; // [rsp+38h] [rbp+10h]

  v4 = file->mFileHandle;
  if ( !v4 )
    return 0;
  if ( type != 1 || offset )
  {
    DistanceToMoveHigh = HIDWORD(offset);
    SetFilePointer(v4, offset, &DistanceToMoveHigh, type);
  }
  return 1;
}

// File Line: 768
// RVA: 0xA38290
__int64 __fastcall UFG::PCFileDevice::FileRead(UFG::PCFileDevice *this, UFG::qFile *file, void *buffer, __int64 num_bytes)
{
  void *v4; // rcx
  unsigned int NumberOfBytesRead; // [rsp+48h] [rbp+10h]

  v4 = file->mFileHandle;
  if ( !v4 )
    return 0i64;
  ReadFile(v4, buffer, num_bytes, &NumberOfBytesRead, 0i64);
  return NumberOfBytesRead;
}

// File Line: 782
// RVA: 0xA38320
__int64 __fastcall UFG::PCFileDevice::FileWrite(UFG::PCFileDevice *this, UFG::qFile *file, const void *buffer, __int64 num_bytes, bool *not_enough_space)
{
  void *v5; // rcx
  BOOL v7; // eax
  bool *v8; // rbx
  unsigned int NumberOfBytesWritten; // [rsp+48h] [rbp+10h]

  v5 = file->mFileHandle;
  if ( !v5 )
    return 0i64;
  NumberOfBytesWritten = 0;
  v7 = WriteFile(v5, buffer, num_bytes, &NumberOfBytesWritten, 0i64);
  v8 = not_enough_space;
  if ( not_enough_space )
  {
    if ( !v7 )
    {
      *v8 = GetLastError() == 39;
      return NumberOfBytesWritten;
    }
    *not_enough_space = 0;
  }
  return NumberOfBytesWritten;
}

// File Line: 867
// RVA: 0xA3A160
UFG::qString *__fastcall UFG::qMakeFullPath(UFG::qString *result, const char *filename)
{
  UFG::qString *v2; // rbx
  char *v3; // rax
  char v4; // dl
  char *v5; // rax
  char UserBuf; // [rsp+30h] [rbp-118h]

  v2 = result;
  v3 = fullpath(&UserBuf, filename, 0x104ui64);
  v4 = UserBuf;
  if ( !v3 )
    v4 = 0;
  UserBuf = v4;
  if ( v4 )
  {
    v5 = &UserBuf;
    do
    {
      if ( *v5 == 47 )
        *v5 = 92;
      ++v5;
    }
    while ( *v5 );
  }
  UFG::qString::qString(v2, &UserBuf);
  return v2;
}

// File Line: 882
// RVA: 0xA3A060
UFG::qString *__fastcall UFG::qMakeFullPath(UFG::qString *result, const char *base_directory, const char *rel_filename)
{
  const char *v3; // rbx
  const char *v4; // rsi
  UFG::qString *v5; // rdi
  char v6; // al
  UFG::qString *v7; // rax
  UFG::qString resulta; // [rsp+30h] [rbp-58h]
  UFG::qString v10; // [rsp+58h] [rbp-30h]

  v3 = rel_filename;
  v4 = base_directory;
  v5 = result;
  if ( (signed int)UFG::qStringLength(rel_filename) < 1
    || (v6 = v3[1], v6 != 58) && (*v3 != 92 || v6 != 92) && (*v3 != 47 || v6 != 47) )
  {
    UFG::qMakeFullPath(&resulta, v4);
    if ( !(unsigned int)UFG::qString::EndsWith(&resulta, "\\", -1) )
      UFG::qString::operator+=(&resulta, "\\");
    v7 = UFG::operator+(&v10, &resulta, v3);
    UFG::qMakeFullPath(v5, v7->mData);
    UFG::qString::~qString(&v10);
    UFG::qString::~qString(&resulta);
  }
  else
  {
    UFG::qMakeFullPath(v5, v3);
  }
  return v5;
}

// File Line: 928
// RVA: 0xA3A1F0
UFG::qString *__fastcall UFG::qMakeRelativePathFromDirToFile(UFG::qString *result, const char *from_directory, const char *to_filename)
{
  const char *v3; // rbx
  const char *v4; // rdi
  UFG::qString *v5; // rsi
  char v6; // al
  char *v7; // rax
  char *v8; // rdx
  UFG::qString v10; // [rsp+40h] [rbp-168h]
  UFG::qString resulta; // [rsp+68h] [rbp-140h]
  char pszPath; // [rsp+90h] [rbp-118h]
  char v13; // [rsp+91h] [rbp-117h]
  char v14; // [rsp+92h] [rbp-116h]

  v3 = to_filename;
  v4 = from_directory;
  v5 = result;
  UFG::qMakeFullPath(&resulta, from_directory);
  UFG::qMakeFullPath(&v10, v3);
  UFG::qString::qString(v5, v4);
  if ( PathRelativePathToA(&pszPath, resulta.mData, 0x10u, v10.mData, 0) )
  {
    v6 = pszPath;
    if ( pszPath )
    {
      v7 = &pszPath;
      do
      {
        if ( *v7 == 47 )
          *v7 = 92;
        ++v7;
      }
      while ( *v7 );
      v6 = pszPath;
    }
    if ( v6 != 46 || (v8 = &v14, v13 != 92) )
      v8 = &pszPath;
    UFG::qString::Set(v5, v8);
  }
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&resulta);
  return v5;
}

// File Line: 1018
// RVA: 0xA39BA0
UFG::qString *__fastcall UFG::qGetDirectory(UFG::qString *result)
{
  UFG::qString *v1; // rbx
  DWORD v2; // eax
  char v3; // dl
  char Buffer; // [rsp+30h] [rbp-408h]

  v1 = result;
  v2 = GetCurrentDirectoryA(0x400u, &Buffer);
  v3 = Buffer;
  if ( !v2 )
    v3 = 0;
  Buffer = v3;
  UFG::qString::qString(v1, &Buffer);
  return v1;
}

// File Line: 1031
// RVA: 0xA3A4A0
bool __fastcall UFG::qSetDirectory(const char *directory)
{
  return SetCurrentDirectoryA(directory) != 0;
}

// File Line: 1044
// RVA: 0x15ADF30
__int64 UFG::_dynamic_initializer_for__gPCFileDevice__()
{
  UFG::qFileDevice::qFileDevice((UFG::qFileDevice *)&UFG::gPCFileDevice.vfptr, "pc_hdd", -1, 0x7FFFFFFF, 0);
  UFG::gPCFileDevice.vfptr = (UFG::qFileDeviceVtbl *)&UFG::PCFileDevice::`vftable;
  UFG::qFileIoThread::qFileIoThread(&stru_14249CB38, "pc_hdd");
  UFG::qFileOpList::qFileOpList(&stru_14249CBA8, "pc_hdd");
  return atexit(UFG::_dynamic_atexit_destructor_for__gPCFileDevice__);
}

// File Line: 1047
// RVA: 0xA38AB0
void __fastcall UFG::qFileSystem::InitPlat(UFG::qFileSystem *this)
{
  UFG::qFileSystem::InitDevice(this, (UFG::qFileDevice *)&UFG::gPCFileDevice.vfptr);
}

// File Line: 1052
// RVA: 0xA37A60
void __fastcall UFG::qFileSystem::ClosePlat(UFG::qFileSystem *this)
{
  UFG::qFileSystem::CloseDevice(this, (UFG::qFileDevice *)&UFG::gPCFileDevice.vfptr);
}

// File Line: 1057
// RVA: 0xA38CB0
UFG::PCFileDevice *__fastcall UFG::qFileSystem::MapFilenameToDevicePlat(UFG::qFileSystem *this, const char *filename)
{
  return &UFG::gPCFileDevice;
}

