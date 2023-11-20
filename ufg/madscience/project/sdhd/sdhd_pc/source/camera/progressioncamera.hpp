// File Line: 25
// RVA: 0x3BEF60
UFG::ComponentIDDesc *__fastcall UFG::ProgressionCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::ProgressionCameraComponent::_DescInit )
  {
    v0 = UFG::GameCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ProgressionCameraComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::ProgressionCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ProgressionCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::ProgressionCameraComponent::_DescInit = 1;
    UFG::ProgressionCameraComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::ProgressionCameraComponent::_TypeIDesc;
}

// File Line: 44
// RVA: 0x3C3480
float __fastcall UFG::ProgressionCameraComponent::GetFov(UFG::ProgressionCameraComponent *this)
{
  return (float)(this->mFov * 3.1415927) * 0.0055555557;
}

