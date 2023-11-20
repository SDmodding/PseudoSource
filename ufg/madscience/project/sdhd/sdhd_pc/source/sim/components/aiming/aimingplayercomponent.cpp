// File Line: 124
// RVA: 0x1543D40
__int64 dynamic_initializer_for__UFG::AimingPlayerComponent::s_AimingPlayerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AimingPlayerComponent::s_AimingPlayerComponentList__);
}

// File Line: 125
// RVA: 0x532660
signed __int64 __fastcall UFG::AimingPlayerComponent::GetTypeSize(UFG::AimingPlayerComponent *this)
{
  return 920i64;
}

// File Line: 207
// RVA: 0x5354A0
bool __fastcall UFG::AimingPlayerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentAimingPlayer.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 213
// RVA: 0x5442E0
UFG::SimComponent *__fastcall UFG::AimingPlayerComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x398ui64, "AimingPlayerComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::AimingPlayerComponent::AimingPlayerComponent((UFG::AimingPlayerComponent *)v3, v1->m_NameUID, v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  if ( (v7->m_Flags >> 14) & 1 )
    v8 = 47;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 219
// RVA: 0x1544520
__int64 UFG::_dynamic_initializer_for__AimTargetPositionTransform_Hash__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimTargetPositionTransform", 0xFFFFFFFF);
  UFG::AimTargetPositionTransform_Hash = result;
  return result;
}

// File Line: 269
// RVA: 0x5157C0
void __fastcall UFG::AimingPlayerComponent::AimingPlayerComponent(UFG::AimingPlayerComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::qPropertySet *v4; // rsi
  UFG::AimingPlayerComponent *v5; // r15
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v6; // rdi
  UFG::SimComponent *v7; // rbp
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v20; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v21; // rcx
  const char *v22; // rax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0> *v33; // rax
  UFG::qList<AimingFreeAimConeClampTask,AimingFreeAimConeClampList,0,0> *v34; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v35; // r14
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v36; // rbx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v37; // rax
  Illusion::Target *v38; // rax
  float v39; // xmm2_4
  float v40; // xmm1_4
  float *v41; // rax
  __int64 *v42; // rcx
  float *v43; // rax
  __int64 *v44; // rcx
  float *v45; // rax
  __int64 *v46; // rcx
  UFG::qMemoryPool *v47; // rax
  UFG::allocator::free_link *v48; // rax
  UFG::SimObject *v49; // rax
  UFG::SimObject *v50; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v51; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v52; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v53; // rax
  UFG::qMemoryPool *v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::SimComponent *v56; // rax
  UFG::SimObject *v57; // rdx
  unsigned __int16 v58; // cx
  unsigned int v59; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v60; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v61; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v62; // rax
  UFG::allocator::free_link *v63; // [rsp+30h] [rbp-68h]
  UFG::qSymbol result; // [rsp+38h] [rbp-60h]
  UFG::qSymbol name; // [rsp+3Ch] [rbp-5Ch]
  __int64 v66; // [rsp+40h] [rbp-58h]
  UFG::SimObjectModifier v67; // [rsp+48h] [rbp-50h]

  v66 = -2i64;
  v4 = properties;
  v5 = this;
  UFG::AimingBaseComponent::AimingBaseComponent(
    (UFG::AimingBaseComponent *)&this->vfptr,
    name_uid,
    properties,
    startSuspended);
  v6 = (UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::SimComponent};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0>(&v5->m_pTSPPC);
  *(_DWORD *)&v5->m_bFocusTargetProbed = 0;
  *(_WORD *)&v5->m_bSupressReticle = 0;
  v5->m_bAimingControlsCamera = 0;
  v5->m_fBlendedReticleSize = -1.0;
  v5->m_fBlendedReticleRadius = -1.0;
  v5->m_fOverrideReticleSize = -1.0;
  v7 = 0i64;
  *(_QWORD *)&v5->m_fAxisXSpeed = 0i64;
  *(_QWORD *)&v5->m_fDampenedAxisXSpeed = 0i64;
  v5->m_fAimObstructedDuration = 0.0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v5->m_vFreeAimLastFramePosition.x = UFG::qVector3::msZero.x;
  v5->m_vFreeAimLastFramePosition.y = v8;
  v5->m_vFreeAimLastFramePosition.z = v9;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  v5->m_vFreeAimCastOrigin.x = UFG::qVector3::msZero.x;
  v5->m_vFreeAimCastOrigin.y = v10;
  v5->m_vFreeAimCastOrigin.z = v11;
  v5->m_bFreeAimRootDirty = 1;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v5->m_vFreeAimRootPosSS.x = UFG::qVector3::msZero.x;
  v5->m_vFreeAimRootPosSS.y = v12;
  v5->m_vFreeAimRootPosSS.z = v13;
  v5->m_qFreeAimRootOriSS.x = UFG::qQuaternion::msUnity.x;
  v5->m_qFreeAimRootOriSS.y = UFG::qQuaternion::msUnity.y;
  v5->m_qFreeAimRootOriSS.z = UFG::qQuaternion::msUnity.z;
  v5->m_qFreeAimRootOriSS.w = UFG::qQuaternion::msUnity.w;
  v5->m_bFreeAimRootMovementLock = 0;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  v5->m_vFreeAimOrigin.x = UFG::qVector3::msZero.x;
  v5->m_vFreeAimOrigin.y = v14;
  v5->m_vFreeAimOrigin.z = v15;
  v16 = UFG::qVector3::msAxisX.y;
  v17 = UFG::qVector3::msAxisX.z;
  v5->m_vFreeAimIntention.x = UFG::qVector3::msAxisX.x;
  v5->m_vFreeAimIntention.y = v16;
  v5->m_vFreeAimIntention.z = v17;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  v5->m_vFreeAimTargetPosition.x = UFG::qVector3::msZero.x;
  v5->m_vFreeAimTargetPosition.y = v18;
  v5->m_vFreeAimTargetPosition.z = v19;
  v20 = &v5->m_FreeAimSimObject;
  v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  v5->m_FreeAimSimObject.m_pPointer = 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v5->m_FreeAimPhysicsObjectProperties.mPrev);
  v22 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v21);
  v5->m_FreeAimPhysicsObjectProperties.mTypeUID = UFG::qStringHash64(v22, 0xFFFFFFFFFFFFFFFFui64);
  *(_QWORD *)&v5->m_fReticleBlend = 1065353216i64;
  v23 = UFG::qVector3::msZero.y;
  v24 = UFG::qVector3::msZero.z;
  v5->m_vFocusTargetSegA.x = UFG::qVector3::msZero.x;
  v5->m_vFocusTargetSegA.y = v23;
  v5->m_vFocusTargetSegA.z = v24;
  v25 = UFG::qVector3::msZero.y;
  v26 = UFG::qVector3::msZero.z;
  v5->m_vFocusTargetSegB.x = UFG::qVector3::msZero.x;
  v5->m_vFocusTargetSegB.y = v25;
  v5->m_vFocusTargetSegB.z = v26;
  v27 = UFG::qVector3::msZero.y;
  v28 = UFG::qVector3::msZero.z;
  v5->m_vFocusTargetClosestPos.x = UFG::qVector3::msZero.x;
  v5->m_vFocusTargetClosestPos.y = v27;
  v5->m_vFocusTargetClosestPos.z = v28;
  v29 = UFG::qVector3::msZero.y;
  v30 = UFG::qVector3::msZero.z;
  v5->m_vFocusTargetSegClosestPos.x = UFG::qVector3::msZero.x;
  v5->m_vFocusTargetSegClosestPos.y = v29;
  v5->m_vFocusTargetSegClosestPos.z = v30;
  v5->m_fFocusTargetRadius = 0.0;
  v5->m_fFocusTargetDistanceSeg = 3.4028235e38;
  v5->m_bResetSoftLockOffset = 0;
  v5->m_eSoftLockType = 0;
  v31 = UFG::qVector3::msZero.y;
  v32 = UFG::qVector3::msZero.z;
  v5->m_vSoftLockOffset.x = UFG::qVector3::msZero.x;
  v5->m_vSoftLockOffset.y = v31;
  v5->m_vSoftLockOffset.z = v32;
  v5->m_fFreeAimSpeedModifier = 1.0;
  *(_QWORD *)&v5->m_fInterpolatedFreeAimConeClamp = 1078530011i64;
  v33 = &v5->m_AimingSoftLockTaskList;
  v33->mNode.mPrev = &v33->mNode;
  v33->mNode.mNext = &v33->mNode;
  v34 = &v5->m_AimingFreeAimConeClampTaskList;
  v34->mNode.mPrev = &v34->mNode;
  v34->mNode.mNext = &v34->mNode;
  v35 = &v5->m_pAimTargetPositionSimObject;
  v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v35->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  v5->m_pAimTargetPositionSimObject.m_pPointer = 0i64;
  v36 = &v5->m_pAimTargetPositionTNC;
  v63 = (UFG::allocator::free_link *)v36;
  v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  v5->m_pAimTargetPositionTNC.m_pPointer = 0i64;
  v5->m_eAimBlendMode = 0;
  v37 = UFG::AimingPlayerComponent::s_AimingPlayerComponentList.mNode.mPrev;
  UFG::AimingPlayerComponent::s_AimingPlayerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *)&v5->mPrev;
  v6->mPrev = v37;
  v5->mNext = (UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *)&UFG::AimingPlayerComponent::s_AimingPlayerComponentList;
  UFG::AimingPlayerComponent::s_AimingPlayerComponentList.mNode.mPrev = (UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::AimingPlayerComponent::_AimingPlayerComponentTypeUID,
    "AimingPlayerComponent");
  v38 = Render::GetBackBufferTarget();
  v39 = (float)v38->mHeight * 0.5;
  v40 = (float)v38->mWidth * 0.5;
  v5->m_vReticleLockedOnCoordsScreen.x = v40;
  v5->m_vReticleLockedOnCoordsScreen.y = v39;
  v5->m_vReticleBlendedCoordsScreen.x = v40;
  v5->m_vReticleBlendedCoordsScreen.y = v39;
  *((_BYTE *)v5 + 848) &= 0xFEu;
  *(float *)&v63 = FLOAT_20_0;
  v41 = UFG::qPropertySet::Get<float>(v4, (UFG::qSymbol *)&PhysicsSym_UnobscuredAimCheckDistance.mUID, DEPTH_RECURSE);
  v42 = (__int64 *)&v63;
  if ( v41 )
    v42 = (__int64 *)v41;
  v5->m_fUnobscuredAimCheckDistance = *(float *)v42;
  *(float *)&v63 = FLOAT_1_5;
  v43 = UFG::qPropertySet::Get<float>(
          v4,
          (UFG::qSymbol *)&PhysicsSym_UnobscuredAimTargetPositionPadDistance.mUID,
          DEPTH_RECURSE);
  v44 = (__int64 *)&v63;
  if ( v43 )
    v44 = (__int64 *)v43;
  v5->m_fUnobscuredAimTargetPositionPadDistance = *(float *)v44;
  *(float *)&v63 = FLOAT_0_1;
  v45 = UFG::qPropertySet::Get<float>(
          v4,
          (UFG::qSymbol *)&PhysicsSym_UnobscuredAimNewPositionPadDistance.mUID,
          DEPTH_RECURSE);
  v46 = (__int64 *)&v63;
  if ( v45 )
    v46 = (__int64 *)v45;
  v5->m_fUnobscuredAimNewPositionPadDistance = *(float *)v46;
  UFG::qSymbol::create_from_string(&result, "AimingPlayerComponent_AimTargetPosition");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &name, &result);
  v47 = UFG::GetSimulationMemoryPool();
  v48 = UFG::qMemoryPool::Allocate(v47, 0x80ui64, "AimingPlayerComponent.AimTargetPosition", 0i64, 1u);
  v63 = v48;
  if ( v48 )
  {
    UFG::SimObject::SimObject((UFG::SimObject *)v48, &name);
    v50 = v49;
  }
  else
  {
    v50 = 0i64;
  }
  if ( v5->m_pAimTargetPositionSimObject.m_pPointer )
  {
    v51 = v35->mPrev;
    v52 = v5->m_pAimTargetPositionSimObject.mNext;
    v51->mNext = v52;
    v52->mPrev = v51;
    v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
    v5->m_pAimTargetPositionSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->m_pAimTargetPositionSimObject.mPrev;
  }
  v5->m_pAimTargetPositionSimObject.m_pPointer = v50;
  if ( v50 )
  {
    v53 = v50->m_SafePointerList.mNode.mPrev;
    v53->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
    v35->mPrev = v53;
    v5->m_pAimTargetPositionSimObject.mNext = &v50->m_SafePointerList.mNode;
    v50->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v35->mPrev;
  }
  v54 = UFG::GetSimulationMemoryPool();
  v55 = UFG::qMemoryPool::Allocate(v54, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  v63 = v55;
  if ( v55 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v55,
      UFG::AimTargetPositionTransform_Hash,
      0i64,
      0);
    v7 = v56;
  }
  UFG::Simulation::TrackSimObject(&UFG::gSim, v5->m_pAimTargetPositionSimObject.m_pPointer);
  v57 = v5->m_pAimTargetPositionSimObject.m_pPointer;
  v58 = v57->m_Flags;
  if ( (v58 >> 14) & 1 )
  {
    v59 = 2;
  }
  else if ( (v58 & 0x8000u) == 0 )
  {
    if ( (v58 >> 13) & 1 )
    {
      v59 = 2;
    }
    else
    {
      v59 = -1;
      if ( (v58 >> 12) & 1 )
        v59 = 1;
    }
  }
  else
  {
    v59 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v67, v57, 1);
  UFG::SimObjectModifier::AttachComponent(&v67, v7, v59);
  UFG::SimObjectModifier::Close(&v67);
  UFG::SimObjectModifier::~SimObjectModifier(&v67);
  if ( v5->m_pAimTargetPositionTNC.m_pPointer )
  {
    v60 = v36->mPrev;
    v61 = v5->m_pAimTargetPositionTNC.mNext;
    v60->mNext = v61;
    v61->mPrev = v60;
    v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    v5->m_pAimTargetPositionTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pAimTargetPositionTNC.mPrev;
  }
  v5->m_pAimTargetPositionTNC.m_pPointer = v7;
  if ( v7 )
  {
    v62 = v7->m_SafePointerList.mNode.mPrev;
    v62->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    v36->mPrev = v62;
    v5->m_pAimTargetPositionTNC.mNext = &v7->m_SafePointerList.mNode;
    v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  }
}

// File Line: 369
// RVA: 0x51AA00
void __fastcall UFG::AimingPlayerComponent::~AimingPlayerComponent(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // rbx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v2; // rdi
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v3; // rcx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v4; // rax
  UFG::SimObject *v5; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v24; // rcx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v25; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::AimingPlayerComponent::s_AimingPlayerComponentpCurrentIterator )
    UFG::AimingPlayerComponent::s_AimingPlayerComponentpCurrentIterator = (UFG::AimingPlayerComponent *)&this->mPrev[-26];
  v2 = (UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->m_pAimTargetPositionSimObject.m_pPointer;
  if ( v5 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v5);
    v6 = &v1->m_pAimTargetPositionSimObject;
    if ( v1->m_pAimTargetPositionSimObject.m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v1->m_pAimTargetPositionSimObject.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v1->m_pAimTargetPositionSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pAimTargetPositionSimObject.mPrev;
    }
    v1->m_pAimTargetPositionSimObject.m_pPointer = 0i64;
  }
  v9 = &v1->m_pAimTargetPositionTNC;
  if ( v1->m_pAimTargetPositionTNC.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v1->m_pAimTargetPositionTNC.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v1->m_pAimTargetPositionTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAimTargetPositionTNC.mPrev;
  }
  v1->m_pAimTargetPositionTNC.m_pPointer = 0i64;
  v12 = v9->mPrev;
  v13 = v1->m_pAimTargetPositionTNC.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->m_pAimTargetPositionTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAimTargetPositionTNC.mPrev;
  v14 = &v1->m_pAimTargetPositionSimObject;
  if ( v1->m_pAimTargetPositionSimObject.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = v1->m_pAimTargetPositionSimObject.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v1->m_pAimTargetPositionSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pAimTargetPositionSimObject.mPrev;
  }
  v1->m_pAimTargetPositionSimObject.m_pPointer = 0i64;
  v17 = v14->mPrev;
  v18 = v1->m_pAimTargetPositionSimObject.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v1->m_pAimTargetPositionSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pAimTargetPositionSimObject.mPrev;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_AimingFreeAimConeClampTaskList);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_AimingSoftLockTaskList);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->m_FreeAimPhysicsObjectProperties.mPrev);
  v19 = &v1->m_FreeAimSimObject;
  if ( v1->m_FreeAimSimObject.m_pPointer )
  {
    v20 = v19->mPrev;
    v21 = v1->m_FreeAimSimObject.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v1->m_FreeAimSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_FreeAimSimObject.mPrev;
  }
  v1->m_FreeAimSimObject.m_pPointer = 0i64;
  v22 = v19->mPrev;
  v23 = v1->m_FreeAimSimObject.mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  v1->m_FreeAimSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_FreeAimSimObject.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTSPPC);
  v24 = v2->mPrev;
  v25 = v2->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::AimingBaseComponent::~AimingBaseComponent((UFG::AimingBaseComponent *)&v1->vfptr);
}

// File Line: 382
// RVA: 0x53D0C0
void __fastcall UFG::AimingPlayerComponent::OnAttach(UFG::AimingPlayerComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v2; // rbp
  UFG::AimingPlayerComponent *v3; // rdi
  unsigned int v4; // eax
  signed int v5; // ebx
  UFG::SimComponent *v6; // rsi
  __int64 v7; // rsi
  signed int v8; // eax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::SimComponent *v14; // rbx
  float v15; // xmm0_4
  float v16; // xmm1_4

  v2 = pSimObject;
  v3 = this;
  v4 = _S59;
  if ( !(_S59 & 1) )
  {
    _S59 |= 1u;
    UFG::qSymbolUC::create_from_string(&symCameraSync01, "CameraSync01");
    atexit(UFG::AimingPlayerComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symCameraSync01__);
    v4 = _S59;
  }
  if ( !(v4 & 2) )
  {
    _S59 = v4 | 2;
    UFG::qSymbolUC::create_from_string(&symSync01_0, "Sync01");
    atexit(UFG::AimingPlayerComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symSync01__);
  }
  UFG::AimingBaseComponent::OnAttach((UFG::AimingBaseComponent *)&v3->vfptr, v2);
  v3->m_bFreeAimRootDirty = 1;
  v5 = -1;
  v3->m_iFreeAimOriginBoneID = -1;
  v3->m_iFreeAimSyncBoneID = -1;
  v6 = v3->m_CharacterAnimationComponent.m_pSimComponent;
  if ( v6 )
  {
    v7 = *(_QWORD *)&v6[2].m_TypeUID;
    if ( v7 )
    {
      if ( *(_QWORD *)(v7 + 440) )
        v8 = Skeleton::GetBoneID(*(Skeleton **)(v7 + 480), symCameraSync01.mUID);
      else
        v8 = -1;
      v3->m_iFreeAimOriginBoneID = v8;
      if ( *(_QWORD *)(v7 + 440) )
        v5 = Skeleton::GetBoneID(*(Skeleton **)(v7 + 480), symSync01_0.mUID);
      v3->m_iFreeAimSyncBoneID = v5;
    }
  }
  v9 = &v3->m_pTSPPC;
  if ( v3->m_pTSPPC.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v3->m_pTSPPC.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v3->m_pTSPPC.m_pSimComponent = 0i64;
LABEL_19:
    v3->m_pTSPPC.m_pSimObject = 0i64;
    v3->m_pTSPPC.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pTSPPC.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_20;
  }
  if ( v3->m_pTSPPC.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *)v3->m_pTSPPC.mNext != &v3->m_pTSPPC) )
  {
    v12 = v9->mPrev;
    v13 = v3->m_pTSPPC.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_19;
  }
LABEL_20:
  v3->m_pTSPPC.m_Changed = 1;
  v3->m_pTSPPC.m_pSimObject = v2;
  v3->m_pTSPPC.m_TypeUID = UFG::TargetingSystemPedPlayerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pTSPPC,
    v2);
  *((_BYTE *)v3 + 848) &= 0xFEu;
  v14 = v3->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_TransformNodeComponent.m_pSimComponent);
  v15 = *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v16 = *(float *)&v14[2].m_BoundComponentHandles.mNode.mNext;
  v3->m_vFreeAimLastFramePosition.x = *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev;
  v3->m_vFreeAimLastFramePosition.y = v15;
  v3->m_vFreeAimLastFramePosition.z = v16;
}

// File Line: 413
// RVA: 0x53FC10
void __fastcall UFG::AimingPlayerComponent::OnDetach(UFG::AimingPlayerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *v1; // r8
  UFG::AimingPlayerComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  v1 = &this->m_pTSPPC;
  v2 = this;
  if ( this->m_pTSPPC.m_pSimComponent )
  {
    v3 = this->m_pTSPPC.mNext;
    v4 = v1->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    this->m_pTSPPC.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pTSPPC.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *)this->m_pTSPPC.mNext != &this->m_pTSPPC) )
  {
    v5 = this->m_pTSPPC.mNext;
    v6 = v1->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  v1->m_Changed = 1;
  UFG::AimingBaseComponent::OnDetach((UFG::AimingBaseComponent *)&v2->vfptr);
}

// File Line: 422
// RVA: 0x576A50
void __fastcall UFG::AimingPlayerComponent::updatePlayerAimDirection(UFG::AimingPlayerComponent *this, const float fDeltaS, UFG::qMatrix44 *matXform)
{
  UFG::AimingPlayerComponent *v3; // rdx
  UFG::SimComponent *v4; // rcx
  float v5; // xmm2_4
  __int64 v6; // rax
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4

  v3 = this;
  v4 = this->m_pTSPPC.m_pSimComponent;
  v5 = fDeltaS;
  if ( (unsigned int)(LODWORD(v4[53].m_pSimObject) - 3) > 1 && LODWORD(v4[53].m_pSimObject) != 2
    || (v6 = *(_QWORD *)&v3->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID) == 0 )
  {
    v3->m_eAimBlendMode = 0;
    goto LABEL_22;
  }
  if ( v4[42].m_BoundComponentHandles.mNode.mPrev )
  {
    if ( v3->m_eAimBlendMode != 3 )
    {
      v7 = *(float *)(*(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8) + 404i64);
      if ( v7 < 0.0 )
        v3->m_fAimTransitionRadPerS = v7;
      v3->m_eAimBlendMode = 3;
      UFG::AimingBaseComponent::updateAimDirection((UFG::AimingBaseComponent *)&v3->vfptr, v5, matXform);
      return;
    }
LABEL_22:
    UFG::AimingBaseComponent::updateAimDirection((UFG::AimingBaseComponent *)&v3->vfptr, fDeltaS, matXform);
    return;
  }
  if ( v3->m_FreeAimSimObject.m_pPointer )
  {
    if ( v3->m_eAimBlendMode == 2 )
      goto LABEL_22;
    v8 = *(float *)(*(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8) + 404i64);
    if ( v8 < 0.0 )
      v3->m_fAimTransitionRadPerS = v8;
    v3->m_eAimBlendMode = 2;
    UFG::AimingBaseComponent::updateAimDirection((UFG::AimingBaseComponent *)&v3->vfptr, v5, matXform);
  }
  else
  {
    if ( v3->m_eAimBlendMode == 1 )
      goto LABEL_22;
    if ( BYTE2(v4[52].m_BoundComponentHandles.mNode.mPrev) )
      v9 = FLOAT_N1_0;
    else
      v9 = *(float *)(*(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8) + 408i64);
    if ( v9 < 0.0 )
      v3->m_fAimTransitionRadPerS = v9;
    v3->m_eAimBlendMode = 1;
    UFG::AimingBaseComponent::updateAimDirection((UFG::AimingBaseComponent *)&v3->vfptr, v5, matXform);
  }
}

// File Line: 485
// RVA: 0x541E70
void __fastcall UFG::AimingPlayerComponent::OnTargetChanged(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // rbx
  UFG::SimComponent *v2; // rcx

  v1 = this;
  v2 = this->m_pTSPPC.m_pSimComponent;
  if ( (unsigned int)(LODWORD(v2[53].m_pSimObject) - 3) > 1 && LODWORD(v2[53].m_pSimObject) != 2 )
    UFG::AimingBaseComponent::OnTargetChanged((UFG::AimingBaseComponent *)&v1->vfptr);
  if ( (unsigned int)(v1->m_eSoftLockType - 2) <= 1 )
    v1->m_eSoftLockType = 0;
}

// File Line: 506
// RVA: 0x558870
void __usercall UFG::AimingPlayerComponent::Update(UFG::AimingPlayerComponent *this@<rcx>, float fDeltaS@<xmm1>, float a3@<xmm0>)
{
  UFG::qMatrix44 *v3; // rbx
  UFG::AimingPlayerComponent *v4; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  float v6; // xmm10_4
  UFG::qMatrix44 *v7; // rsi
  bool v8; // r14
  char v9; // bl
  UFG::SimComponent *v10; // r9
  unsigned __int16 v11; // dx
  unsigned int v12; // er8
  unsigned int v13; // er10
  signed __int64 v14; // rdx
  __int64 v15; // rcx
  char v16; // al
  __int64 v17; // rax
  bool v18; // zf
  char v19; // al
  __int64 v20; // rax
  char v21; // al
  __int64 v22; // rax
  char v23; // al
  UFG::SimComponent *v24; // rcx
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  __m128 v28; // xmm5
  __m128 v29; // xmm2
  float v30; // xmm1_4
  float v31; // xmm5_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  __m128 v34; // xmm2
  float v35; // xmm0_4
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  float v38; // xmm11_4
  float v39; // xmm11_4
  __m128 v40; // xmm12
  float v41; // xmm11_4
  __m128 v42; // xmm8
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  __m128 v46; // xmm9
  float v47; // xmm2_4
  float v48; // xmm8_4
  __m128 v49; // xmm5
  float v50; // xmm3_4
  UFG::TransformNodeComponent *v51; // rcx
  float v52; // xmm0_4
  UFG::qVector3 vAimDirection; // [rsp+18h] [rbp-69h]
  UFG::qMatrix44 m; // [rsp+28h] [rbp-59h]

  v3 = *(UFG::qMatrix44 **)&this->m_Accuracy.m_bEnsureMiss;
  v4 = this;
  UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&this->m_Accuracy.m_bEnsureMiss);
  v5 = v4[-1].m_pAimTargetPositionTNC.mNext;
  v6 = UFG::Metrics::msInstance.mSimTimeUnscaledDelta;
  v7 = v3 + 2;
  v8 = (unsigned int)(LODWORD(v4->m_CharacterOccupantComponent.m_pSimComponent[53].m_pSimObject) - 3) <= 1;
  v9 = 0;
  if ( !v5 )
  {
    v10 = 0i64;
LABEL_20:
    v16 = 0;
    goto LABEL_21;
  }
  v11 = WORD2(v5[4].mNext);
  if ( (v11 >> 14) & 1 )
  {
    v10 = (UFG::SimComponent *)v5[6].mNext[7].mPrev;
  }
  else if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 13) & 1 )
    {
      v10 = (UFG::SimComponent *)v5[6].mNext[6].mPrev;
    }
    else if ( (v11 >> 12) & 1 )
    {
      v12 = (unsigned int)v5[8].mPrev;
      v13 = (unsigned int)v5[6].mPrev;
      if ( v12 >= v13 )
      {
LABEL_15:
        v10 = 0i64;
      }
      else
      {
        v14 = (signed __int64)&v5[6].mNext[v12];
        while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
        {
          ++v12;
          v14 += 16i64;
          if ( v12 >= v13 )
            goto LABEL_15;
        }
        v10 = *(UFG::SimComponent **)v14;
      }
    }
    else
    {
      v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v5, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v10 = (UFG::SimComponent *)v5[6].mNext[7].mPrev;
  }
  if ( !v10 )
    goto LABEL_20;
  v15 = *((_QWORD *)&v10[11].m_SafePointerList.mNode.mPrev
        + ((signed __int64)(signed int)gActionRequest_CameraZoom.m_EnumValue >> 6));
  v16 = 1;
  if ( !_bittest64(&v15, gActionRequest_CameraZoom.m_EnumValue & 0x3F) )
    goto LABEL_20;
LABEL_21:
  BYTE2(v4->mPrev) = v16;
  if ( !v10
    || (v17 = *((_QWORD *)&v10[11].m_SafePointerList.mNode.mPrev
              + ((signed __int64)(signed int)gActionRequest_UseCover.m_EnumValue >> 6)),
        v18 = _bittest64(&v17, gActionRequest_UseCover.m_EnumValue & 0x3F) == 0,
        v19 = 1,
        v18) )
  {
    v19 = 0;
  }
  BYTE3(v4->mPrev) = v19;
  if ( !v10
    || (v20 = *((_QWORD *)&v10[11].m_SafePointerList.mNode.mPrev
              + ((signed __int64)(signed int)gActionRequest_AimingSupressReticle.m_EnumValue >> 6)),
        v18 = _bittest64(&v20, gActionRequest_AimingSupressReticle.m_EnumValue & 0x3F) == 0,
        v21 = 1,
        v18) )
  {
    v21 = 0;
  }
  BYTE4(v4->mPrev) = v21;
  if ( !v10
    || (v22 = *((_QWORD *)&v10[11].m_SafePointerList.mNode.mPrev
              + ((signed __int64)(signed int)gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumValue >> 6)),
        v18 = _bittest64(&v22, gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumValue & 0x3F) == 0,
        v23 = 1,
        v18) )
  {
    v23 = 0;
  }
  BYTE5(v4->mPrev) = v23;
  v24 = v4->m_CharacterOccupantComponent.m_pSimComponent;
  if ( BYTE2(v24[52].m_BoundComponentHandles.mNode.mPrev)
    || (unsigned int)(LODWORD(v24[53].m_pSimObject) - 3) <= 1
    || LODWORD(v24[53].m_pSimObject) == 2 )
  {
    v9 = 1;
  }
  BYTE6(v4->mPrev) = v9;
  UFG::AimingBaseComponent::updateAimOriginPosition(
    (UFG::AimingBaseComponent *)&v4[-1].m_fUnobscuredAimTargetPositionPadDistance,
    v7);
  UFG::AimingPlayerComponent::possiblyResetFreeAimIntention((UFG::AimingPlayerComponent *)((char *)v4 - 64));
  if ( BYTE6(v4->mPrev) )
  {
    UFG::AimingPlayerComponent::updateFreeAimInput((UFG::AimingPlayerComponent *)((char *)v4 - 64), v6);
    UFG::AimingPlayerComponent::updateFreeAimIntention((UFG::AimingPlayerComponent *)((char *)v4 - 64), v6, a3);
  }
  UFG::AimingPlayerComponent::updateFreeAimOrigin((UFG::AimingPlayerComponent *)((char *)v4 - 64), v6);
  UFG::AimingPlayerComponent::updateFreeAimTargetPosition((UFG::AimingPlayerComponent *)((char *)v4 - 64));
  UFG::AimingPlayerComponent::updateTargetDimensions((UFG::AimingPlayerComponent *)((char *)v4 - 64));
  UFG::AimingPlayerComponent::updateSoftLockOffset((UFG::AimingPlayerComponent *)((char *)v4 - 64), v7);
  UFG::AimingPlayerComponent::updateAimIntentionTargetPosition((UFG::AimingPlayerComponent *)((char *)v4 - 64), v7);
  if ( !v8 )
    UFG::AimingBaseComponent::clampAimIntentionTargetPositionDistance((UFG::AimingBaseComponent *)&v4[-1].m_fUnobscuredAimTargetPositionPadDistance);
  UFG::AimingBaseComponent::updateAimIntention(
    (UFG::AimingBaseComponent *)&v4[-1].m_fUnobscuredAimTargetPositionPadDistance,
    v6);
  UFG::AimingBaseComponent::clampAimIntention(
    (UFG::AimingBaseComponent *)&v4[-1].m_fUnobscuredAimTargetPositionPadDistance,
    v7);
  UFG::AimingPlayerComponent::updatePlayerAimDirection((UFG::AimingPlayerComponent *)((char *)v4 - 64), v6, v7);
  UFG::AimingBaseComponent::GetAimDirection(
    (UFG::AimingBaseComponent *)&v4[-1].m_fUnobscuredAimTargetPositionPadDistance,
    &vAimDirection,
    v7);
  v25 = *(float *)&v4->m_TypeUID;
  v26 = (float)(vAimDirection.z * v25) + *(float *)&v4->m_BoundComponentHandles.mNode.mPrev;
  v27 = (float)(v25 * vAimDirection.y) + *((float *)&v4->m_pSimObject + 1);
  *(float *)&v4->vfptr = (float)(vAimDirection.x * v25) + *(float *)&v4->m_pSimObject;
  *(float *)&v4->mPrev = v26;
  *((float *)&v4->vfptr + 1) = v27;
  if ( v4->m_AimingFreeAimConeClampTaskList.mNode.mNext )
  {
    UFG::AimingBaseComponent::GetAimDirection(
      (UFG::AimingBaseComponent *)&v4[-1].m_fUnobscuredAimTargetPositionPadDistance,
      &vAimDirection,
      v7);
    v28 = (__m128)LODWORD(vAimDirection.x);
    v29 = v28;
    v29.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(vAimDirection.y * vAimDirection.y))
                    + (float)(vAimDirection.z * vAimDirection.z);
    if ( v29.m128_f32[0] == 0.0 )
      v30 = 0.0;
    else
      v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
    v31 = vAimDirection.x * v30;
    v32 = vAimDirection.y * v30;
    v33 = vAimDirection.z * v30;
    m.v0.w = 0.0;
    v34 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    m.v0.x = vAimDirection.x * v30;
    m.v0.y = vAimDirection.y * v30;
    m.v0.z = vAimDirection.z * v30;
    v34.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    if ( v34.m128_f32[0] == 0.0 )
    {
      v36 = 0i64;
    }
    else
    {
      LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v34);
      v36 = (__m128)(unsigned int)FLOAT_1_0;
      v36.m128_f32[0] = 1.0 / v35;
    }
    v37 = v36;
    v38 = v36.m128_f32[0];
    v36.m128_f32[0] = v36.m128_f32[0] * UFG::qVector3::msDirUp.z;
    v39 = v38 * UFG::qVector3::msDirUp.x;
    v37.m128_f32[0] = v37.m128_f32[0] * UFG::qVector3::msDirUp.y;
    v40 = v37;
    v40.m128_f32[0] = (float)(v37.m128_f32[0] * v33) - (float)(v36.m128_f32[0] * v32);
    v36.m128_f32[0] = (float)(v36.m128_f32[0] * v31) - (float)(v39 * v33);
    v41 = (float)(v39 * v32) - (float)(v37.m128_f32[0] * v31);
    v42 = v36;
    v42.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v40.m128_f32[0] * v40.m128_f32[0]))
                    + (float)(v41 * v41);
    if ( v42.m128_f32[0] == 0.0 )
      v43 = 0.0;
    else
      v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
    v40.m128_f32[0] = v40.m128_f32[0] * v43;
    v44 = v36.m128_f32[0] * v43;
    m.v1.w = 0.0;
    v46 = v40;
    m.v1.z = v41 * v43;
    LODWORD(m.v1.x) = v40.m128_i32[0];
    m.v1.y = v44;
    v45 = v44 * v33;
    v46.m128_f32[0] = (float)(v40.m128_f32[0] * v33) - (float)((float)(v41 * v43) * v31);
    v47 = (float)(v44 * v31) - (float)(v40.m128_f32[0] * v32);
    v48 = (float)((float)(v41 * v43) * v32) - v45;
    v49 = v46;
    v49.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v48 * v48)) + (float)(v47 * v47);
    if ( v49.m128_f32[0] == 0.0 )
      v50 = 0.0;
    else
      v50 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
    v51 = (UFG::TransformNodeComponent *)v4->m_AimingFreeAimConeClampTaskList.mNode.mNext;
    m.v3.x = *(float *)&v4->vfptr;
    m.v2.w = 0.0;
    m.v3.w = 1.0;
    v52 = *(float *)&v4->mPrev;
    m.v2.z = v47 * v50;
    m.v3.y = *((float *)&v4->vfptr + 1);
    m.v2.x = v48 * v50;
    m.v2.y = v46.m128_f32[0] * v50;
    m.v3.z = v52;
    UFG::TransformNodeComponent::SetWorldTransform(v51, &m);
  }
  UFG::AimingPlayerComponent::updateAccuracy((UFG::AimingPlayerComponent *)((char *)v4 + 0xFFFFFFC0), v6);
}

// File Line: 577
// RVA: 0x523160
float __usercall UFG::AimingPlayerComponent::ComputeRenderReticleRadius@<xmm0>(UFG::AimingPlayerComponent *this@<rcx>, bool screenSpace@<dl>, float a3@<xmm0>)
{
  bool v3; // bl
  float v4; // xmm6_4
  UFG::BaseCameraComponent *v5; // rax
  Illusion::Target *v6; // rax
  __m128i v7; // xmm1
  __m128i v8; // xmm0
  UFG::Camera *v9; // rbx
  UFG::BaseCameraComponent *v10; // rax
  _DWORD *v11; // rax
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  UFG::BaseCameraComponent *v15; // rax
  float *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::BaseCameraComponent *v19; // rax
  float *v20; // rax
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::BaseCameraComponent *v23; // rcx
  UFG::Camera *v24; // rcx
  UFG::qVector3 *v25; // rax
  float v26; // xmm6_4
  float v27; // xmm7_4
  UFG::BaseCameraComponent *v28; // rcx
  UFG::qVector3 *v29; // rax
  __m128 v30; // xmm1
  float v31; // xmm0_4
  UFG::qVector3 world_pos; // [rsp+30h] [rbp-78h]
  UFG::qVector3 v33; // [rsp+40h] [rbp-68h]
  UFG::qVector3 result; // [rsp+50h] [rbp-58h]
  UFG::qVector2 viewport_scale; // [rsp+B0h] [rbp+8h]
  bool is_on_screen; // [rsp+B8h] [rbp+10h]

  v3 = screenSpace;
  ((void (*)(void))this->vfptr[19].__vecDelDtor)();
  v4 = sinf(a3) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  if ( !v3 )
    return v4;
  v5 = UFG::Director::Get()->mCurrentCamera;
  if ( !v5 || v5 == (UFG::BaseCameraComponent *)-80i64 )
    return v4;
  v6 = Render::GetBackBufferTarget();
  v7 = _mm_cvtsi32_si128(v6->mHeight);
  v8 = _mm_cvtsi32_si128(v6->mWidth);
  is_on_screen = 0;
  LODWORD(viewport_scale.x) = (unsigned __int128)_mm_cvtepi32_ps(v8);
  LODWORD(viewport_scale.y) = (unsigned __int128)_mm_cvtepi32_ps(v7);
  v9 = 0i64;
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 )
    v11 = (_DWORD *)&v10->mCamera.mFOVOffset;
  else
    v11 = 0i64;
  v12 = COERCE_FLOAT(v11[40] ^ _xmm[0]) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  v13 = COERCE_FLOAT(v11[41] ^ _xmm[0]) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  v14 = COERCE_FLOAT(v11[42] ^ _xmm[0]) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  v15 = UFG::Director::Get()->mCurrentCamera;
  if ( v15 )
    v16 = &v15->mCamera.mFOVOffset;
  else
    v16 = 0i64;
  v17 = v16[45] + v13;
  v18 = v16[46] + v14;
  world_pos.x = v16[44] + v12;
  world_pos.y = v17;
  world_pos.z = v18;
  v19 = UFG::Director::Get()->mCurrentCamera;
  if ( v19 )
    v20 = &v19->mCamera.mFOVOffset;
  else
    v20 = 0i64;
  v21 = (float)(v4 * v20[32]) + world_pos.x;
  v22 = (float)(v4 * v20[33]) + world_pos.y;
  v33.z = (float)(v4 * v20[34]) + world_pos.z;
  v33.x = v21;
  v33.y = v22;
  v23 = UFG::Director::Get()->mCurrentCamera;
  if ( v23 )
    v24 = &v23->mCamera;
  else
    v24 = 0i64;
  v25 = UFG::Camera::GetScreenCoord(v24, &result, &world_pos, &viewport_scale, &is_on_screen);
  v26 = v25->x;
  v27 = v25->y;
  v28 = UFG::Director::Get()->mCurrentCamera;
  if ( v28 )
    v9 = &v28->mCamera;
  v29 = UFG::Camera::GetScreenCoord(v9, &result, &v33, &viewport_scale, &is_on_screen);
  v30 = (__m128)LODWORD(v29->y);
  v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] - v27) * (float)(v30.m128_f32[0] - v27))
                  + (float)((float)(v29->x - v26) * (float)(v29->x - v26));
  LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v30);
  return v31;
}

// File Line: 653
// RVA: 0x560960
void __fastcall UFG::AimingPlayerComponent::UpdateReticlePosition(const float fDeltaS)
{
  UFG::SimObjectCharacter *v1; // rax
  unsigned __int16 v2; // dx
  UFG::AimingPlayerComponent *v3; // rcx
  unsigned int v4; // edx
  unsigned int v5; // er9
  unsigned int v6; // er10
  signed __int64 v7; // rdx
  unsigned int v8; // er9
  unsigned int v9; // er10
  unsigned int v10; // er9
  unsigned int v11; // er10

  v1 = UFG::GetLocalPlayer();
  if ( !v1 )
    goto LABEL_32;
  v2 = v1->m_Flags;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v8 = v1->mComponentTableEntryCount;
        v9 = v1->m_Components.size;
        if ( v8 < v9 )
        {
          v7 = (signed __int64)&v1->m_Components.p[v8];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
               || UFG::AimingPlayerComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v8;
            v7 += 16i64;
            if ( v8 >= v9 )
            {
              v3 = 0i64;
              goto LABEL_30;
            }
          }
          goto LABEL_14;
        }
      }
      else
      {
        if ( !((v2 >> 12) & 1) )
        {
          v3 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v1->vfptr,
                                               UFG::AimingPlayerComponent::_TypeUID);
          goto LABEL_30;
        }
        v10 = v1->mComponentTableEntryCount;
        v11 = v1->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (signed __int64)&v1->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
               || UFG::AimingPlayerComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v7 += 16i64;
            if ( v10 >= v11 )
              goto LABEL_28;
          }
          goto LABEL_14;
        }
      }
    }
    else
    {
      v5 = v1->mComponentTableEntryCount;
      v6 = v1->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (signed __int64)&v1->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
             || UFG::AimingPlayerComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
          {
            v3 = 0i64;
            goto LABEL_30;
          }
        }
LABEL_14:
        v3 = *(UFG::AimingPlayerComponent **)v7;
        goto LABEL_30;
      }
    }
LABEL_28:
    v3 = 0i64;
    goto LABEL_30;
  }
  v3 = (UFG::AimingPlayerComponent *)v1->m_Components.p[47].m_pComponent;
  if ( !v3
    || (v4 = v3->m_TypeUID, (v4 ^ UFG::AimingPlayerComponent::_TypeUID) & 0xFE000000)
    || UFG::AimingPlayerComponent::_TypeUID & ~v4 & 0x1FFFFFF )
  {
    v3 = 0i64;
  }
LABEL_30:
  if ( !v3 || !UFG::AimingPlayerComponent::updateReticlePosition(v3, fDeltaS) )
LABEL_32:
    UFG::UIHKScreenHud::SetReticleState(STATE_NORMAL);
}

// File Line: 682
// RVA: 0x577560
bool __fastcall UFG::AimingPlayerComponent::updateReticlePosition(UFG::AimingPlayerComponent *this, const float fDeltaS)
{
  UFG::AimingPlayerComponent *v2; // rbx
  float v3; // xmm9_4
  Illusion::Target *v4; // rax
  float v5; // xmm8_4
  float v6; // xmm7_4
  UFG::TargetingSystemPedPlayerComponent *v7; // r13
  UFG::SimObjectWeaponPropertiesComponent *v8; // r15
  bool v9; // al
  UFG::eFocusModeEnum v10; // ecx
  bool v11; // dl
  bool v12; // al
  bool v13; // zf
  UFG::SimObject *v14; // r14
  UFG::eFactionStandingEnum v15; // esi
  __int64 v16; // rcx
  UFG::TargetingSimObject *v17; // rax
  hkLocalFrameGroup *v18; // rdi
  UFG::eHighlightModeEnum v19; // er12
  unsigned __int16 v20; // cx
  unsigned int v21; // er8
  unsigned int v22; // er9
  signed __int64 v23; // rdx
  hkSimpleLocalFrame *v24; // r14
  unsigned int v25; // er8
  unsigned int v26; // er9
  unsigned int v27; // er8
  unsigned int v28; // er9
  unsigned __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  unsigned int v31; // er8
  unsigned int v32; // er9
  signed __int64 v33; // rdx
  unsigned int v34; // er8
  unsigned int v35; // er9
  Illusion::Target *v36; // rax
  float v37; // xmm1_4
  UFG::BaseCameraComponent *v38; // rcx
  UFG::Camera *v39; // rcx
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  UFG::qReflectObject *v43; // rax
  UFG::FireModeInfo *v44; // rdx
  float v45; // xmm7_4
  float v46; // xmm6_4
  float v47; // xmm0_4
  bool v48; // al
  char v49; // di
  UFG::SimComponent *v50; // rax
  float v51; // xmm1_4
  float v52; // xmm0_4
  UFG::BaseCameraComponent *v53; // rcx
  UFG::Camera *v54; // rcx
  UFG::qVector3 *v55; // rax
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm0_4
  float *v59; // rdi
  float v60; // xmm0_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  signed int v63; // eax
  UFG::qReflectObject *v64; // rax
  UFG::FireModeInfo *v65; // rdx
  float v66; // xmm7_4
  float v67; // xmm6_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  unsigned int eWeaponReticleEnum; // [rsp+0h] [rbp-49h]
  UFG::qVector3 result; // [rsp+8h] [rbp-41h]
  UFG::qVector2 viewport_scale; // [rsp+18h] [rbp-31h]
  UFG::qVector3 v73; // [rsp+20h] [rbp-29h]
  bool v74; // [rsp+B0h] [rbp+67h]
  bool is_on_screen; // [rsp+C0h] [rbp+77h]
  bool v76; // [rsp+C8h] [rbp+7Fh]

  v2 = this;
  v3 = fDeltaS;
  v4 = Render::GetBackBufferTarget();
  v5 = (float)v4->mWidth * 0.5;
  v6 = (float)v4->mHeight * 0.5;
  v7 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (*)(void))v2->m_pTargetingSystemPedBaseComponent.m_pSimComponent->vfptr[19].__vecDelDtor)();
  v8 = (UFG::SimObjectWeaponPropertiesComponent *)v7->m_pEquippedSOWPC.m_pPointer;
  if ( !v7->m_bHasRangedWeapon || !v8 )
    goto LABEL_136;
  eWeaponReticleEnum = v8->mHudReticule;
  v9 = v8->mWeaponTypeInfo->mFireModes[v8->mFireMode]->mHasSniperScope && v2->m_bCameraZoomMode;
  if ( v8->mHudReticule == 0 || v9 || !v7->m_bIsAimingActive )
    goto LABEL_136;
  v10 = v7->m_eFocusMode;
  v76 = v10 == 2;
  is_on_screen = (unsigned int)(v10 - 1) <= 1;
  v11 = (unsigned int)(v10 - 3) <= 1;
  v12 = (unsigned int)(v10 - 1) <= 1 || v11;
  v13 = v2->m_bSupressReticle == 0;
  v74 = v12;
  if ( !v13 || !v12 && !v2->m_bUsingCover )
    goto LABEL_136;
  v14 = v2->m_FreeAimSimObject.m_pPointer;
  v15 = 1;
  v16 = (unsigned __int8)v7->m_pTargetingMap->m_Map.p[22];
  v17 = v7->m_pTargets;
  *(_QWORD *)&result.x = v14;
  v18 = (hkLocalFrameGroup *)v17[v16].m_pTarget.m_pPointer;
  if ( v14 && v11 )
    v18 = (hkLocalFrameGroup *)v14;
  v19 = 0;
  if ( !v18 )
    goto LABEL_78;
  v20 = WORD2(v18[3].vfptr);
  if ( (v20 >> 14) & 1 )
  {
    v21 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
    v22 = (unsigned int)v18[4].vfptr;
    if ( v21 < v22 )
    {
      v23 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v21;
      while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
      {
        ++v21;
        v23 += 16i64;
        if ( v21 >= v22 )
          goto LABEL_27;
      }
LABEL_28:
      v24 = *(hkSimpleLocalFrame **)v23;
      goto LABEL_46;
    }
  }
  else
  {
    if ( (v20 & 0x8000u) != 0 )
    {
      v24 = *(hkSimpleLocalFrame **)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 480i64);
      goto LABEL_46;
    }
    if ( (v20 >> 13) & 1 )
    {
      v25 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
      v26 = (unsigned int)v18[4].vfptr;
      if ( v25 < v26 )
      {
        v23 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v25;
        while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
        {
          ++v25;
          v23 += 16i64;
          if ( v25 >= v26 )
          {
            v24 = 0i64;
            goto LABEL_46;
          }
        }
        goto LABEL_28;
      }
    }
    else
    {
      if ( !((v20 >> 12) & 1) )
      {
        v24 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)v18,
                                      UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_46;
      }
      v27 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
      v28 = (unsigned int)v18[4].vfptr;
      if ( v27 < v28 )
      {
        v23 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v27;
        while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
        {
          ++v27;
          v23 += 16i64;
          if ( v27 >= v28 )
          {
            v24 = 0i64;
            goto LABEL_46;
          }
        }
        goto LABEL_28;
      }
    }
  }
LABEL_27:
  v24 = 0i64;
LABEL_46:
  if ( v24 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v24) )
    v18 = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v24);
  if ( !v18 )
    goto LABEL_72;
  v29 = WORD2(v18[3].vfptr);
  if ( !((v29 >> 14) & 1) )
  {
    if ( (v29 & 0x8000u) != 0 )
    {
      v30 = *(UFG::SimComponent **)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 96i64);
      goto LABEL_70;
    }
    if ( (v29 >> 13) & 1 )
    {
      v31 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
      v32 = (unsigned int)v18[4].vfptr;
      if ( v31 < v32 )
      {
        v33 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v31;
        while ( (*(_DWORD *)(v33 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v33 + 8) & 0x1FFFFFF )
        {
          ++v31;
          v33 += 16i64;
          if ( v31 >= v32 )
            goto LABEL_60;
        }
LABEL_61:
        v30 = *(UFG::SimComponent **)v33;
        goto LABEL_70;
      }
    }
    else
    {
      if ( !((v29 >> 12) & 1) )
      {
        v30 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v18, UFG::HealthComponent::_TypeUID);
        goto LABEL_70;
      }
      v34 = *(_DWORD *)&v18[5].m_memSizeAndFlags;
      v35 = (unsigned int)v18[4].vfptr;
      if ( v34 < v35 )
      {
        v33 = *(_QWORD *)&v18[4].m_memSizeAndFlags + 16i64 * v34;
        while ( (*(_DWORD *)(v33 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v33 + 8) & 0x1FFFFFF )
        {
          ++v34;
          v33 += 16i64;
          if ( v34 >= v35 )
          {
            v30 = 0i64;
            goto LABEL_70;
          }
        }
        goto LABEL_61;
      }
    }
LABEL_60:
    v30 = 0i64;
    goto LABEL_70;
  }
  v30 = *(UFG::SimComponent **)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 96i64);
LABEL_70:
  if ( !v30 || !BYTE4(v30[1].m_BoundComponentHandles.mNode.mPrev) )
  {
LABEL_72:
    v15 = (unsigned int)UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
                          (UFG::TargetingSystemPedBaseComponent *)&v7->vfptr,
                          (UFG::SimObject *)v18);
    if ( v15 == 1 )
      v15 = 0;
    if ( v24 && !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v24) )
      v15 = 1;
  }
  v14 = *(UFG::SimObject **)&result.x;
LABEL_78:
  v36 = Render::GetBackBufferTarget();
  v37 = (float)v36->mHeight;
  viewport_scale.x = (float)v36->mWidth;
  viewport_scale.y = v37;
  if ( is_on_screen && !v76 )
  {
    if ( v18 )
    {
      v38 = UFG::Director::Get()->mCurrentCamera;
      v39 = v38 ? &v38->mCamera : 0i64;
      UFG::Camera::GetScreenCoord(v39, &result, &v2->m_vAimPosition, &viewport_scale, &is_on_screen);
      if ( is_on_screen )
      {
        v40 = result.x;
        v41 = result.y;
        if ( !v74 )
          v15 = 1;
        v2->m_vReticleLockedOnCoordsScreen.x = result.x;
        v2->m_vReticleLockedOnCoordsScreen.y = v41;
        *(_QWORD *)&v2->m_fReticleBlend = 0i64;
        v42 = UFG::AimingPlayerComponent::ComputeRenderReticleRadius(v2, 1, v40);
        UFG::UIHKScreenHud::SetReticlePosition(
          (float)(signed int)v2->m_vReticleLockedOnCoordsScreen.x,
          (float)(signed int)v2->m_vReticleLockedOnCoordsScreen.y);
        UFG::UIHKScreenHud::SetReticleState(STATE_COMPLETE);
        UFG::UIHKScreenHud::SetReticleScreenSpaceRadius(v42);
        UFG::UIHKScreenHud::SetReticleTargetFaction(v15);
        UFG::UIHKScreenHud::SetReticleType(
          eWeaponReticleEnum,
          v8->mWeaponTypeInfo->mFireModes[v8->mFireMode]->mExplosionType.mUID != -1);
        v43 = v2->m_FreeAimPhysicsObjectProperties.mData;
        if ( v43 )
          v19 = (UFG::eHighlightModeEnum)v43[2].mBaseNode.mNeighbours[1];
        UFG::UIHKScreenHud::SetReticleHighlightMode(v19);
        v44 = v8->mWeaponTypeInfo->mFireModes[v8->mFireMode];
        if ( v7->m_eFocusMode == 1 )
          v45 = v44->mHardLockReticleSizeMin;
        else
          v45 = v44->mReticleSizeMin;
        if ( v7->m_eFocusMode == 1 )
          v46 = v44->mHardLockReticleSizeMax;
        else
          v46 = v44->mReticleSizeMax;
        v47 = UFG::AimingPlayerComponent::GetReticleSize(v2);
        UFG::UIHKScreenHud::SetReticleSize(v47, v45, v46);
        v2->m_fBlendedReticleRadius = -1.0;
        v2->m_fBlendedReticleSize = -1.0;
        return 1;
      }
    }
LABEL_136:
    v2->m_vReticleLockedOnCoordsScreen.x = v5;
    v2->m_vReticleLockedOnCoordsScreen.y = v6;
    v2->m_vReticleBlendedCoordsScreen.x = v5;
    v48 = 0;
    v2->m_vReticleBlendedCoordsScreen.y = v6;
    v2->m_fReticleBlendRate = 1.0;
    v2->m_fReticleBlend = 1.0;
    return v48;
  }
  if ( !v14 )
    v15 = 1;
  v49 = 0;
  result = UFG::qVector3::msZero;
  if ( UFG::AimingPlayerComponent::ms_eReticleMode == 1 )
  {
    v51 = v2->m_vAimPosition.y;
    result.x = v2->m_vAimPosition.x;
    v52 = v2->m_vAimPosition.z;
    goto LABEL_106;
  }
  if ( UFG::AimingPlayerComponent::ms_eReticleMode == 2 )
  {
    v51 = v2->m_vAimIntentionTargetPosition.y;
    result.x = v2->m_vAimIntentionTargetPosition.x;
    v52 = v2->m_vAimIntentionTargetPosition.z;
LABEL_106:
    v49 = 1;
    goto LABEL_107;
  }
  if ( UFG::AimingPlayerComponent::ms_eReticleMode != 3 )
    goto LABEL_108;
  v50 = UFG::GetCurrentGameCamera();
  if ( !v50 || !BYTE5(v50[11].m_BoundComponentHandles.mNode.mPrev) )
    goto LABEL_108;
  v51 = v2->m_vAimIntentionTargetPosition.y;
  v49 = 1;
  result.x = v2->m_vAimIntentionTargetPosition.x;
  v52 = v2->m_vAimIntentionTargetPosition.z;
LABEL_107:
  result.y = v51;
  result.z = v52;
LABEL_108:
  if ( v49 )
  {
    v74 = 0;
    v53 = UFG::Director::Get()->mCurrentCamera;
    if ( v53 )
      v54 = &v53->mCamera;
    else
      v54 = 0i64;
    v55 = UFG::Camera::GetScreenCoord(v54, &v73, &result, &viewport_scale, &v74);
    if ( UFG::AimingPlayerComponent::ms_bReticleMovementHoriz )
      v5 = v55->x;
    if ( UFG::AimingPlayerComponent::ms_bReticleMovementVert )
      v6 = v55->y;
  }
  v56 = *(float *)&FLOAT_1_0;
  v57 = (float)(s_fReticleBlendIncrementPerS * v3) + v2->m_fReticleBlendRate;
  if ( v57 > 1.0 )
    v57 = *(float *)&FLOAT_1_0;
  v2->m_fReticleBlendRate = v57;
  v58 = v57 + v2->m_fReticleBlend;
  if ( v58 <= 1.0 )
    v56 = v58;
  v2->m_fReticleBlend = v56;
  v59 = (float *)&v2->m_vReticleBlendedCoordsScreen;
  if ( UFG::AimingPlayerComponent::ms_bReticleBlend )
  {
    UFG::qApproach(
      (float *)&v2->m_vReticleBlendedCoordsScreen,
      v5,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(*v59 - v5) & _xmm) * s_fRreticleApproachRate,
      v3);
    UFG::qApproach(
      &v2->m_vReticleBlendedCoordsScreen.y,
      v6,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->m_vReticleBlendedCoordsScreen.y - v6) & _xmm) * s_fRreticleApproachRate,
      v3);
  }
  else
  {
    *v59 = v5;
    v2->m_vReticleBlendedCoordsScreen.y = v6;
  }
  v60 = v2->m_vReticleBlendedCoordsScreen.y;
  v2->m_vReticleLockedOnCoordsScreen.x = *v59;
  v2->m_vReticleLockedOnCoordsScreen.y = v60;
  v61 = UFG::AimingPlayerComponent::ComputeRenderReticleRadius(v2, 1, v60);
  v62 = v2->m_fBlendedReticleRadius;
  if ( v62 >= 0.0 )
    v61 = (float)((float)(v61 - v62) * 0.5) + v62;
  v63 = (signed int)v2->m_vReticleBlendedCoordsScreen.y;
  v2->m_fBlendedReticleRadius = v61;
  UFG::UIHKScreenHud::SetReticlePosition((float)(signed int)*v59, (float)v63);
  UFG::UIHKScreenHud::SetReticleState(STATE_DANGER);
  UFG::UIHKScreenHud::SetReticleScreenSpaceRadius(v2->m_fBlendedReticleRadius);
  UFG::UIHKScreenHud::SetReticleTargetFaction(v15);
  UFG::UIHKScreenHud::SetReticleType(
    eWeaponReticleEnum,
    v8->mWeaponTypeInfo->mFireModes[v8->mFireMode]->mExplosionType.mUID != -1);
  v64 = v2->m_FreeAimPhysicsObjectProperties.mData;
  if ( v64 )
    v19 = (UFG::eHighlightModeEnum)v64[2].mBaseNode.mNeighbours[1];
  UFG::UIHKScreenHud::SetReticleHighlightMode(v19);
  v65 = v8->mWeaponTypeInfo->mFireModes[v8->mFireMode];
  if ( v7->m_eFocusMode == 1 )
    v66 = v65->mHardLockReticleSizeMin;
  else
    v66 = v65->mReticleSizeMin;
  if ( v7->m_eFocusMode == 1 )
    v67 = v65->mHardLockReticleSizeMax;
  else
    v67 = v65->mReticleSizeMax;
  v68 = UFG::AimingPlayerComponent::GetReticleSize(v2);
  v69 = v2->m_fBlendedReticleSize;
  if ( v69 >= 0.0 )
    v68 = (float)((float)(v68 - v69) * 0.5) + v69;
  v2->m_fBlendedReticleSize = v68;
  UFG::UIHKScreenHud::SetReticleSize(v68, v66, v67);
  return 1;
}

// File Line: 943
// RVA: 0x56E750
void __fastcall UFG::AimingPlayerComponent::updateAccuracy(UFG::AimingPlayerComponent *this, const float fDeltaS)
{
  float v2; // xmm10_4
  UFG::AimingPlayerComponent *v3; // rbx
  float v4; // xmm12_4
  float v5; // xmm11_4
  UFG::SimComponent *v6; // rdx
  float v7; // xmm0_4
  bool v8; // si
  bool v9; // bp
  __int64 v10; // rdi
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rcx
  unsigned int v13; // er8
  unsigned int v14; // er9
  signed __int64 v15; // rdx
  unsigned int v16; // er8
  unsigned int v17; // er9
  float v18; // xmm1_4
  unsigned __int16 v19; // cx
  UFG::AimingBaseComponent *v20; // rax
  unsigned int v21; // er8
  unsigned int v22; // er9
  signed __int64 v23; // rdx
  unsigned int v24; // er8
  unsigned int v25; // er9
  unsigned int v26; // er8
  unsigned int v27; // er9
  float v28; // xmm7_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rcx
  float v32; // xmm8_4
  __int64 v33; // rax
  __int64 v34; // rdx
  UFG::GameStatTracker *v35; // rax
  float v36; // xmm6_4
  char v37; // al
  int v38; // xmm0_4
  int v39; // xmm0_4
  float v40; // xmm6_4
  float v41; // xmm6_4
  float fAccuracyModifierContinuous; // [rsp+B0h] [rbp+8h]
  float fAccuracyModifierInstant; // [rsp+C0h] [rbp+18h]

  v2 = this->m_Accuracy.m_fAccuracyUnclamped;
  v3 = this;
  v4 = fDeltaS;
  if ( v2 <= this->m_Accuracy.m_fAccuracyMinimum )
    v2 = this->m_Accuracy.m_fAccuracyMinimum;
  if ( v2 >= this->m_Accuracy.m_fAccuracyMaximum )
    v2 = this->m_Accuracy.m_fAccuracyMaximum;
  v5 = this->m_Accuracy.m_fAccuracyPenalty;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyMaximum = 0x3F800000i64;
  fAccuracyModifierContinuous = 0.0;
  fAccuracyModifierInstant = 0.0;
  if ( !this->m_pTSPPC.m_pSimComponent )
    return;
  v6 = this->m_pTSPPC.m_pSimComponent;
  v7 = this->m_Accuracy.m_fAccuracyOverride;
  v8 = (unsigned int)(LODWORD(v6[53].m_pSimObject) - 1) <= 1;
  v9 = LODWORD(v6[53].m_pSimObject) == 2;
  if ( v7 < 0.0 )
  {
    if ( (unsigned int)(LODWORD(v6[53].m_pSimObject) - 3) > 1
      && (!v8
       || !*(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 30i64) + *(_QWORD *)&v6[1].m_TypeUID + 40)) )
    {
      this->m_fAimObstructedDuration = 0.0;
      return;
    }
    v10 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 30i64) + *(_QWORD *)&v6[1].m_TypeUID + 40);
    if ( !v10 || !v8 || v9 )
    {
LABEL_78:
      UFG::AimingBaseComponent::ApplyAccuracyModifiers(
        (UFG::AimingBaseComponent *)&v3->vfptr,
        0,
        &fAccuracyModifierInstant,
        &fAccuracyModifierContinuous);
      v28 = *(float *)&FLOAT_1_0;
      if ( fAccuracyModifierContinuous <= 0.0 )
      {
        if ( fAccuracyModifierContinuous < 0.0 )
        {
          v30 = fAccuracyModifierContinuous + v3->m_Accuracy.m_fAccuracyMaximum;
          if ( v30 <= 0.0 )
            v30 = 0.0;
          v3->m_Accuracy.m_fAccuracyMaximum = v30;
        }
      }
      else
      {
        v29 = fAccuracyModifierContinuous + v3->m_Accuracy.m_fAccuracyMinimum;
        if ( v29 >= 1.0 )
          v29 = *(float *)&FLOAT_1_0;
        v3->m_Accuracy.m_fAccuracyMinimum = v29;
      }
      v31 = v3->m_pTSPPC.m_pSimComponent[42].m_BoundComponentHandles.mNode.mPrev;
      if ( v31 )
        v32 = *(float *)&v31[3].mPrev;
      else
        v32 = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fDefaultAccuracyRate;
      v33 = *(_QWORD *)&v3->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
      if ( v33 )
      {
        v34 = *(_QWORD *)(*(_QWORD *)(v33 + 176) + 8i64 * *(unsigned int *)(v33 + 172) + 8);
        if ( *(_DWORD *)(v34 + 100) != UFG::gNullQSymbolUC.mUID )
          v32 = v32 * *(float *)(v34 + 168);
      }
      v35 = UFG::GameStatTracker::Instance();
      if ( (signed int)UFG::GameStatTracker::GetStat(v35, GunplayUpgradeStage) >= UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_iRequiredLevelForGunplayUpgradeMarksman )
        v32 = v32 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fGunplayUpgradeMarksmanMultiplier;
      v36 = *(float *)&FLOAT_1_0;
      if ( UFG::IsAnyLocalPlayer(v3->m_pSimObject) )
        v36 = UFG::PlayerBuffTracker::GetAccuracyRateMultiplier() + 1.0;
      if ( v10 && v3->m_bFocusTargetObstructed )
        v3->m_fAimObstructedDuration = v4 + v3->m_fAimObstructedDuration;
      else
        v3->m_fAimObstructedDuration = 0.0;
      v37 = 0;
      *(float *)&v38 = v5;
      if ( UFG::AimingPlayerComponent::ms_fAimObstructionGracePeriod < v3->m_fAimObstructedDuration )
        v37 = 1;
      if ( v5 < 0.0 )
        v38 = LODWORD(v5) ^ _xmm[0];
      if ( *(float *)&v38 >= 0.001 )
        goto LABEL_122;
      *(float *)&v39 = fAccuracyModifierInstant;
      if ( fAccuracyModifierInstant < 0.0 )
        v39 = LODWORD(fAccuracyModifierInstant) ^ _xmm[0];
      if ( *(float *)&v39 >= 0.001 )
      {
LABEL_122:
        v40 = COERCE_FLOAT(LODWORD(v5) ^ _xmm[0]) + fAccuracyModifierInstant;
      }
      else if ( v37 && v8 && !v9 )
      {
        v40 = UFG::AimingPlayerComponent::ms_fObstructedPenaltyRate * v4;
      }
      else
      {
        v40 = (float)(v36 * v32) * v4;
      }
      v41 = v40 + v2;
      if ( v41 <= 0.0 )
      {
        v41 = 0.0;
      }
      else if ( v41 >= 1.0 )
      {
        goto LABEL_119;
      }
      v28 = v41;
LABEL_119:
      v3->m_Accuracy.m_fAccuracyUnclamped = v28;
      return;
    }
    v11 = *(_WORD *)(v10 + 76);
    if ( (v11 >> 14) & 1 )
    {
      v12 = *(UFG::SimComponent **)(*(_QWORD *)(v10 + 104) + 48i64);
      if ( !v12
        || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v12->m_TypeUID) & 0xFE000000
        || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF )
      {
        goto LABEL_23;
      }
LABEL_45:
      if ( v12 )
      {
        v18 = *(float *)&v12[3].m_SafePointerList.mNode.mNext;
        if ( v18 <= -1.0 )
        {
          v18 = FLOAT_N1_0;
        }
        else if ( v18 >= 0.0 )
        {
          v18 = 0.0;
        }
        v3->m_Accuracy.m_fAccuracyMaximum = (float)(UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fAccuracyEvadeModifier
                                                  * v18)
                                          + v3->m_Accuracy.m_fAccuracyMaximum;
      }
      v19 = *(_WORD *)(v10 + 76);
      if ( (v19 >> 14) & 1 )
      {
        v20 = *(UFG::AimingBaseComponent **)(*(_QWORD *)(v10 + 104) + 752i64);
        goto LABEL_76;
      }
      if ( (v19 & 0x8000u) == 0 )
      {
        if ( (v19 >> 13) & 1 )
        {
          v24 = *(_DWORD *)(v10 + 128);
          v25 = *(_DWORD *)(v10 + 96);
          if ( v24 < v25 )
          {
            v23 = *(_QWORD *)(v10 + 104) + 16i64 * v24;
            while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
                 || UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
            {
              ++v24;
              v23 += 16i64;
              if ( v24 >= v25 )
              {
                v20 = 0i64;
                goto LABEL_76;
              }
            }
            goto LABEL_60;
          }
        }
        else
        {
          if ( !((v19 >> 12) & 1) )
          {
            v20 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)v10,
                                                UFG::AimingBaseComponent::_TypeUID);
LABEL_76:
            if ( v20 )
              UFG::AimingBaseComponent::ApplyAccuracyModifiers(
                v20,
                1,
                &fAccuracyModifierInstant,
                &fAccuracyModifierContinuous);
            goto LABEL_78;
          }
          v26 = *(_DWORD *)(v10 + 128);
          v27 = *(_DWORD *)(v10 + 96);
          if ( v26 < v27 )
          {
            v23 = *(_QWORD *)(v10 + 104) + 16i64 * v26;
            while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
                 || UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
            {
              ++v26;
              v23 += 16i64;
              if ( v26 >= v27 )
              {
                v20 = 0i64;
                goto LABEL_76;
              }
            }
            goto LABEL_60;
          }
        }
      }
      else
      {
        v21 = *(_DWORD *)(v10 + 128);
        v22 = *(_DWORD *)(v10 + 96);
        if ( v21 < v22 )
        {
          v23 = *(_QWORD *)(v10 + 104) + 16i64 * v21;
          while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
          {
            ++v21;
            v23 += 16i64;
            if ( v21 >= v22 )
              goto LABEL_59;
          }
LABEL_60:
          v20 = *(UFG::AimingBaseComponent **)v23;
          goto LABEL_76;
        }
      }
LABEL_59:
      v20 = 0i64;
      goto LABEL_76;
    }
    if ( (v11 & 0x8000u) != 0 )
    {
      v12 = *(UFG::SimComponent **)(*(_QWORD *)(v10 + 104) + 48i64);
      if ( !v12 || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v12->m_TypeUID) & 0xFE000000 )
        goto LABEL_23;
      if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF )
        v12 = 0i64;
      goto LABEL_45;
    }
    if ( (v11 >> 13) & 1 )
    {
      v13 = *(_DWORD *)(v10 + 128);
      v14 = *(_DWORD *)(v10 + 96);
      if ( v13 < v14 )
      {
        v15 = *(_QWORD *)(v10 + 104) + 16i64 * v13;
        while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
        {
          ++v13;
          v15 += 16i64;
          if ( v13 >= v14 )
          {
            v12 = 0i64;
            goto LABEL_45;
          }
        }
LABEL_36:
        v12 = *(UFG::SimComponent **)v15;
        goto LABEL_45;
      }
    }
    else
    {
      if ( !((v11 >> 12) & 1) )
      {
        v12 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)v10,
                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_45;
      }
      v16 = *(_DWORD *)(v10 + 128);
      v17 = *(_DWORD *)(v10 + 96);
      if ( v16 < v17 )
      {
        v15 = *(_QWORD *)(v10 + 104) + 16i64 * v16;
        while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
        {
          ++v16;
          v15 += 16i64;
          if ( v16 >= v17 )
          {
            v12 = 0i64;
            goto LABEL_45;
          }
        }
        goto LABEL_36;
      }
    }
LABEL_23:
    v12 = 0i64;
    goto LABEL_45;
  }
  if ( v7 <= 0.0 )
  {
    v7 = 0.0;
  }
  else if ( v7 >= 1.0 )
  {
    LODWORD(this->m_Accuracy.m_fAccuracyUnclamped) = (_DWORD)FLOAT_1_0;
    return;
  }
  this->m_Accuracy.m_fAccuracyUnclamped = v7;
}

// File Line: 1106
// RVA: 0x5784F0
void __fastcall UFG::AimingPlayerComponent::updateSoftLockOffset(UFG::AimingPlayerComponent *this, UFG::qMatrix44 *matXform)
{
  UFG::qMatrix44 *v2; // r13
  UFG::AimingPlayerComponent *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::SimComponent *v5; // rdx
  signed int v6; // er14
  UFG::TransformNodeComponent *v7; // r15
  UFG::SimObject *v8; // rdi
  UFG::AimingPlayerComponent::eSoftLockTypeEnum v9; // ecx
  bool v10; // r12
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  unsigned int v13; // er8
  unsigned int v14; // er10
  UFG::SimComponentHolder *v15; // rdx
  int v16; // ecx
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rax
  unsigned int v19; // er8
  unsigned int v20; // er10
  UFG::SimComponentHolder *v21; // rdx
  unsigned int v22; // er8
  unsigned int v23; // er10
  unsigned int v24; // er8
  unsigned int v25; // er10
  UFG::SimComponent *v26; // rcx
  UFG::SimComponent *v27; // rax
  char v28; // r12
  bool v29; // al
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm8_4
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm12_4
  float v43; // xmm13_4
  float v44; // xmm14_4
  float v45; // xmm2_4
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __int128 v48; // xmm3
  __m128 v49; // xmm9
  float v50; // xmm8_4
  float v51; // xmm3_4
  __int128 v52; // xmm5
  float v53; // xmm8_4
  __m128 v54; // xmm2
  float v55; // xmm4_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm4_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm9_4
  float v62; // xmm11_4
  __m128 v63; // xmm10
  float v64; // xmm11_4
  __m128 v65; // xmm2
  float v66; // xmm0_4
  __int128 v67; // xmm2
  __int128 v68; // xmm1
  float v69; // xmm4_4
  float v70; // xmm2_4
  float v71; // xmm4_4
  __m128 v72; // xmm10
  float v73; // xmm9_4
  float v74; // xmm4_4
  __m128 v75; // xmm2
  float v76; // xmm2_4
  float v77; // xmm8_4
  __int128 v78; // xmm9
  float v79; // xmm10_4
  __m128 v80; // xmm2
  float v81; // xmm3_4
  float v82; // xmm2_4
  float v83; // xmm2_4
  UFG::SimComponent *v84; // rax
  UFG::SimComponent *v85; // rax
  bool v86; // cl
  UFG::AimingPlayerComponent::eSoftLockTypeEnum v87; // eax
  float v88; // xmm14_4
  __m128 v89; // xmm4
  __m128 v90; // xmm5
  __m128 v91; // xmm1
  __m128 v92; // xmm3
  __m128 v93; // xmm9
  float v94; // xmm5_4
  __m128 v95; // xmm2
  float v96; // xmm8_4
  float v97; // xmm1_4
  float v98; // xmm2_4
  float v99; // xmm8_4
  float v100; // xmm2_4
  float v101; // xmm1_4
  float v102; // xmm10_4
  float v103; // xmm8_4
  __m128 v104; // xmm9
  float v105; // xmm8_4
  __m128 v106; // xmm2
  float v107; // xmm1_4
  float v108; // xmm8_4
  float v109; // xmm10_4
  float v110; // xmm11_4
  __m128 v111; // xmm12
  float v112; // xmm13_4
  __m128 v113; // xmm2
  float v114; // xmm7_4
  float v115; // xmm1_4
  float v116; // xmm0_4
  float v117; // xmm2_4
  float v118; // xmm10_4
  float v119; // xmm8_4
  UFG::SimComponent *v120; // rax
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 result; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 v124; // [rsp+A0h] [rbp-60h]
  bool v125; // [rsp+1B0h] [rbp+B0h]

  v2 = matXform;
  v3 = this;
  v4 = UFG::GameStatTracker::Instance();
  if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v4, AimSoftLockEnabled) )
  {
    v3->m_bResetSoftLockOffset = 0;
    v3->m_eSoftLockType = 0;
    return;
  }
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v5 = v3->m_pTSPPC.m_pSimComponent;
  v6 = 0;
  v7 = 0i64;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 30i64)
                          + *(_QWORD *)&v5[1].m_TypeUID
                          + 40);
  if ( v8 )
    v7 = v8->m_pTransformNodeComponent;
  v125 = LODWORD(v5[53].m_pSimObject) == 2;
  if ( v125 )
  {
    v9 = v3->m_eSoftLockType;
    if ( (unsigned int)(v9 - 2) <= 1 )
      v6 = v3->m_eSoftLockType;
    v10 = v3->m_bResetSoftLockOffset && v9 == 1;
    if ( !v8 )
      goto LABEL_37;
    v11 = v8->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v8->m_Components.p[3].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v12 = v8->m_Components.p[4].m_pComponent;
      }
      else if ( (v11 >> 12) & 1 )
      {
        v13 = (unsigned int)v8[1].vfptr;
        v14 = v8->m_Components.size;
        if ( v13 >= v14 )
        {
LABEL_25:
          v12 = 0i64;
        }
        else
        {
          v15 = &v8->m_Components.p[v13];
          while ( (v15->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF )
          {
            ++v13;
            ++v15;
            if ( v13 >= v14 )
              goto LABEL_25;
          }
          v12 = v15->m_pComponent;
        }
      }
      else
      {
        v12 = UFG::SimObject::GetComponentOfType(v8, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v12 = v8->m_Components.p[3].m_pComponent;
    }
    if ( !v12 )
      goto LABEL_37;
    v16 = (int)v12[1].m_SafePointerList.mNode.mNext;
    if ( v16 == 4 )
    {
      v6 = 2;
    }
    else if ( v16 == 1 )
    {
      v6 = 3;
    }
    else if ( !v6 )
    {
LABEL_37:
      if ( v10 && v6 )
        v3->m_bResetSoftLockOffset = 0;
      goto LABEL_40;
    }
    if ( v8 == v3->m_FreeAimSimObject.m_pPointer && v3->m_bResetSoftLockOffset )
      v3->m_bResetSoftLockOffset = 0;
    goto LABEL_37;
  }
LABEL_40:
  if ( !v8 )
    goto LABEL_70;
  v17 = v8->m_Flags;
  if ( !((v17 >> 14) & 1) )
  {
    if ( (v17 & 0x8000u) == 0 )
    {
      if ( (v17 >> 13) & 1 )
      {
        v22 = (unsigned int)v8[1].vfptr;
        v23 = v8->m_Components.size;
        if ( v22 < v23 )
        {
          v21 = &v8->m_Components.p[v22];
          while ( (v21->m_TypeUID & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || UFG::AimingBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF )
          {
            ++v22;
            ++v21;
            if ( v22 >= v23 )
            {
              v18 = 0i64;
              goto LABEL_66;
            }
          }
          goto LABEL_50;
        }
      }
      else
      {
        if ( !((v17 >> 12) & 1) )
        {
          v18 = UFG::SimObject::GetComponentOfType(v8, UFG::AimingBaseComponent::_TypeUID);
          goto LABEL_66;
        }
        v24 = (unsigned int)v8[1].vfptr;
        v25 = v8->m_Components.size;
        if ( v24 < v25 )
        {
          v21 = &v8->m_Components.p[v24];
          while ( (v21->m_TypeUID & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || UFG::AimingBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF )
          {
            ++v24;
            ++v21;
            if ( v24 >= v25 )
            {
              v18 = 0i64;
              goto LABEL_66;
            }
          }
          goto LABEL_50;
        }
      }
    }
    else
    {
      v19 = (unsigned int)v8[1].vfptr;
      v20 = v8->m_Components.size;
      if ( v19 < v20 )
      {
        v21 = &v8->m_Components.p[v19];
        while ( (v21->m_TypeUID & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
             || UFG::AimingBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF )
        {
          ++v19;
          ++v21;
          if ( v19 >= v20 )
            goto LABEL_49;
        }
LABEL_50:
        v18 = v21->m_pComponent;
        goto LABEL_66;
      }
    }
LABEL_49:
    v18 = 0i64;
    goto LABEL_66;
  }
  v18 = v8->m_Components.p[47].m_pComponent;
LABEL_66:
  if ( !v18
    || *(_QWORD *)&v18[3].m_TypeUID - 40i64 == (_QWORD)v18 + 168
    || (v26 = v3->m_pTSPPC.m_pSimComponent, (unsigned int)(LODWORD(v26[53].m_pSimObject) - 1) > 1) )
  {
LABEL_70:
    if ( v6 )
      goto LABEL_75;
    goto LABEL_71;
  }
  *(_DWORD *)(&v26[53].m_SimObjIndex + 1) = 3;
  LODWORD(v26[53].m_pSimObject) = 3;
  v6 = 0;
LABEL_71:
  if ( &v3->m_AimingSoftLockTaskList.mNode.mNext[-3].mNext != (UFG::qNode<AimingSoftLockTask,AimingSoftLockList> **)&v3->m_fFocusTargetRadius
    || UFG::AimingPlayerComponent::ms_bContinuousAbsoluteSoftLock
    || v3->m_bFreeAimRootMovementLock )
  {
    v6 = 1;
  }
LABEL_75:
  v27 = v3->m_pTSPPC.m_pSimComponent;
  v28 = BYTE5(v27[52].m_BoundComponentHandles.mNode.mPrev);
  v29 = BYTE3(v27[52].m_BoundComponentHandles.mNode.mPrev) || v28 || v3->m_bResetSoftLockOffset;
  if ( v6 != v3->m_eSoftLockType || v29 )
  {
    switch ( v6 )
    {
      case 1:
        v30 = v3->m_vFreeAimTargetPosition.y;
        v31 = v3->m_vFreeAimTargetPosition.z;
        v3->m_vSoftLockOffset.x = v3->m_vFreeAimTargetPosition.x;
        v3->m_vSoftLockOffset.y = v30;
        v3->m_vSoftLockOffset.z = v31;
        break;
      case 2:
        UFG::TransformNodeComponent::UpdateWorldTransform(v7);
        UFG::qInverseAffine(&d, &v7->mWorldTransform);
        if ( v3->m_bResetSoftLockOffset )
        {
          UFG::AimingBaseComponent::GetTargetNormalAimPosition(
            (UFG::AimingBaseComponent *)&v3->vfptr,
            &vTargetNormalAimPosition,
            22i64,
            v2);
          v32 = vTargetNormalAimPosition.z;
          v33 = vTargetNormalAimPosition.y;
          v34 = vTargetNormalAimPosition.x;
        }
        else
        {
          v34 = v3->m_vFreeAimTargetPosition.x;
          v33 = v3->m_vFreeAimTargetPosition.y;
          v32 = v3->m_vFreeAimTargetPosition.z;
        }
        v35 = d.v1.y;
        v36 = (float)((float)(d.v1.x * v33) + (float)(v34 * d.v0.x)) + (float)(d.v2.x * v32);
        v37 = v34 * d.v0.y;
        v38 = v34 * d.v0.z;
        v39 = d.v2.y * v32;
        v3->m_vSoftLockOffset.x = v36 + d.v3.x;
        v40 = (float)((float)(v35 * v33) + v37) + v39;
        v41 = (float)((float)(d.v1.z * v33) + v38) + (float)(d.v2.z * v32);
        v3->m_vSoftLockOffset.y = v40 + d.v3.y;
        v3->m_vSoftLockOffset.z = v41 + d.v3.z;
        break;
      case 3:
        UFG::TransformNodeComponent::UpdateWorldTransform(v7);
        v46 = (__m128)LODWORD(v3->m_vFreeAimOrigin.y);
        v42 = v7->mWorldTransform.v3.x;
        v43 = v7->mWorldTransform.v3.y;
        v44 = v7->mWorldTransform.v3.z;
        v45 = v3->m_vFreeAimOrigin.x - v42;
        v46.m128_f32[0] = v46.m128_f32[0] - v43;
        v47 = v46;
        v47.m128_f32[0] = (float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v45 * v45);
        if ( v47.m128_f32[0] == 0.0 )
        {
          v48 = 0i64;
        }
        else
        {
          v48 = (unsigned int)FLOAT_1_0;
          *(float *)&v48 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v47));
        }
        v49 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v52 = v48;
        v50 = *(float *)&v48;
        v51 = *(float *)&v48 * 0.0;
        *(float *)&v52 = *(float *)&v52 * v45;
        v53 = v50 * v46.m128_f32[0];
        d.v0.w = 0.0;
        v54 = v49;
        LODWORD(d.v0.x) = v52;
        d.v0.y = v53;
        d.v0.z = v51;
        v54.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v54.m128_f32[0] == 0.0 )
          v55 = 0.0;
        else
          v55 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v54));
        v56 = v55;
        v57 = v55;
        v58 = v55 * UFG::qVector3::msDirUp.z;
        v59 = v57 * UFG::qVector3::msDirUp.x;
        v60 = v56 * UFG::qVector3::msDirUp.y;
        v63 = (__m128)v52;
        v61 = (float)(v51 * v60) - (float)(v53 * v58);
        v62 = v53 * v59;
        v63.m128_f32[0] = (float)(*(float *)&v52 * v58) - (float)(v51 * v59);
        v65 = v63;
        v64 = v62 - (float)(*(float *)&v52 * v60);
        v65.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v61 * v61)) + (float)(v64 * v64);
        if ( v65.m128_f32[0] == 0.0 )
        {
          v67 = 0i64;
        }
        else
        {
          LODWORD(v66) = (unsigned __int128)_mm_sqrt_ps(v65);
          v67 = (unsigned int)FLOAT_1_0;
          *(float *)&v67 = 1.0 / v66;
        }
        v68 = v67;
        v69 = *(float *)&v67;
        v70 = *(float *)&v67 * v64;
        *(float *)&v68 = *(float *)&v68 * v61;
        v71 = v69 * v63.m128_f32[0];
        d.v1.w = 0.0;
        d.v1.z = v70;
        v72 = (__m128)v68;
        LODWORD(d.v1.x) = v68;
        d.v1.y = v71;
        v72.m128_f32[0] = (float)(*(float *)&v68 * v51) - (float)(v70 * *(float *)&v52);
        v73 = (float)(v70 * v53) - (float)(v71 * v51);
        v74 = (float)(v71 * *(float *)&v52) - (float)(*(float *)&v68 * v53);
        v75 = v72;
        v75.m128_f32[0] = (float)((float)(v72.m128_f32[0] * v72.m128_f32[0]) + (float)(v73 * v73)) + (float)(v74 * v74);
        if ( v75.m128_f32[0] == 0.0 )
          v76 = 0.0;
        else
          v76 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v75));
        d.v3.x = v42;
        d.v3.y = v43;
        d.v2.w = 0.0;
        d.v3.w = 1.0;
        d.v2.z = v76 * v74;
        d.v3.z = v44;
        d.v2.x = v76 * v73;
        d.v2.y = v76 * v72.m128_f32[0];
        UFG::qInverseAffine(&v124, &d);
        if ( v3->m_bResetSoftLockOffset )
        {
          UFG::AimingBaseComponent::GetTargetNormalAimPosition(
            (UFG::AimingBaseComponent *)&v3->vfptr,
            &vTargetNormalAimPosition,
            22i64,
            v2);
          v77 = vTargetNormalAimPosition.x;
          *(float *)&v78 = vTargetNormalAimPosition.y;
          v79 = vTargetNormalAimPosition.z;
        }
        else
        {
          if ( !v28 )
            goto LABEL_146;
          if ( !v3->m_bFocusTargetProbed )
            goto LABEL_146;
          v78 = LODWORD(v3->m_vFreeAimTargetPosition.y);
          v79 = v3->m_vFreeAimTargetPosition.z;
          vTargetNormalAimPosition.x = v3->m_vFreeAimTargetPosition.x;
          v77 = vTargetNormalAimPosition.x;
          LODWORD(vTargetNormalAimPosition.y) = v78;
          vTargetNormalAimPosition.z = v79;
          UFG::qNearestSegPoint(&result, &v3->m_vFocusTargetSegA, &v3->m_vFocusTargetSegB, &vTargetNormalAimPosition);
          v80 = (__m128)v78;
          v80.m128_f32[0] = (float)((float)((float)(*(float *)&v78 - result.y) * (float)(*(float *)&v78 - result.y))
                                  + (float)((float)(v77 - result.x) * (float)(v77 - result.x)))
                          + (float)((float)(v79 - result.z) * (float)(v79 - result.z));
          if ( COERCE_FLOAT(_mm_sqrt_ps(v80)) > (float)(UFG::AimingPlayerComponent::ms_fSoftLockCapsuleExpansionRatio
                                                      * v3->m_fFocusTargetRadius) )
          {
LABEL_146:
            v79 = v3->m_vFocusTargetClosestPos.z;
            *(float *)&v78 = v3->m_vFocusTargetClosestPos.y;
            v77 = v3->m_vFocusTargetClosestPos.x;
          }
        }
        v81 = (float)((float)((float)(v124.v1.y * *(float *)&v78) + (float)(v124.v0.y * v77)) + (float)(v124.v2.y * v79))
            + v124.v3.y;
        v82 = (float)((float)(v124.v1.z * *(float *)&v78) + (float)(v124.v0.z * v77)) + (float)(v124.v2.z * v79);
        v3->m_vSoftLockOffset.x = (float)((float)((float)(v124.v1.x * *(float *)&v78) + (float)(v124.v0.x * v77))
                                        + (float)(v124.v2.x * v79))
                                + v124.v3.x;
        v83 = v82 + v124.v3.z;
        v3->m_vSoftLockOffset.y = v81;
        v3->m_vSoftLockOffset.z = v83;
        break;
      default:
        v6 = 0;
        break;
    }
    v3->m_eSoftLockType = v6;
  }
  if ( v3->m_eSoftLockType == eSOFT_LOCK_NONE )
  {
    v84 = v3->m_pTSPPC.m_pSimComponent;
    if ( LODWORD(v84[53].m_pSimObject) == 2 && !v3->m_bFocusTargetProbed )
    {
      *(_DWORD *)(&v84[53].m_SimObjIndex + 1) = 3;
      LODWORD(v84[53].m_pSimObject) = 3;
      ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD))v3->m_pTSPPC.m_pSimComponent->vfptr[14].__vecDelDtor)(
        v3->m_pTSPPC.m_pSimComponent,
        22i64,
        0i64);
    }
    goto LABEL_143;
  }
  v85 = UFG::GetCurrentGameCamera();
  v86 = v85 && BYTE5(v85[11].m_BoundComponentHandles.mNode.mPrev);
  v87 = v3->m_eSoftLockType;
  if ( v87 != 1 && (!v125 || !v8 || !v7 || v86) )
    goto LABEL_142;
  if ( v87 != 2 )
  {
    if ( v87 != 3 )
      goto LABEL_143;
    v88 = UFG::AimingPlayerComponent::ms_fSoftLockCapsuleExpansionRatio * v3->m_fFocusTargetRadius;
    UFG::TransformNodeComponent::UpdateWorldTransform(v7);
    v89 = (__m128)LODWORD(v3->m_vFreeAimOrigin.x);
    v90 = (__m128)LODWORD(v3->m_vFreeAimOrigin.y);
    v89.m128_f32[0] = v89.m128_f32[0] - v7->mWorldTransform.v3.x;
    v90.m128_f32[0] = v90.m128_f32[0] - v7->mWorldTransform.v3.y;
    v91 = v90;
    v91.m128_f32[0] = (float)(v90.m128_f32[0] * v90.m128_f32[0]) + (float)(v89.m128_f32[0] * v89.m128_f32[0]);
    if ( v91.m128_f32[0] == 0.0 )
    {
      v92 = 0i64;
    }
    else
    {
      v92 = (__m128)(unsigned int)FLOAT_1_0;
      v92.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v91));
    }
    v93 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v89.m128_f32[0] = v89.m128_f32[0] * v92.m128_f32[0];
    v94 = v90.m128_f32[0] * v92.m128_f32[0];
    v92.m128_f32[0] = v92.m128_f32[0] * 0.0;
    v95 = v93;
    v95.m128_f32[0] = (float)((float)(v93.m128_f32[0] * v93.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    v96 = v95.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v95));
    v97 = v96;
    v98 = v96;
    v99 = v96 * UFG::qVector3::msDirUp.z;
    v100 = v98 * UFG::qVector3::msDirUp.x;
    v101 = v97 * UFG::qVector3::msDirUp.y;
    v104 = v89;
    v104.m128_f32[0] = v89.m128_f32[0] * v99;
    v102 = (float)(v92.m128_f32[0] * v101) - (float)(v94 * v99);
    v103 = v94 * v100;
    v104.m128_f32[0] = v104.m128_f32[0] - (float)(v92.m128_f32[0] * v100);
    v106 = v104;
    v105 = v103 - (float)(v89.m128_f32[0] * v101);
    v106.m128_f32[0] = (float)((float)(v104.m128_f32[0] * v104.m128_f32[0]) + (float)(v102 * v102))
                     + (float)(v105 * v105);
    v107 = v106.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v106));
    v108 = v105 * v107;
    v104.m128_f32[0] = v104.m128_f32[0] * v107;
    v109 = v102 * v107;
    v111 = v92;
    v110 = (float)(v108 * v94) - (float)(v92.m128_f32[0] * v104.m128_f32[0]);
    v111.m128_f32[0] = (float)(v92.m128_f32[0] * v109) - (float)(v108 * v89.m128_f32[0]);
    v113 = v111;
    v112 = (float)(v104.m128_f32[0] * v89.m128_f32[0]) - (float)(v94 * v109);
    v113.m128_f32[0] = (float)((float)(v111.m128_f32[0] * v111.m128_f32[0]) + (float)(v110 * v110))
                     + (float)(v112 * v112);
    v114 = v113.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v113));
    v115 = v3->m_vSoftLockOffset.x;
    v116 = v3->m_vSoftLockOffset.y;
    v117 = v3->m_vSoftLockOffset.z;
    v118 = (float)((float)((float)(v109 * v116) + (float)(v89.m128_f32[0] * v115)) + (float)((float)(v110 * v114) * v117))
         + v7->mWorldTransform.v3.x;
    v104.m128_f32[0] = (float)((float)((float)(v104.m128_f32[0] * v116) + (float)(v94 * v115))
                             + (float)((float)(v111.m128_f32[0] * v114) * v117))
                     + v7->mWorldTransform.v3.y;
    v119 = (float)((float)((float)(v108 * v116) + (float)(v92.m128_f32[0] * v115)) + (float)((float)(v112 * v114) * v117))
         + v7->mWorldTransform.v3.z;
    result.x = v118;
    LODWORD(result.y) = v104.m128_i32[0];
    result.z = v119;
    UFG::qNearestSegPoint(&vTargetNormalAimPosition, &v3->m_vFocusTargetSegA, &v3->m_vFocusTargetSegB, &result);
    v104.m128_f32[0] = (float)((float)((float)(v104.m128_f32[0] - vTargetNormalAimPosition.y)
                                     * (float)(v104.m128_f32[0] - vTargetNormalAimPosition.y))
                             + (float)((float)(v118 - vTargetNormalAimPosition.x)
                                     * (float)(v118 - vTargetNormalAimPosition.x)))
                     + (float)((float)(v119 - vTargetNormalAimPosition.z) * (float)(v119 - vTargetNormalAimPosition.z));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v104)) <= v88 )
      goto LABEL_143;
    goto LABEL_141;
  }
  if ( !v3->m_bFocusTargetProbed )
  {
LABEL_141:
    v120 = v3->m_pTSPPC.m_pSimComponent;
    *(_DWORD *)(&v120[53].m_SimObjIndex + 1) = 3;
    LODWORD(v120[53].m_pSimObject) = 3;
    ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD))v3->m_pTSPPC.m_pSimComponent->vfptr[14].__vecDelDtor)(
      v3->m_pTSPPC.m_pSimComponent,
      22i64,
      0i64);
LABEL_142:
    v3->m_eSoftLockType = 0;
  }
LABEL_143:
  v3->m_bResetSoftLockOffset = 0;
}

// File Line: 1378
// RVA: 0x52FA40
float __fastcall UFG::AimingPlayerComponent::GetReticleSize(UFG::AimingPlayerComponent *this)
{
  float result; // xmm0_4
  UFG::AimingPlayerComponent *v2; // rdi
  __int64 v3; // rbx
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r9
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  __int64 v10; // rax
  float *v11; // rdx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4

  result = this->m_fOverrideReticleSize;
  v2 = this;
  if ( result < 0.0 )
  {
    v3 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
    if ( v3 )
    {
      v4 = this->m_pSimObject;
      if ( !v4 )
        goto LABEL_36;
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = v4->m_Components.p[7].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = v4->m_Components.p[6].m_pComponent;
        }
        else if ( (v5 >> 12) & 1 )
        {
          v7 = (unsigned int)v4[1].vfptr;
          v8 = v4->m_Components.size;
          if ( v7 >= v8 )
          {
LABEL_16:
            v6 = 0i64;
          }
          else
          {
            v9 = (signed __int64)&v4->m_Components.p[v7];
            while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                 || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
            {
              ++v7;
              v9 += 16i64;
              if ( v7 >= v8 )
                goto LABEL_16;
            }
            v6 = *(UFG::SimComponent **)v9;
          }
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(v4, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        v6 = v4->m_Components.p[7].m_pComponent;
      }
      if ( v6
        && (v10 = *((_QWORD *)&v6[11].m_SafePointerList.mNode.mPrev
                  + ((signed __int64)(signed int)gActionRequest_CoverPopoutBlind.m_EnumValue >> 6)),
            _bittest64(&v10, gActionRequest_CoverPopoutBlind.m_EnumValue & 0x3F)) )
      {
        result = *(float *)(*(_QWORD *)(*(_QWORD *)(v3 + 176) + 8i64 * *(unsigned int *)(v3 + 172) + 8) + 36i64);
      }
      else
      {
LABEL_36:
        v11 = *(float **)(*(_QWORD *)(v3 + 176) + 8i64 * *(unsigned int *)(v3 + 172) + 8);
        if ( LODWORD(v2->m_pTSPPC.m_pSimComponent[53].m_pSimObject) == 1 )
          v12 = v11[5];
        else
          v12 = v11[7];
        if ( LODWORD(v2->m_pTSPPC.m_pSimComponent[53].m_pSimObject) == 1 )
          v13 = v11[6];
        else
          v13 = v11[8];
        v14 = v2->m_Accuracy.m_fAccuracyUnclamped;
        if ( v14 <= v2->m_Accuracy.m_fAccuracyMinimum )
          v14 = v2->m_Accuracy.m_fAccuracyMinimum;
        if ( v14 >= v2->m_Accuracy.m_fAccuracyMaximum )
          v14 = v2->m_Accuracy.m_fAccuracyMaximum;
        result = (float)((float)(1.0 - v14) * v13) + (float)(v14 * v12);
      }
    }
    else
    {
      result = 0.0;
    }
  }
  return result;
}

// File Line: 1417
// RVA: 0x54D300
void __fastcall UFG::AimingPlayerComponent::SetFreeAimIntention(UFG::AimingPlayerComponent *this, UFG::qVector3 *vDirection)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = vDirection->y;
  v3 = vDirection->z;
  this->m_vFreeAimIntention.x = vDirection->x;
  this->m_vFreeAimIntention.y = v2;
  this->m_vFreeAimIntention.z = v3;
}

// File Line: 1431
// RVA: 0x56B850
void __fastcall UFG::AimingPlayerComponent::possiblyResetFreeAimIntention(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // rbx
  char v2; // bp
  __int64 v3; // r8
  _DWORD *v4; // rdi
  UFG::AimingPlayerComponent::eSoftLockTypeEnum v5; // eax
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm7_4
  __int64 v9; // rsi
  UFG::TransformNodeComponent *v10; // rsi
  __int64 v11; // rsi
  UFG::TransformNodeComponent *v12; // rsi
  float v13; // xmm14_4
  float v14; // xmm15_4
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm8
  float v20; // xmm5_4
  __m128 v21; // xmm2
  float v22; // xmm7_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm8_4
  float v29; // xmm7_4
  __m128 v30; // xmm9
  float v31; // xmm7_4
  __m128 v32; // xmm2
  float v33; // xmm1_4
  float v34; // xmm7_4
  float v35; // xmm9_4
  float v36; // xmm8_4
  float v37; // xmm11_4
  __m128 v38; // xmm12
  float v39; // xmm13_4
  __m128 v40; // xmm2
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm11_4
  float v45; // xmm12_4
  float v46; // xmm13_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  UFG::SimComponent *v53; // rax
  UFG::SimObject *v54; // rcx
  UFG::BaseCameraComponent *v55; // rax
  signed __int64 v56; // rax
  int v57; // xmm2_4
  float v58; // xmm2_4
  float v59; // xmm4_4
  __m128 v60; // xmm5
  float v61; // xmm6_4
  __m128 v62; // xmm3
  UFG::BaseCameraComponent *v63; // rcx
  float v64; // xmm5_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm2_4
  float v68; // xmm6_4
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+20h] [rbp-B8h]
  float v70; // [rsp+E0h] [rbp+8h]

  v1 = this;
  v2 = 0;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v3 = (unsigned int)v1->m_eSnapFreeAimIntentionToTarget;
  v4 = 0i64;
  if ( (_DWORD)v3 )
  {
    UFG::AimingBaseComponent::GetTargetNormalAimPosition(
      (UFG::AimingBaseComponent *)&v1->vfptr,
      &vTargetNormalAimPosition,
      v3,
      0i64);
    v1->m_eSnapFreeAimIntentionToTarget = 0;
    v2 = 1;
  }
  v5 = v1->m_eSoftLockType;
  switch ( v5 )
  {
    case 1:
      v6 = v1->m_vSoftLockOffset.x;
      v7 = v1->m_vSoftLockOffset.y;
      v8 = v1->m_vSoftLockOffset.z;
      goto LABEL_27;
    case 2:
      v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v1->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                     + *(_QWORD *)&v1->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                     + 40);
      if ( v9 )
      {
        v10 = *(UFG::TransformNodeComponent **)(v9 + 88);
        if ( v10 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v10);
          v6 = (float)((float)((float)(v1->m_vSoftLockOffset.y * v10->mWorldTransform.v1.x)
                             + (float)(v1->m_vSoftLockOffset.x * v10->mWorldTransform.v0.x))
                     + (float)(v1->m_vSoftLockOffset.z * v10->mWorldTransform.v2.x))
             + v10->mWorldTransform.v3.x;
          v7 = (float)((float)((float)(v1->m_vSoftLockOffset.y * v10->mWorldTransform.v1.y)
                             + (float)(v1->m_vSoftLockOffset.x * v10->mWorldTransform.v0.y))
                     + (float)(v1->m_vSoftLockOffset.z * v10->mWorldTransform.v2.y))
             + v10->mWorldTransform.v3.y;
          v8 = (float)((float)((float)(v1->m_vSoftLockOffset.y * v10->mWorldTransform.v1.z)
                             + (float)(v1->m_vSoftLockOffset.x * v10->mWorldTransform.v0.z))
                     + (float)(v1->m_vSoftLockOffset.z * v10->mWorldTransform.v2.z))
             + v10->mWorldTransform.v3.z;
          goto LABEL_27;
        }
      }
      break;
    case 3:
      v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v1->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                      + *(_QWORD *)&v1->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                      + 40);
      if ( v11 )
      {
        v12 = *(UFG::TransformNodeComponent **)(v11 + 88);
        if ( v12 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v12);
          v13 = v12->mWorldTransform.v3.x;
          v14 = v12->mWorldTransform.v3.y;
          v70 = v12->mWorldTransform.v3.z;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_TransformNodeComponent.m_pSimComponent);
          v15 = (__m128)LODWORD(v1->m_vFreeAimOrigin.x);
          v16 = (__m128)LODWORD(v1->m_vFreeAimOrigin.y);
          v15.m128_f32[0] = v15.m128_f32[0] - v13;
          v16.m128_f32[0] = v16.m128_f32[0] - v14;
          v17 = v16;
          v17.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15.m128_f32[0] * v15.m128_f32[0]);
          if ( v17.m128_f32[0] == 0.0 )
          {
            v18 = 0i64;
          }
          else
          {
            v18 = (__m128)(unsigned int)FLOAT_1_0;
            v18.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
          }
          v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          v15.m128_f32[0] = v15.m128_f32[0] * v18.m128_f32[0];
          v20 = v16.m128_f32[0] * v18.m128_f32[0];
          v18.m128_f32[0] = v18.m128_f32[0] * 0.0;
          v21 = v19;
          v21.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( v21.m128_f32[0] == 0.0 )
            v22 = 0.0;
          else
            v22 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v21));
          v23 = v22;
          v24 = v22;
          v25 = v22 * UFG::qVector3::msDirUp.z;
          v26 = v24 * UFG::qVector3::msDirUp.x;
          v27 = v23 * UFG::qVector3::msDirUp.y;
          v30 = v15;
          v30.m128_f32[0] = v15.m128_f32[0] * v25;
          v28 = (float)(v18.m128_f32[0] * v27) - (float)(v20 * v25);
          v29 = v20 * v26;
          v30.m128_f32[0] = v30.m128_f32[0] - (float)(v18.m128_f32[0] * v26);
          v32 = v30;
          v31 = v29 - (float)(v15.m128_f32[0] * v27);
          v32.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v28 * v28))
                          + (float)(v31 * v31);
          if ( v32.m128_f32[0] == 0.0 )
            v33 = 0.0;
          else
            v33 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v32));
          v34 = v31 * v33;
          v35 = v30.m128_f32[0] * v33;
          v36 = v28 * v33;
          v38 = v18;
          v37 = (float)(v34 * v20) - (float)(v18.m128_f32[0] * v35);
          v38.m128_f32[0] = (float)(v18.m128_f32[0] * v36) - (float)(v34 * v15.m128_f32[0]);
          v40 = v38;
          v39 = (float)(v35 * v15.m128_f32[0]) - (float)(v20 * v36);
          v40.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37))
                          + (float)(v39 * v39);
          if ( v40.m128_f32[0] == 0.0 )
            v41 = 0.0;
          else
            v41 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v40));
          v42 = v1->m_vSoftLockOffset.y;
          v43 = v1->m_vSoftLockOffset.z;
          v44 = v37 * v41;
          v45 = v38.m128_f32[0] * v41;
          v46 = v39 * v41;
          v47 = v1->m_vSoftLockOffset.x;
          v6 = (float)((float)((float)(v36 * v42) + (float)(v15.m128_f32[0] * v47)) + (float)(v44 * v43)) + v13;
          v8 = (float)((float)((float)(v34 * v42) + (float)(v18.m128_f32[0] * v47)) + (float)(v46 * v43)) + v70;
          v7 = (float)((float)((float)(v35 * v42) + (float)(v20 * v47)) + (float)(v45 * v43)) + v14;
LABEL_27:
          if ( s_iNumIterations > 0 )
          {
            do
            {
              v48 = v6 - v1->m_vFreeAimOrigin.x;
              v49 = v7 - v1->m_vFreeAimOrigin.y;
              v50 = v8 - v1->m_vFreeAimOrigin.z;
              v51 = (float)((float)(v49 * v49) + (float)(v48 * v48)) + (float)(v50 * v50);
              if ( v51 == 0.0 )
                v52 = 0.0;
              else
                v52 = 1.0 / fsqrt(v51);
              v1->m_vFreeAimIntention.x = v48 * v52;
              v1->m_vFreeAimIntention.y = v49 * v52;
              v1->m_vFreeAimIntention.z = v50 * v52;
              UFG::AimingPlayerComponent::updateFreeAimOrigin(v1, 0.0);
              LODWORD(v4) = (_DWORD)v4 + 1;
            }
            while ( (signed int)v4 < s_iNumIterations );
          }
          return;
        }
      }
      break;
  }
  if ( v2 )
  {
    v8 = vTargetNormalAimPosition.z;
    v7 = vTargetNormalAimPosition.y;
    v6 = vTargetNormalAimPosition.x;
    goto LABEL_27;
  }
  v1->m_eSoftLockType = 0;
  if ( !v1->m_bAimingControlsCamera )
  {
    if ( v1->m_CharacterOccupantComponent.m_pSimComponent
      && (v53 = v1->m_CharacterOccupantComponent.m_pSimComponent, v53[1].m_BoundComponentHandles.mNode.mPrev)
      && (v54 = (UFG::SimObject *)v53[1].m_BoundComponentHandles.mNode.mPrev[2].mNext) != 0i64
      && v54->m_pTransformNodeComponent
      && !UFG::SimObjectUtility::IsBoat(v54) )
    {
      v55 = UFG::Director::Get()->mCurrentCamera;
      if ( v55 )
        v56 = (signed __int64)&v55->mCamera;
      else
        v56 = 0i64;
      v57 = *(_DWORD *)(v56 + 164) ^ _xmm[0];
      LODWORD(v1->m_vFreeAimIntention.x) = *(_DWORD *)(v56 + 160) ^ _xmm[0];
      LODWORD(v1->m_vFreeAimIntention.y) = v57;
      v58 = 0.0;
      v1->m_vFreeAimIntention.z = 0.0;
      v59 = v1->m_vFreeAimIntention.y;
      v60 = (__m128)LODWORD(v1->m_vFreeAimIntention.x);
      v61 = v1->m_vFreeAimIntention.z;
      v62 = v60;
      v62.m128_f32[0] = (float)((float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(v59 * v59)) + (float)(v61 * v61);
      if ( v62.m128_f32[0] != 0.0 )
        v58 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v62));
      v1->m_vFreeAimIntention.x = v58 * v60.m128_f32[0];
      v1->m_vFreeAimIntention.y = v58 * v59;
      v1->m_vFreeAimIntention.z = v58 * v61;
    }
    else
    {
      v63 = UFG::Director::Get()->mCurrentCamera;
      if ( v63 )
        v4 = (_DWORD *)&v63->mCamera.mFOVOffset;
      v64 = 0.0;
      LODWORD(v65) = v4[41] ^ _xmm[0];
      LODWORD(v66) = v4[42] ^ _xmm[0];
      LODWORD(v67) = v4[40] ^ _xmm[0];
      v1->m_vFreeAimIntention.x = v67;
      v1->m_vFreeAimIntention.y = v65;
      v1->m_vFreeAimIntention.z = v66;
      v68 = (float)((float)(v65 * v65) + (float)(v67 * v67)) + (float)(v66 * v66);
      if ( v68 != 0.0 )
        v64 = 1.0 / fsqrt(v68);
      v1->m_vFreeAimIntention.x = v67 * v64;
      v1->m_vFreeAimIntention.y = v65 * v64;
      v1->m_vFreeAimIntention.z = v66 * v64;
    }
  }
}

// File Line: 1545
// RVA: 0x573390
void __fastcall UFG::AimingPlayerComponent::updateFreeAimInput(UFG::AimingPlayerComponent *this, const float fDeltaS)
{
  UFG::SimComponent *v2; // rbp
  UFG::AimingPlayerComponent *v3; // rdi
  float v4; // xmm15_4
  float v5; // xmm9_4
  UFG::LinearGraph<float> *v6; // r14
  float v7; // xmm14_4
  __int64 v8; // rax
  __int64 v9; // rdx
  float v10; // xmm12_4
  UFG::SimComponent *v11; // rbx
  float v12; // xmm6_4
  float v13; // xmm7_4
  UFG::SimObject *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // r9
  unsigned int v17; // er8
  unsigned int v18; // er9
  signed __int64 v19; // rdx
  __int64 v20; // rax
  char v21; // al
  float *v22; // rsi
  UFG::GameStatTracker *v23; // rax
  float v24; // xmm6_4
  UFG::GameStatTracker *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm11_4
  float v28; // xmm10_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm14_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  UFG::Controller *v38; // rax
  bool v39; // si
  UFG::GameStatTracker *v40; // rax
  bool v41; // al
  UFG::SimComponent *v42; // rax
  UFG::SimObject *v43; // rcx
  unsigned __int16 v44; // dx
  unsigned int v45; // er8
  unsigned int v46; // er9
  signed __int64 v47; // rdx
  __int64 v48; // rcx
  __int64 v49; // rax
  __int64 v50; // rax
  float v51; // xmm0_4
  int v52; // [rsp+20h] [rbp-E8h]
  float v53; // [rsp+24h] [rbp-E4h]
  float v54; // [rsp+28h] [rbp-E0h]
  int v55; // [rsp+2Ch] [rbp-DCh]
  int v56; // [rsp+30h] [rbp-D8h]
  float v57; // [rsp+34h] [rbp-D4h]
  float v58; // [rsp+38h] [rbp-D0h]
  int v59; // [rsp+3Ch] [rbp-CCh]
  UFG::LinearGraph<float> v60; // [rsp+40h] [rbp-C8h]

  v2 = this->m_pTSPPC.m_pSimComponent;
  v3 = this;
  v4 = fDeltaS;
  if ( v2 )
  {
    v52 = 0;
    v55 = 1065353216;
    v56 = 0;
    v5 = *(float *)&FLOAT_1_0;
    v53 = FLOAT_0_5;
    v60.fDomain = (const float *)&v52;
    v59 = 1065353216;
    v54 = FLOAT_0_80000001;
    v58 = FLOAT_0_30000001;
    v60.tRange = (const float *)&v56;
    v60.nData = 4;
    v6 = &v60;
    v7 = FLOAT_1_5;
    v57 = FLOAT_0_1;
    v8 = *(_QWORD *)&v2[8].m_TypeUID;
    if ( v8 )
    {
      v9 = *(_QWORD *)(*(_QWORD *)(v8 + 176) + 8i64 * *(unsigned int *)(v8 + 172) + 8);
      v7 = *(float *)(v9 + 280);
      v6 = (UFG::LinearGraph<float> *)(v9 + 376);
    }
    v10 = FLOAT_N1_0;
    v11 = 0i64;
    v12 = 0.0;
    v13 = 0.0;
    if ( BYTE3(v2[52].m_BoundComponentHandles.mNode.mPrev) )
    {
      v14 = this->m_pSimObject;
      if ( !v14 )
        goto LABEL_106;
      v15 = v14->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = v14->m_Components.p[7].m_pComponent;
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = v14->m_Components.p[6].m_pComponent;
        }
        else if ( (v15 >> 12) & 1 )
        {
          v17 = (unsigned int)v14[1].vfptr;
          v18 = v14->m_Components.size;
          if ( v17 >= v18 )
          {
LABEL_18:
            v16 = 0i64;
          }
          else
          {
            v19 = (signed __int64)&v14->m_Components.p[v17];
            while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                 || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF )
            {
              ++v17;
              v19 += 16i64;
              if ( v17 >= v18 )
                goto LABEL_18;
            }
            v16 = *(UFG::SimComponent **)v19;
          }
        }
        else
        {
          v16 = UFG::SimObject::GetComponentOfType(v14, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        v16 = v14->m_Components.p[7].m_pComponent;
      }
      if ( v16
        && (v20 = *((_QWORD *)&v16[11].m_SafePointerList.mNode.mPrev
                  + ((signed __int64)(signed int)gActionRequest_CameraZoom.m_EnumValue >> 6)),
            _bittest64(&v20, gActionRequest_CameraZoom.m_EnumValue & 0x3F)) )
      {
        v21 = 1;
      }
      else
      {
LABEL_106:
        v21 = 0;
      }
      v22 = (float *)&v2[53].m_TypeUID;
      if ( LODWORD(v2[53].m_pSimObject) != 4 )
        v22 = (float *)&v2[53].m_SafePointerList;
      if ( v21
        || (v23 = UFG::GameStatTracker::Instance(), !(unsigned __int8)UFG::GameStatTracker::GetStat(v23, XAxisInverted)) )
      {
        v24 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v24 = FLOAT_N1_0;
      }
      LODWORD(v12) = COERCE_UNSIGNED_INT(v24 * *v22) ^ _xmm[0];
      v25 = UFG::GameStatTracker::Instance();
      if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v25, YAxisInverted) )
        v13 = -1.0 * v22[1];
      else
        v13 = 1.0 * v22[1];
    }
    else
    {
      *(_QWORD *)&this->m_fAxisXSpeed = 0i64;
      *(_QWORD *)&this->m_fDampenedAxisXSpeed = 0i64;
    }
    if ( BYTE4(v2[53].vfptr) )
    {
      v3->m_fDampenedAxisXSpeed = UFG::AimingPlayerComponent::ms_fMouseSensitivityH * v12;
      v26 = UFG::AimingPlayerComponent::ms_fMouseSensitivityV * v13;
    }
    else
    {
      if ( v12 <= 0.0 )
      {
        if ( v12 >= 0.0 )
          v27 = 0.0;
        else
          v27 = FLOAT_N1_0;
      }
      else
      {
        v27 = *(float *)&FLOAT_1_0;
      }
      if ( v13 <= 0.0 )
      {
        if ( v13 >= 0.0 )
          v28 = 0.0;
        else
          v28 = FLOAT_N1_0;
      }
      else
      {
        v28 = *(float *)&FLOAT_1_0;
      }
      v29 = UFG::LinearGraph<float>::GetValue(v6, COERCE_CONST_FLOAT(LODWORD(v12) & _xmm));
      v30 = UFG::LinearGraph<float>::GetValue(v6, COERCE_CONST_FLOAT(LODWORD(v13) & _xmm));
      v31 = v3->m_fAxisXSpeed;
      v32 = v30;
      if ( v31 <= 0.0 )
      {
        if ( v31 >= 0.0 )
          v33 = 0.0;
        else
          v33 = FLOAT_N1_0;
      }
      else
      {
        v33 = *(float *)&FLOAT_1_0;
      }
      if ( v27 != v33 )
        v3->m_fAxisXSpeed = 0.0;
      v34 = v3->m_fAxisYSpeed;
      if ( v34 <= 0.0 )
      {
        if ( v34 >= 0.0 )
          v10 = 0.0;
      }
      else
      {
        v10 = *(float *)&FLOAT_1_0;
      }
      if ( v28 != v10 )
        v3->m_fAxisYSpeed = 0.0;
      v35 = v7 * v4;
      v36 = COERCE_FLOAT(LODWORD(v3->m_fAxisXSpeed) & _xmm) + v35;
      if ( v36 >= v29 )
        v36 = v29;
      v3->m_fAxisXSpeed = v36 * v27;
      v37 = COERCE_FLOAT(LODWORD(v3->m_fAxisYSpeed) & _xmm) + v35;
      if ( v37 >= v32 )
        v37 = v32;
      v3->m_fAxisYSpeed = v37 * v28;
      v39 = 0;
      if ( UFG::gInputSystem )
      {
        v38 = UFG::InputSystem::AcquireController(UFG::gInputSystem, 0);
        if ( v38 )
        {
          if ( v38->m_IsKeyboardController )
            v39 = 1;
        }
      }
      v40 = UFG::GameStatTracker::Instance();
      v41 = UFG::GameStatTracker::GetStat(v40, AimSoftLockEnabled);
      if ( UFG::AimingPlayerComponent::ms_bFreeAimSpeedModifierEnabled
        && LOBYTE(v2[52].m_BoundComponentHandles.mNode.mNext)
        && !v3->m_bPreventFreeAimSpeedModifier
        && !v3->m_bCameraZoomMode
        && !v39
        && v41
        && (float)(UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierCapsuleExpansionRatio * v3->m_fFocusTargetRadius) >= v3->m_fFocusTargetDistanceSeg )
      {
        v42 = v3->m_CharacterOccupantComponent.m_pSimComponent;
        if ( v42 && v42[1].m_BoundComponentHandles.mNode.mPrev && v42[1].m_BoundComponentHandles.mNode.mPrev[2].mNext )
        {
          v5 = UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierDriving;
        }
        else
        {
          v43 = v3->m_pSimObject;
          if ( !v43 )
            goto LABEL_107;
          v44 = v43->m_Flags;
          if ( (v44 >> 14) & 1 )
          {
            v11 = v43->m_Components.p[7].m_pComponent;
          }
          else if ( (v44 & 0x8000u) == 0 )
          {
            if ( (v44 >> 13) & 1 )
            {
              v11 = v43->m_Components.p[6].m_pComponent;
            }
            else if ( (v44 >> 12) & 1 )
            {
              v45 = (unsigned int)v43[1].vfptr;
              v46 = v43->m_Components.size;
              if ( v45 < v46 )
              {
                v47 = (signed __int64)&v43->m_Components.p[v45];
                while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                     || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF )
                {
                  ++v45;
                  v47 += 16i64;
                  if ( v45 >= v46 )
                    goto LABEL_96;
                }
                v11 = *(UFG::SimComponent **)v47;
              }
            }
            else
            {
              v11 = UFG::SimObject::GetComponentOfType(v43, UFG::ActionTreeComponent::_TypeUID);
            }
          }
          else
          {
            v11 = v43->m_Components.p[7].m_pComponent;
          }
LABEL_96:
          if ( !v11 )
            goto LABEL_107;
          v48 = *((_QWORD *)&v11[11].m_SafePointerList.mNode.mPrev
                + ((signed __int64)(signed int)gActionRequest_Walk.m_EnumValue >> 6));
          if ( _bittest64(&v48, gActionRequest_Walk.m_EnumValue & 0x3F)
            || (v49 = *((_QWORD *)&v11[11].m_SafePointerList.mNode.mPrev
                      + ((signed __int64)(signed int)gActionRequest_Jog.m_EnumValue >> 6)),
                _bittest64(&v49, gActionRequest_Jog.m_EnumValue & 0x3F))
            || (v50 = *((_QWORD *)&v11[11].m_SafePointerList.mNode.mPrev
                      + ((signed __int64)(signed int)gActionRequest_Sprint.m_EnumValue >> 6)),
                _bittest64(&v50, gActionRequest_Sprint.m_EnumValue & 0x3F)) )
          {
            v5 = UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierMoving;
          }
          else
          {
LABEL_107:
            v5 = UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierIdle;
          }
        }
      }
      UFG::qApproach(
        &v3->m_fFreeAimSpeedModifier,
        v5,
        UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierBlendRate,
        v4);
      v51 = v3->m_fFreeAimSpeedModifier;
      v26 = v51 * v3->m_fAxisYSpeed;
      v3->m_fDampenedAxisXSpeed = v51 * v3->m_fAxisXSpeed;
    }
    v3->m_fDampenedAxisYSpeed = v26;
  }
}

// File Line: 1708
// RVA: 0x573A90
void __usercall UFG::AimingPlayerComponent::updateFreeAimIntention(UFG::AimingPlayerComponent *this@<rcx>, const float fDeltaS@<xmm1>, float a3@<xmm0>)
{
  UFG::SimComponent *v3; // rax
  UFG::AimingPlayerComponent *v4; // rdi
  float v5; // xmm11_4
  __int64 v6; // rax
  float v7; // xmm6_4
  float v8; // xmm10_4
  __int64 v9; // r8
  float *v10; // rsi
  UFG::BaseCameraComponent *v11; // rax
  _DWORD *v12; // rbp
  UFG::BaseCameraComponent *v13; // rbx
  UFG::BaseCameraComponent *v14; // r14
  float v15; // xmm7_4
  float v16; // xmm9_4
  UFG::GameStatTracker *v17; // rax
  float v18; // xmm12_4
  UFG::GameStatTracker *v19; // rax
  float v20; // xmm0_4
  __m128 v21; // xmm2
  float v22; // xmm6_4
  float v23; // xmm8_4
  float v24; // xmm0_4
  float v25; // xmm8_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  signed __int64 v30; // rcx
  float v31; // xmm8_4
  float v32; // xmm7_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  UFG::SimComponent *v35; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rbx
  UFG::TransformNodeComponent *v37; // rbx
  float v38; // xmm0_4
  float v39; // xmm10_4
  int v40; // xmm0_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  UFG::SimObject *v43; // rcx
  UFG::BaseCameraComponent *v44; // rcx
  int v45; // xmm1_4
  int v46; // xmm0_4

  v3 = this->m_pTSPPC.m_pSimComponent;
  v4 = this;
  v5 = fDeltaS;
  if ( v3 )
  {
    v6 = *(_QWORD *)&v3[8].m_TypeUID;
    v7 = UFG::AimingPlayerComponent::default_fAimYawPerS;
    v8 = UFG::AimingPlayerComponent::default_fAimPitchPerS;
    if ( v6 )
    {
      v9 = *(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8);
      v7 = *(float *)(v9 + 272);
      v8 = *(float *)(v9 + 276);
    }
    v10 = (float *)UFG::GetCurrentGameCamera();
    v11 = UFG::GetCurrentBaseCamera();
    v12 = 0i64;
    v13 = v11;
    if ( !v11
      || (v14 = v11,
          !UFG::SimComponent::IsType(
             (UFG::SimComponent *)&v11->vfptr,
             UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID)) )
    {
      v14 = 0i64;
    }
    if ( !v13
      || !UFG::SimComponent::IsType(
            (UFG::SimComponent *)&v13->vfptr,
            UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
    {
      v13 = 0i64;
    }
    if ( v10 )
    {
      (*(void (__fastcall **)(float *))(*(_QWORD *)v10 + 152i64))(v10);
      v15 = tanf(a3 * 0.5) * 1.8;
    }
    else
    {
      v15 = *(float *)&FLOAT_1_0;
    }
    v16 = fDeltaS;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      v16 = FLOAT_0_011111111;
    v17 = UFG::GameStatTracker::Instance();
    v18 = (float)((float)((float)((float)(UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedYawMax
                                        - UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedYawMin)
                                * UFG::GameStatTracker::GetStat(v17, AimSpeedYaw))
                        + UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedYawMin)
                * (float)((float)(v15 * v4->m_fDampenedAxisXSpeed) * v7))
        * v16;
    v19 = UFG::GameStatTracker::Instance();
    v20 = UFG::GameStatTracker::GetStat(v19, AimSpeedPitch);
    v21 = (__m128)LODWORD(v4->m_vFreeAimIntention.x);
    v22 = v20;
    v21.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0])
                    + (float)(v4->m_vFreeAimIntention.y * v4->m_vFreeAimIntention.y);
    v23 = atan2f(v4->m_vFreeAimIntention.z, COERCE_FLOAT(_mm_sqrt_ps(v21)));
    v24 = UFG::AimingPlayerComponent::ms_fFreeAimLatitudeMin;
    v25 = v23
        + (float)((float)((float)((float)((float)(UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedPitchMax
                                                - UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedPitchMin)
                                        * v22)
                                + UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedPitchMin)
                        * (float)((float)(v15 * v4->m_fDampenedAxisYSpeed) * v8))
                * v16);
    v26 = UFG::AimingPlayerComponent::ms_fFreeAimLatitudeMax;
    if ( v14 )
    {
      v24 = *(float *)&v14[4].m_SafePointerList.mNode.mNext;
      v26 = *((float *)&v14[4].m_SafePointerList.mNode.mNext + 1);
    }
    else if ( v13 )
    {
      LODWORD(v24) = LODWORD(v13[10].mCamera.mTransformation.v2.y) ^ _xmm[0];
      LODWORD(v26) = LODWORD(v13[10].mCamera.mTransformation.v2.x) ^ _xmm[0];
    }
    if ( v25 <= v24 )
      v25 = v24;
    if ( v25 >= v26 )
      v25 = v26;
    v27 = atan2f(v4->m_vFreeAimIntention.y, v4->m_vFreeAimIntention.x);
    v28 = UFG::qVector2::msZero.x;
    v29 = UFG::qVector2::msZero.y;
    if ( v10 )
    {
      v28 = v10[280];
      v29 = v10[281];
    }
    v30 = (signed __int64)&v4->m_AimingFreeAimConeClampTaskList.mNode.mPrev[-3].mNext;
    v31 = v25 + (float)((float)(v29 * 3.1415927) * 0.0055555557);
    v32 = (float)(v27 + v18) + (float)((float)(v28 * 3.1415927) * 0.0055555557);
    if ( (UFG::qVector3 *)v30 == &v4->m_vSoftLockOffset )
      v33 = FLOAT_3_1415927;
    else
      v33 = *(float *)(*(_QWORD *)(v30 + 24) + 56i64);
    if ( v33 < v4->m_fInterpolatedFreeAimConeClamp )
      UFG::qApproach(
        &v4->m_fInterpolatedFreeAimConeClamp,
        v33,
        UFG::AimingPlayerComponent::ms_fFreeAimConeClampRate,
        v5);
    else
      v4->m_fInterpolatedFreeAimConeClamp = v33;
    v34 = v4->m_fInterpolatedFreeAimConeClamp - 3.1415927;
    if ( v34 < 0.0 )
      LODWORD(v34) ^= _xmm[0];
    if ( v34 >= 0.001 )
    {
      v35 = v4->m_CharacterOccupantComponent.m_pSimComponent;
      if ( !v35
        || !v35[1].m_BoundComponentHandles.mNode.mPrev
        || (v36 = v35[1].m_BoundComponentHandles.mNode.mPrev[2].mNext) == 0i64
        || (v37 = (UFG::TransformNodeComponent *)v36[5].mNext) == 0i64 )
      {
        v37 = (UFG::TransformNodeComponent *)v4->m_TransformNodeComponent.m_pSimComponent;
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v37);
      v38 = atan2f(v37->mWorldTransform.v0.y, v37->mWorldTransform.v0.x);
      v39 = v38;
      *(float *)&v40 = UFG::qSignedMod((float)(v32 - v38) + 3.1415927, 6.2831855) - 3.1415927;
      if ( *(float *)&v40 <= COERCE_FLOAT(LODWORD(v4->m_fInterpolatedFreeAimConeClamp) ^ _xmm[0]) )
        v40 = LODWORD(v4->m_fInterpolatedFreeAimConeClamp) ^ _xmm[0];
      if ( *(float *)&v40 >= v4->m_fInterpolatedFreeAimConeClamp )
        v40 = SLODWORD(v4->m_fInterpolatedFreeAimConeClamp);
      v32 = UFG::qSignedMod(*(float *)&v40 + v39, 6.2831855);
    }
    v41 = cosf(v31);
    v4->m_vFreeAimIntention.x = cosf(v32) * v41;
    v4->m_vFreeAimIntention.y = sinf(v32) * v41;
    v42 = sinf(v31);
    v43 = v4->m_pSimObject;
    v4->m_vFreeAimIntention.z = v42;
    if ( UFG::IsAnyLocalPlayer(v43) && !UFG::IsAnyLocalPlayer(v4->m_pSimObject) )
    {
      v44 = UFG::Director::Get()->mCurrentCamera;
      if ( v44 )
        v12 = (_DWORD *)&v44->mCamera.mFOVOffset;
      v45 = v12[41] ^ _xmm[0];
      v46 = v12[42] ^ _xmm[0];
      LODWORD(v4->m_vFreeAimIntention.x) = v12[40] ^ _xmm[0];
      LODWORD(v4->m_vFreeAimIntention.y) = v45;
      LODWORD(v4->m_vFreeAimIntention.z) = v46;
    }
  }
}

// File Line: 1848
// RVA: 0x579340
void __fastcall UFG::AimingPlayerComponent::updateTargetDimensions(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // r14
  UFG::SimObject *v2; // rcx
  __m128 v3; // xmm2
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  __int64 v13; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                          + *(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                          + 40);
  if ( v2 )
  {
    v13 = 0i64;
    UFG::SimObjectUtility::GetObjectCapsuleApproximation(
      v2,
      (UFG::qMatrix44 **)&v13,
      &v1->m_vFocusTargetSegA,
      &v1->m_vFocusTargetSegB,
      &v1->m_fFocusTargetRadius);
    UFG::qNearestRaySeg(
      &v1->m_vFreeAimOrigin,
      &v1->m_vFreeAimIntention,
      &v1->m_vFocusTargetSegA,
      &v1->m_vFocusTargetSegB,
      &v1->m_vFocusTargetClosestPos,
      &v1->m_vFocusTargetSegClosestPos);
    v3 = (__m128)LODWORD(v1->m_vFocusTargetClosestPos.y);
    v4 = v1->m_vFocusTargetClosestPos.z - v1->m_vFocusTargetSegClosestPos.z;
    v3.m128_f32[0] = (float)((float)((float)(v3.m128_f32[0] - v1->m_vFocusTargetSegClosestPos.y)
                                   * (float)(v3.m128_f32[0] - v1->m_vFocusTargetSegClosestPos.y))
                           + (float)((float)(v1->m_vFocusTargetClosestPos.x - v1->m_vFocusTargetSegClosestPos.x)
                                   * (float)(v1->m_vFocusTargetClosestPos.x - v1->m_vFocusTargetSegClosestPos.x)))
                   + (float)(v4 * v4);
    LODWORD(v1->m_fFocusTargetDistanceSeg) = (unsigned __int128)_mm_sqrt_ps(v3);
  }
  else
  {
    v5 = UFG::qVector3::msZero.y;
    v6 = UFG::qVector3::msZero.z;
    v1->m_vFocusTargetSegA.x = UFG::qVector3::msZero.x;
    v1->m_vFocusTargetSegA.y = v5;
    v1->m_vFocusTargetSegA.z = v6;
    v7 = UFG::qVector3::msZero.y;
    v8 = UFG::qVector3::msZero.z;
    v1->m_vFocusTargetSegB.x = UFG::qVector3::msZero.x;
    v1->m_vFocusTargetSegB.y = v7;
    v1->m_vFocusTargetSegB.z = v8;
    v9 = UFG::qVector3::msZero.y;
    v10 = UFG::qVector3::msZero.z;
    v1->m_vFocusTargetClosestPos.x = UFG::qVector3::msZero.x;
    v1->m_vFocusTargetClosestPos.y = v9;
    v1->m_vFocusTargetClosestPos.z = v10;
    v11 = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
    v1->m_vFocusTargetSegClosestPos.x = UFG::qVector3::msZero.x;
    v1->m_vFocusTargetSegClosestPos.y = v11;
    v1->m_vFocusTargetSegClosestPos.z = v12;
    v1->m_fFocusTargetRadius = 0.0;
    v1->m_fFocusTargetDistanceSeg = 3.4028235e38;
  }
}

// File Line: 1885
// RVA: 0x5683C0
float __fastcall UFG::AimingPlayerComponent::getDistanceFromFreeAimOriginToStartRaycast(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // rbx
  UFG::SimObject *v2; // rcx
  float v3; // xmm9_4
  unsigned __int16 v4; // dx
  UFG::CharacterPhysicsComponent *v5; // rax
  unsigned int v6; // er8
  unsigned int v7; // er10
  signed __int64 v8; // rdx
  unsigned int v9; // er8
  unsigned int v10; // er10
  unsigned int v11; // er8
  unsigned int v12; // er10
  UFG::SimComponent *v13; // rdi
  float v14; // xmm6_4
  __m128 v15; // xmm7
  float v16; // xmm3_4
  __m128 v17; // xmm2
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float result; // xmm0_4
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+20h] [rbp-58h]

  v1 = this;
  v2 = this->m_pSimObject;
  v3 = FLOAT_0_60000002;
  if ( !v2 )
    goto LABEL_29;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::CharacterPhysicsComponent *)v2->m_Components.p[27].m_pComponent;
    goto LABEL_27;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v6 = (unsigned int)v2[1].vfptr;
    v7 = v2->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v6;
        v8 += 16i64;
        if ( v6 >= v7 )
          goto LABEL_10;
      }
LABEL_11:
      v5 = *(UFG::CharacterPhysicsComponent **)v8;
      goto LABEL_27;
    }
    goto LABEL_10;
  }
  if ( (v4 >> 13) & 1 )
  {
    v9 = (unsigned int)v2[1].vfptr;
    v10 = v2->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
        {
          v5 = 0i64;
          goto LABEL_27;
        }
      }
      goto LABEL_11;
    }
LABEL_10:
    v5 = 0i64;
    goto LABEL_27;
  }
  if ( (v4 >> 12) & 1 )
  {
    v11 = (unsigned int)v2[1].vfptr;
    v12 = v2->m_Components.size;
    if ( v11 < v12 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v11];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v11;
        v8 += 16i64;
        if ( v11 >= v12 )
        {
          v5 = 0i64;
          goto LABEL_27;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  v5 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                           v2,
                                           UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_27:
  if ( v5 )
    v3 = UFG::CharacterPhysicsComponent::GetRadius(v5);
LABEL_29:
  v13 = v1->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_TransformNodeComponent.m_pSimComponent);
  v14 = v1->m_vFreeAimIntention.x;
  v15 = (__m128)LODWORD(v1->m_vFreeAimIntention.y);
  v16 = 0.0;
  v17 = v15;
  v17.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14);
  if ( v17.m128_f32[0] != 0.0 )
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
  v18 = v14 * v16;
  v19 = v15.m128_f32[0] * v16;
  v20 = (float)((float)((float)(*((float *)&v13[2].m_BoundComponentHandles.mNode.mPrev + 1) - v1->m_vFreeAimOrigin.y)
                      * v19)
              + (float)((float)(*(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev - v1->m_vFreeAimOrigin.x) * v18))
      + v3;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(
    (UFG::AimingBaseComponent *)&v1->vfptr,
    &vWeaponProjectileSpawnPosition);
  result = (float)((float)(vWeaponProjectileSpawnPosition.y - v1->m_vFreeAimOrigin.y) * v19)
         + (float)((float)(vWeaponProjectileSpawnPosition.x - v1->m_vFreeAimOrigin.x) * v18);
  if ( v20 > result )
    result = v20;
  return result;
}

// File Line: 1926
// RVA: 0x533600
char __fastcall UFG::AimingPlayerComponent::GetWeaponProjectileSpawnPositionUnobscured(UFG::AimingPlayerComponent *this, UFG::qVector3 *vToPosition, UFG::qVector3 *vPositionReturn)
{
  UFG::qVector3 *v3; // rbx
  UFG::qVector3 *v4; // rdi
  UFG::AimingPlayerComponent *v5; // rsi
  float v6; // xmm4_4
  float v7; // xmm8_4
  float v8; // xmm5_4
  float v9; // xmm7_4
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  float v12; // xmm1_4
  float v13; // xmm8_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  __int64 v20; // rcx
  __int64 v21; // rcx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v22; // rcx
  const char *v23; // rax
  bool v24; // di
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-D8h]
  UFG::qReflectHandleBase v31; // [rsp+30h] [rbp-C8h]
  __int64 v32; // [rsp+58h] [rbp-A0h]
  UFG::RayCastData data; // [rsp+60h] [rbp-98h]

  v32 = -2i64;
  v3 = vPositionReturn;
  v4 = vToPosition;
  v5 = this;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition((UFG::AimingBaseComponent *)&this->vfptr, vPositionReturn);
  if ( !UFG::AimingPlayerComponent::ms_bEnableObscuredAimCheck || !(*((_BYTE *)v5 + 848) & 1) )
    return 0;
  v6 = v3->z;
  v7 = v3->z - v4->z;
  v8 = v3->y;
  v9 = v3->y - v4->y;
  v10 = (__m128)LODWORD(v3->x);
  v10.m128_f32[0] = v10.m128_f32[0] - v4->x;
  v11 = v10;
  v11.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v7 * v7);
  v12 = v11.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v7 * v12;
  v14 = v9 * v12;
  v15 = v10.m128_f32[0] * v12;
  v16 = v5->m_fUnobscuredAimCheckDistance;
  if ( (float)(v16 * v16) > v11.m128_f32[0] || v16 <= 0.0 )
  {
    v17 = v5->m_fUnobscuredAimTargetPositionPadDistance;
    v18 = (float)(v14 * v17) + v4->y;
    v19 = (float)(v13 * v17) + v4->z;
    rayStart.x = (float)(v15 * v17) + v4->x;
    rayStart.y = v18;
    rayStart.z = v19;
  }
  else
  {
    rayStart.x = v3->x - (float)(v15 * v16);
    rayStart.y = v8 - (float)(v14 * v16);
    rayStart.z = v6 - (float)(v13 * v16);
  }
  data.mInput.m_to.m_quad.m128_i8[8] = 0;
  data.mInput.m_to.m_quad.m128_i32[3] = 0;
  *(_QWORD *)&data.mInput.m_enableShapeCollectionFilter.m_bool = 0i64;
  data.mOutput.m_normal.m_quad.m128_u64[1] = -3229614080i64;
  data.mOutput.m_shapeKeys[6] = 0;
  data.mOutput.m_pad[0] = -1;
  *((_QWORD *)&data.mOutput.m_shapeKeyIndex + 1) = 0i64;
  *((_QWORD *)&data.mOutput.m_rootCollidable + 1) = 0i64;
  LODWORD(data.mDebugName) = -1;
  UFG::RayCastData::Init(&data, &rayStart, v3, 0x19u);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  if ( *(_QWORD *)&data.normal.z )
  {
    v20 = *(_QWORD *)(*(_QWORD *)&data.normal.z + 24i64);
    if ( v20 )
    {
      v21 = *(_QWORD *)(v20 + 24);
      if ( v21 )
      {
        if ( *(_QWORD *)(v21 + 40) && (*(_WORD *)(*(_QWORD *)(v21 + 40) + 76i64) >> 14) & 1 )
          return 0;
      }
    }
  }
  UFG::qReflectHandleBase::qReflectHandleBase(&v31);
  v23 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v22);
  v31.mTypeUID = UFG::qStringHash64(v23, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v31, v31.mTypeUID, data.mPhysicsObjectPropertyHandleUid);
  v24 = v31.mData && *(float *)&v31.mData[1].mBaseNode.mUID > 0.0;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v31);
  if ( v24 )
    return 0;
  v25 = v5->m_fUnobscuredAimNewPositionPadDistance;
  v26 = *((float *)&data.mDebugName + 1) - (float)(v15 * v25);
  v27 = *(float *)&data.mCollisionModelName.mUID - (float)(v14 * v25);
  v28 = data.point.x - (float)(v13 * v25);
  v3->x = v26;
  v3->y = v27;
  v3->z = v28;
  return 1;
}

// File Line: 1996
// RVA: 0x5750C0
void __fastcall UFG::AimingPlayerComponent::updateFreeAimTargetPosition(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // r14
  Render::DebugDrawContext *v2; // rsi
  __int64 v3; // r15
  float *v4; // r13
  float v5; // xmm2_4
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm3_4
  int v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float *v14; // rbx
  float v15; // xmm2_4
  float v16; // xmm0_4
  float *v17; // r12
  UFG::SimComponent *v18; // rax
  char v19; // di
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm12_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  __m128 v25; // xmm6
  __m128 v26; // xmm2
  float v27; // xmm11_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v33; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  int v36; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v37; // rcx
  const char *v38; // rax
  UFG::qVector3 *v39; // rax
  unsigned int v40; // xmm3_4
  unsigned int v41; // xmm2_4
  __int64 v42; // rcx
  __int64 v43; // rbx
  unsigned __int16 v44; // cx
  UFG::SimComponent *v45; // rax
  unsigned int v46; // er8
  unsigned int v47; // er10
  __int64 v48; // rdi
  int v49; // edx
  unsigned __int16 v50; // cx
  UFG::SimComponent *v51; // rax
  unsigned int v52; // er8
  unsigned int v53; // er10
  __int64 v54; // rdi
  signed __int64 v55; // rdx
  unsigned int v56; // er8
  unsigned int v57; // er10
  unsigned int v58; // er8
  unsigned int v59; // er10
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v60; // rcx
  unsigned __int16 v61; // cx
  UFG::SimComponent *v62; // rdx
  unsigned int v63; // er8
  unsigned int v64; // er10
  __int64 v65; // rdi
  signed __int64 v66; // rdx
  unsigned int v67; // er8
  unsigned int v68; // er10
  signed __int64 v69; // rax
  __int64 v70; // rcx
  unsigned __int16 v71; // cx
  unsigned int v72; // er8
  unsigned int v73; // er10
  __int64 v74; // rdi
  signed __int64 v75; // rdx
  UFG::SimComponent *v76; // rdi
  unsigned int v77; // er8
  unsigned int v78; // er10
  unsigned int v79; // er8
  unsigned int v80; // er10
  unsigned int v81; // er8
  unsigned int v82; // er10
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v83; // rcx
  const char *v84; // rax
  __int64 v85; // rdx
  float *v86; // rbx
  float v87; // xmm7_4
  __m128 v88; // xmm8
  float v89; // xmm6_4
  float v90; // xmm1_4
  __m128 v91; // xmm2
  float v92; // xmm0_4
  __m128 v93; // xmm2
  float v94; // xmm5_4
  float v95; // xmm6_4
  float v96; // xmm0_4
  float v97; // xmm3_4
  UFG::qVector3 v98; // [rsp+40h] [rbp-98h]
  __int128 rayStart; // [rsp+50h] [rbp-88h]
  UFG::qReflectHandleBase v100; // [rsp+60h] [rbp-78h]
  char v101; // [rsp+88h] [rbp-50h]
  int v102; // [rsp+8Ch] [rbp-4Ch]
  __int64 v103; // [rsp+90h] [rbp-48h]
  int v104; // [rsp+A8h] [rbp-30h]
  int v105; // [rsp+ACh] [rbp-2Ch]
  int v106; // [rsp+B8h] [rbp-20h]
  int v107; // [rsp+D8h] [rbp+0h]
  __int64 v108; // [rsp+E8h] [rbp+10h]
  __int64 v109; // [rsp+F8h] [rbp+20h]
  int v110; // [rsp+100h] [rbp+28h]
  float v111; // [rsp+104h] [rbp+2Ch]
  float v112; // [rsp+108h] [rbp+30h]
  float v113; // [rsp+10Ch] [rbp+34h]
  __int64 v114; // [rsp+120h] [rbp+48h]
  char v115; // [rsp+130h] [rbp+58h]
  unsigned __int64 v116; // [rsp+138h] [rbp+60h]
  unsigned __int64 v117; // [rsp+140h] [rbp+68h]
  Render::DebugDrawContext *v118; // [rsp+1E8h] [rbp+110h]

  v100.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)-2i64;
  v1 = this;
  v2 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v118 = v2;
  v3 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v1->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                 + *(_QWORD *)&v1->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                 + 40);
  v101 = 0;
  v102 = 0;
  v103 = 0i64;
  v104 = 1065353216;
  v105 = -1;
  v107 = 0;
  v106 = -1;
  v108 = 0i64;
  v109 = 0i64;
  v110 = -1;
  v4 = &v1->m_vFreeAimIntention.x;
  v5 = v1->m_vFreeAimIntention.x;
  v6 = (__m128)LODWORD(v1->m_vFreeAimIntention.y);
  v7 = v6;
  v7.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  if ( v7.m128_f32[0] == 0.0 )
    v8 = 0.0;
  else
    v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v7));
  v9 = UFG::AimingPlayerComponent::getDistanceFromFreeAimOriginToStartRaycast(v1);
  v10 = (float)((float)(v1->m_vFreeAimIntention.y * (float)(v8 * v6.m128_f32[0])) + (float)(*v4 * (float)(v8 * v5)))
      + (float)(v1->m_vFreeAimIntention.z * (float)(v8 * 0.0));
  *(float *)&v11 = v10;
  if ( v10 < 0.0 )
    v11 = LODWORD(v10) ^ _xmm[0];
  if ( *(float *)&v11 >= 0.00000011920929 )
    v9 = v9 / v10;
  v12 = (float)(v1->m_vFreeAimIntention.z * v9) + v1->m_vFreeAimOrigin.z;
  v13 = (float)(v1->m_vFreeAimIntention.y * v9) + v1->m_vFreeAimOrigin.y;
  v14 = &v1->m_vFreeAimCastOrigin.x;
  *v14 = (float)(*v4 * v9) + v1->m_vFreeAimOrigin.x;
  v14[1] = v13;
  v14[2] = v12;
  v15 = (float)(UFG::AimingPlayerComponent::ms_fFreeAimTargetRange * v1->m_vFreeAimIntention.z) + v1->m_vFreeAimOrigin.z;
  v16 = (float)(UFG::AimingPlayerComponent::ms_fFreeAimTargetRange * v1->m_vFreeAimIntention.y) + v1->m_vFreeAimOrigin.y;
  v17 = &v1->m_vFreeAimTargetPosition.x;
  *v17 = (float)(UFG::AimingPlayerComponent::ms_fFreeAimTargetRange * *v4) + v1->m_vFreeAimOrigin.x;
  v17[1] = v16;
  v17[2] = v15;
  v18 = UFG::GetCurrentGameCamera();
  v19 = 0;
  v98 = UFG::qVector3::msDirFront;
  if ( s_bGameCameraModifiesFreeAim && v18 && BYTE5(v18[11].m_BoundComponentHandles.mNode.mPrev) )
  {
    v20 = *((float *)&v18[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v21 = *(float *)&v18[10].m_BoundComponentHandles.mNode.mNext;
    v22 = *((float *)&v18[10].m_BoundComponentHandles.mNode.mNext + 1);
    v25 = (__m128)LODWORD(v18[11].vfptr);
    v23 = *(float *)&v18[11].m_SafePointerList.mNode.mPrev - v22;
    v24 = *((float *)&v18[11].vfptr + 1) - v21;
    v25.m128_f32[0] = v25.m128_f32[0] - v20;
    v26 = v25;
    v26.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v23 * v23);
    if ( v26.m128_f32[0] == 0.0 )
      v27 = 0.0;
    else
      v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
    v28 = v23 * v27;
    v29 = v24 * v27;
    v30 = v25.m128_f32[0] * v27;
    v98.x = v30;
    v98.y = v29;
    v98.z = v28;
    *v14 = v20 + (float)(v30 * v9);
    v1->m_vFreeAimCastOrigin.y = (float)(v29 * v9) + v21;
    v1->m_vFreeAimCastOrigin.z = (float)(v28 * v9) + v22;
    v31 = (float)(v28 * UFG::AimingPlayerComponent::ms_fFreeAimTargetRange) + v22;
    v32 = (float)(v29 * UFG::AimingPlayerComponent::ms_fFreeAimTargetRange) + v21;
    *v17 = v20 + (float)(v30 * UFG::AimingPlayerComponent::ms_fFreeAimTargetRange);
    v1->m_vFreeAimTargetPosition.y = v32;
    v1->m_vFreeAimTargetPosition.z = v31;
    v19 = 1;
  }
  UFG::RayCastData::Init(
    (UFG::RayCastData *)&v100.mNext,
    &v1->m_vFreeAimCastOrigin,
    &v1->m_vFreeAimTargetPosition,
    0x19u);
  if ( s_bDrawRaycasts )
    Render::DebugDrawContext::DrawLine(
      v2,
      &v1->m_vFreeAimCastOrigin,
      &v1->m_vFreeAimTargetPosition,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64,
      0);
  *(_WORD *)&v1->m_bFocusTargetProbed = 0;
  v33 = &v1->m_FreeAimSimObject;
  if ( v1->m_FreeAimSimObject.m_pPointer )
  {
    v34 = v33->mPrev;
    v35 = v1->m_FreeAimSimObject.mNext;
    v34->mNext = v35;
    v35->mPrev = v34;
    v33->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v33->mPrev;
    v1->m_FreeAimSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_FreeAimSimObject.mPrev;
  }
  v1->m_FreeAimSimObject.m_pPointer = 0i64;
  v36 = 0;
  while ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, (UFG::RayCastData *)&v100.mNext) )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v100);
    v38 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v37);
    v100.mTypeUID = UFG::qStringHash64(v38, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v100, v100.mTypeUID, v117);
    if ( !*((_QWORD *)&rayStart + 1) || *(float *)(*((_QWORD *)&rayStart + 1) + 88i64) <= 0.69999999 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase(&v100);
      break;
    }
    v39 = &v98;
    if ( !v19 )
      v39 = &v1->m_vFreeAimIntention;
    *(float *)&v40 = (float)(v39->z * 0.0099999998) + v113;
    *(float *)&v41 = (float)(v39->y * 0.0099999998) + v112;
    *(float *)&rayStart = v111 + (float)(v39->x * 0.0099999998);
    *(_QWORD *)((char *)&rayStart + 4) = __PAIR__(v40, v41);
    UFG::RayCastData::Init(
      (UFG::RayCastData *)&v100.mNext,
      (UFG::qVector3 *)&rayStart,
      &v1->m_vFreeAimTargetPosition,
      0x19u);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v100);
    if ( (unsigned int)++v36 >= 3 )
      break;
  }
  if ( v115 )
  {
    if ( !v114 )
      goto LABEL_162;
    UFG::qReflectHandleBase::Init(
      (UFG::qReflectHandleBase *)&v1->m_FreeAimPhysicsObjectProperties.mPrev,
      v1->m_FreeAimPhysicsObjectProperties.mTypeUID,
      v116);
    if ( !v1->m_FreeAimPhysicsObjectProperties.mData )
      UFG::PhysicsPropertyManager::GetDefaultObjectProperties(&v1->m_FreeAimPhysicsObjectProperties);
    v42 = *(_QWORD *)(v114 + 0x18);
    if ( !v42 )
      goto LABEL_162;
    v43 = *(_QWORD *)(v42 + 0x18);
    if ( v43 )
      v43 = *(_QWORD *)(v43 + 0x28);
    if ( !v43 )
      goto LABEL_162;
    v44 = *(_WORD *)(v43 + 76);
    if ( (v44 >> 14) & 1 )
    {
      v45 = *(UFG::SimComponent **)(*(_QWORD *)(v43 + 104) + 48i64);
    }
    else if ( (v44 & 0x8000u) == 0 )
    {
      if ( (v44 >> 13) & 1 )
      {
        v45 = *(UFG::SimComponent **)(*(_QWORD *)(v43 + 104) + 64i64);
      }
      else if ( (v44 >> 12) & 1 )
      {
        v46 = *(_DWORD *)(v43 + 128);
        v47 = *(_DWORD *)(v43 + 96);
        if ( v46 >= v47 )
        {
LABEL_50:
          v45 = 0i64;
        }
        else
        {
          v48 = *(_QWORD *)(v43 + 104);
          while ( (*(_DWORD *)(v48 + 16i64 * v46 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v48 + 16i64 * v46 + 8) & 0x1FFFFFF )
          {
            if ( ++v46 >= v47 )
              goto LABEL_50;
          }
          v45 = *(UFG::SimComponent **)(v48 + 16i64 * v46);
        }
      }
      else
      {
        v45 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v43, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v45 = *(UFG::SimComponent **)(*(_QWORD *)(v43 + 104) + 48i64);
    }
    if ( v45 )
    {
      v49 = (int)v45[1].m_SafePointerList.mNode.mNext;
      if ( v49 == 1 || v49 == 4 )
      {
        if ( !*(_QWORD *)(v43 + 88) )
          goto LABEL_162;
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->m_FreeAimSimObject,
          (UFG::SimComponent *)v43);
        if ( (UFG::SimObject *)v3 == v1->m_FreeAimSimObject.m_pPointer )
        {
          v1->m_bFocusTargetProbed = 1;
          goto LABEL_162;
        }
        v50 = *(_WORD *)(v43 + 76);
        if ( (v50 >> 14) & 1 )
        {
          v51 = *(UFG::SimComponent **)(*(_QWORD *)(v43 + 104) + 704i64);
LABEL_84:
          if ( v51 )
          {
            v60 = v51[1].m_BoundComponentHandles.mNode.mPrev ? v51[1].m_BoundComponentHandles.mNode.mPrev[2].mNext : 0i64;
            if ( v60 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v3 )
              v1->m_bFocusTargetProbed = 1;
          }
          if ( v1->m_bFocusTargetProbed )
            goto LABEL_167;
          if ( v3 )
          {
            v61 = *(_WORD *)(v3 + 76);
            if ( (v61 >> 14) & 1 )
            {
              v62 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 320i64);
              if ( v62
                && !((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v62->m_TypeUID) & 0xFE000000)
                && !(UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v62->m_TypeUID & 0x1FFFFFF) )
              {
LABEL_118:
                if ( v62 )
                {
                  v69 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v62[1].m_Flags + 31i64);
                  v70 = *(_QWORD *)&v62[1].m_TypeUID;
                  if ( *(_QWORD *)(v69 + v70 + 40) )
                  {
                    if ( *(_BYTE *)(v69 + v70 + 49) && *(_QWORD *)(v69 + v70 + 40) == v43 )
                      v1->m_bFocusTargetProbed = 1;
                  }
                }
                goto LABEL_162;
              }
LABEL_96:
              v62 = 0i64;
              goto LABEL_118;
            }
            if ( (v61 & 0x8000u) != 0 )
            {
              v62 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 320i64);
              if ( v62 && !((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v62->m_TypeUID) & 0xFE000000) )
              {
                if ( UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v62->m_TypeUID & 0x1FFFFFF )
                  v62 = 0i64;
                goto LABEL_118;
              }
              goto LABEL_96;
            }
            if ( (v61 >> 13) & 1 )
            {
              v63 = *(_DWORD *)(v3 + 128);
              v64 = *(_DWORD *)(v3 + 96);
              if ( v63 >= v64 )
                goto LABEL_96;
              v65 = *(_QWORD *)(v3 + 104);
              while ( 1 )
              {
                v66 = 2i64 * v63;
                if ( (*(_DWORD *)(v65 + 16i64 * v63 + 8) & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                  && !(UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v65 + 16i64 * v63 + 8) & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v63 >= v64 )
                  goto LABEL_96;
              }
            }
            else
            {
              if ( !((v61 >> 12) & 1) )
              {
                v62 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)v3,
                        UFG::TargetingSystemPedBaseComponent::_TypeUID);
                goto LABEL_118;
              }
              v67 = *(_DWORD *)(v3 + 128);
              v68 = *(_DWORD *)(v3 + 96);
              if ( v67 >= v68 )
                goto LABEL_96;
              v65 = *(_QWORD *)(v3 + 104);
              while ( 1 )
              {
                v66 = 2i64 * v67;
                if ( (*(_DWORD *)(v65 + 16i64 * v67 + 8) & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                  && !(UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v65 + 16i64 * v67 + 8) & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v67 >= v68 )
                  goto LABEL_96;
              }
            }
            v62 = *(UFG::SimComponent **)(v65 + 8 * v66);
            goto LABEL_118;
          }
LABEL_162:
          if ( !v1->m_bFocusTargetProbed )
          {
            if ( v3 )
            {
              v86 = *(float **)(v3 + 88);
              if ( v86 )
              {
                v87 = v1->m_vFreeAimCastOrigin.x - v111;
                v88 = (__m128)LODWORD(v1->m_vFreeAimCastOrigin.y);
                v88.m128_f32[0] = v88.m128_f32[0] - v112;
                v89 = v1->m_vFreeAimCastOrigin.z - v113;
                UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v3 + 88));
                v90 = v1->m_vFreeAimCastOrigin.x - v86[44];
                v91 = (__m128)LODWORD(v1->m_vFreeAimCastOrigin.y);
                v92 = v1->m_vFreeAimCastOrigin.z - v86[46];
                v91.m128_f32[0] = (float)((float)((float)(v91.m128_f32[0] - v86[45]) * (float)(v91.m128_f32[0] - v86[45]))
                                        + (float)(v90 * v90))
                                + (float)(v92 * v92);
                v88.m128_f32[0] = (float)((float)(v88.m128_f32[0] * v88.m128_f32[0]) + (float)(v87 * v87))
                                + (float)(v89 * v89);
                if ( COERCE_FLOAT(_mm_sqrt_ps(v91)) >= (float)(COERCE_FLOAT(_mm_sqrt_ps(v88))
                                                             + s_fExtraObstructionDistance) )
                  v1->m_bFocusTargetObstructed = 1;
              }
            }
          }
LABEL_167:
          v93 = (__m128)LODWORD(v1->m_vFreeAimCastOrigin.y);
          v94 = v112;
          v95 = v113;
          v93.m128_f32[0] = (float)((float)((float)(v93.m128_f32[0] - v112) * (float)(v93.m128_f32[0] - v112))
                                  + (float)((float)(v1->m_vFreeAimCastOrigin.x - v111)
                                          * (float)(v1->m_vFreeAimCastOrigin.x - v111)))
                          + (float)((float)(v1->m_vFreeAimCastOrigin.z - v113)
                                  * (float)(v1->m_vFreeAimCastOrigin.z - v113));
          if ( COERCE_FLOAT(_mm_sqrt_ps(v93)) >= s_fMinDistance )
          {
            *v17 = v111;
            v1->m_vFreeAimTargetPosition.y = v94;
            v1->m_vFreeAimTargetPosition.z = v95;
          }
          else
          {
            v96 = (float)(s_fMinDistance * v1->m_vFreeAimIntention.y) + v1->m_vFreeAimCastOrigin.y;
            v97 = (float)(s_fMinDistance * v1->m_vFreeAimIntention.z) + v1->m_vFreeAimCastOrigin.z;
            *v17 = (float)(s_fMinDistance * *v4) + v1->m_vFreeAimCastOrigin.x;
            v1->m_vFreeAimTargetPosition.y = v96;
            v1->m_vFreeAimTargetPosition.z = v97;
          }
          if ( s_bDrawRaycasts )
            Render::DebugDrawContext::DrawPoint(
              v118,
              &v1->m_vFreeAimTargetPosition,
              &UFG::qColour::Red,
              &UFG::qMatrix44::msIdentity,
              0i64);
          return;
        }
        if ( (v50 & 0x8000u) == 0 )
        {
          if ( (v50 >> 13) & 1 )
          {
            v56 = *(_DWORD *)(v43 + 128);
            v57 = *(_DWORD *)(v43 + 96);
            if ( v56 < v57 )
            {
              v54 = *(_QWORD *)(v43 + 104);
              do
              {
                v55 = 2i64 * v56;
                if ( (*(_DWORD *)(v54 + 16i64 * v56 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                  && !(UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v54 + 16i64 * v56 + 8) & 0x1FFFFFF) )
                {
                  goto LABEL_67;
                }
              }
              while ( ++v56 < v57 );
            }
          }
          else
          {
            if ( !((v50 >> 12) & 1) )
            {
              v51 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v43, UFG::CharacterOccupantComponent::_TypeUID);
              goto LABEL_84;
            }
            v58 = *(_DWORD *)(v43 + 128);
            v59 = *(_DWORD *)(v43 + 96);
            if ( v58 < v59 )
            {
              v54 = *(_QWORD *)(v43 + 104);
              do
              {
                v55 = 2i64 * v58;
                if ( (*(_DWORD *)(v54 + 16i64 * v58 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                  && !(UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v54 + 16i64 * v58 + 8) & 0x1FFFFFF) )
                {
                  goto LABEL_67;
                }
              }
              while ( ++v58 < v59 );
            }
          }
        }
        else
        {
          v52 = *(_DWORD *)(v43 + 128);
          v53 = *(_DWORD *)(v43 + 96);
          if ( v52 < v53 )
          {
            v54 = *(_QWORD *)(v43 + 104);
            while ( 1 )
            {
              v55 = 2i64 * v52;
              if ( (*(_DWORD *)(v54 + 16i64 * v52 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                && !(UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v54 + 16i64 * v52 + 8) & 0x1FFFFFF) )
              {
                break;
              }
              if ( ++v52 >= v53 )
                goto LABEL_68;
            }
LABEL_67:
            v51 = *(UFG::SimComponent **)(v54 + 8 * v55);
            goto LABEL_84;
          }
        }
LABEL_68:
        v51 = 0i64;
        goto LABEL_84;
      }
    }
    v71 = *(_WORD *)(v43 + 76);
    if ( (v71 >> 14) & 1 )
    {
      v72 = *(_DWORD *)(v43 + 128);
      v73 = *(_DWORD *)(v43 + 96);
      if ( v72 < v73 )
      {
        v74 = *(_QWORD *)(v43 + 104);
        while ( 1 )
        {
          v75 = 2i64 * v72;
          if ( (*(_DWORD *)(v74 + 16i64 * v72 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v74 + 16i64 * v72 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v72 >= v73 )
            goto LABEL_131;
        }
LABEL_130:
        v76 = *(UFG::SimComponent **)(v74 + 8 * v75);
        goto LABEL_154;
      }
    }
    else if ( (v71 & 0x8000u) == 0 )
    {
      if ( (v71 >> 13) & 1 )
      {
        v79 = *(_DWORD *)(v43 + 128);
        v80 = *(_DWORD *)(v43 + 96);
        if ( v79 < v80 )
        {
          v74 = *(_QWORD *)(v43 + 104);
          do
          {
            v75 = 2i64 * v79;
            if ( (*(_DWORD *)(v74 + 16i64 * v79 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v74 + 16i64 * v79 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_130;
            }
          }
          while ( ++v79 < v80 );
        }
      }
      else
      {
        if ( !((v71 >> 12) & 1) )
        {
          v76 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v43, UFG::RigidBodyComponent::_TypeUID);
LABEL_154:
          if ( v76 )
          {
            UFG::qReflectHandleBase::qReflectHandleBase(&v100);
            v84 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v83);
            v100.mTypeUID = UFG::qStringHash64(v84, 0xFFFFFFFFFFFFFFFFui64);
            v85 = *(_QWORD *)&v76[2].m_Flags;
            if ( v85 )
              UFG::qReflectHandleBase::operator=(&v100, (UFG::qReflectHandleBase *)(v85 + 224));
            if ( *((_QWORD *)&rayStart + 1) )
            {
              if ( *(_BYTE *)(*((_QWORD *)&rayStart + 1) + 146i64) )
              {
                UFG::qSafePointer<Creature,Creature>::operator=(
                  (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->m_FreeAimSimObject,
                  (UFG::SimComponent *)v43);
                if ( (UFG::SimObject *)v3 == v1->m_FreeAimSimObject.m_pPointer )
                  v1->m_bFocusTargetProbed = 1;
              }
            }
            UFG::qReflectHandleBase::~qReflectHandleBase(&v100);
          }
          goto LABEL_162;
        }
        v81 = *(_DWORD *)(v43 + 128);
        v82 = *(_DWORD *)(v43 + 96);
        if ( v81 < v82 )
        {
          v74 = *(_QWORD *)(v43 + 104);
          do
          {
            v75 = 2i64 * v81;
            if ( (*(_DWORD *)(v74 + 16i64 * v81 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v74 + 16i64 * v81 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_130;
            }
          }
          while ( ++v81 < v82 );
        }
      }
    }
    else
    {
      v77 = *(_DWORD *)(v43 + 128);
      v78 = *(_DWORD *)(v43 + 96);
      if ( v77 < v78 )
      {
        v74 = *(_QWORD *)(v43 + 104);
        do
        {
          v75 = 2i64 * v77;
          if ( (*(_DWORD *)(v74 + 16i64 * v77 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v74 + 16i64 * v77 + 8) & 0x1FFFFFF) )
          {
            goto LABEL_130;
          }
        }
        while ( ++v77 < v78 );
      }
    }
LABEL_131:
    v76 = 0i64;
    goto LABEL_154;
  }
}     }
          while 

// File Line: 2201
// RVA: 0x549DD0
void __fastcall UFG::AimingPlayerComponent::ResetFreeAimIntention(UFG::AimingPlayerComponent *this)
{
  UFG::SimComponent *v1; // rax
  float v2; // xmm2_4
  float v3; // xmm0_4
  __m128 v4; // xmm4
  float v5; // xmm6_4
  __m128 v6; // xmm3

  if ( this->m_pTSPPC.m_pSimComponent )
  {
    v1 = this->m_pTSPPC.m_pSimComponent;
    v2 = 0.0;
    v3 = *(float *)&v1[42].m_pSimObject;
    LODWORD(v1) = *(_DWORD *)(&v1[42].m_SimObjIndex + 1);
    this->m_vFreeAimIntention.y = v3;
    LODWORD(this->m_vFreeAimIntention.x) = (_DWORD)v1;
    this->m_vFreeAimIntention.z = 0.0;
    v4 = (__m128)LODWORD(this->m_vFreeAimIntention.x);
    v5 = this->m_vFreeAimIntention.z;
    v6 = v4;
    v6.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3)) + (float)(v5 * v5);
    if ( v6.m128_f32[0] != 0.0 )
      v2 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
    this->m_vFreeAimIntention.x = v4.m128_f32[0] * v2;
    this->m_vFreeAimIntention.z = v5 * v2;
    this->m_vFreeAimIntention.y = v3 * v2;
  }
}

// File Line: 2213
// RVA: 0x52D900
UFG::qVector3 *__fastcall UFG::AimingPlayerComponent::GetFreeAimFocusPosition(UFG::AimingPlayerComponent *this, UFG::qVector3 *result)
{
  float v2; // xmm5_4
  __int128 v3; // xmm4
  UFG::qVector3 *v4; // rax
  __m128 v5; // xmm2
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm5_4

  v2 = this->m_vFreeAimIntention.y;
  v3 = LODWORD(this->m_vFreeAimIntention.x);
  v4 = result;
  v5 = (__m128)v3;
  v6 = this->m_vFreeAimIntention.z;
  v5.m128_f32[0] = (float)((float)(*(float *)&v3 * *(float *)&v3) + (float)(v2 * v2)) + (float)(v6 * v6);
  LODWORD(v7) = (unsigned __int128)_mm_sqrt_ps(v5);
  *(float *)&v3 = (float)(*(float *)&v3 * (float)(UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / v7))
                + this->m_vFreeAimOrigin.x;
  v8 = (float)(v2 * (float)(UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / v7)) + this->m_vFreeAimOrigin.y;
  result->z = (float)(v6 * (float)(UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / v7)) + this->m_vFreeAimOrigin.z;
  LODWORD(result->x) = v3;
  result->y = v8;
  return v4;
}

// File Line: 2220
// RVA: 0x573F80
void __fastcall UFG::AimingPlayerComponent::updateFreeAimOrigin(UFG::AimingPlayerComponent *this, float dt)
{
  UFG::AimingPlayerComponent *v2; // rdi
  UFG::SimComponent *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm9_4
  UFG::BaseCameraComponent *v9; // rax
  float *v10; // rsi
  UFG::SimComponent *v11; // r14
  UFG::BaseCameraComponent *v12; // rbx
  UFG::BaseCameraComponent *v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v16; // rax
  UFG::qVector3 *v17; // rax
  float v18; // xmm10_4
  float v19; // xmm11_4
  Creature *v20; // r15
  float v21; // xmm7_4
  float v22; // xmm1_4
  float v23; // xmm8_4
  float v24; // xmm9_4
  float v25; // xmm10_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm6_4
  float v31; // xmm11_4
  float v32; // xmm12_4
  float *v33; // rbx
  UFG::qMatrix44 *v34; // rax
  int v35; // edx
  UFG::qVector4 v36; // xmm2
  UFG::qVector4 v37; // xmm0
  UFG::qVector4 v38; // xmm3
  float v39; // xmm1_4
  UFG::qMatrix44 *v40; // rax
  UFG::qVector4 v41; // xmm2
  UFG::qVector4 v42; // xmm1
  UFG::qVector4 v43; // xmm0
  UFG::qMatrix44 *v44; // rax
  UFG::qVector4 v45; // xmm0
  UFG::qVector4 v46; // xmm1
  UFG::qVector4 v47; // xmm0
  UFG::qMatrix44 *v48; // rax
  UFG::qVector4 v49; // xmm1
  UFG::qVector4 v50; // xmm0
  UFG::qVector4 v51; // xmm1
  UFG::SimComponent *v52; // rbx
  UFG::qVector4 v53; // xmm0
  UFG::qVector4 v54; // xmm3
  UFG::qVector4 v55; // xmm1
  UFG::SimObject *v56; // rcx
  unsigned __int16 v57; // dx
  unsigned int v58; // er8
  unsigned int v59; // er10
  signed __int64 v60; // rdx
  UFG::SimComponent *v61; // rax
  unsigned int v62; // er8
  unsigned int v63; // er10
  unsigned int v64; // er8
  unsigned int v65; // er10
  unsigned int v66; // er8
  unsigned int v67; // er10
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v68; // r14
  _DWORD *v69; // rax
  int v70; // xmm4_4
  int v71; // xmm5_4
  int v72; // xmm3_4
  float v73; // xmm2_4
  float v74; // xmm2_4
  float v75; // xmm0_4
  float v76; // xmm1_4
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  float v79; // xmm5_4
  float v80; // xmm2_4
  float v81; // xmm1_4
  float v82; // xmm5_4
  float v83; // xmm2_4
  float v84; // xmm1_4
  float v85; // xmm6_4
  float v86; // xmm4_4
  __m128 v87; // xmm9
  __m128 v88; // xmm2
  float v89; // xmm2_4
  float v90; // xmm1_4
  float v91; // xmm5_4
  float v92; // xmm2_4
  float v93; // xmm5_4
  __m128 v94; // xmm3
  float v95; // xmm6_4
  float v96; // xmm5_4
  __m128 v97; // xmm2
  float v98; // xmm2_4
  float v99; // xmm0_4
  float v100; // xmm1_4
  UFG::qVector4 *v101; // rbx
  UFG::qVector4 v102; // xmm2
  UFG::qVector4 v103; // xmm1
  UFG::qVector4 v104; // xmm0
  float v105; // xmm12_4
  float v106; // xmm11_4
  float v107; // xmm0_4
  float v108; // xmm1_4
  float v109; // xmm12_4
  float v110; // xmm4_4
  __m128 v111; // xmm3
  float v112; // xmm5_4
  __m128 v113; // xmm2
  float v114; // xmm1_4
  __m128 v115; // xmm6
  float v116; // xmm3_4
  float v117; // xmm4_4
  float v118; // xmm5_4
  __m128 v119; // xmm2
  float v120; // xmm2_4
  float v121; // xmm1_4
  float v122; // xmm9_4
  float v123; // xmm2_4
  float v124; // xmm9_4
  float v125; // xmm1_4
  float v126; // xmm10_4
  float v127; // xmm2_4
  float v128; // xmm9_4
  float v129; // xmm6_4
  float v130; // xmm6_4
  float v131; // xmm15_4
  float v132; // xmm14_4
  float v133; // xmm6_4
  float v134; // xmm15_4
  float v135; // xmm14_4
  float v136; // xmm2_4
  float v137; // xmm9_4
  float v138; // xmm10_4
  float v139; // xmm13_4
  float v140; // xmm7_4
  float v141; // xmm4_4
  float v142; // xmm5_4
  UFG::BaseCameraComponent *v143; // rcx
  float v144; // xmm1_4
  float v145; // xmm2_4
  UFG::qMatrix44 v146; // [rsp+20h] [rbp-B8h]
  float v147; // [rsp+60h] [rbp-78h]
  float v148; // [rsp+64h] [rbp-74h]
  char b[112]; // [rsp+68h] [rbp-70h]
  UFG::qMatrix44 transform; // [rsp+D8h] [rbp+0h]
  UFG::qMatrix44 result; // [rsp+118h] [rbp+40h]
  UFG::qMatrix44 v152; // [rsp+158h] [rbp+80h]
  UFG::qMatrix44 m; // [rsp+198h] [rbp+C0h]
  UFG::qMatrix44 d; // [rsp+1D8h] [rbp+100h]
  float v155; // [rsp+2F8h] [rbp+220h]
  float delta_sec; // [rsp+300h] [rbp+228h]
  float v157; // [rsp+308h] [rbp+230h]
  float vars0; // [rsp+310h] [rbp+238h]

  v2 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v3 = v2->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_TransformNodeComponent.m_pSimComponent);
  v4 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext;
  v5 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v6 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev - v2->m_vFreeAimLastFramePosition.x;
  v7 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1) - v2->m_vFreeAimLastFramePosition.y;
  v8 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext - v2->m_vFreeAimLastFramePosition.z;
  v2->m_vFreeAimLastFramePosition.x = *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev;
  v2->m_vFreeAimLastFramePosition.z = v4;
  v2->m_vFreeAimLastFramePosition.y = v5;
  *(float *)b = UFG::qVector3::msZero.x;
  v148 = UFG::qVector3::msZero.x;
  v155 = UFG::qVector3::msZero.y;
  v157 = UFG::qVector3::msZero.z;
  vars0 = UFG::qVector3::msZero.y;
  v147 = UFG::qVector3::msZero.z;
  v9 = UFG::GetCurrentBaseCamera();
  v10 = 0i64;
  v11 = (UFG::SimComponent *)&v9->vfptr;
  if ( !v9
    || (v12 = v9,
        !UFG::SimComponent::IsType(
           (UFG::SimComponent *)&v9->vfptr,
           UFG::FollowCameraComponent::_FollowCameraComponentTypeUID)) )
  {
    v12 = 0i64;
  }
  if ( !v11 || !UFG::SimComponent::IsType(v11, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID) )
    v11 = 0i64;
  if ( v12 )
  {
    if ( !LODWORD(v2->m_pTSPPC.m_pSimComponent[53].m_pSimObject) )
    {
LABEL_9:
      v13 = UFG::Director::Get()->mCurrentCamera;
      if ( v13 )
        v10 = &v13->mCamera.mFOVOffset;
      v14 = v10[45] + v7;
      v15 = v10[46] + v8;
      v2->m_vFreeAimOrigin.x = v10[44] + v6;
      v2->m_vFreeAimOrigin.y = v14;
      v2->m_vFreeAimOrigin.z = v15;
      v2->m_vAimPosition.x = v6 + v2->m_vAimPosition.x;
      v2->m_vAimPosition.y = v7 + v2->m_vAimPosition.y;
      v2->m_vAimPosition.z = v8 + v2->m_vAimPosition.z;
      return;
    }
    if ( !((unsigned __int8 (__fastcall *)(UFG::BaseCameraComponent *))v12->vfptr[37].__vecDelDtor)(v12) )
    {
      v16 = v12->vfptr;
      LOBYTE(v12[8].mCamera.mProjection.v2.x) = 1;
      ((void (__fastcall *)(UFG::BaseCameraComponent *))v16[15].__vecDelDtor)(v12);
      LOBYTE(v12[8].mCamera.mProjection.v2.x) = 0;
    }
    v17 = (UFG::qVector3 *)&v12[10].mCamera.mOverrideView.v1.z;
    v148 = v12[10].mCamera.mOverrideView.v0.w;
    v155 = v12[10].mCamera.mOverrideView.v1.x;
    v157 = v12[10].mCamera.mOverrideView.v1.y;
    if ( !LOBYTE(v12[10].mCamera.mProjection.v2.z) )
      v17 = &UFG::qVector3::msZero;
    v18 = v17->y;
    v19 = v17->z;
    *(float *)b = v17->x;
    vars0 = v18;
    v147 = v19;
    if ( UFG::AimingPlayerComponent::ms_bNewCoverBehaviour && v2->m_bUsingCover )
    {
      v157 = 0.0;
      v155 = 0.0;
    }
  }
  else if ( v11 )
  {
    goto LABEL_9;
  }
  v20 = 0i64;
  if ( v2->m_CharacterAnimationComponent.m_pSimComponent )
    v20 = *(Creature **)&v2->m_CharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
  v21 = *(float *)&FLOAT_1_0;
  if ( UFG::AimingPlayerComponent::ms_bFreeAimRootSmoothing )
  {
    v146.v3.z = UFG::qMatrix44::msIdentity.v1.x;
    v146.v3.w = UFG::qMatrix44::msIdentity.v1.y;
    v147 = UFG::qMatrix44::msIdentity.v1.z;
    v148 = UFG::qMatrix44::msIdentity.v1.w;
    *(float *)b = UFG::qMatrix44::msIdentity.v2.x;
    *(float *)&b[4] = UFG::qMatrix44::msIdentity.v2.y;
    *(float *)&b[8] = UFG::qMatrix44::msIdentity.v2.z;
    *(float *)&b[12] = UFG::qMatrix44::msIdentity.v2.w;
    *(float *)&b[16] = UFG::qMatrix44::msIdentity.v3.x;
    *(float *)&b[20] = UFG::qMatrix44::msIdentity.v3.y;
    *(float *)&b[24] = UFG::qMatrix44::msIdentity.v3.z;
    *(float *)&b[28] = UFG::qMatrix44::msIdentity.v3.w;
    *(UFG::qMatrix44 *)&b[48] = UFG::qMatrix44::msIdentity;
    if ( v20 && v20 != (Creature *)-240i64 )
    {
      Creature::GetTransformMS(v20, v2->m_iFreeAimOriginBoneID, &transform);
      if ( UFG::AimingPlayerComponent::ms_bNewCoverBehaviour && v2->m_bUsingCover && v12 )
      {
        transform.v3.w = 1.0;
        v22 = transform.v3.z + v12[10].mCamera.mOverrideView.v1.y;
        transform.v3.y = transform.v3.y + v12[10].mCamera.mOverrideView.v1.x;
        transform.v3.z = v22;
      }
      Creature::GetTransformMS(v20, v2->m_iFreeAimSyncBoneID, &m);
      UFG::qInverse(&d, &m);
      UFG::qMatrix44::operator*(&transform, &result, &d);
      v23 = result.v3.x;
      v24 = result.v3.y;
      v25 = result.v3.z;
      UFG::qQuaternion::Set((UFG::qQuaternion *)&b[32], &result);
      if ( v2->m_bFreeAimRootDirty )
      {
        v26 = *(float *)&b[32];
        v27 = *(float *)&b[36];
        v2->m_vFreeAimRootPosSS.x = v23;
        v2->m_vFreeAimRootPosSS.y = v24;
        v2->m_vFreeAimRootPosSS.z = v25;
        v2->m_qFreeAimRootOriSS.x = v26;
        v28 = *(float *)&b[40];
        v2->m_qFreeAimRootOriSS.y = v27;
        v29 = *(float *)&b[44];
        v2->m_qFreeAimRootOriSS.z = v28;
        v2->m_qFreeAimRootOriSS.w = v29;
        v2->m_bFreeAimRootDirty = 0;
      }
      v21 = *(float *)&FLOAT_1_0;
      v30 = *(float *)&FLOAT_1_0;
      v31 = *(float *)&FLOAT_1_0;
      if ( v12 )
      {
        v30 = v12[10].mCamera.mOverrideView.v2.y;
        v31 = v12[10].mCamera.mOverrideView.v2.z;
      }
      v32 = delta_sec;
      v33 = &v2->m_vFreeAimRootPosSS.x;
      UFG::qApproach(&v2->m_vFreeAimRootPosSS.x, v23, v30, delta_sec);
      UFG::qApproach(&v2->m_vFreeAimRootPosSS.y, v24, v30, v32);
      UFG::qApproach(&v2->m_vFreeAimRootPosSS.z, v25, v30, v32);
      UFG::qApproachOrientation(&v2->m_qFreeAimRootOriSS, (UFG::qQuaternion *)&b[32], v31, v32);
      v2->m_bFreeAimRootMovementLock = 0;
      if ( UFG::AimingPlayerComponent::ms_bFreeAimAutoMovementLock
        && (float)((float)((float)((float)(v2->m_vFreeAimRootPosSS.y - v24) * (float)(v2->m_vFreeAimRootPosSS.y - v24))
                         + (float)((float)(*v33 - v23) * (float)(*v33 - v23)))
                 + (float)((float)(v2->m_vFreeAimRootPosSS.z - v25) * (float)(v2->m_vFreeAimRootPosSS.z - v25))) > (float)(UFG::AimingPlayerComponent::ms_fFreeAimRootMovementLockThreshold * UFG::AimingPlayerComponent::ms_fFreeAimRootMovementLockThreshold) )
      {
        v2->m_bFreeAimRootMovementLock = 1;
      }
      v34 = UFG::qQuaternion::GetMatrix(&v2->m_qFreeAimRootOriSS, &v152, &UFG::qVector3::msZero);
      v35 = v2->m_iFreeAimSyncBoneID;
      v36 = v34->v2;
      v37 = v34->v0;
      v38 = v34->v1;
      result.v3 = v34->v3;
      v39 = v2->m_vFreeAimRootPosSS.y;
      result.v3.w = 1.0;
      result.v0 = v37;
      v37.x = *v33;
      result.v2 = v36;
      v36.x = v2->m_vFreeAimRootPosSS.z;
      result.v3.x = v37.x;
      result.v3.y = v39;
      result.v3.z = v36.x;
      result.v1 = v38;
      Creature::GetTransform(v20, v35, (UFG::qMatrix44 *)&b[48]);
      v40 = UFG::qMatrix44::operator*(&result, &v152, (UFG::qMatrix44 *)&b[48]);
      v41 = v40->v2;
      v42 = v40->v3;
      v43 = v40->v0;
      v146.v1 = v40->v1;
      v146.v2 = v41;
      v146.v0 = v43;
      v146.v3 = v42;
      v44 = UFG::qQuaternion::GetMatrix((UFG::qQuaternion *)&b[32], &v152, &UFG::qVector3::msZero);
      v45 = v44->v0;
      *(UFG::qVector4 *)&v146.v3.z = v44->v1;
      v46 = v44->v3;
      *(UFG::qVector4 *)&b[8] = v45;
      v47 = v44->v2;
      *(float *)&b[16] = v23;
      *(_DWORD *)&b[28] = 1065353216;
      *(float *)&b[20] = v24;
      *(float *)&b[24] = v25;
      *(UFG::qVector4 *)b = v47;
      v48 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&b[8], &v152, (UFG::qMatrix44 *)&b[48]);
      v49 = v48->v1;
      *(UFG::qVector4 *)&b[8] = v48->v0;
      v50 = v48->v2;
      *(UFG::qVector4 *)((char *)&v146.v3 + 8) = v49;
      v51 = v48->v3;
      *(UFG::qVector4 *)b = v50;
      *(UFG::qVector4 *)&b[16] = v51;
    }
    else
    {
      v52 = v2->m_TransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_TransformNodeComponent.m_pSimComponent);
      v53 = *(UFG::qVector4 *)&v52[2].m_Flags;
      v54 = (UFG::qVector4)v52[2].m_BoundComponentHandles;
      v55 = *(UFG::qVector4 *)&v52[2].vfptr;
      v21 = *(float *)&FLOAT_1_0;
      *(_OWORD *)&v146.v3.z = *(_OWORD *)&v52[2].m_SafePointerList.mNode.mNext;
      v146.v1 = *(UFG::qVector4 *)&v146.v3.z;
      v146.v2 = v53;
      v146.v3 = v54;
      v146.v0 = v55;
      *(UFG::qVector4 *)b = v53;
      *(UFG::qVector4 *)&b[16] = v54;
    }
    goto LABEL_94;
  }
  if ( v20 )
  {
    if ( v12 && LOBYTE(v12[10].mCamera.mProjection.v2.z) )
    {
      Creature::GetTransform(v20, v2->m_iFreeAimSyncBoneID, &v146);
      v56 = v2->m_pSimObject;
      if ( v56 )
      {
        v57 = v56->m_Flags;
        if ( (v57 >> 14) & 1 )
        {
          v58 = (unsigned int)v56[1].vfptr;
          v59 = v56->m_Components.size;
          v60 = v58;
          if ( v58 < v59 )
          {
            v60 = (signed __int64)&v56->m_Components.p[v58];
            while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                 || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF )
            {
              ++v58;
              v60 += 16i64;
              if ( v58 >= v59 )
                goto LABEL_48;
            }
LABEL_49:
            v61 = *(UFG::SimComponent **)v60;
            goto LABEL_72;
          }
        }
        else if ( (v57 & 0x8000u) == 0 )
        {
          if ( (v57 >> 13) & 1 )
          {
            v64 = (unsigned int)v56[1].vfptr;
            v65 = v56->m_Components.size;
            v60 = v64;
            if ( v64 < v65 )
            {
              v60 = (signed __int64)&v56->m_Components.p[v64];
              while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                   || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF )
              {
                ++v64;
                v60 += 16i64;
                if ( v64 >= v65 )
                {
                  v61 = 0i64;
                  goto LABEL_72;
                }
              }
              goto LABEL_49;
            }
          }
          else
          {
            if ( !((v57 >> 12) & 1) )
            {
              v61 = UFG::SimObject::GetComponentOfType(v56, UFG::AICoverComponent::_TypeUID);
              goto LABEL_72;
            }
            v66 = (unsigned int)v56[1].vfptr;
            v67 = v56->m_Components.size;
            v60 = v66;
            if ( v66 < v67 )
            {
              v60 = (signed __int64)&v56->m_Components.p[v66];
              while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                   || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF )
              {
                ++v66;
                v60 += 16i64;
                if ( v66 >= v67 )
                {
                  v61 = 0i64;
                  goto LABEL_72;
                }
              }
              goto LABEL_49;
            }
          }
        }
        else
        {
          v62 = (unsigned int)v56[1].vfptr;
          v63 = v56->m_Components.size;
          v60 = v62;
          if ( v62 < v63 )
          {
            v60 = (signed __int64)&v56->m_Components.p[v62];
            while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                 || UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF )
            {
              ++v62;
              v60 += 16i64;
              if ( v62 >= v63 )
              {
                v61 = 0i64;
                goto LABEL_72;
              }
            }
            goto LABEL_49;
          }
        }
LABEL_48:
        v61 = 0i64;
LABEL_72:
        if ( v61 )
        {
          v68 = v61[1].m_BoundComponentHandles.mNode.mNext;
          if ( v68 )
          {
            if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, signed __int64))v68->mPrev[1].mPrev)(
                   v68,
                   v60) )
            {
              v69 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, char *))v68->mPrev[10].mPrev)(
                                v68,
                                &b[32]);
              v70 = v69[1] ^ _xmm[0];
              v71 = v69[2] ^ _xmm[0];
              v72 = *v69 ^ _xmm[0];
              v73 = (float)((float)(*(float *)&v70 * *(float *)&v70) + (float)(*(float *)&v72 * *(float *)&v72))
                  + (float)(*(float *)&v71 * *(float *)&v71);
              if ( v73 == 0.0 )
                v74 = 0.0;
              else
                v74 = 1.0 / fsqrt(v73);
              v146.v0.w = 0.0;
              v75 = v74 * *(float *)&v70;
              v76 = v74 * *(float *)&v72;
              v77 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
              v146.v0.z = v74 * *(float *)&v71;
              v78 = v77;
              v146.v0.y = v75;
              v146.v0.x = v76;
              v78.m128_f32[0] = (float)((float)(v77.m128_f32[0] * v77.m128_f32[0])
                                      + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                              + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
              if ( v78.m128_f32[0] == 0.0 )
                v79 = 0.0;
              else
                v79 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v78));
              v80 = v79;
              v81 = v79;
              v82 = v79 * UFG::qVector3::msDirUp.z;
              v83 = v80 * UFG::qVector3::msDirUp.x;
              v84 = v81 * UFG::qVector3::msDirUp.y;
              v85 = (float)(v146.v0.z * v84) - (float)(v146.v0.y * v82);
              v87 = (__m128)LODWORD(v146.v0.x);
              v86 = (float)(v146.v0.y * v83) - (float)(v146.v0.x * v84);
              v87.m128_f32[0] = (float)(v146.v0.x * v82) - (float)(v146.v0.z * v83);
              v88 = v87;
              v88.m128_f32[0] = (float)((float)(v87.m128_f32[0] * v87.m128_f32[0]) + (float)(v85 * v85))
                              + (float)(v86 * v86);
              if ( v88.m128_f32[0] == 0.0 )
                v89 = 0.0;
              else
                v89 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v88));
              v94 = (__m128)LODWORD(v146.v0.z);
              v90 = v89;
              v91 = v89;
              v92 = v89 * v86;
              v146.v1.w = 0.0;
              v93 = v91 * v87.m128_f32[0];
              v146.v1.z = v92;
              v146.v1.y = v93;
              v146.v1.x = v90 * v85;
              v94.m128_f32[0] = (float)(v146.v0.z * (float)(v90 * v85)) - (float)(v92 * v146.v0.x);
              v95 = (float)(v92 * v146.v0.y) - (float)(v146.v0.z * v93);
              v96 = (float)(v93 * v146.v0.x) - (float)(v146.v0.y * v146.v1.x);
              v97 = v94;
              v97.m128_f32[0] = (float)((float)(v94.m128_f32[0] * v94.m128_f32[0]) + (float)(v95 * v95))
                              + (float)(v96 * v96);
              if ( v97.m128_f32[0] == 0.0 )
                v98 = 0.0;
              else
                v98 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v97));
              v146.v2.w = 0.0;
              v146.v3.w = 1.0;
              v146.v2.z = v98 * v96;
              v146.v2.x = v98 * v95;
              v146.v2.y = v98 * v94.m128_f32[0];
            }
          }
        }
        goto LABEL_89;
      }
    }
    else
    {
      Creature::GetTransform(v20, v2->m_iFreeAimOriginBoneID, &v146);
    }
LABEL_89:
    if ( UFG::AimingPlayerComponent::ms_bNewCoverBehaviour && v2->m_bUsingCover && v12 )
    {
      Creature::GetTransform(v20, v2->m_iFreeAimSyncBoneID, &transform);
      v99 = v12[10].mCamera.mOverrideView.v1.x;
      v100 = v12[10].mCamera.mOverrideView.v1.y;
      v146.v3.w = 1.0;
      v146.v3.x = v146.v3.x + (float)((float)(transform.v2.x * v100) + (float)(transform.v1.x * v99));
      v21 = *(float *)&FLOAT_1_0;
      v146.v3.y = v146.v3.y + (float)((float)(transform.v2.y * v100) + (float)(transform.v1.y * v99));
      v146.v3.z = v146.v3.z + (float)((float)(transform.v2.z * v100) + (float)(transform.v1.z * v99));
    }
    goto LABEL_94;
  }
  v101 = (UFG::qVector4 *)v2->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_TransformNodeComponent.m_pSimComponent);
  v102 = v101[10];
  v103 = v101[11];
  v104 = v101[8];
  v146.v1 = v101[9];
  v146.v2 = v102;
  v146.v0 = v104;
  v146.v3 = v103;
LABEL_94:
  v105 = (float)(v146.v1.z * vars0) + (float)(v146.v0.z * *(float *)b);
  v106 = (float)((float)((float)(v146.v1.y * vars0) + (float)(v146.v0.y * *(float *)b)) + (float)(v146.v2.y * v147))
       + v146.v3.y;
  v107 = v146.v3.x
       + (float)((float)((float)(v146.v1.x * vars0) + (float)(v146.v0.x * *(float *)b)) + (float)(v146.v2.x * v147));
  v108 = v146.v2.z * v147;
  v2->m_vFreeAimBaseOffset.x = v107;
  v2->m_vFreeAimBaseOffset.y = v106;
  v109 = (float)(v105 + v108) + v146.v3.z;
  vars0 = v107;
  v2->m_vFreeAimBaseOffset.z = v109;
  v110 = v2->m_vFreeAimIntention.y;
  v111 = (__m128)LODWORD(v2->m_vFreeAimIntention.x);
  v113 = v111;
  v112 = v2->m_vFreeAimIntention.z;
  v113.m128_f32[0] = (float)((float)(v111.m128_f32[0] * v111.m128_f32[0]) + (float)(v110 * v110)) + (float)(v112 * v112);
  if ( v113.m128_f32[0] == 0.0 )
    v114 = 0.0;
  else
    v114 = v21 / COERCE_FLOAT(_mm_sqrt_ps(v113));
  v115 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v116 = v111.m128_f32[0] * v114;
  v117 = v110 * v114;
  v118 = v112 * v114;
  v119 = v115;
  v119.m128_f32[0] = (float)((float)(v115.m128_f32[0] * v115.m128_f32[0])
                           + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v119.m128_f32[0] == 0.0 )
    v120 = 0.0;
  else
    v120 = v21 / COERCE_FLOAT(_mm_sqrt_ps(v119));
  v121 = v120;
  v122 = v120;
  v123 = v120 * UFG::qVector3::msDirUp.z;
  v124 = v122 * UFG::qVector3::msDirUp.x;
  v125 = v121 * UFG::qVector3::msDirUp.y;
  v126 = (float)(v125 * v118) - (float)(v123 * v117);
  v127 = (float)(v123 * v116) - (float)(v124 * v118);
  v128 = (float)(v124 * v117) - (float)(v125 * v116);
  v129 = (float)((float)(v127 * v127) + (float)(v126 * v126)) + (float)(v128 * v128);
  if ( v129 == 0.0 )
    v130 = 0.0;
  else
    v130 = v21 / fsqrt(v129);
  v131 = v130;
  v132 = v130;
  v133 = v130 * v128;
  v134 = v131 * v127;
  v135 = v132 * v126;
  v136 = (float)(v133 * v117) - (float)(v134 * v118);
  v137 = (float)(v135 * v118) - (float)(v133 * v116);
  v138 = (float)(v134 * v116) - (float)(v135 * v117);
  v139 = (float)((float)(v137 * v137) + (float)(v136 * v136)) + (float)(v138 * v138);
  if ( v139 == 0.0 )
    v140 = 0.0;
  else
    v140 = v21 / fsqrt(v139);
  v141 = (float)((float)((float)(v117 * v148) + (float)(v134 * v155)) + (float)((float)(v137 * v140) * v157)) + v106;
  v142 = (float)((float)((float)(v118 * v148) + (float)(v133 * v155)) + (float)((float)(v138 * v140) * v157)) + v109;
  v2->m_vFreeAimOrigin.x = (float)((float)((float)(v116 * v148) + (float)(v135 * v155))
                                 + (float)((float)(v136 * v140) * v157))
                         + vars0;
  v2->m_vFreeAimOrigin.y = v141;
  v2->m_vFreeAimOrigin.z = v142;
  if ( !UFG::IsAnyLocalPlayer(v2->m_pSimObject) && UFG::IsAnyLocalPlayer(v2->m_pSimObject) )
  {
    v143 = UFG::Director::Get()->mCurrentCamera;
    if ( v143 )
      v10 = &v143->mCamera.mFOVOffset;
    v144 = v10[45];
    v145 = v10[46];
    v2->m_vFreeAimOrigin.x = v10[44];
    v2->m_vFreeAimOrigin.y = v144;
    v2->m_vFreeAimOrigin.z = v145;
  }
}at)(v138 * v140) * v157)) + v109;
  v2->m_vFreeAimOrigin.x = (float)((float)((float)(v116 * v148) + (float)(v135 * v155))
                                 + (float)((float)(v136 * v140) * v157))
                         + vars0

// File Line: 2440
// RVA: 0x56FDC0
void __usercall UFG::AimingPlayerComponent::updateAimIntentionTargetPosition(UFG::AimingPlayerComponent *this@<rcx>, UFG::qMatrix44 *matXform@<rdx>, __int128 *a3@<xmm7>)
{
  UFG::AimingPlayerComponent *v3; // rbx
  UFG::SimComponent *v4; // rcx
  UFG::qMatrix44 *v5; // r9
  UFG::SimObjectProp *v6; // rdi
  __int64 v7; // r8
  bool v8; // r15
  bool v9; // bp
  char v10; // r13
  UFG::SubTargetingLocation *v11; // r12
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // r14
  unsigned __int16 v14; // cx
  UFG::CharacterAnimationComponent *v15; // rcx
  unsigned int v16; // er8
  unsigned int v17; // edx
  unsigned int v18; // eax
  UFG::CharacterAnimationComponent *v19; // rax
  unsigned int v20; // er8
  unsigned int v21; // er9
  signed __int64 v22; // rdx
  Creature *pCreature; // rsi
  UFG::SubTargetingProfile *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  UFG::qVector3 vSubTargetingLocationWS; // [rsp+30h] [rbp-38h]
  UFG::qMatrix44 *pXform; // [rsp+78h] [rbp+10h]

  pXform = matXform;
  v3 = this;
  v4 = this->m_pTSPPC.m_pSimComponent;
  v5 = matXform;
  if ( v4 )
  {
    v6 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 30i64)
                                + *(_QWORD *)&v4[1].m_TypeUID
                                + 40);
    v7 = LODWORD(v4[53].m_pSimObject);
    LOBYTE(matXform) = (unsigned int)(v7 - 1) <= 1;
    v8 = (unsigned int)(v7 - 3) <= 1;
    v9 = (_DWORD)v7 == 2;
    v10 = 0;
    if ( v3->m_bCameraZoomMode )
      goto LABEL_50;
    if ( !(_BYTE)matXform && !v8 && !v9 )
      goto LABEL_53;
    v11 = (UFG::SubTargetingLocation *)v4[42].m_BoundComponentHandles.mNode.mPrev;
    if ( !v11 || !v6 )
      goto LABEL_50;
    v12 = v6->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = v6->m_Components.p[3].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = v6->m_Components.p[4].m_pComponent;
      }
      else if ( (v12 >> 12) & 1 )
      {
        v7 = v6->mComponentTableEntryCount;
        v5 = (UFG::qMatrix44 *)v6->m_Components.size;
        matXform = (UFG::qMatrix44 *)(unsigned int)v7;
        if ( (unsigned int)v7 >= (unsigned int)v5 )
        {
LABEL_20:
          v13 = 0i64;
        }
        else
        {
          matXform = (UFG::qMatrix44 *)&v6->m_Components.p[(unsigned int)v7];
          while ( (LODWORD(matXform->v0.z) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~LODWORD(matXform->v0.z) & 0x1FFFFFF )
          {
            v7 = (unsigned int)(v7 + 1);
            matXform = (UFG::qMatrix44 *)((char *)matXform + 16);
            if ( (unsigned int)v7 >= (unsigned int)v5 )
              goto LABEL_20;
          }
          v13 = *(UFG::SimComponent **)&matXform->v0.x;
        }
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v6->vfptr,
                UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v13 = v6->m_Components.p[3].m_pComponent;
    }
    if ( !v13
      || !((__int64 (__fastcall *)(UFG::SimComponent *, UFG::qMatrix44 *, __int64, UFG::qMatrix44 *))v13->vfptr[14].__vecDelDtor)(
            v13,
            matXform,
            v7,
            v5) )
    {
LABEL_50:
      if ( v8 || v9 )
        goto LABEL_56;
      v5 = pXform;
LABEL_53:
      if ( !v3->m_CharacterOccupantComponent.m_pSimComponent )
      {
        if ( !v10 )
          UFG::AimingBaseComponent::GetTargetNormalAimPosition(
            (UFG::AimingBaseComponent *)&v3->vfptr,
            &v3->m_vAimIntentionTargetPosition,
            22i64,
            v5);
        return;
      }
LABEL_56:
      v27 = v3->m_vFreeAimTargetPosition.y;
      v28 = v3->m_vFreeAimTargetPosition.z;
      v3->m_vAimIntentionTargetPosition.x = v3->m_vFreeAimTargetPosition.x;
      v3->m_vAimIntentionTargetPosition.y = v27;
      v3->m_vAimIntentionTargetPosition.z = v28;
      return;
    }
    v14 = v6->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
      if ( v15 )
      {
        v16 = UFG::CharacterAnimationComponent::_TypeUID;
        v17 = v15->m_TypeUID;
        v18 = v17 ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_28:
        if ( v18 & 0xFE000000 || v16 & ~v17 & 0x1FFFFFF )
          goto LABEL_30;
LABEL_46:
        if ( v15 )
        {
          pCreature = v15->mCreature;
          if ( pCreature )
          {
            v24 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))v13->vfptr[14].__vecDelDtor)(v13);
            v10 = UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                    v24,
                    &vSubTargetingLocationWS,
                    v11,
                    (UFG::SimObject *)&v6->vfptr,
                    a3,
                    pCreature);
            if ( v10 )
            {
              v25 = vSubTargetingLocationWS.y;
              v3->m_vAimIntentionTargetPosition.x = vSubTargetingLocationWS.x;
              v26 = vSubTargetingLocationWS.z;
              v3->m_vAimIntentionTargetPosition.y = v25;
              v3->m_vAimIntentionTargetPosition.z = v26;
              return;
            }
          }
        }
        goto LABEL_50;
      }
    }
    else
    {
      if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v19 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        else
        {
          if ( (v14 >> 12) & 1 )
          {
            v20 = v6->mComponentTableEntryCount;
            v21 = v6->m_Components.size;
            if ( v20 < v21 )
            {
              v22 = (signed __int64)&v6->m_Components.p[v20];
              while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
              {
                ++v20;
                v22 += 16i64;
                if ( v20 >= v21 )
                {
                  v15 = 0i64;
                  goto LABEL_46;
                }
              }
              v15 = *(UFG::CharacterAnimationComponent **)v22;
              goto LABEL_46;
            }
            goto LABEL_30;
          }
          v19 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v6->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        v15 = v19;
        goto LABEL_46;
      }
      v15 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
      if ( v15 )
      {
        v17 = v15->m_TypeUID;
        v16 = UFG::CharacterAnimationComponent::_TypeUID;
        v18 = UFG::CharacterAnimationComponent::_TypeUID ^ v15->m_TypeUID;
        goto LABEL_28;
      }
    }
LABEL_30:
    v15 = 0i64;
    goto LABEL_46;
  }
}

// File Line: 2505
// RVA: 0x52AA60
void __fastcall UFG::AimingPlayerComponent::GetAngularInaccuracyRad(UFG::AimingPlayerComponent *this)
{
  UFG::AimingPlayerComponent *v1; // rbx
  Illusion::Target *v2; // rax
  float v3; // xmm1_4
  float v4; // xmm0_4
  UFG::Camera *v5; // rbx
  UFG::BaseCameraComponent *v6; // rcx
  UFG::Camera *v7; // rcx
  UFG::BaseCameraComponent *v8; // rcx
  float v9; // xmm2_4
  UFG::qVector3 v10; // [rsp+20h] [rbp-28h]
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]
  UFG::qVector2 viewport_scale; // [rsp+58h] [rbp+10h]
  UFG::qVector2 screen_pos; // [rsp+60h] [rbp+18h]
  UFG::qVector2 v14; // [rsp+68h] [rbp+20h]

  v1 = this;
  v2 = Render::GetBackBufferTarget();
  v3 = (float)v2->mHeight;
  viewport_scale.x = (float)v2->mWidth;
  viewport_scale.y = v3;
  v4 = UFG::AimingPlayerComponent::GetReticleSize(v1);
  v14.y = viewport_scale.y * 0.5;
  screen_pos.y = viewport_scale.y * 0.5;
  v14.x = viewport_scale.x * 0.5;
  screen_pos.x = (float)(viewport_scale.x * v4) + (float)(viewport_scale.x * 0.5);
  v5 = 0i64;
  v6 = UFG::Director::Get()->mCurrentCamera;
  if ( v6 )
    v7 = &v6->mCamera;
  else
    v7 = 0i64;
  UFG::Camera::ScreenToWorldRay(v7, &result, &screen_pos, &viewport_scale);
  v8 = UFG::Director::Get()->mCurrentCamera;
  if ( v8 )
    v5 = &v8->mCamera;
  UFG::Camera::ScreenToWorldRay(v5, &v10, &v14, &viewport_scale);
  v9 = (float)((float)(v10.x * result.x) + (float)(v10.y * result.y)) + (float)(v10.z * result.z);
  if ( v9 <= -1.0 )
  {
    v9 = FLOAT_N1_0;
  }
  else if ( v9 >= 1.0 )
  {
    acosf(1.0);
    return;
  }
  acosf(v9);
}

// File Line: 2530
// RVA: 0x52D520
void __fastcall UFG::AimingPlayerComponent::GetFiringPositionAtAimPosition(UFG::AimingPlayerComponent *this, UFG::qVector3 *vFiringPositionAtAimPosition)
{
  UFG::qVector3 *v2; // rdi
  UFG::AimingPlayerComponent *v3; // rbx
  __m128 v4; // xmm2
  float v5; // xmm0_4
  float v6; // xmm10_4
  float v7; // xmm9_4
  float v8; // xmm8_4
  float v9; // xmm7_4
  float v10; // xmm7_4
  float v11; // xmm13_4
  float v12; // xmm14_4
  __m128 v13; // xmm7
  float v14; // xmm15_4
  __m128 v15; // xmm2
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  __m128 v20; // xmm2
  float v21; // xmm0_4
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm5_4
  float v26; // xmm1_4
  float v27; // xmm10_4
  float v28; // xmm5_4
  __m128 v29; // xmm4
  float v30; // xmm0_4
  __m128 v31; // xmm4
  float v32; // xmm12_4
  float v33; // xmm4_4
  float v34; // xmm12_4
  __m128 v35; // xmm11
  float v36; // xmm5_4
  __m128 v37; // xmm10
  float v38; // xmm9_4
  __m128 v39; // xmm2
  float v40; // xmm6_4
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+20h] [rbp-C8h]
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+30h] [rbp-B8h]
  float v43; // [rsp+F0h] [rbp+8h]
  float v44; // [rsp+F8h] [rbp+10h]

  v2 = vFiringPositionAtAimPosition;
  v3 = this;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(
    (UFG::AimingBaseComponent *)&this->vfptr,
    &vWeaponProjectileSpawnPosition);
  v4 = (__m128)LODWORD(v3->m_vAimOriginPosition.y);
  v5 = (float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z)
     * (float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z);
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] - v3->m_vAimIntentionTargetPosition.y)
                                 * (float)(v4.m128_f32[0] - v3->m_vAimIntentionTargetPosition.y))
                         + (float)((float)(v3->m_vAimOriginPosition.x - v3->m_vAimIntentionTargetPosition.x)
                                 * (float)(v3->m_vAimOriginPosition.x - v3->m_vAimIntentionTargetPosition.x)))
                 + v5;
  LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v4);
  ((void (__fastcall *)(UFG::AimingPlayerComponent *))v3->vfptr[21].__vecDelDtor)(v3);
  v7 = v5;
  v8 = UFG::qRandom(6.2831855, &UFG::qDefaultSeed);
  if ( UFG::AimingPlayerComponent::ms_bCorrectDiscPointPicking )
    v9 = fsqrt(UFG::qRandom(1.0, &UFG::qDefaultSeed));
  else
    v9 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  v10 = v9 * v7;
  v11 = cosf(v8) * v10;
  v12 = sinf(v8) * v10;
  UFG::AimingBaseComponent::GetWeaponProjectileDirection(
    (UFG::AimingBaseComponent *)&v3->vfptr,
    &vWeaponProjectileDirection);
  v13 = (__m128)LODWORD(vWeaponProjectileDirection.x);
  v14 = vWeaponProjectileSpawnPosition.x + (float)(vWeaponProjectileDirection.x * v6);
  v43 = vWeaponProjectileSpawnPosition.y + (float)(vWeaponProjectileDirection.y * v6);
  v15 = v13;
  v44 = vWeaponProjectileSpawnPosition.z + (float)(vWeaponProjectileDirection.z * v6);
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0])
                          + (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y))
                  + (float)(vWeaponProjectileDirection.z * vWeaponProjectileDirection.z);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
  v17 = vWeaponProjectileDirection.x * v16;
  v18 = vWeaponProjectileDirection.y * v16;
  v19 = vWeaponProjectileDirection.z * v16;
  v20 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v20.m128_f32[0] == 0.0 )
  {
    v22 = 0i64;
  }
  else
  {
    LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v20);
    v22 = (__m128)(unsigned int)FLOAT_1_0;
    v22.m128_f32[0] = 1.0 / v21;
  }
  v23 = v22.m128_f32[0];
  v24 = v22.m128_f32[0];
  v22.m128_f32[0] = v22.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v25 = v24 * UFG::qVector3::msDirUp.x;
  v26 = v23 * UFG::qVector3::msDirUp.y;
  v27 = (float)(v26 * v19) - (float)(v22.m128_f32[0] * v18);
  v22.m128_f32[0] = (float)(v22.m128_f32[0] * v17) - (float)(v25 * v19);
  v28 = (float)(v25 * v18) - (float)(v26 * v17);
  v29 = v22;
  v29.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v27 * v27)) + (float)(v28 * v28);
  if ( v29.m128_f32[0] == 0.0 )
  {
    v31 = 0i64;
  }
  else
  {
    LODWORD(v30) = (unsigned __int128)_mm_sqrt_ps(v29);
    v31 = (__m128)(unsigned int)FLOAT_1_0;
    v31.m128_f32[0] = 1.0 / v30;
  }
  v32 = v31.m128_f32[0];
  v35 = v31;
  v33 = v31.m128_f32[0] * v28;
  v34 = v32 * v22.m128_f32[0];
  v35.m128_f32[0] = v35.m128_f32[0] * v27;
  v37 = v35;
  v36 = (float)(v33 * v18) - (float)(v34 * v19);
  v37.m128_f32[0] = (float)(v35.m128_f32[0] * v19) - (float)(v33 * v17);
  v39 = v37;
  v38 = (float)(v34 * v17) - (float)(v35.m128_f32[0] * v18);
  v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v36 * v36)) + (float)(v38 * v38);
  if ( v39.m128_f32[0] == 0.0 )
    v40 = 0.0;
  else
    v40 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v39));
  v2->z = (float)((float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v33) + (float)((float)(v38 * v40) * v12)) + v44;
  v2->y = (float)((float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v34) + (float)((float)(v37.m128_f32[0] * v40) * v12))
        + v43;
  v2->x = (float)((float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v35.m128_f32[0]) + (float)((float)(v36 * v40) * v12))
        + v14;
}

// File Line: 2565
// RVA: 0x52F8D0
float __usercall UFG::AimingPlayerComponent::GetRadialInaccuracyAtAimPosition@<xmm0>(UFG::AimingPlayerComponent *this@<rcx>, float a2@<xmm0>)
{
  UFG::AimingPlayerComponent *v2; // rbx
  float v3; // xmm7_4
  UFG::BaseCameraComponent *v4; // rcx
  __m128 v5; // xmm2
  float v6; // xmm0_4

  v2 = this;
  ((void (*)(void))this->vfptr[19].__vecDelDtor)();
  v3 = a2;
  v4 = UFG::Director::Get()->mCurrentCamera;
  if ( v4 )
    v4 = (UFG::BaseCameraComponent *)((char *)v4 + 80);
  v5 = (__m128)LODWORD(v4->mCamera.mView.v2.y);
  v6 = v4->mCamera.mView.v2.x - v2->m_vAimPosition.x;
  v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - v2->m_vAimPosition.y)
                                 * (float)(v5.m128_f32[0] - v2->m_vAimPosition.y))
                         + (float)(v6 * v6))
                 + (float)((float)(v4->mCamera.mView.v2.z - v2->m_vAimPosition.z)
                         * (float)(v4->mCamera.mView.v2.z - v2->m_vAimPosition.z));
  return COERCE_FLOAT(_mm_sqrt_ps(v5)) * tanf(v3);
}

// File Line: 2575
// RVA: 0x520860
void __fastcall UFG::AimingPlayerComponent::AddAimingSoftLockTask(UFG::AimingPlayerComponent *this, AimingSoftLockTask *pAimingSoftLockTask)
{
  AimingSoftLockTask *v2; // rdi
  UFG::AimingPlayerComponent *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  bool v5; // al
  UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *v6; // rdx
  UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4

  v2 = pAimingSoftLockTask;
  v3 = this;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, AimSoftLockEnabled);
  if ( !UFG::AimingPlayerComponent::ms_bTrackSoftLockDisabled && v5 )
  {
    v6 = (UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *)&v2->mPrev;
    v7 = v3->m_AimingSoftLockTaskList.mNode.mPrev;
    v7->mNext = (UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *)&v2->mPrev;
    v6->mPrev = v7;
    v6->mNext = &v3->m_AimingSoftLockTaskList.mNode;
    v3->m_AimingSoftLockTaskList.mNode.mPrev = (UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *)&v2->mPrev;
    if ( v3->m_eSoftLockType == eSOFT_LOCK_NONE
      && !BYTE2(v3->m_pTSPPC.m_pSimComponent[52].m_BoundComponentHandles.mNode.mPrev) )
    {
      v8 = v3->m_vFreeAimTargetPosition.y;
      v9 = v3->m_vFreeAimTargetPosition.z;
      v3->m_vSoftLockOffset.x = v3->m_vFreeAimTargetPosition.x;
      v3->m_vSoftLockOffset.y = v8;
      v3->m_vSoftLockOffset.z = v9;
      v3->m_bResetSoftLockOffset = 1;
      v3->m_eSoftLockType = 1;
    }
  }
}

// File Line: 2595
// RVA: 0x520820
void __fastcall UFG::AimingPlayerComponent::AddAimingFreeAimConeClampTask(UFG::AimingPlayerComponent *this, AimingFreeAimConeClampTask *pAimingFreeAimConeClampTask)
{
  UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *v2; // rdx
  UFG::qList<AimingFreeAimConeClampTask,AimingFreeAimConeClampList,0,0> *v3; // rcx
  UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *v4; // rax

  v2 = (UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *)&pAimingFreeAimConeClampTask->mPrev;
  v3 = &this->m_AimingFreeAimConeClampTaskList;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

// File Line: 2602
// RVA: 0x54FCE0
void __fastcall UFG::AimingPlayerComponent::SnapAccuracy(UFG::AimingPlayerComponent *this, const float fAccuracy)
{
  float v2; // xmm0_4

  if ( fAccuracy <= 0.0 )
  {
    fAccuracy = 0.0;
  }
  else
  {
    v2 = *(float *)&FLOAT_1_0;
    if ( fAccuracy >= 1.0 )
      goto LABEL_6;
  }
  v2 = fAccuracy;
LABEL_6:
  this->m_Accuracy.m_fAccuracyUnclamped = v2;
  this->m_fBlendedReticleRadius = -1.0;
  this->m_fBlendedReticleSize = -1.0;
}

// File Line: 2611
// RVA: 0x5568F0
void __fastcall UFG::AimingPlayerComponent::TeleportEventHandler(UFG::AimingPlayerComponent *this, UFG::Event *pEvent)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = *((float *)&pEvent[1].m_EventUID + 1);
  v3 = *(float *)&pEvent[1].m_NamePTR;
  LODWORD(this->m_vFreeAimIntention.x) = pEvent[1].m_EventUID;
  this->m_vFreeAimIntention.y = v2;
  this->m_vFreeAimIntention.z = v3;
}

