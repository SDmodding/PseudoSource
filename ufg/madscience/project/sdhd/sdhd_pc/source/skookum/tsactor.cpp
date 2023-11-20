// File Line: 162
// RVA: 0x4E1760
const char *__fastcall UFG::TSActorComponent::GetTypeName(UFG::TSActorComponent *this)
{
  return "TSActorComponent";
}

// File Line: 176
// RVA: 0x4CB750
void __fastcall UFG::TSActorComponent::TSActorComponent(UFG::TSActorComponent *this, UFG::qSymbol *name, UFG::qSymbol *className)
{
  UFG::qSymbol *v3; // rbx
  UFG::TSActorComponent *v4; // rdi
  SSClass *v5; // rax
  SSActorClass *v6; // rbx

  v3 = className;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name->mUID);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TSActorComponent::`vftable;
  v4->mpActor.i_obj_p = 0i64;
  v4->mpActor.i_ptr_id = 0;
  v4->mpActorClass = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TSActorComponent::_TSActorComponentTypeUID,
    "TSActorComponent");
  v5 = SSBrain::get_class((ASymbol *)v3);
  v6 = (SSActorClass *)v5;
  if ( v5 && v5->vfptr->is_actor_class((SSClassDescBase *)&v5->vfptr) )
    v4->mpActorClass = v6;
  else
    v4->mpActorClass = SSBrain::c_actor_class_p;
}

// File Line: 223
// RVA: 0x4E0C50
UFG::TSActor *__fastcall UFG::TSActorComponent::GetActor(UFG::TSActorComponent *this)
{
  UFG::TSActorComponent *v1; // rbx
  UFG::TSActor *v2; // rcx
  UFG::SimObject *v3; // rsi
  SSActorClass *v5; // rdi
  SSClass *v6; // rcx
  SSClass *v7; // rcx
  SSActor *v8; // rax
  UFG::TSActor *v9; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rax
  unsigned int v11; // eax
  UFG::TSVehicle *v12; // rax
  unsigned int v13; // ecx
  UFG::TSActor *v14; // rcx
  UFG::TSActor *v15; // rcx
  UFG::TSActor *v16; // rcx
  UFG::TSActor *v17; // rcx
  ASymbol name; // [rsp+50h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v20; // [rsp+60h] [rbp+18h]

  v1 = this;
  v2 = this->mpActor.i_obj_p;
  if ( !v2 || v2->i_ptr_id != v1->mpActor.i_ptr_id )
  {
    v3 = v1->m_pSimObject;
    if ( (LOBYTE(v3->m_Flags) >> 1) & 1 )
      return 0i64;
    name.i_uid = UFG::qSymbol::qSymbol(&result, v1->m_NameUID)->mUID;
    v5 = v1->mpActorClass;
    if ( UFG::TSVehicle::mClass == v5
      || (v6 = v5->i_superclass_p) != 0i64 && SSClass::is_class(v6, (SSClass *)&UFG::TSVehicle::mClass->vfptr) )
    {
      v12 = (UFG::TSVehicle *)AMemory::c_malloc_func(0x140ui64, "TSVehicle");
      *(_QWORD *)&result.mUID = v12;
      if ( v12 )
        UFG::TSVehicle::TSVehicle(v12, &name);
    }
    else
    {
      if ( UFG::SkookumMgr::mspCharacterClass != v5 )
      {
        v7 = v5->i_superclass_p;
        if ( !v7 || !SSClass::is_class(v7, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
        {
          v8 = (SSActor *)AMemory::c_malloc_func(0xD8ui64, "TSActor");
          v9 = (UFG::TSActor *)v8;
          *(_QWORD *)&result.mUID = v8;
          if ( v8 )
          {
            SSActor::SSActor(v8, &name, v1->mpActorClass, 1);
            v9->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
            UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v9->mTransformNodeComponent);
            v9->mpComponent = 0i64;
            v9->m_audioController.m_pEvent = 0i64;
            v10 = &v9->mpSimObj;
            v20 = v10;
            v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
            v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
            v9->mpSimObj.m_pPointer = 0i64;
          }
          else
          {
            v9 = 0i64;
          }
          v1->mpActor.i_obj_p = v9;
          if ( v9 )
            v11 = v9->i_ptr_id;
          else
            v11 = 0;
          v1->mpActor.i_ptr_id = v11;
LABEL_27:
          v14 = v1->mpActor.i_obj_p;
          if ( !v14 || v1->mpActor.i_ptr_id != v14->i_ptr_id )
            v14 = 0i64;
          v14->mpComponent = v1;
          v15 = v1->mpActor.i_obj_p;
          if ( !v15 || v1->mpActor.i_ptr_id != v15->i_ptr_id )
            v15 = 0i64;
          ++v15->i_ref_count;
          v16 = v1->mpActor.i_obj_p;
          if ( !v16 || v1->mpActor.i_ptr_id != v16->i_ptr_id )
            v16 = 0i64;
          ((void (__fastcall *)(UFG::TSActor *, UFG::SimObject *))v16->vfptr[2].is_actor)(v16, v3);
          goto LABEL_37;
        }
      }
      v12 = (UFG::TSVehicle *)AMemory::c_malloc_func(0x1E0ui64, "TSCharacter");
      *(_QWORD *)&result.mUID = v12;
      if ( v12 )
        UFG::TSCharacter::TSCharacter((UFG::TSCharacter *)v12, &name, v1->mpActorClass);
    }
    v1->mpActor.i_obj_p = (UFG::TSActor *)&v12->vfptr;
    if ( v12 )
      v13 = v12->i_ptr_id;
    else
      v13 = 0;
    v1->mpActor.i_ptr_id = v13;
    goto LABEL_27;
  }
LABEL_37:
  v17 = v1->mpActor.i_obj_p;
  if ( !v17 || v1->mpActor.i_ptr_id != v17->i_ptr_id )
    v17 = 0i64;
  return v17;
}

// File Line: 260
// RVA: 0x50F270
UFG::SimComponent *__fastcall UFG::TSActorComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObject, bool required)
{
  bool v2; // r14
  UFG::SceneObjectProperties *v3; // rdi
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  char *v6; // rsi
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // r14
  UFG::qSymbol *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rsi
  UFG::SimObject *v13; // rdx
  unsigned __int16 v14; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+40h] [rbp-38h]
  UFG::qSymbol result; // [rsp+80h] [rbp+8h]
  UFG::allocator::free_link *v18; // [rsp+90h] [rbp+18h]

  v2 = required;
  v3 = pSceneObject;
  v4 = pSceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_TSActor::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 )
  {
    v6 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v6 )
      goto LABEL_9;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v8 = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(v8, 0x58ui64, "TSActorComponent", 0i64, 1u);
  v18 = v9;
  if ( v9 )
  {
    v10 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v3, &result);
    UFG::TSActorComponent::TSActorComponent((UFG::TSActorComponent *)v9, v10, (UFG::qSymbol *)v6);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = v3->m_pSimObject;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 )
  {
    v15 = 4;
  }
  else if ( (v14 >> 13) & 1 )
  {
    v15 = 3;
  }
  else
  {
    v15 = -1;
    if ( (v14 >> 12) & 1 )
      v15 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v16, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v12, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v12;
}

// File Line: 286
// RVA: 0x4CB7E0
void __fastcall UFG::TSActorComponent::TSActorComponent(UFG::TSActorComponent *this, UFG::TSActor *pActor)
{
  UFG::TSActor *v2; // rdi
  UFG::TSActorComponent *v3; // rbx
  UFG::TSActor *v4; // rcx

  v2 = pActor;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pActor->i_name.i_uid);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TSActorComponent::`vftable;
  v3->mpActor.i_obj_p = v2;
  v3->mpActor.i_ptr_id = v2->i_ptr_id;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::TSActorComponent::_TSActorComponentTypeUID,
    "TSActorComponent");
  v4 = v3->mpActor.i_obj_p;
  if ( !v4 || v3->mpActor.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  v4->mpComponent = v3;
  ++v2->i_ref_count;
}

// File Line: 313
// RVA: 0x50E840
void __fastcall UFG::TSActorComponent::OnAttach(UFG::TSActorComponent *this, UFG::SimObject *pSimObj)
{
  UFG::TSActor *v2; // rax
  unsigned int v3; // er8
  UFG::TSActor *v4; // rcx

  v2 = this->mpActor.i_obj_p;
  if ( v2 )
  {
    v3 = this->mpActor.i_ptr_id;
    if ( v2->i_ptr_id == v3 )
    {
      v4 = 0i64;
      if ( v3 == v2->i_ptr_id )
        v4 = v2;
      ((void (__fastcall *)(UFG::TSActor *, UFG::SimObject *))v4->vfptr[2].is_actor)(v4, pSimObj);
    }
  }
}

// File Line: 325
// RVA: 0x50EAA0
void __fastcall UFG::TSActorComponent::OnDetach(UFG::TSActorComponent *this)
{
  UFG::TSActor *v1; // rax
  UFG::TSActorComponent *v2; // rbx
  unsigned int v3; // edx
  UFG::TSActor *v4; // rcx

  v1 = this->mpActor.i_obj_p;
  v2 = this;
  if ( v1 )
  {
    v3 = this->mpActor.i_ptr_id;
    if ( v1->i_ptr_id == v3 )
    {
      v4 = 0i64;
      if ( v3 == v1->i_ptr_id )
        v4 = v1;
      ((void (*)(void))v4->vfptr[2].as_instance)();
      v2->mpActor.i_obj_p = 0i64;
      v2->mpActor.i_ptr_id = 0;
    }
  }
}

// File Line: 338
// RVA: 0x510590
void __fastcall UFG::TSActorComponent::Suspend(UFG::TSActorComponent *this)
{
  UFG::TSActor *v1; // rdx
  unsigned int v2; // er8
  UFG::TSActor *v3; // rax

  this->m_Flags |= 2u;
  v1 = this->mpActor.i_obj_p;
  if ( v1 )
  {
    v2 = this->mpActor.i_ptr_id;
    if ( v1->i_ptr_id == v2 )
    {
      v3 = 0i64;
      if ( v2 == v1->i_ptr_id )
        v3 = this->mpActor.i_obj_p;
      v3->i_actor_flags &= 0xFFFFFFFB;
    }
  }
}

// File Line: 352
// RVA: 0x50F620
void __fastcall UFG::TSActorComponent::Restore(UFG::TSActorComponent *this)
{
  UFG::TSActor *v1; // rdx
  unsigned int v2; // er8
  UFG::TSActor *v3; // rax

  this->m_Flags &= 0xFFFDu;
  v1 = this->mpActor.i_obj_p;
  if ( v1 )
  {
    v2 = this->mpActor.i_ptr_id;
    if ( v1->i_ptr_id == v2 )
    {
      v3 = 0i64;
      if ( v2 == v1->i_ptr_id )
        v3 = this->mpActor.i_obj_p;
      v3->i_actor_flags |= 4u;
    }
  }
}

// File Line: 389
// RVA: 0x15310B0
__int64 dynamic_initializer_for__UFG::StimulusNotifyScript::smDeleteList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StimulusNotifyScript::smDeleteList__);
}

// File Line: 390
// RVA: 0x1531090
__int64 dynamic_initializer_for__UFG::StimulusNotifyScript::smActiveList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StimulusNotifyScript::smActiveList__);
}

// File Line: 406
// RVA: 0x4CB600
void __fastcall UFG::StimulusNotifyScript::StimulusNotifyScript(UFG::StimulusNotifyScript *this, UFG::eStimulusType notify_type, SSInvokedCoroutine *pICoroutine, UFG::SimObject *pEmitter)
{
  SSInvokedCoroutine *v4; // rsi
  UFG::StimulusNotifyScript *v5; // rbx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v6; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v7; // rdi
  unsigned int v8; // eax
  hkSeekableStreamReader *v9; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v10; // rax

  v4 = pICoroutine;
  v5 = this;
  v6 = (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (UFG::StimulusNotifyCallbackVtbl *)&UFG::StimulusNotifyCallback::`vftable;
  this->m_type = notify_type;
  this->m_delegate.m_Closure.m_pthis = 0i64;
  this->m_delegate.m_Closure.m_pFunction = 0i64;
  v7 = (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::StimulusNotifyCallbackVtbl *)&UFG::StimulusNotifyScript::`vftable;
  this->mpICoroutine.i_obj_p = pICoroutine;
  if ( pICoroutine )
    v8 = pICoroutine->i_ptr_id;
  else
    v8 = 0;
  this->mpICoroutine.i_ptr_id = v8;
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObject>(
    &this->mpEmitter,
    pEmitter);
  v9 = Assembly::GetRCX(v5);
  v5->m_delegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::StimulusNotifyScript::OnStimulusNotify;
  v5->m_delegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v9;
  ++v4->i_pending_count;
  v10 = UFG::StimulusNotifyScript::smActiveList.mNode.mPrev;
  UFG::StimulusNotifyScript::smActiveList.mNode.mPrev->mNext = v7;
  v7->mPrev = v10;
  v7->mNext = (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&UFG::StimulusNotifyScript::smActiveList;
  UFG::StimulusNotifyScript::smActiveList.mNode.mPrev = v7;
}

// File Line: 437
// RVA: 0x50ECF0
char __fastcall UFG::StimulusNotifyScript::OnStimulusNotify(UFG::StimulusNotifyScript *this, UFG::StimulusReceiverComponent *pRecvComp, UFG::Stimulus *pStimulus, UFG::StimulusNotifyCallback *pCallback)
{
  SSInvokedCoroutine *v4; // rbx
  UFG::StimulusReceiverComponent *v5; // rbp
  UFG::SimObject *v6; // rax
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
  SSData **v19; // rcx
  SSData *v20; // rsi
  SSInstance *v21; // rdi
  SSInstance *v22; // rcx
  SSInstance *v23; // rdi
  __int64 v24; // rbx
  _DWORD *v25; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v26; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v27; // rdx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v28; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v29; // rax

  v4 = this->mpICoroutine.i_obj_p;
  v5 = pRecvComp;
  if ( !v4 || this->mpICoroutine.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  v6 = this->mpEmitter.m_pPointer;
  if ( pStimulus )
  {
    if ( !v4 )
    {
LABEL_22:
      v26 = this->mNext;
      v27 = (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&this->mPrev;
      v28 = this->mPrev;
      v28->mNext = v26;
      v26->mPrev = v28;
      v27->mPrev = v27;
      v27->mNext = v27;
      v29 = UFG::StimulusNotifyScript::smDeleteList.mNode.mPrev;
      UFG::StimulusNotifyScript::smDeleteList.mNode.mPrev->mNext = v27;
      v27->mPrev = v29;
      v27->mNext = (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&UFG::StimulusNotifyScript::smDeleteList;
      UFG::StimulusNotifyScript::smDeleteList.mNode.mPrev = v27;
      return 1;
    }
    if ( v6 || !this->mpEmitter.m_Changed )
    {
      v7 = pStimulus->m_pStimulusProducer.m_pPointer;
      if ( v6 && v6 != v7 )
        return 0;
      v9 = UFG::TSSimObject::AsInstanceSimOrActor(v7, *(SSInstance **)(*((_QWORD *)v4->i_data.i_array_p + 2) + 8i64));
      v10 = *((_QWORD *)v4->i_data.i_array_p + 3);
      ++v9->i_ref_count;
      v11 = v9;
      v12 = *(_DWORD **)(v10 + 8);
      v13 = v12[4]-- == 1;
      if ( v13 )
      {
        v12[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v12 + 112i64))();
      }
      *(_QWORD *)(v10 + 8) = v11;
      v14 = UFG::TSSimObject::AsInstanceSimOrActor(
              v5->m_pSimObject,
              *(SSInstance **)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64));
      v16 = *((_QWORD *)v4->i_data.i_array_p + 4);
      ++v14->i_ref_count;
      v17 = v14;
      v18 = *(_DWORD **)(v16 + 8);
      v13 = v18[4]-- == 1;
      if ( v13 )
      {
        v18[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v18 + 112i64))();
      }
      *(_QWORD *)(v16 + 8) = v17;
      v19 = v4->i_data.i_array_p;
      v20 = v19[5];
      v21 = (*v19)->i_data_p;
      ++v21->i_ref_count;
      v22 = v20->i_data_p;
      v13 = v22->i_ref_count-- == 1;
      if ( v13 )
      {
        v22->i_ref_count = 2147483648;
        ((void (*)(void))v22->vfptr[1].get_scope_context)();
      }
      v20->i_data_p = v21;
      LOBYTE(v15) = 1;
      ((void (__fastcall *)(SSInvokedCoroutine *, __int64))v4->vfptr[1].get_topmost_scope)(v4, v15);
      return 1;
    }
  }
  if ( !v4 )
    goto LABEL_22;
  v23 = UFG::gpAIStimulusTypeClass_none;
  v24 = *((_QWORD *)v4->i_data.i_array_p + 5);
  ++v23->i_ref_count;
  v25 = *(_DWORD **)(v24 + 8);
  v13 = v25[4]-- == 1;
  if ( v13 )
  {
    v25[4] = 2147483648;
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
  UFG::TSActor *v3; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+58h] [rbp+20h]

  v3 = this;
  SSActor::SSActor((SSActor *)&this->vfptr, name, pClass, 1);
  v3->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v3->mTransformNodeComponent);
  v3->mpComponent = 0i64;
  v3->m_audioController.m_pEvent = 0i64;
  v4 = &v3->mpSimObj;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v3->mpSimObj.m_pPointer = 0i64;
}

// File Line: 523
// RVA: 0x4CBE40
void __fastcall UFG::TSActor::~TSActor(UFG::TSActor *this)
{
  UFG::TSActor *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::AudioEvent *v7; // rcx

  v1 = this;
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
  v2 = &this->mpSimObj;
  if ( this->mpSimObj.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = v1->m_audioController.m_pEvent;
  if ( v7 )
    UFG::AudioEvent::OnControllerDestroy(v7);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mTransformNodeComponent);
  SSActor::~SSActor((SSActor *)&v1->vfptr);
}

// File Line: 528
// RVA: 0x511890
UFG::TSActor *__fastcall UFG::TSActor::find_instance(UFG::qSymbol *instance_name)
{
  UFG::qSymbol *v1; // rbx
  UFG::TSActor *result; // rax
  UFG::qBaseNodeRB *v3; // rax

  v1 = instance_name;
  result = (UFG::TSActor *)SSActor::find((ASymbol *)instance_name);
  if ( !result )
  {
    v3 = UFG::Simulation::GetSimObject(&UFG::gSim, v1);
    result = UFG::TSActor::FromSimObject((UFG::SimObject *)v3);
  }
  return result;
}

// File Line: 662
// RVA: 0x4E0BC0
UFG::TSActor *__fastcall UFG::TSActor::FromSimObject(UFG::SimObject *pSimObj)
{
  unsigned __int16 v1; // dx
  UFG::TSActorComponent *v2; // rax
  UFG::TSActor *result; // rax

  if ( pSimObj
    && ((v1 = pSimObj->m_Flags, !((v1 >> 14) & 1)) ? ((v1 & 0x8000u) == 0 ? (!((v1 >> 13) & 1) ? (!((v1 >> 12) & 1) ? (v2 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(pSimObj, UFG::TSActorComponent::_TypeUID)) : (v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[2].m_pComponent)) : (v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[3].m_pComponent)) : (v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent)) : (v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent),
        v2) )
  {
    result = UFG::TSActorComponent::GetActor(v2);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 685
// RVA: 0x510480
UFG::TSActor *__fastcall UFG::TSActor::SkookumObjFromSimObj(UFG::SimObject *pSimObj)
{
  unsigned __int16 v1; // dx
  UFG::TSActorComponent *v2; // rax
  UFG::TSActor *result; // rax

  if ( !pSimObj )
    return (UFG::TSActor *)SSBrain::c_nil_p;
  v1 = pSimObj->m_Flags;
  if ( (v1 >> 14) & 1 )
  {
    v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent;
  }
  else if ( (v1 & 0x8000u) == 0 )
  {
    if ( (v1 >> 13) & 1 )
      v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[3].m_pComponent;
    else
      v2 = (UFG::TSActorComponent *)((v1 >> 12) & 1 ? pSimObj->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                                  pSimObj,
                                                                                                  UFG::TSActorComponent::_TypeUID));
  }
  else
  {
    v2 = (UFG::TSActorComponent *)pSimObj->m_Components.p[4].m_pComponent;
  }
  if ( !v2 )
    return (UFG::TSActor *)SSBrain::c_nil_p;
  result = UFG::TSActorComponent::GetActor(v2);
  ++result->i_ref_count;
  return result;
}

// File Line: 714
// RVA: 0x4E0EC0
UFG::TSActor *__fastcall UFG::TSActor::GetArgByNameOrInstance(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSInstance *v2; // rbx
  SSClass *v3; // rdi
  UFG::TSActor *result; // rax

  v2 = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( !v2 )
    goto LABEL_10;
  v3 = v2->i_class_p;
  if ( v3->vfptr->is_actor_class((SSClassDescBase *)&v3->vfptr) )
    return (UFG::TSActor *)v2;
  if ( v3 == SSBrain::c_symbol_class_p && LODWORD(v2->i_user_data) != -1 )
    result = (UFG::TSActor *)SSActor::find((ASymbol *)&v2->i_user_data);
  else
LABEL_10:
    result = 0i64;
  return result;
}

// File Line: 895
// RVA: 0x4E2390
__int64 __fastcall UFG::TSActor::ListCollectNear(APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pInstances, UFG::qVector3 *pos, float radius, SSActorClass *pClass, APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pExclusions)
{
  unsigned int v5; // ebp
  UFG::qVector3 *v6; // r13
  SSActor **v7; // rsi
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v8; // r14
  unsigned __int64 i; // r12
  SSActor *v10; // rbx
  unsigned int v11; // edx
  SSActor **v12; // rcx
  unsigned __int64 j; // r8
  float *v14; // rdi
  unsigned int v15; // er8
  SSActor **v16; // rcx
  unsigned __int64 k; // rdx

  v5 = pInstances->i_count;
  if ( !pClass )
    pClass = SSBrain::c_physical_actor_class_p;
  v6 = pos;
  v7 = pClass->i_instances.i_array_p;
  v8 = pInstances;
  for ( i = (unsigned __int64)&v7[pClass->i_instances.i_count]; (unsigned __int64)v7 < i; ++v7 )
  {
    v10 = *v7;
    if ( pExclusions )
    {
      v11 = 0;
      if ( pExclusions->i_count )
      {
        v12 = pExclusions->i_array_p;
        for ( j = (unsigned __int64)&v12[pExclusions->i_count - 1]; (unsigned __int64)v12 <= j; ++v12 )
        {
          if ( v10 == *v12 )
          {
            if ( v11 < 2 )
              goto LABEL_21;
            --v11;
          }
        }
      }
    }
    v14 = (float *)v10[1].i_class_p;
    if ( v14 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10[1].i_class_p);
      if ( (float)((float)((float)((float)(v6->y - v14[45]) * (float)(v6->y - v14[45]))
                         + (float)((float)(v6->x - v14[44]) * (float)(v6->x - v14[44])))
                 + (float)((float)(v6->z - v14[46]) * (float)(v6->z - v14[46]))) <= (float)(radius * radius) )
      {
        if ( v5 )
        {
          v15 = 0;
          if ( v8->i_count )
          {
            v16 = v8->i_array_p;
            for ( k = (unsigned __int64)&v16[v8->i_count - 1]; (unsigned __int64)v16 <= k; ++v16 )
            {
              if ( v10 == *v16 )
              {
                if ( v15 < 2 )
                  goto LABEL_21;
                --v15;
              }
            }
          }
        }
        APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, v10);
      }
    }
LABEL_21:
    ;
  }
  return v8->i_count - v5;
}

// File Line: 958
// RVA: 0x4E2500
__int64 __fastcall UFG::TSActor::ListRefineNear(APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pInstances, UFG::qVector3 *pos, float radius)
{
  __int64 v3; // rbx
  SSActor **v4; // r14
  UFG::qVector3 *v5; // r12
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v6; // rsi
  SSActor *v7; // rdi
  float *v8; // rbp
  SSActor **v9; // rax
  bool v10; // zf

  LODWORD(v3) = pInstances->i_count;
  v4 = pInstances->i_array_p;
  v5 = pos;
  v6 = pInstances;
  if ( !pInstances->i_count )
    return 0i64;
  do
  {
    v3 = (unsigned int)(v3 - 1);
    v7 = v4[v3];
    v8 = (float *)v7[1].i_class_p;
    if ( v8 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7[1].i_class_p);
      if ( (float)((float)((float)((float)(v5->x - v8[44]) * (float)(v5->x - v8[44]))
                         + (float)((float)(v5->y - v8[45]) * (float)(v5->y - v8[45])))
                 + (float)((float)(v5->z - v8[46]) * (float)(v5->z - v8[46]))) <= (float)(radius * radius) )
      {
        v9 = v6->i_array_p;
        memmove(&v9[v3], &v9[v3 + 1], 8i64 * (unsigned int)(--v6->i_count - v3));
        v10 = v7->i_ref_count-- == 1;
        if ( v10 )
        {
          v7->i_ref_count = 2147483648;
          v7->vfptr[1].get_scope_context((SSObjectBase *)&v7->vfptr);
        }
      }
    }
    ++v4;
  }
  while ( (_DWORD)v3 );
  return v6->i_count;
}

// File Line: 1008
// RVA: 0x4E2610
SSActor *__fastcall UFG::TSActor::ListSelectNearest(APArrayBase<SSActor> *candidates, UFG::qVector3 *pos, float radius, APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pExclusions)
{
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v4; // r14
  UFG::qVector3 *v5; // r12
  float v6; // xmm6_4
  SSActor **v7; // rdi
  SSActor *v8; // rbp
  unsigned __int64 i; // r15
  SSActor *v10; // rbx
  unsigned int v11; // edx
  SSActor **v12; // rcx
  unsigned __int64 j; // r8
  float *v14; // rsi

  v4 = pExclusions;
  v5 = pos;
  if ( radius < 0.0 )
    v6 = FLOAT_3_4028235e38;
  else
    v6 = radius * radius;
  v7 = candidates->i_array_p;
  v8 = 0i64;
  for ( i = (unsigned __int64)&v7[candidates->i_count]; (unsigned __int64)v7 < i; ++v7 )
  {
    v10 = *v7;
    if ( v4 )
    {
      v11 = 0;
      if ( v4->i_count )
      {
        v12 = v4->i_array_p;
        for ( j = (unsigned __int64)&v12[v4->i_count - 1]; (unsigned __int64)v12 <= j; ++v12 )
        {
          if ( v10 == *v12 )
          {
            if ( v11 < 2 )
              goto LABEL_15;
            --v11;
          }
        }
      }
    }
    v14 = (float *)v10[1].i_class_p;
    if ( v14 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10[1].i_class_p);
      if ( (float)((float)((float)((float)(v5->y - v14[45]) * (float)(v5->y - v14[45]))
                         + (float)((float)(v5->x - v14[44]) * (float)(v5->x - v14[44])))
                 + (float)((float)(v5->z - v14[46]) * (float)(v5->z - v14[46]))) < v6 )
      {
        v8 = v10;
        v6 = (float)((float)((float)(v5->y - v14[45]) * (float)(v5->y - v14[45]))
                   + (float)((float)(v5->x - v14[44]) * (float)(v5->x - v14[44])))
           + (float)((float)(v5->z - v14[46]) * (float)(v5->z - v14[46]));
      }
    }
LABEL_15:
    ;
  }
  return v8;
}

// File Line: 1054
// RVA: 0x50EAF0
void __fastcall UFG::TSActor::OnInit(UFG::TSActor *this, UFG::SimObject *pSimObj)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::TSActor *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpSimObj.mPrev;
  v3 = this;
  if ( this->mpSimObj.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = this->mpSimObj.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = v2;
    this->mpSimObj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpSimObj.mPrev;
  }
  this->mpSimObj.m_pPointer = pSimObj;
  if ( pSimObj )
  {
    v6 = pSimObj->m_SafePointerList.mNode.mPrev;
    v6->mNext = v2;
    v2->mPrev = v6;
    this->mpSimObj.mNext = &pSimObj->m_SafePointerList.mNode;
    pSimObj->m_SafePointerList.mNode.mPrev = v2;
  }
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Set(
    &this->mTransformNodeComponent,
    this->mpSimObj.m_pPointer->m_pTransformNodeComponent);
  SSInstance::call_default_constructor((SSInstance *)&v3->vfptr);
  SSActor::enable_behavior((SSActor *)&v3->vfptr, 1);
}

// File Line: 1081
// RVA: 0x50E870
void __fastcall UFG::TSActor::OnDeinit(UFG::TSActor *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // r8
  UFG::TSActor *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  unsigned int v7; // ecx
  bool v8; // zf
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = &this->mTransformNodeComponent;
  v2 = this;
  if ( this->mTransformNodeComponent.m_pSimComponent )
  {
    v3 = this->mTransformNodeComponent.mNext;
    v4 = v1->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    this->mTransformNodeComponent.m_pSimComponent = 0i64;
  }
  else
  {
    if ( !this->mTransformNodeComponent.m_pSimObject
      || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev == v1
      && (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->mTransformNodeComponent.mNext == &this->mTransformNodeComponent )
    {
      goto LABEL_8;
    }
    v5 = this->mTransformNodeComponent.mNext;
    v6 = v1->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
  }
  v1->m_pSimObject = 0i64;
  v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
  v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
LABEL_8:
  v1->m_Changed = 1;
  v7 = v2->i_ref_count;
  if ( (v2->i_ref_count & 0x7FFFFFFF) <= 1 )
  {
    v2->i_ref_count = v7 - 1;
    v8 = v7 == 1;
  }
  else
  {
    UFG::qSymbol::create_suffix(&result, (UFG::qSymbol *)&v2->i_name, "__DORMANT__");
    SSActor::rename((SSActor *)&v2->vfptr, (ASymbol *)&result);
    SSActor::enable_behavior((SSActor *)&v2->vfptr, 0);
    v8 = v2->i_ref_count-- == 1;
  }
  if ( v8 )
  {
    v2->i_ref_count = 2147483648;
    v2->vfptr[1].get_scope_context((SSObjectBase *)&v2->vfptr);
  }
}

// File Line: 1123
// RVA: 0x50EEC0
void __fastcall UFG::TSActor::OnTeleport(UFG::TSCharacter *this)
{
  SSObjectBaseVtbl *v1; // rax
  __int64 v2; // [rsp+40h] [rbp+8h]

  v1 = this->vfptr;
  v2 = 0i64;
  ((void (__fastcall *)(UFG::TSCharacter *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))v1[1].set_data_by_name)(
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
  UFG::TSActor *v1; // rbx

  v1 = this;
  SSInstance::call_destructor((SSInstance *)&this->vfptr);
  v1->i_ptr_id = 0;
  v1->vfptr->__vecDelDtor((SSObjectBase *)&v1->vfptr, 1u);
}

// File Line: 1147
// RVA: 0x4F3650
void __fastcall UFG::TSActor::Mthd_SimObject(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 )
      *ppResult = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)v3);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 1165
// RVA: 0x50C410
void __fastcall UFG::TSActor::Mthd_suspend(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( this->mpSimObj.m_pPointer )
    JUMPOUT(this->i_actor_flags & 0x10000, 0, UFG::SimObject::Suspend);
}

// File Line: 1181
// RVA: 0x506A00
void __fastcall UFG::TSActor::Mthd_restore(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( this->mpSimObj.m_pPointer )
    JUMPOUT(this->i_actor_flags & 0x10000, 0, UFG::SimObject::Restore);
}

// File Line: 1198
// RVA: 0x4F7B30
void __fastcall UFG::TSActor::Mthd_despawn(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // rbx
  SSInvokedMethod *v4; // rsi
  UFG::TSActor *v5; // rdi

  v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  v5 = this;
  if ( v3 && v3 != UFG::GetLocalPlayer() )
  {
    SSActor::enable_behavior((SSActor *)&v5->vfptr, 0);
    if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64) )
      UFG::Simulation::QueueSimObjectToBeDestroyedRecursive(&UFG::gSim, (UFG::SimObject *)&v3->vfptr);
    else
      UFG::Simulation::QueueTrackedSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)&v3->vfptr);
  }
}

// File Line: 1233
// RVA: 0x503CC0
void __fastcall UFG::TSActor::Mthd_is_valid_simobject(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( this->i_actor_flags & 0x10000 || !this->mpSimObj.m_pPointer )
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 1247
// RVA: 0x503D10
void __fastcall UFG::TSActor::Mthd_is_valid_simproxy(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(this->mpSimObj.m_pPointer != 0i64);
}

// File Line: 1256
// RVA: 0x501080
void __fastcall UFG::TSActor::Mthd_is_close_enough_to_marker(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rdi
  SSInvokedMethod *v5; // rsi
  UFG::TSActor *v6; // rbx
  bool v7; // bp
  UFG::qBaseTreeRB *v8; // rax
  SSData **v9; // rcx
  UFG::TransformNodeComponent *v10; // rsi
  float v11; // xmm6_4
  UFG::qBaseNodeRB *v12; // rbx
  UFG::TransformNodeComponent *v13; // rbx

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  v5 = pScope;
  v6 = this;
  if ( !v3 || this->i_actor_flags & 0x10000 )
    v3 = 0i64;
  if ( ppResult && v3 )
  {
    v7 = 0;
    v8 = UFG::TSMarker::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
    v9 = v5->i_data.i_array_p;
    v10 = (UFG::TransformNodeComponent *)v6->mTransformNodeComponent.m_pSimComponent;
    v11 = *(float *)&v9[1]->i_data_p->i_user_data;
    if ( v8 )
    {
      v12 = v8->mNULL.mChild[0];
      if ( v12 )
      {
        v13 = *(UFG::TransformNodeComponent **)&v12[2].mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform(v13);
        UFG::TransformNodeComponent::UpdateWorldTransform(v10);
        v7 = (float)(v11 * v11) > (float)((float)((float)((float)(v10->mWorldTransform.v3.y - v13->mWorldTransform.v3.y)
                                                        * (float)(v10->mWorldTransform.v3.y - v13->mWorldTransform.v3.y))
                                                + (float)((float)(v10->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)
                                                        * (float)(v10->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)))
                                        + (float)((float)(v10->mWorldTransform.v3.z - v13->mWorldTransform.v3.z)
                                                * (float)(v10->mWorldTransform.v3.z - v13->mWorldTransform.v3.z)));
      }
    }
    *v4 = (SSInstance *)SSBoolean::pool_new(v7);
  }
}

// File Line: 1292
// RVA: 0x4F8F60
void __fastcall UFG::TSActor::Mthd_enable_physics(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::RigidBody *v7; // rax
  unsigned int v8; // edx

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
      else
        v7 = (UFG::RigidBody *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v4,
                                                   UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                          (UFG::SimObject *)&v4->vfptr,
                                                                                          UFG::RigidBodyComponent::_TypeUID));
    }
    else
    {
      v7 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v7 )
    {
      v8 = 256;
      if ( (*v5->i_data.i_array_p)->i_data_p->i_user_data )
        v8 = 128;
      UFG::RigidBody::SetMotionType(v7, v8);
    }
  }
}

// File Line: 1314
// RVA: 0x4FFDF0
void __fastcall UFG::TSActor::Mthd_has_fractured_parts(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char v3; // di
  SSInstance **v4; // rsi
  UFG::RigidBody *i; // rbx

  v3 = 0;
  v4 = ppResult;
  if ( this->mpSimObj.m_pPointer )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      for ( i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                    this->mpSimObj.m_pPointer,
                                    UFG::RigidBodyComponent::_TypeUID);
            i;
            i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                    i->m_pSimObject,
                                    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                    0,
                                    (UFG::SimComponent *)&i->vfptr) )
      {
        v3 = UFG::RigidBody::HasFracturedParts(i);
        if ( v3 )
          break;
      }
    }
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 1336
// RVA: 0x4FC4A0
void __fastcall UFG::TSActor::Mthd_get_dir(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *v4 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v3[2]);
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
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi
  int v5; // xmm1_4
  int v6; // xmm0_4
  UFG::qVector3 vec; // [rsp+20h] [rbp-18h]

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      v5 = LODWORD(v3[2].m_SafePointerList.mNode.mPrev) ^ _xmm[0];
      LODWORD(vec.x) = LODWORD(v3[2].vfptr) ^ _xmm[0];
      v6 = HIDWORD(v3[2].vfptr);
      LODWORD(vec.z) = v5;
      LODWORD(vec.y) = v6 ^ _xmm[0];
    }
    else
    {
      vec = UFG::qVector3::msDirBack;
    }
    *v4 = UFG::TSVector3::AsInstance(&vec);
  }
}

// File Line: 1386
// RVA: 0x4FC920
void __fastcall UFG::TSActor::Mthd_get_dir_right(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi
  int v5; // xmm1_4
  int v6; // xmm0_4
  UFG::qVector3 vec; // [rsp+20h] [rbp-18h]

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      v5 = v3[2].m_TypeUID ^ _xmm[0];
      LODWORD(vec.x) = LODWORD(v3[2].m_SafePointerList.mNode.mNext) ^ _xmm[0];
      v6 = HIDWORD(v3[2].m_SafePointerList.mNode.mNext);
      LODWORD(vec.z) = v5;
      LODWORD(vec.y) = v6 ^ _xmm[0];
    }
    else
    {
      vec = UFG::qVector3::msDirRight;
    }
    *v4 = UFG::TSVector3::AsInstance(&vec);
  }
}

// File Line: 1411
// RVA: 0x4FC870
void __fastcall UFG::TSActor::Mthd_get_dir_left(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *v4 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v3[2].m_SafePointerList.mNode.mNext);
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
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *v4 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v3[2].m_Flags);
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
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi
  int v5; // xmm1_4
  int v6; // xmm0_4
  UFG::qVector3 vec; // [rsp+20h] [rbp-18h]

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      v5 = LODWORD(v3[2].m_pSimObject) ^ _xmm[0];
      LODWORD(vec.x) = *(_DWORD *)&v3[2].m_Flags ^ _xmm[0];
      v6 = *(_DWORD *)(&v3[2].m_SimObjIndex + 1);
      LODWORD(vec.z) = v5;
      LODWORD(vec.y) = v6 ^ _xmm[0];
    }
    else
    {
      vec = UFG::qVector3::msDirDown;
    }
    *v4 = UFG::TSVector3::AsInstance(&vec);
  }
}

// File Line: 1486
// RVA: 0x4FDD90
void __fastcall UFG::TSActor::Mthd_get_pos(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rbx
  SSInstance **v4; // rdi

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
      *v4 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v3[2].m_BoundComponentHandles);
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
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rdi
  UFG::SceneObjectProperties *v5; // rcx
  UFG::qPropertySet *v6; // rbx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      v5 = v3->m_pSceneObj;
      if ( v5 )
      {
        v6 = UFG::SceneObjectProperties::GetWritableProperties(v5);
        UFG::qPropertySet::AddRef(v6);
        *v4 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v6);
      }
    }
  }
}

// File Line: 1523
// RVA: 0x4FB700
void __fastcall UFG::TSActor::Mthd_get_archetype_properties(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rdi
  UFG::qPropertySet *v5; // rbx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      v5 = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(v3->m_pSceneObj);
      UFG::qPropertySet::AddRef(v5);
      *v4 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v5);
    }
  }
}

// File Line: 1539
// RVA: 0x4FF680
void __fastcall UFG::TSActor::Mthd_get_xform(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax
  UFG::TransformNodeComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = &UFG::TransformNodeComponent::sIdentityNode;
    if ( v3 )
      v4 = (UFG::TransformNodeComponent *)v3;
    *ppResult = UFG::TSTransform::AsInstance(v4);
  }
}

// File Line: 1572
// RVA: 0x4FD4E0
void __fastcall UFG::TSActor::Mthd_get_last_teleport_frame(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  unsigned int v4; // ecx
  UFG::SceneObjectProperties *v5; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( v3 )
      v5 = v3->m_pSceneObj;
    else
      v5 = 0i64;
    if ( v5 )
      v4 = v5->mLastTeleportFrame;
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
  }
}

// File Line: 1604
// RVA: 0x50C430
void __fastcall UFG::TSActor::Mthd_teleport_dir(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rbx
  SSData **v4; // r8
  float v5; // xmm2_4
  float *v6; // r10
  unsigned __int64 v7; // r9
  float *v8; // rax
  float v9; // xmm4_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm11_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm12_4
  __m128 v18; // xmm13
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
  __m128 v38; // xmm3
  float v39; // xmm10_4
  __m128 v40; // xmm9
  float v41; // xmm8_4
  __m128 v42; // xmm11
  float v43; // xmm1_4
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-D8h]
  float v45; // [rsp+60h] [rbp-98h]
  float v46; // [rsp+64h] [rbp-94h]
  float v47; // [rsp+68h] [rbp-90h]
  float v48; // [rsp+6Ch] [rbp-8Ch]
  int v49; // [rsp+70h] [rbp-88h]
  float v50; // [rsp+74h] [rbp-84h]
  float v51; // [rsp+78h] [rbp-80h]
  float v52; // [rsp+7Ch] [rbp-7Ch]
  float v53; // [rsp+80h] [rbp-78h]
  float v54; // [rsp+84h] [rbp-74h]
  float v55; // [rsp+88h] [rbp-70h]
  float v56; // [rsp+8Ch] [rbp-6Ch]
  float v57; // [rsp+90h] [rbp-68h]
  float v58; // [rsp+94h] [rbp-64h]

  v3 = this;
  if ( this->mpSimObj.m_pPointer )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = 0.0;
    v6 = (float *)(*v4)->i_data_p->i_user_data;
    v7 = v4[1]->i_data_p->i_user_data;
    v8 = (float *)v4[2]->i_data_p->i_user_data;
    v9 = *(float *)v7;
    if ( *(float *)v7 != 0.0 || 0.0 != *(float *)(v7 + 4) || 0.0 != *(float *)(v7 + 8) )
    {
      v23 = (__m128)*(unsigned int *)(v7 + 4);
      v24 = *(float *)(v7 + 8);
      v10 = *(float *)&FLOAT_1_0;
      v25 = v23;
      v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v9 * v9)) + (float)(v24 * v24);
      if ( v25.m128_f32[0] == 0.0 )
        v26 = 0.0;
      else
        v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
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
        v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
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
        LODWORD(v37) = (unsigned __int128)_mm_sqrt_ps(v36);
        v38 = (__m128)(unsigned int)FLOAT_1_0;
        v38.m128_f32[0] = 1.0 / v37;
      }
      v18 = v38;
      v18.m128_f32[0] = v38.m128_f32[0] * v34;
      v17 = v38.m128_f32[0] * v29.m128_f32[0];
      dest.v1.z = v38.m128_f32[0] * v35;
      v40 = v18;
      dest.v1.w = 0.0;
      dest.v1.x = v38.m128_f32[0] * v34;
      dest.v1.y = v17;
      v39 = (float)((float)(v38.m128_f32[0] * v35) * v21) - (float)(v17 * v20);
      v40.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v34) * v20) - (float)((float)(v38.m128_f32[0] * v35) * v22);
      v42 = v40;
      v41 = (float)(v17 * v22) - (float)(v18.m128_f32[0] * v21);
      v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42.m128_f32[0] == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
      dest.v2.w = 0.0;
      v16 = v39 * v43;
      v15 = v40.m128_f32[0] * v43;
      dest.v2.x = v16;
      dest.v2.y = v15;
      v14 = v41 * v43;
      dest.v2.z = v14;
      v12 = v6[1];
      v11 = v6[2];
      v13 = *v6;
      dest.v3.y = v6[1];
      dest.v3.z = v11;
      dest.v3.x = v13;
      LODWORD(dest.v3.w) = (_DWORD)FLOAT_1_0;
    }
    else
    {
      UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)(*v4)->i_data_p->i_user_data);
      v10 = dest.v3.w;
      v11 = dest.v3.z;
      v12 = dest.v3.y;
      v13 = dest.v3.x;
      v5 = dest.v2.w;
      v14 = dest.v2.z;
      v15 = dest.v2.y;
      v16 = dest.v2.x;
      v17 = dest.v1.y;
      v18.m128_i32[0] = LODWORD(dest.v1.x);
      v19 = dest.v0.w;
      v20 = dest.v0.z;
      v21 = dest.v0.y;
      v22 = dest.v0.x;
    }
    v45 = v22;
    v46 = v21;
    v47 = v20;
    v48 = v19;
    v49 = v18.m128_i32[0];
    v50 = v17;
    v51 = v16;
    v52 = v15;
    v53 = v14;
    v54 = v5;
    v55 = v13;
    v56 = v12;
    v57 = v11;
    v58 = v10;
    UFG::TSActor::TeleportToTransform(v3, (UFG::qMatrix44 *)&v45);
  }
}

// File Line: 1635
// RVA: 0x50CBE0
void __fastcall UFG::TSActor::Mthd_teleport_pos(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rbx
  SSData **v4; // r8
  float v5; // xmm2_4
  float *v6; // r10
  float *v7; // r9
  float *v8; // rax
  __m128 v9; // xmm5
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm13_4
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
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-D8h]
  int v45; // [rsp+60h] [rbp-98h]
  float v46; // [rsp+64h] [rbp-94h]
  int v47; // [rsp+68h] [rbp-90h]
  float v48; // [rsp+6Ch] [rbp-8Ch]
  int v49; // [rsp+70h] [rbp-88h]
  float v50; // [rsp+74h] [rbp-84h]
  float v51; // [rsp+78h] [rbp-80h]
  float v52; // [rsp+7Ch] [rbp-7Ch]
  float v53; // [rsp+80h] [rbp-78h]
  float v54; // [rsp+84h] [rbp-74h]
  float v55; // [rsp+88h] [rbp-70h]
  float v56; // [rsp+8Ch] [rbp-6Ch]
  float v57; // [rsp+90h] [rbp-68h]
  float v58; // [rsp+94h] [rbp-64h]

  v3 = this;
  if ( this->mpSimObj.m_pPointer )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = 0.0;
    v6 = (float *)(*v4)->i_data_p->i_user_data;
    v7 = (float *)v4[1]->i_data_p->i_user_data;
    v8 = (float *)v4[2]->i_data_p->i_user_data;
    v9 = (__m128)*(unsigned int *)v7;
    if ( (v9.m128_f32[0] != 0.0 || 0.0 != v7[1] || 0.0 != v7[2])
      && (*v6 != v9.m128_f32[0] || v7[1] != v6[1] || v7[2] != v6[2]) )
    {
      v20 = *((unsigned int *)v7 + 2);
      v10 = *(float *)&FLOAT_1_0;
      v23 = v7[1] - v6[1];
      *(float *)&v20 = *(float *)&v20 - v6[2];
      v9.m128_f32[0] = v9.m128_f32[0] - *v6;
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
        *(float *)&v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
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
        v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
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
        v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
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
        v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
      dest.v2.w = 0.0;
      v16 = v39 * v43;
      v15 = v40.m128_f32[0] * v43;
      dest.v2.x = v16;
      dest.v2.y = v15;
      v14 = v41 * v43;
      dest.v2.z = v14;
      v12 = v6[1];
      v11 = v6[2];
      v13 = *v6;
      dest.v3.y = v6[1];
      dest.v3.z = v11;
      dest.v3.x = v13;
      LODWORD(dest.v3.w) = (_DWORD)FLOAT_1_0;
    }
    else
    {
      UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)(*v4)->i_data_p->i_user_data);
      v10 = dest.v3.w;
      v11 = dest.v3.z;
      v12 = dest.v3.y;
      v13 = dest.v3.x;
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
    v45 = v22;
    v46 = v21;
    v47 = v20;
    v48 = v19;
    v49 = v18;
    v50 = v17;
    v51 = v16;
    v52 = v15;
    v53 = v14;
    v54 = v5;
    v55 = v13;
    v56 = v12;
    v57 = v11;
    v58 = v10;
    UFG::TSActor::TeleportToTransform(v3, (UFG::qMatrix44 *)&v45);
  }
}

// File Line: 1666
// RVA: 0x50D410
void __fastcall UFG::TSActor::Mthd_teleport_pos_preserve_vel(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rbx
  SSData **v4; // r8
  float v5; // xmm2_4
  float *v6; // r10
  float *v7; // r9
  float *v8; // rax
  __m128 v9; // xmm5
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm13_4
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
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-D8h]
  int v45; // [rsp+60h] [rbp-98h]
  float v46; // [rsp+64h] [rbp-94h]
  int v47; // [rsp+68h] [rbp-90h]
  float v48; // [rsp+6Ch] [rbp-8Ch]
  int v49; // [rsp+70h] [rbp-88h]
  float v50; // [rsp+74h] [rbp-84h]
  float v51; // [rsp+78h] [rbp-80h]
  float v52; // [rsp+7Ch] [rbp-7Ch]
  float v53; // [rsp+80h] [rbp-78h]
  float v54; // [rsp+84h] [rbp-74h]
  float v55; // [rsp+88h] [rbp-70h]
  float v56; // [rsp+8Ch] [rbp-6Ch]
  float v57; // [rsp+90h] [rbp-68h]
  float v58; // [rsp+94h] [rbp-64h]

  v3 = this;
  if ( this->mpSimObj.m_pPointer )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = 0.0;
    v6 = (float *)(*v4)->i_data_p->i_user_data;
    v7 = (float *)v4[1]->i_data_p->i_user_data;
    v8 = (float *)v4[2]->i_data_p->i_user_data;
    v9 = (__m128)*(unsigned int *)v7;
    if ( (v9.m128_f32[0] != 0.0 || 0.0 != v7[1] || 0.0 != v7[2])
      && (*v6 != v9.m128_f32[0] || v7[1] != v6[1] || v7[2] != v6[2]) )
    {
      v20 = *((unsigned int *)v7 + 2);
      v10 = *(float *)&FLOAT_1_0;
      v23 = v7[1] - v6[1];
      *(float *)&v20 = *(float *)&v20 - v6[2];
      v9.m128_f32[0] = v9.m128_f32[0] - *v6;
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
        *(float *)&v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
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
        v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
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
        v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
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
        v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
      dest.v2.w = 0.0;
      v16 = v39 * v43;
      v15 = v40.m128_f32[0] * v43;
      dest.v2.x = v16;
      dest.v2.y = v15;
      v14 = v41 * v43;
      dest.v2.z = v14;
      v12 = v6[1];
      v11 = v6[2];
      v13 = *v6;
      dest.v3.y = v6[1];
      dest.v3.z = v11;
      dest.v3.x = v13;
      LODWORD(dest.v3.w) = (_DWORD)FLOAT_1_0;
    }
    else
    {
      UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)(*v4)->i_data_p->i_user_data);
      v10 = dest.v3.w;
      v11 = dest.v3.z;
      v12 = dest.v3.y;
      v13 = dest.v3.x;
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
    v45 = v22;
    v46 = v21;
    v47 = v20;
    v48 = v19;
    v49 = v18;
    v50 = v17;
    v51 = v16;
    v52 = v15;
    v53 = v14;
    v54 = v5;
    v55 = v13;
    v56 = v12;
    v57 = v11;
    v58 = v10;
    UFG::TSActor::TeleportToTransformPreserveVel(v3, (UFG::qMatrix44 *)&v45);
  }
}

// File Line: 1697
// RVA: 0x50D880
void __fastcall UFG::TSActor::Mthd_teleport_xform(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rdi
  SSData **v4; // r8
  SSData *v5; // rax
  unsigned __int64 v6; // rbx
  int v7; // xmm1_4
  int v8; // xmm0_4
  int v9; // xmm1_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  _DWORD *v22; // rbx
  int v23; // xmm2_4
  int v24; // xmm3_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  int v27; // xmm2_4
  int v28; // xmm3_4
  int v29; // xmm2_4
  int v30; // xmm3_4
  int v31; // xmm0_4
  int v32; // xmm2_4
  int v33; // xmm3_4
  int v34; // xmm0_4
  int v35; // [rsp+20h] [rbp-40h]
  int v36; // [rsp+24h] [rbp-3Ch]
  int v37; // [rsp+28h] [rbp-38h]
  int v38; // [rsp+2Ch] [rbp-34h]
  int v39; // [rsp+30h] [rbp-30h]
  int v40; // [rsp+34h] [rbp-2Ch]
  int v41; // [rsp+38h] [rbp-28h]
  int v42; // [rsp+3Ch] [rbp-24h]
  int v43; // [rsp+40h] [rbp-20h]
  int v44; // [rsp+44h] [rbp-1Ch]
  int v45; // [rsp+48h] [rbp-18h]
  int v46; // [rsp+4Ch] [rbp-14h]
  int v47; // [rsp+50h] [rbp-10h]
  int v48; // [rsp+54h] [rbp-Ch]
  int v49; // [rsp+58h] [rbp-8h]
  int v50; // [rsp+5Ch] [rbp-4h]

  v3 = this;
  if ( this->mpSimObj.m_pPointer )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = *v4;
    if ( v4[1]->i_data_p->i_user_data )
    {
      v22 = (_DWORD *)v5->i_data_p->i_user_data;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->i_data_p->i_user_data);
      v23 = v22[34];
      v24 = v22[35];
      v25 = v22[32];
      v36 = v22[33];
      v37 = v23;
      v35 = v25;
      v38 = v24;
      v26 = v22[37];
      v27 = v22[38];
      v28 = v22[39];
      v39 = v22[36];
      v40 = v26;
      v41 = v27;
      v42 = v28;
      v29 = v22[42];
      v30 = v22[43];
      v31 = v22[40];
      v44 = v22[41];
      v43 = v31;
      v45 = v29;
      v46 = v30;
      v32 = v22[46];
      v33 = v22[47];
      v34 = v22[44];
      v48 = v22[45];
      v49 = v32;
      v47 = v34;
      v50 = v33;
      UFG::TSActor::TeleportToTransform(v3, (UFG::qMatrix44 *)&v35);
    }
    else
    {
      v6 = v5->i_data_p->i_user_data;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
      v7 = *(_DWORD *)(v6 + 132);
      v35 = *(_DWORD *)(v6 + 128);
      v8 = *(_DWORD *)(v6 + 136);
      v36 = v7;
      v9 = *(_DWORD *)(v6 + 140);
      v37 = v8;
      v10 = *(_DWORD *)(v6 + 144);
      v38 = v9;
      v11 = *(_DWORD *)(v6 + 148);
      v39 = v10;
      v12 = *(_DWORD *)(v6 + 152);
      v40 = v11;
      v13 = *(_DWORD *)(v6 + 156);
      v41 = v12;
      v14 = *(_DWORD *)(v6 + 160);
      v42 = v13;
      v15 = *(_DWORD *)(v6 + 164);
      v43 = v14;
      v16 = *(_DWORD *)(v6 + 168);
      v44 = v15;
      v17 = *(_DWORD *)(v6 + 172);
      v45 = v16;
      v18 = *(_DWORD *)(v6 + 176);
      v46 = v17;
      v19 = *(_DWORD *)(v6 + 180);
      v47 = v18;
      v20 = *(_DWORD *)(v6 + 184);
      v48 = v19;
      v21 = *(_DWORD *)(v6 + 188);
      v49 = v20;
      v50 = v21;
      UFG::TSActor::TeleportToTransformRaw(v3, (UFG::qMatrix44 *)&v35);
    }
  }
}

// File Line: 1719
// RVA: 0x50DCA0
void __fastcall UFG::TSActor::Mthd_teleport_xform_preserve_vel(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rdi
  unsigned __int64 v4; // rbx
  int v5; // xmm1_4
  int v6; // xmm0_4
  int v7; // xmm1_4
  int v8; // xmm0_4
  int v9; // xmm1_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // [rsp+20h] [rbp-48h]
  int v21; // [rsp+24h] [rbp-44h]
  int v22; // [rsp+28h] [rbp-40h]
  int v23; // [rsp+2Ch] [rbp-3Ch]
  int v24; // [rsp+30h] [rbp-38h]
  int v25; // [rsp+34h] [rbp-34h]
  int v26; // [rsp+38h] [rbp-30h]
  int v27; // [rsp+3Ch] [rbp-2Ch]
  int v28; // [rsp+40h] [rbp-28h]
  int v29; // [rsp+44h] [rbp-24h]
  int v30; // [rsp+48h] [rbp-20h]
  int v31; // [rsp+4Ch] [rbp-1Ch]
  int v32; // [rsp+50h] [rbp-18h]
  int v33; // [rsp+54h] [rbp-14h]
  int v34; // [rsp+58h] [rbp-10h]
  int v35; // [rsp+5Ch] [rbp-Ch]

  v3 = this;
  if ( this->mpSimObj.m_pPointer )
  {
    v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v5 = *(_DWORD *)(v4 + 132);
    v20 = *(_DWORD *)(v4 + 128);
    v6 = *(_DWORD *)(v4 + 136);
    v21 = v5;
    v7 = *(_DWORD *)(v4 + 140);
    v22 = v6;
    v8 = *(_DWORD *)(v4 + 144);
    v23 = v7;
    v9 = *(_DWORD *)(v4 + 148);
    v24 = v8;
    v10 = *(_DWORD *)(v4 + 152);
    v25 = v9;
    v11 = *(_DWORD *)(v4 + 156);
    v26 = v10;
    v12 = *(_DWORD *)(v4 + 160);
    v27 = v11;
    v13 = *(_DWORD *)(v4 + 164);
    v28 = v12;
    v14 = *(_DWORD *)(v4 + 168);
    v29 = v13;
    v15 = *(_DWORD *)(v4 + 172);
    v30 = v14;
    v16 = *(_DWORD *)(v4 + 176);
    v31 = v15;
    v17 = *(_DWORD *)(v4 + 180);
    v32 = v16;
    v18 = *(_DWORD *)(v4 + 184);
    v33 = v17;
    v19 = *(_DWORD *)(v4 + 188);
    v34 = v18;
    v35 = v19;
    UFG::TSActor::TeleportToTransformPreserveVel(v3, (UFG::qMatrix44 *)&v20);
  }
}

// File Line: 1732
// RVA: 0x5068B0
void __fastcall UFG::TSActor::Mthd_reset_follow_camera(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( v4 )
      {
        v5 = UFG::SimObject::GetComponentOfType(v4, UFG::FollowCameraComponent::_TypeUID);
        if ( v5 )
          v5->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)v3);
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
  UFG::TSActor *v3; // rax
  UFG::SimObject *v4; // rcx
  bool v5; // dl
  SSInstance **v6; // rbx

  if ( ppResult )
  {
    v3 = this;
    v4 = this->mpSimObj.m_pPointer;
    v5 = 0;
    v6 = ppResult;
    if ( v4 )
    {
      if ( !(v3->i_actor_flags & 0x10000) )
        v5 = UFG::IsHighlightSimObject(v4);
    }
    *v6 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 1797
// RVA: 0x508AA0
void __fastcall UFG::TSActor::Mthd_set_is_highlighted(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  UFG::RadarSystem *v4; // rax
  UFG::RadarSystem *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    {
      v4 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::AddRimLight(v4, v3);
    }
    else
    {
      v5 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::RemoveRimLight(v5, v3);
    }
  }
}

// File Line: 1939
// RVA: 0x504CC0
void __fastcall UFG::TSActor::Mthd_minimap_add_blip(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSData **v4; // r9

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = pScope->i_data.i_array_p;
    UFG::SimObjectUtility::AttachHudSymbol(
      v3,
      *(const char **)(*v4)->i_data_p->i_user_data,
      v4[1]->i_data_p->i_user_data != 0,
      *(float *)&v4[2]->i_data_p->i_user_data,
      *(const char **)v4[3]->i_data_p->i_user_data);
  }
}

// File Line: 1956
// RVA: 0x504D20
void __fastcall UFG::TSActor::Mthd_minimap_remove_blip(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(this->mpSimObj.m_pPointer, 0i64, UFG::SimObjectUtility::DetachHudSymbol);
}

// File Line: 1971
// RVA: 0x4F5B60
void __fastcall UFG::TSActor::Mthd_audio_event(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // rbx
  SSInstance *v4; // rsi
  unsigned __int16 v5; // cx
  UFG::ActorAudioComponent *v6; // rax
  UFG::ActorAudioComponent *v7; // rdi
  unsigned int v8; // eax
  unsigned int v9; // esi
  UFG::AudioEntity *v10; // rcx
  unsigned int v11; // edx
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax

  v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v4 = (*pScope->i_data.i_array_p)->i_data_p;
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v7 = v6;
    v8 = UFG::TiDo::CalcWwiseUid(*(const char **)v4->i_user_data);
    v9 = v8;
    if ( v7 )
    {
      v10 = v7->m_SFXEntity;
      if ( v10 )
      {
        v11 = v8;
LABEL_26:
        UFG::AudioEntity::CreateAndPlayEvent(v10, v11, 0i64, 0, 0i64);
        return;
      }
    }
    v12 = v3->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = v3->m_Components.p[40].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v3->vfptr,
                UFG::HkAudioEntityComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v3->vfptr,
                UFG::HkAudioEntityComponent::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HkAudioEntityComponent::_TypeUID);
      }
    }
    else
    {
      v13 = v3->m_Components.p[28].m_pComponent;
    }
    if ( v13 )
    {
      v10 = (UFG::AudioEntity *)&v13[1];
      v11 = v9;
      goto LABEL_26;
    }
  }
}

// File Line: 2004
// RVA: 0x4DA430
bool __fastcall UFG::TSActor::Coro_audio_event(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectGame *v2; // r8
  UFG::TSActor *v3; // rdi
  SSInstance *v4; // rsi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // eax
  bool result; // al
  UFG::AudioEvent *v10; // rax

  v2 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v3 = this;
  if ( !v2 || this->i_actor_flags & 0x10000 )
    return 1;
  if ( pScope->i_update_count )
  {
    v10 = this->m_audioController.m_pEvent;
    if ( v10 )
      result = ((*((_BYTE *)v10 + 144) >> 6) & 1) == 0;
    else
      result = 1;
  }
  else
  {
    v4 = (*pScope->i_data.i_array_p)->i_data_p;
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v2->m_Components.p[40].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HkAudioEntityComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HkAudioEntityComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HkAudioEntityComponent::_TypeUID);
      }
      v6 = v7;
    }
    else
    {
      v6 = v2->m_Components.p[28].m_pComponent;
    }
    if ( v6 )
    {
      v8 = UFG::TiDo::CalcWwiseUid(*(const char **)v4->i_user_data);
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v6[1], v8, &v3->m_audioController, 0i64, 0, 0i64);
    }
    result = 0;
  }
  return result;
}

// File Line: 2040
// RVA: 0x4F5D80
void __fastcall UFG::TSActor::Mthd_audio_override_tagged_dialogue(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimComponent *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID);
    if ( v5 )
      LOBYTE(v5[8].m_pSimObject) ^= (LOBYTE(v5[8].m_pSimObject) ^ 8
                                                                * ((*v4->i_data.i_array_p)->i_data_p->i_user_data == 0)) & 8;
  }
}

// File Line: 2054
// RVA: 0x4F5D20
void __fastcall UFG::TSActor::Mthd_audio_force_init(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimComponent *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID);
    if ( v5 )
    {
      if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
        LOBYTE(v5[8].m_pSimObject) |= 0x40u;
      else
        LOBYTE(v5[8].m_pSimObject) &= 0xBFu;
    }
  }
}

// File Line: 2072
// RVA: 0x4F5CC0
void __fastcall UFG::TSActor::Mthd_audio_force_disable(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimComponent *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID);
    if ( v5 )
    {
      if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
        LOBYTE(v5[8].m_pSimObject) |= 0x80u;
      else
        LOBYTE(v5[8].m_pSimObject) &= 0x7Fu;
    }
  }
}

// File Line: 2089
// RVA: 0x4F5DD0
void __fastcall UFG::TSActor::Mthd_audio_set_obstruction_occlusion(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInvokedMethod *v4; // rdi
  UFG::SimComponent *v5; // rbx
  SSData **v6; // rdx
  SSInstance *v7; // rax
  float v8; // xmm1_4

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID);
    if ( v5 )
    {
      v6 = v4->i_data.i_array_p;
      v7 = v6[1]->i_data_p;
      v8 = *(float *)&(*v6)->i_data_p->i_user_data;
      if ( v8 >= 0.0 || *(float *)&v7->i_user_data >= 0.0 )
      {
        UFG::AudioEntity::SetObstructionAndOcclusionTargets(
          (UFG::AudioEntity *)&v5[1],
          v8,
          *(float *)&v7->i_user_data,
          0);
        BYTE5(v5[5].m_pSimObject) = 1;
      }
      else
      {
        BYTE5(v5[5].m_pSimObject) = 0;
        BYTE3(v5[5].m_pSimObject) = 1;
      }
    }
  }
}

// File Line: 2116
// RVA: 0x507EE0
void __fastcall UFG::TSActor::Mthd_set_facial_emotion(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::ActiveAIEntityComponent *v6; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    if ( v6 )
    {
      if ( (*v4->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
        v6->m_FacialEmotion = (*v4->i_data.i_array_p)->i_data_p->i_user_data;
    }
  }
}

// File Line: 2135
// RVA: 0x4DECD0
_BOOL8 __fastcall UFG::TSActor::Coro_wait_until_done_speaking(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *v2; // rcx
  SSInvokedCoroutine *v3; // rdi
  bool v4; // bl
  UFG::SimComponent *v5; // rax
  bool v6; // zf
  char v7; // al
  _BOOL8 result; // rax

  v2 = this->mpSimObj.m_pPointer;
  v3 = pScope;
  v4 = 1;
  if ( v2 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v2, UFG::ActorAudioComponent::_TypeUID);
    if ( v5 )
    {
      if ( SHIDWORD(v5[6].m_BoundComponentHandles.mNode.mNext) <= 0
        || (v6 = v5[6].m_SafePointerList.mNode.mNext == 0i64, v7 = 1, v6) )
      {
        v7 = 0;
      }
      v4 = v7 == 0;
    }
  }
  result = v4;
  if ( v3->i_update_count <= 2 )
    result = 0i64;
  return result;
}

// File Line: 2151
// RVA: 0x4DED40
bool __fastcall UFG::TSActor::Coro_wait_until_fight_over(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSData **v2; // r8
  int v3; // ebp
  signed int v4; // edi
  SSList *v5; // r15
  SSInstance *v6; // r13
  signed int v7; // er14
  bool v8; // r12
  __int64 v9; // rbx
  SSInstance *v10; // rsi
  UFG::SimObject *v11; // rcx
  SSObjectBaseVtbl *v12; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = 0;
  v4 = 0;
  v5 = (SSList *)(*v2)->i_data_p->i_user_data;
  v6 = v2[2]->i_data_p;
  v7 = v5->i_items.i_count;
  v8 = v2[3]->i_data_p->i_user_data != 0;
  if ( (signed int)v5->i_items.i_count > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v5->i_items.i_array_p[v9];
      if ( HIDWORD(v10[1].i_class_p) & 0x10000
        || (v11 = *(UFG::SimObject **)&v10[4].i_ref_count) == 0i64
        || UFG::IsKnockedOut(v11)
        || (v12 = v10[8].vfptr) == 0i64
        || (_QWORD)v12[32].get_scope_context & 0x20 )
      {
        if ( v8 )
        {
          SSList::remove(v5, v10, 1);
          --v7;
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
    while ( v4 < v7 );
  }
  return v3 <= SLODWORD(v6->i_user_data);
}

// File Line: 2268
// RVA: 0x4DA380
char __fastcall UFG::TSActor::Coro_audio_dialogue_external_filename(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // rdi
  bool v3; // bl
  UFG::ActorAudioComponent *v4; // rsi
  SSData **v5; // rdx
  const char *v6; // rbx
  unsigned int v7; // eax

  v2 = pScope;
  v3 = 1;
  if ( pScope->i_update_count )
    return v3;
  if ( this->mpSimObj.m_pPointer && !(this->i_actor_flags & 0x10000) )
  {
    v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                       this->mpSimObj.m_pPointer,
                                       UFG::ActorAudioComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      v6 = *(const char **)v5[1]->i_data_p->i_user_data;
      v7 = UFG::TiDo::CalcWwiseUid(*(const char **)(*v5)->i_data_p->i_user_data);
      v3 = UFG::ActorAudioComponent::QueueSpeechExternalMission(v4, v7, v6, 0i64, 5u, 0) == 0;
    }
    return v3;
  }
  return 1;
}

// File Line: 2302
// RVA: 0x4DA280
char __fastcall UFG::TSActor::Coro_audio_dialogue_external_context(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // rdi
  bool v3; // bl
  UFG::ActorAudioComponent *v4; // rsi
  SSData **v5; // rdx
  SSInstance *v6; // rdi
  const char *v7; // rbx
  unsigned int v8; // eax
  char v9; // al
  UFG::SimObject *v11; // rcx
  UFG::SimComponent *v12; // rax

  v2 = pScope;
  v3 = 1;
  if ( pScope->i_update_count )
  {
    v11 = this->mpSimObj.m_pPointer;
    if ( !v11 )
      return v3;
    v12 = UFG::SimObject::GetComponentOfType(v11, UFG::ActorAudioComponent::_TypeUID);
    if ( !v12 )
      return v3;
    v9 = SHIDWORD(v12[6].m_BoundComponentHandles.mNode.mNext) > 0 && v12[6].m_SafePointerList.mNode.mNext;
    goto LABEL_13;
  }
  if ( !this->mpSimObj.m_pPointer || this->i_actor_flags & 0x10000 )
    return 1;
  v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                     this->mpSimObj.m_pPointer,
                                     UFG::ActorAudioComponent::_TypeUID);
  if ( v4 )
  {
    v5 = v2->i_data.i_array_p;
    v6 = v5[2]->i_data_p;
    v7 = *(const char **)v5[1]->i_data_p->i_user_data;
    v8 = UFG::TiDo::CalcWwiseUid(*(const char **)(*v5)->i_data_p->i_user_data);
    v9 = UFG::ActorAudioComponent::QueueSpeechExternalAmbient(v4, v8, v7, 0i64, v6->i_user_data, 0, 0);
LABEL_13:
    v3 = v9 == 0;
  }
  return v3;
}

// File Line: 2337
// RVA: 0x50C380
void __fastcall UFG::TSActor::Mthd_stop_speech(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::ActorAudioComponent *v4; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID);
    if ( v4 )
      UFG::ActorAudioComponent::StopCurrentlyPlaying(v4, 0);
  }
}

// File Line: 2349
// RVA: 0x50E3E0
void __fastcall UFG::TSActor::Mthd_unmount_facial_animset(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInvokedMethod *v4; // rbx
  unsigned __int16 v5; // r8
  hkgpIndexedMesh::EdgeBarrier *v6; // r8
  UFG::SimComponent *v7; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (hkgpIndexedMesh::EdgeBarrier *)v3->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::DialogueAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
      }
      v6 = (hkgpIndexedMesh::EdgeBarrier *)v7;
    }
    if ( v6 )
      Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        v6,
        *(hkgpIndexedMeshDefinitions::Edge **)(*v4->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2374
// RVA: 0x504A80
void __fastcall UFG::TSActor::Mthd_load_facefx_actor(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInvokedMethod *v4; // rbx
  unsigned __int16 v5; // r8
  AMD_HD3D *v6; // r8
  UFG::SimComponent *v7; // rax
  __int64 v8; // rdx

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (AMD_HD3D *)v3->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::DialogueAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
      }
      v6 = (AMD_HD3D *)v7;
    }
    if ( v6 )
    {
      v8 = *(_QWORD *)(*v4->i_data.i_array_p)->i_data_p->i_user_data;
      _(v6);
    }
  }
}

// File Line: 2387
// RVA: 0x505D50
void __fastcall UFG::TSActor::Mthd_play_facial_anim(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInvokedMethod *v4; // rbx
  unsigned __int16 v5; // r8
  hkgpIndexedMesh::EdgeBarrier *v6; // r9
  UFG::SimComponent *v7; // rax
  SSData **v8; // rdx
  __int64 v9; // r8

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (hkgpIndexedMesh::EdgeBarrier *)v3->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::DialogueAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
      }
      v6 = (hkgpIndexedMesh::EdgeBarrier *)v7;
    }
    if ( v6 )
    {
      v8 = v4->i_data.i_array_p;
      v9 = *(_QWORD *)v8[1]->i_data_p->i_user_data;
      Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        v6,
        *(hkgpIndexedMeshDefinitions::Edge **)(*v8)->i_data_p->i_user_data);
    }
  }
}

// File Line: 2401
// RVA: 0x50E310
void __fastcall UFG::TSActor::Mthd_unload_facefx_actor(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // r8
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[41].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::DialogueAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
    }
    if ( v5 )
      _((AMD_HD3D *)v5);
  }
}

// File Line: 2415
// RVA: 0x4FD0B0
void __fastcall UFG::TSActor::Mthd_get_health(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  unsigned int v4; // xmm6_4
  SSInstance **v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rcx

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = (unsigned int)FLOAT_1_0;
    v5 = ppResult;
    if ( v3 )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
      }
      if ( v7 )
      {
        v8 = v7[6].vfptr;
        if ( v8 )
          v4 = HIDWORD(v8[33].__vecDelDtor);
      }
    }
    *v5 = SSInstance::pool_new(SSBrain::c_real_class_p, v4);
  }
}

// File Line: 2440
// RVA: 0x4FDBF0
void __fastcall UFG::TSActor::Mthd_get_owner(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::SimObjectGame *v4; // r9
  unsigned __int16 v5; // cx
  UFG::InventoryItemComponent *v6; // rax
  UFG::SimObject *v7; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( !(this->i_actor_flags & 0x10000) )
      {
        v5 = v4->m_Flags;
        if ( !((v5 >> 14) & 1) && (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
          {
            v6 = (UFG::InventoryItemComponent *)v4->m_Components.p[11].m_pComponent;
          }
          else if ( (v5 >> 12) & 1 )
          {
            v6 = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v4,
                                                  UFG::InventoryItemComponent::_TypeUID);
          }
          else
          {
            v6 = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v4->vfptr,
                                                  UFG::InventoryItemComponent::_TypeUID);
          }
          if ( v6 )
          {
            v7 = UFG::InventoryItemComponent::GetOwnerSimObject(v6);
            if ( v7 )
              *v3 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v7);
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
  UFG::SimObjectGame *v3; // rbx
  SSInvokedMethod *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[8].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::MissionFailConditionComponent::_TypeUID);
      }
    }
    else
    {
      v6 = v3->m_Components.p[8].m_pComponent;
    }
    if ( v6 )
      UFG::MissionFailConditionComponent::SetFailTrigger(
        (UFG::SimObject *)&v3->vfptr,
        (UFG::qSymbol *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data,
        *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
  }
}

// File Line: 2484
// RVA: 0x5080C0
void __fastcall UFG::TSActor::Mthd_set_fail_threshold(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rbx
  SSInvokedMethod *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[8].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::MissionFailConditionComponent::_TypeUID);
      }
    }
    else
    {
      v6 = v3->m_Components.p[8].m_pComponent;
    }
    if ( v6 )
      UFG::MissionFailConditionComponent::SetFailThreshold(
        (UFG::SimObject *)&v3->vfptr,
        (UFG::qSymbol *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data,
        *(float *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64));
  }
}

// File Line: 2502
// RVA: 0x507FF0
void __fastcall UFG::TSActor::Mthd_set_fail_caption(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rbx
  SSInvokedMethod *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[8].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::MissionFailConditionComponent::_TypeUID);
      }
    }
    else
    {
      v6 = v3->m_Components.p[8].m_pComponent;
    }
    if ( v6 )
      UFG::MissionFailConditionComponent::SetFailCaption(
        (UFG::SimObject *)&v3->vfptr,
        (UFG::qSymbol *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64));
  }
}

// File Line: 2526
// RVA: 0x5079F0
void __fastcall UFG::TSActor::Mthd_set_clip_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::GunComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v4->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    if ( v7 )
      UFG::GunComponent::SetClipAmmo(v7, (*v5->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2546
// RVA: 0x4FC1C0
void __fastcall UFG::TSActor::Mthd_get_clip_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned int v5; // ebx
  SSInstance **v6; // rdi
  unsigned __int16 v7; // dx
  UFG::GunComponent *v8; // rax

  if ( ppResult )
  {
    v3 = this;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v5 = 0;
    v6 = ppResult;
    if ( v4 && !(v3->i_actor_flags & 0x10000) )
    {
      v7 = v4->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v4->vfptr,
                                      UFG::GunComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      if ( v8 )
        v5 = UFG::GunComponent::GetClipAmmo(v8);
    }
    *v6 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 2573
// RVA: 0x5086B0
void __fastcall UFG::TSActor::Mthd_set_if_reset_ammo_on_death(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::SimComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    if ( v7 )
      *((_BYTE *)&v7[3].m_SimObjIndex + 2) = (*v5->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2593
// RVA: 0x505950
void __fastcall UFG::TSActor::Mthd_override_rate_of_fire(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::GunComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v4->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    if ( v7 )
      UFG::GunComponent::OverrideRateOfFire(
        v7,
        (*v5->i_data.i_array_p)->i_data_p->i_user_data != 0,
        *(float *)(*(_QWORD *)(*((_QWORD *)v5->i_data.i_array_p + 1) + 8i64) + 32i64));
  }
}

// File Line: 2614
// RVA: 0x4FCD50
void __fastcall UFG::TSActor::Mthd_get_fire_mode(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectProp *v4; // rcx
  SSInstance **v5; // rdi
  unsigned int v6; // ebx
  unsigned __int16 v7; // dx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rax

  v3 = this;
  v4 = (UFG::SimObjectProp *)this->mpSimObj.m_pPointer;
  v5 = ppResult;
  if ( !v4 || v3->i_actor_flags & 0x10000 )
    v4 = 0i64;
  v6 = -1;
  if ( v4 )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v4->vfptr,
                                                        UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v4);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v4->vfptr,
                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v4->vfptr,
                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v4->vfptr,
                                                        UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    if ( v8 )
      v6 = v8->mFireMode;
  }
  *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
}

// File Line: 2638
// RVA: 0x5082D0
void __fastcall UFG::TSActor::Mthd_set_fire_mode(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectProp *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::SimObjectWeaponPropertiesComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectProp *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v4->vfptr,
                                                        UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v4);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v4->vfptr,
                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v4->vfptr,
                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v4->vfptr,
                                                        UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    if ( v7 )
      v7->mFireMode = (*v5->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 2659
// RVA: 0x508CF0
void __fastcall UFG::TSActor::Mthd_set_must_hit_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // rdi
  UFG::SimObjectGame *v4; // rbx
  SSInstance *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v3 = pScope;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v4 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = (*pScope->i_data.i_array_p)->i_data_p;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol.mUID = v5->i_user_data;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v6;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v7 = v4->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::GunComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      v9 = v8;
      if ( v8 )
      {
        UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&v3->vfptr, 0);
        LODWORD(v9[3].m_SafePointerList.mNode.mNext) = pTrackEnumBinding.m_EnumValue;
      }
    }
    v10 = pTrackEnumBinding.mPrev;
    v11 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v11->mPrev = v10;
  }
}

// File Line: 2685
// RVA: 0x4F64C0
void __fastcall UFG::TSActor::Mthd_clear_must_hit_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    if ( v6 )
      LODWORD(v6[3].m_SafePointerList.mNode.mNext) = 0;
  }
}

// File Line: 2705
// RVA: 0x50B120
void __fastcall UFG::TSActor::Mthd_set_triad_wars_player_id(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::TriadWarsComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::TriadWarsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TriadWarsComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::TriadWarsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TriadWarsComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::TriadWarsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TriadWarsComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::TriadWarsComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v4->vfptr,
                                          UFG::TriadWarsComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::TriadWarsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TriadWarsComponent::_TypeUID);
    }
    if ( v7 )
      UFG::TriadWarsComponent::SetOwnerPlayerId(v7, (*v5->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2723
// RVA: 0x4FF530
void __fastcall UFG::TSActor::Mthd_get_weapon_type(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectProp *v4; // rcx
  SSInstance **v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimObjectWeaponPropertiesComponent *v7; // rax
  UFG::FireModeInfo *v8; // rcx
  EnumList<unsigned long> *v9; // rax
  ASymbol *v10; // rax
  ASymbol *v11; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = this;
    v4 = (UFG::SimObjectProp *)this->mpSimObj.m_pPointer;
    v5 = ppResult;
    if ( v4
      && !(v3->i_actor_flags & 0x10000)
      && ((v6 = v4->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) : (v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v4->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v7 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v4))) : (v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v4->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v4->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)),
          v7) )
    {
      v8 = v7->mWeaponTypeInfo->mFireModes[v7->mFireMode];
      if ( (signed int)UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size <= 0 )
        v9 = 0i64;
      else
        v9 = *UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p;
      v10 = (ASymbol *)UFG::qSymbol::create_from_string(&result, v9->m_enumName.p[v8->mSimObjectWeaponType]);
      *v5 = SSSymbol::as_instance(v10);
    }
    else
    {
      v11 = ASymbol::get_null();
      *v5 = SSSymbol::as_instance(v11);
    }
  }
}

// File Line: 2749
// RVA: 0x50B070
void __fastcall UFG::TSActor::Mthd_set_total_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::GunComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v4->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    if ( v7 )
      UFG::GunComponent::SetTotalAmmo(v7, (*v5->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 2770
// RVA: 0x4FF160
void __fastcall UFG::TSActor::Mthd_get_total_ammo(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned int v5; // ebx
  SSInstance **v6; // rdi
  unsigned __int16 v7; // dx
  UFG::GunComponent *v8; // rax

  if ( ppResult )
  {
    v3 = this;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v5 = 0;
    v6 = ppResult;
    if ( v4 && !(v3->i_actor_flags & 0x10000) )
    {
      v7 = v4->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v4->vfptr,
                                      UFG::GunComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      if ( v8 )
        v5 = UFG::GunComponent::GetTotalAmmo(v8);
    }
    *v6 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 2797
// RVA: 0x4F3D70
void __fastcall UFG::TSActor::Mthd_add_clip_to_gun(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::GunComponent *v6; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v4->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GunComponent::_TypeUID);
    }
    if ( v6 )
      UFG::GunComponent::AddClipOfAmmo(v6);
  }
}

// File Line: 2815
// RVA: 0x501D00
void __fastcall UFG::TSActor::Mthd_is_in_view(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  SSInvokedMethod *v4; // r15
  bool v5; // bp
  UFG::SimComponent *v6; // rdi
  UFG::BaseCameraComponent *v7; // rcx
  UFG::Camera *v8; // r14
  UFG::qMatrix44 *v9; // rbx
  UFG::qMatrix44 *v10; // rax
  float v11; // xmm12_4
  float v12; // xmm11_4
  float v13; // xmm10_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // ST24_4
  float v18; // ST2C_4
  float v19; // ST48_4
  float v20; // ST44_4
  float v21; // ST38_4
  float v22; // ST30_4
  float v23; // ST20_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  __m128 v29; // xmm2
  float v30; // xmm0_4
  __m128 v31; // xmm2
  float v32; // xmm8_4
  float v33; // xmm6_4
  UFG::qMatrix44 result; // [rsp+50h] [rbp-118h]
  __int64 v35; // [rsp+90h] [rbp-D8h]
  float v36; // [rsp+180h] [rbp+18h]
  float v37; // [rsp+188h] [rbp+20h]

  if ( ppResult )
  {
    v35 = -2i64;
    v3 = ppResult;
    v4 = pScope;
    v5 = 0;
    v6 = this->mTransformNodeComponent.m_pSimComponent;
    if ( !(_S8_14 & 1) )
      _S8_14 |= 1u;
    if ( UFG::Metrics::msInstance.mSimFrameCount != frustum_frame_number )
    {
      frustum_frame_number = UFG::Metrics::msInstance.mSimFrameCount;
      v7 = UFG::Director::Get()->mCurrentCamera;
      if ( v7 )
        v8 = &v7->mCamera;
      else
        v8 = 0i64;
      v9 = UFG::Camera::GetViewProjection(v8);
      v10 = UFG::Camera::GetWorldView(v8);
      UFG::qMatrix44::operator*(v10, &result, v9);
      LODWORD(v11) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
      LODWORD(v12) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
      LODWORD(v13) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
      LODWORD(v14) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
      LODWORD(v15) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
      LODWORD(v16) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
      LODWORD(v37) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
      LODWORD(v36) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
      LODWORD(v17) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
      LODWORD(v18) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
      LODWORD(v19) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
      LODWORD(v20) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
      LODWORD(v21) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
      LODWORD(v22) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
      LODWORD(v23) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
      v24 = fsqrt(
              (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                    + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
            + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
      frustum_planes[0].x = (float)(1.0 / v24) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
      *(float *)&dword_14240D6E4 = (float)(1.0 / v24) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
      *(float *)&dword_14240D6E8 = (float)(1.0 / v24) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
      *(float *)&dword_14240D6EC = (float)(1.0 / v24) * COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]);
      v25 = fsqrt((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13));
      *(float *)&dword_14240D6F0 = (float)(1.0 / v25) * v11;
      *(float *)&dword_14240D6F4 = (float)(1.0 / v25) * v12;
      *(float *)&dword_14240D6F8 = (float)(1.0 / v25) * v13;
      *(float *)&dword_14240D6FC = (float)(1.0 / v25)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
      v26 = fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16));
      *(float *)&dword_14240D700 = (float)(1.0 / v26) * v14;
      *(float *)&dword_14240D704 = (float)(1.0 / v26) * v15;
      *(float *)&dword_14240D708 = (float)(1.0 / v26) * v16;
      *(float *)&dword_14240D70C = (float)(1.0 / v26)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]);
      v27 = (__m128)LODWORD(v36);
      v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v37 * v37)) + (float)(v17 * v17);
      LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v27);
      *(float *)&dword_14240D710 = (float)(1.0 / v28) * v37;
      *(float *)&dword_14240D714 = (float)(1.0 / v28) * v36;
      *(float *)&dword_14240D718 = (float)(1.0 / v28) * v17;
      *(float *)&dword_14240D71C = (float)(1.0 / v28)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]);
      v29 = (__m128)LODWORD(v19);
      v29.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v18 * v18)) + (float)(v20 * v20);
      LODWORD(v30) = (unsigned __int128)_mm_sqrt_ps(v29);
      *(float *)&dword_14240D720 = (float)(1.0 / v30) * v18;
      *(float *)&dword_14240D724 = (float)(1.0 / v30) * v19;
      *(float *)&dword_14240D728 = (float)(1.0 / v30) * v20;
      *(float *)&dword_14240D72C = (float)(1.0 / v30)
                                 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]);
      v31 = (__m128)LODWORD(v21);
      v31.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v22 * v22)) + (float)(v23 * v23);
      v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
      *(float *)&dword_14240D730 = v32 * v21;
      *(float *)&dword_14240D734 = v32 * v22;
      *(float *)&dword_14240D738 = v32 * v23;
      *(float *)&dword_14240D73C = v32 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]);
    }
    if ( v6 )
    {
      v33 = *(float *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
      v5 = IntersectSphereFrustum(frustum_planes, (UFG::qVector3 *)&v6[2].m_BoundComponentHandles, v33) != 2;
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 2850
// RVA: 0x4D9AE0
char __fastcall UFG::TSActor::Coro_animate(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectGame *v2; // rbx
  SSData **v3; // r8
  SSInstance *v4; // rsi
  bool v5; // r14
  bool v6; // r15
  const char *v7; // rsi
  int v8; // er8
  ActionNode *v9; // rsi
  unsigned __int16 v10; // dx
  UFG::PowerManagementComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::ActionTreeComponent *v13; // rax
  ActionController *v14; // rcx
  bool v15; // bl
  int v16; // edx
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rbx
  UFG::SimComponent *v20; // rax
  const char *v21; // rdx
  ActionPath absolutePath; // [rsp+28h] [rbp-18h]

  v2 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( !v2 || this->i_actor_flags & 0x10000 )
    return 1;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = v3[1]->i_data_p->i_user_data != 0;
  v6 = v3[2]->i_data_p->i_user_data != 0;
  if ( !pScope->i_update_count )
  {
    absolutePath.mPath.mCount = 0;
    absolutePath.mPath.mData.mOffset = 0i64;
    v7 = *(const char **)v4->i_user_data;
    v8 = 0;
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v8 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v8 & 0x80000000;
    ActionPath::Append(&absolutePath, v7);
    v9 = ActionNode::Find(&absolutePath, 0i64);
    if ( v9 )
    {
      v10 = v2->m_Flags;
      if ( (v2->m_Flags >> 14) & 1 )
      {
        v11 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v2,
                                                   UFG::PowerManagementComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v2,
                                                   UFG::PowerManagementComponent::_TypeUID);
        }
        else
        {
          v11 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v2->vfptr,
                                                   UFG::PowerManagementComponent::_TypeUID);
        }
      }
      else
      {
        v11 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
      if ( v11 )
        UFG::PowerManagementComponent::PreventSuspendTemporarily(v11, 10.0);
      v12 = v2->m_Flags;
      if ( (v12 >> 14) & 1 )
      {
        v13 = (UFG::ActionTreeComponent *)v2->m_Components.p[7].m_pComponent;
      }
      else if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
        {
          v13 = (UFG::ActionTreeComponent *)v2->m_Components.p[6].m_pComponent;
        }
        else if ( (v12 >> 12) & 1 )
        {
          v13 = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v2,
                                              UFG::ActionTreeComponent::_TypeUID);
        }
        else
        {
          v13 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v2->vfptr,
                                              UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        v13 = (UFG::ActionTreeComponent *)v2->m_Components.p[7].m_pComponent;
      }
      if ( v13 )
      {
        v14 = &v13->mActionController;
        if ( v6 )
          ActionController::PlayTracks(v14, v9, 0, 0.0);
        else
          ActionController::Play(v14, v9, 0);
      }
    }
    v15 = v5 == 0;
    v16 = absolutePath.mPath.mCount;
    if ( absolutePath.mPath.mCount < 0 )
      return v15;
    if ( absolutePath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        v16 = absolutePath.mPath.mCount;
      }
    }
    goto LABEL_38;
  }
  if ( !v5 )
    return 1;
  v18 = v2->m_Flags;
  if ( (v18 >> 14) & 1 )
  {
    v19 = v2->m_Components.p[7].m_pComponent;
  }
  else if ( (v18 & 0x8000u) == 0 )
  {
    if ( (v18 >> 13) & 1 )
    {
      v19 = v2->m_Components.p[6].m_pComponent;
    }
    else
    {
      v20 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
      v19 = v20;
    }
  }
  else
  {
    v19 = v2->m_Components.p[7].m_pComponent;
  }
  if ( !v19 )
    return 1;
  v21 = *(const char **)v4->i_user_data;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, v21);
  v15 = ActionController::IsPlayingFullPath((ActionController *)&v19[3], &absolutePath, 1) == 0;
  v16 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount < 0 )
    return v15;
  if ( !absolutePath.mPath.mData.mOffset
    || !(UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
  {
LABEL_38:
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v16 & 0x80000000;
    return v15;
  }
  operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  absolutePath.mPath.mData.mOffset = 0i64;
  absolutePath.mPath.mCount &= 0x80000000;
  return v15;
}

// File Line: 2952
// RVA: 0x4F3920
void __fastcall UFG::TSActor::Mthd_action_tree_query(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  SSInvokedMethod *v4; // rbp
  UFG::TSActor *v5; // rax
  bool v6; // si
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  SSInstance *v11; // rax
  const char *v12; // rbp
  int v13; // er8
  ActionNode *v14; // rax
  int v15; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = pScope;
    v5 = this;
    v6 = 0;
    v7 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v7 && !(v5->i_actor_flags & 0x10000) )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v7->m_Components.p[7].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = v7->m_Components.p[6].m_pComponent;
        }
        else
        {
          v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v9 = v10;
        }
      }
      else
      {
        v9 = v7->m_Components.p[7].m_pComponent;
      }
      if ( v9 )
      {
        v11 = (*v4->i_data.i_array_p)->i_data_p;
        absolutePath.mPath.mCount = 0;
        absolutePath.mPath.mData.mOffset = 0i64;
        v12 = *(const char **)v11->i_user_data;
        v13 = 0;
        if ( absolutePath.mPath.mData.mOffset
          && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
        {
          operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
          v13 = absolutePath.mPath.mCount;
        }
        absolutePath.mPath.mData.mOffset = 0i64;
        absolutePath.mPath.mCount = v13 & 0x80000000;
        ActionPath::Append(&absolutePath, v12);
        v14 = ActionNode::Find(&absolutePath, 0i64);
        if ( v14 )
          v6 = ((__int64 (__fastcall *)(ActionNode *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v14->vfptr[2].GetClassNameUID)(
                 v14,
                 v9[2].m_BoundComponentHandles.mNode.mNext) != 0;
        v15 = absolutePath.mPath.mCount;
        if ( absolutePath.mPath.mCount >= 0 )
        {
          if ( absolutePath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
              v15 = absolutePath.mPath.mCount;
            }
          }
          absolutePath.mPath.mData.mOffset = 0i64;
          absolutePath.mPath.mCount = v15 & 0x80000000;
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 2984
// RVA: 0x502F20
void __fastcall UFG::TSActor::Mthd_is_playing_node(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned __int8 v5; // si
  SSInstance **v6; // rdi
  SSInvokedMethod *v7; // rbp
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  ActionID node_id; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = this;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v5 = 0;
    v6 = ppResult;
    v7 = pScope;
    if ( v4 && !(v3->i_actor_flags & 0x10000) )
    {
      v8 = v4->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v4->m_Components.p[7].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = v4->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v8 >> 12) & 1 )
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::ActionTreeComponent::_TypeUID);
          else
            v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v9 = v10;
        }
      }
      else
      {
        v9 = v4->m_Components.p[7].m_pComponent;
      }
      if ( v9 )
      {
        node_id.mUID = UFG::qStringHashUpper32(
                         *(const char **)(*v7->i_data.i_array_p)->i_data_p->i_user_data,
                         0xFFFFFFFF);
        v5 = ActionController::IsPlaying((ActionController *)&v9[3], &node_id, 0xFFFFFFFF, 1);
      }
    }
    *v6 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 3020
// RVA: 0x502B10
void __fastcall UFG::TSActor::Mthd_is_playing_ai_node(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned __int8 v5; // si
  SSInstance **v6; // rdi
  SSInvokedMethod *v7; // rbp
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  ActionID node_id; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = this;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v5 = 0;
    v6 = ppResult;
    v7 = pScope;
    if ( v4 && !(v3->i_actor_flags & 0x10000) )
    {
      v8 = v4->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v4->m_Components.p[19].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIActionTreeComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIActionTreeComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::AIActionTreeComponent::_TypeUID);
        }
        v9 = v10;
      }
      else
      {
        v9 = v4->m_Components.p[19].m_pComponent;
      }
      if ( v9 )
      {
        node_id.mUID = UFG::qStringHashUpper32(
                         *(const char **)(*v7->i_data.i_array_p)->i_data_p->i_user_data,
                         0xFFFFFFFF);
        v5 = ActionController::IsPlaying((ActionController *)&v9[3].m_TypeUID, &node_id, 0xFFFFFFFF, 1);
      }
    }
    *v6 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 3057
// RVA: 0x502D80
void __fastcall UFG::TSActor::Mthd_is_playing_full_path_node(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  SSInvokedMethod *v4; // rbp
  UFG::TSActor *v5; // rax
  bool v6; // si
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  const char *v11; // rdx
  int v12; // edx
  ActionPath animPath; // [rsp+28h] [rbp-20h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = pScope;
    v5 = this;
    v6 = 0;
    v7 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v7 && !(v5->i_actor_flags & 0x10000) )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v7->m_Components.p[7].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = v7->m_Components.p[6].m_pComponent;
        }
        else
        {
          v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v9 = v10;
        }
      }
      else
      {
        v9 = v7->m_Components.p[7].m_pComponent;
      }
      if ( v9 )
      {
        v11 = *(const char **)(*v4->i_data.i_array_p)->i_data_p->i_user_data;
        animPath.mPath.mCount = 0;
        animPath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&animPath, v11);
        v6 = ActionController::IsPlayingFullPath((ActionController *)&v9[3], &animPath, 1);
        v12 = animPath.mPath.mCount;
        if ( animPath.mPath.mCount >= 0 )
        {
          if ( animPath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset);
              v12 = animPath.mPath.mCount;
            }
          }
          animPath.mPath.mData.mOffset = 0i64;
          animPath.mPath.mCount = v12 & 0x80000000;
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 3095
// RVA: 0x502C20
void __fastcall UFG::TSActor::Mthd_is_playing_full_path_ai_node(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  SSInvokedMethod *v4; // rbp
  UFG::TSActor *v5; // rax
  bool v6; // si
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  const char *v11; // rdx
  int v12; // edx
  ActionPath animPath; // [rsp+28h] [rbp-20h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = pScope;
    v5 = this;
    v6 = 0;
    v7 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v7 && !(v5->i_actor_flags & 0x10000) )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v7->m_Components.p[19].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AIActionTreeComponent::_TypeUID);
        else
          v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AIActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AIActionTreeComponent::_TypeUID);
        v9 = v10;
      }
      else
      {
        v9 = v7->m_Components.p[19].m_pComponent;
      }
      if ( v9 )
      {
        v11 = *(const char **)(*v4->i_data.i_array_p)->i_data_p->i_user_data;
        animPath.mPath.mCount = 0;
        animPath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&animPath, v11);
        v6 = ActionController::IsPlayingFullPath((ActionController *)&v9[3].m_TypeUID, &animPath, 1);
        v12 = animPath.mPath.mCount;
        if ( animPath.mPath.mCount >= 0 )
        {
          if ( animPath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset);
              v12 = animPath.mPath.mCount;
            }
          }
          animPath.mPath.mData.mOffset = 0i64;
          animPath.mPath.mCount = v12 & 0x80000000;
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 3134
// RVA: 0x4F7830
void __fastcall UFG::TSActor::Mthd_dbg_get_playing_full_path(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // r14
  UFG::TSActor *v4; // rax
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  const char *v9; // rsi
  signed __int64 v10; // rbx
  unsigned int v11; // eax
  char v12; // di
  AString *v13; // rcx
  AStringRef *v14; // rbx
  bool v15; // zf
  AObjReusePool<AStringRef> *v16; // rax
  AObjBlock<AStringRef> *v17; // rcx
  unsigned __int64 v18; // rdx
  bool v19; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v20; // rcx
  AStringRef *v21; // rbx
  AObjReusePool<AStringRef> *v22; // rax
  AObjBlock<AStringRef> *v23; // rcx
  unsigned __int64 v24; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v25; // rcx
  AString str; // [rsp+70h] [rbp+18h]
  AStringRef *elem; // [rsp+78h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = this;
    v5 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v5
      && !(v4->i_actor_flags & 0x10000)
      && ((v6 = v5->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActionTreeComponent::_TypeUID)) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ActionTreeComponent::_TypeUID))) : (v7 = v5->m_Components.p[6].m_pComponent)) : (v7 = v5->m_Components.p[7].m_pComponent)) : (v7 = v5->m_Components.p[7].m_pComponent),
          v7
       && (v8 = TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)&v7[3]), (v9 = (const char *)v8) != 0i64)) )
    {
      v10 = -1i64;
      do
        ++v10;
      while ( *(_BYTE *)(v8 + v10) );
      v11 = AMemory::c_req_byte_size_func(v10 + 1);
      v12 = 1;
      elem = AStringRef::pool_new(v9, v10, v11, 1u, 0, 1);
      v13 = (AString *)&elem;
    }
    else
    {
      str.i_str_ref_p = AStringRef::get_empty();
      ++str.i_str_ref_p->i_ref_count;
      v13 = &str;
      v12 = 2;
    }
    *v3 = SSString::as_instance(v13);
    if ( v12 & 2 )
    {
      v12 &= 0xFDu;
      v14 = str.i_str_ref_p;
      v15 = str.i_str_ref_p->i_ref_count == 1;
      --v14->i_ref_count;
      if ( v15 )
      {
        if ( v14->i_deallocate )
          AMemory::c_free_func(v14->i_cstr_p);
        v16 = AStringRef::get_pool();
        v17 = v16->i_block_p;
        v18 = (unsigned __int64)v17->i_objects_a;
        if ( (unsigned __int64)v14 < v18
          || (v19 = (unsigned __int64)v14 < v18 + 24i64 * v17->i_size, v20 = &v16->i_pool, !v19) )
        {
          v20 = &v16->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v20, v14);
      }
    }
    if ( v12 & 1 )
    {
      v21 = elem;
      v15 = elem->i_ref_count == 1;
      --v21->i_ref_count;
      if ( v15 )
      {
        if ( v21->i_deallocate )
          AMemory::c_free_func(v21->i_cstr_p);
        v22 = AStringRef::get_pool();
        v23 = v22->i_block_p;
        v24 = (unsigned __int64)v23->i_objects_a;
        if ( (unsigned __int64)v21 < v24
          || (v19 = (unsigned __int64)v21 < v24 + 24i64 * v23->i_size, v25 = &v22->i_pool, !v19) )
        {
          v25 = &v22->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v25, v21);
      }
    }
  }
}

// File Line: 3159
// RVA: 0x506E00
void __fastcall UFG::TSActor::Mthd_set_action_tree_opening_branch(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // rdi
  UFG::TSActor *v4; // rax
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // r8
  UFG::SimComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  SSInstance *v9; // rax
  const char *v10; // rdi
  int v11; // er8
  ActionNode *v12; // rax
  ActionPath absolutePath; // [rsp+28h] [rbp-20h]

  v3 = pScope;
  v4 = this;
  v5 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v5 && !(v4->i_actor_flags & 0x10000) )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[7].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = v5->m_Components.p[6].m_pComponent;
      }
      else
      {
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v7 = v8;
      }
    }
    else
    {
      v7 = v5->m_Components.p[7].m_pComponent;
    }
    if ( v7 )
    {
      v9 = (*v3->i_data.i_array_p)->i_data_p;
      absolutePath.mPath.mCount = 0;
      absolutePath.mPath.mData.mOffset = 0i64;
      v10 = *(const char **)v9->i_user_data;
      v11 = 0;
      absolutePath.mPath.mData.mOffset = 0i64;
      absolutePath.mPath.mCount = v11 & 0x80000000;
      ActionPath::Append(&absolutePath, v10);
      v12 = ActionNode::Find(&absolutePath, 0i64);
      if ( v12 )
        v7[2].m_BoundComponentHandles.mNode.mNext[1].mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v12;
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
void __fastcall UFG::TSActor::Mthd_pwr_suspend_allow(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::PowerManagementComponent *v6; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v4,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v4,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v4,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v4->vfptr,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v4,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    if ( v6 )
      UFG::PowerManagementComponent::AllowSuspend(v6);
  }
}

// File Line: 3216
// RVA: 0x506240
void __fastcall UFG::TSActor::Mthd_pwr_suspend_prevent(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::PowerManagementComponent *v6; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v4,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v4,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v4,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v4->vfptr,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v4,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    if ( v6 )
      UFG::PowerManagementComponent::PreventSuspendIndefinitely(v6);
  }
}

// File Line: 3236
// RVA: 0x50A8C0
void __fastcall UFG::TSActor::Mthd_set_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // rbx
  UFG::TSActor *v4; // rsi
  UFG::qBaseNodeRB *v5; // rdi
  __int64 v6; // rax
  UFG::SimObjectGame *v7; // rbx
  UFG::qSymbol *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  unsigned __int16 v10; // cx
  UFG::TargetingSystemBaseComponent *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v3 = pScope;
  v4 = this;
  v5 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  v6 = *(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64);
  v7 = (UFG::SimObjectGame *)v4->mpSimObj.m_pPointer;
  if ( v7 && !(v4->i_actor_flags & 0x10000) && v5 )
  {
    v8 = UFG::qSymbol::create_from_string(&result, **(const char ***)(v6 + 32));
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v9 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v9;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < NUM_TARGET_TYPES )
    {
      v10 = v7->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = (UFG::TargetingSystemBaseComponent *)v7->m_Components.p[20].m_pComponent;
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v7,
                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v7,
                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v11 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v7->vfptr,
                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
      }
      else
      {
        v11 = (UFG::TargetingSystemBaseComponent *)v7->m_Components.p[20].m_pComponent;
      }
      if ( v11 )
        UFG::TargetingSystemBaseComponent::SetTarget(
          v11,
          (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
          (UFG::SimObject *)v5);
    }
    v12 = pTrackEnumBinding.mPrev;
    v13 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v13->mPrev = v12;
  }
}ackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v13->mPrev = v12

// File Line: 3270
// RVA: 0x4FEDE0
void __fastcall UFG::TSActor::Mthd_get_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::SimObjectGame *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+70h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( !(this->i_actor_flags & 0x10000) )
      {
        v5 = UFG::qSymbol::create_from_string(
               &result,
               *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
        pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
          v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
          pTrackEnumBinding.mPrev = v6;
          pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        }
        if ( pTrackEnumBinding.m_EnumValue < 0x5B )
        {
          v7 = v4->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = v4->m_Components.p[20].m_pComponent;
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else if ( (v7 >> 12) & 1 )
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v9 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&v4->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v8 = v9;
          }
          else
          {
            v8 = v4->m_Components.p[20].m_pComponent;
          }
          if ( v8 )
            *v3 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(*(UFG::SimObject **)(56i64
                                                                                      * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64)
                                                                                      + *(_QWORD *)&v8[1].m_TypeUID
                                                                                      + 40));
        }
        v10 = pTrackEnumBinding.mPrev;
        v11 = pTrackEnumBinding.mNext;
        pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
        v11->mPrev = v10;
      }
    }
  }
}

// File Line: 3308
// RVA: 0x4FEFA0
void __fastcall UFG::TSActor::Mthd_get_target_as_simobject(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::SimObjectGame *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // r8
  UFG::SimComponent *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+70h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v4 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( !(this->i_actor_flags & 0x10000) )
      {
        v5 = UFG::qSymbol::create_from_string(
               &result,
               *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
        pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
          v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
          pTrackEnumBinding.mPrev = v6;
          pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        }
        if ( pTrackEnumBinding.m_EnumValue < 0x5B )
        {
          v7 = v4->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = v4->m_Components.p[20].m_pComponent;
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else if ( (v7 >> 12) & 1 )
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v9 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&v4->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v8 = v9;
          }
          else
          {
            v8 = v4->m_Components.p[20].m_pComponent;
          }
          if ( v8 )
            *v3 = SSInstance::pool_new(
                    UFG::TSSimObject::mspSimObjectClass,
                    *(_QWORD *)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64)
                              + *(_QWORD *)&v8[1].m_TypeUID
                              + 40));
        }
        v10 = pTrackEnumBinding.mPrev;
        v11 = pTrackEnumBinding.mNext;
        pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
        v11->mPrev = v10;
      }
    }
  }
}

// File Line: 3351
// RVA: 0x4F6650
void __fastcall UFG::TSActor::Mthd_clear_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rax
  unsigned __int16 v6; // cx
  UFG::TargetingSystemBaseComponent *v7; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v4 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v5 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v5;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v3,
                                                      UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v3,
                                                      UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v3->vfptr,
                                                      UFG::TargetingSystemBaseComponent::_TypeUID);
        }
      }
      else
      {
        v7 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
      }
      if ( v7 )
        UFG::TargetingSystemBaseComponent::ClearTarget(v7, (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue);
    }
    v8 = pTrackEnumBinding.mPrev;
    v9 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v9->mPrev = v8;
  }
}

// File Line: 3385
// RVA: 0x50ABE0
void __fastcall UFG::TSActor::Mthd_set_target_lock(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rbx
  SSData **v4; // rdx
  bool v5; // di
  bool v6; // si
  UFG::qSymbol *v7; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rcx
  UFG::SimComponent *v11; // rax
  int v12; // ST20_4
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h]
  UFG::qSymbol result; // [rsp+90h] [rbp+20h]

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = v4[1]->i_data_p->i_user_data != 0;
    v6 = v4[2]->i_data_p->i_user_data != 0;
    v7 = UFG::qSymbol::create_from_string(&result, *(const char **)(*v4)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v8 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v8;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v9 = v3->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v10 = v3->m_Components.p[20].m_pComponent;
      }
      else if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v9 >> 12) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v11 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v3->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v10 = v11;
      }
      else
      {
        v10 = v3->m_Components.p[20].m_pComponent;
      }
      if ( v10 )
      {
        v12 = 0;
        ((void (__fastcall *)(UFG::SimComponent *, _QWORD, bool, bool, int, const char *, _QWORD, _QWORD, signed __int64))v10->vfptr[14].__vecDelDtor)(
          v10,
          pTrackEnumBinding.m_EnumValue,
          v5,
          v6,
          v12,
          "TSActor::Mthd_set_target_lock",
          0i64,
          0i64,
          -2i64);
      }
    }
    v13 = pTrackEnumBinding.mPrev;
    v14 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v14->mPrev = v13;
  }
}

// File Line: 3421
// RVA: 0x50ADC0
void __fastcall UFG::TSActor::Mthd_set_target_prop(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSActor *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::SimObject *v7; // r8
  unsigned __int16 v8; // dx
  UFG::AIScriptInterfaceComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( v5 )
  {
    v6 = v5->i_class_p;
    if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
            v5->i_class_p,
            *v3,
            ppResult) )
    {
      if ( v6 != SSBrain::c_symbol_class_p || LODWORD(v5->i_user_data) == -1 )
        return;
      v5 = SSActor::find((ASymbol *)&v5->i_user_data);
    }
    if ( v5 )
    {
      v7 = v4->mpSimObj.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::AIScriptInterfaceComponent *)v7->m_Components.p[5].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          v10 = (UFG::SimObjectGame *)v4->mpSimObj.m_pPointer;
          if ( (v8 >> 13) & 1 )
          {
            v9 = (UFG::AIScriptInterfaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = (UFG::AIScriptInterfaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          else
          {
            v9 = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v10->vfptr,
                                                      UFG::AIScriptInterfaceComponent::_TypeUID);
          }
        }
        else
        {
          v9 = (UFG::AIScriptInterfaceComponent *)v7->m_Components.p[5].m_pComponent;
        }
        if ( v9 )
          UFG::AIScriptInterfaceComponent::SetDesiredTarget(
            v9,
            eTARGET_TYPE_INTERACTIVE_PROP,
            *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count);
      }
    }
  }
}

// File Line: 3439
// RVA: 0x50A700
void __fastcall UFG::TSActor::Mthd_set_subtarget(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // r8
  UFG::SimObjectCVBase *v4; // rcx
  SSInstance *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::TargetingSystemPedBaseComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v5 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v4->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v4->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v4->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
    }
    if ( v7 )
      UFG::TargetingSystemPedBaseComponent::SetFocusTargetSubTargetingLocationOverride(
        v7,
        (UFG::qSymbol *)&v5->i_user_data);
  }
}

// File Line: 3464
// RVA: 0x507110
void __fastcall UFG::TSActor::Mthd_set_attack_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSActor *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::SimObject *v7; // r8
  unsigned __int16 v8; // dx
  UFG::AIScriptInterfaceComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( v5 )
  {
    v6 = v5->i_class_p;
    if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
            v5->i_class_p,
            *v3,
            ppResult) )
    {
      if ( v6 != SSBrain::c_symbol_class_p || LODWORD(v5->i_user_data) == -1 )
        return;
      v5 = SSActor::find((ASymbol *)&v5->i_user_data);
    }
    if ( v5 )
    {
      v7 = v4->mpSimObj.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::AIScriptInterfaceComponent *)v7->m_Components.p[5].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          v10 = (UFG::SimObjectGame *)v4->mpSimObj.m_pPointer;
          if ( (v8 >> 13) & 1 )
          {
            v9 = (UFG::AIScriptInterfaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = (UFG::AIScriptInterfaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          else
          {
            v9 = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v10->vfptr,
                                                      UFG::AIScriptInterfaceComponent::_TypeUID);
          }
        }
        else
        {
          v9 = (UFG::AIScriptInterfaceComponent *)v7->m_Components.p[5].m_pComponent;
        }
        if ( v9 )
          UFG::AIScriptInterfaceComponent::SetDesiredTarget(
            v9,
            eTARGET_TYPE_FOCUS,
            *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count);
      }
    }
  }
}

// File Line: 3482
// RVA: 0x503690
void __fastcall UFG::TSActor::Mthd_is_target_valid(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::TSActor *v4; // rbx
  bool v5; // si
  UFG::qSymbol *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+70h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = this;
    v5 = 0;
    v6 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v7 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v7;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v8 = (UFG::SimObjectGame *)v4->mpSimObj.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v11 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v8->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v10 = v11;
        }
        else
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        if ( v10 )
          v5 = *(_QWORD *)(56i64
                         * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64)
                         + *(_QWORD *)&v10[1].m_TypeUID
                         + 40) != 0i64;
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
    v12 = pTrackEnumBinding.mPrev;
    v13 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v13->mPrev = v12;
  }
}

// File Line: 3519
// RVA: 0x5034C0
void __fastcall UFG::TSActor::Mthd_is_target_locked(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  UFG::TSActor *v4; // rdi
  bool v5; // bl
  UFG::qSymbol *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  signed __int64 v12; // rdx
  __int64 v13; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+70h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = this;
    v5 = 0;
    v6 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v7 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v7;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v8 = (UFG::SimObjectGame *)v4->mpSimObj.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v11 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v8->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v10 = v11;
        }
        else
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        if ( v10 )
        {
          v12 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64);
          v13 = *(_QWORD *)&v10[1].m_TypeUID;
          v5 = *(_QWORD *)(v12 + v13 + 40) && *(_BYTE *)(v12 + v13 + 49);
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
    v14 = pTrackEnumBinding.mPrev;
    v15 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v15->mPrev = v14;
  }
}

// File Line: 3555
// RVA: 0x4FD390
void __fastcall UFG::TSActor::Mthd_get_inventory_item(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // r9
  SSInstance **v4; // rbx
  unsigned __int16 v5; // cx
  UFG::InventoryComponent *v6; // rax
  ASymbol *v7; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3
      || this->i_actor_flags & 0x10000
      || (v5 = v3->m_Flags, (v5 >> 14) & 1)
      || (v5 & 0x8000u) != 0
      || (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                                                      (UFG::SimObject *)&v3->vfptr,
                                                                                      UFG::InventoryItemComponent::_TypeUID)) : (v6 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryItemComponent::_TypeUID))) : (v6 = (UFG::InventoryComponent *)v3->m_Components.p[11].m_pComponent),
          !v6) )
    {
      v7 = ASymbol::get_null();
      *v4 = SSSymbol::as_instance(v7);
    }
    else
    {
      *v4 = SSSymbol::as_instance((ASymbol *)&v6->m_InventoryItems[4]);
    }
  }
}

// File Line: 3588
// RVA: 0x508800
void __fastcall UFG::TSActor::Mthd_set_interaction_point_active(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rbx
  SSData **v4; // rcx
  SSInstance *v5; // rdx
  bool v6; // di
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  unsigned __int16 v8; // cx
  UFG::InteractableComponent *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = (*v4)->i_data_p;
    v6 = v4[1]->i_data_p->i_user_data != 0;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol.mUID = v5->i_user_data;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      v7 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v7;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v8 = v3->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = (UFG::InteractableComponent *)v3->m_Components.p[12].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = (UFG::InteractableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v3,
                                               UFG::InteractableComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v9 = (UFG::InteractableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v3,
                                               UFG::InteractableComponent::_TypeUID);
        }
        else
        {
          v9 = (UFG::InteractableComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::InteractableComponent::_TypeUID);
        }
      }
      else
      {
        v9 = (UFG::InteractableComponent *)v3->m_Components.p[12].m_pComponent;
      }
      if ( v9 )
        UFG::InteractableComponent::SetIsActive(v9, (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue, v6);
    }
    v10 = pTrackEnumBinding.mPrev;
    v11 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v11->mPrev = v10;
  }
}

// File Line: 3613
// RVA: 0x5073D0
void __fastcall UFG::TSActor::Mthd_set_best_interaction_point(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // r14
  UFG::TSActor *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  __int64 v7; // rdi
  UFG::SimObjectGame *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::InteractableComponent *v14; // rsi
  UFG::SimComponent *v15; // rax
  unsigned __int16 v16; // cx
  UFG::InteractorComponent *v17; // rdi
  UFG::SimComponent *v18; // rax
  UFG::qSymbol *v19; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::InteractionPoint *v21; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v22; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v23; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v24; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v25; // rax
  TracksEnumBinding<unsigned long> v26; // [rsp+28h] [rbp-48h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+30h]

  v3 = pScope;
  v4 = this;
  v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
    v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v6;
    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v7 = pTrackEnumBinding.m_EnumValue;
  v8 = (UFG::SimObjectGame *)v4->mpSimObj.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v8->m_Components.p[20].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v10 = v11;
    }
    else
    {
      v10 = v8->m_Components.p[20].m_pComponent;
    }
    if ( v10 )
    {
      v12 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + v7 + 8)
                                   + *(_QWORD *)&v10[1].m_TypeUID
                                   + 40);
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = (UFG::InteractableComponent *)v12->m_Components.p[12].m_pComponent;
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::InteractableComponent::_TypeUID);
          else
            v15 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::InteractableComponent::_TypeUID);
          v14 = (UFG::InteractableComponent *)v15;
        }
        else
        {
          v14 = (UFG::InteractableComponent *)v12->m_Components.p[12].m_pComponent;
        }
        if ( v14 )
        {
          v16 = v8->m_Flags;
          if ( (v16 >> 14) & 1 )
          {
            v17 = (UFG::InteractorComponent *)v8->m_Components.p[29].m_pComponent;
          }
          else
          {
            if ( (v16 & 0x8000u) == 0 )
            {
              if ( (v16 >> 13) & 1 )
              {
                v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::InteractorComponent::_TypeUID);
              }
              else if ( (v16 >> 12) & 1 )
              {
                v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::InteractorComponent::_TypeUID);
              }
              else
              {
                v18 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v8->vfptr,
                        UFG::InteractorComponent::_TypeUID);
              }
            }
            else
            {
              v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::InteractorComponent::_TypeUID);
            }
            v17 = (UFG::InteractorComponent *)v18;
          }
          if ( v17 )
          {
            v19 = UFG::qSymbol::create_from_string(
                    &result,
                    **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
            v26.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
            v26.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
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
              UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
              v26.mPrev = v20;
              v26.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
              UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
            }
            v21 = UFG::InteractableComponent::FindInteractionPoint(
                    v14,
                    (UFG::SimObject *)&v8->vfptr,
                    (UFG::eTargetTypeEnum)v26.m_EnumValue,
                    1);
            if ( v21 )
              UFG::InteractorComponent::SetBestInteractionPoint(v17, v21, 1);
            v22 = v26.mPrev;
            v23 = v26.mNext;
            v26.mPrev->mNext = v26.mNext;
            v23->mPrev = v22;
            v26.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
            v26.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
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
void __fastcall UFG::TSActor::Mthd_is_best_interaction_point_busy(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  bool v4; // bl
  SSInstance **v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v3->m_Components.p[29].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractorComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
      }
      if ( v7 )
      {
        v8 = v7[1].m_SafePointerList.mNode.mNext;
        if ( v8 )
          v4 = LODWORD(v8[2].mPrev) != 0;
      }
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 3737
// RVA: 0x4F55F0
void __fastcall UFG::TSActor::Mthd_attach_target(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  SSData **v9; // rdx
  float blendInTime; // xmm6_4
  bool attachRelative; // si
  bool attachToTarget; // r14
  bool addToInventory; // r15
  bool v14; // r12
  UFG::qSymbol *v15; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v16; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v17; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v18; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v19; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v21; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v22; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp-39h]
  UFG::eTargetTypeEnum assignmentTargetType[2]; // [rsp+60h] [rbp-31h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+68h] [rbp-29h]
  TracksEnumBinding<unsigned long> v26; // [rsp+88h] [rbp-9h]
  UFG::qSymbolUC targetAttachJoint; // [rsp+F8h] [rbp+67h]
  UFG::qSymbolUC attachJoint; // [rsp+110h] [rbp+7Fh]

  *(_QWORD *)assignmentTargetType = -2i64;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v6;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      UFG::qSymbolUC::create_from_string(
        &attachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
      UFG::qSymbolUC::create_from_string(
        &targetAttachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64));
      v9 = v3->i_data.i_array_p;
      blendInTime = *(float *)&v9[3]->i_data_p->i_user_data;
      attachRelative = v9[4]->i_data_p->i_user_data != 0;
      attachToTarget = v9[5]->i_data_p->i_user_data != 0;
      addToInventory = v9[6]->i_data_p->i_user_data != 0;
      v14 = v9[7]->i_data_p->i_user_data != 0;
      v15 = UFG::qSymbol::create_from_string(&result, *(const char **)v9[8]->i_data_p->i_user_data);
      v26.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
      v26.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
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
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
        v26.mPrev = v16;
        v26.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
      }
      if ( v26.m_EnumValue < 0x5B )
        UFG::TargetAttach(
          v4,
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
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 9) + 8i64) + 32i64) != 0i64,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 10) + 8i64) + 32i64) != 0i64,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 11) + 8i64) + 32i64) != 0i64,
          0i64);
      v17 = v26.mPrev;
      v18 = v26.mNext;
      v26.mPrev->mNext = v26.mNext;
      v18->mPrev = v17;
      v26.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
      v26.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v26;
      v19 = pTrackEnumBinding.mPrev;
      v20 = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      v20->mPrev = v19;
      pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    else
    {
      v7 = pTrackEnumBinding.mPrev;
      v8 = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      v8->mPrev = v7;
      pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
  SSInvokedMethod *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  SSData **v9; // r11
  UFG::qSymbol result; // [rsp+78h] [rbp+27h]
  __int64 v11; // [rsp+80h] [rbp+2Fh]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+88h] [rbp+37h]
  void *targetAttachJoint; // [rsp+B8h] [rbp+67h]
  UFG::qSymbolUC attachJoint; // [rsp+D0h] [rbp+7Fh]

  v11 = -2i64;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v6;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      UFG::qSymbolUC::create_from_string(
        &attachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
      UFG::qSymbolUC::create_from_string(
        (UFG::qSymbolUC *)&targetAttachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64));
      v9 = v3->i_data.i_array_p;
      UFG::TargetDetach(
        v4,
        (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
        0i64,
        &attachJoint,
        (UFG::qSymbolUC *)&targetAttachJoint,
        *(float *)&v9[3]->i_data_p->i_user_data,
        v9[4]->i_data_p->i_user_data != 0,
        v9[5]->i_data_p->i_user_data != 0,
        v9[6]->i_data_p->i_user_data != 0,
        v9[7]->i_data_p->i_user_data != 0,
        v9[8]->i_data_p->i_user_data != 0,
        0,
        *(float *)&v9[9]->i_data_p->i_user_data,
        *(float *)&v9[10]->i_data_p->i_user_data,
        0);
    }
    v7 = pTrackEnumBinding.mPrev;
    v8 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v8->mPrev = v7;
  }
}

// File Line: 3894
// RVA: 0x4F5350
void __fastcall UFG::TSActor::Mthd_attach(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // rbx
  UFG::SimObject *v4; // rsi
  UFG::qBaseNodeRB *v5; // rdi
  SSData **v6; // rdx
  float blendInTime; // xmm6_4
  bool attachRelative; // r14
  bool attachToTarget; // r15
  bool addToInventory; // r12
  bool v11; // r13
  UFG::qSymbol *v12; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rax
  UFG::qSymbol v16; // [rsp+58h] [rbp-19h]
  UFG::eTargetTypeEnum assignmentTargetType[2]; // [rsp+60h] [rbp-11h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+68h] [rbp-9h]
  UFG::qSymbolUC targetAttachJoint; // [rsp+D8h] [rbp+67h]
  UFG::qSymbolUC result; // [rsp+F0h] [rbp+7Fh]

  *(_QWORD *)assignmentTargetType = -2i64;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v5 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
      if ( v5 )
      {
        UFG::qSymbolUC::create_from_string(
          &result,
          **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
        UFG::qSymbolUC::create_from_string(
          &targetAttachJoint,
          **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64));
        v6 = v3->i_data.i_array_p;
        blendInTime = *(float *)&v6[3]->i_data_p->i_user_data;
        attachRelative = v6[4]->i_data_p->i_user_data != 0;
        attachToTarget = v6[5]->i_data_p->i_user_data != 0;
        addToInventory = v6[6]->i_data_p->i_user_data != 0;
        v11 = v6[7]->i_data_p->i_user_data != 0;
        v12 = UFG::qSymbol::create_from_string(&v16, *(const char **)v6[8]->i_data_p->i_user_data);
        pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
          v13 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
          pTrackEnumBinding.mPrev = v13;
          pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
          UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        }
        if ( pTrackEnumBinding.m_EnumValue < 0x5B )
          UFG::TargetAttach(
            v4,
            0,
            (UFG::SimObject *)v5,
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
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 9) + 8i64) + 32i64) != 0i64,
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 10) + 8i64) + 32i64) != 0i64,
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 11) + 8i64) + 32i64) != 0i64,
            0i64);
        v14 = pTrackEnumBinding.mPrev;
        v15 = pTrackEnumBinding.mNext;
        pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
        v15->mPrev = v14;
      }
    }
  }
}

// File Line: 3977
// RVA: 0x4F7F40
void __fastcall UFG::TSActor::Mthd_detach(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r14
  SSInvokedMethod *v4; // rbx
  UFG::qBaseNodeRB *v5; // rbp
  SSData **v6; // rdx
  UFG::qSymbolUC targetAttachJoint; // [rsp+A0h] [rbp+8h]
  UFG::qSymbolUC result; // [rsp+B8h] [rbp+20h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && !(this->i_actor_flags & 0x10000) )
  {
    v5 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
    if ( v5 )
    {
      UFG::qSymbolUC::create_from_string(
        &result,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64));
      UFG::qSymbolUC::create_from_string(
        &targetAttachJoint,
        **(const char ***)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 2) + 8i64) + 32i64));
      v6 = v4->i_data.i_array_p;
      UFG::TargetDetach(
        v3,
        0,
        (UFG::SimObject *)v5,
        &result,
        &targetAttachJoint,
        *(float *)&v6[3]->i_data_p->i_user_data,
        v6[4]->i_data_p->i_user_data != 0,
        v6[5]->i_data_p->i_user_data != 0,
        v6[6]->i_data_p->i_user_data != 0,
        v6[7]->i_data_p->i_user_data != 0,
        v6[8]->i_data_p->i_user_data != 0,
        0,
        *(float *)&v6[9]->i_data_p->i_user_data,
        *(float *)&v6[10]->i_data_p->i_user_data,
        0);
    }
  }
}

// File Line: 4049
// RVA: 0x50E4F0
void __fastcall UFG::TSActor::Mthd_was_hit_by_vehicle(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  char v4; // di
  SSInstance **v5; // rsi
  SSInvokedMethod *v6; // rbp
  unsigned __int16 v7; // r9
  UFG::SimComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rbx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  SSInstance *v13; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    v6 = pScope;
    if ( !v3 )
      goto LABEL_29;
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v3->m_Components.p[15].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
      v8 = v9;
    }
    else
    {
      v8 = v3->m_Components.p[15].m_pComponent;
    }
    if ( !v8 )
      goto LABEL_29;
    if ( *(_DWORD *)(&v8[3].m_SimObjIndex + 1) != 1 )
      goto LABEL_29;
    if ( HIDWORD(v8[2].m_BoundComponentHandles.mNode.mNext) != gAttackTypeWorldCollision.m_EnumValue )
      goto LABEL_29;
    v10 = *(UFG::SimObjectGame **)&v8[3].m_TypeUID;
    if ( !v10 )
      goto LABEL_29;
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
      goto LABEL_29;
    if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
LABEL_29:
        *v5 = (SSInstance *)SSBoolean::pool_new(v4);
        return;
      }
      if ( (v11 >> 12) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::PhysicsMoverInterface::_TypeUID);
      else
        v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
    }
    else
    {
      v12 = v10->m_Components.p[34].m_pComponent;
    }
    if ( v12 )
    {
      v13 = (*v6->i_data.i_array_p)->i_data_p;
      if ( v13 && v13 != SSBrain::c_nil_p )
        v4 = v10 == *(UFG::SimObjectGame **)&v13[4].i_ref_count;
      else
        v4 = 1;
    }
    goto LABEL_29;
  }
}

// File Line: 4100
// RVA: 0x50E670
void __fastcall UFG::TSActor::Mthd_was_shot(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  char v4; // bl
  SSInstance **v5; // rdi
  SSInvokedMethod *v6; // rsi
  unsigned __int16 v7; // r9
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  SSInstance *v10; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    v6 = pScope;
    if ( v3 )
    {
      v7 = v3->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = v3->m_Components.p[15].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
        }
        v8 = v9;
      }
      else
      {
        v8 = v3->m_Components.p[15].m_pComponent;
      }
      if ( v8
        && *(_DWORD *)(&v8[3].m_SimObjIndex + 1) == 1
        && HIDWORD(v8[2].m_BoundComponentHandles.mNode.mNext) == gAttackCollisionProjectile.m_EnumValue )
      {
        v10 = (*v6->i_data.i_array_p)->i_data_p;
        if ( v10 && v10 != SSBrain::c_nil_p )
          v4 = *(_QWORD *)&v8[3].m_TypeUID == *(_QWORD *)&v10[4].i_ref_count;
        else
          v4 = 1;
      }
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 4139
// RVA: 0x4FFE80
void __fastcall UFG::TSActor::Mthd_has_hit_object(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  SSInvokedMethod *v4; // rsi
  UFG::TSActor *v5; // rbx
  unsigned int v6; // er9
  SSClass *v7; // rax
  ASymbol *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  UFG::SimComponent *v10; // rbx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  SSTypedData **v15; // rdx
  unsigned __int64 v16; // r8
  SSInstance *v17; // rcx
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-30h]
  ASymbol result; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = pScope;
    v5 = this;
    v6 = _S9_14;
    if ( _S9_14 & 1 )
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
    if ( !(v6 & 2) )
    {
      v6 |= 2u;
      _S9_14 = v6;
      classData = &v7->i_class_data;
    }
    if ( !(v6 & 4) )
    {
      _S9_14 = v6 | 4;
      v8 = ASymbol::create(&result, "invalid", 0xFFFFFFFF, ATerm_long);
      spInvalid = *(SSInstance **)&APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
                                     (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)classData,
                                     v8)[1].i_name.i_uid;
    }
    v9 = (UFG::SimObjectGame *)v5->mpSimObj.m_pPointer;
    if ( v9 )
    {
      v11 = v9->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v10 = v9->m_Components.p[15].m_pComponent;
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HitReactionComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HitReactionComponent::_TypeUID);
        }
        else
        {
          v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::HitReactionComponent::_TypeUID);
        }
        v10 = v12;
      }
      else
      {
        v10 = v9->m_Components.p[15].m_pComponent;
      }
    }
    else
    {
      v10 = 0i64;
    }
    *v3 = spInvalid;
    if ( v10
      && *(_DWORD *)(&v10[3].m_SimObjIndex + 1) == 1
      && HIDWORD(v10[2].m_BoundComponentHandles.mNode.mNext) == gAttackTypeWorldCollision.m_EnumValue
      && (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(&v10[6].m_SimObjIndex + 1) / UFG::TidoGame::sm_MaxCollisionVelocity) & _xmm)
               * 100.0) >= *(float *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v18);
      v14 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v13);
      v18.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v18, v18.mTypeUID, (unsigned __int64)v10[5].m_pSimObject);
      if ( v18.mData )
      {
        v15 = classData->i_array_p;
        v16 = (unsigned __int64)&v15[classData->i_count];
        if ( (unsigned __int64)v15 < v16 )
        {
          while ( 1 )
          {
            v17 = (*v15)->i_data_p;
            if ( v17->i_user_data == HIDWORD(v18.mData[4].mBaseNode.mParent) )
              break;
            ++v15;
            if ( (unsigned __int64)v15 >= v16 )
              goto LABEL_31;
          }
          *v3 = v17;
        }
      }
LABEL_31:
      UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
    }
    ++(*v3)->i_ref_count;
  }
}

// File Line: 4202
// RVA: 0x5000D0
void __fastcall UFG::TSActor::Mthd_has_hit_static_object(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  SSInvokedMethod *v4; // rbp
  bool v5; // di
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // r9
  UFG::SimComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v10; // rcx
  const char *v11; // rax
  UFG::qReflectHandleBase v12; // [rsp+28h] [rbp-30h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = pScope;
    v5 = 0;
    v6 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = v6->m_Components.p[15].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::HitReactionComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::HitReactionComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::HitReactionComponent::_TypeUID);
        }
        v8 = v9;
      }
      else
      {
        v8 = v6->m_Components.p[15].m_pComponent;
      }
      if ( v8
        && *(_DWORD *)(&v8[3].m_SimObjIndex + 1) == 1
        && HIDWORD(v8[2].m_BoundComponentHandles.mNode.mNext) == gAttackTypeWorldCollision.m_EnumValue
        && (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(&v8[6].m_SimObjIndex + 1) / UFG::TidoGame::sm_MaxCollisionVelocity) & _xmm)
                 * 100.0) >= *(float *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v12);
        v11 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v10);
        v12.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v12, v12.mTypeUID, (unsigned __int64)v8[5].m_pSimObject);
        if ( v12.mData )
          v5 = LODWORD(v12.mData[2].mBaseNode.mChildren[1]) == 1;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 4260
// RVA: 0x4F4E10
void __fastcall UFG::TSActor::Mthd_are_resources_loaded(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInstance **v4; // rsi
  char v5; // di
  unsigned __int16 v6; // dx
  UFG::StreamedResourceComponent *v7; // rbx
  UFG::SimComponent *v8; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = 1;
    if ( v3 )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent;
        }
        else
        {
          if ( (v6 >> 12) & 1 )
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StreamedResourceComponent::_TypeUID);
          else
            v8 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v3->vfptr,
                   UFG::StreamedResourceComponent::_TypeUID);
          v7 = (UFG::StreamedResourceComponent *)v8;
        }
      }
      else
      {
        v7 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
      }
      if ( v7 && UFG::StreamedResourceComponent::IsLoadActive(v7) )
        v5 = UFG::StreamedResourceComponent::AreResourcesLoaded(v7)
          && UFG::StreamedResourceComponent::AreResourcesBound(v7);
    }
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 4282
// RVA: 0x4FEA70
void __fastcall UFG::TSActor::Mthd_get_spawn_priority(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInstance **v4; // rbx
  unsigned __int16 v5; // dx
  UFG::StreamedResourceComponent *v6; // rax
  ASymbol sym; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    sym.i_uid = qSymbol_Low.mUID;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent;
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v3,
                                                   UFG::StreamedResourceComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
      }
      if ( v6 )
        sym.i_uid = UFG::StreamedResourceComponent::GetSpawnPriority(v6, 0i64)->mUID;
    }
    *v4 = SSSymbol::as_instance(&sym);
  }
}

// File Line: 4300
// RVA: 0x5002B0
void __fastcall UFG::TSActor::Mthd_inc_spawn_priority_ref(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInvokedMethod *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::StreamedResourceComponent *v6; // r8
  UFG::SimComponent *v7; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StreamedResourceComponent::_TypeUID);
        else
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::StreamedResourceComponent::_TypeUID);
        v6 = (UFG::StreamedResourceComponent *)v7;
      }
    }
    else
    {
      v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
    }
    if ( v6 )
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(
        v6,
        (UFG::qSymbol *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4309
// RVA: 0x4F7A80
void __fastcall UFG::TSActor::Mthd_dec_spawn_priority_ref(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInvokedMethod *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::StreamedResourceComponent *v6; // r8
  UFG::SimComponent *v7; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StreamedResourceComponent::_TypeUID);
        else
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::StreamedResourceComponent::_TypeUID);
        v6 = (UFG::StreamedResourceComponent *)v7;
      }
    }
    else
    {
      v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
    }
    if ( v6 )
      UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(
        v6,
        (UFG::qSymbol *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4324
// RVA: 0x4E6350
void __fastcall UFG::TSActor::MthdC_find_named(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // rdi
  UFG::TSActor *v4; // rcx
  UFG::qBaseNodeRB *v5; // rax
  SSInstance *v6; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = (UFG::TSActor *)SSActor::find((ASymbol *)&v3->i_user_data);
    if ( !v4 )
    {
      v5 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v3->i_user_data);
      v4 = UFG::TSActor::FromSimObject((UFG::SimObject *)v5);
    }
    v6 = SSBrain::c_nil_p;
    if ( v4 )
      v6 = (SSInstance *)&v4->vfptr;
    *v2 = v6;
    ++v6->i_ref_count;
  }
}

// File Line: 4352
// RVA: 0x4E62C0
void __fastcall UFG::TSActor::MthdC_find_instance(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // rdi
  __int64 v4; // rax
  signed __int64 v5; // rcx
  UFG::TSActor *v6; // rcx
  UFG::qBaseNodeRB *v7; // rax
  SSInstance *v8; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = ((__int64 (*)(void))scope_p->vfptr->get_topmost_scope)();
    if ( v4 )
      v5 = v4 - 8;
    else
      v5 = 0i64;
    v6 = (UFG::TSActor *)APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
                           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(*(_QWORD *)(v5 + 56) + 304i64),
                           (ASymbol *)&v3->i_user_data);
    if ( !v6 )
    {
      v7 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v3->i_user_data);
      v6 = UFG::TSActor::FromSimObject((UFG::SimObject *)v7);
    }
    v8 = SSBrain::c_nil_p;
    if ( v6 )
      v8 = (SSInstance *)&v6->vfptr;
    *v2 = v8;
    ++v8->i_ref_count;
  }
}

// File Line: 4383
// RVA: 0x4E79E0
void __fastcall UFG::TSActor::MthdC_get_instance(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // rdi
  __int64 v4; // rax
  signed __int64 v5; // rax
  __int64 v6; // rcx
  UFG::TSActor *v7; // rax
  UFG::qBaseNodeRB *v8; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = ((__int64 (*)(void))scope_p->vfptr->get_topmost_scope)();
    if ( !v4
      || (v5 = v4 - 8) == 0
      || (v6 = *(_QWORD *)(v5 + 56)) == 0
      || (v7 = (UFG::TSActor *)APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
                                 (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(v6 + 304),
                                 (ASymbol *)&v3->i_user_data)) == 0i64 )
    {
      v8 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v3->i_user_data);
      v7 = UFG::TSActor::FromSimObject((UFG::SimObject *)v8);
    }
    ++v7->i_ref_count;
    *v2 = (SSInstance *)&v7->vfptr;
  }
}

// File Line: 4423
// RVA: 0x511710
void __fastcall UFG::TSActor::TeleportToTransformRaw(UFG::TSActor *this, UFG::qMatrix44 *transform)
{
  UFG::qMatrix44 *v2; // rdi
  UFG::TSActor *v3; // rbx
  UFG::allocator::free_link *v4; // rax

  v2 = transform;
  v3 = this;
  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v4,
      v2,
      v3->mpSimObj.m_pPointer->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  ((void (__fastcall *)(UFG::TSActor *))v3->vfptr[2].get_data_by_name)(v3);
}

// File Line: 4431
// RVA: 0x511350
void __fastcall UFG::TSActor::TeleportToTransform(UFG::TSActor *this, UFG::qMatrix44 *transform)
{
  UFG::qMatrix44 *v2; // rsi
  UFG::TSActor *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::qVector3 out; // [rsp+38h] [rbp-20h]

  v2 = transform;
  v3 = this;
  if ( UFG::PlaceOnGround(&out, (UFG::qVector3 *)&transform->v3, 0.050000001, 0.0) )
  {
    v2->v3.x = out.x;
    v2->v3.y = out.y;
    v2->v3.z = out.z;
    v2->v3.w = 1.0;
  }
  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v4,
      v2,
      v3->mpSimObj.m_pPointer->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  ((void (__fastcall *)(UFG::TSActor *))v3->vfptr[2].get_data_by_name)(v3);
}

// File Line: 4453
// RVA: 0x511430
void __fastcall UFG::TSActor::TeleportToTransformPreserveVel(UFG::TSActor *this, UFG::qMatrix44 *transform)
{
  UFG::TSActor *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  int *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::CharacterPhysicsComponent *v6; // rdi
  UFG::CharacterPhysicsComponent *v7; // rax
  int v8; // xmm1_4
  float v9; // xmm10_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm1_4
  int v24; // xmm0_4
  int v25; // xmm1_4
  int v26; // xmm0_4
  int v27; // xmm1_4
  int v28; // xmm1_4
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm0_4
  int v36; // xmm1_4
  int v37; // xmm0_4
  int v38; // xmm1_4
  int v39; // xmm0_4
  int v40; // xmm1_4
  int v41; // xmm0_4
  int v42; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-49h]
  int v44; // [rsp+30h] [rbp-39h]
  int v45; // [rsp+34h] [rbp-35h]
  int v46; // [rsp+38h] [rbp-31h]
  int v47; // [rsp+3Ch] [rbp-2Dh]
  int v48; // [rsp+40h] [rbp-29h]
  int v49; // [rsp+44h] [rbp-25h]
  int v50; // [rsp+48h] [rbp-21h]
  int v51; // [rsp+4Ch] [rbp-1Dh]
  int v52; // [rsp+50h] [rbp-19h]
  int v53; // [rsp+54h] [rbp-15h]
  int v54; // [rsp+58h] [rbp-11h]
  int v55; // [rsp+5Ch] [rbp-Dh]
  int v56; // [rsp+60h] [rbp-9h]
  int v57; // [rsp+64h] [rbp-5h]
  int v58; // [rsp+68h] [rbp-1h]
  int v59; // [rsp+6Ch] [rbp+3h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = (int *)transform;
  if ( v3
    && ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID)) : (v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v7 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID)),
                                                 v6 = v7) : (v6 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent),
        v6) )
  {
    UFG::CharacterPhysicsComponent::GetVelocity(v6, &result);
    v8 = v4[1];
    v9 = v6->mAdditiveVelocity.x;
    v10 = v6->mAdditiveVelocity.y;
    v11 = v6->mAdditiveVelocity.z;
    v12 = v6->mGravity;
    v13 = v6->mSpeedZ;
    v44 = *v4;
    v14 = v4[2];
    v45 = v8;
    v15 = v4[3];
    v46 = v14;
    v16 = v4[4];
    v47 = v15;
    v17 = v4[5];
    v48 = v16;
    v18 = v4[6];
    v49 = v17;
    v19 = v4[7];
    v50 = v18;
    v20 = v4[8];
    v51 = v19;
    v21 = v4[9];
    v52 = v20;
    v22 = v4[10];
    v53 = v21;
    v23 = v4[11];
    v54 = v22;
    v24 = v4[12];
    v55 = v23;
    v25 = v4[13];
    v56 = v24;
    v26 = v4[14];
    v57 = v25;
    v27 = v4[15];
    v58 = v26;
    v59 = v27;
    UFG::TSActor::TeleportToTransform(v2, (UFG::qMatrix44 *)&v44);
    UFG::CharacterPhysicsComponent::SetVelocity(v6, &result);
    v6->mAdditiveVelocity.x = v9;
    v6->mAdditiveVelocity.y = v10;
    v6->mAdditiveVelocity.z = v11;
    v6->mGravity = v12;
    v6->mSpeedZ = v13;
  }
  else
  {
    v28 = v4[1];
    v44 = *v4;
    v29 = v4[2];
    v45 = v28;
    v30 = v4[3];
    v46 = v29;
    v31 = v4[4];
    v47 = v30;
    v32 = v4[5];
    v48 = v31;
    v33 = v4[6];
    v49 = v32;
    v34 = v4[7];
    v50 = v33;
    v35 = v4[8];
    v51 = v34;
    v36 = v4[9];
    v52 = v35;
    v37 = v4[10];
    v53 = v36;
    v38 = v4[11];
    v54 = v37;
    v39 = v4[12];
    v55 = v38;
    v40 = v4[13];
    v56 = v39;
    v41 = v4[14];
    v57 = v40;
    v42 = v4[15];
    v58 = v41;
    v59 = v42;
    UFG::TSActor::TeleportToTransform(v2, (UFG::qMatrix44 *)&v44);
  }
}

// File Line: 4491
// RVA: 0x4DE7A0
char __fastcall UFG::TSActor::Coro_wait_ai_stimulus(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // r15
  SSData **v3; // r8
  UFG::eStimulusType v4; // er12
  SSInstance *v5; // rbx
  UFG::StimulusNotifyCallback *v6; // r14
  SSClass *v7; // rbp
  SSActorClass *v8; // rsi
  SSActorClass *v9; // rax
  UFG::SimObjectGame *v10; // rbx
  SSClass *v11; // rcx
  __int64 v12; // rdi
  SSClass *v13; // rax
  UFG::qBaseNodeRB *v14; // rbp
  SSClass *v15; // rcx
  unsigned __int16 v16; // cx
  UFG::StimulusReceiverComponent *v17; // rsi
  UFG::SimComponent *v18; // rax
  UFG::qMemoryPool *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::StimulusReceiverComponent *v21; // rax
  unsigned __int16 v22; // cx
  unsigned int v23; // edi
  UFG::allocator::free_link *v24; // rax
  UFG::StimulusNotifyCallback *v25; // rax
  SSInstance *v27; // rbx
  __int64 v28; // rsi
  _DWORD *v29; // rcx
  bool v30; // zf
  UFG::SimObjectModifier v31; // [rsp+38h] [rbp-50h]

  v2 = pScope;
  if ( pScope->i_update_count )
    return 1;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p->i_user_data;
  v5 = v3[1]->i_data_p;
  v6 = 0i64;
  v7 = UFG::TSSimObject::mspSimObjectClass;
  v8 = SSBrain::c_physical_actor_class_p;
  if ( !v5 )
    goto LABEL_11;
  v9 = (SSActorClass *)v5->i_class_p;
  if ( v9 != (SSActorClass *)UFG::TSSimObject::mspSimObjectClass )
  {
    if ( v9 == (SSActorClass *)SSBrain::c_symbol_class_p )
    {
      v10 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v5->i_user_data);
      v7 = UFG::TSSimObject::mspSimObjectClass;
      v8 = SSBrain::c_physical_actor_class_p;
      goto LABEL_12;
    }
    if ( SSBrain::c_physical_actor_class_p == v9
      || (v11 = v9->i_superclass_p) != 0i64
      && SSClass::is_class(v11, (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr) )
    {
      v10 = *(UFG::SimObjectGame **)&v5[4].i_ref_count;
      goto LABEL_12;
    }
LABEL_11:
    v10 = 0i64;
    goto LABEL_12;
  }
  v10 = (UFG::SimObjectGame *)v5->i_user_data;
LABEL_12:
  v12 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64);
  if ( !v12 )
    goto LABEL_52;
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
  if ( v8 == (SSActorClass *)v13 || (v15 = v13->i_superclass_p) != 0i64 && SSClass::is_class(v15, (SSClass *)&v8->vfptr) )
    v14 = *(UFG::qBaseNodeRB **)(v12 + 208);
  else
LABEL_52:
    v14 = 0i64;
LABEL_22:
  if ( !v10 )
  {
    v27 = UFG::gpAIStimulusTypeClass_none;
    v28 = *((_QWORD *)v2->i_data.i_array_p + 5);
    ++v27->i_ref_count;
    v29 = *(_DWORD **)(v28 + 8);
    v30 = v29[4]-- == 1;
    if ( v30 )
    {
      v29[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v29 + 112i64))();
    }
    *(_QWORD *)(v28 + 8) = v27;
    return 1;
  }
  v16 = v10->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = (UFG::StimulusReceiverComponent *)v10->m_Components.p[11].m_pComponent;
  }
  else if ( (v16 & 0x8000u) == 0 )
  {
    if ( (v16 >> 13) & 1 )
    {
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::StimulusReceiverComponent::_TypeUID);
    }
    else if ( (v16 >> 12) & 1 )
    {
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::StimulusReceiverComponent::_TypeUID);
    }
    else
    {
      v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::StimulusReceiverComponent::_TypeUID);
    }
    v17 = (UFG::StimulusReceiverComponent *)v18;
  }
  else
  {
    v17 = (UFG::StimulusReceiverComponent *)v10->m_Components.p[11].m_pComponent;
  }
  if ( !v17 )
  {
    v19 = UFG::GetSimulationMemoryPool();
    v20 = UFG::qMemoryPool::Allocate(v19, 0x428ui64, "StimulusReceiverComponent", 0i64, 1u);
    if ( v20 )
    {
      UFG::StimulusReceiverComponent::StimulusReceiverComponent((UFG::StimulusReceiverComponent *)v20, v10->mNode.mUID);
      v17 = v21;
    }
    else
    {
      v17 = 0i64;
    }
    v22 = v10->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v23 = 11;
    }
    else if ( (v22 & 0x8000u) == 0 )
    {
      v23 = -1;
    }
    else
    {
      v23 = 11;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v31, (UFG::SimObject *)&v10->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v31, (UFG::SimComponent *)&v17->vfptr, v23);
    UFG::SimObjectModifier::Close(&v31);
    UFG::SimObjectModifier::~SimObjectModifier(&v31);
  }
  v24 = UFG::qMalloc(0x90ui64, "StimulusNotifyScript", 0i64);
  if ( v24 )
  {
    UFG::StimulusNotifyScript::StimulusNotifyScript((UFG::StimulusNotifyScript *)v24, v4, v2, (UFG::SimObject *)v14);
    v6 = v25;
  }
  UFG::StimulusReceiverComponent::RegisterNotifyCallback(v17, v6);
  return 0;
}

// File Line: 4538
// RVA: 0x4DB520
char __fastcall UFG::TSActor::Coro_invoke_aibehaviour(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // r8
  UFG::BehaviourControllerComponent *v5; // rax
  UFG::BehaviourControllerComponent *v6; // rbx
  SSData **v7; // rdx
  SSInstance *v8; // r8
  int v9; // er12
  SSInstance *v10; // r15
  float v11; // xmm6_4
  float v12; // xmm7_4
  bool v13; // r14
  char v14; // si
  ActionNode *v15; // rax
  const char *v16; // r14
  signed __int64 v17; // rbx
  unsigned int v18; // eax
  AStringRef *v19; // rbx
  bool v20; // zf
  AObjReusePool<AStringRef> *v21; // rax
  AObjBlock<AStringRef> *v22; // rcx
  unsigned __int64 v23; // rdx
  bool v24; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v25; // rcx
  int v26; // edx
  ActionPath absolutePath; // [rsp+8h] [rbp-79h]
  UFG::InvokeBehaviourParams params; // [rsp+18h] [rbp-69h]
  UFG::InvokeBehaviourResult optResult; // [rsp+48h] [rbp-39h]
  __int64 v31; // [rsp+88h] [rbp+7h]
  AString str; // [rsp+E8h] [rbp+67h]

  v31 = -2i64;
  v2 = pScope;
  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(v3);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v3->vfptr,
                                                  UFG::BehaviourControllerComponent::_TypeUID);
    else
      v5 = (UFG::BehaviourControllerComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v3->vfptr,
                                                                    UFG::BehaviourControllerComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::BehaviourControllerComponent::_TypeUID));
  }
  else
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(v3);
  }
  v6 = v5;
  if ( !v5 )
    return 1;
  v7 = v2->i_data.i_array_p;
  v8 = (*v7)->i_data_p;
  v9 = v7[1]->i_data_p->i_user_data;
  v10 = v7[2]->i_data_p;
  v11 = *(float *)&v7[3]->i_data_p->i_user_data;
  v12 = *(float *)&v7[4]->i_data_p->i_user_data;
  v13 = v7[5]->i_data_p->i_user_data != 0;
  v14 = 1;
  if ( v2->i_update_count )
  {
    if ( v13 )
    {
      v14 = 1;
      if ( UFG::BehaviourControllerComponent::FindBehaviourWithNode(v5, *(const char **)v8->i_user_data) )
        v14 = 0;
    }
  }
  else
  {
    optResult.mId = 0;
    optResult.mDesc = 0i64;
    optResult.mInvokeParams.mNode = 0i64;
    *(_QWORD *)&optResult.mInvokeParams.mPriority = 0i64;
    optResult.mInvokeParams.mControlType = 0;
    optResult.mInvokeParams.mMaxWaitTime = -1.0;
    optResult.mInvokeParams.mMaxLifeTime = -1.0;
    optResult.mInvokeParams.mIsRootInvoke = 1;
    _mm_store_si128((__m128i *)&optResult.mInvokeParams.mInvokeTask, (__m128i)0i64);
    ActionPath::Append(&absolutePath, *(const char **)v8->i_user_data);
    v15 = ActionNode::Find(&absolutePath, 0i64);
    if ( v15 )
    {
      params.mNode = v15;
      *(_QWORD *)&params.mPriority = 0i64;
      params.mMaxWaitTime = -1.0;
      params.mMaxLifeTime = -1.0;
      params.mIsRootInvoke = 1;
      params.mInvokeTask = 0i64;
      params.mControlType = 1;
      params.mPriorityMode = UFG::BehaviourControllerComponent::GetInvokePriorityModeFromString(*(const char **)v10->i_user_data);
      params.mPriority = v9;
      params.mMaxLifeTime = v12;
      params.mMaxWaitTime = v11;
      params.mIsRootInvoke = 1;
      params.mInvokeTask = 0i64;
      if ( (signed int)UFG::BehaviourControllerComponent::InvokeBehaviour(v6, &params, &optResult) >= 1 )
      {
        v14 = 1;
        if ( v13 )
          v14 = 0;
      }
    }
    else
    {
      optResult.mId = -3;
      optResult.mDesc = "Couldnt find behaviour node.";
      optResult.mBehaviour = 0i64;
    }
    UFG::InvokeBehaviourResult::ToString(&optResult, (UFG::qString *)&params);
    v16 = *(const char **)&params.mMaxLifeTime;
    v17 = -1i64;
    do
      ++v17;
    while ( *(_BYTE *)(*(_QWORD *)&params.mMaxLifeTime + v17) );
    v18 = AMemory::c_req_byte_size_func(v17 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v16, v17, v18, 1u, 0, 1);
    ADebug::print(&str, 1);
    v19 = str.i_str_ref_p;
    v20 = str.i_str_ref_p->i_ref_count == 1;
    --v19->i_ref_count;
    if ( v20 )
    {
      if ( v19->i_deallocate )
        AMemory::c_free_func(v19->i_cstr_p);
      v21 = AStringRef::get_pool();
      v22 = v21->i_block_p;
      v23 = (unsigned __int64)v22->i_objects_a;
      if ( (unsigned __int64)v19 < v23
        || (v24 = (unsigned __int64)v19 < v23 + 24i64 * v22->i_size, v25 = &v21->i_pool, !v24) )
      {
        v25 = &v21->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v25, v19);
    }
    UFG::qString::~qString((UFG::qString *)&params);
    v26 = absolutePath.mPath.mCount;
    if ( absolutePath.mPath.mCount >= 0 )
    {
      if ( absolutePath.mPath.mData.mOffset )
      {
        if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
        {
          operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
          v26 = absolutePath.mPath.mCount;
        }
      }
      absolutePath.mPath.mData.mOffset = 0i64;
      absolutePath.mPath.mCount = v26 & 0x80000000;
    }
  }
  return v14;
}

// File Line: 4604
// RVA: 0x4F9280
void __fastcall UFG::TSActor::Mthd_end_aibehaviour(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSActor *v3; // rax
  UFG::SimObjectCVBase *v4; // rcx
  SSInvokedMethod *v5; // rbx
  unsigned __int16 v6; // r8
  UFG::BehaviourControllerComponent *v7; // rax

  v3 = this;
  v4 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v5 = pScope;
  if ( v4 && !(v3->i_actor_flags & 0x10000) )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(v4);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v4->vfptr,
                                                    UFG::BehaviourControllerComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v4->vfptr,
                                                    UFG::BehaviourControllerComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::BehaviourControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v4->vfptr,
                                                    UFG::BehaviourControllerComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(v4);
    }
    if ( v7 )
      UFG::BehaviourControllerComponent::EndBehaviour(
        v7,
        *(const char **)(*v5->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4621
// RVA: 0x5105C0
void __fastcall UFG::TSAIStimulusType_MthdC_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSInstance *v3; // rcx
  SSClass *v4; // rbp
  signed int v5; // esi
  char *v6; // r14
  AStringRef *v7; // rax
  __int64 v8; // rbx
  char *v9; // rcx
  char *v10; // rdx
  ASymbol *v11; // rax
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // r9
  unsigned int v15; // er10
  unsigned int **v16; // rax
  unsigned int v17; // er8
  _BOOL8 v18; // r8
  unsigned int *v19; // rdi
  AObjReusePool<SSInstance> *v20; // rax
  AObjReusePool<SSInstance> *v21; // rbx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  __int64 v25; // rcx
  SSInstance **v26; // rax
  unsigned int v27; // eax
  SSInstance *v28; // rbx
  _DWORD *v29; // rcx
  bool v30; // zf
  SSInstance *v31; // rax
  AStringRef *v32; // rbx
  AObjReusePool<AStringRef> *v33; // rax
  AObjBlock<AStringRef> *v34; // rcx
  unsigned __int64 v35; // rdx
  bool v36; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v37; // rcx
  char buffer_p; // [rsp+40h] [rbp-128h]
  ASymbol result; // [rsp+170h] [rbp+8h]
  AString str; // [rsp+180h] [rbp+18h]

  v2 = pScope;
  v3 = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = SSInstance::get_key_class(v3);
  v5 = 0;
  AString::AString(&str, &buffer_p, 0x100u, 0, 0);
  v6 = (char *)&unk_1423BF9A8;
  do
  {
    AString::set_cstr(&str, (const char *)(*(_QWORD *)v6 + 10i64), 0xFFFFFFFF, 1);
    v7 = str.i_str_ref_p;
    v8 = str.i_str_ref_p->i_length;
    if ( (_DWORD)v8 )
    {
      if ( str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::make_writeable(&str);
        v7 = str.i_str_ref_p;
      }
      v9 = v7->i_cstr_p;
      v10 = &v7->i_cstr_p[v8];
      if ( v7->i_cstr_p < v10 )
      {
        do
        {
          *v9 = AString::c_char2lower[(unsigned __int8)*v9];
          ++v9;
        }
        while ( v9 < v10 );
      }
    }
    v11 = ASymbol::create(&result, &str, 0);
    v12 = v4->i_class_data.i_count;
    if ( !(_DWORD)v12 )
      goto LABEL_33;
    v13 = (signed __int64)v4->i_class_data.i_array_p;
    v14 = v13 + 8 * (v12 - 1);
    v15 = v11->i_uid;
    while ( 1 )
    {
      v16 = (unsigned int **)(v13 + 8 * ((v14 - v13) >> 4));
      v17 = **v16;
      if ( v15 < v17 )
        goto LABEL_17;
      v18 = v15 != v17;
      if ( !v18 )
        break;
      if ( v18 < 0 )
      {
LABEL_17:
        if ( (unsigned int **)v13 == v16 )
          goto LABEL_33;
        v14 = (signed __int64)(v16 - 1);
      }
      else
      {
        if ( (unsigned int **)v14 == v16 )
          goto LABEL_33;
        v13 = (signed __int64)(v16 + 1);
      }
    }
    v19 = *v16;
    if ( *v16 )
    {
      v20 = SSInstance::get_pool();
      v21 = v20;
      v22 = v20->i_pool.i_count;
      if ( v22 )
      {
        v27 = v22 - 1;
        v21->i_pool.i_count = v27;
        v25 = v27;
        v26 = v21->i_pool.i_array_p;
LABEL_26:
        v28 = v26[v25];
      }
      else
      {
        if ( !v21->i_exp_pool.i_count )
          AObjReusePool<SSInstance>::append_block(v21, v21->i_expand_size);
        v23 = v21->i_exp_pool.i_count;
        if ( v23 )
        {
          v24 = v23 - 1;
          v21->i_exp_pool.i_count = v24;
          v25 = v24;
          v26 = v21->i_exp_pool.i_array_p;
          goto LABEL_26;
        }
        v28 = 0i64;
      }
      v28->i_class_p = v4;
      v28->i_user_data = (unsigned int)v5;
      v28->i_ref_count = 1;
      v28->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
      ++v28->i_ref_count;
      v29 = (_DWORD *)*((_QWORD *)v19 + 2);
      v30 = v29[4]-- == 1;
      if ( v30 )
      {
        v29[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v29 + 112i64))();
      }
      *((_QWORD *)v19 + 2) = v28;
      v31 = UFG::gpAIStimulusTypeClass_none;
      if ( !v5 )
        v31 = v28;
      UFG::gpAIStimulusTypeClass_none = v31;
    }
LABEL_33:
    ++v5;
    v6 += 72;
  }
  while ( v5 < 116 );
  v32 = str.i_str_ref_p;
  v30 = str.i_str_ref_p->i_ref_count == 1;
  --v32->i_ref_count;
  if ( v30 )
  {
    if ( v32->i_deallocate )
      AMemory::c_free_func(v32->i_cstr_p);
    v33 = AStringRef::get_pool();
    v34 = v33->i_block_p;
    v35 = (unsigned __int64)v34->i_objects_a;
    if ( (unsigned __int64)v32 < v35
      || (v36 = (unsigned __int64)v32 < v35 + 24i64 * v34->i_size, v37 = &v33->i_pool, !v36) )
    {
      v37 = &v33->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v37, v32);
  }
}

// File Line: 4663
// RVA: 0x1536440
__int64 UFG::_dynamic_initializer_for__gTSPhysicalActor_singleExclude__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__gTSPhysicalActor_singleExclude__);
}

// File Line: 4673
// RVA: 0x4E0E60
APArray<SSActor,SSActor,ACompareAddress<SSActor> > *__fastcall UFG::TSActor::GetArgAutoList(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSActor *v2; // rdx

  v2 = (SSActor *)pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( !v2 || v2 == (SSActor *)SSBrain::c_nil_p )
    return 0i64;
  if ( v2->i_class_p == SSBrain::c_list_class_p )
    return (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v2->i_user_data;
  UFG::gTSPhysicalActor_singleExclude.i_count = 0;
  APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v2);
  return &UFG::gTSPhysicalActor_singleExclude;
}

// File Line: 4703
// RVA: 0x4F6130
void __fastcall UFG::TSActor::Mthd_begin_stimulus_one_off_internal(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  UFG::eStimulusType v4; // eax
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v4 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 0;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v4, &stimulus_parameters, v3);
    }
  }
}

// File Line: 4723
// RVA: 0x4F5FE0
void __fastcall UFG::TSActor::Mthd_begin_stimulus_duration_internal(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdi
  SSData **v4; // rcx
  SSInstance *v5; // rbx
  UFG::eStimulusType v6; // eax
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v4 = pScope->i_data.i_array_p;
      v5 = v4[1]->i_data_p;
      v6 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*v4)->i_data_p->i_user_data);
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 1;
      stimulus_parameters.m_MaxStimulusDuration = *(float *)&v5->i_user_data;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v6, &stimulus_parameters, v3);
    }
  }
}

// File Line: 4744
// RVA: 0x4F60A0
void __fastcall UFG::TSActor::Mthd_begin_stimulus_internal(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  UFG::eStimulusType v4; // eax
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v4 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 1;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v4, &stimulus_parameters, v3);
    }
  }
}

// File Line: 4763
// RVA: 0x4F9340
void __fastcall UFG::TSActor::Mthd_end_stimulus_internal(UFG::TSActor *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  UFG::eStimulusType v4; // eax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v4 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v4, v3);
    }
  }
}

// File Line: 4781
// RVA: 0x4EA900
void __fastcall UFG::TSActor::MthdC_list_convert(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInvokedMethod *v3; // r9
  SSInstance *v4; // r15
  unsigned int *v5; // rbx
  __int64 v6; // rbp
  SSInstance *v7; // rcx
  SSClass *v8; // rax
  UFG::TSActor **v9; // rsi
  unsigned __int64 v10; // r13
  SSClass *v11; // r12
  UFG::TSActor **v12; // r14
  UFG::TSActor *v13; // rdi
  UFG::TSActor *v14; // rbx
  SSClass *v15; // rax
  UFG::TSActor *v16; // rax
  SSClass *v17; // rcx
  bool v18; // zf
  unsigned int *v19; // [rsp+60h] [rbp+8h]
  SSInstance **v20; // [rsp+68h] [rbp+10h]

  v20 = ppResult;
  v2 = ppResult;
  v3 = pScope;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  v5 = (unsigned int *)v4->i_user_data;
  v19 = v5;
  v6 = *v5;
  if ( (_DWORD)v6 )
  {
    v7 = (SSInstance *)pScope->i_scope_p.i_obj_p;
    if ( !v7 || v3->i_scope_p.i_ptr_id != v7->i_ptr_id )
      v7 = 0i64;
    v8 = SSInstance::get_key_class(v7);
    v9 = (UFG::TSActor **)*((_QWORD *)v5 + 1);
    v10 = (unsigned __int64)&v9[v6];
    v11 = v8;
    v12 = (UFG::TSActor **)*((_QWORD *)v5 + 1);
    if ( (unsigned __int64)v9 < v10 )
    {
      while ( 1 )
      {
        v13 = *v9;
        v14 = *v9;
        if ( !*v9 )
          goto LABEL_23;
        v15 = v13->i_class_p;
        if ( v15 == SSBrain::c_symbol_class_p )
          break;
        if ( v15 == UFG::TSSimObject::mspSimObjectClass )
        {
          v16 = UFG::TSActor::FromSimObject((UFG::SimObject *)v13->i_user_data);
LABEL_11:
          v14 = v16;
          if ( v16 )
            v15 = v16->i_class_p;
          else
            v15 = 0i64;
        }
        if ( v15 )
        {
          if ( v11 == v15 || (v17 = v15->i_superclass_p) != 0i64 && SSClass::is_class(v17, v11) )
          {
            if ( v14 )
            {
              if ( v14 != v13 )
              {
                *v12 = v14;
                ++v14->i_ref_count;
                v18 = v13->i_ref_count-- == 1;
                if ( v18 )
                {
                  v13->i_ref_count = 2147483648;
                  v13->vfptr[1].get_scope_context((SSObjectBase *)&v13->vfptr);
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
        ++v9;
        if ( (unsigned __int64)v9 >= v10 )
        {
          v5 = v19;
          v2 = v20;
          goto LABEL_26;
        }
      }
      v16 = (UFG::TSActor *)SSActor::find((ASymbol *)&v13->i_user_data);
      goto LABEL_11;
    }
LABEL_26:
    *v5 = v6;
  }
  if ( v2 )
  {
    ++v4->i_ref_count;
    *v2 = v4;
  }
}

// File Line: 4842
// RVA: 0x510B40
void __fastcall UFG::TSPhysicalActor_MthdC_list_collect_near_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSInvokedMethod *v3; // rsi
  SSData **v4; // r9
  UFG::qVector3 *v5; // rbp
  float v6; // xmm6_4
  SSActor *v7; // rdx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *pExclusions; // rbx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v9; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v10; // rdi
  SSInstance *v11; // rcx
  SSActorClass *v12; // rax
  __int64 v13; // rax
  ARefCountMix<SSInstance> **v14; // rbx
  unsigned __int64 i; // rsi

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = pScope->i_data.i_array_p;
    v5 = (UFG::qVector3 *)(*v4)->i_data_p->i_user_data;
    v6 = *(float *)&v4[1]->i_data_p->i_user_data;
    v7 = (SSActor *)v4[2]->i_data_p;
    if ( v7 && v7 != (SSActor *)SSBrain::c_nil_p )
    {
      if ( v7->i_class_p == SSBrain::c_list_class_p )
      {
        pExclusions = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v7->i_user_data;
      }
      else
      {
        UFG::gTSPhysicalActor_singleExclude.i_count = 0;
        pExclusions = &UFG::gTSPhysicalActor_singleExclude;
        APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v7);
      }
    }
    else
    {
      pExclusions = 0i64;
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
    v11 = (SSInstance *)v3->i_scope_p.i_obj_p;
    if ( !v11 || v3->i_scope_p.i_ptr_id != v11->i_ptr_id )
      v11 = 0i64;
    v12 = (SSActorClass *)SSInstance::get_key_class(v11);
    UFG::TSActor::ListCollectNear(v10, v5, v6, v12, pExclusions);
    v13 = v10->i_count;
    if ( (_DWORD)v13 )
    {
      v14 = (ARefCountMix<SSInstance> **)v10->i_array_p;
      for ( i = (unsigned __int64)&v14[v13]; (unsigned __int64)v14 < i; ++v14 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v14 + 4);
    }
    *v2 = SSList::as_instance((SSList *)v10);
  }
}

// File Line: 4872
// RVA: 0x510A00
void __fastcall UFG::TSPhysicalActor_MthdC_is_class_inside_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r12
  SSInvokedMethod *v3; // rbx
  bool v4; // r15
  UFG::qBaseNodeRB *v5; // rsi
  SSInstance *v6; // rdx
  SSClass *v7; // rdi
  __int64 v8; // rbp
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v9; // rax
  SSActor **v10; // rdi
  UFG::RegionComponent *v11; // r13
  unsigned __int64 v12; // rsi
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v13; // r14
  SSActor *v14; // rbx
  unsigned int v15; // edx
  SSActor **v16; // rax
  unsigned __int64 i; // r8
  SSClass *v18; // rbx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = 0;
    v5 = UFG::TSTriggerRegion::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
    if ( v5 )
    {
      v6 = (SSInstance *)v3->i_scope_p.i_obj_p;
      if ( !v6 || v3->i_scope_p.i_ptr_id != v6->i_ptr_id )
        v6 = 0i64;
      v7 = SSInstance::get_key_class(v6);
      v8 = LODWORD(v7[1].vfptr);
      if ( (_DWORD)v8 )
      {
        v9 = UFG::TSActor::GetArgAutoList((SSInvokedContextBase *)&v3->vfptr, 1u);
        v10 = *(SSActor ***)&v7[1].i_name.i_uid;
        v11 = *(UFG::RegionComponent **)&v5[6].mUID;
        v12 = (unsigned __int64)&v10[v8];
        v13 = v9;
        if ( (unsigned __int64)v10 < v12 )
        {
          while ( 1 )
          {
            v14 = *v10;
            if ( v13 )
            {
              v15 = 0;
              if ( v13->i_count )
              {
                v16 = v13->i_array_p;
                for ( i = (unsigned __int64)&v16[v13->i_count - 1]; (unsigned __int64)v16 <= i; ++v16 )
                {
                  if ( v14 == *v16 )
                  {
                    if ( v15 < 2 )
                      goto LABEL_17;
                    --v15;
                  }
                }
              }
            }
            v18 = v14[1].i_class_p;
            if ( v18 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v18);
              if ( UFG::RegionComponent::IsHitPoint(v11, (UFG::qVector3 *)&v18->i_class_data.i_array_p) )
                break;
            }
LABEL_17:
            ++v10;
            if ( (unsigned __int64)v10 >= v12 )
              goto LABEL_20;
          }
          v4 = 1;
        }
      }
    }
LABEL_20:
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 4929
// RVA: 0x510CA0
void __fastcall UFG::TSPhysicalActor_MthdC_list_collect_trigger_inside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInvokedMethod *v3; // rbx
  UFG::qBaseNodeRB *v4; // r15
  SSList *v5; // rax
  SSList *v6; // r14
  SSInstance *v7; // rcx
  SSClass *v8; // rdi
  __int64 v9; // rbp
  SSActor *v10; // rdx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v11; // rsi
  UFG::RegionComponent *v12; // r15
  SSActor **v13; // rbx
  unsigned __int64 i; // rbp
  SSActor *v15; // rdi
  unsigned int v16; // edx
  SSActor **v17; // rax
  unsigned __int64 j; // r8
  SSClass *v19; // rdi
  __int64 v20; // rax
  ARefCountMix<SSInstance> **v21; // rbx
  unsigned __int64 k; // rdi

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = UFG::TSTriggerRegion::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
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
    *v2 = SSList::as_instance(v6);
    if ( v4 )
    {
      v7 = (SSInstance *)v3->i_scope_p.i_obj_p;
      if ( !v7 || v3->i_scope_p.i_ptr_id != v7->i_ptr_id )
        v7 = 0i64;
      v8 = SSInstance::get_key_class(v7);
      v9 = LODWORD(v8[1].vfptr);
      if ( (_DWORD)v9 )
      {
        v10 = *(SSActor **)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64);
        if ( v10 && v10 != (SSActor *)SSBrain::c_nil_p )
        {
          if ( v10->i_class_p == SSBrain::c_list_class_p )
          {
            v11 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v10->i_user_data;
          }
          else
          {
            UFG::gTSPhysicalActor_singleExclude.i_count = 0;
            v11 = &UFG::gTSPhysicalActor_singleExclude;
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v10);
          }
        }
        else
        {
          v11 = 0i64;
        }
        v12 = *(UFG::RegionComponent **)&v4[6].mUID;
        v13 = *(SSActor ***)&v8[1].i_name.i_uid;
        for ( i = (unsigned __int64)&v13[v9]; (unsigned __int64)v13 < i; ++v13 )
        {
          v15 = *v13;
          if ( v11 )
          {
            v16 = 0;
            if ( v11->i_count )
            {
              v17 = v11->i_array_p;
              for ( j = (unsigned __int64)&v17[v11->i_count - 1]; (unsigned __int64)v17 <= j; ++v17 )
              {
                if ( v15 == *v17 )
                {
                  if ( v16 < 2 )
                    goto LABEL_27;
                  --v16;
                }
              }
            }
          }
          v19 = v15[1].i_class_p;
          if ( v19 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v19);
            if ( UFG::RegionComponent::IsHitPoint(v12, (UFG::qVector3 *)&v19->i_class_data.i_array_p) )
              APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(
                (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v6,
                *v13);
          }
LABEL_27:
          ;
        }
        v20 = v6->i_items.i_count;
        if ( (_DWORD)v20 )
        {
          v21 = (ARefCountMix<SSInstance> **)v6->i_items.i_array_p;
          for ( k = (unsigned __int64)&v21[v20]; (unsigned __int64)v21 < k; ++v21 )
            UFG::PersistentData::MapFloat::Iterator::Next(*v21 + 4);
        }
      }
    }
  }
}

// File Line: 4989
// RVA: 0x510E80
void __fastcall UFG::TSPhysicalActor_MthdC_list_collect_trigger_outside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInvokedMethod *v3; // rbx
  UFG::qBaseNodeRB *v4; // r15
  SSList *v5; // rax
  SSList *v6; // r14
  SSInstance *v7; // rcx
  SSClass *v8; // rdi
  __int64 v9; // rbp
  SSActor *v10; // rdx
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v11; // rsi
  UFG::RegionComponent *v12; // r15
  SSActor **v13; // rbx
  unsigned __int64 i; // rbp
  SSActor *v15; // rdi
  unsigned int v16; // edx
  SSActor **v17; // rax
  unsigned __int64 j; // r8
  SSClass *v19; // rdi
  __int64 v20; // rax
  ARefCountMix<SSInstance> **v21; // rbx
  unsigned __int64 k; // rdi

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = UFG::TSTriggerRegion::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
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
    *v2 = SSList::as_instance(v6);
    if ( v4 )
    {
      v7 = (SSInstance *)v3->i_scope_p.i_obj_p;
      if ( !v7 || v3->i_scope_p.i_ptr_id != v7->i_ptr_id )
        v7 = 0i64;
      v8 = SSInstance::get_key_class(v7);
      v9 = LODWORD(v8[1].vfptr);
      if ( (_DWORD)v9 )
      {
        v10 = *(SSActor **)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64);
        if ( v10 && v10 != (SSActor *)SSBrain::c_nil_p )
        {
          if ( v10->i_class_p == SSBrain::c_list_class_p )
          {
            v11 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v10->i_user_data;
          }
          else
          {
            UFG::gTSPhysicalActor_singleExclude.i_count = 0;
            v11 = &UFG::gTSPhysicalActor_singleExclude;
            APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v10);
          }
        }
        else
        {
          v11 = 0i64;
        }
        v12 = *(UFG::RegionComponent **)&v4[6].mUID;
        v13 = *(SSActor ***)&v8[1].i_name.i_uid;
        for ( i = (unsigned __int64)&v13[v9]; (unsigned __int64)v13 < i; ++v13 )
        {
          v15 = *v13;
          if ( v11 )
          {
            v16 = 0;
            if ( v11->i_count )
            {
              v17 = v11->i_array_p;
              for ( j = (unsigned __int64)&v17[v11->i_count - 1]; (unsigned __int64)v17 <= j; ++v17 )
              {
                if ( v15 == *v17 )
                {
                  if ( v16 < 2 )
                    goto LABEL_27;
                  --v16;
                }
              }
            }
          }
          v19 = v15[1].i_class_p;
          if ( v19 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v19);
            if ( !UFG::RegionComponent::IsHitPoint(v12, (UFG::qVector3 *)&v19->i_class_data.i_array_p) )
              APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(
                (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v6,
                *v13);
          }
LABEL_27:
          ;
        }
        v20 = v6->i_items.i_count;
        if ( (_DWORD)v20 )
        {
          v21 = (ARefCountMix<SSInstance> **)v6->i_items.i_array_p;
          for ( k = (unsigned __int64)&v21[v20]; (unsigned __int64)v21 < k; ++v21 )
            UFG::PersistentData::MapFloat::Iterator::Next(*v21 + 4);
        }
      }
    }
  }
}

// File Line: 5050
// RVA: 0x511060
void __fastcall UFG::TSPhysicalActor_MthdC_list_refine_near_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSInvokedMethod *v3; // r9
  SSData **v4; // rcx
  SSInstance *v5; // rbx
  UFG::qVector3 *v6; // r14
  float v7; // xmm6_4
  SSList *v8; // rdi
  SSInstance *v9; // rcx
  APArrayBase<SSActor> *v10; // rbp
  SSList *v11; // rax
  bool v12; // zf

  v2 = ppResult;
  v3 = pScope;
  v4 = pScope->i_data.i_array_p;
  v5 = v4[2]->i_data_p;
  if ( ppResult || v5 != SSBrain::c_nil_p )
  {
    v6 = (UFG::qVector3 *)(*v4)->i_data_p->i_user_data;
    v7 = *(float *)&v4[1]->i_data_p->i_user_data;
    if ( v5->i_class_p == SSBrain::c_list_class_p )
    {
      v8 = (SSList *)v5->i_user_data;
      ++v5->i_ref_count;
    }
    else
    {
      v9 = (SSInstance *)v3->i_scope_p.i_obj_p;
      if ( !v9 || v3->i_scope_p.i_ptr_id != v9->i_ptr_id )
        v9 = 0i64;
      v10 = (APArrayBase<SSActor> *)SSInstance::get_key_class(v9);
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
      v5 = SSList::as_instance(v8);
      APArray<SSActor,SSActor,ACompareAddress<SSActor>>::operator=(
        (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v8,
        v10 + 19);
    }
    UFG::TSActor::ListRefineNear((APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v8, v6, v7);
    if ( v2 )
    {
      *v2 = v5;
    }
    else
    {
      v12 = v5->i_ref_count-- == 1;
      if ( v12 )
      {
        v5->i_ref_count = 2147483648;
        v5->vfptr[1].get_scope_context((SSObjectBase *)&v5->vfptr);
      }
    }
  }
}

// File Line: 5109
// RVA: 0x5111A0
void __fastcall UFG::TSPhysicalActor_MthdC_list_select_nearest_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInstance **v3; // rsi
  SSInvokedMethod *v4; // rdi
  UFG::qVector3 *v5; // rbp
  SSActor *v6; // rdx
  float v7; // xmm6_4
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v8; // rbx
  __int64 v9; // rdx
  APArrayBase<SSActor> *v10; // rax
  SSInstance *v11; // rcx
  SSActor *v12; // rax
  SSInstance *v13; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = pScope;
    v5 = (UFG::qVector3 *)(*v2)->i_data_p->i_user_data;
    v6 = (SSActor *)v2[3]->i_data_p;
    v7 = *(float *)&v2[1]->i_data_p->i_user_data;
    if ( v6 && v6 != (SSActor *)SSBrain::c_nil_p )
    {
      if ( v6->i_class_p == SSBrain::c_list_class_p )
      {
        v8 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)v6->i_user_data;
      }
      else
      {
        v8 = &UFG::gTSPhysicalActor_singleExclude;
        UFG::gTSPhysicalActor_singleExclude.i_count = 0;
        APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(&UFG::gTSPhysicalActor_singleExclude, v6);
      }
    }
    else
    {
      v8 = 0i64;
    }
    v9 = *(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 2) + 8i64);
    if ( *(SSClass **)(v9 + 24) == SSBrain::c_list_class_p )
    {
      v10 = *(APArrayBase<SSActor> **)(v9 + 32);
    }
    else
    {
      v11 = (SSInstance *)v4->i_scope_p.i_obj_p;
      if ( !v11 || v4->i_scope_p.i_ptr_id != v11->i_ptr_id )
        v11 = 0i64;
      v10 = (APArrayBase<SSActor> *)&SSInstance::get_key_class(v11)[1];
    }
    v12 = UFG::TSActor::ListSelectNearest(v10, v5, v7, v8);
    v13 = SSBrain::c_nil_p;
    if ( v12 )
      v13 = (SSInstance *)&v12->vfptr;
    *v3 = v13;
    ++v13->i_ref_count;
  }
}

// File Line: 5164
// RVA: 0x4CCC60
void UFG::TSActor::BindAtomics(void)
{
  SSActorClass *v0; // rcx
  SSActorClass *v1; // rcx
  SSActorClass *v2; // rcx
  SSActorClass *v3; // rcx
  SSActorClass *v4; // rcx
  SSActorClass *v5; // rcx
  SSActorClass *v6; // rcx
  SSActorClass *v7; // rcx
  SSActorClass *v8; // rcx
  SSActorClass *v9; // rcx
  SSActorClass *v10; // rcx
  SSActorClass *v11; // rcx
  SSActorClass *v12; // rcx
  SSActorClass *v13; // rcx
  SSActorClass *v14; // rcx
  SSActorClass *v15; // rcx
  SSActorClass *v16; // rcx
  SSActorClass *v17; // rcx
  SSActorClass *v18; // rcx
  SSActorClass *v19; // rcx
  SSActorClass *v20; // rcx
  SSActorClass *v21; // rcx
  SSActorClass *v22; // rcx
  SSActorClass *v23; // rcx
  SSActorClass *v24; // rcx
  SSActorClass *v25; // rcx
  SSActorClass *v26; // rcx
  SSActorClass *v27; // rcx
  SSActorClass *v28; // rcx
  SSActorClass *v29; // rcx
  SSActorClass *v30; // rcx
  SSActorClass *v31; // rcx
  SSActorClass *v32; // rcx
  SSActorClass *v33; // rcx
  SSActorClass *v34; // rcx
  SSActorClass *v35; // rcx
  SSActorClass *v36; // rcx
  SSActorClass *v37; // rcx
  SSActorClass *v38; // rcx
  SSActorClass *v39; // rcx
  SSActorClass *v40; // rcx
  SSActorClass *v41; // rcx
  SSActorClass *v42; // rcx
  SSActorClass *v43; // rcx
  SSActorClass *v44; // rcx
  SSActorClass *v45; // rcx
  SSActorClass *v46; // rcx
  SSActorClass *v47; // rcx
  SSActorClass *v48; // rcx
  SSActorClass *v49; // rcx
  SSActorClass *v50; // rcx
  SSActorClass *v51; // rcx
  SSActorClass *v52; // rcx
  SSActorClass *v53; // rcx
  SSActorClass *v54; // rcx
  SSActorClass *v55; // rcx
  SSActorClass *v56; // rcx
  SSActorClass *v57; // rcx
  SSActorClass *v58; // rcx
  SSActorClass *v59; // rcx
  SSActorClass *v60; // rcx
  SSActorClass *v61; // rcx
  SSActorClass *v62; // rcx
  SSActorClass *v63; // rcx
  SSActorClass *v64; // rcx
  SSActorClass *v65; // rcx
  SSActorClass *v66; // rcx
  SSActorClass *v67; // rcx
  SSActorClass *v68; // rcx
  SSActorClass *v69; // rcx
  SSActorClass *v70; // rcx
  SSActorClass *v71; // rcx
  SSActorClass *v72; // rcx
  SSActorClass *v73; // rcx
  SSActorClass *v74; // rcx
  SSActorClass *v75; // rcx
  SSActorClass *v76; // rcx
  SSActorClass *v77; // rcx
  SSActorClass *v78; // rcx
  SSActorClass *v79; // rcx
  SSActorClass *v80; // rcx
  SSActorClass *v81; // rcx
  SSActorClass *v82; // rcx
  SSActorClass *v83; // rcx
  SSActorClass *v84; // rcx
  SSActorClass *v85; // rcx
  SSActorClass *v86; // rcx
  SSActorClass *v87; // rcx
  SSActorClass *v88; // rcx
  SSActorClass *v89; // rcx
  SSActorClass *v90; // rcx
  SSActorClass *v91; // rcx
  SSActorClass *v92; // rcx
  SSActorClass *v93; // rcx
  SSActorClass *v94; // rcx
  SSActorClass *v95; // rcx
  SSClass *v96; // rbx
  SSClass *v97; // rax
  SSClass *v98; // rbx
  __m128i v99; // [rsp+30h] [rbp-10h]

  v0 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_SimObject;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v0->vfptr,
    "SimObject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    "list_convert",
    UFG::TSActor::MthdC_list_convert,
    1,
    0);
  v1 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_wait_ai_stimulus;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v1->vfptr,
    "_wait_ai_stimulus",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v2 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_invoke_aibehaviour;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v2->vfptr,
    "_invoke_aibehaviour",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v3 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_end_aibehaviour;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v3->vfptr,
    "end_aibehaviour",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v4 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_suspend;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v4->vfptr,
    "suspend",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v5 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_restore;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v5->vfptr,
    "restore",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v6 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_triad_wars_player_id;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v6->vfptr,
    "set_triad_wars_player_id",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_close_enough_to_marker;
  v99.m128i_i32[2] = 0;
  v7 = SSBrain::c_actor_class_p;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v7->vfptr,
    "is_close_enough_to_marker",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v8 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v8->vfptr,
    "display_debug_marker",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v9 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_begin_stimulus_one_off_internal;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v9->vfptr,
    "begin_stimulus_one_off_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v10 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_begin_stimulus_duration_internal;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v10->vfptr,
    "begin_stimulus_duration_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v11 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_begin_stimulus_internal;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v11->vfptr,
    "begin_stimulus_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v12 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_end_stimulus_internal;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v12->vfptr,
    "end_stimulus_internal",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr,
    "is_class_inside_trigger",
    UFG::TSPhysicalActor_MthdC_is_class_inside_trigger,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr,
    "list_collect_trigger_inside",
    UFG::TSPhysicalActor_MthdC_list_collect_trigger_inside,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr,
    "list_collect_trigger_outside",
    UFG::TSPhysicalActor_MthdC_list_collect_trigger_outside,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr,
    "list_collect_near_pos",
    UFG::TSPhysicalActor_MthdC_list_collect_near_pos,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr,
    "list_refine_near_pos",
    UFG::TSPhysicalActor_MthdC_list_refine_near_pos,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr,
    "list_select_nearest_pos",
    UFG::TSPhysicalActor_MthdC_list_select_nearest_pos,
    1,
    0);
  v13 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_was_hit_by_vehicle;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v13->vfptr,
    "was_hit_by_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v14 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_was_shot;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v14->vfptr,
    "was_shot",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v15 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_has_hit_object;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v15->vfptr,
    "has_hit_object",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v16 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_has_hit_static_object;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v16->vfptr,
    "has_hit_static_object",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v17 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_are_resources_loaded;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v17->vfptr,
    "are_resources_loaded",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v18 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_spawn_priority;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v18->vfptr,
    "get_spawn_priority",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v19 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_inc_spawn_priority_ref;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v19->vfptr,
    "inc_spawn_priority_ref",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v20 = SSBrain::c_physical_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_dec_spawn_priority_ref;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v20->vfptr,
    "dec_spawn_priority_ref",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    &ASymbol_find_named,
    UFG::TSActor::MthdC_find_named,
    SSBindFlag_class_rebind);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    "find_instance",
    UFG::TSActor::MthdC_find_instance,
    SSBindFlag_class_rebind);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    "get_instance",
    UFG::TSActor::MthdC_get_instance,
    SSBindFlag_class_rebind);
  v21 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_despawn;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v21->vfptr,
    "despawn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v22 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_enable_physics;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v22->vfptr,
    "enable_physics",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v23 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_has_fractured_parts;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v23->vfptr,
    "has_fractured_parts",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v24 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_valid_simobject;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v24->vfptr,
    "is_valid_simobject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v25 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_valid_simproxy;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v25->vfptr,
    "is_valid_simproxy",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_dir;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    "get_dir",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v26 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_dir_back;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v26->vfptr,
    "get_dir_back",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v27 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_dir_right;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v27->vfptr,
    "get_dir_right",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v28 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_dir_left;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v28->vfptr,
    "get_dir_left",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v29 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_dir_up;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v29->vfptr,
    "get_dir_up",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v30 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_dir_down;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v30->vfptr,
    "get_dir_down",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v31 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_pos;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v31->vfptr,
    "get_pos",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v32 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_properties;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v32->vfptr,
    "get_properties",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_archetype_properties;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    "get_archetype_properties",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v33 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_xform;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v33->vfptr,
    "get_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v34 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_teleport_dir;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v34->vfptr,
    "teleport_dir",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v35 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_teleport_pos;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v35->vfptr,
    "teleport_pos",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v36 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_teleport_pos_preserve_vel;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v36->vfptr,
    "teleport_pos_preserve_vel",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v37 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_teleport_xform;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v37->vfptr,
    "teleport_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v38 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_teleport_xform_preserve_vel;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v38->vfptr,
    "teleport_xform_preserve_vel",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v39 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_last_teleport_frame;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v39->vfptr,
    "get_last_teleport_frame",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_in_view;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    "is_in_view",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v40 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_reset_follow_camera;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v40->vfptr,
    "reset_follow_camera",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v41 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_rim_boost;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v41->vfptr,
    "get_rim_boost",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v42 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v42->vfptr,
    "set_rim_boost",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v43 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_highlighted;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v43->vfptr,
    "is_highlighted",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v44 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_is_highlighted;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v44->vfptr,
    "enable_highlight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v45 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_action_tree_query;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v45->vfptr,
    "action_tree_query",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v46 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_playing_node;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v46->vfptr,
    "is_playing_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v47 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_playing_full_path_node;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v47->vfptr,
    "is_playing_full_path_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v48 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_playing_ai_node;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v48->vfptr,
    "is_playing_ai_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v49 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_playing_full_path_ai_node;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v49->vfptr,
    "is_playing_full_path_ai_node",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v50 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_action_tree_opening_branch;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v50->vfptr,
    "set_action_tree_opening_branch",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v51 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_dbg_get_playing_full_path;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v51->vfptr,
    "dbg_get_playing_full_path",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v52 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_load_facefx_actor;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v52->vfptr,
    "load_facefx_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v53 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_play_facial_anim;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v53->vfptr,
    "play_facial_anim",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v54 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_unmount_facial_animset;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v54->vfptr,
    "mount_facial_animset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v55 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_unload_facefx_actor;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v55->vfptr,
    "unload_facefx_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v56 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_unmount_facial_animset;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v56->vfptr,
    "unmount_facial_animset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v57 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_pwr_suspend_allow;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v57->vfptr,
    "pwr_suspend_allow",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v58 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_pwr_suspend_prevent;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v58->vfptr,
    "pwr_suspend_prevent",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v59 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_animate;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v59->vfptr,
    "_animate",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v60 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_attach_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v60->vfptr,
    "attach_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v61 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_detach_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v61->vfptr,
    "detach_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v62 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_attach;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v62->vfptr,
    "attach",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v63 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_detach;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v63->vfptr,
    "detach",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v64 = SSBrain::c_actor_class_p;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_clear_target;
  v99.m128i_i32[2] = 0;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v64->vfptr,
    "clear_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v65 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v65->vfptr,
    "get_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v66 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_target_as_simobject;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v66->vfptr,
    "get_target_as_simobject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v67 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v67->vfptr,
    "set_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v68 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_target_lock;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v68->vfptr,
    "set_target_lock",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v69 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_target_prop;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v69->vfptr,
    "set_target_prop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v70 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_subtarget;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v70->vfptr,
    "set_subtarget",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v71 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_attack_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v71->vfptr,
    "set_attack_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_target_valid;
  v72 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v72->vfptr,
    "is_target_valid",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v73 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_target_locked;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v73->vfptr,
    "is_target_locked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v74 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_inventory_item;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v74->vfptr,
    "get_inventory_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v75 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_best_interaction_point;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v75->vfptr,
    "set_best_interaction_point",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v76 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_is_best_interaction_point_busy;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v76->vfptr,
    "is_best_interaction_point_busy",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v77 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_interaction_point_active;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v77->vfptr,
    "set_interaction_point_active",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v78 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_minimap_add_blip;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v78->vfptr,
    "minimap_add_blip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v79 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_minimap_remove_blip;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v79->vfptr,
    "minimap_remove_blip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_audio_event;
  v99.m128i_i32[2] = 0;
  v80 = SSBrain::c_actor_class_p;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v80->vfptr,
    "audio_event",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v81 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_audio_override_tagged_dialogue;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v81->vfptr,
    "audio_override_tagged_dialogue",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v82 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_audio_force_disable;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v82->vfptr,
    "audio_force_disable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v83 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_audio_force_init;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v83->vfptr,
    "audio_force_init",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v84 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_stop_speech;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v84->vfptr,
    "stop_speech",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v85 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_audio_set_obstruction_occlusion;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v85->vfptr,
    "audio_set_obstruction_occlusion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v86 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_facial_emotion;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v86->vfptr,
    "set_facial_emotion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v87 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v87->vfptr,
    "_audio_dialogue",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_wait_until_done_speaking;
  v99.m128i_i32[2] = 0;
  v88 = SSBrain::c_actor_class_p;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v88->vfptr,
    "_wait_until_done_speaking",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v89 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_audio_event;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v89->vfptr,
    "_audio_event",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v90 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_audio_dialogue_external_filename;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v90->vfptr,
    "_audio_dialogue_external_filename",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v91 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_audio_dialogue_external_context;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v91->vfptr,
    "_audio_dialogue_external_context",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v92 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Coro_wait_until_fight_over;
  _mm_store_si128(&v99, v99);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v92->vfptr,
    "_wait_until_fight_over",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v99,
    0);
  v93 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_fail_trigger;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v93->vfptr,
    "set_fail_trigger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v94 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_fail_threshold;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v94->vfptr,
    "set_fail_threshold",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v95 = SSBrain::c_actor_class_p;
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_fail_caption;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    (SSClass *)&v95->vfptr,
    "set_fail_caption",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v96 = SSBrain::get_class("Weapon");
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_health;
  v99.m128i_i32[2] = 0;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v96,
    "get_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_owner;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v96,
    "get_owner",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v97 = SSBrain::get_class("Firearm");
  v99.m128i_i32[2] = 0;
  v98 = v97;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_if_reset_ammo_on_death;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v97,
    "set_if_reset_ammo_on_death",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_override_rate_of_fire;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "override_rate_of_fire",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_fire_mode;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "set_fire_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_fire_mode;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "get_fire_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_total_ammo;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "set_total_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_total_ammo;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "get_total_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_clip_ammo;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "set_clip_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_clip_ammo;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "get_clip_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_add_clip_to_gun;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "add_clip_to_gun",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_set_must_hit_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "set_must_hit_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_clear_must_hit_target;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "clear_must_hit_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  v99.m128i_i32[2] = 0;
  v99.m128i_i64[0] = (__int64)UFG::TSActor::Mthd_get_weapon_type;
  _mm_store_si128(&v99, v99);
  SSClass::register_method_mthd(
    v98,
    "get_weapon_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v99,
    0);
  UFG::gpAIStimulusTypeClass = SSBrain::get_class("AIStimulusType");
  SSClass::register_method_func(UFG::gpAIStimulusTypeClass, &ASymbolX_ctor, UFG::TSAIStimulusType_MthdC_ctor, 1, 0);
}

// File Line: 5364
// RVA: 0x50F180
void UFG::TSActor::PostFrameCleanup(void)
{
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v0; // rbx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v1; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v2; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v3; // rbx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v4; // rdx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v5; // rax
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v6; // r8
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *i; // rdx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v8; // rcx
  UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *v9; // rax

  v0 = UFG::StimulusNotifyScript::smActiveList.mNode.mNext - 3;
  while ( v0 != (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)&A_cos_355_deg_31 )
  {
    v1 = v0[4].mPrev;
    if ( v1 && LODWORD(v0[4].mNext) == LODWORD(v1->mNext) )
    {
      v0 = v0[3].mNext - 3;
    }
    else
    {
      v2 = v0;
      v3 = v0[3].mNext;
      v4 = v2[3].mPrev;
      v5 = v2[3].mNext;
      v6 = v2 + 3;
      v4->mNext = v5;
      v5->mPrev = v4;
      v6->mPrev = v6;
      v6->mNext = v6;
      v0 = v3 - 3;
      ((void (__fastcall *)(UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *, signed __int64))v2->mPrev->mPrev)(
        v2,
        1i64);
    }
  }
  for ( i = UFG::StimulusNotifyScript::smDeleteList.mNode.mNext;
        (const float *)&UFG::StimulusNotifyScript::smDeleteList.mNode.mNext[-3] != &A_cos_335_deg_31;
        i = UFG::StimulusNotifyScript::smDeleteList.mNode.mNext )
  {
    v8 = i->mPrev;
    v9 = i->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *)48 )
      ((void (__fastcall *)(UFG::qNode<UFG::StimulusNotifyScript,UFG::StimulusNotifyScript> *, signed __int64))i[-3].mPrev->mPrev)(
        &i[-3],
        1i64);
  }
}

// File Line: 5393
// RVA: 0x50F3F0
void __fastcall UFG::TSActor::RayCastToTargetAsyncRayCallback(UFG::RayCastData *raycastData, UFG::SimComponent *simComponent, void *callbackUserData)
{
  SSInvokedContextBase *v3; // rbx
  bool v4; // si
  UFG::SimComponent *v5; // rdi
  UFG::RayCastData *v6; // rbp
  UFG::qBaseNodeRB *v7; // rax
  SSData *v8; // rdx
  SSInstance *v9; // rax
  UFG::SimObject *ray_hit_object; // [rsp+40h] [rbp+18h]

  v3 = *(SSInvokedContextBase **)callbackUserData;
  v4 = 0;
  v5 = simComponent;
  v6 = raycastData;
  if ( !*(_QWORD *)callbackUserData || *((_DWORD *)callbackUserData + 2) != v3->i_ptr_id )
    v3 = 0i64;
  operator delete[](callbackUserData);
  if ( v3 )
  {
    if ( v5 )
    {
      v7 = UFG::TSSimObject::GetArgByNameOrInstance(v3, 1u);
      ray_hit_object = 0i64;
      v4 = UFG::TargetIsVisible(v6, (UFG::SimObject *)v7, &ray_hit_object);
    }
    v8 = *v3->i_data.i_array_p;
    v9 = v8->i_data_p;
    LOBYTE(v8) = 1;
    v9->i_user_data = v4;
    ((void (__fastcall *)(SSInvokedContextBase *, SSData *))v3->vfptr[1].get_topmost_scope)(v3, v8);
  }
}

// File Line: 5424
// RVA: 0x4DCCE0
char __fastcall UFG::TSActor::Coro_raycast_to_target(UFG::TSActor *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // rdi
  UFG::TSActor *v3; // r15
  UFG::SimObject *v4; // rsi
  Render::DebugDrawContext *v5; // r14
  UFG::SimObject *v6; // r8
  __int64 v7; // rcx
  bool v8; // bp
  float *v9; // rbx
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rbx
  bool v14; // al
  UFG::qColour *v16; // r9
  UFG::qVector3 raycastPosition; // [rsp+48h] [rbp-40h]
  UFG::qVector3 p1; // [rsp+58h] [rbp-30h]

  v2 = pScope;
  v3 = this;
  v4 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 1u);
  if ( v4
    && (v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u),
        (v6 = v3->mpSimObj.m_pPointer) != 0i64) )
  {
    v7 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64);
    v8 = *(_QWORD *)(v7 + 32) != 0i64;
    if ( !*(_QWORD *)(v7 + 32) && v2->i_update_count )
      goto LABEL_25;
    if ( (v6->m_Flags & 0x8000u) == 0 )
    {
      UFG::ComputeObjectRaycastPosition(v3->mpSimObj.m_pPointer, &raycastPosition);
    }
    else
    {
      v9 = (float *)v6->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v6->m_pTransformNodeComponent);
      v10 = v9[45];
      v11 = v9[46];
      raycastPosition.x = v9[44];
      raycastPosition.y = v10;
      raycastPosition.z = v11 + 5.0;
    }
    UFG::ComputeObjectRaycastPosition(v4, &p1);
    if ( v2->i_update_count )
    {
LABEL_25:
      if ( v8 )
      {
        v16 = &UFG::qColour::Green;
        if ( (*v2->i_data.i_array_p)->i_data_p->i_user_data )
          v16 = &UFG::qColour::Red;
        Render::DebugDrawContext::DrawLine(v5, &raycastPosition, &p1, v16, &UFG::qMatrix44::msIdentity, 0i64, 0);
      }
    }
    else
    {
      if ( v8 )
        Render::DebugDrawContext::DrawLine(
          v5,
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
        v12->mNext = (UFG::allocator::free_link *)v2;
        LODWORD(v12[1].mNext) = v2->i_ptr_id;
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
              (UFG::SimComponent *)v3->mpComponent,
              v13);
      (*v2->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
      if ( v14 )
      {
        ++v2->i_pending_count;
        return 0;
      }
      operator delete[](v13);
    }
  }
  else
  {
    (*v2->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
  }
  return 1;
}

