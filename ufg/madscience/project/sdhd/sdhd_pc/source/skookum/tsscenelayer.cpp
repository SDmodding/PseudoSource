// File Line: 100
// RVA: 0x4D5830
void UFG::TSSceneLayer::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  UFG::TSSceneLayer::mspSceneLayerClass = SSBrain::get_class("SceneLayer");
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "enable_activate",
    UFG::TSSceneLayer::Mthd_enable_activate,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "is_active",
    UFG::TSSceneLayer::Mthd_is_active,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_name",
    UFG::TSSceneLayer::Mthd_get_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_bounds_min",
    UFG::TSSceneLayer::Mthd_get_bounds_min,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_bounds_max",
    UFG::TSSceneLayer::Mthd_get_bounds_max,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_is_enabled",
    UFG::TSSceneLayer::Mthd_geo_is_enabled,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_enable",
    UFG::TSSceneLayer::Mthd_geo_enable,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_is_auto_activate",
    UFG::TSSceneLayer::Mthd_geo_is_auto_activate,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_enable_auto_activate",
    UFG::TSSceneLayer::Mthd_geo_enable_auto_activate,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "getSimObjects",
    UFG::TSSceneLayer::Mthd_getSimObjects,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "getObjectPropertySets",
    UFG::TSSceneLayer::Mthd_getObjectPropertySets,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "find_named",
    UFG::TSSceneLayer::MthdC_find_named,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "get_named",
    UFG::TSSceneLayer::MthdC_get_named,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSceneLayer::mspSceneLayerClass,
    "geo_set_active_category",
    UFG::TSSceneLayer::MthdC_geo_set_active_category,
    1,
    rebindb);
}

// File Line: 135
// RVA: 0x4F88A0
void __fastcall UFG::TSSceneLayer::Mthd_enable_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::SceneLayer::EnableActivate(
    (UFG::SceneLayer *)i_obj_p[2].vfptr,
    (*i_array_p)->i_data_p->i_user_data != 0,
    PERSISTENT,
    1);
}

// File Line: 145
// RVA: 0x500910
void __fastcall UFG::TSSceneLayer::Mthd_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(((__int64)i_obj_p[2].vfptr->get_scope_context & 2) != 0);
  }
}

// File Line: 159
// RVA: 0x4FAD70
void __fastcall UFG::TSSceneLayer::Mthd_geo_enable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::SceneLayer::EnableGeographical(
    (UFG::SceneLayer *)i_obj_p[2].vfptr,
    (*i_array_p)->i_data_p->i_user_data != 0,
    PERSISTENT);
}

// File Line: 169
// RVA: 0x4FAE60
void __fastcall UFG::TSSceneLayer::Mthd_geo_is_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(((__int64)i_obj_p[2].vfptr->get_scope_context & 0x4000) != 0);
  }
}

// File Line: 183
// RVA: 0x4FADB0
void __fastcall UFG::TSSceneLayer::Mthd_geo_enable_auto_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::SceneLayer *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::SceneLayer *)i_obj_p[2].vfptr;
  UFG::SceneLayer::EnableGeographical(vfptr, 1, PERSISTENT);
  UFG::SceneLayer::EnableAutoActivate(vfptr, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0, PERSISTENT);
}

// File Line: 196
// RVA: 0x4FAE20
void __fastcall UFG::TSSceneLayer::Mthd_geo_is_auto_activate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(((__int64)i_obj_p[2].vfptr->get_scope_context & 0x80) != 0);
  }
}

// File Line: 212
// RVA: 0x4FD6D0
void __fastcall UFG::TSSceneLayer::Mthd_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)&i_obj_p[2].vfptr->as_instance);
  }
}

// File Line: 226
// RVA: 0x4FBC70
void __fastcall UFG::TSSceneLayer::Mthd_get_bounds_min(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&i_obj_p[2].vfptr[1].is_actor);
  }
}

// File Line: 240
// RVA: 0x4FBC30
void __fastcall UFG::TSSceneLayer::Mthd_get_bounds_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)((char *)&i_obj_p[2].vfptr[1].as_instance + 4));
  }
}

// File Line: 251
// RVA: 0x4FB040
void __fastcall UFG::TSSceneLayer::Mthd_getSimObjects(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSList *v3; // rax
  SSList *v4; // r13
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rax
  __int64 v7; // rbp
  SSInstance *(__fastcall **p_get_data_by_name)(SSObjectBase *, ASymbol *); // rax
  __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  SSClass *v11; // r14
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v14; // eax
  __int64 v15; // rcx
  SSInstance **i_array_p; // rax
  SSInstance *v17; // rdx
  unsigned int v18; // eax
  SSInstance *(__fastcall **v20)(SSObjectBase *, ASymbol *); // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
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
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v7 = (__int64)vfptr[1].__vecDelDtor - 88;
    p_get_data_by_name = &vfptr[-1].get_data_by_name;
    v20 = p_get_data_by_name;
    if ( (SSInstance *(__fastcall **)(SSObjectBase *, ASymbol *))v7 == p_get_data_by_name )
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
        pool = SSInstance::get_pool();
        if ( pool->i_pool.i_count )
        {
          v18 = pool->i_pool.i_count - 1;
          pool->i_pool.i_count = v18;
          v15 = v18;
          i_array_p = pool->i_pool.i_array_p;
          goto LABEL_18;
        }
        if ( !pool->i_exp_pool.i_count )
          AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
        i_count = pool->i_exp_pool.i_count;
        if ( i_count )
        {
          v14 = i_count - 1;
          pool->i_exp_pool.i_count = v14;
          v15 = v14;
          i_array_p = pool->i_exp_pool.i_array_p;
LABEL_18:
          v17 = i_array_p[v15];
          goto LABEL_19;
        }
        v17 = 0i64;
LABEL_19:
        v17->i_class_p = v11;
        v17->i_user_data = v10;
        v17->i_ref_count = 1;
        v17->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
        SSList::append(v4, v17, 1);
LABEL_20:
        v9 = *(_QWORD *)(v9 + 72) - 64i64;
      }
      while ( v9 != v7 + 80 );
      p_get_data_by_name = v20;
LABEL_22:
      v7 = *(_QWORD *)(v7 + 96) - 88i64;
      if ( (SSInstance *(__fastcall **)(SSObjectBase *, ASymbol *))v7 == p_get_data_by_name )
      {
LABEL_23:
        *ppResult = SSList::as_instance(v4);
        return;
      }
    }
  }
}

// File Line: 273
// RVA: 0x4FAEA0
void __fastcall UFG::TSSceneLayer::Mthd_getObjectPropertySets(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSList *v3; // rax
  SSList *v4; // r15
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rax
  __int64 v7; // rsi
  SSInstance *(__fastcall **p_get_data_by_name)(SSObjectBase *, ASymbol *); // rax
  unsigned int v9; // r12d
  unsigned int v10; // edi
  UFG::qPropertySet *Segment; // r14
  SSClass *v12; // r13
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v15; // eax
  __int64 v16; // rcx
  SSInstance **i_array_p; // rax
  SSInstance *v18; // rdx
  unsigned int v19; // eax
  SSInstance *(__fastcall **v21)(SSObjectBase *, ASymbol *); // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
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
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v7 = (__int64)vfptr[1].__vecDelDtor - 88;
    p_get_data_by_name = &vfptr[-1].get_data_by_name;
    v21 = p_get_data_by_name;
    if ( (SSInstance *(__fastcall **)(SSObjectBase *, ASymbol *))v7 == p_get_data_by_name )
      goto LABEL_21;
    while ( 1 )
    {
      v9 = *(_DWORD *)(v7 + 108);
      v10 = 0;
      if ( !v9 )
        goto LABEL_20;
      do
      {
        Segment = (UFG::qPropertySet *)UFG::RoadNetworkResource::GetSegment((UFG::RoadNetworkResource *)v7, v10);
        UFG::qPropertySet::AddRef(Segment);
        v12 = UFG::SkookumMgr::mspPropertySetClass;
        pool = SSInstance::get_pool();
        if ( pool->i_pool.i_count )
        {
          v19 = pool->i_pool.i_count - 1;
          pool->i_pool.i_count = v19;
          v16 = v19;
          i_array_p = pool->i_pool.i_array_p;
        }
        else
        {
          if ( !pool->i_exp_pool.i_count )
            AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
          i_count = pool->i_exp_pool.i_count;
          if ( !i_count )
          {
            v18 = 0i64;
            goto LABEL_18;
          }
          v15 = i_count - 1;
          pool->i_exp_pool.i_count = v15;
          v16 = v15;
          i_array_p = pool->i_exp_pool.i_array_p;
        }
        v18 = i_array_p[v16];
LABEL_18:
        v18->i_class_p = v12;
        v18->i_user_data = (unsigned __int64)Segment;
        v18->i_ref_count = 1;
        v18->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
        SSList::append(v4, v18, 1);
        ++v10;
      }
      while ( v10 < v9 );
      p_get_data_by_name = v21;
LABEL_20:
      v7 = *(_QWORD *)(v7 + 96) - 88i64;
      if ( (SSInstance *(__fastcall **)(SSObjectBase *, ASymbol *))v7 == p_get_data_by_name )
      {
LABEL_21:
        *ppResult = SSList::as_instance(v4);
        return;
      }
    }
  }
}

// File Line: 299
// RVA: 0x4E6570
void __fastcall UFG::TSSceneLayer::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseTreeRB *Layer; // rax

  if ( ppResult )
  {
    Layer = UFG::Scene::FindLayer(
              &UFG::Scene::msDefault,
              (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    if ( Layer )
      *ppResult = SSInstance::pool_new(UFG::TSSceneLayer::mspSceneLayerClass, (unsigned __int64)Layer);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 319
// RVA: 0x4E82C0
void __fastcall UFG::TSSceneLayer::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  UFG::qBaseTreeRB *Layer; // rbp
  unsigned int i_user_data; // ebx
  char *v6; // rax

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    Layer = UFG::Scene::FindOrCreateLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)&i_data_p->i_user_data);
    if ( !Layer )
    {
      i_user_data = i_data_p->i_user_data;
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_data_p->i_user_data);
      UFG::qPrintf(
        "Failed to find scene layer: 0x%08x [%s] perhaps it needs to be tagged as global?\n",
        i_user_data,
        v6);
    }
    *ppResult = SSInstance::pool_new(UFG::TSSceneLayer::mspSceneLayerClass, (unsigned __int64)Layer);
  }
}

// File Line: 352
// RVA: 0x4E6F50
void __fastcall UFG::TSSceneLayer::MthdC_geo_set_active_category(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GeographicalLayerManager::SetActiveCategory((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

