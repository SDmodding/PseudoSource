// File Line: 20
// RVA: 0x3BF080
UFG::ComponentIDDesc *__fastcall UFG::TurfCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TurfCameraComponent::_DescInit )
  {
    v0 = UFG::BaseCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TurfCameraComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TurfCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TurfCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::TurfCameraComponent::_DescInit = 1;
    UFG::TurfCameraComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TurfCameraComponent::_TurfCameraComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TurfCameraComponent::_TypeIDesc;
}

