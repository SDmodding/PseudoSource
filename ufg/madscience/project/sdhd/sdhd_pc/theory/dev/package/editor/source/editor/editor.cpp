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
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__mNotificationMessage__);
}

// File Line: 70
// RVA: 0x146DA20
__int64 UFG::Editor::_dynamic_initializer_for__gOptions__()
{
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gOptions__);
}

// File Line: 80
// RVA: 0x146E7D0
__int64 UFG::Editor::_dynamic_initializer_for__mViews__()
{
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__mViews__);
}

// File Line: 83
// RVA: 0x146E6A0
__int64 UFG::Editor::_dynamic_initializer_for__mHoverObjectList__()
{
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__mHoverObjectList__);
}

// File Line: 86
// RVA: 0x146E730
__int64 UFG::Editor::_dynamic_initializer_for__mPhysicsCollisionModelName__()
{
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__mPhysicsCollisionModelName__);
}

// File Line: 274
// RVA: 0x207310
void __fastcall UFG::Editor::Deactivate(UFG::Editor *this)
{
  UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *i; // rdi
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> *mPrev; // rbx
  UFG::Editor::VisibilityManager *v3; // rcx
  UFG::Editor::SelectionManager *v4; // rcx
  const char *v5; // rdx
  UFG::qNode<UFG::DUISurface,UFG::DUISurface> **Surface; // rax
  UFG::DUIContext *v7; // rax
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::qBaseTreeRB *j; // rax
  UFG::SimObject *v10; // rbx

  if ( UFG::Editor::mActive )
  {
    UFG::qEnablePrintHandlers(UFG::Editor::mSavedPrintHandlersEnabled);
    for ( i = (UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *)&UFG::Editor::mViews.mNode.mNext[-1].mNext;
          i != (UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *)((char *)&UFG::Editor::mViews - 8);
          i = (UFG::qList<UFG::Editor::View,UFG::Editor::View,1,0> *)&i[1].mNode.mPrev[-1].mNext )
    {
      mPrev = i[5].mNode.mPrev;
      UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)&mPrev->mNext);
      *(float *)&mPrev[7].mPrev = (float)((float)SLODWORD(mPrev->mPrev[4].mPrev[9].mPrev) * 3.1415927) * 0.0055555557;
    }
    Render::SetRenderFeatures(&UFG::Editor::mSavedGameRenderFeatures);
    UFG::Editor::VisibilityManager::Deactivate(v3);
    UFG::Editor::SelectionManager::InvalidatePaths(v4);
    v5 = UFG::Editor::mWindowGroup_Game;
    if ( UFG::Editor::mWindowMode == WindowMode_Editor )
      v5 = UFG::Editor::mWindowGroup_Editor;
    UFG::DUIManager::DisableGroup(UFG::gDUIWindowManager, v5);
    if ( UFG::Editor::mWindowMode == WindowMode_Editor )
    {
      UFG::Editor::Utility::SetMainWindowClientRect(&UFG::Editor::mGameWindowRect);
      Surface = UFG::DUIManager::GetSurface(UFG::gDUIWindowManager, "DUI.GameOverlay");
      v7 = (UFG::DUIContext *)((__int64 (__fastcall *)(UFG::qNode<UFG::DUISurface,UFG::DUISurface> **))(*Surface)[1].mPrev)(Surface);
      UFG::DUIContext::SetOverallRect(v7, &UFG::Editor::mGameWindowRect);
    }
    UFG::Metrics::msInstance.mSimPausedDebug = 0;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
    UFG::Editor::SetCursorMode(CursorMode_None);
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    LOBYTE(mCurrentCamera->mCamera.mTransformation.v3.x) = 0;
    UFG::PropertySetManager::SetModificationCallback(0i64);
    UFG::qString::Set(&UFG::Editor::mNotificationMessage, "Editor Deactivated");
    UFG::Editor::mUpdateStyle = 1;
    UFG::Editor::mNotificationAge = FLOAT_1_5;
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::gSim);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::gSim.mSimObjects.mTree, &v10->mNode) )
    {
      v10 = j ? (UFG::SimObject *)&j[-1].mNULL : 0i64;
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
  UFG::CommandContext *v2; // rbx
  char *tags[6]; // [rsp+28h] [rbp-30h] BYREF

  tags[0] = "WorldEditor.SpawningMenu";
  tags[1] = "WorldEditor.DebugMenu";
  tags[2] = "WorldEditor.ContextMenu";
  tags[3] = 0i64;
  v2 = (UFG::CommandContext *)UFG::qMalloc(0x50ui64, "CommandContext", 0i64);
  if ( v2 )
  {
    v2->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
    UFG::qBaseTreeRB::qBaseTreeRB(&v2->mDictionary.mTree);
  }
  else
  {
    v2 = 0i64;
  }
  UFG::DUIContext::ShowPopupMenu(dui, (UFG::qBaseNodeRB **)&dui->mInputState, (const char **)tags, v2);
}

// File Line: 635
// RVA: 0x20BCC0
__int64 __fastcall UFG::Editor::GetDrawMode()
{
  unsigned int v0; // ecx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **p_mNext; // rax
  unsigned int mNext; // edx

  v0 = 0;
  if ( !UFG::Editor::mInitialized
    || (p_mNext = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !*((_BYTE *)p_mNext + 88) )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  if ( !UFG::Editor::mActive || !p_mNext )
    return 1i64;
  mNext = (unsigned int)p_mNext[8][7].mNext;
  if ( mNext != 2 )
    return mNext;
  LOBYTE(v0) = !UFG::Metrics::msInstance.mSimPausedDebug;
  return v0;
}

// File Line: 645
// RVA: 0x20BC60
__int64 __fastcall UFG::Editor::GetDrawFlags()
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **p_mNext; // rax

  if ( !UFG::Editor::mInitialized
    || (p_mNext = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !*((_BYTE *)p_mNext + 88) )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  if ( UFG::Editor::mActive && p_mNext )
    return HIDWORD(p_mNext[8][7].mNext);
  else
    return 0i64;
}

