// File Line: 54
// RVA: 0x4CC670
SSInstance *__fastcall UFG::TSMarker::AsInstance(UFG::MarkerBase *marker)
{
  int v2; // eax
  SSClass *v3; // rcx

  v2 = ((__int64 (__fastcall *)(UFG::MarkerBase *))marker->vfptr[16].__vecDelDtor)(marker);
  if ( v2 == 4 )
    return SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)marker);
  if ( v2 == 8 )
    return SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)marker);
  v3 = UFG::TSInterestPoint::mspInterestPointClass;
  if ( v2 != 512 )
    v3 = UFG::TSMarker::mspMarkerClass;
  return SSInstance::pool_new(v3, (unsigned __int64)marker);
}

// File Line: 84
// RVA: 0x4E0F30
UFG::qBaseTreeRB *__fastcall UFG::TSMarker::GetArgByNameOrInstance(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSInstance *i_data_p; // rdi
  SSClass *i_class_p; // rbx
  SSClass *i_superclass_p; // rcx

  i_data_p = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( UFG::TSMarker::mspMarkerClass == i_class_p )
      return (UFG::qBaseTreeRB *)i_data_p->i_user_data;
    i_superclass_p = i_class_p->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, UFG::TSMarker::mspMarkerClass) )
        return (UFG::qBaseTreeRB *)i_data_p->i_user_data;
    }
    if ( i_class_p == SSBrain::c_symbol_class_p )
      return UFG::MarkerBase::GetNamed((UFG::qSymbol *)&i_data_p->i_user_data);
  }
  return 0i64;
}

// File Line: 116
// RVA: 0x4D4290
void UFG::TSMarker::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  UFG::TSMarker::mspMarkerClass = SSBrain::get_class("Marker");
  SSClass::register_method_func(
    UFG::TSMarker::mspMarkerClass,
    "get_name",
    UFG::TSMarker::Mthd_get_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSMarker::mspMarkerClass,
    "get_xform",
    UFG::TSMarker::Mthd_get_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSMarker::mspMarkerClass,
    "set_pos",
    UFG::TSMarker::Mthd_set_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSMarker::mspMarkerClass,
    "set_xform",
    UFG::TSMarker::Mthd_set_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSMarker::mspMarkerClass,
    "get_properties",
    UFG::TSMarker::Mthd_get_properties,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "find_named", UFG::TSMarker::MthdC_find_named, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "get_named", UFG::TSMarker::MthdC_get_named, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSMarker::mspMarkerClass,
    "getInstances",
    UFG::TSMarker::MthdC_getInstances,
    1,
    rebindb);
}

// File Line: 183
// RVA: 0x50B320
void __fastcall UFG::TSMarker::Mthd_set_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::TransformNodeComponent *set_data_by_name; // rdi
  UFG::TransformNodeComponent *i_user_data; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  set_data_by_name = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr[1].set_data_by_name;
  i_user_data = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::TransformNodeComponent::UpdateWorldTransform(i_user_data);
  UFG::TransformNodeComponent::SetWorldTransform(set_data_by_name, &i_user_data->mWorldTransform);
}

// File Line: 195
// RVA: 0x4E6520
void __fastcall UFG::TSMarker::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseTreeRB *Named; // rax

  if ( ppResult )
  {
    Named = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    if ( Named )
      *ppResult = UFG::TSMarker::AsInstance((UFG::MarkerBase *)Named);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 211
// RVA: 0x4FDEA0
void __fastcall UFG::TSMarker::Mthd_get_properties(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r9
  __int64 v3; // r8
  SSObjectBaseVtbl *vfptr; // rax
  void (__fastcall *set_data_by_name)(SSObjectBase *, ASymbol *, SSInstance *); // rcx
  UFG::qPropertySet *v7; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( ppResult && vfptr )
  {
    set_data_by_name = vfptr->set_data_by_name;
    if ( set_data_by_name )
      v3 = *((_QWORD *)set_data_by_name + 10);
    v7 = *(UFG::qPropertySet **)(v3 + 144);
    if ( !v7 )
      v7 = *(UFG::qPropertySet **)(v3 + 152);
    UFG::qPropertySet::AddRef(v7);
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v7);
  }
}

// File Line: 225
// RVA: 0x4E8280
void __fastcall UFG::TSMarker::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseTreeRB *Named; // rax

  if ( ppResult )
  {
    Named = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *ppResult = UFG::TSMarker::AsInstance((UFG::MarkerBase *)Named);
  }
}

// File Line: 248
// RVA: 0x4E6F70
void __fastcall UFG::TSMarker::MthdC_getInstances(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSList *v3; // rax
  SSList *v4; // rsi
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *Markers; // rbp
  UFG::qBaseTreeRB *i; // rax
  unsigned __int64 v7; // rbx
  int v8; // eax
  SSClass *v9; // rcx
  SSInstance *v10; // rax

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
    Markers = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)UFG::MarkerBase::GetMarkers();
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(Markers);
          ;
          i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)Markers, (UFG::qBaseNodeRB *)(v7 + 72)) )
    {
      v7 = i ? (unsigned __int64)&i[-1] : 0i64;
      if ( !v7 )
        break;
      v8 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v7 + 128i64))(v7);
      if ( v8 == 4 )
      {
        v9 = UFG::TSTriggerRegion::mspTriggerRegionClass;
      }
      else if ( v8 == 8 )
      {
        v9 = UFG::TSSpawnPoint::mspSpawnPointClass;
      }
      else
      {
        v9 = UFG::TSInterestPoint::mspInterestPointClass;
        if ( v8 != 512 )
          v9 = UFG::TSMarker::mspMarkerClass;
      }
      v10 = SSInstance::pool_new(v9, v7);
      SSList::append(v4, v10, 1);
    }
    *ppResult = SSList::as_instance(v4);
  }
}

