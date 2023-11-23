// File Line: 34
// RVA: 0x1585F0
bool __fastcall UFG::ClearView::Execute(UFG::ClearView *this, Illusion::SubmitContext *submit_context)
{
  Render::ViewSettings *Identity; // rax
  Render::View v6; // [rsp+50h] [rbp-198h] BYREF

  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&v6, Identity, submit_context);
  Render::View::BeginTarget(&v6, this->mTarget, "ClearView::Execute", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v6, &this->mColour, 1u, 0.0, 0);
  Render::View::EndTarget(&v6);
  return 0;
}

// File Line: 182
// RVA: 0x158690
char __fastcall UFG::DilateTexture::Execute(UFG::DilateTexture *this, Illusion::SubmitContext *submit_context)
{
  Render::ViewSettings *Identity; // rax
  _WORD *v5; // rbx
  Illusion::Material *mMaterial; // rdi
  unsigned int mUID; // r8d
  __int64 mOffset; // rax
  _WORD *v9; // rax
  unsigned int v10; // eax
  Illusion::Material *v11; // rdi
  __int64 v12; // rax
  Render::View v14; // [rsp+50h] [rbp-198h] BYREF
  Render::Poly poly; // [rsp+1F0h] [rbp+8h] BYREF

  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&v14, Identity, submit_context);
  v5 = 0i64;
  Render::View::BeginTarget(&v14, this->mTarget, "PartCompositeBuilder", 0, 0, 0i64, 1, 0, 0, 0);
  mMaterial = this->mMaterial;
  mUID = this->mSourceTarget->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
      mMaterial[1].mStateBlockMask.mFlags[1],
      mUID);
    mOffset = mMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v9 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
    else
      v9 = 0i64;
    *v9 |= 0x20u;
  }
  v10 = UFG::qStringHashUpper32("DefaultWhite", 0xFFFFFFFF);
  v11 = this->mMaterial;
  if ( v11[2].mNode.mUID != v10 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v11[2],
      (unsigned int)v11[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      v10);
    v12 = v11->mMaterialUser.mOffset;
    if ( v12 )
      v5 = (_WORD *)((char *)&v11->mMaterialUser + v12);
    *v5 |= 0x20u;
  }
  Render::Poly::Poly(&poly, 0.0, 0.0, 1.0, 1.0, 1.0 / (float)this->mTarget->mWidth);
  Render::View::Draw(&v14, &poly, this->mMaterial, 0i64);
  Render::View::EndTarget(&v14);
  return 1;
}

// File Line: 216
// RVA: 0x154830
void __fastcall UFG::PartTextureData::PartTextureData(UFG::PartTextureData *this, UFG::PartTemplateInstance *instance)
{
  __int64 mNumItems; // rbp
  unsigned int size; // ecx
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  unsigned int v10; // eax
  __int64 v11; // rsi
  __int64 v12; // r14
  UFG::PartTemplateInstance::SlotEntry *mItems; // rbx
  UFG::PartTextureData::Textures *v14; // r15
  char v15; // dl
  __int64 v16; // r8
  unsigned int v17; // r9d

  this->mParts.p = 0i64;
  *(_QWORD *)&this->mParts.size = 0i64;
  mNumItems = instance->mSlots.mData.mNumItems;
  size = this->mParts.size;
  v6 = instance->mSlots.mData.mNumItems - size;
  if ( v6 <= 0 )
  {
    v10 = size - instance->mSlots.mData.mNumItems;
    if ( v10 )
    {
      if ( v10 < size )
        this->mParts.size = instance->mSlots.mData.mNumItems;
      else
        this->mParts.size = 0;
    }
  }
  else
  {
    v7 = instance->mSlots.mData.mNumItems;
    capacity = this->mParts.capacity;
    if ( size + v6 > capacity )
    {
      if ( capacity )
        v9 = 2 * capacity;
      else
        v9 = 1;
      for ( ; v9 < v7; v9 *= 2 )
        ;
      if ( v9 - v7 > 0x10000 )
        v9 = v7 + 0x10000;
      UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(&this->mParts, v9, "qArray.Reallocate(Resize)");
    }
    this->mParts.size = v7;
  }
  if ( (_DWORD)mNumItems )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      mItems = instance->mSlots.mData.mItems;
      v14 = &this->mParts.p[v11];
      UFG::qMemSet(v14, 0, 0x18u);
      if ( mItems[v12].mBasePart.mPart.mData )
      {
        v15 = 0;
        v16 = 0i64;
        v17 = mItems[v12].mLayers.mData.mNumItems;
        if ( v17 )
        {
          do
          {
            if ( mItems[v12].mLayers.mData.mItems[v16].mPart.mData )
              v15 = 1;
            v16 = (unsigned int)(v16 + 1);
          }
          while ( (unsigned int)v16 < v17 );
          if ( v15 )
          {
            v14->mDiffuseTarget = UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder::sInstance);
            v14->mNormTarget = UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder::sInstance);
            v14->mSpecTarget = UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder::sInstance);
          }
        }
      }
      ++v12;
      ++v11;
      --mNumItems;
    }
    while ( mNumItems );
  }
}

// File Line: 234
// RVA: 0x155730
void __fastcall UFG::PartTextureData::~PartTextureData(UFG::PartTextureData *this)
{
  UFG::PartTextureData *v1; // rbx
  unsigned int i; // r13d
  UFG::PartTextureData::Textures *v3; // r12
  Illusion::Target *mDiffuseTarget; // r15
  UFG::PartCompositeBuilder *v5; // rdi
  __int64 size; // r14
  unsigned int v7; // esi
  unsigned int capacity; // ebx
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  char *v11; // rax
  char *v12; // rbp
  __int64 j; // r9
  Illusion::Target *mNormTarget; // r15
  UFG::PartCompositeBuilder *v15; // rdi
  __int64 v16; // r14
  unsigned int v17; // esi
  unsigned int v18; // ebx
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  char *v21; // rax
  char *v22; // rbp
  __int64 k; // r9
  Illusion::Target *mSpecTarget; // r15
  UFG::PartCompositeBuilder *v25; // rdi
  __int64 v26; // r14
  unsigned int v27; // esi
  unsigned int v28; // ebx
  unsigned int v29; // ebx
  unsigned __int64 v30; // rax
  char *v31; // rax
  char *v32; // rbp
  __int64 m; // r9
  UFG::PartTextureData::Textures *p; // rcx

  v1 = this;
  for ( i = 0; i < this->mParts.size; v1 = this )
  {
    v3 = &v1->mParts.p[i];
    mDiffuseTarget = v3->mDiffuseTarget;
    if ( v3->mDiffuseTarget )
    {
      v5 = UFG::PartCompositeBuilder::sInstance;
      size = UFG::PartCompositeBuilder::sInstance->mFreeTargets.size;
      v7 = size + 1;
      capacity = UFG::PartCompositeBuilder::sInstance->mFreeTargets.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v9 = 2 * capacity;
        else
          v9 = 1;
        for ( ; v9 < v7; v9 *= 2 )
          ;
        if ( v9 <= 2 )
          v9 = 2;
        if ( v9 - v7 > 0x10000 )
          v9 = size + 65537;
        if ( v9 != (_DWORD)size )
        {
          v10 = 8i64 * v9;
          if ( !is_mul_ok(v9, 8ui64) )
            v10 = -1i64;
          v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
          v12 = v11;
          if ( v5->mFreeTargets.p )
          {
            for ( j = 0i64; (unsigned int)j < v5->mFreeTargets.size; j = (unsigned int)(j + 1) )
              *(_QWORD *)&v11[8 * j] = v5->mFreeTargets.p[j];
            operator delete[](v5->mFreeTargets.p);
          }
          v5->mFreeTargets.p = (Illusion::Target **)v12;
          v5->mFreeTargets.capacity = v9;
        }
      }
      v5->mFreeTargets.size = v7;
      v5->mFreeTargets.p[size] = mDiffuseTarget;
      v3->mDiffuseTarget = 0i64;
    }
    mNormTarget = v3->mNormTarget;
    if ( mNormTarget )
    {
      v15 = UFG::PartCompositeBuilder::sInstance;
      v16 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.size;
      v17 = v16 + 1;
      v18 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.capacity;
      if ( (int)v16 + 1 > v18 )
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
            for ( k = 0i64; (unsigned int)k < v15->mFreeTargets.size; k = (unsigned int)(k + 1) )
              *(_QWORD *)&v21[8 * k] = v15->mFreeTargets.p[k];
            operator delete[](v15->mFreeTargets.p);
          }
          v15->mFreeTargets.p = (Illusion::Target **)v22;
          v15->mFreeTargets.capacity = v19;
        }
      }
      v15->mFreeTargets.size = v17;
      v15->mFreeTargets.p[v16] = mNormTarget;
      v3->mNormTarget = 0i64;
    }
    mSpecTarget = v3->mSpecTarget;
    if ( mSpecTarget )
    {
      v25 = UFG::PartCompositeBuilder::sInstance;
      v26 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.size;
      v27 = v26 + 1;
      v28 = UFG::PartCompositeBuilder::sInstance->mFreeTargets.capacity;
      if ( (int)v26 + 1 > v28 )
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
            for ( m = 0i64; (unsigned int)m < v25->mFreeTargets.size; m = (unsigned int)(m + 1) )
              *(_QWORD *)&v31[8 * m] = v25->mFreeTargets.p[m];
            operator delete[](v25->mFreeTargets.p);
          }
          v25->mFreeTargets.p = (Illusion::Target **)v32;
          v25->mFreeTargets.capacity = v29;
        }
      }
      v25->mFreeTargets.size = v27;
      v25->mFreeTargets.p[v26] = mSpecTarget;
      v3->mSpecTarget = 0i64;
    }
    ++i;
  }
  p = v1->mParts.p;
  if ( p )
    operator delete[](p);
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
  unsigned int v2; // esi
  unsigned int v3; // r12d
  unsigned int v4; // r14d
  unsigned int v5; // r13d
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
  Illusion::Material *mMaterial; // rbx
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
  unsigned int *mMaskCopyShaderUID; // rsi
  unsigned int *mMaskDecalSphericalShaderUID; // rdi
  unsigned int v33; // eax
  int v34; // edi
  Illusion::Material *mSobelFilterMaterial; // rbx
  int v36; // edi
  Illusion::Material *v37; // rbx
  Illusion::Material *v38; // rbx
  Illusion::Material *v39; // rbx
  UFG::qResourceWarehouse *v40; // rax
  unsigned int v41; // eax
  int v42; // edi
  Illusion::Material *mDilateFilterMaterial; // rbx
  int v44; // edi
  Illusion::Material *v45; // rbx
  unsigned int v46; // edi
  Illusion::Material *v47; // rbx
  Illusion::Material *v48; // rbx
  Illusion::Material *v49; // rbx
  UFG::qResourceWarehouse *v50; // rax
  unsigned int v51; // eax
  int v52; // edi
  Illusion::Material *mStampMaterial; // rbx
  Illusion::Material *v54; // rbx
  Illusion::Material *v55; // rbx
  UFG::qResourceWarehouse *v56; // rax
  unsigned int v57; // eax
  int v58; // edi
  Illusion::Material *mColourMaterial; // rbx
  Illusion::Material *v60; // rbx
  Illusion::Material *v61; // rbx
  Illusion::Material *v62; // rbx
  Illusion::Material *v63; // rbx
  UFG::qResourceWarehouse *v64; // rax
  Illusion::CreateTargetParams v65; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v66; // [rsp+E0h] [rbp-20h]
  char dest[304]; // [rsp+F0h] [rbp-10h] BYREF

  v66 = -2i64;
  this->mFreeTargets.p = 0i64;
  *(_QWORD *)&this->mFreeTargets.size = 0i64;
  this->mPendingBuilds.mNode.mPrev = &this->mPendingBuilds.mNode;
  this->mPendingBuilds.mNode.mNext = &this->mPendingBuilds.mNode;
  this->mProcessingBuild = 0i64;
  this->mMaterial = 0i64;
  this->mSobelFilterMaterial = 0i64;
  this->mDilateFilterMaterial = 0i64;
  this->mStampMaterial = 0i64;
  this->mColourMaterial = 0i64;
  this->mTempTarget512 = 0i64;
  UFG::qString::qString(&v65.name, "PartCompositeBuilder.TempTexture512");
  *(_QWORD *)&v65.num_mrt = 1i64;
  v65.depth = 1;
  v65.array_size = 1;
  *(_DWORD *)v65.mrt_formats = -256;
  v65.target_flags = 0;
  v65.num_mips = 1;
  memset(v65.textures, 0, 85);
  *(_QWORD *)&v65.width = 0x20000000200i64;
  this->mTempTarget512 = Illusion::CreateTarget(&v65);
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
  this->mMaterial = v15;
  LOWORD(v15[1].mNode.mChild[0]) = 0;
  HIDWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v15[1].mTypeUID = -1957338719;
  LODWORD(v15[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 0;
  v16 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  mMaterial = this->mMaterial;
  *(_WORD *)&mMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&mMaterial[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&mMaterial[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(mMaterial[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) = v16;
  v18 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v19 = this->mMaterial;
  LOWORD(v19[1].mMaterialUser.mOffset) = 0;
  *(&v19[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v19[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v19[2].mNode.mUID = v18;
  v20 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v21 = this->mMaterial;
  LOWORD(v21[2].mTypeUID) = 0;
  HIDWORD(v21[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v21[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texBlendMask", 0xFFFFFFFF);
  *((_DWORD *)&v21[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v21[2].mDebugName[28] = v20;
  v22 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v23 = this->mMaterial;
  LOWORD(v23[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v23[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v23[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v23[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v23[3].mNode.mChild[0]) = v22;
  v24 = UFG::qStringHash32("DEFAULTALPHA", 0xFFFFFFFF);
  v25 = this->mMaterial;
  LOWORD(v25[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v25[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v25[3].mNode.mUID = UFG::qStringHash32("texSpecular", 0xFFFFFFFF);
  *(_DWORD *)&v25[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v25[3].mDebugName[12] = v24;
  v26 = this->mMaterial;
  *((_WORD *)&v26[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v26[3].mDebugName[32] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v26[3].mDebugName[28] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v26[4].mNode.mParent) = 315097330;
  LODWORD(v26[3].mMaterialUser.mOffset) = v2;
  v27 = this->mMaterial;
  LOWORD(v27[4].mNode.mChild[1]) = 0;
  HIDWORD(v27[4].mNode.mChild[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v27[4].mNode.mChild[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v27[4].mDebugName[4] = 1002903008;
  v27[4].mTypeUID = v4;
  v28 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v28, this->mMaterial);
  v29 = UFG::sTexNamesModifiers;
  v30 = UFG::sTexNamesModifiers;
  mMaskCopyShaderUID = this->mMaskCopyShaderUID;
  do
  {
    UFG::qSPrintf(dest, "TEXTURECOMPMASKCOPY%s", *v30);
    *mMaskCopyShaderUID++ = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
    ++v30;
  }
  while ( (__int64)v30 < (__int64)&UFG::PartDebug::sDisplayOpacity );
  mMaskDecalSphericalShaderUID = this->mMaskDecalSphericalShaderUID;
  do
  {
    UFG::qSPrintf(dest, "TEXTURECOMPMASKDECAL%s", *v29);
    *(mMaskDecalSphericalShaderUID - 3) = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
    UFG::qSPrintf(dest, "TEXTURECOMPMASKDECALSPHERICAL%s", *v29);
    *mMaskDecalSphericalShaderUID = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
    UFG::qSPrintf(dest, "TEXTURECOMPMASKDECALSPHERICALPLANAR%s", *v29);
    mMaskDecalSphericalShaderUID[3] = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
    UFG::qSPrintf(dest, "TEXTURECOMPMASKDECALCYLINDRICAL%s", *v29);
    mMaskDecalSphericalShaderUID[6] = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
    ++mMaskDecalSphericalShaderUID;
    ++v29;
  }
  while ( (__int64)v29 < (__int64)&UFG::PartDebug::sDisplayOpacity );
  v33 = UFG::qStringHash32("TEXTURECOMPMASKSOBEL", 0xFFFFFFFF);
  this->mSobelFilterMaterial = Illusion::Factory::NewMaterial("TEXTURECOMPMASKSOBEL", v33, 4u, 0i64, 0i64, 0i64);
  v34 = UFG::qStringHash32("TEXTURECOMPNORMALMAPGEN", 0xFFFFFFFF);
  mSobelFilterMaterial = this->mSobelFilterMaterial;
  LOWORD(mSobelFilterMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mSobelFilterMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mSobelFilterMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mSobelFilterMaterial[1].mTypeUID = -1957338719;
  LODWORD(mSobelFilterMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v34;
  v36 = UFG::qStringHashUpper32(this->mTempTarget512->mTargetTexture[0]->mDebugName, 0xFFFFFFFF);
  v37 = this->mSobelFilterMaterial;
  *(_WORD *)&v37[1].mDebugName[12] = 0;
  *(_DWORD *)&v37[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v37[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v37[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v37[1].mStateBlockMask.mFlags[0]) = v36;
  v38 = this->mSobelFilterMaterial;
  LOWORD(v38[1].mMaterialUser.mOffset) = 0;
  *(&v38[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v38[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v38[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v38[2].mNode.mUID = -1551679522;
  v39 = this->mSobelFilterMaterial;
  LOWORD(v39[2].mTypeUID) = 0;
  HIDWORD(v39[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v39[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v39[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v39[2].mDebugName[28] = 1660426324;
  v40 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v40, this->mSobelFilterMaterial);
  v41 = UFG::qStringHash32("TEXTURECOMPDILATEMAT", 0xFFFFFFFF);
  this->mDilateFilterMaterial = Illusion::Factory::NewMaterial("TEXTURECOMPDILATEMAT", v41, 5u, 0i64, 0i64, 0i64);
  v42 = UFG::qStringHash32("TEXTURECOMPDILATE", 0xFFFFFFFF);
  mDilateFilterMaterial = this->mDilateFilterMaterial;
  LOWORD(mDilateFilterMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mDilateFilterMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mDilateFilterMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mDilateFilterMaterial[1].mTypeUID = -1957338719;
  LODWORD(mDilateFilterMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v42;
  v44 = UFG::qStringHashUpper32(this->mTempTarget512->mTargetTexture[0]->mDebugName, 0xFFFFFFFF);
  v45 = this->mDilateFilterMaterial;
  *(_WORD *)&v45[1].mDebugName[12] = 0;
  *(_DWORD *)&v45[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v45[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v45[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v45[1].mStateBlockMask.mFlags[0]) = v44;
  v46 = UFG::qStringHashUpper32("MASK_DILATE", 0xFFFFFFFF);
  v47 = this->mDilateFilterMaterial;
  LOWORD(v47[1].mMaterialUser.mOffset) = 0;
  *(&v47[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v47[1].mNumParams = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v47[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v47[2].mNode.mUID = v46;
  v48 = this->mDilateFilterMaterial;
  LOWORD(v48[2].mTypeUID) = 0;
  HIDWORD(v48[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v48[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v48[2].UFG::qResourceData + 22) = 315097330;
  *(_DWORD *)&v48[2].mDebugName[28] = 2015536557;
  v49 = this->mDilateFilterMaterial;
  LOWORD(v49[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v49[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v49[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v49[3].mNode.mChild[1]) = 1002903008;
  LODWORD(v49[3].mNode.mChild[0]) = 1660426324;
  v50 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v50, this->mDilateFilterMaterial);
  v51 = UFG::qStringHash32("TEXTURECOMPSTAMP", 0xFFFFFFFF);
  this->mStampMaterial = Illusion::Factory::NewMaterial("TEXTURECOMPSTAMP", v51, 3u, 0i64, 0i64, 0i64);
  v52 = UFG::qStringHash32("TEXTURECOMPSTAMP", 0xFFFFFFFF);
  mStampMaterial = this->mStampMaterial;
  LOWORD(mStampMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mStampMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mStampMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mStampMaterial[1].mTypeUID = -1957338719;
  LODWORD(mStampMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v52;
  v54 = this->mStampMaterial;
  *(_WORD *)&v54[1].mDebugName[12] = 0;
  *(_DWORD *)&v54[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v54[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v54[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v54[1].mStateBlockMask.mFlags[0]) = v3;
  v55 = this->mStampMaterial;
  LOWORD(v55[1].mMaterialUser.mOffset) = 0;
  *(&v55[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v55[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v55[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v55[2].mNode.mUID = v5;
  v56 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v56, this->mStampMaterial);
  v57 = UFG::qStringHash32("SIMPLETEXTURECOMPCOLOUR", 0xFFFFFFFF);
  this->mColourMaterial = Illusion::Factory::NewMaterial("SIMPLETEXTURECOMPCOLOUR", v57, 5u, 0i64, 0i64, 0i64);
  v58 = UFG::qStringHash32("TEXTURECOMPSIMPLECOLOUR", 0xFFFFFFFF);
  mColourMaterial = this->mColourMaterial;
  LOWORD(mColourMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mColourMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mColourMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mColourMaterial[1].mTypeUID = -1957338719;
  LODWORD(mColourMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v58;
  v60 = this->mColourMaterial;
  *(_WORD *)&v60[1].mDebugName[12] = 0;
  *(_DWORD *)&v60[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v60[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v60[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v60[1].mStateBlockMask.mFlags[0]) = 662883558;
  v61 = this->mColourMaterial;
  LOWORD(v61[1].mMaterialUser.mOffset) = 0;
  *(&v61[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v61[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v61[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v61[2].mNode.mUID = 1660426324;
  v62 = this->mColourMaterial;
  LOWORD(v62[2].mTypeUID) = 0;
  HIDWORD(v62[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v62[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v62[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v62[2].mDebugName[28] = 0;
  v63 = this->mColourMaterial;
  LOWORD(v63[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v63[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v63[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texBlendMask", 0xFFFFFFFF);
  LODWORD(v63[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v63[3].mNode.mChild[0]) = 0;
  v64 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v64, this->mColourMaterial);
  UFG::qString::~qString(&v65.name);
}

// File Line: 449
// RVA: 0x154F30
void __fastcall UFG::PartCompositeBuilder::~PartCompositeBuilder(UFG::PartCompositeBuilder *this)
{
  Illusion::Target *mTempTarget512; // rcx
  Illusion::Material *mMaterial; // rbx
  UFG::qResourceWarehouse *v4; // rax
  Illusion::Material *mSobelFilterMaterial; // rbx
  UFG::qResourceWarehouse *v6; // rax
  Illusion::Material *mDilateFilterMaterial; // rbx
  UFG::qResourceWarehouse *v8; // rax
  Illusion::Material *mStampMaterial; // rbx
  UFG::qResourceWarehouse *v10; // rax
  Illusion::Material *mColourMaterial; // rbx
  UFG::qResourceWarehouse *v12; // rax
  unsigned int i; // ebx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *mPrev; // rcx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *mNext; // rax
  Illusion::Target **p; // rcx

  mTempTarget512 = this->mTempTarget512;
  if ( mTempTarget512 )
  {
    Illusion::DeleteTarget((AMD_HD3D *)mTempTarget512, 1);
    this->mTempTarget512 = 0i64;
  }
  mMaterial = this->mMaterial;
  if ( mMaterial )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v4, mMaterial);
    UFG::LibCurlFree(this->mMaterial);
    this->mMaterial = 0i64;
  }
  mSobelFilterMaterial = this->mSobelFilterMaterial;
  if ( mSobelFilterMaterial )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v6, mSobelFilterMaterial);
    UFG::LibCurlFree(this->mSobelFilterMaterial);
    this->mSobelFilterMaterial = 0i64;
  }
  mDilateFilterMaterial = this->mDilateFilterMaterial;
  if ( mDilateFilterMaterial )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v8, mDilateFilterMaterial);
    UFG::LibCurlFree(this->mDilateFilterMaterial);
    this->mDilateFilterMaterial = 0i64;
  }
  mStampMaterial = this->mStampMaterial;
  if ( mStampMaterial )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v10, mStampMaterial);
    UFG::LibCurlFree(this->mStampMaterial);
    this->mStampMaterial = 0i64;
  }
  mColourMaterial = this->mColourMaterial;
  if ( mColourMaterial )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v12, mColourMaterial);
    UFG::LibCurlFree(this->mColourMaterial);
    this->mColourMaterial = 0i64;
  }
  for ( i = 0; i < this->mFreeTargets.size; ++i )
    Illusion::DeleteTarget((AMD_HD3D *)this->mFreeTargets.p[i], 1);
  this->mFreeTargets.size = 0;
  UFG::qList<UFG::CompositeBuild,UFG::CompositeBuild,1,0>::DeleteNodes(&this->mPendingBuilds);
  mPrev = this->mPendingBuilds.mNode.mPrev;
  mNext = this->mPendingBuilds.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPendingBuilds.mNode.mPrev = &this->mPendingBuilds.mNode;
  this->mPendingBuilds.mNode.mNext = &this->mPendingBuilds.mNode;
  p = this->mFreeTargets.p;
  if ( p )
    operator delete[](p);
  this->mFreeTargets.p = 0i64;
  *(_QWORD *)&this->mFreeTargets.size = 0i64;
}

// File Line: 526
// RVA: 0x15B010
void __fastcall UFG::PartCompositeBuilder::SubmitCompositeBuild(
        UFG::PartCompositeBuilder *this,
        UFG::PartCompositeBuilder::CompositeBuildParams *buildParams)
{
  char *v4; // rax
  char *v5; // r8
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *mPrev; // rax

  v4 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v5 = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    *((_QWORD *)v4 + 2) = 0i64;
    *((_QWORD *)v4 + 5) = v4 + 40;
    *((_QWORD *)v4 + 6) = v4 + 40;
    *((_QWORD *)v4 + 7) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  *((_QWORD *)v5 + 2) = buildParams->mDefinition;
  *((_QWORD *)v5 + 3) = buildParams->mDefinition->mTextureData;
  *((_QWORD *)v5 + 8) = buildParams->mCallback;
  *((_QWORD *)v5 + 9) = buildParams->mCallbackParam;
  v5[32] = buildParams->mResetTextures;
  mPrev = this->mPendingBuilds.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)v5;
  *(_QWORD *)v5 = mPrev;
  *((_QWORD *)v5 + 1) = &this->mPendingBuilds;
  this->mPendingBuilds.mNode.mPrev = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)v5;
}

// File Line: 539
// RVA: 0x156330
Illusion::Target *__fastcall UFG::PartCompositeBuilder::AllocTarget(UFG::PartCompositeBuilder *this)
{
  unsigned int size; // r9d
  __int64 v2; // r8
  Illusion::Target *result; // rax
  Illusion::Target *v4; // rbx
  Illusion::CreateTargetParams v5; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v6; // [rsp+D0h] [rbp-30h]
  char dest[256]; // [rsp+E0h] [rbp-20h] BYREF

  v6 = -2i64;
  size = this->mFreeTargets.size;
  if ( this->mFreeTargets.size )
  {
    v2 = size - 1;
    result = this->mFreeTargets.p[v2];
    if ( size <= 1 )
      LODWORD(v2) = 0;
    this->mFreeTargets.size = v2;
  }
  else
  {
    UFG::qSPrintf(dest, 256, "PartCompositeBuilder_%d", (unsigned int)UFG::PartCompositeBuilder::sRenderTargetIndex);
    UFG::qString::qString(&v5.name, dest);
    *(_QWORD *)&v5.num_mrt = 1i64;
    v5.depth = 1;
    v5.array_size = 1;
    *(_DWORD *)v5.mrt_formats = -256;
    v5.target_flags = 0;
    v5.num_mips = 1;
    memset(v5.textures, 0, 85);
    *(_QWORD *)&v5.width = 0x20000000200i64;
    v4 = Illusion::CreateTarget(&v5);
    ++UFG::PartCompositeBuilder::sRenderTargetIndex;
    UFG::qString::~qString(&v5.name);
    return v4;
  }
  return result;
}

// File Line: 566
// RVA: 0x156F50
void __fastcall UFG::PartCompositeBuilder::BuildCommandList(
        UFG::PartCompositeBuilder *this,
        UFG::CompositeBuild *build)
{
  UFG::CompositeBuild *v2; // rdi
  UFG::PartTemplateInstance *mDefinition; // rax
  unsigned int mNumItems; // r8d
  __int64 v6; // r14
  __int64 v7; // r12
  __int64 v8; // r11
  UFG::PartTemplateInstance::SlotEntry *mItems; // r13
  char v10; // dl
  __int64 v11; // r8
  unsigned int v12; // r9d
  UFG::PartTextureData::Textures *p; // r15
  unsigned int v14; // ebx
  UFG::qList<UFG::BuildOp,UFG::BuildOp,1,0> *p_mCommandList; // rsi
  Illusion::Target *mNormTarget; // rdi
  char *v17; // rax
  char *v18; // rdx
  __int64 *v19; // rcx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> *mPrev; // rax
  char *v21; // rax
  char *v22; // rdx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> *v23; // rax
  unsigned int v24; // eax
  unsigned int v25; // ecx
  char *v26; // rax
  char *v27; // rdx
  UFG::qNode<UFG::BuildOp,UFG::BuildOp> *v28; // rax
  int v29[2]; // [rsp+28h] [rbp-60h] BYREF
  __int64 v30; // [rsp+30h] [rbp-58h]
  __int64 v31[10]; // [rsp+38h] [rbp-50h] BYREF
  __int64 v33; // [rsp+A0h] [rbp+18h]

  v2 = build;
  mDefinition = build->mDefinition;
  mNumItems = mDefinition->mSlots.mData.mNumItems;
  if ( mNumItems )
  {
    v6 = 0i64;
    v7 = 0i64;
    v8 = mNumItems;
    v33 = mDefinition->mSlots.mData.mNumItems;
    do
    {
      mItems = v2->mDefinition->mSlots.mData.mItems;
      if ( mItems[v7].mBasePart.mPart.mData )
      {
        v10 = 0;
        v11 = 0i64;
        v12 = mItems[v7].mLayers.mData.mNumItems;
        if ( v12 )
        {
          do
          {
            if ( mItems[v7].mLayers.mData.mItems[v11].mPart.mData )
              v10 = 1;
            v11 = (unsigned int)(v11 + 1);
          }
          while ( (unsigned int)v11 < v12 );
          if ( v10 )
          {
            p = this->mProcessingBuild->mData->mParts.p;
            v14 = 0;
            p_mCommandList = &v2->mCommandList;
            do
            {
              if ( v14 )
              {
                if ( v14 == 1 )
                  mNormTarget = p[v6].mNormTarget;
                else
                  mNormTarget = p[v6].mSpecTarget;
              }
              else
              {
                mNormTarget = p[v6].mDiffuseTarget;
              }
              v17 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
              v18 = v17;
              if ( v17 )
              {
                *((_QWORD *)v17 + 1) = v17 + 8;
                *((_QWORD *)v17 + 2) = v17 + 8;
                *(_QWORD *)v17 = &UFG::BuildOp::`vftable;
                *(_QWORD *)v17 = &UFG::ClearView::`vftable;
              }
              else
              {
                v18 = 0i64;
              }
              *((_QWORD *)v18 + 3) = this->mTempTarget512;
              if ( v14 == 1 )
              {
                v29[0] = 1056964608;
                v29[1] = 1056964608;
                v30 = 1056964608i64;
                v19 = (__int64 *)v29;
              }
              else
              {
                v31[0] = 0i64;
                v31[1] = 0i64;
                v19 = v31;
              }
              *((_DWORD *)v18 + 8) = *(_DWORD *)v19;
              *((_DWORD *)v18 + 9) = *((_DWORD *)v19 + 1);
              *((_DWORD *)v18 + 10) = *((_DWORD *)v19 + 2);
              *((_DWORD *)v18 + 11) = *((_DWORD *)v19 + 3);
              mPrev = p_mCommandList->mNode.mPrev;
              mPrev->mNext = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v18 + 8);
              *((_QWORD *)v18 + 1) = mPrev;
              *((_QWORD *)v18 + 2) = p_mCommandList;
              p_mCommandList->mNode.mPrev = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v18 + 8);
              v21 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
              v22 = v21;
              if ( v21 )
              {
                *((_QWORD *)v21 + 1) = v21 + 8;
                *((_QWORD *)v21 + 2) = v21 + 8;
                *(_QWORD *)v21 = &UFG::BuildOp::`vftable;
                *(_QWORD *)v21 = &UFG::RenderPartToTexture::`vftable;
              }
              else
              {
                v22 = 0i64;
              }
              *((_QWORD *)v22 + 3) = this->mTempTarget512;
              *((_QWORD *)v22 + 7) = &mItems[v7].mBasePart;
              *((_DWORD *)v22 + 8) = v14;
              *((_QWORD *)v22 + 5) = this->mMaterial;
              *((_QWORD *)v22 + 6) = this->mMaskCopyShaderUID;
              v23 = p_mCommandList->mNode.mPrev;
              v23->mNext = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v22 + 8);
              *((_QWORD *)v22 + 1) = v23;
              *((_QWORD *)v22 + 2) = p_mCommandList;
              p_mCommandList->mNode.mPrev = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v22 + 8);
              v24 = 0;
              v25 = mItems[v7].mLayers.mData.mNumItems;
              if ( v25 )
              {
                do
                  ++v24;
                while ( v24 < v25 );
              }
              v26 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
              v27 = v26;
              if ( v26 )
              {
                *((_QWORD *)v26 + 1) = v26 + 8;
                *((_QWORD *)v26 + 2) = v26 + 8;
                *(_QWORD *)v26 = &UFG::BuildOp::`vftable;
                *(_QWORD *)v26 = &UFG::DilateTexture::`vftable;
              }
              else
              {
                v27 = 0i64;
              }
              *((_QWORD *)v27 + 4) = this->mTempTarget512;
              *((_QWORD *)v27 + 3) = mNormTarget;
              *((_QWORD *)v27 + 5) = this->mDilateFilterMaterial;
              v28 = p_mCommandList->mNode.mPrev;
              v28->mNext = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v27 + 8);
              *((_QWORD *)v27 + 1) = v28;
              *((_QWORD *)v27 + 2) = p_mCommandList;
              p_mCommandList->mNode.mPrev = (UFG::qNode<UFG::BuildOp,UFG::BuildOp> *)(v27 + 8);
              ++v14;
            }
            while ( v14 < 3 );
            v8 = v33;
            v2 = build;
          }
        }
      }
      ++v7;
      ++v6;
      v33 = --v8;
    }
    while ( v8 );
  }
}

// File Line: 678
// RVA: 0x15B160
void __fastcall UFG::PartCompositeBuilder::Update(UFG::PartCompositeBuilder *this, float deltaTime)
{
  UFG::CompositeBuild *mProcessingBuild; // rdx
  UFG::CompositeBuild *v4; // rcx
  void (__fastcall *mCallbackFunc)(UFG::PartTemplateInstance *, void *); // rax
  UFG::CompositeBuild *v6; // rcx

  mProcessingBuild = this->mProcessingBuild;
  if ( mProcessingBuild && (bool *)mProcessingBuild->mCurrentOperation == &mProcessingBuild->mResetTextures )
  {
    if ( UFG::PartCompositeBuilder::sLoopBuild )
    {
      mProcessingBuild->mCurrentOperation = (UFG::BuildOp *)&mProcessingBuild->mCommandList.mNode.mNext[-1].mNext;
    }
    else
    {
      mProcessingBuild->mDefinition->mCompositeDirty = 0;
      v4 = this->mProcessingBuild;
      mCallbackFunc = v4->mCallbackFunc;
      if ( mCallbackFunc )
        mCallbackFunc(v4->mDefinition, v4->mCallbackParam);
      v6 = this->mProcessingBuild;
      if ( v6 )
        UFG::CompositeBuild::`scalar deleting destructor(v6, 1);
      this->mProcessingBuild = 0i64;
    }
  }
}

// File Line: 700
// RVA: 0x15A2D0
char __fastcall UFG::PartCompositeBuilder::RenderComposites(
        UFG::PartCompositeBuilder *this,
        Illusion::SubmitContext *submitContext)
{
  char v4; // si
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *mNext; // r14
  UFG::PartTemplateInstance *mPrev; // rdi
  UFG::PartTextureData *mTextureData; // rbp
  char *v9; // rax
  UFG::PartTextureData *v10; // rax
  UFG::CompositeBuild *v11; // rdx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v12; // rcx
  UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *v13; // rax
  UFG::CompositeBuild *mProcessingBuild; // rcx
  bool v15; // al

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
      mNext = this->mPendingBuilds.mNode.mNext;
      mPrev = (UFG::PartTemplateInstance *)mNext[1].mPrev;
      if ( (unsigned __int8)UFG::PartTemplateInstance::AllPartsLoaded(mPrev) )
      {
        if ( LOBYTE(mNext[2].mPrev) )
        {
          mTextureData = mPrev->mTextureData;
          if ( mTextureData )
          {
            UFG::PartTextureData::~PartTextureData(mPrev->mTextureData);
            operator delete[](mTextureData);
            mPrev->mTextureData = 0i64;
          }
        }
        if ( !mPrev->mTextureData )
        {
          v9 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
          if ( v9 )
            UFG::PartTextureData::PartTextureData((UFG::PartTextureData *)v9, mPrev);
          else
            v10 = 0i64;
          mPrev->mTextureData = v10;
        }
        mNext[1].mNext = (UFG::qNode<UFG::CompositeBuild,UFG::CompositeBuild> *)mPrev->mTextureData;
        v11 = (UFG::CompositeBuild *)this->mPendingBuilds.mNode.mNext;
        v12 = v11->mPrev;
        v13 = v11->mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = v11;
        v11->mNext = v11;
        this->mProcessingBuild = v11;
        if ( v11->mDefinition->mCompositeDirty )
          UFG::PartCompositeBuilder::BuildCommandList(this, v11);
        this->mProcessingBuild->mCurrentOperation = (UFG::BuildOp *)&this->mProcessingBuild->mCommandList.mNode.mNext[-1].mNext;
      }
    }
    mProcessingBuild = this->mProcessingBuild;
    if ( mProcessingBuild && (bool *)mProcessingBuild->mCurrentOperation != &mProcessingBuild->mResetTextures )
    {
      while ( 1 )
      {
        v15 = this->mProcessingBuild->mCurrentOperation->vfptr->Execute(
                this->mProcessingBuild->mCurrentOperation,
                submitContext);
        this->mProcessingBuild->mCurrentOperation = (UFG::BuildOp *)&this->mProcessingBuild->mCurrentOperation->mNext[-1].mNext;
        if ( v15 || UFG::PartCompositeBuilder::sSingleStepBuild )
          break;
        if ( this->mProcessingBuild->mCurrentOperation == (UFG::BuildOp *)&this->mProcessingBuild->mResetTextures )
          return v4;
      }
      return !UFG::PartCompositeBuilder::sSingleStepBuild;
    }
  }
  return v4;
}

// File Line: 768
// RVA: 0x15A490
void __fastcall UFG::PartCompositeBuilder::RenderDebugOverlay(UFG::PartCompositeBuilder *this, Render::View *view)
{
  UFG::CompositeBuild *mProcessingBuild; // rax
  UFG::PartTextureData *mData; // rdi
  float v6; // xmm0_4
  int v7; // eax
  UFG::PartTextureData::Textures *p; // rdi
  Render::Poly poly; // [rsp+90h] [rbp+18h] BYREF
  Render::Poly v10; // [rsp+98h] [rbp+20h] BYREF

  if ( UFG::PartCompositeBuilder::sRenderDebugOverlay && UFG::PartCompositeBuilder::sRenderPartTargets )
  {
    mProcessingBuild = this->mProcessingBuild;
    if ( mProcessingBuild )
    {
      mData = mProcessingBuild->mData;
      v6 = (float)UFG::PartCompositeBuilder::sRenderPartIndex;
      v7 = mData->mParts.size - 1;
      if ( (float)UFG::PartCompositeBuilder::sRenderPartIndex >= (float)v7 )
        v6 = (float)v7;
      p = mData->mParts.p;
      Render::Poly::Poly(&poly, 0.0, 0.0, 0.2, 0.35555556, 0.0);
      Render::View::Draw(view, &poly, this->mTempTarget512->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      if ( p[v6].mDiffuseTarget )
      {
        Render::Poly::Poly(&v10, 0.21000001, 0.0, 0.2, 0.35555556, 0.0);
        Render::View::Draw(view, &v10, p[v6].mDiffuseTarget->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      }
      if ( p[v6].mNormTarget )
      {
        Render::Poly::Poly(&v10, 0.0, 0.36555555, 0.2, 0.35555556, 0.0);
        Render::View::Draw(view, &v10, p[v6].mNormTarget->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      }
      if ( p[v6].mSpecTarget )
      {
        Render::Poly::Poly(&v10, 0.21000001, 0.36555555, 0.2, 0.35555556, 0.0);
        Render::View::Draw(view, &v10, p[v6].mSpecTarget->mTargetTexture[0]->mNode.mUID, 0i64, 0, 0);
      }
    }
  }
}

