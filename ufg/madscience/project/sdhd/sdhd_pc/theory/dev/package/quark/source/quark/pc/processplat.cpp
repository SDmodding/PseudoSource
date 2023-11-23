// File Line: 50
// RVA: 0xA37530
void __fastcall UFG::qMutex::qMutex(UFG::qMutex *this, const char *name)
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this, 0xFA0u);
}

// File Line: 86
// RVA: 0xA38CA0
// attributes: thunk
void __stdcall UFG::qMutex::Lock(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

// File Line: 96
// RVA: 0xA397C0
// attributes: thunk
void __stdcall UFG::qMutex::Unlock(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

// File Line: 118
// RVA: 0xA374D0
void __fastcall UFG::qEvent::qEvent(UFG::qEvent *this, const char *name, bool auto_reset)
{
  this->mName = name;
  this->mAutoReset = auto_reset;
  this->mHandlePlat = CreateEventA(0i64, !auto_reset, 0, 0i64);
}

// File Line: 123
// RVA: 0xA37510
void __fastcall UFG::qEvent::qEvent(UFG::qEvent *this)
{
  this->mName = 0i64;
  this->mHandlePlat = (void *)-1i64;
}

// File Line: 129
// RVA: 0xA37740
void __fastcall UFG::qEvent::~qEvent(UFG::qEvent *this)
{
  void *mHandlePlat; // rcx

  mHandlePlat = this->mHandlePlat;
  if ( mHandlePlat != (void *)-1i64 )
    CloseHandle(mHandlePlat);
  this->mHandlePlat = (void *)-1i64;
}

// File Line: 134
// RVA: 0xA37AE0
void __fastcall UFG::qEvent::Create(UFG::qEvent *this, const char *name, bool auto_reset)
{
  this->mName = name;
  this->mAutoReset = auto_reset;
  this->mHandlePlat = CreateEventA(0i64, !auto_reset, 0, 0i64);
}

// File Line: 152
// RVA: 0xA394C0
void __fastcall UFG::qEvent::Signal(UFG::qEvent *this)
{
  SetEvent(this->mHandlePlat);
}

// File Line: 157
// RVA: 0xA37A50
void __fastcall UFG::qEvent::Clear(UFG::qEvent *this)
{
  ResetEvent(this->mHandlePlat);
}

// File Line: 162
// RVA: 0xA398D0
bool __fastcall UFG::qEvent::Wait(UFG::qEvent *this)
{
  return WaitForSingleObject(this->mHandlePlat, 0xFFFFFFFF) == 0;
}

// File Line: 167
// RVA: 0xA398F0
bool __fastcall UFG::qEvent::Wait(UFG::qEvent *this, unsigned __int64 micro_seconds)
{
  return WaitForSingleObject(this->mHandlePlat, (micro_seconds + 999) / 0x3E8) == 0;
}

// File Line: 271
// RVA: 0xA376B0
void __fastcall UFG::qThread::qThread(UFG::qThread *this, const char *name)
{
  this->mName = name;
  *(_QWORD *)&this->mPriority = -1i64;
  this->mThreadFunction = 0i64;
  this->mThreadParam = 0i64;
  this->mStacksize = 0;
  this->mHandlePlat64 = 0i64;
  this->mThreadIDPlat = 0;
  this->mHandlePlat = (void *)-1i64;
}

// File Line: 286
// RVA: 0xA376E0
void __fastcall UFG::qThread::qThread(UFG::qThread *this)
{
  *(_QWORD *)&this->mPriority = -1i64;
  this->mHandlePlat = (void *)-1i64;
  this->mName = 0i64;
  this->mThreadFunction = 0i64;
  this->mThreadParam = 0i64;
  this->mStacksize = 0;
  this->mHandlePlat64 = 0i64;
  this->mThreadIDPlat = 0;
}

// File Line: 310
// RVA: 0xA39470
void __fastcall UFG::qBaseNodeRB::SetUID(UFG::qBaseNodeRB *this, unsigned int uid)
{
  this->mUID = uid;
}

// File Line: 315
// RVA: 0xA39480
bool __fastcall UFG::qThread::SetThreadPriority(UFG::qThread *this, int priority)
{
  void *mHandlePlat; // rcx

  this->mPriority = priority;
  mHandlePlat = this->mHandlePlat;
  if ( priority == -1 )
    priority = UFG::qThread::mDefaultThreadPriority;
  return mHandlePlat == (void *)-1i64 || SetThreadPriority(mHandlePlat, priority);
}

// File Line: 332
// RVA: 0xA39440
bool __fastcall UFG::qThread::SetLogicalCoreID(UFG::qThread *this, DWORD logical_core_id)
{
  void *mHandlePlat; // rcx

  this->mLogicalCoreID = logical_core_id;
  mHandlePlat = this->mHandlePlat;
  return mHandlePlat == (void *)-1i64
      || logical_core_id == -1
      || SetThreadIdealProcessor(mHandlePlat, logical_core_id) != 0;
}

// File Line: 352
// RVA: 0xA394D0
void __fastcall UFG::qThread::Start(UFG::qThread *this, void (__fastcall *thread_function)(void *), void *thread_param)
{
  int mStacksize; // r9d
  HANDLE Thread; // rax
  int mPriority; // edx
  void *mHandlePlat; // rcx
  int mLogicalCoreID; // edx

  mStacksize = this->mStacksize;
  this->mThreadFunction = thread_function;
  this->mThreadParam = thread_param;
  if ( mStacksize <= 0 )
    mStacksize = UFG::qThread::mDefaultThreadStackSize;
  Thread = CreateThread(
             0i64,
             mStacksize,
             (LPTHREAD_START_ROUTINE)thread_function,
             thread_param,
             0,
             &this->mThreadIDPlat);
  mPriority = this->mPriority;
  this->mHandlePlat = Thread;
  if ( mPriority == -1 )
    mPriority = UFG::qThread::mDefaultThreadPriority;
  if ( Thread != (HANDLE)-1i64 )
    SetThreadPriority(Thread, mPriority);
  mHandlePlat = this->mHandlePlat;
  mLogicalCoreID = this->mLogicalCoreID;
  if ( mHandlePlat != (void *)-1i64 && mLogicalCoreID != -1 )
    SetThreadIdealProcessor(mHandlePlat, mLogicalCoreID);
}

// File Line: 368
// RVA: 0xA39560
void __fastcall UFG::qThread::Stop(UFG::qThread *this)
{
  void *mHandlePlat; // rcx
  unsigned int ExitCode; // [rsp+30h] [rbp+8h] BYREF

  mHandlePlat = this->mHandlePlat;
  if ( mHandlePlat != (void *)-1i64 )
  {
    GetExitCodeThread(mHandlePlat, &ExitCode);
    if ( ExitCode == 259 )
    {
      UFG::qPrintf(
        "ERROR: Thread is still active at shutdown!!  Forcefully stopping a thread like this will almost certainly screw "
        "the OS!  thread=0x%08x - %s\n",
        this->mHandlePlat,
        this->mName);
      TerminateThread(this->mHandlePlat, 0);
    }
    CloseHandle(this->mHandlePlat);
    this->mHandlePlat = (void *)-1i64;
  }
}

// File Line: 403
// RVA: 0xA39930
bool __fastcall UFG::qThread::WaitForCompletion(UFG::qThread *this)
{
  void *mHandlePlat; // rcx

  mHandlePlat = this->mHandlePlat;
  return mHandlePlat == (void *)-1i64 || WaitForSingleObject(mHandlePlat, 0xFFFFFFFF) == 0;
}

// File Line: 438
// RVA: 0xA399F0
__int64 __fastcall UFG::qAtomicIncrement(volatile int *v)
{
  return (unsigned int)_InterlockedIncrement(v);
}

// File Line: 443
// RVA: 0xA399E0
__int64 __fastcall UFG::qAtomicDecrement(volatile int *v)
{
  return (unsigned int)_InterlockedDecrement(v);
}

// File Line: 448
// RVA: 0xA399B0
__int64 __fastcall UFG::qAtomicAdd(volatile int *v, int add_amount)
{
  int v2; // r8d
  unsigned __int32 v3; // r9d

  _m_prefetchw((const void *)v);
  do
  {
    v2 = *v;
    v3 = *v + add_amount;
  }
  while ( v2 != _InterlockedCompareExchange(v, v3, *v) );
  return v3;
}

// File Line: 594
// RVA: 0xA3A4C0
// attributes: thunk
void __stdcall UFG::qSleep(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}

// File Line: 599
// RVA: 0xA39B20
unsigned __int64 __fastcall UFG::qGetCurrentThreadID()
{
  return GetCurrentThreadId();
}

// File Line: 607
// RVA: 0x15ADEB0
__int64 UFG::_dynamic_initializer_for__gExecutableFilenameMutex__()
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&UFG::gExecutableFilenameMutex, 0xFA0u);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gExecutableFilenameMutex__);
}

// File Line: 1092
// RVA: 0x15ADE80
__int64 UFG::_dynamic_initializer_for__gExceptionMutex__()
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&gExceptionMutex, 0xFA0u);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gExceptionMutex__);
}

// File Line: 1432
// RVA: 0x15ADE50
__int64 UFG::_dynamic_initializer_for__gCallstackDone__()
{
  UFG::gCallstackDone.mHandlePlat = CreateEventA(0i64, 0, 0, 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gCallstackDone__);
}

// File Line: 2267
// RVA: 0xA39C10
UFG::qString *__fastcall UFG::qGetLocalIP(UFG::qString *result)
{
  __int64 v2; // rbx
  _IP_ADAPTER_INFO *p_AdapterInfo; // rdx
  struct hostent *v4; // rdi
  struct in_addr *v5; // rdx
  char *v6; // rax
  UFG::qString text; // [rsp+28h] [rbp-2DE0h] BYREF
  __int64 v9; // [rsp+50h] [rbp-2DB8h]
  WSAData WSAData; // [rsp+60h] [rbp-2DA8h] BYREF
  _IP_ADAPTER_INFO AdapterInfo; // [rsp+200h] [rbp-2C08h] BYREF
  unsigned int SizePointer; // [rsp+2E18h] [rbp+10h] BYREF

  v9 = -2i64;
  v2 = 0i64;
  UFG::qString::qString(&text);
  SizePointer = 11264;
  if ( GetAdaptersInfo_0(&AdapterInfo, &SizePointer) )
  {
LABEL_8:
    if ( WSAStartup(0x202u, &WSAData) >= 0 )
    {
      v4 = gethostbyname(0i64);
      if ( v4 && !text.mLength )
      {
        do
        {
          v5 = (struct in_addr *)v4->h_addr_list[v2];
          if ( !v5 )
            break;
          v6 = inet_ntoa(*v5);
          UFG::qString::Set(&text, v6);
          ++v2;
        }
        while ( !text.mLength );
      }
      WSACleanup();
    }
    UFG::qString::qString(result, &text);
  }
  else
  {
    p_AdapterInfo = &AdapterInfo;
    while ( !p_AdapterInfo->AddressLength || p_AdapterInfo->IpAddressList.IpAddress.String[0] == 48 )
    {
      p_AdapterInfo = p_AdapterInfo->Next;
      if ( !p_AdapterInfo )
        goto LABEL_8;
    }
    UFG::qString::Set(&text, p_AdapterInfo->IpAddressList.IpAddress.String);
    UFG::qString::qString(result, &text);
  }
  UFG::qString::~qString(&text);
  return result;
}

// File Line: 2318
// RVA: 0xA39F60
UFG::qString *__fastcall UFG::qGetUserName(UFG::qString *result)
{
  BOOLEAN UserName; // al
  char v3; // dl
  char NameBuffer[1032]; // [rsp+30h] [rbp-408h] BYREF
  unsigned int v6; // [rsp+448h] [rbp+10h] BYREF

  v6 = 1024;
  UserName = GetUserNameExA_0(NameDisplay, NameBuffer, &v6);
  v3 = NameBuffer[0];
  if ( !UserName )
    v3 = 0;
  NameBuffer[0] = v3;
  UFG::qString::qString(result, NameBuffer);
  return result;
}

// File Line: 2358
// RVA: 0xA38D70
__int64 __fastcall UFG::OpenRegKey(const char *key_name, HKEY__ **sub_key, UFG::qString *value_name, bool read_only)
{
  unsigned int v7; // esi
  unsigned __int64 v8; // rdi
  UFG::qString *Filename; // rax
  char *mData; // rbx
  int v11; // eax
  char *v12; // rbx
  int v13; // eax
  char *v14; // rbx
  int v15; // eax
  char *v16; // rbx
  int v17; // eax
  char *v18; // rbx
  int v19; // eax
  char *v20; // rbx
  int v21; // eax
  char *v22; // rbx
  int v23; // eax
  char *v24; // rbx
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  UFG::qString v29; // [rsp+18h] [rbp-41h] BYREF
  UFG::qString v30; // [rsp+40h] [rbp-19h] BYREF
  __int64 v31; // [rsp+68h] [rbp+Fh]
  UFG::qString result; // [rsp+70h] [rbp+17h] BYREF
  int v33; // [rsp+D8h] [rbp+7Fh]

  v31 = -2i64;
  UFG::qString::qString((UFG::qString *)&v30.mData, key_name);
  UFG::qString::qString(&v29);
  v7 = 0;
  v8 = 0i64;
  Filename = UFG::qString::GetFilename(&v30, &result);
  UFG::qString::Set(value_name, Filename->mData, Filename->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  *sub_key = 0i64;
  UFG::qString::Set(&v29, v30.mData, v30.mLength - value_name->mLength - 1, 0i64, 0);
  if ( UFG::qString::StartsWith(&v30, "HKEY_CLASSES_ROOT", -1) )
  {
    v8 = 0xFFFFFFFF80000000ui64;
    mData = v29.mData;
    v11 = UFG::qStringLength("HKEY_CLASSES_ROOT");
    UFG::qString::Set(&v29, &mData[v11 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_CURRENT_CONFIG", -1) )
  {
    v8 = -2147483643i64;
    v12 = v29.mData;
    v13 = UFG::qStringLength("HKEY_CURRENT_CONFIG");
    UFG::qString::Set(&v29, &v12[v13 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_CURRENT_USER", -1) )
  {
    v8 = -2147483647i64;
    v14 = v29.mData;
    v15 = UFG::qStringLength("HKEY_CURRENT_USER");
    UFG::qString::Set(&v29, &v14[v15 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_LOCAL_MACHINE", -1) )
  {
    v8 = -2147483646i64;
    v16 = v29.mData;
    v17 = UFG::qStringLength("HKEY_LOCAL_MACHINE");
    UFG::qString::Set(&v29, &v16[v17 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_PERFORMANCE_DATA", -1) )
  {
    v8 = -2147483644i64;
    v18 = v29.mData;
    v19 = UFG::qStringLength("HKEY_PERFORMANCE_DATA");
    UFG::qString::Set(&v29, &v18[v19 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_PERFORMANCE_NLSTEXT", -1) )
  {
    v8 = -2147483552i64;
    v20 = v29.mData;
    v21 = UFG::qStringLength("HKEY_PERFORMANCE_NLSTEXT");
    UFG::qString::Set(&v29, &v20[v21 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_PERFORMANCE_TEXT", -1) )
  {
    v8 = -2147483568i64;
    v22 = v29.mData;
    v23 = UFG::qStringLength("HKEY_PERFORMANCE_TEXT");
    UFG::qString::Set(&v29, &v22[v23 + 1]);
  }
  if ( UFG::qString::StartsWith(&v30, "HKEY_USERS", -1) )
  {
    v8 = -2147483645i64;
    v24 = v29.mData;
    v25 = UFG::qStringLength("HKEY_USERS");
    UFG::qString::Set(&v29, &v24[v25 + 1]);
  }
  else if ( !v8 )
  {
LABEL_26:
    UFG::qString::Set(value_name, 0i64);
    *sub_key = 0i64;
    goto LABEL_27;
  }
  if ( v33 == 1 )
  {
    v26 = 512;
  }
  else
  {
    v26 = 0;
    if ( v33 == 2 )
      v26 = 256;
  }
  v27 = 2;
  if ( read_only )
    v27 = 0;
  if ( RegOpenKeyExA((HKEY)v8, v29.mData, 0, v26 | v27 | 1, sub_key) )
    goto LABEL_26;
  v7 = 1;
LABEL_27:
  UFG::qString::~qString(&v29);
  UFG::qString::~qString(&v30);
  return v7;
}

// File Line: 2411
// RVA: 0xA39D60
UFG::qString *__fastcall UFG::qGetRegistryValue(
        UFG::qString *result,
        const char *key_name,
        const char *default_value,
        const unsigned int key_context)
{
  unsigned int cbData[2]; // [rsp+30h] [rbp-1048h] BYREF
  HKEY__ *sub_key[2]; // [rsp+38h] [rbp-1040h] BYREF
  UFG::qString value_name; // [rsp+48h] [rbp-1030h] BYREF
  char Data[4096]; // [rsp+70h] [rbp-1008h] BYREF

  sub_key[1] = (HKEY__ *)-2i64;
  UFG::qString::qString(result, default_value);
  cbData[1] = 1;
  UFG::qString::qString(&value_name);
  if ( (unsigned int)UFG::OpenRegKey(key_name, sub_key, &value_name, 1) )
  {
    cbData[0] = 4096;
    if ( !RegQueryValueExA(sub_key[0], value_name.mData, 0i64, 0i64, Data, cbData) )
    {
      Data[cbData[0]] = 0;
      UFG::qString::Set(result, Data);
    }
    RegCloseKey(sub_key[0]);
  }
  UFG::qString::~qString(&value_name);
  return result;
}

