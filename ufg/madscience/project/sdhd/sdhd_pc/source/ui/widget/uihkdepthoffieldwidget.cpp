// File Line: 19
// RVA: 0x5C3E70
void __fastcall UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(UFG::UIHKDepthOfFieldWidget *this)
{
  UFG::UIHKDepthOfFieldWidget *v1; // rbx
  float v2; // xmm2_4
  float v3; // xmm3_4

  v1 = this;
  Render::DepthOfField::Focus::Focus(&this->mFocus);
  v1->mFocus.mInFocusRange = UFG::UIHKTweakables::TweakDofInFocusRange;
  v1->mFocus.mNearRange = UFG::UIHKTweakables::TweakDofNearRange;
  v1->mFocus.mFarRange = UFG::UIHKTweakables::TweakDofFarRange;
  v2 = v1->mFocus.mFarRange;
  v1->mFocus.mNearBlurRadius = UFG::UIHKTweakables::TweakDofNearBlurRadius;
  v3 = v1->mFocus.mNearBlurRadius;
  v1->mFocus.mFarBlurRadius = UFG::UIHKTweakables::TweakDofFarBlurRadius;
  UFG::GameCameraComponent::BeginDOFOverride(
    v1->mFocus.mInFocusRange,
    v1->mFocus.mNearRange,
    v2,
    v3,
    UFG::UIHKTweakables::TweakDofFarBlurRadius,
    0);
}

// File Line: 26
// RVA: 0x5C9520
void __fastcall UFG::UIHKDepthOfFieldWidget::~UIHKDepthOfFieldWidget(UFG::UIHKDepthOfFieldWidget *this)
{
  UFG::GameCameraComponent::EndDOFOverride(0);
}

