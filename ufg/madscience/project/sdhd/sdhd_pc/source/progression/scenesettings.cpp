// File Line: 12
// RVA: 0x48D6E0
void __fastcall UFG::SceneSettings::SceneSettings(UFG::SceneSettings *this, const char *name)
{
  const char *v2; // rbx
  UFG::SceneSettings *v3; // rdi
  unsigned int v4; // er8
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  v2 = name;
  v3 = this;
  v4 = UFG::qSymbol::create_from_string(&result, name)->mUID;
  v3->mNode.mParent = 0i64;
  v3->mNode.mChild[0] = 0i64;
  v3->mNode.mChild[1] = 0i64;
  v3->mNode.mUID = v4;
  v3->mVehicleTeleportRange = -1.0;
  UFG::qString::qString(&v3->mName, v2);
  *(_QWORD *)&v3->mTeleportMarker.mUID = -1i64;
  v3->mLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&v3->mLayerSetupOnStart.size = 0i64;
  v3->mLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&v3->mLayerSetupOnEnd.size = 0i64;
  v3->mAltLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&v3->mAltLayerSetupOnStart.size = 0i64;
  v3->mAltLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&v3->mAltLayerSetupOnEnd.size = 0i64;
  v3->mVendorSetupOnStart.p = 0i64;
  *(_QWORD *)&v3->mVendorSetupOnStart.size = 0i64;
  v3->mVendorSetupOnEnd.p = 0i64;
  *(_QWORD *)&v3->mVendorSetupOnEnd.size = 0i64;
  v3->mDisguiseSetupOnStart.p = 0i64;
  *(_QWORD *)&v3->mDisguiseSetupOnStart.size = 0i64;
  v3->mDisguiseSetupOnEnd.p = 0i64;
  *(_QWORD *)&v3->mDisguiseSetupOnEnd.size = 0i64;
  v3->mLoadingHintSetupOnStart.p = 0i64;
  *(_QWORD *)&v3->mLoadingHintSetupOnStart.size = 0i64;
  v3->mLoadingHintSetupOnEnd.p = 0i64;
  *(_QWORD *)&v3->mLoadingHintSetupOnEnd.size = 0i64;
  v3->mLoadingScreenSetupOnStart.p = 0i64;
  *(_QWORD *)&v3->mLoadingScreenSetupOnStart.size = 0i64;
  v3->mLoadingScreenSetupOnEnd.p = 0i64;
  *(_QWORD *)&v3->mLoadingScreenSetupOnEnd.size = 0i64;
  UFG::SceneSettings::Reset(v3);
}

// File Line: 17
// RVA: 0x491190
void __fastcall UFG::SceneSettings::~SceneSettings(UFG::SceneSettings *this)
{
  UFG::SceneSettings *v1; // rdi
  UFG::SceneSettings::LoadingScreenSetup *v2; // rcx
  unsigned int *v3; // rbx
  UFG::SceneSettings::LoadingScreenSetup *v4; // rcx
  unsigned int *v5; // rbx
  UFG::SceneSettings::LoadingHintSetup *v6; // rcx
  unsigned int *v7; // rbx
  UFG::SceneSettings::LoadingHintSetup *v8; // rcx
  unsigned int *v9; // rbx
  UFG::SceneSettings::DisguiseSetup *v10; // rcx
  bool *v11; // rbx
  UFG::SceneSettings::DisguiseSetup *v12; // rcx
  bool *v13; // rbx
  UFG::SceneSettings::VendorSetup *v14; // rcx
  bool *v15; // rbx
  UFG::SceneSettings::VendorSetup *v16; // rcx
  bool *v17; // rbx
  UFG::SceneSettings::AltLayerSetup *v18; // rcx
  bool *v19; // rbx
  UFG::SceneSettings::AltLayerSetup *v20; // rcx
  bool *v21; // rbx
  UFG::SceneSettings::LayerSetup *v22; // rcx
  bool *v23; // rbx
  UFG::SceneSettings::LayerSetup *v24; // rcx
  bool *v25; // rbx

  v1 = this;
  v2 = this->mLoadingScreenSetupOnEnd.p;
  if ( v2 )
  {
    v3 = &v2[-1].mLoadingScreen.mStringHash32;
    `eh vector destructor iterator(
      v2,
      0x30ui64,
      v2[-1].mLoadingScreen.mStringHash32,
      (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
    operator delete[](v3);
  }
  v1->mLoadingScreenSetupOnEnd.p = 0i64;
  *(_QWORD *)&v1->mLoadingScreenSetupOnEnd.size = 0i64;
  v4 = v1->mLoadingScreenSetupOnStart.p;
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
  v1->mLoadingScreenSetupOnStart.p = 0i64;
  *(_QWORD *)&v1->mLoadingScreenSetupOnStart.size = 0i64;
  v6 = v1->mLoadingHintSetupOnEnd.p;
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
  v1->mLoadingHintSetupOnEnd.p = 0i64;
  *(_QWORD *)&v1->mLoadingHintSetupOnEnd.size = 0i64;
  v8 = v1->mLoadingHintSetupOnStart.p;
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
  v1->mLoadingHintSetupOnStart.p = 0i64;
  *(_QWORD *)&v1->mLoadingHintSetupOnStart.size = 0i64;
  v10 = v1->mDisguiseSetupOnEnd.p;
  if ( v10 )
  {
    v11 = &v10[-1].mEnableWardrobe;
    `eh vector destructor iterator(v10, 8ui64, *(_DWORD *)&v10[-1].mEnableWardrobe, (void (__fastcall *)(void *))_);
    operator delete[](v11);
  }
  v1->mDisguiseSetupOnEnd.p = 0i64;
  *(_QWORD *)&v1->mDisguiseSetupOnEnd.size = 0i64;
  v12 = v1->mDisguiseSetupOnStart.p;
  if ( v12 )
  {
    v13 = &v12[-1].mEnableWardrobe;
    `eh vector destructor iterator(v12, 8ui64, *(_DWORD *)&v12[-1].mEnableWardrobe, (void (__fastcall *)(void *))_);
    operator delete[](v13);
  }
  v1->mDisguiseSetupOnStart.p = 0i64;
  *(_QWORD *)&v1->mDisguiseSetupOnStart.size = 0i64;
  v14 = v1->mVendorSetupOnEnd.p;
  if ( v14 )
  {
    v15 = &v14[-1].mEnable;
    `eh vector destructor iterator(v14, 8ui64, *(_DWORD *)&v14[-1].mEnable, (void (__fastcall *)(void *))_);
    operator delete[](v15);
  }
  v1->mVendorSetupOnEnd.p = 0i64;
  *(_QWORD *)&v1->mVendorSetupOnEnd.size = 0i64;
  v16 = v1->mVendorSetupOnStart.p;
  if ( v16 )
  {
    v17 = &v16[-1].mEnable;
    `eh vector destructor iterator(v16, 8ui64, *(_DWORD *)&v16[-1].mEnable, (void (__fastcall *)(void *))_);
    operator delete[](v17);
  }
  v1->mVendorSetupOnStart.p = 0i64;
  *(_QWORD *)&v1->mVendorSetupOnStart.size = 0i64;
  v18 = v1->mAltLayerSetupOnEnd.p;
  if ( v18 )
  {
    v19 = &v18[-1].mFlush;
    `eh vector destructor iterator(
      v18,
      0x30ui64,
      *(_DWORD *)&v18[-1].mFlush,
      (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
    operator delete[](v19);
  }
  v1->mAltLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&v1->mAltLayerSetupOnEnd.size = 0i64;
  v20 = v1->mAltLayerSetupOnStart.p;
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
  v1->mAltLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&v1->mAltLayerSetupOnStart.size = 0i64;
  v22 = v1->mLayerSetupOnEnd.p;
  if ( v22 )
  {
    v23 = &v22[-1].mGeoSettingsPresent;
    `eh vector destructor iterator(v22, 8ui64, *(_DWORD *)&v22[-1].mGeoSettingsPresent, (void (__fastcall *)(void *))_);
    operator delete[](v23);
  }
  v1->mLayerSetupOnEnd.p = 0i64;
  *(_QWORD *)&v1->mLayerSetupOnEnd.size = 0i64;
  v24 = v1->mLayerSetupOnStart.p;
  if ( v24 )
  {
    v25 = &v24[-1].mGeoSettingsPresent;
    `eh vector destructor iterator(v24, 8ui64, *(_DWORD *)&v24[-1].mGeoSettingsPresent, (void (__fastcall *)(void *))_);
    operator delete[](v25);
  }
  v1->mLayerSetupOnStart.p = 0i64;
  *(_QWORD *)&v1->mLayerSetupOnStart.size = 0i64;
  UFG::qString::~qString(&v1->mName);
}

// File Line: 21
// RVA: 0x4B69D0
void __fastcall UFG::SceneSettings::Reset(UFG::SceneSettings *this)
{
  UFG::SceneSettings *v1; // rbx

  v1 = this;
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
  *(_WORD *)&v1->mVehicleDestroy = 0;
  v1->mTeleportPositionInternal.x = -1.0;
  v1->mTeleportPositionInternal.y = -1.0;
  v1->mTeleportPositionInternal.z = -1.0;
}

// File Line: 68
// RVA: 0x492900
void __fastcall UFG::SceneSettings::AddAltLayerSetupOnStart(UFG::SceneSettings *this, const char *layerName, bool activate, bool flush)
{
  bool v4; // si
  bool v5; // bp
  const char *v6; // rbx
  UFG::SceneSettings *v7; // rdi
  __int64 v8; // rsi
  unsigned int v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // edx
  signed __int64 v12; // rbx
  UFG::qString v13; // [rsp+38h] [rbp-40h]
  __int16 v14; // [rsp+60h] [rbp-18h]

  v4 = flush;
  v5 = activate;
  v6 = layerName;
  v7 = this;
  UFG::qString::qString(&v13);
  v14 = 0;
  UFG::qString::Set(&v13, v6);
  LOBYTE(v14) = v4;
  HIBYTE(v14) = v5;
  v8 = v7->mAltLayerSetupOnStart.size;
  v9 = v8 + 1;
  v10 = v7->mAltLayerSetupOnStart.capacity;
  if ( (signed int)v8 + 1 > v10 )
  {
    if ( v10 )
      v11 = 2 * v10;
    else
      v11 = 1;
    for ( ; v11 < v9; v11 *= 2 )
      ;
    if ( v11 - v9 > 0x10000 )
      v11 = v8 + 65537;
    UFG::qArray<UFG::SceneSettings::AltLayerSetup,0>::Reallocate(
      &v7->mAltLayerSetupOnStart,
      v11,
      "SceneSettings::AddAltLayerSetupOnStart");
  }
  v7->mAltLayerSetupOnStart.size = v9;
  v12 = (signed __int64)&v7->mAltLayerSetupOnStart.p[v8];
  UFG::qString::Set((UFG::qString *)v12, v13.mData, v13.mLength, 0i64, 0);
  *(_WORD *)(v12 + 40) = v14;
  UFG::qString::~qString(&v13);
}

// File Line: 77
// RVA: 0x4927F0
void __fastcall UFG::SceneSettings::AddAltLayerSetupOnEnd(UFG::SceneSettings *this, const char *layerName, bool activate, bool flush)
{
  bool v4; // si
  bool v5; // bp
  const char *v6; // rbx
  UFG::SceneSettings *v7; // rdi
  __int64 v8; // rsi
  unsigned int v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // edx
  signed __int64 v12; // rbx
  UFG::qString v13; // [rsp+38h] [rbp-40h]
  __int16 v14; // [rsp+60h] [rbp-18h]

  v4 = flush;
  v5 = activate;
  v6 = layerName;
  v7 = this;
  UFG::qString::qString(&v13);
  v14 = 0;
  UFG::qString::Set(&v13, v6);
  LOBYTE(v14) = v4;
  HIBYTE(v14) = v5;
  v8 = v7->mAltLayerSetupOnEnd.size;
  v9 = v8 + 1;
  v10 = v7->mAltLayerSetupOnEnd.capacity;
  if ( (signed int)v8 + 1 > v10 )
  {
    if ( v10 )
      v11 = 2 * v10;
    else
      v11 = 1;
    for ( ; v11 < v9; v11 *= 2 )
      ;
    if ( v11 - v9 > 0x10000 )
      v11 = v8 + 65537;
    UFG::qArray<UFG::SceneSettings::AltLayerSetup,0>::Reallocate(
      &v7->mAltLayerSetupOnEnd,
      v11,
      "SceneSettings::AddAltLayerSetupOnEnd");
  }
  v7->mAltLayerSetupOnEnd.size = v9;
  v12 = (signed __int64)&v7->mAltLayerSetupOnEnd.p[v8];
  UFG::qString::Set((UFG::qString *)v12, v13.mData, v13.mLength, 0i64, 0);
  *(_WORD *)(v12 + 40) = v14;
  UFG::qString::~qString(&v13);
}

// File Line: 112
// RVA: 0x492D00
void __fastcall UFG::SceneSettings::AddDisguiseSetupOnEnd(UFG::SceneSettings *this, bool enableWardrobe, bool enableStores)
{
  UFG::qArray<UFG::SceneSettings::DisguiseSetup,0> *v3; // rdi
  bool v4; // r14
  bool v5; // bp
  __int64 v6; // rsi
  unsigned int v7; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::SceneSettings::DisguiseSetup *v10; // rax

  v3 = &this->mDisguiseSetupOnEnd;
  v4 = enableWardrobe;
  v5 = enableStores;
  v6 = this->mDisguiseSetupOnEnd.size;
  v7 = this->mDisguiseSetupOnEnd.capacity;
  v8 = v6 + 1;
  if ( (signed int)v6 + 1 > v7 )
  {
    if ( v7 )
      v9 = 2 * v7;
    else
      v9 = 1;
    for ( ; v9 < v8; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v8 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::SceneSettings::DisguiseSetup,0>::Reallocate(v3, v9, "SceneSettings::AddDisguiseSetupOnEnd");
  }
  v10 = v3->p;
  v3->size = v8;
  v10[v6].mDisguise.mUID = -1;
  v10[v6].mEnableVendors = v5;
  v10[v6].mEnableWardrobe = v4;
  v10[v6].mKeepOutfit = 0;
}

// File Line: 120
// RVA: 0x493280
void __fastcall UFG::SceneSettings::AddLoadingHintSetupOnStart(UFG::SceneSettings *this, const char *hintString, unsigned int priority)
{
  unsigned int v3; // ebx
  const char *v4; // rdi
  UFG::SceneSettings *v5; // rsi
  __int64 v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  signed __int64 v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h]

  v3 = priority;
  v4 = hintString;
  v5 = this;
  UFG::qString::qString(&v12);
  v11 = v3;
  UFG::qString::Set(&v12, v4);
  v6 = v5->mLoadingHintSetupOnStart.size;
  v7 = v6 + 1;
  v8 = v5->mLoadingHintSetupOnStart.capacity;
  if ( (signed int)v6 + 1 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      (UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0> *)&v5->mLoadingHintSetupOnStart,
      v9,
      "SceneSettings::AddLoadingHintSetupOnStart");
  }
  v5->mLoadingHintSetupOnStart.size = v7;
  v10 = (signed __int64)&v5->mLoadingHintSetupOnStart.p[v6];
  *(_DWORD *)v10 = v11;
  UFG::qString::Set((UFG::qString *)(v10 + 8), v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

// File Line: 128
// RVA: 0x493190
void __fastcall UFG::SceneSettings::AddLoadingHintSetupOnEnd(UFG::SceneSettings *this, const char *hintString, unsigned int priority)
{
  unsigned int v3; // ebx
  const char *v4; // rdi
  UFG::SceneSettings *v5; // rsi
  __int64 v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  signed __int64 v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h]

  v3 = priority;
  v4 = hintString;
  v5 = this;
  UFG::qString::qString(&v12);
  v11 = v3;
  UFG::qString::Set(&v12, v4);
  v6 = v5->mLoadingHintSetupOnEnd.size;
  v7 = v6 + 1;
  v8 = v5->mLoadingHintSetupOnEnd.capacity;
  if ( (signed int)v6 + 1 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      (UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0> *)&v5->mLoadingHintSetupOnEnd,
      v9,
      "SceneSettings::AddLoadingHintSetupOnEnd");
  }
  v5->mLoadingHintSetupOnEnd.size = v7;
  v10 = (signed __int64)&v5->mLoadingHintSetupOnEnd.p[v6];
  *(_DWORD *)v10 = v11;
  UFG::qString::Set((UFG::qString *)(v10 + 8), v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

// File Line: 136
// RVA: 0x493460
void __fastcall UFG::SceneSettings::AddLoadingScreenSetupOnStart(UFG::SceneSettings *this, const char *loadScreen, unsigned int priority)
{
  unsigned int v3; // ebx
  const char *v4; // rdi
  UFG::SceneSettings *v5; // rsi
  __int64 v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  signed __int64 v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h]

  v3 = priority;
  v4 = loadScreen;
  v5 = this;
  UFG::qString::qString(&v12);
  v11 = v3;
  UFG::qString::Set(&v12, v4);
  v6 = v5->mLoadingScreenSetupOnStart.size;
  v7 = v6 + 1;
  v8 = v5->mLoadingScreenSetupOnStart.capacity;
  if ( (signed int)v6 + 1 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      &v5->mLoadingScreenSetupOnStart,
      v9,
      "SceneSettings::AddLoadingScreenSetupOnStart");
  }
  v5->mLoadingScreenSetupOnStart.size = v7;
  v10 = (signed __int64)&v5->mLoadingScreenSetupOnStart.p[v6];
  *(_DWORD *)v10 = v11;
  UFG::qString::Set((UFG::qString *)(v10 + 8), v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

// File Line: 144
// RVA: 0x493370
void __fastcall UFG::SceneSettings::AddLoadingScreenSetupOnEnd(UFG::SceneSettings *this, const char *loadScreen, unsigned int priority)
{
  unsigned int v3; // ebx
  const char *v4; // rdi
  UFG::SceneSettings *v5; // rsi
  __int64 v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  signed __int64 v10; // rcx
  unsigned int v11; // [rsp+38h] [rbp-40h]
  UFG::qString v12; // [rsp+40h] [rbp-38h]

  v3 = priority;
  v4 = loadScreen;
  v5 = this;
  UFG::qString::qString(&v12);
  v11 = v3;
  UFG::qString::Set(&v12, v4);
  v6 = v5->mLoadingScreenSetupOnEnd.size;
  v7 = v6 + 1;
  v8 = v5->mLoadingScreenSetupOnEnd.capacity;
  if ( (signed int)v6 + 1 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 - v7 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::SceneSettings::LoadingScreenSetup,0>::Reallocate(
      &v5->mLoadingScreenSetupOnEnd,
      v9,
      "SceneSettings::AddLoadingScreenSetupOnEnd");
  }
  v5->mLoadingScreenSetupOnEnd.size = v7;
  v10 = (signed __int64)&v5->mLoadingScreenSetupOnEnd.p[v6];
  *(_DWORD *)v10 = v11;
  UFG::qString::Set((UFG::qString *)(v10 + 8), v12.mData, v12.mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
}

