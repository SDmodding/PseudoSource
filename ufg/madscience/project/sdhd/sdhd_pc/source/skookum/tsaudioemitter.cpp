// File Line: 68
// RVA: 0x4CE6B0
void UFG::TSAudioEmitter::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  UFG::TSAudioEmitter::mspAudioEmitterClass = SSBrain::get_class("AudioEmitter");
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "get_name",
    UFG::TSMarker::Mthd_get_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "get_xform",
    UFG::TSMarker::Mthd_get_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "set_pos",
    UFG::TSMarker::Mthd_set_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "turn_off",
    UFG::TSAudioEmitter::Mthd_turn_off,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "turn_on",
    UFG::TSAudioEmitter::Mthd_turn_on,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "play_one_shot",
    UFG::TSAudioEmitter::Mthd_play_one_shot,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "play",
    UFG::TSAudioEmitter::Mthd_play,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "stop",
    UFG::TSAudioEmitter::Mthd_stop,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "set_rtpc",
    UFG::TSAudioEmitter::Mthd_set_rtpc,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "set_event",
    UFG::TSAudioEmitter::Mthd_set_event,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "is_playing",
    UFG::TSAudioEmitter::Mthd_is_playing,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "audio_set_obstruction_occlusion",
    UFG::TSAudioEmitter::Mthd_audio_set_obstruction_occlusion,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "find_named",
    UFG::TSAudioEmitter::MthdC_find_named,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "get_named",
    UFG::TSAudioEmitter::MthdC_get_named,
    1,
    rebinda);
}

// File Line: 100
// RVA: 0x4FD690
void __fastcall UFG::TSMarker::Mthd_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)&i_obj_p[2].vfptr[1]);
  }
}

// File Line: 114
// RVA: 0x4FF6C0
void __fastcall UFG::TSMarker::Mthd_get_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = UFG::TSTransform::AsInstance((UFG::TransformNodeComponent *)i_obj_p[2].vfptr[1].set_data_by_name);
  }
}

// File Line: 128
// RVA: 0x5093B0
void __fastcall UFG::TSMarker::Mthd_set_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::TransformNodeComponent::SetWorldTranslation(
    (UFG::TransformNodeComponent *)i_obj_p[2].vfptr[1].set_data_by_name,
    (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 140
// RVA: 0x4E63C0
void __fastcall UFG::TSAudioEmitter::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, i_user_data)) != 0i64
      && v4 != (UFG::qBaseTreeRB *)112 )
    {
      *ppResult = SSInstance::pool_new(UFG::TSAudioEmitter::mspAudioEmitterClass, (unsigned __int64)&v4[-2].mNULL);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 158
// RVA: 0x4E8170
void __fastcall UFG::TSAudioEmitter::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax
  unsigned __int64 p_mNULL; // rdx

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, i_user_data)) != 0i64 )
    {
      p_mNULL = (unsigned __int64)&v4[-2].mNULL;
    }
    else
    {
      p_mNULL = 0i64;
    }
    *ppResult = SSInstance::pool_new(UFG::TSAudioEmitter::mspAudioEmitterClass, p_mNULL);
  }
}

// File Line: 185
// RVA: 0x50DDD0
void __fastcall UFG::TSAudioEmitter::Mthd_turn_off(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    if ( UFG::AudioEmitterMarker::EmitterExists((UFG::AudioEmitterMarker *)vfptr) )
    {
      UFG::AudioEmitterMarker::Stop((UFG::AudioEmitterMarker *)vfptr, 0x7D0u);
      LOBYTE(vfptr[3].get_obj_type) |= 2u;
    }
  }
}

// File Line: 202
// RVA: 0x50DE20
void __fastcall UFG::TSAudioEmitter::Mthd_turn_on(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    if ( UFG::AudioEmitterMarker::EmitterExists((UFG::AudioEmitterMarker *)vfptr) )
      LOBYTE(vfptr[3].get_obj_type) &= ~2u;
  }
}

// File Line: 220
// RVA: 0x505C20
void __fastcall UFG::TSAudioEmitter::Mthd_play(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::AudioEmitterMarker *vfptr; // rbx
  UFG::qWiseSymbol source; // [rsp+40h] [rbp+8h] BYREF
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF
  UFG::qWiseSymbol *p_source; // [rsp+58h] [rbp+20h]

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::AudioEmitterMarker *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    source.mUID = result.mUID;
    _((AMD_HD3D *)result.mUID);
    p_source = &source;
    UFG::qWiseSymbol::operator=(&vfptr->m_eventId, &source);
    _((AMD_HD3D *)source.mUID);
    UFG::AudioEmitterMarker::Play(vfptr);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 239
// RVA: 0x50C070
void __fastcall UFG::TSAudioEmitter::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::AudioEmitterMarker *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::AudioEmitterMarker *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    if ( UFG::AudioEmitterMarker::EmitterExists((UFG::AudioEmitterMarker *)i_obj_p[2].vfptr) )
      UFG::AudioEmitterMarker::Stop(vfptr, 0x7D0u);
  }
}

// File Line: 258
// RVA: 0x505E50
void __fastcall UFG::TSAudioEmitter::Mthd_play_one_shot(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::AudioEmitterMarker *vfptr; // rbx
  unsigned int v4; // eax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::AudioEmitterMarker *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    v4 = UFG::TiDo::CalcWwiseUid(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    UFG::AudioEmitterMarker::PlayOneShot(vfptr, v4);
  }
}

// File Line: 278
// RVA: 0x50A360
void __fastcall UFG::TSAudioEmitter::Mthd_set_rtpc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // r8
  SSData *v4; // rax
  SSObjectBase *i_obj_p; // rdx
  SSInstance *v6; // rdi
  SSObjectBaseVtbl *vfptr; // rbx
  unsigned int v8; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1];
  i_obj_p = pScope->i_scope_p.i_obj_p;
  v6 = v4->i_data_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    v8 = UFG::TiDo::CalcWwiseUid(*(const char **)i_data_p->i_user_data);
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)vfptr[2].as_instance, v8, *(float *)&v6->i_user_data);
  }
}

// File Line: 299
// RVA: 0x507DD0
void __fastcall UFG::TSAudioEmitter::Mthd_set_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::AudioEmitterMarker *vfptr; // rbx
  UFG::qWiseSymbol source; // [rsp+40h] [rbp+8h] BYREF
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF
  UFG::qWiseSymbol *p_source; // [rsp+58h] [rbp+20h]

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::AudioEmitterMarker *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    source.mUID = result.mUID;
    _((AMD_HD3D *)result.mUID);
    p_source = &source;
    UFG::qWiseSymbol::operator=(&vfptr->m_eventId, &source);
    _((AMD_HD3D *)source.mUID);
    UFG::AudioEmitterMarker::Reset(vfptr);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 319
// RVA: 0x502A50
void __fastcall UFG::TSAudioEmitter::Mthd_is_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax
  bool (__fastcall *is_actor)(SSObjectBase *); // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( vfptr && (is_actor = vfptr[2].is_actor) != 0i64 )
      *ppResult = SSBoolean::pool_new((*((_BYTE *)is_actor + 144) & 0x40) != 0);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 343
// RVA: 0x4F5E60
void __fastcall UFG::TSAudioEmitter::Mthd_audio_set_obstruction_occlusion(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdx
  SSInstance *v6; // rcx
  float v7; // xmm1_4

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v6 = i_array_p[1]->i_data_p;
    v7 = *(float *)&i_data_p->i_user_data;
    if ( v7 >= 0.0 || *(float *)&v6->i_user_data >= 0.0 )
    {
      UFG::AudioEntity::SetObstructionAndOcclusionTargets(
        (UFG::AudioEntity *)vfptr[2].as_instance,
        v7,
        *(float *)&v6->i_user_data,
        0);
      *((_BYTE *)vfptr[2].as_instance + 301) = 1;
    }
    else
    {
      *((_BYTE *)vfptr[2].as_instance + 301) = 0;
      *((_BYTE *)vfptr[2].as_instance + 299) = 1;
    }
  }
}

