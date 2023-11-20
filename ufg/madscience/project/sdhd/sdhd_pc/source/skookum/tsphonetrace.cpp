// File Line: 51
// RVA: 0x4D4F50
void UFG::TSPhonetrace::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Phonetrace");
  SSClass::register_method_func(v0, "is_successful", UFG::TSPhonetrace::MthdC_is_successful, 1, 0);
  SSClass::register_method_func(v0, "set_solution", UFG::TSPhonetrace::MthdC_set_solution, 1, 0);
  SSClass::register_method_func(v0, "launch_signal_minigame", UFG::TSPhonetrace::MthdC_launch_signal_minigame, 1, 0);
  SSClass::register_method_func(v0, "fail_minigame", UFG::TSPhonetrace::MthdC_fail_minigame, 1, 0);
}

// File Line: 73
// RVA: 0x4E6200
void __fastcall UFG::TSPhonetrace::MthdC_fail_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPhoneTraceMinigame *v2; // rax

  v2 = (UFG::UIHKScreenPhoneTraceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                              "PhoneTraceMinigame");
  if ( v2 )
    UFG::UIHKScreenPhoneTraceMinigame::fail(v2);
}

// File Line: 91
// RVA: 0x4EA6C0
void __fastcall UFG::TSPhonetrace::MthdC_launch_signal_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 v2; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  UFG::UIScreenTextureManager *v6; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(UFG::TransformNodeComponent **)(v2 + 104);
  if ( !v3 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(v2 + 192), &UFG::qMatrix44::msIdentity) )
    v3 = (UFG::TransformNodeComponent *)v2;
  if ( v3 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v4 = v3->mWorldTransform.v3.y;
    v5 = v3->mWorldTransform.v3.z;
    UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.x = v3->mWorldTransform.v3.x;
    UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.y = v4;
    UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z = v5;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "PhoneSignalMinigame", 0i64);
  }
}

// File Line: 109
// RVA: 0x4E9C10
void __fastcall UFG::TSPhonetrace::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenPhoneTraceMinigame::mbWon);
}

// File Line: 122
// RVA: 0x4EF070
void __fastcall UFG::TSPhonetrace::MthdC_set_solution(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  float v3; // xmm7_4
  float v4; // xmm6_4
  UFG::qString *v5; // rax
  UFG::qString *v6; // rbx
  UFG::qString v7; // [rsp+38h] [rbp-50h]

  v2 = pScope->i_data.i_array_p;
  v3 = *(float *)&v2[1]->i_data_p->i_user_data;
  v4 = *(float *)&v2[2]->i_data_p->i_user_data;
  UFG::qString::qString(&v7, *(const char **)(*v2)->i_data_p->i_user_data);
  v6 = v5;
  UFG::qString::Set(&UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood, v5->mData, v5->mLength, 0i64, 0);
  UFG::UIHKScreenPhoneTraceMinigame::xSolution = v3;
  UFG::UIHKScreenPhoneTraceMinigame::ySolution = v4;
  UFG::qString::~qString(v6);
}

