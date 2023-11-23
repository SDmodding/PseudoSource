// File Line: 162
// RVA: 0x4E1760
const char *__fastcall UFG::TSActorComponent::GetTypeName(UFG::TSActorComponent *this)
{
  return "TSActorComponent";
}

// File Line: 176
// RVA: 0x4CB750
void __fastcall UFG::TSActorComponent::TSActorComponent(
        UFG::TSActorComponent *this,
        UFG::qSymbol *name,
        ASymbol *className)
{
  SSClass *v5; // rax
  SSActorClass *v6; // rbx

  UFG::SimComponent::SimComponent(this, name->mUID);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TSActorComponent::`vftable;
  this->mpActor.i_obj_p = 0i64;
  this->mpActor.i_ptr_id = 0;
  this->mpActorClass = 0i64;
  UFG::SimComponent::AddType(this, UFG::TSActorComponent::_TSActorComponentTypeUID, "TSActorComponent");
  v5 = SSBrain::get_class(className);
  v6 = (SSActorClass *)v5;
  if ( v5 && v5->vfptr->is_actor_class(v5) )
    this->mpActorClass = v6;
  else
    this->mpActorClass = SSBrain::c_actor_class_p;
}

// File Line: 223
// RVA: 0x4E0C50
UFG::TSActor *__fastcall UFG::TSActorComponent::GetActor(UFG::TSActorComponent *this)
{
  UFG::TSActor *i_obj_p; // rcx
  UFG::SimObject *m_pSimObject; // rsi
  SSActorClass *mpActorClass; // rdi
  SSClass *v6; // rcx
  SSClass *i_superclass_p; // rcx
  SSActor *v8; // rax
  UFG::TSActor *v9; // rdi
  unsigned int i_ptr_id; // eax
  UFG::TSVehicle *v11; // rax
  unsigned int v12; // ecx
  UFG::TSActor *v13; // rcx
  UFG::TSActor *v14; // rcx
  UFG::TSActor *v15; // rcx
  UFG::TSActor *v16; // rcx
  ASymbol name; // [rsp+50h] [rbp+8h] BYREF
  UFG::TSVehicle *result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSimObj; // [rsp+60h] [rbp+18h]

  i_obj_p = this->mpActor.i_obj_p;
  if ( !i_obj_p || i_obj_p->i_ptr_id != this->mpActor.i_ptr_id )
  {
    m_pSimObject = this->m_pSimObject;
    if ( (m_pSimObject->m_Flags & 2) != 0 )
      return 0i64;
    name.i_uid = UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, this->m_NameUID)->mUID;
    mpActorClass = this->mpActorClass;
    if ( UFG::TSVehicle::mClass == mpActorClass
      || (v6 = mpActorClass->i_superclass_p) != 0i64 && SSClass::is_class(v6, UFG::TSVehicle::mClass) )
    {
      v11 = (UFG::TSVehicle *)AMemory::c_malloc_func(0x140ui64, "TSVehicle");
      result = v11;
      if ( v11 )
        UFG::TSVehicle::TSVehicle(v11, &name);
    }
    else
    {
      if ( UFG::SkookumMgr::mspCharacterClass != mpActorClass )
      {
        i_superclass_p = mpActorClass->i_superclass_p;
        if ( !i_superclass_p || !SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass) )
        {
          v8 = (SSActor *)AMemory::c_malloc_func(0xD8ui64, "TSActor");
          v9 = (UFG::TSActor *)v8;
          result = (UFG::TSVehicle *)v8;
          if ( v8 )
          {
            SSActor::SSActor(v8, &name, this->mpActorClass, 1);
            v9->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
            UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v9->mTransformNodeComponent);
            v9->mpComponent = 0i64;
            v9->m_audioController.m_pEvent = 0i64;
            p_mpSimObj = &v9->mpSimObj;
            v9->mpSimObj.mPrev = &v9->mpSimObj;
            v9->mpSimObj.mNext = &v9->mpSimObj;
            v9->mpSimObj.m_pPointer = 0i64;
          }
          else
          {
            v9 = 0i64;
          }
          this->mpActor.i_obj_p = v9;
          if ( v9 )
            i_ptr_id = v9->i_ptr_id;
          else
            i_ptr_id = 0;
          this->mpActor.i_ptr_id = i_ptr_id;
LABEL_27:
          v13 = this->mpActor.i_obj_p;
          if ( !v13 || this->mpActor.i_ptr_id != v13->i_ptr_id )
            v13 = 0i64;
          v13->mpComponent = this;
          v14 = this->mpActor.i_obj_p;
          if ( !v14 || this->mpActor.i_ptr_id != v14->i_ptr_id )
            v14 = 0i64;
          ++v14->i_ref_count;
          v15 = this->mpActor.i_obj_p;
          if ( !v15 || this->mpActor.i_ptr_id != v15->i_ptr_id )
            v15 = 0i64;
          ((void (__fastcall *)(UFG::TSActor *, UFG::SimObject *))v15->vfptr[2].is_actor)(v15, m_pSimObject);
          goto LABEL_37;
        }
      }
      v11 = (UFG::TSVehicle *)AMemory::c_malloc_func(0x1E0ui64, "TSCharacter");
      result = v11;
      if ( v11 )
        UFG::TSCharacter::TSCharacter((UFG::TSCharacter *)v11, &name, this->mpActorClass);
    }
    this->mpActor.i_obj_p = v11;
    if ( v11 )
      v12 = v11->i_ptr_id;
    else
      v12 = 0;
    this->mpActor.i_ptr_id = v12;
    goto LABEL_27;
  }
LABEL_37:
  v16 = this->mpActor.i_obj_p;
  if ( !v16 || this->mpActor.i_ptr_id != v16->i_ptr_id )
    return 0i64;
  return v16;
}

// File Line: 260
// RVA: 0x50F270
UFG::SimComponent *__fastcall UFG::TSActorComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  char *MemImagePtr; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // r14
  UFG::qSymbol *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rsi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+40h] [rbp-38h] BYREF
  UFG::qSymbol result; // [rsp+80h] [rbp+8h] BYREF
  UFG::allocator::free_link *v18; // [rsp+90h] [rbp+18h]

  mpWritableProperties = pSceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_TSActor::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x58ui64, "TSActorComponent", 0i64, 1u);
  v18 = v9;
  if ( v9 )
  {
    v10 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(
                            pSceneObject,
                            (UFG::qWiseSymbol *)&result);
    UFG::TSActorComponent::TSActorComponent((UFG::TSActorComponent *)v9, v10, (ASymbol *)MemImagePtr);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  m_pSimObject = pSceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v15 = 4;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v15 = 3;
  }
  else
  {
    v15 = -1;
    if ( (m_Flags & 0x1000) != 0 )
      v15 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v12, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v12;
}

// File Line: 286
// RVA: 0x4CB7E0
void __fastcall UFG::TSActorComponent::TSActorComponent(UFG::TSActorComponent *this, UFG::TSActor *pActor)
{
  UFG::TSActor *i_obj_p; // rcx

  UFG::SimComponent::SimComponent(this, pActor->i_name.i_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TSActorComponent::`vftable;
  this->mpActor.i_obj_p = pActor;
  this->mpActor.i_ptr_id = pActor->i_ptr_id;
  UFG::SimComponent::AddType(this, UFG::TSActorComponent::_TSActorComponentTypeUID, "TSActorComponent");
  i_obj_p = this->mpActor.i_obj_p;
  if ( !i_obj_p || this->mpActor.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_obj_p->mpComponent = this;
  ++pActor->i_ref_count;
}

// File Line: 313
// RVA: 0x50E840
void __fastcall UFG::TSActorComponent::OnAttach(UFG::TSActorComponent *this, UFG::SimObject *pSimObj)
{
  UFG::TSActor *i_obj_p; // rax
  unsigned int i_ptr_id; // r8d
  UFG::TSActor *v4; // rcx

  i_obj_p = this->mpActor.i_obj_p;
  if ( i_obj_p )
  {
    i_ptr_id = this->mpActor.i_ptr_id;
    if ( i_obj_p->i_ptr_id == i_ptr_id )
    {
      v4 = 0i64;
      if ( i_ptr_id == i_obj_p->i_ptr_id )
        v4 = i_obj_p;
      ((void (__fastcall *)(UFG::TSActor *, UFG::SimObject *))v4->vfptr[2].is_actor)(v4, pSimObj);
    }
  }
}

// File Line: 325
// RVA: 0x50EAA0
void __fastcall UFG::TSActorComponent::OnDetach(UFG::TSActorComponent *this)
{
  UFG::TSActor *i_obj_p; // rax
  unsigned int i_ptr_id; // edx
  UFG::TSActor *v4; // rcx

  i_obj_p = this->mpActor.i_obj_p;
  if ( i_obj_p )
  {
    i_ptr_id = this->mpActor.i_ptr_id;
    if ( i_obj_p->i_ptr_id == i_ptr_id )
    {
      v4 = 0i64;
      if ( i_ptr_id == i_obj_p->i_ptr_id )
        v4 = i_obj_p;
      v4->vfptr[2].as_instance(v4);
      this->mpActor.i_obj_p = 0i64;
      this->mpActor.i_ptr_id = 0;
    }
  }
}

// File Line: 338
// RVA: 0x510590
void __fastcall UFG::TSActorComponent::Suspend(UFG::TSActorComponent *this)
{
  UFG::TSActor *i_obj_p; // rdx
  unsigned int i_ptr_id; // r8d
  UFG::TSActor *v3; // rax

  this->m_Flags |= 2u;
  i_obj_p = this->mpActor.i_obj_p;
  if ( i_obj_p )
  {
    i_ptr_id = this->mpActor.i_ptr_id;
    if ( i_obj_p->i_ptr_id == i_ptr_id )
    {
      v3 = 0i64;
      if ( i_ptr_id == i_obj_p->i_ptr_id )
        v3 = this->mpActor.i_obj_p;
      v3->i_actor_flags &= ~4u;
    }
  }
}

// File Line: 352
// RVA: 0x50F620
void __fastcall UFG::TSActorComponent::Restore(UFG::TSActorComponent *this)
{
  UFG::TSActor *i_obj_p; // rdx
  unsigned int i_ptr_id; // r8d
  UFG::TSActor *v3; // rax

  this->m_Flags &= ~2u;
  i_obj_p = this->mpActor.i_obj_p;
  if ( i_obj_p )
  {
    i_ptr_id = this->mpActor.i_ptr_id;
    if ( i_obj_p->i_ptr_id == i_ptr_id )
    {
      v3 = 0i64;
      if ( i_ptr_id == i_obj_p->i_ptr_id )
        v3 = this->mpActor.i_obj_p;
      v3->i_actor_flags |= 4u;
    }
  }
}

// File Line: 389
// RVA: 0x15310B0
__int64 dynamic_initializer_for__UFG::StimulusNotifyScript::smDeleteList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StimulusNotifyScript::smDeleteList__);
}

// File Line: 390
// RVA: 0x1531090
__int64 dynamic_initializer_for__UFG::StimulusNotifyScript::smActiveList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StimulusNotifyScript::smActiveList__);
}

// File Line: 406
// RVA: 0x4CB600
void __fastcall UFG::StimulusNotifyScript::StimulusNotifyScript(
        UFG::StimulusNotifyScript *this,
        UFG::eStimulusType notify_type,
        SSInvokedCoroutine *pICoroutine,
        UFG::SimObject *pEmitter)
{
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v6; // rdi
  unsigned int i_ptr_id; // eax
  fastdelegate::detail::GenericClass *RCX; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *mPrev; // rax

  this->UFG::StimulusNotifyCallback::UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>::mPrev = &this->UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>;
  this->UFG::StimulusNotifyCallback::UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>::mNext = &this->UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>;
  this->vfptr = (UFG::StimulusNotifyCallbackVtbl *)&UFG::StimulusNotifyCallback::`vftable;
  this->m_type = notify_type;
  this->m_delegate.m_Closure.m_pthis = 0i64;
  this->m_delegate.m_Closure.m_pFunction = 0i64;
  v6 = &this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>;
  this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>::mPrev = &this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>;
  this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>::mNext = &this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>;
  this->vfptr = (UFG::StimulusNotifyCallbackVtbl *)&UFG::StimulusNotifyScript::`vftable;
  this->mpICoroutine.i_obj_p = pICoroutine;
  if ( pICoroutine )
    i_ptr_id = pICoroutine->i_ptr_id;
  else
    i_ptr_id = 0;
  this->mpICoroutine.i_ptr_id = i_ptr_id;
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>(
    &this->mpEmitter,
    pEmitter);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->m_delegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::StimulusNotifyScript::OnStimulusNotify;
  this->m_delegate.m_Closure.m_pthis = RCX;
  ++pICoroutine->i_pending_count;
  mPrev = UFG::StimulusNotifyScript::smActiveList.mNode.mPrev;
  UFG::StimulusNotifyScript::smActiveList.mNode.mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&UFG::StimulusNotifyScript::smActiveList;
  UFG::StimulusNotifyScript::smActiveList.mNode.mPrev = v6;
}

// File Line: 437
// RVA: 0x50ECF0
char __fastcall UFG::StimulusNotifyScript::OnStimulusNotify(
        UFG::StimulusNotifyScript *this,
        UFG::StimulusReceiverComponent *pRecvComp,
        UFG::Stimulus *pStimulus,
        UFG::StimulusNotifyCallback *pCallback)
{
  SSInvokedCoroutine *i_obj_p; // rbx
  UFG::SimObject *m_pPointer; // rax
  UFG::SimObject *v7; // rcx
  UFG::TSActor *v9; // rax
  __int64 v10; // rsi
  UFG::TSActor *v11; // rdi
  _DWORD *v12; // rcx
  bool v13; // zf
  UFG::TSActor *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rsi
  UFG::TSActor *v17; // rdi
  _DWORD *v18; // rcx
  SSData **i_array_p; // rcx
  SSData *v20; // rsi
  SSInstance *i_data_p; // rdi
  SSInstance *v22; // rcx
  SSInstance *v23; // rdi
  __int64 v24; // rbx
  _DWORD *v25; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *mNext; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v27; // rdx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *mPrev; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v29; // rax

  i_obj_p = this->mpICoroutine.i_obj_p;
  if ( !i_obj_p || this->mpICoroutine.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  m_pPointer = this->mpEmitter.m_pPointer;
  if ( pStimulus )
  {
    if ( !i_obj_p )
    {
LABEL_22:
      mNext = this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>::mNext;
      v27 = &this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>;
      mPrev = this->UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript>::mPrev;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v27->mPrev = v27;
      v27->mNext = v27;
      v29 = UFG::StimulusNotifyScript::smDeleteList.mNode.mPrev;
      UFG::StimulusNotifyScript::smDeleteList.mNode.mPrev->mNext = v27;
      v27->mPrev = v29;
      v27->mNext = (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&UFG::StimulusNotifyScript::smDeleteList;
      UFG::StimulusNotifyScript::smDeleteList.mNode.mPrev = v27;
      return 1;
    }
    if ( m_pPointer || !this->mpEmitter.m_Changed )
    {
      v7 = pStimulus->m_pStimulusProducer.m_pPointer;
      if ( m_pPointer && m_pPointer != v7 )
        return 0;
      v9 = UFG::TSSimObject::AsInstanceSimOrActor(
             v7,
             *(SSInstance **)(*((_QWORD *)i_obj_p->i_data.i_array_p + 2) + 8i64));
      v10 = *((_QWORD *)i_obj_p->i_data.i_array_p + 3);
      ++v9->i_ref_count;
      v11 = v9;
      v12 = *(_DWORD **)(v10 + 8);
      v13 = v12[4]-- == 1;
      if ( v13 )
      {
        v12[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v12 + 112i64))(v12);
      }
      *(_QWORD *)(v10 + 8) = v11;
      v14 = UFG::TSSimObject::AsInstanceSimOrActor(
              pRecvComp->m_pSimObject,
              *(SSInstance **)(*((_QWORD *)i_obj_p->i_data.i_array_p + 1) + 8i64));
      v16 = *((_QWORD *)i_obj_p->i_data.i_array_p + 4);
      ++v14->i_ref_count;
      v17 = v14;
      v18 = *(_DWORD **)(v16 + 8);
      v13 = v18[4]-- == 1;
      if ( v13 )
      {
        v18[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v18 + 112i64))(v18);
      }
      *(_QWORD *)(v16 + 8) = v17;
      i_array_p = i_obj_p->i_data.i_array_p;
      v20 = i_array_p[5];
      i_data_p = (*i_array_p)->i_data_p;
      ++i_data_p->i_ref_count;
      v22 = v20->i_data_p;
      v13 = v22->i_ref_count-- == 1;
      if ( v13 )
      {
        v22->i_ref_count = 0x80000000;
        v22->vfptr[1].get_scope_context(v22);
      }
      v20->i_data_p = i_data_p;
      LOBYTE(v15) = 1;
      ((void (__fastcall *)(SSInvokedCoroutine *, __int64))i_obj_p->vfptr[1].get_topmost_scope)(i_obj_p, v15);
      return 1;
    }
  }
  if ( !i_obj_p )
    goto LABEL_22;
  v23 = UFG::gpAIStimulusTypeClass_none;
  v24 = *((_QWORD *)i_obj_p->i_data.i_array_p + 5);
  ++UFG::gpAIStimulusTypeClass_none->i_ref_count;
  v25 = *(_DWORD **)(v24 + 8);
  v13 = v25[4]-- == 1;
  if ( v13 )
  {
    v25[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *, UFG::StimulusReceiverComponent *, UFG::Stimulus *, UFG::StimulusNotifyCallback *))(*(_QWORD *)v25 + 112i64))(
      v25,
      pRecvComp,
      pStimulus,
      pCallback);
  }
  *(_QWORD *)(v24 + 8) = v23;
  return 1;
}

// File Line: 512
// RVA: 0x4CB6E0
void __fastcall UFG::TSActor::TSActor(UFG::TSActor *this, ASymbol *name, SSActorClass *pClass)
{
  SSActor::SSActor(this, name, pClass, 1);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTransformNodeComponent);
  this->mpComponent = 0i64;
  this->m_audioController.m_pEvent = 0i64;
  this->mpSimObj.mPrev = &this->mpSimObj;
  this->mpSimObj.mNext = &this->mpSimObj;
  this->mpSimObj.m_pPointer = 0i64;
}

// File Line: 523
// RVA: 0x4CBE40
void __fastcall UFG::TSActor::~TSActor(UFG::TSActor *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSimObj; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::AudioEvent *m_pEvent; // rcx

  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
  p_mpSimObj = &this->mpSimObj;
  if ( this->mpSimObj.m_pPointer )
  {
    mPrev = p_mpSimObj->mPrev;
    mNext = p_mpSimObj->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpSimObj->mPrev = p_mpSimObj;
    p_mpSimObj->mNext = p_mpSimObj;
  }
  p_mpSimObj->m_pPointer = 0i64;
  v5 = p_mpSimObj->mPrev;
  v6 = p_mpSimObj->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpSimObj->mPrev = p_mpSimObj;
  p_mpSimObj->mNext = p_mpSimObj;
  m_pEvent = this->m_audioController.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mTransformNodeComponent);
  SSActor::~SSActor(this);
}

// File Line: 528
// RVA: 0x511890
UFG::TSActor *__fastcall UFG::TSActor::find_instance(ASymbol *instance_name)
{
  UFG::TSActor *result; // rax
  UFG::qBaseNodeRB *SimObject; // rax

  result = (UFG::TSActor *)SSActor::find(instance_name);
  if ( !result )
  {
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)instance_name);
    return UFG::TSActor::FromSimObject((UFG::SimObject *)SimObject);
  }
  return result;
}

// File Line: 662
// RVA: 0x4E0BC0
UFG::TSActor *__fastcall UFG::TSActor::FromSimObject(UFG::SimObject *pSimObj)
{
  signed __int16 m_Flags; // dx
  UFG::TSActorComponent *ComponentOfType; // rax

  if ( pSimObj
    && ((m_Flags = pSimObj->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) == 0
        ? ((m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                         pSimObj,
                                                         UFG::TSActorComponent::_TypeUID))
         : (ComponentOfType = (UFG::TSActorComponent *)pSimObj->m_Components.p[2].m_pComponent))
        : (ComponentOfType = (UFG::TSActorComponent *)pSimObj->m_Components.p[3].m_pComponent))
       : (ComponentOfType = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent))
      : (ComponentOfType = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent),
        ComponentOfType) )
  {
    return UFG::TSActorComponent::GetActor(ComponentOfType);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 685
// RVA: 0x510480
UFG::TSActor *__fastcall UFG::TSActor::SkookumObjFromSimObj(UFG::SimObject *pSimObj)
{
  signed __int16 m_Flags; // dx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *result; // rax

  if ( !pSimObj )
    return (UFG::TSActor *)SSBrain::c_nil_p;
  m_Flags = pSimObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = (UFG::TSActorComponent *)pSimObj->m_Components.p[3].m_pComponent;
    else
      m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                             ? pSimObj->m_Components.p[2].m_pComponent
                                             : UFG::SimObject::GetComponentOfType(
                                                 pSimObj,
                                                 UFG::TSActorComponent::_TypeUID));
  }
  else
  {
    m_pComponent = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent;
  }
  if ( !m_pComponent )
    return (UFG::TSActor *)SSBrain::c_nil_p;
  result = UFG::TSActorComponent::GetActor(m_pComponent);
  ++result->i_ref_count;
  return result;
}

// File Line: 714
// RVA: 0x4E0EC0
UFG::TSActor *__fastcall UFG::TSActor::GetArgByNameOrInstance(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSInstance *i_data_p; // rbx
  SSClass *i_class_p; // rdi

  i_data_p = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( !i_data_p )
    return 0i64;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    return (UFG::TSActor *)i_data_p;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    return (UFG::TSActor *)SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
    return 0i64;
}

// File Line: 895
// RVA: 0x4E2390
__int64 __fastcall UFG::TSActor::ListCollectNear(
        APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pInstances,
        UFG::qVector3 *pos,
        float radius,
        SSActorClass *pClass,
        APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pExclusions)
{
  unsigned int i_count; // ebp
  SSActor **i_array_p; // rsi
  SSActor **i; // r12
  SSActor *v10; // rbx
  SSActor **v11; // rcx
  SSActor **v12; // r8
  float *i_class_p; // rdi
  SSActor **v14; // rcx
  SSActor **v15; // rdx

  i_count = pInstances->i_count;
  if ( !pClass )
    pClass = SSBrain::c_physical_actor_class_p;
  i_array_p = pClass->i_instances.i_array_p;
  for ( i = &i_array_p[pClass->i_instances.i_count]; i_array_p < i; ++i_array_p )
  {
    v10 = *i_array_p;
    if ( pExclusions
      && pExclusions->i_count
      && (v11 = pExclusions->i_array_p, v12 = &v11[pExclusions->i_count - 1], v11 <= v12) )
    {
      while ( v10 != *v11 )
      {
        if ( ++v11 > v12 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      i_class_p = (float *)v10[1].i_class_p;
      if ( i_class_p )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10[1].i_class_p);
        if ( (float)((float)((float)((float)(pos->y - i_class_p[45]) * (float)(pos->y - i_class_p[45]))
                           + (float)((float)(pos->x - i_class_p[44]) * (float)(pos->x - i_class_p[44])))
                   + (float)((float)(pos->z - i_class_p[46]) * (float)(pos->z - i_class_p[46]))) <= (float)(radius * radius) )
        {
          if ( i_count
            && pInstances->i_count
            && (v14 = pInstances->i_array_p, v15 = &v14[pInstances->i_count - 1], v14 <= v15) )
          {
            while ( v10 != *v14 )
            {
              if ( ++v14 > v15 )
                goto LABEL_16;
            }
          }
          else
          {
LABEL_16:
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(pInstances, v10);
          }
        }
      }
    }
  }
  return pInstances->i_count - i_count;
}

// File Line: 958
// RVA: 0x4E2500
__int64 __fastcall UFG::TSActor::ListRefineNear(
        APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pInstances,
        UFG::qVector3 *pos,
        float radius)
{
  __int64 v3; // rbx
  SSActor **i_array_p; // r14
  SSActor *v7; // rdi
  float *i_class_p; // rbp
  SSActor **v9; // rax

  LODWORD(v3) = pInstances->i_count;
  i_array_p = pInstances->i_array_p;
  if ( !pInstances->i_count )
    return 0i64;
  do
  {
    v3 = (unsigned int)(v3 - 1);
    v7 = i_array_p[v3];
    i_class_p = (float *)v7[1].i_class_p;
    if ( i_class_p )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7[1].i_class_p);
      if ( (float)((float)((float)((float)(pos->x - i_class_p[44]) * (float)(pos->x - i_class_p[44]))
                         + (float)((float)(pos->y - i_class_p[45]) * (float)(pos->y - i_class_p[45])))
                 + (float)((float)(pos->z - i_class_p[46]) * (float)(pos->z - i_class_p[46]))) <= (float)(radius * radius) )
      {
        v9 = pInstances->i_array_p;
        memmove(&v9[v3], &v9[v3 + 1], 8i64 * (unsigned int)(--pInstances->i_count - v3));
        if ( v7->i_ref_count-- == 1 )
        {
          v7->i_ref_count = 0x80000000;
          v7->vfptr[1].get_scope_context(v7);
        }
      }
    }
    ++i_array_p;
  }
  while ( (_DWORD)v3 );
  return pInstances->i_count;
}

// File Line: 1008
// RVA: 0x4E2610
UFG::TSActor *__fastcall UFG::TSActor::ListSelectNearest(
        APArrayBase<SSActor> *candidates,
        UFG::qVector3 *pos,
        float radius,
        APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pExclusions)
{
  float v6; // xmm6_4
  SSActor **i_array_p; // rdi
  SSActor *v8; // rbp
  SSActor **i; // r15
  SSActor *v10; // rbx
  SSActor **v11; // rcx
  SSActor **v12; // r8
  float *i_class_p; // rsi

  if ( radius < 0.0 )
    v6 = FLOAT_3_4028235e38;
  else
    v6 = radius * radius;
  i_array_p = candidates->i_array_p;
  v8 = 0i64;
  for ( i = &i_array_p[candidates->i_count]; i_array_p < i; ++i_array_p )
  {
    v10 = *i_array_p;
    if ( pExclusions
      && pExclusions->i_count
      && (v11 = pExclusions->i_array_p, v12 = &v11[pExclusions->i_count - 1], v11 <= v12) )
    {
      while ( v10 != *v11 )
      {
        if ( ++v11 > v12 )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      i_class_p = (float *)v10[1].i_class_p;
      if ( i_class_p )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10[1].i_class_p);
        if ( (float)((float)((float)((float)(pos->y - i_class_p[45]) * (float)(pos->y - i_class_p[45]))
                           + (float)((float)(pos->x - i_class_p[44]) * (float)(pos->x - i_class_p[44])))
                   + (float)((float)(pos->z - i_class_p[46]) * (float)(pos->z - i_class_p[46]))) < v6 )
        {
          v8 = v10;
          v6 = (float)((float)((float)(pos->y - i_class_p[45]) * (float)(pos->y - i_class_p[45]))
                     + (float)((float)(pos->x - i_class_p[44]) * (float)(pos->x - i_class_p[44])))
             + (float)((float)(pos->z - i_class_p[46]) * (float)(pos->z - i_class_p[46]));
        }
      }
    }
  }
  return (UFG::TSActor *)v8;
}

// File Line: 1054
// RVA: 0x50EAF0
void __fastcall UFG::TSActor::OnInit(UFG::TSActor *this, UFG::SimObject *pSimObj)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSimObj; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  p_mpSimObj = &this->mpSimObj;
  if ( this->mpSimObj.m_pPointer )
  {
    mPrev = p_mpSimObj->mPrev;
    mNext = this->mpSimObj.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpSimObj->mPrev = p_mpSimObj;
    this->mpSimObj.mNext = &this->mpSimObj;
  }
  this->mpSimObj.m_pPointer = pSimObj;
  if ( pSimObj )
  {
    v6 = pSimObj->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v6->mNext = p_mpSimObj;
    p_mpSimObj->mPrev = v6;
    this->mpSimObj.mNext = &pSimObj->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pSimObj->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpSimObj;
  }
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Set(
    &this->mTransformNodeComponent,
    this->mpSimObj.m_pPointer->m_pTransformNodeComponent);
  SSInstance::call_default_constructor(this);
  SSActor::enable_behavior(this, 1);
}

// File Line: 1081
// RVA: 0x50E870
void __fastcall UFG::TSActor::OnDeinit(UFG::TSActor *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mTransformNodeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  unsigned int i_ref_count; // ecx
  bool v8; // zf
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  p_mTransformNodeComponent = &this->mTransformNodeComponent;
  if ( this->mTransformNodeComponent.m_pSimComponent )
  {
    mNext = this->mTransformNodeComponent.mNext;
    mPrev = p_mTransformNodeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mTransformNodeComponent.m_pSimComponent = 0i64;
  }
  else
  {
    if ( !this->mTransformNodeComponent.m_pSimObject
      || p_mTransformNodeComponent->mPrev == p_mTransformNodeComponent
      && this->mTransformNodeComponent.mNext == &this->mTransformNodeComponent )
    {
      goto LABEL_8;
    }
    v5 = this->mTransformNodeComponent.mNext;
    v6 = p_mTransformNodeComponent->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
  }
  p_mTransformNodeComponent->m_pSimObject = 0i64;
  p_mTransformNodeComponent->mNext = p_mTransformNodeComponent;
  p_mTransformNodeComponent->mPrev = p_mTransformNodeComponent;
LABEL_8:
  p_mTransformNodeComponent->m_Changed = 1;
  i_ref_count = this->i_ref_count;
  if ( (i_ref_count & 0x7FFFFFFF) <= 1 )
  {
    this->i_ref_count = i_ref_count - 1;
    v8 = i_ref_count == 1;
  }
  else
  {
    UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&result, (UFG::qSymbol *)&this->ANamed, "__DORMANT__");
    SSActor::rename(this, (ASymbol *)&result);
    SSActor::enable_behavior(this, 0);
    v8 = this->i_ref_count-- == 1;
  }
  if ( v8 )
  {
    this->i_ref_count = 0x80000000;
    this->vfptr[1].get_scope_context(this);
  }
}

// File Line: 1123
// RVA: 0x50EEC0
void __fastcall UFG::TSActor::OnTeleport(UFG::TSCharacter *this)
{
  SSObjectBaseVtbl *vfptr; // rax
  __int64 v2; // [rsp+40h] [rbp+8h] BYREF

  vfptr = this->vfptr;
  v2 = 0i64;
  ((void (__fastcall *)(UFG::TSCharacter *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))vfptr[1].set_data_by_name)(
    this,
    &qSymbol_on_teleport,
    &v2,
    0i64,
    0i64,
    0i64);
}

// File Line: 1132
// RVA: 0x512570
void __fastcall UFG::TSActor::on_no_references(UFG::TSActor *this)
{
  SSInstance::call_destructor(this);
  this->i_ptr_id = 0;
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 1147
// RVA: 0x4F3650
void __fastcall UFG::TSActor::Mthd_SimObject(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
      *ppResult = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)m_pPointer);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 1165
// RVA: 0x50C410
void __fastcall UFG::TSActor::Mthd_suspend(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
      UFG::SimObject::Suspend(m_pPointer);
  }
}

// File Line: 1181
// RVA: 0x506A00
void __fastcall UFG::TSActor::Mthd_restore(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
      UFG::SimObject::Restore(m_pPointer);
  }
}

// File Line: 1198
// RVA: 0x4F7B30
void __fastcall UFG::TSActor::Mthd_despawn(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rbx

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && m_pPointer != UFG::GetLocalPlayer() )
  {
    SSActor::enable_behavior(this, 0);
    if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) )
      UFG::Simulation::QueueSimObjectToBeDestroyedRecursive(&UFG::gSim, m_pPointer);
    else
      UFG::Simulation::QueueTrackedSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
  }
}

// File Line: 1233
// RVA: 0x503CC0
void __fastcall UFG::TSActor::Mthd_is_valid_simobject(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( (this->i_actor_flags & 0x10000) != 0 || !this->mpSimObj.m_pPointer )
      *ppResult = SSBoolean::pool_new(0);
    else
      *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 1247
// RVA: 0x503D10
void __fastcall UFG::TSActor::Mthd_is_valid_simproxy(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(this->mpSimObj.m_pPointer != 0i64);
}

// File Line: 1256
// RVA: 0x501080
void __fastcall UFG::TSActor::Mthd_is_close_enough_to_marker(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v7; // bp
  UFG::qBaseTreeRB *ArgByNameOrInstance; // rax
  SSData **i_array_p; // rcx
  UFG::TransformNodeComponent *m_pSimComponent; // rsi
  float v11; // xmm6_4
  UFG::qBaseNodeRB *v12; // rbx
  UFG::TransformNodeComponent *v13; // rbx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
    m_pPointer = 0i64;
  if ( ppResult && m_pPointer )
  {
    v7 = 0;
    ArgByNameOrInstance = UFG::TSMarker::GetArgByNameOrInstance(pScope, 0);
    i_array_p = pScope->i_data.i_array_p;
    m_pSimComponent = (UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent;
    v11 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    if ( ArgByNameOrInstance )
    {
      v12 = ArgByNameOrInstance->mNULL.mChild[0];
      if ( v12 )
      {
        v13 = *(UFG::TransformNodeComponent **)&v12[2].mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform(v13);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
        v7 = (float)(v11 * v11) > (float)((float)((float)((float)(m_pSimComponent->mWorldTransform.v3.y
                                                                - v13->mWorldTransform.v3.y)
                                                        * (float)(m_pSimComponent->mWorldTransform.v3.y
                                                                - v13->mWorldTransform.v3.y))
                                                + (float)((float)(m_pSimComponent->mWorldTransform.v3.x
                                                                - v13->mWorldTransform.v3.x)
                                                        * (float)(m_pSimComponent->mWorldTransform.v3.x
                                                                - v13->mWorldTransform.v3.x)))
                                        + (float)((float)(m_pSimComponent->mWorldTransform.v3.z
                                                        - v13->mWorldTransform.v3.z)
                                                * (float)(m_pSimComponent->mWorldTransform.v3.z
                                                        - v13->mWorldTransform.v3.z)));
      }
    }
    *ppResult = SSBoolean::pool_new(v7);
  }
}

// File Line: 1292
// RVA: 0x4F8F60
void __fastcall UFG::TSActor::Mthd_enable_physics(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::RigidBody *ComponentOfTypeHK; // rax
  unsigned int v8; // edx

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pPointer,
                                              UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                              m_pPointer,
                                              UFG::RigidBodyComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      v8 = 256;
      if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        v8 = 128;
      UFG::RigidBody::SetMotionType(ComponentOfTypeHK, v8);
    }
  }
}

// File Line: 1314
// RVA: 0x4FFDF0
void __fastcall UFG::TSActor::Mthd_has_fractured_parts(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  char HasFracturedParts; // di
  UFG::RigidBody *i; // rbx

  HasFracturedParts = 0;
  if ( this->mpSimObj.m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      for ( i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                    this->mpSimObj.m_pPointer,
                                    UFG::RigidBodyComponent::_TypeUID);
            i;
            i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                    i->m_pSimObject,
                                    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                    0,
                                    i) )
      {
        HasFracturedParts = UFG::RigidBody::HasFracturedParts(i);
        if ( HasFracturedParts )
          break;
      }
    }
  }
  *ppResult = SSBoolean::pool_new(HasFracturedParts);
}

// File Line: 1336
// RVA: 0x4FC4A0
void __fastcall UFG::TSActor::Mthd_get_dir(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&m_pSimComponent[2]);
    }
    else
    {
      *ppResult = UFG::TSVector3::AsInstance(&UFG::qVector3::msDirFront);
    }
  }
}

// File Line: 1361
// RVA: 0x4FC550
void __fastcall UFG::TSActor::Mthd_get_dir_back(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  int v5; // xmm1_4
  int vfptr_high; // xmm0_4
  UFG::qVector3 vec; // [rsp+20h] [rbp-18h] BYREF

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      v5 = LODWORD(m_pSimComponent[2].m_SafePointerList.mNode.mPrev) ^ _xmm[0];
      LODWORD(vec.x) = LODWORD(m_pSimComponent[2].vfptr) ^ _xmm[0];
      vfptr_high = HIDWORD(m_pSimComponent[2].vfptr);
      LODWORD(vec.z) = v5;
      LODWORD(vec.y) = vfptr_high ^ _xmm[0];
    }
    else
    {
      vec = UFG::qVector3::msDirBack;
    }
    *ppResult = UFG::TSVector3::AsInstance(&vec);
  }
}

// File Line: 1386
// RVA: 0x4FC920
void __fastcall UFG::TSActor::Mthd_get_dir_right(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  int v5; // xmm1_4
  int mNext_high; // xmm0_4
  UFG::qVector3 vec; // [rsp+20h] [rbp-18h] BYREF

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      v5 = m_pSimComponent[2].m_TypeUID ^ _xmm[0];
      LODWORD(vec.x) = LODWORD(m_pSimComponent[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
      mNext_high = HIDWORD(m_pSimComponent[2].m_SafePointerList.mNode.mNext);
      LODWORD(vec.z) = v5;
      LODWORD(vec.y) = mNext_high ^ _xmm[0];
    }
    else
    {
      vec = UFG::qVector3::msDirRight;
    }
    *ppResult = UFG::TSVector3::AsInstance(&vec);
  }
}

// File Line: 1411
// RVA: 0x4FC870
void __fastcall UFG::TSActor::Mthd_get_dir_left(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&m_pSimComponent[2].m_SafePointerList.mNode.mNext);
    }
    else
    {
      *ppResult = UFG::TSVector3::AsInstance(&UFG::qVector3::msDirLeft);
    }
  }
}

// File Line: 1436
// RVA: 0x4FCAB0
void __fastcall UFG::TSActor::Mthd_get_dir_up(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&m_pSimComponent[2].m_Flags);
    }
    else
    {
      *ppResult = UFG::TSVector3::AsInstance(&UFG::qVector3::msDirUp);
    }
  }
}

// File Line: 1461
// RVA: 0x4FC6E0
void __fastcall UFG::TSActor::Mthd_get_dir_down(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  int v5; // xmm1_4
  int v6; // xmm0_4
  UFG::qVector3 vec; // [rsp+20h] [rbp-18h] BYREF

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      v5 = LODWORD(m_pSimComponent[2].m_pSimObject) ^ _xmm[0];
      LODWORD(vec.x) = *(_DWORD *)&m_pSimComponent[2].m_Flags ^ _xmm[0];
      v6 = *(_DWORD *)(&m_pSimComponent[2].m_SimObjIndex + 1);
      LODWORD(vec.z) = v5;
      LODWORD(vec.y) = v6 ^ _xmm[0];
    }
    else
    {
      vec = UFG::qVector3::msDirDown;
    }
    *ppResult = UFG::TSVector3::AsInstance(&vec);
  }
}

// File Line: 1486
// RVA: 0x4FDD90
void __fastcall UFG::TSActor::Mthd_get_pos(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rbx

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles);
    }
    else
    {
      *ppResult = UFG::TSVector3::AsInstance(&UFG::qVector3::msZero);
    }
  }
}

// File Line: 1511
// RVA: 0x4FDE40
void __fastcall UFG::TSActor::Mthd_get_properties(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertySet *WritableProperties; // rbx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_pSceneObj = m_pPointer->m_pSceneObj;
      if ( m_pSceneObj )
      {
        WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(m_pSceneObj);
        UFG::qPropertySet::AddRef(WritableProperties);
        *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)WritableProperties);
      }
    }
  }
}

// File Line: 1523
// RVA: 0x4FB700
void __fastcall UFG::TSActor::Mthd_get_archetype_properties(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::qPropertySet *ArchetypeProperties; // rbx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      ArchetypeProperties = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(m_pPointer->m_pSceneObj);
      UFG::qPropertySet::AddRef(ArchetypeProperties);
      *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)ArchetypeProperties);
    }
  }
}

// File Line: 1539
// RVA: 0x4FF680
void __fastcall UFG::TSActor::Mthd_get_xform(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::TransformNodeComponent *v4; // rcx

  if ( ppResult )
  {
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    v4 = &UFG::TransformNodeComponent::sIdentityNode;
    if ( m_pSimComponent )
      v4 = (UFG::TransformNodeComponent *)m_pSimComponent;
    *ppResult = UFG::TSTransform::AsInstance(v4);
  }
}

// File Line: 1572
// RVA: 0x4FD4E0
void __fastcall UFG::TSActor::Mthd_get_last_teleport_frame(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  unsigned int mLastTeleportFrame; // ecx
  UFG::SceneObjectProperties *m_pSceneObj; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    mLastTeleportFrame = 0;
    if ( m_pPointer )
      m_pSceneObj = m_pPointer->m_pSceneObj;
    else
      m_pSceneObj = 0i64;
    if ( m_pSceneObj )
      mLastTeleportFrame = m_pSceneObj->mLastTeleportFrame;
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, mLastTeleportFrame);
  }
}

// File Line: 1604
// RVA: 0x50C430
void __fastcall UFG::TSActor::Mthd_teleport_dir(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  float v5; // xmm2_4
  float *i_user_data; // r10
  unsigned __int64 v7; // r9
  float *v8; // rax
  float v9; // xmm4_4
  float w; // xmm7_4
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm11_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm12_4
  __int128 v18; // xmm13
  float v19; // xmm14_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  __m128 v23; // xmm6
  float v24; // xmm5_4
  __m128 v25; // xmm3
  float v26; // xmm1_4
  float v27; // xmm10_4
  __m128 v28; // xmm8
  __m128 v29; // xmm9
  __m128 v30; // xmm3
  float v31; // xmm1_4
  float v32; // xmm8_4
  float v33; // xmm10_4
  float v34; // xmm11_4
  float v35; // xmm8_4
  __m128 v36; // xmm3
  float v37; // xmm0_4
  __int128 v38; // xmm3
  float v39; // xmm10_4
  __m128 v40; // xmm9
  float v41; // xmm8_4
  __m128 v42; // xmm11
  float v43; // xmm1_4
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 v45; // [rsp+60h] [rbp-98h] BYREF

  if ( this->mpSimObj.m_pPointer )
  {
    i_array_p = pScope->i_data.i_array_p;
    v5 = 0.0;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    v7 = i_array_p[1]->i_data_p->i_user_data;
    v8 = (float *)i_array_p[2]->i_data_p->i_user_data;
    v9 = *(float *)v7;
    if ( *(float *)v7 == 0.0 && *(float *)(v7 + 4) == 0.0 && *(float *)(v7 + 8) == 0.0 )
    {
      UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data);
      w = dest.v3.w;
      z = dest.v3.z;
      y = dest.v3.y;
      x = dest.v3.x;
      v5 = dest.v2.w;
      v14 = dest.v2.z;
      v15 = dest.v2.y;
      v16 = dest.v2.x;
      v17 = dest.v1.y;
      *(float *)&v18 = dest.v1.x;
      v19 = dest.v0.w;
      v20 = dest.v0.z;
      v21 = dest.v0.y;
      v22 = dest.v0.x;
    }
    else
    {
      v23 = (__m128)*(unsigned int *)(v7 + 4);
      v24 = *(float *)(v7 + 8);
      w = *(float *)&FLOAT_1_0;
      v25 = v23;
      v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v9 * v9)) + (float)(v24 * v24);
      if ( v25.m128_f32[0] == 0.0 )
        v26 = 0.0;
      else
        v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
      v22 = v9 * v26;
      v21 = v23.m128_f32[0] * v26;
      v20 = v24 * v26;
      v19 = 0.0;
      dest.v0.w = 0.0;
      dest.v0.x = v22;
      dest.v0.y = v21;
      dest.v0.z = v20;
      v27 = v8[1];
      v28 = (__m128)*(unsigned int *)v8;
      v29 = (__m128)*((unsigned int *)v8 + 2);
      v30 = v28;
      v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27))
                      + (float)(v29.m128_f32[0] * v29.m128_f32[0]);
      if ( v30.m128_f32[0] == 0.0 )
        v31 = 0.0;
      else
        v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
      v29.m128_f32[0] = v29.m128_f32[0] * v31;
      v32 = v28.m128_f32[0] * v31;
      v33 = v27 * v31;
      v34 = (float)(v33 * v20) - (float)(v29.m128_f32[0] * v21);
      v29.m128_f32[0] = (float)(v29.m128_f32[0] * v22) - (float)(v32 * v20);
      v35 = (float)(v32 * v21) - (float)(v33 * v22);
      v36 = v29;
      v36.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v34 * v34)) + (float)(v35 * v35);
      if ( v36.m128_f32[0] == 0.0 )
      {
        v38 = 0i64;
      }
      else
      {
        v37 = _mm_sqrt_ps(v36).m128_f32[0];
        v38 = (unsigned int)FLOAT_1_0;
        *(float *)&v38 = 1.0 / v37;
      }
      v18 = v38;
      *(float *)&v18 = *(float *)&v38 * v34;
      v17 = *(float *)&v38 * v29.m128_f32[0];
      dest.v1.z = *(float *)&v38 * v35;
      v40 = (__m128)v18;
      dest.v1.w = 0.0;
      dest.v1.x = *(float *)&v38 * v34;
      dest.v1.y = v17;
      v39 = (float)((float)(*(float *)&v38 * v35) * v21) - (float)(v17 * v20);
      v40.m128_f32[0] = (float)((float)(*(float *)&v38 * v34) * v20) - (float)((float)(*(float *)&v38 * v35) * v22);
      v42 = v40;
      v41 = (float)(v17 * v22) - (float)(*(float *)&v18 * v21);
      v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42.m128_f32[0] == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
      dest.v2.w = 0.0;
      v16 = v39 * v43;
      v15 = v40.m128_f32[0] * v43;
      dest.v2.x = v16;
      dest.v2.y = v15;
      v14 = v41 * v43;
      dest.v2.z = v14;
      y = i_user_data[1];
      z = i_user_data[2];
      x = *i_user_data;
      dest.v3.y = y;
      dest.v3.z = z;
      dest.v3.x = x;
      LODWORD(dest.v3.w) = (_DWORD)FLOAT_1_0;
    }
    v45.v0.x = v22;
    v45.v0.y = v21;
    v45.v0.z = v20;
    v45.v0.w = v19;
    LODWORD(v45.v1.x) = v18;
    v45.v1.y = v17;
    v45.v1.z = v16;
    v45.v1.w = v15;
    v45.v2.x = v14;
    v45.v2.y = v5;
    v45.v2.z = x;
    v45.v2.w = y;
    v45.v3.x = z;
    v45.v3.y = w;
    UFG::TSActor::TeleportToTransform(this, &v45);
  }
}

// File Line: 1635
// RVA: 0x50CBE0
void __fastcall UFG::TSActor::Mthd_teleport_pos(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  float v5; // xmm2_4
  float *i_user_data; // r10
  float *v7; // r9
  float *v8; // rax
  __m128 v9; // xmm5
  float w; // xmm6_4
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm13_4
  float v14; // xmm10_4
  float v15; // xmm11_4
  float v16; // xmm12_4
  float v17; // xmm7_4
  __int128 v18; // xmm9
  float v19; // xmm14_4
  __int128 v20; // xmm3
  float v21; // xmm5_4
  __int128 v22; // xmm8
  float v23; // xmm7_4
  __m128 v24; // xmm4
  __int128 v25; // xmm1
  float v26; // xmm11_4
  __m128 v27; // xmm10
  float v28; // xmm12_4
  __m128 v29; // xmm4
  float v30; // xmm1_4
  float v31; // xmm10_4
  float v32; // xmm11_4
  float v33; // xmm12_4
  float v34; // xmm4_4
  __m128 v35; // xmm7
  float v36; // xmm4_4
  __m128 v37; // xmm10
  float v38; // xmm1_4
  float v39; // xmm12_4
  __m128 v40; // xmm11
  float v41; // xmm10_4
  __m128 v42; // xmm13
  float v43; // xmm1_4
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 v45; // [rsp+60h] [rbp-98h] BYREF

  if ( this->mpSimObj.m_pPointer )
  {
    i_array_p = pScope->i_data.i_array_p;
    v5 = 0.0;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    v7 = (float *)i_array_p[1]->i_data_p->i_user_data;
    v8 = (float *)i_array_p[2]->i_data_p->i_user_data;
    v9 = (__m128)*(unsigned int *)v7;
    if ( v9.m128_f32[0] == 0.0 && v7[1] == 0.0 && v7[2] == 0.0
      || *i_user_data == v9.m128_f32[0] && v7[1] == i_user_data[1] && v7[2] == i_user_data[2] )
    {
      UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data);
      w = dest.v3.w;
      z = dest.v3.z;
      y = dest.v3.y;
      x = dest.v3.x;
      v5 = dest.v2.w;
      v14 = dest.v2.z;
      v15 = dest.v2.y;
      v16 = dest.v2.x;
      v17 = dest.v1.y;
      *(float *)&v18 = dest.v1.x;
      v19 = dest.v0.w;
      *(float *)&v20 = dest.v0.z;
      v21 = dest.v0.y;
      *(float *)&v22 = dest.v0.x;
    }
    else
    {
      v20 = *((unsigned int *)v7 + 2);
      w = *(float *)&FLOAT_1_0;
      v23 = v7[1] - i_user_data[1];
      *(float *)&v20 = *(float *)&v20 - i_user_data[2];
      v9.m128_f32[0] = v9.m128_f32[0] - *i_user_data;
      v24 = v9;
      v24.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v23 * v23))
                      + (float)(*(float *)&v20 * *(float *)&v20);
      if ( v24.m128_f32[0] == 0.0 )
      {
        v25 = 0i64;
      }
      else
      {
        v25 = (unsigned int)FLOAT_1_0;
        *(float *)&v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
      }
      v22 = v25;
      *(float *)&v20 = *(float *)&v20 * *(float *)&v25;
      v19 = 0.0;
      *(float *)&v22 = *(float *)&v25 * v9.m128_f32[0];
      dest.v0.w = 0.0;
      LODWORD(dest.v0.z) = v20;
      v21 = *(float *)&v25 * v23;
      LODWORD(dest.v0.x) = v22;
      dest.v0.y = *(float *)&v25 * v23;
      v26 = v8[1];
      v27 = (__m128)*(unsigned int *)v8;
      v29 = v27;
      v28 = v8[2];
      v29.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v26 * v26)) + (float)(v28 * v28);
      if ( v29.m128_f32[0] == 0.0 )
        v30 = 0.0;
      else
        v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
      v31 = v27.m128_f32[0] * v30;
      v32 = v26 * v30;
      v33 = v28 * v30;
      v18 = v20;
      v35 = (__m128)v22;
      v34 = v21 * v31;
      *(float *)&v18 = (float)(*(float *)&v20 * v32) - (float)(v21 * v33);
      v35.m128_f32[0] = (float)(*(float *)&v22 * v33) - (float)(*(float *)&v20 * v31);
      v37 = v35;
      v36 = v34 - (float)(*(float *)&v22 * v32);
      v37.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(*(float *)&v18 * *(float *)&v18))
                      + (float)(v36 * v36);
      if ( v37.m128_f32[0] == 0.0 )
        v38 = 0.0;
      else
        v38 = 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
      v17 = v35.m128_f32[0] * v38;
      *(float *)&v18 = *(float *)&v18 * v38;
      dest.v1.w = 0.0;
      v40 = (__m128)v18;
      LODWORD(dest.v1.x) = v18;
      dest.v1.y = v17;
      dest.v1.z = v36 * v38;
      v39 = (float)((float)(v36 * v38) * v21) - (float)(v17 * *(float *)&v20);
      v40.m128_f32[0] = (float)(*(float *)&v18 * *(float *)&v20) - (float)((float)(v36 * v38) * *(float *)&v22);
      v42 = v40;
      v41 = (float)(v17 * *(float *)&v22) - (float)(*(float *)&v18 * v21);
      v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42.m128_f32[0] == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
      dest.v2.w = 0.0;
      v16 = v39 * v43;
      v15 = v40.m128_f32[0] * v43;
      dest.v2.x = v16;
      dest.v2.y = v15;
      v14 = v41 * v43;
      dest.v2.z = v14;
      y = i_user_data[1];
      z = i_user_data[2];
      x = *i_user_data;
      dest.v3.y = y;
      dest.v3.z = z;
      dest.v3.x = x;
      LODWORD(dest.v3.w) = (_DWORD)FLOAT_1_0;
    }
    LODWORD(v45.v0.x) = v22;
    v45.v0.y = v21;
    LODWORD(v45.v0.z) = v20;
    v45.v0.w = v19;
    LODWORD(v45.v1.x) = v18;
    v45.v1.y = v17;
    v45.v1.z = v16;
    v45.v1.w = v15;
    v45.v2.x = v14;
    v45.v2.y = v5;
    v45.v2.z = x;
    v45.v2.w = y;
    v45.v3.x = z;
    v45.v3.y = w;
    UFG::TSActor::TeleportToTransform(this, &v45);
  }
}

// File Line: 1666
// RVA: 0x50D410
void __fastcall UFG::TSActor::Mthd_teleport_pos_preserve_vel(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  float v5; // xmm2_4
  float *i_user_data; // r10
  float *v7; // r9
  float *v8; // rax
  __m128 v9; // xmm5
  float w; // xmm6_4
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm13_4
  float v14; // xmm10_4
  float v15; // xmm11_4
  float v16; // xmm12_4
  float v17; // xmm7_4
  __int128 v18; // xmm9
  float v19; // xmm14_4
  __int128 v20; // xmm3
  float v21; // xmm5_4
  __int128 v22; // xmm8
  float v23; // xmm7_4
  __m128 v24; // xmm4
  __int128 v25; // xmm1
  float v26; // xmm11_4
  __m128 v27; // xmm10
  float v28; // xmm12_4
  __m128 v29; // xmm4
  float v30; // xmm1_4
  float v31; // xmm10_4
  float v32; // xmm11_4
  float v33; // xmm12_4
  float v34; // xmm4_4
  __m128 v35; // xmm7
  float v36; // xmm4_4
  __m128 v37; // xmm10
  float v38; // xmm1_4
  float v39; // xmm12_4
  __m128 v40; // xmm11
  float v41; // xmm10_4
  __m128 v42; // xmm13
  float v43; // xmm1_4
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 v45; // [rsp+60h] [rbp-98h] BYREF

  if ( this->mpSimObj.m_pPointer )
  {
    i_array_p = pScope->i_data.i_array_p;
    v5 = 0.0;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    v7 = (float *)i_array_p[1]->i_data_p->i_user_data;
    v8 = (float *)i_array_p[2]->i_data_p->i_user_data;
    v9 = (__m128)*(unsigned int *)v7;
    if ( v9.m128_f32[0] == 0.0 && v7[1] == 0.0 && v7[2] == 0.0
      || *i_user_data == v9.m128_f32[0] && v7[1] == i_user_data[1] && v7[2] == i_user_data[2] )
    {
      UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data);
      w = dest.v3.w;
      z = dest.v3.z;
      y = dest.v3.y;
      x = dest.v3.x;
      v5 = dest.v2.w;
      v14 = dest.v2.z;
      v15 = dest.v2.y;
      v16 = dest.v2.x;
      v17 = dest.v1.y;
      *(float *)&v18 = dest.v1.x;
      v19 = dest.v0.w;
      *(float *)&v20 = dest.v0.z;
      v21 = dest.v0.y;
      *(float *)&v22 = dest.v0.x;
    }
    else
    {
      v20 = *((unsigned int *)v7 + 2);
      w = *(float *)&FLOAT_1_0;
      v23 = v7[1] - i_user_data[1];
      *(float *)&v20 = *(float *)&v20 - i_user_data[2];
      v9.m128_f32[0] = v9.m128_f32[0] - *i_user_data;
      v24 = v9;
      v24.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v23 * v23))
                      + (float)(*(float *)&v20 * *(float *)&v20);
      if ( v24.m128_f32[0] == 0.0 )
      {
        v25 = 0i64;
      }
      else
      {
        v25 = (unsigned int)FLOAT_1_0;
        *(float *)&v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
      }
      v22 = v25;
      *(float *)&v20 = *(float *)&v20 * *(float *)&v25;
      v19 = 0.0;
      *(float *)&v22 = *(float *)&v25 * v9.m128_f32[0];
      dest.v0.w = 0.0;
      LODWORD(dest.v0.z) = v20;
      v21 = *(float *)&v25 * v23;
      LODWORD(dest.v0.x) = v22;
      dest.v0.y = *(float *)&v25 * v23;
      v26 = v8[1];
      v27 = (__m128)*(unsigned int *)v8;
      v29 = v27;
      v28 = v8[2];
      v29.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v26 * v26)) + (float)(v28 * v28);
      if ( v29.m128_f32[0] == 0.0 )
        v30 = 0.0;
      else
        v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
      v31 = v27.m128_f32[0] * v30;
      v32 = v26 * v30;
      v33 = v28 * v30;
      v18 = v20;
      v35 = (__m128)v22;
      v34 = v21 * v31;
      *(float *)&v18 = (float)(*(float *)&v20 * v32) - (float)(v21 * v33);
      v35.m128_f32[0] = (float)(*(float *)&v22 * v33) - (float)(*(float *)&v20 * v31);
      v37 = v35;
      v36 = v34 - (float)(*(float *)&v22 * v32);
      v37.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(*(float *)&v18 * *(float *)&v18))
                      + (float)(v36 * v36);
      if ( v37.m128_f32[0] == 0.0 )
        v38 = 0.0;
      else
        v38 = 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
      v17 = v35.m128_f32[0] * v38;
      *(float *)&v18 = *(float *)&v18 * v38;
      dest.v1.w = 0.0;
      v40 = (__m128)v18;
      LODWORD(dest.v1.x) = v18;
      dest.v1.y = v17;
      dest.v1.z = v36 * v38;
      v39 = (float)((float)(v36 * v38) * v21) - (float)(v17 * *(float *)&v20);
      v40.m128_f32[0] = (float)(*(float *)&v18 * *(float *)&v20) - (float)((float)(v36 * v38) * *(float *)&v22);
      v42 = v40;
      v41 = (float)(v17 * *(float *)&v22) - (float)(*(float *)&v18 * v21);
      v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42.m128_f32[0] == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
      dest.v2.w = 0.0;
      v16 = v39 * v43;
      v15 = v40.m128_f32[0] * v43;
      dest.v2.x = v16;
      dest.v2.y = v15;
      v14 = v41 * v43;
      dest.v2.z = v14;
      y = i_user_data[1];
      z = i_user_data[2];
      x = *i_user_data;
      dest.v3.y = y;
      dest.v3.z = z;
      dest.v3.x = x;
      LODWORD(dest.v3.w) = (_DWORD)FLOAT_1_0;
    }
    LODWORD(v45.v0.x) = v22;
    v45.v0.y = v21;
    LODWORD(v45.v0.z) = v20;
    v45.v0.w = v19;
    LODWORD(v45.v1.x) = v18;
    v45.v1.y = v17;
    v45.v1.z = v16;
    v45.v1.w = v15;
    v45.v2.x = v14;
    v45.v2.y = v5;
    v45.v2.z = x;
    v45.v2.w = y;
    v45.v3.x = z;
    v45.v3.y = w;
    UFG::TSActor::TeleportToTransformPreserveVel(this, &v45);
  }
}

// File Line: 1697
// RVA: 0x50D880
void __fastcall UFG::TSActor::Mthd_teleport_xform(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSData *v5; // rax
  float *i_user_data; // rbx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  UFG::qMatrix44 v34; // [rsp+20h] [rbp-40h] BYREF

  if ( this->mpSimObj.m_pPointer )
  {
    i_array_p = pScope->i_data.i_array_p;
    v5 = *i_array_p;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    if ( i_array_p[1]->i_data_p->i_user_data )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->i_data_p->i_user_data);
      v22 = i_user_data[34];
      v23 = i_user_data[35];
      v24 = i_user_data[32];
      v34.v0.y = i_user_data[33];
      v34.v0.z = v22;
      v34.v0.x = v24;
      v34.v0.w = v23;
      v25 = i_user_data[37];
      v26 = i_user_data[38];
      v27 = i_user_data[39];
      v34.v1.x = i_user_data[36];
      v34.v1.y = v25;
      v34.v1.z = v26;
      v34.v1.w = v27;
      v28 = i_user_data[42];
      v29 = i_user_data[43];
      v30 = i_user_data[40];
      v34.v2.y = i_user_data[41];
      v34.v2.x = v30;
      v34.v2.z = v28;
      v34.v2.w = v29;
      v31 = i_user_data[46];
      v32 = i_user_data[47];
      v33 = i_user_data[44];
      v34.v3.y = i_user_data[45];
      v34.v3.z = v31;
      v34.v3.x = v33;
      v34.v3.w = v32;
      UFG::TSActor::TeleportToTransform(this, &v34);
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->i_data_p->i_user_data);
      v7 = i_user_data[33];
      v34.v0.x = i_user_data[32];
      v8 = i_user_data[34];
      v34.v0.y = v7;
      v9 = i_user_data[35];
      v34.v0.z = v8;
      v10 = i_user_data[36];
      v34.v0.w = v9;
      v11 = i_user_data[37];
      v34.v1.x = v10;
      v12 = i_user_data[38];
      v34.v1.y = v11;
      v13 = i_user_data[39];
      v34.v1.z = v12;
      v14 = i_user_data[40];
      v34.v1.w = v13;
      v15 = i_user_data[41];
      v34.v2.x = v14;
      v16 = i_user_data[42];
      v34.v2.y = v15;
      v17 = i_user_data[43];
      v34.v2.z = v16;
      v18 = i_user_data[44];
      v34.v2.w = v17;
      v19 = i_user_data[45];
      v34.v3.x = v18;
      v20 = i_user_data[46];
      v34.v3.y = v19;
      v21 = i_user_data[47];
      v34.v3.z = v20;
      v34.v3.w = v21;
      UFG::TSActor::TeleportToTransformRaw(this, &v34);
    }
  }
}

// File Line: 1719
// RVA: 0x50DCA0
void __fastcall UFG::TSActor::Mthd_teleport_xform_preserve_vel(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  unsigned __int64 i_user_data; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  UFG::qMatrix44 v20; // [rsp+20h] [rbp-48h] BYREF

  if ( this->mpSimObj.m_pPointer )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_user_data);
    v5 = *(float *)(i_user_data + 132);
    v20.v0.x = *(float *)(i_user_data + 128);
    v6 = *(float *)(i_user_data + 136);
    v20.v0.y = v5;
    v7 = *(float *)(i_user_data + 140);
    v20.v0.z = v6;
    v8 = *(float *)(i_user_data + 144);
    v20.v0.w = v7;
    v9 = *(float *)(i_user_data + 148);
    v20.v1.x = v8;
    v10 = *(float *)(i_user_data + 152);
    v20.v1.y = v9;
    v11 = *(float *)(i_user_data + 156);
    v20.v1.z = v10;
    v12 = *(float *)(i_user_data + 160);
    v20.v1.w = v11;
    v13 = *(float *)(i_user_data + 164);
    v20.v2.x = v12;
    v14 = *(float *)(i_user_data + 168);
    v20.v2.y = v13;
    v15 = *(float *)(i_user_data + 172);
    v20.v2.z = v14;
    v16 = *(float *)(i_user_data + 176);
    v20.v2.w = v15;
    v17 = *(float *)(i_user_data + 180);
    v20.v3.x = v16;
    v18 = *(float *)(i_user_data + 184);
    v20.v3.y = v17;
    v19 = *(float *)(i_user_data + 188);
    v20.v3.z = v18;
    v20.v3.w = v19;
    UFG::TSActor::TeleportToTransformPreserveVel(this, &v20);
  }
}

// File Line: 1732
// RVA: 0x5068B0
void __fastcall UFG::TSActor::Mthd_reset_follow_camera(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( m_pSimObject )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
        if ( ComponentOfType )
          ComponentOfType->vfptr[16].__vecDelDtor(ComponentOfType, (unsigned int)m_pPointer);
      }
    }
  }
}

// File Line: 1752
// RVA: 0x4FE8F0
void __fastcall UFG::TSActor::Mthd_get_rim_boost(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = 0i64;
}

// File Line: 1775
// RVA: 0x501780
void __fastcall UFG::TSActor::Mthd_is_highlighted(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool IsHighlightSimObject; // dl

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    IsHighlightSimObject = 0;
    if ( m_pPointer )
    {
      if ( (this->i_actor_flags & 0x10000) == 0 )
        IsHighlightSimObject = UFG::IsHighlightSimObject(m_pPointer);
    }
    *ppResult = SSBoolean::pool_new(IsHighlightSimObject);
  }
}

// File Line: 1797
// RVA: 0x508AA0
void __fastcall UFG::TSActor::Mthd_set_is_highlighted(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::RadarSystem *v4; // rax
  UFG::RadarSystem *v5; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    {
      v4 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::AddRimLight(
        v4,
        (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)m_pPointer);
    }
    else
    {
      v5 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::RemoveRimLight(v5, m_pPointer);
    }
  }
}

// File Line: 1939
// RVA: 0x504CC0
void __fastcall UFG::TSActor::Mthd_minimap_add_blip(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  SSData **i_array_p; // r9

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    i_array_p = pScope->i_data.i_array_p;
    UFG::SimObjectUtility::AttachHudSymbol(
      m_pPointer,
      *(const char **)(*i_array_p)->i_data_p->i_user_data,
      i_array_p[1]->i_data_p->i_user_data != 0,
      *(float *)&i_array_p[2]->i_data_p->i_user_data,
      *(const char **)i_array_p[3]->i_data_p->i_user_data);
  }
}

// File Line: 1956
// RVA: 0x504D20
void __fastcall UFG::TSActor::Mthd_minimap_remove_blip(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
    UFG::SimObjectUtility::DetachHudSymbol(m_pPointer);
}

// File Line: 1971
// RVA: 0x4F5B60
void __fastcall UFG::TSActor::Mthd_audio_event(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rbx
  SSInstance *i_data_p; // rsi
  __int16 m_Flags; // cx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::ActorAudioComponent *v7; // rdi
  unsigned int v8; // eax
  unsigned int v9; // esi
  UFG::AudioEntity *m_SFXEntity; // rcx
  unsigned int v11; // edx
  __int16 v12; // cx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    v7 = ComponentOfTypeHK;
    v8 = UFG::TiDo::CalcWwiseUid(*(const char **)i_data_p->i_user_data);
    v9 = v8;
    if ( v7 )
    {
      m_SFXEntity = v7->m_SFXEntity;
      if ( m_SFXEntity )
      {
        v11 = v8;
LABEL_24:
        UFG::AudioEntity::CreateAndPlayEvent(m_SFXEntity, v11, 0i64, 0, 0i64);
        return;
      }
    }
    v12 = m_pPointer->m_Flags;
    if ( (v12 & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[40].m_pComponent;
    }
    else if ( v12 >= 0 )
    {
      if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HkAudioEntityComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HkAudioEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[28].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_SFXEntity = (UFG::AudioEntity *)&m_pComponent[1];
      v11 = v9;
      goto LABEL_24;
    }
  }
}

// File Line: 2004
// RVA: 0x4DA430
bool __fastcall UFG::TSActor::Coro_audio_event(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectGame *m_pPointer; // r8
  SSInstance *i_data_p; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int v8; // eax
  UFG::AudioEvent *m_pEvent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
    return 1;
  if ( pScope->i_update_count )
  {
    m_pEvent = this->m_audioController.m_pEvent;
    return !m_pEvent || (*((_BYTE *)m_pEvent + 144) & 0x40) == 0;
  }
  else
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[40].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HkAudioEntityComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HkAudioEntityComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[28].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = UFG::TiDo::CalcWwiseUid(*(const char **)i_data_p->i_user_data);
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&m_pComponent[1],
        v8,
        &this->m_audioController,
        0i64,
        0,
        0i64);
    }
    return 0;
  }
}

// File Line: 2040
// RVA: 0x4F5D80
void __fastcall UFG::TSActor::Mthd_audio_override_tagged_dialogue(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[8].m_pSimObject) ^= (LOBYTE(ComponentOfType[8].m_pSimObject) ^ (8
                                                                                           * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data == 0))) & 8;
  }
}

// File Line: 2054
// RVA: 0x4F5D20
void __fastcall UFG::TSActor::Mthd_audio_force_init(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        LOBYTE(ComponentOfType[8].m_pSimObject) |= 0x40u;
      else
        LOBYTE(ComponentOfType[8].m_pSimObject) &= ~0x40u;
    }
  }
}

// File Line: 2072
// RVA: 0x4F5CC0
void __fastcall UFG::TSActor::Mthd_audio_force_disable(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        LOBYTE(ComponentOfType[8].m_pSimObject) |= 0x80u;
      else
        LOBYTE(ComponentOfType[8].m_pSimObject) &= ~0x80u;
    }
  }
}

// File Line: 2089
// RVA: 0x4F5DD0
void __fastcall UFG::TSActor::Mthd_audio_set_obstruction_occlusion(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rbx
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rax
  float v8; // xmm1_4

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_data_p = i_array_p[1]->i_data_p;
      v8 = *(float *)&(*i_array_p)->i_data_p->i_user_data;
      if ( v8 >= 0.0 || *(float *)&i_data_p->i_user_data >= 0.0 )
      {
        UFG::AudioEntity::SetObstructionAndOcclusionTargets(
          (UFG::AudioEntity *)&ComponentOfType[1],
          v8,
          *(float *)&i_data_p->i_user_data,
          0);
        BYTE5(ComponentOfType[5].m_pSimObject) = 1;
      }
      else
      {
        BYTE5(ComponentOfType[5].m_pSimObject) = 0;
        BYTE3(ComponentOfType[5].m_pSimObject) = 1;
      }
    }
  }
}

// File Line: 2116
// RVA: 0x507EE0
void __fastcall UFG::TSActor::Mthd_set_facial_emotion(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
    {
      if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
        ComponentOfTypeHK->m_FacialEmotion = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    }
  }
}

// File Line: 2135
// RVA: 0x4DECD0
_BOOL8 __fastcall UFG::TSActor::Coro_wait_until_done_speaking(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // bl
  UFG::SimComponent *ComponentOfType; // rax
  bool v6; // zf
  char v7; // al
  _BOOL8 result; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 1;
  if ( m_pPointer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( SHIDWORD(ComponentOfType[6].m_BoundComponentHandles.mNode.mNext) <= 0
        || (v6 = ComponentOfType[6].m_SafePointerList.mNode.mNext == 0i64, v7 = 1, v6) )
      {
        v7 = 0;
      }
      v4 = v7 == 0;
    }
  }
  result = v4;
  if ( pScope->i_update_count <= 2 )
    return 0i64;
  return result;
}

// File Line: 2151
// RVA: 0x4DED40
bool __fastcall UFG::TSActor::Coro_wait_until_fight_over(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r8
  int v3; // ebp
  signed int v4; // edi
  SSList *i_user_data; // r15
  SSInstance *i_data_p; // r13
  signed int i_count; // r14d
  bool v8; // r12
  __int64 v9; // rbx
  SSInstance *v10; // rsi
  UFG::SimObjectGame *v11; // rcx
  SSObjectBaseVtbl *vfptr; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = 0;
  v4 = 0;
  i_user_data = (SSList *)(*i_array_p)->i_data_p->i_user_data;
  i_data_p = i_array_p[2]->i_data_p;
  i_count = i_user_data->i_items.i_count;
  v8 = i_array_p[3]->i_data_p->i_user_data != 0;
  if ( (int)i_user_data->i_items.i_count > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = i_user_data->i_items.i_array_p[v9];
      if ( (HIDWORD(v10[1].i_class_p) & 0x10000) != 0
        || (v11 = *(UFG::SimObjectGame **)&v10[4].i_ref_count) == 0i64
        || UFG::IsKnockedOut(v11)
        || (vfptr = v10[8].vfptr) == 0i64
        || ((__int64)vfptr[32].get_scope_context & 0x20) != 0 )
      {
        if ( v8 )
        {
          SSList::remove(i_user_data, v10, 1);
          --i_count;
          --v4;
          --v9;
        }
      }
      else
      {
        ++v3;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < i_count );
  }
  return v3 <= SLODWORD(i_data_p->i_user_data);
}

// File Line: 2268
// RVA: 0x4DA380
bool __fastcall UFG::TSActor::Coro_audio_dialogue_external_filename(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  char v3; // bl
  UFG::ActorAudioComponent *ComponentOfType; // rsi
  SSData **i_array_p; // rdx
  const char *v6; // rbx
  unsigned int v7; // eax

  v3 = 1;
  if ( pScope->i_update_count )
    return v3;
  if ( this->mpSimObj.m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                    this->mpSimObj.m_pPointer,
                                                    UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      v6 = *(const char **)i_array_p[1]->i_data_p->i_user_data;
      v7 = UFG::TiDo::CalcWwiseUid(*(const char **)(*i_array_p)->i_data_p->i_user_data);
      return UFG::ActorAudioComponent::QueueSpeechExternalMission(ComponentOfType, v7, v6, 0i64, 5u, 0) == 0;
    }
    return v3;
  }
  return 1;
}

// File Line: 2302
// RVA: 0x4DA280
bool __fastcall UFG::TSActor::Coro_audio_dialogue_external_context(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  char v3; // bl
  UFG::ActorAudioComponent *v4; // rsi
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  const char *v7; // rbx
  unsigned int v8; // eax
  char v9; // al
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  v3 = 1;
  if ( pScope->i_update_count )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( !m_pPointer )
      return v3;
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( !ComponentOfType )
      return v3;
    v9 = SHIDWORD(ComponentOfType[6].m_BoundComponentHandles.mNode.mNext) > 0
      && ComponentOfType[6].m_SafePointerList.mNode.mNext;
    return v9 == 0;
  }
  if ( !this->mpSimObj.m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
    return 1;
  v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                     this->mpSimObj.m_pPointer,
                                     UFG::ActorAudioComponent::_TypeUID);
  if ( v4 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = i_array_p[2]->i_data_p;
    v7 = *(const char **)i_array_p[1]->i_data_p->i_user_data;
    v8 = UFG::TiDo::CalcWwiseUid(*(const char **)(*i_array_p)->i_data_p->i_user_data);
    v9 = UFG::ActorAudioComponent::QueueSpeechExternalAmbient(v4, v8, v7, 0i64, i_data_p->i_user_data, 0, 0);
    return v9 == 0;
  }
  return v3;
}

// File Line: 2337
// RVA: 0x50C380
void __fastcall UFG::TSActor::Mthd_stop_speech(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::ActorAudioComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ActorAudioComponent::StopCurrentlyPlaying(ComponentOfType, 0);
  }
}

// File Line: 2349
// RVA: 0x50E3E0
void __fastcall UFG::TSActor::Mthd_unmount_facial_animset(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  hkgpIndexedMesh::EdgeBarrier *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (hkgpIndexedMesh::EdgeBarrier *)m_pPointer->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::DialogueAnimationComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::DialogueAnimationComponent::_TypeUID);
      m_pComponent = (hkgpIndexedMesh::EdgeBarrier *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        m_pComponent,
        *(hkgpIndexedMeshDefinitions::Edge **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2374
// RVA: 0x504A80
void __fastcall UFG::TSActor::Mthd_load_facefx_actor(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  AMD_HD3D *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (AMD_HD3D *)m_pPointer->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::DialogueAnimationComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::DialogueAnimationComponent::_TypeUID);
      m_pComponent = (AMD_HD3D *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      _(m_pComponent);
  }
}

// File Line: 2387
// RVA: 0x505D50
void __fastcall UFG::TSActor::Mthd_play_facial_anim(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  hkgpIndexedMesh::EdgeBarrier *m_pComponent; // r9
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (hkgpIndexedMesh::EdgeBarrier *)m_pPointer->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::DialogueAnimationComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::DialogueAnimationComponent::_TypeUID);
      m_pComponent = (hkgpIndexedMesh::EdgeBarrier *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        m_pComponent,
        *(hkgpIndexedMeshDefinitions::Edge **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2401
// RVA: 0x50E310
void __fastcall UFG::TSActor::Mthd_unload_facefx_actor(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[41].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::DialogueAnimationComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::DialogueAnimationComponent::_TypeUID);
    }
    if ( m_pComponent )
      _((AMD_HD3D *)m_pComponent);
  }
}

// File Line: 2415
// RVA: 0x4FD0B0
void __fastcall UFG::TSActor::Mthd_get_health(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned int vecDelDtor_high; // xmm6_4
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    vecDelDtor_high = (unsigned int)FLOAT_1_0;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
      if ( ComponentOfTypeHK )
      {
        vfptr = ComponentOfTypeHK[6].vfptr;
        if ( vfptr )
          vecDelDtor_high = HIDWORD(vfptr[33].__vecDelDtor);
      }
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, vecDelDtor_high);
  }
}

// File Line: 2440
// RVA: 0x4FDBF0
void __fastcall UFG::TSActor::Mthd_get_owner(UFG::TSActor *this, SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // r9
  __int16 m_Flags; // cx
  UFG::InventoryItemComponent *m_pComponent; // rax
  UFG::SimObject *OwnerSimObject; // rax

  if ( ppResult )
  {
    *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (this->i_actor_flags & 0x10000) == 0 )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = (UFG::InventoryItemComponent *)m_pPointer->m_Components.p[11].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            m_pComponent = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::InventoryItemComponent::_TypeUID);
          }
          else
          {
            m_pComponent = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::InventoryItemComponent::_TypeUID);
          }
          if ( m_pComponent )
          {
            OwnerSimObject = UFG::InventoryItemComponent::GetOwnerSimObject(m_pComponent);
            if ( OwnerSimObject )
              *ppResult = UFG::TSActor::SkookumObjFromSimObj(OwnerSimObject);
          }
        }
      }
    }
  }
}

// File Line: 2466
// RVA: 0x508190
void __fastcall UFG::TSActor::Mthd_set_fail_trigger(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                         m_pPointer,
                         UFG::MissionFailConditionComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::MissionFailConditionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    }
    if ( m_pComponent )
      UFG::MissionFailConditionComponent::SetFailTrigger(
        m_pPointer,
        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
        *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
  }
}

// File Line: 2484
// RVA: 0x5080C0
void __fastcall UFG::TSActor::Mthd_set_fail_threshold(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                         m_pPointer,
                         UFG::MissionFailConditionComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::MissionFailConditionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    }
    if ( m_pComponent )
      UFG::MissionFailConditionComponent::SetFailThreshold(
        m_pPointer,
        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
        *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  }
}

// File Line: 2502
// RVA: 0x507FF0
void __fastcall UFG::TSActor::Mthd_set_fail_caption(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                         m_pPointer,
                         UFG::MissionFailConditionComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::MissionFailConditionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    }
    if ( m_pComponent )
      UFG::MissionFailConditionComponent::SetFailCaption(
        m_pPointer,
        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  }
}

// File Line: 2526
// RVA: 0x5079F0
void __fastcall UFG::TSActor::Mthd_set_clip_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::GunComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::GunComponent::SetClipAmmo(ComponentOfTypeHK, (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2546
// RVA: 0x4FC1C0
void __fastcall UFG::TSActor::Mthd_get_clip_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned int ClipAmmo; // ebx
  __int16 m_Flags; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    ClipAmmo = 0;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::GunComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::GunComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        ClipAmmo = UFG::GunComponent::GetClipAmmo(ComponentOfTypeHK);
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, ClipAmmo);
  }
}

// File Line: 2573
// RVA: 0x5086B0
void __fastcall UFG::TSActor::Mthd_set_if_reset_ammo_on_death(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      *((_BYTE *)&ComponentOfTypeHK[3].m_SimObjIndex + 2) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2593
// RVA: 0x505950
void __fastcall UFG::TSActor::Mthd_override_rate_of_fire(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::GunComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::GunComponent::OverrideRateOfFire(
        ComponentOfTypeHK,
        (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0,
        *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  }
}

// File Line: 2614
// RVA: 0x4FCD50
void __fastcall UFG::TSActor::Mthd_get_fire_mode(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectProp *m_pPointer; // rcx
  unsigned int mFireMode; // ebx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectProp *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
    m_pPointer = 0i64;
  mFireMode = -1;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      goto LABEL_11;
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
      goto LABEL_13;
    }
    if ( (m_Flags & 0x1000) != 0 )
LABEL_11:
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_13:
    if ( ComponentOfTypeHK )
      mFireMode = ComponentOfTypeHK->mFireMode;
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, mFireMode);
}

// File Line: 2638
// RVA: 0x5082D0
void __fastcall UFG::TSActor::Mthd_set_fire_mode(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectProp *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectProp *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      goto LABEL_9;
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
      goto LABEL_11;
    }
    if ( (m_Flags & 0x1000) != 0 )
LABEL_9:
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_11:
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->mFireMode = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 2659
// RVA: 0x508CF0
void __fastcall UFG::TSActor::Mthd_set_must_hit_target(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  SSInstance *i_data_p; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v9; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol.mUID = i_data_p->i_user_data;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
      v9 = ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
        LODWORD(v9[3].m_SafePointerList.mNode.mNext) = pTrackEnumBinding.m_EnumValue;
      }
    }
    v10 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v10;
  }
}

// File Line: 2685
// RVA: 0x4F64C0
void __fastcall UFG::TSActor::Mthd_clear_must_hit_target(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      LODWORD(ComponentOfTypeHK[3].m_SafePointerList.mNode.mNext) = 0;
  }
}

// File Line: 2705
// RVA: 0x50B120
void __fastcall UFG::TSActor::Mthd_set_triad_wars_player_id(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::TriadWarsComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::TriadWarsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::TriadWarsComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::TriadWarsComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::TriadWarsComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::TriadWarsComponent::SetOwnerPlayerId(ComponentOfTypeHK, (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2723
// RVA: 0x4FF530
void __fastcall UFG::TSActor::Mthd_get_weapon_type(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectProp *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::FireModeInfo *v8; // rcx
  EnumList<unsigned long> *v9; // rax
  ASymbol *v10; // rax
  ASymbol *null; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  if ( !ppResult )
    return;
  m_pPointer = (UFG::SimObjectProp *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
  {
LABEL_17:
    null = ASymbol::get_null();
    *ppResult = SSSymbol::as_instance(null);
    return;
  }
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    goto LABEL_10;
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
    goto LABEL_12;
  }
  if ( (m_Flags & 0x1000) != 0 )
LABEL_10:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     m_pPointer,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     m_pPointer,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_12:
  if ( !ComponentOfTypeHK )
    goto LABEL_17;
  v8 = ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode];
  if ( (int)UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size <= 0 )
    v9 = 0i64;
  else
    v9 = *UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p;
  v10 = (ASymbol *)UFG::qSymbol::create_from_string(&result, v9->m_enumName.p[v8->mSimObjectWeaponType]);
  *ppResult = SSSymbol::as_instance(v10);
}

// File Line: 2749
// RVA: 0x50B070
void __fastcall UFG::TSActor::Mthd_set_total_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::GunComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::GunComponent::SetTotalAmmo(ComponentOfTypeHK, (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2770
// RVA: 0x4FF160
void __fastcall UFG::TSActor::Mthd_get_total_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned int TotalAmmo; // ebx
  __int16 m_Flags; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    TotalAmmo = 0;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::GunComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::GunComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        TotalAmmo = UFG::GunComponent::GetTotalAmmo(ComponentOfTypeHK);
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, TotalAmmo);
  }
}

// File Line: 2797
// RVA: 0x4F3D70
void __fastcall UFG::TSActor::Mthd_add_clip_to_gun(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::GunComponent::AddClipOfAmmo(ComponentOfTypeHK);
  }
}

// File Line: 2815
// RVA: 0x501D00
void __fastcall UFG::TSActor::Mthd_is_in_view(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v5; // bp
  UFG::SimComponent *m_pSimComponent; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // r14
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v11; // xmm12_4
  float v12; // xmm11_4
  float v13; // xmm10_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  __m128 v20; // xmm2
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  __m128 v24; // xmm2
  float v25; // xmm4_4
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm8_4
  float v29; // xmm6_4
  float v30; // [rsp+20h] [rbp-148h]
  float v31; // [rsp+30h] [rbp-138h]
  float v32; // [rsp+38h] [rbp-130h]
  float v33; // [rsp+44h] [rbp-124h]
  float v34; // [rsp+48h] [rbp-120h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-118h] BYREF
  __int64 v36; // [rsp+90h] [rbp-D8h]
  float v37; // [rsp+180h] [rbp+18h]

  if ( ppResult )
  {
    v36 = -2i64;
    v5 = 0;
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    if ( (_S8_14 & 1) == 0 )
      _S8_14 |= 1u;
    if ( UFG::Metrics::msInstance.mSimFrameCount != frustum_frame_number )
    {
      frustum_frame_number = UFG::Metrics::msInstance.mSimFrameCount;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mCamera = &mCurrentCamera->mCamera;
      else
        p_mCamera = 0i64;
      ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
      WorldView = UFG::Camera::GetWorldView(p_mCamera);
      UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
      LODWORD(v11) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
      LODWORD(v12) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
      LODWORD(v13) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
      LODWORD(v14) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
      LODWORD(v15) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
      LODWORD(v16) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
      LODWORD(v37) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
      LODWORD(v34) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
      LODWORD(v33) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
      LODWORD(v32) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
      LODWORD(v31) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
      LODWORD(v30) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
      v17 = fsqrt(
              (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                    + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
            + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
      frustum_planes[0].x = (float)(1.0 / v17) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
      *(float *)&dword_14240D6E4 = (float)(1.0 / v17) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
      *(float *)&dword_14240D6E8 = (float)(1.0 / v17) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
      *(float *)&dword_14240D6EC = (float)(1.0 / v17) * COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]);
      v18 = fsqrt((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13));
      *(float *)&dword_14240D6F0 = (float)(1.0 / v18) * v11;
      *(float *)&dword_14240D6F4 = (float)(1.0 / v18) * v12;
      *(float *)&dword_14240D6F8 = (float)(1.0 / v18) * v13;
      *(float *)&dword_14240D6FC = (float)(1.0 / v18)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
      v19 = fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16));
      *(float *)&dword_14240D700 = (float)(1.0 / v19) * v14;
      *(float *)&dword_14240D704 = (float)(1.0 / v19) * v15;
      *(float *)&dword_14240D708 = (float)(1.0 / v19) * v16;
      *(float *)&dword_14240D70C = (float)(1.0 / v19)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]);
      v20 = (__m128)LODWORD(v37);
      LODWORD(v21) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
      LODWORD(v22) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
      v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v21 * v21)) + (float)(v22 * v22);
      v23 = _mm_sqrt_ps(v20).m128_f32[0];
      *(float *)&dword_14240D710 = (float)(1.0 / v23) * v21;
      *(float *)&dword_14240D714 = (float)(1.0 / v23) * v37;
      *(float *)&dword_14240D718 = (float)(1.0 / v23) * v22;
      *(float *)&dword_14240D71C = (float)(1.0 / v23)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]);
      v24 = (__m128)LODWORD(v34);
      LODWORD(v25) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
      v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v25 * v25)) + (float)(v33 * v33);
      v26 = _mm_sqrt_ps(v24).m128_f32[0];
      *(float *)&dword_14240D720 = (float)(1.0 / v26) * v25;
      *(float *)&dword_14240D724 = (float)(1.0 / v26) * v34;
      *(float *)&dword_14240D728 = (float)(1.0 / v26) * v33;
      *(float *)&dword_14240D72C = (float)(1.0 / v26)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]);
      v27 = (__m128)LODWORD(v32);
      v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v31 * v31)) + (float)(v30 * v30);
      v28 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
      *(float *)&dword_14240D730 = v28 * v32;
      *(float *)&dword_14240D734 = v28 * v31;
      *(float *)&dword_14240D738 = v28 * v30;
      *(float *)&dword_14240D73C = v28 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]);
    }
    if ( m_pSimComponent )
    {
      v29 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
      v5 = IntersectSphereFrustum(frustum_planes, (UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles, v29) != 2;
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 2850
// RVA: 0x4D9AE0
bool __fastcall UFG::TSActor::Coro_animate(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // rsi
  bool v5; // r14
  bool v6; // r15
  const char *v7; // rsi
  ActionNodePlayable *v8; // rsi
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax
  __int16 v11; // cx
  UFG::ActionTreeComponent *m_pComponent; // rax
  ActionController *p_mActionController; // rcx
  bool v14; // bl
  int mCount; // edx
  __int16 v17; // cx
  UFG::SimComponent *v18; // rbx
  UFG::SimComponent *v19; // rax
  const char *v20; // rdx
  ActionPath absolutePath; // [rsp+28h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
    return 1;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p->i_user_data != 0;
  v6 = i_array_p[2]->i_data_p->i_user_data != 0;
  if ( !pScope->i_update_count )
  {
    absolutePath.mPath.mCount = 0;
    absolutePath.mPath.mData.mOffset = 0i64;
    v7 = *(const char **)i_data_p->i_user_data;
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = 0;
    ActionPath::Append(&absolutePath, v7);
    v8 = (ActionNodePlayable *)ActionNode::Find(&absolutePath, 0i64);
    if ( v8 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pPointer,
                                                               UFG::PowerManagementComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pPointer,
                                                               UFG::PowerManagementComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        UFG::PowerManagementComponent::PreventSuspendTemporarily(ComponentOfTypeHK, 10.0);
      v11 = m_pPointer->m_Flags;
      if ( (v11 & 0x4000) != 0 )
      {
        m_pComponent = (UFG::ActionTreeComponent *)m_pPointer->m_Components.p[7].m_pComponent;
      }
      else if ( v11 >= 0 )
      {
        if ( (v11 & 0x2000) != 0 )
        {
          m_pComponent = (UFG::ActionTreeComponent *)m_pPointer->m_Components.p[6].m_pComponent;
        }
        else if ( (v11 & 0x1000) != 0 )
        {
          m_pComponent = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::ActionTreeComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = (UFG::ActionTreeComponent *)m_pPointer->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent )
      {
        p_mActionController = &m_pComponent->mActionController;
        if ( v6 )
          ActionController::PlayTracks(p_mActionController, v8, 0, 0.0);
        else
          ActionController::Play(p_mActionController, v8, 0);
      }
    }
    v14 = !v5;
    mCount = absolutePath.mPath.mCount;
    if ( absolutePath.mPath.mCount < 0 )
      return v14;
    if ( absolutePath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        mCount = absolutePath.mPath.mCount;
      }
    }
    goto LABEL_31;
  }
  if ( !i_array_p[1]->i_data_p->i_user_data )
    return 1;
  v17 = m_pPointer->m_Flags;
  if ( (v17 & 0x4000) != 0 )
  {
    v18 = m_pPointer->m_Components.p[7].m_pComponent;
  }
  else if ( v17 >= 0 )
  {
    if ( (v17 & 0x2000) != 0 )
    {
      v18 = m_pPointer->m_Components.p[6].m_pComponent;
    }
    else
    {
      v19 = (v17 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
      v18 = v19;
    }
  }
  else
  {
    v18 = m_pPointer->m_Components.p[7].m_pComponent;
  }
  if ( !v18 )
    return 1;
  v20 = *(const char **)i_data_p->i_user_data;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, v20);
  v14 = !ActionController::IsPlayingFullPath((ActionController *)&v18[3], &absolutePath, 1);
  mCount = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount < 0 )
    return v14;
  if ( !absolutePath.mPath.mData.mOffset
    || !(UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
  {
LABEL_31:
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = mCount & 0x80000000;
    return v14;
  }
  operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  absolutePath.mPath.mData.mOffset = 0i64;
  absolutePath.mPath.mCount &= 0x80000000;
  return v14;
}

// File Line: 2952
// RVA: 0x4F3920
void __fastcall UFG::TSActor::Mthd_action_tree_query(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v6; // si
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v10; // rax
  SSInstance *i_data_p; // rax
  const char *v12; // rbp
  ActionNode *v13; // rax
  int mCount; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h] BYREF

  if ( ppResult )
  {
    v6 = 0;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
        }
        else
        {
          v10 = (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = v10;
        }
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent )
      {
        i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
        absolutePath.mPath.mCount = 0;
        absolutePath.mPath.mData.mOffset = 0i64;
        v12 = *(const char **)i_data_p->i_user_data;
        absolutePath.mPath.mData.mOffset = 0i64;
        absolutePath.mPath.mCount = 0;
        ActionPath::Append(&absolutePath, v12);
        v13 = ActionNode::Find(&absolutePath, 0i64);
        if ( v13 )
          v6 = ((__int64 (__fastcall *)(ActionNode *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v13->vfptr[2].GetClassNameUID)(
                 v13,
                 m_pComponent[2].m_BoundComponentHandles.mNode.mNext) != 0;
        mCount = absolutePath.mPath.mCount;
        if ( absolutePath.mPath.mCount >= 0 )
        {
          if ( absolutePath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
              mCount = absolutePath.mPath.mCount;
            }
          }
          absolutePath.mPath.mData.mOffset = 0i64;
          absolutePath.mPath.mCount = mCount & 0x80000000;
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 2984
// RVA: 0x502F20
void __fastcall UFG::TSActor::Mthd_is_playing_node(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned __int8 IsPlaying; // si
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ActionID node_id; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    IsPlaying = 0;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent )
      {
        node_id.mUID = UFG::qStringHashUpper32(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, -1);
        IsPlaying = ActionController::IsPlaying((ActionController *)&m_pComponent[3], &node_id, 0xFFFFFFFF, 1);
      }
    }
    *ppResult = SSBoolean::pool_new(IsPlaying);
  }
}

// File Line: 3020
// RVA: 0x502B10
void __fastcall UFG::TSActor::Mthd_is_playing_ai_node(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned __int8 IsPlaying; // si
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ActionID node_id; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    IsPlaying = 0;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIActionTreeComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIActionTreeComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
      }
      if ( m_pComponent )
      {
        node_id.mUID = UFG::qStringHashUpper32(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, -1);
        IsPlaying = ActionController::IsPlaying((ActionController *)&m_pComponent[3].m_TypeUID, &node_id, 0xFFFFFFFF, 1);
      }
    }
    *ppResult = SSBoolean::pool_new(IsPlaying);
  }
}

// File Line: 3057
// RVA: 0x502D80
void __fastcall UFG::TSActor::Mthd_is_playing_full_path_node(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool IsPlayingFullPath; // si
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v10; // rax
  const char *v11; // rdx
  int mCount; // edx
  ActionPath animPath; // [rsp+28h] [rbp-20h] BYREF

  if ( ppResult )
  {
    IsPlayingFullPath = 0;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
        }
        else
        {
          v10 = (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = v10;
        }
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent )
      {
        v11 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
        animPath.mPath.mCount = 0;
        animPath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&animPath, v11);
        IsPlayingFullPath = ActionController::IsPlayingFullPath((ActionController *)&m_pComponent[3], &animPath, 1);
        mCount = animPath.mPath.mCount;
        if ( animPath.mPath.mCount >= 0 )
        {
          if ( animPath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset);
              mCount = animPath.mPath.mCount;
            }
          }
          animPath.mPath.mData.mOffset = 0i64;
          animPath.mPath.mCount = mCount & 0x80000000;
        }
      }
    }
    *ppResult = SSBoolean::pool_new(IsPlayingFullPath);
  }
}

// File Line: 3095
// RVA: 0x502C20
void __fastcall UFG::TSActor::Mthd_is_playing_full_path_ai_node(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool IsPlayingFullPath; // si
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  const char *v11; // rdx
  int mCount; // edx
  ActionPath animPath; // [rsp+28h] [rbp-20h] BYREF

  if ( ppResult )
  {
    IsPlayingFullPath = 0;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIActionTreeComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIActionTreeComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
      }
      if ( m_pComponent )
      {
        v11 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
        animPath.mPath.mCount = 0;
        animPath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&animPath, v11);
        IsPlayingFullPath = ActionController::IsPlayingFullPath(
                              (ActionController *)&m_pComponent[3].m_TypeUID,
                              &animPath,
                              1);
        mCount = animPath.mPath.mCount;
        if ( animPath.mPath.mCount >= 0 )
        {
          if ( animPath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset);
              mCount = animPath.mPath.mCount;
            }
          }
          animPath.mPath.mData.mOffset = 0i64;
          animPath.mPath.mCount = mCount & 0x80000000;
        }
      }
    }
    *ppResult = SSBoolean::pool_new(IsPlayingFullPath);
  }
}

// File Line: 3134
// RVA: 0x4F7830
void __fastcall UFG::TSActor::Mthd_dbg_get_playing_full_path(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 Clone; // rax
  char *v9; // rsi
  __int64 v10; // rbx
  unsigned int v11; // eax
  char v12; // di
  AString *p_elem; // rcx
  AStringRef *i_str_ref_p; // rbx
  bool v15; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v19; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *v21; // rbx
  AObjReusePool<AStringRef> *v22; // rax
  AObjBlock<AStringRef> *v23; // rcx
  unsigned __int64 v24; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AString str; // [rsp+70h] [rbp+18h] BYREF
  AStringRef *elem; // [rsp+78h] [rbp+20h] BYREF

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (this->i_actor_flags & 0x10000) == 0
      && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[6].m_pComponent))
         : (ComponentOfType = m_pPointer->m_Components.p[7].m_pComponent))
        : (ComponentOfType = m_pPointer->m_Components.p[7].m_pComponent),
          ComponentOfType
       && (Clone = TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)&ComponentOfType[3]),
           (v9 = (char *)Clone) != 0i64)) )
    {
      v10 = -1i64;
      do
        ++v10;
      while ( *(_BYTE *)(Clone + v10) );
      v11 = AMemory::c_req_byte_size_func(v10 + 1);
      v12 = 1;
      elem = AStringRef::pool_new(v9, v10, v11, 1u, 0, 1);
      p_elem = (AString *)&elem;
    }
    else
    {
      str.i_str_ref_p = AStringRef::get_empty();
      ++str.i_str_ref_p->i_ref_count;
      p_elem = &str;
      v12 = 2;
    }
    *ppResult = SSString::as_instance(p_elem);
    if ( (v12 & 2) != 0 )
    {
      v12 &= ~2u;
      i_str_ref_p = str.i_str_ref_p;
      v15 = str.i_str_ref_p->i_ref_count-- == 1;
      if ( v15 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < i_objects_a
          || (v19 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
              p_i_exp_pool = &pool->i_pool,
              !v19) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
      }
    }
    if ( (v12 & 1) != 0 )
    {
      v21 = elem;
      v15 = elem->i_ref_count-- == 1;
      if ( v15 )
      {
        if ( v21->i_deallocate )
          AMemory::c_free_func(v21->i_cstr_p);
        v22 = AStringRef::get_pool();
        v23 = v22->i_block_p;
        v24 = (unsigned __int64)v23->i_objects_a;
        if ( (unsigned __int64)v21 < v24
          || (v19 = (unsigned __int64)v21 < v24 + 24i64 * v23->i_size, p_i_pool = &v22->i_pool, !v19) )
        {
          p_i_pool = &v22->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v21);
      }
    }
  }
}

// File Line: 3159
// RVA: 0x506E00
void __fastcall UFG::TSActor::Mthd_set_action_tree_opening_branch(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v8; // rax
  SSInstance *i_data_p; // rax
  const char *v10; // rdi
  ActionNode *v11; // rax
  ActionPath absolutePath; // [rsp+28h] [rbp-20h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      else
      {
        v8 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = v8;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
    {
      i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
      absolutePath.mPath.mCount = 0;
      absolutePath.mPath.mData.mOffset = 0i64;
      v10 = *(const char **)i_data_p->i_user_data;
      absolutePath.mPath.mData.mOffset = 0i64;
      absolutePath.mPath.mCount = 0;
      ActionPath::Append(&absolutePath, v10);
      v11 = ActionNode::Find(&absolutePath, 0i64);
      if ( v11 )
        m_pComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v11;
      if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
      {
        if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
          operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      }
    }
  }
}

// File Line: 3196
// RVA: 0x5061A0
void __fastcall UFG::TSActor::Mthd_pwr_suspend_allow(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::PowerManagementComponent::AllowSuspend(ComponentOfTypeHK);
  }
}

// File Line: 3216
// RVA: 0x506240
void __fastcall UFG::TSActor::Mthd_pwr_suspend_prevent(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::PowerManagementComponent::PreventSuspendIndefinitely(ComponentOfTypeHK);
  }
}

// File Line: 3236
// RVA: 0x50A8C0
void __fastcall UFG::TSActor::Mthd_set_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rdi
  __int64 v6; // rax
  UFG::SimObjectGame *m_pPointer; // rbx
  UFG::qSymbol *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // cx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  v6 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 && ArgByNameOrInstance )
  {
    v8 = UFG::qSymbol::create_from_string(&result, **(const char ***)(v6 + 32));
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v8->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < NUM_TARGET_TYPES )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
        UFG::TargetingSystemBaseComponent::SetTarget(
          m_pComponent,
          (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
          (UFG::SimObject *)ArgByNameOrInstance);
    }
    v12 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v12;
  }
}

// File Line: 3270
// RVA: 0x4FEDE0
void __fastcall UFG::TSActor::Mthd_get_target(UFG::TSActor *this, SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+20h] BYREF

  if ( ppResult )
  {
    *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (this->i_actor_flags & 0x10000) == 0 )
      {
        v5 = UFG::qSymbol::create_from_string(
               &result,
               *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
        pTrackEnumBinding.mPrev = &pTrackEnumBinding;
        pTrackEnumBinding.mNext = &pTrackEnumBinding;
        pTrackEnumBinding.m_EnumSymbol.mUID = -1;
        pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
        *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
        pTrackEnumBinding.m_uEnumUID = 0;
        if ( UFG::gTargetTypeEnum.m_enumLists.size )
        {
          TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
        }
        else
        {
          mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
          pTrackEnumBinding.mPrev = mPrev;
          pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
        }
        if ( pTrackEnumBinding.m_EnumValue < 0x5B )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pPointer,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                    m_pPointer,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
          else
          {
            m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
          }
          if ( m_pComponent )
            *ppResult = UFG::TSActor::SkookumObjFromSimObj(*(UFG::SimObject **)(56i64
                                                                              * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64)
                                                                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                                                              + 40));
        }
        v10 = pTrackEnumBinding.mPrev;
        mNext = pTrackEnumBinding.mNext;
        pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
        mNext->mPrev = v10;
      }
    }
  }
}

// File Line: 3308
// RVA: 0x4FEFA0
void __fastcall UFG::TSActor::Mthd_get_target_as_simobject(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+20h] BYREF

  if ( ppResult )
  {
    *ppResult = SSBrain::c_nil_p;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (this->i_actor_flags & 0x10000) == 0 )
      {
        v5 = UFG::qSymbol::create_from_string(
               &result,
               *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
        pTrackEnumBinding.mPrev = &pTrackEnumBinding;
        pTrackEnumBinding.mNext = &pTrackEnumBinding;
        pTrackEnumBinding.m_EnumSymbol.mUID = -1;
        pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
        *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
        pTrackEnumBinding.m_uEnumUID = 0;
        if ( UFG::gTargetTypeEnum.m_enumLists.size )
        {
          TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
        }
        else
        {
          mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
          pTrackEnumBinding.mPrev = mPrev;
          pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
        }
        if ( pTrackEnumBinding.m_EnumValue < 0x5B )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pPointer,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                    m_pPointer,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
          else
          {
            m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
          }
          if ( m_pComponent )
            *ppResult = SSInstance::pool_new(
                          UFG::TSSimObject::mspSimObjectClass,
                          *(_QWORD *)(56i64
                                    * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                         + pTrackEnumBinding.m_EnumValue
                                                         + 8i64)
                                    + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                    + 40));
        }
        v10 = pTrackEnumBinding.mPrev;
        mNext = pTrackEnumBinding.mNext;
        pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
        mNext->mPrev = v10;
      }
    }
  }
}

// File Line: 3351
// RVA: 0x4F6650
void __fastcall UFG::TSActor::Mthd_clear_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // cx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    v4 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v4->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
        UFG::TargetingSystemBaseComponent::ClearTarget(
          m_pComponent,
          (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue);
    }
    v8 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v8;
  }
}

// File Line: 3385
// RVA: 0x50ABE0
void __fastcall UFG::TSActor::Mthd_set_target_lock(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  SSData **i_array_p; // rdx
  bool v5; // di
  bool v6; // si
  UFG::qSymbol *v7; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+90h] [rbp+20h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    i_array_p = pScope->i_data.i_array_p;
    v5 = i_array_p[1]->i_data_p->i_user_data != 0;
    v6 = i_array_p[2]->i_data_p->i_user_data != 0;
    v7 = UFG::qSymbol::create_from_string(&result, *(const char **)(*i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v7->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
        ((void (__fastcall *)(UFG::SimComponent *, _QWORD, bool, bool, _DWORD, const char *, _QWORD, _QWORD, __int64))m_pComponent->vfptr[14].__vecDelDtor)(
          m_pComponent,
          pTrackEnumBinding.m_EnumValue,
          v5,
          v6,
          0,
          "TSActor::Mthd_set_target_lock",
          0i64,
          0i64,
          -2i64);
    }
    v12 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v12;
  }
}

// File Line: 3421
// RVA: 0x50ADC0
void __fastcall UFG::TSActor::Mthd_set_target_prop(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // dx
  UFG::AIScriptInterfaceComponent *m_pComponent; // rax
  UFG::SimObjectGame *v10; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
            i_class_p,
            *i_array_p,
            ppResult) )
    {
      if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
        return;
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
    }
    if ( i_data_p )
    {
      m_pPointer = this->mpSimObj.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::AIScriptInterfaceComponent *)m_pPointer->m_Components.p[5].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v10 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = (UFG::AIScriptInterfaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v10,
                                                                UFG::AIScriptInterfaceComponent::_TypeUID);
          else
            m_pComponent = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                v10,
                                                                UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::AIScriptInterfaceComponent *)m_pPointer->m_Components.p[5].m_pComponent;
        }
        if ( m_pComponent )
          UFG::AIScriptInterfaceComponent::SetDesiredTarget(
            m_pComponent,
            eTARGET_TYPE_INTERACTIVE_PROP,
            *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)&i_data_p[1].i_icoroutines_to_update.i_count);
      }
    }
  }
}

// File Line: 3439
// RVA: 0x50A700
void __fastcall UFG::TSActor::Mthd_set_subtarget(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  SSInstance *i_data_p; // rbx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    m_pPointer,
                                                                    UFG::TargetingSystemPedBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                    m_pPointer,
                                                                    UFG::TargetingSystemPedBaseComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::TargetingSystemPedBaseComponent::SetFocusTargetSubTargetingLocationOverride(
        ComponentOfTypeHK,
        (UFG::qSymbol *)&i_data_p->i_user_data);
  }
}

// File Line: 3464
// RVA: 0x507110
void __fastcall UFG::TSActor::Mthd_set_attack_target(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // dx
  UFG::AIScriptInterfaceComponent *m_pComponent; // rax
  UFG::SimObjectGame *v10; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
            i_class_p,
            *i_array_p,
            ppResult) )
    {
      if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
        return;
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
    }
    if ( i_data_p )
    {
      m_pPointer = this->mpSimObj.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::AIScriptInterfaceComponent *)m_pPointer->m_Components.p[5].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v10 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = (UFG::AIScriptInterfaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v10,
                                                                UFG::AIScriptInterfaceComponent::_TypeUID);
          else
            m_pComponent = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                v10,
                                                                UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::AIScriptInterfaceComponent *)m_pPointer->m_Components.p[5].m_pComponent;
        }
        if ( m_pComponent )
          UFG::AIScriptInterfaceComponent::SetDesiredTarget(
            m_pComponent,
            eTARGET_TYPE_FOCUS,
            *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)&i_data_p[1].i_icoroutines_to_update.i_count);
      }
    }
  }
}

// File Line: 3482
// RVA: 0x503690
void __fastcall UFG::TSActor::Mthd_is_target_valid(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v5; // si
  UFG::qSymbol *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+20h] BYREF

  if ( ppResult )
  {
    v5 = 0;
    v6 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v6->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
          v5 = *(_QWORD *)(56i64
                         * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                              + pTrackEnumBinding.m_EnumValue
                                              + 8i64)
                         + *(_QWORD *)&m_pComponent[1].m_TypeUID
                         + 40) != 0i64;
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
    v12 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v12;
  }
}

// File Line: 3519
// RVA: 0x5034C0
void __fastcall UFG::TSActor::Mthd_is_target_locked(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v5; // bl
  UFG::qSymbol *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v12; // rdx
  __int64 v13; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+20h] BYREF

  if ( ppResult )
  {
    v5 = 0;
    v6 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v6->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
        {
          v12 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64);
          v13 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
          v5 = *(_QWORD *)(v12 + v13 + 40) && *(_BYTE *)(v12 + v13 + 49);
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
    v14 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v14;
  }
}

// File Line: 3555
// RVA: 0x4FD390
void __fastcall UFG::TSActor::Mthd_get_inventory_item(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // r9
  __int16 m_Flags; // cx
  UFG::InventoryComponent *ComponentOfType; // rax
  ASymbol *null; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( !m_pPointer
      || (this->i_actor_flags & 0x10000) != 0
      || (m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0)
      || m_Flags < 0
      || ((m_Flags & 0x2000) == 0
        ? ((m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::InventoryItemComponent::_TypeUID))
         : (ComponentOfType = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::InventoryItemComponent::_TypeUID)))
        : (ComponentOfType = (UFG::InventoryComponent *)m_pPointer->m_Components.p[11].m_pComponent),
          !ComponentOfType) )
    {
      null = ASymbol::get_null();
      *ppResult = SSSymbol::as_instance(null);
    }
    else
    {
      *ppResult = SSSymbol::as_instance((ASymbol *)&ComponentOfType->m_InventoryItems[4]);
    }
  }
}

// File Line: 3588
// RVA: 0x508800
void __fastcall UFG::TSActor::Mthd_set_interaction_point_active(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdx
  bool v6; // di
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int16 m_Flags; // cx
  UFG::InteractableComponent *m_pComponent; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v6 = i_array_p[1]->i_data_p->i_user_data != 0;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol.mUID = i_data_p->i_user_data;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::InteractableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::InteractableComponent::_TypeUID);
        else
          m_pComponent = (UFG::InteractableComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::InteractableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      if ( m_pComponent )
        UFG::InteractableComponent::SetIsActive(m_pComponent, (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue, v6);
    }
    v10 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v10;
  }
}

// File Line: 3613
// RVA: 0x5073D0
void __fastcall UFG::TSActor::Mthd_set_best_interaction_point(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int64 m_EnumValue; // rdi
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::InteractableComponent *v14; // rsi
  UFG::SimComponent *v15; // rax
  __int16 v16; // cx
  UFG::InteractorComponent *v17; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSymbol *v19; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::InteractionPoint *InteractionPoint; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v22; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v24; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v25; // rax
  TracksEnumBinding<unsigned long> v26; // [rsp+28h] [rbp-48h] BYREF
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+A0h] [rbp+30h] BYREF

  v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gTargetTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v11;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v12 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + m_EnumValue + 8)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 )
        {
          v14 = (UFG::InteractableComponent *)v12->m_Components.p[12].m_pComponent;
        }
        else if ( v13 >= 0 )
        {
          v15 = (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::InteractableComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v12, UFG::InteractableComponent::_TypeUID);
          v14 = (UFG::InteractableComponent *)v15;
        }
        else
        {
          v14 = (UFG::InteractableComponent *)v12->m_Components.p[12].m_pComponent;
        }
        if ( v14 )
        {
          v16 = m_pPointer->m_Flags;
          if ( (v16 & 0x4000) != 0 )
          {
            v17 = (UFG::InteractorComponent *)m_pPointer->m_Components.p[29].m_pComponent;
          }
          else
          {
            if ( v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pPointer,
                                    UFG::InteractorComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractorComponent::_TypeUID);
            v17 = (UFG::InteractorComponent *)ComponentOfTypeHK;
          }
          if ( v17 )
          {
            v19 = UFG::qSymbol::create_from_string(
                    &result,
                    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
            v26.mPrev = &v26;
            v26.mNext = &v26;
            v26.m_EnumSymbol.mUID = -1;
            v26.m_EnumSymbol = (UFG::qSymbol)v19->mUID;
            *(_QWORD *)&v26.m_EnumValue = 0i64;
            v26.m_uEnumUID = 0;
            if ( UFG::gTargetTypeEnum.m_enumLists.size )
            {
              TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &v26);
            }
            else
            {
              v20 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
              UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &v26;
              v26.mPrev = v20;
              v26.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
              UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &v26;
            }
            InteractionPoint = UFG::InteractableComponent::FindInteractionPoint(
                                 v14,
                                 m_pPointer,
                                 (UFG::eTargetTypeEnum)v26.m_EnumValue,
                                 1);
            if ( InteractionPoint )
              UFG::InteractorComponent::SetBestInteractionPoint(v17, InteractionPoint, 1);
            v22 = v26.mPrev;
            mNext = v26.mNext;
            v26.mPrev->mNext = v26.mNext;
            mNext->mPrev = v22;
            v26.mPrev = &v26;
            v26.mNext = &v26;
          }
        }
      }
    }
  }
  v24 = pTrackEnumBinding.mPrev;
  v25 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v25->mPrev = v24;
}

// File Line: 3699
// RVA: 0x500EB0
void __fastcall UFG::TSActor::Mthd_is_best_interaction_point_busy(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v4; // bl
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[29].m_pComponent;
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractorComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractorComponent::_TypeUID);
      }
      if ( m_pComponent )
      {
        mNext = m_pComponent[1].m_SafePointerList.mNode.mNext;
        if ( mNext )
          v4 = LODWORD(mNext[2].mPrev) != 0;
      }
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 3737
// RVA: 0x4F55F0
void __fastcall UFG::TSActor::Mthd_attach_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  SSData **i_array_p; // rdx
  float blendInTime; // xmm6_4
  bool attachRelative; // si
  bool attachToTarget; // r14
  bool addToInventory; // r15
  bool v14; // r12
  UFG::qSymbol *v15; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v16; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v17; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v19; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v21; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v22; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp-39h] BYREF
  UFG::eTargetTypeEnum assignmentTargetType[2]; // [rsp+60h] [rbp-31h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+68h] [rbp-29h] BYREF
  TracksEnumBinding<unsigned long> v26; // [rsp+88h] [rbp-9h] BYREF
  UFG::qSymbolUC targetAttachJoint; // [rsp+F8h] [rbp+67h] BYREF
  UFG::qSymbolUC attachJoint; // [rsp+110h] [rbp+7Fh] BYREF

  *(_QWORD *)assignmentTargetType = -2i64;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      UFG::qSymbolUC::create_from_string(
        &attachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      UFG::qSymbolUC::create_from_string(
        &targetAttachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
      i_array_p = pScope->i_data.i_array_p;
      blendInTime = *(float *)&i_array_p[3]->i_data_p->i_user_data;
      attachRelative = i_array_p[4]->i_data_p->i_user_data != 0;
      attachToTarget = i_array_p[5]->i_data_p->i_user_data != 0;
      addToInventory = i_array_p[6]->i_data_p->i_user_data != 0;
      v14 = i_array_p[7]->i_data_p->i_user_data != 0;
      v15 = UFG::qSymbol::create_from_string(&result, *(const char **)i_array_p[8]->i_data_p->i_user_data);
      v26.mPrev = &v26;
      v26.mNext = &v26;
      v26.m_EnumSymbol.mUID = -1;
      v26.m_EnumSymbol = (UFG::qSymbol)v15->mUID;
      *(_QWORD *)&v26.m_EnumValue = 0i64;
      v26.m_uEnumUID = 0;
      if ( UFG::gTargetTypeEnum.m_enumLists.size )
      {
        TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &v26);
      }
      else
      {
        v16 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &v26;
        v26.mPrev = v16;
        v26.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &v26;
      }
      if ( v26.m_EnumValue < 0x5B )
        UFG::TargetAttach(
          m_pPointer,
          (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
          0i64,
          0i64,
          &attachJoint,
          &targetAttachJoint,
          blendInTime,
          attachRelative,
          -1.0,
          attachToTarget,
          addToInventory,
          v14,
          (UFG::eTargetTypeEnum)v26.m_EnumValue,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 9) + 8i64) + 32i64) != 0i64,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 10) + 8i64) + 32i64) != 0i64,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 11) + 8i64) + 32i64) != 0i64,
          0i64);
      v17 = v26.mPrev;
      mNext = v26.mNext;
      v26.mPrev->mNext = v26.mNext;
      mNext->mPrev = v17;
      v26.mPrev = &v26;
      v26.mNext = &v26;
      v19 = pTrackEnumBinding.mPrev;
      v20 = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      v20->mPrev = v19;
      pTrackEnumBinding.mPrev = &pTrackEnumBinding;
      pTrackEnumBinding.mNext = &pTrackEnumBinding;
    }
    else
    {
      v7 = pTrackEnumBinding.mPrev;
      v8 = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      v8->mPrev = v7;
      pTrackEnumBinding.mPrev = &pTrackEnumBinding;
      pTrackEnumBinding.mNext = &pTrackEnumBinding;
    }
    v21 = pTrackEnumBinding.mPrev;
    v22 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v22->mPrev = v21;
  }
}

// File Line: 3821
// RVA: 0x4F80E0
void __fastcall UFG::TSActor::Mthd_detach_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  SSData **i_array_p; // r11
  UFG::qSymbol result; // [rsp+78h] [rbp+27h] BYREF
  __int64 v11; // [rsp+80h] [rbp+2Fh]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+88h] [rbp+37h] BYREF
  void *targetAttachJoint; // [rsp+B8h] [rbp+67h] BYREF
  UFG::qSymbolUC attachJoint; // [rsp+D0h] [rbp+7Fh] BYREF

  v11 = -2i64;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      UFG::qSymbolUC::create_from_string(
        &attachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      UFG::qSymbolUC::create_from_string(
        (UFG::qSymbolUC *)&targetAttachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
      i_array_p = pScope->i_data.i_array_p;
      UFG::TargetDetach(
        m_pPointer,
        (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
        0i64,
        &attachJoint,
        (UFG::qSymbolUC *)&targetAttachJoint,
        *(float *)&i_array_p[3]->i_data_p->i_user_data,
        i_array_p[4]->i_data_p->i_user_data != 0,
        i_array_p[5]->i_data_p->i_user_data != 0,
        i_array_p[6]->i_data_p->i_user_data != 0,
        i_array_p[7]->i_data_p->i_user_data != 0,
        i_array_p[8]->i_data_p->i_user_data != 0,
        0,
        *(float *)&i_array_p[9]->i_data_p->i_user_data,
        *(float *)&i_array_p[10]->i_data_p->i_user_data,
        0);
    }
    v7 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v7;
  }
}

// File Line: 3894
// RVA: 0x4F5350
void __fastcall UFG::TSActor::Mthd_attach(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rsi
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rdi
  SSData **i_array_p; // rdx
  float blendInTime; // xmm6_4
  bool attachRelative; // r14
  bool attachToTarget; // r15
  bool addToInventory; // r12
  bool v11; // r13
  UFG::qSymbol *v12; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qSymbol v16; // [rsp+58h] [rbp-19h] BYREF
  UFG::eTargetTypeEnum assignmentTargetType[2]; // [rsp+60h] [rbp-11h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+68h] [rbp-9h] BYREF
  UFG::qSymbolUC targetAttachJoint; // [rsp+D8h] [rbp+67h] BYREF
  UFG::qSymbolUC result; // [rsp+F0h] [rbp+7Fh] BYREF

  *(_QWORD *)assignmentTargetType = -2i64;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
      if ( ArgByNameOrInstance )
      {
        UFG::qSymbolUC::create_from_string(
          &result,
          **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
        UFG::qSymbolUC::create_from_string(
          &targetAttachJoint,
          **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
        i_array_p = pScope->i_data.i_array_p;
        blendInTime = *(float *)&i_array_p[3]->i_data_p->i_user_data;
        attachRelative = i_array_p[4]->i_data_p->i_user_data != 0;
        attachToTarget = i_array_p[5]->i_data_p->i_user_data != 0;
        addToInventory = i_array_p[6]->i_data_p->i_user_data != 0;
        v11 = i_array_p[7]->i_data_p->i_user_data != 0;
        v12 = UFG::qSymbol::create_from_string(&v16, *(const char **)i_array_p[8]->i_data_p->i_user_data);
        pTrackEnumBinding.mPrev = &pTrackEnumBinding;
        pTrackEnumBinding.mNext = &pTrackEnumBinding;
        pTrackEnumBinding.m_EnumSymbol.mUID = -1;
        pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v12->mUID;
        *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
        pTrackEnumBinding.m_uEnumUID = 0;
        if ( UFG::gTargetTypeEnum.m_enumLists.size )
        {
          TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
        }
        else
        {
          mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
          pTrackEnumBinding.mPrev = mPrev;
          pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
        }
        if ( pTrackEnumBinding.m_EnumValue < 0x5B )
          UFG::TargetAttach(
            m_pPointer,
            eTARGET_TYPE_INVALID,
            (UFG::SimObject *)ArgByNameOrInstance,
            0i64,
            &result,
            &targetAttachJoint,
            blendInTime,
            attachRelative,
            -1.0,
            attachToTarget,
            addToInventory,
            v11,
            (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 9) + 8i64) + 32i64) != 0i64,
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 10) + 8i64) + 32i64) != 0i64,
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 11) + 8i64) + 32i64) != 0i64,
            0i64);
        v14 = pTrackEnumBinding.mPrev;
        mNext = pTrackEnumBinding.mNext;
        pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
        mNext->mPrev = v14;
      }
    }
  }
}>mNext = pTrackEnumBinding.mNext;

// File Line: 3977
// RVA: 0x4F7F40
void __fastcall UFG::TSActor::Mthd_detach(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r14
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rbp
  SSData **i_array_p; // rdx
  UFG::qSymbolUC targetAttachJoint; // [rsp+A0h] [rbp+8h] BYREF
  UFG::qSymbolUC result; // [rsp+B8h] [rbp+20h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
    if ( ArgByNameOrInstance )
    {
      UFG::qSymbolUC::create_from_string(
        &result,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      UFG::qSymbolUC::create_from_string(
        &targetAttachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
      i_array_p = pScope->i_data.i_array_p;
      UFG::TargetDetach(
        m_pPointer,
        eTARGET_TYPE_INVALID,
        (UFG::SimObject *)ArgByNameOrInstance,
        &result,
        &targetAttachJoint,
        *(float *)&i_array_p[3]->i_data_p->i_user_data,
        i_array_p[4]->i_data_p->i_user_data != 0,
        i_array_p[5]->i_data_p->i_user_data != 0,
        i_array_p[6]->i_data_p->i_user_data != 0,
        i_array_p[7]->i_data_p->i_user_data != 0,
        i_array_p[8]->i_data_p->i_user_data != 0,
        0,
        *(float *)&i_array_p[9]->i_data_p->i_user_data,
        *(float *)&i_array_p[10]->i_data_p->i_user_data,
        0);
    }
  }
}

// File Line: 4049
// RVA: 0x50E4F0
void __fastcall UFG::TSActor::Mthd_was_hit_by_vehicle(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v4; // di
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rbx
  __int16 v11; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  SSInstance *i_data_p; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( !m_pPointer )
      goto LABEL_28;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      m_pComponent = v9;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( !m_pComponent )
      goto LABEL_28;
    if ( *(_DWORD *)(&m_pComponent[3].m_SimObjIndex + 1) != 1 )
      goto LABEL_28;
    if ( HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) != gAttackTypeWorldCollision.m_EnumValue )
      goto LABEL_28;
    v10 = *(UFG::SimObjectGame **)&m_pComponent[3].m_TypeUID;
    if ( !v10 )
      goto LABEL_28;
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 )
      goto LABEL_28;
    if ( v11 >= 0 )
    {
      if ( (v11 & 0x2000) != 0 )
      {
LABEL_28:
        *ppResult = SSBoolean::pool_new(v4);
        return;
      }
      if ( (v11 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::PhysicsMoverInterface::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::PhysicsMoverInterface::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = v10->m_Components.p[34].m_pComponent;
    }
    if ( ComponentOfTypeHK )
    {
      i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
      v4 = !i_data_p || i_data_p == SSBrain::c_nil_p || v10 == *(UFG::SimObjectGame **)&i_data_p[4].i_ref_count;
    }
    goto LABEL_28;
  }
}

// File Line: 4100
// RVA: 0x50E670
void __fastcall UFG::TSActor::Mthd_was_shot(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v4; // bl
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  SSInstance *i_data_p; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( m_pComponent
        && *(_DWORD *)(&m_pComponent[3].m_SimObjIndex + 1) == 1
        && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue )
      {
        i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
        v4 = !i_data_p
          || i_data_p == SSBrain::c_nil_p
          || *(_QWORD *)&m_pComponent[3].m_TypeUID == *(_QWORD *)&i_data_p[4].i_ref_count;
      }
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 4139
// RVA: 0x4FFE80
void __fastcall UFG::TSActor::Mthd_has_hit_object(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v6; // r9d
  SSClass *v7; // rax
  ASymbol *v8; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v13; // rcx
  const char *TypeName; // rax
  SSTypedData **i_array_p; // rdx
  SSTypedData **v16; // r8
  SSInstance *i_data_p; // rcx
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-30h] BYREF
  ASymbol result; // [rsp+70h] [rbp+18h] BYREF

  if ( ppResult )
  {
    v6 = _S9_14;
    if ( (_S9_14 & 1) != 0 )
    {
      v7 = spEnumClass;
    }
    else
    {
      _S9_14 |= 1u;
      v7 = SSBrain::get_class("ObjectPropertyType");
      spEnumClass = v7;
      v6 = _S9_14;
    }
    if ( (v6 & 2) == 0 )
    {
      v6 |= 2u;
      _S9_14 = v6;
      classData = &v7->i_class_data;
    }
    if ( (v6 & 4) == 0 )
    {
      _S9_14 = v6 | 4;
      v8 = ASymbol::create(&result, "invalid", 0xFFFFFFFF, ATerm_long);
      spInvalid = *(SSInstance **)&APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
                                     (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)classData,
                                     v8)[1].i_name.i_uid;
    }
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    *ppResult = spInvalid;
    if ( m_pComponent
      && *(_DWORD *)(&m_pComponent[3].m_SimObjIndex + 1) == 1
      && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackTypeWorldCollision.m_EnumValue
      && (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(&m_pComponent[6].m_SimObjIndex + 1) / UFG::TidoGame::sm_MaxCollisionVelocity) & _xmm)
               * 100.0) >= *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v18);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v13);
      v18.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v18, v18.mTypeUID, (unsigned __int64)m_pComponent[5].m_pSimObject);
      if ( v18.mData )
      {
        i_array_p = classData->i_array_p;
        v16 = &i_array_p[classData->i_count];
        if ( i_array_p < v16 )
        {
          while ( 1 )
          {
            i_data_p = (*i_array_p)->i_data_p;
            if ( i_data_p->i_user_data == HIDWORD(v18.mData[4].mBaseNode.mParent) )
              break;
            if ( ++i_array_p >= v16 )
              goto LABEL_30;
          }
          *ppResult = i_data_p;
        }
      }
LABEL_30:
      UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
    }
    ++(*ppResult)->i_ref_count;
  }
}

// File Line: 4202
// RVA: 0x5000D0
void __fastcall UFG::TSActor::Mthd_has_hit_static_object(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v5; // di
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v10; // rcx
  const char *TypeName; // rax
  UFG::qReflectHandleBase v12; // [rsp+28h] [rbp-30h] BYREF

  if ( ppResult )
  {
    v5 = 0;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( m_pComponent
        && *(_DWORD *)(&m_pComponent[3].m_SimObjIndex + 1) == 1
        && HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) == gAttackTypeWorldCollision.m_EnumValue
        && (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                  *(float *)(&m_pComponent[6].m_SimObjIndex + 1)
                                / UFG::TidoGame::sm_MaxCollisionVelocity) & _xmm)
                 * 100.0) >= *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v12);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v10);
        v12.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v12, v12.mTypeUID, (unsigned __int64)m_pComponent[5].m_pSimObject);
        if ( v12.mData )
          v5 = LODWORD(v12.mData[2].mBaseNode.mChildren[1]) == 1;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 4260
// RVA: 0x4F4E10
void __fastcall UFG::TSActor::Mthd_are_resources_loaded(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v5; // di
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v5 = 1;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent;
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::StreamedResourceComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StreamedResourceComponent::_TypeUID);
          m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent && UFG::StreamedResourceComponent::IsLoadActive(m_pComponent) )
        v5 = UFG::StreamedResourceComponent::AreResourcesLoaded(m_pComponent)
          && UFG::StreamedResourceComponent::AreResourcesBound(m_pComponent);
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 4282
// RVA: 0x4FEA70
void __fastcall UFG::TSActor::Mthd_get_spawn_priority(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  ASymbol sym; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    sym.i_uid = qSymbol_Low.mUID;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::StreamedResourceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent )
        sym.i_uid = UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID;
    }
    *ppResult = SSSymbol::as_instance(&sym);
  }
}

// File Line: 4300
// RVA: 0x5002B0
void __fastcall UFG::TSActor::Mthd_inc_spawn_priority_ref(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::StreamedResourceComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(
        m_pComponent,
        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4309
// RVA: 0x4F7A80
void __fastcall UFG::TSActor::Mthd_dec_spawn_priority_ref(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::StreamedResourceComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(
        m_pComponent,
        (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4324
// RVA: 0x4E6350
void __fastcall UFG::TSActor::MthdC_find_named(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_data_p; // rdi
  UFG::TSActor *v4; // rcx
  UFG::qBaseNodeRB *SimObject; // rax
  SSInstance *v6; // rax

  if ( result_pp )
  {
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = (UFG::TSActor *)SSActor::find((ASymbol *)&i_data_p->i_user_data);
    if ( !v4 )
    {
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&i_data_p->i_user_data);
      v4 = UFG::TSActor::FromSimObject((UFG::SimObject *)SimObject);
    }
    v6 = SSBrain::c_nil_p;
    if ( v4 )
      v6 = v4;
    *result_pp = v6;
    ++v6->i_ref_count;
  }
}

// File Line: 4352
// RVA: 0x4E62C0
void __fastcall UFG::TSActor::MthdC_find_instance(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_data_p; // rdi
  SSInstance *v4; // rax
  unsigned __int64 *p_i_user_data2; // rcx
  UFG::TSActor *v6; // rcx
  UFG::qBaseNodeRB *SimObject; // rax
  SSInstance *v8; // rax

  if ( result_pp )
  {
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = scope_p->vfptr->get_topmost_scope(scope_p);
    if ( v4 )
      p_i_user_data2 = &v4[-1].i_user_data2;
    else
      p_i_user_data2 = 0i64;
    v6 = (UFG::TSActor *)APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
                           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(p_i_user_data2[7] + 304),
                           (ASymbol *)&i_data_p->i_user_data);
    if ( !v6 )
    {
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&i_data_p->i_user_data);
      v6 = UFG::TSActor::FromSimObject((UFG::SimObject *)SimObject);
    }
    v8 = SSBrain::c_nil_p;
    if ( v6 )
      v8 = v6;
    *result_pp = v8;
    ++v8->i_ref_count;
  }
}

// File Line: 4383
// RVA: 0x4E79E0
void __fastcall UFG::TSActor::MthdC_get_instance(SSInvokedMethod *scope_p, UFG::TSActor **result_pp)
{
  SSInstance *i_data_p; // rdi
  SSInstance *v4; // rax
  unsigned __int64 *p_i_user_data2; // rax
  unsigned __int64 v6; // rcx
  UFG::TSActor *v7; // rax
  UFG::qBaseNodeRB *SimObject; // rax

  if ( result_pp )
  {
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = scope_p->vfptr->get_topmost_scope(scope_p);
    if ( !v4
      || (p_i_user_data2 = &v4[-1].i_user_data2) == 0i64
      || (v6 = p_i_user_data2[7]) == 0
      || (v7 = (UFG::TSActor *)APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
                                 (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(v6 + 304),
                                 (ASymbol *)&i_data_p->i_user_data)) == 0i64 )
    {
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&i_data_p->i_user_data);
      v7 = UFG::TSActor::FromSimObject((UFG::SimObject *)SimObject);
    }
    ++v7->i_ref_count;
    *result_pp = v7;
  }
}

// File Line: 4423
// RVA: 0x511710
void __fastcall UFG::TSActor::TeleportToTransformRaw(UFG::TSActor *this, UFG::qMatrix44 *transform)
{
  UFG::allocator::free_link *v4; // rax

  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v4,
      transform,
      this->mpSimObj.m_pPointer->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  ((void (__fastcall *)(UFG::TSActor *))this->vfptr[2].get_data_by_name)(this);
}

// File Line: 4431
// RVA: 0x511350
void __fastcall UFG::TSActor::TeleportToTransform(UFG::TSActor *this, UFG::qMatrix44 *transform)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qVector3 out; // [rsp+38h] [rbp-20h] BYREF

  if ( UFG::PlaceOnGround(&out, (UFG::qVector3 *)&transform->v3, 0.050000001, 0.0) )
  {
    *(UFG::qVector3 *)&transform->v3.x = out;
    transform->v3.w = 1.0;
  }
  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v4,
      transform,
      this->mpSimObj.m_pPointer->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  ((void (__fastcall *)(UFG::TSActor *))this->vfptr[2].get_data_by_name)(this);
}

// File Line: 4453
// RVA: 0x511430
void __fastcall UFG::TSActor::TeleportToTransformPreserveVel(UFG::TSActor *this, UFG::qMatrix44 *transform)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rdi
  UFG::CharacterPhysicsComponent *ComponentOfType; // rax
  float y; // xmm1_4
  float x; // xmm10_4
  float v10; // xmm9_4
  float z; // xmm8_4
  float mGravity; // xmm7_4
  float mSpeedZ; // xmm6_4
  float v14; // xmm0_4
  float w; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-49h] BYREF
  UFG::qMatrix44 v44; // [rsp+30h] [rbp-39h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterPhysicsComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterPhysicsComponent::_TypeUID)),
         m_pComponent = ComponentOfType)
      : (m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent),
        m_pComponent) )
  {
    UFG::CharacterPhysicsComponent::GetVelocity(m_pComponent, &result);
    y = transform->v0.y;
    x = m_pComponent->mAdditiveVelocity.x;
    v10 = m_pComponent->mAdditiveVelocity.y;
    z = m_pComponent->mAdditiveVelocity.z;
    mGravity = m_pComponent->mGravity;
    mSpeedZ = m_pComponent->mSpeedZ;
    v44.v0.x = transform->v0.x;
    v14 = transform->v0.z;
    v44.v0.y = y;
    w = transform->v0.w;
    v44.v0.z = v14;
    v16 = transform->v1.x;
    v44.v0.w = w;
    v17 = transform->v1.y;
    v44.v1.x = v16;
    v18 = transform->v1.z;
    v44.v1.y = v17;
    v19 = transform->v1.w;
    v44.v1.z = v18;
    v20 = transform->v2.x;
    v44.v1.w = v19;
    v21 = transform->v2.y;
    v44.v2.x = v20;
    v22 = transform->v2.z;
    v44.v2.y = v21;
    v23 = transform->v2.w;
    v44.v2.z = v22;
    v24 = transform->v3.x;
    v44.v2.w = v23;
    v25 = transform->v3.y;
    v44.v3.x = v24;
    v26 = transform->v3.z;
    v44.v3.y = v25;
    v27 = transform->v3.w;
    v44.v3.z = v26;
    v44.v3.w = v27;
    UFG::TSActor::TeleportToTransform(this, &v44);
    UFG::CharacterPhysicsComponent::SetVelocity(m_pComponent, &result);
    m_pComponent->mAdditiveVelocity.x = x;
    m_pComponent->mAdditiveVelocity.y = v10;
    m_pComponent->mAdditiveVelocity.z = z;
    m_pComponent->mGravity = mGravity;
    m_pComponent->mSpeedZ = mSpeedZ;
  }
  else
  {
    v28 = transform->v0.y;
    v44.v0.x = transform->v0.x;
    v29 = transform->v0.z;
    v44.v0.y = v28;
    v30 = transform->v0.w;
    v44.v0.z = v29;
    v31 = transform->v1.x;
    v44.v0.w = v30;
    v32 = transform->v1.y;
    v44.v1.x = v31;
    v33 = transform->v1.z;
    v44.v1.y = v32;
    v34 = transform->v1.w;
    v44.v1.z = v33;
    v35 = transform->v2.x;
    v44.v1.w = v34;
    v36 = transform->v2.y;
    v44.v2.x = v35;
    v37 = transform->v2.z;
    v44.v2.y = v36;
    v38 = transform->v2.w;
    v44.v2.z = v37;
    v39 = transform->v3.x;
    v44.v2.w = v38;
    v40 = transform->v3.y;
    v44.v3.x = v39;
    v41 = transform->v3.z;
    v44.v3.y = v40;
    v42 = transform->v3.w;
    v44.v3.z = v41;
    v44.v3.w = v42;
    UFG::TSActor::TeleportToTransform(this, &v44);
  }
}

// File Line: 4491
// RVA: 0x4DE7A0
char __fastcall UFG::TSActor::Coro_wait_ai_stimulus(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r8
  UFG::eStimulusType i_user_data; // r12d
  SSInstance *i_data_p; // rbx
  UFG::StimulusNotifyCallback *v6; // r14
  SSClass *v7; // rbp
  SSActorClass *v8; // rsi
  SSActorClass *i_class_p; // rax
  UFG::SimObjectGame *SimObject; // rbx
  SSClass *i_superclass_p; // rcx
  __int64 v12; // rdi
  SSClass *v13; // rax
  UFG::qBaseNodeRB *v14; // rbp
  SSClass *v15; // rcx
  __int16 m_Flags; // cx
  UFG::StimulusReceiverComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::StimulusReceiverComponent *v21; // rax
  __int16 v22; // cx
  unsigned int v23; // edi
  UFG::allocator::free_link *v24; // rax
  UFG::StimulusNotifyCallback *v25; // rax
  SSInstance *v27; // rbx
  __int64 v28; // rsi
  _DWORD *v29; // rcx
  UFG::SimObjectModifier v31; // [rsp+38h] [rbp-50h] BYREF

  if ( pScope->i_update_count )
    return 1;
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  i_data_p = i_array_p[1]->i_data_p;
  v6 = 0i64;
  v7 = UFG::TSSimObject::mspSimObjectClass;
  v8 = SSBrain::c_physical_actor_class_p;
  if ( !i_data_p )
    goto LABEL_11;
  i_class_p = (SSActorClass *)i_data_p->i_class_p;
  if ( i_class_p != UFG::TSSimObject::mspSimObjectClass )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p )
    {
      SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(
                                          &UFG::gSim,
                                          (UFG::qSymbol *)&i_data_p->i_user_data);
      v7 = UFG::TSSimObject::mspSimObjectClass;
      v8 = SSBrain::c_physical_actor_class_p;
      goto LABEL_12;
    }
    if ( SSBrain::c_physical_actor_class_p == i_class_p
      || (i_superclass_p = i_class_p->i_superclass_p) != 0i64
      && SSClass::is_class(i_superclass_p, SSBrain::c_physical_actor_class_p) )
    {
      SimObject = *(UFG::SimObjectGame **)&i_data_p[4].i_ref_count;
      goto LABEL_12;
    }
LABEL_11:
    SimObject = 0i64;
    goto LABEL_12;
  }
  SimObject = (UFG::SimObjectGame *)i_data_p->i_user_data;
LABEL_12:
  v12 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64);
  if ( !v12 )
    goto LABEL_21;
  v13 = *(SSClass **)(v12 + 24);
  if ( v13 == v7 )
  {
    v14 = *(UFG::qBaseNodeRB **)(v12 + 32);
    goto LABEL_22;
  }
  if ( v13 == SSBrain::c_symbol_class_p )
  {
    v14 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)(v12 + 32));
    goto LABEL_22;
  }
  if ( v8 == v13 || (v15 = v13->i_superclass_p) != 0i64 && SSClass::is_class(v15, v8) )
    v14 = *(UFG::qBaseNodeRB **)(v12 + 208);
  else
LABEL_21:
    v14 = 0i64;
LABEL_22:
  if ( !SimObject )
  {
    v27 = UFG::gpAIStimulusTypeClass_none;
    v28 = *((_QWORD *)pScope->i_data.i_array_p + 5);
    ++UFG::gpAIStimulusTypeClass_none->i_ref_count;
    v29 = *(_DWORD **)(v28 + 8);
    if ( v29[4]-- == 1 )
    {
      v29[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v29 + 112i64))(v29);
    }
    *(_QWORD *)(v28 + 8) = v27;
    return 1;
  }
  m_Flags = SimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::StimulusReceiverComponent *)SimObject->m_Components.p[11].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::StimulusReceiverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::StimulusReceiverComponent::_TypeUID);
    m_pComponent = (UFG::StimulusReceiverComponent *)ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = (UFG::StimulusReceiverComponent *)SimObject->m_Components.p[11].m_pComponent;
  }
  if ( !m_pComponent )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v20 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x428ui64, "StimulusReceiverComponent", 0i64, 1u);
    if ( v20 )
    {
      UFG::StimulusReceiverComponent::StimulusReceiverComponent(
        (UFG::StimulusReceiverComponent *)v20,
        SimObject->mNode.mUID);
      m_pComponent = v21;
    }
    else
    {
      m_pComponent = 0i64;
    }
    v22 = SimObject->m_Flags;
    if ( (v22 & 0x4000) != 0 )
    {
      v23 = 11;
    }
    else if ( v22 >= 0 )
    {
      v23 = -1;
    }
    else
    {
      v23 = 11;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v31, SimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v31, m_pComponent, v23);
    UFG::SimObjectModifier::Close(&v31);
    UFG::SimObjectModifier::~SimObjectModifier(&v31);
  }
  v24 = UFG::qMalloc(0x90ui64, "StimulusNotifyScript", 0i64);
  if ( v24 )
  {
    UFG::StimulusNotifyScript::StimulusNotifyScript(
      (UFG::StimulusNotifyScript *)v24,
      i_user_data,
      pScope,
      (UFG::SimObject *)v14);
    v6 = v25;
  }
  UFG::StimulusReceiverComponent::RegisterNotifyCallback(m_pComponent, v6);
  return 0;
}

// File Line: 4538
// RVA: 0x4DB520
bool __fastcall UFG::TSActor::Coro_invoke_aibehaviour(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::BehaviourControllerComponent *v5; // rax
  UFG::BehaviourControllerComponent *v6; // rbx
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // r8
  int i_user_data; // r12d
  SSInstance *v10; // r15
  float v11; // xmm6_4
  float v12; // xmm7_4
  SSInstance *v13; // rcx
  bool v14; // r14
  bool v15; // si
  ActionNode *v16; // rax
  char *v17; // r14
  __int64 v18; // rbx
  unsigned int v19; // eax
  AStringRef *v20; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v25; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  int mCount; // edx
  ActionPath absolutePath; // [rsp+8h] [rbp-79h] BYREF
  UFG::InvokeBehaviourParams params; // [rsp+18h] [rbp-69h] BYREF
  UFG::InvokeBehaviourResult optResult; // [rsp+48h] [rbp-39h] BYREF
  __int64 v32; // [rsp+88h] [rbp+7h]
  AStringRef *str; // [rsp+E8h] [rbp+67h] BYREF

  v32 = -2i64;
  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(m_pPointer);
  else
    v5 = (UFG::BehaviourControllerComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::BehaviourControllerComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::BehaviourControllerComponent::_TypeUID));
  v6 = v5;
  if ( !v5 )
    return 1;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v10 = i_array_p[2]->i_data_p;
  v11 = *(float *)&i_array_p[3]->i_data_p->i_user_data;
  v12 = *(float *)&i_array_p[4]->i_data_p->i_user_data;
  v13 = i_array_p[5]->i_data_p;
  v14 = v13->i_user_data != 0;
  v15 = 1;
  if ( pScope->i_update_count )
  {
    if ( v13->i_user_data )
      return UFG::BehaviourControllerComponent::FindBehaviourWithNode(v5, *(const char **)i_data_p->i_user_data) == 0i64;
  }
  else
  {
    optResult.mId = 0;
    memset(&optResult.mDesc, 0, 28);
    optResult.mInvokeParams.mMaxWaitTime = -1.0;
    optResult.mInvokeParams.mMaxLifeTime = -1.0;
    optResult.mInvokeParams.mIsRootInvoke = 1;
    *(_OWORD *)&optResult.mInvokeParams.mInvokeTask = 0i64;
    ActionPath::Append(&absolutePath, *(const char **)i_data_p->i_user_data);
    v16 = ActionNode::Find(&absolutePath, 0i64);
    if ( v16 )
    {
      params.mNode = v16;
      *(_QWORD *)&params.mPriority = 0i64;
      params.mMaxWaitTime = -1.0;
      params.mMaxLifeTime = -1.0;
      params.mIsRootInvoke = 1;
      params.mInvokeTask = 0i64;
      params.mControlType = eINVOKE_AND_FORGET;
      params.mPriorityMode = UFG::BehaviourControllerComponent::GetInvokePriorityModeFromString(*(const char **)v10->i_user_data);
      params.mPriority = i_user_data;
      params.mMaxLifeTime = v12;
      params.mMaxWaitTime = v11;
      params.mIsRootInvoke = 1;
      params.mInvokeTask = 0i64;
      if ( (int)UFG::BehaviourControllerComponent::InvokeBehaviour(v6, &params, &optResult) >= 1 )
        v15 = !v14;
    }
    else
    {
      optResult.mId = -3;
      optResult.mDesc = "Couldnt find behaviour node.";
      optResult.mBehaviour = 0i64;
    }
    UFG::InvokeBehaviourResult::ToString(&optResult, (UFG::qString *)&params);
    v17 = *(char **)&params.mMaxLifeTime;
    v18 = -1i64;
    do
      ++v18;
    while ( *(_BYTE *)(*(_QWORD *)&params.mMaxLifeTime + v18) );
    v19 = AMemory::c_req_byte_size_func(v18 + 1);
    str = AStringRef::pool_new(v17, v18, v19, 1u, 0, 1);
    ADebug::print((AMD_HD3D *)&str, 1);
    v20 = str;
    if ( str->i_ref_count-- == 1 )
    {
      if ( v20->i_deallocate )
        AMemory::c_free_func(v20->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v20 < i_objects_a
        || (v25 = (unsigned __int64)v20 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v25) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v20);
    }
    UFG::qString::~qString((UFG::qString *)&params);
    mCount = absolutePath.mPath.mCount;
    if ( absolutePath.mPath.mCount >= 0 )
    {
      if ( absolutePath.mPath.mData.mOffset )
      {
        if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
        {
          operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
          mCount = absolutePath.mPath.mCount;
        }
      }
      absolutePath.mPath.mData.mOffset = 0i64;
      absolutePath.mPath.mCount = mCount & 0x80000000;
    }
  }
  return v15;
}

// File Line: 4604
// RVA: 0x4F9280
void __fastcall UFG::TSActor::Mthd_end_aibehaviour(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::BehaviourControllerComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 m_pPointer,
                                                                 UFG::BehaviourControllerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::BehaviourControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                                 m_pPointer,
                                                                 UFG::BehaviourControllerComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::BehaviourControllerComponent::EndBehaviour(
        ComponentOfTypeHK,
        *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4621
// RVA: 0x5105C0
void __fastcall UFG::TSAIStimulusType_MthdC_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // rcx
  SSClass *key_class; // rbp
  int v5; // esi
  char *v6; // r14
  AStringRef *i_str_ref_p; // rax
  __int64 i_length; // rbx
  char *i_cstr_p; // rcx
  char *v10; // rdx
  ASymbol *v11; // rax
  __int64 i_count; // rcx
  SSTypedData **i_array_p; // rdx
  SSTypedData **v14; // r9
  unsigned int i_uid; // r10d
  SSTypedData **v16; // rax
  unsigned int v17; // r8d
  unsigned int *v18; // rdi
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int v20; // eax
  unsigned int v21; // eax
  __int64 v22; // rcx
  SSInstance **v23; // rax
  unsigned int v24; // eax
  SSInstance *v25; // rbx
  _DWORD *v26; // rcx
  bool v27; // zf
  SSInstance *v28; // rax
  AStringRef *v29; // rbx
  AObjReusePool<AStringRef> *v30; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v33; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  char buffer_p[296]; // [rsp+40h] [rbp-128h] BYREF
  ASymbol result; // [rsp+170h] [rbp+8h] BYREF
  AString str; // [rsp+180h] [rbp+18h] BYREF

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  key_class = SSInstance::get_key_class(i_obj_p);
  v5 = 0;
  AString::AString(&str, buffer_p, 0x100u, 0, 0);
  v6 = (char *)&unk_1423BF9A8;
  do
  {
    AString::set_cstr(&str, (char *)(*(_QWORD *)v6 + 10i64), 0xFFFFFFFF, 1);
    i_str_ref_p = str.i_str_ref_p;
    i_length = str.i_str_ref_p->i_length;
    if ( (_DWORD)i_length )
    {
      if ( str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::make_writeable(&str);
        i_str_ref_p = str.i_str_ref_p;
      }
      i_cstr_p = i_str_ref_p->i_cstr_p;
      v10 = &i_str_ref_p->i_cstr_p[i_length];
      if ( i_str_ref_p->i_cstr_p < v10 )
      {
        do
        {
          *i_cstr_p = AString::c_char2lower[(unsigned __int8)*i_cstr_p];
          ++i_cstr_p;
        }
        while ( i_cstr_p < v10 );
      }
    }
    v11 = ASymbol::create(&result, &str, ATerm_short);
    i_count = key_class->i_class_data.i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = key_class->i_class_data.i_array_p;
      v14 = &i_array_p[i_count - 1];
      i_uid = v11->i_uid;
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = &i_array_p[((char *)v14 - (char *)i_array_p) >> 4];
          v17 = (*v16)->i_name.i_uid;
          if ( i_uid >= v17 )
            break;
          if ( i_array_p == v16 )
            goto LABEL_32;
          v14 = v16 - 1;
        }
        if ( i_uid == v17 )
          break;
        if ( v14 == v16 )
          goto LABEL_32;
        i_array_p = v16 + 1;
      }
      v18 = (unsigned int *)*v16;
      if ( *v16 )
      {
        pool = SSInstance::get_pool();
        if ( pool->i_pool.i_count )
        {
          v24 = pool->i_pool.i_count - 1;
          pool->i_pool.i_count = v24;
          v22 = v24;
          v23 = pool->i_pool.i_array_p;
        }
        else
        {
          if ( !pool->i_exp_pool.i_count )
            AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
          v20 = pool->i_exp_pool.i_count;
          if ( !v20 )
          {
            v25 = 0i64;
            goto LABEL_27;
          }
          v21 = v20 - 1;
          pool->i_exp_pool.i_count = v21;
          v22 = v21;
          v23 = pool->i_exp_pool.i_array_p;
        }
        v25 = v23[v22];
LABEL_27:
        v25->i_class_p = key_class;
        v25->i_user_data = (unsigned int)v5;
        v25->i_ref_count = 1;
        v25->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
        ++v25->i_ref_count;
        v26 = (_DWORD *)*((_QWORD *)v18 + 2);
        v27 = v26[4]-- == 1;
        if ( v27 )
        {
          v26[4] = 0x80000000;
          (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v26 + 112i64))(v26);
        }
        *((_QWORD *)v18 + 2) = v25;
        v28 = UFG::gpAIStimulusTypeClass_none;
        if ( !v5 )
          v28 = v25;
        UFG::gpAIStimulusTypeClass_none = v28;
      }
    }
LABEL_32:
    ++v5;
    v6 += 72;
  }
  while ( v5 < 116 );
  v29 = str.i_str_ref_p;
  v27 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v27 )
  {
    if ( v29->i_deallocate )
      AMemory::c_free_func(v29->i_cstr_p);
    v30 = AStringRef::get_pool();
    i_block_p = v30->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)v29 < i_objects_a
      || (v33 = (unsigned __int64)v29 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &v30->i_pool, !v33) )
    {
      p_i_exp_pool = &v30->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v29);
  }
}

// File Line: 4663
// RVA: 0x1536440
__int64 UFG::_dynamic_initializer_for__gTSPhysicalActor_singleExclude__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gTSPhysicalActor_singleExclude__);
}

// File Line: 4673
// RVA: 0x4E0E60
APArray<SSActor,SSActor,ACompareAddress<SSActor> > *__fastcall UFG::TSActor::GetArgAutoList(
        SSInvokedContextBase *pScope,
        unsigned int argPos)
{
  SSActor *i_data_p; // rdx

  i_data_p = (SSActor *)pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( !i_data_p || i_data_p == SSBrain::c_nil_p )
    return 0i64;
  if ( i_data_p->i_class_p == SSBrain::c_list_class_p )
    return (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)i_data_p->i_user_data;
  UFG::gTSPhysicalActor_singleExclude.i_count = 0;
  APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, i_data_p);
  return &UFG::gTSPhysicalActor_singleExclude;
}

// File Line: 4703
// RVA: 0x4F6130
void __fastcall UFG::TSActor::Mthd_begin_stimulus_one_off_internal(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::eStimulusType StimulusType; // eax
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        StimulusType,
        &stimulus_parameters,
        m_pPointer);
    }
  }
}

// File Line: 4723
// RVA: 0x4F5FE0
void __fastcall UFG::TSActor::Mthd_begin_stimulus_duration_internal(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbx
  UFG::eStimulusType StimulusType; // eax
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_data_p = i_array_p[1]->i_data_p;
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*i_array_p)->i_data_p->i_user_data);
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
      stimulus_parameters.m_MaxStimulusDuration = *(float *)&i_data_p->i_user_data;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        StimulusType,
        &stimulus_parameters,
        m_pPointer);
    }
  }
}

// File Line: 4744
// RVA: 0x4F60A0
void __fastcall UFG::TSActor::Mthd_begin_stimulus_internal(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::eStimulusType StimulusType; // eax
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        StimulusType,
        &stimulus_parameters,
        m_pPointer);
    }
  }
}

// File Line: 4763
// RVA: 0x4F9340
void __fastcall UFG::TSActor::Mthd_end_stimulus_internal(
        UFG::TSActor *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::eStimulusType StimulusType; // eax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, StimulusType, m_pPointer);
    }
  }
}

// File Line: 4781
// RVA: 0x4EA900
void __fastcall UFG::TSActor::MthdC_list_convert(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInstance *i_data_p; // r15
  unsigned int *i_user_data; // rbx
  __int64 v6; // rbp
  SSInstance *i_obj_p; // rcx
  SSClass *key_class; // rax
  UFG::TSActor **v9; // rsi
  UFG::TSActor **v10; // r13
  SSClass *v11; // r12
  UFG::TSActor **v12; // r14
  UFG::TSActor *v13; // rdi
  UFG::TSActor *v14; // rbx
  SSClass *i_class_p; // rax
  UFG::TSActor *v16; // rax
  SSClass *i_superclass_p; // rcx
  unsigned int *v19; // [rsp+60h] [rbp+8h]

  v2 = ppResult;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  i_user_data = (unsigned int *)i_data_p->i_user_data;
  v19 = i_user_data;
  v6 = *i_user_data;
  if ( (_DWORD)v6 )
  {
    i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    key_class = SSInstance::get_key_class(i_obj_p);
    v9 = (UFG::TSActor **)*((_QWORD *)i_user_data + 1);
    v10 = &v9[v6];
    v11 = key_class;
    v12 = v9;
    if ( v9 < v10 )
    {
      while ( 1 )
      {
        v13 = *v9;
        v14 = *v9;
        if ( !*v9 )
          goto LABEL_23;
        i_class_p = v13->i_class_p;
        if ( i_class_p == SSBrain::c_symbol_class_p )
          break;
        if ( i_class_p == UFG::TSSimObject::mspSimObjectClass )
        {
          v16 = UFG::TSActor::FromSimObject((UFG::SimObject *)v13->i_user_data);
LABEL_11:
          v14 = v16;
          if ( v16 )
            i_class_p = v16->i_class_p;
          else
            i_class_p = 0i64;
        }
        if ( i_class_p )
        {
          if ( v11 == i_class_p
            || (i_superclass_p = i_class_p->i_superclass_p) != 0i64 && SSClass::is_class(i_superclass_p, v11) )
          {
            if ( v14 )
            {
              if ( v14 != v13 )
              {
                *v12 = v14;
                ++v14->i_ref_count;
                if ( v13->i_ref_count-- == 1 )
                {
                  v13->i_ref_count = 0x80000000;
                  v13->vfptr[1].get_scope_context(v13);
                }
              }
              ++v12;
              goto LABEL_24;
            }
          }
        }
LABEL_23:
        LODWORD(v6) = v6 - 1;
LABEL_24:
        if ( ++v9 >= v10 )
        {
          i_user_data = v19;
          v2 = ppResult;
          goto LABEL_26;
        }
      }
      v16 = (UFG::TSActor *)SSActor::find((ASymbol *)&v13->i_user_data);
      goto LABEL_11;
    }
LABEL_26:
    *i_user_data = v6;
  }
  if ( v2 )
  {
    ++i_data_p->i_ref_count;
    *v2 = i_data_p;
  }
}

// File Line: 4842
// RVA: 0x510B40
void __fastcall UFG::TSPhysicalActor_MthdC_list_collect_near_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  UFG::qVector3 *i_user_data; // rbp
  float v6; // xmm6_4
  SSActor *i_data_p; // rdx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pExclusions; // rbx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v9; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v10; // rdi
  SSInstance *i_obj_p; // rcx
  SSActorClass *key_class; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **v14; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data;
    v6 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    i_data_p = (SSActor *)i_array_p[2]->i_data_p;
    if ( !i_data_p || i_data_p == SSBrain::c_nil_p )
    {
      pExclusions = 0i64;
    }
    else if ( i_data_p->i_class_p == SSBrain::c_list_class_p )
    {
      pExclusions = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)i_data_p->i_user_data;
    }
    else
    {
      UFG::gTSPhysicalActor_singleExclude.i_count = 0;
      pExclusions = &UFG::gTSPhysicalActor_singleExclude;
      APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, i_data_p);
    }
    v9 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v10 = v9;
    if ( v9 )
    {
      v9->i_count = 0;
      v9->i_array_p = 0i64;
      v9->i_size = 0;
      v9->i_array_p = (SSActor **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v10 = 0i64;
    }
    i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    key_class = (SSActorClass *)SSInstance::get_key_class(i_obj_p);
    UFG::TSActor::ListCollectNear(v10, i_user_data, v6, key_class, pExclusions);
    i_count = v10->i_count;
    if ( (_DWORD)i_count )
    {
      v14 = (ARefCountMix<SSInstance> **)v10->i_array_p;
      for ( i = &v14[i_count]; v14 < i; ++v14 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v14 + 4);
    }
    *ppResult = SSList::as_instance((SSList *)v10);
  }
}

// File Line: 4872
// RVA: 0x510A00
void __fastcall UFG::TSPhysicalActor_MthdC_is_class_inside_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v4; // r15
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rsi
  SSInstance *i_obj_p; // rdx
  SSClass *key_class; // rdi
  __int64 vfptr_low; // rbp
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *ArgAutoList; // rax
  SSActor **v10; // rdi
  UFG::RegionComponent *v11; // r13
  SSActor **v12; // rsi
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *i; // r14
  SSActor *v14; // rbx
  SSActor **i_array_p; // rax
  SSActor **v16; // r8
  SSClass *i_class_p; // rbx

  if ( ppResult )
  {
    v4 = 0;
    ArgByNameOrInstance = UFG::TSTriggerRegion::GetArgByNameOrInstance(pScope, 0);
    if ( ArgByNameOrInstance )
    {
      i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
      if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      key_class = SSInstance::get_key_class(i_obj_p);
      vfptr_low = LODWORD(key_class[1].vfptr);
      if ( (_DWORD)vfptr_low )
      {
        ArgAutoList = UFG::TSActor::GetArgAutoList(pScope, 1u);
        v10 = *(SSActor ***)&key_class[1].i_name.i_uid;
        v11 = *(UFG::RegionComponent **)&ArgByNameOrInstance[6].mUID;
        v12 = &v10[vfptr_low];
        for ( i = ArgAutoList; v10 < v12; ++v10 )
        {
          v14 = *v10;
          if ( i && i->i_count && (i_array_p = i->i_array_p, v16 = &i_array_p[i->i_count - 1], i_array_p <= v16) )
          {
            while ( v14 != *i_array_p )
            {
              if ( ++i_array_p > v16 )
                goto LABEL_13;
            }
          }
          else
          {
LABEL_13:
            i_class_p = v14[1].i_class_p;
            if ( i_class_p )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_class_p);
              if ( UFG::RegionComponent::IsHitPoint(v11, (UFG::qVector3 *)&i_class_p->i_class_data.i_array_p) )
              {
                v4 = 1;
                break;
              }
            }
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 4929
// RVA: 0x510CA0
void __fastcall UFG::TSPhysicalActor_MthdC_list_collect_trigger_inside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *ArgByNameOrInstance; // r15
  SSList *v5; // rax
  SSList *v6; // r14
  SSInstance *i_obj_p; // rcx
  SSClass *key_class; // rdi
  __int64 vfptr_low; // rbp
  SSActor *v10; // rdx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *i_user_data; // rsi
  UFG::RegionComponent *v12; // r15
  SSActor **v13; // rbx
  SSActor **i; // rbp
  SSActor *v15; // rdi
  SSActor **i_array_p; // rax
  SSActor **v17; // r8
  SSClass *i_class_p; // rdi
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **v20; // rbx
  ARefCountMix<SSInstance> **j; // rdi

  if ( ppResult )
  {
    ArgByNameOrInstance = UFG::TSTriggerRegion::GetArgByNameOrInstance(pScope, 0);
    v5 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v6 = v5;
    if ( v5 )
    {
      v5->i_items.i_count = 0;
      v5->i_items.i_array_p = 0i64;
      v5->i_items.i_size = 0;
      v5->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v6 = 0i64;
    }
    *ppResult = SSList::as_instance(v6);
    if ( ArgByNameOrInstance )
    {
      i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
      if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      key_class = SSInstance::get_key_class(i_obj_p);
      vfptr_low = LODWORD(key_class[1].vfptr);
      if ( (_DWORD)vfptr_low )
      {
        v10 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
        if ( !v10 || v10 == SSBrain::c_nil_p )
        {
          i_user_data = 0i64;
        }
        else if ( v10->i_class_p == SSBrain::c_list_class_p )
        {
          i_user_data = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v10->i_user_data;
        }
        else
        {
          UFG::gTSPhysicalActor_singleExclude.i_count = 0;
          i_user_data = &UFG::gTSPhysicalActor_singleExclude;
          APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v10);
        }
        v12 = *(UFG::RegionComponent **)&ArgByNameOrInstance[6].mUID;
        v13 = *(SSActor ***)&key_class[1].i_name.i_uid;
        for ( i = &v13[vfptr_low]; v13 < i; ++v13 )
        {
          v15 = *v13;
          if ( i_user_data
            && i_user_data->i_count
            && (i_array_p = i_user_data->i_array_p, v17 = &i_array_p[i_user_data->i_count - 1], i_array_p <= v17) )
          {
            while ( v15 != *i_array_p )
            {
              if ( ++i_array_p > v17 )
                goto LABEL_22;
            }
          }
          else
          {
LABEL_22:
            i_class_p = v15[1].i_class_p;
            if ( i_class_p )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_class_p);
              if ( UFG::RegionComponent::IsHitPoint(v12, (UFG::qVector3 *)&i_class_p->i_class_data.i_array_p) )
                APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(
                  (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v6,
                  *v13);
            }
          }
        }
        i_count = v6->i_items.i_count;
        if ( (_DWORD)i_count )
        {
          v20 = (ARefCountMix<SSInstance> **)v6->i_items.i_array_p;
          for ( j = &v20[i_count]; v20 < j; ++v20 )
            UFG::PersistentData::MapFloat::Iterator::Next(*v20 + 4);
        }
      }
    }
  }
}

// File Line: 4989
// RVA: 0x510E80
void __fastcall UFG::TSPhysicalActor_MthdC_list_collect_trigger_outside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *ArgByNameOrInstance; // r15
  SSList *v5; // rax
  SSList *v6; // r14
  SSInstance *i_obj_p; // rcx
  SSClass *key_class; // rdi
  __int64 vfptr_low; // rbp
  SSActor *v10; // rdx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *i_user_data; // rsi
  UFG::RegionComponent *v12; // r15
  SSActor **v13; // rbx
  SSActor **i; // rbp
  SSActor *v15; // rdi
  SSActor **i_array_p; // rax
  SSActor **v17; // r8
  SSClass *i_class_p; // rdi
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **v20; // rbx
  ARefCountMix<SSInstance> **j; // rdi

  if ( ppResult )
  {
    ArgByNameOrInstance = UFG::TSTriggerRegion::GetArgByNameOrInstance(pScope, 0);
    v5 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v6 = v5;
    if ( v5 )
    {
      v5->i_items.i_count = 0;
      v5->i_items.i_array_p = 0i64;
      v5->i_items.i_size = 0;
      v5->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v6 = 0i64;
    }
    *ppResult = SSList::as_instance(v6);
    if ( ArgByNameOrInstance )
    {
      i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
      if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      key_class = SSInstance::get_key_class(i_obj_p);
      vfptr_low = LODWORD(key_class[1].vfptr);
      if ( (_DWORD)vfptr_low )
      {
        v10 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
        if ( !v10 || v10 == SSBrain::c_nil_p )
        {
          i_user_data = 0i64;
        }
        else if ( v10->i_class_p == SSBrain::c_list_class_p )
        {
          i_user_data = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v10->i_user_data;
        }
        else
        {
          UFG::gTSPhysicalActor_singleExclude.i_count = 0;
          i_user_data = &UFG::gTSPhysicalActor_singleExclude;
          APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v10);
        }
        v12 = *(UFG::RegionComponent **)&ArgByNameOrInstance[6].mUID;
        v13 = *(SSActor ***)&key_class[1].i_name.i_uid;
        for ( i = &v13[vfptr_low]; v13 < i; ++v13 )
        {
          v15 = *v13;
          if ( i_user_data
            && i_user_data->i_count
            && (i_array_p = i_user_data->i_array_p, v17 = &i_array_p[i_user_data->i_count - 1], i_array_p <= v17) )
          {
            while ( v15 != *i_array_p )
            {
              if ( ++i_array_p > v17 )
                goto LABEL_22;
            }
          }
          else
          {
LABEL_22:
            i_class_p = v15[1].i_class_p;
            if ( i_class_p )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_class_p);
              if ( !UFG::RegionComponent::IsHitPoint(v12, (UFG::qVector3 *)&i_class_p->i_class_data.i_array_p) )
                APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(
                  (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v6,
                  *v13);
            }
          }
        }
        i_count = v6->i_items.i_count;
        if ( (_DWORD)i_count )
        {
          v20 = (ARefCountMix<SSInstance> **)v6->i_items.i_array_p;
          for ( j = &v20[i_count]; v20 < j; ++v20 )
            UFG::PersistentData::MapFloat::Iterator::Next(*v20 + 4);
        }
      }
    }
  }
}

// File Line: 5050
// RVA: 0x511060
void __fastcall UFG::TSPhysicalActor_MthdC_list_refine_near_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbx
  UFG::qVector3 *i_user_data; // r14
  float v7; // xmm6_4
  SSList *v8; // rdi
  SSInstance *i_obj_p; // rcx
  APArrayBase<SSActor> *key_class; // rbp
  SSList *v11; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[2]->i_data_p;
  if ( ppResult || i_data_p != SSBrain::c_nil_p )
  {
    i_user_data = (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data;
    v7 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    if ( i_data_p->i_class_p == SSBrain::c_list_class_p )
    {
      v8 = (SSList *)i_data_p->i_user_data;
      ++i_data_p->i_ref_count;
    }
    else
    {
      i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
      if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      key_class = (APArrayBase<SSActor> *)SSInstance::get_key_class(i_obj_p);
      v11 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
      v8 = v11;
      if ( v11 )
      {
        v11->i_items.i_count = 0;
        v11->i_items.i_array_p = 0i64;
        v11->i_items.i_size = 0;
        v11->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      else
      {
        v8 = 0i64;
      }
      i_data_p = SSList::as_instance(v8);
      APArray<SSActor,SSActor,ACompareAddress<SSActor>>::operator=(
        (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v8,
        key_class + 19);
    }
    UFG::TSActor::ListRefineNear((APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v8, i_user_data, v7);
    if ( ppResult )
    {
      *ppResult = i_data_p;
    }
    else if ( i_data_p->i_ref_count-- == 1 )
    {
      i_data_p->i_ref_count = 0x80000000;
      i_data_p->vfptr[1].get_scope_context(i_data_p);
    }
  }
}

// File Line: 5109
// RVA: 0x5111A0
void __fastcall UFG::TSPhysicalActor_MthdC_list_select_nearest_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  UFG::qVector3 *i_user_data; // rbp
  SSActor *i_data_p; // rdx
  float v7; // xmm6_4
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v8; // rbx
  __int64 v9; // rdx
  APArrayBase<SSActor> *v10; // rax
  SSInstance *i_obj_p; // rcx
  UFG::TSActor *v12; // rax
  SSInstance *v13; // rcx

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data;
    i_data_p = (SSActor *)i_array_p[3]->i_data_p;
    v7 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    if ( !i_data_p || i_data_p == SSBrain::c_nil_p )
    {
      v8 = 0i64;
    }
    else if ( i_data_p->i_class_p == SSBrain::c_list_class_p )
    {
      v8 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)i_data_p->i_user_data;
    }
    else
    {
      v8 = &UFG::gTSPhysicalActor_singleExclude;
      UFG::gTSPhysicalActor_singleExclude.i_count = 0;
      APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, i_data_p);
    }
    v9 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64);
    if ( *(SSClass **)(v9 + 24) == SSBrain::c_list_class_p )
    {
      v10 = *(APArrayBase<SSActor> **)(v9 + 32);
    }
    else
    {
      i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
      if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      v10 = (APArrayBase<SSActor> *)&SSInstance::get_key_class(i_obj_p)[1];
    }
    v12 = UFG::TSActor::ListSelectNearest(v10, i_user_data, v7, v8);
    v13 = SSBrain::c_nil_p;
    if ( v12 )
      v13 = v12;
    *ppResult = v13;
    ++v13->i_ref_count;
  }
}

// File Line: 5164
// RVA: 0x4CCC60
void UFG::TSActor::BindAtomics(void)
{
  SSClass *v0; // rbx
  SSClass *v1; // rax
  SSClass *v2; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-20h]
  ASymbol rebinda; // [rsp+20h] [rbp-20h]
  ASymbol rebindb; // [rsp+20h] [rbp-20h]
  ASymbol rebindc; // [rsp+20h] [rbp-20h]
  ASymbol rebindd; // [rsp+20h] [rbp-20h]
  ASymbol rebinde; // [rsp+20h] [rbp-20h]
  ASymbol rebindf; // [rsp+20h] [rbp-20h]
  char (__fastcall *v10)(UFG::TSActor *, SSInvokedCoroutine *); // [rsp+30h] [rbp-10h] BYREF
  int v11; // [rsp+38h] [rbp-8h]

  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_SimObject;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "SimObject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_actor_class_p, "list_convert", UFG::TSActor::MthdC_list_convert, 1, rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Coro_wait_ai_stimulus;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_wait_ai_stimulus",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Coro_invoke_aibehaviour;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_invoke_aibehaviour",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_end_aibehaviour;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "end_aibehaviour",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_suspend;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "suspend",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_restore;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "restore",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_triad_wars_player_id;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_triad_wars_player_id",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_close_enough_to_marker;
  v11 = 0;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_close_enough_to_marker",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))_;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "display_debug_marker",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_begin_stimulus_one_off_internal;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "begin_stimulus_one_off_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_begin_stimulus_duration_internal;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "begin_stimulus_duration_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_begin_stimulus_internal;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "begin_stimulus_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_end_stimulus_internal;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "end_stimulus_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_physical_actor_class_p,
    "is_class_inside_trigger",
    UFG::TSPhysicalActor_MthdC_is_class_inside_trigger,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_physical_actor_class_p,
    "list_collect_trigger_inside",
    UFG::TSPhysicalActor_MthdC_list_collect_trigger_inside,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_physical_actor_class_p,
    "list_collect_trigger_outside",
    UFG::TSPhysicalActor_MthdC_list_collect_trigger_outside,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_physical_actor_class_p,
    "list_collect_near_pos",
    UFG::TSPhysicalActor_MthdC_list_collect_near_pos,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_physical_actor_class_p,
    "list_refine_near_pos",
    UFG::TSPhysicalActor_MthdC_list_refine_near_pos,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_physical_actor_class_p,
    "list_select_nearest_pos",
    UFG::TSPhysicalActor_MthdC_list_select_nearest_pos,
    1,
    rebindf);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_was_hit_by_vehicle;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "was_hit_by_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_was_shot;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "was_shot",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_has_hit_object;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "has_hit_object",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_has_hit_static_object;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "has_hit_static_object",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_are_resources_loaded;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "are_resources_loaded",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_spawn_priority;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "get_spawn_priority",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_inc_spawn_priority_ref;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "inc_spawn_priority_ref",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_dec_spawn_priority_ref;
  SSClass::register_method_mthd(
    SSBrain::c_physical_actor_class_p,
    "dec_spawn_priority_ref",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_actor_class_p,
    &ASymbol_find_named,
    UFG::TSActor::MthdC_find_named,
    SSBindFlag_class_rebind);
  SSClass::register_method_func(
    SSBrain::c_actor_class_p,
    "find_instance",
    UFG::TSActor::MthdC_find_instance,
    SSBindFlag_class_rebind);
  SSClass::register_method_func(
    SSBrain::c_actor_class_p,
    "get_instance",
    UFG::TSActor::MthdC_get_instance,
    SSBindFlag_class_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_despawn;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "despawn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_enable_physics;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "enable_physics",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_has_fractured_parts;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "has_fractured_parts",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_valid_simobject;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_valid_simobject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_valid_simproxy;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_valid_simproxy",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_dir;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_dir",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_dir_back;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_dir_back",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_dir_right;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_dir_right",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_dir_left;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_dir_left",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_dir_up;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_dir_up",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_dir_down;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_dir_down",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_pos;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_pos",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_properties;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_properties",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_archetype_properties;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_archetype_properties",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_xform;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_teleport_dir;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "teleport_dir",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_teleport_pos;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "teleport_pos",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_teleport_pos_preserve_vel;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "teleport_pos_preserve_vel",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_teleport_xform;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "teleport_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_teleport_xform_preserve_vel;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "teleport_xform_preserve_vel",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_last_teleport_frame;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_last_teleport_frame",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_in_view;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_in_view",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_reset_follow_camera;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "reset_follow_camera",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_rim_boost;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_rim_boost",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))_;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_rim_boost",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_highlighted;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_highlighted",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_is_highlighted;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "enable_highlight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_action_tree_query;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "action_tree_query",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_playing_node;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_playing_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_playing_full_path_node;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_playing_full_path_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_playing_ai_node;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_playing_ai_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_playing_full_path_ai_node;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_playing_full_path_ai_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_action_tree_opening_branch;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_action_tree_opening_branch",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_dbg_get_playing_full_path;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "dbg_get_playing_full_path",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_load_facefx_actor;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "load_facefx_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_play_facial_anim;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "play_facial_anim",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_unmount_facial_animset;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "mount_facial_animset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_unload_facefx_actor;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "unload_facefx_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_unmount_facial_animset;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "unmount_facial_animset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_pwr_suspend_allow;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "pwr_suspend_allow",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_pwr_suspend_prevent;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "pwr_suspend_prevent",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = UFG::TSActor::Coro_animate;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_animate",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_attach_target;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "attach_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_detach_target;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "detach_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_attach;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "attach",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_detach;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "detach",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_clear_target;
  v11 = 0;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "clear_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_target;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_target_as_simobject;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_target_as_simobject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_target;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_target_lock;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_target_lock",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_target_prop;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_target_prop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_subtarget;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_subtarget",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_attack_target;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_attack_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_target_valid;
  v11 = 0;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_target_valid",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_target_locked;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_target_locked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_inventory_item;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "get_inventory_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_best_interaction_point;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_best_interaction_point",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_is_best_interaction_point_busy;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "is_best_interaction_point_busy",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_interaction_point_active;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_interaction_point_active",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_minimap_add_blip;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "minimap_add_blip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_minimap_remove_blip;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "minimap_remove_blip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_audio_event;
  v11 = 0;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "audio_event",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_audio_override_tagged_dialogue;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "audio_override_tagged_dialogue",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_audio_force_disable;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "audio_force_disable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_audio_force_init;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "audio_force_init",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_stop_speech;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "stop_speech",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_audio_set_obstruction_occlusion;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "audio_set_obstruction_occlusion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_facial_emotion;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_facial_emotion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_audio_dialogue",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Coro_wait_until_done_speaking;
  v11 = 0;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_wait_until_done_speaking",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Coro_audio_event;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_audio_event",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = UFG::TSActor::Coro_audio_dialogue_external_filename;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_audio_dialogue_external_filename",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = UFG::TSActor::Coro_audio_dialogue_external_context;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_audio_dialogue_external_context",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Coro_wait_until_fight_over;
  SSClass::register_coroutine_mthd(
    SSBrain::c_actor_class_p,
    "_wait_until_fight_over",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_fail_trigger;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_fail_trigger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_fail_threshold;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_fail_threshold",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_fail_caption;
  SSClass::register_method_mthd(
    SSBrain::c_actor_class_p,
    "set_fail_caption",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v0 = SSBrain::get_class("Weapon");
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_health;
  v11 = 0;
  SSClass::register_method_mthd(
    v0,
    "get_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_owner;
  SSClass::register_method_mthd(
    v0,
    "get_owner",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v1 = SSBrain::get_class("Firearm");
  v11 = 0;
  v2 = v1;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_if_reset_ammo_on_death;
  SSClass::register_method_mthd(
    v1,
    "set_if_reset_ammo_on_death",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_override_rate_of_fire;
  SSClass::register_method_mthd(
    v2,
    "override_rate_of_fire",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_fire_mode;
  SSClass::register_method_mthd(
    v2,
    "set_fire_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_fire_mode;
  SSClass::register_method_mthd(
    v2,
    "get_fire_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_total_ammo;
  SSClass::register_method_mthd(
    v2,
    "set_total_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_total_ammo;
  SSClass::register_method_mthd(
    v2,
    "get_total_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_clip_ammo;
  SSClass::register_method_mthd(
    v2,
    "set_clip_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_clip_ammo;
  SSClass::register_method_mthd(
    v2,
    "get_clip_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_add_clip_to_gun;
  SSClass::register_method_mthd(
    v2,
    "add_clip_to_gun",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_set_must_hit_target;
  SSClass::register_method_mthd(
    v2,
    "set_must_hit_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_clear_must_hit_target;
  SSClass::register_method_mthd(
    v2,
    "clear_must_hit_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  v11 = 0;
  v10 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSActor::Mthd_get_weapon_type;
  SSClass::register_method_mthd(
    v2,
    "get_weapon_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v10,
    SSBindFlag_instance_no_rebind);
  UFG::gpAIStimulusTypeClass = SSBrain::get_class("AIStimulusType");
  SSClass::register_method_func(UFG::gpAIStimulusTypeClass, &ASymbolX_ctor, UFG::TSAIStimulusType_MthdC_ctor, 1, 0);
}

// File Line: 5364
// RVA: 0x50F180
void UFG::TSActor::PostFrameCleanup(void)
{
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v0; // rbx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *mPrev; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v2; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *mNext; // rbx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v4; // rdx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v5; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *i; // rdx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v7; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v8; // rax

  v0 = UFG::StimulusNotifyScript::smActiveList.mNode.mNext - 3;
  while ( v0 != (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&A_cos_355_deg_31 )
  {
    mPrev = v0[4].mPrev;
    if ( mPrev && LODWORD(v0[4].mNext) == LODWORD(mPrev->mNext) )
    {
      v0 = v0[3].mNext - 3;
    }
    else
    {
      v2 = v0;
      mNext = v0[3].mNext;
      v4 = v2[3].mPrev;
      v5 = v2[3].mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v2[3].mPrev = v2 + 3;
      v2[3].mNext = v2 + 3;
      v0 = mNext - 3;
      ((void (__fastcall *)(UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *, __int64))v2->mPrev->mPrev)(
        v2,
        1i64);
    }
  }
  for ( i = UFG::StimulusNotifyScript::smDeleteList.mNode.mNext;
        (const float *)&UFG::StimulusNotifyScript::smDeleteList.mNode.mNext[-3] != &A_cos_335_deg_31;
        i = UFG::StimulusNotifyScript::smDeleteList.mNode.mNext )
  {
    v7 = i->mPrev;
    v8 = i->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)48 )
      ((void (__fastcall *)(UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *, __int64))i[-3].mPrev->mPrev)(
        &i[-3],
        1i64);
  }
}

// File Line: 5393
// RVA: 0x50F3F0
void __fastcall UFG::TSActor::RayCastToTargetAsyncRayCallback(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *simComponent,
        _DWORD *callbackUserData)
{
  SSInvokedContextBase *v3; // rbx
  unsigned __int8 IsVisible; // si
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rax
  SSData *v8; // rdx
  SSInstance *i_data_p; // rax
  UFG::SimObject *ray_hit_object; // [rsp+40h] [rbp+18h] BYREF

  v3 = *(SSInvokedContextBase **)callbackUserData;
  IsVisible = 0;
  if ( !*(_QWORD *)callbackUserData || callbackUserData[2] != v3->i_ptr_id )
    v3 = 0i64;
  operator delete[](callbackUserData);
  if ( v3 )
  {
    if ( simComponent )
    {
      ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(v3, 1u);
      ray_hit_object = 0i64;
      IsVisible = UFG::TargetIsVisible(
                    raycastData,
                    (UFG::SimObjectGame *)ArgByNameOrInstance,
                    (UFG::VehicleOccupantComponent **)&ray_hit_object);
    }
    v8 = *v3->i_data.i_array_p;
    i_data_p = v8->i_data_p;
    LOBYTE(v8) = 1;
    i_data_p->i_user_data = IsVisible;
    ((void (__fastcall *)(SSInvokedContextBase *, SSData *))v3->vfptr[1].get_topmost_scope)(v3, v8);
  }
}

// File Line: 5424
// RVA: 0x4DCCE0
char __fastcall UFG::TSActor::Coro_raycast_to_target(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectCVBase *ArgByNameOrInstance; // rsi
  Render::DebugDrawContext *Context; // r14
  UFG::SimObject *m_pPointer; // r8
  __int64 v7; // rcx
  bool v8; // bp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rbx
  bool v14; // al
  UFG::qColour *v16; // r9
  UFG::qVector3 raycastPosition; // [rsp+48h] [rbp-40h] BYREF
  UFG::qVector3 p1; // [rsp+58h] [rbp-30h] BYREF

  ArgByNameOrInstance = (UFG::SimObjectCVBase *)UFG::TSSimObject::GetArgByNameOrInstance(pScope, 1u);
  if ( ArgByNameOrInstance
    && (Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                2u),
        (m_pPointer = this->mpSimObj.m_pPointer) != 0i64) )
  {
    v7 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64);
    v8 = *(_QWORD *)(v7 + 32) != 0i64;
    if ( !*(_QWORD *)(v7 + 32) && pScope->i_update_count )
      goto LABEL_17;
    if ( (m_pPointer->m_Flags & 0x8000u) == 0 )
    {
      UFG::ComputeObjectRaycastPosition((UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer, &raycastPosition);
    }
    else
    {
      m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      raycastPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      raycastPosition.y = y;
      raycastPosition.z = z + 5.0;
    }
    UFG::ComputeObjectRaycastPosition(ArgByNameOrInstance, &p1);
    if ( pScope->i_update_count )
    {
LABEL_17:
      if ( v8 )
      {
        v16 = &UFG::qColour::Green;
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v16 = &UFG::qColour::Red;
        Render::DebugDrawContext::DrawLine(Context, &raycastPosition, &p1, v16, &UFG::qMatrix44::msIdentity, 0i64, 0);
      }
    }
    else
    {
      if ( v8 )
        Render::DebugDrawContext::DrawLine(
          Context,
          &raycastPosition,
          &p1,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
      v12 = UFG::qMalloc(0x10ui64, "TSActor::Coro_raycast_to_target", 0i64);
      v13 = v12;
      if ( v12 )
      {
        v12->mNext = (UFG::allocator::free_link *)pScope;
        LODWORD(v12[1].mNext) = pScope->i_ptr_id;
      }
      else
      {
        v13 = 0i64;
      }
      v14 = UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
              UFG::BasePhysicsSystem::mInstance,
              &raycastPosition,
              &p1,
              12u,
              UFG::TSActor::RayCastToTargetAsyncRayCallback,
              this->mpComponent,
              v13);
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
      if ( v14 )
      {
        ++pScope->i_pending_count;
        return 0;
      }
      operator delete[](v13);
    }
  }
  else
  {
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
  }
  return 1;
}

