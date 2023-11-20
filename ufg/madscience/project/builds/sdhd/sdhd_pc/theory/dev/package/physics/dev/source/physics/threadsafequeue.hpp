// File Line: 18
// RVA: 0x9A670
void __fastcall UFG::ThreadSafeQueue<UFG::CollisionEvent>::~ThreadSafeQueue<UFG::CollisionEvent>(UFG::ThreadSafeQueue<UFG::CollisionEvent> *this)
{
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v1; // rbp
  UFG::QueueNode<UFG::CollisionEvent> *v2; // r14
  bool v3; // di
  UFG::CollisionEvent *v4; // rsi
  bool v5; // di
  UFG::QueueNode<UFG::CollisionEvent> *v6; // rcx
  UFG::QueueNode<UFG::CollisionEvent> *v7; // rax
  bool v8; // di

  v1 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  v2 = &v1->tail;
  v3 = v1->head.next == &v1->tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
  if ( !v3 )
  {
    do
    {
      v4 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mutex);
      v5 = v1->head.next == v2;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
      if ( !v5 )
      {
        v6 = v2->prev;
        v7 = v2->prev->prev;
        v7->next = v2;
        v2->prev = v7;
        v4 = v6->data;
        operator delete[](v6);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
      if ( v4 )
        v4->vfptr->__vecDelDtor((UFG::Event *)&v4->vfptr, 1u);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mutex);
      v8 = v1->head.next == v2;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
    }
    while ( !v8 );
  }
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mutex);
}

// File Line: 41
// RVA: 0xA0680
void __fastcall UFG::ThreadSafeQueue<hkpEntity>::AddHead(UFG::ThreadSafeQueue<UFG::CollisionEvent> *this, UFG::CollisionEvent *t)
{
  UFG::CollisionEvent *v2; // rdi
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v3; // rbp
  _QWORD *v4; // rbx
  char *v5; // rax

  v2 = t;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  v4 = &v3->head.next->prev;
  v5 = UFG::qMalloc(0x18ui64, "QueueNode", 0i64);
  *((_QWORD *)v5 + 2) = v2;
  *(_QWORD *)v5 = v3;
  *((_QWORD *)v5 + 1) = v4;
  *v4 = v5;
  v3->head.next = (UFG::QueueNode<UFG::CollisionEvent> *)v5;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mutex);
}

// File Line: 58
// RVA: 0xAFD90
UFG::BreakoffPart *__fastcall UFG::ThreadSafeQueue<UFG::BreakoffPart>::RemoveTail(UFG::ThreadSafeQueue<UFG::BreakoffPart> *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbp
  UFG::ThreadSafeQueue<UFG::BreakoffPart> *v2; // rbx
  UFG::BreakoffPart *v3; // rsi
  UFG::QueueNode<UFG::BreakoffPart> *v4; // rdi
  UFG::QueueNode<UFG::BreakoffPart> *v5; // rcx
  UFG::QueueNode<UFG::BreakoffPart> *v6; // rax

  v1 = (_RTL_CRITICAL_SECTION *)&this->mutex;
  v2 = this;
  v3 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  UFG::qMutex::Lock(v1);
  v4 = &v2->tail;
  LOBYTE(v2) = v2->head.next == &v2->tail;
  UFG::qMutex::Unlock(v1);
  if ( !(_BYTE)v2 )
  {
    v5 = v4->prev;
    v6 = v4->prev->prev;
    v6->next = v4;
    v4->prev = v6;
    v3 = v5->data;
    operator delete[](v5);
  }
  UFG::qMutex::Unlock(v1);
  return v3;
}

// File Line: 79
// RVA: 0xACB90
_BOOL8 __fastcall UFG::ThreadSafeQueue<UFG::BreakoffPart>::IsAlreadyInQueue(UFG::ThreadSafeQueue<UFG::BreakoffPart> *this, UFG::BreakoffPart *t)
{
  _RTL_CRITICAL_SECTION *v2; // rbp
  UFG::BreakoffPart *v3; // rsi
  UFG::ThreadSafeQueue<UFG::BreakoffPart> *v4; // rbx
  UFG::QueueNode<UFG::BreakoffPart> *v5; // rax
  signed __int64 v6; // rbx
  bool i; // di
  UFG::BreakoffPart *v8; // rdx

  v2 = (_RTL_CRITICAL_SECTION *)&this->mutex;
  v3 = t;
  v4 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  v5 = v4->head.next;
  v6 = (signed __int64)&v4->tail;
  for ( i = 0; v5 != (UFG::QueueNode<UFG::BreakoffPart> *)v6; v5 = v5->next )
  {
    if ( i )
      break;
    v8 = v5->data;
    if ( v8 && v3 )
      i = v8->breakingRigidBody == v3->breakingRigidBody && v8->shapeKey == v3->shapeKey;
  }
  UFG::qMutex::Unlock(v2);
  return i;
}

