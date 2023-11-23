// File Line: 124
// RVA: 0x1543D40
__int64 dynamic_initializer_for__UFG::AimingPlayerComponent::s_AimingPlayerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AimingPlayerComponent::s_AimingPlayerComponentList__);
}

// File Line: 125
// RVA: 0x532660
__int64 __fastcall UFG::AimingPlayerComponent::GetTypeSize(UFG::AimingPlayerComponent *this)
{
  return 920i64;
}

// File Line: 207
// RVA: 0x5354A0
bool __fastcall UFG::AimingPlayerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAimingPlayer,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 213
// RVA: 0x5442E0
UFG::SimComponent *__fastcall UFG::AimingPlayerComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x398ui64, "AimingPlayerComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::AimingPlayerComponent::AimingPlayerComponent(
      (UFG::AimingPlayerComponent *)v3,
      pSceneObj->m_NameUID,
      mpWritableProperties,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v8 = 47;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
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
void __fastcall UFG::AimingPlayerComponent::AimingPlayerComponent(
        UFG::AimingPlayerComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::SimComponent *v6; // rbp
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *TypeName; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pAimTargetPositionSimObject; // r14
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pAimTargetPositionTNC; // rbx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *mPrev; // rax
  Illusion::Target *BackBufferTarget; // rax
  float v35; // xmm2_4
  float v36; // xmm1_4
  float *v37; // rax
  float *v38; // rcx
  float *v39; // rax
  float *v40; // rcx
  float *v41; // rax
  float *v42; // rcx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v44; // rax
  UFG::SimObject *v45; // rax
  UFG::SimObject *v46; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v47; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v49; // rax
  UFG::qMemoryPool *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::SimComponent *v52; // rax
  UFG::SimObject *m_pPointer; // rdx
  __int16 m_Flags; // cx
  unsigned int v55; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v56; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v57; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v58; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v59; // [rsp+30h] [rbp-68h] BYREF
  UFG::qSymbol result; // [rsp+38h] [rbp-60h] BYREF
  UFG::qSymbol name; // [rsp+3Ch] [rbp-5Ch] BYREF
  __int64 v62; // [rsp+40h] [rbp-58h]
  UFG::SimObjectModifier v63; // [rsp+48h] [rbp-50h] BYREF

  v62 = -2i64;
  UFG::AimingBaseComponent::AimingBaseComponent(this, name_uid, properties, startSuspended);
  this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev = &this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>;
  this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mNext = &this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>;
  this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0>(&this->m_pTSPPC);
  *(_DWORD *)&this->m_bFocusTargetProbed = 0;
  *(_WORD *)&this->m_bSupressReticle = 0;
  this->m_bAimingControlsCamera = 0;
  this->m_fBlendedReticleSize = -1.0;
  this->m_fBlendedReticleRadius = -1.0;
  this->m_fOverrideReticleSize = -1.0;
  v6 = 0i64;
  *(_QWORD *)&this->m_fAxisXSpeed = 0i64;
  *(_QWORD *)&this->m_fDampenedAxisXSpeed = 0i64;
  this->m_fAimObstructedDuration = 0.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vFreeAimLastFramePosition.x = UFG::qVector3::msZero.x;
  this->m_vFreeAimLastFramePosition.y = y;
  this->m_vFreeAimLastFramePosition.z = z;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->m_vFreeAimCastOrigin.x = UFG::qVector3::msZero.x;
  this->m_vFreeAimCastOrigin.y = v9;
  this->m_vFreeAimCastOrigin.z = v10;
  this->m_bFreeAimRootDirty = 1;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->m_vFreeAimRootPosSS.x = UFG::qVector3::msZero.x;
  this->m_vFreeAimRootPosSS.y = v11;
  this->m_vFreeAimRootPosSS.z = v12;
  this->m_qFreeAimRootOriSS = UFG::qQuaternion::msUnity;
  this->m_bFreeAimRootMovementLock = 0;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  this->m_vFreeAimOrigin.x = UFG::qVector3::msZero.x;
  this->m_vFreeAimOrigin.y = v13;
  this->m_vFreeAimOrigin.z = v14;
  v15 = UFG::qVector3::msAxisX.y;
  v16 = UFG::qVector3::msAxisX.z;
  this->m_vFreeAimIntention.x = UFG::qVector3::msAxisX.x;
  this->m_vFreeAimIntention.y = v15;
  this->m_vFreeAimIntention.z = v16;
  v17 = UFG::qVector3::msZero.y;
  v18 = UFG::qVector3::msZero.z;
  this->m_vFreeAimTargetPosition.x = UFG::qVector3::msZero.x;
  this->m_vFreeAimTargetPosition.y = v17;
  this->m_vFreeAimTargetPosition.z = v18;
  this->m_FreeAimSimObject.mPrev = &this->m_FreeAimSimObject;
  this->m_FreeAimSimObject.mNext = &this->m_FreeAimSimObject;
  this->m_FreeAimSimObject.m_pPointer = 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->m_FreeAimPhysicsObjectProperties);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
  this->m_FreeAimPhysicsObjectProperties.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  *(_QWORD *)&this->m_fReticleBlend = 1065353216i64;
  v21 = UFG::qVector3::msZero.y;
  v22 = UFG::qVector3::msZero.z;
  this->m_vFocusTargetSegA.x = UFG::qVector3::msZero.x;
  this->m_vFocusTargetSegA.y = v21;
  this->m_vFocusTargetSegA.z = v22;
  v23 = UFG::qVector3::msZero.y;
  v24 = UFG::qVector3::msZero.z;
  this->m_vFocusTargetSegB.x = UFG::qVector3::msZero.x;
  this->m_vFocusTargetSegB.y = v23;
  this->m_vFocusTargetSegB.z = v24;
  v25 = UFG::qVector3::msZero.y;
  v26 = UFG::qVector3::msZero.z;
  this->m_vFocusTargetClosestPos.x = UFG::qVector3::msZero.x;
  this->m_vFocusTargetClosestPos.y = v25;
  this->m_vFocusTargetClosestPos.z = v26;
  v27 = UFG::qVector3::msZero.y;
  v28 = UFG::qVector3::msZero.z;
  this->m_vFocusTargetSegClosestPos.x = UFG::qVector3::msZero.x;
  this->m_vFocusTargetSegClosestPos.y = v27;
  this->m_vFocusTargetSegClosestPos.z = v28;
  this->m_fFocusTargetRadius = 0.0;
  this->m_fFocusTargetDistanceSeg = 3.4028235e38;
  this->m_bResetSoftLockOffset = 0;
  this->m_eSoftLockType = eSOFT_LOCK_NONE;
  v29 = UFG::qVector3::msZero.y;
  v30 = UFG::qVector3::msZero.z;
  this->m_vSoftLockOffset.x = UFG::qVector3::msZero.x;
  this->m_vSoftLockOffset.y = v29;
  this->m_vSoftLockOffset.z = v30;
  this->m_fFreeAimSpeedModifier = 1.0;
  *(_QWORD *)&this->m_fInterpolatedFreeAimConeClamp = 1078530011i64;
  this->m_AimingSoftLockTaskList.mNode.mPrev = &this->m_AimingSoftLockTaskList.mNode;
  this->m_AimingSoftLockTaskList.mNode.mNext = &this->m_AimingSoftLockTaskList.mNode;
  this->m_AimingFreeAimConeClampTaskList.mNode.mPrev = &this->m_AimingFreeAimConeClampTaskList.mNode;
  this->m_AimingFreeAimConeClampTaskList.mNode.mNext = &this->m_AimingFreeAimConeClampTaskList.mNode;
  p_m_pAimTargetPositionSimObject = &this->m_pAimTargetPositionSimObject;
  this->m_pAimTargetPositionSimObject.mPrev = &this->m_pAimTargetPositionSimObject;
  this->m_pAimTargetPositionSimObject.mNext = &this->m_pAimTargetPositionSimObject;
  this->m_pAimTargetPositionSimObject.m_pPointer = 0i64;
  p_m_pAimTargetPositionTNC = &this->m_pAimTargetPositionTNC;
  v59 = &this->m_pAimTargetPositionTNC;
  this->m_pAimTargetPositionTNC.mPrev = &this->m_pAimTargetPositionTNC;
  this->m_pAimTargetPositionTNC.mNext = &this->m_pAimTargetPositionTNC;
  this->m_pAimTargetPositionTNC.m_pPointer = 0i64;
  this->m_eAimBlendMode = eAIM_BLEND_MODE_NONE;
  mPrev = UFG::AimingPlayerComponent::s_AimingPlayerComponentList.mNode.mPrev;
  UFG::AimingPlayerComponent::s_AimingPlayerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>;
  this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mNext = (UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *)&UFG::AimingPlayerComponent::s_AimingPlayerComponentList;
  UFG::AimingPlayerComponent::s_AimingPlayerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>;
  UFG::SimComponent::AddType(this, UFG::AimingPlayerComponent::_AimingPlayerComponentTypeUID, "AimingPlayerComponent");
  BackBufferTarget = Render::GetBackBufferTarget();
  v35 = (float)BackBufferTarget->mHeight * 0.5;
  v36 = (float)BackBufferTarget->mWidth * 0.5;
  this->m_vReticleLockedOnCoordsScreen.x = v36;
  this->m_vReticleLockedOnCoordsScreen.y = v35;
  this->m_vReticleBlendedCoordsScreen.x = v36;
  this->m_vReticleBlendedCoordsScreen.y = v35;
  *((_BYTE *)this + 848) &= ~1u;
  *(float *)&v59 = FLOAT_20_0;
  v37 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_UnobscuredAimCheckDistance,
          DEPTH_RECURSE);
  v38 = (float *)&v59;
  if ( v37 )
    v38 = v37;
  this->m_fUnobscuredAimCheckDistance = *v38;
  *(float *)&v59 = FLOAT_1_5;
  v39 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_UnobscuredAimTargetPositionPadDistance,
          DEPTH_RECURSE);
  v40 = (float *)&v59;
  if ( v39 )
    v40 = v39;
  this->m_fUnobscuredAimTargetPositionPadDistance = *v40;
  *(float *)&v59 = FLOAT_0_1;
  v41 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_UnobscuredAimNewPositionPadDistance,
          DEPTH_RECURSE);
  v42 = (float *)&v59;
  if ( v41 )
    v42 = v41;
  this->m_fUnobscuredAimNewPositionPadDistance = *v42;
  UFG::qSymbol::create_from_string(&result, "AimingPlayerComponent_AimTargetPosition");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &name, &result);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v44 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x80ui64, "AimingPlayerComponent.AimTargetPosition", 0i64, 1u);
  v59 = (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)v44;
  if ( v44 )
  {
    UFG::SimObject::SimObject((UFG::SimObject *)v44, &name);
    v46 = v45;
  }
  else
  {
    v46 = 0i64;
  }
  if ( this->m_pAimTargetPositionSimObject.m_pPointer )
  {
    v47 = p_m_pAimTargetPositionSimObject->mPrev;
    mNext = this->m_pAimTargetPositionSimObject.mNext;
    v47->mNext = mNext;
    mNext->mPrev = v47;
    p_m_pAimTargetPositionSimObject->mPrev = p_m_pAimTargetPositionSimObject;
    this->m_pAimTargetPositionSimObject.mNext = &this->m_pAimTargetPositionSimObject;
  }
  this->m_pAimTargetPositionSimObject.m_pPointer = v46;
  if ( v46 )
  {
    v49 = v46->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v49->mNext = p_m_pAimTargetPositionSimObject;
    p_m_pAimTargetPositionSimObject->mPrev = v49;
    this->m_pAimTargetPositionSimObject.mNext = &v46->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v46->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pAimTargetPositionSimObject;
  }
  v50 = UFG::GetSimulationMemoryPool();
  v51 = UFG::qMemoryPool::Allocate(v50, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  v59 = (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)v51;
  if ( v51 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v51,
      UFG::AimTargetPositionTransform_Hash,
      0i64,
      0);
    v6 = v52;
  }
  UFG::Simulation::TrackSimObject(&UFG::gSim, this->m_pAimTargetPositionSimObject.m_pPointer);
  m_pPointer = this->m_pAimTargetPositionSimObject.m_pPointer;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v55 = 2;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      v55 = 2;
    }
    else
    {
      v55 = -1;
      if ( (m_Flags & 0x1000) != 0 )
        v55 = 1;
    }
  }
  else
  {
    v55 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v63, m_pPointer, 1);
  UFG::SimObjectModifier::AttachComponent(&v63, v6, v55);
  UFG::SimObjectModifier::Close(&v63);
  UFG::SimObjectModifier::~SimObjectModifier(&v63);
  if ( this->m_pAimTargetPositionTNC.m_pPointer )
  {
    v56 = p_m_pAimTargetPositionTNC->mPrev;
    v57 = this->m_pAimTargetPositionTNC.mNext;
    v56->mNext = v57;
    v57->mPrev = v56;
    p_m_pAimTargetPositionTNC->mPrev = p_m_pAimTargetPositionTNC;
    this->m_pAimTargetPositionTNC.mNext = &this->m_pAimTargetPositionTNC;
  }
  this->m_pAimTargetPositionTNC.m_pPointer = v6;
  if ( v6 )
  {
    v58 = v6->m_SafePointerList.mNode.mPrev;
    v58->mNext = p_m_pAimTargetPositionTNC;
    p_m_pAimTargetPositionTNC->mPrev = v58;
    this->m_pAimTargetPositionTNC.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = p_m_pAimTargetPositionTNC;
  }
}

// File Line: 369
// RVA: 0x51AA00
void __fastcall UFG::AimingPlayerComponent::~AimingPlayerComponent(UFG::AimingPlayerComponent *this)
{
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v2; // rdi
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *mPrev; // rcx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *mNext; // rax
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pAimTargetPositionSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pAimTargetPositionTNC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_FreeAimSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v24; // rcx
  UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent> *v25; // rax

  this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingPlayerComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::AimingPlayerComponent::s_AimingPlayerComponentpCurrentIterator )
    UFG::AimingPlayerComponent::s_AimingPlayerComponentpCurrentIterator = (UFG::AimingPlayerComponent *)&this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev[-26];
  v2 = &this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>;
  mPrev = this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  m_pPointer = this->m_pAimTargetPositionSimObject.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pAimTargetPositionSimObject = &this->m_pAimTargetPositionSimObject;
    if ( this->m_pAimTargetPositionSimObject.m_pPointer )
    {
      v7 = p_m_pAimTargetPositionSimObject->mPrev;
      v8 = this->m_pAimTargetPositionSimObject.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      p_m_pAimTargetPositionSimObject->mPrev = p_m_pAimTargetPositionSimObject;
      this->m_pAimTargetPositionSimObject.mNext = &this->m_pAimTargetPositionSimObject;
    }
    this->m_pAimTargetPositionSimObject.m_pPointer = 0i64;
  }
  p_m_pAimTargetPositionTNC = &this->m_pAimTargetPositionTNC;
  if ( this->m_pAimTargetPositionTNC.m_pPointer )
  {
    v10 = p_m_pAimTargetPositionTNC->mPrev;
    v11 = this->m_pAimTargetPositionTNC.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_m_pAimTargetPositionTNC->mPrev = p_m_pAimTargetPositionTNC;
    this->m_pAimTargetPositionTNC.mNext = &this->m_pAimTargetPositionTNC;
  }
  this->m_pAimTargetPositionTNC.m_pPointer = 0i64;
  v12 = p_m_pAimTargetPositionTNC->mPrev;
  v13 = this->m_pAimTargetPositionTNC.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_m_pAimTargetPositionTNC->mPrev = p_m_pAimTargetPositionTNC;
  this->m_pAimTargetPositionTNC.mNext = &this->m_pAimTargetPositionTNC;
  v14 = &this->m_pAimTargetPositionSimObject;
  if ( this->m_pAimTargetPositionSimObject.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = this->m_pAimTargetPositionSimObject.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = v14;
    this->m_pAimTargetPositionSimObject.mNext = &this->m_pAimTargetPositionSimObject;
  }
  this->m_pAimTargetPositionSimObject.m_pPointer = 0i64;
  v17 = v14->mPrev;
  v18 = this->m_pAimTargetPositionSimObject.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v14->mPrev = v14;
  this->m_pAimTargetPositionSimObject.mNext = &this->m_pAimTargetPositionSimObject;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_AimingFreeAimConeClampTaskList);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_AimingSoftLockTaskList);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->m_FreeAimPhysicsObjectProperties);
  p_m_FreeAimSimObject = &this->m_FreeAimSimObject;
  if ( this->m_FreeAimSimObject.m_pPointer )
  {
    v20 = p_m_FreeAimSimObject->mPrev;
    v21 = this->m_FreeAimSimObject.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    p_m_FreeAimSimObject->mPrev = p_m_FreeAimSimObject;
    this->m_FreeAimSimObject.mNext = &this->m_FreeAimSimObject;
  }
  this->m_FreeAimSimObject.m_pPointer = 0i64;
  v22 = p_m_FreeAimSimObject->mPrev;
  v23 = this->m_FreeAimSimObject.mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  p_m_FreeAimSimObject->mPrev = p_m_FreeAimSimObject;
  this->m_FreeAimSimObject.mNext = &this->m_FreeAimSimObject;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTSPPC);
  v24 = v2->mPrev;
  v25 = v2->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::AimingBaseComponent::~AimingBaseComponent(this);
}

// File Line: 382
// RVA: 0x53D0C0
void __fastcall UFG::AimingPlayerComponent::OnAttach(UFG::AimingPlayerComponent *this, UFG::SimObject *pSimObject)
{
  unsigned int v4; // eax
  int v5; // ebx
  UFG::SimComponent *m_pSimComponent; // rsi
  __int64 v7; // rsi
  int BoneID; // eax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *p_m_pTSPPC; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::SimComponent *v14; // rbx
  float v15; // xmm0_4
  float v16; // xmm1_4

  v4 = _S59;
  if ( (_S59 & 1) == 0 )
  {
    _S59 |= 1u;
    UFG::qSymbolUC::create_from_string(&symCameraSync01, "CameraSync01");
    atexit(UFG::AimingPlayerComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symCameraSync01__);
    v4 = _S59;
  }
  if ( (v4 & 2) == 0 )
  {
    _S59 = v4 | 2;
    UFG::qSymbolUC::create_from_string(&symSync01_0, "Sync01");
    atexit(UFG::AimingPlayerComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symSync01__);
  }
  UFG::AimingBaseComponent::OnAttach(this, pSimObject);
  this->m_bFreeAimRootDirty = 1;
  v5 = -1;
  this->m_iFreeAimOriginBoneID = -1;
  this->m_iFreeAimSyncBoneID = -1;
  m_pSimComponent = this->m_CharacterAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v7 = *(_QWORD *)&m_pSimComponent[2].m_TypeUID;
    if ( v7 )
    {
      if ( *(_QWORD *)(v7 + 440) )
        BoneID = Skeleton::GetBoneID(*(Skeleton **)(v7 + 480), symCameraSync01.mUID);
      else
        BoneID = -1;
      this->m_iFreeAimOriginBoneID = BoneID;
      if ( *(_QWORD *)(v7 + 440) )
        v5 = Skeleton::GetBoneID(*(Skeleton **)(v7 + 480), symSync01_0.mUID);
      this->m_iFreeAimSyncBoneID = v5;
    }
  }
  p_m_pTSPPC = &this->m_pTSPPC;
  if ( this->m_pTSPPC.m_pSimComponent )
  {
    mPrev = p_m_pTSPPC->mPrev;
    mNext = this->m_pTSPPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTSPPC.m_pSimComponent = 0i64;
LABEL_19:
    this->m_pTSPPC.m_pSimObject = 0i64;
    this->m_pTSPPC.mNext = &this->m_pTSPPC;
    p_m_pTSPPC->mPrev = p_m_pTSPPC;
    goto LABEL_20;
  }
  if ( this->m_pTSPPC.m_pSimObject && (p_m_pTSPPC->mPrev != p_m_pTSPPC || this->m_pTSPPC.mNext != &this->m_pTSPPC) )
  {
    v12 = p_m_pTSPPC->mPrev;
    v13 = this->m_pTSPPC.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_19;
  }
LABEL_20:
  this->m_pTSPPC.m_Changed = 1;
  this->m_pTSPPC.m_pSimObject = pSimObject;
  this->m_pTSPPC.m_TypeUID = UFG::TargetingSystemPedPlayerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pTSPPC,
    pSimObject);
  *((_BYTE *)this + 848) &= ~1u;
  v14 = this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14);
  v15 = *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v16 = *(float *)&v14[2].m_BoundComponentHandles.mNode.mNext;
  this->m_vFreeAimLastFramePosition.x = *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev;
  this->m_vFreeAimLastFramePosition.y = v15;
  this->m_vFreeAimLastFramePosition.z = v16;
}

// File Line: 413
// RVA: 0x53FC10
void __fastcall UFG::AimingPlayerComponent::OnDetach(UFG::AimingPlayerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedPlayerComponent,0> *p_m_pTSPPC; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  p_m_pTSPPC = &this->m_pTSPPC;
  if ( this->m_pTSPPC.m_pSimComponent )
  {
    mNext = this->m_pTSPPC.mNext;
    mPrev = p_m_pTSPPC->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTSPPC.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pTSPPC->m_pSimObject = 0i64;
    p_m_pTSPPC->mNext = p_m_pTSPPC;
    p_m_pTSPPC->mPrev = p_m_pTSPPC;
    goto LABEL_8;
  }
  if ( this->m_pTSPPC.m_pSimObject && (p_m_pTSPPC->mPrev != p_m_pTSPPC || this->m_pTSPPC.mNext != &this->m_pTSPPC) )
  {
    v5 = this->m_pTSPPC.mNext;
    v6 = p_m_pTSPPC->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pTSPPC->m_Changed = 1;
  UFG::AimingBaseComponent::OnDetach(this);
}

// File Line: 422
// RVA: 0x576A50
void __fastcall UFG::AimingPlayerComponent::updatePlayerAimDirection(
        UFG::AimingPlayerComponent *this,
        float fDeltaS,
        UFG::qMatrix44 *matXform)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  __int64 v6; // rax
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4

  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  if ( (unsigned int)(LODWORD(m_pSimComponent[53].m_pSimObject) - 3) > 1
    && LODWORD(m_pSimComponent[53].m_pSimObject) != 2
    || (v6 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID) == 0 )
  {
    this->m_eAimBlendMode = eAIM_BLEND_MODE_NONE;
    goto LABEL_22;
  }
  if ( m_pSimComponent[42].m_BoundComponentHandles.mNode.mPrev )
  {
    if ( this->m_eAimBlendMode != eAIM_BLEND_MODE_SUBTARGETING )
    {
      v7 = *(float *)(*(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8) + 404i64);
      if ( v7 < 0.0 )
        this->m_fAimTransitionRadPerS = v7;
      this->m_eAimBlendMode = eAIM_BLEND_MODE_SUBTARGETING;
      UFG::AimingBaseComponent::updateAimDirection(this, fDeltaS, matXform);
      return;
    }
LABEL_22:
    UFG::AimingBaseComponent::updateAimDirection(this, fDeltaS, matXform);
    return;
  }
  if ( this->m_FreeAimSimObject.m_pPointer )
  {
    if ( this->m_eAimBlendMode == eAIM_BLEND_MODE_FREEAIM_TARGET )
      goto LABEL_22;
    v8 = *(float *)(*(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8) + 404i64);
    if ( v8 < 0.0 )
      this->m_fAimTransitionRadPerS = v8;
    this->m_eAimBlendMode = eAIM_BLEND_MODE_FREEAIM_TARGET;
    UFG::AimingBaseComponent::updateAimDirection(this, fDeltaS, matXform);
  }
  else
  {
    if ( this->m_eAimBlendMode == eAIM_BLEND_MODE_FREEAIM )
      goto LABEL_22;
    if ( BYTE2(m_pSimComponent[52].m_BoundComponentHandles.mNode.mPrev) )
      v9 = FLOAT_N1_0;
    else
      v9 = *(float *)(*(_QWORD *)(*(_QWORD *)(v6 + 176) + 8i64 * *(unsigned int *)(v6 + 172) + 8) + 408i64);
    if ( v9 < 0.0 )
      this->m_fAimTransitionRadPerS = v9;
    this->m_eAimBlendMode = eAIM_BLEND_MODE_FREEAIM;
    UFG::AimingBaseComponent::updateAimDirection(this, fDeltaS, matXform);
  }
}

// File Line: 485
// RVA: 0x541E70
void __fastcall UFG::AimingPlayerComponent::OnTargetChanged(UFG::AimingPlayerComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  if ( (unsigned int)(LODWORD(m_pSimComponent[53].m_pSimObject) - 3) > 1
    && LODWORD(m_pSimComponent[53].m_pSimObject) != 2 )
  {
    UFG::AimingBaseComponent::OnTargetChanged(this);
  }
  if ( (unsigned int)(this->m_eSoftLockType - 2) <= 1 )
    this->m_eSoftLockType = eSOFT_LOCK_NONE;
}

// File Line: 506
// RVA: 0x558870
void __fastcall UFG::AimingPlayerComponent::Update(UFG::AimingPlayerComponent *this, float fDeltaS)
{
  float v2; // xmm0_4
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  float mSimTimeUnscaledDelta; // xmm10_4
  UFG::qMatrix44 *p_mWorldTransform; // rsi
  bool v8; // r14
  char v9; // bl
  UFG::SimComponent *mPrev; // r9
  __int16 v11; // dx
  unsigned int v12; // r8d
  unsigned int v13; // r10d
  __int64 v14; // rdx
  __int64 v15; // rcx
  char v16; // al
  __int64 v17; // rax
  bool v18; // zf
  char v19; // al
  __int64 v20; // rax
  char v21; // al
  __int64 v22; // rax
  char v23; // al
  UFG::SimComponent *m_pSimComponent; // rcx
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  __m128 x_low; // xmm2
  float v29; // xmm1_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm7_4
  __m128 v33; // xmm2
  float v34; // xmm0_4
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  float v37; // xmm11_4
  float v38; // xmm11_4
  __m128 v39; // xmm12
  float v40; // xmm11_4
  __m128 v41; // xmm8
  float v42; // xmm1_4
  float v43; // xmm0_4
  __m128 v44; // xmm9
  float v45; // xmm2_4
  float v46; // xmm8_4
  __m128 v47; // xmm5
  float v48; // xmm3_4
  UFG::TransformNodeComponent *v49; // rcx
  float v50; // xmm0_4
  UFG::qVector3 vAimDirection; // [rsp+18h] [rbp-69h] BYREF
  UFG::qMatrix44 m; // [rsp+28h] [rbp-59h] BYREF

  v3 = *(UFG::TransformNodeComponent **)&this->m_Accuracy.m_bEnsureMiss;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  mNext = this[-1].m_pAimTargetPositionTNC.mNext;
  mSimTimeUnscaledDelta = UFG::Metrics::msInstance.mSimTimeUnscaledDelta;
  p_mWorldTransform = &v3->mWorldTransform;
  v8 = (unsigned int)(LODWORD(this->m_CharacterOccupantComponent.m_pSimComponent[53].m_pSimObject) - 3) <= 1;
  v9 = 0;
  if ( !mNext )
  {
    mPrev = 0i64;
LABEL_20:
    v16 = 0;
    goto LABEL_21;
  }
  v11 = WORD2(mNext[4].mNext);
  if ( (v11 & 0x4000) != 0 )
  {
    mPrev = (UFG::SimComponent *)mNext[6].mNext[7].mPrev;
  }
  else if ( v11 >= 0 )
  {
    if ( (v11 & 0x2000) != 0 )
    {
      mPrev = (UFG::SimComponent *)mNext[6].mNext[6].mPrev;
    }
    else if ( (v11 & 0x1000) != 0 )
    {
      v12 = (unsigned int)mNext[8].mPrev;
      v13 = (unsigned int)mNext[6].mPrev;
      if ( v12 >= v13 )
      {
LABEL_15:
        mPrev = 0i64;
      }
      else
      {
        v14 = (__int64)&mNext[6].mNext[v12];
        while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v14 += 16i64;
          if ( v12 >= v13 )
            goto LABEL_15;
        }
        mPrev = *(UFG::SimComponent **)v14;
      }
    }
    else
    {
      mPrev = UFG::SimObject::GetComponentOfType((UFG::SimObject *)mNext, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    mPrev = (UFG::SimComponent *)mNext[6].mNext[7].mPrev;
  }
  if ( !mPrev )
    goto LABEL_20;
  v15 = *((_QWORD *)&mPrev[11].m_SafePointerList.mNode.mPrev + ((__int64)(int)gActionRequest_CameraZoom.m_EnumValue >> 6));
  v16 = 1;
  if ( !_bittest64(&v15, gActionRequest_CameraZoom.m_EnumValue & 0x3F) )
    goto LABEL_20;
LABEL_21:
  BYTE2(this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev) = v16;
  if ( !mPrev
    || (v17 = *((_QWORD *)&mPrev[11].m_SafePointerList.mNode.mPrev
              + ((__int64)(int)gActionRequest_UseCover.m_EnumValue >> 6)),
        v18 = _bittest64(&v17, gActionRequest_UseCover.m_EnumValue & 0x3F) == 0,
        v19 = 1,
        v18) )
  {
    v19 = 0;
  }
  BYTE3(this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev) = v19;
  if ( !mPrev
    || (v20 = *((_QWORD *)&mPrev[11].m_SafePointerList.mNode.mPrev
              + ((__int64)(int)gActionRequest_AimingSupressReticle.m_EnumValue >> 6)),
        v18 = _bittest64(&v20, gActionRequest_AimingSupressReticle.m_EnumValue & 0x3F) == 0,
        v21 = 1,
        v18) )
  {
    v21 = 0;
  }
  BYTE4(this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev) = v21;
  if ( !mPrev
    || (v22 = *((_QWORD *)&mPrev[11].m_SafePointerList.mNode.mPrev
              + ((__int64)(int)gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumValue >> 6)),
        v18 = _bittest64(&v22, gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumValue & 0x3F) == 0,
        v23 = 1,
        v18) )
  {
    v23 = 0;
  }
  BYTE5(this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev) = v23;
  m_pSimComponent = this->m_CharacterOccupantComponent.m_pSimComponent;
  if ( BYTE2(m_pSimComponent[52].m_BoundComponentHandles.mNode.mPrev)
    || (unsigned int)(LODWORD(m_pSimComponent[53].m_pSimObject) - 3) <= 1
    || LODWORD(m_pSimComponent[53].m_pSimObject) == 2 )
  {
    v9 = 1;
  }
  BYTE6(this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev) = v9;
  UFG::AimingBaseComponent::updateAimOriginPosition(
    (UFG::AimingPlayerComponent *)((char *)this - 64),
    p_mWorldTransform);
  UFG::AimingPlayerComponent::possiblyResetFreeAimIntention((UFG::AimingPlayerComponent *)((char *)this - 64));
  if ( BYTE6(this->UFG::qNode<UFG::AimingPlayerComponent,UFG::AimingPlayerComponent>::mPrev) )
  {
    UFG::AimingPlayerComponent::updateFreeAimInput(
      (UFG::AimingPlayerComponent *)((char *)this - 64),
      mSimTimeUnscaledDelta);
    UFG::AimingPlayerComponent::updateFreeAimIntention(
      (UFG::AimingPlayerComponent *)((char *)this - 64),
      mSimTimeUnscaledDelta,
      v2);
  }
  UFG::AimingPlayerComponent::updateFreeAimOrigin(
    (UFG::AimingPlayerComponent *)((char *)this - 64),
    mSimTimeUnscaledDelta);
  UFG::AimingPlayerComponent::updateFreeAimTargetPosition((UFG::AimingPlayerComponent *)((char *)this - 64));
  UFG::AimingPlayerComponent::updateTargetDimensions((UFG::AimingPlayerComponent *)((char *)this - 64));
  UFG::AimingPlayerComponent::updateSoftLockOffset((UFG::AimingPlayerComponent *)((char *)this - 64), p_mWorldTransform);
  UFG::AimingPlayerComponent::updateAimIntentionTargetPosition(
    (UFG::AimingPlayerComponent *)((char *)this - 64),
    p_mWorldTransform);
  if ( !v8 )
    UFG::AimingBaseComponent::clampAimIntentionTargetPositionDistance((UFG::AimingPlayerComponent *)((char *)this - 64));
  UFG::AimingBaseComponent::updateAimIntention((UFG::AimingPlayerComponent *)((char *)this - 64), mSimTimeUnscaledDelta);
  UFG::AimingBaseComponent::clampAimIntention((UFG::AimingPlayerComponent *)((char *)this - 64), p_mWorldTransform);
  UFG::AimingPlayerComponent::updatePlayerAimDirection(
    (UFG::AimingPlayerComponent *)((char *)this - 64),
    mSimTimeUnscaledDelta,
    p_mWorldTransform);
  UFG::AimingBaseComponent::GetAimDirection(
    (UFG::AimingPlayerComponent *)((char *)this - 64),
    &vAimDirection,
    p_mWorldTransform);
  v25 = *(float *)&this->m_TypeUID;
  v26 = (float)(vAimDirection.z * v25)
      + *(float *)&this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev;
  v27 = (float)(v25 * vAimDirection.y) + *((float *)&this->m_pSimObject + 1);
  *(float *)&this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr = (float)(vAimDirection.x * v25)
                                                                         + *(float *)&this->m_pSimObject;
  *(float *)&this->UFG::AimingBaseComponent::UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>::mPrev = v26;
  *((float *)&this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr + 1) = v27;
  if ( this->m_AimingFreeAimConeClampTaskList.mNode.mNext )
  {
    UFG::AimingBaseComponent::GetAimDirection(
      (UFG::AimingPlayerComponent *)((char *)this - 64),
      &vAimDirection,
      p_mWorldTransform);
    x_low = (__m128)LODWORD(vAimDirection.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                              + (float)(vAimDirection.y * vAimDirection.y))
                      + (float)(vAimDirection.z * vAimDirection.z);
    if ( x_low.m128_f32[0] == 0.0 )
      v29 = 0.0;
    else
      v29 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
    v30 = vAimDirection.x * v29;
    v31 = vAimDirection.y * v29;
    v32 = vAimDirection.z * v29;
    m.v0.w = 0.0;
    v33 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    m.v0.x = vAimDirection.x * v29;
    m.v0.y = vAimDirection.y * v29;
    m.v0.z = vAimDirection.z * v29;
    v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    if ( v33.m128_f32[0] == 0.0 )
    {
      v35 = 0i64;
    }
    else
    {
      v34 = _mm_sqrt_ps(v33).m128_f32[0];
      v35 = (__m128)(unsigned int)FLOAT_1_0;
      v35.m128_f32[0] = 1.0 / v34;
    }
    v36 = v35;
    v37 = v35.m128_f32[0];
    v35.m128_f32[0] = v35.m128_f32[0] * UFG::qVector3::msDirUp.z;
    v38 = v37 * UFG::qVector3::msDirUp.x;
    v36.m128_f32[0] = v36.m128_f32[0] * UFG::qVector3::msDirUp.y;
    v39 = v36;
    v39.m128_f32[0] = (float)(v36.m128_f32[0] * v32) - (float)(v35.m128_f32[0] * v31);
    v35.m128_f32[0] = (float)(v35.m128_f32[0] * v30) - (float)(v38 * v32);
    v40 = (float)(v38 * v31) - (float)(v36.m128_f32[0] * v30);
    v41 = v35;
    v41.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v39.m128_f32[0] * v39.m128_f32[0]))
                    + (float)(v40 * v40);
    if ( v41.m128_f32[0] == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / _mm_sqrt_ps(v41).m128_f32[0];
    v39.m128_f32[0] = v39.m128_f32[0] * v42;
    m.v1.w = 0.0;
    v44 = v39;
    m.v1.z = v40 * v42;
    LODWORD(m.v1.x) = v39.m128_i32[0];
    m.v1.y = v35.m128_f32[0] * v42;
    v43 = (float)(v35.m128_f32[0] * v42) * v32;
    v44.m128_f32[0] = (float)(v39.m128_f32[0] * v32) - (float)((float)(v40 * v42) * v30);
    v45 = (float)((float)(v35.m128_f32[0] * v42) * v30) - (float)(v39.m128_f32[0] * v31);
    v46 = (float)((float)(v40 * v42) * v31) - v43;
    v47 = v44;
    v47.m128_f32[0] = (float)((float)(v44.m128_f32[0] * v44.m128_f32[0]) + (float)(v46 * v46)) + (float)(v45 * v45);
    if ( v47.m128_f32[0] == 0.0 )
      v48 = 0.0;
    else
      v48 = 1.0 / _mm_sqrt_ps(v47).m128_f32[0];
    v49 = (UFG::TransformNodeComponent *)this->m_AimingFreeAimConeClampTaskList.mNode.mNext;
    m.v3.x = *(float *)&this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr;
    m.v2.w = 0.0;
    m.v3.w = 1.0;
    v50 = *(float *)&this->UFG::AimingBaseComponent::UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>::mPrev;
    m.v2.z = v45 * v48;
    m.v3.y = *((float *)&this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr + 1);
    m.v2.x = v46 * v48;
    m.v2.y = v44.m128_f32[0] * v48;
    m.v3.z = v50;
    UFG::TransformNodeComponent::SetWorldTransform(v49, &m);
  }
  UFG::AimingPlayerComponent::updateAccuracy(
    (UFG::AimingPlayerComponent *)((char *)this + 0xFFFFFFC0),
    mSimTimeUnscaledDelta);
}

// File Line: 577
// RVA: 0x523160
float __fastcall UFG::AimingPlayerComponent::ComputeRenderReticleRadius(
        UFG::AimingPlayerComponent *this,
        bool screenSpace)
{
  float v3; // xmm0_4
  float v4; // xmm6_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  Illusion::Target *BackBufferTarget; // rax
  __m128i v7; // xmm1
  __m128i v8; // xmm0
  UFG::Camera *v9; // rbx
  UFG::BaseCameraComponent *v10; // rax
  _DWORD *p_mFOVOffset; // rax
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
  UFG::Camera *p_mCamera; // rcx
  UFG::qVector3 *ScreenCoord; // rax
  float x; // xmm6_4
  float y; // xmm7_4
  UFG::BaseCameraComponent *v28; // rcx
  UFG::qVector3 *v29; // rax
  __m128 y_low; // xmm1
  float v31; // xmm0_4
  UFG::qVector3 world_pos; // [rsp+30h] [rbp-78h] BYREF
  UFG::qVector3 v33; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-58h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+B0h] [rbp+8h] BYREF
  bool is_on_screen; // [rsp+B8h] [rbp+10h] BYREF

  v3 = ((float (__fastcall *)(UFG::AimingPlayerComponent *))this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[19].__vecDelDtor)(this);
  v4 = sinf(v3) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  if ( !screenSpace )
    return v4;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( !mCurrentCamera || mCurrentCamera == (UFG::BaseCameraComponent *)-80i64 )
    return v4;
  BackBufferTarget = Render::GetBackBufferTarget();
  v7 = _mm_cvtsi32_si128(BackBufferTarget->mHeight);
  v8 = _mm_cvtsi32_si128(BackBufferTarget->mWidth);
  is_on_screen = 0;
  LODWORD(viewport_scale.x) = _mm_cvtepi32_ps(v8).m128_u32[0];
  LODWORD(viewport_scale.y) = _mm_cvtepi32_ps(v7).m128_u32[0];
  v9 = 0i64;
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 )
    p_mFOVOffset = (_DWORD *)&v10->mCamera.mFOVOffset;
  else
    p_mFOVOffset = 0i64;
  v12 = COERCE_FLOAT(p_mFOVOffset[40] ^ _xmm[0]) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  v13 = COERCE_FLOAT(p_mFOVOffset[41] ^ _xmm[0]) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
  v14 = COERCE_FLOAT(p_mFOVOffset[42] ^ _xmm[0]) * UFG::AimingPlayerComponent::ms_fReticleRenderDistanceFromCamera;
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
    p_mCamera = &v23->mCamera;
  else
    p_mCamera = 0i64;
  ScreenCoord = UFG::Camera::GetScreenCoord(p_mCamera, &result, &world_pos, &viewport_scale, &is_on_screen);
  x = ScreenCoord->x;
  y = ScreenCoord->y;
  v28 = UFG::Director::Get()->mCurrentCamera;
  if ( v28 )
    v9 = &v28->mCamera;
  v29 = UFG::Camera::GetScreenCoord(v9, &result, &v33, &viewport_scale, &is_on_screen);
  y_low = (__m128)LODWORD(v29->y);
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                    + (float)((float)(v29->x - x) * (float)(v29->x - x));
  LODWORD(v31) = _mm_sqrt_ps(y_low).m128_u32[0];
  return v31;
}

// File Line: 653
// RVA: 0x560960
void __fastcall UFG::AimingPlayerComponent::UpdateReticlePosition(float fDeltaS)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // dx
  UFG::AimingPlayerComponent *ComponentOfType; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v5; // r9d
  unsigned int v6; // r10d
  __int64 v7; // rdx
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int size; // r10d
  unsigned int v10; // r9d
  unsigned int v11; // r10d

  LocalPlayer = UFG::GetLocalPlayer();
  if ( !LocalPlayer )
    goto LABEL_32;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        mComponentTableEntryCount = LocalPlayer->mComponentTableEntryCount;
        size = LocalPlayer->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          v7 = (__int64)&LocalPlayer->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingPlayerComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v7 += 16i64;
            if ( mComponentTableEntryCount >= size )
            {
              ComponentOfType = 0i64;
              goto LABEL_30;
            }
          }
          goto LABEL_14;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                            LocalPlayer,
                                                            UFG::AimingPlayerComponent::_TypeUID);
          goto LABEL_30;
        }
        v10 = LocalPlayer->mComponentTableEntryCount;
        v11 = LocalPlayer->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (__int64)&LocalPlayer->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingPlayerComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
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
      v5 = LocalPlayer->mComponentTableEntryCount;
      v6 = LocalPlayer->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (__int64)&LocalPlayer->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
             || (UFG::AimingPlayerComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
          {
            ComponentOfType = 0i64;
            goto LABEL_30;
          }
        }
LABEL_14:
        ComponentOfType = *(UFG::AimingPlayerComponent **)v7;
        goto LABEL_30;
      }
    }
LABEL_28:
    ComponentOfType = 0i64;
    goto LABEL_30;
  }
  ComponentOfType = (UFG::AimingPlayerComponent *)LocalPlayer->m_Components.p[47].m_pComponent;
  if ( !ComponentOfType
    || (m_TypeUID = ComponentOfType->m_TypeUID, ((m_TypeUID ^ UFG::AimingPlayerComponent::_TypeUID) & 0xFE000000) != 0)
    || (UFG::AimingPlayerComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ComponentOfType = 0i64;
  }
LABEL_30:
  if ( !ComponentOfType || !UFG::AimingPlayerComponent::updateReticlePosition(ComponentOfType, fDeltaS) )
LABEL_32:
    UFG::UIHKScreenHud::SetReticleState(STATE_NORMAL);
}

// File Line: 682
// RVA: 0x577560
bool __fastcall UFG::AimingPlayerComponent::updateReticlePosition(UFG::AimingPlayerComponent *this, float fDeltaS)
{
  Illusion::Target *BackBufferTarget; // rax
  float x; // xmm8_4
  float v6; // xmm7_4
  UFG::TargetingSystemPedPlayerComponent *v7; // r13
  UFG::SimObjectWeaponPropertiesComponent *m_pPointer; // r15
  bool v9; // al
  UFG::eFocusModeEnum m_eFocusMode; // ecx
  bool v11; // dl
  bool v12; // al
  bool v13; // zf
  UFG::SimObject *v14; // r14
  UFG::eFactionStandingEnum TargetingStandingToMe; // esi
  __int64 v16; // rcx
  UFG::TargetingSimObject *m_pTargets; // rax
  hkLocalFrameGroup *Texture; // rdi
  UFG::eHighlightModeEnum v19; // r12d
  __int16 v20; // cx
  unsigned int v21; // r8d
  unsigned int vfptr; // r9d
  __int64 v23; // rdx
  hkSimpleLocalFrame *ComponentOfType; // r14
  unsigned int v25; // r8d
  unsigned int v26; // r9d
  unsigned int v27; // r8d
  unsigned int v28; // r9d
  __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  unsigned int v31; // r8d
  unsigned int v32; // r9d
  __int64 v33; // rdx
  unsigned int v34; // r8d
  unsigned int v35; // r9d
  Illusion::Target *v36; // rax
  float mHeight; // xmm1_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *v39; // rcx
  float y; // xmm1_4
  float v41; // xmm0_4
  UFG::qReflectObject *mData; // rax
  UFG::FireModeInfo *v43; // rdx
  float mHardLockReticleSizeMin; // xmm7_4
  float mHardLockReticleSizeMax; // xmm6_4
  float ReticleSize; // xmm0_4
  bool result; // al
  char v48; // di
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  float v50; // xmm1_4
  float z; // xmm0_4
  UFG::BaseCameraComponent *v52; // rcx
  UFG::Camera *p_mCamera; // rcx
  UFG::qVector3 *ScreenCoord; // rax
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm0_4
  UFG::qVector2 *p_m_vReticleBlendedCoordsScreen; // rdi
  float v59; // xmm0_4
  float v60; // xmm0_4
  float m_fBlendedReticleRadius; // xmm1_4
  int v62; // eax
  UFG::qReflectObject *v63; // rax
  UFG::FireModeInfo *v64; // rdx
  float mReticleSizeMin; // xmm7_4
  float mReticleSizeMax; // xmm6_4
  float v67; // xmm0_4
  float m_fBlendedReticleSize; // xmm1_4
  unsigned int eWeaponReticleEnum; // [rsp+0h] [rbp-49h]
  UFG::qVector3 v70; // [rsp+8h] [rbp-41h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+18h] [rbp-31h] BYREF
  UFG::qVector3 v72; // [rsp+20h] [rbp-29h] BYREF
  bool v73; // [rsp+B0h] [rbp+67h] BYREF
  bool is_on_screen; // [rsp+C0h] [rbp+77h] BYREF
  bool v75; // [rsp+C8h] [rbp+7Fh]

  BackBufferTarget = Render::GetBackBufferTarget();
  x = (float)BackBufferTarget->mWidth * 0.5;
  v6 = (float)BackBufferTarget->mHeight * 0.5;
  v7 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pTargetingSystemPedBaseComponent.m_pSimComponent->vfptr[19].__vecDelDtor)(this->m_pTargetingSystemPedBaseComponent.m_pSimComponent);
  m_pPointer = (UFG::SimObjectWeaponPropertiesComponent *)v7->m_pEquippedSOWPC.m_pPointer;
  if ( !v7->m_bHasRangedWeapon || !m_pPointer )
    goto LABEL_136;
  eWeaponReticleEnum = m_pPointer->mHudReticule;
  v9 = m_pPointer->mWeaponTypeInfo->mFireModes[m_pPointer->mFireMode]->mHasSniperScope && this->m_bCameraZoomMode;
  if ( !m_pPointer->mHudReticule || v9 || !v7->m_bIsAimingActive )
    goto LABEL_136;
  m_eFocusMode = v7->m_eFocusMode;
  v75 = m_eFocusMode == eFOCUS_MODE_LOCKED_SOFT;
  is_on_screen = (unsigned int)(m_eFocusMode - 1) <= 1;
  v11 = (unsigned int)(m_eFocusMode - 3) <= 1;
  v12 = (unsigned int)(m_eFocusMode - 1) <= 1 || (unsigned int)(m_eFocusMode - 3) <= 1;
  v13 = !this->m_bSupressReticle;
  v73 = v12;
  if ( !v13 || !v12 && !this->m_bUsingCover )
    goto LABEL_136;
  v14 = this->m_FreeAimSimObject.m_pPointer;
  TargetingStandingToMe = FACTIONSTANDING_INDIFFERENT;
  v16 = (unsigned __int8)v7->m_pTargetingMap->m_Map.p[22];
  m_pTargets = v7->m_pTargets;
  *(_QWORD *)&v70.x = v14;
  Texture = (hkLocalFrameGroup *)m_pTargets[v16].m_pTarget.m_pPointer;
  if ( v14 && v11 )
    Texture = (hkLocalFrameGroup *)v14;
  v19 = eHIGHLIGHT_MODE_NONE;
  if ( !Texture )
    goto LABEL_78;
  v20 = WORD2(Texture[3].vfptr);
  if ( (v20 & 0x4000) != 0 )
  {
    v21 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
    vfptr = (unsigned int)Texture[4].vfptr;
    if ( v21 < vfptr )
    {
      v23 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v21;
      while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v21;
        v23 += 16i64;
        if ( v21 >= vfptr )
          goto LABEL_27;
      }
LABEL_28:
      ComponentOfType = *(hkSimpleLocalFrame **)v23;
      goto LABEL_46;
    }
  }
  else
  {
    if ( v20 < 0 )
    {
      ComponentOfType = *(hkSimpleLocalFrame **)(*(_QWORD *)&Texture[4].m_memSizeAndFlags + 480i64);
      goto LABEL_46;
    }
    if ( (v20 & 0x2000) != 0 )
    {
      v25 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
      v26 = (unsigned int)Texture[4].vfptr;
      if ( v25 < v26 )
      {
        v23 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v25;
        while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v25;
          v23 += 16i64;
          if ( v25 >= v26 )
          {
            ComponentOfType = 0i64;
            goto LABEL_46;
          }
        }
        goto LABEL_28;
      }
    }
    else
    {
      if ( (v20 & 0x1000) == 0 )
      {
        ComponentOfType = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)Texture,
                                                  UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_46;
      }
      v27 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
      v28 = (unsigned int)Texture[4].vfptr;
      if ( v27 < v28 )
      {
        v23 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v27;
        while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v27;
          v23 += 16i64;
          if ( v27 >= v28 )
          {
            ComponentOfType = 0i64;
            goto LABEL_46;
          }
        }
        goto LABEL_28;
      }
    }
  }
LABEL_27:
  ComponentOfType = 0i64;
LABEL_46:
  if ( ComponentOfType && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(ComponentOfType) )
    Texture = Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(ComponentOfType);
  if ( !Texture )
    goto LABEL_72;
  v29 = WORD2(Texture[3].vfptr);
  if ( (v29 & 0x4000) == 0 )
  {
    if ( v29 < 0 )
    {
      v30 = *(UFG::SimComponent **)(*(_QWORD *)&Texture[4].m_memSizeAndFlags + 96i64);
      goto LABEL_70;
    }
    if ( (v29 & 0x2000) != 0 )
    {
      v31 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
      v32 = (unsigned int)Texture[4].vfptr;
      if ( v31 < v32 )
      {
        v33 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v31;
        while ( (*(_DWORD *)(v33 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v33 + 8) & 0x1FFFFFF) != 0 )
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
      if ( (v29 & 0x1000) == 0 )
      {
        v30 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)Texture, UFG::HealthComponent::_TypeUID);
        goto LABEL_70;
      }
      v34 = *(_DWORD *)&Texture[5].m_memSizeAndFlags;
      v35 = (unsigned int)Texture[4].vfptr;
      if ( v34 < v35 )
      {
        v33 = *(_QWORD *)&Texture[4].m_memSizeAndFlags + 16i64 * v34;
        while ( (*(_DWORD *)(v33 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
             || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v33 + 8) & 0x1FFFFFF) != 0 )
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
  v30 = *(UFG::SimComponent **)(*(_QWORD *)&Texture[4].m_memSizeAndFlags + 96i64);
LABEL_70:
  if ( !v30 || !BYTE4(v30[1].m_BoundComponentHandles.mNode.mPrev) )
  {
LABEL_72:
    TargetingStandingToMe = (unsigned int)UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
                                            v7,
                                            (UFG::SimObject *)Texture);
    if ( TargetingStandingToMe == FACTIONSTANDING_INDIFFERENT )
      TargetingStandingToMe = FACTIONSTANDING_ALLIED;
    if ( ComponentOfType && !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(ComponentOfType) )
      TargetingStandingToMe = FACTIONSTANDING_INDIFFERENT;
  }
  v14 = *(UFG::SimObject **)&v70.x;
LABEL_78:
  v36 = Render::GetBackBufferTarget();
  mHeight = (float)v36->mHeight;
  viewport_scale.x = (float)v36->mWidth;
  viewport_scale.y = mHeight;
  if ( is_on_screen && !v75 )
  {
    if ( Texture )
    {
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      v39 = mCurrentCamera ? &mCurrentCamera->mCamera : 0i64;
      UFG::Camera::GetScreenCoord(v39, &v70, &this->m_vAimPosition, &viewport_scale, &is_on_screen);
      if ( is_on_screen )
      {
        y = v70.y;
        if ( !v73 )
          TargetingStandingToMe = FACTIONSTANDING_INDIFFERENT;
        this->m_vReticleLockedOnCoordsScreen.x = v70.x;
        this->m_vReticleLockedOnCoordsScreen.y = y;
        *(_QWORD *)&this->m_fReticleBlend = 0i64;
        v41 = UFG::AimingPlayerComponent::ComputeRenderReticleRadius(this, 1);
        UFG::UIHKScreenHud::SetReticlePosition(
          (float)(int)this->m_vReticleLockedOnCoordsScreen.x,
          (float)(int)this->m_vReticleLockedOnCoordsScreen.y);
        UFG::UIHKScreenHud::SetReticleState(STATE_COMPLETE);
        UFG::UIHKScreenHud::SetReticleScreenSpaceRadius(v41);
        UFG::UIHKScreenHud::SetReticleTargetFaction(TargetingStandingToMe);
        UFG::UIHKScreenHud::SetReticleType(
          eWeaponReticleEnum,
          m_pPointer->mWeaponTypeInfo->mFireModes[m_pPointer->mFireMode]->mExplosionType.mUID != -1);
        mData = this->m_FreeAimPhysicsObjectProperties.mData;
        if ( mData )
          v19 = (UFG::eHighlightModeEnum)mData[2].mBaseNode.mNeighbours[1];
        UFG::UIHKScreenHud::SetReticleHighlightMode(v19);
        v43 = m_pPointer->mWeaponTypeInfo->mFireModes[m_pPointer->mFireMode];
        if ( v7->m_eFocusMode == eFOCUS_MODE_LOCKED )
          mHardLockReticleSizeMin = v43->mHardLockReticleSizeMin;
        else
          mHardLockReticleSizeMin = v43->mReticleSizeMin;
        if ( v7->m_eFocusMode == eFOCUS_MODE_LOCKED )
          mHardLockReticleSizeMax = v43->mHardLockReticleSizeMax;
        else
          mHardLockReticleSizeMax = v43->mReticleSizeMax;
        ReticleSize = UFG::AimingPlayerComponent::GetReticleSize(this);
        UFG::UIHKScreenHud::SetReticleSize(ReticleSize, mHardLockReticleSizeMin, mHardLockReticleSizeMax);
        this->m_fBlendedReticleRadius = -1.0;
        this->m_fBlendedReticleSize = -1.0;
        return 1;
      }
    }
LABEL_136:
    this->m_vReticleLockedOnCoordsScreen.x = x;
    this->m_vReticleLockedOnCoordsScreen.y = v6;
    this->m_vReticleBlendedCoordsScreen.x = x;
    result = 0;
    this->m_vReticleBlendedCoordsScreen.y = v6;
    this->m_fReticleBlendRate = 1.0;
    this->m_fReticleBlend = 1.0;
    return result;
  }
  if ( !v14 )
    TargetingStandingToMe = FACTIONSTANDING_INDIFFERENT;
  v48 = 0;
  v70 = UFG::qVector3::msZero;
  if ( UFG::AimingPlayerComponent::ms_eReticleMode == eReticleMode_FollowAP )
  {
    v50 = this->m_vAimPosition.y;
    v70.x = this->m_vAimPosition.x;
    z = this->m_vAimPosition.z;
    goto LABEL_106;
  }
  if ( UFG::AimingPlayerComponent::ms_eReticleMode == eReticleMode_FollowAITP )
  {
    v50 = this->m_vAimIntentionTargetPosition.y;
    v70.x = this->m_vAimIntentionTargetPosition.x;
    z = this->m_vAimIntentionTargetPosition.z;
LABEL_106:
    v48 = 1;
    goto LABEL_107;
  }
  if ( UFG::AimingPlayerComponent::ms_eReticleMode != eReticleMode_FollowAITPCollOnly )
    goto LABEL_108;
  CurrentGameCamera = UFG::GetCurrentGameCamera();
  if ( !CurrentGameCamera || !BYTE5(CurrentGameCamera[47].mPrev) )
    goto LABEL_108;
  v50 = this->m_vAimIntentionTargetPosition.y;
  v48 = 1;
  v70.x = this->m_vAimIntentionTargetPosition.x;
  z = this->m_vAimIntentionTargetPosition.z;
LABEL_107:
  v70.y = v50;
  v70.z = z;
LABEL_108:
  if ( v48 )
  {
    v73 = 0;
    v52 = UFG::Director::Get()->mCurrentCamera;
    if ( v52 )
      p_mCamera = &v52->mCamera;
    else
      p_mCamera = 0i64;
    ScreenCoord = UFG::Camera::GetScreenCoord(p_mCamera, &v72, &v70, &viewport_scale, &v73);
    if ( UFG::AimingPlayerComponent::ms_bReticleMovementHoriz )
      x = ScreenCoord->x;
    if ( UFG::AimingPlayerComponent::ms_bReticleMovementVert )
      v6 = ScreenCoord->y;
  }
  v55 = *(float *)&FLOAT_1_0;
  v56 = (float)(s_fReticleBlendIncrementPerS * fDeltaS) + this->m_fReticleBlendRate;
  if ( v56 > 1.0 )
    v56 = *(float *)&FLOAT_1_0;
  this->m_fReticleBlendRate = v56;
  v57 = v56 + this->m_fReticleBlend;
  if ( v57 <= 1.0 )
    v55 = v57;
  this->m_fReticleBlend = v55;
  p_m_vReticleBlendedCoordsScreen = &this->m_vReticleBlendedCoordsScreen;
  if ( UFG::AimingPlayerComponent::ms_bReticleBlend )
  {
    UFG::qApproach(
      (float *)&this->m_vReticleBlendedCoordsScreen,
      x,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(p_m_vReticleBlendedCoordsScreen->x - x) & _xmm) * s_fRreticleApproachRate,
      fDeltaS);
    UFG::qApproach(
      &this->m_vReticleBlendedCoordsScreen.y,
      v6,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_vReticleBlendedCoordsScreen.y - v6) & _xmm) * s_fRreticleApproachRate,
      fDeltaS);
  }
  else
  {
    p_m_vReticleBlendedCoordsScreen->x = x;
    this->m_vReticleBlendedCoordsScreen.y = v6;
  }
  v59 = this->m_vReticleBlendedCoordsScreen.y;
  this->m_vReticleLockedOnCoordsScreen.x = p_m_vReticleBlendedCoordsScreen->x;
  this->m_vReticleLockedOnCoordsScreen.y = v59;
  v60 = UFG::AimingPlayerComponent::ComputeRenderReticleRadius(this, 1);
  m_fBlendedReticleRadius = this->m_fBlendedReticleRadius;
  if ( m_fBlendedReticleRadius >= 0.0 )
    v60 = (float)((float)(v60 - m_fBlendedReticleRadius) * 0.5) + m_fBlendedReticleRadius;
  v62 = (int)this->m_vReticleBlendedCoordsScreen.y;
  this->m_fBlendedReticleRadius = v60;
  UFG::UIHKScreenHud::SetReticlePosition((float)(int)p_m_vReticleBlendedCoordsScreen->x, (float)v62);
  UFG::UIHKScreenHud::SetReticleState(STATE_DANGER);
  UFG::UIHKScreenHud::SetReticleScreenSpaceRadius(this->m_fBlendedReticleRadius);
  UFG::UIHKScreenHud::SetReticleTargetFaction(TargetingStandingToMe);
  UFG::UIHKScreenHud::SetReticleType(
    eWeaponReticleEnum,
    m_pPointer->mWeaponTypeInfo->mFireModes[m_pPointer->mFireMode]->mExplosionType.mUID != -1);
  v63 = this->m_FreeAimPhysicsObjectProperties.mData;
  if ( v63 )
    v19 = (UFG::eHighlightModeEnum)v63[2].mBaseNode.mNeighbours[1];
  UFG::UIHKScreenHud::SetReticleHighlightMode(v19);
  v64 = m_pPointer->mWeaponTypeInfo->mFireModes[m_pPointer->mFireMode];
  if ( v7->m_eFocusMode == eFOCUS_MODE_LOCKED )
    mReticleSizeMin = v64->mHardLockReticleSizeMin;
  else
    mReticleSizeMin = v64->mReticleSizeMin;
  if ( v7->m_eFocusMode == eFOCUS_MODE_LOCKED )
    mReticleSizeMax = v64->mHardLockReticleSizeMax;
  else
    mReticleSizeMax = v64->mReticleSizeMax;
  v67 = UFG::AimingPlayerComponent::GetReticleSize(this);
  m_fBlendedReticleSize = this->m_fBlendedReticleSize;
  if ( m_fBlendedReticleSize >= 0.0 )
    v67 = (float)((float)(v67 - m_fBlendedReticleSize) * 0.5) + m_fBlendedReticleSize;
  this->m_fBlendedReticleSize = v67;
  UFG::UIHKScreenHud::SetReticleSize(v67, mReticleSizeMin, mReticleSizeMax);
  return 1;
}izeMax;
  else
    mReticleSizeMax = v64->mReticleSizeMax;
  v67 = UFG::AimingPlayerComponent::Get

// File Line: 943
// RVA: 0x56E750
void __fastcall UFG::AimingPlayerComponent::updateAccuracy(UFG::AimingPlayerComponent *this, const float fDeltaS)
{
  float m_fAccuracyUnclamped; // xmm10_4
  float m_fAccuracyPenalty; // xmm11_4
  UFG::SimComponent *m_pSimComponent; // rdx
  float m_fAccuracyOverride; // xmm0_4
  unsigned int v8; // eax
  bool v9; // si
  bool v10; // bp
  __int64 v11; // rdi
  __int16 v12; // cx
  UFG::SimComponent *v13; // rcx
  unsigned int v14; // r8d
  unsigned int v15; // r9d
  __int64 v16; // rdx
  unsigned int v17; // r8d
  unsigned int v18; // r9d
  float v19; // xmm1_4
  __int16 v20; // cx
  UFG::AimingBaseComponent *ComponentOfType; // rax
  unsigned int v22; // r8d
  unsigned int v23; // r9d
  __int64 v24; // rdx
  unsigned int v25; // r8d
  unsigned int v26; // r9d
  unsigned int v27; // r8d
  unsigned int v28; // r9d
  float v29; // xmm7_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  float m_fDefaultAccuracyRate; // xmm8_4
  __int64 v34; // rax
  __int64 v35; // rdx
  UFG::GameStatTracker *v36; // rax
  float v37; // xmm6_4
  char v38; // al
  int v39; // xmm0_4
  int v40; // xmm0_4
  float v41; // xmm6_4
  float v42; // xmm6_4
  float fAccuracyModifierContinuous; // [rsp+B0h] [rbp+8h] BYREF
  float fAccuracyModifierInstant; // [rsp+C0h] [rbp+18h] BYREF

  m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyUnclamped;
  if ( m_fAccuracyUnclamped <= this->m_Accuracy.m_fAccuracyMinimum )
    m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMinimum;
  if ( m_fAccuracyUnclamped >= this->m_Accuracy.m_fAccuracyMaximum )
    m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMaximum;
  m_fAccuracyPenalty = this->m_Accuracy.m_fAccuracyPenalty;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyMaximum = 0x3F800000i64;
  fAccuracyModifierContinuous = 0.0;
  fAccuracyModifierInstant = 0.0;
  if ( !this->m_pTSPPC.m_pSimComponent )
    return;
  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  m_fAccuracyOverride = this->m_Accuracy.m_fAccuracyOverride;
  v8 = LODWORD(m_pSimComponent[53].m_pSimObject) - 1;
  v9 = v8 <= 1;
  v10 = LODWORD(m_pSimComponent[53].m_pSimObject) == 2;
  if ( m_fAccuracyOverride < 0.0 )
  {
    if ( (unsigned int)(LODWORD(m_pSimComponent[53].m_pSimObject) - 3) > 1
      && (v8 > 1
       || !*(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 30i64)
                     + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                     + 40)) )
    {
      this->m_fAimObstructedDuration = 0.0;
      return;
    }
    v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 30i64)
                    + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                    + 40);
    if ( !v11 || v8 > 1 || LODWORD(m_pSimComponent[53].m_pSimObject) == 2 )
    {
LABEL_78:
      UFG::AimingBaseComponent::ApplyAccuracyModifiers(this, 0, &fAccuracyModifierInstant, &fAccuracyModifierContinuous);
      v29 = *(float *)&FLOAT_1_0;
      if ( fAccuracyModifierContinuous <= 0.0 )
      {
        if ( fAccuracyModifierContinuous < 0.0 )
        {
          v31 = fAccuracyModifierContinuous + this->m_Accuracy.m_fAccuracyMaximum;
          if ( v31 <= 0.0 )
            v31 = 0.0;
          this->m_Accuracy.m_fAccuracyMaximum = v31;
        }
      }
      else
      {
        v30 = fAccuracyModifierContinuous + this->m_Accuracy.m_fAccuracyMinimum;
        if ( v30 >= 1.0 )
          v30 = *(float *)&FLOAT_1_0;
        this->m_Accuracy.m_fAccuracyMinimum = v30;
      }
      mPrev = this->m_pTSPPC.m_pSimComponent[42].m_BoundComponentHandles.mNode.mPrev;
      if ( mPrev )
        m_fDefaultAccuracyRate = *(float *)&mPrev[3].mPrev;
      else
        m_fDefaultAccuracyRate = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fDefaultAccuracyRate;
      v34 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
      if ( v34 )
      {
        v35 = *(_QWORD *)(*(_QWORD *)(v34 + 176) + 8i64 * *(unsigned int *)(v34 + 172) + 8);
        if ( *(_DWORD *)(v35 + 100) != UFG::gNullQSymbolUC.mUID )
          m_fDefaultAccuracyRate = m_fDefaultAccuracyRate * *(float *)(v35 + 168);
      }
      v36 = UFG::GameStatTracker::Instance();
      if ( (int)UFG::GameStatTracker::GetStat(v36, GunplayUpgradeStage) >= UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_iRequiredLevelForGunplayUpgradeMarksman )
        m_fDefaultAccuracyRate = m_fDefaultAccuracyRate
                               * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fGunplayUpgradeMarksmanMultiplier;
      v37 = *(float *)&FLOAT_1_0;
      if ( UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
        v37 = UFG::PlayerBuffTracker::GetAccuracyRateMultiplier() + 1.0;
      if ( v11 && this->m_bFocusTargetObstructed )
        this->m_fAimObstructedDuration = fDeltaS + this->m_fAimObstructedDuration;
      else
        this->m_fAimObstructedDuration = 0.0;
      v38 = 0;
      *(float *)&v39 = m_fAccuracyPenalty;
      if ( UFG::AimingPlayerComponent::ms_fAimObstructionGracePeriod < this->m_fAimObstructedDuration )
        v38 = 1;
      if ( m_fAccuracyPenalty < 0.0 )
        v39 = LODWORD(m_fAccuracyPenalty) ^ _xmm[0];
      if ( *(float *)&v39 >= 0.001 )
        goto LABEL_113;
      *(float *)&v40 = fAccuracyModifierInstant;
      if ( fAccuracyModifierInstant < 0.0 )
        v40 = LODWORD(fAccuracyModifierInstant) ^ _xmm[0];
      if ( *(float *)&v40 >= 0.001 )
      {
LABEL_113:
        v41 = COERCE_FLOAT(LODWORD(m_fAccuracyPenalty) ^ _xmm[0]) + fAccuracyModifierInstant;
      }
      else if ( v38 && v9 && !v10 )
      {
        v41 = UFG::AimingPlayerComponent::ms_fObstructedPenaltyRate * fDeltaS;
      }
      else
      {
        v41 = (float)(v37 * m_fDefaultAccuracyRate) * fDeltaS;
      }
      v42 = v41 + m_fAccuracyUnclamped;
      if ( v42 <= 0.0 )
      {
        v42 = 0.0;
      }
      else if ( v42 >= 1.0 )
      {
        goto LABEL_119;
      }
      v29 = v42;
LABEL_119:
      this->m_Accuracy.m_fAccuracyUnclamped = v29;
      return;
    }
    v12 = *(_WORD *)(v11 + 76);
    if ( (v12 & 0x4000) != 0 )
    {
      v13 = *(UFG::SimComponent **)(*(_QWORD *)(v11 + 104) + 48i64);
      if ( !v13
        || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v13->m_TypeUID) & 0xFE000000) != 0
        || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_23;
      }
LABEL_45:
      if ( v13 )
      {
        v19 = *(float *)&v13[3].m_SafePointerList.mNode.mNext;
        if ( v19 <= -1.0 )
        {
          v19 = FLOAT_N1_0;
        }
        else if ( v19 >= 0.0 )
        {
          v19 = 0.0;
        }
        this->m_Accuracy.m_fAccuracyMaximum = (float)(UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fAccuracyEvadeModifier
                                                    * v19)
                                            + this->m_Accuracy.m_fAccuracyMaximum;
      }
      v20 = *(_WORD *)(v11 + 76);
      if ( (v20 & 0x4000) != 0 )
      {
        ComponentOfType = *(UFG::AimingBaseComponent **)(*(_QWORD *)(v11 + 104) + 752i64);
        goto LABEL_76;
      }
      if ( v20 >= 0 )
      {
        if ( (v20 & 0x2000) != 0 )
        {
          v25 = *(_DWORD *)(v11 + 128);
          v26 = *(_DWORD *)(v11 + 96);
          if ( v25 < v26 )
          {
            v24 = *(_QWORD *)(v11 + 104) + 16i64 * v25;
            while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
                 || (UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v25;
              v24 += 16i64;
              if ( v25 >= v26 )
              {
                ComponentOfType = 0i64;
                goto LABEL_76;
              }
            }
            goto LABEL_60;
          }
        }
        else
        {
          if ( (v20 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)v11,
                                                            UFG::AimingBaseComponent::_TypeUID);
LABEL_76:
            if ( ComponentOfType )
              UFG::AimingBaseComponent::ApplyAccuracyModifiers(
                ComponentOfType,
                1,
                &fAccuracyModifierInstant,
                &fAccuracyModifierContinuous);
            goto LABEL_78;
          }
          v27 = *(_DWORD *)(v11 + 128);
          v28 = *(_DWORD *)(v11 + 96);
          if ( v27 < v28 )
          {
            v24 = *(_QWORD *)(v11 + 104) + 16i64 * v27;
            while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
                 || (UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v27;
              v24 += 16i64;
              if ( v27 >= v28 )
              {
                ComponentOfType = 0i64;
                goto LABEL_76;
              }
            }
            goto LABEL_60;
          }
        }
      }
      else
      {
        v22 = *(_DWORD *)(v11 + 128);
        v23 = *(_DWORD *)(v11 + 96);
        if ( v22 < v23 )
        {
          v24 = *(_QWORD *)(v11 + 104) + 16i64 * v22;
          while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v22;
            v24 += 16i64;
            if ( v22 >= v23 )
              goto LABEL_59;
          }
LABEL_60:
          ComponentOfType = *(UFG::AimingBaseComponent **)v24;
          goto LABEL_76;
        }
      }
LABEL_59:
      ComponentOfType = 0i64;
      goto LABEL_76;
    }
    if ( v12 < 0 )
    {
      v13 = *(UFG::SimComponent **)(*(_QWORD *)(v11 + 104) + 48i64);
      if ( !v13 || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v13->m_TypeUID) & 0xFE000000) != 0 )
        goto LABEL_23;
      if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
        v13 = 0i64;
      goto LABEL_45;
    }
    if ( (v12 & 0x2000) != 0 )
    {
      v14 = *(_DWORD *)(v11 + 128);
      v15 = *(_DWORD *)(v11 + 96);
      if ( v14 < v15 )
      {
        v16 = *(_QWORD *)(v11 + 104) + 16i64 * v14;
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v14;
          v16 += 16i64;
          if ( v14 >= v15 )
          {
            v13 = 0i64;
            goto LABEL_45;
          }
        }
LABEL_36:
        v13 = *(UFG::SimComponent **)v16;
        goto LABEL_45;
      }
    }
    else
    {
      if ( (v12 & 0x1000) == 0 )
      {
        v13 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)v11,
                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_45;
      }
      v17 = *(_DWORD *)(v11 + 128);
      v18 = *(_DWORD *)(v11 + 96);
      if ( v17 < v18 )
      {
        v16 = *(_QWORD *)(v11 + 104) + 16i64 * v17;
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v17;
          v16 += 16i64;
          if ( v17 >= v18 )
          {
            v13 = 0i64;
            goto LABEL_45;
          }
        }
        goto LABEL_36;
      }
    }
LABEL_23:
    v13 = 0i64;
    goto LABEL_45;
  }
  if ( m_fAccuracyOverride <= 0.0 )
  {
    m_fAccuracyOverride = 0.0;
  }
  else if ( m_fAccuracyOverride >= 1.0 )
  {
    LODWORD(this->m_Accuracy.m_fAccuracyUnclamped) = (_DWORD)FLOAT_1_0;
    return;
  }
  this->m_Accuracy.m_fAccuracyUnclamped = m_fAccuracyOverride;
}  }
    }
LAB

// File Line: 1106
// RVA: 0x5784F0
void __fastcall UFG::AimingPlayerComponent::updateSoftLockOffset(
        UFG::AimingPlayerComponent *this,
        UFG::qMatrix44 *matXform)
{
  UFG::GameStatTracker *v4; // rax
  UFG::SimComponent *m_pSimComponent; // rdx
  UFG::AimingPlayerComponent::eSoftLockTypeEnum v6; // r14d
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  UFG::SimObject *v8; // rdi
  UFG::AimingPlayerComponent::eSoftLockTypeEnum m_eSoftLockType; // ecx
  bool v10; // r12
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v15; // rdx
  int mNext; // ecx
  signed __int16 v17; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v19; // r8d
  unsigned int v20; // r10d
  UFG::SimComponentHolder *v21; // rdx
  unsigned int v22; // r8d
  unsigned int v23; // r10d
  unsigned int v24; // r8d
  unsigned int v25; // r10d
  UFG::SimComponent *v26; // rcx
  UFG::SimComponent *v27; // rax
  char v28; // r12
  bool v29; // al
  float y; // xmm0_4
  float z; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm8_4
  float x; // xmm4_4
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
  __m128 y_low; // xmm4
  __m128 v47; // xmm1
  __int128 v48; // xmm3
  float v49; // xmm8_4
  float v50; // xmm3_4
  __int128 v51; // xmm5
  float v52; // xmm8_4
  __m128 x_low; // xmm2
  float v54; // xmm4_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm4_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm9_4
  float v61; // xmm11_4
  __m128 v62; // xmm10
  float v63; // xmm11_4
  __m128 v64; // xmm2
  float v65; // xmm0_4
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  float v68; // xmm4_4
  __m128 v69; // xmm10
  float v70; // xmm9_4
  float v71; // xmm4_4
  __m128 v72; // xmm2
  float v73; // xmm2_4
  float v74; // xmm8_4
  __int128 v75; // xmm9
  float v76; // xmm10_4
  __m128 v77; // xmm2
  float v78; // xmm3_4
  float v79; // xmm2_4
  float v80; // xmm2_4
  UFG::SimComponent *v81; // rax
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  bool v83; // cl
  UFG::AimingPlayerComponent::eSoftLockTypeEnum v84; // eax
  float v85; // xmm14_4
  __m128 v86; // xmm4
  __m128 v87; // xmm5
  __m128 v88; // xmm1
  __m128 v89; // xmm3
  float v90; // xmm5_4
  __m128 v91; // xmm2
  float v92; // xmm8_4
  float v93; // xmm1_4
  float v94; // xmm2_4
  float v95; // xmm8_4
  float v96; // xmm2_4
  float v97; // xmm1_4
  float v98; // xmm10_4
  float v99; // xmm8_4
  __m128 v100; // xmm9
  float v101; // xmm8_4
  __m128 v102; // xmm2
  float v103; // xmm1_4
  float v104; // xmm8_4
  float v105; // xmm10_4
  float v106; // xmm11_4
  __m128 v107; // xmm12
  float v108; // xmm13_4
  __m128 v109; // xmm2
  float v110; // xmm7_4
  float v111; // xmm1_4
  float v112; // xmm0_4
  float v113; // xmm2_4
  float v114; // xmm10_4
  float v115; // xmm8_4
  UFG::SimComponent *v116; // rax
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 v120; // [rsp+A0h] [rbp-60h] BYREF
  bool v121; // [rsp+1B0h] [rbp+B0h]

  v4 = UFG::GameStatTracker::Instance();
  if ( !UFG::GameStatTracker::GetStat(v4, AimSoftLockEnabled) )
  {
    this->m_bResetSoftLockOffset = 0;
    this->m_eSoftLockType = eSOFT_LOCK_NONE;
    return;
  }
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  v6 = eSOFT_LOCK_NONE;
  m_pTransformNodeComponent = 0i64;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 30i64)
                          + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                          + 40);
  if ( v8 )
    m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
  v121 = LODWORD(m_pSimComponent[53].m_pSimObject) == 2;
  if ( LODWORD(m_pSimComponent[53].m_pSimObject) == 2 )
  {
    m_eSoftLockType = this->m_eSoftLockType;
    if ( (unsigned int)(m_eSoftLockType - 2) <= 1 )
      v6 = this->m_eSoftLockType;
    v10 = this->m_bResetSoftLockOffset && m_eSoftLockType == eSOFT_LOCK_ABSOLUTE;
    if ( !v8 )
      goto LABEL_37;
    m_Flags = v8->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v8->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v8->m_Components.p[4].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)v8[1].vfptr;
        size = v8->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_25:
          m_pComponent = 0i64;
        }
        else
        {
          v15 = &v8->m_Components.p[vfptr];
          while ( (v15->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            ++v15;
            if ( vfptr >= size )
              goto LABEL_25;
          }
          m_pComponent = v15->m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v8, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v8->m_Components.p[3].m_pComponent;
    }
    if ( !m_pComponent )
      goto LABEL_37;
    mNext = (int)m_pComponent[1].m_SafePointerList.mNode.mNext;
    if ( mNext == 4 )
    {
      v6 = eSOFT_LOCK_RELATIVE_LOCAL;
    }
    else if ( mNext == 1 )
    {
      v6 = eSOFT_LOCK_RELATIVE_LOCAL_ORIENTED_TO_ORIGIN;
    }
    else if ( v6 == eSOFT_LOCK_NONE )
    {
LABEL_37:
      if ( v10 && v6 )
        this->m_bResetSoftLockOffset = 0;
      goto LABEL_40;
    }
    if ( v8 == this->m_FreeAimSimObject.m_pPointer && this->m_bResetSoftLockOffset )
      this->m_bResetSoftLockOffset = 0;
    goto LABEL_37;
  }
LABEL_40:
  if ( !v8 )
    goto LABEL_70;
  v17 = v8->m_Flags;
  if ( (v17 & 0x4000) == 0 )
  {
    if ( v17 >= 0 )
    {
      if ( (v17 & 0x2000) != 0 )
      {
        v22 = (unsigned int)v8[1].vfptr;
        v23 = v8->m_Components.size;
        if ( v22 < v23 )
        {
          v21 = &v8->m_Components.p[v22];
          while ( (v21->m_TypeUID & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v22;
            ++v21;
            if ( v22 >= v23 )
            {
              ComponentOfType = 0i64;
              goto LABEL_66;
            }
          }
          goto LABEL_50;
        }
      }
      else
      {
        if ( (v17 & 0x1000) == 0 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::AimingBaseComponent::_TypeUID);
          goto LABEL_66;
        }
        v24 = (unsigned int)v8[1].vfptr;
        v25 = v8->m_Components.size;
        if ( v24 < v25 )
        {
          v21 = &v8->m_Components.p[v24];
          while ( (v21->m_TypeUID & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v24;
            ++v21;
            if ( v24 >= v25 )
            {
              ComponentOfType = 0i64;
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
             || (UFG::AimingBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v19;
          ++v21;
          if ( v19 >= v20 )
            goto LABEL_49;
        }
LABEL_50:
        ComponentOfType = v21->m_pComponent;
        goto LABEL_66;
      }
    }
LABEL_49:
    ComponentOfType = 0i64;
    goto LABEL_66;
  }
  ComponentOfType = v8->m_Components.p[47].m_pComponent;
LABEL_66:
  if ( !ComponentOfType
    || (UFG::SimObject **)(*(_QWORD *)&ComponentOfType[3].m_TypeUID - 40i64) == &ComponentOfType[2].m_pSimObject
    || (v26 = this->m_pTSPPC.m_pSimComponent, (unsigned int)(LODWORD(v26[53].m_pSimObject) - 1) > 1) )
  {
LABEL_70:
    if ( v6 )
      goto LABEL_75;
    goto LABEL_71;
  }
  *(_DWORD *)(&v26[53].m_SimObjIndex + 1) = 3;
  LODWORD(v26[53].m_pSimObject) = 3;
  v6 = eSOFT_LOCK_NONE;
LABEL_71:
  if ( &this->m_AimingSoftLockTaskList.mNode.mNext[-3].mNext != (UFG::qNode<AimingSoftLockTask,AimingSoftLockList> **)&this->m_fFocusTargetRadius
    || UFG::AimingPlayerComponent::ms_bContinuousAbsoluteSoftLock
    || this->m_bFreeAimRootMovementLock )
  {
    v6 = eSOFT_LOCK_ABSOLUTE;
  }
LABEL_75:
  v27 = this->m_pTSPPC.m_pSimComponent;
  v28 = BYTE5(v27[52].m_BoundComponentHandles.mNode.mPrev);
  v29 = BYTE3(v27[52].m_BoundComponentHandles.mNode.mPrev) || v28 || this->m_bResetSoftLockOffset;
  if ( v6 != this->m_eSoftLockType || v29 )
  {
    switch ( v6 )
    {
      case eSOFT_LOCK_ABSOLUTE:
        y = this->m_vFreeAimTargetPosition.y;
        z = this->m_vFreeAimTargetPosition.z;
        this->m_vSoftLockOffset.x = this->m_vFreeAimTargetPosition.x;
        this->m_vSoftLockOffset.y = y;
        this->m_vSoftLockOffset.z = z;
        break;
      case eSOFT_LOCK_RELATIVE_LOCAL:
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        UFG::qInverseAffine(&d, &m_pTransformNodeComponent->mWorldTransform);
        if ( this->m_bResetSoftLockOffset )
        {
          UFG::AimingBaseComponent::GetTargetNormalAimPosition(this, &vTargetNormalAimPosition, 0x16u, matXform);
          v32 = vTargetNormalAimPosition.z;
          v33 = vTargetNormalAimPosition.y;
          x = vTargetNormalAimPosition.x;
        }
        else
        {
          x = this->m_vFreeAimTargetPosition.x;
          v33 = this->m_vFreeAimTargetPosition.y;
          v32 = this->m_vFreeAimTargetPosition.z;
        }
        v35 = d.v1.y;
        v36 = (float)((float)(d.v1.x * v33) + (float)(x * d.v0.x)) + (float)(d.v2.x * v32);
        v37 = x * d.v0.y;
        v38 = x * d.v0.z;
        v39 = d.v2.y * v32;
        this->m_vSoftLockOffset.x = v36 + d.v3.x;
        v40 = (float)((float)(v35 * v33) + v37) + v39;
        v41 = (float)((float)(d.v1.z * v33) + v38) + (float)(d.v2.z * v32);
        this->m_vSoftLockOffset.y = v40 + d.v3.y;
        this->m_vSoftLockOffset.z = v41 + d.v3.z;
        break;
      case eSOFT_LOCK_RELATIVE_LOCAL_ORIENTED_TO_ORIGIN:
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        y_low = (__m128)LODWORD(this->m_vFreeAimOrigin.y);
        v42 = m_pTransformNodeComponent->mWorldTransform.v3.x;
        v43 = m_pTransformNodeComponent->mWorldTransform.v3.y;
        v44 = m_pTransformNodeComponent->mWorldTransform.v3.z;
        v45 = this->m_vFreeAimOrigin.x - v42;
        y_low.m128_f32[0] = y_low.m128_f32[0] - v43;
        v47 = y_low;
        v47.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v45 * v45);
        if ( v47.m128_f32[0] == 0.0 )
        {
          v48 = 0i64;
        }
        else
        {
          v48 = (unsigned int)FLOAT_1_0;
          *(float *)&v48 = 1.0 / _mm_sqrt_ps(v47).m128_f32[0];
        }
        v51 = v48;
        v49 = *(float *)&v48;
        v50 = *(float *)&v48 * 0.0;
        *(float *)&v51 = *(float *)&v51 * v45;
        v52 = v49 * y_low.m128_f32[0];
        d.v0.w = 0.0;
        x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        LODWORD(d.v0.x) = v51;
        d.v0.y = v52;
        d.v0.z = v50;
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( x_low.m128_f32[0] == 0.0 )
          v54 = 0.0;
        else
          v54 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        v55 = v54;
        v56 = v54;
        v57 = v54 * UFG::qVector3::msDirUp.z;
        v58 = v56 * UFG::qVector3::msDirUp.x;
        v59 = v55 * UFG::qVector3::msDirUp.y;
        v62 = (__m128)v51;
        v60 = (float)(v50 * v59) - (float)(v52 * v57);
        v61 = v52 * v58;
        v62.m128_f32[0] = (float)(*(float *)&v51 * v57) - (float)(v50 * v58);
        v64 = v62;
        v63 = v61 - (float)(*(float *)&v51 * v59);
        v64.m128_f32[0] = (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)(v60 * v60)) + (float)(v63 * v63);
        if ( v64.m128_f32[0] == 0.0 )
        {
          v66 = 0i64;
        }
        else
        {
          v65 = _mm_sqrt_ps(v64).m128_f32[0];
          v66 = (__m128)(unsigned int)FLOAT_1_0;
          v66.m128_f32[0] = 1.0 / v65;
        }
        v67 = v66;
        v67.m128_f32[0] = v66.m128_f32[0] * v60;
        v68 = v66.m128_f32[0] * v62.m128_f32[0];
        d.v1.w = 0.0;
        d.v1.z = v66.m128_f32[0] * v63;
        v69 = v67;
        d.v1.x = v66.m128_f32[0] * v60;
        d.v1.y = v68;
        v69.m128_f32[0] = (float)((float)(v66.m128_f32[0] * v60) * v50)
                        - (float)((float)(v66.m128_f32[0] * v63) * *(float *)&v51);
        v70 = (float)((float)(v66.m128_f32[0] * v63) * v52) - (float)(v68 * v50);
        v71 = (float)(v68 * *(float *)&v51) - (float)(v67.m128_f32[0] * v52);
        v72 = v69;
        v72.m128_f32[0] = (float)((float)(v69.m128_f32[0] * v69.m128_f32[0]) + (float)(v70 * v70)) + (float)(v71 * v71);
        if ( v72.m128_f32[0] == 0.0 )
          v73 = 0.0;
        else
          v73 = 1.0 / _mm_sqrt_ps(v72).m128_f32[0];
        d.v3.x = v42;
        d.v3.y = v43;
        d.v2.w = 0.0;
        d.v3.w = 1.0;
        d.v2.z = v73 * v71;
        d.v3.z = v44;
        d.v2.x = v73 * v70;
        d.v2.y = v73 * v69.m128_f32[0];
        UFG::qInverseAffine(&v120, &d);
        if ( this->m_bResetSoftLockOffset )
        {
          UFG::AimingBaseComponent::GetTargetNormalAimPosition(this, &vTargetNormalAimPosition, 0x16u, matXform);
          v74 = vTargetNormalAimPosition.x;
          *(float *)&v75 = vTargetNormalAimPosition.y;
          v76 = vTargetNormalAimPosition.z;
        }
        else
        {
          if ( !v28 )
            goto LABEL_107;
          if ( !this->m_bFocusTargetProbed )
            goto LABEL_107;
          v75 = LODWORD(this->m_vFreeAimTargetPosition.y);
          v76 = this->m_vFreeAimTargetPosition.z;
          vTargetNormalAimPosition.x = this->m_vFreeAimTargetPosition.x;
          v74 = vTargetNormalAimPosition.x;
          LODWORD(vTargetNormalAimPosition.y) = v75;
          vTargetNormalAimPosition.z = v76;
          UFG::qNearestSegPoint(
            &result,
            &this->m_vFocusTargetSegA,
            &this->m_vFocusTargetSegB,
            &vTargetNormalAimPosition);
          v77 = (__m128)v75;
          v77.m128_f32[0] = (float)((float)((float)(*(float *)&v75 - result.y) * (float)(*(float *)&v75 - result.y))
                                  + (float)((float)(v74 - result.x) * (float)(v74 - result.x)))
                          + (float)((float)(v76 - result.z) * (float)(v76 - result.z));
          if ( _mm_sqrt_ps(v77).m128_f32[0] > (float)(UFG::AimingPlayerComponent::ms_fSoftLockCapsuleExpansionRatio
                                                    * this->m_fFocusTargetRadius) )
          {
LABEL_107:
            v76 = this->m_vFocusTargetClosestPos.z;
            *(float *)&v75 = this->m_vFocusTargetClosestPos.y;
            v74 = this->m_vFocusTargetClosestPos.x;
          }
        }
        v78 = (float)((float)((float)(v120.v1.y * *(float *)&v75) + (float)(v120.v0.y * v74)) + (float)(v120.v2.y * v76))
            + v120.v3.y;
        v79 = (float)((float)(v120.v1.z * *(float *)&v75) + (float)(v120.v0.z * v74)) + (float)(v120.v2.z * v76);
        this->m_vSoftLockOffset.x = (float)((float)((float)(v120.v1.x * *(float *)&v75) + (float)(v120.v0.x * v74))
                                          + (float)(v120.v2.x * v76))
                                  + v120.v3.x;
        v80 = v79 + v120.v3.z;
        this->m_vSoftLockOffset.y = v78;
        this->m_vSoftLockOffset.z = v80;
        break;
      default:
        v6 = eSOFT_LOCK_NONE;
        break;
    }
    this->m_eSoftLockType = v6;
  }
  if ( this->m_eSoftLockType == eSOFT_LOCK_NONE )
  {
    v81 = this->m_pTSPPC.m_pSimComponent;
    if ( LODWORD(v81[53].m_pSimObject) == 2 && !this->m_bFocusTargetProbed )
    {
      *(_DWORD *)(&v81[53].m_SimObjIndex + 1) = 3;
      LODWORD(v81[53].m_pSimObject) = 3;
      ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD))this->m_pTSPPC.m_pSimComponent->vfptr[14].__vecDelDtor)(
        this->m_pTSPPC.m_pSimComponent,
        22i64,
        0i64);
    }
    goto LABEL_143;
  }
  CurrentGameCamera = UFG::GetCurrentGameCamera();
  v83 = CurrentGameCamera && BYTE5(CurrentGameCamera[47].mPrev);
  v84 = this->m_eSoftLockType;
  if ( v84 != eSOFT_LOCK_ABSOLUTE && (!v121 || !v8 || !m_pTransformNodeComponent || v83) )
    goto LABEL_142;
  if ( v84 != eSOFT_LOCK_RELATIVE_LOCAL )
  {
    if ( v84 != eSOFT_LOCK_RELATIVE_LOCAL_ORIENTED_TO_ORIGIN )
      goto LABEL_143;
    v85 = UFG::AimingPlayerComponent::ms_fSoftLockCapsuleExpansionRatio * this->m_fFocusTargetRadius;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v86 = (__m128)LODWORD(this->m_vFreeAimOrigin.x);
    v87 = (__m128)LODWORD(this->m_vFreeAimOrigin.y);
    v86.m128_f32[0] = v86.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.x;
    v87.m128_f32[0] = v87.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y;
    v88 = v87;
    v88.m128_f32[0] = (float)(v87.m128_f32[0] * v87.m128_f32[0]) + (float)(v86.m128_f32[0] * v86.m128_f32[0]);
    if ( v88.m128_f32[0] == 0.0 )
    {
      v89 = 0i64;
    }
    else
    {
      v89 = (__m128)(unsigned int)FLOAT_1_0;
      v89.m128_f32[0] = 1.0 / _mm_sqrt_ps(v88).m128_f32[0];
    }
    v86.m128_f32[0] = v86.m128_f32[0] * v89.m128_f32[0];
    v90 = v87.m128_f32[0] * v89.m128_f32[0];
    v89.m128_f32[0] = v89.m128_f32[0] * 0.0;
    v91 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v91.m128_f32[0] = (float)((float)(v91.m128_f32[0] * v91.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    v92 = v91.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v91).m128_f32[0];
    v93 = v92;
    v94 = v92;
    v95 = v92 * UFG::qVector3::msDirUp.z;
    v96 = v94 * UFG::qVector3::msDirUp.x;
    v97 = v93 * UFG::qVector3::msDirUp.y;
    v100 = v86;
    v100.m128_f32[0] = v86.m128_f32[0] * v95;
    v98 = (float)(v89.m128_f32[0] * v97) - (float)(v90 * v95);
    v99 = v90 * v96;
    v100.m128_f32[0] = v100.m128_f32[0] - (float)(v89.m128_f32[0] * v96);
    v102 = v100;
    v101 = v99 - (float)(v86.m128_f32[0] * v97);
    v102.m128_f32[0] = (float)((float)(v100.m128_f32[0] * v100.m128_f32[0]) + (float)(v98 * v98)) + (float)(v101 * v101);
    v103 = v102.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v102).m128_f32[0];
    v104 = v101 * v103;
    v100.m128_f32[0] = v100.m128_f32[0] * v103;
    v105 = v98 * v103;
    v107 = v89;
    v106 = (float)(v104 * v90) - (float)(v89.m128_f32[0] * v100.m128_f32[0]);
    v107.m128_f32[0] = (float)(v89.m128_f32[0] * v105) - (float)(v104 * v86.m128_f32[0]);
    v109 = v107;
    v108 = (float)(v100.m128_f32[0] * v86.m128_f32[0]) - (float)(v90 * v105);
    v109.m128_f32[0] = (float)((float)(v107.m128_f32[0] * v107.m128_f32[0]) + (float)(v106 * v106))
                     + (float)(v108 * v108);
    v110 = v109.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v109).m128_f32[0];
    v111 = this->m_vSoftLockOffset.x;
    v112 = this->m_vSoftLockOffset.y;
    v113 = this->m_vSoftLockOffset.z;
    v114 = (float)((float)((float)(v105 * v112) + (float)(v86.m128_f32[0] * v111)) + (float)((float)(v106 * v110) * v113))
         + m_pTransformNodeComponent->mWorldTransform.v3.x;
    v100.m128_f32[0] = (float)((float)((float)(v100.m128_f32[0] * v112) + (float)(v90 * v111))
                             + (float)((float)(v107.m128_f32[0] * v110) * v113))
                     + m_pTransformNodeComponent->mWorldTransform.v3.y;
    v115 = (float)((float)((float)(v104 * v112) + (float)(v89.m128_f32[0] * v111)) + (float)((float)(v108 * v110) * v113))
         + m_pTransformNodeComponent->mWorldTransform.v3.z;
    result.x = v114;
    LODWORD(result.y) = v100.m128_i32[0];
    result.z = v115;
    UFG::qNearestSegPoint(&vTargetNormalAimPosition, &this->m_vFocusTargetSegA, &this->m_vFocusTargetSegB, &result);
    v100.m128_f32[0] = (float)((float)((float)(v100.m128_f32[0] - vTargetNormalAimPosition.y)
                                     * (float)(v100.m128_f32[0] - vTargetNormalAimPosition.y))
                             + (float)((float)(v114 - vTargetNormalAimPosition.x)
                                     * (float)(v114 - vTargetNormalAimPosition.x)))
                     + (float)((float)(v115 - vTargetNormalAimPosition.z) * (float)(v115 - vTargetNormalAimPosition.z));
    if ( _mm_sqrt_ps(v100).m128_f32[0] <= v85 )
      goto LABEL_143;
    goto LABEL_141;
  }
  if ( !this->m_bFocusTargetProbed )
  {
LABEL_141:
    v116 = this->m_pTSPPC.m_pSimComponent;
    *(_DWORD *)(&v116[53].m_SimObjIndex + 1) = 3;
    LODWORD(v116[53].m_pSimObject) = 3;
    ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD))this->m_pTSPPC.m_pSimComponent->vfptr[14].__vecDelDtor)(
      this->m_pTSPPC.m_pSimComponent,
      22i64,
      0i64);
LABEL_142:
    this->m_eSoftLockType = eSOFT_LOCK_NONE;
  }
LABEL_143:
  this->m_bResetSoftLockOffset = 0;
}

// File Line: 1378
// RVA: 0x52FA40
float __fastcall UFG::AimingPlayerComponent::GetReticleSize(UFG::AimingPlayerComponent *this)
{
  float result; // xmm0_4
  __int64 v3; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r9
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx
  __int64 v10; // rax
  float *v11; // rdx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float m_fAccuracyUnclamped; // xmm1_4

  result = this->m_fOverrideReticleSize;
  if ( result < 0.0 )
  {
    v3 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
    if ( v3 )
    {
      m_pSimObject = this->m_pSimObject;
      if ( !m_pSimObject )
        goto LABEL_22;
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr >= size )
          {
LABEL_16:
            m_pComponent = 0i64;
          }
          else
          {
            v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                 || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v9 += 16i64;
              if ( vfptr >= size )
                goto LABEL_16;
            }
            m_pComponent = *(UFG::SimComponent **)v9;
          }
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent
        && (v10 = *((_QWORD *)&m_pComponent[11].m_SafePointerList.mNode.mPrev
                  + ((__int64)(int)gActionRequest_CoverPopoutBlind.m_EnumValue >> 6)),
            _bittest64(&v10, gActionRequest_CoverPopoutBlind.m_EnumValue & 0x3F)) )
      {
        return *(float *)(*(_QWORD *)(*(_QWORD *)(v3 + 176) + 8i64 * *(unsigned int *)(v3 + 172) + 8) + 36i64);
      }
      else
      {
LABEL_22:
        v11 = *(float **)(*(_QWORD *)(v3 + 176) + 8i64 * *(unsigned int *)(v3 + 172) + 8);
        if ( LODWORD(this->m_pTSPPC.m_pSimComponent[53].m_pSimObject) == 1 )
          v12 = v11[5];
        else
          v12 = v11[7];
        if ( LODWORD(this->m_pTSPPC.m_pSimComponent[53].m_pSimObject) == 1 )
          v13 = v11[6];
        else
          v13 = v11[8];
        m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyUnclamped;
        if ( m_fAccuracyUnclamped <= this->m_Accuracy.m_fAccuracyMinimum )
          m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMinimum;
        if ( m_fAccuracyUnclamped >= this->m_Accuracy.m_fAccuracyMaximum )
          m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMaximum;
        return (float)((float)(1.0 - m_fAccuracyUnclamped) * v13) + (float)(m_fAccuracyUnclamped * v12);
      }
    }
    else
    {
      return 0.0;
    }
  }
  return result;
}

// File Line: 1417
// RVA: 0x54D300
void __fastcall UFG::AimingPlayerComponent::SetFreeAimIntention(
        UFG::AimingPlayerComponent *this,
        UFG::qVector3 *vDirection)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = vDirection->y;
  z = vDirection->z;
  this->m_vFreeAimIntention.x = vDirection->x;
  this->m_vFreeAimIntention.y = y;
  this->m_vFreeAimIntention.z = z;
}

// File Line: 1431
// RVA: 0x56B850
void __fastcall UFG::AimingPlayerComponent::possiblyResetFreeAimIntention(UFG::AimingPlayerComponent *this)
{
  char v2; // bp
  unsigned int m_eSnapFreeAimIntentionToTarget; // r8d
  _DWORD *p_mFOVOffset; // rdi
  UFG::AimingPlayerComponent::eSoftLockTypeEnum m_eSoftLockType; // eax
  float x; // xmm8_4
  float y; // xmm9_4
  float z; // xmm7_4
  __int64 v9; // rsi
  UFG::TransformNodeComponent *v10; // rsi
  __int64 v11; // rsi
  UFG::TransformNodeComponent *v12; // rsi
  float v13; // xmm14_4
  float v14; // xmm15_4
  __m128 x_low; // xmm4
  __m128 y_low; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  float v19; // xmm5_4
  __m128 v20; // xmm2
  float v21; // xmm7_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm7_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm8_4
  float v28; // xmm7_4
  __m128 v29; // xmm9
  float v30; // xmm7_4
  __m128 v31; // xmm2
  float v32; // xmm1_4
  float v33; // xmm7_4
  float v34; // xmm9_4
  float v35; // xmm8_4
  float v36; // xmm11_4
  __m128 v37; // xmm12
  float v38; // xmm13_4
  __m128 v39; // xmm2
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm11_4
  float v44; // xmm12_4
  float v45; // xmm13_4
  float v46; // xmm1_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimObject *mNext; // rcx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  int v56; // xmm2_4
  float v57; // xmm2_4
  float v58; // xmm4_4
  __m128 v59; // xmm5
  float v60; // xmm6_4
  __m128 v61; // xmm3
  UFG::BaseCameraComponent *v62; // rcx
  float v63; // xmm5_4
  float v64; // xmm3_4
  float v65; // xmm4_4
  float v66; // xmm2_4
  float v67; // xmm6_4
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+20h] [rbp-B8h] BYREF
  float v69; // [rsp+E0h] [rbp+8h]

  v2 = 0;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  m_eSnapFreeAimIntentionToTarget = this->m_eSnapFreeAimIntentionToTarget;
  p_mFOVOffset = 0i64;
  if ( m_eSnapFreeAimIntentionToTarget )
  {
    UFG::AimingBaseComponent::GetTargetNormalAimPosition(
      this,
      &vTargetNormalAimPosition,
      m_eSnapFreeAimIntentionToTarget,
      0i64);
    this->m_eSnapFreeAimIntentionToTarget = eTARGET_TYPE_INVALID;
    v2 = 1;
  }
  m_eSoftLockType = this->m_eSoftLockType;
  switch ( m_eSoftLockType )
  {
    case eSOFT_LOCK_ABSOLUTE:
      x = this->m_vSoftLockOffset.x;
      y = this->m_vSoftLockOffset.y;
      z = this->m_vSoftLockOffset.z;
      goto LABEL_27;
    case eSOFT_LOCK_RELATIVE_LOCAL:
      v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                     + *(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                     + 40);
      if ( v9 )
      {
        v10 = *(UFG::TransformNodeComponent **)(v9 + 88);
        if ( v10 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v10);
          x = (float)((float)((float)(this->m_vSoftLockOffset.y * v10->mWorldTransform.v1.x)
                            + (float)(this->m_vSoftLockOffset.x * v10->mWorldTransform.v0.x))
                    + (float)(this->m_vSoftLockOffset.z * v10->mWorldTransform.v2.x))
            + v10->mWorldTransform.v3.x;
          y = (float)((float)((float)(this->m_vSoftLockOffset.y * v10->mWorldTransform.v1.y)
                            + (float)(this->m_vSoftLockOffset.x * v10->mWorldTransform.v0.y))
                    + (float)(this->m_vSoftLockOffset.z * v10->mWorldTransform.v2.y))
            + v10->mWorldTransform.v3.y;
          z = (float)((float)((float)(this->m_vSoftLockOffset.y * v10->mWorldTransform.v1.z)
                            + (float)(this->m_vSoftLockOffset.x * v10->mWorldTransform.v0.z))
                    + (float)(this->m_vSoftLockOffset.z * v10->mWorldTransform.v2.z))
            + v10->mWorldTransform.v3.z;
          goto LABEL_27;
        }
      }
      break;
    case eSOFT_LOCK_RELATIVE_LOCAL_ORIENTED_TO_ORIGIN:
      v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                      + *(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                      + 40);
      if ( v11 )
      {
        v12 = *(UFG::TransformNodeComponent **)(v11 + 88);
        if ( v12 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v12);
          v13 = v12->mWorldTransform.v3.x;
          v14 = v12->mWorldTransform.v3.y;
          v69 = v12->mWorldTransform.v3.z;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent);
          x_low = (__m128)LODWORD(this->m_vFreeAimOrigin.x);
          y_low = (__m128)LODWORD(this->m_vFreeAimOrigin.y);
          x_low.m128_f32[0] = x_low.m128_f32[0] - v13;
          y_low.m128_f32[0] = y_low.m128_f32[0] - v14;
          v17 = y_low;
          v17.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                          + (float)(x_low.m128_f32[0] * x_low.m128_f32[0]);
          if ( v17.m128_f32[0] == 0.0 )
          {
            v18 = 0i64;
          }
          else
          {
            v18 = (__m128)(unsigned int)FLOAT_1_0;
            v18.m128_f32[0] = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
          }
          x_low.m128_f32[0] = x_low.m128_f32[0] * v18.m128_f32[0];
          v19 = y_low.m128_f32[0] * v18.m128_f32[0];
          v18.m128_f32[0] = v18.m128_f32[0] * 0.0;
          v20 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( v20.m128_f32[0] == 0.0 )
            v21 = 0.0;
          else
            v21 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
          v22 = v21;
          v23 = v21;
          v24 = v21 * UFG::qVector3::msDirUp.z;
          v25 = v23 * UFG::qVector3::msDirUp.x;
          v26 = v22 * UFG::qVector3::msDirUp.y;
          v29 = x_low;
          v29.m128_f32[0] = x_low.m128_f32[0] * v24;
          v27 = (float)(v18.m128_f32[0] * v26) - (float)(v19 * v24);
          v28 = v19 * v25;
          v29.m128_f32[0] = v29.m128_f32[0] - (float)(v18.m128_f32[0] * v25);
          v31 = v29;
          v30 = v28 - (float)(x_low.m128_f32[0] * v26);
          v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v27 * v27))
                          + (float)(v30 * v30);
          if ( v31.m128_f32[0] == 0.0 )
            v32 = 0.0;
          else
            v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
          v33 = v30 * v32;
          v34 = v29.m128_f32[0] * v32;
          v35 = v27 * v32;
          v37 = v18;
          v36 = (float)(v33 * v19) - (float)(v18.m128_f32[0] * v34);
          v37.m128_f32[0] = (float)(v18.m128_f32[0] * v35) - (float)(v33 * x_low.m128_f32[0]);
          v39 = v37;
          v38 = (float)(v34 * x_low.m128_f32[0]) - (float)(v19 * v35);
          v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v36 * v36))
                          + (float)(v38 * v38);
          if ( v39.m128_f32[0] == 0.0 )
            v40 = 0.0;
          else
            v40 = 1.0 / _mm_sqrt_ps(v39).m128_f32[0];
          v41 = this->m_vSoftLockOffset.y;
          v42 = this->m_vSoftLockOffset.z;
          v43 = v36 * v40;
          v44 = v37.m128_f32[0] * v40;
          v45 = v38 * v40;
          v46 = this->m_vSoftLockOffset.x;
          x = (float)((float)((float)(v35 * v41) + (float)(x_low.m128_f32[0] * v46)) + (float)(v43 * v42)) + v13;
          z = (float)((float)((float)(v33 * v41) + (float)(v18.m128_f32[0] * v46)) + (float)(v45 * v42)) + v69;
          y = (float)((float)((float)(v34 * v41) + (float)(v19 * v46)) + (float)(v44 * v42)) + v14;
LABEL_27:
          if ( s_iNumIterations > 0 )
          {
            do
            {
              v47 = x - this->m_vFreeAimOrigin.x;
              v48 = y - this->m_vFreeAimOrigin.y;
              v49 = z - this->m_vFreeAimOrigin.z;
              v50 = (float)((float)(v48 * v48) + (float)(v47 * v47)) + (float)(v49 * v49);
              if ( v50 == 0.0 )
                v51 = 0.0;
              else
                v51 = 1.0 / fsqrt(v50);
              this->m_vFreeAimIntention.x = v47 * v51;
              this->m_vFreeAimIntention.y = v48 * v51;
              this->m_vFreeAimIntention.z = v49 * v51;
              UFG::AimingPlayerComponent::updateFreeAimOrigin(this, 0.0);
              LODWORD(p_mFOVOffset) = (_DWORD)p_mFOVOffset + 1;
            }
            while ( (int)p_mFOVOffset < s_iNumIterations );
          }
          return;
        }
      }
      break;
  }
  if ( v2 )
  {
    z = vTargetNormalAimPosition.z;
    y = vTargetNormalAimPosition.y;
    x = vTargetNormalAimPosition.x;
    goto LABEL_27;
  }
  this->m_eSoftLockType = eSOFT_LOCK_NONE;
  if ( !this->m_bAimingControlsCamera )
  {
    if ( this->m_CharacterOccupantComponent.m_pSimComponent
      && (m_pSimComponent = this->m_CharacterOccupantComponent.m_pSimComponent,
          m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev)
      && (mNext = (UFG::SimObject *)m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev[2].mNext) != 0i64
      && mNext->m_pTransformNodeComponent
      && !UFG::SimObjectUtility::IsBoat(mNext) )
    {
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mCamera = &mCurrentCamera->mCamera;
      else
        p_mCamera = 0i64;
      v56 = LODWORD(p_mCamera->mTransformation.v2.y) ^ _xmm[0];
      LODWORD(this->m_vFreeAimIntention.x) = LODWORD(p_mCamera->mTransformation.v2.x) ^ _xmm[0];
      LODWORD(this->m_vFreeAimIntention.y) = v56;
      v57 = 0.0;
      this->m_vFreeAimIntention.z = 0.0;
      v58 = this->m_vFreeAimIntention.y;
      v59 = (__m128)LODWORD(this->m_vFreeAimIntention.x);
      v60 = this->m_vFreeAimIntention.z;
      v61 = v59;
      v61.m128_f32[0] = (float)((float)(v59.m128_f32[0] * v59.m128_f32[0]) + (float)(v58 * v58)) + (float)(v60 * v60);
      if ( v61.m128_f32[0] != 0.0 )
        v57 = 1.0 / _mm_sqrt_ps(v61).m128_f32[0];
      this->m_vFreeAimIntention.x = v57 * v59.m128_f32[0];
      this->m_vFreeAimIntention.y = v57 * v58;
      this->m_vFreeAimIntention.z = v57 * v60;
    }
    else
    {
      v62 = UFG::Director::Get()->mCurrentCamera;
      if ( v62 )
        p_mFOVOffset = (_DWORD *)&v62->mCamera.mFOVOffset;
      v63 = 0.0;
      LODWORD(v64) = p_mFOVOffset[41] ^ _xmm[0];
      LODWORD(v65) = p_mFOVOffset[42] ^ _xmm[0];
      LODWORD(v66) = p_mFOVOffset[40] ^ _xmm[0];
      this->m_vFreeAimIntention.x = v66;
      this->m_vFreeAimIntention.y = v64;
      this->m_vFreeAimIntention.z = v65;
      v67 = (float)((float)(v64 * v64) + (float)(v66 * v66)) + (float)(v65 * v65);
      if ( v67 != 0.0 )
        v63 = 1.0 / fsqrt(v67);
      this->m_vFreeAimIntention.x = v66 * v63;
      this->m_vFreeAimIntention.y = v64 * v63;
      this->m_vFreeAimIntention.z = v65 * v63;
    }
  }
}

// File Line: 1545
// RVA: 0x573390
void __fastcall UFG::AimingPlayerComponent::updateFreeAimInput(UFG::AimingPlayerComponent *this, float fDeltaS)
{
  UFG::SimComponent *m_pSimComponent; // rbp
  float v5; // xmm9_4
  UFG::LinearGraph<float> *v6; // r14
  float v7; // xmm14_4
  __int64 v8; // rax
  __int64 v9; // rdx
  float v10; // xmm12_4
  UFG::SimComponent *ComponentOfType; // rbx
  float v12; // xmm6_4
  float v13; // xmm7_4
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r9
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v19; // rdx
  __int64 v20; // rax
  char v21; // al
  float *p_m_TypeUID; // rsi
  UFG::GameStatTracker *v23; // rax
  float v24; // xmm6_4
  UFG::GameStatTracker *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm11_4
  float v28; // xmm10_4
  float Value; // xmm6_4
  float v30; // xmm0_4
  float m_fAxisXSpeed; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float m_fAxisYSpeed; // xmm0_4
  float v35; // xmm14_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  UFG::Controller *v38; // rax
  bool v39; // si
  UFG::GameStatTracker *v40; // rax
  bool Stat; // al
  UFG::SimComponent *v42; // rax
  UFG::SimObject *v43; // rcx
  __int16 v44; // dx
  unsigned int v45; // r8d
  unsigned int v46; // r9d
  __int64 v47; // rdx
  __int64 v48; // rcx
  __int64 v49; // rax
  __int64 v50; // rax
  float m_fFreeAimSpeedModifier; // xmm0_4
  int v52[4]; // [rsp+20h] [rbp-E8h] BYREF
  int v53[4]; // [rsp+30h] [rbp-D8h] BYREF
  UFG::LinearGraph<float> v54; // [rsp+40h] [rbp-C8h] BYREF

  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v52[0] = 0;
    v52[3] = 1065353216;
    v53[0] = 0;
    v5 = *(float *)&FLOAT_1_0;
    *(float *)&v52[1] = FLOAT_0_5;
    v54.fDomain = (const float *)v52;
    v53[3] = 1065353216;
    *(float *)&v52[2] = FLOAT_0_80000001;
    *(float *)&v53[2] = FLOAT_0_30000001;
    v54.tRange = (const float *)v53;
    v54.nData = 4;
    v6 = &v54;
    v7 = FLOAT_1_5;
    *(float *)&v53[1] = FLOAT_0_1;
    v8 = *(_QWORD *)&m_pSimComponent[8].m_TypeUID;
    if ( v8 )
    {
      v9 = *(_QWORD *)(*(_QWORD *)(v8 + 176) + 8i64 * *(unsigned int *)(v8 + 172) + 8);
      v7 = *(float *)(v9 + 280);
      v6 = (UFG::LinearGraph<float> *)(v9 + 376);
    }
    v10 = FLOAT_N1_0;
    ComponentOfType = 0i64;
    v12 = 0.0;
    v13 = 0.0;
    if ( BYTE3(m_pSimComponent[52].m_BoundComponentHandles.mNode.mPrev) )
    {
      m_pSimObject = this->m_pSimObject;
      if ( !m_pSimObject )
        goto LABEL_24;
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr >= size )
          {
LABEL_18:
            m_pComponent = 0i64;
          }
          else
          {
            v19 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                 || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v19 += 16i64;
              if ( vfptr >= size )
                goto LABEL_18;
            }
            m_pComponent = *(UFG::SimComponent **)v19;
          }
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent
        && (v20 = *((_QWORD *)&m_pComponent[11].m_SafePointerList.mNode.mPrev
                  + ((__int64)(int)gActionRequest_CameraZoom.m_EnumValue >> 6)),
            _bittest64(&v20, gActionRequest_CameraZoom.m_EnumValue & 0x3F)) )
      {
        v21 = 1;
      }
      else
      {
LABEL_24:
        v21 = 0;
      }
      p_m_TypeUID = (float *)&m_pSimComponent[53].m_TypeUID;
      if ( LODWORD(m_pSimComponent[53].m_pSimObject) != 4 )
        p_m_TypeUID = (float *)&m_pSimComponent[53].m_SafePointerList;
      if ( v21 || (v23 = UFG::GameStatTracker::Instance(), !UFG::GameStatTracker::GetStat(v23, XAxisInverted)) )
        v24 = *(float *)&FLOAT_1_0;
      else
        v24 = FLOAT_N1_0;
      LODWORD(v12) = COERCE_UNSIGNED_INT(v24 * *p_m_TypeUID) ^ _xmm[0];
      v25 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v25, YAxisInverted) )
        v13 = -1.0 * p_m_TypeUID[1];
      else
        v13 = 1.0 * p_m_TypeUID[1];
    }
    else
    {
      *(_QWORD *)&this->m_fAxisXSpeed = 0i64;
      *(_QWORD *)&this->m_fDampenedAxisXSpeed = 0i64;
    }
    if ( BYTE4(m_pSimComponent[53].vfptr) )
    {
      this->m_fDampenedAxisXSpeed = UFG::AimingPlayerComponent::ms_fMouseSensitivityH * v12;
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
      Value = UFG::LinearGraph<float>::GetValue(v6, COERCE_FLOAT(LODWORD(v12) & _xmm));
      v30 = UFG::LinearGraph<float>::GetValue(v6, COERCE_FLOAT(LODWORD(v13) & _xmm));
      m_fAxisXSpeed = this->m_fAxisXSpeed;
      v32 = v30;
      if ( m_fAxisXSpeed <= 0.0 )
      {
        if ( m_fAxisXSpeed >= 0.0 )
          v33 = 0.0;
        else
          v33 = FLOAT_N1_0;
      }
      else
      {
        v33 = *(float *)&FLOAT_1_0;
      }
      if ( v27 != v33 )
        this->m_fAxisXSpeed = 0.0;
      m_fAxisYSpeed = this->m_fAxisYSpeed;
      if ( m_fAxisYSpeed <= 0.0 )
      {
        if ( m_fAxisYSpeed >= 0.0 )
          v10 = 0.0;
      }
      else
      {
        v10 = *(float *)&FLOAT_1_0;
      }
      if ( v28 != v10 )
        this->m_fAxisYSpeed = 0.0;
      v35 = v7 * fDeltaS;
      v36 = COERCE_FLOAT(LODWORD(this->m_fAxisXSpeed) & _xmm) + v35;
      if ( v36 >= Value )
        v36 = Value;
      this->m_fAxisXSpeed = v36 * v27;
      v37 = COERCE_FLOAT(LODWORD(this->m_fAxisYSpeed) & _xmm) + v35;
      if ( v37 >= v32 )
        v37 = v32;
      this->m_fAxisYSpeed = v37 * v28;
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
      Stat = UFG::GameStatTracker::GetStat(v40, AimSoftLockEnabled);
      if ( UFG::AimingPlayerComponent::ms_bFreeAimSpeedModifierEnabled
        && LOBYTE(m_pSimComponent[52].m_BoundComponentHandles.mNode.mNext)
        && !this->m_bPreventFreeAimSpeedModifier
        && !this->m_bCameraZoomMode
        && !v39
        && Stat
        && (float)(UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierCapsuleExpansionRatio * this->m_fFocusTargetRadius) >= this->m_fFocusTargetDistanceSeg )
      {
        v42 = this->m_CharacterOccupantComponent.m_pSimComponent;
        if ( v42 && v42[1].m_BoundComponentHandles.mNode.mPrev && v42[1].m_BoundComponentHandles.mNode.mPrev[2].mNext )
        {
          v5 = UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierDriving;
        }
        else
        {
          v43 = this->m_pSimObject;
          if ( !v43 )
            goto LABEL_101;
          v44 = v43->m_Flags;
          if ( (v44 & 0x4000) != 0 )
          {
            ComponentOfType = v43->m_Components.p[7].m_pComponent;
          }
          else if ( v44 >= 0 )
          {
            if ( (v44 & 0x2000) != 0 )
            {
              ComponentOfType = v43->m_Components.p[6].m_pComponent;
            }
            else if ( (v44 & 0x1000) != 0 )
            {
              v45 = (unsigned int)v43[1].vfptr;
              v46 = v43->m_Components.size;
              if ( v45 < v46 )
              {
                v47 = (__int64)&v43->m_Components.p[v45];
                while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                     || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v45;
                  v47 += 16i64;
                  if ( v45 >= v46 )
                    goto LABEL_96;
                }
                ComponentOfType = *(UFG::SimComponent **)v47;
              }
            }
            else
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(v43, UFG::ActionTreeComponent::_TypeUID);
            }
          }
          else
          {
            ComponentOfType = v43->m_Components.p[7].m_pComponent;
          }
LABEL_96:
          if ( ComponentOfType
            && ((v48 = *((_QWORD *)&ComponentOfType[11].m_SafePointerList.mNode.mPrev
                       + ((__int64)(int)gActionRequest_Walk.m_EnumValue >> 6)),
                 _bittest64(&v48, gActionRequest_Walk.m_EnumValue & 0x3F))
             || (v49 = *((_QWORD *)&ComponentOfType[11].m_SafePointerList.mNode.mPrev
                       + ((__int64)(int)gActionRequest_Jog.m_EnumValue >> 6)),
                 _bittest64(&v49, gActionRequest_Jog.m_EnumValue & 0x3F))
             || (v50 = *((_QWORD *)&ComponentOfType[11].m_SafePointerList.mNode.mPrev
                       + ((__int64)(int)gActionRequest_Sprint.m_EnumValue >> 6)),
                 _bittest64(&v50, gActionRequest_Sprint.m_EnumValue & 0x3F))) )
          {
            v5 = UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierMoving;
          }
          else
          {
LABEL_101:
            v5 = UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierIdle;
          }
        }
      }
      UFG::qApproach(
        &this->m_fFreeAimSpeedModifier,
        v5,
        UFG::AimingPlayerComponent::ms_fFreeAimSpeedModifierBlendRate,
        fDeltaS);
      m_fFreeAimSpeedModifier = this->m_fFreeAimSpeedModifier;
      v26 = m_fFreeAimSpeedModifier * this->m_fAxisYSpeed;
      this->m_fDampenedAxisXSpeed = m_fFreeAimSpeedModifier * this->m_fAxisXSpeed;
    }
    this->m_fDampenedAxisYSpeed = v26;
  }
}

// File Line: 1708
// RVA: 0x573A90
void __fastcall UFG::AimingPlayerComponent::updateFreeAimIntention(UFG::AimingPlayerComponent *this, float fDeltaS)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v5; // rax
  float v6; // xmm6_4
  float v7; // xmm10_4
  __int64 v8; // r8
  float *CurrentGameCamera; // rsi
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  _DWORD *p_mFOVOffset; // rbp
  UFG::BaseCameraComponent *v12; // rbx
  UFG::BaseCameraComponent *v13; // r14
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm9_4
  UFG::GameStatTracker *v17; // rax
  float v18; // xmm12_4
  UFG::GameStatTracker *v19; // rax
  float Stat; // xmm0_4
  __m128 x_low; // xmm2
  float v22; // xmm6_4
  float v23; // xmm8_4
  float v24; // xmm0_4
  float v25; // xmm8_4
  float v26; // xmm1_4
  double v27; // xmm0_8
  float x; // xmm1_4
  float y; // xmm2_4
  double v30; // xmm7_8
  UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> **p_mNext; // rcx
  float v32; // xmm8_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  UFG::SimComponent *v35; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rbx
  UFG::TransformNodeComponent *v37; // rbx
  float v38; // xmm10_4
  float v39; // xmm6_4
  float v40; // xmm0_4
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  int v43; // xmm1_4
  int v44; // xmm0_4

  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v5 = *(_QWORD *)&m_pSimComponent[8].m_TypeUID;
    v6 = UFG::AimingPlayerComponent::default_fAimYawPerS;
    v7 = UFG::AimingPlayerComponent::default_fAimPitchPerS;
    if ( v5 )
    {
      v8 = *(_QWORD *)(*(_QWORD *)(v5 + 176) + 8i64 * *(unsigned int *)(v5 + 172) + 8);
      v6 = *(float *)(v8 + 272);
      v7 = *(float *)(v8 + 276);
    }
    CurrentGameCamera = (float *)UFG::GetCurrentGameCamera();
    CurrentBaseCamera = UFG::GetCurrentBaseCamera();
    p_mFOVOffset = 0i64;
    v12 = CurrentBaseCamera;
    if ( !CurrentBaseCamera
      || (v13 = CurrentBaseCamera,
          !UFG::SimComponent::IsType(CurrentBaseCamera, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID)) )
    {
      v13 = 0i64;
    }
    if ( !v12 || !UFG::SimComponent::IsType(v12, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
      v12 = 0i64;
    if ( CurrentGameCamera )
    {
      v15 = (*(float (__fastcall **)(float *))(*(_QWORD *)CurrentGameCamera + 152i64))(CurrentGameCamera);
      v14 = tanf(v15 * 0.5) * 1.8;
    }
    else
    {
      v14 = *(float *)&FLOAT_1_0;
    }
    v16 = fDeltaS;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      v16 = FLOAT_0_011111111;
    v17 = UFG::GameStatTracker::Instance();
    v18 = (float)((float)((float)((float)(UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedYawMax
                                        - UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedYawMin)
                                * UFG::GameStatTracker::GetStat(v17, AimSpeedYaw))
                        + UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedYawMin)
                * (float)((float)(v14 * this->m_fDampenedAxisXSpeed) * v6))
        * v16;
    v19 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v19, AimSpeedPitch);
    x_low = (__m128)LODWORD(this->m_vFreeAimIntention.x);
    v22 = Stat;
    x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                      + (float)(this->m_vFreeAimIntention.y * this->m_vFreeAimIntention.y);
    v23 = atan2f(this->m_vFreeAimIntention.z, _mm_sqrt_ps(x_low).m128_f32[0]);
    v24 = UFG::AimingPlayerComponent::ms_fFreeAimLatitudeMin;
    v25 = v23
        + (float)((float)((float)((float)((float)(UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedPitchMax
                                                - UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedPitchMin)
                                        * v22)
                                + UFG::AimingPlayerComponent::ms_fOptionsFactorSpeedPitchMin)
                        * (float)((float)(v14 * this->m_fDampenedAxisYSpeed) * v7))
                * v16);
    v26 = UFG::AimingPlayerComponent::ms_fFreeAimLatitudeMax;
    if ( v13 )
    {
      v24 = *(float *)&v13[4].m_SafePointerList.mNode.mNext;
      v26 = *((float *)&v13[4].m_SafePointerList.mNode.mNext + 1);
    }
    else if ( v12 )
    {
      LODWORD(v24) = LODWORD(v12[10].mCamera.mTransformation.v2.y) ^ _xmm[0];
      LODWORD(v26) = LODWORD(v12[10].mCamera.mTransformation.v2.x) ^ _xmm[0];
    }
    if ( v25 <= v24 )
      v25 = v24;
    if ( v25 >= v26 )
      v25 = v26;
    *(_QWORD *)&v27 = LODWORD(this->m_vFreeAimIntention.y);
    *(float *)&v27 = atan2f(*(float *)&v27, this->m_vFreeAimIntention.x);
    x = UFG::qVector2::msZero.x;
    y = UFG::qVector2::msZero.y;
    HIDWORD(v30) = HIDWORD(v27);
    if ( CurrentGameCamera )
    {
      x = CurrentGameCamera[280];
      y = CurrentGameCamera[281];
    }
    p_mNext = &this->m_AimingFreeAimConeClampTaskList.mNode.mPrev[-3].mNext;
    v32 = v25 + (float)((float)(y * 3.1415927) * 0.0055555557);
    *(float *)&v30 = (float)(*(float *)&v27 + v18) + (float)((float)(x * 3.1415927) * 0.0055555557);
    if ( p_mNext == (UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> **)&this->m_vSoftLockOffset )
      v33 = FLOAT_3_1415927;
    else
      v33 = *(float *)&p_mNext[3][3].mNext;
    if ( v33 < this->m_fInterpolatedFreeAimConeClamp )
      UFG::qApproach(
        &this->m_fInterpolatedFreeAimConeClamp,
        v33,
        UFG::AimingPlayerComponent::ms_fFreeAimConeClampRate,
        fDeltaS);
    else
      this->m_fInterpolatedFreeAimConeClamp = v33;
    v34 = this->m_fInterpolatedFreeAimConeClamp - 3.1415927;
    if ( v34 < 0.0 )
      LODWORD(v34) ^= _xmm[0];
    if ( v34 >= 0.001 )
    {
      v35 = this->m_CharacterOccupantComponent.m_pSimComponent;
      if ( !v35
        || !v35[1].m_BoundComponentHandles.mNode.mPrev
        || (mNext = v35[1].m_BoundComponentHandles.mNode.mPrev[2].mNext) == 0i64
        || (v37 = (UFG::TransformNodeComponent *)mNext[5].mNext) == 0i64 )
      {
        v37 = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v37);
      v38 = atan2f(v37->mWorldTransform.v0.y, v37->mWorldTransform.v0.x);
      *(float *)&v30 = (float)(*(float *)&v30 - v38) + 3.1415927;
      *(float *)&v27 = UFG::qSignedMod(v30, 6.2831855) - 3.1415927;
      if ( *(float *)&v27 <= COERCE_FLOAT(LODWORD(this->m_fInterpolatedFreeAimConeClamp) ^ _xmm[0]) )
        *(_QWORD *)&v27 = LODWORD(this->m_fInterpolatedFreeAimConeClamp) ^ (unsigned __int64)(unsigned int)_xmm[0];
      if ( *(float *)&v27 >= this->m_fInterpolatedFreeAimConeClamp )
        *(_QWORD *)&v27 = LODWORD(this->m_fInterpolatedFreeAimConeClamp);
      *(float *)&v27 = *(float *)&v27 + v38;
      LODWORD(v30) = UFG::qSignedMod(v27, 6.2831855);
    }
    v39 = cosf(v32);
    this->m_vFreeAimIntention.x = cosf(*(float *)&v30) * v39;
    this->m_vFreeAimIntention.y = sinf(*(float *)&v30) * v39;
    v40 = sinf(v32);
    m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
    this->m_vFreeAimIntention.z = v40;
    if ( UFG::IsAnyLocalPlayer(m_pSimObject) && !UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
    {
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mFOVOffset = (_DWORD *)&mCurrentCamera->mCamera.mFOVOffset;
      v43 = p_mFOVOffset[41] ^ _xmm[0];
      v44 = p_mFOVOffset[42] ^ _xmm[0];
      LODWORD(this->m_vFreeAimIntention.x) = p_mFOVOffset[40] ^ _xmm[0];
      LODWORD(this->m_vFreeAimIntention.y) = v43;
      LODWORD(this->m_vFreeAimIntention.z) = v44;
    }
  }
}

// File Line: 1848
// RVA: 0x579340
void __fastcall UFG::AimingPlayerComponent::updateTargetDimensions(UFG::AimingPlayerComponent *this)
{
  UFG::SimObject *v2; // rcx
  __m128 y_low; // xmm2
  float v4; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qMatrix44 *v13; // [rsp+50h] [rbp+8h] BYREF

  v2 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                          + *(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_TypeUID
                          + 40);
  if ( v2 )
  {
    v13 = 0i64;
    UFG::SimObjectUtility::GetObjectCapsuleApproximation(
      v2,
      &v13,
      &this->m_vFocusTargetSegA,
      &this->m_vFocusTargetSegB,
      &this->m_fFocusTargetRadius);
    UFG::qNearestRaySeg(
      &this->m_vFreeAimOrigin,
      &this->m_vFreeAimIntention,
      &this->m_vFocusTargetSegA,
      &this->m_vFocusTargetSegB,
      &this->m_vFocusTargetClosestPos,
      &this->m_vFocusTargetSegClosestPos);
    y_low = (__m128)LODWORD(this->m_vFocusTargetClosestPos.y);
    v4 = this->m_vFocusTargetClosestPos.z - this->m_vFocusTargetSegClosestPos.z;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_vFocusTargetSegClosestPos.y)
                                      * (float)(y_low.m128_f32[0] - this->m_vFocusTargetSegClosestPos.y))
                              + (float)((float)(this->m_vFocusTargetClosestPos.x - this->m_vFocusTargetSegClosestPos.x)
                                      * (float)(this->m_vFocusTargetClosestPos.x - this->m_vFocusTargetSegClosestPos.x)))
                      + (float)(v4 * v4);
    LODWORD(this->m_fFocusTargetDistanceSeg) = _mm_sqrt_ps(y_low).m128_u32[0];
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    this->m_vFocusTargetSegA.x = UFG::qVector3::msZero.x;
    this->m_vFocusTargetSegA.y = y;
    this->m_vFocusTargetSegA.z = z;
    v7 = UFG::qVector3::msZero.y;
    v8 = UFG::qVector3::msZero.z;
    this->m_vFocusTargetSegB.x = UFG::qVector3::msZero.x;
    this->m_vFocusTargetSegB.y = v7;
    this->m_vFocusTargetSegB.z = v8;
    v9 = UFG::qVector3::msZero.y;
    v10 = UFG::qVector3::msZero.z;
    this->m_vFocusTargetClosestPos.x = UFG::qVector3::msZero.x;
    this->m_vFocusTargetClosestPos.y = v9;
    this->m_vFocusTargetClosestPos.z = v10;
    v11 = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
    this->m_vFocusTargetSegClosestPos.x = UFG::qVector3::msZero.x;
    this->m_vFocusTargetSegClosestPos.y = v11;
    this->m_vFocusTargetSegClosestPos.z = v12;
    this->m_fFocusTargetRadius = 0.0;
    this->m_fFocusTargetDistanceSeg = 3.4028235e38;
  }
}

// File Line: 1885
// RVA: 0x5683C0
float __fastcall UFG::AimingPlayerComponent::getDistanceFromFreeAimOriginToStartRaycast(
        UFG::AimingPlayerComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  float Radius; // xmm9_4
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v8; // rdx
  unsigned int v9; // r8d
  unsigned int v10; // r10d
  unsigned int v11; // r8d
  unsigned int v12; // r10d
  UFG::TransformNodeComponent *m_pSimComponent; // rdi
  float x; // xmm6_4
  __m128 y_low; // xmm7
  float v16; // xmm3_4
  __m128 v17; // xmm2
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float result; // xmm0_4
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+20h] [rbp-58h] BYREF

  m_pSimObject = this->m_pSimObject;
  Radius = FLOAT_0_60000002;
  if ( !m_pSimObject )
    goto LABEL_29;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterPhysicsComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
    goto LABEL_27;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v8 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v8 += 16i64;
        if ( vfptr >= size )
          goto LABEL_10;
      }
LABEL_11:
      m_pComponent = *(UFG::CharacterPhysicsComponent **)v8;
      goto LABEL_27;
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (__int64)&m_pSimObject->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
        {
          m_pComponent = 0i64;
          goto LABEL_27;
        }
      }
      goto LABEL_11;
    }
LABEL_10:
    m_pComponent = 0i64;
    goto LABEL_27;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      v8 = (__int64)&m_pSimObject->m_Components.p[v11];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v11;
        v8 += 16i64;
        if ( v11 >= v12 )
        {
          m_pComponent = 0i64;
          goto LABEL_27;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pSimObject,
                                                     UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_27:
  if ( m_pComponent )
    Radius = UFG::CharacterPhysicsComponent::GetRadius(m_pComponent);
LABEL_29:
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  x = this->m_vFreeAimIntention.x;
  y_low = (__m128)LODWORD(this->m_vFreeAimIntention.y);
  v16 = 0.0;
  v17 = y_low;
  v17.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
  if ( v17.m128_f32[0] != 0.0 )
    v16 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
  v18 = x * v16;
  v19 = y_low.m128_f32[0] * v16;
  v20 = (float)((float)((float)(m_pSimComponent->mWorldTransform.v3.y - this->m_vFreeAimOrigin.y) * v19)
              + (float)((float)(m_pSimComponent->mWorldTransform.v3.x - this->m_vFreeAimOrigin.x) * v18))
      + Radius;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, &vWeaponProjectileSpawnPosition);
  result = (float)((float)(vWeaponProjectileSpawnPosition.y - this->m_vFreeAimOrigin.y) * v19)
         + (float)((float)(vWeaponProjectileSpawnPosition.x - this->m_vFreeAimOrigin.x) * v18);
  if ( v20 > result )
    return v20;
  return result;
}

// File Line: 1926
// RVA: 0x533600
char __fastcall UFG::AimingPlayerComponent::GetWeaponProjectileSpawnPositionUnobscured(
        UFG::AimingPlayerComponent *this,
        UFG::qVector3 *vToPosition,
        UFG::qVector3 *vPositionReturn)
{
  float z; // xmm4_4
  float v7; // xmm8_4
  float y; // xmm5_4
  float v9; // xmm7_4
  __m128 x_low; // xmm6
  __m128 v11; // xmm2
  float v12; // xmm1_4
  float v13; // xmm8_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float m_fUnobscuredAimCheckDistance; // xmm3_4
  float m_fUnobscuredAimTargetPositionPadDistance; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  __int64 v20; // rcx
  __int64 v21; // rcx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v22; // rcx
  const char *TypeName; // rax
  bool v24; // di
  float m_fUnobscuredAimNewPositionPadDistance; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qReflectHandleBase v31; // [rsp+30h] [rbp-C8h] BYREF
  __int64 v32; // [rsp+58h] [rbp-A0h]
  UFG::RayCastData data; // [rsp+60h] [rbp-98h] BYREF

  v32 = -2i64;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, vPositionReturn);
  if ( !UFG::AimingPlayerComponent::ms_bEnableObscuredAimCheck || (*((_BYTE *)this + 848) & 1) == 0 )
    return 0;
  z = vPositionReturn->z;
  v7 = z - vToPosition->z;
  y = vPositionReturn->y;
  v9 = y - vToPosition->y;
  x_low = (__m128)LODWORD(vPositionReturn->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - vToPosition->x;
  v11 = x_low;
  v11.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v9 * v9)) + (float)(v7 * v7);
  v12 = v11.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  v13 = v7 * v12;
  v14 = v9 * v12;
  v15 = x_low.m128_f32[0] * v12;
  m_fUnobscuredAimCheckDistance = this->m_fUnobscuredAimCheckDistance;
  if ( (float)(m_fUnobscuredAimCheckDistance * m_fUnobscuredAimCheckDistance) > v11.m128_f32[0]
    || m_fUnobscuredAimCheckDistance <= 0.0 )
  {
    m_fUnobscuredAimTargetPositionPadDistance = this->m_fUnobscuredAimTargetPositionPadDistance;
    v18 = (float)(v14 * m_fUnobscuredAimTargetPositionPadDistance) + vToPosition->y;
    v19 = (float)(v13 * m_fUnobscuredAimTargetPositionPadDistance) + vToPosition->z;
    rayStart.x = (float)(v15 * m_fUnobscuredAimTargetPositionPadDistance) + vToPosition->x;
    rayStart.y = v18;
    rayStart.z = v19;
  }
  else
  {
    rayStart.x = vPositionReturn->x - (float)(v15 * m_fUnobscuredAimCheckDistance);
    rayStart.y = y - (float)(v14 * m_fUnobscuredAimCheckDistance);
    rayStart.z = z - (float)(v13 * m_fUnobscuredAimCheckDistance);
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
  UFG::RayCastData::Init(&data, &rayStart, vPositionReturn, 0x19u);
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
        if ( *(_QWORD *)(v21 + 40) && (*(_WORD *)(*(_QWORD *)(v21 + 40) + 76i64) & 0x4000) != 0 )
          return 0;
      }
    }
  }
  UFG::qReflectHandleBase::qReflectHandleBase(&v31);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v22);
  v31.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v31, v31.mTypeUID, data.mPhysicsObjectPropertyHandleUid);
  v24 = v31.mData && *(float *)&v31.mData[1].mBaseNode.mUID > 0.0;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v31);
  if ( v24 )
    return 0;
  m_fUnobscuredAimNewPositionPadDistance = this->m_fUnobscuredAimNewPositionPadDistance;
  v26 = *((float *)&data.mDebugName + 1) - (float)(v15 * m_fUnobscuredAimNewPositionPadDistance);
  v27 = *(float *)&data.mCollisionModelName.mUID - (float)(v14 * m_fUnobscuredAimNewPositionPadDistance);
  v28 = data.point.x - (float)(v13 * m_fUnobscuredAimNewPositionPadDistance);
  vPositionReturn->x = v26;
  vPositionReturn->y = v27;
  vPositionReturn->z = v28;
  return 1;
}

// File Line: 1996
// RVA: 0x5750C0
void __fastcall UFG::AimingPlayerComponent::updateFreeAimTargetPosition(UFG::AimingPlayerComponent *this)
{
  Render::DebugDrawContext *Context; // rsi
  __int64 v3; // r15
  UFG::qVector3 *p_m_vFreeAimIntention; // r13
  float x; // xmm2_4
  __m128 y_low; // xmm3
  __m128 v7; // xmm1
  float v8; // xmm8_4
  float DistanceFromFreeAimOriginToStartRaycast; // xmm9_4
  float v10; // xmm3_4
  int v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  UFG::qVector3 *p_m_vFreeAimTargetPosition; // r12
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  char v18; // di
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm12_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  __m128 mPrev_low; // xmm6
  __m128 v25; // xmm2
  float v26; // xmm11_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_FreeAimSimObject; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  int v35; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v36; // rcx
  const char *TypeName; // rax
  UFG::qVector3 *v38; // rax
  float v39; // xmm3_4
  float v40; // xmm2_4
  __int64 v41; // rcx
  __int64 v42; // rbx
  __int16 v43; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v45; // r8d
  unsigned int v46; // r10d
  __int64 v47; // rdi
  int v48; // edx
  __int16 v49; // cx
  UFG::SimComponent *v50; // rax
  unsigned int v51; // r8d
  unsigned int v52; // r10d
  __int64 v53; // rdi
  __int64 v54; // rdx
  unsigned int v55; // r8d
  unsigned int v56; // r10d
  unsigned int v57; // r8d
  unsigned int v58; // r10d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v59; // rcx
  __int16 v60; // cx
  UFG::SimComponent *v61; // rdx
  unsigned int v62; // r8d
  unsigned int v63; // r10d
  __int64 v64; // rdi
  __int64 v65; // rdx
  unsigned int v66; // r8d
  unsigned int v67; // r10d
  __int64 v68; // rax
  __int64 v69; // rcx
  __int16 v70; // cx
  unsigned int v71; // r8d
  unsigned int v72; // r10d
  __int64 v73; // rdi
  __int64 v74; // rdx
  UFG::SimComponent *v75; // rdi
  unsigned int v76; // r8d
  unsigned int v77; // r10d
  unsigned int v78; // r8d
  unsigned int v79; // r10d
  unsigned int v80; // r8d
  unsigned int v81; // r10d
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v82; // rcx
  const char *v83; // rax
  __int64 v84; // rdx
  float *v85; // rbx
  float v86; // xmm7_4
  __m128 v87; // xmm8
  float v88; // xmm6_4
  float v89; // xmm1_4
  __m128 v90; // xmm2
  float v91; // xmm0_4
  __m128 v92; // xmm2
  float v93; // xmm5_4
  float v94; // xmm6_4
  float v95; // xmm0_4
  float v96; // xmm3_4
  UFG::qVector3 v97; // [rsp+40h] [rbp-98h] BYREF
  float rayStart[2]; // [rsp+50h] [rbp-88h] BYREF
  __int64 rayStart_8; // [rsp+58h] [rbp-80h]
  UFG::qReflectHandleBase v100; // [rsp+60h] [rbp-78h] BYREF
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
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v118 = Context;
  v3 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_Flags + 30i64)
                 + *(_QWORD *)&this->m_pTSPPC.m_pSimComponent[1].m_TypeUID
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
  p_m_vFreeAimIntention = &this->m_vFreeAimIntention;
  x = this->m_vFreeAimIntention.x;
  y_low = (__m128)LODWORD(this->m_vFreeAimIntention.y);
  v7 = y_low;
  v7.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
  if ( v7.m128_f32[0] == 0.0 )
    v8 = 0.0;
  else
    v8 = 1.0 / _mm_sqrt_ps(v7).m128_f32[0];
  DistanceFromFreeAimOriginToStartRaycast = UFG::AimingPlayerComponent::getDistanceFromFreeAimOriginToStartRaycast(this);
  v10 = (float)((float)(this->m_vFreeAimIntention.y * (float)(v8 * y_low.m128_f32[0]))
              + (float)(p_m_vFreeAimIntention->x * (float)(v8 * x)))
      + (float)(this->m_vFreeAimIntention.z * (float)(v8 * 0.0));
  *(float *)&v11 = v10;
  if ( v10 < 0.0 )
    v11 = LODWORD(v10) ^ _xmm[0];
  if ( *(float *)&v11 >= 0.00000011920929 )
    DistanceFromFreeAimOriginToStartRaycast = DistanceFromFreeAimOriginToStartRaycast / v10;
  v12 = (float)(this->m_vFreeAimIntention.z * DistanceFromFreeAimOriginToStartRaycast) + this->m_vFreeAimOrigin.z;
  v13 = (float)(this->m_vFreeAimIntention.y * DistanceFromFreeAimOriginToStartRaycast) + this->m_vFreeAimOrigin.y;
  this->m_vFreeAimCastOrigin.x = (float)(p_m_vFreeAimIntention->x * DistanceFromFreeAimOriginToStartRaycast)
                               + this->m_vFreeAimOrigin.x;
  this->m_vFreeAimCastOrigin.y = v13;
  this->m_vFreeAimCastOrigin.z = v12;
  v14 = (float)(UFG::AimingPlayerComponent::ms_fFreeAimTargetRange * this->m_vFreeAimIntention.z)
      + this->m_vFreeAimOrigin.z;
  v15 = (float)(UFG::AimingPlayerComponent::ms_fFreeAimTargetRange * this->m_vFreeAimIntention.y)
      + this->m_vFreeAimOrigin.y;
  p_m_vFreeAimTargetPosition = &this->m_vFreeAimTargetPosition;
  this->m_vFreeAimTargetPosition.x = (float)(UFG::AimingPlayerComponent::ms_fFreeAimTargetRange
                                           * p_m_vFreeAimIntention->x)
                                   + this->m_vFreeAimOrigin.x;
  this->m_vFreeAimTargetPosition.y = v15;
  this->m_vFreeAimTargetPosition.z = v14;
  CurrentGameCamera = UFG::GetCurrentGameCamera();
  v18 = 0;
  v97 = UFG::qVector3::msDirFront;
  if ( s_bGameCameraModifiesFreeAim && CurrentGameCamera && BYTE5(CurrentGameCamera[47].mPrev) )
  {
    v19 = *((float *)&CurrentGameCamera[43].mPrev + 1);
    v20 = *(float *)&CurrentGameCamera[43].mNext;
    v21 = *((float *)&CurrentGameCamera[43].mNext + 1);
    mPrev_low = (__m128)LODWORD(CurrentGameCamera[44].mPrev);
    v22 = *(float *)&CurrentGameCamera[44].mNext - v21;
    v23 = *((float *)&CurrentGameCamera[44].mPrev + 1) - v20;
    mPrev_low.m128_f32[0] = mPrev_low.m128_f32[0] - v19;
    v25 = mPrev_low;
    v25.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] * mPrev_low.m128_f32[0]) + (float)(v23 * v23))
                    + (float)(v22 * v22);
    if ( v25.m128_f32[0] == 0.0 )
      v26 = 0.0;
    else
      v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
    v27 = v22 * v26;
    v28 = v23 * v26;
    v29 = mPrev_low.m128_f32[0] * v26;
    v97.x = v29;
    v97.y = v28;
    v97.z = v27;
    this->m_vFreeAimCastOrigin.x = v19 + (float)(v29 * DistanceFromFreeAimOriginToStartRaycast);
    this->m_vFreeAimCastOrigin.y = (float)(v28 * DistanceFromFreeAimOriginToStartRaycast) + v20;
    this->m_vFreeAimCastOrigin.z = (float)(v27 * DistanceFromFreeAimOriginToStartRaycast) + v21;
    v30 = (float)(v27 * UFG::AimingPlayerComponent::ms_fFreeAimTargetRange) + v21;
    v31 = (float)(v28 * UFG::AimingPlayerComponent::ms_fFreeAimTargetRange) + v20;
    p_m_vFreeAimTargetPosition->x = v19 + (float)(v29 * UFG::AimingPlayerComponent::ms_fFreeAimTargetRange);
    this->m_vFreeAimTargetPosition.y = v31;
    this->m_vFreeAimTargetPosition.z = v30;
    v18 = 1;
  }
  UFG::RayCastData::Init(
    (UFG::RayCastData *)&v100.mNext,
    &this->m_vFreeAimCastOrigin,
    &this->m_vFreeAimTargetPosition,
    0x19u);
  if ( s_bDrawRaycasts )
    Render::DebugDrawContext::DrawLine(
      Context,
      &this->m_vFreeAimCastOrigin,
      &this->m_vFreeAimTargetPosition,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64,
      0);
  *(_WORD *)&this->m_bFocusTargetProbed = 0;
  p_m_FreeAimSimObject = &this->m_FreeAimSimObject;
  if ( this->m_FreeAimSimObject.m_pPointer )
  {
    mPrev = p_m_FreeAimSimObject->mPrev;
    mNext = this->m_FreeAimSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_FreeAimSimObject->mPrev = p_m_FreeAimSimObject;
    this->m_FreeAimSimObject.mNext = &this->m_FreeAimSimObject;
  }
  this->m_FreeAimSimObject.m_pPointer = 0i64;
  v35 = 0;
  while ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, (UFG::RayCastData *)&v100.mNext) )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v100);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v36);
    v100.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v100, v100.mTypeUID, v117);
    if ( !rayStart_8 || *(float *)(rayStart_8 + 88) <= 0.69999999 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase(&v100);
      break;
    }
    v38 = &v97;
    if ( !v18 )
      v38 = &this->m_vFreeAimIntention;
    v39 = (float)(v38->z * 0.0099999998) + v113;
    v40 = (float)(v38->y * 0.0099999998) + v112;
    rayStart[0] = v111 + (float)(v38->x * 0.0099999998);
    rayStart[1] = v40;
    *(float *)&rayStart_8 = v39;
    UFG::RayCastData::Init(
      (UFG::RayCastData *)&v100.mNext,
      (UFG::qVector3 *)rayStart,
      &this->m_vFreeAimTargetPosition,
      0x19u);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v100);
    if ( (unsigned int)++v35 >= 3 )
      break;
  }
  if ( v115 )
  {
    if ( !v114 )
      goto LABEL_162;
    UFG::qReflectHandleBase::Init(
      &this->m_FreeAimPhysicsObjectProperties,
      this->m_FreeAimPhysicsObjectProperties.mTypeUID,
      v116);
    if ( !this->m_FreeAimPhysicsObjectProperties.mData )
      UFG::PhysicsPropertyManager::GetDefaultObjectProperties(&this->m_FreeAimPhysicsObjectProperties);
    v41 = *(_QWORD *)(v114 + 0x18);
    if ( !v41 )
      goto LABEL_162;
    v42 = *(_QWORD *)(v41 + 0x18);
    if ( v42 )
      v42 = *(_QWORD *)(v42 + 0x28);
    if ( !v42 )
      goto LABEL_162;
    v43 = *(_WORD *)(v42 + 76);
    if ( (v43 & 0x4000) != 0 )
    {
      ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v42 + 104) + 48i64);
    }
    else if ( v43 >= 0 )
    {
      if ( (v43 & 0x2000) != 0 )
      {
        ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v42 + 104) + 64i64);
      }
      else if ( (v43 & 0x1000) != 0 )
      {
        v45 = *(_DWORD *)(v42 + 128);
        v46 = *(_DWORD *)(v42 + 96);
        if ( v45 >= v46 )
        {
LABEL_50:
          ComponentOfType = 0i64;
        }
        else
        {
          v47 = *(_QWORD *)(v42 + 104);
          while ( (*(_DWORD *)(v47 + 16i64 * v45 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v47 + 16i64 * v45 + 8) & 0x1FFFFFF) != 0 )
          {
            if ( ++v45 >= v46 )
              goto LABEL_50;
          }
          ComponentOfType = *(UFG::SimComponent **)(v47 + 16i64 * v45);
        }
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)v42,
                            UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v42 + 104) + 48i64);
    }
    if ( ComponentOfType )
    {
      v48 = (int)ComponentOfType[1].m_SafePointerList.mNode.mNext;
      if ( v48 == 1 || v48 == 4 )
      {
        if ( !*(_QWORD *)(v42 + 88) )
          goto LABEL_162;
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->m_FreeAimSimObject,
          (UFG::SimComponent *)v42);
        if ( (UFG::SimObject *)v3 == this->m_FreeAimSimObject.m_pPointer )
        {
          this->m_bFocusTargetProbed = 1;
          goto LABEL_162;
        }
        v49 = *(_WORD *)(v42 + 76);
        if ( (v49 & 0x4000) != 0 )
        {
          v50 = *(UFG::SimComponent **)(*(_QWORD *)(v42 + 104) + 704i64);
LABEL_84:
          if ( v50 )
          {
            v59 = v50[1].m_BoundComponentHandles.mNode.mPrev
                ? v50[1].m_BoundComponentHandles.mNode.mPrev[2].mNext
                : 0i64;
            if ( v59 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v3 )
              this->m_bFocusTargetProbed = 1;
          }
          if ( this->m_bFocusTargetProbed )
            goto LABEL_167;
          if ( v3 )
          {
            v60 = *(_WORD *)(v3 + 76);
            if ( (v60 & 0x4000) != 0 )
            {
              v61 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 320i64);
              if ( v61
                && ((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v61->m_TypeUID) & 0xFE000000) == 0
                && (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) == 0 )
              {
LABEL_118:
                if ( v61 )
                {
                  v68 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v61[1].m_Flags + 31i64);
                  v69 = *(_QWORD *)&v61[1].m_TypeUID;
                  if ( *(_QWORD *)(v68 + v69 + 40) )
                  {
                    if ( *(_BYTE *)(v68 + v69 + 49) && *(_QWORD *)(v68 + v69 + 40) == v42 )
                      this->m_bFocusTargetProbed = 1;
                  }
                }
                goto LABEL_162;
              }
LABEL_96:
              v61 = 0i64;
              goto LABEL_118;
            }
            if ( v60 < 0 )
            {
              v61 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 320i64);
              if ( v61 && ((UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v61->m_TypeUID) & 0xFE000000) == 0 )
              {
                if ( (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
                  v61 = 0i64;
                goto LABEL_118;
              }
              goto LABEL_96;
            }
            if ( (v60 & 0x2000) != 0 )
            {
              v62 = *(_DWORD *)(v3 + 128);
              v63 = *(_DWORD *)(v3 + 96);
              if ( v62 >= v63 )
                goto LABEL_96;
              v64 = *(_QWORD *)(v3 + 104);
              while ( 1 )
              {
                v65 = 2i64 * v62;
                if ( (*(_DWORD *)(v64 + 16i64 * v62 + 8) & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                  && (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v64 + 16i64 * v62 + 8) & 0x1FFFFFF) == 0 )
                {
                  break;
                }
                if ( ++v62 >= v63 )
                  goto LABEL_96;
              }
            }
            else
            {
              if ( (v60 & 0x1000) == 0 )
              {
                v61 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)v3,
                        UFG::TargetingSystemPedBaseComponent::_TypeUID);
                goto LABEL_118;
              }
              v66 = *(_DWORD *)(v3 + 128);
              v67 = *(_DWORD *)(v3 + 96);
              if ( v66 >= v67 )
                goto LABEL_96;
              v64 = *(_QWORD *)(v3 + 104);
              while ( 1 )
              {
                v65 = 2i64 * v66;
                if ( (*(_DWORD *)(v64 + 16i64 * v66 + 8) & 0xFE000000) == (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
                  && (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v64 + 16i64 * v66 + 8) & 0x1FFFFFF) == 0 )
                {
                  break;
                }
                if ( ++v66 >= v67 )
                  goto LABEL_96;
              }
            }
            v61 = *(UFG::SimComponent **)(v64 + 8 * v65);
            goto LABEL_118;
          }
LABEL_162:
          if ( !this->m_bFocusTargetProbed )
          {
            if ( v3 )
            {
              v85 = *(float **)(v3 + 88);
              if ( v85 )
              {
                v86 = this->m_vFreeAimCastOrigin.x - v111;
                v87 = (__m128)LODWORD(this->m_vFreeAimCastOrigin.y);
                v87.m128_f32[0] = v87.m128_f32[0] - v112;
                v88 = this->m_vFreeAimCastOrigin.z - v113;
                UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v3 + 88));
                v89 = this->m_vFreeAimCastOrigin.x - v85[44];
                v90 = (__m128)LODWORD(this->m_vFreeAimCastOrigin.y);
                v91 = this->m_vFreeAimCastOrigin.z - v85[46];
                v90.m128_f32[0] = (float)((float)((float)(v90.m128_f32[0] - v85[45]) * (float)(v90.m128_f32[0] - v85[45]))
                                        + (float)(v89 * v89))
                                + (float)(v91 * v91);
                v87.m128_f32[0] = (float)((float)(v87.m128_f32[0] * v87.m128_f32[0]) + (float)(v86 * v86))
                                + (float)(v88 * v88);
                if ( _mm_sqrt_ps(v90).m128_f32[0] >= (float)(_mm_sqrt_ps(v87).m128_f32[0] + s_fExtraObstructionDistance) )
                  this->m_bFocusTargetObstructed = 1;
              }
            }
          }
LABEL_167:
          v92 = (__m128)LODWORD(this->m_vFreeAimCastOrigin.y);
          v93 = v112;
          v94 = v113;
          v92.m128_f32[0] = (float)((float)((float)(v92.m128_f32[0] - v112) * (float)(v92.m128_f32[0] - v112))
                                  + (float)((float)(this->m_vFreeAimCastOrigin.x - v111)
                                          * (float)(this->m_vFreeAimCastOrigin.x - v111)))
                          + (float)((float)(this->m_vFreeAimCastOrigin.z - v113)
                                  * (float)(this->m_vFreeAimCastOrigin.z - v113));
          if ( _mm_sqrt_ps(v92).m128_f32[0] >= s_fMinDistance )
          {
            p_m_vFreeAimTargetPosition->x = v111;
            this->m_vFreeAimTargetPosition.y = v93;
            this->m_vFreeAimTargetPosition.z = v94;
          }
          else
          {
            v95 = (float)(s_fMinDistance * this->m_vFreeAimIntention.y) + this->m_vFreeAimCastOrigin.y;
            v96 = (float)(s_fMinDistance * this->m_vFreeAimIntention.z) + this->m_vFreeAimCastOrigin.z;
            p_m_vFreeAimTargetPosition->x = (float)(s_fMinDistance * p_m_vFreeAimIntention->x)
                                          + this->m_vFreeAimCastOrigin.x;
            this->m_vFreeAimTargetPosition.y = v95;
            this->m_vFreeAimTargetPosition.z = v96;
          }
          if ( s_bDrawRaycasts )
            Render::DebugDrawContext::DrawPoint(
              v118,
              &this->m_vFreeAimTargetPosition,
              &UFG::qColour::Red,
              &UFG::qMatrix44::msIdentity,
              0i64);
          return;
        }
        if ( v49 >= 0 )
        {
          if ( (v49 & 0x2000) != 0 )
          {
            v55 = *(_DWORD *)(v42 + 128);
            v56 = *(_DWORD *)(v42 + 96);
            if ( v55 < v56 )
            {
              v53 = *(_QWORD *)(v42 + 104);
              do
              {
                v54 = 2i64 * v55;
                if ( (*(_DWORD *)(v53 + 16i64 * v55 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                  && (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v53 + 16i64 * v55 + 8) & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_67;
                }
              }
              while ( ++v55 < v56 );
            }
          }
          else
          {
            if ( (v49 & 0x1000) == 0 )
            {
              v50 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v42, UFG::CharacterOccupantComponent::_TypeUID);
              goto LABEL_84;
            }
            v57 = *(_DWORD *)(v42 + 128);
            v58 = *(_DWORD *)(v42 + 96);
            if ( v57 < v58 )
            {
              v53 = *(_QWORD *)(v42 + 104);
              do
              {
                v54 = 2i64 * v57;
                if ( (*(_DWORD *)(v53 + 16i64 * v57 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                  && (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v53 + 16i64 * v57 + 8) & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_67;
                }
              }
              while ( ++v57 < v58 );
            }
          }
        }
        else
        {
          v51 = *(_DWORD *)(v42 + 128);
          v52 = *(_DWORD *)(v42 + 96);
          if ( v51 < v52 )
          {
            v53 = *(_QWORD *)(v42 + 104);
            while ( 1 )
            {
              v54 = 2i64 * v51;
              if ( (*(_DWORD *)(v53 + 16i64 * v51 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                && (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v53 + 16i64 * v51 + 8) & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v51 >= v52 )
                goto LABEL_68;
            }
LABEL_67:
            v50 = *(UFG::SimComponent **)(v53 + 8 * v54);
            goto LABEL_84;
          }
        }
LABEL_68:
        v50 = 0i64;
        goto LABEL_84;
      }
    }
    v70 = *(_WORD *)(v42 + 76);
    if ( (v70 & 0x4000) != 0 )
    {
      v71 = *(_DWORD *)(v42 + 128);
      v72 = *(_DWORD *)(v42 + 96);
      if ( v71 < v72 )
      {
        v73 = *(_QWORD *)(v42 + 104);
        while ( 1 )
        {
          v74 = 2i64 * v71;
          if ( (*(_DWORD *)(v73 + 16i64 * v71 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v73 + 16i64 * v71 + 8) & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v71 >= v72 )
            goto LABEL_131;
        }
LABEL_130:
        v75 = *(UFG::SimComponent **)(v73 + 8 * v74);
        goto LABEL_154;
      }
    }
    else if ( v70 >= 0 )
    {
      if ( (v70 & 0x2000) != 0 )
      {
        v78 = *(_DWORD *)(v42 + 128);
        v79 = *(_DWORD *)(v42 + 96);
        if ( v78 < v79 )
        {
          v73 = *(_QWORD *)(v42 + 104);
          do
          {
            v74 = 2i64 * v78;
            if ( (*(_DWORD *)(v73 + 16i64 * v78 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v73 + 16i64 * v78 + 8) & 0x1FFFFFF) == 0 )
            {
              goto LABEL_130;
            }
          }
          while ( ++v78 < v79 );
        }
      }
      else
      {
        if ( (v70 & 0x1000) == 0 )
        {
          v75 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v42, UFG::RigidBodyComponent::_TypeUID);
LABEL_154:
          if ( v75 )
          {
            UFG::qReflectHandleBase::qReflectHandleBase(&v100);
            v83 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v82);
            v100.mTypeUID = UFG::qStringHash64(v83, 0xFFFFFFFFFFFFFFFFui64);
            v84 = *(_QWORD *)&v75[2].m_Flags;
            if ( v84 )
              UFG::qReflectHandleBase::operator=(&v100, (UFG::qReflectHandleBase *)(v84 + 224));
            if ( rayStart_8 )
            {
              if ( *(_BYTE *)(rayStart_8 + 146) )
              {
                UFG::qSafePointer<Creature,Creature>::operator=(
                  (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->m_FreeAimSimObject,
                  (UFG::SimComponent *)v42);
                if ( (UFG::SimObject *)v3 == this->m_FreeAimSimObject.m_pPointer )
                  this->m_bFocusTargetProbed = 1;
              }
            }
            UFG::qReflectHandleBase::~qReflectHandleBase(&v100);
          }
          goto LABEL_162;
        }
        v80 = *(_DWORD *)(v42 + 128);
        v81 = *(_DWORD *)(v42 + 96);
        if ( v80 < v81 )
        {
          v73 = *(_QWORD *)(v42 + 104);
          do
          {
            v74 = 2i64 * v80;
            if ( (*(_DWORD *)(v73 + 16i64 * v80 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v73 + 16i64 * v80 + 8) & 0x1FFFFFF) == 0 )
            {
              goto LABEL_130;
            }
          }
          while ( ++v80 < v81 );
        }
      }
    }
    else
    {
      v76 = *(_DWORD *)(v42 + 128);
      v77 = *(_DWORD *)(v42 + 96);
      if ( v76 < v77 )
      {
        v73 = *(_QWORD *)(v42 + 104);
        do
        {
          v74 = 2i64 * v76;
          if ( (*(_DWORD *)(v73 + 16i64 * v76 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v73 + 16i64 * v76 + 8) & 0x1FFFFFF) == 0 )
          {
            goto LABEL_130;
          }
        }
        while ( ++v76 < v77 );
      }
    }
LABEL_131:
    v75 = 0i64;
    goto LABEL_154;
  }
}

// File Line: 2201
// RVA: 0x549DD0
void __fastcall UFG::AimingPlayerComponent::ResetFreeAimIntention(UFG::AimingPlayerComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  float v2; // xmm2_4
  float v3; // xmm0_4
  __m128 x_low; // xmm4
  float z; // xmm6_4
  __m128 v6; // xmm3

  if ( this->m_pTSPPC.m_pSimComponent )
  {
    m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
    v2 = 0.0;
    v3 = *(float *)&m_pSimComponent[42].m_pSimObject;
    LODWORD(m_pSimComponent) = *(_DWORD *)(&m_pSimComponent[42].m_SimObjIndex + 1);
    this->m_vFreeAimIntention.y = v3;
    LODWORD(this->m_vFreeAimIntention.x) = (_DWORD)m_pSimComponent;
    this->m_vFreeAimIntention.z = 0.0;
    x_low = (__m128)LODWORD(this->m_vFreeAimIntention.x);
    z = this->m_vFreeAimIntention.z;
    v6 = x_low;
    v6.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v3 * v3)) + (float)(z * z);
    if ( v6.m128_f32[0] != 0.0 )
      v2 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
    this->m_vFreeAimIntention.x = x_low.m128_f32[0] * v2;
    this->m_vFreeAimIntention.z = z * v2;
    this->m_vFreeAimIntention.y = v3 * v2;
  }
}

// File Line: 2213
// RVA: 0x52D900
UFG::qVector3 *__fastcall UFG::AimingPlayerComponent::GetFreeAimFocusPosition(
        UFG::AimingPlayerComponent *this,
        UFG::qVector3 *result)
{
  float y; // xmm5_4
  __int128 x_low; // xmm4
  UFG::qVector3 *v4; // rax
  __m128 v5; // xmm2
  float z; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm5_4

  y = this->m_vFreeAimIntention.y;
  x_low = LODWORD(this->m_vFreeAimIntention.x);
  v4 = result;
  v5 = (__m128)x_low;
  z = this->m_vFreeAimIntention.z;
  v5.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(y * y)) + (float)(z * z);
  v7 = _mm_sqrt_ps(v5).m128_f32[0];
  *(float *)&x_low = (float)(*(float *)&x_low * (float)(UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / v7))
                   + this->m_vFreeAimOrigin.x;
  v8 = (float)(y * (float)(UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / v7)) + this->m_vFreeAimOrigin.y;
  result->z = (float)(z * (float)(UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / v7)) + this->m_vFreeAimOrigin.z;
  LODWORD(result->x) = x_low;
  result->y = v8;
  return v4;
}

// File Line: 2220
// RVA: 0x573F80
void __fastcall UFG::AimingPlayerComponent::updateFreeAimOrigin(UFG::AimingPlayerComponent *this, float dt)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float z; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm9_4
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  float *p_mFOVOffset; // rsi
  UFG::SimComponent *v11; // r14
  UFG::BaseCameraComponent *v12; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  UFG::qVector3 *p_z; // rax
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
  UFG::qVector3 *p_m_vFreeAimRootPosSS; // rbx
  UFG::qMatrix44 *Matrix; // rax
  int m_iFreeAimSyncBoneID; // edx
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
  UFG::qVector4 v46; // xmm0
  UFG::qMatrix44 *v47; // rax
  UFG::qVector4 v48; // xmm1
  UFG::qVector4 v49; // xmm0
  UFG::qVector4 v50; // xmm1
  UFG::SimComponent *v51; // rbx
  UFG::qVector4 v52; // xmm2
  UFG::qVector4 v53; // xmm0
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> m_BoundComponentHandles; // xmm3
  UFG::qVector4 v55; // xmm1
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int v58; // r8d
  unsigned int size; // r10d
  __int64 v60; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v62; // r8d
  unsigned int v63; // r10d
  unsigned int v64; // r8d
  unsigned int v65; // r10d
  unsigned int v66; // r8d
  unsigned int v67; // r10d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // r14
  _DWORD *v69; // rax
  int v70; // xmm4_4
  int v71; // xmm5_4
  int v72; // xmm3_4
  float v73; // xmm2_4
  float v74; // xmm2_4
  unsigned int v75; // xmm0_4
  unsigned int v76; // xmm1_4
  __m128 x_low; // xmm2
  float v78; // xmm5_4
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm5_4
  float v82; // xmm2_4
  float v83; // xmm1_4
  float v84; // xmm6_4
  float v85; // xmm4_4
  __m128 v86; // xmm9
  __m128 v87; // xmm2
  float v88; // xmm2_4
  __m128 z_low; // xmm3
  float v90; // xmm6_4
  float v91; // xmm5_4
  __m128 v92; // xmm2
  float v93; // xmm2_4
  float v94; // xmm0_4
  float v95; // xmm1_4
  UFG::SimComponent *v96; // rbx
  UFG::qVector4 v97; // xmm2
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> v98; // xmm1
  UFG::qVector4 v99; // xmm0
  float v100; // xmm12_4
  float v101; // xmm11_4
  float v102; // xmm0_4
  float v103; // xmm1_4
  float v104; // xmm12_4
  float v105; // xmm4_4
  __m128 v106; // xmm3
  float v107; // xmm5_4
  __m128 v108; // xmm2
  float v109; // xmm1_4
  float v110; // xmm3_4
  float v111; // xmm4_4
  float v112; // xmm5_4
  __m128 v113; // xmm2
  float v114; // xmm2_4
  float v115; // xmm1_4
  float v116; // xmm9_4
  float v117; // xmm2_4
  float v118; // xmm9_4
  float v119; // xmm1_4
  float v120; // xmm10_4
  float v121; // xmm2_4
  float v122; // xmm9_4
  float v123; // xmm6_4
  float v124; // xmm6_4
  float v125; // xmm15_4
  float v126; // xmm14_4
  float v127; // xmm6_4
  float v128; // xmm15_4
  float v129; // xmm14_4
  float v130; // xmm2_4
  float v131; // xmm9_4
  float v132; // xmm10_4
  float v133; // xmm13_4
  float v134; // xmm7_4
  float v135; // xmm4_4
  float v136; // xmm5_4
  UFG::BaseCameraComponent *v137; // rcx
  float v138; // xmm1_4
  float v139; // xmm2_4
  UFG::qVector4 v140; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qVector4 v141; // [rsp+30h] [rbp-A8h]
  UFG::qVector4 v142; // [rsp+40h] [rbp-98h]
  _BYTE v143[24]; // [rsp+50h] [rbp-88h]
  _OWORD b[7]; // [rsp+68h] [rbp-70h] BYREF
  UFG::qMatrix44 transform; // [rsp+D8h] [rbp+0h] BYREF
  UFG::qMatrix44 result; // [rsp+118h] [rbp+40h] BYREF
  UFG::qMatrix44 v147; // [rsp+158h] [rbp+80h] BYREF
  UFG::qMatrix44 m; // [rsp+198h] [rbp+C0h] BYREF
  UFG::qMatrix44 d; // [rsp+1D8h] [rbp+100h] BYREF
  float x; // [rsp+2F8h] [rbp+220h]
  float delta_sec; // [rsp+300h] [rbp+228h]
  float v152; // [rsp+308h] [rbp+230h]
  float vars0; // [rsp+310h] [rbp+238h]

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  z = m_pSimComponent->mWorldTransform.v3.z;
  y = m_pSimComponent->mWorldTransform.v3.y;
  v6 = m_pSimComponent->mWorldTransform.v3.x - this->m_vFreeAimLastFramePosition.x;
  v7 = y - this->m_vFreeAimLastFramePosition.y;
  v8 = z - this->m_vFreeAimLastFramePosition.z;
  this->m_vFreeAimLastFramePosition.x = m_pSimComponent->mWorldTransform.v3.x;
  this->m_vFreeAimLastFramePosition.z = z;
  this->m_vFreeAimLastFramePosition.y = y;
  *(float *)b = UFG::qVector3::msZero.x;
  *(float *)&v143[20] = UFG::qVector3::msZero.x;
  x = UFG::qVector3::msZero.y;
  v152 = UFG::qVector3::msZero.z;
  vars0 = UFG::qVector3::msZero.y;
  *(float *)&v143[16] = UFG::qVector3::msZero.z;
  CurrentBaseCamera = UFG::GetCurrentBaseCamera();
  p_mFOVOffset = 0i64;
  v11 = CurrentBaseCamera;
  if ( !CurrentBaseCamera
    || (v12 = CurrentBaseCamera,
        !UFG::SimComponent::IsType(CurrentBaseCamera, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID)) )
  {
    v12 = 0i64;
  }
  if ( !v11 || !UFG::SimComponent::IsType(v11, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID) )
    v11 = 0i64;
  if ( v12 )
  {
    if ( !LODWORD(this->m_pTSPPC.m_pSimComponent[53].m_pSimObject) )
    {
LABEL_9:
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
      v14 = p_mFOVOffset[45] + v7;
      v15 = p_mFOVOffset[46] + v8;
      this->m_vFreeAimOrigin.x = p_mFOVOffset[44] + v6;
      this->m_vFreeAimOrigin.y = v14;
      this->m_vFreeAimOrigin.z = v15;
      this->m_vAimPosition.x = v6 + this->m_vAimPosition.x;
      this->m_vAimPosition.y = v7 + this->m_vAimPosition.y;
      this->m_vAimPosition.z = v8 + this->m_vAimPosition.z;
      return;
    }
    if ( !((unsigned __int8 (__fastcall *)(UFG::BaseCameraComponent *))v12->vfptr[37].__vecDelDtor)(v12) )
    {
      vfptr = v12->vfptr;
      LOBYTE(v12[8].mCamera.mProjection.v2.x) = 1;
      ((void (__fastcall *)(UFG::BaseCameraComponent *))vfptr[15].__vecDelDtor)(v12);
      LOBYTE(v12[8].mCamera.mProjection.v2.x) = 0;
    }
    p_z = (UFG::qVector3 *)&v12[10].mCamera.mOverrideView.v1.z;
    *(float *)&v143[20] = v12[10].mCamera.mOverrideView.v0.w;
    x = v12[10].mCamera.mOverrideView.v1.x;
    v152 = v12[10].mCamera.mOverrideView.v1.y;
    if ( !LOBYTE(v12[10].mCamera.mProjection.v2.z) )
      p_z = &UFG::qVector3::msZero;
    v18 = p_z->y;
    v19 = p_z->z;
    *(float *)b = p_z->x;
    vars0 = v18;
    *(float *)&v143[16] = v19;
    if ( UFG::AimingPlayerComponent::ms_bNewCoverBehaviour && this->m_bUsingCover )
    {
      v152 = 0.0;
      x = 0.0;
    }
  }
  else if ( v11 )
  {
    goto LABEL_9;
  }
  v20 = 0i64;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
    v20 = *(Creature **)&this->m_CharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
  v21 = *(float *)&FLOAT_1_0;
  if ( UFG::AimingPlayerComponent::ms_bFreeAimRootSmoothing )
  {
    *(UFG::qVector4 *)&v143[8] = UFG::qMatrix44::msIdentity.v1;
    b[0] = UFG::qMatrix44::msIdentity.v2;
    b[1] = UFG::qMatrix44::msIdentity.v3;
    *(UFG::qMatrix44 *)&b[3] = UFG::qMatrix44::msIdentity;
    if ( !v20 || v20 == (Creature *)-240i64 )
    {
      v51 = this->m_TransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v51);
      v52 = *(UFG::qVector4 *)&v51[2].m_SafePointerList.mNode.mNext;
      v53 = *(UFG::qVector4 *)&v51[2].m_Flags;
      m_BoundComponentHandles = v51[2].m_BoundComponentHandles;
      v55 = *(UFG::qVector4 *)&v51[2].vfptr;
      v21 = *(float *)&FLOAT_1_0;
      *(_QWORD *)&v143[16] = *(_QWORD *)&v51[2].m_TypeUID;
      v141 = v52;
      v142 = v53;
      *(UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v143 = m_BoundComponentHandles;
      v140 = v55;
      b[0] = v53;
      b[1] = m_BoundComponentHandles;
    }
    else
    {
      Creature::GetTransformMS(v20, this->m_iFreeAimOriginBoneID, &transform);
      if ( UFG::AimingPlayerComponent::ms_bNewCoverBehaviour && this->m_bUsingCover && v12 )
      {
        transform.v3.w = 1.0;
        v22 = transform.v3.z + v12[10].mCamera.mOverrideView.v1.y;
        transform.v3.y = transform.v3.y + v12[10].mCamera.mOverrideView.v1.x;
        transform.v3.z = v22;
      }
      Creature::GetTransformMS(v20, this->m_iFreeAimSyncBoneID, &m);
      UFG::qInverse(&d, &m);
      UFG::qMatrix44::operator*(&transform, &result, &d);
      v23 = result.v3.x;
      v24 = result.v3.y;
      v25 = result.v3.z;
      UFG::qQuaternion::Set((UFG::qQuaternion *)&b[2], &result);
      if ( this->m_bFreeAimRootDirty )
      {
        v26 = *(float *)&b[2];
        v27 = *((float *)&b[2] + 1);
        this->m_vFreeAimRootPosSS.x = v23;
        this->m_vFreeAimRootPosSS.y = v24;
        this->m_vFreeAimRootPosSS.z = v25;
        this->m_qFreeAimRootOriSS.x = v26;
        v28 = *((float *)&b[2] + 2);
        this->m_qFreeAimRootOriSS.y = v27;
        v29 = *((float *)&b[2] + 3);
        this->m_qFreeAimRootOriSS.z = v28;
        this->m_qFreeAimRootOriSS.w = v29;
        this->m_bFreeAimRootDirty = 0;
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
      p_m_vFreeAimRootPosSS = &this->m_vFreeAimRootPosSS;
      UFG::qApproach(&this->m_vFreeAimRootPosSS.x, v23, v30, delta_sec);
      UFG::qApproach(&this->m_vFreeAimRootPosSS.y, v24, v30, v32);
      UFG::qApproach(&this->m_vFreeAimRootPosSS.z, v25, v30, v32);
      UFG::qApproachOrientation(&this->m_qFreeAimRootOriSS, (UFG::qQuaternion *)&b[2], v31, v32);
      this->m_bFreeAimRootMovementLock = 0;
      if ( UFG::AimingPlayerComponent::ms_bFreeAimAutoMovementLock
        && (float)((float)((float)((float)(this->m_vFreeAimRootPosSS.y - v24)
                                 * (float)(this->m_vFreeAimRootPosSS.y - v24))
                         + (float)((float)(p_m_vFreeAimRootPosSS->x - v23) * (float)(p_m_vFreeAimRootPosSS->x - v23)))
                 + (float)((float)(this->m_vFreeAimRootPosSS.z - v25) * (float)(this->m_vFreeAimRootPosSS.z - v25))) > (float)(UFG::AimingPlayerComponent::ms_fFreeAimRootMovementLockThreshold * UFG::AimingPlayerComponent::ms_fFreeAimRootMovementLockThreshold) )
      {
        this->m_bFreeAimRootMovementLock = 1;
      }
      Matrix = UFG::qQuaternion::GetMatrix(&this->m_qFreeAimRootOriSS, &v147, &UFG::qVector3::msZero);
      m_iFreeAimSyncBoneID = this->m_iFreeAimSyncBoneID;
      v36 = Matrix->v2;
      v37 = Matrix->v0;
      v38 = Matrix->v1;
      result.v3 = Matrix->v3;
      v39 = this->m_vFreeAimRootPosSS.y;
      result.v3.w = 1.0;
      result.v0 = v37;
      v37.x = p_m_vFreeAimRootPosSS->x;
      result.v2 = v36;
      v36.x = this->m_vFreeAimRootPosSS.z;
      result.v3.x = v37.x;
      result.v3.y = v39;
      result.v3.z = v36.x;
      result.v1 = v38;
      Creature::GetTransform(v20, m_iFreeAimSyncBoneID, (UFG::qMatrix44 *)&b[3]);
      v40 = UFG::qMatrix44::operator*(&result, &v147, (UFG::qMatrix44 *)&b[3]);
      v41 = v40->v2;
      v42 = v40->v3;
      v43 = v40->v0;
      v141 = v40->v1;
      v142 = v41;
      v140 = v43;
      *(UFG::qVector4 *)v143 = v42;
      v44 = UFG::qQuaternion::GetMatrix((UFG::qQuaternion *)&b[2], &v147, &UFG::qVector3::msZero);
      v45 = v44->v0;
      *(UFG::qVector4 *)&v143[8] = v44->v1;
      *(UFG::qVector4 *)((char *)b + 8) = v45;
      v46 = v44->v2;
      *(_QWORD *)&b[1] = __PAIR64__(LODWORD(v24), LODWORD(v23));
      *((_QWORD *)&b[1] + 1) = LODWORD(v25) | 0x3F80000000000000i64;
      b[0] = v46;
      v47 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)((char *)b + 8), &v147, (UFG::qMatrix44 *)&b[3]);
      v48 = v47->v1;
      *(UFG::qVector4 *)((char *)b + 8) = v47->v0;
      v49 = v47->v2;
      *(UFG::qVector4 *)&v143[8] = v48;
      v50 = v47->v3;
      b[0] = v49;
      b[1] = v50;
    }
    goto LABEL_94;
  }
  if ( v20 )
  {
    if ( v12 && LOBYTE(v12[10].mCamera.mProjection.v2.z) )
    {
      Creature::GetTransform(v20, this->m_iFreeAimSyncBoneID, (UFG::qMatrix44 *)&v140);
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          v58 = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          v60 = v58;
          if ( v58 < size )
          {
            v60 = (__int64)&m_pSimObject->m_Components.p[v58];
            while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                 || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v58;
              v60 += 16i64;
              if ( v58 >= size )
                goto LABEL_48;
            }
LABEL_49:
            ComponentOfType = *(UFG::SimComponent **)v60;
            goto LABEL_72;
          }
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            v64 = (unsigned int)m_pSimObject[1].vfptr;
            v65 = m_pSimObject->m_Components.size;
            v60 = v64;
            if ( v64 < v65 )
            {
              v60 = (__int64)&m_pSimObject->m_Components.p[v64];
              while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                   || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v64;
                v60 += 16i64;
                if ( v64 >= v65 )
                {
                  ComponentOfType = 0i64;
                  goto LABEL_72;
                }
              }
              goto LABEL_49;
            }
          }
          else
          {
            if ( (m_Flags & 0x1000) == 0 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AICoverComponent::_TypeUID);
              goto LABEL_72;
            }
            v66 = (unsigned int)m_pSimObject[1].vfptr;
            v67 = m_pSimObject->m_Components.size;
            v60 = v66;
            if ( v66 < v67 )
            {
              v60 = (__int64)&m_pSimObject->m_Components.p[v66];
              while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                   || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v66;
                v60 += 16i64;
                if ( v66 >= v67 )
                {
                  ComponentOfType = 0i64;
                  goto LABEL_72;
                }
              }
              goto LABEL_49;
            }
          }
        }
        else
        {
          v62 = (unsigned int)m_pSimObject[1].vfptr;
          v63 = m_pSimObject->m_Components.size;
          v60 = v62;
          if ( v62 < v63 )
          {
            v60 = (__int64)&m_pSimObject->m_Components.p[v62];
            while ( (*(_DWORD *)(v60 + 8) & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
                 || (UFG::AICoverComponent::_TypeUID & ~*(_DWORD *)(v60 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v62;
              v60 += 16i64;
              if ( v62 >= v63 )
              {
                ComponentOfType = 0i64;
                goto LABEL_72;
              }
            }
            goto LABEL_49;
          }
        }
LABEL_48:
        ComponentOfType = 0i64;
LABEL_72:
        if ( ComponentOfType )
        {
          mNext = ComponentOfType[1].m_BoundComponentHandles.mNode.mNext;
          if ( mNext )
          {
            if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, __int64))mNext->mPrev[1].mPrev)(
                   mNext,
                   v60) )
            {
              v69 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, _OWORD *))mNext->mPrev[10].mPrev)(
                                mNext,
                                &b[2]);
              v70 = v69[1] ^ _xmm[0];
              v71 = v69[2] ^ _xmm[0];
              v72 = *v69 ^ _xmm[0];
              v73 = (float)((float)(*(float *)&v70 * *(float *)&v70) + (float)(*(float *)&v72 * *(float *)&v72))
                  + (float)(*(float *)&v71 * *(float *)&v71);
              if ( v73 == 0.0 )
                v74 = 0.0;
              else
                v74 = 1.0 / fsqrt(v73);
              v140.w = 0.0;
              *(float *)&v75 = v74 * *(float *)&v70;
              *(float *)&v76 = v74 * *(float *)&v72;
              v140.z = v74 * *(float *)&v71;
              x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
              *(_QWORD *)&v140.x = __PAIR64__(v75, v76);
              x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                        + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                                + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
              if ( x_low.m128_f32[0] == 0.0 )
                v78 = 0.0;
              else
                v78 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
              v79 = v78;
              v80 = v78;
              v81 = v78 * UFG::qVector3::msDirUp.z;
              v82 = v79 * UFG::qVector3::msDirUp.x;
              v83 = v80 * UFG::qVector3::msDirUp.y;
              v84 = (float)(v140.z * v83) - (float)(v140.y * v81);
              v86 = (__m128)LODWORD(v140.x);
              v85 = (float)(v140.y * v82) - (float)(v140.x * v83);
              v86.m128_f32[0] = (float)(v140.x * v81) - (float)(v140.z * v82);
              v87 = v86;
              v87.m128_f32[0] = (float)((float)(v86.m128_f32[0] * v86.m128_f32[0]) + (float)(v84 * v84))
                              + (float)(v85 * v85);
              if ( v87.m128_f32[0] == 0.0 )
                v88 = 0.0;
              else
                v88 = 1.0 / _mm_sqrt_ps(v87).m128_f32[0];
              z_low = (__m128)LODWORD(v140.z);
              v141.w = 0.0;
              v141.z = v88 * v85;
              v141.y = v88 * v86.m128_f32[0];
              v141.x = v88 * v84;
              z_low.m128_f32[0] = (float)(v140.z * (float)(v88 * v84)) - (float)((float)(v88 * v85) * v140.x);
              v90 = (float)((float)(v88 * v85) * v140.y) - (float)(v140.z * (float)(v88 * v86.m128_f32[0]));
              v91 = (float)((float)(v88 * v86.m128_f32[0]) * v140.x) - (float)(v140.y * v141.x);
              v92 = z_low;
              v92.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v90 * v90))
                              + (float)(v91 * v91);
              if ( v92.m128_f32[0] == 0.0 )
                v93 = 0.0;
              else
                v93 = 1.0 / _mm_sqrt_ps(v92).m128_f32[0];
              v142.w = 0.0;
              *(_DWORD *)&v143[12] = 1065353216;
              v142.z = v93 * v91;
              v142.x = v93 * v90;
              v142.y = v93 * z_low.m128_f32[0];
            }
          }
        }
      }
    }
    else
    {
      Creature::GetTransform(v20, this->m_iFreeAimOriginBoneID, (UFG::qMatrix44 *)&v140);
    }
    if ( UFG::AimingPlayerComponent::ms_bNewCoverBehaviour && this->m_bUsingCover && v12 )
    {
      Creature::GetTransform(v20, this->m_iFreeAimSyncBoneID, &transform);
      v94 = v12[10].mCamera.mOverrideView.v1.x;
      v95 = v12[10].mCamera.mOverrideView.v1.y;
      *(_DWORD *)&v143[12] = 1065353216;
      *(float *)v143 = *(float *)v143 + (float)((float)(transform.v2.x * v95) + (float)(transform.v1.x * v94));
      v21 = *(float *)&FLOAT_1_0;
      *(float *)&v143[4] = *(float *)&v143[4] + (float)((float)(transform.v2.y * v95) + (float)(transform.v1.y * v94));
      *(float *)&v143[8] = *(float *)&v143[8] + (float)((float)(transform.v2.z * v95) + (float)(transform.v1.z * v94));
    }
    goto LABEL_94;
  }
  v96 = this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v96);
  v97 = *(UFG::qVector4 *)&v96[2].m_Flags;
  v98 = v96[2].m_BoundComponentHandles;
  v99 = *(UFG::qVector4 *)&v96[2].vfptr;
  v141 = *(UFG::qVector4 *)&v96[2].m_SafePointerList.mNode.mNext;
  v142 = v97;
  v140 = v99;
  *(UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v143 = v98;
LABEL_94:
  v100 = (float)(v141.z * vars0) + (float)(v140.z * *(float *)b);
  v101 = (float)((float)((float)(v141.y * vars0) + (float)(v140.y * *(float *)b)) + (float)(v142.y * *(float *)&v143[16]))
       + *(float *)&v143[4];
  v102 = *(float *)v143
       + (float)((float)((float)(v141.x * vars0) + (float)(v140.x * *(float *)b)) + (float)(v142.x * *(float *)&v143[16]));
  v103 = v142.z * *(float *)&v143[16];
  this->m_vFreeAimBaseOffset.x = v102;
  this->m_vFreeAimBaseOffset.y = v101;
  v104 = (float)(v100 + v103) + *(float *)&v143[8];
  vars0 = v102;
  this->m_vFreeAimBaseOffset.z = v104;
  v105 = this->m_vFreeAimIntention.y;
  v106 = (__m128)LODWORD(this->m_vFreeAimIntention.x);
  v108 = v106;
  v107 = this->m_vFreeAimIntention.z;
  v108.m128_f32[0] = (float)((float)(v106.m128_f32[0] * v106.m128_f32[0]) + (float)(v105 * v105)) + (float)(v107 * v107);
  if ( v108.m128_f32[0] == 0.0 )
    v109 = 0.0;
  else
    v109 = v21 / _mm_sqrt_ps(v108).m128_f32[0];
  v110 = v106.m128_f32[0] * v109;
  v111 = v105 * v109;
  v112 = v107 * v109;
  v113 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v113.m128_f32[0] = (float)((float)(v113.m128_f32[0] * v113.m128_f32[0])
                           + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v113.m128_f32[0] == 0.0 )
    v114 = 0.0;
  else
    v114 = v21 / _mm_sqrt_ps(v113).m128_f32[0];
  v115 = v114;
  v116 = v114;
  v117 = v114 * UFG::qVector3::msDirUp.z;
  v118 = v116 * UFG::qVector3::msDirUp.x;
  v119 = v115 * UFG::qVector3::msDirUp.y;
  v120 = (float)(v119 * v112) - (float)(v117 * v111);
  v121 = (float)(v117 * v110) - (float)(v118 * v112);
  v122 = (float)(v118 * v111) - (float)(v119 * v110);
  v123 = (float)((float)(v121 * v121) + (float)(v120 * v120)) + (float)(v122 * v122);
  if ( v123 == 0.0 )
    v124 = 0.0;
  else
    v124 = v21 / fsqrt(v123);
  v125 = v124;
  v126 = v124;
  v127 = v124 * v122;
  v128 = v125 * v121;
  v129 = v126 * v120;
  v130 = (float)(v127 * v111) - (float)(v128 * v112);
  v131 = (float)(v129 * v112) - (float)(v127 * v110);
  v132 = (float)(v128 * v110) - (float)(v129 * v111);
  v133 = (float)((float)(v131 * v131) + (float)(v130 * v130)) + (float)(v132 * v132);
  if ( v133 == 0.0 )
    v134 = 0.0;
  else
    v134 = v21 / fsqrt(v133);
  v135 = (float)((float)((float)(v111 * *(float *)&v143[20]) + (float)(v128 * x)) + (float)((float)(v131 * v134) * v152))
       + v101;
  v136 = (float)((float)((float)(v112 * *(float *)&v143[20]) + (float)(v127 * x)) + (float)((float)(v132 * v134) * v152))
       + v104;
  this->m_vFreeAimOrigin.x = (float)((float)((float)(v110 * *(float *)&v143[20]) + (float)(v129 * x))
                                   + (float)((float)(v130 * v134) * v152))
                           + vars0;
  this->m_vFreeAimOrigin.y = v135;
  this->m_vFreeAimOrigin.z = v136;
  if ( !UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject)
    && UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
  {
    v137 = UFG::Director::Get()->mCurrentCamera;
    if ( v137 )
      p_mFOVOffset = &v137->mCamera.mFOVOffset;
    v138 = p_mFOVOffset[45];
    v139 = p_mFOVOffset[46];
    this->m_vFreeAimOrigin.x = p_mFOVOffset[44];
    this->m_vFreeAimOrigin.y = v138;
    this->m_vFreeAimOrigin.z = v139;
  }
}

// File Line: 2440
// RVA: 0x56FDC0
void __fastcall UFG::AimingPlayerComponent::updateAimIntentionTargetPosition(
        UFG::AimingPlayerComponent *this,
        __int64 matXform)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::qMatrix44 *size; // r9
  UFG::SimObjectProp *v5; // rdi
  __int64 m_pSimObject_low; // r8
  bool v7; // r15
  bool v8; // bp
  UFG::SubTargetingLocation *mPrev; // r12
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r14
  __int16 v12; // cx
  UFG::CharacterAnimationComponent *v13; // rcx
  unsigned int v14; // r8d
  unsigned int m_TypeUID; // edx
  unsigned int v16; // eax
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v19; // r9d
  __int64 v20; // rdx
  Creature *pCreature; // rsi
  UFG::SubTargetingProfile *v22; // rax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 vSubTargetingLocationWS; // [rsp+30h] [rbp-38h] BYREF
  UFG::qMatrix44 *pXform; // [rsp+78h] [rbp+10h]

  pXform = (UFG::qMatrix44 *)matXform;
  m_pSimComponent = this->m_pTSPPC.m_pSimComponent;
  size = (UFG::qMatrix44 *)matXform;
  if ( m_pSimComponent )
  {
    v5 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 30i64)
                                + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                                + 40);
    m_pSimObject_low = LODWORD(m_pSimComponent[53].m_pSimObject);
    LOBYTE(matXform) = (unsigned int)(m_pSimObject_low - 1) <= 1;
    v7 = (unsigned int)(m_pSimObject_low - 3) <= 1;
    v8 = (_DWORD)m_pSimObject_low == 2;
    if ( this->m_bCameraZoomMode )
      goto LABEL_50;
    if ( (unsigned int)(m_pSimObject_low - 1) > 1
      && (unsigned int)(m_pSimObject_low - 3) > 1
      && (_DWORD)m_pSimObject_low != 2 )
    {
      goto LABEL_53;
    }
    mPrev = (UFG::SubTargetingLocation *)m_pSimComponent[42].m_BoundComponentHandles.mNode.mPrev;
    if ( !mPrev || !v5 )
      goto LABEL_50;
    m_Flags = v5->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v5->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v5->m_Components.p[4].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pSimObject_low = v5->mComponentTableEntryCount;
        size = (UFG::qMatrix44 *)v5->m_Components.size;
        matXform = (unsigned int)m_pSimObject_low;
        if ( (unsigned int)m_pSimObject_low >= (unsigned int)size )
        {
LABEL_20:
          m_pComponent = 0i64;
        }
        else
        {
          matXform = (__int64)&v5->m_Components.p[(unsigned int)m_pSimObject_low];
          while ( (*(_DWORD *)(matXform + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(matXform + 8) & 0x1FFFFFF) != 0 )
          {
            m_pSimObject_low = (unsigned int)(m_pSimObject_low + 1);
            matXform += 16i64;
            if ( (unsigned int)m_pSimObject_low >= (unsigned int)size )
              goto LABEL_20;
          }
          m_pComponent = *(UFG::SimComponent **)matXform;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v5, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v5->m_Components.p[3].m_pComponent;
    }
    if ( !m_pComponent
      || !((__int64 (__fastcall *)(UFG::SimComponent *, __int64, __int64, UFG::qMatrix44 *))m_pComponent->vfptr[14].__vecDelDtor)(
            m_pComponent,
            matXform,
            m_pSimObject_low,
            size) )
    {
LABEL_50:
      if ( v7 || v8 )
      {
LABEL_55:
        y = this->m_vFreeAimTargetPosition.y;
        z = this->m_vFreeAimTargetPosition.z;
        this->m_vAimIntentionTargetPosition.x = this->m_vFreeAimTargetPosition.x;
        this->m_vAimIntentionTargetPosition.y = y;
        this->m_vAimIntentionTargetPosition.z = z;
        return;
      }
      size = pXform;
LABEL_53:
      if ( !this->m_CharacterOccupantComponent.m_pSimComponent )
      {
        UFG::AimingBaseComponent::GetTargetNormalAimPosition(this, &this->m_vAimIntentionTargetPosition, 0x16u, size);
        return;
      }
      goto LABEL_55;
    }
    v12 = v5->m_Flags;
    if ( (v12 & 0x4000) != 0 )
    {
      v13 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
      if ( v13 )
      {
        v14 = UFG::CharacterAnimationComponent::_TypeUID;
        m_TypeUID = v13->m_TypeUID;
        v16 = m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_28:
        if ( (v16 & 0xFE000000) != 0 || (v14 & ~m_TypeUID & 0x1FFFFFF) != 0 )
          goto LABEL_30;
LABEL_46:
        if ( v13 )
        {
          pCreature = v13->mCreature;
          if ( pCreature )
          {
            v22 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[14].__vecDelDtor)(m_pComponent);
            if ( UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                   v22,
                   &vSubTargetingLocationWS,
                   mPrev,
                   v5,
                   pCreature) )
            {
              v23 = vSubTargetingLocationWS.y;
              this->m_vAimIntentionTargetPosition.x = vSubTargetingLocationWS.x;
              v24 = vSubTargetingLocationWS.z;
              this->m_vAimIntentionTargetPosition.y = v23;
              this->m_vAimIntentionTargetPosition.z = v24;
              return;
            }
          }
        }
        goto LABEL_50;
      }
    }
    else
    {
      if ( v12 >= 0 )
      {
        if ( (v12 & 0x2000) != 0 )
        {
          ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v5);
        }
        else
        {
          if ( (v12 & 0x1000) != 0 )
          {
            mComponentTableEntryCount = v5->mComponentTableEntryCount;
            v19 = v5->m_Components.size;
            if ( mComponentTableEntryCount < v19 )
            {
              v20 = (__int64)&v5->m_Components.p[mComponentTableEntryCount];
              while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
              {
                ++mComponentTableEntryCount;
                v20 += 16i64;
                if ( mComponentTableEntryCount >= v19 )
                {
                  v13 = 0i64;
                  goto LABEL_46;
                }
              }
              v13 = *(UFG::CharacterAnimationComponent **)v20;
              goto LABEL_46;
            }
            goto LABEL_30;
          }
          ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v5,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
        }
        v13 = ComponentOfType;
        goto LABEL_46;
      }
      v13 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
      if ( v13 )
      {
        m_TypeUID = v13->m_TypeUID;
        v14 = UFG::CharacterAnimationComponent::_TypeUID;
        v16 = UFG::CharacterAnimationComponent::_TypeUID ^ m_TypeUID;
        goto LABEL_28;
      }
    }
LABEL_30:
    v13 = 0i64;
    goto LABEL_46;
  }
}

// File Line: 2505
// RVA: 0x52AA60
double __fastcall UFG::AimingPlayerComponent::GetAngularInaccuracyRad(UFG::AimingPlayerComponent *this)
{
  Illusion::Target *BackBufferTarget; // rax
  float mHeight; // xmm1_4
  float ReticleSize; // xmm0_4
  UFG::Camera *v5; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rcx
  UFG::BaseCameraComponent *v8; // rcx
  __int64 x_low; // xmm2_8
  double v10; // xmm0_8
  UFG::qVector3 v11; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+58h] [rbp+10h] BYREF
  UFG::qVector2 screen_pos; // [rsp+60h] [rbp+18h] BYREF
  UFG::qVector2 v15; // [rsp+68h] [rbp+20h] BYREF

  BackBufferTarget = Render::GetBackBufferTarget();
  mHeight = (float)BackBufferTarget->mHeight;
  viewport_scale.x = (float)BackBufferTarget->mWidth;
  viewport_scale.y = mHeight;
  ReticleSize = UFG::AimingPlayerComponent::GetReticleSize(this);
  v15.y = viewport_scale.y * 0.5;
  screen_pos.y = viewport_scale.y * 0.5;
  v15.x = viewport_scale.x * 0.5;
  screen_pos.x = (float)(viewport_scale.x * ReticleSize) + (float)(viewport_scale.x * 0.5);
  v5 = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  UFG::Camera::ScreenToWorldRay(p_mCamera, &result, &screen_pos, &viewport_scale);
  v8 = UFG::Director::Get()->mCurrentCamera;
  if ( v8 )
    v5 = &v8->mCamera;
  UFG::Camera::ScreenToWorldRay(v5, &v11, &v15, &viewport_scale);
  x_low = LODWORD(v11.x);
  *(float *)&x_low = (float)((float)(v11.x * result.x) + (float)(v11.y * result.y)) + (float)(v11.z * result.z);
  if ( *(float *)&x_low <= -1.0 )
  {
    x_low = LODWORD(FLOAT_N1_0);
    goto LABEL_11;
  }
  *(_QWORD *)&v10 = (unsigned int)FLOAT_1_0;
  if ( *(float *)&x_low < 1.0 )
  {
LABEL_11:
    HIDWORD(v10) = HIDWORD(x_low);
    *(float *)&v10 = acosf(*(float *)&x_low);
    return v10;
  }
  *(float *)&v10 = acosf(1.0);
  return v10;
}

// File Line: 2530
// RVA: 0x52D520
void __fastcall UFG::AimingPlayerComponent::GetFiringPositionAtAimPosition(
        UFG::AimingPlayerComponent *this,
        UFG::qVector3 *vFiringPositionAtAimPosition)
{
  __m128 y_low; // xmm2
  float v5; // xmm10_4
  double v6; // xmm0_8
  float v7; // xmm9_4
  float v8; // xmm8_4
  float v9; // xmm7_4
  float v10; // xmm7_4
  float v11; // xmm13_4
  float v12; // xmm14_4
  float v13; // xmm15_4
  __m128 x_low; // xmm2
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm9_4
  __m128 v19; // xmm2
  float v20; // xmm0_4
  __m128 v21; // xmm2
  float v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm10_4
  float v27; // xmm5_4
  __m128 v28; // xmm4
  float v29; // xmm0_4
  __m128 v30; // xmm4
  float v31; // xmm12_4
  float v32; // xmm4_4
  float v33; // xmm12_4
  __m128 v34; // xmm11
  float v35; // xmm5_4
  __m128 v36; // xmm10
  float v37; // xmm9_4
  __m128 v38; // xmm2
  float v39; // xmm6_4
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+30h] [rbp-B8h] BYREF
  float v42; // [rsp+F0h] [rbp+8h]
  float v43; // [rsp+F8h] [rbp+10h]

  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, &vWeaponProjectileSpawnPosition);
  y_low = (__m128)LODWORD(this->m_vAimOriginPosition.y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y)
                                    * (float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y))
                            + (float)((float)(this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x)
                                    * (float)(this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x)))
                    + (float)((float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z)
                            * (float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z));
  LODWORD(v5) = _mm_sqrt_ps(y_low).m128_u32[0];
  v6 = ((double (__fastcall *)(UFG::AimingPlayerComponent *))this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[21].__vecDelDtor)(this);
  v7 = *(float *)&v6;
  v8 = UFG::qRandom(6.2831855, (unsigned int *)&UFG::qDefaultSeed);
  if ( UFG::AimingPlayerComponent::ms_bCorrectDiscPointPicking )
    v9 = fsqrt(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed));
  else
    v9 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
  v10 = v9 * v7;
  v11 = cosf(v8) * v10;
  v12 = sinf(v8) * v10;
  UFG::AimingBaseComponent::GetWeaponProjectileDirection(this, &vWeaponProjectileDirection);
  v13 = vWeaponProjectileSpawnPosition.x + (float)(vWeaponProjectileDirection.x * v5);
  v42 = vWeaponProjectileSpawnPosition.y + (float)(vWeaponProjectileDirection.y * v5);
  x_low = (__m128)LODWORD(vWeaponProjectileDirection.x);
  v43 = vWeaponProjectileSpawnPosition.z + (float)(vWeaponProjectileDirection.z * v5);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y))
                    + (float)(vWeaponProjectileDirection.z * vWeaponProjectileDirection.z);
  if ( x_low.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
  v16 = vWeaponProjectileDirection.x * v15;
  v17 = vWeaponProjectileDirection.y * v15;
  v18 = vWeaponProjectileDirection.z * v15;
  v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v19.m128_f32[0] == 0.0 )
  {
    v21 = 0i64;
  }
  else
  {
    v20 = _mm_sqrt_ps(v19).m128_f32[0];
    v21 = (__m128)(unsigned int)FLOAT_1_0;
    v21.m128_f32[0] = 1.0 / v20;
  }
  v22 = v21.m128_f32[0];
  v23 = v21.m128_f32[0];
  v21.m128_f32[0] = v21.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v24 = v23 * UFG::qVector3::msDirUp.x;
  v25 = v22 * UFG::qVector3::msDirUp.y;
  v26 = (float)(v25 * v18) - (float)(v21.m128_f32[0] * v17);
  v21.m128_f32[0] = (float)(v21.m128_f32[0] * v16) - (float)(v24 * v18);
  v27 = (float)(v24 * v17) - (float)(v25 * v16);
  v28 = v21;
  v28.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v26 * v26)) + (float)(v27 * v27);
  if ( v28.m128_f32[0] == 0.0 )
  {
    v30 = 0i64;
  }
  else
  {
    v29 = _mm_sqrt_ps(v28).m128_f32[0];
    v30 = (__m128)(unsigned int)FLOAT_1_0;
    v30.m128_f32[0] = 1.0 / v29;
  }
  v31 = v30.m128_f32[0];
  v34 = v30;
  v32 = v30.m128_f32[0] * v27;
  v33 = v31 * v21.m128_f32[0];
  v34.m128_f32[0] = v34.m128_f32[0] * v26;
  v36 = v34;
  v35 = (float)(v32 * v17) - (float)(v33 * v18);
  v36.m128_f32[0] = (float)(v34.m128_f32[0] * v18) - (float)(v32 * v16);
  v38 = v36;
  v37 = (float)(v33 * v16) - (float)(v34.m128_f32[0] * v17);
  v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
  if ( v38.m128_f32[0] == 0.0 )
    v39 = 0.0;
  else
    v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
  vFiringPositionAtAimPosition->z = (float)((float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v32)
                                          + (float)((float)(v37 * v39) * v12))
                                  + v43;
  vFiringPositionAtAimPosition->y = (float)((float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v33)
                                          + (float)((float)(v36.m128_f32[0] * v39) * v12))
                                  + v42;
  vFiringPositionAtAimPosition->x = (float)((float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v34.m128_f32[0])
                                          + (float)((float)(v35 * v39) * v12))
                                  + v13;
}

// File Line: 2565
// RVA: 0x52F8D0
float __fastcall UFG::AimingPlayerComponent::GetRadialInaccuracyAtAimPosition(UFG::AimingPlayerComponent *this)
{
  double v2; // xmm0_8
  float v3; // xmm7_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  __m128 y_low; // xmm2
  float v6; // xmm0_4

  v2 = ((double (__fastcall *)(UFG::AimingPlayerComponent *))this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[19].__vecDelDtor)(this);
  v3 = *(float *)&v2;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
  y_low = (__m128)LODWORD(mCurrentCamera->mCamera.mView.v2.y);
  v6 = mCurrentCamera->mCamera.mView.v2.x - this->m_vAimPosition.x;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_vAimPosition.y)
                                    * (float)(y_low.m128_f32[0] - this->m_vAimPosition.y))
                            + (float)(v6 * v6))
                    + (float)((float)(mCurrentCamera->mCamera.mView.v2.z - this->m_vAimPosition.z)
                            * (float)(mCurrentCamera->mCamera.mView.v2.z - this->m_vAimPosition.z));
  return _mm_sqrt_ps(y_low).m128_f32[0] * tanf(v3);
}

// File Line: 2575
// RVA: 0x520860
void __fastcall UFG::AimingPlayerComponent::AddAimingSoftLockTask(
        UFG::AimingPlayerComponent *this,
        AimingSoftLockTask *pAimingSoftLockTask)
{
  UFG::GameStatTracker *v4; // rax
  bool Stat; // al
  UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *mPrev; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  v4 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v4, AimSoftLockEnabled);
  if ( !UFG::AimingPlayerComponent::ms_bTrackSoftLockDisabled && Stat )
  {
    mPrev = this->m_AimingSoftLockTaskList.mNode.mPrev;
    mPrev->mNext = &pAimingSoftLockTask->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>;
    pAimingSoftLockTask->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>::mPrev = mPrev;
    pAimingSoftLockTask->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>::mNext = &this->m_AimingSoftLockTaskList.mNode;
    this->m_AimingSoftLockTaskList.mNode.mPrev = &pAimingSoftLockTask->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>;
    if ( this->m_eSoftLockType == eSOFT_LOCK_NONE
      && !BYTE2(this->m_pTSPPC.m_pSimComponent[52].m_BoundComponentHandles.mNode.mPrev) )
    {
      y = this->m_vFreeAimTargetPosition.y;
      z = this->m_vFreeAimTargetPosition.z;
      this->m_vSoftLockOffset.x = this->m_vFreeAimTargetPosition.x;
      this->m_vSoftLockOffset.y = y;
      this->m_vSoftLockOffset.z = z;
      this->m_bResetSoftLockOffset = 1;
      this->m_eSoftLockType = eSOFT_LOCK_ABSOLUTE;
    }
  }
}

// File Line: 2595
// RVA: 0x520820
void __fastcall UFG::AimingPlayerComponent::AddAimingFreeAimConeClampTask(
        UFG::AimingPlayerComponent *this,
        AimingFreeAimConeClampTask *pAimingFreeAimConeClampTask)
{
  UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *v2; // rdx
  UFG::qList<AimingFreeAimConeClampTask,AimingFreeAimConeClampList,0,0> *p_m_AimingFreeAimConeClampTaskList; // rcx
  UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *mPrev; // rax

  v2 = &pAimingFreeAimConeClampTask->UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList>;
  p_m_AimingFreeAimConeClampTaskList = &this->m_AimingFreeAimConeClampTaskList;
  mPrev = p_m_AimingFreeAimConeClampTaskList->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_m_AimingFreeAimConeClampTaskList->mNode;
  p_m_AimingFreeAimConeClampTaskList->mNode.mPrev = v2;
}

// File Line: 2602
// RVA: 0x54FCE0
void __fastcall UFG::AimingPlayerComponent::SnapAccuracy(UFG::AimingPlayerComponent *this, float fAccuracy)
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

