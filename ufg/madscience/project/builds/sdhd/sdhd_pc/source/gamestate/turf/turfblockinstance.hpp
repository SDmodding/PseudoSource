// File Line: 33
// RVA: 0x419890
void __fastcall UFG::TurfBlockInstance::TurfBlockInstance(UFG::TurfBlockInstance *this, unsigned int turfBlockID)
{
  UFG::qReflectHandle<UFG::TurfTemplate> *p_mTurfTemplate; // rbx
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v5; // rcx
  const char *StaticTypeName; // rax

  this->mData = 0i64;
  this->mTurfData = 0i64;
  p_mTurfTemplate = &this->mTurfTemplate;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mTurfTemplate);
  StaticTypeName = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v5);
  p_mTurfTemplate->mTypeUID = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::TurfBlockInstance::Init(this, turfBlockID);
}

// File Line: 41
// RVA: 0x41B8D0
__int64 __fastcall UFG::TurfBlockInstance::ID(UFG::TurfBlockInstance *this)
{
  if ( this->mData && this->mTurfData && this->mTurfTemplate.mData )
    return this->mData->id;
  else
    return 0xFFFFFFFFi64;
}

