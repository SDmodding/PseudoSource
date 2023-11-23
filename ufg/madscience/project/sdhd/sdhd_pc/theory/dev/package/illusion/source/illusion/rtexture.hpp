// File Line: 113
// RVA: 0x8D3F0
void __fastcall Illusion::rTexture::rTexture(Illusion::rTexture *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  Illusion::TextureHandle *p_mTextureHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rTexture::`vftable;
  this->mFilePath.mText.mData.mFlags = 2;
  this->mMovie.mText.mData.mFlags = 2;
  p_mTextureHandle = &this->mTextureHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mTextureHandle);
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mTextureHandle, 0x8B43FABF, p_mTextureHandle->mNameUID, Inventory);
}

// File Line: 135
// RVA: 0x8D4E0
void __fastcall Illusion::rTexture::rTexture(Illusion::rTexture *this)
{
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rTexture::`vftable;
  *(_QWORD *)&this->mFilePath.mText.mData.mNumItems = 0i64;
  this->mFilePath.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mMovie.mText.mData.mNumItems = 0i64;
  this->mMovie.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mOutputScale = 0i64;
  *(_QWORD *)&this->mOutputScale_PC_Medium = 0i64;
  *(_QWORD *)&this->mCompression = 0i64;
  *(_QWORD *)&this->mFilter = 0i64;
  *(_QWORD *)&this->mVolumeSlices = 0i64;
  *(_QWORD *)&this->mTilingU = 0i64;
  this->mWrapV = Default;
  this->mBrightnessDiffuse = 100;
  this->mBrightnessIllum = 100;
  this->mPreserveSize = True;
  UFG::qResourceHandle::qResourceHandle(&this->mTextureHandle);
}

