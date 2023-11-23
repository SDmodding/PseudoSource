// File Line: 92
// RVA: 0x1BED30
void __fastcall Illusion::ModelProxy::ModelProxy(Illusion::ModelProxy *this, Illusion::ModelProxy *value)
{
  unsigned int mNameUID; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax

  UFG::qResourceHandle::qResourceHandle(&this->mModelHandle);
  mNameUID = value->mModelHandle.mNameUID;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mModelHandle, 0xA2ADCD77, mNameUID, Inventory);
  this->mRModel = value->mRModel;
}

// File Line: 95
// RVA: 0x1C19E0
void __fastcall Illusion::ModelProxy::ModelProxy(Illusion::ModelProxy *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax

  UFG::qResourceHandle::qResourceHandle(&this->mModelHandle);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mModelHandle, 0xA2ADCD77, 0, Inventory);
  this->mRModel = 0i64;
}

// File Line: 98
// RVA: 0x3C70
void __fastcall Illusion::ModelProxy::Init(Illusion::ModelProxy *this, unsigned int model_uid)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mModelHandle, 0xA2ADCD77, model_uid, Inventory);
  this->mRModel = 0i64;
}

// File Line: 106
// RVA: 0x1DFD0
Illusion::rModel *__fastcall Illusion::ModelProxy::GetNumMeshes(Illusion::ModelProxy *this)
{
  Illusion::Model *mData; // rax
  Illusion::rModel *result; // rax

  mData = (Illusion::Model *)this->mModelHandle.mData;
  if ( mData )
    return (Illusion::rModel *)mData->mNumMeshes;
  result = this->mRModel;
  if ( result )
    return (Illusion::rModel *)result->mMeshes.mData.mNumItems;
  return result;
}

// File Line: 110
// RVA: 0x2940
Illusion::ModelProxy *__fastcall Illusion::ModelProxy::operator=(Illusion::ModelProxy *this, Illusion::ModelProxy *rhs)
{
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mNameUID; // esi
  UFG::qResourceWarehouse *v6; // rax

  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  mNameUID = rhs->mModelHandle.mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mModelHandle, 0xA2ADCD77, mNameUID, Inventory);
  this->mRModel = rhs->mRModel;
  return this;
}

// File Line: 166
// RVA: 0x21FCB0
void __fastcall Illusion::rMesh::~rMesh(Illusion::rMesh *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  Illusion::BufferHandle *mVertexBufferHandles; // rdi
  __int64 v7; // rsi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax

  Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mVertexDeclHandle, Inventory);
  v4 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v4;
  }
  UFG::qResourceHandle::Close(&this->mIndexBufferHandle, v4);
  mVertexBufferHandles = this->mVertexBufferHandles;
  v7 = 4i64;
  do
  {
    v8 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x92CDEC8F);
      `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v8;
    }
    UFG::qResourceHandle::Close(mVertexBufferHandles++, v8);
    --v7;
  }
  while ( v7 );
  `eh vector destructor iterator(
    this->mVertexBufferHandles,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::BufferHandle::~BufferHandle);
  v10 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v10;
  }
  UFG::qResourceHandle::Close(&this->mIndexBufferHandle, v10);
  UFG::qResourceHandle::~qResourceHandle(&this->mIndexBufferHandle);
  v12 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v12;
  }
  UFG::qResourceHandle::Close(&this->mVertexDeclHandle, v12);
  UFG::qResourceHandle::~qResourceHandle(&this->mVertexDeclHandle);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mMaterial);
  if ( (this->mMaterialName.mText.mData.mFlags & 2) == 0 )
    operator delete[](this->mMaterialName.mText.mData.mItems);
  this->mMaterialName.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mMaterialName.mText.mData.mNumItems = 0i64;
}

// File Line: 213
// RVA: 0x21FE50
void __fastcall Illusion::rModel::~rModel(Illusion::rModel *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  unsigned int i; // edi
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  Illusion::rMesh *mItems; // rcx

  Inventory = `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mBonePaletteHandle, Inventory);
  for ( i = 0; i < this->mMeshes.mData.mNumItems; ++i )
    Illusion::rMesh::`scalar deleting destructor(&this->mMeshes.mData.mItems[i], 0);
  v5 = `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result = v5;
  }
  UFG::qResourceHandle::Close(&this->mBonePaletteHandle, v5);
  UFG::qResourceHandle::~qResourceHandle(&this->mBonePaletteHandle);
  if ( (this->mMeshes.mData.mFlags & 2) == 0 )
  {
    mItems = this->mMeshes.mData.mItems;
    if ( mItems )
      Illusion::rMesh::`vector deleting destructor(mItems, 3u);
  }
  this->mMeshes.mData.mItems = 0i64;
  *(_QWORD *)&this->mMeshes.mData.mNumItems = 0i64;
  if ( (this->mModelName.mText.mData.mFlags & 2) == 0 )
    operator delete[](this->mModelName.mText.mData.mItems);
  this->mModelName.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mModelName.mText.mData.mNumItems = 0i64;
}

