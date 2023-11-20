// File Line: 124
// RVA: 0x98FC0
void __fastcall UFG::PhysicsObjectProperties::PhysicsObjectProperties(UFG::PhysicsObjectProperties *this, MemImageLoadFlag f)
{
  UFG::PhysicsObjectProperties *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // rax
  const char *v6; // rax
  UFG::qString *v7; // rax
  const char *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString v10; // [rsp+20h] [rbp-88h]
  UFG::qString result; // [rsp+48h] [rbp-60h]
  __int64 v12; // [rsp+70h] [rbp-38h]
  UFG::qString v13; // [rsp+78h] [rbp-30h]
  UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *v14; // [rsp+C0h] [rbp+18h]

  v12 = -2i64;
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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsObjectProperties::`vftable;
  this->mActFileName.mText.mData.mFlags = 2;
  this->mUserProperties.mData.mFlags = 2;
  this->mAudioProperties.mData.mFlags = 2;
  this->mConstraintProperties.mData.mFlags = 2;
  v14 = &this->mDefaultSurfaceProperties;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mDefaultSurfaceProperties);
  v6 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  UFG::qString::qString(&v13, v6);
  UFG::qString::Trim(v7, &result);
  UFG::qString::~qString(&v13);
  UFG::qString::MakeLower(&result);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  v2->mScriptEnumSym = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v14, result.mData)->mUID;
  v8 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  UFG::qString::qString(&v13, v8);
  UFG::qString::Trim(v9, &v10);
  UFG::qString::~qString(&v13);
  UFG::qString::ReplaceCharInPlace(&v10, 32, 95);
  UFG::qString::MakeUpper(&v10);
  v2->mNameUid = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v14, v10.mData)->mUID;
  if ( v2->mConvexRadius < 0.02 )
    v2->mConvexRadius = 0.02;
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&result);
}

// File Line: 230
// RVA: 0x99180
void __fastcall UFG::PhysicsSurfaceProperties::PhysicsSurfaceProperties(UFG::PhysicsSurfaceProperties *this, MemImageLoadFlag f)
{
  UFG::PhysicsSurfaceProperties *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  const char *v5; // rax
  UFG::qString *v6; // rax
  int v7; // edx
  unsigned int v8; // eax
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v10; // [rsp+50h] [rbp-38h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v11; // [rsp+A0h] [rbp+18h]

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
  v11 = &this->mHandles;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PhysicsSurfaceProperties::`vftable;
  _((AMD_HD3D *)this->mAudioProperty.mUID);
  v2->debugName = (char *)UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  v5 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  UFG::qString::qString(&v10, v5);
  UFG::qString::Trim(v6, &result);
  UFG::qString::~qString(&v10);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  UFG::qString::MakeUpper(&result);
  v8 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    v8 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v7);
    result.mStringHashUpper32 = v8;
  }
  v2->mNameUid = v8;
  UFG::qString::~qString(&result);
}

