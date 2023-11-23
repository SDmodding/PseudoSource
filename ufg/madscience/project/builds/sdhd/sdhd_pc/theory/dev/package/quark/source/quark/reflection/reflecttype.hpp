// File Line: 278
// RVA: 0x966C0
void __fastcall UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>(
        UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *this,
        unsigned __int64 uid)
{
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = uid;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mTypeUID = -1i64;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::`vftable;
  this->mBaseNode.mUID = uid;
  this->mTypeUID = UFG::qStringHash64("UFG::PhysicsVolumeProperties", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 283
// RVA: 0xABA50
_BOOL8 __fastcall UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::HasFactory(
        UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *this)
{
  return UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::sFactoryOp.mOnCreateFunc != 0i64;
}

// File Line: 284
// RVA: 0xAB710
const char *__fastcall UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::GetTypeName(
        UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject> *this)
{
  return "UFG::PhysicsVolumeProperties";
}

// File Line: 303
// RVA: 0x963D0
void __fastcall UFG::OnLoadClass<UFG::ConstraintDefFixed>(UFG::ConstraintDef *object_data)
{
  if ( object_data )
  {
    UFG::ConstraintDef::ConstraintDef(object_data, 0);
    object_data->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::`vftable;
    object_data->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDefFixed::`vftable;
  }
}

// File Line: 414
// RVA: 0x96680
void __fastcall UFG::qReflectHandle<UFG::qReflectObject>::qReflectHandle<UFG::qReflectObject>(
        UFG::qReflectHandle<UFG::qReflectObject> *this)
{
  UFG::qReflectHandleBase::qReflectHandleBase(this);
  this->mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
}

