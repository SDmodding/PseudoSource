// File Line: 43
// RVA: 0x51BD00
void __fastcall UFG::InteractionPoint::~InteractionPoint(UFG::InteractionPoint *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::InteractorComponent **p; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v13; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::InteractionPoint>Vtbl *)&UFG::InteractionPoint::`vftable;
  UFG::InteractionPoint::RemoveAllInteractors(this, 1);
  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pSimObject = &this->m_pSimObject;
    if ( this->m_pSimObject.m_pPointer )
    {
      mPrev = p_m_pSimObject->mPrev;
      mNext = this->m_pSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pSimObject->mPrev = p_m_pSimObject;
      this->m_pSimObject.mNext = &this->m_pSimObject;
    }
    this->m_pSimObject.m_pPointer = 0i64;
  }
  this->m_bIsActive = 0;
  v6 = &this->m_pSimObject;
  if ( this->m_pSimObject.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = this->m_pSimObject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    this->m_pSimObject.mNext = &this->m_pSimObject;
  }
  this->m_pSimObject.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = this->m_pSimObject.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = v6;
  this->m_pSimObject.mNext = &this->m_pSimObject;
  p = this->m_InteractorList.p;
  if ( p )
    operator delete[](p);
  this->m_InteractorList.p = 0i64;
  *(_QWORD *)&this->m_InteractorList.size = 0i64;
  this->vfptr = (UFG::qSafePointerNode<UFG::InteractionPoint>Vtbl *)&UFG::qSafePointerNode<UFG::InteractionPoint>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v12 = this->m_SafePointerList.mNode.mPrev;
  v13 = this->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 59
// RVA: 0x536820
void __fastcall UFG::InteractionPoint::InitFromDataPtr(UFG::InteractionPoint *this, schema_interactionPoint *dataPtr)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::eInteractionPointUpdateEnum m_eInteractionPointUpdate; // ecx
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm0
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> v14; // [rsp+28h] [rbp-48h] BYREF
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h] BYREF

  this->m_bIsActive = dataPtr->IPActive;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = dataPtr->IPUpdate.mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gInteractionPointUpdateTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInteractionPointUpdateTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  this->m_eInteractionPointUpdate = pTrackEnumBinding.m_EnumValue;
  UFG::InteractionPoint::RemoveAllInteractors(this, 1);
  m_eInteractionPointUpdate = this->m_eInteractionPointUpdate;
  if ( ((m_eInteractionPointUpdate - 2) & 0xFFFFFFFD) != 0 )
  {
    if ( m_eInteractionPointUpdate == eINTERACTION_POINT_UPDATE_BONE )
    {
      this->m_uBoneUID.mUID = dataPtr->IPBoneName.mUID;
    }
    else if ( m_eInteractionPointUpdate == eINTERACTION_POINT_UPDATE_OBJECT_XFORM
           || m_eInteractionPointUpdate == eINTERACTION_POINT_UPDATE_HACK_MIX_0_1_AND_2 )
    {
      v6 = dataPtr->IPXform.v1;
      v7 = dataPtr->IPXform.v2;
      v8 = dataPtr->IPXform.v3;
      this->m_xform.v0 = dataPtr->IPXform.v0;
      this->m_xform.v1 = v6;
      this->m_xform.v2 = v7;
      this->m_xform.v3 = v8;
    }
  }
  else
  {
    this->m_fDistance = dataPtr->IPDistance;
    v14.mPrev = &v14;
    v14.mNext = &v14;
    v14.m_EnumSymbol.mUID = -1;
    v14.m_EnumSymbol.mUID = dataPtr->IPOffsetTarget.mUID;
    *(_QWORD *)&v14.m_EnumValue = 0i64;
    v14.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &v14);
    }
    else
    {
      v9 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &v14;
      v14.mPrev = v9;
      v14.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &v14;
    }
    this->m_eOffsetTarget = v14.m_EnumValue;
    v10 = v14.mPrev;
    mNext = v14.mNext;
    v14.mPrev->mNext = v14.mNext;
    mNext->mPrev = v10;
    v14.mPrev = &v14;
    v14.mNext = &v14;
  }
  v12 = pTrackEnumBinding.mPrev;
  v13 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v13->mPrev = v12;
}

// File Line: 99
// RVA: 0x154D440
__int64 UFG::_dynamic_initializer_for__uidInteractionPointTransform__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointTransform", 0xFFFFFFFF);
  UFG::uidInteractionPointTransform = result;
  return result;
}

// File Line: 105
// RVA: 0x5250A0
void __fastcall UFG::InteractionPoint::CreateSimObject(
        UFG::InteractionPoint *this,
        UFG::SimObject *pOwnerSimObject,
        UFG::TargetingSystemBaseComponent *pTSBC,
        UFG::eTargetTypeEnum eTargetType)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rbp
  UFG::SimObject *v10; // rax
  UFG::SimObject *v11; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qMemoryPool *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::SimComponent *v18; // rax
  UFG::SimObject *m_pPointer; // rdx
  __int16 m_Flags; // cx
  unsigned int v21; // ebx
  UFG::SimObjectModifier v22; // [rsp+40h] [rbp-48h] BYREF
  UFG::qSymbol root; // [rsp+90h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+A0h] [rbp+18h] BYREF

  if ( !this->m_pSimObject.m_pPointer )
  {
    UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&root, &pOwnerSimObject->m_Name, "_IP");
    UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, &root);
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x80ui64, "InteractableComponent.InteractionPoint", 0i64, 1u);
    v9 = 0i64;
    if ( v8 )
    {
      UFG::SimObject::SimObject((UFG::SimObject *)v8, &result);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    p_m_pSimObject = &this->m_pSimObject;
    if ( this->m_pSimObject.m_pPointer )
    {
      mPrev = p_m_pSimObject->mPrev;
      mNext = this->m_pSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pSimObject->mPrev = p_m_pSimObject;
      this->m_pSimObject.mNext = &this->m_pSimObject;
    }
    this->m_pSimObject.m_pPointer = v11;
    if ( v11 )
    {
      v15 = v11->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v15->mNext = p_m_pSimObject;
      p_m_pSimObject->mPrev = v15;
      this->m_pSimObject.mNext = &v11->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v11->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pSimObject;
    }
    v16 = UFG::GetSimulationMemoryPool();
    v17 = UFG::qMemoryPool::Allocate(v16, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
    if ( v17 )
    {
      UFG::TransformNodeComponent::TransformNodeComponent(
        (UFG::TransformNodeComponent *)v17,
        UFG::uidInteractionPointTransform,
        0i64,
        0);
      v9 = v18;
    }
    UFG::Simulation::TrackSimObject(&UFG::gSim, this->m_pSimObject.m_pPointer);
    m_pPointer = this->m_pSimObject.m_pPointer;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v21 = 2;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v21 = 2;
      }
      else
      {
        v21 = -1;
        if ( (m_Flags & 0x1000) != 0 )
          v21 = 1;
      }
    }
    else
    {
      v21 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v22, m_pPointer, 1);
    UFG::SimObjectModifier::AttachComponent(&v22, v9, v21);
    UFG::SimObjectModifier::Close(&v22);
    UFG::SimObjectModifier::~SimObjectModifier(&v22);
  }
  if ( pTSBC )
    UFG::TargetingSystemBaseComponent::SetTarget(pTSBC, eTargetType, this->m_pSimObject.m_pPointer);
}

// File Line: 129
// RVA: 0x525520
void __fastcall UFG::InteractionPoint::DestroySimObject(
        UFG::InteractionPoint *this,
        UFG::TargetingSystemBaseComponent *pTSBC,
        UFG::eTargetTypeEnum eTargetType)
{
  unsigned __int8 v5; // cl
  unsigned __int64 v6; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( pTSBC )
  {
    v5 = pTSBC->m_pTargetingMap->m_Map.p[eTargetType];
    if ( v5 )
    {
      v6 = v5;
      UFG::TargetingSimObject::SetTarget(&pTSBC->m_pTargets[v6], 0i64);
      m_pTargets = pTSBC->m_pTargets;
      if ( m_pTargets[v6].m_bLock )
        m_pTargets[v6].m_bLock = 0;
    }
  }
  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pSimObject = &this->m_pSimObject;
    if ( this->m_pSimObject.m_pPointer )
    {
      mPrev = p_m_pSimObject->mPrev;
      mNext = this->m_pSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pSimObject->mPrev = p_m_pSimObject;
      this->m_pSimObject.mNext = &this->m_pSimObject;
    }
    this->m_pSimObject.m_pPointer = 0i64;
  }
}

// File Line: 191
// RVA: 0x563570
void __fastcall UFG::InteractionPoint::UpdateUsingRoot(
        UFG::InteractionPoint *this,
        UFG::TransformNodeComponent *pRootTNC,
        UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx

  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
      UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &pRootTNC->mWorldTransform);
    }
  }
}

// File Line: 202
// RVA: 0x562B70
void __fastcall UFG::InteractionPoint::UpdateUsingDistance(
        UFG::InteractionPoint *this,
        UFG::TransformNodeComponent *pRootTNC,
        UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float x; // xmm6_4
  float y; // xmm8_4
  __m128 x_low; // xmm7
  float v11; // xmm2_4
  __m128 v12; // xmm1
  float v13; // xmm5_4
  float m_fDistance; // xmm12_4
  float v15; // xmm7_4
  float v16; // xmm11_4
  float v17; // xmm5_4
  float v18; // xmm14_4
  int v19; // xmm11_4
  float v20; // xmm13_4
  float v21; // xmm14_4
  int v22; // xmm7_4
  float v23; // xmm12_4
  int v24; // xmm5_4
  float v25; // xmm12_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm7_4
  float v29; // xmm11_4
  float v30; // xmm5_4
  __m128 v31; // xmm2
  float v32; // xmm8_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm8_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm9_4
  float v39; // xmm6_4
  float v40; // xmm10_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm8_4
  float v45; // xmm6_4
  float v46; // xmm5_4
  float v47; // xmm3_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-D8h] BYREF

  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pInteractorTNC);
      UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
      x_low = (__m128)LODWORD(pInteractorTNC->mWorldTransform.v3.x);
      x = pRootTNC->mWorldTransform.v3.x;
      y = pRootTNC->mWorldTransform.v3.y;
      x_low.m128_f32[0] = x_low.m128_f32[0] - x;
      v12 = x_low;
      v11 = pInteractorTNC->mWorldTransform.v3.y - y;
      v12.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v11 * v11);
      if ( v12.m128_f32[0] == 0.0 )
        v13 = 0.0;
      else
        v13 = 1.0 / _mm_sqrt_ps(v12).m128_f32[0];
      m_fDistance = this->m_fDistance;
      v15 = x_low.m128_f32[0] * v13;
      v16 = v13 * v11;
      v17 = v13 * 0.0;
      v18 = m_fDistance * v16;
      v19 = LODWORD(v16) ^ _xmm[0];
      v20 = (float)(v15 * m_fDistance) + x;
      v21 = v18 + y;
      v22 = LODWORD(v15) ^ _xmm[0];
      v23 = m_fDistance * v17;
      v24 = LODWORD(v17) ^ _xmm[0];
      v25 = v23 + pRootTNC->mWorldTransform.v3.z;
      v26 = (float)((float)(*(float *)&v19 * *(float *)&v19) + (float)(*(float *)&v22 * *(float *)&v22))
          + (float)(*(float *)&v24 * *(float *)&v24);
      if ( v26 == 0.0 )
        v27 = 0.0;
      else
        v27 = 1.0 / fsqrt(v26);
      v28 = *(float *)&v22 * v27;
      v29 = *(float *)&v19 * v27;
      v30 = *(float *)&v24 * v27;
      m.v0.w = 0.0;
      v31 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      m.v0.x = v28;
      m.v0.y = v29;
      m.v0.z = v30;
      v31.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0])
                              + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                      + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( v31.m128_f32[0] == 0.0 )
        v32 = 0.0;
      else
        v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
      v33 = v32;
      v34 = v32;
      v35 = v32 * UFG::qVector3::msDirUp.z;
      v36 = v34 * UFG::qVector3::msDirUp.x;
      v37 = v33 * UFG::qVector3::msDirUp.y;
      v38 = (float)(v30 * v37) - (float)(v29 * v35);
      v39 = (float)(v28 * v35) - (float)(v30 * v36);
      v40 = (float)(v29 * v36) - (float)(v28 * v37);
      v41 = (float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v40 * v40);
      if ( v41 == 0.0 )
        v42 = 0.0;
      else
        v42 = 1.0 / fsqrt(v41);
      m.v1.w = 0.0;
      m.v1.z = v40 * v42;
      m.v1.x = v38 * v42;
      m.v1.y = v39 * v42;
      v43 = (float)((float)(v40 * v42) * v29) - (float)((float)(v39 * v42) * v30);
      v44 = (float)((float)(v38 * v42) * v30) - (float)((float)(v40 * v42) * v28);
      v45 = (float)((float)(v39 * v42) * v28) - (float)((float)(v38 * v42) * v29);
      v46 = (float)((float)(v44 * v44) + (float)(v43 * v43)) + (float)(v45 * v45);
      if ( v46 == 0.0 )
        v47 = 0.0;
      else
        v47 = 1.0 / fsqrt(v46);
      m.v3.x = v20;
      m.v3.y = v21;
      m.v3.z = v25;
      m.v2.w = 0.0;
      m.v3.w = 1.0;
      m.v2.x = v43 * v47;
      m.v2.y = v44 * v47;
      m.v2.z = v45 * v47;
      UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &m);
    }
  }
}

// File Line: 224
// RVA: 0x562A00
void __fastcall UFG::InteractionPoint::UpdateUsingBone(
        UFG::InteractionPoint *this,
        UFG::TransformNodeComponent *pRootTNC,
        UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimObject *m_pSimObject; // rcx
  Creature *v7; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx
  unsigned int mUID; // edx
  int BoneID; // eax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h] BYREF

  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      m_pSimObject = pRootTNC->m_pSimObject;
      v7 = 0i64;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p[8].m_pComponent;
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
              v12 = (__int64)&m_pSimObject->m_Components.p[vfptr];
              while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::BaseAnimationComponent::_TypeUID & 0xFE000000)
                   || (UFG::BaseAnimationComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
              {
                ++vfptr;
                v12 += 16i64;
                if ( vfptr >= size )
                  goto LABEL_16;
              }
              m_pComponent = *(UFG::SimComponent **)v12;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        if ( m_pComponent )
          v7 = *(Creature **)&m_pComponent[2].m_TypeUID;
      }
      if ( v7 )
      {
        mUID = this->m_uBoneUID.mUID;
        if ( mUID != UFG::gNullQSymbolUC.mUID )
        {
          if ( v7->mPose.mRigHandle.mData )
          {
            BoneID = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, mUID);
            if ( BoneID >= 0 )
            {
              Creature::GetTransform(v7, BoneID, &transform);
              UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &transform);
            }
          }
        }
      }
    }
  }
}

// File Line: 263
// RVA: 0x562FD0
void __fastcall UFG::InteractionPoint::UpdateUsingProjected(
        UFG::InteractionPoint *this,
        UFG::TransformNodeComponent *pRootTNC,
        UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r12
  UFG::qMatrix44 *p_mWorldTransform; // rdi
  char v9; // r14
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r9
  unsigned int v13; // edx
  unsigned int m_TypeUID; // ecx
  unsigned int v15; // eax
  unsigned int vfptr; // edx
  unsigned int size; // r10d
  __int64 v18; // r9
  unsigned int v19; // edx
  unsigned int v20; // r10d
  __int64 v21; // rbx
  UFG::TransformNodeComponent *v22; // rbx
  UFG::qVector4 *v23; // rbx
  float m_fDistance; // xmm11_4
  float z; // xmm8_4
  float x; // xmm11_4
  float y; // xmm12_4
  __int128 x_low; // xmm5
  __m128 y_low; // xmm6
  __m128 v30; // xmm1
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  __m128 v34; // xmm7
  float v35; // xmm0_4
  __int128 v36; // xmm7
  float v37; // xmm6_4
  __m128 v38; // xmm2
  float v39; // xmm10_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm10_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  __int128 v45; // xmm13
  float v46; // xmm14_4
  __m128 v47; // xmm9
  float v48; // xmm14_4
  __m128 v49; // xmm2
  float v50; // xmm1_4
  float v51; // xmm0_4
  __m128 v52; // xmm10
  float v53; // xmm9_4
  float v54; // xmm2_4
  __m128 v55; // xmm5
  float v56; // xmm3_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-E8h] BYREF

  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return;
  p_mWorldTransform = 0i64;
  v9 = 1;
  if ( this->m_eOffsetTarget == eTARGET_TYPE_INVALID )
    goto LABEL_36;
  m_pSimObject = pRootTNC->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_36;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        m_TypeUID = m_pComponent->m_TypeUID;
        v13 = UFG::TargetingSystemPedBaseComponent::_TypeUID;
        v15 = UFG::TargetingSystemPedBaseComponent::_TypeUID ^ m_TypeUID;
        goto LABEL_8;
      }
LABEL_10:
      m_pComponent = 0i64;
      goto LABEL_30;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr >= size )
        goto LABEL_10;
      v18 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v18 += 16i64;
        if ( vfptr >= size )
        {
          m_pComponent = 0i64;
          goto LABEL_30;
        }
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemPedBaseComponent::_TypeUID);
        goto LABEL_30;
      }
      v19 = (unsigned int)m_pSimObject[1].vfptr;
      v20 = m_pSimObject->m_Components.size;
      if ( v19 >= v20 )
        goto LABEL_10;
      v18 = (__int64)&m_pSimObject->m_Components.p[v19];
      while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v19;
        v18 += 16i64;
        if ( v19 >= v20 )
        {
          m_pComponent = 0i64;
          goto LABEL_30;
        }
      }
    }
    m_pComponent = *(UFG::SimComponent **)v18;
    goto LABEL_30;
  }
  m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
  if ( !m_pComponent )
    goto LABEL_10;
  v13 = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  m_TypeUID = m_pComponent->m_TypeUID;
  v15 = m_TypeUID ^ UFG::TargetingSystemPedBaseComponent::_TypeUID;
LABEL_8:
  if ( (v15 & 0xFE000000) != 0 || (v13 & ~m_TypeUID & 0x1FFFFFF) != 0 )
    goto LABEL_10;
LABEL_30:
  if ( !m_pComponent )
  {
LABEL_36:
    UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
    v23 = &pRootTNC->mWorldTransform.v3;
    goto LABEL_37;
  }
  v21 = *(_QWORD *)(56i64
                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + (unsigned int)this->m_eOffsetTarget + 8i64)
                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                  + 40);
  if ( !v21 || (v22 = *(UFG::TransformNodeComponent **)(v21 + 88)) == 0i64 )
  {
    v9 = 0;
    goto LABEL_36;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v22);
  p_mWorldTransform = &v22->mWorldTransform;
  UFG::TransformNodeComponent::UpdateWorldTransform(v22);
  v23 = &v22->mWorldTransform.v3;
  if ( !v23 )
    goto LABEL_36;
LABEL_37:
  if ( !p_mWorldTransform )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
    p_mWorldTransform = &pRootTNC->mWorldTransform;
  }
  if ( v9 )
  {
    m_fDistance = this->m_fDistance;
    z = (float)(m_fDistance * p_mWorldTransform->v0.z) + v23->z;
    x = (float)(m_fDistance * p_mWorldTransform->v0.x) + v23->x;
    y = (float)(this->m_fDistance * p_mWorldTransform->v0.y) + v23->y;
  }
  else
  {
    x = v23->x;
    y = v23->y;
    z = v23->z;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(pInteractorTNC);
  x_low = LODWORD(v23->x);
  y_low = (__m128)LODWORD(v23->y);
  *(float *)&x_low = *(float *)&x_low - pInteractorTNC->mWorldTransform.v3.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - pInteractorTNC->mWorldTransform.v3.y;
  v30 = y_low;
  v30.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(*(float *)&x_low * *(float *)&x_low);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  v32 = *(float *)&x_low * v31;
  y_low.m128_f32[0] = y_low.m128_f32[0] * v31;
  v33 = v31 * 0.0;
  v34 = y_low;
  v34.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
  if ( v34.m128_f32[0] == 0.0 )
  {
    v36 = 0i64;
  }
  else
  {
    v35 = _mm_sqrt_ps(v34).m128_f32[0];
    v36 = (unsigned int)FLOAT_1_0;
    *(float *)&v36 = 1.0 / v35;
  }
  *(float *)&x_low = v32 * *(float *)&v36;
  v37 = y_low.m128_f32[0] * *(float *)&v36;
  *(float *)&v36 = *(float *)&v36 * v33;
  m.v0.w = 0.0;
  v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  LODWORD(m.v0.x) = x_low;
  m.v0.y = v37;
  LODWORD(m.v0.z) = v36;
  v38.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v38.m128_f32[0] == 0.0 )
    v39 = 0.0;
  else
    v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
  v40 = v39;
  v41 = v39;
  v42 = v39 * UFG::qVector3::msDirUp.z;
  v43 = v41 * UFG::qVector3::msDirUp.x;
  v44 = v40 * UFG::qVector3::msDirUp.y;
  v45 = v36;
  v47 = (__m128)x_low;
  *(float *)&v45 = (float)(*(float *)&v36 * v44) - (float)(v37 * v42);
  v46 = v37 * v43;
  v47.m128_f32[0] = (float)(*(float *)&x_low * v42) - (float)(*(float *)&v36 * v43);
  v49 = v47;
  v48 = v46 - (float)(*(float *)&x_low * v44);
  v49.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(*(float *)&v45 * *(float *)&v45))
                  + (float)(v48 * v48);
  if ( v49.m128_f32[0] == 0.0 )
    v50 = 0.0;
  else
    v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
  *(float *)&v45 = *(float *)&v45 * v50;
  m.v1.w = 0.0;
  v52 = (__m128)v45;
  m.v1.z = v48 * v50;
  LODWORD(m.v1.x) = v45;
  m.v1.y = v47.m128_f32[0] * v50;
  v51 = (float)(v47.m128_f32[0] * v50) * *(float *)&v36;
  v52.m128_f32[0] = (float)(*(float *)&v45 * *(float *)&v36) - (float)((float)(v48 * v50) * *(float *)&x_low);
  v53 = (float)((float)(v47.m128_f32[0] * v50) * *(float *)&x_low) - (float)(*(float *)&v45 * v37);
  v54 = (float)((float)(v48 * v50) * v37) - v51;
  v55 = v52;
  v55.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v54 * v54)) + (float)(v53 * v53);
  if ( v55.m128_f32[0] == 0.0 )
    v56 = 0.0;
  else
    v56 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
  m.v3.x = x;
  m.v3.y = y;
  m.v3.z = z;
  m.v2.w = 0.0;
  m.v3.w = 1.0;
  m.v2.x = v54 * v56;
  m.v2.y = v52.m128_f32[0] * v56;
  m.v2.z = v53 * v56;
  UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &m);
}

// File Line: 348
// RVA: 0x562F30
void __fastcall UFG::InteractionPoint::UpdateUsingObjectXform(
        UFG::InteractionPoint *this,
        UFG::TransformNodeComponent *pRootTNC,
        UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qMatrix44 *v7; // rax
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm0
  UFG::qMatrix44 m; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h] BYREF

  m_pPointer = this->m_pSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
      v7 = UFG::qMatrix44::operator*(&this->m_xform, &result, &pRootTNC->mWorldTransform);
      v8 = v7->v2;
      v9 = v7->v3;
      v10 = v7->v0;
      m.v1 = v7->v1;
      m.v2 = v8;
      m.v0 = v10;
      m.v3 = v9;
      UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &m);
    }
  }
}

// File Line: 362
// RVA: 0x548E50
void __fastcall UFG::InteractionPoint::RemoveAllInteractors(UFG::InteractionPoint *this, bool bNotifyInteractors)
{
  unsigned int size; // eax
  __int64 v4; // r11
  __int64 v5; // rdi
  UFG::InteractorComponent *v6; // r9
  UFG::InteractionPoint *m_pInteractionPoint; // r8
  unsigned int v8; // r10d
  __int64 v9; // rcx
  UFG::InteractorComponent **p; // rax
  unsigned int v11; // eax
  UFG::InteractorComponent **v12; // rcx

  if ( bNotifyInteractors )
  {
    size = this->m_InteractorList.size;
    if ( size )
    {
      v4 = 0i64;
      v5 = size;
      do
      {
        v6 = this->m_InteractorList.p[v4];
        m_pInteractionPoint = v6->m_pInteractionPoint;
        if ( m_pInteractionPoint )
        {
          v8 = m_pInteractionPoint->m_InteractorList.size;
          v9 = 0i64;
          if ( v8 )
          {
            p = m_pInteractionPoint->m_InteractorList.p;
            while ( *p != v6 )
            {
              v9 = (unsigned int)(v9 + 1);
              ++p;
              if ( (unsigned int)v9 >= v8 )
                goto LABEL_13;
            }
            m_pInteractionPoint->m_InteractorList.p[v9] = m_pInteractionPoint->m_InteractorList.p[v8 - 1];
            v11 = m_pInteractionPoint->m_InteractorList.size;
            if ( v11 > 1 )
              m_pInteractionPoint->m_InteractorList.size = v11 - 1;
            else
              m_pInteractionPoint->m_InteractorList.size = 0;
          }
LABEL_13:
          v6->m_pInteractionPoint = 0i64;
        }
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
  v12 = this->m_InteractorList.p;
  if ( v12 )
    operator delete[](v12);
  this->m_InteractorList.p = 0i64;
  *(_QWORD *)&this->m_InteractorList.size = 0i64;
}

// File Line: 375
// RVA: 0x5209E0
void __fastcall UFG::InteractionPoint::AddInteractor(
        UFG::InteractionPoint *this,
        UFG::InteractorComponent *pInteractor,
        bool bNotifyInteractor)
{
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::InteractorComponent **p; // rax

  for ( ; this->m_InteractorList.size != this->m_InteractorList.capacity; bNotifyInteractor = 0 )
  {
    size = this->m_InteractorList.size;
    capacity = this->m_InteractorList.capacity;
    v8 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v9 = 2 * capacity;
      else
        v9 = 1;
      for ( ; v9 < v8; v9 *= 2 )
        ;
      if ( v9 <= 2 )
        v9 = 2;
      if ( v9 - v8 > 0x10000 )
        v9 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_InteractorList,
        v9,
        "qArray.Add");
    }
    p = this->m_InteractorList.p;
    this->m_InteractorList.size = v8;
    p[size] = pInteractor;
    if ( !bNotifyInteractor )
      break;
    pInteractor->m_pInteractionPoint = this;
  }
}

// File Line: 397
// RVA: 0x1543340
__int64 dynamic_initializer_for__UFG::InteractorComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::InteractorComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::InteractorComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::InteractorComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::InteractorComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 414
// RVA: 0x546670
UFG::allocator::free_link *__fastcall UFG::InteractorComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObjectProperties,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x60ui64, "InteractorComponent", 0i64, 1u);
  v5 = v4;
  if ( v4 )
  {
    UFG::SimComponent::SimComponent((UFG::SimComponent *)v4, pSceneObjectProperties->m_NameUID);
    v5->mNext = (UFG::allocator::free_link *)&UFG::InteractorComponent::`vftable;
    v5[8].mNext = v5 + 8;
    v5[9].mNext = v5 + 8;
    v5[10].mNext = 0i64;
    v5[11].mNext = 0i64;
    UFG::SimComponent::AddType(
      (UFG::SimComponent *)v5,
      UFG::InteractorComponent::_InteractorComponentTypeUID,
      "InteractorComponent");
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObjectProperties->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v7 = 29;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, (UFG::SimComponent *)v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return v5;
}

// File Line: 435
// RVA: 0x51BE10
void __fastcall UFG::InteractorComponent::~InteractorComponent(UFG::InteractorComponent *this)
{
  UFG::InteractionPoint *m_pInteractionPoint; // r9
  unsigned int size; // r10d
  __int64 v4; // rcx
  UFG::InteractorComponent **p; // rax
  unsigned int v6; // eax
  UFG::qSafePointer<UFG::InteractionPoint,UFG::InteractionPoint> *p_m_pBestInteractionPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InteractorComponent::`vftable;
  m_pInteractionPoint = this->m_pInteractionPoint;
  if ( m_pInteractionPoint )
  {
    size = m_pInteractionPoint->m_InteractorList.size;
    v4 = 0i64;
    if ( size )
    {
      p = m_pInteractionPoint->m_InteractorList.p;
      while ( *p != this )
      {
        v4 = (unsigned int)(v4 + 1);
        ++p;
        if ( (unsigned int)v4 >= size )
          goto LABEL_10;
      }
      m_pInteractionPoint->m_InteractorList.p[v4] = m_pInteractionPoint->m_InteractorList.p[size - 1];
      v6 = m_pInteractionPoint->m_InteractorList.size;
      if ( v6 > 1 )
        m_pInteractionPoint->m_InteractorList.size = v6 - 1;
      else
        m_pInteractionPoint->m_InteractorList.size = 0;
    }
LABEL_10:
    this->m_pInteractionPoint = 0i64;
  }
  p_m_pBestInteractionPoint = &this->m_pBestInteractionPoint;
  if ( this->m_pBestInteractionPoint.m_pPointer )
  {
    mPrev = p_m_pBestInteractionPoint->mPrev;
    mNext = this->m_pBestInteractionPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pBestInteractionPoint->mPrev = p_m_pBestInteractionPoint;
    this->m_pBestInteractionPoint.mNext = &this->m_pBestInteractionPoint;
  }
  this->m_pBestInteractionPoint.m_pPointer = 0i64;
  v10 = p_m_pBestInteractionPoint->mPrev;
  v11 = this->m_pBestInteractionPoint.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pBestInteractionPoint->mPrev = p_m_pBestInteractionPoint;
  this->m_pBestInteractionPoint.mNext = &this->m_pBestInteractionPoint;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 443
// RVA: 0x540920
void __fastcall UFG::InteractorComponent::OnDetach(UFG::InteractorComponent *this)
{
  UFG::InteractionPoint *m_pInteractionPoint; // r9
  unsigned int size; // ecx
  int v4; // r8d
  UFG::InteractorComponent **i; // rax
  unsigned int v6; // eax

  m_pInteractionPoint = this->m_pInteractionPoint;
  if ( m_pInteractionPoint )
  {
    size = m_pInteractionPoint->m_InteractorList.size;
    v4 = 0;
    if ( size )
    {
      for ( i = m_pInteractionPoint->m_InteractorList.p; *i != this; ++i )
      {
        if ( ++v4 >= size )
        {
          this->m_pInteractionPoint = 0i64;
          return;
        }
      }
      m_pInteractionPoint->m_InteractorList.p[v4] = m_pInteractionPoint->m_InteractorList.p[size - 1];
      v6 = m_pInteractionPoint->m_InteractorList.size;
      if ( v6 <= 1 )
      {
        m_pInteractionPoint->m_InteractorList.size = 0;
        this->m_pInteractionPoint = 0i64;
        return;
      }
      m_pInteractionPoint->m_InteractorList.size = v6 - 1;
    }
    this->m_pInteractionPoint = 0i64;
  }
}

// File Line: 473
// RVA: 0x54FF90
void __fastcall UFG::InteractorComponent::StartInteraction(
        UFG::InteractorComponent *this,
        UFG::InteractionPoint *pIP,
        bool bNotifyInteractionPoint)
{
  this->m_pInteractionPoint = pIP;
  if ( bNotifyInteractionPoint )
    UFG::InteractionPoint::AddInteractor(pIP, this, 0);
}

// File Line: 486
// RVA: 0x5527F0
void __fastcall UFG::InteractorComponent::StopInteraction(UFG::InteractorComponent *this, bool bNotifyInteractionPoint)
{
  UFG::InteractionPoint *m_pInteractionPoint; // r8
  unsigned int size; // r10d
  __int64 v5; // rcx
  UFG::InteractorComponent **i; // rax
  unsigned int v7; // eax

  m_pInteractionPoint = this->m_pInteractionPoint;
  if ( m_pInteractionPoint )
  {
    if ( bNotifyInteractionPoint )
    {
      size = m_pInteractionPoint->m_InteractorList.size;
      v5 = 0i64;
      if ( size )
      {
        for ( i = m_pInteractionPoint->m_InteractorList.p; *i != this; ++i )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= size )
          {
            this->m_pInteractionPoint = 0i64;
            return;
          }
        }
        m_pInteractionPoint->m_InteractorList.p[v5] = m_pInteractionPoint->m_InteractorList.p[size - 1];
        v7 = m_pInteractionPoint->m_InteractorList.size;
        if ( v7 <= 1 )
        {
          m_pInteractionPoint->m_InteractorList.size = 0;
          this->m_pInteractionPoint = 0i64;
          return;
        }
        m_pInteractionPoint->m_InteractorList.size = v7 - 1;
      }
    }
    this->m_pInteractionPoint = 0i64;
  }
}

// File Line: 499
// RVA: 0x54BD50
void __fastcall UFG::InteractorComponent::SetBestInteractionPoint(
        UFG::InteractorComponent *this,
        UFG::InteractionPoint *pIP,
        bool bUpdateBestInteractionPointTarget)
{
  UFG::qSafePointer<UFG::InteractionPoint,UFG::InteractionPoint> *p_m_pBestInteractionPoint; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimObject *m_pPointer; // rdi
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v14; // rdx
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  __int64 v17; // rax
  unsigned __int8 v18; // cl

  p_m_pBestInteractionPoint = &this->m_pBestInteractionPoint;
  if ( this->m_pBestInteractionPoint.m_pPointer )
  {
    mPrev = p_m_pBestInteractionPoint->mPrev;
    mNext = this->m_pBestInteractionPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pBestInteractionPoint->mPrev = p_m_pBestInteractionPoint;
    this->m_pBestInteractionPoint.mNext = &this->m_pBestInteractionPoint;
  }
  this->m_pBestInteractionPoint.m_pPointer = pIP;
  if ( pIP )
  {
    v7 = pIP->m_SafePointerList.mNode.mPrev;
    v7->mNext = p_m_pBestInteractionPoint;
    p_m_pBestInteractionPoint->mPrev = v7;
    this->m_pBestInteractionPoint.mNext = &pIP->m_SafePointerList.mNode;
    pIP->m_SafePointerList.mNode.mPrev = p_m_pBestInteractionPoint;
  }
  if ( bUpdateBestInteractionPointTarget )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      m_pPointer = 0i64;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
LABEL_27:
        if ( m_pComponent )
        {
          v17 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
          if ( v17 )
          {
            if ( pIP )
              m_pPointer = pIP->m_pSimObject.m_pPointer;
            v18 = *(_BYTE *)(*(_QWORD *)(v17 + 96) + 76i64);
            if ( v18 )
              UFG::TargetingSimObject::SetTarget(
                (UFG::TargetingSimObject *)(*(_QWORD *)(v17 + 88) + 56i64 * v18),
                m_pPointer);
          }
        }
        return;
      }
      if ( m_Flags < 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
        goto LABEL_27;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v14 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v14 += 16i64;
            if ( vfptr >= size )
              goto LABEL_17;
          }
LABEL_18:
          m_pComponent = *(UFG::SimComponent **)v14;
          goto LABEL_27;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
          goto LABEL_27;
        }
        v15 = (unsigned int)m_pSimObject[1].vfptr;
        v16 = m_pSimObject->m_Components.size;
        if ( v15 < v16 )
        {
          v14 = (__int64)&m_pSimObject->m_Components.p[v15];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
               || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v15;
            v14 += 16i64;
            if ( v15 >= v16 )
            {
              m_pComponent = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_18;
        }
      }
LABEL_17:
      m_pComponent = 0i64;
      goto LABEL_27;
    }
  }
}

// File Line: 520
// RVA: 0x1543F00
__int64 dynamic_initializer_for__UFG::InteractableComponent::s_InteractableComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InteractableComponent::s_InteractableComponentList__);
}

// File Line: 521
// RVA: 0x1543310
__int64 dynamic_initializer_for__UFG::InteractableComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::InteractableComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::InteractableComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::InteractableComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::InteractableComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 545
// RVA: 0x52C7B0
UFG::qPropertySet *__fastcall UFG::InteractableComponent::GetDataPtr(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v3; // rax
  UFG::qPropertySet *result; // rax
  UFG::qPropertySet *v5; // rdi
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v7; // rax

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Interactable::sPropertyName,
         DEPTH_RECURSE);
  if ( v3 )
  {
    result = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(v3);
    v5 = result;
    if ( result )
      return result;
  }
  else
  {
    v5 = 0i64;
  }
  mpConstProperties = pSceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = pSceneObj->mpConstProperties;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI,
         DEPTH_RECURSE);
  if ( !v7 )
    return v5;
  result = UFG::qPropertySet::Get<UFG::qPropertySet>(
             v7,
             (UFG::qArray<unsigned long,0> *)&component_Interactable::sPropertyName,
             DEPTH_RECURSE);
  if ( result )
    return (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(result);
  return result;
}

// File Line: 568
// RVA: 0x546580
UFG::qPropertySet *__fastcall UFG::InteractableComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObjectProperties,
        bool isRequired)
{
  UFG::qPropertySet *result; // rax
  component_Interactable *v5; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v12; // ebx
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  result = UFG::InteractableComponent::GetDataPtr(pSceneObjectProperties);
  v5 = (component_Interactable *)result;
  if ( result || isRequired )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v7 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x448ui64, "InteractableComponent", 0i64, 1u);
    if ( v7 )
    {
      UFG::InteractableComponent::InteractableComponent(
        (UFG::InteractableComponent *)v7,
        pSceneObjectProperties->m_NameUID,
        v5);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    m_pSimObject = pSceneObjectProperties->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v12 = 12;
    else
      v12 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v13, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, v9, v12);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
    return (UFG::qPropertySet *)v9;
  }
  return result;
}

// File Line: 589
// RVA: 0x517F00
void __fastcall UFG::InteractableComponent::InteractableComponent(
        UFG::InteractableComponent *this,
        unsigned int name_uid,
        component_Interactable *dataPtr)
{
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  this->mNext = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InteractableComponent::`vftable;
  this->m_fUntargetedCountdownTimer = -1.0;
  `eh vector constructor iterator(
    this->m_InteractionPoints,
    0xA0ui64,
    6,
    (void (__fastcall *)(void *))UFG::InteractionPoint::InteractionPoint);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTSBC);
  mPrev = UFG::InteractableComponent::s_InteractableComponentList.mNode.mPrev;
  UFG::InteractableComponent::s_InteractableComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&UFG::InteractableComponent::s_InteractableComponentList;
  UFG::InteractableComponent::s_InteractableComponentList.mNode.mPrev = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  UFG::SimComponent::AddType(this, UFG::InteractableComponent::_InteractableComponentTypeUID, "InteractableComponent");
  this->m_InteractionPoints[0].m_OwnerInteractableComponent = this;
  this->m_InteractionPoints[1].m_OwnerInteractableComponent = this;
  this->m_InteractionPoints[2].m_OwnerInteractableComponent = this;
  this->m_InteractionPoints[3].m_OwnerInteractableComponent = this;
  this->m_InteractionPoints[4].m_OwnerInteractableComponent = this;
  this->m_InteractionPoints[5].m_OwnerInteractableComponent = this;
  UFG::InteractableComponent::InitFromData(this, dataPtr);
}

// File Line: 605
// RVA: 0x51BC50
void __fastcall UFG::InteractableComponent::~InteractableComponent(UFG::InteractableComponent *this)
{
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *mPrev; // rcx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *mNext; // rax
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v4; // rcx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v5; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InteractableComponent::`vftable;
  UFG::InteractableComponent::DestroyInteractionPoints(this);
  if ( this == UFG::InteractableComponent::s_InteractableComponentpCurrentIterator )
    UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = (UFG::InteractableComponent *)&this->mPrev[-4];
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  this->mNext = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTSBC);
  `eh vector destructor iterator(
    this->m_InteractionPoints,
    0xA0ui64,
    6,
    (void (__fastcall *)(void *))UFG::InteractionPoint::~InteractionPoint);
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  this->mNext = &this->UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 612
// RVA: 0x154CC90
__int64 UFG::_dynamic_initializer_for__symInteractionPoints__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("InteractionPoints", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symInteractionPoints, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symInteractionPoints__);
}

// File Line: 613
// RVA: 0x154CE10
__int64 UFG::_dynamic_initializer_for__symTarget__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Target", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symTarget, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symTarget__);
}

// File Line: 616
// RVA: 0x536660
void __fastcall UFG::InteractableComponent::InitFromData(
        UFG::InteractableComponent *this,
        component_Interactable *dataPtr)
{
  __int64 mOffset; // rax
  UFG::qPropertyList *v4; // rsi
  unsigned int mNumElements; // r14d
  unsigned int i; // edi
  char *ValuePtr; // rax
  __int64 v8; // rcx
  UFG::qPropertySet *v9; // rbx
  schema_interactionPoint *MemImagePtr; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int v12; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  if ( dataPtr )
  {
    mOffset = dataPtr->InteractionPoints.mOffset;
    if ( dataPtr->InteractionPoints.mOffset )
    {
      v4 = (UFG::qPropertyList *)((char *)dataPtr + mOffset);
      if ( (component_Interactable *)((char *)dataPtr + mOffset) )
      {
        mNumElements = v4->mNumElements;
        for ( i = 0; i < mNumElements; ++i )
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v4, 0x1Au, i);
          if ( ValuePtr )
          {
            v8 = *(_QWORD *)ValuePtr;
            if ( *(_QWORD *)ValuePtr )
            {
              v9 = (UFG::qPropertySet *)&ValuePtr[v8];
              if ( &ValuePtr[v8] )
              {
                if ( schema_interactionPoint::IsClass(v9->mSchemaName.mUID) )
                  MemImagePtr = (schema_interactionPoint *)UFG::qPropertySet::GetMemImagePtr(v9);
                else
                  MemImagePtr = 0i64;
                pTrackEnumBinding.mPrev = &pTrackEnumBinding;
                pTrackEnumBinding.mNext = &pTrackEnumBinding;
                pTrackEnumBinding.m_EnumSymbol.mUID = -1;
                pTrackEnumBinding.m_EnumSymbol.mUID = MemImagePtr->IPTarget.mUID;
                *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
                pTrackEnumBinding.m_uEnumUID = 0;
                if ( UFG::gTargetTypeEnum.m_enumLists.size )
                {
                  TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
                }
                else
                {
                  mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
                  UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
                  pTrackEnumBinding.mPrev = mPrev;
                  pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
                  UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
                }
                v12 = pTrackEnumBinding.m_EnumValue - 69;
                if ( pTrackEnumBinding.m_EnumValue == 69 )
                {
                  v12 = 0;
                }
                else if ( v12 >= 5 )
                {
                  v12 = 5;
                }
                UFG::InteractionPoint::InitFromDataPtr(&this->m_InteractionPoints[v12], MemImagePtr);
                v13 = pTrackEnumBinding.mPrev;
                mNext = pTrackEnumBinding.mNext;
                pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
                mNext->mPrev = v13;
                pTrackEnumBinding.mPrev = &pTrackEnumBinding;
                pTrackEnumBinding.mNext = &pTrackEnumBinding;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 654
// RVA: 0x53E390
void __fastcall UFG::InteractableComponent::OnAttach(UFG::InteractableComponent *this, UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTSBC; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx

  p_m_pTSBC = &this->m_pTSBC;
  if ( this->m_pTSBC.m_pSimComponent )
  {
    mNext = this->m_pTSBC.mNext;
    mPrev = p_m_pTSBC->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTSBC->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pTSBC->m_pSimObject = 0i64;
    p_m_pTSBC->mNext = p_m_pTSBC;
    p_m_pTSBC->mPrev = p_m_pTSBC;
    goto LABEL_8;
  }
  if ( this->m_pTSBC.m_pSimObject && (p_m_pTSBC->mPrev != p_m_pTSBC || this->m_pTSBC.mNext != &this->m_pTSBC) )
  {
    v6 = this->m_pTSBC.mNext;
    v7 = p_m_pTSBC->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pTSBC->m_Changed = 1;
  p_m_pTSBC->m_pSimObject = pSimObject;
  p_m_pTSBC->m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pTSBC,
    pSimObject);
}

// File Line: 661
// RVA: 0x5408B0
void __fastcall UFG::InteractableComponent::OnDetach(UFG::InteractableComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTSBC; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  p_m_pTSBC = &this->m_pTSBC;
  if ( this->m_pTSBC.m_pSimComponent )
  {
    mNext = this->m_pTSBC.mNext;
    mPrev = p_m_pTSBC->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTSBC->mNext = p_m_pTSBC;
    p_m_pTSBC->mPrev = p_m_pTSBC;
    p_m_pTSBC->m_Changed = 1;
    p_m_pTSBC->m_pSimComponent = 0i64;
    p_m_pTSBC->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->m_pTSBC.m_pSimObject && (p_m_pTSBC->mPrev != p_m_pTSBC || this->m_pTSBC.mNext != &this->m_pTSBC) )
    {
      v4 = this->m_pTSBC.mNext;
      v5 = p_m_pTSBC->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      p_m_pTSBC->mNext = p_m_pTSBC;
      p_m_pTSBC->mPrev = p_m_pTSBC;
      p_m_pTSBC->m_pSimObject = 0i64;
    }
    p_m_pTSBC->m_Changed = 1;
  }
}

// File Line: 718
// RVA: 0x55E230
void __fastcall UFG::InteractableComponent::UpdateAll(float sim_time_delta)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v3; // rcx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *mPrev; // rax
  float v5; // xmm0_4
  float v6; // xmm0_4
  unsigned __int64 v7; // rax

  Ticks = UFG::qGetTicks();
  v3 = UFG::InteractableComponent::s_InteractableComponentList.mNode.mNext - 4;
  for ( UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = (UFG::InteractableComponent *)&UFG::InteractableComponent::s_InteractableComponentList.mNode.mNext[-4];
        v3 != (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)(&UFG::InteractableComponent::s_InteractableComponentList
                                                                                  - 4);
        UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = (UFG::InteractableComponent *)v3 )
  {
    if ( ((__int64)v3[2].mPrev & 3) == 1 )
    {
      mPrev = v3[67].mPrev;
      if ( mPrev )
      {
        v5 = *(float *)&v3[5].mPrev;
        if ( v5 >= 0.0 )
        {
          if ( mPrev[7].mPrev == (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&mPrev[6].mNext )
          {
            v6 = v5 - sim_time_delta;
            *(float *)&v3[5].mPrev = v6;
            if ( v6 < 0.0 )
            {
              LODWORD(v3[5].mPrev) = -1082130432;
              UFG::InteractableComponent::DestroyInteractionPoints((UFG::InteractableComponent *)v3);
            }
          }
          else
          {
            *(float *)&v3[5].mPrev = UFG::InteractableComponent::ms_fTimeUntargetedToRemoveInteractionPoints;
          }
          v3 = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)UFG::InteractableComponent::s_InteractableComponentpCurrentIterator;
        }
      }
    }
    v3 = v3[4].mNext - 4;
  }
  UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = 0i64;
  v7 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v7);
}

// File Line: 747
// RVA: 0x5248C0
void __fastcall UFG::InteractableComponent::CreateInteractionPoints(UFG::InteractableComponent *this)
{
  int v1; // ebx
  __int64 v3; // rsi
  UFG::eTargetTypeEnum v4; // r8d
  __int64 v5; // rax
  UFG::InteractionPoint *v6; // rcx

  v1 = 69;
  v3 = 6i64;
  do
  {
    if ( v1 <= 69 )
    {
      v4 = eTARGET_TYPE_INTERACTION_POINT0;
    }
    else
    {
      v4 = v1;
      if ( v1 >= 74 )
        v4 = eTARGET_TYPE_INTERACTION_POINT5;
    }
    v5 = (unsigned int)(v4 - 69);
    if ( v4 == eTARGET_TYPE_INTERACTION_POINT0 )
    {
      v5 = 0i64;
    }
    else if ( (unsigned int)v5 >= 5 )
    {
      v5 = 5i64;
    }
    v6 = &this->m_InteractionPoints[v5];
    if ( v6->m_bIsActive )
      UFG::InteractionPoint::CreateSimObject(
        v6,
        this->m_pSimObject,
        (UFG::TargetingSystemBaseComponent *)this->m_pTSBC.m_pSimComponent,
        v4);
    else
      UFG::InteractionPoint::DestroySimObject(
        v6,
        (UFG::TargetingSystemBaseComponent *)this->m_pTSBC.m_pSimComponent,
        v4);
    ++v1;
    this->m_fUntargetedCountdownTimer = UFG::InteractableComponent::ms_fTimeUntargetedToRemoveInteractionPoints;
    --v3;
  }
  while ( v3 );
}

// File Line: 759
// RVA: 0x525400
void __fastcall UFG::InteractableComponent::DestroyInteractionPoints(UFG::InteractableComponent *this)
{
  int v1; // esi
  UFG::InteractionPoint *m_InteractionPoints; // rbx
  __int64 v4; // rbp
  UFG::eTargetTypeEnum v5; // r8d
  unsigned int size; // eax
  __int64 v7; // r11
  __int64 v8; // rdi
  UFG::InteractorComponent *v9; // r9
  UFG::InteractionPoint *m_pInteractionPoint; // r8
  unsigned int v11; // r10d
  __int64 v12; // rcx
  UFG::InteractorComponent **p; // rax
  unsigned int v14; // eax
  UFG::InteractorComponent **v15; // rcx

  v1 = 69;
  m_InteractionPoints = this->m_InteractionPoints;
  v4 = 6i64;
  do
  {
    if ( v1 <= 69 )
    {
      v5 = eTARGET_TYPE_INTERACTION_POINT0;
    }
    else
    {
      v5 = v1;
      if ( v1 >= 74 )
        v5 = eTARGET_TYPE_INTERACTION_POINT5;
    }
    UFG::InteractionPoint::DestroySimObject(
      m_InteractionPoints,
      (UFG::TargetingSystemBaseComponent *)this->m_pTSBC.m_pSimComponent,
      v5);
    size = m_InteractionPoints->m_InteractorList.size;
    if ( size )
    {
      v7 = 0i64;
      v8 = size;
      do
      {
        v9 = m_InteractionPoints->m_InteractorList.p[v7];
        m_pInteractionPoint = v9->m_pInteractionPoint;
        if ( m_pInteractionPoint )
        {
          v11 = m_pInteractionPoint->m_InteractorList.size;
          v12 = 0i64;
          if ( v11 )
          {
            p = m_pInteractionPoint->m_InteractorList.p;
            while ( *p != v9 )
            {
              v12 = (unsigned int)(v12 + 1);
              ++p;
              if ( (unsigned int)v12 >= v11 )
                goto LABEL_17;
            }
            m_pInteractionPoint->m_InteractorList.p[v12] = m_pInteractionPoint->m_InteractorList.p[v11 - 1];
            v14 = m_pInteractionPoint->m_InteractorList.size;
            if ( v14 > 1 )
              m_pInteractionPoint->m_InteractorList.size = v14 - 1;
            else
              m_pInteractionPoint->m_InteractorList.size = 0;
          }
LABEL_17:
          v9->m_pInteractionPoint = 0i64;
        }
        ++v7;
        --v8;
      }
      while ( v8 );
    }
    v15 = m_InteractionPoints->m_InteractorList.p;
    if ( v15 )
      operator delete[](v15);
    m_InteractionPoints->m_InteractorList.p = 0i64;
    *(_QWORD *)&m_InteractionPoints->m_InteractorList.size = 0i64;
    ++m_InteractionPoints;
    ++v1;
    --v4;
  }
  while ( v4 );
}

// File Line: 807
// RVA: 0x560380
void __fastcall UFG::InteractableComponent::UpdateInteractionPoints(
        UFG::InteractableComponent *this,
        UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::InteractionPoint *m_InteractionPoints; // rbx
  __int64 v7; // r12
  UFG::eInteractionPointUpdateEnum m_eInteractionPointUpdate; // ecx
  UFG::SimObject *m_pPointer; // r15
  UFG::TransformNodeComponent *mNext; // r14
  UFG::TransformNodeComponent *v11; // rbp
  __int128 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::SimObject *v15; // rcx
  UFG::TransformNodeComponent *v16; // rcx
  __int32 v17; // ecx
  __int32 v18; // ecx
  int v19; // ecx
  int v20; // ecx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-78h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      m_InteractionPoints = this->m_InteractionPoints;
      v7 = 6i64;
      do
      {
        m_eInteractionPointUpdate = m_InteractionPoints->m_eInteractionPointUpdate;
        if ( m_eInteractionPointUpdate == eINTERACTION_POINT_UPDATE_HACK_MIX_0_1_AND_2 )
        {
          m_pPointer = this->m_InteractionPoints[0].m_pSimObject.m_pPointer;
          if ( m_pPointer )
            m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
          mNext = (UFG::TransformNodeComponent *)this->m_InteractionPoints[1].m_pSimObject.m_pPointer;
          if ( mNext )
            mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
          v11 = (UFG::TransformNodeComponent *)this->m_InteractionPoints[2].m_pSimObject.m_pPointer;
          if ( v11 )
            v11 = (UFG::TransformNodeComponent *)v11->mChildren.mNode.mNext;
          if ( m_pPointer )
          {
            if ( mNext )
            {
              if ( v11 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
                v12 = *(_OWORD *)&m_pPointer[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
                v13 = *(UFG::qVector4 *)m_pPointer[1].mNode.mChild;
                v14 = *(UFG::qVector4 *)&m_pPointer[1].vfptr;
                m.v1 = *(UFG::qVector4 *)&m_pPointer[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
                m.v2 = (UFG::qVector4)v12;
                m.v0 = v14;
                m.v3 = v13;
                UFG::TransformNodeComponent::UpdateWorldTransform(v11);
                UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
                v15 = m_InteractionPoints->m_pSimObject.m_pPointer;
                *(float *)&v12 = (float)(mNext->mWorldTransform.v3.y + v11->mWorldTransform.v3.y) * 0.5;
                v13.x = mNext->mWorldTransform.v3.z + v11->mWorldTransform.v3.z;
                v14.x = mNext->mWorldTransform.v3.w + v11->mWorldTransform.v3.w;
                m.v3.x = (float)(mNext->mWorldTransform.v3.x + v11->mWorldTransform.v3.x) * 0.5;
                LODWORD(m.v3.y) = v12;
                m.v3.z = v13.x * 0.5;
                m.v3.w = v14.x * 0.5;
                if ( v15 )
                {
                  v16 = v15->m_pTransformNodeComponent;
                  if ( v16 )
                    UFG::TransformNodeComponent::SetWorldTransform(v16, &m);
                }
              }
            }
          }
        }
        else if ( m_InteractionPoints->m_pSimObject.m_pPointer )
        {
          v17 = m_eInteractionPointUpdate - 1;
          if ( v17 )
          {
            v18 = v17 - 1;
            if ( v18 )
            {
              v19 = v18 - 1;
              if ( v19 )
              {
                v20 = v19 - 1;
                if ( v20 )
                {
                  if ( v20 == 1 )
                    UFG::InteractionPoint::UpdateUsingObjectXform(
                      m_InteractionPoints,
                      m_pTransformNodeComponent,
                      pInteractorTNC);
                }
                else
                {
                  UFG::InteractionPoint::UpdateUsingProjected(
                    m_InteractionPoints,
                    m_pTransformNodeComponent,
                    pInteractorTNC);
                }
              }
              else
              {
                UFG::InteractionPoint::UpdateUsingBone(m_InteractionPoints, m_pTransformNodeComponent, pInteractorTNC);
              }
            }
            else
            {
              UFG::InteractionPoint::UpdateUsingDistance(m_InteractionPoints, m_pTransformNodeComponent, pInteractorTNC);
            }
          }
          else
          {
            UFG::InteractionPoint::UpdateUsingRoot(m_InteractionPoints, m_pTransformNodeComponent, pInteractorTNC);
          }
        }
        ++m_InteractionPoints;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 845
// RVA: 0x54D930
void __fastcall UFG::InteractableComponent::SetIsActive(
        UFG::InteractableComponent *this,
        UFG::eTargetTypeEnum eTargetType,
        char bIsActive)
{
  unsigned int v3; // edx

  v3 = eTargetType - 69;
  if ( v3 )
  {
    if ( v3 >= 5 )
    {
      this->m_InteractionPoints[5].m_bIsActive = bIsActive;
      return;
    }
  }
  else
  {
    v3 = 0;
  }
  this->m_InteractionPoints[v3].m_bIsActive = bIsActive;
}

// File Line: 875
// RVA: 0x527DD0
UFG::SimObject **__fastcall UFG::InteractableComponent::FindBestInteractionPoint(
        UFG::InteractableComponent *this,
        UFG::SimObject *pInteractingSO,
        UFG::qStaticBitField<6> *bfTestIP,
        const bool bIgnoreMeshTest)
{
  UFG::qStaticBitField<6> *v5; // r12
  unsigned int v8; // ebx
  UFG::SimObject **v9; // r13
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  float v11; // xmm6_4
  __int64 v12; // r14
  UFG::SimObject **p_m_pPointer; // rsi
  UFG::TransformNodeComponent *v14; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rsi
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  __int64 v21; // rdx
  unsigned int v22; // r8d
  unsigned int v23; // r9d
  unsigned int v24; // r8d
  unsigned int v25; // r9d
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned int v28; // r15d
  __int64 v29; // rsi
  UFG::SimObject **v30; // r13
  int v31; // r14d
  UFG::SimObject *v32; // rax
  UFG::TransformNodeComponent *v33; // r12
  __m128 y_low; // xmm2
  __m128 z_low; // xmm0
  int *v36; // rcx
  UFG::DaemonManager *v37; // rax
  int v38; // edi
  float v39; // xmm0_4
  int v40; // eax
  __int64 v41; // r8
  int v42; // edx
  float *v43; // rcx
  unsigned __int64 v44; // r9
  UFG::InteractionPoint *v45; // rdi
  __int64 v46; // rcx
  UFG::DaemonQueryOutput output; // [rsp+28h] [rbp-D8h] BYREF
  __int64 v48; // [rsp+40h] [rbp-C0h]
  void *mem; // [rsp+48h] [rbp-B8h]
  __int64 v50; // [rsp+50h] [rbp-B0h]
  int *v51; // [rsp+58h] [rbp-A8h]
  UFG::FindPathMultiDestPrioritizedImmediateQuery v52; // [rsp+60h] [rbp-A0h] BYREF
  UFG::HavokNavPosition npPosition; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v54; // [rsp+120h] [rbp+20h]
  int v55[14]; // [rsp+128h] [rbp+28h] BYREF

  v54 = -2i64;
  v5 = bfTestIP;
  v8 = 0;
  v9 = 0i64;
  if ( !pInteractingSO )
    return 0i64;
  m_pTransformNodeComponent = pInteractingSO->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0i64;
  UFG::InteractableComponent::CreateInteractionPoints(this);
  UFG::InteractableComponent::UpdateInteractionPoints(this, m_pTransformNodeComponent);
  if ( bIgnoreMeshTest )
  {
    v11 = FLOAT_3_4028235e38;
    v12 = 1i64;
    p_m_pPointer = &this->m_InteractionPoints[0].m_pSimObject.m_pPointer;
    do
    {
      if ( (v12 & v5[(__int64)(int)v8 >> 6].mBits[0]) != 0 )
      {
        if ( *p_m_pPointer )
        {
          v14 = (*p_m_pPointer)->m_pTransformNodeComponent;
          if ( v14 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((*p_m_pPointer)->m_pTransformNodeComponent);
            UFG::TransformNodeComponent::UpdateWorldTransform(v14);
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            if ( (float)((float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y
                                               - v14->mWorldTransform.v3.y)
                                       * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y
                                               - v14->mWorldTransform.v3.y))
                               + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                               - v14->mWorldTransform.v3.x)
                                       * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                               - v14->mWorldTransform.v3.x)))
                       + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v14->mWorldTransform.v3.z)
                               * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v14->mWorldTransform.v3.z))) < v11 )
            {
              v11 = (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v14->mWorldTransform.v3.y)
                                  * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v14->mWorldTransform.v3.y))
                          + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v14->mWorldTransform.v3.x)
                                  * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v14->mWorldTransform.v3.x)))
                  + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v14->mWorldTransform.v3.z)
                          * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v14->mWorldTransform.v3.z));
              v9 = p_m_pPointer - 9;
            }
          }
        }
      }
      ++v8;
      v12 = __ROL8__(v12, 1);
      p_m_pPointer += 20;
    }
    while ( v8 < 6 );
    return v9;
  }
  m_Flags = pInteractingSO->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pInteractingSO->m_Components.p[36].m_pComponent;
    goto LABEL_38;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)pInteractingSO[1].vfptr;
    size = pInteractingSO->m_Components.size;
    if ( vfptr < size )
    {
      p = pInteractingSO->m_Components.p;
      while ( 1 )
      {
        v21 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::NavComponent::_TypeUID & 0xFE000000)
          && (UFG::NavComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_22;
      }
LABEL_21:
      m_pComponent = p[v21].m_pComponent;
      goto LABEL_38;
    }
    goto LABEL_22;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v22 = (unsigned int)pInteractingSO[1].vfptr;
    v23 = pInteractingSO->m_Components.size;
    if ( v22 < v23 )
    {
      p = pInteractingSO->m_Components.p;
      while ( 1 )
      {
        v21 = v22;
        if ( (p[v22].m_TypeUID & 0xFE000000) == (UFG::NavComponent::_TypeUID & 0xFE000000)
          && (UFG::NavComponent::_TypeUID & ~p[v22].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_21;
        }
        if ( ++v22 >= v23 )
          goto LABEL_22;
      }
    }
    goto LABEL_22;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v24 = (unsigned int)pInteractingSO[1].vfptr;
    v25 = pInteractingSO->m_Components.size;
    if ( v24 < v25 )
    {
      p = pInteractingSO->m_Components.p;
      do
      {
        v21 = v24;
        if ( (p[v24].m_TypeUID & 0xFE000000) == (UFG::NavComponent::_TypeUID & 0xFE000000)
          && (UFG::NavComponent::_TypeUID & ~p[v24].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_21;
        }
      }
      while ( ++v24 < v25 );
    }
LABEL_22:
    m_pComponent = 0i64;
    goto LABEL_38;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(pInteractingSO, UFG::NavComponent::_TypeUID);
LABEL_38:
  v52.m_daemonType = DaemonType_Navigation;
  *(_QWORD *)&v52.m_internalType = 1i64;
  v52.m_pOutput = 0i64;
  v52.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathMultiDestPrioritizedImmediateQuery::`vftable;
  v52.m_npFrom.m_vPosition = UFG::qVector3::msZero;
  v52.m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v52.m_npFrom.m_bValid = 0;
  v52.m_npFrom.m_hkvMeshPosition = (hkVector4f)hkvZero_34.m_quad;
  *(_QWORD *)&v52.m_npFrom.m_packedKey = -1i64;
  v52.m_pNavParams = 0i64;
  v52.m_maxSearchIterations = -1;
  v52.m_aPrioritizedDestinations.p = 0i64;
  *(_QWORD *)&v52.m_aPrioritizedDestinations.size = 0i64;
  output.m_id = DaemonType_Navigation;
  *(_QWORD *)&output.m_internalType = 1i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathMultiDestPrioritizedOutput::`vftable;
  mem = 0i64;
  v48 = 0i64;
  v50 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v52.m_npFrom.m_vPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  v52.m_npFrom.m_vPosition.y = y;
  v52.m_npFrom.m_vPosition.z = z;
  v52.m_npFrom.m_bValid = 0;
  UFG::HavokNavPosition::Validate(
    &v52.m_npFrom,
    COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_050000001)),
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    0.0);
  v52.m_pNavParams = (UFG::NavParams *)((char *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext + 4);
  v28 = 0;
  v29 = 1i64;
  v51 = v55;
  v30 = &this->m_InteractionPoints[0].m_pSimObject.m_pPointer;
  v31 = 0;
  do
  {
    if ( (v29 & v5[(__int64)(int)v28 >> 6].mBits[0]) != 0 )
    {
      v32 = *v30;
      if ( *v30 )
      {
        v33 = v32->m_pTransformNodeComponent;
        if ( v33 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v32->m_pTransformNodeComponent);
          y_low = (__m128)LODWORD(v33->mWorldTransform.v3.y);
          z_low = (__m128)LODWORD(v33->mWorldTransform.v3.z);
          npPosition.m_vPosition.x = v33->mWorldTransform.v3.x;
          LODWORD(npPosition.m_vPosition.y) = y_low.m128_i32[0];
          LODWORD(npPosition.m_vPosition.z) = z_low.m128_i32[0];
          npPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
          npPosition.m_bValid = 0;
          *(_QWORD *)&npPosition.m_packedKey = -1i64;
          npPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                  _mm_unpacklo_ps((__m128)LODWORD(npPosition.m_vPosition.x), z_low),
                                                  _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
          UFG::HavokNavPosition::Validate(
            &npPosition,
            COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_050000001)),
            COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
            0.0);
          UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(&v52, &npPosition, 1.0);
          v36 = v51;
          *v51 = v28;
          ++v31;
          v51 = v36 + 1;
        }
        v5 = bfTestIP;
      }
    }
    ++v28;
    v29 = __ROL8__(v29, 1);
    v30 += 20;
  }
  while ( v28 < 6 );
  v37 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v37, &v52, &output);
  v38 = -1;
  if ( output.m_status != Status_Completed )
    goto LABEL_63;
  v39 = FLOAT_3_4028235e38;
  v40 = 0;
  v41 = 0i64;
  if ( v31 >= 4i64 )
  {
    v42 = 2;
    v43 = (float *)((char *)mem + 8);
    v44 = ((unsigned __int64)(v31 - 4i64) >> 2) + 1;
    v41 = 4 * v44;
    do
    {
      if ( *(v43 - 2) < v39 )
      {
        v38 = v40;
        v39 = *(v43 - 2);
      }
      if ( *(v43 - 1) < v39 )
      {
        v38 = v42 - 1;
        v39 = *(v43 - 1);
      }
      if ( *v43 < v39 )
      {
        v38 = v42;
        v39 = *v43;
      }
      if ( v43[1] < v39 )
      {
        v38 = v42 + 1;
        v39 = v43[1];
      }
      v40 += 4;
      v42 += 4;
      v43 += 4;
      --v44;
    }
    while ( v44 );
  }
  for ( ; v41 < v31; ++v41 )
  {
    if ( *((float *)mem + v41) < v39 )
    {
      v38 = v40;
      v39 = *((float *)mem + v41);
    }
    ++v40;
  }
  if ( v38 == -1 )
LABEL_63:
    v45 = 0i64;
  else
    v45 = &this->m_InteractionPoints[v55[v38]];
  v46 = v50;
  if ( v50 )
  {
    --*(_DWORD *)(v50 + 40);
    if ( !*(_DWORD *)(v46 + 40) )
      (**(void (__fastcall ***)(__int64, __int64))v46)(v46, 1i64);
  }
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v48 = 0i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  if ( v52.m_aPrioritizedDestinations.p )
    operator delete[](v52.m_aPrioritizedDestinations.p);
  v52.m_aPrioritizedDestinations.p = 0i64;
  *(_QWORD *)&v52.m_aPrioritizedDestinations.size = 0i64;
  v52.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  return (UFG::SimObject **)v45;
}

// File Line: 990
// RVA: 0x5286F0
UFG::InteractionPoint *__fastcall UFG::InteractableComponent::FindInteractionPoint(
        UFG::InteractableComponent *this,
        UFG::SimObject *pInteractingSO,
        UFG::eTargetTypeEnum eInteractionPointTargetType,
        const bool bIgnoreMeshTest)
{
  __int64 v4; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  __int64 v8; // rax
  UFG::InteractionPoint *v9; // rbx
  UFG::SimObject *m_pSimObject; // rdx
  UFG::TransformNodeComponent *v11; // rdx
  UFG::SimObject *m_pPointer; // rsi
  UFG::TransformNodeComponent *v13; // rsi
  __m128 x_low; // xmm4
  __m128 y_low; // xmm3
  __m128 z_low; // xmm0
  UFG::HavokNavPosition v18; // [rsp+20h] [rbp-48h] BYREF

  v4 = 0i64;
  if ( pInteractingSO )
  {
    m_pTransformNodeComponent = pInteractingSO->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v8 = (unsigned int)(eInteractionPointTargetType - 69);
      if ( eInteractionPointTargetType == eTARGET_TYPE_INTERACTION_POINT0 )
      {
        v8 = 0i64;
      }
      else if ( (unsigned int)v8 >= 5 )
      {
        v8 = 5i64;
      }
      v9 = &this->m_InteractionPoints[v8];
      if ( v9->m_bIsActive )
        UFG::InteractionPoint::CreateSimObject(
          v9,
          this->m_pSimObject,
          (UFG::TargetingSystemBaseComponent *)this->m_pTSBC.m_pSimComponent,
          eInteractionPointTargetType);
      else
        UFG::InteractionPoint::DestroySimObject(
          v9,
          (UFG::TargetingSystemBaseComponent *)this->m_pTSBC.m_pSimComponent,
          eInteractionPointTargetType);
      m_pSimObject = this->m_pSimObject;
      this->m_fUntargetedCountdownTimer = UFG::InteractableComponent::ms_fTimeUntargetedToRemoveInteractionPoints;
      if ( m_pSimObject )
      {
        v11 = m_pSimObject->m_pTransformNodeComponent;
        if ( v11 )
        {
          if ( v9->m_pSimObject.m_pPointer )
          {
            switch ( v9->m_eInteractionPointUpdate )
            {
              case eINTERACTION_POINT_UPDATE_ROOT:
                UFG::InteractionPoint::UpdateUsingRoot(v9, v11, m_pTransformNodeComponent);
                break;
              case eINTERACTION_POINT_UPDATE_DISTANCE:
                UFG::InteractionPoint::UpdateUsingDistance(v9, v11, m_pTransformNodeComponent);
                break;
              case eINTERACTION_POINT_UPDATE_BONE:
                UFG::InteractionPoint::UpdateUsingBone(v9, v11, m_pTransformNodeComponent);
                break;
              case eINTERACTION_POINT_UPDATE_PROJECTED:
                UFG::InteractionPoint::UpdateUsingProjected(v9, v11, m_pTransformNodeComponent);
                break;
              case eINTERACTION_POINT_UPDATE_OBJECT_XFORM:
                UFG::InteractionPoint::UpdateUsingObjectXform(v9, v11, m_pTransformNodeComponent);
                break;
            }
          }
        }
      }
      m_pPointer = v9->m_pSimObject.m_pPointer;
      if ( m_pPointer )
      {
        v13 = m_pPointer->m_pTransformNodeComponent;
        if ( v13 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v13);
          x_low = (__m128)LODWORD(v13->mWorldTransform.v3.x);
          y_low = (__m128)LODWORD(v13->mWorldTransform.v3.y);
          z_low = (__m128)LODWORD(v13->mWorldTransform.v3.z);
          if ( bIgnoreMeshTest )
          {
            return v9;
          }
          else
          {
            v18.m_vPosition.x = v13->mWorldTransform.v3.x;
            LODWORD(v18.m_vPosition.y) = y_low.m128_i32[0];
            v18.m_bValid = 0;
            *(_QWORD *)&v18.m_packedKey = -1i64;
            LODWORD(v18.m_vPosition.z) = z_low.m128_i32[0];
            v18.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
            v18.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(x_low, z_low),
                                             _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
            UFG::HavokNavPosition::Validate(
              &v18,
              COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_050000001)),
              COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
              0.0);
            if ( v18.m_bValid
              && UFG::HavokAIUtilGame::IsValidKey(v18.m_packedKey, v18.m_aiMeshUid)
              && v18.m_packedKey != -1
              && v18.m_aiMeshUid != -1 )
            {
              return v9;
            }
          }
        }
      }
    }
  }
  return (UFG::InteractionPoint *)v4;
}

