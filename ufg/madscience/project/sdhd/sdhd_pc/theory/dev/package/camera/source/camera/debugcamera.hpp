// File Line: 21
// RVA: 0xB98F0
UFG::ComponentIDDesc *__fastcall UFG::DebugCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::DebugCameraComponent::_DescInit )
  {
    v0 = UFG::BaseCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::DebugCameraComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::DebugCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::DebugCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::DebugCameraComponent::_DescInit = 1;
    UFG::DebugCameraComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::DebugCameraComponent::_DebugCameraComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::DebugCameraComponent::_TypeIDesc;
}

// File Line: 30
// RVA: 0xB9AE0
float __fastcall UFG::DebugCameraComponent::GetFov(UFG::DebugCameraComponent *this)
{
  return this->mFov;
}

