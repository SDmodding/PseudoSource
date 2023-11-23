// File Line: 42
// RVA: 0x630A0
void __fastcall UFG::qSafePointerBase<UFG::SimComponent>::~qSafePointerBase<UFG::SimComponent>(
        UFG::qSafePointerBase<UFG::SimComponent> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  this->m_pPointer = 0i64;
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 85
// RVA: 0x2E6340
UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *__fastcall UFG::qSafePointer<Creature,Creature>::operator=(
        UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *this,
        UFG::SimComponent *pointer)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  this->m_pPointer = pointer;
  if ( pointer )
  {
    v4 = pointer->m_SafePointerList.mNode.mPrev;
    v4->mNext = this;
    this->mPrev = v4;
    this->mNext = &pointer->m_SafePointerList.mNode;
    pointer->m_SafePointerList.mNode.mPrev = this;
  }
  return this;
}

// File Line: 86
// RVA: 0x1C4AF0
UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *__fastcall UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
        UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *this,
        UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *safe_pointer)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx

  m_pPointer = safe_pointer->m_pPointer;
  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  this->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v6 = m_pPointer->m_SafePointerList.mNode.mPrev;
    p_mNode = &m_pPointer->m_SafePointerList.mNode;
    v6->mNext = this;
    this->mPrev = v6;
    this->mNext = p_mNode;
    p_mNode->mPrev = this;
  }
  return this;
}

// File Line: 159
// RVA: 0x3F2800
void __fastcall UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>::~qSafePointerWithCallbacksBase<UFG::EncounterBase>(
        UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase> *this)
{
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    this->m_Changed = 1;
    if ( this->m_UnbindCallback.m_Closure.m_pthis || this->m_UnbindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::EncounterBase *))this->m_UnbindCallback.m_Closure.m_pFunction)(
        this->m_UnbindCallback.m_Closure.m_pthis,
        this->m_pPointer);
  }
  this->m_pPointer = 0i64;
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 199
// RVA: 0x6424C0
void __fastcall UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>(
        UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle> *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->m_BindCallback.m_Closure.m_pthis = 0i64;
  this->m_BindCallback.m_Closure.m_pFunction = 0i64;
  this->m_UnbindCallback.m_Closure.m_pthis = 0i64;
  this->m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  this->m_pPointer = 0i64;
  this->m_Changed = 0;
}

// File Line: 201
// RVA: 0x4CB3F0
void __fastcall UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>(
        UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject> *this,
        UFG::SimObject *pointer)
{
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax

  this->mPrev = this;
  this->mNext = this;
  this->m_BindCallback.m_Closure.m_pthis = 0i64;
  this->m_BindCallback.m_Closure.m_pFunction = 0i64;
  this->m_UnbindCallback.m_Closure.m_pthis = 0i64;
  this->m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  this->m_pPointer = pointer;
  this->m_Changed = 0;
  if ( pointer )
  {
    mPrev = pointer->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
    mPrev->mNext = this;
    this->mPrev = mPrev;
    this->mNext = &pointer->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode;
    pointer->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev = this;
    this->m_Changed = 1;
    if ( *(_OWORD *)&this->m_BindCallback != 0i64 )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *))this->m_BindCallback.m_Closure.m_pFunction)(
        this->m_BindCallback.m_Closure.m_pthis,
        this->m_pPointer);
  }
}

// File Line: 231
// RVA: 0x3F9250
UFG::EncounterBase *__fastcall UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
        UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *this,
        UFG::EncounterBase *pointer)
{
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mNext; // rax
  fastdelegate::detail::GenericClass *m_pthis; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v7; // rax
  fastdelegate::detail::GenericClass *v8; // rcx

  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    this->m_Changed = 1;
    m_pthis = this->m_UnbindCallback.m_Closure.m_pthis;
    if ( m_pthis || this->m_UnbindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::EncounterBase *))this->m_UnbindCallback.m_Closure.m_pFunction)(
        m_pthis,
        this->m_pPointer);
  }
  this->m_pPointer = pointer;
  if ( pointer )
  {
    v7 = pointer->m_SafePointerWithCallbackList.mNode.mPrev;
    v7->mNext = this;
    this->mPrev = v7;
    this->mNext = &pointer->m_SafePointerWithCallbackList.mNode;
    pointer->m_SafePointerWithCallbackList.mNode.mPrev = this;
    this->m_Changed = 1;
    v8 = this->m_BindCallback.m_Closure.m_pthis;
    if ( v8 || this->m_BindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::EncounterBase *))this->m_BindCallback.m_Closure.m_pFunction)(
        v8,
        this->m_pPointer);
  }
  return pointer;
}

// File Line: 306
// RVA: 0x4480A0
void __fastcall UFG::qSafePointerNode<UFG::RagdollComponent>::qSafePointerNode<UFG::RagdollComponent>(
        UFG::qSafePointerNode<UFG::RagdollComponent> *this)
{
  UFG::qList<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // r8
  UFG::qSafePointerNode<UFG::RagdollComponent> *mNext; // rax
  UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *vfptr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx

  this->vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)&UFG::qSafePointerNode<UFG::RagdollComponent>::`vftable;
  p_m_SafePointerList = &this->m_SafePointerList;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  mNext = (UFG::qSafePointerNode<UFG::RagdollComponent> *)this->m_SafePointerList.mNode.mNext;
  if ( mNext != (UFG::qSafePointerNode<UFG::RagdollComponent> *)&this->m_SafePointerList )
  {
    do
    {
      vfptr = mNext->vfptr;
      mPrev = mNext->m_SafePointerList.mNode.mPrev;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::RagdollComponent> *, unsigned int))mPrev;
      mPrev->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)vfptr;
      mNext->vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)mNext;
      mNext->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)mNext;
      mNext = (UFG::qSafePointerNode<UFG::RagdollComponent> *)p_m_SafePointerList->mNode.mNext;
    }
    while ( mNext != (UFG::qSafePointerNode<UFG::RagdollComponent> *)p_m_SafePointerList );
  }
}

// File Line: 307
// RVA: 0x39EC40
void __fastcall UFG::qSafePointerNode<Creature>::~qSafePointerNode<Creature>(UFG::qSafePointerNode<Creature> *this)
{
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rax

  this->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&UFG::qSafePointerNode<Creature>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  mPrev = this->m_SafePointerList.mNode.mPrev;
  mNext = this->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 322
// RVA: 0x416580
void __fastcall UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(
        UFG::qSafePointerNode<UFG::ParkourHandle> *this)
{
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx

  p_m_SafePointerList = &this->m_SafePointerList;
  if ( (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)this->m_SafePointerList.mNode.mNext != &this->m_SafePointerList )
  {
    while ( 1 )
    {
      mNext = this->m_SafePointerList.mNode.mNext;
      if ( (unsigned __int64)mNext < 0x10 )
        break;
      if ( mNext[1].mPrev
        || (v4 = mNext->mPrev,
            v5 = mNext->mNext,
            v4->mNext = v5,
            v5->mPrev = v4,
            mNext->mPrev = mNext,
            mNext->mNext = mNext,
            mNext[1].mPrev) )
      {
        mPrev = mNext->mPrev;
        v7 = mNext->mNext;
        mPrev->mNext = v7;
        v7->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
      }
      mNext[1].mPrev = 0i64;
      if ( (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)p_m_SafePointerList->mNode.mNext == p_m_SafePointerList )
        return;
    }
    p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
    p_m_SafePointerList->mNode.mNext = &p_m_SafePointerList->mNode;
  }
}

// File Line: 355
// RVA: 0x3F21E0
void __fastcall UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::qSafePointerNodeWithCallbacks<UFG::EncounterBase>(
        UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *this)
{
  UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *i; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mPrev; // rcx

  UFG::qSafePointerNode<UFG::EncounterBase>::qSafePointerNode<UFG::EncounterBase>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::`vftable;
  this->m_SafePointerWithCallbackList.mNode.mPrev = &this->m_SafePointerWithCallbackList.mNode;
  this->m_SafePointerWithCallbackList.mNode.mNext = &this->m_SafePointerWithCallbackList.mNode;
  for ( i = (UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *)this->m_SafePointerWithCallbackList.mNode.mNext;
        i != (UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *)&this->m_SafePointerWithCallbackList;
        i = (UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *)this->m_SafePointerWithCallbackList.mNode.mNext )
  {
    vfptr = i->vfptr;
    mPrev = i->m_SafePointerList.mNode.mPrev;
    vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::EncounterBase> *, unsigned int))mPrev;
    mPrev->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)vfptr;
    i->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)i;
    i->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)i;
  }
}

// File Line: 356
// RVA: 0x5B1CE0
void __fastcall UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::~qSafePointerNodeWithCallbacks<UFG::SpawnRegion>(
        UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion> *this)
{
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *v5; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::`vftable;
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::SetAllPointersToNull((UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *)this);
  UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerWithCallbackList);
  mPrev = this->m_SafePointerWithCallbackList.mNode.mPrev;
  mNext = this->m_SafePointerWithCallbackList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerWithCallbackList.mNode.mPrev = &this->m_SafePointerWithCallbackList.mNode;
  this->m_SafePointerWithCallbackList.mNode.mNext = &this->m_SafePointerWithCallbackList.mNode;
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::qSafePointerNode<UFG::SpawnRegion>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v4 = this->m_SafePointerList.mNode.mPrev;
  v5 = this->m_SafePointerList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 371
// RVA: 0x5B57A0
void __fastcall UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::SetAllPointersToNull(
        UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *this)
{
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rbx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx

  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  if ( (UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *)this->m_SafePointerWithCallbackList.mNode.mNext != &this->m_SafePointerWithCallbackList )
  {
    while ( 1 )
    {
      mNext = this->m_SafePointerWithCallbackList.mNode.mNext;
      if ( (unsigned int)mNext < 0x10 )
        break;
      if ( mNext[1].mPrev
        || (v3 = mNext->mPrev,
            v4 = mNext->mNext,
            v3->mNext = v4,
            v4->mPrev = v3,
            mNext->mPrev = mNext,
            mNext->mNext = mNext,
            mNext[1].mPrev) )
      {
        mPrev = mNext->mPrev;
        v6 = mNext->mNext;
        mPrev->mNext = v6;
        v6->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        LODWORD(mNext[1].mNext) = 1;
        v7 = mNext[3].mPrev;
        if ( v7 || mNext[3].mNext )
          ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *, UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *))mNext[3].mNext)(
            v7,
            mNext[1].mPrev);
      }
      mNext[1].mPrev = 0i64;
      if ( (UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *)this->m_SafePointerWithCallbackList.mNode.mNext == &this->m_SafePointerWithCallbackList )
        return;
    }
    this->m_SafePointerWithCallbackList.mNode.mPrev = &this->m_SafePointerWithCallbackList.mNode;
    this->m_SafePointerWithCallbackList.mNode.mNext = &this->m_SafePointerWithCallbackList.mNode;
  }
}

