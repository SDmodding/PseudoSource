// File Line: 79
// RVA: 0x4CE5A0
void UFG::TSAudio::BindAtomics(void)
{
  UFG::TSAudio::mspAudioClass = (SSActorClass *)SSBrain::get_class("Audio");
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "destroy",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "create",
    UFG::TSAudio::MthdC_create,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "get_named",
    UFG::TSAudio::MthdC_get_named,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "play_sound",
    UFG::TSAudio::MthdC_play_sound,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "set_rtpc",
    UFG::TSAudio::MthdC_set_rtpc,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "load_file_package",
    UFG::TSAudio::MthdC_load_file_package,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSAudio::mspAudioClass->vfptr,
    "unload_file_package",
    UFG::TSAudio::MthdC_unload_file_package,
    1,
    0);
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
  SSData **v2; // rdx
  SSInstance *v3; // rbx
  bool v4; // zf
  const char ***v5; // rbx
  UFG::qVector3 *v6; // rdx
  const char **v7; // rax
  UFG::OneShot *v8; // rbx
  unsigned int v9; // eax
  UFG::OneShotHandle pHandle; // [rsp+40h] [rbp+8h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = &v3->i_user_data == 0i64;
  v5 = (const char ***)&v3->i_user_data;
  v6 = (UFG::qVector3 *)v2[1]->i_data_p->i_user_data;
  if ( !v4 && v6 )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, v6);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      v7 = *v5;
      v8 = pHandle.m_pOneShot;
      v9 = UFG::TiDo::CalcWwiseUid(*v7);
      UFG::OneShot::Play(v8, v9);
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 185
// RVA: 0x4EE940
void __fastcall UFG::TSAudio::MthdC_set_rtpc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSData *v3; // rax
  float *v4; // rbx
  const char ***v5; // rsi
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *v7; // rdi
  unsigned int v8; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[2];
  v4 = (float *)&v3->i_data_p->i_user_data;
  v5 = (const char ***)&v2[1]->i_data_p->i_user_data;
  if ( v2[1]->i_data_p != (SSInstance *)-32i64 && v3->i_data_p != (SSInstance *)-32i64 )
  {
    v6 = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0)->mpSimObj.m_pPointer;
    if ( v6 )
      v7 = UFG::SimObject::GetComponentOfType(v6, UFG::HkAudioEntityComponent::_TypeUID);
    else
      v7 = 0i64;
    v8 = UFG::TiDo::CalcWwiseUid(**v5);
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v7[1], v8, *v4);
  }
}

// File Line: 209
// RVA: 0x4EAB40
void __fastcall UFG::TSAudio::MthdC_load_file_package(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  const char ***v3; // rax
  const char ***v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+50h] [rbp+18h]

  v2 = pScope->i_data.i_array_p;
  v3 = (const char ***)&v2[1]->i_data_p->i_user_data;
  v4 = (const char ***)&(*v2)->i_data_p->i_user_data;
  if ( (*v2)->i_data_p != (SSInstance *)-32i64 && v2[1]->i_data_p != (SSInstance *)-32i64 )
  {
    v7 = &result;
    v5 = UFG::qSymbol::create_from_string(&result, **v3);
    UFG::TiDo::LoadFilePackage(**v4, (__int64)v5, 0, 0);
  }
}

// File Line: 228
// RVA: 0x4F2AA0
void __fastcall UFG::TSAudio::MthdC_unload_file_package(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax

  v2 = pScope->i_data.i_array_p;
  if ( (*v2)->i_data_p != (SSInstance *)-32i64 )
    UFG::TiDo::UnloadFilePackage(*(const char **)(*v2)->i_data_p->i_user_data);
}

