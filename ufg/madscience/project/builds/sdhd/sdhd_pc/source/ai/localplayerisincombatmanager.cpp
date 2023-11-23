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
void __fastcall UFG::LocalPlayerIsInCombatManager::LocalPlayerIsInCombatManager(
        UFG::LocalPlayerIsInCombatManager *this)
{
  char v2; // cl

  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pLocalPlayerTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pLocalPlayerSimObjectCharacterPropertiesComponent);
  this->m_TypesInCombatAny.mBits[0] = 0i64;
  this->m_TypesInCombatMelee.mBits[0] = 0i64;
  *(_QWORD *)&this->m_NumAttackersAny = 0i64;
  this->m_LastAnyCombatTimestamp = 0i64;
  this->m_LastMeleeCombatTimestamp = 0i64;
  *((_BYTE *)this + 120) &= ~1u;
  this->m_TypesInCombatAny.mBits[0] = 0i64;
  this->m_TypesInCombatMelee.mBits[0] = 0i64;
  v2 = tweak_initted;
  if ( !tweak_initted )
    v2 = 1;
  tweak_initted = v2;
}

// File Line: 86
// RVA: 0x390570
void __fastcall UFG::LocalPlayerIsInCombatManager::Update(UFG::LocalPlayerIsInCombatManager *this)
{
  float v2; // xmm1_4
  unsigned int v3; // eax
  bool v4; // zf
  float v5; // xmm1_4
  unsigned int v6; // eax
  UFG::SimObjectCharacter *v7; // rbx
  UFG::StimulusManager *v8; // rdi
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h] BYREF

  UFG::LocalPlayerIsInCombatManager::FixupPointersToPlayer(this);
  v2 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( this->m_NumAttackersMelee )
    v2 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  v3 = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(
         this,
         v2,
         UFG::LocalPlayerIsInCombatManager::s_RangedDistance,
         0);
  v4 = this->m_NumAttackersMelee == 0;
  this->m_NumAttackersAny = v3;
  v5 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( !v4 )
    v5 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  v6 = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(this, v5, 0.0, 1);
  v4 = this->m_NumAttackersAny == 0;
  this->m_NumAttackersMelee = v6;
  if ( v4 )
  {
    UFG::PedSpawnManager::msProxyExclusionZoneActive = 0;
  }
  else
  {
    this->m_LastAnyCombatTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    UFG::PedSpawnManager::msProxyExclusionZoneActive = 1;
  }
  if ( this->m_NumAttackersMelee )
  {
    this->m_LastMeleeCombatTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v7 = LocalPlayer;
    v8 = UFG::StimulusManager::s_pInstance;
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
    UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
      UFG::StimulusManager::s_pInstance,
      eSTIMULUS_MELEE_FIGHT_VS_COMBATANT,
      LocalPlayer,
      eTARGET_TYPE_INVALID);
    UFG::StimulusManager::AttachStimulusEmitterComponent(v8, &stru_1423BFC28, &stimulus_parameters, v7, 0);
  }
}

// File Line: 120
// RVA: 0x358340
void __fastcall UFG::LocalPlayerIsInCombatManager::FixupPointersToPlayer(UFG::LocalPlayerIsInCombatManager *this)
{
  UFG::SimObjectCharacterPropertiesComponent *v1; // rdi
  UFG::TransformNodeComponent *m_pComponent; // rdx

  v1 = 0i64;
  if ( !this->m_pLocalPlayerTransformNodeComponent.m_pSimComponent )
  {
    if ( LocalPlayer )
      m_pComponent = (UFG::TransformNodeComponent *)LocalPlayer->m_Components.p[2].m_pComponent;
    else
      m_pComponent = 0i64;
    UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Set(
      &this->m_pLocalPlayerTransformNodeComponent,
      m_pComponent);
  }
  if ( !this->m_pLocalPlayerSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    if ( LocalPlayer )
      v1 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(LocalPlayer);
    UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::Set(
      &this->m_pLocalPlayerSimObjectCharacterPropertiesComponent,
      v1);
  }
}

// File Line: 135
// RVA: 0x36ABA0
bool __fastcall UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager *this, int e)
{
  unsigned __int64 m_LastAnyCombatTimestamp; // r8
  unsigned __int64 v3; // rax
  bool result; // al

  m_LastAnyCombatTimestamp = this->m_LastAnyCombatTimestamp;
  result = 0;
  if ( m_LastAnyCombatTimestamp )
  {
    if ( UFG::Metrics::msInstance.mSimTimeMSec - m_LastAnyCombatTimestamp < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer )
    {
      if ( !e )
        return 1;
      v3 = this->m_TypesInCombatAny.mBits[(__int64)e >> 6];
      if ( _bittest64((const __int64 *)&v3, e & 0x3F) )
        return 1;
    }
  }
  return result;
}

// File Line: 143
// RVA: 0x36AE10
bool __fastcall UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager *this, int e)
{
  unsigned __int64 m_LastMeleeCombatTimestamp; // r8
  unsigned __int64 v3; // rax
  bool result; // al

  m_LastMeleeCombatTimestamp = this->m_LastMeleeCombatTimestamp;
  result = 0;
  if ( m_LastMeleeCombatTimestamp )
  {
    if ( UFG::Metrics::msInstance.mSimTimeMSec - m_LastMeleeCombatTimestamp < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer )
    {
      if ( !e )
        return 1;
      v3 = this->m_TypesInCombatMelee.mBits[(__int64)e >> 6];
      if ( _bittest64((const __int64 *)&v3, e & 0x3F) )
        return 1;
    }
  }
  return result;
}

// File Line: 151
// RVA: 0x361810
__int64 __fastcall UFG::LocalPlayerIsInCombatManager::GetNumAttackersAny(
        UFG::LocalPlayerIsInCombatManager *this,
        bool cached)
{
  float v3; // xmm1_4
  __int64 result; // rax

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
  this->m_NumAttackersAny = result;
  return result;
}

// File Line: 169
// RVA: 0x361860
__int64 __fastcall UFG::LocalPlayerIsInCombatManager::GetNumAttackersMelee(
        UFG::LocalPlayerIsInCombatManager *this,
        bool cached)
{
  float v3; // xmm1_4
  __int64 result; // rax

  if ( cached )
    return this->m_NumAttackersMelee;
  v3 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance;
  if ( this->m_NumAttackersMelee )
    v3 = UFG::LocalPlayerIsInCombatManager::s_MeleeDistance
       + UFG::LocalPlayerIsInCombatManager::s_MeleeDistanceHysteresis;
  result = UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(this, v3, 0.0, 1);
  this->m_NumAttackersMelee = result;
  return result;
}

// File Line: 185
// RVA: 0x34FEE0
__int64 __fastcall UFG::LocalPlayerIsInCombatManager::CountAttackerCloserThan(
        UFG::LocalPlayerIsInCombatManager *this,
        float melee_distance,
        float ranged_distance,
        bool melee_only)
{
  bool v4; // di
  Render::DebugDrawContext *Context; // rbx
  unsigned int v8; // esi
  float v9; // xmm8_4
  UFG::SimObjectCharacter *v10; // r15
  __int64 mPrev_low; // rdi
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::NearbyCharacterManager *v13; // r8
  __int64 **v14; // rdx
  __int64 *v15; // rax
  __int64 *v16; // rbp
  _QWORD *v17; // rdx
  __int64 v18; // rcx
  __int64 *v19; // rax
  UFG::NearbyCharacterManager *mNext; // rcx
  __int64 *v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rcx
  __int64 *v24; // rbp
  __int64 v25; // rsi
  UFG::TransformNodeComponent *v26; // rbx
  bool m_IsHostile; // r15
  UFG::SimObjectGame *v28; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v31; // r12
  __int64 v32; // rdi
  unsigned int v33; // eax
  unsigned int MostUsedIndex; // eax
  __int64 v35; // rdi
  bool HasRangedWeaponEquippedWithAmmo; // al
  UFG::qColour *v37; // r9
  float v38; // xmm6_4
  UFG::qVector3 *v39; // rsi
  UFG::qVector3 *v40; // r10
  float v41; // xmm0_4
  __m128 x_low; // xmm1
  bool v43; // r15
  UFG::SimObjectCVBase *v44; // rcx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  __int16 v46; // dx
  UFG::qColour *v47; // r9
  UFG::qVector3 *v48; // rdx
  __int64 v49; // rdx
  __int64 v50; // rax
  __int64 m_eFactionClass; // rbx
  bool v52; // cl
  __int64 v53; // rax
  UFG::qVector3 *v54; // r8
  UFG::qVector3 *v55; // rdx
  __int64 **i; // rax
  _QWORD *v57; // rdx
  __int64 *v58; // rcx
  __int64 *v59; // rax
  __int64 *v60; // rcx
  __int64 **v61; // rax
  unsigned __int64 m_LastMeleeCombatTimestamp; // rcx
  bool v63; // dl
  const char *v64; // rcx
  const char *v65; // rax
  int v66; // r8d
  __int16 v67; // dx
  UFG::FormationManagerComponent *v68; // rax
  __int64 v70; // [rsp+0h] [rbp-128h] BYREF
  void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+28h] [rbp-100h]
  __int64 v72; // [rsp+38h] [rbp-F0h]
  UFG::qVector3 *p0; // [rsp+50h] [rbp-D8h]
  Render::DebugDrawContext *v74; // [rsp+58h] [rbp-D0h]
  __int64 v75; // [rsp+60h] [rbp-C8h]
  __int64 **v76; // [rsp+68h] [rbp-C0h]
  __int64 v77; // [rsp+70h] [rbp-B8h]
  __int64 v78[2]; // [rsp+78h] [rbp-B0h] BYREF
  __int64 *v79; // [rsp+88h] [rbp-A0h] BYREF
  __int64 **v80; // [rsp+90h] [rbp-98h]
  UFG::SimObjectCharacter *v81; // [rsp+130h] [rbp+8h]
  unsigned __int8 IsPlaying; // [rsp+138h] [rbp+10h]
  unsigned int v83; // [rsp+140h] [rbp+18h]

  v78[1] = -2i64;
  v4 = melee_only;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v74 = Context;
  if ( v4 )
    this->m_TypesInCombatMelee.mBits[0] = 0i64;
  else
    this->m_TypesInCombatAny.mBits[0] = 0i64;
  v8 = 0;
  v83 = 0;
  if ( melee_distance <= ranged_distance )
    v9 = ranged_distance;
  else
    v9 = melee_distance;
  v10 = LocalPlayer;
  v81 = LocalPlayer;
  if ( this->m_pLocalPlayerTransformNodeComponent.m_pSimComponent
    && this->m_pLocalPlayerSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    mPrev_low = SLODWORD(this->m_pLocalPlayerSimObjectCharacterPropertiesComponent.m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    m_pSimComponent = this->m_pLocalPlayerTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    p0 = (UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles;
    v79 = (__int64 *)&v79;
    v80 = &v79;
    v13 = UFG::NearbyCharacterManager::s_pInstance;
    v14 = &v79;
    v15 = v78;
    v16 = &v70 + 15;
    v78[0] = (__int64)v16;
    if ( v78 != v16 )
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
        v14 = v80;
        v15 = (__int64 *)(v80 - 2);
      }
      while ( v80 - 2 != (__int64 **)v16 );
    }
    mNext = (UFG::NearbyCharacterManager *)v13->m_Characters[0].mNode.mNext;
    if ( mNext != v13 )
    {
      v21 = v79;
      do
      {
        v21[1] = (__int64)&mNext->m_Characters[1];
        mNext->m_Characters[1].mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v21;
        mNext->m_Characters[1].mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v79;
        v21 = (__int64 *)&mNext->m_Characters[1];
        v79 = (__int64 *)&mNext->m_Characters[1];
        mNext = (UFG::NearbyCharacterManager *)mNext->m_Characters[0].mNode.mNext;
      }
      while ( mNext != v13 );
      v14 = v80;
    }
    v22 = (__int64)(v14 - 2);
    v76 = v14 - 2;
    v77 = mPrev_low;
    if ( v14 - 2 != (__int64 **)v16 )
    {
      do
      {
        v23 = *(_QWORD *)(v22 + 48);
        if ( !v23 )
          goto LABEL_93;
        if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v23 + 112i64))(v23) )
          goto LABEL_93;
        v24 = v76[6];
        if ( (UFG::SimObjectCharacter *)v24[5] == v10 )
          goto LABEL_93;
        v25 = v24[53];
        v26 = (UFG::TransformNodeComponent *)v24[11];
        v75 = v24[35];
        m_IsHostile = UFG::g_AIObjectiveParams[*((int *)v24 + 1041)].m_IsHostile;
        IsPlaying = m_IsHostile;
        v28 = (UFG::SimObjectGame *)v24[5];
        v31 = 0;
        if ( v28 )
        {
          m_Flags = v28->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::HudComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v28, UFG::HudComponent::_TypeUID);
          if ( ComponentOfTypeHK && HIBYTE(ComponentOfTypeHK[3].m_Flags) )
            v31 = 1;
        }
        if ( !m_IsHostile )
        {
          v32 = v24[192];
          if ( v32 )
          {
            v33 = _S31;
            if ( (_S31 & 1) == 0 )
            {
              _S31 |= 1u;
              hostileNodeId.mUID = UFG::qStringHashUpper32("Hostile", -1);
              v33 = _S31;
            }
            if ( (v33 & 2) != 0 )
            {
              MostUsedIndex = mostUsed_Hostile;
            }
            else
            {
              _S31 = v33 | 2;
              MostUsedIndex = GetMostUsedIndex(hostileNodeId.mUID);
              mostUsed_Hostile = MostUsedIndex;
            }
            IsPlaying = ActionController::IsPlaying((ActionController *)(v32 + 216), &hostileNodeId, MostUsedIndex, 1);
          }
        }
        v35 = v24[59];
        if ( !v35 || !v26 || !v25 || !v75 )
        {
          if ( !UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight || !v26 )
            goto LABEL_92;
          UFG::TransformNodeComponent::UpdateWorldTransform(v26);
          v37 = &UFG::qColour::Purple;
LABEL_89:
          v54 = (UFG::qVector3 *)&v26->mWorldTransform.v3;
          goto LABEL_90;
        }
        if ( *(_BYTE *)(v25 + 116) )
        {
          if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v26);
            v37 = &UFG::qColour::Pink;
            goto LABEL_89;
          }
          goto LABEL_92;
        }
        HasRangedWeaponEquippedWithAmmo = UFG::HasRangedWeaponEquippedWithAmmo((UFG::TargetingSystemBaseComponent *)v24[59]);
        if ( melee_only )
        {
          if ( HasRangedWeaponEquippedWithAmmo )
          {
            if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v26);
              v37 = &UFG::qColour::Black;
              goto LABEL_89;
            }
            goto LABEL_92;
          }
        }
        else if ( HasRangedWeaponEquippedWithAmmo )
        {
          v38 = v9;
          goto LABEL_51;
        }
        v38 = melee_distance;
LABEL_51:
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        v39 = (UFG::qVector3 *)&v26->mWorldTransform.v3;
        v40 = p0;
        v41 = p0->y - v26->mWorldTransform.v3.y;
        x_low = (__m128)LODWORD(p0->x);
        x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v26->mWorldTransform.v3.x)
                                          * (float)(x_low.m128_f32[0] - v26->mWorldTransform.v3.x))
                                  + (float)(v41 * v41))
                          + (float)((float)(p0->z - v26->mWorldTransform.v3.z)
                                  * (float)(p0->z - v26->mWorldTransform.v3.z));
        v43 = v38 > _mm_sqrt_ps(x_low).m128_f32[0];
        v44 = *(UFG::SimObjectCVBase **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v35 + 96) + 30i64)
                                       + *(_QWORD *)(v35 + 88)
                                       + 40);
        if ( v44 )
        {
          v46 = v44->m_Flags;
          if ( (v46 & 0x4000) != 0 || v46 < 0 )
          {
            ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v44);
          }
          else if ( (v46 & 0x2000) != 0 || (v46 & 0x1000) != 0 )
          {
            ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              v44,
                                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          }
          else
          {
            ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                              v44,
                                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          }
          v40 = p0;
        }
        else
        {
          ComponentOfType = 0i64;
        }
        if ( v31 )
        {
          if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
          {
            v47 = &UFG::qColour::Purple;
            v48 = v40;
            goto LABEL_64;
          }
          goto LABEL_65;
        }
        if ( ComponentOfType )
        {
          m_eFactionClass = ComponentOfType->m_eFactionClass;
          v52 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v77][m_eFactionClass] == FACTIONSTANDING_ALLIED;
          v53 = v24[65];
          if ( v53 )
            LOBYTE(v53) = *(_DWORD *)(v53 + 80) == 13;
          if ( IsPlaying && v52 && !(_BYTE)v53 )
          {
            if ( v43 )
            {
              if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
              {
                v47 = &UFG::qColour::Blue;
                v48 = p0;
LABEL_64:
                Render::DebugDrawContext::DrawLine(v74, v48, v39, v47, &UFG::qMatrix44::msIdentity, 0i64, 0);
              }
LABEL_65:
              v8 = ++v83;
              v10 = v81;
              v49 = (__int64)*(int *)(v75 + 192) >> 6;
              v50 = 1i64 << (*(_BYTE *)(v75 + 192) & 0x3F);
              if ( melee_only )
                this->m_TypesInCombatMelee.mBits[v49] |= v50;
              else
                this->m_TypesInCombatAny.mBits[v49] |= v50;
              goto LABEL_93;
            }
            if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
            {
              v37 = &UFG::qColour::Red;
              goto LABEL_79;
            }
          }
          else if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
          {
            v37 = &UFG::qColour::White;
LABEL_79:
            v54 = v39;
LABEL_90:
            v55 = p0;
            goto LABEL_91;
          }
        }
        else if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
        {
          v37 = &UFG::qColour::Yellow;
          v54 = (UFG::qVector3 *)&v26->mWorldTransform.v3;
          v55 = v40;
LABEL_91:
          Render::DebugDrawContext::DrawLine(v74, v55, v54, v37, &UFG::qMatrix44::msIdentity, 0i64, 0);
        }
LABEL_92:
        v8 = v83;
        v10 = v81;
LABEL_93:
        v22 = (__int64)(v76[3] - 2);
        v76 = (__int64 **)v22;
        v16 = (__int64 *)v78[0];
      }
      while ( v22 != v78[0] );
    }
    for ( i = v80 - 2; v80 - 2 != (__int64 **)v16; i = v80 - 2 )
    {
      v57 = i + 2;
      v58 = i[2];
      v59 = i[3];
      v58[1] = (__int64)v59;
      *v59 = (__int64)v58;
      *v57 = v57;
      v57[1] = v57;
    }
    v60 = v79;
    v61 = v80;
    v79[1] = (__int64)v80;
    *v61 = v60;
    v79 = (__int64 *)&v79;
    v80 = &v79;
    Context = v74;
    v4 = melee_only;
  }
  if ( UFG::LocalPlayerIsInCombatManager::s_DebugDrawWhetherInFight )
  {
    if ( v4 )
      m_LastMeleeCombatTimestamp = this->m_LastMeleeCombatTimestamp;
    else
      m_LastMeleeCombatTimestamp = this->m_LastAnyCombatTimestamp;
    v63 = m_LastMeleeCombatTimestamp
       && UFG::Metrics::msInstance.mSimTimeMSec - m_LastMeleeCombatTimestamp < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer;
    v64 = "Any";
    if ( v4 )
      v64 = "Melee";
    v65 = "False";
    if ( v63 )
      v65 = "True";
    v66 = 20;
    if ( v4 )
      v66 = 10;
    LODWORD(v72) = v8;
    Render::DebugDrawContext::DrawTextA(
      Context,
      100,
      v66,
      &UFG::qColour::White,
      "IsInFight(%s) - NumAttackers%s(%d) and melee dist %.1f ranged dist %1.f",
      v65,
      v64,
      v72,
      melee_distance,
      ranged_distance);
    if ( v4 && v10 )
    {
      v67 = v10->m_Flags;
      if ( (v67 & 0x4000) != 0 || v67 < 0 || (v67 & 0x2000) != 0 || (v67 & 0x1000) != 0 )
        v68 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v10,
                                                  UFG::FormationManagerComponent::_TypeUID);
      else
        v68 = (UFG::FormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                  v10,
                                                  UFG::FormationManagerComponent::_TypeUID);
      if ( v68 )
      {
        LODWORD(pre_draw_callback) = UFG::FormationManagerComponent::NumAttackersCloserThan(v68, melee_distance, 5);
        Render::DebugDrawContext::DrawTextA(
          Context,
          100,
          30,
          &UFG::qColour::White,
          "NumAIAttackers(%d)",
          pre_draw_callback);
      }
    }
  }
  return v8;
}

