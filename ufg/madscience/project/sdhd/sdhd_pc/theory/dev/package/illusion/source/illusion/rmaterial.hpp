// File Line: 115
// RVA: 0x6DD50
void __fastcall Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(Illusion::eRenderPass::CustomRenderPass *this, Illusion::eRenderPass::StaticPassData *static_pass_data, unsigned int shader_uid, unsigned int alpha_uid, unsigned int raster_uid)
{
  unsigned int v5; // er15
  unsigned int v6; // er14
  Illusion::eRenderPass::CustomRenderPass *v7; // rbx
  UFG::qResourceHandle *v8; // rsi
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax

  v5 = alpha_uid;
  v6 = shader_uid;
  v7 = this;
  this->mStaticPassData = static_pass_data;
  v8 = (UFG::qResourceHandle *)&this->mShaderHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7->mAlphaStateHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7->mRasterStateHandle.mPrev);
  v7->mStaticPassData->mCustomRenderPass = v7;
  v9 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v9;
  }
  UFG::qResourceHandle::Init(v8, 0x8B5561A1, v6, v9);
  v11 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v11;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7->mAlphaStateHandle.mPrev, 0x12C800F2u, v5, v11);
  v13 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v13;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7->mRasterStateHandle.mPrev, 0x3BC715E0u, raster_uid, v13);
}

// File Line: 122
// RVA: 0x6E0F0
void __fastcall Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(Illusion::eRenderPass::CustomRenderPass *this)
{
  Illusion::eRenderPass::CustomRenderPass *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceHandle *v7; // rbx
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  v1 = this;
  this->mStaticPassData->mCustomRenderPass = 0i64;
  v2 = (UFG::qResourceHandle *)&this->mRasterStateHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v5 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mAlphaStateHandle.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mAlphaStateHandle.mPrev);
  v7 = (UFG::qResourceHandle *)&v1->mShaderHandle.mPrev;
  v8 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Close(v7, v8);
  UFG::qResourceHandle::~qResourceHandle(v7);
}

// File Line: 144
// RVA: 0x4BA0
void __fastcall Illusion::rMaterial::rMaterial(Illusion::rMaterial *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+60h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v4 = &this->mHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Illusion::rMaterial,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rMaterial::`vftable';
  `eh vector constructor iterator'(
    this->mRenderPass,
    0x48ui64,
    4,
    (void (__fastcall *)(void *))Illusion::eRenderPass::PassData::PassData);
}

// File Line: 147
// RVA: 0x5210
void __fastcall Illusion::rMaterial::~rMaterial(Illusion::rMaterial *this)
{
  Illusion::rMaterial *v1; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v2; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rMaterial::`vftable';
  `eh vector destructor iterator'(
    this->mRenderPass,
    0x48ui64,
    4,
    (void (__fastcall *)(void *))Illusion::TextureUser::~TextureUser);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v4 = &v1->mHandles;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&v1->mHandles);
  v2 = v1->mHandles.mNode.mPrev;
  v3 = v1->mHandles.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 199
// RVA: 0x95910
void __fastcall Illusion::rMaterial::SetStateValues(Illusion::rMaterial *this, Illusion::StateValues *state_values, Illusion::eRenderPass::Enum render_pass)
{
  Illusion::StateValues *v3; // r10
  UFG::qResourceData *v4; // rax
  UFG::qResourceData *v5; // rax
  UFG::qResourceData *v6; // rax
  UFG::qResourceData *v7; // rdx
  UFG::qResourceData *v8; // rax
  UFG::qResourceData *v9; // rax

  v3 = state_values;
  state_values->mSetValueMask.mFlags[1] = 0i64;
  state_values->mSetValueMask.mFlags[0] = 0i64;
  if ( render_pass == -1 )
  {
    v4 = this->mStaticRenderPass->mCustomRenderPass->mShaderHandle.mData;
    state_values->mSetValueMask.mFlags[0] = 2i64;
    state_values->mParamValues[1] = v4;
    v5 = this->mStaticRenderPass->mCustomRenderPass->mAlphaStateHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v5;
    v6 = this->mStaticRenderPass->mCustomRenderPass->mRasterStateHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v6;
  }
  else
  {
    v7 = this->mStaticRenderPass->mShaderHandle[render_pass].mData;
    v3->mSetValueMask.mFlags[0] = 2i64;
    v3->mParamValues[1] = v7;
    v8 = this->mRenderPass[render_pass].mAlphaStateHandle.mData;
    v3->mSetValueMask.mFlags[0] |= 0x200ui64;
    v3->mParamValues[9] = v8;
    v9 = this->mRenderPass[render_pass].mRasterStateHandle.mData;
    v3->mSetValueMask.mFlags[0] |= 0x400ui64;
    v3->mParamValues[10] = v9;
  }
  ((void (__fastcall *)(Illusion::rMaterial *, Illusion::StateValues *, _QWORD))this->vfptr[2].__vecDelDtor)(
    this,
    v3,
    render_pass);
}

// File Line: 219
// RVA: 0x5B10
void __fastcall Illusion::rMaterial::OnChange(Illusion::rMaterial *this)
{
  Illusion::rMaterial *v1; // rbx
  __int64 v2; // rax
  unsigned int v3; // edi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *v9; // rax
  unsigned int v10; // edi
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  unsigned int v13; // edi
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *v15; // rax
  unsigned int v16; // edi
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  unsigned int v19; // edi
  UFG::qResourceWarehouse *v20; // rax
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  unsigned int v23; // edi
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[1].GetTypeName)();
  v3 = v1->mRenderState.AlphaState;
  v1->mStaticRenderPass = (Illusion::eRenderPass::StaticPassData *)v2;
  v4 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)v1->mRenderPass, 0x12C800F2u, v3, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  v7 = v1->mRenderState.RasterState;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mRenderPass[0].mRasterStateHandle.mPrev, 0x3BC715E0u, v7, v6);
  v9 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  v10 = v1->mRenderState.AlphaState;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v11, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v9;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mRenderPass[1].mAlphaStateHandle.mPrev, 0x12C800F2u, v10, v9);
  v12 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  v13 = v1->mRenderState.RasterState;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v12;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mRenderPass[1].mRasterStateHandle.mPrev,
    0x3BC715E0u,
    v13,
    v12);
  v15 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  v16 = v1->mRenderState.AlphaState;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v17, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v15;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mRenderPass[2].mAlphaStateHandle.mPrev, 0x12C800F2u, v16, v15);
  v18 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  v19 = v1->mRenderState.RasterState;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v20 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v20, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v18;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mRenderPass[2].mRasterStateHandle.mPrev,
    0x3BC715E0u,
    v19,
    v18);
  v21 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v21;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mRenderPass[3].mAlphaStateHandle.mPrev,
    0x12C800F2u,
    0x91A2DD53,
    v21);
  v23 = -1130385655;
  if ( v1->mRenderState.RasterState == -1810908948 )
    v23 = -1810908948;
  v24 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v25 = UFG::qResourceWarehouse::Instance();
    v24 = UFG::qResourceWarehouse::GetInventory(v25, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v24;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mRenderPass[3].mRasterStateHandle.mPrev,
    0x3BC715E0u,
    v23,
    v24);
  v1->mRenderPass[0].mIsActive = v1->mRenderState.mDecalLayer == 0;
  v1->mRenderPass[1].mIsActive = v1->mRenderState.mDecalLayer;
  v1->mRenderPass[2].mIsActive = v1->mRenderState.AlphaState == -1145803578;
  Illusion::rMaterial::mDebugAnyIsolatedMaterials = ((__int64 (__fastcall *)(Illusion::rMaterial *))v1->vfptr[3].__vecDelDtor)(v1);
  v1->vfptr[2].GetTypeName((UFG::qReflectObject *)&v1->vfptr);
}

