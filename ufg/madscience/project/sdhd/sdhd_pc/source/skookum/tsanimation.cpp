// File Line: 53
// RVA: 0x4CE390
void UFG::TSAnimation::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Animation");
  SSClass::register_coroutine_func(
    v0,
    "_request_animation_bank_stream",
    (bool (__fastcall *)(SSInvokedCoroutine *))Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_animation_bank_streamed",
    UFG::TSAnimation::Coro_wait_animation_bank_streamed,
    0);
  SSClass::register_method_func(v0, "load_animation_bank", UFG::TSAnimation::MthdC_load_animation_bank, 1, 0);
  SSClass::register_method_func(v0, "unload_animation_bank", UFG::TSAnimation::MthdC_unload_animation_bank, 1, 0);
  SSClass::register_method_func(
    v0,
    "request_animation_bank_stream",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "is_animation_bank_streamed",
    UFG::TSAnimation::MthdC_is_animation_bank_streamed,
    1,
    0);
  SSClass::register_method_func(v0, "start_animation_bank_use", UFG::TSAnimation::MthdC_start_animation_bank_use, 1, 0);
  SSClass::register_method_func(v0, "end_animation_bank_use", UFG::TSAnimation::MthdC_end_animation_bank_use, 1, 0);
  SSClass::register_method_func(
    v0,
    "load_animation_blend_trees",
    UFG::TSAnimation::MthdC_load_animation_blend_trees,
    1,
    0);
  SSClass::register_method_func(v0, "load_act_file", UFG::TSAnimation::MthdC_load_act_file, 1, 0);
}

// File Line: 122
// RVA: 0x4DEA80
bool __fastcall UFG::TSAnimation::Coro_wait_animation_bank_streamed(SSInvokedCoroutine *pScope)
{
  SSData **v1; // rax
  const char ***v2; // rdi
  const char *v3; // rbx
  AnimationDataBase *v4; // rax
  UFG::qBaseNodeRB *v5; // rax

  v1 = pScope->i_data.i_array_p;
  v2 = (const char ***)&(*v1)->i_data_p->i_user_data;
  if ( (*v1)->i_data_p == (SSInstance *)-32i64 )
    return 0;
  v3 = **v2;
  v4 = AnimationDataBase::GetInstance();
  v5 = AnimationDataBase::FindAnimBank(v4, v3);
  if ( v5 )
    return AnimationGroup::IsStreamedIn((AnimationGroup *)v5);
  UFG::qPrintf("WARNING: Coro_wait_animation_bank_streamed: Animation Group Not Found (%s)!\n", **v2);
  return 1;
}

// File Line: 148
// RVA: 0x4EAAC0
void __fastcall UFG::TSAnimation::MthdC_load_animation_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  AnimationDataBase *v3; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = AnimationDataBase::GetInstance();
  AnimationDataBase::LoadAnimBank(v3, v2);
}

// File Line: 156
// RVA: 0x4F2A50
void __fastcall UFG::TSAnimation::MthdC_unload_animation_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  AnimationDataBase *v3; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = AnimationDataBase::GetInstance();
  AnimationDataBase::UnloadAnimBank(v3, v2);
}

// File Line: 181
// RVA: 0x4E92F0
void __fastcall UFG::TSAnimation::MthdC_is_animation_bank_streamed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  const char *v3; // rbx
  AnimationDataBase *v4; // rax
  char v5; // al

  v2 = ppResult;
  v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = AnimationDataBase::GetInstance();
  v5 = AnimationDataBase::IsStreamedIn(v4, v3);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v5);
}

// File Line: 194
// RVA: 0x4F2370
void __fastcall UFG::TSAnimation::MthdC_start_animation_bank_use(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  const char *v3; // rbx
  AnimationDataBase *v4; // rax
  UFG::qBaseNodeRB *v5; // rax

  v2 = pScope;
  v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = AnimationDataBase::GetInstance();
  v5 = AnimationDataBase::FindAnimBank(v4, v3);
  if ( v5 )
    AnimationGroup::AddRefCount((AnimationGroup *)v5);
  else
    UFG::qPrintf(
      "WARNING: MthdC_start_animation_bank_use: Animation Group Not Found (%s)!\n",
      *(_QWORD *)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 210
// RVA: 0x4E5530
void __fastcall UFG::TSAnimation::MthdC_end_animation_bank_use(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  const char *v3; // rbx
  AnimationDataBase *v4; // rax
  UFG::qBaseNodeRB *v5; // rax

  v2 = pScope;
  v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = AnimationDataBase::GetInstance();
  v5 = AnimationDataBase::FindAnimBank(v4, v3);
  if ( v5 )
    AnimationGroup::RemoveRefCount((AnimationGroup *)v5);
  else
    UFG::qPrintf(
      "WARNING: MthdC_end_animation_bank_use: Animation Group Not Found (%s)!\n",
      *(_QWORD *)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 226
// RVA: 0x4EAAF0
void __fastcall UFG::TSAnimation::MthdC_load_animation_blend_trees(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  BlendTreeDataBase *v3; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = BlendTreeDataBase::GetInstance();
  BlendTreeDataBase::LoadBlendTrees(v3, v2);
}

// File Line: 234
// RVA: 0x4EAA80
void __fastcall UFG::TSAnimation::MthdC_load_act_file(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  bool v3; // ST20_1

  v2 = pScope->i_data.i_array_p;
  v3 = v2[2]->i_data_p->i_user_data != 0;
  ActionNode::Load(*(const char **)(*v2)->i_data_p->i_user_data);
}

// File Line: 282
// RVA: 0x4CE4D0
void UFG::TSAnimationResource::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("AnimationResource");
  SSClass::register_method_func(v0, &ASymbolX_ctor, UFG::TSAnimationResource::Mthd_constructor, 0);
  SSClass::register_method_func(v0, &ASymbolX_dtor, UFG::TSAnimationResource::Mthd_destructor, 0);
  SSClass::register_coroutine_func(v0, "_wait_until_streamed", UFG::TSAnimationResource::Coro_wait_until_streamed, 0);
  SSClass::register_method_func(v0, "add_bank", UFG::TSAnimationResource::Mthd_add_bank, 0);
  SSClass::register_method_func(v0, "activate", UFG::TSAnimationResource::Mthd_activate, 0);
  SSClass::register_method_func(v0, "deactivate", UFG::TSAnimationResource::Mthd_deactivate, 0);
  SSClass::register_method_func(v0, "is_streamed", UFG::TSAnimationResource::Mthd_is_streamed, 0);
}

// File Line: 307
// RVA: 0x4F6960
void __fastcall UFG::TSAnimationResource::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = UFG::qMalloc(0x18ui64, "Skookum.AnimationGroupHandleContainer", 0i64);
  if ( v3 )
  {
    v3->mNext = v3;
    v3[1].mNext = v3;
    LOBYTE(v3[2].mNext) = 0;
    v2[2].vfptr = (SSObjectBaseVtbl *)v3;
  }
  else
  {
    v2[2].vfptr = 0i64;
  }
}

// File Line: 319
// RVA: 0x4F7DA0
void __fastcall UFG::TSAnimationResource::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0> *v3; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v4; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v5; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0> *)v2[2].vfptr;
  if ( v3 )
  {
    UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(v3);
    UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(v3);
    v4 = v3->mNode.mPrev;
    v5 = v3->mNode.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mNode.mPrev = &v3->mNode;
    v3->mNode.mNext = &v3->mNode;
    operator delete[](v3);
  }
}

// File Line: 329
// RVA: 0x4DF310
char __fastcall UFG::TSAnimationResource::Coro_wait_until_streamed(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rdx
  SSObjectBaseVtbl *v2; // rax
  signed __int64 v3; // rdi
  signed __int64 v4; // rbx
  AnimationGroup *v5; // rcx

  v1 = pScope->i_scope_p.i_obj_p;
  if ( !v1 || pScope->i_scope_p.i_ptr_id != v1->i_ptr_id )
    v1 = 0i64;
  v2 = v1[2].vfptr;
  v3 = (signed __int64)&v2[-1].get_scope_context;
  v4 = (signed __int64)v2->get_obj_type - 16;
  if ( (SSInvokedContextBase *(__fastcall **)(SSObjectBase *))v4 != &v2[-1].get_scope_context )
  {
    while ( 1 )
    {
      v5 = *(AnimationGroup **)(v4 + 56);
      if ( !v5 || !AnimationGroup::IsStreamedIn(v5) )
        break;
      v4 = *(_QWORD *)(v4 + 24) - 16i64;
      if ( v4 == v3 )
        return 1;
    }
  }
  return 0;
}

// File Line: 342
// RVA: 0x4F3BA0
void __fastcall UFG::TSAnimationResource::Mthd_add_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  SSData *v3; // rcx
  SSObjectBase *v4; // rcx
  AnimationGroupHandle *v5; // rbx
  SSObjectBaseVtbl *v6; // rsi
  UFG::eAnimationPriorityEnum v7; // edi
  UFG::allocator::free_link *v8; // rax
  AnimationGroupHandle *v9; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v10; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v11; // rax
  UFG::qSymbolUC result; // [rsp+40h] [rbp+8h]
  UFG::allocator::free_link *v13; // [rsp+50h] [rbp+18h]

  v2 = pScope;
  v3 = *pScope->i_data.i_array_p;
  if ( v3->i_data_p != (SSInstance *)-32i64 )
  {
    UFG::qSymbolUC::create_from_string(&result, *(const char **)v3->i_data_p->i_user_data);
    v4 = v2->i_scope_p.i_obj_p;
    v5 = 0i64;
    if ( !v4 || v2->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = v4[2].vfptr;
    v7 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                         &UFG::gAnimationPriorityEnum,
                         (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
    v8 = UFG::qMalloc(0x50ui64, "AnimationGroupHandle", 0i64);
    v13 = v8;
    if ( v8 )
    {
      AnimationGroupHandle::AnimationGroupHandle((AnimationGroupHandle *)v8);
      v5 = v9;
    }
    AnimationGroupHandle::Init(v5, &result, v7);
    v10 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v5->mPrev;
    v11 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v6->__vecDelDtor;
    v11->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v5->mPrev;
    v10->mPrev = v11;
    v10->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v6;
    v6->__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))&v5->mPrev;
  }
}

// File Line: 372
// RVA: 0x4F3AE0
void __fastcall UFG::TSAnimationResource::Mthd_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  AnimationGroupHandleContainer::Bind((AnimationGroupHandleContainer *)v3[2].vfptr);
}

// File Line: 385
// RVA: 0x4F7A20
void __fastcall UFG::TSAnimationResource::Mthd_deactivate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rdi
  AnimationGroupHandle *i; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  for ( i = (AnimationGroupHandle *)((char *)v3->get_obj_type - 16);
        i != (AnimationGroupHandle *)&v3[-1].get_scope_context;
        i = (AnimationGroupHandle *)&i->mNext[-1] )
  {
    AnimationGroupHandle::Unbind(i);
  }
  LOBYTE(v3->is_actor) = 0;
}

// File Line: 398
// RVA: 0x5032F0
void __fastcall UFG::TSAnimationResource::Mthd_is_streamed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rax
  signed __int64 v5; // rdi
  signed __int64 v6; // rbx
  AnimationGroup *v7; // rcx
  bool v8; // cl

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = (signed __int64)&v4[-1].get_scope_context;
  v6 = (signed __int64)v4->get_obj_type - 16;
  if ( (SSInvokedContextBase *(__fastcall **)(SSObjectBase *))v6 != &v4[-1].get_scope_context )
  {
    while ( 1 )
    {
      v7 = *(AnimationGroup **)(v6 + 56);
      if ( !v7 || !AnimationGroup::IsStreamedIn(v7) )
        break;
      v6 = *(_QWORD *)(v6 + 24) - 16i64;
      if ( v6 == v5 )
      {
        v8 = 1;
        goto LABEL_10;
      }
    }
  }
  v8 = 0;
LABEL_10:
  if ( v3 )
    *v3 = (SSInstance *)SSBoolean::pool_new(v8);
}

