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
  DestructionSetDefinitionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionSetDefinitionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSetDefinitionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDefinitionTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  *(_QWORD *)&v1->mBulletDamageMultiplier = 0i64;
  *(_QWORD *)&v1->mImpactDamageMultiplier = 0i64;
  v1->mAttackDamageMultiplier = 0.0;
}

// File Line: 45
// RVA: 0x2E3C80
void __fastcall DestructionSetDefinitionTrack::~DestructionSetDefinitionTrack(DestructionSetDefinitionTrack *this)
{
  DestructionSetDefinitionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDefinitionTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DestructionEventTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionEventTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionEventTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionEventTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mSoundEffect = UFG::gNullQSymbolUC;
  *(_DWORD *)&v1->mFractureObject = 0;
  *(_QWORD *)&v1->mDisableCover = 0i64;
  v1->mRenderModelSwap = UFG::gNullQSymbolUC;
  v1->mVisualTreatment = UFG::gNullQSymbol;
  v1->mDisableSelfIllumination = 0;
  v1->mLifeSpan = -1.0;
}

// File Line: 110
// RVA: 0x2E3AC0
void __fastcall DestructionEventTrack::~DestructionEventTrack(DestructionEventTrack *this)
{
  DestructionEventTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEventTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DestructionEnableRiggedGeoTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionEnableRiggedGeoTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionEnableRiggedGeoTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableRiggedGeoTrack::`vftable';
  v1->mBoneName = UFG::gNullQSymbolUC;
  *(_WORD *)&v1->mEnable = 0;
}

// File Line: 157
// RVA: 0x2E3A50
void __fastcall DestructionEnableRiggedGeoTrack::~DestructionEnableRiggedGeoTrack(DestructionEnableRiggedGeoTrack *this)
{
  DestructionEnableRiggedGeoTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableRiggedGeoTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
void __fastcall DestructionSpawnPropertySetTrack::DestructionSpawnPropertySetTrack(DestructionSpawnPropertySetTrack *this)
{
  DestructionSpawnPropertySetTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionSpawnPropertySetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSpawnPropertySetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPropertySetTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mPropertySetName = UFG::gNullQSymbol;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mTranslateOffset.x = UFG::qVector3::msZero.x;
  v1->mTranslateOffset.y = v2;
  v1->mTranslateOffset.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mRotateOffset.x = UFG::qVector3::msZero.x;
  v1->mRotateOffset.y = v4;
  v1->mRotateOffset.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v1->mLinearImpulseRotation.x = UFG::qVector3::msZero.x;
  v1->mLinearImpulseRotation.y = v6;
  v1->mLinearImpulseRotation.z = v7;
  v1->mLinearImpulseMagnitude = 1.0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v1->mAngularImpulse.x = UFG::qVector3::msZero.x;
  v1->mAngularImpulse.y = v8;
  v1->mAngularImpulse.z = v9;
}

// File Line: 204
// RVA: 0x2E3D60
void __fastcall DestructionSpawnPropertySetTrack::~DestructionSpawnPropertySetTrack(DestructionSpawnPropertySetTrack *this)
{
  DestructionSpawnPropertySetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPropertySetTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
void __fastcall DestructionSpawnPhantomVolumeTrack::DestructionSpawnPhantomVolumeTrack(DestructionSpawnPhantomVolumeTrack *this)
{
  DestructionSpawnPhantomVolumeTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionSpawnPhantomVolumeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSpawnPhantomVolumeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPhantomVolumeTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mPhantomName = UFG::gNullQSymbolUC;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mTranslateOffset.x = UFG::qVector3::msZero.x;
  v1->mTranslateOffset.y = v2;
  v1->mTranslateOffset.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mBoxExtents.x = UFG::qVector3::msZero.x;
  v1->mBoxExtents.y = v4;
  v1->mBoxExtents.z = v5;
  v1->mPhantomTimer = -1.0;
}

// File Line: 247
// RVA: 0x2E3CF0
void __fastcall DestructionSpawnPhantomVolumeTrack::~DestructionSpawnPhantomVolumeTrack(DestructionSpawnPhantomVolumeTrack *this)
{
  DestructionSpawnPhantomVolumeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSpawnPhantomVolumeTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DestructionExplosionTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionExplosionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionExplosionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionExplosionTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mExplosionType = UFG::gNullQSymbol;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mPosition.x = UFG::qVector3::msZero.x;
  v1->mPosition.y = v2;
  v1->mPosition.z = v3;
}

// File Line: 282
// RVA: 0x2E3B30
void __fastcall DestructionExplosionTrack::~DestructionExplosionTrack(DestructionExplosionTrack *this)
{
  DestructionExplosionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionExplosionTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
void __fastcall DestructionEnableFractureElementTrack::DestructionEnableFractureElementTrack(DestructionEnableFractureElementTrack *this)
{
  DestructionEnableFractureElementTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionEnableFractureElementTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionEnableFractureElementTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableFractureElementTrack::`vftable';
  v1->mFractureElement1 = UFG::gNullQSymbolUC;
  v1->mEnable1 = 0;
}

// File Line: 331
// RVA: 0x2E39E0
void __fastcall DestructionEnableFractureElementTrack::~DestructionEnableFractureElementTrack(DestructionEnableFractureElementTrack *this)
{
  DestructionEnableFractureElementTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionEnableFractureElementTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DestructionSetDamageTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionSetDamageTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionSetDamageTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDamageTrack::`vftable';
  *(_QWORD *)&v1->mDestructionObjectName.mUID = UFG::gNullQSymbolUC.mUID;
}

// File Line: 370
// RVA: 0x2E3C10
void __fastcall DestructionSetDamageTrack::~DestructionSetDamageTrack(DestructionSetDamageTrack *this)
{
  DestructionSetDamageTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionSetDamageTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
void __fastcall DestructionDeleteConstraintTrack::DestructionDeleteConstraintTrack(DestructionDeleteConstraintTrack *this)
{
  DestructionDeleteConstraintTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionDeleteConstraintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionDeleteConstraintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionDeleteConstraintTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mDeleteConstraintName = UFG::gNullQSymbol;
  v1->mDeleteConstraints = 0;
}

// File Line: 401
// RVA: 0x2E3970
void __fastcall DestructionDeleteConstraintTrack::~DestructionDeleteConstraintTrack(DestructionDeleteConstraintTrack *this)
{
  DestructionDeleteConstraintTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionDeleteConstraintTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DestructionThrusterTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionThrusterTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionThrusterTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionThrusterTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mOffset.x = UFG::qVector3::msZero.x;
  v1->mOffset.y = v2;
  v1->mOffset.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mForce.x = UFG::qVector3::msZero.x;
  v1->mForce.y = v4;
  v1->mForce.z = v5;
  v1->mDecayRate = 0.0;
}

// File Line: 441
// RVA: 0x2E3E40
void __fastcall DestructionThrusterTrack::~DestructionThrusterTrack(DestructionThrusterTrack *this)
{
  DestructionThrusterTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionThrusterTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DestructionHingeConstraintTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionHingeConstraintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionHingeConstraintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionHingeConstraintTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mConstraintName = UFG::gNullQSymbol;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mPivot.x = UFG::qVector3::msZero.x;
  v1->mPivot.y = v2;
  v1->mPivot.z = v3;
  v4 = UFG::qVector3::msAxisZ.y;
  v5 = UFG::qVector3::msAxisZ.z;
  v1->mAxis.x = UFG::qVector3::msAxisZ.x;
  v1->mAxis.y = v4;
  v1->mAxis.z = v5;
  v1->mLimitMin = 0.0;
  v1->mLimitMax = 1.0;
}

// File Line: 484
// RVA: 0x2E3BA0
void __fastcall DestructionHingeConstraintTrack::~DestructionHingeConstraintTrack(DestructionHingeConstraintTrack *this)
{
  DestructionHingeConstraintTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionHingeConstraintTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
void __fastcall DestructionStiffSpringConstraintTrack::DestructionStiffSpringConstraintTrack(DestructionStiffSpringConstraintTrack *this)
{
  DestructionStiffSpringConstraintTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionStiffSpringConstraintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionStiffSpringConstraintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionStiffSpringConstraintTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mConstraintName = UFG::gNullQSymbol;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mPivot1.x = UFG::qVector3::msZero.x;
  v1->mPivot1.y = v2;
  v1->mPivot1.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mPivot2.x = UFG::qVector3::msZero.x;
  v1->mPivot2.y = v4;
  v1->mPivot2.z = v5;
}

// File Line: 524
// RVA: 0x2E3DD0
void __fastcall DestructionStiffSpringConstraintTrack::~DestructionStiffSpringConstraintTrack(DestructionStiffSpringConstraintTrack *this)
{
  DestructionStiffSpringConstraintTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionStiffSpringConstraintTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
void __fastcall DestructionBallAndSocketConstraintTrack::DestructionBallAndSocketConstraintTrack(DestructionBallAndSocketConstraintTrack *this)
{
  DestructionBallAndSocketConstraintTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DestructionBallAndSocketConstraintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DestructionBallAndSocketConstraintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionBallAndSocketConstraintTrack::`vftable';
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
  v1->mConstraintName = UFG::gNullQSymbol;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mPivot.x = UFG::qVector3::msZero.x;
  v1->mPivot.y = v2;
  v1->mPivot.z = v3;
}

// File Line: 559
// RVA: 0x2E3900
void __fastcall DestructionBallAndSocketConstraintTrack::~DestructionBallAndSocketConstraintTrack(DestructionBallAndSocketConstraintTrack *this)
{
  DestructionBallAndSocketConstraintTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionBallAndSocketConstraintTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

