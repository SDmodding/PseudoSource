// File Line: 42
// RVA: 0x1456BA0
__int64 dynamic_initializer_for__Render::SkyMarshall::gSkyMarshall__()
{
  Render::SkyMarshall::SkyMarshall(&Render::SkyMarshall::gSkyMarshall);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::SkyMarshall::gSkyMarshall__);
}

// File Line: 55
// RVA: 0x1456C60
__int64 Render::_dynamic_initializer_for__sCeilingSettingsUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("cbShaderParams", 0xFFFFFFFF);
  sCeilingSettingsUID = result;
  return result;
}

// File Line: 60
// RVA: 0x1456BE0
__int64 Render::_dynamic_initializer_for__gSkydomeListPropertySet__()
{
  UFG::qSymbol::create_from_string(&gSkydomeListPropertySet, "default-skydomes-list");
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gSkydomeListPropertySet__);
}

// File Line: 115
// RVA: 0x1456BC0
__int64 Render::_dynamic_initializer_for__gCloudRenderLayer__()
{
  RenderQueueLayer::RenderQueueLayer(&Render::gCloudRenderLayer);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gCloudRenderLayer__);
}

// File Line: 120
// RVA: 0x657B0
void __fastcall Render::SkyMarshall::LoadSkydomeList(Render::SkyMarshall *this)
{
  UFG::qPropertySet *PropertySet; // rcx
  UFG::qArray<Render::SkyMarshall::SkydomeResource,0> *p_mSkydomeResources; // r15
  unsigned int *mSkydomeTypeIndex; // rbx
  UFG::qSymbol *p_name; // rax
  __int64 v6; // rdi
  UFG::qPropertyList *v7; // r13
  unsigned int v8; // r12d
  __int64 size; // rdi
  unsigned int v10; // ebx
  unsigned int capacity; // edx
  unsigned int v12; // edx
  __int64 v13; // rsi
  char *ValuePtr; // rax
  UFG::qPropertySet *v15; // rbx
  char *v16; // rax
  UFG::qPropertyList *v17; // r14
  unsigned int v18; // ebp
  char *v19; // rax
  UFG::qPropertySet *v20; // rdi
  char *v21; // rbx
  float *v22; // rax
  int *v23; // rcx
  int v24; // xmm6_4
  UFG::qSymbol v25; // [rsp+20h] [rbp-88h] BYREF
  int v26; // [rsp+24h] [rbp-84h] BYREF
  UFG::qSymbol *v27; // [rsp+28h] [rbp-80h]
  unsigned int *v28; // [rsp+30h] [rbp-78h]
  __int64 v29; // [rsp+38h] [rbp-70h]
  UFG::qPropertySet *v30; // [rsp+40h] [rbp-68h]
  __int64 v31; // [rsp+48h] [rbp-60h]
  UFG::qSymbol name; // [rsp+50h] [rbp-58h] BYREF
  UFG::qSymbol result; // [rsp+54h] [rbp-54h] BYREF
  UFG::qSymbol v34; // [rsp+58h] [rbp-50h] BYREF
  UFG::qSymbol v35; // [rsp+5Ch] [rbp-4Ch] BYREF
  UFG::qSymbol v36; // [rsp+B8h] [rbp+10h] BYREF
  UFG::qSymbol v37; // [rsp+C0h] [rbp+18h] BYREF
  UFG::qSymbol v38; // [rsp+C8h] [rbp+20h] BYREF

  v31 = -2i64;
  UFG::qSymbol::create_from_string(&name, "SunnyList");
  UFG::qSymbol::create_from_string(&result, "CloudyList");
  UFG::qSymbol::create_from_string(&v34, "StormyList");
  UFG::qSymbol::create_from_string(&v35, "CustomList");
  UFG::qSymbol::create_from_string(&v36, "TexturePack");
  UFG::qSymbol::create_from_string(&v37, "ModelList");
  UFG::qSymbol::create_from_string(&v38, "Model");
  UFG::qSymbol::create_from_string(&v25, "RotationRate");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&gSkydomeListPropertySet);
  v30 = PropertySet;
  if ( PropertySet )
  {
    p_mSkydomeResources = &this->mSkydomeResources;
    mSkydomeTypeIndex = this->mSkydomeTypeIndex;
    v28 = mSkydomeTypeIndex;
    p_name = &name;
    v27 = &name;
    v6 = 4i64;
    v29 = 4i64;
    do
    {
      v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, p_name, DEPTH_RECURSE);
      *mSkydomeTypeIndex = p_mSkydomeResources->size;
      v8 = 0;
      if ( v7->mNumElements )
      {
        do
        {
          size = p_mSkydomeResources->size;
          v10 = size + 1;
          capacity = p_mSkydomeResources->capacity;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v12 = 2 * capacity;
            else
              v12 = 1;
            for ( ; v12 < v10; v12 *= 2 )
              ;
            if ( v12 - v10 > 0x10000 )
              v12 = size + 65537;
            UFG::qArray<Render::SkyMarshall::SkydomeResource,0>::Reallocate(p_mSkydomeResources, v12, "qArray.Add");
          }
          p_mSkydomeResources->size = v10;
          v13 = (__int64)&p_mSkydomeResources->p[size];
          ValuePtr = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v8);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v15 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v15 = 0i64;
          *(_DWORD *)v13 = v15->mName.mUID;
          v16 = UFG::qPropertySet::Get<char const *>(v15, &v36, DEPTH_RECURSE);
          UFG::qString::Format((UFG::qString *)(v13 + 56), "Data\\Global\\%s.perm.bin", v16);
          v17 = UFG::qPropertySet::Get<UFG::qPropertyList>(v15, &v37, DEPTH_RECURSE);
          v18 = 0;
          if ( v17->mNumElements )
          {
            v26 = 0;
            do
            {
              v19 = UFG::qPropertyList::GetValuePtr(v17, 0x1Au, v18);
              if ( v19 && *(_QWORD *)v19 )
                v20 = (UFG::qPropertySet *)&v19[*(_QWORD *)v19];
              else
                v20 = 0i64;
              v21 = UFG::qPropertySet::Get<char const *>(v20, &v38, DEPTH_RECURSE);
              v22 = UFG::qPropertySet::Get<float>(v20, &v25, DEPTH_RECURSE);
              v23 = &v26;
              if ( v22 )
                v23 = (int *)v22;
              v24 = *v23;
              *(_DWORD *)(v13 + 8i64 * *(unsigned int *)(v13 + 52) + 4) = UFG::qStringHashUpper32(v21, 0xFFFFFFFF);
              *(_DWORD *)(v13 + 8i64 * (unsigned int)(*(_DWORD *)(v13 + 52))++ + 8) = v24;
              ++v18;
            }
            while ( v18 < v17->mNumElements );
          }
          ++v8;
        }
        while ( v8 < v7->mNumElements );
        mSkydomeTypeIndex = v28;
        v6 = v29;
      }
      p_name = ++v27;
      v28 = ++mSkydomeTypeIndex;
      v29 = --v6;
      PropertySet = v30;
    }
    while ( v6 );
  }
  `eh vector destructor iterator(&name, 4ui64, 4, (void (__fastcall *)(void *))_);
}

// File Line: 179
// RVA: 0x64CC0
void __fastcall Render::SkyMarshall::Init(Render::SkyMarshall *this)
{
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // eax
  Illusion::Material *v6; // rax
  Illusion::Material *v7; // rdi
  int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  UFG::TimeOfDayManager *Instance; // rax
  int v12; // eax
  UFG::qResourceWarehouse *v13; // rax

  v2 = Illusion::Factory::NewRasterState(Render::RasterStateStencilWriteSkybox, 0xB6AAAC80, 0i64, 0i64, 0i64);
  LODWORD(v2[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v2[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v2[1].mNode.mChild + 6) = 519;
  WORD2(v2[1].mNode.mChild[0]) = 511;
  v3 = v2;
  v4 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v4, v3);
  v5 = UFG::qStringHashUpper32("DR_SkyboxMaterial", 0xFFFFFFFF);
  v6 = Illusion::Factory::NewMaterial("DR_SkyboxMaterial", v5, 4u, 0i64, 0i64, 0i64);
  LOWORD(v6[1].mNode.mChild[0]) = 0;
  v7 = v6;
  HIDWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7[1].mTypeUID = -1957338719;
  LODWORD(v7[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 157670756;
  LODWORD(v7[1].mNode.mParent) = v8;
  *(_WORD *)&v7[1].mDebugName[12] = 0;
  *(_DWORD *)&v7[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v7[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v7[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v7[1].mDebugName[4] = v9;
  LOWORD(v7[1].mMaterialUser.mOffset) = 0;
  *(&v7[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v7[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v7[1].mNumParams = v10;
  v7[2].mNode.mUID = -1230328704;
  Instance = UFG::TimeOfDayManager::GetInstance();
  LODWORD(v3) = UFG::TimeOfDayManager::GetFogTexture(Instance)->mNode.mUID;
  LOWORD(v7[2].mTypeUID) = 0;
  HIDWORD(v7[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("texFogCube", 0xFFFFFFFF);
  *((_DWORD *)&v7[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v7[2].mDebugName[28] = (_DWORD)v3;
  LODWORD(v7[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v12;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v7);
  Render::SkyMarshall::LoadSkydomeList(this);
  Render::SkyMarshall::InitCloudResources(this);
}

// File Line: 256
// RVA: 0x64530
void __fastcall Render::SkyMarshall::SkyMarshall(Render::SkyMarshall *this)
{
  int v2; // ecx
  UFG::qstream_typed<Illusion::Buffer> *p_mIndexBuffer; // rax

  UFG::qResourceHandle::qResourceHandle(&this->mTexture);
  UFG::qResourceHandle::qResourceHandle(&this->mNoiseTexture);
  UFG::qResourceHandle::qResourceHandle(&this->mCloudMaterial);
  UFG::qResourceHandle::qResourceHandle(&this->mTestCloudMaterial);
  UFG::qResourceHandle::qResourceHandle(&this->mRimMaterial);
  UFG::qResourceHandle::qResourceHandle(&this->mWispModel);
  this->mEnableDome = 1;
  `eh vector constructor iterator(
    this->mCloudSceneHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Render::CloudSceneHandle::CloudSceneHandle);
  `eh vector constructor iterator(
    this->mWispIndexBuffer,
    0x58ui64,
    17,
    (void (__fastcall *)(void *))Render::SkyMarshall::WispIndexBuffer::WispIndexBuffer);
  v2 = 127;
  p_mIndexBuffer = &this->mTaskInstance[0].mIndexBuffer;
  do
  {
    p_mIndexBuffer[-2].m_Stream = 0i64;
    p_mIndexBuffer->m_Stream = 0i64;
    p_mIndexBuffer += 30;
    --v2;
  }
  while ( v2 >= 0 );
  this->mBoundaryCloudSceneID = 4;
  this->mSkydomeIndex = -1;
  this->mNextSkydomeIndex = 0;
  *(_QWORD *)&this->mLockSkydomeIndex = -1i64;
  *(_QWORD *)&this->mSkydomeState = 2i64;
  this->mSkydomeHandle.mPrev = &this->mSkydomeHandle;
  this->mSkydomeHandle.mNext = &this->mSkydomeHandle;
  this->mSkydomeHandle.mCallback = 0i64;
  this->mSkydomeHandle.mCallbackParam = 0i64;
  this->mSkydomeHandle.mImpl = 0i64;
  *(_DWORD *)&this->mSkydomeHandle.mFlags = 536870915;
  this->mSkydomeHandle._mTargetState.mValue = 1;
  this->mSkydomeResources.p = 0i64;
  *(_QWORD *)&this->mSkydomeResources.size = 0i64;
  UFG::qArray<Render::SkyMarshall::SkydomeResource,0>::Reallocate(
    &this->mSkydomeResources,
    0xAu,
    "qArray.Reallocate(Constructor)");
  this->mLockSkydome = 0;
  *(_QWORD *)&this->mFadeInDuration = 0i64;
  `eh vector constructor iterator(
    this->mSkydomeModel,
    0x20ui64,
    6,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  this->mNumSkydomeModels = 0;
  this->mDebugDomeIndex = -1;
  this->mDomeRotation = 0.0;
  this->mCeilingUV[1].x = 0.5;
  this->mCeilingUV[1].y = 0.5;
}

// File Line: 266
// RVA: 0x663E0
void __fastcall Render::SkyMarshall::SetSkydome(Render::SkyMarshall *this, UFG::qSymbol *skydomeName)
{
  unsigned int mUID; // r11d
  unsigned int size; // r10d
  int v4; // edx

  mUID = skydomeName->mUID;
  if ( skydomeName->mUID == -1 )
  {
    this->mLockSkydomeIndex = -1;
    this->mLockSkydome = 1;
    *(_QWORD *)&this->mFadeInDuration = 0i64;
  }
  else
  {
    size = this->mSkydomeResources.size;
    v4 = 0;
    if ( size )
    {
      while ( this->mSkydomeResources.p[v4].mNameUID.mUID != mUID )
      {
        if ( ++v4 >= size )
          return;
      }
      this->mLockSkydomeIndex = v4;
      this->mLockSkydome = 1;
      *(_QWORD *)&this->mFadeInDuration = 0i64;
    }
  }
}

// File Line: 292
// RVA: 0x67E30
void __fastcall Render::SkyMarshall::UpdateSkydomeTarget(Render::SkyMarshall *this, float weatherTarget)
{
  int v3; // eax

  v3 = UFG::qRandom(this->mSkydomeTypeIndex[1] - this->mSkydomeTypeIndex[0], &UFG::qDefaultSeed);
  this->mFadeInDuration = 30.0;
  this->mFadeOutDuration = 30.0;
  this->mNextSkydomeIndex = v3;
}

// File Line: 310
// RVA: 0x65C30
void __fastcall Render::SkyMarshall::ReleaseSkydome(Render::SkyMarshall *this)
{
  this->mLockSkydome = 0;
}

// File Line: 315
// RVA: 0x67380
void __fastcall Render::SkyMarshall::TexturePackLoaded(UFG::DataStreamer::Handle *handle, void *param)
{
  Render::SkyMarshall::gSkyMarshall.mSkydomeState = FADE_IN;
}

// File Line: 320
// RVA: 0x67450
void __fastcall Render::SkyMarshall::Update(Render::SkyMarshall *this, float deltaT)
{
  float v3; // xmm7_4
  int mLockSkydomeIndex; // eax
  Render::SkyMarshall::SkydomeState mSkydomeState; // ecx
  Render::SkyMarshall::SkydomeState v6; // ecx
  __int32 v7; // ecx
  __int32 v8; // ecx
  float mFadeInDuration; // xmm1_4
  __int64 mSkydomeIndex; // rax
  Render::SkyMarshall::SkydomeResource *v11; // rsi
  unsigned int i; // edi
  UFG::qResourceInventory *Inventory; // rax
  unsigned int model_uid; // r14d
  UFG::qResourceWarehouse *v15; // rax
  float mFadeOutDuration; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 y_low; // xmm2
  float v24; // xmm6_4
  unsigned int mBoundaryCloudSceneID; // eax
  __int64 v26; // rbx
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax
  float v29; // xmm6_4
  float v30; // xmm5_4
  unsigned int v31; // r14d
  UFG::qResourceData **p_mData; // r15
  UFG::qResourceData *v33; // rdi
  unsigned int mParent; // eax
  float v35; // xmm1_4
  __m128 v36; // xmm2
  float v37; // xmm11_4
  __int64 v38; // rsi
  float v39; // xmm1_4
  float v40; // xmm12_4
  float v41; // xmm13_4
  float v42; // xmm11_4
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  char *v44; // rcx
  char *v45; // rbx
  float v46; // xmm7_4
  float v47; // xmm8_4
  float v48; // xmm10_4
  float v49; // xmm9_4
  __m128 v50; // xmm2
  float v51; // xmm7_4
  float v52; // xmm5_4
  float v53; // xmm4_4
  float v54; // xmm3_4
  CullManager *v55; // rax
  CullInfo *v56; // rax
  unsigned int v57; // r8d
  CullInfo *j; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v59; // rax
  char *v60; // rcx
  __int64 v61; // rdx
  __int64 v62; // rax
  char *v63; // rax
  _DWORD *v64; // rcx
  CullManager *v65; // rax
  __m128 v66; // xmm2
  float v67; // xmm1_4
  int v68; // ecx
  __m128 v69; // xmm3
  float v70; // xmm1_4
  int v71; // ecx
  __m128 v72; // xmm2
  float v73; // xmm1_4
  int v74; // ecx
  __m128 v75; // xmm3
  float v76; // xmm1_4
  int v77; // ecx
  __m128 v78; // xmm2
  float v79; // xmm1_4
  int v80; // ecx
  __m128 v81; // xmm2
  float v82; // xmm1_4
  int v83; // ecx

  v3 = deltaT;
  if ( this->mLockSkydome )
    mLockSkydomeIndex = this->mLockSkydomeIndex;
  else
    mLockSkydomeIndex = this->mNextSkydomeIndex;
  if ( mLockSkydomeIndex != this->mSkydomeIndex )
  {
    mSkydomeState = this->mSkydomeState;
    if ( mSkydomeState <= LOADING )
    {
      if ( mSkydomeState >= LOADING )
        goto LABEL_9;
    }
    else
    {
      this->mSkydomeState = FADE_OUT;
    }
    this->mSkydomeIndex = mLockSkydomeIndex;
  }
LABEL_9:
  v6 = this->mSkydomeState;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 == 2 )
        {
          mFadeInDuration = this->mFadeInDuration;
          if ( mFadeInDuration <= 0.0 )
            this->mSkydomeOpacity = 1.0;
          else
            this->mSkydomeOpacity = (float)(v3 / mFadeInDuration) + this->mSkydomeOpacity;
          if ( this->mSkydomeOpacity >= 1.0 )
          {
            this->mSkydomeState = COMPLETE;
            this->mSkydomeOpacity = 1.0;
          }
        }
      }
      else
      {
        mSkydomeIndex = (unsigned int)this->mSkydomeIndex;
        if ( (int)mSkydomeIndex >= 0 && (int)mSkydomeIndex < (signed int)this->mSkydomeResources.size )
        {
          this->mSkydomeRotationIndex = mSkydomeIndex;
          v11 = &this->mSkydomeResources.p[mSkydomeIndex];
          UFG::DataStreamer::QueueStream(
            &this->mSkydomeHandle,
            v11->texture_pack_name.mData,
            DATA_CLOUDS,
            DEFAULT_PRIORITY,
            3u,
            Render::SkyMarshall::TexturePackLoaded,
            0i64);
          this->mSkydomeState = LOADING;
          for ( i = 0; i < v11->num_models; ++i )
          {
            Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            model_uid = v11->modelResource[i].model_uid;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v15 = UFG::qResourceWarehouse::Instance();
              Inventory = UFG::qResourceWarehouse::GetInventory(v15, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
            }
            UFG::qResourceHandle::Init(&this->mSkydomeModel[i], 0xA2ADCD77, model_uid, Inventory);
          }
          this->mNumSkydomeModels = v11->num_models;
        }
      }
    }
    else
    {
      UFG::DataStreamer::ReleaseStream(&this->mSkydomeHandle);
      this->mSkydomeState = UNLOADED;
    }
  }
  else
  {
    mFadeOutDuration = this->mFadeOutDuration;
    if ( mFadeOutDuration <= 0.0 )
      this->mSkydomeOpacity = 0.0;
    else
      this->mSkydomeOpacity = this->mSkydomeOpacity - (float)(deltaT / mFadeOutDuration);
    if ( this->mSkydomeOpacity <= 0.0 )
      *(_QWORD *)&this->mSkydomeState = 1i64;
  }
  Render::SkyMarshall::sCloudOpacity = Render::SkyMarshall::sCloudOpacity
                                     + (float)(Render::SkyMarshall::sCloudOpacityRate * v3);
  v17 = (float)(UFG::TimeOfDayManager::GetInstance()->m_WeatherState - 0.25) * 2.0;
  if ( v17 <= 0.0 )
  {
    v17 = 0.0;
  }
  else if ( v17 >= 1.0 )
  {
    v17 = *(float *)&FLOAT_1_0;
  }
  v18 = *(float *)&FLOAT_1_0;
  v19 = 1.0 - v17;
  v20 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight * 0.00027777778;
  if ( v20 >= (float)(Render::SkyMarshall::sCloudTimeFadeDuration + Render::SkyMarshall::sCloudStartTime) )
  {
    if ( v20 > (float)(Render::SkyMarshall::sCloudEndTime - Render::SkyMarshall::sCloudTimeFadeDuration) )
    {
      v21 = (float)(v20 - (float)(Render::SkyMarshall::sCloudEndTime - Render::SkyMarshall::sCloudTimeFadeDuration))
          / Render::SkyMarshall::sCloudTimeFadeDuration;
      if ( v21 <= 0.0 )
      {
        v21 = 0.0;
      }
      else if ( v21 >= 1.0 )
      {
        v21 = *(float *)&FLOAT_1_0;
      }
      v18 = 1.0 - v21;
    }
  }
  else
  {
    v18 = (float)(v20 - Render::SkyMarshall::sCloudStartTime) / Render::SkyMarshall::sCloudTimeFadeDuration;
    if ( v18 <= 0.0 )
    {
      v18 = 0.0;
    }
    else if ( v18 >= 1.0 )
    {
      v18 = *(float *)&FLOAT_1_0;
    }
  }
  if ( v19 >= v18 )
    v19 = v18;
  this->mEnviroScalar = v19;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                              + (float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                      * m_pTransformNodeComponent->mWorldTransform.v3.x))
                      + (float)(m_pTransformNodeComponent->mWorldTransform.v3.z
                              * m_pTransformNodeComponent->mWorldTransform.v3.z);
    LODWORD(v24) = _mm_sqrt_ps(y_low).m128_u32[0];
  }
  else
  {
    v24 = 0.0;
  }
  mBoundaryCloudSceneID = this->mBoundaryCloudSceneID;
  if ( mBoundaryCloudSceneID == 4 )
  {
    if ( v24 > 2100.0 )
      this->mBoundaryCloudSceneID = Render::SkyMarshall::LoadCloudScene(this, "HK_BOUNDARY_scene");
  }
  else if ( v24 < 2100.0 )
  {
    v26 = mBoundaryCloudSceneID;
    if ( this->mCloudSceneHandle[v26].mData )
    {
      v27 = `UFG::qGetResourceInventory<Render::CloudScene>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::CloudScene>::`2::result )
      {
        v28 = UFG::qResourceWarehouse::Instance();
        v27 = UFG::qResourceWarehouse::GetInventory(v28, 0x4438A32Fu);
        `UFG::qGetResourceInventory<Render::CloudScene>::`2::result = v27;
      }
      UFG::qResourceHandle::Close(&this->mCloudSceneHandle[v26], v27);
    }
    this->mBoundaryCloudSceneID = 4;
  }
  v29 = (float)(v24 - 2100.0) / Render::SkyMarshall::sBoundaryFadeDistance;
  if ( v29 <= 0.0 )
  {
    v29 = 0.0;
  }
  else if ( v29 >= 1.0 )
  {
    v29 = *(float *)&FLOAT_1_0;
  }
  v30 = FLOAT_0_016666668;
  this->mBoundaryCloudSceneOpacity = v29;
  v31 = 0;
  p_mData = &this->mCloudSceneHandle[0].mData;
  do
  {
    v33 = *p_mData;
    if ( *p_mData )
    {
      mParent = (unsigned int)v33[1].mNode.mParent;
      v35 = v3 + *((float *)&v33[1].mNode.mParent + 1);
      *((float *)&v33[1].mNode.mParent + 1) = v35;
      if ( mParent )
      {
        if ( Render::SkyMarshall::sEnableClouds && Render::SkyMarshall::sEnableSpeed )
        {
          v36 = (__m128)LODWORD(Render::SkyMarshall::sCloudWindX);
          v36.m128_f32[0] = (float)(v36.m128_f32[0] * v36.m128_f32[0])
                          + (float)(Render::SkyMarshall::sCloudWindY * Render::SkyMarshall::sCloudWindY);
          v37 = v36.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
          v38 = UFG::Metrics::msFrameCount & 3;
          v39 = (float)((float)(v35 * v30) * v30) * 1000.0;
          v40 = (float)((float)(v37 * Render::SkyMarshall::sCloudWindX) * v39) * Render::SkyMarshall::sCloudWindSpeed;
          v41 = (float)((float)(v37 * Render::SkyMarshall::sCloudWindY) * v39) * Render::SkyMarshall::sCloudWindSpeed;
          v42 = (float)((float)(v37 * 0.0) * v39) * Render::SkyMarshall::sCloudWindSpeed;
          if ( (unsigned int)v38 < mParent )
          {
            do
            {
              mPrev = v33[1].mResourceHandles.mNode.mPrev;
              if ( mPrev )
                v44 = (char *)&v33[1].mResourceHandles + (_QWORD)mPrev;
              else
                v44 = 0i64;
              v45 = &v44[192 * v38];
              if ( !*((_DWORD *)v45 + 46) )
              {
                v46 = v41 + *((float *)v45 + 25);
                v47 = v42 + *((float *)v45 + 26);
                v48 = fmodf(
                        (float)(v40 + *((float *)v45 + 24)) - *(float *)v33[1].mNode.mChild,
                        *((float *)&v33[1].mNode.mChild[1] + 1))
                    + *(float *)v33[1].mNode.mChild;
                v49 = fmodf(v46 - *((float *)v33[1].mNode.mChild + 1), *(float *)&v33[1].mNode.mUID)
                    + *((float *)v33[1].mNode.mChild + 1);
                v50 = 0i64;
                v50.m128_f32[0] = (float)1;
                v51 = fmodf(v47 - *(float *)&v33[1].mNode.mChild[1], *((float *)&v33[1].mNode.mUID + 1))
                    + *(float *)&v33[1].mNode.mChild[1];
                *((float *)v45 + 12) = v48;
                *((float *)v45 + 13) = v49;
                *((_DWORD *)v45 + 15) = 1065353216;
                *((float *)v45 + 14) = v51;
                v52 = 1.0 / *(float *)v45;
                v53 = 1.0 / *((float *)v45 + 5);
                v54 = 1.0 / *((float *)v45 + 10);
                *(__m128 *)(v45 + 108) = v50;
                *(__m128 *)(v45 + 124) = _mm_shuffle_ps(v50, v50, 81);
                *(__m128 *)(v45 + 140) = _mm_shuffle_ps(v50, v50, 69);
                *(__m128 *)(v45 + 156) = _mm_shuffle_ps(v50, v50, 21);
                *((float *)v45 + 27) = v52;
                *((float *)v45 + 32) = v53;
                *((float *)v45 + 37) = v54;
                *((float *)v45 + 39) = COERCE_FLOAT(LODWORD(v48) ^ _xmm[0]) * v52;
                *((_DWORD *)v45 + 42) = 1065353216;
                *((float *)v45 + 40) = COERCE_FLOAT(LODWORD(v49) ^ _xmm[0]) * v53;
                *((float *)v45 + 41) = COERCE_FLOAT(LODWORD(v51) ^ _xmm[0]) * v54;
              }
              v38 = (unsigned int)(v38 + 4);
            }
            while ( (unsigned int)v38 < LODWORD(v33[1].mNode.mParent) );
            v3 = deltaT;
          }
        }
        v55 = CullManager::Instance();
        v56 = CullManager::AllocFrameCullInfos(v55, (int)v33[1].mNode.mParent);
        v57 = 0;
        for ( j = v56; v57 < LODWORD(v33[1].mNode.mParent); *(float *)((char *)&j->mAABBMax[2] + v61) = (float)v64[28] )
        {
          v59 = v33[1].mResourceHandles.mNode.mPrev;
          if ( v59 )
            v60 = (char *)&v33[1].mResourceHandles + (_QWORD)v59;
          else
            v60 = 0i64;
          v61 = v57++;
          v62 = 3 * v61;
          v61 <<= 6;
          v63 = &v60[64 * v62];
          v64 = (_DWORD *)*((_QWORD *)v63 + 10);
          *(float **)((char *)&j->mpLocalWorld + v61) = (float *)v63;
          *(float *)((char *)&j->mAABBMax[3] + v61) = NAN;
          *(float *)((char *)j->mAABBMin + v61) = (float)v64[23];
          *(float *)((char *)&j->mAABBMin[1] + v61) = (float)v64[24];
          *(float *)((char *)&j->mAABBMin[2] + v61) = (float)v64[25];
          *(float *)((char *)j->mAABBMax + v61) = (float)v64[26];
          *(float *)((char *)&j->mAABBMax[1] + v61) = (float)v64[27];
        }
        v65 = CullManager::Instance();
        CullManager::AllocPrebuiltFrameCullInfos(v65, &this->mCullResults[v31], (int)v33[1].mNode.mParent, j, 0i64);
        v30 = FLOAT_0_016666668;
      }
    }
    ++v31;
    p_mData += 4;
  }
  while ( v31 < 4 );
  v66 = (__m128)LODWORD(Render::SkyMarshall::sCeilingSpeed[0]);
  v66.m128_f32[0] = (float)(Render::SkyMarshall::sCeilingSpeed[0] * v3) + this->mCeilingUV[0].x;
  v67 = v66.m128_f32[0];
  v68 = (int)v66.m128_f32[0];
  if ( (int)v66.m128_f32[0] != 0x80000000 && (float)v68 != v66.m128_f32[0] )
    v67 = (float)(v68 - (_mm_movemask_ps(_mm_unpacklo_ps(v66, v66)) & 1));
  this->mCeilingUV[0].x = v66.m128_f32[0] - v67;
  v69 = (__m128)(unsigned int)dword_142024054;
  v69.m128_f32[0] = (float)(*(float *)&dword_142024054 * v3) + this->mCeilingUV[0].y;
  v70 = v69.m128_f32[0];
  v71 = (int)v69.m128_f32[0];
  if ( (int)v69.m128_f32[0] != 0x80000000 && (float)v71 != v69.m128_f32[0] )
    v70 = (float)(v71 - (_mm_movemask_ps(_mm_unpacklo_ps(v69, v69)) & 1));
  this->mCeilingUV[0].y = v69.m128_f32[0] - v70;
  v72 = (__m128)(unsigned int)dword_142024058;
  v72.m128_f32[0] = (float)(*(float *)&dword_142024058 * v3) + this->mCeilingUV[1].x;
  v73 = v72.m128_f32[0];
  v74 = (int)v72.m128_f32[0];
  if ( (int)v72.m128_f32[0] != 0x80000000 && (float)v74 != v72.m128_f32[0] )
    v73 = (float)(v74 - (_mm_movemask_ps(_mm_unpacklo_ps(v72, v72)) & 1));
  this->mCeilingUV[1].x = v72.m128_f32[0] - v73;
  v75 = (__m128)(unsigned int)dword_14202405C;
  v75.m128_f32[0] = (float)(*(float *)&dword_14202405C * v3) + this->mCeilingUV[1].y;
  v76 = v75.m128_f32[0];
  v77 = (int)v75.m128_f32[0];
  if ( (int)v75.m128_f32[0] != 0x80000000 && (float)v77 != v75.m128_f32[0] )
    v76 = (float)(v77 - (_mm_movemask_ps(_mm_unpacklo_ps(v75, v75)) & 1));
  this->mCeilingUV[1].y = v75.m128_f32[0] - v76;
  v78 = (__m128)LODWORD(Render::SkyMarshall::sDomeSpeed);
  v78.m128_f32[0] = (float)(Render::SkyMarshall::sDomeSpeed * v3) + this->mDomeUVOffset;
  v79 = v78.m128_f32[0];
  v80 = (int)v78.m128_f32[0];
  if ( (int)v78.m128_f32[0] != 0x80000000 && (float)v80 != v78.m128_f32[0] )
    v79 = (float)(v80 - (_mm_movemask_ps(_mm_unpacklo_ps(v78, v78)) & 1));
  this->mDomeUVOffset = v78.m128_f32[0] - v79;
  v81 = (__m128)LODWORD(Render::SkyMarshall::sOuterDomeSpeed);
  v81.m128_f32[0] = (float)(Render::SkyMarshall::sOuterDomeSpeed * v3) + this->mOuterDomeUVOffset;
  v82 = v81.m128_f32[0];
  v83 = (int)v81.m128_f32[0];
  if ( (int)v81.m128_f32[0] != 0x80000000 && (float)v83 != v81.m128_f32[0] )
    v82 = (float)(v83 - (_mm_movemask_ps(_mm_unpacklo_ps(v81, v81)) & 1));
  this->mOuterDomeUVOffset = v81.m128_f32[0] - v82;
  this->mDomeRotation = (float)(v3 * 0.0049999999) + this->mDomeRotation;
} this->mDomeRotation = (float)(v3 * 0.0049999999) + this->mDomeRotation;
}

// File Line: 533
// RVA: 0x65C40
void __fastcall Render::SkyMarshall::RenderCloudDome(Render::SkyMarshall *this, Render::View *pView, float fidelity)
{
  UFG::qResourceData *mData; // rbx
  Illusion::StateValues *StateValues; // rax
  unsigned int i; // ebp
  char *v8; // rax
  char *v9; // rbx
  int v10; // xmm0_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  int v13; // xmm0_4
  unsigned int v14; // esi
  Illusion::StateValues *v15; // rax
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-88h] BYREF

  if ( (_S1_11 & 1) == 0 )
  {
    _S1_11 |= 1u;
    ceilingSettingsIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                               &Illusion::gStateSystem,
                                               sCeilingSettingsUID,
                                               sCeilingSettingsName,
                                               0);
  }
  if ( this->mEnableDome && (unsigned int)(this->mSkydomeState - 1) > 2 )
  {
    mData = this->mNoiseTexture.mData;
    StateValues = Render::View::GetStateValues(pView);
    StateValues->mSetValueMask.mFlags[0] |= 0x40000000000ui64;
    StateValues->mParamValues[42] = mData;
    for ( i = 0; i < this->mNumSkydomeModels; ++i )
    {
      dest = UFG::qMatrix44::msIdentity;
      UFG::qRotationMatrixZ(
        &dest,
        COERCE_FLOAT(COERCE_UNSIGNED_INT(
                       this->mSkydomeResources.p[this->mSkydomeRotationIndex].modelResource[i].rotation
                     * this->mDomeRotation) ^ _xmm[0]));
      dest.v3.x = pView->mViewWorld.v3.x;
      dest.v3.y = pView->mViewWorld.v3.y;
      dest.v3.z = pView->mViewWorld.v3.z;
      dest.v3.w = 1.0;
      v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      v9 = v8;
      *(float *)v8 = this->mDomeUVOffset;
      *((float *)v8 + 1) = Render::SkyMarshall::sRimIntensity;
      if ( Render::SkyMarshall::sDisplayHighlight )
        v10 = (int)FLOAT_1_0;
      else
        v10 = 0;
      *((_DWORD *)v8 + 4) = v10;
      if ( Render::SkyMarshall::sDisplayFog )
        v11 = (int)FLOAT_1_0;
      else
        v11 = 0;
      *((_DWORD *)v8 + 5) = v11;
      if ( Render::SkyMarshall::sDisplayDirect )
        v12 = (int)FLOAT_1_0;
      else
        v12 = 0;
      *((_DWORD *)v8 + 6) = v12;
      if ( Render::SkyMarshall::sDisplayHalo )
        v13 = (int)FLOAT_1_0;
      else
        v13 = 0;
      *((_DWORD *)v8 + 7) = v13;
      *((_DWORD *)v8 + 8) = LODWORD(this->mSkydomeOpacity);
      *((_DWORD *)v8 + 12) = LODWORD(this->mCeilingUV[0].x);
      *((_DWORD *)v8 + 13) = LODWORD(this->mCeilingUV[0].y);
      *((_DWORD *)v8 + 14) = LODWORD(this->mCeilingUV[1].x);
      *((_DWORD *)v8 + 15) = LODWORD(this->mCeilingUV[1].y);
      *((float *)v8 + 16) = Render::SkyMarshall::sFlowmapSpeed;
      *((float *)v8 + 17) = Render::SkyMarshall::sFlowmapIntensity;
      *((float *)v8 + 18) = Render::SkyMarshall::sFlowmapOffset;
      *((float *)v8 + 19) = Render::SkyMarshall::sFlowmapNoise;
      v14 = (__int16)ceilingSettingsIndex;
      v15 = Render::View::GetStateValues(pView);
      if ( v14 >= 0x40 )
        v15->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v14 - 64);
      else
        v15->mSetValueMask.mFlags[0] |= 1i64 << v14;
      v15->mParamValues[(__int16)v14] = v9;
      Render::View::Draw(pView, &this->mSkydomeModel[i], &dest, 0, 0i64);
    }
  }
}

// File Line: 582
// RVA: 0x65F40
void __fastcall Render::SkyMarshall::RenderFar(Render::SkyMarshall *this, Render::View *pView, float fidelity)
{
  unsigned int v4; // eax
  Illusion::Material *force_mat; // rbx
  unsigned int v6; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float w; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm10_4
  float v16; // xmm11_4
  float v17; // xmm12_4
  float v18; // xmm13_4
  float v19; // xmm14_4
  float v20; // xmm15_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float v22; // xmm2_4
  __m128 z_low; // xmm1
  float v24; // xmm3_4
  float v25; // xmm0_4
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-B8h] BYREF
  unsigned int v27; // [rsp+130h] [rbp+38h]

  v4 = _S2_2;
  if ( (_S2_2 & 1) == 0 )
  {
    _S2_2 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&hMatSky);
    atexit(Render::SkyMarshall::RenderFar_::_2_::_dynamic_atexit_destructor_for__hMatSky__);
    v4 = _S2_2;
  }
  force_mat = (Illusion::Material *)hMatSky.mData;
  if ( !hMatSky.mData )
  {
    v6 = UFG::qStringHashUpper32("DR_SkyboxMaterial", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
    {
      v8 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&hMatSky, 0xB4C26312, v6, Inventory);
    v4 = _S2_2;
    force_mat = (Illusion::Material *)hMatSky.mData;
  }
  x = UFG::qMatrix44::msIdentity.v0.x;
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  local_world = UFG::qMatrix44::msIdentity;
  v13 = UFG::qMatrix44::msIdentity.v1.x;
  v14 = UFG::qMatrix44::msIdentity.v1.y;
  v15 = UFG::qMatrix44::msIdentity.v1.z;
  v16 = UFG::qMatrix44::msIdentity.v1.w;
  v17 = UFG::qMatrix44::msIdentity.v2.x;
  v18 = UFG::qMatrix44::msIdentity.v2.y;
  v19 = UFG::qMatrix44::msIdentity.v2.z;
  v20 = UFG::qMatrix44::msIdentity.v2.w;
  if ( (v4 & 2) != 0 )
  {
    v25 = kSkyBoxScale;
  }
  else
  {
    _S2_2 = v4 | 2;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    v22 = mCurrentCamera->mCamera.mTransformation.v1.z;
    z_low = (__m128)LODWORD(mCurrentCamera->mCamera.mTransformation.v2.z);
    v24 = mCurrentCamera->mCamera.mTransformation.v1.w;
    if ( v22 == 0.0 || v22 == v24 )
      z_low = (__m128)v27;
    else
      z_low.m128_f32[0] = (float)(z_low.m128_f32[0] - mCurrentCamera->mCamera.mTransformation.v2.w) / (float)(v22 - v24);
    z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) * 0.33333334;
    LODWORD(v25) = _mm_sqrt_ps(z_low).m128_u32[0];
    kSkyBoxScale = v25;
    v20 = local_world.v2.w;
    v19 = local_world.v2.z;
    v18 = local_world.v2.y;
    v17 = local_world.v2.x;
    v16 = local_world.v1.w;
    v15 = local_world.v1.z;
    v14 = local_world.v1.y;
    v13 = local_world.v1.x;
    w = local_world.v0.w;
    z = local_world.v0.z;
    y = local_world.v0.y;
    x = local_world.v0.x;
  }
  local_world.v0.x = x * v25;
  local_world.v0.y = y * v25;
  local_world.v0.z = z * v25;
  local_world.v0.w = w * v25;
  local_world.v1.x = v13 * v25;
  local_world.v1.y = v14 * v25;
  local_world.v1.z = v15 * v25;
  local_world.v1.w = v16 * v25;
  local_world.v2.x = v17 * v25;
  local_world.v2.y = v18 * v25;
  local_world.v2.z = v19 * v25;
  local_world.v2.w = v20 * v25;
  local_world.v3.x = pView->mViewWorld.v3.x;
  local_world.v3.y = pView->mViewWorld.v3.y;
  local_world.v3.z = pView->mViewWorld.v3.z;
  LODWORD(local_world.v3.w) = (_DWORD)FLOAT_1_0;
  Render::View::Draw(pView, &gDeferredCube, &local_world, 0, force_mat);
}

// File Line: 604
// RVA: 0x67300
void __fastcall Render::SkyMarshall::SyncFlushDrawCloudTask(
        Render::SkyMarshall *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  SimpleTaskRenderResults *mMainMemCloudRenderResults; // r8
  SimpleTaskRenderResults *mNext; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v6; // rcx

  if ( Render::gCloudTask )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, Render::gCloudTask);
    mMainMemCloudRenderResults = Render::gCloudSortTaskParams->mMainMemCloudRenderResults;
    mNext = (SimpleTaskRenderResults *)mMainMemCloudRenderResults->mPendingQueues.mNode.mNext;
    if ( mNext != mMainMemCloudRenderResults )
    {
      mPrev = serialization_list->mNode.mPrev;
      v6 = mMainMemCloudRenderResults->mPendingQueues.mNode.mPrev;
      mPrev->mNext = &mNext->mPendingQueues.mNode;
      mNext->mPendingQueues.mNode.mPrev = mPrev;
      v6->mNext = &serialization_list->mNode;
      serialization_list->mNode.mPrev = v6;
      mMainMemCloudRenderResults->mPendingQueues.mNode.mPrev = &mMainMemCloudRenderResults->mPendingQueues.mNode;
      mMainMemCloudRenderResults->mPendingQueues.mNode.mNext = &mMainMemCloudRenderResults->mPendingQueues.mNode;
    }
    Render::gCloudRenderLayer.mSerializationList = serialization_list;
    RenderQueueLayer::SerializeRenderQueues(&Render::gCloudRenderLayer);
    Render::gCloudRenderLayer.mSerializationList = 0i64;
  }
}

// File Line: 642
// RVA: 0x656B0
__int64 __fastcall Render::SkyMarshall::LoadCloudScene(Render::SkyMarshall *this, const char *sceneName)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  UFG::qResourceData **p_mData; // r8
  unsigned int v7; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  __int64 v11; // rbx
  UFG::qResourceData *mData; // rax

  v4 = UFG::qStringHashUpper32(sceneName, 0xFFFFFFFF);
  v5 = 0;
  p_mData = &this->mCloudSceneHandle[0].mData;
  v7 = v4;
  while ( *p_mData )
  {
    if ( *((_DWORD *)p_mData + 2) == v4 )
    {
      UFG::qPrintf("Cloud scene %s already loaded.\n", sceneName);
      return 4i64;
    }
    ++v5;
    p_mData += 4;
    if ( v5 >= 4 )
    {
      UFG::qPrintf("Cannot load cloud scene %s; Exceeded max number of cloud scene slots.\n", sceneName);
      return 4i64;
    }
  }
  Inventory = `UFG::qGetResourceInventory<Render::CloudScene>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CloudScene>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0x4438A32Fu);
    `UFG::qGetResourceInventory<Render::CloudScene>::`2::result = Inventory;
  }
  v11 = v5;
  UFG::qResourceHandle::Init(&this->mCloudSceneHandle[v11], 0x4438A32Fu, v7, Inventory);
  mData = this->mCloudSceneHandle[v11].mData;
  if ( !mData )
  {
    UFG::qPrintf("Cannot load cloud scene %s; Check CloudScenePack.xml\n", sceneName);
    return 4i64;
  }
  HIDWORD(mData[1].mNode.mParent) = 0;
  return v5;
}

// File Line: 683
// RVA: 0x67390
void __fastcall Render::SkyMarshall::UnloadCloudScene(Render::SkyMarshall *this, const char *sceneName)
{
  int v4; // eax
  int v5; // ebx
  unsigned int *i; // r8
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax

  v4 = UFG::qStringHashUpper32(sceneName, 0xFFFFFFFF);
  v5 = 0;
  for ( i = &this->mCloudSceneHandle[0].mNameUID; !*((_QWORD *)i - 1) || *i != v4; i += 8 )
  {
    if ( (unsigned int)++v5 >= 4 )
    {
      UFG::qPrintf("Cannot unload cloud scene %s; not found.\n", sceneName);
      return;
    }
  }
  Inventory = `UFG::qGetResourceInventory<Render::CloudScene>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CloudScene>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x4438A32Fu);
    `UFG::qGetResourceInventory<Render::CloudScene>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mCloudSceneHandle[v5], Inventory);
}

// File Line: 713
// RVA: 0x64C20
CloudSortTaskParamIndices *__fastcall Render::GetCloudSortTaskParamIndices()
{
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned __int16 Param; // ax

  if ( !isInitialized_0 )
  {
    v0 = UFG::qStringHash32("cbCloudSettings", 0xFFFFFFFF);
    paramIndices_0.paramIndex_cbCloudSettings = (unsigned __int16)Illusion::StateSystem::GetParam(
                                                                    &Illusion::gStateSystem,
                                                                    v0);
    v1 = UFG::qStringHash32("cbEnvironmentSettings", 0xFFFFFFFF);
    paramIndices_0.paramIndex_cbEnvironmentSettings = (unsigned __int16)Illusion::StateSystem::GetParam(
                                                                          &Illusion::gStateSystem,
                                                                          v1);
    v2 = UFG::qStringHash32("cbInstancing", 0xFFFFFFFF);
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, v2);
    isInitialized_0 = 1;
    paramIndices_0.paramIndex_cbInstancing = Param;
  }
  return &paramIndices_0;
}

// File Line: 742
// RVA: 0x654A0
void __fastcall Render::SkyMarshall::InitWispModel(Render::SkyMarshall *this)
{
  UFG::qResourceData *v2; // rbp
  UFG::qBaseNodeRB *v3; // rax
  _QWORD *v4; // rcx
  char *v5; // rdi
  unsigned int mStringHash32; // ebx
  Illusion::Buffer *v7; // rsi
  __int64 mOffset; // rax
  char *v9; // rcx
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qString alloc_name; // [rsp+48h] [rbp-40h] BYREF

  v2 = Illusion::Factory::NewModel("SkyMarshall.TheWisp", 0xA952ACC5, 1u, 0i64, 0i64, 0i64);
  v3 = v2[2].mNode.mChild[0];
  if ( v3 )
    v4 = (UFG::qBaseNodeRB **)((char *)v2[2].mNode.mChild + (_QWORD)v3);
  else
    v4 = 0i64;
  v5 = (char *)v4 + *v4;
  if ( !*v4 )
    v5 = 0i64;
  UFG::qString::qString(&alloc_name, "SkyMarshall.TheWisp.VertexBuffer");
  mStringHash32 = alloc_name.mStringHash32;
  if ( alloc_name.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(alloc_name.mData, 0xFFFFFFFF);
    alloc_name.mStringHash32 = mStringHash32;
  }
  *((_QWORD *)v5 + 28) = 3i64;
  *((_DWORD *)v5 + 58) = 2;
  v7 = Illusion::Factory::NewBuffer(alloc_name.mData, mStringHash32, 0x40u, 0i64, alloc_name.mData, 0i64, 0i64);
  v7->mBufferType = 0;
  v7->mElementByteSize = 16;
  v7->mNumElements = 4;
  mOffset = v7->mData.mOffset;
  if ( mOffset )
    v9 = (char *)&v7->mData + mOffset;
  else
    v9 = 0i64;
  *(_DWORD *)v9 = -1090519040;
  *((_DWORD *)v9 + 1) = -1090519040;
  *((_DWORD *)v9 + 2) = 0;
  *((_DWORD *)v9 + 3) = 1048576000;
  *((_DWORD *)v9 + 4) = 1056964608;
  *((_DWORD *)v9 + 5) = -1090519040;
  *((_DWORD *)v9 + 6) = 1048576000;
  *((_DWORD *)v9 + 7) = 1048576000;
  *((_DWORD *)v9 + 8) = 1056964608;
  *((_DWORD *)v9 + 9) = 1056964608;
  *((_QWORD *)v9 + 5) = 1048576000i64;
  *((_DWORD *)v9 + 12) = -1090519040;
  *(_QWORD *)(v9 + 52) = 1056964608i64;
  *((_DWORD *)v9 + 15) = 0;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, &v7->UFG::qResourceData);
  *((_QWORD *)v5 + 30) = "SkyMarshall.TheWisp";
  *((_DWORD *)v5 + 30) = mStringHash32;
  *((_DWORD *)v5 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gCloudWispDescriptor);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mWispModel, 0xA2ADCD77, 0xA952ACC5, Inventory);
  UFG::qString::~qString(&alloc_name);
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v2);
}

// File Line: 797
// RVA: 0x64F50
void __fastcall Render::SkyMarshall::InitCloudResources(Render::SkyMarshall *this)
{
  unsigned int v2; // r14d
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  _WORD *v8; // rbp
  UFG::qResourceData *v9; // rax
  UFG::qResourceData *v10; // rbx
  UFG::qResourceWarehouse *v11; // rax
  unsigned int v12; // r15d
  Illusion::Material *v13; // rdi
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  UFG::TimeOfDayManager *Instance; // rax
  int v19; // eax
  unsigned int v20; // eax
  UFG::qResourceWarehouse *v21; // rax
  __int64 mOffset; // rax
  _WORD *v23; // rax
  __int64 v24; // rax
  UFG::qResourceInventory *v25; // rax
  UFG::qResourceWarehouse *v26; // rax
  unsigned int (*mCloudInstanceBuffer)[512]; // rax
  __int64 v28; // rcx

  v2 = UFG::qStringHashUpper32("SKY_Clouds_001", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mTexture, 0x8B43FABF, v2, Inventory);
  v5 = UFG::qStringHashUpper32("SKY_Noise_001", 0xFFFFFFFF);
  v6 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mNoiseTexture, 0x8B43FABF, v5, v6);
  v8 = 0i64;
  v9 = Illusion::Factory::NewAlphaState(Render::AlphaStateModulatedAddAlpha, 0x46A8B3E9u, 0i64, 0i64, 0i64);
  LOWORD(v9[1].mNode.mParent) = 1025;
  LOWORD(v9[1].mNode.mChild[0]) = 1793;
  BYTE2(v9[1].mNode.mParent) = 5;
  BYTE2(v9[1].mNode.mChild[0]) = 1;
  v10 = v9;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, v10);
  v12 = UFG::qStringHashUpper32("SkyMarshall.CloudMat", 0xFFFFFFFF);
  v13 = Illusion::Factory::NewMaterial("SkyMarshall.CloudMat", v12, 6u, 0i64, 0i64, 0i64);
  LODWORD(v10) = UFG::qStringHash32("HK_CLOUD", 0xFFFFFFFF);
  LOWORD(v13[1].mNode.mChild[0]) = 0;
  HIDWORD(v13[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v13[1].mTypeUID = -1957338719;
  LODWORD(v13[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v10;
  LODWORD(v13[1].mNode.mParent) = v14;
  *(_WORD *)&v13[1].mDebugName[12] = 0;
  *(_DWORD *)&v13[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v13[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v13[1].mStateBlockMask.mFlags[0]) = v2;
  *(_DWORD *)&v13[1].mDebugName[4] = v15;
  LOWORD(v13[1].mMaterialUser.mOffset) = 0;
  *(&v13[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v13[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v13[2].mNode.mUID = 1185461225;
  v13[1].mNumParams = v16;
  LOWORD(v13[2].mTypeUID) = 0;
  HIDWORD(v13[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v13[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v13[2].mDebugName[28] = 1099738947;
  LODWORD(v13[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v17;
  Instance = UFG::TimeOfDayManager::GetInstance();
  LODWORD(v10) = UFG::TimeOfDayManager::GetFogTexture(Instance)->mNode.mUID;
  LOWORD(v13[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v13[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v19 = UFG::qStringHash32("texFogCube", 0xFFFFFFFF);
  LODWORD(v13[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v13[3].mNode.mChild[0]) = (_DWORD)v10;
  LODWORD(v13[2].mStateBlockMask.mFlags[0]) = v19;
  LODWORD(v10) = UFG::qStringHashUpper32("CloudGradient", 0xFFFFFFFF);
  LOWORD(v13[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v13[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v13[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v13[3].mDebugName[12] = (_DWORD)v10;
  v13[3].mNode.mUID = v20;
  v21 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v21, v13);
  if ( v13[2].mNode.mUID != 1185461225 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v13[2],
      (unsigned int)v13[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x46A8B3E9u);
    mOffset = v13->mMaterialUser.mOffset;
    if ( mOffset )
      v23 = (_WORD *)((char *)&v13->mMaterialUser + mOffset);
    else
      v23 = 0i64;
    *v23 |= 0x20u;
  }
  if ( *(_DWORD *)&v13[2].mDebugName[28] != 1099738947 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v13[2].mDebugName[4],
      *((_DWORD *)&v13[2].UFG::qResourceData + 22),
      0x418CAF43u);
    v24 = v13->mMaterialUser.mOffset;
    if ( v24 )
      v8 = (_WORD *)((char *)&v13->mMaterialUser + v24);
    *v8 |= 0x20u;
  }
  v25 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v26 = UFG::qResourceWarehouse::Instance();
    v25 = UFG::qResourceWarehouse::GetInventory(v26, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v25;
  }
  UFG::qResourceHandle::Init(&this->mCloudMaterial, 0xB4C26312, v12, v25);
  Render::SkyMarshall::InitWispModel(this);
  Render::SkyMarshall::InitIndexBuffers(this);
  mCloudInstanceBuffer = this->mCloudInstanceBuffer;
  v28 = 128i64;
  do
  {
    *(_QWORD *)mCloudInstanceBuffer = 0x1000000010i64;
    *(_QWORD *)&(*mCloudInstanceBuffer)[2] = 0x1000000010i64;
    *(_QWORD *)&(*mCloudInstanceBuffer)[4] = 0x1000000010i64;
    mCloudInstanceBuffer = (unsigned int (*)[512])((char *)mCloudInstanceBuffer + 64);
    *(_QWORD *)&(*mCloudInstanceBuffer)[-10] = 0x1000000010i64;
    *(_QWORD *)&(*mCloudInstanceBuffer)[-8] = 0x1000000010i64;
    *(_QWORD *)&(*mCloudInstanceBuffer)[-6] = 0x1000000010i64;
    *(_QWORD *)&(*mCloudInstanceBuffer)[-4] = 0x1000000010i64;
    *(_QWORD *)&(*mCloudInstanceBuffer)[-2] = 0x1000000010i64;
    --v28;
  }
  while ( v28 );
}

// File Line: 926
// RVA: 0x64B90
bool __fastcall Render::SkyMarshall::CloudDistanceCompare(
        Render::SkyMarshall::CloudInstanceID *a,
        Render::SkyMarshall::CloudInstanceID *b)
{
  UFG::qResourceData *mData; // r9
  UFG::qResourceData *v4; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  char *v6; // r10
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  char *v8; // r9

  mData = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[b->mSceneIndex].mData;
  v4 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[a->mSceneIndex].mData;
  mPrev = v4[1].mResourceHandles.mNode.mPrev;
  v6 = (char *)&v4[1].mResourceHandles + (_QWORD)mPrev;
  if ( !mPrev )
    v6 = 0i64;
  v7 = mData[1].mResourceHandles.mNode.mPrev;
  if ( v7 )
    v8 = (char *)&mData[1].mResourceHandles + (_QWORD)v7;
  else
    v8 = 0i64;
  return *(float *)&v6[192 * a->mInstanceIndex + 180] < *(float *)&v8[192 * b->mInstanceIndex + 180];
}

// File Line: 934
// RVA: 0x65370
void __fastcall Render::SkyMarshall::InitIndexBuffers(Render::SkyMarshall *this)
{
  unsigned int mStringHash32; // esi
  unsigned int v3; // ebx
  Illusion::Buffer *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax
  unsigned int *mAvailableBuffers; // rax
  UFG::qString v7; // [rsp+48h] [rbp-30h] BYREF

  if ( (_S3_1 & 1) == 0 )
  {
    _S3_1 |= 1u;
    index_buffer_size = index_buffer_elements << 10;
  }
  UFG::qString::qString(&v7, "SkyMarshall.IndexBufferDefault");
  mStringHash32 = v7.mStringHash32;
  if ( v7.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v7.mData, 0xFFFFFFFF);
    v7.mStringHash32 = mStringHash32;
  }
  v3 = 0;
  v4 = Illusion::Factory::NewBuffer(
         v7.mData,
         mStringHash32,
         index_buffer_size,
         0i64,
         "SkyMarshall.IndexBuffer",
         0i64,
         0i64);
  v4->mNumElements = index_buffer_elements << 9;
  v4->mBufferType = 1;
  v4->mElementByteSize = 2;
  v4->mFlags |= 2u;
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v5, &v4->UFG::qResourceData);
  Render::SkyMarshall::WispIndexBuffer::InitBufferHandles(&this->mWispIndexBuffer[16], mStringHash32, mStringHash32);
  Render::SkyMarshall::WispIndexBuffer::Reset(&this->mWispIndexBuffer[16], 0x200u);
  UFG::qString::~qString(&v7);
  mAvailableBuffers = this->mAvailableBuffers;
  do
    *mAvailableBuffers++ = v3++;
  while ( v3 < 0x10 );
}

// File Line: 1030
// RVA: 0x64EB0
void __fastcall Render::SkyMarshall::WispIndexBuffer::InitBufferHandles(
        Render::SkyMarshall::WispIndexBuffer *this,
        unsigned int bufferA,
        unsigned int bufferB)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  Inventory = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mBufferHandle[0], 0x92CDEC8F, bufferA, Inventory);
  v8 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v8;
  }
  UFG::qResourceHandle::Init(&this->mBufferHandle[1], 0x92CDEC8F, bufferB, v8);
}

// File Line: 1036
// RVA: 0x66300
char __fastcall Render::SkyMarshall::WispIndexBuffer::Reset(
        Render::SkyMarshall::WispIndexBuffer *this,
        unsigned int numWisps)
{
  __int16 v5; // bx
  UFG::qResourceData *mData; // rbp
  _WORD *v7; // rax
  unsigned __int16 v8; // r9
  unsigned __int16 v9; // r10
  __int64 v10; // rdx
  __int16 v11; // cx

  if ( numWisps == this->mNumWisps )
    return 0;
  v5 = 1;
  mData = this->mBufferHandle[Render::SkyMarshall::WispIndexBuffer::mActiveBuffer].mData;
  v7 = Illusion::IBufferPlat::Lock((Illusion::IBufferPlat *)mData, LOCK_OVERWRITE);
  v8 = 0;
  if ( numWisps )
  {
    v9 = 0;
    do
    {
      v10 = v9;
      ++v8;
      v7[v9 + 2] = v5 + 2;
      v7[v9 + 3] = v5 + 2;
      v11 = v5 - 1;
      v7[v9 + 5] = v5 + 1;
      v7[v9 + 1] = v5;
      v7[v9 + 4] = v5;
      v9 += 6;
      v5 += 4;
      v7[v10] = v11;
    }
    while ( v8 < numWisps );
  }
  Illusion::IBufferPlat::Unlock((Illusion::IBufferPlat *)mData);
  this->mNumWisps = numWisps;
  this->mNewestBuffer = Render::SkyMarshall::WispIndexBuffer::mActiveBuffer;
  this->mOutOfSync = 1;
  return 1;
}

// File Line: 1127
// RVA: 0x66470
void __fastcall Render::SkyMarshall::SubmitCloudTask(
        Render::SkyMarshall *this,
        UFG::RenderContext *render_context,
        CB_EnvironmentSettings *pEnvSettings)
{
  Render::SkyMarshall *v4; // r15
  float mEnviroScalar; // xmm1_4
  int v6; // r13d
  unsigned int v7; // edx
  CullResults **mCullResults; // r11
  UFG::qResourceData **p_mData; // r10
  UFG::qResourceData *v10; // r8
  unsigned int v11; // ecx
  CullResults *v12; // r9
  unsigned int v13; // r10d
  __int64 v14; // rdx
  unsigned int v15; // eax
  __int64 v16; // r9
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rcx
  char *v18; // r8
  float *v19; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v20; // rcx
  char *v21; // r8
  float *v22; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v23; // rcx
  char *v24; // r8
  float *v25; // rcx
  UFG::qResourceData *mData; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  char *v28; // r8
  float *v29; // rcx
  unsigned __int16 *v30; // r8
  __int64 v31; // r9
  UFG::qResourceData *v32; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v33; // rax
  char *v34; // rdx
  float *v35; // rcx
  float *v36; // r12
  __int64 v37; // rax
  __int64 v38; // rcx
  Render::SkyMarshall::CloudInstanceID *v39; // rbx
  float v40; // eax
  Render::SkyMarshall::CloudInstanceID v41; // eax
  Render::SkyMarshall::CloudInstanceID v42; // eax
  Render::SkyMarshall::CloudInstanceID v43; // eax
  Render::SkyMarshall::CloudInstanceID *v44; // rbx
  Render::SkyMarshall::CloudInstanceID *v45; // rdx
  UFG::qResourceData *v46; // r10
  __int64 v47; // r14
  UFG::qResourceData *v48; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v49; // rax
  __int64 v50; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v51; // rax
  __int64 v52; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v53; // rsi
  UFG::qResourceData *v54; // rcx
  __int64 v55; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v56; // rax
  __int64 v57; // r8
  Render::SkyMarshall::CloudInstanceID v58; // eax
  __int64 v59; // r12
  float *p_y; // r15
  int v61; // eax
  __int64 v62; // r9
  unsigned __int16 v63; // dx
  UFG::qResourceData *v64; // r10
  __int64 v65; // rsi
  unsigned __int16 *v66; // r8
  UFG::qResourceData *v67; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v68; // rcx
  __int64 v69; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v70; // rcx
  __int64 v71; // rbx
  UFG::qResourceData *v72; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v73; // rcx
  char *v74; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v75; // rcx
  char *v76; // rbx
  UFG::qResourceData *v77; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v78; // rcx
  char *v79; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v80; // rcx
  char *v81; // rbx
  UFG::qResourceData *v82; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v83; // rcx
  char *v84; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v85; // rcx
  char *v86; // rbx
  UFG::qResourceData *v87; // rbx
  __int64 v88; // rsi
  UFG::qResourceData *v89; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v90; // rcx
  char *v91; // r10
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v92; // rcx
  char *v93; // r8
  int v94; // eax
  __int64 v95; // rsi
  unsigned int v96; // r13d
  int v97; // r14d
  unsigned __int16 *v98; // r12
  int v99; // r8d
  UFG::qResourceData *v100; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v101; // rax
  char *v102; // rdx
  char *local_world; // rsi
  __int64 v104; // rdx
  __int64 v105; // r10
  __int64 v106; // rcx
  UFG::qVector4 v107; // xmm2
  UFG::qVector4 v108; // xmm1
  UFG::qVector4 v109; // xmm0
  UFG::qVector4 v110; // xmm2
  UFG::qVector4 v111; // xmm1
  UFG::qVector4 v112; // xmm0
  float v113; // xmm0_4
  float mBoundaryCloudSceneOpacity; // xmm1_4
  float v115; // xmm1_4
  float v116; // xmm2_4
  UFG::qVector3 *v117; // r13
  float v118; // xmm1_4
  float v119; // xmm2_4
  float v120; // xmm1_4
  float v121; // xmm2_4
  _QWORD *v122; // rax
  __int64 v123; // r8
  char *v124; // rax
  UFG::qResourceData *v125; // r8
  UFG::qBaseNodeRB *v126; // rax
  char *v127; // r9
  Render::DebugDrawContext *Context; // rbx
  char *v129; // rbx
  char *v130; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  __int128 v133; // xmm2
  __int128 v134; // xmm1
  __int128 v135; // xmm0
  __int128 v136; // xmm2
  __int128 v137; // xmm1
  __int128 v138; // xmm0
  UFG::qResourceData *v139; // rax
  UFG::qBaseNodeRB *v140; // rcx
  _QWORD *v141; // rax
  char *v142; // rax
  char *v143; // rax
  UFG::qTask *v144; // rdx
  _QWORD *v145; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v152; // rax
  unsigned __int64 Ticks; // rax
  __int64 v154; // [rsp+30h] [rbp-90h]
  UFG::qMatrix44 d; // [rsp+40h] [rbp-80h] BYREF
  char *v156; // [rsp+8D0h] [rbp+810h]
  __int64 v157; // [rsp+8D8h] [rbp+818h]
  __int64 v158; // [rsp+8E0h] [rbp+820h]
  UFG::qVector3 *aabb_max; // [rsp+8E8h] [rbp+828h]

  *(_QWORD *)&d.v1.x = -2i64;
  v4 = this;
  if ( !this->mEnableDome && Render::SkyMarshall::sEnableClouds )
  {
    mEnviroScalar = this->mEnviroScalar;
    if ( mEnviroScalar < 0.0 )
      LODWORD(mEnviroScalar) ^= _xmm[0];
    if ( mEnviroScalar >= 0.001 )
    {
      *(_QWORD *)&d.v0.x = UFG::qGetTicks();
      Render::SkyMarshall::WispIndexBuffer::mActiveBuffer = Render::SkyMarshall::WispIndexBuffer::mActiveBuffer == 0;
      *(_QWORD *)&d.v0.z = &render_context->mMainViewSettings;
      UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
      sSortIndex = ((_BYTE)sSortIndex + 1) & 0xF;
      v6 = 0;
      v7 = 0;
      mCullResults = v4->mCullResults;
      p_mData = &v4->mCloudSceneHandle[0].mData;
      do
      {
        v10 = *p_mData;
        if ( *p_mData )
        {
          v11 = 0;
          if ( LODWORD(v10[1].mNode.mParent) )
          {
            v12 = *mCullResults;
            do
            {
              if ( v12[(unsigned __int64)v11].mViewResult[0] <= 1u )
              {
                *((_WORD *)&d.v2.x + 2 * (unsigned int)v6) = v7;
                *((_WORD *)&d.v2.x + 2 * (unsigned int)v6++ + 1) = v11;
              }
              ++v11;
            }
            while ( v11 < LODWORD(v10[1].mNode.mParent) );
          }
        }
        ++v7;
        ++mCullResults;
        p_mData += 4;
      }
      while ( v7 < 4 );
      v13 = 0;
      v14 = 0i64;
      if ( v6 >= 4 )
      {
        v15 = ((unsigned int)(v6 - 4) >> 2) + 1;
        v16 = v15;
        v13 = 4 * v15;
        do
        {
          p_mResourceHandles = &v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.x + 2 * v14)].mData[1].mResourceHandles;
          v18 = (char *)p_mResourceHandles + (unsigned __int64)p_mResourceHandles->mNode.mPrev;
          if ( !p_mResourceHandles->mNode.mPrev )
            v18 = 0i64;
          v19 = (float *)&v18[192 * *((unsigned __int16 *)&d.v2.x + 2 * v14 + 1)];
          v19[45] = (float)((float)((float)(d.v3.y - v19[13]) * (float)(d.v3.y - v19[13]))
                          + (float)((float)(d.v3.x - v19[12]) * (float)(d.v3.x - v19[12])))
                  + (float)((float)(d.v3.z - v19[14]) * (float)(d.v3.z - v19[14]));
          v20 = &v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.y + 2 * v14)].mData[1].mResourceHandles;
          v21 = (char *)v20 + (unsigned __int64)v20->mNode.mPrev;
          if ( !v20->mNode.mPrev )
            v21 = 0i64;
          v22 = (float *)&v21[192 * *((unsigned __int16 *)&d.v2.y + 2 * v14 + 1)];
          v22[45] = (float)((float)((float)(d.v3.y - v22[13]) * (float)(d.v3.y - v22[13]))
                          + (float)((float)(d.v3.x - v22[12]) * (float)(d.v3.x - v22[12])))
                  + (float)((float)(d.v3.z - v22[14]) * (float)(d.v3.z - v22[14]));
          v23 = &v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.z + 2 * v14)].mData[1].mResourceHandles;
          v24 = (char *)v23 + (unsigned __int64)v23->mNode.mPrev;
          if ( !v23->mNode.mPrev )
            v24 = 0i64;
          v25 = (float *)&v24[192 * *((unsigned __int16 *)&d.v2.z + 2 * v14 + 1)];
          v25[45] = (float)((float)((float)(d.v3.y - v25[13]) * (float)(d.v3.y - v25[13]))
                          + (float)((float)(d.v3.x - v25[12]) * (float)(d.v3.x - v25[12])))
                  + (float)((float)(d.v3.z - v25[14]) * (float)(d.v3.z - v25[14]));
          mData = v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.w + 2 * v14)].mData;
          mPrev = mData[1].mResourceHandles.mNode.mPrev;
          if ( mPrev )
            v28 = (char *)&mPrev[7].mNext + (_QWORD)mData;
          else
            v28 = 0i64;
          v29 = (float *)&v28[192 * *((unsigned __int16 *)&d.v2.w + 2 * v14 + 1)];
          v29[45] = (float)((float)((float)(d.v3.x - v29[12]) * (float)(d.v3.x - v29[12]))
                          + (float)((float)(d.v3.y - v29[13]) * (float)(d.v3.y - v29[13])))
                  + (float)((float)(d.v3.z - v29[14]) * (float)(d.v3.z - v29[14]));
          v14 += 4i64;
          --v16;
        }
        while ( v16 );
      }
      if ( v13 < v6 )
      {
        v30 = (unsigned __int16 *)&d.v2.x + 2 * v14 + 1;
        v31 = v6 - v13;
        do
        {
          v32 = v4->mCloudSceneHandle[*(v30 - 1)].mData;
          v33 = v32[1].mResourceHandles.mNode.mPrev;
          if ( v33 )
            v34 = (char *)&v33[7].mNext + (_QWORD)v32;
          else
            v34 = 0i64;
          v35 = (float *)&v34[192 * *v30];
          v35[45] = (float)((float)((float)(d.v3.x - v35[12]) * (float)(d.v3.x - v35[12]))
                          + (float)((float)(d.v3.y - v35[13]) * (float)(d.v3.y - v35[13])))
                  + (float)((float)(d.v3.z - v35[14]) * (float)(d.v3.z - v35[14]));
          v30 += 2;
          --v31;
        }
        while ( v31 );
      }
      v36 = &d.v1.w + v6;
      v37 = (4i64 * v6 - 100 + 96) >> 2;
      LODWORD(v38) = v37 + 1;
      if ( (int)v37 + 1 < 32 )
      {
        v154 = (int)v38;
        if ( (int)v38 >= 2i64 )
        {
          v59 = 0i64;
          p_y = &d.v2.y;
          v38 = (int)v38;
          do
          {
            v61 = *(_DWORD *)p_y;
            *(float *)&aabb_max = *p_y;
            v62 = v59;
            if ( v59 >= 0 )
            {
              v63 = WORD1(aabb_max);
              if ( v59 + 1 < 4 )
              {
LABEL_104:
                if ( v62 >= 0 )
                {
                  v87 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[(unsigned __int16)v61].mData;
                  v88 = 192i64 * v63;
                  do
                  {
                    v89 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[*((unsigned __int16 *)&d.v2.x + 2 * v62)].mData;
                    v90 = v87[1].mResourceHandles.mNode.mPrev;
                    if ( v90 )
                      v91 = (char *)&v90[7].mNext + (_QWORD)v87;
                    else
                      v91 = 0i64;
                    v92 = v89[1].mResourceHandles.mNode.mPrev;
                    if ( v92 )
                      v93 = (char *)&v92[7].mNext + (_QWORD)v89;
                    else
                      v93 = 0i64;
                    if ( *(float *)&v93[192 * *((unsigned __int16 *)&d.v2.x + 2 * v62 + 1) + 180] <= *(float *)&v91[v88 + 180] )
                      break;
                    *((_DWORD *)&d.v2.y + v62) = *((_DWORD *)&d.v2.x + v62);
                    --v62;
                  }
                  while ( v62 >= 0 );
                }
              }
              else
              {
                v64 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[(unsigned __int16)v61].mData;
                v65 = 192i64 * WORD1(aabb_max);
                v66 = (unsigned __int16 *)p_y - 5;
                while ( 1 )
                {
                  v67 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v66[3]].mData;
                  v68 = v64[1].mResourceHandles.mNode.mPrev;
                  v69 = v68 ? (__int64)&v68[7].mNext + (_QWORD)v64 : 0i64;
                  v70 = v67[1].mResourceHandles.mNode.mPrev;
                  v71 = v70 ? (__int64)&v70[7].mNext + (_QWORD)v67 : 0i64;
                  if ( *(float *)(192i64 * v66[4] + v71 + 180) <= *(float *)(v69 + v65 + 180) )
                    break;
                  *(_DWORD *)(v66 + 5) = *(_DWORD *)(v66 + 3);
                  v72 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v66[1]].mData;
                  v73 = v64[1].mResourceHandles.mNode.mPrev;
                  if ( v73 )
                    v74 = (char *)&v73[7].mNext + (_QWORD)v64;
                  else
                    v74 = 0i64;
                  v75 = v72[1].mResourceHandles.mNode.mPrev;
                  if ( v75 )
                    v76 = (char *)&v75[7].mNext + (_QWORD)v72;
                  else
                    v76 = 0i64;
                  if ( *(float *)&v76[192 * v66[2] + 180] <= *(float *)&v74[v65 + 180] )
                  {
                    --v62;
                    break;
                  }
                  *(_DWORD *)(v66 + 3) = *(_DWORD *)(v66 + 1);
                  v77 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[*(v66 - 1)].mData;
                  v78 = v64[1].mResourceHandles.mNode.mPrev;
                  if ( v78 )
                    v79 = (char *)&v78[7].mNext + (_QWORD)v64;
                  else
                    v79 = 0i64;
                  v80 = v77[1].mResourceHandles.mNode.mPrev;
                  if ( v80 )
                    v81 = (char *)&v80[7].mNext + (_QWORD)v77;
                  else
                    v81 = 0i64;
                  if ( *(float *)&v81[192 * *v66 + 180] <= *(float *)&v79[v65 + 180] )
                  {
                    v62 -= 2i64;
                    break;
                  }
                  *(_DWORD *)(v66 + 1) = *(_DWORD *)(v66 - 1);
                  v82 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[*(v66 - 3)].mData;
                  v83 = v64[1].mResourceHandles.mNode.mPrev;
                  if ( v83 )
                    v84 = (char *)&v83[7].mNext + (_QWORD)v64;
                  else
                    v84 = 0i64;
                  v85 = v82[1].mResourceHandles.mNode.mPrev;
                  if ( v85 )
                    v86 = (char *)&v85[7].mNext + (_QWORD)v82;
                  else
                    v86 = 0i64;
                  if ( *(float *)&v86[192 * *(v66 - 2) + 180] <= *(float *)&v84[v65 + 180] )
                  {
                    v62 -= 3i64;
                    break;
                  }
                  *(_DWORD *)(v66 - 1) = *(_DWORD *)(v66 - 3);
                  v62 -= 4i64;
                  v66 -= 8;
                  if ( v62 < 3 )
                  {
                    v63 = WORD1(aabb_max);
                    goto LABEL_104;
                  }
                }
              }
              v38 = v154;
            }
            *((_DWORD *)&d.v2.y + v62) = v61;
            ++p_y;
            ++v59;
          }
          while ( v59 + 1 < v38 );
          v4 = (Render::SkyMarshall *)v156;
        }
      }
      else
      {
        v39 = (Render::SkyMarshall::CloudInstanceID *)(&d.v2.x + v37 / 2);
        if ( Render::SkyMarshall::CloudDistanceCompare(v39, (Render::SkyMarshall::CloudInstanceID *)&d.v2) )
        {
          v40 = *(float *)v39;
          *v39 = LODWORD(d.v2.x);
          d.v2.x = v40;
        }
        if ( Render::SkyMarshall::CloudDistanceCompare((Render::SkyMarshall::CloudInstanceID *)&d.v1.w + v6, v39) )
        {
          v41 = *(Render::SkyMarshall::CloudInstanceID *)v36;
          *v36 = *(float *)v39;
          *v39 = v41;
        }
        if ( Render::SkyMarshall::CloudDistanceCompare(v39, (Render::SkyMarshall::CloudInstanceID *)&d.v2) )
        {
          v42 = *v39;
          *v39 = LODWORD(d.v2.x);
          LODWORD(d.v2.x) = v42;
        }
        v43 = *v39;
        LODWORD(v156) = *v39;
        v44 = (Render::SkyMarshall::CloudInstanceID *)&d.v2;
        v45 = (Render::SkyMarshall::CloudInstanceID *)(&d.v1.w + v6);
        if ( &d.v2 <= (UFG::qVector4 *)v36 )
        {
          v46 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v43.mSceneIndex].mData;
          v47 = 192i64 * WORD1(v156);
          do
          {
            while ( 1 )
            {
              v48 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v44->mSceneIndex].mData;
              v49 = v48[1].mResourceHandles.mNode.mPrev;
              v50 = v49 ? (__int64)&v49[7].mNext + (_QWORD)v48 : 0i64;
              v51 = v46[1].mResourceHandles.mNode.mPrev;
              v52 = v51 ? (__int64)&v51[7].mNext + (_QWORD)v46 : 0i64;
              if ( *(float *)(v52 + v47 + 180) <= *(float *)(192i64 * v44->mInstanceIndex + v50 + 180)
                || v44 >= (Render::SkyMarshall::CloudInstanceID *)v36 )
              {
                break;
              }
              ++v44;
            }
            v53 = v46[1].mResourceHandles.mNode.mPrev;
            while ( 1 )
            {
              v54 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v45->mSceneIndex].mData;
              v55 = v53 ? (__int64)&v53[7].mNext + (_QWORD)v46 : 0i64;
              v56 = v54[1].mResourceHandles.mNode.mPrev;
              v57 = v56 ? (__int64)&v56[7].mNext + (_QWORD)v54 : 0i64;
              if ( *(float *)(192i64 * v45->mInstanceIndex + v57 + 180) <= *(float *)(v55 + v47 + 180)
                || &d.v2 >= (UFG::qVector4 *)v45 )
              {
                break;
              }
              --v45;
            }
            if ( v44 > v45 )
              break;
            v58 = *v44;
            *v44 = *v45;
            *v45 = v58;
            ++v44;
            --v45;
          }
          while ( v44 <= v45 );
        }
        if ( &d.v2 < (UFG::qVector4 *)v45 )
          UFG::qQuickSortImpl<Render::SkyMarshall::CloudInstanceID,bool (*)(Render::SkyMarshall::CloudInstanceID const &,Render::SkyMarshall::CloudInstanceID const &)>(
            (Render::SkyMarshall::CloudInstanceID *)&d.v2,
            v45,
            Render::SkyMarshall::CloudDistanceCompare);
        if ( v44 < (Render::SkyMarshall::CloudInstanceID *)v36 )
          UFG::qQuickSortImpl<Render::SkyMarshall::CloudInstanceID,bool (*)(Render::SkyMarshall::CloudInstanceID const &,Render::SkyMarshall::CloudInstanceID const &)>(
            v44,
            (Render::SkyMarshall::CloudInstanceID *)&d.v1.w + v6,
            Render::SkyMarshall::CloudDistanceCompare);
      }
      v94 = 128;
      if ( (unsigned int)v6 < 0x80 )
        v94 = v6;
      v95 = v157;
      *(_DWORD *)(v157 + 980) += v94;
      v96 = 0;
      LODWORD(v156) = 0;
      v97 = v94 - 1;
      if ( v94 - 1 >= 0 )
      {
        v98 = (unsigned __int16 *)&d.v2.x + 2 * v97 + 1;
        do
        {
          v99 = *(v98 - 1);
          v100 = v4->mCloudSceneHandle[*(v98 - 1)].mData;
          v101 = v100[1].mResourceHandles.mNode.mPrev;
          if ( v101 )
            v102 = (char *)&v100[1].mResourceHandles + (_QWORD)v101;
          else
            v102 = 0i64;
          local_world = &v102[192 * *v98];
          v104 = *((_QWORD *)local_world + 10);
          v105 = v96;
          v106 = v96;
          v107 = (UFG::qVector4)*((_OWORD *)local_world + 1);
          v108 = (UFG::qVector4)*((_OWORD *)local_world + 2);
          v109 = (UFG::qVector4)*((_OWORD *)local_world + 3);
          v4->mTaskInstance[v106].mTransform.v0 = *(UFG::qVector4 *)local_world;
          v4->mTaskInstance[v106].mTransform.v1 = v107;
          v4->mTaskInstance[v106].mTransform.v2 = v108;
          v4->mTaskInstance[v106].mTransform.v3 = v109;
          v110 = *(UFG::qVector4 *)(local_world + 124);
          v111 = *(UFG::qVector4 *)(local_world + 140);
          v112 = *(UFG::qVector4 *)(local_world + 156);
          v4->mTaskInstance[v106].mInverseTransform.v0 = *(UFG::qVector4 *)(local_world + 108);
          v4->mTaskInstance[v106].mInverseTransform.v1 = v110;
          v4->mTaskInstance[v106].mInverseTransform.v2 = v111;
          v4->mTaskInstance[v106].mInverseTransform.v3 = v112;
          v4->mTaskInstance[v106].mScale = *((float *)local_world + 43);
          if ( Render::SkyMarshall::sUseCloudOpacity )
            v113 = *((float *)local_world + 44);
          else
            v113 = *(float *)&FLOAT_1_0;
          if ( v4->mBoundaryCloudSceneID == v99 )
            mBoundaryCloudSceneOpacity = v4->mBoundaryCloudSceneOpacity;
          else
            mBoundaryCloudSceneOpacity = *(float *)&FLOAT_1_0;
          v4->mTaskInstance[v106].mOpacity = (float)((float)(v113 * Render::SkyMarshall::sGlobalOpacity)
                                                   * mBoundaryCloudSceneOpacity)
                                           * v4->mEnviroScalar;
          v4->mTaskInstance[v106].mNumWisps = *(_DWORD *)(v104 + 88);
          v115 = *(float *)(v104 + 120);
          v116 = *(float *)(v104 + 124);
          v4->mTaskInstance[v106].mCenter.x = *(float *)(v104 + 116);
          v4->mTaskInstance[v106].mCenter.y = v115;
          v4->mTaskInstance[v106].mCenter.z = v116;
          v117 = (UFG::qVector3 *)(v104 + 92);
          v118 = *(float *)(v104 + 96);
          v119 = *(float *)(v104 + 100);
          v4->mTaskInstance[v106].mAABBMin.x = *(float *)(v104 + 92);
          v4->mTaskInstance[v106].mAABBMin.y = v118;
          v4->mTaskInstance[v106].mAABBMin.z = v119;
          aabb_max = (UFG::qVector3 *)(v104 + 104);
          v120 = *(float *)(v104 + 108);
          v121 = *(float *)(v104 + 112);
          v4->mTaskInstance[v106].mAABBMax.x = *(float *)(v104 + 104);
          v4->mTaskInstance[v106].mAABBMax.y = v120;
          v4->mTaskInstance[v106].mAABBMax.z = v121;
          v4->mTaskInstance[v106].mRadius = *(float *)(v104 + 128);
          v122 = *(_QWORD **)(v104 + 152);
          v4->mTaskInstance[v106].mAttributeBuffer.m_Stream = v122;
          v123 = v122[12];
          if ( v123 )
            v124 = (char *)v122 + v123 + 96;
          else
            v124 = 0i64;
          v4->mTaskInstance[v106].mAttributeBufferData = v124;
          v125 = v4->mWispIndexBuffer[16].mBufferHandle[Render::SkyMarshall::WispIndexBuffer::mActiveBuffer].mData;
          v4->mTaskInstance[v106].mIndexBuffer.m_Stream = v125;
          v126 = v125[1].mNode.mChild[0];
          if ( v126 )
            v127 = (char *)v125[1].mNode.mChild + (_QWORD)v126;
          else
            v127 = 0i64;
          v4->mTaskInstance[v105].mIndexBufferData = v127;
          *(_WORD *)&v4->mTaskInstance[v106].mReset = 0;
          v4->mTaskInstance[v106].mDebugName = (void *)(v104 + 52);
          if ( Render::SkyMarshall::sCloudDrawDebug )
          {
            Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    2u);
            Render::DebugDrawContext::DrawAABB(
              Context,
              v117,
              aabb_max,
              &UFG::qColour::Blue,
              (UFG::qMatrix44 *)local_world,
              0i64);
            Render::DebugDrawContext::DrawAxes(Context, (UFG::qMatrix44 *)local_world, 20.0, 0, 0i64);
          }
          v96 = (_DWORD)v156 + 1;
          LODWORD(v156) = (_DWORD)v156 + 1;
          v98 -= 2;
          --v97;
        }
        while ( v97 >= 0 );
        if ( v96 )
        {
          v129 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xE8u, 0x10u);
          Render::gCloudSortTaskParams = (CloudSortTaskParams *)v129;
          v130 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x20u);
          v156 = v130;
          aabb_max = (UFG::qVector3 *)v130;
          if ( v130 )
          {
            *(_QWORD *)v130 = v130;
            *((_QWORD *)v130 + 1) = v130;
          }
          else
          {
            v130 = 0i64;
          }
          *((_QWORD *)v129 + 24) = v130;
          *((_QWORD *)v129 + 20) = v158;
          y = d.v3.y;
          z = d.v3.z;
          *((_DWORD *)v129 + 32) = LODWORD(d.v3.x);
          *((float *)v129 + 33) = y;
          *((float *)v129 + 34) = z;
          *((_DWORD *)v129 + 35) = v96;
          *((_QWORD *)v129 + 18) = v4->mTaskInstance;
          *((_QWORD *)v129 + 21) = Illusion::gEngine.FrameMemory;
          v133 = *(_OWORD *)(*(_QWORD *)&d.v0.z + 16i64);
          v134 = *(_OWORD *)(*(_QWORD *)&d.v0.z + 32i64);
          v135 = *(_OWORD *)(*(_QWORD *)&d.v0.z + 48i64);
          *(_OWORD *)v129 = **(_OWORD **)&d.v0.z;
          *((_OWORD *)v129 + 1) = v133;
          *((_OWORD *)v129 + 2) = v134;
          *((_OWORD *)v129 + 3) = v135;
          v95 = v157;
          v136 = *(_OWORD *)(v157 + 1088);
          v137 = *(_OWORD *)(v157 + 1104);
          v138 = *(_OWORD *)(v157 + 1120);
          *((_OWORD *)v129 + 4) = *(_OWORD *)(v157 + 1072);
          *((_OWORD *)v129 + 5) = v136;
          *((_OWORD *)v129 + 6) = v137;
          *((_OWORD *)v129 + 7) = v138;
          *((_QWORD *)v129 + 22) = Render::GetViewStateBlockParams();
          *((_QWORD *)v129 + 23) = Render::GetCloudSortTaskParamIndices();
          *((_QWORD *)v129 + 25) = &Render::gCloudRenderLayer;
          v139 = v4->mWispModel.mData;
          v140 = v139[2].mNode.mChild[0];
          if ( v140 )
            v141 = (UFG::qBaseNodeRB **)((char *)v139[2].mNode.mChild + (_QWORD)v140);
          else
            v141 = 0i64;
          if ( *v141 )
            v142 = (char *)v141 + *v141;
          else
            v142 = 0i64;
          *((_QWORD *)v129 + 26) = v142;
          *((_DWORD *)v129 + 38) = *(_DWORD *)(*((_QWORD *)v142 + 14) + 108i64);
          *((_QWORD *)v129 + 27) = v4->mCloudMaterial.mData;
          v143 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
          v144 = (UFG::qTask *)v143;
          v156 = v143;
          aabb_max = (UFG::qVector3 *)v143;
          if ( v143 )
          {
            *(_QWORD *)v143 = v143;
            *((_QWORD *)v143 + 1) = v143;
            v145 = v143 + 16;
            *v145 = v145;
            v145[1] = v145;
            mSpuElf = gTaskFunctionDeclData_CloudSortTask.mSpuElf;
            mTaskFunctionSPU = gTaskFunctionDeclData_CloudSortTask.mTaskFunctionSPU;
            mTaskFunctionPPU = gTaskFunctionDeclData_CloudSortTask.mTaskFunctionPPU;
            mTaskFunctionOffload = gTaskFunctionDeclData_CloudSortTask.mTaskFunctionOffload;
            if ( !gTaskFunctionDeclData_CloudSortTask.mCurrentSPUEnabled )
            {
              mSpuElf = 0i64;
              mTaskFunctionSPU = 0i64;
              mTaskFunctionOffload = 0i64;
            }
            v144->mTaskGroup = 0i64;
            v144->mFlags = 2;
            v144->mSyncVars.i64 = 0i64;
            v144->mSyncVars.v.mDependents = 0i64;
            v144->mFunctionDeclData = &gTaskFunctionDeclData_CloudSortTask;
            if ( mSpuElf )
              mAddress = mSpuElf->mAddress;
            else
              mAddress = 0i64;
            v144->mSPUElfAddress = mAddress;
            v144->mSPUFunction = mTaskFunctionSPU;
            v144->mPPUFunction = mTaskFunctionPPU;
            v144->mParam0 = v129;
            v144->mParam1 = 0i64;
            v144->mParam2 = 0i64;
            v144->mParam3 = 0i64;
            if ( mTaskFunctionOffload )
            {
              v144->mFlags = 130;
              v144->mOffloadThread = 0;
            }
          }
          mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
          v152 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
          v152->mNext = v144;
          v144->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v152;
          v144->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
          mSingleFrameTasks->mNode.mPrev = v144;
          Render::gCloudTask = v144;
          UFG::qTaskManager::Queue(&UFG::gTaskManager, v144);
          goto LABEL_160;
        }
        v95 = v157;
      }
      Render::gCloudTask = 0i64;
      Render::gCloudSortTaskParams = 0i64;
LABEL_160:
      Ticks = UFG::qGetTicks();
      *(float *)(v95 + 904) = UFG::qGetTickTime(*(unsigned __int64 *)&d.v0.x, Ticks) + *(float *)(v95 + 904);
      return;
    }
  }
  Render::gCloudTask = 0i64;
}

