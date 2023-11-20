// File Line: 42
// RVA: 0x1456BA0
__int64 dynamic_initializer_for__Render::SkyMarshall::gSkyMarshall__()
{
  Render::SkyMarshall::SkyMarshall(&Render::SkyMarshall::gSkyMarshall);
  return atexit(dynamic_atexit_destructor_for__Render::SkyMarshall::gSkyMarshall__);
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
  return atexit(Render::_dynamic_atexit_destructor_for__gSkydomeListPropertySet__);
}

// File Line: 115
// RVA: 0x1456BC0
__int64 Render::_dynamic_initializer_for__gCloudRenderLayer__()
{
  RenderQueueLayer::RenderQueueLayer(&Render::gCloudRenderLayer);
  return atexit(Render::_dynamic_atexit_destructor_for__gCloudRenderLayer__);
}

// File Line: 120
// RVA: 0x657B0
void __fastcall Render::SkyMarshall::LoadSkydomeList(Render::SkyMarshall *this)
{
  Render::SkyMarshall *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qArray<Render::SkyMarshall::SkydomeResource,0> *v3; // r15
  unsigned int *v4; // rbx
  UFG::qSymbol *v5; // rax
  signed __int64 v6; // rdi
  UFG::qPropertyList *v7; // r13
  unsigned int v8; // er12
  __int64 v9; // rdi
  unsigned int v10; // ebx
  unsigned int v11; // edx
  unsigned int v12; // edx
  signed __int64 v13; // rsi
  char *v14; // rax
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
  UFG::qSymbol v25; // [rsp+20h] [rbp-88h]
  int v26; // [rsp+24h] [rbp-84h]
  UFG::qSymbol *v27; // [rsp+28h] [rbp-80h]
  unsigned int *v28; // [rsp+30h] [rbp-78h]
  __int64 v29; // [rsp+38h] [rbp-70h]
  UFG::qPropertySet *v30; // [rsp+40h] [rbp-68h]
  __int64 v31; // [rsp+48h] [rbp-60h]
  UFG::qSymbol name; // [rsp+50h] [rbp-58h]
  UFG::qSymbol result; // [rsp+54h] [rbp-54h]
  UFG::qSymbol v34; // [rsp+58h] [rbp-50h]
  UFG::qSymbol v35; // [rsp+5Ch] [rbp-4Ch]
  UFG::qSymbol v36; // [rsp+B8h] [rbp+10h]
  UFG::qSymbol v37; // [rsp+C0h] [rbp+18h]
  UFG::qSymbol v38; // [rsp+C8h] [rbp+20h]

  v31 = -2i64;
  v1 = this;
  UFG::qSymbol::create_from_string(&name, "SunnyList");
  UFG::qSymbol::create_from_string(&result, "CloudyList");
  UFG::qSymbol::create_from_string(&v34, "StormyList");
  UFG::qSymbol::create_from_string(&v35, "CustomList");
  UFG::qSymbol::create_from_string(&v36, "TexturePack");
  UFG::qSymbol::create_from_string(&v37, "ModelList");
  UFG::qSymbol::create_from_string(&v38, "Model");
  UFG::qSymbol::create_from_string(&v25, "RotationRate");
  v2 = UFG::PropertySetManager::GetPropertySet(&gSkydomeListPropertySet);
  v30 = v2;
  if ( v2 )
  {
    v3 = &v1->mSkydomeResources;
    v4 = v1->mSkydomeTypeIndex;
    v28 = v4;
    v5 = &name;
    v27 = &name;
    v6 = 4i64;
    v29 = 4i64;
    do
    {
      v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, v5, DEPTH_RECURSE);
      *v4 = v3->size;
      v8 = 0;
      if ( v7->mNumElements )
      {
        do
        {
          v9 = v3->size;
          v10 = v9 + 1;
          v11 = v3->capacity;
          if ( (signed int)v9 + 1 > v11 )
          {
            if ( v11 )
              v12 = 2 * v11;
            else
              v12 = 1;
            for ( ; v12 < v10; v12 *= 2 )
              ;
            if ( v12 - v10 > 0x10000 )
              v12 = v9 + 65537;
            UFG::qArray<Render::SkyMarshall::SkydomeResource,0>::Reallocate(v3, v12, "qArray.Add");
          }
          v3->size = v10;
          v13 = (signed __int64)&v3->p[v9];
          v14 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v8);
          if ( v14 && *(_QWORD *)v14 )
            v15 = (UFG::qPropertySet *)&v14[*(_QWORD *)v14];
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
        v4 = v28;
        v6 = v29;
      }
      v5 = v27 + 1;
      ++v27;
      ++v4;
      v28 = v4;
      v29 = --v6;
      v2 = v30;
    }
    while ( v6 );
  }
  `eh vector destructor iterator(&name, 4ui64, 4, (void (__fastcall *)(void *))_);
}

// File Line: 179
// RVA: 0x64CC0
void __fastcall Render::SkyMarshall::Init(Render::SkyMarshall *this)
{
  Render::SkyMarshall *v1; // rsi
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // eax
  Illusion::Material *v6; // rax
  Illusion::Material *v7; // rdi
  int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  UFG::TimeOfDayManager *v11; // rax
  int v12; // eax
  UFG::qResourceWarehouse *v13; // rax

  v1 = this;
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
  LODWORD(v7[1].mResourceHandles.mNode.mNext) = 157670756;
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
  LODWORD(v7[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v7[1].mNumParams = v10;
  v7[2].mNode.mUID = -1230328704;
  v11 = UFG::TimeOfDayManager::GetInstance();
  LODWORD(v3) = UFG::TimeOfDayManager::GetFogTexture(v11)->mNode.mUID;
  LOWORD(v7[2].mTypeUID) = 0;
  HIDWORD(v7[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("texFogCube", 0xFFFFFFFF);
  *((_DWORD *)&v7[2].0 + 22) = -1958479169;
  *(_DWORD *)&v7[2].mDebugName[28] = (_DWORD)v3;
  LODWORD(v7[2].mResourceHandles.mNode.mNext) = v12;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, (UFG::qResourceData *)&v7->mNode);
  Render::SkyMarshall::LoadSkydomeList(v1);
  Render::SkyMarshall::InitCloudResources(v1);
}

// File Line: 256
// RVA: 0x64530
void __fastcall Render::SkyMarshall::SkyMarshall(Render::SkyMarshall *this)
{
  Render::SkyMarshall *v1; // rbx
  signed int v2; // ecx
  UFG::qstream_typed<Illusion::Buffer> *v3; // rax
  UFG::qArray<Render::SkyMarshall::SkydomeResource,0> *v4; // rcx
  UFG::DataStreamer::Handle *v5; // [rsp+58h] [rbp+10h]

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mTexture.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mNoiseTexture.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mCloudMaterial.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mTestCloudMaterial.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mRimMaterial.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mWispModel.mPrev);
  v1->mEnableDome = 1;
  `eh vector constructor iterator(
    v1->mCloudSceneHandle,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Render::CloudSceneHandle::CloudSceneHandle);
  `eh vector constructor iterator(
    v1->mWispIndexBuffer,
    0x58ui64,
    17,
    (void (__fastcall *)(void *))Render::SkyMarshall::WispIndexBuffer::WispIndexBuffer);
  v2 = 127;
  v3 = &v1->mTaskInstance[0].mIndexBuffer;
  do
  {
    v3[-2].m_Stream = 0i64;
    v3->m_Stream = 0i64;
    v3 += 30;
    --v2;
  }
  while ( v2 >= 0 );
  v1->mBoundaryCloudSceneID = 4;
  v1->mSkydomeIndex = -1;
  v1->mNextSkydomeIndex = 0;
  *(_QWORD *)&v1->mLockSkydomeIndex = -1i64;
  *(_QWORD *)&v1->mSkydomeState = 2i64;
  v5 = &v1->mSkydomeHandle;
  v5->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v5->mPrev;
  v1->mSkydomeHandle.mCallback = 0i64;
  v1->mSkydomeHandle.mCallbackParam = 0i64;
  v1->mSkydomeHandle.mImpl = 0i64;
  *(_DWORD *)&v1->mSkydomeHandle.mFlags = 536870915;
  v1->mSkydomeHandle._mTargetState.mValue = 1;
  v4 = &v1->mSkydomeResources;
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  UFG::qArray<Render::SkyMarshall::SkydomeResource,0>::Reallocate(
    &v1->mSkydomeResources,
    0xAu,
    "qArray.Reallocate(Constructor)");
  v1->mLockSkydome = 0;
  *(_QWORD *)&v1->mFadeInDuration = 0i64;
  `eh vector constructor iterator(
    v1->mSkydomeModel,
    0x20ui64,
    6,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  v1->mNumSkydomeModels = 0;
  v1->mDebugDomeIndex = -1;
  v1->mDomeRotation = 0.0;
  v1->mCeilingUV[1].x = 0.5;
  v1->mCeilingUV[1].y = 0.5;
}

// File Line: 266
// RVA: 0x663E0
void __fastcall Render::SkyMarshall::SetSkydome(Render::SkyMarshall *this, UFG::qSymbol *skydomeName)
{
  unsigned int v2; // er11
  unsigned int v3; // er10
  int v4; // edx

  v2 = skydomeName->mUID;
  if ( skydomeName->mUID == -1 )
  {
    this->mLockSkydomeIndex = -1;
    this->mLockSkydome = 1;
    *(_QWORD *)&this->mFadeInDuration = 0i64;
  }
  else
  {
    v3 = this->mSkydomeResources.size;
    v4 = 0;
    if ( v3 )
    {
      while ( this->mSkydomeResources.p[v4].mNameUID.mUID != v2 )
      {
        if ( ++v4 >= v3 )
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
  Render::SkyMarshall *v2; // rbx
  int v3; // eax

  v2 = this;
  v3 = UFG::qRandom(this->mSkydomeTypeIndex[1] - this->mSkydomeTypeIndex[0], &UFG::qDefaultSeed);
  v2->mFadeInDuration = 30.0;
  v2->mFadeOutDuration = 30.0;
  v2->mNextSkydomeIndex = v3;
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
  Render::SkyMarshall::gSkyMarshall.mSkydomeState = 4;
}

// File Line: 320
// RVA: 0x67450
void __fastcall Render::SkyMarshall::Update(Render::SkyMarshall *this, float deltaT)
{
  Render::SkyMarshall *v2; // rbp
  float v3; // xmm7_4
  int v4; // eax
  Render::SkyMarshall::SkydomeState v5; // ecx
  Render::SkyMarshall::SkydomeState v6; // ecx
  int v7; // ecx
  int v8; // ecx
  float v9; // xmm1_4
  __int64 v10; // rax
  signed __int64 v11; // rsi
  unsigned int i; // edi
  UFG::qResourceInventory *v13; // rax
  unsigned int v14; // er14
  UFG::qResourceWarehouse *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  UFG::TransformNodeComponent *v22; // rbx
  __m128 v23; // xmm2
  float v24; // xmm6_4
  unsigned int v25; // eax
  signed __int64 v26; // rbx
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax
  float v29; // xmm6_4
  float v30; // xmm5_4
  unsigned int v31; // er14
  UFG::qResourceData **v32; // r15
  UFG::qResourceData *v33; // rdi
  unsigned int v34; // eax
  float v35; // xmm1_4
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  float v38; // xmm11_4
  __int64 v39; // rsi
  float v40; // xmm1_4
  float v41; // xmm12_4
  float v42; // xmm13_4
  float v43; // xmm11_4
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v44; // rax
  signed __int64 v45; // rcx
  signed __int64 v46; // rbx
  float v47; // xmm7_4
  float v48; // xmm8_4
  float v49; // xmm10_4
  float v50; // xmm9_4
  __m128 v51; // xmm2
  float v52; // xmm7_4
  float v53; // xmm5_4
  float v54; // xmm4_4
  float v55; // xmm3_4
  CullManager *v56; // rax
  CullInfo *v57; // rax
  unsigned int v58; // er8
  CullInfo *j; // rsi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v60; // rax
  signed __int64 v61; // rcx
  __int64 v62; // rdx
  signed __int64 v63; // rax
  signed __int64 v64; // rax
  _DWORD *v65; // rcx
  CullManager *v66; // rax
  __m128 v67; // xmm2
  float v68; // xmm1_4
  signed int v69; // ecx
  __m128 v70; // xmm3
  float v71; // xmm1_4
  signed int v72; // ecx
  __m128 v73; // xmm2
  float v74; // xmm1_4
  signed int v75; // ecx
  __m128 v76; // xmm3
  float v77; // xmm1_4
  signed int v78; // ecx
  __m128 v79; // xmm2
  float v80; // xmm1_4
  signed int v81; // ecx
  __m128 v82; // xmm2
  float v83; // xmm1_4
  signed int v84; // ecx
  float v85; // [rsp+118h] [rbp+10h]

  v85 = deltaT;
  v2 = this;
  v3 = deltaT;
  if ( this->mLockSkydome )
    v4 = this->mLockSkydomeIndex;
  else
    v4 = this->mNextSkydomeIndex;
  if ( v4 != this->mSkydomeIndex )
  {
    v5 = this->mSkydomeState;
    if ( (signed int)v5 <= 3 )
    {
      if ( (signed int)v5 >= 3 )
        goto LABEL_9;
    }
    else
    {
      v2->mSkydomeState = 0;
    }
    v2->mSkydomeIndex = v4;
  }
LABEL_9:
  v6 = v2->mSkydomeState;
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
          v9 = v2->mFadeInDuration;
          if ( v9 <= 0.0 )
            v2->mSkydomeOpacity = 1.0;
          else
            v2->mSkydomeOpacity = (float)(v3 / v9) + v2->mSkydomeOpacity;
          if ( v2->mSkydomeOpacity >= 1.0 )
          {
            v2->mSkydomeState = 5;
            v2->mSkydomeOpacity = 1.0;
          }
        }
      }
      else
      {
        v10 = (unsigned int)v2->mSkydomeIndex;
        if ( (signed int)v10 >= 0 && (signed int)v10 < (signed int)v2->mSkydomeResources.size )
        {
          v2->mSkydomeRotationIndex = v10;
          v11 = (signed __int64)&v2->mSkydomeResources.p[v10];
          UFG::DataStreamer::QueueStream(
            &v2->mSkydomeHandle,
            *(const char **)(v11 + 80),
            DATA_CLOUDS,
            DEFAULT_PRIORITY,
            3u,
            Render::SkyMarshall::TexturePackLoaded,
            0i64);
          v2->mSkydomeState = 3;
          for ( i = 0; i < *(_DWORD *)(v11 + 52); ++i )
          {
            v13 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            v14 = *(_DWORD *)(v11 + 8i64 * i + 4);
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v15 = UFG::qResourceWarehouse::Instance();
              v13 = UFG::qResourceWarehouse::GetInventory(v15, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v13;
            }
            UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mSkydomeModel[i].mPrev, 0xA2ADCD77, v14, v13);
          }
          v2->mNumSkydomeModels = *(_DWORD *)(v11 + 52);
        }
      }
    }
    else
    {
      UFG::DataStreamer::ReleaseStream(&v2->mSkydomeHandle);
      v2->mSkydomeState = 2;
    }
  }
  else
  {
    v16 = v2->mFadeOutDuration;
    if ( v16 <= 0.0 )
      v2->mSkydomeOpacity = 0.0;
    else
      v2->mSkydomeOpacity = v2->mSkydomeOpacity - (float)(deltaT / v16);
    if ( v2->mSkydomeOpacity <= 0.0 )
      *(_QWORD *)&v2->mSkydomeState = 1i64;
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
  v2->mEnviroScalar = v19;
  if ( LocalPlayer )
    v22 = LocalPlayer->m_pTransformNodeComponent;
  else
    v22 = 0i64;
  if ( v22 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v22);
    v23 = (__m128)LODWORD(v22->mWorldTransform.v3.y);
    v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0])
                            + (float)(v22->mWorldTransform.v3.x * v22->mWorldTransform.v3.x))
                    + (float)(v22->mWorldTransform.v3.z * v22->mWorldTransform.v3.z);
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
  }
  else
  {
    v24 = 0.0;
  }
  v25 = v2->mBoundaryCloudSceneID;
  if ( v25 == 4 )
  {
    if ( v24 > 2100.0 )
      v2->mBoundaryCloudSceneID = Render::SkyMarshall::LoadCloudScene(v2, "HK_BOUNDARY_scene");
  }
  else if ( v24 < 2100.0 )
  {
    v26 = v25;
    if ( v2->mCloudSceneHandle[v26].mData )
    {
      v27 = `UFG::qGetResourceInventory<Render::CloudScene>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::CloudScene>::`2::result )
      {
        v28 = UFG::qResourceWarehouse::Instance();
        v27 = UFG::qResourceWarehouse::GetInventory(v28, 0x4438A32Fu);
        `UFG::qGetResourceInventory<Render::CloudScene>::`2::result = v27;
      }
      UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mCloudSceneHandle[v26].mPrev, v27);
    }
    v2->mBoundaryCloudSceneID = 4;
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
  v2->mBoundaryCloudSceneOpacity = v29;
  v31 = 0;
  v32 = &v2->mCloudSceneHandle[0].mData;
  do
  {
    v33 = *v32;
    if ( *v32 )
    {
      v34 = (unsigned int)v33[1].mNode.mParent;
      v35 = v3 + *((float *)&v33[1].mNode.mParent + 1);
      *((float *)&v33[1].mNode.mParent + 1) = v35;
      if ( v34 )
      {
        if ( Render::SkyMarshall::sEnableClouds && Render::SkyMarshall::sEnableSpeed )
        {
          v36 = (__m128)LODWORD(Render::SkyMarshall::sCloudWindX);
          v37 = v36;
          v37.m128_f32[0] = (float)(v36.m128_f32[0] * v36.m128_f32[0])
                          + (float)(Render::SkyMarshall::sCloudWindY * Render::SkyMarshall::sCloudWindY);
          v38 = v37.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
          v39 = UFG::Metrics::msFrameCount & 3;
          v40 = (float)((float)(v35 * v30) * v30) * 1000.0;
          v41 = (float)((float)(v38 * Render::SkyMarshall::sCloudWindX) * v40) * Render::SkyMarshall::sCloudWindSpeed;
          v42 = (float)((float)(v38 * Render::SkyMarshall::sCloudWindY) * v40) * Render::SkyMarshall::sCloudWindSpeed;
          v43 = (float)((float)(v38 * 0.0) * v40) * Render::SkyMarshall::sCloudWindSpeed;
          if ( (unsigned int)v39 < v34 )
          {
            do
            {
              v44 = v33[1].mResourceHandles.mNode.mPrev;
              if ( v44 )
                v45 = (signed __int64)&v33[1].mResourceHandles + (_QWORD)v44;
              else
                v45 = 0i64;
              v46 = v45 + 192 * v39;
              if ( !*(_DWORD *)(v46 + 184) )
              {
                v47 = v42 + *(float *)(v46 + 100);
                v48 = v43 + *(float *)(v46 + 104);
                v49 = fmodf(
                        (float)(v41 + *(float *)(v46 + 96)) - *(float *)v33[1].mNode.mChild,
                        *((float *)&v33[1].mNode.mChild[1] + 1))
                    + *(float *)v33[1].mNode.mChild;
                v50 = fmodf(v47 - *((float *)v33[1].mNode.mChild + 1), *(float *)&v33[1].mNode.mUID)
                    + *((float *)v33[1].mNode.mChild + 1);
                v51 = 0i64;
                v51.m128_f32[0] = (float)1;
                v52 = fmodf(v48 - *(float *)&v33[1].mNode.mChild[1], *((float *)&v33[1].mNode.mUID + 1))
                    + *(float *)&v33[1].mNode.mChild[1];
                *(float *)(v46 + 48) = v49;
                *(float *)(v46 + 52) = v50;
                *(_DWORD *)(v46 + 60) = 1065353216;
                *(float *)(v46 + 56) = v52;
                v53 = 1.0 / *(float *)v46;
                v54 = 1.0 / *(float *)(v46 + 20);
                v55 = 1.0 / *(float *)(v46 + 40);
                *(__m128 *)(v46 + 108) = v51;
                *(__m128 *)(v46 + 124) = _mm_shuffle_ps(v51, v51, 81);
                *(__m128 *)(v46 + 140) = _mm_shuffle_ps(v51, v51, 69);
                *(__m128 *)(v46 + 156) = _mm_shuffle_ps(v51, v51, 21);
                *(float *)(v46 + 108) = v53;
                *(float *)(v46 + 128) = v54;
                *(float *)(v46 + 148) = v55;
                *(float *)(v46 + 156) = COERCE_FLOAT(LODWORD(v49) ^ _xmm[0]) * v53;
                *(_DWORD *)(v46 + 168) = 1065353216;
                *(float *)(v46 + 160) = COERCE_FLOAT(LODWORD(v50) ^ _xmm[0]) * v54;
                *(float *)(v46 + 164) = COERCE_FLOAT(LODWORD(v52) ^ _xmm[0]) * v55;
              }
              v39 = (unsigned int)(v39 + 4);
            }
            while ( (unsigned int)v39 < LODWORD(v33[1].mNode.mParent) );
            v3 = v85;
          }
        }
        v56 = CullManager::Instance();
        v57 = CullManager::AllocFrameCullInfos(v56, (int)v33[1].mNode.mParent);
        v58 = 0;
        for ( j = v57; v58 < LODWORD(v33[1].mNode.mParent); *(float *)((char *)&j->mAABBMax[2] + v62) = (float)v65[28] )
        {
          v60 = v33[1].mResourceHandles.mNode.mPrev;
          if ( v60 )
            v61 = (signed __int64)&v33[1].mResourceHandles + (_QWORD)v60;
          else
            v61 = 0i64;
          v62 = v58++;
          v63 = 3 * v62;
          v62 <<= 6;
          v64 = v61 + (v63 << 6);
          v65 = *(_DWORD **)(v64 + 80);
          *(float **)((char *)&j->mpLocalWorld + v62) = (float *)v64;
          *(_DWORD *)((char *)&j->mPixelScaleBias + v62) = -131072;
          *(float *)((char *)j->mAABBMin + v62) = (float)v65[23];
          *(float *)((char *)&j->mAABBMin[1] + v62) = (float)v65[24];
          *(float *)((char *)&j->mAABBMin[2] + v62) = (float)v65[25];
          *(float *)((char *)j->mAABBMax + v62) = (float)v65[26];
          *(float *)((char *)&j->mAABBMax[1] + v62) = (float)v65[27];
        }
        v66 = CullManager::Instance();
        CullManager::AllocPrebuiltFrameCullInfos(v66, &v2->mCullResults[v31], (int)v33[1].mNode.mParent, j, 0i64);
        v30 = FLOAT_0_016666668;
      }
    }
    ++v31;
    v32 += 4;
  }
  while ( v31 < 4 );
  v67 = (__m128)LODWORD(Render::SkyMarshall::sCeilingSpeed[0]);
  v67.m128_f32[0] = (float)(Render::SkyMarshall::sCeilingSpeed[0] * v3) + v2->mCeilingUV[0].x;
  v68 = v67.m128_f32[0];
  v69 = (signed int)v67.m128_f32[0];
  if ( (signed int)v67.m128_f32[0] != 0x80000000 && (float)v69 != v67.m128_f32[0] )
    v68 = (float)(v69 - (_mm_movemask_ps(_mm_unpacklo_ps(v67, v67)) & 1));
  v2->mCeilingUV[0].x = v67.m128_f32[0] - v68;
  v70 = (__m128)(unsigned int)dword_142024054;
  v70.m128_f32[0] = (float)(*(float *)&dword_142024054 * v3) + v2->mCeilingUV[0].y;
  v71 = v70.m128_f32[0];
  v72 = (signed int)v70.m128_f32[0];
  if ( (signed int)v70.m128_f32[0] != 0x80000000 && (float)v72 != v70.m128_f32[0] )
    v71 = (float)(v72 - (_mm_movemask_ps(_mm_unpacklo_ps(v70, v70)) & 1));
  v2->mCeilingUV[0].y = v70.m128_f32[0] - v71;
  v73 = (__m128)(unsigned int)dword_142024058;
  v73.m128_f32[0] = (float)(*(float *)&dword_142024058 * v3) + v2->mCeilingUV[1].x;
  v74 = v73.m128_f32[0];
  v75 = (signed int)v73.m128_f32[0];
  if ( (signed int)v73.m128_f32[0] != 0x80000000 && (float)v75 != v73.m128_f32[0] )
    v74 = (float)(v75 - (_mm_movemask_ps(_mm_unpacklo_ps(v73, v73)) & 1));
  v2->mCeilingUV[1].x = v73.m128_f32[0] - v74;
  v76 = (__m128)(unsigned int)dword_14202405C;
  v76.m128_f32[0] = (float)(*(float *)&dword_14202405C * v3) + v2->mCeilingUV[1].y;
  v77 = v76.m128_f32[0];
  v78 = (signed int)v76.m128_f32[0];
  if ( (signed int)v76.m128_f32[0] != 0x80000000 && (float)v78 != v76.m128_f32[0] )
    v77 = (float)(v78 - (_mm_movemask_ps(_mm_unpacklo_ps(v76, v76)) & 1));
  v2->mCeilingUV[1].y = v76.m128_f32[0] - v77;
  v79 = (__m128)LODWORD(Render::SkyMarshall::sDomeSpeed);
  v79.m128_f32[0] = (float)(Render::SkyMarshall::sDomeSpeed * v3) + v2->mDomeUVOffset;
  v80 = v79.m128_f32[0];
  v81 = (signed int)v79.m128_f32[0];
  if ( (signed int)v79.m128_f32[0] != 0x80000000 && (float)v81 != v79.m128_f32[0] )
    v80 = (float)(v81 - (_mm_movemask_ps(_mm_unpacklo_ps(v79, v79)) & 1));
  v2->mDomeUVOffset = v79.m128_f32[0] - v80;
  v82 = (__m128)LODWORD(Render::SkyMarshall::sOuterDomeSpeed);
  v82.m128_f32[0] = (float)(Render::SkyMarshall::sOuterDomeSpeed * v3) + v2->mOuterDomeUVOffset;
  v83 = v82.m128_f32[0];
  v84 = (signed int)v82.m128_f32[0];
  if ( (signed int)v82.m128_f32[0] != 0x80000000 && (float)v84 != v82.m128_f32[0] )
    v83 = (float)(v84 - (_mm_movemask_ps(_mm_unpacklo_ps(v82, v82)) & 1));
  v2->mOuterDomeUVOffset = v82.m128_f32[0] - v83;
  v2->mDomeRotation = (float)(v3 * 0.0049999999) + v2->mDomeRotation;
}

// File Line: 533
// RVA: 0x65C40
void __fastcall Render::SkyMarshall::RenderCloudDome(Render::SkyMarshall *this, Render::View *pView, float fidelity)
{
  Render::View *v3; // r15
  Render::SkyMarshall *v4; // rdi
  UFG::qResourceData *v5; // rbx
  Illusion::StateValues *v6; // rax
  unsigned int v7; // ebp
  char *v8; // rax
  char *v9; // rbx
  int v10; // xmm0_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  int v13; // xmm0_4
  unsigned int v14; // esi
  Illusion::StateValues *v15; // rax
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-88h]

  v3 = pView;
  v4 = this;
  if ( !(_S1_11 & 1) )
  {
    _S1_11 |= 1u;
    ceilingSettingsIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                               &Illusion::gStateSystem,
                                               sCeilingSettingsUID,
                                               sCeilingSettingsName,
                                               0);
  }
  if ( v4->mEnableDome )
  {
    if ( (unsigned int)(v4->mSkydomeState - 1) > 2 )
    {
      v5 = v4->mNoiseTexture.mData;
      v6 = Render::View::GetStateValues(v3);
      v6->mSetValueMask.mFlags[0] |= 0x40000000000ui64;
      v6->mParamValues[42] = v5;
      v7 = 0;
      if ( v4->mNumSkydomeModels )
      {
        do
        {
          dest = UFG::qMatrix44::msIdentity;
          UFG::qRotationMatrixZ(
            &dest,
            COERCE_FLOAT(COERCE_UNSIGNED_INT(
                           v4->mSkydomeResources.p->modelResource[v7 + 12i64 * (unsigned int)v4->mSkydomeRotationIndex].rotation
                         * v4->mDomeRotation) ^ _xmm[0]));
          dest.v3.x = v3->mViewWorld.v3.x;
          dest.v3.y = v3->mViewWorld.v3.y;
          dest.v3.z = v3->mViewWorld.v3.z;
          dest.v3.w = 1.0;
          v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
          v9 = v8;
          *(float *)v8 = v4->mDomeUVOffset;
          *((float *)v8 + 1) = Render::SkyMarshall::sRimIntensity;
          if ( Render::SkyMarshall::sDisplayHighlight )
            v10 = (signed int)FLOAT_1_0;
          else
            v10 = 0;
          *((_DWORD *)v8 + 4) = v10;
          if ( Render::SkyMarshall::sDisplayFog )
            v11 = (signed int)FLOAT_1_0;
          else
            v11 = 0;
          *((_DWORD *)v8 + 5) = v11;
          if ( Render::SkyMarshall::sDisplayDirect )
            v12 = (signed int)FLOAT_1_0;
          else
            v12 = 0;
          *((_DWORD *)v8 + 6) = v12;
          if ( Render::SkyMarshall::sDisplayHalo )
            v13 = (signed int)FLOAT_1_0;
          else
            v13 = 0;
          *((_DWORD *)v8 + 7) = v13;
          *((_DWORD *)v8 + 8) = LODWORD(v4->mSkydomeOpacity);
          *((_DWORD *)v8 + 12) = LODWORD(v4->mCeilingUV[0].x);
          *((_DWORD *)v8 + 13) = LODWORD(v4->mCeilingUV[0].y);
          *((_DWORD *)v8 + 14) = LODWORD(v4->mCeilingUV[1].x);
          *((_DWORD *)v8 + 15) = LODWORD(v4->mCeilingUV[1].y);
          *((float *)v8 + 16) = Render::SkyMarshall::sFlowmapSpeed;
          *((float *)v8 + 17) = Render::SkyMarshall::sFlowmapIntensity;
          *((float *)v8 + 18) = Render::SkyMarshall::sFlowmapOffset;
          *((float *)v8 + 19) = Render::SkyMarshall::sFlowmapNoise;
          v14 = (signed __int16)ceilingSettingsIndex;
          v15 = Render::View::GetStateValues(v3);
          if ( v14 >= 0x40 )
            v15->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v14 - 64);
          else
            v15->mSetValueMask.mFlags[0] |= 1i64 << v14;
          v15->mParamValues[(signed __int16)v14] = v9;
          Render::View::Draw(v3, &v4->mSkydomeModel[v7++], &dest, 0);
        }
        while ( v7 < v4->mNumSkydomeModels );
      }
    }
  }
}

// File Line: 582
// RVA: 0x65F40
void __fastcall Render::SkyMarshall::RenderFar(Render::SkyMarshall *this, Render::View *pView, float fidelity)
{
  Render::View *v3; // rdi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm9_4
  float v14; // xmm10_4
  float v15; // xmm11_4
  float v16; // xmm12_4
  float v17; // xmm13_4
  float v18; // xmm14_4
  float v19; // xmm15_4
  UFG::BaseCameraComponent *v20; // rax
  float v21; // xmm2_4
  __m128 v22; // xmm1
  float v23; // xmm3_4
  float v24; // xmm0_4
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-B8h]
  unsigned int v26; // [rsp+130h] [rbp+38h]

  v3 = pView;
  v4 = _S2_2;
  if ( !(_S2_2 & 1) )
  {
    _S2_2 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&hMatSky.mPrev);
    atexit(Render::SkyMarshall::RenderFar_::_2_::_dynamic_atexit_destructor_for__hMatSky__);
    v4 = _S2_2;
  }
  if ( !hMatSky.mData )
  {
    v5 = UFG::qStringHashUpper32("DR_SkyboxMaterial", 0xFFFFFFFF);
    v6 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v6;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&hMatSky.mPrev, 0xB4C26312, v5, v6);
    v4 = _S2_2;
  }
  v8 = UFG::qMatrix44::msIdentity.v0.x;
  v9 = UFG::qMatrix44::msIdentity.v0.y;
  v10 = UFG::qMatrix44::msIdentity.v0.z;
  v11 = UFG::qMatrix44::msIdentity.v0.w;
  local_world = UFG::qMatrix44::msIdentity;
  v12 = UFG::qMatrix44::msIdentity.v1.x;
  v13 = UFG::qMatrix44::msIdentity.v1.y;
  v14 = UFG::qMatrix44::msIdentity.v1.z;
  v15 = UFG::qMatrix44::msIdentity.v1.w;
  v16 = UFG::qMatrix44::msIdentity.v2.x;
  v17 = UFG::qMatrix44::msIdentity.v2.y;
  v18 = UFG::qMatrix44::msIdentity.v2.z;
  v19 = UFG::qMatrix44::msIdentity.v2.w;
  if ( v4 & 2 )
  {
    v24 = kSkyBoxScale;
  }
  else
  {
    _S2_2 = v4 | 2;
    v20 = UFG::Director::Get()->mCurrentCamera;
    if ( v20 )
      v20 = (UFG::BaseCameraComponent *)((char *)v20 + 80);
    v21 = v20->mCamera.mTransformation.v1.z;
    v22 = (__m128)LODWORD(v20->mCamera.mTransformation.v2.z);
    v23 = v20->mCamera.mTransformation.v1.w;
    if ( v21 == 0.0 || v21 == v23 )
      v22 = (__m128)v26;
    else
      v22.m128_f32[0] = (float)(v22.m128_f32[0] - v20->mCamera.mTransformation.v2.w) / (float)(v21 - v23);
    v22.m128_f32[0] = (float)(v22.m128_f32[0] * v22.m128_f32[0]) * 0.33333334;
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v22);
    kSkyBoxScale = v24;
    v19 = local_world.v2.w;
    v18 = local_world.v2.z;
    v17 = local_world.v2.y;
    v16 = local_world.v2.x;
    v15 = local_world.v1.w;
    v14 = local_world.v1.z;
    v13 = local_world.v1.y;
    v12 = local_world.v1.x;
    v11 = local_world.v0.w;
    v10 = local_world.v0.z;
    v9 = local_world.v0.y;
    v8 = local_world.v0.x;
  }
  local_world.v0.x = v8 * v24;
  local_world.v0.y = v9 * v24;
  local_world.v0.z = v10 * v24;
  local_world.v0.w = v11 * v24;
  local_world.v1.x = v12 * v24;
  local_world.v1.y = v13 * v24;
  local_world.v1.z = v14 * v24;
  local_world.v1.w = v15 * v24;
  local_world.v2.x = v16 * v24;
  local_world.v2.y = v17 * v24;
  local_world.v2.z = v18 * v24;
  local_world.v2.w = v19 * v24;
  local_world.v3.x = v3->mViewWorld.v3.x;
  local_world.v3.y = v3->mViewWorld.v3.y;
  local_world.v3.z = v3->mViewWorld.v3.z;
  LODWORD(local_world.v3.w) = (_DWORD)FLOAT_1_0;
  Render::View::Draw(v3, &gDeferredCube, &local_world, 0);
}

// File Line: 604
// RVA: 0x67300
void __fastcall Render::SkyMarshall::SyncFlushDrawCloudTask(Render::SkyMarshall *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // rbx
  SimpleTaskRenderResults *v3; // r8
  SimpleTaskRenderResults *v4; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v5; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v6; // rcx

  v2 = serialization_list;
  if ( Render::gCloudTask )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, Render::gCloudTask);
    v3 = Render::gCloudSortTaskParams->mMainMemCloudRenderResults;
    v4 = (SimpleTaskRenderResults *)v3->mPendingQueues.mNode.mNext;
    if ( v4 != v3 )
    {
      v5 = v2->mNode.mPrev;
      v6 = v3->mPendingQueues.mNode.mPrev;
      v5->mNext = &v4->mPendingQueues.mNode;
      v4->mPendingQueues.mNode.mPrev = v5;
      v6->mNext = &v2->mNode;
      v2->mNode.mPrev = v6;
      v3->mPendingQueues.mNode.mPrev = &v3->mPendingQueues.mNode;
      v3->mPendingQueues.mNode.mNext = &v3->mPendingQueues.mNode;
    }
    Render::gCloudRenderLayer.mSerializationList = v2;
    RenderQueueLayer::SerializeRenderQueues(&Render::gCloudRenderLayer);
    Render::gCloudRenderLayer.mSerializationList = 0i64;
  }
}

// File Line: 642
// RVA: 0x656B0
signed __int64 __fastcall Render::SkyMarshall::LoadCloudScene(Render::SkyMarshall *this, const char *sceneName)
{
  const char *v2; // rbp
  Render::SkyMarshall *v3; // r14
  unsigned int v4; // eax
  unsigned int v5; // edi
  signed __int64 v6; // r8
  unsigned int v7; // esi
  const char *v8; // rcx
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  signed __int64 v12; // rbx
  UFG::qResourceData *v13; // rax

  v2 = sceneName;
  v3 = this;
  v4 = UFG::qStringHashUpper32(sceneName, 0xFFFFFFFF);
  v5 = 0;
  v6 = (signed __int64)&v3->mCloudSceneHandle[0].mData;
  v7 = v4;
  while ( *(_QWORD *)v6 )
  {
    if ( *(_DWORD *)(v6 + 8) == v4 )
    {
      v8 = "Cloud scene %s already loaded.\n";
      goto LABEL_6;
    }
    ++v5;
    v6 += 32i64;
    if ( v5 >= 4 )
      goto LABEL_5;
  }
  if ( v5 >= 4 )
  {
LABEL_5:
    v8 = "Cannot load cloud scene %s; Exceeded max number of cloud scene slots.\n";
LABEL_6:
    UFG::qPrintf(v8, v2, v6);
    return 4i64;
  }
  v10 = `UFG::qGetResourceInventory<Render::CloudScene>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CloudScene>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x4438A32Fu);
    `UFG::qGetResourceInventory<Render::CloudScene>::`2::result = v10;
  }
  v12 = v5;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mCloudSceneHandle[v12].mPrev, 0x4438A32Fu, v7, v10);
  v13 = v3->mCloudSceneHandle[v12].mData;
  if ( !v13 )
  {
    v8 = "Cannot load cloud scene %s; Check CloudScenePack.xml\n";
    goto LABEL_6;
  }
  HIDWORD(v13[1].mNode.mParent) = 0;
  return v5;
}

// File Line: 683
// RVA: 0x67390
void __fastcall Render::SkyMarshall::UnloadCloudScene(Render::SkyMarshall *this, const char *sceneName)
{
  const char *v2; // rdi
  Render::SkyMarshall *v3; // rsi
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int *v6; // r8
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = sceneName;
  v3 = this;
  v4 = UFG::qStringHashUpper32(sceneName, 0xFFFFFFFF);
  v5 = 0;
  v6 = &v3->mCloudSceneHandle[0].mNameUID;
  while ( !*((_QWORD *)v6 - 1) || *v6 != v4 )
  {
    ++v5;
    v6 += 8;
    if ( v5 >= 4 )
    {
      UFG::qPrintf("Cannot unload cloud scene %s; not found.\n", v2, v6);
      return;
    }
  }
  v7 = `UFG::qGetResourceInventory<Render::CloudScene>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CloudScene>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x4438A32Fu);
    `UFG::qGetResourceInventory<Render::CloudScene>::`2::result = v7;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mCloudSceneHandle[v5].mPrev, v7);
}

// File Line: 713
// RVA: 0x64C20
CloudSortTaskParamIndices *__fastcall Render::GetCloudSortTaskParamIndices()
{
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned __int16 v3; // ax

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
    v3 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, v2);
    isInitialized_0 = 1;
    paramIndices_0.paramIndex_cbInstancing = v3;
  }
  return &paramIndices_0;
}

// File Line: 742
// RVA: 0x654A0
void __fastcall Render::SkyMarshall::InitWispModel(Render::SkyMarshall *this)
{
  Render::SkyMarshall *v1; // r14
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // rbp
  UFG::qBaseNodeRB *v4; // rax
  _QWORD *v5; // rcx
  char *v6; // rdi
  int v7; // edx
  unsigned int v8; // ebx
  Illusion::Buffer *v9; // rax
  UFG::qResourceData *v10; // rsi
  __int64 v11; // rax
  signed __int64 v12; // rcx
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qString alloc_name; // [rsp+48h] [rbp-40h]

  v1 = this;
  v2 = Illusion::Factory::NewModel("SkyMarshall.TheWisp", 0xA952ACC5, 1u, 0i64, 0i64, 0i64);
  v3 = v2;
  v4 = v2[2].mNode.mChild[0];
  if ( v4 )
    v5 = (UFG::qBaseNodeRB **)((char *)v3[2].mNode.mChild + (_QWORD)v4);
  else
    v5 = 0i64;
  v6 = (char *)v5 + *v5;
  if ( !*v5 )
    v6 = 0i64;
  UFG::qString::qString(&alloc_name, "SkyMarshall.TheWisp.VertexBuffer");
  v8 = alloc_name.mStringHash32;
  if ( alloc_name.mStringHash32 == -1 )
  {
    v8 = UFG::qStringHash32(alloc_name.mData, alloc_name.mStringHash32 | v7);
    alloc_name.mStringHash32 = v8;
  }
  *((_QWORD *)v6 + 28) = 3i64;
  *((_DWORD *)v6 + 58) = 2;
  v9 = Illusion::Factory::NewBuffer(alloc_name.mData, v8, 0x40u, 0i64, alloc_name.mData, 0i64, 0i64);
  v10 = (UFG::qResourceData *)v9;
  v9->mBufferType = 0;
  v9->mElementByteSize = 16;
  v9->mNumElements = 4;
  v11 = v9->mData.mOffset;
  if ( v11 )
    v12 = (signed __int64)v10[1].mNode.mChild + v11;
  else
    v12 = 0i64;
  *(_DWORD *)v12 = -1090519040;
  *(_DWORD *)(v12 + 4) = -1090519040;
  *(_DWORD *)(v12 + 8) = 0;
  *(_DWORD *)(v12 + 12) = 1048576000;
  *(_DWORD *)(v12 + 16) = 1056964608;
  *(_DWORD *)(v12 + 20) = -1090519040;
  *(_DWORD *)(v12 + 24) = 1048576000;
  *(_DWORD *)(v12 + 28) = 1048576000;
  *(_DWORD *)(v12 + 32) = 1056964608;
  *(_DWORD *)(v12 + 36) = 1056964608;
  *(_QWORD *)(v12 + 40) = 1048576000i64;
  *(_DWORD *)(v12 + 48) = -1090519040;
  *(_QWORD *)(v12 + 52) = 1056964608i64;
  *(_DWORD *)(v12 + 60) = 0;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v10);
  *((_QWORD *)v6 + 30) = "SkyMarshall.TheWisp";
  *((_DWORD *)v6 + 30) = v8;
  *((_DWORD *)v6 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gCloudWispDescriptor);
  v14 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v14;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mWispModel.mPrev, 0xA2ADCD77, 0xA952ACC5, v14);
  UFG::qString::~qString(&alloc_name);
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, v3);
}

// File Line: 797
// RVA: 0x64F50
void __fastcall Render::SkyMarshall::InitCloudResources(Render::SkyMarshall *this)
{
  Render::SkyMarshall *v1; // rsi
  unsigned int v2; // er14
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  _WORD *v8; // rbp
  UFG::qResourceData *v9; // rax
  UFG::qResourceData *v10; // rbx
  UFG::qResourceWarehouse *v11; // rax
  unsigned int v12; // er15
  Illusion::Material *v13; // rdi
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  UFG::TimeOfDayManager *v18; // rax
  int v19; // eax
  unsigned int v20; // eax
  UFG::qResourceWarehouse *v21; // rax
  __int64 v22; // rax
  _WORD *v23; // rax
  __int64 v24; // rax
  UFG::qResourceInventory *v25; // rax
  UFG::qResourceWarehouse *v26; // rax
  unsigned int (*v27)[512]; // rax
  signed __int64 v28; // rcx

  v1 = this;
  v2 = UFG::qStringHashUpper32("SKY_Clouds_001", 0xFFFFFFFF);
  v3 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mTexture.mPrev, 0x8B43FABF, v2, v3);
  v5 = UFG::qStringHashUpper32("SKY_Noise_001", 0xFFFFFFFF);
  v6 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mNoiseTexture.mPrev, 0x8B43FABF, v5, v6);
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
  LODWORD(v13[1].mResourceHandles.mNode.mNext) = (_DWORD)v10;
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
  LODWORD(v13[2].mResourceHandles.mNode.mPrev) = 315097330;
  v13[2].mNode.mUID = 1185461225;
  v13[1].mNumParams = v16;
  LOWORD(v13[2].mTypeUID) = 0;
  HIDWORD(v13[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v13[2].0 + 22) = 1002903008;
  *(_DWORD *)&v13[2].mDebugName[28] = 1099738947;
  LODWORD(v13[2].mResourceHandles.mNode.mNext) = v17;
  v18 = UFG::TimeOfDayManager::GetInstance();
  LODWORD(v10) = UFG::TimeOfDayManager::GetFogTexture(v18)->mNode.mUID;
  LOWORD(v13[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v13[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v19 = UFG::qStringHash32("texFogCube", 0xFFFFFFFF);
  LODWORD(v13[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v13[3].mNode.mChild[0]) = (_DWORD)v10;
  LODWORD(v13[2].mStateBlockMask.mFlags[0]) = v19;
  LODWORD(v10) = UFG::qStringHashUpper32("CloudGradient", 0xFFFFFFFF);
  LOWORD(v13[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v13[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v13[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v13[3].mDebugName[12] = (_DWORD)v10;
  v13[3].mNode.mUID = v20;
  v21 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v21, (UFG::qResourceData *)&v13->mNode);
  if ( v13[2].mNode.mUID != 1185461225 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v13[2],
      (unsigned int)v13[2].mResourceHandles.mNode.mPrev,
      0x46A8B3E9u);
    v22 = v13->mMaterialUser.mOffset;
    if ( v22 )
      v23 = (_WORD *)((char *)&v13->mMaterialUser + v22);
    else
      v23 = 0i64;
    *v23 |= 0x20u;
  }
  if ( *(_DWORD *)&v13[2].mDebugName[28] != 1099738947 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v13[2].mDebugName[4], *((_DWORD *)&v13[2].0 + 22), 0x418CAF43u);
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
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mCloudMaterial.mPrev, 0xB4C26312, v12, v25);
  Render::SkyMarshall::InitWispModel(v1);
  Render::SkyMarshall::InitIndexBuffers(v1);
  v27 = v1->mCloudInstanceBuffer;
  v28 = 128i64;
  do
  {
    *(_QWORD *)v27 = 68719476752i64;
    *(_QWORD *)&(*v27)[2] = 68719476752i64;
    *(_QWORD *)&(*v27)[4] = 68719476752i64;
    v27 = (unsigned int (*)[512])((char *)v27 + 64);
    *(_QWORD *)&(*v27)[-10] = 68719476752i64;
    *(_QWORD *)&(*v27)[-8] = 68719476752i64;
    *(_QWORD *)&(*v27)[-6] = 68719476752i64;
    *(_QWORD *)&(*v27)[-4] = 68719476752i64;
    *(_QWORD *)&(*v27)[-2] = 68719476752i64;
    --v28;
  }
  while ( v28 );
}

// File Line: 926
// RVA: 0x64B90
bool __fastcall Render::SkyMarshall::CloudDistanceCompare(Render::SkyMarshall::CloudInstanceID *a, Render::SkyMarshall::CloudInstanceID *b)
{
  Render::SkyMarshall::CloudInstanceID *v2; // r11
  UFG::qResourceData *v3; // r9
  UFG::qResourceData *v4; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  signed __int64 v6; // r10
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  signed __int64 v8; // r9

  v2 = a;
  v3 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[b->mSceneIndex].mData;
  v4 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[a->mSceneIndex].mData;
  v5 = v4[1].mResourceHandles.mNode.mPrev;
  v6 = (signed __int64)&v4[1].mResourceHandles + (_QWORD)v5;
  if ( !v5 )
    v6 = 0i64;
  v7 = v3[1].mResourceHandles.mNode.mPrev;
  if ( v7 )
    v8 = (signed __int64)&v3[1].mResourceHandles + (_QWORD)v7;
  else
    v8 = 0i64;
  return *(float *)(192i64 * v2->mInstanceIndex + v6 + 180) < *(float *)(192i64 * b->mInstanceIndex + v8 + 180);
}

// File Line: 934
// RVA: 0x65370
void __fastcall Render::SkyMarshall::InitIndexBuffers(Render::SkyMarshall *this)
{
  Render::SkyMarshall *v1; // rbp
  int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // ebx
  Illusion::Buffer *v5; // rax
  UFG::qResourceData *v6; // rdi
  UFG::qResourceWarehouse *v7; // rax
  unsigned int *v8; // rax
  UFG::qString v9; // [rsp+48h] [rbp-30h]

  v1 = this;
  if ( !(_S3_1 & 1) )
  {
    _S3_1 |= 1u;
    index_buffer_size = index_buffer_elements << 10;
  }
  UFG::qString::qString(&v9, "SkyMarshall.IndexBufferDefault");
  v3 = v9.mStringHash32;
  if ( v9.mStringHash32 == -1 )
  {
    v3 = UFG::qStringHash32(v9.mData, v9.mStringHash32 | v2);
    v9.mStringHash32 = v3;
  }
  v4 = 0;
  v5 = Illusion::Factory::NewBuffer(v9.mData, v3, index_buffer_size, 0i64, "SkyMarshall.IndexBuffer", 0i64, 0i64);
  v6 = (UFG::qResourceData *)v5;
  v5->mNumElements = index_buffer_elements << 9;
  v5->mBufferType = 1;
  v5->mElementByteSize = 2;
  v5->mFlags |= 2u;
  v7 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v7, v6);
  Render::SkyMarshall::WispIndexBuffer::InitBufferHandles(&v1->mWispIndexBuffer[16], v3, v3);
  Render::SkyMarshall::WispIndexBuffer::Reset(&v1->mWispIndexBuffer[16], 0x200u);
  UFG::qString::~qString(&v9);
  v8 = v1->mAvailableBuffers;
  do
  {
    *v8 = v4++;
    ++v8;
  }
  while ( v4 < 0x10 );
}

// File Line: 1030
// RVA: 0x64EB0
void __fastcall Render::SkyMarshall::WispIndexBuffer::InitBufferHandles(Render::SkyMarshall::WispIndexBuffer *this, unsigned int bufferA, unsigned int bufferB)
{
  UFG::qResourceInventory *v3; // rax
  unsigned int v4; // esi
  unsigned int v5; // edi
  Render::SkyMarshall::WispIndexBuffer *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  v3 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  v4 = bufferB;
  v5 = bufferA;
  v6 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v7, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)v6->mBufferHandle, 0x92CDEC8F, v5, v3);
  v8 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v8;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mBufferHandle[1].mPrev, 0x92CDEC8F, v4, v8);
}

// File Line: 1036
// RVA: 0x66300
char __fastcall Render::SkyMarshall::WispIndexBuffer::Reset(Render::SkyMarshall::WispIndexBuffer *this, unsigned int numWisps)
{
  unsigned int v2; // esi
  Render::SkyMarshall::WispIndexBuffer *v3; // rdi
  signed __int16 v5; // bx
  UFG::qResourceData *v6; // rbp
  _WORD *v7; // rax
  unsigned __int16 v8; // r9
  unsigned __int16 v9; // r10
  __int64 v10; // rdx
  __int16 v11; // cx

  v2 = numWisps;
  v3 = this;
  if ( numWisps == this->mNumWisps )
    return 0;
  v5 = 1;
  v6 = this->mBufferHandle[Render::SkyMarshall::WispIndexBuffer::mActiveBuffer].mData;
  v7 = Illusion::IBufferPlat::Lock((Illusion::IBufferPlat *)v6, LOCK_OVERWRITE);
  v8 = 0;
  if ( v2 )
  {
    v9 = 0;
    do
    {
      v10 = v9;
      ++v8;
      v7[v10 + 2] = v5 + 2;
      v7[v10 + 3] = v5 + 2;
      v11 = v5 - 1;
      v7[v10 + 5] = v5 + 1;
      v7[v10 + 1] = v5;
      v7[v10 + 4] = v5;
      v9 += 6;
      v5 += 4;
      v7[v10] = v11;
    }
    while ( v8 < v2 );
  }
  Illusion::IBufferPlat::Unlock((Illusion::IBufferPlat *)v6);
  v3->mNumWisps = v2;
  v3->mNewestBuffer = Render::SkyMarshall::WispIndexBuffer::mActiveBuffer;
  v3->mOutOfSync = 1;
  return 1;
}

// File Line: 1127
// RVA: 0x66470
void __fastcall Render::SkyMarshall::SubmitCloudTask(Render::SkyMarshall *this, UFG::RenderContext *render_context, CB_EnvironmentSettings *pEnvSettings)
{
  UFG::RenderContext *v3; // rbx
  Render::SkyMarshall *v4; // r15
  float v5; // xmm1_4
  signed int v6; // er13
  unsigned int v7; // edx
  CullResults **v8; // r11
  UFG::qResourceData **v9; // r10
  UFG::qResourceData *v10; // r8
  unsigned int v11; // ecx
  CullResults *v12; // r9
  __int64 v13; // rax
  unsigned int v14; // er10
  __int64 v15; // rdx
  unsigned int v16; // eax
  __int64 v17; // r9
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v18; // rcx
  char *v19; // r8
  float *v20; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v21; // rcx
  char *v22; // r8
  float *v23; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v24; // rcx
  char *v25; // r8
  float *v26; // rcx
  UFG::qResourceData *v27; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v28; // rax
  signed __int64 v29; // r8
  float *v30; // rcx
  unsigned __int16 *v31; // r8
  __int64 v32; // r9
  UFG::qResourceData *v33; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v34; // rax
  signed __int64 v35; // rdx
  float *v36; // rcx
  Render::SkyMarshall::CloudInstanceID *v37; // r12
  signed __int64 v38; // rax
  signed __int64 v39; // rcx
  Render::SkyMarshall::CloudInstanceID *v40; // rbx
  float v41; // eax
  Render::SkyMarshall::CloudInstanceID v42; // eax
  Render::SkyMarshall::CloudInstanceID v43; // eax
  Render::SkyMarshall::CloudInstanceID v44; // eax
  Render::SkyMarshall::CloudInstanceID *v45; // rbx
  Render::SkyMarshall::CloudInstanceID *v46; // rdx
  UFG::qResourceData *v47; // r10
  signed __int64 v48; // r14
  UFG::qResourceData *v49; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v50; // rax
  signed __int64 v51; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v52; // rax
  signed __int64 v53; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v54; // rsi
  UFG::qResourceData *v55; // rcx
  signed __int64 v56; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v57; // rax
  signed __int64 v58; // r8
  Render::SkyMarshall::CloudInstanceID v59; // eax
  signed __int64 v60; // r12
  int *v61; // r15
  int v62; // eax
  signed __int64 v63; // r9
  unsigned __int16 v64; // dx
  UFG::qResourceData *v65; // r10
  signed __int64 v66; // rsi
  unsigned __int16 *v67; // r8
  UFG::qResourceData *v68; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v69; // rcx
  signed __int64 v70; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v71; // rcx
  signed __int64 v72; // rbx
  UFG::qResourceData *v73; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v74; // rcx
  signed __int64 v75; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v76; // rcx
  signed __int64 v77; // rbx
  UFG::qResourceData *v78; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v79; // rcx
  signed __int64 v80; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v81; // rcx
  signed __int64 v82; // rbx
  UFG::qResourceData *v83; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v84; // rcx
  signed __int64 v85; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v86; // rcx
  signed __int64 v87; // rbx
  UFG::qResourceData *v88; // rbx
  signed __int64 v89; // rsi
  UFG::qResourceData *v90; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v91; // rcx
  signed __int64 v92; // r10
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v93; // rcx
  signed __int64 v94; // r8
  signed int v95; // eax
  __int64 v96; // rsi
  unsigned int v97; // er13
  int v98; // er14
  unsigned __int16 *v99; // r12
  int v100; // er8
  UFG::qResourceData *v101; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v102; // rax
  signed __int64 v103; // rdx
  signed __int64 local_world; // rsi
  __int64 v105; // rdx
  __int64 v106; // r10
  signed __int64 v107; // rcx
  UFG::qVector4 v108; // xmm2
  UFG::qVector4 v109; // xmm1
  UFG::qVector4 v110; // xmm0
  UFG::qVector4 v111; // xmm2
  UFG::qVector4 v112; // xmm1
  UFG::qVector4 v113; // xmm0
  float v114; // xmm0_4
  float v115; // xmm1_4
  float v116; // xmm1_4
  float v117; // xmm2_4
  UFG::qVector3 *v118; // r13
  float v119; // xmm1_4
  float v120; // xmm2_4
  float v121; // xmm1_4
  float v122; // xmm2_4
  _QWORD *v123; // rax
  __int64 v124; // r8
  signed __int64 v125; // rax
  UFG::qResourceData *v126; // r8
  UFG::qBaseNodeRB *v127; // rax
  signed __int64 v128; // r9
  Render::DebugDrawContext *v129; // rbx
  char *v130; // rax
  char *v131; // rbx
  char *v132; // rax
  float v133; // xmm1_4
  float v134; // xmm2_4
  __int128 v135; // xmm2
  __int128 v136; // xmm1
  __int128 v137; // xmm0
  __int128 v138; // xmm2
  __int128 v139; // xmm1
  __int128 v140; // xmm0
  UFG::qResourceData *v141; // rax
  UFG::qBaseNodeRB *v142; // rcx
  _QWORD *v143; // rax
  char *v144; // rax
  char *v145; // rax
  UFG::qTask *v146; // rdx
  _QWORD *v147; // rax
  UFG::qSpuElf *v148; // rax
  void (__fastcall *v149)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v150)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v151)(void *, void *, void *, void *); // r9
  char *v152; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v153; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v154; // rax
  unsigned __int64 v155; // rax
  signed __int64 v156; // [rsp+30h] [rbp-90h]
  UFG::qMatrix44 d; // [rsp+40h] [rbp-80h]
  char *v158; // [rsp+8D0h] [rbp+810h]
  _OWORD *v159; // [rsp+8D8h] [rbp+818h]
  __int64 v160; // [rsp+8E0h] [rbp+820h]
  UFG::qVector3 *aabb_max; // [rsp+8E8h] [rbp+828h]

  *(_QWORD *)&d.v1.x = -2i64;
  v3 = render_context;
  v4 = this;
  if ( !this->mEnableDome && Render::SkyMarshall::sEnableClouds )
  {
    v5 = this->mEnviroScalar;
    if ( v5 < 0.0 )
      LODWORD(v5) ^= _xmm[0];
    if ( v5 >= 0.001 )
    {
      *(_QWORD *)&d.v0.x = UFG::qGetTicks();
      Render::SkyMarshall::WispIndexBuffer::mActiveBuffer = Render::SkyMarshall::WispIndexBuffer::mActiveBuffer == 0;
      *(_QWORD *)&d.v0.z = (char *)v3 + 1008;
      UFG::qInverseAffine(&d, &v3->mMainViewSettings.mWorldView);
      sSortIndex = ((_BYTE)sSortIndex + 1) & 0xF;
      v6 = 0;
      v7 = 0;
      v8 = v4->mCullResults;
      v9 = &v4->mCloudSceneHandle[0].mData;
      do
      {
        v10 = *v9;
        if ( *v9 )
        {
          v11 = 0;
          if ( LODWORD(v10[1].mNode.mParent) > 0 )
          {
            v12 = *v8;
            do
            {
              if ( v12[(unsigned __int64)v11].mViewResult[0] <= 1u )
              {
                v13 = (unsigned int)v6;
                *((_WORD *)&d.v2.x + 2 * v13) = v7;
                *((_WORD *)&d.v2.x + 2 * v13 + 1) = v11;
                ++v6;
              }
              ++v11;
            }
            while ( v11 < LODWORD(v10[1].mNode.mParent) );
          }
        }
        ++v7;
        ++v8;
        v9 += 4;
      }
      while ( v7 < 4 );
      v14 = 0;
      v15 = 0i64;
      if ( v6 >= 4 )
      {
        v16 = ((unsigned int)(v6 - 4) >> 2) + 1;
        v17 = v16;
        v14 = 4 * v16;
        do
        {
          v18 = &v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.x + 2 * v15)].mData[1].mResourceHandles;
          v19 = (char *)v18 + (unsigned __int64)v18->mNode.mPrev;
          if ( !v18->mNode.mPrev )
            v19 = 0i64;
          v20 = (float *)&v19[192 * *((unsigned __int16 *)&d.v2.x + 2 * v15 + 1)];
          v20[45] = (float)((float)((float)(d.v3.y - v20[13]) * (float)(d.v3.y - v20[13]))
                          + (float)((float)(d.v3.x - v20[12]) * (float)(d.v3.x - v20[12])))
                  + (float)((float)(d.v3.z - v20[14]) * (float)(d.v3.z - v20[14]));
          v21 = &v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.y + 2 * v15)].mData[1].mResourceHandles;
          v22 = (char *)v21 + (unsigned __int64)v21->mNode.mPrev;
          if ( !v21->mNode.mPrev )
            v22 = 0i64;
          v23 = (float *)&v22[192 * *((unsigned __int16 *)&d.v2.y + 2 * v15 + 1)];
          v23[45] = (float)((float)((float)(d.v3.y - v23[13]) * (float)(d.v3.y - v23[13]))
                          + (float)((float)(d.v3.x - v23[12]) * (float)(d.v3.x - v23[12])))
                  + (float)((float)(d.v3.z - v23[14]) * (float)(d.v3.z - v23[14]));
          v24 = &v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.z + 2 * v15)].mData[1].mResourceHandles;
          v25 = (char *)v24 + (unsigned __int64)v24->mNode.mPrev;
          if ( !v24->mNode.mPrev )
            v25 = 0i64;
          v26 = (float *)&v25[192 * *((unsigned __int16 *)&d.v2.z + 2 * v15 + 1)];
          v26[45] = (float)((float)((float)(d.v3.y - v26[13]) * (float)(d.v3.y - v26[13]))
                          + (float)((float)(d.v3.x - v26[12]) * (float)(d.v3.x - v26[12])))
                  + (float)((float)(d.v3.z - v26[14]) * (float)(d.v3.z - v26[14]));
          v27 = v4->mCloudSceneHandle[*((unsigned __int16 *)&d.v2.w + 2 * v15)].mData;
          v28 = v27[1].mResourceHandles.mNode.mPrev;
          if ( v28 )
            v29 = (signed __int64)&v28[7].mNext + (_QWORD)v27;
          else
            v29 = 0i64;
          v30 = (float *)(v29 + 192i64 * *((unsigned __int16 *)&d.v2.w + 2 * v15 + 1));
          v30[45] = (float)((float)((float)(d.v3.x - v30[12]) * (float)(d.v3.x - v30[12]))
                          + (float)((float)(d.v3.y - v30[13]) * (float)(d.v3.y - v30[13])))
                  + (float)((float)(d.v3.z - v30[14]) * (float)(d.v3.z - v30[14]));
          v15 += 4i64;
          --v17;
        }
        while ( v17 );
      }
      if ( v14 < v6 )
      {
        v31 = (unsigned __int16 *)((char *)&d.v2.x + 4 * v15 + 2);
        v32 = v6 - v14;
        do
        {
          v33 = v4->mCloudSceneHandle[*(v31 - 1)].mData;
          v34 = v33[1].mResourceHandles.mNode.mPrev;
          if ( v34 )
            v35 = (signed __int64)&v34[7].mNext + (_QWORD)v33;
          else
            v35 = 0i64;
          v36 = (float *)(v35 + 192i64 * *v31);
          v36[45] = (float)((float)((float)(d.v3.x - v36[12]) * (float)(d.v3.x - v36[12]))
                          + (float)((float)(d.v3.y - v36[13]) * (float)(d.v3.y - v36[13])))
                  + (float)((float)(d.v3.z - v36[14]) * (float)(d.v3.z - v36[14]));
          v31 += 2;
          --v32;
        }
        while ( v32 );
      }
      v37 = (Render::SkyMarshall::CloudInstanceID *)(&d.v1.w + v6);
      v38 = (4i64 * v6 - 100 + 96) >> 2;
      LODWORD(v39) = v38 + 1;
      if ( (signed int)v38 + 1 < 32 )
      {
        v156 = (signed int)v39;
        if ( (signed int)v39 >= 2i64 )
        {
          v60 = 0i64;
          v61 = (int *)&d.v2.y;
          v39 = (signed int)v39;
          do
          {
            v62 = *v61;
            LODWORD(aabb_max) = *v61;
            v63 = v60;
            if ( v60 >= 0 )
            {
              v64 = WORD1(aabb_max);
              if ( v60 + 1 < 4 )
              {
LABEL_104:
                if ( v63 >= 0 )
                {
                  v88 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[(unsigned __int16)v62].mData;
                  v89 = 192i64 * v64;
                  do
                  {
                    v90 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[*((unsigned __int16 *)&d.v2.x + 2 * v63)].mData;
                    v91 = v88[1].mResourceHandles.mNode.mPrev;
                    if ( v91 )
                      v92 = (signed __int64)&v91[7].mNext + (_QWORD)v88;
                    else
                      v92 = 0i64;
                    v93 = v90[1].mResourceHandles.mNode.mPrev;
                    if ( v93 )
                      v94 = (signed __int64)&v93[7].mNext + (_QWORD)v90;
                    else
                      v94 = 0i64;
                    if ( *(float *)(192i64 * *((unsigned __int16 *)&d.v2.x + 2 * v63 + 1) + v94 + 180) <= *(float *)(v92 + v89 + 180) )
                      break;
                    *((_DWORD *)&d.v2.y + v63) = *((_DWORD *)&d.v2.x + v63);
                    --v63;
                  }
                  while ( v63 >= 0 );
                }
              }
              else
              {
                v65 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[(unsigned __int16)v62].mData;
                v66 = 192i64 * WORD1(aabb_max);
                v67 = (unsigned __int16 *)((char *)v61 - 10);
                while ( 1 )
                {
                  v68 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v67[3]].mData;
                  v69 = v65[1].mResourceHandles.mNode.mPrev;
                  v70 = (signed __int64)(v69 ? (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&v69[7].mNext + (_QWORD)v65) : 0i64);
                  v71 = v68[1].mResourceHandles.mNode.mPrev;
                  v72 = (signed __int64)(v71 ? (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&v71[7].mNext + (_QWORD)v68) : 0i64);
                  if ( *(float *)(192i64 * v67[4] + v72 + 180) <= *(float *)(v70 + v66 + 180) )
                    break;
                  *(_DWORD *)(v67 + 5) = *(_DWORD *)(v67 + 3);
                  v73 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v67[1]].mData;
                  v74 = v65[1].mResourceHandles.mNode.mPrev;
                  if ( v74 )
                    v75 = (signed __int64)&v74[7].mNext + (_QWORD)v65;
                  else
                    v75 = 0i64;
                  v76 = v73[1].mResourceHandles.mNode.mPrev;
                  if ( v76 )
                    v77 = (signed __int64)&v76[7].mNext + (_QWORD)v73;
                  else
                    v77 = 0i64;
                  if ( *(float *)(192i64 * v67[2] + v77 + 180) <= *(float *)(v75 + v66 + 180) )
                  {
                    --v63;
                    break;
                  }
                  *(_DWORD *)(v67 + 3) = *(_DWORD *)(v67 + 1);
                  v78 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[*(v67 - 1)].mData;
                  v79 = v65[1].mResourceHandles.mNode.mPrev;
                  if ( v79 )
                    v80 = (signed __int64)&v79[7].mNext + (_QWORD)v65;
                  else
                    v80 = 0i64;
                  v81 = v78[1].mResourceHandles.mNode.mPrev;
                  if ( v81 )
                    v82 = (signed __int64)&v81[7].mNext + (_QWORD)v78;
                  else
                    v82 = 0i64;
                  if ( *(float *)(192i64 * *v67 + v82 + 180) <= *(float *)(v80 + v66 + 180) )
                  {
                    v63 -= 2i64;
                    break;
                  }
                  *(_DWORD *)(v67 + 1) = *(_DWORD *)(v67 - 1);
                  v83 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[*(v67 - 3)].mData;
                  v84 = v65[1].mResourceHandles.mNode.mPrev;
                  if ( v84 )
                    v85 = (signed __int64)&v84[7].mNext + (_QWORD)v65;
                  else
                    v85 = 0i64;
                  v86 = v83[1].mResourceHandles.mNode.mPrev;
                  if ( v86 )
                    v87 = (signed __int64)&v86[7].mNext + (_QWORD)v83;
                  else
                    v87 = 0i64;
                  if ( *(float *)(192i64 * *(v67 - 2) + v87 + 180) <= *(float *)(v85 + v66 + 180) )
                  {
                    v63 -= 3i64;
                    break;
                  }
                  *(_DWORD *)(v67 - 1) = *(_DWORD *)(v67 - 3);
                  v63 -= 4i64;
                  v67 -= 8;
                  if ( v63 < 3 )
                  {
                    v64 = WORD1(aabb_max);
                    goto LABEL_104;
                  }
                }
              }
              v39 = v156;
            }
            *((_DWORD *)&d.v2.y + v63) = v62;
            ++v61;
            ++v60;
          }
          while ( v60 + 1 < v39 );
          v4 = (Render::SkyMarshall *)v158;
        }
      }
      else
      {
        v40 = (Render::SkyMarshall::CloudInstanceID *)(&d.v2.x + v38 / 2);
        if ( Render::SkyMarshall::CloudDistanceCompare(v40, (Render::SkyMarshall::CloudInstanceID *)&d.v2) )
        {
          v41 = *(float *)v40;
          *v40 = LODWORD(d.v2.x);
          d.v2.x = v41;
        }
        if ( Render::SkyMarshall::CloudDistanceCompare((Render::SkyMarshall::CloudInstanceID *)&d.v1.w + v6, v40) )
        {
          v42 = *v37;
          *v37 = *v40;
          *v40 = v42;
        }
        if ( Render::SkyMarshall::CloudDistanceCompare(v40, (Render::SkyMarshall::CloudInstanceID *)&d.v2) )
        {
          v43 = *v40;
          *v40 = LODWORD(d.v2.x);
          LODWORD(d.v2.x) = v43;
        }
        v44 = *v40;
        LODWORD(v158) = *v40;
        v45 = (Render::SkyMarshall::CloudInstanceID *)&d.v2;
        v46 = (Render::SkyMarshall::CloudInstanceID *)(&d.v1.w + v6);
        if ( &d.v2 <= (UFG::qVector4 *)v37 )
        {
          v47 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v44.mSceneIndex].mData;
          v48 = 192i64 * WORD1(v158);
          do
          {
            while ( 1 )
            {
              v49 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v45->mSceneIndex].mData;
              v50 = v49[1].mResourceHandles.mNode.mPrev;
              v51 = (signed __int64)(v50 ? (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&v50[7].mNext + (_QWORD)v49) : 0i64);
              v52 = v47[1].mResourceHandles.mNode.mPrev;
              v53 = (signed __int64)(v52 ? (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&v52[7].mNext + (_QWORD)v47) : 0i64);
              if ( *(float *)(v53 + v48 + 180) <= *(float *)(192i64 * v45->mInstanceIndex + v51 + 180) || v45 >= v37 )
                break;
              ++v45;
            }
            v54 = v47[1].mResourceHandles.mNode.mPrev;
            while ( 1 )
            {
              v55 = Render::SkyMarshall::gSkyMarshall.mCloudSceneHandle[v46->mSceneIndex].mData;
              v56 = (signed __int64)(v54 ? (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&v54[7].mNext + (_QWORD)v47) : 0i64);
              v57 = v55[1].mResourceHandles.mNode.mPrev;
              v58 = (signed __int64)(v57 ? (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&v57[7].mNext + (_QWORD)v55) : 0i64);
              if ( *(float *)(192i64 * v46->mInstanceIndex + v58 + 180) <= *(float *)(v56 + v48 + 180)
                || &d.v2 >= (UFG::qVector4 *)v46 )
              {
                break;
              }
              --v46;
            }
            if ( v45 > v46 )
              break;
            v59 = *v45;
            *v45 = *v46;
            *v46 = v59;
            ++v45;
            --v46;
          }
          while ( v45 <= v46 );
        }
        if ( &d.v2 < (UFG::qVector4 *)v46 )
          UFG::qQuickSortImpl<Render::SkyMarshall::CloudInstanceID,bool (*)(Render::SkyMarshall::CloudInstanceID const &,Render::SkyMarshall::CloudInstanceID const &)>(
            (Render::SkyMarshall::CloudInstanceID *)&d.v2,
            v46,
            Render::SkyMarshall::CloudDistanceCompare);
        if ( v45 < v37 )
          UFG::qQuickSortImpl<Render::SkyMarshall::CloudInstanceID,bool (*)(Render::SkyMarshall::CloudInstanceID const &,Render::SkyMarshall::CloudInstanceID const &)>(
            v45,
            (Render::SkyMarshall::CloudInstanceID *)&d.v1.w + v6,
            Render::SkyMarshall::CloudDistanceCompare);
      }
      v95 = 128;
      if ( (unsigned int)v6 < 0x80 )
        v95 = v6;
      v96 = (__int64)v159;
      *(_DWORD *)(v96 + 980) += v95;
      v97 = 0;
      LODWORD(v158) = 0;
      v98 = v95 - 1;
      if ( v95 - 1 >= 0 )
      {
        v99 = (unsigned __int16 *)((char *)&d.v2.x + 4 * v98 + 2);
        do
        {
          v100 = *(v99 - 1);
          v101 = v4->mCloudSceneHandle[*(v99 - 1)].mData;
          v102 = v101[1].mResourceHandles.mNode.mPrev;
          if ( v102 )
            v103 = (signed __int64)&v101[1].mResourceHandles + (_QWORD)v102;
          else
            v103 = 0i64;
          local_world = v103 + 192i64 * *v99;
          v105 = *(_QWORD *)(local_world + 80);
          v106 = v97;
          v107 = v97;
          v108 = *(UFG::qVector4 *)(local_world + 16);
          v109 = *(UFG::qVector4 *)(local_world + 32);
          v110 = *(UFG::qVector4 *)(local_world + 48);
          v4->mTaskInstance[v107].mTransform.v0 = *(UFG::qVector4 *)local_world;
          v4->mTaskInstance[v107].mTransform.v1 = v108;
          v4->mTaskInstance[v107].mTransform.v2 = v109;
          v4->mTaskInstance[v107].mTransform.v3 = v110;
          v111 = *(UFG::qVector4 *)(local_world + 124);
          v112 = *(UFG::qVector4 *)(local_world + 140);
          v113 = *(UFG::qVector4 *)(local_world + 156);
          v4->mTaskInstance[v107].mInverseTransform.v0 = *(UFG::qVector4 *)(local_world + 108);
          v4->mTaskInstance[v107].mInverseTransform.v1 = v111;
          v4->mTaskInstance[v107].mInverseTransform.v2 = v112;
          v4->mTaskInstance[v107].mInverseTransform.v3 = v113;
          v4->mTaskInstance[v107].mScale = *(float *)(local_world + 172);
          if ( Render::SkyMarshall::sUseCloudOpacity )
            v114 = *(float *)(local_world + 176);
          else
            v114 = *(float *)&FLOAT_1_0;
          if ( v4->mBoundaryCloudSceneID == v100 )
            v115 = v4->mBoundaryCloudSceneOpacity;
          else
            v115 = *(float *)&FLOAT_1_0;
          v4->mTaskInstance[v107].mOpacity = (float)((float)(v114 * Render::SkyMarshall::sGlobalOpacity) * v115)
                                           * v4->mEnviroScalar;
          v4->mTaskInstance[v107].mNumWisps = *(_DWORD *)(v105 + 88);
          v116 = *(float *)(v105 + 120);
          v117 = *(float *)(v105 + 124);
          v4->mTaskInstance[v107].mCenter.x = *(float *)(v105 + 116);
          v4->mTaskInstance[v107].mCenter.y = v116;
          v4->mTaskInstance[v107].mCenter.z = v117;
          v118 = (UFG::qVector3 *)(v105 + 92);
          v119 = *(float *)(v105 + 96);
          v120 = *(float *)(v105 + 100);
          v4->mTaskInstance[v107].mAABBMin.x = *(float *)(v105 + 92);
          v4->mTaskInstance[v107].mAABBMin.y = v119;
          v4->mTaskInstance[v107].mAABBMin.z = v120;
          aabb_max = (UFG::qVector3 *)(v105 + 104);
          v121 = *(float *)(v105 + 108);
          v122 = *(float *)(v105 + 112);
          v4->mTaskInstance[v107].mAABBMax.x = *(float *)(v105 + 104);
          v4->mTaskInstance[v107].mAABBMax.y = v121;
          v4->mTaskInstance[v107].mAABBMax.z = v122;
          v4->mTaskInstance[v107].mRadius = *(float *)(v105 + 128);
          v123 = *(_QWORD **)(v105 + 152);
          v4->mTaskInstance[v107].mAttributeBuffer.m_Stream = v123;
          v124 = v123[12];
          if ( v124 )
            v125 = (signed __int64)v123 + v124 + 96;
          else
            v125 = 0i64;
          v4->mTaskInstance[v107].mAttributeBufferData = (void *)v125;
          v126 = v4->mWispIndexBuffer[16].mBufferHandle[Render::SkyMarshall::WispIndexBuffer::mActiveBuffer].mData;
          v4->mTaskInstance[v107].mIndexBuffer.m_Stream = v126;
          v127 = v126[1].mNode.mChild[0];
          if ( v127 )
            v128 = (signed __int64)v126[1].mNode.mChild + (_QWORD)v127;
          else
            v128 = 0i64;
          *((_QWORD *)&v4->mTexture.mPrev + 30 * (v106 + 43)) = v128;
          *(_WORD *)&v4->mTaskInstance[v107].mReset = 0;
          v4->mTaskInstance[v107].mDebugName = (void *)(v105 + 52);
          if ( Render::SkyMarshall::sCloudDrawDebug )
          {
            v129 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                 Render::DebugDrawManager::mInstance,
                                                 2u);
            Render::DebugDrawContext::DrawAABB(
              v129,
              v118,
              aabb_max,
              &UFG::qColour::Blue,
              (UFG::qMatrix44 *)local_world,
              0i64);
            Render::DebugDrawContext::DrawAxes(v129, (UFG::qMatrix44 *)local_world, 20.0, 0, 0i64);
          }
          v97 = (_DWORD)v158 + 1;
          LODWORD(v158) = (_DWORD)v158 + 1;
          v99 -= 2;
          --v98;
        }
        while ( v98 >= 0 );
        if ( v97 )
        {
          v130 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xE8u, 0x10u);
          v131 = v130;
          Render::gCloudSortTaskParams = (CloudSortTaskParams *)v130;
          v132 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x20u);
          v158 = v132;
          aabb_max = (UFG::qVector3 *)v132;
          if ( v132 )
          {
            *(_QWORD *)v132 = v132;
            *((_QWORD *)v132 + 1) = v132;
          }
          else
          {
            v132 = 0i64;
          }
          *((_QWORD *)v131 + 24) = v132;
          *((_QWORD *)v131 + 20) = v160;
          v133 = d.v3.y;
          v134 = d.v3.z;
          *((_DWORD *)v131 + 32) = LODWORD(d.v3.x);
          *((float *)v131 + 33) = v133;
          *((float *)v131 + 34) = v134;
          *((_DWORD *)v131 + 35) = v97;
          *((_QWORD *)v131 + 18) = (char *)v4 + 10112;
          *((_QWORD *)v131 + 21) = Illusion::gEngine.FrameMemory;
          v135 = *(_OWORD *)(*(_QWORD *)&d.v0.z + 16i64);
          v136 = *(_OWORD *)(*(_QWORD *)&d.v0.z + 32i64);
          v137 = *(_OWORD *)(*(_QWORD *)&d.v0.z + 48i64);
          *(_OWORD *)v131 = **(_OWORD **)&d.v0.z;
          *((_OWORD *)v131 + 1) = v135;
          *((_OWORD *)v131 + 2) = v136;
          *((_OWORD *)v131 + 3) = v137;
          v96 = (__int64)v159;
          v138 = v159[68];
          v139 = v159[69];
          v140 = v159[70];
          *((_OWORD *)v131 + 4) = v159[67];
          *((_OWORD *)v131 + 5) = v138;
          *((_OWORD *)v131 + 6) = v139;
          *((_OWORD *)v131 + 7) = v140;
          *((_QWORD *)v131 + 22) = Render::GetViewStateBlockParams();
          *((_QWORD *)v131 + 23) = Render::GetCloudSortTaskParamIndices();
          *((_QWORD *)v131 + 25) = &Render::gCloudRenderLayer;
          v141 = v4->mWispModel.mData;
          v142 = v141[2].mNode.mChild[0];
          if ( v142 )
            v143 = (UFG::qBaseNodeRB **)((char *)v141[2].mNode.mChild + (_QWORD)v142);
          else
            v143 = 0i64;
          if ( *v143 )
            v144 = (char *)v143 + *v143;
          else
            v144 = 0i64;
          *((_QWORD *)v131 + 26) = v144;
          *((_DWORD *)v131 + 38) = *(_DWORD *)(*((_QWORD *)v144 + 14) + 108i64);
          *((_QWORD *)v131 + 27) = v4->mCloudMaterial.mData;
          v145 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
          v146 = (UFG::qTask *)v145;
          v158 = v145;
          aabb_max = (UFG::qVector3 *)v145;
          if ( v145 )
          {
            *(_QWORD *)v145 = v145;
            *((_QWORD *)v145 + 1) = v145;
            v147 = v145 + 16;
            *v147 = v147;
            v147[1] = v147;
            v148 = gTaskFunctionDeclData_CloudSortTask.mSpuElf;
            v149 = gTaskFunctionDeclData_CloudSortTask.mTaskFunctionSPU;
            v150 = gTaskFunctionDeclData_CloudSortTask.mTaskFunctionPPU;
            v151 = gTaskFunctionDeclData_CloudSortTask.mTaskFunctionOffload;
            if ( !gTaskFunctionDeclData_CloudSortTask.mCurrentSPUEnabled )
            {
              v148 = 0i64;
              v149 = 0i64;
              v151 = 0i64;
            }
            v146->mTaskGroup = 0i64;
            v146->mFlags = 2;
            v146->mSyncVars.i64 = 0i64;
            v146->mSyncVars.v.mDependents = 0i64;
            v146->mFunctionDeclData = &gTaskFunctionDeclData_CloudSortTask;
            if ( v148 )
              v152 = v148->mAddress;
            else
              v152 = 0i64;
            v146->mSPUElfAddress = v152;
            v146->mSPUFunction = v149;
            v146->mPPUFunction = v150;
            v146->mParam0 = v131;
            v146->mParam1 = 0i64;
            v146->mParam2 = 0i64;
            v146->mParam3 = 0i64;
            if ( v151 )
            {
              v146->mFlags = 130;
              v146->mOffloadThread = 0;
            }
          }
          v153 = UFG::gTaskManager.mSingleFrameTasks;
          v154 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
          v154->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v146->mPrev;
          v146->mPrev = v154;
          v146->mNext = &v153->mNode;
          v153->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v146->mPrev;
          Render::gCloudTask = v146;
          UFG::qTaskManager::Queue(&UFG::gTaskManager, v146);
          goto LABEL_160;
        }
        v96 = (__int64)v159;
      }
      Render::gCloudTask = 0i64;
      Render::gCloudSortTaskParams = 0i64;
LABEL_160:
      v155 = UFG::qGetTicks();
      *(float *)(v96 + 904) = UFG::qGetTickTime(*(unsigned __int64 *)&d.v0.x, v155) + *(float *)(v96 + 904);
      return;
    }
  }
  Render::gCloudTask = 0i64;
}

