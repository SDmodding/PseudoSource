// File Line: 45
// RVA: 0x4D5270
void UFG::TSPokerDice::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("PokerDice");
  SSClass::register_method_func(v0, "set_stake_limit", UFG::TSPokerDice::MthdC_set_stake_limit, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "refresh_player_hand", UFG::TSPokerDice::MthdC_refresh_player_hand, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "refresh_player_held", UFG::TSPokerDice::MthdC_refresh_player_held, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "refresh_house_hand", UFG::TSPokerDice::MthdC_refresh_house_hand, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "refresh_house_held", UFG::TSPokerDice::MthdC_refresh_house_held, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "lock_selected_tile_to_C",
    UFG::TSPokerDice::MthdC_lock_selected_tile_to_C,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "send_tile_coords", UFG::TSPokerDice::MthdC_send_tile_coords, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "get_num_wins", UFG::TSPokerDice::MthdC_get_num_wins, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "get_num_losses", UFG::TSPokerDice::MthdC_get_num_losses, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "set_for_mission", UFG::TSPokerDice::MthdC_set_for_mission, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "enable_controls", UFG::TSPokerDice::MthdC_enable_controls, 1, rebindj);
}

// File Line: 70
// RVA: 0x4E4DE0
void __fastcall UFG::TSPokerDice::MthdC_enable_controls(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rax

  Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                 UFG::UIScreenManager::s_instance,
                                                 "PokerDiceMinigame");
  if ( Screen )
    UFG::UIHKScreenPokerDiceMinigame::enableProgression(
      Screen,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0,
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
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
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rbx
  SSData **i_array_p; // r8
  int i_user_data; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  int v8; // edi
  UFG::allocator::free_link *v9; // rax

  Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                 UFG::UIScreenManager::s_instance,
                                                 "PokerDiceMinigame");
  if ( Screen )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    v6 = i_array_p[1]->i_data_p->i_user_data;
    v7 = i_array_p[2]->i_data_p->i_user_data;
    v8 = i_array_p[3]->i_data_p->i_user_data;
    v9 = UFG::qMalloc(0xCui64, UFG::gGlobalNewName, 0i64);
    if ( v9 )
    {
      LODWORD(v9->mNext) = i_user_data;
      HIDWORD(v9->mNext) = v6;
      LODWORD(v9[1].mNext) = v7;
    }
    UFG::UIHKScreenPokerDiceMinigame::setAcceptButtonCoords(Screen, (UFG::qVector3 *)v9, v8);
  }
}

// File Line: 111
// RVA: 0x4E8580
void __fastcall UFG::TSPokerDice::MthdC_get_num_wins(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( ppResult )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PokerDiceMinigame");
    if ( Screen )
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(Screen[1].mNext));
  }
}

// File Line: 130
// RVA: 0x4E8530
void __fastcall UFG::TSPokerDice::MthdC_get_num_losses(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( ppResult )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PokerDiceMinigame");
    if ( Screen )
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, HIDWORD(Screen[1].mNext));
  }
}

// File Line: 149
// RVA: 0x4EACF0
void __fastcall UFG::TSPokerDice::MthdC_lock_selected_tile_to_C(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rax

  Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                 UFG::UIScreenManager::s_instance,
                                                 "PokerDiceMinigame");
  if ( Screen )
    UFG::UIHKScreenPokerDiceMinigame::lockSelectedTile(Screen, (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
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
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rax
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
    Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                   UFG::UIScreenManager::s_instance,
                                                   "PokerDiceMinigame");
    v4 = (unsigned int *)Screen;
    if ( Screen )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(Screen);
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
      *ppResult = SSList::as_instance(v6);
    }
  }
}

// File Line: 204
// RVA: 0x4EBC20
void __fastcall UFG::TSPokerDice::MthdC_refresh_house_hand(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rax
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
    Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                   UFG::UIScreenManager::s_instance,
                                                   "PokerDiceMinigame");
    v4 = (unsigned int *)Screen;
    if ( Screen )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(Screen);
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
      *ppResult = SSList::as_instance(v6);
    }
  }
}

// File Line: 229
// RVA: 0x4EBFF0
void __fastcall UFG::TSPokerDice::MthdC_refresh_player_held(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rax
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
    Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                   UFG::UIScreenManager::s_instance,
                                                   "PokerDiceMinigame");
    v4 = (bool *)Screen;
    if ( Screen )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(Screen);
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
      SSList::append(v6, v7, 1);
      v8 = SSBoolean::pool_new(v4[221]);
      SSList::append(v6, v8, 1);
      v9 = SSBoolean::pool_new(v4[222]);
      SSList::append(v6, v9, 1);
      v10 = SSBoolean::pool_new(v4[223]);
      SSList::append(v6, v10, 1);
      v11 = SSBoolean::pool_new(v4[224]);
      SSList::append(v6, v11, 1);
      *ppResult = SSList::as_instance(v6);
    }
  }
}

// File Line: 253
// RVA: 0x4EBD70
void __fastcall UFG::TSPokerDice::MthdC_refresh_house_held(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPokerDiceMinigame *Screen; // rax
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
    Screen = (UFG::UIHKScreenPokerDiceMinigame *)UFG::UIScreenManagerBase::getScreen(
                                                   UFG::UIScreenManager::s_instance,
                                                   "PokerDiceMinigame");
    v4 = (bool *)Screen;
    if ( Screen )
    {
      UFG::UIHKScreenPokerDiceMinigame::refreshGameData(Screen);
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
      SSList::append(v6, v7, 1);
      v8 = SSBoolean::pool_new(v4[226]);
      SSList::append(v6, v8, 1);
      v9 = SSBoolean::pool_new(v4[227]);
      SSList::append(v6, v9, 1);
      v10 = SSBoolean::pool_new(v4[228]);
      SSList::append(v6, v10, 1);
      v11 = SSBoolean::pool_new(v4[229]);
      SSList::append(v6, v11, 1);
      *ppResult = SSList::as_instance(v6);
    }
  }
}

