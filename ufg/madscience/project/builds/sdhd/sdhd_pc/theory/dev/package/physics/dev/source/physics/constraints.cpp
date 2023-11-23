// File Line: 33
// RVA: 0xAB520
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject>::GetTypeName(
        UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject> *this)
{
  return "UFG::ConstraintDef";
}

// File Line: 34
// RVA: 0xAB530
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef>::GetTypeName(
        UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef> *this)
{
  return "UFG::ConstraintDefBallAndSocket";
}

// File Line: 35
// RVA: 0xAB540
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef>::GetStaticTypeName(
        UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef> *this)
{
  return "UFG::ConstraintDefHinge";
}

// File Line: 36
// RVA: 0x1458B40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::ConstraintDefStiffSpring_UFG::ConstraintDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::ConstraintDefStiffSpring", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory,
    "UFG::ConstraintDefStiffSpring",
    v0);
  UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ConstraintDefStiffSpring>::`vftable;
  UFG::qReflectInventory<UFG::ConstraintDefStiffSpring>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ConstraintDefStiffSpring_UFG::ConstraintDef_::sInventory__);
}

// File Line: 37
// RVA: 0xAB550
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef>::GetTypeName(
        UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef> *this)
{
  return "UFG::ConstraintDefRagdoll";
}

// File Line: 38
// RVA: 0x14589C0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::ConstraintDefFixed_UFG::ConstraintDef_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::ConstraintDefFixed", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory,
    "UFG::ConstraintDefFixed",
    v0);
  UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ConstraintDefFixed>::`vftable;
  UFG::qReflectInventory<UFG::ConstraintDefFixed>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ConstraintDefFixed_UFG::ConstraintDef_::sInventory__);
}

// File Line: 43
// RVA: 0x14585C0
__int64 dynamic_initializer_for__UFG::ConstraintDef::sConstraintLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ConstraintDef::sConstraintLookup.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ConstraintDef::sConstraintLookup__);
}

// File Line: 51
// RVA: 0x1458460
__int64 dynamic_initializer_for__UFG::Constraint::mConstraintList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Constraint::mConstraintList__);
}

// File Line: 53
// RVA: 0x1458FD0
__int64 UFG::_dynamic_initializer_for__gConstraintAudioEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gConstraintAudioEventChannel,
    "ConstraintAudioEvent",
    "This is an event that gets generated constraints contain moving bodies.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gConstraintAudioEventChannel__);
}

// File Line: 59
// RVA: 0x98380
void __fastcall UFG::ConstraintAudioEvent::ConstraintAudioEvent(UFG::ConstraintAudioEvent *this)
{
  unsigned int mUID; // edx

  mUID = UFG::gConstraintAudioEventChannel.mUID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = mUID;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::ConstraintAudioEvent::`vftable;
  this->mConstraint.mPrev = &this->mConstraint;
  this->mConstraint.mNext = &this->mConstraint;
  this->mConstraint.m_pPointer = 0i64;
  this->mAudioEffect.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
}

// File Line: 66
// RVA: 0x982E0
void __fastcall UFG::Constraint::Constraint(UFG::Constraint *this, unsigned int *_name)
{
  UFG::qNode<UFG::Constraint,UFG::Constraint> *mPrev; // rax

  UFG::qSafePointerNode<UFG::Constraint>::qSafePointerNode<UFG::Constraint>(this);
  this->mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mNext = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable;
  this->mName.mUID = *_name;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mDefinition);
  this->mDefinition.mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
  mPrev = UFG::Constraint::mConstraintList.mNode.mPrev;
  UFG::Constraint::mConstraintList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&UFG::Constraint::mConstraintList;
  UFG::Constraint::mConstraintList.mNode.mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
}

// File Line: 74
// RVA: 0x97FA0
void __fastcall UFG::Constraint::Constraint(
        UFG::Constraint *this,
        UFG::qReflectHandle<UFG::qReflectObject> *rDef,
        hkpRigidBody *rb0,
        hkpRigidBody *rb1)
{
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v8; // rdi
  UFG::qReflectObject *mData; // rbp
  unsigned __int64 mTypeUID; // rsi
  hkpConstraintInstance *BallAndSocketConstraint; // rax
  UFG::qReflectObject *v12; // rsi
  hkpConstraintInstance *HingeConstraint; // rax
  UFG::qVector3 *v14; // rax
  UFG::qNode<UFG::Constraint,UFG::Constraint> *mPrev; // rax

  UFG::qSafePointerNode<UFG::Constraint>::qSafePointerNode<UFG::Constraint>(this);
  v8 = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mNext = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable;
  this->mName.mUID = -1;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mDefinition, rDef);
  mData = 0i64;
  if ( this->mDefinition.mData )
    mData = this->mDefinition.mData;
  this->mName.mUID = (unsigned int)mData[1].vfptr;
  mTypeUID = rDef->mData->mTypeUID;
  if ( mTypeUID == UFG::qStringHash64("UFG::ConstraintDefBallAndSocket", 0xFFFFFFFFFFFFFFFFui64) )
  {
    BallAndSocketConstraint = UFG::CreateBallAndSocketConstraint(
                                rb0,
                                rb1,
                                &this->mName,
                                (UFG::qVector3 *)mData[1].mBaseNode.mNeighbours,
                                *((float *)&mData[1].mBaseNode.mUID + 1),
                                *(float *)&mData[1].mBaseNode.mParent);
LABEL_14:
    this->mConstraintInstance = BallAndSocketConstraint;
    goto LABEL_15;
  }
  if ( mTypeUID != UFG::qStringHash64("UFG::ConstraintDefHinge", 0xFFFFFFFFFFFFFFFFui64) )
  {
    if ( mTypeUID == UFG::qStringHash64("UFG::ConstraintDefStiffSpring", 0xFFFFFFFFFFFFFFFFui64) )
    {
      BallAndSocketConstraint = UFG::CreateStiffSpringConstraint(
                                  rb0,
                                  rb1,
                                  &this->mName,
                                  (UFG::qVector3 *)rDef->mData[1].mBaseNode.mNeighbours,
                                  (UFG::qVector3 *)((char *)&rDef->mData[1].mBaseNode.mNeighbours[1] + 4),
                                  -1.0,
                                  *((float *)&rDef->mData[1].mBaseNode.mUID + 1),
                                  *(float *)&rDef->mData[1].mBaseNode.mParent);
    }
    else if ( mTypeUID == UFG::qStringHash64("UFG::ConstraintDefRagdoll", 0xFFFFFFFFFFFFFFFFui64) )
    {
      v14 = (UFG::qVector3 *)rDef->mData;
      BallAndSocketConstraint = UFG::CreateRagdollConstraint(
                                  rb0,
                                  rb1,
                                  &this->mName,
                                  v14 + 10,
                                  v14 + 11,
                                  v14 + 12,
                                  v14[13].x,
                                  v14[13].y,
                                  v14[13].z,
                                  v14[14].x,
                                  v14[14].y,
                                  v14[14].z,
                                  v14[7].z,
                                  v14[8].x);
    }
    else
    {
      if ( mTypeUID != UFG::qStringHash64("UFG::ConstraintDefFixed", 0xFFFFFFFFFFFFFFFFui64) )
        goto LABEL_15;
      BallAndSocketConstraint = UFG::CreateFixedConstraint(
                                  rb0,
                                  rb1,
                                  &this->mName,
                                  *((float *)&rDef->mData[1].mBaseNode.mUID + 1),
                                  *(float *)&rDef->mData[1].mBaseNode.mParent);
    }
    goto LABEL_14;
  }
  v12 = rDef->mData;
  HingeConstraint = UFG::CreateHingeConstraint(
                      rb0,
                      rb1,
                      &this->mName,
                      (UFG::qVector3 *)v12[1].mBaseNode.mNeighbours,
                      (UFG::qVector3 *)((char *)&v12[1].mBaseNode.mNeighbours[1] + 4),
                      *(float *)&v12[1].mHandles.mNode.mPrev,
                      *((float *)&v12[1].mHandles.mNode.mPrev + 1),
                      BYTE4(v12[1].mHandles.mNode.mNext),
                      *((float *)&v12[2].vfptr + 1),
                      *(float *)&v12[2].vfptr,
                      *((float *)&v12[1].mBaseNode.mUID + 1),
                      *(float *)&v12[1].mBaseNode.mParent);
  this->mConstraintInstance = HingeConstraint;
  if ( ((unsigned int (__fastcall *)(hkpConstraintData *))HingeConstraint->m_data->vfptr[1].__first_virtual_table_function__)(HingeConstraint->m_data) == 18 )
    LODWORD(this->mConstraintInstance->m_data[10].vfptr) = v12[1].mHandles.mNode.mNext;
LABEL_15:
  if ( BYTE5(mData[1].mBaseNode.mParent) )
    hkpConstraintInstance::setPriority(this->mConstraintInstance, PRIORITY_TOI);
  mPrev = UFG::Constraint::mConstraintList.mNode.mPrev;
  UFG::Constraint::mConstraintList.mNode.mPrev->mNext = v8;
  v8->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&UFG::Constraint::mConstraintList;
  UFG::Constraint::mConstraintList.mNode.mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  UFG::qReflectHandleBase::~qReflectHandleBase(rDef);
}

// File Line: 141
// RVA: 0x97B50
void __fastcall UFG::Constraint::Constraint(
        UFG::Constraint *this,
        UFG::PhysicsObjectProperties::ConstraintProperty *cp,
        hkpRigidBody *body)
{
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v6; // r15
  hkpConstraintInstance *v7; // rbp
  __int64 v8; // rsi
  char v9; // dl
  char v10; // cl
  _QWORD **Value; // rax
  hkpPointToPlaneConstraintData *v12; // rax
  hkpPointToPlaneConstraintData *v13; // rax
  hkpPointToPlaneConstraintData *v14; // r12
  hkJobType v15; // edx
  char v16; // dl
  char v17; // cl
  _QWORD **v18; // rax
  hkpMalleableConstraintData *v19; // rax
  hkJobType v20; // edx
  hkpMalleableConstraintData *v21; // rax
  hkpMalleableConstraintData *v22; // rbx
  char v23; // dl
  char v24; // cl
  _QWORD **v25; // rax
  hkpConstraintInstance *v26; // rax
  hkJobType v27; // edx
  hkpConstraintInstance *v28; // rax
  UFG::qNode<UFG::Constraint,UFG::Constraint> *mPrev; // rax
  hkVector4f b; // [rsp+70h] [rbp-B8h] BYREF
  hkVector4f planeNormalW; // [rsp+80h] [rbp-A8h] BYREF
  hkVector4f pivotW; // [rsp+90h] [rbp-98h] BYREF
  hkTransformf bodyBTransform; // [rsp+A0h] [rbp-88h] BYREF

  UFG::qSafePointerNode<UFG::Constraint>::qSafePointerNode<UFG::Constraint>(this);
  v6 = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mNext = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable;
  v7 = 0i64;
  this->mConstraintInstance = 0i64;
  this->mName.mUID = cp->mName.mUID;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mDefinition);
  this->mDefinition.mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
  if ( cp->mBallSocketConstraint )
  {
    this->mConstraintInstance = UFG::CreateBallAndSocketConstraint(
                                  body,
                                  0i64,
                                  &this->mName,
                                  &cp->mConstraintPivot1,
                                  1.0,
                                  -1.0);
  }
  else if ( cp->mStiffSpringConstraint )
  {
    this->mConstraintInstance = UFG::CreateStiffSpringConstraint(
                                  body,
                                  0i64,
                                  &cp->mName,
                                  &cp->mConstraintPivot2,
                                  &cp->mConstraintPivot1,
                                  -1.0,
                                  1.0,
                                  -1.0);
  }
  else if ( cp->mHingeConstraint )
  {
    this->mConstraintInstance = UFG::CreateHingeConstraint(
                                  body,
                                  0i64,
                                  &cp->mName,
                                  &cp->mConstraintPivot1,
                                  &cp->mHingeAxis,
                                  cp->mHingeLimitMin,
                                  cp->mHingeLimitMax,
                                  0,
                                  0.0,
                                  0.0,
                                  1.0,
                                  -1.0);
  }
  else if ( cp->mPointInPlaneConstraint )
  {
    v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v9 = ++*(_BYTE *)(v8 + 80);
    *(_DWORD *)(v8 + 4i64 * v9) = 3;
    *(_QWORD *)(v8 + 8i64 * v9 + 16) = "hkpPointToPlaneConstraintData";
    *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
    v10 = *(_BYTE *)(v8 + 81);
    if ( v9 > v10 )
      v10 = v9;
    *(_BYTE *)(v8 + 81) = v10;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkpPointToPlaneConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                             Value[11],
                                             192i64);
    if ( v12 )
    {
      hkpPointToPlaneConstraintData::hkpPointToPlaneConstraintData(v12);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    bodyBTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    bodyBTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    bodyBTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    bodyBTransform.m_translation = 0i64;
    b.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(cp->mConstraintPivot1.x), (__m128)LODWORD(cp->mConstraintPivot1.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(cp->mConstraintPivot1.y), (__m128)(unsigned int)FLOAT_1_0));
    hkVector4f::setTransformedPos(&pivotW, &body->m_motion.m_motionState.m_transform, &b);
    planeNormalW.m_quad = _mm_unpacklo_ps(
                            _mm_unpacklo_ps((__m128)LODWORD(cp->mNormal.x), (__m128)LODWORD(cp->mNormal.z)),
                            _mm_unpacklo_ps((__m128)LODWORD(cp->mNormal.y), (__m128)0i64));
    hkpPointToPlaneConstraintData::setInWorldSpace(
      v14,
      &body->m_motion.m_motionState.m_transform,
      &bodyBTransform,
      &pivotW,
      &planeNormalW);
    if ( 1.0 == cp->mStrength )
    {
      v22 = (hkpMalleableConstraintData *)v14;
    }
    else
    {
      v16 = ++*(_BYTE *)(v8 + 80);
      *(_DWORD *)(v8 + 4i64 * v16) = 3;
      *(_QWORD *)(v8 + 8i64 * v16 + 16) = "hkpMalleableConstraintData";
      *(_QWORD *)(v8 + 8i64 * v16 + 48) = 0i64;
      v17 = *(_BYTE *)(v8 + 81);
      if ( v16 > v17 )
        v17 = v16;
      *(_BYTE *)(v8 + 81) = v17;
      v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v19 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(
                                            v18[11],
                                            80i64);
      if ( v19 )
      {
        hkpMalleableConstraintData::hkpMalleableConstraintData(v19, v14);
        v22 = v21;
      }
      else
      {
        v22 = 0i64;
      }
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v20);
      hkpMalleableConstraintData::setStrength(v22, cp->mStrength);
      hkReferencedObject::removeReference(v14);
    }
    HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v15);
    v23 = ++*(_BYTE *)(v8 + 80);
    *(_DWORD *)(v8 + 4i64 * v23) = 3;
    *(_QWORD *)(v8 + 8i64 * v23 + 16) = "hkpConstraintInstance";
    *(_QWORD *)(v8 + 8i64 * v23 + 48) = 0i64;
    v24 = *(_BYTE *)(v8 + 81);
    if ( v23 > v24 )
      v24 = v23;
    *(_BYTE *)(v8 + 81) = v24;
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 112i64);
    if ( v26 )
    {
      hkpConstraintInstance::hkpConstraintInstance(v26, body, 0i64, v22, PRIORITY_PSI);
      v7 = v28;
    }
    this->mConstraintInstance = v7;
    HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v27);
    hkReferencedObject::removeReference(v22);
  }
  mPrev = UFG::Constraint::mConstraintList.mNode.mPrev;
  UFG::Constraint::mConstraintList.mNode.mPrev->mNext = v6;
  v6->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&UFG::Constraint::mConstraintList;
  UFG::Constraint::mConstraintList.mNode.mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
}

// File Line: 206
// RVA: 0x9BE00
void __fastcall UFG::Constraint::~Constraint(UFG::Constraint *this)
{
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v2; // rbx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *mPrev; // rdx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *mNext; // rax
  hkpConstraintInstance *mConstraintInstance; // rdx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v6; // rcx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v9; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable;
  v2 = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  this->mNext = &this->UFG::qNode<UFG::Constraint,UFG::Constraint>;
  mConstraintInstance = this->mConstraintInstance;
  if ( mConstraintInstance )
  {
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraintInstance);
    hkReferencedObject::removeReference(this->mConstraintInstance);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mDefinition);
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::qSafePointerNode<UFG::Constraint>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v8 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev;
  v9 = this->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 233
// RVA: 0xA4F30
UFG::Constraint *__fastcall UFG::Constraint::CreateHingeConstraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot,
        UFG::qVector3 *axis,
        float limitMin,
        float limitMax)
{
  char *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rbx
  UFG::qSymbol _name; // [rsp+60h] [rbp-28h] BYREF
  __int64 v16; // [rsp+68h] [rbp-20h]
  char *v17; // [rsp+70h] [rbp-18h]
  UFG::qSymbol *p_name; // [rsp+78h] [rbp-10h]

  v16 = -2i64;
  v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v17 = v11;
  if ( v11 )
  {
    p_name = &_name;
    _name.mUID = name->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v11, &_name.mUID);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  *(_QWORD *)(v13 + 40) = UFG::CreateHingeConstraint(
                            body1,
                            body2,
                            name,
                            pivot,
                            axis,
                            limitMin,
                            limitMax,
                            0,
                            0.0,
                            0.0,
                            1.0,
                            -1.0);
  return (UFG::Constraint *)v13;
}

// File Line: 242
// RVA: 0xA4710
UFG::Constraint *__fastcall UFG::Constraint::CreateBallAndSocketConstraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot)
{
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbx
  UFG::qSymbol _name; // [rsp+30h] [rbp-28h] BYREF
  __int64 v13; // [rsp+38h] [rbp-20h]
  char *v14; // [rsp+40h] [rbp-18h]
  UFG::qSymbol *p_name; // [rsp+48h] [rbp-10h]

  v13 = -2i64;
  v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v14 = v8;
  if ( v8 )
  {
    p_name = &_name;
    _name.mUID = name->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v8, &_name.mUID);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *(_QWORD *)(v10 + 40) = UFG::CreateBallAndSocketConstraint(body1, body2, name, pivot, 1.0, -1.0);
  return (UFG::Constraint *)v10;
}

// File Line: 251
// RVA: 0xA65F0
UFG::Constraint *__fastcall UFG::Constraint::CreateStiffSpringContraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot1,
        UFG::qVector3 *pivot2)
{
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  UFG::qSymbol _name; // [rsp+40h] [rbp-28h] BYREF
  __int64 v14; // [rsp+48h] [rbp-20h]
  char *v15; // [rsp+50h] [rbp-18h]
  UFG::qSymbol *p_name; // [rsp+58h] [rbp-10h]

  v14 = -2i64;
  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v15 = v9;
  if ( v9 )
  {
    p_name = &_name;
    _name.mUID = name->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v9, &_name.mUID);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  *(_QWORD *)(v11 + 40) = UFG::CreateStiffSpringConstraint(body1, body2, name, pivot1, pivot2);
  return (UFG::Constraint *)v11;
}

// File Line: 260
// RVA: 0xA4E70
UFG::Constraint *__fastcall UFG::Constraint::CreateFixedContraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name)
{
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  UFG::qSymbol _name; // [rsp+78h] [rbp+20h] BYREF

  v6 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  if ( v6 )
  {
    _name.mUID = name->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v6, &_name.mUID);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  *(_QWORD *)(v8 + 40) = UFG::CreateFixedConstraint(body1, body2, name, 1.0, -1.0);
  return (UFG::Constraint *)v8;
}

// File Line: 273
// RVA: 0xA61D0
hkpConstraintInstance *__fastcall UFG::CreateStiffSpringConstraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot1,
        UFG::qVector3 *pivot2)
{
  __int128 m_col2; // xmm0
  hkVector4f v8; // xmm1
  hkMotionState *p_m_motionState; // rdx
  __int64 v10; // rbx
  char v11; // dl
  char v12; // cl
  _QWORD **Value; // rax
  hkpStiffSpringConstraintData *v14; // rax
  hkpMalleableConstraintData *v15; // rax
  hkpMalleableConstraintData *v16; // rdi
  char v17; // al
  __m128 v18; // xmm8
  __m128 v19; // xmm8
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  _QWORD **v22; // rax
  hkpMalleableConstraintData *v23; // rax
  hkpMalleableConstraintData *v24; // rax
  hkpMalleableConstraintData *v25; // r14
  _QWORD **v26; // rax
  hkpBreakableConstraintData *v27; // rax
  __int64 v28; // rax
  __int64 v29; // r14
  char v30; // r8
  char v31; // cl
  _QWORD **v32; // rax
  hkpConstraintInstance *v33; // rax
  __int64 v34; // rax
  __int64 v35; // rsi
  char v36; // al
  _BYTE v38[40]; // [rsp+30h] [rbp-81h] BYREF
  __m128 m_quad; // [rsp+58h] [rbp-59h]
  __int128 v40; // [rsp+68h] [rbp-49h]
  __m128 v41; // [rsp+78h] [rbp-39h]
  hkVector4f b; // [rsp+88h] [rbp-29h] BYREF
  __int64 v43; // [rsp+98h] [rbp-19h]
  unsigned int *v44; // [rsp+118h] [rbp+67h]
  float v45; // [rsp+120h] [rbp+6Fh]
  float v46; // [rsp+128h] [rbp+77h]

  v43 = -2i64;
  b.m_quad = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)LODWORD(pivot1->x), (__m128)LODWORD(pivot1->z)),
               _mm_unpacklo_ps((__m128)LODWORD(pivot1->y), (__m128)(unsigned int)FLOAT_1_0));
  *(__m128 *)&v38[16] = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)*v44, (__m128)v44[2]),
                          _mm_unpacklo_ps((__m128)v44[1], (__m128)(unsigned int)FLOAT_1_0));
  hkVector4f::setTransformedPos((hkVector4f *)&v38[8], &body1->m_motion.m_motionState.m_transform, &b);
  if ( body2 )
  {
    *(hkVector4f *)&v38[24] = body2->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    m_quad = body2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
    m_col2 = (__int128)body2->m_motion.m_motionState.m_transform.m_rotation.m_col2;
    v8.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_translation;
    p_m_motionState = (hkMotionState *)&v38[24];
  }
  else
  {
    *(hkVector4f *)&v38[24] = (hkVector4f)transform.m_quad;
    m_quad = direction.m_quad;
    m_col2 = (__int128)stru_141A71280.m_quad;
    v8.m_quad = 0i64;
    p_m_motionState = &body1->m_motion.m_motionState;
  }
  v40 = m_col2;
  v41 = v8.m_quad;
  hkVector4f::setTransformedPos((hkVector4f *)v38, &p_m_motionState->m_transform, (hkVector4f *)&v38[16]);
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v11) = 3;
  *(_QWORD *)(v10 + 8i64 * v11 + 16) = "hkpStiffSpringConstraintData";
  *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v10 + 81);
  if ( v11 > v12 )
    v12 = v11;
  *(_BYTE *)(v10 + 81) = v12;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkpStiffSpringConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          112i64);
  if ( v14 )
  {
    hkpStiffSpringConstraintData::hkpStiffSpringConstraintData(v14);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = *(_BYTE *)(v10 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  hkVector4f::setTransformedInversePos(
    (hkVector4f *)&v16->m_atoms.m_bridgeAtom.m_constraintData,
    &body1->m_motion.m_motionState.m_transform,
    (hkVector4f *)&v38[8]);
  hkVector4f::setTransformedInversePos((hkVector4f *)&v16->m_strength, (hkTransformf *)&v38[24], (hkVector4f *)v38);
  v18 = _mm_sub_ps(*(__m128 *)&v38[8], *(__m128 *)v38);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 170), _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)));
  v21 = _mm_rsqrt_ps(v20);
  HIDWORD(v16[1].m_userData) = _mm_andnot_ps(
                                 _mm_cmple_ps(v20, (__m128)0i64),
                                 _mm_mul_ps(
                                   v20,
                                   _mm_mul_ps(
                                     _mm_mul_ps(*(__m128 *)_xmm, v21),
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21))))).m128_u32[0];
  LODWORD(v16[1].m_constraintData) = _mm_andnot_ps(
                                       _mm_cmple_ps(v20, (__m128)0i64),
                                       _mm_mul_ps(
                                         v20,
                                         _mm_mul_ps(
                                           _mm_mul_ps(*(__m128 *)_xmm, v21),
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21))))).m128_u32[0];
  if ( v45 != -1.0 )
  {
    *((float *)&v16[1].m_userData + 1) = v45;
    *(float *)&v16[1].m_constraintData = v45;
  }
  if ( v46 < 1.0 )
  {
    v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 80i64);
    if ( v23 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v23, v16);
      v25 = v24;
    }
    else
    {
      v25 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v25, v46);
    hkReferencedObject::removeReference(v16);
    v16 = v25;
  }
  if ( *(float *)&pivot2 > 0.0 )
  {
    v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v27 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 96i64);
    if ( v27 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v27, v16);
      v29 = v28;
    }
    else
    {
      v29 = 0i64;
    }
    *(_DWORD *)(v29 + 76) = (_DWORD)pivot2;
    hkReferencedObject::removeReference(v16);
    v16 = (hkpMalleableConstraintData *)v29;
  }
  v30 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v30) = 3;
  *(_QWORD *)(v10 + 8i64 * v30 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v10 + 8i64 * v30 + 48) = 0i64;
  v31 = *(_BYTE *)(v10 + 81);
  if ( v30 > v31 )
    v31 = v30;
  *(_BYTE *)(v10 + 81) = v31;
  v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v32[11] + 8i64))(v32[11], 112i64);
  if ( v33 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v33, body1, body2, v16, PRIORITY_PSI);
    v35 = v34;
  }
  else
  {
    v35 = 0i64;
  }
  v36 = *(_BYTE *)(v10 + 80);
  if ( v36 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v36 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v16);
  return (hkpConstraintInstance *)v35;
}

// File Line: 329
// RVA: 0xA47E0
hkpConstraintInstance *__fastcall UFG::CreateBallAndSocketConstraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot)
{
  hkVector4f v6; // xmm0
  hkVector4f v7; // xmm1
  __int64 v8; // rbx
  char v9; // dl
  char v10; // cl
  _QWORD **Value; // rax
  hkpBallAndSocketConstraintData *v12; // rax
  hkpBallAndSocketConstraintData *v13; // rax
  hkpBallAndSocketConstraintData *v14; // rdi
  char v15; // al
  _QWORD **v16; // rax
  hkpMalleableConstraintData *v17; // rax
  hkpMalleableConstraintData *v18; // rax
  hkpMalleableConstraintData *v19; // r14
  _QWORD **v20; // rax
  hkpBreakableConstraintData *v21; // rax
  hkpBallAndSocketConstraintData *v22; // rax
  hkpBallAndSocketConstraintData *v23; // r14
  char v24; // r8
  char v25; // cl
  _QWORD **v26; // rax
  hkpConstraintInstance *v27; // rax
  hkpConstraintInstance *v28; // rax
  hkpConstraintInstance *v29; // rsi
  char v30; // al
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> array; // [rsp+10h] [rbp-61h] BYREF
  hkVector4f b; // [rsp+28h] [rbp-49h] BYREF
  hkVector4f pivota; // [rsp+38h] [rbp-39h] BYREF
  hkTransformf bodyBTransform; // [rsp+48h] [rbp-29h] BYREF
  void *v36; // [rsp+C8h] [rbp+57h]
  void *retaddr; // [rsp+E8h] [rbp+77h]
  float v38; // [rsp+F0h] [rbp+7Fh]

  if ( body2 )
  {
    bodyBTransform.m_rotation.m_col0 = body2->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    bodyBTransform.m_rotation.m_col1 = body2->m_motion.m_motionState.m_transform.m_rotation.m_col1;
    v6.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_rotation.m_col2;
    v7.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_translation;
  }
  else
  {
    bodyBTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    bodyBTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v6.m_quad = stru_141A71280.m_quad;
    v7.m_quad = 0i64;
  }
  bodyBTransform.m_translation = (hkVector4f)v7.m_quad;
  bodyBTransform.m_rotation.m_col2 = (hkVector4f)v6.m_quad;
  b.m_quad = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)LODWORD(pivot->x), (__m128)LODWORD(pivot->z)),
               _mm_unpacklo_ps((__m128)LODWORD(pivot->y), (__m128)(unsigned int)FLOAT_1_0));
  hkVector4f::setTransformedPos(&pivota, &body1->m_motion.m_motionState.m_transform, &b);
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v9) = 3;
  *(_QWORD *)(v8 + 8i64 * v9 + 16) = "hkpBallAndSocketConstraintData";
  *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
  v10 = *(_BYTE *)(v8 + 81);
  if ( v9 > v10 )
    v10 = v9;
  *(_BYTE *)(v8 + 81) = v10;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpBallAndSocketConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                            Value[11],
                                            112i64);
  v36 = v12;
  if ( v12 )
  {
    hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData(v12);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = *(_BYTE *)(v8 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  hkpBallAndSocketConstraintData::setInWorldSpace(
    v14,
    &body1->m_motion.m_motionState.m_transform,
    &bodyBTransform,
    &pivota);
  if ( *(float *)&retaddr < 1.0 )
  {
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 80i64);
    v36 = v17;
    if ( v17 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v17, v14);
      v19 = v18;
    }
    else
    {
      v19 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v19, *(const float *)&retaddr);
    hkReferencedObject::removeReference(v14);
    v14 = (hkpBallAndSocketConstraintData *)v19;
  }
  if ( v38 > 0.0 )
  {
    v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v21 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v20[11] + 8i64))(v20[11], 96i64);
    v36 = v21;
    if ( v21 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v21, v14);
      v23 = v22;
    }
    else
    {
      v23 = 0i64;
    }
    v23->m_atoms.m_pivots.m_translationB.m_quad.m128_f32[3] = v38;
    hkReferencedObject::removeReference(v14);
    v14 = v23;
  }
  v24 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v24) = 3;
  *(_QWORD *)(v8 + 8i64 * v24 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v8 + 8i64 * v24 + 48) = 0i64;
  v25 = *(_BYTE *)(v8 + 81);
  if ( v24 > v25 )
    v25 = v24;
  *(_BYTE *)(v8 + 81) = v25;
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 112i64);
  v36 = v27;
  if ( v27 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v27, body1, body2, v14, PRIORITY_PSI);
    v29 = v28;
  }
  else
  {
    v29 = 0i64;
  }
  v30 = *(_BYTE *)(v8 + 80);
  if ( v30 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v30 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v14);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
  array.m_data[array.m_size] = v29;
  hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(&array, METHOD_STABILIZED);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  return v29;
}

// File Line: 382
// RVA: 0xA5040
hkpConstraintInstance *__fastcall UFG::CreateHingeConstraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot,
        UFG::qVector3 *axis,
        float limitMin,
        float limitMax)
{
  hkpRigidBody *v8; // r12
  __m128 m_quad; // xmm0
  hkVector4f v10; // xmm1
  __int64 v11; // rbx
  char v12; // dl
  char v13; // cl
  _QWORD **v14; // rax
  hkpLimitedHingeConstraintData *v15; // rax
  hkpLimitedHingeConstraintData *v16; // rax
  hkpLimitedHingeConstraintData *v17; // r15
  char v18; // al
  hkpMalleableConstraintData *v19; // rsi
  _QWORD **v20; // rax
  hkpMalleableConstraintData *v21; // rax
  hkpMalleableConstraintData *v22; // rax
  _QWORD **v23; // rax
  hkpBreakableConstraintData *v24; // rax
  __int64 v25; // rax
  __int64 v26; // r12
  char v27; // dl
  char v28; // cl
  _QWORD **v29; // rax
  hkpConstraintInstance *v30; // rax
  hkpConstraintInstance *v31; // rax
  hkpConstraintInstance *v32; // r14
  char v33; // al
  char v34; // dl
  char v35; // cl
  _QWORD **v36; // rax
  hkpPositionConstraintMotor *v37; // rax
  __int64 v38; // rax
  __int64 v39; // rsi
  char v40; // al
  char v41; // dl
  char v42; // cl
  hkpConstraintInstance *v43; // r15
  char v44; // al
  _QWORD **Value; // rax
  hkpHingeConstraintData *v47; // rax
  hkpHingeConstraintData *v48; // rax
  hkpHingeConstraintData *v49; // rbx
  _QWORD **v50; // rax
  hkpMalleableConstraintData *v51; // rax
  hkpMalleableConstraintData *v52; // rax
  hkpMalleableConstraintData *v53; // rsi
  _QWORD **v54; // rax
  hkpBreakableConstraintData *v55; // rax
  hkpHingeConstraintData *v56; // rax
  hkpHingeConstraintData *v57; // rsi
  __int64 v58; // rsi
  char v59; // dl
  char v60; // cl
  _QWORD **v61; // rax
  hkpConstraintInstance *v62; // rax
  hkpConstraintInstance *v63; // rax
  char v64; // al
  hkVector4f pivota; // [rsp+30h] [rbp-91h] BYREF
  hkVector4f axisIn; // [rsp+40h] [rbp-81h] BYREF
  _BYTE v67[48]; // [rsp+48h] [rbp-79h] BYREF
  hkVector4f bodyBTransform_40; // [rsp+78h] [rbp-49h] BYREF
  __int64 bodyBTransform_56; // [rsp+88h] [rbp-39h]
  hkpRigidBody *v70; // [rsp+F8h] [rbp+37h]
  unsigned int *retaddr; // [rsp+118h] [rbp+57h]
  float v72; // [rsp+120h] [rbp+5Fh]
  float v73; // [rsp+128h] [rbp+67h]
  char v74; // [rsp+130h] [rbp+6Fh]
  int v75; // [rsp+138h] [rbp+77h]

  v72 = *(float *)&body1;
  bodyBTransform_56 = -2i64;
  v8 = body1;
  if ( body2 )
  {
    *(hkVector4f *)&v67[8] = body2->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    *(hkVector4f *)&v67[24] = body2->m_motion.m_motionState.m_transform.m_rotation.m_col1;
    m_quad = body2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
    v10.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_translation;
  }
  else
  {
    *(hkVector4f *)&v67[8] = (hkVector4f)transform.m_quad;
    *(hkVector4f *)&v67[24] = (hkVector4f)direction.m_quad;
    m_quad = stru_141A71280.m_quad;
    v10.m_quad = 0i64;
  }
  *(hkVector4f *)&v67[16] = (hkVector4f)v10.m_quad;
  *(__m128 *)v67 = m_quad;
  *(__m128 *)&v67[32] = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(pivot->x), (__m128)LODWORD(pivot->z)),
                          _mm_unpacklo_ps((__m128)LODWORD(pivot->y), (__m128)(unsigned int)FLOAT_1_0));
  hkVector4f::setTransformedPos(&pivota, &body1->m_motion.m_motionState.m_transform, (hkVector4f *)&v67[32]);
  bodyBTransform_40.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps((__m128)*retaddr, (__m128)retaddr[2]),
                               _mm_unpacklo_ps((__m128)retaddr[1], (__m128)0i64));
  hkVector4f::setRotatedDir(&axisIn, &v8->m_motion.m_motionState.m_transform.m_rotation, &bodyBTransform_40);
  if ( v72 == -1.0 || v73 == -1.0 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v47 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
                                      224i64);
    v70 = (hkpRigidBody *)v47;
    if ( v47 )
    {
      hkpHingeConstraintData::hkpHingeConstraintData(v47);
      v49 = v48;
    }
    else
    {
      v49 = 0i64;
    }
    hkpHingeConstraintData::setInWorldSpace(
      v49,
      &v8->m_motion.m_motionState.m_transform,
      (hkTransformf *)&v67[8],
      &pivota,
      &axisIn);
    if ( limitMin < 1.0 )
    {
      v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v51 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v50[11] + 8i64))(
                                            v50[11],
                                            80i64);
      v70 = (hkpRigidBody *)v51;
      if ( v51 )
      {
        hkpMalleableConstraintData::hkpMalleableConstraintData(v51, v49);
        v53 = v52;
      }
      else
      {
        v53 = 0i64;
      }
      hkpMalleableConstraintData::setStrength(v53, limitMin);
      hkReferencedObject::removeReference(v49);
      v49 = (hkpHingeConstraintData *)v53;
    }
    if ( limitMax > 0.0 )
    {
      v54 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v55 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v54[11] + 8i64))(
                                            v54[11],
                                            96i64);
      v70 = (hkpRigidBody *)v55;
      if ( v55 )
      {
        hkpBreakableConstraintData::hkpBreakableConstraintData(v55, v49);
        v57 = v56;
      }
      else
      {
        v57 = 0i64;
      }
      v57->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad.m128_f32[3] = limitMax;
      hkReferencedObject::removeReference(v49);
      v49 = v57;
    }
    v58 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v59 = ++*(_BYTE *)(v58 + 80);
    *(_DWORD *)(v58 + 4i64 * v59) = 3;
    *(_QWORD *)(v58 + 8i64 * v59 + 16) = "hkpConstraintInstance";
    *(_QWORD *)(v58 + 8i64 * v59 + 48) = 0i64;
    v60 = *(_BYTE *)(v58 + 81);
    if ( v59 > v60 )
      v60 = v59;
    *(_BYTE *)(v58 + 81) = v60;
    v61 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v62 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v61[11] + 8i64))(v61[11], 112i64);
    v70 = (hkpRigidBody *)v62;
    if ( v62 )
    {
      hkpConstraintInstance::hkpConstraintInstance(v62, v8, body2, v49, PRIORITY_PSI);
      v32 = v63;
    }
    else
    {
      v32 = 0i64;
    }
    v64 = *(_BYTE *)(v58 + 80);
    if ( v64 > 0 )
    {
      *(_BYTE *)(v58 + 80) = v64 - 1;
    }
    else
    {
      *(_BYTE *)(v58 + 80) = 0;
      *(_DWORD *)v58 = 3;
      *(_QWORD *)(v58 + 16) = 0i64;
      *(_QWORD *)(v58 + 48) = 0i64;
    }
    hkReferencedObject::removeReference(v49);
    return v32;
  }
  v11 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v12 = ++*(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 4i64 * v12) = 3;
  *(_QWORD *)(v11 + 8i64 * v12 + 16) = "hkpLimitedHingeConstraintData";
  *(_QWORD *)(v11 + 8i64 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v11 + 81);
  if ( v12 > v13 )
    v13 = v12;
  *(_BYTE *)(v11 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(
                                           v14[11],
                                           304i64);
  retaddr = (unsigned int *)v15;
  if ( v15 )
  {
    hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v15);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = *(_BYTE *)(v11 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkpLimitedHingeConstraintData::setInWorldSpace(
    v17,
    &v8->m_motion.m_motionState.m_transform,
    (hkTransformf *)&v67[8],
    &pivota,
    &axisIn);
  v17->m_atoms.m_angLimit.m_minAngle = (float)(v72 * 3.1415927) * 0.0055555557;
  v17->m_atoms.m_angLimit.m_maxAngle = (float)(v73 * 3.1415927) * 0.0055555557;
  v19 = (hkpMalleableConstraintData *)v17;
  if ( limitMin < 1.0 )
  {
    v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v21 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v20[11] + 8i64))(v20[11], 80i64);
    retaddr = (unsigned int *)v21;
    if ( v21 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v21, v17);
      v19 = v22;
    }
    else
    {
      v19 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v19, limitMin);
    hkReferencedObject::removeReference(v17);
  }
  if ( limitMax > 0.0 && !v74 )
  {
    v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 96i64);
    retaddr = (unsigned int *)v24;
    if ( v24 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v24, v19);
      v26 = v25;
    }
    else
    {
      v26 = 0i64;
    }
    *(float *)(v26 + 76) = limitMax;
    hkReferencedObject::removeReference(v19);
    v19 = (hkpMalleableConstraintData *)v26;
    v8 = v70;
  }
  v27 = ++*(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 4i64 * v27) = 3;
  *(_QWORD *)(v11 + 8i64 * v27 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v11 + 8i64 * v27 + 48) = 0i64;
  v28 = *(_BYTE *)(v11 + 81);
  if ( v27 > v28 )
    v28 = v27;
  *(_BYTE *)(v11 + 81) = v28;
  v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v29[11] + 8i64))(v29[11], 112i64);
  v70 = (hkpRigidBody *)v30;
  if ( v30 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v30, v8, body2, v19, PRIORITY_PSI);
    v32 = v31;
  }
  else
  {
    v32 = 0i64;
  }
  v33 = *(_BYTE *)(v11 + 80);
  if ( v33 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v33 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v19);
  if ( !v74 )
    return v32;
  v17->m_atoms.m_angMotor.m_targetAngle = (float)(*(float *)&axis * 3.1415927) * 0.0055555557;
  v34 = ++*(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 4i64 * v34) = 3;
  *(_QWORD *)(v11 + 8i64 * v34 + 16) = "hkpPositionConstraintMotor";
  *(_QWORD *)(v11 + 8i64 * v34 + 48) = 0i64;
  v35 = *(_BYTE *)(v11 + 81);
  if ( v34 > v35 )
    v35 = v34;
  *(_BYTE *)(v11 + 81) = v35;
  v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v37 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v36[11] + 8i64))(v36[11], 48i64);
  v70 = (hkpRigidBody *)v37;
  if ( v37 )
  {
    hkpPositionConstraintMotor::hkpPositionConstraintMotor(v37, 0.0);
    v39 = v38;
  }
  else
  {
    v39 = 0i64;
  }
  *(_DWORD *)(v39 + 24) = v75 ^ _xmm[0];
  *(_DWORD *)(v39 + 28) = v75;
  v40 = *(_BYTE *)(v11 + 80);
  if ( v40 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v40 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  v41 = ++*(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 4i64 * v41) = 3;
  *(_QWORD *)(v11 + 8i64 * v41 + 16) = "poweredConstraint";
  *(_QWORD *)(v11 + 8i64 * v41 + 48) = 0i64;
  v42 = *(_BYTE *)(v11 + 81);
  if ( v41 > v42 )
    v42 = v41;
  *(_BYTE *)(v11 + 81) = v42;
  v43 = hkpConstraintUtils::convertToPowered(v32, (hkpConstraintMotor *)v39, (hkBool)1);
  v44 = *(_BYTE *)(v11 + 80);
  if ( v44 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v44 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v32);
  hkReferencedObject::removeReference((hkReferencedObject *)v39);
  return v43;
}ol)1);
  v44 = *(_BYTE *)(v11 + 80);
  if ( v44 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v44 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }


// File Line: 490
// RVA: 0xA5B40
hkpConstraintInstance *__fastcall UFG::CreateRagdollConstraint(
        hkpRigidBody *parent,
        hkpRigidBody *child,
        UFG::qSymbol *name,
        UFG::qVector3 *pivot,
        UFG::qVector3 *twistAxis,
        UFG::qVector3 *planeAxis,
        float planeMin,
        float planeMax,
        float twistMin)
{
  __int64 v11; // rbx
  char v12; // dl
  char v13; // cl
  _QWORD **Value; // rax
  hkpRagdollConstraintData *v15; // rax
  hkpRagdollConstraintData *v16; // rax
  hkpRagdollConstraintData *v17; // rdi
  char v18; // al
  _QWORD **v19; // rax
  hkpBreakableConstraintData *v20; // rax
  hkpRagdollConstraintData *v21; // rax
  hkpRagdollConstraintData *v22; // rsi
  char v23; // dl
  char v24; // cl
  _QWORD **v25; // rax
  hkpConstraintInstance *v26; // rax
  __int64 v27; // rax
  __int64 v28; // rsi
  char v29; // al
  hkVector4f array; // [rsp+38h] [rbp-69h] BYREF
  hkVector4f v32; // [rsp+48h] [rbp-59h] BYREF
  hkVector4f planeAxisW; // [rsp+58h] [rbp-49h] BYREF
  hkVector4f twistAxisW; // [rsp+68h] [rbp-39h] BYREF
  hkVector4f pivota; // [rsp+78h] [rbp-29h] BYREF
  hkVector4f v36; // [rsp+A0h] [rbp-1h] BYREF
  unsigned int *retaddr; // [rsp+F8h] [rbp+57h]
  unsigned int *v38; // [rsp+100h] [rbp+5Fh]
  float v39; // [rsp+108h] [rbp+67h]
  float v40; // [rsp+110h] [rbp+6Fh]
  float v41; // [rsp+118h] [rbp+77h]

  hkVector4f::setTransformedPos(&v36, &child->m_motion.m_motionState.m_transform, (hkVector4f *)&v32.m_quad.m128_u16[4]);
  array.m_quad = _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)*retaddr, (__m128)retaddr[2]),
                   _mm_unpacklo_ps((__m128)retaddr[1], (__m128)0i64));
  hkVector4f::setRotatedDir(&twistAxisW, &parent->m_motion.m_motionState.m_transform.m_rotation, &array);
  v32.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)*v38, (__m128)v38[2]),
                 _mm_unpacklo_ps((__m128)v38[1], (__m128)0i64));
  hkVector4f::setRotatedDir(&planeAxisW, &parent->m_motion.m_motionState.m_transform.m_rotation, &v32);
  v11 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v12 = ++*(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 4i64 * v12) = 3;
  *(_QWORD *)(v11 + 8i64 * v12 + 16) = "hkpRagdollConstraintData";
  *(_QWORD *)(v11 + 8i64 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v11 + 81);
  if ( v12 > v13 )
    v13 = v12;
  *(_BYTE *)(v11 + 81) = v13;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
                                      416i64);
  retaddr = (unsigned int *)v15;
  if ( v15 )
  {
    hkpRagdollConstraintData::hkpRagdollConstraintData(v15);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = *(_BYTE *)(v11 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkpRagdollConstraintData::setInWorldSpace(
    v17,
    &child->m_motion.m_motionState.m_transform,
    &parent->m_motion.m_motionState.m_transform,
    &pivota,
    &twistAxisW,
    &planeAxisW);
  v17->m_atoms.m_planesLimit.m_minAngle = (float)(v39 * 3.1415927) * 0.0055555557;
  v17->m_atoms.m_planesLimit.m_maxAngle = (float)(v40 * 3.1415927) * 0.0055555557;
  v17->m_atoms.m_twistLimit.m_minAngle = (float)(v41 * 3.1415927) * 0.0055555557;
  v17->m_atoms.m_twistLimit.m_maxAngle = (float)(*(float *)&twistAxis * 3.1415927) * 0.0055555557;
  v17->m_atoms.m_coneLimit.m_maxAngle = (float)(*(float *)&planeAxis * 3.1415927) * 0.0055555557;
  hkpRagdollConstraintData::setMaxFrictionTorque(v17, planeMin);
  if ( twistMin > 0.0 )
  {
    v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 96i64);
    retaddr = (unsigned int *)v20;
    if ( v20 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v20, v17);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    v22->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad.m128_f32[3] = twistMin;
    hkReferencedObject::removeReference(v17);
    v17 = v22;
  }
  v23 = ++*(_BYTE *)(v11 + 80);
  *(_DWORD *)(v11 + 4i64 * v23) = 3;
  *(_QWORD *)(v11 + 8i64 * v23 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v11 + 8i64 * v23 + 48) = 0i64;
  v24 = *(_BYTE *)(v11 + 81);
  if ( v23 > v24 )
    v24 = v23;
  *(_BYTE *)(v11 + 81) = v24;
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 112i64);
  retaddr = (unsigned int *)v26;
  if ( v26 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v26, child, parent, v17, PRIORITY_PSI);
    v28 = v27;
  }
  else
  {
    v28 = 0i64;
  }
  v29 = *(_BYTE *)(v11 + 80);
  if ( v29 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v29 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v17);
  array.m_quad.m128_u64[0] = 0i64;
  array.m_quad.m128_u64[1] = 0x8000000000000000ui64;
  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
  *(_QWORD *)(array.m_quad.m128_u64[0] + 8i64 * array.m_quad.m128_i32[2]++) = v28;
  hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
    (hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *)&array,
    METHOD_STABILIZED);
  array.m_quad.m128_i32[2] = 0;
  if ( array.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)array.m_quad.m128_u64[0],
      8 * array.m_quad.m128_i32[3]);
  return (hkpConstraintInstance *)v28;
}

// File Line: 542
// RVA: 0xA4B60
hkpConstraintInstance *__fastcall UFG::CreateFixedConstraint(
        hkpRigidBody *body1,
        hkpRigidBody *body2,
        UFG::qSymbol *name,
        float strength,
        float breakingStrength)
{
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm3
  __int64 v13; // rbx
  char v14; // dl
  char v15; // cl
  _QWORD **Value; // rax
  hkpFixedConstraintData *v17; // rax
  hkpFixedConstraintData *v18; // rax
  hkpFixedConstraintData *v19; // rdi
  char v20; // al
  _QWORD **v21; // rax
  hkpMalleableConstraintData *v22; // rax
  hkpMalleableConstraintData *v23; // rax
  hkpMalleableConstraintData *v24; // rbp
  _QWORD **v25; // rax
  hkpBreakableConstraintData *v26; // rax
  hkpFixedConstraintData *v27; // rax
  hkpFixedConstraintData *v28; // rbp
  char v29; // dl
  char v30; // cl
  _QWORD **v31; // rax
  hkpConstraintInstance *v32; // rax
  __int64 v33; // rax
  __int64 v34; // rsi
  char v35; // al
  hkTransformf bodyBTransform; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v38; // [rsp+70h] [rbp-78h]
  hkTransformf pivot; // [rsp+80h] [rbp-68h] BYREF

  v38 = -2i64;
  if ( body2 )
  {
    bodyBTransform.m_rotation.m_col0 = body2->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    bodyBTransform.m_rotation.m_col1 = body2->m_motion.m_motionState.m_transform.m_rotation.m_col1;
    v8.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_rotation.m_col2;
    v9.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_translation;
  }
  else
  {
    bodyBTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    bodyBTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v8.m_quad = stru_141A71280.m_quad;
    v9.m_quad = 0i64;
  }
  bodyBTransform.m_translation = (hkVector4f)v9.m_quad;
  bodyBTransform.m_rotation.m_col2 = (hkVector4f)v8.m_quad;
  v10.m_quad = (__m128)body1->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v11.m_quad = (__m128)body1->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v12.m_quad = (__m128)body1->m_motion.m_motionState.m_transform.m_translation;
  pivot.m_rotation.m_col0 = body1->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  pivot.m_rotation.m_col1 = (hkVector4f)v10.m_quad;
  pivot.m_rotation.m_col2 = (hkVector4f)v11.m_quad;
  pivot.m_translation = (hkVector4f)v12.m_quad;
  v13 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v14 = ++*(_BYTE *)(v13 + 80);
  *(_DWORD *)(v13 + 4i64 * v14) = 3;
  *(_QWORD *)(v13 + 8i64 * v14 + 16) = "hkpFixedConstraintData";
  *(_QWORD *)(v13 + 8i64 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v13 + 81);
  if ( v14 > v15 )
    v15 = v14;
  *(_BYTE *)(v13 + 81) = v15;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpFixedConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 224i64);
  if ( v17 )
  {
    hkpFixedConstraintData::hkpFixedConstraintData(v17);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v20 = *(_BYTE *)(v13 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
  hkpFixedConstraintData::setInWorldSpace(v19, &body1->m_motion.m_motionState.m_transform, &bodyBTransform, &pivot);
  if ( strength < 1.0 )
  {
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 80i64);
    if ( v22 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v22, v19);
      v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v24, strength);
    hkReferencedObject::removeReference(v19);
    v19 = (hkpFixedConstraintData *)v24;
  }
  if ( breakingStrength > 0.0 )
  {
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 96i64);
    if ( v26 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v26, v19);
      v28 = v27;
    }
    else
    {
      v28 = 0i64;
    }
    v28->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad.m128_f32[3] = breakingStrength;
    v28->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad.m128_i16[0] = 257;
    hkReferencedObject::removeReference(v19);
    v19 = v28;
  }
  v29 = ++*(_BYTE *)(v13 + 80);
  *(_DWORD *)(v13 + 4i64 * v29) = 3;
  *(_QWORD *)(v13 + 8i64 * v29 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v13 + 8i64 * v29 + 48) = 0i64;
  v30 = *(_BYTE *)(v13 + 81);
  if ( v29 > v30 )
    v30 = v29;
  *(_BYTE *)(v13 + 81) = v30;
  v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v31[11] + 8i64))(v31[11], 112i64);
  if ( v32 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v32, body1, body2, v19, PRIORITY_PSI);
    v34 = v33;
  }
  else
  {
    v34 = 0i64;
  }
  v35 = *(_BYTE *)(v13 + 80);
  if ( v35 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v35 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v19);
  return (hkpConstraintInstance *)v34;
}

// File Line: 590
// RVA: 0xA9130
void __fastcall UFG::Constraint::GenerateAudioEvents(hkVector4f *location)
{
  UFG::qNode<UFG::Constraint,UFG::Constraint> **i; // rdi
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v2; // r15
  hkpConstraintInstance *v3; // rsi
  __m128 *v4; // r14
  hkpEntity *v5; // rbp
  bool v6; // bl
  __m128 v7; // xmm4
  __m128 v8; // xmm4
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  float v15; // xmm6_4
  char *v16; // rax
  __int64 v17; // rax
  __int64 v18; // rbx
  int v19; // xmm2_4
  int v20; // xmm1_4
  hkVector4f pivotAinW; // [rsp+30h] [rbp-98h] BYREF
  hkVector4f pivotBinW; // [rsp+40h] [rbp-88h] BYREF
  hkBool result; // [rsp+D8h] [rbp+10h] BYREF
  hkBool v25; // [rsp+E0h] [rbp+18h] BYREF
  hkBool v26; // [rsp+E8h] [rbp+20h] BYREF

  for ( i = &UFG::Constraint::mConstraintList.mNode.mNext[-2].mNext;
        i != (UFG::qNode<UFG::Constraint,UFG::Constraint> **)((char *)&UFG::Constraint::mConstraintList - 24);
        i = &i[4][-2].mNext )
  {
    v2 = i[11];
    if ( v2 )
    {
      if ( LODWORD(v2[6].mNext) != -1 )
      {
        v3 = (hkpConstraintInstance *)i[5];
        if ( hkpConstraintInstance::isEnabled(v3, &result)->m_bool )
        {
          if ( v3->m_owner )
          {
            v4 = (__m128 *)v3->m_entities[0];
            v5 = v3->m_entities[1];
            v6 = 0;
            if ( v4 && hkpEntity::isActive(v3->m_entities[0], &v25)->m_bool )
              v6 = v4[1].m128_u64[0] != 0;
            if ( v5 && hkpEntity::isActive(v5, &v26)->m_bool && v5->m_world || v6 )
            {
              hkpConstraintInstance::getPivotsInWorld(v3, &pivotAinW, &pivotBinW);
              v7 = _mm_sub_ps(pivotAinW.m_quad, location->m_quad);
              v8 = _mm_mul_ps(v7, v7);
              v9 = _mm_add_ps(
                     _mm_shuffle_ps(v8, v8, 170),
                     _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)));
              v10 = _mm_rsqrt_ps(v9);
              if ( _mm_andnot_ps(
                     _mm_cmple_ps(v9, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10)),
                       v9)).m128_f32[0] <= *((float *)&v2[6].mNext + 1) )
              {
                v11 = _mm_sub_ps(v4[35], v5->m_motion.m_linearVelocity.m_quad);
                v12 = _mm_mul_ps(v11, v11);
                v13 = _mm_add_ps(
                        _mm_shuffle_ps(v12, v12, 170),
                        _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)));
                v14 = _mm_rsqrt_ps(v13);
                v15 = _mm_andnot_ps(
                        _mm_cmple_ps(v13, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                            _mm_mul_ps(*(__m128 *)_xmm, v14)),
                          v13)).m128_f32[0];
                if ( v15 >= *(float *)&v2[7].mPrev )
                {
                  v16 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
                  if ( v16 )
                  {
                    UFG::ConstraintAudioEvent::ConstraintAudioEvent((UFG::ConstraintAudioEvent *)v16);
                    v18 = v17;
                  }
                  else
                  {
                    v18 = 0i64;
                  }
                  UFG::qSafePointer<Creature,Creature>::operator=(
                    (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v18 + 56),
                    (UFG::SimComponent *)i);
                  UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v18 + 80), (UFG::qWiseSymbol *)&v2[6].mNext);
                  v19 = pivotAinW.m_quad.m128_i32[2];
                  v20 = pivotAinW.m_quad.m128_i32[1];
                  *(_DWORD *)(v18 + 84) = pivotAinW.m_quad.m128_i32[0];
                  *(_DWORD *)(v18 + 88) = v20;
                  *(_DWORD *)(v18 + 92) = v19;
                  *(float *)(v18 + 96) = v15;
                  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v18);
                }
              }
            }
          }
        }
      }
    }
  }
}

