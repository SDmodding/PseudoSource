// File Line: 39
// RVA: 0x41ACD0
UFG::qSymbol *__fastcall UFG::TurfInstance::GameplayPrefab(UFG::TurfInstance *this, UFG::qSymbol *result)
{
  UFG::qReflectObject *v2; // rax
  unsigned int v4; // [rsp+20h] [rbp+8h]

  if ( this->mData && this->mComponent && (v2 = this->mTemplate.mData) != 0i64 )
    v4 = (unsigned int)v2[2].mBaseNode.mParent;
  else
    v4 = -1;
  result->mUID = v4;
  return result;
}

