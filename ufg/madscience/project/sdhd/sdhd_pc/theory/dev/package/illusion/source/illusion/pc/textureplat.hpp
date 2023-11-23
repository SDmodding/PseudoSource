// File Line: 85
// RVA: 0xA15D20
void __fastcall Illusion::TextureD3DResource::TextureD3DResource(
        Illusion::TextureD3DResource *this,
        unsigned int name_uid,
        const char *name)
{
  UFG::qResourceData::qResourceData(this, 0xEF77C5F7, name_uid, name);
  this->mGpuResource = 0i64;
  this->mStagingResource = 0i64;
  this->mStagingResourceInitialized = 0;
  this->mDeferredContextTextureAccessBuffer = 0i64;
  this->mShaderResourceView = 0i64;
  this->mNumberMipViews = 0;
  this->mShaderResourceViewMips = 0i64;
  this->mSamplerState = 0i64;
  this->mRefCount = 0;
  this->mAliased = 0;
  this->mDelayedReadCopy[0] = 0i64;
  this->mDelayedReadCopy[1] = 0i64;
  this->mDelayedReadCopy[2] = 0i64;
  this->mDelayedReadCopy[3] = 0i64;
  this->mDelayedReadCopy[4] = 0i64;
}

// File Line: 255
// RVA: 0xA15E60
void __fastcall Illusion::TexturePlat::TexturePlat(Illusion::TexturePlat *this)
{
  *(_QWORD *)&this->mCpuAccess = 0i64;
  *(_QWORD *)&this->mUploadAfterUnmap = 0i64;
  this->mInitialImageData = 0i64;
  this->mMappedResource = 0i64;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&this->mVRamHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mTextureD3DResourceHandle);
  UFG::qMemSet(this->mPadding, 0, 0x48u);
  this->mTextureD3DResourceHandle.mNameUID = 0;
}

// File Line: 261
// RVA: 0xA16E10
void __fastcall Illusion::TexturePlat::~TexturePlat(Illusion::TexturePlat *this)
{
  Illusion::TextureD3DResourceHandle *p_mTextureD3DResourceHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax

  p_mTextureD3DResourceHandle = &this->mTextureD3DResourceHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xEF77C5F7);
    `UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mTextureD3DResourceHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mTextureD3DResourceHandle);
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&this->mVRamHandle);
}

