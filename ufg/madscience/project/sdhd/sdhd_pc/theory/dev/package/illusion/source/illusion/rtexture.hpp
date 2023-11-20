// File Line: 113
// RVA: 0x8D3F0
void __fastcall Illusion::rTexture::rTexture(Illusion::rTexture *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // rax
  UFG::qResourceHandle *v5; // rdi
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v4 = &this->mHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rTexture::`vftable;
  this->mFilePath.mText.mData.mFlags = 2;
  this->mMovie.mText.mData.mFlags = 2;
  v5 = (UFG::qResourceHandle *)&this->mTextureHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mTextureHandle.mPrev);
  v6 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(v5, 0x8B43FABF, v5->mNameUID, v6);
}

// File Line: 135
// RVA: 0x8D4E0
void __fastcall Illusion::rTexture::rTexture(Illusion::rTexture *this)
{
  Illusion::rTexture *v1; // rbx
  UFG::qReflectString *v2; // [rsp+48h] [rbp+10h]
  UFG::qReflectString *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>((UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&Illusion::rTexture::`vftable;
  v2 = &v1->mFilePath;
  *(_QWORD *)&v2->mText.mData.mNumItems = 0i64;
  v2->mText.mData.mItems = 0i64;
  v3 = &v1->mMovie;
  *(_QWORD *)&v3->mText.mData.mNumItems = 0i64;
  v3->mText.mData.mItems = 0i64;
  *(_QWORD *)&v1->mOutputScale = 0i64;
  *(_QWORD *)&v1->mOutputScale_PC_Medium = 0i64;
  *(_QWORD *)&v1->mCompression = 0i64;
  *(_QWORD *)&v1->mFilter = 0i64;
  *(_QWORD *)&v1->mVolumeSlices = 0i64;
  *(_QWORD *)&v1->mTilingU = 0i64;
  v1->mWrapV = 0;
  v1->mBrightnessDiffuse = 100;
  v1->mBrightnessIllum = 100;
  v1->mPreserveSize = 1;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mTextureHandle.mPrev);
}

