// File Line: 21
// RVA: 0x14E7690
__int64 dynamic_initializer_for__RumbleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RumbleTrack", 0xFFFFFFFF);
  RumbleTrack::sClassNameUID = result;
  return result;
}

// File Line: 31
// RVA: 0x3FDCD0
void __fastcall RumbleTrack::RumbleTrack(RumbleTrack *this, MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RumbleTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RumbleTrack::`vftable;
}

// File Line: 40
// RVA: 0x3FDD10
void __fastcall RumbleTrack::RumbleTrack(RumbleTrack *this)
{
  ITrack::ITrack(this, RumbleTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RumbleTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RumbleTrack::`vftable;
  *(_QWORD *)&this->m_audioTagId = 0i64;
  this->m_secondUID = 0;
}

// File Line: 144
// RVA: 0x3FD9F0
void __fastcall PlayEffectBaseTrack::PlayEffectBaseTrack(PlayEffectBaseTrack *this)
{
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4

  this->mAttachLimbName = UFG::gNullQSymbolUC;
  this->mWorldEffectMode = 0;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  x = UFG::qMatrix44::msIdentity.v0.x;
  this->mTransform.v0.y = UFG::qMatrix44::msIdentity.v0.y;
  this->mTransform.v0.z = z;
  this->mTransform.v0.x = x;
  this->mTransform.v0.w = w;
  y = UFG::qMatrix44::msIdentity.v1.y;
  v5 = UFG::qMatrix44::msIdentity.v1.z;
  v6 = UFG::qMatrix44::msIdentity.v1.w;
  this->mTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mTransform.v1.y = y;
  this->mTransform.v1.z = v5;
  this->mTransform.v1.w = v6;
  v7 = UFG::qMatrix44::msIdentity.v2.z;
  v8 = UFG::qMatrix44::msIdentity.v2.w;
  v9 = UFG::qMatrix44::msIdentity.v2.x;
  this->mTransform.v2.y = UFG::qMatrix44::msIdentity.v2.y;
  this->mTransform.v2.x = v9;
  this->mTransform.v2.z = v7;
  this->mTransform.v2.w = v8;
  v10 = UFG::qMatrix44::msIdentity.v3.y;
  v11 = UFG::qMatrix44::msIdentity.v3.z;
  v12 = UFG::qMatrix44::msIdentity.v3.w;
  this->mTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mTransform.v3.y = v10;
  this->mTransform.v3.z = v11;
  this->mTransform.v3.w = v12;
  v13 = UFG::qVector3::msZero.z;
  v14 = UFG::qVector3::msZero.x;
  this->mTranslation.y = UFG::qVector3::msZero.y;
  this->mTranslation.x = v14;
  this->mTranslation.z = v13;
  v15 = UFG::qVector3::msZero.z;
  v16 = UFG::qVector3::msZero.x;
  this->mRotation.y = UFG::qVector3::msZero.y;
  this->mRotation.x = v16;
  this->mRotation.z = v15;
  this->mEffectName = UFG::gNullQSymbolUC;
  *(_WORD *)&this->mPlayToEnd = 1;
  this->mAttachEffect = 1;
}

// File Line: 185
// RVA: 0x14E7630
__int64 dynamic_initializer_for__PlayEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayEffectTrack", 0xFFFFFFFF);
  PlayEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 205
// RVA: 0x3FDBA0
void __fastcall PlayEffectTrack::PlayEffectTrack(PlayEffectTrack *this)
{
  ITrack::ITrack(this, PlayEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<PlayEffectTask>::`vftable;
  PlayEffectBaseTrack::PlayEffectBaseTrack(&this->PlayEffectBaseTrack);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayEffectTrack::`vftable;
}

// File Line: 226
// RVA: 0x14E8860
__int64 dynamic_initializer_for__gFootStepTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gFootStepTypeEnum,
    gFootStepTypeStrings,
    gFootStepTypeStringsCount,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gFootStepTypeEnum__);
}

// File Line: 231
// RVA: 0x14E75D0
__int64 dynamic_initializer_for__FootStepLeftEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FootStepLeftEffectTrack", 0xFFFFFFFF);
  FootStepLeftEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 241
// RVA: 0x3FD8E0
void __fastcall FootStepLeftEffectTrack::FootStepLeftEffectTrack(FootStepLeftEffectTrack *this)
{
  ITrack::ITrack(this, FootStepLeftEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<FootStepLeftEffectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&FootStepLeftEffectTrack::`vftable;
  *(_QWORD *)&this->mStepSound = 0i64;
}

// File Line: 264
// RVA: 0x14E75F0
__int64 dynamic_initializer_for__FootStepRightEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FootStepRightEffectTrack", 0xFFFFFFFF);
  FootStepRightEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 274
// RVA: 0x3FD930
void __fastcall FootStepRightEffectTrack::FootStepRightEffectTrack(FootStepRightEffectTrack *this)
{
  ITrack::ITrack(this, FootStepRightEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<FootStepRightEffectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&FootStepRightEffectTrack::`vftable;
  *(_QWORD *)&this->mStepSound = 0i64;
}

// File Line: 295
// RVA: 0x14E7570
__int64 dynamic_initializer_for__CollisionEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionEffectTrack", 0xFFFFFFFF);
  CollisionEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 307
// RVA: 0x3FD7E0
void __fastcall CollisionEffectTrack::CollisionEffectTrack(CollisionEffectTrack *this)
{
  ITrack::ITrack(this, CollisionEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CollisionEffectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionEffectTrack::`vftable;
  this->m_TargetMaterial = 0;
  *(_WORD *)&this->m_AudioEffect = 257;
}

// File Line: 311
// RVA: 0x400A90
__int64 __fastcall CollisionEffectTrack::GetTargetMaterialUID(CollisionEffectTrack *this)
{
  __int64 v1; // rax

  if ( (int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v1 = 0i64;
  else
    v1 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 6);
  return UFG::qStringHashUpper32(
           *(const char **)(*(_QWORD *)(v1 + 16) + 8i64 * (unsigned int)this->m_TargetMaterial),
           -1);
}

// File Line: 331
// RVA: 0x14E75B0
__int64 dynamic_initializer_for__EffectSurfaceCollisionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("EffectSurfaceCollisionTrack", 0xFFFFFFFF);
  EffectSurfaceCollisionTrack::sClassNameUID = result;
  return result;
}

// File Line: 347
// RVA: 0x3FD880
void __fastcall EffectSurfaceCollisionTrack::EffectSurfaceCollisionTrack(EffectSurfaceCollisionTrack *this)
{
  ITrack::ITrack(this, EffectSurfaceCollisionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<EffectSurfaceCollisionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&EffectSurfaceCollisionTrack::`vftable;
  *(_QWORD *)&this->m_SourceImpactMaterial = 0i64;
  this->m_ProbeLength = 0.30000001;
  *(_WORD *)&this->m_AudioEffect = 257;
}

// File Line: 362
// RVA: 0x400A20
UFG::qSymbolUC *__fastcall EffectSurfaceCollisionTrack::GetBoneUID(
        EffectSurfaceCollisionTrack *this,
        UFG::qSymbolUC *result)
{
  __int64 v3; // rdx

  if ( (int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v3 = 0i64;
  else
    v3 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 3);
  UFG::qSymbolUC::create_from_string(result, *(const char **)(*(_QWORD *)(v3 + 16) + 8i64 * (unsigned int)this->m_Bone));
  return result;
}

// File Line: 385
// RVA: 0x14E88A0
__int64 dynamic_initializer_for__gVisualTreatmentEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gVisualTreatmentEnum, "Global/Act/VisualTreatmentEnum.xml");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gVisualTreatmentEnum__);
}

// File Line: 386
// RVA: 0x14E76D0
__int64 dynamic_initializer_for__VisualTreatmentTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VisualTreatmentTrack", 0xFFFFFFFF);
  VisualTreatmentTrack::sClassNameUID = result;
  return result;
}

// File Line: 400
// RVA: 0x3FDE60
void __fastcall VisualTreatmentTrack::VisualTreatmentTrack(VisualTreatmentTrack *this)
{
  ITrack::ITrack(this, VisualTreatmentTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VisualTreatmentTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VisualTreatmentTrack::`vftable;
  *(_QWORD *)&this->mVisualTreatment = 0i64;
  this->mMotionEffect = 1.0;
  *(_WORD *)&this->mSoundEffect = 0;
  this->mIsAdditive = 0;
  this->mFadeOut = 0.0;
}

// File Line: 417
// RVA: 0x14E7590
__int64 dynamic_initializer_for__DamageEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DamageEffectTrack", 0xFFFFFFFF);
  DamageEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 425
// RVA: 0x3FD830
void __fastcall DamageEffectTrack::DamageEffectTrack(DamageEffectTrack *this)
{
  ITrack::ITrack(this, DamageEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DamageEffectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DamageEffectTrack::`vftable;
  this->m_fDamage = 0.0;
}

// File Line: 437
// RVA: 0x14E7650
__int64 dynamic_initializer_for__RimLightTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RimLightTargetTrack", 0xFFFFFFFF);
  RimLightTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 454
// RVA: 0x14E7610
__int64 dynamic_initializer_for__LightingRimBoostTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LightingRimBoostTrack", 0xFFFFFFFF);
  LightingRimBoostTrack::sClassNameUID = result;
  return result;
}

// File Line: 462
// RVA: 0x3FD980
void __fastcall LightingRimBoostTrack::LightingRimBoostTrack(LightingRimBoostTrack *this)
{
  ITrack::ITrack(this, LightingRimBoostTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<LightingRimBoostTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&LightingRimBoostTrack::`vftable;
  this->mMultiplier = 1.0;
}

// File Line: 475
// RVA: 0x14E7670
__int64 dynamic_initializer_for__RimLightTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RimLightTrack", 0xFFFFFFFF);
  RimLightTrack::sClassNameUID = result;
  return result;
}

// File Line: 489
// RVA: 0x14E7550
__int64 dynamic_initializer_for__ApplyWetnessOrSweatTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ApplyWetnessOrSweatTrack", 0xFFFFFFFF);
  ApplyWetnessOrSweatTrack::sClassNameUID = result;
  return result;
}

// File Line: 506
// RVA: 0x14E76B0
__int64 dynamic_initializer_for__SetHighlightingModeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SetHighlightingModeTrack", 0xFFFFFFFF);
  SetHighlightingModeTrack::sClassNameUID = result;
  return result;
}

// File Line: 512
// RVA: 0x3FDD60
void __fastcall SetHighlightingModeTrack::SetHighlightingModeTrack(SetHighlightingModeTrack *this)
{
  ITrack::ITrack(this, SetHighlightingModeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SetHighlightingModeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetHighlightingModeTrack::`vftable;
  this->mHighlightingMode.mValue = 0;
}

