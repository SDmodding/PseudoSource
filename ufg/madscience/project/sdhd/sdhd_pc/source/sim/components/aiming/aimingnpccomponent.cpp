// File Line: 31
// RVA: 0x532650
__int64 __fastcall UFG::AimingNPCComponent::GetTypeSize(UFG::AimingNPCComponent *this)
{
  return 456i64;
}

// File Line: 53
// RVA: 0x545C90
UFG::AimingNPCComponent *__fastcall UFG::AimingNPCComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimComponent *v4; // rsi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v10; // r8
  unsigned int v11; // ecx
  unsigned int v12; // r9d
  unsigned int v13; // ecx
  unsigned int v14; // r9d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v19; // rax
  unsigned int v20; // ebx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-30h] BYREF

  m_pSimObject = pSceneObj->m_pSimObject;
  v4 = 0i64;
  if ( !m_pSimObject )
    goto LABEL_30;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[47].m_pComponent;
    goto LABEL_28;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v10 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::AimingBaseComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_12;
      }
LABEL_11:
      m_pComponent = p[v10].m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v10 = v11;
        if ( (p[v11].m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::AimingBaseComponent::_TypeUID & ~p[v11].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_11;
        }
        if ( ++v11 >= v12 )
          goto LABEL_12;
      }
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pSimObject[1].vfptr;
    v14 = m_pSimObject->m_Components.size;
    if ( v13 < v14 )
    {
      p = m_pSimObject->m_Components.p;
      do
      {
        v10 = v13;
        if ( (p[v13].m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::AimingBaseComponent::_TypeUID & ~p[v13].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_11;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_12:
    m_pComponent = 0i64;
    goto LABEL_28;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AimingBaseComponent::_TypeUID);
LABEL_28:
  if ( m_pComponent )
    return 0i64;
LABEL_30:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1C8ui64, "AimingNPCComponent", 0i64, 1u);
  if ( v17 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::AimingNPCComponent::AimingNPCComponent(
      (UFG::AimingNPCComponent *)v17,
      pSceneObj->m_NameUID,
      mpWritableProperties);
    v4 = v19;
  }
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v20 = 47;
  else
    v20 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v21, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, v4, v20);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  return (UFG::AimingNPCComponent *)v4;
}

// File Line: 71
// RVA: 0x154CB90
__int64 UFG::_dynamic_initializer_for__symBaseAccuracy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BaseAIAimingAccuracy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBaseAccuracy, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symBaseAccuracy__);
}

// File Line: 72
// RVA: 0x154CBD0
__int64 UFG::_dynamic_initializer_for__symBaseAccuracyVersusNPC__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BaseAIAimingAccuracyVersusNPC", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBaseAccuracyVersusNPC, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symBaseAccuracyVersusNPC__);
}

// File Line: 75
// RVA: 0x56BFB0
void __fastcall UFG::AimingNPCComponent::propertiesLoad(UFG::AimingNPCComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::qPropertySet *mpConstProperties; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  float *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SceneObjectProperties *v8; // rax
  float *v9; // rax

  m_pSimObject = this->m_pSimObject;
  mpConstProperties = 0i64;
  if ( m_pSimObject && (m_pSceneObj = m_pSimObject->m_pSceneObj) != 0i64 )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  this->m_fBaseAIAccuracy = -1.0;
  this->m_fPlayerDodgeFactor = 0.0;
  if ( mpWritableProperties )
  {
    v6 = UFG::qPropertySet::Get<float>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&UFG::symBaseAccuracy,
           DEPTH_RECURSE);
    if ( v6 )
      this->m_fBaseAIAccuracy = *v6;
  }
  v7 = this->m_pSimObject;
  if ( v7 )
  {
    v8 = v7->m_pSceneObj;
    if ( v8 )
    {
      mpConstProperties = v8->mpWritableProperties;
      if ( !mpConstProperties )
        mpConstProperties = v8->mpConstProperties;
    }
  }
  this->m_fBaseAIAccuracyVersusNPC = this->m_fBaseAIAccuracy;
  if ( mpConstProperties )
  {
    v9 = UFG::qPropertySet::Get<float>(
           mpConstProperties,
           (UFG::qArray<unsigned long,0> *)&UFG::symBaseAccuracyVersusNPC,
           DEPTH_RECURSE);
    if ( v9 )
      this->m_fBaseAIAccuracyVersusNPC = *v9;
  }
}

// File Line: 117
// RVA: 0x515730
void __fastcall UFG::AimingNPCComponent::AimingNPCComponent(
        UFG::AimingNPCComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::AimingBaseComponent::AimingBaseComponent(this, name_uid, properties, 0);
  this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingNPCComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingNPCComponent::`vftable{for `UFG::UpdateInterface};
  this->m_fBaseAIAccuracy = -1.0;
  this->m_fBaseAIAccuracyVersusNPC = -1.0;
  this->m_fPlayerDodgeFactor = 0.0;
  this->m_pSimTargetAimPos.mPrev = &this->m_pSimTargetAimPos;
  this->m_pSimTargetAimPos.mNext = &this->m_pSimTargetAimPos;
  this->m_pSimTargetAimPos.m_pPointer = 0i64;
  UFG::SimComponent::AddType(this, UFG::AimingNPCComponent::_AimingNPCComponentTypeUID, "AimingNPCComponent");
}

// File Line: 144
// RVA: 0x51A940
void __fastcall UFG::AimingNPCComponent::~AimingNPCComponent(UFG::AimingNPCComponent *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimTargetAimPos; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingNPCComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingNPCComponent::`vftable{for `UFG::UpdateInterface};
  m_pPointer = this->m_pSimTargetAimPos.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pSimTargetAimPos = &this->m_pSimTargetAimPos;
    if ( this->m_pSimTargetAimPos.m_pPointer )
    {
      mPrev = p_m_pSimTargetAimPos->mPrev;
      mNext = this->m_pSimTargetAimPos.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pSimTargetAimPos->mPrev = p_m_pSimTargetAimPos;
      this->m_pSimTargetAimPos.mNext = &this->m_pSimTargetAimPos;
    }
    this->m_pSimTargetAimPos.m_pPointer = 0i64;
  }
  v6 = &this->m_pSimTargetAimPos;
  if ( this->m_pSimTargetAimPos.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = this->m_pSimTargetAimPos.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    this->m_pSimTargetAimPos.mNext = &this->m_pSimTargetAimPos;
  }
  this->m_pSimTargetAimPos.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = this->m_pSimTargetAimPos.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = v6;
  this->m_pSimTargetAimPos.mNext = &this->m_pSimTargetAimPos;
  UFG::AimingBaseComponent::~AimingBaseComponent(this);
}

// File Line: 157
// RVA: 0x53D0A0
void __fastcall UFG::AimingNPCComponent::OnAttach(UFG::AimingNPCComponent *this, UFG::SimObject *pSimObject)
{
  UFG::AimingBaseComponent::OnAttach(this, pSimObject);
  UFG::AimingNPCComponent::propertiesLoad(this);
}

// File Line: 166
// RVA: 0x53FBB0
void __fastcall UFG::AimingNPCComponent::OnDetach(UFG::AimingNPCComponent *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimTargetAimPos; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  UFG::AimingBaseComponent::OnDetach(this);
  m_pPointer = this->m_pSimTargetAimPos.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pSimTargetAimPos = &this->m_pSimTargetAimPos;
    if ( this->m_pSimTargetAimPos.m_pPointer )
    {
      mPrev = p_m_pSimTargetAimPos->mPrev;
      mNext = this->m_pSimTargetAimPos.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pSimTargetAimPos->mPrev = p_m_pSimTargetAimPos;
      this->m_pSimTargetAimPos.mNext = &this->m_pSimTargetAimPos;
    }
    this->m_pSimTargetAimPos.m_pPointer = 0i64;
  }
}

// File Line: 179
// RVA: 0x5586D0
void __fastcall UFG::AimingNPCComponent::Update(UFG::AimingNPCComponent *this, float fDeltaS)
{
  UFG::TransformNodeComponent *v2; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // rdx
  UFG::AimingBaseComponent *v5; // rcx
  int mNext; // xmm0_4
  int mNext_high; // xmm1_4
  __m128 m_pSimObject_low; // xmm2
  float v9; // xmm0_4
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-58h] BYREF

  v2 = *(UFG::TransformNodeComponent **)&this->m_Accuracy.m_bEnsureMiss;
  UFG::TransformNodeComponent::UpdateWorldTransform(v2);
  p_mWorldTransform = &v2->mWorldTransform;
  v5 = (UFG::AimingNPCComponent *)((char *)this - 64);
  if ( LOBYTE(this->m_TransformNodeComponent.mNext[35].mPrev) )
  {
    UFG::AimingBaseComponent::updateAimOriginPosition(v5, p_mWorldTransform);
    UFG::AimingNPCComponent::updateAimIntentionTargetPosition(
      (UFG::AimingNPCComponent *)((char *)this - 64),
      &v2->mWorldTransform);
    UFG::AimingBaseComponent::clampAimIntentionTargetPositionDistance((UFG::AimingNPCComponent *)((char *)this - 64));
    UFG::AimingBaseComponent::updateAimIntention((UFG::AimingNPCComponent *)((char *)this - 64), fDeltaS);
    UFG::AimingBaseComponent::clampAimIntention((UFG::AimingNPCComponent *)((char *)this - 64), &v2->mWorldTransform);
    UFG::AimingBaseComponent::updateAimDirection(
      (UFG::AimingNPCComponent *)((char *)this - 64),
      fDeltaS,
      &v2->mWorldTransform);
    UFG::AimingBaseComponent::updateAimPosition((UFG::AimingNPCComponent *)((char *)this - 64), &v2->mWorldTransform);
    UFG::AimingNPCComponent::updateAccuracy((UFG::AimingNPCComponent *)((char *)this - 64), fDeltaS);
  }
  else
  {
    UFG::AimingBaseComponent::updateAimOriginPosition(v5, p_mWorldTransform);
    UFG::AimingBaseComponent::GetTargetNormalAimPosition(
      (UFG::AimingNPCComponent *)((char *)this - 64),
      (UFG::qVector3 *)((char *)&this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev
                      + 4),
      0x16u,
      &v2->mWorldTransform);
    UFG::AimingBaseComponent::updateAimIntention((UFG::AimingNPCComponent *)((char *)this - 64), fDeltaS);
    mNext = (int)this->m_BoundComponentHandles.mNode.mNext;
    mNext_high = HIDWORD(this->m_BoundComponentHandles.mNode.mNext);
    LODWORD(this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr) = HIDWORD(this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev);
    HIDWORD(this->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr) = mNext;
    LODWORD(this->mPrev) = mNext_high;
    this->m_NameUID = -1082130432;
    *(_DWORD *)&this->m_Flags = 1065353216;
    UFG::qTranspose(&dest, &v2->mWorldTransform);
    UFG::AimingBaseComponent::UpdateLocalAimDirection(
      (UFG::AimingNPCComponent *)((char *)this - 64),
      &dest,
      (UFG::qVector3 *)&this->UFG::UpdateInterface);
    m_pSimObject_low = (__m128)LODWORD(this->m_pSimObject);
    v9 = *((float *)&this->m_pSimObject + 1) - *(float *)&this->m_BoundComponentHandles.mNode.mNext;
    m_pSimObject_low.m128_f32[0] = (float)((float)((float)(m_pSimObject_low.m128_f32[0]
                                                         - *((float *)&this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev
                                                           + 1))
                                                 * (float)(m_pSimObject_low.m128_f32[0]
                                                         - *((float *)&this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev
                                                           + 1)))
                                         + (float)(v9 * v9))
                                 + (float)((float)(*(float *)&this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev
                                                 - *((float *)&this->m_BoundComponentHandles.mNode.mNext + 1))
                                         * (float)(*(float *)&this->m_BoundComponentHandles.mNode.UFG::AimingBaseComponent::UFG::SimComponent::mPrev
                                                 - *((float *)&this->m_BoundComponentHandles.mNode.mNext + 1)));
    this->m_TypeUID = _mm_sqrt_ps(m_pSimObject_low).m128_u32[0];
  }
}

// File Line: 236
// RVA: 0x56DE10
void __fastcall UFG::AimingNPCComponent::updateAccuracy(UFG::AimingNPCComponent *this, const float fDeltaS)
{
  float m_fAccuracyUnclamped; // xmm12_4
  float m_fAccuracyPenalty; // xmm13_4
  UFG::SimComponent *v6; // rsi
  float m_fAccuracyOverride; // xmm0_4
  UFG::SimComponent *m_pSimComponent; // rdx
  float v9; // xmm11_4
  float v10; // xmm6_4
  UFG::SimObjectCharacter *v11; // rbx
  __int16 m_Flags; // cx
  UFG::AimingBaseComponent *m_pComponent; // rax
  unsigned int v14; // r8d
  unsigned int v15; // r10d
  __int64 v16; // rdx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  unsigned int v19; // r8d
  unsigned int v20; // r10d
  __int16 v21; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v23; // r8d
  unsigned int v24; // r10d
  __int64 v25; // rdx
  unsigned int v26; // r8d
  unsigned int v27; // r10d
  unsigned int v28; // r8d
  unsigned int v29; // r10d
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 y_low; // xmm2
  float v32; // xmm6_4
  __m128 v33; // xmm8
  float v34; // xmm9_4
  float v35; // xmm10_4
  __m128 v36; // xmm2
  float v37; // xmm1_4
  float v38; // xmm6_4
  float v39; // xmm8_4
  float v40; // xmm9_4
  float v41; // xmm5_4
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  UFG::SimObject *m_pSimObject; // rcx
  float m_fDefaultAccuracyRate; // xmm6_4
  __int16 v48; // dx
  unsigned int vfptr; // r8d
  unsigned int v50; // r10d
  __int64 v51; // rdx
  unsigned int v52; // r8d
  unsigned int v53; // r10d
  unsigned int v54; // r8d
  unsigned int v55; // r10d
  unsigned int v56; // r8d
  unsigned int v57; // r10d
  __int64 v58; // rax
  __int64 v59; // rax
  __int64 v60; // rdx
  int v61; // xmm0_4
  int v62; // xmm0_4
  float v63; // xmm6_4
  float fAccuracyModifierContinuous; // [rsp+C0h] [rbp+8h] BYREF
  float fAccuracyModifierInstant; // [rsp+D0h] [rbp+18h] BYREF

  m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyUnclamped;
  if ( m_fAccuracyUnclamped <= this->m_Accuracy.m_fAccuracyMinimum )
    m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMinimum;
  if ( m_fAccuracyUnclamped >= this->m_Accuracy.m_fAccuracyMaximum )
    m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMaximum;
  m_fAccuracyPenalty = this->m_Accuracy.m_fAccuracyPenalty;
  v6 = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyMaximum = 1065353216i64;
  m_fAccuracyOverride = this->m_Accuracy.m_fAccuracyOverride;
  fAccuracyModifierContinuous = 0.0;
  fAccuracyModifierInstant = 0.0;
  if ( m_fAccuracyOverride < 0.0 )
  {
    m_pSimComponent = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
    v9 = *(float *)&FLOAT_1_0;
    v10 = 0.0;
    if ( !m_pSimComponent )
      goto LABEL_133;
    v11 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 30i64)
                                      + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                                      + 40);
    if ( !v11 )
      goto LABEL_79;
    m_Flags = v11->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::AimingBaseComponent *)v11->m_Components.p[47].m_pComponent;
      goto LABEL_38;
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        mComponentTableEntryCount = v11->mComponentTableEntryCount;
        size = v11->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          v16 = (__int64)&v11->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v16 += 16i64;
            if ( mComponentTableEntryCount >= size )
            {
              m_pComponent = 0i64;
              goto LABEL_38;
            }
          }
          goto LABEL_22;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                       v11,
                                                       UFG::AimingBaseComponent::_TypeUID);
LABEL_38:
          if ( m_pComponent )
            UFG::AimingBaseComponent::ApplyAccuracyModifiers(
              m_pComponent,
              1,
              &fAccuracyModifierInstant,
              &fAccuracyModifierContinuous);
          if ( !UFG::IsAnyLocalPlayer(v11) )
            goto LABEL_78;
          v21 = v11->m_Flags;
          if ( (v21 & 0x4000) != 0 )
          {
            ComponentOfType = v11->m_Components.p[44].m_pComponent;
            goto LABEL_66;
          }
          if ( v21 >= 0 )
          {
            if ( (v21 & 0x2000) != 0 )
            {
              v26 = v11->mComponentTableEntryCount;
              v27 = v11->m_Components.size;
              if ( v26 < v27 )
              {
                v25 = (__int64)&v11->m_Components.p[v26];
                while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                     || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v26;
                  v25 += 16i64;
                  if ( v26 >= v27 )
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
              if ( (v21 & 0x1000) == 0 )
              {
                ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_66:
                if ( !ComponentOfType )
                {
                  m_pTransformNodeComponent = v11->m_pTransformNodeComponent;
                  if ( m_pTransformNodeComponent )
                  {
                    y_low = (__m128)LODWORD(this->m_vAimOriginPosition.y);
                    v33 = (__m128)LODWORD(this->m_vAimIntentionTargetPosition.y);
                    v32 = this->m_vAimIntentionTargetPosition.x - this->m_vAimOriginPosition.x;
                    v33.m128_f32[0] = v33.m128_f32[0] - this->m_vAimOriginPosition.y;
                    v34 = this->m_vAimIntentionTargetPosition.z - this->m_vAimOriginPosition.z;
                    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y)
                                                      * (float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y))
                                              + (float)((float)(this->m_vAimOriginPosition.x
                                                              - this->m_vAimIntentionTargetPosition.x)
                                                      * (float)(this->m_vAimOriginPosition.x
                                                              - this->m_vAimIntentionTargetPosition.x)))
                                      + (float)((float)(this->m_vAimOriginPosition.z
                                                      - this->m_vAimIntentionTargetPosition.z)
                                              * (float)(this->m_vAimOriginPosition.z
                                                      - this->m_vAimIntentionTargetPosition.z));
                    LODWORD(v35) = _mm_sqrt_ps(y_low).m128_u32[0];
                    v36 = v33;
                    v36.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32))
                                    + (float)(v34 * v34);
                    if ( v36.m128_f32[0] == 0.0 )
                      v37 = 0.0;
                    else
                      v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
                    v38 = v32 * v37;
                    v39 = v33.m128_f32[0] * v37;
                    v40 = v34 * v37;
                    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                    v41 = (float)((float)(m_pTransformNodeComponent->mWorldVelocity.y * v39)
                                + (float)(m_pTransformNodeComponent->mWorldVelocity.x * v38))
                        + (float)(m_pTransformNodeComponent->mWorldVelocity.z * v40);
                    v42 = (float)((float)((float)(m_pTransformNodeComponent->mWorldVelocity.y - (float)(v39 * v41))
                                        * (float)(m_pTransformNodeComponent->mWorldVelocity.y - (float)(v39 * v41)))
                                + (float)((float)(m_pTransformNodeComponent->mWorldVelocity.x - (float)(v38 * v41))
                                        * (float)(m_pTransformNodeComponent->mWorldVelocity.x - (float)(v38 * v41))))
                        + (float)((float)(m_pTransformNodeComponent->mWorldVelocity.z - (float)(v40 * v41))
                                * (float)(m_pTransformNodeComponent->mWorldVelocity.z - (float)(v40 * v41)));
                    v43 = v42
                        / (float)(UFG::AimingNPCComponent::ms_fPlayerDodgeFactorLateralSpeed
                                * UFG::AimingNPCComponent::ms_fPlayerDodgeFactorLateralSpeed);
                    if ( v43 > 1.0 )
                      v43 = *(float *)&FLOAT_1_0;
                    this->m_fPlayerDodgeFactor = v43 * UFG::AimingNPCComponent::ms_fPlayerDodgeFactorLateral;
                    if ( v35 < UFG::AimingNPCComponent::ms_fPlayerRushDistance && v41 < -5.0 && v42 < 1.0 )
                      this->m_fPlayerDodgeFactor = UFG::AimingNPCComponent::ms_fPlayerDodgeFactorRush;
                    if ( UFG::AimingNPCComponent::ms_fPlayerDodgeFactorMinCutoff > this->m_fPlayerDodgeFactor )
LABEL_78:
                      this->m_fPlayerDodgeFactor = 0.0;
                  }
                }
LABEL_79:
                UFG::AimingBaseComponent::ApplyAccuracyModifiers(
                  this,
                  0,
                  &fAccuracyModifierInstant,
                  &fAccuracyModifierContinuous);
                if ( fAccuracyModifierContinuous <= 0.0 )
                {
                  if ( fAccuracyModifierContinuous < 0.0 )
                  {
                    v45 = fAccuracyModifierContinuous + this->m_Accuracy.m_fAccuracyMaximum;
                    if ( v45 <= 0.0 )
                      v45 = 0.0;
                    this->m_Accuracy.m_fAccuracyMaximum = v45;
                  }
                }
                else
                {
                  v44 = fAccuracyModifierContinuous + this->m_Accuracy.m_fAccuracyMinimum;
                  if ( v44 >= 1.0 )
                    v44 = *(float *)&FLOAT_1_0;
                  this->m_Accuracy.m_fAccuracyMinimum = v44;
                }
                m_pSimObject = this->m_pSimObject;
                m_fDefaultAccuracyRate = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fDefaultAccuracyRate;
                if ( !m_pSimObject )
                  goto LABEL_122;
                v48 = m_pSimObject->m_Flags;
                if ( (v48 & 0x4000) != 0 )
                {
                  vfptr = (unsigned int)m_pSimObject[1].vfptr;
                  v50 = m_pSimObject->m_Components.size;
                  if ( vfptr < v50 )
                  {
                    v51 = (__int64)&m_pSimObject->m_Components.p[vfptr];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++vfptr;
                      v51 += 16i64;
                      if ( vfptr >= v50 )
                        goto LABEL_118;
                    }
LABEL_95:
                    v6 = *(UFG::SimComponent **)v51;
                  }
                }
                else
                {
                  if ( v48 < 0 )
                  {
                    v52 = (unsigned int)m_pSimObject[1].vfptr;
                    v53 = m_pSimObject->m_Components.size;
                    if ( v52 >= v53 )
                      goto LABEL_118;
                    v51 = (__int64)&m_pSimObject->m_Components.p[v52];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++v52;
                      v51 += 16i64;
                      if ( v52 >= v53 )
                        goto LABEL_118;
                    }
                    goto LABEL_95;
                  }
                  if ( (v48 & 0x2000) != 0 )
                  {
                    v54 = (unsigned int)m_pSimObject[1].vfptr;
                    v55 = m_pSimObject->m_Components.size;
                    if ( v54 >= v55 )
                      goto LABEL_118;
                    v51 = (__int64)&m_pSimObject->m_Components.p[v54];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++v54;
                      v51 += 16i64;
                      if ( v54 >= v55 )
                        goto LABEL_118;
                    }
                    goto LABEL_95;
                  }
                  if ( (v48 & 0x1000) == 0 )
                  {
                    v6 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TriadWarsComponent::_TypeUID);
                    goto LABEL_118;
                  }
                  v56 = (unsigned int)m_pSimObject[1].vfptr;
                  v57 = m_pSimObject->m_Components.size;
                  if ( v56 < v57 )
                  {
                    v51 = (__int64)&m_pSimObject->m_Components.p[v56];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++v56;
                      v51 += 16i64;
                      if ( v56 >= v57 )
                        goto LABEL_118;
                    }
                    goto LABEL_95;
                  }
                }
LABEL_118:
                if ( v6 )
                {
                  if ( LODWORD(v6[1].m_BoundComponentHandles.mNode.mPrev) != -1 )
                  {
                    v58 = *(_QWORD *)&v6[1].m_Flags;
                    if ( v58 )
                      m_fDefaultAccuracyRate = *(float *)(v58 + 88);
                  }
                }
LABEL_122:
                v59 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
                if ( v59 )
                {
                  v60 = *(_QWORD *)(*(_QWORD *)(v59 + 176) + 8i64 * *(unsigned int *)(v59 + 172) + 8);
                  if ( *(_DWORD *)(v60 + 100) != UFG::gNullQSymbolUC.mUID )
                    m_fDefaultAccuracyRate = m_fDefaultAccuracyRate * *(float *)(v60 + 168);
                }
                *(float *)&v61 = m_fAccuracyPenalty;
                if ( m_fAccuracyPenalty < 0.0 )
                  v61 = LODWORD(m_fAccuracyPenalty) ^ _xmm[0];
                if ( *(float *)&v61 >= 0.001 )
                  goto LABEL_132;
                *(float *)&v62 = fAccuracyModifierInstant;
                if ( fAccuracyModifierInstant < 0.0 )
                  v62 = LODWORD(fAccuracyModifierInstant) ^ _xmm[0];
                if ( *(float *)&v62 >= 0.001 )
LABEL_132:
                  v10 = COERCE_FLOAT(LODWORD(m_fAccuracyPenalty) ^ _xmm[0]) + fAccuracyModifierInstant;
                else
                  v10 = m_fDefaultAccuracyRate * fDeltaS;
LABEL_133:
                v63 = v10 + m_fAccuracyUnclamped;
                if ( v63 <= 0.0 )
                {
                  v63 = 0.0;
                }
                else if ( v63 >= 1.0 )
                {
                  goto LABEL_138;
                }
                v9 = v63;
LABEL_138:
                this->m_Accuracy.m_fAccuracyUnclamped = v9;
                return;
              }
              v28 = v11->mComponentTableEntryCount;
              v29 = v11->m_Components.size;
              if ( v28 < v29 )
              {
                v25 = (__int64)&v11->m_Components.p[v28];
                while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                     || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v28;
                  v25 += 16i64;
                  if ( v28 >= v29 )
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
            v23 = v11->mComponentTableEntryCount;
            v24 = v11->m_Components.size;
            if ( v23 < v24 )
            {
              v25 = (__int64)&v11->m_Components.p[v23];
              while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                   || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v23;
                v25 += 16i64;
                if ( v23 >= v24 )
                  goto LABEL_49;
              }
LABEL_50:
              ComponentOfType = *(UFG::SimComponent **)v25;
              goto LABEL_66;
            }
          }
LABEL_49:
          ComponentOfType = 0i64;
          goto LABEL_66;
        }
        v19 = v11->mComponentTableEntryCount;
        v20 = v11->m_Components.size;
        if ( v19 < v20 )
        {
          v16 = (__int64)&v11->m_Components.p[v19];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v19;
            v16 += 16i64;
            if ( v19 >= v20 )
            {
              m_pComponent = 0i64;
              goto LABEL_38;
            }
          }
          goto LABEL_22;
        }
      }
    }
    else
    {
      v14 = v11->mComponentTableEntryCount;
      v15 = v11->m_Components.size;
      if ( v14 < v15 )
      {
        v16 = (__int64)&v11->m_Components.p[v14];
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v14;
          v16 += 16i64;
          if ( v14 >= v15 )
            goto LABEL_21;
        }
LABEL_22:
        m_pComponent = *(UFG::AimingBaseComponent **)v16;
        goto LABEL_38;
      }
    }
LABEL_21:
    m_pComponent = 0i64;
    goto LABEL_38;
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
}

// File Line: 384
// RVA: 0x56F9C0
void __fastcall UFG::AimingNPCComponent::updateAimIntentionTargetPosition(
        UFG::AimingNPCComponent *this,
        UFG::qMatrix44 *matXform)
{
  UFG::SimComponent *m_pSimComponent; // r14
  UFG::SimObjectProp *v4; // rbx
  __int64 v5; // rax
  UFG::SubTargetingLocation *v6; // r12
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdi
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v11; // rdx
  __int16 v12; // dx
  UFG::CharacterAnimationComponent *v13; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  __int64 v17; // rdx
  Creature *pCreature; // r15
  UFG::SubTargetingProfile *v19; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  double WeaponProjectileSpeed; // xmm0_8
  __m128 x_low; // xmm3
  float v24; // xmm1_4
  UFG::SimObject *m_pPointer; // rdx
  UFG::qVector3 *p_m_vAimIntentionTargetPosition; // r8
  unsigned __int8 v27; // cl
  UFG::qVector3 vSubTargetingLocationWS; // [rsp+30h] [rbp-28h] BYREF

  UFG::AimingBaseComponent::GetTargetNormalAimPosition(this, &this->m_vAimIntentionTargetPosition, 0x16u, matXform);
  m_pSimComponent = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( LOBYTE(m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev) && m_pSimComponent )
  {
    v4 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 30i64)
                                + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                                + 40);
    if ( !v4 )
      goto LABEL_52;
    v5 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    if ( v5 )
      v6 = *(UFG::SubTargetingLocation **)(v5 + 2736);
    else
      v6 = 0i64;
    if ( !v6 )
      goto LABEL_51;
    m_Flags = v4->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v4->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v4->m_Components.p[4].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = v4->mComponentTableEntryCount;
        size = v4->m_Components.size;
        if ( mComponentTableEntryCount >= size )
        {
LABEL_20:
          m_pComponent = 0i64;
        }
        else
        {
          v11 = (__int64)&v4->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v11 += 16i64;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_20;
          }
          m_pComponent = *(UFG::SimComponent **)v11;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v4, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v4->m_Components.p[3].m_pComponent;
    }
    if ( !m_pComponent
      || !((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[14].__vecDelDtor)(m_pComponent) )
    {
LABEL_51:
      WeaponProjectileSpeed = UFG::AimingBaseComponent::GetWeaponProjectileSpeed(this);
      x_low = (__m128)LODWORD(this->m_vAimOriginPosition.x);
      x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.x)
                                        * (float)(x_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.x))
                                + (float)((float)(this->m_vAimOriginPosition.y - this->m_vAimIntentionTargetPosition.y)
                                        * (float)(this->m_vAimOriginPosition.y - this->m_vAimIntentionTargetPosition.y)))
                        + (float)((float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z)
                                * (float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z));
      UFG::AimingBaseComponent::getPredictedPositionOffset(
        this,
        &vSubTargetingLocationWS,
        v4,
        *(float *)&WeaponProjectileSpeed,
        _mm_sqrt_ps(x_low).m128_f32[0]);
      v24 = vSubTargetingLocationWS.y + this->m_vAimIntentionTargetPosition.y;
      this->m_vAimIntentionTargetPosition.x = vSubTargetingLocationWS.x + this->m_vAimIntentionTargetPosition.x;
      *(float *)&WeaponProjectileSpeed = vSubTargetingLocationWS.z + this->m_vAimIntentionTargetPosition.z;
      this->m_vAimIntentionTargetPosition.y = v24;
      this->m_vAimIntentionTargetPosition.z = *(float *)&WeaponProjectileSpeed;
LABEL_52:
      m_pPointer = this->m_pSimTargetAimPos.m_pPointer;
      p_m_vAimIntentionTargetPosition = &this->m_vAimIntentionTargetPosition;
      if ( m_pPointer )
      {
        UFG::AimingNPCComponent::updateSimTarget(
          (UFG::AICoverComponent *)this,
          m_pPointer,
          p_m_vAimIntentionTargetPosition);
      }
      else
      {
        UFG::AimingNPCComponent::generateSimTarget(this, &this->m_pSimTargetAimPos, p_m_vAimIntentionTargetPosition);
        v27 = *(_BYTE *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 11i64);
        if ( v27 )
          UFG::TargetingSimObject::SetTarget(
            (UFG::TargetingSimObject *)(*(_QWORD *)&m_pSimComponent[1].m_TypeUID + 56i64 * v27),
            this->m_pSimTargetAimPos.m_pPointer);
      }
      return;
    }
    v12 = v4->m_Flags;
    if ( (v12 & 0x4000) != 0 )
    {
      v13 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
      if ( v13
        && ((UFG::CharacterAnimationComponent::_TypeUID ^ v13->m_TypeUID) & 0xFE000000) == 0
        && (UFG::CharacterAnimationComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) == 0 )
      {
LABEL_47:
        if ( v13 )
        {
          pCreature = v13->mCreature;
          if ( pCreature )
          {
            v19 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[14].__vecDelDtor)(m_pComponent);
            if ( UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                   v19,
                   &vSubTargetingLocationWS,
                   v6,
                   v4,
                   pCreature) )
            {
              y = vSubTargetingLocationWS.y;
              this->m_vAimIntentionTargetPosition.x = vSubTargetingLocationWS.x;
              z = vSubTargetingLocationWS.z;
              this->m_vAimIntentionTargetPosition.y = y;
              this->m_vAimIntentionTargetPosition.z = z;
            }
          }
        }
        goto LABEL_51;
      }
LABEL_29:
      v13 = 0i64;
      goto LABEL_47;
    }
    if ( v12 < 0 )
    {
      v13 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
      if ( v13 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v13->m_TypeUID) & 0xFE000000) == 0 )
      {
        if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
          v13 = 0i64;
        goto LABEL_47;
      }
      goto LABEL_29;
    }
    if ( (v12 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    else
    {
      if ( (v12 & 0x1000) != 0 )
      {
        v15 = v4->mComponentTableEntryCount;
        v16 = v4->m_Components.size;
        if ( v15 < v16 )
        {
          v17 = (__int64)&v4->m_Components.p[v15];
          while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v15;
            v17 += 16i64;
            if ( v15 >= v16 )
            {
              v13 = 0i64;
              goto LABEL_47;
            }
          }
          v13 = *(UFG::CharacterAnimationComponent **)v17;
          goto LABEL_47;
        }
        goto LABEL_29;
      }
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              v4,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    v13 = ComponentOfType;
    goto LABEL_47;
  }
}

// File Line: 447
// RVA: 0x1549B40
__int64 UFG::_dynamic_initializer_for__guidTransformNodeComponent__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
  UFG::guidTransformNodeComponent = result;
  return result;
}

// File Line: 450
// RVA: 0x5681D0
void __fastcall UFG::AimingNPCComponent::generateSimTarget(
        UFG::AimingNPCComponent *this,
        UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *destPointer,
        UFG::qVector3 *vPosition)
{
  __int64 v5; // r8
  UFG::qSymbol *v6; // rax
  UFG::SimObject *SimObject; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::TransformNodeComponent *v14; // rax
  UFG::TransformNodeComponent *v15; // rdi
  UFG::SimObject *m_pPointer; // rdx
  __int16 m_Flags; // cx
  unsigned int v18; // ebx
  UFG::qVector4 v19; // xmm2
  UFG::qMatrix44 m; // [rsp+30h] [rbp-178h] BYREF
  UFG::SimObjectModifier v21; // [rsp+70h] [rbp-138h] BYREF
  __int64 v22; // [rsp+90h] [rbp-118h]
  char pszSymbolString[256]; // [rsp+A0h] [rbp-108h] BYREF
  UFG::allocator::free_link *result; // [rsp+1B8h] [rbp+10h] BYREF

  v22 = -2i64;
  v5 = uUniqueID++;
  UFG::qSPrintf(pszSymbolString, "AimingPosition_%d", v5);
  v6 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, pszSymbolString);
  SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v6);
  if ( destPointer->m_pPointer )
  {
    mPrev = destPointer->mPrev;
    mNext = destPointer->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    destPointer->mPrev = destPointer;
    destPointer->mNext = destPointer;
  }
  destPointer->m_pPointer = SimObject;
  if ( SimObject )
  {
    p_mNode = &SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v11 = SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v11->mNext = destPointer;
    destPointer->mPrev = v11;
    destPointer->mNext = p_mNode;
    p_mNode->mPrev = destPointer;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v13 = UFG::qMemoryPool::Allocate(
          SimulationMemoryPool,
          0x110ui64,
          "AimingPosition Sim Target TransformNodeComponent",
          0i64,
          1u);
  result = v13;
  if ( v13 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v13,
      UFG::guidTransformNodeComponent,
      0i64,
      0);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  m_pPointer = destPointer->m_pPointer;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v18 = 2;
  }
  else
  {
    v18 = -1;
    if ( (m_Flags & 0x1000) != 0 )
      v18 = 1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v21, m_pPointer, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, v15, v18);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  v19 = 0i64;
  v19.x = (float)1;
  m.v0 = v19;
  m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v19, (__m128)v19, 81);
  m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v19, (__m128)v19, 69);
  m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v19, (__m128)v19, 21);
  m.v3.x = vPosition->x;
  m.v3.y = vPosition->y;
  m.v3.z = vPosition->z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform(v15, &m);
}

// File Line: 484
// RVA: 0x52A9F0
float __fastcall UFG::AimingNPCComponent::GetAngularInaccuracyRad(UFG::AimingNPCComponent *this)
{
  __int64 v1; // rax
  float m_fAccuracyUnclamped; // xmm1_4
  __int64 v3; // r8

  v1 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
  if ( !v1 )
    return 0.0;
  m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyUnclamped;
  if ( m_fAccuracyUnclamped <= this->m_Accuracy.m_fAccuracyMinimum )
    m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMinimum;
  if ( m_fAccuracyUnclamped >= this->m_Accuracy.m_fAccuracyMaximum )
    m_fAccuracyUnclamped = this->m_Accuracy.m_fAccuracyMaximum;
  v3 = *(_QWORD *)(*(_QWORD *)(v1 + 176) + 8i64 * *(unsigned int *)(v1 + 172) + 8);
  return (float)((float)(1.0 - m_fAccuracyUnclamped) * *(float *)(v3 + 48))
       + (float)(m_fAccuracyUnclamped * *(float *)(v3 + 44));
}

// File Line: 503
// RVA: 0x52D070
void __fastcall UFG::AimingNPCComponent::GetFiringPositionAtAimPosition(
        UFG::AimingNPCComponent *this,
        UFG::qVector3 *vFiringPositionAtAimPosition)
{
  bool m_bEnsureMiss; // di
  __m128 x_low; // xmm1
  float v6; // xmm13_4
  double v7; // xmm0_8
  float v8; // xmm11_4
  unsigned int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  float v14; // xmm8_4
  float v15; // xmm8_4
  float v16; // xmm8_4
  float v17; // xmm10_4
  float m_fPlayerDodgeFactor; // xmm0_4
  float v19; // xmm12_4
  float v20; // xmm14_4
  float v21; // xmm15_4
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  __m128 v29; // xmm2
  float v30; // xmm9_4
  float v31; // xmm1_4
  float v32; // xmm10_4
  float v33; // xmm9_4
  __m128 v34; // xmm4
  float v35; // xmm0_4
  __m128 v36; // xmm4
  __m128 v37; // xmm11
  float v38; // xmm13_4
  float v39; // xmm4_4
  float v40; // xmm9_4
  __m128 v41; // xmm10
  float v42; // xmm8_4
  __m128 v43; // xmm2
  float v44; // xmm7_4
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+28h] [rbp-D0h] BYREF
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+38h] [rbp-C0h] BYREF
  float v47; // [rsp+100h] [rbp+8h]
  float v48; // [rsp+108h] [rbp+10h]

  m_bEnsureMiss = this->m_Accuracy.m_bEnsureMiss;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, &vWeaponProjectileSpawnPosition);
  x_low = (__m128)LODWORD(this->m_vAimOriginPosition.x);
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.x)
                                    * (float)(x_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.x))
                            + (float)((float)(this->m_vAimOriginPosition.y - this->m_vAimIntentionTargetPosition.y)
                                    * (float)(this->m_vAimOriginPosition.y - this->m_vAimIntentionTargetPosition.y)))
                    + (float)((float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z)
                            * (float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z));
  LODWORD(v6) = _mm_sqrt_ps(x_low).m128_u32[0];
  v7 = ((double (__fastcall *)(UFG::AimingNPCComponent *))this->UFG::AimingBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[21].__vecDelDtor)(this);
  v8 = *(float *)&v7;
  v9 = _S60;
  if ( (_S60 & 1) == 0 )
  {
    v9 = _S60 | 1;
    _S60 |= 1u;
    s_fDirection = FLOAT_1_5707964;
  }
  if ( (v9 & 2) != 0 )
  {
    v10 = s_fHalfRange;
  }
  else
  {
    _S60 = v9 | 2;
    v10 = FLOAT_1_9198623;
    s_fHalfRange = FLOAT_1_9198623;
  }
  v11 = (float)(UFG::qRandom(v10 * 2.0, (unsigned int *)&UFG::qDefaultSeed) - s_fHalfRange) + s_fDirection;
  v12 = UFG::qRandom(s_fDistanceMax, (unsigned int *)&UFG::qDefaultSeed) + s_fDistanceMin;
  v13 = UFG::qRandom(6.2831855, (unsigned int *)&UFG::qDefaultSeed);
  if ( UFG::AimingNPCComponent::ms_bCorrectDiscPointPicking )
    v14 = fsqrt(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed));
  else
    v14 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
  v15 = v14 * v8;
  if ( m_bEnsureMiss )
  {
    v16 = v12;
    v17 = v11;
  }
  else
  {
    m_fPlayerDodgeFactor = this->m_fPlayerDodgeFactor;
    v16 = v15 + (float)((float)(v12 - v15) * m_fPlayerDodgeFactor);
    v17 = v13 + (float)((float)(v11 - v13) * m_fPlayerDodgeFactor);
  }
  v19 = cosf(v17) * v16;
  v47 = sinf(v17) * v16;
  UFG::AimingBaseComponent::GetWeaponProjectileDirection(this, &vWeaponProjectileDirection);
  v20 = (float)(vWeaponProjectileDirection.x * v6) + vWeaponProjectileSpawnPosition.x;
  v21 = (float)(vWeaponProjectileDirection.y * v6) + vWeaponProjectileSpawnPosition.y;
  v48 = (float)(vWeaponProjectileDirection.z * v6) + vWeaponProjectileSpawnPosition.z;
  v22 = (__m128)LODWORD(vWeaponProjectileDirection.x);
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0])
                          + (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y))
                  + (float)(vWeaponProjectileDirection.z * vWeaponProjectileDirection.z);
  if ( v22.m128_f32[0] == 0.0 )
    v23 = 0.0;
  else
    v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
  v24 = vWeaponProjectileDirection.x * v23;
  v25 = vWeaponProjectileDirection.y * v23;
  v26 = vWeaponProjectileDirection.z * v23;
  v27 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v27.m128_f32[0] == 0.0 )
  {
    v29 = 0i64;
  }
  else
  {
    v28 = _mm_sqrt_ps(v27).m128_f32[0];
    v29 = (__m128)(unsigned int)FLOAT_1_0;
    v29.m128_f32[0] = 1.0 / v28;
  }
  v30 = v29.m128_f32[0] * UFG::qVector3::msDirUp.x;
  v31 = v29.m128_f32[0] * UFG::qVector3::msDirUp.y;
  v29.m128_f32[0] = v29.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v32 = (float)(v31 * v26) - (float)(v29.m128_f32[0] * v25);
  v29.m128_f32[0] = (float)(v29.m128_f32[0] * v24) - (float)(v30 * v26);
  v33 = (float)(v30 * v25) - (float)(v31 * v24);
  v34 = v29;
  v34.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
  if ( v34.m128_f32[0] == 0.0 )
  {
    v36 = 0i64;
  }
  else
  {
    v35 = _mm_sqrt_ps(v34).m128_f32[0];
    v36 = (__m128)(unsigned int)FLOAT_1_0;
    v36.m128_f32[0] = 1.0 / v35;
  }
  v37 = v36;
  v37.m128_f32[0] = v36.m128_f32[0] * v32;
  v38 = v36.m128_f32[0] * v29.m128_f32[0];
  v39 = v36.m128_f32[0] * v33;
  v40 = (float)(v39 * v25) - (float)(v38 * v26);
  v41 = v37;
  v41.m128_f32[0] = (float)(v37.m128_f32[0] * v26) - (float)(v39 * v24);
  v42 = (float)(v38 * v24) - (float)(v37.m128_f32[0] * v25);
  v43 = v41;
  v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
  if ( v43.m128_f32[0] == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
  vFiringPositionAtAimPosition->x = (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _xmm[0]) * v37.m128_f32[0])
                                          + (float)((float)(v40 * v44) * v47))
                                  + v20;
  vFiringPositionAtAimPosition->y = (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _xmm[0]) * v38)
                                          + (float)((float)(v41.m128_f32[0] * v44) * v47))
                                  + v21;
  vFiringPositionAtAimPosition->z = (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _xmm[0]) * v39)
                                          + (float)((float)(v42 * v44) * v47))
                                  + v48;
}

