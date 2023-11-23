// File Line: 39
// RVA: 0x41ACD0
UFG::qSymbol *__fastcall UFG::TurfInstance::GameplayPrefab(UFG::TurfInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *mData; // rax
  unsigned int mParent; // [rsp+20h] [rbp+8h]

  if ( this->mData && this->mComponent && (mData = this->mTemplate.mData) != 0i64 )
    mParent = (unsigned int)mData[2].mBaseNode.mParent;
  else
    mParent = -1;
  result->mUID = mParent;
  return result;
}

