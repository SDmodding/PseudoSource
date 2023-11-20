// File Line: 77
// RVA: 0x44CE90
void __fastcall UFG::RagdollDefinition::RagdollDefinition(UFG::RagdollDefinition *this, MemImageLoadFlag f)
{
  UFG::RagdollDefinition *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // rax
  char *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v9; // [rsp+50h] [rbp-38h]
  UFG::qReflectHandle<UFG::ModelAsset> *v10; // [rsp+A0h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::RagdollDefinition,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::RagdollDefinition::`vftable;
  v10 = &this->mModelAsset;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mModelAsset);
  v2->mBoneMappings.mData.mFlags = 2;
  v2->mBaseConstraints.mData.mFlags = 2;
  v2->mCollisionSubSystemInfo.mData.mFlags = 2;
  v6 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  UFG::qString::qString(&v9, v6);
  UFG::qString::Trim(v7, &result);
  UFG::qString::~qString(&v9);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  v2->mName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v10, result.mData)->mUID;
  UFG::qString::~qString(&result);
}

