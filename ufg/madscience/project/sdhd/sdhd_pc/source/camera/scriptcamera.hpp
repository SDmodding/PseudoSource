// File Line: 37
// RVA: 0x3BEFF0
UFG::ComponentIDDesc *__fastcall UFG::ScriptCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::ScriptCameraComponent::_DescInit )
  {
    v0 = UFG::GameCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ScriptCameraComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::ScriptCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ScriptCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::ScriptCameraComponent::_DescInit = 1;
    UFG::ScriptCameraComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::ScriptCameraComponent::_TypeIDesc;
}

// File Line: 48
// RVA: 0x3C34A0
float __fastcall UFG::ScriptCameraComponent::GetFov(UFG::ScriptCameraComponent *this)
{
  return (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
}

// File Line: 49
// RVA: 0x50FC50
void __fastcall UFG::ScriptCameraComponent::SetFov(UFG::ScriptCameraComponent *this, float degrees)
{
  UFG::HomerCubic<float> *p_mFov; // rbx

  p_mFov = &this->mFov;
  this->mFov.p1 = degrees;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  p_mFov->mParameter = 0.0;
  p_mFov->p0 = p_mFov->p1;
  p_mFov->v0 = p_mFov->v1;
  UFG::HomerCubic<float>::MakeCoeffs(p_mFov);
  p_mFov->mParameter = 0.0;
}

