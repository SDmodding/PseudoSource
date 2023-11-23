// File Line: 77
// RVA: 0x44CE90
void __fastcall UFG::RagdollDefinition::RagdollDefinition(UFG::RagdollDefinition *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  char *Name; // rax
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v7; // [rsp+50h] [rbp-38h] BYREF
  UFG::qReflectHandle<UFG::ModelAsset> *p_mModelAsset; // [rsp+A0h] [rbp+18h] BYREF

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::RagdollDefinition,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::RagdollDefinition::`vftable;
  p_mModelAsset = &this->mModelAsset;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mModelAsset);
  this->mBoneMappings.mData.mFlags = 2;
  this->mBaseConstraints.mData.mFlags = 2;
  this->mCollisionSubSystemInfo.mData.mFlags = 2;
  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::qString(&v7, Name);
  UFG::qString::Trim(v5, &result);
  UFG::qString::~qString(&v7);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  this->mName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&p_mModelAsset, result.mData)->mUID;
  UFG::qString::~qString(&result);
}

