// File Line: 58
// RVA: 0x3BEE40
UFG::ComponentIDDesc *__fastcall UFG::GameCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::GameCameraComponent::_DescInit )
  {
    v0 = UFG::BaseCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::GameCameraComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::GameCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::GameCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::GameCameraComponent::_DescInit = 1;
    UFG::GameCameraComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::GameCameraComponent::_GameCameraComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::GameCameraComponent::_TypeIDesc;
}

// File Line: 76
// RVA: 0x3C6D60
SSMetaClass *__fastcall UFG::GameCameraComponent::MotionRelativeDirection(SSClass *this)
{
  return &this->i_metaclass;
}

// File Line: 363
// RVA: 0x3BEED0
UFG::ComponentIDDesc *__fastcall UFG::GameSubject::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::GameSubject::_DescInit )
  {
    v0 = UFG::CameraSubject::AccessComponentDesc();
    ++UFG::CameraSubject::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CameraSubject::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::GameSubject::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::GameSubject::_TypeIDesc.mChildBitMask = v1;
    UFG::GameSubject::_TypeIDesc.mChildren = 0;
    UFG::GameSubject::_DescInit = 1;
    UFG::GameSubject::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::GameSubject::_GameSubjectTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::GameSubject::_TypeIDesc;
}

