// File Line: 79
// RVA: 0x4CE5A0
void UFG::TSAudio::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]

  UFG::TSAudio::mspAudioClass = (SSActorClass *)SSBrain::get_class("Audio");
  SSClass::register_method_func(
    UFG::TSAudio::mspAudioClass,
    "destroy",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(UFG::TSAudio::mspAudioClass, "create", UFG::TSAudio::MthdC_create, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(UFG::TSAudio::mspAudioClass, "get_named", UFG::TSAudio::MthdC_get_named, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(UFG::TSAudio::mspAudioClass, "play_sound", UFG::TSAudio::MthdC_play_sound, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(UFG::TSAudio::mspAudioClass, "set_rtpc", UFG::TSAudio::MthdC_set_rtpc, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSAudio::mspAudioClass,
    "load_file_package",
    UFG::TSAudio::MthdC_load_file_package,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSAudio::mspAudioClass,
    "unload_file_package",
    UFG::TSAudio::MthdC_unload_file_package,
    1,
    rebinde);
}

// File Line: 105
// RVA: 0x4E4880
void __fastcall UFG::TSAudio::MthdC_create(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  *ppResult = SSBrain::c_nil_p;
}

// File Line: 162
// RVA: 0x4EB320
void __fastcall UFG::TSAudio::MthdC_play_sound(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  bool v4; // zf
  const char ***p_i_user_data; // rbx
  UFG::qVector3 *i_user_data; // rdx
  const char **v7; // rax
  UFG::OneShot *m_pOneShot; // rbx
  unsigned int v9; // eax
  UFG::OneShotHandle pHandle; // [rsp+40h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = &i_data_p->i_user_data == 0i64;
  p_i_user_data = (const char ***)&i_data_p->i_user_data;
  i_user_data = (UFG::qVector3 *)i_array_p[1]->i_data_p->i_user_data;
  if ( !v4 && i_user_data )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, i_user_data);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      v7 = *p_i_user_data;
      m_pOneShot = pHandle.m_pOneShot;
      v9 = UFG::TiDo::CalcWwiseUid(*v7);
      UFG::OneShot::Play(m_pOneShot, v9);
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 185
// RVA: 0x4EE940
void __fastcall UFG::TSAudio::MthdC_set_rtpc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSData *v3; // rax
  float *p_i_user_data; // rbx
  const char ***v5; // rsi
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rdi
  unsigned int v8; // eax

  i_array_p = pScope->i_data.i_array_p;
  v3 = i_array_p[2];
  p_i_user_data = (float *)&v3->i_data_p->i_user_data;
  v5 = (const char ***)&i_array_p[1]->i_data_p->i_user_data;
  if ( i_array_p[1]->i_data_p != (SSInstance *)-32i64 && v3->i_data_p != (SSInstance *)-32i64 )
  {
    m_pPointer = UFG::TSActor::GetArgByNameOrInstance(pScope, 0)->mpSimObj.m_pPointer;
    if ( m_pPointer )
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HkAudioEntityComponent::_TypeUID);
    else
      ComponentOfType = 0i64;
    v8 = UFG::TiDo::CalcWwiseUid(**v5);
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&ComponentOfType[1], v8, *p_i_user_data);
  }
}

// File Line: 209
// RVA: 0x4EAB40
void __fastcall UFG::TSAudio::MthdC_load_file_package(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  const char ***p_i_user_data; // rax
  const char ***v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_result; // [rsp+50h] [rbp+18h]

  i_array_p = pScope->i_data.i_array_p;
  p_i_user_data = (const char ***)&i_array_p[1]->i_data_p->i_user_data;
  v4 = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 && i_array_p[1]->i_data_p != (SSInstance *)-32i64 )
  {
    p_result = &result;
    v5 = UFG::qSymbol::create_from_string(&result, **p_i_user_data);
    UFG::TiDo::LoadFilePackage(**v4, &v5->mUID, 0, 0);
  }
}

// File Line: 228
// RVA: 0x4F2AA0
void __fastcall UFG::TSAudio::MthdC_unload_file_package(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax

  i_array_p = pScope->i_data.i_array_p;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
    UFG::TiDo::UnloadFilePackage(*(const char **)(*i_array_p)->i_data_p->i_user_data);
}

