// File Line: 33
// RVA: 0x419890
void __fastcall UFG::TurfBlockInstance::TurfBlockInstance(UFG::TurfBlockInstance *this, unsigned int turfBlockID)
{
  unsigned int v2; // edi
  UFG::TurfBlockInstance *v3; // rsi
  UFG::qReflectHandle<UFG::TurfTemplate> *v4; // rbx
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v5; // rcx
  const char *v6; // rax

  v2 = turfBlockID;
  v3 = this;
  this->mData = 0i64;
  this->mTurfData = 0i64;
  v4 = &this->mTurfTemplate;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mTurfTemplate.mPrev);
  v6 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v5);
  v4->mTypeUID = UFG::qStringHash64(v6, 0xFFFFFFFFFFFFFFFFui64);
  UFG::TurfBlockInstance::Init(v3, v2);
}

// File Line: 41
// RVA: 0x41B8D0
signed __int64 __fastcall UFG::TurfBlockInstance::ID(UFG::TurfBlockInstance *this)
{
  signed __int64 result; // rax

  if ( this->mData && this->mTurfData && this->mTurfTemplate.mData )
    result = this->mData->id;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

