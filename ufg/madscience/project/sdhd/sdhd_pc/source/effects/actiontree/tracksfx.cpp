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
  RumbleTrack *v2; // rbx

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<RumbleTask>::`vftable';
  v2->vfptr = (Expression::IMemberMapVtbl *)&RumbleTrack::`vftable';
}

// File Line: 40
// RVA: 0x3FDD10
void __fastcall RumbleTrack::RumbleTrack(RumbleTrack *this)
{
  RumbleTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RumbleTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RumbleTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&RumbleTrack::`vftable';
  *(_QWORD *)&v1->m_audioTagId = 0i64;
  v1->m_secondUID = 0;
}

// File Line: 144
// RVA: 0x3FD9F0
void __fastcall PlayEffectBaseTrack::PlayEffectBaseTrack(PlayEffectBaseTrack *this)
{
  float v1; // xmm2_4
  float v2; // xmm3_4
  float v3; // xmm0_4
  float v4; // xmm1_4
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
  v1 = UFG::qMatrix44::msIdentity.v0.z;
  v2 = UFG::qMatrix44::msIdentity.v0.w;
  v3 = UFG::qMatrix44::msIdentity.v0.x;
  this->mTransform.v0.y = UFG::qMatrix44::msIdentity.v0.y;
  this->mTransform.v0.z = v1;
  this->mTransform.v0.x = v3;
  this->mTransform.v0.w = v2;
  v4 = UFG::qMatrix44::msIdentity.v1.y;
  v5 = UFG::qMatrix44::msIdentity.v1.z;
  v6 = UFG::qMatrix44::msIdentity.v1.w;
  this->mTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mTransform.v1.y = v4;
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
  PlayEffectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PlayEffectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PlayEffectTask>::`vftable';
  PlayEffectBaseTrack::PlayEffectBaseTrack((PlayEffectBaseTrack *)&v1->mAttachLimbName);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayEffectTrack::`vftable';
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
  return atexit(dynamic_atexit_destructor_for__gFootStepTypeEnum__);
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
  FootStepLeftEffectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, FootStepLeftEffectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<FootStepLeftEffectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&FootStepLeftEffectTrack::`vftable';
  *(_QWORD *)&v1->mStepSound = 0i64;
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
  FootStepRightEffectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, FootStepRightEffectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<FootStepRightEffectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&FootStepRightEffectTrack::`vftable';
  *(_QWORD *)&v1->mStepSound = 0i64;
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
  CollisionEffectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CollisionEffectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CollisionEffectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionEffectTrack::`vftable';
  v1->m_TargetMaterial = 0;
  *(_WORD *)&v1->m_AudioEffect = 257;
}

// File Line: 311
// RVA: 0x400A90
__int64 __fastcall CollisionEffectTrack::GetTargetMaterialUID(CollisionEffectTrack *this)
{
  __int64 v1; // rax

  if ( (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v1 = 0i64;
  else
    v1 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 6);
  return UFG::qStringHashUpper32(
           *(const char **)(*(_QWORD *)(v1 + 16) + 8i64 * (unsigned int)this->m_TargetMaterial),
           0xFFFFFFFF);
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
  EffectSurfaceCollisionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, EffectSurfaceCollisionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<EffectSurfaceCollisionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&EffectSurfaceCollisionTrack::`vftable';
  *(_QWORD *)&v1->m_SourceImpactMaterial = 0i64;
  v1->m_ProbeLength = 0.30000001;
  *(_WORD *)&v1->m_AudioEffect = 257;
}

// File Line: 362
// RVA: 0x400A20
UFG::qSymbolUC *__fastcall EffectSurfaceCollisionTrack::GetBoneUID(EffectSurfaceCollisionTrack *this, UFG::qSymbolUC *result)
{
  UFG::qSymbolUC *v2; // rbx
  __int64 v3; // rdx

  v2 = result;
  if ( (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v3 = 0i64;
  else
    v3 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 3);
  UFG::qSymbolUC::create_from_string(v2, *(const char **)(*(_QWORD *)(v3 + 16) + 8i64 * (unsigned int)this->m_Bone));
  return v2;
}

// File Line: 385
// RVA: 0x14E88A0
__int64 dynamic_initializer_for__gVisualTreatmentEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gVisualTreatmentEnum, "Global/Act/VisualTreatmentEnum.xml");
  return atexit(dynamic_atexit_destructor_for__gVisualTreatmentEnum__);
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
  VisualTreatmentTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, VisualTreatmentTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<VisualTreatmentTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&VisualTreatmentTrack::`vftable';
  *(_QWORD *)&v1->mVisualTreatment = 0i64;
  v1->mMotionEffect = 1.0;
  *(_WORD *)&v1->mSoundEffect = 0;
  v1->mIsAdditive = 0;
  v1->mFadeOut = 0.0;
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
  DamageEffectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DamageEffectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DamageEffectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DamageEffectTrack::`vftable';
  v1->m_fDamage = 0.0;
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
  LightingRimBoostTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, LightingRimBoostTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<LightingRimBoostTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&LightingRimBoostTrack::`vftable';
  v1->mMultiplier = 1.0;
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
  SetHighlightingModeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SetHighlightingModeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SetHighlightingModeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&SetHighlightingModeTrack::`vftable';
  v1->mHighlightingMode.mValue = 0;
}

