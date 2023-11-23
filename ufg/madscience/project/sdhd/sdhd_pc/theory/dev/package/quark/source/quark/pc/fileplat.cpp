// File Line: 64
// RVA: 0xA3A330
char __fastcall UFG::qRemoveEmptyDirectoriesRecurse(const char *directory_base)
{
  HANDLE FirstFileA; // rbx
  bool v2; // al
  UFG::qString *v3; // rax
  UFG::qString v5; // [rsp+28h] [rbp-1F0h] BYREF
  UFG::qString lhs; // [rsp+50h] [rbp-1C8h] BYREF
  UFG::qString result; // [rsp+78h] [rbp-1A0h] BYREF
  UFG::qString v8; // [rsp+A0h] [rbp-178h] BYREF
  _WIN32_FIND_DATAA FindFileData; // [rsp+D0h] [rbp-148h] BYREF

  UFG::qString::qString(&lhs, directory_base);
  UFG::operator+(&result, &lhs, "\\*");
  FirstFileA = FindFirstFileA(result.mData, &FindFileData);
  if ( FirstFileA != (HANDLE)-1i64 )
  {
    do
    {
      v2 = FindFileData.cFileName[0] != 46
        || FindFileData.cFileName[1] && (FindFileData.cFileName[1] != 46 || FindFileData.cFileName[2]);
      if ( (FindFileData.dwFileAttributes & 0x10) != 0 && v2 )
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
    while ( FindNextFileA(FirstFileA, &FindFileData) );
    FindClose(FirstFileA);
  }
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&lhs);
  return 1;
}

// File Line: 187
// RVA: 0xA38CC0
void __fastcall UFG::PCFileDevice::Mount(UFG::PCFileDevice *this)
{
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *mPrev; // rax

  mPrev = this->mFileOpLists.mNode.UFG::qFileDevice::mPrev;
  mPrev->mNext = &this->mFileOpList;
  this->mFileOpList.mNext = &this->mFileOpLists.mNode;
  this->mFileOpList.mPrev = mPrev;
  this->mFileOpLists.mNode.UFG::qFileDevice::mPrev = &this->mFileOpList;
  UFG::qFileIoThread::Start(&this->mIoThread, this, &this->mFileOpList, 0, -1, -1);
}

// File Line: 194
// RVA: 0xA397D0
void __fastcall UFG::PCFileDevice::Unmount(UFG::PCFileDevice *this)
{
  UFG::PCFileDevice *v1; // rbx
  UFG::qFileDeviceVtbl *vfptr; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *mPrev; // rax

  v1 = this;
  UFG::qFileIoThread::Stop(&this->mIoThread);
  v1 = (UFG::PCFileDevice *)((char *)v1 + 264);
  vfptr = v1->vfptr;
  mPrev = v1->mPrev;
  *(_QWORD *)vfptr->gap8 = mPrev;
  mPrev->mPrev = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)vfptr;
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
  __int64 v2; // rbx
  const char *v3; // rcx
  _ULARGE_INTEGER FreeBytesAvailableToCaller; // [rsp+38h] [rbp+10h] BYREF
  _ULARGE_INTEGER TotalNumberOfFreeBytes; // [rsp+40h] [rbp+18h] BYREF
  _ULARGE_INTEGER TotalNumberOfBytes; // [rsp+48h] [rbp+20h] BYREF

  v2 = 0i64;
  v3 = "C:\\";
  if ( base_directory )
    v3 = base_directory;
  FreeBytesAvailableToCaller.QuadPart = 0i64;
  TotalNumberOfBytes.QuadPart = 0i64;
  TotalNumberOfFreeBytes.QuadPart = 0i64;
  if ( GetDiskFreeSpaceExA(v3, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes) )
    return (_ULARGE_INTEGER)FreeBytesAvailableToCaller.QuadPart;
  return (_ULARGE_INTEGER)v2;
}

// File Line: 228
// RVA: 0xA383E0
__int64 __fastcall UFG::PCFileDevice::FindFilesAndDirs(
        UFG::PCFileDevice *this,
        UFG::qList<UFG::qString,UFG::qString,1,0> *files,
        const char *initial_directory,
        bool recursive,
        UFG::qList<UFG::qString,UFG::qString,1,0> *file_patterns,
        UFG::qList<UFG::qString,UFG::qString,1,0> *dir_patterns)
{
  bool v6; // di
  UFG::qString *v9; // rax
  __int64 *v10; // rax
  __int64 *v11; // rcx
  __int64 *v12; // rax
  unsigned int v13; // r13d
  UFG::qString *v14; // r12
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  HANDLE FirstFileA; // rax
  void *v18; // rbx
  UFG::qString *v19; // rax
  UFG::qString *v20; // rax
  UFG::qString *v21; // rbx
  __int64 *v22; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v23; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rsi
  int v25; // r14d
  char *v26; // rbx
  char v27; // cl
  UFG::qString *v28; // rax
  UFG::qString *v29; // rax
  UFG::qString *v30; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v32; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rsi
  int matched; // r14d
  char *mData; // rbx
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
  __int64 *v47; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qString *v48; // [rsp+28h] [rbp-D8h]
  UFG::qString *v49; // [rsp+30h] [rbp-D0h]
  __int64 v50; // [rsp+38h] [rbp-C8h]
  UFG::qString v51; // [rsp+40h] [rbp-C0h] BYREF
  _WIN32_FIND_DATAA FindFileData; // [rsp+70h] [rbp-90h] BYREF
  HANDLE v53; // [rsp+1F8h] [rbp+F8h]

  v50 = -2i64;
  v6 = recursive;
  if ( !files || !initial_directory || !*initial_directory )
    return 0i64;
  v47 = (__int64 *)&v47;
  v48 = (UFG::qString *)&v47;
  v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v9 )
  {
    UFG::qString::qString(v9, initial_directory);
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
    mPrev = v14->mPrev;
    mNext = v14->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v14->mPrev = v14;
    v14->mNext = v14;
    UFG::qString::qString(&v51);
    UFG::qString::Format(&v51, "%s\\*", v14->mData);
    FirstFileA = FindFirstFileA(v51.mData, &FindFileData);
    v18 = FirstFileA;
    v53 = FirstFileA;
    if ( FirstFileA == (HANDLE)-1i64 )
    {
      UFG::qString::~qString(v14);
      operator delete[](v14);
      UFG::qString::~qString(&v51);
      break;
    }
    if ( !FirstFileA )
      goto LABEL_50;
    do
    {
      if ( (FindFileData.dwFileAttributes & 0x10) == 0 )
      {
        v32 = file_patterns;
        if ( !file_patterns )
          goto LABEL_48;
        v33 = file_patterns->mNode.mNext;
        do
        {
          if ( v33 == (UFG::qNode<UFG::qString,UFG::qString> *)v32 )
            break;
          matched = UFG::qWildcardMatchInsensitive((char *)v33[1].mNext, FindFileData.cFileName);
          if ( matched )
          {
            mData = v14->mData;
            if ( *mData == 46 )
            {
              v36 = mData[1];
              if ( v36 == 92 || v36 == 47 )
                mData += 2;
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
            UFG::qString::Format(v39, "%s\\%s", mData, FindFileData.cFileName);
            v40 = files->mNode.mPrev;
            v40->mNext = v39;
            v39->mPrev = v40;
            v39->mNext = &files->mNode;
            files->mNode.mPrev = v39;
            ++v13;
          }
          v33 = v33->mNext;
          v32 = file_patterns;
        }
        while ( !matched );
        goto LABEL_47;
      }
      if ( FindFileData.cFileName[0] != 46
        || FindFileData.cFileName[1] && (FindFileData.cFileName[1] != 46 || FindFileData.cFileName[2]) )
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
          UFG::qString::Format(v21, "%s\\%s", v14->mData, FindFileData.cFileName);
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
            v25 = UFG::qWildcardMatchInsensitive((char *)v24[1].mNext, FindFileData.cFileName);
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
              UFG::qString::Format(v30, "%s\\%s", v26, FindFileData.cFileName);
              v31 = files->mNode.mPrev;
              v31->mNext = v30;
              v30->mPrev = v31;
              v30->mNext = &files->mNode;
              files->mNode.mPrev = v30;
              ++v13;
            }
            v24 = v24->mNext;
            v23 = dir_patterns;
          }
          while ( !v25 );
LABEL_47:
          v18 = v53;
        }
      }
LABEL_48:
      v6 = recursive;
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
    i->mPrev = i;
    i->mNext = i;
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
bool __fastcall UFG::PCFileDevice::DirectoryExists(UFG::PCFileDevice *this, const char *directory)
{
  HANDLE FirstFileA; // rax
  _WIN32_FIND_DATAA FindFileData; // [rsp+20h] [rbp-148h] BYREF

  if ( !directory || !*directory )
    return 1;
  FirstFileA = FindFirstFileA(directory, &FindFileData);
  if ( FirstFileA == (HANDLE)-1i64 )
    return 0;
  FindClose(FirstFileA);
  return (FindFileData.dwFileAttributes & 0x10) != 0;
}

// File Line: 364
// RVA: 0xA37B10
char __fastcall UFG::PCFileDevice::CreateDirectoryA(UFG::PCFileDevice *this, const char *directory)
{
  UFG::qString *v2; // rax
  __int64 *v3; // rax
  __int64 *v4; // rcx
  __int64 *v5; // rax
  UFG::qString *FilePath; // rax
  UFG::qString *i; // rbx
  __int64 mPrev; // rbx
  char v9; // di
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  __int64 *v13; // rdx
  UFG::qString *v14; // rcx
  __int64 *v16; // [rsp+30h] [rbp-11h] BYREF
  UFG::qString *v17; // [rsp+38h] [rbp-9h]
  UFG::qString v18; // [rsp+40h] [rbp-1h] BYREF
  UFG::qString result; // [rsp+68h] [rbp+27h] BYREF

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
    FilePath = UFG::qString::GetFilePath(&v18, &result);
    UFG::qString::Set(&v18, FilePath->mData, FilePath->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
  }
  for ( i = v17; i != (UFG::qString *)&v16; i = (UFG::qString *)i->mNext )
  {
    if ( CreateDirectoryA(i->mData, 0i64) || GetLastError() == 183 )
    {
      if ( i != (UFG::qString *)&v16 )
      {
        mPrev = (__int64)i->mPrev;
        if ( (__int64 **)mPrev == &v16 )
        {
LABEL_18:
          v9 = 1;
          goto LABEL_20;
        }
        while ( CreateDirectoryA(*(LPCSTR *)(mPrev + 24), 0i64) || GetLastError() == 183 )
        {
          mPrev = *(_QWORD *)mPrev;
          if ( (__int64 **)mPrev == &v16 )
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
    mNext = j->mNext;
    v11->mNext = mNext;
    mNext->mPrev = v11;
    j->mPrev = j;
    j->mNext = j;
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
  UFG::qNode<UFG::qString,UFG::qString> *i; // rbx
  bool v4; // di
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> v11[2]; // [rsp+28h] [rbp-20h] BYREF

  if ( !directory || !*directory )
    return 0;
  v11[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v11;
  v11[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v11;
  if ( (unsigned int)UFG::qGetFiles(v11, directory, 1, pattern) )
  {
    for ( i = v11[0].mNode.mNext; i != (UFG::qNode<UFG::qString,UFG::qString> *)v11; i = i->mNext )
      UFG::qDeleteFile((const char *)i[1].mNext);
  }
  UFG::qRemoveEmptyDirectoriesRecurse(directory);
  v4 = RemoveDirectoryA(directory) || GetLastError() == 2;
  for ( j = (UFG::qString *)v11[0].mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v11[0].mNode.mNext != v11;
        j = (UFG::qString *)v11[0].mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v8 = v11[0].mNode.mPrev;
  v9 = v11[0].mNode.mNext;
  v11[0].mNode.mPrev->mNext = v11[0].mNode.mNext;
  v9->mPrev = v8;
  v11[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v11;
  v11[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v11;
  return v4;
}

// File Line: 451
// RVA: 0xA383A0
bool __fastcall UFG::PCFileDevice::FilenameExists(UFG::PCFileDevice *this, const char *filename)
{
  char FileInformation[56]; // [rsp+20h] [rbp-38h] BYREF

  return filename && *filename && GetFileAttributesExA(filename, GetFileExInfoStandard, FileInformation);
}

// File Line: 467
// RVA: 0xA38920
unsigned __int64 __fastcall UFG::PCFileDevice::GetFilenameSize(UFG::PCFileDevice *this, const char *filename)
{
  __int64 v2; // rbx
  char FileInformation[28]; // [rsp+20h] [rbp-38h] BYREF
  unsigned int v5; // [rsp+3Ch] [rbp-1Ch]
  unsigned int v6; // [rsp+40h] [rbp-18h]

  if ( !filename || !*filename )
    return 0i64;
  v2 = 0i64;
  if ( GetFileAttributesExA(filename, GetFileExInfoStandard, FileInformation) )
    return v6 | ((unsigned __int64)v5 << 32);
  return v2;
}

// File Line: 485
// RVA: 0xA38970
_FILETIME __fastcall UFG::PCFileDevice::GetFilenameTime(UFG::PCFileDevice *this, const char *filename)
{
  char FileInformation[20]; // [rsp+20h] [rbp-38h] BYREF
  FILETIME FileTime; // [rsp+34h] [rbp-24h] BYREF
  _FILETIME LocalFileTime; // [rsp+68h] [rbp+10h] BYREF

  if ( !filename || !*filename )
    return 0i64;
  if ( GetFileAttributesExA(filename, GetFileExInfoStandard, FileInformation)
    && FileTimeToLocalFileTime(&FileTime, &LocalFileTime) )
  {
    return LocalFileTime;
  }
  return 0i64;
}

// File Line: 518
// RVA: 0xA39340
bool __fastcall UFG::PCFileDevice::SetFilenameTime(
        UFG::PCFileDevice *this,
        const char *filename,
        FILETIME modification_time)
{
  HANDLE FileA; // rdi
  bool v6; // bl
  FILETIME LocalFileTime; // [rsp+68h] [rbp+10h] BYREF
  _FILETIME FileTime; // [rsp+78h] [rbp+20h] BYREF

  if ( !filename || !*filename )
    return 0;
  FileA = CreateFileA(filename, 0x180u, 0, 0i64, 3u, 0, 0i64);
  if ( GetLastError() == 2 )
    FileA = CreateFileA(filename, 0x180u, 0, 0i64, 1u, 0, 0i64);
  LocalFileTime = modification_time;
  LocalFileTimeToFileTime(&LocalFileTime, &FileTime);
  v6 = SetFileTime(FileA, 0i64, 0i64, &FileTime);
  CloseHandle(FileA);
  return v6;
}

// File Line: 552
// RVA: 0xA388D0
char __fastcall UFG::PCFileDevice::GetFilenameReadOnly(UFG::PCFileDevice *this, const char *filename)
{
  char v2; // bl
  char FileInformation[48]; // [rsp+20h] [rbp-38h] BYREF

  if ( !filename || !*filename )
    return 0;
  v2 = 0;
  if ( GetFileAttributesExA(filename, GetFileExInfoStandard, FileInformation) )
    return FileInformation[0] & 1;
  return v2;
}

// File Line: 570
// RVA: 0xA392C0
char __fastcall UFG::PCFileDevice::SetFilenameReadOnly(
        UFG::PCFileDevice *this,
        const char *filename,
        bool make_read_only)
{
  int FileInformation[14]; // [rsp+20h] [rbp-38h] BYREF

  if ( !filename || !*filename || !GetFileAttributesExA(filename, GetFileExInfoStandard, FileInformation) )
    return 0;
  if ( make_read_only )
    SetFileAttributesA(filename, FileInformation[0] | 1);
  else
    SetFileAttributesA(filename, FileInformation[0] & 0xFFFFFFFE);
  return 1;
}

// File Line: 593
// RVA: 0xA37E10
char __fastcall UFG::PCFileDevice::DeleteFilename(UFG::PCFileDevice *this, const char *filename)
{
  BOOL v2; // eax
  bool v3; // bl

  if ( !filename || !*filename )
    return 0;
  v2 = DeleteFileA(filename);
  v3 = v2;
  if ( !v2 && GetLastError() == 2 )
    return 1;
  return v3;
}

// File Line: 612
// RVA: 0xA39270
bool __fastcall UFG::PCFileDevice::RenameFilename(
        UFG::PCFileDevice *this,
        const char *src_filename,
        const char *dest_filename)
{
  return src_filename && *src_filename && dest_filename && *dest_filename && MoveFileA(src_filename, dest_filename);
}

// File Line: 627
// RVA: 0xA38170
char __fastcall UFG::PCFileDevice::FileOpen(UFG::PCFileDevice *this, UFG::qFile *file, bool warn_if_fail)
{
  DWORD dwCreationDisposition; // ecx
  DWORD v5; // edx
  UFG::qFileAccessType mAccessType; // eax
  bool v8; // zf
  DWORD dwFlagsAndAttributes; // eax
  HANDLE FileA; // rax
  DWORD LastError; // eax
  int DistanceToMoveHigh; // [rsp+58h] [rbp+10h] BYREF

  dwCreationDisposition = 0;
  v5 = 0;
  mAccessType = file->mAccessType;
  if ( mAccessType == QACCESS_READ_WRITE )
  {
    v5 = -1073741824;
    dwCreationDisposition = 2;
    goto LABEL_12;
  }
  if ( (mAccessType & 1) != 0 )
  {
    v5 = 0x80000000;
LABEL_11:
    dwCreationDisposition = 3;
    goto LABEL_12;
  }
  if ( (mAccessType & 2) != 0 )
  {
    v5 = 0x40000000;
    dwCreationDisposition = 2;
    goto LABEL_12;
  }
  if ( (mAccessType & 4) != 0 )
  {
    v5 = 0x40000000;
    dwCreationDisposition = 4;
    goto LABEL_12;
  }
  if ( (mAccessType & 8) != 0 )
  {
    v5 = 0x40000000;
    goto LABEL_11;
  }
LABEL_12:
  v8 = (mAccessType & 0x10) == 0;
  dwFlagsAndAttributes = 128;
  if ( !v8 )
    dwFlagsAndAttributes = 0x8000000;
  FileA = CreateFileA(file->mFilename, v5, 1u, 0i64, dwCreationDisposition, dwFlagsAndAttributes, 0i64);
  v8 = (file->mAccessType & 4) == 0;
  file->mFileHandle = FileA;
  if ( !v8 )
  {
    DistanceToMoveHigh = 0;
    SetFilePointer(FileA, 0, &DistanceToMoveHigh, 2u);
  }
  if ( file->mFileHandle != (void *)-1i64 )
    return 1;
  if ( warn_if_fail )
  {
    LastError = GetLastError();
    UFG::qPrintf("WARNING: File open error code 0x%08x : %s\n", LastError, file->mFilename);
  }
  file->mFileHandle = 0i64;
  return 0;
}

// File Line: 694
// RVA: 0xA38110
char __fastcall UFG::PCFileDevice::FileClose(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *mFileHandle; // rcx

  mFileHandle = file->mFileHandle;
  if ( !mFileHandle )
    return 0;
  CloseHandle(mFileHandle);
  file->mFileHandle = 0i64;
  return 1;
}

// File Line: 707
// RVA: 0xA38840
__int64 __fastcall UFG::PCFileDevice::GetFilePosition(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *mFileHandle; // rcx
  DWORD v4; // eax
  int DistanceToMoveHigh; // [rsp+38h] [rbp+10h] BYREF

  mFileHandle = file->mFileHandle;
  if ( !mFileHandle )
    return -1i64;
  DistanceToMoveHigh = 0;
  v4 = SetFilePointer(mFileHandle, 0, &DistanceToMoveHigh, 1u);
  return ((__int64)DistanceToMoveHigh << 32) | v4;
}

// File Line: 718
// RVA: 0xA38890
unsigned __int64 __fastcall UFG::PCFileDevice::GetFileSize(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *mFileHandle; // rcx
  DWORD FileSize; // eax
  unsigned int FileSizeHigh; // [rsp+38h] [rbp+10h] BYREF

  mFileHandle = file->mFileHandle;
  if ( !mFileHandle )
    return -1i64;
  FileSizeHigh = 0;
  FileSize = GetFileSize(mFileHandle, &FileSizeHigh);
  return ((unsigned __int64)FileSizeHigh << 32) | FileSize;
}

// File Line: 735
// RVA: 0xA38140
char __fastcall UFG::PCFileDevice::FileFlush(UFG::PCFileDevice *this, UFG::qFile *file)
{
  void *mFileHandle; // rcx

  mFileHandle = file->mFileHandle;
  if ( mFileHandle == (void *)-1i64 )
    return 0;
  FlushFileBuffers(mFileHandle);
  return 1;
}

// File Line: 745
// RVA: 0xA382D0
char __fastcall UFG::PCFileDevice::FileSeek(UFG::PCFileDevice *this, UFG::qFile *file, DWORD type, __int64 offset)
{
  void *mFileHandle; // rcx
  int DistanceToMoveHigh; // [rsp+38h] [rbp+10h] BYREF

  mFileHandle = file->mFileHandle;
  if ( !mFileHandle )
    return 0;
  if ( type != 1 || offset )
  {
    DistanceToMoveHigh = HIDWORD(offset);
    SetFilePointer(mFileHandle, offset, &DistanceToMoveHigh, type);
  }
  return 1;
}

// File Line: 768
// RVA: 0xA38290
__int64 __fastcall UFG::PCFileDevice::FileRead(
        UFG::PCFileDevice *this,
        UFG::qFile *file,
        void *buffer,
        __int64 num_bytes)
{
  void *mFileHandle; // rcx
  unsigned int NumberOfBytesRead; // [rsp+48h] [rbp+10h] BYREF

  mFileHandle = file->mFileHandle;
  if ( !mFileHandle )
    return 0i64;
  ReadFile(mFileHandle, buffer, num_bytes, &NumberOfBytesRead, 0i64);
  return NumberOfBytesRead;
}

// File Line: 782
// RVA: 0xA38320
__int64 __fastcall UFG::PCFileDevice::FileWrite(
        UFG::PCFileDevice *this,
        UFG::qFile *file,
        const void *buffer,
        __int64 num_bytes,
        bool *not_enough_space)
{
  void *mFileHandle; // rcx
  BOOL v7; // eax
  bool *v8; // rbx
  unsigned int NumberOfBytesWritten; // [rsp+48h] [rbp+10h] BYREF

  mFileHandle = file->mFileHandle;
  if ( !mFileHandle )
    return 0i64;
  NumberOfBytesWritten = 0;
  v7 = WriteFile(mFileHandle, buffer, num_bytes, &NumberOfBytesWritten, 0i64);
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
  char *v3; // rax
  char v4; // dl
  char *v5; // rax
  char UserBuf[280]; // [rsp+30h] [rbp-118h] BYREF

  v3 = fullpath(UserBuf, filename, 0x104ui64);
  v4 = UserBuf[0];
  if ( !v3 )
    v4 = 0;
  UserBuf[0] = v4;
  if ( v4 )
  {
    v5 = UserBuf;
    do
    {
      if ( *v5 == 47 )
        *v5 = 92;
      ++v5;
    }
    while ( *v5 );
  }
  UFG::qString::qString(result, UserBuf);
  return result;
}

// File Line: 882
// RVA: 0xA3A060
UFG::qString *__fastcall UFG::qMakeFullPath(UFG::qString *result, const char *base_directory, const char *rel_filename)
{
  char v6; // al
  UFG::qString *v7; // rax
  UFG::qString resulta; // [rsp+30h] [rbp-58h] BYREF
  UFG::qString v10; // [rsp+58h] [rbp-30h] BYREF

  if ( (int)UFG::qStringLength(rel_filename) >= 1
    && ((v6 = rel_filename[1], v6 == 58) || *rel_filename == 92 && v6 == 92 || *rel_filename == 47 && v6 == 47) )
  {
    UFG::qMakeFullPath(result, rel_filename);
  }
  else
  {
    UFG::qMakeFullPath(&resulta, base_directory);
    if ( !UFG::qString::EndsWith(&resulta, "\\", -1) )
      UFG::qString::operator+=(&resulta, "\\");
    v7 = UFG::operator+(&v10, &resulta, rel_filename);
    UFG::qMakeFullPath(result, v7->mData);
    UFG::qString::~qString(&v10);
    UFG::qString::~qString(&resulta);
  }
  return result;
}

// File Line: 928
// RVA: 0xA3A1F0
UFG::qString *__fastcall UFG::qMakeRelativePathFromDirToFile(
        UFG::qString *result,
        const char *from_directory,
        const char *to_filename)
{
  char v6; // al
  char *v7; // rax
  char *v8; // rdx
  UFG::qString v10; // [rsp+40h] [rbp-168h] BYREF
  UFG::qString resulta; // [rsp+68h] [rbp-140h] BYREF
  char pszPath[2]; // [rsp+90h] [rbp-118h] BYREF
  char v13; // [rsp+92h] [rbp-116h] BYREF

  UFG::qMakeFullPath(&resulta, from_directory);
  UFG::qMakeFullPath(&v10, to_filename);
  UFG::qString::qString(result, from_directory);
  if ( PathRelativePathToA(pszPath, resulta.mData, 0x10u, v10.mData, 0) )
  {
    v6 = pszPath[0];
    if ( pszPath[0] )
    {
      v7 = pszPath;
      do
      {
        if ( *v7 == 47 )
          *v7 = 92;
        ++v7;
      }
      while ( *v7 );
      v6 = pszPath[0];
    }
    if ( v6 != 46 || (v8 = &v13, pszPath[1] != 92) )
      v8 = pszPath;
    UFG::qString::Set(result, v8);
  }
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&resulta);
  return result;
}

// File Line: 1018
// RVA: 0xA39BA0
UFG::qString *__fastcall UFG::qGetDirectory(UFG::qString *result)
{
  DWORD CurrentDirectoryA; // eax
  char v3; // dl
  char Buffer[1032]; // [rsp+30h] [rbp-408h] BYREF

  CurrentDirectoryA = GetCurrentDirectoryA(0x400u, Buffer);
  v3 = Buffer[0];
  if ( !CurrentDirectoryA )
    v3 = 0;
  Buffer[0] = v3;
  UFG::qString::qString(result, Buffer);
  return result;
}

// File Line: 1031
// RVA: 0xA3A4A0
bool __fastcall UFG::qSetDirectory(const char *directory)
{
  return SetCurrentDirectoryA(directory);
}

// File Line: 1044
// RVA: 0x15ADF30
__int64 UFG::_dynamic_initializer_for__gPCFileDevice__()
{
  UFG::qFileDevice::qFileDevice(&UFG::gPCFileDevice, "pc_hdd", -1, 0x7FFFFFFF, CASE_INSENSITIVE);
  UFG::gPCFileDevice.vfptr = (UFG::qFileDeviceVtbl *)&UFG::PCFileDevice::`vftable;
  UFG::qFileIoThread::qFileIoThread(&stru_14249CB38, "pc_hdd");
  UFG::qFileOpList::qFileOpList(&stru_14249CBA8, "pc_hdd");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gPCFileDevice__);
}

// File Line: 1047
// RVA: 0xA38AB0
void __fastcall UFG::qFileSystem::InitPlat(UFG::qFileSystem *this)
{
  UFG::qFileSystem::InitDevice(this, &UFG::gPCFileDevice);
}

// File Line: 1052
// RVA: 0xA37A60
void __fastcall UFG::qFileSystem::ClosePlat(UFG::qFileSystem *this)
{
  UFG::qFileSystem::CloseDevice(this, &UFG::gPCFileDevice);
}

// File Line: 1057
// RVA: 0xA38CB0
UFG::PCFileDevice *__fastcall UFG::qFileSystem::MapFilenameToDevicePlat(UFG::qFileSystem *this, const char *filename)
{
  return &UFG::gPCFileDevice;
}

