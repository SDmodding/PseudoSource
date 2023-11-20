// File Line: 33
// RVA: 0x146AEA0
__int64 dynamic_initializer_for__ModelType::smUnresolvedModels__()
{
  return atexit(dynamic_atexit_destructor_for__ModelType::smUnresolvedModels__);
}

// File Line: 40
// RVA: 0x1BEDC0
void __fastcall ModelType::ModelType(ModelType *this)
{
  ModelType *v1; // rdi
  UFG::RigHandle *v2; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *v3; // [rsp+48h] [rbp+10h]
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *v4; // [rsp+48h] [rbp+10h]
  UFG::qList<VisibilityCommand,VisibilityCommand,1,0> *v5; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->mPrev = (UFG::qNode<ModelType,ModelType> *)&this->mPrev;
  this->mNext = (UFG::qNode<ModelType,ModelType> *)&this->mPrev;
  v2 = &this->mRigHandle;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mRigHandle.mPrev);
  v2->mLoadFunction = 0i64;
  v2->mUnloadFunction = 0i64;
  v2->mUserData = 0i64;
  v2->mUFGSkeleton = 0i64;
  v3 = &v1->mModelBindingSkinTable;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &v1->mModelBindingRigidTable;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &v1->mQueuedVisibilityCommands;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  *(_QWORD *)&v1->mAABBMax.z = -804905914i64;
  v1->mAABBMin.x = 8999999500.0;
  v1->mAABBMin.y = 8999999500.0;
  v1->mAABBMin.z = 8999999500.0;
  v1->mAABBMax.x = -8999999500.0;
  v1->mAABBMax.y = -8999999500.0;
}

// File Line: 55
// RVA: 0x1BF220
void __fastcall ModelType::~ModelType(ModelType *this)
{
  ModelType *v1; // rdi
  UFG::qList<VisibilityCommand,VisibilityCommand,1,0> *v2; // rbx
  UFG::qNode<VisibilityCommand,VisibilityCommand> *v3; // rcx
  UFG::qNode<VisibilityCommand,VisibilityCommand> *v4; // rax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v5; // rcx
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v6; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v7; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qNode<ModelType,ModelType> *v11; // rcx
  UFG::qNode<ModelType,ModelType> *v12; // rax

  v1 = this;
  v2 = &this->mQueuedVisibilityCommands;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mQueuedVisibilityCommands);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0>::DeleteNodes(&v1->mModelBindingRigidTable);
  v5 = v1->mModelBindingRigidTable.mNode.mPrev;
  v6 = v1->mModelBindingRigidTable.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mModelBindingRigidTable.mNode.mPrev = &v1->mModelBindingRigidTable.mNode;
  v1->mModelBindingRigidTable.mNode.mNext = &v1->mModelBindingRigidTable.mNode;
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0>::DeleteNodes(&v1->mModelBindingSkinTable);
  v7 = v1->mModelBindingSkinTable.mNode.mPrev;
  v8 = v1->mModelBindingSkinTable.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mModelBindingSkinTable.mNode.mPrev = &v1->mModelBindingSkinTable.mNode;
  v1->mModelBindingSkinTable.mNode.mNext = &v1->mModelBindingSkinTable.mNode;
  v9 = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = v9;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mRigHandle.mPrev, v9);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mRigHandle.mPrev);
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mPrev = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
}

// File Line: 70
// RVA: 0x1BF120
void __fastcall ModelType::ModelBindingSkin::~ModelBindingSkin(ModelType::ModelBindingSkin *this)
{
  ModelType::ModelBindingSkin *v1; // rbx
  ModelType::SimpleMorphTargets *v2; // rdi
  ModelType::SkinnedDecalLayer *v3; // rdi
  Render::Softbody *v4; // rdi
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v7; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v8; // rax

  v1 = this;
  v2 = this->mMorphTargets;
  if ( v2 )
  {
    `eh vector destructor iterator(v2, 0x20ui64, 2, (void (__fastcall *)(void *))Illusion::ModelHandle::~ModelHandle);
    operator delete[](v2);
  }
  operator delete[](v1->mSkeletonToModelBoneMap);
  v3 = v1->mDecalLayer;
  if ( v3 )
  {
    ModelType::SkinnedDecalLayer::~SkinnedDecalLayer(v1->mDecalLayer);
    operator delete[](v3);
  }
  v4 = v1->mSoftbody;
  if ( v4 )
  {
    Render::Softbody::~Softbody(v1->mSoftbody);
    operator delete[](v4);
    v1->mSoftbody = 0i64;
  }
  v5 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mModelProxy.mModelHandle.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mModelProxy.mModelHandle.mPrev);
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v1->mPrev;
}

// File Line: 83
// RVA: 0x1BFB00
void __fastcall ModelType::ModelBindingSkin::CreateDecalLayer(ModelType::ModelBindingSkin *this, const unsigned int decal_material_uid, const unsigned int decal_task_uid, const unsigned int num_results)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // ebp
  ModelType::ModelBindingSkin *v7; // rbx
  UFG::allocator::free_link *v8; // rax

  v4 = num_results;
  v5 = decal_task_uid;
  v6 = decal_material_uid;
  v7 = this;
  if ( !this->mDecalLayer )
  {
    v8 = UFG::qMalloc(0x48ui64, "SkinnedDecalLayer", 0i64);
    if ( v8 )
      ModelType::SkinnedDecalLayer::SkinnedDecalLayer((ModelType::SkinnedDecalLayer *)v8, v6, v5, v4);
    v7->mDecalLayer = (ModelType::SkinnedDecalLayer *)v8;
  }
}

// File Line: 101
// RVA: 0x1BF050
void __fastcall ModelType::ModelBindingRigid::~ModelBindingRigid(ModelType::ModelBindingRigid *this)
{
  ModelType::ModelBindingRigid *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v7; // rcx
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v8; // rax

  v1 = this;
  v2 = (UFG::qResourceHandle *)&this->mMorphModelHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v5 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mModelProxy.mModelHandle.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mModelProxy.mModelHandle.mPrev);
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v1->mPrev;
}

// File Line: 109
// RVA: 0x1BEE90
void __fastcall ModelType::SimpleMorphTargets::SimpleMorphTargets(ModelType::SimpleMorphTargets *this)
{
  ModelType::SimpleMorphTargets *v1; // rbx

  v1 = this;
  `eh vector constructor iterator(this, 0x20ui64, 2, (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  v1->mNumModelBindings = 0;
}

// File Line: 118
// RVA: 0x1BEEE0
void __fastcall ModelType::SkinnedDecalLayer::SkinnedDecalLayer(ModelType::SkinnedDecalLayer *this, unsigned int decal_material_uid, unsigned int decal_task_uid, unsigned int num_results)
{
  unsigned int v4; // esi
  unsigned int v5; // ebp
  unsigned int v6; // er14
  ModelType::SkinnedDecalLayer *v7; // rbx
  UFG::qResourceHandle *v8; // rdi
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax

  v4 = num_results;
  v5 = decal_task_uid;
  v6 = decal_material_uid;
  v7 = this;
  v8 = (UFG::qResourceHandle *)&this->mDecalMaterialHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mDecalMaterialHandle.mPrev);
  v9 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v9;
  }
  UFG::qResourceHandle::Init(v8, 0xB4C26312, v6, v9);
  *(_QWORD *)&v7->mDecalSeriesCount = 0i64;
  v7->mDecalVertSeries = 0i64;
  v7->mDecalVerts = 0i64;
  v7->mClipQuery = 0i64;
  v7->mDecalTaskUID = v5;
  v7->mMaxResults = v4;
}

// File Line: 131
// RVA: 0x1BF320
void __fastcall ModelType::SkinnedDecalLayer::~SkinnedDecalLayer(ModelType::SkinnedDecalLayer *this)
{
  ModelType::SkinnedDecalLayer *v1; // rbx
  unsigned int *v2; // rcx
  Render::SkinClipInfo::ClipOutputVertex *v3; // rcx
  Render::SkinClipInfo *v4; // rcx
  UFG::qResourceHandle *v5; // rbx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  v1 = this;
  v2 = this->mDecalVertSeries;
  if ( v2 )
  {
    operator delete[](v2);
    v1->mDecalVertSeries = 0i64;
  }
  v3 = v1->mDecalVerts;
  if ( v3 )
  {
    operator delete[](v3);
    v1->mDecalVerts = 0i64;
  }
  v4 = v1->mClipQuery;
  if ( v4 )
  {
    operator delete[](v4);
    v1->mClipQuery = 0i64;
  }
  v5 = (UFG::qResourceHandle *)&v1->mDecalMaterialHandle.mPrev;
  v6 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v6;
  }
  UFG::qResourceHandle::Close(v5, v6);
  UFG::qResourceHandle::~qResourceHandle(v5);
}

// File Line: 150
// RVA: 0x1BF8B0
void __fastcall ModelType::SkinnedDecalLayer::CreateDecal(ModelType::SkinnedDecalLayer *this, UFG::qMatrix44 *decal_world, UFG::qMatrix44 *model_local_world, float radius, Render::DecalSettings *settings, Illusion::ModelProxy *model_proxy)
{
  UFG::qMatrix44 *v6; // r15
  UFG::qMatrix44 *v7; // r12
  ModelType::SkinnedDecalLayer *v8; // rbx
  unsigned __int64 v9; // rax
  Render::SkinClipInfo *v10; // r14
  unsigned int v11; // edi
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rbp
  int v15; // esi
  UFG::allocator::free_link *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  Render::SkinClipInfo *v18; // rax
  Render::SkinClipInfo *v19; // r9
  UFG::qResourceData *v20; // rdx
  int *v21; // rcx
  int *v22; // rax
  Illusion::rModel *v23; // rax
  int v24; // xmm1_4
  int v25; // xmm2_4
  Illusion::rModel *v26; // rax
  int v27; // xmm1_4
  int v28; // xmm2_4
  int v29; // [rsp+48h] [rbp-60h]
  int v30; // [rsp+4Ch] [rbp-5Ch]
  int v31; // [rsp+50h] [rbp-58h]
  int v32; // [rsp+54h] [rbp-54h]
  int v33; // [rsp+58h] [rbp-50h]
  int v34; // [rsp+5Ch] [rbp-4Ch]
  int v35; // [rsp+60h] [rbp-48h]
  int v36; // [rsp+64h] [rbp-44h]

  v6 = model_local_world;
  v7 = decal_world;
  v8 = this;
  if ( !this->mDecalVertSeries )
  {
    v9 = 4i64 * ModelType::SkinnedDecalLayer::mMaxDecals;
    if ( !is_mul_ok(ModelType::SkinnedDecalLayer::mMaxDecals, 4ui64) )
      v9 = -1i64;
    this->mDecalVertSeries = (unsigned int *)UFG::qMalloc(v9, "SkinnedDecalInfos", 0x1000ui64);
  }
  v10 = 0i64;
  if ( !v8->mDecalVerts )
  {
    v11 = ModelType::SkinnedDecalLayer::mMaxDecalVerts + 1;
    v12 = 44i64 * (ModelType::SkinnedDecalLayer::mMaxDecalVerts + 1);
    if ( !is_mul_ok(ModelType::SkinnedDecalLayer::mMaxDecalVerts + 1, 0x2Cui64) )
      v12 = -1i64;
    v13 = UFG::qMalloc(v12, "SkinnedDecalResults", 0x1000ui64);
    v14 = v13;
    if ( v13 )
    {
      v15 = v11 - 1;
      if ( (signed int)(v11 - 1) >= 0 )
      {
        v16 = v13 + 5;
        do
        {
          `vector constructor iterator(v16, 2ui64, 2, (void *(__fastcall *)(void *))UFG::qHalfFloat::qHalfFloat);
          v16 = (UFG::allocator::free_link *)((char *)v16 + 44);
          --v15;
        }
        while ( v15 >= 0 );
      }
    }
    else
    {
      v14 = 0i64;
    }
    v8->mDecalVerts = (Render::SkinClipInfo::ClipOutputVertex *)v14;
  }
  if ( !v8->mClipQuery )
  {
    v17 = UFG::qMalloc(0xF8ui64, "SkinnedDecalQuery", 0x1000ui64);
    if ( v17 )
    {
      Render::SkinClipInfo::SkinClipInfo((Render::SkinClipInfo *)v17, v8->mMaxResults);
      v10 = v18;
    }
    v8->mClipQuery = v10;
  }
  if ( v8->mDecalVertSeries )
  {
    if ( v8->mDecalVerts )
    {
      v19 = v8->mClipQuery;
      if ( v19 )
      {
        v20 = model_proxy->mModelHandle.mData;
        v21 = (int *)&UFG::qVector3::msZero;
        if ( v20 )
        {
          v22 = (int *)&v20[1].mNode.mChild[1];
        }
        else
        {
          v23 = model_proxy->mRModel;
          if ( v23 )
            v22 = (int *)&v23->mAABBMax;
          else
            v22 = (int *)&UFG::qVector3::msZero;
        }
        v24 = v22[1];
        v25 = v22[2];
        v29 = *v22;
        v30 = v24;
        v31 = v25;
        v32 = 1065353216;
        if ( v20 )
        {
          v21 = (int *)&v20[1];
        }
        else
        {
          v26 = model_proxy->mRModel;
          if ( v26 )
            v21 = (int *)&v26->mAABBMin;
        }
        v27 = v21[1];
        v28 = v21[2];
        v33 = *v21;
        v34 = v27;
        v35 = v28;
        v36 = 1065353216;
        Render::SkinClipInfo::SubmitClipQuery(
          v19,
          v7,
          v6,
          radius,
          (UFG::qVector4 *)&v33,
          (UFG::qVector4 *)&v29,
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
  ModelType::SkinnedDecalLayer *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // er8
  unsigned int v4; // ebp
  unsigned int v5; // er8
  unsigned int v6; // edi
  unsigned int v7; // esi
  bool v8; // zf
  __int64 v9; // rcx
  __int64 v10; // r8
  unsigned int v11; // edx
  __int64 v12; // rcx
  unsigned int result_verts_written; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( Render::SkinClipInfo::AllResultsReady(this->mClipQuery) )
  {
    v2 = Render::SkinClipInfo::GetResultVertexCount(v1->mClipQuery);
    v3 = ModelType::SkinnedDecalLayer::mMaxDecalVerts;
    v4 = v2;
    if ( v2 <= ModelType::SkinnedDecalLayer::mMaxDecalVerts )
    {
      while ( 1 )
      {
        v5 = v3 - v1->mDecalVertCount;
        if ( v5 >= v4 && v1->mDecalSeriesCount != ModelType::SkinnedDecalLayer::mMaxDecals )
          break;
        if ( !v1->mDecalSeriesCount )
          break;
        v6 = 0;
        v7 = *v1->mDecalVertSeries;
        v8 = v1->mDecalVertCount == v7;
        v1->mDecalVertCount -= v7;
        if ( !v8 )
        {
          do
          {
            Render::SkinClipInfo::ClipOutputVertex::operator=(&v1->mDecalVerts[v6], &v1->mDecalVerts[v6 + v7]);
            ++v6;
          }
          while ( v6 < v1->mDecalVertCount );
        }
        v8 = v1->mDecalSeriesCount-- == 1;
        v9 = 0i64;
        if ( !v8 )
        {
          do
          {
            v10 = (unsigned int)(v9 + 1);
            v1->mDecalVertSeries[v9] = v1->mDecalVertSeries[v10];
            v9 = (unsigned int)(v9 + 1);
          }
          while ( (unsigned int)v10 < v1->mDecalSeriesCount );
        }
        v3 = ModelType::SkinnedDecalLayer::mMaxDecalVerts;
      }
      Render::SkinClipInfo::ReadQueryResult(
        v1->mClipQuery,
        &v1->mDecalVerts[v1->mDecalVertCount],
        v5,
        &result_verts_written);
      v11 = result_verts_written;
      v12 = v1->mDecalSeriesCount;
      v1->mDecalVertCount += result_verts_written;
      v1->mDecalVertSeries[v12] = v11;
      ++v1->mDecalSeriesCount;
    }
  }
}

// File Line: 208
// RVA: 0x1BFC40
void __fastcall ModelType::SkinnedDecalLayer::Draw(ModelType::SkinnedDecalLayer *this, Render::Skinning *skinning, Render::SkinningParams *params)
{
  Render::SkinClipInfo::ClipOutputVertex *v3; // rax

  if ( this->mDecalVertCount )
  {
    params->mDecalMaterial = (Illusion::Material *)this->mDecalMaterialHandle.mData;
    params->mDecalVertNum = this->mDecalVertCount;
    v3 = this->mDecalVerts;
    params->clip_info = 0i64;
    params->mDecalVerts = v3;
    params->mDecalTaskUID = this->mDecalTaskUID;
    Render::Skinning::DrawSkinnedDecal(skinning, params);
  }
}

// File Line: 230
// RVA: 0x1BFE10
void __fastcall ModelType::RemoveModelBinding(ModelType *this, Illusion::ModelProxy *model_proxy)
{
  ModelType::ModelBindingSkin *v2; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *v3; // rbp
  Illusion::ModelProxy *v4; // rsi
  ModelType *v5; // r14
  Illusion::rModel *v6; // rax
  ModelType::ModelBindingSkin *v7; // rdi
  unsigned int v8; // eax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v9; // rax
  ModelType::ModelBindingRigid *v10; // rbx
  Illusion::rModel *v11; // rax
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *v12; // rdi
  unsigned int v13; // eax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v14; // rax

  v2 = (ModelType::ModelBindingSkin *)this->mModelBindingSkinTable.mNode.mNext;
  v3 = &this->mModelBindingSkinTable;
  v4 = model_proxy;
  v5 = this;
  if ( v2 != (ModelType::ModelBindingSkin *)&this->mModelBindingSkinTable )
  {
    do
    {
      v6 = v2->mModelProxy.mRModel;
      v7 = (ModelType::ModelBindingSkin *)v2->mNext;
      if ( v6 && v6 == v4->mRModel
        || (v8 = v4->mModelHandle.mNameUID) != 0 && v8 == v2->mModelProxy.mModelHandle.mNameUID )
      {
        v9 = v2->mPrev;
        v9->mNext = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v7->mPrev;
        v7->mPrev = v9;
        v2->mPrev = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v2->mPrev;
        ModelType::ModelBindingSkin::~ModelBindingSkin(v2);
        operator delete[](v2);
      }
      v2 = v7;
    }
    while ( v7 != (ModelType::ModelBindingSkin *)v3 );
  }
  v10 = (ModelType::ModelBindingRigid *)v5->mModelBindingRigidTable.mNode.mNext;
  if ( v10 != (ModelType::ModelBindingRigid *)&v5->mModelBindingRigidTable )
  {
    do
    {
      v11 = v10->mModelProxy.mRModel;
      v12 = (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)v10->mNext;
      if ( v11 && v11 == v4->mRModel
        || (v13 = v4->mModelHandle.mNameUID) != 0 && v13 == v10->mModelProxy.mModelHandle.mNameUID )
      {
        v14 = v10->mPrev;
        v14->mNext = &v12->mNode;
        v12->mNode.mPrev = v14;
        v10->mPrev = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v10->mPrev;
        v10->mNext = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v10->mPrev;
        ModelType::ModelBindingRigid::~ModelBindingRigid(v10);
        operator delete[](v10);
      }
      v10 = (ModelType::ModelBindingRigid *)v12;
    }
    while ( v12 != &v5->mModelBindingRigidTable );
  }
}

// File Line: 257
// RVA: 0x1BFDB0
void __fastcall ModelType::RemoveAllSkinModelBindings(ModelType *this)
{
  ModelType::ModelBindingSkin *v1; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *v2; // rdi
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v3; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v4; // rax

  v1 = (ModelType::ModelBindingSkin *)this->mModelBindingSkinTable.mNode.mNext;
  v2 = &this->mModelBindingSkinTable;
  if ( v1 != (ModelType::ModelBindingSkin *)&this->mModelBindingSkinTable )
  {
    do
    {
      v3 = v1->mPrev;
      v4 = v1->mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v1->mPrev = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v1->mPrev;
      v1->mNext = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v1->mPrev;
      ModelType::ModelBindingSkin::~ModelBindingSkin(v1);
      operator delete[](v1);
      v1 = (ModelType::ModelBindingSkin *)v2->mNode.mNext;
    }
    while ( v1 != (ModelType::ModelBindingSkin *)v2 );
  }
}

// File Line: 262
// RVA: 0x1BFF00
void __fastcall ModelType::SetRigidModelVisibilityOnBone(ModelType *this, unsigned int bone_name_uid, bool visible)
{
  bool v3; // di
  unsigned int v4; // esi
  ModelType *v5; // rbx
  UFG::qBaseNodeRB *v6; // rcx
  int v7; // eax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v8; // r9
  signed int v9; // ecx
  UFG::qList<ModelType,ModelType,1,0> *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdx
  UFG::qNode<VisibilityCommand,VisibilityCommand> *v13; // rax

  v3 = visible;
  v4 = bone_name_uid;
  v5 = this;
  v6 = this->mRigHandle.mData[3].mNode.mParent;
  if ( v6 )
  {
    v7 = Skeleton::GetBoneID((Skeleton *)v6, bone_name_uid);
    v8 = v5->mModelBindingRigidTable.mNode.mNext;
    if ( v8 != (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v5->mModelBindingRigidTable )
    {
      while ( LOWORD(v8[7].mPrev) != v7 )
      {
        v8 = v8->mNext;
        if ( v8 == (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v5->mModelBindingRigidTable )
          goto LABEL_7;
      }
      WORD1(v8[7].mPrev) = v3 != 0;
    }
  }
LABEL_7:
  v9 = -1;
  v10 = (UFG::qList<ModelType,ModelType,1,0> *)ModelType::smUnresolvedModels.mNode.mNext;
  if ( (UFG::qList<ModelType,ModelType,1,0> *)ModelType::smUnresolvedModels.mNode.mNext != &ModelType::smUnresolvedModels )
  {
    while ( 1 )
    {
      ++v9;
      if ( v10 == (UFG::qList<ModelType,ModelType,1,0> *)v5 )
        break;
      v10 = (UFG::qList<ModelType,ModelType,1,0> *)v10->mNode.mNext;
      if ( v10 == &ModelType::smUnresolvedModels )
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
      LODWORD(v12[2].mNext) = v4;
      BYTE4(v12[2].mNext) = v3;
      v13 = v5->mQueuedVisibilityCommands.mNode.mPrev;
      v13->mNext = (UFG::qNode<VisibilityCommand,VisibilityCommand> *)v12;
      v12->mNext = (UFG::allocator::free_link *)v13;
      v12[1].mNext = (UFG::allocator::free_link *)&v5->mQueuedVisibilityCommands;
      v5->mQueuedVisibilityCommands.mNode.mPrev = (UFG::qNode<VisibilityCommand,VisibilityCommand> *)v12;
    }
  }
}

// File Line: 293
// RVA: 0x1BFD10
void __fastcall ModelType::ProcessQueuedVisibilityCommands(ModelType *this)
{
  UFG::qNode<VisibilityCommand,VisibilityCommand> *v1; // rbx
  UFG::qList<VisibilityCommand,VisibilityCommand,1,0> *v2; // rbp
  ModelType *v3; // rdi
  char v4; // si
  Skeleton *v5; // rcx
  int v6; // eax
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v7; // rcx

  v1 = this->mQueuedVisibilityCommands.mNode.mNext;
  v2 = &this->mQueuedVisibilityCommands;
  v3 = this;
  if ( v1 != (UFG::qNode<VisibilityCommand,VisibilityCommand> *)&this->mQueuedVisibilityCommands )
  {
    do
    {
      v4 = BYTE4(v1[1].mPrev);
      v5 = (Skeleton *)v3->mRigHandle.mData[3].mNode.mParent;
      if ( v5 )
      {
        v6 = Skeleton::GetBoneID(v5, (const unsigned int)v1[1].mPrev);
        v7 = v3->mModelBindingRigidTable.mNode.mNext;
        if ( v7 != (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v3->mModelBindingRigidTable )
        {
          while ( LOWORD(v7[7].mPrev) != v6 )
          {
            v7 = v7->mNext;
            if ( v7 == (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v3->mModelBindingRigidTable )
              goto LABEL_8;
          }
          WORD1(v7[7].mPrev) = v4 != 0;
        }
      }
LABEL_8:
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<VisibilityCommand,VisibilityCommand> *)v2 );
  }
}

// File Line: 303
// RVA: 0x1BF700
ModelType::ModelBindingSkin *__fastcall ModelType::AddSkinModelBinding(ModelType *this, Illusion::ModelProxy *model_proxy, UFG::qMatrix44 *mat, unsigned int model_index, unsigned int lod)
{
  unsigned int v5; // er12
  Illusion::ModelProxy *v6; // rdi
  ModelType *v7; // rbp
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v8; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v9; // r14
  Illusion::rModel *v10; // r8
  unsigned int v11; // ecx
  UFG::allocator::free_link *v13; // rax
  ModelType::ModelBindingSkin *v14; // rbx
  UFG::qResourceHandle *v15; // rsi
  unsigned int v16; // er15
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v19; // rax
  unsigned int v20; // eax
  unsigned int task_uid; // [rsp+20h] [rbp-58h]
  __int64 v22; // [rsp+28h] [rbp-50h]
  UFG::allocator::free_link *v23; // [rsp+30h] [rbp-48h]
  UFG::allocator::free_link *v24; // [rsp+38h] [rbp-40h]
  UFG::allocator::free_link *v25; // [rsp+40h] [rbp-38h]
  unsigned int mesh_count; // [rsp+80h] [rbp+8h]

  v22 = -2i64;
  v5 = model_index;
  v6 = model_proxy;
  v7 = this;
  v8 = this->mModelBindingSkinTable.mNode.mNext;
  v9 = &this->mModelBindingSkinTable.mNode;
  while ( v8 != v9 )
  {
    v10 = (Illusion::rModel *)v8[4].mNext;
    if ( v10 && v10 == model_proxy->mRModel )
      return 0i64;
    v11 = model_proxy->mModelHandle.mNameUID;
    if ( v11 )
    {
      if ( v11 == LODWORD(v8[4].mPrev) )
        return 0i64;
    }
    v8 = v8->mNext;
  }
  ModelType::UpdateAABB(v7, model_proxy);
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
    v16 = v6->mModelHandle.mNameUID;
    v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v18 = UFG::qResourceWarehouse::Instance();
      v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
    }
    UFG::qResourceHandle::Init(v15, 0xA2ADCD77, v16, v17);
    v15[1].mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v6->mRModel;
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
  v19 = v9->mPrev;
  v19->mNext = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v14->mPrev;
  v14->mPrev = v19;
  v14->mNext = v9;
  v9->mPrev = (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)&v14->mPrev;
  v14->mNumMappedBones = 0;
  v14->mModelIndex = v5;
  ModelType::buildSkeletonToModelBoneMap(v7, v14);
  task_uid = 0;
  mesh_count = 0;
  if ( !lod
    && Render::Skinning::SupportsSkinnedDecals(&Render::Skinning::gSkinning, v6, &task_uid, &mesh_count)
    && task_uid
    && mesh_count )
  {
    v20 = Render::DecalManager::GetSkinnedDecalMaterialUID(&Render::gDecalManager);
    ModelType::ModelBindingSkin::CreateDecalLayer(v14, v20, task_uid, mesh_count);
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
  ModelType::ModelBindingSkin *v2; // rsi
  ModelType *v3; // r13
  UFG::qResourceData *v4; // rdi
  UFG::qResourceData *v5; // rdi
  Illusion::rModel *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  unsigned int v8; // er12
  unsigned int v9; // er15
  unsigned int v10; // ecx
  unsigned int v11; // ebp
  unsigned int v12; // edx
  UFG::qBaseNodeRB *v13; // rax
  unsigned int v14; // edx
  char v15; // al
  UFG::qResourceData *v16; // rbx
  UFG::qWiseSymbol *v17; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]

  v2 = model_binding;
  v3 = this;
  ModelType::UpdateAABB(this, &model_binding->mModelProxy);
  v4 = v2->mModelProxy.mModelHandle.mData;
  if ( v4 )
  {
    v5 = *(UFG::qResourceData **)&v4[1].mDebugName[28];
  }
  else
  {
    v6 = v2->mModelProxy.mRModel;
    if ( !v6 )
      return;
    v5 = v6->mBonePaletteHandle.mData;
  }
  if ( !v2->mSkeletonToModelBoneMap )
  {
    if ( v5 )
    {
      v7 = UFG::qMalloc((unsigned int)(160 * LODWORD(v5[1].mNode.mParent)), "SkeletonToModelBoneMap", 0i64);
      v2->mSkeletonToModelBoneMap = (char *)v7;
      UFG::qMemSet(v7, 255, 160 * LODWORD(v5[1].mNode.mParent));
      v8 = 0;
      if ( LODWORD(v5[1].mNode.mParent) )
      {
        v9 = 0;
        do
        {
          v10 = HIDWORD(v5[1].mNode.mParent);
          v11 = 0;
          if ( v10 )
          {
            do
            {
              v12 = *((unsigned __int8 *)&v5[1].mResourceHandles.mNode.mNext + v9 + (unsigned __int64)v11);
              if ( v12 >= v10 )
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
              v15 = -1;
              if ( v14 != -1 )
              {
                v16 = v3->mRigHandle.mData;
                v17 = UFG::qSymbol::qSymbol(&result, v14);
                v15 = Skeleton::GetBoneID((Skeleton *)v16[3].mNode.mParent, v17->mUID);
              }
              ++v11;
              v2->mSkeletonToModelBoneMap[v2->mNumMappedBones++] = v15;
              v10 = HIDWORD(v5[1].mNode.mParent);
            }
            while ( v11 < v10 );
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
  hkaPose *v2; // rbp
  SkeletalPose *v3; // rsi
  ModelType *v4; // r15
  ModelType::ModelBindingSkin *v5; // rbx
  float v6; // xmm6_4
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *v7; // r13
  char v8; // r12
  float v9; // xmm10_4
  float v10; // xmm9_4
  float v11; // xmm11_4
  float v12; // xmm8_4
  float v13; // xmm7_4
  ModelType::ModelBindingSkin *v14; // r14
  UFG::qResourceData *v15; // rax
  float *v16; // rdi
  float *v17; // rbx
  hkQsTransformf *v18; // rax
  ModelType::ModelBindingRigid *v19; // rbx
  __m128 v20; // xmm12
  __m128 v21; // xmm13
  ModelType::ModelBindingRigid *v22; // rsi
  __int64 v23; // rdx
  hkQsTransformf *v24; // rdi
  UFG::qResourceData *v25; // rax
  UFG::qVector3 *v26; // rcx
  UFG::qVector3 *v27; // rax
  __m128 v28; // [rsp+20h] [rbp-118h]
  __m128 v29; // [rsp+30h] [rbp-108h]
  hkVector4f b; // [rsp+40h] [rbp-F8h]
  hkVector4f v31; // [rsp+50h] [rbp-E8h]
  hkVector4f v32; // [rsp+60h] [rbp-D8h]
  hkVector4f v33; // [rsp+70h] [rbp-C8h]

  v2 = pose->mHavokPose;
  v3 = pose;
  v4 = this;
  if ( v2 )
  {
    v5 = (ModelType::ModelBindingSkin *)this->mModelBindingSkinTable.mNode.mNext;
    v6 = FLOAT_N3_4028235e38;
    v7 = &this->mModelBindingSkinTable;
    v8 = 0;
    v9 = FLOAT_3_4028235e38;
    v10 = FLOAT_3_4028235e38;
    v11 = FLOAT_3_4028235e38;
    v12 = FLOAT_N3_4028235e38;
    v13 = FLOAT_N3_4028235e38;
    if ( v5 != (ModelType::ModelBindingSkin *)&this->mModelBindingSkinTable )
    {
      do
      {
        v14 = (ModelType::ModelBindingSkin *)v5->mNext;
        if ( v5->mModelProxy.mModelHandle.mData || v5->mModelProxy.mRModel )
        {
          if ( v5->mSkeletonToModelBoneMap
            || (ModelType::buildSkeletonToModelBoneMap(v4, v5), v5->mSkeletonToModelBoneMap) )
          {
            v8 = 1;
            if ( v5->mNumMappedBones <= 1 )
            {
              v15 = v5->mModelProxy.mModelHandle.mData;
              if ( v15 )
                v16 = (float *)&v15[1];
              else
                v16 = &v5->mModelProxy.mRModel->mAABBMin.x;
              if ( v15 )
                v17 = (float *)&v15[1].mNode.mChild[1];
              else
                v17 = &v5->mModelProxy.mRModel->mAABBMax.x;
              if ( *(_BYTE *)v2->m_boneFlags.m_data & 2 )
                v18 = hkaPose::calculateBoneModelSpace(v2, 0);
              else
                v18 = v2->m_modelPose.m_data;
              if ( v9 >= (float)(v18->m_translation.m_quad.m128_f32[0] + *v16) )
                v9 = v18->m_translation.m_quad.m128_f32[0] + *v16;
              if ( v11 >= (float)(v18->m_translation.m_quad.m128_f32[1] + v16[1]) )
                v11 = v18->m_translation.m_quad.m128_f32[1] + v16[1];
              if ( v10 >= (float)(v18->m_translation.m_quad.m128_f32[2] + v16[2]) )
                v10 = v18->m_translation.m_quad.m128_f32[2] + v16[2];
              if ( v6 <= (float)(v18->m_translation.m_quad.m128_f32[0] + *v17) )
                v6 = v18->m_translation.m_quad.m128_f32[0] + *v17;
              if ( v12 <= (float)(v18->m_translation.m_quad.m128_f32[1] + v17[1]) )
                v12 = v18->m_translation.m_quad.m128_f32[1] + v17[1];
              if ( v13 <= (float)(v18->m_translation.m_quad.m128_f32[2] + v17[2]) )
                v13 = v18->m_translation.m_quad.m128_f32[2] + v17[2];
            }
            else
            {
              if ( v9 >= v3->mPoseAABBMin.x )
                v9 = v3->mPoseAABBMin.x;
              if ( v11 >= v3->mPoseAABBMin.y )
                v11 = v3->mPoseAABBMin.y;
              if ( v10 >= v3->mPoseAABBMin.z )
                v10 = v3->mPoseAABBMin.z;
              if ( v6 <= v3->mPoseAABBMax.x )
                v6 = v3->mPoseAABBMax.x;
              if ( v12 <= v3->mPoseAABBMax.y )
                v12 = v3->mPoseAABBMax.y;
              if ( v13 <= v3->mPoseAABBMax.z )
                v13 = v3->mPoseAABBMax.z;
            }
          }
        }
        v5 = v14;
      }
      while ( v14 != (ModelType::ModelBindingSkin *)v7 );
    }
    v19 = (ModelType::ModelBindingRigid *)v4->mModelBindingRigidTable.mNode.mNext;
    v20 = aabb_min_start.m_quad;
    v21 = aabb_max_start.m_quad;
    v28 = aabb_min_start.m_quad;
    v29 = aabb_max_start.m_quad;
    if ( v19 != (ModelType::ModelBindingRigid *)&v4->mModelBindingRigidTable )
    {
      do
      {
        v22 = (ModelType::ModelBindingRigid *)v19->mNext;
        if ( (v19->mModelProxy.mModelHandle.mData || v19->mModelProxy.mRModel) && v19->mVisible )
        {
          v23 = v19->mBoneID;
          if ( v2->m_boneFlags.m_data[v23] & 2 )
            v24 = hkaPose::calculateBoneModelSpace(v2, v23);
          else
            v24 = &v2->m_modelPose.m_data[v23];
          v25 = v19->mModelProxy.mModelHandle.mData;
          v8 = 1;
          if ( v25 )
            v26 = (UFG::qVector3 *)&v25[1];
          else
            v26 = &v19->mModelProxy.mRModel->mAABBMin;
          if ( v25 )
            v27 = (UFG::qVector3 *)&v25[1].mNode.mChild[1];
          else
            v27 = &v19->mModelProxy.mRModel->mAABBMax;
          b.m_quad = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(v26->x), (__m128)LODWORD(v26->z)),
                       _mm_unpacklo_ps((__m128)LODWORD(v26->y), (__m128)(unsigned int)FLOAT_1_0));
          v31.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps((__m128)LODWORD(v27->x), (__m128)LODWORD(v27->z)),
                         _mm_unpacklo_ps((__m128)LODWORD(v27->y), (__m128)(unsigned int)FLOAT_1_0));
          hkVector4f::setTransformedPos(&v32, v24, &b);
          hkVector4f::setTransformedPos(&v33, v24, &v31);
          v20 = _mm_min_ps(_mm_min_ps(v20, v32.m_quad), v33.m_quad);
          v21 = _mm_max_ps(_mm_max_ps(v21, v32.m_quad), v33.m_quad);
          v28 = v20;
          v29 = v21;
        }
        v19 = v22;
      }
      while ( v22 != (ModelType::ModelBindingRigid *)&v4->mModelBindingRigidTable );
    }
    if ( v8 )
    {
      if ( v10 >= v28.m128_f32[2] )
        v10 = v28.m128_f32[2];
      if ( v11 >= v28.m128_f32[1] )
        v11 = v28.m128_f32[1];
      if ( v9 >= v28.m128_f32[0] )
        v9 = v28.m128_f32[0];
      v4->mAABBMin.x = v9;
      v4->mAABBMin.y = v11;
      v4->mAABBMin.z = v10;
      if ( v13 <= v29.m128_f32[2] )
        v13 = v29.m128_f32[2];
      if ( v12 <= v29.m128_f32[1] )
        v12 = v29.m128_f32[1];
      if ( v6 <= v29.m128_f32[0] )
        v6 = v29.m128_f32[0];
      v4->mAABBMax.x = v6;
      v4->mAABBMax.y = v12;
      v4->mAABBMax.z = v13;
    }
  }
}

// File Line: 612
// RVA: 0x1BF470
void __fastcall ModelType::AddModelBinding(ModelType *this, Illusion::ModelProxy *model_proxy, UFG::qMatrix44 *mat, unsigned int model_index, unsigned int lod)
{
  unsigned int v5; // esi
  UFG::qMatrix44 *v6; // rbp
  Illusion::ModelProxy *v7; // rbx
  ModelType *v8; // rdi
  Illusion::rModel *v9; // rax
  const char *v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // er14
  unsigned int v14; // ebx
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceHandle v19; // [rsp+38h] [rbp-40h]
  __int64 v20; // [rsp+58h] [rbp-20h]

  v5 = model_index;
  v6 = mat;
  v7 = model_proxy;
  v8 = this;
  v9 = model_proxy->mRModel;
  if ( v9 )
  {
    if ( v9->mBonePaletteHandle.mData )
    {
      ModelType::AddSkinModelBinding(this, model_proxy, mat, model_index, lod);
    }
    else
    {
      if ( v9->mModelName.mText.mData.mNumItems )
        v10 = v9->mModelName.mText.mData.mItems;
      else
        v10 = &customWorldMapCaption;
      v11 = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
      v12 = Skeleton::GetBoneID((Skeleton *)v8->mRigHandle.mData[3].mNode.mParent, v11);
      if ( v12 != -1 )
        ModelType::AddRigidModelBinding(v8, v7, v12, v6, v5);
    }
  }
  else
  {
    v13 = Skeleton::GetBoneID((Skeleton *)this->mRigHandle.mData[3].mNode.mParent, model_proxy->mModelHandle.mNameUID);
    v14 = v7->mModelHandle.mNameUID;
    UFG::qResourceHandle::qResourceHandle(&v19);
    v15 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v16 = UFG::qResourceWarehouse::Instance();
      v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v15;
    }
    UFG::qResourceHandle::Init(&v19, 0xA2ADCD77, v14, v15);
    v20 = 0i64;
    ModelType::AddRigidModelBinding(v8, (Illusion::ModelProxy *)&v19, v13, v6, v5);
    v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v18 = UFG::qResourceWarehouse::Instance();
      v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
    }
    UFG::qResourceHandle::Close(&v19, v17);
    UFG::qResourceHandle::~qResourceHandle(&v19);
  }
}

// File Line: 643
// RVA: 0x1BFC90
ModelType::ModelBindingRigid *__fastcall ModelType::FindRigidModelBinding(ModelType *this, unsigned int model_name_uid, unsigned int bone_name_uid, unsigned int model_index)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  ModelType::ModelBindingRigid *v6; // rbx
  int v7; // edx
  ModelType::ModelBindingRigid *result; // rax

  v4 = model_name_uid;
  v5 = model_index;
  v6 = (ModelType::ModelBindingRigid *)&this->mModelBindingRigidTable;
  v7 = Skeleton::GetBoneID((Skeleton *)this->mRigHandle.mData[3].mNode.mParent, bone_name_uid);
  result = (ModelType::ModelBindingRigid *)v6->mNext;
  if ( result == v6 )
    return 0i64;
  while ( result->mModelUID != v4 || result->mBoneID != v7 || result->mModelIndex != v5 )
  {
    result = (ModelType::ModelBindingRigid *)result->mNext;
    if ( result == v6 )
      return 0i64;
  }
  return result;
}

// File Line: 659
// RVA: 0x1BF600
ModelType::ModelBindingRigid *__fastcall ModelType::AddRigidModelBinding(ModelType *this, Illusion::ModelProxy *model_proxy, unsigned int bone_index, UFG::qMatrix44 *mat, unsigned int model_index)
{
  unsigned int v5; // er14
  Illusion::ModelProxy *v6; // rdi
  ModelType *v7; // r8
  ModelType::ModelBindingRigid *v8; // rax
  ModelType::ModelBindingRigid *v9; // rsi
  Illusion::rModel *v10; // rdx
  unsigned int v11; // ecx
  ModelType::ModelBindingRigid *v13; // rax
  ModelType::ModelBindingRigid *v14; // rbx
  UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *v15; // rcx

  v5 = bone_index;
  v6 = model_proxy;
  v7 = this;
  v8 = (ModelType::ModelBindingRigid *)this->mModelBindingRigidTable.mNode.mNext;
  v9 = (ModelType::ModelBindingRigid *)&this->mModelBindingRigidTable;
  while ( v8 != v9 )
  {
    v10 = v8->mModelProxy.mRModel;
    if ( v10 && v10 == v6->mRModel
      || (v11 = v6->mModelHandle.mNameUID) != 0 && v11 == v8->mModelProxy.mModelHandle.mNameUID )
    {
      if ( v8->mBoneID == v5 && v8->mModelIndex == model_index )
        return 0i64;
    }
    v8 = (ModelType::ModelBindingRigid *)v8->mNext;
  }
  ModelType::UpdateAABB(v7, v6);
  v13 = (ModelType::ModelBindingRigid *)UFG::qMalloc(0x78ui64, "ModelBindingRigid", 0i64);
  v14 = v13;
  if ( v13 )
  {
    v13->mPrev = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v13->mPrev;
    v13->mNext = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v13->mPrev;
    Illusion::ModelProxy::ModelProxy(&v13->mModelProxy, v6);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v14->mMorphModelHandle.mPrev);
    *(_DWORD *)&v14->mBoneID = 65536;
    *(_QWORD *)&v14->mNumMappedBones = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  v14->mBoneID = v5;
  v14->mModelIndex = model_index;
  v15 = v9->mPrev;
  v15->mNext = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v14->mPrev;
  v14->mPrev = v15;
  v14->mNext = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v9->mPrev;
  v9->mPrev = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)&v14->mPrev;
  return v14;
}

// File Line: 700
// RVA: 0x1C00C0
void __fastcall ModelType::UpdateAABB(ModelType *this, Illusion::ModelProxy *model_proxy)
{
  float *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Illusion::rModel *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4

  v2 = (float *)model_proxy->mModelHandle.mData;
  if ( v2 )
  {
    v3 = this->mAABBMin.x;
    if ( v3 >= v2[22] )
      v3 = v2[22];
    this->mAABBMin.x = v3;
    v4 = this->mAABBMin.y;
    if ( v4 >= v2[23] )
      v4 = v2[23];
    this->mAABBMin.y = v4;
    v5 = this->mAABBMin.z;
    if ( v5 >= v2[24] )
      v5 = v2[24];
    this->mAABBMin.z = v5;
    v6 = this->mAABBMax.x;
    if ( v6 <= v2[26] )
      v6 = v2[26];
    this->mAABBMax.x = v6;
    v7 = this->mAABBMax.y;
    if ( v7 <= v2[27] )
      v7 = v2[27];
    this->mAABBMax.y = v7;
    v8 = v2[28];
  }
  else
  {
    v9 = model_proxy->mRModel;
    if ( !v9 )
      return;
    v10 = this->mAABBMin.x;
    if ( v10 >= v9->mAABBMin.x )
      v10 = v9->mAABBMin.x;
    this->mAABBMin.x = v10;
    v11 = this->mAABBMin.y;
    if ( v11 >= v9->mAABBMin.y )
      v11 = v9->mAABBMin.y;
    this->mAABBMin.y = v11;
    v12 = this->mAABBMin.z;
    if ( v12 >= v9->mAABBMin.z )
      v12 = v9->mAABBMin.z;
    this->mAABBMin.z = v12;
    v13 = this->mAABBMax.x;
    if ( v13 <= v9->mAABBMax.x )
      v13 = v9->mAABBMax.x;
    this->mAABBMax.x = v13;
    v14 = this->mAABBMax.y;
    if ( v14 <= v9->mAABBMax.y )
      v14 = v9->mAABBMax.y;
    this->mAABBMax.y = v14;
    v8 = v9->mAABBMax.z;
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
  ModelType *v1; // rsi
  int v2; // edi
  UFG::qResourceData *v3; // r14
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rcx
  __int64 v6; // r15
  __int64 v7; // rbp
  char *v8; // rbx
  int v9; // er13
  __int64 v10; // rax
  char *v11; // r14
  UFG::allocator::free_link *v12; // rbx
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  unsigned int v15; // er12
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::qNode<ModelType,ModelType> *v21; // rcx
  UFG::qNode<ModelType,ModelType> *v22; // rax
  UFG::qNode<ModelType,ModelType> *v23; // rax
  UFG::qResourceHandle v24; // [rsp+28h] [rbp-1060h]
  UFG::allocator::free_link *v25; // [rsp+48h] [rbp-1040h]
  __int64 v26; // [rsp+50h] [rbp-1038h]
  char v27; // [rsp+68h] [rbp-1020h]
  char v28; // [rsp+6Ch] [rbp-101Ch]
  UFG::allocator::free_link *v29; // [rsp+1090h] [rbp+8h]
  UFG::qResourceHandle *v30; // [rsp+1090h] [rbp+8h]
  UFG::qResourceHandle *v31; // [rsp+1098h] [rbp+10h]
  signed __int64 v32; // [rsp+1098h] [rbp+10h]
  signed __int64 v33; // [rsp+1098h] [rbp+10h]
  signed __int64 v34; // [rsp+10A0h] [rbp+18h]

  v26 = -2i64;
  v1 = this;
  v2 = 0;
  if ( (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)this->mModelBindingRigidTable.mNode.mNext == &this->mModelBindingRigidTable )
  {
    v3 = this->mRigHandle.mData;
    if ( _S5_4 & 1 )
    {
      v5 = inventory;
    }
    else
    {
      _S5_4 |= 1u;
      v4 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
      inventory = v5;
    }
    LODWORD(v6) = 0;
    v1->mLastInventoryQueryTransactionNum = -1;
    v7 = 0i64;
    if ( LODWORD(v3[1].mResourceHandles.mNode.mNext) )
    {
      v8 = &v27;
      while ( 1 )
      {
        v9 = *(_DWORD *)(8 * v7 + *(_QWORD *)&v3[1].mTypeUID + 4);
        v10 = (__int64)v5->vfptr->Get(v5, *(_DWORD *)(8 * v7 + *(_QWORD *)&v3[1].mTypeUID + 4));
        if ( !v10 )
        {
          v1->mLastInventoryQueryTransactionNum = inventory->mTransactionNum;
          v21 = v1->mPrev;
          v22 = v1->mNext;
          v21->mNext = v22;
          v22->mPrev = v21;
          v1->mPrev = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
          v1->mNext = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
          v23 = ModelType::smUnresolvedModels.mNode.mPrev;
          ModelType::smUnresolvedModels.mNode.mPrev->mNext = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
          v1->mPrev = v23;
          v1->mNext = (UFG::qNode<ModelType,ModelType> *)&ModelType::smUnresolvedModels;
          ModelType::smUnresolvedModels.mNode.mPrev = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
          return;
        }
        *((_DWORD *)v8 + 1) = *(_DWORD *)(8 * v7 + *(_QWORD *)&v3[1].mTypeUID);
        *(_DWORD *)v8 = v9;
        *((_QWORD *)v8 - 1) = v10;
        LODWORD(v6) = v6 + 1;
        v8 += 16;
        v7 = (unsigned int)(v7 + 1);
        if ( (unsigned int)v7 >= LODWORD(v3[1].mResourceHandles.mNode.mNext) )
          break;
        v5 = inventory;
      }
      v6 = (signed int)v6;
      if ( (signed int)v6 >= 1i64 )
      {
        v11 = &v28;
        do
        {
          v12 = UFG::qMalloc(0x78ui64, "ModelBindingRigid", 0i64);
          v29 = v12;
          if ( v12 )
          {
            v31 = &v24;
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
            v32 = (signed __int64)&v12[3];
            v34 = (signed __int64)&v12[3];
            UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v12[3]);
            v15 = v24.mNameUID;
            v16 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v17 = UFG::qResourceWarehouse::Instance();
              v16 = UFG::qResourceWarehouse::GetInventory(v17, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v16;
            }
            UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12[3], 0xA2ADCD77, v15, v16);
            v12[7].mNext = v25;
            v33 = (signed __int64)&v12[9];
            UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v12[9]);
            LODWORD(v12[14].mNext) = 0x10000;
            v12[13].mNext = 0i64;
          }
          else
          {
            v12 = 0i64;
          }
          if ( v2 & 1 )
          {
            v2 &= 0xFFFFFFFE;
            v30 = &v24;
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
          ModelType::UpdateAABB(v1, (Illusion::ModelProxy *)&v12[3]);
          v20 = (UFG::allocator::free_link *)v1->mModelBindingRigidTable.mNode.mPrev;
          v20[1].mNext = v12;
          v12->mNext = v20;
          v12[1].mNext = (UFG::allocator::free_link *)&v1->mModelBindingRigidTable;
          v1->mModelBindingRigidTable.mNode.mPrev = (UFG::qNode<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid> *)v12;
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
  ModelType *v1; // rbx
  UFG::qList<ModelType,ModelType,1,0> *v2; // rdi
  UFG::qNode<ModelType,ModelType> *v3; // rcx
  UFG::qNode<ModelType,ModelType> *v4; // rax

  if ( !(_S6_4 & 1) )
  {
    _S6_4 |= 1u;
    v0 = UFG::qResourceWarehouse::Instance();
    inventory_0 = UFG::qResourceWarehouse::GetInventory(v0, 0xA2ADCD77);
  }
  v1 = (ModelType *)ModelType::smUnresolvedModels.mNode.mNext;
  if ( (UFG::qList<ModelType,ModelType,1,0> *)ModelType::smUnresolvedModels.mNode.mNext != &ModelType::smUnresolvedModels )
  {
    do
    {
      v2 = (UFG::qList<ModelType,ModelType,1,0> *)v1->mNext;
      if ( v1->mLastInventoryQueryTransactionNum != inventory_0->mTransactionNum )
      {
        ModelType::buildModelBindingRigid(v1);
        ModelType::ProcessQueuedVisibilityCommands(v1);
        if ( v1->mLastInventoryQueryTransactionNum == -1 )
        {
          v3 = v1->mPrev;
          v4 = v1->mNext;
          v3->mNext = v4;
          v4->mPrev = v3;
          v1->mPrev = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
          v1->mNext = (UFG::qNode<ModelType,ModelType> *)&v1->mPrev;
          v1->mLastInventoryQueryTransactionNum = -1;
        }
      }
      v1 = (ModelType *)v2;
    }
    while ( v2 != &ModelType::smUnresolvedModels );
  }
}

