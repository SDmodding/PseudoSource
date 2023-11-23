// File Line: 65
// RVA: 0x41C480
void __fastcall UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *this,
        unsigned int newsize,
        const char *reason)
{
  __int64 v5; // rax
  bool v6; // cf
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  unsigned int v9; // ebx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v10; // rsi
  unsigned __int64 v11; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v12; // rax
  UFG::SimComponent *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p; // rcx
  UFG::SimComponent **p_m_pPointer; // rbx

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
      LODWORD(v8->mNext) = newsize;
      v10 = (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v8[1];
      `eh vector constructor iterator(
        &v8[1],
        0x18ui64,
        newsize,
        (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
    }
    else
    {
      v10 = 0i64;
    }
    if ( this->p )
    {
      if ( this->size )
      {
        do
        {
          v11 = v9;
          v12 = &v10[v11];
          m_pPointer = this->p[v11].m_pPointer;
          if ( v10[v11].m_pPointer )
          {
            mPrev = v12->mPrev;
            mNext = v12->mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            v12->mPrev = v12;
            v12->mNext = v12;
          }
          v12->m_pPointer = m_pPointer;
          if ( m_pPointer )
          {
            v16 = m_pPointer->m_SafePointerList.mNode.mPrev;
            v16->mNext = v12;
            v12->mPrev = v16;
            v12->mNext = &m_pPointer->m_SafePointerList.mNode;
            m_pPointer->m_SafePointerList.mNode.mPrev = v12;
          }
          ++v9;
        }
        while ( v9 < this->size );
      }
      p = this->p;
      if ( p )
      {
        p_m_pPointer = &p[-1].m_pPointer;
        `eh vector destructor iterator(
          p,
          0x18ui64,
          (int)p[-1].m_pPointer,
          (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
        operator delete[](p_m_pPointer);
      }
    }
    this->p = v10;
    this->capacity = newsize;
  }
}

// File Line: 152
// RVA: 0x9ADA0
void __fastcall UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::~qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>(
        UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *this)
{
  DNA::DNAPropertyBagSerializer::CreateContext *p; // rcx
  unsigned int *p_mStringHash32; // rbx

  p = this->p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mName.mStringHash32;
    `eh vector destructor iterator(
      p,
      0x40ui64,
      p[-1].mName.mStringHash32,
      (void (__fastcall *)(void *))DNA::DNAPropertyBagSerializer::CreateContext::~CreateContext);
    operator delete[](p_mStringHash32);
  }
  this->p = 0i64;
  *(_QWORD *)&this->size = 0i64;
}

// File Line: 253
// RVA: 0x41A1D0
UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *__fastcall UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *this,
        UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *item,
        const char *reason)
{
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v8; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p; // rdx
  UFG::SimComponent *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax

  size = this->size;
  capacity = this->capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v6; v8 *= 2 )
      ;
    if ( v8 - v6 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
      (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)this,
      v8,
      reason);
  }
  p = this->p;
  this->size = v6;
  m_pPointer = item->m_pPointer;
  v11 = &p[size];
  if ( v11->m_pPointer )
  {
    mPrev = v11->mPrev;
    mNext = v11->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v11->mPrev = v11;
    v11->mNext = v11;
  }
  v11->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v14 = m_pPointer->m_SafePointerList.mNode.mPrev;
    v14->mNext = v11;
    v11->mPrev = v14;
    v11->mNext = &m_pPointer->m_SafePointerList.mNode;
    m_pPointer->m_SafePointerList.mNode.mPrev = v11;
  }
  return &this->p[size];
}

// File Line: 393
// RVA: 0x355E70
void __fastcall UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0>::FastDelete(
        UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0> *this,
        unsigned int index)
{
  UFG::AICoverQuery::CoverQueryRecord *v2; // r10
  UFG::AICoverQuery::CoverQueryRecord *v3; // r9
  UFG::CoverPosition *m_pCoverPosition; // rax

  v2 = &this->p[index];
  v3 = &this->p[this->size - 1];
  m_pCoverPosition = v3->m_pCoverPosition;
  v2->m_pCoverPosition = m_pCoverPosition;
  if ( m_pCoverPosition )
    ++m_pCoverPosition->m_iRefCount;
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

