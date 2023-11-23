// File Line: 43
// RVA: 0x99290
void __fastcall UFG::PhysicsVolumeProperties::PhysicsVolumeProperties(
        UFG::PhysicsVolumeProperties *this,
        const char *_name,
        unsigned __int64 uid)
{
  unsigned int v5; // ebx

  UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>(
    this,
    uid);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsVolumeProperties::`vftable;
  *(_QWORD *)&this->mName.mText.mData.mNumItems = 0i64;
  this->mName.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mFootStepEffect.mUID = -1i64;
  this->mFootStepDecal_Right.mUID = -1;
  *(_QWORD *)&this->mFootStepDecalCountdown = 0i64;
  this->mFireIgnitionTime = 0.0;
  this->mHitRecordType = -1;
  this->mReserved = 0;
  v5 = UFG::qStringLength(_name) + 1;
  UFG::qReflectArray<char>::Resize(&this->mName.mText, v5, "qReflectString::Set()");
  UFG::qMemCopy(this->mName.mText.mData.mItems, _name, v5);
}

// File Line: 53
// RVA: 0x99340
void __fastcall UFG::PhysicsVolumeProperties::PhysicsVolumeProperties(
        UFG::PhysicsVolumeProperties *this,
        MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  UFG::qReflectString *p_mName; // rsi
  const char *Name; // rdi
  unsigned int v5; // ebx

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsVolumeProperties::`vftable;
  p_mName = &this->mName;
  this->mName.mText.mData.mFlags = 2;
  Name = UFG::qReflectObject::GetName(this);
  v5 = UFG::qStringLength(Name) + 1;
  UFG::qReflectArray<char>::Resize(&p_mName->mText, v5, "qReflectString::Set()");
  UFG::qMemCopy(p_mName->mText.mData.mItems, Name, v5);
}

