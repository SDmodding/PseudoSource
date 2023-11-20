// File Line: 100
// RVA: 0x4D5830
void UFG::TSSceneLayer::BindAtomics(void)
{
  UFG::TSSceneLayer::mspSceneLayerClass = SSBrain::get_class("SceneLayer");
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "enable_activate",
    UFG::TSSceneLayer::Mthd_enable_activate,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "is_active",
    UFG::TSSceneLayer::Mthd_is_active,
    0);
  SSClass::register_method_func(UFG::TSSceneLayer::mspSceneLayerClass, "get_name", UFG::TSSceneLayer::Mthd_get_name, 0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_bounds_min",
    UFG::TSSceneLayer::Mthd_get_bounds_min,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_bounds_max",
    UFG::TSSceneLayer::Mthd_get_bounds_max,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_is_enabled",
    UFG::TSSceneLayer::Mthd_geo_is_enabled,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_enable",
    UFG::TSSceneLayer::Mthd_geo_enable,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_is_auto_activate",
    UFG::TSSceneLayer::Mthd_geo_is_auto_activate,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_enable_auto_activate",
    UFG::TSSceneLayer::Mthd_geo_enable_auto_activate,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "getSimObjects",
    UFG::TSSceneLayer::Mthd_getSimObjects,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "getObjectPropertySets",
    UFG::TSSceneLayer::Mthd_getObjectPropertySets,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "find_named",
    UFG::TSSceneLayer::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_named",
    UFG::TSSceneLayer::MthdC_get_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_set_active_category",
    UFG::TSSceneLayer::MthdC_geo_set_active_category,
    1,
    0);
}

// File Line: 135
// RVA: 0x4F88A0
void __fastcall UFG::TSSceneLayer::Mthd_enable_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // rdx
  SSObjectBase *v4; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = pScope->i_scope_p.i_obj_p;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v4[2].vfptr, (*v2)->i_data_p->i_user_data != 0, PERSISTENT, 1);
}

// File Line: 145
// RVA: 0x500910
void __fastcall UFG::TSSceneLayer::Mthd_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new((LODWORD(v2[2].vfptr->get_scope_context) >> 1) & 1);
  }
}

// File Line: 159
// RVA: 0x4FAD70
void __fastcall UFG::TSSceneLayer::Mthd_geo_enable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // rdx
  SSObjectBase *v4; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = pScope->i_scope_p.i_obj_p;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  UFG::SceneLayer::EnableGeographical((UFG::SceneLayer *)v4[2].vfptr, (*v2)->i_data_p->i_user_data != 0, PERSISTENT);
}

// File Line: 169
// RVA: 0x4FAE60
void __fastcall UFG::TSSceneLayer::Mthd_geo_is_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new((LODWORD(v2[2].vfptr->get_scope_context) >> 14) & 1);
  }
}

// File Line: 183
// RVA: 0x4FADB0
void __fastcall UFG::TSSceneLayer::Mthd_geo_enable_auto_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInvokedMethod *v3; // rdi
  UFG::SceneLayer *v4; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (UFG::SceneLayer *)v2[2].vfptr;
  UFG::SceneLayer::EnableGeographical(v4, 1, PERSISTENT);
  UFG::SceneLayer::EnableAutoActivate(v4, (*v3->i_data.i_array_p)->i_data_p->i_user_data != 0, PERSISTENT);
}

// File Line: 196
// RVA: 0x4FAE20
void __fastcall UFG::TSSceneLayer::Mthd_geo_is_auto_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new((LODWORD(v2[2].vfptr->get_scope_context) >> 7) & 1);
  }
}

// File Line: 212
// RVA: 0x4FD6D0
void __fastcall UFG::TSSceneLayer::Mthd_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)&v3[2].vfptr->as_instance);
  }
}

// File Line: 226
// RVA: 0x4FBC70
void __fastcall UFG::TSSceneLayer::Mthd_get_bounds_min(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v3[2].vfptr[1].is_actor);
  }
}

// File Line: 240
// RVA: 0x4FBC30
void __fastcall UFG::TSSceneLayer::Mthd_get_bounds_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)((char *)&v3[2].vfptr[1].as_instance + 4));
  }
}

// File Line: 251
// RVA: 0x4FB040
void __fastcall UFG::TSSceneLayer::Mthd_getSimObjects(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSList *v3; // rax
  SSList *v4; // r13
  SSObjectBase *v5; // rcx
  SSObjectBaseVtbl *v6; // rax
  signed __int64 v7; // rbp
  signed __int64 v8; // rax
  signed __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  SSClass *v11; // r14
  AObjReusePool<SSInstance> *v12; // rax
  AObjReusePool<SSInstance> *v13; // rbx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  __int64 v17; // rcx
  SSInstance **v18; // rax
  SSInstance *v19; // rdx
  unsigned int v20; // eax
  SSInstance **v21; // [rsp+68h] [rbp+10h]
  signed __int64 v22; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    v21 = ppResult;
    v2 = pScope;
    v3 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v4 = v3;
    if ( v3 )
    {
      v3->i_items.i_count = 0;
      v3->i_items.i_array_p = 0i64;
      v3->i_items.i_size = 0;
      v3->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v4 = 0i64;
    }
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v6 = v5[2].vfptr;
    v7 = (signed __int64)v6[1].__vecDelDtor - 88;
    v8 = (signed __int64)&v6[-1].get_data_by_name;
    v22 = v8;
    if ( v7 == v8 )
      goto LABEL_23;
    while ( 1 )
    {
      v9 = *(_QWORD *)(v7 + 152) - 64i64;
      if ( v9 == v7 + 80 )
        goto LABEL_22;
      do
      {
        v10 = *(_QWORD *)(v9 + 40);
        if ( !v10 )
          goto LABEL_20;
        v11 = UFG::TSSimObject::mspSimObjectClass;
        v12 = SSInstance::get_pool();
        v13 = v12;
        v14 = v12->i_pool.i_count;
        if ( v14 )
        {
          v20 = v14 - 1;
          v13->i_pool.i_count = v20;
          v17 = v20;
          v18 = v13->i_pool.i_array_p;
          goto LABEL_18;
        }
        if ( !v13->i_exp_pool.i_count )
          AObjReusePool<SSInstance>::append_block(v13, v13->i_expand_size);
        v15 = v13->i_exp_pool.i_count;
        if ( v15 )
        {
          v16 = v15 - 1;
          v13->i_exp_pool.i_count = v16;
          v17 = v16;
          v18 = v13->i_exp_pool.i_array_p;
LABEL_18:
          v19 = v18[v17];
          goto LABEL_19;
        }
        v19 = 0i64;
LABEL_19:
        v19->i_class_p = v11;
        v19->i_user_data = v10;
        v19->i_ref_count = 1;
        v19->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
        SSList::append(v4, v19, 1);
LABEL_20:
        v9 = *(_QWORD *)(v9 + 72) - 64i64;
      }
      while ( v9 != v7 + 80 );
      v8 = v22;
LABEL_22:
      v7 = *(_QWORD *)(v7 + 96) - 88i64;
      if ( v7 == v8 )
      {
LABEL_23:
        *v21 = SSList::as_instance(v4);
        return;
      }
    }
  }
}

// File Line: 273
// RVA: 0x4FAEA0
void __fastcall UFG::TSSceneLayer::Mthd_getObjectPropertySets(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSList *v3; // rax
  SSList *v4; // r15
  SSObjectBase *v5; // rcx
  SSObjectBaseVtbl *v6; // rax
  signed __int64 v7; // rsi
  signed __int64 v8; // rax
  unsigned int v9; // er12
  unsigned int v10; // edi
  UFG::qPropertySet *v11; // r14
  SSClass *v12; // r13
  AObjReusePool<SSInstance> *v13; // rax
  AObjReusePool<SSInstance> *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  __int64 v18; // rcx
  SSInstance **v19; // rax
  SSInstance *v20; // rdx
  unsigned int v21; // eax
  SSInstance **v22; // [rsp+68h] [rbp+10h]
  signed __int64 v23; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    v22 = ppResult;
    v2 = pScope;
    v3 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v4 = v3;
    if ( v3 )
    {
      v3->i_items.i_count = 0;
      v3->i_items.i_array_p = 0i64;
      v3->i_items.i_size = 0;
      v3->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v4 = 0i64;
    }
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v6 = v5[2].vfptr;
    v7 = (signed __int64)v6[1].__vecDelDtor - 88;
    v8 = (signed __int64)&v6[-1].get_data_by_name;
    v23 = v8;
    if ( v7 == v8 )
      goto LABEL_21;
    while ( 1 )
    {
      v9 = *(_DWORD *)(v7 + 108);
      v10 = 0;
      if ( !v9 )
        goto LABEL_20;
      do
      {
        v11 = (UFG::qPropertySet *)UFG::RoadNetworkResource::GetSegment((UFG::RoadNetworkResource *)v7, v10);
        UFG::qPropertySet::AddRef(v11);
        v12 = UFG::SkookumMgr::mspPropertySetClass;
        v13 = SSInstance::get_pool();
        v14 = v13;
        v15 = v13->i_pool.i_count;
        if ( v15 )
        {
          v21 = v15 - 1;
          v14->i_pool.i_count = v21;
          v18 = v21;
          v19 = v14->i_pool.i_array_p;
        }
        else
        {
          if ( !v14->i_exp_pool.i_count )
            AObjReusePool<SSInstance>::append_block(v14, v14->i_expand_size);
          v16 = v14->i_exp_pool.i_count;
          if ( !v16 )
          {
            v20 = 0i64;
            goto LABEL_18;
          }
          v17 = v16 - 1;
          v14->i_exp_pool.i_count = v17;
          v18 = v17;
          v19 = v14->i_exp_pool.i_array_p;
        }
        v20 = v19[v18];
LABEL_18:
        v20->i_class_p = v12;
        v20->i_user_data = (unsigned __int64)v11;
        v20->i_ref_count = 1;
        v20->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
        SSList::append(v4, v20, 1);
        ++v10;
      }
      while ( v10 < v9 );
      v8 = v23;
LABEL_20:
      v7 = *(_QWORD *)(v7 + 96) - 88i64;
      if ( v7 == v8 )
      {
LABEL_21:
        *v22 = SSList::as_instance(v4);
        return;
      }
    }
  }
}

// File Line: 299
// RVA: 0x4E6570
void __fastcall UFG::TSSceneLayer::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::qBaseTreeRB *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::Scene::FindLayer(
           &UFG::Scene::msDefault,
           (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    if ( v3 )
      *v2 = SSInstance::pool_new(UFG::TSSceneLayer::mspSceneLayerClass, (unsigned __int64)v3);
    else
      *v2 = SSBrain::c_nil_p;
  }
}

// File Line: 319
// RVA: 0x4E82C0
void __fastcall UFG::TSSceneLayer::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSInstance *v3; // rdi
  UFG::qBaseTreeRB *v4; // rbp
  unsigned int v5; // ebx
  char *v6; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p;
    v4 = UFG::Scene::FindOrCreateLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)&v3->i_user_data);
    if ( !v4 )
    {
      v5 = v3->i_user_data;
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->i_user_data);
      UFG::qPrintf("Failed to find scene layer: 0x%08x [%s] perhaps it needs to be tagged as global?\n", v5, v6);
    }
    *v2 = SSInstance::pool_new(UFG::TSSceneLayer::mspSceneLayerClass, (unsigned __int64)v4);
  }
}

// File Line: 352
// RVA: 0x4E6F50
void __fastcall UFG::TSSceneLayer::MthdC_geo_set_active_category(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GeographicalLayerManager::SetActiveCategory((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

