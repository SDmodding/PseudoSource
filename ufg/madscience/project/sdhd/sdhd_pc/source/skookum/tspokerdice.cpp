// File Line: 45
// RVA: 0x4D5270
void UFG::TSPokerDice::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("PokerDice");
  SSClass::register_method_func(v0, "set_stake_limit", UFG::TSPokerDice::MthdC_set_stake_limit, 1, 0);
  SSClass::register_method_func(v0, "refresh_player_hand", UFG::TSPokerDice::MthdC_refresh_player_hand, 1, 0);
  SSClass::register_method_func(v0, "refresh_player_held", UFG::TSPokerDice::MthdC_refresh_player_held, 1, 0);
  SSClass::register_method_func(v0, "refresh_house_hand", UFG::TSPokerDice::MthdC_refresh_house_hand, 1, 0);
  SSClass::register_method_func(v0, "refresh_house_held", UFG::TSPokerDice::MthdC_refresh_house_held, 1, 0);
  SSClass::register_method_func(v0, "lock_selected_tile_to_C", UFG::TSPokerDice::MthdC_lock_selected_tile_to_C, 1, 0);
  SSClass::register_method_func(v0, "send_tile_coords", UFG::TSPokerDice::MthdC_send_tile_coords, 1, 0);
  SSClass::register_method_func(v0, "get_num_wins", UFG::TSPokerDice::MthdC_get_num_wins, 1, 0);
  SSClass::register_method_func(v0, "get_num_losses", UFG::TSPokerDice::MthdC_get_num_losses, 1, 0);
  SSClass::register_method_func(v0, "set_for_mission", UFG::TSPokerDice::MthdC_set_for_mission, 1, 0);
  SSClass::register_method_func(v0, "enable_controls", UFG::TSPokerDice::MthdC_enable_controls, 1, 0);
}

// File Line: 70
// RVA: 0x4E4DE0
void __fastcall UFG::TSPokerDice::MthdC_enable_controls(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::UIHKScreenPokerDiceMinigame *v3; // rax

  v2 = pScope;
  v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                             "PokerDiceMinigame");
  if ( v3 )
    UFG::UIHKScreenPokerDiceMinigame::enableProgression(
      v3,
      (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0,
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 81
// RVA: 0x4EDE30
void __fastcall UFG::TSPokerDice::MthdC_set_for_mission(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame::mbMissionMode = 1;
}

// File Line: 88
// RVA: 0x4ECF60
void __fastcall UFG::TSPokerDice::MthdC_send_tile_coords(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::UIHKScreenPokerDiceMinigame *v3; // rbx
  SSData **v4; // r8
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  int v8; // edi
  UFG::allocator::free_link *v9; // rax

  v2 = pScope;
  v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                             "PokerDiceMinigame");
  if ( v3 )
  {
    v4 = v2->i_data.i_array_p;
    v5 = (*v4)->i_data_p->i_user_data;
    v6 = v4[1]->i_data_p->i_user_data;
    v7 = v4[2]->i_data_p->i_user_data;
    v8 = v4[3]->i_data_p->i_user_data;
    v9 = UFG::qMalloc(0xCui64, UFG::gGlobalNewName, 0i64);
    if ( v9 )
    {
      LODWORD(v9->mNext) = v5;
      HIDWORD(v9->mNext) = v6;
      LODWORD(v9[1].mNext) = v7;
    }
    UFG::UIHKScreenPokerDiceMinigame::setAcceptButtonCoords(v3, (UFG::qVector3 *)v9, v8);
  }
}

// File Line: 111
// RVA: 0x4E8580
void __fastcall UFG::TSPokerDice::MthdC_get_num_wins(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "PokerDiceMinigame");
    if ( v3 )
      *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(v3[1].mNext));
  }
}

// File Line: 130
// RVA: 0x4E8530
void __fastcall UFG::TSPokerDice::MthdC_get_num_losses(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "PokerDiceMinigame");
    if ( v3 )
      *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, HIDWORD(v3[1].mNext));
  }
}

// File Line: 149
// RVA: 0x4EACF0
void __fastcall UFG::TSPokerDice::MthdC_lock_selected_tile_to_C(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::UIHKScreenPokerDiceMinigame *v3; // rax

  v2 = pScope;
  v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                             "PokerDiceMinigame");
  if ( v3 )
    UFG::UIHKScreenPokerDiceMinigame::lockSelectedTile(v3, (*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 167
// RVA: 0x4EF1C0
void __fastcall UFG::TSPokerDice::MthdC_set_stake_limit(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame::miLimit = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 179
// RVA: 0x4EBEA0
void __fastcall UFG::TSPokerDice::MthdC_refresh_player_hand(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::UIHKScreenPokerDiceMinigame *v3; // rax
  unsigned int *v4; // rdi
  SSList *v5; // rax
  SSList *v6; // rbx
  SSInstance *v7; // rax
  SSInstance *v8; // rax
  SSInstance *v9; // rax
  SSInstance *v10; // rax
  SSInstance *v11; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                               "PokerDiceMinigame");
    v4 = (unsigned int *)v3;
    if ( v3 )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(v3);
      v5 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList(5)");
      v6 = v5;
      if ( v5 )
      {
        v5->i_items.i_count = 0;
        v5->i_items.i_array_p = 0i64;
        v5->i_items.i_size = 5;
        v5->i_items.i_array_p = APArrayBase<SSInstance>::alloc_array(5u);
      }
      else
      {
        v6 = 0i64;
      }
      v7 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[44]);
      SSList::append(v6, v7, 1);
      v8 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[45]);
      SSList::append(v6, v8, 1);
      v9 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[46]);
      SSList::append(v6, v9, 1);
      v10 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[47]);
      SSList::append(v6, v10, 1);
      v11 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[48]);
      SSList::append(v6, v11, 1);
      *v2 = SSList::as_instance(v6);
    }
  }
}

// File Line: 204
// RVA: 0x4EBC20
void __fastcall UFG::TSPokerDice::MthdC_refresh_house_hand(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::UIHKScreenPokerDiceMinigame *v3; // rax
  unsigned int *v4; // rdi
  SSList *v5; // rax
  SSList *v6; // rbx
  SSInstance *v7; // rax
  SSInstance *v8; // rax
  SSInstance *v9; // rax
  SSInstance *v10; // rax
  SSInstance *v11; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                               "PokerDiceMinigame");
    v4 = (unsigned int *)v3;
    if ( v3 )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(v3);
      v5 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList(5)");
      v6 = v5;
      if ( v5 )
      {
        v5->i_items.i_count = 0;
        v5->i_items.i_array_p = 0i64;
        v5->i_items.i_size = 5;
        v5->i_items.i_array_p = APArrayBase<SSInstance>::alloc_array(5u);
      }
      else
      {
        v6 = 0i64;
      }
      v7 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[49]);
      SSList::append(v6, v7, 1);
      v8 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[50]);
      SSList::append(v6, v8, 1);
      v9 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[51]);
      SSList::append(v6, v9, 1);
      v10 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[52]);
      SSList::append(v6, v10, 1);
      v11 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4[53]);
      SSList::append(v6, v11, 1);
      *v2 = SSList::as_instance(v6);
    }
  }
}

// File Line: 229
// RVA: 0x4EBFF0
void __fastcall UFG::TSPokerDice::MthdC_refresh_player_held(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::UIHKScreenPokerDiceMinigame *v3; // rax
  bool *v4; // rdi
  SSList *v5; // rax
  SSList *v6; // rbx
  SSBoolean *v7; // rax
  SSBoolean *v8; // rax
  SSBoolean *v9; // rax
  SSBoolean *v10; // rax
  SSBoolean *v11; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                               "PokerDiceMinigame");
    v4 = (bool *)v3;
    if ( v3 )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(v3);
      v5 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList(5)");
      v6 = v5;
      if ( v5 )
      {
        v5->i_items.i_count = 0;
        v5->i_items.i_array_p = 0i64;
        v5->i_items.i_size = 5;
        v5->i_items.i_array_p = APArrayBase<SSInstance>::alloc_array(5u);
      }
      else
      {
        v6 = 0i64;
      }
      v7 = SSBoolean::pool_new(v4[220]);
      SSList::append(v6, (SSInstance *)&v7->vfptr, 1);
      v8 = SSBoolean::pool_new(v4[221]);
      SSList::append(v6, (SSInstance *)&v8->vfptr, 1);
      v9 = SSBoolean::pool_new(v4[222]);
      SSList::append(v6, (SSInstance *)&v9->vfptr, 1);
      v10 = SSBoolean::pool_new(v4[223]);
      SSList::append(v6, (SSInstance *)&v10->vfptr, 1);
      v11 = SSBoolean::pool_new(v4[224]);
      SSList::append(v6, (SSInstance *)&v11->vfptr, 1);
      *v2 = SSList::as_instance(v6);
    }
  }
}

// File Line: 253
// RVA: 0x4EBD70
void __fastcall UFG::TSPokerDice::MthdC_refresh_house_held(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::UIHKScreenPokerDiceMinigame *v3; // rax
  bool *v4; // rdi
  SSList *v5; // rax
  SSList *v6; // rbx
  SSBoolean *v7; // rax
  SSBoolean *v8; // rax
  SSBoolean *v9; // rax
  SSBoolean *v10; // rax
  SSBoolean *v11; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                               "PokerDiceMinigame");
    v4 = (bool *)v3;
    if ( v3 )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(v3);
      v5 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList(5)");
      v6 = v5;
      if ( v5 )
      {
        v5->i_items.i_count = 0;
        v5->i_items.i_array_p = 0i64;
        v5->i_items.i_size = 5;
        v5->i_items.i_array_p = APArrayBase<SSInstance>::alloc_array(5u);
      }
      else
      {
        v6 = 0i64;
      }
      v7 = SSBoolean::pool_new(v4[225]);
      SSList::append(v6, (SSInstance *)&v7->vfptr, 1);
      v8 = SSBoolean::pool_new(v4[226]);
      SSList::append(v6, (SSInstance *)&v8->vfptr, 1);
      v9 = SSBoolean::pool_new(v4[227]);
      SSList::append(v6, (SSInstance *)&v9->vfptr, 1);
      v10 = SSBoolean::pool_new(v4[228]);
      SSList::append(v6, (SSInstance *)&v10->vfptr, 1);
      v11 = SSBoolean::pool_new(v4[229]);
      SSList::append(v6, (SSInstance *)&v11->vfptr, 1);
      *v2 = SSList::as_instance(v6);
    }
  }
}

