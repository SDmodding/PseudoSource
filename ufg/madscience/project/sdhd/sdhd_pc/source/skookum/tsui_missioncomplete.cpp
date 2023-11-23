// File Line: 34
// RVA: 0x4D8070
void UFG::TSUI_MissionComplete::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("MissionComplete");
  SSClass::register_method_func(v0, "show", UFG::TSUI_MissionComplete::MthdC_show, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "add_reward", UFG::TSUI_MissionComplete::MthdC_add_reward, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "is_active", UFG::TSUI_MissionComplete::MthdC_is_active, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "manual_show", UFG::TSUI_MissionComplete::MthdC_manual_show, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "add_racers", UFG::TSUI_MissionComplete::MthdC_add_racers, 1, rebindd);
}

// File Line: 46
// RVA: 0x4EFE10
void __fastcall UFG::TSUI_MissionComplete::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // r9
  SSInstance *v4; // r8
  SSInstance *v5; // rcx
  int i_user_data; // [rsp+40h] [rbp+8h] BYREF
  int v7; // [rsp+50h] [rbp+18h] BYREF
  int *v8; // [rsp+58h] [rbp+20h]

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p;
  v5 = i_array_p[2]->i_data_p;
  v8 = &i_user_data;
  i_user_data = v5->i_user_data;
  v7 = v4->i_user_data;
  UFG::UIHKScreenMissionComplete::Activate(
    (__int64)&v7,
    (__int64)&i_user_data,
    *(const char **)i_data_p->i_user_data,
    0);
}

// File Line: 56
// RVA: 0x4E3250
void __fastcall UFG::TSUI_MissionComplete::MthdC_add_reward(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  SSInstance *v4; // rbx
  unsigned int v5; // eax
  UFG::qSymbol uiscreen_type; // [rsp+40h] [rbp+8h] BYREF
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol *p_uiscreen_type; // [rsp+58h] [rbp+20h]

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p;
  p_uiscreen_type = &uiscreen_type;
  v5 = UFG::qStringHash32("MISSION_COMPLETE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol(&result, v5);
  uiscreen_type.mUID = result.mUID;
  UFG::UIHKScreenMissionComplete::AddReward(
    *(const char **)v4->i_user_data,
    i_data_p->i_user_data,
    (__int64)&uiscreen_type);
}

// File Line: 66
// RVA: 0x4E92C0
void __fastcall UFG::TSUI_MissionComplete::MthdC_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenMissionComplete::mState != STATE_IDLE);
}

// File Line: 79
// RVA: 0x4EAD60
void __fastcall UFG::TSUI_MissionComplete::MthdC_manual_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax
  UFG::qSymbol rewardPropertySetName; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_rewardPropertySetName; // [rsp+50h] [rbp+18h]

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  p_rewardPropertySetName = &rewardPropertySetName;
  rewardPropertySetName.mUID = i_data_p->i_user_data;
  UFG::RewardsHandler::HandleRewards(ShowReward, &rewardPropertySetName, 0i64);
}

// File Line: 87
// RVA: 0x4E3100
void __fastcall UFG::TSUI_MissionComplete::MthdC_add_racers(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 i_user_data; // rcx
  unsigned int v3; // eax
  __int64 v4; // rdi
  __int64 v5; // rbp
  __int64 size; // rsi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int *p_mStringHash32; // rbx
  UFG::qArray<UFG::qString,0> racerNames; // [rsp+38h] [rbp-40h] BYREF
  UFG::qString v11; // [rsp+48h] [rbp-30h] BYREF

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(_DWORD *)i_user_data;
  v4 = *(_QWORD *)(i_user_data + 8);
  racerNames.p = 0i64;
  *(_QWORD *)&racerNames.size = 0i64;
  if ( v3 )
  {
    v5 = v3;
    do
    {
      UFG::qString::qString(&v11, **(const char ***)(*(_QWORD *)v4 + 32i64));
      size = racerNames.size;
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
      UFG::qString::Set(&racerNames.p[size], v11.mData, v11.mLength, 0i64, 0);
      UFG::qString::~qString(&v11);
      v4 += 8i64;
      --v5;
    }
    while ( v5 );
  }
  UFG::UIHKScreenMissionComplete::FillRacerInfo(&racerNames);
  if ( racerNames.p )
  {
    p_mStringHash32 = &racerNames.p[-1].mStringHash32;
    `eh vector destructor iterator(
      racerNames.p,
      0x28ui64,
      racerNames.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
}

