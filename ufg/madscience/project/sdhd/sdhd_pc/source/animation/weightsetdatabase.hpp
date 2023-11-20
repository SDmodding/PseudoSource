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
  WeightSetGroup *v1; // rbx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v2; // rax
  BinString *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v2 = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Expression::IMemberMapVtbl *)&WeightSetGroup::`vftable';
  v3 = &this->mName;
  v3->mOffset = 1i64;
  BinString::Set(v3, &customWorldMapCaption);
  v1->mWeightsets.mCount = 0;
  v1->mWeightsets.mData.mOffset = 0i64;
}

// File Line: 173
// RVA: 0x29F8F0
void __fastcall WeightSetGroup::~WeightSetGroup(WeightSetGroup *this)
{
  WeightSetGroup *v1; // rbx
  char *v2; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v3; // rdx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v4; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v5; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&WeightSetGroup::`vftable';
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&this->mWeightsets);
  if ( !(~LOBYTE(v1->mName.mOffset) & 1) )
  {
    if ( v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&v1->mName + (v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v3 = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 175
// RVA: 0x2C03F0
__int64 __fastcall WeightSetGroup::GetClassNameUID(WeightSetGroup *this)
{
  return WeightSetGroup::sClassNameUID;
}

// File Line: 215
// RVA: 0x2C30B0
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

