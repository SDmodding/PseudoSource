// File Line: 20
// RVA: 0xA28030
void __fastcall UFG::UI::QueuePopScreen(const char *screen_name)
{
  UFG::UIScreenManager *v1; // rbx
  const char *v2; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v3; // rax

  v1 = UFG::UIScreenManager::s_instance;
  v2 = screen_name;
  v3 = UFG::UIScreenManagerBase::getScreenFromStack(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         screen_name,
         &UFG::UIScreenManager::s_instance->m_screenStack);
  if ( v3
    || (v3 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)UFG::UIScreenManagerBase::getScreenFromPendingStack(
                                                           (UFG::UIScreenManagerBase *)&v1->vfptr,
                                                           v2,
                                                           &v1->mPendingScreenLoads)) != 0i64 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      *((_DWORD *)v3 + 28));
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

