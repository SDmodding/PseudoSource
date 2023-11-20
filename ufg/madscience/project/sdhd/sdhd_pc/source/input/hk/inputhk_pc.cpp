// File Line: 582
// RVA: 0xA3F630
signed __int64 __fastcall UFG::HK_DetermineKeyboardLayout()
{
  signed __int64 result; // rax
  unsigned __int16 v1; // ax
  bool v2; // zf

  result = (unsigned int)gHK_KeyboardLayout;
  if ( gHK_KeyboardLayout == HKKeyboardLayout_Invalid )
  {
    v1 = (unsigned __int64)GetKeyboardLayout(0);
    if ( (_BYTE)v1 == 12 )
    {
      v2 = (((v1 >> 10) - 1) & 0xFA) == 0;
      result = (unsigned int)gHK_KeyboardLayout;
      if ( v2 )
        result = 3i64;
      gHK_KeyboardLayout = (signed int)result;
    }
    else
    {
      result = (unsigned int)((_BYTE)v1 == 21) + 1;
      gHK_KeyboardLayout = (signed int)result;
    }
  }
  return result;
}

// File Line: 622
// RVA: 0xA3F690
void __fastcall UFG::HK_InitInput(UFG *this)
{
  int v1; // eax
  unsigned __int16 v2; // ax
  __int16 v3; // cx
  unsigned __int16 v4; // ax
  UFG::InputActionMap *v5; // rcx
  UFG::InputActionMap *v6; // rax

  v1 = gHK_KeyboardLayout;
  if ( gHK_KeyboardLayout == HKKeyboardLayout_Invalid )
  {
    v2 = (unsigned __int64)GetKeyboardLayout(0);
    if ( (_BYTE)v2 == 12 )
    {
      v3 = v2 >> 10;
      v1 = gHK_KeyboardLayout;
      if ( !(((_BYTE)v3 - 1) & 0xFA) )
        v1 = 3;
    }
    else
    {
      v1 = ((_BYTE)v2 == 21) + 1;
    }
    gHK_KeyboardLayout = v1;
  }
  UFG::gInitialGamepadMaps[0] = &UFG::gUIActionMap;
  qword_14235F878 = (__int64)&UFG::gUIFaceButtonActionMap;
  qword_14235F880 = (__int64)&UFG::gDebugCameraMap;
  qword_14235F888 = (__int64)&UFG::Editor::mJoystickActionMap;
  UFG::gInitialKeyboardMaps[0] = &UFG::Editor::mGlobalKeyboardMap;
  qword_14235F890 = (__int64)&UFG::gHKGameplayOnFootActionMap;
  qword_14235F898 = (__int64)&UFG::gHKDebugInputMap;
  qword_14235F8A0 = (__int64)&UFG::gHKGameplayCommonActionMap;
  qword_14235F8A8 = (__int64)&UFG::gHKCameraOnlyActionMap;
  qword_14235F8B0 = (__int64)&UFG::gHKGameplayDrivingActionMap;
  qword_14235F8B8 = (__int64)&UFG::gHKGameplayDrivingWithPDAActionMap;
  qword_14235F8C0 = (__int64)&UFG::gHKGameplayDrivingDuringPhoneCallActionMap;
  qword_14235F8C8 = (__int64)&UFG::gHK_TrafficDebugController;
  qword_14235F8D0 = (__int64)&UFG::gHKGameplaySniperActionMap;
  qword_14235F8D8 = (__int64)&UFG::gHKGameplayOnFootPDAOpenActionMap;
  qword_14235F8E0 = (__int64)&UFG::gHKGameplayOnFootPDASignalActionMap;
  qword_14235F8E8 = (__int64)&UFG::gHKGameplayLimitedOnFootActionMap;
  qword_14235F8F0 = (__int64)&UFG::gHKGameplayLimitedDrivingActionMap;
  qword_14235F8F8 = (__int64)&UFG::gTweakerUIMap;
  UFG::gInitialMultiMaps[0] = &UFG::gHK_MultiInputMap;
  qword_14235F978 = (__int64)&UFG::gHK_Camera_MouseActionMap;
  if ( !v1 )
  {
    v4 = (unsigned __int64)GetKeyboardLayout(0);
    if ( (_BYTE)v4 != 12 )
    {
      v1 = ((_BYTE)v4 == 21) + 1;
      gHK_KeyboardLayout = v1;
LABEL_10:
      qword_14235F980 = (__int64)&UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ;
      qword_14235F988 = (__int64)&UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_QWERTY_QWERTZ;
      qword_14235F990 = (__int64)&UFG::gHK_On_Foot_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      qword_14235F998 = (__int64)&UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      qword_14235F9A0 = (__int64)&UFG::gHK_On_Foot_PDA_Signal_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      qword_14235F9A8 = (__int64)&UFG::gHK_Driving_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      qword_14235F9B0 = (__int64)&UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      v5 = &UFG::gHK_Sniper_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      goto LABEL_11;
    }
    if ( !(((v4 >> 10) - 1) & 0xFA) )
    {
      v1 = 3;
      gHK_KeyboardLayout = 3;
      goto LABEL_17;
    }
    v1 = gHK_KeyboardLayout;
  }
  if ( v1 != 3 )
    goto LABEL_10;
LABEL_17:
  qword_14235F980 = (__int64)&UFG::gUIActionMap_Keyboard_AZERTY;
  qword_14235F988 = (__int64)&UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_AZERTY;
  qword_14235F990 = (__int64)&UFG::gHK_On_Foot_KeyboardAndMouseActionMap_AZERTY;
  qword_14235F998 = (__int64)&UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_AZERTY;
  qword_14235F9A0 = (__int64)&UFG::gHK_On_Foot_PDA_Signal_KeyboardAndMouseActionMap_AZERTY;
  qword_14235F9A8 = (__int64)&UFG::gHK_Driving_KeyboardAndMouseActionMap_AZERTY;
  qword_14235F9B0 = (__int64)&UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_AZERTY;
  v5 = &UFG::gHK_Sniper_KeyboardAndMouseActionMap_AZERTY;
LABEL_11:
  qword_14235F9B8 = (__int64)v5;
  qword_14235F9C0 = (__int64)&UFG::gHKCameraOnlyKeyboardActionMap;
  if ( v1 == 3 )
  {
    qword_14235F9C8 = (__int64)&UFG::gHK_On_Foot_Limited_KeyboardAndMouseActionMap_AZERTY;
    v6 = &UFG::gHK_Driving_Limited_KeyboardAndMouseActionMap_AZERTY;
  }
  else
  {
    qword_14235F9C8 = (__int64)&UFG::gHK_On_Foot_Limited_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
    v6 = &UFG::gHK_Driving_Limited_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
  }
  qword_14235F9D0 = (__int64)v6;
  qword_14235F900 = 0i64;
  qword_14235FA78 = 0i64;
  qword_14235F9E0 = 0i64;
  qword_14235F9D8 = (__int64)&UFG::gTweakerUIKeyboardMap;
}

// File Line: 713
// RVA: 0xA3F9B0
void __fastcall UFG::HK_PostInputInit(UFG *this)
{
  int v1; // esi
  __int64 v2; // rbp
  UFG::Controller *v3; // rbx
  int v4; // eax
  unsigned __int16 v5; // ax
  char v6; // cl
  __int16 v7; // cx
  unsigned __int8 v8; // al
  int v9; // edi
  UFG::InputActionMap *v10; // rdx
  UFG::InputActionMap *v11; // rdx

  v1 = 0;
  v2 = 0i64;
  do
  {
    v3 = UFG::gInputSystem->mControllers[v2];
    if ( v3 )
    {
      UFG::Controller::DisableInputActionMap(UFG::gInputSystem->mControllers[v2], &UFG::gDebugCameraMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::Editor::mJoystickActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKGameplayDrivingActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKGameplayDrivingWithPDAActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKGameplayDrivingDuringPhoneCallActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKCameraOnlyActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKGameplayLimitedOnFootActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKGameplayLimitedDrivingActionMap);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gTweakerUIMap);
      v4 = gHK_KeyboardLayout;
      if ( gHK_KeyboardLayout == HKKeyboardLayout_Invalid )
      {
        v5 = (unsigned __int64)GetKeyboardLayout(0);
        v6 = v5;
        if ( (_BYTE)v5 == 12 )
        {
          v7 = v5 >> 10;
          v8 = v5 >> 10;
          if ( (_BYTE)v7 && (v8 <= 2u || (unsigned __int8)(v8 - 5) <= 1u) )
          {
            v4 = 3;
            gHK_KeyboardLayout = 3;
          }
          else
          {
            v4 = gHK_KeyboardLayout;
          }
        }
        else
        {
          v4 = ((_BYTE)v5 == 21) + 1;
          gHK_KeyboardLayout = (v6 == 21) + 1;
        }
      }
      v9 = v4;
      if ( v4 == 3 )
      {
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_Driving_KeyboardAndMouseActionMap_AZERTY);
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_AZERTY);
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_AZERTY);
        v10 = &UFG::gHK_On_Foot_PDA_Signal_KeyboardAndMouseActionMap_AZERTY;
      }
      else
      {
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_Driving_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
        v10 = &UFG::gHK_On_Foot_PDA_Signal_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      }
      UFG::Controller::DisableInputActionMap(v3, v10);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gHKCameraOnlyKeyboardActionMap);
      if ( v9 == 3 )
      {
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_On_Foot_Limited_KeyboardAndMouseActionMap_AZERTY);
        v11 = &UFG::gHK_Driving_Limited_KeyboardAndMouseActionMap_AZERTY;
      }
      else
      {
        UFG::Controller::DisableInputActionMap(v3, &UFG::gHK_On_Foot_Limited_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
        v11 = &UFG::gHK_Driving_Limited_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
      }
      UFG::Controller::DisableInputActionMap(v3, v11);
      UFG::Controller::DisableInputActionMap(v3, &UFG::gTweakerUIKeyboardMap);
      UFG::SetInputMode(IM_ON_FOOT, v1);
      if ( v3->m_IsKeyboardController )
      {
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_Attack, REMAP_ID_ATTACK_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_MeleeAttack, REMAP_ID_MELEE_ATTACK_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_Fire,
          REMAP_ID_FIRE_3,
          &UFG::ActionDef_FireFull,
          &UFG::ActionDef_FireFullReleased);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_MoveFwdBack, REMAP_ID_MOVE_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_Steer,
          REMAP_ID_STEER_3,
          &UFG::ActionDef_NoSteer,
          0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_ForwardKey,
          REMAP_ID_FORWARD_KEY_3,
          &UFG::ActionDef_ForwardKeyReleased,
          0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_Grab, REMAP_ID_GRAPPLE_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_Weapon, REMAP_ID_RELOAD_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_EquipUP, REMAP_ID_PHONEUP_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_Accelerate,
          REMAP_ID_ACCEL_3,
          &UFG::ActionDef_AccelerateOff,
          &UFG::ActionDef_AccelerateOn);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_Freerun, REMAP_ID_FREERUN_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_Focus,
          REMAP_ID_AIM_3,
          &UFG::ActionDef_Raw_Focus,
          0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_Action, REMAP_ID_ACTION_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_VehicleActionHijack,
          REMAP_ID_ACTIONHIJACK_3,
          0i64,
          0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_CoverToggle, REMAP_ID_COVERTOGGLE_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_Brake,
          REMAP_ID_BRAKE_3,
          &UFG::ActionDef_BrakeReleased,
          0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_HandBrake, REMAP_ID_HAND_BRAKE_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_VehicleFire, REMAP_ID_VEHICLE_FIRE_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_VehicleFocus,
          REMAP_ID_VEHICLE_FOCUS_3,
          0i64,
          0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_VehicleRamReload,
          REMAP_ID_VEHICLE_RAMRELOAD_3,
          0i64,
          0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_HornStart,
          REMAP_ID_VEHICLE_HORN_3,
          &UFG::ActionDef_HornStop,
          0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_LookBack, REMAP_ID_LOOK_BACK_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(
          v3,
          &UFG::ActionDef_Raw_Focus_Lock,
          REMAP_ID_WEAPON_SPECIAL_3,
          0i64,
          0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_LeanBack, REMAP_ID_LEAN_BACK_3, 0i64, 0i64);
        UFG::Controller::AddActionToRemappableList(v3, &UFG::ActionDef_LeanForward, REMAP_ID_LEAN_FORWARD_3, 0i64, 0i64);
      }
    }
    ++v1;
    ++v2;
  }
  while ( v1 < 5 );
}

// File Line: 803
// RVA: 0xA3F430
void __fastcall UFG::CheckForPCControllerSwap(UFG *this)
{
  signed int v1; // er9
  int v2; // ebx
  UFG::Controller *v3; // rax
  signed int v4; // er8
  UFG::Controller **v5; // rcx
  signed __int64 v6; // rax
  UFG::Controller *v7; // rdi
  bool v8; // al
  UFG::eHKControllerInputMode v9; // ebp
  unsigned int v10; // er14
  UFG::TiDo *v11; // rax
  __int64 v12; // rdx
  UFG::Controller *v13; // rsi
  UFG::TiDo *v14; // rax
  unsigned int v15; // edx

  v1 = -1;
  v2 = UFG::gInputSystem->mKeyboardIndex;
  v3 = UFG::gInputSystem->mControllers[4];
  if ( v2 || !v3 || v3->m_IsKeyboardController )
  {
    v4 = 0;
    v5 = UFG::gInputSystem->mControllers;
    v6 = 0i64;
    while ( !*v5 || (*v5)->m_IsKeyboardController )
    {
      ++v6;
      ++v4;
      ++v5;
      if ( v6 >= 5 )
        goto LABEL_11;
    }
    v1 = v4;
  }
  else
  {
    v1 = 4;
  }
LABEL_11:
  v7 = UFG::gInputSystem->mControllers[0];
  v8 = v7 && v7->m_IsKeyboardController;
  if ( UFG::InputSystem::msPCKeyboardSwapMode )
  {
    if ( UFG::InputSystem::msPCKeyboardSwapMode == 1 )
    {
      if ( !v8 || v1 < 0 || v2 < 0 )
        return;
      v2 = v1;
    }
    else if ( UFG::InputSystem::msPCKeyboardSwapMode != 2 || v8 || v1 < 0 || v2 < 0 )
    {
      return;
    }
    goto LABEL_31;
  }
  if ( v7->m_ControllerInUse == (_BYTE)UFG::InputSystem::msPCKeyboardSwapMode )
  {
    if ( v8 )
      v2 = v1;
    if ( v2 >= 0 && UFG::gInputSystem->mControllers[v2]->m_ControllerInUse )
    {
LABEL_31:
      v9 = v7->m_ActiveMapSet;
      v10 = v7->m_SubModes;
      v7->m_SubModes = 0;
      v11 = UFG::TiDo::GetInstance();
      UFG::TiDo::UnregisterControllerForEvents(v11, 0);
      v12 = v2;
      UFG::gInputSystem->mControllers[0] = UFG::gInputSystem->mControllers[v12];
      UFG::gInputSystem->mControllers[v12] = v7;
      v13 = UFG::gInputSystem->mControllers[0];
      UFG::Controller::DeleteMapDataStructures(UFG::gInputSystem->mControllers[0]);
      UFG::Controller::DeleteMapDataStructures(v7);
      v13->mControllerIndex = 0;
      v7->mControllerIndex = v2;
      UFG::Controller::CreateMapDataStructures(v13);
      UFG::Controller::CreateMapDataStructures(v7);
      UFG::Controller::ApplyRemapList(v13);
      UFG::Controller::ApplyRemapList(v7);
      if ( !v13->m_IsKeyboardController )
      {
        v14 = UFG::TiDo::GetInstance();
        UFG::TiDo::RegisterControllerForEvents(v14, 0);
      }
      UFG::SetInputMode(v9, 0);
      v15 = UI_HASH_INPUT_SWAPPED_38;
      v13->m_SubModes = v10;
      UFG::UIScreenManagerBase::queueMessage(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v15,
        0xFFFFFFFF);
      return;
    }
  }
}

