// File Line: 50
// RVA: 0xA37530
void __fastcall UFG::qMutex::qMutex(UFG::qMutex *this, const char *name)
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this, 0xFA0u);
}

// File Line: 86
// RVA: 0xA38CA0
void __stdcall UFG::qMutex::Lock(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

// File Line: 96
// RVA: 0xA397C0
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
  this->mHandlePlat = CreateEventA(0i64, auto_reset == 0, 0, 0i64);
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
  UFG::qEvent *v1; // rbx
  void *v2; // rcx

  v1 = this;
  v2 = this->mHandlePlat;
  if ( v2 != (void *)-1i64 )
    CloseHandle(v2);
  v1->mHandlePlat = (void *)-1i64;
}

// File Line: 134
// RVA: 0xA37AE0
void __fastcall UFG::qEvent::Create(UFG::qEvent *this, const char *name, bool auto_reset)
{
  this->mName = name;
  this->mAutoReset = auto_reset;
  this->mHandlePlat = CreateEventA(0i64, auto_reset == 0, 0, 0i64);
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
  return WaitForSingleObject(
           this->mHandlePlat,
           (unsigned __int64)(((unsigned __int64)(micro_seconds
                                                + 999
                                                - ((micro_seconds + 999) * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)
                            + ((micro_seconds + 999) * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 9) == 0;
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
  void *v2; // rcx
  bool result; // al

  this->mPriority = priority;
  v2 = this->mHandlePlat;
  if ( priority == -1 )
    priority = UFG::qThread::mDefaultThreadPriority;
  if ( v2 == (void *)-1i64 )
    result = 1;
  else
    result = SetThreadPriority(v2, priority) != 0;
  return result;
}

// File Line: 332
// RVA: 0xA39440
bool __fastcall UFG::qThread::SetLogicalCoreID(UFG::qThread *this, int logical_core_id)
{
  void *v2; // rcx
  bool result; // al

  this->mLogicalCoreID = logical_core_id;
  v2 = this->mHandlePlat;
  if ( v2 == (void *)-1i64 || logical_core_id == -1 )
    result = 1;
  else
    result = SetThreadIdealProcessor(v2, logical_core_id) != 0;
  return result;
}

// File Line: 352
// RVA: 0xA394D0
void __fastcall UFG::qThread::Start(UFG::qThread *this, void (__fastcall *thread_function)(void *), void *thread_param)
{
  int v3; // er9
  UFG::qThread *v4; // rbx
  HANDLE v5; // rax
  int v6; // edx
  void *v7; // rcx
  DWORD v8; // edx

  v3 = this->mStacksize;
  this->mThreadFunction = thread_function;
  this->mThreadParam = thread_param;
  if ( v3 <= 0 )
    v3 = UFG::qThread::mDefaultThreadStackSize;
  v4 = this;
  v5 = CreateThread(0i64, v3, (LPTHREAD_START_ROUTINE)thread_function, thread_param, 0, &this->mThreadIDPlat);
  v6 = v4->mPriority;
  v4->mHandlePlat = v5;
  if ( v6 == -1 )
    v6 = UFG::qThread::mDefaultThreadPriority;
  if ( v5 != (HANDLE)-1i64 )
    SetThreadPriority(v5, v6);
  v7 = v4->mHandlePlat;
  v8 = v4->mLogicalCoreID;
  if ( v7 != (void *)-1i64 && v8 != -1 )
    SetThreadIdealProcessor(v7, v8);
}

// File Line: 368
// RVA: 0xA39560
void __fastcall UFG::qThread::Stop(UFG::qThread *this)
{
  UFG::qThread *v1; // rbx
  void *v2; // rcx
  unsigned int ExitCode; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->mHandlePlat;
  if ( v2 != (void *)-1i64 )
  {
    GetExitCodeThread(v2, &ExitCode);
    if ( ExitCode == 259 )
    {
      UFG::qPrintf(
        "ERROR: Thread is still active at shutdown!!  Forcefully stopping a thread like this will almost certainly screw "
        "the OS!  thread=0x%08x - %s\n",
        v1->mHandlePlat,
        v1->mName);
      TerminateThread(v1->mHandlePlat, 0);
    }
    CloseHandle(v1->mHandlePlat);
    v1->mHandlePlat = (void *)-1i64;
  }
}

// File Line: 403
// RVA: 0xA39930
bool __fastcall UFG::qThread::WaitForCompletion(UFG::qThread *this)
{
  void *v1; // rcx
  bool result; // al

  v1 = this->mHandlePlat;
  if ( v1 == (void *)-1i64 )
    result = 1;
  else
    result = WaitForSingleObject(v1, 0xFFFFFFFF) == 0;
  return result;
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
  volatile int v2; // er8
  unsigned __int32 v3; // er9

  __asm { prefetchw byte ptr [rcx]; Prefetch processor cache line into L1 data cache (mark as modified) }
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gExecutableFilenameMutex__);
}

// File Line: 1092
// RVA: 0x15ADE80
__int64 UFG::_dynamic_initializer_for__gExceptionMutex__()
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&gExceptionMutex, 0xFA0u);
  return atexit(UFG::_dynamic_atexit_destructor_for__gExceptionMutex__);
}

// File Line: 1432
// RVA: 0x15ADE50
__int64 UFG::_dynamic_initializer_for__gCallstackDone__()
{
  UFG::gCallstackDone.mHandlePlat = CreateEventA(0i64, 0, 0, 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gCallstackDone__);
}

// File Line: 2267
// RVA: 0xA39C10
UFG::qString *__fastcall UFG::qGetLocalIP(UFG::qString *result)
{
  UFG::qString *v1; // rsi
  __int64 v2; // rbx
  _IP_ADAPTER_INFO *v3; // rdx
  struct hostent *v4; // rdi
  struct in_addr *v5; // rdx
  char *v6; // rax
  UFG::qString text; // [rsp+28h] [rbp-2DE0h]
  __int64 v9; // [rsp+50h] [rbp-2DB8h]
  WSAData WSAData; // [rsp+60h] [rbp-2DA8h]
  _IP_ADAPTER_INFO AdapterInfo; // [rsp+200h] [rbp-2C08h]
  UFG::qString *v12; // [rsp+2E10h] [rbp+8h]
  unsigned int SizePointer; // [rsp+2E18h] [rbp+10h]

  v12 = result;
  v9 = -2i64;
  v1 = result;
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
    UFG::qString::qString(v1, &text);
  }
  else
  {
    v3 = &AdapterInfo;
    while ( !v3->AddressLength || v3->IpAddressList.IpAddress.String[0] == 48 )
    {
      v3 = v3->Next;
      if ( !v3 )
        goto LABEL_8;
    }
    UFG::qString::Set(&text, v3->IpAddressList.IpAddress.String);
    UFG::qString::qString(v1, &text);
  }
  UFG::qString::~qString(&text);
  return v1;
}

// File Line: 2318
// RVA: 0xA39F60
UFG::qString *__fastcall UFG::qGetUserName(UFG::qString *result)
{
  UFG::qString *v1; // rbx
  BOOLEAN v2; // al
  char v3; // dl
  char NameBuffer; // [rsp+30h] [rbp-408h]
  int v6; // [rsp+448h] [rbp+10h]

  v1 = result;
  v6 = 1024;
  v2 = GetUserNameExA_0(NameDisplay, &NameBuffer, (PULONG)&v6);
  v3 = NameBuffer;
  if ( !v2 )
    v3 = 0;
  NameBuffer = v3;
  UFG::qString::qString(v1, &NameBuffer);
  return v1;
}

// File Line: 2358
// RVA: 0xA38D70
__int64 __fastcall UFG::OpenRegKey(const char *key_name, HKEY__ **sub_key, UFG::qString *value_name, bool read_only)
{
  bool v4; // r12
  UFG::qString *v5; // r15
  HKEY__ **v6; // r14
  unsigned int v7; // esi
  HKEY v8; // rdi
  UFG::qString *v9; // rax
  char *v10; // rbx
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
  signed int v26; // eax
  signed int v27; // er9
  UFG::qString v29; // [rsp+18h] [rbp-41h]
  UFG::qString v30; // [rsp+40h] [rbp-19h]
  __int64 v31; // [rsp+68h] [rbp+Fh]
  UFG::qString result; // [rsp+70h] [rbp+17h]
  int v33; // [rsp+D8h] [rbp+7Fh]

  v31 = -2i64;
  v4 = read_only;
  v5 = value_name;
  v6 = sub_key;
  UFG::qString::qString((UFG::qString *)((char *)&v30 + 24), key_name);
  UFG::qString::qString(&v29);
  v7 = 0;
  v8 = 0i64;
  v9 = UFG::qString::GetFilename(&v30, &result);
  UFG::qString::Set(v5, v9->mData, v9->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  *v6 = 0i64;
  UFG::qString::Set(&v29, v30.mData, v30.mLength - v5->mLength - 1, 0i64, 0);
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_CLASSES_ROOT", -1) )
  {
    v8 = HKEY_CLASSES_ROOT;
    v10 = v29.mData;
    v11 = UFG::qStringLength("HKEY_CLASSES_ROOT");
    UFG::qString::Set(&v29, &v10[v11 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_CURRENT_CONFIG", -1) )
  {
    v8 = HKEY_CURRENT_CONFIG;
    v12 = v29.mData;
    v13 = UFG::qStringLength("HKEY_CURRENT_CONFIG");
    UFG::qString::Set(&v29, &v12[v13 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_CURRENT_USER", -1) )
  {
    v8 = HKEY_CURRENT_USER;
    v14 = v29.mData;
    v15 = UFG::qStringLength("HKEY_CURRENT_USER");
    UFG::qString::Set(&v29, &v14[v15 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_LOCAL_MACHINE", -1) )
  {
    v8 = HKEY_LOCAL_MACHINE;
    v16 = v29.mData;
    v17 = UFG::qStringLength("HKEY_LOCAL_MACHINE");
    UFG::qString::Set(&v29, &v16[v17 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_PERFORMANCE_DATA", -1) )
  {
    v8 = HKEY_PERFORMANCE_DATA;
    v18 = v29.mData;
    v19 = UFG::qStringLength("HKEY_PERFORMANCE_DATA");
    UFG::qString::Set(&v29, &v18[v19 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_PERFORMANCE_NLSTEXT", -1) )
  {
    v8 = HKEY_PERFORMANCE_NLSTEXT;
    v20 = v29.mData;
    v21 = UFG::qStringLength("HKEY_PERFORMANCE_NLSTEXT");
    UFG::qString::Set(&v29, &v20[v21 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_PERFORMANCE_TEXT", -1) )
  {
    v8 = HKEY_PERFORMANCE_TEXT;
    v22 = v29.mData;
    v23 = UFG::qStringLength("HKEY_PERFORMANCE_TEXT");
    UFG::qString::Set(&v29, &v22[v23 + 1]);
  }
  if ( (unsigned int)UFG::qString::StartsWith(&v30, "HKEY_USERS", -1) )
  {
    v8 = HKEY_USERS;
    v24 = v29.mData;
    v25 = UFG::qStringLength("HKEY_USERS");
    UFG::qString::Set(&v29, &v24[v25 + 1]);
  }
  else if ( !v8 )
  {
LABEL_26:
    UFG::qString::Set(v5, 0i64);
    *v6 = 0i64;
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
  if ( v4 )
    v27 = 0;
  if ( RegOpenKeyExA(v8, v29.mData, 0, v26 | v27 | 1, v6) )
    goto LABEL_26;
  v7 = 1;
LABEL_27:
  UFG::qString::~qString(&v29);
  UFG::qString::~qString(&v30);
  return v7;
}

// File Line: 2411
// RVA: 0xA39D60
UFG::qString *__fastcall UFG::qGetRegistryValue(UFG::qString *result, const char *key_name, const char *default_value, const unsigned int key_context)
{
  const char *v4; // rdi
  UFG::qString *v5; // rsi
  unsigned int cbData; // [rsp+30h] [rbp-1048h]
  int v8; // [rsp+34h] [rbp-1044h]
  HKEY__ *sub_key; // [rsp+38h] [rbp-1040h]
  __int64 v10; // [rsp+40h] [rbp-1038h]
  UFG::qString value_name; // [rsp+48h] [rbp-1030h]
  char Data[4096]; // [rsp+70h] [rbp-1008h]
  UFG::qString *v13; // [rsp+1080h] [rbp+8h]

  v13 = result;
  v10 = -2i64;
  v4 = key_name;
  v5 = result;
  UFG::qString::qString(result, default_value);
  v8 = 1;
  UFG::qString::qString(&value_name);
  if ( (unsigned int)UFG::OpenRegKey(v4, &sub_key, &value_name, 1) )
  {
    cbData = 4096;
    if ( !RegQueryValueExA(sub_key, value_name.mData, 0i64, 0i64, Data, &cbData) )
    {
      Data[cbData] = 0;
      UFG::qString::Set(v5, Data);
    }
    RegCloseKey(sub_key);
  }
  UFG::qString::~qString(&value_name);
  return v5;
}

