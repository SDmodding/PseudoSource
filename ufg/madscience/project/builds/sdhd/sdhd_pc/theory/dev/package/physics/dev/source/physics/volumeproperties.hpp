// File Line: 43
// RVA: 0x99290
void __fastcall UFG::PhysicsVolumeProperties::PhysicsVolumeProperties(UFG::PhysicsVolumeProperties *this, const char *_name, unsigned __int64 uid)
{
  const char *v3; // rsi
  UFG::PhysicsVolumeProperties *v4; // r14
  unsigned int v5; // ebx
  UFG::qReflectString *v6; // [rsp+68h] [rbp+20h]

  v3 = _name;
  v4 = this;
  UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>(
    (UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *)&this->vfptr,
    uid);
  v4->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsVolumeProperties::`vftable';
  v6 = &v4->mName;
  *(_QWORD *)&v6->mText.mData.mNumItems = 0i64;
  v6->mText.mData.mItems = 0i64;
  *(_QWORD *)&v4->mFootStepEffect.mUID = -1i64;
  v4->mFootStepDecal_Right.mUID = -1;
  *(_QWORD *)&v4->mFootStepDecalCountdown = 0i64;
  v4->mFireIgnitionTime = 0.0;
  v4->mHitRecordType = -1;
  v4->mReserved = 0;
  v5 = (unsigned __int64)UFG::qStringLength(v3) + 1;
  UFG::qReflectArray<char>::Resize(&v4->mName.mText, v5, "qReflectString::Set()");
  UFG::qMemCopy(v4->mName.mText.mData.mItems, v3, v5);
}

// File Line: 53
// RVA: 0x99340
void __fastcall UFG::PhysicsVolumeProperties::PhysicsVolumeProperties(UFG::PhysicsVolumeProperties *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  const char *v4; // rdi
  unsigned int v5; // ebx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v6; // [rsp+60h] [rbp+18h]
  UFG::qReflectArray<char> *v7; // [rsp+60h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v6 = &this->mHandles;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsVolumeProperties::`vftable';
  v7 = &this->mName.mText;
  v7->mData.mFlags = 2;
  v4 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&this->vfptr);
  v5 = (unsigned __int64)UFG::qStringLength(v4) + 1;
  UFG::qReflectArray<char>::Resize(v7, v5, "qReflectString::Set()");
  UFG::qMemCopy(v7->mData.mItems, v4, v5);
}

