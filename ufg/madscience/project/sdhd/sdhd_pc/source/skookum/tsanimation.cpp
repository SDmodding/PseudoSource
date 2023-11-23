// File Line: 53
// RVA: 0x4CE390
void UFG::TSAnimation::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]

  v0 = SSBrain::get_class("Animation");
  SSClass::register_coroutine_func(
    v0,
    "_request_animation_bank_stream",
    (bool (__fastcall *)(SSInvokedCoroutine *))Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_animation_bank_streamed",
    UFG::TSAnimation::Coro_wait_animation_bank_streamed,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(v0, "load_animation_bank", UFG::TSAnimation::MthdC_load_animation_bank, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "unload_animation_bank", UFG::TSAnimation::MthdC_unload_animation_bank, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "request_animation_bank_stream",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "is_animation_bank_streamed",
    UFG::TSAnimation::MthdC_is_animation_bank_streamed,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "start_animation_bank_use",
    UFG::TSAnimation::MthdC_start_animation_bank_use,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "end_animation_bank_use",
    UFG::TSAnimation::MthdC_end_animation_bank_use,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "load_animation_blend_trees",
    UFG::TSAnimation::MthdC_load_animation_blend_trees,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "load_act_file", UFG::TSAnimation::MthdC_load_act_file, 1, rebindg);
}

// File Line: 122
// RVA: 0x4DEA80
bool __fastcall UFG::TSAnimation::Coro_wait_animation_bank_streamed(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // rax
  const char ***p_i_user_data; // rdi
  const char *v3; // rbx
  AnimationDataBase *Instance; // rax
  UFG::qBaseNodeRB *AnimBank; // rax

  i_array_p = pScope->i_data.i_array_p;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( (*i_array_p)->i_data_p == (SSInstance *)-32i64 )
    return 0;
  v3 = **p_i_user_data;
  Instance = AnimationDataBase::GetInstance();
  AnimBank = AnimationDataBase::FindAnimBank(Instance, v3);
  if ( AnimBank )
    return AnimationGroup::IsStreamedIn((AnimationGroup *)AnimBank);
  UFG::qPrintf("WARNING: Coro_wait_animation_bank_streamed: Animation Group Not Found (%s)!\n", **p_i_user_data);
  return 1;
}

// File Line: 148
// RVA: 0x4EAAC0
void __fastcall UFG::TSAnimation::MthdC_load_animation_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  AnimationDataBase *Instance; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = AnimationDataBase::GetInstance();
  AnimationDataBase::LoadAnimBank(Instance, v2);
}

// File Line: 156
// RVA: 0x4F2A50
void __fastcall UFG::TSAnimation::MthdC_unload_animation_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  AnimationDataBase *Instance; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = AnimationDataBase::GetInstance();
  AnimationDataBase::UnloadAnimBank(Instance, v2);
}

// File Line: 181
// RVA: 0x4E92F0
void __fastcall UFG::TSAnimation::MthdC_is_animation_bank_streamed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v3; // rbx
  AnimationDataBase *Instance; // rax
  char IsStreamedIn; // al

  v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = AnimationDataBase::GetInstance();
  IsStreamedIn = AnimationDataBase::IsStreamedIn(Instance, v3);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(IsStreamedIn);
}

// File Line: 194
// RVA: 0x4F2370
void __fastcall UFG::TSAnimation::MthdC_start_animation_bank_use(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v3; // rbx
  AnimationDataBase *Instance; // rax
  UFG::qBaseNodeRB *AnimBank; // rax

  v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = AnimationDataBase::GetInstance();
  AnimBank = AnimationDataBase::FindAnimBank(Instance, v3);
  if ( AnimBank )
    AnimationGroup::AddRefCount((AnimationGroup *)AnimBank);
  else
    UFG::qPrintf(
      "WARNING: MthdC_start_animation_bank_use: Animation Group Not Found (%s)!\n",
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 210
// RVA: 0x4E5530
void __fastcall UFG::TSAnimation::MthdC_end_animation_bank_use(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v3; // rbx
  AnimationDataBase *Instance; // rax
  UFG::qBaseNodeRB *AnimBank; // rax

  v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = AnimationDataBase::GetInstance();
  AnimBank = AnimationDataBase::FindAnimBank(Instance, v3);
  if ( AnimBank )
    AnimationGroup::RemoveRefCount((AnimationGroup *)AnimBank);
  else
    UFG::qPrintf(
      "WARNING: MthdC_end_animation_bank_use: Animation Group Not Found (%s)!\n",
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 226
// RVA: 0x4EAAF0
void __fastcall UFG::TSAnimation::MthdC_load_animation_blend_trees(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  BlendTreeDataBase *Instance; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = BlendTreeDataBase::GetInstance();
  BlendTreeDataBase::LoadBlendTrees(Instance, v2);
}

// File Line: 234
// RVA: 0x4EAA80
void __fastcall UFG::TSAnimation::MthdC_load_act_file(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  ActionNode::Load(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 282
// RVA: 0x4CE4D0
void UFG::TSAnimationResource::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("AnimationResource");
  SSClass::register_method_func(
    v0,
    &ASymbolX_ctor,
    UFG::TSAnimationResource::Mthd_constructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    &ASymbolX_dtor,
    UFG::TSAnimationResource::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_streamed",
    UFG::TSAnimationResource::Coro_wait_until_streamed,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "add_bank", UFG::TSAnimationResource::Mthd_add_bank, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "activate", UFG::TSAnimationResource::Mthd_activate, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    "deactivate",
    UFG::TSAnimationResource::Mthd_deactivate,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    "is_streamed",
    UFG::TSAnimationResource::Mthd_is_streamed,
    SSBindFlag_instance_no_rebind);
}

// File Line: 307
// RVA: 0x4F6960
void __fastcall UFG::TSAnimationResource::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::allocator::free_link *v3; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v3 = UFG::qMalloc(0x18ui64, "Skookum.AnimationGroupHandleContainer", 0i64);
  if ( v3 )
  {
    v3->mNext = v3;
    v3[1].mNext = v3;
    LOBYTE(v3[2].mNext) = 0;
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v3;
  }
  else
  {
    i_obj_p[2].vfptr = 0i64;
  }
}

// File Line: 319
// RVA: 0x4F7DA0
void __fastcall UFG::TSAnimationResource::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0> *vfptr; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mPrev; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mNext; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0> *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(vfptr);
    UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(vfptr);
    mPrev = vfptr->mNode.mPrev;
    mNext = vfptr->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    vfptr->mNode.mPrev = &vfptr->mNode;
    vfptr->mNode.mNext = &vfptr->mNode;
    operator delete[](vfptr);
  }
}

// File Line: 329
// RVA: 0x4DF310
char __fastcall UFG::TSAnimationResource::Coro_wait_until_streamed(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rax
  SSInvokedContextBase *(__fastcall **p_get_scope_context)(SSObjectBase *); // rdi
  __int64 v4; // rbx
  AnimationGroup *v5; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  p_get_scope_context = &vfptr[-1].get_scope_context;
  v4 = (__int64)vfptr->get_obj_type - 16;
  if ( (SSInvokedContextBase *(__fastcall **)(SSObjectBase *))v4 != &vfptr[-1].get_scope_context )
  {
    while ( 1 )
    {
      v5 = *(AnimationGroup **)(v4 + 56);
      if ( !v5 || !AnimationGroup::IsStreamedIn(v5) )
        break;
      v4 = *(_QWORD *)(v4 + 24) - 16i64;
      if ( (SSInvokedContextBase *(__fastcall **)(SSObjectBase *))v4 == p_get_scope_context )
        return 1;
    }
  }
  return 0;
}

// File Line: 342
// RVA: 0x4F3BA0
void __fastcall UFG::TSAnimationResource::Mthd_add_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData *v3; // rcx
  SSObjectBase *i_obj_p; // rcx
  AnimationGroupHandle *v5; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *vfptr; // rsi
  UFG::eAnimationPriorityEnum EnumFromSymbol; // edi
  UFG::allocator::free_link *v8; // rax
  AnimationGroupHandle *v9; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mPrev; // rax
  UFG::qSymbolUC result; // [rsp+40h] [rbp+8h] BYREF
  UFG::allocator::free_link *v12; // [rsp+50h] [rbp+18h]

  v3 = *pScope->i_data.i_array_p;
  if ( v3->i_data_p != (SSInstance *)-32i64 )
  {
    UFG::qSymbolUC::create_from_string(&result, *(const char **)v3->i_data_p->i_user_data);
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v5 = 0i64;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)i_obj_p[2].vfptr;
    EnumFromSymbol = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                     &UFG::gAnimationPriorityEnum,
                                     (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64)
                                                    + 32i64));
    v8 = UFG::qMalloc(0x50ui64, "AnimationGroupHandle", 0i64);
    v12 = v8;
    if ( v8 )
    {
      AnimationGroupHandle::AnimationGroupHandle((AnimationGroupHandle *)v8);
      v5 = v9;
    }
    AnimationGroupHandle::Init(v5, &result, EnumFromSymbol);
    mPrev = vfptr->mPrev;
    mPrev->mNext = &v5->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
    v5->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev = mPrev;
    v5->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext = vfptr;
    vfptr->mPrev = &v5->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  }
}

// File Line: 372
// RVA: 0x4F3AE0
void __fastcall UFG::TSAnimationResource::Mthd_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  AnimationGroupHandleContainer::Bind((AnimationGroupHandleContainer *)i_obj_p[2].vfptr);
}

// File Line: 385
// RVA: 0x4F7A20
void __fastcall UFG::TSAnimationResource::Mthd_deactivate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdi
  AnimationGroupHandle *i; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  for ( i = (AnimationGroupHandle *)((char *)vfptr->get_obj_type - 16);
        i != (AnimationGroupHandle *)&vfptr[-1].get_scope_context;
        i = (AnimationGroupHandle *)&i->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1] )
  {
    AnimationGroupHandle::Unbind(i);
  }
  LOBYTE(vfptr->is_actor) = 0;
}

// File Line: 398
// RVA: 0x5032F0
void __fastcall UFG::TSAnimationResource::Mthd_is_streamed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax
  SSInvokedContextBase *(__fastcall **p_get_scope_context)(SSObjectBase *); // rdi
  __int64 v6; // rbx
  AnimationGroup *v7; // rcx
  bool v8; // cl

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  p_get_scope_context = &vfptr[-1].get_scope_context;
  v6 = (__int64)vfptr->get_obj_type - 16;
  if ( (SSInvokedContextBase *(__fastcall **)(SSObjectBase *))v6 != &vfptr[-1].get_scope_context )
  {
    while ( 1 )
    {
      v7 = *(AnimationGroup **)(v6 + 56);
      if ( !v7 || !AnimationGroup::IsStreamedIn(v7) )
        break;
      v6 = *(_QWORD *)(v6 + 24) - 16i64;
      if ( (SSInvokedContextBase *(__fastcall **)(SSObjectBase *))v6 == p_get_scope_context )
      {
        v8 = 1;
        goto LABEL_10;
      }
    }
  }
  v8 = 0;
LABEL_10:
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v8);
}

