// File Line: 280
// RVA: 0x437940
void __fastcall UFG::TrueCrowdModel::TrueCrowdModel(UFG::TrueCrowdModel *this, MemImageLoadFlag flag)
{
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rdx
  char *v7; // rbx

  this->mPropSet = UFG::PropertySetManager::FindPropertySet(&this->mPropSetName);
  for ( i = 0; i < this->mNumTextureSets; ++i )
  {
    mOffset = this->mTextureSets.mOffset;
    if ( mOffset )
      v5 = (char *)&this->mTextureSets + mOffset;
    else
      v5 = 0i64;
    v6 = &v5[8 * i];
    v7 = &v6[*(_QWORD *)v6];
    if ( !*(_QWORD *)v6 )
      v7 = 0i64;
    if ( v7 )
      *((_QWORD *)v7 + 5) = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)v7 + 8);
  }
}

// File Line: 460
// RVA: 0x4380A0
void __fastcall UFG::TrueCrowdDataBase::~TrueCrowdDataBase(UFG::TrueCrowdDataBase *this)
{
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *p_mKnownRequests; // rbx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *mPrev; // rcx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax

  p_mKnownRequests = &this->mKnownRequests;
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0>::DeleteNodes(&this->mKnownRequests);
  mPrev = p_mKnownRequests->mNode.mPrev;
  mNext = p_mKnownRequests->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mKnownRequests->mNode.mPrev = &p_mKnownRequests->mNode;
  p_mKnownRequests->mNode.mNext = &p_mKnownRequests->mNode;
  `eh vector destructor iterator(
    this->mDefinition.mEntities,
    0x50Cui64,
    25,
    (void (__fastcall *)(void *))UFG::TrueCrowdDefinition::Entity::~Entity);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&this->mResourceHandles);
  v5 = this->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  v6 = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mResourceHandles.UFG::qResourceData::mNode.mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

