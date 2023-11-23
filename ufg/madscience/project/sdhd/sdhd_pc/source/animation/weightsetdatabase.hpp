// File Line: 43
// RVA: 0x2C0400
__int64 __fastcall WeightsetEntry::GetClassNameUID(WeightsetEntry *this)
{
  return WeightsetEntry::sClassNameUID;
}

// File Line: 93
// RVA: 0x3A7DD0
__int64 __fastcall Weightset::GetClassNameUID(Weightset *this)
{
  return Weightset::sClassNameUID;
}

// File Line: 171
// RVA: 0x39EA20
void __fastcall WeightSetGroup::WeightSetGroup(WeightSetGroup *this)
{
  BinString *p_mName; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<WeightSetGroup,WeightSetGroup>;
  this->mNext = &this->UFG::qNode<WeightSetGroup,WeightSetGroup>;
  this->vfptr = (Expression::IMemberMapVtbl *)&WeightSetGroup::`vftable;
  p_mName = &this->mName;
  p_mName->mOffset = 1i64;
  BinString::Set(p_mName, &customCaption);
  this->mWeightsets.mCount = 0;
  this->mWeightsets.mData.mOffset = 0i64;
}

// File Line: 173
// RVA: 0x29F8F0
void __fastcall WeightSetGroup::~WeightSetGroup(WeightSetGroup *this)
{
  char *v2; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *mPrev; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&WeightSetGroup::`vftable;
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&this->mWeightsets);
  if ( (this->mName.mOffset & 1) != 0 && (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<WeightSetGroup,WeightSetGroup>;
  this->mNext = &this->UFG::qNode<WeightSetGroup,WeightSetGroup>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 175
// RVA: 0x2C03F0
__int64 __fastcall WeightSetGroup::GetClassNameUID(WeightSetGroup *this)
{
  return WeightSetGroup::sClassNameUID;
}

// File Line: 215
// RVA: 0x2C30B0
// attributes: thunk
WeightSetDataBase *__fastcall WeightSetGroup::GetResourceOwner(WeightSetGroup *this)
{
  return WeightSetDataBase::GetInstance();
}

// File Line: 217
// RVA: 0x3A7DC0
__int64 __fastcall WeightSetDataBase::GetClassNameUID(WeightSetDataBase *this)
{
  return WeightSetDataBase::sClassNameUID;
}

// File Line: 255
// RVA: 0x3AB720
WeightSetDataBase *__fastcall WeightSetDataBase::LoadWeightSetGroupMemberMap(const char *fileName)
{
  return WeightSetDataBase::LoadWeightSetGroup(WeightSetDataBase::sWeightSetDataBase, fileName);
}

