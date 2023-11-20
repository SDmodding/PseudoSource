// File Line: 278
// RVA: 0x966C0
void __fastcall UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>(UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *this, unsigned __int64 uid)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // r8
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v3; // [rsp+48h] [rbp+10h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = uid;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mTypeUID = -1i64;
  v3 = &this->mHandles;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::`vftable;
  v2->mBaseNode.mUID = uid;
  this->mTypeUID = UFG::qStringHash64("UFG::PhysicsVolumeProperties", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 283
// RVA: 0xABA50
_BOOL8 __fastcall UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::HasFactory(UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *this)
{
  return UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::sFactoryOp.mOnCreateFunc != 0i64;
}

// File Line: 284
// RVA: 0xAB710
const char *__fastcall UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::GetTypeName(UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *this)
{
  return "UFG::PhysicsVolumeProperties";
}

// File Line: 303
// RVA: 0x963D0
void __fastcall UFG::OnLoadClass<UFG::ConstraintDefFixed>(char *object_data)
{
  char *v1; // rbx

  v1 = object_data;
  if ( object_data )
  {
    UFG::ConstraintDef::ConstraintDef((UFG::ConstraintDef *)object_data, 0);
    *(_QWORD *)v1 = &UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::`vftable;
    *(_QWORD *)v1 = &UFG::ConstraintDefFixed::`vftable;
  }
}

// File Line: 414
// RVA: 0x96680
void __fastcall UFG::qReflectHandle<UFG::qReflectObject>::qReflectHandle<UFG::qReflectObject>(UFG::qReflectHandle<UFG::qReflectObject> *this)
{
  UFG::qReflectHandle<UFG::qReflectObject> *v1; // rbx

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mPrev);
  v1->mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
}

