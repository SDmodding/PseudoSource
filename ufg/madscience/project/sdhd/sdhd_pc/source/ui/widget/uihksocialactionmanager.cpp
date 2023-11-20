// File Line: 41
// RVA: 0x1566CB0
__int64 dynamic_initializer_for__UFG::UIHKSocialActionManager::SocialAction__()
{
  UFG::UIHKSocialActionWidget::UIHKSocialActionWidget(&UFG::UIHKSocialActionManager::SocialAction);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKSocialActionManager::SocialAction__);
}

// File Line: 66
// RVA: 0x5CD560
void __fastcall UFG::UIHKSocialActionManager::~UIHKSocialActionManager(UFG::UIHKSocialActionManager *this)
{
  UFG::UIHKSocialActionManager *v1; // rbx

  v1 = this;
  UFG::UIHKSocialActionManager::mThis = 0i64;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKHelpBarWidget::Hide(&UFG::UIHKScreenGlobalOverlay::mThis->HelpBar, UI_HASH_HELPBAR_SOCIAL_20);
  v1->mTargets.size = 0;
  v1->mScoredTargets.size = 0;
}

// File Line: 79
// RVA: 0x5ED560
void __fastcall UFG::UIHKSocialActionManager::Init(UFG::UIHKSocialActionManager *this, UFG::UIScreen *screen)
{
  if ( screen )
  {
    UFG::UIHKSocialActionManager::SocialAction.mID = 0;
    if ( ((unsigned int)UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.pObjectInterface->vfptr->gap8[8])(
        UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.pObjectInterface,
        &UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage,
        *(_QWORD *)&UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.mValue.NValue);
      UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.pObjectInterface = 0i64;
    }
    UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.Type = 6;
    *(_QWORD *)&UFG::UIHKSocialActionManager::SocialAction.mInitScreenX = 0i64;
    *(_QWORD *)&UFG::UIHKSocialActionManager::SocialAction.mWidgetNameOnStage.mValue.NValue = "mc_FaceAction0";
  }
}

// File Line: 221
// RVA: 0x617640
void __fastcall UFG::UIHKSocialActionManager::Update(UFG::UIHKSocialActionManager *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rdi
  UFG::UIHKSocialActionManager *v4; // rbx
  signed int v5; // ebx
  Scaleform::GFx::Movie *v6; // rdi
  char ptr; // [rsp+38h] [rbp-40h]
  __int64 v8; // [rsp+48h] [rbp-30h]
  unsigned int v9; // [rsp+50h] [rbp-28h]
  double v10; // [rsp+58h] [rbp-20h]

  v3 = screen;
  v4 = this;
  UFG::UIHKSocialActionWidget::Update(&UFG::UIHKSocialActionManager::SocialAction, screen, elapsed, 0);
  if ( v4->mTargets.p[4].m_pSimObject )
  {
    v5 = 4;
  }
  else if ( v4->mTargets.p[3].m_pSimObject )
  {
    v5 = 3;
  }
  else if ( v4->mTargets.p[2].m_pSimObject )
  {
    v5 = 2;
  }
  else
  {
    if ( !v4->mTargets.p[1].m_pSimObject )
      return;
    v5 = 1;
  }
  v6 = v3->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v9 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(v8, &ptr, COERCE_DOUBLE(*(_QWORD *)&v10));
    v8 = 0i64;
  }
  v9 = 5;
  v10 = (double)v5;
  Scaleform::GFx::Movie::Invoke(v6, "FaceAction_hitTest", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

