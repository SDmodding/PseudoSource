// File Line: 20
// RVA: 0xA28030
void __fastcall UFG::UI::QueuePopScreen(const char *screen_name)
{
  UFG::UIScreenManager *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **ScreenFromStack; // rax

  v1 = UFG::UIScreenManager::s_instance;
  ScreenFromStack = UFG::UIScreenManagerBase::getScreenFromStack(
                      UFG::UIScreenManager::s_instance,
                      screen_name,
                      &UFG::UIScreenManager::s_instance->m_screenStack);
  if ( ScreenFromStack
    || (ScreenFromStack = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)UFG::UIScreenManagerBase::getScreenFromPendingStack(
                                                                        v1,
                                                                        screen_name,
                                                                        &v1->mPendingScreenLoads)) != 0i64 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, *((_DWORD *)ScreenFromStack + 28));
  }
}

// File Line: 46
// RVA: 0xA26240
float __fastcall UFG::UI::GetFloat(Scaleform::GFx::Value *flashVal)
{
  __int32 v1; // eax

  v1 = flashVal->Type & 0x8F;
  if ( v1 == 3 )
    return (float)flashVal->mValue.IValue;
  if ( v1 == 4 )
    return (float)flashVal->mValue.IValue;
  return flashVal->mValue.NValue;
}

