// File Line: 42
// RVA: 0x630A0
void __fastcall UFG::qSafePointerBase<UFG::SimComponent>::~qSafePointerBase<UFG::SimComponent>(UFG::qSafePointerBase<UFG::SimComponent> *this)
{
  UFG::qSafePointerBase<UFG::SimComponent> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  if ( this->m_pPointer )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mPrev;
  }
  this->m_pPointer = 0i64;
  v4 = this->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

// File Line: 85
// RVA: 0x2E6340
UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *__fastcall UFG::qSafePointer<Creature,Creature>::operator=(UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *this, UFG::SimComponent *pointer)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  if ( this->m_pPointer )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mPrev;
  }
  this->m_pPointer = pointer;
  if ( pointer )
  {
    v4 = pointer->m_SafePointerList.mNode.mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mPrev = v4;
    this->mNext = &pointer->m_SafePointerList.mNode;
    pointer->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mPrev;
  }
  return this;
}

// File Line: 86
// RVA: 0x1C4AF0
UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *__fastcall UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *this, UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *safe_pointer)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // r8
  UFG::SimComponent *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx

  v2 = this;
  v3 = safe_pointer->m_pPointer;
  if ( v2->m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = v3;
  if ( v3 )
  {
    v6 = v3->m_SafePointerList.mNode.mPrev;
    v7 = &v3->m_SafePointerList.mNode;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mPrev = v6;
    v2->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  return v2;
}

// File Line: 159
// RVA: 0x3F2800
void __fastcall UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>::~qSafePointerWithCallbacksBase<UFG::EncounterBase>(UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase> *this)
{
  UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase> *v1; // rbx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  if ( this->m_pPointer )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->m_Changed = 1;
    if ( *(_OWORD *)&this->m_UnbindCallback != 0i64 )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::EncounterBase *))this->m_UnbindCallback.m_Closure.m_pFunction)(
        this->m_UnbindCallback.m_Closure.m_pthis,
        this->m_pPointer);
  }
  v1->m_pPointer = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

// File Line: 199
// RVA: 0x6424C0
void __fastcall UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>(UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle> *this)
{
  this->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  this->m_BindCallback.m_Closure.m_pthis = 0i64;
  this->m_BindCallback.m_Closure.m_pFunction = 0i64;
  this->m_UnbindCallback.m_Closure.m_pthis = 0i64;
  this->m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  this->m_pPointer = 0i64;
  this->m_Changed = 0;
}

// File Line: 201
// RVA: 0x4CB3F0
void __fastcall UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>(UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject> *this, UFG::SimObject *pointer)
{
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rax

  this->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  this->m_BindCallback.m_Closure.m_pthis = 0i64;
  this->m_BindCallback.m_Closure.m_pFunction = 0i64;
  this->m_UnbindCallback.m_Closure.m_pthis = 0i64;
  this->m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  this->m_pPointer = pointer;
  this->m_Changed = 0;
  if ( pointer )
  {
    v2 = pointer->m_SafePointerWithCallbackList.mNode.mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mPrev = v2;
    this->mNext = &pointer->m_SafePointerWithCallbackList.mNode;
    pointer->m_SafePointerWithCallbackList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->m_Changed = 1;
    if ( *(_OWORD *)&this->m_BindCallback != 0i64 )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *))this->m_BindCallback.m_Closure.m_pFunction)(
        this->m_BindCallback.m_Closure.m_pthis,
        this->m_pPointer);
  }
}

// File Line: 231
// RVA: 0x3F9250
UFG::EncounterBase *__fastcall UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *this, UFG::EncounterBase *pointer)
{
  UFG::EncounterBase *v2; // rdi
  UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *v3; // rbx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v5; // rax
  fastdelegate::detail::GenericClass *v6; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v7; // rax
  fastdelegate::detail::GenericClass *v8; // rcx

  v2 = pointer;
  v3 = this;
  if ( this->m_pPointer )
  {
    v4 = this->mPrev;
    v5 = this->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    this->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->m_Changed = 1;
    v6 = this->m_UnbindCallback.m_Closure.m_pthis;
    if ( v6 || v3->m_UnbindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::EncounterBase *))v3->m_UnbindCallback.m_Closure.m_pFunction)(
        v6,
        v3->m_pPointer);
  }
  v3->m_pPointer = v2;
  if ( v2 )
  {
    v7 = v2->m_SafePointerWithCallbackList.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mPrev = v7;
    v3->mNext = &v2->m_SafePointerWithCallbackList.mNode;
    v2->m_SafePointerWithCallbackList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->m_Changed = 1;
    v8 = v3->m_BindCallback.m_Closure.m_pthis;
    if ( v8 || v3->m_BindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::EncounterBase *))v3->m_BindCallback.m_Closure.m_pFunction)(
        v8,
        v3->m_pPointer);
  }
  return v2;
}

// File Line: 306
// RVA: 0x4480A0
void __fastcall UFG::qSafePointerNode<UFG::RagdollComponent>::qSafePointerNode<UFG::RagdollComponent>(UFG::qSafePointerNode<UFG::RagdollComponent> *this)
{
  UFG::qList<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList,1,0> *v1; // r8
  UFG::qSafePointerNode<UFG::RagdollComponent> *v2; // rax
  UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *v4; // rcx

  this->vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)&UFG::qSafePointerNode<UFG::RagdollComponent>::`vftable';
  v1 = &this->m_SafePointerList;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  v2 = (UFG::qSafePointerNode<UFG::RagdollComponent> *)this->m_SafePointerList.mNode.mNext;
  if ( v2 != (UFG::qSafePointerNode<UFG::RagdollComponent> *)&this->m_SafePointerList )
  {
    do
    {
      v3 = v2->vfptr;
      v4 = v2->m_SafePointerList.mNode.mPrev;
      v3[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::RagdollComponent> *, unsigned int))v4;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)v3;
      v2->vfptr = (UFG::qSafePointerNode<UFG::RagdollComponent>Vtbl *)v2;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollComponent>,UFG::qSafePointerNodeList> *)v2;
      v2 = (UFG::qSafePointerNode<UFG::RagdollComponent> *)v1->mNode.mNext;
    }
    while ( v2 != (UFG::qSafePointerNode<UFG::RagdollComponent> *)v1 );
  }
}

// File Line: 307
// RVA: 0x39EC40
void __fastcall UFG::qSafePointerNode<Creature>::~qSafePointerNode<Creature>(UFG::qSafePointerNode<Creature> *this)
{
  UFG::qSafePointerNode<Creature> *v1; // rbx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&UFG::qSafePointerNode<Creature>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  v4 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v2 = v1->m_SafePointerList.mNode.mPrev;
  v3 = v1->m_SafePointerList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 322
// RVA: 0x416580
void __fastcall UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(UFG::qSafePointerNode<UFG::ParkourHandle> *this)
{
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v1; // r8
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx

  v1 = &this->m_SafePointerList;
  v2 = this;
  if ( (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)this->m_SafePointerList.mNode.mNext != &this->m_SafePointerList )
  {
    while ( 1 )
    {
      v3 = v2->m_SafePointerList.mNode.mNext;
      if ( (unsigned __int64)v3 < 0x10 )
        break;
      if ( v3[1].mPrev
        || (v4 = v3->mPrev, v5 = v3->mNext, v4->mNext = v5, v5->mPrev = v4, v3->mPrev = v3, v3->mNext = v3, v3[1].mPrev) )
      {
        v6 = v3->mPrev;
        v7 = v3->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v3->mPrev = v3;
        v3->mNext = v3;
      }
      v3[1].mPrev = 0i64;
      if ( (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)v1->mNode.mNext == v1 )
        return;
    }
    v1->mNode.mPrev = &v1->mNode;
    v1->mNode.mNext = &v1->mNode;
  }
}

// File Line: 355
// RVA: 0x3F21E0
void __fastcall UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::qSafePointerNodeWithCallbacks<UFG::EncounterBase>(UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *this)
{
  UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *v1; // rbx
  UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList,1,0> *v2; // r8
  UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList,1,0> *v3; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v5; // rcx

  v1 = this;
  UFG::qSafePointerNode<UFG::EncounterBase>::qSafePointerNode<UFG::EncounterBase>((UFG::qSafePointerNode<UFG::EncounterBase> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::`vftable';
  v2 = &v1->m_SafePointerWithCallbackList;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v3 = (UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList,1,0> *)v1->m_SafePointerWithCallbackList.mNode.mNext;
  if ( v3 != &v1->m_SafePointerWithCallbackList )
  {
    do
    {
      v4 = v3->mNode.mPrev;
      v5 = v3->mNode.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mNode.mPrev = &v3->mNode;
      v3->mNode.mNext = &v3->mNode;
      v3 = (UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList,1,0> *)v1->m_SafePointerWithCallbackList.mNode.mNext;
    }
    while ( v3 != v2 );
  }
}

// File Line: 356
// RVA: 0x5B1CE0
void __fastcall UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::~qSafePointerNodeWithCallbacks<UFG::SpawnRegion>(UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion> *this)
{
  UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion> *v1; // rdi
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::`vftable';
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::SetAllPointersToNull((UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *)this);
  UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::SpawnRegion>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerWithCallbackList);
  v2 = v1->m_SafePointerWithCallbackList.mNode.mPrev;
  v3 = v1->m_SafePointerWithCallbackList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->m_SafePointerWithCallbackList.mNode.mPrev = &v1->m_SafePointerWithCallbackList.mNode;
  v1->m_SafePointerWithCallbackList.mNode.mNext = &v1->m_SafePointerWithCallbackList.mNode;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::qSafePointerNode<UFG::SpawnRegion>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v4 = v1->m_SafePointerList.mNode.mPrev;
  v5 = v1->m_SafePointerList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
}

// File Line: 371
// RVA: 0x5B57A0
void __fastcall UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::SetAllPointersToNull(UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *this)
{
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *v1; // rsi
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rbx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx

  v1 = this;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  if ( (UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *)v1->m_SafePointerWithCallbackList.mNode.mNext != &v1->m_SafePointerWithCallbackList )
  {
    while ( 1 )
    {
      v2 = v1->m_SafePointerWithCallbackList.mNode.mNext;
      if ( (unsigned int)v2 < 0x10 )
        break;
      if ( v2[1].mPrev
        || (v3 = v2->mPrev, v4 = v2->mNext, v3->mNext = v4, v4->mPrev = v3, v2->mPrev = v2, v2->mNext = v2, v2[1].mPrev) )
      {
        v5 = v2->mPrev;
        v6 = v2->mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v2->mPrev = v2;
        v2->mNext = v2;
        LODWORD(v2[1].mNext) = 1;
        v7 = v2[3].mPrev;
        if ( v7 || v2[3].mNext )
          ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *, UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *))v2[3].mNext)(
            v7,
            v2[1].mPrev);
      }
      v2[1].mPrev = 0i64;
      if ( (UFG::qList<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *)v1->m_SafePointerWithCallbackList.mNode.mNext == &v1->m_SafePointerWithCallbackList )
        return;
    }
    v1->m_SafePointerWithCallbackList.mNode.mPrev = &v1->m_SafePointerWithCallbackList.mNode;
    v1->m_SafePointerWithCallbackList.mNode.mNext = &v1->m_SafePointerWithCallbackList.mNode;
  }
}

