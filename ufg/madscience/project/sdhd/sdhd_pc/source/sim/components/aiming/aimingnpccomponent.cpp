// File Line: 31
// RVA: 0x532650
signed __int64 __fastcall UFG::AimingNPCComponent::GetTypeSize(UFG::AimingNPCComponent *this)
{
  return 456i64;
}

// File Line: 53
// RVA: 0x545C90
UFG::SimComponent *__fastcall UFG::AimingNPCComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbp
  UFG::SimObject *v3; // rdi
  UFG::SimComponent *v4; // rsi
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // ecx
  unsigned int v8; // er9
  UFG::SimComponentHolder *v9; // rbx
  signed __int64 v10; // r8
  unsigned int v11; // ecx
  unsigned int v12; // er9
  unsigned int v13; // ecx
  unsigned int v14; // er9
  UFG::qMemoryPool *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::qPropertySet *v18; // r8
  UFG::SimComponent *v19; // rax
  unsigned int v20; // ebx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = pSceneObj->m_pSimObject;
  v4 = 0i64;
  if ( !v3 )
    goto LABEL_30;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[47].m_pComponent;
    goto LABEL_28;
  }
  if ( (v5 & 0x8000u) != 0 )
  {
    v7 = (unsigned int)v3[1].vfptr;
    v8 = v3->m_Components.size;
    if ( v7 < v8 )
    {
      v9 = v3->m_Components.p;
      while ( 1 )
      {
        v10 = v7;
        if ( (v9[v7].m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::AimingBaseComponent::_TypeUID & ~v9[v7].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v7 >= v8 )
          goto LABEL_12;
      }
LABEL_11:
      v6 = v9[v10].m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_12;
  }
  if ( (v5 >> 13) & 1 )
  {
    v11 = (unsigned int)v3[1].vfptr;
    v12 = v3->m_Components.size;
    if ( v11 < v12 )
    {
      v9 = v3->m_Components.p;
      while ( 1 )
      {
        v10 = v11;
        if ( (v9[v11].m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::AimingBaseComponent::_TypeUID & ~v9[v11].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_11;
        }
        if ( ++v11 >= v12 )
          goto LABEL_12;
      }
    }
    goto LABEL_12;
  }
  if ( (v5 >> 12) & 1 )
  {
    v13 = (unsigned int)v3[1].vfptr;
    v14 = v3->m_Components.size;
    if ( v13 < v14 )
    {
      v9 = v3->m_Components.p;
      do
      {
        v10 = v13;
        if ( (v9[v13].m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::AimingBaseComponent::_TypeUID & ~v9[v13].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_11;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_12:
    v6 = 0i64;
    goto LABEL_28;
  }
  v6 = UFG::SimObject::GetComponentOfType(v3, UFG::AimingBaseComponent::_TypeUID);
LABEL_28:
  if ( v6 )
    return 0i64;
LABEL_30:
  v16 = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(v16, 0x1C8ui64, "AimingNPCComponent", 0i64, 1u);
  if ( v17 )
  {
    v18 = v2->mpWritableProperties;
    if ( !v18 )
      v18 = v2->mpConstProperties;
    UFG::AimingNPCComponent::AimingNPCComponent((UFG::AimingNPCComponent *)v17, v2->m_NameUID, v18);
    v4 = v19;
  }
  if ( (v3->m_Flags >> 14) & 1 )
    v20 = 47;
  else
    v20 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v21, v3, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, v4, v20);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  return v4;
}

// File Line: 71
// RVA: 0x154CB90
__int64 UFG::_dynamic_initializer_for__symBaseAccuracy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BaseAIAimingAccuracy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBaseAccuracy, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symBaseAccuracy__);
}

// File Line: 72
// RVA: 0x154CBD0
__int64 UFG::_dynamic_initializer_for__symBaseAccuracyVersusNPC__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BaseAIAimingAccuracyVersusNPC", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBaseAccuracyVersusNPC, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symBaseAccuracyVersusNPC__);
}

// File Line: 75
// RVA: 0x56BFB0
void __fastcall UFG::AimingNPCComponent::propertiesLoad(UFG::AimingNPCComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::qPropertySet *v2; // rdi
  UFG::AimingNPCComponent *v3; // rbx
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rcx
  float *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SceneObjectProperties *v8; // rax
  float *v9; // rax

  v1 = this->m_pSimObject;
  v2 = 0i64;
  v3 = this;
  if ( v1 && (v4 = v1->m_pSceneObj) != 0i64 )
  {
    v5 = v4->mpWritableProperties;
    if ( !v5 )
      v5 = v4->mpConstProperties;
  }
  else
  {
    v5 = 0i64;
  }
  v3->m_fBaseAIAccuracy = -1.0;
  v3->m_fPlayerDodgeFactor = 0.0;
  if ( v5 )
  {
    v6 = UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&UFG::symBaseAccuracy.mUID, DEPTH_RECURSE);
    if ( v6 )
      v3->m_fBaseAIAccuracy = *v6;
  }
  v7 = v3->m_pSimObject;
  if ( v7 )
  {
    v8 = v7->m_pSceneObj;
    if ( v8 )
    {
      v2 = v8->mpWritableProperties;
      if ( !v2 )
        v2 = v8->mpConstProperties;
    }
  }
  v3->m_fBaseAIAccuracyVersusNPC = v3->m_fBaseAIAccuracy;
  if ( v2 )
  {
    v9 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&UFG::symBaseAccuracyVersusNPC.mUID, DEPTH_RECURSE);
    if ( v9 )
      v3->m_fBaseAIAccuracyVersusNPC = *v9;
  }
}

// File Line: 117
// RVA: 0x515730
void __fastcall UFG::AimingNPCComponent::AimingNPCComponent(UFG::AimingNPCComponent *this, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::AimingNPCComponent *v3; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+58h] [rbp+20h]

  v3 = this;
  UFG::AimingBaseComponent::AimingBaseComponent((UFG::AimingBaseComponent *)&this->vfptr, name_uid, properties, 0);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingNPCComponent::`vftable'{for `UFG::SimComponent'};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingNPCComponent::`vftable'{for `UFG::UpdateInterface'};
  v3->m_fBaseAIAccuracy = -1.0;
  v3->m_fBaseAIAccuracyVersusNPC = -1.0;
  v3->m_fPlayerDodgeFactor = 0.0;
  v4 = &v3->m_pSimTargetAimPos;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v3->m_pSimTargetAimPos.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::AimingNPCComponent::_AimingNPCComponentTypeUID,
    "AimingNPCComponent");
}

// File Line: 144
// RVA: 0x51A940
void __fastcall UFG::AimingNPCComponent::~AimingNPCComponent(UFG::AimingNPCComponent *this)
{
  UFG::AimingNPCComponent *v1; // rbx
  UFG::SimObject *v2; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingNPCComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingNPCComponent::`vftable'{for `UFG::UpdateInterface'};
  v2 = this->m_pSimTargetAimPos.m_pPointer;
  if ( v2 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v2);
    v3 = &v1->m_pSimTargetAimPos;
    if ( v1->m_pSimTargetAimPos.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v1->m_pSimTargetAimPos.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v1->m_pSimTargetAimPos.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetAimPos.mPrev;
    }
    v1->m_pSimTargetAimPos.m_pPointer = 0i64;
  }
  v6 = &v1->m_pSimTargetAimPos;
  if ( v1->m_pSimTargetAimPos.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->m_pSimTargetAimPos.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->m_pSimTargetAimPos.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetAimPos.mPrev;
  }
  v1->m_pSimTargetAimPos.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->m_pSimTargetAimPos.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->m_pSimTargetAimPos.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetAimPos.mPrev;
  UFG::AimingBaseComponent::~AimingBaseComponent((UFG::AimingBaseComponent *)&v1->vfptr);
}

// File Line: 157
// RVA: 0x53D0A0
void __fastcall UFG::AimingNPCComponent::OnAttach(UFG::AimingNPCComponent *this, UFG::SimObject *pSimObject)
{
  UFG::AimingNPCComponent *v2; // rbx

  v2 = this;
  UFG::AimingBaseComponent::OnAttach((UFG::AimingBaseComponent *)&this->vfptr, pSimObject);
  UFG::AimingNPCComponent::propertiesLoad(v2);
}

// File Line: 166
// RVA: 0x53FBB0
void __fastcall UFG::AimingNPCComponent::OnDetach(UFG::AimingNPCComponent *this)
{
  UFG::AimingNPCComponent *v1; // rbx
  UFG::SimObject *v2; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  UFG::AimingBaseComponent::OnDetach((UFG::AimingBaseComponent *)&this->vfptr);
  v2 = v1->m_pSimTargetAimPos.m_pPointer;
  if ( v2 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v2);
    v3 = &v1->m_pSimTargetAimPos;
    if ( v1->m_pSimTargetAimPos.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v1->m_pSimTargetAimPos.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v1->m_pSimTargetAimPos.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetAimPos.mPrev;
    }
    v1->m_pSimTargetAimPos.m_pPointer = 0i64;
  }
}

// File Line: 179
// RVA: 0x5586D0
void __fastcall UFG::AimingNPCComponent::Update(UFG::AimingNPCComponent *this, float fDeltaS)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::AimingNPCComponent *v3; // r14
  UFG::qMatrix44 *v4; // rdx
  UFG::AimingBaseComponent *v5; // rcx
  int v6; // xmm0_4
  int v7; // xmm1_4
  __m128 v8; // xmm2
  float v9; // xmm0_4
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-58h]

  v2 = *(UFG::qMatrix44 **)&this->m_Accuracy.m_bEnsureMiss;
  v3 = this;
  UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&this->m_Accuracy.m_bEnsureMiss);
  v4 = v2 + 2;
  v5 = (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent;
  if ( LOBYTE(v3->m_TransformNodeComponent.mNext[35].mPrev) )
  {
    UFG::AimingBaseComponent::updateAimOriginPosition(v5, v4);
    UFG::AimingNPCComponent::updateAimIntentionTargetPosition((UFG::AimingNPCComponent *)((char *)v3 - 64), v2 + 2);
    UFG::AimingBaseComponent::clampAimIntentionTargetPositionDistance((UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent);
    UFG::AimingBaseComponent::updateAimIntention(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      fDeltaS);
    UFG::AimingBaseComponent::clampAimIntention(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      v2 + 2);
    UFG::AimingBaseComponent::updateAimDirection(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      fDeltaS,
      v2 + 2);
    UFG::AimingBaseComponent::updateAimPosition(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      v2 + 2);
    UFG::AimingNPCComponent::updateAccuracy((UFG::AimingNPCComponent *)((char *)v3 - 64), fDeltaS);
  }
  else
  {
    UFG::AimingBaseComponent::updateAimOriginPosition(v5, v4);
    UFG::AimingBaseComponent::GetTargetNormalAimPosition(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      (UFG::qVector3 *)((char *)&v3->m_BoundComponentHandles.mNode.mPrev + 4),
      22i64,
      v2 + 2);
    UFG::AimingBaseComponent::updateAimIntention(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      fDeltaS);
    v6 = (int)v3->m_BoundComponentHandles.mNode.mNext;
    v7 = HIDWORD(v3->m_BoundComponentHandles.mNode.mNext);
    LODWORD(v3->vfptr) = HIDWORD(v3->m_BoundComponentHandles.mNode.mPrev);
    HIDWORD(v3->vfptr) = v6;
    LODWORD(v3->mPrev) = v7;
    v3->m_NameUID = -1082130432;
    *(_DWORD *)&v3->m_Flags = 1065353216;
    UFG::qTranspose(&dest, v2 + 2);
    UFG::AimingBaseComponent::UpdateLocalAimDirection(
      (UFG::AimingBaseComponent *)&v3[-1].m_CharacterOccupantComponent.m_pSimComponent,
      &dest,
      (UFG::qVector3 *)&v3->vfptr);
    v8 = (__m128)LODWORD(v3->m_pSimObject);
    v9 = *((float *)&v3->m_pSimObject + 1) - *(float *)&v3->m_BoundComponentHandles.mNode.mNext;
    v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] - *((float *)&v3->m_BoundComponentHandles.mNode.mPrev + 1))
                                   * (float)(v8.m128_f32[0] - *((float *)&v3->m_BoundComponentHandles.mNode.mPrev + 1)))
                           + (float)(v9 * v9))
                   + (float)((float)(*(float *)&v3->m_BoundComponentHandles.mNode.mPrev
                                   - *((float *)&v3->m_BoundComponentHandles.mNode.mNext + 1))
                           * (float)(*(float *)&v3->m_BoundComponentHandles.mNode.mPrev
                                   - *((float *)&v3->m_BoundComponentHandles.mNode.mNext + 1)));
    v3->m_TypeUID = (unsigned __int128)_mm_sqrt_ps(v8);
  }
}

// File Line: 236
// RVA: 0x56DE10
void __fastcall UFG::AimingNPCComponent::updateAccuracy(UFG::AimingNPCComponent *this, const float fDeltaS)
{
  float v2; // xmm12_4
  UFG::AimingNPCComponent *v3; // rdi
  float v4; // xmm14_4
  float v5; // xmm13_4
  UFG::SimComponent *v6; // rsi
  float v7; // xmm0_4
  UFG::SimComponent *v8; // rdx
  float v9; // xmm11_4
  float v10; // xmm6_4
  __int64 v11; // rbx
  unsigned __int16 v12; // cx
  UFG::AimingBaseComponent *v13; // rax
  unsigned int v14; // er8
  unsigned int v15; // er10
  signed __int64 v16; // rdx
  unsigned int v17; // er8
  unsigned int v18; // er10
  unsigned int v19; // er8
  unsigned int v20; // er10
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  unsigned int v23; // er8
  unsigned int v24; // er10
  signed __int64 v25; // rdx
  unsigned int v26; // er8
  unsigned int v27; // er10
  unsigned int v28; // er8
  unsigned int v29; // er10
  UFG::TransformNodeComponent *v30; // rbx
  __m128 v31; // xmm2
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
  UFG::SimObject *v46; // rcx
  float v47; // xmm6_4
  unsigned __int16 v48; // dx
  unsigned int v49; // er8
  unsigned int v50; // er10
  signed __int64 v51; // rdx
  unsigned int v52; // er8
  unsigned int v53; // er10
  unsigned int v54; // er8
  unsigned int v55; // er10
  unsigned int v56; // er8
  unsigned int v57; // er10
  __int64 v58; // rax
  __int64 v59; // rax
  __int64 v60; // rdx
  int v61; // xmm0_4
  int v62; // xmm0_4
  float v63; // xmm6_4
  float fAccuracyModifierContinuous; // [rsp+C0h] [rbp+8h]
  float fAccuracyModifierInstant; // [rsp+D0h] [rbp+18h]

  v2 = this->m_Accuracy.m_fAccuracyUnclamped;
  v3 = this;
  v4 = fDeltaS;
  if ( v2 <= this->m_Accuracy.m_fAccuracyMinimum )
    v2 = this->m_Accuracy.m_fAccuracyMinimum;
  if ( v2 >= this->m_Accuracy.m_fAccuracyMaximum )
    v2 = this->m_Accuracy.m_fAccuracyMaximum;
  v5 = this->m_Accuracy.m_fAccuracyPenalty;
  v6 = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyMaximum = 1065353216i64;
  v7 = this->m_Accuracy.m_fAccuracyOverride;
  fAccuracyModifierContinuous = 0.0;
  fAccuracyModifierInstant = 0.0;
  if ( v7 < 0.0 )
  {
    v8 = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
    v9 = *(float *)&FLOAT_1_0;
    v10 = 0.0;
    if ( !v8 )
      goto LABEL_133;
    v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + 30i64) + *(_QWORD *)&v8[1].m_TypeUID + 40);
    if ( !v11 )
      goto LABEL_79;
    v12 = *(_WORD *)(v11 + 76);
    if ( (v12 >> 14) & 1 )
    {
      v13 = *(UFG::AimingBaseComponent **)(*(_QWORD *)(v11 + 104) + 752i64);
      goto LABEL_38;
    }
    if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v17 = *(_DWORD *)(v11 + 128);
        v18 = *(_DWORD *)(v11 + 96);
        if ( v17 < v18 )
        {
          v16 = *(_QWORD *)(v11 + 104) + 16i64 * v17;
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
          {
            ++v17;
            v16 += 16i64;
            if ( v17 >= v18 )
            {
              v13 = 0i64;
              goto LABEL_38;
            }
          }
          goto LABEL_22;
        }
      }
      else
      {
        if ( !((v12 >> 12) & 1) )
        {
          v13 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)v11,
                                              UFG::AimingBaseComponent::_TypeUID);
LABEL_38:
          if ( v13 )
            UFG::AimingBaseComponent::ApplyAccuracyModifiers(
              v13,
              1,
              &fAccuracyModifierInstant,
              &fAccuracyModifierContinuous);
          if ( !UFG::IsAnyLocalPlayer((UFG::SimObject *)v11) )
            goto LABEL_78;
          v21 = *(_WORD *)(v11 + 76);
          if ( (v21 >> 14) & 1 )
          {
            v22 = *(UFG::SimComponent **)(*(_QWORD *)(v11 + 104) + 704i64);
            goto LABEL_66;
          }
          if ( (v21 & 0x8000u) == 0 )
          {
            if ( (v21 >> 13) & 1 )
            {
              v26 = *(_DWORD *)(v11 + 128);
              v27 = *(_DWORD *)(v11 + 96);
              if ( v26 < v27 )
              {
                v25 = *(_QWORD *)(v11 + 104) + 16i64 * v26;
                while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                     || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
                {
                  ++v26;
                  v25 += 16i64;
                  if ( v26 >= v27 )
                  {
                    v22 = 0i64;
                    goto LABEL_66;
                  }
                }
                goto LABEL_50;
              }
            }
            else
            {
              if ( !((v21 >> 12) & 1) )
              {
                v22 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)v11,
                        UFG::CharacterOccupantComponent::_TypeUID);
LABEL_66:
                if ( !v22 )
                {
                  v30 = *(UFG::TransformNodeComponent **)(v11 + 88);
                  if ( v30 )
                  {
                    v31 = (__m128)LODWORD(v3->m_vAimOriginPosition.y);
                    v33 = (__m128)LODWORD(v3->m_vAimIntentionTargetPosition.y);
                    v32 = v3->m_vAimIntentionTargetPosition.x - v3->m_vAimOriginPosition.x;
                    v33.m128_f32[0] = v33.m128_f32[0] - v3->m_vAimOriginPosition.y;
                    v34 = v3->m_vAimIntentionTargetPosition.z - v3->m_vAimOriginPosition.z;
                    v31.m128_f32[0] = (float)((float)((float)(v31.m128_f32[0] - v3->m_vAimIntentionTargetPosition.y)
                                                    * (float)(v31.m128_f32[0] - v3->m_vAimIntentionTargetPosition.y))
                                            + (float)((float)(v3->m_vAimOriginPosition.x
                                                            - v3->m_vAimIntentionTargetPosition.x)
                                                    * (float)(v3->m_vAimOriginPosition.x
                                                            - v3->m_vAimIntentionTargetPosition.x)))
                                    + (float)((float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z)
                                            * (float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z));
                    LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v31);
                    v36 = v33;
                    v36.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32))
                                    + (float)(v34 * v34);
                    if ( v36.m128_f32[0] == 0.0 )
                      v37 = 0.0;
                    else
                      v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
                    v38 = v32 * v37;
                    v39 = v33.m128_f32[0] * v37;
                    v40 = v34 * v37;
                    UFG::TransformNodeComponent::UpdateWorldTransform(v30);
                    v41 = (float)((float)(v30->mWorldVelocity.y * v39) + (float)(v30->mWorldVelocity.x * v38))
                        + (float)(v30->mWorldVelocity.z * v40);
                    v42 = (float)((float)((float)(v30->mWorldVelocity.y - (float)(v39 * v41))
                                        * (float)(v30->mWorldVelocity.y - (float)(v39 * v41)))
                                + (float)((float)(v30->mWorldVelocity.x - (float)(v38 * v41))
                                        * (float)(v30->mWorldVelocity.x - (float)(v38 * v41))))
                        + (float)((float)(v30->mWorldVelocity.z - (float)(v40 * v41))
                                * (float)(v30->mWorldVelocity.z - (float)(v40 * v41)));
                    v43 = v42
                        / (float)(UFG::AimingNPCComponent::ms_fPlayerDodgeFactorLateralSpeed
                                * UFG::AimingNPCComponent::ms_fPlayerDodgeFactorLateralSpeed);
                    if ( v43 > 1.0 )
                      v43 = *(float *)&FLOAT_1_0;
                    v3->m_fPlayerDodgeFactor = v43 * UFG::AimingNPCComponent::ms_fPlayerDodgeFactorLateral;
                    if ( v35 < UFG::AimingNPCComponent::ms_fPlayerRushDistance && v41 < -5.0 && v42 < 1.0 )
                      v3->m_fPlayerDodgeFactor = UFG::AimingNPCComponent::ms_fPlayerDodgeFactorRush;
                    if ( UFG::AimingNPCComponent::ms_fPlayerDodgeFactorMinCutoff > v3->m_fPlayerDodgeFactor )
                    {
LABEL_78:
                      v3->m_fPlayerDodgeFactor = 0.0;
                      goto LABEL_79;
                    }
                  }
                }
LABEL_79:
                UFG::AimingBaseComponent::ApplyAccuracyModifiers(
                  (UFG::AimingBaseComponent *)&v3->vfptr,
                  0,
                  &fAccuracyModifierInstant,
                  &fAccuracyModifierContinuous);
                if ( fAccuracyModifierContinuous <= 0.0 )
                {
                  if ( fAccuracyModifierContinuous < 0.0 )
                  {
                    v45 = fAccuracyModifierContinuous + v3->m_Accuracy.m_fAccuracyMaximum;
                    if ( v45 <= 0.0 )
                      v45 = 0.0;
                    v3->m_Accuracy.m_fAccuracyMaximum = v45;
                  }
                }
                else
                {
                  v44 = fAccuracyModifierContinuous + v3->m_Accuracy.m_fAccuracyMinimum;
                  if ( v44 >= 1.0 )
                    v44 = *(float *)&FLOAT_1_0;
                  v3->m_Accuracy.m_fAccuracyMinimum = v44;
                }
                v46 = v3->m_pSimObject;
                v47 = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fDefaultAccuracyRate;
                if ( !v46 )
                  goto LABEL_122;
                v48 = v46->m_Flags;
                if ( (v48 >> 14) & 1 )
                {
                  v49 = (unsigned int)v46[1].vfptr;
                  v50 = v46->m_Components.size;
                  if ( v49 < v50 )
                  {
                    v51 = (signed __int64)&v46->m_Components.p[v49];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF )
                    {
                      ++v49;
                      v51 += 16i64;
                      if ( v49 >= v50 )
                        goto LABEL_118;
                    }
LABEL_95:
                    v6 = *(UFG::SimComponent **)v51;
                    goto LABEL_118;
                  }
                }
                else
                {
                  if ( (v48 & 0x8000u) != 0 )
                  {
                    v52 = (unsigned int)v46[1].vfptr;
                    v53 = v46->m_Components.size;
                    if ( v52 >= v53 )
                      goto LABEL_118;
                    v51 = (signed __int64)&v46->m_Components.p[v52];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF )
                    {
                      ++v52;
                      v51 += 16i64;
                      if ( v52 >= v53 )
                        goto LABEL_118;
                    }
                    goto LABEL_95;
                  }
                  if ( (v48 >> 13) & 1 )
                  {
                    v54 = (unsigned int)v46[1].vfptr;
                    v55 = v46->m_Components.size;
                    if ( v54 >= v55 )
                      goto LABEL_118;
                    v51 = (signed __int64)&v46->m_Components.p[v54];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF )
                    {
                      ++v54;
                      v51 += 16i64;
                      if ( v54 >= v55 )
                        goto LABEL_118;
                    }
                    goto LABEL_95;
                  }
                  if ( !((v48 >> 12) & 1) )
                  {
                    v6 = UFG::SimObject::GetComponentOfType(v46, UFG::TriadWarsComponent::_TypeUID);
                    goto LABEL_118;
                  }
                  v56 = (unsigned int)v46[1].vfptr;
                  v57 = v46->m_Components.size;
                  if ( v56 < v57 )
                  {
                    v51 = (signed __int64)&v46->m_Components.p[v56];
                    while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF )
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
                      v47 = *(float *)(v58 + 88);
                  }
                }
LABEL_122:
                v59 = *(_QWORD *)&v3->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
                if ( v59 )
                {
                  v60 = *(_QWORD *)(*(_QWORD *)(v59 + 176) + 8i64 * *(unsigned int *)(v59 + 172) + 8);
                  if ( *(_DWORD *)(v60 + 100) != UFG::gNullQSymbolUC.mUID )
                    v47 = v47 * *(float *)(v60 + 168);
                }
                *(float *)&v61 = v5;
                if ( v5 < 0.0 )
                  v61 = LODWORD(v5) ^ _xmm[0];
                if ( *(float *)&v61 >= 0.001 )
                  goto LABEL_141;
                *(float *)&v62 = fAccuracyModifierInstant;
                if ( fAccuracyModifierInstant < 0.0 )
                  v62 = LODWORD(fAccuracyModifierInstant) ^ _xmm[0];
                if ( *(float *)&v62 >= 0.001 )
LABEL_141:
                  v10 = COERCE_FLOAT(LODWORD(v5) ^ _xmm[0]) + fAccuracyModifierInstant;
                else
                  v10 = v47 * v4;
LABEL_133:
                v63 = v10 + v2;
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
                v3->m_Accuracy.m_fAccuracyUnclamped = v9;
                return;
              }
              v28 = *(_DWORD *)(v11 + 128);
              v29 = *(_DWORD *)(v11 + 96);
              if ( v28 < v29 )
              {
                v25 = *(_QWORD *)(v11 + 104) + 16i64 * v28;
                while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                     || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
                {
                  ++v28;
                  v25 += 16i64;
                  if ( v28 >= v29 )
                  {
                    v22 = 0i64;
                    goto LABEL_66;
                  }
                }
                goto LABEL_50;
              }
            }
          }
          else
          {
            v23 = *(_DWORD *)(v11 + 128);
            v24 = *(_DWORD *)(v11 + 96);
            if ( v23 < v24 )
            {
              v25 = *(_QWORD *)(v11 + 104) + 16i64 * v23;
              while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                   || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
              {
                ++v23;
                v25 += 16i64;
                if ( v23 >= v24 )
                  goto LABEL_49;
              }
LABEL_50:
              v22 = *(UFG::SimComponent **)v25;
              goto LABEL_66;
            }
          }
LABEL_49:
          v22 = 0i64;
          goto LABEL_66;
        }
        v19 = *(_DWORD *)(v11 + 128);
        v20 = *(_DWORD *)(v11 + 96);
        if ( v19 < v20 )
        {
          v16 = *(_QWORD *)(v11 + 104) + 16i64 * v19;
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
               || UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
          {
            ++v19;
            v16 += 16i64;
            if ( v19 >= v20 )
            {
              v13 = 0i64;
              goto LABEL_38;
            }
          }
          goto LABEL_22;
        }
      }
    }
    else
    {
      v14 = *(_DWORD *)(v11 + 128);
      v15 = *(_DWORD *)(v11 + 96);
      if ( v14 < v15 )
      {
        v16 = *(_QWORD *)(v11 + 104) + 16i64 * v14;
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
             || UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
        {
          ++v14;
          v16 += 16i64;
          if ( v14 >= v15 )
            goto LABEL_21;
        }
LABEL_22:
        v13 = *(UFG::AimingBaseComponent **)v16;
        goto LABEL_38;
      }
    }
LABEL_21:
    v13 = 0i64;
    goto LABEL_38;
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

// File Line: 384
// RVA: 0x56F9C0
void __usercall UFG::AimingNPCComponent::updateAimIntentionTargetPosition(UFG::AimingNPCComponent *this@<rcx>, UFG::qMatrix44 *matXform@<rdx>, float a3@<xmm0>, __int128 *a4@<xmm7>)
{
  UFG::AimingNPCComponent *v4; // rsi
  UFG::SimComponent *v5; // r14
  UFG::SimObjectProp *v6; // rbx
  __int64 v7; // rax
  UFG::SubTargetingLocation *v8; // r12
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rdi
  unsigned int v11; // er8
  unsigned int v12; // er9
  signed __int64 v13; // rdx
  unsigned __int16 v14; // dx
  UFG::CharacterAnimationComponent *v15; // rcx
  UFG::CharacterAnimationComponent *v16; // rax
  unsigned int v17; // er8
  unsigned int v18; // er9
  signed __int64 v19; // rdx
  Creature *pCreature; // r15
  UFG::SubTargetingProfile *v21; // rax
  float v22; // xmm1_4
  __m128 v23; // xmm3
  float v24; // xmm1_4
  float v25; // xmm0_4
  UFG::SimObject *v26; // rdx
  UFG::qVector3 *v27; // r8
  unsigned __int8 v28; // cl
  UFG::qVector3 vSubTargetingLocationWS; // [rsp+30h] [rbp-28h]

  v4 = this;
  UFG::AimingBaseComponent::GetTargetNormalAimPosition(
    (UFG::AimingBaseComponent *)&this->vfptr,
    &this->m_vAimIntentionTargetPosition,
    22i64,
    matXform);
  v5 = v4->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( LOBYTE(v5[8].m_BoundComponentHandles.mNode.mPrev) && v5 )
  {
    v6 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 30i64)
                                + *(_QWORD *)&v5[1].m_TypeUID
                                + 40);
    if ( !v6 )
      goto LABEL_52;
    v7 = ((__int64 (__fastcall *)(UFG::SimComponent *))v5->vfptr[18].__vecDelDtor)(v5);
    if ( v7 )
      v8 = *(UFG::SubTargetingLocation **)(v7 + 2736);
    else
      v8 = 0i64;
    if ( !v8 )
      goto LABEL_51;
    v9 = v6->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v6->m_Components.p[3].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v10 = v6->m_Components.p[4].m_pComponent;
      }
      else if ( (v9 >> 12) & 1 )
      {
        v11 = v6->mComponentTableEntryCount;
        v12 = v6->m_Components.size;
        if ( v11 >= v12 )
        {
LABEL_20:
          v10 = 0i64;
        }
        else
        {
          v13 = (signed __int64)&v6->m_Components.p[v11];
          while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF )
          {
            ++v11;
            v13 += 16i64;
            if ( v11 >= v12 )
              goto LABEL_20;
          }
          v10 = *(UFG::SimComponent **)v13;
        }
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v6->vfptr,
                UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v10 = v6->m_Components.p[3].m_pComponent;
    }
    if ( !v10 || !((__int64 (__fastcall *)(UFG::SimComponent *))v10->vfptr[14].__vecDelDtor)(v10) )
    {
LABEL_51:
      UFG::AimingBaseComponent::GetWeaponProjectileSpeed((UFG::AimingBaseComponent *)&v4->vfptr);
      v23 = (__m128)LODWORD(v4->m_vAimOriginPosition.x);
      v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] - v4->m_vAimIntentionTargetPosition.x)
                                      * (float)(v23.m128_f32[0] - v4->m_vAimIntentionTargetPosition.x))
                              + (float)((float)(v4->m_vAimOriginPosition.y - v4->m_vAimIntentionTargetPosition.y)
                                      * (float)(v4->m_vAimOriginPosition.y - v4->m_vAimIntentionTargetPosition.y)))
                      + (float)((float)(v4->m_vAimOriginPosition.z - v4->m_vAimIntentionTargetPosition.z)
                              * (float)(v4->m_vAimOriginPosition.z - v4->m_vAimIntentionTargetPosition.z));
      UFG::AimingBaseComponent::getPredictedPositionOffset(
        (UFG::AimingBaseComponent *)&v4->vfptr,
        &vSubTargetingLocationWS,
        (UFG::SimObject *)&v6->vfptr,
        a3,
        COERCE_CONST_FLOAT(_mm_sqrt_ps(v23)));
      v24 = vSubTargetingLocationWS.y + v4->m_vAimIntentionTargetPosition.y;
      v4->m_vAimIntentionTargetPosition.x = vSubTargetingLocationWS.x + v4->m_vAimIntentionTargetPosition.x;
      v25 = vSubTargetingLocationWS.z + v4->m_vAimIntentionTargetPosition.z;
      v4->m_vAimIntentionTargetPosition.y = v24;
      v4->m_vAimIntentionTargetPosition.z = v25;
LABEL_52:
      v26 = v4->m_pSimTargetAimPos.m_pPointer;
      v27 = &v4->m_vAimIntentionTargetPosition;
      if ( v26 )
      {
        UFG::AimingNPCComponent::updateSimTarget((UFG::AICoverComponent *)v4, v26, v27);
      }
      else
      {
        UFG::AimingNPCComponent::generateSimTarget(v4, &v4->m_pSimTargetAimPos, v27);
        v28 = *(_BYTE *)(*(_QWORD *)&v5[1].m_Flags + 11i64);
        if ( v28 )
          UFG::TargetingSimObject::SetTarget(
            (UFG::TargetingSimObject *)(*(_QWORD *)&v5[1].m_TypeUID + 56i64 * v28),
            v4->m_pSimTargetAimPos.m_pPointer);
      }
      return;
    }
    v14 = v6->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
      if ( v15
        && !((UFG::CharacterAnimationComponent::_TypeUID ^ v15->m_TypeUID) & 0xFE000000)
        && !(UFG::CharacterAnimationComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF) )
      {
LABEL_47:
        if ( v15 )
        {
          pCreature = v15->mCreature;
          if ( pCreature )
          {
            v21 = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *))v10->vfptr[14].__vecDelDtor)(v10);
            if ( UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                   v21,
                   &vSubTargetingLocationWS,
                   v8,
                   (UFG::SimObject *)&v6->vfptr,
                   a4,
                   pCreature) )
            {
              v22 = vSubTargetingLocationWS.y;
              v4->m_vAimIntentionTargetPosition.x = vSubTargetingLocationWS.x;
              a3 = vSubTargetingLocationWS.z;
              v4->m_vAimIntentionTargetPosition.y = v22;
              v4->m_vAimIntentionTargetPosition.z = a3;
            }
          }
        }
        goto LABEL_51;
      }
LABEL_29:
      v15 = 0i64;
      goto LABEL_47;
    }
    if ( (v14 & 0x8000u) != 0 )
    {
      v15 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
      if ( v15 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v15->m_TypeUID) & 0xFE000000) )
      {
        if ( UFG::CharacterAnimationComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF )
          v15 = 0i64;
        goto LABEL_47;
      }
      goto LABEL_29;
    }
    if ( (v14 >> 13) & 1 )
    {
      v16 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v6);
    }
    else
    {
      if ( (v14 >> 12) & 1 )
      {
        v17 = v6->mComponentTableEntryCount;
        v18 = v6->m_Components.size;
        if ( v17 < v18 )
        {
          v19 = (signed __int64)&v6->m_Components.p[v17];
          while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF )
          {
            ++v17;
            v19 += 16i64;
            if ( v17 >= v18 )
            {
              v15 = 0i64;
              goto LABEL_47;
            }
          }
          v15 = *(UFG::CharacterAnimationComponent **)v19;
          goto LABEL_47;
        }
        goto LABEL_29;
      }
      v16 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v6->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v15 = v16;
    goto LABEL_47;
  }
}                 UFG::CharacterAnimationComponent::_TypeUID);
    }
    v15 = v16;
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
void __fastcall UFG::AimingNPCComponent::generateSimTarget(UFG::AimingNPCComponent *this, UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *destPointer, UFG::qVector3 *vPosition)
{
  UFG::qVector3 *v3; // rsi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rbx
  __int64 v5; // r8
  UFG::qSymbol *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qMemoryPool *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::TransformNodeComponent *v14; // rax
  UFG::TransformNodeComponent *v15; // rdi
  UFG::SimObject *v16; // rdx
  unsigned __int16 v17; // cx
  unsigned int v18; // ebx
  UFG::qVector4 v19; // xmm2
  UFG::qMatrix44 m; // [rsp+30h] [rbp-178h]
  UFG::SimObjectModifier v21; // [rsp+70h] [rbp-138h]
  __int64 v22; // [rsp+90h] [rbp-118h]
  char pszSymbolString; // [rsp+A0h] [rbp-108h]
  UFG::qSymbol result; // [rsp+1B8h] [rbp+10h]

  v22 = -2i64;
  v3 = vPosition;
  v4 = destPointer;
  v5 = uUniqueID++;
  UFG::qSPrintf(&pszSymbolString, "AimingPosition_%d", v5);
  v6 = UFG::qSymbol::create_from_string(&result, &pszSymbolString);
  v7 = UFG::Simulation::CreateSimObject(&UFG::gSim, v6);
  if ( v4->m_pPointer )
  {
    v8 = v4->mPrev;
    v9 = v4->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = v7;
  if ( v7 )
  {
    v10 = &v7->m_SafePointerList.mNode;
    v11 = v7->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v11;
    v4->mNext = v10;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v12 = UFG::GetSimulationMemoryPool();
  v13 = UFG::qMemoryPool::Allocate(v12, 0x110ui64, "AimingPosition Sim Target TransformNodeComponent", 0i64, 1u);
  *(_QWORD *)&result.mUID = v13;
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
  v16 = v4->m_pPointer;
  v17 = v16->m_Flags;
  if ( (v17 >> 14) & 1 || (v17 & 0x8000u) != 0 || (v17 >> 13) & 1 )
  {
    v18 = 2;
  }
  else
  {
    v18 = -1;
    if ( (v17 >> 12) & 1 )
      v18 = 1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v21, v16, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, (UFG::SimComponent *)&v15->vfptr, v18);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  v19 = 0i64;
  v19.x = (float)1;
  m.v0 = v19;
  m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v19, (__m128)v19, 81);
  m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v19, (__m128)v19, 69);
  m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v19, (__m128)v19, 21);
  m.v3.x = v3->x;
  m.v3.y = v3->y;
  m.v3.z = v3->z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform(v15, &m);
}

// File Line: 484
// RVA: 0x52A9F0
float __fastcall UFG::AimingNPCComponent::GetAngularInaccuracyRad(UFG::AimingNPCComponent *this)
{
  __int64 v1; // rax
  float v2; // xmm1_4
  __int64 v3; // r8

  v1 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
  if ( !v1 )
    return 0.0;
  v2 = this->m_Accuracy.m_fAccuracyUnclamped;
  if ( v2 <= this->m_Accuracy.m_fAccuracyMinimum )
    v2 = this->m_Accuracy.m_fAccuracyMinimum;
  if ( v2 >= this->m_Accuracy.m_fAccuracyMaximum )
    v2 = this->m_Accuracy.m_fAccuracyMaximum;
  v3 = *(_QWORD *)(*(_QWORD *)(v1 + 176) + 8i64 * *(unsigned int *)(v1 + 172) + 8);
  return (float)((float)(1.0 - v2) * *(float *)(v3 + 48)) + (float)(v2 * *(float *)(v3 + 44));
}

// File Line: 503
// RVA: 0x52D070
void __fastcall UFG::AimingNPCComponent::GetFiringPositionAtAimPosition(UFG::AimingNPCComponent *this, UFG::qVector3 *vFiringPositionAtAimPosition)
{
  UFG::qVector3 *v2; // rsi
  UFG::AimingNPCComponent *v3; // rbx
  bool v4; // di
  __m128 v5; // xmm1
  float v6; // xmm0_4
  float v7; // xmm13_4
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
  float v18; // xmm0_4
  float v19; // xmm12_4
  __m128 v20; // xmm5
  float v21; // xmm14_4
  float v22; // xmm15_4
  __m128 v23; // xmm2
  float v24; // xmm1_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm8_4
  __m128 v28; // xmm2
  float v29; // xmm0_4
  __m128 v30; // xmm2
  float v31; // xmm9_4
  float v32; // xmm1_4
  float v33; // xmm10_4
  float v34; // xmm9_4
  __m128 v35; // xmm4
  float v36; // xmm0_4
  __m128 v37; // xmm4
  __m128 v38; // xmm11
  float v39; // xmm13_4
  float v40; // xmm4_4
  float v41; // xmm9_4
  __m128 v42; // xmm10
  float v43; // xmm8_4
  __m128 v44; // xmm2
  float v45; // xmm7_4
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+28h] [rbp-D0h]
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+38h] [rbp-C0h]
  float v48; // [rsp+100h] [rbp+8h]
  float v49; // [rsp+108h] [rbp+10h]

  v2 = vFiringPositionAtAimPosition;
  v3 = this;
  v4 = this->m_Accuracy.m_bEnsureMiss;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(
    (UFG::AimingBaseComponent *)&this->vfptr,
    &vWeaponProjectileSpawnPosition);
  v5 = (__m128)LODWORD(v3->m_vAimOriginPosition.x);
  v6 = (float)(v3->m_vAimOriginPosition.y - v3->m_vAimIntentionTargetPosition.y)
     * (float)(v3->m_vAimOriginPosition.y - v3->m_vAimIntentionTargetPosition.y);
  v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - v3->m_vAimIntentionTargetPosition.x)
                                 * (float)(v5.m128_f32[0] - v3->m_vAimIntentionTargetPosition.x))
                         + v6)
                 + (float)((float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z)
                         * (float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z));
  LODWORD(v7) = (unsigned __int128)_mm_sqrt_ps(v5);
  ((void (__fastcall *)(UFG::AimingNPCComponent *))v3->vfptr[21].__vecDelDtor)(v3);
  v8 = v6;
  v9 = _S60;
  if ( !(_S60 & 1) )
  {
    v9 = _S60 | 1;
    _S60 |= 1u;
    s_fDirection = FLOAT_1_5707964;
  }
  if ( v9 & 2 )
  {
    v10 = s_fHalfRange;
  }
  else
  {
    _S60 = v9 | 2;
    v10 = FLOAT_1_9198623;
    s_fHalfRange = FLOAT_1_9198623;
  }
  v11 = (float)(UFG::qRandom(v10 * 2.0, &UFG::qDefaultSeed) - s_fHalfRange) + s_fDirection;
  v12 = UFG::qRandom(s_fDistanceMax, &UFG::qDefaultSeed) + s_fDistanceMin;
  v13 = UFG::qRandom(6.2831855, &UFG::qDefaultSeed);
  if ( UFG::AimingNPCComponent::ms_bCorrectDiscPointPicking )
    v14 = fsqrt(UFG::qRandom(1.0, &UFG::qDefaultSeed));
  else
    v14 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  v15 = v14 * v8;
  if ( v4 )
  {
    v16 = v12;
    v17 = v11;
  }
  else
  {
    v18 = v3->m_fPlayerDodgeFactor;
    v16 = v15 + (float)((float)(v12 - v15) * v18);
    v17 = v13 + (float)((float)(v11 - v13) * v18);
  }
  v19 = cosf(v17) * v16;
  v48 = sinf(v17) * v16;
  UFG::AimingBaseComponent::GetWeaponProjectileDirection(
    (UFG::AimingBaseComponent *)&v3->vfptr,
    &vWeaponProjectileDirection);
  v20 = (__m128)LODWORD(vWeaponProjectileDirection.x);
  v21 = (float)(vWeaponProjectileDirection.x * v7) + vWeaponProjectileSpawnPosition.x;
  v22 = (float)(vWeaponProjectileDirection.y * v7) + vWeaponProjectileSpawnPosition.y;
  v49 = (float)(vWeaponProjectileDirection.z * v7) + vWeaponProjectileSpawnPosition.z;
  v23 = v20;
  v23.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0])
                          + (float)(vWeaponProjectileDirection.y * vWeaponProjectileDirection.y))
                  + (float)(vWeaponProjectileDirection.z * vWeaponProjectileDirection.z);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v25 = vWeaponProjectileDirection.x * v24;
  v26 = vWeaponProjectileDirection.y * v24;
  v27 = vWeaponProjectileDirection.z * v24;
  v28 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v28.m128_f32[0] == 0.0 )
  {
    v30 = 0i64;
  }
  else
  {
    LODWORD(v29) = (unsigned __int128)_mm_sqrt_ps(v28);
    v30 = (__m128)(unsigned int)FLOAT_1_0;
    v30.m128_f32[0] = 1.0 / v29;
  }
  v31 = v30.m128_f32[0] * UFG::qVector3::msDirUp.x;
  v32 = v30.m128_f32[0] * UFG::qVector3::msDirUp.y;
  v30.m128_f32[0] = v30.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v33 = (float)(v32 * v27) - (float)(v30.m128_f32[0] * v26);
  v30.m128_f32[0] = (float)(v30.m128_f32[0] * v25) - (float)(v31 * v27);
  v34 = (float)(v31 * v26) - (float)(v32 * v25);
  v35 = v30;
  v35.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v33 * v33)) + (float)(v34 * v34);
  if ( v35.m128_f32[0] == 0.0 )
  {
    v37 = 0i64;
  }
  else
  {
    LODWORD(v36) = (unsigned __int128)_mm_sqrt_ps(v35);
    v37 = (__m128)(unsigned int)FLOAT_1_0;
    v37.m128_f32[0] = 1.0 / v36;
  }
  v38 = v37;
  v38.m128_f32[0] = v37.m128_f32[0] * v33;
  v39 = v37.m128_f32[0] * v30.m128_f32[0];
  v40 = v37.m128_f32[0] * v34;
  v41 = (float)(v40 * v26) - (float)(v39 * v27);
  v42 = v38;
  v42.m128_f32[0] = (float)(v38.m128_f32[0] * v27) - (float)(v40 * v25);
  v43 = (float)(v39 * v25) - (float)(v38.m128_f32[0] * v26);
  v44 = v42;
  v44.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v41 * v41)) + (float)(v43 * v43);
  if ( v44.m128_f32[0] == 0.0 )
    v45 = 0.0;
  else
    v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
  v2->x = (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _xmm[0]) * v38.m128_f32[0]) + (float)((float)(v41 * v45) * v48))
        + v21;
  v2->y = (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _xmm[0]) * v39) + (float)((float)(v42.m128_f32[0] * v45) * v48))
        + v22;
  v2->z = (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _xmm[0]) * v40) + (float)((float)(v43 * v45) * v48)) + v49;
}

