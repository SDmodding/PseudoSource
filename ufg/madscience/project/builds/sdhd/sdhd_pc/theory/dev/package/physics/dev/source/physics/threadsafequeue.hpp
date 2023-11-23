// File Line: 18
// RVA: 0x9A670
void __fastcall UFG::ThreadSafeQueue<UFG::CollisionEvent>::~ThreadSafeQueue<UFG::CollisionEvent>(
        UFG::ThreadSafeQueue<UFG::CollisionEvent> *this)
{
  UFG::QueueNode<UFG::CollisionEvent> *p_tail; // r14
  bool v3; // di
  UFG::CollisionEvent *data; // rsi
  bool v5; // di
  UFG::QueueNode<UFG::CollisionEvent> *prev; // rcx
  UFG::QueueNode<UFG::CollisionEvent> *v7; // rax
  bool v8; // di

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  p_tail = &this->tail;
  v3 = this->head.next == &this->tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mutex);
  if ( !v3 )
  {
    do
    {
      data = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
      v5 = this->head.next == p_tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mutex);
      if ( !v5 )
      {
        prev = p_tail->prev;
        v7 = p_tail->prev->prev;
        v7->next = p_tail;
        p_tail->prev = v7;
        data = prev->data;
        operator delete[](prev);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mutex);
      if ( data )
        data->vfptr->__vecDelDtor(data, 1u);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
      v8 = this->head.next == p_tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mutex);
    }
    while ( !v8 );
  }
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mutex);
}

// File Line: 41
// RVA: 0xA0680
void __fastcall UFG::ThreadSafeQueue<hkpEntity>::AddHead(
        UFG::ThreadSafeQueue<UFG::CollisionEvent> *this,
        UFG::CollisionEvent *t)
{
  UFG::QueueNode<UFG::CollisionEvent> *next; // rbx
  UFG::QueueNode<UFG::CollisionEvent> *v5; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  next = this->head.next;
  v5 = (UFG::QueueNode<UFG::CollisionEvent> *)UFG::qMalloc(0x18ui64, "QueueNode", 0i64);
  v5->data = t;
  v5->prev = &this->head;
  v5->next = next;
  next->prev = v5;
  this->head.next = v5;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mutex);
}

// File Line: 58
// RVA: 0xAFD90
UFG::BreakoffPart *__fastcall UFG::ThreadSafeQueue<UFG::BreakoffPart>::RemoveTail(
        UFG::ThreadSafeQueue<UFG::BreakoffPart> *this)
{
  _RTL_CRITICAL_SECTION *p_mutex; // rbp
  UFG::ThreadSafeQueue<UFG::BreakoffPart> *v2; // rbx
  UFG::BreakoffPart *data; // rsi
  UFG::QueueNode<UFG::BreakoffPart> *p_tail; // rdi
  UFG::QueueNode<UFG::BreakoffPart> *prev; // rcx
  UFG::QueueNode<UFG::BreakoffPart> *v6; // rax

  p_mutex = (_RTL_CRITICAL_SECTION *)&this->mutex;
  v2 = this;
  data = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  UFG::qMutex::Lock(p_mutex);
  p_tail = &v2->tail;
  LOBYTE(v2) = v2->head.next == &v2->tail;
  UFG::qMutex::Unlock(p_mutex);
  if ( !(_BYTE)v2 )
  {
    prev = p_tail->prev;
    v6 = p_tail->prev->prev;
    v6->next = p_tail;
    p_tail->prev = v6;
    data = prev->data;
    operator delete[](prev);
  }
  UFG::qMutex::Unlock(p_mutex);
  return data;
}

// File Line: 79
// RVA: 0xACB90
_BOOL8 __fastcall UFG::ThreadSafeQueue<UFG::BreakoffPart>::IsAlreadyInQueue(
        UFG::ThreadSafeQueue<UFG::BreakoffPart> *this,
        UFG::BreakoffPart *t)
{
  _RTL_CRITICAL_SECTION *p_mutex; // rbp
  UFG::QueueNode<UFG::BreakoffPart> *next; // rax
  UFG::QueueNode<UFG::BreakoffPart> *p_tail; // rbx
  bool i; // di
  UFG::BreakoffPart *data; // rdx

  p_mutex = (_RTL_CRITICAL_SECTION *)&this->mutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mutex);
  next = this->head.next;
  p_tail = &this->tail;
  for ( i = 0; next != p_tail; next = next->next )
  {
    if ( i )
      break;
    data = next->data;
    if ( data && t )
      i = data->breakingRigidBody == t->breakingRigidBody && data->shapeKey == t->shapeKey;
  }
  UFG::qMutex::Unlock(p_mutex);
  return i;
}

