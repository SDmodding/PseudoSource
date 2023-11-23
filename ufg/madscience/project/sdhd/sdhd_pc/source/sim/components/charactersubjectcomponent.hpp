// File Line: 41
// RVA: 0x51EB20
UFG::ComponentIDDesc *__fastcall UFG::CharacterSubjectComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterSubjectComponent::_DescInit )
  {
    v0 = UFG::CameraSubject::AccessComponentDesc();
    ++UFG::CameraSubject::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CameraSubject::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CharacterSubjectComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CharacterSubjectComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CharacterSubjectComponent::_TypeIDesc.mChildren = 0;
    UFG::CharacterSubjectComponent::_DescInit = 1;
    UFG::CharacterSubjectComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CharacterSubjectComponent::_CharacterSubjectComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CharacterSubjectComponent::_TypeIDesc;
}

// File Line: 58
// RVA: 0x53B770
void __fastcall UFG::CharacterSubjectComponent::IsPlayer(UFG::InventoryComponent *this)
{
  UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject);
}

// File Line: 63
// RVA: 0x5359F0
bool __fastcall UFG::CharacterSubjectComponent::HasParkourHandle(UFG::CharacterSubjectComponent *this)
{
  return this->mParkourHandle != 0i64;
}

// File Line: 118
// RVA: 0x52FD40
float __fastcall UFG::CharacterSubjectComponent::GetSpeed(UFG::CharacterSubjectComponent *this)
{
  return this->mFilteredSpeed;
}

// File Line: 119
// RVA: 0x535A30
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::HeadPosition(UFG::CharacterSubjectComponent *this)
{
  if ( !this->mHeadDirty )
    return &this->mHeadPosition;
  UFG::CharacterSubjectComponent::UpdateHead(this);
  return &this->mHeadPosition;
}

// File Line: 120
// RVA: 0x3C0BE0
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::CambonePosition(UFG::CharacterSubjectComponent *this)
{
  if ( !this->mCamboneDirty )
    return &this->mCambonePosition;
  UFG::CharacterSubjectComponent::UpdateCambone(this);
  return &this->mCambonePosition;
}

// File Line: 121
// RVA: 0x3C7D60
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::PelvisPosition(UFG::CharacterSubjectComponent *this)
{
  if ( !this->mPelvisDirty )
    return &this->mPelvisPosition;
  UFG::CharacterSubjectComponent::UpdatePelvis(this);
  return &this->mPelvisPosition;
}

// File Line: 123
// RVA: 0x533990
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::GrapplePosition(UFG::CharacterSubjectComponent *this)
{
  return &this->mGrapplePosition;
}

// File Line: 138
// RVA: 0x52F970
float __fastcall UFG::CharacterSubjectComponent::GetRadius(UFG::CharacterSubjectComponent *this)
{
  return this->mRadius;
}

// File Line: 139
// RVA: 0x52DF40
float __fastcall UFG::CharacterSubjectComponent::GetHeight(UFG::CharacterSubjectComponent *this)
{
  return this->mBox.mMax.z - this->mBox.mMin.z;
}

// File Line: 143
// RVA: 0x52ACB0
UFG::qBox *__fastcall UFG::CharacterSubjectComponent::GetBoxMin(UFG::CharacterSubjectComponent *this)
{
  return &this->mBox;
}

// File Line: 144
// RVA: 0x52ACA0
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::GetBoxMax(UFG::CharacterSubjectComponent *this)
{
  return &this->mBox.mMax;
}

// File Line: 282
// RVA: 0x3C3590
float __fastcall UFG::CharacterSubjectComponent::GetLockedElevation(
        UFG::CharacterSubjectComponent *this,
        UFG::CharacterSubjectComponent::SrcTransform src)
{
  float result; // xmm0_4

  switch ( src )
  {
    case SrcTransform_Camera:
      result = this->rLockedElevationCam;
      break;
    case SrcTransform_Pelvis:
      result = this->rLockedElevationHip;
      break;
    case SrcTransform_Head:
      result = this->rLockedElevationHed;
      break;
    case SrcTransform_FocusCreatureCambone:
      result = this->rLockedElevationFocusCreatureCambone;
      break;
    case SrcTransform_FocusCreaturePelvis:
      result = this->rLockedElevationFocusCreaturePelvis;
      break;
    case SrcTransform_FocusCreatureHead:
      result = this->rLockedElevationFocusCreatureHead;
      break;
    default:
      result = this->rLockedElevationDef;
      break;
  }
  return result;
}

