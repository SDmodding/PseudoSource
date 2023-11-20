// File Line: 65
// RVA: 0x41C480
void __fastcall UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *this, unsigned int newsize, const char *reason)
{
  int v3; // er14
  UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *v4; // rdi
  signed __int64 v5; // rax
  unsigned __int8 v6; // cf
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  unsigned int v9; // ebx
  signed __int64 v10; // rsi
  signed __int64 v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimComponent *v13; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v17; // rcx
  UFG::SimComponent **v18; // rbx

  v3 = newsize;
  v4 = this;
  if ( newsize != this->size )
  {
    v5 = 24i64 * newsize;
    if ( !is_mul_ok(newsize, 0x18ui64) )
      v5 = -1i64;
    v6 = __CFADD__(v5, 8i64);
    v7 = v5 + 8;
    if ( v6 )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, reason, 0i64);
    v9 = 0;
    if ( v8 )
    {
      LODWORD(v8->mNext) = v3;
      v10 = (signed __int64)&v8[1];
      `eh vector constructor iterator'(
        &v8[1],
        0x18ui64,
        v3,
        (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
    }
    else
    {
      v10 = 0i64;
    }
    if ( v4->p )
    {
      if ( v4->size )
      {
        do
        {
          v11 = 24i64 * v9;
          v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v11 + v10);
          v13 = v4->p[(unsigned __int64)v11 / 0x18].m_pPointer;
          if ( *(_QWORD *)(v11 + v10 + 16) )
          {
            v14 = v12->mPrev;
            v15 = v12->mNext;
            v14->mNext = v15;
            v15->mPrev = v14;
            v12->mPrev = v12;
            v12->mNext = v12;
          }
          v12[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v13;
          if ( v13 )
          {
            v16 = v13->m_SafePointerList.mNode.mPrev;
            v16->mNext = v12;
            v12->mPrev = v16;
            v12->mNext = &v13->m_SafePointerList.mNode;
            v13->m_SafePointerList.mNode.mPrev = v12;
          }
          ++v9;
        }
        while ( v9 < v4->size );
      }
      v17 = v4->p;
      if ( v17 )
      {
        v18 = &v17[-1].m_pPointer;
        `eh vector destructor iterator'(
          v17,
          0x18ui64,
          (int)v17[-1].m_pPointer,
          (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
        operator delete[](v18);
      }
    }
    v4->p = (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)v10;
    v4->capacity = v3;
  }
}

// File Line: 152
// RVA: 0x9ADA0
void __fastcall UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::~qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>(UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *this)
{
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *v1; // rdi
  DNA::DNAPropertyBagSerializer::CreateContext *v2; // rcx
  unsigned int *v3; // rbx

  v1 = this;
  v2 = this->p;
  if ( v2 )
  {
    v3 = &v2[-1].mName.mStringHash32;
    `eh vector destructor iterator'(
      v2,
      0x40ui64,
      v2[-1].mName.mStringHash32,
      (void (__fastcall *)(void *))DNA::DNAPropertyBagSerializer::CreateContext::~CreateContext);
    operator delete[](v3);
  }
  v1->p = 0i64;
  *(_QWORD *)&v1->size = 0i64;
}

// File Line: 253
// RVA: 0x41A1D0
UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *__fastcall UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *this, UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *item, const char *reason)
{
  __int64 v3; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *v7; // rdi
  unsigned int v8; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v9; // rdx
  UFG::SimComponent *v10; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax

  v3 = this->size;
  v4 = item;
  v5 = this->capacity;
  v6 = v3 + 1;
  v7 = this;
  if ( (signed int)v3 + 1 > v5 )
  {
    if ( v5 )
      v8 = 2 * v5;
    else
      v8 = 1;
    for ( ; v8 < v6; v8 *= 2 )
      ;
    if ( v8 - v6 > 0x10000 )
      v8 = v3 + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
      (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)this,
      v8,
      reason);
  }
  v9 = v7->p;
  v7->size = v6;
  v10 = v4->m_pPointer;
  v11 = &v9[v3];
  if ( v11->m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v11->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  }
  v11->m_pPointer = v10;
  if ( v10 )
  {
    v14 = v10->m_SafePointerList.mNode.mPrev;
    v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mPrev = v14;
    v11->mNext = &v10->m_SafePointerList.mNode;
    v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  }
  return &v7->p[v3];
}

// File Line: 393
// RVA: 0x355E70
void __fastcall UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0>::FastDelete(UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0> *this, unsigned int index)
{
  UFG::AICoverQuery::CoverQueryRecord *v2; // r10
  UFG::AICoverQuery::CoverQueryRecord *v3; // r9
  UFG::CoverPosition *v4; // rax

  v2 = &this->p[index];
  v3 = &this->p[this->size - 1];
  v4 = v3->m_pCoverPosition;
  v2->m_pCoverPosition = v4;
  if ( v4 )
    ++v4->m_iRefCount;
  v2->m_bPathFound = v3->m_bPathFound;
  v2->m_fPathCost = v3->m_fPathCost;
  v2->m_fDistancePriority = v3->m_fDistancePriority;
  v2->m_fDistanceToTargetPriority = v3->m_fDistanceToTargetPriority;
  v2->m_fSweetSpotPriority = v3->m_fSweetSpotPriority;
  v2->m_fLineOfSightPriority = v3->m_fLineOfSightPriority;
  v2->m_fDirectLineOfSightPriority = v3->m_fDirectLineOfSightPriority;
  v2->m_fNotExposedPriority = v3->m_fNotExposedPriority;
  v2->m_fDistanceFromAlliesPriority = v3->m_fDistanceFromAlliesPriority;
  v2->m_fRadialSpreadFromAlliesPriority = v3->m_fRadialSpreadFromAlliesPriority;
  if ( this->size > 1 )
    --this->size;
  else
    this->size = 0;
}

