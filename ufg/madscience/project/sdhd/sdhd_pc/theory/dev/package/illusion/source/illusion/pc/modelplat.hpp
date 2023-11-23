// File Line: 62
// RVA: 0xA15810
void __fastcall Illusion::BufferD3DResource::BufferD3DResource(
        Illusion::BufferD3DResource *this,
        unsigned int name_uid,
        const char *name,
        bool bFrameGenerated)
{
  UFG::qResourceData::qResourceData(this, 0x171246ADu, name_uid, name);
  this->mGpuResource = 0i64;
  this->mResourceOffset = 0;
  this->mStagingResource = 0i64;
  this->mRefCount = 0;
  this->mFrameGenerated = bFrameGenerated;
  this->mShaderResourceView = 0i64;
}

// File Line: 116
// RVA: 0xA15ED0
void __fastcall Illusion::TextureQueueNode::TextureQueueNode(
        Illusion::TextureQueueNode *this,
        Illusion::TextureD3DResource *resource,
        Illusion::Texture *texture)
{
  unsigned int mUID; // eax
  int v4; // ebx
  unsigned __int64 Ticks; // rax
  Illusion::Texture **mRequestingTextures; // rax

  mUID = resource->mNode.mUID;
  v4 = 0;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->mResource = resource;
  Ticks = UFG::qGetTicks();
  this->mTextureLoader = 0i64;
  this->mTimeStamp = Ticks;
  UFG::qMemSet(this->mRequestingTextures, 0, 0x100u);
  mRequestingTextures = this->mRequestingTextures;
  while ( *mRequestingTextures )
  {
    ++v4;
    ++mRequestingTextures;
    if ( v4 >= 32 )
      goto LABEL_6;
  }
  this->mRequestingTextures[v4] = texture;
LABEL_6:
  this->mTimeStamp = UFG::qGetTicks();
}

// File Line: 209
// RVA: 0xA163F0
void __fastcall Illusion::BufferPlat::~BufferPlat(Illusion::BufferPlat *this)
{
  Illusion::BufferD3DResourceHandle *p_mBufferD3DResourceHandle; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax

  Illusion::BufferD3DResourceInventory::OnBufferUnload(
    &Illusion::gBufferD3DResourceInventory,
    (Illusion::Buffer *)&this[-2].mPadding[56]);
  p_mBufferD3DResourceHandle = &this->mBufferD3DResourceHandle;
  mPrev = p_mBufferD3DResourceHandle->mPrev;
  mNext = p_mBufferD3DResourceHandle->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mBufferD3DResourceHandle->mPrev = p_mBufferD3DResourceHandle;
  p_mBufferD3DResourceHandle->mNext = p_mBufferD3DResourceHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x171246ADu);
    `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mBufferD3DResourceHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mBufferD3DResourceHandle);
}

