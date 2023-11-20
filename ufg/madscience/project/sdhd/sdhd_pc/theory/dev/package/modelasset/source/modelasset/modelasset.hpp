// File Line: 129
// RVA: 0x21ED10
void __fastcall UFG::ModelAsset::ModelAsset(UFG::ModelAsset *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+30h] [rbp+18h]

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

