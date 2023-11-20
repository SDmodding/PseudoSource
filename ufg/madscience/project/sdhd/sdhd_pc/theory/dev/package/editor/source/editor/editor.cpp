// File Line: 51
// RVA: 0x146DAE0
__int64 UFG::Editor::_dynamic_initializer_for__gSelectedColour__()
{
  UFG::Editor::gSelectedColour = UFG::qColour::Yellow;
  return LODWORD(UFG::qColour::Yellow.a);
}

// File Line: 68
// RVA: 0x146E6F0
__int64 UFG::Editor::_dynamic_initializer_for__mNotificationMessage__()
{
  UFG::qString::qString(&UFG::Editor::mNotificationMessage);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__mNotificationMessage__);
}

// File Line: 70
// RVA: 0x146DA20
__int64 UFG::Editor::_dynamic_initializer_for__gOptions__()
{
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gOptions__);
}

// File Line: 80
// RVA: 0x146E7D0
__int64 UFG::Editor::_dynamic_initializer_for__mViews__()
{
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__mViews__);
}

// File Line: 83
// RVA: 0x146E6A0
__int64 UFG::Editor::_dynamic_initializer_for__mHoverObjectList__()
{
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__mHoverObjectList__);
}

// File Line: 86
// RVA: 0x146E730
__int64 UFG::Editor::_dynamic_initializer_for__mPhysicsCollisionModelName__()
{
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__mPhysicsCollisionModelName__);
}

// File Line: 274
// RVA: 0x207310
void __fastcall UFG::Editor::Deactivate(UFG::Editor *this)
{
  UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *i; // rdi
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> *v2; // rbx
  UFG::Editor::VisibilityManager *v3; // rcx
  UFG::Editor::SelectionManager *v4; // rcx
  const char *v5; // rdx
  UFG::qNode<UFG::DUISurface,UFG::DUISurface> **v6; // rax
  UFG::DUIContext *v7; // rax
  UFG::BaseCameraComponent *v8; // rcx
  UFG::qBaseTreeRB *j; // rax
  UFG::SimObject *v10; // rbx

  if ( UFG::Editor::mActive )
  {
    UFG::qEnablePrintHandlers(UFG::Editor::mSavedPrintHandlersEnabled);
    for ( i = (UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *)&UFG::Editor::mViews.mNode.mNext[-1].mNext;
          i != (UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *)((char *)&UFG::Editor::mViews - 8);
          i = (UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *)&i[1].mNode.mPrev[-1].mNext )
    {
      v2 = i[5].mNode.mPrev;
      UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)&v2->mNext);
      *(float *)&v2[7].mPrev = (float)((float)SLODWORD(v2->mPrev[4].mPrev[9].mPrev) * 3.1415927) * 0.0055555557;
    }
    Render::SetRenderFeatures(&UFG::Editor::mSavedGameRenderFeatures);
    UFG::Editor::VisibilityManager::Deactivate(v3);
    UFG::Editor::SelectionManager::InvalidatePaths(v4);
    v5 = UFG::Editor::mWindowGroup_Game;
    if ( UFG::Editor::mWindowMode == WindowMode_Editor )
      v5 = UFG::Editor::mWindowGroup_Editor;
    UFG::DUIManager::DisableGroup((UFG::DUIManager *)&UFG::gDUIWindowManager->vfptr, v5);
    if ( UFG::Editor::mWindowMode == WindowMode_Editor )
    {
      UFG::Editor::Utility::SetMainWindowClientRect(&UFG::Editor::mGameWindowRect);
      v6 = UFG::DUIManager::GetSurface((UFG::DUIManager *)&UFG::gDUIWindowManager->vfptr, "DUI.GameOverlay");
      v7 = (UFG::DUIContext *)((__int64 (__fastcall *)(UFG::qNode<UFG::DUISurface,UFG::DUISurface> **))(*v6)[1].mPrev)(v6);
      UFG::DUIContext::SetOverallRect(v7, &UFG::Editor::mGameWindowRect);
    }
    UFG::Metrics::msInstance.mSimPausedDebug = 0;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
    UFG::Editor::SetCursorMode(0);
    v8 = UFG::Director::Get()->mCurrentCamera;
    if ( v8 )
      v8 = (UFG::BaseCameraComponent *)((char *)v8 + 80);
    LOBYTE(v8->mCamera.mTransformation.v3.x) = 0;
    UFG::PropertySetManager::SetModificationCallback(0i64);
    UFG::qString::Set(&UFG::Editor::mNotificationMessage, "Editor Deactivated");
    UFG::Editor::mUpdateStyle = 1;
    UFG::Editor::mNotificationAge = FLOAT_1_5;
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::gSim);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::gSim.mSimObjects.mTree, &v10->mNode) )
    {
      v10 = (UFG::SimObject *)(j ? &j[-1].mNULL : 0i64);
      if ( !v10 )
        break;
      UFG::UnWireframeSimObject(v10);
    }
    UFG::Editor::mActive = 0;
  }
}

// File Line: 316
// RVA: 0x20DD60
_BOOL8 __fastcall UFG::Editor::IsActive()
{
  return UFG::Editor::mActive;
}

// File Line: 361
// RVA: 0x20B3B0
UFG::qNode<UFG::Editor::View,UFG::Editor::View> **__fastcall UFG::Editor::GetActiveView()
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **result; // rax

  if ( !UFG::Editor::mInitialized )
    return 0i64;
  result = &UFG::Editor::mViews.mNode.mNext[-1].mNext;
  if ( &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
    return 0i64;
  while ( !*((_BYTE *)result + 88) )
  {
    result = &result[2][-1].mNext;
    if ( result == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
      return 0i64;
  }
  return result;
}

// File Line: 498
// RVA: 0x2137A0
void __fastcall UFG::Editor::ShowContextMenu(UFG::DUIContext *dui)
{
  UFG::DUIContext *v1; // rdi
  UFG::CommandContext *v2; // rbx
  char *tags; // [rsp+28h] [rbp-30h]
  const char *v4; // [rsp+30h] [rbp-28h]
  const char *v5; // [rsp+38h] [rbp-20h]
  __int64 v6; // [rsp+40h] [rbp-18h]

  v1 = dui;
  tags = "WorldEditor.SpawningMenu";
  v4 = "WorldEditor.DebugMenu";
  v5 = "WorldEditor.ContextMenu";
  v6 = 0i64;
  v2 = (UFG::CommandContext *)UFG::qMalloc(0x50ui64, "CommandContext", 0i64);
  if ( v2 )
  {
    v2->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable';
    UFG::qBaseTreeRB::qBaseTreeRB(&v2->mDictionary.mTree);
  }
  else
  {
    v2 = 0i64;
  }
  UFG::DUIContext::ShowPopupMenu(v1, &v1->mInputState.mMousePos, (const char **)&tags, v2);
}

// File Line: 635
// RVA: 0x20BCC0
signed __int64 __fastcall UFG::Editor::GetDrawMode()
{
  unsigned int v0; // ecx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v1; // rax
  unsigned int v2; // edx

  v0 = 0;
  if ( UFG::Editor::mInitialized
    && (v1 = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
    while ( !*((_BYTE *)v1 + 88) )
    {
      v1 = &v1[2][-1].mNext;
      if ( v1 == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v1 = 0i64;
  }
  if ( !UFG::Editor::mActive || !v1 )
    return 1i64;
  v2 = (unsigned int)v1[8][7].mNext;
  if ( v2 != 2 )
    return v2;
  LOBYTE(v0) = UFG::Metrics::msInstance.mSimPausedDebug == 0;
  return v0;
}

// File Line: 645
// RVA: 0x20BC60
__int64 __fastcall UFG::Editor::GetDrawFlags()
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v0; // rax
  __int64 result; // rax

  if ( UFG::Editor::mInitialized
    && (v0 = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
    while ( !*((_BYTE *)v0 + 88) )
    {
      v0 = &v0[2][-1].mNext;
      if ( v0 == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v0 = 0i64;
  }
  if ( UFG::Editor::mActive && v0 )
    result = HIDWORD(v0[8][7].mNext);
  else
    result = 0i64;
  return result;
}

