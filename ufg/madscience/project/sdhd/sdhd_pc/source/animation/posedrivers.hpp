// File Line: 62
// RVA: 0x2BECD0
__int64 __fastcall JointReferences::GetClassNameUID(JointReferences *this)
{
  return JointReferences::sClassNameUID;
}

// File Line: 98
// RVA: 0x2DC2D0
_BOOL8 __fastcall PoseDriver::IsActive(PoseDriver *this)
{
  return this->mActive != 0;
}

// File Line: 99
// RVA: 0x2DCAD0
void __fastcall PoseDriver::SetActive(PoseDriver *this, bool tf)
{
  this->mActive = tf;
}

// File Line: 109
// RVA: 0x2DC3E0
_BOOL8 __fastcall PoseDriver::IsDisabled(PoseDriver *this)
{
  return this->mDisabled != 0;
}

// File Line: 150
// RVA: 0x2DC320
bool __fastcall AimConstraint::IsDisabled(AimConstraint *this)
{
  return AimConstraint::sDisable || this->mDisabled;
}

// File Line: 153
// RVA: 0x2BDAE0
__int64 __fastcall AimConstraint::GetClassNameUID(AimConstraint *this)
{
  return AimConstraint::sClassNameUID;
}

// File Line: 179
// RVA: 0x2C30C0
__int64 __fastcall AimConstraint::GetEffectorJoint(AimConstraint *this)
{
  return (unsigned int)this->mJointID;
}

// File Line: 222
// RVA: 0x2DC300
bool __fastcall AimConstraint2::IsDisabled(AimConstraint2 *this)
{
  return AimConstraint2::sDisable || this->mDisabled;
}

// File Line: 225
// RVA: 0x2AF780
Expression::IMemberMap *__fastcall AimConstraint2::CreateClone(AimConstraint2 *this)
{
  AimConstraint2 *v1; // rbx
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rcx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::CreateClone of AimConstraint2",
         0i64,
         1u);
  if ( v2 )
  {
    AimConstraint2::AimConstraint2((AimConstraint2 *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  *(_QWORD *)(v4 + 8) = v1->mResourceOwner;
  *(_QWORD *)(v4 + 32) = v1->mResourceOwner;
  *(_BYTE *)(v4 + 40) = v1->mActive;
  *(_BYTE *)(v4 + 41) = v1->mDisabled;
  *(_BYTE *)(v4 + 42) = v1->mBreakpoint;
  *(_DWORD *)(v4 + 44) = v1->mName.mUID;
  *(_DWORD *)(v4 + 48) = v1->mJointID;
  *(_DWORD *)(v4 + 52) = v1->mTargetJointID;
  *(_DWORD *)(v4 + 56) = v1->mEffectorJoint.mUID;
  *(_DWORD *)(v4 + 60) = v1->mTargetJoint.mUID;
  return (Expression::IMemberMap *)v4;
}

// File Line: 274
// RVA: 0x2DC340
bool __fastcall AimConstraintMultiLink::IsDisabled(AimConstraintMultiLink *this)
{
  return AimConstraintMultiLink::sDisable || this->mDisabled;
}

// File Line: 277
// RVA: 0x3A5610
void __fastcall AimConstraintMultiLink::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x90ui64, "MemberMap::AimConstraintMultiLink", 0i64, 1u);
  if ( v0 )
    AimConstraintMultiLink::AimConstraintMultiLink((AimConstraintMultiLink *)v0);
}

// File Line: 379
// RVA: 0x298C20
void __fastcall TwoLinkIKsolver::TwoLinkIKsolver(TwoLinkIKsolver *this, MemImageLoadFlag flag)
{
  UFG::qNode<PoseDriver,PoseDriver> *v2; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v2 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&TwoLinkIKsolver::`vftable';
  this->mLinkInfo.m_firstJointIdx = -1;
  this->mLinkInfo.m_secondJointIdx = -1;
  this->mLinkInfo.m_endBoneIdx = -1;
  this->mLinkInfo.m_firstJointTwistIdx = -1;
  this->mLinkInfo.m_secondJointTwistIdx = -1;
  this->mLinkInfo.m_hingeAxisLS = (hkVector4f)aabbOut.m_quad;
  this->mLinkInfo.m_cosineMaxHingeAngle = -1.0;
  this->mLinkInfo.m_cosineMinHingeAngle = 1.0;
  this->mLinkInfo.m_firstJointIkGain = 1.0;
  this->mLinkInfo.m_secondJointIkGain = 1.0;
  this->mLinkInfo.m_endJointIkGain = 1.0;
  this->mLinkInfo.m_endTargetMS = (hkVector4f)aabbOut.m_quad;
  this->mLinkInfo.m_endTargetRotationMS = (hkQuaternionf)qi.m_vec.m_quad;
  this->mLinkInfo.m_endBoneOffsetLS = (hkVector4f)aabbOut.m_quad;
  this->mLinkInfo.m_endBoneRotationOffsetLS = (hkQuaternionf)qi.m_vec.m_quad;
  *(_WORD *)&this->mLinkInfo.m_enforceEndPosition.m_bool = 1;
}

// File Line: 386
// RVA: 0x2DC450
bool __fastcall TwoLinkIKsolver::IsDisabled(TwoLinkIKsolver *this)
{
  return TwoLinkIKsolver::sDisable || this->mDisabled;
}

// File Line: 389
// RVA: 0x2C2AC0
const char *__fastcall TwoLinkIKsolver::GetClassname(TwoLinkIKsolver *this)
{
  return TwoLinkIKsolver::sClassName;
}

// File Line: 414
// RVA: 0x2BD6E0
__int64 __fastcall TwoLinkIKsolver::GetBaseJoint(TwoLinkIKsolver *this)
{
  return (unsigned int)this->mLinkInfo.m_firstJointIdx;
}

// File Line: 415
// RVA: 0x2C30D0
__int64 __fastcall TwoLinkIKsolver::GetEffectorJoint(TwoLinkIKsolver *this)
{
  return (unsigned int)this->mLinkInfo.m_endBoneIdx;
}

// File Line: 462
// RVA: 0x2DC3C0
bool __fastcall OrientationConstraint::IsDisabled(OrientationConstraint *this)
{
  return OrientationConstraint::sDisable || this->mDisabled;
}

// File Line: 465
// RVA: 0x2BF000
__int64 __fastcall OrientationConstraint::GetClassNameUID(OrientationConstraint *this)
{
  return OrientationConstraint::sClassNameUID;
}

// File Line: 530
// RVA: 0x2DC430
bool __fastcall TwistXRotLinearLink::IsDisabled(TwistXRotLinearLink *this)
{
  return TwistXRotLinearLink::sDisable || this->mDisabled;
}

// File Line: 533
// RVA: 0x3A6120
TwistXRotLinearLink *__fastcall TwistXRotLinearLink::Create()
{
  char *v0; // rdx
  _QWORD *v1; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "MemberMap::TwistXRotLinearLink", 0i64, 1u);
  if ( !v0 )
    return 0i64;
  *(_QWORD *)v0 = &Expression::IMemberMap::`vftable';
  *((_QWORD *)v0 + 1) = 0i64;
  v1 = v0 + 16;
  *v1 = v1;
  v1[1] = v1;
  *(_QWORD *)v0 = &PoseDriver::`vftable';
  *((_WORD *)v0 + 20) = 0;
  v0[42] = 0;
  *((_DWORD *)v0 + 11) = -1;
  *((UFG::qStaticSymbolUC *)v0 + 11) = symEffectorNone;
  *(_QWORD *)v0 = &TwistXRotLinearLink::`vftable';
  *((UFG::qSymbolUC *)v0 + 14) = UFG::gNullQSymbolUC;
  *((UFG::qSymbolUC *)v0 + 15) = UFG::gNullQSymbolUC;
  *((UFG::qSymbolUC *)v0 + 16) = UFG::gNullQSymbolUC;
  *(_QWORD *)(v0 + 68) = -1i64;
  *((_DWORD *)v0 + 19) = -1;
  v0[80] = 0;
  *((_DWORD *)v0 + 21) = -1090519040;
  *((_DWORD *)v0 + 22) = 0;
  v0[40] = 1;
  return (TwistXRotLinearLink *)v0;
}

// File Line: 563
// RVA: 0x2DC2E0
bool __fastcall TwistXRotLinearLink::IsBound(TwistXRotLinearLink *this)
{
  return this->mDriveJointID >= 0 && this->mBaseJointID >= 0 && this->mEndJointID >= 0;
}

// File Line: 595
// RVA: 0x2DC3A0
bool __fastcall FollowLink::IsDisabled(FollowLink *this)
{
  return FollowLink::sDisable || this->mDisabled;
}

// File Line: 598
// RVA: 0x2AFAF0
Expression::IMemberMap *__fastcall FollowLink::CreateClone(FollowLink *this)
{
  FollowLink *v1; // rbx
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rcx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "MemberMap::CreateClone of FollowLink", 0i64, 1u);
  if ( v2 )
  {
    FollowLink::FollowLink((FollowLink *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  *(_QWORD *)(v4 + 8) = v1->mResourceOwner;
  *(_QWORD *)(v4 + 32) = v1->mResourceOwner;
  *(_BYTE *)(v4 + 40) = v1->mActive;
  *(_BYTE *)(v4 + 41) = v1->mDisabled;
  *(_BYTE *)(v4 + 42) = v1->mBreakpoint;
  *(_DWORD *)(v4 + 44) = v1->mName.mUID;
  *(_QWORD *)(v4 + 48) = v1->mCreature;
  *(_DWORD *)(v4 + 56) = v1->mDriveJoint.mUID;
  *(_DWORD *)(v4 + 60) = v1->mFollowJoint.mUID;
  *(_DWORD *)(v4 + 64) = v1->mDriveJointID;
  *(_DWORD *)(v4 + 68) = v1->mFollowJointID;
  *(_DWORD *)(v4 + 72) = v1->mTransformFloatParamRotInput.mValue;
  *(_DWORD *)(v4 + 76) = v1->mTransformFloatParamRotOutput.mValue;
  *(_BYTE *)(v4 + 80) = v1->mDriveJointIsParentOfFollow;
  *(float *)(v4 + 84) = v1->m_M;
  *(float *)(v4 + 88) = v1->m_B;
  return (Expression::IMemberMap *)v4;
}

// File Line: 661
// RVA: 0x2DC360
bool __fastcall Follow2Link::IsDisabled(Follow2Link *this)
{
  return Follow2Link::sDisable || this->mDisabled;
}

// File Line: 664
// RVA: 0x2C1300
const char *__fastcall Follow2Link::GetClassname(Follow2Link *this)
{
  return Follow2Link::sClassName;
}

// File Line: 705
// RVA: 0x2DC380
bool __fastcall Follow3Link::IsDisabled(Follow3Link *this)
{
  return Follow3Link::sDisable || this->mDisabled;
}

// File Line: 708
// RVA: 0x2C1310
const char *__fastcall Follow3Link::GetClassname(Follow3Link *this)
{
  return Follow3Link::sClassName;
}

// File Line: 777
// RVA: 0x2DC410
bool __fastcall Spring1DOF::IsDisabled(Spring1DOF *this)
{
  return Spring1DOF::sDisable || this->mDisabled;
}

// File Line: 780
// RVA: 0x2AFCD0
Spring1DOF *__fastcall Spring1DOF::CreateClone(Spring1DOF *this)
{
  Spring1DOF *v1; // rdi
  char *v2; // rax
  Spring1DOF *v3; // rax
  Spring1DOF *v4; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB8ui64, "MemberMap::CreateClone of Spring1DOF", 0i64, 1u);
  if ( v2 )
  {
    Spring1DOF::Spring1DOF((Spring1DOF *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  Spring1DOF::operator=(v4, v1);
  return v4;
}

// File Line: 922
// RVA: 0x2DC3F0
bool __fastcall RootUprightDriver::IsDisabled(RootUprightDriver *this)
{
  return RootUprightDriver::sDisable || this->mDisabled;
}

// File Line: 925
// RVA: 0x2BF5D0
__int64 __fastcall RootUprightDriver::GetClassNameUID(RootUprightDriver *this)
{
  return RootUprightDriver::sClassNameUID;
}

