// File Line: 124
// RVA: 0x98FC0
void __fastcall UFG::PhysicsObjectProperties::PhysicsObjectProperties(
        UFG::PhysicsObjectProperties *this,
        MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  const char *Name; // rax
  UFG::qString *v5; // rax
  const char *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString v8; // [rsp+20h] [rbp-88h] BYREF
  UFG::qString result; // [rsp+48h] [rbp-60h] BYREF
  __int64 v10; // [rsp+70h] [rbp-38h]
  UFG::qString v11; // [rsp+78h] [rbp-30h] BYREF
  UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *p_mDefaultSurfaceProperties; // [rsp+C0h] [rbp+18h] BYREF

  v10 = -2i64;
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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsObjectProperties::`vftable;
  this->mActFileName.mText.mData.mFlags = 2;
  this->mUserProperties.mData.mFlags = 2;
  this->mAudioProperties.mData.mFlags = 2;
  this->mConstraintProperties.mData.mFlags = 2;
  p_mDefaultSurfaceProperties = &this->mDefaultSurfaceProperties;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mDefaultSurfaceProperties);
  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::qString(&v11, Name);
  UFG::qString::Trim(v5, &result);
  UFG::qString::~qString(&v11);
  UFG::qString::MakeLower(&result);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  this->mScriptEnumSym = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                         (UFG::qSymbol *)&p_mDefaultSurfaceProperties,
                                         result.mData)->mUID;
  v6 = UFG::qReflectObject::GetName(this);
  UFG::qString::qString(&v11, v6);
  UFG::qString::Trim(v7, &v8);
  UFG::qString::~qString(&v11);
  UFG::qString::ReplaceCharInPlace(&v8, 32, 95);
  UFG::qString::MakeUpper(&v8);
  this->mNameUid = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                   (UFG::qSymbol *)&p_mDefaultSurfaceProperties,
                                   v8.mData)->mUID;
  if ( this->mConvexRadius < 0.02 )
    this->mConvexRadius = 0.02;
  UFG::qString::~qString(&v8);
  UFG::qString::~qString(&result);
}

// File Line: 230
// RVA: 0x99180
void __fastcall UFG::PhysicsSurfaceProperties::PhysicsSurfaceProperties(
        UFG::PhysicsSurfaceProperties *this,
        MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  const char *Name; // rax
  UFG::qString *v5; // rax
  unsigned int mStringHashUpper32; // eax
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v8; // [rsp+50h] [rbp-38h] BYREF

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsSurfaceProperties::`vftable;
  _((AMD_HD3D *)this->mAudioProperty.mUID);
  this->debugName = (char *)UFG::qReflectObject::GetName(this);
  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::qString(&v8, Name);
  UFG::qString::Trim(v5, &result);
  UFG::qString::~qString(&v8);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  UFG::qString::MakeUpper(&result);
  mStringHashUpper32 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, 0xFFFFFFFF);
    result.mStringHashUpper32 = mStringHashUpper32;
  }
  this->mNameUid = mStringHashUpper32;
  UFG::qString::~qString(&result);
}

