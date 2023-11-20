// File Line: 58
// RVA: 0x4D6D70
void UFG::TSSpyPC::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("SpyPC");
  SSClass::register_method_func(v0, "private_enable_user_input", UFG::TSSpyPC::MthdC_enable_user_input, 1, 0);
  SSClass::register_method_func(v0, "start_profiling_characters", UFG::TSSpyPC::MthdC_start_profiling_characters, 1, 0);
  SSClass::register_method_func(v0, "fail_spycam", UFG::TSSpyPC::MthdC_fail_spycam, 1, 0);
  SSClass::register_method_func(v0, "stop_fla_loading", UFG::TSSpyPC::MthdC_stop_fla_loading, 1, 0);
  SSClass::register_method_func(v0, "cancel_triad_sensitive", UFG::TSSpyPC::MthdC_cancel_triad_sensitive, 1, 0);
  SSClass::register_coroutine_func(v0, "_wait_until_SpyPC_finishes", UFG::TSSpyPC::Coro_wait_until_SpyPC_finishes, 0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_at_neighborhood_screen",
    UFG::TSSpyPC::Coro_wait_until_at_neighborhood_screen,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_at_cameras_screen",
    UFG::TSSpyPC::Coro_wait_until_at_cameras_screen,
    0);
  SSClass::register_coroutine_func(v0, "_wait_until_viewing_camera", UFG::TSSpyPC::Coro_wait_until_viewing_camera, 0);
}

// File Line: 83
// RVA: 0x4F26F0
void __fastcall UFG::TSSpyPC::MthdC_stop_fla_loading(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenSpyCam *v2; // rax

  v2 = (UFG::UIHKScreenSpyCam *)UFG::UIScreenManagerBase::getScreen(
                                  (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                  "SpyCam");
  if ( v2 )
    UFG::UIHKScreenSpyCam::stopLoadingLoop(v2);
}

// File Line: 94
// RVA: 0x4E4260
void __fastcall UFG::TSSpyPC::MthdC_cancel_triad_sensitive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenSpyCam *v2; // rax

  v2 = (UFG::UIHKScreenSpyCam *)UFG::UIScreenManagerBase::getScreen(
                                  (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                  "SpyCam");
  if ( v2 )
    UFG::UIHKScreenSpyCam::cancelTriadSensitive(v2);
}

// File Line: 106
// RVA: 0x4E6230
void __fastcall UFG::TSSpyPC::MthdC_fail_spycam(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *v2; // rax
  SSClass *v3; // rax
  SSInstance *v4; // rcx
  SSInstance *args_pp; // [rsp+60h] [rbp+18h]

  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  v2 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  if ( v2 )
  {
    LOBYTE(v2[1].vfptr) = 1;
    v3 = SSBrain::get_class("SpyPC");
    if ( LODWORD(v3[1].vfptr) )
      v4 = **(SSInstance ***)&v3[1].i_name.i_uid;
    else
      v4 = 0i64;
    args_pp = 0i64;
    SSInstance::coroutine_call(v4, (ASymbol *)&qSymbol__fail_camera, &args_pp, 0, 1, 0.0, 0i64, 0i64);
  }
}

// File Line: 127
// RVA: 0x4E5360
void __fastcall UFG::TSSpyPC::MthdC_enable_user_input(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ScriptCameraComponent::mbUserInputEnabled = 1;
}

// File Line: 134
// RVA: 0x4F25A0
void __fastcall UFG::TSSpyPC::MthdC_start_profiling_characters(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v2; // rcx
  UFG::ScriptCameraComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::ScriptCameraComponent::_TypeUID);
    if ( v3 )
      UFG::ScriptCameraComponent::EnableProfiling(v3);
  }
}

// File Line: 145
// RVA: 0x4DEB80
bool __fastcall UFG::TSSpyPC::Coro_wait_until_SpyPC_finishes(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  return v1 && LOBYTE(v1[1].vfptr);
}

// File Line: 159
// RVA: 0x4DEC40
bool __fastcall UFG::TSSpyPC::Coro_wait_until_at_neighborhood_screen(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  return v1 && LODWORD(v1[1].mPrev) == 1;
}

// File Line: 177
// RVA: 0x4DEBC0
char __fastcall UFG::TSSpyPC::Coro_wait_until_at_cameras_screen(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  UFG::UIScreen *v2; // rax
  unsigned __int64 v3; // rdx
  _BYTE *v4; // rcx
  unsigned __int64 v5; // r8
  signed __int64 v6; // rdx

  v1 = pScope;
  v2 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  if ( v2 && LODWORD(v2[1].mPrev) == 2 )
  {
    v3 = (*v1->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = *(_BYTE **)v3;
    v5 = *(_QWORD *)v3 + *(unsigned int *)(v3 + 8) + 1i64;
    if ( *(_QWORD *)v3 >= v5 )
      return 1;
    v6 = (char *)v2[1].mNext - v4;
    while ( *v4 == v4[v6] )
    {
      if ( (unsigned __int64)++v4 >= v5 )
        return 1;
    }
  }
  return 0;
}

// File Line: 197
// RVA: 0x4DF380
bool __fastcall UFG::TSSpyPC::Coro_wait_until_viewing_camera(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  return v1 && LODWORD(v1[1].mPrev) == 3;
}

