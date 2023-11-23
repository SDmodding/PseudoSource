// File Line: 22
// RVA: 0x1495210
__int64 dynamic_initializer_for__DestructionSetDefinitionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionSetDefinitionTrack", 0xFFFFFFFF);
  DestructionSetDefinitionTrack::sClassNameUID = result;
  return result;
}

// File Line: 40
// RVA: 0x2DEC90
void __fastcall DestructionSetDefinitionTrack::DestructionSetDefinitionTrack(DestructionSetDefinitionTrack *this)
{
  ITrack::ITrack(this, DestructionSetDefinitionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSetDefinitionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDefinitionTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  *(_QWORD *)&this->mBulletDamageMultiplier = 0i64;
  *(_QWORD *)&this->mImpactDamageMultiplier = 0i64;
  this->mAttackDamageMultiplier = 0.0;
}

// File Line: 45
// RVA: 0x2E3C80
void __fastcall DestructionSetDefinitionTrack::~DestructionSetDefinitionTrack(DestructionSetDefinitionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDefinitionTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 64
// RVA: 0x1495190
__int64 dynamic_initializer_for__DestructionEventTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionEventTrack", 0xFFFFFFFF);
  DestructionEventTrack::sClassNameUID = result;
  return result;
}

// File Line: 105
// RVA: 0x2DEA90
void __fastcall DestructionEventTrack::DestructionEventTrack(DestructionEventTrack *this)
{
  ITrack::ITrack(this, DestructionEventTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionEventTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEventTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mSoundEffect = UFG::gNullQSymbolUC;
  *(_DWORD *)&this->mFractureObject = 0;
  *(_QWORD *)&this->mDisableCover = 0i64;
  this->mRenderModelSwap = UFG::gNullQSymbolUC;
  this->mVisualTreatment = UFG::gNullQSymbol;
  this->mDisableSelfIllumination = 0;
  this->mLifeSpan = -1.0;
}

// File Line: 110
// RVA: 0x2E3AC0
void __fastcall DestructionEventTrack::~DestructionEventTrack(DestructionEventTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEventTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 141
// RVA: 0x1495170
__int64 dynamic_initializer_for__DestructionEnableRiggedGeoTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionEnableRiggedGeoTrack", 0xFFFFFFFF);
  DestructionEnableRiggedGeoTrack::sClassNameUID = result;
  return result;
}

// File Line: 152
// RVA: 0x2DEA40
void __fastcall DestructionEnableRiggedGeoTrack::DestructionEnableRiggedGeoTrack(DestructionEnableRiggedGeoTrack *this)
{
  ITrack::ITrack(this, DestructionEnableRiggedGeoTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionEnableRiggedGeoTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableRiggedGeoTrack::`vftable;
  this->mBoneName = UFG::gNullQSymbolUC;
  *(_WORD *)&this->mEnable = 0;
}

// File Line: 157
// RVA: 0x2E3A50
void __fastcall DestructionEnableRiggedGeoTrack::~DestructionEnableRiggedGeoTrack(
        DestructionEnableRiggedGeoTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableRiggedGeoTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 173
// RVA: 0x1495250
__int64 dynamic_initializer_for__DestructionSpawnPropertySetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionSpawnPropertySetTrack", 0xFFFFFFFF);
  DestructionSpawnPropertySetTrack::sClassNameUID = result;
  return result;
}

// File Line: 200
// RVA: 0x2DEDA0
void __fastcall DestructionSpawnPropertySetTrack::DestructionSpawnPropertySetTrack(
        DestructionSpawnPropertySetTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  ITrack::ITrack(this, DestructionSpawnPropertySetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSpawnPropertySetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPropertySetTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mPropertySetName = UFG::gNullQSymbol;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mTranslateOffset.x = UFG::qVector3::msZero.x;
  this->mTranslateOffset.y = y;
  this->mTranslateOffset.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mRotateOffset.x = UFG::qVector3::msZero.x;
  this->mRotateOffset.y = v4;
  this->mRotateOffset.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->mLinearImpulseRotation.x = UFG::qVector3::msZero.x;
  this->mLinearImpulseRotation.y = v6;
  this->mLinearImpulseRotation.z = v7;
  this->mLinearImpulseMagnitude = 1.0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  this->mAngularImpulse.x = UFG::qVector3::msZero.x;
  this->mAngularImpulse.y = v8;
  this->mAngularImpulse.z = v9;
}

// File Line: 204
// RVA: 0x2E3D60
void __fastcall DestructionSpawnPropertySetTrack::~DestructionSpawnPropertySetTrack(
        DestructionSpawnPropertySetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPropertySetTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 224
// RVA: 0x1495230
__int64 dynamic_initializer_for__DestructionSpawnPhantomVolumeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionSpawnPhantomVolumeTrack", 0xFFFFFFFF);
  DestructionSpawnPhantomVolumeTrack::sClassNameUID = result;
  return result;
}

// File Line: 243
// RVA: 0x2DECF0
void __fastcall DestructionSpawnPhantomVolumeTrack::DestructionSpawnPhantomVolumeTrack(
        DestructionSpawnPhantomVolumeTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  ITrack::ITrack(this, DestructionSpawnPhantomVolumeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSpawnPhantomVolumeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPhantomVolumeTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mPhantomName = UFG::gNullQSymbolUC;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mTranslateOffset.x = UFG::qVector3::msZero.x;
  this->mTranslateOffset.y = y;
  this->mTranslateOffset.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mBoxExtents.x = UFG::qVector3::msZero.x;
  this->mBoxExtents.y = v4;
  this->mBoxExtents.z = v5;
  this->mPhantomTimer = -1.0;
}

// File Line: 247
// RVA: 0x2E3CF0
void __fastcall DestructionSpawnPhantomVolumeTrack::~DestructionSpawnPhantomVolumeTrack(
        DestructionSpawnPhantomVolumeTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPhantomVolumeTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 264
// RVA: 0x14951B0
__int64 dynamic_initializer_for__DestructionExplosionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionExplosionTrack", 0xFFFFFFFF);
  DestructionExplosionTrack::sClassNameUID = result;
  return result;
}

// File Line: 277
// RVA: 0x2DEB10
void __fastcall DestructionExplosionTrack::DestructionExplosionTrack(DestructionExplosionTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  ITrack::ITrack(this, DestructionExplosionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionExplosionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionExplosionTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mExplosionType = UFG::gNullQSymbol;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPosition.x = UFG::qVector3::msZero.x;
  this->mPosition.y = y;
  this->mPosition.z = z;
}

// File Line: 282
// RVA: 0x2E3B30
void __fastcall DestructionExplosionTrack::~DestructionExplosionTrack(DestructionExplosionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionExplosionTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 297
// RVA: 0x1495150
__int64 dynamic_initializer_for__DestructionEnableFractureElementTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionEnableFractureElementTrack", 0xFFFFFFFF);
  DestructionEnableFractureElementTrack::sClassNameUID = result;
  return result;
}

// File Line: 326
// RVA: 0x2DE9F0
void __fastcall DestructionEnableFractureElementTrack::DestructionEnableFractureElementTrack(
        DestructionEnableFractureElementTrack *this)
{
  ITrack::ITrack(this, DestructionEnableFractureElementTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionEnableFractureElementTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableFractureElementTrack::`vftable;
  this->mFractureElement1 = UFG::gNullQSymbolUC;
  this->mEnable1 = 0;
}

// File Line: 331
// RVA: 0x2E39E0
void __fastcall DestructionEnableFractureElementTrack::~DestructionEnableFractureElementTrack(
        DestructionEnableFractureElementTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableFractureElementTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 355
// RVA: 0x14951F0
__int64 dynamic_initializer_for__DestructionSetDamageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionSetDamageTrack", 0xFFFFFFFF);
  DestructionSetDamageTrack::sClassNameUID = result;
  return result;
}

// File Line: 365
// RVA: 0x2DEC40
void __fastcall DestructionSetDamageTrack::DestructionSetDamageTrack(DestructionSetDamageTrack *this)
{
  ITrack::ITrack(this, DestructionSetDamageTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSetDamageTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDamageTrack::`vftable;
  *(_QWORD *)&this->mDestructionObjectName.mUID = UFG::gNullQSymbolUC.mUID;
}

// File Line: 370
// RVA: 0x2E3C10
void __fastcall DestructionSetDamageTrack::~DestructionSetDamageTrack(DestructionSetDamageTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDamageTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 385
// RVA: 0x1495130
__int64 dynamic_initializer_for__DestructionDeleteConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionDeleteConstraintTrack", 0xFFFFFFFF);
  DestructionDeleteConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 396
// RVA: 0x2DE990
void __fastcall DestructionDeleteConstraintTrack::DestructionDeleteConstraintTrack(
        DestructionDeleteConstraintTrack *this)
{
  ITrack::ITrack(this, DestructionDeleteConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionDeleteConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionDeleteConstraintTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mDeleteConstraintName = UFG::gNullQSymbol;
  this->mDeleteConstraints = 0;
}

// File Line: 401
// RVA: 0x2E3970
void __fastcall DestructionDeleteConstraintTrack::~DestructionDeleteConstraintTrack(
        DestructionDeleteConstraintTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionDeleteConstraintTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 417
// RVA: 0x1495290
__int64 dynamic_initializer_for__DestructionThrusterTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionThrusterTrack", 0xFFFFFFFF);
  DestructionThrusterTrack::sClassNameUID = result;
  return result;
}

// File Line: 436
// RVA: 0x2DEF40
void __fastcall DestructionThrusterTrack::DestructionThrusterTrack(DestructionThrusterTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  ITrack::ITrack(this, DestructionThrusterTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionThrusterTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionThrusterTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mOffset.x = UFG::qVector3::msZero.x;
  this->mOffset.y = y;
  this->mOffset.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mForce.x = UFG::qVector3::msZero.x;
  this->mForce.y = v4;
  this->mForce.z = v5;
  this->mDecayRate = 0.0;
}

// File Line: 441
// RVA: 0x2E3E40
void __fastcall DestructionThrusterTrack::~DestructionThrusterTrack(DestructionThrusterTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionThrusterTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 458
// RVA: 0x14951D0
__int64 dynamic_initializer_for__DestructionHingeConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionHingeConstraintTrack", 0xFFFFFFFF);
  DestructionHingeConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 479
// RVA: 0x2DEB90
void __fastcall DestructionHingeConstraintTrack::DestructionHingeConstraintTrack(DestructionHingeConstraintTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  ITrack::ITrack(this, DestructionHingeConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionHingeConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionHingeConstraintTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mConstraintName = UFG::gNullQSymbol;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPivot.x = UFG::qVector3::msZero.x;
  this->mPivot.y = y;
  this->mPivot.z = z;
  v4 = UFG::qVector3::msAxisZ.y;
  v5 = UFG::qVector3::msAxisZ.z;
  this->mAxis.x = UFG::qVector3::msAxisZ.x;
  this->mAxis.y = v4;
  this->mAxis.z = v5;
  this->mLimitMin = 0.0;
  this->mLimitMax = 1.0;
}

// File Line: 484
// RVA: 0x2E3BA0
void __fastcall DestructionHingeConstraintTrack::~DestructionHingeConstraintTrack(
        DestructionHingeConstraintTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionHingeConstraintTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 502
// RVA: 0x1495270
__int64 dynamic_initializer_for__DestructionStiffSpringConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionStiffSpringConstraintTrack", 0xFFFFFFFF);
  DestructionStiffSpringConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 519
// RVA: 0x2DEEA0
void __fastcall DestructionStiffSpringConstraintTrack::DestructionStiffSpringConstraintTrack(
        DestructionStiffSpringConstraintTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  ITrack::ITrack(this, DestructionStiffSpringConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionStiffSpringConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionStiffSpringConstraintTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mConstraintName = UFG::gNullQSymbol;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPivot1.x = UFG::qVector3::msZero.x;
  this->mPivot1.y = y;
  this->mPivot1.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mPivot2.x = UFG::qVector3::msZero.x;
  this->mPivot2.y = v4;
  this->mPivot2.z = v5;
}

// File Line: 524
// RVA: 0x2E3DD0
void __fastcall DestructionStiffSpringConstraintTrack::~DestructionStiffSpringConstraintTrack(
        DestructionStiffSpringConstraintTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionStiffSpringConstraintTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 541
// RVA: 0x1495110
__int64 dynamic_initializer_for__DestructionBallAndSocketConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionBallAndSocketConstraintTrack", 0xFFFFFFFF);
  DestructionBallAndSocketConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 554
// RVA: 0x2DE910
void __fastcall DestructionBallAndSocketConstraintTrack::DestructionBallAndSocketConstraintTrack(
        DestructionBallAndSocketConstraintTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  ITrack::ITrack(this, DestructionBallAndSocketConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionBallAndSocketConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionBallAndSocketConstraintTrack::`vftable;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
  this->mConstraintName = UFG::gNullQSymbol;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPivot.x = UFG::qVector3::msZero.x;
  this->mPivot.y = y;
  this->mPivot.z = z;
}

// File Line: 559
// RVA: 0x2E3900
void __fastcall DestructionBallAndSocketConstraintTrack::~DestructionBallAndSocketConstraintTrack(
        DestructionBallAndSocketConstraintTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionBallAndSocketConstraintTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

