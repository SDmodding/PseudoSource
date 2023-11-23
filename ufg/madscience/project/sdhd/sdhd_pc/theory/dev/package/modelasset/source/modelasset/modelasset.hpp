// File Line: 129
// RVA: 0x21ED10
void __fastcall UFG::ModelAsset::ModelAsset(UFG::ModelAsset *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAsset::`vftable;
  this->mFilePath.mText.mData.mFlags = 2;
  this->mModelInfo.mData.mFlags = 2;
  this->mCustomDataSlotArray.mData.mFlags = 2;
  this->mCustomDataSlots.mData.mFlags = 2;
  this->mRigFile.mText.mData.mFlags = 2;
  this->mRigName.mText.mData.mFlags = 2;
  this->mRigBone.mText.mData.mFlags = 2;
  this->mData.mData.mFlags = 2;
}

