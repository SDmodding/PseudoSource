// File Line: 43
// RVA: 0x51BD00
void __fastcall UFG::InteractionPoint::~InteractionPoint(UFG::InteractionPoint *this)
{
  UFG::InteractionPoint *v1; // rbx
  UFG::SimObject *v2; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::InteractorComponent **v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList,1,0> *v14; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::InteractionPoint>Vtbl *)&UFG::InteractionPoint::`vftable';
  UFG::InteractionPoint::RemoveAllInteractors(this, 1);
  v2 = v1->m_pSimObject.m_pPointer;
  if ( v2 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v2);
    v3 = &v1->m_pSimObject;
    if ( v1->m_pSimObject.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v1->m_pSimObject.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v1->m_pSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimObject.mPrev;
    }
    v1->m_pSimObject.m_pPointer = 0i64;
  }
  v1->m_bIsActive = 0;
  v6 = &v1->m_pSimObject;
  if ( v1->m_pSimObject.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->m_pSimObject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->m_pSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimObject.mPrev;
  }
  v1->m_pSimObject.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->m_pSimObject.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->m_pSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimObject.mPrev;
  v11 = v1->m_InteractorList.p;
  if ( v11 )
    operator delete[](v11);
  v1->m_InteractorList.p = 0i64;
  *(_QWORD *)&v1->m_InteractorList.size = 0i64;
  v1->vfptr = (UFG::qSafePointerNode<UFG::InteractionPoint>Vtbl *)&UFG::qSafePointerNode<UFG::InteractionPoint>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v1);
  v14 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v12 = v1->m_SafePointerList.mNode.mPrev;
  v13 = v1->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
}

// File Line: 59
// RVA: 0x536820
void __fastcall UFG::InteractionPoint::InitFromDataPtr(UFG::InteractionPoint *this, schema_interactionPoint *dataPtr)
{
  schema_interactionPoint *v2; // rdi
  UFG::InteractionPoint *v3; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v4; // rax
  UFG::eInteractionPointUpdateEnum v5; // ecx
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm0
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> v14; // [rsp+28h] [rbp-48h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h]

  v2 = dataPtr;
  v3 = this;
  this->m_bIsActive = dataPtr->IPActive;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
    v4 = UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v4;
    pTrackEnumBinding.mNext = &UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInteractionPointUpdateTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v3->m_eInteractionPointUpdate = pTrackEnumBinding.m_EnumValue;
  UFG::InteractionPoint::RemoveAllInteractors(v3, 1);
  v5 = v3->m_eInteractionPointUpdate;
  if ( (v5 - 2) & 0xFFFFFFFD )
  {
    if ( v5 == 3 )
    {
      v3->m_uBoneUID.mUID = v2->IPBoneName.mUID;
    }
    else if ( v5 == 5 || v5 == 6 )
    {
      v6 = v2->IPXform.v1;
      v7 = v2->IPXform.v2;
      v8 = v2->IPXform.v3;
      v3->m_xform.v0 = v2->IPXform.v0;
      v3->m_xform.v1 = v6;
      v3->m_xform.v2 = v7;
      v3->m_xform.v3 = v8;
    }
  }
  else
  {
    v3->m_fDistance = v2->IPDistance;
    v14.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v14;
    v14.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v14;
    v14.m_EnumSymbol.mUID = -1;
    v14.m_EnumSymbol.mUID = v2->IPOffsetTarget.mUID;
    *(_QWORD *)&v14.m_EnumValue = 0i64;
    v14.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &v14);
    }
    else
    {
      v9 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v14;
      v14.mPrev = v9;
      v14.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v14;
    }
    v3->m_eOffsetTarget = v14.m_EnumValue;
    v10 = v14.mPrev;
    v11 = v14.mNext;
    v14.mPrev->mNext = v14.mNext;
    v11->mPrev = v10;
    v14.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v14;
    v14.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v14;
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
void __fastcall UFG::InteractionPoint::CreateSimObject(UFG::InteractionPoint *this, UFG::SimObject *pOwnerSimObject, UFG::TargetingSystemBaseComponent *pTSBC, UFG::eTargetTypeEnum eTargetType)
{
  UFG::eTargetTypeEnum v4; // er14
  UFG::TargetingSystemBaseComponent *v5; // rsi
  UFG::InteractionPoint *v6; // rdi
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rbp
  UFG::SimObject *v10; // rax
  UFG::SimObject *v11; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qMemoryPool *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::SimComponent *v18; // rax
  UFG::SimObject *v19; // rdx
  unsigned __int16 v20; // cx
  unsigned int v21; // ebx
  UFG::SimObjectModifier v22; // [rsp+40h] [rbp-48h]
  UFG::qSymbol root; // [rsp+90h] [rbp+8h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+18h]

  v4 = eTargetType;
  v5 = pTSBC;
  v6 = this;
  if ( !this->m_pSimObject.m_pPointer )
  {
    UFG::qSymbol::create_suffix(&root, &pOwnerSimObject->m_Name, "_IP");
    UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, &root);
    v7 = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(v7, 0x80ui64, "InteractableComponent.InteractionPoint", 0i64, 1u);
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
    v12 = &v6->m_pSimObject;
    if ( v6->m_pSimObject.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v6->m_pSimObject.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v6->m_pSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->m_pSimObject.mPrev;
    }
    v6->m_pSimObject.m_pPointer = v11;
    if ( v11 )
    {
      v15 = v11->m_SafePointerList.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v12->mPrev = v15;
      v6->m_pSimObject.mNext = &v11->m_SafePointerList.mNode;
      v11->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
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
    UFG::Simulation::TrackSimObject(&UFG::gSim, v6->m_pSimObject.m_pPointer);
    v19 = v6->m_pSimObject.m_pPointer;
    v20 = v19->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v21 = 2;
    }
    else if ( (v20 & 0x8000u) == 0 )
    {
      if ( (v20 >> 13) & 1 )
      {
        v21 = 2;
      }
      else
      {
        v21 = -1;
        if ( (v20 >> 12) & 1 )
          v21 = 1;
      }
    }
    else
    {
      v21 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v22, v19, 1);
    UFG::SimObjectModifier::AttachComponent(&v22, v9, v21);
    UFG::SimObjectModifier::Close(&v22);
    UFG::SimObjectModifier::~SimObjectModifier(&v22);
  }
  if ( v5 )
    UFG::TargetingSystemBaseComponent::SetTarget(v5, v4, v6->m_pSimObject.m_pPointer);
}

// File Line: 129
// RVA: 0x525520
void __fastcall UFG::InteractionPoint::DestroySimObject(UFG::InteractionPoint *this, UFG::TargetingSystemBaseComponent *pTSBC, UFG::eTargetTypeEnum eTargetType)
{
  UFG::InteractionPoint *v3; // rsi
  UFG::TargetingSystemBaseComponent *v4; // rdi
  unsigned __int8 v5; // cl
  unsigned __int64 v6; // rbx
  UFG::TargetingSimObject *v7; // rax
  UFG::SimObject *v8; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  v3 = this;
  v4 = pTSBC;
  if ( pTSBC )
  {
    v5 = pTSBC->m_pTargetingMap->m_Map.p[eTargetType];
    if ( v5 )
    {
      v6 = v5;
      UFG::TargetingSimObject::SetTarget(&pTSBC->m_pTargets[v6], 0i64);
      v7 = v4->m_pTargets;
      if ( v7[v6].m_bLock )
        v7[v6].m_bLock = 0;
    }
  }
  v8 = v3->m_pSimObject.m_pPointer;
  if ( v8 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v8);
    v9 = &v3->m_pSimObject;
    if ( v3->m_pSimObject.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v3->m_pSimObject.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v3->m_pSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pSimObject.mPrev;
    }
    v3->m_pSimObject.m_pPointer = 0i64;
  }
}

// File Line: 191
// RVA: 0x563570
void __fastcall UFG::InteractionPoint::UpdateUsingRoot(UFG::InteractionPoint *this, UFG::TransformNodeComponent *pRootTNC, UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *v3; // rbx
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx

  v3 = this->m_pSimObject.m_pPointer;
  v4 = pRootTNC;
  if ( v3 )
  {
    v5 = v3->m_pTransformNodeComponent;
    if ( v5 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
      UFG::TransformNodeComponent::SetWorldTransform(v5, &v4->mWorldTransform);
    }
  }
}

// File Line: 202
// RVA: 0x562B70
void __fastcall UFG::InteractionPoint::UpdateUsingDistance(UFG::InteractionPoint *this, UFG::TransformNodeComponent *pRootTNC, UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *v3; // rax
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx
  UFG::InteractionPoint *v6; // rbp
  UFG::TransformNodeComponent *v7; // rsi
  float v8; // xmm6_4
  float v9; // xmm8_4
  __m128 v10; // xmm7
  float v11; // xmm2_4
  __m128 v12; // xmm1
  float v13; // xmm5_4
  float v14; // xmm12_4
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
  __m128 v28; // xmm6
  float v29; // xmm7_4
  float v30; // xmm11_4
  float v31; // xmm5_4
  __m128 v32; // xmm2
  float v33; // xmm8_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm8_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm9_4
  float v40; // xmm6_4
  float v41; // xmm10_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm6_4
  float v45; // xmm2_4
  float v46; // xmm8_4
  float v47; // xmm6_4
  float v48; // xmm5_4
  float v49; // xmm3_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-D8h]

  v3 = this->m_pSimObject.m_pPointer;
  v4 = pInteractorTNC;
  v5 = pRootTNC;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->m_pTransformNodeComponent;
    if ( v7 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pInteractorTNC);
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      v10 = (__m128)LODWORD(v4->mWorldTransform.v3.x);
      v8 = v5->mWorldTransform.v3.x;
      v9 = v5->mWorldTransform.v3.y;
      v10.m128_f32[0] = v10.m128_f32[0] - v8;
      v12 = v10;
      v11 = v4->mWorldTransform.v3.y - v9;
      v12.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v11 * v11);
      if ( v12.m128_f32[0] == 0.0 )
        v13 = 0.0;
      else
        v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
      v14 = v6->m_fDistance;
      v15 = v10.m128_f32[0] * v13;
      v16 = v13 * v11;
      v17 = v13 * 0.0;
      v18 = v14 * v16;
      v19 = LODWORD(v16) ^ _xmm[0];
      v20 = (float)(v15 * v14) + v8;
      v21 = v18 + v9;
      v22 = LODWORD(v15) ^ _xmm[0];
      v23 = v14 * v17;
      v24 = LODWORD(v17) ^ _xmm[0];
      v25 = v23 + v5->mWorldTransform.v3.z;
      v26 = (float)((float)(*(float *)&v19 * *(float *)&v19) + (float)(*(float *)&v22 * *(float *)&v22))
          + (float)(*(float *)&v24 * *(float *)&v24);
      if ( v26 == 0.0 )
        v27 = 0.0;
      else
        v27 = 1.0 / fsqrt(v26);
      v28 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v29 = *(float *)&v22 * v27;
      v30 = *(float *)&v19 * v27;
      v31 = *(float *)&v24 * v27;
      m.v0.w = 0.0;
      v32 = v28;
      m.v0.x = v29;
      m.v0.y = v30;
      m.v0.z = v31;
      v32.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0])
                              + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                      + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( v32.m128_f32[0] == 0.0 )
        v33 = 0.0;
      else
        v33 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v32));
      v34 = v33;
      v35 = v33;
      v36 = v33 * UFG::qVector3::msDirUp.z;
      v37 = v35 * UFG::qVector3::msDirUp.x;
      v38 = v34 * UFG::qVector3::msDirUp.y;
      v39 = (float)(v31 * v38) - (float)(v30 * v36);
      v40 = (float)(v29 * v36) - (float)(v31 * v37);
      v41 = (float)(v30 * v37) - (float)(v29 * v38);
      v42 = (float)((float)(v40 * v40) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42 == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / fsqrt(v42);
      v44 = v40 * v43;
      m.v1.w = 0.0;
      m.v1.z = v41 * v43;
      m.v1.x = v39 * v43;
      m.v1.y = v44;
      v45 = (float)((float)(v41 * v43) * v30) - (float)(v44 * v31);
      v46 = (float)((float)(v39 * v43) * v31) - (float)((float)(v41 * v43) * v29);
      v47 = (float)(v44 * v29) - (float)((float)(v39 * v43) * v30);
      v48 = (float)((float)(v46 * v46) + (float)(v45 * v45)) + (float)(v47 * v47);
      if ( v48 == 0.0 )
        v49 = 0.0;
      else
        v49 = 1.0 / fsqrt(v48);
      m.v3.x = v20;
      m.v3.y = v21;
      m.v3.z = v25;
      m.v2.w = 0.0;
      m.v3.w = 1.0;
      m.v2.x = v45 * v49;
      m.v2.y = v46 * v49;
      m.v2.z = v47 * v49;
      UFG::TransformNodeComponent::SetWorldTransform(v7, &m);
    }
  }
}

// File Line: 224
// RVA: 0x562A00
void __fastcall UFG::InteractionPoint::UpdateUsingBone(UFG::InteractionPoint *this, UFG::TransformNodeComponent *pRootTNC, UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *v3; // rax
  UFG::InteractionPoint *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::SimObject *v6; // rcx
  Creature *v7; // rbx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned int v13; // edx
  int v14; // eax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h]

  v3 = this->m_pSimObject.m_pPointer;
  v4 = this;
  if ( v3 )
  {
    v5 = v3->m_pTransformNodeComponent;
    if ( v5 )
    {
      v6 = pRootTNC->m_pSimObject;
      v7 = 0i64;
      if ( v6 )
      {
        v8 = v6->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = v6->m_Components.p[9].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = v6->m_Components.p[8].m_pComponent;
          }
          else if ( (v8 >> 12) & 1 )
          {
            v10 = (unsigned int)v6[1].vfptr;
            v11 = v6->m_Components.size;
            if ( v10 >= v11 )
            {
LABEL_16:
              v9 = 0i64;
            }
            else
            {
              v12 = (signed __int64)&v6->m_Components.p[v10];
              while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::BaseAnimationComponent::_TypeUID & 0xFE000000)
                   || UFG::BaseAnimationComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
              {
                ++v10;
                v12 += 16i64;
                if ( v10 >= v11 )
                  goto LABEL_16;
              }
              v9 = *(UFG::SimComponent **)v12;
            }
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType(v6, UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v9 = v6->m_Components.p[9].m_pComponent;
        }
        if ( v9 )
          v7 = *(Creature **)&v9[2].m_TypeUID;
      }
      if ( v7 )
      {
        v13 = v4->m_uBoneUID.mUID;
        if ( v13 != UFG::gNullQSymbolUC.mUID )
        {
          if ( v7->mPose.mRigHandle.mData )
          {
            v14 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, v13);
            if ( v14 >= 0 )
            {
              Creature::GetTransform(v7, v14, &transform);
              UFG::TransformNodeComponent::SetWorldTransform(v5, &transform);
            }
          }
        }
      }
    }
  }
}

// File Line: 263
// RVA: 0x562FD0
void __fastcall UFG::InteractionPoint::UpdateUsingProjected(UFG::InteractionPoint *this, UFG::TransformNodeComponent *pRootTNC, UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *v3; // rax
  UFG::TransformNodeComponent *v4; // r15
  UFG::TransformNodeComponent *v5; // rsi
  UFG::InteractionPoint *v6; // rbp
  UFG::TransformNodeComponent *v7; // r12
  float *v8; // rdi
  char v9; // r14
  UFG::SimObject *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // r9
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // er10
  signed __int64 v18; // r9
  unsigned int v19; // edx
  unsigned int v20; // er10
  __int64 v21; // rbx
  UFG::TransformNodeComponent *v22; // rbx
  float *v23; // rbx
  float v24; // xmm11_4
  float v25; // xmm8_4
  float v26; // xmm11_4
  float v27; // xmm12_4
  __int128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  __m128 v34; // xmm7
  float v35; // xmm0_4
  __int128 v36; // xmm7
  __m128 v37; // xmm9
  float v38; // xmm6_4
  __m128 v39; // xmm2
  float v40; // xmm10_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm10_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  __int128 v46; // xmm13
  float v47; // xmm14_4
  __m128 v48; // xmm9
  float v49; // xmm14_4
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm9_4
  float v53; // xmm0_4
  __m128 v54; // xmm10
  float v55; // xmm9_4
  float v56; // xmm2_4
  __m128 v57; // xmm5
  float v58; // xmm3_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-E8h]

  v3 = this->m_pSimObject.m_pPointer;
  v4 = pInteractorTNC;
  v5 = pRootTNC;
  v6 = this;
  if ( !v3 )
    return;
  v7 = v3->m_pTransformNodeComponent;
  if ( !v7 )
    return;
  v8 = 0i64;
  v9 = 1;
  if ( this->m_eOffsetTarget == eTARGET_TYPE_INVALID )
    goto LABEL_36;
  v10 = pRootTNC->m_pSimObject;
  if ( !v10 )
    goto LABEL_36;
  v11 = v10->m_Flags;
  if ( !((v11 >> 14) & 1) )
  {
    if ( (v11 & 0x8000u) != 0 )
    {
      v12 = v10->m_Components.p[20].m_pComponent;
      if ( v12 )
      {
        v14 = v12->m_TypeUID;
        v13 = UFG::TargetingSystemPedBaseComponent::_TypeUID;
        v15 = UFG::TargetingSystemPedBaseComponent::_TypeUID ^ v12->m_TypeUID;
        goto LABEL_8;
      }
LABEL_10:
      v12 = 0i64;
      goto LABEL_30;
    }
    if ( (v11 >> 13) & 1 )
    {
      v16 = (unsigned int)v10[1].vfptr;
      v17 = v10->m_Components.size;
      if ( v16 >= v17 )
        goto LABEL_10;
      v18 = (signed __int64)&v10->m_Components.p[v16];
      while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
      {
        ++v16;
        v18 += 16i64;
        if ( v16 >= v17 )
        {
          v12 = 0i64;
          goto LABEL_30;
        }
      }
    }
    else
    {
      if ( !((v11 >> 12) & 1) )
      {
        v12 = UFG::SimObject::GetComponentOfType(v10, UFG::TargetingSystemPedBaseComponent::_TypeUID);
        goto LABEL_30;
      }
      v19 = (unsigned int)v10[1].vfptr;
      v20 = v10->m_Components.size;
      if ( v19 >= v20 )
        goto LABEL_10;
      v18 = (signed __int64)&v10->m_Components.p[v19];
      while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
      {
        ++v19;
        v18 += 16i64;
        if ( v19 >= v20 )
        {
          v12 = 0i64;
          goto LABEL_30;
        }
      }
    }
    v12 = *(UFG::SimComponent **)v18;
    goto LABEL_30;
  }
  v12 = v10->m_Components.p[20].m_pComponent;
  if ( !v12 )
    goto LABEL_10;
  v13 = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  v14 = v12->m_TypeUID;
  v15 = v14 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID;
LABEL_8:
  if ( v15 & 0xFE000000 || v13 & ~v14 & 0x1FFFFFF )
    goto LABEL_10;
LABEL_30:
  if ( !v12 )
  {
LABEL_36:
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v23 = &v5->mWorldTransform.v3.x;
    goto LABEL_37;
  }
  v21 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v12[1].m_Flags + (unsigned int)v6->m_eOffsetTarget + 8i64)
                  + *(_QWORD *)&v12[1].m_TypeUID
                  + 40);
  if ( !v21 || (v22 = *(UFG::TransformNodeComponent **)(v21 + 88)) == 0i64 )
  {
    v9 = 0;
    goto LABEL_36;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v22);
  v8 = &v22->mWorldTransform.v0.x;
  UFG::TransformNodeComponent::UpdateWorldTransform(v22);
  v23 = &v22->mWorldTransform.v3.x;
  if ( !v23 )
    goto LABEL_36;
LABEL_37:
  if ( !v8 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v8 = &v5->mWorldTransform.v0.x;
  }
  if ( v9 )
  {
    v24 = v6->m_fDistance;
    v25 = (float)(v24 * v8[2]) + v23[2];
    v26 = (float)(v24 * *v8) + *v23;
    v27 = (float)(v6->m_fDistance * v8[1]) + v23[1];
  }
  else
  {
    v26 = *v23;
    v27 = v23[1];
    v25 = v23[2];
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v28 = *(unsigned int *)v23;
  v29 = (__m128)*((unsigned int *)v23 + 1);
  *(float *)&v28 = *(float *)&v28 - v4->mWorldTransform.v3.x;
  v29.m128_f32[0] = v29.m128_f32[0] - v4->mWorldTransform.v3.y;
  v30 = v29;
  v30.m128_f32[0] = (float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(*(float *)&v28 * *(float *)&v28);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
  v32 = *(float *)&v28 * v31;
  v29.m128_f32[0] = v29.m128_f32[0] * v31;
  v33 = v31 * 0.0;
  v34 = v29;
  v34.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
  if ( v34.m128_f32[0] == 0.0 )
  {
    v36 = 0i64;
  }
  else
  {
    LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v34);
    v36 = (unsigned int)FLOAT_1_0;
    *(float *)&v36 = 1.0 / v35;
  }
  v37 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  *(float *)&v28 = v32 * *(float *)&v36;
  v38 = v29.m128_f32[0] * *(float *)&v36;
  *(float *)&v36 = *(float *)&v36 * v33;
  m.v0.w = 0.0;
  v39 = v37;
  LODWORD(m.v0.x) = v28;
  m.v0.y = v38;
  LODWORD(m.v0.z) = v36;
  v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v39.m128_f32[0] == 0.0 )
    v40 = 0.0;
  else
    v40 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v39));
  v41 = v40;
  v42 = v40;
  v43 = v40 * UFG::qVector3::msDirUp.z;
  v44 = v42 * UFG::qVector3::msDirUp.x;
  v45 = v41 * UFG::qVector3::msDirUp.y;
  v46 = v36;
  v48 = (__m128)v28;
  *(float *)&v46 = (float)(*(float *)&v36 * v45) - (float)(v38 * v43);
  v47 = v38 * v44;
  v48.m128_f32[0] = (float)(*(float *)&v28 * v43) - (float)(*(float *)&v36 * v44);
  v50 = v48;
  v49 = v47 - (float)(*(float *)&v28 * v45);
  v50.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(*(float *)&v46 * *(float *)&v46))
                  + (float)(v49 * v49);
  if ( v50.m128_f32[0] == 0.0 )
    v51 = 0.0;
  else
    v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
  *(float *)&v46 = *(float *)&v46 * v51;
  v52 = v48.m128_f32[0] * v51;
  m.v1.w = 0.0;
  v54 = (__m128)v46;
  m.v1.z = v49 * v51;
  LODWORD(m.v1.x) = v46;
  m.v1.y = v52;
  v53 = v52 * *(float *)&v36;
  v54.m128_f32[0] = (float)(*(float *)&v46 * *(float *)&v36) - (float)((float)(v49 * v51) * *(float *)&v28);
  v55 = (float)(v52 * *(float *)&v28) - (float)(*(float *)&v46 * v38);
  v56 = (float)((float)(v49 * v51) * v38) - v53;
  v57 = v54;
  v57.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v56 * v56)) + (float)(v55 * v55);
  if ( v57.m128_f32[0] == 0.0 )
    v58 = 0.0;
  else
    v58 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v57));
  m.v3.x = v26;
  m.v3.y = v27;
  m.v3.z = v25;
  m.v2.w = 0.0;
  m.v3.w = 1.0;
  m.v2.x = v56 * v58;
  m.v2.y = v54.m128_f32[0] * v58;
  m.v2.z = v55 * v58;
  UFG::TransformNodeComponent::SetWorldTransform(v7, &m);
}

// File Line: 348
// RVA: 0x562F30
void __fastcall UFG::InteractionPoint::UpdateUsingObjectXform(UFG::InteractionPoint *this, UFG::TransformNodeComponent *pRootTNC, UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *v3; // rax
  UFG::TransformNodeComponent *v4; // rsi
  UFG::InteractionPoint *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx
  UFG::qMatrix44 *v7; // rax
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm0
  UFG::qMatrix44 m; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h]

  v3 = this->m_pSimObject.m_pPointer;
  v4 = pRootTNC;
  v5 = this;
  if ( v3 )
  {
    v6 = v3->m_pTransformNodeComponent;
    if ( v6 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pRootTNC);
      v7 = UFG::qMatrix44::operator*(&v5->m_xform, &result, &v4->mWorldTransform);
      v8 = v7->v2;
      v9 = v7->v3;
      v10 = v7->v0;
      m.v1 = v7->v1;
      m.v2 = v8;
      m.v0 = v10;
      m.v3 = v9;
      UFG::TransformNodeComponent::SetWorldTransform(v6, &m);
    }
  }
}

// File Line: 362
// RVA: 0x548E50
void __fastcall UFG::InteractionPoint::RemoveAllInteractors(UFG::InteractionPoint *this, bool bNotifyInteractors)
{
  UFG::InteractionPoint *v2; // rbx
  unsigned int v3; // eax
  __int64 v4; // r11
  __int64 v5; // rdi
  UFG::InteractorComponent *v6; // r9
  UFG::InteractionPoint *v7; // r8
  unsigned int v8; // er10
  __int64 v9; // rcx
  UFG::InteractorComponent **v10; // rax
  unsigned int v11; // eax
  UFG::InteractorComponent **v12; // rcx

  v2 = this;
  if ( bNotifyInteractors )
  {
    v3 = this->m_InteractorList.size;
    if ( v3 )
    {
      v4 = 0i64;
      v5 = v3;
      do
      {
        v6 = v2->m_InteractorList.p[v4];
        v7 = v6->m_pInteractionPoint;
        if ( v7 )
        {
          v8 = v7->m_InteractorList.size;
          v9 = 0i64;
          if ( v8 )
          {
            v10 = v7->m_InteractorList.p;
            while ( *v10 != v6 )
            {
              v9 = (unsigned int)(v9 + 1);
              ++v10;
              if ( (unsigned int)v9 >= v8 )
                goto LABEL_13;
            }
            v7->m_InteractorList.p[v9] = v7->m_InteractorList.p[v8 - 1];
            v11 = v7->m_InteractorList.size;
            if ( v11 > 1 )
              v7->m_InteractorList.size = v11 - 1;
            else
              v7->m_InteractorList.size = 0;
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
  v12 = v2->m_InteractorList.p;
  if ( v12 )
    operator delete[](v12);
  v2->m_InteractorList.p = 0i64;
  *(_QWORD *)&v2->m_InteractorList.size = 0i64;
}

// File Line: 375
// RVA: 0x5209E0
void __fastcall UFG::InteractionPoint::AddInteractor(UFG::InteractionPoint *this, UFG::InteractorComponent *pInteractor, bool bNotifyInteractor)
{
  bool v3; // bp
  UFG::InteractorComponent *v4; // r14
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v5; // r15
  __int64 v6; // rsi
  unsigned int v7; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::qReflectInventoryBase **v10; // rax

  v3 = bNotifyInteractor;
  v4 = pInteractor;
  v5 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this;
  if ( this->m_InteractorList.size != this->m_InteractorList.capacity )
  {
    do
    {
      v6 = v5[2].size;
      v7 = v5[2].capacity;
      v8 = v6 + 1;
      if ( (signed int)v6 + 1 > v7 )
      {
        if ( v7 )
          v9 = 2 * v7;
        else
          v9 = 1;
        for ( ; v9 < v8; v9 *= 2 )
          ;
        if ( v9 <= 2 )
          v9 = 2;
        if ( v9 - v8 > 0x10000 )
          v9 = v6 + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v5 + 2, v9, "qArray.Add");
      }
      v10 = v5[2].p;
      v5[2].size = v8;
      v10[v6] = (UFG::qReflectInventoryBase *)v4;
      if ( !v3 )
        break;
      v4->m_pInteractionPoint = (UFG::InteractionPoint *)v5;
      v3 = 0;
    }
    while ( v5[2].size != v5[2].capacity );
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
UFG::allocator::free_link *__fastcall UFG::InteractorComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObjectProperties, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h]
  UFG::allocator::free_link *v10; // [rsp+80h] [rbp+18h]

  v2 = pSceneObjectProperties;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x60ui64, "InteractorComponent", 0i64, 1u);
  v5 = v4;
  if ( v4 )
  {
    UFG::SimComponent::SimComponent((UFG::SimComponent *)v4, v2->m_NameUID);
    v5->mNext = (UFG::allocator::free_link *)&UFG::InteractorComponent::`vftable';
    v10 = v5 + 8;
    v10->mNext = v10;
    v10[1].mNext = v10;
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
  v6 = v2->m_pSimObject;
  if ( (v6->m_Flags >> 14) & 1 )
    v7 = 29;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, (UFG::SimComponent *)v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return v5;
}

// File Line: 435
// RVA: 0x51BE10
void __fastcall UFG::InteractorComponent::~InteractorComponent(UFG::InteractorComponent *this)
{
  UFG::InteractorComponent *v1; // r8
  UFG::InteractionPoint *v2; // r9
  unsigned int v3; // er10
  __int64 v4; // rcx
  UFG::InteractorComponent **v5; // rax
  unsigned int v6; // eax
  UFG::qSafePointer<UFG::InteractionPoint,UFG::InteractionPoint> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InteractorComponent::`vftable';
  v2 = this->m_pInteractionPoint;
  if ( v2 )
  {
    v3 = v2->m_InteractorList.size;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = v2->m_InteractorList.p;
      while ( *v5 != v1 )
      {
        v4 = (unsigned int)(v4 + 1);
        ++v5;
        if ( (unsigned int)v4 >= v3 )
          goto LABEL_10;
      }
      v2->m_InteractorList.p[v4] = v2->m_InteractorList.p[v3 - 1];
      v6 = v2->m_InteractorList.size;
      if ( v6 > 1 )
        v2->m_InteractorList.size = v6 - 1;
      else
        v2->m_InteractorList.size = 0;
    }
LABEL_10:
    v1->m_pInteractionPoint = 0i64;
  }
  v7 = &v1->m_pBestInteractionPoint;
  if ( v1->m_pBestInteractionPoint.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pBestInteractionPoint.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pBestInteractionPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *)&v1->m_pBestInteractionPoint.mPrev;
  }
  v1->m_pBestInteractionPoint.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pBestInteractionPoint.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pBestInteractionPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *)&v1->m_pBestInteractionPoint.mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 443
// RVA: 0x540920
void __fastcall UFG::InteractorComponent::OnDetach(UFG::InteractorComponent *this)
{
  UFG::InteractionPoint *v1; // r9
  UFG::InteractorComponent *v2; // r10
  unsigned int v3; // ecx
  unsigned int v4; // er8
  UFG::InteractorComponent **v5; // rax
  unsigned int v6; // eax

  v1 = this->m_pInteractionPoint;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_InteractorList.size;
    v4 = 0;
    if ( v3 )
    {
      v5 = v1->m_InteractorList.p;
      while ( *v5 != v2 )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
        {
          v2->m_pInteractionPoint = 0i64;
          return;
        }
      }
      v1->m_InteractorList.p[v4] = v1->m_InteractorList.p[v3 - 1];
      v6 = v1->m_InteractorList.size;
      if ( v6 <= 1 )
      {
        v1->m_InteractorList.size = 0;
        v2->m_pInteractionPoint = 0i64;
        return;
      }
      v1->m_InteractorList.size = v6 - 1;
    }
    v2->m_pInteractionPoint = 0i64;
  }
}

// File Line: 473
// RVA: 0x54FF90
void __fastcall UFG::InteractorComponent::StartInteraction(UFG::InteractorComponent *this, UFG::InteractionPoint *pIP, bool bNotifyInteractionPoint)
{
  this->m_pInteractionPoint = pIP;
  if ( bNotifyInteractionPoint )
    UFG::InteractionPoint::AddInteractor(pIP, this, 0);
}

// File Line: 486
// RVA: 0x5527F0
void __fastcall UFG::InteractorComponent::StopInteraction(UFG::InteractorComponent *this, bool bNotifyInteractionPoint)
{
  UFG::InteractionPoint *v2; // r8
  UFG::InteractorComponent *v3; // r9
  unsigned int v4; // er10
  __int64 v5; // rcx
  UFG::InteractorComponent **v6; // rax
  unsigned int v7; // eax

  v2 = this->m_pInteractionPoint;
  v3 = this;
  if ( v2 )
  {
    if ( bNotifyInteractionPoint )
    {
      v4 = v2->m_InteractorList.size;
      v5 = 0i64;
      if ( v4 )
      {
        v6 = v2->m_InteractorList.p;
        while ( *v6 != v3 )
        {
          v5 = (unsigned int)(v5 + 1);
          ++v6;
          if ( (unsigned int)v5 >= v4 )
          {
            v3->m_pInteractionPoint = 0i64;
            return;
          }
        }
        v2->m_InteractorList.p[v5] = v2->m_InteractorList.p[v4 - 1];
        v7 = v2->m_InteractorList.size;
        if ( v7 <= 1 )
        {
          v2->m_InteractorList.size = 0;
          v3->m_pInteractionPoint = 0i64;
          return;
        }
        v2->m_InteractorList.size = v7 - 1;
      }
    }
    v3->m_pInteractionPoint = 0i64;
  }
}

// File Line: 499
// RVA: 0x54BD50
void __fastcall UFG::InteractorComponent::SetBestInteractionPoint(UFG::InteractorComponent *this, UFG::InteractionPoint *pIP, bool bUpdateBestInteractionPointTarget)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v3; // r10
  UFG::InteractionPoint *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v5; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObject *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimObject *v10; // rdi
  UFG::SimComponent *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // er9
  signed __int64 v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er9
  __int64 v17; // rax
  unsigned __int8 v18; // cl

  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *)&this->m_pBestInteractionPoint.mPrev;
  v4 = pIP;
  if ( this->m_pBestInteractionPoint.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = this->m_pBestInteractionPoint.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = v3;
    this->m_pBestInteractionPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InteractionPoint>,UFG::qSafePointerNodeList> *)&this->m_pBestInteractionPoint.mPrev;
  }
  this->m_pBestInteractionPoint.m_pPointer = pIP;
  if ( pIP )
  {
    v7 = pIP->m_SafePointerList.mNode.mPrev;
    v7->mNext = v3;
    v3->mPrev = v7;
    this->m_pBestInteractionPoint.mNext = &pIP->m_SafePointerList.mNode;
    pIP->m_SafePointerList.mNode.mPrev = v3;
  }
  if ( bUpdateBestInteractionPointTarget )
  {
    v8 = this->m_pSimObject;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      v10 = 0i64;
      if ( (v9 >> 14) & 1 )
      {
        v11 = v8->m_Components.p[20].m_pComponent;
LABEL_27:
        if ( v11 )
        {
          v17 = ((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[15].__vecDelDtor)(v11);
          if ( v17 )
          {
            if ( v4 )
              v10 = v4->m_pSimObject.m_pPointer;
            v18 = *(_BYTE *)(*(_QWORD *)(v17 + 96) + 76i64);
            if ( v18 )
              UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)(v17 + 88) + 56i64 * v18), v10);
          }
        }
        return;
      }
      if ( (v9 & 0x8000u) != 0 )
      {
        v11 = v8->m_Components.p[20].m_pComponent;
        goto LABEL_27;
      }
      if ( (v9 >> 13) & 1 )
      {
        v12 = (unsigned int)v8[1].vfptr;
        v13 = v8->m_Components.size;
        if ( v12 < v13 )
        {
          v14 = (signed __int64)&v8->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
               || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_17;
          }
LABEL_18:
          v11 = *(UFG::SimComponent **)v14;
          goto LABEL_27;
        }
      }
      else
      {
        if ( !((v9 >> 12) & 1) )
        {
          v11 = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          goto LABEL_27;
        }
        v15 = (unsigned int)v8[1].vfptr;
        v16 = v8->m_Components.size;
        if ( v15 < v16 )
        {
          v14 = (signed __int64)&v8->m_Components.p[v15];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
               || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
          {
            ++v15;
            v14 += 16i64;
            if ( v15 >= v16 )
            {
              v11 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_18;
        }
      }
LABEL_17:
      v11 = 0i64;
      goto LABEL_27;
    }
  }
}      }
          goto LABEL_18;
        }
      }
LABEL_17:
     

// File Line: 520
// RVA: 0x1543F00
__int64 dynamic_initializer_for__UFG::InteractableComponent::s_InteractableComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::InteractableComponent::s_InteractableComponentList__);
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
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qPropertySet *v3; // rax
  UFG::qPropertySet *result; // rax
  UFG::qPropertySet *v5; // rdi
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v2,
         (UFG::qSymbol *)&component_Interactable::sPropertyName.mUID,
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
  v6 = v1->mpWritableProperties;
  if ( !v6 )
    v6 = v1->mpConstProperties;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID, DEPTH_RECURSE);
  if ( !v7 )
    return v5;
  result = UFG::qPropertySet::Get<UFG::qPropertySet>(
             v7,
             (UFG::qSymbol *)&component_Interactable::sPropertyName.mUID,
             DEPTH_RECURSE);
  if ( result )
    result = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(result);
  return result;
}

// File Line: 568
// RVA: 0x546580
component_Interactable *__fastcall UFG::InteractableComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObjectProperties, bool isRequired)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rbx
  component_Interactable *result; // rax
  component_Interactable *v5; // rdi
  UFG::qMemoryPool *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // rdi
  UFG::SimObject *v10; // rdx
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = isRequired;
  v3 = pSceneObjectProperties;
  result = (component_Interactable *)UFG::InteractableComponent::GetDataPtr(pSceneObjectProperties);
  v5 = result;
  if ( result || v2 )
  {
    v6 = UFG::GetSimulationMemoryPool();
    v7 = UFG::qMemoryPool::Allocate(v6, 0x448ui64, "InteractableComponent", 0i64, 1u);
    if ( v7 )
    {
      UFG::InteractableComponent::InteractableComponent((UFG::InteractableComponent *)v7, v3->m_NameUID, v5);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = v3->m_pSimObject;
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 || (v11 & 0x8000u) != 0 )
      v12 = 12;
    else
      v12 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v13, v10, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, v9, v12);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
    result = (component_Interactable *)v9;
  }
  return result;
}

// File Line: 589
// RVA: 0x517F00
void __fastcall UFG::InteractableComponent::InteractableComponent(UFG::InteractableComponent *this, unsigned int name_uid, component_Interactable *dataPtr)
{
  component_Interactable *v3; // rdi
  UFG::InteractableComponent *v4; // rsi
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v5; // rbx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v6; // rax

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InteractableComponent::`vftable';
  v4->m_fUntargetedCountdownTimer = -1.0;
  `eh vector constructor iterator'(
    v4->m_InteractionPoints,
    0xA0ui64,
    6,
    (void (__fastcall *)(void *))UFG::InteractionPoint::InteractionPoint);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v4->m_pTSBC);
  v6 = UFG::InteractableComponent::s_InteractableComponentList.mNode.mPrev;
  UFG::InteractableComponent::s_InteractableComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&UFG::InteractableComponent::s_InteractableComponentList;
  UFG::InteractableComponent::s_InteractableComponentList.mNode.mPrev = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::InteractableComponent::_InteractableComponentTypeUID,
    "InteractableComponent");
  v4->m_InteractionPoints[0].m_OwnerInteractableComponent = v4;
  v4->m_InteractionPoints[1].m_OwnerInteractableComponent = v4;
  v4->m_InteractionPoints[2].m_OwnerInteractableComponent = v4;
  v4->m_InteractionPoints[3].m_OwnerInteractableComponent = v4;
  v4->m_InteractionPoints[4].m_OwnerInteractableComponent = v4;
  v4->m_InteractionPoints[5].m_OwnerInteractableComponent = v4;
  UFG::InteractableComponent::InitFromData(v4, v3);
}

// File Line: 605
// RVA: 0x51BC50
void __fastcall UFG::InteractableComponent::~InteractableComponent(UFG::InteractableComponent *this)
{
  UFG::InteractableComponent *v1; // rdi
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v2; // rbx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v3; // rcx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v4; // rax
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v5; // rcx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InteractableComponent::`vftable';
  UFG::InteractableComponent::DestroyInteractionPoints(this);
  if ( v1 == UFG::InteractableComponent::s_InteractableComponentpCurrentIterator )
    UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = (UFG::InteractableComponent *)&v1->mPrev[-4];
  v2 = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTSBC);
  `eh vector destructor iterator'(
    v1->m_InteractionPoints,
    0xA0ui64,
    6,
    (void (__fastcall *)(void *))UFG::InteractionPoint::~InteractionPoint);
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 612
// RVA: 0x154CC90
__int64 UFG::_dynamic_initializer_for__symInteractionPoints__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("InteractionPoints", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symInteractionPoints, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symInteractionPoints__);
}

// File Line: 613
// RVA: 0x154CE10
__int64 UFG::_dynamic_initializer_for__symTarget__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Target", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symTarget, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symTarget__);
}

// File Line: 616
// RVA: 0x536660
void __fastcall UFG::InteractableComponent::InitFromData(UFG::InteractableComponent *this, component_Interactable *dataPtr)
{
  UFG::InteractableComponent *v2; // r15
  __int64 v3; // rax
  UFG::qPropertyList *v4; // rsi
  unsigned int v5; // er14
  unsigned int v6; // edi
  char *v7; // rax
  __int64 v8; // rcx
  UFG::qPropertySet *v9; // rbx
  schema_interactionPoint *v10; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  unsigned int v12; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  if ( dataPtr )
  {
    v2 = this;
    v3 = dataPtr->InteractionPoints.mOffset;
    if ( dataPtr->InteractionPoints.mOffset )
    {
      v4 = (UFG::qPropertyList *)((char *)dataPtr + v3);
      if ( (component_Interactable *)((char *)dataPtr + v3) )
      {
        v5 = v4->mNumElements;
        v6 = 0;
        if ( v5 )
        {
          do
          {
            v7 = UFG::qPropertyList::GetValuePtr(v4, 0x1Au, v6);
            if ( v7 )
            {
              v8 = *(_QWORD *)v7;
              if ( *(_QWORD *)v7 )
              {
                v9 = (UFG::qPropertySet *)&v7[v8];
                if ( &v7[v8] )
                {
                  if ( schema_interactionPoint::IsClass(v9->mSchemaName.mUID) )
                    v10 = (schema_interactionPoint *)UFG::qPropertySet::GetMemImagePtr(v9);
                  else
                    v10 = 0i64;
                  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
                  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
                  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
                  pTrackEnumBinding.m_EnumSymbol.mUID = v10->IPTarget.mUID;
                  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
                  pTrackEnumBinding.m_uEnumUID = 0;
                  if ( UFG::gTargetTypeEnum.m_enumLists.size )
                  {
                    TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
                  }
                  else
                  {
                    v11 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
                    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
                    pTrackEnumBinding.mPrev = v11;
                    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
                    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
                  UFG::InteractionPoint::InitFromDataPtr(&v2->m_InteractionPoints[v12], v10);
                  v13 = pTrackEnumBinding.mPrev;
                  v14 = pTrackEnumBinding.mNext;
                  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
                  v14->mPrev = v13;
                  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
                  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
                }
              }
            }
            ++v6;
          }
          while ( v6 < v5 );
        }
      }
    }
  }
}

// File Line: 654
// RVA: 0x53E390
void __fastcall UFG::InteractableComponent::OnAttach(UFG::InteractableComponent *this, UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v2; // r8
  UFG::SimObject *v3; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx

  v2 = &this->m_pTSBC;
  v3 = pSimObject;
  if ( this->m_pTSBC.m_pSimComponent )
  {
    v4 = this->m_pTSBC.mNext;
    v5 = v2->mPrev;
    v5->mNext = v4;
    v4->mPrev = v5;
    v2->m_pSimComponent = 0i64;
LABEL_7:
    v2->m_pSimObject = 0i64;
    v2->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pTSBC.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)this->m_pTSBC.mNext != &this->m_pTSBC) )
  {
    v6 = this->m_pTSBC.mNext;
    v7 = v2->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v2->m_Changed = 1;
  v2->m_pSimObject = v3;
  v2->m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(v2, v3);
}

// File Line: 661
// RVA: 0x5408B0
void __fastcall UFG::InteractableComponent::OnDetach(UFG::InteractableComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  v1 = &this->m_pTSBC;
  if ( this->m_pTSBC.m_pSimComponent )
  {
    v2 = this->m_pTSBC.mNext;
    v3 = v1->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimComponent = 0i64;
    v1->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->m_pTSBC.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v1->mPrev != v1
       || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)this->m_pTSBC.mNext != &this->m_pTSBC) )
    {
      v4 = this->m_pTSBC.mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->m_pSimObject = 0i64;
    }
    v1->m_Changed = 1;
  }
}

// File Line: 718
// RVA: 0x55E230
void __fastcall UFG::InteractableComponent::UpdateAll(float sim_time_delta)
{
  float v1; // xmm7_4
  unsigned __int64 v2; // rdi
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v3; // rcx
  UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm0_4
  unsigned __int64 v7; // rax

  v1 = sim_time_delta;
  v2 = UFG::qGetTicks();
  v3 = UFG::InteractableComponent::s_InteractableComponentList.mNode.mNext - 4;
  for ( UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = (UFG::InteractableComponent *)&UFG::InteractableComponent::s_InteractableComponentList.mNode.mNext[-4];
        v3 != (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)(&UFG::InteractableComponent::s_InteractableComponentList
                                                                                  - 4);
        UFG::InteractableComponent::s_InteractableComponentpCurrentIterator = (UFG::InteractableComponent *)v3 )
  {
    if ( ((_QWORD)v3[2].mPrev & 3) == 1 )
    {
      v4 = v3[67].mPrev;
      if ( v4 )
      {
        v5 = *(float *)&v3[5].mPrev;
        if ( v5 >= 0.0 )
        {
          if ( v4[7].mPrev == (UFG::qNode<UFG::InteractableComponent,UFG::InteractableComponent> *)&v4[6].mNext )
          {
            v6 = v5 - v1;
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
                                               + UFG::qGetTickTime(v2, v7);
}

// File Line: 747
// RVA: 0x5248C0
void __fastcall UFG::InteractableComponent::CreateInteractionPoints(UFG::InteractableComponent *this)
{
  signed int v1; // ebx
  UFG::InteractableComponent *v2; // rdi
  signed __int64 v3; // rsi
  UFG::eTargetTypeEnum v4; // er8
  signed __int64 v5; // rax
  UFG::InteractionPoint *v6; // rcx

  v1 = 69;
  v2 = this;
  v3 = 6i64;
  do
  {
    if ( v1 <= 69 )
    {
      v4 = 69;
    }
    else
    {
      v4 = v1;
      if ( v1 >= 74 )
        v4 = 74;
    }
    v5 = (unsigned int)(v4 - 69);
    if ( v4 == 69 )
    {
      v5 = 0i64;
    }
    else if ( (unsigned int)v5 >= 5 )
    {
      v5 = 5i64;
    }
    v6 = &v2->m_InteractionPoints[v5];
    if ( v6->m_bIsActive )
      UFG::InteractionPoint::CreateSimObject(
        v6,
        v2->m_pSimObject,
        (UFG::TargetingSystemBaseComponent *)v2->m_pTSBC.m_pSimComponent,
        v4);
    else
      UFG::InteractionPoint::DestroySimObject(v6, (UFG::TargetingSystemBaseComponent *)v2->m_pTSBC.m_pSimComponent, v4);
    ++v1;
    v2->m_fUntargetedCountdownTimer = UFG::InteractableComponent::ms_fTimeUntargetedToRemoveInteractionPoints;
    --v3;
  }
  while ( v3 );
}

// File Line: 759
// RVA: 0x525400
void __fastcall UFG::InteractableComponent::DestroyInteractionPoints(UFG::InteractableComponent *this)
{
  signed int v1; // esi
  UFG::InteractableComponent *v2; // r14
  UFG::InteractionPoint *v3; // rbx
  signed __int64 v4; // rbp
  UFG::eTargetTypeEnum v5; // er8
  unsigned int v6; // eax
  __int64 v7; // r11
  __int64 v8; // rdi
  UFG::InteractorComponent *v9; // r9
  UFG::InteractionPoint *v10; // r8
  unsigned int v11; // er10
  __int64 v12; // rcx
  UFG::InteractorComponent **v13; // rax
  unsigned int v14; // eax
  UFG::InteractorComponent **v15; // rcx

  v1 = 69;
  v2 = this;
  v3 = this->m_InteractionPoints;
  v4 = 6i64;
  do
  {
    if ( v1 <= 69 )
    {
      v5 = 69;
    }
    else
    {
      v5 = v1;
      if ( v1 >= 74 )
        v5 = 74;
    }
    UFG::InteractionPoint::DestroySimObject(v3, (UFG::TargetingSystemBaseComponent *)v2->m_pTSBC.m_pSimComponent, v5);
    v6 = v3->m_InteractorList.size;
    if ( v6 )
    {
      v7 = 0i64;
      v8 = v6;
      do
      {
        v9 = v3->m_InteractorList.p[v7];
        v10 = v9->m_pInteractionPoint;
        if ( v10 )
        {
          v11 = v10->m_InteractorList.size;
          v12 = 0i64;
          if ( v11 )
          {
            v13 = v10->m_InteractorList.p;
            while ( *v13 != v9 )
            {
              v12 = (unsigned int)(v12 + 1);
              ++v13;
              if ( (unsigned int)v12 >= v11 )
                goto LABEL_17;
            }
            v10->m_InteractorList.p[v12] = v10->m_InteractorList.p[v11 - 1];
            v14 = v10->m_InteractorList.size;
            if ( v14 > 1 )
              v10->m_InteractorList.size = v14 - 1;
            else
              v10->m_InteractorList.size = 0;
          }
LABEL_17:
          v9->m_pInteractionPoint = 0i64;
        }
        ++v7;
        --v8;
      }
      while ( v8 );
    }
    v15 = v3->m_InteractorList.p;
    if ( v15 )
      operator delete[](v15);
    v3->m_InteractorList.p = 0i64;
    *(_QWORD *)&v3->m_InteractorList.size = 0i64;
    ++v3;
    ++v1;
    --v4;
  }
  while ( v4 );
}

// File Line: 807
// RVA: 0x560380
void __fastcall UFG::InteractableComponent::UpdateInteractionPoints(UFG::InteractableComponent *this, UFG::TransformNodeComponent *pInteractorTNC)
{
  UFG::SimObject *v2; // rdi
  UFG::TransformNodeComponent *v3; // rsi
  UFG::InteractableComponent *v4; // r13
  UFG::TransformNodeComponent *v5; // rdi
  UFG::InteractionPoint *v6; // rbx
  signed __int64 v7; // r12
  UFG::eInteractionPointUpdateEnum v8; // ecx
  UFG::SimObject *v9; // r15
  UFG::TransformNodeComponent *v10; // r14
  UFG::TransformNodeComponent *v11; // rbp
  __int128 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::SimObject *v15; // rcx
  UFG::TransformNodeComponent *v16; // rcx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-78h]

  v2 = this->m_pSimObject;
  v3 = pInteractorTNC;
  v4 = this;
  if ( v2 )
  {
    v5 = v2->m_pTransformNodeComponent;
    if ( v5 )
    {
      v6 = this->m_InteractionPoints;
      v7 = 6i64;
      do
      {
        v8 = v6->m_eInteractionPointUpdate;
        if ( v8 == 6 )
        {
          v9 = v4->m_InteractionPoints[0].m_pSimObject.m_pPointer;
          if ( v9 )
            v9 = (UFG::SimObject *)v9->m_pTransformNodeComponent;
          v10 = (UFG::TransformNodeComponent *)v4->m_InteractionPoints[1].m_pSimObject.m_pPointer;
          if ( v10 )
            v10 = (UFG::TransformNodeComponent *)v10->mChildren.mNode.mNext;
          v11 = (UFG::TransformNodeComponent *)v4->m_InteractionPoints[2].m_pSimObject.m_pPointer;
          if ( v11 )
            v11 = (UFG::TransformNodeComponent *)v11->mChildren.mNode.mNext;
          if ( v9 )
          {
            if ( v10 )
            {
              if ( v11 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                v12 = *(_OWORD *)&v9[1].m_SafePointerWithCallbackList.mNode.mNext;
                v13 = *(UFG::qVector4 *)v9[1].mNode.mChild;
                v14 = *(UFG::qVector4 *)&v9[1].vfptr;
                m.v1 = *(UFG::qVector4 *)&v9[1].m_SafePointerList.mNode.mNext;
                m.v2 = (UFG::qVector4)v12;
                m.v0 = v14;
                m.v3 = v13;
                UFG::TransformNodeComponent::UpdateWorldTransform(v11);
                UFG::TransformNodeComponent::UpdateWorldTransform(v10);
                v15 = v6->m_pSimObject.m_pPointer;
                *(float *)&v12 = (float)(v10->mWorldTransform.v3.y + v11->mWorldTransform.v3.y) * 0.5;
                v13.x = v10->mWorldTransform.v3.z + v11->mWorldTransform.v3.z;
                v14.x = v10->mWorldTransform.v3.w + v11->mWorldTransform.v3.w;
                m.v3.x = (float)(v10->mWorldTransform.v3.x + v11->mWorldTransform.v3.x) * 0.5;
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
        else if ( v6->m_pSimObject.m_pPointer )
        {
          v17 = v8 - 1;
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
                    UFG::InteractionPoint::UpdateUsingObjectXform(v6, v5, v3);
                }
                else
                {
                  UFG::InteractionPoint::UpdateUsingProjected(v6, v5, v3);
                }
              }
              else
              {
                UFG::InteractionPoint::UpdateUsingBone(v6, v5, v3);
              }
            }
            else
            {
              UFG::InteractionPoint::UpdateUsingDistance(v6, v5, v3);
            }
          }
          else
          {
            UFG::InteractionPoint::UpdateUsingRoot(v6, v5, v3);
          }
        }
        ++v6;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 845
// RVA: 0x54D930
void __fastcall UFG::InteractableComponent::SetIsActive(UFG::InteractableComponent *this, UFG::eTargetTypeEnum eTargetType, const bool bIsActive)
{
  unsigned __int32 v3; // edx

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
UFG::InteractionPoint *__fastcall UFG::InteractableComponent::FindBestInteractionPoint(UFG::InteractableComponent *this, UFG::SimObject *pInteractingSO, UFG::qStaticBitField<6> *bfTestIP, const bool bIgnoreMeshTest)
{
  bool v4; // si
  UFG::qStaticBitField<6> *v5; // r12
  UFG::SimObject *v6; // rdi
  UFG::InteractableComponent *v7; // r14
  unsigned int v8; // ebx
  signed __int64 v9; // r13
  UFG::TransformNodeComponent *v10; // r15
  float v11; // xmm6_4
  signed __int64 v12; // r14
  signed __int64 v13; // rsi
  UFG::TransformNodeComponent *v14; // rdi
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rsi
  unsigned int v18; // er8
  unsigned int v19; // er9
  UFG::SimComponentHolder *v20; // rdi
  signed __int64 v21; // rdx
  unsigned int v22; // er8
  unsigned int v23; // er9
  unsigned int v24; // er8
  unsigned int v25; // er9
  float v26; // xmm1_4
  float v27; // xmm2_4
  unsigned int v28; // er15
  signed __int64 v29; // rsi
  UFG::SimObject **v30; // r13
  int v31; // er14
  UFG::SimObject *v32; // rax
  UFG::TransformNodeComponent *v33; // r12
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  int *v36; // rcx
  UFG::DaemonManager *v37; // rax
  int v38; // edi
  float v39; // xmm0_4
  int v40; // eax
  signed __int64 v41; // r8
  signed int v42; // edx
  float *v43; // rcx
  unsigned __int64 v44; // r9
  signed __int64 v45; // rdi
  __int64 v46; // rcx
  UFG::DaemonQueryOutput output; // [rsp+28h] [rbp-D8h]
  __int64 v48; // [rsp+40h] [rbp-C0h]
  void *mem; // [rsp+48h] [rbp-B8h]
  __int64 v50; // [rsp+50h] [rbp-B0h]
  int *v51; // [rsp+58h] [rbp-A8h]
  UFG::FindPathMultiDestPrioritizedImmediateQuery v52; // [rsp+60h] [rbp-A0h]
  UFG::HavokNavPosition npPosition; // [rsp+E0h] [rbp-20h]
  __int64 v54; // [rsp+120h] [rbp+20h]
  int v55[14]; // [rsp+128h] [rbp+28h]
  UFG::InteractableComponent *v56; // [rsp+1A0h] [rbp+A0h]
  UFG::qStaticBitField<6> *v57; // [rsp+1B0h] [rbp+B0h]

  v57 = bfTestIP;
  v56 = this;
  v54 = -2i64;
  v4 = bIgnoreMeshTest;
  v5 = bfTestIP;
  v6 = pInteractingSO;
  v7 = this;
  v8 = 0;
  v9 = 0i64;
  if ( !pInteractingSO )
    return 0i64;
  v10 = pInteractingSO->m_pTransformNodeComponent;
  if ( !v10 )
    return 0i64;
  UFG::InteractableComponent::CreateInteractionPoints(this);
  UFG::InteractableComponent::UpdateInteractionPoints(v7, v10);
  if ( v4 )
  {
    v11 = FLOAT_3_4028235e38;
    v12 = 1i64;
    v13 = (signed __int64)&v56->m_InteractionPoints[0].m_pSimObject.m_pPointer;
    do
    {
      if ( v12 & v5[(signed __int64)(signed int)v8 >> 6].mBits[0] )
      {
        if ( *(_QWORD *)v13 )
        {
          v14 = *(UFG::TransformNodeComponent **)(*(_QWORD *)v13 + 88i64);
          if ( v14 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(*(_QWORD *)v13 + 88i64));
            UFG::TransformNodeComponent::UpdateWorldTransform(v14);
            UFG::TransformNodeComponent::UpdateWorldTransform(v10);
            if ( (float)((float)((float)((float)(v10->mWorldTransform.v3.y - v14->mWorldTransform.v3.y)
                                       * (float)(v10->mWorldTransform.v3.y - v14->mWorldTransform.v3.y))
                               + (float)((float)(v10->mWorldTransform.v3.x - v14->mWorldTransform.v3.x)
                                       * (float)(v10->mWorldTransform.v3.x - v14->mWorldTransform.v3.x)))
                       + (float)((float)(v10->mWorldTransform.v3.z - v14->mWorldTransform.v3.z)
                               * (float)(v10->mWorldTransform.v3.z - v14->mWorldTransform.v3.z))) < v11 )
            {
              v11 = (float)((float)((float)(v10->mWorldTransform.v3.y - v14->mWorldTransform.v3.y)
                                  * (float)(v10->mWorldTransform.v3.y - v14->mWorldTransform.v3.y))
                          + (float)((float)(v10->mWorldTransform.v3.x - v14->mWorldTransform.v3.x)
                                  * (float)(v10->mWorldTransform.v3.x - v14->mWorldTransform.v3.x)))
                  + (float)((float)(v10->mWorldTransform.v3.z - v14->mWorldTransform.v3.z)
                          * (float)(v10->mWorldTransform.v3.z - v14->mWorldTransform.v3.z));
              v9 = v13 - 72;
            }
          }
        }
      }
      ++v8;
      v12 = __ROL8__(v12, 1);
      v13 += 160i64;
    }
    while ( v8 < 6 );
    return (UFG::InteractionPoint *)v9;
  }
  v16 = v6->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = v6->m_Components.p[36].m_pComponent;
    goto LABEL_38;
  }
  if ( (v16 & 0x8000u) != 0 )
  {
    v18 = (unsigned int)v6[1].vfptr;
    v19 = v6->m_Components.size;
    if ( v18 < v19 )
    {
      v20 = v6->m_Components.p;
      while ( 1 )
      {
        v21 = v18;
        if ( (v20[v18].m_TypeUID & 0xFE000000) == (UFG::NavComponent::_TypeUID & 0xFE000000)
          && !(UFG::NavComponent::_TypeUID & ~v20[v18].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v18 >= v19 )
          goto LABEL_22;
      }
LABEL_21:
      v17 = v20[v21].m_pComponent;
      goto LABEL_38;
    }
    goto LABEL_22;
  }
  if ( (v16 >> 13) & 1 )
  {
    v22 = (unsigned int)v6[1].vfptr;
    v23 = v6->m_Components.size;
    if ( v22 < v23 )
    {
      v20 = v6->m_Components.p;
      while ( 1 )
      {
        v21 = v22;
        if ( (v20[v22].m_TypeUID & 0xFE000000) == (UFG::NavComponent::_TypeUID & 0xFE000000)
          && !(UFG::NavComponent::_TypeUID & ~v20[v22].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_21;
        }
        if ( ++v22 >= v23 )
          goto LABEL_22;
      }
    }
    goto LABEL_22;
  }
  if ( (v16 >> 12) & 1 )
  {
    v24 = (unsigned int)v6[1].vfptr;
    v25 = v6->m_Components.size;
    if ( v24 < v25 )
    {
      v20 = v6->m_Components.p;
      do
      {
        v21 = v24;
        if ( (v20[v24].m_TypeUID & 0xFE000000) == (UFG::NavComponent::_TypeUID & 0xFE000000)
          && !(UFG::NavComponent::_TypeUID & ~v20[v24].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_21;
        }
      }
      while ( ++v24 < v25 );
    }
LABEL_22:
    v17 = 0i64;
    goto LABEL_38;
  }
  v17 = UFG::SimObject::GetComponentOfType(v6, UFG::NavComponent::_TypeUID);
LABEL_38:
  v52.m_daemonType = 0;
  *(_QWORD *)&v52.m_internalType = 1i64;
  v52.m_pOutput = 0i64;
  v52.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathMultiDestPrioritizedImmediateQuery::`vftable';
  v52.m_npFrom.m_vPosition = UFG::qVector3::msZero;
  v52.m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  v52.m_npFrom.m_bValid = 0;
  v52.m_npFrom.m_hkvMeshPosition = (hkVector4f)hkvZero_34.m_quad;
  *(_QWORD *)&v52.m_npFrom.m_packedKey = -1i64;
  v52.m_pNavParams = 0i64;
  v52.m_maxSearchIterations = -1;
  v52.m_aPrioritizedDestinations.p = 0i64;
  *(_QWORD *)&v52.m_aPrioritizedDestinations.size = 0i64;
  output.m_id = 0;
  *(_QWORD *)&output.m_internalType = 1i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathMultiDestPrioritizedOutput::`vftable';
  mem = 0i64;
  v48 = 0i64;
  v50 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  v26 = v10->mWorldTransform.v3.y;
  v27 = v10->mWorldTransform.v3.z;
  v52.m_npFrom.m_vPosition.x = v10->mWorldTransform.v3.x;
  v52.m_npFrom.m_vPosition.y = v26;
  v52.m_npFrom.m_vPosition.z = v27;
  v52.m_npFrom.m_bValid = 0;
  UFG::HavokNavPosition::Validate(&v52.m_npFrom, 0.050000001, 1.0, 0.0);
  v52.m_pNavParams = (UFG::NavParams *)((char *)&v17[2].m_BoundComponentHandles.mNode.mNext + 4);
  v28 = 0;
  v29 = 1i64;
  v51 = v55;
  v30 = &v56->m_InteractionPoints[0].m_pSimObject.m_pPointer;
  v31 = 0;
  do
  {
    if ( (v29 & v5[(signed __int64)(signed int)v28 >> 6].mBits[0]) != 0 )
    {
      v32 = *v30;
      if ( *v30 )
      {
        v33 = v32->m_pTransformNodeComponent;
        if ( v33 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v32->m_pTransformNodeComponent);
          v34 = (__m128)LODWORD(v33->mWorldTransform.v3.y);
          v35 = (__m128)LODWORD(v33->mWorldTransform.v3.z);
          npPosition.m_vPosition.x = v33->mWorldTransform.v3.x;
          LODWORD(npPosition.m_vPosition.y) = v34.m128_i32[0];
          LODWORD(npPosition.m_vPosition.z) = v35.m128_i32[0];
          npPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
          npPosition.m_bValid = 0;
          *(_QWORD *)&npPosition.m_packedKey = -1i64;
          npPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                  _mm_unpacklo_ps((__m128)LODWORD(npPosition.m_vPosition.x), v35),
                                                  _mm_unpacklo_ps(v34, (__m128)(unsigned int)FLOAT_1_0));
          UFG::HavokNavPosition::Validate(&npPosition, 0.050000001, 1.0, 0.0);
          UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(&v52, &npPosition, 1.0);
          v36 = v51;
          *v51 = v28;
          ++v31;
          v51 = v36 + 1;
        }
        v5 = v57;
      }
    }
    ++v28;
    v29 = __ROL8__(v29, 1);
    v30 += 20;
  }
  while ( v28 < 6 );
  v37 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v37, (UFG::DaemonQueryInput *)&v52.vfptr, &output);
  v38 = -1;
  if ( output.m_status != 3 )
    goto LABEL_75;
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
LABEL_75:
    v45 = 0i64;
  else
    v45 = (signed __int64)&v56->m_InteractionPoints[v55[v38]];
  v46 = v50;
  if ( v50 )
  {
    --*(_DWORD *)(v50 + 40);
    if ( !*(_DWORD *)(v46 + 40) )
      (**(void (__fastcall ***)(__int64, signed __int64))v46)(v46, 1i64);
  }
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v48 = 0i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable';
  if ( v52.m_aPrioritizedDestinations.p )
    operator delete[](v52.m_aPrioritizedDestinations.p);
  v52.m_aPrioritizedDestinations.p = 0i64;
  *(_QWORD *)&v52.m_aPrioritizedDestinations.size = 0i64;
  v52.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable';
  return (UFG::InteractionPoint *)v45;
}

// File Line: 990
// RVA: 0x5286F0
UFG::InteractionPoint *__fastcall UFG::InteractableComponent::FindInteractionPoint(UFG::InteractableComponent *this, UFG::SimObject *pInteractingSO, UFG::eTargetTypeEnum eInteractionPointTargetType, const bool bIgnoreMeshTest)
{
  UFG::InteractionPoint *v4; // rdi
  bool v5; // r14
  UFG::InteractableComponent *v6; // rsi
  UFG::TransformNodeComponent *v7; // rbp
  signed __int64 v8; // rax
  UFG::InteractionPoint *v9; // rbx
  UFG::SimObject *v10; // rdx
  UFG::TransformNodeComponent *v11; // rdx
  UFG::SimObject *v12; // rsi
  UFG::TransformNodeComponent *v13; // rsi
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  UFG::HavokNavPosition v18; // [rsp+20h] [rbp-48h]

  v4 = 0i64;
  v5 = bIgnoreMeshTest;
  v6 = this;
  if ( pInteractingSO )
  {
    v7 = pInteractingSO->m_pTransformNodeComponent;
    if ( v7 )
    {
      v8 = (unsigned int)(eInteractionPointTargetType - 69);
      if ( eInteractionPointTargetType == 69 )
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
      v10 = v6->m_pSimObject;
      v6->m_fUntargetedCountdownTimer = UFG::InteractableComponent::ms_fTimeUntargetedToRemoveInteractionPoints;
      if ( v10 )
      {
        v11 = v10->m_pTransformNodeComponent;
        if ( v11 )
        {
          if ( v9->m_pSimObject.m_pPointer )
          {
            switch ( v9->m_eInteractionPointUpdate )
            {
              case 1:
                UFG::InteractionPoint::UpdateUsingRoot(v9, v11, v7);
                break;
              case 2:
                UFG::InteractionPoint::UpdateUsingDistance(v9, v11, v7);
                break;
              case 3:
                UFG::InteractionPoint::UpdateUsingBone(v9, v11, v7);
                break;
              case 4:
                UFG::InteractionPoint::UpdateUsingProjected(v9, v11, v7);
                break;
              case 5:
                UFG::InteractionPoint::UpdateUsingObjectXform(v9, v11, v7);
                break;
            }
          }
        }
      }
      v12 = v9->m_pSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_pTransformNodeComponent;
        if ( v13 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v13);
          v14 = (__m128)LODWORD(v13->mWorldTransform.v3.x);
          v15 = (__m128)LODWORD(v13->mWorldTransform.v3.y);
          v16 = (__m128)LODWORD(v13->mWorldTransform.v3.z);
          if ( v5 )
          {
            v4 = v9;
          }
          else
          {
            v18.m_vPosition.x = v13->mWorldTransform.v3.x;
            LODWORD(v18.m_vPosition.y) = v15.m128_i32[0];
            v18.m_bValid = 0;
            *(_QWORD *)&v18.m_packedKey = -1i64;
            LODWORD(v18.m_vPosition.z) = v16.m128_i32[0];
            v18.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
            v18.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v14, v16),
                                             _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
            UFG::HavokNavPosition::Validate(&v18, 0.050000001, 1.0, 0.0);
            if ( v18.m_bValid
              && UFG::HavokAIUtilGame::IsValidKey(v18.m_packedKey, v18.m_aiMeshUid)
              && v18.m_packedKey != -1
              && v18.m_aiMeshUid != -1 )
            {
              v4 = v9;
            }
          }
        }
      }
    }
  }
  return v4;
}

