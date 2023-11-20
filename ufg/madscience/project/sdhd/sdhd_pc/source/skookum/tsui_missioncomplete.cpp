// File Line: 34
// RVA: 0x4D8070
void UFG::TSUI_MissionComplete::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("MissionComplete");
  SSClass::register_method_func(v0, "show", UFG::TSUI_MissionComplete::MthdC_show, 1, 0);
  SSClass::register_method_func(v0, "add_reward", UFG::TSUI_MissionComplete::MthdC_add_reward, 1, 0);
  SSClass::register_method_func(v0, "is_active", UFG::TSUI_MissionComplete::MthdC_is_active, 1, 0);
  SSClass::register_method_func(v0, "manual_show", UFG::TSUI_MissionComplete::MthdC_manual_show, 1, 0);
  SSClass::register_method_func(v0, "add_racers", UFG::TSUI_MissionComplete::MthdC_add_racers, 1, 0);
}

// File Line: 46
// RVA: 0x4EFE10
void __fastcall UFG::TSUI_MissionComplete::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // r9
  SSInstance *v4; // r8
  SSInstance *v5; // rcx
  int v6; // [rsp+40h] [rbp+8h]
  int v7; // [rsp+50h] [rbp+18h]
  int *v8; // [rsp+58h] [rbp+20h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p;
  v5 = v2[2]->i_data_p;
  v8 = &v6;
  v6 = v5->i_user_data;
  v7 = v4->i_user_data;
  UFG::UIHKScreenMissionComplete::Activate((__int64)&v7, (__int64)&v6, *(const char **)v3->i_user_data, 0);
}

// File Line: 56
// RVA: 0x4E3250
void __fastcall UFG::TSUI_MissionComplete::MthdC_add_reward(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rdi
  SSInstance *v4; // rbx
  unsigned int v5; // eax
  UFG::qSymbol uiscreen_type; // [rsp+40h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]
  UFG::qSymbol *v8; // [rsp+58h] [rbp+20h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p;
  v8 = &uiscreen_type;
  v5 = UFG::qStringHash32("MISSION_COMPLETE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&result, v5);
  uiscreen_type.mUID = result.mUID;
  UFG::UIHKScreenMissionComplete::AddReward(*(const char **)v4->i_user_data, v3->i_user_data, (__int64)&uiscreen_type);
}

// File Line: 66
// RVA: 0x4E92C0
void __fastcall UFG::TSUI_MissionComplete::MthdC_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenMissionComplete::mState != 0);
}

// File Line: 79
// RVA: 0x4EAD60
void __fastcall UFG::TSUI_MissionComplete::MthdC_manual_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rax
  UFG::qSymbol rewardPropertySetName; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v4; // [rsp+50h] [rbp+18h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = &rewardPropertySetName;
  rewardPropertySetName.mUID = v2->i_user_data;
  UFG::RewardsHandler::HandleRewards(0, (__int64)&rewardPropertySetName, 0i64);
}

// File Line: 87
// RVA: 0x4E3100
void __fastcall UFG::TSUI_MissionComplete::MthdC_add_racers(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 v2; // rcx
  unsigned int v3; // eax
  __int64 v4; // rdi
  __int64 v5; // rbp
  __int64 v6; // rsi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int *v9; // rbx
  UFG::qArray<UFG::qString,0> racerNames; // [rsp+38h] [rbp-40h]
  UFG::qString v11; // [rsp+48h] [rbp-30h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(_DWORD *)v2;
  v4 = *(_QWORD *)(v2 + 8);
  racerNames.p = 0i64;
  *(_QWORD *)&racerNames.size = 0i64;
  if ( v3 )
  {
    v5 = v3;
    do
    {
      UFG::qString::qString(&v11, **(const char ***)(*(_QWORD *)v4 + 32i64));
      v6 = racerNames.size;
      v7 = racerNames.size + 1;
      if ( racerNames.size + 1 > racerNames.capacity )
      {
        if ( racerNames.capacity )
          v8 = 2 * racerNames.capacity;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 - v7 > 0x10000 )
          v8 = racerNames.size + 65537;
        UFG::qArray<UFG::qString,0>::Reallocate(&racerNames, v8, "qArray.Add");
      }
      racerNames.size = v7;
      UFG::qString::Set(&racerNames.p[v6], v11.mData, v11.mLength, 0i64, 0);
      UFG::qString::~qString(&v11);
      v4 += 8i64;
      --v5;
    }
    while ( v5 );
  }
  UFG::UIHKScreenMissionComplete::FillRacerInfo(&racerNames);
  if ( racerNames.p )
  {
    v9 = &racerNames.p[-1].mStringHash32;
    `eh vector destructor iterator(
      racerNames.p,
      0x28ui64,
      racerNames.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v9);
  }
}

