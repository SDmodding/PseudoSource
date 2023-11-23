// File Line: 28
// RVA: 0x418F10
void UFG::TSGameplayUtil::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("GameplayUtil");
  SSClass::register_method_func(v0, "allowsOperationTheme", UFG::TSGameplayUtil::MthdC_allowsOperationTheme, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "getStringProperty", UFG::TSGameplayUtil::MthdC_getStringProperty, 1, rebinda);
}

// File Line: 36
// RVA: 0x419410
void __fastcall UFG::TSGameplayUtil::MthdC_allowsOperationTheme(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::qBaseNodeRB *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  bool *v8; // rax
  bool *v9; // rcx
  char v10; // [rsp+30h] [rbp+8h] BYREF
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  UFG::qArray<unsigned long,0> v12; // [rsp+40h] [rbp+18h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  name.mUID = (*i_array_p)->i_data_p->i_user_data;
  v12.size = i_array_p[1]->i_data_p->i_user_data;
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
  if ( !SimObject )
    goto LABEL_2;
  v5 = SimObject[2].mChild[1];
  v6 = (UFG::qPropertySet *)v5[4].mChild[1];
  if ( !v6 )
    v6 = *(UFG::qPropertySet **)&v5[4].mUID;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v6,
         (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_gameplayOperationThemesAllowed,
         DEPTH_RECURSE);
  if ( v7 )
  {
    v10 = 1;
    v8 = UFG::qPropertySet::Get<bool>(v7, &v12, DEPTH_RECURSE);
    v9 = (bool *)&v10;
    if ( v8 )
      v9 = v8;
    *ppResult = SSBoolean::pool_new(*v9);
  }
  else
  {
LABEL_2:
    *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 44
// RVA: 0x4194D0
void __fastcall UFG::TSGameplayUtil::MthdC_getStringProperty(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::qBaseNodeRB *v5; // rax
  UFG::qPropertySet *v6; // rcx
  char *v7; // rax
  AString *v8; // rax
  AStringRef *p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  UFG::qString v16; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol name; // [rsp+60h] [rbp+8h] BYREF
  UFG::qArray<unsigned long,0> v18; // [rsp+70h] [rbp+18h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  name.mUID = (*i_array_p)->i_data_p->i_user_data;
  v18.size = i_array_p[1]->i_data_p->i_user_data;
  UFG::qString::qString(&v16);
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
  if ( SimObject )
  {
    v5 = SimObject[2].mChild[1];
    v6 = (UFG::qPropertySet *)v5[4].mChild[1];
    if ( !v6 )
      v6 = *(UFG::qPropertySet **)&v5[4].mUID;
    v7 = UFG::qPropertySet::Get<char const *>(v6, &v18, DEPTH_RECURSE);
    if ( v7 )
    {
      UFG::qString::Set(&v16, v7);
      AString::AString((AString *)&v18.p, v16.mData, 0);
      *ppResult = SSString::as_instance(v8);
      p = (AStringRef *)v18.p;
      if ( (*((_WORD *)v18.p + 8))-- == 1 )
      {
        if ( p->i_deallocate )
          AMemory::c_free_func(p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)p < i_objects_a
          || (v14 = (unsigned __int64)p < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v14) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, p);
      }
    }
  }
  UFG::qString::~qString(&v16);
}

