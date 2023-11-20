// File Line: 280
// RVA: 0x437940
void __fastcall UFG::TrueCrowdModel::TrueCrowdModel(UFG::TrueCrowdModel *this, MemImageLoadFlag flag)
{
  UFG::TrueCrowdModel *v2; // rsi
  unsigned int v3; // edi
  __int64 v4; // rax
  signed __int64 v5; // rcx
  _QWORD *v6; // rdx
  char *v7; // rbx

  v2 = this;
  this->mPropSet = UFG::PropertySetManager::FindPropertySet(&this->mPropSetName);
  v3 = 0;
  if ( v2->mNumTextureSets > 0u )
  {
    do
    {
      v4 = v2->mTextureSets.mOffset;
      if ( v4 )
        v5 = (signed __int64)&v2->mTextureSets + v4;
      else
        v5 = 0i64;
      v6 = (_QWORD *)(v5 + 8i64 * v3);
      v7 = (char *)v6 + *v6;
      if ( !*v6 )
        v7 = 0i64;
      if ( v7 )
        *((_QWORD *)v7 + 5) = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)v7 + 8);
      ++v3;
    }
    while ( v3 < v2->mNumTextureSets );
  }
}

// File Line: 460
// RVA: 0x4380A0
void __fastcall UFG::TrueCrowdDataBase::~TrueCrowdDataBase(UFG::TrueCrowdDataBase *this)
{
  UFG::TrueCrowdDataBase *v1; // rdi
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0> *v2; // rbx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v3; // rcx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v4; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax

  v1 = this;
  v2 = &this->mKnownRequests;
  UFG::qList<UFG::TrueCrowdSet,UFG::TrueCrowdSet,1,0>::DeleteNodes(&this->mKnownRequests);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  `eh vector destructor iterator'(
    v1->mDefinition.mEntities,
    0x50Cui64,
    25,
    (void (__fastcall *)(void *))UFG::TrueCrowdDefinition::Entity::~Entity);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
  v5 = v1->mResourceHandles.mNode.mPrev;
  v6 = v1->mResourceHandles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mResourceHandles.mNode.mPrev = &v1->mResourceHandles.mNode;
  v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
}

