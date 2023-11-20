// File Line: 85
// RVA: 0xA15D20
void __fastcall Illusion::TextureD3DResource::TextureD3DResource(Illusion::TextureD3DResource *this, unsigned int name_uid, const char *name)
{
  Illusion::TextureD3DResource *v3; // rbx

  v3 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode, 0xEF77C5F7, name_uid, name);
  v3->mGpuResource = 0i64;
  v3->mStagingResource = 0i64;
  v3->mStagingResourceInitialized = 0;
  v3->mDeferredContextTextureAccessBuffer = 0i64;
  v3->mShaderResourceView = 0i64;
  v3->mNumberMipViews = 0;
  v3->mShaderResourceViewMips = 0i64;
  v3->mSamplerState = 0i64;
  v3->mRefCount = 0;
  v3->mAliased = 0;
  v3->mDelayedReadCopy[0] = 0i64;
  v3->mDelayedReadCopy[1] = 0i64;
  v3->mDelayedReadCopy[2] = 0i64;
  v3->mDelayedReadCopy[3] = 0i64;
  v3->mDelayedReadCopy[4] = 0i64;
}

// File Line: 255
// RVA: 0xA15E60
void __fastcall Illusion::TexturePlat::TexturePlat(Illusion::TexturePlat *this)
{
  Illusion::TexturePlat *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->mCpuAccess = 0i64;
  *(_QWORD *)&this->mUploadAfterUnmap = 0i64;
  this->mInitialImageData = 0i64;
  this->mMappedResource = 0i64;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&this->mVRamHandle);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mTextureD3DResourceHandle.mPrev);
  UFG::qMemSet(v1->mPadding, 0, 0x48u);
  v1->mTextureD3DResourceHandle.mNameUID = 0;
}

// File Line: 261
// RVA: 0xA16E10
void __fastcall Illusion::TexturePlat::~TexturePlat(Illusion::TexturePlat *this)
{
  Illusion::TexturePlat *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax

  v1 = this;
  v2 = (UFG::qResourceHandle *)&this->mTextureD3DResourceHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Illusion::TextureD3DResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::TextureD3DResource>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xEF77C5F7);
    `UFG::qGetResourceInventory<Illusion::TextureD3DResource>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v1->mVRamHandle);
}

