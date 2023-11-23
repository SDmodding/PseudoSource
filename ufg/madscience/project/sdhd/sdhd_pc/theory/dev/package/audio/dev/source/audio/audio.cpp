// File Line: 51
// RVA: 0x1465680
__int64 dynamic_initializer_for__g_AudioMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&g_AudioMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_AudioMemoryPool__);
}

// File Line: 52
// RVA: 0x1465660
__int64 dynamic_initializer_for__g_AudioComponentPool__()
{
  UFG::qMemoryPool::qMemoryPool(&g_AudioComponentPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_AudioComponentPool__);
}

// File Line: 69
// RVA: 0x142B20
char *__fastcall AK::AllocHook(unsigned __int64 in_size)
{
  if ( in_size >= 0x20000 )
    return UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, in_size, "AUDIOKINETIC", 0i64, 0);
  else
    return UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, in_size, "AUDIOKINETIC_TOP", 1ui64, 0);
}

// File Line: 96
// RVA: 0x14E890
char *__fastcall AK::VirtualAllocHook(
        void *in_pMemAddress,
        unsigned __int64 in_size,
        unsigned int in_dwAllocationType,
        unsigned int in_dwProtect)
{
  if ( in_size >= 0x20000 )
    return UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, in_size, "AUDIOKINETIC", 0i64, 0);
  else
    return UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, in_size, "AUDIOKINETIC_TOP", 1ui64, 0);
}

// File Line: 205
// RVA: 0x1465600
__int64 UFG::_dynamic_initializer_for__gAudioListener__()
{
  `eh vector constructor iterator(
    (char *)gAudioListener,
    0x70ui64,
    8,
    (void (__fastcall *)(void *))UFG::Audio3DListener::Audio3DListener);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gAudioListener__);
}

// File Line: 210
// RVA: 0x1465170
__int64 dynamic_initializer_for__UFG::TiDo::sm_eventFilterString__()
{
  UFG::qString::qString(&UFG::TiDo::sm_eventFilterString, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_eventFilterString__);
}

// File Line: 211
// RVA: 0x14653D0
__int64 dynamic_initializer_for__UFG::TiDo::sm_tweakedEventFilterString__()
{
  UFG::qString::qString(&UFG::TiDo::sm_tweakedEventFilterString, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_tweakedEventFilterString__);
}

// File Line: 212
// RVA: 0x14651A0
__int64 dynamic_initializer_for__UFG::TiDo::sm_filterList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_filterList__);
}

// File Line: 214
// RVA: 0x1465290
__int64 dynamic_initializer_for__UFG::TiDo::sm_objectFilterString__()
{
  UFG::qString::qString(&UFG::TiDo::sm_objectFilterString, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_objectFilterString__);
}

// File Line: 215
// RVA: 0x1465400
__int64 dynamic_initializer_for__UFG::TiDo::sm_tweakedObjectFilterString__()
{
  UFG::qString::qString(&UFG::TiDo::sm_tweakedObjectFilterString, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_tweakedObjectFilterString__);
}

// File Line: 216
// RVA: 0x1465270
__int64 dynamic_initializer_for__UFG::TiDo::sm_objectFilterList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_objectFilterList__);
}

// File Line: 234
// RVA: 0x1465070
__int64 dynamic_initializer_for__UFG::TiDo::sm_audioLoadMutex__()
{
  UFG::qMutex::qMutex(&UFG::TiDo::sm_audioLoadMutex, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_audioLoadMutex__);
}

// File Line: 235
// RVA: 0x14650A0
__int64 dynamic_initializer_for__UFG::TiDo::sm_audioShutdownMutex__()
{
  UFG::qMutex::qMutex(&UFG::TiDo::sm_audioShutdownMutex, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TiDo::sm_audioShutdownMutex__);
}

// File Line: 264
// RVA: 0x146F20
void __fastcall UFG::InitAudioMemPool(unsigned int size)
{
  if ( g_AudioMemoryPool.mInitializedUID != 0x34566543 )
    UFG::qMemoryPool::Init(&g_AudioMemoryPool, "AudioMemory", size, 0x10000, 0, 1u, 0i64, 1, 1);
  if ( g_AudioComponentPool.mInitializedUID != 0x34566543 )
    UFG::qMemoryPool::Init(
      &g_AudioComponentPool,
      "AudioComponentMemory",
      0xE0000i64,
      0xC0000,
      1,
      1u,
      UFG::gMainMemoryPool,
      1,
      1);
}

// File Line: 309
// RVA: 0x140AB0
void __fastcall UFG::TiDo::TiDo(UFG::TiDo *this)
{
  this->vfptr = (UFG::TiDoVtbl *)&UFG::TiDo::`vftable;
  UFG::qFixedAllocator::Init(&UFG::gAudioEventPool, 77824, 152, "AudioEventPool", 0i64);
  UFG::qFixedAllocator::Init(&UFG::gAudioEventCallbackObjectPool, 0x4000, 16, "AudioEventCallbackObject", 0i64);
}

// File Line: 316
// RVA: 0x141700
void __fastcall UFG::TiDo::~TiDo(UFG::TiDo *this)
{
  this->vfptr = (UFG::TiDoVtbl *)&UFG::TiDo::`vftable;
  if ( UFG::TiDo::m_pInstance )
    UFG::TiDo::m_pInstance->vfptr->__vecDelDtor(UFG::TiDo::m_pInstance, 1i64);
  if ( g_AudioMemoryPool.mInitializedUID == 878077251 )
    UFG::qMemoryPool::Close(&g_AudioMemoryPool);
  if ( g_AudioComponentPool.mInitializedUID == 878077251 )
    UFG::qMemoryPool::Close(&g_AudioComponentPool);
}

// File Line: 354
// RVA: 0x146440
void __fastcall UFG::TiDo::GetProjectSubpath(UFG::TiDo *this, UFG::qString *path)
{
  unsigned __int64 v3; // rbx
  UFG::qReflectWarehouse *v4; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectObject *ObjectByName; // rax
  const char *vfptr; // r8
  UFG::qString *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  v3 = UFG::qStringHash64("UFG::SoundEngineInitParamsReflect", 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v4, v3);
  ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, "SoundEngineParams");
  if ( LODWORD(ObjectByName[1].mBaseNode.mUID) )
    vfptr = (const char *)ObjectByName[1].vfptr;
  else
    vfptr = &customCaption;
  v8 = UFG::qString::FormatEx(&result, "%s", vfptr);
  UFG::qString::Set(path, v8->mData, v8->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
}

// File Line: 366
// RVA: 0x146100
UFG::TiDo *__fastcall UFG::TiDo::GetInstance()
{
  return UFG::TiDo::m_pInstance;
}

// File Line: 374
// RVA: 0x146110
_BOOL8 __fastcall UFG::TiDo::GetIsInstantiated()
{
  return UFG::TiDo::m_pInstance != 0i64;
}

// File Line: 439
// RVA: 0x14C330
void __fastcall UFG::TiDo::SetWwiseIOPaths(UFG::TiDo *this)
{
  UFG::qString *v2; // rbx
  UFG::qString *Directory; // rax
  UFG::qString v4; // [rsp+38h] [rbp-D0h] BYREF
  UFG::qString lhs; // [rsp+60h] [rbp-A8h] BYREF
  UFG::qString result; // [rsp+88h] [rbp-80h] BYREF
  UFG::qString v7; // [rsp+B0h] [rbp-58h] BYREF
  UFG::qString v8; // [rsp+D8h] [rbp-30h] BYREF

  UFG::qString::qString(&v4);
  (*(void (__fastcall **)(UFG::TiDo *, UFG::qString *))&this->vfptr->gap8[8])(this, &v4);
  UFG::qString::FormatEx(&result, "\\Data\\Audio\\%s\\", v4.mData);
  UFG::qString::qString(&lhs);
  this->vfptr->LookupLocalisedLanguage(this, &lhs);
  v2 = UFG::operator+(&v8, &lhs, "\\");
  Directory = UFG::qGetDirectory(&v7);
  UFG::WwiseInterface::SetIOPaths(Directory->mData, result.mData, result.mData, v2->mData, &customCaption);
  UFG::qString::~qString(&v7);
  UFG::qString::~qString(&v8);
  UFG::qString::~qString(&lhs);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v4);
}

// File Line: 455
// RVA: 0x1482C0
void __fastcall UFG::TiDo::LoadDefaultFilePackages(UFG::TiDo *this)
{
  unsigned __int64 v1; // rbx
  UFG::qReflectWarehouse *v2; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectObject *ObjectByName; // rdi
  unsigned int v5; // ebx
  __int64 v6; // rdx
  UFG::qReflectObjectVtbl *vfptr; // rcx
  const char *GetTypeName; // r10
  char v9; // r8
  char v10; // r9
  UFG::qSymbol deviceName; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol *p_deviceName; // [rsp+50h] [rbp+18h]

  v1 = UFG::qStringHash64("UFG::FilePackageManifest", 0xFFFFFFFFFFFFFFFFui64);
  v2 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v2, v1);
  ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, "FilePackageList");
  v5 = 0;
  if ( LODWORD(ObjectByName[1].mBaseNode.mUID) )
  {
    p_deviceName = &deviceName;
    do
    {
      v6 = 7i64 * v5;
      vfptr = ObjectByName[1].vfptr;
      if ( LODWORD(vfptr[v6 + 6].__vecDelDtor) )
        GetTypeName = (const char *)vfptr[v6 + 5].GetTypeName;
      else
        GetTypeName = &customCaption;
      v9 = (char)vfptr[v6 + 6].GetTypeName;
      v10 = BYTE1(vfptr[v6 + 6].GetTypeName);
      deviceName.mUID = (unsigned int)vfptr[v6 + 5].__vecDelDtor;
      UFG::WwiseInterface::LoadFilePackage((__int64)&deviceName, GetTypeName, v9, v10);
      ++v5;
    }
    while ( v5 < LODWORD(ObjectByName[1].mBaseNode.mUID) );
  }
}

// File Line: 481
// RVA: 0x14E630
void __fastcall UFG::TiDo::UpdateFrame(UFG::TiDo *this, float delta_sec)
{
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
  if ( UFG::TiDo::sm_shuttingDown )
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
  }
  else
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    if ( UFG::AudioListener::sm_pInstance )
      ((void (__fastcall *)(UFG::AudioListener *))UFG::AudioListener::sm_pInstance->vfptr->Update)(UFG::AudioListener::sm_pInstance);
    UFG::SoundBankManager::Update(delta_sec);
    UFG::OneShotPool::Update();
    UFG::AudioEventManager::UpdateEventList(&UFG::AudioEventManager::sm_orphanEventList);
    UFG::AudioEntityManager::Update(delta_sec);
    if ( AK::SoundEngine::IsInitialized() )
      AK::SoundEngine::RenderAudio();
  }
}

// File Line: 563
// RVA: 0x145F40
void __fastcall UFG::TiDo::GetInitParams(UFG::TiDo *this, UFG::SoundEngineInitParams *initParams)
{
  unsigned __int64 v3; // rbx
  UFG::qReflectWarehouse *v4; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectObject *ObjectByName; // rdi
  unsigned int v7; // ebp
  UFG::qList<UFG::SoundEngineDeviceSettings,UFG::SoundEngineDeviceSettings,1,0> *p_m_devices; // r14
  _DWORD *v9; // rbx
  char *v10; // rax
  char *v11; // rdx
  int v12; // ecx
  UFG::qNode<UFG::SoundEngineDeviceSettings,UFG::SoundEngineDeviceSettings> *mPrev; // rax

  v3 = UFG::qStringHash64("UFG::SoundEngineInitParamsReflect", 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v4, v3);
  ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, "SoundEngineParams");
  initParams->maxMemoryPools = (int)ObjectByName[1].mBaseNode.mParent;
  initParams->memorySize = HIDWORD(ObjectByName[1].mBaseNode.mParent) << 10;
  initParams->affinityMask = HIDWORD(ObjectByName[1].mBaseNode.mNeighbours[1]);
  initParams->stackSize = HIDWORD(ObjectByName[1].mTypeUID);
  v7 = 0;
  if ( LODWORD(ObjectByName[2].mBaseNode.mUID) )
  {
    p_m_devices = &initParams->m_devices;
    do
    {
      v9 = (_DWORD *)ObjectByName[2].vfptr + 26 * v7;
      v10 = UFG::qMalloc(0x30ui64, "SoundEngineDeviceSettings", 0i64);
      v11 = v10;
      if ( v10 )
      {
        *((_QWORD *)v10 + 1) = v10 + 8;
        *((_QWORD *)v10 + 2) = v10 + 8;
        *(_QWORD *)v10 = &UFG::SoundEngineDeviceSettings::`vftable;
        *((_DWORD *)v10 + 6) = -1;
      }
      else
      {
        v11 = 0i64;
      }
      *((_DWORD *)v11 + 6) = v9[20];
      v12 = v9[21] << 10;
      *((_DWORD *)v11 + 8) = v12;
      *((_DWORD *)v11 + 11) = v9[24];
      *((_DWORD *)v11 + 9) = v9[22];
      *((_DWORD *)v11 + 10) = v9[23];
      *((_DWORD *)v11 + 7) = 2 * v12 * *((_DWORD *)v11 + 11);
      mPrev = p_m_devices->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::SoundEngineDeviceSettings,UFG::SoundEngineDeviceSettings> *)(v11 + 8);
      *((_QWORD *)v11 + 1) = mPrev;
      *((_QWORD *)v11 + 2) = p_m_devices;
      p_m_devices->mNode.mPrev = (UFG::qNode<UFG::SoundEngineDeviceSettings,UFG::SoundEngineDeviceSettings> *)(v11 + 8);
      ++v7;
    }
    while ( v7 < LODWORD(ObjectByName[2].mBaseNode.mUID) );
  }
  initParams->defaultPoolSize = (int)(float)(*(float *)ObjectByName[1].mBaseNode.mChildren * 1048576.0);
  initParams->preparedEventPoolSize = (int)(float)(*((float *)ObjectByName[1].mBaseNode.mChildren + 1) * 1048576.0);
  initParams->enginePoolSize = (int)(float)(*(float *)&ObjectByName[1].mBaseNode.mChildren[1] * 1048576.0);
  initParams->defaultPoolLowMemoryThreshold = *((float *)&ObjectByName[1].mBaseNode.mChildren[1] + 1);
  initParams->lowerEngineLowMemoryThreshold = *(float *)ObjectByName[1].mBaseNode.mNeighbours;
  initParams->maxNumPaths = HIDWORD(ObjectByName[1].mBaseNode.mNeighbours[0]);
  initParams->maxNumTransitions = (int)ObjectByName[1].mBaseNode.mNeighbours[1];
  initParams->streamingLookAheadRatio = *(float *)&ObjectByName[1].mHandles.mNode.mNext;
  initParams->enableRumble = BYTE4(ObjectByName[1].mHandles.mNode.mNext);
}

// File Line: 671
// RVA: 0x146E90
void __fastcall UFG::TiDo::Init(UFG::TiDo *this, UFG::SoundEngineInitParams *initParams)
{
  UFG::qFixedAllocator::Init(&UFG::gOneShotPool, 27600, 368, "OneShotPool", 0i64);
  UFG::TiDo::sm_isMuted = 0;
  UFG::gEnableAudioProfiler = 1;
  UFG::WwiseInterface::InitializeSoundEngine(initParams);
  UFG::SoundBankManager::Init();
  (*(void (__fastcall **)(UFG::TiDo *))this->vfptr->gap8)(this);
  UFG::TiDo::LoadDefaultFilePackages(this);
  this->vfptr->LoadAudio(this, "Global");
  this->vfptr->InitAudioTweaker(this);
}

// File Line: 699
// RVA: 0x14C960
void __fastcall UFG::TiDo::Shutdown(UFG::TiDo *this)
{
  if ( !UFG::WwiseInterface::smShuttingDown )
    AK::SoundEngine::StopAll(0xFFFFFFFFui64);
  ((void (__fastcall *)(UFG::TiDo *))this->vfptr->UpdateFrame)(this);
  UFG::TiDo::m_pInstance->vfptr->Close(UFG::TiDo::m_pInstance);
  UFG::TiDo::sm_soundEnabled = 0;
}

// File Line: 769
// RVA: 0x148ED0
void UFG::TiDo::MarkAllOcclusionInfosDirty(void)
{
  __int64 (__fastcall **v0)(); // rax
  UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *p_mNext; // rbx
  __int64 (__fastcall **v2)(); // [rsp+30h] [rbp+8h] BYREF

  v0 = &`UFG::TiDo::MarkAllOcclusionInfosDirty::`2::MakeOcclusionDirtyFunctor::`vftable;
  p_mNext = (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
  v2 = &`UFG::TiDo::MarkAllOcclusionInfosDirty::`2::MakeOcclusionDirtyFunctor::`vftable;
  if ( &UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext != (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> **)((char *)&UFG::AudioEntityManager::sm_EntityList - 8) )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(__int64 (__fastcall ***)(), UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *))*v0)(
        &v2,
        p_mNext);
      p_mNext = (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)&p_mNext[1].mNode.mPrev[-1].mNext;
      if ( p_mNext == (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)((char *)&UFG::AudioEntityManager::sm_EntityList
                                                                          - 8) )
        break;
      v0 = v2;
    }
  }
}

// File Line: 773
// RVA: 0x144E60
void __fastcall UFG::TiDo::MarkAllOcclusionInfosDirty_::_2_::MakeOcclusionDirtyFunctor::Do(
        UFG::AudioEntity *pAe,
        __int64 a2)
{
  *(_BYTE *)(a2 + 299) = 1;
}

// File Line: 787
// RVA: 0x148EB0
char __fastcall UFG::TiDo::LookupLocalisedLanguage(UFG::TiDo *this, UFG::qString *language)
{
  UFG::qString::Set(language, "English(US)");
  return 1;
}

// File Line: 830
// RVA: 0x143D20
void __fastcall UFG::TiDo::Close(UFG::TiDo *this)
{
  if ( UFG::TiDo::sm_soundEnabled )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioShutdownMutex);
    if ( !UFG::TiDo::sm_fullShutdownOccurred )
    {
      UFG::TiDo::sm_fullShutdownOccurred = 1;
      UFG::SoundBankManager::OnGameShutdown();
      UFG::WwiseInterface::ShutdownSoundEngine();
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioShutdownMutex);
  }
}

// File Line: 927
// RVA: 0x148D90
void __fastcall UFG::TiDo::LoadingGameStart(UFG::TiDo *this, UFG::qWiseSymbol *loadingMixState)
{
  `anonymous namespace::gLoadingGame = 1;
}

// File Line: 936
// RVA: 0x148D70
char __fastcall UFG::TiDo::LoadingGameEnd(UFG::TiDo *this, UFG::qWiseSymbol *endLoadMixState)
{
  if ( UFG::WwiseInterface::smLoadScreen )
    return 0;
  `anonymous namespace::gLoadingGame = 0;
  return 1;
}

// File Line: 949
// RVA: 0x147E70
void __fastcall UFG::TiDo::LoadAudio(UFG::TiDo *this, const char *name)
{
  UFG::SoundBankManager::LoadGroup(name);
}

// File Line: 954
// RVA: 0x14CE60
void __fastcall UFG::TiDo::UnloadAudio(UFG::TiDo *this, const char *name)
{
  UFG::SoundBankManager::UnloadGroup(name);
}

// File Line: 965
// RVA: 0x14CD50
void UFG::TiDo::StopSound(void)
{
  UFG::TiDo::m_pInstance->vfptr->Close(UFG::TiDo::m_pInstance);
  UFG::TiDo::sm_soundEnabled = 0;
}

// File Line: 974
// RVA: 0x14CAD0
void UFG::TiDo::StartSound(void)
{
  UFG::TiDo::sm_soundEnabled = 1;
  UFG::TiDo::m_pInstance->vfptr->Init(UFG::TiDo::m_pInstance);
}

// File Line: 982
// RVA: 0x143890
signed __int64 __fastcall UFG::TiDo::CalcWwiseUid(const char *name)
{
  signed __int64 result; // rax

  result = UFG::qStringLength(name);
  if ( (_DWORD)result )
    return AK::SoundEngine::GetIDFromString(name);
  return result;
}

// File Line: 995
// RVA: 0x146160
const char *__fastcall UFG::TiDo::GetNameFromWwiseUid(unsigned int uid)
{
  UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
  return UFG::qWiseSymbolRegistry::Get(uid);
}

// File Line: 1008
// RVA: 0x14C590
bool __fastcall UFG::TiDo::SetWwiseSwitch(
        UFG::TiDo *this,
        unsigned int switchId,
        unsigned int switchStateId,
        unsigned __int64 objectId)
{
  return UFG::WwiseInterface::SetWwiseSwitch(switchId, switchStateId, objectId);
}

// File Line: 1032
// RVA: 0x14C430
bool __fastcall UFG::TiDo::SetWwiseRtpcValue(
        UFG::TiDo *this,
        unsigned int rtpcId,
        float value,
        unsigned __int64 objectId)
{
  return UFG::WwiseInterface::SetWwiseRtpcValue(rtpcId, value, objectId);
}

// File Line: 1059
// RVA: 0x144470
bool __fastcall UFG::TiDo::Debug_GetWwiseState(UFG::TiDo *this, unsigned int stateId, unsigned int *state)
{
  return AK::SoundEngine::Query::GetState(stateId, state) == AK_Success;
}

// File Line: 1097
// RVA: 0x14CD30
void __fastcall UFG::TiDo::StopPlaying(UFG::TiDo *this, unsigned int playingId)
{
  if ( playingId )
  {
    if ( !UFG::WwiseInterface::smShuttingDown )
      AK::SoundEngine::StopPlayingID(playingId, 0, AkCurveInterpolation_Linear);
  }
}

// File Line: 1106
// RVA: 0x14B890
void __fastcall UFG::TiDo::ScreenMinimized(UFG::TiDo *this, bool isScreenMinimized)
{
  unsigned int IDFromString; // eax
  unsigned int v3; // eax

  if ( isScreenMinimized )
  {
    UFG::TiDo::sm_isMuted = 1;
    if ( (unsigned int)UFG::qStringLength("master_volume") )
    {
      IDFromString = AK::SoundEngine::GetIDFromString("master_volume");
      UFG::WwiseInterface::SetWwiseRtpcValue(IDFromString, 0.0, 0xFFFFFFFFFFFFFFFFui64);
    }
    else
    {
      UFG::WwiseInterface::SetWwiseRtpcValue(0, 0.0, 0xFFFFFFFFFFFFFFFFui64);
    }
  }
  else
  {
    UFG::TiDo::sm_isMuted = 0;
    v3 = UFG::qStringLength("master_volume");
    if ( v3 )
      v3 = AK::SoundEngine::GetIDFromString("master_volume");
    UFG::WwiseInterface::SetWwiseRtpcValue(v3, 10.0, 0xFFFFFFFFFFFFFFFFui64);
  }
}

// File Line: 1133
// RVA: 0x14C170
void __fastcall UFG::TiDo::SetRumbleEnabled(UFG::TiDo *this, bool enabled)
{
  float v3; // xmm6_4
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF

  UFG::TiDo::sm_rumbleEnabled = enabled;
  if ( enabled )
    v3 = *(float *)&FLOAT_1_0;
  else
    v3 = 0.0;
  UFG::qWiseSymbol::create_from_string(&result, "rumble_enabled");
  UFG::WwiseInterface::SetWwiseRtpcValue(result.mUID, v3, 0xFFFFFFFFFFFFFFFFui64);
  AK::SoundEngine::SetListenerPipeline(0, 1, enabled);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 1150
// RVA: 0x14B010
void __fastcall UFG::TiDo::RegisterControllerForEvents(UFG::TiDo *this, int iControllerNum)
{
  char v2; // bl
  float v3; // xmm6_4

  if ( iControllerNum >= 0 )
  {
    v2 = iControllerNum;
    if ( UFG::TiDo::sm_rumbleEnabled )
      v3 = 0.0;
    else
      v3 = FLOAT_N96_0;
    if ( iControllerNum < 4 && AK::MotionEngine::AddPlayerMotionDevice(iControllerNum, 0, 0x196u, 0i64) == AK_Success )
      AK::MotionEngine::SetPlayerVolume(v2, v3);
  }
}

// File Line: 1161
// RVA: 0x14D180
void __fastcall UFG::TiDo::UnregisterControllerForEvents(UFG::TiDo *this, unsigned int iControllerNum)
{
  if ( iControllerNum <= 3 )
    AK::MotionEngine::RemovePlayerMotionDevice(iControllerNum, 0, 0x196u);
}

// File Line: 1237
// RVA: 0x144AC0
float __fastcall UFG::TiDo::Distance2FromListener(UFG::TiDo *this, unsigned int id, UFG::qVector3 *emitterPos)
{
  float result; // xmm0_4
  UFG::Audio3DListener *v4; // rax
  float v5; // xmm0_4

  result = *(float *)&FLOAT_1_0;
  if ( id < 8 )
  {
    v4 = &gAudioListener[id];
    if ( v4 )
    {
      v5 = emitterPos->z - v4->m_matrix.v3.z;
      return (float)((float)((float)(emitterPos->y - v4->m_matrix.v3.y) * (float)(emitterPos->y - v4->m_matrix.v3.y))
                   + (float)((float)(emitterPos->x - v4->m_matrix.v3.x) * (float)(emitterPos->x - v4->m_matrix.v3.x)))
           + (float)(v5 * v5);
    }
  }
  return result;
}

// File Line: 1251
// RVA: 0x144B20
float __fastcall UFG::TiDo::Distance2FromListener(UFG::TiDo *this, unsigned int id, UFG::qVector4 *emitterPos)
{
  float result; // xmm0_4
  UFG::Audio3DListener *v4; // rax

  result = *(float *)&FLOAT_1_0;
  if ( id < 8 )
  {
    v4 = &gAudioListener[id];
    if ( v4 )
      return (float)((float)((float)(emitterPos->y - v4->m_matrix.v3.y) * (float)(emitterPos->y - v4->m_matrix.v3.y))
                   + (float)((float)(emitterPos->x - v4->m_matrix.v3.x) * (float)(emitterPos->x - v4->m_matrix.v3.x)))
           + (float)((float)(emitterPos->z - v4->m_matrix.v3.z) * (float)(emitterPos->z - v4->m_matrix.v3.z));
  }
  return result;
}

// File Line: 1282
// RVA: 0x146120
UFG::Audio3DListener *__fastcall UFG::TiDo::GetListener(UFG::TiDo *this, unsigned int id)
{
  if ( id >= 8 )
    return 0i64;
  else
    return &gAudioListener[id];
}

// File Line: 1293
// RVA: 0x145DB0
// attributes: thunk
UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *__fastcall UFG::TiDo::GetEntity(UFG::qSymbol *id)
{
  return UFG::AudioEntityManager::FindNamed(id);
}

// File Line: 1314
// RVA: 0x148AC0
char __fastcall UFG::TiDo::LoadFilePackage(const char *packageName, unsigned int *deviceName, bool localized, bool dlc)
{
  UFG::qSymbol deviceNamea; // [rsp+48h] [rbp+10h] BYREF

  deviceNamea.mUID = *deviceName;
  return UFG::WwiseInterface::LoadFilePackage((__int64)&deviceNamea, packageName, localized, dlc);
}

// File Line: 1320
// RVA: 0x14CF40
char __fastcall UFG::TiDo::UnloadFilePackage(const char *packageName)
{
  UFG::WwiseInterface::UnloadFilePackage(packageName);
  return 1;
}

// File Line: 1327
// RVA: 0x148D00
char __fastcall UFG::TiDo::LoadWwiseBank(UFG::qWiseSymbol *bankId)
{
  UFG::SoundBank *SoundBank; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
  if ( UFG::TiDo::sm_shuttingDown )
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    return 0;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
  if ( bankId->mUID - 1 > 0xFFFFFFFD )
    return 0;
  SoundBank = UFG::SoundBankManager::FindOrCreateSoundBank(bankId);
  if ( !SoundBank )
    return 0;
  ++SoundBank->m_count;
  return 1;
}

// File Line: 1346
// RVA: 0x1468C0
// attributes: thunk
__int64 __fastcall UFG::TiDo::GetWwiseStreamFileSize(unsigned int fileId)
{
  return UFG::WwiseInterface::GetStreamFileSize(fileId);
}

// File Line: 1352
// RVA: 0x14D100
char __fastcall UFG::TiDo::UnloadWwiseBank(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v3; // rax
  UFG::SoundBank *p_mCount; // rcx
  unsigned int m_count; // eax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
  if ( UFG::TiDo::sm_shuttingDown )
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    return 0;
  }
  else
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    if ( bankId->mUID - 1 <= 0xFFFFFFFD )
    {
      v3 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID);
      if ( v3 )
      {
        p_mCount = (UFG::SoundBank *)&v3[-1].mCount;
        if ( v3 != (UFG::qBaseTreeRB *)8 )
        {
          m_count = p_mCount->m_count;
          if ( m_count )
            p_mCount->m_count = m_count - 1;
        }
      }
    }
    return 1;
  }
}

// File Line: 1368
// RVA: 0x143530
_BOOL8 __fastcall UFG::TiDo::BankLoaded(unsigned int bankId)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v2; // rax
  UFG::SoundBank *p_mCount; // rax
  bool v4; // bl
  UFG::qWiseSymbol v6; // [rsp+48h] [rbp+10h] BYREF

  mUID = UFG::qSymbol::qSymbol(&v6, bankId)->mUID;
  v4 = 0;
  if ( mUID )
  {
    v2 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, mUID);
    if ( v2 )
    {
      p_mCount = (UFG::SoundBank *)&v2[-1].mCount;
      if ( p_mCount )
      {
        if ( p_mCount->m_loadState == LoadState_Loaded )
          v4 = 1;
      }
    }
  }
  _((AMD_HD3D *)v6.mUID);
  return v4;
}

// File Line: 1386
// RVA: 0x14AC30
void __fastcall UFG::TiDo::PostGlobalEvent(unsigned int eventId)
{
  UFG::WwiseInterface::PostAudioEvent(eventId, 1ui64, 0, 0i64, 0i64);
}

// File Line: 1505
// RVA: 0x147B80
char __fastcall UFG::TiDo::IsEventEnabled(UFG::TiDo *this, unsigned int eventId)
{
  const char *v3; // rax
  char v4; // di
  UFG::qString *i; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  if ( UFG::qString::operator==(&UFG::TiDo::sm_eventFilterString, &customCaption)
    || UFG::qString::operator==(&UFG::TiDo::sm_eventFilterString, "unfiltered") )
  {
    return 1;
  }
  UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
  v3 = UFG::qWiseSymbolRegistry::Get(eventId);
  UFG::qString::qString(&v7, v3);
  v4 = 1;
  for ( i = (UFG::qString *)UFG::TiDo::sm_filterList.mNode.mNext;
        i != (UFG::qString *)&UFG::TiDo::sm_filterList;
        i = (UFG::qString *)i->mNext )
  {
    if ( (unsigned int)UFG::qString::StartsWith(i, "!", -1) )
    {
      UFG::qString::Substring(i, &result, 1, -1);
      if ( (unsigned int)UFG::qString::find(&v7, result.mData) != UFG::qString::npos )
        v4 = 0;
      UFG::qString::~qString(&result);
    }
    else if ( (unsigned int)UFG::qString::find(&v7, i->mData) == UFG::qString::npos )
    {
      v4 = 0;
    }
  }
  UFG::qString::~qString(&v7);
  return v4;
}

// File Line: 1593
// RVA: 0x148380
void __fastcall UFG::TiDo::LoadEventSymbols(UFG::TiDo *this)
{
  SimpleXML::XMLDocument *v1; // rax
  SimpleXML::XMLDocument *v2; // rdi
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *i; // rbp
  char *Name; // rax
  SimpleXML::XMLNode *j; // rbx
  char *v7; // rax
  char *v8; // rax
  SimpleXML::XMLNode *k; // rbx
  char *v10; // rax
  char *v11; // rax
  SimpleXML::XMLNode *m; // rsi
  SimpleXML::XMLNode *Node; // rbx
  char *v14; // rax
  char *v15; // rax
  SimpleXML::XMLNode *n; // rbx
  char *v17; // rax
  char *v18; // rax
  SimpleXML::XMLNode *ii; // rbx
  char *v20; // rax
  UFG::qString v21; // [rsp+28h] [rbp-30h] BYREF

  if ( !UFG::TiDo::sm_eventSymbolsLoaded )
  {
    UFG::qString::qString(&v21, "Data\\Global\\Act\\AudioTag.xml");
    v1 = SimpleXML::XMLDocument::Open(v21.mData, 1ui64, 0i64);
    v2 = v1;
    if ( v1 )
    {
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, 0i64);
      if ( ChildNode )
      {
        for ( i = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, ChildNode);
              i;
              i = SimpleXML::XMLDocument::GetNode(v2, 0i64, i) )
        {
          Name = SimpleXML::XMLNode::GetName(i);
          if ( !(unsigned int)UFG::qStringCompare(Name, "EventType", -1)
            && (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
          {
            for ( j = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, i); j; j = SimpleXML::XMLDocument::GetNode(
                                                                                  v2,
                                                                                  0i64,
                                                                                  j) )
            {
              v7 = SimpleXML::XMLNode::GetName(j);
              if ( !(unsigned int)UFG::qStringCompare(v7, "Event", -1) )
                UFG::TiDo::LoadEventSymbols_::_4_::Local::AddNodeToRegistry(j);
            }
          }
          v8 = SimpleXML::XMLNode::GetName(i);
          if ( !(unsigned int)UFG::qStringCompare(v8, "DialogueType", -1)
            && (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
          {
            for ( k = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, i); k; k = SimpleXML::XMLDocument::GetNode(
                                                                                  v2,
                                                                                  0i64,
                                                                                  k) )
            {
              v10 = SimpleXML::XMLNode::GetName(k);
              if ( !(unsigned int)UFG::qStringCompare(v10, "Dialogue", -1) )
                UFG::TiDo::LoadEventSymbols_::_4_::Local::AddNodeToRegistry(k);
            }
          }
          v11 = SimpleXML::XMLNode::GetName(i);
          if ( !(unsigned int)UFG::qStringCompare(v11, "ArgumentType", -1)
            && (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
          {
            for ( m = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, i); m; m = SimpleXML::XMLDocument::GetNode(
                                                                                  v2,
                                                                                  0i64,
                                                                                  m) )
            {
              Node = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, m);
              SimpleXML::XMLNode::GetChildCount(m);
              for ( ; Node; Node = SimpleXML::XMLDocument::GetNode(v2, 0i64, Node) )
              {
                v14 = SimpleXML::XMLNode::GetName(Node);
                if ( !(unsigned int)UFG::qStringCompare(v14, "Argument", -1) )
                  UFG::TiDo::LoadEventSymbols_::_4_::Local::AddNodeToRegistry(Node);
              }
            }
          }
          v15 = SimpleXML::XMLNode::GetName(i);
          if ( !(unsigned int)UFG::qStringCompare(v15, "RTPCType", -1) && (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
          {
            for ( n = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, i); n; n = SimpleXML::XMLDocument::GetNode(
                                                                                  v2,
                                                                                  0i64,
                                                                                  n) )
            {
              v17 = SimpleXML::XMLNode::GetName(n);
              if ( !(unsigned int)UFG::qStringCompare(v17, "RTPC", -1) )
                UFG::TiDo::LoadEventSymbols_::_4_::Local::AddNodeToRegistry(n);
            }
          }
          v18 = SimpleXML::XMLNode::GetName(i);
          if ( !(unsigned int)UFG::qStringCompare(v18, "AuxBussType", -1)
            && (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
          {
            for ( ii = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, i);
                  ii;
                  ii = SimpleXML::XMLDocument::GetNode(v2, 0i64, ii) )
            {
              v20 = SimpleXML::XMLNode::GetName(ii);
              if ( !(unsigned int)UFG::qStringCompare(v20, "AuxBuss", -1) )
                UFG::TiDo::LoadEventSymbols_::_4_::Local::AddNodeToRegistry(ii);
            }
          }
        }
      }
      SimpleXML::XMLDocument::~XMLDocument(v2);
      operator delete[](v2);
    }
    UFG::SoundBankManager::LoadBankSymbols(1);
    UFG::TiDo::sm_eventSymbolsLoaded = 1;
    UFG::qString::~qString(&v21);
  }
}

// File Line: 1603
// RVA: 0x142A70
void __fastcall UFG::TiDo::LoadEventSymbols_::_4_::Local::AddNodeToRegistry(SimpleXML::XMLNode *node)
{
  unsigned int Attribute; // edi
  char *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString v5; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  Attribute = SimpleXML::XMLNode::GetAttribute(node, "id", 0);
  v3 = SimpleXML::XMLNode::GetAttribute(node, "name");
  UFG::qString::qString(&v5, v3);
  v4 = UFG::qString::ToLower(&v5, &result);
  UFG::qString::Set(&v5, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  _((AMD_HD3D *)Attribute);
  UFG::qString::~qString(&v5);
}

// File Line: 1849
// RVA: 0x14B630
unsigned int __fastcall UFG::TiDo::ResolveDialogueEvent(unsigned int eventId, unsigned int *args, unsigned int numArgs)
{
  return AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(eventId, args, numArgs, 0);
}

