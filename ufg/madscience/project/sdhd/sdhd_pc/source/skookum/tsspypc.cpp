// File Line: 58
// RVA: 0x4D6D70
void UFG::TSSpyPC::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("SpyPC");
  SSClass::register_method_func(v0, "private_enable_user_input", UFG::TSSpyPC::MthdC_enable_user_input, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "start_profiling_characters",
    UFG::TSSpyPC::MthdC_start_profiling_characters,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "fail_spycam", UFG::TSSpyPC::MthdC_fail_spycam, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "stop_fla_loading", UFG::TSSpyPC::MthdC_stop_fla_loading, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "cancel_triad_sensitive", UFG::TSSpyPC::MthdC_cancel_triad_sensitive, 1, rebindd);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_SpyPC_finishes",
    UFG::TSSpyPC::Coro_wait_until_SpyPC_finishes,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_at_neighborhood_screen",
    UFG::TSSpyPC::Coro_wait_until_at_neighborhood_screen,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_at_cameras_screen",
    UFG::TSSpyPC::Coro_wait_until_at_cameras_screen,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_viewing_camera",
    UFG::TSSpyPC::Coro_wait_until_viewing_camera,
    SSBindFlag_instance_no_rebind);
}

// File Line: 83
// RVA: 0x4F26F0
void __fastcall UFG::TSSpyPC::MthdC_stop_fla_loading(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenSpyCam *Screen; // rax

  Screen = (UFG::UIHKScreenSpyCam *)UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyCam");
  if ( Screen )
    UFG::UIHKScreenSpyCam::stopLoadingLoop(Screen);
}

// File Line: 94
// RVA: 0x4E4260
void __fastcall UFG::TSSpyPC::MthdC_cancel_triad_sensitive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenSpyCam *Screen; // rax

  Screen = (UFG::UIHKScreenSpyCam *)UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyCam");
  if ( Screen )
    UFG::UIHKScreenSpyCam::cancelTriadSensitive(Screen);
}

// File Line: 106
// RVA: 0x4E6230
void __fastcall UFG::TSSpyPC::MthdC_fail_spycam(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax
  SSClass *v3; // rax
  SSInstance *v4; // rcx
  SSInstance *args_pp; // [rsp+60h] [rbp+18h] BYREF

  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  if ( Screen )
  {
    LOBYTE(Screen[1].vfptr) = 1;
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
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ScriptCameraComponent::EnableProfiling(ComponentOfType);
  }
}

// File Line: 145
// RVA: 0x4DEB80
bool __fastcall UFG::TSSpyPC::Coro_wait_until_SpyPC_finishes(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  return Screen && LOBYTE(Screen[1].vfptr);
}

// File Line: 159
// RVA: 0x4DEC40
bool __fastcall UFG::TSSpyPC::Coro_wait_until_at_neighborhood_screen(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  return Screen && LODWORD(Screen[1].mPrev) == 1;
}

// File Line: 177
// RVA: 0x4DEBC0
char __fastcall UFG::TSSpyPC::Coro_wait_until_at_cameras_screen(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax
  unsigned __int64 i_user_data; // rdx
  _BYTE *v4; // rcx
  unsigned __int64 v5; // r8
  __int64 v6; // rdx

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  if ( Screen && LODWORD(Screen[1].mPrev) == 2 )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = *(_BYTE **)i_user_data;
    v5 = *(_QWORD *)i_user_data + *(unsigned int *)(i_user_data + 8) + 1i64;
    if ( *(_QWORD *)i_user_data >= v5 )
      return 1;
    v6 = (char *)Screen[1].mNext - v4;
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
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  return Screen && LODWORD(Screen[1].mPrev) == 3;
}

