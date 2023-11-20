// File Line: 98
// RVA: 0x549B10
void __fastcall UFG::MeleeInfo::Reset(UFG::MeleeInfo *this)
{
  ActionPath *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  __int64 v8; // rax
  char *v9; // rcx

  v1 = &this->mActionPath;
  *(_QWORD *)&this->mAttackLocationLateralID = 0i64;
  this->mAttackFromBehind = 0;
  *(_QWORD *)&this->mAttackMaterialUID = 0i64;
  this->mAttackIntensityUID = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->mHitPosition.x = UFG::qVector3::msZero.x;
  this->mHitPosition.y = v2;
  this->mHitPosition.z = v3;
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
    v8 = this->mActionPath.mPath.mData.mOffset;
    if ( v8 )
    {
      v9 = (char *)&this->mActionPath.mPath.mData + v8;
      if ( v9 )
        operator delete[](v9);
    }
    v1->mPath.mData.mOffset = 0i64;
    v1->mPath.mCount &= 0x80000000;
  }
  ActionPath::Append(v1, 0i64);
}

// File Line: 335
// RVA: 0x51F090
UFG::ComponentIDDesc *__fastcall UFG::HitReactionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HitReactionComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HitReactionComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HitReactionComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::HitReactionComponent::_DescInit = 1;
    UFG::HitReactionComponent::_TypeUID = UFG::HitReactionComponent::_TypeIDesc.mChildBitMask | (UFG::HitReactionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HitReactionComponent::_HitReactionComponentTypeUID = UFG::HitReactionComponent::_TypeIDesc.mChildBitMask | (UFG::HitReactionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HitReactionComponent::_TypeIDesc;
}

