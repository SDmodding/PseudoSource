// File Line: 33
// RVA: 0xAB520
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject>::GetTypeName(UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject> *this)
{
  return "UFG::ConstraintDef";
}

// File Line: 34
// RVA: 0xAB530
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef>::GetTypeName(UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef> *this)
{
  return "UFG::ConstraintDefBallAndSocket";
}

// File Line: 35
// RVA: 0xAB540
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef>::GetStaticTypeName(UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef> *this)
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
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory.vfptr,
    "UFG::ConstraintDefStiffSpring",
    v0);
  UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ConstraintDefStiffSpring>::`vftable';
  UFG::qReflectInventory<UFG::ConstraintDefStiffSpring>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ConstraintDefStiffSpring_UFG::ConstraintDef_::sInventory__);
}

// File Line: 37
// RVA: 0xAB550
const char *__fastcall UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef>::GetTypeName(UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef> *this)
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
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory.vfptr,
    "UFG::ConstraintDefFixed",
    v0);
  UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ConstraintDefFixed>::`vftable';
  UFG::qReflectInventory<UFG::ConstraintDefFixed>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::ConstraintDefFixed,UFG::ConstraintDef>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ConstraintDefFixed_UFG::ConstraintDef_::sInventory__);
}

// File Line: 43
// RVA: 0x14585C0
__int64 dynamic_initializer_for__UFG::ConstraintDef::sConstraintLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ConstraintDef::sConstraintLookup.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::ConstraintDef::sConstraintLookup__);
}

// File Line: 51
// RVA: 0x1458460
__int64 dynamic_initializer_for__UFG::Constraint::mConstraintList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Constraint::mConstraintList__);
}

// File Line: 53
// RVA: 0x1458FD0
__int64 UFG::_dynamic_initializer_for__gConstraintAudioEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gConstraintAudioEventChannel,
    "ConstraintAudioEvent",
    "This is an event that gets generated constraints contain moving bodies.");
  return atexit(UFG::_dynamic_atexit_destructor_for__gConstraintAudioEventChannel__);
}

// File Line: 59
// RVA: 0x98380
void __fastcall UFG::ConstraintAudioEvent::ConstraintAudioEvent(UFG::ConstraintAudioEvent *this)
{
  unsigned int v1; // edx
  UFG::qNode<UFG::Event,UFG::Event> *v2; // rax
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v3; // [rsp+48h] [rbp+10h]

  v1 = UFG::gConstraintAudioEventChannel.mUID;
  v2 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_EventUID = v1;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::ConstraintAudioEvent::`vftable';
  v3 = &this->mConstraint;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mConstraint.m_pPointer = 0i64;
  this->mAudioEffect.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
}

// File Line: 66
// RVA: 0x982E0
void __fastcall UFG::Constraint::Constraint(UFG::Constraint *this, __int64 _name)
{
  unsigned int *v2; // rbx
  UFG::Constraint *v3; // rsi
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v4; // rdi
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v5; // rax

  v2 = (unsigned int *)_name;
  v3 = this;
  UFG::qSafePointerNode<UFG::Constraint>::qSafePointerNode<UFG::Constraint>((UFG::qSafePointerNode<UFG::Constraint> *)&this->vfptr);
  v4 = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable';
  v3->mName.mUID = *v2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mDefinition.mPrev);
  v3->mDefinition.mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
  v5 = UFG::Constraint::mConstraintList.mNode.mPrev;
  UFG::Constraint::mConstraintList.mNode.mPrev->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&UFG::Constraint::mConstraintList;
  UFG::Constraint::mConstraintList.mNode.mPrev = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v3->mPrev;
}

// File Line: 74
// RVA: 0x97FA0
void __fastcall UFG::Constraint::Constraint(UFG::Constraint *this, UFG::qReflectHandle<UFG::qReflectObject> *rDef, hkpRigidBody *rb0, hkpRigidBody *rb1)
{
  hkpRigidBody *v4; // r12
  hkpRigidBody *v5; // r13
  UFG::qReflectHandle<UFG::qReflectObject> *v6; // r14
  UFG::Constraint *v7; // rbx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v8; // rdi
  UFG::qReflectObject *v9; // rbp
  unsigned __int64 v10; // rsi
  hkpConstraintInstance *v11; // rax
  UFG::qReflectObject *v12; // rsi
  hkpConstraintInstance *v13; // rax
  UFG::qVector3 *v14; // rax
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v15; // rax

  v4 = rb1;
  v5 = rb0;
  v6 = rDef;
  v7 = this;
  UFG::qSafePointerNode<UFG::Constraint>::qSafePointerNode<UFG::Constraint>((UFG::qSafePointerNode<UFG::Constraint> *)&this->vfptr);
  v8 = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v7->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  v7->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable';
  v7->mName.mUID = -1;
  UFG::qReflectHandleBase::qReflectHandleBase(
    (UFG::qReflectHandleBase *)&v7->mDefinition.mPrev,
    (UFG::qReflectHandleBase *)&v6->mPrev);
  v9 = 0i64;
  if ( v7->mDefinition.mData )
    v9 = v7->mDefinition.mData;
  v7->mName.mUID = (unsigned int)v9[1].vfptr;
  v10 = v6->mData->mTypeUID;
  if ( v10 == UFG::qStringHash64("UFG::ConstraintDefBallAndSocket", 0xFFFFFFFFFFFFFFFFui64) )
  {
    v11 = UFG::CreateBallAndSocketConstraint(
            v5,
            v4,
            &v7->mName,
            (UFG::qVector3 *)v9[1].mBaseNode.mNeighbours,
            *((float *)&v9[1].mBaseNode.mUID + 1),
            *(float *)&v9[1].mBaseNode.mParent);
LABEL_14:
    v7->mConstraintInstance = v11;
    goto LABEL_15;
  }
  if ( v10 != UFG::qStringHash64("UFG::ConstraintDefHinge", 0xFFFFFFFFFFFFFFFFui64) )
  {
    if ( v10 == UFG::qStringHash64("UFG::ConstraintDefStiffSpring", 0xFFFFFFFFFFFFFFFFui64) )
    {
      v11 = UFG::CreateStiffSpringConstraint(
              v5,
              v4,
              &v7->mName,
              (UFG::qVector3 *)v6->mData[1].mBaseNode.mNeighbours,
              (UFG::qVector3 *)((char *)&v6->mData[1].mBaseNode.mNeighbours[1] + 4),
              -1.0,
              *((float *)&v6->mData[1].mBaseNode.mUID + 1),
              *(float *)&v6->mData[1].mBaseNode.mParent);
    }
    else if ( v10 == UFG::qStringHash64("UFG::ConstraintDefRagdoll", 0xFFFFFFFFFFFFFFFFui64) )
    {
      v14 = (UFG::qVector3 *)v6->mData;
      v11 = UFG::CreateRagdollConstraint(
              v5,
              v4,
              &v7->mName,
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
      if ( v10 != UFG::qStringHash64("UFG::ConstraintDefFixed", 0xFFFFFFFFFFFFFFFFui64) )
        goto LABEL_15;
      v11 = UFG::CreateFixedConstraint(
              v5,
              v4,
              &v7->mName,
              *((float *)&v6->mData[1].mBaseNode.mUID + 1),
              *(float *)&v6->mData[1].mBaseNode.mParent);
    }
    goto LABEL_14;
  }
  v12 = v6->mData;
  v13 = UFG::CreateHingeConstraint(
          v5,
          v4,
          &v7->mName,
          (UFG::qVector3 *)v12[1].mBaseNode.mNeighbours,
          (UFG::qVector3 *)((char *)&v12[1].mBaseNode.mNeighbours[1] + 4),
          *(float *)&v12[1].mHandles.mNode.mPrev,
          *((float *)&v12[1].mHandles.mNode.mPrev + 1),
          BYTE4(v12[1].mHandles.mNode.mNext),
          *((float *)&v12[2].vfptr + 1),
          *(float *)&v12[2].vfptr,
          *((float *)&v12[1].mBaseNode.mUID + 1),
          *(float *)&v12[1].mBaseNode.mParent);
  v7->mConstraintInstance = v13;
  if ( ((unsigned int (*)(void))v13->m_data->vfptr[1].__first_virtual_table_function__)() == 18 )
    LODWORD(v7->mConstraintInstance->m_data[10].vfptr) = v12[1].mHandles.mNode.mNext;
LABEL_15:
  if ( BYTE5(v9[1].mBaseNode.mParent) )
    hkpConstraintInstance::setPriority(v7->mConstraintInstance, PRIORITY_TOI);
  v15 = UFG::Constraint::mConstraintList.mNode.mPrev;
  UFG::Constraint::mConstraintList.mNode.mPrev->mNext = v8;
  v8->mPrev = v15;
  v7->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&UFG::Constraint::mConstraintList;
  UFG::Constraint::mConstraintList.mNode.mPrev = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v7->mPrev;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v6->mPrev);
}

// File Line: 141
// RVA: 0x97B50
void __fastcall UFG::Constraint::Constraint(UFG::Constraint *this, UFG::PhysicsObjectProperties::ConstraintProperty *cp, hkpRigidBody *body)
{
  hkpRigidBody *v3; // r13
  UFG::PhysicsObjectProperties::ConstraintProperty *v4; // rdi
  UFG::Constraint *v5; // r14
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v6; // r15
  hkpConstraintInstance *v7; // rbp
  signed __int64 v8; // rsi
  char v9; // dl
  __int64 v10; // rax
  char v11; // cl
  _QWORD **v12; // rax
  hkpPointToPlaneConstraintData *v13; // rax
  hkpPointToPlaneConstraintData *v14; // rax
  hkpPointToPlaneConstraintData *v15; // r12
  hkJobType v16; // edx
  char v17; // dl
  __int64 v18; // rax
  char v19; // cl
  _QWORD **v20; // rax
  hkpMalleableConstraintData *v21; // rax
  hkJobType v22; // edx
  hkpMalleableConstraintData *v23; // rax
  hkpMalleableConstraintData *v24; // rbx
  char v25; // dl
  __int64 v26; // rax
  char v27; // cl
  _QWORD **v28; // rax
  hkpConstraintInstance *v29; // rax
  hkJobType v30; // edx
  hkpConstraintInstance *v31; // rax
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v32; // rax
  hkVector4f b; // [rsp+70h] [rbp-B8h]
  hkVector4f planeNormalW; // [rsp+80h] [rbp-A8h]
  hkVector4f pivotW; // [rsp+90h] [rbp-98h]
  hkTransformf bodyBTransform; // [rsp+A0h] [rbp-88h]

  v3 = body;
  v4 = cp;
  v5 = this;
  UFG::qSafePointerNode<UFG::Constraint>::qSafePointerNode<UFG::Constraint>((UFG::qSafePointerNode<UFG::Constraint> *)&this->vfptr);
  v6 = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable';
  v7 = 0i64;
  v5->mConstraintInstance = 0i64;
  v5->mName.mUID = v4->mName.mUID;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v5->mDefinition.mPrev);
  v5->mDefinition.mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
  if ( v4->mBallSocketConstraint )
  {
    v5->mConstraintInstance = UFG::CreateBallAndSocketConstraint(
                                v3,
                                0i64,
                                &v5->mName,
                                &v4->mConstraintPivot1,
                                1.0,
                                -1.0);
  }
  else if ( v4->mStiffSpringConstraint )
  {
    v5->mConstraintInstance = UFG::CreateStiffSpringConstraint(
                                v3,
                                0i64,
                                &v4->mName,
                                &v4->mConstraintPivot2,
                                &v4->mConstraintPivot1,
                                -1.0,
                                1.0,
                                -1.0);
  }
  else if ( v4->mHingeConstraint )
  {
    v5->mConstraintInstance = UFG::CreateHingeConstraint(
                                v3,
                                0i64,
                                &v4->mName,
                                &v4->mConstraintPivot1,
                                &v4->mHingeAxis,
                                v4->mHingeLimitMin,
                                v4->mHingeLimitMax,
                                0,
                                0.0,
                                0.0,
                                1.0,
                                -1.0);
  }
  else if ( v4->mPointInPlaneConstraint )
  {
    v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v9 = ++*(_BYTE *)(v8 + 80);
    v10 = v9;
    *(_DWORD *)(v8 + 4 * v10) = 3;
    *(_QWORD *)(v8 + 8 * v10 + 16) = "hkpPointToPlaneConstraintData";
    *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
    v11 = *(_BYTE *)(v8 + 81);
    if ( v9 > v11 )
      v11 = v9;
    *(_BYTE *)(v8 + 81) = v11;
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpPointToPlaneConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                             v12[11],
                                             192i64);
    if ( v13 )
    {
      hkpPointToPlaneConstraintData::hkpPointToPlaneConstraintData(v13);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    bodyBTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    bodyBTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    bodyBTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    bodyBTransform.m_translation = 0i64;
    b.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(v4->mConstraintPivot1.x), (__m128)LODWORD(v4->mConstraintPivot1.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(v4->mConstraintPivot1.y), (__m128)(unsigned int)FLOAT_1_0));
    hkVector4f::setTransformedPos(&pivotW, &v3->m_motion.m_motionState.m_transform, &b);
    planeNormalW.m_quad = _mm_unpacklo_ps(
                            _mm_unpacklo_ps((__m128)LODWORD(v4->mNormal.x), (__m128)LODWORD(v4->mNormal.z)),
                            _mm_unpacklo_ps((__m128)LODWORD(v4->mNormal.y), (__m128)0i64));
    hkpPointToPlaneConstraintData::setInWorldSpace(
      v15,
      &v3->m_motion.m_motionState.m_transform,
      &bodyBTransform,
      &pivotW,
      &planeNormalW);
    if ( 1.0 == v4->mStrength )
    {
      v24 = (hkpMalleableConstraintData *)v15;
    }
    else
    {
      v17 = ++*(_BYTE *)(v8 + 80);
      v18 = v17;
      *(_DWORD *)(v8 + 4 * v18) = 3;
      *(_QWORD *)(v8 + 8 * v18 + 16) = "hkpMalleableConstraintData";
      *(_QWORD *)(v8 + 8 * v18 + 48) = 0i64;
      v19 = *(_BYTE *)(v8 + 81);
      if ( v17 > v19 )
        v19 = v17;
      *(_BYTE *)(v8 + 81) = v19;
      v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v21 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(
                                            v20[11],
                                            80i64);
      if ( v21 )
      {
        hkpMalleableConstraintData::hkpMalleableConstraintData(v21, (hkpConstraintData *)&v15->vfptr);
        v24 = v23;
      }
      else
      {
        v24 = 0i64;
      }
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v22);
      hkpMalleableConstraintData::setStrength(v24, v4->mStrength);
      hkReferencedObject::removeReference((hkReferencedObject *)&v15->vfptr);
    }
    HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v16);
    v25 = ++*(_BYTE *)(v8 + 80);
    v26 = v25;
    *(_DWORD *)(v8 + 4 * v26) = 3;
    *(_QWORD *)(v8 + 8 * v26 + 16) = "hkpConstraintInstance";
    *(_QWORD *)(v8 + 8 * v26 + 48) = 0i64;
    v27 = *(_BYTE *)(v8 + 81);
    if ( v25 > v27 )
      v27 = v25;
    *(_BYTE *)(v8 + 81) = v27;
    v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(
                                     v28[11],
                                     112i64);
    if ( v29 )
    {
      hkpConstraintInstance::hkpConstraintInstance(
        v29,
        (hkpEntity *)&v3->vfptr,
        0i64,
        (hkpConstraintData *)&v24->vfptr,
        PRIORITY_PSI);
      v7 = v31;
    }
    v5->mConstraintInstance = v7;
    HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v30);
    hkReferencedObject::removeReference((hkReferencedObject *)&v24->vfptr);
  }
  v32 = UFG::Constraint::mConstraintList.mNode.mPrev;
  UFG::Constraint::mConstraintList.mNode.mPrev->mNext = v6;
  v6->mPrev = v32;
  v5->mNext = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&UFG::Constraint::mConstraintList;
  UFG::Constraint::mConstraintList.mNode.mPrev = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&v5->mPrev;
}

// File Line: 206
// RVA: 0x9BE00
void __fastcall UFG::Constraint::~Constraint(UFG::Constraint *this)
{
  UFG::Constraint *v1; // rdi
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v2; // rbx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v3; // rdx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v4; // rax
  hkpConstraintInstance *v5; // rdx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v6; // rcx
  UFG::qNode<UFG::Constraint,UFG::Constraint> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::Constraint::`vftable';
  v2 = (UFG::qNode<UFG::Constraint,UFG::Constraint> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = this->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = this->mConstraintInstance;
  if ( v5 )
  {
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v5);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mConstraintInstance->vfptr);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mDefinition.mPrev);
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::Constraint>Vtbl *)&UFG::qSafePointerNode<UFG::Constraint>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v8 = v1->m_SafePointerList.mNode.mPrev;
  v9 = v1->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
}

// File Line: 233
// RVA: 0xA4F30
UFG::Constraint *__fastcall UFG::Constraint::CreateHingeConstraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, UFG::qVector3 *pivot, UFG::qVector3 *axis, float limitMin, float limitMax)
{
  UFG::qVector3 *v7; // rsi
  UFG::qSymbol *v8; // rdi
  hkpRigidBody *v9; // rbp
  hkpRigidBody *v10; // r14
  char *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rbx
  UFG::qSymbol _name; // [rsp+60h] [rbp-28h]
  __int64 v16; // [rsp+68h] [rbp-20h]
  char *v17; // [rsp+70h] [rbp-18h]
  UFG::qSymbol *v18; // [rsp+78h] [rbp-10h]

  v16 = -2i64;
  v7 = pivot;
  v8 = name;
  v9 = body2;
  v10 = body1;
  v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v17 = v11;
  if ( v11 )
  {
    v18 = &_name;
    _name.mUID = v8->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v11, (__int64)&_name);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  *(_QWORD *)(v13 + 40) = UFG::CreateHingeConstraint(v10, v9, v8, v7, axis, limitMin, limitMax, 0, 0.0, 0.0, 1.0, -1.0);
  return (UFG::Constraint *)v13;
}

// File Line: 242
// RVA: 0xA4710
UFG::Constraint *__fastcall UFG::Constraint::CreateBallAndSocketConstraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, UFG::qVector3 *pivot)
{
  UFG::qVector3 *v4; // rsi
  UFG::qSymbol *v5; // rdi
  hkpRigidBody *v6; // rbp
  hkpRigidBody *v7; // r14
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbx
  UFG::qSymbol _name; // [rsp+30h] [rbp-28h]
  __int64 v13; // [rsp+38h] [rbp-20h]
  char *v14; // [rsp+40h] [rbp-18h]
  UFG::qSymbol *v15; // [rsp+48h] [rbp-10h]

  v13 = -2i64;
  v4 = pivot;
  v5 = name;
  v6 = body2;
  v7 = body1;
  v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v14 = v8;
  if ( v8 )
  {
    v15 = &_name;
    _name.mUID = v5->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v8, (__int64)&_name);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *(_QWORD *)(v10 + 40) = UFG::CreateBallAndSocketConstraint(v7, v6, v5, v4, 1.0, -1.0);
  return (UFG::Constraint *)v10;
}

// File Line: 251
// RVA: 0xA65F0
UFG::Constraint *__fastcall UFG::Constraint::CreateStiffSpringContraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, UFG::qVector3 *pivot1, UFG::qVector3 *pivot2)
{
  UFG::qVector3 *v5; // rsi
  UFG::qSymbol *v6; // rdi
  hkpRigidBody *v7; // rbp
  hkpRigidBody *v8; // r14
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  UFG::qSymbol _name; // [rsp+40h] [rbp-28h]
  __int64 v14; // [rsp+48h] [rbp-20h]
  char *v15; // [rsp+50h] [rbp-18h]
  UFG::qSymbol *v16; // [rsp+58h] [rbp-10h]

  v14 = -2i64;
  v5 = pivot1;
  v6 = name;
  v7 = body2;
  v8 = body1;
  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v15 = v9;
  if ( v9 )
  {
    v16 = &_name;
    _name.mUID = v6->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v9, (__int64)&_name);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  *(_QWORD *)(v11 + 40) = UFG::CreateStiffSpringConstraint(v8, v7, v6, v5, pivot2);
  return (UFG::Constraint *)v11;
}

// File Line: 260
// RVA: 0xA4E70
UFG::Constraint *__fastcall UFG::Constraint::CreateFixedContraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name)
{
  UFG::qSymbol *v3; // rdi
  hkpRigidBody *v4; // rsi
  hkpRigidBody *v5; // rbp
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  UFG::qSymbol _name; // [rsp+78h] [rbp+20h]

  v3 = name;
  v4 = body2;
  v5 = body1;
  v6 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  if ( v6 )
  {
    _name.mUID = v3->mUID;
    UFG::Constraint::Constraint((UFG::Constraint *)v6, (__int64)&_name);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  *(_QWORD *)(v8 + 40) = UFG::CreateFixedConstraint(v5, v4, v3, 1.0, -1.0);
  return (UFG::Constraint *)v8;
}

// File Line: 273
// RVA: 0xA61D0
hkpConstraintInstance *__fastcall UFG::CreateStiffSpringConstraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, UFG::qVector3 *pivot1, UFG::qVector3 *pivot2)
{
  hkpRigidBody *v5; // rsi
  hkpRigidBody *v6; // r15
  __m128 v7; // xmm0
  __int128 v8; // xmm1
  hkTransformf *v9; // rdx
  signed __int64 v10; // rbx
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  hkpStiffSpringConstraintData *v15; // rax
  hkpMalleableConstraintData *v16; // rax
  hkpMalleableConstraintData *v17; // rdi
  char v18; // al
  __m128 v19; // xmm8
  __m128 v20; // xmm8
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  _QWORD **v24; // rax
  hkpMalleableConstraintData *v25; // rax
  hkpMalleableConstraintData *v26; // rax
  hkpMalleableConstraintData *v27; // r14
  _QWORD **v28; // rax
  hkpBreakableConstraintData *v29; // rax
  __int64 v30; // rax
  __int64 v31; // r14
  char v32; // r8
  __int64 v33; // rax
  char v34; // cl
  _QWORD **v35; // rax
  hkpConstraintInstance *v36; // rax
  __int64 v37; // rax
  __int64 v38; // rsi
  char v39; // al
  hkVector4f v41; // [rsp+30h] [rbp-81h]
  hkVector4f v42; // [rsp+40h] [rbp-71h]
  __m128 v43; // [rsp+58h] [rbp-59h]
  __m128 v44; // [rsp+68h] [rbp-49h]
  __int128 v45; // [rsp+78h] [rbp-39h]
  hkVector4f b; // [rsp+88h] [rbp-29h]
  __int64 v47; // [rsp+98h] [rbp-19h]
  unsigned int *v48; // [rsp+118h] [rbp+67h]
  float v49; // [rsp+120h] [rbp+6Fh]
  float v50; // [rsp+128h] [rbp+77h]

  v47 = -2i64;
  v5 = body2;
  v6 = body1;
  b.m_quad = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)LODWORD(pivot1->x), (__m128)LODWORD(pivot1->z)),
               _mm_unpacklo_ps((__m128)LODWORD(pivot1->y), (__m128)(unsigned int)FLOAT_1_0));
  v42.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)*v48, (__m128)v48[2]),
                 _mm_unpacklo_ps((__m128)v48[1], (__m128)(unsigned int)FLOAT_1_0));
  hkVector4f::setTransformedPos((hkVector4f *)((char *)&v41 + 8), &body1->m_motion.m_motionState.m_transform, &b);
  if ( v5 )
  {
    *(hkVector4f *)((char *)&v42 + 8) = v5->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    v43 = v5->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
    v7 = v5->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
    v8 = (__int128)v5->m_motion.m_motionState.m_transform.m_translation;
    v9 = (hkTransformf *)&v42.m_quad.m128_u16[4];
  }
  else
  {
    *(hkVector4f *)((char *)&v42 + 8) = (hkVector4f)transform.m_quad;
    v43 = direction.m_quad;
    v7 = stru_141A71280.m_quad;
    v8 = 0i64;
    v9 = &v6->m_motion.m_motionState.m_transform;
  }
  v44 = v7;
  v45 = v8;
  hkVector4f::setTransformedPos(&v41, v9, &v42);
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 3;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "hkpStiffSpringConstraintData";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkpStiffSpringConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                          v14[11],
                                          112i64);
  if ( v15 )
  {
    hkpStiffSpringConstraintData::hkpStiffSpringConstraintData(v15);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = *(_BYTE *)(v10 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  hkVector4f::setTransformedInversePos(
    (hkVector4f *)&v17->m_atoms.m_bridgeAtom.m_constraintData,
    &v6->m_motion.m_motionState.m_transform,
    (hkVector4f *)((char *)&v41 + 8));
  hkVector4f::setTransformedInversePos((hkVector4f *)&v17->m_strength, (hkTransformf *)&v42.m_quad.m128_u16[4], &v41);
  v19 = _mm_sub_ps(*(__m128 *)((char *)&v41.m_quad + 8), v41.m_quad);
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 170), _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)));
  v22 = _mm_rsqrt_ps(v21);
  HIDWORD(v17[1].m_userData) = (unsigned __int128)_mm_andnot_ps(
                                                    _mm_cmpleps(v21, (__m128)0i64),
                                                    _mm_mul_ps(
                                                      v21,
                                                      _mm_mul_ps(
                                                        _mm_mul_ps(*(__m128 *)_xmm, v22),
                                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)))));
  v23 = v22;
  LODWORD(v17[1].m_constraintData) = (unsigned __int128)_mm_andnot_ps(
                                                          _mm_cmpleps(v21, (__m128)0i64),
                                                          _mm_mul_ps(
                                                            v21,
                                                            _mm_mul_ps(
                                                              _mm_mul_ps(*(__m128 *)_xmm, v23),
                                                              _mm_sub_ps(
                                                                (__m128)_xmm,
                                                                _mm_mul_ps(_mm_mul_ps(v23, v21), v23)))));
  if ( v49 != -1.0 )
  {
    *((float *)&v17[1].m_userData + 1) = v49;
    *(float *)&v17[1].m_constraintData = v49;
  }
  if ( v50 < 1.0 )
  {
    v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(
                                          v24[11],
                                          80i64);
    if ( v25 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v25, (hkpConstraintData *)&v17->vfptr);
      v27 = v26;
    }
    else
    {
      v27 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v27, v50);
    hkReferencedObject::removeReference((hkReferencedObject *)&v17->vfptr);
    v17 = v27;
  }
  if ( *(float *)&pivot2 > 0.0 )
  {
    v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(
                                          v28[11],
                                          96i64);
    if ( v29 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v29, (hkpConstraintData *)&v17->vfptr);
      v31 = v30;
    }
    else
    {
      v31 = 0i64;
    }
    *(_DWORD *)(v31 + 76) = (_DWORD)pivot2;
    hkReferencedObject::removeReference((hkReferencedObject *)&v17->vfptr);
    v17 = (hkpMalleableConstraintData *)v31;
  }
  v32 = ++*(_BYTE *)(v10 + 80);
  v33 = v32;
  *(_DWORD *)(v10 + 4 * v33) = 3;
  *(_QWORD *)(v10 + 8 * v33 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v10 + 8 * v33 + 48) = 0i64;
  v34 = *(_BYTE *)(v10 + 81);
  if ( v32 > v34 )
    v34 = v32;
  *(_BYTE *)(v10 + 81) = v34;
  v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v36 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v35[11] + 8i64))(
                                   v35[11],
                                   112i64);
  if ( v36 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v36,
      (hkpEntity *)&v6->vfptr,
      (hkpEntity *)&v5->vfptr,
      (hkpConstraintData *)&v17->vfptr,
      PRIORITY_PSI);
    v38 = v37;
  }
  else
  {
    v38 = 0i64;
  }
  v39 = *(_BYTE *)(v10 + 80);
  if ( v39 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v39 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v17->vfptr);
  return (hkpConstraintInstance *)v38;
}= 0;
    *(_DWORD *)v10 = 3;
    *(_Q

// File Line: 329
// RVA: 0xA47E0
hkpConstraintInstance *__fastcall UFG::CreateBallAndSocketConstraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, UFG::qVector3 *pivot)
{
  hkpRigidBody *v4; // rsi
  hkpRigidBody *v5; // r15
  hkVector4f v6; // xmm0
  hkVector4f v7; // xmm1
  signed __int64 v8; // rbx
  char v9; // dl
  __int64 v10; // rax
  char v11; // cl
  _QWORD **v12; // rax
  hkpBallAndSocketConstraintData *v13; // rax
  hkpBallAndSocketConstraintData *v14; // rax
  hkpBallAndSocketConstraintData *v15; // rdi
  char v16; // al
  _QWORD **v17; // rax
  hkpMalleableConstraintData *v18; // rax
  hkpMalleableConstraintData *v19; // rax
  hkpMalleableConstraintData *v20; // r14
  _QWORD **v21; // rax
  hkpBreakableConstraintData *v22; // rax
  hkpBallAndSocketConstraintData *v23; // rax
  hkpBallAndSocketConstraintData *v24; // r14
  char v25; // r8
  __int64 v26; // rax
  char v27; // cl
  _QWORD **v28; // rax
  hkpConstraintInstance *v29; // rax
  __int64 v30; // rax
  __int64 v31; // rsi
  char v32; // al
  _QWORD *array; // [rsp+10h] [rbp-61h]
  int v35; // [rsp+18h] [rbp-59h]
  int v36; // [rsp+1Ch] [rbp-55h]
  hkVector4f b; // [rsp+28h] [rbp-49h]
  hkVector4f pivota; // [rsp+38h] [rbp-39h]
  hkTransformf bodyBTransform; // [rsp+48h] [rbp-29h]
  void *v40; // [rsp+C8h] [rbp+57h]
  void *retaddr; // [rsp+E8h] [rbp+77h]
  float v42; // [rsp+F0h] [rbp+7Fh]

  v4 = body2;
  v5 = body1;
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
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 3;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "hkpBallAndSocketConstraintData";
  *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 81) = v11;
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkpBallAndSocketConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                            v12[11],
                                            112i64);
  v40 = v13;
  if ( v13 )
  {
    hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData(v13);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = *(_BYTE *)(v8 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  hkpBallAndSocketConstraintData::setInWorldSpace(
    v15,
    &v5->m_motion.m_motionState.m_transform,
    &bodyBTransform,
    &pivota);
  if ( *(float *)&retaddr < 1.0 )
  {
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(
                                          v17[11],
                                          80i64);
    v40 = v18;
    if ( v18 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v18, (hkpConstraintData *)&v15->vfptr);
      v20 = v19;
    }
    else
    {
      v20 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v20, *(const float *)&retaddr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v15->vfptr);
    v15 = (hkpBallAndSocketConstraintData *)v20;
  }
  if ( v42 > 0.0 )
  {
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                          v21[11],
                                          96i64);
    v40 = v22;
    if ( v22 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v22, (hkpConstraintData *)&v15->vfptr);
      v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    v24->m_atoms.m_pivots.m_translationB.m_quad.m128_f32[3] = v42;
    hkReferencedObject::removeReference((hkReferencedObject *)&v15->vfptr);
    v15 = v24;
  }
  v25 = ++*(_BYTE *)(v8 + 80);
  v26 = v25;
  *(_DWORD *)(v8 + 4 * v26) = 3;
  *(_QWORD *)(v8 + 8 * v26 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v8 + 8 * v26 + 48) = 0i64;
  v27 = *(_BYTE *)(v8 + 81);
  if ( v25 > v27 )
    v27 = v25;
  *(_BYTE *)(v8 + 81) = v27;
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(
                                   v28[11],
                                   112i64);
  v40 = v29;
  if ( v29 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v29,
      (hkpEntity *)&v5->vfptr,
      (hkpEntity *)&v4->vfptr,
      (hkpConstraintData *)&v15->vfptr,
      PRIORITY_PSI);
    v31 = v30;
  }
  else
  {
    v31 = 0i64;
  }
  v32 = *(_BYTE *)(v8 + 80);
  if ( v32 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v32 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v15->vfptr);
  array = 0i64;
  v36 = 2147483648;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
  array[v35] = v31;
  hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
    (hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *)&array,
    0);
  v35 = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v36);
  return (hkpConstraintInstance *)v31;
}

// File Line: 382
// RVA: 0xA5040
hkpConstraintInstance *__fastcall UFG::CreateHingeConstraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, UFG::qVector3 *pivot, UFG::qVector3 *axis, float limitMin, float limitMax)
{
  hkpRigidBody *v7; // r14
  hkpRigidBody *v8; // r12
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  signed __int64 v11; // rbx
  char v12; // dl
  __int64 v13; // rax
  char v14; // cl
  _QWORD **v15; // rax
  hkpLimitedHingeConstraintData *v16; // rax
  hkpLimitedHingeConstraintData *v17; // rax
  hkpLimitedHingeConstraintData *v18; // r15
  char v19; // al
  hkpMalleableConstraintData *v20; // rsi
  _QWORD **v21; // rax
  hkpMalleableConstraintData *v22; // rax
  hkpMalleableConstraintData *v23; // rax
  _QWORD **v24; // rax
  hkpBreakableConstraintData *v25; // rax
  __int64 v26; // rax
  __int64 v27; // r12
  char v28; // dl
  __int64 v29; // rax
  char v30; // cl
  _QWORD **v31; // rax
  hkpConstraintInstance *v32; // rax
  hkpConstraintInstance *v33; // rax
  hkpConstraintInstance *v34; // r14
  char v35; // al
  char v36; // dl
  __int64 v37; // rax
  char v38; // cl
  _QWORD **v39; // rax
  hkpPositionConstraintMotor *v40; // rax
  __int64 v41; // rax
  __int64 v42; // rsi
  char v43; // al
  char v44; // dl
  __int64 v45; // rax
  char v46; // cl
  hkpConstraintInstance *v47; // r15
  char v48; // al
  _QWORD **v50; // rax
  hkpHingeConstraintData *v51; // rax
  hkpHingeConstraintData *v52; // rax
  hkpHingeConstraintData *v53; // rbx
  _QWORD **v54; // rax
  hkpMalleableConstraintData *v55; // rax
  hkpMalleableConstraintData *v56; // rax
  hkpMalleableConstraintData *v57; // rsi
  _QWORD **v58; // rax
  hkpBreakableConstraintData *v59; // rax
  hkpHingeConstraintData *v60; // rax
  hkpHingeConstraintData *v61; // rsi
  signed __int64 v62; // rsi
  char v63; // dl
  __int64 v64; // rax
  char v65; // cl
  _QWORD **v66; // rax
  hkpConstraintInstance *v67; // rax
  hkpConstraintInstance *v68; // rax
  char v69; // al
  hkVector4f pivota; // [rsp+30h] [rbp-91h]
  __m256i axisIn; // [rsp+40h] [rbp-81h]
  hkVector4f v72; // [rsp+60h] [rbp-61h]
  __m128 v73; // [rsp+78h] [rbp-49h]
  __int64 v74; // [rsp+88h] [rbp-39h]
  hkpRigidBody *v75; // [rsp+F8h] [rbp+37h]
  unsigned int *retaddr; // [rsp+118h] [rbp+57h]
  hkpRigidBody *v77; // [rsp+120h] [rbp+5Fh]
  float v78; // [rsp+128h] [rbp+67h]
  char v79; // [rsp+130h] [rbp+6Fh]
  int v80; // [rsp+138h] [rbp+77h]

  v77 = body1;
  v74 = -2i64;
  v7 = body2;
  v8 = body1;
  if ( body2 )
  {
    *(hkVector4f *)&axisIn.m256i_u64[2] = body2->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    v72.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_rotation.m_col1;
    v9.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_rotation.m_col2;
    v10.m_quad = (__m128)body2->m_motion.m_motionState.m_transform.m_translation;
  }
  else
  {
    *(hkVector4f *)&axisIn.m256i_u64[2] = (hkVector4f)transform.m_quad;
    v72.m_quad = direction.m_quad;
    v9.m_quad = stru_141A71280.m_quad;
    v10.m_quad = 0i64;
  }
  *(hkVector4f *)&axisIn.m256i_u64[3] = (hkVector4f)v10.m_quad;
  *(hkVector4f *)&axisIn.m256i_u64[1] = (hkVector4f)v9.m_quad;
  *(hkVector4f *)((char *)&v72 + 8) = (hkVector4f)_mm_unpacklo_ps(
                                                    _mm_unpacklo_ps(
                                                      (__m128)LODWORD(pivot->x),
                                                      (__m128)LODWORD(pivot->z)),
                                                    _mm_unpacklo_ps(
                                                      (__m128)LODWORD(pivot->y),
                                                      (__m128)(unsigned int)FLOAT_1_0));
  hkVector4f::setTransformedPos(&pivota, &body1->m_motion.m_motionState.m_transform, (hkVector4f *)((char *)&v72 + 8));
  v73 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)*retaddr, (__m128)retaddr[2]),
          _mm_unpacklo_ps((__m128)retaddr[1], (__m128)0i64));
  hkVector4f::setRotatedDir(
    (hkVector4f *)&axisIn,
    (hkMatrix3f *)&v8->m_motion.m_motionState.m_transform.m_rotation.m_col0,
    (hkVector4f *)&v73);
  if ( *(float *)&v77 == -1.0 || v78 == -1.0 )
  {
    v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v51 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v50[11] + 8i64))(
                                      v50[11],
                                      224i64);
    v75 = (hkpRigidBody *)v51;
    if ( v51 )
    {
      hkpHingeConstraintData::hkpHingeConstraintData(v51);
      v53 = v52;
    }
    else
    {
      v53 = 0i64;
    }
    hkpHingeConstraintData::setInWorldSpace(
      v53,
      &v8->m_motion.m_motionState.m_transform,
      (hkTransformf *)&axisIn.m256i_u64[2],
      &pivota,
      (hkVector4f *)&axisIn);
    if ( limitMin < 1.0 )
    {
      v54 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v55 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v54[11] + 8i64))(
                                            v54[11],
                                            80i64);
      v75 = (hkpRigidBody *)v55;
      if ( v55 )
      {
        hkpMalleableConstraintData::hkpMalleableConstraintData(v55, (hkpConstraintData *)&v53->vfptr);
        v57 = v56;
      }
      else
      {
        v57 = 0i64;
      }
      hkpMalleableConstraintData::setStrength(v57, limitMin);
      hkReferencedObject::removeReference((hkReferencedObject *)&v53->vfptr);
      v53 = (hkpHingeConstraintData *)v57;
    }
    if ( limitMax > 0.0 )
    {
      v58 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v59 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v58[11] + 8i64))(
                                            v58[11],
                                            96i64);
      v75 = (hkpRigidBody *)v59;
      if ( v59 )
      {
        hkpBreakableConstraintData::hkpBreakableConstraintData(v59, (hkpConstraintData *)&v53->vfptr);
        v61 = v60;
      }
      else
      {
        v61 = 0i64;
      }
      v61->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad.m128_f32[3] = limitMax;
      hkReferencedObject::removeReference((hkReferencedObject *)&v53->vfptr);
      v53 = v61;
    }
    v62 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v63 = ++*(_BYTE *)(v62 + 80);
    v64 = v63;
    *(_DWORD *)(v62 + 4 * v64) = 3;
    *(_QWORD *)(v62 + 8 * v64 + 16) = "hkpConstraintInstance";
    *(_QWORD *)(v62 + 8 * v64 + 48) = 0i64;
    v65 = *(_BYTE *)(v62 + 81);
    if ( v63 > v65 )
      v65 = v63;
    *(_BYTE *)(v62 + 81) = v65;
    v66 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v67 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v66[11] + 8i64))(
                                     v66[11],
                                     112i64);
    v75 = (hkpRigidBody *)v67;
    if ( v67 )
    {
      hkpConstraintInstance::hkpConstraintInstance(
        v67,
        (hkpEntity *)&v8->vfptr,
        (hkpEntity *)&v7->vfptr,
        (hkpConstraintData *)&v53->vfptr,
        PRIORITY_PSI);
      v34 = v68;
    }
    else
    {
      v34 = 0i64;
    }
    v69 = *(_BYTE *)(v62 + 80);
    if ( v69 > 0 )
    {
      *(_BYTE *)(v62 + 80) = v69 - 1;
    }
    else
    {
      *(_BYTE *)(v62 + 80) = 0;
      *(_DWORD *)v62 = 3;
      *(_QWORD *)(v62 + 16) = 0i64;
      *(_QWORD *)(v62 + 48) = 0i64;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v53->vfptr);
    return v34;
  }
  v11 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v12 = ++*(_BYTE *)(v11 + 80);
  v13 = v12;
  *(_DWORD *)(v11 + 4 * v13) = 3;
  *(_QWORD *)(v11 + 8 * v13 + 16) = "hkpLimitedHingeConstraintData";
  *(_QWORD *)(v11 + 8 * v13 + 48) = 0i64;
  v14 = *(_BYTE *)(v11 + 81);
  if ( v12 > v14 )
    v14 = v12;
  *(_BYTE *)(v11 + 81) = v14;
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                           v15[11],
                                           304i64);
  retaddr = (unsigned int *)v16;
  if ( v16 )
  {
    hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v16);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = *(_BYTE *)(v11 + 80);
  if ( v19 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v19 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkpLimitedHingeConstraintData::setInWorldSpace(
    v18,
    &v8->m_motion.m_motionState.m_transform,
    (hkTransformf *)&axisIn.m256i_u64[2],
    &pivota,
    (hkVector4f *)&axisIn);
  v18->m_atoms.m_angLimit.m_minAngle = (float)(*(float *)&v77 * 3.1415927) * 0.0055555557;
  v18->m_atoms.m_angLimit.m_maxAngle = (float)(v78 * 3.1415927) * 0.0055555557;
  v20 = (hkpMalleableConstraintData *)v18;
  if ( limitMin < 1.0 )
  {
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                          v21[11],
                                          80i64);
    retaddr = (unsigned int *)v22;
    if ( v22 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v22, (hkpConstraintData *)&v18->vfptr);
      v20 = v23;
    }
    else
    {
      v20 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v20, limitMin);
    hkReferencedObject::removeReference((hkReferencedObject *)&v18->vfptr);
  }
  if ( limitMax > 0.0 && !v79 )
  {
    v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(
                                          v24[11],
                                          96i64);
    retaddr = (unsigned int *)v25;
    if ( v25 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v25, (hkpConstraintData *)&v20->vfptr);
      v27 = v26;
    }
    else
    {
      v27 = 0i64;
    }
    *(float *)(v27 + 76) = limitMax;
    hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
    v20 = (hkpMalleableConstraintData *)v27;
    v8 = v75;
  }
  v28 = ++*(_BYTE *)(v11 + 80);
  v29 = v28;
  *(_DWORD *)(v11 + 4 * v29) = 3;
  *(_QWORD *)(v11 + 8 * v29 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v11 + 8 * v29 + 48) = 0i64;
  v30 = *(_BYTE *)(v11 + 81);
  if ( v28 > v30 )
    v30 = v28;
  *(_BYTE *)(v11 + 81) = v30;
  v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v31[11] + 8i64))(
                                   v31[11],
                                   112i64);
  v75 = (hkpRigidBody *)v32;
  if ( v32 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v32,
      (hkpEntity *)&v8->vfptr,
      (hkpEntity *)&v7->vfptr,
      (hkpConstraintData *)&v20->vfptr,
      PRIORITY_PSI);
    v34 = v33;
  }
  else
  {
    v34 = 0i64;
  }
  v35 = *(_BYTE *)(v11 + 80);
  if ( v35 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v35 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
  if ( !v79 )
    return v34;
  v18->m_atoms.m_angMotor.m_targetAngle = (float)(*(float *)&axis * 3.1415927) * 0.0055555557;
  v36 = ++*(_BYTE *)(v11 + 80);
  v37 = v36;
  *(_DWORD *)(v11 + 4 * v37) = 3;
  *(_QWORD *)(v11 + 8 * v37 + 16) = "hkpPositionConstraintMotor";
  *(_QWORD *)(v11 + 8 * v37 + 48) = 0i64;
  v38 = *(_BYTE *)(v11 + 81);
  if ( v36 > v38 )
    v38 = v36;
  *(_BYTE *)(v11 + 81) = v38;
  v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v40 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v39[11] + 8i64))(
                                        v39[11],
                                        48i64);
  v75 = (hkpRigidBody *)v40;
  if ( v40 )
  {
    hkpPositionConstraintMotor::hkpPositionConstraintMotor(v40, 0.0);
    v42 = v41;
  }
  else
  {
    v42 = 0i64;
  }
  *(_DWORD *)(v42 + 24) = v80 ^ _xmm[0];
  *(_DWORD *)(v42 + 28) = v80;
  v43 = *(_BYTE *)(v11 + 80);
  if ( v43 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v43 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  v44 = ++*(_BYTE *)(v11 + 80);
  v45 = v44;
  *(_DWORD *)(v11 + 4 * v45) = 3;
  *(_QWORD *)(v11 + 8 * v45 + 16) = "poweredConstraint";
  *(_QWORD *)(v11 + 8 * v45 + 48) = 0i64;
  v46 = *(_BYTE *)(v11 + 81);
  if ( v44 > v46 )
    v46 = v44;
  *(_BYTE *)(v11 + 81) = v46;
  v47 = hkpConstraintUtils::convertToPowered(v34, (hkpConstraintMotor *)v42, (hkBool)1);
  v48 = *(_BYTE *)(v11 + 80);
  if ( v48 > 0 )
  {
    *(_BYTE *)(v11 + 80) = v48 - 1;
  }
  else
  {
    *(_BYTE *)(v11 + 80) = 0;
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v34->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)v42);
  return v47;
}

// File Line: 490
// RVA: 0xA5B40
hkpConstraintInstance *__fastcall UFG::CreateRagdollConstraint(hkpRigidBody *parent, hkpRigidBody *child, UFG::qSymbol *name, UFG::qVector3 *pivot, UFG::qVector3 *twistAxis, UFG::qVector3 *planeAxis, float planeMin, float planeMax, float twistMin)
{
  hkpRigidBody *v9; // r14
  hkpRigidBody *v10; // r15
  hkVector4f b; // ST28_16
  signed __int64 v12; // rbx
  char v13; // dl
  __int64 v14; // rax
  char v15; // cl
  _QWORD **v16; // rax
  hkpRagdollConstraintData *v17; // rax
  hkpRagdollConstraintData *v18; // rax
  hkpRagdollConstraintData *v19; // rdi
  char v20; // al
  _QWORD **v21; // rax
  hkpBreakableConstraintData *v22; // rax
  hkpRagdollConstraintData *v23; // rax
  hkpRagdollConstraintData *v24; // rsi
  char v25; // dl
  __int64 v26; // rax
  char v27; // cl
  _QWORD **v28; // rax
  hkpConstraintInstance *v29; // rax
  __int64 v30; // rax
  __int64 v31; // rsi
  char v32; // al
  hkVector4f array; // [rsp+38h] [rbp-69h]
  hkVector4f v35; // [rsp+48h] [rbp-59h]
  hkVector4f planeAxisW; // [rsp+58h] [rbp-49h]
  hkVector4f twistAxisW; // [rsp+68h] [rbp-39h]
  hkVector4f pivota; // [rsp+78h] [rbp-29h]
  __int64 v39; // [rsp+A0h] [rbp-1h]
  unsigned int *retaddr; // [rsp+F8h] [rbp+57h]
  unsigned int *v41; // [rsp+100h] [rbp+5Fh]
  float v42; // [rsp+108h] [rbp+67h]
  float v43; // [rsp+110h] [rbp+6Fh]
  float v44; // [rsp+118h] [rbp+77h]

  v9 = child;
  v10 = parent;
  b.m_quad = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)LODWORD(pivot->x), (__m128)LODWORD(pivot->z)),
               _mm_unpacklo_ps((__m128)LODWORD(pivot->y), (__m128)(unsigned int)FLOAT_1_0));
  hkVector4f::setTransformedPos(
    (hkVector4f *)&v39,
    &child->m_motion.m_motionState.m_transform,
    (hkVector4f *)((char *)&v35 + 8));
  array.m_quad = _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)*retaddr, (__m128)retaddr[2]),
                   _mm_unpacklo_ps((__m128)retaddr[1], (__m128)0i64));
  hkVector4f::setRotatedDir(
    &twistAxisW,
    (hkMatrix3f *)&v10->m_motion.m_motionState.m_transform.m_rotation.m_col0,
    &array);
  v35.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)*v41, (__m128)v41[2]),
                 _mm_unpacklo_ps((__m128)v41[1], (__m128)0i64));
  hkVector4f::setRotatedDir(&planeAxisW, (hkMatrix3f *)&v10->m_motion.m_motionState.m_transform.m_rotation.m_col0, &v35);
  v12 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v13 = ++*(_BYTE *)(v12 + 80);
  v14 = v13;
  *(_DWORD *)(v12 + 4 * v14) = 3;
  *(_QWORD *)(v12 + 8 * v14 + 16) = "hkpRagdollConstraintData";
  *(_QWORD *)(v12 + 8 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v12 + 81);
  if ( v13 > v15 )
    v15 = v13;
  *(_BYTE *)(v12 + 81) = v15;
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(
                                      v16[11],
                                      416i64);
  retaddr = (unsigned int *)v17;
  if ( v17 )
  {
    hkpRagdollConstraintData::hkpRagdollConstraintData(v17);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v20 = *(_BYTE *)(v12 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v12 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v12 + 80) = 0;
    *(_DWORD *)v12 = 3;
    *(_QWORD *)(v12 + 16) = 0i64;
    *(_QWORD *)(v12 + 48) = 0i64;
  }
  hkpRagdollConstraintData::setInWorldSpace(
    v19,
    &v9->m_motion.m_motionState.m_transform,
    &v10->m_motion.m_motionState.m_transform,
    &pivota,
    &twistAxisW,
    &planeAxisW);
  v19->m_atoms.m_planesLimit.m_minAngle = (float)(v42 * 3.1415927) * 0.0055555557;
  v19->m_atoms.m_planesLimit.m_maxAngle = (float)(v43 * 3.1415927) * 0.0055555557;
  v19->m_atoms.m_twistLimit.m_minAngle = (float)(v44 * 3.1415927) * 0.0055555557;
  v19->m_atoms.m_twistLimit.m_maxAngle = (float)(*(float *)&twistAxis * 3.1415927) * 0.0055555557;
  v19->m_atoms.m_coneLimit.m_maxAngle = (float)(*(float *)&planeAxis * 3.1415927) * 0.0055555557;
  hkpRagdollConstraintData::setMaxFrictionTorque(v19, planeMin);
  if ( twistMin > 0.0 )
  {
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                          v21[11],
                                          96i64);
    retaddr = (unsigned int *)v22;
    if ( v22 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v22, (hkpConstraintData *)&v19->vfptr);
      v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    v24->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad.m128_f32[3] = twistMin;
    hkReferencedObject::removeReference((hkReferencedObject *)&v19->vfptr);
    v19 = v24;
  }
  v25 = ++*(_BYTE *)(v12 + 80);
  v26 = v25;
  *(_DWORD *)(v12 + 4 * v26) = 3;
  *(_QWORD *)(v12 + 8 * v26 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v12 + 8 * v26 + 48) = 0i64;
  v27 = *(_BYTE *)(v12 + 81);
  if ( v25 > v27 )
    v27 = v25;
  *(_BYTE *)(v12 + 81) = v27;
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(
                                   v28[11],
                                   112i64);
  retaddr = (unsigned int *)v29;
  if ( v29 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v29,
      (hkpEntity *)&v9->vfptr,
      (hkpEntity *)&v10->vfptr,
      (hkpConstraintData *)&v19->vfptr,
      PRIORITY_PSI);
    v31 = v30;
  }
  else
  {
    v31 = 0i64;
  }
  v32 = *(_BYTE *)(v12 + 80);
  if ( v32 > 0 )
  {
    *(_BYTE *)(v12 + 80) = v32 - 1;
  }
  else
  {
    *(_BYTE *)(v12 + 80) = 0;
    *(_DWORD *)v12 = 3;
    *(_QWORD *)(v12 + 16) = 0i64;
    *(_QWORD *)(v12 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v19->vfptr);
  array.m_quad.m128_u64[0] = 0i64;
  array.m_quad.m128_u64[1] = 0x8000000000000000i64;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
  *(_QWORD *)(array.m_quad.m128_u64[0] + 8i64 * array.m_quad.m128_i32[2]) = v31;
  ++array.m_quad.m128_i32[2];
  hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
    (hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *)&array,
    0);
  array.m_quad.m128_i32[2] = 0;
  if ( array.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)array.m_quad.m128_u64[0],
      8 * array.m_quad.m128_i32[3]);
  return (hkpConstraintInstance *)v31;
}

// File Line: 542
// RVA: 0xA4B60
hkpConstraintInstance *__fastcall UFG::CreateFixedConstraint(hkpRigidBody *body1, hkpRigidBody *body2, UFG::qSymbol *name, float strength, float breakingStrength)
{
  float v5; // xmm6_4
  hkpRigidBody *v6; // rsi
  hkpRigidBody *v7; // r14
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm3
  signed __int64 v13; // rbx
  char v14; // dl
  __int64 v15; // rax
  char v16; // cl
  _QWORD **v17; // rax
  hkpFixedConstraintData *v18; // rax
  hkpFixedConstraintData *v19; // rax
  hkpFixedConstraintData *v20; // rdi
  char v21; // al
  _QWORD **v22; // rax
  hkpMalleableConstraintData *v23; // rax
  hkpMalleableConstraintData *v24; // rax
  hkpMalleableConstraintData *v25; // rbp
  _QWORD **v26; // rax
  hkpBreakableConstraintData *v27; // rax
  hkpFixedConstraintData *v28; // rax
  hkpFixedConstraintData *v29; // rbp
  char v30; // dl
  __int64 v31; // rax
  char v32; // cl
  _QWORD **v33; // rax
  hkpConstraintInstance *v34; // rax
  __int64 v35; // rax
  __int64 v36; // rsi
  char v37; // al
  hkTransformf bodyBTransform; // [rsp+30h] [rbp-B8h]
  __int64 v40; // [rsp+70h] [rbp-78h]
  hkTransformf pivot; // [rsp+80h] [rbp-68h]

  v40 = -2i64;
  v5 = strength;
  v6 = body2;
  v7 = body1;
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
  v15 = v14;
  *(_DWORD *)(v13 + 4 * v15) = 3;
  *(_QWORD *)(v13 + 8 * v15 + 16) = "hkpFixedConstraintData";
  *(_QWORD *)(v13 + 8 * v15 + 48) = 0i64;
  v16 = *(_BYTE *)(v13 + 81);
  if ( v14 > v16 )
    v16 = v14;
  *(_BYTE *)(v13 + 81) = v16;
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkpFixedConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(
                                    v17[11],
                                    224i64);
  if ( v18 )
  {
    hkpFixedConstraintData::hkpFixedConstraintData(v18);
    v20 = v19;
  }
  else
  {
    v20 = 0i64;
  }
  v21 = *(_BYTE *)(v13 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
  hkpFixedConstraintData::setInWorldSpace(v20, &v7->m_motion.m_motionState.m_transform, &bodyBTransform, &pivot);
  if ( v5 < 1.0 )
  {
    v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                          v22[11],
                                          80i64);
    if ( v23 )
    {
      hkpMalleableConstraintData::hkpMalleableConstraintData(v23, (hkpConstraintData *)&v20->vfptr);
      v25 = v24;
    }
    else
    {
      v25 = 0i64;
    }
    hkpMalleableConstraintData::setStrength(v25, v5);
    hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
    v20 = (hkpFixedConstraintData *)v25;
  }
  if ( breakingStrength > 0.0 )
  {
    v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v27 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(
                                          v26[11],
                                          96i64);
    if ( v27 )
    {
      hkpBreakableConstraintData::hkpBreakableConstraintData(v27, (hkpConstraintData *)&v20->vfptr);
      v29 = v28;
    }
    else
    {
      v29 = 0i64;
    }
    v29->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad.m128_f32[3] = breakingStrength;
    v29->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad.m128_i16[0] = 257;
    hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
    v20 = v29;
  }
  v30 = ++*(_BYTE *)(v13 + 80);
  v31 = v30;
  *(_DWORD *)(v13 + 4 * v31) = 3;
  *(_QWORD *)(v13 + 8 * v31 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v13 + 8 * v31 + 48) = 0i64;
  v32 = *(_BYTE *)(v13 + 81);
  if ( v30 > v32 )
    v32 = v30;
  *(_BYTE *)(v13 + 81) = v32;
  v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v34 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v33[11] + 8i64))(
                                   v33[11],
                                   112i64);
  if ( v34 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v34,
      (hkpEntity *)&v7->vfptr,
      (hkpEntity *)&v6->vfptr,
      (hkpConstraintData *)&v20->vfptr,
      PRIORITY_PSI);
    v36 = v35;
  }
  else
  {
    v36 = 0i64;
  }
  v37 = *(_BYTE *)(v13 + 80);
  if ( v37 > 0 )
  {
    *(_BYTE *)(v13 + 80) = v37 - 1;
  }
  else
  {
    *(_BYTE *)(v13 + 80) = 0;
    *(_DWORD *)v13 = 3;
    *(_QWORD *)(v13 + 16) = 0i64;
    *(_QWORD *)(v13 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
  return (hkpConstraintInstance *)v36;
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
  char v6; // bl
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
  float v19; // xmm2_4
  float v20; // xmm1_4
  hkVector4f pivotAinW; // [rsp+30h] [rbp-98h]
  hkVector4f pivotBinW; // [rsp+40h] [rbp-88h]
  hkVector4f *v23; // [rsp+D0h] [rbp+8h]
  hkBool result; // [rsp+D8h] [rbp+10h]
  hkBool v25; // [rsp+E0h] [rbp+18h]
  hkBool v26; // [rsp+E8h] [rbp+20h]

  v23 = location;
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
        if ( hkpConstraintInstance::isEnabled((hkpConstraintInstance *)i[5], &result)->m_bool )
        {
          if ( v3->m_owner )
          {
            v4 = (__m128 *)v3->m_entities[0];
            v5 = v3->m_entities[1];
            v6 = 0;
            if ( v4 )
            {
              if ( hkpEntity::isActive(v3->m_entities[0], &v25)->m_bool )
              {
                v6 = 0;
                if ( v4[1].m128_u64[0] )
                  v6 = 1;
              }
            }
            if ( v5 && hkpEntity::isActive(v5, &v26)->m_bool && v5->m_world || v6 )
            {
              hkpConstraintInstance::getPivotsInWorld(v3, &pivotAinW, &pivotBinW);
              v7 = _mm_sub_ps(pivotAinW.m_quad, v23->m_quad);
              v8 = _mm_mul_ps(v7, v7);
              v9 = _mm_add_ps(
                     _mm_shuffle_ps(v8, v8, 170),
                     _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)));
              v10 = _mm_rsqrt_ps(v9);
              if ( COERCE_FLOAT(
                     _mm_andnot_ps(
                       _mm_cmpleps(v9, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                           _mm_mul_ps(*(__m128 *)_xmm, v10)),
                         v9))) <= *((float *)&v2[6].mNext + 1) )
              {
                v11 = _mm_sub_ps(v4[35], v5->m_motion.m_linearVelocity.m_quad);
                v12 = _mm_mul_ps(v11, v11);
                v13 = _mm_add_ps(
                        _mm_shuffle_ps(v12, v12, 170),
                        _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)));
                v14 = _mm_rsqrt_ps(v13);
                LODWORD(v15) = (unsigned __int128)_mm_andnot_ps(
                                                    _mm_cmpleps(v13, (__m128)0i64),
                                                    _mm_mul_ps(
                                                      _mm_mul_ps(
                                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                                                        _mm_mul_ps(*(__m128 *)_xmm, v14)),
                                                      v13));
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
                  v19 = pivotAinW.m_quad.m128_f32[2];
                  v20 = pivotAinW.m_quad.m128_f32[1];
                  *(_DWORD *)(v18 + 84) = pivotAinW.m_quad.m128_i32[0];
                  *(float *)(v18 + 88) = v20;
                  *(float *)(v18 + 92) = v19;
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

