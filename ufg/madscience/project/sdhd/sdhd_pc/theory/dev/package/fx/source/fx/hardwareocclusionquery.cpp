// File Line: 21
// RVA: 0x146AF70
__int64 dynamic_initializer_for__FX::HardwareOcclusionQuery::mUnculledMat__()
{
  UFG::qResourceHandle::qResourceHandle(&FX::HardwareOcclusionQuery::mUnculledMat);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__FX::HardwareOcclusionQuery::mUnculledMat__);
}

// File Line: 22
// RVA: 0x146AF40
__int64 dynamic_initializer_for__FX::HardwareOcclusionQuery::mProbeMat__()
{
  UFG::qResourceHandle::qResourceHandle(&FX::HardwareOcclusionQuery::mProbeMat);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__FX::HardwareOcclusionQuery::mProbeMat__);
}

// File Line: 23
// RVA: 0x146AF10
__int64 dynamic_initializer_for__FX::HardwareOcclusionQuery::mFlareProbe__()
{
  UFG::qResourceHandle::qResourceHandle(&FX::HardwareOcclusionQuery::mFlareProbe);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__FX::HardwareOcclusionQuery::mFlareProbe__);
}

// File Line: 33
// RVA: 0x1D2550
void __fastcall FX::HardwareOcclusionQuery::Release(FX::HardwareOcclusionQuery *this)
{
  Illusion::IOcclusion *OcclusionSystem; // rax
  __int64 mQueryID; // rdx
  Illusion::IOcclusion *v4; // rdi
  __int64 mUnculledQueryID; // rdx

  OcclusionSystem = Render::GetOcclusionSystem();
  mQueryID = this->mQueryID;
  v4 = OcclusionSystem;
  if ( (_DWORD)mQueryID != -1 )
  {
    OcclusionSystem->vfptr->ReleaseQueryHandle(OcclusionSystem, mQueryID, this->mTarget);
    this->mQueryID = -1;
  }
  mUnculledQueryID = this->mUnculledQueryID;
  if ( (_DWORD)mUnculledQueryID != -1 )
  {
    v4->vfptr->ReleaseQueryHandle(v4, mUnculledQueryID, this->mTarget);
    this->mUnculledQueryID = -1;
  }
}

// File Line: 38
// RVA: 0x1D0960
void FX::HardwareOcclusionQuery::InitSystem(void)
{
  unsigned int v0; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v2; // rax

  if ( !FX::HardwareOcclusionQuery::mUnculledMat.mData )
  {
    FX::HardwareOcclusionQuery::InitMaterial();
    v0 = UFG::qStringHashUpper32("DR_Sphere", -1);
    Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v2 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v2, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&FX::HardwareOcclusionQuery::mFlareProbe, 0xA2ADCD77, v0, Inventory);
  }
}

// File Line: 50
// RVA: 0x1D7A40
char __fastcall FX::HardwareOcclusionQuery::StartOcclusionUnculled(
        FX::HardwareOcclusionQuery *this,
        Render::View *view)
{
  Illusion::SubmitContext *mSubmitContext; // r14
  Illusion::Target **v5; // rbx
  Illusion::IOcclusion *OcclusionSystem; // rax
  char *v7; // rdi
  unsigned int mUnculledQueryID; // ebx

  mSubmitContext = view->mSubmitContext;
  if ( this->mUnculledQueryID == -1 )
  {
    v5 = (Illusion::Target **)Render::View::GetStateValues(view)->mParamValues[11];
    OcclusionSystem = Render::GetOcclusionSystem();
    this->mUnculledQueryID = OcclusionSystem->vfptr->GetQueryHandle(OcclusionSystem, *v5);
    this->mTarget = *v5;
  }
  if ( this->mUnculledQueryID == -1 )
    return 0;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v7 )
  {
    mUnculledQueryID = this->mUnculledQueryID;
    *(_QWORD *)v7 = Render::View::GetStateValues(view)->mParamValues[11];
    *((_DWORD *)v7 + 2) = mUnculledQueryID;
  }
  else
  {
    v7 = 0i64;
  }
  ((void (__fastcall *)(Illusion::SubmitContext *, __int64, _QWORD, char *, __int64))mSubmitContext->vfptr->AddRenderCommand)(
    mSubmitContext,
    18i64,
    0i64,
    v7,
    -2i64);
  return 1;
}

// File Line: 73
// RVA: 0x1CBD50
void __fastcall FX::HardwareOcclusionQuery::EndOcclusionUnculled(FX::HardwareOcclusionQuery *this, Render::View *view)
{
  Illusion::SubmitContext *mSubmitContext; // rsi
  char *v5; // rdi
  unsigned int mUnculledQueryID; // ebx

  mSubmitContext = view->mSubmitContext;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v5 )
  {
    mUnculledQueryID = this->mUnculledQueryID;
    *(_QWORD *)v5 = Render::View::GetStateValues(view)->mParamValues[11];
    *((_DWORD *)v5 + 2) = mUnculledQueryID;
  }
  else
  {
    v5 = 0i64;
  }
  mSubmitContext->vfptr->AddRenderCommand(mSubmitContext, 19, 0, v5);
}

// File Line: 81
// RVA: 0x1D7980
char __fastcall FX::HardwareOcclusionQuery::StartOcclusion(FX::HardwareOcclusionQuery *this, Render::View *view)
{
  Illusion::SubmitContext *mSubmitContext; // r14
  Illusion::IOcclusion *OcclusionSystem; // rbx
  Illusion::Target **v6; // rdi
  unsigned int v7; // eax
  char *v9; // rdi
  unsigned int mQueryID; // ebx

  mSubmitContext = view->mSubmitContext;
  if ( this->mQueryID == -1 )
  {
    OcclusionSystem = Render::GetOcclusionSystem();
    v6 = (Illusion::Target **)Render::View::GetStateValues(view)->mParamValues[11];
    v7 = OcclusionSystem->vfptr->GetQueryHandle(OcclusionSystem, *v6);
    this->mQueryID = v7;
    this->mTarget = *v6;
    if ( v7 == -1 )
      return 0;
  }
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v9 )
  {
    mQueryID = this->mQueryID;
    *(_QWORD *)v9 = Render::View::GetStateValues(view)->mParamValues[11];
    *((_DWORD *)v9 + 2) = mQueryID;
  }
  else
  {
    v9 = 0i64;
  }
  ((void (__fastcall *)(Illusion::SubmitContext *, __int64, _QWORD, char *, __int64))mSubmitContext->vfptr->AddRenderCommand)(
    mSubmitContext,
    18i64,
    0i64,
    v9,
    -2i64);
  return 1;
}

// File Line: 104
// RVA: 0x1CBCC0
void __fastcall FX::HardwareOcclusionQuery::EndOcclusion(FX::HardwareOcclusionQuery *this, Render::View *view)
{
  Illusion::SubmitContext *mSubmitContext; // rsi
  char *v5; // rdi
  unsigned int mQueryID; // ebx

  mSubmitContext = view->mSubmitContext;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v5 )
  {
    mQueryID = this->mQueryID;
    *(_QWORD *)v5 = Render::View::GetStateValues(view)->mParamValues[11];
    *((_DWORD *)v5 + 2) = mQueryID;
  }
  else
  {
    v5 = 0i64;
  }
  mSubmitContext->vfptr->AddRenderCommand(mSubmitContext, 19, 0, v5);
}

// File Line: 112
// RVA: 0x1CEB80
void __fastcall FX::HardwareOcclusionQuery::Init(FX::HardwareOcclusionQuery *this)
{
  *(_QWORD *)&this->mQueryID = -1i64;
  this->mTarget = 0i64;
}

// File Line: 135
// RVA: 0x1CD310
float __fastcall FX::HardwareOcclusionQuery::GetVisibility(FX::HardwareOcclusionQuery *this)
{
  Illusion::IOcclusion *OcclusionSystem; // rax
  __int64 mQueryID; // rdx
  __int64 mUnculledQueryID; // r8
  float result; // xmm0_4

  OcclusionSystem = Render::GetOcclusionSystem();
  mQueryID = this->mQueryID;
  if ( (_DWORD)mQueryID == -1 )
    return 0.0;
  mUnculledQueryID = this->mUnculledQueryID;
  if ( (_DWORD)mUnculledQueryID == -1 )
    return 0.0;
  OcclusionSystem->vfptr->GetPercentVisible(OcclusionSystem, mQueryID, mUnculledQueryID, this->mTarget);
  return result;
}

// File Line: 218
// RVA: 0x1CBB00
void __fastcall FX::HardwareOcclusionQuery::DrawSphere(
        FX::HardwareOcclusionQuery *this,
        Render::View *view,
        UFG::qMatrix44 *probeTransform)
{
  Illusion::Material *force_mat; // rbp
  UFG::qResourceData *mData; // rsi
  unsigned int v6; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax

  force_mat = (Illusion::Material *)FX::HardwareOcclusionQuery::mProbeMat.mData;
  mData = FX::HardwareOcclusionQuery::mUnculledMat.mData;
  v6 = *(_DWORD *)&FX::HardwareOcclusionQuery::mProbeMat.mData[1].mDebugName[28];
  if ( *(_DWORD *)&FX::HardwareOcclusionQuery::mUnculledMat.mData[1].mDebugName[28] != v6 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mUnculledMat.mData[1].mDebugName[4],
      (unsigned int)FX::HardwareOcclusionQuery::mUnculledMat.mData[2].mNode.mParent,
      v6);
    mPrev = mData[1].mResourceHandles.mNode.mPrev;
    if ( mPrev )
      mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)mPrev + (_QWORD)mData + 120);
    LOWORD(mPrev->mPrev) |= 0x20u;
  }
  if ( FX::HardwareOcclusionQuery::StartOcclusionUnculled(this, view) )
  {
    Render::View::Draw(
      view,
      &FX::HardwareOcclusionQuery::mFlareProbe,
      probeTransform,
      0,
      (Illusion::Material *)FX::HardwareOcclusionQuery::mUnculledMat.mData);
    FX::HardwareOcclusionQuery::EndOcclusionUnculled(this, view);
  }
  if ( FX::HardwareOcclusionQuery::StartOcclusion(this, view) )
  {
    Render::View::Draw(view, &FX::HardwareOcclusionQuery::mFlareProbe, probeTransform, 0, force_mat);
    FX::HardwareOcclusionQuery::EndOcclusion(this, view);
  }
}

// File Line: 224
// RVA: 0x1CFFE0
void FX::HardwareOcclusionQuery::InitMaterial(void)
{
  UFG::qResourceData *v0; // rbx
  UFG::qResourceWarehouse *v1; // rax
  unsigned int mStringHashUpper32; // eax
  Illusion::Material *v3; // rdi
  int v4; // ebx
  UFG::qResourceWarehouse *v5; // rax
  unsigned int v6; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *v9; // rbx
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // esi
  Illusion::Material *v12; // rdi
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qString v16; // [rsp+38h] [rbp-30h] BYREF

  v0 = Illusion::Factory::NewRasterState("FX.UnculledMaterial.Rasterstate", 0x8DBA91E2, 0i64, 0i64, 0i64);
  LOWORD(v0[1].mNode.mParent) = 0;
  BYTE3(v0[1].mNode.mParent) = 1;
  v1 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v1, v0);
  UFG::qString::qString(&v16, "FXHardwardOcclusionMatUnculled");
  mStringHashUpper32 = v16.mStringHashUpper32;
  if ( v16.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(v16.mData, -1);
    v16.mStringHashUpper32 = mStringHashUpper32;
  }
  v3 = Illusion::Factory::NewMaterial(v16.mData, mStringHashUpper32, 3u, 0i64, 0i64, 0i64);
  v4 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v3[1].mTypeUID = -1957338719;
  LODWORD(v3[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v4;
  *(_WORD *)&v3[1].mDebugName[12] = 0;
  *(_DWORD *)&v3[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v3[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v3[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v3[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v3[1].mMaterialUser.mOffset) = 0;
  *(&v3[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v3[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v3[2].mNode.mUID = -1917152798;
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v5, v3);
  v6 = v16.mStringHashUpper32;
  if ( v16.mStringHashUpper32 == -1 )
  {
    v6 = UFG::qStringHashUpper32(v16.mData, -1);
    v16.mStringHashUpper32 = v6;
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&FX::HardwareOcclusionQuery::mUnculledMat, 0xB4C26312, v6, Inventory);
  UFG::qString::~qString(&v16);
  v9 = Illusion::Factory::NewRasterState(FX::RasterStateFlareNoColor, 0x22E6858Bu, 0i64, 0i64, 0i64);
  LODWORD(v9[1].mNode.mParent) = 16973825;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, v9);
  v11 = UFG::qStringHashUpper32("FlareProbeMat", -1);
  v12 = Illusion::Factory::NewMaterial("FlareProbeMat", v11, 3u, 0i64, 0i64, 0i64);
  LODWORD(v9) = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v12[1].mNode.mChild[0]) = 0;
  HIDWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12[1].mTypeUID = -1957338719;
  LODWORD(v12[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v9;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v12[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v12[1].mMaterialUser.mOffset) = 0;
  *(&v12[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v12[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v12[2].mNode.mUID = 585532811;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v12);
  v14 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v14;
  }
  UFG::qResourceHandle::Init(&FX::HardwareOcclusionQuery::mProbeMat, 0xB4C26312, v11, v14);
}

