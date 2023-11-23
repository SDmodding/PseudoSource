// File Line: 12
// RVA: 0x48D6E0
void __fastcall UFG::SceneSettings::SceneSettings(UFG::SceneSettings *this, const char *name)
{
  unsigned int mUID; // r8d
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF

  mUID = UFG::qSymbol::create_from_string(&result, name)->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->mVehicleTeleportRange = -1.0;
  UFG::qString::qString(&this->mName, name);
  *(_QWORD *)&this->mTeleportMarker.mUID = -1i64;
  this->mLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mLayerSetupOnStart.size = 0i64;
  this->mLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mLayerSetupOnEnd.size = 0i64;
  this->mAltLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mAltLayerSetupOnStart.size = 0i64;
  this->mAltLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mAltLayerSetupOnEnd.size = 0i64;
  this->mVendorSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mVendorSetupOnStart.size = 0i64;
  this->mVendorSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mVendorSetupOnEnd.size = 0i64;
  this->mDisguiseSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mDisguiseSetupOnStart.size = 0i64;
  this->mDisguiseSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mDisguiseSetupOnEnd.size = 0i64;
  this->mLoadingHintSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mLoadingHintSetupOnStart.size = 0i64;
  this->mLoadingHintSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mLoadingHintSetupOnEnd.size = 0i64;
  this->mLoadingScreenSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mLoadingScreenSetupOnStart.size = 0i64;
  this->mLoadingScreenSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mLoadingScreenSetupOnEnd.size = 0i64;
  UFG::SceneSettings::Reset(this);
}

// File Line: 17
// RVA: 0x491190
void __fastcall UFG::SceneSettings::~SceneSettings(UFG::SceneSettings *this)
{
  UFG::SceneSettings::LoadingScreenSetup *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::SceneSettings::LoadingScreenSetup *v4; // rcx
  unsigned int *v5; // rbx
  UFG::SceneSettings::LoadingHintSetup *v6; // rcx
  unsigned int *v7; // rbx
  UFG::SceneSettings::LoadingHintSetup *v8; // rcx
  unsigned int *v9; // rbx
  UFG::SceneSettings::DisguiseSetup *v10; // rcx
  bool *p_mEnableWardrobe; // rbx
  UFG::SceneSettings::DisguiseSetup *v12; // rcx
  bool *v13; // rbx
  UFG::SceneSettings::VendorSetup *v14; // rcx
  bool *p_mEnable; // rbx
  UFG::SceneSettings::VendorSetup *v16; // rcx
  bool *v17; // rbx
  UFG::SceneSettings::AltLayerSetup *v18; // rcx
  bool *p_mFlush; // rbx
  UFG::SceneSettings::AltLayerSetup *v20; // rcx
  bool *v21; // rbx
  UFG::SceneSettings::LayerSetup *v22; // rcx
  bool *p_mGeoSettingsPresent; // rbx
  UFG::SceneSettings::LayerSetup *v24; // rcx
  bool *v25; // rbx

  p = this->mLoadingScreenSetupOnEnd.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mLoadingScreen.mStringHash32;
    `eh vector destructor iterator(
      p,
      0x30ui64,
      p[-1].mLoadingScreen.mStringHash32,
      (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
    operator delete[](p_mStringHash32);
  }
  this->mLoadingScreenSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mLoadingScreenSetupOnEnd.size = 0i64;
  v4 = this->mLoadingScreenSetupOnStart.p;
  if ( v4 )
  {
    v5 = &v4[-1].mLoadingScreen.mStringHash32;
    `eh vector destructor iterator(
      v4,
      0x30ui64,
      v4[-1].mLoadingScreen.mStringHash32,
      (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
    operator delete[](v5);
  }
  this->mLoadingScreenSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mLoadingScreenSetupOnStart.size = 0i64;
  v6 = this->mLoadingHintSetupOnEnd.p;
  if ( v6 )
  {
    v7 = &v6[-1].mHintString.mStringHash32;
    `eh vector destructor iterator(
      v6,
      0x30ui64,
      v6[-1].mHintString.mStringHash32,
      (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
    operator delete[](v7);
  }
  this->mLoadingHintSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mLoadingHintSetupOnEnd.size = 0i64;
  v8 = this->mLoadingHintSetupOnStart.p;
  if ( v8 )
  {
    v9 = &v8[-1].mHintString.mStringHash32;
    `eh vector destructor iterator(
      v8,
      0x30ui64,
      v8[-1].mHintString.mStringHash32,
      (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
    operator delete[](v9);
  }
  this->mLoadingHintSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mLoadingHintSetupOnStart.size = 0i64;
  v10 = this->mDisguiseSetupOnEnd.p;
  if ( v10 )
  {
    p_mEnableWardrobe = &v10[-1].mEnableWardrobe;
    `eh vector destructor iterator(v10, 8ui64, *(_DWORD *)&v10[-1].mEnableWardrobe, (void (__fastcall *)(void *))_);
    operator delete[](p_mEnableWardrobe);
  }
  this->mDisguiseSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mDisguiseSetupOnEnd.size = 0i64;
  v12 = this->mDisguiseSetupOnStart.p;
  if ( v12 )
  {
    v13 = &v12[-1].mEnableWardrobe;
    `eh vector destructor iterator(v12, 8ui64, *(_DWORD *)&v12[-1].mEnableWardrobe, (void (__fastcall *)(void *))_);
    operator delete[](v13);
  }
  this->mDisguiseSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mDisguiseSetupOnStart.size = 0i64;
  v14 = this->mVendorSetupOnEnd.p;
  if ( v14 )
  {
    p_mEnable = &v14[-1].mEnable;
    `eh vector destructor iterator(v14, 8ui64, *(_DWORD *)&v14[-1].mEnable, (void (__fastcall *)(void *))_);
    operator delete[](p_mEnable);
  }
  this->mVendorSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mVendorSetupOnEnd.size = 0i64;
  v16 = this->mVendorSetupOnStart.p;
  if ( v16 )
  {
    v17 = &v16[-1].mEnable;
    `eh vector destructor iterator(v16, 8ui64, *(_DWORD *)&v16[-1].mEnable, (void (__fastcall *)(void *))_);
    operator delete[](v17);
  }
  this->mVendorSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mVendorSetupOnStart.size = 0i64;
  v18 = this->mAltLayerSetupOnEnd.p;
  if ( v18 )
  {
    p_mFlush = &v18[-1].mFlush;
    `eh vector destructor iterator(
      v18,
      0x30ui64,
      *(_DWORD *)&v18[-1].mFlush,
      (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
    operator delete[](p_mFlush);
  }
  this->mAltLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mAltLayerSetupOnEnd.size = 0i64;
  v20 = this->mAltLayerSetupOnStart.p;
  if ( v20 )
  {
    v21 = &v20[-1].mFlush;
    `eh vector destructor iterator(
      v20,
      0x30ui64,
      *(_DWORD *)&v20[-1].mFlush,
      (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
    operator delete[](v21);
  }
  this->mAltLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mAltLayerSetupOnStart.size = 0i64;
  v22 = this->mLayerSetupOnEnd.p;
  if ( v22 )
  {
    p_mGeoSettingsPresent = &v22[-1].mGeoSettingsPresent;
    `eh vector destructor iterator(v22, 8ui64, *(_DWORD *)&v22[-1].mGeoSettingsPresent, (void (__fastcall *)(void *))_);
    operator delete[](p_mGeoSettingsPresent);
  }
  this->mLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&this->mLayerSetupOnEnd.size = 0i64;
  v24 = this->mLayerSetupOnStart.p;
  if ( v24 )
  {
    v25 = &v24[-1].mGeoSettingsPresent;
    `eh vector destructor iterator(v24, 8ui64, *(_DWORD *)&v24[-1].mGeoSettingsPresent, (void (__fastcall *)(void *))_);
    operator delete[](v25);
  }
  this->mLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&this->mLayerSetupOnStart.size = 0i64;
  UFG::qString::~qString(&this->mName);
}

// File Line: 21
// RVA: 0x4B69D0
void __fastcall UFG::SceneSettings::Reset(UFG::SceneSettings *this)
{
  this->mWeatherOverrideIntensity = -1.0;
  this->mWeatherOverrideWetness = -1.0;
  this->mWeatherOverrideLock = 0;
  this->mTimeOverrideInSeconds = -1.0;
  *(_DWORD *)&this->mTimeOverrideLockSet = 0;
  *(_DWORD *)&this->mShowCurtains = 257;
  *(_DWORD *)&this->mEnableAmbientPedsOnStart = 257;
  *(_WORD *)&this->mEnableTrafficOnStart = 257;
  this->mResetEnvironmentOverride = 0;
  UFG::qSymbol::set_null(&this->mTeleportMarker);
  *(_WORD *)&this->mVehicleDestroy = 0;
  this->mTeleportPositionInternal.x = -1.0;
  this->mTeleportPositionInternal.y = -1.0;
  this->mTeleportPositionInternal.z = -1.0;
}

// File Line: 68
// RVA: 0x492900
void __fastcall UFG::SceneSettings::AddAltLayerSetupOnStart(
        UFG::SceneSettings *this,
        const char *layerName,
        bool activate,
        bool flush)
{
  __int64 size; // rsi
  unsigned int v9; // ebx
  unsigned int capacity; // edx
  unsigned int v11; // edx
  UFG::SceneSettings::AltLayerSetup *v12; // rbx
  UFG::qString v13; // [rsp+38h] [rbp-40h] BYREF
  __int16 v14; // [rsp+60h] [rbp-18h]

  UFG::qString::qString(&v13);
  v14 = 0;
  UFG::qString::Set(&v13, layerName);
  LOBYTE(v14) = flush;
  HIBYTE(v14) = activate;
  size = this->mAltLayerSetupOnStart.size;
  v9 = size + 1;
  capacity = this->mAltLayerSetupOnStart.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v11 = 2 * capacity;
    else
      v11 = 1;
    for ( ; v11 < v9; v11 *= 2 )
      ;
    if ( v11 - v9 > 0x10000 )
      v11 = size + 65537;
    UFG::qArray<UFG::SceneSettings::AltLayerSetup,0>::Reallocate(
      &this->mAltLayerSetupOnStart,
      v11,
      "SceneSettings::AddAltLayerSetupOnStart");
  }
  this->mAltLayerSetupOnStart.size = v9;
  v12 = &this->mAltLayerSetupOnStart.p[size];
  UFG::qString::Set(&v12->mLayerName, v13.mData, v13.mLength, 0i64, 0);
  *(_WORD *)&v12->mFlush = v14;
  UFG::qString::~qString(&v13);
}

// File Line: 77
// RVA: 0x4927F0
void __fastcall UFG::SceneSettings::AddAltLayerSetupOnEnd(
        UFG::SceneSettings *this,
        const char *layerName,
        bool activate,
        bool flush)
{
  __int64 size; // rsi
  unsigned int v9; // ebx
  unsigned int capacity; // edx
  unsigned int v11; // edx
  UFG::SceneSettings::AltLayerSetup *v12; // rbx
  UFG::qString v13; // [rsp+38h] [rbp-40h] BYREF
  __int16 v14; // [rsp+60h] [rbp-18h]

  UFG::qString::qString(&v13);
  v14 = 0;
  UFG::qString::Set(&v13, layerName);
  LOBYTE(v14) = flush;
  HIBYTE(v14) = activate;
  size = this->mAltLayerSetupOnEnd.size;
  v9 = size + 1;
  capacity = this->mAltLayerSetupOnEnd.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v11 = 2 * capacity;
    else
      v11 = 1;
    for ( ; v11 < v9; v11 *= 2 )
      ;
    if ( v11 - v9 > 0x10000 )
      v11 = size + 65537;
    UFG::qArray<UFG::SceneSettings::AltLayerSetup,0>::Reallocate(
      &this->mAltLayerSetupOnEnd,
      v11,
      "SceneSettings::AddAltLayerSetupOnEnd");
  }
  this->mAltLayerSetupOnEnd.size = v9;
  v12 = &this->mAltLayerSetupOnEnd.p[size];
  UFG::qString::Set(&v12->mLayerName, v13.mData, v13.mLength, 0i64, 0);
  *(_WORD *)&v12->mFlush = v14;
  UFG::qString::~qString(&v13);
}

// File Line: 112
// RVA: 0x492D00
void __fastcall UFG::SceneSettings::AddDisguiseSetupOnEnd(
        UFG::SceneSettings *this,
        bool enableWardrobe,
        bool enableStores)
{
  UFG::qArray<UFG::SceneSettings::DisguiseSetup,0> *p_mDisguiseSetupOnEnd; // rdi
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::SceneSettings::DisguiseSetup *p; // rax

  p_mDisguiseSetupOnEnd = &this->mDisguiseSetupOnEnd;
  size = this->mDisguiseSetupOnEnd.size;
  capacity = this->mDisguiseSetupOnEnd.capacity;
  v8 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v8; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v8 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::SceneSettings::DisguiseSetup,0>::Reallocate(
      p_mDisguiseSetupOnEnd,
      v9,
      "SceneSettings::AddDisguiseSetupOnEnd");
  }
  p = p_mDisguiseSetupOnEnd->p;
  p_mDisguiseSetupOnEnd->size = v8;
  p[size].mDisguise.mUID = -1;
  p[size].mEnableVendors = enableStores;
  p[size].mEnableWardrobe = enableWardrobe;
  p[size].mKeepOutfit = 0;
}

// File Line: 120
// RVA: 0x493280
void __fastcall UFG::SceneSettings::AddLoadingHintSetupOnStart(
        UFG::SceneSettings *this,
        const char *hintString,
        unsigned int priority)
{
  __int64 size; // rdi
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  UFG::SceneSettings::LoadingHintSetup *v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h] BYREF

  UFG::qString::qString(&v12);
  v11 = priority;
  UFG::qString::Set(&v12, hintString);
  size = this->mLoadingHintSetupOnStart.size;
  v7 = size + 1;
  capacity = this->mLoadingHintSetupOnStart.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      (UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0> *)&this->mLoadingHintSetupOnStart,
      v9,
      "SceneSettings::AddLoadingHintSetupOnStart");
  }
  this->mLoadingHintSetupOnStart.size = v7;
  v10 = &this->mLoadingHintSetupOnStart.p[size];
  v10->mPriority = v11;
  UFG::qString::Set(&v10->mHintString, v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

// File Line: 128
// RVA: 0x493190
void __fastcall UFG::SceneSettings::AddLoadingHintSetupOnEnd(
        UFG::SceneSettings *this,
        const char *hintString,
        unsigned int priority)
{
  __int64 size; // rdi
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  UFG::SceneSettings::LoadingHintSetup *v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h] BYREF

  UFG::qString::qString(&v12);
  v11 = priority;
  UFG::qString::Set(&v12, hintString);
  size = this->mLoadingHintSetupOnEnd.size;
  v7 = size + 1;
  capacity = this->mLoadingHintSetupOnEnd.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      (UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0> *)&this->mLoadingHintSetupOnEnd,
      v9,
      "SceneSettings::AddLoadingHintSetupOnEnd");
  }
  this->mLoadingHintSetupOnEnd.size = v7;
  v10 = &this->mLoadingHintSetupOnEnd.p[size];
  v10->mPriority = v11;
  UFG::qString::Set(&v10->mHintString, v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

// File Line: 136
// RVA: 0x493460
void __fastcall UFG::SceneSettings::AddLoadingScreenSetupOnStart(
        UFG::SceneSettings *this,
        const char *loadScreen,
        unsigned int priority)
{
  __int64 size; // rdi
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  UFG::SceneSettings::LoadingScreenSetup *v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h] BYREF

  UFG::qString::qString(&v12);
  v11 = priority;
  UFG::qString::Set(&v12, loadScreen);
  size = this->mLoadingScreenSetupOnStart.size;
  v7 = size + 1;
  capacity = this->mLoadingScreenSetupOnStart.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      &this->mLoadingScreenSetupOnStart,
      v9,
      "SceneSettings::AddLoadingScreenSetupOnStart");
  }
  this->mLoadingScreenSetupOnStart.size = v7;
  v10 = &this->mLoadingScreenSetupOnStart.p[size];
  v10->mPriority = v11;
  UFG::qString::Set(&v10->mLoadingScreen, v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

// File Line: 144
// RVA: 0x493370
void __fastcall UFG::SceneSettings::AddLoadingScreenSetupOnEnd(
        UFG::SceneSettings *this,
        const char *loadScreen,
        unsigned int priority)
{
  __int64 size; // rdi
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  UFG::SceneSettings::LoadingScreenSetup *v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h] BYREF

  UFG::qString::qString(&v12);
  v11 = priority;
  UFG::qString::Set(&v12, loadScreen);
  size = this->mLoadingScreenSetupOnEnd.size;
  v7 = size + 1;
  capacity = this->mLoadingScreenSetupOnEnd.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = size + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      &this->mLoadingScreenSetupOnEnd,
      v9,
      "SceneSettings::AddLoadingScreenSetupOnEnd");
  }
  this->mLoadingScreenSetupOnEnd.size = v7;
  v10 = &this->mLoadingScreenSetupOnEnd.p[size];
  v10->mPriority = v11;
  UFG::qString::Set(&v10->mLoadingScreen, v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

