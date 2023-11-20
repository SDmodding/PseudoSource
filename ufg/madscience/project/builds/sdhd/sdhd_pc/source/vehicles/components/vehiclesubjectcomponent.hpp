// File Line: 52
// RVA: 0x66F1C0
UFG::ComponentIDDesc *__fastcall UFG::VehicleSubjectComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleSubjectComponent::_DescInit )
  {
    v0 = UFG::CameraSubject::AccessComponentDesc();
    ++UFG::CameraSubject::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CameraSubject::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::VehicleSubjectComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::VehicleSubjectComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::VehicleSubjectComponent::_TypeIDesc.mChildren = 0;
    UFG::VehicleSubjectComponent::_DescInit = 1;
    UFG::VehicleSubjectComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::VehicleSubjectComponent::_VehicleSubjectComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::VehicleSubjectComponent::_TypeIDesc;
}

// File Line: 68
// RVA: 0x67B550
UFG::qVector3 *__fastcall UFG::VehicleSubjectComponent::GetUp(UFG::VehicleSubjectComponent *this)
{
  return &this->vUp;
}

// File Line: 70
// RVA: 0x67AFD0
UFG::qVector3 *__fastcall UFG::VehicleSubjectComponent::GetPosition(UFG::VehicleSubjectComponent *this)
{
  return &this->mPositionOffset;
}

// File Line: 71
// RVA: 0x67A7F0
UFG::qMatrix44 *__fastcall UFG::VehicleSubjectComponent::GetLocalWorld(UFG::VehicleSubjectComponent *this)
{
  return &this->mLocalWorldOffset;
}

// File Line: 72
// RVA: 0x67BA90
UFG::qMatrix44 *__fastcall UFG::VehicleSubjectComponent::GetWorldLocal(UFG::VehicleSubjectComponent *this)
{
  return &this->mWorldLocalOffset;
}

// File Line: 88
// RVA: 0x67F360
char __fastcall UFG::VehicleSubjectComponent::IsParked(UFG::VehicleSubjectComponent *this)
{
  UFG::VehicleSubjectComponent *v1; // rbx
  char result; // al

  v1 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[34].__vecDelDtor)()
    || (result = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v1->vfptr[35].__vecDelDtor)(v1)) != 0 )
  {
    result = 1;
  }
  return result;
}

// File Line: 98
// RVA: 0x674210
_BOOL8 __fastcall UFG::VehicleSubjectComponent::CanPassOnLeft(UFG::VehicleSubjectComponent *this)
{
  return this->bCanPassLeft;
}

// File Line: 99
// RVA: 0x674220
_BOOL8 __fastcall UFG::VehicleSubjectComponent::CanPassOnRight(UFG::VehicleSubjectComponent *this)
{
  return this->bCanPassRight;
}

// File Line: 101
// RVA: 0x6747D0
bool __fastcall UFG::VehicleSubjectComponent::ContainsPlayer(UFG::VehicleSubjectComponent *this)
{
  return this->pPlayerOccupant != 0i64;
}

// File Line: 124
// RVA: 0x67B850
UFG::qVector3 *__fastcall UFG::VehicleSubjectComponent::GetVelocity(UFG::VehicleSubjectComponent *this)
{
  return &this->vVelocity;
}

// File Line: 131
// RVA: 0x67B180
float __fastcall UFG::VehicleSubjectComponent::GetRadius(UFG::VehicleSubjectComponent *this)
{
  return this->mRadius;
}

// File Line: 134
// RVA: 0x67A6E0
float __fastcall UFG::VehicleSubjectComponent::GetHeight(UFG::VehicleSubjectComponent *this)
{
  return this->mBox.mMax.z - this->mBox.mMin.z;
}

// File Line: 136
// RVA: 0x679710
UFG::qBox *__fastcall UFG::VehicleSubjectComponent::GetBoxMin(UFG::VehicleSubjectComponent *this)
{
  return &this->mBox;
}

// File Line: 137
// RVA: 0x679700
UFG::qVector3 *__fastcall UFG::VehicleSubjectComponent::GetBoxMax(UFG::VehicleSubjectComponent *this)
{
  return &this->mBox.mMax;
}

