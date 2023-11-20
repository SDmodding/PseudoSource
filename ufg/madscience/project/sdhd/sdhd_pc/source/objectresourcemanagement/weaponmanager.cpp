// File Line: 45
// RVA: 0x43E5E0
void UFG::WeaponManager::Init(void)
{
  UFG::WeaponManager *v0; // rbx

  v0 = (UFG::WeaponManager *)UFG::qMalloc(0x10ui64, "WeaponManager", 0i64);
  if ( v0 )
  {
    v0->mElements.p = 0i64;
    *(_QWORD *)&v0->mElements.size = 0i64;
    if ( UFG::WeaponManager::sMaxWeaponElements > v0->mElements.capacity )
      UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::Reallocate(
        &v0->mElements,
        UFG::WeaponManager::sMaxWeaponElements,
        "WeaponManager");
    UFG::WeaponManager::sbCleanUpFreeWeapons = 0;
    UFG::WeaponManager::sbInViewOk = 0;
    UFG::WeaponManager::sInstance = v0;
  }
  else
  {
    UFG::WeaponManager::sInstance = 0i64;
  }
}

// File Line: 51
// RVA: 0x43B230
void UFG::WeaponManager::Destroy(void)
{
  UFG::WeaponManager *v0; // rdi
  UFG::WeaponManager::WeaponEntry *v1; // rcx
  UFG::SimObject **v2; // rbx

  v0 = UFG::WeaponManager::sInstance;
  if ( UFG::WeaponManager::sInstance )
  {
    v1 = UFG::WeaponManager::sInstance->mElements.p;
    if ( v1 )
    {
      v2 = &v1[-1].mComponent.m_pPointer;
      `eh vector destructor iterator(
        v1,
        0x30ui64,
        (int)v1[-1].mComponent.m_pPointer,
        (void (__fastcall *)(void *))UFG::AIAwareness::KnowledgeSpace::PositionCandidate::~PositionCandidate);
      operator delete[](v2);
    }
    v0->mElements.p = 0i64;
    *(_QWORD *)&v0->mElements.size = 0i64;
    operator delete[](v0);
  }
  UFG::WeaponManager::sInstance = 0i64;
}

// File Line: 58
// RVA: 0x43F0B0
UFG::WeaponManager *__fastcall UFG::WeaponManager::Instance()
{
  return UFG::WeaponManager::sInstance;
}

// File Line: 88
// RVA: 0x438920
void __fastcall UFG::WeaponManager::AddWeapon(UFG::WeaponManager *this, UFG::SimObjectWeaponPropertiesComponent *weapon)
{
  UFG::SimObject *v2; // rsi
  UFG::WeaponManager *v3; // rdi
  __int64 v4; // rbx
  UFG::qSymbolUC *v5; // rcx
  char *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::WeaponManager::WeaponEntry item; // [rsp+28h] [rbp-38h]

  v2 = (UFG::SimObject *)weapon;
  v3 = this;
  if ( weapon->mIsRealWeapon )
  {
    if ( this->mElements.size >= UFG::WeaponManager::sMaxWeaponElements )
    {
      v4 = 0i64;
      if ( this->mElements.size )
      {
        do
        {
          v5 = (UFG::qSymbolUC *)v3->mElements.p[v4].mComponent.m_pPointer->mNode.mParent;
          if ( v5 )
          {
            v6 = UFG::qSymbol::as_cstr_dbg(v5 + 18);
            UFG::qPrintf("Weapon %s %d\n", v6, (unsigned int)v4);
          }
          v4 = (unsigned int)(v4 + 1);
        }
        while ( (unsigned int)v4 < v3->mElements.size );
      }
    }
    item.mComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&item.mComponent.mPrev;
    item.mComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&item.mComponent.mPrev;
    item.mComponent.m_pPointer = 0i64;
    item.mComponent.m_pPointer = v2;
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&item.mComponent.mPrev;
    item.mComponent.mPrev = v9;
    item.mComponent.mNext = &v2->m_SafePointerList.mNode;
    item.mComponent.mNext->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&item.mComponent.mPrev;
    item.mScore = 0.0;
    item.mEquipped = 0;
    item.mSpawnTime = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::Add(&v3->mElements, &item, "qArray.Add");
    if ( item.mComponent.m_pPointer )
    {
      v10 = item.mComponent.mPrev;
      v11 = item.mComponent.mNext;
      item.mComponent.mPrev->mNext = item.mComponent.mNext;
      v11->mPrev = v10;
      item.mComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&item.mComponent.mPrev;
      item.mComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&item.mComponent.mPrev;
    }
    v12 = item.mComponent.mPrev;
    v13 = item.mComponent.mNext;
    item.mComponent.mPrev->mNext = item.mComponent.mNext;
    v13->mPrev = v12;
  }
}

// File Line: 129
// RVA: 0x43BB70
void __fastcall UFG::WeaponManager::DoCleanUp(UFG::WeaponManager *this)
{
  UFG::SimObject *v1; // rdi
  char v2; // bl
  UFG::WeaponManager *v3; // r13
  UFG::SimObjectCharacter *v4; // rax
  UFG::TargetingSystemPedPlayerComponent *v5; // rax
  UFG::TargetingSimObject *v6; // rdx
  UFG::TargetingMap *v7; // rcx
  signed int v8; // er14
  signed __int64 v9; // rsi
  UFG::WeaponManager::WeaponEntry *v10; // r15
  UFG::SimObjectWeaponPropertiesComponent *v11; // rcx
  UFG::SimObject *v12; // r12
  UFG::BaseCameraComponent *v13; // rcx
  UFG::Camera *v14; // rbx
  UFG::qBaseNodeRB *v15; // rcx
  __int64 v16; // rdi
  UFG::qMatrix44 *v17; // rbx
  UFG::qMatrix44 *v18; // rax
  float v19; // xmm11_4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // ST38_4
  float v23; // xmm15_4
  float v24; // xmm14_4
  float v25; // xmm13_4
  float v26; // ST20_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  __m128 v32; // xmm2
  float v33; // xmm0_4
  float v34; // xmm6_4
  float v35; // xmm4_4
  __m128 v36; // xmm2
  float v37; // xmm0_4
  __m128 v38; // xmm2
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm3_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *v42; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::SimObject *v45; // [rsp+48h] [rbp-B8h]
  UFG::SimObject *v46; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-A0h]
  UFG::qVector4 planes; // [rsp+A0h] [rbp-60h]
  float v49; // [rsp+B0h] [rbp-50h]
  float v50; // [rsp+B4h] [rbp-4Ch]
  float v51; // [rsp+B8h] [rbp-48h]
  float v52; // [rsp+BCh] [rbp-44h]
  float v53; // [rsp+C0h] [rbp-40h]
  float v54; // [rsp+C4h] [rbp-3Ch]
  float v55; // [rsp+C8h] [rbp-38h]
  float v56; // [rsp+CCh] [rbp-34h]
  float v57; // [rsp+D0h] [rbp-30h]
  float v58; // [rsp+D4h] [rbp-2Ch]
  float v59; // [rsp+D8h] [rbp-28h]
  float v60; // [rsp+DCh] [rbp-24h]
  float v61; // [rsp+E0h] [rbp-20h]
  float v62; // [rsp+E4h] [rbp-1Ch]
  float v63; // [rsp+E8h] [rbp-18h]
  float v64; // [rsp+ECh] [rbp-14h]
  float v65; // [rsp+F0h] [rbp-10h]
  float v66; // [rsp+F4h] [rbp-Ch]
  float v67; // [rsp+F8h] [rbp-8h]
  float v68; // [rsp+FCh] [rbp-4h]
  char v69; // [rsp+1F0h] [rbp+F0h]
  UFG::Camera *v70; // [rsp+1F8h] [rbp+F8h]
  float v71; // [rsp+1F8h] [rbp+F8h]

  v1 = 0i64;
  v2 = 0;
  v3 = this;
  v69 = 0;
  v46 = 0i64;
  v45 = 0i64;
  v4 = UFG::GetLocalPlayer();
  if ( v4 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>((UFG::SimObjectCVBase *)&v4->vfptr);
    if ( v5 )
    {
      v6 = v5->m_pTargets;
      v7 = v5->m_pTargetingMap;
      v1 = v6[(unsigned __int8)v7->m_Map.p[42]].m_pTarget.m_pPointer;
      v46 = v6[(unsigned __int8)v7->m_Map.p[42]].m_pTarget.m_pPointer;
      v45 = v6[(unsigned __int8)v7->m_Map.p[43]].m_pTarget.m_pPointer;
    }
  }
  v8 = v3->mElements.size - 1;
  if ( v8 < 0 )
  {
LABEL_27:
    UFG::WeaponManager::sbCleanUpFreeWeapons = 0;
    UFG::WeaponManager::sbInViewOk = 0;
    return;
  }
  v9 = v8;
  do
  {
    v10 = v3->mElements.p;
    v11 = (UFG::SimObjectWeaponPropertiesComponent *)v10[v9].mComponent.m_pPointer;
    if ( v11 )
    {
      v12 = v11->m_pSimObject;
      if ( !UFG::SimObjectWeaponPropertiesComponent::IsOwned(v11) && v12 != v1 && v12 != v45 )
      {
        if ( (!UFG::UIHK_NISOverlay::IsCurtainVisible() || !UFG::UIHK_NISOverlay::IsCurtainStable())
          && !UFG::WeaponManager::sbInViewOk )
        {
          v13 = UFG::Director::Get()->mCurrentCamera;
          if ( v13 )
            v14 = &v13->mCamera;
          else
            v14 = 0i64;
          v70 = v14;
          v15 = v10[v9].mComponent.m_pPointer->mNode.mParent;
          if ( v15 )
            v16 = *(_QWORD *)&v15[2].mUID;
          else
            v16 = 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
          v17 = UFG::Camera::GetViewProjection(v14);
          v18 = UFG::Camera::GetWorldView(v70);
          UFG::qMatrix44::operator*(v18, &result, v17);
          LODWORD(v19) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
          LODWORD(v20) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
          LODWORD(v21) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
          LODWORD(v22) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
          LODWORD(v23) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
          LODWORD(v24) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
          LODWORD(v25) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
          LODWORD(v26) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
          LODWORD(v71) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
          v27 = fsqrt(
                  (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0])
                                * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                        + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])
                                * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
                + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
          planes.x = COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * (float)(1.0 / v27);
          planes.y = COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * (float)(1.0 / v27);
          planes.z = COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * (float)(1.0 / v27);
          planes.w = COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]) * (float)(1.0 / v27);
          v28 = fsqrt((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21));
          v49 = v19 * (float)(1.0 / v28);
          v50 = v20 * (float)(1.0 / v28);
          v51 = v21 * (float)(1.0 / v28);
          LODWORD(v29) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
          LODWORD(v30) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
          v52 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]) * (float)(1.0 / v28);
          v31 = fsqrt((float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v25 * v25));
          v32 = (__m128)LODWORD(v71);
          v53 = v23 * (float)(1.0 / v31);
          v54 = v24 * (float)(1.0 / v31);
          v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v29 * v29))
                          + (float)(v30 * v30);
          v55 = v25 * (float)(1.0 / v31);
          v56 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]) * (float)(1.0 / v31);
          LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v32);
          v60 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]) * (float)(1.0 / v33);
          v57 = v29 * (float)(1.0 / v33);
          LODWORD(v34) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
          v58 = v71 * (float)(1.0 / v33);
          v59 = v30 * (float)(1.0 / v33);
          LODWORD(v35) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
          v36 = (__m128)LODWORD(v22);
          v36.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v34 * v34))
                          + (float)(v35 * v35);
          LODWORD(v37) = (unsigned __int128)_mm_sqrt_ps(v36);
          v64 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]) * (float)(1.0 / v37);
          v61 = v34 * (float)(1.0 / v37);
          v38 = (__m128)LODWORD(v26);
          v63 = v35 * (float)(1.0 / v37);
          LODWORD(v39) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
          v62 = v22 * (float)(1.0 / v37);
          LODWORD(v40) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
          v38.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v39 * v39))
                          + (float)(v40 * v40);
          v41 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v38));
          v66 = v26 * v41;
          v68 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v41;
          v65 = v41 * v39;
          v67 = v40 * v41;
          if ( DistanceToFrustum(&planes, (UFG::qVector3 *)(v16 + 176)) < 1.0 )
          {
            v2 = 1;
            v69 = 1;
            goto LABEL_25;
          }
          v2 = v69;
        }
        v42 = &v10[v9].mComponent;
        if ( v42->m_pPointer )
        {
          v43 = v42->mPrev;
          v44 = v42->mNext;
          v43->mNext = v44;
          v44->mPrev = v43;
          v42->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v42->mPrev;
          v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v42->mPrev;
        }
        v42->m_pPointer = 0i64;
        UFG::SimObject::Destroy(v12);
        UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::FastDelete(&v3->mElements, v8);
      }
    }
LABEL_25:
    v1 = v46;
    --v9;
    --v8;
  }
  while ( v8 >= 0 );
  if ( !v2 )
    goto LABEL_27;
}

// File Line: 200
// RVA: 0x444E60
void __fastcall UFG::WeaponManager::Update(UFG::WeaponManager *this, float deltaTime)
{
  UFG::WeaponManager *v2; // rsi
  int v3; // eax
  __int64 v4; // r14
  signed __int64 v5; // rdi
  UFG::WeaponManager::WeaponEntry *v6; // rax
  UFG::SimObjectGame *v7; // rbx
  unsigned __int16 v8; // cx
  UFG::WaterFloatingTrackerComponent *v9; // rax
  unsigned __int16 v10; // cx
  UFG::RigidBody *v11; // rax
  signed int v12; // ebx
  signed __int64 v13; // rdi
  UFG::WeaponManager::WeaponEntry *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectCharacter *v18; // rbx
  __int64 v19; // r13
  UFG::TransformNodeComponent *v20; // r15
  float v21; // xmm6_4
  __int64 v22; // r14
  __int64 v23; // rbx
  UFG::WeaponManager::WeaponEntry *v24; // rdi
  bool v25; // al
  UFG::qBaseNodeRB *v26; // rcx
  UFG::TransformNodeComponent *v27; // rbp
  UFG::SimObjectWeaponPropertiesComponent *v28; // rcx
  __m128 v29; // xmm2
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  signed int v33; // er12
  __int64 v34; // r14
  signed __int64 v35; // rbx
  UFG::WeaponManager::WeaponEntry *v36; // rdi
  UFG::SimObject *v37; // r15
  UFG::TransformNodeComponent *v38; // rbp
  float v39; // xmm1_4
  float v40; // xmm2_4
  UFG::Camera *v41; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::qVector3 world_pos; // [rsp+30h] [rbp-68h]
  UFG::qVector3 result; // [rsp+40h] [rbp-58h]
  bool is_on_screen; // [rsp+A0h] [rbp+8h]
  UFG::qVector2 viewport_scale; // [rsp+B0h] [rbp+18h]

  v2 = this;
  if ( UFG::WeaponManager::sbCleanUpFreeWeapons )
    UFG::WeaponManager::DoCleanUp(this);
  v3 = v2->mElements.size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = v3;
    do
    {
      v6 = v2->mElements.p;
      if ( !v6[v5].mEquipped )
      {
        v7 = (UFG::SimObjectGame *)v6[v5].mComponent.m_pPointer;
        if ( v7 )
          v7 = (UFG::SimObjectGame *)v7->mNode.mParent;
        if ( v7 )
        {
          v8 = v7->m_Flags;
          if ( (v8 >> 14) & 1 )
          {
            v9 = (UFG::WaterFloatingTrackerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v7,
                                                         UFG::WaterFloatingTrackerComponent::_TypeUID);
          }
          else if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
              v9 = (UFG::WaterFloatingTrackerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v7,
                                                           UFG::WaterFloatingTrackerComponent::_TypeUID);
            else
              v9 = (UFG::WaterFloatingTrackerComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             v7,
                                                                             UFG::WaterFloatingTrackerComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::WaterFloatingTrackerComponent::_TypeUID));
          }
          else
          {
            v9 = (UFG::WaterFloatingTrackerComponent *)v7->m_Components.p[35].m_pComponent;
          }
          if ( v9 && UFG::WaterFloatingTrackerComponent::IsSunk(v9) )
          {
            v10 = v7->m_Flags;
            if ( (v10 >> 14) & 1 )
            {
              v11 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
            }
            else if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
                v11 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
              else
                v11 = (UFG::RigidBody *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v7,
                                                             UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                    (UFG::SimObject *)&v7->vfptr,
                                                                                                    UFG::RigidBodyComponent::_TypeUID));
            }
            else
            {
              v11 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
            }
            if ( v11 && (unsigned int)UFG::RigidBody::GetMotionType(v11) == 128 )
              UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)&v7->vfptr);
          }
        }
      }
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v12 = v2->mElements.size - 1;
  if ( v12 >= 0 )
  {
    v13 = v12;
    do
    {
      v14 = v2->mElements.p;
      if ( !v14[v13].mComponent.m_pPointer )
      {
        v15 = &v14[v13].mComponent;
        if ( v15->m_pPointer )
        {
          v16 = v15->mPrev;
          v17 = v15->mNext;
          v16->mNext = v17;
          v17->mPrev = v16;
          v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
          v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
        }
        v15->m_pPointer = 0i64;
        UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::StableDelete(&v2->mElements, v12);
      }
      --v13;
      --v12;
    }
    while ( v12 >= 0 );
  }
  v18 = LocalPlayer;
  if ( LocalPlayer )
  {
    if ( NISManager::GetInstance()->mState == STATE_INVALID )
    {
      v19 = v2->mElements.size;
      if ( (unsigned int)v19 > UFG::WeaponManager::sSoftContractionCount )
      {
        v20 = v18->m_pTransformNodeComponent;
        v21 = UFG::Metrics::msInstance.mSimTime_Temp;
        v22 = (unsigned int)v19;
        if ( v19 > 0 )
        {
          v23 = 0i64;
          do
          {
            v24 = v2->mElements.p;
            v25 = UFG::SimObjectWeaponPropertiesComponent::IsOwned((UFG::SimObjectWeaponPropertiesComponent *)v24[v23].mComponent.m_pPointer);
            v24[v23].mEquipped = v25;
            if ( v25 )
            {
              v24[v23].mScore = 0.0;
            }
            else
            {
              v26 = v24[v23].mComponent.m_pPointer->mNode.mParent;
              if ( v26 )
                v27 = *(UFG::TransformNodeComponent **)&v26[2].mUID;
              else
                v27 = 0i64;
              v24[v23].mTimeAlive = v21 - v24[v23].mSpawnTime;
              UFG::TransformNodeComponent::UpdateWorldTransform(v27);
              UFG::TransformNodeComponent::UpdateWorldTransform(v20);
              v28 = (UFG::SimObjectWeaponPropertiesComponent *)v24[v23].mComponent.m_pPointer;
              v29 = (__m128)LODWORD(v20->mWorldTransform.v3.y);
              v30 = v20->mWorldTransform.v3.x - v27->mWorldTransform.v3.x;
              v31 = v20->mWorldTransform.v3.z - v27->mWorldTransform.v3.z;
              v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] - v27->mWorldTransform.v3.y)
                                              * (float)(v29.m128_f32[0] - v27->mWorldTransform.v3.y))
                                      + (float)(v30 * v30))
                              + (float)(v31 * v31);
              LODWORD(v32) = (unsigned __int128)_mm_sqrt_ps(v29);
              v24[v23].mDistFromPlayer = v32;
              v24[v23].mScore = (float)(v32 * UFG::WeaponManager::sDistanceScoreMultiplier)
                              * (float)(UFG::WeaponManager::sTimeAliveScoreMultiplier * v24[v23].mTimeAlive);
              if ( !UFG::SimObjectWeaponPropertiesComponent::HasAmmo(v28)
                && !v24[v23].mComponent.m_pPointer[1].m_ReservedComponentSlots )
              {
                v24[v23].mScore = UFG::WeaponManager::sNoAmmoMultiplier * v24[v23].mScore;
              }
            }
            ++v23;
            --v22;
          }
          while ( v22 );
        }
        UFG::qQuickSortImpl<UFG::WeaponManager::WeaponEntry,bool (*)(UFG::WeaponManager::WeaponEntry const &,UFG::WeaponManager::WeaponEntry const &)>(
          v2->mElements.p,
          &v2->mElements.p[(signed int)v2->mElements.size - 1],
          UFG::CloseTargetsSort);
        if ( !UFG::WeaponManager::sDisableContraction )
        {
          v33 = v19 - 1;
          v34 = (signed int)v19 - 1;
          if ( (signed int)v19 - 1 >= 0 )
          {
            v35 = v33;
            while ( 1 )
            {
              v36 = v2->mElements.p;
              if ( !v36[v35].mEquipped
                && ((signed int)v19 > (signed int)UFG::WeaponManager::sHardContractionCount
                 || UFG::WeaponManager::sSoftContractionMinDist < v36[v35].mDistFromPlayer) )
              {
                v37 = (UFG::SimObject *)v36[v35].mComponent.m_pPointer->mNode.mParent;
                if ( v37 )
                  v38 = v37->m_pTransformNodeComponent;
                else
                  v38 = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(v38);
                v39 = v38->mWorldTransform.v3.y;
                v40 = v38->mWorldTransform.v3.z;
                world_pos.x = v38->mWorldTransform.v3.x;
                world_pos.y = v39;
                world_pos.z = v40;
                v41 = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
                if ( v41 )
                  v41 = (UFG::Camera *)((char *)v41 + 80);
                is_on_screen = 0;
                viewport_scale.x = 1.0;
                viewport_scale.y = 1.0;
                UFG::Camera::GetScreenCoord(v41, &result, &world_pos, &viewport_scale, &is_on_screen);
                if ( v36[v35].mDistFromPlayer > 100.0 || !is_on_screen )
                  break;
              }
              --v33;
              --v35;
              if ( --v34 < 0 )
                return;
            }
            v42 = &v36[v35].mComponent;
            if ( v42->m_pPointer )
            {
              v43 = v42->mPrev;
              v44 = v42->mNext;
              v43->mNext = v44;
              v44->mPrev = v43;
              v42->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v42->mPrev;
              v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v42->mPrev;
            }
            v42->m_pPointer = 0i64;
            UFG::SimObject::Destroy(v37);
            UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::FastDelete(&v2->mElements, v33);
          }
        }
      }
    }
  }
}

// File Line: 338
// RVA: 0x43A780
void __fastcall UFG::WeaponManager::CleanUpFreeWeapons(UFG::WeaponManager *this, bool in_view)
{
  UFG::WeaponManager::sbInViewOk = in_view;
  UFG::WeaponManager::sbCleanUpFreeWeapons = 1;
}

