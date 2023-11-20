// File Line: 34
// RVA: 0x1585F0
bool __fastcall UFG::ClearView::Execute(UFG::ClearView *this, Illusion::SubmitContext *submit_context)
{
  Illusion::SubmitContext *v2; // rbx
  UFG::ClearView *v3; // rdi
  Render::ViewSettings *v4; // rax
  Render::View v6; // [rsp+50h] [rbp-198h]

  v2 = submit_context;
  v3 = this;
  v4 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v6, v4, v2);
  Render::View::BeginTarget(&v6, v3->mTarget, "ClearView::Execute", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v6, &v3->mColour, 1u, 0.0, 0);
  Render::View::EndTarget(&v6);
  return 0;
}

// File Line: 182
// RVA: 0x158690
char __fastcall UFG::DilateTexture::Execute(UFG::DilateTexture *this, Illusion::SubmitContext *submit_context)
{
  Illusion::SubmitContext *v2; // rbx
  UFG::DilateTexture *v3; // rsi
  Render::ViewSettings *v4; // rax
  _WORD *v5; // rbx
  Illusion::Material *v6; // rdi
  unsigned int v7; // er8
  __int64 v8; // rax
  _WORD *v9; // rax
  unsigned int v10; // eax
  Illusion::Material *v11; // rdi
  __int64 v12; // rax
  Render::View v14; // [rsp+50h] [rbp-198h]
  Render::Poly poly; // [rsp+1F0h] [rbp+8h]

  v2 = submit_context;
  v3 = this;
  v4 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v14, v4, v2);
  v5 = 0i64;
  Render::View::BeginTarget(&v14, v3->mTarget, "PartCompositeBuilder", 0, 0, 0i64, 1, 0, 0, 0);
  v6 = v3->mMaterial;
  v7 = v3->mSourceTarget->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(v6[1].mStateBlockMask.mFlags[0]) != v7 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6[1].mDebugName[20], v6[1].mStateBlockMask.mFlags[1], v7);
    v8 = v6->mMaterialUser.mOffset;
    if ( v8 )
      v9 = (_WORD *)((char *)&v6->mMaterialUser + v8);
    else
      v9 = 0i64;
    *v9 |= 0x20u;
  }
  v10 = UFG::qStringHashUpper32("DefaultWhite", 0xFFFFFFFF);
  v11 = v3->mMaterial;
  if ( v11[2].mNode.mUID != v10 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v11[2], (unsigned int)v11[2].mResourceHandles.mNode.mPrev, v10);
    v12 = v11->mMaterialUser.mOffset;
    if ( v12 )
      v5 = (_WORD *)((char *)&v11->mMaterialUser + v12);
    *v5 |= 0x20u;
  }
  Render::Poly::Poly(&poly, 0.0, 0.0, 1.0, 1.0, 1.0 / (float)v3->mTarget->mWidth);
  Render::View::Draw(&v14, &poly, v3->mMaterial, 0i64);
  Render::View::EndTarget(&v14);
  return 1;
}

// File Line: 216
// RVA: 0x154830
void __fastcall UFG::PartTextureData::PartTextureData(UFG::PartTextureData *this, UFG::PartTemplateInstance *instance)
{
  UFG::PartTemplateInstance *v2; // r13
  UFG::PartTextureData *v3; // rdi
  __int64 v4; // rbp
  unsigned int v5; // ecx
  signed int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  __int64 v10; // rsi
  __int64 v11; // r14
  UFG::PartTemplateInstance::SlotEntry *v12; // rbx
  UFG::PartTextureData::Textures *v13; // r15
  char v14; // dl
  __int64 v15; // r8
  unsigned int v16; // er9

  v2 = instance;
  v3 = this;
  this->mParts.p = 0i64;
  *(_QWORD *)&this->mParts.size = 0i64;
  v4 = instance->mSlots.mData.mNumItems;
  v5 = this->mParts.size;
  v6 = instance->mSlots.mData.mNumItems - v5;
  if ( v6 <= 0 )
  {
    if ( v5 != instance->mSlots.mData.mNumItems )
    {
      if ( v5 - instance->mSlots.mData.mNumItems < v5 )
        v3->mParts.size = instance->mSlots.mData.mNumItems;
      else
        v3->mParts.size = 0;
    }
  }
  else
  {
    v7 = instance->mSlots.mData.mNumItems;
    v8 = v3->mParts.capacity;
    if ( v5 + v6 > v8 )
    {
      if ( v8 )
        v9 = 2 * v8;
      else
        v9 = 1;
      for ( ; v9 < v7; v9 *= 2 )
        ;
      if ( v9 - v7 > 0x10000 )
        v9 = v7 + 0x10000;
      UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(&v3->mParts, v9, "qArray.Reallocate(Resize)");
    }
    v3->mParts.size = v7;
  }
  if ( (_DWORD)v4 )
  {
    v10 = 0i64;
    v11 = 0i64;
    do
    {
      v12 = v2->mSlots.mData.mItems;
      v13 = &v3->mParts.p[v10];
      UFG::qMemSet(&v3->mParts.p[v10], 0, 0x18u);
      if ( v12[v11].mBasePart.mPart.mData )
      {
        v14 = 0;
        v15 = 0i64;
        v16 = v12[v11].mLayers.mData.mNumItems;
        if ( v16 )
        {
          do
          {
            if ( v12[v11].mLayers.mData.mItems[v15].mPart.mData )
              v14 = 1;
            v15 = (unsigned int)(v15 + 1);
          }
          while ( (unsigned int)v15 < v16 );
          if ( v14 )
          {
            v13->mDiffuseTarget = UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder::sInstance);
            v13->mNormTarget = UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder::sInstance);
            v13->mSpecTarget = UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder::sInstance);
          }
        }
      }
      ++v11;
      ++v10;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 234
// RVA: 0x155730
void __fastcall UFG::PartTextureData::~PartTextureData(UFG::PartTextureData *this)
{
  UFG::PartTextureData *v1; // rbx
  unsigned int v2; // er13
  UFG::PartTextureData::Textures *v3; // r12
  Illusion::Target *v4; // r15
  UFG::PartCompositeBuilder *v5; // rdi
  __int64 v6; // r14
  unsigned int v7; // esi
  unsigned int v8; // ebx
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  char *v11; // rax
  char *v12; // rbp
  __int64 v13; // r9
  Illusion::Target *v14; // r15
  UFG::PartCompositeBuilder *v15; // rdi
  __int64 v16; // r14
  unsigned int v17; // esi
  unsigned int v18; // ebx
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  char *v21; // rax
  char *v22; // rbp
  __int64 v23; // r9
  Illusion::Target *v24; // r15
  UFG::PartCompositeBuilder *v25; // rdi
  __int64 v26; // r14
  unsigned int v27; // esi
  unsigned int v28; // ebx
  unsigned int v29; // ebx
  unsigned __int64 v30; // rax
  char *v31; // rax
  char *v32; // rbp
  __int64 v33; // r9
  UFG::PartTextureData::Textures *v34; // rcx
  UFG::PartTextureData *v35; // [rsp+60h] [rbp+8h]

  v35 = this;
  v1 = this;
  v2 = 0;
  if ( this->mParts.size )
  {
    do
    {
      v3 = &v1->mParts.p[v2];
      v4 = v3->mDiffuseTarget;
      if ( v3->mDiffuseTarget )
      {
        v5 = UFG::PartCompositeBuilder::sInstance;
        v6 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.size;
        v7 = v6 + 1;
        v8 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.capacity;
        if ( (signed int)v6 + 1 > v8 )
        {
          if ( v8 )
            v9 = 2 * v8;
          else
            v9 = 1;
          for ( ; v9 < v7; v9 *= 2 )
            ;
          if ( v9 <= 2 )
            v9 = 2;
          if ( v9 - v7 > 0x10000 )
            v9 = v6 + 65537;
          if ( v9 != (_DWORD)v6 )
          {
            v10 = 8i64 * v9;
            if ( !is_mul_ok(v9, 8ui64) )
              v10 = -1i64;
            v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
            v12 = v11;
            if ( v5->mFreeTargets.p )
            {
              v13 = 0i64;
              if ( v5->mFreeTargets.size )
              {
                do
                {
                  *(_QWORD *)&v11[8 * v13] = v5->mFreeTargets.p[v13];
                  v13 = (unsigned int)(v13 + 1);
                }
                while ( (unsigned int)v13 < v5->mFreeTargets.size );
              }
              operator delete[](v5->mFreeTargets.p);
            }
            v5->mFreeTargets.p = (Illusion::Target **)v12;
            v5->mFreeTargets.capacity = v9;
          }
        }
        v5->mFreeTargets.size = v7;
        v5->mFreeTargets.p[v6] = v4;
        v3->mDiffuseTarget = 0i64;
      }
      v14 = v3->mNormTarget;
      if ( v14 )
      {
        v15 = UFG::PartCompositeBuilder::sInstance;
        v16 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.size;
        v17 = v16 + 1;
        v18 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.capacity;
        if ( (signed int)v16 + 1 > v18 )
        {
          if ( v18 )
            v19 = 2 * v18;
          else
            v19 = 1;
          for ( ; v19 < v17; v19 *= 2 )
            ;
          if ( v19 <= 2 )
            v19 = 2;
          if ( v19 - v17 > 0x10000 )
            v19 = v16 + 65537;
          if ( v19 != (_DWORD)v16 )
          {
            v20 = 8i64 * v19;
            if ( !is_mul_ok(v19, 8ui64) )
              v20 = -1i64;
            v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
            v22 = v21;
            if ( v15->mFreeTargets.p )
            {
              v23 = 0i64;
              if ( v15->mFreeTargets.size )
              {
                do
                {
                  *(_QWORD *)&v21[8 * v23] = v15->mFreeTargets.p[v23];
                  v23 = (unsigned int)(v23 + 1);
                }
                while ( (unsigned int)v23 < v15->mFreeTargets.size );
              }
              operator delete[](v15->mFreeTargets.p);
            }
            v15->mFreeTargets.p = (Illusion::Target **)v22;
            v15->mFreeTargets.capacity = v19;
          }
        }
        v15->mFreeTargets.size = v17;
        v15->mFreeTargets.p[v16] = v14;
        v3->mNormTarget = 0i64;
      }
      v24 = v3->mSpecTarget;
      if ( v24 )
      {
        v25 = UFG::PartCompositeBuilder::sInstance;
        v26 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.size;
        v27 = v26 + 1;
        v28 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.capacity;
        if ( (signed int)v26 + 1 > v28 )
        {
          if ( v28 )
            v29 = 2 * v28;
          else
            v29 = 1;
          for ( ; v29 < v27; v29 *= 2 )
            ;
          if ( v29 <= 2 )
            v29 = 2;
          if ( v29 - v27 > 0x10000 )
            v29 = v26 + 65537;
          if ( v29 != (_DWORD)v26 )
          {
            v30 = 8i64 * v29;
            if ( !is_mul_ok(v29, 8ui64) )
              v30 = -1i64;
            v31 = UFG::qMalloc(v30, "qArray.Add", 0i64);
            v32 = v31;
            if ( v25->mFreeTargets.p )
            {
              v33 = 0i64;
              if ( v25->mFreeTargets.size )
              {
                do
                {
                  *(_QWORD *)&v31[8 * v33] = v25->mFreeTargets.p[v33];
                  v33 = (unsigned int)(v33 + 1);
                }
                while ( (unsigned int)v33 < v25->mFreeTargets.size );
              }
              operator delete[](v25->mFreeTargets.p);
            }
            v25->mFreeTargets.p = (Illusion::Target **)v32;
            v25->mFreeTargets.capacity = v29;
          }
        }
        v25->mFreeTargets.size = v27;
        v25->mFreeTargets.p[v26] = v24;
        v3->mSpecTarget = 0i64;
      }
      ++v2;
      v1 = v35;
    }
    while ( v2 < v35->mParts.size );
  }
  v34 = v1->mParts.p;
  if ( v34 )
    operator delete[](v34);
  v1->mParts.p = 0i64;
  *(_QWORD *)&v1->mParts.size = 0i64;
}

// File Line: 274
// RVA: 0x159210
void UFG::PartCompositeBuilder::Init(void)
{
  char *v0; // rax
  UFG::PartCompositeBuilder *v1; // rax

  v0 = UFG::qMalloc(0x98ui64, UFG::gGlobalNewName, 0i64);
  if ( v0 )
  {
    UFG::PartCompositeBuilder::PartCompositeBuilder((UFG::PartCompositeBuilder *)v0);
    UFG::PartCompositeBuilder::sInstance = v1;
  }
  else
  {
    UFG::PartCompositeBuilder::sInstance = 0i64;
  }
}

// File Line: 280
// RVA: 0x15A060
void UFG::PartCompositeBuilder::Quit(void)
{
  UFG::PartCompositeBuilder *v0; // rbx

  v0 = UFG::PartCompositeBuilder::sInstance;
  if ( UFG::PartCompositeBuilder::sInstance )
  {
    UFG::PartCompositeBuilder::~PartCompositeBuilder(UFG::PartCompositeBuilder::sInstance);
    operator delete[](v0);
  }
  UFG::PartCompositeBuilder::sInstance = 0i64;
}

// File Line: 287
// RVA: 0x1594C0
UFG::PartCompositeBuilder *__fastcall UFG::PartCompositeBuilder::Instance()
{
  return UFG::PartCompositeBuilder::sInstance;
}

// File Line: 300
// RVA: 0x153250
void __fastcall UFG::PartCompositeBuilder::PartCompositeBuilder(UFG::PartCompositeBuilder *this)
{
  UFG::PartCompositeBuilder *v1; // r15
  unsigned int v2; // esi
  unsigned int v3; // er12
  unsigned int v4; // er14
  unsigned int v5; // er13
  UFG::qResourceData *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceData *v8; // rbx
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceData *v10; // rbx
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceData *v12; // rbx
  UFG::qResourceWarehouse *v13; // rax
  unsigned int v14; // eax
  Illusion::Material *v15; // rbx
  int v16; // edi
  Illusion::Material *v17; // rbx
  unsigned int v18; // edi
  Illusion::Material *v19; // rbx
  int v20; // edi
  Illusion::Material *v21; // rbx
  int v22; // edi
  Illusion::Material *v23; // rbx
  int v24; // edi
  Illusion::Material *v25; // rbx
  Illusion::Material *v26; // rbx
  Illusion::Material *v27; // rbx
  UFG::qResourceWarehouse *v28; // rax
  const char **v29; // rbx
  const char **v30; // rdi
  unsigned int *v31; // rsi
  unsigned int *v32; // rdi
  unsigned int v33; // eax
  int v34; // edi
  Illusion::Material *v35; // rbx
  int v36; // edi
  Illusion::Material *v37; // rbx
  Illusion::Material *v38; // rbx
  Illusion::Material *v39; // rbx
  UFG::qResourceWarehouse *v40; // rax
  unsigned int v41; // eax
  int v42; // edi
  Illusion::Material *v43; // rbx
  int v44; // edi
  Illusion::Material *v45; // rbx
  unsigned int v46; // edi
  Illusion::Material *v47; // rbx
  Illusion::Material *v48; // rbx
  Illusion::Material *v49; // rbx
  UFG::qResourceWarehouse *v50; // rax
  unsigned int v51; // eax
  int v52; // edi
  Illusion::Material *v53; // rbx
  Illusion::Material *v54; // rbx
  Illusion::Material *v55; // rbx
  UFG::qResourceWarehouse *v56; // rax
  unsigned int v57; // eax
  int v58; // edi
  Illusion::Material *v59; // rbx
  Illusion::Material *v60; // rbx
  Illusion::Material *v61; // rbx
  Illusion::Material *v62; // rbx
  Illusion::Material *v63; // rbx
  UFG::qResourceWarehouse *v64; // rax
  UFG::qString v65; // [rsp+30h] [rbp-D0h]
  __int64 v66; // [rsp+58h] [rbp-A8h]
  int v67; // [rsp+60h] [rbp-A0h]
  int v68; // [rsp+64h] [rbp-9Ch]
  int v69; // [rsp+68h] [rbp-98h]
  __int64 v70; // [rsp+6Ch] [rbp-94h]
  int v71; // [rsp+74h] [rbp-8Ch]
  int v72; // [rsp+78h] [rbp-88h]
  __int128 v73; // [rsp+80h] [rbp-80h]
  __int128 v74; // [rsp+90h] [rbp-70h]
  __int64 v75; // [rsp+A0h] [rbp-60h]
  __int64 v76; // [rsp+A8h] [rbp-58h]
  __int64 v77; // [rsp+B0h] [rbp-50h]
  __int64 v78; // [rsp+B8h] [rbp-48h]
  __int64 v79; // [rsp+C0h] [rbp-40h]
  __int64 v80; // [rsp+C8h] [rbp-38h]
  int v81; // [rsp+D0h] [rbp-30h]
  char v82; // [rsp+D4h] [rbp-2Ch]
  __int64 v83; // [rsp+E0h] [rbp-20h]
  char dest; // [rsp+F0h] [rbp-10h]
  UFG::qList<UFG::CompositeBuild,UFG::CompositeBuild,1,0> *v85; // [rsp+238h] [rbp+138h]

  v83 = -2i64;
  v1 = this;
  this->mFreeTargets.p = 0i64;
  *(_QWORD *)&this->mFreeTargets.size = 0i64;
  v85 = &this->mPendingBuilds;
  v85->mNode.mPrev = &v85->mNode;
  v85->mNode.mNext = &v85->mNode;
  this->mProcessingBuild = 0i64;
  this->mMaterial = 0i64;
  this->mSobelFilterMaterial = 0i64;
  this->mDilateFilterMaterial = 0i64;
  this->mStampMaterial = 0i64;
  this->mColourMaterial = 0i64;
  this->mTempTarget512 = 0i64;
  UFG::qString::qString(&v65, "PartCompositeBuilder.TempTexture512");
  v70 = 1i64;
  v66 = 0i64;
  v67 = 1;
  v68 = 1;
  v69 = -1;
  v71 = 0;
  v72 = 1;
  _mm_store_si128((__m128i *)&v73, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v74, (__m128i)0i64);
  v75 = 0i64;
  v76 = 0i64;
  v77 = 0i64;
  v78 = 0i64;
  v79 = 0i64;
  v80 = 0i64;
  v81 = 0;
  v82 = 0;
  v66 = 2199023256064i64;
  LOBYTE(v69) = 0;
  v1->mTempTarget512 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v65);
  v2 = UFG::qStringHash32("PartCompositeBuilder.AlphaState.OnlyColour", 0xFFFFFFFF);
  v3 = UFG::qStringHash32("PartCompositeBuilder.AlphaState.OnlyAlpha", 0xFFFFFFFF);
  v4 = UFG::qStringHash32("PartCompositeBuilder.RasterState.OnlyColour", 0xFFFFFFFF);
  v5 = UFG::qStringHash32("PartCompositeBuilder.RasterState.OnlyAlpha", 0xFFFFFFFF);
  v6 = Illusion::Factory::NewAlphaState("PartCompositeBuilder.AlphaState.OnlyColour", v2, 0i64, 0i64, 0i64);
  LOWORD(v6[1].mNode.mParent) = 1025;
  BYTE2(v6[1].mNode.mParent) = 5;
  BYTE3(v6[1].mNode.mChild[0]) = 7;
  v7 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v7, v6);
  v8 = Illusion::Factory::NewAlphaState("PartCompositeBuilder.AlphaState.OnlyAlpha", v3, 0i64, 0i64, 0i64);
  LOWORD(v8[1].mNode.mParent) = 257;
  BYTE5(v8[1].mNode.mParent) = 0;
  BYTE2(v8[1].mNode.mParent) = 0;
  BYTE3(v8[1].mNode.mChild[0]) = 8;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, v8);
  v10 = Illusion::Factory::NewRasterState("PartCompositeBuilder.RasterState.OnlyColour", v4, 0i64, 0i64, 0i64);
  LOWORD(v10[1].mNode.mParent) = 0;
  BYTE3(v10[1].mNode.mParent) = 0;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, v10);
  v12 = Illusion::Factory::NewRasterState("PartCompositeBuilder.RasterState.OnlyAlpha", v5, 0i64, 0i64, 0i64);
  LOWORD(v12[1].mNode.mParent) = 0;
  BYTE3(v12[1].mNode.mParent) = 0;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v12);
  v14 = UFG::qStringHashUpper32("CharacterStudioMaterial", 0xFFFFFFFF);
  v15 = Illusion::Factory::NewMaterial("CharacterStudioMaterial", v14, 8u, 0i64, 0i64, 0i64);
  v1->mMaterial = v15;
  LOWORD(v15[1].mNode.mChild[0]) = 0;
  HIDWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v15[1].mTypeUID = -1957338719;
  LODWORD(v15[1].mResourceHandles.mNode.mNext) = 0;
  v16 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v17 = v1->mMaterial;
  *(_WORD *)&v17[1].mDebugName[12] = 0;
  *(_DWORD *)&v17[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v17[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v17[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v17[1].mStateBlockMask.mFlags[0]) = v16;
  v18 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v19 = v1->mMaterial;
  LOWORD(v19[1].mMaterialUser.mOffset) = 0;
  *(&v19[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v19[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v19[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v19[2].mNode.mUID = v18;
  v20 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v21 = v1->mMaterial;
  LOWORD(v21[2].mTypeUID) = 0;
  HIDWORD(v21[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v21[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texBlendMask", 0xFFFFFFFF);
  *((_DWORD *)&v21[2].0 + 22) = -1958479169;
  *(_DWORD *)&v21[2].mDebugName[28] = v20;
  v22 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v23 = v1->mMaterial;
  LOWORD(v23[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v23[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v23[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v23[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v23[3].mNode.mChild[0]) = v22;
  v24 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v25 = v1->mMaterial;
  LOWORD(v25[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v25[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v25[3].mNode.mUID = UFG::qStringHash32("texSpecular", 0xFFFFFFFF);
  *(_DWORD *)&v25[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v25[3].mDebugName[12] = v24;
  v26 = v1->mMaterial;
  *((_WORD *)&v26[3].0 + 44) = 0;
  *(_DWORD *)&v26[3].mDebugName[32] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v26[3].mDebugName[28] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v26[4].mNode.mParent) = 315097330;
  LODWORD(v26[3].mMaterialUser.mOffset) = v2;
  v27 = v1->mMaterial;
  LOWORD(v27[4].mNode.mChild[1]) = 0;
  HIDWORD(v27[4].mNode.mChild[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v27[4].mNode.mChild[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v27[4].mDebugName[4] = 1002903008;
  v27[4].mTypeUID = v4;
  v28 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v28, (UFG::qResourceData *)&v1->mMaterial->mNode);
  v29 = UFG::sTexNamesModifiers;
  v30 = UFG::sTexNamesModifiers;
  v31 = v1->mMaskCopyShaderUID;
  do
  {
    UFG::qSPrintf(&dest, "TEXTURECOMPMASKCOPY%s", *v30);
    *v31 = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
    ++v31;
    ++v30;
  }
  while ( (signed __int64)v30 < (signed __int64)&UFG::PartDebug::sDisplayOpacity );
  v32 = v1->mMaskDecalSphericalShaderUID;
  do
  {
    UFG::qSPrintf(&dest, "TEXTURECOMPMASKDECAL%s", *v29);
    *(v32 - 3) = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
    UFG::qSPrintf(&dest, "TEXTURECOMPMASKDECALSPHERICAL%s", *v29);
    *v32 = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
    UFG::qSPrintf(&dest, "TEXTURECOMPMASKDECALSPHERICALPLANAR%s", *v29);
    v32[3] = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
    UFG::qSPrintf(&dest, "TEXTURECOMPMASKDECALCYLINDRICAL%s", *v29);
    v32[6] = UFG::qStringHashUpper32(&dest, 0xFFFFFFFF);
    ++v32;
    ++v29;
  }
  while ( (signed __int64)v29 < (signed __int64)&UFG::PartDebug::sDisplayOpacity );
  v33 = UFG::qStringHash32("TEXTURECOMPMASKSOBEL", 0xFFFFFFFF);
  v1->mSobelFilterMaterial = Illusion::Factory::NewMaterial("TEXTURECOMPMASKSOBEL", v33, 4u, 0i64, 0i64, 0i64);
  v34 = UFG::qStringHash32("TEXTURECOMPNORMALMAPGEN", 0xFFFFFFFF);
  v35 = v1->mSobelFilterMaterial;
  LOWORD(v35[1].mNode.mChild[0]) = 0;
  HIDWORD(v35[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v35[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v35[1].mTypeUID = -1957338719;
  LODWORD(v35[1].mResourceHandles.mNode.mNext) = v34;
  v36 = UFG::qStringHashUpper32(v1->mTempTarget512->mTargetTexture[0]->mDebugName, 0xFFFFFFFF);
  v37 = v1->mSobelFilterMaterial;
  *(_WORD *)&v37[1].mDebugName[12] = 0;
  *(_DWORD *)&v37[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v37[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v37[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v37[1].mStateBlockMask.mFlags[0]) = v36;
  v38 = v1->mSobelFilterMaterial;
  LOWORD(v38[1].mMaterialUser.mOffset) = 0;
  *(&v38[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v38[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v38[2].mResourceHandles.mNode.mPrev) = 315097330;
  v38[2].mNode.mUID = -1551679522;
  v39 = v1->mSobelFilterMaterial;
  LOWORD(v39[2].mTypeUID) = 0;
  HIDWORD(v39[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v39[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v39[2].0 + 22) = 1002903008;
  *(_DWORD *)&v39[2].mDebugName[28] = 1660426324;
  v40 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v40, (UFG::qResourceData *)&v1->mSobelFilterMaterial->mNode);
  v41 = UFG::qStringHash32("TEXTURECOMPDILATEMAT", 0xFFFFFFFF);
  v1->mDilateFilterMaterial = Illusion::Factory::NewMaterial("TEXTURECOMPDILATEMAT", v41, 5u, 0i64, 0i64, 0i64);
  v42 = UFG::qStringHash32("TEXTURECOMPDILATE", 0xFFFFFFFF);
  v43 = v1->mDilateFilterMaterial;
  LOWORD(v43[1].mNode.mChild[0]) = 0;
  HIDWORD(v43[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v43[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v43[1].mTypeUID = -1957338719;
  LODWORD(v43[1].mResourceHandles.mNode.mNext) = v42;
  v44 = UFG::qStringHashUpper32(v1->mTempTarget512->mTargetTexture[0]->mDebugName, 0xFFFFFFFF);
  v45 = v1->mDilateFilterMaterial;
  *(_WORD *)&v45[1].mDebugName[12] = 0;
  *(_DWORD *)&v45[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v45[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v45[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v45[1].mStateBlockMask.mFlags[0]) = v44;
  v46 = UFG::qStringHashUpper32("MASK_DILATE", 0xFFFFFFFF);
  v47 = v1->mDilateFilterMaterial;
  LOWORD(v47[1].mMaterialUser.mOffset) = 0;
  *(&v47[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v47[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v47[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v47[2].mNode.mUID = v46;
  v48 = v1->mDilateFilterMaterial;
  LOWORD(v48[2].mTypeUID) = 0;
  HIDWORD(v48[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v48[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v48[2].0 + 22) = 315097330;
  *(_DWORD *)&v48[2].mDebugName[28] = 2015536557;
  v49 = v1->mDilateFilterMaterial;
  LOWORD(v49[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v49[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v49[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v49[3].mNode.mChild[1]) = 1002903008;
  LODWORD(v49[3].mNode.mChild[0]) = 1660426324;
  v50 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v50, (UFG::qResourceData *)&v1->mDilateFilterMaterial->mNode);
  v51 = UFG::qStringHash32("TEXTURECOMPSTAMP", 0xFFFFFFFF);
  v1->mStampMaterial = Illusion::Factory::NewMaterial("TEXTURECOMPSTAMP", v51, 3u, 0i64, 0i64, 0i64);
  v52 = UFG::qStringHash32("TEXTURECOMPSTAMP", 0xFFFFFFFF);
  v53 = v1->mStampMaterial;
  LOWORD(v53[1].mNode.mChild[0]) = 0;
  HIDWORD(v53[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v53[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v53[1].mTypeUID = -1957338719;
  LODWORD(v53[1].mResourceHandles.mNode.mNext) = v52;
  v54 = v1->mStampMaterial;
  *(_WORD *)&v54[1].mDebugName[12] = 0;
  *(_DWORD *)&v54[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v54[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v54[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v54[1].mStateBlockMask.mFlags[0]) = v3;
  v55 = v1->mStampMaterial;
  LOWORD(v55[1].mMaterialUser.mOffset) = 0;
  *(&v55[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v55[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v55[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v55[2].mNode.mUID = v5;
  v56 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v56, (UFG::qResourceData *)&v1->mStampMaterial->mNode);
  v57 = UFG::qStringHash32("SIMPLETEXTURECOMPCOLOUR", 0xFFFFFFFF);
  v1->mColourMaterial = Illusion::Factory::NewMaterial("SIMPLETEXTURECOMPCOLOUR", v57, 5u, 0i64, 0i64, 0i64);
  v58 = UFG::qStringHash32("TEXTURECOMPSIMPLECOLOUR", 0xFFFFFFFF);
  v59 = v1->mColourMaterial;
  LOWORD(v59[1].mNode.mChild[0]) = 0;
  HIDWORD(v59[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v59[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v59[1].mTypeUID = -1957338719;
  LODWORD(v59[1].mResourceHandles.mNode.mNext) = v58;
  v60 = v1->mColourMaterial;
  *(_WORD *)&v60[1].mDebugName[12] = 0;
  *(_DWORD *)&v60[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v60[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v60[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v60[1].mStateBlockMask.mFlags[0]) = 662883558;
  v61 = v1->mColourMaterial;
  LOWORD(v61[1].mMaterialUser.mOffset) = 0;
  *(&v61[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v61[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v61[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v61[2].mNode.mUID = 1660426324;
  v62 = v1->mColourMaterial;
  LOWORD(v62[2].mTypeUID) = 0;
  HIDWORD(v62[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v62[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v62[2].0 + 22) = -1958479169;
  *(_DWORD *)&v62[2].mDebugName[28] = 0;
  v63 = v1->mColourMaterial;
  LOWORD(v63[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v63[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v63[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texBlendMask", 0xFFFFFFFF);
  LODWORD(v63[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v63[3].mNode.mChild[0]) = 0;
  v64 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v64, (UFG::qResourceData *)&v1->mColourMaterial->mNode);
  UFG::qString::~qString(&v65);
}

// File Line: 449
// RVA: 0x154F30
void __fastcall UFG::PartCompositeBuilder::~PartCompositeBuilder(UFG::PartCompositeBuilder *this)
{
  UFG::PartCompositeBuilder *v1; // rdi
  Illusion::Target *v2; // rcx
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *v9; // rbx
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceData *v11; // rbx
  UFG::qResourceWarehouse *v12; // rax
  unsigned int i; // ebx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v14; // rcx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v15; // rax
  Illusion::Target **v16; // rcx

  v1 = this;
  v2 = this->mTempTarget512;
  if ( v2 )
  {
    Illusion::DeleteTarget(v2, 1);
    v1->mTempTarget512 = 0i64;
  }
  v3 = (UFG::qResourceData *)&v1->mMaterial->mNode;
  if ( v3 )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v4, v3);
    UFG::LibCurlFree(v1->mMaterial);
    v1->mMaterial = 0i64;
  }
  v5 = (UFG::qResourceData *)&v1->mSobelFilterMaterial->mNode;
  if ( v5 )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v6, v5);
    UFG::LibCurlFree(v1->mSobelFilterMaterial);
    v1->mSobelFilterMaterial = 0i64;
  }
  v7 = (UFG::qResourceData *)&v1->mDilateFilterMaterial->mNode;
  if ( v7 )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v8, v7);
    UFG::LibCurlFree(v1->mDilateFilterMaterial);
    v1->mDilateFilterMaterial = 0i64;
  }
  v9 = (UFG::qResourceData *)&v1->mStampMaterial->mNode;
  if ( v9 )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v10, v9);
    UFG::LibCurlFree(v1->mStampMaterial);
    v1->mStampMaterial = 0i64;
  }
  v11 = (UFG::qResourceData *)&v1->mColourMaterial->mNode;
  if ( v11 )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v12, v11);
    UFG::LibCurlFree(v1->mColourMaterial);
    v1->mColourMaterial = 0i64;
  }
  for ( i = 0; i < v1->mFreeTargets.size; ++i )
    Illusion::DeleteTarget(v1->mFreeTargets.p[i], 1);
  v1->mFreeTargets.size = 0;
  UFG::qList<UFG::CompositeBuild,UFG::CompositeBuild,1,0>::DeleteNodes(&v1->mPendingBuilds);
  v14 = v1->mPendingBuilds.mNode.mPrev;
  v15 = v1->mPendingBuilds.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v1->mPendingBuilds.mNode.mPrev = &v1->mPendingBuilds.mNode;
  v1->mPendingBuilds.mNode.mNext = &v1->mPendingBuilds.mNode;
  v16 = v1->mFreeTargets.p;
  if ( v16 )
    operator delete[](v16);
  v1->mFreeTargets.p = 0i64;
  *(_QWORD *)&v1->mFreeTargets.size = 0i64;
}

// File Line: 526
// RVA: 0x15B010
void __fastcall UFG::PartCompositeBuilder::SubmitCompositeBuild(UFG::PartCompositeBuilder *this, UFG::PartCompositeBuilder::CompositeBuildParams *buildParams)
{
  UFG::PartCompositeBuilder::CompositeBuildParams *v2; // rbx
  UFG::PartCompositeBuilder *v3; // rdi
  char *v4; // rax
  char *v5; // r8
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v6; // rax
  _QWORD *v7; // [rsp+48h] [rbp+10h]

  v2 = buildParams;
  v3 = this;
  v4 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v5 = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    *((_QWORD *)v4 + 2) = 0i64;
    v7 = v4 + 40;
    *v7 = v7;
    v7[1] = v7;
    *((_QWORD *)v4 + 7) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  *((_QWORD *)v5 + 2) = v2->mDefinition;
  *((_QWORD *)v5 + 3) = v2->mDefinition->mTextureData;
  *((_QWORD *)v5 + 8) = v2->mCallback;
  *((_QWORD *)v5 + 9) = v2->mCallbackParam;
  v5[32] = v2->mResetTextures;
  v6 = v3->mPendingBuilds.mNode.mPrev;
  v6->mNext = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)v5;
  *(_QWORD *)v5 = v6;
  *((_QWORD *)v5 + 1) = (char *)v3 + 16;
  v3->mPendingBuilds.mNode.mPrev = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)v5;
}

// File Line: 539
// RVA: 0x156330
Illusion::Target *__fastcall UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder *this)
{
  unsigned int v1; // er9
  __int64 v2; // r8
  Illusion::Target *result; // rax
  Illusion::Target *v4; // rbx
  UFG::qString v5; // [rsp+20h] [rbp-E0h]
  __int64 v6; // [rsp+48h] [rbp-B8h]
  int v7; // [rsp+50h] [rbp-B0h]
  int v8; // [rsp+54h] [rbp-ACh]
  int v9; // [rsp+58h] [rbp-A8h]
  __int64 v10; // [rsp+5Ch] [rbp-A4h]
  int v11; // [rsp+64h] [rbp-9Ch]
  int v12; // [rsp+68h] [rbp-98h]
  __int128 v13; // [rsp+70h] [rbp-90h]
  __int128 v14; // [rsp+80h] [rbp-80h]
  __int64 v15; // [rsp+90h] [rbp-70h]
  __int64 v16; // [rsp+98h] [rbp-68h]
  __int64 v17; // [rsp+A0h] [rbp-60h]
  __int64 v18; // [rsp+A8h] [rbp-58h]
  __int64 v19; // [rsp+B0h] [rbp-50h]
  __int64 v20; // [rsp+B8h] [rbp-48h]
  int v21; // [rsp+C0h] [rbp-40h]
  char v22; // [rsp+C4h] [rbp-3Ch]
  __int64 v23; // [rsp+D0h] [rbp-30h]
  char dest; // [rsp+E0h] [rbp-20h]

  v23 = -2i64;
  v1 = this->mFreeTargets.size;
  if ( this->mFreeTargets.size )
  {
    v2 = v1 - 1;
    result = this->mFreeTargets.p[v2];
    if ( v1 <= 1 )
      LODWORD(v2) = 0;
    this->mFreeTargets.size = v2;
  }
  else
  {
    UFG::qSPrintf(&dest, 256, "PartCompositeBuilder_%d", (unsigned int)UFG::PartCompositeBuilder::sRenderTargetIndex);
    UFG::qString::qString(&v5, &dest);
    v10 = 1i64;
    v6 = 0i64;
    v7 = 1;
    v8 = 1;
    v9 = -1;
    v11 = 0;
    v12 = 1;
    _mm_store_si128((__m128i *)&v13, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v14, (__m128i)0i64);
    v15 = 0i64;
    v16 = 0i64;
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    v21 = 0;
    v22 = 0;
    v6 = 2199023256064i64;
    LOBYTE(v9) = 0;
    v4 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v5);
    ++UFG::PartCompositeBuilder::sRenderTargetIndex;
    UFG::qString::~qString(&v5);
    result = v4;
  }
  return result;
}

// File Line: 566
// RVA: 0x156F50
void __fastcall UFG::PartCompositeBuilder::BuildCommandList(UFG::PartCompositeBuilder *this, UFG::CompositeBuild *build)
{
  UFG::CompositeBuild *v2; // rdi
  UFG::PartCompositeBuilder *v3; // rbp
  UFG::PartTemplateInstance *v4; // rax
  unsigned int v5; // er8
  __int64 v6; // r14
  __int64 v7; // r12
  __int64 v8; // r11
  UFG::PartTemplateInstance::SlotEntry *v9; // r13
  char v10; // dl
  __int64 v11; // r8
  unsigned int v12; // er9
  UFG::PartTextureData::Textures *v13; // r15
  unsigned int v14; // ebx
  UFG::qList<UFG::BuildOp,UFG::BuildOp,1,0> *v15; // rsi
  Illusion::Target *v16; // rdi
  char *v17; // rax
  char *v18; // rdx
  _QWORD *v19; // rcx
  __int64 *v20; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> **v21; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> *v22; // rax
  char *v23; // rax
  char *v24; // rdx
  _QWORD *v25; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> **v26; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> *v27; // rax
  unsigned int v28; // eax
  unsigned int v29; // ecx
  char *v30; // rax
  char *v31; // rdx
  _QWORD *v32; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> **v33; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> *v34; // rax
  int v35; // [rsp+28h] [rbp-60h]
  int v36; // [rsp+2Ch] [rbp-5Ch]
  __int64 v37; // [rsp+30h] [rbp-58h]
  __int64 v38; // [rsp+38h] [rbp-50h]
  __int64 v39; // [rsp+40h] [rbp-48h]
  UFG::CompositeBuild *v40; // [rsp+98h] [rbp+10h]
  __int64 v41; // [rsp+A0h] [rbp+18h]

  v40 = build;
  v2 = build;
  v3 = this;
  v4 = build->mDefinition;
  v5 = v4->mSlots.mData.mNumItems;
  if ( v5 )
  {
    v6 = 0i64;
    v7 = 0i64;
    v8 = v5;
    v41 = v4->mSlots.mData.mNumItems;
    do
    {
      v9 = v2->mDefinition->mSlots.mData.mItems;
      if ( v9[v7].mBasePart.mPart.mData )
      {
        v10 = 0;
        v11 = 0i64;
        v12 = v9[v7].mLayers.mData.mNumItems;
        if ( v12 )
        {
          do
          {
            if ( v9[v7].mLayers.mData.mItems[v11].mPart.mData )
              v10 = 1;
            v11 = (unsigned int)(v11 + 1);
          }
          while ( (unsigned int)v11 < v12 );
          if ( v10 )
          {
            v13 = v3->mProcessingBuild->mData->mParts.p;
            v14 = 0;
            v15 = &v2->mCommandList;
            do
            {
              v16 = 0i64;
              if ( v14 )
              {
                if ( v14 == 1 )
                {
                  v16 = v13[v6].mNormTarget;
                }
                else if ( v14 == 2 )
                {
                  v16 = v13[v6].mSpecTarget;
                }
              }
              else
              {
                v16 = v13[v6].mDiffuseTarget;
              }
              v17 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
              v18 = v17;
              if ( v17 )
              {
                v19 = v17 + 8;
                *v19 = v19;
                v19[1] = v19;
                *(_QWORD *)v17 = &UFG::BuildOp::`vftable';
                *(_QWORD *)v17 = &UFG::ClearView::`vftable';
              }
              else
              {
                v18 = 0i64;
              }
              *((_QWORD *)v18 + 3) = v3->mTempTarget512;
              if ( v14 == 1 )
              {
                v35 = 1056964608;
                v36 = 1056964608;
                v37 = 1056964608i64;
                v20 = (__int64 *)&v35;
              }
              else
              {
                v38 = 0i64;
                v39 = 0i64;
                v20 = &v38;
              }
              *((_DWORD *)v18 + 8) = *(_DWORD *)v20;
              *((_DWORD *)v18 + 9) = *((_DWORD *)v20 + 1);
              *((_DWORD *)v18 + 10) = *((_DWORD *)v20 + 2);
              *((_DWORD *)v18 + 11) = *((_DWORD *)v20 + 3);
              v21 = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> **)(v18 + 8);
              v22 = v15->mNode.mPrev;
              v22->mNext = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v18 + 8);
              *v21 = v22;
              v21[1] = &v15->mNode;
              v15->mNode.mPrev = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v18 + 8);
              v23 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
              v24 = v23;
              if ( v23 )
              {
                v25 = v23 + 8;
                *v25 = v25;
                v25[1] = v25;
                *(_QWORD *)v23 = &UFG::BuildOp::`vftable';
                *(_QWORD *)v23 = &UFG::RenderPartToTexture::`vftable';
              }
              else
              {
                v24 = 0i64;
              }
              *((_QWORD *)v24 + 3) = v3->mTempTarget512;
              *((_QWORD *)v24 + 7) = (char *)&v9[v7] + 8;
              *((_DWORD *)v24 + 8) = v14;
              *((_QWORD *)v24 + 5) = v3->mMaterial;
              *((_QWORD *)v24 + 6) = (char *)v3 + 40;
              v26 = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> **)(v24 + 8);
              v27 = v15->mNode.mPrev;
              v27->mNext = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v24 + 8);
              *v26 = v27;
              v26[1] = &v15->mNode;
              v15->mNode.mPrev = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v24 + 8);
              v28 = 0;
              v29 = v9[v7].mLayers.mData.mNumItems;
              if ( v29 )
              {
                do
                  ++v28;
                while ( v28 < v29 );
              }
              v30 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
              v31 = v30;
              if ( v30 )
              {
                v32 = v30 + 8;
                *v32 = v32;
                v32[1] = v32;
                *(_QWORD *)v30 = &UFG::BuildOp::`vftable';
                *(_QWORD *)v30 = &UFG::DilateTexture::`vftable';
              }
              else
              {
                v31 = 0i64;
              }
              *((_QWORD *)v31 + 4) = v3->mTempTarget512;
              *((_QWORD *)v31 + 3) = v16;
              *((_QWORD *)v31 + 5) = v3->mDilateFilterMaterial;
              v33 = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> **)(v31 + 8);
              v34 = v15->mNode.mPrev;
              v34->mNext = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v31 + 8);
              *v33 = v34;
              v33[1] = &v15->mNode;
              v15->mNode.mPrev = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v31 + 8);
              ++v14;
            }
            while ( v14 < 3 );
            v8 = v41;
            v2 = v40;
          }
        }
      }
      ++v7;
      ++v6;
      v41 = --v8;
    }
    while ( v8 );
  }
}

// File Line: 678
// RVA: 0x15B160
void __fastcall UFG::PartCompositeBuilder::Update(UFG::PartCompositeBuilder *this, float deltaTime)
{
  UFG::CompositeBuild *v2; // rdx
  UFG::PartCompositeBuilder *v3; // rbx
  UFG::CompositeBuild *v4; // rcx
  void (__fastcall *v5)(UFG::PartTemplateInstance *, void *); // rax
  UFG::CompositeBuild *v6; // rcx

  v2 = this->mProcessingBuild;
  v3 = this;
  if ( v2 && (bool *)v2->mCurrentOperation == &v2->mResetTextures )
  {
    if ( UFG::PartCompositeBuilder::sLoopBuild )
    {
      v2->mCurrentOperation = (UFG::BuildOp *)&v2->mCommandList.mNode.mNext[-1].mNext;
    }
    else
    {
      v2->mDefinition->mCompositeDirty = 0;
      v4 = this->mProcessingBuild;
      v5 = v4->mCallbackFunc;
      if ( v5 )
        v5(v4->mDefinition, v4->mCallbackParam);
      v6 = v3->mProcessingBuild;
      if ( v6 )
        UFG::CompositeBuild::`scalar deleting destructor'(v6, 1);
      v3->mProcessingBuild = 0i64;
    }
  }
}

// File Line: 700
// RVA: 0x15A2D0
char __fastcall UFG::PartCompositeBuilder::RenderComposites(UFG::PartCompositeBuilder *this, Illusion::SubmitContext *submitContext)
{
  Illusion::SubmitContext *v2; // r15
  UFG::PartCompositeBuilder *v3; // rbx
  char v4; // si
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v6; // r14
  UFG::PartTemplateInstance *v7; // rdi
  UFG::PartTextureData *v8; // rbp
  char *v9; // rax
  UFG::PartTextureData *v10; // rax
  UFG::CompositeBuild *v11; // rdx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v12; // rcx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v13; // rax
  UFG::CompositeBuild *v14; // rcx
  bool v15; // al

  v2 = submitContext;
  v3 = this;
  v4 = 0;
  if ( *(_OWORD *)&this->mPendingBuilds.mNode.mNext != (unsigned __int64)&this->mPendingBuilds )
  {
    if ( UFG::PartCompositeBuilder::sSingleStepBuild )
    {
      if ( !UFG::PartCompositeBuilder::sStepThisFrame )
        return 0;
      UFG::PartCompositeBuilder::sStepThisFrame = 0;
    }
    if ( !this->mProcessingBuild )
    {
      v6 = this->mPendingBuilds.mNode.mNext;
      v7 = (UFG::PartTemplateInstance *)v6[1].mPrev;
      if ( (unsigned __int8)UFG::PartTemplateInstance::AllPartsLoaded((UFG::PartTemplateInstance *)v6[1].mPrev) )
      {
        if ( LOBYTE(v6[2].mPrev) )
        {
          v8 = v7->mTextureData;
          if ( v8 )
          {
            UFG::PartTextureData::~PartTextureData(v7->mTextureData);
            operator delete[](v8);
            v7->mTextureData = 0i64;
          }
        }
        if ( !v7->mTextureData )
        {
          v9 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
          if ( v9 )
            UFG::PartTextureData::PartTextureData((UFG::PartTextureData *)v9, v7);
          else
            v10 = 0i64;
          v7->mTextureData = v10;
        }
        v6[1].mNext = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)v7->mTextureData;
        v11 = (UFG::CompositeBuild *)v3->mPendingBuilds.mNode.mNext;
        v12 = v11->mPrev;
        v13 = v11->mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)&v11->mPrev;
        v11->mNext = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)&v11->mPrev;
        v3->mProcessingBuild = v11;
        if ( v11->mDefinition->mCompositeDirty )
          UFG::PartCompositeBuilder::BuildCommandList(v3, v11);
        v3->mProcessingBuild->mCurrentOperation = (UFG::BuildOp *)&v3->mProcessingBuild->mCommandList.mNode.mNext[-1].mNext;
      }
    }
    v14 = v3->mProcessingBuild;
    if ( v14 && (bool *)v14->mCurrentOperation != &v14->mResetTextures )
    {
      while ( 1 )
      {
        v15 = v3->mProcessingBuild->mCurrentOperation->vfptr->Execute(v3->mProcessingBuild->mCurrentOperation, v2);
        v3->mProcessingBuild->mCurrentOperation = (UFG::BuildOp *)&v3->mProcessingBuild->mCurrentOperation->mNext[-1].mNext;
        if ( v15 || UFG::PartCompositeBuilder::sSingleStepBuild )
          break;
        if ( v3->mProcessingBuild->mCurrentOperation == (UFG::BuildOp *)&v3->mProcessingBuild->mResetTextures )
          return v4;
      }
      v4 = 1;
      if ( UFG::PartCompositeBuilder::sSingleStepBuild )
        v4 = 0;
    }
  }
  return v4;
}

// File Line: 768
// RVA: 0x15A490
void __fastcall UFG::PartCompositeBuilder::RenderDebugOverlay(UFG::PartCompositeBuilder *this, Render::View *view)
{
  Render::View *v2; // rsi
  UFG::PartCompositeBuilder *v3; // rbp
  UFG::CompositeBuild *v4; // rax
  UFG::PartTextureData *v5; // rdi
  float v6; // xmm0_4
  int v7; // eax
  UFG::PartTextureData::Textures *v8; // rdi
  Render::Poly poly; // [rsp+90h] [rbp+18h]
  Render::Poly v10; // [rsp+98h] [rbp+20h]

  v2 = view;
  v3 = this;
  if ( UFG::PartCompositeBuilder::sRenderDebugOverlay && UFG::PartCompositeBuilder::sRenderPartTargets )
  {
    v4 = this->mProcessingBuild;
    if ( v4 )
    {
      v5 = v4->mData;
      v6 = (float)UFG::PartCompositeBuilder::sRenderPartIndex;
      v7 = v5->mParts.size - 1;
      if ( (float)UFG::PartCompositeBuilder::sRenderPartIndex >= (float)v7 )
        v6 = (float)v7;
      v8 = v5->mParts.p;
      Render::Poly::Poly(&poly, 0.0, 0.0, 0.2, 0.35555556, 0.0);
      Render::View::Draw(v2, &poly, v3->mTempTarget512->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      if ( v8[v6].mDiffuseTarget )
      {
        Render::Poly::Poly(&v10, 0.21000001, 0.0, 0.2, 0.35555556, 0.0);
        Render::View::Draw(v2, &v10, v8[v6].mDiffuseTarget->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      }
      if ( v8[v6].mNormTarget )
      {
        Render::Poly::Poly(&v10, 0.0, 0.36555555, 0.2, 0.35555556, 0.0);
        Render::View::Draw(v2, &v10, v8[v6].mNormTarget->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      }
      if ( v8[v6].mSpecTarget )
      {
        Render::Poly::Poly(&v10, 0.21000001, 0.36555555, 0.2, 0.35555556, 0.0);
        Render::View::Draw(v2, &v10, v8[v6].mSpecTarget->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      }
    }
  }
}

