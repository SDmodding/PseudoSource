// File Line: 54
// RVA: 0x4CC670
SSInstance *__fastcall UFG::TSMarker::AsInstance(UFG::MarkerBase *marker)
{
  UFG::MarkerBase *v1; // rbx
  int v2; // eax
  SSClass *v3; // rcx

  v1 = marker;
  v2 = ((__int64 (*)(void))marker->vfptr[16].__vecDelDtor)();
  if ( v2 == 4 )
    return SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)v1);
  if ( v2 == 8 )
    return SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)v1);
  v3 = UFG::TSInterestPoint::mspInterestPointClass;
  if ( v2 != 512 )
    v3 = UFG::TSMarker::mspMarkerClass;
  return SSInstance::pool_new(v3, (unsigned __int64)v1);
}

// File Line: 84
// RVA: 0x4E0F30
UFG::qBaseTreeRB *__fastcall UFG::TSMarker::GetArgByNameOrInstance(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSInstance *v2; // rdi
  SSClass *v3; // rbx
  SSClass *v4; // rcx

  v2 = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( v2 )
  {
    v3 = v2->i_class_p;
    if ( UFG::TSMarker::mspMarkerClass == v3 )
      return (UFG::qBaseTreeRB *)v2->i_user_data;
    v4 = v3->i_superclass_p;
    if ( v4 )
    {
      if ( SSClass::is_class(v4, UFG::TSMarker::mspMarkerClass) )
        return (UFG::qBaseTreeRB *)v2->i_user_data;
    }
    if ( v3 == SSBrain::c_symbol_class_p )
      return UFG::MarkerBase::GetNamed((UFG::qSymbol *)&v2->i_user_data);
  }
  return 0i64;
}

// File Line: 116
// RVA: 0x4D4290
void UFG::TSMarker::BindAtomics(void)
{
  UFG::TSMarker::mspMarkerClass = SSBrain::get_class("Marker");
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "get_name", UFG::TSMarker::Mthd_get_name, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "get_xform", UFG::TSMarker::Mthd_get_xform, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "set_pos", UFG::TSMarker::Mthd_set_pos, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "set_xform", UFG::TSMarker::Mthd_set_xform, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "get_properties", UFG::TSMarker::Mthd_get_properties, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "find_named", UFG::TSMarker::MthdC_find_named, 1, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "get_named", UFG::TSMarker::MthdC_get_named, 1, 0);
  SSClass::register_method_func(UFG::TSMarker::mspMarkerClass, "getInstances", UFG::TSMarker::MthdC_getInstances, 1, 0);
}

// File Line: 183
// RVA: 0x50B320
void __fastcall UFG::TSMarker::Mthd_set_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::TransformNodeComponent *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::TransformNodeComponent *)v2[2].vfptr[1].set_data_by_name;
  v4 = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  UFG::TransformNodeComponent::SetWorldTransform(v3, &v4->mWorldTransform);
}

// File Line: 195
// RVA: 0x4E6520
void __fastcall UFG::TSMarker::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::qBaseTreeRB *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    if ( v3 )
      *v2 = UFG::TSMarker::AsInstance((UFG::MarkerBase *)v3);
    else
      *v2 = SSBrain::c_nil_p;
  }
}

// File Line: 211
// RVA: 0x4FDEA0
void __fastcall UFG::TSMarker::Mthd_get_properties(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r9
  __int64 v3; // r8
  SSInstance **v4; // rdi
  SSObjectBaseVtbl *v5; // rax
  void (__fastcall *v6)(SSObjectBase *, ASymbol *, SSInstance *); // rcx
  UFG::qPropertySet *v7; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  v4 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = v2[2].vfptr;
  if ( ppResult && v5 )
  {
    v6 = v5->set_data_by_name;
    if ( v6 )
      v3 = *((_QWORD *)v6 + 10);
    v7 = *(UFG::qPropertySet **)(v3 + 144);
    if ( !v7 )
      v7 = *(UFG::qPropertySet **)(v3 + 152);
    UFG::qPropertySet::AddRef(v7);
    *v4 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v7);
  }
}

// File Line: 225
// RVA: 0x4E8280
void __fastcall UFG::TSMarker::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::qBaseTreeRB *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *v2 = UFG::TSMarker::AsInstance((UFG::MarkerBase *)v3);
  }
}

// File Line: 248
// RVA: 0x4E6F70
void __fastcall UFG::TSMarker::MthdC_getInstances(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSList *v3; // rax
  SSList *v4; // rsi
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v5; // rbp
  UFG::qBaseTreeRB *i; // rax
  unsigned __int64 v7; // rbx
  int v8; // eax
  SSClass *v9; // rcx
  SSInstance *v10; // rax

  if ( ppResult )
  {
    v2 = ppResult;
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
    v5 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)UFG::MarkerBase::GetMarkers();
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v5);
          ;
          i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)v5, (UFG::qBaseNodeRB *)(v7 + 72)) )
    {
      v7 = (unsigned __int64)(i ? &i[-1] : 0i64);
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
    *v2 = SSList::as_instance(v4);
  }
}

