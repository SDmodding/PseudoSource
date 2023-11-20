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
  TargetPlayEffectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetPlayEffectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayEffectTask>::`vftable';
  PlayEffectBaseTrack::PlayEffectBaseTrack((PlayEffectBaseTrack *)&v1->mAttachLimbName);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayEffectTrack::`vftable';
  v1->m_eTargetType.mValue = 22;
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
  TargetPlayTrack *v1; // rsi
  char *v2; // rax
  TargetPlayTrack *v3; // rax
  TargetPlayTrack *v4; // rdi
  UFG::qOffset64<ActionNodeReference *> *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rax

  v1 = this;
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
  v5 = &v4->mActionNodeReference;
  v6 = v4->mActionNodeReference.mOffset;
  if ( v6 && (UFG::qOffset64<ActionNodeReference *> *)((char *)v5 + v6) )
    (*(void (__fastcall **)(char *, signed __int64))(*(__int64 *)((char *)&v5->mOffset + v6) + 8))(
      (char *)v5 + v6,
      1i64);
  TargetPlayTrack::operator=(v4, v1);
  v7 = v1->mActionNodeReference.mOffset;
  if ( v7 )
    v8 = (signed __int64)&v1->mActionNodeReference + v7;
  else
    v8 = 0i64;
  v9 = (*(__int64 (**)(void))(*(_QWORD *)v8 + 16i64))();
  if ( v9 )
    v5->mOffset = v9 - (_QWORD)v5;
  else
    v5->mOffset = 0i64;
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
  TargetPlayAITrack *v1; // rsi
  char *v2; // rax
  char *v3; // rbx
  char *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "TargetPlayAITrack::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefTrack<TargetPlayAITask>::NodeRefTrack<TargetPlayAITask>(
      (NodeRefTrack<TargetPlayAITask> *)v2,
      TargetPlayAITrack::sClassNameUID);
    *(_QWORD *)v3 = &TargetPlayAITrack::`vftable';
    *((_DWORD *)v3 + 16) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v3 + 56;
  v5 = *((_QWORD *)v3 + 7);
  if ( v5 && &v4[v5] )
    (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)&v4[v5] + 8i64))(&v4[v5], 1i64);
  ITrack::operator=((ITrack *)v3, (ITrack *)&v1->vfptr);
  v6 = v1->mActionNodeReference.mOffset;
  if ( v6 && (v7 = (signed __int64)&v1->mActionNodeReference + v6) != 0 )
    v8 = v7 - (_QWORD)v4;
  else
    v8 = 0i64;
  *(_QWORD *)v4 = v8;
  *((_DWORD *)v3 + 16) = v1->mTargetType;
  v9 = v1->mActionNodeReference.mOffset;
  if ( v9 )
    v10 = (signed __int64)&v1->mActionNodeReference + v9;
  else
    v10 = 0i64;
  v11 = (*(__int64 (**)(void))(*(_QWORD *)v10 + 16i64))();
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
  TargetSpawnTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetSpawnTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSpawnTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSpawnTrack::`vftable';
  v1->m_eTargetType.mValue = 0;
  SpawnTrack::SpawnTrack(&v1->m_SpawnTrack);
}

// File Line: 365
// RVA: 0x303610
void __fastcall TargetSpawnTrack::ResolveReferences(TargetSpawnTrack *this, ActionNode *parent)
{
  ActionNode *v2; // rdi
  TargetSpawnTrack *v3; // rbx

  v2 = parent;
  v3 = this;
  _((AMD_HD3D *)this);
  v3->m_SpawnTrack.vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v3->m_SpawnTrack.vfptr, (unsigned int)v2);
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
  TargetSyncPositionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetSyncPositionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSyncPositionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSyncPositionTrack::`vftable';
  *(_QWORD *)&v1->mSyncTime = 0i64;
  *(_QWORD *)&v1->mAttachment.mUID = -1i64;
  *(_WORD *)&v1->mSyncToTarget = 0;
  v1->mPositionXYOnly = 0;
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
  TargetAttachTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAttachTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachTrack::`vftable';
  v1->mTargetType = 0;
  *(_QWORD *)&v1->mAssignmentTargetType = eTARGET_TYPE_EQUIPPED;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  *(_WORD *)&v1->mAttachToTarget = 0;
  v1->mAttachRelativeMaxDistance = -1.0;
  *(_WORD *)&v1->mAssignTargetType = 256;
  v1->mAddToInventory = 1;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetAttachEXTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAttachEXTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachEXTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachEXTrack::`vftable';
  *(_QWORD *)&v1->mRootTargetType = 1i64;
  *(_QWORD *)&v1->mAssignmentTargetType = 17i64;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  *(_WORD *)&v1->mAttachToTarget = 0;
  v1->mAttachRelativeMaxDistance = -1.0;
  *(_WORD *)&v1->mAssignTargetType = 256;
  v1->mAddToInventory = 1;
  v1->mPositionOnly = 0;
  v1->mTimeEnd = 0.0;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetStealAttachedItemTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetStealAttachedItemTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetStealAttachedItemTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetStealAttachedItemTrack::`vftable';
  v1->mTargetToStealFromType = 23;
  *(_QWORD *)&v1->mStolenItemAssignmentTargetType = 17i64;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  v1->mStolenItemJointName.mUID = -1;
  *(_DWORD *)&v1->mAddToInventory = 16842753;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mVictimDetachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mStolenItemJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetDetachTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetDetachTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachTrack::`vftable';
  *(_QWORD *)&v1->mTargetType = 0i64;
  v1->mClampVelocity = -1.0;
  v1->mDisableCollisionDelay = 0.0;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  *(_DWORD *)&v1->mDettachFromTarget = 16842752;
  *(_WORD *)&v1->mMakeUpright = 1;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetDetachEXTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetDetachEXTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachEXTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachEXTrack::`vftable';
  *(_QWORD *)&v1->mRootTargetType = 1i64;
  v1->mBlendOutTime = 0.0;
  v1->mClampVelocity = -1.0;
  v1->mDisableCollisionDelay = 0.0;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  *(_DWORD *)&v1->mDettachFromTarget = 16842752;
  *(_WORD *)&v1->mMakeUpright = 1;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetAttachEffectorTrack *v1; // rbx
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAttachEffectorTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachEffectorTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachEffectorTrack::`vftable';
  v1->mTargetType = 0;
  v1->mPostPhysicsUpdateOnly = 0;
  v1->mBlendInTime = 0.0;
  *(_QWORD *)&v1->mAttachEffectorName.mUID = -1i64;
  v1->mTargetAttachAdjustJointName.mUID = -1;
  v1->mAttachEffectorName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "LeftArmIK")->mUID;
  v1->mTargetAttachBaseJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachAdjustJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetDetachEffectorTrack *v1; // rbx
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetDetachEffectorTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachEffectorTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachEffectorTrack::`vftable';
  *(_QWORD *)&v1->mTargetType = 0i64;
  *(_QWORD *)&v1->mAttachEffectorName.mUID = -1i64;
  v1->mTargetAttachAdjustJointName.mUID = -1;
  v1->mAttachEffectorName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "LeftArmIK")->mUID;
  v1->mTargetAttachBaseJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachAdjustJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetAssignTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAssignTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignTrack::`vftable';
  *(_QWORD *)&v1->m_eAssignFrom.mValue = 0i64;
  *(_WORD *)&v1->m_bContinuous = 0;
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
void __fastcall TargetAssignTargetsTargetToMyTargetTrack::TargetAssignTargetsTargetToMyTargetTrack(TargetAssignTargetsTargetToMyTargetTrack *this)
{
  TargetAssignTargetsTargetToMyTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAssignTargetsTargetToMyTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignTargetsTargetToMyTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignTargetsTargetToMyTargetTrack::`vftable';
  *(_QWORD *)&v1->m_eTargetType.mValue = 0i64;
  v1->m_eMyTargetType.mValue = 0;
  v1->m_bContinuous = 0;
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
void __fastcall TargetAssignMyTargetToTargetsTargetTrack::TargetAssignMyTargetToTargetsTargetTrack(TargetAssignMyTargetToTargetsTargetTrack *this)
{
  TargetAssignMyTargetToTargetsTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAssignMyTargetToTargetsTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignMyTargetToTargetsTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignMyTargetToTargetsTargetTrack::`vftable';
  *(_QWORD *)&v1->m_eMyTargetType.mValue = 0i64;
  v1->m_eTargetsTargetType.mValue = 0;
  v1->m_bContinuous = 0;
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
  TargetVehicleBreakWindowTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetVehicleBreakWindowTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetVehicleBreakWindowTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetVehicleBreakWindowTrack::`vftable';
  v1->m_eTargetType.mValue = 28;
  v1->m_eWindowType.mValue = 3;
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
  TargetFocusOverrideTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetFocusOverrideTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetFocusOverrideTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetFocusOverrideTrack::`vftable';
  v1->m_eTargetType.mValue = 23;
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
  TargetHitReactionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetHitReactionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetHitReactionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetHitReactionTrack::`vftable';
  v1->m_eTargetType.mValue = 23;
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
  TargetAttachConstraintTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAttachConstraintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttachConstraintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAttachConstraintTrack::`vftable';
  v1->mTargetType = 0;
  v1->mAssignmentTargetType = 17;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  *(_WORD *)&v1->mAttachToTarget = 0;
  v1->mAttachRelativeMaxDistance = -1.0;
  *(_WORD *)&v1->mAssignTargetType = 256;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetAttachJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetDetachConstraintTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetDetachConstraintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDetachConstraintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDetachConstraintTrack::`vftable';
  v1->mTargetType = 0;
  *(_QWORD *)&v1->mDetachJointName.mUID = -1i64;
  v1->mDetachFromTarget = 0;
  v1->mDetachJointName.mUID = gStaticSymbolUC_none.mUID;
  v1->mTargetDetachJointName.mUID = gStaticSymbolUC_none.mUID;
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
  TargetLatchParkourHandleTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetLatchParkourHandleTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetLatchParkourHandleTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetLatchParkourHandleTrack::`vftable';
  v1->mTargetType = 0;
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
  TargetAttackRightsTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAttackRightsTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAttackRightsTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAttackRightsTrack::`vftable';
  v1->mTargetType = 0;
  *(_WORD *)&v1->mAttackingEnabled = 256;
}

// File Line: 1240
// RVA: 0x2E5640
void __fastcall TargetAttackRightsTrack::~TargetAttackRightsTrack(TargetAttackRightsTrack *this)
{
  TargetAttackRightsTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAttackRightsTrack::`vftable';
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
  TargetGunSetAmmoForAIDeathTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetGunSetAmmoForAIDeathTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetGunSetAmmoForAIDeathTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetGunSetAmmoForAIDeathTrack::`vftable';
  v1->m_eTargetType.mValue = 17;
}

// File Line: 1281
// RVA: 0x2E1BF0
void __fastcall TargetPhysicalAttackTrack::TargetPhysicalAttackTrack(TargetPhysicalAttackTrack *this)
{
  TargetPhysicalAttackTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetPhysicalAttackTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPhysicalAttackTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalAttackTrack::`vftable';
  v1->m_eTargetType.mValue = 17;
  v1->m_fAttackSpeed = -1.0;
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
  TargetPhysicalImpulseTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetPhysicalImpulseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPhysicalImpulseTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalImpulseTrack::`vftable';
  v1->m_eTargetType.mValue = 49;
  v1->m_fMagnitude = 10.0;
  v1->m_fPitch = 0.78539819;
  v1->m_eDirectionType.mValue = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->m_vDirection.x = UFG::qVector3::msZero.x;
  v1->m_vDirection.y = v2;
  v1->m_vDirection.z = v3;
}

// File Line: 1319
// RVA: 0x149C570
__int64 dynamic_initializer_for__gDirectionTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gDirectionTypeEnum, gDirectionTypeStringList, 3, 0i64);
  return atexit(dynamic_atexit_destructor_for__gDirectionTypeEnum__);
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
  TargetPhysicalDamageTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetPhysicalDamageTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPhysicalDamageTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalDamageTrack::`vftable';
  v1->m_eTargetType.mValue = 49;
  v1->m_iDamageType = 0;
  v1->m_fDamage = 1.0;
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
  return atexit(dynamic_atexit_destructor_for__gTargetingProfileEnum__);
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
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

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
  TargetingProfileSelectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetingProfileSelectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetingProfileSelectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetingProfileSelectTrack::`vftable';
  v1->m_iTargetingProfile = 0;
  v1->m_TargetingProfileSymbol.mUID = -1;
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
  TargetAssignSubTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetAssignSubTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetAssignSubTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignSubTargetTrack::`vftable';
  v1->m_SubTargetName.mOffset = 1i64;
  BinString::Set(&v1->m_SubTargetName, &customWorldMapCaption);
  *(_QWORD *)&v1->m_SubTargetType = 0i64;
  *(_WORD *)&v1->m_RetrieveParent = 256;
  v1->m_AssignToTargetType = 0;
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
  TargetWeaponModeChangeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetWeaponModeChangeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetWeaponModeChangeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponModeChangeTrack::`vftable';
  v1->m_eTargetType.mValue = 0;
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
  TargetFractureTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetFractureTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetFractureTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureTrack::`vftable';
  v1->mTargetType.mValue = 27;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mImpulse.x = UFG::qVector3::msZero.x;
  v1->mImpulse.y = v2;
  v1->mImpulse.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mImpulseOffset.x = UFG::qVector3::msZero.x;
  v1->mImpulseOffset.y = v4;
  v1->mImpulseOffset.z = v5;
  v1->mImpulseAtCentreOfMass = 1;
}

// File Line: 1487
// RVA: 0x2E5720
void __fastcall TargetFractureTrack::~TargetFractureTrack(TargetFractureTrack *this)
{
  TargetFractureTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureTrack::`vftable';
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
  TargetFractureStrengthTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetFractureStrengthTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetFractureStrengthTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureStrengthTrack::`vftable';
  v1->mTargetType.mValue = 27;
}

// File Line: 1515
// RVA: 0x2E56B0
void __fastcall TargetFractureStrengthTrack::~TargetFractureStrengthTrack(TargetFractureStrengthTrack *this)
{
  TargetFractureStrengthTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFractureStrengthTrack::`vftable';
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
  ProxyTargetSphereCastTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ProxyTargetSphereCastTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ProxyTargetSphereCastTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ProxyTargetSphereCastTrack::`vftable';
  v1->mAssignToTargetType.mValue = 0;
  v1->mRadius = 0.30000001;
  *(_QWORD *)&v1->mStart.x = 1056964608i64;
  v1->mStart.z = 1.0;
  *(_QWORD *)&v1->mEnd.x = 1075838976i64;
  v1->mEnd.z = 1.0;
  v1->mFromBone = UFG::gNullQSymbolUC;
  v1->mToTarget.mValue = 0;
  v1->mToTargetBone = UFG::gNullQSymbolUC;
  v1->mMakeUpright = 0;
  v1->mCollisionLayer = 12;
  *(_WORD *)&v1->mAllowExternalLocking = 257;
}

// File Line: 1575
// RVA: 0x2E04C0
void __fastcall ProxyTargetSphereCastTrack::ProxyTargetSphereCastTrack(ProxyTargetSphereCastTrack *this, MemImageLoadFlag flag)
{
  ProxyTargetSphereCastTrack *v2; // rbx

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<ProxyTargetSphereCastTask>::`vftable';
  v2->vfptr = (Expression::IMemberMapVtbl *)&ProxyTargetSphereCastTrack::`vftable';
}

// File Line: 1579
// RVA: 0x2E44B0
void __fastcall ProxyTargetSphereCastTrack::~ProxyTargetSphereCastTrack(ProxyTargetSphereCastTrack *this)
{
  ProxyTargetSphereCastTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ProxyTargetSphereCastTrack::`vftable';
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

