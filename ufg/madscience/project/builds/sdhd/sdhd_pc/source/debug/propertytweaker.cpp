// File Line: 17
// RVA: 0x14E4EC0
__int64 dynamic_initializer_for__gNamedSetToEdit__()
{
  UFG::qString::qString(&gNamedSetToEdit);
  return atexit(dynamic_atexit_destructor_for__gNamedSetToEdit__);
}

// File Line: 41
// RVA: 0x14E1930
__int64 dynamic_initializer_for__BackButtonArray__()
{
  `eh vector constructor iterator(BackButtonArray, 0x10ui64, 20, (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit(dynamic_atexit_destructor_for__BackButtonArray__);
}

// File Line: 224
// RVA: 0x14E1970
__int64 dynamic_initializer_for__ListOfPropSetPages__()
{
  return atexit(dynamic_atexit_destructor_for__ListOfPropSetPages__);
}

// File Line: 258
// RVA: 0x3FC580
void __fastcall EditPageInfo::~EditPageInfo(EditPageInfo *this)
{
  EditPageInfo *v1; // rdi
  UFG::qNode<PropSetEditInfo,PropSetEditInfo> *v3; // rcx
  UFG::qNode<PropSetEditInfo,PropSetEditInfo> *v4; // rax
  UFG::qNode<EditPageInfo,EditPageInfo> *v5; // rcx
  UFG::qNode<EditPageInfo,EditPageInfo> *v6; // rax

  v1 = this;
  if ( this->mPropertySetParents )
  {
    if ( this->mNumPropSetParents )
    {
      do
        operator delete[]((void *)v1->mPropertySetParents[v1->mNumPropSetParents]);
      while ( v1->mNumPropSetParents-- != 1 );
    }
    operator delete[](v1->mPropertySetParents);
    v1->mPropertySetParents = 0i64;
  }
  UFG::qList<PropSetEditInfo,PropSetEditInfo,1,0>::DeleteNodes(&v1->mPropSetTweakList);
  UFG::qList<PropSetEditInfo,PropSetEditInfo,1,0>::DeleteNodes(&v1->mPropSetTweakList);
  v3 = v1->mPropSetTweakList.mNode.mPrev;
  v4 = v1->mPropSetTweakList.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mPropSetTweakList.mNode.mPrev = &v1->mPropSetTweakList.mNode;
  v1->mPropSetTweakList.mNode.mNext = &v1->mPropSetTweakList.mNode;
  UFG::qString::~qString(&v1->mTweak_base_name);
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mPrev = (UFG::qNode<EditPageInfo,EditPageInfo> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<EditPageInfo,EditPageInfo> *)&v1->mPrev;
}

