// File Line: 21
// RVA: 0x146AF70
__int64 dynamic_initializer_for__FX::HardwareOcclusionQuery::mUnculledMat__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mUnculledMat.mPrev);
  return atexit(dynamic_atexit_destructor_for__FX::HardwareOcclusionQuery::mUnculledMat__);
}

// File Line: 22
// RVA: 0x146AF40
__int64 dynamic_initializer_for__FX::HardwareOcclusionQuery::mProbeMat__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mProbeMat.mPrev);
  return atexit(dynamic_atexit_destructor_for__FX::HardwareOcclusionQuery::mProbeMat__);
}

// File Line: 23
// RVA: 0x146AF10
__int64 dynamic_initializer_for__FX::HardwareOcclusionQuery::mFlareProbe__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mFlareProbe.mPrev);
  return atexit(dynamic_atexit_destructor_for__FX::HardwareOcclusionQuery::mFlareProbe__);
}

// File Line: 33
// RVA: 0x1D2550
void __fastcall FX::HardwareOcclusionQuery::Release(FX::HardwareOcclusionQuery *this)
{
  FX::HardwareOcclusionQuery *v1; // rbx
  Illusion::IOcclusion *v2; // rax
  __int64 v3; // rdx
  Illusion::IOcclusion *v4; // rdi
  __int64 v5; // rdx

  v1 = this;
  v2 = Render::GetOcclusionSystem();
  v3 = v1->mQueryID;
  v4 = v2;
  if ( (_DWORD)v3 != -1 )
  {
    v2->vfptr->ReleaseQueryHandle(v2, v3, v1->mTarget);
    v1->mQueryID = -1;
  }
  v5 = v1->mUnculledQueryID;
  if ( (_DWORD)v5 != -1 )
  {
    v4->vfptr->ReleaseQueryHandle(v4, v5, v1->mTarget);
    v1->mUnculledQueryID = -1;
  }
}

// File Line: 38
// RVA: 0x1D0960
void FX::HardwareOcclusionQuery::InitSystem(void)
{
  unsigned int v0; // ebx
  UFG::qResourceInventory *v1; // rax
  UFG::qResourceWarehouse *v2; // rax

  if ( !FX::HardwareOcclusionQuery::mUnculledMat.mData )
  {
    FX::HardwareOcclusionQuery::InitMaterial();
    v0 = UFG::qStringHashUpper32("DR_Sphere", 0xFFFFFFFF);
    v1 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
    {
      v2 = UFG::qResourceWarehouse::Instance();
      v1 = UFG::qResourceWarehouse::GetInventory(v2, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v1;
    }
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mFlareProbe.mPrev,
      0xA2ADCD77,
      v0,
      v1);
  }
}

// File Line: 50
// RVA: 0x1D7A40
char __fastcall FX::HardwareOcclusionQuery::StartOcclusionUnculled(FX::HardwareOcclusionQuery *this, Render::View *view)
{
  Render::View *v2; // rbp
  FX::HardwareOcclusionQuery *v3; // rsi
  Illusion::SubmitContext *v4; // r14
  Illusion::Target **v5; // rbx
  Illusion::IOcclusion *v6; // rax
  char *v7; // rdi
  unsigned int v8; // ebx

  v2 = view;
  v3 = this;
  v4 = view->mSubmitContext;
  if ( this->mUnculledQueryID == -1 )
  {
    v5 = (Illusion::Target **)Render::View::GetStateValues(view)->mParamValues[11];
    v6 = Render::GetOcclusionSystem();
    v3->mUnculledQueryID = v6->vfptr->GetQueryHandle(v6, *v5);
    v3->mTarget = *v5;
  }
  if ( v3->mUnculledQueryID == -1 )
    return 0;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v7 )
  {
    v8 = v3->mUnculledQueryID;
    *(_QWORD *)v7 = Render::View::GetStateValues(v2)->mParamValues[11];
    *((_DWORD *)v7 + 2) = v8;
  }
  else
  {
    v7 = 0i64;
  }
  ((void (__fastcall *)(Illusion::SubmitContext *, signed __int64, _QWORD, char *, signed __int64))v4->vfptr->AddRenderCommand)(
    v4,
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
  Render::View *v2; // rbp
  FX::HardwareOcclusionQuery *v3; // rbx
  Illusion::SubmitContext *v4; // rsi
  char *v5; // rdi
  unsigned int v6; // ebx

  v2 = view;
  v3 = this;
  v4 = view->mSubmitContext;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v5 )
  {
    v6 = v3->mUnculledQueryID;
    *(_QWORD *)v5 = Render::View::GetStateValues(v2)->mParamValues[11];
    *((_DWORD *)v5 + 2) = v6;
  }
  else
  {
    v5 = 0i64;
  }
  v4->vfptr->AddRenderCommand(v4, 19, 0, v5);
}

// File Line: 81
// RVA: 0x1D7980
char __fastcall FX::HardwareOcclusionQuery::StartOcclusion(FX::HardwareOcclusionQuery *this, Render::View *view)
{
  Render::View *v2; // rbp
  FX::HardwareOcclusionQuery *v3; // rsi
  Illusion::SubmitContext *v4; // r14
  Illusion::IOcclusion *v5; // rbx
  Illusion::Target **v6; // rdi
  unsigned int v7; // eax
  char *v9; // rdi
  unsigned int v10; // ebx

  v2 = view;
  v3 = this;
  v4 = view->mSubmitContext;
  if ( this->mQueryID == -1 )
  {
    v5 = Render::GetOcclusionSystem();
    v6 = (Illusion::Target **)Render::View::GetStateValues(v2)->mParamValues[11];
    v7 = v5->vfptr->GetQueryHandle(v5, *v6);
    v3->mQueryID = v7;
    v3->mTarget = *v6;
    if ( v7 == -1 )
      return 0;
  }
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v9 )
  {
    v10 = v3->mQueryID;
    *(_QWORD *)v9 = Render::View::GetStateValues(v2)->mParamValues[11];
    *((_DWORD *)v9 + 2) = v10;
  }
  else
  {
    v9 = 0i64;
  }
  ((void (__fastcall *)(Illusion::SubmitContext *, signed __int64, _QWORD, char *, signed __int64))v4->vfptr->AddRenderCommand)(
    v4,
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
  Render::View *v2; // rbp
  FX::HardwareOcclusionQuery *v3; // rbx
  Illusion::SubmitContext *v4; // rsi
  char *v5; // rdi
  unsigned int v6; // ebx

  v2 = view;
  v3 = this;
  v4 = view->mSubmitContext;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
  if ( v5 )
  {
    v6 = v3->mQueryID;
    *(_QWORD *)v5 = Render::View::GetStateValues(v2)->mParamValues[11];
    *((_DWORD *)v5 + 2) = v6;
  }
  else
  {
    v5 = 0i64;
  }
  v4->vfptr->AddRenderCommand(v4, 19, 0, v5);
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
  FX::HardwareOcclusionQuery *v1; // rbx
  Illusion::IOcclusion *v2; // rax
  __int64 v3; // rdx
  __int64 v4; // r8
  float result; // xmm0_4

  v1 = this;
  v2 = Render::GetOcclusionSystem();
  v3 = v1->mQueryID;
  if ( (_DWORD)v3 == -1 )
    return 0.0;
  v4 = v1->mUnculledQueryID;
  if ( (_DWORD)v4 == -1 )
    return 0.0;
  v2->vfptr->GetPercentVisible(v2, v3, v4, v1->mTarget);
  return result;
}

// File Line: 218
// RVA: 0x1CBB00
void __fastcall FX::HardwareOcclusionQuery::DrawSphere(FX::HardwareOcclusionQuery *this, Render::View *view, UFG::qMatrix44 *probeTransform)
{
  UFG::qResourceData *v3; // rsi
  UFG::qMatrix44 *v4; // r14
  unsigned int v5; // er8
  Render::View *v6; // rbx
  FX::HardwareOcclusionQuery *v7; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax

  v3 = FX::HardwareOcclusionQuery::mUnculledMat.mData;
  v4 = probeTransform;
  v5 = *(_DWORD *)&FX::HardwareOcclusionQuery::mProbeMat.mData[1].mDebugName[28];
  v6 = view;
  v7 = this;
  if ( *(_DWORD *)&FX::HardwareOcclusionQuery::mUnculledMat.mData[1].mDebugName[28] != v5 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mUnculledMat.mData[1].mDebugName[4],
      (unsigned int)FX::HardwareOcclusionQuery::mUnculledMat.mData[2].mNode.mParent,
      v5);
    v8 = v3[1].mResourceHandles.mNode.mPrev;
    if ( v8 )
      v8 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v8 + (_QWORD)v3 + 120);
    LOWORD(v8->mPrev) |= 0x20u;
  }
  if ( FX::HardwareOcclusionQuery::StartOcclusionUnculled(v7, v6) )
  {
    Render::View::Draw(v6, &FX::HardwareOcclusionQuery::mFlareProbe, v4, 0);
    FX::HardwareOcclusionQuery::EndOcclusionUnculled(v7, v6);
  }
  if ( FX::HardwareOcclusionQuery::StartOcclusion(v7, v6) )
  {
    Render::View::Draw(v6, &FX::HardwareOcclusionQuery::mFlareProbe, v4, 0);
    FX::HardwareOcclusionQuery::EndOcclusion(v7, v6);
  }
}

// File Line: 224
// RVA: 0x1CFFE0
void FX::HardwareOcclusionQuery::InitMaterial(void)
{
  UFG::qResourceData *v0; // rax
  UFG::qResourceData *v1; // rbx
  UFG::qResourceWarehouse *v2; // rax
  int v3; // edx
  unsigned int v4; // eax
  Illusion::Material *v5; // rdi
  int v6; // ebx
  UFG::qResourceWarehouse *v7; // rax
  int v8; // edx
  unsigned int v9; // ebx
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceData *v12; // rax
  UFG::qResourceData *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  unsigned int v15; // esi
  Illusion::Material *v16; // rdi
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qString v20; // [rsp+38h] [rbp-30h]

  v0 = Illusion::Factory::NewRasterState("FX.UnculledMaterial.Rasterstate", 0x8DBA91E2, 0i64, 0i64, 0i64);
  v1 = v0;
  LOWORD(v0[1].mNode.mParent) = 0;
  BYTE3(v0[1].mNode.mParent) = 1;
  v2 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v2, v1);
  UFG::qString::qString(&v20, "FXHardwardOcclusionMatUnculled");
  v4 = v20.mStringHashUpper32;
  if ( v20.mStringHashUpper32 == -1 )
  {
    v4 = UFG::qStringHashUpper32(v20.mData, v20.mStringHashUpper32 | v3);
    v20.mStringHashUpper32 = v4;
  }
  v5 = Illusion::Factory::NewMaterial(v20.mData, v4, 3u, 0i64, 0i64, 0i64);
  v6 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v5[1].mNode.mChild[0]) = 0;
  HIDWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v5[1].mTypeUID = -1957338719;
  LODWORD(v5[1].mResourceHandles.mNode.mNext) = v6;
  *(_WORD *)&v5[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v5[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v5[1].mMaterialUser.mOffset) = 0;
  *(&v5[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v5[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v5[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v5[2].mNode.mUID = -1917152798;
  v7 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v7, (UFG::qResourceData *)&v5->mNode);
  v9 = v20.mStringHashUpper32;
  if ( v20.mStringHashUpper32 == -1 )
  {
    v9 = UFG::qStringHashUpper32(v20.mData, v20.mStringHashUpper32 | v8);
    v20.mStringHashUpper32 = v9;
  }
  v10 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v10;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mUnculledMat.mPrev,
    0xB4C26312,
    v9,
    v10);
  UFG::qString::~qString(&v20);
  v12 = Illusion::Factory::NewRasterState(FX::RasterStateFlareNoColor, 0x22E6858Bu, 0i64, 0i64, 0i64);
  v13 = v12;
  LODWORD(v12[1].mNode.mParent) = 16973825;
  v14 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v14, v13);
  v15 = UFG::qStringHashUpper32("FlareProbeMat", 0xFFFFFFFF);
  v16 = Illusion::Factory::NewMaterial("FlareProbeMat", v15, 3u, 0i64, 0i64, 0i64);
  LODWORD(v13) = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v16[1].mNode.mChild[0]) = 0;
  HIDWORD(v16[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v16[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v16[1].mTypeUID = -1957338719;
  LODWORD(v16[1].mResourceHandles.mNode.mNext) = (_DWORD)v13;
  *(_WORD *)&v16[1].mDebugName[12] = 0;
  *(_DWORD *)&v16[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v16[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v16[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v16[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v16[1].mMaterialUser.mOffset) = 0;
  *(&v16[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v16[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v16[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v16[2].mNode.mUID = 585532811;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, (UFG::qResourceData *)&v16->mNode);
  v18 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v18;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&FX::HardwareOcclusionQuery::mProbeMat.mPrev, 0xB4C26312, v15, v18);
}

