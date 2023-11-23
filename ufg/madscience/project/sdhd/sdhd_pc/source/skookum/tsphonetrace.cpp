// File Line: 51
// RVA: 0x4D4F50
void UFG::TSPhonetrace::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Phonetrace");
  SSClass::register_method_func(v0, "is_successful", UFG::TSPhonetrace::MthdC_is_successful, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "set_solution", UFG::TSPhonetrace::MthdC_set_solution, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "launch_signal_minigame",
    UFG::TSPhonetrace::MthdC_launch_signal_minigame,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "fail_minigame", UFG::TSPhonetrace::MthdC_fail_minigame, 1, rebindc);
}

// File Line: 73
// RVA: 0x4E6200
void __fastcall UFG::TSPhonetrace::MthdC_fail_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPhoneTraceMinigame *Screen; // rax

  Screen = (UFG::UIHKScreenPhoneTraceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                  UFG::UIScreenManager::s_instance,
                                                  "PhoneTraceMinigame");
  if ( Screen )
    UFG::UIHKScreenPhoneTraceMinigame::fail(Screen);
}

// File Line: 91
// RVA: 0x4EA6C0
void __fastcall UFG::TSPhonetrace::MthdC_launch_signal_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 i_user_data; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::UIScreenTextureManager *v6; // rax

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(UFG::TransformNodeComponent **)(i_user_data + 104);
  if ( !v3 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
    v3 = (UFG::TransformNodeComponent *)i_user_data;
  if ( v3 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    y = v3->mWorldTransform.v3.y;
    z = v3->mWorldTransform.v3.z;
    UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.x = v3->mWorldTransform.v3.x;
    UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.y = y;
    UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z = z;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "PhoneSignalMinigame", 0i64);
  }
}

// File Line: 109
// RVA: 0x4E9C10
void __fastcall UFG::TSPhonetrace::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenPhoneTraceMinigame::mbWon);
}

// File Line: 122
// RVA: 0x4EF070
void __fastcall UFG::TSPhonetrace::MthdC_set_solution(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  float v3; // xmm7_4
  float v4; // xmm6_4
  UFG::qString *v5; // rax
  UFG::qString *v6; // rbx
  UFG::qString v7; // [rsp+38h] [rbp-50h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  v3 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  v4 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
  UFG::qString::qString(&v7, *(const char **)(*i_array_p)->i_data_p->i_user_data);
  v6 = v5;
  UFG::qString::Set(&UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood, v5->mData, v5->mLength, 0i64, 0);
  UFG::UIHKScreenPhoneTraceMinigame::xSolution = v3;
  UFG::UIHKScreenPhoneTraceMinigame::ySolution = v4;
  UFG::qString::~qString(v6);
}

