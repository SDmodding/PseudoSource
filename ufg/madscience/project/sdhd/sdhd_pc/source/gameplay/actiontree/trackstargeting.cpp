// File Line: 56
// RVA: 0x1496450
__int64 dynamic_initializer_for__TargetJumpTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetJumpTrack", 0xFFFFFFFF);
  TargetJumpTrack::sClassNameUID = result;
  return result;
}

// File Line: 80
// RVA: 0x1496530
__int64 dynamic_initializer_for__TargetPlayEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPlayEffectTrack", 0xFFFFFFFF);
  TargetPlayEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 102
// RVA: 0x2E1DA0
void __fastcall TargetPlayEffectTrack::TargetPlayEffectTrack(TargetPlayEffectTrack *this)
{
  ITrack::ITrack(this, TargetPlayEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayEffectTask>::`vftable;
  PlayEffectBaseTrack::PlayEffectBaseTrack(&this->PlayEffectBaseTrack);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayEffectTrack::`vftable;
  this->m_eTargetType.mValue = 22;
}

// File Line: 118
// RVA: 0x14962D0
__int64 dynamic_initializer_for__TargetDamageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDamageTrack", 0xFFFFFFFF);
  TargetDamageTrack::sClassNameUID = result;
  return result;
}

// File Line: 141
// RVA: 0x1496570
__int64 dynamic_initializer_for__TargetPlayTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPlayTrack", 0xFFFFFFFF);
  TargetPlayTrack::sClassNameUID = result;
  return result;
}

// File Line: 159
// RVA: 0x2FD770
TargetPlayTrack *__fastcall TargetPlayTrack::CreateClone(TargetPlayTrack *this)
{
  char *v2; // rax
  TargetPlayTrack *v3; // rax
  TargetPlayTrack *v4; // rdi
  UFG::qOffset64<ActionNodeReference *> *p_mActionNodeReference; // rbx
  __int64 mOffset; // rax
  __int64 v7; // rax
  char *v8; // rcx
  __int64 v9; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x88ui64, "TargetPlayTrack::CreateClone", 0i64, 1u);
  if ( v2 )
  {
    TargetPlayTrack::TargetPlayTrack((TargetPlayTrack *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  p_mActionNodeReference = &v4->mActionNodeReference;
  mOffset = v4->mActionNodeReference.mOffset;
  if ( mOffset && (UFG::qOffset64<ActionNodeReference *> *)((char *)p_mActionNodeReference + mOffset) )
    (*(void (__fastcall **)(char *, __int64))(*(__int64 *)((char *)&p_mActionNodeReference->mOffset + mOffset) + 8))(
      (char *)p_mActionNodeReference + mOffset,
      1i64);
  TargetPlayTrack::operator=(v4, this);
  v7 = this->mActionNodeReference.mOffset;
  if ( v7 )
    v8 = (char *)&this->mActionNodeReference + v7;
  else
    v8 = 0i64;
  v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 16i64))(v8);
  if ( v9 )
    p_mActionNodeReference->mOffset = v9 - (_QWORD)p_mActionNodeReference;
  else
    p_mActionNodeReference->mOffset = 0i64;
  return v4;
}

// File Line: 255
// RVA: 0x1496510
__int64 dynamic_initializer_for__TargetPlayAITrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPlayAITrack", 0xFFFFFFFF);
  TargetPlayAITrack::sClassNameUID = result;
  return result;
}

// File Line: 266
// RVA: 0x2FD670
Expression::IMemberMap *__fastcall TargetPlayAITrack::CreateClone(TargetPlayAITrack *this)
{
  char *v2; // rax
  char *v3; // rbx
  char *v4; // rdi
  __int64 v5; // rax
  __int64 mOffset; // rax
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  char *v10; // rcx
  __int64 v11; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "TargetPlayAITrack::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefTrack<TargetPlayAITask>::NodeRefTrack<TargetPlayAITask>(
      (NodeRefTrack<TargetPlayAITask> *)v2,
      TargetPlayAITrack::sClassNameUID);
    *(_QWORD *)v3 = &TargetPlayAITrack::`vftable;
    *((_DWORD *)v3 + 16) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v3 + 56;
  v5 = *((_QWORD *)v3 + 7);
  if ( v5 && &v4[v5] )
    (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)&v4[v5] + 8i64))(&v4[v5], 1i64);
  ITrack::operator=((ITrack *)v3, this);
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset && (v7 = (char *)&this->mActionNodeReference + mOffset) != 0i64 )
    v8 = v7 - v4;
  else
    v8 = 0i64;
  *(_QWORD *)v4 = v8;
  *((_DWORD *)v3 + 16) = this->mTargetType;
  v9 = this->mActionNodeReference.mOffset;
  if ( v9 )
    v10 = (char *)&this->mActionNodeReference + v9;
  else
    v10 = 0i64;
  v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 16i64))(v10);
  if ( v11 )
    *(_QWORD *)v4 = v11 - (_QWORD)v4;
  else
    *(_QWORD *)v4 = 0i64;
  return (Expression::IMemberMap *)v3;
}

// File Line: 347
// RVA: 0x1496610
__int64 dynamic_initializer_for__TargetSpawnTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSpawnTrack", 0xFFFFFFFF);
  TargetSpawnTrack::sClassNameUID = result;
  return result;
}

// File Line: 361
// RVA: 0x2E1E90
void __fastcall TargetSpawnTrack::TargetSpawnTrack(TargetSpawnTrack *this)
{
  ITrack::ITrack(this, TargetSpawnTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSpawnTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSpawnTrack::`vftable;
  this->m_eTargetType.mValue = 0;
  SpawnTrack::SpawnTrack(&this->m_SpawnTrack);
}

// File Line: 365
// RVA: 0x303610
void __fastcall TargetSpawnTrack::ResolveReferences(TargetSpawnTrack *this, ActionNode *parent)
{
  _((AMD_HD3D *)this);
  this->m_SpawnTrack.vfptr[1].__vecDelDtor(&this->m_SpawnTrack, (unsigned int)parent);
}

// File Line: 382
// RVA: 0x1496550
__int64 dynamic_initializer_for__TargetPlayHoldTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPlayHoldTrack", 0xFFFFFFFF);
  TargetPlayHoldTrack::sClassNameUID = result;
  return result;
}

// File Line: 392
// RVA: 0x14963F0
__int64 dynamic_initializer_for__TargetGrappleReleaseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetGrappleReleaseTrack", 0xFFFFFFFF);
  TargetGrappleReleaseTrack::sClassNameUID = result;
  return result;
}

// File Line: 404
// RVA: 0x1496490
__int64 dynamic_initializer_for__TargetLockTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetLockTrack", 0xFFFFFFFF);
  TargetLockTrack::sClassNameUID = result;
  return result;
}

// File Line: 421
// RVA: 0x14965D0
__int64 dynamic_initializer_for__TargetReleaseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetReleaseTrack", 0xFFFFFFFF);
  TargetReleaseTrack::sClassNameUID = result;
  return result;
}

// File Line: 441
// RVA: 0x1496650
__int64 dynamic_initializer_for__TargetSteerToTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSteerToTrack", 0xFFFFFFFF);
  TargetSteerToTrack::sClassNameUID = result;
  return result;
}

// File Line: 474
// RVA: 0x1496670
__int64 dynamic_initializer_for__TargetSyncPositionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSyncPositionTrack", 0xFFFFFFFF);
  TargetSyncPositionTrack::sClassNameUID = result;
  return result;
}

// File Line: 494
// RVA: 0x2E1FC0
void __fastcall TargetSyncPositionTrack::TargetSyncPositionTrack(TargetSyncPositionTrack *this)
{
  ITrack::ITrack(this, TargetSyncPositionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSyncPositionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSyncPositionTrack::`vftable;
  *(_QWORD *)&this->mSyncTime = 0i64;
  *(_QWORD *)&this->mAttachment.mUID = -1i64;
  *(_WORD *)&this->mSyncToTarget = 0;
  this->mPositionXYOnly = 0;
}

// File Line: 515
// RVA: 0x1496290
__int64 dynamic_initializer_for__TargetAttachTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAttachTrack", 0xFFFFFFFF);
  TargetAttachTrack::sClassNameUID = result;
  return result;
}

// File Line: 542
// RVA: 0x2E16A0
void __fastcall TargetAttachTrack::TargetAttachTrack(TargetAttachTrack *this)
{
  ITrack::ITrack(this, TargetAttachTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachTrack::`vftable;
  this->mTargetType = 0;
  *(_QWORD *)&this->mAssignmentTargetType = eTARGET_TYPE_EQUIPPED;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  *(_WORD *)&this->mAttachToTarget = 0;
  this->mAttachRelativeMaxDistance = -1.0;
  *(_WORD *)&this->mAssignTargetType = 256;
  this->mAddToInventory = 1;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 569
// RVA: 0x1496250
__int64 dynamic_initializer_for__TargetAttachEXTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAttachEXTrack", 0xFFFFFFFF);
  TargetAttachEXTrack::sClassNameUID = result;
  return result;
}

// File Line: 600
// RVA: 0x2E1580
void __fastcall TargetAttachEXTrack::TargetAttachEXTrack(TargetAttachEXTrack *this)
{
  ITrack::ITrack(this, TargetAttachEXTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachEXTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachEXTrack::`vftable;
  *(_QWORD *)&this->mRootTargetType = 1i64;
  *(_QWORD *)&this->mAssignmentTargetType = 17i64;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  *(_WORD *)&this->mAttachToTarget = 0;
  this->mAttachRelativeMaxDistance = -1.0;
  *(_WORD *)&this->mAssignTargetType = 256;
  this->mAddToInventory = 1;
  this->mPositionOnly = 0;
  this->mTimeEnd = 0.0;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 633
// RVA: 0x1496630
__int64 dynamic_initializer_for__TargetStealAttachedItemTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetStealAttachedItemTrack", 0xFFFFFFFF);
  TargetStealAttachedItemTrack::sClassNameUID = result;
  return result;
}

// File Line: 665
// RVA: 0x2E1EE0
void __fastcall TargetStealAttachedItemTrack::TargetStealAttachedItemTrack(TargetStealAttachedItemTrack *this)
{
  ITrack::ITrack(this, TargetStealAttachedItemTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetStealAttachedItemTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetStealAttachedItemTrack::`vftable;
  this->mTargetToStealFromType = 23;
  *(_QWORD *)&this->mStolenItemAssignmentTargetType = 17i64;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  this->mStolenItemJointName.mUID = -1;
  *(_DWORD *)&this->mAddToInventory = 16842753;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mVictimDetachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mStolenItemJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 690
// RVA: 0x1496370
__int64 dynamic_initializer_for__TargetDetachTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDetachTrack", 0xFFFFFFFF);
  TargetDetachTrack::sClassNameUID = result;
  return result;
}

// File Line: 718
// RVA: 0x2E1940
void __fastcall TargetDetachTrack::TargetDetachTrack(TargetDetachTrack *this)
{
  ITrack::ITrack(this, TargetDetachTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachTrack::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
  this->mClampVelocity = -1.0;
  this->mDisableCollisionDelay = 0.0;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  *(_DWORD *)&this->mDettachFromTarget = 16842752;
  *(_WORD *)&this->mMakeUpright = 1;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 744
// RVA: 0x1496330
__int64 dynamic_initializer_for__TargetDetachEXTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDetachEXTrack", 0xFFFFFFFF);
  TargetDetachEXTrack::sClassNameUID = result;
  return result;
}

// File Line: 774
// RVA: 0x2E1840
void __fastcall TargetDetachEXTrack::TargetDetachEXTrack(TargetDetachEXTrack *this)
{
  ITrack::ITrack(this, TargetDetachEXTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachEXTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachEXTrack::`vftable;
  *(_QWORD *)&this->mRootTargetType = 1i64;
  this->mBlendOutTime = 0.0;
  this->mClampVelocity = -1.0;
  this->mDisableCollisionDelay = 0.0;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  *(_DWORD *)&this->mDettachFromTarget = 16842752;
  *(_WORD *)&this->mMakeUpright = 1;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 801
// RVA: 0x1496270
__int64 dynamic_initializer_for__TargetAttachEffectorTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAttachEffectorTrack", 0xFFFFFFFF);
  TargetAttachEffectorTrack::sClassNameUID = result;
  return result;
}

// File Line: 816
// RVA: 0x2E1610
void __fastcall TargetAttachEffectorTrack::TargetAttachEffectorTrack(TargetAttachEffectorTrack *this)
{
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h] BYREF

  ITrack::ITrack(this, TargetAttachEffectorTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachEffectorTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachEffectorTrack::`vftable;
  this->mTargetType = 0;
  this->mPostPhysicsUpdateOnly = 0;
  this->mBlendInTime = 0.0;
  *(_QWORD *)&this->mAttachEffectorName.mUID = -1i64;
  this->mTargetAttachAdjustJointName.mUID = -1;
  this->mAttachEffectorName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "LeftArmIK")->mUID;
  this->mTargetAttachBaseJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachAdjustJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 838
// RVA: 0x1496350
__int64 dynamic_initializer_for__TargetDetachEffectorTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDetachEffectorTrack", 0xFFFFFFFF);
  TargetDetachEffectorTrack::sClassNameUID = result;
  return result;
}

// File Line: 851
// RVA: 0x2E18C0
void __fastcall TargetDetachEffectorTrack::TargetDetachEffectorTrack(TargetDetachEffectorTrack *this)
{
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h] BYREF

  ITrack::ITrack(this, TargetDetachEffectorTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachEffectorTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachEffectorTrack::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
  *(_QWORD *)&this->mAttachEffectorName.mUID = -1i64;
  this->mTargetAttachAdjustJointName.mUID = -1;
  this->mAttachEffectorName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "LeftArmIK")->mUID;
  this->mTargetAttachBaseJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachAdjustJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 874
// RVA: 0x1496590
__int64 dynamic_initializer_for__TargetPropInteractTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropInteractTrack", 0xFFFFFFFF);
  TargetPropInteractTrack::sClassNameUID = result;
  return result;
}

// File Line: 894
// RVA: 0x2E14B0
void __fastcall TargetAssignTrack::TargetAssignTrack(TargetAssignTrack *this)
{
  ITrack::ITrack(this, TargetAssignTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignTrack::`vftable;
  *(_QWORD *)&this->m_eAssignFrom.mValue = 0i64;
  *(_WORD *)&this->m_bContinuous = 0;
}

// File Line: 897
// RVA: 0x1496210
__int64 dynamic_initializer_for__TargetAssignTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAssignTrack", 0xFFFFFFFF);
  TargetAssignTrack::sClassNameUID = result;
  return result;
}

// File Line: 925
// RVA: 0x2E1460
void __fastcall TargetAssignTargetsTargetToMyTargetTrack::TargetAssignTargetsTargetToMyTargetTrack(
        TargetAssignTargetsTargetToMyTargetTrack *this)
{
  ITrack::ITrack(this, TargetAssignTargetsTargetToMyTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignTargetsTargetToMyTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignTargetsTargetToMyTargetTrack::`vftable;
  *(_QWORD *)&this->m_eTargetType.mValue = 0i64;
  this->m_eMyTargetType.mValue = 0;
  this->m_bContinuous = 0;
}

// File Line: 928
// RVA: 0x14961F0
__int64 dynamic_initializer_for__TargetAssignTargetsTargetToMyTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAssignTargetsTargetToMyTargetTrack", 0xFFFFFFFF);
  TargetAssignTargetsTargetToMyTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 956
// RVA: 0x2E13A0
void __fastcall TargetAssignMyTargetToTargetsTargetTrack::TargetAssignMyTargetToTargetsTargetTrack(
        TargetAssignMyTargetToTargetsTargetTrack *this)
{
  ITrack::ITrack(this, TargetAssignMyTargetToTargetsTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignMyTargetToTargetsTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignMyTargetToTargetsTargetTrack::`vftable;
  *(_QWORD *)&this->m_eMyTargetType.mValue = 0i64;
  this->m_eTargetsTargetType.mValue = 0;
  this->m_bContinuous = 0;
}

// File Line: 959
// RVA: 0x14961B0
__int64 dynamic_initializer_for__TargetAssignMyTargetToTargetsTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAssignMyTargetToTargetsTargetTrack", 0xFFFFFFFF);
  TargetAssignMyTargetToTargetsTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 981
// RVA: 0x14962F0
__int64 dynamic_initializer_for__TargetDestroyTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDestroyTrack", 0xFFFFFFFF);
  TargetDestroyTrack::sClassNameUID = result;
  return result;
}

// File Line: 995
// RVA: 0x14966B0
__int64 dynamic_initializer_for__TargetWeaponAmmoConsumeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetWeaponAmmoConsumeTrack", 0xFFFFFFFF);
  TargetWeaponAmmoConsumeTrack::sClassNameUID = result;
  return result;
}

// File Line: 1015
// RVA: 0x1496190
__int64 dynamic_initializer_for__TargetAddToInventoryTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAddToInventoryTrack", 0xFFFFFFFF);
  TargetAddToInventoryTrack::sClassNameUID = result;
  return result;
}

// File Line: 1029
// RVA: 0x14965F0
__int64 dynamic_initializer_for__TargetRemoveFromInventoryTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetRemoveFromInventoryTrack", 0xFFFFFFFF);
  TargetRemoveFromInventoryTrack::sClassNameUID = result;
  return result;
}

// File Line: 1043
// RVA: 0x14965B0
__int64 dynamic_initializer_for__TargetPurchaseItemTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPurchaseItemTrack", 0xFFFFFFFF);
  TargetPurchaseItemTrack::sClassNameUID = result;
  return result;
}

// File Line: 1057
// RVA: 0x1496690
__int64 dynamic_initializer_for__TargetVehicleBreakWindowTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVehicleBreakWindowTrack", 0xFFFFFFFF);
  TargetVehicleBreakWindowTrack::sClassNameUID = result;
  return result;
}

// File Line: 1067
// RVA: 0x2E2020
void __fastcall TargetVehicleBreakWindowTrack::TargetVehicleBreakWindowTrack(TargetVehicleBreakWindowTrack *this)
{
  ITrack::ITrack(this, TargetVehicleBreakWindowTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetVehicleBreakWindowTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVehicleBreakWindowTrack::`vftable;
  this->m_eTargetType.mValue = 28;
  this->m_eWindowType.mValue = 3;
}

// File Line: 1081
// RVA: 0x1496390
__int64 dynamic_initializer_for__TargetFocusOverrideTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetFocusOverrideTrack", 0xFFFFFFFF);
  TargetFocusOverrideTrack::sClassNameUID = result;
  return result;
}

// File Line: 1090
// RVA: 0x2E19C0
void __fastcall TargetFocusOverrideTrack::TargetFocusOverrideTrack(TargetFocusOverrideTrack *this)
{
  ITrack::ITrack(this, TargetFocusOverrideTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetFocusOverrideTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFocusOverrideTrack::`vftable;
  this->m_eTargetType.mValue = 23;
}

// File Line: 1103
// RVA: 0x1496430
__int64 dynamic_initializer_for__TargetHitReactionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetHitReactionTrack", 0xFFFFFFFF);
  TargetHitReactionTrack::sClassNameUID = result;
  return result;
}

// File Line: 1111
// RVA: 0x2E1B50
void __fastcall TargetHitReactionTrack::TargetHitReactionTrack(TargetHitReactionTrack *this)
{
  ITrack::ITrack(this, TargetHitReactionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetHitReactionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetHitReactionTrack::`vftable;
  this->m_eTargetType.mValue = 23;
}

// File Line: 1123
// RVA: 0x1496230
__int64 dynamic_initializer_for__TargetAttachConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAttachConstraintTrack", 0xFFFFFFFF);
  TargetAttachConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 1145
// RVA: 0x2E1500
void __fastcall TargetAttachConstraintTrack::TargetAttachConstraintTrack(TargetAttachConstraintTrack *this)
{
  ITrack::ITrack(this, TargetAttachConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachConstraintTrack::`vftable;
  this->mTargetType = 0;
  this->mAssignmentTargetType = 17;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  *(_WORD *)&this->mAttachToTarget = 0;
  this->mAttachRelativeMaxDistance = -1.0;
  *(_WORD *)&this->mAssignTargetType = 256;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 1168
// RVA: 0x1496310
__int64 dynamic_initializer_for__TargetDetachConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDetachConstraintTrack", 0xFFFFFFFF);
  TargetDetachConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 1180
// RVA: 0x2E17D0
void __fastcall TargetDetachConstraintTrack::TargetDetachConstraintTrack(TargetDetachConstraintTrack *this)
{
  ITrack::ITrack(this, TargetDetachConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachConstraintTrack::`vftable;
  this->mTargetType = 0;
  *(_QWORD *)&this->mDetachJointName.mUID = -1i64;
  this->mDetachFromTarget = 0;
  this->mDetachJointName.mUID = gStaticSymbolUC_none.mUID;
  this->mTargetDetachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 1202
// RVA: 0x1496470
__int64 dynamic_initializer_for__TargetLatchParkourHandleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetLatchParkourHandleTrack", 0xFFFFFFFF);
  TargetLatchParkourHandleTrack::sClassNameUID = result;
  return result;
}

// File Line: 1210
// RVA: 0x2E1BA0
void __fastcall TargetLatchParkourHandleTrack::TargetLatchParkourHandleTrack(TargetLatchParkourHandleTrack *this)
{
  ITrack::ITrack(this, TargetLatchParkourHandleTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetLatchParkourHandleTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetLatchParkourHandleTrack::`vftable;
  this->mTargetType = 0;
}

// File Line: 1224
// RVA: 0x14962B0
__int64 dynamic_initializer_for__TargetAttackRightsTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAttackRightsTrack", 0xFFFFFFFF);
  TargetAttackRightsTrack::sClassNameUID = result;
  return result;
}

// File Line: 1235
// RVA: 0x2E1780
void __fastcall TargetAttackRightsTrack::TargetAttackRightsTrack(TargetAttackRightsTrack *this)
{
  ITrack::ITrack(this, TargetAttackRightsTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttackRightsTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttackRightsTrack::`vftable;
  this->mTargetType = 0;
  *(_WORD *)&this->mAttackingEnabled = 256;
}

// File Line: 1240
// RVA: 0x2E5640
void __fastcall TargetAttackRightsTrack::~TargetAttackRightsTrack(TargetAttackRightsTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttackRightsTrack::`vftable;
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

// File Line: 1257
// RVA: 0x1496410
__int64 dynamic_initializer_for__TargetGunSetAmmoForAIDeathTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetGunSetAmmoForAIDeathTrack", 0xFFFFFFFF);
  TargetGunSetAmmoForAIDeathTrack::sClassNameUID = result;
  return result;
}

// File Line: 1265
// RVA: 0x2E1B00
void __fastcall TargetGunSetAmmoForAIDeathTrack::TargetGunSetAmmoForAIDeathTrack(TargetGunSetAmmoForAIDeathTrack *this)
{
  ITrack::ITrack(this, TargetGunSetAmmoForAIDeathTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetGunSetAmmoForAIDeathTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetGunSetAmmoForAIDeathTrack::`vftable;
  this->m_eTargetType.mValue = 17;
}

// File Line: 1281
// RVA: 0x2E1BF0
void __fastcall TargetPhysicalAttackTrack::TargetPhysicalAttackTrack(TargetPhysicalAttackTrack *this)
{
  ITrack::ITrack(this, TargetPhysicalAttackTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPhysicalAttackTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalAttackTrack::`vftable;
  this->m_eTargetType.mValue = 17;
  this->m_fAttackSpeed = -1.0;
}

// File Line: 1284
// RVA: 0x14964B0
__int64 dynamic_initializer_for__TargetPhysicalAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalAttackTrack", 0xFFFFFFFF);
  TargetPhysicalAttackTrack::sClassNameUID = result;
  return result;
}

// File Line: 1309
// RVA: 0x2E1CA0
void __fastcall TargetPhysicalImpulseTrack::TargetPhysicalImpulseTrack(TargetPhysicalImpulseTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  ITrack::ITrack(this, TargetPhysicalImpulseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPhysicalImpulseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalImpulseTrack::`vftable;
  this->m_eTargetType.mValue = 49;
  this->m_fMagnitude = 10.0;
  this->m_fPitch = 0.78539819;
  this->m_eDirectionType.mValue = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vDirection.x = UFG::qVector3::msZero.x;
  this->m_vDirection.y = y;
  this->m_vDirection.z = z;
}

// File Line: 1319
// RVA: 0x149C570
__int64 dynamic_initializer_for__gDirectionTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gDirectionTypeEnum, gDirectionTypeStringList, 3, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDirectionTypeEnum__);
}

// File Line: 1321
// RVA: 0x14964F0
__int64 dynamic_initializer_for__TargetPhysicalImpulseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalImpulseTrack", 0xFFFFFFFF);
  TargetPhysicalImpulseTrack::sClassNameUID = result;
  return result;
}

// File Line: 1352
// RVA: 0x2E1C40
void __fastcall TargetPhysicalDamageTrack::TargetPhysicalDamageTrack(TargetPhysicalDamageTrack *this)
{
  ITrack::ITrack(this, TargetPhysicalDamageTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPhysicalDamageTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalDamageTrack::`vftable;
  this->m_eTargetType.mValue = 49;
  this->m_iDamageType = 0;
  this->m_fDamage = 1.0;
}

// File Line: 1355
// RVA: 0x14964D0
__int64 dynamic_initializer_for__TargetPhysicalDamageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalDamageTrack", 0xFFFFFFFF);
  TargetPhysicalDamageTrack::sClassNameUID = result;
  return result;
}

// File Line: 1374
// RVA: 0x149CA00
__int64 dynamic_initializer_for__gTargetingProfileEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gTargetingProfileEnum, "Global/Act/TargetingProfileEnum.xml");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTargetingProfileEnum__);
}

// File Line: 1375
// RVA: 0x14966F0
__int64 dynamic_initializer_for__TargetingProfileSelectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetingProfileSelectTrack", 0xFFFFFFFF);
  TargetingProfileSelectTrack::sClassNameUID = result;
  return result;
}

// File Line: 1380
// RVA: 0x303640
void __fastcall TargetingProfileSelectTrack::ResolveReferences(TargetingProfileSelectTrack *this, ActionNode *parent)
{
  const char *v2; // rdx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  if ( (gTargetingProfileEnum.m_enumLists.size & 0x80000000) != 0 )
    v2 = 0i64;
  else
    v2 = (*gTargetingProfileEnum.m_enumLists.p)->m_enumName.p[this->m_iTargetingProfile];
  this->m_TargetingProfileSymbol = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, v2)->mUID;
}

// File Line: 1390
// RVA: 0x2E20C0
void __fastcall TargetingProfileSelectTrack::TargetingProfileSelectTrack(TargetingProfileSelectTrack *this)
{
  ITrack::ITrack(this, TargetingProfileSelectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetingProfileSelectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetingProfileSelectTrack::`vftable;
  this->m_iTargetingProfile = 0;
  this->m_TargetingProfileSymbol.mUID = -1;
}

// File Line: 1406
// RVA: 0x14961D0
__int64 dynamic_initializer_for__TargetAssignSubTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAssignSubTargetTrack", 0xFFFFFFFF);
  TargetAssignSubTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 1424
// RVA: 0x2E13F0
void __fastcall TargetAssignSubTargetTrack::TargetAssignSubTargetTrack(TargetAssignSubTargetTrack *this)
{
  ITrack::ITrack(this, TargetAssignSubTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignSubTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignSubTargetTrack::`vftable;
  this->m_SubTargetName.mOffset = 1i64;
  BinString::Set(&this->m_SubTargetName, &customCaption);
  *(_QWORD *)&this->m_SubTargetType = 0i64;
  *(_WORD *)&this->m_RetrieveParent = 256;
  this->m_AssignToTargetType = 0;
}

// File Line: 1442
// RVA: 0x14966D0
__int64 dynamic_initializer_for__TargetWeaponModeChangeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetWeaponModeChangeTrack", 0xFFFFFFFF);
  TargetWeaponModeChangeTrack::sClassNameUID = result;
  return result;
}

// File Line: 1451
// RVA: 0x2E2070
void __fastcall TargetWeaponModeChangeTrack::TargetWeaponModeChangeTrack(TargetWeaponModeChangeTrack *this)
{
  ITrack::ITrack(this, TargetWeaponModeChangeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetWeaponModeChangeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponModeChangeTrack::`vftable;
  this->m_eTargetType.mValue = 0;
}

// File Line: 1465
// RVA: 0x14963D0
__int64 dynamic_initializer_for__TargetFractureTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetFractureTrack", 0xFFFFFFFF);
  TargetFractureTrack::sClassNameUID = result;
  return result;
}

// File Line: 1483
// RVA: 0x2E1A60
void __fastcall TargetFractureTrack::TargetFractureTrack(TargetFractureTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  ITrack::ITrack(this, TargetFractureTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetFractureTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureTrack::`vftable;
  this->mTargetType.mValue = 27;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mImpulse.x = UFG::qVector3::msZero.x;
  this->mImpulse.y = y;
  this->mImpulse.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mImpulseOffset.x = UFG::qVector3::msZero.x;
  this->mImpulseOffset.y = v4;
  this->mImpulseOffset.z = v5;
  this->mImpulseAtCentreOfMass = 1;
}

// File Line: 1487
// RVA: 0x2E5720
void __fastcall TargetFractureTrack::~TargetFractureTrack(TargetFractureTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureTrack::`vftable;
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

// File Line: 1503
// RVA: 0x14963B0
__int64 dynamic_initializer_for__TargetFractureStrengthTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetFractureStrengthTrack", 0xFFFFFFFF);
  TargetFractureStrengthTrack::sClassNameUID = result;
  return result;
}

// File Line: 1511
// RVA: 0x2E1A10
void __fastcall TargetFractureStrengthTrack::TargetFractureStrengthTrack(TargetFractureStrengthTrack *this)
{
  ITrack::ITrack(this, TargetFractureStrengthTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetFractureStrengthTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureStrengthTrack::`vftable;
  this->mTargetType.mValue = 27;
}

// File Line: 1515
// RVA: 0x2E56B0
void __fastcall TargetFractureStrengthTrack::~TargetFractureStrengthTrack(TargetFractureStrengthTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureStrengthTrack::`vftable;
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

// File Line: 1539
// RVA: 0x1495B90
__int64 dynamic_initializer_for__ProxyTargetSphereCastTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ProxyTargetSphereCastTrack", 0xFFFFFFFF);
  ProxyTargetSphereCastTrack::sClassNameUID = result;
  return result;
}

// File Line: 1566
// RVA: 0x2E0500
void __fastcall ProxyTargetSphereCastTrack::ProxyTargetSphereCastTrack(ProxyTargetSphereCastTrack *this)
{
  ITrack::ITrack(this, ProxyTargetSphereCastTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ProxyTargetSphereCastTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ProxyTargetSphereCastTrack::`vftable;
  this->mAssignToTargetType.mValue = 0;
  this->mRadius = 0.30000001;
  *(_QWORD *)&this->mStart.x = 1056964608i64;
  this->mStart.z = 1.0;
  *(_QWORD *)&this->mEnd.x = 1075838976i64;
  this->mEnd.z = 1.0;
  this->mFromBone = UFG::gNullQSymbolUC;
  this->mToTarget.mValue = 0;
  this->mToTargetBone = UFG::gNullQSymbolUC;
  this->mMakeUpright = 0;
  this->mCollisionLayer = 12;
  *(_WORD *)&this->mAllowExternalLocking = 257;
}

// File Line: 1575
// RVA: 0x2E04C0
void __fastcall ProxyTargetSphereCastTrack::ProxyTargetSphereCastTrack(
        ProxyTargetSphereCastTrack *this,
        MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ProxyTargetSphereCastTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ProxyTargetSphereCastTrack::`vftable;
}

// File Line: 1579
// RVA: 0x2E44B0
void __fastcall ProxyTargetSphereCastTrack::~ProxyTargetSphereCastTrack(ProxyTargetSphereCastTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ProxyTargetSphereCastTrack::`vftable;
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

