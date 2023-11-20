// File Line: 34
// RVA: 0x4196F0
void __fastcall UFG::RacketInstance2::RacketInstance2(UFG::RacketInstance2 *this)
{
  UFG::RacketInstance2 *v1; // rdi
  UFG::qReflectHandle<UFG::RacketType> *v2; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v3; // rcx
  const char *v4; // rax

  v1 = this;
  this->mTurf.mTurfIndex = 0;
  this->mTurf.mComponent = 0i64;
  v2 = &this->mType;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mType.mPrev);
  v4 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v3);
  v2->mTypeUID = UFG::qStringHash64(v4, 0xFFFFFFFFFFFFFFFFui64);
  *(_QWORD *)&v1->mBlockIndex = 0i64;
}

