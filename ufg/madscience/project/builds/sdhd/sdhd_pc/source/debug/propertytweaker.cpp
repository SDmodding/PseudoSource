// File Line: 17
// RVA: 0x14E4EC0
__int64 dynamic_initializer_for__gNamedSetToEdit__()
{
  UFG::qString::qString(&gNamedSetToEdit);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNamedSetToEdit__);
}

// File Line: 41
// RVA: 0x14E1930
__int64 dynamic_initializer_for__BackButtonArray__()
{
  `eh vector constructor iterator(
    (char *)BackButtonArray,
    0x10ui64,
    20,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__BackButtonArray__);
}

// File Line: 224
// RVA: 0x14E1970
__int64 dynamic_initializer_for__ListOfPropSetPages__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ListOfPropSetPages__);
}

// File Line: 258
// RVA: 0x3FC580
void __fastcall EditPageInfo::~EditPageInfo(EditPageInfo *this)
{
  UFG::qNode<PropSetEditInfo,PropSetEditInfo> *mPrev; // rcx
  UFG::qNode<PropSetEditInfo,PropSetEditInfo> *mNext; // rax
  UFG::qNode<EditPageInfo,EditPageInfo> *v5; // rcx
  UFG::qNode<EditPageInfo,EditPageInfo> *v6; // rax

  if ( this->mPropertySetParents )
  {
    if ( this->mNumPropSetParents )
    {
      do
        operator delete[]((void *)this->mPropertySetParents[this->mNumPropSetParents]);
      while ( this->mNumPropSetParents-- != 1 );
    }
    operator delete[](this->mPropertySetParents);
    this->mPropertySetParents = 0i64;
  }
  UFG::qList<PropSetEditInfo,PropSetEditInfo,1,0>::DeleteNodes(&this->mPropSetTweakList);
  UFG::qList<PropSetEditInfo,PropSetEditInfo,1,0>::DeleteNodes(&this->mPropSetTweakList);
  mPrev = this->mPropSetTweakList.mNode.mPrev;
  mNext = this->mPropSetTweakList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPropSetTweakList.mNode.mPrev = &this->mPropSetTweakList.mNode;
  this->mPropSetTweakList.mNode.mNext = &this->mPropSetTweakList.mNode;
  UFG::qString::~qString(&this->mTweak_base_name);
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = this;
  this->mNext = this;
}

