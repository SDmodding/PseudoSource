// File Line: 166
// RVA: 0x41EA20
void __fastcall UFG::EnableInputMapsBySubMode_OnFoot(UFG::Controller *controller, UFG::InputActionMap *normal)
{
  UFG::InputActionMap *v2; // rdi
  UFG::Controller *v3; // rbx
  UFG::Controller *v4; // rcx
  unsigned int v5; // ecx

  v2 = normal;
  v3 = controller;
  if ( controller->m_IsKeyboardController )
  {
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      if ( v3->m_SubModes & 1 )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_On_Foot_Limited_KeyboardAndMouseActionMap_AZERTY);
        return;
      }
      if ( (v3->m_SubModes >> 1) & 1 )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_AZERTY);
        return;
      }
      v4 = v3;
      if ( (v3->m_SubModes >> 2) & 1 )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_On_Foot_PDA_Signal_KeyboardAndMouseActionMap_AZERTY);
        return;
      }
      goto LABEL_9;
    }
    if ( v3->m_SubModes & 1 )
    {
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_On_Foot_Limited_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
    else if ( (v3->m_SubModes >> 1) & 1 )
    {
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
    else
    {
      v4 = v3;
      if ( !((v3->m_SubModes >> 2) & 1) )
      {
LABEL_9:
        UFG::Controller::EnableInputActionMap(v4, v2);
        return;
      }
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_On_Foot_PDA_Signal_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
  }
  else if ( controller->m_SubModes & 1 )
  {
    UFG::Controller::EnableInputActionMap(controller, &UFG::gHKGameplayLimitedOnFootActionMap);
  }
  else
  {
    v5 = controller->m_SubModes;
    if ( (v5 >> 1) & 1 )
    {
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHKGameplayOnFootPDAOpenActionMap);
    }
    else
    {
      if ( (v5 >> 2) & 1 )
        normal = &UFG::gHKGameplayOnFootPDASignalActionMap;
      UFG::Controller::EnableInputActionMap(v3, normal);
    }
  }
}

// File Line: 183
// RVA: 0x41ED20
void __fastcall UFG::EnableInputMaps_OnFoot(UFG::Controller *controller)
{
  UFG::Controller *v1; // rbx

  v1 = controller;
  UFG::Controller::EnableInputActionMap(controller, &UFG::Editor::mGlobalKeyboardMap);
  if ( v1->m_IsKeyboardController )
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Camera_MouseActionMap);
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_AZERTY);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_AZERTY);
      UFG::EnableInputMapsBySubMode_OnFoot(v1, &UFG::gHK_On_Foot_KeyboardAndMouseActionMap_AZERTY);
    }
    else
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_QWERTY_QWERTZ);
      UFG::EnableInputMapsBySubMode_OnFoot(v1, &UFG::gHK_On_Foot_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
    v1->m_ActiveMapSet = 1;
  }
  else
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIFaceButtonActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHKGameplayCommonActionMap);
    UFG::EnableInputMapsBySubMode_OnFoot(v1, &UFG::gHKGameplayOnFootActionMap);
    v1->m_ActiveMapSet = 1;
    v1->m_ActiveMapSet = 1;
  }
}

// File Line: 220
// RVA: 0x41EE30
void __fastcall UFG::EnableInputMaps_OnFootWithPDA(UFG::Controller *controller)
{
  UFG::Controller *v1; // rbx
  UFG::InputActionMap *v2; // rdx

  v1 = controller;
  UFG::Controller::EnableInputActionMap(controller, &UFG::Editor::mGlobalKeyboardMap);
  if ( v1->m_IsKeyboardController )
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Camera_MouseActionMap);
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_AZERTY);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_AZERTY);
      v2 = &UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_AZERTY;
    }
    else
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_QWERTY_QWERTZ);
      v2 = &UFG::gHK_On_Foot_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
    }
  }
  else
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIFaceButtonActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHKGameplayCommonActionMap);
    v2 = &UFG::gHKGameplayOnFootPDAOpenActionMap;
  }
  UFG::EnableInputMapsBySubMode_OnFoot(v1, v2);
  v1->m_ActiveMapSet = 7;
}

// File Line: 256
// RVA: 0x41E8C0
void __fastcall UFG::EnableInputMapsBySubMode_Driving(UFG::Controller *controller, UFG::InputActionMap *normal)
{
  UFG::InputActionMap *v2; // rdi
  UFG::Controller *v3; // rbx
  UFG::Controller *v4; // rcx
  unsigned int v5; // ecx

  v2 = normal;
  v3 = controller;
  if ( controller->m_IsKeyboardController )
  {
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      if ( v3->m_SubModes & 1 )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_Driving_Limited_KeyboardAndMouseActionMap_AZERTY);
        return;
      }
      if ( (v3->m_SubModes >> 1) & 1 )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_AZERTY);
        return;
      }
      v4 = v3;
      if ( (v3->m_SubModes >> 2) & 1 )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_AZERTY);
        return;
      }
      goto LABEL_9;
    }
    if ( v3->m_SubModes & 1 )
    {
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_Driving_Limited_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
    else if ( (v3->m_SubModes >> 1) & 1 )
    {
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
    else
    {
      v4 = v3;
      if ( !((v3->m_SubModes >> 2) & 1) )
      {
LABEL_9:
        UFG::Controller::EnableInputActionMap(v4, v2);
        return;
      }
      UFG::Controller::EnableInputActionMap(v3, &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ);
    }
  }
  else if ( controller->m_SubModes & 1 )
  {
    UFG::Controller::EnableInputActionMap(controller, &UFG::gHKGameplayLimitedDrivingActionMap);
  }
  else
  {
    v5 = controller->m_SubModes;
    if ( (v5 >> 1) & 1 || (v5 >> 2) & 1 )
      normal = &UFG::gHKGameplayDrivingDuringPhoneCallActionMap;
    UFG::Controller::EnableInputActionMap(v3, normal);
  }
}

// File Line: 273
// RVA: 0x41EBA0
void __fastcall UFG::EnableInputMaps_Driving(UFG::Controller *controller)
{
  UFG::Controller *v1; // rbx
  UFG::InputActionMap *v2; // rdx

  v1 = controller;
  UFG::Controller::EnableInputActionMap(controller, &UFG::Editor::mGlobalKeyboardMap);
  if ( v1->m_IsKeyboardController )
  {
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_AZERTY);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_AZERTY);
      v2 = &UFG::gHK_Driving_KeyboardAndMouseActionMap_AZERTY;
    }
    else
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_QWERTY_QWERTZ);
      v2 = &UFG::gHK_Driving_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
    }
  }
  else
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIFaceButtonActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHKGameplayCommonActionMap);
    v2 = &UFG::gHKGameplayDrivingActionMap;
  }
  UFG::EnableInputMapsBySubMode_Driving(v1, v2);
  v1->m_ActiveMapSet = 4;
}

// File Line: 308
// RVA: 0x41EC60
void __fastcall UFG::EnableInputMaps_DrivingWithPDA(UFG::Controller *controller)
{
  UFG::Controller *v1; // rbx
  UFG::InputActionMap *v2; // rdx

  v1 = controller;
  UFG::Controller::EnableInputActionMap(controller, &UFG::Editor::mGlobalKeyboardMap);
  if ( v1->m_IsKeyboardController )
  {
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_AZERTY);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_AZERTY);
      v2 = &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_AZERTY;
    }
    else
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_QWERTY_QWERTZ);
      v2 = &UFG::gHK_Driving_PDA_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
    }
  }
  else
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIFaceButtonActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHKGameplayCommonActionMap);
    v2 = &UFG::gHKGameplayDrivingWithPDAActionMap;
  }
  UFG::EnableInputMapsBySubMode_Driving(v1, v2);
  v1->m_ActiveMapSet = 5;
}

// File Line: 343
// RVA: 0x41EF00
void __fastcall UFG::EnableInputMaps_Sniper(UFG::Controller *controller)
{
  UFG::Controller *v1; // rbx
  UFG::InputActionMap *v2; // rdx

  v1 = controller;
  UFG::Controller::EnableInputActionMap(controller, &UFG::Editor::mGlobalKeyboardMap);
  if ( v1->m_IsKeyboardController )
  {
    if ( UFG::HK_DetermineKeyboardLayout() == 3 )
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_AZERTY);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_AZERTY);
      v2 = &UFG::gHK_Sniper_KeyboardAndMouseActionMap_AZERTY;
    }
    else
    {
      UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ);
      UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Gameplay_Common_KeyboardMouseActionMap_QWERTY_QWERTZ);
      v2 = &UFG::gHK_Sniper_KeyboardAndMouseActionMap_QWERTY_QWERTZ;
    }
  }
  else
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIFaceButtonActionMap);
    UFG::Controller::EnableInputActionMap(v1, &UFG::gHKGameplayCommonActionMap);
    v2 = &UFG::gHKGameplaySniperActionMap;
  }
  UFG::Controller::EnableInputActionMap(v1, v2);
  v1->m_ActiveMapSet = 6;
}

// File Line: 378
// RVA: 0x41EFC0
void __fastcall UFG::EnableInputMaps_UI_Only(UFG::Controller *controller)
{
  UFG::Controller *v1; // rbx
  UFG::HKKeyboardLayout v2; // eax
  UFG::Controller *v3; // rcx
  UFG::InputActionMap *v4; // rdx

  v1 = controller;
  UFG::Controller::EnableInputActionMap(controller, &UFG::Editor::mGlobalKeyboardMap);
  UFG::Controller::EnableInputActionMap(v1, &UFG::gHK_Camera_MouseActionMap);
  if ( v1->m_IsKeyboardController )
  {
    v2 = UFG::HK_DetermineKeyboardLayout();
    v3 = v1;
    if ( v2 == 3 )
      v4 = &UFG::gUIActionMap_Keyboard_AZERTY;
    else
      v4 = &UFG::gUIActionMap_Keyboard_QWERTY_QWERTZ;
  }
  else
  {
    UFG::Controller::EnableInputActionMap(v1, &UFG::gUIActionMap);
    v4 = &UFG::gUIFaceButtonActionMap;
    v3 = v1;
  }
  UFG::Controller::EnableInputActionMap(v3, v4);
  v1->m_ActiveMapSet = 8;
}

// File Line: 484
// RVA: 0x41F240
void __fastcall UFG::SetInputMode_PDA_Off(int controllerIndex)
{
  UFG::Controller *v1; // rbx
  unsigned int v2; // eax

  v1 = UFG::gInputSystem->mControllers[controllerIndex];
  if ( v1 )
  {
    v2 = v1->m_ActiveMapSet;
    if ( v2 == 7 )
    {
      UFG::Controller::DisableAllMaps(UFG::gInputSystem->mControllers[controllerIndex]);
      UFG::EnableInputMaps_OnFoot(v1);
    }
    else if ( v2 == 5 )
    {
      UFG::Controller::DisableAllMaps(UFG::gInputSystem->mControllers[controllerIndex]);
      UFG::EnableInputMaps_Driving(v1);
    }
  }
}

// File Line: 495
// RVA: 0x41F2A0
void __fastcall UFG::SetInputMode_PDA_On(int controllerIndex)
{
  UFG::Controller *v1; // rbx
  unsigned int v2; // eax

  v1 = UFG::gInputSystem->mControllers[controllerIndex];
  if ( v1 )
  {
    v2 = v1->m_ActiveMapSet;
    if ( v2 == 1 )
    {
      UFG::Controller::DisableAllMaps(UFG::gInputSystem->mControllers[controllerIndex]);
      UFG::EnableInputMaps_OnFootWithPDA(v1);
    }
    else if ( v2 == 4 )
    {
      UFG::Controller::DisableAllMaps(UFG::gInputSystem->mControllers[controllerIndex]);
      UFG::EnableInputMaps_DrivingWithPDA(v1);
    }
  }
}

// File Line: 506
// RVA: 0x41F040
void __fastcall UFG::SetInputMode(UFG::eHKControllerInputMode mode, int controllerIndex)
{
  __int32 v2; // ebx
  UFG::Controller *v3; // rdi
  UFG::InputActionMap *v4; // rdx

  v2 = mode - 1;
  v3 = UFG::gInputSystem->mControllers[controllerIndex];
  UFG::Controller::DisableAllMaps(UFG::gInputSystem->mControllers[controllerIndex]);
  switch ( v2 )
  {
    case 0:
      UFG::EnableInputMaps_OnFoot(v3);
      break;
    case 1:
      UFG::Controller::EnableInputActionMap(v3, &UFG::Editor::mGlobalKeyboardMap);
      if ( v3->m_IsKeyboardController )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHKCameraOnlyKeyboardActionMap);
      }
      else
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHKCameraOnlyActionMap);
        UFG::Controller::EnableInputActionMap(v3, &UFG::gUIActionMap);
      }
      v3->m_ActiveMapSet = 2;
      break;
    case 2:
      UFG::Controller::EnableInputActionMap(v3, &UFG::Editor::mGlobalKeyboardMap);
      if ( !v3->m_IsKeyboardController )
      {
        UFG::Controller::EnableInputActionMap(v3, &UFG::Editor::mJoystickActionMap);
        UFG::Controller::EnableInputActionMap(v3, &UFG::gHKGameplayCommonActionMap);
        UFG::EnableInputMapsBySubMode_OnFoot(v3, &UFG::gHKGameplayOnFootActionMap);
      }
      v3->m_ActiveMapSet = 3;
      break;
    case 3:
      UFG::EnableInputMaps_Driving(v3);
      break;
    case 4:
      UFG::EnableInputMaps_DrivingWithPDA(v3);
      break;
    case 5:
      UFG::EnableInputMaps_Sniper(v3);
      break;
    case 6:
      UFG::EnableInputMaps_OnFootWithPDA(v3);
      break;
    case 7:
      UFG::EnableInputMaps_UI_Only(v3);
      break;
    case 8:
      if ( UFG::gDebugCameraComponent && UFG::gDebugCameraComponent->mDebugCameraOn )
        UFG::Controller::EnableInputActionMap(v3, &UFG::gDebugCameraMap);
      UFG::Controller::EnableInputActionMap(v3, &UFG::Editor::mGlobalKeyboardMap);
      v4 = &UFG::gTweakerUIKeyboardMap;
      if ( !v3->m_IsKeyboardController )
        v4 = &UFG::gTweakerUIMap;
      UFG::Controller::EnableInputActionMap(v3, v4);
      v3->m_ActiveMapSet = 9;
      break;
    default:
      return;
  }
}

// File Line: 609
// RVA: 0x41E850
void __fastcall UFG::ActivateInputSubMode(UFG::eHKInputSubMode subMode, int controllerIndex)
{
  UFG::eHKInputSubMode v2; // er9
  UFG::Controller *v3; // rcx

  v2 = subMode;
  v3 = UFG::gInputSystem->mControllers[controllerIndex];
  v3->m_SubModes |= v2;
  UFG::SetInputMode((UFG::eHKControllerInputMode)v3->m_ActiveMapSet, controllerIndex);
}

// File Line: 618
// RVA: 0x41E880
void __fastcall UFG::DeactivateInputSubMode(UFG::eHKInputSubMode subMode, int controllerIndex)
{
  UFG::eHKInputSubMode v2; // er9
  UFG::Controller *v3; // rcx

  v2 = subMode;
  if ( (unsigned int)controllerIndex <= 4 )
  {
    v3 = UFG::gInputSystem->mControllers[controllerIndex];
    if ( v3 )
    {
      v3->m_SubModes &= ~v2;
      UFG::SetInputMode((UFG::eHKControllerInputMode)v3->m_ActiveMapSet, controllerIndex);
    }
  }
}

