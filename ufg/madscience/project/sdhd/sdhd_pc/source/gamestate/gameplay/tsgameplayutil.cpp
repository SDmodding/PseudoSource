// File Line: 28
// RVA: 0x418F10
void UFG::TSGameplayUtil::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("GameplayUtil");
  SSClass::register_method_func(v0, "allowsOperationTheme", UFG::TSGameplayUtil::MthdC_allowsOperationTheme, 1, 0);
  SSClass::register_method_func(v0, "getStringProperty", UFG::TSGameplayUtil::MthdC_getStringProperty, 1, 0);
}

// File Line: 36
// RVA: 0x419410
void __fastcall UFG::TSGameplayUtil::MthdC_allowsOperationTheme(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  bool *v8; // rax
  bool *v9; // rcx
  char v10; // [rsp+30h] [rbp+8h]
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  UFG::qSymbol v12; // [rsp+40h] [rbp+18h]

  v2 = pScope->i_data.i_array_p;
  v3 = ppResult;
  name.mUID = (*v2)->i_data_p->i_user_data;
  v12.mUID = v2[1]->i_data_p->i_user_data;
  v4 = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
  if ( !v4 )
    goto LABEL_11;
  v5 = v4[2].mChild[1];
  v6 = (UFG::qPropertySet *)v5[4].mChild[1];
  if ( !v6 )
    v6 = *(UFG::qPropertySet **)&v5[4].mUID;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v6,
         (UFG::qSymbol *)&qSymbolX_propset_gameplayOperationThemesAllowed.mUID,
         DEPTH_RECURSE);
  if ( v7 )
  {
    v10 = 1;
    v8 = UFG::qPropertySet::Get<bool>(v7, &v12, DEPTH_RECURSE);
    v9 = (bool *)&v10;
    if ( v8 )
      v9 = v8;
    *v3 = (SSInstance *)SSBoolean::pool_new(*v9);
  }
  else
  {
LABEL_11:
    *v3 = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 44
// RVA: 0x4194D0
void __fastcall UFG::TSGameplayUtil::MthdC_getStringProperty(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSData **v3; // r8
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *v5; // rax
  UFG::qPropertySet *v6; // rcx
  char *v7; // rax
  AString *v8; // rax
  AStringRef *v9; // rbx
  bool v10; // zf
  AObjReusePool<AStringRef> *v11; // rax
  AObjBlock<AStringRef> *v12; // rcx
  unsigned __int64 v13; // rdx
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v15; // rcx
  UFG::qString v16; // [rsp+28h] [rbp-30h]
  UFG::qSymbol name; // [rsp+60h] [rbp+8h]
  UFG::qSymbol v18; // [rsp+70h] [rbp+18h]
  AString v19; // [rsp+78h] [rbp+20h]

  v2 = ppResult;
  v3 = pScope->i_data.i_array_p;
  name.mUID = (*v3)->i_data_p->i_user_data;
  v18.mUID = v3[1]->i_data_p->i_user_data;
  UFG::qString::qString(&v16);
  v4 = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
  if ( v4 )
  {
    v5 = v4[2].mChild[1];
    v6 = (UFG::qPropertySet *)v5[4].mChild[1];
    if ( !v6 )
      v6 = *(UFG::qPropertySet **)&v5[4].mUID;
    v7 = UFG::qPropertySet::Get<char const *>(v6, &v18, DEPTH_RECURSE);
    if ( v7 )
    {
      UFG::qString::Set(&v16, v7);
      AString::AString(&v19, v16.mData, 0);
      *v2 = SSString::as_instance(v8);
      v9 = v19.i_str_ref_p;
      v10 = v19.i_str_ref_p->i_ref_count == 1;
      --v9->i_ref_count;
      if ( v10 )
      {
        if ( v9->i_deallocate )
          AMemory::c_free_func(v9->i_cstr_p);
        v11 = AStringRef::get_pool();
        v12 = v11->i_block_p;
        v13 = (unsigned __int64)v12->i_objects_a;
        if ( (unsigned __int64)v9 < v13
          || (v14 = (unsigned __int64)v9 < v13 + 24i64 * v12->i_size, v15 = &v11->i_pool, !v14) )
        {
          v15 = &v11->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v15, v9);
      }
    }
  }
  UFG::qString::~qString(&v16);
}

