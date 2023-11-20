// File Line: 62
// RVA: 0xA15810
void __fastcall Illusion::BufferD3DResource::BufferD3DResource(Illusion::BufferD3DResource *this, unsigned int name_uid, const char *name, bool bFrameGenerated)
{
  bool v4; // bl
  Illusion::BufferD3DResource *v5; // rdi

  v4 = bFrameGenerated;
  v5 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode, 0x171246ADu, name_uid, name);
  v5->mGpuResource = 0i64;
  v5->mResourceOffset = 0;
  v5->mStagingResource = 0i64;
  v5->mRefCount = 0;
  v5->mFrameGenerated = v4;
  v5->mShaderResourceView = 0i64;
}

// File Line: 116
// RVA: 0xA15ED0
void __fastcall Illusion::TextureQueueNode::TextureQueueNode(Illusion::TextureQueueNode *this, Illusion::TextureD3DResource *resource, Illusion::Texture *texture)
{
  unsigned int v3; // eax
  signed int v4; // ebx
  Illusion::Texture *v5; // rbp
  Illusion::TextureQueueNode *v6; // rdi
  unsigned __int64 v7; // rax
  Illusion::Texture **v8; // rax

  v3 = resource->mNode.mUID;
  v4 = 0;
  v5 = texture;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v3;
  v6 = this;
  this->mResource = resource;
  v7 = UFG::qGetTicks();
  v6->mTextureLoader = 0i64;
  v6->mTimeStamp = v7;
  UFG::qMemSet(v6->mRequestingTextures, 0, 0x100u);
  v8 = v6->mRequestingTextures;
  while ( *v8 )
  {
    ++v4;
    ++v8;
    if ( v4 >= 32 )
      goto LABEL_6;
  }
  v6->mRequestingTextures[v4] = v5;
LABEL_6:
  v6->mTimeStamp = UFG::qGetTicks();
}

// File Line: 209
// RVA: 0xA163F0
void __fastcall Illusion::BufferPlat::~BufferPlat(Illusion::BufferPlat *this)
{
  Illusion::BufferPlat *v1; // rbx
  UFG::qResourceHandle *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax

  v1 = this;
  Illusion::BufferD3DResourceInventory::OnBufferUnload(
    &Illusion::gBufferD3DResourceInventory,
    (Illusion::Buffer *)&this[-2].mPadding[56]);
  v2 = (UFG::qResourceHandle *)&v1->mBufferD3DResourceHandle.mPrev;
  v3 = v2->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
  v5 = `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x171246ADu);
    `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result = v5;
  }
  UFG::qResourceHandle::Close(v2, v5);
  UFG::qResourceHandle::~qResourceHandle(v2);
}

