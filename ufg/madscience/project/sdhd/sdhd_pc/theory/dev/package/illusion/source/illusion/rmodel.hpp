// File Line: 92
// RVA: 0x1BED30
void __fastcall Illusion::ModelProxy::ModelProxy(Illusion::ModelProxy *this, Illusion::ModelProxy *value)
{
  Illusion::ModelProxy *v2; // rdi
  Illusion::ModelProxy *v3; // rbx
  unsigned int v4; // esi
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax

  v2 = value;
  v3 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mModelHandle.mPrev);
  v4 = v2->mModelHandle.mNameUID;
  v5 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mModelHandle.mPrev, 0xA2ADCD77, v4, v5);
  v3->mRModel = v2->mRModel;
}

// File Line: 95
// RVA: 0x1C19E0
void __fastcall Illusion::ModelProxy::ModelProxy(Illusion::ModelProxy *this)
{
  Illusion::ModelProxy *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mModelHandle.mPrev);
  v2 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mModelHandle.mPrev, 0xA2ADCD77, 0, v2);
  v1->mRModel = 0i64;
}

// File Line: 98
// RVA: 0x3C70
void __fastcall Illusion::ModelProxy::Init(Illusion::ModelProxy *this, unsigned int model_uid)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // edi
  Illusion::ModelProxy *v4; // rbx
  UFG::qResourceWarehouse *v5; // rax

  v2 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  v3 = model_uid;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mModelHandle.mPrev, 0xA2ADCD77, v3, v2);
  v4->mRModel = 0i64;
}

// File Line: 106
// RVA: 0x1DFD0
Illusion::rModel *__fastcall Illusion::ModelProxy::GetNumMeshes(Illusion::ModelProxy *this)
{
  Illusion::Model *v1; // rax
  Illusion::rModel *result; // rax

  v1 = (Illusion::Model *)this->mModelHandle.mData;
  if ( v1 )
    return (Illusion::rModel *)v1->mNumMeshes;
  result = this->mRModel;
  if ( result )
    result = (Illusion::rModel *)result->mMeshes.mData.mNumItems;
  return result;
}

// File Line: 110
// RVA: 0x2940
Illusion::ModelProxy *__fastcall Illusion::ModelProxy::operator=(Illusion::ModelProxy *this, Illusion::ModelProxy *rhs)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // esi
  Illusion::ModelProxy *v4; // rdi
  Illusion::ModelProxy *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax

  v2 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  v3 = rhs->mModelHandle.mNameUID;
  v4 = rhs;
  v5 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mModelHandle.mPrev, 0xA2ADCD77, v3, v2);
  v5->mRModel = v4->mRModel;
  return v5;
}

// File Line: 166
// RVA: 0x21FCB0
void __fastcall Illusion::rMesh::~rMesh(Illusion::rMesh *this)
{
  Illusion::rMesh *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceHandle *v6; // rdi
  signed __int64 v7; // rsi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax

  v1 = this;
  v2 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev, v2);
  v4 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mIndexBufferHandle.mPrev, v4);
  v6 = (UFG::qResourceHandle *)v1->mVertexBufferHandles;
  v7 = 4i64;
  do
  {
    v8 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x92CDEC8F);
      `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v8;
    }
    UFG::qResourceHandle::Close(v6, v8);
    ++v6;
    --v7;
  }
  while ( v7 );
  `eh vector destructor iterator'(
    v1->mVertexBufferHandles,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::BufferHandle::~BufferHandle);
  v10 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v10;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mIndexBufferHandle.mPrev, v10);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mIndexBufferHandle.mPrev);
  v12 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v12;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev, v12);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mMaterial.mPrev);
  if ( !(v1->mMaterialName.mText.mData.mFlags & 2) )
    operator delete[](v1->mMaterialName.mText.mData.mItems);
  v1->mMaterialName.mText.mData.mItems = 0i64;
  *(_QWORD *)&v1->mMaterialName.mText.mData.mNumItems = 0i64;
}

// File Line: 213
// RVA: 0x21FE50
void __fastcall Illusion::rModel::~rModel(Illusion::rModel *this)
{
  Illusion::rModel *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  unsigned int v4; // edi
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  Illusion::rMesh *v7; // rcx

  v1 = this;
  v2 = `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mBonePaletteHandle.mPrev, v2);
  v4 = 0;
  if ( v1->mMeshes.mData.mNumItems )
  {
    do
      Illusion::rMesh::`scalar deleting destructor'(&v1->mMeshes.mData.mItems[v4++], 0);
    while ( v4 < v1->mMeshes.mData.mNumItems );
  }
  v5 = `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mBonePaletteHandle.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mBonePaletteHandle.mPrev);
  if ( !(v1->mMeshes.mData.mFlags & 2) )
  {
    v7 = v1->mMeshes.mData.mItems;
    if ( v7 )
      Illusion::rMesh::`vector deleting destructor'(v7, 3u);
  }
  v1->mMeshes.mData.mItems = 0i64;
  *(_QWORD *)&v1->mMeshes.mData.mNumItems = 0i64;
  if ( !(v1->mModelName.mText.mData.mFlags & 2) )
    operator delete[](v1->mModelName.mText.mData.mItems);
  v1->mModelName.mText.mData.mItems = 0i64;
  *(_QWORD *)&v1->mModelName.mText.mData.mNumItems = 0i64;
}

