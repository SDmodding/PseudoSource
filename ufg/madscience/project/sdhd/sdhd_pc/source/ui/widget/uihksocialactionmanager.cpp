// File Line: 41
// RVA: 0x1566CB0
__int64 dynamic_initializer_for__UFG::UIHKSocialActionManager::SocialAction__()
{
  UFG::UIHKSocialActionWidget::UIHKSocialActionWidget(&UFG::UIHKSocialActionManager::SocialAction);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKSocialActionManager::SocialAction__);
}

// File Line: 66
// RVA: 0x5CD560
void __fastcall UFG::UIHKSocialActionManager::~UIHKSocialActionManager(UFG::UIHKSocialActionManager *this)
{
  UFG::UIHKSocialActionManager::mThis = 0i64;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKHelpBarWidget::Hide(&UFG::UIHKScreenGlobalOverlay::mThis->HelpBar, UI_HASH_HELPBAR_SOCIAL_20);
  this->mTargets.size = 0;
  this->mScoredTargets.size = 0;
}

// File Line: 79
// RVA: 0x5ED560
void __fastcall UFG::UIHKSocialActionManager::Init(UFG::UIHKSocialActionManager *this, UFG::UIScreen *screen)
{
  if ( screen )
  {
    UFG::UIHKSocialActionManager::SocialAction.mID = 0;
    if ( (UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.pObjectInterface->vfptr->gap8[8])(
        UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.pObjectInterface,
        &UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage,
        UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.mValue);
      UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.pObjectInterface = 0i64;
    }
    UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.Type = VT_String;
    *(_QWORD *)&UFG::UIHKSocialActionManager::SocialAction.mInitScreenX = 0i64;
    UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.mValue.pString = "mc_FaceAction0";
  }
}

// File Line: 221
// RVA: 0x617640
void __fastcall UFG::UIHKSocialActionManager::Update(
        UFG::UIHKSocialActionManager *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  int v5; // ebx
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-40h] BYREF

  UFG::UIHKSocialActionWidget::Update(&UFG::UIHKSocialActionManager::SocialAction, screen, elapsed, 0);
  if ( this->mTargets.p[4].m_pSimObject )
  {
    v5 = 4;
  }
  else if ( this->mTargets.p[3].m_pSimObject )
  {
    v5 = 3;
  }
  else if ( this->mTargets.p[2].m_pSimObject )
  {
    v5 = 2;
  }
  else
  {
    if ( !this->mTargets.p[1].m_pSimObject )
      return;
    v5 = 1;
  }
  pObject = screen->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)v5;
  Scaleform::GFx::Movie::Invoke(pObject, "FaceAction_hitTest", 0i64, &ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

