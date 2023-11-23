// File Line: 98
// RVA: 0x549B10
void __fastcall UFG::MeleeInfo::Reset(UFG::MeleeInfo *this)
{
  ActionPath *p_mActionPath; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  __int64 mOffset; // rax
  char *v9; // rcx

  p_mActionPath = &this->mActionPath;
  *(_QWORD *)&this->mAttackLocationLateralID = 0i64;
  this->mAttackFromBehind = 0;
  *(_QWORD *)&this->mAttackMaterialUID = 0i64;
  this->mAttackIntensityUID = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mHitPosition.x = UFG::qVector3::msZero.x;
  this->mHitPosition.y = y;
  this->mHitPosition.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mHitDirection.x = UFG::qVector3::msZero.x;
  this->mHitDirection.y = v4;
  this->mHitDirection.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->mHitNormal.x = UFG::qVector3::msZero.x;
  this->mHitNormal.y = v6;
  this->mHitNormal.z = v7;
  if ( this->mActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->mActionPath.mPath.mData.mOffset;
    if ( mOffset )
    {
      v9 = (char *)&this->mActionPath.mPath.mData + mOffset;
      if ( v9 )
        operator delete[](v9);
    }
    p_mActionPath->mPath.mData.mOffset = 0i64;
    p_mActionPath->mPath.mCount &= 0x80000000;
  }
  ActionPath::Append(p_mActionPath, 0i64);
}

// File Line: 335
// RVA: 0x51F090
UFG::ComponentIDDesc *__fastcall UFG::HitReactionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HitReactionComponent::_DescInit )
  {
    UFG::HitReactionComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HitReactionComponent::_DescInit = 1;
    UFG::HitReactionComponent::_TypeUID = UFG::HitReactionComponent::_TypeIDesc.mChildBitMask | (UFG::HitReactionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HitReactionComponent::_HitReactionComponentTypeUID = UFG::HitReactionComponent::_TypeIDesc.mChildBitMask | (UFG::HitReactionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HitReactionComponent::_TypeIDesc;
}

