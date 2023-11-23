// File Line: 34
// RVA: 0x4196F0
void __fastcall UFG::RacketInstance2::RacketInstance2(UFG::RacketInstance2 *this)
{
  UFG::qReflectHandle<UFG::RacketType> *p_mType; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v3; // rcx
  const char *TypeName; // rax

  this->mTurf.mTurfIndex = 0;
  this->mTurf.mComponent = 0i64;
  p_mType = &this->mType;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mType);
  TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v3);
  p_mType->mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  *(_QWORD *)&this->mBlockIndex = 0i64;
}

