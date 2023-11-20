// File Line: 43
// RVA: 0x350F40
void UFG::LocalPlayerIsInCombatManager::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax

  if ( !UFG::LocalPlayerIsInCombatManager::s_pInstance )
  {
    v0 = UFG::qMalloc(0x90ui64, "LocalPlayerIsInCombatManager", 0i64);
    if ( v0 )
      UFG::LocalPlayerIsInCombatManager::LocalPlayerIsInCombatManager((UFG::LocalPlayerIsInCombatManager *)v0);
    UFG::LocalPlayerIsInCombatManager::s_pInstance = (UFG::LocalPlayerIsInCombatManager *)v0;
  }
}

// File Line: 51
// RVA: 0x351E10
void UFG::LocalPlayerIsInCombatManager::DeleteInstance(void)
{
  UFG::LocalPlayerIsInCombatManager *v0; // rbx

  v0 = UFG::LocalPlayerIsInCombatManager::s_pInstance;
  if ( UFG::LocalPlayerIsInCombatManager::s_pInstance )
  {
    UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&UFG::LocalPlayerIsInCombatManager::s_pInstance->m_pLocalPlayerSimObjectCharacterPropertiesComponent);
    UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v0->m_pLocalPlayerTransformNodeComponent);
    operator delete[](v0);
  }
  UFG::LocalPlayerIsInCombatManager::s_pInstance = 0i64;
}

// File Line: 58
// RVA: 0x330420
void __fastcall UFG::LocalPlayerIsInCombatManager::LocalPlayerIsInCombatManager(UFG::LocalPlayerIsInCombatManager *this)
{
  UFG::LocalPlayerIsInCombatManager *v1; // rbx
  char v2; // cl

  v1 = this;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pLocalPlayerTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v1->m_pLocalPlayerSimObjectCharacterPropertiesComponent);
  v1->m_TypesInCombatAny.mBits[0] = 0i64;
  v1->m_TypesInCombatMelee.mBits[0] = 0i64;
  *(_QWORD *)&v1->m_NumAttackersAny = 0i64;
  v1->m_LastAnyCombatTimestamp = 0i64;
  v1->m_LastMeleeCombatTimestamp = 0i64;
  *((_BYTE *)v1 + 120) &= 0xFEu;
  v1->m_TypesInCombatAny.mBits[0] = 0i64;
  v1->m_TypesInCombatMelee.mBits[0] = 0i64;
  v2 = tweak_initted;
  if ( !tweak_initted )
    v2 = 1;
  tweak_initted = v2;
}

// File Line: 86
// RVA: 0x390570
void __fastcall UFG::LocalPlayerIsInCombatManager::Update(UFG::LocalPlayerIsInCombatManager *this)
{
  UFG::LocalPlayerIsInCombatManager *v1; // rbx
  float v2; // xmm1_4
  unsigned int v3; // eax
  bool v4; // zf
  float v5; // xmm1_4
  unsigned int v6; // eax
  UFG::SimObjectCharacter *v7; // rbx
  UFG::StimulusManager *v8; // rdi
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h]

  v1 = this;
  UFG::LocalPlayerIsInCombatManager::FixupPointersToPlayer(this);
  v2 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( v1->m_NumAttackersMelee )
    v2 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  v3 = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(
         v1,
         v2,
         UFG::LocalPlayerIsInCombatManager::s_RangedDistance,
         0);
  v4 = v1->m_NumAttackersMelee == 0;
  v1->m_NumAttackersAny = v3;
  v5 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( !v4 )
    v5 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  v6 = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(v1, v5, 0.0, 1);
  v4 = v1->m_NumAttackersAny == 0;
  v1->m_NumAttackersMelee = v6;
  if ( v4 )
  {
    UFG::PedSpawnManager::msProxyExclusionZoneActive = 0;
  }
  else
  {
    v1->m_LastAnyCombatTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    UFG::PedSpawnManager::msProxyExclusionZoneActive = 1;
  }
  if ( v1->m_NumAttackersMelee )
  {
    v1->m_LastMeleeCombatTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v7 = LocalPlayer;
    v8 = UFG::StimulusManager::s_pInstance;
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusEmissionType = 0;
    UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
      UFG::StimulusManager::s_pInstance,
      eSTIMULUS_MELEE_FIGHT_VS_COMBATANT,
      (UFG::SimObject *)&LocalPlayer->vfptr,
      0);
    UFG::StimulusManager::AttachStimulusEmitterComponent(
      v8,
      &stru_1423BFC28,
      &stimulus_parameters,
      (UFG::SimObject *)&v7->vfptr,
      0);
  }
}

// File Line: 120
// RVA: 0x358340
void __fastcall UFG::LocalPlayerIsInCombatManager::FixupPointersToPlayer(UFG::LocalPlayerIsInCombatManager *this)
{
  UFG::SimObjectCharacterPropertiesComponent *v1; // rdi
  UFG::LocalPlayerIsInCombatManager *v2; // rbx
  UFG::TransformNodeComponent *v3; // rdx

  v1 = 0i64;
  v2 = this;
  if ( !this->m_pLocalPlayerTransformNodeComponent.m_pSimComponent )
  {
    if ( LocalPlayer )
      v3 = (UFG::TransformNodeComponent *)LocalPlayer->m_Components.p[2].m_pComponent;
    else
      v3 = 0i64;
    UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Set(&this->m_pLocalPlayerTransformNodeComponent, v3);
  }
  if ( !v2->m_pLocalPlayerSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    if ( LocalPlayer )
      v1 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&LocalPlayer->vfptr);
    UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::Set(
      &v2->m_pLocalPlayerSimObjectCharacterPropertiesComponent,
      v1);
  }
}

// File Line: 135
// RVA: 0x36ABA0
bool __fastcall UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager *this, UFG::eCharacterTypeEnum e)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rax
  bool result; // al

  v2 = this->m_LastAnyCombatTimestamp;
  result = 0;
  if ( v2 )
  {
    if ( UFG::Metrics::msInstance.mSimTimeMSec - v2 < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer )
    {
      if ( e == eCHARACTER_TYPE_INVALID
        || (v3 = this->m_TypesInCombatAny.mBits[(signed __int64)(signed int)e >> 6],
            _bittest64((const signed __int64 *)&v3, e & 0x3F)) )
      {
        result = 1;
      }
    }
  }
  return result;
}

// File Line: 143
// RVA: 0x36AE10
bool __fastcall UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager *this, UFG::eCharacterTypeEnum e)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rax
  bool result; // al

  v2 = this->m_LastMeleeCombatTimestamp;
  result = 0;
  if ( v2 )
  {
    if ( UFG::Metrics::msInstance.mSimTimeMSec - v2 < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer )
    {
      if ( e == eCHARACTER_TYPE_INVALID
        || (v3 = this->m_TypesInCombatMelee.mBits[(signed __int64)(signed int)e >> 6],
            _bittest64((const signed __int64 *)&v3, e & 0x3F)) )
      {
        result = 1;
      }
    }
  }
  return result;
}

// File Line: 151
// RVA: 0x361810
__int64 __fastcall UFG::LocalPlayerIsInCombatManager::GetNumAttackersAny(UFG::LocalPlayerIsInCombatManager *this, bool cached)
{
  UFG::LocalPlayerIsInCombatManager *v2; // rbx
  float v3; // xmm1_4
  __int64 result; // rax

  v2 = this;
  if ( cached )
    return this->m_NumAttackersAny;
  v3 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( this->m_NumAttackersMelee )
    v3 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  result = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(
             this,
             v3,
             UFG::LocalPlayerIsInCombatManager::s_RangedDistance,
             0);
  v2->m_NumAttackersAny = result;
  return result;
}

// File Line: 169
// RVA: 0x361860
__int64 __fastcall UFG::LocalPlayerIsInCombatManager::GetNumAttackersMelee(UFG::LocalPlayerIsInCombatManager *this, bool cached)
{
  UFG::LocalPlayerIsInCombatManager *v2; // rbx
  float v3; // xmm1_4
  __int64 result; // rax

  v2 = this;
  if ( cached )
    return this->m_NumAttackersMelee;
  v3 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( this->m_NumAttackersMelee )
    v3 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  result = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(this, v3, 0.0, 1);
  v2->m_NumAttackersMelee = result;
  return result;
}

// File Line: 185
// RVA: 0x34FEE0
__int64 __fastcall UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(UFG::LocalPlayerIsInCombatManager *this, float melee_distance, float ranged_distance, bool melee_only)
{
  bool v4; // di
  float v5; // xmm7_4
  UFG::LocalPlayerIsInCombatManager *v6; // r13
  Render::DebugDrawContext *v7; // rbx
  unsigned int v8; // esi
  float v9; // xmm8_4
  UFG::SimObjectCharacter *v10; // r15
  __int64 v11; // rdi
  UFG::SimComponent *v12; // rbx
  UFG::NearbyCharacterManager *v13; // r8
  __int64 **v14; // rdx
  __int64 *v15; // rax
  __int64 *v16; // rbp
  _QWORD *v17; // rdx
  __int64 v18; // rcx
  __int64 *v19; // rax
  UFG::NearbyCharacterManager *v20; // rcx
  __int64 *v21; // rdx
  __int64 **v22; // rax
  signed __int64 v23; // rcx
  __int64 v24; // rcx
  __int64 *v25; // rbp
  __int64 v26; // rsi
  UFG::TransformNodeComponent *v27; // rbx
  __int64 v28; // rax
  bool v29; // r15
  UFG::SimObjectGame *v30; // rcx
  unsigned __int16 v31; // dx
  UFG::SimComponent *v32; // rax
  bool v33; // r12
  __int64 v34; // rdi
  unsigned int v35; // eax
  unsigned int v36; // eax
  __int64 v37; // rdi
  bool v38; // al
  UFG::qColour *v39; // r9
  float v40; // xmm6_4
  UFG::qVector3 *v41; // rsi
  UFG::qVector3 *v42; // r10
  float v43; // xmm0_4
  __m128 v44; // xmm1
  bool v45; // r15
  UFG::SimObjectCVBase *v46; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v47; // rax
  unsigned __int16 v48; // dx
  UFG::qColour *v49; // r9
  UFG::qVector3 *v50; // rdx
  signed __int64 v51; // rdx
  signed __int64 v52; // rax
  __int64 v53; // rbx
  bool v54; // cl
  __int64 v55; // rax
  UFG::qVector3 *v56; // r8
  UFG::qVector3 *v57; // rdx
  __int64 i; // rax
  _QWORD *v59; // rdx
  __int64 v60; // rcx
  _QWORD *v61; // rax
  __int64 *v62; // rcx
  __int64 **v63; // rax
  unsigned __int64 v64; // rcx
  bool v65; // dl
  const char *v66; // rcx
  char *v67; // rax
  int v68; // er8
  unsigned __int16 v69; // dx
  UFG::FormationManagerComponent *v70; // rax
  __int64 v72; // [rsp+0h] [rbp-128h]
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+28h] [rbp-100h]
  bool is_screen_coords[8]; // [rsp+30h] [rbp-F8h]
  unsigned int v75; // [rsp+38h] [rbp-F0h]
  double v76; // [rsp+40h] [rbp-E8h]
  double v77; // [rsp+48h] [rbp-E0h]
  UFG::qVector3 *p0; // [rsp+50h] [rbp-D8h]
  Render::DebugDrawContext *v79; // [rsp+58h] [rbp-D0h]
  __int64 v80; // [rsp+60h] [rbp-C8h]
  __int64 **v81; // [rsp+68h] [rbp-C0h]
  __int64 v82; // [rsp+70h] [rbp-B8h]
  __int64 *v83; // [rsp+78h] [rbp-B0h]
  __int64 v84; // [rsp+80h] [rbp-A8h]
  __int64 *v85; // [rsp+88h] [rbp-A0h]
  __int64 **v86; // [rsp+90h] [rbp-98h]
  UFG::SimObjectCharacter *v87; // [rsp+130h] [rbp+8h]
  char v88; // [rsp+138h] [rbp+10h]
  unsigned int v89; // [rsp+140h] [rbp+18h]
  bool v90; // [rsp+148h] [rbp+20h]

  v90 = melee_only;
  v84 = -2i64;
  v4 = melee_only;
  v5 = melee_distance;
  v6 = this;
  v7 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v79 = v7;
  if ( v4 )
    v6->m_TypesInCombatMelee.mBits[0] = 0i64;
  else
    v6->m_TypesInCombatAny.mBits[0] = 0i64;
  v8 = 0;
  v89 = 0;
  if ( melee_distance <= ranged_distance )
    v9 = ranged_distance;
  else
    v9 = melee_distance;
  v10 = LocalPlayer;
  v87 = LocalPlayer;
  if ( v6->m_pLocalPlayerTransformNodeComponent.m_pSimComponent
    && v6->m_pLocalPlayerSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v11 = SLODWORD(v6->m_pLocalPlayerSimObjectCharacterPropertiesComponent.m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v12 = v6->m_pLocalPlayerTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6->m_pLocalPlayerTransformNodeComponent.m_pSimComponent);
    p0 = (UFG::qVector3 *)&v12[2].m_BoundComponentHandles;
    v85 = (__int64 *)&v85;
    v86 = &v85;
    v13 = UFG::NearbyCharacterManager::s_pInstance;
    v14 = &v85;
    v15 = (__int64 *)&v83;
    v16 = &v72 + 15;
    v83 = v16;
    if ( &v83 != (__int64 **)v16 )
    {
      do
      {
        v17 = v15 + 2;
        v18 = v15[2];
        v19 = (__int64 *)v15[3];
        *(_QWORD *)(v18 + 8) = v19;
        *v19 = v18;
        *v17 = v17;
        v17[1] = v17;
        v14 = v86;
        v15 = (__int64 *)(v86 - 2);
      }
      while ( v86 - 2 != (__int64 **)v16 );
    }
    v20 = (UFG::NearbyCharacterManager *)v13->m_Characters[0].mNode.mNext;
    if ( v20 != v13 )
    {
      v21 = v85;
      do
      {
        v22 = (__int64 **)&v20->m_Characters[1];
        v21[1] = (__int64)&v20->m_Characters[1];
        *v22 = v21;
        v22[1] = (__int64 *)&v85;
        v21 = (__int64 *)&v20->m_Characters[1];
        v85 = (__int64 *)&v20->m_Characters[1];
        v20 = (UFG::NearbyCharacterManager *)v20->m_Characters[0].mNode.mNext;
      }
      while ( v20 != v13 );
      v14 = v86;
    }
    v23 = (signed __int64)(v14 - 2);
    v81 = v14 - 2;
    v82 = v11;
    if ( v14 - 2 != (__int64 **)v16 )
    {
      do
      {
        v24 = *(_QWORD *)(v23 + 48);
        if ( !v24 )
          goto LABEL_97;
        if ( !(*(unsigned __int8 (**)(void))(*(_QWORD *)v24 + 112i64))() )
          goto LABEL_97;
        v25 = v81[6];
        if ( (UFG::SimObjectCharacter *)v25[5] == v10 )
          goto LABEL_97;
        v26 = v25[53];
        v27 = (UFG::TransformNodeComponent *)v25[11];
        v80 = v25[35];
        v28 = *((signed int *)v25 + 1041);
        v29 = UFG::g_AIObjectiveParams[v28].m_IsHostile;
        v88 = UFG::g_AIObjectiveParams[v28].m_IsHostile;
        v30 = (UFG::SimObjectGame *)v25[5];
        v33 = 0;
        if ( v30 )
        {
          v31 = v30->m_Flags;
          if ( (v31 >> 14) & 1 )
          {
            v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v30, UFG::HudComponent::_TypeUID);
          }
          else if ( (v31 & 0x8000u) == 0 )
          {
            if ( (v31 >> 13) & 1 )
              v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v30, UFG::HudComponent::_TypeUID);
            else
              v32 = (v31 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v30, UFG::HudComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v30->vfptr, UFG::HudComponent::_TypeUID);
          }
          else
          {
            v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v30, UFG::HudComponent::_TypeUID);
          }
          if ( v32 && HIBYTE(v32[3].m_Flags) )
            v33 = 1;
        }
        if ( !v29 )
        {
          v34 = v25[192];
          if ( v34 )
          {
            v35 = _S31;
            if ( !(_S31 & 1) )
            {
              _S31 |= 1u;
              hostileNodeId.mUID = UFG::qStringHashUpper32("Hostile", 0xFFFFFFFF);
              v35 = _S31;
            }
            if ( v35 & 2 )
            {
              v36 = mostUsed_Hostile;
            }
            else
            {
              _S31 = v35 | 2;
              v36 = GetMostUsedIndex(hostileNodeId.mUID);
              mostUsed_Hostile = v36;
            }
            v88 = ActionController::IsPlaying((ActionController *)(v34 + 216), &hostileNodeId, v36, 1);
          }
        }
        v37 = v25[59];
        if ( !v37 || !v27 || !v26 || !v80 )
        {
          if ( !UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight || !v27 )
            goto LABEL_96;
          UFG::TransformNodeComponent::UpdateWorldTransform(v27);
          v39 = &UFG::qColour::Purple;
LABEL_93:
          v56 = (UFG::qVector3 *)&v27->mWorldTransform.v3;
          goto LABEL_94;
        }
        if ( *(_BYTE *)(v26 + 116) )
        {
          if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v27);
            v39 = &UFG::qColour::Pink;
            goto LABEL_93;
          }
          goto LABEL_96;
        }
        v38 = UFG::HasRangedWeaponEquippedWithAmmo((UFG::TargetingSystemBaseComponent *)v25[59]);
        if ( v90 )
        {
          if ( v38 )
          {
            if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v27);
              v39 = &UFG::qColour::Black;
              goto LABEL_93;
            }
            goto LABEL_96;
          }
        }
        else if ( v38 )
        {
          v40 = v9;
          goto LABEL_53;
        }
        v40 = v5;
LABEL_53:
        UFG::TransformNodeComponent::UpdateWorldTransform(v27);
        v41 = (UFG::qVector3 *)&v27->mWorldTransform.v3;
        v42 = p0;
        v43 = p0->y - v27->mWorldTransform.v3.y;
        v44 = (__m128)LODWORD(p0->x);
        v44.m128_f32[0] = (float)((float)((float)(v44.m128_f32[0] - v27->mWorldTransform.v3.x)
                                        * (float)(v44.m128_f32[0] - v27->mWorldTransform.v3.x))
                                + (float)(v43 * v43))
                        + (float)((float)(p0->z - v27->mWorldTransform.v3.z) * (float)(p0->z - v27->mWorldTransform.v3.z));
        v45 = v40 > COERCE_FLOAT(_mm_sqrt_ps(v44));
        v46 = *(UFG::SimObjectCVBase **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v37 + 96) + 30i64)
                                       + *(_QWORD *)(v37 + 88)
                                       + 40);
        if ( v46 )
        {
          v48 = v46->m_Flags;
          if ( (v48 >> 14) & 1 )
          {
            v47 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v46);
          }
          else if ( (v48 & 0x8000u) == 0 )
          {
            if ( (v48 >> 13) & 1 )
            {
              v47 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v46->vfptr,
                                                                    UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
            }
            else if ( (v48 >> 12) & 1 )
            {
              v47 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v46->vfptr,
                                                                    UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
            }
            else
            {
              v47 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                    (UFG::SimObject *)&v46->vfptr,
                                                                    UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
            }
          }
          else
          {
            v47 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v46);
          }
          v42 = p0;
        }
        else
        {
          v47 = 0i64;
        }
        if ( v33 )
        {
          if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
          {
            v49 = &UFG::qColour::Purple;
            v50 = v42;
            goto LABEL_68;
          }
          goto LABEL_69;
        }
        if ( v47 )
        {
          v53 = v47->m_eFactionClass;
          v54 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[0][v53 + 39 * v82] == 0;
          v55 = v25[65];
          if ( v55 )
            LOBYTE(v55) = *(_DWORD *)(v55 + 80) == 13;
          if ( v88 && v54 && !(_BYTE)v55 )
          {
            if ( v45 )
            {
              if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
              {
                v49 = &UFG::qColour::Blue;
                v50 = p0;
LABEL_68:
                Render::DebugDrawContext::DrawLine(v79, v50, v41, v49, &UFG::qMatrix44::msIdentity, 0i64, 0);
              }
LABEL_69:
              v8 = v89++ + 1;
              v10 = v87;
              v51 = (signed __int64)*(signed int *)(v80 + 192) >> 6;
              v52 = 1i64 << (*(_BYTE *)(v80 + 192) & 0x3F);
              if ( v90 )
                v6->m_TypesInCombatMelee.mBits[v51] |= v52;
              else
                v6->m_TypesInCombatAny.mBits[v51] |= v52;
              goto LABEL_97;
            }
            if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
            {
              v39 = &UFG::qColour::Red;
              goto LABEL_83;
            }
          }
          else if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
          {
            v39 = &UFG::qColour::White;
LABEL_83:
            v56 = v41;
LABEL_94:
            v57 = p0;
            goto LABEL_95;
          }
        }
        else if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
        {
          v39 = &UFG::qColour::Yellow;
          v56 = (UFG::qVector3 *)&v27->mWorldTransform.v3;
          v57 = v42;
LABEL_95:
          Render::DebugDrawContext::DrawLine(v79, v57, v56, v39, &UFG::qMatrix44::msIdentity, 0i64, 0);
          goto LABEL_96;
        }
LABEL_96:
        v8 = v89;
        v10 = v87;
LABEL_97:
        v23 = (signed __int64)(v81[3] - 2);
        v81 = (__int64 **)v23;
        v16 = v83;
      }
      while ( (__int64 *)v23 != v83 );
    }
    for ( i = (__int64)(v86 - 2); v86 - 2 != (__int64 **)v16; i = (__int64)(v86 - 2) )
    {
      v59 = (_QWORD *)(i + 16);
      v60 = *(_QWORD *)(i + 16);
      v61 = *(_QWORD **)(i + 24);
      *(_QWORD *)(v60 + 8) = v61;
      *v61 = v60;
      *v59 = v59;
      v59[1] = v59;
    }
    v62 = v85;
    v63 = v86;
    v85[1] = (__int64)v86;
    *v63 = v62;
    v85 = (__int64 *)&v85;
    v86 = &v85;
    v7 = v79;
    v4 = v90;
  }
  if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
  {
    if ( v4 )
      v64 = v6->m_LastMeleeCombatTimestamp;
    else
      v64 = v6->m_LastAnyCombatTimestamp;
    v65 = v64 && UFG::Metrics::msInstance.mSimTimeMSec - v64 < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer;
    v66 = "Any";
    if ( v4 )
      v66 = "Melee";
    v67 = "False";
    if ( v65 )
      v67 = "True";
    v68 = 20;
    if ( v4 )
      v68 = 10;
    v77 = ranged_distance;
    v76 = v5;
    v75 = v8;
    *(_QWORD *)is_screen_coords = v66;
    pre_draw_callback = (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))v67;
    Render::DebugDrawContext::DrawTextA(
      v7,
      100,
      v68,
      &UFG::qColour::White,
      "IsInFight(%s) - NumAttackers%s(%d) and melee dist %.1f ranged dist %1.f",
      v67);
    if ( v4 && v10 )
    {
      v69 = v10->m_Flags;
      if ( (v69 >> 14) & 1 )
      {
        v70 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v10->vfptr,
                                                  UFG::FormationManagerComponent::_TypeUID);
      }
      else if ( (v69 & 0x8000u) == 0 )
      {
        if ( (v69 >> 13) & 1 )
        {
          v70 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v10->vfptr,
                                                    UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v69 >> 12) & 1 )
        {
          v70 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v10->vfptr,
                                                    UFG::FormationManagerComponent::_TypeUID);
        }
        else
        {
          v70 = (UFG::FormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v10->vfptr,
                                                    UFG::FormationManagerComponent::_TypeUID);
        }
      }
      else
      {
        v70 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v10->vfptr,
                                                  UFG::FormationManagerComponent::_TypeUID);
      }
      if ( v70 )
      {
        LODWORD(pre_draw_callback) = UFG::FormationManagerComponent::NumAttackersCloserThan(v70, v5, 5);
        Render::DebugDrawContext::DrawTextA(v7, 100, 30, &UFG::qColour::White, "NumAIAttackers(%d)", pre_draw_callback);
      }
    }
  }
  return v8;
}

