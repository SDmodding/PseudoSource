// File Line: 68
// RVA: 0x4CE6B0
void UFG::TSAudioEmitter::BindAtomics(void)
{
  UFG::TSAudioEmitter::mspAudioEmitterClass = SSBrain::get_class("AudioEmitter");
  SSClass::register_method_func(UFG::TSAudioEmitter::mspAudioEmitterClass, "get_name", UFG::TSMarker::Mthd_get_name, 0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "get_xform",
    UFG::TSMarker::Mthd_get_xform,
    0);
  SSClass::register_method_func(UFG::TSAudioEmitter::mspAudioEmitterClass, "set_pos", UFG::TSMarker::Mthd_set_pos, 0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "turn_off",
    UFG::TSAudioEmitter::Mthd_turn_off,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "turn_on",
    UFG::TSAudioEmitter::Mthd_turn_on,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "play_one_shot",
    UFG::TSAudioEmitter::Mthd_play_one_shot,
    0);
  SSClass::register_method_func(UFG::TSAudioEmitter::mspAudioEmitterClass, "play", UFG::TSAudioEmitter::Mthd_play, 0);
  SSClass::register_method_func(UFG::TSAudioEmitter::mspAudioEmitterClass, "stop", UFG::TSAudioEmitter::Mthd_stop, 0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "set_rtpc",
    UFG::TSAudioEmitter::Mthd_set_rtpc,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "set_event",
    UFG::TSAudioEmitter::Mthd_set_event,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "is_playing",
    UFG::TSAudioEmitter::Mthd_is_playing,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "audio_set_obstruction_occlusion",
    UFG::TSAudioEmitter::Mthd_audio_set_obstruction_occlusion,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "find_named",
    UFG::TSAudioEmitter::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSAudioEmitter::mspAudioEmitterClass,
    "get_named",
    UFG::TSAudioEmitter::MthdC_get_named,
    1,
    0);
}

// File Line: 100
// RVA: 0x4FD690
void __fastcall UFG::TSMarker::Mthd_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)&v3[2].vfptr[1]);
  }
}

// File Line: 114
// RVA: 0x4FF6C0
void __fastcall UFG::TSMarker::Mthd_get_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = UFG::TSTransform::AsInstance((UFG::TransformNodeComponent *)v2[2].vfptr[1].set_data_by_name);
  }
}

// File Line: 128
// RVA: 0x5093B0
void __fastcall UFG::TSMarker::Mthd_set_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  UFG::TransformNodeComponent::SetWorldTranslation(
    (UFG::TransformNodeComponent *)v2[2].vfptr[1].set_data_by_name,
    (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 140
// RVA: 0x4E63C0
void __fastcall UFG::TSAudioEmitter::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, v3)) != 0i64
      && v4 != (UFG::qBaseTreeRB *)112 )
    {
      *v2 = SSInstance::pool_new(UFG::TSAudioEmitter::mspAudioEmitterClass, (unsigned __int64)&v4[-2].mNULL);
    }
    else
    {
      *v2 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 158
// RVA: 0x4E8170
void __fastcall UFG::TSAudioEmitter::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  unsigned __int64 v5; // rdx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3 && (v4 = UFG::qBaseTreeRB::Get(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, v3)) != 0i64 )
      v5 = (unsigned __int64)&v4[-2].mNULL;
    else
      v5 = 0i64;
    *v2 = SSInstance::pool_new(UFG::TSAudioEmitter::mspAudioEmitterClass, v5);
  }
}

// File Line: 185
// RVA: 0x50DDD0
void __fastcall UFG::TSAudioEmitter::Mthd_turn_off(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
  {
    if ( UFG::AudioEmitterMarker::EmitterExists((UFG::AudioEmitterMarker *)v3) )
    {
      UFG::AudioEmitterMarker::Stop((UFG::AudioEmitterMarker *)v3, 0x7D0u);
      LOBYTE(v3[3].get_obj_type) |= 2u;
    }
  }
}

// File Line: 202
// RVA: 0x50DE20
void __fastcall UFG::TSAudioEmitter::Mthd_turn_on(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
  {
    if ( UFG::AudioEmitterMarker::EmitterExists((UFG::AudioEmitterMarker *)v3) )
      LOBYTE(v3[3].get_obj_type) &= 0xFDu;
  }
}

// File Line: 220
// RVA: 0x505C20
void __fastcall UFG::TSAudioEmitter::Mthd_play(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::AudioEmitterMarker *v3; // rbx
  UFG::qWiseSymbol source; // [rsp+40h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]
  UFG::qWiseSymbol *v6; // [rsp+58h] [rbp+20h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::AudioEmitterMarker *)v2[2].vfptr;
  if ( v3 )
  {
    UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    source.mUID = result.mUID;
    _((AMD_HD3D *)result.mUID);
    v6 = &source;
    UFG::qWiseSymbol::operator=(&v3->m_eventId, &source);
    _((AMD_HD3D *)source.mUID);
    UFG::AudioEmitterMarker::Play(v3);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 239
// RVA: 0x50C070
void __fastcall UFG::TSAudioEmitter::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::AudioEmitterMarker *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::AudioEmitterMarker *)v2[2].vfptr;
  if ( v3 )
  {
    if ( UFG::AudioEmitterMarker::EmitterExists((UFG::AudioEmitterMarker *)v2[2].vfptr) )
      UFG::AudioEmitterMarker::Stop(v3, 0x7D0u);
  }
}

// File Line: 258
// RVA: 0x505E50
void __fastcall UFG::TSAudioEmitter::Mthd_play_one_shot(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::AudioEmitterMarker *v3; // rbx
  unsigned int v4; // eax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::AudioEmitterMarker *)v2[2].vfptr;
  if ( v3 )
  {
    v4 = UFG::TiDo::CalcWwiseUid(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    UFG::AudioEmitterMarker::PlayOneShot(v3, v4);
  }
}

// File Line: 278
// RVA: 0x50A360
void __fastcall UFG::TSAudioEmitter::Mthd_set_rtpc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // r8
  SSData *v4; // rax
  SSObjectBase *v5; // rdx
  SSInstance *v6; // rdi
  SSObjectBaseVtbl *v7; // rbx
  unsigned int v8; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1];
  v5 = pScope->i_scope_p.i_obj_p;
  v6 = v4->i_data_p;
  if ( !v5 || pScope->i_scope_p.i_ptr_id != v5->i_ptr_id )
    v5 = 0i64;
  v7 = v5[2].vfptr;
  if ( v7 )
  {
    v8 = UFG::TiDo::CalcWwiseUid(*(const char **)v3->i_user_data);
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)v7[2].as_instance, v8, *(float *)&v6->i_user_data);
  }
}

// File Line: 299
// RVA: 0x507DD0
void __fastcall UFG::TSAudioEmitter::Mthd_set_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::AudioEmitterMarker *v3; // rbx
  UFG::qWiseSymbol source; // [rsp+40h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]
  UFG::qWiseSymbol *v6; // [rsp+58h] [rbp+20h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::AudioEmitterMarker *)v2[2].vfptr;
  if ( v3 )
  {
    UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    source.mUID = result.mUID;
    _((AMD_HD3D *)result.mUID);
    v6 = &source;
    UFG::qWiseSymbol::operator=(&v3->m_eventId, &source);
    _((AMD_HD3D *)source.mUID);
    UFG::AudioEmitterMarker::Reset(v3);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 319
// RVA: 0x502A50
void __fastcall UFG::TSAudioEmitter::Mthd_is_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax
  bool (__fastcall *v4)(SSObjectBase *); // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = v2[2].vfptr;
    if ( v3 )
    {
      v4 = v3[2].is_actor;
      if ( v4 )
        *ppResult = (SSInstance *)SSBoolean::pool_new((*((_BYTE *)v4 + 144) >> 6) & 1);
      else
        *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    }
    else
    {
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 343
// RVA: 0x4F5E60
void __fastcall UFG::TSAudioEmitter::Mthd_audio_set_obstruction_occlusion(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rbx
  SSData **v4; // rcx
  SSInstance *v5; // rdx
  SSInstance *v6; // rcx
  float v7; // xmm1_4

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = (*v4)->i_data_p;
    v6 = v4[1]->i_data_p;
    v7 = *(float *)&v5->i_user_data;
    if ( v7 >= 0.0 || *(float *)&v6->i_user_data >= 0.0 )
    {
      UFG::AudioEntity::SetObstructionAndOcclusionTargets(
        (UFG::AudioEntity *)v3[2].as_instance,
        v7,
        *(float *)&v6->i_user_data,
        0);
      *((_BYTE *)v3[2].as_instance + 301) = 1;
    }
    else
    {
      *((_BYTE *)v3[2].as_instance + 301) = 0;
      *((_BYTE *)v3[2].as_instance + 299) = 1;
    }
  }
}

