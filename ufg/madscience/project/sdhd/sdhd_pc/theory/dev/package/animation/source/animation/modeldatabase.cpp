// File Line: 33
// RVA: 0x146AEA0
__int64 dynamic_initializer_for__ModelType::smUnresolvedModels__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ModelType::smUnresolvedModels__);
}

// File Line: 40
// RVA: 0x1BEDC0
void __fastcall ModelType::ModelType(ModelType *this)
{
  UFG::RigHandle *p_mRigHandle; // rbx

  this->mPrev = this;
  this->mNext = this;
  p_mRigHandle = &this->mRigHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  p_mRigHandle->mLoadFunction = 0i64;
  p_mRigHandle->mUnloadFunction = 0i64;
  p_mRigHandle->mUserData = 0i64;
  p_mRigHandle->mUFGSkeleton = 0i64;
  this->mModelBindingSkinTable.mNode.mPrev = &this->mModelBindingSkinTable.mNode;
  this->mModelBindingSkinTable.mNode.mNext = &this->mModelBindingSkinTable.mNode;
  this->mModelBindingRigidTable.mNode.mPrev = &this->mModelBindingRigidTable.mNode;
  this->mModelBindingRigidTable.mNode.mNext = &this->mModelBindingRigidTable.mNode;
  this->mQueuedVisibilityCommands.mNode.mPrev = &this->mQueuedVisibilityCommands.mNode;
  this->mQueuedVisibilityCommands.mNode.mNext = &this->mQueuedVisibilityCommands.mNode;
  *(_QWORD *)&this->mAABBMax.z = -804905914i64;
  this->mAABBMin.x = 8999999500.0;
  this->mAABBMin.y = 8999999500.0;
  this->mAABBMin.z = 8999999500.0;
  this->mAABBMax.x = -8999999500.0;
  this->mAABBMax.y = -8999999500.0;
}

// File Line: 55
// RVA: 0x1BF220
void __fastcall ModelType::~ModelType(ModelType *this)
{
  UFG::qList<VisibilityCommand,VisibilityCommand,1,0> *p_mQueuedVisibilityCommands; // rbx
  UFG::qNode<VisibilityCommand,VisibilityCommand> *mPrev; // rcx
  UFG::qNode<VisibilityCommand,VisibilityCommand> *mNext; // rax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v5; // rcx
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v6; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v7; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v8; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qNode<ModelType,ModelType> *v11; // rcx
  UFG::qNode<ModelType,ModelType> *v12; // rax

  p_mQueuedVisibilityCommands = &this->mQueuedVisibilityCommands;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mQueuedVisibilityCommands);
  mPrev = p_mQueuedVisibilityCommands->mNode.mPrev;
  mNext = p_mQueuedVisibilityCommands->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mQueuedVisibilityCommands->mNode.mPrev = &p_mQueuedVisibilityCommands->mNode;
  p_mQueuedVisibilityCommands->mNode.mNext = &p_mQueuedVisibilityCommands->mNode;
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0>::DeleteNodes(&this->mModelBindingRigidTable);
  v5 = this->mModelBindingRigidTable.mNode.mPrev;
  v6 = this->mModelBindingRigidTable.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mModelBindingRigidTable.mNode.mPrev = &this->mModelBindingRigidTable.mNode;
  this->mModelBindingRigidTable.mNode.mNext = &this->mModelBindingRigidTable.mNode;
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0>::DeleteNodes(&this->mModelBindingSkinTable);
  v7 = this->mModelBindingSkinTable.mNode.mPrev;
  v8 = this->mModelBindingSkinTable.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mModelBindingSkinTable.mNode.mPrev = &this->mModelBindingSkinTable.mNode;
  this->mModelBindingSkinTable.mNode.mNext = &this->mModelBindingSkinTable.mNode;
  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mRigHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mRigHandle);
  v11 = this->mPrev;
  v12 = this->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 70
// RVA: 0x1BF120
void __fastcall ModelType::ModelBindingSkin::~ModelBindingSkin(ModelType::ModelBindingSkin *this)
{
  ModelType::SimpleMorphTargets *mMorphTargets; // rdi
  ModelType::SkinnedDecalLayer *mDecalLayer; // rdi
  Render::Softbody *mSoftbody; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mPrev; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rax

  mMorphTargets = this->mMorphTargets;
  if ( mMorphTargets )
  {
    `eh vector destructor iterator(
      mMorphTargets,
      0x20ui64,
      2,
      (void (__fastcall *)(void *))Illusion::ModelHandle::~ModelHandle);
    operator delete[](mMorphTargets);
  }
  operator delete[](this->mSkeletonToModelBoneMap);
  mDecalLayer = this->mDecalLayer;
  if ( mDecalLayer )
  {
    ModelType::SkinnedDecalLayer::~SkinnedDecalLayer(this->mDecalLayer);
    operator delete[](mDecalLayer);
  }
  mSoftbody = this->mSoftbody;
  if ( mSoftbody )
  {
    Render::Softbody::~Softbody(this->mSoftbody);
    operator delete[](mSoftbody);
    this->mSoftbody = 0i64;
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mModelProxy.mModelHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mModelProxy.mModelHandle);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 83
// RVA: 0x1BFB00
void __fastcall ModelType::ModelBindingSkin::CreateDecalLayer(
        ModelType::ModelBindingSkin *this,
        unsigned int decal_material_uid,
        unsigned int decal_task_uid,
        unsigned int num_results)
{
  UFG::allocator::free_link *v8; // rax

  if ( !this->mDecalLayer )
  {
    v8 = UFG::qMalloc(0x48ui64, "SkinnedDecalLayer", 0i64);
    if ( v8 )
      ModelType::SkinnedDecalLayer::SkinnedDecalLayer(
        (ModelType::SkinnedDecalLayer *)v8,
        decal_material_uid,
        decal_task_uid,
        num_results);
    this->mDecalLayer = (ModelType::SkinnedDecalLayer *)v8;
  }
}

// File Line: 101
// RVA: 0x1BF050
void __fastcall ModelType::ModelBindingRigid::~ModelBindingRigid(ModelType::ModelBindingRigid *this)
{
  Illusion::ModelHandle *p_mMorphModelHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *mPrev; // rcx
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *mNext; // rax

  p_mMorphModelHandle = &this->mMorphModelHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mMorphModelHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mMorphModelHandle);
  v5 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v5;
  }
  UFG::qResourceHandle::Close(&this->mModelProxy.mModelHandle, v5);
  UFG::qResourceHandle::~qResourceHandle(&this->mModelProxy.mModelHandle);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 109
// RVA: 0x1BEE90
void __fastcall ModelType::SimpleMorphTargets::SimpleMorphTargets(ModelType::SimpleMorphTargets *this)
{
  `eh vector constructor iterator(this, 0x20ui64, 2, (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  this->mNumModelBindings = 0;
}

// File Line: 118
// RVA: 0x1BEEE0
void __fastcall ModelType::SkinnedDecalLayer::SkinnedDecalLayer(
        ModelType::SkinnedDecalLayer *this,
        unsigned int decal_material_uid,
        unsigned int decal_task_uid,
        unsigned int num_results)
{
  Illusion::MaterialHandle *p_mDecalMaterialHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax

  p_mDecalMaterialHandle = &this->mDecalMaterialHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mDecalMaterialHandle);
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mDecalMaterialHandle, 0xB4C26312, decal_material_uid, Inventory);
  *(_QWORD *)&this->mDecalSeriesCount = 0i64;
  this->mDecalVertSeries = 0i64;
  this->mDecalVerts = 0i64;
  this->mClipQuery = 0i64;
  this->mDecalTaskUID = decal_task_uid;
  this->mMaxResults = num_results;
}

// File Line: 131
// RVA: 0x1BF320
void __fastcall ModelType::SkinnedDecalLayer::~SkinnedDecalLayer(ModelType::SkinnedDecalLayer *this)
{
  unsigned int *mDecalVertSeries; // rcx
  Render::SkinClipInfo::ClipOutputVertex *mDecalVerts; // rcx
  Render::SkinClipInfo *mClipQuery; // rcx
  Illusion::MaterialHandle *p_mDecalMaterialHandle; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  mDecalVertSeries = this->mDecalVertSeries;
  if ( mDecalVertSeries )
  {
    operator delete[](mDecalVertSeries);
    this->mDecalVertSeries = 0i64;
  }
  mDecalVerts = this->mDecalVerts;
  if ( mDecalVerts )
  {
    operator delete[](mDecalVerts);
    this->mDecalVerts = 0i64;
  }
  mClipQuery = this->mClipQuery;
  if ( mClipQuery )
  {
    operator delete[](mClipQuery);
    this->mClipQuery = 0i64;
  }
  p_mDecalMaterialHandle = &this->mDecalMaterialHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mDecalMaterialHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mDecalMaterialHandle);
}

// File Line: 150
// RVA: 0x1BF8B0
void __fastcall ModelType::SkinnedDecalLayer::CreateDecal(
        ModelType::SkinnedDecalLayer *this,
        UFG::qMatrix44 *decal_world,
        UFG::qMatrix44 *model_local_world,
        float radius,
        Render::DecalSettings *settings,
        Illusion::ModelProxy *model_proxy)
{
  unsigned __int64 v9; // rax
  Render::SkinClipInfo *v10; // r14
  unsigned int v11; // edi
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  Render::SkinClipInfo::ClipOutputVertex *v14; // rbp
  int v15; // esi
  char *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  Render::SkinClipInfo *v18; // rax
  Render::SkinClipInfo *mClipQuery; // r9
  UFG::qResourceData *mData; // rdx
  UFG::qVector3 *p_mAABBMin; // rcx
  UFG::qVector3 *p_mAABBMax; // rax
  Illusion::rModel *mRModel; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  Illusion::rModel *v26; // rax
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector4 v29; // [rsp+48h] [rbp-60h] BYREF
  UFG::qVector4 v30; // [rsp+58h] [rbp-50h] BYREF

  if ( !this->mDecalVertSeries )
  {
    v9 = 4i64 * ModelType::SkinnedDecalLayer::mMaxDecals;
    if ( !is_mul_ok(ModelType::SkinnedDecalLayer::mMaxDecals, 4ui64) )
      v9 = -1i64;
    this->mDecalVertSeries = (unsigned int *)UFG::qMalloc(v9, "SkinnedDecalInfos", 0x1000ui64);
  }
  v10 = 0i64;
  if ( !this->mDecalVerts )
  {
    v11 = ModelType::SkinnedDecalLayer::mMaxDecalVerts + 1;
    v12 = 44i64 * (ModelType::SkinnedDecalLayer::mMaxDecalVerts + 1);
    if ( !is_mul_ok(ModelType::SkinnedDecalLayer::mMaxDecalVerts + 1, 0x2Cui64) )
      v12 = -1i64;
    v13 = UFG::qMalloc(v12, "SkinnedDecalResults", 0x1000ui64);
    v14 = (Render::SkinClipInfo::ClipOutputVertex *)v13;
    if ( v13 )
    {
      v15 = v11 - 1;
      if ( (int)(v11 - 1) >= 0 )
      {
        v16 = (char *)&v13[5];
        do
        {
          `vector constructor iterator(v16, 2ui64, 2, (void *(__fastcall *)(void *))UFG::qHalfFloat::qHalfFloat);
          v16 += 44;
          --v15;
        }
        while ( v15 >= 0 );
      }
    }
    else
    {
      v14 = 0i64;
    }
    this->mDecalVerts = v14;
  }
  if ( !this->mClipQuery )
  {
    v17 = UFG::qMalloc(0xF8ui64, "SkinnedDecalQuery", 0x1000ui64);
    if ( v17 )
    {
      Render::SkinClipInfo::SkinClipInfo((Render::SkinClipInfo *)v17, this->mMaxResults);
      v10 = v18;
    }
    this->mClipQuery = v10;
  }
  if ( this->mDecalVertSeries )
  {
    if ( this->mDecalVerts )
    {
      mClipQuery = this->mClipQuery;
      if ( mClipQuery )
      {
        mData = model_proxy->mModelHandle.mData;
        p_mAABBMin = &UFG::qVector3::msZero;
        if ( mData )
        {
          p_mAABBMax = (UFG::qVector3 *)&mData[1].mNode.mChild[1];
        }
        else
        {
          mRModel = model_proxy->mRModel;
          if ( mRModel )
            p_mAABBMax = &mRModel->mAABBMax;
          else
            p_mAABBMax = &UFG::qVector3::msZero;
        }
        y = p_mAABBMax->y;
        z = p_mAABBMax->z;
        v29.x = p_mAABBMax->x;
        v29.y = y;
        v29.z = z;
        v29.w = 1.0;
        if ( mData )
        {
          p_mAABBMin = (UFG::qVector3 *)&mData[1];
        }
        else
        {
          v26 = model_proxy->mRModel;
          if ( v26 )
            p_mAABBMin = &v26->mAABBMin;
        }
        v27 = p_mAABBMin->y;
        v28 = p_mAABBMin->z;
        v30.x = p_mAABBMin->x;
        v30.y = v27;
        v30.z = v28;
        v30.w = 1.0;
        Render::SkinClipInfo::SubmitClipQuery(
          mClipQuery,
          decal_world,
          model_local_world,
          radius,
          &v30,
          &v29,
          settings->mFalloff,
          settings->mDepth);
      }
    }
  }
}

// File Line: 170
// RVA: 0x1C06A0
void __fastcall ModelType::SkinnedDecalLayer::UpdateDecalMesh(ModelType::SkinnedDecalLayer *this)
{
  unsigned int ResultVertexCount; // eax
  unsigned int v3; // r8d
  unsigned int v4; // ebp
  unsigned int v5; // r8d
  unsigned int v6; // edi
  unsigned int v7; // esi
  bool v8; // zf
  __int64 v9; // rcx
  __int64 v10; // r8
  unsigned int v11; // edx
  __int64 mDecalSeriesCount; // rcx
  unsigned int result_verts_written; // [rsp+30h] [rbp+8h] BYREF

  if ( Render::SkinClipInfo::AllResultsReady(this->mClipQuery) )
  {
    ResultVertexCount = Render::SkinClipInfo::GetResultVertexCount(this->mClipQuery);
    v3 = ModelType::SkinnedDecalLayer::mMaxDecalVerts;
    v4 = ResultVertexCount;
    if ( ResultVertexCount <= ModelType::SkinnedDecalLayer::mMaxDecalVerts )
    {
      while ( 1 )
      {
        v5 = v3 - this->mDecalVertCount;
        if ( v5 >= v4 && this->mDecalSeriesCount != ModelType::SkinnedDecalLayer::mMaxDecals )
          break;
        if ( !this->mDecalSeriesCount )
          break;
        v6 = 0;
        v7 = *this->mDecalVertSeries;
        v8 = this->mDecalVertCount == v7;
        this->mDecalVertCount -= v7;
        if ( !v8 )
        {
          do
          {
            Render::SkinClipInfo::ClipOutputVertex::operator=(&this->mDecalVerts[v6], &this->mDecalVerts[v6 + v7]);
            ++v6;
          }
          while ( v6 < this->mDecalVertCount );
        }
        v8 = this->mDecalSeriesCount-- == 1;
        v9 = 0i64;
        if ( !v8 )
        {
          do
          {
            v10 = (unsigned int)(v9 + 1);
            this->mDecalVertSeries[v9] = this->mDecalVertSeries[v10];
            v9 = v10;
          }
          while ( (unsigned int)v10 < this->mDecalSeriesCount );
        }
        v3 = ModelType::SkinnedDecalLayer::mMaxDecalVerts;
      }
      Render::SkinClipInfo::ReadQueryResult(
        this->mClipQuery,
        &this->mDecalVerts[this->mDecalVertCount],
        v5,
        &result_verts_written);
      v11 = result_verts_written;
      mDecalSeriesCount = this->mDecalSeriesCount;
      this->mDecalVertCount += result_verts_written;
      this->mDecalVertSeries[mDecalSeriesCount] = v11;
      ++this->mDecalSeriesCount;
    }
  }
}

// File Line: 208
// RVA: 0x1BFC40
void __fastcall ModelType::SkinnedDecalLayer::Draw(
        ModelType::SkinnedDecalLayer *this,
        Render::Skinning *skinning,
        Render::SkinningParams *params)
{
  Render::SkinClipInfo::ClipOutputVertex *mDecalVerts; // rax

  if ( this->mDecalVertCount )
  {
    params->mDecalMaterial = (Illusion::Material *)this->mDecalMaterialHandle.mData;
    params->mDecalVertNum = this->mDecalVertCount;
    mDecalVerts = this->mDecalVerts;
    params->clip_info = 0i64;
    params->mDecalVerts = mDecalVerts;
    params->mDecalTaskUID = this->mDecalTaskUID;
    Render::Skinning::DrawSkinnedDecal(skinning, params);
  }
}

// File Line: 230
// RVA: 0x1BFE10
void __fastcall ModelType::RemoveModelBinding(ModelType *this, Illusion::ModelProxy *model_proxy)
{
  ModelType::ModelBindingSkin *mNext; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // rbp
  Illusion::rModel *mRModel; // rax
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *v7; // rdi
  unsigned int mNameUID; // eax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mPrev; // rax
  ModelType::ModelBindingRigid *v10; // rbx
  Illusion::rModel *v11; // rax
  ModelType *v12; // rdi
  unsigned int v13; // eax
  UFG::qNode<ModelType,ModelType> *v14; // rax

  mNext = (ModelType::ModelBindingSkin *)this->mModelBindingSkinTable.mNode.mNext;
  p_mModelBindingSkinTable = &this->mModelBindingSkinTable;
  if ( mNext != (ModelType::ModelBindingSkin *)&this->mModelBindingSkinTable )
  {
    do
    {
      mRModel = mNext->mModelProxy.mRModel;
      v7 = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)mNext->mNext;
      if ( mRModel && mRModel == model_proxy->mRModel
        || (mNameUID = model_proxy->mModelHandle.mNameUID) != 0 && mNameUID == mNext->mModelProxy.mModelHandle.mNameUID )
      {
        mPrev = mNext->mPrev;
        mPrev->mNext = &v7->mNode;
        v7->mNode.mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        ModelType::ModelBindingSkin::~ModelBindingSkin(mNext);
        operator delete[](mNext);
      }
      mNext = (ModelType::ModelBindingSkin *)v7;
    }
    while ( v7 != p_mModelBindingSkinTable );
  }
  v10 = (ModelType::ModelBindingRigid *)this->mModelBindingRigidTable.mNode.mNext;
  if ( v10 != (ModelType::ModelBindingRigid *)&this->mModelBindingRigidTable )
  {
    do
    {
      v11 = v10->mModelProxy.mRModel;
      v12 = (ModelType *)v10->mNext;
      if ( v11 && v11 == model_proxy->mRModel
        || (v13 = model_proxy->mModelHandle.mNameUID) != 0 && v13 == v10->mModelProxy.mModelHandle.mNameUID )
      {
        v14 = (UFG::qNode<ModelType,ModelType> *)v10->mPrev;
        v14->mNext = v12;
        v12->mPrev = v14;
        v10->mPrev = v10;
        v10->mNext = v10;
        ModelType::ModelBindingRigid::~ModelBindingRigid(v10);
        operator delete[](v10);
      }
      v10 = (ModelType::ModelBindingRigid *)v12;
    }
    while ( v12 != (ModelType *)&this->mModelBindingRigidTable );
  }
}

// File Line: 257
// RVA: 0x1BFDB0
void __fastcall ModelType::RemoveAllSkinModelBindings(ModelType *this)
{
  ModelType::ModelBindingSkin *mNext; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *i; // rdi
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mPrev; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v4; // rax

  mNext = (ModelType::ModelBindingSkin *)this->mModelBindingSkinTable.mNode.mNext;
  for ( i = &this->mModelBindingSkinTable;
        mNext != (ModelType::ModelBindingSkin *)i;
        mNext = (ModelType::ModelBindingSkin *)i->mNode.mNext )
  {
    mPrev = mNext->mPrev;
    v4 = mNext->mNext;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    ModelType::ModelBindingSkin::~ModelBindingSkin(mNext);
    operator delete[](mNext);
  }
}

// File Line: 262
// RVA: 0x1BFF00
void __fastcall ModelType::SetRigidModelVisibilityOnBone(ModelType *this, unsigned int bone_name_uid, bool visible)
{
  UFG::qBaseNodeRB *mParent; // rcx
  int BoneID; // eax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *mNext; // r9
  int v9; // ecx
  ModelType *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdx
  UFG::qNode<VisibilityCommand,VisibilityCommand> *mPrev; // rax

  mParent = this->mRigHandle.mData[3].mNode.mParent;
  if ( mParent )
  {
    BoneID = Skeleton::GetBoneID((Skeleton *)mParent, bone_name_uid);
    mNext = this->mModelBindingRigidTable.mNode.mNext;
    if ( mNext != (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&this->mModelBindingRigidTable )
    {
      while ( LOWORD(mNext[7].mPrev) != BoneID )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&this->mModelBindingRigidTable )
          goto LABEL_7;
      }
      WORD1(mNext[7].mPrev) = visible;
    }
  }
LABEL_7:
  v9 = -1;
  v10 = (ModelType *)ModelType::smUnresolvedModels.mNode.mNext;
  if ( (UFG::qList<ModelType,ModelType,1,0> *)ModelType::smUnresolvedModels.mNode.mNext != &ModelType::smUnresolvedModels )
  {
    while ( 1 )
    {
      ++v9;
      if ( v10 == this )
        break;
      v10 = (ModelType *)v10->mNext;
      if ( v10 == (ModelType *)&ModelType::smUnresolvedModels )
        return;
    }
    if ( v9 != -1 )
    {
      v11 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v12 = v11;
      if ( v11 )
      {
        v11->mNext = v11;
        v11[1].mNext = v11;
      }
      else
      {
        v12 = 0i64;
      }
      LODWORD(v12[2].mNext) = bone_name_uid;
      BYTE4(v12[2].mNext) = visible;
      mPrev = this->mQueuedVisibilityCommands.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<VisibilityCommand,VisibilityCommand> *)v12;
      v12->mNext = (UFG::allocator::free_link *)mPrev;
      v12[1].mNext = (UFG::allocator::free_link *)&this->mQueuedVisibilityCommands;
      this->mQueuedVisibilityCommands.mNode.mPrev = (UFG::qNode<VisibilityCommand,VisibilityCommand> *)v12;
    }
  }
}

// File Line: 293
// RVA: 0x1BFD10
void __fastcall ModelType::ProcessQueuedVisibilityCommands(ModelType *this)
{
  UFG::qNode<VisibilityCommand,VisibilityCommand> *mNext; // rbx
  UFG::qList<VisibilityCommand,VisibilityCommand,1,0> *i; // rbp
  char v4; // si
  UFG::qBaseNodeRB *mParent; // rcx
  int BoneID; // eax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v7; // rcx

  mNext = this->mQueuedVisibilityCommands.mNode.mNext;
  for ( i = &this->mQueuedVisibilityCommands;
        mNext != (UFG::qNode<VisibilityCommand,VisibilityCommand> *)i;
        mNext = mNext->mNext )
  {
    v4 = BYTE4(mNext[1].mPrev);
    mParent = this->mRigHandle.mData[3].mNode.mParent;
    if ( mParent )
    {
      BoneID = Skeleton::GetBoneID((Skeleton *)mParent, (unsigned int)mNext[1].mPrev);
      v7 = this->mModelBindingRigidTable.mNode.mNext;
      if ( v7 != (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&this->mModelBindingRigidTable )
      {
        while ( LOWORD(v7[7].mPrev) != BoneID )
        {
          v7 = v7->mNext;
          if ( v7 == (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&this->mModelBindingRigidTable )
            goto LABEL_8;
        }
        WORD1(v7[7].mPrev) = v4 != 0;
      }
    }
LABEL_8:
    ;
  }
}

// File Line: 303
// RVA: 0x1BF700
ModelType::ModelBindingSkin *__fastcall ModelType::AddSkinModelBinding(
        ModelType *this,
        Illusion::ModelProxy *model_proxy,
        UFG::qMatrix44 *mat,
        unsigned int model_index,
        unsigned int lod)
{
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rax
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // r14
  Illusion::rModel *v10; // r8
  unsigned int mNameUID; // ecx
  UFG::allocator::free_link *v13; // rax
  ModelType::ModelBindingSkin *v14; // rbx
  UFG::qResourceHandle *v15; // rsi
  unsigned int v16; // r15d
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mPrev; // rax
  unsigned int SkinnedDecalMaterialUID; // eax
  unsigned int task_uid; // [rsp+20h] [rbp-58h] BYREF
  __int64 v22; // [rsp+28h] [rbp-50h]
  UFG::allocator::free_link *v23; // [rsp+30h] [rbp-48h]
  UFG::allocator::free_link *v24; // [rsp+38h] [rbp-40h]
  UFG::allocator::free_link *v25; // [rsp+40h] [rbp-38h]
  unsigned int mesh_count; // [rsp+80h] [rbp+8h] BYREF

  v22 = -2i64;
  mNext = this->mModelBindingSkinTable.mNode.mNext;
  p_mModelBindingSkinTable = &this->mModelBindingSkinTable;
  while ( mNext != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
  {
    v10 = (Illusion::rModel *)mNext[4].mNext;
    if ( v10 && v10 == model_proxy->mRModel )
      return 0i64;
    mNameUID = model_proxy->mModelHandle.mNameUID;
    if ( mNameUID )
    {
      if ( mNameUID == LODWORD(mNext[4].mPrev) )
        return 0i64;
    }
    mNext = mNext->mNext;
  }
  ModelType::UpdateAABB(this, model_proxy);
  v13 = UFG::qMalloc(0x68ui64, "AddSkinModelBinding", 0i64);
  v14 = (ModelType::ModelBindingSkin *)v13;
  v23 = v13;
  if ( v13 )
  {
    v13->mNext = v13;
    v13[1].mNext = v13;
    v15 = (UFG::qResourceHandle *)&v13[5];
    v24 = v13 + 5;
    v25 = v13 + 5;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v13[5]);
    v16 = model_proxy->mModelHandle.mNameUID;
    Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v18 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(v15, 0xA2ADCD77, v16, Inventory);
    v15[1].mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)model_proxy->mRModel;
    v14->mNumMappedBones = 0;
    v14->mMorphTargets = 0i64;
    v14->mDecalLayer = 0i64;
    v14->mSkeletonToModelBoneMap = 0i64;
    v14->mModelIndex = 0;
    v14->mSoftbody = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  mPrev = p_mModelBindingSkinTable->mNode.mPrev;
  mPrev->mNext = v14;
  v14->mPrev = mPrev;
  v14->mNext = &p_mModelBindingSkinTable->mNode;
  p_mModelBindingSkinTable->mNode.mPrev = v14;
  v14->mNumMappedBones = 0;
  v14->mModelIndex = model_index;
  ModelType::buildSkeletonToModelBoneMap(this, v14);
  task_uid = 0;
  mesh_count = 0;
  if ( !lod
    && Render::Skinning::SupportsSkinnedDecals(&Render::Skinning::gSkinning, model_proxy, &task_uid, &mesh_count)
    && task_uid
    && mesh_count )
  {
    SkinnedDecalMaterialUID = Render::DecalManager::GetSkinnedDecalMaterialUID(&Render::gDecalManager);
    ModelType::ModelBindingSkin::CreateDecalLayer(v14, SkinnedDecalMaterialUID, task_uid, mesh_count);
  }
  return v14;
}

// File Line: 353
// RVA: 0x1BFD00
UFG::qBaseNodeRB *__fastcall ModelType::GetSkeleton(ModelType *this)
{
  return this->mRigHandle.mData[3].mNode.mParent;
}

// File Line: 398
// RVA: 0x1C0AD0
void __fastcall ModelType::buildSkeletonToModelBoneMap(ModelType *this, ModelType::ModelBindingSkin *model_binding)
{
  UFG::qResourceData *mData; // rdi
  UFG::qResourceData *v5; // rdi
  Illusion::rModel *mRModel; // rdi
  char *v7; // rax
  unsigned int v8; // r12d
  unsigned int v9; // r15d
  unsigned int mParent_high; // ecx
  unsigned int i; // ebp
  unsigned int v12; // edx
  UFG::qBaseNodeRB *v13; // rax
  unsigned int v14; // edx
  char BoneID; // al
  UFG::qResourceData *v16; // rbx
  UFG::qWiseSymbol *v17; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF

  ModelType::UpdateAABB(this, &model_binding->mModelProxy);
  mData = model_binding->mModelProxy.mModelHandle.mData;
  if ( mData )
  {
    v5 = *(UFG::qResourceData **)&mData[1].mDebugName[28];
  }
  else
  {
    mRModel = model_binding->mModelProxy.mRModel;
    if ( !mRModel )
      return;
    v5 = mRModel->mBonePaletteHandle.mData;
  }
  if ( !model_binding->mSkeletonToModelBoneMap )
  {
    if ( v5 )
    {
      v7 = (char *)UFG::qMalloc((unsigned int)(160 * LODWORD(v5[1].mNode.mParent)), "SkeletonToModelBoneMap", 0i64);
      model_binding->mSkeletonToModelBoneMap = v7;
      UFG::qMemSet(v7, 255, 160 * LODWORD(v5[1].mNode.mParent));
      v8 = 0;
      if ( LODWORD(v5[1].mNode.mParent) )
      {
        v9 = 0;
        do
        {
          mParent_high = HIDWORD(v5[1].mNode.mParent);
          for ( i = 0; i < mParent_high; mParent_high = HIDWORD(v5[1].mNode.mParent) )
          {
            v12 = *((unsigned __int8 *)&v5[1].mResourceHandles.mNode.mNext + v9 + (unsigned __int64)i);
            if ( v12 >= mParent_high )
            {
              v14 = 0;
            }
            else
            {
              v13 = v5[1].mNode.mChild[1];
              if ( v13 )
                v14 = *(_DWORD *)((char *)&v5[1].mNode.mChild[1] + 4 * (unsigned __int8)v12 + (_QWORD)v13);
              else
                v14 = *(_DWORD *)(4i64 * (unsigned __int8)v12);
            }
            BoneID = -1;
            if ( v14 != -1 )
            {
              v16 = this->mRigHandle.mData;
              v17 = UFG::qSymbol::qSymbol(&result, v14);
              BoneID = Skeleton::GetBoneID((Skeleton *)v16[3].mNode.mParent, v17->mUID);
            }
            ++i;
            model_binding->mSkeletonToModelBoneMap[model_binding->mNumMappedBones++] = BoneID;
          }
          ++v8;
          v9 += 160;
        }
        while ( v8 < LODWORD(v5[1].mNode.mParent) );
      }
    }
  }
}

// File Line: 504
// RVA: 0x146AED0
void dynamic_initializer_for__aabb_min_start__()
{
  aabb_min_start.m_quad = (__m128)_xmm;
}

// File Line: 505
// RVA: 0x146AEC0
void dynamic_initializer_for__aabb_max_start__()
{
  aabb_max_start.m_quad = (__m128)_xmm_ff7fffffff7fffffff7fffffff7fffff;
}

// File Line: 508
// RVA: 0x1C0230
void __fastcall ModelType::UpdateAABB(ModelType *this, SkeletalPose *pose)
{
  hkaPose *mHavokPose; // rbp
  ModelType::ModelBindingSkin *mNext; // rbx
  float v6; // xmm6_4
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // r13
  char v8; // r12
  float x; // xmm10_4
  float z; // xmm9_4
  float y; // xmm11_4
  float v12; // xmm8_4
  float v13; // xmm7_4
  ModelType::ModelBindingSkin *v14; // r14
  UFG::qResourceData *mData; // rax
  float *p_x; // rdi
  float *v17; // rbx
  hkQsTransformf *m_data; // rax
  ModelType::ModelBindingRigid *v19; // rbx
  __m128 m_quad; // xmm12
  __m128 v21; // xmm13
  ModelType::ModelBindingRigid *v22; // rsi
  __int64 mBoneID; // rdx
  hkQsTransformf *v24; // rdi
  UFG::qResourceData *v25; // rax
  UFG::qVector3 *p_mAABBMin; // rcx
  UFG::qVector3 *p_mAABBMax; // rax
  __m128 v28; // [rsp+20h] [rbp-118h]
  __m128 v29; // [rsp+30h] [rbp-108h]
  hkVector4f b; // [rsp+40h] [rbp-F8h] BYREF
  hkVector4f v31; // [rsp+50h] [rbp-E8h] BYREF
  hkVector4f v32; // [rsp+60h] [rbp-D8h] BYREF
  hkVector4f v33; // [rsp+70h] [rbp-C8h] BYREF

  mHavokPose = pose->mHavokPose;
  if ( mHavokPose )
  {
    mNext = (ModelType::ModelBindingSkin *)this->mModelBindingSkinTable.mNode.mNext;
    v6 = FLOAT_N3_4028235e38;
    p_mModelBindingSkinTable = &this->mModelBindingSkinTable;
    v8 = 0;
    x = FLOAT_3_4028235e38;
    z = FLOAT_3_4028235e38;
    y = FLOAT_3_4028235e38;
    v12 = FLOAT_N3_4028235e38;
    v13 = FLOAT_N3_4028235e38;
    if ( mNext != (ModelType::ModelBindingSkin *)&this->mModelBindingSkinTable )
    {
      do
      {
        v14 = (ModelType::ModelBindingSkin *)mNext->mNext;
        if ( mNext->mModelProxy.mModelHandle.mData || mNext->mModelProxy.mRModel )
        {
          if ( mNext->mSkeletonToModelBoneMap
            || (ModelType::buildSkeletonToModelBoneMap(this, mNext), mNext->mSkeletonToModelBoneMap) )
          {
            v8 = 1;
            if ( mNext->mNumMappedBones <= 1 )
            {
              mData = mNext->mModelProxy.mModelHandle.mData;
              if ( mData )
                p_x = (float *)&mData[1];
              else
                p_x = &mNext->mModelProxy.mRModel->mAABBMin.x;
              if ( mData )
                v17 = (float *)&mData[1].mNode.mChild[1];
              else
                v17 = &mNext->mModelProxy.mRModel->mAABBMax.x;
              if ( (*(_BYTE *)mHavokPose->m_boneFlags.m_data & 2) != 0 )
                m_data = hkaPose::calculateBoneModelSpace(mHavokPose, 0);
              else
                m_data = mHavokPose->m_modelPose.m_data;
              if ( x >= (float)(m_data->m_translation.m_quad.m128_f32[0] + *p_x) )
                x = m_data->m_translation.m_quad.m128_f32[0] + *p_x;
              if ( y >= (float)(m_data->m_translation.m_quad.m128_f32[1] + p_x[1]) )
                y = m_data->m_translation.m_quad.m128_f32[1] + p_x[1];
              if ( z >= (float)(m_data->m_translation.m_quad.m128_f32[2] + p_x[2]) )
                z = m_data->m_translation.m_quad.m128_f32[2] + p_x[2];
              if ( v6 <= (float)(m_data->m_translation.m_quad.m128_f32[0] + *v17) )
                v6 = m_data->m_translation.m_quad.m128_f32[0] + *v17;
              if ( v12 <= (float)(m_data->m_translation.m_quad.m128_f32[1] + v17[1]) )
                v12 = m_data->m_translation.m_quad.m128_f32[1] + v17[1];
              if ( v13 <= (float)(m_data->m_translation.m_quad.m128_f32[2] + v17[2]) )
                v13 = m_data->m_translation.m_quad.m128_f32[2] + v17[2];
            }
            else
            {
              if ( x >= pose->mPoseAABBMin.x )
                x = pose->mPoseAABBMin.x;
              if ( y >= pose->mPoseAABBMin.y )
                y = pose->mPoseAABBMin.y;
              if ( z >= pose->mPoseAABBMin.z )
                z = pose->mPoseAABBMin.z;
              if ( v6 <= pose->mPoseAABBMax.x )
                v6 = pose->mPoseAABBMax.x;
              if ( v12 <= pose->mPoseAABBMax.y )
                v12 = pose->mPoseAABBMax.y;
              if ( v13 <= pose->mPoseAABBMax.z )
                v13 = pose->mPoseAABBMax.z;
            }
          }
        }
        mNext = v14;
      }
      while ( v14 != (ModelType::ModelBindingSkin *)p_mModelBindingSkinTable );
    }
    v19 = (ModelType::ModelBindingRigid *)this->mModelBindingRigidTable.mNode.mNext;
    m_quad = aabb_min_start.m_quad;
    v21 = aabb_max_start.m_quad;
    v28 = aabb_min_start.m_quad;
    v29 = aabb_max_start.m_quad;
    if ( v19 != (ModelType::ModelBindingRigid *)&this->mModelBindingRigidTable )
    {
      do
      {
        v22 = (ModelType::ModelBindingRigid *)v19->mNext;
        if ( (v19->mModelProxy.mModelHandle.mData || v19->mModelProxy.mRModel) && v19->mVisible )
        {
          mBoneID = v19->mBoneID;
          if ( (mHavokPose->m_boneFlags.m_data[mBoneID] & 2) != 0 )
            v24 = hkaPose::calculateBoneModelSpace(mHavokPose, mBoneID);
          else
            v24 = &mHavokPose->m_modelPose.m_data[mBoneID];
          v25 = v19->mModelProxy.mModelHandle.mData;
          v8 = 1;
          if ( v25 )
            p_mAABBMin = (UFG::qVector3 *)&v25[1];
          else
            p_mAABBMin = &v19->mModelProxy.mRModel->mAABBMin;
          if ( v25 )
            p_mAABBMax = (UFG::qVector3 *)&v25[1].mNode.mChild[1];
          else
            p_mAABBMax = &v19->mModelProxy.mRModel->mAABBMax;
          b.m_quad = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(p_mAABBMin->x), (__m128)LODWORD(p_mAABBMin->z)),
                       _mm_unpacklo_ps((__m128)LODWORD(p_mAABBMin->y), (__m128)(unsigned int)FLOAT_1_0));
          v31.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps((__m128)LODWORD(p_mAABBMax->x), (__m128)LODWORD(p_mAABBMax->z)),
                         _mm_unpacklo_ps((__m128)LODWORD(p_mAABBMax->y), (__m128)(unsigned int)FLOAT_1_0));
          hkVector4f::setTransformedPos(&v32, v24, &b);
          hkVector4f::setTransformedPos(&v33, v24, &v31);
          m_quad = _mm_min_ps(_mm_min_ps(m_quad, v32.m_quad), v33.m_quad);
          v21 = _mm_max_ps(_mm_max_ps(v21, v32.m_quad), v33.m_quad);
          v28 = m_quad;
          v29 = v21;
        }
        v19 = v22;
      }
      while ( v22 != (ModelType::ModelBindingRigid *)&this->mModelBindingRigidTable );
    }
    if ( v8 )
    {
      if ( z >= v28.m128_f32[2] )
        z = v28.m128_f32[2];
      if ( y >= v28.m128_f32[1] )
        y = v28.m128_f32[1];
      if ( x >= v28.m128_f32[0] )
        x = v28.m128_f32[0];
      this->mAABBMin.x = x;
      this->mAABBMin.y = y;
      this->mAABBMin.z = z;
      if ( v13 <= v29.m128_f32[2] )
        v13 = v29.m128_f32[2];
      if ( v12 <= v29.m128_f32[1] )
        v12 = v29.m128_f32[1];
      if ( v6 <= v29.m128_f32[0] )
        v6 = v29.m128_f32[0];
      this->mAABBMax.x = v6;
      this->mAABBMax.y = v12;
      this->mAABBMax.z = v13;
    }
  }
}

// File Line: 612
// RVA: 0x1BF470
void __fastcall ModelType::AddModelBinding(
        ModelType *this,
        Illusion::ModelProxy *model_proxy,
        UFG::qMatrix44 *mat,
        unsigned int model_index,
        unsigned int lod)
{
  Illusion::rModel *mRModel; // rax
  const char *mItems; // rcx
  unsigned int v11; // eax
  unsigned int BoneID; // eax
  unsigned int v13; // r14d
  unsigned int mNameUID; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  Illusion::ModelProxy v19; // [rsp+38h] [rbp-40h] BYREF

  mRModel = model_proxy->mRModel;
  if ( mRModel )
  {
    if ( mRModel->mBonePaletteHandle.mData )
    {
      ModelType::AddSkinModelBinding(this, model_proxy, mat, model_index, lod);
    }
    else
    {
      if ( mRModel->mModelName.mText.mData.mNumItems )
        mItems = mRModel->mModelName.mText.mData.mItems;
      else
        mItems = &customCaption;
      v11 = UFG::qStringHashUpper32(mItems, -1);
      BoneID = Skeleton::GetBoneID((Skeleton *)this->mRigHandle.mData[3].mNode.mParent, v11);
      if ( BoneID != -1 )
        ModelType::AddRigidModelBinding(this, model_proxy, BoneID, mat, model_index);
    }
  }
  else
  {
    v13 = Skeleton::GetBoneID((Skeleton *)this->mRigHandle.mData[3].mNode.mParent, model_proxy->mModelHandle.mNameUID);
    mNameUID = model_proxy->mModelHandle.mNameUID;
    UFG::qResourceHandle::qResourceHandle(&v19.mModelHandle);
    Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v16 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v19.mModelHandle, 0xA2ADCD77, mNameUID, Inventory);
    v19.mRModel = 0i64;
    ModelType::AddRigidModelBinding(this, &v19, v13, mat, model_index);
    v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v18 = UFG::qResourceWarehouse::Instance();
      v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
    }
    UFG::qResourceHandle::Close(&v19.mModelHandle, v17);
    UFG::qResourceHandle::~qResourceHandle(&v19.mModelHandle);
  }
}

// File Line: 643
// RVA: 0x1BFC90
ModelType::ModelBindingRigid *__fastcall ModelType::FindRigidModelBinding(
        ModelType *this,
        unsigned int model_name_uid,
        unsigned int bone_name_uid,
        unsigned int model_index)
{
  ModelType::ModelBindingRigid *p_mModelBindingRigidTable; // rbx
  int BoneID; // edx
  ModelType::ModelBindingRigid *result; // rax

  p_mModelBindingRigidTable = (ModelType::ModelBindingRigid *)&this->mModelBindingRigidTable;
  BoneID = Skeleton::GetBoneID((Skeleton *)this->mRigHandle.mData[3].mNode.mParent, bone_name_uid);
  result = (ModelType::ModelBindingRigid *)p_mModelBindingRigidTable->mNext;
  if ( result == p_mModelBindingRigidTable )
    return 0i64;
  while ( result->mModelUID != model_name_uid || result->mBoneID != BoneID || result->mModelIndex != model_index )
  {
    result = (ModelType::ModelBindingRigid *)result->mNext;
    if ( result == p_mModelBindingRigidTable )
      return 0i64;
  }
  return result;
}

// File Line: 659
// RVA: 0x1BF600
ModelType::ModelBindingRigid *__fastcall ModelType::AddRigidModelBinding(
        ModelType *this,
        Illusion::ModelProxy *model_proxy,
        unsigned int bone_index,
        UFG::qMatrix44 *mat,
        unsigned int model_index)
{
  ModelType::ModelBindingRigid *mNext; // rax
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *p_mModelBindingRigidTable; // rsi
  Illusion::rModel *mRModel; // rdx
  unsigned int mNameUID; // ecx
  ModelType::ModelBindingRigid *v13; // rax
  ModelType::ModelBindingRigid *v14; // rbx
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *mPrev; // rcx

  mNext = (ModelType::ModelBindingRigid *)this->mModelBindingRigidTable.mNode.mNext;
  p_mModelBindingRigidTable = &this->mModelBindingRigidTable;
  while ( mNext != (ModelType::ModelBindingRigid *)p_mModelBindingRigidTable )
  {
    mRModel = mNext->mModelProxy.mRModel;
    if ( (mRModel && mRModel == model_proxy->mRModel
       || (mNameUID = model_proxy->mModelHandle.mNameUID) != 0 && mNameUID == mNext->mModelProxy.mModelHandle.mNameUID)
      && mNext->mBoneID == bone_index
      && mNext->mModelIndex == model_index )
    {
      return 0i64;
    }
    mNext = (ModelType::ModelBindingRigid *)mNext->mNext;
  }
  ModelType::UpdateAABB(this, model_proxy);
  v13 = (ModelType::ModelBindingRigid *)UFG::qMalloc(0x78ui64, "ModelBindingRigid", 0i64);
  v14 = v13;
  if ( v13 )
  {
    v13->mPrev = v13;
    v13->mNext = v13;
    Illusion::ModelProxy::ModelProxy(&v13->mModelProxy, model_proxy);
    UFG::qResourceHandle::qResourceHandle(&v14->mMorphModelHandle);
    *(_DWORD *)&v14->mBoneID = 65536;
    *(_QWORD *)&v14->mNumMappedBones = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  v14->mBoneID = bone_index;
  v14->mModelIndex = model_index;
  mPrev = p_mModelBindingRigidTable->mNode.mPrev;
  mPrev->mNext = v14;
  v14->mPrev = mPrev;
  v14->mNext = &p_mModelBindingRigidTable->mNode;
  p_mModelBindingRigidTable->mNode.mPrev = v14;
  return v14;
}

// File Line: 700
// RVA: 0x1C00C0
void __fastcall ModelType::UpdateAABB(ModelType *this, Illusion::ModelProxy *model_proxy)
{
  float *mData; // rax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Illusion::rModel *mRModel; // rax
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4

  mData = (float *)model_proxy->mModelHandle.mData;
  if ( mData )
  {
    x = this->mAABBMin.x;
    if ( x >= mData[22] )
      x = mData[22];
    this->mAABBMin.x = x;
    y = this->mAABBMin.y;
    if ( y >= mData[23] )
      y = mData[23];
    this->mAABBMin.y = y;
    z = this->mAABBMin.z;
    if ( z >= mData[24] )
      z = mData[24];
    this->mAABBMin.z = z;
    v6 = this->mAABBMax.x;
    if ( v6 <= mData[26] )
      v6 = mData[26];
    this->mAABBMax.x = v6;
    v7 = this->mAABBMax.y;
    if ( v7 <= mData[27] )
      v7 = mData[27];
    this->mAABBMax.y = v7;
    v8 = mData[28];
  }
  else
  {
    mRModel = model_proxy->mRModel;
    if ( !mRModel )
      return;
    v10 = this->mAABBMin.x;
    if ( v10 >= mRModel->mAABBMin.x )
      v10 = mRModel->mAABBMin.x;
    this->mAABBMin.x = v10;
    v11 = this->mAABBMin.y;
    if ( v11 >= mRModel->mAABBMin.y )
      v11 = mRModel->mAABBMin.y;
    this->mAABBMin.y = v11;
    v12 = this->mAABBMin.z;
    if ( v12 >= mRModel->mAABBMin.z )
      v12 = mRModel->mAABBMin.z;
    this->mAABBMin.z = v12;
    v13 = this->mAABBMax.x;
    if ( v13 <= mRModel->mAABBMax.x )
      v13 = mRModel->mAABBMax.x;
    this->mAABBMax.x = v13;
    v14 = this->mAABBMax.y;
    if ( v14 <= mRModel->mAABBMax.y )
      v14 = mRModel->mAABBMax.y;
    this->mAABBMax.y = v14;
    v8 = mRModel->mAABBMax.z;
  }
  v15 = this->mAABBMax.z;
  if ( v15 <= v8 )
    v15 = v8;
  this->mAABBMax.z = v15;
}

// File Line: 714
// RVA: 0x1C07B0
void __fastcall ModelType::buildModelBindingRigid(ModelType *this)
{
  int v2; // edi
  UFG::qResourceData *mData; // r14
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *Inventory; // rcx
  __int64 v6; // r15
  __int64 v7; // rbp
  char *v8; // rbx
  unsigned int v9; // r13d
  __int64 v10; // rax
  char *v11; // r14
  UFG::allocator::free_link *v12; // rbx
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  unsigned int mNameUID; // r12d
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v20; // rax
  UFG::qNode<ModelType,ModelType> *mPrev; // rcx
  UFG::qNode<ModelType,ModelType> *mNext; // rax
  UFG::qNode<ModelType,ModelType> *v23; // rax
  UFG::qResourceHandle v24; // [rsp+28h] [rbp-1060h] BYREF
  UFG::allocator::free_link *v25; // [rsp+48h] [rbp-1040h]
  __int64 v26; // [rsp+50h] [rbp-1038h]
  char v27; // [rsp+68h] [rbp-1020h] BYREF
  char v28; // [rsp+6Ch] [rbp-101Ch] BYREF

  v26 = -2i64;
  v2 = 0;
  if ( (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)this->mModelBindingRigidTable.mNode.mNext == &this->mModelBindingRigidTable )
  {
    mData = this->mRigHandle.mData;
    if ( (_S5_4 & 1) != 0 )
    {
      Inventory = inventory;
    }
    else
    {
      _S5_4 |= 1u;
      v4 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
      inventory = Inventory;
    }
    LODWORD(v6) = 0;
    this->mLastInventoryQueryTransactionNum = -1;
    v7 = 0i64;
    if ( LODWORD(mData[1].mResourceHandles.mNode.mNext) )
    {
      v8 = &v27;
      while ( 1 )
      {
        v9 = *(_DWORD *)(8 * v7 + *(_QWORD *)&mData[1].mTypeUID + 4);
        v10 = (__int64)Inventory->vfptr->Get(Inventory, v9);
        if ( !v10 )
        {
          this->mLastInventoryQueryTransactionNum = inventory->mTransactionNum;
          mPrev = this->mPrev;
          mNext = this->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          this->mPrev = this;
          this->mNext = this;
          v23 = ModelType::smUnresolvedModels.mNode.mPrev;
          ModelType::smUnresolvedModels.mNode.mPrev->mNext = this;
          this->mPrev = v23;
          this->mNext = (UFG::qNode<ModelType,ModelType> *)&ModelType::smUnresolvedModels;
          ModelType::smUnresolvedModels.mNode.mPrev = this;
          return;
        }
        *((_DWORD *)v8 + 1) = *(_DWORD *)(8 * v7 + *(_QWORD *)&mData[1].mTypeUID);
        *(_DWORD *)v8 = v9;
        *((_QWORD *)v8 - 1) = v10;
        LODWORD(v6) = v6 + 1;
        v8 += 16;
        v7 = (unsigned int)(v7 + 1);
        if ( (unsigned int)v7 >= LODWORD(mData[1].mResourceHandles.mNode.mNext) )
          break;
        Inventory = inventory;
      }
      v6 = (int)v6;
      if ( (int)v6 >= 1i64 )
      {
        v11 = &v28;
        do
        {
          v12 = UFG::qMalloc(0x78ui64, "ModelBindingRigid", 0i64);
          if ( v12 )
          {
            UFG::qResourceHandle::qResourceHandle(&v24);
            v13 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v14 = UFG::qResourceWarehouse::Instance();
              v13 = UFG::qResourceWarehouse::GetInventory(v14, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v13;
            }
            UFG::qResourceHandle::Init(&v24, 0xA2ADCD77, *((_DWORD *)v11 - 1), v13);
            v25 = 0i64;
            v2 |= 1u;
            v12->mNext = v12;
            v12[1].mNext = v12;
            UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v12[3]);
            mNameUID = v24.mNameUID;
            v16 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v17 = UFG::qResourceWarehouse::Instance();
              v16 = UFG::qResourceWarehouse::GetInventory(v17, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v16;
            }
            UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12[3], 0xA2ADCD77, mNameUID, v16);
            v12[7].mNext = v25;
            UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v12[9]);
            LODWORD(v12[14].mNext) = 0x10000;
            v12[13].mNext = 0i64;
          }
          else
          {
            v12 = 0i64;
          }
          if ( (v2 & 1) != 0 )
          {
            v2 &= ~1u;
            v18 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v19 = UFG::qResourceWarehouse::Instance();
              v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v18;
            }
            UFG::qResourceHandle::Close(&v24, v18);
            UFG::qResourceHandle::~qResourceHandle(&v24);
          }
          LOWORD(v12[14].mNext) = *(_WORD *)v11;
          HIDWORD(v12[13].mNext) = 0;
          ModelType::UpdateAABB(this, (Illusion::ModelProxy *)&v12[3]);
          v20 = this->mModelBindingRigidTable.mNode.mPrev;
          v20->mNext = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)v12;
          v12->mNext = (UFG::allocator::free_link *)v20;
          v12[1].mNext = (UFG::allocator::free_link *)&this->mModelBindingRigidTable;
          this->mModelBindingRigidTable.mNode.mPrev = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)v12;
          v11 += 16;
          --v6;
        }
        while ( v6 );
      }
    }
  }
}

// File Line: 782
// RVA: 0x1BFFF0
void ModelType::TryBindMissingModels(void)
{
  UFG::qResourceWarehouse *v0; // rax
  ModelType *mNext; // rbx
  UFG::qList<ModelType,ModelType,1,0> *v2; // rdi
  UFG::qNode<ModelType,ModelType> *mPrev; // rcx
  UFG::qNode<ModelType,ModelType> *v4; // rax

  if ( (_S6_4 & 1) == 0 )
  {
    _S6_4 |= 1u;
    v0 = UFG::qResourceWarehouse::Instance();
    inventory_0 = UFG::qResourceWarehouse::GetInventory(v0, 0xA2ADCD77);
  }
  mNext = (ModelType *)ModelType::smUnresolvedModels.mNode.mNext;
  if ( (UFG::qList<ModelType,ModelType,1,0> *)ModelType::smUnresolvedModels.mNode.mNext != &ModelType::smUnresolvedModels )
  {
    do
    {
      v2 = (UFG::qList<ModelType,ModelType,1,0> *)mNext->mNext;
      if ( mNext->mLastInventoryQueryTransactionNum != inventory_0->mTransactionNum )
      {
        ModelType::buildModelBindingRigid(mNext);
        ModelType::ProcessQueuedVisibilityCommands(mNext);
        if ( mNext->mLastInventoryQueryTransactionNum == -1 )
        {
          mPrev = mNext->mPrev;
          v4 = mNext->mNext;
          mPrev->mNext = v4;
          v4->mPrev = mPrev;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          mNext->mLastInventoryQueryTransactionNum = -1;
        }
      }
      mNext = (ModelType *)v2;
    }
    while ( v2 != &ModelType::smUnresolvedModels );
  }
}

