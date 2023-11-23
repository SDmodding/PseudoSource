// File Line: 20
// RVA: 0xECCC9C
OSuite::ZGameInterface *__fastcall OSuite::GameInterface()
{
  return &OSuite::ZOnlineSuite::m_pInstance->m_gameInterface;
}

// File Line: 43
// RVA: 0xECC888
void __fastcall OSuite::ZOnlineSuite::ZOnlineSuite(OSuite::ZOnlineSuite *this)
{
  this->m_pGameConfig = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnlineSuite::`vftable;
  OSuite::ZGameInterface::ZGameInterface(&this->m_gameInterface);
  this->m_pszSessionId = 0i64;
  this->m_webServiceClientManager.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZWebServiceClientManager::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_webServiceClientManager.m_Mutex);
  OSuite::ZWebServiceClientManager::ZWebServiceClientList::ZWebServiceClientList(&this->m_webServiceClientManager.m_webServiceList);
}

// File Line: 47
// RVA: 0xECD04C
OSuite::ZOnlineSuite *__fastcall OSuite::ZOnlineSuite::Instance()
{
  return OSuite::ZOnlineSuite::m_pInstance;
}

// File Line: 59
// RVA: 0xECD1AC
__int64 __fastcall OSuite::ZOnlineSuite::PreInitialize(OSuite::IAllocator *preInitAllocator)
{
  OSuite::ZError::EError Clone; // eax

  OSuite::ZObject::m_allocator = preInitAllocator;
  Clone = (unsigned int)TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)preInitAllocator);
  OSuite::ZObject::m_allocator = 0i64;
  OSuite::ZOnlineSuite::m_preInitResult = Clone;
  return 0i64;
}

// File Line: 78
// RVA: 0xECCE9C
signed __int64 __fastcall OSuite::ZOnlineSuite::Initialize(
        OSuite::IAllocator *pAllocator,
        OSuite::IGameConfig *pGameConfig,
        const char *pszGameName,
        OSuite::ZOnlineSuite::OSUrlType ePreferedType)
{
  const char *v8; // rdx
  OSuite::IAllocator *v9; // rbx
  OSuite::IAllocatorVtbl *vfptr; // rdi
  unsigned __int64 v11; // rax
  OSuite::ZString *v12; // rax
  const char *v13; // rbx
  unsigned __int64 v14; // rax
  OSuite::ZOnlineSuite *v15; // rax
  OSuite::ZError::EError v16; // ebx
  OSuite::ZWorker *v17; // rax
  int v18; // ebx
  OSuite::ZWorker *v19; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-68h] BYREF
  OSuite::ZStringBuilder v21; // [rsp+38h] [rbp-50h] BYREF

  OSuite::ZObject::m_allocator = pAllocator;
  if ( !pGameConfig )
    return 2i64;
  v21.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v21, 0x40ui64);
  v8 = "http://%s.os.eidos.com:8080";
  if ( ePreferedType != URL_NONSECURE )
    v8 = "https://%s.os.eidos.com";
  OSuite::ZStringBuilder::AppendFormat(&v21, v8, pszGameName);
  v9 = OSuite::ZObject::m_allocator;
  vfptr = OSuite::ZObject::m_allocator->vfptr;
  v11 = OSuite::ZStringBuilder::Count(&v21);
  OSuite::ZOnlineSuite::m_pszGameUrl = (char *)vfptr->malloc(v9, v11 + 1, 0i64);
  v12 = OSuite::ZStringBuilder::ToString(&v21, &result);
  v13 = OSuite::ZString::c_str(v12);
  v14 = OSuite::ZStringBuilder::Count(&v21);
  strcpy_s(OSuite::ZOnlineSuite::m_pszGameUrl, v14 + 1, v13);
  OSuite::ZString::~ZString(&result);
  v15 = (OSuite::ZOnlineSuite *)OSuite::ZObject::operator new(0x90ui64);
  if ( v15 )
  {
    v15->m_pGameConfig = 0i64;
    v15->m_gameInterface.m_pLogger = 0i64;
    v15->m_gameInterface.m_strUserId.m_pString = 0i64;
    v15->m_pszSessionId = 0i64;
    v15->m_webServiceClientManager.m_Mutex.m_pInternalMutex = 0i64;
    v15->m_webServiceClientManager.m_webServiceList.m_pList = 0i64;
    OSuite::ZOnlineSuite::ZOnlineSuite(v15);
  }
  OSuite::ZOnlineSuite::m_pInstance = v15;
  v16 = (unsigned int)OSuite::ZGameInterface::Initialize(
                        &v15->m_gameInterface,
                        OSuite::ZOnlineSuite::m_pszGameUrl,
                        pGameConfig);
  OSuite::ZOnlineSuite::m_initResult = v16;
  if ( v16 == ZERROR_OK )
  {
    OSuite::psock::init();
    OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
    OSuite::TSingleton<OSuite::ZSocketManager>::Object();
    OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    OSuite::ZMetricAppender::Init();
    v17 = OSuite::ZWorker::Instance();
    OSuite::ZThread::Start(v17);
    OSuite::ZWorker::Instance()->m_deltaTimeUs = 60000;
    v18 = pGameConfig->vfptr->DefaultOnlineSuiteThreadPriority(pGameConfig);
    v19 = OSuite::ZWorker::Instance();
    OSuite::ZThread::SetAbsolutePriority(v19, v18);
    OSuite::ZOnlineSuite::m_pInstance->m_pGameConfig = pGameConfig;
    v16 = OSuite::ZOnlineSuite::m_initResult;
  }
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v21);
  return (unsigned int)v16;
}

// File Line: 133
// RVA: 0xECD31C
__int64 __fastcall OSuite::ZOnlineSuite::Update(OSuite::ZOnlineSuite *this)
{
  OSuite::ZWorker *v1; // rax

  v1 = OSuite::ZWorker::Instance();
  OSuite::ZWorker::CallCallbacks(v1);
  return 0i64;
}

// File Line: 141
// RVA: 0xECD294
__int64 __fastcall OSuite::ZOnlineSuite::Shutdown()
{
  OSuite::ZWorker *v0; // rax
  OSuite::ZWorker *v1; // rax

  OSuite::ZWebServiceClientManager::Clean(&OSuite::ZOnlineSuite::m_pInstance->m_webServiceClientManager);
  OSuite::ZMetricAppender::UnInit();
  v0 = OSuite::ZWorker::Instance();
  OSuite::ZWorker::Stop(v0);
  v1 = OSuite::ZWorker::Instance();
  OSuite::ZThread::Join(v1);
  OSuite::ZWorker::FreeInstance();
  OSuite::ZOnlineSuite::Cleanup(OSuite::ZOnlineSuite::m_pInstance);
  if ( OSuite::ZOnlineSuite::m_pInstance )
    OSuite::ZOnlineSuite::m_pInstance->vfptr->__vecDelDtor(OSuite::ZOnlineSuite::m_pInstance, 1i64);
  OSuite::ZOnlineSuite::m_pInstance = 0i64;
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, OSuite::ZOnlineSuite::m_pszGameUrl);
  OSuite::ZObject::m_allocator = 0i64;
  return 0i64;
}

// File Line: 170
// RVA: 0xECCB74
OSuite::ZWebServiceClient *__fastcall OSuite::ZOnlineSuite::CreateWebServiceClient(
        OSuite::ZOnlineSuite *this,
        const char *url,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *cb)
{
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rax
  OSuite::ZString *p_result; // rcx
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  const char *v11; // rax
  OSuite::ZWebServiceClient *v12; // rbx
  OSuite::ZString v14; // [rsp+20h] [rbp-29h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-11h] BYREF
  OSuite::ZString v16; // [rsp+50h] [rbp+7h] BYREF
  OSuite::ZString that; // [rsp+68h] [rbp+1Fh] BYREF

  that.m_pString = 0i64;
  OSuite::ZString::ZString(&that, url);
  if ( !OSuite::ZString::StartsWith(&that, "http") )
  {
    if ( OSuite::ZString::IndexOf(&that, 47, 0i64) )
    {
      OSuite::ZString::ZString(&v14, OSuite::ZOnlineSuite::m_pszGameUrl);
      v6 = OSuite::ZString::operator+(v5, &result, "/");
      v7 = OSuite::ZString::operator+(v6, &v16, &that);
      OSuite::ZString::operator=(&that, v7);
      OSuite::ZString::~ZString(&v16);
      OSuite::ZString::~ZString(&result);
      p_result = &v14;
    }
    else
    {
      OSuite::ZString::ZString(&result, OSuite::ZOnlineSuite::m_pszGameUrl);
      v10 = OSuite::ZString::operator+(v9, &v14, &that);
      OSuite::ZString::operator=(&that, v10);
      OSuite::ZString::~ZString(&v14);
      p_result = &result;
    }
    OSuite::ZString::~ZString(p_result);
  }
  v11 = OSuite::ZString::c_str(&that);
  v12 = OSuite::ZWebServiceClientManager::Create(&this->m_webServiceClientManager, v11, cb);
  OSuite::ZString::~ZString(&that);
  return v12;
}

// File Line: 188
// RVA: 0xECD1D4
void __fastcall OSuite::ZOnlineSuite::Release(OSuite::ZOnlineSuite *this, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZWebServiceClientManager::Release(&this->m_webServiceClientManager, pWebServiceClient, 0);
}

// File Line: 193
// RVA: 0xECCCA8
OSuite::ZWebServiceClient *__fastcall OSuite::ZOnlineSuite::GetForUrl(OSuite::ZOnlineSuite *this, OSuite::ZUrl *url)
{
  return OSuite::ZWebServiceClientManager::GetForUrl(&this->m_webServiceClientManager, url);
}

// File Line: 247
// RVA: 0xECD274
char __fastcall OSuite::ZOnlineSuite::SetPrimaryUser(int userId)
{
  OSuite::AuthenticationManager *v1; // rax

  OSuite::ZOnlineSuite::m_primaryUser = userId;
  v1 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  OSuite::AuthenticationManager::ForceTicketUpdate(v1);
  return 1;
}

// File Line: 261
// RVA: 0xECCCBC
char *__fastcall OSuite::ZOnlineSuite::GetSessionId(OSuite::ZOnlineSuite *this)
{
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rbx
  const char *v4; // rax
  OSuite::ZUuid v6; // [rsp+20h] [rbp-48h] BYREF
  OSuite::ZString result; // [rsp+40h] [rbp-28h] BYREF

  if ( !this->m_pszSessionId )
  {
    result.m_pString = 0i64;
    v6.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::ZObject};
    v6.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::IHashable};
    OSuite::psock::uuid::create(v6.m_anUuid, 1);
    OSuite::ZUuid::ToString(&v6, &result);
    v2 = OSuite::ZString::Count(&result);
    this->m_pszSessionId = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(
                                     OSuite::ZObject::m_allocator,
                                     v2 + 1,
                                     0i64);
    v3 = OSuite::ZString::Count(&result);
    v4 = OSuite::ZString::c_str(&result);
    strncpy_s(this->m_pszSessionId, v2 + 1, v4, v3);
    this->m_pszSessionId[OSuite::ZString::Count(&result)] = 0;
    OSuite::ZString::~ZString(&result);
  }
  return this->m_pszSessionId;
}

// File Line: 288
// RVA: 0xECCCB4
OSuite::IGameConfig *__fastcall OSuite::ZOnlineSuite::GetGameConfig(OSuite::ZOnlineSuite *this)
{
  return this->m_pGameConfig;
}

// File Line: 302
// RVA: 0xECCA44
void __fastcall OSuite::ZOnlineSuite::Cleanup(OSuite::ZOnlineSuite *this)
{
  if ( this->m_pszSessionId )
  {
    ((void (__fastcall *)(OSuite::IAllocator *))OSuite::ZObject::m_allocator->vfptr->free)(OSuite::ZObject::m_allocator);
    this->m_pszSessionId = 0i64;
  }
  this->m_pGameConfig = 0i64;
}

