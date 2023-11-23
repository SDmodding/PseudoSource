// File Line: 115
// RVA: 0x6DD50
void __fastcall Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(
        Illusion::eRenderPass::CustomRenderPass *this,
        Illusion::eRenderPass::StaticPassData *static_pass_data,
        unsigned int shader_uid,
        unsigned int alpha_uid,
        unsigned int raster_uid)
{
  Illusion::ShaderHandle *p_mShaderHandle; // rsi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax

  this->mStaticPassData = static_pass_data;
  p_mShaderHandle = &this->mShaderHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mAlphaStateHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateHandle);
  this->mStaticPassData->mCustomRenderPass = this;
  Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mShaderHandle, 0x8B5561A1, shader_uid, Inventory);
  v11 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v11;
  }
  UFG::qResourceHandle::Init(&this->mAlphaStateHandle, 0x12C800F2u, alpha_uid, v11);
  v13 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v13;
  }
  UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, raster_uid, v13);
}

// File Line: 122
// RVA: 0x6E0F0
void __fastcall Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(
        Illusion::eRenderPass::CustomRenderPass *this)
{
  Illusion::RasterStateHandle *p_mRasterStateHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  Illusion::ShaderHandle *p_mShaderHandle; // rbx
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  this->mStaticPassData->mCustomRenderPass = 0i64;
  p_mRasterStateHandle = &this->mRasterStateHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mRasterStateHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mRasterStateHandle);
  v5 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v5;
  }
  UFG::qResourceHandle::Close(&this->mAlphaStateHandle, v5);
  UFG::qResourceHandle::~qResourceHandle(&this->mAlphaStateHandle);
  p_mShaderHandle = &this->mShaderHandle;
  v8 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v8;
  }
  UFG::qResourceHandle::Close(p_mShaderHandle, v8);
  UFG::qResourceHandle::~qResourceHandle(p_mShaderHandle);
}

// File Line: 144
// RVA: 0x4BA0
void __fastcall Illusion::rMaterial::rMaterial(Illusion::rMaterial *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Illusion::rMaterial,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rMaterial::`vftable;
  `eh vector constructor iterator(
    this->mRenderPass,
    0x48ui64,
    4,
    (void (__fastcall *)(void *))Illusion::eRenderPass::PassData::PassData);
}

// File Line: 147
// RVA: 0x5210
void __fastcall Illusion::rMaterial::~rMaterial(Illusion::rMaterial *this)
{
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax

  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rMaterial::`vftable;
  `eh vector destructor iterator(
    this->mRenderPass,
    0x48ui64,
    4,
    (void (__fastcall *)(void *))Illusion::TextureUser::~TextureUser);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&this->mHandles);
  mPrev = this->mHandles.mNode.mPrev;
  mNext = this->mHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
}

// File Line: 199
// RVA: 0x95910
void __fastcall Illusion::rMaterial::SetStateValues(
        Illusion::rMaterial *this,
        Illusion::StateValues *state_values,
        unsigned int render_pass)
{
  UFG::qResourceData *mData; // rax
  UFG::qResourceData *v6; // rax
  UFG::qResourceData *v7; // rax
  UFG::qResourceData *v8; // rdx
  char *v9; // rcx
  void *v10; // rax
  void *v11; // rax

  state_values->mSetValueMask.mFlags[1] = 0i64;
  state_values->mSetValueMask.mFlags[0] = 0i64;
  if ( render_pass == -1 )
  {
    mData = this->mStaticRenderPass->mCustomRenderPass->mShaderHandle.mData;
    state_values->mSetValueMask.mFlags[0] = 2i64;
    state_values->mParamValues[1] = mData;
    v6 = this->mStaticRenderPass->mCustomRenderPass->mAlphaStateHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v6;
    v7 = this->mStaticRenderPass->mCustomRenderPass->mRasterStateHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v7;
  }
  else
  {
    v8 = this->mStaticRenderPass->mShaderHandle[render_pass].mData;
    state_values->mSetValueMask.mFlags[0] = 2i64;
    state_values->mParamValues[1] = v8;
    v9 = (char *)this + 72 * (int)render_pass;
    v10 = (void *)*((_QWORD *)v9 + 16);
    state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
    state_values->mParamValues[9] = v10;
    v11 = (void *)*((_QWORD *)v9 + 20);
    state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
    state_values->mParamValues[10] = v11;
  }
  ((void (__fastcall *)(Illusion::rMaterial *, Illusion::StateValues *, _QWORD))this->vfptr[2].__vecDelDtor)(
    this,
    state_values,
    render_pass);
}

// File Line: 219
// RVA: 0x5B10
void __fastcall Illusion::rMaterial::OnChange(Illusion::rMaterial *this)
{
  Illusion::eRenderPass::StaticPassData *v2; // rax
  unsigned int AlphaState; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  unsigned int RasterState; // edi
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

  v2 = (Illusion::eRenderPass::StaticPassData *)this->vfptr[1].GetTypeName(this);
  AlphaState = this->mRenderState.AlphaState;
  this->mStaticRenderPass = v2;
  Inventory = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[0].mAlphaStateHandle, 0x12C800F2u, AlphaState, Inventory);
  v6 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  RasterState = this->mRenderState.RasterState;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[0].mRasterStateHandle, 0x3BC715E0u, RasterState, v6);
  v9 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  v10 = this->mRenderState.AlphaState;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v11, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v9;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[1].mAlphaStateHandle, 0x12C800F2u, v10, v9);
  v12 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  v13 = this->mRenderState.RasterState;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v12;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[1].mRasterStateHandle, 0x3BC715E0u, v13, v12);
  v15 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  v16 = this->mRenderState.AlphaState;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v17, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v15;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[2].mAlphaStateHandle, 0x12C800F2u, v16, v15);
  v18 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  v19 = this->mRenderState.RasterState;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v20 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v20, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v18;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[2].mRasterStateHandle, 0x3BC715E0u, v19, v18);
  v21 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v21;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[3].mAlphaStateHandle, 0x12C800F2u, 0x91A2DD53, v21);
  v23 = -1130385655;
  if ( this->mRenderState.RasterState == DoubleSided )
    v23 = -1810908948;
  v24 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v25 = UFG::qResourceWarehouse::Instance();
    v24 = UFG::qResourceWarehouse::GetInventory(v25, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v24;
  }
  UFG::qResourceHandle::Init(&this->mRenderPass[3].mRasterStateHandle, 0x3BC715E0u, v23, v24);
  this->mRenderPass[0].mIsActive = !this->mRenderState.mDecalLayer;
  this->mRenderPass[1].mIsActive = this->mRenderState.mDecalLayer;
  this->mRenderPass[2].mIsActive = this->mRenderState.AlphaState == -1145803578;
  Illusion::rMaterial::mDebugAnyIsolatedMaterials = ((__int64 (__fastcall *)(Illusion::rMaterial *))this->vfptr[3].__vecDelDtor)(this);
  this->vfptr[2].GetTypeName(this);
}

