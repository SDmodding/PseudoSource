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
  UFG::WeaponManager::WeaponEntry *p; // rcx
  UFG::SimObject **p_m_pPointer; // rbx

  v0 = UFG::WeaponManager::sInstance;
  if ( UFG::WeaponManager::sInstance )
  {
    p = UFG::WeaponManager::sInstance->mElements.p;
    if ( p )
    {
      p_m_pPointer = &p[-1].mComponent.m_pPointer;
      `eh vector destructor iterator(
        p,
        0x30ui64,
        (int)p[-1].mComponent.m_pPointer,
        (void (__fastcall *)(void *))UFG::AIAwareness::KnowledgeSpace::PositionCandidate::~PositionCandidate);
      operator delete[](p_m_pPointer);
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
void __fastcall UFG::WeaponManager::AddWeapon(UFG::WeaponManager *this, UFG::SimObject *weapon)
{
  __int64 i; // rbx
  UFG::qBaseNodeRB *mParent; // rcx
  char *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::WeaponManager::WeaponEntry item; // [rsp+28h] [rbp-38h] BYREF

  if ( LOBYTE(weapon[1].m_Flags) )
  {
    if ( this->mElements.size >= UFG::WeaponManager::sMaxWeaponElements )
    {
      for ( i = 0i64; (unsigned int)i < this->mElements.size; i = (unsigned int)(i + 1) )
      {
        mParent = this->mElements.p[i].mComponent.m_pPointer->mNode.mParent;
        if ( mParent )
        {
          v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)mParent[2].mChild);
          UFG::qPrintf("Weapon %s %d\n", v6, (unsigned int)i);
        }
      }
    }
    item.mComponent.mPrev = &item.mComponent;
    item.mComponent.mNext = &item.mComponent;
    item.mComponent.m_pPointer = weapon;
    mPrev = weapon->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    mPrev->mNext = &item.mComponent;
    item.mComponent.mPrev = mPrev;
    item.mComponent.mNext = &weapon->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    weapon->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &item.mComponent;
    item.mScore = 0.0;
    item.mEquipped = 0;
    item.mSpawnTime = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::Add(&this->mElements, &item, "qArray.Add");
    if ( item.mComponent.m_pPointer )
    {
      v8 = item.mComponent.mPrev;
      mNext = item.mComponent.mNext;
      item.mComponent.mPrev->mNext = item.mComponent.mNext;
      mNext->mPrev = v8;
      item.mComponent.mPrev = &item.mComponent;
      item.mComponent.mNext = &item.mComponent;
    }
    v10 = item.mComponent.mPrev;
    v11 = item.mComponent.mNext;
    item.mComponent.mPrev->mNext = item.mComponent.mNext;
    v11->mPrev = v10;
  }
}

// File Line: 129
// RVA: 0x43BB70
void __fastcall UFG::WeaponManager::DoCleanUp(UFG::WeaponManager *this)
{
  UFG::SimObject *m_pPointer; // rdi
  char v2; // bl
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TargetingSystemPedPlayerComponent *v5; // rax
  UFG::TargetingSimObject *m_pTargets; // rdx
  UFG::TargetingMap *m_pTargetingMap; // rcx
  signed int v8; // r14d
  __int64 v9; // rsi
  UFG::WeaponManager::WeaponEntry *p; // r15
  UFG::SimObjectWeaponPropertiesComponent *v11; // rcx
  UFG::SimObject *m_pSimObject; // r12
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rbx
  UFG::qBaseNodeRB *mParent; // rcx
  __int64 v16; // rdi
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v19; // xmm11_4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm15_4
  float v23; // xmm14_4
  float v24; // xmm13_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  __m128 v30; // xmm2
  float v31; // xmm0_4
  float v32; // xmm6_4
  float v33; // xmm4_4
  __m128 v34; // xmm2
  float v35; // xmm0_4
  __m128 v36; // xmm2
  float v37; // xmm3_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *p_mComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  float v41; // [rsp+20h] [rbp-E0h]
  float v42; // [rsp+24h] [rbp-DCh]
  float v43; // [rsp+2Ch] [rbp-D4h]
  float v44; // [rsp+38h] [rbp-C8h]
  UFG::SimObject *v45; // [rsp+48h] [rbp-B8h]
  UFG::SimObject *v46; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector4 planes; // [rsp+A0h] [rbp-60h] BYREF
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

  m_pPointer = 0i64;
  v2 = 0;
  v69 = 0;
  v46 = 0i64;
  v45 = 0i64;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(LocalPlayer);
    if ( v5 )
    {
      m_pTargets = v5->m_pTargets;
      m_pTargetingMap = v5->m_pTargetingMap;
      m_pPointer = m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[42]].m_pTarget.m_pPointer;
      v46 = m_pPointer;
      v45 = m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[43]].m_pTarget.m_pPointer;
    }
  }
  v8 = this->mElements.size - 1;
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
    p = this->mElements.p;
    v11 = (UFG::SimObjectWeaponPropertiesComponent *)p[v9].mComponent.m_pPointer;
    if ( v11 )
    {
      m_pSimObject = v11->m_pSimObject;
      if ( !UFG::SimObjectWeaponPropertiesComponent::IsOwned(v11) && m_pSimObject != m_pPointer && m_pSimObject != v45 )
      {
        if ( (!UFG::UIHK_NISOverlay::IsCurtainVisible() || !UFG::UIHK_NISOverlay::IsCurtainStable())
          && !UFG::WeaponManager::sbInViewOk )
        {
          mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
          if ( mCurrentCamera )
            p_mCamera = &mCurrentCamera->mCamera;
          else
            p_mCamera = 0i64;
          v70 = p_mCamera;
          mParent = p[v9].mComponent.m_pPointer->mNode.mParent;
          if ( mParent )
            v16 = *(_QWORD *)&mParent[2].mUID;
          else
            v16 = 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
          ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
          WorldView = UFG::Camera::GetWorldView(v70);
          UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
          LODWORD(v19) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
          LODWORD(v20) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
          LODWORD(v21) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
          LODWORD(v44) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
          LODWORD(v22) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
          LODWORD(v23) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
          LODWORD(v24) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
          LODWORD(v41) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
          LODWORD(v71) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
          LODWORD(v42) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
          LODWORD(v43) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
          v25 = fsqrt(
                  (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0])
                                * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                        + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])
                                * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
                + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
          planes.x = COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * (float)(1.0 / v25);
          planes.y = COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * (float)(1.0 / v25);
          planes.z = COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * (float)(1.0 / v25);
          planes.w = COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]) * (float)(1.0 / v25);
          v26 = fsqrt((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21));
          v49 = v19 * (float)(1.0 / v26);
          v50 = v20 * (float)(1.0 / v26);
          v51 = v21 * (float)(1.0 / v26);
          LODWORD(v27) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
          LODWORD(v28) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
          v52 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]) * (float)(1.0 / v26);
          v29 = fsqrt((float)((float)(v23 * v23) + (float)(v22 * v22)) + (float)(v24 * v24));
          v30 = (__m128)LODWORD(v71);
          v53 = v22 * (float)(1.0 / v29);
          v54 = v23 * (float)(1.0 / v29);
          v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v27 * v27))
                          + (float)(v28 * v28);
          v55 = v24 * (float)(1.0 / v29);
          v56 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]) * (float)(1.0 / v29);
          v31 = _mm_sqrt_ps(v30).m128_f32[0];
          v60 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]) * (float)(1.0 / v31);
          v57 = v27 * (float)(1.0 / v31);
          LODWORD(v32) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
          v58 = v71 * (float)(1.0 / v31);
          v59 = v28 * (float)(1.0 / v31);
          LODWORD(v33) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
          v34 = (__m128)LODWORD(v44);
          v34.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v32 * v32))
                          + (float)(v33 * v33);
          v35 = _mm_sqrt_ps(v34).m128_f32[0];
          v64 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]) * (float)(1.0 / v35);
          v61 = v32 * (float)(1.0 / v35);
          v36 = (__m128)LODWORD(v41);
          v63 = v33 * (float)(1.0 / v35);
          v62 = v44 * (float)(1.0 / v35);
          v36.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v42 * v42))
                          + (float)(v43 * v43);
          v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
          v66 = v41 * v37;
          v68 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]) * v37;
          v65 = v37 * v42;
          v67 = v43 * v37;
          if ( DistanceToFrustum(&planes, (UFG::qVector3 *)(v16 + 176)) < 1.0 )
          {
            v2 = 1;
            v69 = 1;
            goto LABEL_25;
          }
          v2 = v69;
        }
        p_mComponent = &p[v9].mComponent;
        if ( p_mComponent->m_pPointer )
        {
          mPrev = p_mComponent->mPrev;
          mNext = p_mComponent->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mComponent->mPrev = p_mComponent;
          p_mComponent->mNext = p_mComponent;
        }
        p_mComponent->m_pPointer = 0i64;
        UFG::SimObject::Destroy(m_pSimObject);
        UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::FastDelete(&this->mElements, v8);
      }
    }
LABEL_25:
    m_pPointer = v46;
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
  signed int v3; // eax
  __int64 v4; // r14
  __int64 v5; // rdi
  UFG::WeaponManager::WeaponEntry *p; // rax
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::WaterFloatingTrackerComponent *m_pComponent; // rax
  __int16 v10; // cx
  UFG::RigidBody *ComponentOfTypeHK; // rax
  signed int v12; // ebx
  __int64 v13; // rdi
  UFG::WeaponManager::WeaponEntry *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *p_mComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectCharacter *v18; // rbx
  unsigned int size; // r13d
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  float mSimTime_Temp; // xmm6_4
  __int64 v22; // r14
  __int64 v23; // rbx
  UFG::WeaponManager::WeaponEntry *v24; // rdi
  bool IsOwned; // al
  UFG::qBaseNodeRB *mParent; // rcx
  UFG::TransformNodeComponent *v27; // rbp
  UFG::SimObjectWeaponPropertiesComponent *v28; // rcx
  __m128 y_low; // xmm2
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  signed int v33; // r12d
  __int64 v34; // r14
  __int64 i; // rbx
  UFG::WeaponManager::WeaponEntry *v36; // rdi
  UFG::SimObject *v37; // r15
  UFG::TransformNodeComponent *v38; // rbp
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::Camera *mCurrentCamera; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::qVector3 world_pos; // [rsp+30h] [rbp-68h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-58h] BYREF
  bool is_on_screen; // [rsp+A0h] [rbp+8h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+B0h] [rbp+18h] BYREF

  if ( UFG::WeaponManager::sbCleanUpFreeWeapons )
    UFG::WeaponManager::DoCleanUp(this);
  v3 = this->mElements.size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = v3;
    do
    {
      p = this->mElements.p;
      if ( p[v5].mEquipped )
        goto LABEL_29;
      m_pPointer = (UFG::SimObjectGame *)p[v5].mComponent.m_pPointer;
      if ( m_pPointer )
        m_pPointer = (UFG::SimObjectGame *)m_pPointer->mNode.mParent;
      if ( !m_pPointer )
        goto LABEL_29;
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        goto LABEL_15;
      if ( m_Flags < 0 )
      {
        m_pComponent = (UFG::WaterFloatingTrackerComponent *)m_pPointer->m_Components.p[35].m_pComponent;
        goto LABEL_17;
      }
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_15:
        m_pComponent = (UFG::WaterFloatingTrackerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pPointer,
                                                               UFG::WaterFloatingTrackerComponent::_TypeUID);
      else
        m_pComponent = (UFG::WaterFloatingTrackerComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pPointer,
                                                               UFG::WaterFloatingTrackerComponent::_TypeUID);
LABEL_17:
      if ( m_pComponent && UFG::WaterFloatingTrackerComponent::IsSunk(m_pComponent) )
      {
        v10 = m_pPointer->m_Flags;
        if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::RigidBodyComponent::_TypeUID);
        if ( ComponentOfTypeHK && (unsigned int)UFG::RigidBody::GetMotionType(ComponentOfTypeHK) == 128 )
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
      }
LABEL_29:
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v12 = this->mElements.size - 1;
  if ( v12 >= 0 )
  {
    v13 = v12;
    do
    {
      v14 = this->mElements.p;
      if ( !v14[v13].mComponent.m_pPointer )
      {
        p_mComponent = &v14[v13].mComponent;
        if ( p_mComponent->m_pPointer )
        {
          mPrev = p_mComponent->mPrev;
          mNext = p_mComponent->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mComponent->mPrev = p_mComponent;
          p_mComponent->mNext = p_mComponent;
        }
        p_mComponent->m_pPointer = 0i64;
        UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::StableDelete(&this->mElements, v12);
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
      size = this->mElements.size;
      if ( this->mElements.size > UFG::WeaponManager::sSoftContractionCount )
      {
        m_pTransformNodeComponent = v18->m_pTransformNodeComponent;
        mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
        v22 = size;
        if ( this->mElements.size )
        {
          v23 = 0i64;
          do
          {
            v24 = this->mElements.p;
            IsOwned = UFG::SimObjectWeaponPropertiesComponent::IsOwned((UFG::SimObjectWeaponPropertiesComponent *)v24[v23].mComponent.m_pPointer);
            v24[v23].mEquipped = IsOwned;
            if ( IsOwned )
            {
              v24[v23].mScore = 0.0;
            }
            else
            {
              mParent = v24[v23].mComponent.m_pPointer->mNode.mParent;
              if ( mParent )
                v27 = *(UFG::TransformNodeComponent **)&mParent[2].mUID;
              else
                v27 = 0i64;
              v24[v23].mTimeAlive = mSimTime_Temp - v24[v23].mSpawnTime;
              UFG::TransformNodeComponent::UpdateWorldTransform(v27);
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v28 = (UFG::SimObjectWeaponPropertiesComponent *)v24[v23].mComponent.m_pPointer;
              y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
              v30 = m_pTransformNodeComponent->mWorldTransform.v3.x - v27->mWorldTransform.v3.x;
              v31 = m_pTransformNodeComponent->mWorldTransform.v3.z - v27->mWorldTransform.v3.z;
              y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v27->mWorldTransform.v3.y)
                                                * (float)(y_low.m128_f32[0] - v27->mWorldTransform.v3.y))
                                        + (float)(v30 * v30))
                                + (float)(v31 * v31);
              v32 = _mm_sqrt_ps(y_low).m128_f32[0];
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
          this->mElements.p,
          &this->mElements.p[(int)this->mElements.size - 1],
          UFG::CloseTargetsSort);
        if ( !UFG::WeaponManager::sDisableContraction )
        {
          v33 = size - 1;
          v34 = (int)(size - 1);
          if ( (int)(size - 1) >= 0 )
          {
            for ( i = v33; ; --i )
            {
              v36 = this->mElements.p;
              if ( !v36[i].mEquipped
                && ((int)size > (int)UFG::WeaponManager::sHardContractionCount
                 || UFG::WeaponManager::sSoftContractionMinDist < v36[i].mDistFromPlayer) )
              {
                v37 = (UFG::SimObject *)v36[i].mComponent.m_pPointer->mNode.mParent;
                if ( v37 )
                  v38 = v37->m_pTransformNodeComponent;
                else
                  v38 = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(v38);
                y = v38->mWorldTransform.v3.y;
                z = v38->mWorldTransform.v3.z;
                world_pos.x = v38->mWorldTransform.v3.x;
                world_pos.y = y;
                world_pos.z = z;
                mCurrentCamera = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
                if ( mCurrentCamera )
                  mCurrentCamera = (UFG::Camera *)((char *)mCurrentCamera + 80);
                is_on_screen = 0;
                viewport_scale.x = 1.0;
                viewport_scale.y = 1.0;
                UFG::Camera::GetScreenCoord(mCurrentCamera, &result, &world_pos, &viewport_scale, &is_on_screen);
                if ( v36[i].mDistFromPlayer > 100.0 || !is_on_screen )
                  break;
              }
              --v33;
              if ( --v34 < 0 )
                return;
            }
            v42 = &v36[i].mComponent;
            if ( v42->m_pPointer )
            {
              v43 = v42->mPrev;
              v44 = v42->mNext;
              v43->mNext = v44;
              v44->mPrev = v43;
              v42->mPrev = v42;
              v42->mNext = v42;
            }
            v42->m_pPointer = 0i64;
            UFG::SimObject::Destroy(v37);
            UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::FastDelete(&this->mElements, v33);
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

