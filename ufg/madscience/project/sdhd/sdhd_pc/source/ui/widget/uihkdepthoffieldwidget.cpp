// File Line: 19
// RVA: 0x5C3E70
void __fastcall UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(UFG::UIHKDepthOfFieldWidget *this)
{
  float mFarRange; // xmm2_4
  float mNearBlurRadius; // xmm3_4

  Render::DepthOfField::Focus::Focus(&this->mFocus);
  this->mFocus.mInFocusRange = UFG::UIHKTweakables::TweakDofInFocusRange;
  this->mFocus.mNearRange = UFG::UIHKTweakables::TweakDofNearRange;
  this->mFocus.mFarRange = UFG::UIHKTweakables::TweakDofFarRange;
  mFarRange = this->mFocus.mFarRange;
  this->mFocus.mNearBlurRadius = UFG::UIHKTweakables::TweakDofNearBlurRadius;
  mNearBlurRadius = this->mFocus.mNearBlurRadius;
  this->mFocus.mFarBlurRadius = UFG::UIHKTweakables::TweakDofFarBlurRadius;
  UFG::GameCameraComponent::BeginDOFOverride(
    this->mFocus.mInFocusRange,
    this->mFocus.mNearRange,
    mFarRange,
    mNearBlurRadius,
    UFG::UIHKTweakables::TweakDofFarBlurRadius,
    DOFOverridePriority_0);
}

// File Line: 26
// RVA: 0x5C9520
void __fastcall UFG::UIHKDepthOfFieldWidget::~UIHKDepthOfFieldWidget(UFG::UIHKDepthOfFieldWidget *this)
{
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
}

